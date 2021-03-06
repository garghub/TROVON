static int wusbhc_rh_port_reset(struct wusbhc *wusbhc, u8 port_idx)
{
int result = 0;
struct wusb_port *port = wusb_port_by_idx(wusbhc, port_idx);
struct wusb_dev *wusb_dev = port->wusb_dev;
if (wusb_dev == NULL)
return -ENOTCONN;
port->status |= USB_PORT_STAT_RESET;
port->change |= USB_PORT_STAT_C_RESET;
if (wusb_dev->addr & WUSB_DEV_ADDR_UNAUTH)
result = 0;
else
result = wusb_dev_update_address(wusbhc, wusb_dev);
port->status &= ~USB_PORT_STAT_RESET;
port->status |= USB_PORT_STAT_ENABLE;
port->change |= USB_PORT_STAT_C_RESET | USB_PORT_STAT_C_ENABLE;
return result;
}
int wusbhc_rh_status_data(struct usb_hcd *usb_hcd, char *_buf)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
size_t cnt, size;
unsigned long *buf = (unsigned long *) _buf;
size = wusbhc->ports_max + 1 ;
size = (size + 8 - 1) / 8;
for (cnt = 0; cnt < wusbhc->ports_max; cnt++)
if (wusb_port_by_idx(wusbhc, cnt)->change)
set_bit(cnt + 1, buf);
else
clear_bit(cnt + 1, buf);
return size;
}
static int wusbhc_rh_get_hub_descr(struct wusbhc *wusbhc, u16 wValue,
u16 wIndex,
struct usb_hub_descriptor *descr,
u16 wLength)
{
u16 temp = 1 + (wusbhc->ports_max / 8);
u8 length = 7 + 2 * temp;
if (wLength < length)
return -ENOSPC;
descr->bDescLength = 7 + 2 * temp;
descr->bDescriptorType = 0x29;
descr->bNbrPorts = wusbhc->ports_max;
descr->wHubCharacteristics = cpu_to_le16(
0x00
| 0x00
| 0x10
| 0x00
| 0x00);
descr->bPwrOn2PwrGood = 0;
descr->bHubContrCurrent = 0;
memset(&descr->u.hs.DeviceRemovable[0], 0, temp);
memset(&descr->u.hs.DeviceRemovable[temp], 0xff, temp);
return 0;
}
static int wusbhc_rh_clear_hub_feat(struct wusbhc *wusbhc, u16 feature)
{
int result;
switch (feature) {
case C_HUB_LOCAL_POWER:
case C_HUB_OVER_CURRENT:
result = 0;
break;
default:
result = -EPIPE;
}
return result;
}
static int wusbhc_rh_get_hub_status(struct wusbhc *wusbhc, u32 *buf,
u16 wLength)
{
*buf = 0;
return 0;
}
static int wusbhc_rh_set_port_feat(struct wusbhc *wusbhc, u16 feature,
u8 selector, u8 port_idx)
{
struct device *dev = wusbhc->dev;
if (port_idx > wusbhc->ports_max)
return -EINVAL;
switch (feature) {
case USB_PORT_FEAT_C_OVER_CURRENT:
case USB_PORT_FEAT_C_ENABLE:
case USB_PORT_FEAT_C_SUSPEND:
case USB_PORT_FEAT_C_CONNECTION:
case USB_PORT_FEAT_C_RESET:
return 0;
case USB_PORT_FEAT_POWER:
mutex_lock(&wusbhc->mutex);
wusb_port_by_idx(wusbhc, port_idx)->status |= USB_PORT_STAT_POWER;
mutex_unlock(&wusbhc->mutex);
return 0;
case USB_PORT_FEAT_RESET:
return wusbhc_rh_port_reset(wusbhc, port_idx);
case USB_PORT_FEAT_ENABLE:
case USB_PORT_FEAT_SUSPEND:
dev_err(dev, "(port_idx %d) set feat %d/%d UNIMPLEMENTED\n",
port_idx, feature, selector);
return -ENOSYS;
default:
dev_err(dev, "(port_idx %d) set feat %d/%d UNKNOWN\n",
port_idx, feature, selector);
return -EPIPE;
}
return 0;
}
static int wusbhc_rh_clear_port_feat(struct wusbhc *wusbhc, u16 feature,
u8 selector, u8 port_idx)
{
int result = 0;
struct device *dev = wusbhc->dev;
if (port_idx > wusbhc->ports_max)
return -EINVAL;
mutex_lock(&wusbhc->mutex);
switch (feature) {
case USB_PORT_FEAT_POWER:
case USB_PORT_FEAT_C_OVER_CURRENT:
break;
case USB_PORT_FEAT_C_RESET:
wusb_port_by_idx(wusbhc, port_idx)->change &= ~USB_PORT_STAT_C_RESET;
break;
case USB_PORT_FEAT_C_CONNECTION:
wusb_port_by_idx(wusbhc, port_idx)->change &= ~USB_PORT_STAT_C_CONNECTION;
break;
case USB_PORT_FEAT_ENABLE:
__wusbhc_dev_disable(wusbhc, port_idx);
break;
case USB_PORT_FEAT_C_ENABLE:
wusb_port_by_idx(wusbhc, port_idx)->change &= ~USB_PORT_STAT_C_ENABLE;
break;
case USB_PORT_FEAT_SUSPEND:
case USB_PORT_FEAT_C_SUSPEND:
dev_err(dev, "(port_idx %d) Clear feat %d/%d UNIMPLEMENTED\n",
port_idx, feature, selector);
result = -ENOSYS;
break;
default:
dev_err(dev, "(port_idx %d) Clear feat %d/%d UNKNOWN\n",
port_idx, feature, selector);
result = -EPIPE;
break;
}
mutex_unlock(&wusbhc->mutex);
return result;
}
static int wusbhc_rh_get_port_status(struct wusbhc *wusbhc, u16 port_idx,
u32 *_buf, u16 wLength)
{
__le16 *buf = (__le16 *)_buf;
if (port_idx > wusbhc->ports_max)
return -EINVAL;
mutex_lock(&wusbhc->mutex);
buf[0] = cpu_to_le16(wusb_port_by_idx(wusbhc, port_idx)->status);
buf[1] = cpu_to_le16(wusb_port_by_idx(wusbhc, port_idx)->change);
mutex_unlock(&wusbhc->mutex);
return 0;
}
int wusbhc_rh_control(struct usb_hcd *usb_hcd, u16 reqntype, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
int result = -ENOSYS;
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
switch (reqntype) {
case GetHubDescriptor:
result = wusbhc_rh_get_hub_descr(
wusbhc, wValue, wIndex,
(struct usb_hub_descriptor *) buf, wLength);
break;
case ClearHubFeature:
result = wusbhc_rh_clear_hub_feat(wusbhc, wValue);
break;
case GetHubStatus:
result = wusbhc_rh_get_hub_status(wusbhc, (u32 *)buf, wLength);
break;
case SetPortFeature:
result = wusbhc_rh_set_port_feat(wusbhc, wValue, wIndex >> 8,
(wIndex & 0xff) - 1);
break;
case ClearPortFeature:
result = wusbhc_rh_clear_port_feat(wusbhc, wValue, wIndex >> 8,
(wIndex & 0xff) - 1);
break;
case GetPortStatus:
result = wusbhc_rh_get_port_status(wusbhc, wIndex - 1,
(u32 *)buf, wLength);
break;
case SetHubFeature:
default:
dev_err(wusbhc->dev, "%s (%p [%p], %x, %x, %x, %p, %x) "
"UNIMPLEMENTED\n", __func__, usb_hcd, wusbhc, reqntype,
wValue, wIndex, buf, wLength);
result = -ENOSYS;
}
return result;
}
int wusbhc_rh_start_port_reset(struct usb_hcd *usb_hcd, unsigned port_idx)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
dev_err(wusbhc->dev, "%s (%p [%p], port_idx %u) UNIMPLEMENTED\n",
__func__, usb_hcd, wusbhc, port_idx);
WARN_ON(1);
return -ENOSYS;
}
static void wusb_port_init(struct wusb_port *port)
{
port->status |= USB_PORT_STAT_HIGH_SPEED;
}
int wusbhc_rh_create(struct wusbhc *wusbhc)
{
int result = -ENOMEM;
size_t port_size, itr;
port_size = wusbhc->ports_max * sizeof(wusbhc->port[0]);
wusbhc->port = kzalloc(port_size, GFP_KERNEL);
if (wusbhc->port == NULL)
goto error_port_alloc;
for (itr = 0; itr < wusbhc->ports_max; itr++)
wusb_port_init(&wusbhc->port[itr]);
result = 0;
error_port_alloc:
return result;
}
void wusbhc_rh_destroy(struct wusbhc *wusbhc)
{
kfree(wusbhc->port);
}
