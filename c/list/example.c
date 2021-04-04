#include <Python.h>

///  wxy.hello()
static PyObject* hello_from_c(PyObject *self, PyObject *args) {
  printf("Hello from c\n");
  return Py_None;
}

/// c = wxy.add(1, 2)
static PyObject* add(PyObject *self, PyObject *args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)){
    return NULL;
  }
  int c = a + b;
  return Py_BuildValue("i", c);
}

/// c = wxy.add_to([1, 2], 3)
static PyObject* add_to(PyObject *self, PyObject *args) {
  PyObject *list;
  int c;
  //    O! (object) [typeobject, PyObject *] typeobjectで指定した型でなければエラー
  //    &PyList_Type でリストを指定　&list　に受ける
  if (!PyArg_ParseTuple(args, "O!i", &PyList_Type, &list, &c)){
    return NULL;
  }

  // リストのサイズ取得
  int size = PyList_Size(list);
  // 値を抽出 
  for (int i = 0; i < size; i++) {
    PyObject* v_obj = PyList_GetItem(list, i);
    int value = PyLong_AsLong(v_obj);
    printf("要素%d=%d\n", i, value);
  }

  PyObject* added_list = PySequence_List(list);   //  出力先作成
  PyList_Append(added_list, Py_BuildValue("i", c)); //  加算
  return added_list;
}

///  モジュールが提供するメソッド定義
static PyMethodDef methods[] = {
  {"hello", (PyCFunction)hello_from_c, METH_NOARGS, "wxy.helloはコンソールにHello from cを出力する"},
  {"add", (PyCFunction)add, METH_VARARGS, "wxy.add(a, b)はa + bを返す"},
  {"add_to", (PyCFunction)add_to, METH_VARARGS, "wxy.add_to([a, b], c)は[a,b]にcを加えた新しいリストを返す"},
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
