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
if (info->match & XT_OWNER_UID)
if ((filp->f_cred->fsuid >= info->uid_min &&
filp->f_cred->fsuid <= info->uid_max) ^
!(info->invert & XT_OWNER_UID))
return false;
if (info->match & XT_OWNER_GID)
if ((filp->f_cred->fsgid >= info->gid_min &&
filp->f_cred->fsgid <= info->gid_max) ^
!(info->invert & XT_OWNER_GID))
return false;
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
