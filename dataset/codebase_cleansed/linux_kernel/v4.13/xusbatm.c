static struct usb_interface *xusbatm_find_intf(struct usb_device *usb_dev, int altsetting, u8 ep)
{
struct usb_host_interface *alt;
struct usb_interface *intf;
int i, j;
for (i = 0; i < usb_dev->actconfig->desc.bNumInterfaces; i++)
if ((intf = usb_dev->actconfig->interface[i]) && (alt = usb_altnum_to_altsetting(intf, altsetting)))
for (j = 0; j < alt->desc.bNumEndpoints; j++)
if (alt->endpoint[j].desc.bEndpointAddress == ep)
return intf;
return NULL;
}
static int xusbatm_capture_intf(struct usbatm_data *usbatm, struct usb_device *usb_dev,
struct usb_interface *intf, int altsetting, int claim)
{
int ifnum = intf->altsetting->desc.bInterfaceNumber;
int ret;
if (claim && (ret = usb_driver_claim_interface(&xusbatm_usb_driver, intf, usbatm))) {
usb_err(usbatm, "%s: failed to claim interface %2d (%d)!\n", __func__, ifnum, ret);
return ret;
}
ret = usb_set_interface(usb_dev, ifnum, altsetting);
if (ret) {
usb_err(usbatm, "%s: altsetting %2d for interface %2d failed (%d)!\n", __func__, altsetting, ifnum, ret);
return ret;
}
return 0;
}
static void xusbatm_release_intf(struct usb_device *usb_dev, struct usb_interface *intf, int claimed)
{
if (claimed) {
usb_set_intfdata(intf, NULL);
usb_driver_release_interface(&xusbatm_usb_driver, intf);
}
}
static int xusbatm_bind(struct usbatm_data *usbatm,
struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *usb_dev = interface_to_usbdev(intf);
int drv_ix = id - xusbatm_usb_ids;
int rx_alt = rx_altsetting[drv_ix];
int tx_alt = tx_altsetting[drv_ix];
struct usb_interface *rx_intf = xusbatm_find_intf(usb_dev, rx_alt, rx_endpoint[drv_ix]);
struct usb_interface *tx_intf = xusbatm_find_intf(usb_dev, tx_alt, tx_endpoint[drv_ix]);
int ret;
usb_dbg(usbatm, "%s: binding driver %d: vendor %04x product %04x"
" rx: ep %02x padd %d alt %2d tx: ep %02x padd %d alt %2d\n",
__func__, drv_ix, vendor[drv_ix], product[drv_ix],
rx_endpoint[drv_ix], rx_padding[drv_ix], rx_alt,
tx_endpoint[drv_ix], tx_padding[drv_ix], tx_alt);
if (!rx_intf || !tx_intf) {
if (!rx_intf)
usb_dbg(usbatm, "%s: no interface contains endpoint %02x in altsetting %2d\n",
__func__, rx_endpoint[drv_ix], rx_alt);
if (!tx_intf)
usb_dbg(usbatm, "%s: no interface contains endpoint %02x in altsetting %2d\n",
__func__, tx_endpoint[drv_ix], tx_alt);
return -ENODEV;
}
if ((rx_intf != intf) && (tx_intf != intf))
return -ENODEV;
if ((rx_intf == tx_intf) && (rx_alt != tx_alt)) {
usb_err(usbatm, "%s: altsettings clash on interface %2d (%2d vs %2d)!\n", __func__,
rx_intf->altsetting->desc.bInterfaceNumber, rx_alt, tx_alt);
return -EINVAL;
}
usb_dbg(usbatm, "%s: rx If#=%2d; tx If#=%2d\n", __func__,
rx_intf->altsetting->desc.bInterfaceNumber,
tx_intf->altsetting->desc.bInterfaceNumber);
ret = xusbatm_capture_intf(usbatm, usb_dev, rx_intf, rx_alt, rx_intf != intf);
if (ret)
return ret;
if ((tx_intf != rx_intf) && (ret = xusbatm_capture_intf(usbatm, usb_dev, tx_intf, tx_alt, tx_intf != intf))) {
xusbatm_release_intf(usb_dev, rx_intf, rx_intf != intf);
return ret;
}
return 0;
}
static void xusbatm_unbind(struct usbatm_data *usbatm,
struct usb_interface *intf)
{
struct usb_device *usb_dev = interface_to_usbdev(intf);
int i;
usb_dbg(usbatm, "%s entered\n", __func__);
for (i = 0; i < usb_dev->actconfig->desc.bNumInterfaces; i++) {
struct usb_interface *cur_intf = usb_dev->actconfig->interface[i];
if (cur_intf && (usb_get_intfdata(cur_intf) == usbatm)) {
usb_set_intfdata(cur_intf, NULL);
usb_driver_release_interface(&xusbatm_usb_driver, cur_intf);
}
}
}
static int xusbatm_atm_start(struct usbatm_data *usbatm,
struct atm_dev *atm_dev)
{
atm_dbg(usbatm, "%s entered\n", __func__);
eth_random_addr(atm_dev->esi);
return 0;
}
static int xusbatm_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return usbatm_usb_probe(intf, id,
xusbatm_drivers + (id - xusbatm_usb_ids));
}
static int __init xusbatm_init(void)
{
int i;
if (!num_vendor ||
num_vendor != num_product ||
num_vendor != num_rx_endpoint ||
num_vendor != num_tx_endpoint) {
printk(KERN_WARNING "xusbatm: malformed module parameters\n");
return -EINVAL;
}
for (i = 0; i < num_vendor; i++) {
rx_endpoint[i] |= USB_DIR_IN;
tx_endpoint[i] &= USB_ENDPOINT_NUMBER_MASK;
xusbatm_usb_ids[i].match_flags = USB_DEVICE_ID_MATCH_DEVICE;
xusbatm_usb_ids[i].idVendor = vendor[i];
xusbatm_usb_ids[i].idProduct = product[i];
xusbatm_drivers[i].driver_name = xusbatm_driver_name;
xusbatm_drivers[i].bind = xusbatm_bind;
xusbatm_drivers[i].unbind = xusbatm_unbind;
xusbatm_drivers[i].atm_start = xusbatm_atm_start;
xusbatm_drivers[i].bulk_in = rx_endpoint[i];
xusbatm_drivers[i].bulk_out = tx_endpoint[i];
xusbatm_drivers[i].rx_padding = rx_padding[i];
xusbatm_drivers[i].tx_padding = tx_padding[i];
}
return usb_register(&xusbatm_usb_driver);
}
static void __exit xusbatm_exit(void)
{
usb_deregister(&xusbatm_usb_driver);
}
