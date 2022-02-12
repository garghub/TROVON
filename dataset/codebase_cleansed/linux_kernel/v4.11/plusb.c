static inline int
pl_vendor_req(struct usbnet *dev, u8 req, u8 val, u8 index)
{
return usbnet_read_cmd(dev, req,
USB_DIR_IN | USB_TYPE_VENDOR |
USB_RECIP_DEVICE,
val, index, NULL, 0);
}
static inline int
pl_clear_QuickLink_features(struct usbnet *dev, int val)
{
return pl_vendor_req(dev, 1, (u8) val, 0);
}
static inline int
pl_set_QuickLink_features(struct usbnet *dev, int val)
{
return pl_vendor_req(dev, 3, (u8) val, 0);
}
static int pl_reset(struct usbnet *dev)
{
int status;
status = pl_set_QuickLink_features(dev,
PL_S_EN|PL_RESET_OUT|PL_RESET_IN|PL_PEER_E);
if (status != 0 && netif_msg_probe(dev))
netif_dbg(dev, link, dev->net, "pl_reset --> %d\n", status);
return 0;
}
