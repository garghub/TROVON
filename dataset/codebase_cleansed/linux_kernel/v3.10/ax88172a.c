static int asix_mdio_bus_read(struct mii_bus *bus, int phy_id, int regnum)
{
return asix_mdio_read(((struct usbnet *)bus->priv)->net, phy_id,
regnum);
}
static int asix_mdio_bus_write(struct mii_bus *bus, int phy_id, int regnum,
u16 val)
{
asix_mdio_write(((struct usbnet *)bus->priv)->net, phy_id, regnum, val);
return 0;
}
static int ax88172a_ioctl(struct net_device *net, struct ifreq *rq, int cmd)
{
if (!netif_running(net))
return -EINVAL;
if (!net->phydev)
return -ENODEV;
return phy_mii_ioctl(net->phydev, rq, cmd);
}
static void ax88172a_adjust_link(struct net_device *netdev)
{
struct phy_device *phydev = netdev->phydev;
struct usbnet *dev = netdev_priv(netdev);
struct ax88172a_private *priv = dev->driver_priv;
u16 mode = 0;
if (phydev->link) {
mode = AX88772_MEDIUM_DEFAULT;
if (phydev->duplex == DUPLEX_HALF)
mode &= ~AX_MEDIUM_FD;
if (phydev->speed != SPEED_100)
mode &= ~AX_MEDIUM_PS;
}
if (mode != priv->oldmode) {
asix_write_medium_mode(dev, mode);
priv->oldmode = mode;
netdev_dbg(netdev, "speed %u duplex %d, setting mode to 0x%04x\n",
phydev->speed, phydev->duplex, mode);
phy_print_status(phydev);
}
}
static void ax88172a_status(struct usbnet *dev, struct urb *urb)
{
}
static int ax88172a_init_mdio(struct usbnet *dev)
{
struct ax88172a_private *priv = dev->driver_priv;
int ret, i;
priv->mdio = mdiobus_alloc();
if (!priv->mdio) {
netdev_err(dev->net, "Could not allocate MDIO bus\n");
return -ENOMEM;
}
priv->mdio->priv = (void *)dev;
priv->mdio->read = &asix_mdio_bus_read;
priv->mdio->write = &asix_mdio_bus_write;
priv->mdio->name = "Asix MDIO Bus";
snprintf(priv->mdio->id, MII_BUS_ID_SIZE, "usb-%03d:%03d",
dev->udev->bus->busnum, dev->udev->devnum);
priv->mdio->irq = kzalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!priv->mdio->irq) {
ret = -ENOMEM;
goto mfree;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
priv->mdio->irq[i] = PHY_POLL;
ret = mdiobus_register(priv->mdio);
if (ret) {
netdev_err(dev->net, "Could not register MDIO bus\n");
goto ifree;
}
netdev_info(dev->net, "registered mdio bus %s\n", priv->mdio->id);
return 0;
ifree:
kfree(priv->mdio->irq);
mfree:
mdiobus_free(priv->mdio);
return ret;
}
static void ax88172a_remove_mdio(struct usbnet *dev)
{
struct ax88172a_private *priv = dev->driver_priv;
netdev_info(dev->net, "deregistering mdio bus %s\n", priv->mdio->id);
mdiobus_unregister(priv->mdio);
kfree(priv->mdio->irq);
mdiobus_free(priv->mdio);
}
int ax88172a_get_settings(struct net_device *net, struct ethtool_cmd *cmd)
{
if (!net->phydev)
return -ENODEV;
return phy_ethtool_gset(net->phydev, cmd);
}
int ax88172a_set_settings(struct net_device *net, struct ethtool_cmd *cmd)
{
if (!net->phydev)
return -ENODEV;
return phy_ethtool_sset(net->phydev, cmd);
}
int ax88172a_nway_reset(struct net_device *net)
{
if (!net->phydev)
return -ENODEV;
return phy_start_aneg(net->phydev);
}
static int ax88172a_reset_phy(struct usbnet *dev, int embd_phy)
{
int ret;
ret = asix_sw_reset(dev, AX_SWRESET_IPPD);
if (ret < 0)
goto err;
msleep(150);
ret = asix_sw_reset(dev, AX_SWRESET_CLEAR);
if (ret < 0)
goto err;
msleep(150);
ret = asix_sw_reset(dev, embd_phy ? AX_SWRESET_IPRL : AX_SWRESET_IPPD);
if (ret < 0)
goto err;
return 0;
err:
return ret;
}
static int ax88172a_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
u8 buf[ETH_ALEN];
struct ax88172a_private *priv;
usbnet_get_endpoints(dev, intf);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev->driver_priv = priv;
ret = asix_read_cmd(dev, AX_CMD_READ_NODE_ID, 0, 0, ETH_ALEN, buf);
if (ret < 0) {
netdev_err(dev->net, "Failed to read MAC address: %d\n", ret);
goto free;
}
memcpy(dev->net->dev_addr, buf, ETH_ALEN);
dev->net->netdev_ops = &ax88172a_netdev_ops;
dev->net->ethtool_ops = &ax88172a_ethtool_ops;
ret = asix_read_cmd(dev, AX_CMD_SW_PHY_STATUS, 0, 0, 1, buf);
if (ret < 0) {
netdev_err(dev->net, "Failed to read software interface selection register: %d\n",
ret);
goto free;
}
netdev_dbg(dev->net, "AX_CMD_SW_PHY_STATUS = 0x%02x\n", buf[0]);
switch (buf[0] & AX_PHY_SELECT_MASK) {
case AX_PHY_SELECT_INTERNAL:
netdev_dbg(dev->net, "use internal phy\n");
priv->use_embdphy = 1;
break;
case AX_PHY_SELECT_EXTERNAL:
netdev_dbg(dev->net, "use external phy\n");
priv->use_embdphy = 0;
break;
default:
netdev_err(dev->net, "Interface mode not supported by driver\n");
ret = -ENOTSUPP;
goto free;
}
priv->phy_addr = asix_read_phy_addr(dev, priv->use_embdphy);
ax88172a_reset_phy(dev, priv->use_embdphy);
if (dev->driver_info->flags & FLAG_FRAMING_AX) {
dev->rx_urb_size = 2048;
}
ret = ax88172a_init_mdio(dev);
if (ret)
goto free;
return 0;
free:
kfree(priv);
return ret;
}
static int ax88172a_stop(struct usbnet *dev)
{
struct ax88172a_private *priv = dev->driver_priv;
netdev_dbg(dev->net, "Stopping interface\n");
if (priv->phydev) {
netdev_info(dev->net, "Disconnecting from phy %s\n",
priv->phy_name);
phy_stop(priv->phydev);
phy_disconnect(priv->phydev);
}
return 0;
}
static void ax88172a_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct ax88172a_private *priv = dev->driver_priv;
ax88172a_remove_mdio(dev);
kfree(priv);
}
static int ax88172a_reset(struct usbnet *dev)
{
struct asix_data *data = (struct asix_data *)&dev->data;
struct ax88172a_private *priv = dev->driver_priv;
int ret;
u16 rx_ctl;
ax88172a_reset_phy(dev, priv->use_embdphy);
msleep(150);
rx_ctl = asix_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after software reset\n", rx_ctl);
ret = asix_write_rx_ctl(dev, 0x0000);
if (ret < 0)
goto out;
rx_ctl = asix_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x setting to 0x0000\n", rx_ctl);
msleep(150);
ret = asix_write_cmd(dev, AX_CMD_WRITE_IPG0,
AX88772_IPG0_DEFAULT | AX88772_IPG1_DEFAULT,
AX88772_IPG2_DEFAULT, 0, NULL);
if (ret < 0) {
netdev_err(dev->net, "Write IPG,IPG1,IPG2 failed: %d\n", ret);
goto out;
}
memcpy(data->mac_addr, dev->net->dev_addr, ETH_ALEN);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr);
if (ret < 0)
goto out;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL);
if (ret < 0)
goto out;
rx_ctl = asix_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after all initializations\n",
rx_ctl);
rx_ctl = asix_read_medium_status(dev);
netdev_dbg(dev->net, "Medium Status is 0x%04x after all initializations\n",
rx_ctl);
snprintf(priv->phy_name, 20, PHY_ID_FMT,
priv->mdio->id, priv->phy_addr);
priv->phydev = phy_connect(dev->net, priv->phy_name,
&ax88172a_adjust_link,
PHY_INTERFACE_MODE_MII);
if (IS_ERR(priv->phydev)) {
netdev_err(dev->net, "Could not connect to PHY device %s\n",
priv->phy_name);
ret = PTR_ERR(priv->phydev);
goto out;
}
netdev_info(dev->net, "Connected to phy %s\n", priv->phy_name);
genphy_resume(priv->phydev);
phy_start(priv->phydev);
return 0;
out:
return ret;
}
static int ax88172a_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
struct ax88172a_private *dp = dev->driver_priv;
struct asix_rx_fixup_info *rx = &dp->rx_fixup_info;
return asix_rx_fixup_internal(dev, skb, rx);
}
