import sys
if sys.prefix == '/home/schmelz/atmos-control/ros2_workspace':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/schmelz/atmos-control/install/px4_mpc'
