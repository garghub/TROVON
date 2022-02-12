int waker(struct pt_regs *ctx)
{
struct task_struct *p = (void *) PT_REGS_PARM1(ctx);
struct wokeby_t woke = {};
u32 pid;
pid = _(p->pid);
bpf_get_current_comm(&woke.name, sizeof(woke.name));
woke.ret = bpf_get_stackid(ctx, &stackmap, STACKID_FLAGS);
bpf_map_update_elem(&wokeby, &pid, &woke, BPF_ANY);
return 0;
}
static inline int update_counts(struct pt_regs *ctx, u32 pid, u64 delta)
{
struct key_t key = {};
struct wokeby_t *woke;
u64 zero = 0, *val;
bpf_get_current_comm(&key.target, sizeof(key.target));
key.tret = bpf_get_stackid(ctx, &stackmap, STACKID_FLAGS);
woke = bpf_map_lookup_elem(&wokeby, &pid);
if (woke) {
key.wret = woke->ret;
__builtin_memcpy(&key.waker, woke->name, TASK_COMM_LEN);
bpf_map_delete_elem(&wokeby, &pid);
}
val = bpf_map_lookup_elem(&counts, &key);
if (!val) {
bpf_map_update_elem(&counts, &key, &zero, BPF_NOEXIST);
val = bpf_map_lookup_elem(&counts, &key);
if (!val)
return 0;
}
(*val) += delta;
return 0;
}
int oncpu(struct pt_regs *ctx)
{
struct task_struct *p = (void *) PT_REGS_PARM1(ctx);
u64 delta, ts, *tsp;
u32 pid;
pid = _(p->pid);
ts = bpf_ktime_get_ns();
bpf_map_update_elem(&start, &pid, &ts, BPF_ANY);
pid = bpf_get_current_pid_tgid();
tsp = bpf_map_lookup_elem(&start, &pid);
if (!tsp)
return 0;
delta = bpf_ktime_get_ns() - *tsp;
bpf_map_delete_elem(&start, &pid);
delta = delta / 1000;
if (delta < MINBLOCK_US)
return 0;
return update_counts(ctx, pid, delta);
}
