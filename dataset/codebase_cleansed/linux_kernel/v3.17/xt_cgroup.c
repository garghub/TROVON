static int cgroup_mt_check(const struct xt_mtchk_param *par)
{
struct xt_cgroup_info *info = par->matchinfo;
if (info->invert & ~1)
return -EINVAL;
return 0;
}
static bool
cgroup_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_cgroup_info *info = par->matchinfo;
if (skb->sk == NULL)
return false;
return (info->id == skb->sk->sk_classid) ^ info->invert;
}
static int __init cgroup_mt_init(void)
{
return xt_register_match(&cgroup_mt_reg);
}
static void __exit cgroup_mt_exit(void)
{
xt_unregister_match(&cgroup_mt_reg);
}
