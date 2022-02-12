static char *split_if_spec(char *str, ...)
{
char **arg, *end;
va_list ap;
va_start(ap, str);
while ((arg = va_arg(ap, char**)) != NULL) {
if (*str == '\0') {
va_end(ap);
return NULL;
}
end = strchr(str, ',');
if (end != str)
*arg = str;
if (end == NULL) {
va_end(ap);
return NULL;
}
*end++ = '\0';
str = end;
}
va_end(ap);
return str;
}
static void setup_etheraddr(struct net_device *dev, char *str)
{
unsigned char *addr = dev->dev_addr;
if (str == NULL)
goto random;
if (!mac_pton(str, addr)) {
pr_err("%s: failed to parse '%s' as an ethernet address\n",
dev->name, str);
goto random;
}
if (is_multicast_ether_addr(addr)) {
pr_err("%s: attempt to assign a multicast ethernet address\n",
dev->name);
goto random;
}
if (!is_valid_ether_addr(addr)) {
pr_err("%s: attempt to assign an invalid ethernet address\n",
dev->name);
goto random;
}
if (!is_local_ether_addr(addr))
pr_warn("%s: assigning a globally valid ethernet address\n",
dev->name);
return;
random:
pr_info("%s: choosing a random ethernet address\n",
dev->name);
eth_hw_addr_random(dev);
}
static int tuntap_open(struct iss_net_private *lp)
{
struct ifreq ifr;
char *dev_name = lp->tp.info.tuntap.dev_name;
int err = -EINVAL;
int fd;
fd = simc_open("/dev/net/tun", 02, 0);
if (fd < 0) {
pr_err("%s: failed to open /dev/net/tun, returned %d (errno = %d)\n",
lp->dev->name, fd, errno);
return fd;
}
memset(&ifr, 0, sizeof(ifr));
ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
strlcpy(ifr.ifr_name, dev_name, sizeof(ifr.ifr_name));
err = simc_ioctl(fd, TUNSETIFF, &ifr);
if (err < 0) {
pr_err("%s: failed to set interface %s, returned %d (errno = %d)\n",
lp->dev->name, dev_name, err, errno);
simc_close(fd);
return err;
}
lp->tp.info.tuntap.fd = fd;
return err;
}
static void tuntap_close(struct iss_net_private *lp)
{
simc_close(lp->tp.info.tuntap.fd);
lp->tp.info.tuntap.fd = -1;
}
static int tuntap_read(struct iss_net_private *lp, struct sk_buff **skb)
{
return simc_read(lp->tp.info.tuntap.fd,
(*skb)->data, (*skb)->dev->mtu + ETH_HEADER_OTHER);
}
static int tuntap_write(struct iss_net_private *lp, struct sk_buff **skb)
{
return simc_write(lp->tp.info.tuntap.fd, (*skb)->data, (*skb)->len);
}
unsigned short tuntap_protocol(struct sk_buff *skb)
{
return eth_type_trans(skb, skb->dev);
}
static int tuntap_poll(struct iss_net_private *lp)
{
return simc_poll(lp->tp.info.tuntap.fd);
}
static int tuntap_probe(struct iss_net_private *lp, int index, char *init)
{
struct net_device *dev = lp->dev;
char *dev_name = NULL, *mac_str = NULL, *rem = NULL;
if (strncmp(init, TRANSPORT_TUNTAP_NAME,
sizeof(TRANSPORT_TUNTAP_NAME) - 1))
return 0;
init += sizeof(TRANSPORT_TUNTAP_NAME) - 1;
if (*init == ',') {
rem = split_if_spec(init + 1, &mac_str, &dev_name);
if (rem != NULL) {
pr_err("%s: extra garbage on specification : '%s'\n",
dev->name, rem);
return 0;
}
} else if (*init != '\0') {
pr_err("%s: invalid argument: %s. Skipping device!\n",
dev->name, init);
return 0;
}
if (!dev_name) {
pr_err("%s: missing tuntap device name\n", dev->name);
return 0;
}
strlcpy(lp->tp.info.tuntap.dev_name, dev_name,
sizeof(lp->tp.info.tuntap.dev_name));
setup_etheraddr(dev, mac_str);
lp->mtu = TRANSPORT_TUNTAP_MTU;
lp->tp.info.tuntap.fd = -1;
lp->tp.open = tuntap_open;
lp->tp.close = tuntap_close;
lp->tp.read = tuntap_read;
lp->tp.write = tuntap_write;
lp->tp.protocol = tuntap_protocol;
lp->tp.poll = tuntap_poll;
return 1;
}
static int iss_net_rx(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
int pkt_len;
struct sk_buff *skb;
if (lp->tp.poll(lp) == 0)
return 0;
skb = dev_alloc_skb(dev->mtu + 2 + ETH_HEADER_OTHER);
if (skb == NULL) {
lp->stats.rx_dropped++;
return 0;
}
skb_reserve(skb, 2);
skb->dev = dev;
skb_reset_mac_header(skb);
pkt_len = lp->tp.read(lp, &skb);
skb_put(skb, pkt_len);
if (pkt_len > 0) {
skb_trim(skb, pkt_len);
skb->protocol = lp->tp.protocol(skb);
lp->stats.rx_bytes += skb->len;
lp->stats.rx_packets++;
netif_rx_ni(skb);
return pkt_len;
}
kfree_skb(skb);
return pkt_len;
}
static int iss_net_poll(void)
{
struct list_head *ele;
int err, ret = 0;
spin_lock(&opened_lock);
list_for_each(ele, &opened) {
struct iss_net_private *lp;
lp = list_entry(ele, struct iss_net_private, opened_list);
if (!netif_running(lp->dev))
break;
spin_lock(&lp->lock);
while ((err = iss_net_rx(lp->dev)) > 0)
ret++;
spin_unlock(&lp->lock);
if (err < 0) {
pr_err("Device '%s' read returned %d, shutting it down\n",
lp->dev->name, err);
dev_close(lp->dev);
} else {
}
}
spin_unlock(&opened_lock);
return ret;
}
static void iss_net_timer(unsigned long priv)
{
struct iss_net_private *lp = (struct iss_net_private *)priv;
iss_net_poll();
spin_lock(&lp->lock);
mod_timer(&lp->timer, jiffies + lp->timer_val);
spin_unlock(&lp->lock);
}
static int iss_net_open(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
int err;
spin_lock_bh(&lp->lock);
err = lp->tp.open(lp);
if (err < 0)
goto out;
netif_start_queue(dev);
while ((err = iss_net_rx(dev)) > 0)
;
spin_unlock_bh(&lp->lock);
spin_lock_bh(&opened_lock);
list_add(&lp->opened_list, &opened);
spin_unlock_bh(&opened_lock);
spin_lock_bh(&lp->lock);
init_timer(&lp->timer);
lp->timer_val = ISS_NET_TIMER_VALUE;
lp->timer.data = (unsigned long) lp;
lp->timer.function = iss_net_timer;
mod_timer(&lp->timer, jiffies + lp->timer_val);
out:
spin_unlock_bh(&lp->lock);
return err;
}
static int iss_net_close(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
netif_stop_queue(dev);
spin_lock_bh(&lp->lock);
spin_lock(&opened_lock);
list_del(&opened);
spin_unlock(&opened_lock);
del_timer_sync(&lp->timer);
lp->tp.close(lp);
spin_unlock_bh(&lp->lock);
return 0;
}
static int iss_net_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
int len;
netif_stop_queue(dev);
spin_lock_bh(&lp->lock);
len = lp->tp.write(lp, &skb);
if (len == skb->len) {
lp->stats.tx_packets++;
lp->stats.tx_bytes += skb->len;
netif_trans_update(dev);
netif_start_queue(dev);
netif_wake_queue(dev);
} else if (len == 0) {
netif_start_queue(dev);
lp->stats.tx_dropped++;
} else {
netif_start_queue(dev);
pr_err("%s: %s failed(%d)\n", dev->name, __func__, len);
}
spin_unlock_bh(&lp->lock);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static struct net_device_stats *iss_net_get_stats(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
return &lp->stats;
}
static void iss_net_set_multicast_list(struct net_device *dev)
{
}
static void iss_net_tx_timeout(struct net_device *dev)
{
}
static int iss_net_set_mac(struct net_device *dev, void *addr)
{
struct iss_net_private *lp = netdev_priv(dev);
struct sockaddr *hwaddr = addr;
if (!is_valid_ether_addr(hwaddr->sa_data))
return -EADDRNOTAVAIL;
spin_lock_bh(&lp->lock);
memcpy(dev->dev_addr, hwaddr->sa_data, ETH_ALEN);
spin_unlock_bh(&lp->lock);
return 0;
}
static int iss_net_change_mtu(struct net_device *dev, int new_mtu)
{
return -EINVAL;
}
void iss_net_user_timer_expire(unsigned long _conn)
{
}
static int iss_net_configure(int index, char *init)
{
struct net_device *dev;
struct iss_net_private *lp;
int err;
dev = alloc_etherdev(sizeof(*lp));
if (dev == NULL) {
pr_err("eth_configure: failed to allocate device\n");
return 1;
}
lp = netdev_priv(dev);
*lp = (struct iss_net_private) {
.device_list = LIST_HEAD_INIT(lp->device_list),
.opened_list = LIST_HEAD_INIT(lp->opened_list),
.dev = dev,
.index = index,
};
spin_lock_init(&lp->lock);
snprintf(dev->name, sizeof(dev->name), "eth%d", index);
if (!tuntap_probe(lp, index, init)) {
pr_err("%s: invalid arguments. Skipping device!\n",
dev->name);
goto errout;
}
pr_info("Netdevice %d (%pM)\n", index, dev->dev_addr);
if (!driver_registered) {
platform_driver_register(&iss_net_driver);
driver_registered = 1;
}
spin_lock(&devices_lock);
list_add(&lp->device_list, &devices);
spin_unlock(&devices_lock);
lp->pdev.id = index;
lp->pdev.name = DRIVER_NAME;
platform_device_register(&lp->pdev);
SET_NETDEV_DEV(dev, &lp->pdev.dev);
dev->netdev_ops = &iss_netdev_ops;
dev->mtu = lp->mtu;
dev->watchdog_timeo = (HZ >> 1);
dev->irq = -1;
rtnl_lock();
err = register_netdevice(dev);
rtnl_unlock();
if (err) {
pr_err("%s: error registering net device!\n", dev->name);
free_netdev(dev);
return 1;
}
init_timer(&lp->tl);
lp->tl.function = iss_net_user_timer_expire;
return 0;
errout:
return -EIO;
}
static int __init iss_net_setup(char *str)
{
struct iss_net_private *device = NULL;
struct iss_net_init *new;
struct list_head *ele;
char *end;
int rc;
unsigned n;
end = strchr(str, '=');
if (!end) {
printk(ERR "Expected '=' after device number\n");
return 1;
}
*end = 0;
rc = kstrtouint(str, 0, &n);
*end = '=';
if (rc < 0) {
printk(ERR "Failed to parse '%s'\n", str);
return 1;
}
str = end;
spin_lock(&devices_lock);
list_for_each(ele, &devices) {
device = list_entry(ele, struct iss_net_private, device_list);
if (device->index == n)
break;
}
spin_unlock(&devices_lock);
if (device && device->index == n) {
printk(ERR "Device %u already configured\n", n);
return 1;
}
new = alloc_bootmem(sizeof(*new));
if (new == NULL) {
printk(ERR "Alloc_bootmem failed\n");
return 1;
}
INIT_LIST_HEAD(&new->list);
new->index = n;
new->init = str + 1;
list_add_tail(&new->list, &eth_cmd_line);
return 1;
}
static int iss_net_init(void)
{
struct list_head *ele, *next;
list_for_each_safe(ele, next, &eth_cmd_line) {
struct iss_net_init *eth;
eth = list_entry(ele, struct iss_net_init, list);
iss_net_configure(eth->index, eth->init);
}
return 1;
}
