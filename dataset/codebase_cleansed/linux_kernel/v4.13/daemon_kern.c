static void daemon_init(struct net_device *dev, void *data)
{
struct uml_net_private *pri;
struct daemon_data *dpri;
struct daemon_init *init = data;
pri = netdev_priv(dev);
dpri = (struct daemon_data *) pri->user;
dpri->sock_type = init->sock_type;
dpri->ctl_sock = init->ctl_sock;
dpri->fd = -1;
dpri->control = -1;
dpri->dev = dev;
dpri->ctl_addr = NULL;
dpri->data_addr = NULL;
dpri->local_addr = NULL;
printk("daemon backend (uml_switch version %d) - %s:%s",
SWITCH_VERSION, dpri->sock_type, dpri->ctl_sock);
printk("\n");
}
static int daemon_read(int fd, struct sk_buff *skb, struct uml_net_private *lp)
{
return net_recvfrom(fd, skb_mac_header(skb),
skb->dev->mtu + ETH_HEADER_OTHER);
}
static int daemon_write(int fd, struct sk_buff *skb, struct uml_net_private *lp)
{
return daemon_user_write(fd, skb->data, skb->len,
(struct daemon_data *) &lp->user);
}
static int daemon_setup(char *str, char **mac_out, void *data)
{
struct daemon_init *init = data;
char *remain;
*init = ((struct daemon_init)
{ .sock_type = "unix",
.ctl_sock = "/tmp/uml.ctl" });
remain = split_if_spec(str, mac_out, &init->sock_type, &init->ctl_sock,
NULL);
if (remain != NULL)
printk(KERN_WARNING "daemon_setup : Ignoring data socket "
"specification\n");
return 1;
}
static int register_daemon(void)
{
register_transport(&daemon_transport);
return 0;
}
