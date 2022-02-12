static inline
void wspy_init(void)
{
Py_Initialize();
}
static inline
void wspy_finalize(void)
{
Py_Finalize();
}
char * py_dissector_name(PyObject * py_dissector)
{
PyObject * py_object_name;
assert(py_dissector);
py_object_name = PyObject_Str(py_dissector);
return PyString_AS_STRING(py_object_name);
}
void py_dissector_register(PyObject * py_dissector)
{
PyObject_CallMethod(py_dissector, "register_protocol", NULL);
}
static const char *get_py_register_file(void)
{
static const char * wspython_register_file = NULL;
if (!wspython_register_file) {
#ifdef _WIN32
wspython_register_file = g_strdup_printf("%s\\register-dissector.py", get_wspython_dir());
#else
wspython_register_file = g_strdup_printf("%s/register-dissector.py", get_wspython_dir());
#endif
}
return wspython_register_file;
}
void register_all_py_protocols_func(void)
{
FILE * py_reg;
PyObject * global_dict, * main_module, * register_fn;
PyObject * py_dissectors, * py_dissector;
PyObject * py_args;
Py_ssize_t index;
char * name;
g_py_dissectors = g_hash_table_new(g_str_hash, g_str_equal);
wspy_init();
py_reg = fopen(get_py_register_file(), "r");
if (py_reg == NULL) {
printf("Can't open Python registration file: %s\n", get_py_register_file());
return;
}
PyRun_SimpleFile(py_reg, get_py_register_file());
main_module = PyImport_AddModule("__main__");
global_dict = PyModule_GetDict(main_module);
register_fn = PyDict_GetItemString(global_dict, "register_dissectors");
if (register_fn == NULL) {
printf("Error in Python registration file: %s\n", get_py_register_file());
return;
}
py_args = Py_BuildValue("ss", get_wspython_dir(), get_plugins_pers_dir());
py_dissectors = PyObject_CallObject(register_fn, py_args);
if (!py_dissectors || !PySequence_Check(py_dissectors)) {
printf("Python dissectors not registered ...\n");
return;
}
for (index = 0; (py_dissector = PySequence_GetItem(py_dissectors, index)); index++)
{
name = py_dissector_name(py_dissector);
py_dissector_register(py_dissector);
g_hash_table_insert(g_py_dissectors, (gpointer*)name, py_dissector);
}
}
void py_dissector_args(tvbuff_t ** tvb, packet_info ** pinfo, proto_tree ** tree)
{
*tvb = g_tvb;
*pinfo = g_pinfo;
*tree = g_tree;
}
void py_dissect(tvbuff_t * tvb, packet_info * pinfo,
proto_tree * tree)
{
PyObject * py_dissector;
g_tree = tree;
g_pinfo = pinfo;
g_tvb = tvb;
py_dissector = g_hash_table_lookup(g_py_dissectors, pinfo->current_proto);
assert(py_dissector);
PyObject_CallMethod(py_dissector, "pre_dissect", NULL);
}
dissector_handle_t py_create_dissector_handle(const int proto)
{
return create_dissector_handle(&py_dissect, proto);
}
static void register_all_py_handoffs_foreach(gpointer key _U_, gpointer value, gpointer user_data _U_)
{
PyObject * py_dissector = (PyObject *)value;
PyObject_CallMethod(py_dissector, "register_handoff", NULL);
}
void
register_all_py_handoffs_func(void)
{
g_hash_table_foreach(g_py_dissectors, register_all_py_handoffs_foreach, NULL);
}
