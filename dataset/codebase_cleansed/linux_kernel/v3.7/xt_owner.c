static int owner_check(const struct xt_mtchk_param *par)
{
struct xt_owner_match_info *info = par->matchinfo;
if ((info->match & (XT_OWNER_UID|XT_OWNER_GID)) &&
(current_user_ns() != &init_user_ns))
return -EINVAL;
return 0;
}
static bool
owner_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_owner_match_info *info = par->matchinfo;
const struct file *filp;
if (skb->sk == NULL || skb->sk->sk_socket == NULL)
return (info->match ^ info->invert) == 0;
else if (info->match & info->invert & XT_OWNER_SOCKET)
return false;
filp = skb->sk->sk_socket->file;
if (filp == NULL)
return ((info->match ^ info->invert) &
(XT_OWNER_UID | XT_OWNER_GID)) == 0;
if (info->match & XT_OWNER_UID) {
kuid_t uid_min = make_kuid(&init_user_ns, info->uid_min);
kuid_t uid_max = make_kuid(&init_user_ns, info->uid_max);
if ((uid_gte(filp->f_cred->fsuid, uid_min) &&
uid_lte(filp->f_cred->fsuid, uid_max)) ^
!(info->invert & XT_OWNER_UID))
return false;
}
if (info->match & XT_OWNER_GID) {
kgid_t gid_min = make_kgid(&init_user_ns, info->gid_min);
kgid_t gid_max = make_kgid(&init_user_ns, info->gid_max);
if ((gid_gte(filp->f_cred->fsgid, gid_min) &&
gid_lte(filp->f_cred->fsgid, gid_max)) ^
!(info->invert & XT_OWNER_GID))
return false;
}
return true;
}
static int __init owner_mt_init(void)
{
return xt_register_match(&owner_mt_reg);
}
static void __exit owner_mt_exit(void)
{
xt_unregister_match(&owner_mt_reg);
}
