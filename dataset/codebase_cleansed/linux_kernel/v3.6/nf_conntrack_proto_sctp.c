static inline struct sctp_net *sctp_pernet(struct net *net)
{
return net_generic(net, sctp_net_id);
}
static bool sctp_pkt_to_tuple(const struct sk_buff *skb, unsigned int dataoff,
struct nf_conntrack_tuple *tuple)
{
const struct sctphdr *hp;
struct sctphdr _hdr;
hp = skb_header_pointer(skb, dataoff, 8, &_hdr);
if (hp == NULL)
return false;
tuple->src.u.sctp.port = hp->source;
tuple->dst.u.sctp.port = hp->dest;
return true;
}
static bool sctp_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
tuple->src.u.sctp.port = orig->dst.u.sctp.port;
tuple->dst.u.sctp.port = orig->src.u.sctp.port;
return true;
}
static int sctp_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
return seq_printf(s, "sport=%hu dport=%hu ",
ntohs(tuple->src.u.sctp.port),
ntohs(tuple->dst.u.sctp.port));
}
static int sctp_print_conntrack(struct seq_file *s, struct nf_conn *ct)
{
enum sctp_conntrack state;
spin_lock_bh(&ct->lock);
state = ct->proto.sctp.state;
spin_unlock_bh(&ct->lock);
return seq_printf(s, "%s ", sctp_conntrack_names[state]);
}
static int do_basic_checks(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
unsigned long *map)
{
u_int32_t offset, count;
sctp_chunkhdr_t _sch, *sch;
int flag;
flag = 0;
for_each_sctp_chunk (skb, sch, _sch, offset, dataoff, count) {
pr_debug("Chunk Num: %d Type: %d\n", count, sch->type);
if (sch->type == SCTP_CID_INIT ||
sch->type == SCTP_CID_INIT_ACK ||
sch->type == SCTP_CID_SHUTDOWN_COMPLETE)
flag = 1;
if (((sch->type == SCTP_CID_COOKIE_ACK ||
sch->type == SCTP_CID_COOKIE_ECHO ||
flag) &&
count != 0) || !sch->length) {
pr_debug("Basic checks failed\n");
return 1;
}
if (map)
set_bit(sch->type, map);
}
pr_debug("Basic checks passed\n");
return count == 0;
}
static int sctp_new_state(enum ip_conntrack_dir dir,
enum sctp_conntrack cur_state,
int chunk_type)
{
int i;
pr_debug("Chunk type: %d\n", chunk_type);
switch (chunk_type) {
case SCTP_CID_INIT:
pr_debug("SCTP_CID_INIT\n");
i = 0;
break;
case SCTP_CID_INIT_ACK:
pr_debug("SCTP_CID_INIT_ACK\n");
i = 1;
break;
case SCTP_CID_ABORT:
pr_debug("SCTP_CID_ABORT\n");
i = 2;
break;
case SCTP_CID_SHUTDOWN:
pr_debug("SCTP_CID_SHUTDOWN\n");
i = 3;
break;
case SCTP_CID_SHUTDOWN_ACK:
pr_debug("SCTP_CID_SHUTDOWN_ACK\n");
i = 4;
break;
case SCTP_CID_ERROR:
pr_debug("SCTP_CID_ERROR\n");
i = 5;
break;
case SCTP_CID_COOKIE_ECHO:
pr_debug("SCTP_CID_COOKIE_ECHO\n");
i = 6;
break;
case SCTP_CID_COOKIE_ACK:
pr_debug("SCTP_CID_COOKIE_ACK\n");
i = 7;
break;
case SCTP_CID_SHUTDOWN_COMPLETE:
pr_debug("SCTP_CID_SHUTDOWN_COMPLETE\n");
i = 8;
break;
default:
pr_debug("Unknown chunk type, Will stay in %s\n",
sctp_conntrack_names[cur_state]);
return cur_state;
}
pr_debug("dir: %d cur_state: %s chunk_type: %d new_state: %s\n",
dir, sctp_conntrack_names[cur_state], chunk_type,
sctp_conntrack_names[sctp_conntracks[dir][i][cur_state]]);
return sctp_conntracks[dir][i][cur_state];
}
static unsigned int *sctp_get_timeouts(struct net *net)
{
return sctp_pernet(net)->timeouts;
}
static int sctp_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum,
unsigned int *timeouts)
{
enum sctp_conntrack new_state, old_state;
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
const struct sctphdr *sh;
struct sctphdr _sctph;
const struct sctp_chunkhdr *sch;
struct sctp_chunkhdr _sch;
u_int32_t offset, count;
unsigned long map[256 / sizeof(unsigned long)] = { 0 };
sh = skb_header_pointer(skb, dataoff, sizeof(_sctph), &_sctph);
if (sh == NULL)
goto out;
if (do_basic_checks(ct, skb, dataoff, map) != 0)
goto out;
if (!test_bit(SCTP_CID_INIT, map) &&
!test_bit(SCTP_CID_SHUTDOWN_COMPLETE, map) &&
!test_bit(SCTP_CID_COOKIE_ECHO, map) &&
!test_bit(SCTP_CID_ABORT, map) &&
!test_bit(SCTP_CID_SHUTDOWN_ACK, map) &&
sh->vtag != ct->proto.sctp.vtag[dir]) {
pr_debug("Verification tag check failed\n");
goto out;
}
old_state = new_state = SCTP_CONNTRACK_NONE;
spin_lock_bh(&ct->lock);
for_each_sctp_chunk (skb, sch, _sch, offset, dataoff, count) {
if (sch->type == SCTP_CID_INIT) {
if (sh->vtag != 0)
goto out_unlock;
} else if (sch->type == SCTP_CID_ABORT) {
if (sh->vtag != ct->proto.sctp.vtag[dir] &&
sh->vtag != ct->proto.sctp.vtag[!dir])
goto out_unlock;
} else if (sch->type == SCTP_CID_SHUTDOWN_COMPLETE) {
if (sh->vtag != ct->proto.sctp.vtag[dir] &&
sh->vtag != ct->proto.sctp.vtag[!dir] &&
sch->flags & SCTP_CHUNK_FLAG_T)
goto out_unlock;
} else if (sch->type == SCTP_CID_COOKIE_ECHO) {
if (sh->vtag != ct->proto.sctp.vtag[dir])
goto out_unlock;
}
old_state = ct->proto.sctp.state;
new_state = sctp_new_state(dir, old_state, sch->type);
if (new_state == SCTP_CONNTRACK_MAX) {
pr_debug("nf_conntrack_sctp: Invalid dir=%i ctype=%u "
"conntrack=%u\n",
dir, sch->type, old_state);
goto out_unlock;
}
if (sch->type == SCTP_CID_INIT ||
sch->type == SCTP_CID_INIT_ACK) {
sctp_inithdr_t _inithdr, *ih;
ih = skb_header_pointer(skb, offset + sizeof(sctp_chunkhdr_t),
sizeof(_inithdr), &_inithdr);
if (ih == NULL)
goto out_unlock;
pr_debug("Setting vtag %x for dir %d\n",
ih->init_tag, !dir);
ct->proto.sctp.vtag[!dir] = ih->init_tag;
}
ct->proto.sctp.state = new_state;
if (old_state != new_state)
nf_conntrack_event_cache(IPCT_PROTOINFO, ct);
}
spin_unlock_bh(&ct->lock);
nf_ct_refresh_acct(ct, ctinfo, skb, timeouts[new_state]);
if (old_state == SCTP_CONNTRACK_COOKIE_ECHOED &&
dir == IP_CT_DIR_REPLY &&
new_state == SCTP_CONNTRACK_ESTABLISHED) {
pr_debug("Setting assured bit\n");
set_bit(IPS_ASSURED_BIT, &ct->status);
nf_conntrack_event_cache(IPCT_ASSURED, ct);
}
return NF_ACCEPT;
out_unlock:
spin_unlock_bh(&ct->lock);
out:
return -NF_ACCEPT;
}
static bool sctp_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, unsigned int *timeouts)
{
enum sctp_conntrack new_state;
const struct sctphdr *sh;
struct sctphdr _sctph;
const struct sctp_chunkhdr *sch;
struct sctp_chunkhdr _sch;
u_int32_t offset, count;
unsigned long map[256 / sizeof(unsigned long)] = { 0 };
sh = skb_header_pointer(skb, dataoff, sizeof(_sctph), &_sctph);
if (sh == NULL)
return false;
if (do_basic_checks(ct, skb, dataoff, map) != 0)
return false;
if (test_bit(SCTP_CID_ABORT, map) ||
test_bit(SCTP_CID_SHUTDOWN_COMPLETE, map) ||
test_bit(SCTP_CID_COOKIE_ACK, map))
return false;
memset(&ct->proto.sctp, 0, sizeof(ct->proto.sctp));
new_state = SCTP_CONNTRACK_MAX;
for_each_sctp_chunk (skb, sch, _sch, offset, dataoff, count) {
new_state = sctp_new_state(IP_CT_DIR_ORIGINAL,
SCTP_CONNTRACK_NONE, sch->type);
if (new_state == SCTP_CONNTRACK_NONE ||
new_state == SCTP_CONNTRACK_MAX) {
pr_debug("nf_conntrack_sctp: invalid new deleting.\n");
return false;
}
if (sch->type == SCTP_CID_INIT) {
if (sh->vtag == 0) {
sctp_inithdr_t _inithdr, *ih;
ih = skb_header_pointer(skb, offset + sizeof(sctp_chunkhdr_t),
sizeof(_inithdr), &_inithdr);
if (ih == NULL)
return false;
pr_debug("Setting vtag %x for new conn\n",
ih->init_tag);
ct->proto.sctp.vtag[IP_CT_DIR_REPLY] =
ih->init_tag;
} else {
return false;
}
}
else {
pr_debug("Setting vtag %x for new conn OOTB\n",
sh->vtag);
ct->proto.sctp.vtag[IP_CT_DIR_REPLY] = sh->vtag;
}
ct->proto.sctp.state = new_state;
}
return true;
}
static int sctp_to_nlattr(struct sk_buff *skb, struct nlattr *nla,
struct nf_conn *ct)
{
struct nlattr *nest_parms;
spin_lock_bh(&ct->lock);
nest_parms = nla_nest_start(skb, CTA_PROTOINFO_SCTP | NLA_F_NESTED);
if (!nest_parms)
goto nla_put_failure;
if (nla_put_u8(skb, CTA_PROTOINFO_SCTP_STATE, ct->proto.sctp.state) ||
nla_put_be32(skb, CTA_PROTOINFO_SCTP_VTAG_ORIGINAL,
ct->proto.sctp.vtag[IP_CT_DIR_ORIGINAL]) ||
nla_put_be32(skb, CTA_PROTOINFO_SCTP_VTAG_REPLY,
ct->proto.sctp.vtag[IP_CT_DIR_REPLY]))
goto nla_put_failure;
spin_unlock_bh(&ct->lock);
nla_nest_end(skb, nest_parms);
return 0;
nla_put_failure:
spin_unlock_bh(&ct->lock);
return -1;
}
static int nlattr_to_sctp(struct nlattr *cda[], struct nf_conn *ct)
{
struct nlattr *attr = cda[CTA_PROTOINFO_SCTP];
struct nlattr *tb[CTA_PROTOINFO_SCTP_MAX+1];
int err;
if (!attr)
return 0;
err = nla_parse_nested(tb,
CTA_PROTOINFO_SCTP_MAX,
attr,
sctp_nla_policy);
if (err < 0)
return err;
if (!tb[CTA_PROTOINFO_SCTP_STATE] ||
!tb[CTA_PROTOINFO_SCTP_VTAG_ORIGINAL] ||
!tb[CTA_PROTOINFO_SCTP_VTAG_REPLY])
return -EINVAL;
spin_lock_bh(&ct->lock);
ct->proto.sctp.state = nla_get_u8(tb[CTA_PROTOINFO_SCTP_STATE]);
ct->proto.sctp.vtag[IP_CT_DIR_ORIGINAL] =
nla_get_be32(tb[CTA_PROTOINFO_SCTP_VTAG_ORIGINAL]);
ct->proto.sctp.vtag[IP_CT_DIR_REPLY] =
nla_get_be32(tb[CTA_PROTOINFO_SCTP_VTAG_REPLY]);
spin_unlock_bh(&ct->lock);
return 0;
}
static int sctp_nlattr_size(void)
{
return nla_total_size(0)
+ nla_policy_len(sctp_nla_policy, CTA_PROTOINFO_SCTP_MAX + 1);
}
static int sctp_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
unsigned int *timeouts = data;
struct sctp_net *sn = sctp_pernet(net);
int i;
for (i=0; i<SCTP_CONNTRACK_MAX; i++)
timeouts[i] = sn->timeouts[i];
for (i=CTA_TIMEOUT_SCTP_UNSPEC+1; i<CTA_TIMEOUT_SCTP_MAX+1; i++) {
if (tb[i]) {
timeouts[i] = ntohl(nla_get_be32(tb[i])) * HZ;
}
}
return 0;
}
static int
sctp_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeouts = data;
int i;
for (i=CTA_TIMEOUT_SCTP_UNSPEC+1; i<CTA_TIMEOUT_SCTP_MAX+1; i++) {
if (nla_put_be32(skb, i, htonl(timeouts[i] / HZ)))
goto nla_put_failure;
}
return 0;
nla_put_failure:
return -ENOSPC;
}
static int sctp_kmemdup_sysctl_table(struct nf_proto_net *pn,
struct sctp_net *sn)
{
#ifdef CONFIG_SYSCTL
if (pn->ctl_table)
return 0;
pn->ctl_table = kmemdup(sctp_sysctl_table,
sizeof(sctp_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_table)
return -ENOMEM;
pn->ctl_table[0].data = &sn->timeouts[SCTP_CONNTRACK_CLOSED];
pn->ctl_table[1].data = &sn->timeouts[SCTP_CONNTRACK_COOKIE_WAIT];
pn->ctl_table[2].data = &sn->timeouts[SCTP_CONNTRACK_COOKIE_ECHOED];
pn->ctl_table[3].data = &sn->timeouts[SCTP_CONNTRACK_ESTABLISHED];
pn->ctl_table[4].data = &sn->timeouts[SCTP_CONNTRACK_SHUTDOWN_SENT];
pn->ctl_table[5].data = &sn->timeouts[SCTP_CONNTRACK_SHUTDOWN_RECD];
pn->ctl_table[6].data = &sn->timeouts[SCTP_CONNTRACK_SHUTDOWN_ACK_SENT];
#endif
return 0;
}
static int sctp_kmemdup_compat_sysctl_table(struct nf_proto_net *pn,
struct sctp_net *sn)
{
#ifdef CONFIG_SYSCTL
#ifdef CONFIG_NF_CONNTRACK_PROC_COMPAT
pn->ctl_compat_table = kmemdup(sctp_compat_sysctl_table,
sizeof(sctp_compat_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_compat_table)
return -ENOMEM;
pn->ctl_compat_table[0].data = &sn->timeouts[SCTP_CONNTRACK_CLOSED];
pn->ctl_compat_table[1].data = &sn->timeouts[SCTP_CONNTRACK_COOKIE_WAIT];
pn->ctl_compat_table[2].data = &sn->timeouts[SCTP_CONNTRACK_COOKIE_ECHOED];
pn->ctl_compat_table[3].data = &sn->timeouts[SCTP_CONNTRACK_ESTABLISHED];
pn->ctl_compat_table[4].data = &sn->timeouts[SCTP_CONNTRACK_SHUTDOWN_SENT];
pn->ctl_compat_table[5].data = &sn->timeouts[SCTP_CONNTRACK_SHUTDOWN_RECD];
pn->ctl_compat_table[6].data = &sn->timeouts[SCTP_CONNTRACK_SHUTDOWN_ACK_SENT];
#endif
#endif
return 0;
}
static int sctp_init_net(struct net *net, u_int16_t proto)
{
int ret;
struct sctp_net *sn = sctp_pernet(net);
struct nf_proto_net *pn = &sn->pn;
if (!pn->users) {
int i;
for (i = 0; i < SCTP_CONNTRACK_MAX; i++)
sn->timeouts[i] = sctp_timeouts[i];
}
if (proto == AF_INET) {
ret = sctp_kmemdup_compat_sysctl_table(pn, sn);
if (ret < 0)
return ret;
ret = sctp_kmemdup_sysctl_table(pn, sn);
if (ret < 0)
nf_ct_kfree_compat_sysctl_table(pn);
} else
ret = sctp_kmemdup_sysctl_table(pn, sn);
return ret;
}
static int sctp_net_init(struct net *net)
{
int ret = 0;
ret = nf_conntrack_l4proto_register(net,
&nf_conntrack_l4proto_sctp4);
if (ret < 0) {
pr_err("nf_conntrack_l4proto_sctp4 :protocol register failed.\n");
goto out;
}
ret = nf_conntrack_l4proto_register(net,
&nf_conntrack_l4proto_sctp6);
if (ret < 0) {
pr_err("nf_conntrack_l4proto_sctp6 :protocol register failed.\n");
goto cleanup_sctp4;
}
return 0;
cleanup_sctp4:
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_sctp4);
out:
return ret;
}
static void sctp_net_exit(struct net *net)
{
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_sctp6);
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_sctp4);
}
static int __init nf_conntrack_proto_sctp_init(void)
{
return register_pernet_subsys(&sctp_net_ops);
}
static void __exit nf_conntrack_proto_sctp_fini(void)
{
unregister_pernet_subsys(&sctp_net_ops);
}
