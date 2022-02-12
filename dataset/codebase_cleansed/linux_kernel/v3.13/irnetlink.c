static struct net_device * ifname_to_netdev(struct net *net, struct genl_info *info)
{
char * ifname;
if (!info->attrs[IRDA_NL_ATTR_IFNAME])
return NULL;
ifname = nla_data(info->attrs[IRDA_NL_ATTR_IFNAME]);
IRDA_DEBUG(5, "%s(): Looking for %s\n", __func__, ifname);
return dev_get_by_name(net, ifname);
}
static int irda_nl_set_mode(struct sk_buff *skb, struct genl_info *info)
{
struct net_device * dev;
struct irlap_cb * irlap;
u32 mode;
if (!info->attrs[IRDA_NL_ATTR_MODE])
return -EINVAL;
mode = nla_get_u32(info->attrs[IRDA_NL_ATTR_MODE]);
IRDA_DEBUG(5, "%s(): Switching to mode: %d\n", __func__, mode);
dev = ifname_to_netdev(&init_net, info);
if (!dev)
return -ENODEV;
irlap = (struct irlap_cb *)dev->atalk_ptr;
if (!irlap) {
dev_put(dev);
return -ENODEV;
}
irlap->mode = mode;
dev_put(dev);
return 0;
}
static int irda_nl_get_mode(struct sk_buff *skb, struct genl_info *info)
{
struct net_device * dev;
struct irlap_cb * irlap;
struct sk_buff *msg;
void *hdr;
int ret = -ENOBUFS;
dev = ifname_to_netdev(&init_net, info);
if (!dev)
return -ENODEV;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg) {
dev_put(dev);
return -ENOMEM;
}
irlap = (struct irlap_cb *)dev->atalk_ptr;
if (!irlap) {
ret = -ENODEV;
goto err_out;
}
hdr = genlmsg_put(msg, info->snd_portid, info->snd_seq,
&irda_nl_family, 0, IRDA_NL_CMD_GET_MODE);
if (hdr == NULL) {
ret = -EMSGSIZE;
goto err_out;
}
if(nla_put_string(msg, IRDA_NL_ATTR_IFNAME,
dev->name))
goto err_out;
if(nla_put_u32(msg, IRDA_NL_ATTR_MODE, irlap->mode))
goto err_out;
genlmsg_end(msg, hdr);
return genlmsg_reply(msg, info);
err_out:
nlmsg_free(msg);
dev_put(dev);
return ret;
}
int irda_nl_register(void)
{
return genl_register_family_with_ops(&irda_nl_family, irda_nl_ops);
}
void irda_nl_unregister(void)
{
genl_unregister_family(&irda_nl_family);
}
