import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/amr01/workspace/robofun-1.0/object-detection-ws/install/scuttle_mqtt'
