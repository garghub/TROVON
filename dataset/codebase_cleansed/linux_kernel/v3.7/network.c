static char *split_if_spec(char *str, ...)
{
char **arg, *end;
va_list ap;
va_start(ap, str);
while ((arg = va_arg(ap, char**)) != NULL) {
if (*str == '\0')
return NULL;
end = strchr(str, ',');
if (end != str)
*arg = str;
if (end == NULL)
return NULL;
*end ++ = '\0';
str = end;
}
va_end(ap);
return str;
}
static void dev_ip_addr(void *d, char *buf, char *bin_buf)
{
struct net_device *dev = d;
struct in_device *ip = dev->ip_ptr;
struct in_ifaddr *in;
__be32 addr;
if ((ip == NULL) || ((in = ip->ifa_list) == NULL)) {
printk(KERN_WARNING "Device not assigned an IP address!\n");
return;
}
addr = in->ifa_address;
sprintf(buf, "%d.%d.%d.%d", addr & 0xff, (addr >> 8) & 0xff,
(addr >> 16) & 0xff, addr >> 24);
if (bin_buf) {
bin_buf[0] = addr & 0xff;
bin_buf[1] = (addr >> 8) & 0xff;
bin_buf[2] = (addr >> 16) & 0xff;
bin_buf[3] = addr >> 24;
}
}
static void inline set_ether_mac(void *d, unsigned char *addr)
{
struct net_device *dev = d;
memcpy(dev->dev_addr, addr, ETH_ALEN);
}
static int tuntap_open(struct iss_net_private *lp)
{
struct ifreq ifr;
char *dev_name = lp->tp.info.tuntap.dev_name;
int err = -EINVAL;
int fd;
if (!lp->tp.info.tuntap.fixed_config)
return -EINVAL;
if ((fd = simc_open("/dev/net/tun", 02, 0)) < 0) {
printk("Failed to open /dev/net/tun, returned %d "
"(errno = %d)\n", fd, errno);
return fd;
}
memset(&ifr, 0, sizeof ifr);
ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
strlcpy(ifr.ifr_name, dev_name, sizeof ifr.ifr_name);
if ((err = simc_ioctl(fd, TUNSETIFF, (void*) &ifr)) < 0) {
printk("Failed to set interface, returned %d "
"(errno = %d)\n", err, errno);
simc_close(fd);
return err;
}
lp->tp.info.tuntap.fd = fd;
return err;
}
static void tuntap_close(struct iss_net_private *lp)
{
#if 0
if (lp->tp.info.tuntap.fixed_config)
iter_addresses(lp->tp.info.tuntap.dev, close_addr, lp->host.dev_name);
#endif
simc_close(lp->tp.info.tuntap.fd);
lp->tp.info.tuntap.fd = -1;
}
static int tuntap_read (struct iss_net_private *lp, struct sk_buff **skb)
{
#if 0
*skb = ether_adjust_skb(*skb, ETH_HEADER_OTHER);
if (*skb == NULL)
return -ENOMEM;
#endif
return simc_read(lp->tp.info.tuntap.fd,
(*skb)->data, (*skb)->dev->mtu + ETH_HEADER_OTHER);
}
static int tuntap_write (struct iss_net_private *lp, struct sk_buff **skb)
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
const int len = strlen(TRANSPORT_TUNTAP_NAME);
char *dev_name = NULL, *mac_str = NULL, *rem = NULL;
if (strncmp(init, TRANSPORT_TUNTAP_NAME, len))
return 0;
if (*(init += strlen(TRANSPORT_TUNTAP_NAME)) == ',') {
if ((rem=split_if_spec(init+1, &mac_str, &dev_name)) != NULL) {
printk("Extra garbage on specification : '%s'\n", rem);
return 0;
}
} else if (*init != '\0') {
printk("Invalid argument: %s. Skipping device!\n", init);
return 0;
}
if (dev_name) {
strncpy(lp->tp.info.tuntap.dev_name, dev_name,
sizeof lp->tp.info.tuntap.dev_name);
lp->tp.info.tuntap.fixed_config = 1;
} else
strcpy(lp->tp.info.tuntap.dev_name, TRANSPORT_TUNTAP_NAME);
#if 0
if (setup_etheraddr(mac_str, lp->mac))
lp->have_mac = 1;
#endif
lp->mtu = TRANSPORT_TUNTAP_MTU;
lp->tp.info.tuntap.fd = -1;
lp->tp.open = tuntap_open;
lp->tp.close = tuntap_close;
lp->tp.read = tuntap_read;
lp->tp.write = tuntap_write;
lp->tp.protocol = tuntap_protocol;
lp->tp.poll = tuntap_poll;
printk("TUN/TAP backend - ");
#if 0
if (lp->host.gate_addr != NULL)
printk("IP = %s", lp->host.gate_addr);
#endif
printk("\n");
return 1;
}
static int iss_net_rx(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
int pkt_len;
struct sk_buff *skb;
if (lp->tp.poll(lp) == 0)
return 0;
if ((skb = dev_alloc_skb(dev->mtu + 2 + ETH_HEADER_OTHER)) == NULL) {
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
printk(KERN_ERR "Device '%s' read returned %d, "
"shutting it down\n", lp->dev->name, err);
dev_close(lp->dev);
} else {
}
}
spin_unlock(&opened_lock);
return ret;
}
static void iss_net_timer(unsigned long priv)
{
struct iss_net_private* lp = (struct iss_net_private*) priv;
spin_lock(&lp->lock);
iss_net_poll();
mod_timer(&lp->timer, jiffies + lp->timer_val);
spin_unlock(&lp->lock);
}
static int iss_net_open(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
char addr[sizeof "255.255.255.255\0"];
int err;
spin_lock(&lp->lock);
if ((err = lp->tp.open(lp)) < 0)
goto out;
if (!lp->have_mac) {
dev_ip_addr(dev, addr, &lp->mac[2]);
set_ether_mac(dev, lp->mac);
}
netif_start_queue(dev);
while ((err = iss_net_rx(dev)) > 0)
;
spin_lock(&opened_lock);
list_add(&lp->opened_list, &opened);
spin_unlock(&opened_lock);
init_timer(&lp->timer);
lp->timer_val = ISS_NET_TIMER_VALUE;
lp->timer.data = (unsigned long) lp;
lp->timer.function = iss_net_timer;
mod_timer(&lp->timer, jiffies + lp->timer_val);
out:
spin_unlock(&lp->lock);
return err;
}
static int iss_net_close(struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
printk("iss_net_close!\n");
netif_stop_queue(dev);
spin_lock(&lp->lock);
spin_lock(&opened_lock);
list_del(&opened);
spin_unlock(&opened_lock);
del_timer_sync(&lp->timer);
lp->tp.close(lp);
spin_unlock(&lp->lock);
return 0;
}
static int iss_net_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct iss_net_private *lp = netdev_priv(dev);
unsigned long flags;
int len;
netif_stop_queue(dev);
spin_lock_irqsave(&lp->lock, flags);
len = lp->tp.write(lp, &skb);
if (len == skb->len) {
lp->stats.tx_packets++;
lp->stats.tx_bytes += skb->len;
dev->trans_start = jiffies;
netif_start_queue(dev);
netif_wake_queue(dev);
} else if (len == 0) {
netif_start_queue(dev);
lp->stats.tx_dropped++;
} else {
netif_start_queue(dev);
printk(KERN_ERR "iss_net_start_xmit: failed(%d)\n", len);
}
spin_unlock_irqrestore(&lp->lock, flags);
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
#if 0
if (dev->flags & IFF_PROMISC)
return;
else if (!netdev_mc_empty(dev))
dev->flags |= IFF_ALLMULTI;
else
dev->flags &= ~IFF_ALLMULTI;
#endif
}
static void iss_net_tx_timeout(struct net_device *dev)
{
#if 0
dev->trans_start = jiffies;
netif_wake_queue(dev);
#endif
}
static int iss_net_set_mac(struct net_device *dev, void *addr)
{
#if 0
struct iss_net_private *lp = netdev_priv(dev);
struct sockaddr *hwaddr = addr;
spin_lock(&lp->lock);
memcpy(dev->dev_addr, hwaddr->sa_data, ETH_ALEN);
spin_unlock(&lp->lock);
#endif
return 0;
}
static int iss_net_change_mtu(struct net_device *dev, int new_mtu)
{
#if 0
struct iss_net_private *lp = netdev_priv(dev);
int err = 0;
spin_lock(&lp->lock);
if (new_mtu < 0)
err = new_mtu;
else
dev->mtu = new_mtu;
spin_unlock(&lp->lock);
return err;
#endif
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
if ((dev = alloc_etherdev(sizeof *lp)) == NULL) {
printk(KERN_ERR "eth_configure: failed to allocate device\n");
return 1;
}
lp = netdev_priv(dev);
*lp = ((struct iss_net_private) {
.device_list = LIST_HEAD_INIT(lp->device_list),
.opened_list = LIST_HEAD_INIT(lp->opened_list),
.lock = __SPIN_LOCK_UNLOCKED(lp.lock),
.dev = dev,
.index = index,
.mac = { 0xfe, 0xfd, 0x0, 0x0, 0x0, 0x0 },
.have_mac = 0,
});
if (!tuntap_probe(lp, index, init)) {
printk("Invalid arguments. Skipping device!\n");
goto errout;
}
printk(KERN_INFO "Netdevice %d ", index);
if (lp->have_mac)
printk("(%pM) ", lp->mac);
printk(": ");
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
SET_NETDEV_DEV(dev,&lp->pdev.dev);
snprintf(dev->name, sizeof dev->name, "eth%d", index);
dev->netdev_ops = &iss_netdev_ops;
dev->mtu = lp->mtu;
dev->watchdog_timeo = (HZ >> 1);
dev->irq = -1;
rtnl_lock();
err = register_netdevice(dev);
rtnl_unlock();
if (err) {
printk("Error registering net device!\n");
free_netdev(dev);
return 1;
}
init_timer(&lp->tl);
lp->tl.function = iss_net_user_timer_expire;
#if 0
if (lp->have_mac)
set_ether_mac(dev, lp->mac);
#endif
return 0;
errout:
return -EIO;
}
static int iss_net_setup(char *str)
{
struct iss_net_private *device = NULL;
struct iss_net_init *new;
struct list_head *ele;
char *end;
int n;
n = simple_strtoul(str, &end, 0);
if (end == str) {
printk(ERR "Failed to parse '%s'\n", str);
return 1;
}
if (n < 0) {
printk(ERR "Device %d is negative\n", n);
return 1;
}
if (*(str = end) != '=') {
printk(ERR "Expected '=' after device number\n");
return 1;
}
spin_lock(&devices_lock);
list_for_each(ele, &devices) {
device = list_entry(ele, struct iss_net_private, device_list);
if (device->index == n)
break;
}
spin_unlock(&devices_lock);
if (device && device->index == n) {
printk(ERR "Device %d already configured\n", n);
return 1;
}
if ((new = alloc_bootmem(sizeof new)) == NULL) {
printk("Alloc_bootmem failed\n");
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
