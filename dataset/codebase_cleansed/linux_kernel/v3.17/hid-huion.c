static __u8 *huion_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct huion_drvdata *drvdata = hid_get_drvdata(hdev);
switch (hdev->product) {
case USB_DEVICE_ID_HUION_TABLET:
if (drvdata->rdesc != NULL) {
rdesc = drvdata->rdesc;
*rsize = drvdata->rsize;
}
break;
}
return rdesc;
}
static int huion_tablet_enable(struct hid_device *hdev)
{
int rc;
struct usb_device *usb_dev = hid_to_usb_dev(hdev);
struct huion_drvdata *drvdata = hid_get_drvdata(hdev);
__le16 *buf = NULL;
size_t len;
s32 params[HUION_PH_ID_NUM];
s32 resolution;
__u8 *p;
s32 v;
len = HUION_PRM_NUM * sizeof(*buf);
buf = kmalloc(len, GFP_KERNEL);
if (buf == NULL) {
hid_err(hdev, "failed to allocate parameter buffer\n");
rc = -ENOMEM;
goto cleanup;
}
rc = usb_control_msg(usb_dev, usb_rcvctrlpipe(usb_dev, 0),
USB_REQ_GET_DESCRIPTOR, USB_DIR_IN,
(USB_DT_STRING << 8) + 0x64,
0x0409, buf, len,
USB_CTRL_GET_TIMEOUT);
if (rc == -EPIPE) {
hid_err(hdev, "device parameters not found\n");
rc = -ENODEV;
goto cleanup;
} else if (rc < 0) {
hid_err(hdev, "failed to get device parameters: %d\n", rc);
rc = -ENODEV;
goto cleanup;
} else if (rc != len) {
hid_err(hdev, "invalid device parameters\n");
rc = -ENODEV;
goto cleanup;
}
params[HUION_PH_ID_X_LM] = le16_to_cpu(buf[HUION_PRM_X_LM]);
params[HUION_PH_ID_Y_LM] = le16_to_cpu(buf[HUION_PRM_Y_LM]);
params[HUION_PH_ID_PRESSURE_LM] =
le16_to_cpu(buf[HUION_PRM_PRESSURE_LM]);
resolution = le16_to_cpu(buf[HUION_PRM_RESOLUTION]);
if (resolution == 0) {
params[HUION_PH_ID_X_PM] = 0;
params[HUION_PH_ID_Y_PM] = 0;
} else {
params[HUION_PH_ID_X_PM] = params[HUION_PH_ID_X_LM] *
1000 / resolution;
params[HUION_PH_ID_Y_PM] = params[HUION_PH_ID_Y_LM] *
1000 / resolution;
}
drvdata->rdesc = devm_kmalloc(&hdev->dev,
sizeof(huion_tablet_rdesc_template),
GFP_KERNEL);
if (drvdata->rdesc == NULL) {
hid_err(hdev, "failed to allocate fixed rdesc\n");
rc = -ENOMEM;
goto cleanup;
}
drvdata->rsize = sizeof(huion_tablet_rdesc_template);
memcpy(drvdata->rdesc, huion_tablet_rdesc_template,
drvdata->rsize);
for (p = drvdata->rdesc;
p <= drvdata->rdesc + drvdata->rsize - 4;) {
if (p[0] == 0xFE && p[1] == 0xED && p[2] == 0x1D &&
p[3] < sizeof(params)) {
v = params[p[3]];
put_unaligned(cpu_to_le32(v), (s32 *)p);
p += 4;
} else {
p++;
}
}
rc = 0;
cleanup:
kfree(buf);
return rc;
}
static int huion_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int rc;
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct huion_drvdata *drvdata;
drvdata = devm_kzalloc(&hdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (drvdata == NULL) {
hid_err(hdev, "failed to allocate driver data\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, drvdata);
switch (id->product) {
case USB_DEVICE_ID_HUION_TABLET:
if (intf->cur_altsetting->desc.bInterfaceNumber == 0) {
rc = huion_tablet_enable(hdev);
if (rc) {
hid_err(hdev, "tablet enabling failed\n");
return rc;
}
}
break;
}
rc = hid_parse(hdev);
if (rc) {
hid_err(hdev, "parse failed\n");
return rc;
}
rc = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (rc) {
hid_err(hdev, "hw start failed\n");
return rc;
}
return 0;
}
static int huion_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
if (intf->cur_altsetting->desc.bInterfaceNumber == 0 &&
report->type == HID_INPUT_REPORT &&
report->id == 0x07 && size >= 2)
data[1] ^= 0x40;
return 0;
}
