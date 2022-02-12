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
unsigned long try_msr_calibrate_tsc(void)
{
u32 lo, hi, ratio, freq_id, freq;
unsigned long res;
int cpu_index;
cpu_index = match_cpu(boot_cpu_data.x86, boot_cpu_data.x86_model);
if (cpu_index < 0)
return 0;
if (freq_desc_tables[cpu_index].msr_plat) {
rdmsr(MSR_PLATFORM_INFO, lo, hi);
ratio = (lo >> 8) & 0x1f;
} else {
rdmsr(MSR_IA32_PERF_STATUS, lo, hi);
ratio = (hi >> 8) & 0x1f;
}
pr_info("Maximum core-clock to bus-clock ratio: 0x%x\n", ratio);
if (!ratio)
goto fail;
rdmsr(MSR_FSB_FREQ, lo, hi);
freq_id = lo & 0x7;
freq = id_to_freq(cpu_index, freq_id);
pr_info("Resolved frequency ID: %u, frequency: %u KHz\n",
freq_id, freq);
if (!freq)
goto fail;
res = freq * ratio;
pr_info("TSC runs at %lu KHz\n", res);
#ifdef CONFIG_X86_LOCAL_APIC
lapic_timer_frequency = (freq * 1000) / HZ;
pr_info("lapic_timer_frequency = %d\n", lapic_timer_frequency);
#endif
return res;
fail:
pr_warn("Fast TSC calibration using MSR failed\n");
return 0;
}
