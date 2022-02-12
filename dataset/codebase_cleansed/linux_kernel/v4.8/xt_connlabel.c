static bool
connlabel_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_connlabel_mtinfo *info = par->matchinfo;
enum ip_conntrack_info ctinfo;
struct nf_conn_labels *labels;
struct nf_conn *ct;
bool invert = info->options & XT_CONNLABEL_OP_INVERT;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL || nf_ct_is_untracked(ct))
return invert;
labels = nf_ct_labels_find(ct);
if (!labels)
return invert;
if (test_bit(info->bit, labels->bits))
return !invert;
if (info->options & XT_CONNLABEL_OP_SET) {
if (!test_and_set_bit(info->bit, labels->bits))
nf_conntrack_event_cache(IPCT_LABEL, ct);
return !invert;
}
return invert;
}
static int connlabel_mt_check(const struct xt_mtchk_param *par)
{
const int options = XT_CONNLABEL_OP_INVERT |
XT_CONNLABEL_OP_SET;
struct xt_connlabel_mtinfo *info = par->matchinfo;
int ret;
if (info->options & ~options) {
pr_err("Unknown options in mask %x\n", info->options);
return -EINVAL;
}
ret = nf_ct_l3proto_try_module_get(par->family);
if (ret < 0) {
pr_info("cannot load conntrack support for proto=%u\n",
par->family);
return ret;
}
ret = nf_connlabels_get(par->net, info->bit);
if (ret < 0)
nf_ct_l3proto_module_put(par->family);
return ret;
}
static void connlabel_mt_destroy(const struct xt_mtdtor_param *par)
{
nf_connlabels_put(par->net);
nf_ct_l3proto_module_put(par->family);
}
static int __init connlabel_mt_init(void)
{
return xt_register_match(&connlabels_mt_reg);
}
static void __exit connlabel_mt_exit(void)
{
xt_unregister_match(&connlabels_mt_reg);
}
