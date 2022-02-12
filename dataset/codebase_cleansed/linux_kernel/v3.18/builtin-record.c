static int record__write(struct record *rec, void *bf, size_t size)
{
if (perf_data_file__write(rec->session->file, bf, size) < 0) {
pr_err("failed to write perf data, error: %m\n");
return -1;
}
rec->bytes_written += size;
return 0;
}
static int process_synthesized_event(struct perf_tool *tool,
union perf_event *event,
struct perf_sample *sample __maybe_unused,
struct machine *machine __maybe_unused)
{
struct record *rec = container_of(tool, struct record, tool);
return record__write(rec, event, event->header.size);
}
static int record__mmap_read(struct record *rec, int idx)
{
struct perf_mmap *md = &rec->evlist->mmap[idx];
unsigned int head = perf_mmap__read_head(md);
unsigned int old = md->prev;
unsigned char *data = md->base + page_size;
unsigned long size;
void *buf;
int rc = 0;
if (old == head)
return 0;
rec->samples++;
size = head - old;
if ((old & md->mask) + size != (head & md->mask)) {
buf = &data[old & md->mask];
size = md->mask + 1 - (old & md->mask);
old += size;
if (record__write(rec, buf, size) < 0) {
rc = -1;
goto out;
}
}
buf = &data[old & md->mask];
size = head - old;
old += size;
if (record__write(rec, buf, size) < 0) {
rc = -1;
goto out;
}
md->prev = old;
perf_evlist__mmap_consume(rec->evlist, idx);
out:
return rc;
}
static void sig_handler(int sig)
{
if (sig == SIGCHLD)
child_finished = 1;
else
signr = sig;
done = 1;
}
static void record__sig_exit(void)
{
if (signr == -1)
return;
signal(signr, SIG_DFL);
raise(signr);
}
static int record__open(struct record *rec)
{
char msg[512];
struct perf_evsel *pos;
struct perf_evlist *evlist = rec->evlist;
struct perf_session *session = rec->session;
struct record_opts *opts = &rec->opts;
int rc = 0;
perf_evlist__config(evlist, opts);
evlist__for_each(evlist, pos) {
try_again:
if (perf_evsel__open(pos, evlist->cpus, evlist->threads) < 0) {
if (perf_evsel__fallback(pos, errno, msg, sizeof(msg))) {
if (verbose)
ui__warning("%s\n", msg);
goto try_again;
}
rc = -errno;
perf_evsel__open_strerror(pos, &opts->target,
errno, msg, sizeof(msg));
ui__error("%s\n", msg);
goto out;
}
}
if (perf_evlist__apply_filters(evlist)) {
error("failed to set filter with %d (%s)\n", errno,
strerror_r(errno, msg, sizeof(msg)));
rc = -1;
goto out;
}
if (perf_evlist__mmap(evlist, opts->mmap_pages, false) < 0) {
if (errno == EPERM) {
pr_err("Permission error mapping pages.\n"
"Consider increasing "
"/proc/sys/kernel/perf_event_mlock_kb,\n"
"or try again with a smaller value of -m/--mmap_pages.\n"
"(current value: %u)\n", opts->mmap_pages);
rc = -errno;
} else {
pr_err("failed to mmap with %d (%s)\n", errno,
strerror_r(errno, msg, sizeof(msg)));
rc = -errno;
}
goto out;
}
session->evlist = evlist;
perf_session__set_id_hdr_size(session);
out:
return rc;
}
static int process_buildids(struct record *rec)
{
struct perf_data_file *file = &rec->file;
struct perf_session *session = rec->session;
u64 start = session->header.data_offset;
u64 size = lseek(file->fd, 0, SEEK_CUR);
if (size == 0)
return 0;
return __perf_session__process_events(session, start,
size - start,
size, &build_id__mark_dso_hit_ops);
}
static void perf_event__synthesize_guest_os(struct machine *machine, void *data)
{
int err;
struct perf_tool *tool = data;
err = perf_event__synthesize_modules(tool, process_synthesized_event,
machine);
if (err < 0)
pr_err("Couldn't record guest kernel [%d]'s reference"
" relocation symbol.\n", machine->pid);
err = perf_event__synthesize_kernel_mmap(tool, process_synthesized_event,
machine);
if (err < 0)
pr_err("Couldn't record guest kernel [%d]'s reference"
" relocation symbol.\n", machine->pid);
}
static int record__mmap_read_all(struct record *rec)
{
u64 bytes_written = rec->bytes_written;
int i;
int rc = 0;
for (i = 0; i < rec->evlist->nr_mmaps; i++) {
if (rec->evlist->mmap[i].base) {
if (record__mmap_read(rec, i) != 0) {
rc = -1;
goto out;
}
}
}
if (bytes_written != rec->bytes_written)
rc = record__write(rec, &finished_round_event, sizeof(finished_round_event));
out:
return rc;
}
static void record__init_features(struct record *rec)
{
struct perf_session *session = rec->session;
int feat;
for (feat = HEADER_FIRST_FEATURE; feat < HEADER_LAST_FEATURE; feat++)
perf_header__set_feat(&session->header, feat);
if (rec->no_buildid)
perf_header__clear_feat(&session->header, HEADER_BUILD_ID);
if (!have_tracepoints(&rec->evlist->entries))
perf_header__clear_feat(&session->header, HEADER_TRACING_DATA);
if (!rec->opts.branch_stack)
perf_header__clear_feat(&session->header, HEADER_BRANCH_STACK);
}
static void workload_exec_failed_signal(int signo __maybe_unused,
siginfo_t *info,
void *ucontext __maybe_unused)
{
workload_exec_errno = info->si_value.sival_int;
done = 1;
child_finished = 1;
}
static int __cmd_record(struct record *rec, int argc, const char **argv)
{
int err;
int status = 0;
unsigned long waking = 0;
const bool forks = argc > 0;
struct machine *machine;
struct perf_tool *tool = &rec->tool;
struct record_opts *opts = &rec->opts;
struct perf_data_file *file = &rec->file;
struct perf_session *session;
bool disabled = false, draining = false;
rec->progname = argv[0];
atexit(record__sig_exit);
signal(SIGCHLD, sig_handler);
signal(SIGINT, sig_handler);
signal(SIGTERM, sig_handler);
session = perf_session__new(file, false, NULL);
if (session == NULL) {
pr_err("Perf session creation failed.\n");
return -1;
}
rec->session = session;
record__init_features(rec);
if (forks) {
err = perf_evlist__prepare_workload(rec->evlist, &opts->target,
argv, file->is_pipe,
workload_exec_failed_signal);
if (err < 0) {
pr_err("Couldn't run the workload!\n");
status = err;
goto out_delete_session;
}
}
if (record__open(rec) != 0) {
err = -1;
goto out_child;
}
if (!rec->evlist->nr_groups)
perf_header__clear_feat(&session->header, HEADER_GROUP_DESC);
if (file->is_pipe) {
err = perf_header__write_pipe(file->fd);
if (err < 0)
goto out_child;
} else {
err = perf_session__write_header(session, rec->evlist,
file->fd, false);
if (err < 0)
goto out_child;
}
if (!rec->no_buildid
&& !perf_header__has_feat(&session->header, HEADER_BUILD_ID)) {
pr_err("Couldn't generate buildids. "
"Use --no-buildid to profile anyway.\n");
err = -1;
goto out_child;
}
machine = &session->machines.host;
if (file->is_pipe) {
err = perf_event__synthesize_attrs(tool, session,
process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize attrs.\n");
goto out_child;
}
if (have_tracepoints(&rec->evlist->entries)) {
err = perf_event__synthesize_tracing_data(tool, file->fd, rec->evlist,
process_synthesized_event);
if (err <= 0) {
pr_err("Couldn't record tracing data.\n");
goto out_child;
}
rec->bytes_written += err;
}
}
err = perf_event__synthesize_kernel_mmap(tool, process_synthesized_event,
machine);
if (err < 0)
pr_err("Couldn't record kernel reference relocation symbol\n"
"Symbol resolution may be skewed if relocation was used (e.g. kexec).\n"
"Check /proc/kallsyms permission or run as root.\n");
err = perf_event__synthesize_modules(tool, process_synthesized_event,
machine);
if (err < 0)
pr_err("Couldn't record kernel module information.\n"
"Symbol resolution may be skewed if relocation was used (e.g. kexec).\n"
"Check /proc/modules permission or run as root.\n");
if (perf_guest) {
machines__process_guests(&session->machines,
perf_event__synthesize_guest_os, tool);
}
err = __machine__synthesize_threads(machine, tool, &opts->target, rec->evlist->threads,
process_synthesized_event, opts->sample_address);
if (err != 0)
goto out_child;
if (rec->realtime_prio) {
struct sched_param param;
param.sched_priority = rec->realtime_prio;
if (sched_setscheduler(0, SCHED_FIFO, &param)) {
pr_err("Could not set realtime priority.\n");
err = -1;
goto out_child;
}
}
if (!target__none(&opts->target) && !opts->initial_delay)
perf_evlist__enable(rec->evlist);
if (forks)
perf_evlist__start_workload(rec->evlist);
if (opts->initial_delay) {
usleep(opts->initial_delay * 1000);
perf_evlist__enable(rec->evlist);
}
for (;;) {
int hits = rec->samples;
if (record__mmap_read_all(rec) < 0) {
err = -1;
goto out_child;
}
if (hits == rec->samples) {
if (done || draining)
break;
err = perf_evlist__poll(rec->evlist, -1);
if (err > 0 || (err < 0 && errno == EINTR))
err = 0;
waking++;
if (perf_evlist__filter_pollfd(rec->evlist, POLLERR | POLLHUP) == 0)
draining = true;
}
if (done && !disabled && !target__none(&opts->target)) {
perf_evlist__disable(rec->evlist);
disabled = true;
}
}
if (forks && workload_exec_errno) {
char msg[STRERR_BUFSIZE];
const char *emsg = strerror_r(workload_exec_errno, msg, sizeof(msg));
pr_err("Workload failed: %s\n", emsg);
err = -1;
goto out_child;
}
if (!quiet) {
fprintf(stderr, "[ perf record: Woken up %ld times to write data ]\n", waking);
fprintf(stderr,
"[ perf record: Captured and wrote %.3f MB %s (~%" PRIu64 " samples) ]\n",
(double)rec->bytes_written / 1024.0 / 1024.0,
file->path,
rec->bytes_written / 24);
}
out_child:
if (forks) {
int exit_status;
if (!child_finished)
kill(rec->evlist->workload.pid, SIGTERM);
wait(&exit_status);
if (err < 0)
status = err;
else if (WIFEXITED(exit_status))
status = WEXITSTATUS(exit_status);
else if (WIFSIGNALED(exit_status))
signr = WTERMSIG(exit_status);
} else
status = err;
if (!err && !file->is_pipe) {
rec->session->header.data_size += rec->bytes_written;
if (!rec->no_buildid)
process_buildids(rec);
perf_session__write_header(rec->session, rec->evlist,
file->fd, true);
}
out_delete_session:
perf_session__delete(session);
return status;
}
static int
parse_branch_stack(const struct option *opt, const char *str, int unset)
{
#define ONLY_PLM \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
uint64_t *mode = (uint64_t *)opt->value;
const struct branch_mode *br;
char *s, *os = NULL, *p;
int ret = -1;
if (unset)
return 0;
if (*mode)
return -1;
if (str) {
s = os = strdup(str);
if (!s)
return -1;
for (;;) {
p = strchr(s, ',');
if (p)
*p = '\0';
for (br = branch_modes; br->name; br++) {
if (!strcasecmp(s, br->name))
break;
}
if (!br->name) {
ui__warning("unknown branch filter %s,"
" check man page\n", s);
goto error;
}
*mode |= br->mode;
if (!p)
break;
s = p + 1;
}
}
ret = 0;
if ((*mode & ~ONLY_PLM) == 0) {
*mode = PERF_SAMPLE_BRANCH_ANY;
}
error:
free(os);
return ret;
}
static void callchain_debug(void)
{
static const char *str[CALLCHAIN_MAX] = { "NONE", "FP", "DWARF" };
pr_debug("callchain: type %s\n", str[callchain_param.record_mode]);
if (callchain_param.record_mode == CALLCHAIN_DWARF)
pr_debug("callchain: stack dump size %d\n",
callchain_param.dump_size);
}
int record_parse_callchain_opt(const struct option *opt __maybe_unused,
const char *arg,
int unset)
{
int ret;
callchain_param.enabled = !unset;
if (unset) {
callchain_param.record_mode = CALLCHAIN_NONE;
pr_debug("callchain: disabled\n");
return 0;
}
ret = parse_callchain_record_opt(arg);
if (!ret)
callchain_debug();
return ret;
}
int record_callchain_opt(const struct option *opt __maybe_unused,
const char *arg __maybe_unused,
int unset __maybe_unused)
{
callchain_param.enabled = true;
if (callchain_param.record_mode == CALLCHAIN_NONE)
callchain_param.record_mode = CALLCHAIN_FP;
callchain_debug();
return 0;
}
static int perf_record_config(const char *var, const char *value, void *cb)
{
if (!strcmp(var, "record.call-graph"))
var = "call-graph.record-mode";
return perf_default_config(var, value, cb);
}
int cmd_record(int argc, const char **argv, const char *prefix __maybe_unused)
{
int err = -ENOMEM;
struct record *rec = &record;
char errbuf[BUFSIZ];
rec->evlist = perf_evlist__new();
if (rec->evlist == NULL)
return -ENOMEM;
perf_config(perf_record_config, rec);
argc = parse_options(argc, argv, record_options, record_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc && target__none(&rec->opts.target))
usage_with_options(record_usage, record_options);
if (nr_cgroups && !rec->opts.target.system_wide) {
ui__error("cgroup monitoring only available in"
" system-wide mode\n");
usage_with_options(record_usage, record_options);
}
symbol__init(NULL);
if (symbol_conf.kptr_restrict)
pr_warning(
"WARNING: Kernel address maps (/proc/{kallsyms,modules}) are restricted,\n"
"check /proc/sys/kernel/kptr_restrict.\n\n"
"Samples in kernel functions may not be resolved if a suitable vmlinux\n"
"file is not found in the buildid cache or in the vmlinux path.\n\n"
"Samples in kernel modules won't be resolved at all.\n\n"
"If some relocation was applied (e.g. kexec) symbols may be misresolved\n"
"even with a suitable vmlinux or kallsyms file.\n\n");
if (rec->no_buildid_cache || rec->no_buildid)
disable_buildid_cache();
if (rec->evlist->nr_entries == 0 &&
perf_evlist__add_default(rec->evlist) < 0) {
pr_err("Not enough memory for event selector list\n");
goto out_symbol_exit;
}
if (rec->opts.target.tid && !rec->opts.no_inherit_set)
rec->opts.no_inherit = true;
err = target__validate(&rec->opts.target);
if (err) {
target__strerror(&rec->opts.target, err, errbuf, BUFSIZ);
ui__warning("%s", errbuf);
}
err = target__parse_uid(&rec->opts.target);
if (err) {
int saved_errno = errno;
target__strerror(&rec->opts.target, err, errbuf, BUFSIZ);
ui__error("%s", errbuf);
err = -saved_errno;
goto out_symbol_exit;
}
err = -ENOMEM;
if (perf_evlist__create_maps(rec->evlist, &rec->opts.target) < 0)
usage_with_options(record_usage, record_options);
if (record_opts__config(&rec->opts)) {
err = -EINVAL;
goto out_symbol_exit;
}
err = __cmd_record(&record, argc, argv);
out_symbol_exit:
perf_evlist__delete(rec->evlist);
symbol__exit();
return err;
}
