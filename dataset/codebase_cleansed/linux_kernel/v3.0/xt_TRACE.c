static unsigned int
trace_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
skb->nf_trace = 1;
return XT_CONTINUE;
}
static int __init trace_tg_init(void)
{
return xt_register_target(&trace_tg_reg);
}
static void __exit trace_tg_exit(void)
{
xt_unregister_target(&trace_tg_reg);
}
