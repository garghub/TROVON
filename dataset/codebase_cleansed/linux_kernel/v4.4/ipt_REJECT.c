static unsigned int
reject_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ipt_reject_info *reject = par->targinfo;
int hook = par->hooknum;
switch (reject->with) {
case IPT_ICMP_NET_UNREACHABLE:
nf_send_unreach(skb, ICMP_NET_UNREACH, hook);
break;
case IPT_ICMP_HOST_UNREACHABLE:
nf_send_unreach(skb, ICMP_HOST_UNREACH, hook);
break;
case IPT_ICMP_PROT_UNREACHABLE:
nf_send_unreach(skb, ICMP_PROT_UNREACH, hook);
break;
case IPT_ICMP_PORT_UNREACHABLE:
nf_send_unreach(skb, ICMP_PORT_UNREACH, hook);
break;
case IPT_ICMP_NET_PROHIBITED:
nf_send_unreach(skb, ICMP_NET_ANO, hook);
break;
case IPT_ICMP_HOST_PROHIBITED:
nf_send_unreach(skb, ICMP_HOST_ANO, hook);
break;
case IPT_ICMP_ADMIN_PROHIBITED:
nf_send_unreach(skb, ICMP_PKT_FILTERED, hook);
break;
case IPT_TCP_RESET:
nf_send_reset(par->net, skb, hook);
case IPT_ICMP_ECHOREPLY:
break;
}
return NF_DROP;
}
static int reject_tg_check(const struct xt_tgchk_param *par)
{
const struct ipt_reject_info *rejinfo = par->targinfo;
const struct ipt_entry *e = par->entryinfo;
if (rejinfo->with == IPT_ICMP_ECHOREPLY) {
pr_info("ECHOREPLY no longer supported.\n");
return -EINVAL;
} else if (rejinfo->with == IPT_TCP_RESET) {
if (e->ip.proto != IPPROTO_TCP ||
(e->ip.invflags & XT_INV_PROTO)) {
pr_info("TCP_RESET invalid for non-tcp\n");
return -EINVAL;
}
}
return 0;
}
static int __init reject_tg_init(void)
{
return xt_register_target(&reject_tg_reg);
}
static void __exit reject_tg_exit(void)
{
xt_unregister_target(&reject_tg_reg);
}
