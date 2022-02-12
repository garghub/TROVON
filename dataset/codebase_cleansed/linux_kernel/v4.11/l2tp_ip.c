static inline struct l2tp_ip_sock *l2tp_ip_sk(const struct sock *sk)
{
return (struct l2tp_ip_sock *)sk;
}
static struct sock *__l2tp_ip_bind_lookup(const struct net *net, __be32 laddr,
__be32 raddr, int dif, u32 tunnel_id)
{
struct sock *sk;
sk_for_each_bound(sk, &l2tp_ip_bind_table) {
const struct l2tp_ip_sock *l2tp = l2tp_ip_sk(sk);
const struct inet_sock *inet = inet_sk(sk);
if (!net_eq(sock_net(sk), net))
continue;
if (sk->sk_bound_dev_if && dif && sk->sk_bound_dev_if != dif)
continue;
if (inet->inet_rcv_saddr && laddr &&
inet->inet_rcv_saddr != laddr)
continue;
if (inet->inet_daddr && raddr && inet->inet_daddr != raddr)
continue;
if (l2tp->conn_id != tunnel_id)
continue;
goto found;
}
sk = NULL;
found:
return sk;
}
static int l2tp_ip_recv(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
struct sock *sk;
u32 session_id;
u32 tunnel_id;
unsigned char *ptr, *optr;
struct l2tp_session *session;
struct l2tp_tunnel *tunnel = NULL;
int length;
if (!pskb_may_pull(skb, 4))
goto discard;
optr = ptr = skb->data;
session_id = ntohl(*((__be32 *) ptr));
ptr += 4;
if (session_id == 0) {
__skb_pull(skb, 4);
goto pass_up;
}
session = l2tp_session_get(net, NULL, session_id, true);
if (!session)
goto discard;
tunnel = session->tunnel;
if (!tunnel)
goto discard_sess;
if (tunnel->debug & L2TP_MSG_DATA) {
length = min(32u, skb->len);
if (!pskb_may_pull(skb, length))
goto discard_sess;
optr = ptr = skb->data;
ptr += 4;
pr_debug("%s: ip recv\n", tunnel->name);
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, ptr, length);
}
l2tp_recv_common(session, skb, ptr, optr, 0, skb->len, tunnel->recv_payload_hook);
l2tp_session_dec_refcount(session);
return 0;
pass_up:
if (!pskb_may_pull(skb, 12))
goto discard;
if ((skb->data[0] & 0xc0) != 0xc0)
goto discard;
tunnel_id = ntohl(*(__be32 *) &skb->data[4]);
tunnel = l2tp_tunnel_find(net, tunnel_id);
if (tunnel) {
sk = tunnel->sock;
sock_hold(sk);
} else {
struct iphdr *iph = (struct iphdr *) skb_network_header(skb);
read_lock_bh(&l2tp_ip_lock);
sk = __l2tp_ip_bind_lookup(net, iph->daddr, iph->saddr,
inet_iif(skb), tunnel_id);
if (!sk) {
read_unlock_bh(&l2tp_ip_lock);
goto discard;
}
sock_hold(sk);
read_unlock_bh(&l2tp_ip_lock);
}
if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
goto discard_put;
nf_reset(skb);
return sk_receive_skb(sk, skb, 1);
discard_sess:
if (session->deref)
session->deref(session);
l2tp_session_dec_refcount(session);
goto discard;
discard_put:
sock_put(sk);
discard:
kfree_skb(skb);
return 0;
}
static int l2tp_ip_open(struct sock *sk)
{
inet_sk(sk)->inet_num = IPPROTO_L2TP;
write_lock_bh(&l2tp_ip_lock);
sk_add_node(sk, &l2tp_ip_table);
write_unlock_bh(&l2tp_ip_lock);
return 0;
}
static void l2tp_ip_close(struct sock *sk, long timeout)
{
write_lock_bh(&l2tp_ip_lock);
hlist_del_init(&sk->sk_bind_node);
sk_del_node_init(sk);
write_unlock_bh(&l2tp_ip_lock);
sk_common_release(sk);
}
static void l2tp_ip_destroy_sock(struct sock *sk)
{
struct sk_buff *skb;
struct l2tp_tunnel *tunnel = l2tp_sock_to_tunnel(sk);
while ((skb = __skb_dequeue_tail(&sk->sk_write_queue)) != NULL)
kfree_skb(skb);
if (tunnel) {
l2tp_tunnel_closeall(tunnel);
sock_put(sk);
}
sk_refcnt_debug_dec(sk);
}
static int l2tp_ip_bind(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
struct inet_sock *inet = inet_sk(sk);
struct sockaddr_l2tpip *addr = (struct sockaddr_l2tpip *) uaddr;
struct net *net = sock_net(sk);
int ret;
int chk_addr_ret;
if (addr_len < sizeof(struct sockaddr_l2tpip))
return -EINVAL;
if (addr->l2tp_family != AF_INET)
return -EINVAL;
lock_sock(sk);
ret = -EINVAL;
if (!sock_flag(sk, SOCK_ZAPPED))
goto out;
if (sk->sk_state != TCP_CLOSE)
goto out;
chk_addr_ret = inet_addr_type(net, addr->l2tp_addr.s_addr);
ret = -EADDRNOTAVAIL;
if (addr->l2tp_addr.s_addr && chk_addr_ret != RTN_LOCAL &&
chk_addr_ret != RTN_MULTICAST && chk_addr_ret != RTN_BROADCAST)
goto out;
if (addr->l2tp_addr.s_addr)
inet->inet_rcv_saddr = inet->inet_saddr = addr->l2tp_addr.s_addr;
if (chk_addr_ret == RTN_MULTICAST || chk_addr_ret == RTN_BROADCAST)
inet->inet_saddr = 0;
write_lock_bh(&l2tp_ip_lock);
if (__l2tp_ip_bind_lookup(net, addr->l2tp_addr.s_addr, 0,
sk->sk_bound_dev_if, addr->l2tp_conn_id)) {
write_unlock_bh(&l2tp_ip_lock);
ret = -EADDRINUSE;
goto out;
}
sk_dst_reset(sk);
l2tp_ip_sk(sk)->conn_id = addr->l2tp_conn_id;
sk_add_bind_node(sk, &l2tp_ip_bind_table);
sk_del_node_init(sk);
write_unlock_bh(&l2tp_ip_lock);
ret = 0;
sock_reset_flag(sk, SOCK_ZAPPED);
out:
release_sock(sk);
return ret;
}
static int l2tp_ip_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
struct sockaddr_l2tpip *lsa = (struct sockaddr_l2tpip *) uaddr;
int rc;
if (addr_len < sizeof(*lsa))
return -EINVAL;
if (ipv4_is_multicast(lsa->l2tp_addr.s_addr))
return -EINVAL;
lock_sock(sk);
if (sock_flag(sk, SOCK_ZAPPED)) {
rc = -EINVAL;
goto out_sk;
}
rc = __ip4_datagram_connect(sk, uaddr, addr_len);
if (rc < 0)
goto out_sk;
l2tp_ip_sk(sk)->peer_conn_id = lsa->l2tp_conn_id;
write_lock_bh(&l2tp_ip_lock);
hlist_del_init(&sk->sk_bind_node);
sk_add_bind_node(sk, &l2tp_ip_bind_table);
write_unlock_bh(&l2tp_ip_lock);
out_sk:
release_sock(sk);
return rc;
}
static int l2tp_ip_disconnect(struct sock *sk, int flags)
{
if (sock_flag(sk, SOCK_ZAPPED))
return 0;
return __udp_disconnect(sk, flags);
}
static int l2tp_ip_getname(struct socket *sock, struct sockaddr *uaddr,
int *uaddr_len, int peer)
{
struct sock *sk = sock->sk;
struct inet_sock *inet = inet_sk(sk);
struct l2tp_ip_sock *lsk = l2tp_ip_sk(sk);
struct sockaddr_l2tpip *lsa = (struct sockaddr_l2tpip *)uaddr;
memset(lsa, 0, sizeof(*lsa));
lsa->l2tp_family = AF_INET;
if (peer) {
if (!inet->inet_dport)
return -ENOTCONN;
lsa->l2tp_conn_id = lsk->peer_conn_id;
lsa->l2tp_addr.s_addr = inet->inet_daddr;
} else {
__be32 addr = inet->inet_rcv_saddr;
if (!addr)
addr = inet->inet_saddr;
lsa->l2tp_conn_id = lsk->conn_id;
lsa->l2tp_addr.s_addr = addr;
}
*uaddr_len = sizeof(*lsa);
return 0;
}
static int l2tp_ip_backlog_recv(struct sock *sk, struct sk_buff *skb)
{
int rc;
rc = sock_queue_rcv_skb(sk, skb);
if (rc < 0)
goto drop;
return 0;
drop:
IP_INC_STATS(sock_net(sk), IPSTATS_MIB_INDISCARDS);
kfree_skb(skb);
return 0;
}
static int l2tp_ip_sendmsg(struct sock *sk, struct msghdr *msg, size_t len)
{
struct sk_buff *skb;
int rc;
struct inet_sock *inet = inet_sk(sk);
struct rtable *rt = NULL;
struct flowi4 *fl4;
int connected = 0;
__be32 daddr;
lock_sock(sk);
rc = -ENOTCONN;
if (sock_flag(sk, SOCK_DEAD))
goto out;
if (msg->msg_name) {
DECLARE_SOCKADDR(struct sockaddr_l2tpip *, lip, msg->msg_name);
rc = -EINVAL;
if (msg->msg_namelen < sizeof(*lip))
goto out;
if (lip->l2tp_family != AF_INET) {
rc = -EAFNOSUPPORT;
if (lip->l2tp_family != AF_UNSPEC)
goto out;
}
daddr = lip->l2tp_addr.s_addr;
} else {
rc = -EDESTADDRREQ;
if (sk->sk_state != TCP_ESTABLISHED)
goto out;
daddr = inet->inet_daddr;
connected = 1;
}
rc = -ENOMEM;
skb = sock_wmalloc(sk, 2 + NET_SKB_PAD + sizeof(struct iphdr) +
4 + len, 0, GFP_KERNEL);
if (!skb)
goto error;
skb_reserve(skb, 2 + NET_SKB_PAD);
skb_reset_network_header(skb);
skb_reserve(skb, sizeof(struct iphdr));
skb_reset_transport_header(skb);
*((__be32 *) skb_put(skb, 4)) = 0;
rc = memcpy_from_msg(skb_put(skb, len), msg, len);
if (rc < 0) {
kfree_skb(skb);
goto error;
}
fl4 = &inet->cork.fl.u.ip4;
if (connected)
rt = (struct rtable *) __sk_dst_check(sk, 0);
rcu_read_lock();
if (rt == NULL) {
const struct ip_options_rcu *inet_opt;
inet_opt = rcu_dereference(inet->inet_opt);
if (inet_opt && inet_opt->opt.srr)
daddr = inet_opt->opt.faddr;
rt = ip_route_output_ports(sock_net(sk), fl4, sk,
daddr, inet->inet_saddr,
inet->inet_dport, inet->inet_sport,
sk->sk_protocol, RT_CONN_FLAGS(sk),
sk->sk_bound_dev_if);
if (IS_ERR(rt))
goto no_route;
if (connected) {
sk_setup_caps(sk, &rt->dst);
} else {
skb_dst_set(skb, &rt->dst);
goto xmit;
}
}
skb_dst_set_noref(skb, &rt->dst);
xmit:
rc = ip_queue_xmit(sk, skb, &inet->cork.fl);
rcu_read_unlock();
error:
if (rc >= 0)
rc = len;
out:
release_sock(sk);
return rc;
no_route:
rcu_read_unlock();
IP_INC_STATS(sock_net(sk), IPSTATS_MIB_OUTNOROUTES);
kfree_skb(skb);
rc = -EHOSTUNREACH;
goto out;
}
static int l2tp_ip_recvmsg(struct sock *sk, struct msghdr *msg,
size_t len, int noblock, int flags, int *addr_len)
{
struct inet_sock *inet = inet_sk(sk);
size_t copied = 0;
int err = -EOPNOTSUPP;
DECLARE_SOCKADDR(struct sockaddr_in *, sin, msg->msg_name);
struct sk_buff *skb;
if (flags & MSG_OOB)
goto out;
skb = skb_recv_datagram(sk, flags, noblock, &err);
if (!skb)
goto out;
copied = skb->len;
if (len < copied) {
msg->msg_flags |= MSG_TRUNC;
copied = len;
}
err = skb_copy_datagram_msg(skb, 0, msg, copied);
if (err)
goto done;
sock_recv_timestamp(msg, sk, skb);
if (sin) {
sin->sin_family = AF_INET;
sin->sin_addr.s_addr = ip_hdr(skb)->saddr;
sin->sin_port = 0;
memset(&sin->sin_zero, 0, sizeof(sin->sin_zero));
*addr_len = sizeof(*sin);
}
if (inet->cmsg_flags)
ip_cmsg_recv(msg, skb);
if (flags & MSG_TRUNC)
copied = skb->len;
done:
skb_free_datagram(sk, skb);
out:
return err ? err : copied;
}
int l2tp_ioctl(struct sock *sk, int cmd, unsigned long arg)
{
struct sk_buff *skb;
int amount;
switch (cmd) {
case SIOCOUTQ:
amount = sk_wmem_alloc_get(sk);
break;
case SIOCINQ:
spin_lock_bh(&sk->sk_receive_queue.lock);
skb = skb_peek(&sk->sk_receive_queue);
amount = skb ? skb->len : 0;
spin_unlock_bh(&sk->sk_receive_queue.lock);
break;
default:
return -ENOIOCTLCMD;
}
return put_user(amount, (int __user *)arg);
}
static int __init l2tp_ip_init(void)
{
int err;
pr_info("L2TP IP encapsulation support (L2TPv3)\n");
err = proto_register(&l2tp_ip_prot, 1);
if (err != 0)
goto out;
err = inet_add_protocol(&l2tp_ip_protocol, IPPROTO_L2TP);
if (err)
goto out1;
inet_register_protosw(&l2tp_ip_protosw);
return 0;
out1:
proto_unregister(&l2tp_ip_prot);
out:
return err;
}
static void __exit l2tp_ip_exit(void)
{
inet_unregister_protosw(&l2tp_ip_protosw);
inet_del_protocol(&l2tp_ip_protocol, IPPROTO_L2TP);
proto_unregister(&l2tp_ip_prot);
}
