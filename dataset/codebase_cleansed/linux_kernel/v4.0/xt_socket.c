static int
extract_icmp4_fields(const struct sk_buff *skb,
u8 *protocol,
__be32 *raddr,
__be32 *laddr,
__be16 *rport,
__be16 *lport)
{
unsigned int outside_hdrlen = ip_hdrlen(skb);
struct iphdr *inside_iph, _inside_iph;
struct icmphdr *icmph, _icmph;
__be16 *ports, _ports[2];
icmph = skb_header_pointer(skb, outside_hdrlen,
sizeof(_icmph), &_icmph);
if (icmph == NULL)
return 1;
switch (icmph->type) {
case ICMP_DEST_UNREACH:
case ICMP_SOURCE_QUENCH:
case ICMP_REDIRECT:
case ICMP_TIME_EXCEEDED:
case ICMP_PARAMETERPROB:
break;
default:
return 1;
}
inside_iph = skb_header_pointer(skb, outside_hdrlen +
sizeof(struct icmphdr),
sizeof(_inside_iph), &_inside_iph);
if (inside_iph == NULL)
return 1;
if (inside_iph->protocol != IPPROTO_TCP &&
inside_iph->protocol != IPPROTO_UDP)
return 1;
ports = skb_header_pointer(skb, outside_hdrlen +
sizeof(struct icmphdr) +
(inside_iph->ihl << 2),
sizeof(_ports), &_ports);
if (ports == NULL)
return 1;
*protocol = inside_iph->protocol;
*laddr = inside_iph->saddr;
*lport = ports[0];
*raddr = inside_iph->daddr;
*rport = ports[1];
return 0;
}
static struct sock *
xt_socket_get_sock_v4(struct net *net, const u8 protocol,
const __be32 saddr, const __be32 daddr,
const __be16 sport, const __be16 dport,
const struct net_device *in)
{
switch (protocol) {
case IPPROTO_TCP:
return __inet_lookup(net, &tcp_hashinfo,
saddr, sport, daddr, dport,
in->ifindex);
case IPPROTO_UDP:
return udp4_lib_lookup(net, saddr, sport, daddr, dport,
in->ifindex);
}
return NULL;
}
static bool
socket_match(const struct sk_buff *skb, struct xt_action_param *par,
const struct xt_socket_mtinfo1 *info)
{
const struct iphdr *iph = ip_hdr(skb);
struct udphdr _hdr, *hp = NULL;
struct sock *sk = skb->sk;
__be32 uninitialized_var(daddr), uninitialized_var(saddr);
__be16 uninitialized_var(dport), uninitialized_var(sport);
u8 uninitialized_var(protocol);
#ifdef XT_SOCKET_HAVE_CONNTRACK
struct nf_conn const *ct;
enum ip_conntrack_info ctinfo;
#endif
if (iph->protocol == IPPROTO_UDP || iph->protocol == IPPROTO_TCP) {
hp = skb_header_pointer(skb, ip_hdrlen(skb),
sizeof(_hdr), &_hdr);
if (hp == NULL)
return false;
protocol = iph->protocol;
saddr = iph->saddr;
sport = hp->source;
daddr = iph->daddr;
dport = hp->dest;
} else if (iph->protocol == IPPROTO_ICMP) {
if (extract_icmp4_fields(skb, &protocol, &saddr, &daddr,
&sport, &dport))
return false;
} else {
return false;
}
#ifdef XT_SOCKET_HAVE_CONNTRACK
ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct) &&
((iph->protocol != IPPROTO_ICMP &&
ctinfo == IP_CT_ESTABLISHED_REPLY) ||
(iph->protocol == IPPROTO_ICMP &&
ctinfo == IP_CT_RELATED_REPLY)) &&
(ct->status & IPS_SRC_NAT_DONE)) {
daddr = ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.ip;
dport = (iph->protocol == IPPROTO_TCP) ?
ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u.tcp.port :
ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u.udp.port;
}
#endif
if (!sk)
sk = xt_socket_get_sock_v4(dev_net(skb->dev), protocol,
saddr, daddr, sport, dport,
par->in);
if (sk) {
bool wildcard;
bool transparent = true;
wildcard = (!(info->flags & XT_SOCKET_NOWILDCARD) &&
sk->sk_state != TCP_TIME_WAIT &&
inet_sk(sk)->inet_rcv_saddr == 0);
if (info->flags & XT_SOCKET_TRANSPARENT)
transparent = ((sk->sk_state != TCP_TIME_WAIT &&
inet_sk(sk)->transparent) ||
(sk->sk_state == TCP_TIME_WAIT &&
inet_twsk(sk)->tw_transparent));
if (sk != skb->sk)
sock_gen_put(sk);
if (wildcard || !transparent)
sk = NULL;
}
pr_debug("proto %hhu %pI4:%hu -> %pI4:%hu (orig %pI4:%hu) sock %p\n",
protocol, &saddr, ntohs(sport),
&daddr, ntohs(dport),
&iph->daddr, hp ? ntohs(hp->dest) : 0, sk);
return (sk != NULL);
}
static bool
socket_mt4_v0(const struct sk_buff *skb, struct xt_action_param *par)
{
static struct xt_socket_mtinfo1 xt_info_v0 = {
.flags = 0,
};
return socket_match(skb, par, &xt_info_v0);
}
static bool
socket_mt4_v1_v2(const struct sk_buff *skb, struct xt_action_param *par)
{
return socket_match(skb, par, par->matchinfo);
}
static int
extract_icmp6_fields(const struct sk_buff *skb,
unsigned int outside_hdrlen,
int *protocol,
const struct in6_addr **raddr,
const struct in6_addr **laddr,
__be16 *rport,
__be16 *lport,
struct ipv6hdr *ipv6_var)
{
const struct ipv6hdr *inside_iph;
struct icmp6hdr *icmph, _icmph;
__be16 *ports, _ports[2];
u8 inside_nexthdr;
__be16 inside_fragoff;
int inside_hdrlen;
icmph = skb_header_pointer(skb, outside_hdrlen,
sizeof(_icmph), &_icmph);
if (icmph == NULL)
return 1;
if (icmph->icmp6_type & ICMPV6_INFOMSG_MASK)
return 1;
inside_iph = skb_header_pointer(skb, outside_hdrlen + sizeof(_icmph),
sizeof(*ipv6_var), ipv6_var);
if (inside_iph == NULL)
return 1;
inside_nexthdr = inside_iph->nexthdr;
inside_hdrlen = ipv6_skip_exthdr(skb, outside_hdrlen + sizeof(_icmph) +
sizeof(*ipv6_var),
&inside_nexthdr, &inside_fragoff);
if (inside_hdrlen < 0)
return 1;
if (inside_nexthdr != IPPROTO_TCP &&
inside_nexthdr != IPPROTO_UDP)
return 1;
ports = skb_header_pointer(skb, inside_hdrlen,
sizeof(_ports), &_ports);
if (ports == NULL)
return 1;
*protocol = inside_nexthdr;
*laddr = &inside_iph->saddr;
*lport = ports[0];
*raddr = &inside_iph->daddr;
*rport = ports[1];
return 0;
}
static struct sock *
xt_socket_get_sock_v6(struct net *net, const u8 protocol,
const struct in6_addr *saddr, const struct in6_addr *daddr,
const __be16 sport, const __be16 dport,
const struct net_device *in)
{
switch (protocol) {
case IPPROTO_TCP:
return inet6_lookup(net, &tcp_hashinfo,
saddr, sport, daddr, dport,
in->ifindex);
case IPPROTO_UDP:
return udp6_lib_lookup(net, saddr, sport, daddr, dport,
in->ifindex);
}
return NULL;
}
static bool
socket_mt6_v1_v2(const struct sk_buff *skb, struct xt_action_param *par)
{
struct ipv6hdr ipv6_var, *iph = ipv6_hdr(skb);
struct udphdr _hdr, *hp = NULL;
struct sock *sk = skb->sk;
const struct in6_addr *daddr = NULL, *saddr = NULL;
__be16 uninitialized_var(dport), uninitialized_var(sport);
int thoff = 0, uninitialized_var(tproto);
const struct xt_socket_mtinfo1 *info = (struct xt_socket_mtinfo1 *) par->matchinfo;
tproto = ipv6_find_hdr(skb, &thoff, -1, NULL, NULL);
if (tproto < 0) {
pr_debug("unable to find transport header in IPv6 packet, dropping\n");
return NF_DROP;
}
if (tproto == IPPROTO_UDP || tproto == IPPROTO_TCP) {
hp = skb_header_pointer(skb, thoff,
sizeof(_hdr), &_hdr);
if (hp == NULL)
return false;
saddr = &iph->saddr;
sport = hp->source;
daddr = &iph->daddr;
dport = hp->dest;
} else if (tproto == IPPROTO_ICMPV6) {
if (extract_icmp6_fields(skb, thoff, &tproto, &saddr, &daddr,
&sport, &dport, &ipv6_var))
return false;
} else {
return false;
}
if (!sk)
sk = xt_socket_get_sock_v6(dev_net(skb->dev), tproto,
saddr, daddr, sport, dport,
par->in);
if (sk) {
bool wildcard;
bool transparent = true;
wildcard = (!(info->flags & XT_SOCKET_NOWILDCARD) &&
sk->sk_state != TCP_TIME_WAIT &&
ipv6_addr_any(&sk->sk_v6_rcv_saddr));
if (info->flags & XT_SOCKET_TRANSPARENT)
transparent = ((sk->sk_state != TCP_TIME_WAIT &&
inet_sk(sk)->transparent) ||
(sk->sk_state == TCP_TIME_WAIT &&
inet_twsk(sk)->tw_transparent));
if (sk != skb->sk)
sock_gen_put(sk);
if (wildcard || !transparent)
sk = NULL;
}
pr_debug("proto %hhd %pI6:%hu -> %pI6:%hu "
"(orig %pI6:%hu) sock %p\n",
tproto, saddr, ntohs(sport),
daddr, ntohs(dport),
&iph->daddr, hp ? ntohs(hp->dest) : 0, sk);
return (sk != NULL);
}
static int socket_mt_v1_check(const struct xt_mtchk_param *par)
{
const struct xt_socket_mtinfo1 *info = (struct xt_socket_mtinfo1 *) par->matchinfo;
if (info->flags & ~XT_SOCKET_FLAGS_V1) {
pr_info("unknown flags 0x%x\n", info->flags & ~XT_SOCKET_FLAGS_V1);
return -EINVAL;
}
return 0;
}
static int socket_mt_v2_check(const struct xt_mtchk_param *par)
{
const struct xt_socket_mtinfo2 *info = (struct xt_socket_mtinfo2 *) par->matchinfo;
if (info->flags & ~XT_SOCKET_FLAGS_V2) {
pr_info("unknown flags 0x%x\n", info->flags & ~XT_SOCKET_FLAGS_V2);
return -EINVAL;
}
return 0;
}
static int __init socket_mt_init(void)
{
nf_defrag_ipv4_enable();
#ifdef XT_SOCKET_HAVE_IPV6
nf_defrag_ipv6_enable();
#endif
return xt_register_matches(socket_mt_reg, ARRAY_SIZE(socket_mt_reg));
}
static void __exit socket_mt_exit(void)
{
xt_unregister_matches(socket_mt_reg, ARRAY_SIZE(socket_mt_reg));
}
