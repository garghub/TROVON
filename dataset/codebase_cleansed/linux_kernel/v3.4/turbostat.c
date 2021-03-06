void cpu_mask_init(int ncpus)
{
cpu_mask = CPU_ALLOC(ncpus);
if (cpu_mask == NULL) {
perror("CPU_ALLOC");
exit(3);
}
cpu_mask_size = CPU_ALLOC_SIZE(ncpus);
CPU_ZERO_S(cpu_mask_size, cpu_mask);
}
void cpu_mask_uninit()
{
CPU_FREE(cpu_mask);
cpu_mask = NULL;
cpu_mask_size = 0;
}
int cpu_migrate(int cpu)
{
CPU_ZERO_S(cpu_mask_size, cpu_mask);
CPU_SET_S(cpu, cpu_mask_size, cpu_mask);
if (sched_setaffinity(0, cpu_mask_size, cpu_mask) == -1)
return -1;
else
return 0;
}
int get_msr(int cpu, off_t offset, unsigned long long *msr)
{
ssize_t retval;
char pathname[32];
int fd;
sprintf(pathname, "/dev/cpu/%d/msr", cpu);
fd = open(pathname, O_RDONLY);
if (fd < 0)
return -1;
retval = pread(fd, msr, sizeof *msr, offset);
close(fd);
if (retval != sizeof *msr)
return -1;
return 0;
}
void print_header(void)
{
if (show_pkg)
fprintf(stderr, "pk");
if (show_pkg)
fprintf(stderr, " ");
if (show_core)
fprintf(stderr, "cor");
if (show_cpu)
fprintf(stderr, " CPU");
if (show_pkg || show_core || show_cpu)
fprintf(stderr, " ");
if (do_nhm_cstates)
fprintf(stderr, " %%c0");
if (has_aperf)
fprintf(stderr, " GHz");
fprintf(stderr, " TSC");
if (do_nhm_cstates)
fprintf(stderr, " %%c1");
if (do_nhm_cstates)
fprintf(stderr, " %%c3");
if (do_nhm_cstates)
fprintf(stderr, " %%c6");
if (do_snb_cstates)
fprintf(stderr, " %%c7");
if (do_snb_cstates)
fprintf(stderr, " %%pc2");
if (do_nhm_cstates)
fprintf(stderr, " %%pc3");
if (do_nhm_cstates)
fprintf(stderr, " %%pc6");
if (do_snb_cstates)
fprintf(stderr, " %%pc7");
if (extra_msr_offset)
fprintf(stderr, " MSR 0x%x ", extra_msr_offset);
putc('\n', stderr);
}
void dump_cnt(struct counters *cnt)
{
if (!cnt)
return;
if (cnt->pkg) fprintf(stderr, "package: %d ", cnt->pkg);
if (cnt->core) fprintf(stderr, "core:: %d ", cnt->core);
if (cnt->cpu) fprintf(stderr, "CPU: %d ", cnt->cpu);
if (cnt->tsc) fprintf(stderr, "TSC: %016llX\n", cnt->tsc);
if (cnt->c3) fprintf(stderr, "c3: %016llX\n", cnt->c3);
if (cnt->c6) fprintf(stderr, "c6: %016llX\n", cnt->c6);
if (cnt->c7) fprintf(stderr, "c7: %016llX\n", cnt->c7);
if (cnt->aperf) fprintf(stderr, "aperf: %016llX\n", cnt->aperf);
if (cnt->pc2) fprintf(stderr, "pc2: %016llX\n", cnt->pc2);
if (cnt->pc3) fprintf(stderr, "pc3: %016llX\n", cnt->pc3);
if (cnt->pc6) fprintf(stderr, "pc6: %016llX\n", cnt->pc6);
if (cnt->pc7) fprintf(stderr, "pc7: %016llX\n", cnt->pc7);
if (cnt->extra_msr) fprintf(stderr, "msr0x%x: %016llX\n", extra_msr_offset, cnt->extra_msr);
}
void dump_list(struct counters *cnt)
{
printf("dump_list 0x%p\n", cnt);
for (; cnt; cnt = cnt->next)
dump_cnt(cnt);
}
void print_cnt(struct counters *p)
{
double interval_float;
interval_float = tv_delta.tv_sec + tv_delta.tv_usec/1000000.0;
if (p == cnt_average) {
if (show_pkg)
fprintf(stderr, " ");
if (show_pkg && show_core)
fprintf(stderr, " ");
if (show_core)
fprintf(stderr, " ");
if (show_cpu)
fprintf(stderr, " " " ");
} else {
if (show_pkg)
fprintf(stderr, "%2d", p->pkg);
if (show_pkg && show_core)
fprintf(stderr, " ");
if (show_core)
fprintf(stderr, "%3d", p->core);
if (show_cpu)
fprintf(stderr, " %3d", p->cpu);
}
if (do_nhm_cstates) {
if (show_pkg || show_core || show_cpu)
fprintf(stderr, " ");
if (!skip_c0)
fprintf(stderr, "%6.2f", 100.0 * p->mperf/p->tsc);
else
fprintf(stderr, " ****");
}
if (has_aperf) {
if (!aperf_mperf_unstable) {
fprintf(stderr, " %3.2f",
1.0 * p->tsc / units * p->aperf /
p->mperf / interval_float);
} else {
if (p->aperf > p->tsc || p->mperf > p->tsc) {
fprintf(stderr, " ***");
} else {
fprintf(stderr, "%3.1f*",
1.0 * p->tsc /
units * p->aperf /
p->mperf / interval_float);
}
}
}
fprintf(stderr, "%5.2f", 1.0 * p->tsc/units/interval_float);
if (do_nhm_cstates) {
if (!skip_c1)
fprintf(stderr, " %6.2f", 100.0 * p->c1/p->tsc);
else
fprintf(stderr, " ****");
}
if (do_nhm_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->c3/p->tsc);
if (do_nhm_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->c6/p->tsc);
if (do_snb_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->c7/p->tsc);
if (do_snb_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->pc2/p->tsc);
if (do_nhm_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->pc3/p->tsc);
if (do_nhm_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->pc6/p->tsc);
if (do_snb_cstates)
fprintf(stderr, " %6.2f", 100.0 * p->pc7/p->tsc);
if (extra_msr_offset)
fprintf(stderr, " 0x%016llx", p->extra_msr);
putc('\n', stderr);
}
void print_counters(struct counters *counters)
{
struct counters *cnt;
static int printed;
if (!printed || !summary_only)
print_header();
if (num_cpus > 1)
print_cnt(cnt_average);
printed = 1;
if (summary_only)
return;
for (cnt = counters; cnt != NULL; cnt = cnt->next)
print_cnt(cnt);
}
int compute_delta(struct counters *after,
struct counters *before, struct counters *delta)
{
int errors = 0;
int perf_err = 0;
skip_c0 = skip_c1 = 0;
for ( ; after && before && delta;
after = after->next, before = before->next, delta = delta->next) {
if (before->cpu != after->cpu) {
printf("cpu configuration changed: %d != %d\n",
before->cpu, after->cpu);
return -1;
}
if (SUBTRACT_COUNTER(after->tsc, before->tsc, delta->tsc)) {
fprintf(stderr, "cpu%d TSC went backwards %llX to %llX\n",
before->cpu, before->tsc, after->tsc);
errors++;
}
if (delta->tsc < (1000 * 1000)) {
fprintf(stderr, "Insanely slow TSC rate,"
" TSC stops in idle?\n");
fprintf(stderr, "You can disable all c-states"
" by booting with \"idle=poll\"\n");
fprintf(stderr, "or just the deep ones with"
" \"processor.max_cstate=1\"\n");
exit(-3);
}
if (SUBTRACT_COUNTER(after->c3, before->c3, delta->c3)) {
fprintf(stderr, "cpu%d c3 counter went backwards %llX to %llX\n",
before->cpu, before->c3, after->c3);
errors++;
}
if (SUBTRACT_COUNTER(after->c6, before->c6, delta->c6)) {
fprintf(stderr, "cpu%d c6 counter went backwards %llX to %llX\n",
before->cpu, before->c6, after->c6);
errors++;
}
if (SUBTRACT_COUNTER(after->c7, before->c7, delta->c7)) {
fprintf(stderr, "cpu%d c7 counter went backwards %llX to %llX\n",
before->cpu, before->c7, after->c7);
errors++;
}
if (SUBTRACT_COUNTER(after->pc2, before->pc2, delta->pc2)) {
fprintf(stderr, "cpu%d pc2 counter went backwards %llX to %llX\n",
before->cpu, before->pc2, after->pc2);
errors++;
}
if (SUBTRACT_COUNTER(after->pc3, before->pc3, delta->pc3)) {
fprintf(stderr, "cpu%d pc3 counter went backwards %llX to %llX\n",
before->cpu, before->pc3, after->pc3);
errors++;
}
if (SUBTRACT_COUNTER(after->pc6, before->pc6, delta->pc6)) {
fprintf(stderr, "cpu%d pc6 counter went backwards %llX to %llX\n",
before->cpu, before->pc6, after->pc6);
errors++;
}
if (SUBTRACT_COUNTER(after->pc7, before->pc7, delta->pc7)) {
fprintf(stderr, "cpu%d pc7 counter went backwards %llX to %llX\n",
before->cpu, before->pc7, after->pc7);
errors++;
}
perf_err = SUBTRACT_COUNTER(after->aperf, before->aperf, delta->aperf);
if (perf_err) {
fprintf(stderr, "cpu%d aperf counter went backwards %llX to %llX\n",
before->cpu, before->aperf, after->aperf);
}
perf_err |= SUBTRACT_COUNTER(after->mperf, before->mperf, delta->mperf);
if (perf_err) {
fprintf(stderr, "cpu%d mperf counter went backwards %llX to %llX\n",
before->cpu, before->mperf, after->mperf);
}
if (perf_err) {
if (!aperf_mperf_unstable) {
fprintf(stderr, "%s: APERF or MPERF went backwards *\n", progname);
fprintf(stderr, "* Frequency results do not cover entire interval *\n");
fprintf(stderr, "* fix this by running Linux-2.6.30 or later *\n");
aperf_mperf_unstable = 1;
}
skip_c0 = 1;
skip_c1 = 1;
}
if (delta->mperf > delta->tsc)
delta->c1 = 0;
else
delta->c1 = delta->tsc - delta->mperf
- delta->c3 - delta->c6 - delta->c7;
if (delta->mperf == 0)
delta->mperf = 1;
delta->extra_msr = after->extra_msr;
if (errors) {
fprintf(stderr, "ERROR cpu%d before:\n", before->cpu);
dump_cnt(before);
fprintf(stderr, "ERROR cpu%d after:\n", before->cpu);
dump_cnt(after);
errors = 0;
}
}
return 0;
}
void compute_average(struct counters *delta, struct counters *avg)
{
struct counters *sum;
sum = calloc(1, sizeof(struct counters));
if (sum == NULL) {
perror("calloc sum");
exit(1);
}
for (; delta; delta = delta->next) {
sum->tsc += delta->tsc;
sum->c1 += delta->c1;
sum->c3 += delta->c3;
sum->c6 += delta->c6;
sum->c7 += delta->c7;
sum->aperf += delta->aperf;
sum->mperf += delta->mperf;
sum->pc2 += delta->pc2;
sum->pc3 += delta->pc3;
sum->pc6 += delta->pc6;
sum->pc7 += delta->pc7;
}
avg->tsc = sum->tsc/num_cpus;
avg->c1 = sum->c1/num_cpus;
avg->c3 = sum->c3/num_cpus;
avg->c6 = sum->c6/num_cpus;
avg->c7 = sum->c7/num_cpus;
avg->aperf = sum->aperf/num_cpus;
avg->mperf = sum->mperf/num_cpus;
avg->pc2 = sum->pc2/num_cpus;
avg->pc3 = sum->pc3/num_cpus;
avg->pc6 = sum->pc6/num_cpus;
avg->pc7 = sum->pc7/num_cpus;
free(sum);
}
int get_counters(struct counters *cnt)
{
for ( ; cnt; cnt = cnt->next) {
if (cpu_migrate(cnt->cpu))
return -1;
if (get_msr(cnt->cpu, MSR_TSC, &cnt->tsc))
return -1;
if (has_aperf) {
if (get_msr(cnt->cpu, MSR_APERF, &cnt->aperf))
return -1;
if (get_msr(cnt->cpu, MSR_MPERF, &cnt->mperf))
return -1;
}
if (do_nhm_cstates) {
if (get_msr(cnt->cpu, MSR_CORE_C3_RESIDENCY, &cnt->c3))
return -1;
if (get_msr(cnt->cpu, MSR_CORE_C6_RESIDENCY, &cnt->c6))
return -1;
}
if (do_snb_cstates)
if (get_msr(cnt->cpu, MSR_CORE_C7_RESIDENCY, &cnt->c7))
return -1;
if (do_nhm_cstates) {
if (get_msr(cnt->cpu, MSR_PKG_C3_RESIDENCY, &cnt->pc3))
return -1;
if (get_msr(cnt->cpu, MSR_PKG_C6_RESIDENCY, &cnt->pc6))
return -1;
}
if (do_snb_cstates) {
if (get_msr(cnt->cpu, MSR_PKG_C2_RESIDENCY, &cnt->pc2))
return -1;
if (get_msr(cnt->cpu, MSR_PKG_C7_RESIDENCY, &cnt->pc7))
return -1;
}
if (extra_msr_offset)
if (get_msr(cnt->cpu, extra_msr_offset, &cnt->extra_msr))
return -1;
}
return 0;
}
void print_nehalem_info(void)
{
unsigned long long msr;
unsigned int ratio;
if (!do_nehalem_platform_info)
return;
get_msr(0, MSR_NEHALEM_PLATFORM_INFO, &msr);
ratio = (msr >> 40) & 0xFF;
fprintf(stderr, "%d * %.0f = %.0f MHz max efficiency\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
fprintf(stderr, "%d * %.0f = %.0f MHz TSC frequency\n",
ratio, bclk, ratio * bclk);
if (verbose > 1)
fprintf(stderr, "MSR_NEHALEM_PLATFORM_INFO: 0x%llx\n", msr);
if (!do_nehalem_turbo_ratio_limit)
return;
get_msr(0, MSR_NEHALEM_TURBO_RATIO_LIMIT, &msr);
ratio = (msr >> 24) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 4 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 16) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 3 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 2 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 0) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 1 active cores\n",
ratio, bclk, ratio * bclk);
}
void free_counter_list(struct counters *list)
{
struct counters *p;
for (p = list; p; ) {
struct counters *free_me;
free_me = p;
p = p->next;
free(free_me);
}
}
void free_all_counters(void)
{
free_counter_list(cnt_even);
cnt_even = NULL;
free_counter_list(cnt_odd);
cnt_odd = NULL;
free_counter_list(cnt_delta);
cnt_delta = NULL;
free_counter_list(cnt_average);
cnt_average = NULL;
}
void insert_counters(struct counters **list,
struct counters *new)
{
struct counters *prev;
if (*list == NULL) {
new->next = *list;
*list = new;
return;
}
if (!summary_only)
show_cpu = 1;
if (((*list)->pkg > new->pkg) ||
(((*list)->pkg == new->pkg) && ((*list)->core > new->core)) ||
(((*list)->pkg == new->pkg) && ((*list)->core == new->core) && ((*list)->cpu > new->cpu))) {
new->next = *list;
*list = new;
return;
}
prev = *list;
while (prev->next && (prev->next->pkg < new->pkg)) {
prev = prev->next;
if (!summary_only)
show_pkg = 1;
}
while (prev->next && (prev->next->pkg == new->pkg)
&& (prev->next->core < new->core)) {
prev = prev->next;
if (!summary_only)
show_core = 1;
}
while (prev->next && (prev->next->pkg == new->pkg)
&& (prev->next->core == new->core)
&& (prev->next->cpu < new->cpu)) {
prev = prev->next;
}
new->next = prev->next;
prev->next = new;
}
void alloc_new_counters(int pkg, int core, int cpu)
{
struct counters *new;
if (verbose > 1)
printf("pkg%d core%d, cpu%d\n", pkg, core, cpu);
new = (struct counters *)calloc(1, sizeof(struct counters));
if (new == NULL) {
perror("calloc");
exit(1);
}
new->pkg = pkg;
new->core = core;
new->cpu = cpu;
insert_counters(&cnt_odd, new);
new = (struct counters *)calloc(1,
sizeof(struct counters));
if (new == NULL) {
perror("calloc");
exit(1);
}
new->pkg = pkg;
new->core = core;
new->cpu = cpu;
insert_counters(&cnt_even, new);
new = (struct counters *)calloc(1, sizeof(struct counters));
if (new == NULL) {
perror("calloc");
exit(1);
}
new->pkg = pkg;
new->core = core;
new->cpu = cpu;
insert_counters(&cnt_delta, new);
new = (struct counters *)calloc(1, sizeof(struct counters));
if (new == NULL) {
perror("calloc");
exit(1);
}
new->pkg = pkg;
new->core = core;
new->cpu = cpu;
cnt_average = new;
}
int get_physical_package_id(int cpu)
{
char path[64];
FILE *filep;
int pkg;
sprintf(path, "/sys/devices/system/cpu/cpu%d/topology/physical_package_id", cpu);
filep = fopen(path, "r");
if (filep == NULL) {
perror(path);
exit(1);
}
fscanf(filep, "%d", &pkg);
fclose(filep);
return pkg;
}
int get_core_id(int cpu)
{
char path[64];
FILE *filep;
int core;
sprintf(path, "/sys/devices/system/cpu/cpu%d/topology/core_id", cpu);
filep = fopen(path, "r");
if (filep == NULL) {
perror(path);
exit(1);
}
fscanf(filep, "%d", &core);
fclose(filep);
return core;
}
int for_all_cpus(void (func)(int, int, int))
{
FILE *fp;
int cpu_count;
int retval;
fp = fopen(proc_stat, "r");
if (fp == NULL) {
perror(proc_stat);
exit(1);
}
retval = fscanf(fp, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d\n");
if (retval != 0) {
perror("/proc/stat format");
exit(1);
}
for (cpu_count = 0; ; cpu_count++) {
int cpu;
retval = fscanf(fp, "cpu%u %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d\n", &cpu);
if (retval != 1)
break;
func(get_physical_package_id(cpu), get_core_id(cpu), cpu);
}
fclose(fp);
return cpu_count;
}
void re_initialize(void)
{
free_all_counters();
num_cpus = for_all_cpus(alloc_new_counters);
cpu_mask_uninit();
cpu_mask_init(num_cpus);
printf("turbostat: re-initialized with num_cpus %d\n", num_cpus);
}
void dummy(int pkg, int core, int cpu) { return; }
int verify_num_cpus(void)
{
int new_num_cpus;
new_num_cpus = for_all_cpus(dummy);
if (new_num_cpus != num_cpus) {
if (verbose)
printf("num_cpus was %d, is now %d\n",
num_cpus, new_num_cpus);
return -1;
}
return 0;
}
void turbostat_loop()
{
restart:
get_counters(cnt_even);
gettimeofday(&tv_even, (struct timezone *)NULL);
while (1) {
if (verify_num_cpus()) {
re_initialize();
goto restart;
}
sleep(interval_sec);
if (get_counters(cnt_odd)) {
re_initialize();
goto restart;
}
gettimeofday(&tv_odd, (struct timezone *)NULL);
compute_delta(cnt_odd, cnt_even, cnt_delta);
timersub(&tv_odd, &tv_even, &tv_delta);
compute_average(cnt_delta, cnt_average);
print_counters(cnt_delta);
sleep(interval_sec);
if (get_counters(cnt_even)) {
re_initialize();
goto restart;
}
gettimeofday(&tv_even, (struct timezone *)NULL);
compute_delta(cnt_even, cnt_odd, cnt_delta);
timersub(&tv_even, &tv_odd, &tv_delta);
compute_average(cnt_delta, cnt_average);
print_counters(cnt_delta);
}
}
void check_dev_msr()
{
struct stat sb;
if (stat("/dev/cpu/0/msr", &sb)) {
fprintf(stderr, "no /dev/cpu/0/msr\n");
fprintf(stderr, "Try \"# modprobe msr\"\n");
exit(-5);
}
}
void check_super_user()
{
if (getuid() != 0) {
fprintf(stderr, "must be root\n");
exit(-6);
}
}
int has_nehalem_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case 0x1A:
case 0x1E:
case 0x1F:
case 0x25:
case 0x2C:
case 0x2A:
case 0x2D:
case 0x3A:
case 0x3D:
return 1;
case 0x2E:
case 0x2F:
default:
return 0;
}
}
int is_snb(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case 0x2A:
case 0x2D:
return 1;
}
return 0;
}
double discover_bclk(unsigned int family, unsigned int model)
{
if (is_snb(family, model))
return 100.00;
else
return 133.33;
}
void check_cpuid()
{
unsigned int eax, ebx, ecx, edx, max_level;
unsigned int fms, family, model, stepping;
eax = ebx = ecx = edx = 0;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if (ebx == 0x756e6547 && edx == 0x49656e69 && ecx == 0x6c65746e)
genuine_intel = 1;
if (verbose)
fprintf(stderr, "%.4s%.4s%.4s ",
(char *)&ebx, (char *)&edx, (char *)&ecx);
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
family = (fms >> 8) & 0xf;
model = (fms >> 4) & 0xf;
stepping = fms & 0xf;
if (family == 6 || family == 0xf)
model += ((fms >> 16) & 0xf) << 4;
if (verbose)
fprintf(stderr, "%d CPUID levels; family:model:stepping 0x%x:%x:%x (%d:%d:%d)\n",
max_level, family, model, stepping, family, model, stepping);
if (!(edx & (1 << 5))) {
fprintf(stderr, "CPUID: no MSR\n");
exit(1);
}
ebx = ecx = edx = 0;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if (max_level < 0x80000007) {
fprintf(stderr, "CPUID: no invariant TSC (max_level 0x%x)\n", max_level);
exit(1);
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
has_invariant_tsc = edx & (1 << 8);
if (!has_invariant_tsc) {
fprintf(stderr, "No invariant TSC\n");
exit(1);
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
has_aperf = ecx & (1 << 0);
if (!has_aperf) {
fprintf(stderr, "No APERF MSR\n");
exit(1);
}
do_nehalem_platform_info = genuine_intel && has_invariant_tsc;
do_nhm_cstates = genuine_intel;
do_snb_cstates = is_snb(family, model);
bclk = discover_bclk(family, model);
do_nehalem_turbo_ratio_limit = has_nehalem_turbo_ratio_limit(family, model);
}
void usage()
{
fprintf(stderr, "%s: [-v] [-M MSR#] [-i interval_sec | command ...]\n",
progname);
exit(1);
}
int dir_filter(const struct dirent *dirp)
{
if (isdigit(dirp->d_name[0]))
return 1;
else
return 0;
}
int open_dev_cpu_msr(int dummy1)
{
return 0;
}
void turbostat_init()
{
check_cpuid();
check_dev_msr();
check_super_user();
num_cpus = for_all_cpus(alloc_new_counters);
cpu_mask_init(num_cpus);
if (verbose)
print_nehalem_info();
}
int fork_it(char **argv)
{
int retval;
pid_t child_pid;
get_counters(cnt_even);
gettimeofday(&tv_even, (struct timezone *)NULL);
child_pid = fork();
if (!child_pid) {
execvp(argv[0], argv);
} else {
int status;
if (child_pid == -1) {
perror("fork");
exit(1);
}
signal(SIGINT, SIG_IGN);
signal(SIGQUIT, SIG_IGN);
if (waitpid(child_pid, &status, 0) == -1) {
perror("wait");
exit(1);
}
}
get_counters(cnt_odd);
gettimeofday(&tv_odd, (struct timezone *)NULL);
retval = compute_delta(cnt_odd, cnt_even, cnt_delta);
timersub(&tv_odd, &tv_even, &tv_delta);
compute_average(cnt_delta, cnt_average);
if (!retval)
print_counters(cnt_delta);
fprintf(stderr, "%.6f sec\n", tv_delta.tv_sec + tv_delta.tv_usec/1000000.0);
return 0;
}
void cmdline(int argc, char **argv)
{
int opt;
progname = argv[0];
while ((opt = getopt(argc, argv, "+svi:M:")) != -1) {
switch (opt) {
case 's':
summary_only++;
break;
case 'v':
verbose++;
break;
case 'i':
interval_sec = atoi(optarg);
break;
case 'M':
sscanf(optarg, "%x", &extra_msr_offset);
if (verbose > 1)
fprintf(stderr, "MSR 0x%X\n", extra_msr_offset);
break;
default:
usage();
}
}
}
int main(int argc, char **argv)
{
cmdline(argc, argv);
if (verbose > 1)
fprintf(stderr, "turbostat Dec 6, 2010"
" - Len Brown <lenb@kernel.org>\n");
if (verbose > 1)
fprintf(stderr, "http://userweb.kernel.org/~lenb/acpi/utils/pmtools/turbostat/\n");
turbostat_init();
if (argc - optind)
return fork_it(argv + optind);
else
turbostat_loop();
return 0;
}
