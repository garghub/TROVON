static int hidp_sock_release(struct socket *sock)
{
struct sock *sk = sock->sk;
BT_DBG("sock %p sk %p", sock, sk);
if (!sk)
return 0;
sock_orphan(sk);
sock_put(sk);
return 0;
}
static int hidp_sock_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *) arg;
struct hidp_connadd_req ca;
struct hidp_conndel_req cd;
struct hidp_connlist_req cl;
struct hidp_conninfo ci;
struct socket *csock;
struct socket *isock;
int err;
BT_DBG("cmd %x arg %lx", cmd, arg);
switch (cmd) {
case HIDPCONNADD:
if (!capable(CAP_NET_ADMIN))
return -EACCES;
if (copy_from_user(&ca, argp, sizeof(ca)))
return -EFAULT;
csock = sockfd_lookup(ca.ctrl_sock, &err);
if (!csock)
return err;
isock = sockfd_lookup(ca.intr_sock, &err);
if (!isock) {
sockfd_put(csock);
return err;
}
if (csock->sk->sk_state != BT_CONNECTED ||
isock->sk->sk_state != BT_CONNECTED) {
sockfd_put(csock);
sockfd_put(isock);
return -EBADFD;
}
err = hidp_add_connection(&ca, csock, isock);
if (!err) {
if (copy_to_user(argp, &ca, sizeof(ca)))
err = -EFAULT;
} else {
sockfd_put(csock);
sockfd_put(isock);
}
return err;
case HIDPCONNDEL:
if (!capable(CAP_NET_ADMIN))
return -EACCES;
if (copy_from_user(&cd, argp, sizeof(cd)))
return -EFAULT;
return hidp_del_connection(&cd);
case HIDPGETCONNLIST:
if (copy_from_user(&cl, argp, sizeof(cl)))
return -EFAULT;
if (cl.cnum <= 0)
return -EINVAL;
err = hidp_get_connlist(&cl);
if (!err && copy_to_user(argp, &cl, sizeof(cl)))
return -EFAULT;
return err;
case HIDPGETCONNINFO:
if (copy_from_user(&ci, argp, sizeof(ci)))
return -EFAULT;
err = hidp_get_conninfo(&ci);
if (!err && copy_to_user(argp, &ci, sizeof(ci)))
return -EFAULT;
return err;
}
return -EINVAL;
}
static int hidp_sock_compat_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
if (cmd == HIDPGETCONNLIST) {
struct hidp_connlist_req cl;
uint32_t uci;
int err;
if (get_user(cl.cnum, (uint32_t __user *) arg) ||
get_user(uci, (u32 __user *) (arg + 4)))
return -EFAULT;
cl.ci = compat_ptr(uci);
if (cl.cnum <= 0)
return -EINVAL;
err = hidp_get_connlist(&cl);
if (!err && put_user(cl.cnum, (uint32_t __user *) arg))
err = -EFAULT;
return err;
} else if (cmd == HIDPCONNADD) {
struct compat_hidp_connadd_req ca;
struct hidp_connadd_req __user *uca;
uca = compat_alloc_user_space(sizeof(*uca));
if (copy_from_user(&ca, (void __user *) arg, sizeof(ca)))
return -EFAULT;
if (put_user(ca.ctrl_sock, &uca->ctrl_sock) ||
put_user(ca.intr_sock, &uca->intr_sock) ||
put_user(ca.parser, &uca->parser) ||
put_user(ca.rd_size, &uca->rd_size) ||
put_user(compat_ptr(ca.rd_data), &uca->rd_data) ||
put_user(ca.country, &uca->country) ||
put_user(ca.subclass, &uca->subclass) ||
put_user(ca.vendor, &uca->vendor) ||
put_user(ca.product, &uca->product) ||
put_user(ca.version, &uca->version) ||
put_user(ca.flags, &uca->flags) ||
put_user(ca.idle_to, &uca->idle_to) ||
copy_to_user(&uca->name[0], &ca.name[0], 128))
return -EFAULT;
arg = (unsigned long) uca;
}
return hidp_sock_ioctl(sock, cmd, arg);
}
static int hidp_sock_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
BT_DBG("sock %p", sock);
if (sock->type != SOCK_RAW)
return -ESOCKTNOSUPPORT;
sk = sk_alloc(net, PF_BLUETOOTH, GFP_ATOMIC, &hidp_proto);
if (!sk)
return -ENOMEM;
sock_init_data(sock, sk);
sock->ops = &hidp_sock_ops;
sock->state = SS_UNCONNECTED;
sock_reset_flag(sk, SOCK_ZAPPED);
sk->sk_protocol = protocol;
sk->sk_state = BT_OPEN;
return 0;
}
int __init hidp_init_sockets(void)
{
int err;
err = proto_register(&hidp_proto, 0);
if (err < 0)
return err;
err = bt_sock_register(BTPROTO_HIDP, &hidp_sock_family_ops);
if (err < 0)
goto error;
return 0;
error:
BT_ERR("Can't register HIDP socket");
proto_unregister(&hidp_proto);
return err;
}
void __exit hidp_cleanup_sockets(void)
{
if (bt_sock_unregister(BTPROTO_HIDP) < 0)
BT_ERR("Can't unregister HIDP socket");
proto_unregister(&hidp_proto);
}
