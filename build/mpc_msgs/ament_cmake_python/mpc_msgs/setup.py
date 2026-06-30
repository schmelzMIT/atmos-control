from setuptools import find_packages
from setuptools import setup

setup(
    name='mpc_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('mpc_msgs', 'mpc_msgs.*')),
)
