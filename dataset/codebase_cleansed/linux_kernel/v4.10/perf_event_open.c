static size_t syscall_arg__scnprintf_perf_flags(char *bf, size_t size,
struct syscall_arg *arg)
{
int printed = 0, flags = arg->val;
if (flags == 0)
return 0;
#define P_FLAG(n) \
if (flags & PERF_FLAG_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
flags &= ~PERF_FLAG_##n; \
}
P_FLAG(FD_NO_GROUP);
P_FLAG(FD_OUTPUT);
P_FLAG(PID_CGROUP);
P_FLAG(FD_CLOEXEC);
#undef P_FLAG
if (flags)
printed += scnprintf(bf + printed, size - printed, "%s%#x", printed ? "|" : "", flags);
return printed;
}
