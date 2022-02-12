static bool
statistic_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_statistic_info *info = par->matchinfo;
bool ret = info->flags & XT_STATISTIC_INVERT;
int nval, oval;
switch (info->mode) {
case XT_STATISTIC_MODE_RANDOM:
if ((prandom_u32() & 0x7FFFFFFF) < info->u.random.probability)
ret = !ret;
break;
case XT_STATISTIC_MODE_NTH:
do {
oval = atomic_read(&info->master->count);
nval = (oval == info->u.nth.every) ? 0 : oval + 1;
} while (atomic_cmpxchg(&info->master->count, oval, nval) != oval);
if (nval == 0)
ret = !ret;
break;
}
return ret;
}
static int statistic_mt_check(const struct xt_mtchk_param *par)
{
struct xt_statistic_info *info = par->matchinfo;
if (info->mode > XT_STATISTIC_MODE_MAX ||
info->flags & ~XT_STATISTIC_MASK)
return -EINVAL;
info->master = kzalloc(sizeof(*info->master), GFP_KERNEL);
if (info->master == NULL)
return -ENOMEM;
atomic_set(&info->master->count, info->u.nth.count);
return 0;
}
static void statistic_mt_destroy(const struct xt_mtdtor_param *par)
{
const struct xt_statistic_info *info = par->matchinfo;
kfree(info->master);
}
static int __init statistic_mt_init(void)
{
return xt_register_match(&xt_statistic_mt_reg);
}
static void __exit statistic_mt_exit(void)
{
xt_unregister_match(&xt_statistic_mt_reg);
}
