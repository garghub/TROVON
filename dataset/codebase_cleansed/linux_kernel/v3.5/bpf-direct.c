static void emulator(int nr, siginfo_t *info, void *void_context)
{
ucontext_t *ctx = (ucontext_t *)(void_context);
int syscall;
char *buf;
ssize_t bytes;
size_t len;
if (info->si_code != SYS_SECCOMP)
return;
if (!ctx)
return;
syscall = ctx->uc_mcontext.gregs[REG_SYSCALL];
buf = (char *) ctx->uc_mcontext.gregs[REG_ARG1];
len = (size_t) ctx->uc_mcontext.gregs[REG_ARG2];
if (syscall != __NR_write)
return;
if (ctx->uc_mcontext.gregs[REG_ARG0] != STDERR_FILENO)
return;
ctx->uc_mcontext.gregs[REG_RESULT] = -1;
if (write(STDOUT_FILENO, "[ERR] ", 6) > 0) {
bytes = write(STDOUT_FILENO, buf, len);
ctx->uc_mcontext.gregs[REG_RESULT] = bytes;
}
return;
}
static int install_emulator(void)
{
struct sigaction act;
sigset_t mask;
memset(&act, 0, sizeof(act));
sigemptyset(&mask);
sigaddset(&mask, SIGSYS);
act.sa_sigaction = &emulator;
act.sa_flags = SA_SIGINFO;
if (sigaction(SIGSYS, &act, NULL) < 0) {
perror("sigaction");
return -1;
}
if (sigprocmask(SIG_UNBLOCK, &mask, NULL)) {
perror("sigprocmask");
return -1;
}
return 0;
}
static int install_filter(void)
{
struct sock_filter filter[] = {
BPF_STMT(BPF_LD+BPF_W+BPF_ABS, syscall_nr),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_rt_sigreturn, 0, 1),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
#ifdef __NR_sigreturn
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_sigreturn, 0, 1),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
#endif
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_exit_group, 0, 1),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_exit, 0, 1),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_read, 1, 0),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_write, 3, 2),
BPF_STMT(BPF_LD+BPF_W+BPF_ABS, syscall_arg(0)),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, STDIN_FILENO, 4, 0),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_KILL),
BPF_STMT(BPF_LD+BPF_W+BPF_ABS, syscall_arg(0)),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, STDOUT_FILENO, 1, 0),
BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, STDERR_FILENO, 1, 2),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_TRAP),
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_KILL),
};
struct sock_fprog prog = {
.len = (unsigned short)(sizeof(filter)/sizeof(filter[0])),
.filter = filter,
};
if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
perror("prctl(NO_NEW_PRIVS)");
return 1;
}
if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
perror("prctl");
return 1;
}
return 0;
}
int main(int argc, char **argv)
{
char buf[4096];
ssize_t bytes = 0;
if (install_emulator())
return 1;
if (install_filter())
return 1;
syscall(__NR_write, STDOUT_FILENO,
payload("OHAI! WHAT IS YOUR NAME? "));
bytes = syscall(__NR_read, STDIN_FILENO, buf, sizeof(buf));
syscall(__NR_write, STDOUT_FILENO, payload("HELLO, "));
syscall(__NR_write, STDOUT_FILENO, buf, bytes);
syscall(__NR_write, STDERR_FILENO,
payload("Error message going to STDERR\n"));
return 0;
}
int main(void)
{
return 1;
}
