static void print_wrong_arg_exit(void)
{
printf(_("invalid or unknown argument\n"));
exit(EXIT_FAILURE);
}
int cmd_set(int argc, char **argv)
{
extern char *optarg;
extern int optind, opterr, optopt;
unsigned int cpu;
union {
struct {
int sched_mc:1;
int sched_smt:1;
int perf_bias:1;
};
int params;
} params;
int sched_mc = 0, sched_smt = 0, perf_bias = 0;
int ret = 0;
setlocale(LC_ALL, "");
textdomain(PACKAGE);
params.params = 0;
while ((ret = getopt_long(argc, argv, "m:s:b:",
set_opts, NULL)) != -1) {
switch (ret) {
case 'b':
if (params.perf_bias)
print_wrong_arg_exit();
perf_bias = atoi(optarg);
if (perf_bias < 0 || perf_bias > 15) {
printf(_("--perf-bias param out "
"of range [0-%d]\n"), 15);
print_wrong_arg_exit();
}
params.perf_bias = 1;
break;
case 'm':
if (params.sched_mc)
print_wrong_arg_exit();
sched_mc = atoi(optarg);
if (sched_mc < 0 || sched_mc > 2) {
printf(_("--sched-mc param out "
"of range [0-%d]\n"), 2);
print_wrong_arg_exit();
}
params.sched_mc = 1;
break;
case 's':
if (params.sched_smt)
print_wrong_arg_exit();
sched_smt = atoi(optarg);
if (sched_smt < 0 || sched_smt > 2) {
printf(_("--sched-smt param out "
"of range [0-%d]\n"), 2);
print_wrong_arg_exit();
}
params.sched_smt = 1;
break;
default:
print_wrong_arg_exit();
}
};
if (!params.params)
print_wrong_arg_exit();
if (params.sched_mc) {
ret = sysfs_set_sched("mc", sched_mc);
if (ret)
fprintf(stderr, _("Error setting sched-mc %s\n"),
(ret == -ENODEV) ? "not supported" : "");
}
if (params.sched_smt) {
ret = sysfs_set_sched("smt", sched_smt);
if (ret)
fprintf(stderr, _("Error setting sched-smt %s\n"),
(ret == -ENODEV) ? "not supported" : "");
}
if (bitmask_isallclear(cpus_chosen))
bitmask_setall(cpus_chosen);
for (cpu = bitmask_first(cpus_chosen);
cpu <= bitmask_last(cpus_chosen); cpu++) {
if (!bitmask_isbitset(cpus_chosen, cpu) ||
cpufreq_cpu_exists(cpu))
continue;
if (params.perf_bias) {
ret = msr_intel_set_perf_bias(cpu, perf_bias);
if (ret) {
fprintf(stderr, _("Error setting perf-bias "
"value on CPU %d\n"), cpu);
break;
}
}
}
return ret;
}
