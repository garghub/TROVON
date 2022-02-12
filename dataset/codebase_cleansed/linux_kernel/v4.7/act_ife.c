int ife_tlv_meta_encode(void *skbdata, u16 attrtype, u16 dlen, const void *dval)
{
u32 *tlv = (u32 *)(skbdata);
u16 totlen = nla_total_size(dlen);
char *dptr = (char *)tlv + NLA_HDRLEN;
u32 htlv = attrtype << 16 | totlen;
*tlv = htonl(htlv);
memset(dptr, 0, totlen - NLA_HDRLEN);
memcpy(dptr, dval, dlen);
return totlen;
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
if (len == 4)
return 0;
return -EINVAL;
}
int ife_validate_meta_u16(void *val, int len)
{
if (len == NLA_ALIGN(2))
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
struct tcf_ife_info *ife = a->priv;
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
struct tcf_ife_info *ife = a->priv;
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
struct nlattr *est, struct tc_action *a,
int ovr, int bind)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
struct nlattr *tb[TCA_IFE_MAX + 1];
struct nlattr *tb2[IFE_META_MAX + 1];
struct tcf_ife_info *ife;
struct tc_ife *parm;
u16 ife_type = 0;
u8 *daddr = NULL;
u8 *saddr = NULL;
int ret = 0, exists = 0;
int err;
err = nla_parse_nested(tb, TCA_IFE_MAX, nla, ife_policy);
if (err < 0)
return err;
if (!tb[TCA_IFE_PARMS])
return -EINVAL;
parm = nla_data(tb[TCA_IFE_PARMS]);
exists = tcf_hash_check(tn, parm->index, a, bind);
if (exists && bind)
return 0;
if (parm->flags & IFE_ENCODE) {
if (!tb[TCA_IFE_TYPE]) {
if (exists)
tcf_hash_release(a, bind);
pr_info("You MUST pass etherype for encoding\n");
return -EINVAL;
}
}
if (!exists) {
ret = tcf_hash_create(tn, parm->index, est, a, sizeof(*ife),
bind, false);
if (ret)
return ret;
ret = ACT_P_CREATED;
} else {
tcf_hash_release(a, bind);
if (!ovr)
return -EEXIST;
}
ife = to_ife(a);
ife->flags = parm->flags;
if (parm->flags & IFE_ENCODE) {
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
NULL);
if (err) {
metadata_parse_err:
if (exists)
tcf_hash_release(a, bind);
if (ret == ACT_P_CREATED)
_tcf_ife_cleanup(a, bind);
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
_tcf_ife_cleanup(a, bind);
if (exists)
spin_unlock_bh(&ife->tcf_lock);
return err;
}
}
if (exists)
spin_unlock_bh(&ife->tcf_lock);
if (ret == ACT_P_CREATED)
tcf_hash_insert(tn, a);
return ret;
}
static int tcf_ife_dump(struct sk_buff *skb, struct tc_action *a, int bind,
int ref)
{
unsigned char *b = skb_tail_pointer(skb);
struct tcf_ife_info *ife = a->priv;
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
t.install = jiffies_to_clock_t(jiffies - ife->tcf_tm.install);
t.lastuse = jiffies_to_clock_t(jiffies - ife->tcf_tm.lastuse);
t.expires = jiffies_to_clock_t(ife->tcf_tm.expires);
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
int find_decode_metaid(struct sk_buff *skb, struct tcf_ife_info *ife,
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
struct tcf_ife_info *ife = a->priv;
int action = ife->tcf_action;
struct ifeheadr *ifehdr = (struct ifeheadr *)skb->data;
u16 ifehdrln = ifehdr->metalen;
struct meta_tlvhdr *tlv = (struct meta_tlvhdr *)(ifehdr->tlv_data);
spin_lock(&ife->tcf_lock);
bstats_update(&ife->tcf_bstats, skb);
ife->tcf_tm.lastuse = jiffies;
spin_unlock(&ife->tcf_lock);
ifehdrln = ntohs(ifehdrln);
if (unlikely(!pskb_may_pull(skb, ifehdrln))) {
spin_lock(&ife->tcf_lock);
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
skb_set_mac_header(skb, ifehdrln);
__skb_pull(skb, ifehdrln);
skb->protocol = eth_type_trans(skb, skb->dev);
ifehdrln -= IFE_METAHDRLEN;
while (ifehdrln > 0) {
u8 *tlvdata = (u8 *)tlv;
u16 mtype = tlv->type;
u16 mlen = tlv->len;
mtype = ntohs(mtype);
mlen = ntohs(mlen);
if (find_decode_metaid(skb, ife, mtype, (mlen - 4),
(void *)(tlvdata + 4))) {
pr_info_ratelimited("Unknown metaid %d alnlen %d\n",
mtype, mlen);
ife->tcf_qstats.overlimits++;
}
tlvdata += mlen;
ifehdrln -= mlen;
tlv = (struct meta_tlvhdr *)tlvdata;
}
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
struct tcf_ife_info *ife = a->priv;
int action = ife->tcf_action;
struct ethhdr *oethh;
struct ethhdr *iethh;
struct tcf_meta_info *e;
u16 metalen = ife_get_sz(skb, ife);
int hdrm = metalen + skb->dev->hard_header_len + IFE_METAHDRLEN;
unsigned int skboff = skb->dev->hard_header_len;
u32 at = G_TC_AT(skb->tc_verd);
int new_len = skb->len + hdrm;
bool exceed_mtu = false;
int err;
if (at & AT_EGRESS) {
if (new_len > skb->dev->mtu)
exceed_mtu = true;
}
spin_lock(&ife->tcf_lock);
bstats_update(&ife->tcf_bstats, skb);
ife->tcf_tm.lastuse = jiffies;
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
iethh = eth_hdr(skb);
err = skb_cow_head(skb, hdrm);
if (unlikely(err)) {
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
if (!(at & AT_EGRESS))
skb_push(skb, skb->dev->hard_header_len);
__skb_push(skb, hdrm);
memcpy(skb->data, iethh, skb->mac_len);
skb_reset_mac_header(skb);
oethh = eth_hdr(skb);
metalen += IFE_METAHDRLEN;
metalen = htons(metalen);
memcpy((skb->data + skboff), &metalen, IFE_METAHDRLEN);
skboff += IFE_METAHDRLEN;
list_for_each_entry(e, &ife->metalist, metalist) {
if (e->ops->encode) {
err = e->ops->encode(skb, (void *)(skb->data + skboff),
e);
}
if (err < 0) {
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
skboff += err;
}
if (!is_zero_ether_addr(ife->eth_src))
ether_addr_copy(oethh->h_source, ife->eth_src);
else
ether_addr_copy(oethh->h_source, iethh->h_source);
if (!is_zero_ether_addr(ife->eth_dst))
ether_addr_copy(oethh->h_dest, ife->eth_dst);
else
ether_addr_copy(oethh->h_dest, iethh->h_dest);
oethh->h_proto = htons(ife->eth_type);
if (!(at & AT_EGRESS))
skb_pull(skb, skb->dev->hard_header_len);
spin_unlock(&ife->tcf_lock);
return action;
}
static int tcf_ife_act(struct sk_buff *skb, const struct tc_action *a,
struct tcf_result *res)
{
struct tcf_ife_info *ife = a->priv;
if (ife->flags & IFE_ENCODE)
return tcf_ife_encode(skb, a, res);
if (!(ife->flags & IFE_ENCODE))
return tcf_ife_decode(skb, a, res);
pr_info_ratelimited("unknown failure(policy neither de/encode\n");
spin_lock(&ife->tcf_lock);
bstats_update(&ife->tcf_bstats, skb);
ife->tcf_tm.lastuse = jiffies;
ife->tcf_qstats.drops++;
spin_unlock(&ife->tcf_lock);
return TC_ACT_SHOT;
}
static int tcf_ife_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
struct tc_action *a)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
return tcf_generic_walker(tn, skb, cb, type, a);
}
static int tcf_ife_search(struct net *net, struct tc_action *a, u32 index)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int ife_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, ife_net_id);
return tc_action_net_init(tn, &act_ife_ops, IFE_TAB_MASK);
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
