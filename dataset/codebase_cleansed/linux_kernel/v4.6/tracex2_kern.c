int bpf_prog2(struct pt_regs *ctx)
{
long loc = 0;
long init_val = 1;
long *value;
BPF_KPROBE_READ_RET_IP(loc, ctx);
value = bpf_map_lookup_elem(&my_map, &loc);
if (value)
*value += 1;
else
bpf_map_update_elem(&my_map, &loc, &init_val, BPF_ANY);
return 0;
}
static unsigned int log2(unsigned int v)
{
unsigned int r;
unsigned int shift;
r = (v > 0xFFFF) << 4; v >>= r;
shift = (v > 0xFF) << 3; v >>= shift; r |= shift;
shift = (v > 0xF) << 2; v >>= shift; r |= shift;
shift = (v > 0x3) << 1; v >>= shift; r |= shift;
r |= (v >> 1);
return r;
}
static unsigned int log2l(unsigned long v)
{
unsigned int hi = v >> 32;
if (hi)
return log2(hi) + 32;
else
return log2(v);
}
int bpf_prog3(struct pt_regs *ctx)
{
long write_size = PT_REGS_PARM3(ctx);
long init_val = 1;
long *value;
struct hist_key key = {};
key.index = log2l(write_size);
key.pid_tgid = bpf_get_current_pid_tgid();
key.uid_gid = bpf_get_current_uid_gid();
bpf_get_current_comm(&key.comm, sizeof(key.comm));
value = bpf_map_lookup_elem(&my_hist_map, &key);
if (value)
__sync_fetch_and_add(value, 1);
else
bpf_map_update_elem(&my_hist_map, &key, &init_val, BPF_ANY);
return 0;
}
