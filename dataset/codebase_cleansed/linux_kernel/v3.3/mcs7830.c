static int mcs7830_get_reg(struct usbnet *dev, u16 index, u16 size, void *data)
{
struct usb_device *xdev = dev->udev;
int ret;
void *buffer;
buffer = kmalloc(size, GFP_NOIO);
if (buffer == NULL)
return -ENOMEM;
ret = usb_control_msg(xdev, usb_rcvctrlpipe(xdev, 0), MCS7830_RD_BREQ,
MCS7830_RD_BMREQ, 0x0000, index, buffer,
size, MCS7830_CTRL_TIMEOUT);
memcpy(data, buffer, size);
kfree(buffer);
return ret;
}
static int mcs7830_set_reg(struct usbnet *dev, u16 index, u16 size, const void *data)
{
struct usb_device *xdev = dev->udev;
int ret;
void *buffer;
buffer = kmemdup(data, size, GFP_NOIO);
if (buffer == NULL)
return -ENOMEM;
ret = usb_control_msg(xdev, usb_sndctrlpipe(xdev, 0), MCS7830_WR_BREQ,
MCS7830_WR_BMREQ, 0x0000, index, buffer,
size, MCS7830_CTRL_TIMEOUT);
kfree(buffer);
return ret;
}
static void mcs7830_async_cmd_callback(struct urb *urb)
{
struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;
int status = urb->status;
if (status < 0)
printk(KERN_DEBUG "%s() failed with %d\n",
__func__, status);
kfree(req);
usb_free_urb(urb);
}
static void mcs7830_set_reg_async(struct usbnet *dev, u16 index, u16 size, void *data)
{
struct usb_ctrlrequest *req;
int ret;
struct urb *urb;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
dev_dbg(&dev->udev->dev,
"Error allocating URB in write_cmd_async!\n");
return;
}
req = kmalloc(sizeof *req, GFP_ATOMIC);
if (!req) {
dev_err(&dev->udev->dev,
"Failed to allocate memory for control request\n");
goto out;
}
req->bRequestType = MCS7830_WR_BMREQ;
req->bRequest = MCS7830_WR_BREQ;
req->wValue = 0;
req->wIndex = cpu_to_le16(index);
req->wLength = cpu_to_le16(size);
usb_fill_control_urb(urb, dev->udev,
usb_sndctrlpipe(dev->udev, 0),
(void *)req, data, size,
mcs7830_async_cmd_callback, req);
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret < 0) {
dev_err(&dev->udev->dev,
"Error submitting the control message: ret=%d\n", ret);
goto out;
}
return;
out:
kfree(req);
usb_free_urb(urb);
}
static int mcs7830_hif_get_mac_address(struct usbnet *dev, unsigned char *addr)
{
int ret = mcs7830_get_reg(dev, HIF_REG_ETHERNET_ADDR, ETH_ALEN, addr);
if (ret < 0)
return ret;
return 0;
}
static int mcs7830_hif_set_mac_address(struct usbnet *dev, unsigned char *addr)
{
int ret = mcs7830_set_reg(dev, HIF_REG_ETHERNET_ADDR, ETH_ALEN, addr);
if (ret < 0)
return ret;
return 0;
}
static int mcs7830_set_mac_address(struct net_device *netdev, void *p)
{
int ret;
struct usbnet *dev = netdev_priv(netdev);
struct sockaddr *addr = p;
if (netif_running(netdev))
return -EBUSY;
if (!is_valid_ether_addr(addr->sa_data))
return -EINVAL;
ret = mcs7830_hif_set_mac_address(dev, addr->sa_data);
if (ret < 0)
return ret;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
return 0;
}
static int mcs7830_read_phy(struct usbnet *dev, u8 index)
{
int ret;
int i;
__le16 val;
u8 cmd[2] = {
HIF_REG_PHY_CMD1_READ | HIF_REG_PHY_CMD1_PHYADDR,
HIF_REG_PHY_CMD2_PEND_FLAG_BIT | index,
};
mutex_lock(&dev->phy_mutex);
ret = mcs7830_set_reg(dev, HIF_REG_PHY_CMD1, 2, cmd);
if (ret < 0)
goto out;
for (i = 0; i < 10; i++) {
ret = mcs7830_get_reg(dev, HIF_REG_PHY_CMD1, 2, cmd);
if ((ret < 0) || (cmd[1] & HIF_REG_PHY_CMD2_READY_FLAG_BIT))
break;
ret = -EIO;
msleep(1);
}
if (ret < 0)
goto out;
ret = mcs7830_get_reg(dev, HIF_REG_PHY_DATA, 2, &val);
if (ret < 0)
goto out;
ret = le16_to_cpu(val);
dev_dbg(&dev->udev->dev, "read PHY reg %02x: %04x (%d tries)\n",
index, val, i);
out:
mutex_unlock(&dev->phy_mutex);
return ret;
}
static int mcs7830_write_phy(struct usbnet *dev, u8 index, u16 val)
{
int ret;
int i;
__le16 le_val;
u8 cmd[2] = {
HIF_REG_PHY_CMD1_WRITE | HIF_REG_PHY_CMD1_PHYADDR,
HIF_REG_PHY_CMD2_PEND_FLAG_BIT | (index & 0x1F),
};
mutex_lock(&dev->phy_mutex);
le_val = cpu_to_le16(val);
ret = mcs7830_set_reg(dev, HIF_REG_PHY_DATA, 2, &le_val);
if (ret < 0)
goto out;
ret = mcs7830_set_reg(dev, HIF_REG_PHY_CMD1, 2, cmd);
if (ret < 0)
goto out;
for (i = 0; i < 10; i++) {
ret = mcs7830_get_reg(dev, HIF_REG_PHY_CMD1, 2, cmd);
if ((ret < 0) || (cmd[1] & HIF_REG_PHY_CMD2_READY_FLAG_BIT))
break;
ret = -EIO;
msleep(1);
}
if (ret < 0)
goto out;
ret = 0;
dev_dbg(&dev->udev->dev, "write PHY reg %02x: %04x (%d tries)\n",
index, val, i);
out:
mutex_unlock(&dev->phy_mutex);
return ret;
}
static int mcs7830_set_autoneg(struct usbnet *dev, int ptrUserPhyMode)
{
int ret;
ret = mcs7830_write_phy(dev, MII_ADVERTISE, MCS7830_MII_ADVERTISE);
if (!ret)
ret = mcs7830_write_phy(dev, MII_BMCR, 0x0000);
if (!ret)
ret = mcs7830_write_phy(dev, MII_BMCR, BMCR_ANENABLE);
if (!ret)
ret = mcs7830_write_phy(dev, MII_BMCR,
BMCR_ANENABLE | BMCR_ANRESTART );
return ret;
}
static int mcs7830_get_rev(struct usbnet *dev)
{
u8 dummy[2];
int ret;
ret = mcs7830_get_reg(dev, HIF_REG_FRAME_DROP_COUNTER, 2, dummy);
if (ret > 0)
return 2;
return 1;
}
static void mcs7830_rev_C_fixup(struct usbnet *dev)
{
u8 pause_threshold = HIF_REG_PAUSE_THRESHOLD_DEFAULT;
int retry;
for (retry = 0; retry < 2; retry++) {
if (mcs7830_get_rev(dev) == 2) {
dev_info(&dev->udev->dev, "applying rev.C fixup\n");
mcs7830_set_reg(dev, HIF_REG_PAUSE_THRESHOLD,
1, &pause_threshold);
}
msleep(1);
}
}
static int mcs7830_mdio_read(struct net_device *netdev, int phy_id,
int location)
{
struct usbnet *dev = netdev_priv(netdev);
return mcs7830_read_phy(dev, location);
}
static void mcs7830_mdio_write(struct net_device *netdev, int phy_id,
int location, int val)
{
struct usbnet *dev = netdev_priv(netdev);
mcs7830_write_phy(dev, location, val);
}
static int mcs7830_ioctl(struct net_device *net, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(net);
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static inline struct mcs7830_data *mcs7830_get_data(struct usbnet *dev)
{
return (struct mcs7830_data *)&dev->data;
}
static void mcs7830_hif_update_multicast_hash(struct usbnet *dev)
{
struct mcs7830_data *data = mcs7830_get_data(dev);
mcs7830_set_reg_async(dev, HIF_REG_MULTICAST_HASH,
sizeof data->multi_filter,
data->multi_filter);
}
static void mcs7830_hif_update_config(struct usbnet *dev)
{
struct mcs7830_data *data = mcs7830_get_data(dev);
mcs7830_set_reg_async(dev, HIF_REG_CONFIG, 1, &data->config);
}
static void mcs7830_data_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct mcs7830_data *data = mcs7830_get_data(dev);
memset(data->multi_filter, 0, sizeof data->multi_filter);
data->config = HIF_REG_CONFIG_TXENABLE;
data->config |= HIF_REG_CONFIG_ALLMULTICAST;
if (net->flags & IFF_PROMISC) {
data->config |= HIF_REG_CONFIG_PROMISCUOUS;
} else if (net->flags & IFF_ALLMULTI ||
netdev_mc_count(net) > MCS7830_MAX_MCAST) {
data->config |= HIF_REG_CONFIG_ALLMULTICAST;
} else if (netdev_mc_empty(net)) {
} else {
struct netdev_hw_addr *ha;
u32 crc_bits;
netdev_for_each_mc_addr(ha, net) {
crc_bits = ether_crc(ETH_ALEN, ha->addr) >> 26;
data->multi_filter[crc_bits >> 3] |= 1 << (crc_bits & 7);
}
}
}
static int mcs7830_apply_base_config(struct usbnet *dev)
{
int ret;
ret = mcs7830_hif_set_mac_address(dev, dev->net->dev_addr);
if (ret) {
dev_info(&dev->udev->dev, "Cannot set MAC address\n");
goto out;
}
ret = mcs7830_set_autoneg(dev, 0);
if (ret) {
dev_info(&dev->udev->dev, "Cannot set autoneg\n");
goto out;
}
mcs7830_hif_update_multicast_hash(dev);
mcs7830_hif_update_config(dev);
mcs7830_rev_C_fixup(dev);
ret = 0;
out:
return ret;
}
static void mcs7830_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
mcs7830_data_set_multicast(net);
mcs7830_hif_update_multicast_hash(dev);
mcs7830_hif_update_config(dev);
}
static int mcs7830_get_regs_len(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
switch (mcs7830_get_rev(dev)) {
case 1:
return 21;
case 2:
return 32;
}
return 0;
}
static void mcs7830_get_drvinfo(struct net_device *net, struct ethtool_drvinfo *drvinfo)
{
usbnet_get_drvinfo(net, drvinfo);
drvinfo->regdump_len = mcs7830_get_regs_len(net);
}
static void mcs7830_get_regs(struct net_device *net, struct ethtool_regs *regs, void *data)
{
struct usbnet *dev = netdev_priv(net);
regs->version = mcs7830_get_rev(dev);
mcs7830_get_reg(dev, 0, regs->len, data);
}
static int mcs7830_bind(struct usbnet *dev, struct usb_interface *udev)
{
struct net_device *net = dev->net;
int ret;
int retry;
ret = -EINVAL;
for (retry = 0; retry < 5 && ret; retry++)
ret = mcs7830_hif_get_mac_address(dev, net->dev_addr);
if (ret) {
dev_warn(&dev->udev->dev, "Cannot read MAC address\n");
goto out;
}
mcs7830_data_set_multicast(net);
ret = mcs7830_apply_base_config(dev);
if (ret)
goto out;
net->ethtool_ops = &mcs7830_ethtool_ops;
net->netdev_ops = &mcs7830_netdev_ops;
dev->rx_urb_size = ETH_FRAME_LEN + 1;
dev->mii.mdio_read = mcs7830_mdio_read;
dev->mii.mdio_write = mcs7830_mdio_write;
dev->mii.dev = net;
dev->mii.phy_id_mask = 0x3f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = *((u8 *) net->dev_addr + 1);
ret = usbnet_get_endpoints(dev, udev);
out:
return ret;
}
static int mcs7830_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
u8 status;
if (skb->len == 0) {
dev_err(&dev->udev->dev, "unexpected empty rx frame\n");
return 0;
}
skb_trim(skb, skb->len - 1);
status = skb->data[skb->len];
if (status != MCS7830_RX_FRAME_CORRECT) {
dev_dbg(&dev->udev->dev, "rx fixup status %x\n", status);
dev->net->stats.rx_errors++;
if (status & (MCS7830_RX_SHORT_FRAME
|MCS7830_RX_LENGTH_ERROR
|MCS7830_RX_LARGE_FRAME))
dev->net->stats.rx_length_errors++;
if (status & MCS7830_RX_ALIGNMENT_ERROR)
dev->net->stats.rx_frame_errors++;
if (status & MCS7830_RX_CRC_ERROR)
dev->net->stats.rx_crc_errors++;
}
return skb->len > 0;
}
static int mcs7830_reset_resume (struct usb_interface *intf)
{
struct usbnet *dev = usb_get_intfdata(intf);
mcs7830_apply_base_config(dev);
usbnet_resume(intf);
return 0;
}
