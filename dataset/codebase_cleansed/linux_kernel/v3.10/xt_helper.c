static bool
helper_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_helper_info *info = par->matchinfo;
const struct nf_conn *ct;
const struct nf_conn_help *master_help;
const struct nf_conntrack_helper *helper;
enum ip_conntrack_info ctinfo;
bool ret = info->invert;
ct = nf_ct_get(skb, &ctinfo);
if (!ct || !ct->master)
return ret;
master_help = nfct_help(ct->master);
if (!master_help)
return ret;
helper = rcu_dereference(master_help->helper);
if (!helper)
return ret;
if (info->name[0] == '\0')
ret = !ret;
else
ret ^= !strncmp(helper->name, info->name,
strlen(helper->name));
return ret;
}
static int helper_mt_check(const struct xt_mtchk_param *par)
{
struct xt_helper_info *info = par->matchinfo;
int ret;
ret = nf_ct_l3proto_try_module_get(par->family);
if (ret < 0) {
pr_info("cannot load conntrack support for proto=%u\n",
par->family);
return ret;
}
info->name[29] = '\0';
return 0;
}
static void helper_mt_destroy(const struct xt_mtdtor_param *par)
{
nf_ct_l3proto_module_put(par->family);
}
static int __init helper_mt_init(void)
{
return xt_register_match(&helper_mt_reg);
}
static void __exit helper_mt_exit(void)
{
xt_unregister_match(&helper_mt_reg);
}
