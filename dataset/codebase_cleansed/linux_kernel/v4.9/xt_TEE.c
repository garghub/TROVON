static unsigned int
tee_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_tee_tginfo *info = par->targinfo;
int oif = info->priv ? info->priv->oif : 0;
nf_dup_ipv4(par->net, skb, par->hooknum, &info->gw.in, oif);
return XT_CONTINUE;
}
static unsigned int
tee_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_tee_tginfo *info = par->targinfo;
int oif = info->priv ? info->priv->oif : 0;
nf_dup_ipv6(par->net, skb, par->hooknum, &info->gw.in6, oif);
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
int ret;
if (info->oif[sizeof(info->oif)-1] != '\0')
return -EINVAL;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
priv->tginfo = info;
priv->oif = -1;
priv->notifier.notifier_call = tee_netdev_event;
info->priv = priv;
ret = register_netdevice_notifier(&priv->notifier);
if (ret) {
kfree(priv);
return ret;
}
} else
info->priv = NULL;
static_key_slow_inc(&xt_tee_enabled);
return 0;
}
static void tee_tg_destroy(const struct xt_tgdtor_param *par)
{
struct xt_tee_tginfo *info = par->targinfo;
if (info->priv) {
unregister_netdevice_notifier(&info->priv->notifier);
kfree(info->priv);
}
static_key_slow_dec(&xt_tee_enabled);
}
static int __init tee_tg_init(void)
{
return xt_register_targets(tee_tg_reg, ARRAY_SIZE(tee_tg_reg));
}
static void __exit tee_tg_exit(void)
{
xt_unregister_targets(tee_tg_reg, ARRAY_SIZE(tee_tg_reg));
}
