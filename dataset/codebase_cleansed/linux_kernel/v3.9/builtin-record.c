static int on_exit(on_exit_func_t function, void *arg)
{
if (__on_exit_count == ATEXIT_MAX)
return -ENOMEM;
else if (__on_exit_count == 0)
atexit(__handle_on_exit_funcs);
__on_exit_funcs[__on_exit_count] = function;
__on_exit_args[__on_exit_count++] = arg;
return 0;
}
static void __handle_on_exit_funcs(void)
{
int i;
for (i = 0; i < __on_exit_count; i++)
__on_exit_funcs[i] (__exitcode, __on_exit_args[i]);
}
static void advance_output(struct perf_record *rec, size_t size)
{
rec->bytes_written += size;
}
static int write_output(struct perf_record *rec, void *buf, size_t size)
{
while (size) {
int ret = write(rec->output, buf, size);
if (ret < 0) {
pr_err("failed to write\n");
return -1;
}
size -= ret;
buf += ret;
rec->bytes_written += ret;
}
return 0;
}
static int process_synthesized_event(struct perf_tool *tool,
union perf_event *event,
struct perf_sample *sample __maybe_unused,
struct machine *machine __maybe_unused)
{
struct perf_record *rec = container_of(tool, struct perf_record, tool);
if (write_output(rec, event, event->header.size) < 0)
return -1;
return 0;
}
static int perf_record__mmap_read(struct perf_record *rec,
struct perf_mmap *md)
{
unsigned int head = perf_mmap__read_head(md);
unsigned int old = md->prev;
unsigned char *data = md->base + rec->page_size;
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
if (write_output(rec, buf, size) < 0) {
rc = -1;
goto out;
}
}
buf = &data[old & md->mask];
size = head - old;
old += size;
if (write_output(rec, buf, size) < 0) {
rc = -1;
goto out;
}
md->prev = old;
perf_mmap__write_tail(md, old);
out:
return rc;
}
static void sig_handler(int sig)
{
if (sig == SIGCHLD)
child_finished = 1;
done = 1;
signr = sig;
}
static void perf_record__sig_exit(int exit_status __maybe_unused, void *arg)
{
struct perf_record *rec = arg;
int status;
if (rec->evlist->workload.pid > 0) {
if (!child_finished)
kill(rec->evlist->workload.pid, SIGTERM);
wait(&status);
if (WIFSIGNALED(status))
psignal(WTERMSIG(status), rec->progname);
}
if (signr == -1 || signr == SIGUSR1)
return;
signal(signr, SIG_DFL);
kill(getpid(), signr);
}
static bool perf_evlist__equal(struct perf_evlist *evlist,
struct perf_evlist *other)
{
struct perf_evsel *pos, *pair;
if (evlist->nr_entries != other->nr_entries)
return false;
pair = perf_evlist__first(other);
list_for_each_entry(pos, &evlist->entries, node) {
if (memcmp(&pos->attr, &pair->attr, sizeof(pos->attr) != 0))
return false;
pair = perf_evsel__next(pair);
}
return true;
}
static int perf_record__open(struct perf_record *rec)
{
char msg[512];
struct perf_evsel *pos;
struct perf_evlist *evlist = rec->evlist;
struct perf_session *session = rec->session;
struct perf_record_opts *opts = &rec->opts;
int rc = 0;
perf_evlist__config(evlist, opts);
list_for_each_entry(pos, &evlist->entries, node) {
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
strerror(errno));
rc = -1;
goto out;
}
if (perf_evlist__mmap(evlist, opts->mmap_pages, false) < 0) {
if (errno == EPERM) {
pr_err("Permission error mapping pages.\n"
"Consider increasing "
"/proc/sys/kernel/perf_event_mlock_kb,\n"
"or try again with a smaller value of -m/--mmap_pages.\n"
"(current value: %d)\n", opts->mmap_pages);
rc = -errno;
} else if (!is_power_of_2(opts->mmap_pages) &&
(opts->mmap_pages != UINT_MAX)) {
pr_err("--mmap_pages/-m value must be a power of two.");
rc = -EINVAL;
} else {
pr_err("failed to mmap with %d (%s)\n", errno, strerror(errno));
rc = -errno;
}
goto out;
}
if (rec->file_new)
session->evlist = evlist;
else {
if (!perf_evlist__equal(session->evlist, evlist)) {
fprintf(stderr, "incompatible append\n");
rc = -1;
goto out;
}
}
perf_session__set_id_hdr_size(session);
out:
return rc;
}
static int process_buildids(struct perf_record *rec)
{
u64 size = lseek(rec->output, 0, SEEK_CUR);
if (size == 0)
return 0;
rec->session->fd = rec->output;
return __perf_session__process_events(rec->session, rec->post_processing_offset,
size - rec->post_processing_offset,
size, &build_id__mark_dso_hit_ops);
}
static void perf_record__exit(int status, void *arg)
{
struct perf_record *rec = arg;
if (status != 0)
return;
if (!rec->opts.pipe_output) {
rec->session->header.data_size += rec->bytes_written;
if (!rec->no_buildid)
process_buildids(rec);
perf_session__write_header(rec->session, rec->evlist,
rec->output, true);
perf_session__delete(rec->session);
perf_evlist__delete(rec->evlist);
symbol__exit();
}
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
machine, "_text");
if (err < 0)
err = perf_event__synthesize_kernel_mmap(tool, process_synthesized_event,
machine, "_stext");
if (err < 0)
pr_err("Couldn't record guest kernel [%d]'s reference"
" relocation symbol.\n", machine->pid);
}
static int perf_record__mmap_read_all(struct perf_record *rec)
{
int i;
int rc = 0;
for (i = 0; i < rec->evlist->nr_mmaps; i++) {
if (rec->evlist->mmap[i].base) {
if (perf_record__mmap_read(rec, &rec->evlist->mmap[i]) != 0) {
rc = -1;
goto out;
}
}
}
if (perf_header__has_feat(&rec->session->header, HEADER_TRACING_DATA))
rc = write_output(rec, &finished_round_event,
sizeof(finished_round_event));
out:
return rc;
}
static int __cmd_record(struct perf_record *rec, int argc, const char **argv)
{
struct stat st;
int flags;
int err, output, feat;
unsigned long waking = 0;
const bool forks = argc > 0;
struct machine *machine;
struct perf_tool *tool = &rec->tool;
struct perf_record_opts *opts = &rec->opts;
struct perf_evlist *evsel_list = rec->evlist;
const char *output_name = rec->output_name;
struct perf_session *session;
bool disabled = false;
rec->progname = argv[0];
rec->page_size = sysconf(_SC_PAGE_SIZE);
on_exit(perf_record__sig_exit, rec);
signal(SIGCHLD, sig_handler);
signal(SIGINT, sig_handler);
signal(SIGUSR1, sig_handler);
if (!output_name) {
if (!fstat(STDOUT_FILENO, &st) && S_ISFIFO(st.st_mode))
opts->pipe_output = true;
else
rec->output_name = output_name = "perf.data";
}
if (output_name) {
if (!strcmp(output_name, "-"))
opts->pipe_output = true;
else if (!stat(output_name, &st) && st.st_size) {
if (rec->write_mode == WRITE_FORCE) {
char oldname[PATH_MAX];
snprintf(oldname, sizeof(oldname), "%s.old",
output_name);
unlink(oldname);
rename(output_name, oldname);
}
} else if (rec->write_mode == WRITE_APPEND) {
rec->write_mode = WRITE_FORCE;
}
}
flags = O_CREAT|O_RDWR;
if (rec->write_mode == WRITE_APPEND)
rec->file_new = 0;
else
flags |= O_TRUNC;
if (opts->pipe_output)
output = STDOUT_FILENO;
else
output = open(output_name, flags, S_IRUSR | S_IWUSR);
if (output < 0) {
perror("failed to create output file");
return -1;
}
rec->output = output;
session = perf_session__new(output_name, O_WRONLY,
rec->write_mode == WRITE_FORCE, false, NULL);
if (session == NULL) {
pr_err("Not enough memory for reading perf file header\n");
return -1;
}
rec->session = session;
for (feat = HEADER_FIRST_FEATURE; feat < HEADER_LAST_FEATURE; feat++)
perf_header__set_feat(&session->header, feat);
if (rec->no_buildid)
perf_header__clear_feat(&session->header, HEADER_BUILD_ID);
if (!have_tracepoints(&evsel_list->entries))
perf_header__clear_feat(&session->header, HEADER_TRACING_DATA);
if (!rec->opts.branch_stack)
perf_header__clear_feat(&session->header, HEADER_BRANCH_STACK);
if (!rec->file_new) {
err = perf_session__read_header(session, output);
if (err < 0)
goto out_delete_session;
}
if (forks) {
err = perf_evlist__prepare_workload(evsel_list, opts, argv);
if (err < 0) {
pr_err("Couldn't run the workload!\n");
goto out_delete_session;
}
}
if (perf_record__open(rec) != 0) {
err = -1;
goto out_delete_session;
}
if (!evsel_list->nr_groups)
perf_header__clear_feat(&session->header, HEADER_GROUP_DESC);
on_exit(perf_record__exit, rec);
if (opts->pipe_output) {
err = perf_header__write_pipe(output);
if (err < 0)
goto out_delete_session;
} else if (rec->file_new) {
err = perf_session__write_header(session, evsel_list,
output, false);
if (err < 0)
goto out_delete_session;
}
if (!rec->no_buildid
&& !perf_header__has_feat(&session->header, HEADER_BUILD_ID)) {
pr_err("Couldn't generate buildids. "
"Use --no-buildid to profile anyway.\n");
err = -1;
goto out_delete_session;
}
rec->post_processing_offset = lseek(output, 0, SEEK_CUR);
machine = &session->machines.host;
if (opts->pipe_output) {
err = perf_event__synthesize_attrs(tool, session,
process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize attrs.\n");
goto out_delete_session;
}
err = perf_event__synthesize_event_types(tool, process_synthesized_event,
machine);
if (err < 0) {
pr_err("Couldn't synthesize event_types.\n");
goto out_delete_session;
}
if (have_tracepoints(&evsel_list->entries)) {
err = perf_event__synthesize_tracing_data(tool, output, evsel_list,
process_synthesized_event);
if (err <= 0) {
pr_err("Couldn't record tracing data.\n");
goto out_delete_session;
}
advance_output(rec, err);
}
}
err = perf_event__synthesize_kernel_mmap(tool, process_synthesized_event,
machine, "_text");
if (err < 0)
err = perf_event__synthesize_kernel_mmap(tool, process_synthesized_event,
machine, "_stext");
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
if (perf_target__has_task(&opts->target))
err = perf_event__synthesize_thread_map(tool, evsel_list->threads,
process_synthesized_event,
machine);
else if (perf_target__has_cpu(&opts->target))
err = perf_event__synthesize_threads(tool, process_synthesized_event,
machine);
else
err = 0;
if (err != 0)
goto out_delete_session;
if (rec->realtime_prio) {
struct sched_param param;
param.sched_priority = rec->realtime_prio;
if (sched_setscheduler(0, SCHED_FIFO, &param)) {
pr_err("Could not set realtime priority.\n");
err = -1;
goto out_delete_session;
}
}
if (!perf_target__none(&opts->target))
perf_evlist__enable(evsel_list);
if (forks)
perf_evlist__start_workload(evsel_list);
for (;;) {
int hits = rec->samples;
if (perf_record__mmap_read_all(rec) < 0) {
err = -1;
goto out_delete_session;
}
if (hits == rec->samples) {
if (done)
break;
err = poll(evsel_list->pollfd, evsel_list->nr_fds, -1);
waking++;
}
if (done && !disabled && !perf_target__none(&opts->target)) {
perf_evlist__disable(evsel_list);
disabled = true;
}
}
if (quiet || signr == SIGUSR1)
return 0;
fprintf(stderr, "[ perf record: Woken up %ld times to write data ]\n", waking);
fprintf(stderr,
"[ perf record: Captured and wrote %.3f MB %s (~%" PRIu64 " samples) ]\n",
(double)rec->bytes_written / 1024.0 / 1024.0,
output_name,
rec->bytes_written / 24);
return 0;
out_delete_session:
perf_session__delete(session);
return err;
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
static int get_stack_size(char *str, unsigned long *_size)
{
char *endptr;
unsigned long size;
unsigned long max_size = round_down(USHRT_MAX, sizeof(u64));
size = strtoul(str, &endptr, 0);
do {
if (*endptr)
break;
size = round_up(size, sizeof(u64));
if (!size || size > max_size)
break;
*_size = size;
return 0;
} while (0);
pr_err("callchain: Incorrect stack dump size (max %ld): %s\n",
max_size, str);
return -1;
}
int record_parse_callchain_opt(const struct option *opt,
const char *arg, int unset)
{
struct perf_record_opts *opts = opt->value;
char *tok, *name, *saveptr = NULL;
char *buf;
int ret = -1;
if (unset)
return 0;
BUG_ON(!arg);
buf = malloc(strlen(arg) + 1);
if (!buf)
return -ENOMEM;
strcpy(buf, arg);
tok = strtok_r((char *)buf, ",", &saveptr);
name = tok ? : (char *)buf;
do {
if (!strncmp(name, "fp", sizeof("fp"))) {
if (!strtok_r(NULL, ",", &saveptr)) {
opts->call_graph = CALLCHAIN_FP;
ret = 0;
} else
pr_err("callchain: No more arguments "
"needed for -g fp\n");
break;
#ifdef LIBUNWIND_SUPPORT
} else if (!strncmp(name, "dwarf", sizeof("dwarf"))) {
const unsigned long default_stack_dump_size = 8192;
ret = 0;
opts->call_graph = CALLCHAIN_DWARF;
opts->stack_dump_size = default_stack_dump_size;
tok = strtok_r(NULL, ",", &saveptr);
if (tok) {
unsigned long size = 0;
ret = get_stack_size(tok, &size);
opts->stack_dump_size = size;
}
if (!ret)
pr_debug("callchain: stack dump size %d\n",
opts->stack_dump_size);
#endif
} else {
pr_err("callchain: Unknown -g option "
"value: %s\n", arg);
break;
}
} while (0);
free(buf);
if (!ret)
pr_debug("callchain: type %d\n", opts->call_graph);
return ret;
}
int cmd_record(int argc, const char **argv, const char *prefix __maybe_unused)
{
int err = -ENOMEM;
struct perf_evsel *pos;
struct perf_evlist *evsel_list;
struct perf_record *rec = &record;
char errbuf[BUFSIZ];
evsel_list = perf_evlist__new(NULL, NULL);
if (evsel_list == NULL)
return -ENOMEM;
rec->evlist = evsel_list;
argc = parse_options(argc, argv, record_options, record_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc && perf_target__none(&rec->opts.target))
usage_with_options(record_usage, record_options);
if (rec->force && rec->append_file) {
ui__error("Can't overwrite and append at the same time."
" You need to choose between -f and -A");
usage_with_options(record_usage, record_options);
} else if (rec->append_file) {
rec->write_mode = WRITE_APPEND;
} else {
rec->write_mode = WRITE_FORCE;
}
if (nr_cgroups && !rec->opts.target.system_wide) {
ui__error("cgroup monitoring only available in"
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
if (rec->no_buildid_cache || rec->no_buildid)
disable_buildid_cache();
if (evsel_list->nr_entries == 0 &&
perf_evlist__add_default(evsel_list) < 0) {
pr_err("Not enough memory for event selector list\n");
goto out_symbol_exit;
}
err = perf_target__validate(&rec->opts.target);
if (err) {
perf_target__strerror(&rec->opts.target, err, errbuf, BUFSIZ);
ui__warning("%s", errbuf);
}
err = perf_target__parse_uid(&rec->opts.target);
if (err) {
int saved_errno = errno;
perf_target__strerror(&rec->opts.target, err, errbuf, BUFSIZ);
ui__error("%s", errbuf);
err = -saved_errno;
goto out_free_fd;
}
err = -ENOMEM;
if (perf_evlist__create_maps(evsel_list, &rec->opts.target) < 0)
usage_with_options(record_usage, record_options);
list_for_each_entry(pos, &evsel_list->entries, node) {
if (perf_header__push_event(pos->attr.config, perf_evsel__name(pos)))
goto out_free_fd;
}
if (rec->opts.user_interval != ULLONG_MAX)
rec->opts.default_interval = rec->opts.user_interval;
if (rec->opts.user_freq != UINT_MAX)
rec->opts.freq = rec->opts.user_freq;
if (rec->opts.default_interval)
rec->opts.freq = 0;
else if (rec->opts.freq) {
rec->opts.default_interval = rec->opts.freq;
} else {
ui__error("frequency and count are zero, aborting\n");
err = -EINVAL;
goto out_free_fd;
}
err = __cmd_record(&record, argc, argv);
out_free_fd:
perf_evlist__delete_maps(evsel_list);
out_symbol_exit:
symbol__exit();
return err;
}
