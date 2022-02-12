static void elo_input_configured(struct hid_device *hdev,
struct hid_input *hidinput)
{
struct input_dev *input = hidinput->input;
set_bit(BTN_TOUCH, input->keybit);
set_bit(ABS_PRESSURE, input->absbit);
input_set_abs_params(input, ABS_PRESSURE, 0, 256, 0, 0);
}
static void elo_process_data(struct input_dev *input, const u8 *data, int size)
{
int press;
input_report_abs(input, ABS_X, (data[3] << 8) | data[2]);
input_report_abs(input, ABS_Y, (data[5] << 8) | data[4]);
press = 0;
if (data[1] & 0x80)
press = (data[7] << 8) | data[6];
input_report_abs(input, ABS_PRESSURE, press);
if (data[1] & 0x03) {
input_report_key(input, BTN_TOUCH, 1);
input_sync(input);
}
if (data[1] & 0x04)
input_report_key(input, BTN_TOUCH, 0);
input_sync(input);
}
static int elo_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
struct hid_input *hidinput;
if (!(hdev->claimed & HID_CLAIMED_INPUT) || list_empty(&hdev->inputs))
return 0;
hidinput = list_first_entry(&hdev->inputs, struct hid_input, list);
switch (report->id) {
case 0:
if (data[0] == 'T') {
elo_process_data(hidinput->input, data, size);
return 1;
}
break;
default:
hid_info(hdev, "unknown report type %d\n", report->id);
break;
}
return 0;
}
static int elo_smartset_send_get(struct usb_device *dev, u8 command,
void *data)
{
unsigned int pipe;
u8 dir;
if (command == ELO_SEND_SMARTSET_COMMAND) {
pipe = usb_sndctrlpipe(dev, 0);
dir = USB_DIR_OUT;
} else if (command == ELO_GET_SMARTSET_RESPONSE) {
pipe = usb_rcvctrlpipe(dev, 0);
dir = USB_DIR_IN;
} else
return -EINVAL;
return usb_control_msg(dev, pipe, command,
dir | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, 0, data, ELO_SMARTSET_PACKET_SIZE,
ELO_SMARTSET_CMD_TIMEOUT);
}
static int elo_flush_smartset_responses(struct usb_device *dev)
{
return usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
ELO_FLUSH_SMARTSET_RESPONSES,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, 0, NULL, 0, USB_CTRL_SET_TIMEOUT);
}
static void elo_work(struct work_struct *work)
{
struct elo_priv *priv = container_of(work, struct elo_priv, work.work);
struct usb_device *dev = priv->usbdev;
unsigned char *buffer = priv->buffer;
int ret;
ret = elo_flush_smartset_responses(dev);
if (ret < 0) {
dev_err(&dev->dev, "initial FLUSH_SMARTSET_RESPONSES failed, error %d\n",
ret);
goto fail;
}
*buffer = ELO_DIAG;
ret = elo_smartset_send_get(dev, ELO_SEND_SMARTSET_COMMAND, buffer);
if (ret < 0) {
dev_err(&dev->dev, "send Diagnostics Command failed, error %d\n",
ret);
goto fail;
}
ret = elo_smartset_send_get(dev, ELO_GET_SMARTSET_RESPONSE, buffer);
if (ret < 0) {
dev_err(&dev->dev, "get Diagnostics Command response failed, error %d\n",
ret);
goto fail;
}
if (*buffer != 'A') {
ret = elo_smartset_send_get(dev, ELO_GET_SMARTSET_RESPONSE,
buffer);
if (ret < 0) {
dev_err(&dev->dev, "get acknowledge response failed, error %d\n",
ret);
goto fail;
}
}
fail:
ret = elo_flush_smartset_responses(dev);
if (ret < 0)
dev_err(&dev->dev, "final FLUSH_SMARTSET_RESPONSES failed, error %d\n",
ret);
queue_delayed_work(wq, &priv->work, ELO_PERIODIC_READ_INTERVAL);
}
static bool elo_broken_firmware(struct usb_device *dev)
{
struct usb_device *hub = dev->parent;
struct usb_device *child = NULL;
u16 fw_lvl = le16_to_cpu(dev->descriptor.bcdDevice);
u16 child_vid, child_pid;
int i;
if (!use_fw_quirk)
return false;
if (fw_lvl != 0x10d)
return false;
usb_hub_for_each_child(hub, i, child) {
child_vid = le16_to_cpu(child->descriptor.idVendor);
child_pid = le16_to_cpu(child->descriptor.idProduct);
if (child_vid==0x04b3) {
switch (child_pid) {
case 0x4676:
case 0x4677:
case 0x4678:
case 0x4679:
return false;
}
}
}
return true;
}
static int elo_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct elo_priv *priv;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
INIT_DELAYED_WORK(&priv->work, elo_work);
priv->usbdev = interface_to_usbdev(to_usb_interface(hdev->dev.parent));
hid_set_drvdata(hdev, priv);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
if (elo_broken_firmware(priv->usbdev)) {
hid_info(hdev, "broken firmware found, installing workaround\n");
queue_delayed_work(wq, &priv->work, ELO_PERIODIC_READ_INTERVAL);
}
return 0;
err_free:
kfree(priv);
return ret;
}
static void elo_remove(struct hid_device *hdev)
{
struct elo_priv *priv = hid_get_drvdata(hdev);
hid_hw_stop(hdev);
flush_workqueue(wq);
kfree(priv);
}
static int __init elo_driver_init(void)
{
int ret;
wq = create_singlethread_workqueue("elousb");
if (!wq)
return -ENOMEM;
ret = hid_register_driver(&elo_driver);
if (ret)
destroy_workqueue(wq);
return ret;
}
static void __exit elo_driver_exit(void)
{
hid_unregister_driver(&elo_driver);
destroy_workqueue(wq);
}
