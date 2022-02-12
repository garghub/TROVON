static bool
quota_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
struct xt_quota_info *q = (void *)par->matchinfo;
struct xt_quota_priv *priv = q->master;
bool ret = q->flags & XT_QUOTA_INVERT;
spin_lock_bh(&priv->lock);
if (priv->quota >= skb->len) {
priv->quota -= skb->len;
ret = !ret;
} else {
priv->quota = 0;
}
spin_unlock_bh(&priv->lock);
return ret;
}
static int quota_mt_check(const struct xt_mtchk_param *par)
{
struct xt_quota_info *q = par->matchinfo;
if (q->flags & ~XT_QUOTA_MASK)
return -EINVAL;
q->master = kmalloc(sizeof(*q->master), GFP_KERNEL);
if (q->master == NULL)
return -ENOMEM;
spin_lock_init(&q->master->lock);
q->master->quota = q->quota;
return 0;
}
static void quota_mt_destroy(const struct xt_mtdtor_param *par)
{
const struct xt_quota_info *q = par->matchinfo;
kfree(q->master);
}
static int __init quota_mt_init(void)
{
return xt_register_match(&quota_mt_reg);
}
static void __exit quota_mt_exit(void)
{
xt_unregister_match(&quota_mt_reg);
}
