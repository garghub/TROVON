static inline int system_refcount(struct event_subsystem *system)
{
return system->ref_count & ~SYSTEM_FL_FREE_NAME;
}
static int system_refcount_inc(struct event_subsystem *system)
{
return (system->ref_count++) & ~SYSTEM_FL_FREE_NAME;
}
static int system_refcount_dec(struct event_subsystem *system)
{
return (--system->ref_count) & ~SYSTEM_FL_FREE_NAME;
}
static struct list_head *
trace_get_fields(struct ftrace_event_call *event_call)
{
if (!event_call->class->get_fields)
return &event_call->class->fields;
return event_call->class->get_fields(event_call);
}
static struct ftrace_event_field *
__find_event_field(struct list_head *head, char *name)
{
struct ftrace_event_field *field;
list_for_each_entry(field, head, link) {
if (!strcmp(field->name, name))
return field;
}
return NULL;
}
struct ftrace_event_field *
trace_find_event_field(struct ftrace_event_call *call, char *name)
{
struct ftrace_event_field *field;
struct list_head *head;
field = __find_event_field(&ftrace_common_fields, name);
if (field)
return field;
head = trace_get_fields(call);
return __find_event_field(head, name);
}
static int __trace_define_field(struct list_head *head, const char *type,
const char *name, int offset, int size,
int is_signed, int filter_type)
{
struct ftrace_event_field *field;
field = kmem_cache_alloc(field_cachep, GFP_TRACE);
if (!field)
return -ENOMEM;
field->name = name;
field->type = type;
if (filter_type == FILTER_OTHER)
field->filter_type = filter_assign_type(type);
else
field->filter_type = filter_type;
field->offset = offset;
field->size = size;
field->is_signed = is_signed;
list_add(&field->link, head);
return 0;
}
int trace_define_field(struct ftrace_event_call *call, const char *type,
const char *name, int offset, int size, int is_signed,
int filter_type)
{
struct list_head *head;
if (WARN_ON(!call->class))
return 0;
head = trace_get_fields(call);
return __trace_define_field(head, type, name, offset, size,
is_signed, filter_type);
}
static int trace_define_common_fields(void)
{
int ret;
struct trace_entry ent;
__common_field(unsigned short, type);
__common_field(unsigned char, flags);
__common_field(unsigned char, preempt_count);
__common_field(int, pid);
return ret;
}
static void trace_destroy_fields(struct ftrace_event_call *call)
{
struct ftrace_event_field *field, *next;
struct list_head *head;
head = trace_get_fields(call);
list_for_each_entry_safe(field, next, head, link) {
list_del(&field->link);
kmem_cache_free(field_cachep, field);
}
}
int trace_event_raw_init(struct ftrace_event_call *call)
{
int id;
id = register_ftrace_event(&call->event);
if (!id)
return -ENODEV;
return 0;
}
int ftrace_event_reg(struct ftrace_event_call *call,
enum trace_reg type, void *data)
{
struct ftrace_event_file *file = data;
switch (type) {
case TRACE_REG_REGISTER:
return tracepoint_probe_register(call->name,
call->class->probe,
file);
case TRACE_REG_UNREGISTER:
tracepoint_probe_unregister(call->name,
call->class->probe,
file);
return 0;
#ifdef CONFIG_PERF_EVENTS
case TRACE_REG_PERF_REGISTER:
return tracepoint_probe_register(call->name,
call->class->perf_probe,
call);
case TRACE_REG_PERF_UNREGISTER:
tracepoint_probe_unregister(call->name,
call->class->perf_probe,
call);
return 0;
case TRACE_REG_PERF_OPEN:
case TRACE_REG_PERF_CLOSE:
case TRACE_REG_PERF_ADD:
case TRACE_REG_PERF_DEL:
return 0;
#endif
}
return 0;
}
void trace_event_enable_cmd_record(bool enable)
{
struct ftrace_event_file *file;
struct trace_array *tr;
mutex_lock(&event_mutex);
do_for_each_event_file(tr, file) {
if (!(file->flags & FTRACE_EVENT_FL_ENABLED))
continue;
if (enable) {
tracing_start_cmdline_record();
set_bit(FTRACE_EVENT_FL_RECORDED_CMD_BIT, &file->flags);
} else {
tracing_stop_cmdline_record();
clear_bit(FTRACE_EVENT_FL_RECORDED_CMD_BIT, &file->flags);
}
} while_for_each_event_file();
mutex_unlock(&event_mutex);
}
static int __ftrace_event_enable_disable(struct ftrace_event_file *file,
int enable, int soft_disable)
{
struct ftrace_event_call *call = file->event_call;
int ret = 0;
int disable;
switch (enable) {
case 0:
if (soft_disable) {
if (atomic_dec_return(&file->sm_ref) > 0)
break;
disable = file->flags & FTRACE_EVENT_FL_SOFT_DISABLED;
clear_bit(FTRACE_EVENT_FL_SOFT_MODE_BIT, &file->flags);
} else
disable = !(file->flags & FTRACE_EVENT_FL_SOFT_MODE);
if (disable && (file->flags & FTRACE_EVENT_FL_ENABLED)) {
clear_bit(FTRACE_EVENT_FL_ENABLED_BIT, &file->flags);
if (file->flags & FTRACE_EVENT_FL_RECORDED_CMD) {
tracing_stop_cmdline_record();
clear_bit(FTRACE_EVENT_FL_RECORDED_CMD_BIT, &file->flags);
}
call->class->reg(call, TRACE_REG_UNREGISTER, file);
}
if (file->flags & FTRACE_EVENT_FL_SOFT_MODE)
set_bit(FTRACE_EVENT_FL_SOFT_DISABLED_BIT, &file->flags);
else
clear_bit(FTRACE_EVENT_FL_SOFT_DISABLED_BIT, &file->flags);
break;
case 1:
if (!soft_disable)
clear_bit(FTRACE_EVENT_FL_SOFT_DISABLED_BIT, &file->flags);
else {
if (atomic_inc_return(&file->sm_ref) > 1)
break;
set_bit(FTRACE_EVENT_FL_SOFT_MODE_BIT, &file->flags);
}
if (!(file->flags & FTRACE_EVENT_FL_ENABLED)) {
if (soft_disable)
set_bit(FTRACE_EVENT_FL_SOFT_DISABLED_BIT, &file->flags);
if (trace_flags & TRACE_ITER_RECORD_CMD) {
tracing_start_cmdline_record();
set_bit(FTRACE_EVENT_FL_RECORDED_CMD_BIT, &file->flags);
}
ret = call->class->reg(call, TRACE_REG_REGISTER, file);
if (ret) {
tracing_stop_cmdline_record();
pr_info("event trace: Could not enable event "
"%s\n", call->name);
break;
}
set_bit(FTRACE_EVENT_FL_ENABLED_BIT, &file->flags);
call->flags |= TRACE_EVENT_FL_WAS_ENABLED;
}
break;
}
return ret;
}
static int ftrace_event_enable_disable(struct ftrace_event_file *file,
int enable)
{
return __ftrace_event_enable_disable(file, enable, 0);
}
static void ftrace_clear_events(struct trace_array *tr)
{
struct ftrace_event_file *file;
mutex_lock(&event_mutex);
list_for_each_entry(file, &tr->events, list) {
ftrace_event_enable_disable(file, 0);
}
mutex_unlock(&event_mutex);
}
static void __put_system(struct event_subsystem *system)
{
struct event_filter *filter = system->filter;
WARN_ON_ONCE(system_refcount(system) == 0);
if (system_refcount_dec(system))
return;
list_del(&system->list);
if (filter) {
kfree(filter->filter_string);
kfree(filter);
}
if (system->ref_count & SYSTEM_FL_FREE_NAME)
kfree(system->name);
kfree(system);
}
static void __get_system(struct event_subsystem *system)
{
WARN_ON_ONCE(system_refcount(system) == 0);
system_refcount_inc(system);
}
static void __get_system_dir(struct ftrace_subsystem_dir *dir)
{
WARN_ON_ONCE(dir->ref_count == 0);
dir->ref_count++;
__get_system(dir->subsystem);
}
static void __put_system_dir(struct ftrace_subsystem_dir *dir)
{
WARN_ON_ONCE(dir->ref_count == 0);
WARN_ON_ONCE(system_refcount(dir->subsystem) == 1 && dir->ref_count != 1);
__put_system(dir->subsystem);
if (!--dir->ref_count)
kfree(dir);
}
static void put_system(struct ftrace_subsystem_dir *dir)
{
mutex_lock(&event_mutex);
__put_system_dir(dir);
mutex_unlock(&event_mutex);
}
static void remove_subsystem(struct ftrace_subsystem_dir *dir)
{
if (!dir)
return;
if (!--dir->nr_events) {
debugfs_remove_recursive(dir->entry);
list_del(&dir->list);
__put_system_dir(dir);
}
}
static void *event_file_data(struct file *filp)
{
return ACCESS_ONCE(file_inode(filp)->i_private);
}
static void remove_event_file_dir(struct ftrace_event_file *file)
{
struct dentry *dir = file->dir;
struct dentry *child;
if (dir) {
spin_lock(&dir->d_lock);
list_for_each_entry(child, &dir->d_subdirs, d_u.d_child) {
if (child->d_inode)
child->d_inode->i_private = NULL;
}
spin_unlock(&dir->d_lock);
debugfs_remove_recursive(dir);
}
list_del(&file->list);
remove_subsystem(file->system);
kmem_cache_free(file_cachep, file);
}
static int
__ftrace_set_clr_event_nolock(struct trace_array *tr, const char *match,
const char *sub, const char *event, int set)
{
struct ftrace_event_file *file;
struct ftrace_event_call *call;
int ret = -EINVAL;
list_for_each_entry(file, &tr->events, list) {
call = file->event_call;
if (!call->name || !call->class || !call->class->reg)
continue;
if (call->flags & TRACE_EVENT_FL_IGNORE_ENABLE)
continue;
if (match &&
strcmp(match, call->name) != 0 &&
strcmp(match, call->class->system) != 0)
continue;
if (sub && strcmp(sub, call->class->system) != 0)
continue;
if (event && strcmp(event, call->name) != 0)
continue;
ftrace_event_enable_disable(file, set);
ret = 0;
}
return ret;
}
static int __ftrace_set_clr_event(struct trace_array *tr, const char *match,
const char *sub, const char *event, int set)
{
int ret;
mutex_lock(&event_mutex);
ret = __ftrace_set_clr_event_nolock(tr, match, sub, event, set);
mutex_unlock(&event_mutex);
return ret;
}
static int ftrace_set_clr_event(struct trace_array *tr, char *buf, int set)
{
char *event = NULL, *sub = NULL, *match;
match = strsep(&buf, ":");
if (buf) {
sub = match;
event = buf;
match = NULL;
if (!strlen(sub) || strcmp(sub, "*") == 0)
sub = NULL;
if (!strlen(event) || strcmp(event, "*") == 0)
event = NULL;
}
return __ftrace_set_clr_event(tr, match, sub, event, set);
}
int trace_set_clr_event(const char *system, const char *event, int set)
{
struct trace_array *tr = top_trace_array();
return __ftrace_set_clr_event(tr, NULL, system, event, set);
}
static ssize_t
ftrace_event_write(struct file *file, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
struct trace_parser parser;
struct seq_file *m = file->private_data;
struct trace_array *tr = m->private;
ssize_t read, ret;
if (!cnt)
return 0;
ret = tracing_update_buffers();
if (ret < 0)
return ret;
if (trace_parser_get_init(&parser, EVENT_BUF_SIZE + 1))
return -ENOMEM;
read = trace_get_user(&parser, ubuf, cnt, ppos);
if (read >= 0 && trace_parser_loaded((&parser))) {
int set = 1;
if (*parser.buffer == '!')
set = 0;
parser.buffer[parser.idx] = 0;
ret = ftrace_set_clr_event(tr, parser.buffer + !set, set);
if (ret)
goto out_put;
}
ret = read;
out_put:
trace_parser_put(&parser);
return ret;
}
static void *
t_next(struct seq_file *m, void *v, loff_t *pos)
{
struct ftrace_event_file *file = v;
struct ftrace_event_call *call;
struct trace_array *tr = m->private;
(*pos)++;
list_for_each_entry_continue(file, &tr->events, list) {
call = file->event_call;
if (call->class && call->class->reg)
return file;
}
return NULL;
}
static void *t_start(struct seq_file *m, loff_t *pos)
{
struct ftrace_event_file *file;
struct trace_array *tr = m->private;
loff_t l;
mutex_lock(&event_mutex);
file = list_entry(&tr->events, struct ftrace_event_file, list);
for (l = 0; l <= *pos; ) {
file = t_next(m, file, &l);
if (!file)
break;
}
return file;
}
static void *
s_next(struct seq_file *m, void *v, loff_t *pos)
{
struct ftrace_event_file *file = v;
struct trace_array *tr = m->private;
(*pos)++;
list_for_each_entry_continue(file, &tr->events, list) {
if (file->flags & FTRACE_EVENT_FL_ENABLED)
return file;
}
return NULL;
}
static void *s_start(struct seq_file *m, loff_t *pos)
{
struct ftrace_event_file *file;
struct trace_array *tr = m->private;
loff_t l;
mutex_lock(&event_mutex);
file = list_entry(&tr->events, struct ftrace_event_file, list);
for (l = 0; l <= *pos; ) {
file = s_next(m, file, &l);
if (!file)
break;
}
return file;
}
static int t_show(struct seq_file *m, void *v)
{
struct ftrace_event_file *file = v;
struct ftrace_event_call *call = file->event_call;
if (strcmp(call->class->system, TRACE_SYSTEM) != 0)
seq_printf(m, "%s:", call->class->system);
seq_printf(m, "%s\n", call->name);
return 0;
}
static void t_stop(struct seq_file *m, void *p)
{
mutex_unlock(&event_mutex);
}
static ssize_t
event_enable_read(struct file *filp, char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_event_file *file;
unsigned long flags;
char buf[4] = "0";
mutex_lock(&event_mutex);
file = event_file_data(filp);
if (likely(file))
flags = file->flags;
mutex_unlock(&event_mutex);
if (!file)
return -ENODEV;
if (flags & FTRACE_EVENT_FL_ENABLED &&
!(flags & FTRACE_EVENT_FL_SOFT_DISABLED))
strcpy(buf, "1");
if (flags & FTRACE_EVENT_FL_SOFT_DISABLED ||
flags & FTRACE_EVENT_FL_SOFT_MODE)
strcat(buf, "*");
strcat(buf, "\n");
return simple_read_from_buffer(ubuf, cnt, ppos, buf, strlen(buf));
}
static ssize_t
event_enable_write(struct file *filp, const char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_event_file *file;
unsigned long val;
int ret;
ret = kstrtoul_from_user(ubuf, cnt, 10, &val);
if (ret)
return ret;
ret = tracing_update_buffers();
if (ret < 0)
return ret;
switch (val) {
case 0:
case 1:
ret = -ENODEV;
mutex_lock(&event_mutex);
file = event_file_data(filp);
if (likely(file))
ret = ftrace_event_enable_disable(file, val);
mutex_unlock(&event_mutex);
break;
default:
return -EINVAL;
}
*ppos += cnt;
return ret ? ret : cnt;
}
static ssize_t
system_enable_read(struct file *filp, char __user *ubuf, size_t cnt,
loff_t *ppos)
{
const char set_to_char[4] = { '?', '0', '1', 'X' };
struct ftrace_subsystem_dir *dir = filp->private_data;
struct event_subsystem *system = dir->subsystem;
struct ftrace_event_call *call;
struct ftrace_event_file *file;
struct trace_array *tr = dir->tr;
char buf[2];
int set = 0;
int ret;
mutex_lock(&event_mutex);
list_for_each_entry(file, &tr->events, list) {
call = file->event_call;
if (!call->name || !call->class || !call->class->reg)
continue;
if (system && strcmp(call->class->system, system->name) != 0)
continue;
set |= (1 << !!(file->flags & FTRACE_EVENT_FL_ENABLED));
if (set == 3)
break;
}
mutex_unlock(&event_mutex);
buf[0] = set_to_char[set];
buf[1] = '\n';
ret = simple_read_from_buffer(ubuf, cnt, ppos, buf, 2);
return ret;
}
static ssize_t
system_enable_write(struct file *filp, const char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_subsystem_dir *dir = filp->private_data;
struct event_subsystem *system = dir->subsystem;
const char *name = NULL;
unsigned long val;
ssize_t ret;
ret = kstrtoul_from_user(ubuf, cnt, 10, &val);
if (ret)
return ret;
ret = tracing_update_buffers();
if (ret < 0)
return ret;
if (val != 0 && val != 1)
return -EINVAL;
if (system)
name = system->name;
ret = __ftrace_set_clr_event(dir->tr, NULL, name, NULL, val);
if (ret)
goto out;
ret = cnt;
out:
*ppos += cnt;
return ret;
}
static void *f_next(struct seq_file *m, void *v, loff_t *pos)
{
struct ftrace_event_call *call = event_file_data(m->private);
struct list_head *common_head = &ftrace_common_fields;
struct list_head *head = trace_get_fields(call);
struct list_head *node = v;
(*pos)++;
switch ((unsigned long)v) {
case FORMAT_HEADER:
node = common_head;
break;
case FORMAT_FIELD_SEPERATOR:
node = head;
break;
case FORMAT_PRINTFMT:
return NULL;
}
node = node->prev;
if (node == common_head)
return (void *)FORMAT_FIELD_SEPERATOR;
else if (node == head)
return (void *)FORMAT_PRINTFMT;
else
return node;
}
static int f_show(struct seq_file *m, void *v)
{
struct ftrace_event_call *call = event_file_data(m->private);
struct ftrace_event_field *field;
const char *array_descriptor;
switch ((unsigned long)v) {
case FORMAT_HEADER:
seq_printf(m, "name: %s\n", call->name);
seq_printf(m, "ID: %d\n", call->event.type);
seq_printf(m, "format:\n");
return 0;
case FORMAT_FIELD_SEPERATOR:
seq_putc(m, '\n');
return 0;
case FORMAT_PRINTFMT:
seq_printf(m, "\nprint fmt: %s\n",
call->print_fmt);
return 0;
}
field = list_entry(v, struct ftrace_event_field, link);
array_descriptor = strchr(field->type, '[');
if (!strncmp(field->type, "__data_loc", 10))
array_descriptor = NULL;
if (!array_descriptor)
seq_printf(m, "\tfield:%s %s;\toffset:%u;\tsize:%u;\tsigned:%d;\n",
field->type, field->name, field->offset,
field->size, !!field->is_signed);
else
seq_printf(m, "\tfield:%.*s %s%s;\toffset:%u;\tsize:%u;\tsigned:%d;\n",
(int)(array_descriptor - field->type),
field->type, field->name,
array_descriptor, field->offset,
field->size, !!field->is_signed);
return 0;
}
static void *f_start(struct seq_file *m, loff_t *pos)
{
void *p = (void *)FORMAT_HEADER;
loff_t l = 0;
mutex_lock(&event_mutex);
if (!event_file_data(m->private))
return ERR_PTR(-ENODEV);
while (l < *pos && p)
p = f_next(m, p, &l);
return p;
}
static void f_stop(struct seq_file *m, void *p)
{
mutex_unlock(&event_mutex);
}
static int trace_format_open(struct inode *inode, struct file *file)
{
struct seq_file *m;
int ret;
ret = seq_open(file, &trace_format_seq_ops);
if (ret < 0)
return ret;
m = file->private_data;
m->private = file;
return 0;
}
static ssize_t
event_id_read(struct file *filp, char __user *ubuf, size_t cnt, loff_t *ppos)
{
int id = (long)event_file_data(filp);
char buf[32];
int len;
if (*ppos)
return 0;
if (unlikely(!id))
return -ENODEV;
len = sprintf(buf, "%d\n", id);
return simple_read_from_buffer(ubuf, cnt, ppos, buf, len);
}
static ssize_t
event_filter_read(struct file *filp, char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_event_call *call;
struct trace_seq *s;
int r = -ENODEV;
if (*ppos)
return 0;
s = kmalloc(sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
trace_seq_init(s);
mutex_lock(&event_mutex);
call = event_file_data(filp);
if (call)
print_event_filter(call, s);
mutex_unlock(&event_mutex);
if (call)
r = simple_read_from_buffer(ubuf, cnt, ppos, s->buffer, s->len);
kfree(s);
return r;
}
static ssize_t
event_filter_write(struct file *filp, const char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_event_call *call;
char *buf;
int err = -ENODEV;
if (cnt >= PAGE_SIZE)
return -EINVAL;
buf = (char *)__get_free_page(GFP_TEMPORARY);
if (!buf)
return -ENOMEM;
if (copy_from_user(buf, ubuf, cnt)) {
free_page((unsigned long) buf);
return -EFAULT;
}
buf[cnt] = '\0';
mutex_lock(&event_mutex);
call = event_file_data(filp);
if (call)
err = apply_event_filter(call, buf);
mutex_unlock(&event_mutex);
free_page((unsigned long) buf);
if (err < 0)
return err;
*ppos += cnt;
return cnt;
}
static int subsystem_open(struct inode *inode, struct file *filp)
{
struct event_subsystem *system = NULL;
struct ftrace_subsystem_dir *dir = NULL;
struct trace_array *tr;
int ret;
mutex_lock(&trace_types_lock);
mutex_lock(&event_mutex);
list_for_each_entry(tr, &ftrace_trace_arrays, list) {
list_for_each_entry(dir, &tr->systems, list) {
if (dir == inode->i_private) {
if (dir->nr_events) {
__get_system_dir(dir);
system = dir->subsystem;
}
goto exit_loop;
}
}
}
exit_loop:
mutex_unlock(&event_mutex);
mutex_unlock(&trace_types_lock);
if (!system)
return -ENODEV;
WARN_ON(!dir);
if (trace_array_get(tr) < 0) {
put_system(dir);
return -ENODEV;
}
ret = tracing_open_generic(inode, filp);
if (ret < 0) {
trace_array_put(tr);
put_system(dir);
}
return ret;
}
static int system_tr_open(struct inode *inode, struct file *filp)
{
struct ftrace_subsystem_dir *dir;
struct trace_array *tr = inode->i_private;
int ret;
if (trace_array_get(tr) < 0)
return -ENODEV;
dir = kzalloc(sizeof(*dir), GFP_KERNEL);
if (!dir) {
trace_array_put(tr);
return -ENOMEM;
}
dir->tr = tr;
ret = tracing_open_generic(inode, filp);
if (ret < 0) {
trace_array_put(tr);
kfree(dir);
}
filp->private_data = dir;
return ret;
}
static int subsystem_release(struct inode *inode, struct file *file)
{
struct ftrace_subsystem_dir *dir = file->private_data;
trace_array_put(dir->tr);
if (dir->subsystem)
put_system(dir);
else
kfree(dir);
return 0;
}
static ssize_t
subsystem_filter_read(struct file *filp, char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_subsystem_dir *dir = filp->private_data;
struct event_subsystem *system = dir->subsystem;
struct trace_seq *s;
int r;
if (*ppos)
return 0;
s = kmalloc(sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
trace_seq_init(s);
print_subsystem_event_filter(system, s);
r = simple_read_from_buffer(ubuf, cnt, ppos, s->buffer, s->len);
kfree(s);
return r;
}
static ssize_t
subsystem_filter_write(struct file *filp, const char __user *ubuf, size_t cnt,
loff_t *ppos)
{
struct ftrace_subsystem_dir *dir = filp->private_data;
char *buf;
int err;
if (cnt >= PAGE_SIZE)
return -EINVAL;
buf = (char *)__get_free_page(GFP_TEMPORARY);
if (!buf)
return -ENOMEM;
if (copy_from_user(buf, ubuf, cnt)) {
free_page((unsigned long) buf);
return -EFAULT;
}
buf[cnt] = '\0';
err = apply_subsystem_event_filter(dir, buf);
free_page((unsigned long) buf);
if (err < 0)
return err;
*ppos += cnt;
return cnt;
}
static ssize_t
show_header(struct file *filp, char __user *ubuf, size_t cnt, loff_t *ppos)
{
int (*func)(struct trace_seq *s) = filp->private_data;
struct trace_seq *s;
int r;
if (*ppos)
return 0;
s = kmalloc(sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
trace_seq_init(s);
func(s);
r = simple_read_from_buffer(ubuf, cnt, ppos, s->buffer, s->len);
kfree(s);
return r;
}
static int
ftrace_event_open(struct inode *inode, struct file *file,
const struct seq_operations *seq_ops)
{
struct seq_file *m;
int ret;
ret = seq_open(file, seq_ops);
if (ret < 0)
return ret;
m = file->private_data;
m->private = inode->i_private;
return ret;
}
static int ftrace_event_release(struct inode *inode, struct file *file)
{
struct trace_array *tr = inode->i_private;
trace_array_put(tr);
return seq_release(inode, file);
}
static int
ftrace_event_avail_open(struct inode *inode, struct file *file)
{
const struct seq_operations *seq_ops = &show_event_seq_ops;
return ftrace_event_open(inode, file, seq_ops);
}
static int
ftrace_event_set_open(struct inode *inode, struct file *file)
{
const struct seq_operations *seq_ops = &show_set_event_seq_ops;
struct trace_array *tr = inode->i_private;
int ret;
if (trace_array_get(tr) < 0)
return -ENODEV;
if ((file->f_mode & FMODE_WRITE) &&
(file->f_flags & O_TRUNC))
ftrace_clear_events(tr);
ret = ftrace_event_open(inode, file, seq_ops);
if (ret < 0)
trace_array_put(tr);
return ret;
}
static struct event_subsystem *
create_new_subsystem(const char *name)
{
struct event_subsystem *system;
system = kmalloc(sizeof(*system), GFP_KERNEL);
if (!system)
return NULL;
system->ref_count = 1;
if (!core_kernel_data((unsigned long)name)) {
system->ref_count |= SYSTEM_FL_FREE_NAME;
system->name = kstrdup(name, GFP_KERNEL);
if (!system->name)
goto out_free;
} else
system->name = name;
system->filter = NULL;
system->filter = kzalloc(sizeof(struct event_filter), GFP_KERNEL);
if (!system->filter)
goto out_free;
list_add(&system->list, &event_subsystems);
return system;
out_free:
if (system->ref_count & SYSTEM_FL_FREE_NAME)
kfree(system->name);
kfree(system);
return NULL;
}
static struct dentry *
event_subsystem_dir(struct trace_array *tr, const char *name,
struct ftrace_event_file *file, struct dentry *parent)
{
struct ftrace_subsystem_dir *dir;
struct event_subsystem *system;
struct dentry *entry;
list_for_each_entry(dir, &tr->systems, list) {
system = dir->subsystem;
if (strcmp(system->name, name) == 0) {
dir->nr_events++;
file->system = dir;
return dir->entry;
}
}
list_for_each_entry(system, &event_subsystems, list) {
if (strcmp(system->name, name) == 0)
break;
}
if (&system->list == &event_subsystems)
system = NULL;
dir = kmalloc(sizeof(*dir), GFP_KERNEL);
if (!dir)
goto out_fail;
if (!system) {
system = create_new_subsystem(name);
if (!system)
goto out_free;
} else
__get_system(system);
dir->entry = debugfs_create_dir(name, parent);
if (!dir->entry) {
pr_warning("Failed to create system directory %s\n", name);
__put_system(system);
goto out_free;
}
dir->tr = tr;
dir->ref_count = 1;
dir->nr_events = 1;
dir->subsystem = system;
file->system = dir;
entry = debugfs_create_file("filter", 0644, dir->entry, dir,
&ftrace_subsystem_filter_fops);
if (!entry) {
kfree(system->filter);
system->filter = NULL;
pr_warning("Could not create debugfs '%s/filter' entry\n", name);
}
trace_create_file("enable", 0644, dir->entry, dir,
&ftrace_system_enable_fops);
list_add(&dir->list, &tr->systems);
return dir->entry;
out_free:
kfree(dir);
out_fail:
if (!dir || !system)
pr_warning("No memory to create event subsystem %s\n",
name);
return NULL;
}
static int
event_create_dir(struct dentry *parent,
struct ftrace_event_file *file,
const struct file_operations *id,
const struct file_operations *enable,
const struct file_operations *filter,
const struct file_operations *format)
{
struct ftrace_event_call *call = file->event_call;
struct trace_array *tr = file->tr;
struct list_head *head;
struct dentry *d_events;
int ret;
if (strcmp(call->class->system, TRACE_SYSTEM) != 0) {
d_events = event_subsystem_dir(tr, call->class->system, file, parent);
if (!d_events)
return -ENOMEM;
} else
d_events = parent;
file->dir = debugfs_create_dir(call->name, d_events);
if (!file->dir) {
pr_warning("Could not create debugfs '%s' directory\n",
call->name);
return -1;
}
if (call->class->reg && !(call->flags & TRACE_EVENT_FL_IGNORE_ENABLE))
trace_create_file("enable", 0644, file->dir, file,
enable);
#ifdef CONFIG_PERF_EVENTS
if (call->event.type && call->class->reg)
trace_create_file("id", 0444, file->dir,
(void *)(long)call->event.type, id);
#endif
head = trace_get_fields(call);
if (list_empty(head)) {
ret = call->class->define_fields(call);
if (ret < 0) {
pr_warning("Could not initialize trace point"
" events/%s\n", call->name);
return -1;
}
}
trace_create_file("filter", 0644, file->dir, call,
filter);
trace_create_file("format", 0444, file->dir, call,
format);
return 0;
}
static void remove_event_from_tracers(struct ftrace_event_call *call)
{
struct ftrace_event_file *file;
struct trace_array *tr;
do_for_each_event_file_safe(tr, file) {
if (file->event_call != call)
continue;
remove_event_file_dir(file);
break;
} while_for_each_event_file();
}
static void event_remove(struct ftrace_event_call *call)
{
struct trace_array *tr;
struct ftrace_event_file *file;
do_for_each_event_file(tr, file) {
if (file->event_call != call)
continue;
ftrace_event_enable_disable(file, 0);
break;
} while_for_each_event_file();
if (call->event.funcs)
__unregister_ftrace_event(&call->event);
remove_event_from_tracers(call);
list_del(&call->list);
}
static int event_init(struct ftrace_event_call *call)
{
int ret = 0;
if (WARN_ON(!call->name))
return -EINVAL;
if (call->class->raw_init) {
ret = call->class->raw_init(call);
if (ret < 0 && ret != -ENOSYS)
pr_warn("Could not initialize trace events/%s\n",
call->name);
}
return ret;
}
static int
__register_event(struct ftrace_event_call *call, struct module *mod)
{
int ret;
ret = event_init(call);
if (ret < 0)
return ret;
list_add(&call->list, &ftrace_events);
call->mod = mod;
return 0;
}
static struct ftrace_event_file *
trace_create_new_event(struct ftrace_event_call *call,
struct trace_array *tr)
{
struct ftrace_event_file *file;
file = kmem_cache_alloc(file_cachep, GFP_TRACE);
if (!file)
return NULL;
file->event_call = call;
file->tr = tr;
atomic_set(&file->sm_ref, 0);
list_add(&file->list, &tr->events);
return file;
}
static int
__trace_add_new_event(struct ftrace_event_call *call,
struct trace_array *tr,
const struct file_operations *id,
const struct file_operations *enable,
const struct file_operations *filter,
const struct file_operations *format)
{
struct ftrace_event_file *file;
file = trace_create_new_event(call, tr);
if (!file)
return -ENOMEM;
return event_create_dir(tr->event_dir, file, id, enable, filter, format);
}
static __init int
__trace_early_add_new_event(struct ftrace_event_call *call,
struct trace_array *tr)
{
struct ftrace_event_file *file;
file = trace_create_new_event(call, tr);
if (!file)
return -ENOMEM;
return 0;
}
int trace_add_event_call(struct ftrace_event_call *call)
{
int ret;
mutex_lock(&trace_types_lock);
mutex_lock(&event_mutex);
ret = __register_event(call, NULL);
if (ret >= 0)
__add_event_to_tracers(call, NULL);
mutex_unlock(&event_mutex);
mutex_unlock(&trace_types_lock);
return ret;
}
static void __trace_remove_event_call(struct ftrace_event_call *call)
{
event_remove(call);
trace_destroy_fields(call);
destroy_preds(call);
}
static int probe_remove_event_call(struct ftrace_event_call *call)
{
struct trace_array *tr;
struct ftrace_event_file *file;
#ifdef CONFIG_PERF_EVENTS
if (call->perf_refcount)
return -EBUSY;
#endif
do_for_each_event_file(tr, file) {
if (file->event_call != call)
continue;
if (file->flags & FTRACE_EVENT_FL_ENABLED)
return -EBUSY;
break;
} while_for_each_event_file();
__trace_remove_event_call(call);
return 0;
}
int trace_remove_event_call(struct ftrace_event_call *call)
{
int ret;
mutex_lock(&trace_types_lock);
mutex_lock(&event_mutex);
down_write(&trace_event_sem);
ret = probe_remove_event_call(call);
up_write(&trace_event_sem);
mutex_unlock(&event_mutex);
mutex_unlock(&trace_types_lock);
return ret;
}
static struct ftrace_module_file_ops *
find_ftrace_file_ops(struct ftrace_module_file_ops *file_ops, struct module *mod)
{
if (file_ops && mod == file_ops->mod)
return file_ops;
list_for_each_entry(file_ops, &ftrace_module_file_list, list) {
if (file_ops->mod == mod)
return file_ops;
}
return NULL;
}
static struct ftrace_module_file_ops *
trace_create_file_ops(struct module *mod)
{
struct ftrace_module_file_ops *file_ops;
file_ops = kmalloc(sizeof(*file_ops), GFP_KERNEL);
if (!file_ops)
return NULL;
file_ops->mod = mod;
file_ops->id = ftrace_event_id_fops;
file_ops->id.owner = mod;
file_ops->enable = ftrace_enable_fops;
file_ops->enable.owner = mod;
file_ops->filter = ftrace_event_filter_fops;
file_ops->filter.owner = mod;
file_ops->format = ftrace_event_format_fops;
file_ops->format.owner = mod;
list_add(&file_ops->list, &ftrace_module_file_list);
return file_ops;
}
static void trace_module_add_events(struct module *mod)
{
struct ftrace_module_file_ops *file_ops = NULL;
struct ftrace_event_call **call, **start, **end;
start = mod->trace_events;
end = mod->trace_events + mod->num_trace_events;
if (start == end)
return;
file_ops = trace_create_file_ops(mod);
if (!file_ops)
return;
for_each_event(call, start, end) {
__register_event(*call, mod);
__add_event_to_tracers(*call, file_ops);
}
}
static void trace_module_remove_events(struct module *mod)
{
struct ftrace_module_file_ops *file_ops;
struct ftrace_event_call *call, *p;
bool clear_trace = false;
down_write(&trace_event_sem);
list_for_each_entry_safe(call, p, &ftrace_events, list) {
if (call->mod == mod) {
if (call->flags & TRACE_EVENT_FL_WAS_ENABLED)
clear_trace = true;
__trace_remove_event_call(call);
}
}
list_for_each_entry(file_ops, &ftrace_module_file_list, list) {
if (file_ops->mod == mod)
break;
}
if (&file_ops->list != &ftrace_module_file_list) {
list_del(&file_ops->list);
kfree(file_ops);
}
up_write(&trace_event_sem);
if (clear_trace)
tracing_reset_all_online_cpus();
}
static int trace_module_notify(struct notifier_block *self,
unsigned long val, void *data)
{
struct module *mod = data;
mutex_lock(&trace_types_lock);
mutex_lock(&event_mutex);
switch (val) {
case MODULE_STATE_COMING:
trace_module_add_events(mod);
break;
case MODULE_STATE_GOING:
trace_module_remove_events(mod);
break;
}
mutex_unlock(&event_mutex);
mutex_unlock(&trace_types_lock);
return 0;
}
static int
__trace_add_new_mod_event(struct ftrace_event_call *call,
struct trace_array *tr,
struct ftrace_module_file_ops *file_ops)
{
return __trace_add_new_event(call, tr,
&file_ops->id, &file_ops->enable,
&file_ops->filter, &file_ops->format);
}
static inline struct ftrace_module_file_ops *
find_ftrace_file_ops(struct ftrace_module_file_ops *file_ops, struct module *mod)
{
return NULL;
}
static inline int trace_module_notify(struct notifier_block *self,
unsigned long val, void *data)
{
return 0;
}
static inline int
__trace_add_new_mod_event(struct ftrace_event_call *call,
struct trace_array *tr,
struct ftrace_module_file_ops *file_ops)
{
return -ENODEV;
}
static void
__trace_add_event_dirs(struct trace_array *tr)
{
struct ftrace_module_file_ops *file_ops = NULL;
struct ftrace_event_call *call;
int ret;
list_for_each_entry(call, &ftrace_events, list) {
if (call->mod) {
file_ops = find_ftrace_file_ops(file_ops, call->mod);
if (!file_ops)
continue;
ret = __trace_add_new_mod_event(call, tr, file_ops);
if (ret < 0)
pr_warning("Could not create directory for event %s\n",
call->name);
continue;
}
ret = __trace_add_new_event(call, tr,
&ftrace_event_id_fops,
&ftrace_enable_fops,
&ftrace_event_filter_fops,
&ftrace_event_format_fops);
if (ret < 0)
pr_warning("Could not create directory for event %s\n",
call->name);
}
}
static struct ftrace_event_file *
find_event_file(struct trace_array *tr, const char *system, const char *event)
{
struct ftrace_event_file *file;
struct ftrace_event_call *call;
list_for_each_entry(file, &tr->events, list) {
call = file->event_call;
if (!call->name || !call->class || !call->class->reg)
continue;
if (call->flags & TRACE_EVENT_FL_IGNORE_ENABLE)
continue;
if (strcmp(event, call->name) == 0 &&
strcmp(system, call->class->system) == 0)
return file;
}
return NULL;
}
static void
event_enable_probe(unsigned long ip, unsigned long parent_ip, void **_data)
{
struct event_probe_data **pdata = (struct event_probe_data **)_data;
struct event_probe_data *data = *pdata;
if (!data)
return;
if (data->enable)
clear_bit(FTRACE_EVENT_FL_SOFT_DISABLED_BIT, &data->file->flags);
else
set_bit(FTRACE_EVENT_FL_SOFT_DISABLED_BIT, &data->file->flags);
}
static void
event_enable_count_probe(unsigned long ip, unsigned long parent_ip, void **_data)
{
struct event_probe_data **pdata = (struct event_probe_data **)_data;
struct event_probe_data *data = *pdata;
if (!data)
return;
if (!data->count)
return;
if (data->enable == !(data->file->flags & FTRACE_EVENT_FL_SOFT_DISABLED))
return;
if (data->count != -1)
(data->count)--;
event_enable_probe(ip, parent_ip, _data);
}
static int
event_enable_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *_data)
{
struct event_probe_data *data = _data;
seq_printf(m, "%ps:", (void *)ip);
seq_printf(m, "%s:%s:%s",
data->enable ? ENABLE_EVENT_STR : DISABLE_EVENT_STR,
data->file->event_call->class->system,
data->file->event_call->name);
if (data->count == -1)
seq_printf(m, ":unlimited\n");
else
seq_printf(m, ":count=%ld\n", data->count);
return 0;
}
static int
event_enable_init(struct ftrace_probe_ops *ops, unsigned long ip,
void **_data)
{
struct event_probe_data **pdata = (struct event_probe_data **)_data;
struct event_probe_data *data = *pdata;
data->ref++;
return 0;
}
static void
event_enable_free(struct ftrace_probe_ops *ops, unsigned long ip,
void **_data)
{
struct event_probe_data **pdata = (struct event_probe_data **)_data;
struct event_probe_data *data = *pdata;
if (WARN_ON_ONCE(data->ref <= 0))
return;
data->ref--;
if (!data->ref) {
__ftrace_event_enable_disable(data->file, 0, 1);
module_put(data->file->event_call->mod);
kfree(data);
}
*pdata = NULL;
}
static int
event_enable_func(struct ftrace_hash *hash,
char *glob, char *cmd, char *param, int enabled)
{
struct trace_array *tr = top_trace_array();
struct ftrace_event_file *file;
struct ftrace_probe_ops *ops;
struct event_probe_data *data;
const char *system;
const char *event;
char *number;
bool enable;
int ret;
if (!enabled || !param)
return -EINVAL;
system = strsep(&param, ":");
if (!param)
return -EINVAL;
event = strsep(&param, ":");
mutex_lock(&event_mutex);
ret = -EINVAL;
file = find_event_file(tr, system, event);
if (!file)
goto out;
enable = strcmp(cmd, ENABLE_EVENT_STR) == 0;
if (enable)
ops = param ? &event_enable_count_probe_ops : &event_enable_probe_ops;
else
ops = param ? &event_disable_count_probe_ops : &event_disable_probe_ops;
if (glob[0] == '!') {
unregister_ftrace_function_probe_func(glob+1, ops);
ret = 0;
goto out;
}
ret = -ENOMEM;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
goto out;
data->enable = enable;
data->count = -1;
data->file = file;
if (!param)
goto out_reg;
number = strsep(&param, ":");
ret = -EINVAL;
if (!strlen(number))
goto out_free;
ret = kstrtoul(number, 0, &data->count);
if (ret)
goto out_free;
out_reg:
ret = try_module_get(file->event_call->mod);
if (!ret) {
ret = -EBUSY;
goto out_free;
}
ret = __ftrace_event_enable_disable(file, 1, 1);
if (ret < 0)
goto out_put;
ret = register_ftrace_function_probe(glob, ops, data);
if (!ret) {
ret = -ENOENT;
goto out_disable;
} else if (ret < 0)
goto out_disable;
ret = 0;
out:
mutex_unlock(&event_mutex);
return ret;
out_disable:
__ftrace_event_enable_disable(file, 0, 1);
out_put:
module_put(file->event_call->mod);
out_free:
kfree(data);
goto out;
}
static __init int register_event_cmds(void)
{
int ret;
ret = register_ftrace_command(&event_enable_cmd);
if (WARN_ON(ret < 0))
return ret;
ret = register_ftrace_command(&event_disable_cmd);
if (WARN_ON(ret < 0))
unregister_ftrace_command(&event_enable_cmd);
return ret;
}
static inline int register_event_cmds(void) { return 0; }
static __init void
__trace_early_add_event_dirs(struct trace_array *tr)
{
struct ftrace_event_file *file;
int ret;
list_for_each_entry(file, &tr->events, list) {
ret = event_create_dir(tr->event_dir, file,
&ftrace_event_id_fops,
&ftrace_enable_fops,
&ftrace_event_filter_fops,
&ftrace_event_format_fops);
if (ret < 0)
pr_warning("Could not create directory for event %s\n",
file->event_call->name);
}
}
static __init void
__trace_early_add_events(struct trace_array *tr)
{
struct ftrace_event_call *call;
int ret;
list_for_each_entry(call, &ftrace_events, list) {
if (WARN_ON_ONCE(call->mod))
continue;
ret = __trace_early_add_new_event(call, tr);
if (ret < 0)
pr_warning("Could not create early event %s\n",
call->name);
}
}
static void
__trace_remove_event_dirs(struct trace_array *tr)
{
struct ftrace_event_file *file, *next;
list_for_each_entry_safe(file, next, &tr->events, list)
remove_event_file_dir(file);
}
static void
__add_event_to_tracers(struct ftrace_event_call *call,
struct ftrace_module_file_ops *file_ops)
{
struct trace_array *tr;
list_for_each_entry(tr, &ftrace_trace_arrays, list) {
if (file_ops)
__trace_add_new_mod_event(call, tr, file_ops);
else
__trace_add_new_event(call, tr,
&ftrace_event_id_fops,
&ftrace_enable_fops,
&ftrace_event_filter_fops,
&ftrace_event_format_fops);
}
}
static __init int setup_trace_event(char *str)
{
strlcpy(bootup_event_buf, str, COMMAND_LINE_SIZE);
ring_buffer_expanded = true;
tracing_selftest_disabled = true;
return 1;
}
static int
create_event_toplevel_files(struct dentry *parent, struct trace_array *tr)
{
struct dentry *d_events;
struct dentry *entry;
entry = debugfs_create_file("set_event", 0644, parent,
tr, &ftrace_set_event_fops);
if (!entry) {
pr_warning("Could not create debugfs 'set_event' entry\n");
return -ENOMEM;
}
d_events = debugfs_create_dir("events", parent);
if (!d_events) {
pr_warning("Could not create debugfs 'events' directory\n");
return -ENOMEM;
}
trace_create_file("header_page", 0444, d_events,
ring_buffer_print_page_header,
&ftrace_show_header_fops);
trace_create_file("header_event", 0444, d_events,
ring_buffer_print_entry_header,
&ftrace_show_header_fops);
trace_create_file("enable", 0644, d_events,
tr, &ftrace_tr_enable_fops);
tr->event_dir = d_events;
return 0;
}
int event_trace_add_tracer(struct dentry *parent, struct trace_array *tr)
{
int ret;
mutex_lock(&event_mutex);
ret = create_event_toplevel_files(parent, tr);
if (ret)
goto out_unlock;
down_write(&trace_event_sem);
__trace_add_event_dirs(tr);
up_write(&trace_event_sem);
out_unlock:
mutex_unlock(&event_mutex);
return ret;
}
static __init int
early_event_add_tracer(struct dentry *parent, struct trace_array *tr)
{
int ret;
mutex_lock(&event_mutex);
ret = create_event_toplevel_files(parent, tr);
if (ret)
goto out_unlock;
down_write(&trace_event_sem);
__trace_early_add_event_dirs(tr);
up_write(&trace_event_sem);
out_unlock:
mutex_unlock(&event_mutex);
return ret;
}
int event_trace_del_tracer(struct trace_array *tr)
{
mutex_lock(&event_mutex);
__ftrace_set_clr_event_nolock(tr, NULL, NULL, NULL, 0);
down_write(&trace_event_sem);
__trace_remove_event_dirs(tr);
debugfs_remove_recursive(tr->event_dir);
up_write(&trace_event_sem);
tr->event_dir = NULL;
mutex_unlock(&event_mutex);
return 0;
}
static __init int event_trace_memsetup(void)
{
field_cachep = KMEM_CACHE(ftrace_event_field, SLAB_PANIC);
file_cachep = KMEM_CACHE(ftrace_event_file, SLAB_PANIC);
return 0;
}
static __init int event_trace_enable(void)
{
struct trace_array *tr = top_trace_array();
struct ftrace_event_call **iter, *call;
char *buf = bootup_event_buf;
char *token;
int ret;
for_each_event(iter, __start_ftrace_events, __stop_ftrace_events) {
call = *iter;
ret = event_init(call);
if (!ret)
list_add(&call->list, &ftrace_events);
}
__trace_early_add_events(tr);
while (true) {
token = strsep(&buf, ",");
if (!token)
break;
if (!*token)
continue;
ret = ftrace_set_clr_event(tr, token, 1);
if (ret)
pr_warn("Failed to enable trace event: %s\n", token);
}
trace_printk_start_comm();
register_event_cmds();
return 0;
}
static __init int event_trace_init(void)
{
struct trace_array *tr;
struct dentry *d_tracer;
struct dentry *entry;
int ret;
tr = top_trace_array();
d_tracer = tracing_init_dentry();
if (!d_tracer)
return 0;
entry = debugfs_create_file("available_events", 0444, d_tracer,
tr, &ftrace_avail_fops);
if (!entry)
pr_warning("Could not create debugfs "
"'available_events' entry\n");
if (trace_define_common_fields())
pr_warning("tracing: Failed to allocate common fields");
ret = early_event_add_tracer(d_tracer, tr);
if (ret)
return ret;
ret = register_module_notifier(&trace_module_nb);
if (ret)
pr_warning("Failed to register trace events module notifier\n");
return 0;
}
static __init void test_work(struct work_struct *dummy)
{
spin_lock(&test_spinlock);
spin_lock_irq(&test_spinlock_irq);
udelay(1);
spin_unlock_irq(&test_spinlock_irq);
spin_unlock(&test_spinlock);
mutex_lock(&test_mutex);
msleep(1);
mutex_unlock(&test_mutex);
}
static __init int event_test_thread(void *unused)
{
void *test_malloc;
test_malloc = kmalloc(1234, GFP_KERNEL);
if (!test_malloc)
pr_info("failed to kmalloc\n");
schedule_on_each_cpu(test_work);
kfree(test_malloc);
set_current_state(TASK_INTERRUPTIBLE);
while (!kthread_should_stop())
schedule();
return 0;
}
static __init void event_test_stuff(void)
{
struct task_struct *test_thread;
test_thread = kthread_run(event_test_thread, NULL, "test-events");
msleep(1);
kthread_stop(test_thread);
}
static __init void event_trace_self_tests(void)
{
struct ftrace_subsystem_dir *dir;
struct ftrace_event_file *file;
struct ftrace_event_call *call;
struct event_subsystem *system;
struct trace_array *tr;
int ret;
tr = top_trace_array();
pr_info("Running tests on trace events:\n");
list_for_each_entry(file, &tr->events, list) {
call = file->event_call;
if (!call->class || !call->class->probe)
continue;
#ifndef CONFIG_EVENT_TRACE_TEST_SYSCALLS
if (call->class->system &&
strcmp(call->class->system, "syscalls") == 0)
continue;
#endif
pr_info("Testing event %s: ", call->name);
if (file->flags & FTRACE_EVENT_FL_ENABLED) {
pr_warning("Enabled event during self test!\n");
WARN_ON_ONCE(1);
continue;
}
ftrace_event_enable_disable(file, 1);
event_test_stuff();
ftrace_event_enable_disable(file, 0);
pr_cont("OK\n");
}
pr_info("Running tests on trace event systems:\n");
list_for_each_entry(dir, &tr->systems, list) {
system = dir->subsystem;
if (strcmp(system->name, "ftrace") == 0)
continue;
pr_info("Testing event system %s: ", system->name);
ret = __ftrace_set_clr_event(tr, NULL, system->name, NULL, 1);
if (WARN_ON_ONCE(ret)) {
pr_warning("error enabling system %s\n",
system->name);
continue;
}
event_test_stuff();
ret = __ftrace_set_clr_event(tr, NULL, system->name, NULL, 0);
if (WARN_ON_ONCE(ret)) {
pr_warning("error disabling system %s\n",
system->name);
continue;
}
pr_cont("OK\n");
}
pr_info("Running tests on all trace events:\n");
pr_info("Testing all events: ");
ret = __ftrace_set_clr_event(tr, NULL, NULL, NULL, 1);
if (WARN_ON_ONCE(ret)) {
pr_warning("error enabling all events\n");
return;
}
event_test_stuff();
ret = __ftrace_set_clr_event(tr, NULL, NULL, NULL, 0);
if (WARN_ON_ONCE(ret)) {
pr_warning("error disabling all events\n");
return;
}
pr_cont("OK\n");
}
static void
function_test_events_call(unsigned long ip, unsigned long parent_ip,
struct ftrace_ops *op, struct pt_regs *pt_regs)
{
struct ring_buffer_event *event;
struct ring_buffer *buffer;
struct ftrace_entry *entry;
unsigned long flags;
long disabled;
int cpu;
int pc;
pc = preempt_count();
preempt_disable_notrace();
cpu = raw_smp_processor_id();
disabled = atomic_inc_return(&per_cpu(ftrace_test_event_disable, cpu));
if (disabled != 1)
goto out;
local_save_flags(flags);
event = trace_current_buffer_lock_reserve(&buffer,
TRACE_FN, sizeof(*entry),
flags, pc);
if (!event)
goto out;
entry = ring_buffer_event_data(event);
entry->ip = ip;
entry->parent_ip = parent_ip;
trace_buffer_unlock_commit(buffer, event, flags, pc);
out:
atomic_dec(&per_cpu(ftrace_test_event_disable, cpu));
preempt_enable_notrace();
}
static __init void event_trace_self_test_with_function(void)
{
int ret;
ret = register_ftrace_function(&trace_ops);
if (WARN_ON(ret < 0)) {
pr_info("Failed to enable function tracer for event tests\n");
return;
}
pr_info("Running tests again, along with the function tracer\n");
event_trace_self_tests();
unregister_ftrace_function(&trace_ops);
}
static __init void event_trace_self_test_with_function(void)
{
}
static __init int event_trace_self_tests_init(void)
{
if (!tracing_selftest_disabled) {
event_trace_self_tests();
event_trace_self_test_with_function();
}
return 0;
}
