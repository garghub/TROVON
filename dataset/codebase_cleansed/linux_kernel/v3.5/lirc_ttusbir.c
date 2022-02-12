static int set_use_inc(void *data)
{
int i, retval;
struct ttusbir_device *ttusbir = data;
DPRINTK("Sending first URBs\n");
ttusbir->opened = 1;
for (i = 0; i < num_urbs; i++) {
retval = usb_submit_urb(ttusbir->urb[i], GFP_KERNEL);
if (retval) {
dev_err(&ttusbir->interf->dev,
"%s: usb_submit_urb failed on urb %d\n",
__func__, i);
return retval;
}
}
return 0;
}
static void set_use_dec(void *data)
{
struct ttusbir_device *ttusbir = data;
DPRINTK("Device closed\n");
ttusbir->opened = 0;
}
static void urb_complete(struct urb *urb)
{
struct ttusbir_device *ttusbir;
unsigned char *buf;
int i;
int l;
ttusbir = urb->context;
if (!ttusbir->opened)
return;
buf = (unsigned char *)urb->transfer_buffer;
for (i = 0; i < 128; i++) {
buf[i] = ~map_table[buf[i]];
if (ttusbir->last_pulse == buf[i]) {
if (ttusbir->last_num < PULSE_MASK/63)
ttusbir->last_num++;
} else {
l = ttusbir->last_num * 62;
if (ttusbir->last_pulse)
l |= PULSE_BIT;
if (!lirc_buffer_full(&ttusbir->rbuf)) {
lirc_buffer_write(&ttusbir->rbuf, (void *)&l);
wake_up_interruptible(&ttusbir->rbuf.wait_poll);
}
ttusbir->last_num = 0;
ttusbir->last_pulse = buf[i];
}
}
usb_submit_urb(urb, GFP_ATOMIC);
}
static int probe(struct usb_interface *intf, const struct usb_device_id *id)
{
int alt_set, endp;
int found = 0;
int i, j;
int struct_size;
struct usb_host_interface *host_interf;
struct usb_interface_descriptor *interf_desc;
struct usb_host_endpoint *host_endpoint;
struct ttusbir_device *ttusbir;
DPRINTK("Module ttusbir probe\n");
struct_size = sizeof(struct ttusbir_device) +
(sizeof(struct urb *) * num_urbs) +
(sizeof(char *) * num_urbs) +
(num_urbs * 128);
ttusbir = kzalloc(struct_size, GFP_KERNEL);
if (!ttusbir)
return -ENOMEM;
ttusbir->urb = (struct urb **)((char *)ttusbir +
sizeof(struct ttusbir_device));
ttusbir->buffer = (char **)((char *)ttusbir->urb +
(sizeof(struct urb *) * num_urbs));
for (i = 0; i < num_urbs; i++)
ttusbir->buffer[i] = (char *)ttusbir->buffer +
(sizeof(char *)*num_urbs) + (i * 128);
ttusbir->usb_driver = &usb_driver;
ttusbir->alt_setting = -1;
ttusbir->udev = usb_get_dev(interface_to_usbdev(intf));
ttusbir->interf = intf;
ttusbir->last_pulse = 0x00;
ttusbir->last_num = 0;
for (alt_set = 0; alt_set < intf->num_altsetting && !found; alt_set++) {
host_interf = &intf->altsetting[alt_set];
interf_desc = &host_interf->desc;
for (endp = 0; endp < interf_desc->bNumEndpoints; endp++) {
host_endpoint = &host_interf->endpoint[endp];
if ((host_endpoint->desc.bEndpointAddress == 0x82) &&
(host_endpoint->desc.wMaxPacketSize == 0x10)) {
ttusbir->alt_setting = alt_set;
ttusbir->endpoint = endp;
found = 1;
break;
}
}
}
if (ttusbir->alt_setting != -1)
DPRINTK("alt setting: %d\n", ttusbir->alt_setting);
else {
dev_err(&intf->dev, "Could not find alternate setting\n");
kfree(ttusbir);
return -EINVAL;
}
usb_set_interface(ttusbir->udev, 0, ttusbir->alt_setting);
usb_set_intfdata(intf, ttusbir);
if (lirc_buffer_init(&ttusbir->rbuf, sizeof(int), 256) < 0) {
dev_err(&intf->dev, "Could not get memory for LIRC data buffer\n");
usb_set_intfdata(intf, NULL);
kfree(ttusbir);
return -ENOMEM;
}
strcpy(ttusbir->driver.name, "TTUSBIR");
ttusbir->driver.minor = -1;
ttusbir->driver.code_length = 1;
ttusbir->driver.sample_rate = 0;
ttusbir->driver.data = ttusbir;
ttusbir->driver.add_to_buf = NULL;
ttusbir->driver.rbuf = &ttusbir->rbuf;
ttusbir->driver.set_use_inc = set_use_inc;
ttusbir->driver.set_use_dec = set_use_dec;
ttusbir->driver.dev = &intf->dev;
ttusbir->driver.owner = THIS_MODULE;
ttusbir->driver.features = LIRC_CAN_REC_MODE2;
ttusbir->minor = lirc_register_driver(&ttusbir->driver);
if (ttusbir->minor < 0) {
dev_err(&intf->dev, "Error registering as LIRC driver\n");
usb_set_intfdata(intf, NULL);
lirc_buffer_free(&ttusbir->rbuf);
kfree(ttusbir);
return -EIO;
}
for (i = 0; i < num_urbs; i++) {
ttusbir->urb[i] = usb_alloc_urb(8, GFP_KERNEL);
if (!ttusbir->urb[i]) {
dev_err(&intf->dev, "Could not allocate memory for the URB\n");
for (j = i - 1; j >= 0; j--)
kfree(ttusbir->urb[j]);
lirc_buffer_free(&ttusbir->rbuf);
lirc_unregister_driver(ttusbir->minor);
kfree(ttusbir);
usb_set_intfdata(intf, NULL);
return -ENOMEM;
}
ttusbir->urb[i]->dev = ttusbir->udev;
ttusbir->urb[i]->context = ttusbir;
ttusbir->urb[i]->pipe = usb_rcvisocpipe(ttusbir->udev,
ttusbir->endpoint);
ttusbir->urb[i]->interval = 1;
ttusbir->urb[i]->transfer_flags = URB_ISO_ASAP;
ttusbir->urb[i]->transfer_buffer = &ttusbir->buffer[i][0];
ttusbir->urb[i]->complete = urb_complete;
ttusbir->urb[i]->number_of_packets = 8;
ttusbir->urb[i]->transfer_buffer_length = 128;
for (j = 0; j < 8; j++) {
ttusbir->urb[i]->iso_frame_desc[j].offset = j*16;
ttusbir->urb[i]->iso_frame_desc[j].length = 16;
}
}
return 0;
}
static void disconnect(struct usb_interface *intf)
{
int i;
struct ttusbir_device *ttusbir;
DPRINTK("Module ttusbir disconnect\n");
ttusbir = (struct ttusbir_device *) usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
lirc_unregister_driver(ttusbir->minor);
DPRINTK("unregistered\n");
for (i = 0; i < num_urbs; i++) {
usb_kill_urb(ttusbir->urb[i]);
usb_free_urb(ttusbir->urb[i]);
}
DPRINTK("URBs killed\n");
lirc_buffer_free(&ttusbir->rbuf);
kfree(ttusbir);
}
