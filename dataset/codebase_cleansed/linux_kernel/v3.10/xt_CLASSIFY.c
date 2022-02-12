static unsigned int
classify_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_classify_target_info *clinfo = par->targinfo;
skb->priority = clinfo->priority;
return XT_CONTINUE;
}
static int __init classify_tg_init(void)
{
return xt_register_targets(classify_tg_reg, ARRAY_SIZE(classify_tg_reg));
}
static void __exit classify_tg_exit(void)
{
xt_unregister_targets(classify_tg_reg, ARRAY_SIZE(classify_tg_reg));
}
