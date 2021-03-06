static struct wpan_phy *fake_to_phy(const struct net_device *dev)
{
struct fakehard_priv *priv = netdev_priv(dev);
return priv->phy;
}
static struct wpan_phy *fake_get_phy(const struct net_device *dev)
{
struct wpan_phy *phy = fake_to_phy(dev);
return to_phy(get_device(&phy->dev));
}
static u16 fake_get_pan_id(const struct net_device *dev)
{
BUG_ON(dev->type != ARPHRD_IEEE802154);
return 0xeba1;
}
static u16 fake_get_short_addr(const struct net_device *dev)
{
BUG_ON(dev->type != ARPHRD_IEEE802154);
return 0x1;
}
static u8 fake_get_dsn(const struct net_device *dev)
{
BUG_ON(dev->type != ARPHRD_IEEE802154);
return 0x00;
}
static u8 fake_get_bsn(const struct net_device *dev)
{
BUG_ON(dev->type != ARPHRD_IEEE802154);
return 0x00;
}
static int fake_assoc_req(struct net_device *dev,
struct ieee802154_addr *addr, u8 channel, u8 page, u8 cap)
{
struct wpan_phy *phy = fake_to_phy(dev);
mutex_lock(&phy->pib_lock);
phy->current_channel = channel;
phy->current_page = page;
mutex_unlock(&phy->pib_lock);
return ieee802154_nl_assoc_confirm(dev, fake_get_short_addr(dev),
IEEE802154_SUCCESS);
}
static int fake_assoc_resp(struct net_device *dev,
struct ieee802154_addr *addr, u16 short_addr, u8 status)
{
return 0;
}
static int fake_disassoc_req(struct net_device *dev,
struct ieee802154_addr *addr, u8 reason)
{
return ieee802154_nl_disassoc_confirm(dev, IEEE802154_SUCCESS);
}
static int fake_start_req(struct net_device *dev, struct ieee802154_addr *addr,
u8 channel, u8 page,
u8 bcn_ord, u8 sf_ord, u8 pan_coord, u8 blx,
u8 coord_realign)
{
struct wpan_phy *phy = fake_to_phy(dev);
mutex_lock(&phy->pib_lock);
phy->current_channel = channel;
phy->current_page = page;
mutex_unlock(&phy->pib_lock);
ieee802154_nl_start_confirm(dev, IEEE802154_INVALID_PARAMETER);
return 0;
}
static int fake_scan_req(struct net_device *dev, u8 type, u32 channels,
u8 page, u8 duration)
{
u8 edl[27] = {};
return ieee802154_nl_scan_confirm(dev, IEEE802154_SUCCESS, type,
channels, page,
type == IEEE802154_MAC_SCAN_ED ? edl : NULL);
}
static int ieee802154_fake_open(struct net_device *dev)
{
netif_start_queue(dev);
return 0;
}
static int ieee802154_fake_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static netdev_tx_t ieee802154_fake_xmit(struct sk_buff *skb,
struct net_device *dev)
{
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int ieee802154_fake_ioctl(struct net_device *dev, struct ifreq *ifr,
int cmd)
{
struct sockaddr_ieee802154 *sa =
(struct sockaddr_ieee802154 *)&ifr->ifr_addr;
u16 pan_id, short_addr;
switch (cmd) {
case SIOCGIFADDR:
pan_id = fake_get_pan_id(dev);
short_addr = fake_get_short_addr(dev);
if (pan_id == IEEE802154_PANID_BROADCAST ||
short_addr == IEEE802154_ADDR_BROADCAST)
return -EADDRNOTAVAIL;
sa->family = AF_IEEE802154;
sa->addr.addr_type = IEEE802154_ADDR_SHORT;
sa->addr.pan_id = pan_id;
sa->addr.short_addr = short_addr;
return 0;
}
return -ENOIOCTLCMD;
}
static int ieee802154_fake_mac_addr(struct net_device *dev, void *p)
{
return -EBUSY;
}
static void ieee802154_fake_destruct(struct net_device *dev)
{
struct wpan_phy *phy = fake_to_phy(dev);
wpan_phy_unregister(phy);
free_netdev(dev);
wpan_phy_free(phy);
}
static void ieee802154_fake_setup(struct net_device *dev)
{
dev->addr_len = IEEE802154_ADDR_LEN;
memset(dev->broadcast, 0xff, IEEE802154_ADDR_LEN);
dev->features = NETIF_F_HW_CSUM;
dev->needed_tailroom = 2;
dev->mtu = 127;
dev->tx_queue_len = 10;
dev->type = ARPHRD_IEEE802154;
dev->flags = IFF_NOARP | IFF_BROADCAST;
dev->watchdog_timeo = 0;
dev->destructor = ieee802154_fake_destruct;
}
static int __devinit ieee802154fake_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct fakehard_priv *priv;
struct wpan_phy *phy = wpan_phy_alloc(0);
int err;
if (!phy)
return -ENOMEM;
dev = alloc_netdev(sizeof(struct fakehard_priv), "hardwpan%d", ieee802154_fake_setup);
if (!dev) {
wpan_phy_free(phy);
return -ENOMEM;
}
memcpy(dev->dev_addr, "\xba\xbe\xca\xfe\xde\xad\xbe\xef",
dev->addr_len);
memcpy(dev->perm_addr, dev->dev_addr, dev->addr_len);
phy->channels_supported[0] |= 0x7FFF800;
phy->channels_supported[3] |= 0x3fff;
phy->transmit_power = 0xbf;
dev->netdev_ops = &fake_ops;
dev->ml_priv = &fake_mlme;
priv = netdev_priv(dev);
priv->phy = phy;
wpan_phy_set_dev(phy, &pdev->dev);
SET_NETDEV_DEV(dev, &phy->dev);
platform_set_drvdata(pdev, dev);
err = wpan_phy_register(phy);
if (err)
goto out;
err = register_netdev(dev);
if (err < 0)
goto out;
dev_info(&pdev->dev, "Added ieee802154 HardMAC hardware\n");
return 0;
out:
unregister_netdev(dev);
return err;
}
static int __devexit ieee802154fake_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
unregister_netdev(dev);
return 0;
}
static __init int fake_init(void)
{
ieee802154fake_dev = platform_device_register_simple(
"ieee802154hardmac", -1, NULL, 0);
return platform_driver_register(&ieee802154fake_driver);
}
static __exit void fake_exit(void)
{
platform_driver_unregister(&ieee802154fake_driver);
platform_device_unregister(ieee802154fake_dev);
}
