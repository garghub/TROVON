static bool
connlabel_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_connlabel_mtinfo *info = par->matchinfo;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
bool invert = info->options & XT_CONNLABEL_OP_INVERT;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL || nf_ct_is_untracked(ct))
return invert;
if (info->options & XT_CONNLABEL_OP_SET)
return (nf_connlabel_set(ct, info->bit) == 0) ^ invert;
return nf_connlabel_match(ct, info->bit) ^ invert;
}
static int connlabel_mt_check(const struct xt_mtchk_param *par)
{
const int options = XT_CONNLABEL_OP_INVERT |
XT_CONNLABEL_OP_SET;
struct xt_connlabel_mtinfo *info = par->matchinfo;
int ret;
size_t words;
if (info->bit > XT_CONNLABEL_MAXBIT)
return -ERANGE;
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
par->net->ct.labels_used++;
words = BITS_TO_LONGS(info->bit+1);
if (words > par->net->ct.label_words)
par->net->ct.label_words = words;
return ret;
}
static void connlabel_mt_destroy(const struct xt_mtdtor_param *par)
{
par->net->ct.labels_used--;
if (par->net->ct.labels_used == 0)
par->net->ct.label_words = 0;
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
