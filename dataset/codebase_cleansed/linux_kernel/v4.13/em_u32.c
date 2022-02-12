static int em_u32_match(struct sk_buff *skb, struct tcf_ematch *em,
struct tcf_pkt_info *info)
{
struct tc_u32_key *key = (struct tc_u32_key *) em->data;
const unsigned char *ptr = skb_network_header(skb);
if (info) {
if (info->ptr)
ptr = info->ptr;
ptr += (info->nexthdr & key->offmask);
}
ptr += key->off;
if (!tcf_valid_offset(skb, ptr, sizeof(u32)))
return 0;
return !(((*(__be32 *) ptr) ^ key->val) & key->mask);
}
static int __init init_em_u32(void)
{
return tcf_em_register(&em_u32_ops);
}
static void __exit exit_em_u32(void)
{
tcf_em_unregister(&em_u32_ops);
}
