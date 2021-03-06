int sock_diag_check_cookie(void *sk, __u32 *cookie)
{
if ((cookie[0] != INET_DIAG_NOCOOKIE ||
cookie[1] != INET_DIAG_NOCOOKIE) &&
((u32)(unsigned long)sk != cookie[0] ||
(u32)((((unsigned long)sk) >> 31) >> 1) != cookie[1]))
return -ESTALE;
else
return 0;
}
void sock_diag_save_cookie(void *sk, __u32 *cookie)
{
cookie[0] = (u32)(unsigned long)sk;
cookie[1] = (u32)(((unsigned long)sk >> 31) >> 1);
}
int sock_diag_put_meminfo(struct sock *sk, struct sk_buff *skb, int attrtype)
{
__u32 *mem;
mem = RTA_DATA(__RTA_PUT(skb, attrtype, SK_MEMINFO_VARS * sizeof(__u32)));
mem[SK_MEMINFO_RMEM_ALLOC] = sk_rmem_alloc_get(sk);
mem[SK_MEMINFO_RCVBUF] = sk->sk_rcvbuf;
mem[SK_MEMINFO_WMEM_ALLOC] = sk_wmem_alloc_get(sk);
mem[SK_MEMINFO_SNDBUF] = sk->sk_sndbuf;
mem[SK_MEMINFO_FWD_ALLOC] = sk->sk_forward_alloc;
mem[SK_MEMINFO_WMEM_QUEUED] = sk->sk_wmem_queued;
mem[SK_MEMINFO_OPTMEM] = atomic_read(&sk->sk_omem_alloc);
return 0;
rtattr_failure:
return -EMSGSIZE;
}
void sock_diag_register_inet_compat(int (*fn)(struct sk_buff *skb, struct nlmsghdr *nlh))
{
mutex_lock(&sock_diag_table_mutex);
inet_rcv_compat = fn;
mutex_unlock(&sock_diag_table_mutex);
}
void sock_diag_unregister_inet_compat(int (*fn)(struct sk_buff *skb, struct nlmsghdr *nlh))
{
mutex_lock(&sock_diag_table_mutex);
inet_rcv_compat = NULL;
mutex_unlock(&sock_diag_table_mutex);
}
int sock_diag_register(const struct sock_diag_handler *hndl)
{
int err = 0;
if (hndl->family >= AF_MAX)
return -EINVAL;
mutex_lock(&sock_diag_table_mutex);
if (sock_diag_handlers[hndl->family])
err = -EBUSY;
else
sock_diag_handlers[hndl->family] = hndl;
mutex_unlock(&sock_diag_table_mutex);
return err;
}
void sock_diag_unregister(const struct sock_diag_handler *hnld)
{
int family = hnld->family;
if (family >= AF_MAX)
return;
mutex_lock(&sock_diag_table_mutex);
BUG_ON(sock_diag_handlers[family] != hnld);
sock_diag_handlers[family] = NULL;
mutex_unlock(&sock_diag_table_mutex);
}
static const inline struct sock_diag_handler *sock_diag_lock_handler(int family)
{
if (sock_diag_handlers[family] == NULL)
request_module("net-pf-%d-proto-%d-type-%d", PF_NETLINK,
NETLINK_SOCK_DIAG, family);
mutex_lock(&sock_diag_table_mutex);
return sock_diag_handlers[family];
}
static inline void sock_diag_unlock_handler(const struct sock_diag_handler *h)
{
mutex_unlock(&sock_diag_table_mutex);
}
static int __sock_diag_rcv_msg(struct sk_buff *skb, struct nlmsghdr *nlh)
{
int err;
struct sock_diag_req *req = NLMSG_DATA(nlh);
const struct sock_diag_handler *hndl;
if (nlmsg_len(nlh) < sizeof(*req))
return -EINVAL;
hndl = sock_diag_lock_handler(req->sdiag_family);
if (hndl == NULL)
err = -ENOENT;
else
err = hndl->dump(skb, nlh);
sock_diag_unlock_handler(hndl);
return err;
}
static int sock_diag_rcv_msg(struct sk_buff *skb, struct nlmsghdr *nlh)
{
int ret;
switch (nlh->nlmsg_type) {
case TCPDIAG_GETSOCK:
case DCCPDIAG_GETSOCK:
if (inet_rcv_compat == NULL)
request_module("net-pf-%d-proto-%d-type-%d", PF_NETLINK,
NETLINK_SOCK_DIAG, AF_INET);
mutex_lock(&sock_diag_table_mutex);
if (inet_rcv_compat != NULL)
ret = inet_rcv_compat(skb, nlh);
else
ret = -EOPNOTSUPP;
mutex_unlock(&sock_diag_table_mutex);
return ret;
case SOCK_DIAG_BY_FAMILY:
return __sock_diag_rcv_msg(skb, nlh);
default:
return -EINVAL;
}
}
static void sock_diag_rcv(struct sk_buff *skb)
{
mutex_lock(&sock_diag_mutex);
netlink_rcv_skb(skb, &sock_diag_rcv_msg);
mutex_unlock(&sock_diag_mutex);
}
static int __init sock_diag_init(void)
{
sock_diag_nlsk = netlink_kernel_create(&init_net, NETLINK_SOCK_DIAG, 0,
sock_diag_rcv, NULL, THIS_MODULE);
return sock_diag_nlsk == NULL ? -ENOMEM : 0;
}
static void __exit sock_diag_exit(void)
{
netlink_kernel_release(sock_diag_nlsk);
}
