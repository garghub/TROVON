static unsigned long long
process_jbd2_dev_to_name(struct trace_seq *s, unsigned long long *args)
{
unsigned int dev = args[0];
trace_seq_printf(s, "%d:%d", MAJOR(dev), MINOR(dev));
return 0;
}
static unsigned long long
process_jiffies_to_msecs(struct trace_seq *s, unsigned long long *args)
{
unsigned long long jiffies = args[0];
trace_seq_printf(s, "%lld", jiffies);
return jiffies;
}
int PEVENT_PLUGIN_LOADER(struct pevent *pevent)
{
pevent_register_print_function(pevent,
process_jbd2_dev_to_name,
PEVENT_FUNC_ARG_STRING,
"jbd2_dev_to_name",
PEVENT_FUNC_ARG_INT,
PEVENT_FUNC_ARG_VOID);
pevent_register_print_function(pevent,
process_jiffies_to_msecs,
PEVENT_FUNC_ARG_LONG,
"jiffies_to_msecs",
PEVENT_FUNC_ARG_LONG,
PEVENT_FUNC_ARG_VOID);
return 0;
}
void PEVENT_PLUGIN_UNLOADER(struct pevent *pevent)
{
pevent_unregister_print_function(pevent, process_jbd2_dev_to_name,
"jbd2_dev_to_name");
pevent_unregister_print_function(pevent, process_jiffies_to_msecs,
"jiffies_to_msecs");
}
