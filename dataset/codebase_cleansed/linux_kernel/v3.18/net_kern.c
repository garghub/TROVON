static int update_drop_skb(int max)
{
struct sk_buff *new;
unsigned long flags;
int err = 0;
spin_lock_irqsave(&drop_lock, flags);
if (max <= drop_max)
goto out;
err = -ENOMEM;
new = dev_alloc_skb(max);
if (new == NULL)
goto out;
skb_put(new, max);
kfree_skb(drop_skb);
drop_skb = new;
drop_max = max;
err = 0;
out:
spin_unlock_irqrestore(&drop_lock, flags);
return err;
}
static int uml_net_rx(struct net_device *dev)
{
struct uml_net_private *lp = netdev_priv(dev);
int pkt_len;
struct sk_buff *skb;
skb = dev_alloc_skb(lp->max_packet);
if (skb == NULL) {
drop_skb->dev = dev;
(*lp->read)(lp->fd, drop_skb, lp);
dev->stats.rx_dropped++;
return 0;
}
skb->dev = dev;
skb_put(skb, lp->max_packet);
skb_reset_mac_header(skb);
pkt_len = (*lp->read)(lp->fd, skb, lp);
if (pkt_len > 0) {
skb_trim(skb, pkt_len);
skb->protocol = (*lp->protocol)(skb);
dev->stats.rx_bytes += skb->len;
dev->stats.rx_packets++;
netif_rx(skb);
return pkt_len;
}
kfree_skb(skb);
return pkt_len;
}
static void uml_dev_close(struct work_struct *work)
{
struct uml_net_private *lp =
container_of(work, struct uml_net_private, work);
dev_close(lp->dev);
}
static irqreturn_t uml_net_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct uml_net_private *lp = netdev_priv(dev);
int err;
if (!netif_running(dev))
return IRQ_NONE;
spin_lock(&lp->lock);
while ((err = uml_net_rx(dev)) > 0) ;
if (err < 0) {
printk(KERN_ERR
"Device '%s' read returned %d, shutting it down\n",
dev->name, err);
schedule_work(&lp->work);
goto out;
}
reactivate_fd(lp->fd, UM_ETH_IRQ);
out:
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
static int uml_net_open(struct net_device *dev)
{
struct uml_net_private *lp = netdev_priv(dev);
int err;
if (lp->fd >= 0) {
err = -ENXIO;
goto out;
}
lp->fd = (*lp->open)(&lp->user);
if (lp->fd < 0) {
err = lp->fd;
goto out;
}
err = um_request_irq(dev->irq, lp->fd, IRQ_READ, uml_net_interrupt,
IRQF_SHARED, dev->name, dev);
if (err != 0) {
printk(KERN_ERR "uml_net_open: failed to get irq(%d)\n", err);
err = -ENETUNREACH;
goto out_close;
}
lp->tl.data = (unsigned long) &lp->user;
netif_start_queue(dev);
while ((err = uml_net_rx(dev)) > 0) ;
spin_lock(&opened_lock);
list_add(&lp->list, &opened);
spin_unlock(&opened_lock);
return 0;
out_close:
if (lp->close != NULL) (*lp->close)(lp->fd, &lp->user);
lp->fd = -1;
out:
return err;
}
static int uml_net_close(struct net_device *dev)
{
struct uml_net_private *lp = netdev_priv(dev);
netif_stop_queue(dev);
um_free_irq(dev->irq, dev);
if (lp->close != NULL)
(*lp->close)(lp->fd, &lp->user);
lp->fd = -1;
spin_lock(&opened_lock);
list_del(&lp->list);
spin_unlock(&opened_lock);
return 0;
}
static int uml_net_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct uml_net_private *lp = netdev_priv(dev);
unsigned long flags;
int len;
netif_stop_queue(dev);
spin_lock_irqsave(&lp->lock, flags);
len = (*lp->write)(lp->fd, skb, lp);
skb_tx_timestamp(skb);
if (len == skb->len) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
dev->trans_start = jiffies;
netif_start_queue(dev);
netif_wake_queue(dev);
}
else if (len == 0) {
netif_start_queue(dev);
dev->stats.tx_dropped++;
}
else {
netif_start_queue(dev);
printk(KERN_ERR "uml_net_start_xmit: failed(%d)\n", len);
}
spin_unlock_irqrestore(&lp->lock, flags);
dev_consume_skb_any(skb);
return NETDEV_TX_OK;
}
static void uml_net_set_multicast_list(struct net_device *dev)
{
return;
}
static void uml_net_tx_timeout(struct net_device *dev)
{
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
static int uml_net_change_mtu(struct net_device *dev, int new_mtu)
{
dev->mtu = new_mtu;
return 0;
}
static void uml_net_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
uml_net_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static void uml_net_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRIVER_NAME, sizeof(info->driver));
strlcpy(info->version, "42", sizeof(info->version));
}
static void uml_net_user_timer_expire(unsigned long _conn)
{
#ifdef undef
struct connection *conn = (struct connection *)_conn;
dprintk(KERN_INFO "uml_net_user_timer_expire [%p]\n", conn);
do_connect(conn);
#endif
}
static void setup_etheraddr(struct net_device *dev, char *str)
{
unsigned char *addr = dev->dev_addr;
char *end;
int i;
if (str == NULL)
goto random;
for (i = 0; i < 6; i++) {
addr[i] = simple_strtoul(str, &end, 16);
if ((end == str) ||
((*end != ':') && (*end != ',') && (*end != '\0'))) {
printk(KERN_ERR
"setup_etheraddr: failed to parse '%s' "
"as an ethernet address\n", str);
goto random;
}
str = end + 1;
}
if (is_multicast_ether_addr(addr)) {
printk(KERN_ERR
"Attempt to assign a multicast ethernet address to a "
"device disallowed\n");
goto random;
}
if (!is_valid_ether_addr(addr)) {
printk(KERN_ERR
"Attempt to assign an invalid ethernet address to a "
"device disallowed\n");
goto random;
}
if (!is_local_ether_addr(addr)) {
printk(KERN_WARNING
"Warning: Assigning a globally valid ethernet "
"address to a device\n");
printk(KERN_WARNING "You should set the 2nd rightmost bit in "
"the first byte of the MAC,\n");
printk(KERN_WARNING "i.e. %02x:%02x:%02x:%02x:%02x:%02x\n",
addr[0] | 0x02, addr[1], addr[2], addr[3], addr[4],
addr[5]);
}
return;
random:
printk(KERN_INFO
"Choosing a random ethernet address for device %s\n", dev->name);
eth_hw_addr_random(dev);
}
static void net_device_release(struct device *dev)
{
struct uml_net *device = dev_get_drvdata(dev);
struct net_device *netdev = device->dev;
struct uml_net_private *lp = netdev_priv(netdev);
if (lp->remove != NULL)
(*lp->remove)(&lp->user);
list_del(&device->list);
kfree(device);
free_netdev(netdev);
}
static void eth_configure(int n, void *init, char *mac,
struct transport *transport)
{
struct uml_net *device;
struct net_device *dev;
struct uml_net_private *lp;
int err, size;
size = transport->private_size + sizeof(struct uml_net_private);
device = kzalloc(sizeof(*device), GFP_KERNEL);
if (device == NULL) {
printk(KERN_ERR "eth_configure failed to allocate struct "
"uml_net\n");
return;
}
dev = alloc_etherdev(size);
if (dev == NULL) {
printk(KERN_ERR "eth_configure: failed to allocate struct "
"net_device for eth%d\n", n);
goto out_free_device;
}
INIT_LIST_HEAD(&device->list);
device->index = n;
snprintf(dev->name, sizeof(dev->name), "eth%d", n);
setup_etheraddr(dev, mac);
printk(KERN_INFO "Netdevice %d (%pM) : ", n, dev->dev_addr);
lp = netdev_priv(dev);
memset(lp, 0, size);
INIT_WORK(&lp->work, uml_dev_close);
if (!driver_registered) {
platform_driver_register(&uml_net_driver);
driver_registered = 1;
}
device->pdev.id = n;
device->pdev.name = DRIVER_NAME;
device->pdev.dev.release = net_device_release;
dev_set_drvdata(&device->pdev.dev, device);
if (platform_device_register(&device->pdev))
goto out_free_netdev;
SET_NETDEV_DEV(dev,&device->pdev.dev);
device->dev = dev;
(*transport->kern->init)(dev, init);
*lp = ((struct uml_net_private)
{ .list = LIST_HEAD_INIT(lp->list),
.dev = dev,
.fd = -1,
.mac = { 0xfe, 0xfd, 0x0, 0x0, 0x0, 0x0},
.max_packet = transport->user->max_packet,
.protocol = transport->kern->protocol,
.open = transport->user->open,
.close = transport->user->close,
.remove = transport->user->remove,
.read = transport->kern->read,
.write = transport->kern->write,
.add_address = transport->user->add_address,
.delete_address = transport->user->delete_address });
init_timer(&lp->tl);
spin_lock_init(&lp->lock);
lp->tl.function = uml_net_user_timer_expire;
memcpy(lp->mac, dev->dev_addr, sizeof(lp->mac));
if ((transport->user->init != NULL) &&
((*transport->user->init)(&lp->user, dev) != 0))
goto out_unregister;
dev->mtu = transport->user->mtu;
dev->netdev_ops = &uml_netdev_ops;
dev->ethtool_ops = &uml_net_ethtool_ops;
dev->watchdog_timeo = (HZ >> 1);
dev->irq = UM_ETH_IRQ;
err = update_drop_skb(lp->max_packet);
if (err)
goto out_undo_user_init;
rtnl_lock();
err = register_netdevice(dev);
rtnl_unlock();
if (err)
goto out_undo_user_init;
spin_lock(&devices_lock);
list_add(&device->list, &devices);
spin_unlock(&devices_lock);
return;
out_undo_user_init:
if (transport->user->remove != NULL)
(*transport->user->remove)(&lp->user);
out_unregister:
platform_device_unregister(&device->pdev);
return;
out_free_netdev:
free_netdev(dev);
out_free_device:
kfree(device);
}
static struct uml_net *find_device(int n)
{
struct uml_net *device;
struct list_head *ele;
spin_lock(&devices_lock);
list_for_each(ele, &devices) {
device = list_entry(ele, struct uml_net, list);
if (device->index == n)
goto out;
}
device = NULL;
out:
spin_unlock(&devices_lock);
return device;
}
static int eth_parse(char *str, int *index_out, char **str_out,
char **error_out)
{
char *end;
int n, err = -EINVAL;
n = simple_strtoul(str, &end, 0);
if (end == str) {
*error_out = "Bad device number";
return err;
}
str = end;
if (*str != '=') {
*error_out = "Expected '=' after device number";
return err;
}
str++;
if (find_device(n)) {
*error_out = "Device already configured";
return err;
}
*index_out = n;
*str_out = str;
return 0;
}
static int check_transport(struct transport *transport, char *eth, int n,
void **init_out, char **mac_out)
{
int len;
len = strlen(transport->name);
if (strncmp(eth, transport->name, len))
return 0;
eth += len;
if (*eth == ',')
eth++;
else if (*eth != '\0')
return 0;
*init_out = kmalloc(transport->setup_size, GFP_KERNEL);
if (*init_out == NULL)
return 1;
if (!transport->setup(eth, mac_out, *init_out)) {
kfree(*init_out);
*init_out = NULL;
}
return 1;
}
void register_transport(struct transport *new)
{
struct list_head *ele, *next;
struct eth_init *eth;
void *init;
char *mac = NULL;
int match;
spin_lock(&transports_lock);
BUG_ON(!list_empty(&new->list));
list_add(&new->list, &transports);
spin_unlock(&transports_lock);
list_for_each_safe(ele, next, &eth_cmd_line) {
eth = list_entry(ele, struct eth_init, list);
match = check_transport(new, eth->init, eth->index, &init,
&mac);
if (!match)
continue;
else if (init != NULL) {
eth_configure(eth->index, init, mac, new);
kfree(init);
}
list_del(&eth->list);
}
}
static int eth_setup_common(char *str, int index)
{
struct list_head *ele;
struct transport *transport;
void *init;
char *mac = NULL;
int found = 0;
spin_lock(&transports_lock);
list_for_each(ele, &transports) {
transport = list_entry(ele, struct transport, list);
if (!check_transport(transport, str, index, &init, &mac))
continue;
if (init != NULL) {
eth_configure(index, init, mac, transport);
kfree(init);
}
found = 1;
break;
}
spin_unlock(&transports_lock);
return found;
}
static int __init eth_setup(char *str)
{
struct eth_init *new;
char *error;
int n, err;
err = eth_parse(str, &n, &str, &error);
if (err) {
printk(KERN_ERR "eth_setup - Couldn't parse '%s' : %s\n",
str, error);
return 1;
}
new = alloc_bootmem(sizeof(*new));
INIT_LIST_HEAD(&new->list);
new->index = n;
new->init = str;
list_add_tail(&new->list, &eth_cmd_line);
return 1;
}
static int net_config(char *str, char **error_out)
{
int n, err;
err = eth_parse(str, &n, &str, error_out);
if (err)
return err;
str = kstrdup(str, GFP_KERNEL);
if (str == NULL) {
*error_out = "net_config failed to strdup string";
return -ENOMEM;
}
err = !eth_setup_common(str, n);
if (err)
kfree(str);
return err;
}
static int net_id(char **str, int *start_out, int *end_out)
{
char *end;
int n;
n = simple_strtoul(*str, &end, 0);
if ((*end != '\0') || (end == *str))
return -1;
*start_out = n;
*end_out = n;
*str = end;
return n;
}
static int net_remove(int n, char **error_out)
{
struct uml_net *device;
struct net_device *dev;
struct uml_net_private *lp;
device = find_device(n);
if (device == NULL)
return -ENODEV;
dev = device->dev;
lp = netdev_priv(dev);
if (lp->fd > 0)
return -EBUSY;
unregister_netdev(dev);
platform_device_unregister(&device->pdev);
return 0;
}
static int uml_inetaddr_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct in_ifaddr *ifa = ptr;
struct net_device *dev = ifa->ifa_dev->dev;
struct uml_net_private *lp;
void (*proc)(unsigned char *, unsigned char *, void *);
unsigned char addr_buf[4], netmask_buf[4];
if (dev->netdev_ops->ndo_open != uml_net_open)
return NOTIFY_DONE;
lp = netdev_priv(dev);
proc = NULL;
switch (event) {
case NETDEV_UP:
proc = lp->add_address;
break;
case NETDEV_DOWN:
proc = lp->delete_address;
break;
}
if (proc != NULL) {
memcpy(addr_buf, &ifa->ifa_address, sizeof(addr_buf));
memcpy(netmask_buf, &ifa->ifa_mask, sizeof(netmask_buf));
(*proc)(addr_buf, netmask_buf, &lp->user);
}
return NOTIFY_DONE;
}
static void inet_register(void)
{
struct list_head *ele;
struct uml_net_private *lp;
struct in_device *ip;
struct in_ifaddr *in;
register_inetaddr_notifier(&uml_inetaddr_notifier);
spin_lock(&opened_lock);
list_for_each(ele, &opened) {
lp = list_entry(ele, struct uml_net_private, list);
ip = lp->dev->ip_ptr;
if (ip == NULL)
continue;
in = ip->ifa_list;
while (in != NULL) {
uml_inetaddr_event(NULL, NETDEV_UP, in);
in = in->ifa_next;
}
}
spin_unlock(&opened_lock);
}
static inline void inet_register(void)
{
}
static int uml_net_init(void)
{
mconsole_register_dev(&net_mc);
inet_register();
return 0;
}
static void close_devices(void)
{
struct list_head *ele;
struct uml_net_private *lp;
spin_lock(&opened_lock);
list_for_each(ele, &opened) {
lp = list_entry(ele, struct uml_net_private, list);
um_free_irq(lp->dev->irq, lp->dev);
if ((lp->close != NULL) && (lp->fd >= 0))
(*lp->close)(lp->fd, &lp->user);
if (lp->remove != NULL)
(*lp->remove)(&lp->user);
}
spin_unlock(&opened_lock);
}
void iter_addresses(void *d, void (*cb)(unsigned char *, unsigned char *,
void *),
void *arg)
{
struct net_device *dev = d;
struct in_device *ip = dev->ip_ptr;
struct in_ifaddr *in;
unsigned char address[4], netmask[4];
if (ip == NULL) return;
in = ip->ifa_list;
while (in != NULL) {
memcpy(address, &in->ifa_address, sizeof(address));
memcpy(netmask, &in->ifa_mask, sizeof(netmask));
(*cb)(address, netmask, arg);
in = in->ifa_next;
}
}
int dev_netmask(void *d, void *m)
{
struct net_device *dev = d;
struct in_device *ip = dev->ip_ptr;
struct in_ifaddr *in;
__be32 *mask_out = m;
if (ip == NULL)
return 1;
in = ip->ifa_list;
if (in == NULL)
return 1;
*mask_out = in->ifa_mask;
return 0;
}
void *get_output_buffer(int *len_out)
{
void *ret;
ret = (void *) __get_free_pages(GFP_KERNEL, 0);
if (ret) *len_out = PAGE_SIZE;
else *len_out = 0;
return ret;
}
void free_output_buffer(void *buffer)
{
free_pages((unsigned long) buffer, 0);
}
int tap_setup_common(char *str, char *type, char **dev_name, char **mac_out,
char **gate_addr)
{
char *remain;
remain = split_if_spec(str, dev_name, mac_out, gate_addr, NULL);
if (remain != NULL) {
printk(KERN_ERR "tap_setup_common - Extra garbage on "
"specification : '%s'\n", remain);
return 1;
}
return 0;
}
unsigned short eth_protocol(struct sk_buff *skb)
{
return eth_type_trans(skb, skb->dev);
}
