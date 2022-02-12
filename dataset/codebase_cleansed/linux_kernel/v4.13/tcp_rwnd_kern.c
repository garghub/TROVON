int bpf_rwnd(struct bpf_sock_ops *skops)
{
int rv = -1;
int op;
if (bpf_ntohl(skops->remote_port) !=
55601 && skops->local_port != 55601)
return -1;
op = (int) skops->op;
#ifdef DEBUG
bpf_printk("BPF command: %d\n", op);
#endif
if (op == BPF_SOCK_OPS_RWND_INIT &&
skops->family == AF_INET6) {
if (skops->local_ip6[0] != skops->remote_ip6[0] ||
(bpf_ntohl(skops->local_ip6[1]) & 0xfffff000) !=
(bpf_ntohl(skops->remote_ip6[1]) & 0xfffff000))
rv = 40;
}
#ifdef DEBUG
bpf_printk("Returning %d\n", rv);
#endif
skops->reply = rv;
return 1;
}
