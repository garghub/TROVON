static unsigned int
ebt_snat_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ebt_nat_info *info = par->targinfo;
if (!skb_make_writable(skb, 0))
return EBT_DROP;
memcpy(eth_hdr(skb)->h_source, info->mac, ETH_ALEN);
if (!(info->target & NAT_ARP_BIT) &&
eth_hdr(skb)->h_proto == htons(ETH_P_ARP)) {
const struct arphdr *ap;
struct arphdr _ah;
ap = skb_header_pointer(skb, 0, sizeof(_ah), &_ah);
if (ap == NULL)
return EBT_DROP;
if (ap->ar_hln != ETH_ALEN)
goto out;
if (skb_store_bits(skb, sizeof(_ah), info->mac, ETH_ALEN))
return EBT_DROP;
}
out:
return info->target | ~EBT_VERDICT_BITS;
}
static int ebt_snat_tg_check(const struct xt_tgchk_param *par)
{
const struct ebt_nat_info *info = par->targinfo;
int tmp;
tmp = info->target | ~EBT_VERDICT_BITS;
if (BASE_CHAIN && tmp == EBT_RETURN)
return -EINVAL;
if (tmp < -NUM_STANDARD_TARGETS || tmp >= 0)
return -EINVAL;
tmp = info->target | EBT_VERDICT_BITS;
if ((tmp & ~NAT_ARP_BIT) != ~NAT_ARP_BIT)
return -EINVAL;
return 0;
}
static int __init ebt_snat_init(void)
{
return xt_register_target(&ebt_snat_tg_reg);
}
static void __exit ebt_snat_fini(void)
{
xt_unregister_target(&ebt_snat_tg_reg);
}
