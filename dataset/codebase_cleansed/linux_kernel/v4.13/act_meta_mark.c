static int skbmark_encode(struct sk_buff *skb, void *skbdata,
struct tcf_meta_info *e)
{
u32 ifemark = skb->mark;
return ife_encode_meta_u32(ifemark, skbdata, e);
}
static int skbmark_decode(struct sk_buff *skb, void *data, u16 len)
{
u32 ifemark = *(u32 *)data;
skb->mark = ntohl(ifemark);
return 0;
}
static int skbmark_check(struct sk_buff *skb, struct tcf_meta_info *e)
{
return ife_check_meta_u32(skb->mark, e);
}
static int __init ifemark_init_module(void)
{
return register_ife_op(&ife_skbmark_ops);
}
static void __exit ifemark_cleanup_module(void)
{
unregister_ife_op(&ife_skbmark_ops);
}
