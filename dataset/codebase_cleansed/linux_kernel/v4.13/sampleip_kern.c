int do_sample(struct bpf_perf_event_data *ctx)
{
u64 ip;
u32 *value, init_val = 1;
ip = PT_REGS_IP(&ctx->regs);
value = bpf_map_lookup_elem(&ip_map, &ip);
if (value)
*value += 1;
else
bpf_map_update_elem(&ip_map, &ip, &init_val, BPF_NOEXIST);
return 0;
}
