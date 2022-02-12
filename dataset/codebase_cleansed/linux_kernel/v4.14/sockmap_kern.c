int bpf_prog1(struct __sk_buff *skb)
{
return skb->len;
}
int bpf_prog2(struct __sk_buff *skb)
{
__u32 lport = skb->local_port;
__u32 rport = skb->remote_port;
int ret = 0;
if (lport == 10000)
ret = 10;
else
ret = 1;
bpf_printk("sockmap: %d -> %d @ %d\n", lport, bpf_ntohl(rport), ret);
return bpf_sk_redirect_map(skb, &sock_map, ret, 0);
}
int bpf_sockmap(struct bpf_sock_ops *skops)
{
__u32 lport, rport;
int op, err = 0, index, key, ret;
op = (int) skops->op;
switch (op) {
case BPF_SOCK_OPS_PASSIVE_ESTABLISHED_CB:
lport = skops->local_port;
rport = skops->remote_port;
if (lport == 10000) {
ret = 1;
err = bpf_sock_map_update(skops, &sock_map, &ret,
BPF_NOEXIST);
bpf_printk("passive(%i -> %i) map ctx update err: %d\n",
lport, bpf_ntohl(rport), err);
}
break;
case BPF_SOCK_OPS_ACTIVE_ESTABLISHED_CB:
lport = skops->local_port;
rport = skops->remote_port;
if (bpf_ntohl(rport) == 10001) {
ret = 10;
err = bpf_sock_map_update(skops, &sock_map, &ret,
BPF_NOEXIST);
bpf_printk("active(%i -> %i) map ctx update err: %d\n",
lport, bpf_ntohl(rport), err);
}
break;
default:
break;
}
return 0;
}
