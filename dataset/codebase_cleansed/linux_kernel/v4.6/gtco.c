static void parse_hid_report_descriptor(struct gtco *device, char * report,
int length)
{
struct device *ddev = &device->intf->dev;
int x, i = 0;
__u8 prefix;
__u8 size;
__u8 tag;
__u8 type;
__u8 data = 0;
__u16 data16 = 0;
__u32 data32 = 0;
int inputnum = 0;
__u32 usage = 0;
__u32 globalval[TAG_GLOB_MAX];
__u32 oldval[TAG_GLOB_MAX];
char maintype = 'x';
char globtype[12];
int indent = 0;
char indentstr[10] = "";
dev_dbg(ddev, "======>>>>>>PARSE<<<<<<======\n");
while (i < length) {
prefix = report[i];
i++;
size = PREF_SIZE(prefix);
switch (size) {
case 1:
data = report[i];
break;
case 2:
data16 = get_unaligned_le16(&report[i]);
break;
case 3:
size = 4;
data32 = get_unaligned_le32(&report[i]);
break;
}
i += size;
tag = PREF_TAG(prefix);
type = PREF_TYPE(prefix);
switch (type) {
case TYPE_MAIN:
strcpy(globtype, "");
switch (tag) {
case TAG_MAIN_INPUT:
maintype = 'I';
if (data == 2)
strcpy(globtype, "Variable");
else if (data == 3)
strcpy(globtype, "Var|Const");
dev_dbg(ddev, "::::: Saving Report: %d input #%d Max: 0x%X(%d) Min:0x%X(%d) of %d bits\n",
globalval[TAG_GLOB_REPORT_ID], inputnum,
globalval[TAG_GLOB_LOG_MAX], globalval[TAG_GLOB_LOG_MAX],
globalval[TAG_GLOB_LOG_MIN], globalval[TAG_GLOB_LOG_MIN],
globalval[TAG_GLOB_REPORT_SZ] * globalval[TAG_GLOB_REPORT_CNT]);
switch (inputnum) {
case 0:
dev_dbg(ddev, "GER: X Usage: 0x%x\n", usage);
if (device->max_X == 0) {
device->max_X = globalval[TAG_GLOB_LOG_MAX];
device->min_X = globalval[TAG_GLOB_LOG_MIN];
}
break;
case 1:
dev_dbg(ddev, "GER: Y Usage: 0x%x\n", usage);
if (device->max_Y == 0) {
device->max_Y = globalval[TAG_GLOB_LOG_MAX];
device->min_Y = globalval[TAG_GLOB_LOG_MIN];
}
break;
default:
if (usage == DIGITIZER_USAGE_TILT_X) {
if (device->maxtilt_X == 0) {
device->maxtilt_X = globalval[TAG_GLOB_LOG_MAX];
device->mintilt_X = globalval[TAG_GLOB_LOG_MIN];
}
}
if (usage == DIGITIZER_USAGE_TILT_Y) {
if (device->maxtilt_Y == 0) {
device->maxtilt_Y = globalval[TAG_GLOB_LOG_MAX];
device->mintilt_Y = globalval[TAG_GLOB_LOG_MIN];
}
}
if (usage == DIGITIZER_USAGE_TIP_PRESSURE) {
if (device->maxpressure == 0) {
device->maxpressure = globalval[TAG_GLOB_LOG_MAX];
device->minpressure = globalval[TAG_GLOB_LOG_MIN];
}
}
break;
}
inputnum++;
break;
case TAG_MAIN_OUTPUT:
maintype = 'O';
break;
case TAG_MAIN_FEATURE:
maintype = 'F';
break;
case TAG_MAIN_COL_START:
maintype = 'S';
if (data == 0) {
dev_dbg(ddev, "======>>>>>> Physical\n");
strcpy(globtype, "Physical");
} else
dev_dbg(ddev, "======>>>>>>\n");
indent++;
for (x = 0; x < indent; x++)
indentstr[x] = '-';
indentstr[x] = 0;
for (x = 0; x < TAG_GLOB_MAX; x++)
oldval[x] = globalval[x];
break;
case TAG_MAIN_COL_END:
dev_dbg(ddev, "<<<<<<======\n");
maintype = 'E';
indent--;
for (x = 0; x < indent; x++)
indentstr[x] = '-';
indentstr[x] = 0;
for (x = 0; x < TAG_GLOB_MAX; x++)
globalval[x] = oldval[x];
break;
}
switch (size) {
case 1:
dev_dbg(ddev, "%sMAINTAG:(%d) %c SIZE: %d Data: %s 0x%x\n",
indentstr, tag, maintype, size, globtype, data);
break;
case 2:
dev_dbg(ddev, "%sMAINTAG:(%d) %c SIZE: %d Data: %s 0x%x\n",
indentstr, tag, maintype, size, globtype, data16);
break;
case 4:
dev_dbg(ddev, "%sMAINTAG:(%d) %c SIZE: %d Data: %s 0x%x\n",
indentstr, tag, maintype, size, globtype, data32);
break;
}
break;
case TYPE_GLOBAL:
switch (tag) {
case TAG_GLOB_USAGE:
if (device->usage == 0)
device->usage = data;
strcpy(globtype, "USAGE");
break;
case TAG_GLOB_LOG_MIN:
strcpy(globtype, "LOG_MIN");
break;
case TAG_GLOB_LOG_MAX:
strcpy(globtype, "LOG_MAX");
break;
case TAG_GLOB_PHYS_MIN:
strcpy(globtype, "PHYS_MIN");
break;
case TAG_GLOB_PHYS_MAX:
strcpy(globtype, "PHYS_MAX");
break;
case TAG_GLOB_UNIT_EXP:
strcpy(globtype, "EXP");
break;
case TAG_GLOB_UNIT:
strcpy(globtype, "UNIT");
break;
case TAG_GLOB_REPORT_SZ:
strcpy(globtype, "REPORT_SZ");
break;
case TAG_GLOB_REPORT_ID:
strcpy(globtype, "REPORT_ID");
inputnum = 0;
break;
case TAG_GLOB_REPORT_CNT:
strcpy(globtype, "REPORT_CNT");
break;
case TAG_GLOB_PUSH:
strcpy(globtype, "PUSH");
break;
case TAG_GLOB_POP:
strcpy(globtype, "POP");
break;
}
if (tag < TAG_GLOB_MAX) {
switch (size) {
case 1:
dev_dbg(ddev, "%sGLOBALTAG:%s(%d) SIZE: %d Data: 0x%x\n",
indentstr, globtype, tag, size, data);
globalval[tag] = data;
break;
case 2:
dev_dbg(ddev, "%sGLOBALTAG:%s(%d) SIZE: %d Data: 0x%x\n",
indentstr, globtype, tag, size, data16);
globalval[tag] = data16;
break;
case 4:
dev_dbg(ddev, "%sGLOBALTAG:%s(%d) SIZE: %d Data: 0x%x\n",
indentstr, globtype, tag, size, data32);
globalval[tag] = data32;
break;
}
} else {
dev_dbg(ddev, "%sGLOBALTAG: ILLEGAL TAG:%d SIZE: %d\n",
indentstr, tag, size);
}
break;
case TYPE_LOCAL:
switch (tag) {
case TAG_GLOB_USAGE:
strcpy(globtype, "USAGE");
usage = data;
break;
case TAG_GLOB_LOG_MIN:
strcpy(globtype, "MIN");
break;
case TAG_GLOB_LOG_MAX:
strcpy(globtype, "MAX");
break;
default:
strcpy(globtype, "UNKNOWN");
break;
}
switch (size) {
case 1:
dev_dbg(ddev, "%sLOCALTAG:(%d) %s SIZE: %d Data: 0x%x\n",
indentstr, tag, globtype, size, data);
break;
case 2:
dev_dbg(ddev, "%sLOCALTAG:(%d) %s SIZE: %d Data: 0x%x\n",
indentstr, tag, globtype, size, data16);
break;
case 4:
dev_dbg(ddev, "%sLOCALTAG:(%d) %s SIZE: %d Data: 0x%x\n",
indentstr, tag, globtype, size, data32);
break;
}
break;
}
}
}
static int gtco_input_open(struct input_dev *inputdev)
{
struct gtco *device = input_get_drvdata(inputdev);
device->urbinfo->dev = device->usbdev;
if (usb_submit_urb(device->urbinfo, GFP_KERNEL))
return -EIO;
return 0;
}
static void gtco_input_close(struct input_dev *inputdev)
{
struct gtco *device = input_get_drvdata(inputdev);
usb_kill_urb(device->urbinfo);
}
static void gtco_setup_caps(struct input_dev *inputdev)
{
struct gtco *device = input_get_drvdata(inputdev);
inputdev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS) |
BIT_MASK(EV_MSC);
inputdev->mscbit[0] = BIT_MASK(MSC_SCAN) | BIT_MASK(MSC_SERIAL) |
BIT_MASK(MSC_RAW);
input_set_abs_params(inputdev, ABS_X, device->min_X, device->max_X,
0, 0);
input_set_abs_params(inputdev, ABS_Y, device->min_Y, device->max_Y,
0, 0);
input_set_abs_params(inputdev, ABS_DISTANCE, 0, 1, 0, 0);
input_set_abs_params(inputdev, ABS_TILT_X, device->mintilt_X,
device->maxtilt_X, 0, 0);
input_set_abs_params(inputdev, ABS_TILT_Y, device->mintilt_Y,
device->maxtilt_Y, 0, 0);
input_set_abs_params(inputdev, ABS_PRESSURE, device->minpressure,
device->maxpressure, 0, 0);
input_set_abs_params(inputdev, ABS_MISC, 0, 0xFF, 0, 0);
}
static void gtco_urb_callback(struct urb *urbinfo)
{
struct gtco *device = urbinfo->context;
struct input_dev *inputdev;
int rc;
u32 val = 0;
char le_buffer[2];
inputdev = device->inputdevice;
if (urbinfo->status == -ECONNRESET ||
urbinfo->status == -ENOENT ||
urbinfo->status == -ESHUTDOWN) {
return;
}
if (urbinfo->status != 0) {
goto resubmit;
}
if (inputdev->id.product == PID_1000 ||
inputdev->id.product == PID_1001 ||
inputdev->id.product == PID_1002) {
switch (device->buffer[0]) {
case 5:
val = ((u16)(device->buffer[8]) << 1);
val |= (u16)(device->buffer[7] >> 7);
input_report_abs(inputdev, ABS_PRESSURE,
device->buffer[8]);
device->buffer[7] = (u8)((device->buffer[7]) & 0x7F);
case 4:
input_report_abs(inputdev, ABS_TILT_X,
sign_extend32(device->buffer[6], 6));
input_report_abs(inputdev, ABS_TILT_Y,
sign_extend32(device->buffer[7], 6));
case 2:
case 3:
val = (device->buffer[5]) & MASK_BUTTON;
input_event(inputdev, EV_MSC, MSC_SERIAL, val);
case 1:
val = get_unaligned_le16(&device->buffer[1]);
input_report_abs(inputdev, ABS_X, val);
val = get_unaligned_le16(&device->buffer[3]);
input_report_abs(inputdev, ABS_Y, val);
val = device->buffer[5] & MASK_INRANGE ? 1 : 0;
input_report_abs(inputdev, ABS_DISTANCE, val);
if (device->buffer[0] == 1) {
val = device->buffer[5] & MASK_BUTTON;
dev_dbg(&device->intf->dev,
"======>>>>>>REPORT 1: val 0x%X(%d)\n",
val, val);
input_event(inputdev, EV_MSC, MSC_SERIAL, val);
}
break;
case 7:
input_event(inputdev, EV_MSC, MSC_SCAN,
device->buffer[1]);
break;
}
}
if (inputdev->id.product == PID_400 ||
inputdev->id.product == PID_401) {
if (device->buffer[0] == 2) {
input_event(inputdev, EV_MSC, MSC_SCAN, device->buffer[1]);
}
if (device->buffer[0] == 1) {
char buttonbyte;
if (device->max_X > 0x10000) {
val = (u16)(((u16)(device->buffer[2] << 8)) | (u8)device->buffer[1]);
val |= (u32)(((u8)device->buffer[3] & 0x1) << 16);
input_report_abs(inputdev, ABS_X, val);
le_buffer[0] = (u8)((u8)(device->buffer[3]) >> 1);
le_buffer[0] |= (u8)((device->buffer[3] & 0x1) << 7);
le_buffer[1] = (u8)(device->buffer[4] >> 1);
le_buffer[1] |= (u8)((device->buffer[5] & 0x1) << 7);
val = get_unaligned_le16(le_buffer);
input_report_abs(inputdev, ABS_Y, val);
buttonbyte = device->buffer[5] >> 1;
} else {
val = get_unaligned_le16(&device->buffer[1]);
input_report_abs(inputdev, ABS_X, val);
val = get_unaligned_le16(&device->buffer[3]);
input_report_abs(inputdev, ABS_Y, val);
buttonbyte = device->buffer[5];
}
val = buttonbyte & MASK_INRANGE ? 1 : 0;
input_report_abs(inputdev, ABS_DISTANCE, val);
val = buttonbyte & 0x0F;
#ifdef USE_BUTTONS
for (i = 0; i < 5; i++)
input_report_key(inputdev, BTN_DIGI + i, val & (1 << i));
#else
input_event(inputdev, EV_MSC, MSC_SERIAL, val);
#endif
input_report_abs(inputdev, ABS_MISC, device->buffer[6]);
}
}
input_event(inputdev, EV_MSC, MSC_RAW, device->buffer[0]);
input_sync(inputdev);
resubmit:
rc = usb_submit_urb(urbinfo, GFP_ATOMIC);
if (rc != 0)
dev_err(&device->intf->dev,
"usb_submit_urb failed rc=0x%x\n", rc);
}
static int gtco_probe(struct usb_interface *usbinterface,
const struct usb_device_id *id)
{
struct gtco *gtco;
struct input_dev *input_dev;
struct hid_descriptor *hid_desc;
char *report;
int result = 0, retry;
int error;
struct usb_endpoint_descriptor *endpoint;
gtco = kzalloc(sizeof(struct gtco), GFP_KERNEL);
input_dev = input_allocate_device();
if (!gtco || !input_dev) {
dev_err(&usbinterface->dev, "No more memory\n");
error = -ENOMEM;
goto err_free_devs;
}
gtco->inputdevice = input_dev;
gtco->usbdev = interface_to_usbdev(usbinterface);
gtco->intf = usbinterface;
gtco->buffer = usb_alloc_coherent(gtco->usbdev, REPORT_MAX_SIZE,
GFP_KERNEL, &gtco->buf_dma);
if (!gtco->buffer) {
dev_err(&usbinterface->dev, "No more memory for us buffers\n");
error = -ENOMEM;
goto err_free_devs;
}
gtco->urbinfo = usb_alloc_urb(0, GFP_KERNEL);
if (!gtco->urbinfo) {
dev_err(&usbinterface->dev, "Failed to allocate URB\n");
error = -ENOMEM;
goto err_free_buf;
}
if (usbinterface->altsetting[0].desc.bNumEndpoints < 1) {
dev_err(&usbinterface->dev,
"Invalid number of endpoints\n");
error = -EINVAL;
goto err_free_urb;
}
endpoint = &usbinterface->altsetting[0].endpoint[0].desc;
dev_dbg(&usbinterface->dev, "gtco # interfaces: %d\n", usbinterface->num_altsetting);
dev_dbg(&usbinterface->dev, "num endpoints: %d\n", usbinterface->cur_altsetting->desc.bNumEndpoints);
dev_dbg(&usbinterface->dev, "interface class: %d\n", usbinterface->cur_altsetting->desc.bInterfaceClass);
dev_dbg(&usbinterface->dev, "endpoint: attribute:0x%x type:0x%x\n", endpoint->bmAttributes, endpoint->bDescriptorType);
if (usb_endpoint_xfer_int(endpoint))
dev_dbg(&usbinterface->dev, "endpoint: we have interrupt endpoint\n");
dev_dbg(&usbinterface->dev, "endpoint extra len:%d\n", usbinterface->altsetting[0].extralen);
if (usb_get_extra_descriptor(usbinterface->cur_altsetting,
HID_DEVICE_TYPE, &hid_desc) != 0) {
dev_err(&usbinterface->dev,
"Can't retrieve exta USB descriptor to get hid report descriptor length\n");
error = -EIO;
goto err_free_urb;
}
dev_dbg(&usbinterface->dev,
"Extra descriptor success: type:%d len:%d\n",
hid_desc->bDescriptorType, hid_desc->wDescriptorLength);
report = kzalloc(le16_to_cpu(hid_desc->wDescriptorLength), GFP_KERNEL);
if (!report) {
dev_err(&usbinterface->dev, "No more memory for report\n");
error = -ENOMEM;
goto err_free_urb;
}
for (retry = 0; retry < 3; retry++) {
result = usb_control_msg(gtco->usbdev,
usb_rcvctrlpipe(gtco->usbdev, 0),
USB_REQ_GET_DESCRIPTOR,
USB_RECIP_INTERFACE | USB_DIR_IN,
REPORT_DEVICE_TYPE << 8,
0,
report,
le16_to_cpu(hid_desc->wDescriptorLength),
5000);
dev_dbg(&usbinterface->dev, "usb_control_msg result: %d\n", result);
if (result == le16_to_cpu(hid_desc->wDescriptorLength)) {
parse_hid_report_descriptor(gtco, report, result);
break;
}
}
kfree(report);
if (result != le16_to_cpu(hid_desc->wDescriptorLength)) {
dev_err(&usbinterface->dev,
"Failed to get HID Report Descriptor of size: %d\n",
hid_desc->wDescriptorLength);
error = -EIO;
goto err_free_urb;
}
usb_make_path(gtco->usbdev, gtco->usbpath, sizeof(gtco->usbpath));
strlcat(gtco->usbpath, "/input0", sizeof(gtco->usbpath));
input_dev->open = gtco_input_open;
input_dev->close = gtco_input_close;
input_dev->name = "GTCO_CalComp";
input_dev->phys = gtco->usbpath;
input_set_drvdata(input_dev, gtco);
gtco_setup_caps(input_dev);
usb_to_input_id(gtco->usbdev, &input_dev->id);
input_dev->dev.parent = &usbinterface->dev;
endpoint = &usbinterface->altsetting[0].endpoint[0].desc;
usb_fill_int_urb(gtco->urbinfo,
gtco->usbdev,
usb_rcvintpipe(gtco->usbdev,
endpoint->bEndpointAddress),
gtco->buffer,
REPORT_MAX_SIZE,
gtco_urb_callback,
gtco,
endpoint->bInterval);
gtco->urbinfo->transfer_dma = gtco->buf_dma;
gtco->urbinfo->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_set_intfdata(usbinterface, gtco);
error = input_register_device(input_dev);
if (error)
goto err_free_urb;
return 0;
err_free_urb:
usb_free_urb(gtco->urbinfo);
err_free_buf:
usb_free_coherent(gtco->usbdev, REPORT_MAX_SIZE,
gtco->buffer, gtco->buf_dma);
err_free_devs:
input_free_device(input_dev);
kfree(gtco);
return error;
}
static void gtco_disconnect(struct usb_interface *interface)
{
struct gtco *gtco = usb_get_intfdata(interface);
if (gtco) {
input_unregister_device(gtco->inputdevice);
usb_kill_urb(gtco->urbinfo);
usb_free_urb(gtco->urbinfo);
usb_free_coherent(gtco->usbdev, REPORT_MAX_SIZE,
gtco->buffer, gtco->buf_dma);
kfree(gtco);
}
dev_info(&interface->dev, "gtco driver disconnected\n");
}
