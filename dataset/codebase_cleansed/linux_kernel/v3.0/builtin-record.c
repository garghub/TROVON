static void advance_output(size_t size)
{
bytes_written += size;
}
static void write_output(void *buf, size_t size)
{
while (size) {
int ret = write(output, buf, size);
if (ret < 0)
die("failed to write");
size -= ret;
buf += ret;
bytes_written += ret;
}
}
static int process_synthesized_event(union perf_event *event,
struct perf_sample *sample __used,
struct perf_session *self __used)
{
write_output(event, event->header.size);
return 0;
}
static void mmap_read(struct perf_mmap *md)
{
unsigned int head = perf_mmap__read_head(md);
unsigned int old = md->prev;
unsigned char *data = md->base + page_size;
unsigned long size;
void *buf;
if (old == head)
return;
samples++;
size = head - old;
if ((old & md->mask) + size != (head & md->mask)) {
buf = &data[old & md->mask];
size = md->mask + 1 - (old & md->mask);
old += size;
write_output(buf, size);
}
buf = &data[old & md->mask];
size = head - old;
old += size;
write_output(buf, size);
md->prev = old;
perf_mmap__write_tail(md, old);
}
static void sig_handler(int sig)
{
done = 1;
signr = sig;
}
static void sig_atexit(void)
{
if (child_pid > 0)
kill(child_pid, SIGTERM);
if (signr == -1 || signr == SIGUSR1)
return;
signal(signr, SIG_DFL);
kill(getpid(), signr);
}
static void config_attr(struct perf_evsel *evsel, struct perf_evlist *evlist)
{
struct perf_event_attr *attr = &evsel->attr;
int track = !evsel->idx;
attr->inherit = !no_inherit;
attr->read_format = PERF_FORMAT_TOTAL_TIME_ENABLED |
PERF_FORMAT_TOTAL_TIME_RUNNING |
PERF_FORMAT_ID;
attr->sample_type |= PERF_SAMPLE_IP | PERF_SAMPLE_TID;
if (evlist->nr_entries > 1)
attr->sample_type |= PERF_SAMPLE_ID;
if (!attr->sample_period || (user_freq != UINT_MAX &&
user_interval != ULLONG_MAX)) {
if (freq) {
attr->sample_type |= PERF_SAMPLE_PERIOD;
attr->freq = 1;
attr->sample_freq = freq;
} else {
attr->sample_period = default_interval;
}
}
if (no_samples)
attr->sample_freq = 0;
if (inherit_stat)
attr->inherit_stat = 1;
if (sample_address) {
attr->sample_type |= PERF_SAMPLE_ADDR;
attr->mmap_data = track;
}
if (call_graph)
attr->sample_type |= PERF_SAMPLE_CALLCHAIN;
if (system_wide)
attr->sample_type |= PERF_SAMPLE_CPU;
if (sample_id_all_avail &&
(sample_time || system_wide || !no_inherit || cpu_list))
attr->sample_type |= PERF_SAMPLE_TIME;
if (raw_samples) {
attr->sample_type |= PERF_SAMPLE_TIME;
attr->sample_type |= PERF_SAMPLE_RAW;
attr->sample_type |= PERF_SAMPLE_CPU;
}
if (nodelay) {
attr->watermark = 0;
attr->wakeup_events = 1;
}
attr->mmap = track;
attr->comm = track;
if (target_pid == -1 && target_tid == -1 && !system_wide) {
attr->disabled = 1;
attr->enable_on_exec = 1;
}
}
static bool perf_evlist__equal(struct perf_evlist *evlist,
struct perf_evlist *other)
{
struct perf_evsel *pos, *pair;
if (evlist->nr_entries != other->nr_entries)
return false;
pair = list_entry(other->entries.next, struct perf_evsel, node);
list_for_each_entry(pos, &evlist->entries, node) {
if (memcmp(&pos->attr, &pair->attr, sizeof(pos->attr) != 0))
return false;
pair = list_entry(pair->node.next, struct perf_evsel, node);
}
return true;
}
static void open_counters(struct perf_evlist *evlist)
{
struct perf_evsel *pos;
if (evlist->cpus->map[0] < 0)
no_inherit = true;
list_for_each_entry(pos, &evlist->entries, node) {
struct perf_event_attr *attr = &pos->attr;
bool time_needed = attr->sample_type & PERF_SAMPLE_TIME;
config_attr(pos, evlist);
retry_sample_id:
attr->sample_id_all = sample_id_all_avail ? 1 : 0;
try_again:
if (perf_evsel__open(pos, evlist->cpus, evlist->threads, group) < 0) {
int err = errno;
if (err == EPERM || err == EACCES) {
ui__warning_paranoid();
exit(EXIT_FAILURE);
} else if (err == ENODEV && cpu_list) {
die("No such device - did you specify"
" an out-of-range profile CPU?\n");
} else if (err == EINVAL && sample_id_all_avail) {
sample_id_all_avail = false;
if (!sample_time && !raw_samples && !time_needed)
attr->sample_type &= ~PERF_SAMPLE_TIME;
goto retry_sample_id;
}
if (attr->type == PERF_TYPE_HARDWARE
&& attr->config == PERF_COUNT_HW_CPU_CYCLES) {
if (verbose)
ui__warning("The cycles event is not supported, "
"trying to fall back to cpu-clock-ticks\n");
attr->type = PERF_TYPE_SOFTWARE;
attr->config = PERF_COUNT_SW_CPU_CLOCK;
goto try_again;
}
if (err == ENOENT) {
ui__warning("The %s event is not supported.\n",
event_name(pos));
exit(EXIT_FAILURE);
}
printf("\n");
error("sys_perf_event_open() syscall returned with %d (%s). /bin/dmesg may provide additional information.\n",
err, strerror(err));
#if defined(__i386__) || defined(__x86_64__)
if (attr->type == PERF_TYPE_HARDWARE && err == EOPNOTSUPP)
die("No hardware sampling interrupt available."
" No APIC? If so then you can boot the kernel"
" with the \"lapic\" boot parameter to"
" force-enable it.\n");
#endif
die("No CONFIG_PERF_EVENTS=y kernel support configured?\n");
}
}
if (perf_evlist__set_filters(evlist)) {
error("failed to set filter with %d (%s)\n", errno,
strerror(errno));
exit(-1);
}
if (perf_evlist__mmap(evlist, mmap_pages, false) < 0)
die("failed to mmap with %d (%s)\n", errno, strerror(errno));
if (file_new)
session->evlist = evlist;
else {
if (!perf_evlist__equal(session->evlist, evlist)) {
fprintf(stderr, "incompatible append\n");
exit(-1);
}
}
perf_session__update_sample_type(session);
}
static int process_buildids(void)
{
u64 size = lseek(output, 0, SEEK_CUR);
if (size == 0)
return 0;
session->fd = output;
return __perf_session__process_events(session, post_processing_offset,
size - post_processing_offset,
size, &build_id__mark_dso_hit_ops);
}
static void atexit_header(void)
{
if (!pipe_output) {
session->header.data_size += bytes_written;
if (!no_buildid)
process_buildids();
perf_session__write_header(session, evsel_list, output, true);
perf_session__delete(session);
perf_evlist__delete(evsel_list);
symbol__exit();
}
}
static void perf_event__synthesize_guest_os(struct machine *machine, void *data)
{
int err;
struct perf_session *psession = data;
if (machine__is_host(machine))
return;
err = perf_event__synthesize_modules(process_synthesized_event,
psession, machine);
if (err < 0)
pr_err("Couldn't record guest kernel [%d]'s reference"
" relocation symbol.\n", machine->pid);
err = perf_event__synthesize_kernel_mmap(process_synthesized_event,
psession, machine, "_text");
if (err < 0)
err = perf_event__synthesize_kernel_mmap(process_synthesized_event,
psession, machine,
"_stext");
if (err < 0)
pr_err("Couldn't record guest kernel [%d]'s reference"
" relocation symbol.\n", machine->pid);
}
static void mmap_read_all(void)
{
int i;
for (i = 0; i < evsel_list->nr_mmaps; i++) {
if (evsel_list->mmap[i].base)
mmap_read(&evsel_list->mmap[i]);
}
if (perf_header__has_feat(&session->header, HEADER_TRACE_INFO))
write_output(&finished_round_event, sizeof(finished_round_event));
}
static int __cmd_record(int argc, const char **argv)
{
int i;
struct stat st;
int flags;
int err;
unsigned long waking = 0;
int child_ready_pipe[2], go_pipe[2];
const bool forks = argc > 0;
char buf;
struct machine *machine;
page_size = sysconf(_SC_PAGE_SIZE);
atexit(sig_atexit);
signal(SIGCHLD, sig_handler);
signal(SIGINT, sig_handler);
signal(SIGUSR1, sig_handler);
if (forks && (pipe(child_ready_pipe) < 0 || pipe(go_pipe) < 0)) {
perror("failed to create pipes");
exit(-1);
}
if (!output_name) {
if (!fstat(STDOUT_FILENO, &st) && S_ISFIFO(st.st_mode))
pipe_output = 1;
else
output_name = "perf.data";
}
if (output_name) {
if (!strcmp(output_name, "-"))
pipe_output = 1;
else if (!stat(output_name, &st) && st.st_size) {
if (write_mode == WRITE_FORCE) {
char oldname[PATH_MAX];
snprintf(oldname, sizeof(oldname), "%s.old",
output_name);
unlink(oldname);
rename(output_name, oldname);
}
} else if (write_mode == WRITE_APPEND) {
write_mode = WRITE_FORCE;
}
}
flags = O_CREAT|O_RDWR;
if (write_mode == WRITE_APPEND)
file_new = 0;
else
flags |= O_TRUNC;
if (pipe_output)
output = STDOUT_FILENO;
else
output = open(output_name, flags, S_IRUSR | S_IWUSR);
if (output < 0) {
perror("failed to create output file");
exit(-1);
}
session = perf_session__new(output_name, O_WRONLY,
write_mode == WRITE_FORCE, false, NULL);
if (session == NULL) {
pr_err("Not enough memory for reading perf file header\n");
return -1;
}
if (!no_buildid)
perf_header__set_feat(&session->header, HEADER_BUILD_ID);
if (!file_new) {
err = perf_session__read_header(session, output);
if (err < 0)
goto out_delete_session;
}
if (have_tracepoints(&evsel_list->entries))
perf_header__set_feat(&session->header, HEADER_TRACE_INFO);
if (mmap_pages == UINT_MAX)
mmap_pages = (512 * 1024) / page_size;
if (forks) {
child_pid = fork();
if (child_pid < 0) {
perror("failed to fork");
exit(-1);
}
if (!child_pid) {
if (pipe_output)
dup2(2, 1);
close(child_ready_pipe[0]);
close(go_pipe[1]);
fcntl(go_pipe[0], F_SETFD, FD_CLOEXEC);
execvp("", (char **)argv);
close(child_ready_pipe[1]);
if (read(go_pipe[0], &buf, 1) == -1)
perror("unable to read pipe");
execvp(argv[0], (char **)argv);
perror(argv[0]);
kill(getppid(), SIGUSR1);
exit(-1);
}
if (!system_wide && target_tid == -1 && target_pid == -1)
evsel_list->threads->map[0] = child_pid;
close(child_ready_pipe[1]);
close(go_pipe[0]);
if (read(child_ready_pipe[0], &buf, 1) == -1) {
perror("unable to read pipe");
exit(-1);
}
close(child_ready_pipe[0]);
}
open_counters(evsel_list);
atexit(atexit_header);
if (pipe_output) {
err = perf_header__write_pipe(output);
if (err < 0)
return err;
} else if (file_new) {
err = perf_session__write_header(session, evsel_list,
output, false);
if (err < 0)
return err;
}
post_processing_offset = lseek(output, 0, SEEK_CUR);
if (pipe_output) {
err = perf_session__synthesize_attrs(session,
process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize attrs.\n");
return err;
}
err = perf_event__synthesize_event_types(process_synthesized_event,
session);
if (err < 0) {
pr_err("Couldn't synthesize event_types.\n");
return err;
}
if (have_tracepoints(&evsel_list->entries)) {
err = perf_event__synthesize_tracing_data(output, evsel_list,
process_synthesized_event,
session);
if (err <= 0) {
pr_err("Couldn't record tracing data.\n");
return err;
}
advance_output(err);
}
}
machine = perf_session__find_host_machine(session);
if (!machine) {
pr_err("Couldn't find native kernel information.\n");
return -1;
}
err = perf_event__synthesize_kernel_mmap(process_synthesized_event,
session, machine, "_text");
if (err < 0)
err = perf_event__synthesize_kernel_mmap(process_synthesized_event,
session, machine, "_stext");
if (err < 0)
pr_err("Couldn't record kernel reference relocation symbol\n"
"Symbol resolution may be skewed if relocation was used (e.g. kexec).\n"
"Check /proc/kallsyms permission or run as root.\n");
err = perf_event__synthesize_modules(process_synthesized_event,
session, machine);
if (err < 0)
pr_err("Couldn't record kernel module information.\n"
"Symbol resolution may be skewed if relocation was used (e.g. kexec).\n"
"Check /proc/modules permission or run as root.\n");
if (perf_guest)
perf_session__process_machines(session,
perf_event__synthesize_guest_os);
if (!system_wide)
perf_event__synthesize_thread_map(evsel_list->threads,
process_synthesized_event,
session);
else
perf_event__synthesize_threads(process_synthesized_event,
session);
if (realtime_prio) {
struct sched_param param;
param.sched_priority = realtime_prio;
if (sched_setscheduler(0, SCHED_FIFO, &param)) {
pr_err("Could not set realtime priority.\n");
exit(-1);
}
}
if (forks)
close(go_pipe[1]);
for (;;) {
int hits = samples;
int thread;
mmap_read_all();
if (hits == samples) {
if (done)
break;
err = poll(evsel_list->pollfd, evsel_list->nr_fds, -1);
waking++;
}
if (done) {
for (i = 0; i < evsel_list->cpus->nr; i++) {
struct perf_evsel *pos;
list_for_each_entry(pos, &evsel_list->entries, node) {
for (thread = 0;
thread < evsel_list->threads->nr;
thread++)
ioctl(FD(pos, i, thread),
PERF_EVENT_IOC_DISABLE);
}
}
}
}
if (quiet || signr == SIGUSR1)
return 0;
fprintf(stderr, "[ perf record: Woken up %ld times to write data ]\n", waking);
fprintf(stderr,
"[ perf record: Captured and wrote %.3f MB %s (~%" PRIu64 " samples) ]\n",
(double)bytes_written / 1024.0 / 1024.0,
output_name,
bytes_written / 24);
return 0;
out_delete_session:
perf_session__delete(session);
return err;
}
int cmd_record(int argc, const char **argv, const char *prefix __used)
{
int err = -ENOMEM;
struct perf_evsel *pos;
evsel_list = perf_evlist__new(NULL, NULL);
if (evsel_list == NULL)
return -ENOMEM;
argc = parse_options(argc, argv, record_options, record_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc && target_pid == -1 && target_tid == -1 &&
!system_wide && !cpu_list)
usage_with_options(record_usage, record_options);
if (force && append_file) {
fprintf(stderr, "Can't overwrite and append at the same time."
" You need to choose between -f and -A");
usage_with_options(record_usage, record_options);
} else if (append_file) {
write_mode = WRITE_APPEND;
} else {
write_mode = WRITE_FORCE;
}
if (nr_cgroups && !system_wide) {
fprintf(stderr, "cgroup monitoring only available in"
" system-wide mode\n");
usage_with_options(record_usage, record_options);
}
symbol__init();
if (symbol_conf.kptr_restrict)
pr_warning(
"WARNING: Kernel address maps (/proc/{kallsyms,modules}) are restricted,\n"
"check /proc/sys/kernel/kptr_restrict.\n\n"
"Samples in kernel functions may not be resolved if a suitable vmlinux\n"
"file is not found in the buildid cache or in the vmlinux path.\n\n"
"Samples in kernel modules won't be resolved at all.\n\n"
"If some relocation was applied (e.g. kexec) symbols may be misresolved\n"
"even with a suitable vmlinux or kallsyms file.\n\n");
if (no_buildid_cache || no_buildid)
disable_buildid_cache();
if (evsel_list->nr_entries == 0 &&
perf_evlist__add_default(evsel_list) < 0) {
pr_err("Not enough memory for event selector list\n");
goto out_symbol_exit;
}
if (target_pid != -1)
target_tid = target_pid;
if (perf_evlist__create_maps(evsel_list, target_pid,
target_tid, cpu_list) < 0)
usage_with_options(record_usage, record_options);
list_for_each_entry(pos, &evsel_list->entries, node) {
if (perf_evsel__alloc_fd(pos, evsel_list->cpus->nr,
evsel_list->threads->nr) < 0)
goto out_free_fd;
if (perf_header__push_event(pos->attr.config, event_name(pos)))
goto out_free_fd;
}
if (perf_evlist__alloc_pollfd(evsel_list) < 0)
goto out_free_fd;
if (user_interval != ULLONG_MAX)
default_interval = user_interval;
if (user_freq != UINT_MAX)
freq = user_freq;
if (default_interval)
freq = 0;
else if (freq) {
default_interval = freq;
} else {
fprintf(stderr, "frequency and count are zero, aborting\n");
err = -EINVAL;
goto out_free_fd;
}
err = __cmd_record(argc, argv);
out_free_fd:
perf_evlist__delete_maps(evsel_list);
out_symbol_exit:
symbol__exit();
return err;
}
