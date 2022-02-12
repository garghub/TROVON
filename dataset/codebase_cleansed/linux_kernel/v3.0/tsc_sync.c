static __cpuinit void check_tsc_warp(void)
{
cycles_t start, now, prev, end;
int i;
rdtsc_barrier();
start = get_cycles();
rdtsc_barrier();
end = start + tsc_khz * 20ULL;
now = start;
for (i = 0; ; i++) {
arch_spin_lock(&sync_lock);
prev = last_tsc;
rdtsc_barrier();
now = get_cycles();
rdtsc_barrier();
last_tsc = now;
arch_spin_unlock(&sync_lock);
if (unlikely(!(i & 7))) {
if (now > end || i > 10000000)
break;
cpu_relax();
touch_nmi_watchdog();
}
if (unlikely(prev > now)) {
arch_spin_lock(&sync_lock);
max_warp = max(max_warp, prev - now);
nr_warps++;
arch_spin_unlock(&sync_lock);
}
}
WARN(!(now-start),
"Warning: zero tsc calibration delta: %Ld [max: %Ld]\n",
now-start, end-start);
}
void __cpuinit check_tsc_sync_source(int cpu)
{
int cpus = 2;
if (unsynchronized_tsc())
return;
if (boot_cpu_has(X86_FEATURE_TSC_RELIABLE)) {
if (cpu == (nr_cpu_ids-1) || system_state != SYSTEM_BOOTING)
pr_info(
"Skipped synchronization checks as TSC is reliable.\n");
return;
}
atomic_set(&stop_count, 0);
while (atomic_read(&start_count) != cpus-1)
cpu_relax();
atomic_inc(&start_count);
check_tsc_warp();
while (atomic_read(&stop_count) != cpus-1)
cpu_relax();
if (nr_warps) {
pr_warning("TSC synchronization [CPU#%d -> CPU#%d]:\n",
smp_processor_id(), cpu);
pr_warning("Measured %Ld cycles TSC warp between CPUs, "
"turning off TSC clock.\n", max_warp);
mark_tsc_unstable("check_tsc_sync_source failed");
} else {
pr_debug("TSC synchronization [CPU#%d -> CPU#%d]: passed\n",
smp_processor_id(), cpu);
}
atomic_set(&start_count, 0);
nr_warps = 0;
max_warp = 0;
last_tsc = 0;
atomic_inc(&stop_count);
}
void __cpuinit check_tsc_sync_target(void)
{
int cpus = 2;
if (unsynchronized_tsc() || boot_cpu_has(X86_FEATURE_TSC_RELIABLE))
return;
atomic_inc(&start_count);
while (atomic_read(&start_count) != cpus)
cpu_relax();
check_tsc_warp();
atomic_inc(&stop_count);
while (atomic_read(&stop_count) != cpus)
cpu_relax();
}
