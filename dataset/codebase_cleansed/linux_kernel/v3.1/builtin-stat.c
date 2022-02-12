static int perf_evsel__alloc_stat_priv(struct perf_evsel *evsel)
{
evsel->priv = zalloc(sizeof(struct perf_stat));
return evsel->priv == NULL ? -ENOMEM : 0;
}
static void perf_evsel__free_stat_priv(struct perf_evsel *evsel)
{
free(evsel->priv);
evsel->priv = NULL;
}
static void update_stats(struct stats *stats, u64 val)
{
double delta;
stats->n++;
delta = val - stats->mean;
stats->mean += delta / stats->n;
stats->M2 += delta*(val - stats->mean);
}
static double avg_stats(struct stats *stats)
{
return stats->mean;
}
static double stddev_stats(struct stats *stats)
{
double variance = stats->M2 / (stats->n - 1);
double variance_mean = variance / stats->n;
return sqrt(variance_mean);
}
static int create_perf_stat_counter(struct perf_evsel *evsel)
{
struct perf_event_attr *attr = &evsel->attr;
if (scale)
attr->read_format = PERF_FORMAT_TOTAL_TIME_ENABLED |
PERF_FORMAT_TOTAL_TIME_RUNNING;
attr->inherit = !no_inherit;
if (system_wide)
return perf_evsel__open_per_cpu(evsel, evsel_list->cpus, group);
if (target_pid == -1 && target_tid == -1) {
attr->disabled = 1;
attr->enable_on_exec = 1;
}
return perf_evsel__open_per_thread(evsel, evsel_list->threads, group);
}
static inline int nsec_counter(struct perf_evsel *evsel)
{
if (perf_evsel__match(evsel, SOFTWARE, SW_CPU_CLOCK) ||
perf_evsel__match(evsel, SOFTWARE, SW_TASK_CLOCK))
return 1;
return 0;
}
static void update_shadow_stats(struct perf_evsel *counter, u64 *count)
{
if (perf_evsel__match(counter, SOFTWARE, SW_TASK_CLOCK))
update_stats(&runtime_nsecs_stats[0], count[0]);
else if (perf_evsel__match(counter, HARDWARE, HW_CPU_CYCLES))
update_stats(&runtime_cycles_stats[0], count[0]);
else if (perf_evsel__match(counter, HARDWARE, HW_STALLED_CYCLES_FRONTEND))
update_stats(&runtime_stalled_cycles_front_stats[0], count[0]);
else if (perf_evsel__match(counter, HARDWARE, HW_STALLED_CYCLES_BACKEND))
update_stats(&runtime_stalled_cycles_back_stats[0], count[0]);
else if (perf_evsel__match(counter, HARDWARE, HW_BRANCH_INSTRUCTIONS))
update_stats(&runtime_branches_stats[0], count[0]);
else if (perf_evsel__match(counter, HARDWARE, HW_CACHE_REFERENCES))
update_stats(&runtime_cacherefs_stats[0], count[0]);
else if (perf_evsel__match(counter, HW_CACHE, HW_CACHE_L1D))
update_stats(&runtime_l1_dcache_stats[0], count[0]);
else if (perf_evsel__match(counter, HW_CACHE, HW_CACHE_L1I))
update_stats(&runtime_l1_icache_stats[0], count[0]);
else if (perf_evsel__match(counter, HW_CACHE, HW_CACHE_LL))
update_stats(&runtime_ll_cache_stats[0], count[0]);
else if (perf_evsel__match(counter, HW_CACHE, HW_CACHE_DTLB))
update_stats(&runtime_dtlb_cache_stats[0], count[0]);
else if (perf_evsel__match(counter, HW_CACHE, HW_CACHE_ITLB))
update_stats(&runtime_itlb_cache_stats[0], count[0]);
}
static int read_counter_aggr(struct perf_evsel *counter)
{
struct perf_stat *ps = counter->priv;
u64 *count = counter->counts->aggr.values;
int i;
if (__perf_evsel__read(counter, evsel_list->cpus->nr,
evsel_list->threads->nr, scale) < 0)
return -1;
for (i = 0; i < 3; i++)
update_stats(&ps->res_stats[i], count[i]);
if (verbose) {
fprintf(stderr, "%s: %" PRIu64 " %" PRIu64 " %" PRIu64 "\n",
event_name(counter), count[0], count[1], count[2]);
}
update_shadow_stats(counter, count);
return 0;
}
static int read_counter(struct perf_evsel *counter)
{
u64 *count;
int cpu;
for (cpu = 0; cpu < evsel_list->cpus->nr; cpu++) {
if (__perf_evsel__read_on_cpu(counter, cpu, 0, scale) < 0)
return -1;
count = counter->counts->cpu[cpu].values;
update_shadow_stats(counter, count);
}
return 0;
}
static int run_perf_stat(int argc __used, const char **argv)
{
unsigned long long t0, t1;
struct perf_evsel *counter;
int status = 0;
int child_ready_pipe[2], go_pipe[2];
const bool forks = (argc > 0);
char buf;
if (forks && (pipe(child_ready_pipe) < 0 || pipe(go_pipe) < 0)) {
perror("failed to create pipes");
exit(1);
}
if (forks) {
if ((child_pid = fork()) < 0)
perror("failed to fork");
if (!child_pid) {
close(child_ready_pipe[0]);
close(go_pipe[1]);
fcntl(go_pipe[0], F_SETFD, FD_CLOEXEC);
execvp("", (char **)argv);
close(child_ready_pipe[1]);
if (read(go_pipe[0], &buf, 1) == -1)
perror("unable to read pipe");
execvp(argv[0], (char **)argv);
perror(argv[0]);
exit(-1);
}
if (target_tid == -1 && target_pid == -1 && !system_wide)
evsel_list->threads->map[0] = child_pid;
close(child_ready_pipe[1]);
close(go_pipe[0]);
if (read(child_ready_pipe[0], &buf, 1) == -1)
perror("unable to read pipe");
close(child_ready_pipe[0]);
}
list_for_each_entry(counter, &evsel_list->entries, node) {
if (create_perf_stat_counter(counter) < 0) {
if (errno == EINVAL || errno == ENOSYS || errno == ENOENT) {
if (verbose)
ui__warning("%s event is not supported by the kernel.\n",
event_name(counter));
counter->supported = false;
continue;
}
if (errno == EPERM || errno == EACCES) {
error("You may not have permission to collect %sstats.\n"
"\t Consider tweaking"
" /proc/sys/kernel/perf_event_paranoid or running as root.",
system_wide ? "system-wide " : "");
} else {
error("open_counter returned with %d (%s). "
"/bin/dmesg may provide additional information.\n",
errno, strerror(errno));
}
if (child_pid != -1)
kill(child_pid, SIGTERM);
die("Not all events could be opened.\n");
return -1;
}
counter->supported = true;
}
if (perf_evlist__set_filters(evsel_list)) {
error("failed to set filter with %d (%s)\n", errno,
strerror(errno));
return -1;
}
t0 = rdclock();
if (forks) {
close(go_pipe[1]);
wait(&status);
} else {
while(!done) sleep(1);
}
t1 = rdclock();
update_stats(&walltime_nsecs_stats, t1 - t0);
if (no_aggr) {
list_for_each_entry(counter, &evsel_list->entries, node) {
read_counter(counter);
perf_evsel__close_fd(counter, evsel_list->cpus->nr, 1);
}
} else {
list_for_each_entry(counter, &evsel_list->entries, node) {
read_counter_aggr(counter);
perf_evsel__close_fd(counter, evsel_list->cpus->nr,
evsel_list->threads->nr);
}
}
return WEXITSTATUS(status);
}
static void print_noise_pct(double total, double avg)
{
double pct = 0.0;
if (avg)
pct = 100.0*total/avg;
if (csv_output)
fprintf(stderr, "%s%.2f%%", csv_sep, pct);
else
fprintf(stderr, " ( +-%6.2f%% )", pct);
}
static void print_noise(struct perf_evsel *evsel, double avg)
{
struct perf_stat *ps;
if (run_count == 1)
return;
ps = evsel->priv;
print_noise_pct(stddev_stats(&ps->res_stats[0]), avg);
}
static void nsec_printout(int cpu, struct perf_evsel *evsel, double avg)
{
double msecs = avg / 1e6;
char cpustr[16] = { '\0', };
const char *fmt = csv_output ? "%s%.6f%s%s" : "%s%18.6f%s%-25s";
if (no_aggr)
sprintf(cpustr, "CPU%*d%s",
csv_output ? 0 : -4,
evsel_list->cpus->map[cpu], csv_sep);
fprintf(stderr, fmt, cpustr, msecs, csv_sep, event_name(evsel));
if (evsel->cgrp)
fprintf(stderr, "%s%s", csv_sep, evsel->cgrp->name);
if (csv_output)
return;
if (perf_evsel__match(evsel, SOFTWARE, SW_TASK_CLOCK))
fprintf(stderr, " # %8.3f CPUs utilized ", avg / avg_stats(&walltime_nsecs_stats));
}
static void print_stalled_cycles_frontend(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_cycles_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 50.0)
color = PERF_COLOR_RED;
else if (ratio > 30.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 10.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " frontend cycles idle ");
}
static void print_stalled_cycles_backend(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_cycles_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 75.0)
color = PERF_COLOR_RED;
else if (ratio > 50.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 20.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " backend cycles idle ");
}
static void print_branch_misses(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_branches_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 20.0)
color = PERF_COLOR_RED;
else if (ratio > 10.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 5.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " of all branches ");
}
static void print_l1_dcache_misses(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_l1_dcache_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 20.0)
color = PERF_COLOR_RED;
else if (ratio > 10.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 5.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " of all L1-dcache hits ");
}
static void print_l1_icache_misses(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_l1_icache_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 20.0)
color = PERF_COLOR_RED;
else if (ratio > 10.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 5.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " of all L1-icache hits ");
}
static void print_dtlb_cache_misses(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_dtlb_cache_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 20.0)
color = PERF_COLOR_RED;
else if (ratio > 10.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 5.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " of all dTLB cache hits ");
}
static void print_itlb_cache_misses(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_itlb_cache_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 20.0)
color = PERF_COLOR_RED;
else if (ratio > 10.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 5.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " of all iTLB cache hits ");
}
static void print_ll_cache_misses(int cpu, struct perf_evsel *evsel __used, double avg)
{
double total, ratio = 0.0;
const char *color;
total = avg_stats(&runtime_ll_cache_stats[cpu]);
if (total)
ratio = avg / total * 100.0;
color = PERF_COLOR_NORMAL;
if (ratio > 20.0)
color = PERF_COLOR_RED;
else if (ratio > 10.0)
color = PERF_COLOR_MAGENTA;
else if (ratio > 5.0)
color = PERF_COLOR_YELLOW;
fprintf(stderr, " # ");
color_fprintf(stderr, color, "%6.2f%%", ratio);
fprintf(stderr, " of all LL-cache hits ");
}
static void abs_printout(int cpu, struct perf_evsel *evsel, double avg)
{
double total, ratio = 0.0;
char cpustr[16] = { '\0', };
const char *fmt;
if (csv_output)
fmt = "%s%.0f%s%s";
else if (big_num)
fmt = "%s%'18.0f%s%-25s";
else
fmt = "%s%18.0f%s%-25s";
if (no_aggr)
sprintf(cpustr, "CPU%*d%s",
csv_output ? 0 : -4,
evsel_list->cpus->map[cpu], csv_sep);
else
cpu = 0;
fprintf(stderr, fmt, cpustr, avg, csv_sep, event_name(evsel));
if (evsel->cgrp)
fprintf(stderr, "%s%s", csv_sep, evsel->cgrp->name);
if (csv_output)
return;
if (perf_evsel__match(evsel, HARDWARE, HW_INSTRUCTIONS)) {
total = avg_stats(&runtime_cycles_stats[cpu]);
if (total)
ratio = avg / total;
fprintf(stderr, " # %5.2f insns per cycle ", ratio);
total = avg_stats(&runtime_stalled_cycles_front_stats[cpu]);
total = max(total, avg_stats(&runtime_stalled_cycles_back_stats[cpu]));
if (total && avg) {
ratio = total / avg;
fprintf(stderr, "\n # %5.2f stalled cycles per insn", ratio);
}
} else if (perf_evsel__match(evsel, HARDWARE, HW_BRANCH_MISSES) &&
runtime_branches_stats[cpu].n != 0) {
print_branch_misses(cpu, evsel, avg);
} else if (
evsel->attr.type == PERF_TYPE_HW_CACHE &&
evsel->attr.config == ( PERF_COUNT_HW_CACHE_L1D |
((PERF_COUNT_HW_CACHE_OP_READ) << 8) |
((PERF_COUNT_HW_CACHE_RESULT_MISS) << 16)) &&
runtime_l1_dcache_stats[cpu].n != 0) {
print_l1_dcache_misses(cpu, evsel, avg);
} else if (
evsel->attr.type == PERF_TYPE_HW_CACHE &&
evsel->attr.config == ( PERF_COUNT_HW_CACHE_L1I |
((PERF_COUNT_HW_CACHE_OP_READ) << 8) |
((PERF_COUNT_HW_CACHE_RESULT_MISS) << 16)) &&
runtime_l1_icache_stats[cpu].n != 0) {
print_l1_icache_misses(cpu, evsel, avg);
} else if (
evsel->attr.type == PERF_TYPE_HW_CACHE &&
evsel->attr.config == ( PERF_COUNT_HW_CACHE_DTLB |
((PERF_COUNT_HW_CACHE_OP_READ) << 8) |
((PERF_COUNT_HW_CACHE_RESULT_MISS) << 16)) &&
runtime_dtlb_cache_stats[cpu].n != 0) {
print_dtlb_cache_misses(cpu, evsel, avg);
} else if (
evsel->attr.type == PERF_TYPE_HW_CACHE &&
evsel->attr.config == ( PERF_COUNT_HW_CACHE_ITLB |
((PERF_COUNT_HW_CACHE_OP_READ) << 8) |
((PERF_COUNT_HW_CACHE_RESULT_MISS) << 16)) &&
runtime_itlb_cache_stats[cpu].n != 0) {
print_itlb_cache_misses(cpu, evsel, avg);
} else if (
evsel->attr.type == PERF_TYPE_HW_CACHE &&
evsel->attr.config == ( PERF_COUNT_HW_CACHE_LL |
((PERF_COUNT_HW_CACHE_OP_READ) << 8) |
((PERF_COUNT_HW_CACHE_RESULT_MISS) << 16)) &&
runtime_ll_cache_stats[cpu].n != 0) {
print_ll_cache_misses(cpu, evsel, avg);
} else if (perf_evsel__match(evsel, HARDWARE, HW_CACHE_MISSES) &&
runtime_cacherefs_stats[cpu].n != 0) {
total = avg_stats(&runtime_cacherefs_stats[cpu]);
if (total)
ratio = avg * 100 / total;
fprintf(stderr, " # %8.3f %% of all cache refs ", ratio);
} else if (perf_evsel__match(evsel, HARDWARE, HW_STALLED_CYCLES_FRONTEND)) {
print_stalled_cycles_frontend(cpu, evsel, avg);
} else if (perf_evsel__match(evsel, HARDWARE, HW_STALLED_CYCLES_BACKEND)) {
print_stalled_cycles_backend(cpu, evsel, avg);
} else if (perf_evsel__match(evsel, HARDWARE, HW_CPU_CYCLES)) {
total = avg_stats(&runtime_nsecs_stats[cpu]);
if (total)
ratio = 1.0 * avg / total;
fprintf(stderr, " # %8.3f GHz ", ratio);
} else if (runtime_nsecs_stats[cpu].n != 0) {
total = avg_stats(&runtime_nsecs_stats[cpu]);
if (total)
ratio = 1000.0 * avg / total;
fprintf(stderr, " # %8.3f M/sec ", ratio);
} else {
fprintf(stderr, " ");
}
}
static void print_counter_aggr(struct perf_evsel *counter)
{
struct perf_stat *ps = counter->priv;
double avg = avg_stats(&ps->res_stats[0]);
int scaled = counter->counts->scaled;
if (scaled == -1) {
fprintf(stderr, "%*s%s%*s",
csv_output ? 0 : 18,
counter->supported ? CNTR_NOT_COUNTED : CNTR_NOT_SUPPORTED,
csv_sep,
csv_output ? 0 : -24,
event_name(counter));
if (counter->cgrp)
fprintf(stderr, "%s%s", csv_sep, counter->cgrp->name);
fputc('\n', stderr);
return;
}
if (nsec_counter(counter))
nsec_printout(-1, counter, avg);
else
abs_printout(-1, counter, avg);
print_noise(counter, avg);
if (csv_output) {
fputc('\n', stderr);
return;
}
if (scaled) {
double avg_enabled, avg_running;
avg_enabled = avg_stats(&ps->res_stats[1]);
avg_running = avg_stats(&ps->res_stats[2]);
fprintf(stderr, " [%5.2f%%]", 100 * avg_running / avg_enabled);
}
fprintf(stderr, "\n");
}
static void print_counter(struct perf_evsel *counter)
{
u64 ena, run, val;
int cpu;
for (cpu = 0; cpu < evsel_list->cpus->nr; cpu++) {
val = counter->counts->cpu[cpu].val;
ena = counter->counts->cpu[cpu].ena;
run = counter->counts->cpu[cpu].run;
if (run == 0 || ena == 0) {
fprintf(stderr, "CPU%*d%s%*s%s%*s",
csv_output ? 0 : -4,
evsel_list->cpus->map[cpu], csv_sep,
csv_output ? 0 : 18,
counter->supported ? CNTR_NOT_COUNTED : CNTR_NOT_SUPPORTED,
csv_sep,
csv_output ? 0 : -24,
event_name(counter));
if (counter->cgrp)
fprintf(stderr, "%s%s", csv_sep, counter->cgrp->name);
fputc('\n', stderr);
continue;
}
if (nsec_counter(counter))
nsec_printout(cpu, counter, val);
else
abs_printout(cpu, counter, val);
if (!csv_output) {
print_noise(counter, 1.0);
if (run != ena)
fprintf(stderr, " (%.2f%%)", 100.0 * run / ena);
}
fputc('\n', stderr);
}
}
static void print_stat(int argc, const char **argv)
{
struct perf_evsel *counter;
int i;
fflush(stdout);
if (!csv_output) {
fprintf(stderr, "\n");
fprintf(stderr, " Performance counter stats for ");
if(target_pid == -1 && target_tid == -1) {
fprintf(stderr, "\'%s", argv[0]);
for (i = 1; i < argc; i++)
fprintf(stderr, " %s", argv[i]);
} else if (target_pid != -1)
fprintf(stderr, "process id \'%d", target_pid);
else
fprintf(stderr, "thread id \'%d", target_tid);
fprintf(stderr, "\'");
if (run_count > 1)
fprintf(stderr, " (%d runs)", run_count);
fprintf(stderr, ":\n\n");
}
if (no_aggr) {
list_for_each_entry(counter, &evsel_list->entries, node)
print_counter(counter);
} else {
list_for_each_entry(counter, &evsel_list->entries, node)
print_counter_aggr(counter);
}
if (!csv_output) {
if (!null_run)
fprintf(stderr, "\n");
fprintf(stderr, " %17.9f seconds time elapsed",
avg_stats(&walltime_nsecs_stats)/1e9);
if (run_count > 1) {
fprintf(stderr, " ");
print_noise_pct(stddev_stats(&walltime_nsecs_stats),
avg_stats(&walltime_nsecs_stats));
}
fprintf(stderr, "\n\n");
}
}
static void skip_signal(int signo)
{
if(child_pid == -1)
done = 1;
signr = signo;
}
static void sig_atexit(void)
{
if (child_pid != -1)
kill(child_pid, SIGTERM);
if (signr == -1)
return;
signal(signr, SIG_DFL);
kill(getpid(), signr);
}
static int stat__set_big_num(const struct option *opt __used,
const char *s __used, int unset)
{
big_num_opt = unset ? 0 : 1;
return 0;
}
static int add_default_attributes(void)
{
struct perf_evsel *pos;
size_t attr_nr = 0;
size_t c;
if (null_run)
return 0;
if (!evsel_list->nr_entries) {
for (c = 0; c < ARRAY_SIZE(default_attrs); c++) {
pos = perf_evsel__new(default_attrs + c, c + attr_nr);
if (pos == NULL)
return -1;
perf_evlist__add(evsel_list, pos);
}
attr_nr += c;
}
if (detailed_run < 1)
return 0;
for (c = 0; c < ARRAY_SIZE(detailed_attrs); c++) {
pos = perf_evsel__new(detailed_attrs + c, c + attr_nr);
if (pos == NULL)
return -1;
perf_evlist__add(evsel_list, pos);
}
attr_nr += c;
if (detailed_run < 2)
return 0;
for (c = 0; c < ARRAY_SIZE(very_detailed_attrs); c++) {
pos = perf_evsel__new(very_detailed_attrs + c, c + attr_nr);
if (pos == NULL)
return -1;
perf_evlist__add(evsel_list, pos);
}
if (detailed_run < 3)
return 0;
for (c = 0; c < ARRAY_SIZE(very_very_detailed_attrs); c++) {
pos = perf_evsel__new(very_very_detailed_attrs + c, c + attr_nr);
if (pos == NULL)
return -1;
perf_evlist__add(evsel_list, pos);
}
return 0;
}
int cmd_stat(int argc, const char **argv, const char *prefix __used)
{
struct perf_evsel *pos;
int status = -ENOMEM;
setlocale(LC_ALL, "");
evsel_list = perf_evlist__new(NULL, NULL);
if (evsel_list == NULL)
return -ENOMEM;
argc = parse_options(argc, argv, options, stat_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (csv_sep)
csv_output = true;
else
csv_sep = DEFAULT_SEPARATOR;
if (csv_output) {
if (big_num_opt == 1) {
fprintf(stderr, "-B option not supported with -x\n");
usage_with_options(stat_usage, options);
} else
big_num = false;
} else if (big_num_opt == 0)
big_num = false;
if (!argc && target_pid == -1 && target_tid == -1)
usage_with_options(stat_usage, options);
if (run_count <= 0)
usage_with_options(stat_usage, options);
if ((no_aggr || nr_cgroups) && !system_wide) {
fprintf(stderr, "both cgroup and no-aggregation "
"modes only available in system-wide mode\n");
usage_with_options(stat_usage, options);
}
if (add_default_attributes())
goto out;
if (target_pid != -1)
target_tid = target_pid;
evsel_list->threads = thread_map__new(target_pid, target_tid);
if (evsel_list->threads == NULL) {
pr_err("Problems finding threads of monitor\n");
usage_with_options(stat_usage, options);
}
if (system_wide)
evsel_list->cpus = cpu_map__new(cpu_list);
else
evsel_list->cpus = cpu_map__dummy_new();
if (evsel_list->cpus == NULL) {
perror("failed to parse CPUs map");
usage_with_options(stat_usage, options);
return -1;
}
list_for_each_entry(pos, &evsel_list->entries, node) {
if (perf_evsel__alloc_stat_priv(pos) < 0 ||
perf_evsel__alloc_counts(pos, evsel_list->cpus->nr) < 0 ||
perf_evsel__alloc_fd(pos, evsel_list->cpus->nr, evsel_list->threads->nr) < 0)
goto out_free_fd;
}
atexit(sig_atexit);
signal(SIGINT, skip_signal);
signal(SIGALRM, skip_signal);
signal(SIGABRT, skip_signal);
status = 0;
for (run_idx = 0; run_idx < run_count; run_idx++) {
if (run_count != 1 && verbose)
fprintf(stderr, "[ perf stat: executing run #%d ... ]\n", run_idx + 1);
if (sync_run)
sync();
status = run_perf_stat(argc, argv);
}
if (status != -1)
print_stat(argc, argv);
out_free_fd:
list_for_each_entry(pos, &evsel_list->entries, node)
perf_evsel__free_stat_priv(pos);
perf_evlist__delete_maps(evsel_list);
out:
perf_evlist__delete(evsel_list);
return status;
}
