static inline void diff_timespec(struct timespec *r, struct timespec *a,
struct timespec *b)
{
r->tv_sec = a->tv_sec - b->tv_sec;
if (a->tv_nsec < b->tv_nsec) {
r->tv_nsec = a->tv_nsec + 1000000000L - b->tv_nsec;
r->tv_sec--;
} else {
r->tv_nsec = a->tv_nsec - b->tv_nsec ;
}
}
static void perf_stat__reset_stats(void)
{
perf_evlist__reset_stats(evsel_list);
perf_stat__reset_shadow_stats();
}
static int create_perf_stat_counter(struct perf_evsel *evsel)
{
struct perf_event_attr *attr = &evsel->attr;
if (stat_config.scale)
attr->read_format = PERF_FORMAT_TOTAL_TIME_ENABLED |
PERF_FORMAT_TOTAL_TIME_RUNNING;
attr->inherit = !no_inherit;
attr->sample_period = 0;
if (!(STAT_RECORD && perf_stat.file.is_pipe))
attr->sample_type = PERF_SAMPLE_IDENTIFIER;
if (perf_evsel__is_group_leader(evsel)) {
attr->disabled = 1;
if (target__none(&target) && !initial_delay)
attr->enable_on_exec = 1;
}
if (target__has_cpu(&target))
return perf_evsel__open_per_cpu(evsel, perf_evsel__cpus(evsel));
return perf_evsel__open_per_thread(evsel, evsel_list->threads);
}
static inline int nsec_counter(struct perf_evsel *evsel)
{
if (perf_evsel__match(evsel, SOFTWARE, SW_CPU_CLOCK) ||
perf_evsel__match(evsel, SOFTWARE, SW_TASK_CLOCK))
return 1;
return 0;
}
static int process_synthesized_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_sample *sample __maybe_unused,
struct machine *machine __maybe_unused)
{
if (perf_data_file__write(&perf_stat.file, event, event->header.size) < 0) {
pr_err("failed to write perf data, error: %m\n");
return -1;
}
perf_stat.bytes_written += event->header.size;
return 0;
}
static int write_stat_round_event(u64 tm, u64 type)
{
return perf_event__synthesize_stat_round(NULL, tm, type,
process_synthesized_event,
NULL);
}
static int
perf_evsel__write_stat_event(struct perf_evsel *counter, u32 cpu, u32 thread,
struct perf_counts_values *count)
{
struct perf_sample_id *sid = SID(counter, cpu, thread);
return perf_event__synthesize_stat(NULL, cpu, thread, sid->id, count,
process_synthesized_event, NULL);
}
static int read_counter(struct perf_evsel *counter)
{
int nthreads = thread_map__nr(evsel_list->threads);
int ncpus = perf_evsel__nr_cpus(counter);
int cpu, thread;
if (!counter->supported)
return -ENOENT;
if (counter->system_wide)
nthreads = 1;
for (thread = 0; thread < nthreads; thread++) {
for (cpu = 0; cpu < ncpus; cpu++) {
struct perf_counts_values *count;
count = perf_counts(counter->counts, cpu, thread);
if (perf_evsel__read(counter, cpu, thread, count))
return -1;
if (STAT_RECORD) {
if (perf_evsel__write_stat_event(counter, cpu, thread, count)) {
pr_err("failed to write stat event\n");
return -1;
}
}
}
}
return 0;
}
static void read_counters(bool close_counters)
{
struct perf_evsel *counter;
evlist__for_each(evsel_list, counter) {
if (read_counter(counter))
pr_debug("failed to read counter %s\n", counter->name);
if (perf_stat_process_counter(&stat_config, counter))
pr_warning("failed to process counter %s\n", counter->name);
if (close_counters) {
perf_evsel__close_fd(counter, perf_evsel__nr_cpus(counter),
thread_map__nr(evsel_list->threads));
}
}
}
static void process_interval(void)
{
struct timespec ts, rs;
read_counters(false);
clock_gettime(CLOCK_MONOTONIC, &ts);
diff_timespec(&rs, &ts, &ref_time);
if (STAT_RECORD) {
if (WRITE_STAT_ROUND_EVENT(rs.tv_sec * NSECS_PER_SEC + rs.tv_nsec, INTERVAL))
pr_err("failed to write stat round event\n");
}
print_counters(&rs, 0, NULL);
}
static void enable_counters(void)
{
if (initial_delay)
usleep(initial_delay * 1000);
if (!target__none(&target) || initial_delay)
perf_evlist__enable(evsel_list);
}
static void workload_exec_failed_signal(int signo __maybe_unused, siginfo_t *info,
void *ucontext __maybe_unused)
{
workload_exec_errno = info->si_value.sival_int;
}
static bool has_unit(struct perf_evsel *counter)
{
return counter->unit && *counter->unit;
}
static bool has_scale(struct perf_evsel *counter)
{
return counter->scale != 1;
}
static int perf_stat_synthesize_config(bool is_pipe)
{
struct perf_evsel *counter;
int err;
if (is_pipe) {
err = perf_event__synthesize_attrs(NULL, perf_stat.session,
process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize attrs.\n");
return err;
}
}
evlist__for_each(evsel_list, counter) {
if (!counter->supported)
continue;
if (has_unit(counter)) {
err = perf_event__synthesize_event_update_unit(NULL, counter, process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize evsel unit.\n");
return err;
}
}
if (has_scale(counter)) {
err = perf_event__synthesize_event_update_scale(NULL, counter, process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize evsel scale.\n");
return err;
}
}
if (counter->own_cpus) {
err = perf_event__synthesize_event_update_cpus(NULL, counter, process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize evsel scale.\n");
return err;
}
}
if (is_pipe) {
err = perf_event__synthesize_event_update_name(NULL, counter, process_synthesized_event);
if (err < 0) {
pr_err("Couldn't synthesize evsel name.\n");
return err;
}
}
}
err = perf_event__synthesize_thread_map2(NULL, evsel_list->threads,
process_synthesized_event,
NULL);
if (err < 0) {
pr_err("Couldn't synthesize thread map.\n");
return err;
}
err = perf_event__synthesize_cpu_map(NULL, evsel_list->cpus,
process_synthesized_event, NULL);
if (err < 0) {
pr_err("Couldn't synthesize thread map.\n");
return err;
}
err = perf_event__synthesize_stat_config(NULL, &stat_config,
process_synthesized_event, NULL);
if (err < 0) {
pr_err("Couldn't synthesize config.\n");
return err;
}
return 0;
}
static int __store_counter_ids(struct perf_evsel *counter,
struct cpu_map *cpus,
struct thread_map *threads)
{
int cpu, thread;
for (cpu = 0; cpu < cpus->nr; cpu++) {
for (thread = 0; thread < threads->nr; thread++) {
int fd = FD(counter, cpu, thread);
if (perf_evlist__id_add_fd(evsel_list, counter,
cpu, thread, fd) < 0)
return -1;
}
}
return 0;
}
static int store_counter_ids(struct perf_evsel *counter)
{
struct cpu_map *cpus = counter->cpus;
struct thread_map *threads = counter->threads;
if (perf_evsel__alloc_id(counter, cpus->nr, threads->nr))
return -ENOMEM;
return __store_counter_ids(counter, cpus, threads);
}
static int __run_perf_stat(int argc, const char **argv)
{
int interval = stat_config.interval;
char msg[512];
unsigned long long t0, t1;
struct perf_evsel *counter;
struct timespec ts;
size_t l;
int status = 0;
const bool forks = (argc > 0);
bool is_pipe = STAT_RECORD ? perf_stat.file.is_pipe : false;
if (interval) {
ts.tv_sec = interval / 1000;
ts.tv_nsec = (interval % 1000) * 1000000;
} else {
ts.tv_sec = 1;
ts.tv_nsec = 0;
}
if (forks) {
if (perf_evlist__prepare_workload(evsel_list, &target, argv, is_pipe,
workload_exec_failed_signal) < 0) {
perror("failed to prepare workload");
return -1;
}
child_pid = evsel_list->workload.pid;
}
if (group)
perf_evlist__set_leader(evsel_list);
evlist__for_each(evsel_list, counter) {
if (create_perf_stat_counter(counter) < 0) {
if (errno == EINVAL || errno == ENOSYS ||
errno == ENOENT || errno == EOPNOTSUPP ||
errno == ENXIO) {
if (verbose)
ui__warning("%s event is not supported by the kernel.\n",
perf_evsel__name(counter));
counter->supported = false;
if ((counter->leader != counter) ||
!(counter->leader->nr_members > 1))
continue;
}
perf_evsel__open_strerror(counter, &target,
errno, msg, sizeof(msg));
ui__error("%s\n", msg);
if (child_pid != -1)
kill(child_pid, SIGTERM);
return -1;
}
counter->supported = true;
l = strlen(counter->unit);
if (l > unit_width)
unit_width = l;
if (STAT_RECORD && store_counter_ids(counter))
return -1;
}
if (perf_evlist__apply_filters(evsel_list, &counter)) {
error("failed to set filter \"%s\" on event %s with %d (%s)\n",
counter->filter, perf_evsel__name(counter), errno,
strerror_r(errno, msg, sizeof(msg)));
return -1;
}
if (STAT_RECORD) {
int err, fd = perf_data_file__fd(&perf_stat.file);
if (is_pipe) {
err = perf_header__write_pipe(perf_data_file__fd(&perf_stat.file));
} else {
err = perf_session__write_header(perf_stat.session, evsel_list,
fd, false);
}
if (err < 0)
return err;
err = perf_stat_synthesize_config(is_pipe);
if (err < 0)
return err;
}
t0 = rdclock();
clock_gettime(CLOCK_MONOTONIC, &ref_time);
if (forks) {
perf_evlist__start_workload(evsel_list);
enable_counters();
if (interval) {
while (!waitpid(child_pid, &status, WNOHANG)) {
nanosleep(&ts, NULL);
process_interval();
}
}
wait(&status);
if (workload_exec_errno) {
const char *emsg = strerror_r(workload_exec_errno, msg, sizeof(msg));
pr_err("Workload failed: %s\n", emsg);
return -1;
}
if (WIFSIGNALED(status))
psignal(WTERMSIG(status), argv[0]);
} else {
enable_counters();
while (!done) {
nanosleep(&ts, NULL);
if (interval)
process_interval();
}
}
t1 = rdclock();
update_stats(&walltime_nsecs_stats, t1 - t0);
read_counters(true);
return WEXITSTATUS(status);
}
static int run_perf_stat(int argc, const char **argv)
{
int ret;
if (pre_cmd) {
ret = system(pre_cmd);
if (ret)
return ret;
}
if (sync_run)
sync();
ret = __run_perf_stat(argc, argv);
if (ret)
return ret;
if (post_cmd) {
ret = system(post_cmd);
if (ret)
return ret;
}
return ret;
}
static void print_running(u64 run, u64 ena)
{
if (csv_output) {
fprintf(stat_config.output, "%s%" PRIu64 "%s%.2f",
csv_sep,
run,
csv_sep,
ena ? 100.0 * run / ena : 100.0);
} else if (run != ena) {
fprintf(stat_config.output, " (%.2f%%)", 100.0 * run / ena);
}
}
static void print_noise_pct(double total, double avg)
{
double pct = rel_stddev_stats(total, avg);
if (csv_output)
fprintf(stat_config.output, "%s%.2f%%", csv_sep, pct);
else if (pct)
fprintf(stat_config.output, " ( +-%6.2f%% )", pct);
}
static void print_noise(struct perf_evsel *evsel, double avg)
{
struct perf_stat_evsel *ps;
if (run_count == 1)
return;
ps = evsel->priv;
print_noise_pct(stddev_stats(&ps->res_stats[0]), avg);
}
static void aggr_printout(struct perf_evsel *evsel, int id, int nr)
{
switch (stat_config.aggr_mode) {
case AGGR_CORE:
fprintf(stat_config.output, "S%d-C%*d%s%*d%s",
cpu_map__id_to_socket(id),
csv_output ? 0 : -8,
cpu_map__id_to_cpu(id),
csv_sep,
csv_output ? 0 : 4,
nr,
csv_sep);
break;
case AGGR_SOCKET:
fprintf(stat_config.output, "S%*d%s%*d%s",
csv_output ? 0 : -5,
id,
csv_sep,
csv_output ? 0 : 4,
nr,
csv_sep);
break;
case AGGR_NONE:
fprintf(stat_config.output, "CPU%*d%s",
csv_output ? 0 : -4,
perf_evsel__cpus(evsel)->map[id], csv_sep);
break;
case AGGR_THREAD:
fprintf(stat_config.output, "%*s-%*d%s",
csv_output ? 0 : 16,
thread_map__comm(evsel->threads, id),
csv_output ? 0 : -8,
thread_map__pid(evsel->threads, id),
csv_sep);
break;
case AGGR_GLOBAL:
case AGGR_UNSET:
default:
break;
}
}
static void nsec_printout(int id, int nr, struct perf_evsel *evsel, double avg)
{
FILE *output = stat_config.output;
double msecs = avg / 1e6;
const char *fmt_v, *fmt_n;
char name[25];
fmt_v = csv_output ? "%.6f%s" : "%18.6f%s";
fmt_n = csv_output ? "%s" : "%-25s";
aggr_printout(evsel, id, nr);
scnprintf(name, sizeof(name), "%s%s",
perf_evsel__name(evsel), csv_output ? "" : " (msec)");
fprintf(output, fmt_v, msecs, csv_sep);
if (csv_output)
fprintf(output, "%s%s", evsel->unit, csv_sep);
else
fprintf(output, "%-*s%s", unit_width, evsel->unit, csv_sep);
fprintf(output, fmt_n, name);
if (evsel->cgrp)
fprintf(output, "%s%s", csv_sep, evsel->cgrp->name);
}
static void abs_printout(int id, int nr, struct perf_evsel *evsel, double avg)
{
FILE *output = stat_config.output;
double sc = evsel->scale;
const char *fmt;
if (csv_output) {
fmt = sc != 1.0 ? "%.2f%s" : "%.0f%s";
} else {
if (big_num)
fmt = sc != 1.0 ? "%'18.2f%s" : "%'18.0f%s";
else
fmt = sc != 1.0 ? "%18.2f%s" : "%18.0f%s";
}
aggr_printout(evsel, id, nr);
fprintf(output, fmt, avg, csv_sep);
if (evsel->unit)
fprintf(output, "%-*s%s",
csv_output ? 0 : unit_width,
evsel->unit, csv_sep);
fprintf(output, "%-*s", csv_output ? 0 : 25, perf_evsel__name(evsel));
if (evsel->cgrp)
fprintf(output, "%s%s", csv_sep, evsel->cgrp->name);
}
static void printout(int id, int nr, struct perf_evsel *counter, double uval)
{
int cpu = cpu_map__id_to_cpu(id);
if (stat_config.aggr_mode == AGGR_GLOBAL)
cpu = 0;
if (nsec_counter(counter))
nsec_printout(id, nr, counter, uval);
else
abs_printout(id, nr, counter, uval);
if (!csv_output && !stat_config.interval)
perf_stat__print_shadow_stats(stat_config.output, counter,
uval, cpu,
stat_config.aggr_mode);
}
static void print_aggr(char *prefix)
{
FILE *output = stat_config.output;
struct perf_evsel *counter;
int cpu, s, s2, id, nr;
double uval;
u64 ena, run, val;
if (!(aggr_map || aggr_get_id))
return;
for (s = 0; s < aggr_map->nr; s++) {
id = aggr_map->map[s];
evlist__for_each(evsel_list, counter) {
val = ena = run = 0;
nr = 0;
for (cpu = 0; cpu < perf_evsel__nr_cpus(counter); cpu++) {
s2 = aggr_get_id(perf_evsel__cpus(counter), cpu);
if (s2 != id)
continue;
val += perf_counts(counter->counts, cpu, 0)->val;
ena += perf_counts(counter->counts, cpu, 0)->ena;
run += perf_counts(counter->counts, cpu, 0)->run;
nr++;
}
if (prefix)
fprintf(output, "%s", prefix);
if (run == 0 || ena == 0) {
aggr_printout(counter, id, nr);
fprintf(output, "%*s%s",
csv_output ? 0 : 18,
counter->supported ? CNTR_NOT_COUNTED : CNTR_NOT_SUPPORTED,
csv_sep);
fprintf(output, "%-*s%s",
csv_output ? 0 : unit_width,
counter->unit, csv_sep);
fprintf(output, "%*s",
csv_output ? 0 : -25,
perf_evsel__name(counter));
if (counter->cgrp)
fprintf(output, "%s%s",
csv_sep, counter->cgrp->name);
print_running(run, ena);
fputc('\n', output);
continue;
}
uval = val * counter->scale;
printout(id, nr, counter, uval);
if (!csv_output)
print_noise(counter, 1.0);
print_running(run, ena);
fputc('\n', output);
}
}
}
static void print_aggr_thread(struct perf_evsel *counter, char *prefix)
{
FILE *output = stat_config.output;
int nthreads = thread_map__nr(counter->threads);
int ncpus = cpu_map__nr(counter->cpus);
int cpu, thread;
double uval;
for (thread = 0; thread < nthreads; thread++) {
u64 ena = 0, run = 0, val = 0;
for (cpu = 0; cpu < ncpus; cpu++) {
val += perf_counts(counter->counts, cpu, thread)->val;
ena += perf_counts(counter->counts, cpu, thread)->ena;
run += perf_counts(counter->counts, cpu, thread)->run;
}
if (prefix)
fprintf(output, "%s", prefix);
uval = val * counter->scale;
printout(thread, 0, counter, uval);
if (!csv_output)
print_noise(counter, 1.0);
print_running(run, ena);
fputc('\n', output);
}
}
static void print_counter_aggr(struct perf_evsel *counter, char *prefix)
{
FILE *output = stat_config.output;
struct perf_stat_evsel *ps = counter->priv;
double avg = avg_stats(&ps->res_stats[0]);
int scaled = counter->counts->scaled;
double uval;
double avg_enabled, avg_running;
avg_enabled = avg_stats(&ps->res_stats[1]);
avg_running = avg_stats(&ps->res_stats[2]);
if (prefix)
fprintf(output, "%s", prefix);
if (scaled == -1 || !counter->supported) {
fprintf(output, "%*s%s",
csv_output ? 0 : 18,
counter->supported ? CNTR_NOT_COUNTED : CNTR_NOT_SUPPORTED,
csv_sep);
fprintf(output, "%-*s%s",
csv_output ? 0 : unit_width,
counter->unit, csv_sep);
fprintf(output, "%*s",
csv_output ? 0 : -25,
perf_evsel__name(counter));
if (counter->cgrp)
fprintf(output, "%s%s", csv_sep, counter->cgrp->name);
print_running(avg_running, avg_enabled);
fputc('\n', output);
return;
}
uval = avg * counter->scale;
printout(-1, 0, counter, uval);
print_noise(counter, avg);
print_running(avg_running, avg_enabled);
fprintf(output, "\n");
}
static void print_counter(struct perf_evsel *counter, char *prefix)
{
FILE *output = stat_config.output;
u64 ena, run, val;
double uval;
int cpu;
for (cpu = 0; cpu < perf_evsel__nr_cpus(counter); cpu++) {
val = perf_counts(counter->counts, cpu, 0)->val;
ena = perf_counts(counter->counts, cpu, 0)->ena;
run = perf_counts(counter->counts, cpu, 0)->run;
if (prefix)
fprintf(output, "%s", prefix);
if (run == 0 || ena == 0) {
fprintf(output, "CPU%*d%s%*s%s",
csv_output ? 0 : -4,
perf_evsel__cpus(counter)->map[cpu], csv_sep,
csv_output ? 0 : 18,
counter->supported ? CNTR_NOT_COUNTED : CNTR_NOT_SUPPORTED,
csv_sep);
fprintf(output, "%-*s%s",
csv_output ? 0 : unit_width,
counter->unit, csv_sep);
fprintf(output, "%*s",
csv_output ? 0 : -25,
perf_evsel__name(counter));
if (counter->cgrp)
fprintf(output, "%s%s",
csv_sep, counter->cgrp->name);
print_running(run, ena);
fputc('\n', output);
continue;
}
uval = val * counter->scale;
printout(cpu, 0, counter, uval);
if (!csv_output)
print_noise(counter, 1.0);
print_running(run, ena);
fputc('\n', output);
}
}
static void print_interval(char *prefix, struct timespec *ts)
{
FILE *output = stat_config.output;
static int num_print_interval;
sprintf(prefix, "%6lu.%09lu%s", ts->tv_sec, ts->tv_nsec, csv_sep);
if (num_print_interval == 0 && !csv_output) {
switch (stat_config.aggr_mode) {
case AGGR_SOCKET:
fprintf(output, "# time socket cpus counts %*s events\n", unit_width, "unit");
break;
case AGGR_CORE:
fprintf(output, "# time core cpus counts %*s events\n", unit_width, "unit");
break;
case AGGR_NONE:
fprintf(output, "# time CPU counts %*s events\n", unit_width, "unit");
break;
case AGGR_THREAD:
fprintf(output, "# time comm-pid counts %*s events\n", unit_width, "unit");
break;
case AGGR_GLOBAL:
default:
fprintf(output, "# time counts %*s events\n", unit_width, "unit");
case AGGR_UNSET:
break;
}
}
if (++num_print_interval == 25)
num_print_interval = 0;
}
static void print_header(int argc, const char **argv)
{
FILE *output = stat_config.output;
int i;
fflush(stdout);
if (!csv_output) {
fprintf(output, "\n");
fprintf(output, " Performance counter stats for ");
if (target.system_wide)
fprintf(output, "\'system wide");
else if (target.cpu_list)
fprintf(output, "\'CPU(s) %s", target.cpu_list);
else if (!target__has_task(&target)) {
fprintf(output, "\'%s", argv ? argv[0] : "pipe");
for (i = 1; argv && (i < argc); i++)
fprintf(output, " %s", argv[i]);
} else if (target.pid)
fprintf(output, "process id \'%s", target.pid);
else
fprintf(output, "thread id \'%s", target.tid);
fprintf(output, "\'");
if (run_count > 1)
fprintf(output, " (%d runs)", run_count);
fprintf(output, ":\n\n");
}
}
static void print_footer(void)
{
FILE *output = stat_config.output;
if (!null_run)
fprintf(output, "\n");
fprintf(output, " %17.9f seconds time elapsed",
avg_stats(&walltime_nsecs_stats)/1e9);
if (run_count > 1) {
fprintf(output, " ");
print_noise_pct(stddev_stats(&walltime_nsecs_stats),
avg_stats(&walltime_nsecs_stats));
}
fprintf(output, "\n\n");
}
static void print_counters(struct timespec *ts, int argc, const char **argv)
{
int interval = stat_config.interval;
struct perf_evsel *counter;
char buf[64], *prefix = NULL;
if (STAT_RECORD && perf_stat.file.is_pipe)
return;
if (interval)
print_interval(prefix = buf, ts);
else
print_header(argc, argv);
switch (stat_config.aggr_mode) {
case AGGR_CORE:
case AGGR_SOCKET:
print_aggr(prefix);
break;
case AGGR_THREAD:
evlist__for_each(evsel_list, counter)
print_aggr_thread(counter, prefix);
break;
case AGGR_GLOBAL:
evlist__for_each(evsel_list, counter)
print_counter_aggr(counter, prefix);
break;
case AGGR_NONE:
evlist__for_each(evsel_list, counter)
print_counter(counter, prefix);
break;
case AGGR_UNSET:
default:
break;
}
if (!interval && !csv_output)
print_footer();
fflush(stat_config.output);
}
static void skip_signal(int signo)
{
if ((child_pid == -1) || stat_config.interval)
done = 1;
signr = signo;
child_pid = -1;
}
static void sig_atexit(void)
{
sigset_t set, oset;
sigemptyset(&set);
sigaddset(&set, SIGCHLD);
sigprocmask(SIG_BLOCK, &set, &oset);
if (child_pid != -1)
kill(child_pid, SIGTERM);
sigprocmask(SIG_SETMASK, &oset, NULL);
if (signr == -1)
return;
signal(signr, SIG_DFL);
kill(getpid(), signr);
}
static int stat__set_big_num(const struct option *opt __maybe_unused,
const char *s __maybe_unused, int unset)
{
big_num_opt = unset ? 0 : 1;
return 0;
}
static int perf_stat__get_socket(struct cpu_map *map, int cpu)
{
return cpu_map__get_socket(map, cpu, NULL);
}
static int perf_stat__get_core(struct cpu_map *map, int cpu)
{
return cpu_map__get_core(map, cpu, NULL);
}
static int cpu_map__get_max(struct cpu_map *map)
{
int i, max = -1;
for (i = 0; i < map->nr; i++) {
if (map->map[i] > max)
max = map->map[i];
}
return max;
}
static int perf_stat__get_aggr(aggr_get_id_t get_id, struct cpu_map *map, int idx)
{
int cpu;
if (idx >= map->nr)
return -1;
cpu = map->map[idx];
if (cpus_aggr_map->map[cpu] == -1)
cpus_aggr_map->map[cpu] = get_id(map, idx);
return cpus_aggr_map->map[cpu];
}
static int perf_stat__get_socket_cached(struct cpu_map *map, int idx)
{
return perf_stat__get_aggr(perf_stat__get_socket, map, idx);
}
static int perf_stat__get_core_cached(struct cpu_map *map, int idx)
{
return perf_stat__get_aggr(perf_stat__get_core, map, idx);
}
static int perf_stat_init_aggr_mode(void)
{
int nr;
switch (stat_config.aggr_mode) {
case AGGR_SOCKET:
if (cpu_map__build_socket_map(evsel_list->cpus, &aggr_map)) {
perror("cannot build socket map");
return -1;
}
aggr_get_id = perf_stat__get_socket_cached;
break;
case AGGR_CORE:
if (cpu_map__build_core_map(evsel_list->cpus, &aggr_map)) {
perror("cannot build core map");
return -1;
}
aggr_get_id = perf_stat__get_core_cached;
break;
case AGGR_NONE:
case AGGR_GLOBAL:
case AGGR_THREAD:
case AGGR_UNSET:
default:
break;
}
nr = cpu_map__get_max(evsel_list->cpus);
cpus_aggr_map = cpu_map__empty_new(nr + 1);
return cpus_aggr_map ? 0 : -ENOMEM;
}
static void perf_stat__exit_aggr_mode(void)
{
cpu_map__put(aggr_map);
cpu_map__put(cpus_aggr_map);
aggr_map = NULL;
cpus_aggr_map = NULL;
}
static inline int perf_env__get_cpu(struct perf_env *env, struct cpu_map *map, int idx)
{
int cpu;
if (idx > map->nr)
return -1;
cpu = map->map[idx];
if (cpu >= env->nr_cpus_online)
return -1;
return cpu;
}
static int perf_env__get_socket(struct cpu_map *map, int idx, void *data)
{
struct perf_env *env = data;
int cpu = perf_env__get_cpu(env, map, idx);
return cpu == -1 ? -1 : env->cpu[cpu].socket_id;
}
static int perf_env__get_core(struct cpu_map *map, int idx, void *data)
{
struct perf_env *env = data;
int core = -1, cpu = perf_env__get_cpu(env, map, idx);
if (cpu != -1) {
int socket_id = env->cpu[cpu].socket_id;
core = (socket_id << 16) | (env->cpu[cpu].core_id & 0xffff);
}
return core;
}
static int perf_env__build_socket_map(struct perf_env *env, struct cpu_map *cpus,
struct cpu_map **sockp)
{
return cpu_map__build_map(cpus, sockp, perf_env__get_socket, env);
}
static int perf_env__build_core_map(struct perf_env *env, struct cpu_map *cpus,
struct cpu_map **corep)
{
return cpu_map__build_map(cpus, corep, perf_env__get_core, env);
}
static int perf_stat__get_socket_file(struct cpu_map *map, int idx)
{
return perf_env__get_socket(map, idx, &perf_stat.session->header.env);
}
static int perf_stat__get_core_file(struct cpu_map *map, int idx)
{
return perf_env__get_core(map, idx, &perf_stat.session->header.env);
}
static int perf_stat_init_aggr_mode_file(struct perf_stat *st)
{
struct perf_env *env = &st->session->header.env;
switch (stat_config.aggr_mode) {
case AGGR_SOCKET:
if (perf_env__build_socket_map(env, evsel_list->cpus, &aggr_map)) {
perror("cannot build socket map");
return -1;
}
aggr_get_id = perf_stat__get_socket_file;
break;
case AGGR_CORE:
if (perf_env__build_core_map(env, evsel_list->cpus, &aggr_map)) {
perror("cannot build core map");
return -1;
}
aggr_get_id = perf_stat__get_core_file;
break;
case AGGR_NONE:
case AGGR_GLOBAL:
case AGGR_THREAD:
case AGGR_UNSET:
default:
break;
}
return 0;
}
static int add_default_attributes(void)
{
struct perf_event_attr default_attrs[] = {
{ .type = PERF_TYPE_SOFTWARE, .config = PERF_COUNT_SW_TASK_CLOCK },
{ .type = PERF_TYPE_SOFTWARE, .config = PERF_COUNT_SW_CONTEXT_SWITCHES },
{ .type = PERF_TYPE_SOFTWARE, .config = PERF_COUNT_SW_CPU_MIGRATIONS },
{ .type = PERF_TYPE_SOFTWARE, .config = PERF_COUNT_SW_PAGE_FAULTS },
{ .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_CPU_CYCLES },
{ .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_STALLED_CYCLES_FRONTEND },
{ .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_STALLED_CYCLES_BACKEND },
{ .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_INSTRUCTIONS },
{ .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_BRANCH_INSTRUCTIONS },
{ .type = PERF_TYPE_HARDWARE, .config = PERF_COUNT_HW_BRANCH_MISSES },
};
struct perf_event_attr detailed_attrs[] = {
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_L1D << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_L1D << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_MISS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_LL << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_LL << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_MISS << 16) },
};
struct perf_event_attr very_detailed_attrs[] = {
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_L1I << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_L1I << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_MISS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_DTLB << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_DTLB << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_MISS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_ITLB << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_ITLB << 0 |
(PERF_COUNT_HW_CACHE_OP_READ << 8) |
(PERF_COUNT_HW_CACHE_RESULT_MISS << 16) },
};
struct perf_event_attr very_very_detailed_attrs[] = {
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_L1D << 0 |
(PERF_COUNT_HW_CACHE_OP_PREFETCH << 8) |
(PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16) },
{ .type = PERF_TYPE_HW_CACHE,
.config =
PERF_COUNT_HW_CACHE_L1D << 0 |
(PERF_COUNT_HW_CACHE_OP_PREFETCH << 8) |
(PERF_COUNT_HW_CACHE_RESULT_MISS << 16) },
};
if (null_run)
return 0;
if (transaction_run) {
int err;
if (pmu_have_event("cpu", "cycles-ct") &&
pmu_have_event("cpu", "el-start"))
err = parse_events(evsel_list, transaction_attrs, NULL);
else
err = parse_events(evsel_list, transaction_limited_attrs, NULL);
if (err) {
fprintf(stderr, "Cannot set up transaction events\n");
return -1;
}
return 0;
}
if (!evsel_list->nr_entries) {
if (perf_evlist__add_default_attrs(evsel_list, default_attrs) < 0)
return -1;
}
if (detailed_run < 1)
return 0;
if (perf_evlist__add_default_attrs(evsel_list, detailed_attrs) < 0)
return -1;
if (detailed_run < 2)
return 0;
if (perf_evlist__add_default_attrs(evsel_list, very_detailed_attrs) < 0)
return -1;
if (detailed_run < 3)
return 0;
return perf_evlist__add_default_attrs(evsel_list, very_very_detailed_attrs);
}
static void init_features(struct perf_session *session)
{
int feat;
for (feat = HEADER_FIRST_FEATURE; feat < HEADER_LAST_FEATURE; feat++)
perf_header__set_feat(&session->header, feat);
perf_header__clear_feat(&session->header, HEADER_BUILD_ID);
perf_header__clear_feat(&session->header, HEADER_TRACING_DATA);
perf_header__clear_feat(&session->header, HEADER_BRANCH_STACK);
perf_header__clear_feat(&session->header, HEADER_AUXTRACE);
}
static int __cmd_record(int argc, const char **argv)
{
struct perf_session *session;
struct perf_data_file *file = &perf_stat.file;
argc = parse_options(argc, argv, stat_options, stat_record_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (output_name)
file->path = output_name;
if (run_count != 1 || forever) {
pr_err("Cannot use -r option with perf stat record.\n");
return -1;
}
session = perf_session__new(file, false, NULL);
if (session == NULL) {
pr_err("Perf session creation failed.\n");
return -1;
}
init_features(session);
session->evlist = evsel_list;
perf_stat.session = session;
perf_stat.record = true;
return argc;
}
static int process_stat_round_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_session *session)
{
struct stat_round_event *round = &event->stat_round;
struct perf_evsel *counter;
struct timespec tsh, *ts = NULL;
const char **argv = session->header.env.cmdline_argv;
int argc = session->header.env.nr_cmdline;
evlist__for_each(evsel_list, counter)
perf_stat_process_counter(&stat_config, counter);
if (round->type == PERF_STAT_ROUND_TYPE__FINAL)
update_stats(&walltime_nsecs_stats, round->time);
if (stat_config.interval && round->time) {
tsh.tv_sec = round->time / NSECS_PER_SEC;
tsh.tv_nsec = round->time % NSECS_PER_SEC;
ts = &tsh;
}
print_counters(ts, argc, argv);
return 0;
}
static
int process_stat_config_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_session *session __maybe_unused)
{
struct perf_stat *st = container_of(tool, struct perf_stat, tool);
perf_event__read_stat_config(&stat_config, &event->stat_config);
if (cpu_map__empty(st->cpus)) {
if (st->aggr_mode != AGGR_UNSET)
pr_warning("warning: processing task data, aggregation mode not set\n");
return 0;
}
if (st->aggr_mode != AGGR_UNSET)
stat_config.aggr_mode = st->aggr_mode;
if (perf_stat.file.is_pipe)
perf_stat_init_aggr_mode();
else
perf_stat_init_aggr_mode_file(st);
return 0;
}
static int set_maps(struct perf_stat *st)
{
if (!st->cpus || !st->threads)
return 0;
if (WARN_ONCE(st->maps_allocated, "stats double allocation\n"))
return -EINVAL;
perf_evlist__set_maps(evsel_list, st->cpus, st->threads);
if (perf_evlist__alloc_stats(evsel_list, true))
return -ENOMEM;
st->maps_allocated = true;
return 0;
}
static
int process_thread_map_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_session *session __maybe_unused)
{
struct perf_stat *st = container_of(tool, struct perf_stat, tool);
if (st->threads) {
pr_warning("Extra thread map event, ignoring.\n");
return 0;
}
st->threads = thread_map__new_event(&event->thread_map);
if (!st->threads)
return -ENOMEM;
return set_maps(st);
}
static
int process_cpu_map_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_session *session __maybe_unused)
{
struct perf_stat *st = container_of(tool, struct perf_stat, tool);
struct cpu_map *cpus;
if (st->cpus) {
pr_warning("Extra cpu map event, ignoring.\n");
return 0;
}
cpus = cpu_map__new_data(&event->cpu_map.data);
if (!cpus)
return -ENOMEM;
st->cpus = cpus;
return set_maps(st);
}
static int __cmd_report(int argc, const char **argv)
{
struct perf_session *session;
const struct option options[] = {
OPT_STRING('i', "input", &input_name, "file", "input file name"),
OPT_SET_UINT(0, "per-socket", &perf_stat.aggr_mode,
"aggregate counts per processor socket", AGGR_SOCKET),
OPT_SET_UINT(0, "per-core", &perf_stat.aggr_mode,
"aggregate counts per physical processor core", AGGR_CORE),
OPT_SET_UINT('A', "no-aggr", &perf_stat.aggr_mode,
"disable CPU count aggregation", AGGR_NONE),
OPT_END()
};
struct stat st;
int ret;
argc = parse_options(argc, argv, options, stat_report_usage, 0);
if (!input_name || !strlen(input_name)) {
if (!fstat(STDIN_FILENO, &st) && S_ISFIFO(st.st_mode))
input_name = "-";
else
input_name = "perf.data";
}
perf_stat.file.path = input_name;
perf_stat.file.mode = PERF_DATA_MODE_READ;
session = perf_session__new(&perf_stat.file, false, &perf_stat.tool);
if (session == NULL)
return -1;
perf_stat.session = session;
stat_config.output = stderr;
evsel_list = session->evlist;
ret = perf_session__process_events(session);
if (ret)
return ret;
perf_session__delete(session);
return 0;
}
int cmd_stat(int argc, const char **argv, const char *prefix __maybe_unused)
{
const char * const stat_usage[] = {
"perf stat [<options>] [<command>]",
NULL
};
int status = -EINVAL, run_idx;
const char *mode;
FILE *output = stderr;
unsigned int interval;
const char * const stat_subcommands[] = { "record", "report" };
setlocale(LC_ALL, "");
evsel_list = perf_evlist__new();
if (evsel_list == NULL)
return -ENOMEM;
argc = parse_options_subcommand(argc, argv, stat_options, stat_subcommands,
(const char **) stat_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (csv_sep) {
csv_output = true;
if (!strcmp(csv_sep, "\\t"))
csv_sep = "\t";
} else
csv_sep = DEFAULT_SEPARATOR;
if (argc && !strncmp(argv[0], "rec", 3)) {
argc = __cmd_record(argc, argv);
if (argc < 0)
return -1;
} else if (argc && !strncmp(argv[0], "rep", 3))
return __cmd_report(argc, argv);
interval = stat_config.interval;
if (!STAT_RECORD && output_name && strcmp(output_name, "-"))
output = NULL;
if (output_name && output_fd) {
fprintf(stderr, "cannot use both --output and --log-fd\n");
parse_options_usage(stat_usage, stat_options, "o", 1);
parse_options_usage(NULL, stat_options, "log-fd", 0);
goto out;
}
if (output_fd < 0) {
fprintf(stderr, "argument to --log-fd must be a > 0\n");
parse_options_usage(stat_usage, stat_options, "log-fd", 0);
goto out;
}
if (!output) {
struct timespec tm;
mode = append_file ? "a" : "w";
output = fopen(output_name, mode);
if (!output) {
perror("failed to create output file");
return -1;
}
clock_gettime(CLOCK_REALTIME, &tm);
fprintf(output, "# started on %s\n", ctime(&tm.tv_sec));
} else if (output_fd > 0) {
mode = append_file ? "a" : "w";
output = fdopen(output_fd, mode);
if (!output) {
perror("Failed opening logfd");
return -errno;
}
}
stat_config.output = output;
if (csv_output) {
if (big_num_opt == 1) {
fprintf(stderr, "-B option not supported with -x\n");
parse_options_usage(stat_usage, stat_options, "B", 1);
parse_options_usage(NULL, stat_options, "x", 1);
goto out;
} else
big_num = false;
} else if (big_num_opt == 0)
big_num = false;
if (!argc && target__none(&target))
usage_with_options(stat_usage, stat_options);
if (run_count < 0) {
pr_err("Run count must be a positive number\n");
parse_options_usage(stat_usage, stat_options, "r", 1);
goto out;
} else if (run_count == 0) {
forever = true;
run_count = 1;
}
if ((stat_config.aggr_mode == AGGR_THREAD) && !target__has_task(&target)) {
fprintf(stderr, "The --per-thread option is only available "
"when monitoring via -p -t options.\n");
parse_options_usage(NULL, stat_options, "p", 1);
parse_options_usage(NULL, stat_options, "t", 1);
goto out;
}
if (((stat_config.aggr_mode != AGGR_GLOBAL &&
stat_config.aggr_mode != AGGR_THREAD) || nr_cgroups) &&
!target__has_cpu(&target)) {
fprintf(stderr, "both cgroup and no-aggregation "
"modes only available in system-wide mode\n");
parse_options_usage(stat_usage, stat_options, "G", 1);
parse_options_usage(NULL, stat_options, "A", 1);
parse_options_usage(NULL, stat_options, "a", 1);
goto out;
}
if (add_default_attributes())
goto out;
target__validate(&target);
if (perf_evlist__create_maps(evsel_list, &target) < 0) {
if (target__has_task(&target)) {
pr_err("Problems finding threads of monitor\n");
parse_options_usage(stat_usage, stat_options, "p", 1);
parse_options_usage(NULL, stat_options, "t", 1);
} else if (target__has_cpu(&target)) {
perror("failed to parse CPUs map");
parse_options_usage(stat_usage, stat_options, "C", 1);
parse_options_usage(NULL, stat_options, "a", 1);
}
goto out;
}
if (stat_config.aggr_mode == AGGR_THREAD)
thread_map__read_comms(evsel_list->threads);
if (interval && interval < 100) {
if (interval < 10) {
pr_err("print interval must be >= 10ms\n");
parse_options_usage(stat_usage, stat_options, "I", 1);
goto out;
} else
pr_warning("print interval < 100ms. "
"The overhead percentage could be high in some cases. "
"Please proceed with caution.\n");
}
if (perf_evlist__alloc_stats(evsel_list, interval))
goto out;
if (perf_stat_init_aggr_mode())
goto out;
atexit(sig_atexit);
if (!forever)
signal(SIGINT, skip_signal);
signal(SIGCHLD, skip_signal);
signal(SIGALRM, skip_signal);
signal(SIGABRT, skip_signal);
status = 0;
for (run_idx = 0; forever || run_idx < run_count; run_idx++) {
if (run_count != 1 && verbose)
fprintf(output, "[ perf stat: executing run #%d ... ]\n",
run_idx + 1);
status = run_perf_stat(argc, argv);
if (forever && status != -1) {
print_counters(NULL, argc, argv);
perf_stat__reset_stats();
}
}
if (!forever && status != -1 && !interval)
print_counters(NULL, argc, argv);
if (STAT_RECORD) {
int fd = perf_data_file__fd(&perf_stat.file);
int err = perf_event__synthesize_kernel_mmap((void *)&perf_stat,
process_synthesized_event,
&perf_stat.session->machines.host);
if (err) {
pr_warning("Couldn't synthesize the kernel mmap record, harmless, "
"older tools may produce warnings about this file\n.");
}
if (!interval) {
if (WRITE_STAT_ROUND_EVENT(walltime_nsecs_stats.max, FINAL))
pr_err("failed to write stat round event\n");
}
if (!perf_stat.file.is_pipe) {
perf_stat.session->header.data_size += perf_stat.bytes_written;
perf_session__write_header(perf_stat.session, evsel_list, fd, true);
}
perf_session__delete(perf_stat.session);
}
perf_stat__exit_aggr_mode();
perf_evlist__free_stats(evsel_list);
out:
perf_evlist__delete(evsel_list);
return status;
}
