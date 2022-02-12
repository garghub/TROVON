static void logi_dj_recv_destroy_djhid_device(struct dj_receiver_dev *djrcv_dev,
struct dj_report *dj_report)
{
struct dj_device *dj_dev;
unsigned long flags;
spin_lock_irqsave(&djrcv_dev->lock, flags);
dj_dev = djrcv_dev->paired_dj_devices[dj_report->device_index];
djrcv_dev->paired_dj_devices[dj_report->device_index] = NULL;
spin_unlock_irqrestore(&djrcv_dev->lock, flags);
if (dj_dev != NULL) {
hid_destroy_device(dj_dev->hdev);
kfree(dj_dev);
} else {
dev_err(&djrcv_dev->hdev->dev, "%s: can't destroy a NULL device\n",
__func__);
}
}
static void logi_dj_recv_add_djhid_device(struct dj_receiver_dev *djrcv_dev,
struct dj_report *dj_report)
{
struct hid_device *djrcv_hdev = djrcv_dev->hdev;
struct usb_interface *intf = to_usb_interface(djrcv_hdev->dev.parent);
struct usb_device *usbdev = interface_to_usbdev(intf);
struct hid_device *dj_hiddev;
struct dj_device *dj_dev;
unsigned char tmpstr[3];
if (dj_report->report_params[DEVICE_PAIRED_PARAM_SPFUNCTION] &
SPFUNCTION_DEVICE_LIST_EMPTY) {
dbg_hid("%s: device list is empty\n", __func__);
djrcv_dev->querying_devices = false;
return;
}
if (djrcv_dev->paired_dj_devices[dj_report->device_index]) {
dbg_hid("%s: device is already known\n", __func__);
return;
}
dj_hiddev = hid_allocate_device();
if (IS_ERR(dj_hiddev)) {
dev_err(&djrcv_hdev->dev, "%s: hid_allocate_device failed\n",
__func__);
return;
}
dj_hiddev->ll_driver = &logi_dj_ll_driver;
dj_hiddev->dev.parent = &djrcv_hdev->dev;
dj_hiddev->bus = BUS_USB;
dj_hiddev->vendor = le16_to_cpu(usbdev->descriptor.idVendor);
dj_hiddev->product =
(dj_report->report_params[DEVICE_PAIRED_PARAM_EQUAD_ID_MSB]
<< 8) |
dj_report->report_params[DEVICE_PAIRED_PARAM_EQUAD_ID_LSB];
snprintf(dj_hiddev->name, sizeof(dj_hiddev->name),
"Logitech Unifying Device. Wireless PID:%04x",
dj_hiddev->product);
dj_hiddev->group = HID_GROUP_LOGITECH_DJ_DEVICE;
usb_make_path(usbdev, dj_hiddev->phys, sizeof(dj_hiddev->phys));
snprintf(tmpstr, sizeof(tmpstr), ":%d", dj_report->device_index);
strlcat(dj_hiddev->phys, tmpstr, sizeof(dj_hiddev->phys));
dj_dev = kzalloc(sizeof(struct dj_device), GFP_KERNEL);
if (!dj_dev) {
dev_err(&djrcv_hdev->dev, "%s: failed allocating dj_device\n",
__func__);
goto dj_device_allocate_fail;
}
dj_dev->reports_supported = get_unaligned_le32(
dj_report->report_params + DEVICE_PAIRED_RF_REPORT_TYPE);
dj_dev->hdev = dj_hiddev;
dj_dev->dj_receiver_dev = djrcv_dev;
dj_dev->device_index = dj_report->device_index;
dj_hiddev->driver_data = dj_dev;
djrcv_dev->paired_dj_devices[dj_report->device_index] = dj_dev;
if (hid_add_device(dj_hiddev)) {
dev_err(&djrcv_hdev->dev, "%s: failed adding dj_device\n",
__func__);
goto hid_add_device_fail;
}
return;
hid_add_device_fail:
djrcv_dev->paired_dj_devices[dj_report->device_index] = NULL;
kfree(dj_dev);
dj_device_allocate_fail:
hid_destroy_device(dj_hiddev);
}
static void delayedwork_callback(struct work_struct *work)
{
struct dj_receiver_dev *djrcv_dev =
container_of(work, struct dj_receiver_dev, work);
struct dj_report dj_report;
unsigned long flags;
int count;
int retval;
dbg_hid("%s\n", __func__);
spin_lock_irqsave(&djrcv_dev->lock, flags);
count = kfifo_out(&djrcv_dev->notif_fifo, &dj_report,
sizeof(struct dj_report));
if (count != sizeof(struct dj_report)) {
dev_err(&djrcv_dev->hdev->dev, "%s: workitem triggered without "
"notifications available\n", __func__);
spin_unlock_irqrestore(&djrcv_dev->lock, flags);
return;
}
if (!kfifo_is_empty(&djrcv_dev->notif_fifo)) {
if (schedule_work(&djrcv_dev->work) == 0) {
dbg_hid("%s: did not schedule the work item, was "
"already queued\n", __func__);
}
}
spin_unlock_irqrestore(&djrcv_dev->lock, flags);
switch (dj_report.report_type) {
case REPORT_TYPE_NOTIF_DEVICE_PAIRED:
logi_dj_recv_add_djhid_device(djrcv_dev, &dj_report);
break;
case REPORT_TYPE_NOTIF_DEVICE_UNPAIRED:
logi_dj_recv_destroy_djhid_device(djrcv_dev, &dj_report);
break;
default:
if (!djrcv_dev->paired_dj_devices[dj_report.device_index]) {
retval = logi_dj_recv_query_paired_devices(djrcv_dev);
if (!retval) {
break;
}
dev_err(&djrcv_dev->hdev->dev,
"%s:logi_dj_recv_query_paired_devices "
"error:%d\n", __func__, retval);
}
dbg_hid("%s: unexpected report type\n", __func__);
}
}
static void logi_dj_recv_queue_notification(struct dj_receiver_dev *djrcv_dev,
struct dj_report *dj_report)
{
kfifo_in(&djrcv_dev->notif_fifo, dj_report, sizeof(struct dj_report));
if (schedule_work(&djrcv_dev->work) == 0) {
dbg_hid("%s: did not schedule the work item, was already "
"queued\n", __func__);
}
}
static void logi_dj_recv_forward_null_report(struct dj_receiver_dev *djrcv_dev,
struct dj_report *dj_report)
{
unsigned int i;
u8 reportbuffer[MAX_REPORT_SIZE];
struct dj_device *djdev;
djdev = djrcv_dev->paired_dj_devices[dj_report->device_index];
memset(reportbuffer, 0, sizeof(reportbuffer));
for (i = 0; i < NUMBER_OF_HID_REPORTS; i++) {
if (djdev->reports_supported & (1 << i)) {
reportbuffer[0] = i;
if (hid_input_report(djdev->hdev,
HID_INPUT_REPORT,
reportbuffer,
hid_reportid_size_map[i], 1)) {
dbg_hid("hid_input_report error sending null "
"report\n");
}
}
}
}
static void logi_dj_recv_forward_report(struct dj_receiver_dev *djrcv_dev,
struct dj_report *dj_report)
{
struct dj_device *dj_device;
dj_device = djrcv_dev->paired_dj_devices[dj_report->device_index];
if ((dj_report->report_type > ARRAY_SIZE(hid_reportid_size_map) - 1) ||
(hid_reportid_size_map[dj_report->report_type] == 0)) {
dbg_hid("invalid report type:%x\n", dj_report->report_type);
return;
}
if (hid_input_report(dj_device->hdev,
HID_INPUT_REPORT, &dj_report->report_type,
hid_reportid_size_map[dj_report->report_type], 1)) {
dbg_hid("hid_input_report error\n");
}
}
static void logi_dj_recv_forward_hidpp(struct dj_device *dj_dev, u8 *data,
int size)
{
if (hid_input_report(dj_dev->hdev, HID_INPUT_REPORT, data, size, 1))
dbg_hid("hid_input_report error\n");
}
static int logi_dj_recv_send_report(struct dj_receiver_dev *djrcv_dev,
struct dj_report *dj_report)
{
struct hid_device *hdev = djrcv_dev->hdev;
struct hid_report *report;
struct hid_report_enum *output_report_enum;
u8 *data = (u8 *)(&dj_report->device_index);
unsigned int i;
output_report_enum = &hdev->report_enum[HID_OUTPUT_REPORT];
report = output_report_enum->report_id_hash[REPORT_ID_DJ_SHORT];
if (!report) {
dev_err(&hdev->dev, "%s: unable to find dj report\n", __func__);
return -ENODEV;
}
for (i = 0; i < DJREPORT_SHORT_LENGTH - 1; i++)
report->field[0]->value[i] = data[i];
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
return 0;
}
static int logi_dj_recv_query_paired_devices(struct dj_receiver_dev *djrcv_dev)
{
struct dj_report *dj_report;
int retval;
if (djrcv_dev->querying_devices)
return 0;
dj_report = kzalloc(sizeof(struct dj_report), GFP_KERNEL);
if (!dj_report)
return -ENOMEM;
dj_report->report_id = REPORT_ID_DJ_SHORT;
dj_report->device_index = 0xFF;
dj_report->report_type = REPORT_TYPE_CMD_GET_PAIRED_DEVICES;
retval = logi_dj_recv_send_report(djrcv_dev, dj_report);
kfree(dj_report);
return retval;
}
static int logi_dj_recv_switch_to_dj_mode(struct dj_receiver_dev *djrcv_dev,
unsigned timeout)
{
struct hid_device *hdev = djrcv_dev->hdev;
struct dj_report *dj_report;
u8 *buf;
int retval;
dj_report = kzalloc(sizeof(struct dj_report), GFP_KERNEL);
if (!dj_report)
return -ENOMEM;
dj_report->report_id = REPORT_ID_DJ_SHORT;
dj_report->device_index = 0xFF;
dj_report->report_type = REPORT_TYPE_CMD_SWITCH;
dj_report->report_params[CMD_SWITCH_PARAM_DEVBITFIELD] = 0x3F;
dj_report->report_params[CMD_SWITCH_PARAM_TIMEOUT_SECONDS] = (u8)timeout;
retval = logi_dj_recv_send_report(djrcv_dev, dj_report);
msleep(50);
buf = (u8 *)dj_report;
memset(buf, 0, HIDPP_REPORT_SHORT_LENGTH);
buf[0] = REPORT_ID_HIDPP_SHORT;
buf[1] = 0xFF;
buf[2] = 0x80;
buf[3] = 0x00;
buf[4] = 0x00;
buf[5] = 0x09;
buf[6] = 0x00;
hid_hw_raw_request(hdev, REPORT_ID_HIDPP_SHORT, buf,
HIDPP_REPORT_SHORT_LENGTH, HID_OUTPUT_REPORT,
HID_REQ_SET_REPORT);
kfree(dj_report);
return retval;
}
static int logi_dj_ll_open(struct hid_device *hid)
{
dbg_hid("%s:%s\n", __func__, hid->phys);
return 0;
}
static void logi_dj_ll_close(struct hid_device *hid)
{
dbg_hid("%s:%s\n", __func__, hid->phys);
}
static int logi_dj_ll_raw_request(struct hid_device *hid,
unsigned char reportnum, __u8 *buf,
size_t count, unsigned char report_type,
int reqtype)
{
struct dj_device *djdev = hid->driver_data;
struct dj_receiver_dev *djrcv_dev = djdev->dj_receiver_dev;
u8 *out_buf;
int ret;
if ((buf[0] == REPORT_ID_HIDPP_SHORT) ||
(buf[0] == REPORT_ID_HIDPP_LONG)) {
if (count < 2)
return -EINVAL;
if (count == 7 && !memcmp(buf, unifying_name_query,
sizeof(unifying_name_query)))
buf[4] |= djdev->device_index - 1;
else
buf[1] = djdev->device_index;
return hid_hw_raw_request(djrcv_dev->hdev, reportnum, buf,
count, report_type, reqtype);
}
if (buf[0] != REPORT_TYPE_LEDS)
return -EINVAL;
out_buf = kzalloc(DJREPORT_SHORT_LENGTH, GFP_ATOMIC);
if (!out_buf)
return -ENOMEM;
if (count > DJREPORT_SHORT_LENGTH - 2)
count = DJREPORT_SHORT_LENGTH - 2;
out_buf[0] = REPORT_ID_DJ_SHORT;
out_buf[1] = djdev->device_index;
memcpy(out_buf + 2, buf, count);
ret = hid_hw_raw_request(djrcv_dev->hdev, out_buf[0], out_buf,
DJREPORT_SHORT_LENGTH, report_type, reqtype);
kfree(out_buf);
return ret;
}
static void rdcat(char *rdesc, unsigned int *rsize, const char *data, unsigned int size)
{
memcpy(rdesc + *rsize, data, size);
*rsize += size;
}
static int logi_dj_ll_parse(struct hid_device *hid)
{
struct dj_device *djdev = hid->driver_data;
unsigned int rsize = 0;
char *rdesc;
int retval;
dbg_hid("%s\n", __func__);
djdev->hdev->version = 0x0111;
djdev->hdev->country = 0x00;
rdesc = kmalloc(MAX_RDESC_SIZE, GFP_KERNEL);
if (!rdesc)
return -ENOMEM;
if (djdev->reports_supported & STD_KEYBOARD) {
dbg_hid("%s: sending a kbd descriptor, reports_supported: %x\n",
__func__, djdev->reports_supported);
rdcat(rdesc, &rsize, kbd_descriptor, sizeof(kbd_descriptor));
}
if (djdev->reports_supported & STD_MOUSE) {
dbg_hid("%s: sending a mouse descriptor, reports_supported: "
"%x\n", __func__, djdev->reports_supported);
rdcat(rdesc, &rsize, mse_descriptor, sizeof(mse_descriptor));
}
if (djdev->reports_supported & MULTIMEDIA) {
dbg_hid("%s: sending a multimedia report descriptor: %x\n",
__func__, djdev->reports_supported);
rdcat(rdesc, &rsize, consumer_descriptor, sizeof(consumer_descriptor));
}
if (djdev->reports_supported & POWER_KEYS) {
dbg_hid("%s: sending a power keys report descriptor: %x\n",
__func__, djdev->reports_supported);
rdcat(rdesc, &rsize, syscontrol_descriptor, sizeof(syscontrol_descriptor));
}
if (djdev->reports_supported & MEDIA_CENTER) {
dbg_hid("%s: sending a media center report descriptor: %x\n",
__func__, djdev->reports_supported);
rdcat(rdesc, &rsize, media_descriptor, sizeof(media_descriptor));
}
if (djdev->reports_supported & KBD_LEDS) {
dbg_hid("%s: need to send kbd leds report descriptor: %x\n",
__func__, djdev->reports_supported);
}
rdcat(rdesc, &rsize, hidpp_descriptor, sizeof(hidpp_descriptor));
retval = hid_parse_report(hid, rdesc, rsize);
kfree(rdesc);
return retval;
}
static int logi_dj_ll_start(struct hid_device *hid)
{
dbg_hid("%s\n", __func__);
return 0;
}
static void logi_dj_ll_stop(struct hid_device *hid)
{
dbg_hid("%s\n", __func__);
}
static int logi_dj_dj_event(struct hid_device *hdev,
struct hid_report *report, u8 *data,
int size)
{
struct dj_receiver_dev *djrcv_dev = hid_get_drvdata(hdev);
struct dj_report *dj_report = (struct dj_report *) data;
unsigned long flags;
if ((dj_report->device_index < DJ_DEVICE_INDEX_MIN) ||
(dj_report->device_index > DJ_DEVICE_INDEX_MAX)) {
if (dj_report->device_index != DJ_RECEIVER_INDEX)
dev_err(&hdev->dev, "%s: invalid device index:%d\n",
__func__, dj_report->device_index);
return false;
}
spin_lock_irqsave(&djrcv_dev->lock, flags);
if (!djrcv_dev->paired_dj_devices[dj_report->device_index]) {
logi_dj_recv_queue_notification(djrcv_dev, dj_report);
goto out;
}
switch (dj_report->report_type) {
case REPORT_TYPE_NOTIF_DEVICE_PAIRED:
break;
case REPORT_TYPE_NOTIF_DEVICE_UNPAIRED:
logi_dj_recv_queue_notification(djrcv_dev, dj_report);
break;
case REPORT_TYPE_NOTIF_CONNECTION_STATUS:
if (dj_report->report_params[CONNECTION_STATUS_PARAM_STATUS] ==
STATUS_LINKLOSS) {
logi_dj_recv_forward_null_report(djrcv_dev, dj_report);
}
break;
default:
logi_dj_recv_forward_report(djrcv_dev, dj_report);
}
out:
spin_unlock_irqrestore(&djrcv_dev->lock, flags);
return true;
}
static int logi_dj_hidpp_event(struct hid_device *hdev,
struct hid_report *report, u8 *data,
int size)
{
struct dj_receiver_dev *djrcv_dev = hid_get_drvdata(hdev);
struct dj_report *dj_report = (struct dj_report *) data;
unsigned long flags;
u8 device_index = dj_report->device_index;
if (device_index == HIDPP_RECEIVER_INDEX) {
if (size == HIDPP_REPORT_LONG_LENGTH &&
!memcmp(data, unifying_name_answer,
sizeof(unifying_name_answer)) &&
((data[4] & 0xF0) == 0x40))
device_index = (data[4] & 0x0F) + 1;
else
return false;
}
if ((device_index < DJ_DEVICE_INDEX_MIN) ||
(device_index > DJ_DEVICE_INDEX_MAX)) {
dev_err(&hdev->dev, "%s: invalid device index:%d\n",
__func__, dj_report->device_index);
return false;
}
spin_lock_irqsave(&djrcv_dev->lock, flags);
if (!djrcv_dev->paired_dj_devices[device_index])
goto out;
logi_dj_recv_forward_hidpp(djrcv_dev->paired_dj_devices[device_index],
data, size);
out:
spin_unlock_irqrestore(&djrcv_dev->lock, flags);
return false;
}
static int logi_dj_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data,
int size)
{
dbg_hid("%s, size:%d\n", __func__, size);
switch (data[0]) {
case REPORT_ID_DJ_SHORT:
if (size != DJREPORT_SHORT_LENGTH) {
dev_err(&hdev->dev, "DJ report of bad size (%d)", size);
return false;
}
return logi_dj_dj_event(hdev, report, data, size);
case REPORT_ID_HIDPP_SHORT:
if (size != HIDPP_REPORT_SHORT_LENGTH) {
dev_err(&hdev->dev,
"Short HID++ report of bad size (%d)", size);
return false;
}
return logi_dj_hidpp_event(hdev, report, data, size);
case REPORT_ID_HIDPP_LONG:
if (size != HIDPP_REPORT_LONG_LENGTH) {
dev_err(&hdev->dev,
"Long HID++ report of bad size (%d)", size);
return false;
}
return logi_dj_hidpp_event(hdev, report, data, size);
}
return false;
}
static int logi_dj_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct dj_receiver_dev *djrcv_dev;
int retval;
dbg_hid("%s called for ifnum %d\n", __func__,
intf->cur_altsetting->desc.bInterfaceNumber);
if (intf->cur_altsetting->desc.bInterfaceNumber !=
LOGITECH_DJ_INTERFACE_NUMBER) {
dbg_hid("%s: ignoring ifnum %d\n", __func__,
intf->cur_altsetting->desc.bInterfaceNumber);
return -ENODEV;
}
djrcv_dev = kzalloc(sizeof(struct dj_receiver_dev), GFP_KERNEL);
if (!djrcv_dev) {
dev_err(&hdev->dev,
"%s:failed allocating dj_receiver_dev\n", __func__);
return -ENOMEM;
}
djrcv_dev->hdev = hdev;
INIT_WORK(&djrcv_dev->work, delayedwork_callback);
spin_lock_init(&djrcv_dev->lock);
if (kfifo_alloc(&djrcv_dev->notif_fifo,
DJ_MAX_NUMBER_NOTIFICATIONS * sizeof(struct dj_report),
GFP_KERNEL)) {
dev_err(&hdev->dev,
"%s:failed allocating notif_fifo\n", __func__);
kfree(djrcv_dev);
return -ENOMEM;
}
hid_set_drvdata(hdev, djrcv_dev);
retval = hid_parse(hdev);
if (retval) {
dev_err(&hdev->dev,
"%s:parse of interface 2 failed\n", __func__);
goto hid_parse_fail;
}
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, REPORT_ID_DJ_SHORT,
0, DJREPORT_SHORT_LENGTH - 1)) {
retval = -ENODEV;
goto hid_parse_fail;
}
retval = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (retval) {
dev_err(&hdev->dev,
"%s:hid_hw_start returned error\n", __func__);
goto hid_hw_start_fail;
}
retval = logi_dj_recv_switch_to_dj_mode(djrcv_dev, 0);
if (retval < 0) {
dev_err(&hdev->dev,
"%s:logi_dj_recv_switch_to_dj_mode returned error:%d\n",
__func__, retval);
goto switch_to_dj_mode_fail;
}
retval = hid_hw_open(hdev);
if (retval < 0) {
dev_err(&hdev->dev, "%s:hid_hw_open returned error:%d\n",
__func__, retval);
goto llopen_failed;
}
hid_device_io_start(hdev);
retval = logi_dj_recv_query_paired_devices(djrcv_dev);
if (retval < 0) {
dev_err(&hdev->dev, "%s:logi_dj_recv_query_paired_devices "
"error:%d\n", __func__, retval);
goto logi_dj_recv_query_paired_devices_failed;
}
return retval;
logi_dj_recv_query_paired_devices_failed:
hid_hw_close(hdev);
llopen_failed:
switch_to_dj_mode_fail:
hid_hw_stop(hdev);
hid_hw_start_fail:
hid_parse_fail:
kfifo_free(&djrcv_dev->notif_fifo);
kfree(djrcv_dev);
hid_set_drvdata(hdev, NULL);
return retval;
}
static int logi_dj_reset_resume(struct hid_device *hdev)
{
int retval;
struct dj_receiver_dev *djrcv_dev = hid_get_drvdata(hdev);
retval = logi_dj_recv_switch_to_dj_mode(djrcv_dev, 0);
if (retval < 0) {
dev_err(&hdev->dev,
"%s:logi_dj_recv_switch_to_dj_mode returned error:%d\n",
__func__, retval);
}
return 0;
}
static void logi_dj_remove(struct hid_device *hdev)
{
struct dj_receiver_dev *djrcv_dev = hid_get_drvdata(hdev);
struct dj_device *dj_dev;
int i;
dbg_hid("%s\n", __func__);
cancel_work_sync(&djrcv_dev->work);
hid_hw_close(hdev);
hid_hw_stop(hdev);
for (i = 0; i < (DJ_MAX_PAIRED_DEVICES + DJ_DEVICE_INDEX_MIN); i++) {
dj_dev = djrcv_dev->paired_dj_devices[i];
if (dj_dev != NULL) {
hid_destroy_device(dj_dev->hdev);
kfree(dj_dev);
djrcv_dev->paired_dj_devices[i] = NULL;
}
}
kfifo_free(&djrcv_dev->notif_fifo);
kfree(djrcv_dev);
hid_set_drvdata(hdev, NULL);
}
