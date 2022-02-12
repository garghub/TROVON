int bpf_prog1(struct bpf_sock *sk)
{
char fmt[] = "socket: family %d type %d protocol %d\n";
bpf_trace_printk(fmt, sizeof(fmt), sk->family, sk->type, sk->protocol);
if (sk->family == PF_INET6 &&
sk->type == SOCK_RAW &&
sk->protocol == IPPROTO_ICMPV6)
return 0;
return 1;
}
int bpf_prog2(struct bpf_sock *sk)
{
char fmt[] = "socket: family %d type %d protocol %d\n";
bpf_trace_printk(fmt, sizeof(fmt), sk->family, sk->type, sk->protocol);
if (sk->family == PF_INET &&
sk->type == SOCK_RAW &&
sk->protocol == IPPROTO_ICMP)
return 0;
return 1;
}
