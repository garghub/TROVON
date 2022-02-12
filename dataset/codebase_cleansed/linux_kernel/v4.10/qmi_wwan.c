static void qmi_wwan_netdev_setup(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct qmi_wwan_state *info = (void *)&dev->data;
if (info->flags & QMI_WWAN_FLAG_RAWIP) {
net->header_ops = NULL;
net->type = ARPHRD_NONE;
net->hard_header_len = 0;
net->addr_len = 0;
net->flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
netdev_dbg(net, "mode: raw IP\n");
} else if (!net->header_ops) {
ether_setup(net);
netdev_dbg(net, "mode: Ethernet\n");
}
usbnet_change_mtu(net, net->mtu);
}
static ssize_t raw_ip_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct qmi_wwan_state *info = (void *)&dev->data;
return sprintf(buf, "%c\n", info->flags & QMI_WWAN_FLAG_RAWIP ? 'Y' : 'N');
}
static ssize_t raw_ip_store(struct device *d, struct device_attribute *attr, const char *buf, size_t len)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct qmi_wwan_state *info = (void *)&dev->data;
bool enable;
int ret;
if (strtobool(buf, &enable))
return -EINVAL;
if (enable == (info->flags & QMI_WWAN_FLAG_RAWIP))
return len;
if (!rtnl_trylock())
return restart_syscall();
if (netif_running(dev->net)) {
netdev_err(dev->net, "Cannot change a running device\n");
ret = -EBUSY;
goto err;
}
ret = call_netdevice_notifiers(NETDEV_PRE_TYPE_CHANGE, dev->net);
ret = notifier_to_errno(ret);
if (ret) {
netdev_err(dev->net, "Type change was refused\n");
goto err;
}
if (enable)
info->flags |= QMI_WWAN_FLAG_RAWIP;
else
info->flags &= ~QMI_WWAN_FLAG_RAWIP;
qmi_wwan_netdev_setup(dev->net);
call_netdevice_notifiers(NETDEV_POST_TYPE_CHANGE, dev->net);
ret = len;
err:
rtnl_unlock();
return ret;
}
static int qmi_wwan_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
struct qmi_wwan_state *info = (void *)&dev->data;
bool rawip = info->flags & QMI_WWAN_FLAG_RAWIP;
__be16 proto;
if (skb->len < dev->net->hard_header_len)
return 0;
switch (skb->data[0] & 0xf0) {
case 0x40:
proto = htons(ETH_P_IP);
break;
case 0x60:
proto = htons(ETH_P_IPV6);
break;
case 0x00:
if (rawip)
return 0;
if (is_multicast_ether_addr(skb->data))
return 1;
skb_reset_mac_header(skb);
goto fix_dest;
default:
if (rawip)
return 0;
return 1;
}
if (rawip) {
skb->dev = dev->net;
skb->protocol = proto;
return 1;
}
if (skb_headroom(skb) < ETH_HLEN)
return 0;
skb_push(skb, ETH_HLEN);
skb_reset_mac_header(skb);
eth_hdr(skb)->h_proto = proto;
eth_zero_addr(eth_hdr(skb)->h_source);
fix_dest:
memcpy(eth_hdr(skb)->h_dest, dev->net->dev_addr, ETH_ALEN);
return 1;
}
static bool possibly_iphdr(const char *data)
{
return (data[0] & 0xd0) == 0x40;
}
static int qmi_wwan_mac_addr(struct net_device *dev, void *p)
{
int ret;
struct sockaddr *addr = p;
ret = eth_prepare_mac_addr_change(dev, p);
if (ret < 0)
return ret;
if (possibly_iphdr(addr->sa_data))
return -EADDRNOTAVAIL;
eth_commit_mac_addr_change(dev, p);
return 0;
}
static int qmi_wwan_manage_power(struct usbnet *dev, int on)
{
struct qmi_wwan_state *info = (void *)&dev->data;
int rv;
dev_dbg(&dev->intf->dev, "%s() pmcount=%d, on=%d\n", __func__,
atomic_read(&info->pmcount), on);
if ((on && atomic_add_return(1, &info->pmcount) == 1) ||
(!on && atomic_dec_and_test(&info->pmcount))) {
rv = usb_autopm_get_interface(dev->intf);
dev->intf->needs_remote_wakeup = on;
if (!rv)
usb_autopm_put_interface(dev->intf);
}
return 0;
}
static int qmi_wwan_cdc_wdm_manage_power(struct usb_interface *intf, int on)
{
struct usbnet *dev = usb_get_intfdata(intf);
if (!dev)
return 0;
return qmi_wwan_manage_power(dev, on);
}
static int qmi_wwan_register_subdriver(struct usbnet *dev)
{
int rv;
struct usb_driver *subdriver = NULL;
struct qmi_wwan_state *info = (void *)&dev->data;
rv = usbnet_get_endpoints(dev, info->data);
if (rv < 0)
goto err;
if (info->control != info->data)
dev->status = &info->control->cur_altsetting->endpoint[0];
if (!dev->status) {
rv = -EINVAL;
goto err;
}
atomic_set(&info->pmcount, 0);
subdriver = usb_cdc_wdm_register(info->control, &dev->status->desc,
4096, &qmi_wwan_cdc_wdm_manage_power);
if (IS_ERR(subdriver)) {
dev_err(&info->control->dev, "subdriver registration failed\n");
rv = PTR_ERR(subdriver);
goto err;
}
dev->status = NULL;
info->subdriver = subdriver;
err:
return rv;
}
static int qmi_wwan_change_dtr(struct usbnet *dev, bool on)
{
u8 intf = dev->intf->cur_altsetting->desc.bInterfaceNumber;
return usbnet_write_cmd(dev, USB_CDC_REQ_SET_CONTROL_LINE_STATE,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
on ? 0x01 : 0x00, intf, NULL, 0);
}
static int qmi_wwan_bind(struct usbnet *dev, struct usb_interface *intf)
{
int status = -1;
u8 *buf = intf->cur_altsetting->extra;
int len = intf->cur_altsetting->extralen;
struct usb_interface_descriptor *desc = &intf->cur_altsetting->desc;
struct usb_cdc_union_desc *cdc_union;
struct usb_cdc_ether_desc *cdc_ether;
struct usb_driver *driver = driver_of(intf);
struct qmi_wwan_state *info = (void *)&dev->data;
struct usb_cdc_parsed_header hdr;
BUILD_BUG_ON((sizeof(((struct usbnet *)0)->data) <
sizeof(struct qmi_wwan_state)));
info->control = intf;
info->data = intf;
cdc_parse_cdc_header(&hdr, intf, buf, len);
cdc_union = hdr.usb_cdc_union_desc;
cdc_ether = hdr.usb_cdc_ether_desc;
if (cdc_union) {
info->data = usb_ifnum_to_if(dev->udev,
cdc_union->bSlaveInterface0);
if (desc->bInterfaceNumber != cdc_union->bMasterInterface0 ||
!info->data) {
dev_err(&intf->dev,
"bogus CDC Union: master=%u, slave=%u\n",
cdc_union->bMasterInterface0,
cdc_union->bSlaveInterface0);
cdc_union = NULL;
info->data = intf;
}
}
if (cdc_ether) {
dev->hard_mtu = le16_to_cpu(cdc_ether->wMaxSegmentSize);
usbnet_get_ethernet_addr(dev, cdc_ether->iMACAddress);
}
if (info->control != info->data) {
status = usb_driver_claim_interface(driver, info->data, dev);
if (status < 0)
goto err;
}
status = qmi_wwan_register_subdriver(dev);
if (status < 0 && info->control != info->data) {
usb_set_intfdata(info->data, NULL);
usb_driver_release_interface(driver, info->data);
}
if (dev->driver_info->data & QMI_WWAN_QUIRK_DTR ||
le16_to_cpu(dev->udev->descriptor.bcdUSB) >= 0x0201) {
qmi_wwan_manage_power(dev, 1);
qmi_wwan_change_dtr(dev, true);
}
if (ether_addr_equal(dev->net->dev_addr, default_modem_addr) ||
ether_addr_equal(dev->net->dev_addr, buggy_fw_addr))
eth_hw_addr_random(dev->net);
if (possibly_iphdr(dev->net->dev_addr)) {
dev->net->dev_addr[0] |= 0x02;
dev->net->dev_addr[0] &= 0xbf;
}
dev->net->netdev_ops = &qmi_wwan_netdev_ops;
dev->net->sysfs_groups[0] = &qmi_wwan_sysfs_attr_group;
err:
return status;
}
static void qmi_wwan_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct qmi_wwan_state *info = (void *)&dev->data;
struct usb_driver *driver = driver_of(intf);
struct usb_interface *other;
if (info->subdriver && info->subdriver->disconnect)
info->subdriver->disconnect(info->control);
if (le16_to_cpu(dev->udev->descriptor.bcdUSB) >= 0x0201) {
qmi_wwan_change_dtr(dev, false);
qmi_wwan_manage_power(dev, 0);
}
if (intf == info->control)
other = info->data;
else
other = info->control;
if (other && intf != other) {
usb_set_intfdata(other, NULL);
usb_driver_release_interface(driver, other);
}
info->subdriver = NULL;
info->data = NULL;
info->control = NULL;
}
static int qmi_wwan_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usbnet *dev = usb_get_intfdata(intf);
struct qmi_wwan_state *info = (void *)&dev->data;
int ret;
ret = usbnet_suspend(intf, message);
if (ret < 0)
goto err;
if (intf == info->control && info->subdriver &&
info->subdriver->suspend)
ret = info->subdriver->suspend(intf, message);
if (ret < 0)
usbnet_resume(intf);
err:
return ret;
}
static int qmi_wwan_resume(struct usb_interface *intf)
{
struct usbnet *dev = usb_get_intfdata(intf);
struct qmi_wwan_state *info = (void *)&dev->data;
int ret = 0;
bool callsub = (intf == info->control && info->subdriver &&
info->subdriver->resume);
if (callsub)
ret = info->subdriver->resume(intf);
if (ret < 0)
goto err;
ret = usbnet_resume(intf);
if (ret < 0 && callsub)
info->subdriver->suspend(intf, PMSG_SUSPEND);
err:
return ret;
}
static bool quectel_ec20_detected(struct usb_interface *intf)
{
struct usb_device *dev = interface_to_usbdev(intf);
if (dev->actconfig &&
le16_to_cpu(dev->descriptor.idVendor) == 0x05c6 &&
le16_to_cpu(dev->descriptor.idProduct) == 0x9215 &&
dev->actconfig->desc.bNumInterfaces == 5)
return true;
return false;
}
static int qmi_wwan_probe(struct usb_interface *intf,
const struct usb_device_id *prod)
{
struct usb_device_id *id = (struct usb_device_id *)prod;
struct usb_interface_descriptor *desc = &intf->cur_altsetting->desc;
if (!id->driver_info) {
dev_dbg(&intf->dev, "setting defaults for dynamic device id\n");
id->driver_info = (unsigned long)&qmi_wwan_info;
}
if (quectel_ec20_detected(intf) && desc->bInterfaceNumber == 0) {
dev_dbg(&intf->dev, "Quectel EC20 quirk, skipping interface 0\n");
return -ENODEV;
}
return usbnet_probe(intf, id);
}
