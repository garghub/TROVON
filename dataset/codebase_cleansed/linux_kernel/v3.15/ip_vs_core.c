const char *ip_vs_proto_name(unsigned int proto)
{
static char buf[20];
switch (proto) {
case IPPROTO_IP:
return "IP";
case IPPROTO_UDP:
return "UDP";
case IPPROTO_TCP:
return "TCP";
case IPPROTO_SCTP:
return "SCTP";
case IPPROTO_ICMP:
return "ICMP";
#ifdef CONFIG_IP_VS_IPV6
case IPPROTO_ICMPV6:
return "ICMPv6";
#endif
default:
sprintf(buf, "IP_%d", proto);
return buf;
}
}
void ip_vs_init_hash_table(struct list_head *table, int rows)
{
while (--rows >= 0)
INIT_LIST_HEAD(&table[rows]);
}
static inline void
ip_vs_in_stats(struct ip_vs_conn *cp, struct sk_buff *skb)
{
struct ip_vs_dest *dest = cp->dest;
struct netns_ipvs *ipvs = net_ipvs(skb_net(skb));
if (dest && (dest->flags & IP_VS_DEST_F_AVAILABLE)) {
struct ip_vs_cpu_stats *s;
struct ip_vs_service *svc;
s = this_cpu_ptr(dest->stats.cpustats);
s->ustats.inpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.inbytes += skb->len;
u64_stats_update_end(&s->syncp);
rcu_read_lock();
svc = rcu_dereference(dest->svc);
s = this_cpu_ptr(svc->stats.cpustats);
s->ustats.inpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.inbytes += skb->len;
u64_stats_update_end(&s->syncp);
rcu_read_unlock();
s = this_cpu_ptr(ipvs->tot_stats.cpustats);
s->ustats.inpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.inbytes += skb->len;
u64_stats_update_end(&s->syncp);
}
}
static inline void
ip_vs_out_stats(struct ip_vs_conn *cp, struct sk_buff *skb)
{
struct ip_vs_dest *dest = cp->dest;
struct netns_ipvs *ipvs = net_ipvs(skb_net(skb));
if (dest && (dest->flags & IP_VS_DEST_F_AVAILABLE)) {
struct ip_vs_cpu_stats *s;
struct ip_vs_service *svc;
s = this_cpu_ptr(dest->stats.cpustats);
s->ustats.outpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.outbytes += skb->len;
u64_stats_update_end(&s->syncp);
rcu_read_lock();
svc = rcu_dereference(dest->svc);
s = this_cpu_ptr(svc->stats.cpustats);
s->ustats.outpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.outbytes += skb->len;
u64_stats_update_end(&s->syncp);
rcu_read_unlock();
s = this_cpu_ptr(ipvs->tot_stats.cpustats);
s->ustats.outpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.outbytes += skb->len;
u64_stats_update_end(&s->syncp);
}
}
static inline void
ip_vs_conn_stats(struct ip_vs_conn *cp, struct ip_vs_service *svc)
{
struct netns_ipvs *ipvs = net_ipvs(svc->net);
struct ip_vs_cpu_stats *s;
s = this_cpu_ptr(cp->dest->stats.cpustats);
s->ustats.conns++;
s = this_cpu_ptr(svc->stats.cpustats);
s->ustats.conns++;
s = this_cpu_ptr(ipvs->tot_stats.cpustats);
s->ustats.conns++;
}
static inline void
ip_vs_set_state(struct ip_vs_conn *cp, int direction,
const struct sk_buff *skb,
struct ip_vs_proto_data *pd)
{
if (likely(pd->pp->state_transition))
pd->pp->state_transition(cp, direction, skb, pd);
}
static inline int
ip_vs_conn_fill_param_persist(const struct ip_vs_service *svc,
struct sk_buff *skb, int protocol,
const union nf_inet_addr *caddr, __be16 cport,
const union nf_inet_addr *vaddr, __be16 vport,
struct ip_vs_conn_param *p)
{
ip_vs_conn_fill_param(svc->net, svc->af, protocol, caddr, cport, vaddr,
vport, p);
p->pe = rcu_dereference(svc->pe);
if (p->pe && p->pe->fill_param)
return p->pe->fill_param(p, skb);
return 0;
}
static struct ip_vs_conn *
ip_vs_sched_persist(struct ip_vs_service *svc,
struct sk_buff *skb, __be16 src_port, __be16 dst_port,
int *ignored, struct ip_vs_iphdr *iph)
{
struct ip_vs_conn *cp = NULL;
struct ip_vs_dest *dest;
struct ip_vs_conn *ct;
__be16 dport = 0;
unsigned int flags;
struct ip_vs_conn_param param;
const union nf_inet_addr fwmark = { .ip = htonl(svc->fwmark) };
union nf_inet_addr snet;
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6)
ipv6_addr_prefix(&snet.in6, &iph->saddr.in6,
(__force __u32) svc->netmask);
else
#endif
snet.ip = iph->saddr.ip & svc->netmask;
IP_VS_DBG_BUF(6, "p-schedule: src %s:%u dest %s:%u "
"mnet %s\n",
IP_VS_DBG_ADDR(svc->af, &iph->saddr), ntohs(src_port),
IP_VS_DBG_ADDR(svc->af, &iph->daddr), ntohs(dst_port),
IP_VS_DBG_ADDR(svc->af, &snet));
{
int protocol = iph->protocol;
const union nf_inet_addr *vaddr = &iph->daddr;
__be16 vport = 0;
if (dst_port == svc->port) {
if (svc->port != FTPPORT)
vport = dst_port;
} else {
if (svc->fwmark) {
protocol = IPPROTO_IP;
vaddr = &fwmark;
}
}
if (ip_vs_conn_fill_param_persist(svc, skb, protocol, &snet, 0,
vaddr, vport, &param) < 0) {
*ignored = -1;
return NULL;
}
}
ct = ip_vs_ct_in_get(&param);
if (!ct || !ip_vs_check_template(ct)) {
struct ip_vs_scheduler *sched;
sched = rcu_dereference(svc->scheduler);
dest = sched->schedule(svc, skb, iph);
if (!dest) {
IP_VS_DBG(1, "p-schedule: no dest found.\n");
kfree(param.pe_data);
*ignored = 0;
return NULL;
}
if (dst_port == svc->port && svc->port != FTPPORT)
dport = dest->port;
ct = ip_vs_conn_new(&param, &dest->addr, dport,
IP_VS_CONN_F_TEMPLATE, dest, skb->mark);
if (ct == NULL) {
kfree(param.pe_data);
*ignored = -1;
return NULL;
}
ct->timeout = svc->timeout;
} else {
dest = ct->dest;
kfree(param.pe_data);
}
dport = dst_port;
if (dport == svc->port && dest->port)
dport = dest->port;
flags = (svc->flags & IP_VS_SVC_F_ONEPACKET
&& iph->protocol == IPPROTO_UDP) ?
IP_VS_CONN_F_ONE_PACKET : 0;
ip_vs_conn_fill_param(svc->net, svc->af, iph->protocol, &iph->saddr,
src_port, &iph->daddr, dst_port, &param);
cp = ip_vs_conn_new(&param, &dest->addr, dport, flags, dest, skb->mark);
if (cp == NULL) {
ip_vs_conn_put(ct);
*ignored = -1;
return NULL;
}
ip_vs_control_add(cp, ct);
ip_vs_conn_put(ct);
ip_vs_conn_stats(cp, svc);
return cp;
}
struct ip_vs_conn *
ip_vs_schedule(struct ip_vs_service *svc, struct sk_buff *skb,
struct ip_vs_proto_data *pd, int *ignored,
struct ip_vs_iphdr *iph)
{
struct ip_vs_protocol *pp = pd->pp;
struct ip_vs_conn *cp = NULL;
struct ip_vs_scheduler *sched;
struct ip_vs_dest *dest;
__be16 _ports[2], *pptr;
unsigned int flags;
*ignored = 1;
pptr = frag_safe_skb_hp(skb, iph->len, sizeof(_ports), _ports, iph);
if (pptr == NULL)
return NULL;
if (pptr[0] == FTPDATA) {
IP_VS_DBG_PKT(12, svc->af, pp, skb, 0,
"Not scheduling FTPDATA");
return NULL;
}
if ((!skb->dev || skb->dev->flags & IFF_LOOPBACK) &&
(cp = pp->conn_in_get(svc->af, skb, iph, 1))) {
IP_VS_DBG_PKT(12, svc->af, pp, skb, 0,
"Not scheduling reply for existing connection");
__ip_vs_conn_put(cp);
return NULL;
}
if (svc->flags & IP_VS_SVC_F_PERSISTENT)
return ip_vs_sched_persist(svc, skb, pptr[0], pptr[1], ignored,
iph);
*ignored = 0;
if (!svc->fwmark && pptr[1] != svc->port) {
if (!svc->port)
pr_err("Schedule: port zero only supported "
"in persistent services, "
"check your ipvs configuration\n");
return NULL;
}
sched = rcu_dereference(svc->scheduler);
dest = sched->schedule(svc, skb, iph);
if (dest == NULL) {
IP_VS_DBG(1, "Schedule: no dest found.\n");
return NULL;
}
flags = (svc->flags & IP_VS_SVC_F_ONEPACKET
&& iph->protocol == IPPROTO_UDP) ?
IP_VS_CONN_F_ONE_PACKET : 0;
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(svc->net, svc->af, iph->protocol,
&iph->saddr, pptr[0], &iph->daddr,
pptr[1], &p);
cp = ip_vs_conn_new(&p, &dest->addr,
dest->port ? dest->port : pptr[1],
flags, dest, skb->mark);
if (!cp) {
*ignored = -1;
return NULL;
}
}
IP_VS_DBG_BUF(6, "Schedule fwd:%c c:%s:%u v:%s:%u "
"d:%s:%u conn->flags:%X conn->refcnt:%d\n",
ip_vs_fwd_tag(cp),
IP_VS_DBG_ADDR(svc->af, &cp->caddr), ntohs(cp->cport),
IP_VS_DBG_ADDR(svc->af, &cp->vaddr), ntohs(cp->vport),
IP_VS_DBG_ADDR(svc->af, &cp->daddr), ntohs(cp->dport),
cp->flags, atomic_read(&cp->refcnt));
ip_vs_conn_stats(cp, svc);
return cp;
}
int ip_vs_leave(struct ip_vs_service *svc, struct sk_buff *skb,
struct ip_vs_proto_data *pd, struct ip_vs_iphdr *iph)
{
__be16 _ports[2], *pptr;
#ifdef CONFIG_SYSCTL
struct net *net;
struct netns_ipvs *ipvs;
int unicast;
#endif
pptr = frag_safe_skb_hp(skb, iph->len, sizeof(_ports), _ports, iph);
if (pptr == NULL) {
return NF_DROP;
}
#ifdef CONFIG_SYSCTL
net = skb_net(skb);
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6)
unicast = ipv6_addr_type(&iph->daddr.in6) & IPV6_ADDR_UNICAST;
else
#endif
unicast = (inet_addr_type(net, iph->daddr.ip) == RTN_UNICAST);
ipvs = net_ipvs(net);
if (ipvs->sysctl_cache_bypass && svc->fwmark && unicast) {
int ret;
struct ip_vs_conn *cp;
unsigned int flags = (svc->flags & IP_VS_SVC_F_ONEPACKET &&
iph->protocol == IPPROTO_UDP) ?
IP_VS_CONN_F_ONE_PACKET : 0;
union nf_inet_addr daddr = { .all = { 0, 0, 0, 0 } };
IP_VS_DBG(6, "%s(): create a cache_bypass entry\n", __func__);
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(svc->net, svc->af, iph->protocol,
&iph->saddr, pptr[0],
&iph->daddr, pptr[1], &p);
cp = ip_vs_conn_new(&p, &daddr, 0,
IP_VS_CONN_F_BYPASS | flags,
NULL, skb->mark);
if (!cp)
return NF_DROP;
}
ip_vs_in_stats(cp, skb);
ip_vs_set_state(cp, IP_VS_DIR_INPUT, skb, pd);
ret = cp->packet_xmit(skb, cp, pd->pp, iph);
atomic_inc(&cp->in_pkts);
ip_vs_conn_put(cp);
return ret;
}
#endif
if ((svc->port == FTPPORT) && (pptr[1] != FTPPORT))
return NF_ACCEPT;
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6) {
if (!skb->dev) {
struct net *net_ = dev_net(skb_dst(skb)->dev);
skb->dev = net_->loopback_dev;
}
icmpv6_send(skb, ICMPV6_DEST_UNREACH, ICMPV6_PORT_UNREACH, 0);
} else
#endif
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
return NF_DROP;
}
static int sysctl_snat_reroute(struct sk_buff *skb)
{
struct netns_ipvs *ipvs = net_ipvs(skb_net(skb));
return ipvs->sysctl_snat_reroute;
}
static int sysctl_nat_icmp_send(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
return ipvs->sysctl_nat_icmp_send;
}
static int sysctl_expire_nodest_conn(struct netns_ipvs *ipvs)
{
return ipvs->sysctl_expire_nodest_conn;
}
static int sysctl_snat_reroute(struct sk_buff *skb) { return 0; }
static int sysctl_nat_icmp_send(struct net *net) { return 0; }
static int sysctl_expire_nodest_conn(struct netns_ipvs *ipvs) { return 0; }
__sum16 ip_vs_checksum_complete(struct sk_buff *skb, int offset)
{
return csum_fold(skb_checksum(skb, offset, skb->len - offset, 0));
}
static inline enum ip_defrag_users ip_vs_defrag_user(unsigned int hooknum)
{
if (NF_INET_LOCAL_IN == hooknum)
return IP_DEFRAG_VS_IN;
if (NF_INET_FORWARD == hooknum)
return IP_DEFRAG_VS_FWD;
return IP_DEFRAG_VS_OUT;
}
static inline int ip_vs_gather_frags(struct sk_buff *skb, u_int32_t user)
{
int err;
local_bh_disable();
err = ip_defrag(skb, user);
local_bh_enable();
if (!err)
ip_send_check(ip_hdr(skb));
return err;
}
static int ip_vs_route_me_harder(int af, struct sk_buff *skb)
{
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (sysctl_snat_reroute(skb) && ip6_route_me_harder(skb) != 0)
return 1;
} else
#endif
if ((sysctl_snat_reroute(skb) ||
skb_rtable(skb)->rt_flags & RTCF_LOCAL) &&
ip_route_me_harder(skb, RTN_LOCAL) != 0)
return 1;
return 0;
}
void ip_vs_nat_icmp(struct sk_buff *skb, struct ip_vs_protocol *pp,
struct ip_vs_conn *cp, int inout)
{
struct iphdr *iph = ip_hdr(skb);
unsigned int icmp_offset = iph->ihl*4;
struct icmphdr *icmph = (struct icmphdr *)(skb_network_header(skb) +
icmp_offset);
struct iphdr *ciph = (struct iphdr *)(icmph + 1);
if (inout) {
iph->saddr = cp->vaddr.ip;
ip_send_check(iph);
ciph->daddr = cp->vaddr.ip;
ip_send_check(ciph);
} else {
iph->daddr = cp->daddr.ip;
ip_send_check(iph);
ciph->saddr = cp->daddr.ip;
ip_send_check(ciph);
}
if (IPPROTO_TCP == ciph->protocol || IPPROTO_UDP == ciph->protocol ||
IPPROTO_SCTP == ciph->protocol) {
__be16 *ports = (void *)ciph + ciph->ihl*4;
if (inout)
ports[1] = cp->vport;
else
ports[0] = cp->dport;
}
icmph->checksum = 0;
icmph->checksum = ip_vs_checksum_complete(skb, icmp_offset);
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (inout)
IP_VS_DBG_PKT(11, AF_INET, pp, skb, (void *)ciph - (void *)iph,
"Forwarding altered outgoing ICMP");
else
IP_VS_DBG_PKT(11, AF_INET, pp, skb, (void *)ciph - (void *)iph,
"Forwarding altered incoming ICMP");
}
void ip_vs_nat_icmp_v6(struct sk_buff *skb, struct ip_vs_protocol *pp,
struct ip_vs_conn *cp, int inout)
{
struct ipv6hdr *iph = ipv6_hdr(skb);
unsigned int icmp_offset = 0;
unsigned int offs = 0;
int protocol;
struct icmp6hdr *icmph;
struct ipv6hdr *ciph;
unsigned short fragoffs;
ipv6_find_hdr(skb, &icmp_offset, IPPROTO_ICMPV6, &fragoffs, NULL);
icmph = (struct icmp6hdr *)(skb_network_header(skb) + icmp_offset);
offs = icmp_offset + sizeof(struct icmp6hdr);
ciph = (struct ipv6hdr *)(skb_network_header(skb) + offs);
protocol = ipv6_find_hdr(skb, &offs, -1, &fragoffs, NULL);
if (inout) {
iph->saddr = cp->vaddr.in6;
ciph->daddr = cp->vaddr.in6;
} else {
iph->daddr = cp->daddr.in6;
ciph->saddr = cp->daddr.in6;
}
if (!fragoffs && (IPPROTO_TCP == protocol || IPPROTO_UDP == protocol ||
IPPROTO_SCTP == protocol)) {
__be16 *ports = (void *)(skb_network_header(skb) + offs);
IP_VS_DBG(11, "%s() changed port %d to %d\n", __func__,
ntohs(inout ? ports[1] : ports[0]),
ntohs(inout ? cp->vport : cp->dport));
if (inout)
ports[1] = cp->vport;
else
ports[0] = cp->dport;
}
icmph->icmp6_cksum = ~csum_ipv6_magic(&iph->saddr, &iph->daddr,
skb->len - icmp_offset,
IPPROTO_ICMPV6, 0);
skb->csum_start = skb_network_header(skb) - skb->head + icmp_offset;
skb->csum_offset = offsetof(struct icmp6hdr, icmp6_cksum);
skb->ip_summed = CHECKSUM_PARTIAL;
if (inout)
IP_VS_DBG_PKT(11, AF_INET6, pp, skb,
(void *)ciph - (void *)iph,
"Forwarding altered outgoing ICMPv6");
else
IP_VS_DBG_PKT(11, AF_INET6, pp, skb,
(void *)ciph - (void *)iph,
"Forwarding altered incoming ICMPv6");
}
static int handle_response_icmp(int af, struct sk_buff *skb,
union nf_inet_addr *snet,
__u8 protocol, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp,
unsigned int offset, unsigned int ihl)
{
unsigned int verdict = NF_DROP;
if (IP_VS_FWD_METHOD(cp) != 0) {
pr_err("shouldn't reach here, because the box is on the "
"half connection in the tun/dr module.\n");
}
if (!skb_csum_unnecessary(skb) && ip_vs_checksum_complete(skb, ihl)) {
IP_VS_DBG_BUF(1, "Forward ICMP: failed checksum from %s!\n",
IP_VS_DBG_ADDR(af, snet));
goto out;
}
if (IPPROTO_TCP == protocol || IPPROTO_UDP == protocol ||
IPPROTO_SCTP == protocol)
offset += 2 * sizeof(__u16);
if (!skb_make_writable(skb, offset))
goto out;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
ip_vs_nat_icmp_v6(skb, pp, cp, 1);
else
#endif
ip_vs_nat_icmp(skb, pp, cp, 1);
if (ip_vs_route_me_harder(af, skb))
goto out;
ip_vs_out_stats(cp, skb);
skb->ipvs_property = 1;
if (!(cp->flags & IP_VS_CONN_F_NFCT))
ip_vs_notrack(skb);
else
ip_vs_update_conntrack(skb, cp, 0);
verdict = NF_ACCEPT;
out:
__ip_vs_conn_put(cp);
return verdict;
}
static int ip_vs_out_icmp(struct sk_buff *skb, int *related,
unsigned int hooknum)
{
struct iphdr *iph;
struct icmphdr _icmph, *ic;
struct iphdr _ciph, *cih;
struct ip_vs_iphdr ciph;
struct ip_vs_conn *cp;
struct ip_vs_protocol *pp;
unsigned int offset, ihl;
union nf_inet_addr snet;
*related = 1;
if (ip_is_fragment(ip_hdr(skb))) {
if (ip_vs_gather_frags(skb, ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
}
iph = ip_hdr(skb);
offset = ihl = iph->ihl * 4;
ic = skb_header_pointer(skb, offset, sizeof(_icmph), &_icmph);
if (ic == NULL)
return NF_DROP;
IP_VS_DBG(12, "Outgoing ICMP (%d,%d) %pI4->%pI4\n",
ic->type, ntohs(icmp_id(ic)),
&iph->saddr, &iph->daddr);
if ((ic->type != ICMP_DEST_UNREACH) &&
(ic->type != ICMP_SOURCE_QUENCH) &&
(ic->type != ICMP_TIME_EXCEEDED)) {
*related = 0;
return NF_ACCEPT;
}
offset += sizeof(_icmph);
cih = skb_header_pointer(skb, offset, sizeof(_ciph), &_ciph);
if (cih == NULL)
return NF_ACCEPT;
pp = ip_vs_proto_get(cih->protocol);
if (!pp)
return NF_ACCEPT;
if (unlikely(cih->frag_off & htons(IP_OFFSET) &&
pp->dont_defrag))
return NF_ACCEPT;
IP_VS_DBG_PKT(11, AF_INET, pp, skb, offset,
"Checking outgoing ICMP for");
ip_vs_fill_ip4hdr(cih, &ciph);
ciph.len += offset;
cp = pp->conn_out_get(AF_INET, skb, &ciph, 1);
if (!cp)
return NF_ACCEPT;
snet.ip = iph->saddr;
return handle_response_icmp(AF_INET, skb, &snet, cih->protocol, cp,
pp, ciph.len, ihl);
}
static int ip_vs_out_icmp_v6(struct sk_buff *skb, int *related,
unsigned int hooknum, struct ip_vs_iphdr *ipvsh)
{
struct icmp6hdr _icmph, *ic;
struct ipv6hdr _ip6h, *ip6h;
struct ip_vs_iphdr ciph = {.flags = 0, .fragoffs = 0};
struct ip_vs_conn *cp;
struct ip_vs_protocol *pp;
union nf_inet_addr snet;
unsigned int writable;
*related = 1;
ic = frag_safe_skb_hp(skb, ipvsh->len, sizeof(_icmph), &_icmph, ipvsh);
if (ic == NULL)
return NF_DROP;
if (ic->icmp6_type & ICMPV6_INFOMSG_MASK) {
*related = 0;
return NF_ACCEPT;
}
if (ipvsh->flags & IP6_FH_F_FRAG)
return NF_DROP;
IP_VS_DBG(8, "Outgoing ICMPv6 (%d,%d) %pI6c->%pI6c\n",
ic->icmp6_type, ntohs(icmpv6_id(ic)),
&ipvsh->saddr, &ipvsh->daddr);
ciph.len = ipvsh->len + sizeof(_icmph);
ip6h = skb_header_pointer(skb, ciph.len, sizeof(_ip6h), &_ip6h);
if (ip6h == NULL)
return NF_ACCEPT;
ciph.saddr.in6 = ip6h->saddr;
ciph.daddr.in6 = ip6h->daddr;
ciph.protocol = ipv6_find_hdr(skb, &ciph.len, -1, &ciph.fragoffs, NULL);
if (ciph.protocol < 0)
return NF_ACCEPT;
pp = ip_vs_proto_get(ciph.protocol);
if (!pp)
return NF_ACCEPT;
cp = pp->conn_out_get(AF_INET6, skb, &ciph, 1);
if (!cp)
return NF_ACCEPT;
snet.in6 = ciph.saddr.in6;
writable = ciph.len;
return handle_response_icmp(AF_INET6, skb, &snet, ciph.protocol, cp,
pp, writable, sizeof(struct ipv6hdr));
}
static inline int is_sctp_abort(const struct sk_buff *skb, int nh_len)
{
sctp_chunkhdr_t *sch, schunk;
sch = skb_header_pointer(skb, nh_len + sizeof(sctp_sctphdr_t),
sizeof(schunk), &schunk);
if (sch == NULL)
return 0;
if (sch->type == SCTP_CID_ABORT)
return 1;
return 0;
}
static inline int is_tcp_reset(const struct sk_buff *skb, int nh_len)
{
struct tcphdr _tcph, *th;
th = skb_header_pointer(skb, nh_len, sizeof(_tcph), &_tcph);
if (th == NULL)
return 0;
return th->rst;
}
static inline bool is_new_conn(const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
switch (iph->protocol) {
case IPPROTO_TCP: {
struct tcphdr _tcph, *th;
th = skb_header_pointer(skb, iph->len, sizeof(_tcph), &_tcph);
if (th == NULL)
return false;
return th->syn;
}
case IPPROTO_SCTP: {
sctp_chunkhdr_t *sch, schunk;
sch = skb_header_pointer(skb, iph->len + sizeof(sctp_sctphdr_t),
sizeof(schunk), &schunk);
if (sch == NULL)
return false;
return sch->type == SCTP_CID_INIT;
}
default:
return false;
}
}
static unsigned int
handle_response(int af, struct sk_buff *skb, struct ip_vs_proto_data *pd,
struct ip_vs_conn *cp, struct ip_vs_iphdr *iph)
{
struct ip_vs_protocol *pp = pd->pp;
IP_VS_DBG_PKT(11, af, pp, skb, 0, "Outgoing packet");
if (!skb_make_writable(skb, iph->len))
goto drop;
if (pp->snat_handler && !pp->snat_handler(skb, pp, cp, iph))
goto drop;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
ipv6_hdr(skb)->saddr = cp->vaddr.in6;
else
#endif
{
ip_hdr(skb)->saddr = cp->vaddr.ip;
ip_send_check(ip_hdr(skb));
}
if (ip_vs_route_me_harder(af, skb))
goto drop;
IP_VS_DBG_PKT(10, af, pp, skb, 0, "After SNAT");
ip_vs_out_stats(cp, skb);
ip_vs_set_state(cp, IP_VS_DIR_OUTPUT, skb, pd);
skb->ipvs_property = 1;
if (!(cp->flags & IP_VS_CONN_F_NFCT))
ip_vs_notrack(skb);
else
ip_vs_update_conntrack(skb, cp, 0);
ip_vs_conn_put(cp);
LeaveFunction(11);
return NF_ACCEPT;
drop:
ip_vs_conn_put(cp);
kfree_skb(skb);
LeaveFunction(11);
return NF_STOLEN;
}
static unsigned int
ip_vs_out(unsigned int hooknum, struct sk_buff *skb, int af)
{
struct net *net = NULL;
struct ip_vs_iphdr iph;
struct ip_vs_protocol *pp;
struct ip_vs_proto_data *pd;
struct ip_vs_conn *cp;
EnterFunction(11);
if (skb->ipvs_property)
return NF_ACCEPT;
if (unlikely(skb->sk != NULL && hooknum == NF_INET_LOCAL_OUT &&
af == AF_INET)) {
struct sock *sk = skb->sk;
struct inet_sock *inet = inet_sk(skb->sk);
if (inet && sk->sk_family == PF_INET && inet->nodefrag)
return NF_ACCEPT;
}
if (unlikely(!skb_dst(skb)))
return NF_ACCEPT;
net = skb_net(skb);
if (!net_ipvs(net)->enable)
return NF_ACCEPT;
ip_vs_fill_iph_skb(af, skb, &iph);
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (unlikely(iph.protocol == IPPROTO_ICMPV6)) {
int related;
int verdict = ip_vs_out_icmp_v6(skb, &related,
hooknum, &iph);
if (related)
return verdict;
}
} else
#endif
if (unlikely(iph.protocol == IPPROTO_ICMP)) {
int related;
int verdict = ip_vs_out_icmp(skb, &related, hooknum);
if (related)
return verdict;
}
pd = ip_vs_proto_data_get(net, iph.protocol);
if (unlikely(!pd))
return NF_ACCEPT;
pp = pd->pp;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET)
#endif
if (unlikely(ip_is_fragment(ip_hdr(skb)) && !pp->dont_defrag)) {
if (ip_vs_gather_frags(skb,
ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
ip_vs_fill_ip4hdr(skb_network_header(skb), &iph);
}
cp = pp->conn_out_get(af, skb, &iph, 0);
if (likely(cp))
return handle_response(af, skb, pd, cp, &iph);
if (sysctl_nat_icmp_send(net) &&
(pp->protocol == IPPROTO_TCP ||
pp->protocol == IPPROTO_UDP ||
pp->protocol == IPPROTO_SCTP)) {
__be16 _ports[2], *pptr;
pptr = frag_safe_skb_hp(skb, iph.len,
sizeof(_ports), _ports, &iph);
if (pptr == NULL)
return NF_ACCEPT;
if (ip_vs_has_real_service(net, af, iph.protocol, &iph.saddr,
pptr[0])) {
if ((iph.protocol != IPPROTO_TCP &&
iph.protocol != IPPROTO_SCTP)
|| ((iph.protocol == IPPROTO_TCP
&& !is_tcp_reset(skb, iph.len))
|| (iph.protocol == IPPROTO_SCTP
&& !is_sctp_abort(skb,
iph.len)))) {
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (!skb->dev)
skb->dev = net->loopback_dev;
icmpv6_send(skb,
ICMPV6_DEST_UNREACH,
ICMPV6_PORT_UNREACH,
0);
} else
#endif
icmp_send(skb,
ICMP_DEST_UNREACH,
ICMP_PORT_UNREACH, 0);
return NF_DROP;
}
}
}
IP_VS_DBG_PKT(12, af, pp, skb, 0,
"ip_vs_out: packet continues traversal as normal");
return NF_ACCEPT;
}
static unsigned int
ip_vs_reply4(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_out(ops->hooknum, skb, AF_INET);
}
static unsigned int
ip_vs_local_reply4(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_out(ops->hooknum, skb, AF_INET);
}
static unsigned int
ip_vs_reply6(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_out(ops->hooknum, skb, AF_INET6);
}
static unsigned int
ip_vs_local_reply6(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_out(ops->hooknum, skb, AF_INET6);
}
static int
ip_vs_in_icmp(struct sk_buff *skb, int *related, unsigned int hooknum)
{
struct net *net = NULL;
struct iphdr *iph;
struct icmphdr _icmph, *ic;
struct iphdr _ciph, *cih;
struct ip_vs_iphdr ciph;
struct ip_vs_conn *cp;
struct ip_vs_protocol *pp;
struct ip_vs_proto_data *pd;
unsigned int offset, offset2, ihl, verdict;
bool ipip;
*related = 1;
if (ip_is_fragment(ip_hdr(skb))) {
if (ip_vs_gather_frags(skb, ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
}
iph = ip_hdr(skb);
offset = ihl = iph->ihl * 4;
ic = skb_header_pointer(skb, offset, sizeof(_icmph), &_icmph);
if (ic == NULL)
return NF_DROP;
IP_VS_DBG(12, "Incoming ICMP (%d,%d) %pI4->%pI4\n",
ic->type, ntohs(icmp_id(ic)),
&iph->saddr, &iph->daddr);
if ((ic->type != ICMP_DEST_UNREACH) &&
(ic->type != ICMP_SOURCE_QUENCH) &&
(ic->type != ICMP_TIME_EXCEEDED)) {
*related = 0;
return NF_ACCEPT;
}
offset += sizeof(_icmph);
cih = skb_header_pointer(skb, offset, sizeof(_ciph), &_ciph);
if (cih == NULL)
return NF_ACCEPT;
net = skb_net(skb);
ipip = false;
if (cih->protocol == IPPROTO_IPIP) {
if (unlikely(cih->frag_off & htons(IP_OFFSET)))
return NF_ACCEPT;
if (!(skb_rtable(skb)->rt_flags & RTCF_LOCAL))
return NF_ACCEPT;
offset += cih->ihl * 4;
cih = skb_header_pointer(skb, offset, sizeof(_ciph), &_ciph);
if (cih == NULL)
return NF_ACCEPT;
ipip = true;
}
pd = ip_vs_proto_data_get(net, cih->protocol);
if (!pd)
return NF_ACCEPT;
pp = pd->pp;
if (unlikely(cih->frag_off & htons(IP_OFFSET) &&
pp->dont_defrag))
return NF_ACCEPT;
IP_VS_DBG_PKT(11, AF_INET, pp, skb, offset,
"Checking incoming ICMP for");
offset2 = offset;
ip_vs_fill_ip4hdr(cih, &ciph);
ciph.len += offset;
offset = ciph.len;
cp = pp->conn_in_get(AF_INET, skb, &ciph, ipip ? 0 : 1);
if (!cp)
return NF_ACCEPT;
verdict = NF_DROP;
if (!skb_csum_unnecessary(skb) && ip_vs_checksum_complete(skb, ihl)) {
IP_VS_DBG(1, "Incoming ICMP: failed checksum from %pI4!\n",
&iph->saddr);
goto out;
}
if (ipip) {
__be32 info = ic->un.gateway;
__u8 type = ic->type;
__u8 code = ic->code;
if (ic->type == ICMP_DEST_UNREACH &&
ic->code == ICMP_FRAG_NEEDED) {
struct ip_vs_dest *dest = cp->dest;
u32 mtu = ntohs(ic->un.frag.mtu);
__be16 frag_off = cih->frag_off;
if (pskb_pull(skb, ihl + sizeof(_icmph)) == NULL)
goto ignore_ipip;
offset2 -= ihl + sizeof(_icmph);
skb_reset_network_header(skb);
IP_VS_DBG(12, "ICMP for IPIP %pI4->%pI4: mtu=%u\n",
&ip_hdr(skb)->saddr, &ip_hdr(skb)->daddr, mtu);
ipv4_update_pmtu(skb, dev_net(skb->dev),
mtu, 0, 0, 0, 0);
if (!(frag_off & htons(IP_DF)))
goto ignore_ipip;
if (dest) {
struct ip_vs_dest_dst *dest_dst;
rcu_read_lock();
dest_dst = rcu_dereference(dest->dest_dst);
if (dest_dst)
mtu = dst_mtu(dest_dst->dst_cache);
rcu_read_unlock();
}
if (mtu > 68 + sizeof(struct iphdr))
mtu -= sizeof(struct iphdr);
info = htonl(mtu);
}
if (pskb_pull(skb, offset2) == NULL)
goto ignore_ipip;
skb_reset_network_header(skb);
IP_VS_DBG(12, "Sending ICMP for %pI4->%pI4: t=%u, c=%u, i=%u\n",
&ip_hdr(skb)->saddr, &ip_hdr(skb)->daddr,
type, code, ntohl(info));
icmp_send(skb, type, code, info);
ip_vs_out_stats(cp, skb);
ignore_ipip:
consume_skb(skb);
verdict = NF_STOLEN;
goto out;
}
ip_vs_in_stats(cp, skb);
if (IPPROTO_TCP == cih->protocol || IPPROTO_UDP == cih->protocol ||
IPPROTO_SCTP == cih->protocol)
offset += 2 * sizeof(__u16);
verdict = ip_vs_icmp_xmit(skb, cp, pp, offset, hooknum, &ciph);
out:
__ip_vs_conn_put(cp);
return verdict;
}
static int ip_vs_in_icmp_v6(struct sk_buff *skb, int *related,
unsigned int hooknum, struct ip_vs_iphdr *iph)
{
struct net *net = NULL;
struct ipv6hdr _ip6h, *ip6h;
struct icmp6hdr _icmph, *ic;
struct ip_vs_iphdr ciph = {.flags = 0, .fragoffs = 0};
struct ip_vs_conn *cp;
struct ip_vs_protocol *pp;
struct ip_vs_proto_data *pd;
unsigned int offs_ciph, writable, verdict;
*related = 1;
ic = frag_safe_skb_hp(skb, iph->len, sizeof(_icmph), &_icmph, iph);
if (ic == NULL)
return NF_DROP;
if (ic->icmp6_type & ICMPV6_INFOMSG_MASK) {
*related = 0;
return NF_ACCEPT;
}
if (iph->flags & IP6_FH_F_FRAG)
return NF_DROP;
IP_VS_DBG(8, "Incoming ICMPv6 (%d,%d) %pI6c->%pI6c\n",
ic->icmp6_type, ntohs(icmpv6_id(ic)),
&iph->saddr, &iph->daddr);
ciph.len = iph->len + sizeof(_icmph);
offs_ciph = ciph.len;
ip6h = skb_header_pointer(skb, ciph.len, sizeof(_ip6h), &_ip6h);
if (ip6h == NULL)
return NF_ACCEPT;
ciph.saddr.in6 = ip6h->saddr;
ciph.daddr.in6 = ip6h->daddr;
ciph.protocol = ipv6_find_hdr(skb, &ciph.len, -1, &ciph.fragoffs, NULL);
if (ciph.protocol < 0)
return NF_ACCEPT;
net = skb_net(skb);
pd = ip_vs_proto_data_get(net, ciph.protocol);
if (!pd)
return NF_ACCEPT;
pp = pd->pp;
if (ciph.fragoffs)
return NF_ACCEPT;
IP_VS_DBG_PKT(11, AF_INET6, pp, skb, offs_ciph,
"Checking incoming ICMPv6 for");
cp = pp->conn_in_get(AF_INET6, skb, &ciph,
(hooknum == NF_INET_LOCAL_OUT) ? 0 : 1);
if (!cp)
return NF_ACCEPT;
if ((hooknum == NF_INET_LOCAL_OUT) &&
(IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ)) {
__ip_vs_conn_put(cp);
return NF_ACCEPT;
}
ip_vs_in_stats(cp, skb);
writable = ciph.len;
if (IPPROTO_TCP == ciph.protocol || IPPROTO_UDP == ciph.protocol ||
IPPROTO_SCTP == ciph.protocol)
writable += 2 * sizeof(__u16);
verdict = ip_vs_icmp_xmit_v6(skb, cp, pp, writable, hooknum, &ciph);
__ip_vs_conn_put(cp);
return verdict;
}
static unsigned int
ip_vs_in(unsigned int hooknum, struct sk_buff *skb, int af)
{
struct net *net;
struct ip_vs_iphdr iph;
struct ip_vs_protocol *pp;
struct ip_vs_proto_data *pd;
struct ip_vs_conn *cp;
int ret, pkts;
struct netns_ipvs *ipvs;
if (skb->ipvs_property)
return NF_ACCEPT;
if (unlikely((skb->pkt_type != PACKET_HOST &&
hooknum != NF_INET_LOCAL_OUT) ||
!skb_dst(skb))) {
ip_vs_fill_iph_skb(af, skb, &iph);
IP_VS_DBG_BUF(12, "packet type=%d proto=%d daddr=%s"
" ignored in hook %u\n",
skb->pkt_type, iph.protocol,
IP_VS_DBG_ADDR(af, &iph.daddr), hooknum);
return NF_ACCEPT;
}
net = skb_net(skb);
ipvs = net_ipvs(net);
if (unlikely(sysctl_backup_only(ipvs) || !ipvs->enable))
return NF_ACCEPT;
ip_vs_fill_iph_skb(af, skb, &iph);
if (unlikely(skb->sk != NULL && hooknum == NF_INET_LOCAL_OUT &&
af == AF_INET)) {
struct sock *sk = skb->sk;
struct inet_sock *inet = inet_sk(skb->sk);
if (inet && sk->sk_family == PF_INET && inet->nodefrag)
return NF_ACCEPT;
}
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (unlikely(iph.protocol == IPPROTO_ICMPV6)) {
int related;
int verdict = ip_vs_in_icmp_v6(skb, &related, hooknum,
&iph);
if (related)
return verdict;
}
} else
#endif
if (unlikely(iph.protocol == IPPROTO_ICMP)) {
int related;
int verdict = ip_vs_in_icmp(skb, &related, hooknum);
if (related)
return verdict;
}
pd = ip_vs_proto_data_get(net, iph.protocol);
if (unlikely(!pd))
return NF_ACCEPT;
pp = pd->pp;
cp = pp->conn_in_get(af, skb, &iph, 0);
if (unlikely(sysctl_expire_nodest_conn(ipvs)) && cp && cp->dest &&
unlikely(!atomic_read(&cp->dest->weight)) && !iph.fragoffs &&
is_new_conn(skb, &iph)) {
ip_vs_conn_expire_now(cp);
__ip_vs_conn_put(cp);
cp = NULL;
}
if (unlikely(!cp) && !iph.fragoffs) {
int v;
if (!pp->conn_schedule(af, skb, pd, &v, &cp, &iph))
return v;
}
if (unlikely(!cp)) {
IP_VS_DBG_PKT(12, af, pp, skb, 0,
"ip_vs_in: packet continues traversal as normal");
if (iph.fragoffs) {
IP_VS_DBG_RL("Unhandled frag, load nf_defrag_ipv6\n");
IP_VS_DBG_PKT(7, af, pp, skb, 0, "unhandled fragment");
}
return NF_ACCEPT;
}
IP_VS_DBG_PKT(11, af, pp, skb, 0, "Incoming packet");
if (cp->dest && !(cp->dest->flags & IP_VS_DEST_F_AVAILABLE)) {
if (sysctl_expire_nodest_conn(ipvs)) {
ip_vs_conn_expire_now(cp);
}
__ip_vs_conn_put(cp);
return NF_DROP;
}
ip_vs_in_stats(cp, skb);
ip_vs_set_state(cp, IP_VS_DIR_INPUT, skb, pd);
if (cp->packet_xmit)
ret = cp->packet_xmit(skb, cp, pp, &iph);
else {
IP_VS_DBG_RL("warning: packet_xmit is null");
ret = NF_ACCEPT;
}
if (cp->flags & IP_VS_CONN_F_ONE_PACKET)
pkts = sysctl_sync_threshold(ipvs);
else
pkts = atomic_add_return(1, &cp->in_pkts);
if (ipvs->sync_state & IP_VS_STATE_MASTER)
ip_vs_sync_conn(net, cp, pkts);
ip_vs_conn_put(cp);
return ret;
}
static unsigned int
ip_vs_remote_request4(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_in(ops->hooknum, skb, AF_INET);
}
static unsigned int
ip_vs_local_request4(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_in(ops->hooknum, skb, AF_INET);
}
static unsigned int
ip_vs_remote_request6(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_in(ops->hooknum, skb, AF_INET6);
}
static unsigned int
ip_vs_local_request6(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_in(ops->hooknum, skb, AF_INET6);
}
static unsigned int
ip_vs_forward_icmp(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
int r;
struct net *net;
struct netns_ipvs *ipvs;
if (ip_hdr(skb)->protocol != IPPROTO_ICMP)
return NF_ACCEPT;
net = skb_net(skb);
ipvs = net_ipvs(net);
if (unlikely(sysctl_backup_only(ipvs) || !ipvs->enable))
return NF_ACCEPT;
return ip_vs_in_icmp(skb, &r, ops->hooknum);
}
static unsigned int
ip_vs_forward_icmp_v6(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
int r;
struct net *net;
struct netns_ipvs *ipvs;
struct ip_vs_iphdr iphdr;
ip_vs_fill_iph_skb(AF_INET6, skb, &iphdr);
if (iphdr.protocol != IPPROTO_ICMPV6)
return NF_ACCEPT;
net = skb_net(skb);
ipvs = net_ipvs(net);
if (unlikely(sysctl_backup_only(ipvs) || !ipvs->enable))
return NF_ACCEPT;
return ip_vs_in_icmp_v6(skb, &r, ops->hooknum, &iphdr);
}
static int __net_init __ip_vs_init(struct net *net)
{
struct netns_ipvs *ipvs;
ipvs = net_generic(net, ip_vs_net_id);
if (ipvs == NULL)
return -ENOMEM;
ipvs->enable = 0;
ipvs->net = net;
ipvs->gen = atomic_read(&ipvs_netns_cnt);
atomic_inc(&ipvs_netns_cnt);
net->ipvs = ipvs;
if (ip_vs_estimator_net_init(net) < 0)
goto estimator_fail;
if (ip_vs_control_net_init(net) < 0)
goto control_fail;
if (ip_vs_protocol_net_init(net) < 0)
goto protocol_fail;
if (ip_vs_app_net_init(net) < 0)
goto app_fail;
if (ip_vs_conn_net_init(net) < 0)
goto conn_fail;
if (ip_vs_sync_net_init(net) < 0)
goto sync_fail;
printk(KERN_INFO "IPVS: Creating netns size=%zu id=%d\n",
sizeof(struct netns_ipvs), ipvs->gen);
return 0;
sync_fail:
ip_vs_conn_net_cleanup(net);
conn_fail:
ip_vs_app_net_cleanup(net);
app_fail:
ip_vs_protocol_net_cleanup(net);
protocol_fail:
ip_vs_control_net_cleanup(net);
control_fail:
ip_vs_estimator_net_cleanup(net);
estimator_fail:
net->ipvs = NULL;
return -ENOMEM;
}
static void __net_exit __ip_vs_cleanup(struct net *net)
{
ip_vs_service_net_cleanup(net);
ip_vs_conn_net_cleanup(net);
ip_vs_app_net_cleanup(net);
ip_vs_protocol_net_cleanup(net);
ip_vs_control_net_cleanup(net);
ip_vs_estimator_net_cleanup(net);
IP_VS_DBG(2, "ipvs netns %d released\n", net_ipvs(net)->gen);
net->ipvs = NULL;
}
static void __net_exit __ip_vs_dev_cleanup(struct net *net)
{
EnterFunction(2);
net_ipvs(net)->enable = 0;
smp_wmb();
ip_vs_sync_net_cleanup(net);
LeaveFunction(2);
}
static int __init ip_vs_init(void)
{
int ret;
ret = ip_vs_control_init();
if (ret < 0) {
pr_err("can't setup control.\n");
goto exit;
}
ip_vs_protocol_init();
ret = ip_vs_conn_init();
if (ret < 0) {
pr_err("can't setup connection table.\n");
goto cleanup_protocol;
}
ret = register_pernet_subsys(&ipvs_core_ops);
if (ret < 0)
goto cleanup_conn;
ret = register_pernet_device(&ipvs_core_dev_ops);
if (ret < 0)
goto cleanup_sub;
ret = nf_register_hooks(ip_vs_ops, ARRAY_SIZE(ip_vs_ops));
if (ret < 0) {
pr_err("can't register hooks.\n");
goto cleanup_dev;
}
ret = ip_vs_register_nl_ioctl();
if (ret < 0) {
pr_err("can't register netlink/ioctl.\n");
goto cleanup_hooks;
}
pr_info("ipvs loaded.\n");
return ret;
cleanup_hooks:
nf_unregister_hooks(ip_vs_ops, ARRAY_SIZE(ip_vs_ops));
cleanup_dev:
unregister_pernet_device(&ipvs_core_dev_ops);
cleanup_sub:
unregister_pernet_subsys(&ipvs_core_ops);
cleanup_conn:
ip_vs_conn_cleanup();
cleanup_protocol:
ip_vs_protocol_cleanup();
ip_vs_control_cleanup();
exit:
return ret;
}
static void __exit ip_vs_cleanup(void)
{
ip_vs_unregister_nl_ioctl();
nf_unregister_hooks(ip_vs_ops, ARRAY_SIZE(ip_vs_ops));
unregister_pernet_device(&ipvs_core_dev_ops);
unregister_pernet_subsys(&ipvs_core_ops);
ip_vs_conn_cleanup();
ip_vs_protocol_cleanup();
ip_vs_control_cleanup();
pr_info("ipvs unloaded.\n");
}
