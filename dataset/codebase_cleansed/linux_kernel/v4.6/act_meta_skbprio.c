static int skbprio_check(struct sk_buff *skb, struct tcf_meta_info *e)
{
return ife_check_meta_u32(skb->priority, e);
}
static int skbprio_encode(struct sk_buff *skb, void *skbdata,
struct tcf_meta_info *e)
{
u32 ifeprio = skb->priority;
return ife_encode_meta_u32(ifeprio, skbdata, e);
}
static int skbprio_decode(struct sk_buff *skb, void *data, u16 len)
{
u32 ifeprio = *(u32 *)data;
skb->priority = ntohl(ifeprio);
return 0;
}
static int __init ifeprio_init_module(void)
{
return register_ife_op(&ife_prio_ops);
}
static void __exit ifeprio_cleanup_module(void)
{
unregister_ife_op(&ife_prio_ops);
}
