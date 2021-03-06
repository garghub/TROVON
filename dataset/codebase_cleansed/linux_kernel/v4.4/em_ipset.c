static int em_ipset_change(struct net *net, void *data, int data_len,
struct tcf_ematch *em)
{
struct xt_set_info *set = data;
ip_set_id_t index;
if (data_len != sizeof(*set))
return -EINVAL;
index = ip_set_nfnl_get_byindex(net, set->index);
if (index == IPSET_INVALID_ID)
return -ENOENT;
em->datalen = sizeof(*set);
em->data = (unsigned long)kmemdup(data, em->datalen, GFP_KERNEL);
if (em->data)
return 0;
ip_set_nfnl_put(net, index);
return -ENOMEM;
}
static void em_ipset_destroy(struct tcf_ematch *em)
{
const struct xt_set_info *set = (const void *) em->data;
if (set) {
ip_set_nfnl_put(em->net, set->index);
kfree((void *) em->data);
}
}
static int em_ipset_match(struct sk_buff *skb, struct tcf_ematch *em,
struct tcf_pkt_info *info)
{
struct ip_set_adt_opt opt;
struct xt_action_param acpar;
const struct xt_set_info *set = (const void *) em->data;
struct net_device *dev, *indev = NULL;
int ret, network_offset;
switch (tc_skb_protocol(skb)) {
case htons(ETH_P_IP):
acpar.family = NFPROTO_IPV4;
if (!pskb_network_may_pull(skb, sizeof(struct iphdr)))
return 0;
acpar.thoff = ip_hdrlen(skb);
break;
case htons(ETH_P_IPV6):
acpar.family = NFPROTO_IPV6;
if (!pskb_network_may_pull(skb, sizeof(struct ipv6hdr)))
return 0;
acpar.thoff = sizeof(struct ipv6hdr);
break;
default:
return 0;
}
acpar.hooknum = 0;
opt.family = acpar.family;
opt.dim = set->dim;
opt.flags = set->flags;
opt.cmdflags = 0;
opt.ext.timeout = ~0u;
network_offset = skb_network_offset(skb);
skb_pull(skb, network_offset);
dev = skb->dev;
rcu_read_lock();
if (skb->skb_iif)
indev = dev_get_by_index_rcu(em->net, skb->skb_iif);
acpar.net = em->net;
acpar.in = indev ? indev : dev;
acpar.out = dev;
ret = ip_set_test(set->index, skb, &acpar, &opt);
rcu_read_unlock();
skb_push(skb, network_offset);
return ret;
}
static int __init init_em_ipset(void)
{
return tcf_em_register(&em_ipset_ops);
}
static void __exit exit_em_ipset(void)
{
tcf_em_unregister(&em_ipset_ops);
}
