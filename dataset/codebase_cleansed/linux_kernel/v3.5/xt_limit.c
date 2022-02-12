static bool
limit_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_rateinfo *r = par->matchinfo;
struct xt_limit_priv *priv = r->master;
unsigned long now = jiffies;
spin_lock_bh(&limit_lock);
priv->credit += (now - xchg(&priv->prev, now)) * CREDITS_PER_JIFFY;
if (priv->credit > r->credit_cap)
priv->credit = r->credit_cap;
if (priv->credit >= r->cost) {
priv->credit -= r->cost;
spin_unlock_bh(&limit_lock);
return true;
}
spin_unlock_bh(&limit_lock);
return false;
}
static u32 user2credits(u32 user)
{
if (user > 0xFFFFFFFF / (HZ*CREDITS_PER_JIFFY))
return (user / XT_LIMIT_SCALE) * HZ * CREDITS_PER_JIFFY;
return (user * HZ * CREDITS_PER_JIFFY) / XT_LIMIT_SCALE;
}
static int limit_mt_check(const struct xt_mtchk_param *par)
{
struct xt_rateinfo *r = par->matchinfo;
struct xt_limit_priv *priv;
if (r->burst == 0
|| user2credits(r->avg * r->burst) < user2credits(r->avg)) {
pr_info("Overflow, try lower: %u/%u\n",
r->avg, r->burst);
return -ERANGE;
}
priv = kmalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
r->master = priv;
if (r->cost == 0) {
priv->prev = jiffies;
priv->credit = user2credits(r->avg * r->burst);
r->credit_cap = priv->credit;
r->cost = user2credits(r->avg);
}
return 0;
}
static void limit_mt_destroy(const struct xt_mtdtor_param *par)
{
const struct xt_rateinfo *info = par->matchinfo;
kfree(info->master);
}
static void limit_mt_compat_from_user(void *dst, const void *src)
{
const struct compat_xt_rateinfo *cm = src;
struct xt_rateinfo m = {
.avg = cm->avg,
.burst = cm->burst,
.prev = cm->prev | (unsigned long)cm->master << 32,
.credit = cm->credit,
.credit_cap = cm->credit_cap,
.cost = cm->cost,
};
memcpy(dst, &m, sizeof(m));
}
static int limit_mt_compat_to_user(void __user *dst, const void *src)
{
const struct xt_rateinfo *m = src;
struct compat_xt_rateinfo cm = {
.avg = m->avg,
.burst = m->burst,
.prev = m->prev,
.credit = m->credit,
.credit_cap = m->credit_cap,
.cost = m->cost,
.master = m->prev >> 32,
};
return copy_to_user(dst, &cm, sizeof(cm)) ? -EFAULT : 0;
}
static int __init limit_mt_init(void)
{
return xt_register_match(&limit_mt_reg);
}
static void __exit limit_mt_exit(void)
{
xt_unregister_match(&limit_mt_reg);
}
