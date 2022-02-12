static void aperfmperf_snapshot_khz(void *dummy)
{
u64 aperf, aperf_delta;
u64 mperf, mperf_delta;
struct aperfmperf_sample *s = this_cpu_ptr(&samples);
ktime_t now = ktime_get();
s64 time_delta = ktime_ms_delta(now, s->time);
unsigned long flags;
if (time_delta < APERFMPERF_CACHE_THRESHOLD_MS)
return;
local_irq_save(flags);
rdmsrl(MSR_IA32_APERF, aperf);
rdmsrl(MSR_IA32_MPERF, mperf);
local_irq_restore(flags);
aperf_delta = aperf - s->aperf;
mperf_delta = mperf - s->mperf;
if (mperf_delta == 0)
return;
s->time = now;
s->aperf = aperf;
s->mperf = mperf;
if (time_delta > APERFMPERF_STALE_THRESHOLD_MS)
s->khz = 0;
else
s->khz = div64_u64((cpu_khz * aperf_delta), mperf_delta);
}
unsigned int arch_freq_get_on_cpu(int cpu)
{
unsigned int khz;
if (!cpu_khz)
return 0;
if (!static_cpu_has(X86_FEATURE_APERFMPERF))
return 0;
smp_call_function_single(cpu, aperfmperf_snapshot_khz, NULL, 1);
khz = per_cpu(samples.khz, cpu);
if (khz)
return khz;
msleep(APERFMPERF_REFRESH_DELAY_MS);
smp_call_function_single(cpu, aperfmperf_snapshot_khz, NULL, 1);
return per_cpu(samples.khz, cpu);
}
