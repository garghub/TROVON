int ife_encode_meta_u16(u16 metaval, void *skbdata, struct tcf_meta_info *mi)
{
u16 edata = 0;
if (mi->metaval)
edata = *(u16 *)mi->metaval;
else if (metaval)
edata = metaval;
if (!edata)
return 0;
edata = htons(edata);
return ife_tlv_meta_encode(skbdata, mi->metaid, 2, &edata);
}
int ife_get_meta_u32(struct sk_buff *skb, struct tcf_meta_info *mi)
{
if (mi->metaval)
return nla_put_u32(skb, mi->metaid, *(u32 *)mi->metaval);
else
return nla_put(skb, mi->metaid, 0, NULL);
}
int ife_check_meta_u32(u32 metaval, struct tcf_meta_info *mi)
{
if (metaval || mi->metaval)
return 8;
return 0;
}
int ife_check_meta_u16(u16 metaval, struct tcf_meta_info *mi)
{
if (metaval || mi->metaval)
return 8;
return 0;
}
int ife_encode_meta_u32(u32 metaval, void *skbdata, struct tcf_meta_info *mi)
{
u32 edata = metaval;
if (mi->metaval)
edata = *(u32 *)mi->metaval;
else if (metaval)
edata = metaval;
if (!edata)
return 0;
edata = htonl(edata);
return ife_tlv_meta_encode(skbdata, mi->metaid, 4, &edata);
}
int ife_get_meta_u16(struct sk_buff *skb, struct tcf_meta_info *mi)
{
if (mi->metaval)
return nla_put_u16(skb, mi->metaid, *(u16 *)mi->metaval);
else
return nla_put(skb, mi->metaid, 0, NULL);
}
int ife_alloc_meta_u32(struct tcf_meta_info *mi, void *metaval, gfp_t gfp)
{
mi->metaval = kmemdup(metaval, sizeof(u32), gfp);
if (!mi->metaval)
return -ENOMEM;
return 0;
}
int ife_alloc_meta_u16(struct tcf_meta_info *mi, void *metaval, gfp_t gfp)
{
mi->metaval = kmemdup(metaval, sizeof(u16), gfp);
if (!mi->metaval)
return -ENOMEM;
return 0;
}
void ife_release_meta_gen(struct tcf_meta_info *mi)
{
kfree(mi->metaval);
}
int ife_validate_meta_u32(void *val, int len)
{
if (len == sizeof(u32))
return 0;
return -EINVAL;
}
int ife_validate_meta_u16(void *val, int len)
{
if (len == sizeof(u16))
return 0;
return -EINVAL;
}
static struct tcf_meta_ops *find_ife_oplist(u16 metaid)
{
struct tcf_meta_ops *o;
read_lock(&ife_mod_lock);
list_for_each_entry(o, &ifeoplist, list) {
if (o->metaid == metaid) {
if (!try_module_get(o->owner))
o = NULL;
read_unlock(&ife_mod_lock);
return o;
}
}
read_unlock(&ife_mod_lock);
return NULL;
}
int register_ife_op(struct tcf_meta_ops *mops)
{
struct tcf_meta_ops *m;
if (!mops->metaid || !mops->metatype || !mops->name ||
!mops->check_presence || !mops->encode || !mops->decode ||
!mops->get || !mops->alloc)
return -EINVAL;
write_lock(&ife_mod_lock);
list_for_each_entry(m, &ifeoplist, list) {
if (m->metaid == mops->metaid ||
(strcmp(mops->name, m->name) == 0)) {
write_unlock(&ife_mod_lock);
return -EEXIST;
}
}
if (!mops->release)
mops->release = ife_release_meta_gen;
list_add_tail(&mops->list, &ifeoplist);
write_unlock(&ife_mod_lock);
return 0;
}
int unregister_ife_op(struct tcf_meta_ops *mops)
{
struct tcf_meta_ops *m;
int err = -ENOENT;
write_lock(&ife_mod_lock);
list_for_each_entry(m, &ifeoplist, list) {
if (m->metaid == mops->metaid) {
list_del(&mops->list);
err = 0;
break;
}
}
write_unlock(&ife_mod_lock);
return err;
}
static int ife_validate_metatype(struct tcf_meta_ops *ops, void *val, int len)
{
int ret = 0;
if (ops->validate)
return ops->validate(val, len);
if (ops->metatype == NLA_U32)
ret = ife_validate_meta_u32(val, len);
else if (ops->metatype == NLA_U16)
ret = ife_validate_meta_u16(val, len);
return ret;
}
static int load_metaops_and_vet(struct tcf_ife_info *ife, u32 metaid,
void *val, int len, bool exists)
{
struct tcf_meta_ops *ops = find_ife_oplist(metaid);
int ret = 0;
if (!ops) {
ret = -ENOENT;
#ifdef CONFIG_MODULES
if (exists)
spin_unlock_bh(&ife->tcf_lock);
rtnl_unlock();
request_module("ifemeta%u", metaid);
rtnl_lock();
if (exists)
spin_lock_bh(&ife->tcf_lock);
ops = find_ife_oplist(metaid);
#endif
}
if (ops) {
ret = 0;
if (len)
ret = ife_validate_metatype(ops, val, len);
module_put(ops->owner);
}
return ret;
}
static int add_metainfo(struct tcf_ife_info *ife, u32 metaid, void *metaval,
int len, bool atomic)
{
struct tcf_meta_info *mi = NULL;
struct tcf_meta_ops *ops = find_ife_oplist(metaid);
int ret = 0;
if (!ops)
return -ENOENT;
mi = kzalloc(sizeof(*mi), atomic ? GFP_ATOMIC : GFP_KERNEL);
if (!mi) {
module_put(ops->owner);
return -ENOMEM;
}
mi->metaid = metaid;
mi->ops = ops;
if (len > 0) {
ret = ops->alloc(mi, metaval, atomic ? GFP_ATOMIC : GFP_KERNEL);
if (ret != 0) {
kfree(mi);
module_put(ops->owner);
return ret;
}
}
list_add_tail(&mi->metalist, &ife->metalist);
return ret;
}
static int use_all_metadata(struct tcf_ife_info *ife)
{
struct tcf_meta_ops *o;
int rc = 0;
int installed = 0;
read_lock(&ife_mod_lock);
list_for_each_entry(o, &ifeoplist, list) {
rc = add_metainfo(ife, o->metaid, NULL, 0, true);
if (rc == 0)
installed += 1;
}
read_unlock(&ife_mod_lock);
if (installed)
return 0;
else
return -EINVAL;
}
static int dump_metalist(struct sk_buff *skb, struct tcf_ife_info *ife)
{
struct tcf_meta_info *e;
struct nlattr *nest;
unsigned char *b = skb_tail_pointer(skb);
int total_encoded = 0;
if (list_empty(&ife->metalist))
return 0;
nest = nla_nest_start(skb, TCA_IFE_METALST);
if (!nest)
goto out_nlmsg_trim;
list_for_each_entry(e, &ife->metalist, metalist) {
if (!e->ops->get(skb, e))
total_encoded += 1;
}
if (!total_encoded)
goto out_nlmsg_trim;
nla_nest_end(skb, nest);
return 0;
out_nlmsg_trim:
nlmsg_trim(skb, b);
return -1;
}
static void _tcf_ife_cleanup(struct tc_action *a, int bind)
{
struct tcf_ife_info *ife = to_ife(a);
struct tcf_meta_info *e, *n;
list_for_each_entry_safe(e, n, &ife->metalist, metalist) {
module_put(e->ops->owner);
list_del(&e->metalist);
if (e->metaval) {
if (e->ops->release)
e->ops->release(e);
else
kfree(e->metaval);
}
kfree(e);
}
}
static void tcf_ife_cleanup(struct tc_action *a, int bind)
{
struct tcf_ife_info *ife = to_ife(a);
spin_lock_bh(&ife->tcf_lock);
_tcf_ife_cleanup(a, bind);
spin_unlock_bh(&ife->tcf_lock);
}
static int populate_metalist(struct tcf_ife_info *ife, struct nlattr **tb,
bool exists)
{
int len = 0;
int rc = 0;
int i = 0;
void *val;
for (i = 1; i < max_metacnt; i++) {
if (tb[i]) {
val = nla_data(tb[i]);
len = nla_len(tb[i]);
rc = load_metaops_and_vet(ife, i, val, len, exists);
if (rc != 0)
return rc;
rc = add_metainfo(ife, i, val, len, exists);
if (rc)
return rc;
}
}
return rc;
}
static int tcf_ife_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action **a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
struct nlattr *tb[TCA_IFE_MAX + 1];
struct nlattr *tb2[IFE_META_MAX + 1];
struct tcf_ife_info *ife;
u16 ife_type = ETH_P_IFE;
struct tc_ife *parm;
u8 *daddr = NULL;
u8 *saddr = NULL;
bool exists = false;
int ret = 0;
int err;
err = nla_parse_nested(tb, TCA_IFE_MAX, nla, ife_policy, NULL);
if (err < 0)
return err;
if (!tb[TCA_IFE_PARMS])
return -EINVAL;
parm = nla_data(tb[TCA_IFE_PARMS]);
exists = tcf_idr_check(tn, parm->index, a, bind);
if (exists && bind)
return 0;
if (!exists) {
ret = tcf_idr_create(tn, parm->index, est, a, &act_ife_ops,
bind, false);
if (ret)
return ret;
ret = ACT_P_CREATED;
} else {
tcf_idr_release(*a, bind);
if (!ovr)
return -EEXIST;
}
ife = to_ife(*a);
ife->flags = parm->flags;
if (parm->flags & IFE_ENCODE) {
if (tb[TCA_IFE_TYPE])
ife_type = nla_get_u16(tb[TCA_IFE_TYPE]);
if (tb[TCA_IFE_DMAC])
daddr = nla_data(tb[TCA_IFE_DMAC]);
if (tb[TCA_IFE_SMAC])
saddr = nla_data(tb[TCA_IFE_SMAC]);
}
if (exists)
spin_lock_bh(&ife->tcf_lock);
ife->tcf_action = parm->action;
if (parm->flags & IFE_ENCODE) {
if (daddr)
ether_addr_copy(ife->eth_dst, daddr);
else
eth_zero_addr(ife->eth_dst);
if (saddr)
ether_addr_copy(ife->eth_src, saddr);
else
eth_zero_addr(ife->eth_src);
ife->eth_type = ife_type;
}
if (ret == ACT_P_CREATED)
INIT_LIST_HEAD(&ife->metalist);
if (tb[TCA_IFE_METALST]) {
err = nla_parse_nested(tb2, IFE_META_MAX, tb[TCA_IFE_METALST],
NULL, NULL);
if (err) {
metadata_parse_err:
if (exists)
tcf_idr_release(*a, bind);
if (ret == ACT_P_CREATED)
_tcf_ife_cleanup(*a, bind);
if (exists)
spin_unlock_bh(&ife->tcf_lock);
return err;
}
err = populate_metalist(ife, tb2, exists);
if (err)
goto metadata_parse_err;
} else {
err = use_all_metadata(ife);
if (err) {
if (ret == ACT_P_CREATED)
_tcf_ife_cleanup(*a, bind);
if (exists)
spin_unlock_bh(&ife->tcf_lock);
return err;
}
}
if (exists)
spin_unlock_bh(&ife->tcf_lock);
if (ret == ACT_P_CREATED)
tcf_idr_insert(tn, *a);
return ret;
}
static int tcf_ife_dump(struct sk_buff *skb, struct tc_action *a, int bind,
int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_ife_info *ife = to_ife(a);
struct tc_ife opt = {
.index = ife->tcf_index,
.refcnt = ife->tcf_refcnt - ref,
.bindcnt = ife->tcf_bindcnt - bind,
.action = ife->tcf_action,
.flags = ife->flags,
};
struct tcf_t t;
if (nla_put(skb, TCA_IFE_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
tcf_tm_dump(&t, &ife->tcf_tm);
if (nla_put_64bit(skb, TCA_IFE_TM, sizeof(t), &t, TCA_IFE_PAD))
goto nla_put_failure;
if (!is_zero_ether_addr(ife->eth_dst)) {
if (nla_put(skb, TCA_IFE_DMAC, ETH_ALEN, ife->eth_dst))
goto nla_put_failure;
}
if (!is_zero_ether_addr(ife->eth_src)) {
if (nla_put(skb, TCA_IFE_SMAC, ETH_ALEN, ife->eth_src))
goto nla_put_failure;
}
if (nla_put(skb, TCA_IFE_TYPE, 2, &ife->eth_type))
goto nla_put_failure;
if (dump_metalist(skb, ife)) {
pr_info("Failed to dump metalist\n");
}
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static int find_decode_metaid(struct sk_buff *skb, struct tcf_ife_info *ife,
u16 metaid, u16 mlen, void *mdata)
{
struct tcf_meta_info *e;
list_for_each_entry(e, &ife->metalist, metalist) {
if (metaid == e->metaid) {
if (e->ops) {
return e->ops->decode(skb, mdata, mlen);
}
}
}
return 0;
}
static int tcf_ife_decode(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_ife_info *ife = to_ife(a);
int action = ife->tcf_action;
u8 *ifehdr_end;
u8 *tlv_data;
u16 metalen;
spin_lock(&ife->tcf_lock);
bstats_update(&ife->tcf_bstats, skb);
tcf_lastuse_update(&ife->tcf_tm);
spin_unlock(&ife->tcf_lock);
if (skb_at_tc_ingress(skb))
skb_push(skb, skb->dev->hard_header_len);
tlv_data = ife_decode(skb, &metalen);
if (unlikely(!tlv_data)) {
spin_lock(&ife->tcf_lock);
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
ifehdr_end = tlv_data + metalen;
for (; tlv_data < ifehdr_end; tlv_data = ife_tlv_meta_next(tlv_data)) {
u8 *curr_data;
u16 mtype;
u16 dlen;
curr_data = ife_tlv_meta_decode(tlv_data, &mtype, &dlen, NULL);
if (find_decode_metaid(skb, ife, mtype, dlen, curr_data)) {
pr_info_ratelimited("Unknown metaid %d dlen %d\n",
mtype, dlen);
ife->tcf_qstats.overlimits++;
}
}
if (WARN_ON(tlv_data != ifehdr_end)) {
spin_lock(&ife->tcf_lock);
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
skb->protocol = eth_type_trans(skb, skb->dev);
skb_reset_network_header(skb);
return action;
}
static int ife_get_sz(struct sk_buff *skb, struct tcf_ife_info *ife)
{
struct tcf_meta_info *e, *n;
int tot_run_sz = 0, run_sz = 0;
list_for_each_entry_safe(e, n, &ife->metalist, metalist) {
if (e->ops->check_presence) {
run_sz = e->ops->check_presence(skb, e);
tot_run_sz += run_sz;
}
}
return tot_run_sz;
}
static int tcf_ife_encode(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_ife_info *ife = to_ife(a);
int action = ife->tcf_action;
struct ethhdr *oethh;
struct tcf_meta_info *e;
u16 metalen = ife_get_sz(skb, ife);
int hdrm = metalen + skb->dev->hard_header_len + IFE_METAHDRLEN;
unsigned int skboff = 0;
int new_len = skb->len + hdrm;
bool exceed_mtu = false;
void *ife_meta;
int err = 0;
if (!skb_at_tc_ingress(skb)) {
if (new_len > skb->dev->mtu)
exceed_mtu = true;
}
spin_lock(&ife->tcf_lock);
bstats_update(&ife->tcf_bstats, skb);
tcf_lastuse_update(&ife->tcf_tm);
if (!metalen) {
ife->tcf_qstats.overlimits++;
spin_unlock(&ife->tcf_lock);
return action;
}
if ((action == TC_ACT_SHOT) || exceed_mtu) {
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
if (skb_at_tc_ingress(skb))
skb_push(skb, skb->dev->hard_header_len);
ife_meta = ife_encode(skb, metalen);
list_for_each_entry(e, &ife->metalist, metalist) {
if (e->ops->encode) {
err = e->ops->encode(skb, (void *)(ife_meta + skboff),
e);
}
if (err < 0) {
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
skboff += err;
}
oethh = (struct ethhdr *)skb->data;
if (!is_zero_ether_addr(ife->eth_src))
ether_addr_copy(oethh->h_source, ife->eth_src);
if (!is_zero_ether_addr(ife->eth_dst))
ether_addr_copy(oethh->h_dest, ife->eth_dst);
oethh->h_proto = htons(ife->eth_type);
if (skb_at_tc_ingress(skb))
skb_pull(skb, skb->dev->hard_header_len);
spin_unlock(&ife->tcf_lock);
return action;
}
static int tcf_ife_act(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_ife_info *ife = to_ife(a);
if (ife->flags & IFE_ENCODE)
return tcf_ife_encode(skb, a, res);
if (!(ife->flags & IFE_ENCODE))
return tcf_ife_decode(skb, a, res);
pr_info_ratelimited("unknown failure(policy neither de/encode\n");
spin_lock(&ife->tcf_lock);
bstats_update(&ife->tcf_bstats, skb);
tcf_lastuse_update(&ife->tcf_tm);
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
static int tcf_ife_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
const struct tc_action_ops *ops)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
return tcf_generic_walker(tn, skb, cb, type, ops);
}
static int tcf_ife_search(struct net *net, struct tc_action **a, u32 index)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
return tcf_idr_search(tn, a, index);
}
static __net_init int ife_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
return tc_action_net_init(tn, &act_ife_ops);
}
static void __net_exit ife_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
tc_action_net_exit(tn);
}
static int __init ife_init_module(void)
{
return tcf_register_action(&act_ife_ops, &ife_net_ops);
}
static void __exit ife_cleanup_module(void)
{
tcf_unregister_action(&act_ife_ops, &ife_net_ops);
}
