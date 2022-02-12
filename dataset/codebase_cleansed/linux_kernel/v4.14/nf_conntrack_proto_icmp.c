static inline struct nf_icmp_net *icmp_pernet(struct net *net)
{
return &net->ct.nf_ct_proto.icmp;
}
static bool icmp_pkt_to_tuple(const struct sk_buff *skb, unsigned int dataoff,
struct net *net, struct nf_conntrack_tuple *tuple)
{
const struct icmphdr *hp;
struct icmphdr _hdr;
hp = skb_header_pointer(skb, dataoff, sizeof(_hdr), &_hdr);
if (hp == NULL)
return false;
tuple->dst.u.icmp.type = hp->type;
tuple->src.u.icmp.id = hp->un.echo.id;
tuple->dst.u.icmp.code = hp->code;
return true;
}
static bool icmp_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
if (orig->dst.u.icmp.type >= sizeof(invmap) ||
!invmap[orig->dst.u.icmp.type])
return false;
tuple->src.u.icmp.id = orig->src.u.icmp.id;
tuple->dst.u.icmp.type = invmap[orig->dst.u.icmp.type] - 1;
tuple->dst.u.icmp.code = orig->dst.u.icmp.code;
return true;
}
static unsigned int *icmp_get_timeouts(struct net *net)
{
return &icmp_pernet(net)->timeout;
}
static int icmp_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int *timeout)
{
nf_ct_refresh_acct(ct, ctinfo, skb, *timeout);
return NF_ACCEPT;
}
static bool icmp_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, unsigned int *timeouts)
{
static const u_int8_t valid_new[] = {
[ICMP_ECHO] = 1,
[ICMP_TIMESTAMP] = 1,
[ICMP_INFO_REQUEST] = 1,
[ICMP_ADDRESS] = 1
};
if (ct->tuplehash[0].tuple.dst.u.icmp.type >= sizeof(valid_new) ||
!valid_new[ct->tuplehash[0].tuple.dst.u.icmp.type]) {
pr_debug("icmp: can't create new conn with type %u\n",
ct->tuplehash[0].tuple.dst.u.icmp.type);
nf_ct_dump_tuple_ip(&ct->tuplehash[0].tuple);
return false;
}
return true;
}
static int
icmp_error_message(struct net *net, struct nf_conn *tmpl, struct sk_buff *skb,
unsigned int hooknum)
{
struct nf_conntrack_tuple innertuple, origtuple;
const struct nf_conntrack_l4proto *innerproto;
const struct nf_conntrack_tuple_hash *h;
const struct nf_conntrack_zone *zone;
enum ip_conntrack_info ctinfo;
struct nf_conntrack_zone tmp;
WARN_ON(skb_nfct(skb));
zone = nf_ct_zone_tmpl(tmpl, skb, &tmp);
if (!nf_ct_get_tuplepr(skb,
skb_network_offset(skb) + ip_hdrlen(skb)
+ sizeof(struct icmphdr),
PF_INET, net, &origtuple)) {
pr_debug("icmp_error_message: failed to get tuple\n");
return -NF_ACCEPT;
}
innerproto = __nf_ct_l4proto_find(PF_INET, origtuple.dst.protonum);
if (!nf_ct_invert_tuple(&innertuple, &origtuple,
&nf_conntrack_l3proto_ipv4, innerproto)) {
pr_debug("icmp_error_message: no match\n");
return -NF_ACCEPT;
}
ctinfo = IP_CT_RELATED;
h = nf_conntrack_find_get(net, zone, &innertuple);
if (!h) {
pr_debug("icmp_error_message: no match\n");
return -NF_ACCEPT;
}
if (NF_CT_DIRECTION(h) == IP_CT_DIR_REPLY)
ctinfo += IP_CT_IS_REPLY;
nf_ct_set(skb, nf_ct_tuplehash_to_ctrack(h), ctinfo);
return NF_ACCEPT;
}
static int
icmp_error(struct net *net, struct nf_conn *tmpl,
struct sk_buff *skb, unsigned int dataoff,
u8 pf, unsigned int hooknum)
{
const struct icmphdr *icmph;
struct icmphdr _ih;
icmph = skb_header_pointer(skb, ip_hdrlen(skb), sizeof(_ih), &_ih);
if (icmph == NULL) {
if (LOG_INVALID(net, IPPROTO_ICMP))
nf_log_packet(net, PF_INET, 0, skb, NULL, NULL,
NULL, "nf_ct_icmp: short packet ");
return -NF_ACCEPT;
}
if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
nf_ip_checksum(skb, hooknum, dataoff, 0)) {
if (LOG_INVALID(net, IPPROTO_ICMP))
nf_log_packet(net, PF_INET, 0, skb, NULL, NULL, NULL,
"nf_ct_icmp: bad HW ICMP checksum ");
return -NF_ACCEPT;
}
if (icmph->type > NR_ICMP_TYPES) {
if (LOG_INVALID(net, IPPROTO_ICMP))
nf_log_packet(net, PF_INET, 0, skb, NULL, NULL, NULL,
"nf_ct_icmp: invalid ICMP type ");
return -NF_ACCEPT;
}
if (icmph->type != ICMP_DEST_UNREACH &&
icmph->type != ICMP_SOURCE_QUENCH &&
icmph->type != ICMP_TIME_EXCEEDED &&
icmph->type != ICMP_PARAMETERPROB &&
icmph->type != ICMP_REDIRECT)
return NF_ACCEPT;
return icmp_error_message(net, tmpl, skb, hooknum);
}
static int icmp_tuple_to_nlattr(struct sk_buff *skb,
const struct nf_conntrack_tuple *t)
{
if (nla_put_be16(skb, CTA_PROTO_ICMP_ID, t->src.u.icmp.id) ||
nla_put_u8(skb, CTA_PROTO_ICMP_TYPE, t->dst.u.icmp.type) ||
nla_put_u8(skb, CTA_PROTO_ICMP_CODE, t->dst.u.icmp.code))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int icmp_nlattr_to_tuple(struct nlattr *tb[],
struct nf_conntrack_tuple *tuple)
{
if (!tb[CTA_PROTO_ICMP_TYPE] ||
!tb[CTA_PROTO_ICMP_CODE] ||
!tb[CTA_PROTO_ICMP_ID])
return -EINVAL;
tuple->dst.u.icmp.type = nla_get_u8(tb[CTA_PROTO_ICMP_TYPE]);
tuple->dst.u.icmp.code = nla_get_u8(tb[CTA_PROTO_ICMP_CODE]);
tuple->src.u.icmp.id = nla_get_be16(tb[CTA_PROTO_ICMP_ID]);
if (tuple->dst.u.icmp.type >= sizeof(invmap) ||
!invmap[tuple->dst.u.icmp.type])
return -EINVAL;
return 0;
}
static int icmp_nlattr_tuple_size(void)
{
return nla_policy_len(icmp_nla_policy, CTA_PROTO_MAX + 1);
}
static int icmp_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
unsigned int *timeout = data;
struct nf_icmp_net *in = icmp_pernet(net);
if (tb[CTA_TIMEOUT_ICMP_TIMEOUT]) {
*timeout =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_ICMP_TIMEOUT])) * HZ;
} else {
*timeout = in->timeout;
}
return 0;
}
static int
icmp_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeout = data;
if (nla_put_be32(skb, CTA_TIMEOUT_ICMP_TIMEOUT, htonl(*timeout / HZ)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -ENOSPC;
}
static int icmp_kmemdup_sysctl_table(struct nf_proto_net *pn,
struct nf_icmp_net *in)
{
#ifdef CONFIG_SYSCTL
pn->ctl_table = kmemdup(icmp_sysctl_table,
sizeof(icmp_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_table)
return -ENOMEM;
pn->ctl_table[0].data = &in->timeout;
#endif
return 0;
}
static int icmp_init_net(struct net *net, u_int16_t proto)
{
struct nf_icmp_net *in = icmp_pernet(net);
struct nf_proto_net *pn = &in->pn;
in->timeout = nf_ct_icmp_timeout;
return icmp_kmemdup_sysctl_table(pn, in);
}
static struct nf_proto_net *icmp_get_net_proto(struct net *net)
{
return &net->ct.nf_ct_proto.icmp.pn;
}
