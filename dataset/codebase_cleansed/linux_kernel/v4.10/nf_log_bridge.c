static void nf_log_bridge_packet(struct net *net, u_int8_t pf,
unsigned int hooknum,
const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct nf_loginfo *loginfo,
const char *prefix)
{
nf_log_l2packet(net, pf, eth_hdr(skb)->h_proto, hooknum, skb,
in, out, loginfo, prefix);
}
static int __net_init nf_log_bridge_net_init(struct net *net)
{
return nf_log_set(net, NFPROTO_BRIDGE, &nf_bridge_logger);
}
static void __net_exit nf_log_bridge_net_exit(struct net *net)
{
nf_log_unset(net, &nf_bridge_logger);
}
static int __init nf_log_bridge_init(void)
{
int ret;
nf_logger_request_module(NFPROTO_IPV4, NF_LOG_TYPE_LOG);
nf_logger_request_module(NFPROTO_IPV6, NF_LOG_TYPE_LOG);
nf_logger_request_module(NFPROTO_ARP, NF_LOG_TYPE_LOG);
ret = register_pernet_subsys(&nf_log_bridge_net_ops);
if (ret < 0)
return ret;
nf_log_register(NFPROTO_BRIDGE, &nf_bridge_logger);
return 0;
}
static void __exit nf_log_bridge_exit(void)
{
unregister_pernet_subsys(&nf_log_bridge_net_ops);
nf_log_unregister(&nf_bridge_logger);
}
