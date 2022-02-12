static inline struct nf_udplite_net *udplite_pernet(struct net *net)
{
return &net->ct.nf_ct_proto.udplite;
}
static bool udplite_pkt_to_tuple(const struct sk_buff *skb,
unsigned int dataoff,
struct net *net,
struct nf_conntrack_tuple *tuple)
{
const struct udphdr *hp;
struct udphdr _hdr;
hp = skb_header_pointer(skb, dataoff, 4, &_hdr);
if (hp == NULL)
return false;
tuple->src.u.udp.port = hp->source;
tuple->dst.u.udp.port = hp->dest;
return true;
}
static bool udplite_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
tuple->src.u.udp.port = orig->dst.u.udp.port;
tuple->dst.u.udp.port = orig->src.u.udp.port;
return true;
}
static void udplite_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
seq_printf(s, "sport=%hu dport=%hu ",
ntohs(tuple->src.u.udp.port),
ntohs(tuple->dst.u.udp.port));
}
static unsigned int *udplite_get_timeouts(struct net *net)
{
return udplite_pernet(net)->timeouts;
}
static int udplite_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum,
unsigned int *timeouts)
{
if (test_bit(IPS_SEEN_REPLY_BIT, &ct->status)) {
nf_ct_refresh_acct(ct, ctinfo, skb,
timeouts[UDPLITE_CT_REPLIED]);
if (!test_and_set_bit(IPS_ASSURED_BIT, &ct->status))
nf_conntrack_event_cache(IPCT_ASSURED, ct);
} else {
nf_ct_refresh_acct(ct, ctinfo, skb,
timeouts[UDPLITE_CT_UNREPLIED]);
}
return NF_ACCEPT;
}
static bool udplite_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, unsigned int *timeouts)
{
return true;
}
static int udplite_error(struct net *net, struct nf_conn *tmpl,
struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info *ctinfo,
u_int8_t pf,
unsigned int hooknum)
{
unsigned int udplen = skb->len - dataoff;
const struct udphdr *hdr;
struct udphdr _hdr;
unsigned int cscov;
hdr = skb_header_pointer(skb, dataoff, sizeof(_hdr), &_hdr);
if (hdr == NULL) {
if (LOG_INVALID(net, IPPROTO_UDPLITE))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udplite: short packet ");
return -NF_ACCEPT;
}
cscov = ntohs(hdr->len);
if (cscov == 0)
cscov = udplen;
else if (cscov < sizeof(*hdr) || cscov > udplen) {
if (LOG_INVALID(net, IPPROTO_UDPLITE))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udplite: invalid checksum coverage ");
return -NF_ACCEPT;
}
if (!hdr->check) {
if (LOG_INVALID(net, IPPROTO_UDPLITE))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udplite: checksum missing ");
return -NF_ACCEPT;
}
if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
nf_checksum_partial(skb, hooknum, dataoff, cscov, IPPROTO_UDP,
pf)) {
if (LOG_INVALID(net, IPPROTO_UDPLITE))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udplite: bad UDPLite checksum ");
return -NF_ACCEPT;
}
return NF_ACCEPT;
}
static int udplite_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
unsigned int *timeouts = data;
struct nf_udplite_net *un = udplite_pernet(net);
timeouts[UDPLITE_CT_UNREPLIED] = un->timeouts[UDPLITE_CT_UNREPLIED];
timeouts[UDPLITE_CT_REPLIED] = un->timeouts[UDPLITE_CT_REPLIED];
if (tb[CTA_TIMEOUT_UDPLITE_UNREPLIED]) {
timeouts[UDPLITE_CT_UNREPLIED] =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_UDPLITE_UNREPLIED])) * HZ;
}
if (tb[CTA_TIMEOUT_UDPLITE_REPLIED]) {
timeouts[UDPLITE_CT_REPLIED] =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_UDPLITE_REPLIED])) * HZ;
}
return 0;
}
static int
udplite_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeouts = data;
if (nla_put_be32(skb, CTA_TIMEOUT_UDPLITE_UNREPLIED,
htonl(timeouts[UDPLITE_CT_UNREPLIED] / HZ)) ||
nla_put_be32(skb, CTA_TIMEOUT_UDPLITE_REPLIED,
htonl(timeouts[UDPLITE_CT_REPLIED] / HZ)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -ENOSPC;
}
static int udplite_kmemdup_sysctl_table(struct nf_proto_net *pn,
struct nf_udplite_net *un)
{
#ifdef CONFIG_SYSCTL
if (pn->ctl_table)
return 0;
pn->ctl_table = kmemdup(udplite_sysctl_table,
sizeof(udplite_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_table)
return -ENOMEM;
pn->ctl_table[0].data = &un->timeouts[UDPLITE_CT_UNREPLIED];
pn->ctl_table[1].data = &un->timeouts[UDPLITE_CT_REPLIED];
#endif
return 0;
}
static int udplite_init_net(struct net *net, u_int16_t proto)
{
struct nf_udplite_net *un = udplite_pernet(net);
struct nf_proto_net *pn = &un->pn;
if (!pn->users) {
int i;
for (i = 0 ; i < UDPLITE_CT_MAX; i++)
un->timeouts[i] = udplite_timeouts[i];
}
return udplite_kmemdup_sysctl_table(pn, un);
}
