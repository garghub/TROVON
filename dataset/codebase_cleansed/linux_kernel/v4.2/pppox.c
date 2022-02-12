int register_pppox_proto(int proto_num, const struct pppox_proto *pp)
{
if (proto_num < 0 || proto_num > PX_MAX_PROTO)
return -EINVAL;
if (pppox_protos[proto_num])
return -EALREADY;
pppox_protos[proto_num] = pp;
return 0;
}
void unregister_pppox_proto(int proto_num)
{
if (proto_num >= 0 && proto_num <= PX_MAX_PROTO)
pppox_protos[proto_num] = NULL;
}
void pppox_unbind_sock(struct sock *sk)
{
if (sk->sk_state & (PPPOX_BOUND | PPPOX_CONNECTED | PPPOX_ZOMBIE)) {
ppp_unregister_channel(&pppox_sk(sk)->chan);
sk->sk_state = PPPOX_DEAD;
}
}
int pppox_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
struct sock *sk = sock->sk;
struct pppox_sock *po = pppox_sk(sk);
int rc;
lock_sock(sk);
switch (cmd) {
case PPPIOCGCHAN: {
int index;
rc = -ENOTCONN;
if (!(sk->sk_state & PPPOX_CONNECTED))
break;
rc = -EINVAL;
index = ppp_channel_index(&po->chan);
if (put_user(index , (int __user *) arg))
break;
rc = 0;
sk->sk_state |= PPPOX_BOUND;
break;
}
default:
rc = pppox_protos[sk->sk_protocol]->ioctl ?
pppox_protos[sk->sk_protocol]->ioctl(sock, cmd, arg) : -ENOTTY;
}
release_sock(sk);
return rc;
}
static int pppox_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
int rc = -EPROTOTYPE;
if (protocol < 0 || protocol > PX_MAX_PROTO)
goto out;
rc = -EPROTONOSUPPORT;
if (!pppox_protos[protocol])
request_module("pppox-proto-%d", protocol);
if (!pppox_protos[protocol] ||
!try_module_get(pppox_protos[protocol]->owner))
goto out;
rc = pppox_protos[protocol]->create(net, sock, kern);
module_put(pppox_protos[protocol]->owner);
out:
return rc;
}
static int __init pppox_init(void)
{
return sock_register(&pppox_proto_family);
}
static void __exit pppox_exit(void)
{
sock_unregister(PF_PPPOX);
}
