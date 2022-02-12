static int owner_check(const struct xt_mtchk_param *par)
{
struct xt_owner_match_info *info = par->matchinfo;
struct net *net = par->net;
if ((info->match & (XT_OWNER_UID|XT_OWNER_GID)) &&
(current_user_ns() != net->user_ns))
return -EINVAL;
if (info->match & XT_OWNER_UID) {
kuid_t uid_min = make_kuid(net->user_ns, info->uid_min);
kuid_t uid_max = make_kuid(net->user_ns, info->uid_max);
if (!uid_valid(uid_min) || !uid_valid(uid_max) ||
(info->uid_max < info->uid_min) ||
uid_lt(uid_max, uid_min)) {
return -EINVAL;
}
}
if (info->match & XT_OWNER_GID) {
kgid_t gid_min = make_kgid(net->user_ns, info->gid_min);
kgid_t gid_max = make_kgid(net->user_ns, info->gid_max);
if (!gid_valid(gid_min) || !gid_valid(gid_max) ||
(info->gid_max < info->gid_min) ||
gid_lt(gid_max, gid_min)) {
return -EINVAL;
}
}
return 0;
}
static bool
owner_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_owner_match_info *info = par->matchinfo;
const struct file *filp;
struct sock *sk = skb_to_full_sk(skb);
struct net *net = xt_net(par);
if (sk == NULL || sk->sk_socket == NULL)
return (info->match ^ info->invert) == 0;
else if (info->match & info->invert & XT_OWNER_SOCKET)
return false;
filp = sk->sk_socket->file;
if (filp == NULL)
return ((info->match ^ info->invert) &
(XT_OWNER_UID | XT_OWNER_GID)) == 0;
if (info->match & XT_OWNER_UID) {
kuid_t uid_min = make_kuid(net->user_ns, info->uid_min);
kuid_t uid_max = make_kuid(net->user_ns, info->uid_max);
if ((uid_gte(filp->f_cred->fsuid, uid_min) &&
uid_lte(filp->f_cred->fsuid, uid_max)) ^
!(info->invert & XT_OWNER_UID))
return false;
}
if (info->match & XT_OWNER_GID) {
kgid_t gid_min = make_kgid(net->user_ns, info->gid_min);
kgid_t gid_max = make_kgid(net->user_ns, info->gid_max);
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
