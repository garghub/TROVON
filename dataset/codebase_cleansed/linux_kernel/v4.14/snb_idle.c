static int snb_get_count(enum intel_snb_id id, unsigned long long *val,
unsigned int cpu)
{
int msr;
switch (id) {
case C7:
msr = MSR_CORE_C7_RESIDENCY;
break;
case PC2:
msr = MSR_PKG_C2_RESIDENCY;
break;
case PC7:
msr = MSR_PKG_C7_RESIDENCY;
break;
case TSC:
msr = MSR_TSC;
break;
default:
return -1;
};
if (read_msr(cpu, msr, val))
return -1;
return 0;
}
static int snb_get_count_percent(unsigned int id, double *percent,
unsigned int cpu)
{
*percent = 0.0;
if (!is_valid[cpu])
return -1;
*percent = (100.0 *
(current_count[id][cpu] - previous_count[id][cpu])) /
(tsc_at_measure_end - tsc_at_measure_start);
dprint("%s: previous: %llu - current: %llu - (%u)\n",
snb_cstates[id].name, previous_count[id][cpu],
current_count[id][cpu], cpu);
dprint("%s: tsc_diff: %llu - count_diff: %llu - percent: %2.f (%u)\n",
snb_cstates[id].name,
(unsigned long long) tsc_at_measure_end - tsc_at_measure_start,
current_count[id][cpu] - previous_count[id][cpu],
*percent, cpu);
return 0;
}
static int snb_start(void)
{
int num, cpu;
unsigned long long val;
for (num = 0; num < SNB_CSTATE_COUNT; num++) {
for (cpu = 0; cpu < cpu_count; cpu++) {
snb_get_count(num, &val, cpu);
previous_count[num][cpu] = val;
}
}
snb_get_count(TSC, &tsc_at_measure_start, base_cpu);
return 0;
}
static int snb_stop(void)
{
unsigned long long val;
int num, cpu;
snb_get_count(TSC, &tsc_at_measure_end, base_cpu);
for (num = 0; num < SNB_CSTATE_COUNT; num++) {
for (cpu = 0; cpu < cpu_count; cpu++) {
is_valid[cpu] = !snb_get_count(num, &val, cpu);
current_count[num][cpu] = val;
}
}
return 0;
}
static struct cpuidle_monitor *snb_register(void)
{
int num;
if (cpupower_cpu_info.vendor != X86_VENDOR_INTEL
|| cpupower_cpu_info.family != 6)
return NULL;
switch (cpupower_cpu_info.model) {
case 0x2A:
case 0x2D:
case 0x3A:
case 0x3E:
case 0x3C:
case 0x3F:
case 0x45:
case 0x46:
break;
default:
return NULL;
}
is_valid = calloc(cpu_count, sizeof(int));
for (num = 0; num < SNB_CSTATE_COUNT; num++) {
previous_count[num] = calloc(cpu_count,
sizeof(unsigned long long));
current_count[num] = calloc(cpu_count,
sizeof(unsigned long long));
}
intel_snb_monitor.name_len = strlen(intel_snb_monitor.name);
return &intel_snb_monitor;
}
void snb_unregister(void)
{
int num;
free(is_valid);
for (num = 0; num < SNB_CSTATE_COUNT; num++) {
free(previous_count[num]);
free(current_count[num]);
}
}
