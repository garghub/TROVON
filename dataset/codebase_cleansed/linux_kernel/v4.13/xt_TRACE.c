static int trace_tg_check(const struct xt_tgchk_param *par)
{
return nf_logger_find_get(par->family, NF_LOG_TYPE_LOG);
}
static void trace_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_logger_put(par->family, NF_LOG_TYPE_LOG);
}
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
