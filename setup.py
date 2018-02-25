
from setuptools import setup
from setuptools import Extension

ext_FieldFileSetup = Extension(
    '_FieldFileSetup',
    sources=['FieldFileSetup_wrap.cxx', 'FieldFileSetup.cpp'],
)

if __name__ == '__main__':
    setup(
        name='FieldFileSetup',
        version='0.0.1',
        description='SWIG Example package',
        ext_modules=[ext_FieldFileSetup],
        py_modules=['FieldFileSetup'],
    )