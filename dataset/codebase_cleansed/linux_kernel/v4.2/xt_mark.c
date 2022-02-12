static unsigned int
mark_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_mark_tginfo2 *info = par->targinfo;
skb->mark = (skb->mark & ~info->mask) ^ info->mark;
return XT_CONTINUE;
}
static bool
mark_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_mark_mtinfo1 *info = par->matchinfo;
return ((skb->mark & info->mask) == info->mark) ^ info->invert;
}
static int __init mark_mt_init(void)
{
int ret;
ret = xt_register_target(&mark_tg_reg);
if (ret < 0)
return ret;
ret = xt_register_match(&mark_mt_reg);
if (ret < 0) {
xt_unregister_target(&mark_tg_reg);
return ret;
}
return 0;
}
static void __exit mark_mt_exit(void)
{
xt_unregister_match(&mark_mt_reg);
xt_unregister_target(&mark_tg_reg);
}
