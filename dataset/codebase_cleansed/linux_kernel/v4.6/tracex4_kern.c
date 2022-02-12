int bpf_prog1(struct pt_regs *ctx)
{
long ptr = PT_REGS_PARM2(ctx);
bpf_map_delete_elem(&my_map, &ptr);
return 0;
}
int bpf_prog2(struct pt_regs *ctx)
{
long ptr = PT_REGS_RC(ctx);
long ip = 0;
BPF_KRETPROBE_READ_RET_IP(ip, ctx);
struct pair v = {
.val = bpf_ktime_get_ns(),
.ip = ip,
};
bpf_map_update_elem(&my_map, &ptr, &v, BPF_ANY);
return 0;
}
