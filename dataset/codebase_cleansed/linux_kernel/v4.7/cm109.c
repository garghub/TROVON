static unsigned short special_keymap(int code)
{
if (code > 0xff) {
switch (code - 0xff) {
case RECORD_MUTE: return KEY_MICMUTE;
case PLAYBACK_MUTE: return KEY_MUTE;
case VOLUME_DOWN: return KEY_VOLUMEDOWN;
case VOLUME_UP: return KEY_VOLUMEUP;
}
}
return KEY_RESERVED;
}
static unsigned short keymap_kip1000(int scancode)
{
switch (scancode) {
case 0x82: return KEY_NUMERIC_0;
case 0x14: return KEY_NUMERIC_1;
case 0x12: return KEY_NUMERIC_2;
case 0x11: return KEY_NUMERIC_3;
case 0x24: return KEY_NUMERIC_4;
case 0x22: return KEY_NUMERIC_5;
case 0x21: return KEY_NUMERIC_6;
case 0x44: return KEY_NUMERIC_7;
case 0x42: return KEY_NUMERIC_8;
case 0x41: return KEY_NUMERIC_9;
case 0x81: return KEY_NUMERIC_POUND;
case 0x84: return KEY_NUMERIC_STAR;
case 0x88: return KEY_ENTER;
case 0x48: return KEY_ESC;
case 0x28: return KEY_LEFT;
case 0x18: return KEY_RIGHT;
default: return special_keymap(scancode);
}
}
static unsigned short keymap_gtalk(int scancode)
{
switch (scancode) {
case 0x11: return KEY_NUMERIC_0;
case 0x21: return KEY_NUMERIC_1;
case 0x41: return KEY_NUMERIC_2;
case 0x81: return KEY_NUMERIC_3;
case 0x12: return KEY_NUMERIC_4;
case 0x22: return KEY_NUMERIC_5;
case 0x42: return KEY_NUMERIC_6;
case 0x82: return KEY_NUMERIC_7;
case 0x14: return KEY_NUMERIC_8;
case 0x24: return KEY_NUMERIC_9;
case 0x44: return KEY_NUMERIC_POUND;
case 0x84: return KEY_NUMERIC_STAR;
case 0x18: return KEY_ENTER;
case 0x28: return KEY_ESC;
case 0x48: return KEY_UP;
case 0x88: return KEY_DOWN;
default: return special_keymap(scancode);
}
}
static unsigned short keymap_usbph01(int scancode)
{
switch (scancode) {
case 0x11: return KEY_NUMERIC_0;
case 0x21: return KEY_NUMERIC_1;
case 0x41: return KEY_NUMERIC_2;
case 0x81: return KEY_NUMERIC_3;
case 0x12: return KEY_NUMERIC_4;
case 0x22: return KEY_NUMERIC_5;
case 0x42: return KEY_NUMERIC_6;
case 0x82: return KEY_NUMERIC_7;
case 0x14: return KEY_NUMERIC_8;
case 0x24: return KEY_NUMERIC_9;
case 0x44: return KEY_NUMERIC_POUND;
case 0x84: return KEY_NUMERIC_STAR;
case 0x18: return KEY_ENTER;
case 0x28: return KEY_ESC;
case 0x48: return KEY_LEFT;
case 0x88: return KEY_RIGHT;
default: return special_keymap(scancode);
}
}
static unsigned short keymap_atcom(int scancode)
{
switch (scancode) {
case 0x82: return KEY_NUMERIC_0;
case 0x11: return KEY_NUMERIC_1;
case 0x12: return KEY_NUMERIC_2;
case 0x14: return KEY_NUMERIC_3;
case 0x21: return KEY_NUMERIC_4;
case 0x22: return KEY_NUMERIC_5;
case 0x24: return KEY_NUMERIC_6;
case 0x41: return KEY_NUMERIC_7;
case 0x42: return KEY_NUMERIC_8;
case 0x44: return KEY_NUMERIC_9;
case 0x84: return KEY_NUMERIC_POUND;
case 0x81: return KEY_NUMERIC_STAR;
case 0x18: return KEY_ENTER;
case 0x28: return KEY_ESC;
case 0x48: return KEY_LEFT;
case 0x88: return KEY_RIGHT;
default: return special_keymap(scancode);
}
}
static void report_key(struct cm109_dev *dev, int key)
{
struct input_dev *idev = dev->idev;
if (dev->key_code >= 0) {
input_report_key(idev, dev->key_code, 0);
}
dev->key_code = key;
if (key >= 0) {
input_report_key(idev, key, 1);
}
input_sync(idev);
}
static void cm109_report_special(struct cm109_dev *dev)
{
static const u8 autorelease = RECORD_MUTE | PLAYBACK_MUTE;
struct input_dev *idev = dev->idev;
u8 data = dev->irq_data->byte[HID_IR0];
unsigned short keycode;
int i;
for (i = 0; i < 4; i++) {
keycode = dev->keymap[0xff + BIT(i)];
if (keycode == KEY_RESERVED)
continue;
input_report_key(idev, keycode, data & BIT(i));
if (data & autorelease & BIT(i)) {
input_sync(idev);
input_report_key(idev, keycode, 0);
}
}
input_sync(idev);
}
static void cm109_submit_buzz_toggle(struct cm109_dev *dev)
{
int error;
if (dev->buzzer_state)
dev->ctl_data->byte[HID_OR0] |= BUZZER_ON;
else
dev->ctl_data->byte[HID_OR0] &= ~BUZZER_ON;
error = usb_submit_urb(dev->urb_ctl, GFP_ATOMIC);
if (error)
dev_err(&dev->intf->dev,
"%s: usb_submit_urb (urb_ctl) failed %d\n",
__func__, error);
}
static void cm109_urb_irq_callback(struct urb *urb)
{
struct cm109_dev *dev = urb->context;
const int status = urb->status;
int error;
unsigned long flags;
dev_dbg(&dev->intf->dev, "### URB IRQ: [0x%02x 0x%02x 0x%02x 0x%02x] keybit=0x%02x\n",
dev->irq_data->byte[0],
dev->irq_data->byte[1],
dev->irq_data->byte[2],
dev->irq_data->byte[3],
dev->keybit);
if (status) {
if (status == -ESHUTDOWN)
return;
dev_err_ratelimited(&dev->intf->dev, "%s: urb status %d\n",
__func__, status);
goto out;
}
cm109_report_special(dev);
if (dev->keybit == 0xf) {
if ((dev->gpi & 0xf0) == (dev->irq_data->byte[HID_IR1] & 0xf0))
goto out;
dev->gpi = dev->irq_data->byte[HID_IR1] & 0xf0;
dev->keybit = 0x1;
} else {
report_key(dev, dev->keymap[dev->irq_data->byte[HID_IR1]]);
dev->keybit <<= 1;
if (dev->keybit > 0x8)
dev->keybit = 0xf;
}
out:
spin_lock_irqsave(&dev->ctl_submit_lock, flags);
dev->irq_urb_pending = 0;
if (likely(!dev->shutdown)) {
if (dev->buzzer_state)
dev->ctl_data->byte[HID_OR0] |= BUZZER_ON;
else
dev->ctl_data->byte[HID_OR0] &= ~BUZZER_ON;
dev->ctl_data->byte[HID_OR1] = dev->keybit;
dev->ctl_data->byte[HID_OR2] = dev->keybit;
dev->buzzer_pending = 0;
dev->ctl_urb_pending = 1;
error = usb_submit_urb(dev->urb_ctl, GFP_ATOMIC);
if (error)
dev_err(&dev->intf->dev,
"%s: usb_submit_urb (urb_ctl) failed %d\n",
__func__, error);
}
spin_unlock_irqrestore(&dev->ctl_submit_lock, flags);
}
static void cm109_urb_ctl_callback(struct urb *urb)
{
struct cm109_dev *dev = urb->context;
const int status = urb->status;
int error;
unsigned long flags;
dev_dbg(&dev->intf->dev, "### URB CTL: [0x%02x 0x%02x 0x%02x 0x%02x]\n",
dev->ctl_data->byte[0],
dev->ctl_data->byte[1],
dev->ctl_data->byte[2],
dev->ctl_data->byte[3]);
if (status) {
if (status == -ESHUTDOWN)
return;
dev_err_ratelimited(&dev->intf->dev, "%s: urb status %d\n",
__func__, status);
}
spin_lock_irqsave(&dev->ctl_submit_lock, flags);
dev->ctl_urb_pending = 0;
if (likely(!dev->shutdown)) {
if (dev->buzzer_pending || status) {
dev->buzzer_pending = 0;
dev->ctl_urb_pending = 1;
cm109_submit_buzz_toggle(dev);
} else if (likely(!dev->irq_urb_pending)) {
dev->irq_urb_pending = 1;
error = usb_submit_urb(dev->urb_irq, GFP_ATOMIC);
if (error)
dev_err(&dev->intf->dev,
"%s: usb_submit_urb (urb_irq) failed %d\n",
__func__, error);
}
}
spin_unlock_irqrestore(&dev->ctl_submit_lock, flags);
}
static void cm109_toggle_buzzer_async(struct cm109_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->ctl_submit_lock, flags);
if (dev->ctl_urb_pending) {
dev->buzzer_pending = 1;
} else {
dev->ctl_urb_pending = 1;
cm109_submit_buzz_toggle(dev);
}
spin_unlock_irqrestore(&dev->ctl_submit_lock, flags);
}
static void cm109_toggle_buzzer_sync(struct cm109_dev *dev, int on)
{
int error;
if (on)
dev->ctl_data->byte[HID_OR0] |= BUZZER_ON;
else
dev->ctl_data->byte[HID_OR0] &= ~BUZZER_ON;
error = usb_control_msg(dev->udev,
usb_sndctrlpipe(dev->udev, 0),
dev->ctl_req->bRequest,
dev->ctl_req->bRequestType,
le16_to_cpu(dev->ctl_req->wValue),
le16_to_cpu(dev->ctl_req->wIndex),
dev->ctl_data,
USB_PKT_LEN, USB_CTRL_SET_TIMEOUT);
if (error < 0 && error != -EINTR)
dev_err(&dev->intf->dev, "%s: usb_control_msg() failed %d\n",
__func__, error);
}
static void cm109_stop_traffic(struct cm109_dev *dev)
{
dev->shutdown = 1;
smp_wmb();
usb_kill_urb(dev->urb_ctl);
usb_kill_urb(dev->urb_irq);
cm109_toggle_buzzer_sync(dev, 0);
dev->shutdown = 0;
smp_wmb();
}
static void cm109_restore_state(struct cm109_dev *dev)
{
if (dev->open) {
cm109_toggle_buzzer_async(dev);
}
}
static int cm109_input_open(struct input_dev *idev)
{
struct cm109_dev *dev = input_get_drvdata(idev);
int error;
error = usb_autopm_get_interface(dev->intf);
if (error < 0) {
dev_err(&idev->dev, "%s - cannot autoresume, result %d\n",
__func__, error);
return error;
}
mutex_lock(&dev->pm_mutex);
dev->buzzer_state = 0;
dev->key_code = -1;
dev->keybit = 0xf;
dev->ctl_data->byte[HID_OR0] = HID_OR_GPO_BUZ_SPDIF;
dev->ctl_data->byte[HID_OR1] = dev->keybit;
dev->ctl_data->byte[HID_OR2] = dev->keybit;
dev->ctl_data->byte[HID_OR3] = 0x00;
error = usb_submit_urb(dev->urb_ctl, GFP_KERNEL);
if (error)
dev_err(&dev->intf->dev, "%s: usb_submit_urb (urb_ctl) failed %d\n",
__func__, error);
else
dev->open = 1;
mutex_unlock(&dev->pm_mutex);
if (error)
usb_autopm_put_interface(dev->intf);
return error;
}
static void cm109_input_close(struct input_dev *idev)
{
struct cm109_dev *dev = input_get_drvdata(idev);
mutex_lock(&dev->pm_mutex);
cm109_stop_traffic(dev);
dev->open = 0;
mutex_unlock(&dev->pm_mutex);
usb_autopm_put_interface(dev->intf);
}
static int cm109_input_ev(struct input_dev *idev, unsigned int type,
unsigned int code, int value)
{
struct cm109_dev *dev = input_get_drvdata(idev);
dev_dbg(&dev->intf->dev,
"input_ev: type=%u code=%u value=%d\n", type, code, value);
if (type != EV_SND)
return -EINVAL;
switch (code) {
case SND_TONE:
case SND_BELL:
dev->buzzer_state = !!value;
if (!dev->resetting)
cm109_toggle_buzzer_async(dev);
return 0;
default:
return -EINVAL;
}
}
static void cm109_usb_cleanup(struct cm109_dev *dev)
{
kfree(dev->ctl_req);
if (dev->ctl_data)
usb_free_coherent(dev->udev, USB_PKT_LEN,
dev->ctl_data, dev->ctl_dma);
if (dev->irq_data)
usb_free_coherent(dev->udev, USB_PKT_LEN,
dev->irq_data, dev->irq_dma);
usb_free_urb(dev->urb_irq);
usb_free_urb(dev->urb_ctl);
kfree(dev);
}
static void cm109_usb_disconnect(struct usb_interface *interface)
{
struct cm109_dev *dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
input_unregister_device(dev->idev);
cm109_usb_cleanup(dev);
}
static int cm109_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct driver_info *nfo = (struct driver_info *)id->driver_info;
struct usb_host_interface *interface;
struct usb_endpoint_descriptor *endpoint;
struct cm109_dev *dev;
struct input_dev *input_dev = NULL;
int ret, pipe, i;
int error = -ENOMEM;
interface = intf->cur_altsetting;
endpoint = &interface->endpoint[0].desc;
if (!usb_endpoint_is_int_in(endpoint))
return -ENODEV;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
spin_lock_init(&dev->ctl_submit_lock);
mutex_init(&dev->pm_mutex);
dev->udev = udev;
dev->intf = intf;
dev->idev = input_dev = input_allocate_device();
if (!input_dev)
goto err_out;
dev->irq_data = usb_alloc_coherent(udev, USB_PKT_LEN,
GFP_KERNEL, &dev->irq_dma);
if (!dev->irq_data)
goto err_out;
dev->ctl_data = usb_alloc_coherent(udev, USB_PKT_LEN,
GFP_KERNEL, &dev->ctl_dma);
if (!dev->ctl_data)
goto err_out;
dev->ctl_req = kmalloc(sizeof(*(dev->ctl_req)), GFP_KERNEL);
if (!dev->ctl_req)
goto err_out;
dev->urb_irq = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->urb_irq)
goto err_out;
dev->urb_ctl = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->urb_ctl)
goto err_out;
pipe = usb_rcvintpipe(udev, endpoint->bEndpointAddress);
ret = usb_maxpacket(udev, pipe, usb_pipeout(pipe));
if (ret != USB_PKT_LEN)
dev_err(&intf->dev, "invalid payload size %d, expected %d\n",
ret, USB_PKT_LEN);
usb_fill_int_urb(dev->urb_irq, udev, pipe, dev->irq_data,
USB_PKT_LEN,
cm109_urb_irq_callback, dev, endpoint->bInterval);
dev->urb_irq->transfer_dma = dev->irq_dma;
dev->urb_irq->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
dev->urb_irq->dev = udev;
dev->ctl_req->bRequestType = USB_TYPE_CLASS | USB_RECIP_INTERFACE |
USB_DIR_OUT;
dev->ctl_req->bRequest = USB_REQ_SET_CONFIGURATION;
dev->ctl_req->wValue = cpu_to_le16(0x200);
dev->ctl_req->wIndex = cpu_to_le16(interface->desc.bInterfaceNumber);
dev->ctl_req->wLength = cpu_to_le16(USB_PKT_LEN);
usb_fill_control_urb(dev->urb_ctl, udev, usb_sndctrlpipe(udev, 0),
(void *)dev->ctl_req, dev->ctl_data, USB_PKT_LEN,
cm109_urb_ctl_callback, dev);
dev->urb_ctl->transfer_dma = dev->ctl_dma;
dev->urb_ctl->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
dev->urb_ctl->dev = udev;
usb_make_path(udev, dev->phys, sizeof(dev->phys));
strlcat(dev->phys, "/input0", sizeof(dev->phys));
input_dev->name = nfo->name;
input_dev->phys = dev->phys;
usb_to_input_id(udev, &input_dev->id);
input_dev->dev.parent = &intf->dev;
input_set_drvdata(input_dev, dev);
input_dev->open = cm109_input_open;
input_dev->close = cm109_input_close;
input_dev->event = cm109_input_ev;
input_dev->keycode = dev->keymap;
input_dev->keycodesize = sizeof(unsigned char);
input_dev->keycodemax = ARRAY_SIZE(dev->keymap);
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_SND);
input_dev->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
for (i = 0; i < KEYMAP_SIZE; i++) {
unsigned short k = keymap(i);
dev->keymap[i] = k;
__set_bit(k, input_dev->keybit);
}
__clear_bit(KEY_RESERVED, input_dev->keybit);
error = input_register_device(dev->idev);
if (error)
goto err_out;
usb_set_intfdata(intf, dev);
return 0;
err_out:
input_free_device(input_dev);
cm109_usb_cleanup(dev);
return error;
}
static int cm109_usb_suspend(struct usb_interface *intf, pm_message_t message)
{
struct cm109_dev *dev = usb_get_intfdata(intf);
dev_info(&intf->dev, "cm109: usb_suspend (event=%d)\n", message.event);
mutex_lock(&dev->pm_mutex);
cm109_stop_traffic(dev);
mutex_unlock(&dev->pm_mutex);
return 0;
}
static int cm109_usb_resume(struct usb_interface *intf)
{
struct cm109_dev *dev = usb_get_intfdata(intf);
dev_info(&intf->dev, "cm109: usb_resume\n");
mutex_lock(&dev->pm_mutex);
cm109_restore_state(dev);
mutex_unlock(&dev->pm_mutex);
return 0;
}
static int cm109_usb_pre_reset(struct usb_interface *intf)
{
struct cm109_dev *dev = usb_get_intfdata(intf);
mutex_lock(&dev->pm_mutex);
dev->resetting = 1;
smp_wmb();
cm109_stop_traffic(dev);
return 0;
}
static int cm109_usb_post_reset(struct usb_interface *intf)
{
struct cm109_dev *dev = usb_get_intfdata(intf);
dev->resetting = 0;
smp_wmb();
cm109_restore_state(dev);
mutex_unlock(&dev->pm_mutex);
return 0;
}
static int __init cm109_select_keymap(void)
{
if (!strcasecmp(phone, "kip1000")) {
keymap = keymap_kip1000;
printk(KERN_INFO KBUILD_MODNAME ": "
"Keymap for Komunikate KIP1000 phone loaded\n");
} else if (!strcasecmp(phone, "gtalk")) {
keymap = keymap_gtalk;
printk(KERN_INFO KBUILD_MODNAME ": "
"Keymap for Genius G-talk phone loaded\n");
} else if (!strcasecmp(phone, "usbph01")) {
keymap = keymap_usbph01;
printk(KERN_INFO KBUILD_MODNAME ": "
"Keymap for Allied-Telesis Corega USBPH01 phone loaded\n");
} else if (!strcasecmp(phone, "atcom")) {
keymap = keymap_atcom;
printk(KERN_INFO KBUILD_MODNAME ": "
"Keymap for ATCom AU-100 phone loaded\n");
} else {
printk(KERN_ERR KBUILD_MODNAME ": "
"Unsupported phone: %s\n", phone);
return -EINVAL;
}
return 0;
}
static int __init cm109_init(void)
{
int err;
err = cm109_select_keymap();
if (err)
return err;
err = usb_register(&cm109_driver);
if (err)
return err;
printk(KERN_INFO KBUILD_MODNAME ": "
DRIVER_DESC ": " DRIVER_VERSION " (C) " DRIVER_AUTHOR "\n");
return 0;
}
static void __exit cm109_exit(void)
{
usb_deregister(&cm109_driver);
}
