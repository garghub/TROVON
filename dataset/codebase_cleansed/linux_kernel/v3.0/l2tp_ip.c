static inline struct l2tp_ip_sock *l2tp_ip_sk(const struct sock *sk)
{
return (struct l2tp_ip_sock *)sk;
}
static struct sock *__l2tp_ip_bind_lookup(struct net *net, __be32 laddr, int dif, u32 tunnel_id)
{
struct hlist_node *node;
struct sock *sk;
sk_for_each_bound(sk, node, &l2tp_ip_bind_table) {
struct inet_sock *inet = inet_sk(sk);
struct l2tp_ip_sock *l2tp = l2tp_ip_sk(sk);
if (l2tp == NULL)
continue;
if ((l2tp->conn_id == tunnel_id) &&
net_eq(sock_net(sk), net) &&
!(inet->inet_rcv_saddr && inet->inet_rcv_saddr != laddr) &&
!(sk->sk_bound_dev_if && sk->sk_bound_dev_if != dif))
goto found;
}
sk = NULL;
found:
return sk;
}
static inline struct sock *l2tp_ip_bind_lookup(struct net *net, __be32 laddr, int dif, u32 tunnel_id)
{
struct sock *sk = __l2tp_ip_bind_lookup(net, laddr, dif, tunnel_id);
if (sk)
sock_hold(sk);
return sk;
}
static int l2tp_ip_recv(struct sk_buff *skb)
{
struct sock *sk;
u32 session_id;
u32 tunnel_id;
unsigned char *ptr, *optr;
struct l2tp_session *session;
struct l2tp_tunnel *tunnel = NULL;
int length;
int offset;
optr = ptr = skb->data;
if (!pskb_may_pull(skb, 4))
goto discard;
session_id = ntohl(*((__be32 *) ptr));
ptr += 4;
if (session_id == 0) {
__skb_pull(skb, 4);
goto pass_up;
}
session = l2tp_session_find(&init_net, NULL, session_id);
if (session == NULL)
goto discard;
tunnel = session->tunnel;
if (tunnel == NULL)
goto discard;
if (tunnel->debug & L2TP_MSG_DATA) {
length = min(32u, skb->len);
if (!pskb_may_pull(skb, length))
goto discard;
printk(KERN_DEBUG "%s: ip recv: ", tunnel->name);
offset = 0;
do {
printk(" %02X", ptr[offset]);
} while (++offset < length);
printk("\n");
}
l2tp_recv_common(session, skb, ptr, optr, 0, skb->len, tunnel->recv_payload_hook);
return 0;
pass_up:
if (!pskb_may_pull(skb, 12))
goto discard;
if ((skb->data[0] & 0xc0) != 0xc0)
goto discard;
tunnel_id = ntohl(*(__be32 *) &skb->data[4]);
tunnel = l2tp_tunnel_find(&init_net, tunnel_id);
if (tunnel != NULL)
sk = tunnel->sock;
else {
struct iphdr *iph = (struct iphdr *) skb_network_header(skb);
read_lock_bh(&l2tp_ip_lock);
sk = __l2tp_ip_bind_lookup(&init_net, iph->daddr, 0, tunnel_id);
read_unlock_bh(&l2tp_ip_lock);
}
if (sk == NULL)
goto discard;
sock_hold(sk);
if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
goto discard_put;
nf_reset(skb);
return sk_receive_skb(sk, skb, 1);
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
hlist_del_init(&sk->sk_node);
write_unlock_bh(&l2tp_ip_lock);
sk_common_release(sk);
}
static void l2tp_ip_destroy_sock(struct sock *sk)
{
struct sk_buff *skb;
while ((skb = __skb_dequeue_tail(&sk->sk_write_queue)) != NULL)
kfree_skb(skb);
sk_refcnt_debug_dec(sk);
}
static int l2tp_ip_bind(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
struct inet_sock *inet = inet_sk(sk);
struct sockaddr_l2tpip *addr = (struct sockaddr_l2tpip *) uaddr;
int ret = -EINVAL;
int chk_addr_ret;
ret = -EADDRINUSE;
read_lock_bh(&l2tp_ip_lock);
if (__l2tp_ip_bind_lookup(&init_net, addr->l2tp_addr.s_addr, sk->sk_bound_dev_if, addr->l2tp_conn_id))
goto out_in_use;
read_unlock_bh(&l2tp_ip_lock);
lock_sock(sk);
if (sk->sk_state != TCP_CLOSE || addr_len < sizeof(struct sockaddr_l2tpip))
goto out;
chk_addr_ret = inet_addr_type(&init_net, addr->l2tp_addr.s_addr);
ret = -EADDRNOTAVAIL;
if (addr->l2tp_addr.s_addr && chk_addr_ret != RTN_LOCAL &&
chk_addr_ret != RTN_MULTICAST && chk_addr_ret != RTN_BROADCAST)
goto out;
inet->inet_rcv_saddr = inet->inet_saddr = addr->l2tp_addr.s_addr;
if (chk_addr_ret == RTN_MULTICAST || chk_addr_ret == RTN_BROADCAST)
inet->inet_saddr = 0;
sk_dst_reset(sk);
l2tp_ip_sk(sk)->conn_id = addr->l2tp_conn_id;
write_lock_bh(&l2tp_ip_lock);
sk_add_bind_node(sk, &l2tp_ip_bind_table);
sk_del_node_init(sk);
write_unlock_bh(&l2tp_ip_lock);
ret = 0;
out:
release_sock(sk);
return ret;
out_in_use:
read_unlock_bh(&l2tp_ip_lock);
return ret;
}
static int l2tp_ip_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
struct sockaddr_l2tpip *lsa = (struct sockaddr_l2tpip *) uaddr;
struct inet_sock *inet = inet_sk(sk);
struct flowi4 *fl4;
struct rtable *rt;
__be32 saddr;
int oif, rc;
rc = -EINVAL;
if (addr_len < sizeof(*lsa))
goto out;
rc = -EAFNOSUPPORT;
if (lsa->l2tp_family != AF_INET)
goto out;
lock_sock(sk);
sk_dst_reset(sk);
oif = sk->sk_bound_dev_if;
saddr = inet->inet_saddr;
rc = -EINVAL;
if (ipv4_is_multicast(lsa->l2tp_addr.s_addr))
goto out;
fl4 = &inet->cork.fl.u.ip4;
rt = ip_route_connect(fl4, lsa->l2tp_addr.s_addr, saddr,
RT_CONN_FLAGS(sk), oif,
IPPROTO_L2TP,
0, 0, sk, true);
if (IS_ERR(rt)) {
rc = PTR_ERR(rt);
if (rc == -ENETUNREACH)
IP_INC_STATS_BH(&init_net, IPSTATS_MIB_OUTNOROUTES);
goto out;
}
rc = -ENETUNREACH;
if (rt->rt_flags & (RTCF_MULTICAST | RTCF_BROADCAST)) {
ip_rt_put(rt);
goto out;
}
l2tp_ip_sk(sk)->peer_conn_id = lsa->l2tp_conn_id;
if (!inet->inet_saddr)
inet->inet_saddr = fl4->saddr;
if (!inet->inet_rcv_saddr)
inet->inet_rcv_saddr = fl4->saddr;
inet->inet_daddr = fl4->daddr;
sk->sk_state = TCP_ESTABLISHED;
inet->inet_id = jiffies;
sk_dst_set(sk, &rt->dst);
write_lock_bh(&l2tp_ip_lock);
hlist_del_init(&sk->sk_bind_node);
sk_add_bind_node(sk, &l2tp_ip_bind_table);
write_unlock_bh(&l2tp_ip_lock);
rc = 0;
out:
release_sock(sk);
return rc;
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
if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
goto drop;
nf_reset(skb);
rc = sock_queue_rcv_skb(sk, skb);
if (rc < 0)
goto drop;
return 0;
drop:
IP_INC_STATS(&init_net, IPSTATS_MIB_INDISCARDS);
kfree_skb(skb);
return -1;
}
static int l2tp_ip_sendmsg(struct kiocb *iocb, struct sock *sk, struct msghdr *msg, size_t len)
{
struct sk_buff *skb;
int rc;
struct l2tp_ip_sock *lsa = l2tp_ip_sk(sk);
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
struct sockaddr_l2tpip *lip = (struct sockaddr_l2tpip *) msg->msg_name;
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
if (sk->sk_state != TCP_ESTABLISHED)
return -EDESTADDRREQ;
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
rc = memcpy_fromiovec(skb_put(skb, len), msg->msg_iov, len);
if (rc < 0) {
kfree_skb(skb);
goto error;
}
fl4 = &inet->cork.fl.u.ip4;
if (connected)
rt = (struct rtable *) __sk_dst_check(sk, 0);
if (rt == NULL) {
struct ip_options_rcu *inet_opt;
rcu_read_lock();
inet_opt = rcu_dereference(inet->inet_opt);
if (inet_opt && inet_opt->opt.srr)
daddr = inet_opt->opt.faddr;
rcu_read_unlock();
rt = ip_route_output_ports(sock_net(sk), fl4, sk,
daddr, inet->inet_saddr,
inet->inet_dport, inet->inet_sport,
sk->sk_protocol, RT_CONN_FLAGS(sk),
sk->sk_bound_dev_if);
if (IS_ERR(rt))
goto no_route;
sk_setup_caps(sk, &rt->dst);
}
skb_dst_set(skb, dst_clone(&rt->dst));
rc = ip_queue_xmit(skb, &inet->cork.fl);
error:
if (rc >= 0) {
lsa->tx_packets++;
lsa->tx_bytes += len;
rc = len;
} else {
lsa->tx_errors++;
}
out:
release_sock(sk);
return rc;
no_route:
IP_INC_STATS(sock_net(sk), IPSTATS_MIB_OUTNOROUTES);
kfree_skb(skb);
rc = -EHOSTUNREACH;
goto out;
}
static int l2tp_ip_recvmsg(struct kiocb *iocb, struct sock *sk, struct msghdr *msg,
size_t len, int noblock, int flags, int *addr_len)
{
struct inet_sock *inet = inet_sk(sk);
struct l2tp_ip_sock *lsk = l2tp_ip_sk(sk);
size_t copied = 0;
int err = -EOPNOTSUPP;
struct sockaddr_in *sin = (struct sockaddr_in *)msg->msg_name;
struct sk_buff *skb;
if (flags & MSG_OOB)
goto out;
if (addr_len)
*addr_len = sizeof(*sin);
skb = skb_recv_datagram(sk, flags, noblock, &err);
if (!skb)
goto out;
copied = skb->len;
if (len < copied) {
msg->msg_flags |= MSG_TRUNC;
copied = len;
}
err = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, copied);
if (err)
goto done;
sock_recv_timestamp(msg, sk, skb);
if (sin) {
sin->sin_family = AF_INET;
sin->sin_addr.s_addr = ip_hdr(skb)->saddr;
sin->sin_port = 0;
memset(&sin->sin_zero, 0, sizeof(sin->sin_zero));
}
if (inet->cmsg_flags)
ip_cmsg_recv(msg, skb);
if (flags & MSG_TRUNC)
copied = skb->len;
done:
skb_free_datagram(sk, skb);
out:
if (err) {
lsk->rx_errors++;
return err;
}
lsk->rx_packets++;
lsk->rx_bytes += copied;
return copied;
}
static int __init l2tp_ip_init(void)
{
int err;
printk(KERN_INFO "L2TP IP encapsulation support (L2TPv3)\n");
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
