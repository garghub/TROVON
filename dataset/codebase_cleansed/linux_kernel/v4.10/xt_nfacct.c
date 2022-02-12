static bool nfacct_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
int overquota;
const struct xt_nfacct_match_info *info = par->targinfo;
nfnl_acct_update(skb, info->nfacct);
overquota = nfnl_acct_overquota(xt_net(par), skb, info->nfacct);
return overquota == NFACCT_UNDERQUOTA ? false : true;
}
static int
nfacct_mt_checkentry(const struct xt_mtchk_param *par)
{
struct xt_nfacct_match_info *info = par->matchinfo;
struct nf_acct *nfacct;
nfacct = nfnl_acct_find_get(par->net, info->name);
if (nfacct == NULL) {
pr_info("xt_nfacct: accounting object with name `%s' "
"does not exists\n", info->name);
return -ENOENT;
}
info->nfacct = nfacct;
return 0;
}
static void
nfacct_mt_destroy(const struct xt_mtdtor_param *par)
{
const struct xt_nfacct_match_info *info = par->matchinfo;
nfnl_acct_put(info->nfacct);
}
static int __init nfacct_mt_init(void)
{
return xt_register_match(&nfacct_mt_reg);
}
static void __exit nfacct_mt_exit(void)
{
xt_unregister_match(&nfacct_mt_reg);
}
