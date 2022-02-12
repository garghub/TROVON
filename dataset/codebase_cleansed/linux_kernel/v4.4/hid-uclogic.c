static __u8 *uclogic_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct usb_interface *iface = to_usb_interface(hdev->dev.parent);
__u8 iface_num = iface->cur_altsetting->desc.bInterfaceNumber;
struct uclogic_drvdata *drvdata = hid_get_drvdata(hdev);
switch (hdev->product) {
case USB_DEVICE_ID_UCLOGIC_TABLET_PF1209:
if (*rsize == PF1209_RDESC_ORIG_SIZE) {
rdesc = pf1209_rdesc_fixed;
*rsize = sizeof(pf1209_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP4030U:
if (*rsize == WPXXXXU_RDESC_ORIG_SIZE) {
rdesc = wp4030u_rdesc_fixed;
*rsize = sizeof(wp4030u_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP5540U:
if (*rsize == WPXXXXU_RDESC_ORIG_SIZE) {
rdesc = wp5540u_rdesc_fixed;
*rsize = sizeof(wp5540u_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP8060U:
if (*rsize == WPXXXXU_RDESC_ORIG_SIZE) {
rdesc = wp8060u_rdesc_fixed;
*rsize = sizeof(wp8060u_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP1062:
if (*rsize == WP1062_RDESC_ORIG_SIZE) {
rdesc = wp1062_rdesc_fixed;
*rsize = sizeof(wp1062_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_WIRELESS_TABLET_TWHL850:
switch (iface_num) {
case 0:
if (*rsize == TWHL850_RDESC_ORIG_SIZE0) {
rdesc = twhl850_rdesc_fixed0;
*rsize = sizeof(twhl850_rdesc_fixed0);
}
break;
case 1:
if (*rsize == TWHL850_RDESC_ORIG_SIZE1) {
rdesc = twhl850_rdesc_fixed1;
*rsize = sizeof(twhl850_rdesc_fixed1);
}
break;
case 2:
if (*rsize == TWHL850_RDESC_ORIG_SIZE2) {
rdesc = twhl850_rdesc_fixed2;
*rsize = sizeof(twhl850_rdesc_fixed2);
}
break;
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_TWHA60:
switch (iface_num) {
case 0:
if (*rsize == TWHA60_RDESC_ORIG_SIZE0) {
rdesc = twha60_rdesc_fixed0;
*rsize = sizeof(twha60_rdesc_fixed0);
}
break;
case 1:
if (*rsize == TWHA60_RDESC_ORIG_SIZE1) {
rdesc = twha60_rdesc_fixed1;
*rsize = sizeof(twha60_rdesc_fixed1);
}
break;
}
break;
default:
if (drvdata->rdesc != NULL) {
rdesc = drvdata->rdesc;
*rsize = drvdata->rsize;
}
}
return rdesc;
}
static int uclogic_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct uclogic_drvdata *drvdata = hid_get_drvdata(hdev);
if ((drvdata->ignore_pen_usage) &&
(field->application == HID_DG_PEN))
return -1;
return 0;
}
static int uclogic_input_configured(struct hid_device *hdev,
struct hid_input *hi)
{
char *name;
const char *suffix = NULL;
struct hid_field *field;
size_t len;
if (!hi->report)
return 0;
field = hi->report->field[0];
switch (field->application) {
case HID_GD_KEYBOARD:
suffix = "Keyboard";
break;
case HID_GD_MOUSE:
suffix = "Mouse";
break;
case HID_GD_KEYPAD:
suffix = "Pad";
break;
case HID_DG_PEN:
suffix = "Pen";
break;
case HID_CP_CONSUMER_CONTROL:
suffix = "Consumer Control";
break;
case HID_GD_SYSTEM_CONTROL:
suffix = "System Control";
break;
}
if (suffix) {
len = strlen(hdev->name) + 2 + strlen(suffix);
name = devm_kzalloc(&hi->input->dev, len, GFP_KERNEL);
if (name) {
snprintf(name, len, "%s %s", hdev->name, suffix);
hi->input->name = name;
}
}
return 0;
}
static int uclogic_tablet_enable(struct hid_device *hdev)
{
int rc;
struct usb_device *usb_dev = hid_to_usb_dev(hdev);
struct uclogic_drvdata *drvdata = hid_get_drvdata(hdev);
__le16 *buf = NULL;
size_t len;
s32 params[UCLOGIC_PH_ID_NUM];
s32 resolution;
__u8 *p;
s32 v;
len = UCLOGIC_PRM_NUM * sizeof(*buf);
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
params[UCLOGIC_PH_ID_X_LM] = le16_to_cpu(buf[UCLOGIC_PRM_X_LM]);
params[UCLOGIC_PH_ID_Y_LM] = le16_to_cpu(buf[UCLOGIC_PRM_Y_LM]);
params[UCLOGIC_PH_ID_PRESSURE_LM] =
le16_to_cpu(buf[UCLOGIC_PRM_PRESSURE_LM]);
resolution = le16_to_cpu(buf[UCLOGIC_PRM_RESOLUTION]);
if (resolution == 0) {
params[UCLOGIC_PH_ID_X_PM] = 0;
params[UCLOGIC_PH_ID_Y_PM] = 0;
} else {
params[UCLOGIC_PH_ID_X_PM] = params[UCLOGIC_PH_ID_X_LM] *
1000 / resolution;
params[UCLOGIC_PH_ID_Y_PM] = params[UCLOGIC_PH_ID_Y_LM] *
1000 / resolution;
}
drvdata->rdesc = devm_kzalloc(&hdev->dev,
sizeof(uclogic_tablet_rdesc_template),
GFP_KERNEL);
if (drvdata->rdesc == NULL) {
hid_err(hdev, "failed to allocate fixed rdesc\n");
rc = -ENOMEM;
goto cleanup;
}
drvdata->rsize = sizeof(uclogic_tablet_rdesc_template);
memcpy(drvdata->rdesc, uclogic_tablet_rdesc_template,
drvdata->rsize);
for (p = drvdata->rdesc;
p <= drvdata->rdesc + drvdata->rsize - 4;) {
if (p[0] == 0xFE && p[1] == 0xED && p[2] == 0x1D &&
p[3] < ARRAY_SIZE(params)) {
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
static int uclogic_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int rc;
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct uclogic_drvdata *drvdata;
hdev->quirks |= HID_QUIRK_MULTI_INPUT;
hdev->quirks |= HID_QUIRK_NO_EMPTY_INPUT;
drvdata = devm_kzalloc(&hdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (drvdata == NULL)
return -ENOMEM;
hid_set_drvdata(hdev, drvdata);
switch (id->product) {
case USB_DEVICE_ID_HUION_TABLET:
if (intf->cur_altsetting->desc.bInterfaceNumber == 0) {
rc = uclogic_tablet_enable(hdev);
if (rc) {
hid_err(hdev, "tablet enabling failed\n");
return rc;
}
drvdata->invert_pen_inrange = true;
} else {
drvdata->ignore_pen_usage = true;
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
static int uclogic_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
struct uclogic_drvdata *drvdata = hid_get_drvdata(hdev);
if ((drvdata->invert_pen_inrange) &&
(report->type == HID_INPUT_REPORT) &&
(report->id == UCLOGIC_PEN_REPORT_ID) &&
(size >= 2))
data[1] ^= 0x40;
return 0;
}
