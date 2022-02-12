static int skbtcindex_encode(struct sk_buff *skb, void *skbdata,
struct tcf_meta_info *e)
{
u32 ifetc_index = skb->tc_index;
return ife_encode_meta_u16(ifetc_index, skbdata, e);
}
static int skbtcindex_decode(struct sk_buff *skb, void *data, u16 len)
{
u16 ifetc_index = *(u16 *)data;
skb->tc_index = ntohs(ifetc_index);
return 0;
}
static int skbtcindex_check(struct sk_buff *skb, struct tcf_meta_info *e)
{
return ife_check_meta_u16(skb->tc_index, e);
}
static int __init ifetc_index_init_module(void)
{
return register_ife_op(&ife_skbtcindex_ops);
}
static void __exit ifetc_index_cleanup_module(void)
{
unregister_ife_op(&ife_skbtcindex_ops);
}
