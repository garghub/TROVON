static unsigned int
checksum_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
if (skb->ip_summed == CHECKSUM_PARTIAL)
skb_checksum_help(skb);
return XT_CONTINUE;
}
static int checksum_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_CHECKSUM_info *einfo = par->targinfo;
if (einfo->operation & ~XT_CHECKSUM_OP_FILL) {
pr_info("unsupported CHECKSUM operation %x\n", einfo->operation);
return -EINVAL;
}
if (!einfo->operation) {
pr_info("no CHECKSUM operation enabled\n");
return -EINVAL;
}
return 0;
}
static int __init checksum_tg_init(void)
{
return xt_register_target(&checksum_tg_reg);
}
static void __exit checksum_tg_exit(void)
{
xt_unregister_target(&checksum_tg_reg);
}
