import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from visualization_msgs.msg import MarkerArray
from cv_bridge import CvBridge
from object_detection_msgs.msg import Object, Objects

import paho.mqtt.client as mqtt
import numpy as np
import cv2
import base64
import json

class ImagePublisher(Node):
	def __init__(self):
		super().__init__("ImagePublisher")

		self.object_detection = True
		self.current_frame = None
		
		if self.object_detection:
			self.image_topic = "camera/color/image_raw"
			self.detected_object_img_topic = "camera/image_tracked"
			self.detected_object_topic = "camera/detected_objects"
			self.image_sub = self.create_subscription(Objects, self.detected_object_topic, self._on_detected_objects_callback, 10)
			self.detected_image_sub = self.create_subscription(Image, self.detected_object_img_topic, self._on_img_tracked_callback, 10)
		else:
			self.image_topic = "camera/color/image_raw"
		self.image_sub = self.create_subscription(Image, self.image_topic, self._on_img_callback, 10)
		self.mqtt_client = mqtt.Client()

		self.mqtt_client.connect("localhost", 1883, 60)
		self.br = CvBridge()
		print("image publisher up")
		
	def _image_to_base64(self, image):
		base64_img = cv2.imencode('.png', image)[1].tobytes()
		# self.get_logger().info("Encoding took {:.2f}ms".format((end-start)*1000))
		return base64.b64encode(base64_img)

	def _on_img_tracked_callback(self, msg):
		if msg != None:
			image = msg.data

			# np_arr = np.fromstring(np.array(image), np.uint8)
			object_frame = self.br.imgmsg_to_cv2(msg, 'bgr8')

			obj_frame_reduced = cv2.resize(object_frame,(480,360))

			base64_colour_string = self._image_to_base64(obj_frame_reduced)
			print(base64_colour_string)

			self.mqtt_client.publish("/camera/image", base64_colour_string)

	def _on_img_callback(self, msg):
		if msg != None:
			image = msg.data

			self.get_logger().info('<ImagePublisher> Receiving video frame')

			# np_arr = np.fromstring(np.array(image), np.uint8)
			self.current_frame = self.br.imgmsg_to_cv2(msg, 'bgr8')

	def _on_detected_objects_callback(self, msg):
		if msg != None:
			object_list = msg.objects

			num_detected_objects = len(object_list)
			self.mqtt_client.publish("/num_detected_objects", num_detected_objects)
			det_objects_dict = {}
			for det_object in object_list:
				x_min = int(det_object.x)
				y_min = int(det_object.y)

				width = int(det_object.width)
				height = int(det_object.height)

				x_max = int(x_min + width)
				y_max = int(y_min + width)

				label = det_object.label
				
				if self.current_frame is None:
					return
					
				curr_frame = self.current_frame.copy()

				cv2.rectangle(curr_frame, (x_min,y_min), (x_max,y_max), (255,0,0), 4)

				if ((y_max - y_min > 10) and (x_max - x_min > 10)):
					det_object_frame = self.current_frame[y_min:y_max,x_min:x_max]
					det_objects_b64 = self._image_to_base64(det_object_frame)

					if label in det_objects_dict:
						det_objects_dict[label].append(str(det_objects_b64))
					else:
						det_objects_dict[label] = [str(det_objects_b64)]

			# det_objects_b64 = {}
			# for det_object_frame in det_objects:
			#     det_objects_b64[]
			#     det_objects_b64.append(self._image_to_base64(det_object_frame))
			det_objects_json = json.dumps(det_objects_dict)
			self.mqtt_client.publish("/detected_objects_frame", det_objects_json)
			# cv2.imshow("Detected object", det_object_frame)
			# cv2.waitKey(0)

def main():
	rclpy.init()
	image_publisher_node = ImagePublisher()

	try:
		rclpy.spin(image_publisher_node)
	except KeyboardInterrupt:
		pass

	rclpy.shutdown()
