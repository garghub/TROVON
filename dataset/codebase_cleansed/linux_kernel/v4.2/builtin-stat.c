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
if (scale)
attr->read_format = PERF_FORMAT_TOTAL_TIME_ENABLED |
PERF_FORMAT_TOTAL_TIME_RUNNING;
attr->inherit = !no_inherit;
if (target__has_cpu(&target))
return perf_evsel__open_per_cpu(evsel, perf_evsel__cpus(evsel));
if (!target__has_task(&target) && perf_evsel__is_group_leader(evsel)) {
attr->disabled = 1;
if (!initial_delay)
attr->enable_on_exec = 1;
}
return perf_evsel__open_per_thread(evsel, evsel_list->threads);
}
static inline int nsec_counter(struct perf_evsel *evsel)
{
if (perf_evsel__match(evsel, SOFTWARE, SW_CPU_CLOCK) ||
perf_evsel__match(evsel, SOFTWARE, SW_TASK_CLOCK))
return 1;
return 0;
}
static void zero_per_pkg(struct perf_evsel *counter)
{
if (counter->per_pkg_mask)
memset(counter->per_pkg_mask, 0, MAX_NR_CPUS);
}
static int check_per_pkg(struct perf_evsel *counter, int cpu, bool *skip)
{
unsigned long *mask = counter->per_pkg_mask;
struct cpu_map *cpus = perf_evsel__cpus(counter);
int s;
*skip = false;
if (!counter->per_pkg)
return 0;
if (cpu_map__empty(cpus))
return 0;
if (!mask) {
mask = zalloc(MAX_NR_CPUS);
if (!mask)
return -ENOMEM;
counter->per_pkg_mask = mask;
}
s = cpu_map__get_socket(cpus, cpu);
if (s < 0)
return -1;
*skip = test_and_set_bit(s, mask) == 1;
return 0;
}
static int
process_counter_values(struct perf_evsel *evsel, int cpu, int thread,
struct perf_counts_values *count)
{
struct perf_counts_values *aggr = &evsel->counts->aggr;
static struct perf_counts_values zero;
bool skip = false;
if (check_per_pkg(evsel, cpu, &skip)) {
pr_err("failed to read per-pkg counter\n");
return -1;
}
if (skip)
count = &zero;
switch (aggr_mode) {
case AGGR_THREAD:
case AGGR_CORE:
case AGGR_SOCKET:
case AGGR_NONE:
if (!evsel->snapshot)
perf_evsel__compute_deltas(evsel, cpu, thread, count);
perf_counts_values__scale(count, scale, NULL);
if (aggr_mode == AGGR_NONE)
perf_stat__update_shadow_stats(evsel, count->values, cpu);
break;
case AGGR_GLOBAL:
aggr->val += count->val;
if (scale) {
aggr->ena += count->ena;
aggr->run += count->run;
}
default:
break;
}
return 0;
}
static int process_counter_maps(struct perf_evsel *counter)
{
int nthreads = thread_map__nr(counter->threads);
int ncpus = perf_evsel__nr_cpus(counter);
int cpu, thread;
if (counter->system_wide)
nthreads = 1;
for (thread = 0; thread < nthreads; thread++) {
for (cpu = 0; cpu < ncpus; cpu++) {
if (process_counter_values(counter, cpu, thread,
perf_counts(counter->counts, cpu, thread)))
return -1;
}
}
return 0;
}
static int process_counter(struct perf_evsel *counter)
{
struct perf_counts_values *aggr = &counter->counts->aggr;
struct perf_stat *ps = counter->priv;
u64 *count = counter->counts->aggr.values;
int i, ret;
aggr->val = aggr->ena = aggr->run = 0;
init_stats(ps->res_stats);
if (counter->per_pkg)
zero_per_pkg(counter);
ret = process_counter_maps(counter);
if (ret)
return ret;
if (aggr_mode != AGGR_GLOBAL)
return 0;
if (!counter->snapshot)
perf_evsel__compute_deltas(counter, -1, -1, aggr);
perf_counts_values__scale(aggr, scale, &counter->counts->scaled);
for (i = 0; i < 3; i++)
update_stats(&ps->res_stats[i], count[i]);
if (verbose) {
fprintf(output, "%s: %" PRIu64 " %" PRIu64 " %" PRIu64 "\n",
perf_evsel__name(counter), count[0], count[1], count[2]);
}
perf_stat__update_shadow_stats(counter, count, 0);
return 0;
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
}
}
return 0;
}
static void read_counters(bool close_counters)
{
struct perf_evsel *counter;
evlist__for_each(evsel_list, counter) {
if (read_counter(counter))
pr_warning("failed to read counter %s\n", counter->name);
if (process_counter(counter))
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
print_counters(&rs, 0, NULL);
}
static void handle_initial_delay(void)
{
struct perf_evsel *counter;
if (initial_delay) {
const int ncpus = cpu_map__nr(evsel_list->cpus),
nthreads = thread_map__nr(evsel_list->threads);
usleep(initial_delay * 1000);
evlist__for_each(evsel_list, counter)
perf_evsel__enable(counter, ncpus, nthreads);
}
}
static void workload_exec_failed_signal(int signo __maybe_unused, siginfo_t *info,
void *ucontext __maybe_unused)
{
workload_exec_errno = info->si_value.sival_int;
}
static int __run_perf_stat(int argc, const char **argv)
{
char msg[512];
unsigned long long t0, t1;
struct perf_evsel *counter;
struct timespec ts;
size_t l;
int status = 0;
const bool forks = (argc > 0);
if (interval) {
ts.tv_sec = interval / 1000;
ts.tv_nsec = (interval % 1000) * 1000000;
} else {
ts.tv_sec = 1;
ts.tv_nsec = 0;
}
if (forks) {
if (perf_evlist__prepare_workload(evsel_list, &target, argv, false,
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
}
if (perf_evlist__apply_filters(evsel_list, &counter)) {
error("failed to set filter \"%s\" on event %s with %d (%s)\n",
counter->filter, perf_evsel__name(counter), errno,
strerror_r(errno, msg, sizeof(msg)));
return -1;
}
t0 = rdclock();
clock_gettime(CLOCK_MONOTONIC, &ref_time);
if (forks) {
perf_evlist__start_workload(evsel_list);
handle_initial_delay();
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
handle_initial_delay();
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
fprintf(output, "%s%" PRIu64 "%s%.2f",
csv_sep,
run,
csv_sep,
ena ? 100.0 * run / ena : 100.0);
} else if (run != ena) {
fprintf(output, " (%.2f%%)", 100.0 * run / ena);
}
}
static void print_noise_pct(double total, double avg)
{
double pct = rel_stddev_stats(total, avg);
if (csv_output)
fprintf(output, "%s%.2f%%", csv_sep, pct);
else if (pct)
fprintf(output, " ( +-%6.2f%% )", pct);
}
static void print_noise(struct perf_evsel *evsel, double avg)
{
struct perf_stat *ps;
if (run_count == 1)
return;
ps = evsel->priv;
print_noise_pct(stddev_stats(&ps->res_stats[0]), avg);
}
static void aggr_printout(struct perf_evsel *evsel, int id, int nr)
{
switch (aggr_mode) {
case AGGR_CORE:
fprintf(output, "S%d-C%*d%s%*d%s",
cpu_map__id_to_socket(id),
csv_output ? 0 : -8,
cpu_map__id_to_cpu(id),
csv_sep,
csv_output ? 0 : 4,
nr,
csv_sep);
break;
case AGGR_SOCKET:
fprintf(output, "S%*d%s%*d%s",
csv_output ? 0 : -5,
id,
csv_sep,
csv_output ? 0 : 4,
nr,
csv_sep);
break;
case AGGR_NONE:
fprintf(output, "CPU%*d%s",
csv_output ? 0 : -4,
perf_evsel__cpus(evsel)->map[id], csv_sep);
break;
case AGGR_THREAD:
fprintf(output, "%*s-%*d%s",
csv_output ? 0 : 16,
thread_map__comm(evsel->threads, id),
csv_output ? 0 : -8,
thread_map__pid(evsel->threads, id),
csv_sep);
break;
case AGGR_GLOBAL:
default:
break;
}
}
static void nsec_printout(int id, int nr, struct perf_evsel *evsel, double avg)
{
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
if (csv_output || interval)
return;
if (perf_evsel__match(evsel, SOFTWARE, SW_TASK_CLOCK))
fprintf(output, " # %8.3f CPUs utilized ",
avg / avg_stats(&walltime_nsecs_stats));
else
fprintf(output, " ");
}
static void abs_printout(int id, int nr, struct perf_evsel *evsel, double avg)
{
double sc = evsel->scale;
const char *fmt;
int cpu = cpu_map__id_to_cpu(id);
if (csv_output) {
fmt = sc != 1.0 ? "%.2f%s" : "%.0f%s";
} else {
if (big_num)
fmt = sc != 1.0 ? "%'18.2f%s" : "%'18.0f%s";
else
fmt = sc != 1.0 ? "%18.2f%s" : "%18.0f%s";
}
aggr_printout(evsel, id, nr);
if (aggr_mode == AGGR_GLOBAL)
cpu = 0;
fprintf(output, fmt, avg, csv_sep);
if (evsel->unit)
fprintf(output, "%-*s%s",
csv_output ? 0 : unit_width,
evsel->unit, csv_sep);
fprintf(output, "%-*s", csv_output ? 0 : 25, perf_evsel__name(evsel));
if (evsel->cgrp)
fprintf(output, "%s%s", csv_sep, evsel->cgrp->name);
if (csv_output || interval)
return;
perf_stat__print_shadow_stats(output, evsel, avg, cpu, aggr_mode);
}
static void print_aggr(char *prefix)
{
struct perf_evsel *counter;
int cpu, cpu2, s, s2, id, nr;
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
cpu2 = perf_evsel__cpus(counter)->map[cpu];
s2 = aggr_get_id(evsel_list->cpus, cpu2);
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
if (nsec_counter(counter))
nsec_printout(id, nr, counter, uval);
else
abs_printout(id, nr, counter, uval);
if (!csv_output)
print_noise(counter, 1.0);
print_running(run, ena);
fputc('\n', output);
}
}
}
static void print_aggr_thread(struct perf_evsel *counter, char *prefix)
{
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
if (nsec_counter(counter))
nsec_printout(thread, 0, counter, uval);
else
abs_printout(thread, 0, counter, uval);
if (!csv_output)
print_noise(counter, 1.0);
print_running(run, ena);
fputc('\n', output);
}
}
static void print_counter_aggr(struct perf_evsel *counter, char *prefix)
{
struct perf_stat *ps = counter->priv;
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
if (nsec_counter(counter))
nsec_printout(-1, 0, counter, uval);
else
abs_printout(-1, 0, counter, uval);
print_noise(counter, avg);
print_running(avg_running, avg_enabled);
fprintf(output, "\n");
}
static void print_counter(struct perf_evsel *counter, char *prefix)
{
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
if (nsec_counter(counter))
nsec_printout(cpu, 0, counter, uval);
else
abs_printout(cpu, 0, counter, uval);
if (!csv_output)
print_noise(counter, 1.0);
print_running(run, ena);
fputc('\n', output);
}
}
static void print_interval(char *prefix, struct timespec *ts)
{
static int num_print_interval;
sprintf(prefix, "%6lu.%09lu%s", ts->tv_sec, ts->tv_nsec, csv_sep);
if (num_print_interval == 0 && !csv_output) {
switch (aggr_mode) {
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
}
}
if (++num_print_interval == 25)
num_print_interval = 0;
}
static void print_header(int argc, const char **argv)
{
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
fprintf(output, "\'%s", argv[0]);
for (i = 1; i < argc; i++)
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
struct perf_evsel *counter;
char buf[64], *prefix = NULL;
if (interval)
print_interval(prefix = buf, ts);
else
print_header(argc, argv);
switch (aggr_mode) {
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
default:
break;
}
if (!interval && !csv_output)
print_footer();
fflush(output);
}
static void skip_signal(int signo)
{
if ((child_pid == -1) || interval)
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
static int perf_stat_init_aggr_mode(void)
{
switch (aggr_mode) {
case AGGR_SOCKET:
if (cpu_map__build_socket_map(evsel_list->cpus, &aggr_map)) {
perror("cannot build socket map");
return -1;
}
aggr_get_id = cpu_map__get_socket;
break;
case AGGR_CORE:
if (cpu_map__build_core_map(evsel_list->cpus, &aggr_map)) {
perror("cannot build core map");
return -1;
}
aggr_get_id = cpu_map__get_core;
break;
case AGGR_NONE:
case AGGR_GLOBAL:
case AGGR_THREAD:
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
int cmd_stat(int argc, const char **argv, const char *prefix __maybe_unused)
{
bool append_file = false;
int output_fd = 0;
const char *output_name = NULL;
const struct option options[] = {
OPT_BOOLEAN('T', "transaction", &transaction_run,
"hardware transaction statistics"),
OPT_CALLBACK('e', "event", &evsel_list, "event",
"event selector. use 'perf list' to list available events",
parse_events_option),
OPT_CALLBACK(0, "filter", &evsel_list, "filter",
"event filter", parse_filter),
OPT_BOOLEAN('i', "no-inherit", &no_inherit,
"child tasks do not inherit counters"),
OPT_STRING('p', "pid", &target.pid, "pid",
"stat events on existing process id"),
OPT_STRING('t', "tid", &target.tid, "tid",
"stat events on existing thread id"),
OPT_BOOLEAN('a', "all-cpus", &target.system_wide,
"system-wide collection from all CPUs"),
OPT_BOOLEAN('g', "group", &group,
"put the counters into a counter group"),
OPT_BOOLEAN('c', "scale", &scale, "scale/normalize counters"),
OPT_INCR('v', "verbose", &verbose,
"be more verbose (show counter open errors, etc)"),
OPT_INTEGER('r', "repeat", &run_count,
"repeat command and print average + stddev (max: 100, forever: 0)"),
OPT_BOOLEAN('n', "null", &null_run,
"null run - dont start any counters"),
OPT_INCR('d', "detailed", &detailed_run,
"detailed run - start a lot of events"),
OPT_BOOLEAN('S', "sync", &sync_run,
"call sync() before starting a run"),
OPT_CALLBACK_NOOPT('B', "big-num", NULL, NULL,
"print large numbers with thousands\' separators",
stat__set_big_num),
OPT_STRING('C', "cpu", &target.cpu_list, "cpu",
"list of cpus to monitor in system-wide"),
OPT_SET_UINT('A', "no-aggr", &aggr_mode,
"disable CPU count aggregation", AGGR_NONE),
OPT_STRING('x', "field-separator", &csv_sep, "separator",
"print counts with custom separator"),
OPT_CALLBACK('G', "cgroup", &evsel_list, "name",
"monitor event in cgroup name only", parse_cgroups),
OPT_STRING('o', "output", &output_name, "file", "output file name"),
OPT_BOOLEAN(0, "append", &append_file, "append to the output file"),
OPT_INTEGER(0, "log-fd", &output_fd,
"log output to fd, instead of stderr"),
OPT_STRING(0, "pre", &pre_cmd, "command",
"command to run prior to the measured command"),
OPT_STRING(0, "post", &post_cmd, "command",
"command to run after to the measured command"),
OPT_UINTEGER('I', "interval-print", &interval,
"print counts at regular interval in ms (>= 100)"),
OPT_SET_UINT(0, "per-socket", &aggr_mode,
"aggregate counts per processor socket", AGGR_SOCKET),
OPT_SET_UINT(0, "per-core", &aggr_mode,
"aggregate counts per physical processor core", AGGR_CORE),
OPT_SET_UINT(0, "per-thread", &aggr_mode,
"aggregate counts per thread", AGGR_THREAD),
OPT_UINTEGER('D', "delay", &initial_delay,
"ms to wait before starting measurement after program start"),
OPT_END()
};
const char * const stat_usage[] = {
"perf stat [<options>] [<command>]",
NULL
};
int status = -EINVAL, run_idx;
const char *mode;
setlocale(LC_ALL, "");
evsel_list = perf_evlist__new();
if (evsel_list == NULL)
return -ENOMEM;
argc = parse_options(argc, argv, options, stat_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
output = stderr;
if (output_name && strcmp(output_name, "-"))
output = NULL;
if (output_name && output_fd) {
fprintf(stderr, "cannot use both --output and --log-fd\n");
parse_options_usage(stat_usage, options, "o", 1);
parse_options_usage(NULL, options, "log-fd", 0);
goto out;
}
if (output_fd < 0) {
fprintf(stderr, "argument to --log-fd must be a > 0\n");
parse_options_usage(stat_usage, options, "log-fd", 0);
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
if (csv_sep) {
csv_output = true;
if (!strcmp(csv_sep, "\\t"))
csv_sep = "\t";
} else
csv_sep = DEFAULT_SEPARATOR;
if (csv_output) {
if (big_num_opt == 1) {
fprintf(stderr, "-B option not supported with -x\n");
parse_options_usage(stat_usage, options, "B", 1);
parse_options_usage(NULL, options, "x", 1);
goto out;
} else
big_num = false;
} else if (big_num_opt == 0)
big_num = false;
if (!argc && target__none(&target))
usage_with_options(stat_usage, options);
if (run_count < 0) {
pr_err("Run count must be a positive number\n");
parse_options_usage(stat_usage, options, "r", 1);
goto out;
} else if (run_count == 0) {
forever = true;
run_count = 1;
}
if ((aggr_mode == AGGR_THREAD) && !target__has_task(&target)) {
fprintf(stderr, "The --per-thread option is only available "
"when monitoring via -p -t options.\n");
parse_options_usage(NULL, options, "p", 1);
parse_options_usage(NULL, options, "t", 1);
goto out;
}
if (((aggr_mode != AGGR_GLOBAL && aggr_mode != AGGR_THREAD) || nr_cgroups) &&
!target__has_cpu(&target)) {
fprintf(stderr, "both cgroup and no-aggregation "
"modes only available in system-wide mode\n");
parse_options_usage(stat_usage, options, "G", 1);
parse_options_usage(NULL, options, "A", 1);
parse_options_usage(NULL, options, "a", 1);
goto out;
}
if (add_default_attributes())
goto out;
target__validate(&target);
if (perf_evlist__create_maps(evsel_list, &target) < 0) {
if (target__has_task(&target)) {
pr_err("Problems finding threads of monitor\n");
parse_options_usage(stat_usage, options, "p", 1);
parse_options_usage(NULL, options, "t", 1);
} else if (target__has_cpu(&target)) {
perror("failed to parse CPUs map");
parse_options_usage(stat_usage, options, "C", 1);
parse_options_usage(NULL, options, "a", 1);
}
goto out;
}
if (aggr_mode == AGGR_THREAD)
thread_map__read_comms(evsel_list->threads);
if (interval && interval < 100) {
pr_err("print interval must be >= 100ms\n");
parse_options_usage(stat_usage, options, "I", 1);
goto out;
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
perf_evlist__free_stats(evsel_list);
out:
perf_evlist__delete(evsel_list);
return status;
}
