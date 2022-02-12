void inet_sock_destruct(struct sock *sk)
{
struct inet_sock *inet = inet_sk(sk);
__skb_queue_purge(&sk->sk_receive_queue);
__skb_queue_purge(&sk->sk_error_queue);
sk_mem_reclaim(sk);
if (sk->sk_type == SOCK_STREAM && sk->sk_state != TCP_CLOSE) {
pr_err("Attempt to release TCP socket in state %d %p\n",
sk->sk_state, sk);
return;
}
if (!sock_flag(sk, SOCK_DEAD)) {
pr_err("Attempt to release alive inet socket %p\n", sk);
return;
}
WARN_ON(atomic_read(&sk->sk_rmem_alloc));
WARN_ON(atomic_read(&sk->sk_wmem_alloc));
WARN_ON(sk->sk_wmem_queued);
WARN_ON(sk->sk_forward_alloc);
kfree(rcu_dereference_protected(inet->inet_opt, 1));
dst_release(rcu_dereference_check(sk->sk_dst_cache, 1));
dst_release(sk->sk_rx_dst);
sk_refcnt_debug_dec(sk);
}
static int inet_autobind(struct sock *sk)
{
struct inet_sock *inet;
lock_sock(sk);
inet = inet_sk(sk);
if (!inet->inet_num) {
if (sk->sk_prot->get_port(sk, 0)) {
release_sock(sk);
return -EAGAIN;
}
inet->inet_sport = htons(inet->inet_num);
}
release_sock(sk);
return 0;
}
int inet_listen(struct socket *sock, int backlog)
{
struct sock *sk = sock->sk;
unsigned char old_state;
int err;
lock_sock(sk);
err = -EINVAL;
if (sock->state != SS_UNCONNECTED || sock->type != SOCK_STREAM)
goto out;
old_state = sk->sk_state;
if (!((1 << old_state) & (TCPF_CLOSE | TCPF_LISTEN)))
goto out;
if (old_state != TCP_LISTEN) {
if ((sysctl_tcp_fastopen & TFO_SERVER_ENABLE) != 0 &&
!inet_csk(sk)->icsk_accept_queue.fastopenq.max_qlen) {
if ((sysctl_tcp_fastopen & TFO_SERVER_WO_SOCKOPT1) != 0)
fastopen_queue_tune(sk, backlog);
else if ((sysctl_tcp_fastopen &
TFO_SERVER_WO_SOCKOPT2) != 0)
fastopen_queue_tune(sk,
((uint)sysctl_tcp_fastopen) >> 16);
tcp_fastopen_init_key_once(true);
}
err = inet_csk_listen_start(sk, backlog);
if (err)
goto out;
}
sk->sk_max_ack_backlog = backlog;
err = 0;
out:
release_sock(sk);
return err;
}
static int inet_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
struct inet_protosw *answer;
struct inet_sock *inet;
struct proto *answer_prot;
unsigned char answer_flags;
int try_loading_module = 0;
int err;
if (protocol < 0 || protocol >= IPPROTO_MAX)
return -EINVAL;
sock->state = SS_UNCONNECTED;
lookup_protocol:
err = -ESOCKTNOSUPPORT;
rcu_read_lock();
list_for_each_entry_rcu(answer, &inetsw[sock->type], list) {
err = 0;
if (protocol == answer->protocol) {
if (protocol != IPPROTO_IP)
break;
} else {
if (IPPROTO_IP == protocol) {
protocol = answer->protocol;
break;
}
if (IPPROTO_IP == answer->protocol)
break;
}
err = -EPROTONOSUPPORT;
}
if (unlikely(err)) {
if (try_loading_module < 2) {
rcu_read_unlock();
if (++try_loading_module == 1)
request_module("net-pf-%d-proto-%d-type-%d",
PF_INET, protocol, sock->type);
else
request_module("net-pf-%d-proto-%d",
PF_INET, protocol);
goto lookup_protocol;
} else
goto out_rcu_unlock;
}
err = -EPERM;
if (sock->type == SOCK_RAW && !kern &&
!ns_capable(net->user_ns, CAP_NET_RAW))
goto out_rcu_unlock;
sock->ops = answer->ops;
answer_prot = answer->prot;
answer_flags = answer->flags;
rcu_read_unlock();
WARN_ON(!answer_prot->slab);
err = -ENOBUFS;
sk = sk_alloc(net, PF_INET, GFP_KERNEL, answer_prot, kern);
if (!sk)
goto out;
err = 0;
if (INET_PROTOSW_REUSE & answer_flags)
sk->sk_reuse = SK_CAN_REUSE;
inet = inet_sk(sk);
inet->is_icsk = (INET_PROTOSW_ICSK & answer_flags) != 0;
inet->nodefrag = 0;
if (SOCK_RAW == sock->type) {
inet->inet_num = protocol;
if (IPPROTO_RAW == protocol)
inet->hdrincl = 1;
}
if (net->ipv4.sysctl_ip_no_pmtu_disc)
inet->pmtudisc = IP_PMTUDISC_DONT;
else
inet->pmtudisc = IP_PMTUDISC_WANT;
inet->inet_id = 0;
sock_init_data(sock, sk);
sk->sk_destruct = inet_sock_destruct;
sk->sk_protocol = protocol;
sk->sk_backlog_rcv = sk->sk_prot->backlog_rcv;
inet->uc_ttl = -1;
inet->mc_loop = 1;
inet->mc_ttl = 1;
inet->mc_all = 1;
inet->mc_index = 0;
inet->mc_list = NULL;
inet->rcv_tos = 0;
sk_refcnt_debug_inc(sk);
if (inet->inet_num) {
inet->inet_sport = htons(inet->inet_num);
sk->sk_prot->hash(sk);
}
if (sk->sk_prot->init) {
err = sk->sk_prot->init(sk);
if (err)
sk_common_release(sk);
}
out:
return err;
out_rcu_unlock:
rcu_read_unlock();
goto out;
}
int inet_release(struct socket *sock)
{
struct sock *sk = sock->sk;
if (sk) {
long timeout;
ip_mc_drop_socket(sk);
timeout = 0;
if (sock_flag(sk, SOCK_LINGER) &&
!(current->flags & PF_EXITING))
timeout = sk->sk_lingertime;
sock->sk = NULL;
sk->sk_prot->close(sk, timeout);
}
return 0;
}
int inet_bind(struct socket *sock, struct sockaddr *uaddr, int addr_len)
{
struct sockaddr_in *addr = (struct sockaddr_in *)uaddr;
struct sock *sk = sock->sk;
struct inet_sock *inet = inet_sk(sk);
struct net *net = sock_net(sk);
unsigned short snum;
int chk_addr_ret;
u32 tb_id = RT_TABLE_LOCAL;
int err;
if (sk->sk_prot->bind) {
err = sk->sk_prot->bind(sk, uaddr, addr_len);
goto out;
}
err = -EINVAL;
if (addr_len < sizeof(struct sockaddr_in))
goto out;
if (addr->sin_family != AF_INET) {
err = -EAFNOSUPPORT;
if (addr->sin_family != AF_UNSPEC ||
addr->sin_addr.s_addr != htonl(INADDR_ANY))
goto out;
}
tb_id = l3mdev_fib_table_by_index(net, sk->sk_bound_dev_if) ? : tb_id;
chk_addr_ret = inet_addr_type_table(net, addr->sin_addr.s_addr, tb_id);
err = -EADDRNOTAVAIL;
if (!net->ipv4.sysctl_ip_nonlocal_bind &&
!(inet->freebind || inet->transparent) &&
addr->sin_addr.s_addr != htonl(INADDR_ANY) &&
chk_addr_ret != RTN_LOCAL &&
chk_addr_ret != RTN_MULTICAST &&
chk_addr_ret != RTN_BROADCAST)
goto out;
snum = ntohs(addr->sin_port);
err = -EACCES;
if (snum && snum < PROT_SOCK &&
!ns_capable(net->user_ns, CAP_NET_BIND_SERVICE))
goto out;
lock_sock(sk);
err = -EINVAL;
if (sk->sk_state != TCP_CLOSE || inet->inet_num)
goto out_release_sock;
inet->inet_rcv_saddr = inet->inet_saddr = addr->sin_addr.s_addr;
if (chk_addr_ret == RTN_MULTICAST || chk_addr_ret == RTN_BROADCAST)
inet->inet_saddr = 0;
if ((snum || !inet->bind_address_no_port) &&
sk->sk_prot->get_port(sk, snum)) {
inet->inet_saddr = inet->inet_rcv_saddr = 0;
err = -EADDRINUSE;
goto out_release_sock;
}
if (inet->inet_rcv_saddr)
sk->sk_userlocks |= SOCK_BINDADDR_LOCK;
if (snum)
sk->sk_userlocks |= SOCK_BINDPORT_LOCK;
inet->inet_sport = htons(inet->inet_num);
inet->inet_daddr = 0;
inet->inet_dport = 0;
sk_dst_reset(sk);
err = 0;
out_release_sock:
release_sock(sk);
out:
return err;
}
int inet_dgram_connect(struct socket *sock, struct sockaddr *uaddr,
int addr_len, int flags)
{
struct sock *sk = sock->sk;
if (addr_len < sizeof(uaddr->sa_family))
return -EINVAL;
if (uaddr->sa_family == AF_UNSPEC)
return sk->sk_prot->disconnect(sk, flags);
if (!inet_sk(sk)->inet_num && inet_autobind(sk))
return -EAGAIN;
return sk->sk_prot->connect(sk, uaddr, addr_len);
}
static long inet_wait_for_connect(struct sock *sk, long timeo, int writebias)
{
DEFINE_WAIT(wait);
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
sk->sk_write_pending += writebias;
while ((1 << sk->sk_state) & (TCPF_SYN_SENT | TCPF_SYN_RECV)) {
release_sock(sk);
timeo = schedule_timeout(timeo);
lock_sock(sk);
if (signal_pending(current) || !timeo)
break;
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
}
finish_wait(sk_sleep(sk), &wait);
sk->sk_write_pending -= writebias;
return timeo;
}
int __inet_stream_connect(struct socket *sock, struct sockaddr *uaddr,
int addr_len, int flags)
{
struct sock *sk = sock->sk;
int err;
long timeo;
if (addr_len < sizeof(uaddr->sa_family))
return -EINVAL;
if (uaddr->sa_family == AF_UNSPEC) {
err = sk->sk_prot->disconnect(sk, flags);
sock->state = err ? SS_DISCONNECTING : SS_UNCONNECTED;
goto out;
}
switch (sock->state) {
default:
err = -EINVAL;
goto out;
case SS_CONNECTED:
err = -EISCONN;
goto out;
case SS_CONNECTING:
err = -EALREADY;
break;
case SS_UNCONNECTED:
err = -EISCONN;
if (sk->sk_state != TCP_CLOSE)
goto out;
err = sk->sk_prot->connect(sk, uaddr, addr_len);
if (err < 0)
goto out;
sock->state = SS_CONNECTING;
err = -EINPROGRESS;
break;
}
timeo = sock_sndtimeo(sk, flags & O_NONBLOCK);
if ((1 << sk->sk_state) & (TCPF_SYN_SENT | TCPF_SYN_RECV)) {
int writebias = (sk->sk_protocol == IPPROTO_TCP) &&
tcp_sk(sk)->fastopen_req &&
tcp_sk(sk)->fastopen_req->data ? 1 : 0;
if (!timeo || !inet_wait_for_connect(sk, timeo, writebias))
goto out;
err = sock_intr_errno(timeo);
if (signal_pending(current))
goto out;
}
if (sk->sk_state == TCP_CLOSE)
goto sock_error;
sock->state = SS_CONNECTED;
err = 0;
out:
return err;
sock_error:
err = sock_error(sk) ? : -ECONNABORTED;
sock->state = SS_UNCONNECTED;
if (sk->sk_prot->disconnect(sk, flags))
sock->state = SS_DISCONNECTING;
goto out;
}
int inet_stream_connect(struct socket *sock, struct sockaddr *uaddr,
int addr_len, int flags)
{
int err;
lock_sock(sock->sk);
err = __inet_stream_connect(sock, uaddr, addr_len, flags);
release_sock(sock->sk);
return err;
}
int inet_accept(struct socket *sock, struct socket *newsock, int flags)
{
struct sock *sk1 = sock->sk;
int err = -EINVAL;
struct sock *sk2 = sk1->sk_prot->accept(sk1, flags, &err);
if (!sk2)
goto do_err;
lock_sock(sk2);
sock_rps_record_flow(sk2);
WARN_ON(!((1 << sk2->sk_state) &
(TCPF_ESTABLISHED | TCPF_SYN_RECV |
TCPF_CLOSE_WAIT | TCPF_CLOSE)));
sock_graft(sk2, newsock);
newsock->state = SS_CONNECTED;
err = 0;
release_sock(sk2);
do_err:
return err;
}
int inet_getname(struct socket *sock, struct sockaddr *uaddr,
int *uaddr_len, int peer)
{
struct sock *sk = sock->sk;
struct inet_sock *inet = inet_sk(sk);
DECLARE_SOCKADDR(struct sockaddr_in *, sin, uaddr);
sin->sin_family = AF_INET;
if (peer) {
if (!inet->inet_dport ||
(((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_SYN_SENT)) &&
peer == 1))
return -ENOTCONN;
sin->sin_port = inet->inet_dport;
sin->sin_addr.s_addr = inet->inet_daddr;
} else {
__be32 addr = inet->inet_rcv_saddr;
if (!addr)
addr = inet->inet_saddr;
sin->sin_port = inet->inet_sport;
sin->sin_addr.s_addr = addr;
}
memset(sin->sin_zero, 0, sizeof(sin->sin_zero));
*uaddr_len = sizeof(*sin);
return 0;
}
int inet_sendmsg(struct socket *sock, struct msghdr *msg, size_t size)
{
struct sock *sk = sock->sk;
sock_rps_record_flow(sk);
if (!inet_sk(sk)->inet_num && !sk->sk_prot->no_autobind &&
inet_autobind(sk))
return -EAGAIN;
return sk->sk_prot->sendmsg(sk, msg, size);
}
ssize_t inet_sendpage(struct socket *sock, struct page *page, int offset,
size_t size, int flags)
{
struct sock *sk = sock->sk;
sock_rps_record_flow(sk);
if (!inet_sk(sk)->inet_num && !sk->sk_prot->no_autobind &&
inet_autobind(sk))
return -EAGAIN;
if (sk->sk_prot->sendpage)
return sk->sk_prot->sendpage(sk, page, offset, size, flags);
return sock_no_sendpage(sock, page, offset, size, flags);
}
int inet_recvmsg(struct socket *sock, struct msghdr *msg, size_t size,
int flags)
{
struct sock *sk = sock->sk;
int addr_len = 0;
int err;
sock_rps_record_flow(sk);
err = sk->sk_prot->recvmsg(sk, msg, size, flags & MSG_DONTWAIT,
flags & ~MSG_DONTWAIT, &addr_len);
if (err >= 0)
msg->msg_namelen = addr_len;
return err;
}
int inet_shutdown(struct socket *sock, int how)
{
struct sock *sk = sock->sk;
int err = 0;
how++;
if ((how & ~SHUTDOWN_MASK) || !how)
return -EINVAL;
lock_sock(sk);
if (sock->state == SS_CONNECTING) {
if ((1 << sk->sk_state) &
(TCPF_SYN_SENT | TCPF_SYN_RECV | TCPF_CLOSE))
sock->state = SS_DISCONNECTING;
else
sock->state = SS_CONNECTED;
}
switch (sk->sk_state) {
case TCP_CLOSE:
err = -ENOTCONN;
default:
sk->sk_shutdown |= how;
if (sk->sk_prot->shutdown)
sk->sk_prot->shutdown(sk, how);
break;
case TCP_LISTEN:
if (!(how & RCV_SHUTDOWN))
break;
case TCP_SYN_SENT:
err = sk->sk_prot->disconnect(sk, O_NONBLOCK);
sock->state = err ? SS_DISCONNECTING : SS_UNCONNECTED;
break;
}
sk->sk_state_change(sk);
release_sock(sk);
return err;
}
int inet_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
struct sock *sk = sock->sk;
int err = 0;
struct net *net = sock_net(sk);
switch (cmd) {
case SIOCGSTAMP:
err = sock_get_timestamp(sk, (struct timeval __user *)arg);
break;
case SIOCGSTAMPNS:
err = sock_get_timestampns(sk, (struct timespec __user *)arg);
break;
case SIOCADDRT:
case SIOCDELRT:
case SIOCRTMSG:
err = ip_rt_ioctl(net, cmd, (void __user *)arg);
break;
case SIOCDARP:
case SIOCGARP:
case SIOCSARP:
err = arp_ioctl(net, cmd, (void __user *)arg);
break;
case SIOCGIFADDR:
case SIOCSIFADDR:
case SIOCGIFBRDADDR:
case SIOCSIFBRDADDR:
case SIOCGIFNETMASK:
case SIOCSIFNETMASK:
case SIOCGIFDSTADDR:
case SIOCSIFDSTADDR:
case SIOCSIFPFLAGS:
case SIOCGIFPFLAGS:
case SIOCSIFFLAGS:
err = devinet_ioctl(net, cmd, (void __user *)arg);
break;
default:
if (sk->sk_prot->ioctl)
err = sk->sk_prot->ioctl(sk, cmd, arg);
else
err = -ENOIOCTLCMD;
break;
}
return err;
}
static int inet_compat_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
struct sock *sk = sock->sk;
int err = -ENOIOCTLCMD;
if (sk->sk_prot->compat_ioctl)
err = sk->sk_prot->compat_ioctl(sk, cmd, arg);
return err;
}
void inet_register_protosw(struct inet_protosw *p)
{
struct list_head *lh;
struct inet_protosw *answer;
int protocol = p->protocol;
struct list_head *last_perm;
spin_lock_bh(&inetsw_lock);
if (p->type >= SOCK_MAX)
goto out_illegal;
last_perm = &inetsw[p->type];
list_for_each(lh, &inetsw[p->type]) {
answer = list_entry(lh, struct inet_protosw, list);
if ((INET_PROTOSW_PERMANENT & answer->flags) == 0)
break;
if (protocol == answer->protocol)
goto out_permanent;
last_perm = lh;
}
list_add_rcu(&p->list, last_perm);
out:
spin_unlock_bh(&inetsw_lock);
return;
out_permanent:
pr_err("Attempt to override permanent protocol %d\n", protocol);
goto out;
out_illegal:
pr_err("Ignoring attempt to register invalid socket type %d\n",
p->type);
goto out;
}
void inet_unregister_protosw(struct inet_protosw *p)
{
if (INET_PROTOSW_PERMANENT & p->flags) {
pr_err("Attempt to unregister permanent protocol %d\n",
p->protocol);
} else {
spin_lock_bh(&inetsw_lock);
list_del_rcu(&p->list);
spin_unlock_bh(&inetsw_lock);
synchronize_net();
}
}
static int inet_sk_reselect_saddr(struct sock *sk)
{
struct inet_sock *inet = inet_sk(sk);
__be32 old_saddr = inet->inet_saddr;
__be32 daddr = inet->inet_daddr;
struct flowi4 *fl4;
struct rtable *rt;
__be32 new_saddr;
struct ip_options_rcu *inet_opt;
inet_opt = rcu_dereference_protected(inet->inet_opt,
sock_owned_by_user(sk));
if (inet_opt && inet_opt->opt.srr)
daddr = inet_opt->opt.faddr;
fl4 = &inet->cork.fl.u.ip4;
rt = ip_route_connect(fl4, daddr, 0, RT_CONN_FLAGS(sk),
sk->sk_bound_dev_if, sk->sk_protocol,
inet->inet_sport, inet->inet_dport, sk);
if (IS_ERR(rt))
return PTR_ERR(rt);
sk_setup_caps(sk, &rt->dst);
new_saddr = fl4->saddr;
if (new_saddr == old_saddr)
return 0;
if (sysctl_ip_dynaddr > 1) {
pr_info("%s(): shifting inet->saddr from %pI4 to %pI4\n",
__func__, &old_saddr, &new_saddr);
}
inet->inet_saddr = inet->inet_rcv_saddr = new_saddr;
__sk_prot_rehash(sk);
return 0;
}
int inet_sk_rebuild_header(struct sock *sk)
{
struct inet_sock *inet = inet_sk(sk);
struct rtable *rt = (struct rtable *)__sk_dst_check(sk, 0);
__be32 daddr;
struct ip_options_rcu *inet_opt;
struct flowi4 *fl4;
int err;
if (rt)
return 0;
rcu_read_lock();
inet_opt = rcu_dereference(inet->inet_opt);
daddr = inet->inet_daddr;
if (inet_opt && inet_opt->opt.srr)
daddr = inet_opt->opt.faddr;
rcu_read_unlock();
fl4 = &inet->cork.fl.u.ip4;
rt = ip_route_output_ports(sock_net(sk), fl4, sk, daddr, inet->inet_saddr,
inet->inet_dport, inet->inet_sport,
sk->sk_protocol, RT_CONN_FLAGS(sk),
sk->sk_bound_dev_if);
if (!IS_ERR(rt)) {
err = 0;
sk_setup_caps(sk, &rt->dst);
} else {
err = PTR_ERR(rt);
sk->sk_route_caps = 0;
if (!sysctl_ip_dynaddr ||
sk->sk_state != TCP_SYN_SENT ||
(sk->sk_userlocks & SOCK_BINDADDR_LOCK) ||
(err = inet_sk_reselect_saddr(sk)) != 0)
sk->sk_err_soft = -err;
}
return err;
}
static struct sk_buff *inet_gso_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
const struct net_offload *ops;
unsigned int offset = 0;
bool udpfrag, encap;
struct iphdr *iph;
int proto;
int nhoff;
int ihl;
int id;
if (unlikely(skb_shinfo(skb)->gso_type &
~(SKB_GSO_TCPV4 |
SKB_GSO_UDP |
SKB_GSO_DODGY |
SKB_GSO_TCP_ECN |
SKB_GSO_GRE |
SKB_GSO_GRE_CSUM |
SKB_GSO_IPIP |
SKB_GSO_SIT |
SKB_GSO_TCPV6 |
SKB_GSO_UDP_TUNNEL |
SKB_GSO_UDP_TUNNEL_CSUM |
SKB_GSO_TUNNEL_REMCSUM |
0)))
goto out;
skb_reset_network_header(skb);
nhoff = skb_network_header(skb) - skb_mac_header(skb);
if (unlikely(!pskb_may_pull(skb, sizeof(*iph))))
goto out;
iph = ip_hdr(skb);
ihl = iph->ihl * 4;
if (ihl < sizeof(*iph))
goto out;
id = ntohs(iph->id);
proto = iph->protocol;
if (unlikely(!pskb_may_pull(skb, ihl)))
goto out;
__skb_pull(skb, ihl);
encap = SKB_GSO_CB(skb)->encap_level > 0;
if (encap)
features &= skb->dev->hw_enc_features;
SKB_GSO_CB(skb)->encap_level += ihl;
skb_reset_transport_header(skb);
segs = ERR_PTR(-EPROTONOSUPPORT);
if (skb->encapsulation &&
skb_shinfo(skb)->gso_type & (SKB_GSO_SIT|SKB_GSO_IPIP))
udpfrag = proto == IPPROTO_UDP && encap;
else
udpfrag = proto == IPPROTO_UDP && !skb->encapsulation;
ops = rcu_dereference(inet_offloads[proto]);
if (likely(ops && ops->callbacks.gso_segment))
segs = ops->callbacks.gso_segment(skb, features);
if (IS_ERR_OR_NULL(segs))
goto out;
skb = segs;
do {
iph = (struct iphdr *)(skb_mac_header(skb) + nhoff);
if (udpfrag) {
iph->id = htons(id);
iph->frag_off = htons(offset >> 3);
if (skb->next)
iph->frag_off |= htons(IP_MF);
offset += skb->len - nhoff - ihl;
} else {
iph->id = htons(id++);
}
iph->tot_len = htons(skb->len - nhoff);
ip_send_check(iph);
if (encap)
skb_reset_inner_headers(skb);
skb->network_header = (u8 *)iph - skb->head;
} while ((skb = skb->next));
out:
return segs;
}
static struct sk_buff **inet_gro_receive(struct sk_buff **head,
struct sk_buff *skb)
{
const struct net_offload *ops;
struct sk_buff **pp = NULL;
struct sk_buff *p;
const struct iphdr *iph;
unsigned int hlen;
unsigned int off;
unsigned int id;
int flush = 1;
int proto;
off = skb_gro_offset(skb);
hlen = off + sizeof(*iph);
iph = skb_gro_header_fast(skb, off);
if (skb_gro_header_hard(skb, hlen)) {
iph = skb_gro_header_slow(skb, hlen, off);
if (unlikely(!iph))
goto out;
}
proto = iph->protocol;
rcu_read_lock();
ops = rcu_dereference(inet_offloads[proto]);
if (!ops || !ops->callbacks.gro_receive)
goto out_unlock;
if (*(u8 *)iph != 0x45)
goto out_unlock;
if (unlikely(ip_fast_csum((u8 *)iph, 5)))
goto out_unlock;
id = ntohl(*(__be32 *)&iph->id);
flush = (u16)((ntohl(*(__be32 *)iph) ^ skb_gro_len(skb)) | (id & ~IP_DF));
id >>= 16;
for (p = *head; p; p = p->next) {
struct iphdr *iph2;
if (!NAPI_GRO_CB(p)->same_flow)
continue;
iph2 = (struct iphdr *)(p->data + off);
if ((iph->protocol ^ iph2->protocol) |
((__force u32)iph->saddr ^ (__force u32)iph2->saddr) |
((__force u32)iph->daddr ^ (__force u32)iph2->daddr)) {
NAPI_GRO_CB(p)->same_flow = 0;
continue;
}
NAPI_GRO_CB(p)->flush |=
(iph->ttl ^ iph2->ttl) |
(iph->tos ^ iph2->tos) |
((iph->frag_off ^ iph2->frag_off) & htons(IP_DF));
NAPI_GRO_CB(p)->flush_id =
((u16)(ntohs(iph2->id) + NAPI_GRO_CB(p)->count) ^ id);
NAPI_GRO_CB(p)->flush |= flush;
}
NAPI_GRO_CB(skb)->flush |= flush;
skb_set_network_header(skb, off);
skb_gro_pull(skb, sizeof(*iph));
skb_set_transport_header(skb, skb_gro_offset(skb));
pp = ops->callbacks.gro_receive(head, skb);
out_unlock:
rcu_read_unlock();
out:
NAPI_GRO_CB(skb)->flush |= flush;
return pp;
}
int inet_recv_error(struct sock *sk, struct msghdr *msg, int len, int *addr_len)
{
if (sk->sk_family == AF_INET)
return ip_recv_error(sk, msg, len, addr_len);
#if IS_ENABLED(CONFIG_IPV6)
if (sk->sk_family == AF_INET6)
return pingv6_ops.ipv6_recv_error(sk, msg, len, addr_len);
#endif
return -EINVAL;
}
static int inet_gro_complete(struct sk_buff *skb, int nhoff)
{
__be16 newlen = htons(skb->len - nhoff);
struct iphdr *iph = (struct iphdr *)(skb->data + nhoff);
const struct net_offload *ops;
int proto = iph->protocol;
int err = -ENOSYS;
if (skb->encapsulation)
skb_set_inner_network_header(skb, nhoff);
csum_replace2(&iph->check, iph->tot_len, newlen);
iph->tot_len = newlen;
rcu_read_lock();
ops = rcu_dereference(inet_offloads[proto]);
if (WARN_ON(!ops || !ops->callbacks.gro_complete))
goto out_unlock;
err = ops->callbacks.gro_complete(skb, nhoff + sizeof(*iph));
out_unlock:
rcu_read_unlock();
return err;
}
int inet_ctl_sock_create(struct sock **sk, unsigned short family,
unsigned short type, unsigned char protocol,
struct net *net)
{
struct socket *sock;
int rc = sock_create_kern(net, family, type, protocol, &sock);
if (rc == 0) {
*sk = sock->sk;
(*sk)->sk_allocation = GFP_ATOMIC;
(*sk)->sk_prot->unhash(*sk);
}
return rc;
}
u64 snmp_get_cpu_field(void __percpu *mib, int cpu, int offt)
{
return *(((unsigned long *)per_cpu_ptr(mib, cpu)) + offt);
}
unsigned long snmp_fold_field(void __percpu *mib, int offt)
{
unsigned long res = 0;
int i;
for_each_possible_cpu(i)
res += snmp_get_cpu_field(mib, i, offt);
return res;
}
u64 snmp_get_cpu_field64(void __percpu *mib, int cpu, int offt,
size_t syncp_offset)
{
void *bhptr;
struct u64_stats_sync *syncp;
u64 v;
unsigned int start;
bhptr = per_cpu_ptr(mib, cpu);
syncp = (struct u64_stats_sync *)(bhptr + syncp_offset);
do {
start = u64_stats_fetch_begin_irq(syncp);
v = *(((u64 *)bhptr) + offt);
} while (u64_stats_fetch_retry_irq(syncp, start));
return v;
}
u64 snmp_fold_field64(void __percpu *mib, int offt, size_t syncp_offset)
{
u64 res = 0;
int cpu;
for_each_possible_cpu(cpu) {
res += snmp_get_cpu_field64(mib, cpu, offt, syncp_offset);
}
return res;
}
static __net_init int ipv4_mib_init_net(struct net *net)
{
int i;
net->mib.tcp_statistics = alloc_percpu(struct tcp_mib);
if (!net->mib.tcp_statistics)
goto err_tcp_mib;
net->mib.ip_statistics = alloc_percpu(struct ipstats_mib);
if (!net->mib.ip_statistics)
goto err_ip_mib;
for_each_possible_cpu(i) {
struct ipstats_mib *af_inet_stats;
af_inet_stats = per_cpu_ptr(net->mib.ip_statistics, i);
u64_stats_init(&af_inet_stats->syncp);
}
net->mib.net_statistics = alloc_percpu(struct linux_mib);
if (!net->mib.net_statistics)
goto err_net_mib;
net->mib.udp_statistics = alloc_percpu(struct udp_mib);
if (!net->mib.udp_statistics)
goto err_udp_mib;
net->mib.udplite_statistics = alloc_percpu(struct udp_mib);
if (!net->mib.udplite_statistics)
goto err_udplite_mib;
net->mib.icmp_statistics = alloc_percpu(struct icmp_mib);
if (!net->mib.icmp_statistics)
goto err_icmp_mib;
net->mib.icmpmsg_statistics = kzalloc(sizeof(struct icmpmsg_mib),
GFP_KERNEL);
if (!net->mib.icmpmsg_statistics)
goto err_icmpmsg_mib;
tcp_mib_init(net);
return 0;
err_icmpmsg_mib:
free_percpu(net->mib.icmp_statistics);
err_icmp_mib:
free_percpu(net->mib.udplite_statistics);
err_udplite_mib:
free_percpu(net->mib.udp_statistics);
err_udp_mib:
free_percpu(net->mib.net_statistics);
err_net_mib:
free_percpu(net->mib.ip_statistics);
err_ip_mib:
free_percpu(net->mib.tcp_statistics);
err_tcp_mib:
return -ENOMEM;
}
static __net_exit void ipv4_mib_exit_net(struct net *net)
{
kfree(net->mib.icmpmsg_statistics);
free_percpu(net->mib.icmp_statistics);
free_percpu(net->mib.udplite_statistics);
free_percpu(net->mib.udp_statistics);
free_percpu(net->mib.net_statistics);
free_percpu(net->mib.ip_statistics);
free_percpu(net->mib.tcp_statistics);
}
static int __init init_ipv4_mibs(void)
{
return register_pernet_subsys(&ipv4_mib_ops);
}
static __net_init int inet_init_net(struct net *net)
{
seqlock_init(&net->ipv4.ip_local_ports.lock);
net->ipv4.ip_local_ports.range[0] = 32768;
net->ipv4.ip_local_ports.range[1] = 60999;
seqlock_init(&net->ipv4.ping_group_range.lock);
net->ipv4.ping_group_range.range[0] = make_kgid(&init_user_ns, 1);
net->ipv4.ping_group_range.range[1] = make_kgid(&init_user_ns, 0);
return 0;
}
static __net_exit void inet_exit_net(struct net *net)
{
}
static int __init init_inet_pernet_ops(void)
{
return register_pernet_subsys(&af_inet_ops);
}
static int __init ipv4_offload_init(void)
{
if (udpv4_offload_init() < 0)
pr_crit("%s: Cannot add UDP protocol offload\n", __func__);
if (tcpv4_offload_init() < 0)
pr_crit("%s: Cannot add TCP protocol offload\n", __func__);
dev_add_offload(&ip_packet_offload);
inet_add_offload(&ipip_offload, IPPROTO_IPIP);
return 0;
}
static int __init inet_init(void)
{
struct inet_protosw *q;
struct list_head *r;
int rc = -EINVAL;
sock_skb_cb_check_size(sizeof(struct inet_skb_parm));
rc = proto_register(&tcp_prot, 1);
if (rc)
goto out;
rc = proto_register(&udp_prot, 1);
if (rc)
goto out_unregister_tcp_proto;
rc = proto_register(&raw_prot, 1);
if (rc)
goto out_unregister_udp_proto;
rc = proto_register(&ping_prot, 1);
if (rc)
goto out_unregister_raw_proto;
(void)sock_register(&inet_family_ops);
#ifdef CONFIG_SYSCTL
ip_static_sysctl_init();
#endif
if (inet_add_protocol(&icmp_protocol, IPPROTO_ICMP) < 0)
pr_crit("%s: Cannot add ICMP protocol\n", __func__);
if (inet_add_protocol(&udp_protocol, IPPROTO_UDP) < 0)
pr_crit("%s: Cannot add UDP protocol\n", __func__);
if (inet_add_protocol(&tcp_protocol, IPPROTO_TCP) < 0)
pr_crit("%s: Cannot add TCP protocol\n", __func__);
#ifdef CONFIG_IP_MULTICAST
if (inet_add_protocol(&igmp_protocol, IPPROTO_IGMP) < 0)
pr_crit("%s: Cannot add IGMP protocol\n", __func__);
#endif
for (r = &inetsw[0]; r < &inetsw[SOCK_MAX]; ++r)
INIT_LIST_HEAD(r);
for (q = inetsw_array; q < &inetsw_array[INETSW_ARRAY_LEN]; ++q)
inet_register_protosw(q);
arp_init();
ip_init();
tcp_v4_init();
tcp_init();
udp_init();
udplite4_register();
ping_init();
if (icmp_init() < 0)
panic("Failed to create the ICMP control socket.\n");
#if defined(CONFIG_IP_MROUTE)
if (ip_mr_init())
pr_crit("%s: Cannot init ipv4 mroute\n", __func__);
#endif
if (init_inet_pernet_ops())
pr_crit("%s: Cannot init ipv4 inet pernet ops\n", __func__);
if (init_ipv4_mibs())
pr_crit("%s: Cannot init ipv4 mibs\n", __func__);
ipv4_proc_init();
ipfrag_init();
dev_add_pack(&ip_packet_type);
ip_tunnel_core_init();
rc = 0;
out:
return rc;
out_unregister_raw_proto:
proto_unregister(&raw_prot);
out_unregister_udp_proto:
proto_unregister(&udp_prot);
out_unregister_tcp_proto:
proto_unregister(&tcp_prot);
goto out;
}
static int __init ipv4_proc_init(void)
{
int rc = 0;
if (raw_proc_init())
goto out_raw;
if (tcp4_proc_init())
goto out_tcp;
if (udp4_proc_init())
goto out_udp;
if (ping_proc_init())
goto out_ping;
if (ip_misc_proc_init())
goto out_misc;
out:
return rc;
out_misc:
ping_proc_exit();
out_ping:
udp4_proc_exit();
out_udp:
tcp4_proc_exit();
out_tcp:
raw_proc_exit();
out_raw:
rc = -ENOMEM;
goto out;
}
static int __init ipv4_proc_init(void)
{
return 0;
}
