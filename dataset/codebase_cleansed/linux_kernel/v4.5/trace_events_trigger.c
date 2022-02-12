static void
trigger_data_free(struct event_trigger_data *data)
{
if (data->cmd_ops->set_filter)
data->cmd_ops->set_filter(NULL, data, NULL);
synchronize_sched();
kfree(data);
}
enum event_trigger_type
event_triggers_call(struct trace_event_file *file, void *rec)
{
struct event_trigger_data *data;
enum event_trigger_type tt = ETT_NONE;
struct event_filter *filter;
if (list_empty(&file->triggers))
return tt;
list_for_each_entry_rcu(data, &file->triggers, list) {
if (!rec) {
data->ops->func(data);
continue;
}
filter = rcu_dereference_sched(data->filter);
if (filter && !filter_match_preds(filter, rec))
continue;
if (data->cmd_ops->post_trigger) {
tt |= data->cmd_ops->trigger_type;
continue;
}
data->ops->func(data);
}
return tt;
}
void
event_triggers_post_call(struct trace_event_file *file,
enum event_trigger_type tt)
{
struct event_trigger_data *data;
list_for_each_entry_rcu(data, &file->triggers, list) {
if (data->cmd_ops->trigger_type & tt)
data->ops->func(data);
}
}
static void *trigger_next(struct seq_file *m, void *t, loff_t *pos)
{
struct trace_event_file *event_file = event_file_data(m->private);
if (t == SHOW_AVAILABLE_TRIGGERS)
return NULL;
return seq_list_next(t, &event_file->triggers, pos);
}
static void *trigger_start(struct seq_file *m, loff_t *pos)
{
struct trace_event_file *event_file;
mutex_lock(&event_mutex);
event_file = event_file_data(m->private);
if (unlikely(!event_file))
return ERR_PTR(-ENODEV);
if (list_empty(&event_file->triggers))
return *pos == 0 ? SHOW_AVAILABLE_TRIGGERS : NULL;
return seq_list_start(&event_file->triggers, *pos);
}
static void trigger_stop(struct seq_file *m, void *t)
{
mutex_unlock(&event_mutex);
}
static int trigger_show(struct seq_file *m, void *v)
{
struct event_trigger_data *data;
struct event_command *p;
if (v == SHOW_AVAILABLE_TRIGGERS) {
seq_puts(m, "# Available triggers:\n");
seq_putc(m, '#');
mutex_lock(&trigger_cmd_mutex);
list_for_each_entry_reverse(p, &trigger_commands, list)
seq_printf(m, " %s", p->name);
seq_putc(m, '\n');
mutex_unlock(&trigger_cmd_mutex);
return 0;
}
data = list_entry(v, struct event_trigger_data, list);
data->ops->print(m, data->ops, data);
return 0;
}
static int event_trigger_regex_open(struct inode *inode, struct file *file)
{
int ret = 0;
mutex_lock(&event_mutex);
if (unlikely(!event_file_data(file))) {
mutex_unlock(&event_mutex);
return -ENODEV;
}
if (file->f_mode & FMODE_READ) {
ret = seq_open(file, &event_triggers_seq_ops);
if (!ret) {
struct seq_file *m = file->private_data;
m->private = file;
}
}
mutex_unlock(&event_mutex);
return ret;
}
static int trigger_process_regex(struct trace_event_file *file, char *buff)
{
char *command, *next = buff;
struct event_command *p;
int ret = -EINVAL;
command = strsep(&next, ": \t");
command = (command[0] != '!') ? command : command + 1;
mutex_lock(&trigger_cmd_mutex);
list_for_each_entry(p, &trigger_commands, list) {
if (strcmp(p->name, command) == 0) {
ret = p->func(p, file, buff, command, next);
goto out_unlock;
}
}
out_unlock:
mutex_unlock(&trigger_cmd_mutex);
return ret;
}
static ssize_t event_trigger_regex_write(struct file *file,
const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
struct trace_event_file *event_file;
ssize_t ret;
char *buf;
if (!cnt)
return 0;
if (cnt >= PAGE_SIZE)
return -EINVAL;
buf = memdup_user_nul(ubuf, cnt);
if (IS_ERR(buf))
return PTR_ERR(buf);
strim(buf);
mutex_lock(&event_mutex);
event_file = event_file_data(file);
if (unlikely(!event_file)) {
mutex_unlock(&event_mutex);
kfree(buf);
return -ENODEV;
}
ret = trigger_process_regex(event_file, buf);
mutex_unlock(&event_mutex);
kfree(buf);
if (ret < 0)
goto out;
*ppos += cnt;
ret = cnt;
out:
return ret;
}
static int event_trigger_regex_release(struct inode *inode, struct file *file)
{
mutex_lock(&event_mutex);
if (file->f_mode & FMODE_READ)
seq_release(inode, file);
mutex_unlock(&event_mutex);
return 0;
}
static ssize_t
event_trigger_write(struct file *filp, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
return event_trigger_regex_write(filp, ubuf, cnt, ppos);
}
static int
event_trigger_open(struct inode *inode, struct file *filp)
{
return event_trigger_regex_open(inode, filp);
}
static int
event_trigger_release(struct inode *inode, struct file *file)
{
return event_trigger_regex_release(inode, file);
}
static __init int register_event_command(struct event_command *cmd)
{
struct event_command *p;
int ret = 0;
mutex_lock(&trigger_cmd_mutex);
list_for_each_entry(p, &trigger_commands, list) {
if (strcmp(cmd->name, p->name) == 0) {
ret = -EBUSY;
goto out_unlock;
}
}
list_add(&cmd->list, &trigger_commands);
out_unlock:
mutex_unlock(&trigger_cmd_mutex);
return ret;
}
static __init int unregister_event_command(struct event_command *cmd)
{
struct event_command *p, *n;
int ret = -ENODEV;
mutex_lock(&trigger_cmd_mutex);
list_for_each_entry_safe(p, n, &trigger_commands, list) {
if (strcmp(cmd->name, p->name) == 0) {
ret = 0;
list_del_init(&p->list);
goto out_unlock;
}
}
out_unlock:
mutex_unlock(&trigger_cmd_mutex);
return ret;
}
static int
event_trigger_print(const char *name, struct seq_file *m,
void *data, char *filter_str)
{
long count = (long)data;
seq_puts(m, name);
if (count == -1)
seq_puts(m, ":unlimited");
else
seq_printf(m, ":count=%ld", count);
if (filter_str)
seq_printf(m, " if %s\n", filter_str);
else
seq_putc(m, '\n');
return 0;
}
static int
event_trigger_init(struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
data->ref++;
return 0;
}
static void
event_trigger_free(struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
if (WARN_ON_ONCE(data->ref <= 0))
return;
data->ref--;
if (!data->ref)
trigger_data_free(data);
}
static int trace_event_trigger_enable_disable(struct trace_event_file *file,
int trigger_enable)
{
int ret = 0;
if (trigger_enable) {
if (atomic_inc_return(&file->tm_ref) > 1)
return ret;
set_bit(EVENT_FILE_FL_TRIGGER_MODE_BIT, &file->flags);
ret = trace_event_enable_disable(file, 1, 1);
} else {
if (atomic_dec_return(&file->tm_ref) > 0)
return ret;
clear_bit(EVENT_FILE_FL_TRIGGER_MODE_BIT, &file->flags);
ret = trace_event_enable_disable(file, 0, 1);
}
return ret;
}
void
clear_event_triggers(struct trace_array *tr)
{
struct trace_event_file *file;
list_for_each_entry(file, &tr->events, list) {
struct event_trigger_data *data;
list_for_each_entry_rcu(data, &file->triggers, list) {
trace_event_trigger_enable_disable(file, 0);
if (data->ops->free)
data->ops->free(data->ops, data);
}
}
}
static void update_cond_flag(struct trace_event_file *file)
{
struct event_trigger_data *data;
bool set_cond = false;
list_for_each_entry_rcu(data, &file->triggers, list) {
if (data->filter || data->cmd_ops->post_trigger) {
set_cond = true;
break;
}
}
if (set_cond)
set_bit(EVENT_FILE_FL_TRIGGER_COND_BIT, &file->flags);
else
clear_bit(EVENT_FILE_FL_TRIGGER_COND_BIT, &file->flags);
}
static int register_trigger(char *glob, struct event_trigger_ops *ops,
struct event_trigger_data *data,
struct trace_event_file *file)
{
struct event_trigger_data *test;
int ret = 0;
list_for_each_entry_rcu(test, &file->triggers, list) {
if (test->cmd_ops->trigger_type == data->cmd_ops->trigger_type) {
ret = -EEXIST;
goto out;
}
}
if (data->ops->init) {
ret = data->ops->init(data->ops, data);
if (ret < 0)
goto out;
}
list_add_rcu(&data->list, &file->triggers);
ret++;
update_cond_flag(file);
if (trace_event_trigger_enable_disable(file, 1) < 0) {
list_del_rcu(&data->list);
update_cond_flag(file);
ret--;
}
out:
return ret;
}
static void unregister_trigger(char *glob, struct event_trigger_ops *ops,
struct event_trigger_data *test,
struct trace_event_file *file)
{
struct event_trigger_data *data;
bool unregistered = false;
list_for_each_entry_rcu(data, &file->triggers, list) {
if (data->cmd_ops->trigger_type == test->cmd_ops->trigger_type) {
unregistered = true;
list_del_rcu(&data->list);
trace_event_trigger_enable_disable(file, 0);
update_cond_flag(file);
break;
}
}
if (unregistered && data->ops->free)
data->ops->free(data->ops, data);
}
static int
event_trigger_callback(struct event_command *cmd_ops,
struct trace_event_file *file,
char *glob, char *cmd, char *param)
{
struct event_trigger_data *trigger_data;
struct event_trigger_ops *trigger_ops;
char *trigger = NULL;
char *number;
int ret;
if (param && isdigit(param[0]))
trigger = strsep(&param, " \t");
trigger_ops = cmd_ops->get_trigger_ops(cmd, trigger);
ret = -ENOMEM;
trigger_data = kzalloc(sizeof(*trigger_data), GFP_KERNEL);
if (!trigger_data)
goto out;
trigger_data->count = -1;
trigger_data->ops = trigger_ops;
trigger_data->cmd_ops = cmd_ops;
INIT_LIST_HEAD(&trigger_data->list);
if (glob[0] == '!') {
cmd_ops->unreg(glob+1, trigger_ops, trigger_data, file);
kfree(trigger_data);
ret = 0;
goto out;
}
if (trigger) {
number = strsep(&trigger, ":");
ret = -EINVAL;
if (!strlen(number))
goto out_free;
ret = kstrtoul(number, 0, &trigger_data->count);
if (ret)
goto out_free;
}
if (!param)
goto out_reg;
if (!cmd_ops->set_filter)
goto out_reg;
ret = cmd_ops->set_filter(param, trigger_data, file);
if (ret < 0)
goto out_free;
out_reg:
ret = cmd_ops->reg(glob, trigger_ops, trigger_data, file);
if (!ret) {
ret = -ENOENT;
goto out_free;
} else if (ret < 0)
goto out_free;
ret = 0;
out:
return ret;
out_free:
if (cmd_ops->set_filter)
cmd_ops->set_filter(NULL, trigger_data, NULL);
kfree(trigger_data);
goto out;
}
static int set_trigger_filter(char *filter_str,
struct event_trigger_data *trigger_data,
struct trace_event_file *file)
{
struct event_trigger_data *data = trigger_data;
struct event_filter *filter = NULL, *tmp;
int ret = -EINVAL;
char *s;
if (!filter_str)
goto assign;
s = strsep(&filter_str, " \t");
if (!strlen(s) || strcmp(s, "if") != 0)
goto out;
if (!filter_str)
goto out;
ret = create_event_filter(file->event_call, filter_str, false, &filter);
if (ret)
goto out;
assign:
tmp = rcu_access_pointer(data->filter);
rcu_assign_pointer(data->filter, filter);
if (tmp) {
synchronize_sched();
free_event_filter(tmp);
}
kfree(data->filter_str);
data->filter_str = NULL;
if (filter_str) {
data->filter_str = kstrdup(filter_str, GFP_KERNEL);
if (!data->filter_str) {
free_event_filter(rcu_access_pointer(data->filter));
data->filter = NULL;
ret = -ENOMEM;
}
}
out:
return ret;
}
static void
traceon_trigger(struct event_trigger_data *data)
{
if (tracing_is_on())
return;
tracing_on();
}
static void
traceon_count_trigger(struct event_trigger_data *data)
{
if (tracing_is_on())
return;
if (!data->count)
return;
if (data->count != -1)
(data->count)--;
tracing_on();
}
static void
traceoff_trigger(struct event_trigger_data *data)
{
if (!tracing_is_on())
return;
tracing_off();
}
static void
traceoff_count_trigger(struct event_trigger_data *data)
{
if (!tracing_is_on())
return;
if (!data->count)
return;
if (data->count != -1)
(data->count)--;
tracing_off();
}
static int
traceon_trigger_print(struct seq_file *m, struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
return event_trigger_print("traceon", m, (void *)data->count,
data->filter_str);
}
static int
traceoff_trigger_print(struct seq_file *m, struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
return event_trigger_print("traceoff", m, (void *)data->count,
data->filter_str);
}
static struct event_trigger_ops *
onoff_get_trigger_ops(char *cmd, char *param)
{
struct event_trigger_ops *ops;
if (strcmp(cmd, "traceon") == 0)
ops = param ? &traceon_count_trigger_ops :
&traceon_trigger_ops;
else
ops = param ? &traceoff_count_trigger_ops :
&traceoff_trigger_ops;
return ops;
}
static void
snapshot_trigger(struct event_trigger_data *data)
{
tracing_snapshot();
}
static void
snapshot_count_trigger(struct event_trigger_data *data)
{
if (!data->count)
return;
if (data->count != -1)
(data->count)--;
snapshot_trigger(data);
}
static int
register_snapshot_trigger(char *glob, struct event_trigger_ops *ops,
struct event_trigger_data *data,
struct trace_event_file *file)
{
int ret = register_trigger(glob, ops, data, file);
if (ret > 0 && tracing_alloc_snapshot() != 0) {
unregister_trigger(glob, ops, data, file);
ret = 0;
}
return ret;
}
static int
snapshot_trigger_print(struct seq_file *m, struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
return event_trigger_print("snapshot", m, (void *)data->count,
data->filter_str);
}
static struct event_trigger_ops *
snapshot_get_trigger_ops(char *cmd, char *param)
{
return param ? &snapshot_count_trigger_ops : &snapshot_trigger_ops;
}
static __init int register_trigger_snapshot_cmd(void)
{
int ret;
ret = register_event_command(&trigger_snapshot_cmd);
WARN_ON(ret < 0);
return ret;
}
static __init int register_trigger_snapshot_cmd(void) { return 0; }
static void
stacktrace_trigger(struct event_trigger_data *data)
{
trace_dump_stack(STACK_SKIP);
}
static void
stacktrace_count_trigger(struct event_trigger_data *data)
{
if (!data->count)
return;
if (data->count != -1)
(data->count)--;
stacktrace_trigger(data);
}
static int
stacktrace_trigger_print(struct seq_file *m, struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
return event_trigger_print("stacktrace", m, (void *)data->count,
data->filter_str);
}
static struct event_trigger_ops *
stacktrace_get_trigger_ops(char *cmd, char *param)
{
return param ? &stacktrace_count_trigger_ops : &stacktrace_trigger_ops;
}
static __init int register_trigger_stacktrace_cmd(void)
{
int ret;
ret = register_event_command(&trigger_stacktrace_cmd);
WARN_ON(ret < 0);
return ret;
}
static __init int register_trigger_stacktrace_cmd(void) { return 0; }
static __init void unregister_trigger_traceon_traceoff_cmds(void)
{
unregister_event_command(&trigger_traceon_cmd);
unregister_event_command(&trigger_traceoff_cmd);
}
static void
event_enable_trigger(struct event_trigger_data *data)
{
struct enable_trigger_data *enable_data = data->private_data;
if (enable_data->enable)
clear_bit(EVENT_FILE_FL_SOFT_DISABLED_BIT, &enable_data->file->flags);
else
set_bit(EVENT_FILE_FL_SOFT_DISABLED_BIT, &enable_data->file->flags);
}
static void
event_enable_count_trigger(struct event_trigger_data *data)
{
struct enable_trigger_data *enable_data = data->private_data;
if (!data->count)
return;
if (enable_data->enable == !(enable_data->file->flags & EVENT_FILE_FL_SOFT_DISABLED))
return;
if (data->count != -1)
(data->count)--;
event_enable_trigger(data);
}
static int
event_enable_trigger_print(struct seq_file *m, struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
struct enable_trigger_data *enable_data = data->private_data;
seq_printf(m, "%s:%s:%s",
enable_data->enable ? ENABLE_EVENT_STR : DISABLE_EVENT_STR,
enable_data->file->event_call->class->system,
trace_event_name(enable_data->file->event_call));
if (data->count == -1)
seq_puts(m, ":unlimited");
else
seq_printf(m, ":count=%ld", data->count);
if (data->filter_str)
seq_printf(m, " if %s\n", data->filter_str);
else
seq_putc(m, '\n');
return 0;
}
static void
event_enable_trigger_free(struct event_trigger_ops *ops,
struct event_trigger_data *data)
{
struct enable_trigger_data *enable_data = data->private_data;
if (WARN_ON_ONCE(data->ref <= 0))
return;
data->ref--;
if (!data->ref) {
trace_event_enable_disable(enable_data->file, 0, 1);
module_put(enable_data->file->event_call->mod);
trigger_data_free(data);
kfree(enable_data);
}
}
static int
event_enable_trigger_func(struct event_command *cmd_ops,
struct trace_event_file *file,
char *glob, char *cmd, char *param)
{
struct trace_event_file *event_enable_file;
struct enable_trigger_data *enable_data;
struct event_trigger_data *trigger_data;
struct event_trigger_ops *trigger_ops;
struct trace_array *tr = file->tr;
const char *system;
const char *event;
char *trigger;
char *number;
bool enable;
int ret;
if (!param)
return -EINVAL;
trigger = strsep(&param, " \t");
if (!trigger)
return -EINVAL;
system = strsep(&trigger, ":");
if (!trigger)
return -EINVAL;
event = strsep(&trigger, ":");
ret = -EINVAL;
event_enable_file = find_event_file(tr, system, event);
if (!event_enable_file)
goto out;
enable = strcmp(cmd, ENABLE_EVENT_STR) == 0;
trigger_ops = cmd_ops->get_trigger_ops(cmd, trigger);
ret = -ENOMEM;
trigger_data = kzalloc(sizeof(*trigger_data), GFP_KERNEL);
if (!trigger_data)
goto out;
enable_data = kzalloc(sizeof(*enable_data), GFP_KERNEL);
if (!enable_data) {
kfree(trigger_data);
goto out;
}
trigger_data->count = -1;
trigger_data->ops = trigger_ops;
trigger_data->cmd_ops = cmd_ops;
INIT_LIST_HEAD(&trigger_data->list);
RCU_INIT_POINTER(trigger_data->filter, NULL);
enable_data->enable = enable;
enable_data->file = event_enable_file;
trigger_data->private_data = enable_data;
if (glob[0] == '!') {
cmd_ops->unreg(glob+1, trigger_ops, trigger_data, file);
kfree(trigger_data);
kfree(enable_data);
ret = 0;
goto out;
}
if (trigger) {
number = strsep(&trigger, ":");
ret = -EINVAL;
if (!strlen(number))
goto out_free;
ret = kstrtoul(number, 0, &trigger_data->count);
if (ret)
goto out_free;
}
if (!param)
goto out_reg;
if (!cmd_ops->set_filter)
goto out_reg;
ret = cmd_ops->set_filter(param, trigger_data, file);
if (ret < 0)
goto out_free;
out_reg:
ret = try_module_get(event_enable_file->event_call->mod);
if (!ret) {
ret = -EBUSY;
goto out_free;
}
ret = trace_event_enable_disable(event_enable_file, 1, 1);
if (ret < 0)
goto out_put;
ret = cmd_ops->reg(glob, trigger_ops, trigger_data, file);
if (!ret) {
ret = -ENOENT;
goto out_disable;
} else if (ret < 0)
goto out_disable;
ret = 0;
out:
return ret;
out_disable:
trace_event_enable_disable(event_enable_file, 0, 1);
out_put:
module_put(event_enable_file->event_call->mod);
out_free:
if (cmd_ops->set_filter)
cmd_ops->set_filter(NULL, trigger_data, NULL);
kfree(trigger_data);
kfree(enable_data);
goto out;
}
static int event_enable_register_trigger(char *glob,
struct event_trigger_ops *ops,
struct event_trigger_data *data,
struct trace_event_file *file)
{
struct enable_trigger_data *enable_data = data->private_data;
struct enable_trigger_data *test_enable_data;
struct event_trigger_data *test;
int ret = 0;
list_for_each_entry_rcu(test, &file->triggers, list) {
test_enable_data = test->private_data;
if (test_enable_data &&
(test_enable_data->file == enable_data->file)) {
ret = -EEXIST;
goto out;
}
}
if (data->ops->init) {
ret = data->ops->init(data->ops, data);
if (ret < 0)
goto out;
}
list_add_rcu(&data->list, &file->triggers);
ret++;
update_cond_flag(file);
if (trace_event_trigger_enable_disable(file, 1) < 0) {
list_del_rcu(&data->list);
update_cond_flag(file);
ret--;
}
out:
return ret;
}
static void event_enable_unregister_trigger(char *glob,
struct event_trigger_ops *ops,
struct event_trigger_data *test,
struct trace_event_file *file)
{
struct enable_trigger_data *test_enable_data = test->private_data;
struct enable_trigger_data *enable_data;
struct event_trigger_data *data;
bool unregistered = false;
list_for_each_entry_rcu(data, &file->triggers, list) {
enable_data = data->private_data;
if (enable_data &&
(enable_data->file == test_enable_data->file)) {
unregistered = true;
list_del_rcu(&data->list);
trace_event_trigger_enable_disable(file, 0);
update_cond_flag(file);
break;
}
}
if (unregistered && data->ops->free)
data->ops->free(data->ops, data);
}
static struct event_trigger_ops *
event_enable_get_trigger_ops(char *cmd, char *param)
{
struct event_trigger_ops *ops;
bool enable;
enable = strcmp(cmd, ENABLE_EVENT_STR) == 0;
if (enable)
ops = param ? &event_enable_count_trigger_ops :
&event_enable_trigger_ops;
else
ops = param ? &event_disable_count_trigger_ops :
&event_disable_trigger_ops;
return ops;
}
static __init void unregister_trigger_enable_disable_cmds(void)
{
unregister_event_command(&trigger_enable_cmd);
unregister_event_command(&trigger_disable_cmd);
}
static __init int register_trigger_enable_disable_cmds(void)
{
int ret;
ret = register_event_command(&trigger_enable_cmd);
if (WARN_ON(ret < 0))
return ret;
ret = register_event_command(&trigger_disable_cmd);
if (WARN_ON(ret < 0))
unregister_trigger_enable_disable_cmds();
return ret;
}
static __init int register_trigger_traceon_traceoff_cmds(void)
{
int ret;
ret = register_event_command(&trigger_traceon_cmd);
if (WARN_ON(ret < 0))
return ret;
ret = register_event_command(&trigger_traceoff_cmd);
if (WARN_ON(ret < 0))
unregister_trigger_traceon_traceoff_cmds();
return ret;
}
__init int register_trigger_cmds(void)
{
register_trigger_traceon_traceoff_cmds();
register_trigger_snapshot_cmd();
register_trigger_stacktrace_cmd();
register_trigger_enable_disable_cmds();
return 0;
}
