static int __hwahc_set_cluster_id(struct hwahc *hwahc, u8 cluster_id)
{
int result;
struct wusbhc *wusbhc = &hwahc->wusbhc;
struct wahc *wa = &hwahc->wa;
struct device *dev = &wa->usb_iface->dev;
result = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_SET_CLUSTER_ID,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
cluster_id,
wa->usb_iface->cur_altsetting->desc.bInterfaceNumber,
NULL, 0, USB_CTRL_SET_TIMEOUT);
if (result < 0)
dev_err(dev, "Cannot set WUSB Cluster ID to 0x%02x: %d\n",
cluster_id, result);
else
wusbhc->cluster_id = cluster_id;
dev_info(dev, "Wireless USB Cluster ID set to 0x%02x\n", cluster_id);
return result;
}
static int __hwahc_op_set_num_dnts(struct wusbhc *wusbhc, u8 interval, u8 slots)
{
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
return usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_SET_NUM_DNTS,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
interval << 8 | slots,
wa->usb_iface->cur_altsetting->desc.bInterfaceNumber,
NULL, 0, USB_CTRL_SET_TIMEOUT);
}
static int hwahc_op_reset(struct usb_hcd *usb_hcd)
{
int result;
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct device *dev = &hwahc->wa.usb_iface->dev;
mutex_lock(&wusbhc->mutex);
wa_nep_disarm(&hwahc->wa);
result = __wa_set_feature(&hwahc->wa, WA_RESET);
if (result < 0) {
dev_err(dev, "error commanding HC to reset: %d\n", result);
goto error_unlock;
}
result = __wa_wait_status(&hwahc->wa, WA_STATUS_RESETTING, 0);
if (result < 0) {
dev_err(dev, "error waiting for HC to reset: %d\n", result);
goto error_unlock;
}
error_unlock:
mutex_unlock(&wusbhc->mutex);
return result;
}
static int hwahc_op_start(struct usb_hcd *usb_hcd)
{
u8 addr;
int result;
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
result = -ENOSPC;
mutex_lock(&wusbhc->mutex);
addr = wusb_cluster_id_get();
if (addr == 0)
goto error_cluster_id_get;
result = __hwahc_set_cluster_id(hwahc, addr);
if (result < 0)
goto error_set_cluster_id;
usb_hcd->uses_new_polling = 1;
set_bit(HCD_FLAG_POLL_RH, &usb_hcd->flags);
usb_hcd->state = HC_STATE_RUNNING;
pm_runtime_get_noresume(&usb_hcd->self.root_hub->dev);
result = 0;
out:
mutex_unlock(&wusbhc->mutex);
return result;
error_set_cluster_id:
wusb_cluster_id_put(wusbhc->cluster_id);
error_cluster_id_get:
goto out;
}
static void hwahc_op_stop(struct usb_hcd *usb_hcd)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
mutex_lock(&wusbhc->mutex);
wusb_cluster_id_put(wusbhc->cluster_id);
mutex_unlock(&wusbhc->mutex);
}
static int hwahc_op_get_frame_number(struct usb_hcd *usb_hcd)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
return usb_get_current_frame_number(wa->usb_dev);
}
static int hwahc_op_urb_enqueue(struct usb_hcd *usb_hcd, struct urb *urb,
gfp_t gfp)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
return wa_urb_enqueue(&hwahc->wa, urb->ep, urb, gfp);
}
static int hwahc_op_urb_dequeue(struct usb_hcd *usb_hcd, struct urb *urb,
int status)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
return wa_urb_dequeue(&hwahc->wa, urb, status);
}
static void hwahc_op_endpoint_disable(struct usb_hcd *usb_hcd,
struct usb_host_endpoint *ep)
{
struct wusbhc *wusbhc = usb_hcd_to_wusbhc(usb_hcd);
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
rpipe_ep_disable(&hwahc->wa, ep);
}
static int __hwahc_op_wusbhc_start(struct wusbhc *wusbhc)
{
int result;
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct device *dev = &hwahc->wa.usb_iface->dev;
result = __wa_set_feature(&hwahc->wa, WA_ENABLE);
if (result < 0) {
dev_err(dev, "error commanding HC to start: %d\n", result);
goto error_stop;
}
result = __wa_wait_status(&hwahc->wa, WA_ENABLE, WA_ENABLE);
if (result < 0) {
dev_err(dev, "error waiting for HC to start: %d\n", result);
goto error_stop;
}
result = wa_nep_arm(&hwahc->wa, GFP_KERNEL);
if (result < 0) {
dev_err(dev, "cannot listen to notifications: %d\n", result);
goto error_stop;
}
return result;
error_stop:
__wa_clear_feature(&hwahc->wa, WA_ENABLE);
return result;
}
static void __hwahc_op_wusbhc_stop(struct wusbhc *wusbhc, int delay)
{
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
u8 iface_no = wa->usb_iface->cur_altsetting->desc.bInterfaceNumber;
int ret;
ret = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_CHAN_STOP,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
delay * 1000,
iface_no,
NULL, 0, USB_CTRL_SET_TIMEOUT);
if (ret == 0)
msleep(delay);
wa_nep_disarm(&hwahc->wa);
__wa_stop(&hwahc->wa);
}
static int __hwahc_op_bwa_set(struct wusbhc *wusbhc, s8 stream_index,
const struct uwb_mas_bm *mas)
{
int result;
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
struct device *dev = &wa->usb_iface->dev;
u8 mas_le[UWB_NUM_MAS/8];
result = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_SET_STREAM_IDX,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
stream_index,
wa->usb_iface->cur_altsetting->desc.bInterfaceNumber,
NULL, 0, USB_CTRL_SET_TIMEOUT);
if (result < 0) {
dev_err(dev, "Cannot set WUSB stream index: %d\n", result);
goto out;
}
uwb_mas_bm_copy_le(mas_le, mas);
result = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_SET_WUSB_MAS,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, wa->usb_iface->cur_altsetting->desc.bInterfaceNumber,
mas_le, 32, USB_CTRL_SET_TIMEOUT);
if (result < 0)
dev_err(dev, "Cannot set WUSB MAS allocation: %d\n", result);
out:
return result;
}
static int __hwahc_op_mmcie_add(struct wusbhc *wusbhc, u8 interval,
u8 repeat_cnt, u8 handle,
struct wuie_hdr *wuie)
{
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
u8 iface_no = wa->usb_iface->cur_altsetting->desc.bInterfaceNumber;
return usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_ADD_MMC_IE,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
interval << 8 | repeat_cnt,
handle << 8 | iface_no,
wuie, wuie->bLength, USB_CTRL_SET_TIMEOUT);
}
static int __hwahc_op_mmcie_rm(struct wusbhc *wusbhc, u8 handle)
{
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
u8 iface_no = wa->usb_iface->cur_altsetting->desc.bInterfaceNumber;
return usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_REMOVE_MMC_IE,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, handle << 8 | iface_no,
NULL, 0, USB_CTRL_SET_TIMEOUT);
}
static int __hwahc_op_dev_info_set(struct wusbhc *wusbhc,
struct wusb_dev *wusb_dev)
{
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
u8 iface_no = wa->usb_iface->cur_altsetting->desc.bInterfaceNumber;
struct hwa_dev_info *dev_info;
int ret;
dev_info = kzalloc(sizeof(struct hwa_dev_info), GFP_KERNEL);
if (!dev_info)
return -ENOMEM;
uwb_mas_bm_copy_le(dev_info->bmDeviceAvailability,
&wusb_dev->availability);
dev_info->bDeviceAddress = wusb_dev->addr;
if (wusb_dev->wusb_cap_descr)
dev_info->wPHYRates = wusb_dev->wusb_cap_descr->wPHYRates;
else
dev_info->wPHYRates = cpu_to_le16(USB_WIRELESS_PHY_53);
ret = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
WUSB_REQ_SET_DEV_INFO,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, wusb_dev->port_idx << 8 | iface_no,
dev_info, sizeof(struct hwa_dev_info),
USB_CTRL_SET_TIMEOUT);
kfree(dev_info);
return ret;
}
static int __hwahc_dev_set_key(struct wusbhc *wusbhc, u8 port_idx, u32 tkid,
const void *key, size_t key_size,
u8 key_idx)
{
int result = -ENOMEM;
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
u8 iface_no = wa->usb_iface->cur_altsetting->desc.bInterfaceNumber;
struct usb_key_descriptor *keyd;
size_t keyd_len;
keyd_len = sizeof(*keyd) + key_size;
keyd = kzalloc(keyd_len, GFP_KERNEL);
if (keyd == NULL)
return -ENOMEM;
keyd->bLength = keyd_len;
keyd->bDescriptorType = USB_DT_KEY;
keyd->tTKID[0] = (tkid >> 0) & 0xff;
keyd->tTKID[1] = (tkid >> 8) & 0xff;
keyd->tTKID[2] = (tkid >> 16) & 0xff;
memcpy(keyd->bKeyData, key, key_size);
result = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
USB_REQ_SET_DESCRIPTOR,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
USB_DT_KEY << 8 | key_idx,
port_idx << 8 | iface_no,
keyd, keyd_len, USB_CTRL_SET_TIMEOUT);
kzfree(keyd);
return result;
}
static int __hwahc_op_set_ptk(struct wusbhc *wusbhc, u8 port_idx, u32 tkid,
const void *key, size_t key_size)
{
int result = -ENOMEM;
struct hwahc *hwahc = container_of(wusbhc, struct hwahc, wusbhc);
struct wahc *wa = &hwahc->wa;
u8 iface_no = wa->usb_iface->cur_altsetting->desc.bInterfaceNumber;
u8 encryption_value;
if (key) {
u8 key_idx = wusb_key_index(0, WUSB_KEY_INDEX_TYPE_PTK,
WUSB_KEY_INDEX_ORIGINATOR_HOST);
result = __hwahc_dev_set_key(wusbhc, port_idx, tkid,
key, key_size, key_idx);
if (result < 0)
goto error_set_key;
encryption_value = wusbhc->ccm1_etd->bEncryptionValue;
} else {
encryption_value = 0;
}
result = usb_control_msg(wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
USB_REQ_SET_ENCRYPTION,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
encryption_value, port_idx << 8 | iface_no,
NULL, 0, USB_CTRL_SET_TIMEOUT);
if (result < 0)
dev_err(wusbhc->dev, "Can't set host's WUSB encryption for "
"port index %u to %s (value %d): %d\n", port_idx,
wusb_et_name(wusbhc->ccm1_etd->bEncryptionType),
wusbhc->ccm1_etd->bEncryptionValue, result);
error_set_key:
return result;
}
static int __hwahc_op_set_gtk(struct wusbhc *wusbhc, u32 tkid,
const void *key, size_t key_size)
{
u8 key_idx = wusb_key_index(0, WUSB_KEY_INDEX_TYPE_GTK,
WUSB_KEY_INDEX_ORIGINATOR_HOST);
return __hwahc_dev_set_key(wusbhc, 0, tkid, key, key_size, key_idx);
}
static int wa_fill_descr(struct wahc *wa)
{
int result;
struct device *dev = &wa->usb_iface->dev;
char *itr;
struct usb_device *usb_dev = wa->usb_dev;
struct usb_descriptor_header *hdr;
struct usb_wa_descriptor *wa_descr;
size_t itr_size, actconfig_idx;
actconfig_idx = (usb_dev->actconfig - usb_dev->config) /
sizeof(usb_dev->config[0]);
itr = usb_dev->rawdescriptors[actconfig_idx];
itr_size = le16_to_cpu(usb_dev->actconfig->desc.wTotalLength);
while (itr_size >= sizeof(*hdr)) {
hdr = (struct usb_descriptor_header *) itr;
dev_dbg(dev, "Extra device descriptor: "
"type %02x/%u bytes @ %zu (%zu left)\n",
hdr->bDescriptorType, hdr->bLength,
(itr - usb_dev->rawdescriptors[actconfig_idx]),
itr_size);
if (hdr->bDescriptorType == USB_DT_WIRE_ADAPTER)
goto found;
itr += hdr->bLength;
itr_size -= hdr->bLength;
}
dev_err(dev, "cannot find Wire Adapter Class descriptor\n");
return -ENODEV;
found:
result = -EINVAL;
if (hdr->bLength > itr_size) {
dev_err(dev, "incomplete Wire Adapter Class descriptor "
"(%zu bytes left, %u needed)\n",
itr_size, hdr->bLength);
goto error;
}
if (hdr->bLength < sizeof(*wa->wa_descr)) {
dev_err(dev, "short Wire Adapter Class descriptor\n");
goto error;
}
wa->wa_descr = wa_descr = (struct usb_wa_descriptor *) hdr;
if (le16_to_cpu(wa_descr->bcdWAVersion) > 0x0100)
dev_warn(dev, "Wire Adapter v%d.%d newer than groked v1.0\n",
le16_to_cpu(wa_descr->bcdWAVersion) & 0xff00 >> 8,
le16_to_cpu(wa_descr->bcdWAVersion) & 0x00ff);
result = 0;
error:
return result;
}
static int hwahc_security_create(struct hwahc *hwahc)
{
int result;
struct wusbhc *wusbhc = &hwahc->wusbhc;
struct usb_device *usb_dev = hwahc->wa.usb_dev;
struct device *dev = &usb_dev->dev;
struct usb_security_descriptor *secd;
struct usb_encryption_descriptor *etd;
void *itr, *top;
size_t itr_size, needed, bytes;
u8 index;
char buf[64];
index = (usb_dev->actconfig - usb_dev->config) /
sizeof(usb_dev->config[0]);
itr = usb_dev->rawdescriptors[index];
itr_size = le16_to_cpu(usb_dev->actconfig->desc.wTotalLength);
top = itr + itr_size;
result = __usb_get_extra_descriptor(usb_dev->rawdescriptors[index],
le16_to_cpu(usb_dev->actconfig->desc.wTotalLength),
USB_DT_SECURITY, (void **) &secd);
if (result == -1) {
dev_warn(dev, "BUG? WUSB host has no security descriptors\n");
return 0;
}
needed = sizeof(*secd);
if (top - (void *)secd < needed) {
dev_err(dev, "BUG? Not enough data to process security "
"descriptor header (%zu bytes left vs %zu needed)\n",
top - (void *) secd, needed);
return 0;
}
needed = le16_to_cpu(secd->wTotalLength);
if (top - (void *)secd < needed) {
dev_err(dev, "BUG? Not enough data to process security "
"descriptors (%zu bytes left vs %zu needed)\n",
top - (void *) secd, needed);
return 0;
}
itr = (void *) secd + sizeof(*secd);
top = (void *) secd + le16_to_cpu(secd->wTotalLength);
index = 0;
bytes = 0;
while (itr < top) {
etd = itr;
if (top - itr < sizeof(*etd)) {
dev_err(dev, "BUG: bad host security descriptor; "
"not enough data (%zu vs %zu left)\n",
top - itr, sizeof(*etd));
break;
}
if (etd->bLength < sizeof(*etd)) {
dev_err(dev, "BUG: bad host encryption descriptor; "
"descriptor is too short "
"(%zu vs %zu needed)\n",
(size_t)etd->bLength, sizeof(*etd));
break;
}
itr += etd->bLength;
bytes += snprintf(buf + bytes, sizeof(buf) - bytes,
"%s (0x%02x) ",
wusb_et_name(etd->bEncryptionType),
etd->bEncryptionValue);
wusbhc->ccm1_etd = etd;
}
dev_info(dev, "supported encryption types: %s\n", buf);
if (wusbhc->ccm1_etd == NULL) {
dev_err(dev, "E: host doesn't support CCM-1 crypto\n");
return 0;
}
return 0;
}
static void hwahc_security_release(struct hwahc *hwahc)
{
}
static int hwahc_create(struct hwahc *hwahc, struct usb_interface *iface,
kernel_ulong_t quirks)
{
int result;
struct device *dev = &iface->dev;
struct wusbhc *wusbhc = &hwahc->wusbhc;
struct wahc *wa = &hwahc->wa;
struct usb_device *usb_dev = interface_to_usbdev(iface);
wa->usb_dev = usb_get_dev(usb_dev);
wa->usb_iface = usb_get_intf(iface);
wusbhc->dev = dev;
wusbhc->uwb_rc = NULL;
result = wa_fill_descr(wa);
if (result < 0)
goto error_fill_descriptor;
if (wa->wa_descr->bNumPorts > USB_MAXCHILDREN) {
dev_err(dev, "FIXME: USB_MAXCHILDREN too low for WUSB "
"adapter (%u ports)\n", wa->wa_descr->bNumPorts);
wusbhc->ports_max = USB_MAXCHILDREN;
} else {
wusbhc->ports_max = wa->wa_descr->bNumPorts;
}
wusbhc->mmcies_max = wa->wa_descr->bNumMMCIEs;
wusbhc->start = __hwahc_op_wusbhc_start;
wusbhc->stop = __hwahc_op_wusbhc_stop;
wusbhc->mmcie_add = __hwahc_op_mmcie_add;
wusbhc->mmcie_rm = __hwahc_op_mmcie_rm;
wusbhc->dev_info_set = __hwahc_op_dev_info_set;
wusbhc->bwa_set = __hwahc_op_bwa_set;
wusbhc->set_num_dnts = __hwahc_op_set_num_dnts;
wusbhc->set_ptk = __hwahc_op_set_ptk;
wusbhc->set_gtk = __hwahc_op_set_gtk;
result = hwahc_security_create(hwahc);
if (result < 0) {
dev_err(dev, "Can't initialize security: %d\n", result);
goto error_security_create;
}
wa->wusb = wusbhc;
result = wusbhc_create(&hwahc->wusbhc);
if (result < 0) {
dev_err(dev, "Can't create WUSB HC structures: %d\n", result);
goto error_wusbhc_create;
}
result = wa_create(&hwahc->wa, iface, quirks);
if (result < 0)
goto error_wa_create;
return 0;
error_wa_create:
wusbhc_destroy(&hwahc->wusbhc);
error_wusbhc_create:
error_security_create:
error_fill_descriptor:
usb_put_intf(iface);
usb_put_dev(usb_dev);
return result;
}
static void hwahc_destroy(struct hwahc *hwahc)
{
struct wusbhc *wusbhc = &hwahc->wusbhc;
mutex_lock(&wusbhc->mutex);
__wa_destroy(&hwahc->wa);
wusbhc_destroy(&hwahc->wusbhc);
hwahc_security_release(hwahc);
hwahc->wusbhc.dev = NULL;
uwb_rc_put(wusbhc->uwb_rc);
usb_put_intf(hwahc->wa.usb_iface);
usb_put_dev(hwahc->wa.usb_dev);
mutex_unlock(&wusbhc->mutex);
}
static void hwahc_init(struct hwahc *hwahc)
{
wa_init(&hwahc->wa);
}
static int hwahc_probe(struct usb_interface *usb_iface,
const struct usb_device_id *id)
{
int result;
struct usb_hcd *usb_hcd;
struct wusbhc *wusbhc;
struct hwahc *hwahc;
struct device *dev = &usb_iface->dev;
result = -ENOMEM;
usb_hcd = usb_create_hcd(&hwahc_hc_driver, &usb_iface->dev, "wusb-hwa");
if (usb_hcd == NULL) {
dev_err(dev, "unable to allocate instance\n");
goto error_alloc;
}
usb_hcd->wireless = 1;
usb_hcd->self.sg_tablesize = ~0;
wusbhc = usb_hcd_to_wusbhc(usb_hcd);
hwahc = container_of(wusbhc, struct hwahc, wusbhc);
hwahc_init(hwahc);
result = hwahc_create(hwahc, usb_iface, id->driver_info);
if (result < 0) {
dev_err(dev, "Cannot initialize internals: %d\n", result);
goto error_hwahc_create;
}
result = usb_add_hcd(usb_hcd, 0, 0);
if (result < 0) {
dev_err(dev, "Cannot add HCD: %d\n", result);
goto error_add_hcd;
}
device_wakeup_enable(usb_hcd->self.controller);
result = wusbhc_b_create(&hwahc->wusbhc);
if (result < 0) {
dev_err(dev, "Cannot setup phase B of WUSBHC: %d\n", result);
goto error_wusbhc_b_create;
}
return 0;
error_wusbhc_b_create:
usb_remove_hcd(usb_hcd);
error_add_hcd:
hwahc_destroy(hwahc);
error_hwahc_create:
usb_put_hcd(usb_hcd);
error_alloc:
return result;
}
static void hwahc_disconnect(struct usb_interface *usb_iface)
{
struct usb_hcd *usb_hcd;
struct wusbhc *wusbhc;
struct hwahc *hwahc;
usb_hcd = usb_get_intfdata(usb_iface);
wusbhc = usb_hcd_to_wusbhc(usb_hcd);
hwahc = container_of(wusbhc, struct hwahc, wusbhc);
wusbhc_b_destroy(&hwahc->wusbhc);
usb_remove_hcd(usb_hcd);
hwahc_destroy(hwahc);
usb_put_hcd(usb_hcd);
}
