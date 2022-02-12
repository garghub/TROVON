static void usb_kbd_irq(struct urb *urb)
{
struct usb_kbd *kbd = urb->context;
int i;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
goto resubmit;
}
for (i = 0; i < 8; i++)
input_report_key(kbd->dev, usb_kbd_keycode[i + 224], (kbd->new[0] >> i) & 1);
for (i = 2; i < 8; i++) {
if (kbd->old[i] > 3 && memscan(kbd->new + 2, kbd->old[i], 6) == kbd->new + 8) {
if (usb_kbd_keycode[kbd->old[i]])
input_report_key(kbd->dev, usb_kbd_keycode[kbd->old[i]], 0);
else
hid_info(urb->dev,
"Unknown key (scancode %#x) released.\n",
kbd->old[i]);
}
if (kbd->new[i] > 3 && memscan(kbd->old + 2, kbd->new[i], 6) == kbd->old + 8) {
if (usb_kbd_keycode[kbd->new[i]])
input_report_key(kbd->dev, usb_kbd_keycode[kbd->new[i]], 1);
else
hid_info(urb->dev,
"Unknown key (scancode %#x) pressed.\n",
kbd->new[i]);
}
}
input_sync(kbd->dev);
memcpy(kbd->old, kbd->new, 8);
resubmit:
i = usb_submit_urb (urb, GFP_ATOMIC);
if (i)
hid_err(urb->dev, "can't resubmit intr, %s-%s/input0, status %d",
kbd->usbdev->bus->bus_name,
kbd->usbdev->devpath, i);
}
static int usb_kbd_event(struct input_dev *dev, unsigned int type,
unsigned int code, int value)
{
unsigned long flags;
struct usb_kbd *kbd = input_get_drvdata(dev);
if (type != EV_LED)
return -1;
spin_lock_irqsave(&kbd->leds_lock, flags);
kbd->newleds = (!!test_bit(LED_KANA, dev->led) << 3) | (!!test_bit(LED_COMPOSE, dev->led) << 3) |
(!!test_bit(LED_SCROLLL, dev->led) << 2) | (!!test_bit(LED_CAPSL, dev->led) << 1) |
(!!test_bit(LED_NUML, dev->led));
if (kbd->led_urb_submitted){
spin_unlock_irqrestore(&kbd->leds_lock, flags);
return 0;
}
if (*(kbd->leds) == kbd->newleds){
spin_unlock_irqrestore(&kbd->leds_lock, flags);
return 0;
}
*(kbd->leds) = kbd->newleds;
kbd->led->dev = kbd->usbdev;
if (usb_submit_urb(kbd->led, GFP_ATOMIC))
pr_err("usb_submit_urb(leds) failed\n");
else
kbd->led_urb_submitted = true;
spin_unlock_irqrestore(&kbd->leds_lock, flags);
return 0;
}
static void usb_kbd_led(struct urb *urb)
{
unsigned long flags;
struct usb_kbd *kbd = urb->context;
if (urb->status)
hid_warn(urb->dev, "led urb status %d received\n",
urb->status);
spin_lock_irqsave(&kbd->leds_lock, flags);
if (*(kbd->leds) == kbd->newleds){
kbd->led_urb_submitted = false;
spin_unlock_irqrestore(&kbd->leds_lock, flags);
return;
}
*(kbd->leds) = kbd->newleds;
kbd->led->dev = kbd->usbdev;
if (usb_submit_urb(kbd->led, GFP_ATOMIC)){
hid_err(urb->dev, "usb_submit_urb(leds) failed\n");
kbd->led_urb_submitted = false;
}
spin_unlock_irqrestore(&kbd->leds_lock, flags);
}
static int usb_kbd_open(struct input_dev *dev)
{
struct usb_kbd *kbd = input_get_drvdata(dev);
kbd->irq->dev = kbd->usbdev;
if (usb_submit_urb(kbd->irq, GFP_KERNEL))
return -EIO;
return 0;
}
static void usb_kbd_close(struct input_dev *dev)
{
struct usb_kbd *kbd = input_get_drvdata(dev);
usb_kill_urb(kbd->irq);
}
static int usb_kbd_alloc_mem(struct usb_device *dev, struct usb_kbd *kbd)
{
if (!(kbd->irq = usb_alloc_urb(0, GFP_KERNEL)))
return -1;
if (!(kbd->led = usb_alloc_urb(0, GFP_KERNEL)))
return -1;
if (!(kbd->new = usb_alloc_coherent(dev, 8, GFP_ATOMIC, &kbd->new_dma)))
return -1;
if (!(kbd->cr = kmalloc(sizeof(struct usb_ctrlrequest), GFP_KERNEL)))
return -1;
if (!(kbd->leds = usb_alloc_coherent(dev, 1, GFP_ATOMIC, &kbd->leds_dma)))
return -1;
return 0;
}
static void usb_kbd_free_mem(struct usb_device *dev, struct usb_kbd *kbd)
{
usb_free_urb(kbd->irq);
usb_free_urb(kbd->led);
usb_free_coherent(dev, 8, kbd->new, kbd->new_dma);
kfree(kbd->cr);
usb_free_coherent(dev, 1, kbd->leds, kbd->leds_dma);
}
static int usb_kbd_probe(struct usb_interface *iface,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(iface);
struct usb_host_interface *interface;
struct usb_endpoint_descriptor *endpoint;
struct usb_kbd *kbd;
struct input_dev *input_dev;
int i, pipe, maxp;
int error = -ENOMEM;
interface = iface->cur_altsetting;
if (interface->desc.bNumEndpoints != 1)
return -ENODEV;
endpoint = &interface->endpoint[0].desc;
if (!usb_endpoint_is_int_in(endpoint))
return -ENODEV;
pipe = usb_rcvintpipe(dev, endpoint->bEndpointAddress);
maxp = usb_maxpacket(dev, pipe, usb_pipeout(pipe));
kbd = kzalloc(sizeof(struct usb_kbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!kbd || !input_dev)
goto fail1;
if (usb_kbd_alloc_mem(dev, kbd))
goto fail2;
kbd->usbdev = dev;
kbd->dev = input_dev;
spin_lock_init(&kbd->leds_lock);
if (dev->manufacturer)
strlcpy(kbd->name, dev->manufacturer, sizeof(kbd->name));
if (dev->product) {
if (dev->manufacturer)
strlcat(kbd->name, " ", sizeof(kbd->name));
strlcat(kbd->name, dev->product, sizeof(kbd->name));
}
if (!strlen(kbd->name))
snprintf(kbd->name, sizeof(kbd->name),
"USB HIDBP Keyboard %04x:%04x",
le16_to_cpu(dev->descriptor.idVendor),
le16_to_cpu(dev->descriptor.idProduct));
usb_make_path(dev, kbd->phys, sizeof(kbd->phys));
strlcat(kbd->phys, "/input0", sizeof(kbd->phys));
input_dev->name = kbd->name;
input_dev->phys = kbd->phys;
usb_to_input_id(dev, &input_dev->id);
input_dev->dev.parent = &iface->dev;
input_set_drvdata(input_dev, kbd);
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_LED) |
BIT_MASK(EV_REP);
input_dev->ledbit[0] = BIT_MASK(LED_NUML) | BIT_MASK(LED_CAPSL) |
BIT_MASK(LED_SCROLLL) | BIT_MASK(LED_COMPOSE) |
BIT_MASK(LED_KANA);
for (i = 0; i < 255; i++)
set_bit(usb_kbd_keycode[i], input_dev->keybit);
clear_bit(0, input_dev->keybit);
input_dev->event = usb_kbd_event;
input_dev->open = usb_kbd_open;
input_dev->close = usb_kbd_close;
usb_fill_int_urb(kbd->irq, dev, pipe,
kbd->new, (maxp > 8 ? 8 : maxp),
usb_kbd_irq, kbd, endpoint->bInterval);
kbd->irq->transfer_dma = kbd->new_dma;
kbd->irq->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
kbd->cr->bRequestType = USB_TYPE_CLASS | USB_RECIP_INTERFACE;
kbd->cr->bRequest = 0x09;
kbd->cr->wValue = cpu_to_le16(0x200);
kbd->cr->wIndex = cpu_to_le16(interface->desc.bInterfaceNumber);
kbd->cr->wLength = cpu_to_le16(1);
usb_fill_control_urb(kbd->led, dev, usb_sndctrlpipe(dev, 0),
(void *) kbd->cr, kbd->leds, 1,
usb_kbd_led, kbd);
kbd->led->transfer_dma = kbd->leds_dma;
kbd->led->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
error = input_register_device(kbd->dev);
if (error)
goto fail2;
usb_set_intfdata(iface, kbd);
device_set_wakeup_enable(&dev->dev, 1);
return 0;
fail2:
usb_kbd_free_mem(dev, kbd);
fail1:
input_free_device(input_dev);
kfree(kbd);
return error;
}
static void usb_kbd_disconnect(struct usb_interface *intf)
{
struct usb_kbd *kbd = usb_get_intfdata (intf);
usb_set_intfdata(intf, NULL);
if (kbd) {
usb_kill_urb(kbd->irq);
input_unregister_device(kbd->dev);
usb_kill_urb(kbd->led);
usb_kbd_free_mem(interface_to_usbdev(intf), kbd);
kfree(kbd);
}
}
