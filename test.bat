swig -c++ -python FieldFileSetup.i

python setup.py build_ext --inplace

python main.py