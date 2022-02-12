static struct net *pick_net(struct sk_buff *skb)
{
#ifdef CONFIG_NET_NS
const struct dst_entry *dst;
if (skb->dev != NULL)
return dev_net(skb->dev);
dst = skb_dst(skb);
if (dst != NULL && dst->dev != NULL)
return dev_net(dst->dev);
#endif
return &init_net;
}
static bool
tee_tg_route4(struct sk_buff *skb, const struct xt_tee_tginfo *info)
{
const struct iphdr *iph = ip_hdr(skb);
struct net *net = pick_net(skb);
struct rtable *rt;
struct flowi4 fl4;
memset(&fl4, 0, sizeof(fl4));
if (info->priv) {
if (info->priv->oif == -1)
return false;
fl4.flowi4_oif = info->priv->oif;
}
fl4.daddr = info->gw.ip;
fl4.flowi4_tos = RT_TOS(iph->tos);
fl4.flowi4_scope = RT_SCOPE_UNIVERSE;
fl4.flowi4_flags = FLOWI_FLAG_KNOWN_NH;
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt))
return false;
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
skb->dev = rt->dst.dev;
skb->protocol = htons(ETH_P_IP);
return true;
}
static unsigned int
tee_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_tee_tginfo *info = par->targinfo;
struct iphdr *iph;
if (__this_cpu_read(tee_active))
return XT_CONTINUE;
skb = pskb_copy(skb, GFP_ATOMIC);
if (skb == NULL)
return XT_CONTINUE;
#ifdef WITH_CONNTRACK
nf_conntrack_put(skb->nfct);
skb->nfct = &nf_ct_untracked_get()->ct_general;
skb->nfctinfo = IP_CT_NEW;
nf_conntrack_get(skb->nfct);
#endif
iph = ip_hdr(skb);
iph->frag_off |= htons(IP_DF);
if (par->hooknum == NF_INET_PRE_ROUTING ||
par->hooknum == NF_INET_LOCAL_IN)
--iph->ttl;
ip_send_check(iph);
if (tee_tg_route4(skb, info)) {
__this_cpu_write(tee_active, true);
ip_local_out(skb);
__this_cpu_write(tee_active, false);
} else {
kfree_skb(skb);
}
return XT_CONTINUE;
}
static bool
tee_tg_route6(struct sk_buff *skb, const struct xt_tee_tginfo *info)
{
const struct ipv6hdr *iph = ipv6_hdr(skb);
struct net *net = pick_net(skb);
struct dst_entry *dst;
struct flowi6 fl6;
memset(&fl6, 0, sizeof(fl6));
if (info->priv) {
if (info->priv->oif == -1)
return false;
fl6.flowi6_oif = info->priv->oif;
}
fl6.daddr = info->gw.in6;
fl6.flowlabel = ((iph->flow_lbl[0] & 0xF) << 16) |
(iph->flow_lbl[1] << 8) | iph->flow_lbl[2];
fl6.flowi6_flags = FLOWI_FLAG_KNOWN_NH;
dst = ip6_route_output(net, NULL, &fl6);
if (dst->error) {
dst_release(dst);
return false;
}
skb_dst_drop(skb);
skb_dst_set(skb, dst);
skb->dev = dst->dev;
skb->protocol = htons(ETH_P_IPV6);
return true;
}
static unsigned int
tee_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_tee_tginfo *info = par->targinfo;
if (__this_cpu_read(tee_active))
return XT_CONTINUE;
skb = pskb_copy(skb, GFP_ATOMIC);
if (skb == NULL)
return XT_CONTINUE;
#ifdef WITH_CONNTRACK
nf_conntrack_put(skb->nfct);
skb->nfct = &nf_ct_untracked_get()->ct_general;
skb->nfctinfo = IP_CT_NEW;
nf_conntrack_get(skb->nfct);
#endif
if (par->hooknum == NF_INET_PRE_ROUTING ||
par->hooknum == NF_INET_LOCAL_IN) {
struct ipv6hdr *iph = ipv6_hdr(skb);
--iph->hop_limit;
}
if (tee_tg_route6(skb, info)) {
__this_cpu_write(tee_active, true);
ip6_local_out(skb);
__this_cpu_write(tee_active, false);
} else {
kfree_skb(skb);
}
return XT_CONTINUE;
}
static int tee_netdev_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct xt_tee_priv *priv;
priv = container_of(this, struct xt_tee_priv, notifier);
switch (event) {
case NETDEV_REGISTER:
if (!strcmp(dev->name, priv->tginfo->oif))
priv->oif = dev->ifindex;
break;
case NETDEV_UNREGISTER:
if (dev->ifindex == priv->oif)
priv->oif = -1;
break;
case NETDEV_CHANGENAME:
if (!strcmp(dev->name, priv->tginfo->oif))
priv->oif = dev->ifindex;
else if (dev->ifindex == priv->oif)
priv->oif = -1;
break;
}
return NOTIFY_DONE;
}
static int tee_tg_check(const struct xt_tgchk_param *par)
{
struct xt_tee_tginfo *info = par->targinfo;
struct xt_tee_priv *priv;
if (memcmp(&info->gw, &tee_zero_address,
sizeof(tee_zero_address)) == 0)
return -EINVAL;
if (info->oif[0]) {
if (info->oif[sizeof(info->oif)-1] != '\0')
return -EINVAL;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
priv->tginfo = info;
priv->oif = -1;
priv->notifier.notifier_call = tee_netdev_event;
info->priv = priv;
register_netdevice_notifier(&priv->notifier);
} else
info->priv = NULL;
return 0;
}
static void tee_tg_destroy(const struct xt_tgdtor_param *par)
{
struct xt_tee_tginfo *info = par->targinfo;
if (info->priv) {
unregister_netdevice_notifier(&info->priv->notifier);
kfree(info->priv);
}
}
static int __init tee_tg_init(void)
{
return xt_register_targets(tee_tg_reg, ARRAY_SIZE(tee_tg_reg));
}
static void __exit tee_tg_exit(void)
{
xt_unregister_targets(tee_tg_reg, ARRAY_SIZE(tee_tg_reg));
}
