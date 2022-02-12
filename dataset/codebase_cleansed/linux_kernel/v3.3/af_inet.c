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
void build_ehash_secret(void)
{
u32 rnd;
do {
get_random_bytes(&rnd, sizeof(rnd));
} while (rnd == 0);
cmpxchg(&inet_ehash_secret, 0, rnd);
}
static inline int inet_netns_ok(struct net *net, int protocol)
{
int hash;
const struct net_protocol *ipprot;
if (net_eq(net, &init_net))
return 1;
hash = protocol & (MAX_INET_PROTOS - 1);
ipprot = rcu_dereference(inet_protos[hash]);
if (ipprot == NULL)
return 1;
return ipprot->netns_ok;
}
static int inet_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
struct inet_protosw *answer;
struct inet_sock *inet;
struct proto *answer_prot;
unsigned char answer_flags;
char answer_no_check;
int try_loading_module = 0;
int err;
if (unlikely(!inet_ehash_secret))
if (sock->type != SOCK_RAW && sock->type != SOCK_DGRAM)
build_ehash_secret();
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
if (sock->type == SOCK_RAW && !kern && !capable(CAP_NET_RAW))
goto out_rcu_unlock;
err = -EAFNOSUPPORT;
if (!inet_netns_ok(net, protocol))
goto out_rcu_unlock;
sock->ops = answer->ops;
answer_prot = answer->prot;
answer_no_check = answer->no_check;
answer_flags = answer->flags;
rcu_read_unlock();
WARN_ON(answer_prot->slab == NULL);
err = -ENOBUFS;
sk = sk_alloc(net, PF_INET, GFP_KERNEL, answer_prot);
if (sk == NULL)
goto out;
err = 0;
sk->sk_no_check = answer_no_check;
if (INET_PROTOSW_REUSE & answer_flags)
sk->sk_reuse = 1;
inet = inet_sk(sk);
inet->is_icsk = (INET_PROTOSW_ICSK & answer_flags) != 0;
inet->nodefrag = 0;
if (SOCK_RAW == sock->type) {
inet->inet_num = protocol;
if (IPPROTO_RAW == protocol)
inet->hdrincl = 1;
}
if (ipv4_config.no_pmtu_disc)
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
sock_rps_reset_flow(sk);
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
unsigned short snum;
int chk_addr_ret;
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
chk_addr_ret = inet_addr_type(sock_net(sk), addr->sin_addr.s_addr);
err = -EADDRNOTAVAIL;
if (!sysctl_ip_nonlocal_bind &&
!(inet->freebind || inet->transparent) &&
addr->sin_addr.s_addr != htonl(INADDR_ANY) &&
chk_addr_ret != RTN_LOCAL &&
chk_addr_ret != RTN_MULTICAST &&
chk_addr_ret != RTN_BROADCAST)
goto out;
snum = ntohs(addr->sin_port);
err = -EACCES;
if (snum && snum < PROT_SOCK && !capable(CAP_NET_BIND_SERVICE))
goto out;
lock_sock(sk);
err = -EINVAL;
if (sk->sk_state != TCP_CLOSE || inet->inet_num)
goto out_release_sock;
inet->inet_rcv_saddr = inet->inet_saddr = addr->sin_addr.s_addr;
if (chk_addr_ret == RTN_MULTICAST || chk_addr_ret == RTN_BROADCAST)
inet->inet_saddr = 0;
if (sk->sk_prot->get_port(sk, snum)) {
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
int inet_dgram_connect(struct socket *sock, struct sockaddr * uaddr,
int addr_len, int flags)
{
struct sock *sk = sock->sk;
if (addr_len < sizeof(uaddr->sa_family))
return -EINVAL;
if (uaddr->sa_family == AF_UNSPEC)
return sk->sk_prot->disconnect(sk, flags);
if (!inet_sk(sk)->inet_num && inet_autobind(sk))
return -EAGAIN;
return sk->sk_prot->connect(sk, (struct sockaddr *)uaddr, addr_len);
}
static long inet_wait_for_connect(struct sock *sk, long timeo)
{
DEFINE_WAIT(wait);
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
while ((1 << sk->sk_state) & (TCPF_SYN_SENT | TCPF_SYN_RECV)) {
release_sock(sk);
timeo = schedule_timeout(timeo);
lock_sock(sk);
if (signal_pending(current) || !timeo)
break;
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
}
finish_wait(sk_sleep(sk), &wait);
return timeo;
}
int inet_stream_connect(struct socket *sock, struct sockaddr *uaddr,
int addr_len, int flags)
{
struct sock *sk = sock->sk;
int err;
long timeo;
if (addr_len < sizeof(uaddr->sa_family))
return -EINVAL;
lock_sock(sk);
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
if (!timeo || !inet_wait_for_connect(sk, timeo))
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
release_sock(sk);
return err;
sock_error:
err = sock_error(sk) ? : -ECONNABORTED;
sock->state = SS_UNCONNECTED;
if (sk->sk_prot->disconnect(sk, flags))
sock->state = SS_DISCONNECTING;
goto out;
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
(TCPF_ESTABLISHED | TCPF_CLOSE_WAIT | TCPF_CLOSE)));
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
int inet_sendmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg,
size_t size)
{
struct sock *sk = sock->sk;
sock_rps_record_flow(sk);
if (!inet_sk(sk)->inet_num && !sk->sk_prot->no_autobind &&
inet_autobind(sk))
return -EAGAIN;
return sk->sk_prot->sendmsg(iocb, sk, msg, size);
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
int inet_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg,
size_t size, int flags)
{
struct sock *sk = sock->sk;
int addr_len = 0;
int err;
sock_rps_record_flow(sk);
err = sk->sk_prot->recvmsg(iocb, sk, msg, size, flags & MSG_DONTWAIT,
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
answer = NULL;
last_perm = &inetsw[p->type];
list_for_each(lh, &inetsw[p->type]) {
answer = list_entry(lh, struct inet_protosw, list);
if (INET_PROTOSW_PERMANENT & answer->flags) {
if (protocol == answer->protocol)
break;
last_perm = lh;
}
answer = NULL;
}
if (answer)
goto out_permanent;
list_add_rcu(&p->list, last_perm);
out:
spin_unlock_bh(&inetsw_lock);
return;
out_permanent:
printk(KERN_ERR "Attempt to override permanent protocol %d.\n",
protocol);
goto out;
out_illegal:
printk(KERN_ERR
"Ignoring attempt to register invalid socket type %d.\n",
p->type);
goto out;
}
void inet_unregister_protosw(struct inet_protosw *p)
{
if (INET_PROTOSW_PERMANENT & p->flags) {
printk(KERN_ERR
"Attempt to unregister permanent protocol %d.\n",
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
inet->inet_sport, inet->inet_dport, sk, false);
if (IS_ERR(rt))
return PTR_ERR(rt);
sk_setup_caps(sk, &rt->dst);
new_saddr = fl4->saddr;
if (new_saddr == old_saddr)
return 0;
if (sysctl_ip_dynaddr > 1) {
printk(KERN_INFO "%s(): shifting inet->saddr from %pI4 to %pI4\n",
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
static int inet_gso_send_check(struct sk_buff *skb)
{
const struct iphdr *iph;
const struct net_protocol *ops;
int proto;
int ihl;
int err = -EINVAL;
if (unlikely(!pskb_may_pull(skb, sizeof(*iph))))
goto out;
iph = ip_hdr(skb);
ihl = iph->ihl * 4;
if (ihl < sizeof(*iph))
goto out;
if (unlikely(!pskb_may_pull(skb, ihl)))
goto out;
__skb_pull(skb, ihl);
skb_reset_transport_header(skb);
iph = ip_hdr(skb);
proto = iph->protocol & (MAX_INET_PROTOS - 1);
err = -EPROTONOSUPPORT;
rcu_read_lock();
ops = rcu_dereference(inet_protos[proto]);
if (likely(ops && ops->gso_send_check))
err = ops->gso_send_check(skb);
rcu_read_unlock();
out:
return err;
}
static struct sk_buff *inet_gso_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
struct iphdr *iph;
const struct net_protocol *ops;
int proto;
int ihl;
int id;
unsigned int offset = 0;
if (!(features & NETIF_F_V4_CSUM))
features &= ~NETIF_F_SG;
if (unlikely(skb_shinfo(skb)->gso_type &
~(SKB_GSO_TCPV4 |
SKB_GSO_UDP |
SKB_GSO_DODGY |
SKB_GSO_TCP_ECN |
0)))
goto out;
if (unlikely(!pskb_may_pull(skb, sizeof(*iph))))
goto out;
iph = ip_hdr(skb);
ihl = iph->ihl * 4;
if (ihl < sizeof(*iph))
goto out;
if (unlikely(!pskb_may_pull(skb, ihl)))
goto out;
__skb_pull(skb, ihl);
skb_reset_transport_header(skb);
iph = ip_hdr(skb);
id = ntohs(iph->id);
proto = iph->protocol & (MAX_INET_PROTOS - 1);
segs = ERR_PTR(-EPROTONOSUPPORT);
rcu_read_lock();
ops = rcu_dereference(inet_protos[proto]);
if (likely(ops && ops->gso_segment))
segs = ops->gso_segment(skb, features);
rcu_read_unlock();
if (!segs || IS_ERR(segs))
goto out;
skb = segs;
do {
iph = ip_hdr(skb);
if (proto == IPPROTO_UDP) {
iph->id = htons(id);
iph->frag_off = htons(offset >> 3);
if (skb->next != NULL)
iph->frag_off |= htons(IP_MF);
offset += (skb->len - skb->mac_len - iph->ihl * 4);
} else
iph->id = htons(id++);
iph->tot_len = htons(skb->len - skb->mac_len);
iph->check = 0;
iph->check = ip_fast_csum(skb_network_header(skb), iph->ihl);
} while ((skb = skb->next));
out:
return segs;
}
static struct sk_buff **inet_gro_receive(struct sk_buff **head,
struct sk_buff *skb)
{
const struct net_protocol *ops;
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
proto = iph->protocol & (MAX_INET_PROTOS - 1);
rcu_read_lock();
ops = rcu_dereference(inet_protos[proto]);
if (!ops || !ops->gro_receive)
goto out_unlock;
if (*(u8 *)iph != 0x45)
goto out_unlock;
if (unlikely(ip_fast_csum((u8 *)iph, iph->ihl)))
goto out_unlock;
id = ntohl(*(__be32 *)&iph->id);
flush = (u16)((ntohl(*(__be32 *)iph) ^ skb_gro_len(skb)) | (id ^ IP_DF));
id >>= 16;
for (p = *head; p; p = p->next) {
struct iphdr *iph2;
if (!NAPI_GRO_CB(p)->same_flow)
continue;
iph2 = ip_hdr(p);
if ((iph->protocol ^ iph2->protocol) |
(iph->tos ^ iph2->tos) |
((__force u32)iph->saddr ^ (__force u32)iph2->saddr) |
((__force u32)iph->daddr ^ (__force u32)iph2->daddr)) {
NAPI_GRO_CB(p)->same_flow = 0;
continue;
}
NAPI_GRO_CB(p)->flush |=
(iph->ttl ^ iph2->ttl) |
((u16)(ntohs(iph2->id) + NAPI_GRO_CB(p)->count) ^ id);
NAPI_GRO_CB(p)->flush |= flush;
}
NAPI_GRO_CB(skb)->flush |= flush;
skb_gro_pull(skb, sizeof(*iph));
skb_set_transport_header(skb, skb_gro_offset(skb));
pp = ops->gro_receive(head, skb);
out_unlock:
rcu_read_unlock();
out:
NAPI_GRO_CB(skb)->flush |= flush;
return pp;
}
static int inet_gro_complete(struct sk_buff *skb)
{
const struct net_protocol *ops;
struct iphdr *iph = ip_hdr(skb);
int proto = iph->protocol & (MAX_INET_PROTOS - 1);
int err = -ENOSYS;
__be16 newlen = htons(skb->len - skb_network_offset(skb));
csum_replace2(&iph->check, iph->tot_len, newlen);
iph->tot_len = newlen;
rcu_read_lock();
ops = rcu_dereference(inet_protos[proto]);
if (WARN_ON(!ops || !ops->gro_complete))
goto out_unlock;
err = ops->gro_complete(skb);
out_unlock:
rcu_read_unlock();
return err;
}
int inet_ctl_sock_create(struct sock **sk, unsigned short family,
unsigned short type, unsigned char protocol,
struct net *net)
{
struct socket *sock;
int rc = sock_create_kern(family, type, protocol, &sock);
if (rc == 0) {
*sk = sock->sk;
(*sk)->sk_allocation = GFP_ATOMIC;
(*sk)->sk_prot->unhash(*sk);
sk_change_net(*sk, net);
}
return rc;
}
unsigned long snmp_fold_field(void __percpu *mib[], int offt)
{
unsigned long res = 0;
int i, j;
for_each_possible_cpu(i) {
for (j = 0; j < SNMP_ARRAY_SZ; j++)
res += *(((unsigned long *) per_cpu_ptr(mib[j], i)) + offt);
}
return res;
}
u64 snmp_fold_field64(void __percpu *mib[], int offt, size_t syncp_offset)
{
u64 res = 0;
int cpu;
for_each_possible_cpu(cpu) {
void *bhptr;
struct u64_stats_sync *syncp;
u64 v;
unsigned int start;
bhptr = per_cpu_ptr(mib[0], cpu);
syncp = (struct u64_stats_sync *)(bhptr + syncp_offset);
do {
start = u64_stats_fetch_begin_bh(syncp);
v = *(((u64 *) bhptr) + offt);
} while (u64_stats_fetch_retry_bh(syncp, start));
res += v;
}
return res;
}
int snmp_mib_init(void __percpu *ptr[2], size_t mibsize, size_t align)
{
BUG_ON(ptr == NULL);
ptr[0] = __alloc_percpu(mibsize, align);
if (!ptr[0])
return -ENOMEM;
#if SNMP_ARRAY_SZ == 2
ptr[1] = __alloc_percpu(mibsize, align);
if (!ptr[1]) {
free_percpu(ptr[0]);
ptr[0] = NULL;
return -ENOMEM;
}
#endif
return 0;
}
void snmp_mib_free(void __percpu *ptr[SNMP_ARRAY_SZ])
{
int i;
BUG_ON(ptr == NULL);
for (i = 0; i < SNMP_ARRAY_SZ; i++) {
free_percpu(ptr[i]);
ptr[i] = NULL;
}
}
static __net_init int ipv4_mib_init_net(struct net *net)
{
if (snmp_mib_init((void __percpu **)net->mib.tcp_statistics,
sizeof(struct tcp_mib),
__alignof__(struct tcp_mib)) < 0)
goto err_tcp_mib;
if (snmp_mib_init((void __percpu **)net->mib.ip_statistics,
sizeof(struct ipstats_mib),
__alignof__(struct ipstats_mib)) < 0)
goto err_ip_mib;
if (snmp_mib_init((void __percpu **)net->mib.net_statistics,
sizeof(struct linux_mib),
__alignof__(struct linux_mib)) < 0)
goto err_net_mib;
if (snmp_mib_init((void __percpu **)net->mib.udp_statistics,
sizeof(struct udp_mib),
__alignof__(struct udp_mib)) < 0)
goto err_udp_mib;
if (snmp_mib_init((void __percpu **)net->mib.udplite_statistics,
sizeof(struct udp_mib),
__alignof__(struct udp_mib)) < 0)
goto err_udplite_mib;
if (snmp_mib_init((void __percpu **)net->mib.icmp_statistics,
sizeof(struct icmp_mib),
__alignof__(struct icmp_mib)) < 0)
goto err_icmp_mib;
net->mib.icmpmsg_statistics = kzalloc(sizeof(struct icmpmsg_mib),
GFP_KERNEL);
if (!net->mib.icmpmsg_statistics)
goto err_icmpmsg_mib;
tcp_mib_init(net);
return 0;
err_icmpmsg_mib:
snmp_mib_free((void __percpu **)net->mib.icmp_statistics);
err_icmp_mib:
snmp_mib_free((void __percpu **)net->mib.udplite_statistics);
err_udplite_mib:
snmp_mib_free((void __percpu **)net->mib.udp_statistics);
err_udp_mib:
snmp_mib_free((void __percpu **)net->mib.net_statistics);
err_net_mib:
snmp_mib_free((void __percpu **)net->mib.ip_statistics);
err_ip_mib:
snmp_mib_free((void __percpu **)net->mib.tcp_statistics);
err_tcp_mib:
return -ENOMEM;
}
static __net_exit void ipv4_mib_exit_net(struct net *net)
{
kfree(net->mib.icmpmsg_statistics);
snmp_mib_free((void __percpu **)net->mib.icmp_statistics);
snmp_mib_free((void __percpu **)net->mib.udplite_statistics);
snmp_mib_free((void __percpu **)net->mib.udp_statistics);
snmp_mib_free((void __percpu **)net->mib.net_statistics);
snmp_mib_free((void __percpu **)net->mib.ip_statistics);
snmp_mib_free((void __percpu **)net->mib.tcp_statistics);
}
static int __init init_ipv4_mibs(void)
{
return register_pernet_subsys(&ipv4_mib_ops);
}
static int __init inet_init(void)
{
struct sk_buff *dummy_skb;
struct inet_protosw *q;
struct list_head *r;
int rc = -EINVAL;
BUILD_BUG_ON(sizeof(struct inet_skb_parm) > sizeof(dummy_skb->cb));
sysctl_local_reserved_ports = kzalloc(65536 / 8, GFP_KERNEL);
if (!sysctl_local_reserved_ports)
goto out;
rc = proto_register(&tcp_prot, 1);
if (rc)
goto out_free_reserved_ports;
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
tcp_prot.sysctl_mem = init_net.ipv4.sysctl_tcp_mem;
if (inet_add_protocol(&icmp_protocol, IPPROTO_ICMP) < 0)
printk(KERN_CRIT "inet_init: Cannot add ICMP protocol\n");
if (inet_add_protocol(&udp_protocol, IPPROTO_UDP) < 0)
printk(KERN_CRIT "inet_init: Cannot add UDP protocol\n");
if (inet_add_protocol(&tcp_protocol, IPPROTO_TCP) < 0)
printk(KERN_CRIT "inet_init: Cannot add TCP protocol\n");
#ifdef CONFIG_IP_MULTICAST
if (inet_add_protocol(&igmp_protocol, IPPROTO_IGMP) < 0)
printk(KERN_CRIT "inet_init: Cannot add IGMP protocol\n");
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
printk(KERN_CRIT "inet_init: Cannot init ipv4 mroute\n");
#endif
if (init_ipv4_mibs())
printk(KERN_CRIT "inet_init: Cannot init ipv4 mibs\n");
ipv4_proc_init();
ipfrag_init();
dev_add_pack(&ip_packet_type);
rc = 0;
out:
return rc;
out_unregister_raw_proto:
proto_unregister(&raw_prot);
out_unregister_udp_proto:
proto_unregister(&udp_prot);
out_unregister_tcp_proto:
proto_unregister(&tcp_prot);
out_free_reserved_ports:
kfree(sysctl_local_reserved_ports);
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
