static size_t syscall_arg__scnprintf_socket_type(char *bf, size_t size, struct syscall_arg *arg)
{
size_t printed;
int type = arg->val,
flags = type & ~SOCK_TYPE_MASK;
type &= SOCK_TYPE_MASK;
switch (type) {
#define P_SK_TYPE(n) case SOCK_##n: printed = scnprintf(bf, size, #n); break;
P_SK_TYPE(STREAM);
P_SK_TYPE(DGRAM);
P_SK_TYPE(RAW);
P_SK_TYPE(RDM);
P_SK_TYPE(SEQPACKET);
P_SK_TYPE(DCCP);
P_SK_TYPE(PACKET);
#undef P_SK_TYPE
default:
printed = scnprintf(bf, size, "%#x", type);
}
#define P_SK_FLAG(n) \
if (flags & SOCK_##n) { \
printed += scnprintf(bf + printed, size - printed, "|%s", #n); \
flags &= ~SOCK_##n; \
}
P_SK_FLAG(CLOEXEC);
P_SK_FLAG(NONBLOCK);
#undef P_SK_FLAG
if (flags)
printed += scnprintf(bf + printed, size - printed, "|%#x", flags);
return printed;
}
