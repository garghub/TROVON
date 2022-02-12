static const char *xen_hypercall_name(unsigned op)
{
if (op < ARRAY_SIZE(xen_hypercall_names) &&
xen_hypercall_names[op] != NULL)
return xen_hypercall_names[op];
return "";
}
unsigned long long process_xen_hypercall_name(struct trace_seq *s,
unsigned long long *args)
{
unsigned int op = args[0];
trace_seq_printf(s, "%s", xen_hypercall_name(op));
return 0;
}
int PEVENT_PLUGIN_LOADER(struct pevent *pevent)
{
pevent_register_print_function(pevent,
process_xen_hypercall_name,
PEVENT_FUNC_ARG_STRING,
"xen_hypercall_name",
PEVENT_FUNC_ARG_INT,
PEVENT_FUNC_ARG_VOID);
return 0;
}
void PEVENT_PLUGIN_UNLOADER(struct pevent *pevent)
{
pevent_unregister_print_function(pevent, process_xen_hypercall_name,
"xen_hypercall_name");
}
