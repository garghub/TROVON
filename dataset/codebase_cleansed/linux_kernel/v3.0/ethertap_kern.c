static void etap_init(struct net_device *dev, void *data)
{
struct uml_net_private *pri;
struct ethertap_data *epri;
struct ethertap_init *init = data;
pri = netdev_priv(dev);
epri = (struct ethertap_data *) pri->user;
epri->dev_name = init->dev_name;
epri->gate_addr = init->gate_addr;
epri->data_fd = -1;
epri->control_fd = -1;
epri->dev = dev;
printk(KERN_INFO "ethertap backend - %s", epri->dev_name);
if (epri->gate_addr != NULL)
printk(KERN_CONT ", IP = %s", epri->gate_addr);
printk(KERN_CONT "\n");
}
static int etap_read(int fd, struct sk_buff *skb, struct uml_net_private *lp)
{
int len;
len = net_recvfrom(fd, skb_mac_header(skb),
skb->dev->mtu + 2 + ETH_HEADER_ETHERTAP);
if (len <= 0)
return(len);
skb_pull(skb, 2);
len -= 2;
return len;
}
static int etap_write(int fd, struct sk_buff *skb, struct uml_net_private *lp)
{
skb_push(skb, 2);
return net_send(fd, skb->data, skb->len);
}
int ethertap_setup(char *str, char **mac_out, void *data)
{
struct ethertap_init *init = data;
*init = ((struct ethertap_init)
{ .dev_name = NULL,
.gate_addr = NULL });
if (tap_setup_common(str, "ethertap", &init->dev_name, mac_out,
&init->gate_addr))
return 0;
if (init->dev_name == NULL) {
printk(KERN_ERR "ethertap_setup : Missing tap device name\n");
return 0;
}
return 1;
}
static int register_ethertap(void)
{
register_transport(&ethertap_transport);
return 0;
}
