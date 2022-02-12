static bool switch_output_signal(struct record *rec)
{
return rec->switch_output.signal &&
trigger_is_ready(&switch_output_trigger);
}
static bool switch_output_size(struct record *rec)
{
return rec->switch_output.size &&
trigger_is_ready(&switch_output_trigger) &&
(rec->bytes_written >= rec->switch_output.size);
}
static bool switch_output_time(struct record *rec)
{
return rec->switch_output.time &&
trigger_is_ready(&switch_output_trigger);
}
static int record__write(struct record *rec, void *bf, size_t size)
{
if (perf_data_file__write(rec->session->file, bf, size) < 0) {
pr_err("failed to write perf data, error: %m\n");
return -1;
}
rec->bytes_written += size;
if (switch_output_size(rec))
trigger_hit(&switch_output_trigger);
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
static int
backward_rb_find_range(void *buf, int mask, u64 head, u64 *start, u64 *end)
{
struct perf_event_header *pheader;
u64 evt_head = head;
int size = mask + 1;
pr_debug2("backward_rb_find_range: buf=%p, head=%"PRIx64"\n", buf, head);
pheader = (struct perf_event_header *)(buf + (head & mask));
*start = head;
while (true) {
if (evt_head - head >= (unsigned int)size) {
pr_debug("Finished reading backward ring buffer: rewind\n");
if (evt_head - head > (unsigned int)size)
evt_head -= pheader->size;
*end = evt_head;
return 0;
}
pheader = (struct perf_event_header *)(buf + (evt_head & mask));
if (pheader->size == 0) {
pr_debug("Finished reading backward ring buffer: get start\n");
*end = evt_head;
return 0;
}
evt_head += pheader->size;
pr_debug3("move evt_head: %"PRIx64"\n", evt_head);
}
WARN_ONCE(1, "Shouldn't get here\n");
return -1;
}
static int
rb_find_range(void *data, int mask, u64 head, u64 old,
u64 *start, u64 *end, bool backward)
{
if (!backward) {
*start = old;
*end = head;
return 0;
}
return backward_rb_find_range(data, mask, head, start, end);
}
static int
record__mmap_read(struct record *rec, struct perf_mmap *md,
bool overwrite, bool backward)
{
u64 head = perf_mmap__read_head(md);
u64 old = md->prev;
u64 end = head, start = old;
unsigned char *data = md->base + page_size;
unsigned long size;
void *buf;
int rc = 0;
if (rb_find_range(data, md->mask, head,
old, &start, &end, backward))
return -1;
if (start == end)
return 0;
rec->samples++;
size = end - start;
if (size > (unsigned long)(md->mask) + 1) {
WARN_ONCE(1, "failed to keep up with mmap data. (warn only once)\n");
md->prev = head;
perf_mmap__consume(md, overwrite || backward);
return 0;
}
if ((start & md->mask) + size != (end & md->mask)) {
buf = &data[start & md->mask];
size = md->mask + 1 - (start & md->mask);
start += size;
if (record__write(rec, buf, size) < 0) {
rc = -1;
goto out;
}
}
buf = &data[start & md->mask];
size = end - start;
start += size;
if (record__write(rec, buf, size) < 0) {
rc = -1;
goto out;
}
md->prev = head;
perf_mmap__consume(md, overwrite || backward);
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
static void sigsegv_handler(int sig)
{
perf_hooks__recover();
sighandler_dump_stack(sig);
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
trigger_error(&auxtrace_snapshot_trigger);
} else {
if (auxtrace_record__snapshot_finish(rec->itr))
trigger_error(&auxtrace_snapshot_trigger);
else
trigger_ready(&auxtrace_snapshot_trigger);
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
static int record__mmap_evlist(struct record *rec,
struct perf_evlist *evlist)
{
struct record_opts *opts = &rec->opts;
char msg[512];
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
return -errno;
} else {
pr_err("failed to mmap with %d (%s)\n", errno,
str_error_r(errno, msg, sizeof(msg)));
if (errno)
return -errno;
else
return -EINVAL;
}
}
return 0;
}
static int record__mmap(struct record *rec)
{
return record__mmap_evlist(rec, rec->evlist);
}
static int record__open(struct record *rec)
{
char msg[BUFSIZ];
struct perf_evsel *pos;
struct perf_evlist *evlist = rec->evlist;
struct perf_session *session = rec->session;
struct record_opts *opts = &rec->opts;
struct perf_evsel_config_term *err_term;
int rc = 0;
perf_evlist__config(evlist, opts, &callchain_param);
evlist__for_each_entry(evlist, pos) {
try_again:
if (perf_evsel__open(pos, pos->cpus, pos->threads) < 0) {
if (perf_evsel__fallback(pos, errno, msg, sizeof(msg))) {
if (verbose > 0)
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
str_error_r(errno, msg, sizeof(msg)));
rc = -1;
goto out;
}
if (perf_evlist__apply_drv_configs(evlist, &pos, &err_term)) {
error("failed to set config \"%s\" on event %s with %d (%s)\n",
err_term->val.drv_cfg, perf_evsel__name(pos), errno,
str_error_r(errno, msg, sizeof(msg)));
rc = -1;
goto out;
}
rc = record__mmap(rec);
if (rc)
goto out;
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
static int record__mmap_read_evlist(struct record *rec, struct perf_evlist *evlist,
bool backward)
{
u64 bytes_written = rec->bytes_written;
int i;
int rc = 0;
struct perf_mmap *maps;
if (!evlist)
return 0;
maps = backward ? evlist->backward_mmap : evlist->mmap;
if (!maps)
return 0;
if (backward && evlist->bkw_mmap_state != BKW_MMAP_DATA_PENDING)
return 0;
for (i = 0; i < evlist->nr_mmaps; i++) {
struct auxtrace_mmap *mm = &maps[i].auxtrace_mmap;
if (maps[i].base) {
if (record__mmap_read(rec, &maps[i],
evlist->overwrite, backward) != 0) {
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
if (backward)
perf_evlist__toggle_bkw_mmap(evlist, BKW_MMAP_EMPTY);
out:
return rc;
}
static int record__mmap_read_all(struct record *rec)
{
int err;
err = record__mmap_read_evlist(rec, rec->evlist, false);
if (err)
return err;
return record__mmap_read_evlist(rec, rec->evlist, true);
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
static void
record__finish_output(struct record *rec)
{
struct perf_data_file *file = &rec->file;
int fd = perf_data_file__fd(file);
if (file->is_pipe)
return;
rec->session->header.data_size += rec->bytes_written;
file->size = lseek(perf_data_file__fd(file), 0, SEEK_CUR);
if (!rec->no_buildid) {
process_buildids(rec);
if (rec->buildid_all)
dsos__hit_all(rec->session);
}
perf_session__write_header(rec->session, rec->evlist, fd, true);
return;
}
static int record__synthesize_workload(struct record *rec, bool tail)
{
int err;
struct thread_map *thread_map;
if (rec->opts.tail_synthesize != tail)
return 0;
thread_map = thread_map__new_by_tid(rec->evlist->workload.pid);
if (thread_map == NULL)
return -1;
err = perf_event__synthesize_thread_map(&rec->tool, thread_map,
process_synthesized_event,
&rec->session->machines.host,
rec->opts.sample_address,
rec->opts.proc_map_timeout);
thread_map__put(thread_map);
return err;
}
static int
record__switch_output(struct record *rec, bool at_exit)
{
struct perf_data_file *file = &rec->file;
int fd, err;
char timestamp[] = "InvalidTimestamp";
record__synthesize(rec, true);
if (target__none(&rec->opts.target))
record__synthesize_workload(rec, true);
rec->samples = 0;
record__finish_output(rec);
err = fetch_current_timestamp(timestamp, sizeof(timestamp));
if (err) {
pr_err("Failed to get current timestamp\n");
return -EINVAL;
}
fd = perf_data_file__switch(file, timestamp,
rec->session->header.data_offset,
at_exit);
if (fd >= 0 && !at_exit) {
rec->bytes_written = 0;
rec->session->header.data_size = 0;
}
if (!quiet)
fprintf(stderr, "[ perf record: Dump %s.%s ]\n",
file->path, timestamp);
if (!at_exit) {
record__synthesize(rec, false);
if (target__none(&rec->opts.target))
record__synthesize_workload(rec, false);
}
return fd;
}
static void workload_exec_failed_signal(int signo __maybe_unused,
siginfo_t *info,
void *ucontext __maybe_unused)
{
workload_exec_errno = info->si_value.sival_int;
done = 1;
child_finished = 1;
}
int __weak
perf_event__synth_time_conv(const struct perf_event_mmap_page *pc __maybe_unused,
struct perf_tool *tool __maybe_unused,
perf_event__handler_t process __maybe_unused,
struct machine *machine __maybe_unused)
{
return 0;
}
static const struct perf_event_mmap_page *
perf_evlist__pick_pc(struct perf_evlist *evlist)
{
if (evlist) {
if (evlist->mmap && evlist->mmap[0].base)
return evlist->mmap[0].base;
if (evlist->backward_mmap && evlist->backward_mmap[0].base)
return evlist->backward_mmap[0].base;
}
return NULL;
}
static const struct perf_event_mmap_page *record__pick_pc(struct record *rec)
{
const struct perf_event_mmap_page *pc;
pc = perf_evlist__pick_pc(rec->evlist);
if (pc)
return pc;
return NULL;
}
static int record__synthesize(struct record *rec, bool tail)
{
struct perf_session *session = rec->session;
struct machine *machine = &session->machines.host;
struct perf_data_file *file = &rec->file;
struct record_opts *opts = &rec->opts;
struct perf_tool *tool = &rec->tool;
int fd = perf_data_file__fd(file);
int err = 0;
if (rec->opts.tail_synthesize != tail)
return 0;
if (file->is_pipe) {
err = perf_event__synthesize_attrs(tool, session,
process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize attrs.\n");
goto out;
}
if (have_tracepoints(&rec->evlist->entries)) {
err = perf_event__synthesize_tracing_data(tool, fd, rec->evlist,
process_synthesized_event);
if (err <= 0) {
pr_err("Couldn't record tracing data.\n");
goto out;
}
rec->bytes_written += err;
}
}
err = perf_event__synth_time_conv(record__pick_pc(rec), tool,
process_synthesized_event, machine);
if (err)
goto out;
if (rec->opts.full_auxtrace) {
err = perf_event__synthesize_auxtrace_info(rec->itr, tool,
session, process_synthesized_event);
if (err)
goto out;
}
err = perf_event__synthesize_kernel_mmap(tool, process_synthesized_event,
machine);
WARN_ONCE(err < 0, "Couldn't record kernel reference relocation symbol\n"
"Symbol resolution may be skewed if relocation was used (e.g. kexec).\n"
"Check /proc/kallsyms permission or run as root.\n");
err = perf_event__synthesize_modules(tool, process_synthesized_event,
machine);
WARN_ONCE(err < 0, "Couldn't record kernel module information.\n"
"Symbol resolution may be skewed if relocation was used (e.g. kexec).\n"
"Check /proc/modules permission or run as root.\n");
if (perf_guest) {
machines__process_guests(&session->machines,
perf_event__synthesize_guest_os, tool);
}
err = __machine__synthesize_threads(machine, tool, &opts->target, rec->evlist->threads,
process_synthesized_event, opts->sample_address,
opts->proc_map_timeout);
out:
return err;
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
signal(SIGSEGV, sigsegv_handler);
if (rec->opts.record_namespaces)
tool->namespace_events = true;
if (rec->opts.auxtrace_snapshot_mode || rec->switch_output.enabled) {
signal(SIGUSR2, snapshot_sig_handler);
if (rec->opts.auxtrace_snapshot_mode)
trigger_on(&auxtrace_snapshot_trigger);
if (rec->switch_output.enabled)
trigger_on(&switch_output_trigger);
} else {
signal(SIGUSR2, SIG_IGN);
}
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
err = bpf__apply_obj_config();
if (err) {
char errbuf[BUFSIZ];
bpf__strerror_apply_obj_config(err, errbuf, sizeof(errbuf));
pr_err("ERROR: Apply config to BPF failed: %s\n",
errbuf);
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
err = record__synthesize(rec, false);
if (err < 0)
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
pid_t tgid;
event = malloc(sizeof(event->comm) + machine->id_hdr_size);
if (event == NULL) {
err = -ENOMEM;
goto out_child;
}
tgid = perf_event__synthesize_comm(tool, event,
rec->evlist->workload.pid,
process_synthesized_event,
machine);
free(event);
if (tgid == -1)
goto out_child;
event = malloc(sizeof(event->namespaces) +
(NR_NAMESPACES * sizeof(struct perf_ns_link_info)) +
machine->id_hdr_size);
if (event == NULL) {
err = -ENOMEM;
goto out_child;
}
perf_event__synthesize_namespaces(tool, event,
rec->evlist->workload.pid,
tgid, process_synthesized_event,
machine);
free(event);
perf_evlist__start_workload(rec->evlist);
}
if (opts->initial_delay) {
usleep(opts->initial_delay * USEC_PER_MSEC);
perf_evlist__enable(rec->evlist);
}
trigger_ready(&auxtrace_snapshot_trigger);
trigger_ready(&switch_output_trigger);
perf_hooks__invoke_record_start();
for (;;) {
unsigned long long hits = rec->samples;
if (trigger_is_hit(&switch_output_trigger) || done || draining)
perf_evlist__toggle_bkw_mmap(rec->evlist, BKW_MMAP_DATA_PENDING);
if (record__mmap_read_all(rec) < 0) {
trigger_error(&auxtrace_snapshot_trigger);
trigger_error(&switch_output_trigger);
err = -1;
goto out_child;
}
if (auxtrace_record__snapshot_started) {
auxtrace_record__snapshot_started = 0;
if (!trigger_is_error(&auxtrace_snapshot_trigger))
record__read_auxtrace_snapshot(rec);
if (trigger_is_error(&auxtrace_snapshot_trigger)) {
pr_err("AUX area tracing snapshot failed\n");
err = -1;
goto out_child;
}
}
if (trigger_is_hit(&switch_output_trigger)) {
if (rec->evlist->bkw_mmap_state == BKW_MMAP_RUNNING)
continue;
trigger_ready(&switch_output_trigger);
perf_evlist__toggle_bkw_mmap(rec->evlist, BKW_MMAP_RUNNING);
if (!quiet)
fprintf(stderr, "[ perf record: dump data: Woken up %ld times ]\n",
waking);
waking = 0;
fd = record__switch_output(rec, false);
if (fd < 0) {
pr_err("Failed to switch to new file\n");
trigger_error(&switch_output_trigger);
err = fd;
goto out_child;
}
if (rec->switch_output.time)
alarm(rec->switch_output.time);
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
trigger_off(&auxtrace_snapshot_trigger);
perf_evlist__disable(rec->evlist);
disabled = true;
}
}
trigger_off(&auxtrace_snapshot_trigger);
trigger_off(&switch_output_trigger);
if (forks && workload_exec_errno) {
char msg[STRERR_BUFSIZE];
const char *emsg = str_error_r(workload_exec_errno, msg, sizeof(msg));
pr_err("Workload failed: %s\n", emsg);
err = -1;
goto out_child;
}
if (!quiet)
fprintf(stderr, "[ perf record: Woken up %ld times to write data ]\n", waking);
if (target__none(&rec->opts.target))
record__synthesize_workload(rec, true);
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
record__synthesize(rec, true);
rec->samples = 0;
if (!err) {
if (!rec->timestamp_filename) {
record__finish_output(rec);
} else {
fd = record__switch_output(rec, true);
if (fd < 0) {
status = fd;
goto out_delete_session;
}
}
}
perf_hooks__invoke_record_end();
if (!err && !quiet) {
char samples[128];
const char *postfix = rec->timestamp_filename ?
".<timestamp>" : "";
if (rec->samples && !rec->opts.full_auxtrace)
scnprintf(samples, sizeof(samples),
" (%" PRIu64 " samples)", rec->samples);
else
samples[0] = '\0';
fprintf(stderr, "[ perf record: Captured and wrote %.3f MB %s%s%s ]\n",
perf_data_file__size(file) / 1024.0 / 1024.0,
file->path, postfix, samples);
}
out_delete_session:
perf_session__delete(session);
return status;
}
static void callchain_debug(struct callchain_param *callchain)
{
static const char *str[CALLCHAIN_MAX] = { "NONE", "FP", "DWARF", "LBR" };
pr_debug("callchain: type %s\n", str[callchain->record_mode]);
if (callchain->record_mode == CALLCHAIN_DWARF)
pr_debug("callchain: stack dump size %d\n",
callchain->dump_size);
}
int record_opts__parse_callchain(struct record_opts *record,
struct callchain_param *callchain,
const char *arg, bool unset)
{
int ret;
callchain->enabled = !unset;
if (unset) {
callchain->record_mode = CALLCHAIN_NONE;
pr_debug("callchain: disabled\n");
return 0;
}
ret = parse_callchain_record_opt(arg, callchain);
if (!ret) {
if (callchain->record_mode == CALLCHAIN_DWARF)
record->sample_address = true;
callchain_debug(callchain);
}
return ret;
}
int record_parse_callchain_opt(const struct option *opt,
const char *arg,
int unset)
{
return record_opts__parse_callchain(opt->value, &callchain_param, arg, unset);
}
int record_callchain_opt(const struct option *opt,
const char *arg __maybe_unused,
int unset __maybe_unused)
{
struct callchain_param *callchain = opt->value;
callchain->enabled = true;
if (callchain->record_mode == CALLCHAIN_NONE)
callchain->record_mode = CALLCHAIN_FP;
callchain_debug(callchain);
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
static void switch_output_size_warn(struct record *rec)
{
u64 wakeup_size = perf_evlist__mmap_size(rec->opts.mmap_pages);
struct switch_output *s = &rec->switch_output;
wakeup_size /= 2;
if (s->size < wakeup_size) {
char buf[100];
unit_number__scnprintf(buf, sizeof(buf), wakeup_size);
pr_warning("WARNING: switch-output data size lower than "
"wakeup kernel buffer size (%s) "
"expect bigger perf.data sizes\n", buf);
}
}
static int switch_output_setup(struct record *rec)
{
struct switch_output *s = &rec->switch_output;
static struct parse_tag tags_size[] = {
{ .tag = 'B', .mult = 1 },
{ .tag = 'K', .mult = 1 << 10 },
{ .tag = 'M', .mult = 1 << 20 },
{ .tag = 'G', .mult = 1 << 30 },
{ .tag = 0 },
};
static struct parse_tag tags_time[] = {
{ .tag = 's', .mult = 1 },
{ .tag = 'm', .mult = 60 },
{ .tag = 'h', .mult = 60*60 },
{ .tag = 'd', .mult = 60*60*24 },
{ .tag = 0 },
};
unsigned long val;
if (!s->set)
return 0;
if (!strcmp(s->str, "signal")) {
s->signal = true;
pr_debug("switch-output with SIGUSR2 signal\n");
goto enabled;
}
val = parse_tag_value(s->str, tags_size);
if (val != (unsigned long) -1) {
s->size = val;
pr_debug("switch-output with %s size threshold\n", s->str);
goto enabled;
}
val = parse_tag_value(s->str, tags_time);
if (val != (unsigned long) -1) {
s->time = val;
pr_debug("switch-output with %s time threshold (%lu seconds)\n",
s->str, s->time);
goto enabled;
}
return -1;
enabled:
rec->timestamp_filename = true;
s->enabled = true;
if (s->size && !rec->opts.no_buffering)
switch_output_size_warn(rec);
return 0;
}
int cmd_record(int argc, const char **argv)
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
err = perf_config(perf_record_config, rec);
if (err)
return err;
argc = parse_options(argc, argv, record_options, record_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (quiet)
perf_quiet_option();
if (!argc && target__none(&rec->opts.target))
rec->opts.target.system_wide = true;
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
if (switch_output_setup(rec)) {
parse_options_usage(record_usage, record_options, "switch-output", 0);
return -EINVAL;
}
if (rec->switch_output.time) {
signal(SIGALRM, alarm_sig_handler);
alarm(rec->switch_output.time);
}
if (!rec->itr) {
rec->itr = auxtrace_record__init(rec->evlist, &err);
if (err)
goto out;
}
err = auxtrace_parse_snapshot_options(rec->itr, &rec->opts,
rec->opts.auxtrace_snapshot_opts);
if (err)
goto out;
symbol_conf.allow_aliases = true;
symbol__init(NULL);
err = auxtrace_parse_filters(rec->evlist);
if (err)
goto out;
if (dry_run)
goto out;
err = bpf__setup_stdout(rec->evlist);
if (err) {
bpf__strerror_setup_stdout(rec->evlist, err, errbuf, sizeof(errbuf));
pr_err("ERROR: Setup BPF stdout failed: %s\n",
errbuf);
goto out;
}
err = -ENOMEM;
if (symbol_conf.kptr_restrict)
pr_warning(
"WARNING: Kernel address maps (/proc/{kallsyms,modules}) are restricted,\n"
"check /proc/sys/kernel/kptr_restrict.\n\n"
"Samples in kernel functions may not be resolved if a suitable vmlinux\n"
"file is not found in the buildid cache or in the vmlinux path.\n\n"
"Samples in kernel modules won't be resolved at all.\n\n"
"If some relocation was applied (e.g. kexec) symbols may be misresolved\n"
"even with a suitable vmlinux or kallsyms file.\n\n");
if (rec->no_buildid_cache || rec->no_buildid) {
disable_buildid_cache();
} else if (rec->switch_output.enabled) {
bool disable = true;
if (rec->no_buildid_set && !rec->no_buildid)
disable = false;
if (rec->no_buildid_cache_set && !rec->no_buildid_cache)
disable = false;
if (disable) {
rec->no_buildid = true;
rec->no_buildid_cache = true;
disable_buildid_cache();
}
}
if (record.opts.overwrite)
record.opts.tail_synthesize = true;
if (rec->evlist->nr_entries == 0 &&
perf_evlist__add_default(rec->evlist) < 0) {
pr_err("Not enough memory for event selector list\n");
goto out;
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
goto out;
}
rec->opts.ignore_missing_thread = rec->opts.target.uid != UINT_MAX;
err = -ENOMEM;
if (perf_evlist__create_maps(rec->evlist, &rec->opts.target) < 0)
usage_with_options(record_usage, record_options);
err = auxtrace_record__options(rec->itr, rec->evlist, &rec->opts);
if (err)
goto out;
if (rec->opts.full_auxtrace)
rec->buildid_all = true;
if (record_opts__config(&rec->opts)) {
err = -EINVAL;
goto out;
}
err = __cmd_record(&record, argc, argv);
out:
perf_evlist__delete(rec->evlist);
symbol__exit();
auxtrace_record__free(rec->itr);
return err;
}
static void snapshot_sig_handler(int sig __maybe_unused)
{
struct record *rec = &record;
if (trigger_is_ready(&auxtrace_snapshot_trigger)) {
trigger_hit(&auxtrace_snapshot_trigger);
auxtrace_record__snapshot_started = 1;
if (auxtrace_record__snapshot_start(record.itr))
trigger_error(&auxtrace_snapshot_trigger);
}
if (switch_output_signal(rec))
trigger_hit(&switch_output_trigger);
}
static void alarm_sig_handler(int sig __maybe_unused)
{
struct record *rec = &record;
if (switch_output_time(rec))
trigger_hit(&switch_output_trigger);
}
