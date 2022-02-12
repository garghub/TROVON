int bpf_prog1(struct bpf_perf_event_data *ctx)
{
char fmt[] = "CPU-%d period %lld ip %llx";
u32 cpu = bpf_get_smp_processor_id();
struct key_t key;
u64 *val, one = 1;
if (ctx->sample_period < 10000)
return 0;
bpf_get_current_comm(&key.comm, sizeof(key.comm));
key.kernstack = bpf_get_stackid(ctx, &stackmap, KERN_STACKID_FLAGS);
key.userstack = bpf_get_stackid(ctx, &stackmap, USER_STACKID_FLAGS);
if ((int)key.kernstack < 0 && (int)key.userstack < 0) {
bpf_trace_printk(fmt, sizeof(fmt), cpu, ctx->sample_period,
PT_REGS_IP(&ctx->regs));
return 0;
}
val = bpf_map_lookup_elem(&counts, &key);
if (val)
(*val)++;
else
bpf_map_update_elem(&counts, &key, &one, BPF_NOEXIST);
return 0;
}
