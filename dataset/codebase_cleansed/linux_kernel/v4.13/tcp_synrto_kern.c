int bpf_synrto(struct bpf_sock_ops *skops)
{
int rv = -1;
int op;
if (bpf_ntohl(skops->remote_port) != 55601 &&
skops->local_port != 55601)
return -1;
op = (int) skops->op;
#ifdef DEBUG
bpf_printk("BPF command: %d\n", op);
#endif
if (op == BPF_SOCK_OPS_TIMEOUT_INIT &&
skops->family == AF_INET6) {
if (skops->local_ip6[0] == skops->remote_ip6[0] &&
(bpf_ntohl(skops->local_ip6[1]) & 0xfff00000) ==
(bpf_ntohl(skops->remote_ip6[1]) & 0xfff00000))
rv = 10;
}
#ifdef DEBUG
bpf_printk("Returning %d\n", rv);
#endif
skops->reply = rv;
return 1;
}
