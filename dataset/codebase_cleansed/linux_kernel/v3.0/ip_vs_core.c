const char *ip_vs_proto_name(unsigned proto)
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
s = this_cpu_ptr(dest->stats.cpustats);
s->ustats.inpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.inbytes += skb->len;
u64_stats_update_end(&s->syncp);
s = this_cpu_ptr(dest->svc->stats.cpustats);
s->ustats.inpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.inbytes += skb->len;
u64_stats_update_end(&s->syncp);
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
s = this_cpu_ptr(dest->stats.cpustats);
s->ustats.outpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.outbytes += skb->len;
u64_stats_update_end(&s->syncp);
s = this_cpu_ptr(dest->svc->stats.cpustats);
s->ustats.outpkts++;
u64_stats_update_begin(&s->syncp);
s->ustats.outbytes += skb->len;
u64_stats_update_end(&s->syncp);
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
static inline int
ip_vs_set_state(struct ip_vs_conn *cp, int direction,
const struct sk_buff *skb,
struct ip_vs_proto_data *pd)
{
if (unlikely(!pd->pp->state_transition))
return 0;
return pd->pp->state_transition(cp, direction, skb, pd);
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
p->pe = svc->pe;
if (p->pe && p->pe->fill_param)
return p->pe->fill_param(p, skb);
return 0;
}
static struct ip_vs_conn *
ip_vs_sched_persist(struct ip_vs_service *svc,
struct sk_buff *skb,
__be16 src_port, __be16 dst_port, int *ignored)
{
struct ip_vs_conn *cp = NULL;
struct ip_vs_iphdr iph;
struct ip_vs_dest *dest;
struct ip_vs_conn *ct;
__be16 dport = 0;
unsigned int flags;
struct ip_vs_conn_param param;
union nf_inet_addr snet;
ip_vs_fill_iphdr(svc->af, skb_network_header(skb), &iph);
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6)
ipv6_addr_prefix(&snet.in6, &iph.saddr.in6, svc->netmask);
else
#endif
snet.ip = iph.saddr.ip & svc->netmask;
IP_VS_DBG_BUF(6, "p-schedule: src %s:%u dest %s:%u "
"mnet %s\n",
IP_VS_DBG_ADDR(svc->af, &iph.saddr), ntohs(src_port),
IP_VS_DBG_ADDR(svc->af, &iph.daddr), ntohs(dst_port),
IP_VS_DBG_ADDR(svc->af, &snet));
{
int protocol = iph.protocol;
const union nf_inet_addr *vaddr = &iph.daddr;
const union nf_inet_addr fwmark = { .ip = htonl(svc->fwmark) };
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
dest = svc->scheduler->schedule(svc, skb);
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
&& iph.protocol == IPPROTO_UDP)?
IP_VS_CONN_F_ONE_PACKET : 0;
ip_vs_conn_fill_param(svc->net, svc->af, iph.protocol, &iph.saddr,
src_port, &iph.daddr, dst_port, &param);
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
struct ip_vs_proto_data *pd, int *ignored)
{
struct ip_vs_protocol *pp = pd->pp;
struct ip_vs_conn *cp = NULL;
struct ip_vs_iphdr iph;
struct ip_vs_dest *dest;
__be16 _ports[2], *pptr;
unsigned int flags;
*ignored = 1;
ip_vs_fill_iphdr(svc->af, skb_network_header(skb), &iph);
pptr = skb_header_pointer(skb, iph.len, sizeof(_ports), _ports);
if (pptr == NULL)
return NULL;
if (pptr[0] == FTPDATA) {
IP_VS_DBG_PKT(12, svc->af, pp, skb, 0,
"Not scheduling FTPDATA");
return NULL;
}
if ((!skb->dev || skb->dev->flags & IFF_LOOPBACK) &&
(cp = pp->conn_in_get(svc->af, skb, &iph, iph.len, 1))) {
IP_VS_DBG_PKT(12, svc->af, pp, skb, 0,
"Not scheduling reply for existing connection");
__ip_vs_conn_put(cp);
return NULL;
}
if (svc->flags & IP_VS_SVC_F_PERSISTENT)
return ip_vs_sched_persist(svc, skb, pptr[0], pptr[1], ignored);
*ignored = 0;
if (!svc->fwmark && pptr[1] != svc->port) {
if (!svc->port)
pr_err("Schedule: port zero only supported "
"in persistent services, "
"check your ipvs configuration\n");
return NULL;
}
dest = svc->scheduler->schedule(svc, skb);
if (dest == NULL) {
IP_VS_DBG(1, "Schedule: no dest found.\n");
return NULL;
}
flags = (svc->flags & IP_VS_SVC_F_ONEPACKET
&& iph.protocol == IPPROTO_UDP)?
IP_VS_CONN_F_ONE_PACKET : 0;
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(svc->net, svc->af, iph.protocol,
&iph.saddr, pptr[0], &iph.daddr, pptr[1],
&p);
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
struct ip_vs_proto_data *pd)
{
__be16 _ports[2], *pptr;
struct ip_vs_iphdr iph;
#ifdef CONFIG_SYSCTL
struct net *net;
struct netns_ipvs *ipvs;
int unicast;
#endif
ip_vs_fill_iphdr(svc->af, skb_network_header(skb), &iph);
pptr = skb_header_pointer(skb, iph.len, sizeof(_ports), _ports);
if (pptr == NULL) {
ip_vs_service_put(svc);
return NF_DROP;
}
#ifdef CONFIG_SYSCTL
net = skb_net(skb);
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6)
unicast = ipv6_addr_type(&iph.daddr.in6) & IPV6_ADDR_UNICAST;
else
#endif
unicast = (inet_addr_type(net, iph.daddr.ip) == RTN_UNICAST);
ipvs = net_ipvs(net);
if (ipvs->sysctl_cache_bypass && svc->fwmark && unicast) {
int ret, cs;
struct ip_vs_conn *cp;
unsigned int flags = (svc->flags & IP_VS_SVC_F_ONEPACKET &&
iph.protocol == IPPROTO_UDP)?
IP_VS_CONN_F_ONE_PACKET : 0;
union nf_inet_addr daddr = { .all = { 0, 0, 0, 0 } };
ip_vs_service_put(svc);
IP_VS_DBG(6, "%s(): create a cache_bypass entry\n", __func__);
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(svc->net, svc->af, iph.protocol,
&iph.saddr, pptr[0],
&iph.daddr, pptr[1], &p);
cp = ip_vs_conn_new(&p, &daddr, 0,
IP_VS_CONN_F_BYPASS | flags,
NULL, skb->mark);
if (!cp)
return NF_DROP;
}
ip_vs_in_stats(cp, skb);
cs = ip_vs_set_state(cp, IP_VS_DIR_INPUT, skb, pd);
ret = cp->packet_xmit(skb, cp, pd->pp);
atomic_inc(&cp->in_pkts);
ip_vs_conn_put(cp);
return ret;
}
#endif
if ((svc->port == FTPPORT) && (pptr[1] != FTPPORT)) {
ip_vs_service_put(svc);
return NF_ACCEPT;
}
ip_vs_service_put(svc);
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6) {
if (!skb->dev) {
struct net *net = dev_net(skb_dst(skb)->dev);
skb->dev = net->loopback_dev;
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
int err = ip_defrag(skb, user);
if (!err)
ip_send_check(ip_hdr(skb));
return err;
}
static inline int ip_vs_gather_frags_v6(struct sk_buff *skb, u_int32_t user)
{
return 0;
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
unsigned int icmp_offset = sizeof(struct ipv6hdr);
struct icmp6hdr *icmph = (struct icmp6hdr *)(skb_network_header(skb) +
icmp_offset);
struct ipv6hdr *ciph = (struct ipv6hdr *)(icmph + 1);
if (inout) {
iph->saddr = cp->vaddr.in6;
ciph->daddr = cp->vaddr.in6;
} else {
iph->daddr = cp->daddr.in6;
ciph->saddr = cp->daddr.in6;
}
if (IPPROTO_TCP == ciph->nexthdr || IPPROTO_UDP == ciph->nexthdr ||
IPPROTO_SCTP == ciph->nexthdr) {
__be16 *ports = (void *)ciph + sizeof(struct ipv6hdr);
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
if (ip_hdr(skb)->frag_off & htons(IP_MF | IP_OFFSET)) {
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
offset += cih->ihl * 4;
ip_vs_fill_iphdr(AF_INET, cih, &ciph);
cp = pp->conn_out_get(AF_INET, skb, &ciph, offset, 1);
if (!cp)
return NF_ACCEPT;
snet.ip = iph->saddr;
return handle_response_icmp(AF_INET, skb, &snet, cih->protocol, cp,
pp, offset, ihl);
}
static int ip_vs_out_icmp_v6(struct sk_buff *skb, int *related,
unsigned int hooknum)
{
struct ipv6hdr *iph;
struct icmp6hdr _icmph, *ic;
struct ipv6hdr _ciph, *cih;
struct ip_vs_iphdr ciph;
struct ip_vs_conn *cp;
struct ip_vs_protocol *pp;
unsigned int offset;
union nf_inet_addr snet;
*related = 1;
if (ipv6_hdr(skb)->nexthdr == IPPROTO_FRAGMENT) {
if (ip_vs_gather_frags_v6(skb, ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
}
iph = ipv6_hdr(skb);
offset = sizeof(struct ipv6hdr);
ic = skb_header_pointer(skb, offset, sizeof(_icmph), &_icmph);
if (ic == NULL)
return NF_DROP;
IP_VS_DBG(12, "Outgoing ICMPv6 (%d,%d) %pI6->%pI6\n",
ic->icmp6_type, ntohs(icmpv6_id(ic)),
&iph->saddr, &iph->daddr);
if ((ic->icmp6_type != ICMPV6_DEST_UNREACH) &&
(ic->icmp6_type != ICMPV6_PKT_TOOBIG) &&
(ic->icmp6_type != ICMPV6_TIME_EXCEED)) {
*related = 0;
return NF_ACCEPT;
}
offset += sizeof(_icmph);
cih = skb_header_pointer(skb, offset, sizeof(_ciph), &_ciph);
if (cih == NULL)
return NF_ACCEPT;
pp = ip_vs_proto_get(cih->nexthdr);
if (!pp)
return NF_ACCEPT;
if (unlikely(cih->nexthdr == IPPROTO_FRAGMENT && pp->dont_defrag))
return NF_ACCEPT;
IP_VS_DBG_PKT(11, AF_INET6, pp, skb, offset,
"Checking outgoing ICMPv6 for");
offset += sizeof(struct ipv6hdr);
ip_vs_fill_iphdr(AF_INET6, cih, &ciph);
cp = pp->conn_out_get(AF_INET6, skb, &ciph, offset, 1);
if (!cp)
return NF_ACCEPT;
ipv6_addr_copy(&snet.in6, &iph->saddr);
return handle_response_icmp(AF_INET6, skb, &snet, cih->nexthdr, cp,
pp, offset, sizeof(struct ipv6hdr));
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
static unsigned int
handle_response(int af, struct sk_buff *skb, struct ip_vs_proto_data *pd,
struct ip_vs_conn *cp, int ihl)
{
struct ip_vs_protocol *pp = pd->pp;
IP_VS_DBG_PKT(11, af, pp, skb, 0, "Outgoing packet");
if (!skb_make_writable(skb, ihl))
goto drop;
if (pp->snat_handler && !pp->snat_handler(skb, pp, cp))
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
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (unlikely(iph.protocol == IPPROTO_ICMPV6)) {
int related;
int verdict = ip_vs_out_icmp_v6(skb, &related,
hooknum);
if (related)
return verdict;
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
}
} else
#endif
if (unlikely(iph.protocol == IPPROTO_ICMP)) {
int related;
int verdict = ip_vs_out_icmp(skb, &related, hooknum);
if (related)
return verdict;
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
}
pd = ip_vs_proto_data_get(net, iph.protocol);
if (unlikely(!pd))
return NF_ACCEPT;
pp = pd->pp;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (ipv6_hdr(skb)->nexthdr == IPPROTO_FRAGMENT) {
if (ip_vs_gather_frags_v6(skb,
ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
}
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
} else
#endif
if (unlikely(ip_hdr(skb)->frag_off & htons(IP_MF|IP_OFFSET) &&
!pp->dont_defrag)) {
if (ip_vs_gather_frags(skb,
ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
}
cp = pp->conn_out_get(af, skb, &iph, iph.len, 0);
if (likely(cp))
return handle_response(af, skb, pd, cp, iph.len);
if (sysctl_nat_icmp_send(net) &&
(pp->protocol == IPPROTO_TCP ||
pp->protocol == IPPROTO_UDP ||
pp->protocol == IPPROTO_SCTP)) {
__be16 _ports[2], *pptr;
pptr = skb_header_pointer(skb, iph.len,
sizeof(_ports), _ports);
if (pptr == NULL)
return NF_ACCEPT;
if (ip_vs_lookup_real_service(net, af, iph.protocol,
&iph.saddr,
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
struct net *net =
dev_net(skb_dst(skb)->dev);
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
ip_vs_reply4(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_out(hooknum, skb, AF_INET);
}
static unsigned int
ip_vs_local_reply4(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int verdict;
local_bh_disable();
verdict = ip_vs_out(hooknum, skb, AF_INET);
local_bh_enable();
return verdict;
}
static unsigned int
ip_vs_reply6(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_out(hooknum, skb, AF_INET6);
}
static unsigned int
ip_vs_local_reply6(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int verdict;
local_bh_disable();
verdict = ip_vs_out(hooknum, skb, AF_INET6);
local_bh_enable();
return verdict;
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
unsigned int offset, ihl, verdict;
*related = 1;
if (ip_hdr(skb)->frag_off & htons(IP_MF | IP_OFFSET)) {
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
pd = ip_vs_proto_data_get(net, cih->protocol);
if (!pd)
return NF_ACCEPT;
pp = pd->pp;
if (unlikely(cih->frag_off & htons(IP_OFFSET) &&
pp->dont_defrag))
return NF_ACCEPT;
IP_VS_DBG_PKT(11, AF_INET, pp, skb, offset,
"Checking incoming ICMP for");
offset += cih->ihl * 4;
ip_vs_fill_iphdr(AF_INET, cih, &ciph);
cp = pp->conn_in_get(AF_INET, skb, &ciph, offset, 1);
if (!cp)
return NF_ACCEPT;
verdict = NF_DROP;
if (!skb_csum_unnecessary(skb) && ip_vs_checksum_complete(skb, ihl)) {
IP_VS_DBG(1, "Incoming ICMP: failed checksum from %pI4!\n",
&iph->saddr);
goto out;
}
ip_vs_in_stats(cp, skb);
if (IPPROTO_TCP == cih->protocol || IPPROTO_UDP == cih->protocol)
offset += 2 * sizeof(__u16);
verdict = ip_vs_icmp_xmit(skb, cp, pp, offset, hooknum);
out:
__ip_vs_conn_put(cp);
return verdict;
}
static int
ip_vs_in_icmp_v6(struct sk_buff *skb, int *related, unsigned int hooknum)
{
struct net *net = NULL;
struct ipv6hdr *iph;
struct icmp6hdr _icmph, *ic;
struct ipv6hdr _ciph, *cih;
struct ip_vs_iphdr ciph;
struct ip_vs_conn *cp;
struct ip_vs_protocol *pp;
struct ip_vs_proto_data *pd;
unsigned int offset, verdict;
*related = 1;
if (ipv6_hdr(skb)->nexthdr == IPPROTO_FRAGMENT) {
if (ip_vs_gather_frags_v6(skb, ip_vs_defrag_user(hooknum)))
return NF_STOLEN;
}
iph = ipv6_hdr(skb);
offset = sizeof(struct ipv6hdr);
ic = skb_header_pointer(skb, offset, sizeof(_icmph), &_icmph);
if (ic == NULL)
return NF_DROP;
IP_VS_DBG(12, "Incoming ICMPv6 (%d,%d) %pI6->%pI6\n",
ic->icmp6_type, ntohs(icmpv6_id(ic)),
&iph->saddr, &iph->daddr);
if ((ic->icmp6_type != ICMPV6_DEST_UNREACH) &&
(ic->icmp6_type != ICMPV6_PKT_TOOBIG) &&
(ic->icmp6_type != ICMPV6_TIME_EXCEED)) {
*related = 0;
return NF_ACCEPT;
}
offset += sizeof(_icmph);
cih = skb_header_pointer(skb, offset, sizeof(_ciph), &_ciph);
if (cih == NULL)
return NF_ACCEPT;
net = skb_net(skb);
pd = ip_vs_proto_data_get(net, cih->nexthdr);
if (!pd)
return NF_ACCEPT;
pp = pd->pp;
if (unlikely(cih->nexthdr == IPPROTO_FRAGMENT && pp->dont_defrag))
return NF_ACCEPT;
IP_VS_DBG_PKT(11, AF_INET6, pp, skb, offset,
"Checking incoming ICMPv6 for");
offset += sizeof(struct ipv6hdr);
ip_vs_fill_iphdr(AF_INET6, cih, &ciph);
cp = pp->conn_in_get(AF_INET6, skb, &ciph, offset, 1);
if (!cp)
return NF_ACCEPT;
ip_vs_in_stats(cp, skb);
if (IPPROTO_TCP == cih->nexthdr || IPPROTO_UDP == cih->nexthdr ||
IPPROTO_SCTP == cih->nexthdr)
offset += 2 * sizeof(__u16);
verdict = ip_vs_icmp_xmit_v6(skb, cp, pp, offset, hooknum);
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
int ret, restart, pkts;
struct netns_ipvs *ipvs;
if (skb->ipvs_property)
return NF_ACCEPT;
if (unlikely((skb->pkt_type != PACKET_HOST &&
hooknum != NF_INET_LOCAL_OUT) ||
!skb_dst(skb))) {
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
IP_VS_DBG_BUF(12, "packet type=%d proto=%d daddr=%s"
" ignored in hook %u\n",
skb->pkt_type, iph.protocol,
IP_VS_DBG_ADDR(af, &iph.daddr), hooknum);
return NF_ACCEPT;
}
net = skb_net(skb);
if (!net_ipvs(net)->enable)
return NF_ACCEPT;
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
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
int verdict = ip_vs_in_icmp_v6(skb, &related, hooknum);
if (related)
return verdict;
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
}
} else
#endif
if (unlikely(iph.protocol == IPPROTO_ICMP)) {
int related;
int verdict = ip_vs_in_icmp(skb, &related, hooknum);
if (related)
return verdict;
ip_vs_fill_iphdr(af, skb_network_header(skb), &iph);
}
pd = ip_vs_proto_data_get(net, iph.protocol);
if (unlikely(!pd))
return NF_ACCEPT;
pp = pd->pp;
cp = pp->conn_in_get(af, skb, &iph, iph.len, 0);
if (unlikely(!cp)) {
int v;
if (!pp->conn_schedule(af, skb, pd, &v, &cp))
return v;
}
if (unlikely(!cp)) {
IP_VS_DBG_PKT(12, af, pp, skb, 0,
"ip_vs_in: packet continues traversal as normal");
return NF_ACCEPT;
}
IP_VS_DBG_PKT(11, af, pp, skb, 0, "Incoming packet");
ipvs = net_ipvs(net);
if (cp->dest && !(cp->dest->flags & IP_VS_DEST_F_AVAILABLE)) {
if (sysctl_expire_nodest_conn(ipvs)) {
ip_vs_conn_expire_now(cp);
}
__ip_vs_conn_put(cp);
return NF_DROP;
}
ip_vs_in_stats(cp, skb);
restart = ip_vs_set_state(cp, IP_VS_DIR_INPUT, skb, pd);
if (cp->packet_xmit)
ret = cp->packet_xmit(skb, cp, pp);
else {
IP_VS_DBG_RL("warning: packet_xmit is null");
ret = NF_ACCEPT;
}
if (cp->flags & IP_VS_CONN_F_ONE_PACKET)
pkts = sysctl_sync_threshold(ipvs);
else
pkts = atomic_add_return(1, &cp->in_pkts);
if ((ipvs->sync_state & IP_VS_STATE_MASTER) &&
cp->protocol == IPPROTO_SCTP) {
if ((cp->state == IP_VS_SCTP_S_ESTABLISHED &&
(pkts % sysctl_sync_period(ipvs)
== sysctl_sync_threshold(ipvs))) ||
(cp->old_state != cp->state &&
((cp->state == IP_VS_SCTP_S_CLOSED) ||
(cp->state == IP_VS_SCTP_S_SHUT_ACK_CLI) ||
(cp->state == IP_VS_SCTP_S_SHUT_ACK_SER)))) {
ip_vs_sync_conn(net, cp);
goto out;
}
}
else if ((ipvs->sync_state & IP_VS_STATE_MASTER) &&
(((cp->protocol != IPPROTO_TCP ||
cp->state == IP_VS_TCP_S_ESTABLISHED) &&
(pkts % sysctl_sync_period(ipvs)
== sysctl_sync_threshold(ipvs))) ||
((cp->protocol == IPPROTO_TCP) && (cp->old_state != cp->state) &&
((cp->state == IP_VS_TCP_S_FIN_WAIT) ||
(cp->state == IP_VS_TCP_S_CLOSE) ||
(cp->state == IP_VS_TCP_S_CLOSE_WAIT) ||
(cp->state == IP_VS_TCP_S_TIME_WAIT)))))
ip_vs_sync_conn(net, cp);
out:
cp->old_state = cp->state;
ip_vs_conn_put(cp);
return ret;
}
static unsigned int
ip_vs_remote_request4(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_in(hooknum, skb, AF_INET);
}
static unsigned int
ip_vs_local_request4(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int verdict;
local_bh_disable();
verdict = ip_vs_in(hooknum, skb, AF_INET);
local_bh_enable();
return verdict;
}
static unsigned int
ip_vs_remote_request6(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ip_vs_in(hooknum, skb, AF_INET6);
}
static unsigned int
ip_vs_local_request6(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int verdict;
local_bh_disable();
verdict = ip_vs_in(hooknum, skb, AF_INET6);
local_bh_enable();
return verdict;
}
static unsigned int
ip_vs_forward_icmp(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
int r;
struct net *net;
if (ip_hdr(skb)->protocol != IPPROTO_ICMP)
return NF_ACCEPT;
net = skb_net(skb);
if (!net_ipvs(net)->enable)
return NF_ACCEPT;
return ip_vs_in_icmp(skb, &r, hooknum);
}
static unsigned int
ip_vs_forward_icmp_v6(unsigned int hooknum, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
int r;
struct net *net;
if (ipv6_hdr(skb)->nexthdr != IPPROTO_ICMPV6)
return NF_ACCEPT;
net = skb_net(skb);
if (!net_ipvs(net)->enable)
return NF_ACCEPT;
return ip_vs_in_icmp_v6(skb, &r, hooknum);
}
static int __net_init __ip_vs_init(struct net *net)
{
struct netns_ipvs *ipvs;
ipvs = net_generic(net, ip_vs_net_id);
if (ipvs == NULL) {
pr_err("%s(): no memory.\n", __func__);
return -ENOMEM;
}
ipvs->enable = 0;
ipvs->net = net;
ipvs->gen = atomic_read(&ipvs_netns_cnt);
atomic_inc(&ipvs_netns_cnt);
net->ipvs = ipvs;
if (__ip_vs_estimator_init(net) < 0)
goto estimator_fail;
if (__ip_vs_control_init(net) < 0)
goto control_fail;
if (__ip_vs_protocol_init(net) < 0)
goto protocol_fail;
if (__ip_vs_app_init(net) < 0)
goto app_fail;
if (__ip_vs_conn_init(net) < 0)
goto conn_fail;
if (__ip_vs_sync_init(net) < 0)
goto sync_fail;
printk(KERN_INFO "IPVS: Creating netns size=%zu id=%d\n",
sizeof(struct netns_ipvs), ipvs->gen);
return 0;
sync_fail:
__ip_vs_conn_cleanup(net);
conn_fail:
__ip_vs_app_cleanup(net);
app_fail:
__ip_vs_protocol_cleanup(net);
protocol_fail:
__ip_vs_control_cleanup(net);
control_fail:
__ip_vs_estimator_cleanup(net);
estimator_fail:
return -ENOMEM;
}
static void __net_exit __ip_vs_cleanup(struct net *net)
{
__ip_vs_service_cleanup(net);
__ip_vs_conn_cleanup(net);
__ip_vs_app_cleanup(net);
__ip_vs_protocol_cleanup(net);
__ip_vs_control_cleanup(net);
__ip_vs_estimator_cleanup(net);
IP_VS_DBG(2, "ipvs netns %d released\n", net_ipvs(net)->gen);
}
static void __net_exit __ip_vs_dev_cleanup(struct net *net)
{
EnterFunction(2);
net_ipvs(net)->enable = 0;
smp_wmb();
__ip_vs_sync_cleanup(net);
LeaveFunction(2);
}
static int __init ip_vs_init(void)
{
int ret;
ip_vs_estimator_init();
ret = ip_vs_control_init();
if (ret < 0) {
pr_err("can't setup control.\n");
goto cleanup_estimator;
}
ip_vs_protocol_init();
ret = ip_vs_app_init();
if (ret < 0) {
pr_err("can't setup application helper.\n");
goto cleanup_protocol;
}
ret = ip_vs_conn_init();
if (ret < 0) {
pr_err("can't setup connection table.\n");
goto cleanup_app;
}
ret = ip_vs_sync_init();
if (ret < 0) {
pr_err("can't setup sync data.\n");
goto cleanup_conn;
}
ret = register_pernet_subsys(&ipvs_core_ops);
if (ret < 0)
goto cleanup_sync;
ret = register_pernet_device(&ipvs_core_dev_ops);
if (ret < 0)
goto cleanup_sub;
ret = nf_register_hooks(ip_vs_ops, ARRAY_SIZE(ip_vs_ops));
if (ret < 0) {
pr_err("can't register hooks.\n");
goto cleanup_dev;
}
pr_info("ipvs loaded.\n");
return ret;
cleanup_dev:
unregister_pernet_device(&ipvs_core_dev_ops);
cleanup_sub:
unregister_pernet_subsys(&ipvs_core_ops);
cleanup_sync:
ip_vs_sync_cleanup();
cleanup_conn:
ip_vs_conn_cleanup();
cleanup_app:
ip_vs_app_cleanup();
cleanup_protocol:
ip_vs_protocol_cleanup();
ip_vs_control_cleanup();
cleanup_estimator:
ip_vs_estimator_cleanup();
return ret;
}
static void __exit ip_vs_cleanup(void)
{
nf_unregister_hooks(ip_vs_ops, ARRAY_SIZE(ip_vs_ops));
unregister_pernet_device(&ipvs_core_dev_ops);
unregister_pernet_subsys(&ipvs_core_ops);
ip_vs_sync_cleanup();
ip_vs_conn_cleanup();
ip_vs_app_cleanup();
ip_vs_protocol_cleanup();
ip_vs_control_cleanup();
ip_vs_estimator_cleanup();
pr_info("ipvs unloaded.\n");
}
