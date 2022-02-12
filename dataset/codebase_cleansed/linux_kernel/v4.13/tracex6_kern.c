int bpf_prog1(struct pt_regs *ctx)
{
u32 key = bpf_get_smp_processor_id();
u64 count, *val;
s64 error;
count = bpf_perf_event_read(&counters, key);
error = (s64)count;
if (error <= -2 && error >= -22)
return 0;
val = bpf_map_lookup_elem(&values, &key);
if (val)
*val = count;
else
bpf_map_update_elem(&values, &key, &count, BPF_NOEXIST);
return 0;
}
