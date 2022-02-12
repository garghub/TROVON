static inline struct trace_bprintk_fmt *lookup_format(const char *fmt)
{
struct trace_bprintk_fmt *pos;
list_for_each_entry(pos, &trace_bprintk_fmt_list, list) {
if (!strcmp(pos->fmt, fmt))
return pos;
}
return NULL;
}
static
void hold_module_trace_bprintk_format(const char **start, const char **end)
{
const char **iter;
char *fmt;
if (start != end)
trace_printk_init_buffers();
mutex_lock(&btrace_mutex);
for (iter = start; iter < end; iter++) {
struct trace_bprintk_fmt *tb_fmt = lookup_format(*iter);
if (tb_fmt) {
*iter = tb_fmt->fmt;
continue;
}
fmt = NULL;
tb_fmt = kmalloc(sizeof(*tb_fmt), GFP_KERNEL);
if (tb_fmt) {
fmt = kmalloc(strlen(*iter) + 1, GFP_KERNEL);
if (fmt) {
list_add_tail(&tb_fmt->list, &trace_bprintk_fmt_list);
strcpy(fmt, *iter);
tb_fmt->fmt = fmt;
} else
kfree(tb_fmt);
}
*iter = fmt;
}
mutex_unlock(&btrace_mutex);
}
static int module_trace_bprintk_format_notify(struct notifier_block *self,
unsigned long val, void *data)
{
struct module *mod = data;
if (mod->num_trace_bprintk_fmt) {
const char **start = mod->trace_bprintk_fmt_start;
const char **end = start + mod->num_trace_bprintk_fmt;
if (val == MODULE_STATE_COMING)
hold_module_trace_bprintk_format(start, end);
}
return 0;
}
static const char **
find_next_mod_format(int start_index, void *v, const char **fmt, loff_t *pos)
{
struct trace_bprintk_fmt *mod_fmt;
if (list_empty(&trace_bprintk_fmt_list))
return NULL;
if (!v || start_index == *pos) {
struct trace_bprintk_fmt *p;
list_for_each_entry(p, &trace_bprintk_fmt_list, list) {
if (start_index == *pos)
return &p->fmt;
start_index++;
}
return NULL;
}
mod_fmt = container_of(v, typeof(*mod_fmt), fmt);
if (mod_fmt->list.next == &trace_bprintk_fmt_list)
return NULL;
mod_fmt = container_of(mod_fmt->list.next, typeof(*mod_fmt), list);
return &mod_fmt->fmt;
}
static void format_mod_start(void)
{
mutex_lock(&btrace_mutex);
}
static void format_mod_stop(void)
{
mutex_unlock(&btrace_mutex);
}
__init static int
module_trace_bprintk_format_notify(struct notifier_block *self,
unsigned long val, void *data)
{
return 0;
}
static inline const char **
find_next_mod_format(int start_index, void *v, const char **fmt, loff_t *pos)
{
return NULL;
}
static inline void format_mod_start(void) { }
static inline void format_mod_stop(void) { }
int __trace_bprintk(unsigned long ip, const char *fmt, ...)
{
int ret;
va_list ap;
if (unlikely(!fmt))
return 0;
if (!(trace_flags & TRACE_ITER_PRINTK))
return 0;
va_start(ap, fmt);
ret = trace_vbprintk(ip, fmt, ap);
va_end(ap);
return ret;
}
int __ftrace_vbprintk(unsigned long ip, const char *fmt, va_list ap)
{
if (unlikely(!fmt))
return 0;
if (!(trace_flags & TRACE_ITER_PRINTK))
return 0;
return trace_vbprintk(ip, fmt, ap);
}
int __trace_printk(unsigned long ip, const char *fmt, ...)
{
int ret;
va_list ap;
if (!(trace_flags & TRACE_ITER_PRINTK))
return 0;
va_start(ap, fmt);
ret = trace_vprintk(ip, fmt, ap);
va_end(ap);
return ret;
}
int __ftrace_vprintk(unsigned long ip, const char *fmt, va_list ap)
{
if (!(trace_flags & TRACE_ITER_PRINTK))
return 0;
return trace_vprintk(ip, fmt, ap);
}
static const char **find_next(void *v, loff_t *pos)
{
const char **fmt = v;
int start_index;
int last_index;
start_index = __stop___trace_bprintk_fmt - __start___trace_bprintk_fmt;
if (*pos < start_index)
return __start___trace_bprintk_fmt + *pos;
last_index = start_index;
start_index = __stop___tracepoint_str - __start___tracepoint_str;
if (*pos < last_index + start_index)
return __start___tracepoint_str + (*pos - last_index);
return find_next_mod_format(start_index, v, fmt, pos);
}
static void *
t_start(struct seq_file *m, loff_t *pos)
{
format_mod_start();
return find_next(NULL, pos);
}
static void *t_next(struct seq_file *m, void * v, loff_t *pos)
{
(*pos)++;
return find_next(v, pos);
}
static int t_show(struct seq_file *m, void *v)
{
const char **fmt = v;
const char *str = *fmt;
int i;
seq_printf(m, "0x%lx : \"", *(unsigned long *)fmt);
for (i = 0; str[i]; i++) {
switch (str[i]) {
case '\n':
seq_puts(m, "\\n");
break;
case '\t':
seq_puts(m, "\\t");
break;
case '\\':
seq_puts(m, "\\");
break;
case '"':
seq_puts(m, "\\\"");
break;
default:
seq_putc(m, str[i]);
}
}
seq_puts(m, "\"\n");
return 0;
}
static void t_stop(struct seq_file *m, void *p)
{
format_mod_stop();
}
static int
ftrace_formats_open(struct inode *inode, struct file *file)
{
return seq_open(file, &show_format_seq_ops);
}
static __init int init_trace_printk_function_export(void)
{
struct dentry *d_tracer;
d_tracer = tracing_init_dentry();
if (!d_tracer)
return 0;
trace_create_file("printk_formats", 0444, d_tracer,
NULL, &ftrace_formats_fops);
return 0;
}
static __init int init_trace_printk(void)
{
return register_module_notifier(&module_trace_bprintk_format_nb);
}
