static bool
comment_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
return true;
}
static int __init comment_mt_init(void)
{
return xt_register_match(&comment_mt_reg);
}
static void __exit comment_mt_exit(void)
{
xt_unregister_match(&comment_mt_reg);
}
