static void cpuidle_cpu_output(unsigned int cpu, int verbose)
{
int idlestates, idlestate;
char *tmp;
printf(_ ("Analyzing CPU %d:\n"), cpu);
idlestates = sysfs_get_idlestate_count(cpu);
if (idlestates == 0) {
printf(_("CPU %u: No idle states\n"), cpu);
return;
} else if (idlestates <= 0) {
printf(_("CPU %u: Can't read idle state info\n"), cpu);
return;
}
tmp = sysfs_get_idlestate_name(cpu, idlestates - 1);
if (!tmp) {
printf(_("Could not determine max idle state %u\n"),
idlestates - 1);
return;
}
printf(_("Number of idle states: %d\n"), idlestates);
printf(_("Available idle states:"));
for (idlestate = 1; idlestate < idlestates; idlestate++) {
tmp = sysfs_get_idlestate_name(cpu, idlestate);
if (!tmp)
continue;
printf(" %s", tmp);
free(tmp);
}
printf("\n");
if (!verbose)
return;
for (idlestate = 1; idlestate < idlestates; idlestate++) {
tmp = sysfs_get_idlestate_name(cpu, idlestate);
if (!tmp)
continue;
printf("%s:\n", tmp);
free(tmp);
tmp = sysfs_get_idlestate_desc(cpu, idlestate);
if (!tmp)
continue;
printf(_("Flags/Description: %s\n"), tmp);
free(tmp);
printf(_("Latency: %lu\n"),
sysfs_get_idlestate_latency(cpu, idlestate));
printf(_("Usage: %lu\n"),
sysfs_get_idlestate_usage(cpu, idlestate));
printf(_("Duration: %llu\n"),
sysfs_get_idlestate_time(cpu, idlestate));
}
printf("\n");
}
static void cpuidle_general_output(void)
{
char *tmp;
tmp = sysfs_get_cpuidle_driver();
if (!tmp) {
printf(_("Could not determine cpuidle driver\n"));
return;
}
printf(_("CPUidle driver: %s\n"), tmp);
free(tmp);
tmp = sysfs_get_cpuidle_governor();
if (!tmp) {
printf(_("Could not determine cpuidle governor\n"));
return;
}
printf(_("CPUidle governor: %s\n"), tmp);
free(tmp);
}
static void proc_cpuidle_cpu_output(unsigned int cpu)
{
long max_allowed_cstate = 2000000000;
int cstates, cstate;
cstates = sysfs_get_idlestate_count(cpu);
if (cstates == 0) {
} else if (cstates <= 0) {
printf(_("CPU %u: Can't read C-state info\n"), cpu);
return;
}
printf(_("active state: C0\n"));
printf(_("max_cstate: C%u\n"), cstates-1);
printf(_("maximum allowed latency: %lu usec\n"), max_allowed_cstate);
printf(_("states:\t\n"));
for (cstate = 1; cstate < cstates; cstate++) {
printf(_(" C%d: "
"type[C%d] "), cstate, cstate);
printf(_("promotion[--] demotion[--] "));
printf(_("latency[%03lu] "),
sysfs_get_idlestate_latency(cpu, cstate));
printf(_("usage[%08lu] "),
sysfs_get_idlestate_usage(cpu, cstate));
printf(_("duration[%020Lu] \n"),
sysfs_get_idlestate_time(cpu, cstate));
}
}
static inline void cpuidle_exit(int fail)
{
exit(EXIT_FAILURE);
}
int cmd_idle_info(int argc, char **argv)
{
extern char *optarg;
extern int optind, opterr, optopt;
int ret = 0, cont = 1, output_param = 0, verbose = 1;
unsigned int cpu = 0;
do {
ret = getopt_long(argc, argv, "os", info_opts, NULL);
if (ret == -1)
break;
switch (ret) {
case '?':
output_param = '?';
cont = 0;
break;
case 's':
verbose = 0;
break;
case -1:
cont = 0;
break;
case 'o':
if (output_param) {
output_param = -1;
cont = 0;
break;
}
output_param = ret;
break;
}
} while (cont);
switch (output_param) {
case -1:
printf(_("You can't specify more than one "
"output-specific argument\n"));
cpuidle_exit(EXIT_FAILURE);
case '?':
printf(_("invalid or unknown argument\n"));
cpuidle_exit(EXIT_FAILURE);
}
if (bitmask_isallclear(cpus_chosen))
bitmask_setbit(cpus_chosen, 0);
if (output_param == 0)
cpuidle_general_output();
for (cpu = bitmask_first(cpus_chosen);
cpu <= bitmask_last(cpus_chosen); cpu++) {
if (!bitmask_isbitset(cpus_chosen, cpu) ||
cpufreq_cpu_exists(cpu))
continue;
switch (output_param) {
case 'o':
proc_cpuidle_cpu_output(cpu);
break;
case 0:
printf("\n");
cpuidle_cpu_output(cpu, verbose);
break;
}
}
return EXIT_SUCCESS;
}
