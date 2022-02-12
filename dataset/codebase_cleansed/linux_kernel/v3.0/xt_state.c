static bool
state_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_state_info *sinfo = par->matchinfo;
enum ip_conntrack_info ctinfo;
unsigned int statebit;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (!ct)
statebit = XT_STATE_INVALID;
else {
if (nf_ct_is_untracked(ct))
statebit = XT_STATE_UNTRACKED;
else
statebit = XT_STATE_BIT(ctinfo);
}
return (sinfo->statemask & statebit);
}
static int state_mt_check(const struct xt_mtchk_param *par)
{
int ret;
ret = nf_ct_l3proto_try_module_get(par->family);
if (ret < 0)
pr_info("cannot load conntrack support for proto=%u\n",
par->family);
return ret;
}
static void state_mt_destroy(const struct xt_mtdtor_param *par)
{
nf_ct_l3proto_module_put(par->family);
}
static int __init state_mt_init(void)
{
return xt_register_match(&state_mt_reg);
}
static void __exit state_mt_exit(void)
{
xt_unregister_match(&state_mt_reg);
}
