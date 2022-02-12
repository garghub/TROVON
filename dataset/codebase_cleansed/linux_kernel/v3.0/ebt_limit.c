static bool
ebt_limit_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
struct ebt_limit_info *info = (void *)par->matchinfo;
unsigned long now = jiffies;
spin_lock_bh(&limit_lock);
info->credit += (now - xchg(&info->prev, now)) * CREDITS_PER_JIFFY;
if (info->credit > info->credit_cap)
info->credit = info->credit_cap;
if (info->credit >= info->cost) {
info->credit -= info->cost;
spin_unlock_bh(&limit_lock);
return true;
}
spin_unlock_bh(&limit_lock);
return false;
}
static u_int32_t
user2credits(u_int32_t user)
{
if (user > 0xFFFFFFFF / (HZ*CREDITS_PER_JIFFY))
return (user / EBT_LIMIT_SCALE) * HZ * CREDITS_PER_JIFFY;
return (user * HZ * CREDITS_PER_JIFFY) / EBT_LIMIT_SCALE;
}
static int ebt_limit_mt_check(const struct xt_mtchk_param *par)
{
struct ebt_limit_info *info = par->matchinfo;
if (info->burst == 0 ||
user2credits(info->avg * info->burst) < user2credits(info->avg)) {
pr_info("overflow, try lower: %u/%u\n",
info->avg, info->burst);
return -EINVAL;
}
info->prev = jiffies;
info->credit = user2credits(info->avg * info->burst);
info->credit_cap = user2credits(info->avg * info->burst);
info->cost = user2credits(info->avg);
return 0;
}
static int __init ebt_limit_init(void)
{
return xt_register_match(&ebt_limit_mt_reg);
}
static void __exit ebt_limit_fini(void)
{
xt_unregister_match(&ebt_limit_mt_reg);
}
