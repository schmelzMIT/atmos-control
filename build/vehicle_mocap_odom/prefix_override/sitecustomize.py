import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/schmelz/atmos-control/install/vehicle_mocap_odom'
