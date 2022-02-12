int bpf_clamp(struct bpf_sock_ops *skops)
{
int bufsize = 150000;
int to_init = 10;
int clamp = 100;
int rv = 0;
int op;
if (bpf_ntohl(skops->remote_port) != 55601 && skops->local_port != 55601)
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
case BPF_SOCK_OPS_TIMEOUT_INIT:
rv = to_init;
break;
case BPF_SOCK_OPS_TCP_CONNECT_CB:
rv = bpf_setsockopt(skops, SOL_SOCKET, SO_SNDBUF,
&bufsize, sizeof(bufsize));
rv = rv*100 + bpf_setsockopt(skops, SOL_SOCKET,
SO_RCVBUF, &bufsize,
sizeof(bufsize));
break;
case BPF_SOCK_OPS_ACTIVE_ESTABLISHED_CB:
rv = bpf_setsockopt(skops, SOL_TCP,
TCP_BPF_SNDCWND_CLAMP,
&clamp, sizeof(clamp));
break;
case BPF_SOCK_OPS_PASSIVE_ESTABLISHED_CB:
rv = bpf_setsockopt(skops, SOL_TCP,
TCP_BPF_SNDCWND_CLAMP,
&clamp, sizeof(clamp));
rv = rv*100 + bpf_setsockopt(skops, SOL_SOCKET,
SO_SNDBUF, &bufsize,
sizeof(bufsize));
rv = rv*100 + bpf_setsockopt(skops, SOL_SOCKET,
SO_RCVBUF, &bufsize,
sizeof(bufsize));
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
