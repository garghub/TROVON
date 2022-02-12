int bpf_prog1(struct pt_regs *ctx)
{
struct S {
u64 pid;
u64 cookie;
} data;
memset(&data, 0, sizeof(data));
data.pid = bpf_get_current_pid_tgid();
data.cookie = 0x12345678;
bpf_perf_event_output(ctx, &my_map, 0, &data, sizeof(data));
return 0;
}
