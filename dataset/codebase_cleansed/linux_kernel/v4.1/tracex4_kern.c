int bpf_prog1(struct pt_regs *ctx)
{
long ptr = ctx->si;
bpf_map_delete_elem(&my_map, &ptr);
return 0;
}
int bpf_prog2(struct pt_regs *ctx)
{
long ptr = ctx->ax;
long ip = 0;
bpf_probe_read(&ip, sizeof(ip), (void *)(ctx->bp + sizeof(ip)));
struct pair v = {
.val = bpf_ktime_get_ns(),
.ip = ip,
};
bpf_map_update_elem(&my_map, &ptr, &v, BPF_ANY);
return 0;
}
