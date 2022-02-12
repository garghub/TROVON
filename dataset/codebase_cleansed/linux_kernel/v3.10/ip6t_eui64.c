static bool
eui64_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
unsigned char eui64[8];
if (!(skb_mac_header(skb) >= skb->head &&
skb_mac_header(skb) + ETH_HLEN <= skb->data) &&
par->fragoff != 0) {
par->hotdrop = true;
return false;
}
memset(eui64, 0, sizeof(eui64));
if (eth_hdr(skb)->h_proto == htons(ETH_P_IPV6)) {
if (ipv6_hdr(skb)->version == 0x6) {
memcpy(eui64, eth_hdr(skb)->h_source, 3);
memcpy(eui64 + 5, eth_hdr(skb)->h_source + 3, 3);
eui64[3] = 0xff;
eui64[4] = 0xfe;
eui64[0] ^= 0x02;
if (!memcmp(ipv6_hdr(skb)->saddr.s6_addr + 8, eui64,
sizeof(eui64)))
return true;
}
}
return false;
}
static int __init eui64_mt6_init(void)
{
return xt_register_match(&eui64_mt6_reg);
}
static void __exit eui64_mt6_exit(void)
{
xt_unregister_match(&eui64_mt6_reg);
}
