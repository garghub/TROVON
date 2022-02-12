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
return udp_timeouts;
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
nf_log_packet(pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udp: short packet ");
return -NF_ACCEPT;
}
if (ntohs(hdr->len) > udplen || ntohs(hdr->len) < sizeof(*hdr)) {
if (LOG_INVALID(net, IPPROTO_UDP))
nf_log_packet(pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udp: truncated/malformed packet ");
return -NF_ACCEPT;
}
if (!hdr->check)
return NF_ACCEPT;
if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
nf_checksum(skb, hooknum, dataoff, IPPROTO_UDP, pf)) {
if (LOG_INVALID(net, IPPROTO_UDP))
nf_log_packet(pf, 0, skb, NULL, NULL, NULL,
"nf_ct_udp: bad UDP checksum ");
return -NF_ACCEPT;
}
return NF_ACCEPT;
}
static int udp_timeout_nlattr_to_obj(struct nlattr *tb[], void *data)
{
unsigned int *timeouts = data;
timeouts[UDP_CT_UNREPLIED] = udp_timeouts[UDP_CT_UNREPLIED];
timeouts[UDP_CT_REPLIED] = udp_timeouts[UDP_CT_REPLIED];
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
NLA_PUT_BE32(skb, CTA_TIMEOUT_UDP_UNREPLIED,
htonl(timeouts[UDP_CT_UNREPLIED] / HZ));
NLA_PUT_BE32(skb, CTA_TIMEOUT_UDP_REPLIED,
htonl(timeouts[UDP_CT_REPLIED] / HZ));
return 0;
nla_put_failure:
return -ENOSPC;
}
