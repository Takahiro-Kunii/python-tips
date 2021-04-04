```
static PyObject* add(PyObject *self, PyObject *args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)){
    return NULL;
  }
  int c = a + b;
  return Py_BuildValue("i", c);
}

static PyMethodDef methods[] = {
  
  {"add", (PyCFunction)add, METH_VARARGS, "wxy.add(a, b)はa + bを返す"},
  {NULL}
};
```

### 引数


>  if (!PyArg_ParseTuple(args, "ii", &a, &b)){

"ii"が引数の数や型を示す

https://docs.python.org/3.6/c-api/arg.html#numbers


### 戻り値

> Py_BuildValue("i", c)


### 利用

```
# 加算と結果
print(wxy.add(1, 2))

```
