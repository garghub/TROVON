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
u64 head = perf_mmap__read_head(md);
u64 old = md->prev;
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
static int record__process_auxtrace(struct perf_tool *tool,
union perf_event *event, void *data1,
size_t len1, void *data2, size_t len2)
{
struct record *rec = container_of(tool, struct record, tool);
struct perf_data_file *file = &rec->file;
size_t padding;
u8 pad[8] = {0};
if (!perf_data_file__is_pipe(file)) {
off_t file_offset;
int fd = perf_data_file__fd(file);
int err;
file_offset = lseek(fd, 0, SEEK_CUR);
if (file_offset == -1)
return -1;
err = auxtrace_index__auxtrace_event(&rec->session->auxtrace_index,
event, file_offset);
if (err)
return err;
}
padding = (len1 + len2) & 7;
if (padding)
padding = 8 - padding;
record__write(rec, event, event->header.size);
record__write(rec, data1, len1);
if (len2)
record__write(rec, data2, len2);
record__write(rec, &pad, padding);
return 0;
}
static int record__auxtrace_mmap_read(struct record *rec,
struct auxtrace_mmap *mm)
{
int ret;
ret = auxtrace_mmap__read(mm, rec->itr, &rec->tool,
record__process_auxtrace);
if (ret < 0)
return ret;
if (ret)
rec->samples++;
return 0;
}
static int record__auxtrace_mmap_read_snapshot(struct record *rec,
struct auxtrace_mmap *mm)
{
int ret;
ret = auxtrace_mmap__read_snapshot(mm, rec->itr, &rec->tool,
record__process_auxtrace,
rec->opts.auxtrace_snapshot_size);
if (ret < 0)
return ret;
if (ret)
rec->samples++;
return 0;
}
static int record__auxtrace_read_snapshot_all(struct record *rec)
{
int i;
int rc = 0;
for (i = 0; i < rec->evlist->nr_mmaps; i++) {
struct auxtrace_mmap *mm =
&rec->evlist->mmap[i].auxtrace_mmap;
if (!mm->base)
continue;
if (record__auxtrace_mmap_read_snapshot(rec, mm) != 0) {
rc = -1;
goto out;
}
}
out:
return rc;
}
static void record__read_auxtrace_snapshot(struct record *rec)
{
pr_debug("Recording AUX area tracing snapshot\n");
if (record__auxtrace_read_snapshot_all(rec) < 0) {
auxtrace_snapshot_err = -1;
} else {
auxtrace_snapshot_err = auxtrace_record__snapshot_finish(rec->itr);
if (!auxtrace_snapshot_err)
auxtrace_snapshot_enabled = 1;
}
}
static inline
int record__auxtrace_mmap_read(struct record *rec __maybe_unused,
struct auxtrace_mmap *mm __maybe_unused)
{
return 0;
}
static inline
void record__read_auxtrace_snapshot(struct record *rec __maybe_unused)
{
}
static inline
int auxtrace_record__snapshot_start(struct auxtrace_record *itr __maybe_unused)
{
return 0;
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
if (perf_evsel__open(pos, pos->cpus, pos->threads) < 0) {
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
if (perf_evlist__apply_filters(evlist, &pos)) {
error("failed to set filter \"%s\" on event %s with %d (%s)\n",
pos->filter, perf_evsel__name(pos), errno,
strerror_r(errno, msg, sizeof(msg)));
rc = -1;
goto out;
}
if (perf_evlist__mmap_ex(evlist, opts->mmap_pages, false,
opts->auxtrace_mmap_pages,
opts->auxtrace_snapshot_mode) < 0) {
if (errno == EPERM) {
pr_err("Permission error mapping pages.\n"
"Consider increasing "
"/proc/sys/kernel/perf_event_mlock_kb,\n"
"or try again with a smaller value of -m/--mmap_pages.\n"
"(current value: %u,%u)\n",
opts->mmap_pages, opts->auxtrace_mmap_pages);
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
static int process_sample_event(struct perf_tool *tool,
union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct machine *machine)
{
struct record *rec = container_of(tool, struct record, tool);
rec->samples++;
return build_id__mark_dso_hit(tool, event, sample, evsel, machine);
}
static int process_buildids(struct record *rec)
{
struct perf_data_file *file = &rec->file;
struct perf_session *session = rec->session;
if (file->size == 0)
return 0;
symbol_conf.ignore_vmlinux_buildid = true;
if (rec->buildid_all)
rec->tool.sample = NULL;
return perf_session__process_events(session);
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
struct auxtrace_mmap *mm = &rec->evlist->mmap[i].auxtrace_mmap;
if (rec->evlist->mmap[i].base) {
if (record__mmap_read(rec, i) != 0) {
rc = -1;
goto out;
}
}
if (mm->base && !rec->opts.auxtrace_snapshot_mode &&
record__auxtrace_mmap_read(rec, mm) != 0) {
rc = -1;
goto out;
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
if (!rec->opts.full_auxtrace)
perf_header__clear_feat(&session->header, HEADER_AUXTRACE);
perf_header__clear_feat(&session->header, HEADER_STAT);
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
int fd;
rec->progname = argv[0];
atexit(record__sig_exit);
signal(SIGCHLD, sig_handler);
signal(SIGINT, sig_handler);
signal(SIGTERM, sig_handler);
if (rec->opts.auxtrace_snapshot_mode)
signal(SIGUSR2, snapshot_sig_handler);
else
signal(SIGUSR2, SIG_IGN);
session = perf_session__new(file, false, tool);
if (session == NULL) {
pr_err("Perf session creation failed.\n");
return -1;
}
fd = perf_data_file__fd(file);
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
if (rec->tool.ordered_events && !perf_evlist__sample_id_all(rec->evlist)) {
pr_warning("WARNING: No sample_id_all support, falling back to unordered processing\n");
rec->tool.ordered_events = false;
}
if (!rec->evlist->nr_groups)
perf_header__clear_feat(&session->header, HEADER_GROUP_DESC);
if (file->is_pipe) {
err = perf_header__write_pipe(fd);
if (err < 0)
goto out_child;
} else {
err = perf_session__write_header(session, rec->evlist, fd, false);
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
err = perf_event__synthesize_tracing_data(tool, fd, rec->evlist,
process_synthesized_event);
if (err <= 0) {
pr_err("Couldn't record tracing data.\n");
goto out_child;
}
rec->bytes_written += err;
}
}
if (rec->opts.full_auxtrace) {
err = perf_event__synthesize_auxtrace_info(rec->itr, tool,
session, process_synthesized_event);
if (err)
goto out_delete_session;
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
process_synthesized_event, opts->sample_address,
opts->proc_map_timeout);
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
if (forks) {
union perf_event *event;
event = malloc(sizeof(event->comm) + machine->id_hdr_size);
if (event == NULL) {
err = -ENOMEM;
goto out_child;
}
perf_event__synthesize_comm(tool, event,
rec->evlist->workload.pid,
process_synthesized_event,
machine);
free(event);
perf_evlist__start_workload(rec->evlist);
}
if (opts->initial_delay) {
usleep(opts->initial_delay * 1000);
perf_evlist__enable(rec->evlist);
}
auxtrace_snapshot_enabled = 1;
for (;;) {
unsigned long long hits = rec->samples;
if (record__mmap_read_all(rec) < 0) {
auxtrace_snapshot_enabled = 0;
err = -1;
goto out_child;
}
if (auxtrace_record__snapshot_started) {
auxtrace_record__snapshot_started = 0;
if (!auxtrace_snapshot_err)
record__read_auxtrace_snapshot(rec);
if (auxtrace_snapshot_err) {
pr_err("AUX area tracing snapshot failed\n");
err = -1;
goto out_child;
}
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
auxtrace_snapshot_enabled = 0;
perf_evlist__disable(rec->evlist);
disabled = true;
}
}
auxtrace_snapshot_enabled = 0;
if (forks && workload_exec_errno) {
char msg[STRERR_BUFSIZE];
const char *emsg = strerror_r(workload_exec_errno, msg, sizeof(msg));
pr_err("Workload failed: %s\n", emsg);
err = -1;
goto out_child;
}
if (!quiet)
fprintf(stderr, "[ perf record: Woken up %ld times to write data ]\n", waking);
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
rec->samples = 0;
if (!err && !file->is_pipe) {
rec->session->header.data_size += rec->bytes_written;
file->size = lseek(perf_data_file__fd(file), 0, SEEK_CUR);
if (!rec->no_buildid) {
process_buildids(rec);
if (rec->buildid_all)
dsos__hit_all(rec->session);
}
perf_session__write_header(rec->session, rec->evlist, fd, true);
}
if (!err && !quiet) {
char samples[128];
if (rec->samples && !rec->opts.full_auxtrace)
scnprintf(samples, sizeof(samples),
" (%" PRIu64 " samples)", rec->samples);
else
samples[0] = '\0';
fprintf(stderr, "[ perf record: Captured and wrote %.3f MB %s%s ]\n",
perf_data_file__size(file) / 1024.0 / 1024.0,
file->path, samples);
}
out_delete_session:
perf_session__delete(session);
return status;
}
static void callchain_debug(void)
{
static const char *str[CALLCHAIN_MAX] = { "NONE", "FP", "DWARF", "LBR" };
pr_debug("callchain: type %s\n", str[callchain_param.record_mode]);
if (callchain_param.record_mode == CALLCHAIN_DWARF)
pr_debug("callchain: stack dump size %d\n",
callchain_param.dump_size);
}
int record_parse_callchain_opt(const struct option *opt,
const char *arg,
int unset)
{
int ret;
struct record_opts *record = (struct record_opts *)opt->value;
record->callgraph_set = true;
callchain_param.enabled = !unset;
if (unset) {
callchain_param.record_mode = CALLCHAIN_NONE;
pr_debug("callchain: disabled\n");
return 0;
}
ret = parse_callchain_record_opt(arg, &callchain_param);
if (!ret) {
if (callchain_param.record_mode == CALLCHAIN_DWARF)
record->sample_address = true;
callchain_debug();
}
return ret;
}
int record_callchain_opt(const struct option *opt,
const char *arg __maybe_unused,
int unset __maybe_unused)
{
struct record_opts *record = (struct record_opts *)opt->value;
record->callgraph_set = true;
callchain_param.enabled = true;
if (callchain_param.record_mode == CALLCHAIN_NONE)
callchain_param.record_mode = CALLCHAIN_FP;
callchain_debug();
return 0;
}
static int perf_record_config(const char *var, const char *value, void *cb)
{
struct record *rec = cb;
if (!strcmp(var, "record.build-id")) {
if (!strcmp(value, "cache"))
rec->no_buildid_cache = false;
else if (!strcmp(value, "no-cache"))
rec->no_buildid_cache = true;
else if (!strcmp(value, "skip"))
rec->no_buildid = true;
else
return -1;
return 0;
}
if (!strcmp(var, "record.call-graph"))
var = "call-graph.record-mode";
return perf_default_config(var, value, cb);
}
static int parse_clockid(const struct option *opt, const char *str, int unset)
{
struct record_opts *opts = (struct record_opts *)opt->value;
const struct clockid_map *cm;
const char *ostr = str;
if (unset) {
opts->use_clockid = 0;
return 0;
}
if (!str)
return 0;
if (opts->use_clockid)
return -1;
opts->use_clockid = true;
if (sscanf(str, "%d", &opts->clockid) == 1)
return 0;
if (!strncasecmp(str, "CLOCK_", 6))
str += 6;
for (cm = clockids; cm->name; cm++) {
if (!strcasecmp(str, cm->name)) {
opts->clockid = cm->clockid;
return 0;
}
}
opts->use_clockid = false;
ui__warning("unknown clockid %s, check man page\n", ostr);
return -1;
}
static int record__parse_mmap_pages(const struct option *opt,
const char *str,
int unset __maybe_unused)
{
struct record_opts *opts = opt->value;
char *s, *p;
unsigned int mmap_pages;
int ret;
if (!str)
return -EINVAL;
s = strdup(str);
if (!s)
return -ENOMEM;
p = strchr(s, ',');
if (p)
*p = '\0';
if (*s) {
ret = __perf_evlist__parse_mmap_pages(&mmap_pages, s);
if (ret)
goto out_free;
opts->mmap_pages = mmap_pages;
}
if (!p) {
ret = 0;
goto out_free;
}
ret = __perf_evlist__parse_mmap_pages(&mmap_pages, p + 1);
if (ret)
goto out_free;
opts->auxtrace_mmap_pages = mmap_pages;
out_free:
free(s);
return ret;
}
int cmd_record(int argc, const char **argv, const char *prefix __maybe_unused)
{
int err;
struct record *rec = &record;
char errbuf[BUFSIZ];
#ifndef HAVE_LIBBPF_SUPPORT
# define set_nobuild(s, l, c) set_option_nobuild(record_options, s, l, "NO_LIBBPF=1", c)
set_nobuild('\0', "clang-path", true);
set_nobuild('\0', "clang-opt", true);
# undef set_nobuild
#endif
#ifndef HAVE_BPF_PROLOGUE
# if !defined (HAVE_DWARF_SUPPORT)
# define REASON "NO_DWARF=1"
# elif !defined (HAVE_LIBBPF_SUPPORT)
# define REASON "NO_LIBBPF=1"
# else
# define REASON "this architecture doesn't support BPF prologue"
# endif
# define set_nobuild(s, l, c) set_option_nobuild(record_options, s, l, REASON, c)
set_nobuild('\0', "vmlinux", true);
# undef set_nobuild
# undef REASON
#endif
rec->evlist = perf_evlist__new();
if (rec->evlist == NULL)
return -ENOMEM;
perf_config(perf_record_config, rec);
argc = parse_options(argc, argv, record_options, record_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc && target__none(&rec->opts.target))
usage_with_options(record_usage, record_options);
if (nr_cgroups && !rec->opts.target.system_wide) {
usage_with_options_msg(record_usage, record_options,
"cgroup monitoring only available in system-wide mode");
}
if (rec->opts.record_switch_events &&
!perf_can_record_switch_events()) {
ui__error("kernel does not support recording context switch events\n");
parse_options_usage(record_usage, record_options, "switch-events", 0);
return -EINVAL;
}
if (!rec->itr) {
rec->itr = auxtrace_record__init(rec->evlist, &err);
if (err)
return err;
}
err = auxtrace_parse_snapshot_options(rec->itr, &rec->opts,
rec->opts.auxtrace_snapshot_opts);
if (err)
return err;
err = -ENOMEM;
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
err = auxtrace_record__options(rec->itr, rec->evlist, &rec->opts);
if (err)
goto out_symbol_exit;
if (rec->opts.full_auxtrace)
rec->buildid_all = true;
if (record_opts__config(&rec->opts)) {
err = -EINVAL;
goto out_symbol_exit;
}
err = __cmd_record(&record, argc, argv);
out_symbol_exit:
perf_evlist__delete(rec->evlist);
symbol__exit();
auxtrace_record__free(rec->itr);
return err;
}
static void snapshot_sig_handler(int sig __maybe_unused)
{
if (!auxtrace_snapshot_enabled)
return;
auxtrace_snapshot_enabled = 0;
auxtrace_snapshot_err = auxtrace_record__snapshot_start(record.itr);
auxtrace_record__snapshot_started = 1;
}
