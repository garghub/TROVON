static void keyspan_print(struct usb_keyspan* dev)
{
char codes[4 * RECV_SIZE];
int i;
for (i = 0; i < RECV_SIZE; i++)
snprintf(codes + i * 3, 4, "%02x ", dev->in_buffer[i]);
dev_info(&dev->udev->dev, "%s\n", codes);
}
static int keyspan_load_tester(struct usb_keyspan* dev, int bits_needed)
{
if (dev->data.bits_left >= bits_needed)
return 0;
if (dev->data.pos >= dev->data.len) {
dev_dbg(&dev->interface->dev,
"%s - Error ran out of data. pos: %d, len: %d\n",
__func__, dev->data.pos, dev->data.len);
return -1;
}
while ((dev->data.bits_left + 7 < (sizeof(dev->data.tester) * 8)) &&
(dev->data.pos < dev->data.len)) {
dev->data.tester += (dev->data.buffer[dev->data.pos++] << dev->data.bits_left);
dev->data.bits_left += 8;
}
return 0;
}
static void keyspan_report_button(struct usb_keyspan *remote, int button, int press)
{
struct input_dev *input = remote->input;
input_event(input, EV_MSC, MSC_SCAN, button);
input_report_key(input, remote->keymap[button], press);
input_sync(input);
}
static void keyspan_check_data(struct usb_keyspan *remote)
{
int i;
int found = 0;
struct keyspan_message message;
switch(remote->stage) {
case 0:
for (i = 0; i < RECV_SIZE && remote->in_buffer[i] == GAP; ++i);
if (i < RECV_SIZE) {
memcpy(remote->data.buffer, remote->in_buffer, RECV_SIZE);
remote->data.len = RECV_SIZE;
remote->data.pos = 0;
remote->data.tester = 0;
remote->data.bits_left = 0;
remote->stage = 1;
}
break;
case 1:
memcpy(remote->data.buffer + remote->data.len, remote->in_buffer, RECV_SIZE);
remote->data.len += RECV_SIZE;
found = 0;
while ((remote->data.bits_left >= 14 || remote->data.pos < remote->data.len) && !found) {
for (i = 0; i < 8; ++i) {
if (keyspan_load_tester(remote, 14) != 0) {
remote->stage = 0;
return;
}
if ((remote->data.tester & SYNC_MASK) == SYNC) {
remote->data.tester = remote->data.tester >> 14;
remote->data.bits_left -= 14;
found = 1;
break;
} else {
remote->data.tester = remote->data.tester >> 1;
--remote->data.bits_left;
}
}
}
if (!found) {
remote->stage = 0;
remote->data.len = 0;
} else {
remote->stage = 2;
}
break;
case 2:
memcpy(remote->data.buffer + remote->data.len, remote->in_buffer, RECV_SIZE);
remote->data.len += RECV_SIZE;
message.system = 0;
for (i = 0; i < 9; i++) {
keyspan_load_tester(remote, 6);
if ((remote->data.tester & ZERO_MASK) == ZERO) {
message.system = message.system << 1;
remote->data.tester = remote->data.tester >> 5;
remote->data.bits_left -= 5;
} else if ((remote->data.tester & ONE_MASK) == ONE) {
message.system = (message.system << 1) + 1;
remote->data.tester = remote->data.tester >> 6;
remote->data.bits_left -= 6;
} else {
dev_err(&remote->interface->dev,
"%s - Unknown sequence found in system data.\n",
__func__);
remote->stage = 0;
return;
}
}
message.button = 0;
for (i = 0; i < 5; i++) {
keyspan_load_tester(remote, 6);
if ((remote->data.tester & ZERO_MASK) == ZERO) {
message.button = message.button << 1;
remote->data.tester = remote->data.tester >> 5;
remote->data.bits_left -= 5;
} else if ((remote->data.tester & ONE_MASK) == ONE) {
message.button = (message.button << 1) + 1;
remote->data.tester = remote->data.tester >> 6;
remote->data.bits_left -= 6;
} else {
dev_err(&remote->interface->dev,
"%s - Unknown sequence found in button data.\n",
__func__);
remote->stage = 0;
return;
}
}
keyspan_load_tester(remote, 6);
if ((remote->data.tester & ZERO_MASK) == ZERO) {
message.toggle = 0;
remote->data.tester = remote->data.tester >> 5;
remote->data.bits_left -= 5;
} else if ((remote->data.tester & ONE_MASK) == ONE) {
message.toggle = 1;
remote->data.tester = remote->data.tester >> 6;
remote->data.bits_left -= 6;
} else {
dev_err(&remote->interface->dev,
"%s - Error in message, invalid toggle.\n",
__func__);
remote->stage = 0;
return;
}
keyspan_load_tester(remote, 5);
if ((remote->data.tester & STOP_MASK) == STOP) {
remote->data.tester = remote->data.tester >> 5;
remote->data.bits_left -= 5;
} else {
dev_err(&remote->interface->dev,
"Bad message received, no stop bit found.\n");
}
dev_dbg(&remote->interface->dev,
"%s found valid message: system: %d, button: %d, toggle: %d\n",
__func__, message.system, message.button, message.toggle);
if (message.toggle != remote->toggle) {
keyspan_report_button(remote, message.button, 1);
keyspan_report_button(remote, message.button, 0);
remote->toggle = message.toggle;
}
remote->stage = 0;
break;
}
}
static int keyspan_setup(struct usb_device* dev)
{
int retval = 0;
retval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x11, 0x40, 0x5601, 0x0, NULL, 0, 0);
if (retval) {
dev_dbg(&dev->dev, "%s - failed to set bit rate due to error: %d\n",
__func__, retval);
return(retval);
}
retval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x44, 0x40, 0x0, 0x0, NULL, 0, 0);
if (retval) {
dev_dbg(&dev->dev, "%s - failed to set resume sensitivity due to error: %d\n",
__func__, retval);
return(retval);
}
retval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x22, 0x40, 0x0, 0x0, NULL, 0, 0);
if (retval) {
dev_dbg(&dev->dev, "%s - failed to turn receive on due to error: %d\n",
__func__, retval);
return(retval);
}
dev_dbg(&dev->dev, "%s - Setup complete.\n", __func__);
return(retval);
}
static void keyspan_irq_recv(struct urb *urb)
{
struct usb_keyspan *dev = urb->context;
int retval;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
goto resubmit;
break;
}
if (debug)
keyspan_print(dev);
keyspan_check_data(dev);
resubmit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->interface->dev,
"%s - usb_submit_urb failed with result: %d\n",
__func__, retval);
}
static int keyspan_open(struct input_dev *dev)
{
struct usb_keyspan *remote = input_get_drvdata(dev);
remote->irq_urb->dev = remote->udev;
if (usb_submit_urb(remote->irq_urb, GFP_KERNEL))
return -EIO;
return 0;
}
static void keyspan_close(struct input_dev *dev)
{
struct usb_keyspan *remote = input_get_drvdata(dev);
usb_kill_urb(remote->irq_urb);
}
static struct usb_endpoint_descriptor *keyspan_get_in_endpoint(struct usb_host_interface *iface)
{
struct usb_endpoint_descriptor *endpoint;
int i;
for (i = 0; i < iface->desc.bNumEndpoints; ++i) {
endpoint = &iface->endpoint[i].desc;
if (usb_endpoint_is_int_in(endpoint)) {
return endpoint;
}
}
return NULL;
}
static int keyspan_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_endpoint_descriptor *endpoint;
struct usb_keyspan *remote;
struct input_dev *input_dev;
int i, error;
endpoint = keyspan_get_in_endpoint(interface->cur_altsetting);
if (!endpoint)
return -ENODEV;
remote = kzalloc(sizeof(*remote), GFP_KERNEL);
input_dev = input_allocate_device();
if (!remote || !input_dev) {
error = -ENOMEM;
goto fail1;
}
remote->udev = udev;
remote->input = input_dev;
remote->interface = interface;
remote->in_endpoint = endpoint;
remote->toggle = -1;
remote->in_buffer = usb_alloc_coherent(udev, RECV_SIZE, GFP_ATOMIC, &remote->in_dma);
if (!remote->in_buffer) {
error = -ENOMEM;
goto fail1;
}
remote->irq_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!remote->irq_urb) {
error = -ENOMEM;
goto fail2;
}
error = keyspan_setup(udev);
if (error) {
error = -ENODEV;
goto fail3;
}
if (udev->manufacturer)
strlcpy(remote->name, udev->manufacturer, sizeof(remote->name));
if (udev->product) {
if (udev->manufacturer)
strlcat(remote->name, " ", sizeof(remote->name));
strlcat(remote->name, udev->product, sizeof(remote->name));
}
if (!strlen(remote->name))
snprintf(remote->name, sizeof(remote->name),
"USB Keyspan Remote %04x:%04x",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
usb_make_path(udev, remote->phys, sizeof(remote->phys));
strlcat(remote->phys, "/input0", sizeof(remote->phys));
memcpy(remote->keymap, keyspan_key_table, sizeof(remote->keymap));
input_dev->name = remote->name;
input_dev->phys = remote->phys;
usb_to_input_id(udev, &input_dev->id);
input_dev->dev.parent = &interface->dev;
input_dev->keycode = remote->keymap;
input_dev->keycodesize = sizeof(unsigned short);
input_dev->keycodemax = ARRAY_SIZE(remote->keymap);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
__set_bit(EV_KEY, input_dev->evbit);
for (i = 0; i < ARRAY_SIZE(keyspan_key_table); i++)
__set_bit(keyspan_key_table[i], input_dev->keybit);
__clear_bit(KEY_RESERVED, input_dev->keybit);
input_set_drvdata(input_dev, remote);
input_dev->open = keyspan_open;
input_dev->close = keyspan_close;
usb_fill_int_urb(remote->irq_urb,
remote->udev,
usb_rcvintpipe(remote->udev, endpoint->bEndpointAddress),
remote->in_buffer, RECV_SIZE, keyspan_irq_recv, remote,
endpoint->bInterval);
remote->irq_urb->transfer_dma = remote->in_dma;
remote->irq_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
error = input_register_device(remote->input);
if (error)
goto fail3;
usb_set_intfdata(interface, remote);
return 0;
fail3: usb_free_urb(remote->irq_urb);
fail2: usb_free_coherent(udev, RECV_SIZE, remote->in_buffer, remote->in_dma);
fail1: kfree(remote);
input_free_device(input_dev);
return error;
}
static void keyspan_disconnect(struct usb_interface *interface)
{
struct usb_keyspan *remote;
remote = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
if (remote) {
input_unregister_device(remote->input);
usb_kill_urb(remote->irq_urb);
usb_free_urb(remote->irq_urb);
usb_free_coherent(remote->udev, RECV_SIZE, remote->in_buffer, remote->in_dma);
kfree(remote);
}
}
