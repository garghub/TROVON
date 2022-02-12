static int udp_lib_lport_inuse(struct net *net, __u16 num,
const struct udp_hslot *hslot,
unsigned long *bitmap,
struct sock *sk,
int (*saddr_comp)(const struct sock *sk1,
const struct sock *sk2,
bool match_wildcard),
unsigned int log)
{
struct sock *sk2;
kuid_t uid = sock_i_uid(sk);
sk_for_each(sk2, &hslot->head) {
if (net_eq(sock_net(sk2), net) &&
sk2 != sk &&
(bitmap || udp_sk(sk2)->udp_port_hash == num) &&
(!sk2->sk_reuse || !sk->sk_reuse) &&
(!sk2->sk_bound_dev_if || !sk->sk_bound_dev_if ||
sk2->sk_bound_dev_if == sk->sk_bound_dev_if) &&
(!sk2->sk_reuseport || !sk->sk_reuseport ||
rcu_access_pointer(sk->sk_reuseport_cb) ||
!uid_eq(uid, sock_i_uid(sk2))) &&
saddr_comp(sk, sk2, true)) {
if (!bitmap)
return 1;
__set_bit(udp_sk(sk2)->udp_port_hash >> log, bitmap);
}
}
return 0;
}
static int udp_lib_lport_inuse2(struct net *net, __u16 num,
struct udp_hslot *hslot2,
struct sock *sk,
int (*saddr_comp)(const struct sock *sk1,
const struct sock *sk2,
bool match_wildcard))
{
struct sock *sk2;
kuid_t uid = sock_i_uid(sk);
int res = 0;
spin_lock(&hslot2->lock);
udp_portaddr_for_each_entry(sk2, &hslot2->head) {
if (net_eq(sock_net(sk2), net) &&
sk2 != sk &&
(udp_sk(sk2)->udp_port_hash == num) &&
(!sk2->sk_reuse || !sk->sk_reuse) &&
(!sk2->sk_bound_dev_if || !sk->sk_bound_dev_if ||
sk2->sk_bound_dev_if == sk->sk_bound_dev_if) &&
(!sk2->sk_reuseport || !sk->sk_reuseport ||
rcu_access_pointer(sk->sk_reuseport_cb) ||
!uid_eq(uid, sock_i_uid(sk2))) &&
saddr_comp(sk, sk2, true)) {
res = 1;
break;
}
}
spin_unlock(&hslot2->lock);
return res;
}
static int udp_reuseport_add_sock(struct sock *sk, struct udp_hslot *hslot,
int (*saddr_same)(const struct sock *sk1,
const struct sock *sk2,
bool match_wildcard))
{
struct net *net = sock_net(sk);
kuid_t uid = sock_i_uid(sk);
struct sock *sk2;
sk_for_each(sk2, &hslot->head) {
if (net_eq(sock_net(sk2), net) &&
sk2 != sk &&
sk2->sk_family == sk->sk_family &&
ipv6_only_sock(sk2) == ipv6_only_sock(sk) &&
(udp_sk(sk2)->udp_port_hash == udp_sk(sk)->udp_port_hash) &&
(sk2->sk_bound_dev_if == sk->sk_bound_dev_if) &&
sk2->sk_reuseport && uid_eq(uid, sock_i_uid(sk2)) &&
(*saddr_same)(sk, sk2, false)) {
return reuseport_add_sock(sk, sk2);
}
}
if (!rcu_access_pointer(sk->sk_reuseport_cb))
return reuseport_alloc(sk);
return 0;
}
int udp_lib_get_port(struct sock *sk, unsigned short snum,
int (*saddr_comp)(const struct sock *sk1,
const struct sock *sk2,
bool match_wildcard),
unsigned int hash2_nulladdr)
{
struct udp_hslot *hslot, *hslot2;
struct udp_table *udptable = sk->sk_prot->h.udp_table;
int error = 1;
struct net *net = sock_net(sk);
if (!snum) {
int low, high, remaining;
unsigned int rand;
unsigned short first, last;
DECLARE_BITMAP(bitmap, PORTS_PER_CHAIN);
inet_get_local_port_range(net, &low, &high);
remaining = (high - low) + 1;
rand = prandom_u32();
first = reciprocal_scale(rand, remaining) + low;
rand = (rand | 1) * (udptable->mask + 1);
last = first + udptable->mask + 1;
do {
hslot = udp_hashslot(udptable, net, first);
bitmap_zero(bitmap, PORTS_PER_CHAIN);
spin_lock_bh(&hslot->lock);
udp_lib_lport_inuse(net, snum, hslot, bitmap, sk,
saddr_comp, udptable->log);
snum = first;
do {
if (low <= snum && snum <= high &&
!test_bit(snum >> udptable->log, bitmap) &&
!inet_is_local_reserved_port(net, snum))
goto found;
snum += rand;
} while (snum != first);
spin_unlock_bh(&hslot->lock);
} while (++first != last);
goto fail;
} else {
hslot = udp_hashslot(udptable, net, snum);
spin_lock_bh(&hslot->lock);
if (hslot->count > 10) {
int exist;
unsigned int slot2 = udp_sk(sk)->udp_portaddr_hash ^ snum;
slot2 &= udptable->mask;
hash2_nulladdr &= udptable->mask;
hslot2 = udp_hashslot2(udptable, slot2);
if (hslot->count < hslot2->count)
goto scan_primary_hash;
exist = udp_lib_lport_inuse2(net, snum, hslot2,
sk, saddr_comp);
if (!exist && (hash2_nulladdr != slot2)) {
hslot2 = udp_hashslot2(udptable, hash2_nulladdr);
exist = udp_lib_lport_inuse2(net, snum, hslot2,
sk, saddr_comp);
}
if (exist)
goto fail_unlock;
else
goto found;
}
scan_primary_hash:
if (udp_lib_lport_inuse(net, snum, hslot, NULL, sk,
saddr_comp, 0))
goto fail_unlock;
}
found:
inet_sk(sk)->inet_num = snum;
udp_sk(sk)->udp_port_hash = snum;
udp_sk(sk)->udp_portaddr_hash ^= snum;
if (sk_unhashed(sk)) {
if (sk->sk_reuseport &&
udp_reuseport_add_sock(sk, hslot, saddr_comp)) {
inet_sk(sk)->inet_num = 0;
udp_sk(sk)->udp_port_hash = 0;
udp_sk(sk)->udp_portaddr_hash ^= snum;
goto fail_unlock;
}
sk_add_node_rcu(sk, &hslot->head);
hslot->count++;
sock_prot_inuse_add(sock_net(sk), sk->sk_prot, 1);
hslot2 = udp_hashslot2(udptable, udp_sk(sk)->udp_portaddr_hash);
spin_lock(&hslot2->lock);
if (IS_ENABLED(CONFIG_IPV6) && sk->sk_reuseport &&
sk->sk_family == AF_INET6)
hlist_add_tail_rcu(&udp_sk(sk)->udp_portaddr_node,
&hslot2->head);
else
hlist_add_head_rcu(&udp_sk(sk)->udp_portaddr_node,
&hslot2->head);
hslot2->count++;
spin_unlock(&hslot2->lock);
}
sock_set_flag(sk, SOCK_RCU_FREE);
error = 0;
fail_unlock:
spin_unlock_bh(&hslot->lock);
fail:
return error;
}
int ipv4_rcv_saddr_equal(const struct sock *sk1, const struct sock *sk2,
bool match_wildcard)
{
struct inet_sock *inet1 = inet_sk(sk1), *inet2 = inet_sk(sk2);
if (!ipv6_only_sock(sk2)) {
if (inet1->inet_rcv_saddr == inet2->inet_rcv_saddr)
return 1;
if (!inet1->inet_rcv_saddr || !inet2->inet_rcv_saddr)
return match_wildcard;
}
return 0;
}
static u32 udp4_portaddr_hash(const struct net *net, __be32 saddr,
unsigned int port)
{
return jhash_1word((__force u32)saddr, net_hash_mix(net)) ^ port;
}
int udp_v4_get_port(struct sock *sk, unsigned short snum)
{
unsigned int hash2_nulladdr =
udp4_portaddr_hash(sock_net(sk), htonl(INADDR_ANY), snum);
unsigned int hash2_partial =
udp4_portaddr_hash(sock_net(sk), inet_sk(sk)->inet_rcv_saddr, 0);
udp_sk(sk)->udp_portaddr_hash = hash2_partial;
return udp_lib_get_port(sk, snum, ipv4_rcv_saddr_equal, hash2_nulladdr);
}
static int compute_score(struct sock *sk, struct net *net,
__be32 saddr, __be16 sport,
__be32 daddr, unsigned short hnum, int dif)
{
int score;
struct inet_sock *inet;
if (!net_eq(sock_net(sk), net) ||
udp_sk(sk)->udp_port_hash != hnum ||
ipv6_only_sock(sk))
return -1;
score = (sk->sk_family == PF_INET) ? 2 : 1;
inet = inet_sk(sk);
if (inet->inet_rcv_saddr) {
if (inet->inet_rcv_saddr != daddr)
return -1;
score += 4;
}
if (inet->inet_daddr) {
if (inet->inet_daddr != saddr)
return -1;
score += 4;
}
if (inet->inet_dport) {
if (inet->inet_dport != sport)
return -1;
score += 4;
}
if (sk->sk_bound_dev_if) {
if (sk->sk_bound_dev_if != dif)
return -1;
score += 4;
}
if (sk->sk_incoming_cpu == raw_smp_processor_id())
score++;
return score;
}
static u32 udp_ehashfn(const struct net *net, const __be32 laddr,
const __u16 lport, const __be32 faddr,
const __be16 fport)
{
static u32 udp_ehash_secret __read_mostly;
net_get_random_once(&udp_ehash_secret, sizeof(udp_ehash_secret));
return __inet_ehashfn(laddr, lport, faddr, fport,
udp_ehash_secret + net_hash_mix(net));
}
static struct sock *udp4_lib_lookup2(struct net *net,
__be32 saddr, __be16 sport,
__be32 daddr, unsigned int hnum, int dif,
struct udp_hslot *hslot2,
struct sk_buff *skb)
{
struct sock *sk, *result;
int score, badness, matches = 0, reuseport = 0;
u32 hash = 0;
result = NULL;
badness = 0;
udp_portaddr_for_each_entry_rcu(sk, &hslot2->head) {
score = compute_score(sk, net, saddr, sport,
daddr, hnum, dif);
if (score > badness) {
reuseport = sk->sk_reuseport;
if (reuseport) {
hash = udp_ehashfn(net, daddr, hnum,
saddr, sport);
result = reuseport_select_sock(sk, hash, skb,
sizeof(struct udphdr));
if (result)
return result;
matches = 1;
}
badness = score;
result = sk;
} else if (score == badness && reuseport) {
matches++;
if (reciprocal_scale(hash, matches) == 0)
result = sk;
hash = next_pseudo_random32(hash);
}
}
return result;
}
struct sock *__udp4_lib_lookup(struct net *net, __be32 saddr,
__be16 sport, __be32 daddr, __be16 dport,
int dif, struct udp_table *udptable, struct sk_buff *skb)
{
struct sock *sk, *result;
unsigned short hnum = ntohs(dport);
unsigned int hash2, slot2, slot = udp_hashfn(net, hnum, udptable->mask);
struct udp_hslot *hslot2, *hslot = &udptable->hash[slot];
int score, badness, matches = 0, reuseport = 0;
u32 hash = 0;
if (hslot->count > 10) {
hash2 = udp4_portaddr_hash(net, daddr, hnum);
slot2 = hash2 & udptable->mask;
hslot2 = &udptable->hash2[slot2];
if (hslot->count < hslot2->count)
goto begin;
result = udp4_lib_lookup2(net, saddr, sport,
daddr, hnum, dif,
hslot2, skb);
if (!result) {
unsigned int old_slot2 = slot2;
hash2 = udp4_portaddr_hash(net, htonl(INADDR_ANY), hnum);
slot2 = hash2 & udptable->mask;
if (unlikely(slot2 == old_slot2))
return result;
hslot2 = &udptable->hash2[slot2];
if (hslot->count < hslot2->count)
goto begin;
result = udp4_lib_lookup2(net, saddr, sport,
daddr, hnum, dif,
hslot2, skb);
}
return result;
}
begin:
result = NULL;
badness = 0;
sk_for_each_rcu(sk, &hslot->head) {
score = compute_score(sk, net, saddr, sport,
daddr, hnum, dif);
if (score > badness) {
reuseport = sk->sk_reuseport;
if (reuseport) {
hash = udp_ehashfn(net, daddr, hnum,
saddr, sport);
result = reuseport_select_sock(sk, hash, skb,
sizeof(struct udphdr));
if (result)
return result;
matches = 1;
}
result = sk;
badness = score;
} else if (score == badness && reuseport) {
matches++;
if (reciprocal_scale(hash, matches) == 0)
result = sk;
hash = next_pseudo_random32(hash);
}
}
return result;
}
static inline struct sock *__udp4_lib_lookup_skb(struct sk_buff *skb,
__be16 sport, __be16 dport,
struct udp_table *udptable)
{
const struct iphdr *iph = ip_hdr(skb);
return __udp4_lib_lookup(dev_net(skb->dev), iph->saddr, sport,
iph->daddr, dport, inet_iif(skb),
udptable, skb);
}
struct sock *udp4_lib_lookup_skb(struct sk_buff *skb,
__be16 sport, __be16 dport)
{
return __udp4_lib_lookup_skb(skb, sport, dport, &udp_table);
}
struct sock *udp4_lib_lookup(struct net *net, __be32 saddr, __be16 sport,
__be32 daddr, __be16 dport, int dif)
{
struct sock *sk;
sk = __udp4_lib_lookup(net, saddr, sport, daddr, dport,
dif, &udp_table, NULL);
if (sk && !atomic_inc_not_zero(&sk->sk_refcnt))
sk = NULL;
return sk;
}
static inline bool __udp_is_mcast_sock(struct net *net, struct sock *sk,
__be16 loc_port, __be32 loc_addr,
__be16 rmt_port, __be32 rmt_addr,
int dif, unsigned short hnum)
{
struct inet_sock *inet = inet_sk(sk);
if (!net_eq(sock_net(sk), net) ||
udp_sk(sk)->udp_port_hash != hnum ||
(inet->inet_daddr && inet->inet_daddr != rmt_addr) ||
(inet->inet_dport != rmt_port && inet->inet_dport) ||
(inet->inet_rcv_saddr && inet->inet_rcv_saddr != loc_addr) ||
ipv6_only_sock(sk) ||
(sk->sk_bound_dev_if && sk->sk_bound_dev_if != dif))
return false;
if (!ip_mc_sf_allow(sk, loc_addr, rmt_addr, dif))
return false;
return true;
}
void __udp4_lib_err(struct sk_buff *skb, u32 info, struct udp_table *udptable)
{
struct inet_sock *inet;
const struct iphdr *iph = (const struct iphdr *)skb->data;
struct udphdr *uh = (struct udphdr *)(skb->data+(iph->ihl<<2));
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct sock *sk;
int harderr;
int err;
struct net *net = dev_net(skb->dev);
sk = __udp4_lib_lookup(net, iph->daddr, uh->dest,
iph->saddr, uh->source, skb->dev->ifindex, udptable,
NULL);
if (!sk) {
__ICMP_INC_STATS(net, ICMP_MIB_INERRORS);
return;
}
err = 0;
harderr = 0;
inet = inet_sk(sk);
switch (type) {
default:
case ICMP_TIME_EXCEEDED:
err = EHOSTUNREACH;
break;
case ICMP_SOURCE_QUENCH:
goto out;
case ICMP_PARAMETERPROB:
err = EPROTO;
harderr = 1;
break;
case ICMP_DEST_UNREACH:
if (code == ICMP_FRAG_NEEDED) {
ipv4_sk_update_pmtu(skb, sk, info);
if (inet->pmtudisc != IP_PMTUDISC_DONT) {
err = EMSGSIZE;
harderr = 1;
break;
}
goto out;
}
err = EHOSTUNREACH;
if (code <= NR_ICMP_UNREACH) {
harderr = icmp_err_convert[code].fatal;
err = icmp_err_convert[code].errno;
}
break;
case ICMP_REDIRECT:
ipv4_sk_redirect(skb, sk);
goto out;
}
if (!inet->recverr) {
if (!harderr || sk->sk_state != TCP_ESTABLISHED)
goto out;
} else
ip_icmp_error(sk, skb, err, uh->dest, info, (u8 *)(uh+1));
sk->sk_err = err;
sk->sk_error_report(sk);
out:
return;
}
void udp_err(struct sk_buff *skb, u32 info)
{
__udp4_lib_err(skb, info, &udp_table);
}
void udp_flush_pending_frames(struct sock *sk)
{
struct udp_sock *up = udp_sk(sk);
if (up->pending) {
up->len = 0;
up->pending = 0;
ip_flush_pending_frames(sk);
}
}
void udp4_hwcsum(struct sk_buff *skb, __be32 src, __be32 dst)
{
struct udphdr *uh = udp_hdr(skb);
int offset = skb_transport_offset(skb);
int len = skb->len - offset;
int hlen = len;
__wsum csum = 0;
if (!skb_has_frag_list(skb)) {
skb->csum_start = skb_transport_header(skb) - skb->head;
skb->csum_offset = offsetof(struct udphdr, check);
uh->check = ~csum_tcpudp_magic(src, dst, len,
IPPROTO_UDP, 0);
} else {
struct sk_buff *frags;
skb_walk_frags(skb, frags) {
csum = csum_add(csum, frags->csum);
hlen -= frags->len;
}
csum = skb_checksum(skb, offset, hlen, csum);
skb->ip_summed = CHECKSUM_NONE;
uh->check = csum_tcpudp_magic(src, dst, len, IPPROTO_UDP, csum);
if (uh->check == 0)
uh->check = CSUM_MANGLED_0;
}
}
void udp_set_csum(bool nocheck, struct sk_buff *skb,
__be32 saddr, __be32 daddr, int len)
{
struct udphdr *uh = udp_hdr(skb);
if (nocheck) {
uh->check = 0;
} else if (skb_is_gso(skb)) {
uh->check = ~udp_v4_check(len, saddr, daddr, 0);
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
uh->check = 0;
uh->check = udp_v4_check(len, saddr, daddr, lco_csum(skb));
if (uh->check == 0)
uh->check = CSUM_MANGLED_0;
} else {
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_start = skb_transport_header(skb) - skb->head;
skb->csum_offset = offsetof(struct udphdr, check);
uh->check = ~udp_v4_check(len, saddr, daddr, 0);
}
}
static int udp_send_skb(struct sk_buff *skb, struct flowi4 *fl4)
{
struct sock *sk = skb->sk;
struct inet_sock *inet = inet_sk(sk);
struct udphdr *uh;
int err = 0;
int is_udplite = IS_UDPLITE(sk);
int offset = skb_transport_offset(skb);
int len = skb->len - offset;
__wsum csum = 0;
uh = udp_hdr(skb);
uh->source = inet->inet_sport;
uh->dest = fl4->fl4_dport;
uh->len = htons(len);
uh->check = 0;
if (is_udplite)
csum = udplite_csum(skb);
else if (sk->sk_no_check_tx) {
skb->ip_summed = CHECKSUM_NONE;
goto send;
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
udp4_hwcsum(skb, fl4->saddr, fl4->daddr);
goto send;
} else
csum = udp_csum(skb);
uh->check = csum_tcpudp_magic(fl4->saddr, fl4->daddr, len,
sk->sk_protocol, csum);
if (uh->check == 0)
uh->check = CSUM_MANGLED_0;
send:
err = ip_send_skb(sock_net(sk), skb);
if (err) {
if (err == -ENOBUFS && !inet->recverr) {
UDP_INC_STATS(sock_net(sk),
UDP_MIB_SNDBUFERRORS, is_udplite);
err = 0;
}
} else
UDP_INC_STATS(sock_net(sk),
UDP_MIB_OUTDATAGRAMS, is_udplite);
return err;
}
int udp_push_pending_frames(struct sock *sk)
{
struct udp_sock *up = udp_sk(sk);
struct inet_sock *inet = inet_sk(sk);
struct flowi4 *fl4 = &inet->cork.fl.u.ip4;
struct sk_buff *skb;
int err = 0;
skb = ip_finish_skb(sk, fl4);
if (!skb)
goto out;
err = udp_send_skb(skb, fl4);
out:
up->len = 0;
up->pending = 0;
return err;
}
int udp_sendmsg(struct sock *sk, struct msghdr *msg, size_t len)
{
struct inet_sock *inet = inet_sk(sk);
struct udp_sock *up = udp_sk(sk);
struct flowi4 fl4_stack;
struct flowi4 *fl4;
int ulen = len;
struct ipcm_cookie ipc;
struct rtable *rt = NULL;
int free = 0;
int connected = 0;
__be32 daddr, faddr, saddr;
__be16 dport;
u8 tos;
int err, is_udplite = IS_UDPLITE(sk);
int corkreq = up->corkflag || msg->msg_flags&MSG_MORE;
int (*getfrag)(void *, char *, int, int, int, struct sk_buff *);
struct sk_buff *skb;
struct ip_options_data opt_copy;
if (len > 0xFFFF)
return -EMSGSIZE;
if (msg->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
ipc.opt = NULL;
ipc.tx_flags = 0;
ipc.ttl = 0;
ipc.tos = -1;
getfrag = is_udplite ? udplite_getfrag : ip_generic_getfrag;
fl4 = &inet->cork.fl.u.ip4;
if (up->pending) {
lock_sock(sk);
if (likely(up->pending)) {
if (unlikely(up->pending != AF_INET)) {
release_sock(sk);
return -EINVAL;
}
goto do_append_data;
}
release_sock(sk);
}
ulen += sizeof(struct udphdr);
if (msg->msg_name) {
DECLARE_SOCKADDR(struct sockaddr_in *, usin, msg->msg_name);
if (msg->msg_namelen < sizeof(*usin))
return -EINVAL;
if (usin->sin_family != AF_INET) {
if (usin->sin_family != AF_UNSPEC)
return -EAFNOSUPPORT;
}
daddr = usin->sin_addr.s_addr;
dport = usin->sin_port;
if (dport == 0)
return -EINVAL;
} else {
if (sk->sk_state != TCP_ESTABLISHED)
return -EDESTADDRREQ;
daddr = inet->inet_daddr;
dport = inet->inet_dport;
connected = 1;
}
ipc.sockc.tsflags = sk->sk_tsflags;
ipc.addr = inet->inet_saddr;
ipc.oif = sk->sk_bound_dev_if;
if (msg->msg_controllen) {
err = ip_cmsg_send(sk, msg, &ipc, sk->sk_family == AF_INET6);
if (unlikely(err)) {
kfree(ipc.opt);
return err;
}
if (ipc.opt)
free = 1;
connected = 0;
}
if (!ipc.opt) {
struct ip_options_rcu *inet_opt;
rcu_read_lock();
inet_opt = rcu_dereference(inet->inet_opt);
if (inet_opt) {
memcpy(&opt_copy, inet_opt,
sizeof(*inet_opt) + inet_opt->opt.optlen);
ipc.opt = &opt_copy.opt;
}
rcu_read_unlock();
}
saddr = ipc.addr;
ipc.addr = faddr = daddr;
sock_tx_timestamp(sk, ipc.sockc.tsflags, &ipc.tx_flags);
if (ipc.opt && ipc.opt->opt.srr) {
if (!daddr)
return -EINVAL;
faddr = ipc.opt->opt.faddr;
connected = 0;
}
tos = get_rttos(&ipc, inet);
if (sock_flag(sk, SOCK_LOCALROUTE) ||
(msg->msg_flags & MSG_DONTROUTE) ||
(ipc.opt && ipc.opt->opt.is_strictroute)) {
tos |= RTO_ONLINK;
connected = 0;
}
if (ipv4_is_multicast(daddr)) {
if (!ipc.oif)
ipc.oif = inet->mc_index;
if (!saddr)
saddr = inet->mc_addr;
connected = 0;
} else if (!ipc.oif)
ipc.oif = inet->uc_index;
if (connected)
rt = (struct rtable *)sk_dst_check(sk, 0);
if (!rt) {
struct net *net = sock_net(sk);
__u8 flow_flags = inet_sk_flowi_flags(sk);
fl4 = &fl4_stack;
flowi4_init_output(fl4, ipc.oif, sk->sk_mark, tos,
RT_SCOPE_UNIVERSE, sk->sk_protocol,
flow_flags,
faddr, saddr, dport, inet->inet_sport);
if (!saddr && ipc.oif) {
err = l3mdev_get_saddr(net, ipc.oif, fl4);
if (err < 0)
goto out;
}
security_sk_classify_flow(sk, flowi4_to_flowi(fl4));
rt = ip_route_output_flow(net, fl4, sk);
if (IS_ERR(rt)) {
err = PTR_ERR(rt);
rt = NULL;
if (err == -ENETUNREACH)
IP_INC_STATS(net, IPSTATS_MIB_OUTNOROUTES);
goto out;
}
err = -EACCES;
if ((rt->rt_flags & RTCF_BROADCAST) &&
!sock_flag(sk, SOCK_BROADCAST))
goto out;
if (connected)
sk_dst_set(sk, dst_clone(&rt->dst));
}
if (msg->msg_flags&MSG_CONFIRM)
goto do_confirm;
back_from_confirm:
saddr = fl4->saddr;
if (!ipc.addr)
daddr = ipc.addr = fl4->daddr;
if (!corkreq) {
skb = ip_make_skb(sk, fl4, getfrag, msg, ulen,
sizeof(struct udphdr), &ipc, &rt,
msg->msg_flags);
err = PTR_ERR(skb);
if (!IS_ERR_OR_NULL(skb))
err = udp_send_skb(skb, fl4);
goto out;
}
lock_sock(sk);
if (unlikely(up->pending)) {
release_sock(sk);
net_dbg_ratelimited("cork app bug 2\n");
err = -EINVAL;
goto out;
}
fl4 = &inet->cork.fl.u.ip4;
fl4->daddr = daddr;
fl4->saddr = saddr;
fl4->fl4_dport = dport;
fl4->fl4_sport = inet->inet_sport;
up->pending = AF_INET;
do_append_data:
up->len += ulen;
err = ip_append_data(sk, fl4, getfrag, msg, ulen,
sizeof(struct udphdr), &ipc, &rt,
corkreq ? msg->msg_flags|MSG_MORE : msg->msg_flags);
if (err)
udp_flush_pending_frames(sk);
else if (!corkreq)
err = udp_push_pending_frames(sk);
else if (unlikely(skb_queue_empty(&sk->sk_write_queue)))
up->pending = 0;
release_sock(sk);
out:
ip_rt_put(rt);
if (free)
kfree(ipc.opt);
if (!err)
return len;
if (err == -ENOBUFS || test_bit(SOCK_NOSPACE, &sk->sk_socket->flags)) {
UDP_INC_STATS(sock_net(sk),
UDP_MIB_SNDBUFERRORS, is_udplite);
}
return err;
do_confirm:
dst_confirm(&rt->dst);
if (!(msg->msg_flags&MSG_PROBE) || len)
goto back_from_confirm;
err = 0;
goto out;
}
int udp_sendpage(struct sock *sk, struct page *page, int offset,
size_t size, int flags)
{
struct inet_sock *inet = inet_sk(sk);
struct udp_sock *up = udp_sk(sk);
int ret;
if (flags & MSG_SENDPAGE_NOTLAST)
flags |= MSG_MORE;
if (!up->pending) {
struct msghdr msg = { .msg_flags = flags|MSG_MORE };
ret = udp_sendmsg(sk, &msg, 0);
if (ret < 0)
return ret;
}
lock_sock(sk);
if (unlikely(!up->pending)) {
release_sock(sk);
net_dbg_ratelimited("udp cork app bug 3\n");
return -EINVAL;
}
ret = ip_append_page(sk, &inet->cork.fl.u.ip4,
page, offset, size, flags);
if (ret == -EOPNOTSUPP) {
release_sock(sk);
return sock_no_sendpage(sk->sk_socket, page, offset,
size, flags);
}
if (ret < 0) {
udp_flush_pending_frames(sk);
goto out;
}
up->len += size;
if (!(up->corkflag || (flags&MSG_MORE)))
ret = udp_push_pending_frames(sk);
if (!ret)
ret = size;
out:
release_sock(sk);
return ret;
}
static int first_packet_length(struct sock *sk)
{
struct sk_buff_head list_kill, *rcvq = &sk->sk_receive_queue;
struct sk_buff *skb;
int res;
__skb_queue_head_init(&list_kill);
spin_lock_bh(&rcvq->lock);
while ((skb = skb_peek(rcvq)) != NULL &&
udp_lib_checksum_complete(skb)) {
__UDP_INC_STATS(sock_net(sk), UDP_MIB_CSUMERRORS,
IS_UDPLITE(sk));
__UDP_INC_STATS(sock_net(sk), UDP_MIB_INERRORS,
IS_UDPLITE(sk));
atomic_inc(&sk->sk_drops);
__skb_unlink(skb, rcvq);
__skb_queue_tail(&list_kill, skb);
}
res = skb ? skb->len : -1;
spin_unlock_bh(&rcvq->lock);
if (!skb_queue_empty(&list_kill)) {
bool slow = lock_sock_fast(sk);
__skb_queue_purge(&list_kill);
sk_mem_reclaim_partial(sk);
unlock_sock_fast(sk, slow);
}
return res;
}
int udp_ioctl(struct sock *sk, int cmd, unsigned long arg)
{
switch (cmd) {
case SIOCOUTQ:
{
int amount = sk_wmem_alloc_get(sk);
return put_user(amount, (int __user *)arg);
}
case SIOCINQ:
{
int amount = max_t(int, 0, first_packet_length(sk));
return put_user(amount, (int __user *)arg);
}
default:
return -ENOIOCTLCMD;
}
return 0;
}
int udp_recvmsg(struct sock *sk, struct msghdr *msg, size_t len, int noblock,
int flags, int *addr_len)
{
struct inet_sock *inet = inet_sk(sk);
DECLARE_SOCKADDR(struct sockaddr_in *, sin, msg->msg_name);
struct sk_buff *skb;
unsigned int ulen, copied;
int peeked, peeking, off;
int err;
int is_udplite = IS_UDPLITE(sk);
bool checksum_valid = false;
bool slow;
if (flags & MSG_ERRQUEUE)
return ip_recv_error(sk, msg, len, addr_len);
try_again:
peeking = off = sk_peek_offset(sk, flags);
skb = __skb_recv_datagram(sk, flags | (noblock ? MSG_DONTWAIT : 0),
&peeked, &off, &err);
if (!skb)
return err;
ulen = skb->len;
copied = len;
if (copied > ulen - off)
copied = ulen - off;
else if (copied < ulen)
msg->msg_flags |= MSG_TRUNC;
if (copied < ulen || UDP_SKB_CB(skb)->partial_cov || peeking) {
checksum_valid = !udp_lib_checksum_complete(skb);
if (!checksum_valid)
goto csum_copy_err;
}
if (checksum_valid || skb_csum_unnecessary(skb))
err = skb_copy_datagram_msg(skb, off, msg, copied);
else {
err = skb_copy_and_csum_datagram_msg(skb, off, msg);
if (err == -EINVAL)
goto csum_copy_err;
}
if (unlikely(err)) {
trace_kfree_skb(skb, udp_recvmsg);
if (!peeked) {
atomic_inc(&sk->sk_drops);
UDP_INC_STATS(sock_net(sk),
UDP_MIB_INERRORS, is_udplite);
}
skb_free_datagram_locked(sk, skb);
return err;
}
if (!peeked)
UDP_INC_STATS(sock_net(sk),
UDP_MIB_INDATAGRAMS, is_udplite);
sock_recv_ts_and_drops(msg, sk, skb);
if (sin) {
sin->sin_family = AF_INET;
sin->sin_port = udp_hdr(skb)->source;
sin->sin_addr.s_addr = ip_hdr(skb)->saddr;
memset(sin->sin_zero, 0, sizeof(sin->sin_zero));
*addr_len = sizeof(*sin);
}
if (inet->cmsg_flags)
ip_cmsg_recv_offset(msg, skb, sizeof(struct udphdr) + off);
err = copied;
if (flags & MSG_TRUNC)
err = ulen;
__skb_free_datagram_locked(sk, skb, peeking ? -err : err);
return err;
csum_copy_err:
slow = lock_sock_fast(sk);
if (!skb_kill_datagram(sk, skb, flags)) {
UDP_INC_STATS(sock_net(sk), UDP_MIB_CSUMERRORS, is_udplite);
UDP_INC_STATS(sock_net(sk), UDP_MIB_INERRORS, is_udplite);
}
unlock_sock_fast(sk, slow);
cond_resched();
msg->msg_flags &= ~MSG_TRUNC;
goto try_again;
}
int udp_disconnect(struct sock *sk, int flags)
{
struct inet_sock *inet = inet_sk(sk);
sk->sk_state = TCP_CLOSE;
inet->inet_daddr = 0;
inet->inet_dport = 0;
sock_rps_reset_rxhash(sk);
sk->sk_bound_dev_if = 0;
if (!(sk->sk_userlocks & SOCK_BINDADDR_LOCK))
inet_reset_saddr(sk);
if (!(sk->sk_userlocks & SOCK_BINDPORT_LOCK)) {
sk->sk_prot->unhash(sk);
inet->inet_sport = 0;
}
sk_dst_reset(sk);
return 0;
}
void udp_lib_unhash(struct sock *sk)
{
if (sk_hashed(sk)) {
struct udp_table *udptable = sk->sk_prot->h.udp_table;
struct udp_hslot *hslot, *hslot2;
hslot = udp_hashslot(udptable, sock_net(sk),
udp_sk(sk)->udp_port_hash);
hslot2 = udp_hashslot2(udptable, udp_sk(sk)->udp_portaddr_hash);
spin_lock_bh(&hslot->lock);
if (rcu_access_pointer(sk->sk_reuseport_cb))
reuseport_detach_sock(sk);
if (sk_del_node_init_rcu(sk)) {
hslot->count--;
inet_sk(sk)->inet_num = 0;
sock_prot_inuse_add(sock_net(sk), sk->sk_prot, -1);
spin_lock(&hslot2->lock);
hlist_del_init_rcu(&udp_sk(sk)->udp_portaddr_node);
hslot2->count--;
spin_unlock(&hslot2->lock);
}
spin_unlock_bh(&hslot->lock);
}
}
void udp_lib_rehash(struct sock *sk, u16 newhash)
{
if (sk_hashed(sk)) {
struct udp_table *udptable = sk->sk_prot->h.udp_table;
struct udp_hslot *hslot, *hslot2, *nhslot2;
hslot2 = udp_hashslot2(udptable, udp_sk(sk)->udp_portaddr_hash);
nhslot2 = udp_hashslot2(udptable, newhash);
udp_sk(sk)->udp_portaddr_hash = newhash;
if (hslot2 != nhslot2 ||
rcu_access_pointer(sk->sk_reuseport_cb)) {
hslot = udp_hashslot(udptable, sock_net(sk),
udp_sk(sk)->udp_port_hash);
spin_lock_bh(&hslot->lock);
if (rcu_access_pointer(sk->sk_reuseport_cb))
reuseport_detach_sock(sk);
if (hslot2 != nhslot2) {
spin_lock(&hslot2->lock);
hlist_del_init_rcu(&udp_sk(sk)->udp_portaddr_node);
hslot2->count--;
spin_unlock(&hslot2->lock);
spin_lock(&nhslot2->lock);
hlist_add_head_rcu(&udp_sk(sk)->udp_portaddr_node,
&nhslot2->head);
nhslot2->count++;
spin_unlock(&nhslot2->lock);
}
spin_unlock_bh(&hslot->lock);
}
}
}
static void udp_v4_rehash(struct sock *sk)
{
u16 new_hash = udp4_portaddr_hash(sock_net(sk),
inet_sk(sk)->inet_rcv_saddr,
inet_sk(sk)->inet_num);
udp_lib_rehash(sk, new_hash);
}
static int __udp_queue_rcv_skb(struct sock *sk, struct sk_buff *skb)
{
int rc;
if (inet_sk(sk)->inet_daddr) {
sock_rps_save_rxhash(sk, skb);
sk_mark_napi_id(sk, skb);
sk_incoming_cpu_update(sk);
}
rc = __sock_queue_rcv_skb(sk, skb);
if (rc < 0) {
int is_udplite = IS_UDPLITE(sk);
if (rc == -ENOMEM)
UDP_INC_STATS(sock_net(sk), UDP_MIB_RCVBUFERRORS,
is_udplite);
UDP_INC_STATS(sock_net(sk), UDP_MIB_INERRORS, is_udplite);
kfree_skb(skb);
trace_udp_fail_queue_rcv_skb(rc, sk);
return -1;
}
return 0;
}
void udp_encap_enable(void)
{
if (!static_key_enabled(&udp_encap_needed))
static_key_slow_inc(&udp_encap_needed);
}
int udp_queue_rcv_skb(struct sock *sk, struct sk_buff *skb)
{
struct udp_sock *up = udp_sk(sk);
int rc;
int is_udplite = IS_UDPLITE(sk);
if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
goto drop;
nf_reset(skb);
if (static_key_false(&udp_encap_needed) && up->encap_type) {
int (*encap_rcv)(struct sock *sk, struct sk_buff *skb);
encap_rcv = ACCESS_ONCE(up->encap_rcv);
if (encap_rcv) {
int ret;
if (udp_lib_checksum_complete(skb))
goto csum_error;
ret = encap_rcv(sk, skb);
if (ret <= 0) {
__UDP_INC_STATS(sock_net(sk),
UDP_MIB_INDATAGRAMS,
is_udplite);
return -ret;
}
}
}
if ((is_udplite & UDPLITE_RECV_CC) && UDP_SKB_CB(skb)->partial_cov) {
if (up->pcrlen == 0) {
net_dbg_ratelimited("UDPLite: partial coverage %d while full coverage %d requested\n",
UDP_SKB_CB(skb)->cscov, skb->len);
goto drop;
}
if (UDP_SKB_CB(skb)->cscov < up->pcrlen) {
net_dbg_ratelimited("UDPLite: coverage %d too small, need min %d\n",
UDP_SKB_CB(skb)->cscov, up->pcrlen);
goto drop;
}
}
if (rcu_access_pointer(sk->sk_filter) &&
udp_lib_checksum_complete(skb))
goto csum_error;
if (sk_filter_trim_cap(sk, skb, sizeof(struct udphdr)))
goto drop;
udp_csum_pull_header(skb);
if (sk_rcvqueues_full(sk, sk->sk_rcvbuf)) {
__UDP_INC_STATS(sock_net(sk), UDP_MIB_RCVBUFERRORS,
is_udplite);
goto drop;
}
rc = 0;
ipv4_pktinfo_prepare(sk, skb);
bh_lock_sock(sk);
if (!sock_owned_by_user(sk))
rc = __udp_queue_rcv_skb(sk, skb);
else if (sk_add_backlog(sk, skb, sk->sk_rcvbuf)) {
bh_unlock_sock(sk);
goto drop;
}
bh_unlock_sock(sk);
return rc;
csum_error:
__UDP_INC_STATS(sock_net(sk), UDP_MIB_CSUMERRORS, is_udplite);
drop:
__UDP_INC_STATS(sock_net(sk), UDP_MIB_INERRORS, is_udplite);
atomic_inc(&sk->sk_drops);
kfree_skb(skb);
return -1;
}
static void udp_sk_rx_dst_set(struct sock *sk, struct dst_entry *dst)
{
struct dst_entry *old;
dst_hold(dst);
old = xchg(&sk->sk_rx_dst, dst);
dst_release(old);
}
static int __udp4_lib_mcast_deliver(struct net *net, struct sk_buff *skb,
struct udphdr *uh,
__be32 saddr, __be32 daddr,
struct udp_table *udptable,
int proto)
{
struct sock *sk, *first = NULL;
unsigned short hnum = ntohs(uh->dest);
struct udp_hslot *hslot = udp_hashslot(udptable, net, hnum);
unsigned int hash2 = 0, hash2_any = 0, use_hash2 = (hslot->count > 10);
unsigned int offset = offsetof(typeof(*sk), sk_node);
int dif = skb->dev->ifindex;
struct hlist_node *node;
struct sk_buff *nskb;
if (use_hash2) {
hash2_any = udp4_portaddr_hash(net, htonl(INADDR_ANY), hnum) &
udp_table.mask;
hash2 = udp4_portaddr_hash(net, daddr, hnum) & udp_table.mask;
start_lookup:
hslot = &udp_table.hash2[hash2];
offset = offsetof(typeof(*sk), __sk_common.skc_portaddr_node);
}
sk_for_each_entry_offset_rcu(sk, node, &hslot->head, offset) {
if (!__udp_is_mcast_sock(net, sk, uh->dest, daddr,
uh->source, saddr, dif, hnum))
continue;
if (!first) {
first = sk;
continue;
}
nskb = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!nskb)) {
atomic_inc(&sk->sk_drops);
__UDP_INC_STATS(net, UDP_MIB_RCVBUFERRORS,
IS_UDPLITE(sk));
__UDP_INC_STATS(net, UDP_MIB_INERRORS,
IS_UDPLITE(sk));
continue;
}
if (udp_queue_rcv_skb(sk, nskb) > 0)
consume_skb(nskb);
}
if (use_hash2 && hash2 != hash2_any) {
hash2 = hash2_any;
goto start_lookup;
}
if (first) {
if (udp_queue_rcv_skb(first, skb) > 0)
consume_skb(skb);
} else {
kfree_skb(skb);
__UDP_INC_STATS(net, UDP_MIB_IGNOREDMULTI,
proto == IPPROTO_UDPLITE);
}
return 0;
}
static inline int udp4_csum_init(struct sk_buff *skb, struct udphdr *uh,
int proto)
{
int err;
UDP_SKB_CB(skb)->partial_cov = 0;
UDP_SKB_CB(skb)->cscov = skb->len;
if (proto == IPPROTO_UDPLITE) {
err = udplite_checksum_init(skb, uh);
if (err)
return err;
}
return (__force int)skb_checksum_init_zero_check(skb, proto, uh->check,
inet_compute_pseudo);
}
int __udp4_lib_rcv(struct sk_buff *skb, struct udp_table *udptable,
int proto)
{
struct sock *sk;
struct udphdr *uh;
unsigned short ulen;
struct rtable *rt = skb_rtable(skb);
__be32 saddr, daddr;
struct net *net = dev_net(skb->dev);
if (!pskb_may_pull(skb, sizeof(struct udphdr)))
goto drop;
uh = udp_hdr(skb);
ulen = ntohs(uh->len);
saddr = ip_hdr(skb)->saddr;
daddr = ip_hdr(skb)->daddr;
if (ulen > skb->len)
goto short_packet;
if (proto == IPPROTO_UDP) {
if (ulen < sizeof(*uh) || pskb_trim_rcsum(skb, ulen))
goto short_packet;
uh = udp_hdr(skb);
}
if (udp4_csum_init(skb, uh, proto))
goto csum_error;
sk = skb_steal_sock(skb);
if (sk) {
struct dst_entry *dst = skb_dst(skb);
int ret;
if (unlikely(sk->sk_rx_dst != dst))
udp_sk_rx_dst_set(sk, dst);
ret = udp_queue_rcv_skb(sk, skb);
sock_put(sk);
if (ret > 0)
return -ret;
return 0;
}
if (rt->rt_flags & (RTCF_BROADCAST|RTCF_MULTICAST))
return __udp4_lib_mcast_deliver(net, skb, uh,
saddr, daddr, udptable, proto);
sk = __udp4_lib_lookup_skb(skb, uh->source, uh->dest, udptable);
if (sk) {
int ret;
if (inet_get_convert_csum(sk) && uh->check && !IS_UDPLITE(sk))
skb_checksum_try_convert(skb, IPPROTO_UDP, uh->check,
inet_compute_pseudo);
ret = udp_queue_rcv_skb(sk, skb);
if (ret > 0)
return -ret;
return 0;
}
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
goto drop;
nf_reset(skb);
if (udp_lib_checksum_complete(skb))
goto csum_error;
__UDP_INC_STATS(net, UDP_MIB_NOPORTS, proto == IPPROTO_UDPLITE);
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
short_packet:
net_dbg_ratelimited("UDP%s: short packet: From %pI4:%u %d/%d to %pI4:%u\n",
proto == IPPROTO_UDPLITE ? "Lite" : "",
&saddr, ntohs(uh->source),
ulen, skb->len,
&daddr, ntohs(uh->dest));
goto drop;
csum_error:
net_dbg_ratelimited("UDP%s: bad checksum. From %pI4:%u to %pI4:%u ulen %d\n",
proto == IPPROTO_UDPLITE ? "Lite" : "",
&saddr, ntohs(uh->source), &daddr, ntohs(uh->dest),
ulen);
__UDP_INC_STATS(net, UDP_MIB_CSUMERRORS, proto == IPPROTO_UDPLITE);
drop:
__UDP_INC_STATS(net, UDP_MIB_INERRORS, proto == IPPROTO_UDPLITE);
kfree_skb(skb);
return 0;
}
static struct sock *__udp4_lib_mcast_demux_lookup(struct net *net,
__be16 loc_port, __be32 loc_addr,
__be16 rmt_port, __be32 rmt_addr,
int dif)
{
struct sock *sk, *result;
unsigned short hnum = ntohs(loc_port);
unsigned int slot = udp_hashfn(net, hnum, udp_table.mask);
struct udp_hslot *hslot = &udp_table.hash[slot];
if (hslot->count > 10)
return NULL;
result = NULL;
sk_for_each_rcu(sk, &hslot->head) {
if (__udp_is_mcast_sock(net, sk, loc_port, loc_addr,
rmt_port, rmt_addr, dif, hnum)) {
if (result)
return NULL;
result = sk;
}
}
return result;
}
static struct sock *__udp4_lib_demux_lookup(struct net *net,
__be16 loc_port, __be32 loc_addr,
__be16 rmt_port, __be32 rmt_addr,
int dif)
{
unsigned short hnum = ntohs(loc_port);
unsigned int hash2 = udp4_portaddr_hash(net, loc_addr, hnum);
unsigned int slot2 = hash2 & udp_table.mask;
struct udp_hslot *hslot2 = &udp_table.hash2[slot2];
INET_ADDR_COOKIE(acookie, rmt_addr, loc_addr);
const __portpair ports = INET_COMBINED_PORTS(rmt_port, hnum);
struct sock *sk;
udp_portaddr_for_each_entry_rcu(sk, &hslot2->head) {
if (INET_MATCH(sk, net, acookie, rmt_addr,
loc_addr, ports, dif))
return sk;
break;
}
return NULL;
}
void udp_v4_early_demux(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
const struct iphdr *iph;
const struct udphdr *uh;
struct sock *sk = NULL;
struct dst_entry *dst;
int dif = skb->dev->ifindex;
int ours;
if (!pskb_may_pull(skb, skb_transport_offset(skb) + sizeof(struct udphdr)))
return;
iph = ip_hdr(skb);
uh = udp_hdr(skb);
if (skb->pkt_type == PACKET_BROADCAST ||
skb->pkt_type == PACKET_MULTICAST) {
struct in_device *in_dev = __in_dev_get_rcu(skb->dev);
if (!in_dev)
return;
if (skb->pkt_type == PACKET_MULTICAST) {
ours = ip_check_mc_rcu(in_dev, iph->daddr, iph->saddr,
iph->protocol);
if (!ours)
return;
}
sk = __udp4_lib_mcast_demux_lookup(net, uh->dest, iph->daddr,
uh->source, iph->saddr, dif);
} else if (skb->pkt_type == PACKET_HOST) {
sk = __udp4_lib_demux_lookup(net, uh->dest, iph->daddr,
uh->source, iph->saddr, dif);
}
if (!sk || !atomic_inc_not_zero_hint(&sk->sk_refcnt, 2))
return;
skb->sk = sk;
skb->destructor = sock_efree;
dst = READ_ONCE(sk->sk_rx_dst);
if (dst)
dst = dst_check(dst, 0);
if (dst) {
if (dst->flags & DST_NOCACHE) {
if (likely(atomic_inc_not_zero(&dst->__refcnt)))
skb_dst_set(skb, dst);
} else {
skb_dst_set_noref(skb, dst);
}
}
}
int udp_rcv(struct sk_buff *skb)
{
return __udp4_lib_rcv(skb, &udp_table, IPPROTO_UDP);
}
void udp_destroy_sock(struct sock *sk)
{
struct udp_sock *up = udp_sk(sk);
bool slow = lock_sock_fast(sk);
udp_flush_pending_frames(sk);
unlock_sock_fast(sk, slow);
if (static_key_false(&udp_encap_needed) && up->encap_type) {
void (*encap_destroy)(struct sock *sk);
encap_destroy = ACCESS_ONCE(up->encap_destroy);
if (encap_destroy)
encap_destroy(sk);
}
}
int udp_lib_setsockopt(struct sock *sk, int level, int optname,
char __user *optval, unsigned int optlen,
int (*push_pending_frames)(struct sock *))
{
struct udp_sock *up = udp_sk(sk);
int val, valbool;
int err = 0;
int is_udplite = IS_UDPLITE(sk);
if (optlen < sizeof(int))
return -EINVAL;
if (get_user(val, (int __user *)optval))
return -EFAULT;
valbool = val ? 1 : 0;
switch (optname) {
case UDP_CORK:
if (val != 0) {
up->corkflag = 1;
} else {
up->corkflag = 0;
lock_sock(sk);
push_pending_frames(sk);
release_sock(sk);
}
break;
case UDP_ENCAP:
switch (val) {
case 0:
case UDP_ENCAP_ESPINUDP:
case UDP_ENCAP_ESPINUDP_NON_IKE:
up->encap_rcv = xfrm4_udp_encap_rcv;
case UDP_ENCAP_L2TPINUDP:
up->encap_type = val;
udp_encap_enable();
break;
default:
err = -ENOPROTOOPT;
break;
}
break;
case UDP_NO_CHECK6_TX:
up->no_check6_tx = valbool;
break;
case UDP_NO_CHECK6_RX:
up->no_check6_rx = valbool;
break;
case UDPLITE_SEND_CSCOV:
if (!is_udplite)
return -ENOPROTOOPT;
if (val != 0 && val < 8)
val = 8;
else if (val > USHRT_MAX)
val = USHRT_MAX;
up->pcslen = val;
up->pcflag |= UDPLITE_SEND_CC;
break;
case UDPLITE_RECV_CSCOV:
if (!is_udplite)
return -ENOPROTOOPT;
if (val != 0 && val < 8)
val = 8;
else if (val > USHRT_MAX)
val = USHRT_MAX;
up->pcrlen = val;
up->pcflag |= UDPLITE_RECV_CC;
break;
default:
err = -ENOPROTOOPT;
break;
}
return err;
}
int udp_setsockopt(struct sock *sk, int level, int optname,
char __user *optval, unsigned int optlen)
{
if (level == SOL_UDP || level == SOL_UDPLITE)
return udp_lib_setsockopt(sk, level, optname, optval, optlen,
udp_push_pending_frames);
return ip_setsockopt(sk, level, optname, optval, optlen);
}
int compat_udp_setsockopt(struct sock *sk, int level, int optname,
char __user *optval, unsigned int optlen)
{
if (level == SOL_UDP || level == SOL_UDPLITE)
return udp_lib_setsockopt(sk, level, optname, optval, optlen,
udp_push_pending_frames);
return compat_ip_setsockopt(sk, level, optname, optval, optlen);
}
int udp_lib_getsockopt(struct sock *sk, int level, int optname,
char __user *optval, int __user *optlen)
{
struct udp_sock *up = udp_sk(sk);
int val, len;
if (get_user(len, optlen))
return -EFAULT;
len = min_t(unsigned int, len, sizeof(int));
if (len < 0)
return -EINVAL;
switch (optname) {
case UDP_CORK:
val = up->corkflag;
break;
case UDP_ENCAP:
val = up->encap_type;
break;
case UDP_NO_CHECK6_TX:
val = up->no_check6_tx;
break;
case UDP_NO_CHECK6_RX:
val = up->no_check6_rx;
break;
case UDPLITE_SEND_CSCOV:
val = up->pcslen;
break;
case UDPLITE_RECV_CSCOV:
val = up->pcrlen;
break;
default:
return -ENOPROTOOPT;
}
if (put_user(len, optlen))
return -EFAULT;
if (copy_to_user(optval, &val, len))
return -EFAULT;
return 0;
}
int udp_getsockopt(struct sock *sk, int level, int optname,
char __user *optval, int __user *optlen)
{
if (level == SOL_UDP || level == SOL_UDPLITE)
return udp_lib_getsockopt(sk, level, optname, optval, optlen);
return ip_getsockopt(sk, level, optname, optval, optlen);
}
int compat_udp_getsockopt(struct sock *sk, int level, int optname,
char __user *optval, int __user *optlen)
{
if (level == SOL_UDP || level == SOL_UDPLITE)
return udp_lib_getsockopt(sk, level, optname, optval, optlen);
return compat_ip_getsockopt(sk, level, optname, optval, optlen);
}
unsigned int udp_poll(struct file *file, struct socket *sock, poll_table *wait)
{
unsigned int mask = datagram_poll(file, sock, wait);
struct sock *sk = sock->sk;
sock_rps_record_flow(sk);
if ((mask & POLLRDNORM) && !(file->f_flags & O_NONBLOCK) &&
!(sk->sk_shutdown & RCV_SHUTDOWN) && first_packet_length(sk) == -1)
mask &= ~(POLLIN | POLLRDNORM);
return mask;
}
static struct sock *udp_get_first(struct seq_file *seq, int start)
{
struct sock *sk;
struct udp_iter_state *state = seq->private;
struct net *net = seq_file_net(seq);
for (state->bucket = start; state->bucket <= state->udp_table->mask;
++state->bucket) {
struct udp_hslot *hslot = &state->udp_table->hash[state->bucket];
if (hlist_empty(&hslot->head))
continue;
spin_lock_bh(&hslot->lock);
sk_for_each(sk, &hslot->head) {
if (!net_eq(sock_net(sk), net))
continue;
if (sk->sk_family == state->family)
goto found;
}
spin_unlock_bh(&hslot->lock);
}
sk = NULL;
found:
return sk;
}
static struct sock *udp_get_next(struct seq_file *seq, struct sock *sk)
{
struct udp_iter_state *state = seq->private;
struct net *net = seq_file_net(seq);
do {
sk = sk_next(sk);
} while (sk && (!net_eq(sock_net(sk), net) || sk->sk_family != state->family));
if (!sk) {
if (state->bucket <= state->udp_table->mask)
spin_unlock_bh(&state->udp_table->hash[state->bucket].lock);
return udp_get_first(seq, state->bucket + 1);
}
return sk;
}
static struct sock *udp_get_idx(struct seq_file *seq, loff_t pos)
{
struct sock *sk = udp_get_first(seq, 0);
if (sk)
while (pos && (sk = udp_get_next(seq, sk)) != NULL)
--pos;
return pos ? NULL : sk;
}
static void *udp_seq_start(struct seq_file *seq, loff_t *pos)
{
struct udp_iter_state *state = seq->private;
state->bucket = MAX_UDP_PORTS;
return *pos ? udp_get_idx(seq, *pos-1) : SEQ_START_TOKEN;
}
static void *udp_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct sock *sk;
if (v == SEQ_START_TOKEN)
sk = udp_get_idx(seq, 0);
else
sk = udp_get_next(seq, v);
++*pos;
return sk;
}
static void udp_seq_stop(struct seq_file *seq, void *v)
{
struct udp_iter_state *state = seq->private;
if (state->bucket <= state->udp_table->mask)
spin_unlock_bh(&state->udp_table->hash[state->bucket].lock);
}
int udp_seq_open(struct inode *inode, struct file *file)
{
struct udp_seq_afinfo *afinfo = PDE_DATA(inode);
struct udp_iter_state *s;
int err;
err = seq_open_net(inode, file, &afinfo->seq_ops,
sizeof(struct udp_iter_state));
if (err < 0)
return err;
s = ((struct seq_file *)file->private_data)->private;
s->family = afinfo->family;
s->udp_table = afinfo->udp_table;
return err;
}
int udp_proc_register(struct net *net, struct udp_seq_afinfo *afinfo)
{
struct proc_dir_entry *p;
int rc = 0;
afinfo->seq_ops.start = udp_seq_start;
afinfo->seq_ops.next = udp_seq_next;
afinfo->seq_ops.stop = udp_seq_stop;
p = proc_create_data(afinfo->name, S_IRUGO, net->proc_net,
afinfo->seq_fops, afinfo);
if (!p)
rc = -ENOMEM;
return rc;
}
void udp_proc_unregister(struct net *net, struct udp_seq_afinfo *afinfo)
{
remove_proc_entry(afinfo->name, net->proc_net);
}
static void udp4_format_sock(struct sock *sp, struct seq_file *f,
int bucket)
{
struct inet_sock *inet = inet_sk(sp);
__be32 dest = inet->inet_daddr;
__be32 src = inet->inet_rcv_saddr;
__u16 destp = ntohs(inet->inet_dport);
__u16 srcp = ntohs(inet->inet_sport);
seq_printf(f, "%5d: %08X:%04X %08X:%04X"
" %02X %08X:%08X %02X:%08lX %08X %5u %8d %lu %d %pK %d",
bucket, src, srcp, dest, destp, sp->sk_state,
sk_wmem_alloc_get(sp),
sk_rmem_alloc_get(sp),
0, 0L, 0,
from_kuid_munged(seq_user_ns(f), sock_i_uid(sp)),
0, sock_i_ino(sp),
atomic_read(&sp->sk_refcnt), sp,
atomic_read(&sp->sk_drops));
}
int udp4_seq_show(struct seq_file *seq, void *v)
{
seq_setwidth(seq, 127);
if (v == SEQ_START_TOKEN)
seq_puts(seq, " sl local_address rem_address st tx_queue "
"rx_queue tr tm->when retrnsmt uid timeout "
"inode ref pointer drops");
else {
struct udp_iter_state *state = seq->private;
udp4_format_sock(v, seq, state->bucket);
}
seq_pad(seq, '\n');
return 0;
}
static int __net_init udp4_proc_init_net(struct net *net)
{
return udp_proc_register(net, &udp4_seq_afinfo);
}
static void __net_exit udp4_proc_exit_net(struct net *net)
{
udp_proc_unregister(net, &udp4_seq_afinfo);
}
int __init udp4_proc_init(void)
{
return register_pernet_subsys(&udp4_net_ops);
}
void udp4_proc_exit(void)
{
unregister_pernet_subsys(&udp4_net_ops);
}
static int __init set_uhash_entries(char *str)
{
ssize_t ret;
if (!str)
return 0;
ret = kstrtoul(str, 0, &uhash_entries);
if (ret)
return 0;
if (uhash_entries && uhash_entries < UDP_HTABLE_SIZE_MIN)
uhash_entries = UDP_HTABLE_SIZE_MIN;
return 1;
}
void __init udp_table_init(struct udp_table *table, const char *name)
{
unsigned int i;
table->hash = alloc_large_system_hash(name,
2 * sizeof(struct udp_hslot),
uhash_entries,
21,
0,
&table->log,
&table->mask,
UDP_HTABLE_SIZE_MIN,
64 * 1024);
table->hash2 = table->hash + (table->mask + 1);
for (i = 0; i <= table->mask; i++) {
INIT_HLIST_HEAD(&table->hash[i].head);
table->hash[i].count = 0;
spin_lock_init(&table->hash[i].lock);
}
for (i = 0; i <= table->mask; i++) {
INIT_HLIST_HEAD(&table->hash2[i].head);
table->hash2[i].count = 0;
spin_lock_init(&table->hash2[i].lock);
}
}
u32 udp_flow_hashrnd(void)
{
static u32 hashrnd __read_mostly;
net_get_random_once(&hashrnd, sizeof(hashrnd));
return hashrnd;
}
void __init udp_init(void)
{
unsigned long limit;
udp_table_init(&udp_table, "UDP");
limit = nr_free_buffer_pages() / 8;
limit = max(limit, 128UL);
sysctl_udp_mem[0] = limit / 4 * 3;
sysctl_udp_mem[1] = limit;
sysctl_udp_mem[2] = sysctl_udp_mem[0] * 2;
sysctl_udp_rmem_min = SK_MEM_QUANTUM;
sysctl_udp_wmem_min = SK_MEM_QUANTUM;
}
