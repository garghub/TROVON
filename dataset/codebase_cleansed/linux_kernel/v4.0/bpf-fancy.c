int main(int argc, char **argv)
{
struct bpf_labels l = {
.count = 0,
};
static const char msg1[] = "Please type something: ";
static const char msg2[] = "You typed: ";
char buf[256];
struct sock_filter filter[] = {
LOAD_SYSCALL_NR,
SYSCALL(__NR_exit, ALLOW),
SYSCALL(__NR_exit_group, ALLOW),
SYSCALL(__NR_write, JUMP(&l, write_fd)),
SYSCALL(__NR_read, JUMP(&l, read)),
DENY,
LABEL(&l, read),
ARG(0),
JNE(STDIN_FILENO, DENY),
ARG(1),
JNE((unsigned long)buf, DENY),
ARG(2),
JGE(sizeof(buf), DENY),
ALLOW,
LABEL(&l, write_fd),
ARG(0),
JEQ(STDOUT_FILENO, JUMP(&l, write_buf)),
JEQ(STDERR_FILENO, JUMP(&l, write_buf)),
DENY,
LABEL(&l, write_buf),
ARG(1),
JEQ((unsigned long)msg1, JUMP(&l, msg1_len)),
JEQ((unsigned long)msg2, JUMP(&l, msg2_len)),
JEQ((unsigned long)buf, JUMP(&l, buf_len)),
DENY,
LABEL(&l, msg1_len),
ARG(2),
JLT(sizeof(msg1), ALLOW),
DENY,
LABEL(&l, msg2_len),
ARG(2),
JLT(sizeof(msg2), ALLOW),
DENY,
LABEL(&l, buf_len),
ARG(2),
JLT(sizeof(buf), ALLOW),
DENY,
};
struct sock_fprog prog = {
.filter = filter,
.len = (unsigned short)(sizeof(filter)/sizeof(filter[0])),
};
ssize_t bytes;
bpf_resolve_jumps(&l, filter, sizeof(filter)/sizeof(*filter));
if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
perror("prctl(NO_NEW_PRIVS)");
return 1;
}
if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
perror("prctl(SECCOMP)");
return 1;
}
syscall(__NR_write, STDOUT_FILENO, msg1, strlen(msg1));
bytes = syscall(__NR_read, STDIN_FILENO, buf, sizeof(buf)-1);
bytes = (bytes > 0 ? bytes : 0);
syscall(__NR_write, STDERR_FILENO, msg2, strlen(msg2));
syscall(__NR_write, STDERR_FILENO, buf, bytes);
syscall(__NR_write, STDERR_FILENO, msg2, strlen(msg2)+2);
return 0;
}
