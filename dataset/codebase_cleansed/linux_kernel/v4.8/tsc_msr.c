static int match_cpu(u8 family, u8 model)
{
int i;
for (i = 0; i < ARRAY_SIZE(freq_desc_tables); i++) {
if ((family == freq_desc_tables[i].x86_family) &&
(model == freq_desc_tables[i].x86_model))
return i;
}
return -1;
}
unsigned long cpu_khz_from_msr(void)
{
u32 lo, hi, ratio, freq_id, freq;
unsigned long res;
int cpu_index;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return 0;
cpu_index = match_cpu(boot_cpu_data.x86, boot_cpu_data.x86_model);
if (cpu_index < 0)
return 0;
if (freq_desc_tables[cpu_index].msr_plat) {
rdmsr(MSR_PLATFORM_INFO, lo, hi);
ratio = (lo >> 8) & 0xff;
} else {
rdmsr(MSR_IA32_PERF_STATUS, lo, hi);
ratio = (hi >> 8) & 0x1f;
}
rdmsr(MSR_FSB_FREQ, lo, hi);
freq_id = lo & 0x7;
freq = id_to_freq(cpu_index, freq_id);
res = freq * ratio;
#ifdef CONFIG_X86_LOCAL_APIC
lapic_timer_frequency = (freq * 1000) / HZ;
#endif
return res;
}
