static inline struct nf_udp_net *udp_pernet(struct net *net)
{
return &net->ct.nf_ct_proto.udp;
}
static bool udp_pkt_to_tuple(const struct sk_buff *skb,
unsigned int dataoff,
struct nf_conntrack_tuple *tuple)
{
const struct udphdr *hp;
struct udphdr _hdr;
hp = skb_header_pointer(skb, dataoff, sizeof(_hdr), &_hdr);
if (hp == NULL)
return false;
tuple->src.u.udp.port = hp->source;
tuple->dst.u.udp.port = hp->dest;
return true;
}
static bool udp_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
tuple->src.u.udp.port = orig->dst.u.udp.port;
tuple->dst.u.udp.port = orig->src.u.udp.port;
return true;
}
static int udp_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
return seq_printf(s, "sport=%hu dport=%hu ",
ntohs(tuple->src.u.udp.port),
ntohs(tuple->dst.u.udp.port));
}
static unsigned int *udp_get_timeouts(struct net *net)
{
return udp_pernet(net)->timeouts;
}
static int udp_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum,
unsigned int *timeouts)
{
if (test_bit(IPS_SEEN_REPLY_BIT, &ct->status)) {
nf_ct_refresh_acct(ct, ctinfo, skb,
timeouts[UDP_CT_REPLIED]);
if (!test_and_set_bit(IPS_ASSURED_BIT, &ct->status))
nf_conntrack_event_cache(IPCT_ASSURED, ct);
} else {
nf_ct_refresh_acct(ct, ctinfo, skb,
timeouts[UDP_CT_UNREPLIED]);
}
return NF_ACCEPT;
}
static bool udp_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, unsigned int *timeouts)
{
return true;
}
static int udp_error(struct net *net, struct nf_conn *tmpl, struct sk_buff *skb,
unsigned int dataoff, enum ip_conntrack_info *ctinfo,
u_int8_t pf,
unsigned int hooknum)
{
unsigned int udplen = skb->len - dataoff;
const struct udphdr *hdr;
struct udphdr _hdr;
hdr = skb_header_pointer(skb, dataoff, sizeof(_hdr), &_hdr);
if (hdr == NULL) {
if (LOG_INVALID(net, IPPROTO_UDP))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udp: short packet ");
return -NF_ACCEPT;
}
if (ntohs(hdr->len) > udplen || ntohs(hdr->len) < sizeof(*hdr)) {
if (LOG_INVALID(net, IPPROTO_UDP))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udp: truncated/malformed packet ");
return -NF_ACCEPT;
}
if (!hdr->check)
return NF_ACCEPT;
if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
nf_checksum(skb, hooknum, dataoff, IPPROTO_UDP, pf)) {
if (LOG_INVALID(net, IPPROTO_UDP))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udp: bad UDP checksum ");
return -NF_ACCEPT;
}
return NF_ACCEPT;
}
static int udp_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
unsigned int *timeouts = data;
struct nf_udp_net *un = udp_pernet(net);
timeouts[UDP_CT_UNREPLIED] = un->timeouts[UDP_CT_UNREPLIED];
timeouts[UDP_CT_REPLIED] = un->timeouts[UDP_CT_REPLIED];
if (tb[CTA_TIMEOUT_UDP_UNREPLIED]) {
timeouts[UDP_CT_UNREPLIED] =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_UDP_UNREPLIED])) * HZ;
}
if (tb[CTA_TIMEOUT_UDP_REPLIED]) {
timeouts[UDP_CT_REPLIED] =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_UDP_REPLIED])) * HZ;
}
return 0;
}
static int
udp_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeouts = data;
if (nla_put_be32(skb, CTA_TIMEOUT_UDP_UNREPLIED,
htonl(timeouts[UDP_CT_UNREPLIED] / HZ)) ||
nla_put_be32(skb, CTA_TIMEOUT_UDP_REPLIED,
htonl(timeouts[UDP_CT_REPLIED] / HZ)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -ENOSPC;
}
static int udp_kmemdup_sysctl_table(struct nf_proto_net *pn,
struct nf_udp_net *un)
{
#ifdef CONFIG_SYSCTL
if (pn->ctl_table)
return 0;
pn->ctl_table = kmemdup(udp_sysctl_table,
sizeof(udp_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_table)
return -ENOMEM;
pn->ctl_table[0].data = &un->timeouts[UDP_CT_UNREPLIED];
pn->ctl_table[1].data = &un->timeouts[UDP_CT_REPLIED];
#endif
return 0;
}
static int udp_kmemdup_compat_sysctl_table(struct nf_proto_net *pn,
struct nf_udp_net *un)
{
#ifdef CONFIG_SYSCTL
#ifdef CONFIG_NF_CONNTRACK_PROC_COMPAT
pn->ctl_compat_table = kmemdup(udp_compat_sysctl_table,
sizeof(udp_compat_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_compat_table)
return -ENOMEM;
pn->ctl_compat_table[0].data = &un->timeouts[UDP_CT_UNREPLIED];
pn->ctl_compat_table[1].data = &un->timeouts[UDP_CT_REPLIED];
#endif
#endif
return 0;
}
static int udp_init_net(struct net *net, u_int16_t proto)
{
int ret;
struct nf_udp_net *un = udp_pernet(net);
struct nf_proto_net *pn = &un->pn;
if (!pn->users) {
int i;
for (i = 0; i < UDP_CT_MAX; i++)
un->timeouts[i] = udp_timeouts[i];
}
if (proto == AF_INET) {
ret = udp_kmemdup_compat_sysctl_table(pn, un);
if (ret < 0)
return ret;
ret = udp_kmemdup_sysctl_table(pn, un);
if (ret < 0)
nf_ct_kfree_compat_sysctl_table(pn);
} else
ret = udp_kmemdup_sysctl_table(pn, un);
return ret;
}
static struct nf_proto_net *udp_get_net_proto(struct net *net)
{
return &net->ct.nf_ct_proto.udp.pn;
}
