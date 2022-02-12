static inline struct dccp_net *dccp_pernet(struct net *net)
{
return net_generic(net, dccp_net_id);
}
static bool dccp_pkt_to_tuple(const struct sk_buff *skb, unsigned int dataoff,
struct nf_conntrack_tuple *tuple)
{
struct dccp_hdr _hdr, *dh;
dh = skb_header_pointer(skb, dataoff, sizeof(_hdr), &_hdr);
if (dh == NULL)
return false;
tuple->src.u.dccp.port = dh->dccph_sport;
tuple->dst.u.dccp.port = dh->dccph_dport;
return true;
}
static bool dccp_invert_tuple(struct nf_conntrack_tuple *inv,
const struct nf_conntrack_tuple *tuple)
{
inv->src.u.dccp.port = tuple->dst.u.dccp.port;
inv->dst.u.dccp.port = tuple->src.u.dccp.port;
return true;
}
static bool dccp_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff)
{
struct net *net = nf_ct_net(ct);
struct dccp_net *dn;
struct dccp_hdr _dh, *dh;
const char *msg;
u_int8_t state;
dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &dh);
BUG_ON(dh == NULL);
state = dccp_state_table[CT_DCCP_ROLE_CLIENT][dh->dccph_type][CT_DCCP_NONE];
switch (state) {
default:
dn = dccp_pernet(net);
if (dn->dccp_loose == 0) {
msg = "nf_ct_dccp: not picking up existing connection ";
goto out_invalid;
}
case CT_DCCP_REQUEST:
break;
case CT_DCCP_INVALID:
msg = "nf_ct_dccp: invalid state transition ";
goto out_invalid;
}
ct->proto.dccp.role[IP_CT_DIR_ORIGINAL] = CT_DCCP_ROLE_CLIENT;
ct->proto.dccp.role[IP_CT_DIR_REPLY] = CT_DCCP_ROLE_SERVER;
ct->proto.dccp.state = CT_DCCP_NONE;
ct->proto.dccp.last_pkt = DCCP_PKT_REQUEST;
ct->proto.dccp.last_dir = IP_CT_DIR_ORIGINAL;
ct->proto.dccp.handshake_seq = 0;
return true;
out_invalid:
if (LOG_INVALID(net, IPPROTO_DCCP))
nf_log_packet(nf_ct_l3num(ct), 0, skb, NULL, NULL, NULL, msg);
return false;
}
static u64 dccp_ack_seq(const struct dccp_hdr *dh)
{
const struct dccp_hdr_ack_bits *dhack;
dhack = (void *)dh + __dccp_basic_hdr_len(dh);
return ((u64)ntohs(dhack->dccph_ack_nr_high) << 32) +
ntohl(dhack->dccph_ack_nr_low);
}
static int dccp_packet(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, enum ip_conntrack_info ctinfo,
u_int8_t pf, unsigned int hooknum)
{
struct net *net = nf_ct_net(ct);
struct dccp_net *dn;
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
struct dccp_hdr _dh, *dh;
u_int8_t type, old_state, new_state;
enum ct_dccp_roles role;
dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &dh);
BUG_ON(dh == NULL);
type = dh->dccph_type;
if (type == DCCP_PKT_RESET &&
!test_bit(IPS_SEEN_REPLY_BIT, &ct->status)) {
nf_ct_kill_acct(ct, ctinfo, skb);
return NF_ACCEPT;
}
spin_lock_bh(&ct->lock);
role = ct->proto.dccp.role[dir];
old_state = ct->proto.dccp.state;
new_state = dccp_state_table[role][type][old_state];
switch (new_state) {
case CT_DCCP_REQUEST:
if (old_state == CT_DCCP_TIMEWAIT &&
role == CT_DCCP_ROLE_SERVER) {
ct->proto.dccp.role[dir] = CT_DCCP_ROLE_CLIENT;
ct->proto.dccp.role[!dir] = CT_DCCP_ROLE_SERVER;
}
break;
case CT_DCCP_RESPOND:
if (old_state == CT_DCCP_REQUEST)
ct->proto.dccp.handshake_seq = dccp_hdr_seq(dh);
break;
case CT_DCCP_PARTOPEN:
if (old_state == CT_DCCP_RESPOND &&
type == DCCP_PKT_ACK &&
dccp_ack_seq(dh) == ct->proto.dccp.handshake_seq)
set_bit(IPS_ASSURED_BIT, &ct->status);
break;
case CT_DCCP_IGNORE:
if (ct->proto.dccp.last_dir == !dir &&
ct->proto.dccp.last_pkt == DCCP_PKT_REQUEST &&
type == DCCP_PKT_RESPONSE) {
ct->proto.dccp.role[!dir] = CT_DCCP_ROLE_CLIENT;
ct->proto.dccp.role[dir] = CT_DCCP_ROLE_SERVER;
ct->proto.dccp.handshake_seq = dccp_hdr_seq(dh);
new_state = CT_DCCP_RESPOND;
break;
}
ct->proto.dccp.last_dir = dir;
ct->proto.dccp.last_pkt = type;
spin_unlock_bh(&ct->lock);
if (LOG_INVALID(net, IPPROTO_DCCP))
nf_log_packet(pf, 0, skb, NULL, NULL, NULL,
"nf_ct_dccp: invalid packet ignored ");
return NF_ACCEPT;
case CT_DCCP_INVALID:
spin_unlock_bh(&ct->lock);
if (LOG_INVALID(net, IPPROTO_DCCP))
nf_log_packet(pf, 0, skb, NULL, NULL, NULL,
"nf_ct_dccp: invalid state transition ");
return -NF_ACCEPT;
}
ct->proto.dccp.last_dir = dir;
ct->proto.dccp.last_pkt = type;
ct->proto.dccp.state = new_state;
spin_unlock_bh(&ct->lock);
if (new_state != old_state)
nf_conntrack_event_cache(IPCT_PROTOINFO, ct);
dn = dccp_pernet(net);
nf_ct_refresh_acct(ct, ctinfo, skb, dn->dccp_timeout[new_state]);
return NF_ACCEPT;
}
static int dccp_error(struct net *net, struct nf_conn *tmpl,
struct sk_buff *skb, unsigned int dataoff,
enum ip_conntrack_info *ctinfo,
u_int8_t pf, unsigned int hooknum)
{
struct dccp_hdr _dh, *dh;
unsigned int dccp_len = skb->len - dataoff;
unsigned int cscov;
const char *msg;
dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &dh);
if (dh == NULL) {
msg = "nf_ct_dccp: short packet ";
goto out_invalid;
}
if (dh->dccph_doff * 4 < sizeof(struct dccp_hdr) ||
dh->dccph_doff * 4 > dccp_len) {
msg = "nf_ct_dccp: truncated/malformed packet ";
goto out_invalid;
}
cscov = dccp_len;
if (dh->dccph_cscov) {
cscov = (dh->dccph_cscov - 1) * 4;
if (cscov > dccp_len) {
msg = "nf_ct_dccp: bad checksum coverage ";
goto out_invalid;
}
}
if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
nf_checksum_partial(skb, hooknum, dataoff, cscov, IPPROTO_DCCP,
pf)) {
msg = "nf_ct_dccp: bad checksum ";
goto out_invalid;
}
if (dh->dccph_type >= DCCP_PKT_INVALID) {
msg = "nf_ct_dccp: reserved packet type ";
goto out_invalid;
}
return NF_ACCEPT;
out_invalid:
if (LOG_INVALID(net, IPPROTO_DCCP))
nf_log_packet(pf, 0, skb, NULL, NULL, NULL, msg);
return -NF_ACCEPT;
}
static int dccp_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
return seq_printf(s, "sport=%hu dport=%hu ",
ntohs(tuple->src.u.dccp.port),
ntohs(tuple->dst.u.dccp.port));
}
static int dccp_print_conntrack(struct seq_file *s, struct nf_conn *ct)
{
return seq_printf(s, "%s ", dccp_state_names[ct->proto.dccp.state]);
}
static int dccp_to_nlattr(struct sk_buff *skb, struct nlattr *nla,
struct nf_conn *ct)
{
struct nlattr *nest_parms;
spin_lock_bh(&ct->lock);
nest_parms = nla_nest_start(skb, CTA_PROTOINFO_DCCP | NLA_F_NESTED);
if (!nest_parms)
goto nla_put_failure;
NLA_PUT_U8(skb, CTA_PROTOINFO_DCCP_STATE, ct->proto.dccp.state);
NLA_PUT_U8(skb, CTA_PROTOINFO_DCCP_ROLE,
ct->proto.dccp.role[IP_CT_DIR_ORIGINAL]);
NLA_PUT_BE64(skb, CTA_PROTOINFO_DCCP_HANDSHAKE_SEQ,
cpu_to_be64(ct->proto.dccp.handshake_seq));
nla_nest_end(skb, nest_parms);
spin_unlock_bh(&ct->lock);
return 0;
nla_put_failure:
spin_unlock_bh(&ct->lock);
return -1;
}
static int nlattr_to_dccp(struct nlattr *cda[], struct nf_conn *ct)
{
struct nlattr *attr = cda[CTA_PROTOINFO_DCCP];
struct nlattr *tb[CTA_PROTOINFO_DCCP_MAX + 1];
int err;
if (!attr)
return 0;
err = nla_parse_nested(tb, CTA_PROTOINFO_DCCP_MAX, attr,
dccp_nla_policy);
if (err < 0)
return err;
if (!tb[CTA_PROTOINFO_DCCP_STATE] ||
!tb[CTA_PROTOINFO_DCCP_ROLE] ||
nla_get_u8(tb[CTA_PROTOINFO_DCCP_ROLE]) > CT_DCCP_ROLE_MAX ||
nla_get_u8(tb[CTA_PROTOINFO_DCCP_STATE]) >= CT_DCCP_IGNORE) {
return -EINVAL;
}
spin_lock_bh(&ct->lock);
ct->proto.dccp.state = nla_get_u8(tb[CTA_PROTOINFO_DCCP_STATE]);
if (nla_get_u8(tb[CTA_PROTOINFO_DCCP_ROLE]) == CT_DCCP_ROLE_CLIENT) {
ct->proto.dccp.role[IP_CT_DIR_ORIGINAL] = CT_DCCP_ROLE_CLIENT;
ct->proto.dccp.role[IP_CT_DIR_REPLY] = CT_DCCP_ROLE_SERVER;
} else {
ct->proto.dccp.role[IP_CT_DIR_ORIGINAL] = CT_DCCP_ROLE_SERVER;
ct->proto.dccp.role[IP_CT_DIR_REPLY] = CT_DCCP_ROLE_CLIENT;
}
if (tb[CTA_PROTOINFO_DCCP_HANDSHAKE_SEQ]) {
ct->proto.dccp.handshake_seq =
be64_to_cpu(nla_get_be64(tb[CTA_PROTOINFO_DCCP_HANDSHAKE_SEQ]));
}
spin_unlock_bh(&ct->lock);
return 0;
}
static int dccp_nlattr_size(void)
{
return nla_total_size(0)
+ nla_policy_len(dccp_nla_policy, CTA_PROTOINFO_DCCP_MAX + 1);
}
static __net_init int dccp_net_init(struct net *net)
{
struct dccp_net *dn = dccp_pernet(net);
dn->dccp_loose = 1;
dn->dccp_timeout[CT_DCCP_REQUEST] = 2 * DCCP_MSL;
dn->dccp_timeout[CT_DCCP_RESPOND] = 4 * DCCP_MSL;
dn->dccp_timeout[CT_DCCP_PARTOPEN] = 4 * DCCP_MSL;
dn->dccp_timeout[CT_DCCP_OPEN] = 12 * 3600 * HZ;
dn->dccp_timeout[CT_DCCP_CLOSEREQ] = 64 * HZ;
dn->dccp_timeout[CT_DCCP_CLOSING] = 64 * HZ;
dn->dccp_timeout[CT_DCCP_TIMEWAIT] = 2 * DCCP_MSL;
#ifdef CONFIG_SYSCTL
dn->sysctl_table = kmemdup(dccp_sysctl_table,
sizeof(dccp_sysctl_table), GFP_KERNEL);
if (!dn->sysctl_table)
return -ENOMEM;
dn->sysctl_table[0].data = &dn->dccp_timeout[CT_DCCP_REQUEST];
dn->sysctl_table[1].data = &dn->dccp_timeout[CT_DCCP_RESPOND];
dn->sysctl_table[2].data = &dn->dccp_timeout[CT_DCCP_PARTOPEN];
dn->sysctl_table[3].data = &dn->dccp_timeout[CT_DCCP_OPEN];
dn->sysctl_table[4].data = &dn->dccp_timeout[CT_DCCP_CLOSEREQ];
dn->sysctl_table[5].data = &dn->dccp_timeout[CT_DCCP_CLOSING];
dn->sysctl_table[6].data = &dn->dccp_timeout[CT_DCCP_TIMEWAIT];
dn->sysctl_table[7].data = &dn->dccp_loose;
dn->sysctl_header = register_net_sysctl_table(net,
nf_net_netfilter_sysctl_path, dn->sysctl_table);
if (!dn->sysctl_header) {
kfree(dn->sysctl_table);
return -ENOMEM;
}
#endif
return 0;
}
static __net_exit void dccp_net_exit(struct net *net)
{
struct dccp_net *dn = dccp_pernet(net);
#ifdef CONFIG_SYSCTL
unregister_net_sysctl_table(dn->sysctl_header);
kfree(dn->sysctl_table);
#endif
}
static int __init nf_conntrack_proto_dccp_init(void)
{
int err;
err = register_pernet_subsys(&dccp_net_ops);
if (err < 0)
goto err1;
err = nf_conntrack_l4proto_register(&dccp_proto4);
if (err < 0)
goto err2;
err = nf_conntrack_l4proto_register(&dccp_proto6);
if (err < 0)
goto err3;
return 0;
err3:
nf_conntrack_l4proto_unregister(&dccp_proto4);
err2:
unregister_pernet_subsys(&dccp_net_ops);
err1:
return err;
}
static void __exit nf_conntrack_proto_dccp_fini(void)
{
unregister_pernet_subsys(&dccp_net_ops);
nf_conntrack_l4proto_unregister(&dccp_proto6);
nf_conntrack_l4proto_unregister(&dccp_proto4);
}
