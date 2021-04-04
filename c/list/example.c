#include <Python.h>

///  hello_from_c()
static PyObject* hello_from_c(PyObject *self, PyObject *args) {
  printf("Hello from c\n");
  return Py_None;
}

static PyObject* add(PyObject *self, PyObject *args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)){
    return NULL;
  }
  int c = a + b;
  return Py_BuildValue("i", c);
}

///  モジュールが提供するメソッド定義
static PyMethodDef methods[] = {
  {"hello", (PyCFunction)hello_from_c, METH_NOARGS, "wxy.helloはコンソールにHello from cを出力する"},
  {"add", (PyCFunction)add, METH_VARARGS, "wxy.add(a, b)はa + bを返す"},
  {NULL}
};

///  モジュール定義
static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT, "wxy", "モジュール：wxyの説明", -1, methods
};

/// モジュールの初期化
PyMODINIT_FUNC PyInit_wxy(void) {
  return PyModule_Create(&module);
}
