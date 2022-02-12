static enum led_brightness ttusbir_brightness_get(struct led_classdev *led_dev)
{
struct ttusbir *tt = container_of(led_dev, struct ttusbir, led);
return tt->led_on ? LED_FULL : LED_OFF;
}
static void ttusbir_set_led(struct ttusbir *tt)
{
int ret;
smp_mb();
if (tt->led_on != tt->is_led_on && tt->udev &&
atomic_add_unless(&tt->led_complete, 1, 1)) {
tt->bulk_buffer[4] = tt->is_led_on = tt->led_on;
ret = usb_submit_urb(tt->bulk_urb, GFP_ATOMIC);
if (ret) {
dev_warn(tt->dev, "failed to submit bulk urb: %d\n",
ret);
atomic_dec(&tt->led_complete);
}
}
}
static void ttusbir_brightness_set(struct led_classdev *led_dev, enum
led_brightness brightness)
{
struct ttusbir *tt = container_of(led_dev, struct ttusbir, led);
tt->led_on = brightness != LED_OFF;
ttusbir_set_led(tt);
}
static void ttusbir_bulk_complete(struct urb *urb)
{
struct ttusbir *tt = urb->context;
atomic_dec(&tt->led_complete);
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
usb_unlink_urb(urb);
return;
case -EPIPE:
default:
dev_dbg(tt->dev, "Error: urb status = %d\n", urb->status);
break;
}
ttusbir_set_led(tt);
}
static void ttusbir_process_ir_data(struct ttusbir *tt, uint8_t *buf)
{
struct ir_raw_event rawir;
unsigned i, v, b;
bool event = false;
init_ir_raw_event(&rawir);
for (i = 0; i < 128; i++) {
v = buf[i] & 0xfe;
switch (v) {
case 0xfe:
rawir.pulse = false;
rawir.duration = NS_PER_BYTE;
if (ir_raw_event_store_with_filter(tt->rc, &rawir))
event = true;
break;
case 0:
rawir.pulse = true;
rawir.duration = NS_PER_BYTE;
if (ir_raw_event_store_with_filter(tt->rc, &rawir))
event = true;
break;
default:
if (v & 2) {
b = ffz(v | 1);
rawir.pulse = true;
} else {
b = ffs(v) - 1;
rawir.pulse = false;
}
rawir.duration = NS_PER_BIT * (8 - b);
if (ir_raw_event_store_with_filter(tt->rc, &rawir))
event = true;
rawir.pulse = !rawir.pulse;
rawir.duration = NS_PER_BIT * b;
if (ir_raw_event_store_with_filter(tt->rc, &rawir))
event = true;
break;
}
}
if (event)
ir_raw_event_handle(tt->rc);
}
static void ttusbir_urb_complete(struct urb *urb)
{
struct ttusbir *tt = urb->context;
int rc;
switch (urb->status) {
case 0:
ttusbir_process_ir_data(tt, urb->transfer_buffer);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
usb_unlink_urb(urb);
return;
case -EPIPE:
default:
dev_dbg(tt->dev, "Error: urb status = %d\n", urb->status);
break;
}
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (rc && rc != -ENODEV)
dev_warn(tt->dev, "failed to resubmit urb: %d\n", rc);
}
static int ttusbir_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct ttusbir *tt;
struct usb_interface_descriptor *idesc;
struct usb_endpoint_descriptor *desc;
struct rc_dev *rc;
int i, j, ret;
int altsetting = -1;
tt = kzalloc(sizeof(*tt), GFP_KERNEL);
rc = rc_allocate_device();
if (!tt || !rc) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < intf->num_altsetting && altsetting == -1; i++) {
int max_packet, bulk_out_endp = -1, iso_in_endp = -1;
idesc = &intf->altsetting[i].desc;
for (j = 0; j < idesc->bNumEndpoints; j++) {
desc = &intf->altsetting[i].endpoint[j].desc;
max_packet = le16_to_cpu(desc->wMaxPacketSize);
if (usb_endpoint_dir_in(desc) &&
usb_endpoint_xfer_isoc(desc) &&
max_packet == 0x10)
iso_in_endp = j;
else if (usb_endpoint_dir_out(desc) &&
usb_endpoint_xfer_bulk(desc) &&
max_packet == 0x20)
bulk_out_endp = j;
if (bulk_out_endp != -1 && iso_in_endp != -1) {
tt->bulk_out_endp = bulk_out_endp;
tt->iso_in_endp = iso_in_endp;
altsetting = i;
break;
}
}
}
if (altsetting == -1) {
dev_err(&intf->dev, "cannot find expected altsetting\n");
ret = -ENODEV;
goto out;
}
tt->dev = &intf->dev;
tt->udev = interface_to_usbdev(intf);
tt->rc = rc;
ret = usb_set_interface(tt->udev, 0, altsetting);
if (ret)
goto out;
for (i = 0; i < NUM_URBS; i++) {
struct urb *urb = usb_alloc_urb(8, GFP_KERNEL);
void *buffer;
if (!urb) {
ret = -ENOMEM;
goto out;
}
urb->dev = tt->udev;
urb->context = tt;
urb->pipe = usb_rcvisocpipe(tt->udev, tt->iso_in_endp);
urb->interval = 1;
buffer = usb_alloc_coherent(tt->udev, 128, GFP_KERNEL,
&urb->transfer_dma);
if (!buffer) {
usb_free_urb(urb);
ret = -ENOMEM;
goto out;
}
urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP | URB_ISO_ASAP;
urb->transfer_buffer = buffer;
urb->complete = ttusbir_urb_complete;
urb->number_of_packets = 8;
urb->transfer_buffer_length = 128;
for (j = 0; j < 8; j++) {
urb->iso_frame_desc[j].offset = j * 16;
urb->iso_frame_desc[j].length = 16;
}
tt->urb[i] = urb;
}
tt->bulk_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!tt->bulk_urb) {
ret = -ENOMEM;
goto out;
}
tt->bulk_buffer[0] = 0xaa;
tt->bulk_buffer[1] = 0x01;
tt->bulk_buffer[2] = 0x05;
tt->bulk_buffer[3] = 0x01;
usb_fill_bulk_urb(tt->bulk_urb, tt->udev, usb_sndbulkpipe(tt->udev,
tt->bulk_out_endp), tt->bulk_buffer, sizeof(tt->bulk_buffer),
ttusbir_bulk_complete, tt);
tt->led.name = "ttusbir:green:power";
tt->led.default_trigger = "rc-feedback";
tt->led.brightness_set = ttusbir_brightness_set;
tt->led.brightness_get = ttusbir_brightness_get;
tt->is_led_on = tt->led_on = true;
atomic_set(&tt->led_complete, 0);
ret = led_classdev_register(&intf->dev, &tt->led);
if (ret)
goto out;
usb_make_path(tt->udev, tt->phys, sizeof(tt->phys));
rc->input_name = DRIVER_DESC;
rc->input_phys = tt->phys;
usb_to_input_id(tt->udev, &rc->input_id);
rc->dev.parent = &intf->dev;
rc->driver_type = RC_DRIVER_IR_RAW;
rc->allowed_protocols = RC_BIT_ALL;
rc->priv = tt;
rc->driver_name = DRIVER_NAME;
rc->map_name = RC_MAP_TT_1500;
rc->timeout = MS_TO_NS(100);
rc->rx_resolution = NS_PER_BIT;
ret = rc_register_device(rc);
if (ret) {
dev_err(&intf->dev, "failed to register rc device %d\n", ret);
goto out2;
}
usb_set_intfdata(intf, tt);
for (i = 0; i < NUM_URBS; i++) {
ret = usb_submit_urb(tt->urb[i], GFP_KERNEL);
if (ret) {
dev_err(tt->dev, "failed to submit urb %d\n", ret);
goto out3;
}
}
return 0;
out3:
rc_unregister_device(rc);
rc = NULL;
out2:
led_classdev_unregister(&tt->led);
out:
if (tt) {
for (i = 0; i < NUM_URBS && tt->urb[i]; i++) {
struct urb *urb = tt->urb[i];
usb_kill_urb(urb);
usb_free_coherent(tt->udev, 128, urb->transfer_buffer,
urb->transfer_dma);
usb_free_urb(urb);
}
usb_kill_urb(tt->bulk_urb);
usb_free_urb(tt->bulk_urb);
kfree(tt);
}
rc_free_device(rc);
return ret;
}
static void ttusbir_disconnect(struct usb_interface *intf)
{
struct ttusbir *tt = usb_get_intfdata(intf);
struct usb_device *udev = tt->udev;
int i;
tt->udev = NULL;
rc_unregister_device(tt->rc);
led_classdev_unregister(&tt->led);
for (i = 0; i < NUM_URBS; i++) {
usb_kill_urb(tt->urb[i]);
usb_free_coherent(udev, 128, tt->urb[i]->transfer_buffer,
tt->urb[i]->transfer_dma);
usb_free_urb(tt->urb[i]);
}
usb_kill_urb(tt->bulk_urb);
usb_free_urb(tt->bulk_urb);
usb_set_intfdata(intf, NULL);
kfree(tt);
}
static int ttusbir_suspend(struct usb_interface *intf, pm_message_t message)
{
struct ttusbir *tt = usb_get_intfdata(intf);
int i;
for (i = 0; i < NUM_URBS; i++)
usb_kill_urb(tt->urb[i]);
led_classdev_suspend(&tt->led);
usb_kill_urb(tt->bulk_urb);
return 0;
}
static int ttusbir_resume(struct usb_interface *intf)
{
struct ttusbir *tt = usb_get_intfdata(intf);
int i, rc;
tt->is_led_on = true;
led_classdev_resume(&tt->led);
for (i = 0; i < NUM_URBS; i++) {
rc = usb_submit_urb(tt->urb[i], GFP_KERNEL);
if (rc) {
dev_warn(tt->dev, "failed to submit urb: %d\n", rc);
break;
}
}
return rc;
}
