static int cfusbl_receive(struct cflayer *layr, struct cfpkt *pkt)
{
u8 hpad;
cfpkt_extr_head(pkt, &hpad, 1);
cfpkt_extr_head(pkt, NULL, hpad);
return layr->up->receive(layr->up, pkt);
}
static int cfusbl_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
struct caif_payload_info *info;
u8 hpad;
u8 zeros[CFUSB_ALIGNMENT];
struct sk_buff *skb;
struct cfusbl *usbl = container_of(layr, struct cfusbl, layer);
skb = cfpkt_tonative(pkt);
skb_reset_network_header(skb);
skb->protocol = htons(ETH_P_IP);
info = cfpkt_info(pkt);
hpad = (info->hdr_len + CFUSB_PAD_DESCR_SZ) & (CFUSB_ALIGNMENT - 1);
if (skb_headroom(skb) < ETH_HLEN + CFUSB_PAD_DESCR_SZ + hpad) {
pr_warn("Headroom to small\n");
kfree_skb(skb);
return -EIO;
}
memset(zeros, 0, hpad);
cfpkt_add_head(pkt, zeros, hpad);
cfpkt_add_head(pkt, &hpad, 1);
cfpkt_add_head(pkt, usbl->tx_eth_hdr, sizeof(usbl->tx_eth_hdr));
return layr->dn->transmit(layr->dn, pkt);
}
static void cfusbl_ctrlcmd(struct cflayer *layr, enum caif_ctrlcmd ctrl,
int phyid)
{
if (layr->up && layr->up->ctrlcmd)
layr->up->ctrlcmd(layr->up, ctrl, layr->id);
}
static struct cflayer *cfusbl_create(int phyid, u8 ethaddr[ETH_ALEN],
u8 braddr[ETH_ALEN])
{
struct cfusbl *this = kmalloc(sizeof(struct cfusbl), GFP_ATOMIC);
if (!this) {
pr_warn("Out of memory\n");
return NULL;
}
caif_assert(offsetof(struct cfusbl, layer) == 0);
memset(this, 0, sizeof(struct cflayer));
this->layer.receive = cfusbl_receive;
this->layer.transmit = cfusbl_transmit;
this->layer.ctrlcmd = cfusbl_ctrlcmd;
snprintf(this->layer.name, CAIF_LAYER_NAME_SZ, "usb%d", phyid);
this->layer.id = phyid;
memcpy(&this->tx_eth_hdr[ETH_ALEN], braddr, ETH_ALEN);
memcpy(&this->tx_eth_hdr[ETH_ALEN], ethaddr, ETH_ALEN);
this->tx_eth_hdr[12] = cpu_to_be16(ETH_P_802_EX1) & 0xff;
this->tx_eth_hdr[13] = (cpu_to_be16(ETH_P_802_EX1) >> 8) & 0xff;
pr_debug("caif ethernet TX-header dst:%pM src:%pM type:%02x%02x\n",
this->tx_eth_hdr, this->tx_eth_hdr + ETH_ALEN,
this->tx_eth_hdr[12], this->tx_eth_hdr[13]);
return (struct cflayer *) this;
}
static int cfusbl_device_notify(struct notifier_block *me, unsigned long what,
void *arg)
{
struct net_device *dev = arg;
struct caif_dev_common common;
struct cflayer *layer, *link_support;
struct usbnet *usbnet;
struct usb_device *usbdev;
if (!(dev->dev.parent && dev->dev.parent->driver &&
strcmp(dev->dev.parent->driver->name, "cdc_ncm") == 0))
return 0;
usbnet = netdev_priv(dev);
usbdev = usbnet->udev;
pr_debug("USB CDC NCM device VID:0x%4x PID:0x%4x\n",
le16_to_cpu(usbdev->descriptor.idVendor),
le16_to_cpu(usbdev->descriptor.idProduct));
if (!(le16_to_cpu(usbdev->descriptor.idVendor) == STE_USB_VID &&
le16_to_cpu(usbdev->descriptor.idProduct) == STE_USB_PID_CAIF))
return 0;
if (what == NETDEV_UNREGISTER)
module_put(THIS_MODULE);
if (what != NETDEV_REGISTER)
return 0;
__module_get(THIS_MODULE);
memset(&common, 0, sizeof(common));
common.use_frag = false;
common.use_fcs = false;
common.use_stx = false;
common.link_select = CAIF_LINK_HIGH_BANDW;
common.flowctrl = NULL;
link_support = cfusbl_create(dev->ifindex, dev->dev_addr,
dev->broadcast);
if (!link_support)
return -ENOMEM;
if (dev->num_tx_queues > 1)
pr_warn("USB device uses more than one tx queue\n");
caif_enroll_dev(dev, &common, link_support, CFUSB_MAX_HEADLEN,
&layer, &caif_usb_type.func);
if (!pack_added)
dev_add_pack(&caif_usb_type);
pack_added = true;
strncpy(layer->name, dev->name,
sizeof(layer->name) - 1);
layer->name[sizeof(layer->name) - 1] = 0;
return 0;
}
static int __init cfusbl_init(void)
{
return register_netdevice_notifier(&caif_device_notifier);
}
static void __exit cfusbl_exit(void)
{
unregister_netdevice_notifier(&caif_device_notifier);
dev_remove_pack(&caif_usb_type);
}
