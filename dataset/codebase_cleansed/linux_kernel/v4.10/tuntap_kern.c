static void tuntap_init(struct net_device *dev, void *data)
{
struct uml_net_private *pri;
struct tuntap_data *tpri;
struct tuntap_init *init = data;
pri = netdev_priv(dev);
tpri = (struct tuntap_data *) pri->user;
tpri->dev_name = init->dev_name;
tpri->fixed_config = (init->dev_name != NULL);
tpri->gate_addr = init->gate_addr;
tpri->fd = -1;
tpri->dev = dev;
printk(KERN_INFO "TUN/TAP backend - ");
if (tpri->gate_addr != NULL)
printk(KERN_CONT "IP = %s", tpri->gate_addr);
printk(KERN_CONT "\n");
}
static int tuntap_read(int fd, struct sk_buff *skb, struct uml_net_private *lp)
{
return net_read(fd, skb_mac_header(skb),
skb->dev->mtu + ETH_HEADER_OTHER);
}
static int tuntap_write(int fd, struct sk_buff *skb, struct uml_net_private *lp)
{
return net_write(fd, skb->data, skb->len);
}
int tuntap_setup(char *str, char **mac_out, void *data)
{
struct tuntap_init *init = data;
*init = ((struct tuntap_init)
{ .dev_name = NULL,
.gate_addr = NULL });
if (tap_setup_common(str, "tuntap", &init->dev_name, mac_out,
&init->gate_addr))
return 0;
return 1;
}
static int register_tuntap(void)
{
register_transport(&tuntap_transport);
return 0;
}
