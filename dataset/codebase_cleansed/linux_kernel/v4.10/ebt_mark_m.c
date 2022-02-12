static bool
ebt_mark_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ebt_mark_m_info *info = par->matchinfo;
if (info->bitmask & EBT_MARK_OR)
return !!(skb->mark & info->mask) ^ info->invert;
return ((skb->mark & info->mask) == info->mark) ^ info->invert;
}
static int ebt_mark_mt_check(const struct xt_mtchk_param *par)
{
const struct ebt_mark_m_info *info = par->matchinfo;
if (info->bitmask & ~EBT_MARK_MASK)
return -EINVAL;
if ((info->bitmask & EBT_MARK_OR) && (info->bitmask & EBT_MARK_AND))
return -EINVAL;
if (!info->bitmask)
return -EINVAL;
return 0;
}
static void mark_mt_compat_from_user(void *dst, const void *src)
{
const struct compat_ebt_mark_m_info *user = src;
struct ebt_mark_m_info *kern = dst;
kern->mark = user->mark;
kern->mask = user->mask;
kern->invert = user->invert;
kern->bitmask = user->bitmask;
}
static int mark_mt_compat_to_user(void __user *dst, const void *src)
{
struct compat_ebt_mark_m_info __user *user = dst;
const struct ebt_mark_m_info *kern = src;
if (put_user(kern->mark, &user->mark) ||
put_user(kern->mask, &user->mask) ||
put_user(kern->invert, &user->invert) ||
put_user(kern->bitmask, &user->bitmask))
return -EFAULT;
return 0;
}
static int __init ebt_mark_m_init(void)
{
return xt_register_match(&ebt_mark_mt_reg);
}
static void __exit ebt_mark_m_fini(void)
{
xt_unregister_match(&ebt_mark_mt_reg);
}
