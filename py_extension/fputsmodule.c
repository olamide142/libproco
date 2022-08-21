#include <Python.h>
#include <stdio.h>

// CC=gcc python setup.py install

int fputs(const char*, FILE*);


static PyObject *method_fputs(PyObject *self, PyObject *args) {
	
	char *str, *filename = NULL;
	int bytes_copied = -1;

	if (!PyArg_ParseTuple(args, "ss", &str, &filename)) {
		return NULL;
	}

	FILE *fp = fopen(filename, "w");
	bytes_copied = fputs(str, fp);
	fclose(fp);

	return PyLong_FromLong(bytes_copied);
}


static PyMethodDef FputsMethods[] = {
	
	{"fputs", method_fputs, METH_VARARGS, "Python interface for fputs C lib function"},
	{NULL, NULL, 0, NULL}

};


static struct PyModuleDef fputsmodule = {
	
	PyModuleDef_HEAD_INIT,
	"fputs",
	"Python interface for fputs C lib function",
	-1,
	FputsMethods
};

PyMODINIT_FUNC PyInit_fputs(void) {

	return PyModule_Create(&fputsmodule);
}

int main(int argc, char *argv[]){

	return 0;
}
