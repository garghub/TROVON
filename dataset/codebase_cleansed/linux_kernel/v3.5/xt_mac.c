static bool mac_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_mac_info *info = par->matchinfo;
bool ret;
if (skb->dev == NULL || skb->dev->type != ARPHRD_ETHER)
return false;
if (skb_mac_header(skb) < skb->head)
return false;
if (skb_mac_header(skb) + ETH_HLEN > skb->data)
return false;
ret = ether_addr_equal(eth_hdr(skb)->h_source, info->srcaddr);
ret ^= info->invert;
return ret;
}
static int __init mac_mt_init(void)
{
return xt_register_match(&mac_mt_reg);
}
static void __exit mac_mt_exit(void)
{
xt_unregister_match(&mac_mt_reg);
}
