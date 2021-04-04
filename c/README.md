# CでPythonから使えるモジュールを書くには

* [Python C API](https://docs.python.org/ja/3/extending/extending.html)を使う

例）Cでwxyというモジュールを作る
```
import wxy

wxy.hello()
```
### 流れ
1. Python C API（Python.h）を使いC/C++でモジュール`wxy`作成
1. ビルド `wxy.so`ができる

本格利用なら追加作業
1. soファイルをインストールしてpipで管理
1. pipで管理している`wxy`をimportして*.pyで使う

### Python C API


用意するファイル
* Cソースファイル
* モジュール作成用スクリプトファイル

#### Cソースファイル
##### example.c
```
#include <Python.h>

///  hello_from_c()
static PyObject* hello_from_c(PyObject *self, PyObject *args) {
  printf("Hello from c\n");
  return Py_None;
}

///  モジュールが提供するメソッド定義
static PyMethodDef methods[] = {
  {"hello", (PyCFunction)hello_from_c, METH_NOARGS, "wxy.helloはコンソールにHello from cを出力する"},
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
```

#### モジュールが提供するメソッド定義
```
static PyMethodDef methods[] = {
    { "Python側メソッド名", {C関数名}, 引数の指定フラグ, "関数の説明" },
    ・
    ・　メソッド分の繰り返し
    ・
    { NULL }
};
```
#### モジュールが提供するメソッド定義
```
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "Python側モジュール名", "モジュールの説明", -1, {PyMethodDef配列として定義した変数名}(methods)
};
```
#### モジュールの初期化
```
PyMODINIT_FUNC PyInit_{Python側モジュール名}(void)
{
    return PyModule_Create(&{struct PyModuleDefで定義した変数});
}
```

#### モジュール作成用スクリプトファイル
##### setup.py
```
from distutils.core import setup, Extension

setup(name='wxy',
        version='1.0.0',
        ext_modules=[Extension('wxy', ['example.c'])]
)
```

Scriptの決まり

```
from distutils.core import setup, Extension
 
setup(name = 'pipの登録名', version = '1.0.0',  \
   ext_modules = [Extension('モジュール名', ['C/C++ソースファイル'])])
```

### ビルド実行

インストールまではしない

> python setup.py build_ext -i


> python setup.py install

### 利用


```
import wxy

# まずは、動作検証
wxy.hello()
```
