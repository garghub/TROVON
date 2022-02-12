int bpf_prog1(struct pt_regs *ctx)
{
u64 count;
u32 key = bpf_get_smp_processor_id();
char fmt[] = "CPU-%d %llu\n";
count = bpf_perf_event_read(&my_map, key);
bpf_trace_printk(fmt, sizeof(fmt), key, count);
return 0;
}
