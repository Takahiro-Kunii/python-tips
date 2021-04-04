from distutils.core import setup, Extension

setup(name='wxy',
        version='1.0.0',
        ext_modules=[Extension('wxy', ['example.c'])]
)