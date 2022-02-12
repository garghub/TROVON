static PyObject *perf_trace_context_common_pc(PyObject *obj, PyObject *args)
{
static struct scripting_context *scripting_context;
PyObject *context;
int retval;
if (!PyArg_ParseTuple(args, "O", &context))
return NULL;
scripting_context = PyCObject_AsVoidPtr(context);
retval = common_pc(scripting_context);
return Py_BuildValue("i", retval);
}
static PyObject *perf_trace_context_common_flags(PyObject *obj,
PyObject *args)
{
static struct scripting_context *scripting_context;
PyObject *context;
int retval;
if (!PyArg_ParseTuple(args, "O", &context))
return NULL;
scripting_context = PyCObject_AsVoidPtr(context);
retval = common_flags(scripting_context);
return Py_BuildValue("i", retval);
}
static PyObject *perf_trace_context_common_lock_depth(PyObject *obj,
PyObject *args)
{
static struct scripting_context *scripting_context;
PyObject *context;
int retval;
if (!PyArg_ParseTuple(args, "O", &context))
return NULL;
scripting_context = PyCObject_AsVoidPtr(context);
retval = common_lock_depth(scripting_context);
return Py_BuildValue("i", retval);
}
PyMODINIT_FUNC initperf_trace_context(void)
{
(void) Py_InitModule("perf_trace_context", ContextMethods);
}
