static void install_accept_all_seccomp(void)
{
struct sock_filter filter[] = {
BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
};
struct sock_fprog prog = {
.len = (unsigned short)(sizeof(filter)/sizeof(filter[0])),
.filter = filter,
};
if (prctl(PR_SET_SECCOMP, 2, &prog))
perror("prctl");
}
int main(int ac, char **argv)
{
FILE *f;
char filename[256];
struct rlimit r = {RLIM_INFINITY, RLIM_INFINITY};
snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);
setrlimit(RLIMIT_MEMLOCK, &r);
if (load_bpf_file(filename)) {
printf("%s", bpf_log_buf);
return 1;
}
install_accept_all_seccomp();
f = popen("dd if=/dev/zero of=/dev/null count=5", "r");
(void) f;
read_trace_pipe();
return 0;
}
