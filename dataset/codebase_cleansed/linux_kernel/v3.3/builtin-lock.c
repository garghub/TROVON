static struct thread_stat *thread_stat_find(u32 tid)
{
struct rb_node *node;
struct thread_stat *st;
node = thread_stats.rb_node;
while (node) {
st = container_of(node, struct thread_stat, rb);
if (st->tid == tid)
return st;
else if (tid < st->tid)
node = node->rb_left;
else
node = node->rb_right;
}
return NULL;
}
static void thread_stat_insert(struct thread_stat *new)
{
struct rb_node **rb = &thread_stats.rb_node;
struct rb_node *parent = NULL;
struct thread_stat *p;
while (*rb) {
p = container_of(*rb, struct thread_stat, rb);
parent = *rb;
if (new->tid < p->tid)
rb = &(*rb)->rb_left;
else if (new->tid > p->tid)
rb = &(*rb)->rb_right;
else
BUG_ON("inserting invalid thread_stat\n");
}
rb_link_node(&new->rb, parent, rb);
rb_insert_color(&new->rb, &thread_stats);
}
static struct thread_stat *thread_stat_findnew_after_first(u32 tid)
{
struct thread_stat *st;
st = thread_stat_find(tid);
if (st)
return st;
st = zalloc(sizeof(struct thread_stat));
if (!st)
die("memory allocation failed\n");
st->tid = tid;
INIT_LIST_HEAD(&st->seq_list);
thread_stat_insert(st);
return st;
}
static struct thread_stat *thread_stat_findnew_first(u32 tid)
{
struct thread_stat *st;
st = zalloc(sizeof(struct thread_stat));
if (!st)
die("memory allocation failed\n");
st->tid = tid;
INIT_LIST_HEAD(&st->seq_list);
rb_link_node(&st->rb, NULL, &thread_stats.rb_node);
rb_insert_color(&st->rb, &thread_stats);
thread_stat_findnew = thread_stat_findnew_after_first;
return st;
}
static int lock_stat_key_wait_time_min(struct lock_stat *one,
struct lock_stat *two)
{
u64 s1 = one->wait_time_min;
u64 s2 = two->wait_time_min;
if (s1 == ULLONG_MAX)
s1 = 0;
if (s2 == ULLONG_MAX)
s2 = 0;
return s1 > s2;
}
static void select_key(void)
{
int i;
for (i = 0; keys[i].name; i++) {
if (!strcmp(keys[i].name, sort_key)) {
compare = keys[i].key;
return;
}
}
die("Unknown compare key:%s\n", sort_key);
}
static void insert_to_result(struct lock_stat *st,
int (*bigger)(struct lock_stat *, struct lock_stat *))
{
struct rb_node **rb = &result.rb_node;
struct rb_node *parent = NULL;
struct lock_stat *p;
while (*rb) {
p = container_of(*rb, struct lock_stat, rb);
parent = *rb;
if (bigger(st, p))
rb = &(*rb)->rb_left;
else
rb = &(*rb)->rb_right;
}
rb_link_node(&st->rb, parent, rb);
rb_insert_color(&st->rb, &result);
}
static struct lock_stat *pop_from_result(void)
{
struct rb_node *node = result.rb_node;
if (!node)
return NULL;
while (node->rb_left)
node = node->rb_left;
rb_erase(node, &result);
return container_of(node, struct lock_stat, rb);
}
static struct lock_stat *lock_stat_findnew(void *addr, const char *name)
{
struct list_head *entry = lockhashentry(addr);
struct lock_stat *ret, *new;
list_for_each_entry(ret, entry, hash_entry) {
if (ret->addr == addr)
return ret;
}
new = zalloc(sizeof(struct lock_stat));
if (!new)
goto alloc_failed;
new->addr = addr;
new->name = zalloc(sizeof(char) * strlen(name) + 1);
if (!new->name)
goto alloc_failed;
strcpy(new->name, name);
new->wait_time_min = ULLONG_MAX;
list_add(&new->hash_entry, entry);
return new;
alloc_failed:
die("memory allocation failed\n");
}
static struct lock_seq_stat *get_seq(struct thread_stat *ts, void *addr)
{
struct lock_seq_stat *seq;
list_for_each_entry(seq, &ts->seq_list, list) {
if (seq->addr == addr)
return seq;
}
seq = zalloc(sizeof(struct lock_seq_stat));
if (!seq)
die("Not enough memory\n");
seq->state = SEQ_STATE_UNINITIALIZED;
seq->addr = addr;
list_add(&seq->list, &ts->seq_list);
return seq;
}
static void
report_lock_acquire_event(struct trace_acquire_event *acquire_event,
struct event *__event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct lock_stat *ls;
struct thread_stat *ts;
struct lock_seq_stat *seq;
ls = lock_stat_findnew(acquire_event->addr, acquire_event->name);
if (ls->discard)
return;
ts = thread_stat_findnew(thread->pid);
seq = get_seq(ts, acquire_event->addr);
switch (seq->state) {
case SEQ_STATE_UNINITIALIZED:
case SEQ_STATE_RELEASED:
if (!acquire_event->flag) {
seq->state = SEQ_STATE_ACQUIRING;
} else {
if (acquire_event->flag & TRY_LOCK)
ls->nr_trylock++;
if (acquire_event->flag & READ_LOCK)
ls->nr_readlock++;
seq->state = SEQ_STATE_READ_ACQUIRED;
seq->read_count = 1;
ls->nr_acquired++;
}
break;
case SEQ_STATE_READ_ACQUIRED:
if (acquire_event->flag & READ_LOCK) {
seq->read_count++;
ls->nr_acquired++;
goto end;
} else {
goto broken;
}
break;
case SEQ_STATE_ACQUIRED:
case SEQ_STATE_ACQUIRING:
case SEQ_STATE_CONTENDED:
broken:
ls->discard = 1;
bad_hist[BROKEN_ACQUIRE]++;
list_del(&seq->list);
free(seq);
goto end;
break;
default:
BUG_ON("Unknown state of lock sequence found!\n");
break;
}
ls->nr_acquire++;
seq->prev_event_time = timestamp;
end:
return;
}
static void
report_lock_acquired_event(struct trace_acquired_event *acquired_event,
struct event *__event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct lock_stat *ls;
struct thread_stat *ts;
struct lock_seq_stat *seq;
u64 contended_term;
ls = lock_stat_findnew(acquired_event->addr, acquired_event->name);
if (ls->discard)
return;
ts = thread_stat_findnew(thread->pid);
seq = get_seq(ts, acquired_event->addr);
switch (seq->state) {
case SEQ_STATE_UNINITIALIZED:
return;
case SEQ_STATE_ACQUIRING:
break;
case SEQ_STATE_CONTENDED:
contended_term = timestamp - seq->prev_event_time;
ls->wait_time_total += contended_term;
if (contended_term < ls->wait_time_min)
ls->wait_time_min = contended_term;
if (ls->wait_time_max < contended_term)
ls->wait_time_max = contended_term;
break;
case SEQ_STATE_RELEASED:
case SEQ_STATE_ACQUIRED:
case SEQ_STATE_READ_ACQUIRED:
ls->discard = 1;
bad_hist[BROKEN_ACQUIRED]++;
list_del(&seq->list);
free(seq);
goto end;
break;
default:
BUG_ON("Unknown state of lock sequence found!\n");
break;
}
seq->state = SEQ_STATE_ACQUIRED;
ls->nr_acquired++;
seq->prev_event_time = timestamp;
end:
return;
}
static void
report_lock_contended_event(struct trace_contended_event *contended_event,
struct event *__event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct lock_stat *ls;
struct thread_stat *ts;
struct lock_seq_stat *seq;
ls = lock_stat_findnew(contended_event->addr, contended_event->name);
if (ls->discard)
return;
ts = thread_stat_findnew(thread->pid);
seq = get_seq(ts, contended_event->addr);
switch (seq->state) {
case SEQ_STATE_UNINITIALIZED:
return;
case SEQ_STATE_ACQUIRING:
break;
case SEQ_STATE_RELEASED:
case SEQ_STATE_ACQUIRED:
case SEQ_STATE_READ_ACQUIRED:
case SEQ_STATE_CONTENDED:
ls->discard = 1;
bad_hist[BROKEN_CONTENDED]++;
list_del(&seq->list);
free(seq);
goto end;
break;
default:
BUG_ON("Unknown state of lock sequence found!\n");
break;
}
seq->state = SEQ_STATE_CONTENDED;
ls->nr_contended++;
seq->prev_event_time = timestamp;
end:
return;
}
static void
report_lock_release_event(struct trace_release_event *release_event,
struct event *__event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct lock_stat *ls;
struct thread_stat *ts;
struct lock_seq_stat *seq;
ls = lock_stat_findnew(release_event->addr, release_event->name);
if (ls->discard)
return;
ts = thread_stat_findnew(thread->pid);
seq = get_seq(ts, release_event->addr);
switch (seq->state) {
case SEQ_STATE_UNINITIALIZED:
goto end;
break;
case SEQ_STATE_ACQUIRED:
break;
case SEQ_STATE_READ_ACQUIRED:
seq->read_count--;
BUG_ON(seq->read_count < 0);
if (!seq->read_count) {
ls->nr_release++;
goto end;
}
break;
case SEQ_STATE_ACQUIRING:
case SEQ_STATE_CONTENDED:
case SEQ_STATE_RELEASED:
ls->discard = 1;
bad_hist[BROKEN_RELEASE]++;
goto free_seq;
break;
default:
BUG_ON("Unknown state of lock sequence found!\n");
break;
}
ls->nr_release++;
free_seq:
list_del(&seq->list);
free(seq);
end:
return;
}
static void
process_lock_acquire_event(void *data,
struct event *event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct trace_acquire_event acquire_event;
u64 tmp;
tmp = raw_field_value(event, "lockdep_addr", data);
memcpy(&acquire_event.addr, &tmp, sizeof(void *));
acquire_event.name = (char *)raw_field_ptr(event, "name", data);
acquire_event.flag = (int)raw_field_value(event, "flag", data);
if (trace_handler->acquire_event)
trace_handler->acquire_event(&acquire_event, event, cpu, timestamp, thread);
}
static void
process_lock_acquired_event(void *data,
struct event *event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct trace_acquired_event acquired_event;
u64 tmp;
tmp = raw_field_value(event, "lockdep_addr", data);
memcpy(&acquired_event.addr, &tmp, sizeof(void *));
acquired_event.name = (char *)raw_field_ptr(event, "name", data);
if (trace_handler->acquire_event)
trace_handler->acquired_event(&acquired_event, event, cpu, timestamp, thread);
}
static void
process_lock_contended_event(void *data,
struct event *event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct trace_contended_event contended_event;
u64 tmp;
tmp = raw_field_value(event, "lockdep_addr", data);
memcpy(&contended_event.addr, &tmp, sizeof(void *));
contended_event.name = (char *)raw_field_ptr(event, "name", data);
if (trace_handler->acquire_event)
trace_handler->contended_event(&contended_event, event, cpu, timestamp, thread);
}
static void
process_lock_release_event(void *data,
struct event *event __used,
int cpu __used,
u64 timestamp __used,
struct thread *thread __used)
{
struct trace_release_event release_event;
u64 tmp;
tmp = raw_field_value(event, "lockdep_addr", data);
memcpy(&release_event.addr, &tmp, sizeof(void *));
release_event.name = (char *)raw_field_ptr(event, "name", data);
if (trace_handler->acquire_event)
trace_handler->release_event(&release_event, event, cpu, timestamp, thread);
}
static void
process_raw_event(void *data, int cpu, u64 timestamp, struct thread *thread)
{
struct event *event;
int type;
type = trace_parse_common_type(data);
event = trace_find_event(type);
if (!strcmp(event->name, "lock_acquire"))
process_lock_acquire_event(data, event, cpu, timestamp, thread);
if (!strcmp(event->name, "lock_acquired"))
process_lock_acquired_event(data, event, cpu, timestamp, thread);
if (!strcmp(event->name, "lock_contended"))
process_lock_contended_event(data, event, cpu, timestamp, thread);
if (!strcmp(event->name, "lock_release"))
process_lock_release_event(data, event, cpu, timestamp, thread);
}
static void print_bad_events(int bad, int total)
{
int i;
const char *name[4] =
{ "acquire", "acquired", "contended", "release" };
pr_info("\n=== output for debug===\n\n");
pr_info("bad: %d, total: %d\n", bad, total);
pr_info("bad rate: %f %%\n", (double)bad / (double)total * 100);
pr_info("histogram of events caused bad sequence\n");
for (i = 0; i < BROKEN_MAX; i++)
pr_info(" %10s: %d\n", name[i], bad_hist[i]);
}
static void print_result(void)
{
struct lock_stat *st;
char cut_name[20];
int bad, total;
pr_info("%20s ", "Name");
pr_info("%10s ", "acquired");
pr_info("%10s ", "contended");
pr_info("%15s ", "total wait (ns)");
pr_info("%15s ", "max wait (ns)");
pr_info("%15s ", "min wait (ns)");
pr_info("\n\n");
bad = total = 0;
while ((st = pop_from_result())) {
total++;
if (st->discard) {
bad++;
continue;
}
bzero(cut_name, 20);
if (strlen(st->name) < 16) {
pr_info("%20s ", st->name);
} else {
strncpy(cut_name, st->name, 16);
cut_name[16] = '.';
cut_name[17] = '.';
cut_name[18] = '.';
cut_name[19] = '\0';
pr_info("%20s ", cut_name);
}
pr_info("%10u ", st->nr_acquired);
pr_info("%10u ", st->nr_contended);
pr_info("%15" PRIu64 " ", st->wait_time_total);
pr_info("%15" PRIu64 " ", st->wait_time_max);
pr_info("%15" PRIu64 " ", st->wait_time_min == ULLONG_MAX ?
0 : st->wait_time_min);
pr_info("\n");
}
print_bad_events(bad, total);
}
static void dump_threads(void)
{
struct thread_stat *st;
struct rb_node *node;
struct thread *t;
pr_info("%10s: comm\n", "Thread ID");
node = rb_first(&thread_stats);
while (node) {
st = container_of(node, struct thread_stat, rb);
t = perf_session__findnew(session, st->tid);
pr_info("%10d: %s\n", st->tid, t->comm);
node = rb_next(node);
};
}
static void dump_map(void)
{
unsigned int i;
struct lock_stat *st;
pr_info("Address of instance: name of class\n");
for (i = 0; i < LOCKHASH_SIZE; i++) {
list_for_each_entry(st, &lockhash_table[i], hash_entry) {
pr_info(" %p: %s\n", st->addr, st->name);
}
}
}
static void dump_info(void)
{
if (info_threads)
dump_threads();
else if (info_map)
dump_map();
else
die("Unknown type of information\n");
}
static int process_sample_event(struct perf_tool *tool __used,
union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel __used,
struct machine *machine)
{
struct thread *thread = machine__findnew_thread(machine, sample->tid);
if (thread == NULL) {
pr_debug("problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
process_raw_event(sample->raw_data, sample->cpu, sample->time, thread);
return 0;
}
static int read_events(void)
{
session = perf_session__new(input_name, O_RDONLY, 0, false, &eops);
if (!session)
die("Initializing perf session failed\n");
return perf_session__process_events(session, &eops);
}
static void sort_result(void)
{
unsigned int i;
struct lock_stat *st;
for (i = 0; i < LOCKHASH_SIZE; i++) {
list_for_each_entry(st, &lockhash_table[i], hash_entry) {
insert_to_result(st, compare);
}
}
}
static void __cmd_report(void)
{
setup_pager();
select_key();
read_events();
sort_result();
print_result();
}
static int __cmd_record(int argc, const char **argv)
{
unsigned int rec_argc, i, j;
const char **rec_argv;
rec_argc = ARRAY_SIZE(record_args) + argc - 1;
rec_argv = calloc(rec_argc + 1, sizeof(char *));
if (rec_argv == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(record_args); i++)
rec_argv[i] = strdup(record_args[i]);
for (j = 1; j < (unsigned int)argc; j++, i++)
rec_argv[i] = argv[j];
BUG_ON(i != rec_argc);
return cmd_record(i, rec_argv, NULL);
}
int cmd_lock(int argc, const char **argv, const char *prefix __used)
{
unsigned int i;
symbol__init();
for (i = 0; i < LOCKHASH_SIZE; i++)
INIT_LIST_HEAD(lockhash_table + i);
argc = parse_options(argc, argv, lock_options, lock_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc)
usage_with_options(lock_usage, lock_options);
if (!strncmp(argv[0], "rec", 3)) {
return __cmd_record(argc, argv);
} else if (!strncmp(argv[0], "report", 6)) {
trace_handler = &report_lock_ops;
if (argc) {
argc = parse_options(argc, argv,
report_options, report_usage, 0);
if (argc)
usage_with_options(report_usage, report_options);
}
__cmd_report();
} else if (!strcmp(argv[0], "script")) {
return cmd_script(argc, argv, prefix);
} else if (!strcmp(argv[0], "info")) {
if (argc) {
argc = parse_options(argc, argv,
info_options, info_usage, 0);
if (argc)
usage_with_options(info_usage, info_options);
}
trace_handler = &report_lock_ops;
setup_pager();
read_events();
dump_info();
} else {
usage_with_options(lock_usage, lock_options);
}
return 0;
}
