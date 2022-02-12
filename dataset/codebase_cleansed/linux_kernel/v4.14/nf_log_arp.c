static void dump_arp_packet(struct nf_log_buf *m,
const struct nf_loginfo *info,
const struct sk_buff *skb, unsigned int nhoff)
{
const struct arphdr *ah;
struct arphdr _arph;
const struct arppayload *ap;
struct arppayload _arpp;
ah = skb_header_pointer(skb, 0, sizeof(_arph), &_arph);
if (ah == NULL) {
nf_log_buf_add(m, "TRUNCATED");
return;
}
nf_log_buf_add(m, "ARP HTYPE=%d PTYPE=0x%04x OPCODE=%d",
ntohs(ah->ar_hrd), ntohs(ah->ar_pro), ntohs(ah->ar_op));
if (ah->ar_hrd != htons(ARPHRD_ETHER) ||
ah->ar_hln != ETH_ALEN ||
ah->ar_pln != sizeof(__be32))
return;
ap = skb_header_pointer(skb, sizeof(_arph), sizeof(_arpp), &_arpp);
if (ap == NULL) {
nf_log_buf_add(m, " INCOMPLETE [%zu bytes]",
skb->len - sizeof(_arph));
return;
}
nf_log_buf_add(m, " MACSRC=%pM IPSRC=%pI4 MACDST=%pM IPDST=%pI4",
ap->mac_src, ap->ip_src, ap->mac_dst, ap->ip_dst);
}
static void nf_log_arp_packet(struct net *net, u_int8_t pf,
unsigned int hooknum, const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct nf_loginfo *loginfo,
const char *prefix)
{
struct nf_log_buf *m;
if (!net_eq(net, &init_net) && !sysctl_nf_log_all_netns)
return;
m = nf_log_buf_open();
if (!loginfo)
loginfo = &default_loginfo;
nf_log_dump_packet_common(m, pf, hooknum, skb, in, out, loginfo,
prefix);
dump_arp_packet(m, loginfo, skb, 0);
nf_log_buf_close(m);
}
static int __net_init nf_log_arp_net_init(struct net *net)
{
return nf_log_set(net, NFPROTO_ARP, &nf_arp_logger);
}
static void __net_exit nf_log_arp_net_exit(struct net *net)
{
nf_log_unset(net, &nf_arp_logger);
}
static int __init nf_log_arp_init(void)
{
int ret;
ret = register_pernet_subsys(&nf_log_arp_net_ops);
if (ret < 0)
return ret;
ret = nf_log_register(NFPROTO_ARP, &nf_arp_logger);
if (ret < 0) {
pr_err("failed to register logger\n");
goto err1;
}
return 0;
err1:
unregister_pernet_subsys(&nf_log_arp_net_ops);
return ret;
}
static void __exit nf_log_arp_exit(void)
{
unregister_pernet_subsys(&nf_log_arp_net_ops);
nf_log_unregister(&nf_arp_logger);
}
