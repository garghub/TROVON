static nokprobe_inline bool trace_kprobe_is_return(struct trace_kprobe *tk)
{
return tk->rp.handler != NULL;
}
static nokprobe_inline const char *trace_kprobe_symbol(struct trace_kprobe *tk)
{
return tk->symbol ? tk->symbol : "unknown";
}
static nokprobe_inline unsigned long trace_kprobe_offset(struct trace_kprobe *tk)
{
return tk->rp.kp.offset;
}
static nokprobe_inline bool trace_kprobe_has_gone(struct trace_kprobe *tk)
{
return !!(kprobe_gone(&tk->rp.kp));
}
static nokprobe_inline bool trace_kprobe_within_module(struct trace_kprobe *tk,
struct module *mod)
{
int len = strlen(mod->name);
const char *name = trace_kprobe_symbol(tk);
return strncmp(mod->name, name, len) == 0 && name[len] == ':';
}
static nokprobe_inline bool trace_kprobe_is_on_module(struct trace_kprobe *tk)
{
return !!strchr(trace_kprobe_symbol(tk), ':');
}
unsigned long update_symbol_cache(struct symbol_cache *sc)
{
sc->addr = (unsigned long)kallsyms_lookup_name(sc->symbol);
if (sc->addr)
sc->addr += sc->offset;
return sc->addr;
}
void free_symbol_cache(struct symbol_cache *sc)
{
kfree(sc->symbol);
kfree(sc);
}
struct symbol_cache *alloc_symbol_cache(const char *sym, long offset)
{
struct symbol_cache *sc;
if (!sym || strlen(sym) == 0)
return NULL;
sc = kzalloc(sizeof(struct symbol_cache), GFP_KERNEL);
if (!sc)
return NULL;
sc->symbol = kstrdup(sym, GFP_KERNEL);
if (!sc->symbol) {
kfree(sc);
return NULL;
}
sc->offset = offset;
update_symbol_cache(sc);
return sc;
}
static struct trace_kprobe *alloc_trace_kprobe(const char *group,
const char *event,
void *addr,
const char *symbol,
unsigned long offs,
int nargs, bool is_return)
{
struct trace_kprobe *tk;
int ret = -ENOMEM;
tk = kzalloc(SIZEOF_TRACE_KPROBE(nargs), GFP_KERNEL);
if (!tk)
return ERR_PTR(ret);
if (symbol) {
tk->symbol = kstrdup(symbol, GFP_KERNEL);
if (!tk->symbol)
goto error;
tk->rp.kp.symbol_name = tk->symbol;
tk->rp.kp.offset = offs;
} else
tk->rp.kp.addr = addr;
if (is_return)
tk->rp.handler = kretprobe_dispatcher;
else
tk->rp.kp.pre_handler = kprobe_dispatcher;
if (!event || !is_good_name(event)) {
ret = -EINVAL;
goto error;
}
tk->tp.call.class = &tk->tp.class;
tk->tp.call.name = kstrdup(event, GFP_KERNEL);
if (!tk->tp.call.name)
goto error;
if (!group || !is_good_name(group)) {
ret = -EINVAL;
goto error;
}
tk->tp.class.system = kstrdup(group, GFP_KERNEL);
if (!tk->tp.class.system)
goto error;
INIT_LIST_HEAD(&tk->list);
INIT_LIST_HEAD(&tk->tp.files);
return tk;
error:
kfree(tk->tp.call.name);
kfree(tk->symbol);
kfree(tk);
return ERR_PTR(ret);
}
static void free_trace_kprobe(struct trace_kprobe *tk)
{
int i;
for (i = 0; i < tk->tp.nr_args; i++)
traceprobe_free_probe_arg(&tk->tp.args[i]);
kfree(tk->tp.call.class->system);
kfree(tk->tp.call.name);
kfree(tk->symbol);
kfree(tk);
}
static struct trace_kprobe *find_trace_kprobe(const char *event,
const char *group)
{
struct trace_kprobe *tk;
list_for_each_entry(tk, &probe_list, list)
if (strcmp(ftrace_event_name(&tk->tp.call), event) == 0 &&
strcmp(tk->tp.call.class->system, group) == 0)
return tk;
return NULL;
}
static int
enable_trace_kprobe(struct trace_kprobe *tk, struct ftrace_event_file *file)
{
int ret = 0;
if (file) {
struct event_file_link *link;
link = kmalloc(sizeof(*link), GFP_KERNEL);
if (!link) {
ret = -ENOMEM;
goto out;
}
link->file = file;
list_add_tail_rcu(&link->list, &tk->tp.files);
tk->tp.flags |= TP_FLAG_TRACE;
} else
tk->tp.flags |= TP_FLAG_PROFILE;
if (trace_probe_is_registered(&tk->tp) && !trace_kprobe_has_gone(tk)) {
if (trace_kprobe_is_return(tk))
ret = enable_kretprobe(&tk->rp);
else
ret = enable_kprobe(&tk->rp.kp);
}
out:
return ret;
}
static int
disable_trace_kprobe(struct trace_kprobe *tk, struct ftrace_event_file *file)
{
struct event_file_link *link = NULL;
int wait = 0;
int ret = 0;
if (file) {
link = find_event_file_link(&tk->tp, file);
if (!link) {
ret = -EINVAL;
goto out;
}
list_del_rcu(&link->list);
wait = 1;
if (!list_empty(&tk->tp.files))
goto out;
tk->tp.flags &= ~TP_FLAG_TRACE;
} else
tk->tp.flags &= ~TP_FLAG_PROFILE;
if (!trace_probe_is_enabled(&tk->tp) && trace_probe_is_registered(&tk->tp)) {
if (trace_kprobe_is_return(tk))
disable_kretprobe(&tk->rp);
else
disable_kprobe(&tk->rp.kp);
wait = 1;
}
out:
if (wait) {
synchronize_sched();
kfree(link);
}
return ret;
}
static int __register_trace_kprobe(struct trace_kprobe *tk)
{
int i, ret;
if (trace_probe_is_registered(&tk->tp))
return -EINVAL;
for (i = 0; i < tk->tp.nr_args; i++)
traceprobe_update_arg(&tk->tp.args[i]);
if (trace_probe_is_enabled(&tk->tp))
tk->rp.kp.flags &= ~KPROBE_FLAG_DISABLED;
else
tk->rp.kp.flags |= KPROBE_FLAG_DISABLED;
if (trace_kprobe_is_return(tk))
ret = register_kretprobe(&tk->rp);
else
ret = register_kprobe(&tk->rp.kp);
if (ret == 0)
tk->tp.flags |= TP_FLAG_REGISTERED;
else {
pr_warning("Could not insert probe at %s+%lu: %d\n",
trace_kprobe_symbol(tk), trace_kprobe_offset(tk), ret);
if (ret == -ENOENT && trace_kprobe_is_on_module(tk)) {
pr_warning("This probe might be able to register after"
"target module is loaded. Continue.\n");
ret = 0;
} else if (ret == -EILSEQ) {
pr_warning("Probing address(0x%p) is not an "
"instruction boundary.\n",
tk->rp.kp.addr);
ret = -EINVAL;
}
}
return ret;
}
static void __unregister_trace_kprobe(struct trace_kprobe *tk)
{
if (trace_probe_is_registered(&tk->tp)) {
if (trace_kprobe_is_return(tk))
unregister_kretprobe(&tk->rp);
else
unregister_kprobe(&tk->rp.kp);
tk->tp.flags &= ~TP_FLAG_REGISTERED;
if (tk->rp.kp.symbol_name)
tk->rp.kp.addr = NULL;
}
}
static int unregister_trace_kprobe(struct trace_kprobe *tk)
{
if (trace_probe_is_enabled(&tk->tp))
return -EBUSY;
if (unregister_kprobe_event(tk))
return -EBUSY;
__unregister_trace_kprobe(tk);
list_del(&tk->list);
return 0;
}
static int register_trace_kprobe(struct trace_kprobe *tk)
{
struct trace_kprobe *old_tk;
int ret;
mutex_lock(&probe_lock);
old_tk = find_trace_kprobe(ftrace_event_name(&tk->tp.call),
tk->tp.call.class->system);
if (old_tk) {
ret = unregister_trace_kprobe(old_tk);
if (ret < 0)
goto end;
free_trace_kprobe(old_tk);
}
ret = register_kprobe_event(tk);
if (ret) {
pr_warning("Failed to register probe event(%d)\n", ret);
goto end;
}
ret = __register_trace_kprobe(tk);
if (ret < 0)
unregister_kprobe_event(tk);
else
list_add_tail(&tk->list, &probe_list);
end:
mutex_unlock(&probe_lock);
return ret;
}
static int trace_kprobe_module_callback(struct notifier_block *nb,
unsigned long val, void *data)
{
struct module *mod = data;
struct trace_kprobe *tk;
int ret;
if (val != MODULE_STATE_COMING)
return NOTIFY_DONE;
mutex_lock(&probe_lock);
list_for_each_entry(tk, &probe_list, list) {
if (trace_kprobe_within_module(tk, mod)) {
__unregister_trace_kprobe(tk);
ret = __register_trace_kprobe(tk);
if (ret)
pr_warning("Failed to re-register probe %s on"
"%s: %d\n",
ftrace_event_name(&tk->tp.call),
mod->name, ret);
}
}
mutex_unlock(&probe_lock);
return NOTIFY_DONE;
}
static int create_trace_kprobe(int argc, char **argv)
{
struct trace_kprobe *tk;
int i, ret = 0;
bool is_return = false, is_delete = false;
char *symbol = NULL, *event = NULL, *group = NULL;
char *arg;
unsigned long offset = 0;
void *addr = NULL;
char buf[MAX_EVENT_NAME_LEN];
if (argv[0][0] == 'p')
is_return = false;
else if (argv[0][0] == 'r')
is_return = true;
else if (argv[0][0] == '-')
is_delete = true;
else {
pr_info("Probe definition must be started with 'p', 'r' or"
" '-'.\n");
return -EINVAL;
}
if (argv[0][1] == ':') {
event = &argv[0][2];
if (strchr(event, '/')) {
group = event;
event = strchr(group, '/') + 1;
event[-1] = '\0';
if (strlen(group) == 0) {
pr_info("Group name is not specified\n");
return -EINVAL;
}
}
if (strlen(event) == 0) {
pr_info("Event name is not specified\n");
return -EINVAL;
}
}
if (!group)
group = KPROBE_EVENT_SYSTEM;
if (is_delete) {
if (!event) {
pr_info("Delete command needs an event name.\n");
return -EINVAL;
}
mutex_lock(&probe_lock);
tk = find_trace_kprobe(event, group);
if (!tk) {
mutex_unlock(&probe_lock);
pr_info("Event %s/%s doesn't exist.\n", group, event);
return -ENOENT;
}
ret = unregister_trace_kprobe(tk);
if (ret == 0)
free_trace_kprobe(tk);
mutex_unlock(&probe_lock);
return ret;
}
if (argc < 2) {
pr_info("Probe point is not specified.\n");
return -EINVAL;
}
if (isdigit(argv[1][0])) {
if (is_return) {
pr_info("Return probe point must be a symbol.\n");
return -EINVAL;
}
ret = kstrtoul(&argv[1][0], 0, (unsigned long *)&addr);
if (ret) {
pr_info("Failed to parse address.\n");
return ret;
}
} else {
symbol = argv[1];
ret = traceprobe_split_symbol_offset(symbol, &offset);
if (ret) {
pr_info("Failed to parse symbol.\n");
return ret;
}
if (offset && is_return) {
pr_info("Return probe must be used without offset.\n");
return -EINVAL;
}
}
argc -= 2; argv += 2;
if (!event) {
if (symbol)
snprintf(buf, MAX_EVENT_NAME_LEN, "%c_%s_%ld",
is_return ? 'r' : 'p', symbol, offset);
else
snprintf(buf, MAX_EVENT_NAME_LEN, "%c_0x%p",
is_return ? 'r' : 'p', addr);
event = buf;
}
tk = alloc_trace_kprobe(group, event, addr, symbol, offset, argc,
is_return);
if (IS_ERR(tk)) {
pr_info("Failed to allocate trace_probe.(%d)\n",
(int)PTR_ERR(tk));
return PTR_ERR(tk);
}
ret = 0;
for (i = 0; i < argc && i < MAX_TRACE_ARGS; i++) {
struct probe_arg *parg = &tk->tp.args[i];
tk->tp.nr_args++;
arg = strchr(argv[i], '=');
if (arg) {
*arg++ = '\0';
parg->name = kstrdup(argv[i], GFP_KERNEL);
} else {
arg = argv[i];
snprintf(buf, MAX_EVENT_NAME_LEN, "arg%d", i + 1);
parg->name = kstrdup(buf, GFP_KERNEL);
}
if (!parg->name) {
pr_info("Failed to allocate argument[%d] name.\n", i);
ret = -ENOMEM;
goto error;
}
if (!is_good_name(parg->name)) {
pr_info("Invalid argument[%d] name: %s\n",
i, parg->name);
ret = -EINVAL;
goto error;
}
if (traceprobe_conflict_field_name(parg->name,
tk->tp.args, i)) {
pr_info("Argument[%d] name '%s' conflicts with "
"another field.\n", i, argv[i]);
ret = -EINVAL;
goto error;
}
ret = traceprobe_parse_probe_arg(arg, &tk->tp.size, parg,
is_return, true);
if (ret) {
pr_info("Parse error at argument[%d]. (%d)\n", i, ret);
goto error;
}
}
ret = register_trace_kprobe(tk);
if (ret)
goto error;
return 0;
error:
free_trace_kprobe(tk);
return ret;
}
static int release_all_trace_kprobes(void)
{
struct trace_kprobe *tk;
int ret = 0;
mutex_lock(&probe_lock);
list_for_each_entry(tk, &probe_list, list)
if (trace_probe_is_enabled(&tk->tp)) {
ret = -EBUSY;
goto end;
}
while (!list_empty(&probe_list)) {
tk = list_entry(probe_list.next, struct trace_kprobe, list);
ret = unregister_trace_kprobe(tk);
if (ret)
goto end;
free_trace_kprobe(tk);
}
end:
mutex_unlock(&probe_lock);
return ret;
}
static void *probes_seq_start(struct seq_file *m, loff_t *pos)
{
mutex_lock(&probe_lock);
return seq_list_start(&probe_list, *pos);
}
static void *probes_seq_next(struct seq_file *m, void *v, loff_t *pos)
{
return seq_list_next(v, &probe_list, pos);
}
static void probes_seq_stop(struct seq_file *m, void *v)
{
mutex_unlock(&probe_lock);
}
static int probes_seq_show(struct seq_file *m, void *v)
{
struct trace_kprobe *tk = v;
int i;
seq_putc(m, trace_kprobe_is_return(tk) ? 'r' : 'p');
seq_printf(m, ":%s/%s", tk->tp.call.class->system,
ftrace_event_name(&tk->tp.call));
if (!tk->symbol)
seq_printf(m, " 0x%p", tk->rp.kp.addr);
else if (tk->rp.kp.offset)
seq_printf(m, " %s+%u", trace_kprobe_symbol(tk),
tk->rp.kp.offset);
else
seq_printf(m, " %s", trace_kprobe_symbol(tk));
for (i = 0; i < tk->tp.nr_args; i++)
seq_printf(m, " %s=%s", tk->tp.args[i].name, tk->tp.args[i].comm);
seq_putc(m, '\n');
return 0;
}
static int probes_open(struct inode *inode, struct file *file)
{
int ret;
if ((file->f_mode & FMODE_WRITE) && (file->f_flags & O_TRUNC)) {
ret = release_all_trace_kprobes();
if (ret < 0)
return ret;
}
return seq_open(file, &probes_seq_op);
}
static ssize_t probes_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
return traceprobe_probes_write(file, buffer, count, ppos,
create_trace_kprobe);
}
static int probes_profile_seq_show(struct seq_file *m, void *v)
{
struct trace_kprobe *tk = v;
seq_printf(m, " %-44s %15lu %15lu\n",
ftrace_event_name(&tk->tp.call), tk->nhit,
tk->rp.kp.nmissed);
return 0;
}
static int profile_open(struct inode *inode, struct file *file)
{
return seq_open(file, &profile_seq_op);
}
static nokprobe_inline void
__kprobe_trace_func(struct trace_kprobe *tk, struct pt_regs *regs,
struct ftrace_event_file *ftrace_file)
{
struct kprobe_trace_entry_head *entry;
struct ring_buffer_event *event;
struct ring_buffer *buffer;
int size, dsize, pc;
unsigned long irq_flags;
struct ftrace_event_call *call = &tk->tp.call;
WARN_ON(call != ftrace_file->event_call);
if (ftrace_trigger_soft_disabled(ftrace_file))
return;
local_save_flags(irq_flags);
pc = preempt_count();
dsize = __get_data_size(&tk->tp, regs);
size = sizeof(*entry) + tk->tp.size + dsize;
event = trace_event_buffer_lock_reserve(&buffer, ftrace_file,
call->event.type,
size, irq_flags, pc);
if (!event)
return;
entry = ring_buffer_event_data(event);
entry->ip = (unsigned long)tk->rp.kp.addr;
store_trace_args(sizeof(*entry), &tk->tp, regs, (u8 *)&entry[1], dsize);
event_trigger_unlock_commit_regs(ftrace_file, buffer, event,
entry, irq_flags, pc, regs);
}
static void
kprobe_trace_func(struct trace_kprobe *tk, struct pt_regs *regs)
{
struct event_file_link *link;
list_for_each_entry_rcu(link, &tk->tp.files, list)
__kprobe_trace_func(tk, regs, link->file);
}
static nokprobe_inline void
__kretprobe_trace_func(struct trace_kprobe *tk, struct kretprobe_instance *ri,
struct pt_regs *regs,
struct ftrace_event_file *ftrace_file)
{
struct kretprobe_trace_entry_head *entry;
struct ring_buffer_event *event;
struct ring_buffer *buffer;
int size, pc, dsize;
unsigned long irq_flags;
struct ftrace_event_call *call = &tk->tp.call;
WARN_ON(call != ftrace_file->event_call);
if (ftrace_trigger_soft_disabled(ftrace_file))
return;
local_save_flags(irq_flags);
pc = preempt_count();
dsize = __get_data_size(&tk->tp, regs);
size = sizeof(*entry) + tk->tp.size + dsize;
event = trace_event_buffer_lock_reserve(&buffer, ftrace_file,
call->event.type,
size, irq_flags, pc);
if (!event)
return;
entry = ring_buffer_event_data(event);
entry->func = (unsigned long)tk->rp.kp.addr;
entry->ret_ip = (unsigned long)ri->ret_addr;
store_trace_args(sizeof(*entry), &tk->tp, regs, (u8 *)&entry[1], dsize);
event_trigger_unlock_commit_regs(ftrace_file, buffer, event,
entry, irq_flags, pc, regs);
}
static void
kretprobe_trace_func(struct trace_kprobe *tk, struct kretprobe_instance *ri,
struct pt_regs *regs)
{
struct event_file_link *link;
list_for_each_entry_rcu(link, &tk->tp.files, list)
__kretprobe_trace_func(tk, ri, regs, link->file);
}
static enum print_line_t
print_kprobe_event(struct trace_iterator *iter, int flags,
struct trace_event *event)
{
struct kprobe_trace_entry_head *field;
struct trace_seq *s = &iter->seq;
struct trace_probe *tp;
u8 *data;
int i;
field = (struct kprobe_trace_entry_head *)iter->ent;
tp = container_of(event, struct trace_probe, call.event);
trace_seq_printf(s, "%s: (", ftrace_event_name(&tp->call));
if (!seq_print_ip_sym(s, field->ip, flags | TRACE_ITER_SYM_OFFSET))
goto out;
trace_seq_putc(s, ')');
data = (u8 *)&field[1];
for (i = 0; i < tp->nr_args; i++)
if (!tp->args[i].type->print(s, tp->args[i].name,
data + tp->args[i].offset, field))
goto out;
trace_seq_putc(s, '\n');
out:
return trace_handle_return(s);
}
static enum print_line_t
print_kretprobe_event(struct trace_iterator *iter, int flags,
struct trace_event *event)
{
struct kretprobe_trace_entry_head *field;
struct trace_seq *s = &iter->seq;
struct trace_probe *tp;
u8 *data;
int i;
field = (struct kretprobe_trace_entry_head *)iter->ent;
tp = container_of(event, struct trace_probe, call.event);
trace_seq_printf(s, "%s: (", ftrace_event_name(&tp->call));
if (!seq_print_ip_sym(s, field->ret_ip, flags | TRACE_ITER_SYM_OFFSET))
goto out;
trace_seq_puts(s, " <- ");
if (!seq_print_ip_sym(s, field->func, flags & ~TRACE_ITER_SYM_OFFSET))
goto out;
trace_seq_putc(s, ')');
data = (u8 *)&field[1];
for (i = 0; i < tp->nr_args; i++)
if (!tp->args[i].type->print(s, tp->args[i].name,
data + tp->args[i].offset, field))
goto out;
trace_seq_putc(s, '\n');
out:
return trace_handle_return(s);
}
static int kprobe_event_define_fields(struct ftrace_event_call *event_call)
{
int ret, i;
struct kprobe_trace_entry_head field;
struct trace_kprobe *tk = (struct trace_kprobe *)event_call->data;
DEFINE_FIELD(unsigned long, ip, FIELD_STRING_IP, 0);
for (i = 0; i < tk->tp.nr_args; i++) {
struct probe_arg *parg = &tk->tp.args[i];
ret = trace_define_field(event_call, parg->type->fmttype,
parg->name,
sizeof(field) + parg->offset,
parg->type->size,
parg->type->is_signed,
FILTER_OTHER);
if (ret)
return ret;
}
return 0;
}
static int kretprobe_event_define_fields(struct ftrace_event_call *event_call)
{
int ret, i;
struct kretprobe_trace_entry_head field;
struct trace_kprobe *tk = (struct trace_kprobe *)event_call->data;
DEFINE_FIELD(unsigned long, func, FIELD_STRING_FUNC, 0);
DEFINE_FIELD(unsigned long, ret_ip, FIELD_STRING_RETIP, 0);
for (i = 0; i < tk->tp.nr_args; i++) {
struct probe_arg *parg = &tk->tp.args[i];
ret = trace_define_field(event_call, parg->type->fmttype,
parg->name,
sizeof(field) + parg->offset,
parg->type->size,
parg->type->is_signed,
FILTER_OTHER);
if (ret)
return ret;
}
return 0;
}
static void
kprobe_perf_func(struct trace_kprobe *tk, struct pt_regs *regs)
{
struct ftrace_event_call *call = &tk->tp.call;
struct kprobe_trace_entry_head *entry;
struct hlist_head *head;
int size, __size, dsize;
int rctx;
head = this_cpu_ptr(call->perf_events);
if (hlist_empty(head))
return;
dsize = __get_data_size(&tk->tp, regs);
__size = sizeof(*entry) + tk->tp.size + dsize;
size = ALIGN(__size + sizeof(u32), sizeof(u64));
size -= sizeof(u32);
entry = perf_trace_buf_prepare(size, call->event.type, regs, &rctx);
if (!entry)
return;
entry->ip = (unsigned long)tk->rp.kp.addr;
memset(&entry[1], 0, dsize);
store_trace_args(sizeof(*entry), &tk->tp, regs, (u8 *)&entry[1], dsize);
perf_trace_buf_submit(entry, size, rctx, 0, 1, regs, head, NULL);
}
static void
kretprobe_perf_func(struct trace_kprobe *tk, struct kretprobe_instance *ri,
struct pt_regs *regs)
{
struct ftrace_event_call *call = &tk->tp.call;
struct kretprobe_trace_entry_head *entry;
struct hlist_head *head;
int size, __size, dsize;
int rctx;
head = this_cpu_ptr(call->perf_events);
if (hlist_empty(head))
return;
dsize = __get_data_size(&tk->tp, regs);
__size = sizeof(*entry) + tk->tp.size + dsize;
size = ALIGN(__size + sizeof(u32), sizeof(u64));
size -= sizeof(u32);
entry = perf_trace_buf_prepare(size, call->event.type, regs, &rctx);
if (!entry)
return;
entry->func = (unsigned long)tk->rp.kp.addr;
entry->ret_ip = (unsigned long)ri->ret_addr;
store_trace_args(sizeof(*entry), &tk->tp, regs, (u8 *)&entry[1], dsize);
perf_trace_buf_submit(entry, size, rctx, 0, 1, regs, head, NULL);
}
static int kprobe_register(struct ftrace_event_call *event,
enum trace_reg type, void *data)
{
struct trace_kprobe *tk = (struct trace_kprobe *)event->data;
struct ftrace_event_file *file = data;
switch (type) {
case TRACE_REG_REGISTER:
return enable_trace_kprobe(tk, file);
case TRACE_REG_UNREGISTER:
return disable_trace_kprobe(tk, file);
#ifdef CONFIG_PERF_EVENTS
case TRACE_REG_PERF_REGISTER:
return enable_trace_kprobe(tk, NULL);
case TRACE_REG_PERF_UNREGISTER:
return disable_trace_kprobe(tk, NULL);
case TRACE_REG_PERF_OPEN:
case TRACE_REG_PERF_CLOSE:
case TRACE_REG_PERF_ADD:
case TRACE_REG_PERF_DEL:
return 0;
#endif
}
return 0;
}
static int kprobe_dispatcher(struct kprobe *kp, struct pt_regs *regs)
{
struct trace_kprobe *tk = container_of(kp, struct trace_kprobe, rp.kp);
tk->nhit++;
if (tk->tp.flags & TP_FLAG_TRACE)
kprobe_trace_func(tk, regs);
#ifdef CONFIG_PERF_EVENTS
if (tk->tp.flags & TP_FLAG_PROFILE)
kprobe_perf_func(tk, regs);
#endif
return 0;
}
static int
kretprobe_dispatcher(struct kretprobe_instance *ri, struct pt_regs *regs)
{
struct trace_kprobe *tk = container_of(ri->rp, struct trace_kprobe, rp);
tk->nhit++;
if (tk->tp.flags & TP_FLAG_TRACE)
kretprobe_trace_func(tk, ri, regs);
#ifdef CONFIG_PERF_EVENTS
if (tk->tp.flags & TP_FLAG_PROFILE)
kretprobe_perf_func(tk, ri, regs);
#endif
return 0;
}
static int register_kprobe_event(struct trace_kprobe *tk)
{
struct ftrace_event_call *call = &tk->tp.call;
int ret;
INIT_LIST_HEAD(&call->class->fields);
if (trace_kprobe_is_return(tk)) {
call->event.funcs = &kretprobe_funcs;
call->class->define_fields = kretprobe_event_define_fields;
} else {
call->event.funcs = &kprobe_funcs;
call->class->define_fields = kprobe_event_define_fields;
}
if (set_print_fmt(&tk->tp, trace_kprobe_is_return(tk)) < 0)
return -ENOMEM;
ret = register_ftrace_event(&call->event);
if (!ret) {
kfree(call->print_fmt);
return -ENODEV;
}
call->flags = 0;
call->class->reg = kprobe_register;
call->data = tk;
ret = trace_add_event_call(call);
if (ret) {
pr_info("Failed to register kprobe event: %s\n",
ftrace_event_name(call));
kfree(call->print_fmt);
unregister_ftrace_event(&call->event);
}
return ret;
}
static int unregister_kprobe_event(struct trace_kprobe *tk)
{
int ret;
ret = trace_remove_event_call(&tk->tp.call);
if (!ret)
kfree(tk->tp.call.print_fmt);
return ret;
}
static __init int init_kprobe_trace(void)
{
struct dentry *d_tracer;
struct dentry *entry;
if (register_module_notifier(&trace_kprobe_module_nb))
return -EINVAL;
d_tracer = tracing_init_dentry();
if (!d_tracer)
return 0;
entry = debugfs_create_file("kprobe_events", 0644, d_tracer,
NULL, &kprobe_events_ops);
if (!entry)
pr_warning("Could not create debugfs "
"'kprobe_events' entry\n");
entry = debugfs_create_file("kprobe_profile", 0444, d_tracer,
NULL, &kprobe_profile_ops);
if (!entry)
pr_warning("Could not create debugfs "
"'kprobe_profile' entry\n");
return 0;
}
static __used int kprobe_trace_selftest_target(int a1, int a2, int a3,
int a4, int a5, int a6)
{
return a1 + a2 + a3 + a4 + a5 + a6;
}
static struct ftrace_event_file *
find_trace_probe_file(struct trace_kprobe *tk, struct trace_array *tr)
{
struct ftrace_event_file *file;
list_for_each_entry(file, &tr->events, list)
if (file->event_call == &tk->tp.call)
return file;
return NULL;
}
static __init int kprobe_trace_self_tests_init(void)
{
int ret, warn = 0;
int (*target)(int, int, int, int, int, int);
struct trace_kprobe *tk;
struct ftrace_event_file *file;
if (tracing_is_disabled())
return -ENODEV;
target = kprobe_trace_selftest_target;
pr_info("Testing kprobe tracing: ");
ret = traceprobe_command("p:testprobe kprobe_trace_selftest_target "
"$stack $stack0 +0($stack)",
create_trace_kprobe);
if (WARN_ON_ONCE(ret)) {
pr_warn("error on probing function entry.\n");
warn++;
} else {
tk = find_trace_kprobe("testprobe", KPROBE_EVENT_SYSTEM);
if (WARN_ON_ONCE(tk == NULL)) {
pr_warn("error on getting new probe.\n");
warn++;
} else {
file = find_trace_probe_file(tk, top_trace_array());
if (WARN_ON_ONCE(file == NULL)) {
pr_warn("error on getting probe file.\n");
warn++;
} else
enable_trace_kprobe(tk, file);
}
}
ret = traceprobe_command("r:testprobe2 kprobe_trace_selftest_target "
"$retval", create_trace_kprobe);
if (WARN_ON_ONCE(ret)) {
pr_warn("error on probing function return.\n");
warn++;
} else {
tk = find_trace_kprobe("testprobe2", KPROBE_EVENT_SYSTEM);
if (WARN_ON_ONCE(tk == NULL)) {
pr_warn("error on getting 2nd new probe.\n");
warn++;
} else {
file = find_trace_probe_file(tk, top_trace_array());
if (WARN_ON_ONCE(file == NULL)) {
pr_warn("error on getting probe file.\n");
warn++;
} else
enable_trace_kprobe(tk, file);
}
}
if (warn)
goto end;
ret = target(1, 2, 3, 4, 5, 6);
tk = find_trace_kprobe("testprobe", KPROBE_EVENT_SYSTEM);
if (WARN_ON_ONCE(tk == NULL)) {
pr_warn("error on getting test probe.\n");
warn++;
} else {
file = find_trace_probe_file(tk, top_trace_array());
if (WARN_ON_ONCE(file == NULL)) {
pr_warn("error on getting probe file.\n");
warn++;
} else
disable_trace_kprobe(tk, file);
}
tk = find_trace_kprobe("testprobe2", KPROBE_EVENT_SYSTEM);
if (WARN_ON_ONCE(tk == NULL)) {
pr_warn("error on getting 2nd test probe.\n");
warn++;
} else {
file = find_trace_probe_file(tk, top_trace_array());
if (WARN_ON_ONCE(file == NULL)) {
pr_warn("error on getting probe file.\n");
warn++;
} else
disable_trace_kprobe(tk, file);
}
ret = traceprobe_command("-:testprobe", create_trace_kprobe);
if (WARN_ON_ONCE(ret)) {
pr_warn("error on deleting a probe.\n");
warn++;
}
ret = traceprobe_command("-:testprobe2", create_trace_kprobe);
if (WARN_ON_ONCE(ret)) {
pr_warn("error on deleting a probe.\n");
warn++;
}
end:
release_all_trace_kprobes();
if (warn)
pr_cont("NG: Some tests are failed. Please check them.\n");
else
pr_cont("OK\n");
return 0;
}
