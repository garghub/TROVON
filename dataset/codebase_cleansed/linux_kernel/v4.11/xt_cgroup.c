static int cgroup_mt_check_v0(const struct xt_mtchk_param *par)
{
struct xt_cgroup_info_v0 *info = par->matchinfo;
if (info->invert & ~1)
return -EINVAL;
return 0;
}
static int cgroup_mt_check_v1(const struct xt_mtchk_param *par)
{
struct xt_cgroup_info_v1 *info = par->matchinfo;
struct cgroup *cgrp;
if ((info->invert_path & ~1) || (info->invert_classid & ~1))
return -EINVAL;
if (!info->has_path && !info->has_classid) {
pr_info("xt_cgroup: no path or classid specified\n");
return -EINVAL;
}
if (info->has_path && info->has_classid) {
pr_info("xt_cgroup: both path and classid specified\n");
return -EINVAL;
}
if (info->has_path) {
cgrp = cgroup_get_from_path(info->path);
if (IS_ERR(cgrp)) {
pr_info("xt_cgroup: invalid path, errno=%ld\n",
PTR_ERR(cgrp));
return -EINVAL;
}
info->priv = cgrp;
}
return 0;
}
static bool
cgroup_mt_v0(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_cgroup_info_v0 *info = par->matchinfo;
if (skb->sk == NULL || !sk_fullsock(skb->sk))
return false;
return (info->id == sock_cgroup_classid(&skb->sk->sk_cgrp_data)) ^
info->invert;
}
static bool cgroup_mt_v1(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_cgroup_info_v1 *info = par->matchinfo;
struct sock_cgroup_data *skcd = &skb->sk->sk_cgrp_data;
struct cgroup *ancestor = info->priv;
if (!skb->sk || !sk_fullsock(skb->sk))
return false;
if (ancestor)
return cgroup_is_descendant(sock_cgroup_ptr(skcd), ancestor) ^
info->invert_path;
else
return (info->classid == sock_cgroup_classid(skcd)) ^
info->invert_classid;
}
static void cgroup_mt_destroy_v1(const struct xt_mtdtor_param *par)
{
struct xt_cgroup_info_v1 *info = par->matchinfo;
if (info->priv)
cgroup_put(info->priv);
}
static int __init cgroup_mt_init(void)
{
return xt_register_matches(cgroup_mt_reg, ARRAY_SIZE(cgroup_mt_reg));
}
static void __exit cgroup_mt_exit(void)
{
xt_unregister_matches(cgroup_mt_reg, ARRAY_SIZE(cgroup_mt_reg));
}
