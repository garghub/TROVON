static int get_common_field(struct scripting_context *context,
int *offset, int *size, const char *type)
{
struct pevent *pevent = context->pevent;
struct event_format *event;
struct format_field *field;
if (!*size) {
if (!pevent->events)
return 0;
event = pevent->events[0];
field = pevent_find_common_field(event, type);
if (!field)
return 0;
*offset = field->offset;
*size = field->size;
}
return pevent_read_number(pevent, context->event_data + *offset, *size);
}
int common_lock_depth(struct scripting_context *context)
{
static int offset;
static int size;
int ret;
ret = get_common_field(context, &size, &offset,
"common_lock_depth");
if (ret < 0)
return -1;
return ret;
}
int common_flags(struct scripting_context *context)
{
static int offset;
static int size;
int ret;
ret = get_common_field(context, &size, &offset,
"common_flags");
if (ret < 0)
return -1;
return ret;
}
int common_pc(struct scripting_context *context)
{
static int offset;
static int size;
int ret;
ret = get_common_field(context, &size, &offset,
"common_preempt_count");
if (ret < 0)
return -1;
return ret;
}
unsigned long long
raw_field_value(struct event_format *event, const char *name, void *data)
{
struct format_field *field;
unsigned long long val;
field = pevent_find_any_field(event, name);
if (!field)
return 0ULL;
pevent_read_number_field(field, data, &val);
return val;
}
unsigned long long read_size(struct event_format *event, void *ptr, int size)
{
return pevent_read_number(event->pevent, ptr, size);
}
void event_format__print(struct event_format *event,
int cpu, void *data, int size)
{
struct pevent_record record;
struct trace_seq s;
memset(&record, 0, sizeof(record));
record.cpu = cpu;
record.size = size;
record.data = data;
trace_seq_init(&s);
pevent_event_info(&s, event, &record);
trace_seq_do_printf(&s);
trace_seq_destroy(&s);
}
void parse_proc_kallsyms(struct pevent *pevent,
char *file, unsigned int size __maybe_unused)
{
unsigned long long addr;
char *func;
char *line;
char *next = NULL;
char *addr_str;
char *mod;
char *fmt = NULL;
line = strtok_r(file, "\n", &next);
while (line) {
mod = NULL;
addr_str = strtok_r(line, " ", &fmt);
addr = strtoull(addr_str, NULL, 16);
strtok_r(NULL, " ", &fmt);
func = strtok_r(NULL, "\t", &fmt);
mod = strtok_r(NULL, "]", &fmt);
if (mod)
mod = mod + 1;
pevent_register_function(pevent, func, addr, mod);
line = strtok_r(NULL, "\n", &next);
}
}
void parse_ftrace_printk(struct pevent *pevent,
char *file, unsigned int size __maybe_unused)
{
unsigned long long addr;
char *printk;
char *line;
char *next = NULL;
char *addr_str;
char *fmt;
line = strtok_r(file, "\n", &next);
while (line) {
addr_str = strtok_r(line, ":", &fmt);
if (!addr_str) {
warning("printk format with empty entry");
break;
}
addr = strtoull(addr_str, NULL, 16);
printk = strdup(fmt+1);
line = strtok_r(NULL, "\n", &next);
pevent_register_print_string(pevent, printk, addr);
}
}
int parse_ftrace_file(struct pevent *pevent, char *buf, unsigned long size)
{
return pevent_parse_event(pevent, buf, size, "ftrace");
}
int parse_event_file(struct pevent *pevent,
char *buf, unsigned long size, char *sys)
{
return pevent_parse_event(pevent, buf, size, sys);
}
struct event_format *trace_find_next_event(struct pevent *pevent,
struct event_format *event)
{
static int idx;
if (!pevent || !pevent->events)
return NULL;
if (!event) {
idx = 0;
return pevent->events[0];
}
if (idx < pevent->nr_events && event == pevent->events[idx]) {
idx++;
if (idx == pevent->nr_events)
return NULL;
return pevent->events[idx];
}
for (idx = 1; idx < pevent->nr_events; idx++) {
if (event == pevent->events[idx - 1])
return pevent->events[idx];
}
return NULL;
}
unsigned long long eval_flag(const char *flag)
{
int i;
if (isdigit(flag[0]))
return strtoull(flag, NULL, 0);
for (i = 0; i < (int)(sizeof(flags)/sizeof(flags[0])); i++)
if (strcmp(flags[i].name, flag) == 0)
return flags[i].value;
return 0;
}
