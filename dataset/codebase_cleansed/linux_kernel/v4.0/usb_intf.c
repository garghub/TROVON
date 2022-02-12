static int r871x_suspend(struct usb_interface *pusb_intf, pm_message_t state)
{
struct net_device *pnetdev = usb_get_intfdata(pusb_intf);
netdev_info(pnetdev, "Suspending...\n");
if (!pnetdev || !netif_running(pnetdev)) {
netdev_info(pnetdev, "Unable to suspend\n");
return 0;
}
if (pnetdev->netdev_ops->ndo_stop)
pnetdev->netdev_ops->ndo_stop(pnetdev);
mdelay(10);
netif_device_detach(pnetdev);
return 0;
}
static int r871x_resume(struct usb_interface *pusb_intf)
{
struct net_device *pnetdev = usb_get_intfdata(pusb_intf);
netdev_info(pnetdev, "Resuming...\n");
if (!pnetdev || !netif_running(pnetdev)) {
netdev_info(pnetdev, "Unable to resume\n");
return 0;
}
netif_device_attach(pnetdev);
if (pnetdev->netdev_ops->ndo_open)
pnetdev->netdev_ops->ndo_open(pnetdev);
return 0;
}
static int r871x_reset_resume(struct usb_interface *pusb_intf)
{
return 0;
}
static uint r8712_usb_dvobj_init(struct _adapter *padapter)
{
uint status = _SUCCESS;
struct usb_host_interface *phost_iface;
struct usb_interface_descriptor *piface_desc;
struct dvobj_priv *pdvobjpriv = &padapter->dvobjpriv;
struct usb_device *pusbd = pdvobjpriv->pusbdev;
pdvobjpriv->padapter = padapter;
padapter->EepromAddressSize = 6;
phost_iface = &pintf->altsetting[0];
piface_desc = &phost_iface->desc;
pdvobjpriv->nr_endpoint = piface_desc->bNumEndpoints;
if (pusbd->speed == USB_SPEED_HIGH) {
pdvobjpriv->ishighspeed = true;
dev_info(&pusbd->dev, "r8712u: USB_SPEED_HIGH with %d endpoints\n",
pdvobjpriv->nr_endpoint);
} else {
pdvobjpriv->ishighspeed = false;
dev_info(&pusbd->dev, "r8712u: USB_SPEED_LOW with %d endpoints\n",
pdvobjpriv->nr_endpoint);
}
if ((r8712_alloc_io_queue(padapter)) == _FAIL)
status = _FAIL;
return status;
}
static void r8712_usb_dvobj_deinit(struct _adapter *padapter)
{
}
void rtl871x_intf_stop(struct _adapter *padapter)
{
if (!padapter->bSurpriseRemoved) {
}
if (padapter->dvobjpriv.inirp_deinit)
padapter->dvobjpriv.inirp_deinit(padapter);
r8712_usb_write_port_cancel(padapter);
}
void r871x_dev_unload(struct _adapter *padapter)
{
if (padapter->bup == true) {
padapter->bDriverStopped = true;
rtl871x_intf_stop(padapter);
r8712_stop_drv_threads(padapter);
if (!padapter->bSurpriseRemoved) {
padapter->hw_init_completed = false;
rtl8712_hal_deinit(padapter);
}
if (padapter->dvobj_deinit)
padapter->dvobj_deinit(padapter);
padapter->bup = false;
}
}
static void disable_ht_for_spec_devid(const struct usb_device_id *pdid,
struct _adapter *padapter)
{
u16 vid, pid;
u32 flags;
int i;
int num = sizeof(specific_device_id_tbl) /
sizeof(struct specific_device_id);
for (i = 0; i < num; i++) {
vid = specific_device_id_tbl[i].idVendor;
pid = specific_device_id_tbl[i].idProduct;
flags = specific_device_id_tbl[i].flags;
if ((pdid->idVendor == vid) && (pdid->idProduct == pid) &&
(flags&SPEC_DEV_ID_DISABLE_HT)) {
padapter->registrypriv.ht_enable = 0;
padapter->registrypriv.cbw40_enable = 0;
padapter->registrypriv.ampdu_enable = 0;
}
}
}
static int r871xu_drv_init(struct usb_interface *pusb_intf,
const struct usb_device_id *pdid)
{
uint status;
struct _adapter *padapter = NULL;
struct dvobj_priv *pdvobjpriv;
struct net_device *pnetdev;
struct usb_device *udev;
udev = interface_to_usbdev(pusb_intf);
usb_get_dev(udev);
pintf = pusb_intf;
pnetdev = r8712_init_netdev();
if (!pnetdev)
goto error;
padapter = netdev_priv(pnetdev);
disable_ht_for_spec_devid(pdid, padapter);
pdvobjpriv = &padapter->dvobjpriv;
pdvobjpriv->padapter = padapter;
padapter->dvobjpriv.pusbdev = udev;
padapter->pusb_intf = pusb_intf;
usb_set_intfdata(pusb_intf, pnetdev);
SET_NETDEV_DEV(pnetdev, &pusb_intf->dev);
pnetdev->dev.type = &wlan_type;
padapter->dvobj_init = &r8712_usb_dvobj_init;
padapter->dvobj_deinit = &r8712_usb_dvobj_deinit;
padapter->halpriv.hal_bus_init = &r8712_usb_hal_bus_init;
padapter->dvobjpriv.inirp_init = &r8712_usb_inirp_init;
padapter->dvobjpriv.inirp_deinit = &r8712_usb_inirp_deinit;
if (!padapter->dvobj_init)
goto error;
else {
status = padapter->dvobj_init(padapter);
if (status != _SUCCESS)
goto error;
}
status = r8712_init_drv_sw(padapter);
if (status == _FAIL)
goto error;
{
int i, offset;
u8 mac[6];
u8 tmpU1b, AutoloadFail, eeprom_CustomerID;
u8 *pdata = padapter->eeprompriv.efuse_eeprom_data;
tmpU1b = r8712_read8(padapter, EE_9346CR);
dev_info(&udev->dev, "r8712u: Boot from %s: Autoload %s\n",
(tmpU1b & _9356SEL) ? "EEPROM" : "EFUSE",
(tmpU1b & _EEPROM_EN) ? "OK" : "Failed");
if (tmpU1b & _EEPROM_EN) {
AutoloadFail = true;
tmpU1b = r8712_read8(padapter, EFUSE_TEST+3);
r8712_write8(padapter, EFUSE_TEST + 3, tmpU1b | 0x80);
msleep(20);
r8712_write8(padapter, EFUSE_TEST + 3,
(tmpU1b & (~BIT(7))));
tmpU1b = (u8)((r8712_read32(padapter, PMC_FSM) >> 15) &
0x1F);
if (tmpU1b == 0x3)
padapter->registrypriv.chip_version =
RTL8712_3rdCUT;
else
padapter->registrypriv.chip_version =
(tmpU1b >> 1) + 1;
switch (padapter->registrypriv.chip_version) {
case RTL8712_1stCUT:
case RTL8712_2ndCUT:
case RTL8712_3rdCUT:
break;
default:
padapter->registrypriv.chip_version =
RTL8712_2ndCUT;
break;
}
for (i = 0, offset = 0; i < 128; i += 8, offset++)
r8712_efuse_pg_packet_read(padapter, offset,
&pdata[i]);
if (!r8712_initmac || !mac_pton(r8712_initmac, mac)) {
ether_addr_copy(mac, &pdata[0x12]);
}
eeprom_CustomerID = pdata[0x52];
switch (eeprom_CustomerID) {
case EEPROM_CID_ALPHA:
padapter->eeprompriv.CustomerID =
RT_CID_819x_ALPHA;
break;
case EEPROM_CID_CAMEO:
padapter->eeprompriv.CustomerID =
RT_CID_819x_CAMEO;
break;
case EEPROM_CID_SITECOM:
padapter->eeprompriv.CustomerID =
RT_CID_819x_Sitecom;
break;
case EEPROM_CID_COREGA:
padapter->eeprompriv.CustomerID =
RT_CID_COREGA;
break;
case EEPROM_CID_Senao:
padapter->eeprompriv.CustomerID =
RT_CID_819x_Senao;
break;
case EEPROM_CID_EDIMAX_BELKIN:
padapter->eeprompriv.CustomerID =
RT_CID_819x_Edimax_Belkin;
break;
case EEPROM_CID_SERCOMM_BELKIN:
padapter->eeprompriv.CustomerID =
RT_CID_819x_Sercomm_Belkin;
break;
case EEPROM_CID_WNC_COREGA:
padapter->eeprompriv.CustomerID =
RT_CID_819x_WNC_COREGA;
break;
case EEPROM_CID_WHQL:
break;
case EEPROM_CID_NetCore:
padapter->eeprompriv.CustomerID =
RT_CID_819x_Netcore;
break;
case EEPROM_CID_CAMEO1:
padapter->eeprompriv.CustomerID =
RT_CID_819x_CAMEO1;
break;
case EEPROM_CID_CLEVO:
padapter->eeprompriv.CustomerID =
RT_CID_819x_CLEVO;
break;
default:
padapter->eeprompriv.CustomerID =
RT_CID_DEFAULT;
break;
}
dev_info(&udev->dev, "r8712u: CustomerID = 0x%.4x\n",
padapter->eeprompriv.CustomerID);
switch (padapter->eeprompriv.CustomerID) {
case RT_CID_DEFAULT:
case RT_CID_819x_ALPHA:
case RT_CID_819x_CAMEO:
padapter->ledpriv.LedStrategy = SW_LED_MODE1;
padapter->ledpriv.bRegUseLed = true;
break;
case RT_CID_819x_Sitecom:
padapter->ledpriv.LedStrategy = SW_LED_MODE2;
padapter->ledpriv.bRegUseLed = true;
break;
case RT_CID_COREGA:
case RT_CID_819x_Senao:
padapter->ledpriv.LedStrategy = SW_LED_MODE3;
padapter->ledpriv.bRegUseLed = true;
break;
case RT_CID_819x_Edimax_Belkin:
padapter->ledpriv.LedStrategy = SW_LED_MODE4;
padapter->ledpriv.bRegUseLed = true;
break;
case RT_CID_819x_Sercomm_Belkin:
padapter->ledpriv.LedStrategy = SW_LED_MODE5;
padapter->ledpriv.bRegUseLed = true;
break;
case RT_CID_819x_WNC_COREGA:
padapter->ledpriv.LedStrategy = SW_LED_MODE6;
padapter->ledpriv.bRegUseLed = true;
break;
default:
padapter->ledpriv.LedStrategy = SW_LED_MODE0;
padapter->ledpriv.bRegUseLed = false;
break;
}
} else
AutoloadFail = false;
if (((mac[0] == 0xff) && (mac[1] == 0xff) &&
(mac[2] == 0xff) && (mac[3] == 0xff) &&
(mac[4] == 0xff) && (mac[5] == 0xff)) ||
((mac[0] == 0x00) && (mac[1] == 0x00) &&
(mac[2] == 0x00) && (mac[3] == 0x00) &&
(mac[4] == 0x00) && (mac[5] == 0x00)) ||
(!AutoloadFail)) {
mac[0] = 0x00;
mac[1] = 0xe0;
mac[2] = 0x4c;
mac[3] = 0x87;
mac[4] = 0x00;
mac[5] = 0x00;
}
if (r8712_initmac) {
mac[0] &= 0xFE;
dev_info(&udev->dev,
"r8712u: MAC Address from user = %pM\n", mac);
} else
dev_info(&udev->dev,
"r8712u: MAC Address from efuse = %pM\n", mac);
ether_addr_copy(pnetdev->dev_addr, mac);
}
if (rtl871x_load_fw(padapter))
goto error;
spin_lock_init(&padapter->lockRxFF0Filter);
mutex_init(&padapter->mutex_start);
return 0;
error:
usb_put_dev(udev);
usb_set_intfdata(pusb_intf, NULL);
if (padapter && padapter->dvobj_deinit != NULL)
padapter->dvobj_deinit(padapter);
if (pnetdev)
free_netdev(pnetdev);
return -ENODEV;
}
static void r871xu_dev_remove(struct usb_interface *pusb_intf)
{
struct net_device *pnetdev = usb_get_intfdata(pusb_intf);
struct usb_device *udev = interface_to_usbdev(pusb_intf);
if (pnetdev) {
struct _adapter *padapter = netdev_priv(pnetdev);
usb_set_intfdata(pusb_intf, NULL);
release_firmware(padapter->fw);
wait_for_completion(&padapter->rtl8712_fw_ready);
if (drvpriv.drv_registered == true)
padapter->bSurpriseRemoved = true;
unregister_netdev(pnetdev);
flush_scheduled_work();
udelay(1);
r8712_stop_drv_timers(padapter);
r871x_dev_unload(padapter);
r8712_free_drv_sw(padapter);
usb_put_dev(udev);
}
if (udev->state != USB_STATE_NOTATTACHED)
usb_reset_device(udev);
}
static int __init r8712u_drv_entry(void)
{
drvpriv.drv_registered = true;
return usb_register(&drvpriv.r871xu_drv);
}
static void __exit r8712u_drv_halt(void)
{
drvpriv.drv_registered = false;
usb_deregister(&drvpriv.r871xu_drv);
}
