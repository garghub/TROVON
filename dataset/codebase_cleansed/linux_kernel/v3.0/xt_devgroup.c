static bool devgroup_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_devgroup_info *info = par->matchinfo;
if (info->flags & XT_DEVGROUP_MATCH_SRC &&
(((info->src_group ^ par->in->group) & info->src_mask ? 1 : 0) ^
((info->flags & XT_DEVGROUP_INVERT_SRC) ? 1 : 0)))
return false;
if (info->flags & XT_DEVGROUP_MATCH_DST &&
(((info->dst_group ^ par->out->group) & info->dst_mask ? 1 : 0) ^
((info->flags & XT_DEVGROUP_INVERT_DST) ? 1 : 0)))
return false;
return true;
}
static int devgroup_mt_checkentry(const struct xt_mtchk_param *par)
{
const struct xt_devgroup_info *info = par->matchinfo;
if (info->flags & ~(XT_DEVGROUP_MATCH_SRC | XT_DEVGROUP_INVERT_SRC |
XT_DEVGROUP_MATCH_DST | XT_DEVGROUP_INVERT_DST))
return -EINVAL;
if (info->flags & XT_DEVGROUP_MATCH_SRC &&
par->hook_mask & ~((1 << NF_INET_PRE_ROUTING) |
(1 << NF_INET_LOCAL_IN) |
(1 << NF_INET_FORWARD)))
return -EINVAL;
if (info->flags & XT_DEVGROUP_MATCH_DST &&
par->hook_mask & ~((1 << NF_INET_FORWARD) |
(1 << NF_INET_LOCAL_OUT) |
(1 << NF_INET_POST_ROUTING)))
return -EINVAL;
return 0;
}
static int __init devgroup_mt_init(void)
{
return xt_register_match(&devgroup_mt_reg);
}
static void __exit devgroup_mt_exit(void)
{
xt_unregister_match(&devgroup_mt_reg);
}
