static inline struct dccp_net *dccp_pernet(struct net *net)
{
return net_generic(net, dccp_net_id);
}
static bool dccp_pkt_to_tuple(const struct sk_buff *skb, unsigned int dataoff,
struct net *net, struct nf_conntrack_tuple *tuple)
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
unsigned int dataoff, unsigned int *timeouts)
{
struct net *net = nf_ct_net(ct);
struct dccp_net *dn;
struct dccp_hdr _dh, *dh;
const char *msg;
u_int8_t state;
dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
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
nf_log_packet(net, nf_ct_l3num(ct), 0, skb, NULL, NULL,
NULL, "%s", msg);
return false;
}
static u64 dccp_ack_seq(const struct dccp_hdr *dh)
{
const struct dccp_hdr_ack_bits *dhack;
dhack = (void *)dh + __dccp_basic_hdr_len(dh);
return ((u64)ntohs(dhack->dccph_ack_nr_high) << 32) +
ntohl(dhack->dccph_ack_nr_low);
}
static unsigned int *dccp_get_timeouts(struct net *net)
{
return dccp_pernet(net)->dccp_timeout;
}
static int dccp_packet(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, enum ip_conntrack_info ctinfo,
u_int8_t pf, unsigned int hooknum,
unsigned int *timeouts)
{
struct net *net = nf_ct_net(ct);
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
struct dccp_hdr _dh, *dh;
u_int8_t type, old_state, new_state;
enum ct_dccp_roles role;
dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
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
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_dccp: invalid packet ignored ");
return NF_ACCEPT;
case CT_DCCP_INVALID:
spin_unlock_bh(&ct->lock);
if (LOG_INVALID(net, IPPROTO_DCCP))
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL,
"nf_ct_dccp: invalid state transition ");
return -NF_ACCEPT;
}
ct->proto.dccp.last_dir = dir;
ct->proto.dccp.last_pkt = type;
ct->proto.dccp.state = new_state;
spin_unlock_bh(&ct->lock);
if (new_state != old_state)
nf_conntrack_event_cache(IPCT_PROTOINFO, ct);
nf_ct_refresh_acct(ct, ctinfo, skb, timeouts[new_state]);
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
dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
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
nf_log_packet(net, pf, 0, skb, NULL, NULL, NULL, "%s", msg);
return -NF_ACCEPT;
}
static void dccp_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
seq_printf(s, "sport=%hu dport=%hu ",
ntohs(tuple->src.u.dccp.port),
ntohs(tuple->dst.u.dccp.port));
}
static void dccp_print_conntrack(struct seq_file *s, struct nf_conn *ct)
{
seq_printf(s, "%s ", dccp_state_names[ct->proto.dccp.state]);
}
static int dccp_to_nlattr(struct sk_buff *skb, struct nlattr *nla,
struct nf_conn *ct)
{
struct nlattr *nest_parms;
spin_lock_bh(&ct->lock);
nest_parms = nla_nest_start(skb, CTA_PROTOINFO_DCCP | NLA_F_NESTED);
if (!nest_parms)
goto nla_put_failure;
if (nla_put_u8(skb, CTA_PROTOINFO_DCCP_STATE, ct->proto.dccp.state) ||
nla_put_u8(skb, CTA_PROTOINFO_DCCP_ROLE,
ct->proto.dccp.role[IP_CT_DIR_ORIGINAL]) ||
nla_put_be64(skb, CTA_PROTOINFO_DCCP_HANDSHAKE_SEQ,
cpu_to_be64(ct->proto.dccp.handshake_seq)))
goto nla_put_failure;
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
static int dccp_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
struct dccp_net *dn = dccp_pernet(net);
unsigned int *timeouts = data;
int i;
for (i=0; i<CT_DCCP_MAX; i++)
timeouts[i] = dn->dccp_timeout[i];
for (i=CTA_TIMEOUT_DCCP_UNSPEC+1; i<CTA_TIMEOUT_DCCP_MAX+1; i++) {
if (tb[i]) {
timeouts[i] = ntohl(nla_get_be32(tb[i])) * HZ;
}
}
return 0;
}
static int
dccp_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeouts = data;
int i;
for (i=CTA_TIMEOUT_DCCP_UNSPEC+1; i<CTA_TIMEOUT_DCCP_MAX+1; i++) {
if (nla_put_be32(skb, i, htonl(timeouts[i] / HZ)))
goto nla_put_failure;
}
return 0;
nla_put_failure:
return -ENOSPC;
}
static int dccp_kmemdup_sysctl_table(struct net *net, struct nf_proto_net *pn,
struct dccp_net *dn)
{
#ifdef CONFIG_SYSCTL
if (pn->ctl_table)
return 0;
pn->ctl_table = kmemdup(dccp_sysctl_table,
sizeof(dccp_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_table)
return -ENOMEM;
pn->ctl_table[0].data = &dn->dccp_timeout[CT_DCCP_REQUEST];
pn->ctl_table[1].data = &dn->dccp_timeout[CT_DCCP_RESPOND];
pn->ctl_table[2].data = &dn->dccp_timeout[CT_DCCP_PARTOPEN];
pn->ctl_table[3].data = &dn->dccp_timeout[CT_DCCP_OPEN];
pn->ctl_table[4].data = &dn->dccp_timeout[CT_DCCP_CLOSEREQ];
pn->ctl_table[5].data = &dn->dccp_timeout[CT_DCCP_CLOSING];
pn->ctl_table[6].data = &dn->dccp_timeout[CT_DCCP_TIMEWAIT];
pn->ctl_table[7].data = &dn->dccp_loose;
if (net->user_ns != &init_user_ns)
pn->ctl_table[0].procname = NULL;
#endif
return 0;
}
static int dccp_init_net(struct net *net, u_int16_t proto)
{
struct dccp_net *dn = dccp_pernet(net);
struct nf_proto_net *pn = &dn->pn;
if (!pn->users) {
dn->dccp_loose = 1;
dn->dccp_timeout[CT_DCCP_REQUEST] = 2 * DCCP_MSL;
dn->dccp_timeout[CT_DCCP_RESPOND] = 4 * DCCP_MSL;
dn->dccp_timeout[CT_DCCP_PARTOPEN] = 4 * DCCP_MSL;
dn->dccp_timeout[CT_DCCP_OPEN] = 12 * 3600 * HZ;
dn->dccp_timeout[CT_DCCP_CLOSEREQ] = 64 * HZ;
dn->dccp_timeout[CT_DCCP_CLOSING] = 64 * HZ;
dn->dccp_timeout[CT_DCCP_TIMEWAIT] = 2 * DCCP_MSL;
}
return dccp_kmemdup_sysctl_table(net, pn, dn);
}
static __net_init int dccp_net_init(struct net *net)
{
int ret = 0;
ret = nf_ct_l4proto_pernet_register(net, &dccp_proto4);
if (ret < 0) {
pr_err("nf_conntrack_dccp4: pernet registration failed.\n");
goto out;
}
ret = nf_ct_l4proto_pernet_register(net, &dccp_proto6);
if (ret < 0) {
pr_err("nf_conntrack_dccp6: pernet registration failed.\n");
goto cleanup_dccp4;
}
return 0;
cleanup_dccp4:
nf_ct_l4proto_pernet_unregister(net, &dccp_proto4);
out:
return ret;
}
static __net_exit void dccp_net_exit(struct net *net)
{
nf_ct_l4proto_pernet_unregister(net, &dccp_proto6);
nf_ct_l4proto_pernet_unregister(net, &dccp_proto4);
}
static int __init nf_conntrack_proto_dccp_init(void)
{
int ret;
ret = register_pernet_subsys(&dccp_net_ops);
if (ret < 0)
goto out_pernet;
ret = nf_ct_l4proto_register(&dccp_proto4);
if (ret < 0)
goto out_dccp4;
ret = nf_ct_l4proto_register(&dccp_proto6);
if (ret < 0)
goto out_dccp6;
return 0;
out_dccp6:
nf_ct_l4proto_unregister(&dccp_proto4);
out_dccp4:
unregister_pernet_subsys(&dccp_net_ops);
out_pernet:
return ret;
}
static void __exit nf_conntrack_proto_dccp_fini(void)
{
nf_ct_l4proto_unregister(&dccp_proto6);
nf_ct_l4proto_unregister(&dccp_proto4);
unregister_pernet_subsys(&dccp_net_ops);
}
