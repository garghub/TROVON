static unsigned int
reject_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ip6t_reject_info *reject = par->targinfo;
struct net *net = xt_net(par);
switch (reject->with) {
case IP6T_ICMP6_NO_ROUTE:
nf_send_unreach6(net, skb, ICMPV6_NOROUTE, xt_hooknum(par));
break;
case IP6T_ICMP6_ADM_PROHIBITED:
nf_send_unreach6(net, skb, ICMPV6_ADM_PROHIBITED,
xt_hooknum(par));
break;
case IP6T_ICMP6_NOT_NEIGHBOUR:
nf_send_unreach6(net, skb, ICMPV6_NOT_NEIGHBOUR,
xt_hooknum(par));
break;
case IP6T_ICMP6_ADDR_UNREACH:
nf_send_unreach6(net, skb, ICMPV6_ADDR_UNREACH,
xt_hooknum(par));
break;
case IP6T_ICMP6_PORT_UNREACH:
nf_send_unreach6(net, skb, ICMPV6_PORT_UNREACH,
xt_hooknum(par));
break;
case IP6T_ICMP6_ECHOREPLY:
break;
case IP6T_TCP_RESET:
nf_send_reset6(net, skb, xt_hooknum(par));
break;
case IP6T_ICMP6_POLICY_FAIL:
nf_send_unreach6(net, skb, ICMPV6_POLICY_FAIL, xt_hooknum(par));
break;
case IP6T_ICMP6_REJECT_ROUTE:
nf_send_unreach6(net, skb, ICMPV6_REJECT_ROUTE,
xt_hooknum(par));
break;
}
return NF_DROP;
}
static int reject_tg6_check(const struct xt_tgchk_param *par)
{
const struct ip6t_reject_info *rejinfo = par->targinfo;
const struct ip6t_entry *e = par->entryinfo;
if (rejinfo->with == IP6T_ICMP6_ECHOREPLY) {
pr_info("ECHOREPLY is not supported.\n");
return -EINVAL;
} else if (rejinfo->with == IP6T_TCP_RESET) {
if (!(e->ipv6.flags & IP6T_F_PROTO) ||
e->ipv6.proto != IPPROTO_TCP ||
(e->ipv6.invflags & XT_INV_PROTO)) {
pr_info("TCP_RESET illegal for non-tcp\n");
return -EINVAL;
}
}
return 0;
}
static int __init reject_tg6_init(void)
{
return xt_register_target(&reject_tg6_reg);
}
static void __exit reject_tg6_exit(void)
{
xt_unregister_target(&reject_tg6_reg);
}
