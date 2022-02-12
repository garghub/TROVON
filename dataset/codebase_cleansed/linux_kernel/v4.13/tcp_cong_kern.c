int bpf_cong(struct bpf_sock_ops *skops)
{
char cong[] = "dctcp";
int rv = 0;
int op;
if (bpf_ntohl(skops->remote_port) != 55601 &&
skops->local_port != 55601)
return -1;
op = (int) skops->op;
#ifdef DEBUG
bpf_printk("BPF command: %d\n", op);
#endif
if (skops->family == AF_INET6 &&
skops->local_ip6[0] == skops->remote_ip6[0] &&
(bpf_ntohl(skops->local_ip6[1]) & 0xfff00000) ==
(bpf_ntohl(skops->remote_ip6[1]) & 0xfff00000)) {
switch (op) {
case BPF_SOCK_OPS_NEEDS_ECN:
rv = 1;
break;
case BPF_SOCK_OPS_ACTIVE_ESTABLISHED_CB:
rv = bpf_setsockopt(skops, SOL_TCP, TCP_CONGESTION,
cong, sizeof(cong));
break;
case BPF_SOCK_OPS_PASSIVE_ESTABLISHED_CB:
rv = bpf_setsockopt(skops, SOL_TCP, TCP_CONGESTION,
cong, sizeof(cong));
break;
default:
rv = -1;
}
} else {
rv = -1;
}
#ifdef DEBUG
bpf_printk("Returning %d\n", rv);
#endif
skops->reply = rv;
return 1;
}
