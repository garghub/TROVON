static int cbaf_check(struct cbaf *cbaf)
{
int result;
struct device *dev = &cbaf->usb_iface->dev;
struct wusb_cbaf_assoc_info *assoc_info;
struct wusb_cbaf_assoc_request *assoc_request;
size_t assoc_size;
void *itr, *top;
int ar_rhi = 0, ar_assoc = 0;
result = usb_control_msg(
cbaf->usb_dev, usb_rcvctrlpipe(cbaf->usb_dev, 0),
CBAF_REQ_GET_ASSOCIATION_INFORMATION,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, cbaf->usb_iface->cur_altsetting->desc.bInterfaceNumber,
cbaf->buffer, cbaf->buffer_size, 1000 );
if (result < 0) {
dev_err(dev, "Cannot get available association types: %d\n",
result);
return result;
}
assoc_info = cbaf->buffer;
if (result < sizeof(*assoc_info)) {
dev_err(dev, "Not enough data to decode association info "
"header (%zu vs %zu bytes required)\n",
(size_t)result, sizeof(*assoc_info));
return result;
}
assoc_size = le16_to_cpu(assoc_info->Length);
if (result < assoc_size) {
dev_err(dev, "Not enough data to decode association info "
"(%zu vs %zu bytes required)\n",
(size_t)assoc_size, sizeof(*assoc_info));
return result;
}
itr = cbaf->buffer + sizeof(*assoc_info);
top = cbaf->buffer + assoc_size;
dev_dbg(dev, "Found %u association requests (%zu bytes)\n",
assoc_info->NumAssociationRequests, assoc_size);
while (itr < top) {
u16 ar_type, ar_subtype;
u32 ar_size;
const char *ar_name;
assoc_request = itr;
if (top - itr < sizeof(*assoc_request)) {
dev_err(dev, "Not enough data to decode associaton "
"request (%zu vs %zu bytes needed)\n",
top - itr, sizeof(*assoc_request));
break;
}
ar_type = le16_to_cpu(assoc_request->AssociationTypeId);
ar_subtype = le16_to_cpu(assoc_request->AssociationSubTypeId);
ar_size = le32_to_cpu(assoc_request->AssociationTypeInfoSize);
ar_name = "unknown";
switch (ar_type) {
case AR_TYPE_WUSB:
switch (ar_subtype) {
case AR_TYPE_WUSB_RETRIEVE_HOST_INFO:
ar_name = "RETRIEVE_HOST_INFO";
ar_rhi = 1;
break;
case AR_TYPE_WUSB_ASSOCIATE:
ar_name = "ASSOCIATE";
ar_assoc = 1;
break;
};
break;
};
dev_dbg(dev, "Association request #%02u: 0x%04x/%04x "
"(%zu bytes): %s\n",
assoc_request->AssociationDataIndex, ar_type,
ar_subtype, (size_t)ar_size, ar_name);
itr += sizeof(*assoc_request);
}
if (!ar_rhi) {
dev_err(dev, "Missing RETRIEVE_HOST_INFO association "
"request\n");
return -EINVAL;
}
if (!ar_assoc) {
dev_err(dev, "Missing ASSOCIATE association request\n");
return -EINVAL;
}
return 0;
}
static int cbaf_send_host_info(struct cbaf *cbaf)
{
struct wusb_cbaf_host_info *hi;
size_t name_len;
size_t hi_size;
hi = cbaf->buffer;
memset(hi, 0, sizeof(*hi));
*hi = cbaf_host_info_defaults;
hi->CHID = cbaf->chid;
hi->LangID = 0;
strlcpy(hi->HostFriendlyName, cbaf->host_name, CBA_NAME_LEN);
name_len = strlen(cbaf->host_name);
hi->HostFriendlyName_hdr.len = cpu_to_le16(name_len);
hi_size = sizeof(*hi) + name_len;
return usb_control_msg(cbaf->usb_dev, usb_sndctrlpipe(cbaf->usb_dev, 0),
CBAF_REQ_SET_ASSOCIATION_RESPONSE,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0x0101,
cbaf->usb_iface->cur_altsetting->desc.bInterfaceNumber,
hi, hi_size, 1000 );
}
static int cbaf_cdid_get(struct cbaf *cbaf)
{
int result;
struct device *dev = &cbaf->usb_iface->dev;
struct wusb_cbaf_device_info *di;
size_t needed;
di = cbaf->buffer;
result = usb_control_msg(
cbaf->usb_dev, usb_rcvctrlpipe(cbaf->usb_dev, 0),
CBAF_REQ_GET_ASSOCIATION_REQUEST,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0x0200, cbaf->usb_iface->cur_altsetting->desc.bInterfaceNumber,
di, cbaf->buffer_size, 1000 );
if (result < 0) {
dev_err(dev, "Cannot request device information: %d\n", result);
return result;
}
needed = result < sizeof(*di) ? sizeof(*di) : le32_to_cpu(di->Length);
if (result < needed) {
dev_err(dev, "Not enough data in DEVICE_INFO reply (%zu vs "
"%zu bytes needed)\n", (size_t)result, needed);
return -ENOENT;
}
strlcpy(cbaf->device_name, di->DeviceFriendlyName, CBA_NAME_LEN);
cbaf->cdid = di->CDID;
cbaf->device_band_groups = le16_to_cpu(di->BandGroups);
return 0;
}
static ssize_t cbaf_wusb_chid_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
char pr_chid[WUSB_CKHDID_STRSIZE];
ckhdid_printf(pr_chid, sizeof(pr_chid), &cbaf->chid);
return scnprintf(buf, PAGE_SIZE, "%s\n", pr_chid);
}
static ssize_t cbaf_wusb_chid_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t result;
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
result = sscanf(buf,
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx",
&cbaf->chid.data[0] , &cbaf->chid.data[1],
&cbaf->chid.data[2] , &cbaf->chid.data[3],
&cbaf->chid.data[4] , &cbaf->chid.data[5],
&cbaf->chid.data[6] , &cbaf->chid.data[7],
&cbaf->chid.data[8] , &cbaf->chid.data[9],
&cbaf->chid.data[10], &cbaf->chid.data[11],
&cbaf->chid.data[12], &cbaf->chid.data[13],
&cbaf->chid.data[14], &cbaf->chid.data[15]);
if (result != 16)
return -EINVAL;
result = cbaf_send_host_info(cbaf);
if (result < 0)
return result;
result = cbaf_cdid_get(cbaf);
if (result < 0)
return result;
return size;
}
static ssize_t cbaf_wusb_host_name_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
return scnprintf(buf, PAGE_SIZE, "%s\n", cbaf->host_name);
}
static ssize_t cbaf_wusb_host_name_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t result;
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
result = sscanf(buf, "%63s", cbaf->host_name);
if (result != 1)
return -EINVAL;
return size;
}
static ssize_t cbaf_wusb_host_band_groups_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
return scnprintf(buf, PAGE_SIZE, "0x%04x\n", cbaf->host_band_groups);
}
static ssize_t cbaf_wusb_host_band_groups_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t result;
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
u16 band_groups = 0;
result = sscanf(buf, "%04hx", &band_groups);
if (result != 1)
return -EINVAL;
cbaf->host_band_groups = band_groups;
return size;
}
static ssize_t cbaf_wusb_cdid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
char pr_cdid[WUSB_CKHDID_STRSIZE];
ckhdid_printf(pr_cdid, sizeof(pr_cdid), &cbaf->cdid);
return scnprintf(buf, PAGE_SIZE, "%s\n", pr_cdid);
}
static ssize_t cbaf_wusb_cdid_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t result;
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
struct wusb_ckhdid cdid;
result = sscanf(buf,
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx",
&cdid.data[0] , &cdid.data[1],
&cdid.data[2] , &cdid.data[3],
&cdid.data[4] , &cdid.data[5],
&cdid.data[6] , &cdid.data[7],
&cdid.data[8] , &cdid.data[9],
&cdid.data[10], &cdid.data[11],
&cdid.data[12], &cdid.data[13],
&cdid.data[14], &cdid.data[15]);
if (result != 16)
return -EINVAL;
cbaf->cdid = cdid;
return size;
}
static ssize_t cbaf_wusb_device_band_groups_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
return scnprintf(buf, PAGE_SIZE, "0x%04x\n", cbaf->device_band_groups);
}
static ssize_t cbaf_wusb_device_name_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
return scnprintf(buf, PAGE_SIZE, "%s\n", cbaf->device_name);
}
static int cbaf_cc_upload(struct cbaf *cbaf)
{
int result;
struct device *dev = &cbaf->usb_iface->dev;
struct wusb_cbaf_cc_data *ccd;
char pr_cdid[WUSB_CKHDID_STRSIZE];
ccd = cbaf->buffer;
*ccd = cbaf_cc_data_defaults;
ccd->CHID = cbaf->chid;
ccd->CDID = cbaf->cdid;
ccd->CK = cbaf->ck;
ccd->BandGroups = cpu_to_le16(cbaf->host_band_groups);
dev_dbg(dev, "Trying to upload CC:\n");
ckhdid_printf(pr_cdid, sizeof(pr_cdid), &ccd->CHID);
dev_dbg(dev, " CHID %s\n", pr_cdid);
ckhdid_printf(pr_cdid, sizeof(pr_cdid), &ccd->CDID);
dev_dbg(dev, " CDID %s\n", pr_cdid);
dev_dbg(dev, " Bandgroups 0x%04x\n", cbaf->host_band_groups);
result = usb_control_msg(
cbaf->usb_dev, usb_sndctrlpipe(cbaf->usb_dev, 0),
CBAF_REQ_SET_ASSOCIATION_RESPONSE,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0x0201, cbaf->usb_iface->cur_altsetting->desc.bInterfaceNumber,
ccd, sizeof(*ccd), 1000 );
return result;
}
static ssize_t cbaf_wusb_ck_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t result;
struct usb_interface *iface = to_usb_interface(dev);
struct cbaf *cbaf = usb_get_intfdata(iface);
result = sscanf(buf,
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx "
"%02hhx %02hhx %02hhx %02hhx",
&cbaf->ck.data[0] , &cbaf->ck.data[1],
&cbaf->ck.data[2] , &cbaf->ck.data[3],
&cbaf->ck.data[4] , &cbaf->ck.data[5],
&cbaf->ck.data[6] , &cbaf->ck.data[7],
&cbaf->ck.data[8] , &cbaf->ck.data[9],
&cbaf->ck.data[10], &cbaf->ck.data[11],
&cbaf->ck.data[12], &cbaf->ck.data[13],
&cbaf->ck.data[14], &cbaf->ck.data[15]);
if (result != 16)
return -EINVAL;
result = cbaf_cc_upload(cbaf);
if (result < 0)
return result;
return size;
}
static int cbaf_probe(struct usb_interface *iface,
const struct usb_device_id *id)
{
struct cbaf *cbaf;
struct device *dev = &iface->dev;
int result = -ENOMEM;
cbaf = kzalloc(sizeof(*cbaf), GFP_KERNEL);
if (cbaf == NULL)
goto error_kzalloc;
cbaf->buffer = kmalloc(512, GFP_KERNEL);
if (cbaf->buffer == NULL)
goto error_kmalloc_buffer;
cbaf->buffer_size = 512;
cbaf->usb_dev = usb_get_dev(interface_to_usbdev(iface));
cbaf->usb_iface = usb_get_intf(iface);
result = cbaf_check(cbaf);
if (result < 0) {
dev_err(dev, "This device is not WUSB-CBAF compliant"
"and is not supported yet.\n");
goto error_check;
}
result = sysfs_create_group(&dev->kobj, &cbaf_dev_attr_group);
if (result < 0) {
dev_err(dev, "Can't register sysfs attr group: %d\n", result);
goto error_create_group;
}
usb_set_intfdata(iface, cbaf);
return 0;
error_create_group:
error_check:
kfree(cbaf->buffer);
error_kmalloc_buffer:
kfree(cbaf);
error_kzalloc:
return result;
}
static void cbaf_disconnect(struct usb_interface *iface)
{
struct cbaf *cbaf = usb_get_intfdata(iface);
struct device *dev = &iface->dev;
sysfs_remove_group(&dev->kobj, &cbaf_dev_attr_group);
usb_set_intfdata(iface, NULL);
usb_put_intf(iface);
kfree(cbaf->buffer);
kzfree(cbaf);
}
