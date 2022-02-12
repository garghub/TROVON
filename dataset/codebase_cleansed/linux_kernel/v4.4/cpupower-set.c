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
int perf_bias:1;
};
int params;
} params;
int perf_bias = 0;
int ret = 0;
setlocale(LC_ALL, "");
textdomain(PACKAGE);
params.params = 0;
while ((ret = getopt_long(argc, argv, "b:",
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
default:
print_wrong_arg_exit();
}
};
if (!params.params)
print_wrong_arg_exit();
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
