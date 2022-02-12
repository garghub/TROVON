int bpf_prog1(struct pt_regs *ctx)
{
int sc_nr = (int)PT_REGS_PARM1(ctx);
bpf_tail_call(ctx, &progs, sc_nr);
if (sc_nr >= __NR_getuid && sc_nr <= __NR_getsid) {
char fmt[] = "syscall=%d (one of get/set uid/pid/gid)\n";
bpf_trace_printk(fmt, sizeof(fmt), sc_nr);
}
return 0;
}
PROG(SYS__NR_write)(struct pt_regs *ctx)
{
struct seccomp_data sd;
bpf_probe_read(&sd, sizeof(sd), (void *)PT_REGS_PARM2(ctx));
if (sd.args[2] == 512) {
char fmt[] = "write(fd=%d, buf=%p, size=%d)\n";
bpf_trace_printk(fmt, sizeof(fmt),
sd.args[0], sd.args[1], sd.args[2]);
}
return 0;
}
PROG(SYS__NR_read)(struct pt_regs *ctx)
{
struct seccomp_data sd;
bpf_probe_read(&sd, sizeof(sd), (void *)PT_REGS_PARM2(ctx));
if (sd.args[2] > 128 && sd.args[2] <= 1024) {
char fmt[] = "read(fd=%d, buf=%p, size=%d)\n";
bpf_trace_printk(fmt, sizeof(fmt),
sd.args[0], sd.args[1], sd.args[2]);
}
return 0;
}
PROG(SYS__NR_mmap)(struct pt_regs *ctx)
{
char fmt[] = "mmap\n";
bpf_trace_printk(fmt, sizeof(fmt));
return 0;
}
