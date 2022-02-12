static inline struct l2tp_ip6_sock *l2tp_ip6_sk(const struct sock *sk)
{
return (struct l2tp_ip6_sock *)sk;
}
static struct sock *__l2tp_ip6_bind_lookup(struct net *net,
struct in6_addr *laddr,
int dif, u32 tunnel_id)
{
struct hlist_node *node;
struct sock *sk;
sk_for_each_bound(sk, node, &l2tp_ip6_bind_table) {
struct in6_addr *addr = inet6_rcv_saddr(sk);
struct l2tp_ip6_sock *l2tp = l2tp_ip6_sk(sk);
if (l2tp == NULL)
continue;
if ((l2tp->conn_id == tunnel_id) &&
net_eq(sock_net(sk), net) &&
!(addr && ipv6_addr_equal(addr, laddr)) &&
!(sk->sk_bound_dev_if && sk->sk_bound_dev_if != dif))
goto found;
}
sk = NULL;
found:
return sk;
}
static inline struct sock *l2tp_ip6_bind_lookup(struct net *net,
struct in6_addr *laddr,
int dif, u32 tunnel_id)
{
struct sock *sk = __l2tp_ip6_bind_lookup(net, laddr, dif, tunnel_id);
if (sk)
sock_hold(sk);
return sk;
}
static int l2tp_ip6_recv(struct sk_buff *skb)
{
struct sock *sk;
u32 session_id;
u32 tunnel_id;
unsigned char *ptr, *optr;
struct l2tp_session *session;
struct l2tp_tunnel *tunnel = NULL;
int length;
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
pr_debug("%s: ip recv\n", tunnel->name);
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, ptr, length);
}
l2tp_recv_common(session, skb, ptr, optr, 0, skb->len,
tunnel->recv_payload_hook);
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
struct ipv6hdr *iph = ipv6_hdr(skb);
read_lock_bh(&l2tp_ip6_lock);
sk = __l2tp_ip6_bind_lookup(&init_net, &iph->daddr,
0, tunnel_id);
read_unlock_bh(&l2tp_ip6_lock);
}
if (sk == NULL)
goto discard;
sock_hold(sk);
if (!xfrm6_policy_check(sk, XFRM_POLICY_IN, skb))
goto discard_put;
nf_reset(skb);
return sk_receive_skb(sk, skb, 1);
discard_put:
sock_put(sk);
discard:
kfree_skb(skb);
return 0;
}
static int l2tp_ip6_open(struct sock *sk)
{
inet_sk(sk)->inet_num = IPPROTO_L2TP;
write_lock_bh(&l2tp_ip6_lock);
sk_add_node(sk, &l2tp_ip6_table);
write_unlock_bh(&l2tp_ip6_lock);
return 0;
}
static void l2tp_ip6_close(struct sock *sk, long timeout)
{
write_lock_bh(&l2tp_ip6_lock);
hlist_del_init(&sk->sk_bind_node);
sk_del_node_init(sk);
write_unlock_bh(&l2tp_ip6_lock);
sk_common_release(sk);
}
static void l2tp_ip6_destroy_sock(struct sock *sk)
{
lock_sock(sk);
ip6_flush_pending_frames(sk);
release_sock(sk);
inet6_destroy_sock(sk);
}
static int l2tp_ip6_bind(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
struct inet_sock *inet = inet_sk(sk);
struct ipv6_pinfo *np = inet6_sk(sk);
struct sockaddr_l2tpip6 *addr = (struct sockaddr_l2tpip6 *) uaddr;
__be32 v4addr = 0;
int addr_type;
int err;
if (!sock_flag(sk, SOCK_ZAPPED))
return -EINVAL;
if (addr->l2tp_family != AF_INET6)
return -EINVAL;
if (addr_len < sizeof(*addr))
return -EINVAL;
addr_type = ipv6_addr_type(&addr->l2tp_addr);
if (addr_type == IPV6_ADDR_MAPPED)
return -EADDRNOTAVAIL;
if (addr_type & IPV6_ADDR_MULTICAST)
return -EADDRNOTAVAIL;
err = -EADDRINUSE;
read_lock_bh(&l2tp_ip6_lock);
if (__l2tp_ip6_bind_lookup(&init_net, &addr->l2tp_addr,
sk->sk_bound_dev_if, addr->l2tp_conn_id))
goto out_in_use;
read_unlock_bh(&l2tp_ip6_lock);
lock_sock(sk);
err = -EINVAL;
if (sk->sk_state != TCP_CLOSE)
goto out_unlock;
rcu_read_lock();
if (addr_type != IPV6_ADDR_ANY) {
struct net_device *dev = NULL;
if (addr_type & IPV6_ADDR_LINKLOCAL) {
if (addr_len >= sizeof(struct sockaddr_in6) &&
addr->l2tp_scope_id) {
sk->sk_bound_dev_if = addr->l2tp_scope_id;
}
if (!sk->sk_bound_dev_if)
goto out_unlock_rcu;
err = -ENODEV;
dev = dev_get_by_index_rcu(sock_net(sk),
sk->sk_bound_dev_if);
if (!dev)
goto out_unlock_rcu;
}
v4addr = LOOPBACK4_IPV6;
err = -EADDRNOTAVAIL;
if (!ipv6_chk_addr(sock_net(sk), &addr->l2tp_addr, dev, 0))
goto out_unlock_rcu;
}
rcu_read_unlock();
inet->inet_rcv_saddr = inet->inet_saddr = v4addr;
np->rcv_saddr = addr->l2tp_addr;
np->saddr = addr->l2tp_addr;
l2tp_ip6_sk(sk)->conn_id = addr->l2tp_conn_id;
write_lock_bh(&l2tp_ip6_lock);
sk_add_bind_node(sk, &l2tp_ip6_bind_table);
sk_del_node_init(sk);
write_unlock_bh(&l2tp_ip6_lock);
sock_reset_flag(sk, SOCK_ZAPPED);
release_sock(sk);
return 0;
out_unlock_rcu:
rcu_read_unlock();
out_unlock:
release_sock(sk);
return err;
out_in_use:
read_unlock_bh(&l2tp_ip6_lock);
return err;
}
static int l2tp_ip6_connect(struct sock *sk, struct sockaddr *uaddr,
int addr_len)
{
struct sockaddr_l2tpip6 *lsa = (struct sockaddr_l2tpip6 *) uaddr;
struct sockaddr_in6 *usin = (struct sockaddr_in6 *) uaddr;
struct in6_addr *daddr;
int addr_type;
int rc;
if (sock_flag(sk, SOCK_ZAPPED))
return -EINVAL;
if (addr_len < sizeof(*lsa))
return -EINVAL;
addr_type = ipv6_addr_type(&usin->sin6_addr);
if (addr_type & IPV6_ADDR_MULTICAST)
return -EINVAL;
if (addr_type & IPV6_ADDR_MAPPED) {
daddr = &usin->sin6_addr;
if (ipv4_is_multicast(daddr->s6_addr32[3]))
return -EINVAL;
}
rc = ip6_datagram_connect(sk, uaddr, addr_len);
lock_sock(sk);
l2tp_ip6_sk(sk)->peer_conn_id = lsa->l2tp_conn_id;
write_lock_bh(&l2tp_ip6_lock);
hlist_del_init(&sk->sk_bind_node);
sk_add_bind_node(sk, &l2tp_ip6_bind_table);
write_unlock_bh(&l2tp_ip6_lock);
release_sock(sk);
return rc;
}
static int l2tp_ip6_disconnect(struct sock *sk, int flags)
{
if (sock_flag(sk, SOCK_ZAPPED))
return 0;
return udp_disconnect(sk, flags);
}
static int l2tp_ip6_getname(struct socket *sock, struct sockaddr *uaddr,
int *uaddr_len, int peer)
{
struct sockaddr_l2tpip6 *lsa = (struct sockaddr_l2tpip6 *)uaddr;
struct sock *sk = sock->sk;
struct ipv6_pinfo *np = inet6_sk(sk);
struct l2tp_ip6_sock *lsk = l2tp_ip6_sk(sk);
lsa->l2tp_family = AF_INET6;
lsa->l2tp_flowinfo = 0;
lsa->l2tp_scope_id = 0;
lsa->l2tp_unused = 0;
if (peer) {
if (!lsk->peer_conn_id)
return -ENOTCONN;
lsa->l2tp_conn_id = lsk->peer_conn_id;
lsa->l2tp_addr = np->daddr;
if (np->sndflow)
lsa->l2tp_flowinfo = np->flow_label;
} else {
if (ipv6_addr_any(&np->rcv_saddr))
lsa->l2tp_addr = np->saddr;
else
lsa->l2tp_addr = np->rcv_saddr;
lsa->l2tp_conn_id = lsk->conn_id;
}
if (ipv6_addr_type(&lsa->l2tp_addr) & IPV6_ADDR_LINKLOCAL)
lsa->l2tp_scope_id = sk->sk_bound_dev_if;
*uaddr_len = sizeof(*lsa);
return 0;
}
static int l2tp_ip6_backlog_recv(struct sock *sk, struct sk_buff *skb)
{
int rc;
rc = sock_queue_rcv_skb(sk, skb);
if (rc < 0)
goto drop;
return 0;
drop:
IP_INC_STATS(&init_net, IPSTATS_MIB_INDISCARDS);
kfree_skb(skb);
return -1;
}
static int l2tp_ip6_push_pending_frames(struct sock *sk)
{
struct sk_buff *skb;
__be32 *transhdr = NULL;
int err = 0;
skb = skb_peek(&sk->sk_write_queue);
if (skb == NULL)
goto out;
transhdr = (__be32 *)skb_transport_header(skb);
*transhdr = 0;
err = ip6_push_pending_frames(sk);
out:
return err;
}
static int l2tp_ip6_sendmsg(struct kiocb *iocb, struct sock *sk,
struct msghdr *msg, size_t len)
{
struct ipv6_txoptions opt_space;
struct sockaddr_l2tpip6 *lsa =
(struct sockaddr_l2tpip6 *) msg->msg_name;
struct in6_addr *daddr, *final_p, final;
struct ipv6_pinfo *np = inet6_sk(sk);
struct ipv6_txoptions *opt = NULL;
struct ip6_flowlabel *flowlabel = NULL;
struct dst_entry *dst = NULL;
struct flowi6 fl6;
int addr_len = msg->msg_namelen;
int hlimit = -1;
int tclass = -1;
int dontfrag = -1;
int transhdrlen = 4;
int ulen = len + transhdrlen;
int err;
if (len > INT_MAX)
return -EMSGSIZE;
if (msg->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
memset(&fl6, 0, sizeof(fl6));
fl6.flowi6_mark = sk->sk_mark;
if (lsa) {
if (addr_len < SIN6_LEN_RFC2133)
return -EINVAL;
if (lsa->l2tp_family && lsa->l2tp_family != AF_INET6)
return -EAFNOSUPPORT;
daddr = &lsa->l2tp_addr;
if (np->sndflow) {
fl6.flowlabel = lsa->l2tp_flowinfo & IPV6_FLOWINFO_MASK;
if (fl6.flowlabel&IPV6_FLOWLABEL_MASK) {
flowlabel = fl6_sock_lookup(sk, fl6.flowlabel);
if (flowlabel == NULL)
return -EINVAL;
daddr = &flowlabel->dst;
}
}
if (sk->sk_state == TCP_ESTABLISHED &&
ipv6_addr_equal(daddr, &np->daddr))
daddr = &np->daddr;
if (addr_len >= sizeof(struct sockaddr_in6) &&
lsa->l2tp_scope_id &&
ipv6_addr_type(daddr) & IPV6_ADDR_LINKLOCAL)
fl6.flowi6_oif = lsa->l2tp_scope_id;
} else {
if (sk->sk_state != TCP_ESTABLISHED)
return -EDESTADDRREQ;
daddr = &np->daddr;
fl6.flowlabel = np->flow_label;
}
if (fl6.flowi6_oif == 0)
fl6.flowi6_oif = sk->sk_bound_dev_if;
if (msg->msg_controllen) {
opt = &opt_space;
memset(opt, 0, sizeof(struct ipv6_txoptions));
opt->tot_len = sizeof(struct ipv6_txoptions);
err = datagram_send_ctl(sock_net(sk), sk, msg, &fl6, opt,
&hlimit, &tclass, &dontfrag);
if (err < 0) {
fl6_sock_release(flowlabel);
return err;
}
if ((fl6.flowlabel & IPV6_FLOWLABEL_MASK) && !flowlabel) {
flowlabel = fl6_sock_lookup(sk, fl6.flowlabel);
if (flowlabel == NULL)
return -EINVAL;
}
if (!(opt->opt_nflen|opt->opt_flen))
opt = NULL;
}
if (opt == NULL)
opt = np->opt;
if (flowlabel)
opt = fl6_merge_options(&opt_space, flowlabel, opt);
opt = ipv6_fixup_options(&opt_space, opt);
fl6.flowi6_proto = sk->sk_protocol;
if (!ipv6_addr_any(daddr))
fl6.daddr = *daddr;
else
fl6.daddr.s6_addr[15] = 0x1;
if (ipv6_addr_any(&fl6.saddr) && !ipv6_addr_any(&np->saddr))
fl6.saddr = np->saddr;
final_p = fl6_update_dst(&fl6, opt, &final);
if (!fl6.flowi6_oif && ipv6_addr_is_multicast(&fl6.daddr))
fl6.flowi6_oif = np->mcast_oif;
else if (!fl6.flowi6_oif)
fl6.flowi6_oif = np->ucast_oif;
security_sk_classify_flow(sk, flowi6_to_flowi(&fl6));
dst = ip6_dst_lookup_flow(sk, &fl6, final_p, true);
if (IS_ERR(dst)) {
err = PTR_ERR(dst);
goto out;
}
if (hlimit < 0) {
if (ipv6_addr_is_multicast(&fl6.daddr))
hlimit = np->mcast_hops;
else
hlimit = np->hop_limit;
if (hlimit < 0)
hlimit = ip6_dst_hoplimit(dst);
}
if (tclass < 0)
tclass = np->tclass;
if (dontfrag < 0)
dontfrag = np->dontfrag;
if (msg->msg_flags & MSG_CONFIRM)
goto do_confirm;
back_from_confirm:
lock_sock(sk);
err = ip6_append_data(sk, ip_generic_getfrag, msg->msg_iov,
ulen, transhdrlen, hlimit, tclass, opt,
&fl6, (struct rt6_info *)dst,
msg->msg_flags, dontfrag);
if (err)
ip6_flush_pending_frames(sk);
else if (!(msg->msg_flags & MSG_MORE))
err = l2tp_ip6_push_pending_frames(sk);
release_sock(sk);
done:
dst_release(dst);
out:
fl6_sock_release(flowlabel);
return err < 0 ? err : len;
do_confirm:
dst_confirm(dst);
if (!(msg->msg_flags & MSG_PROBE) || len)
goto back_from_confirm;
err = 0;
goto done;
}
static int l2tp_ip6_recvmsg(struct kiocb *iocb, struct sock *sk,
struct msghdr *msg, size_t len, int noblock,
int flags, int *addr_len)
{
struct inet_sock *inet = inet_sk(sk);
struct sockaddr_l2tpip6 *lsa = (struct sockaddr_l2tpip6 *)msg->msg_name;
size_t copied = 0;
int err = -EOPNOTSUPP;
struct sk_buff *skb;
if (flags & MSG_OOB)
goto out;
if (addr_len)
*addr_len = sizeof(*lsa);
if (flags & MSG_ERRQUEUE)
return ipv6_recv_error(sk, msg, len);
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
if (lsa) {
lsa->l2tp_family = AF_INET6;
lsa->l2tp_unused = 0;
lsa->l2tp_addr = ipv6_hdr(skb)->saddr;
lsa->l2tp_flowinfo = 0;
lsa->l2tp_scope_id = 0;
if (ipv6_addr_type(&lsa->l2tp_addr) & IPV6_ADDR_LINKLOCAL)
lsa->l2tp_scope_id = IP6CB(skb)->iif;
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
static int __init l2tp_ip6_init(void)
{
int err;
pr_info("L2TP IP encapsulation support for IPv6 (L2TPv3)\n");
err = proto_register(&l2tp_ip6_prot, 1);
if (err != 0)
goto out;
err = inet6_add_protocol(&l2tp_ip6_protocol, IPPROTO_L2TP);
if (err)
goto out1;
inet6_register_protosw(&l2tp_ip6_protosw);
return 0;
out1:
proto_unregister(&l2tp_ip6_prot);
out:
return err;
}
static void __exit l2tp_ip6_exit(void)
{
inet6_unregister_protosw(&l2tp_ip6_protosw);
inet6_del_protocol(&l2tp_ip6_protocol, IPPROTO_L2TP);
proto_unregister(&l2tp_ip6_prot);
}
