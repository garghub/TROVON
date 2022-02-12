static void
probe_likely_condition(struct ftrace_likely_data *f, int val, int expect)
{
struct trace_event_call *call = &event_branch;
struct trace_array *tr = branch_tracer;
struct trace_array_cpu *data;
struct ring_buffer_event *event;
struct trace_branch *entry;
struct ring_buffer *buffer;
unsigned long flags;
int pc;
const char *p;
if (current->trace_recursion & TRACE_BRANCH_BIT)
return;
if (unlikely(!tr))
return;
raw_local_irq_save(flags);
current->trace_recursion |= TRACE_BRANCH_BIT;
data = this_cpu_ptr(tr->trace_buffer.data);
if (atomic_read(&data->disabled))
goto out;
pc = preempt_count();
buffer = tr->trace_buffer.buffer;
event = trace_buffer_lock_reserve(buffer, TRACE_BRANCH,
sizeof(*entry), flags, pc);
if (!event)
goto out;
entry = ring_buffer_event_data(event);
p = f->data.file + strlen(f->data.file);
while (p >= f->data.file && *p != '/')
p--;
p++;
strncpy(entry->func, f->data.func, TRACE_FUNC_SIZE);
strncpy(entry->file, p, TRACE_FILE_SIZE);
entry->func[TRACE_FUNC_SIZE] = 0;
entry->file[TRACE_FILE_SIZE] = 0;
entry->constant = f->constant;
entry->line = f->data.line;
entry->correct = val == expect;
if (!call_filter_check_discard(call, entry, buffer, event))
trace_buffer_unlock_commit_nostack(buffer, event);
out:
current->trace_recursion &= ~TRACE_BRANCH_BIT;
raw_local_irq_restore(flags);
}
static inline
void trace_likely_condition(struct ftrace_likely_data *f, int val, int expect)
{
if (!branch_tracing_enabled)
return;
probe_likely_condition(f, val, expect);
}
int enable_branch_tracing(struct trace_array *tr)
{
mutex_lock(&branch_tracing_mutex);
branch_tracer = tr;
smp_wmb();
branch_tracing_enabled++;
mutex_unlock(&branch_tracing_mutex);
return 0;
}
void disable_branch_tracing(void)
{
mutex_lock(&branch_tracing_mutex);
if (!branch_tracing_enabled)
goto out_unlock;
branch_tracing_enabled--;
out_unlock:
mutex_unlock(&branch_tracing_mutex);
}
static int branch_trace_init(struct trace_array *tr)
{
return enable_branch_tracing(tr);
}
static void branch_trace_reset(struct trace_array *tr)
{
disable_branch_tracing();
}
static enum print_line_t trace_branch_print(struct trace_iterator *iter,
int flags, struct trace_event *event)
{
struct trace_branch *field;
trace_assign_type(field, iter->ent);
trace_seq_printf(&iter->seq, "[%s] %s:%s:%d\n",
field->correct ? " ok " : " MISS ",
field->func,
field->file,
field->line);
return trace_handle_return(&iter->seq);
}
static void branch_print_header(struct seq_file *s)
{
seq_puts(s, "# TASK-PID CPU# TIMESTAMP CORRECT"
" FUNC:FILE:LINE\n"
"# | | | | | "
" |\n");
}
__init static int init_branch_tracer(void)
{
int ret;
ret = register_trace_event(&trace_branch_event);
if (!ret) {
printk(KERN_WARNING "Warning: could not register "
"branch events\n");
return 1;
}
return register_tracer(&branch_trace);
}
static inline
void trace_likely_condition(struct ftrace_likely_data *f, int val, int expect)
{
}
void ftrace_likely_update(struct ftrace_likely_data *f, int val,
int expect, int is_constant)
{
if (is_constant) {
f->constant++;
val = expect;
}
trace_likely_condition(f, val, expect);
if (val == expect)
f->data.correct++;
else
f->data.incorrect++;
}
static int annotated_branch_stat_headers(struct seq_file *m)
{
seq_puts(m, " correct incorrect % "
" Function "
" File Line\n"
" ------- --------- - "
" -------- "
" ---- ----\n");
return 0;
}
static inline long get_incorrect_percent(struct ftrace_branch_data *p)
{
long percent;
if (p->correct) {
percent = p->incorrect * 100;
percent /= p->correct + p->incorrect;
} else
percent = p->incorrect ? 100 : -1;
return percent;
}
static const char *branch_stat_process_file(struct ftrace_branch_data *p)
{
const char *f;
f = p->file + strlen(p->file);
while (f >= p->file && *f != '/')
f--;
return ++f;
}
static void branch_stat_show(struct seq_file *m,
struct ftrace_branch_data *p, const char *f)
{
long percent;
percent = get_incorrect_percent(p);
if (percent < 0)
seq_puts(m, " X ");
else
seq_printf(m, "%3ld ", percent);
seq_printf(m, "%-30.30s %-20.20s %d\n", p->func, f, p->line);
}
static int branch_stat_show_normal(struct seq_file *m,
struct ftrace_branch_data *p, const char *f)
{
seq_printf(m, "%8lu %8lu ", p->correct, p->incorrect);
branch_stat_show(m, p, f);
return 0;
}
static int annotate_branch_stat_show(struct seq_file *m, void *v)
{
struct ftrace_likely_data *p = v;
const char *f;
int l;
f = branch_stat_process_file(&p->data);
if (!p->constant)
return branch_stat_show_normal(m, &p->data, f);
l = snprintf(NULL, 0, "/%lu", p->constant);
l = l > 8 ? 0 : 8 - l;
seq_printf(m, "%8lu/%lu %*lu ",
p->data.correct, p->constant, l, p->data.incorrect);
branch_stat_show(m, &p->data, f);
return 0;
}
static void *annotated_branch_stat_start(struct tracer_stat *trace)
{
return __start_annotated_branch_profile;
}
static void *
annotated_branch_stat_next(void *v, int idx)
{
struct ftrace_likely_data *p = v;
++p;
if ((void *)p >= (void *)__stop_annotated_branch_profile)
return NULL;
return p;
}
static int annotated_branch_stat_cmp(void *p1, void *p2)
{
struct ftrace_branch_data *a = p1;
struct ftrace_branch_data *b = p2;
long percent_a, percent_b;
percent_a = get_incorrect_percent(a);
percent_b = get_incorrect_percent(b);
if (percent_a < percent_b)
return -1;
if (percent_a > percent_b)
return 1;
if (a->incorrect < b->incorrect)
return -1;
if (a->incorrect > b->incorrect)
return 1;
if (a->correct > b->correct)
return -1;
if (a->correct < b->correct)
return 1;
return 0;
}
__init static int init_annotated_branch_stats(void)
{
int ret;
ret = register_stat_tracer(&annotated_branch_stats);
if (!ret) {
printk(KERN_WARNING "Warning: could not register "
"annotated branches stats\n");
return 1;
}
return 0;
}
static int all_branch_stat_headers(struct seq_file *m)
{
seq_puts(m, " miss hit % "
" Function "
" File Line\n"
" ------- --------- - "
" -------- "
" ---- ----\n");
return 0;
}
static void *all_branch_stat_start(struct tracer_stat *trace)
{
return __start_branch_profile;
}
static void *
all_branch_stat_next(void *v, int idx)
{
struct ftrace_branch_data *p = v;
++p;
if ((void *)p >= (void *)__stop_branch_profile)
return NULL;
return p;
}
static int all_branch_stat_show(struct seq_file *m, void *v)
{
struct ftrace_branch_data *p = v;
const char *f;
f = branch_stat_process_file(p);
return branch_stat_show_normal(m, p, f);
}
__init static int all_annotated_branch_stats(void)
{
int ret;
ret = register_stat_tracer(&all_branch_stats);
if (!ret) {
printk(KERN_WARNING "Warning: could not register "
"all branches stats\n");
return 1;
}
return 0;
}
