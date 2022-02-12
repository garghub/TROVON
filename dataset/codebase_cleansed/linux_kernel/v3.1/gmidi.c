static int config_buf(struct usb_gadget *gadget,
u8 *buf, u8 type, unsigned index)
{
int len;
if (index != 0) {
return -EINVAL;
}
len = usb_gadget_config_buf(&config_desc,
buf, USB_BUFSIZ, gmidi_function);
if (len < 0) {
return len;
}
((struct usb_config_descriptor *)buf)->bDescriptorType = type;
return len;
}
static struct usb_request *alloc_ep_req(struct usb_ep *ep, unsigned length)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req) {
req->length = length;
req->buf = kmalloc(length, GFP_ATOMIC);
if (!req->buf) {
usb_ep_free_request(ep, req);
req = NULL;
}
}
return req;
}
static void free_ep_req(struct usb_ep *ep, struct usb_request *req)
{
kfree(req->buf);
usb_ep_free_request(ep, req);
}
static void gmidi_read_data(struct usb_ep *ep, int cable,
uint8_t *data, int length)
{
struct gmidi_device *dev = ep->driver_data;
if (!dev->out_substream) {
return;
}
if (!test_bit(dev->out_substream->number, &dev->out_triggered)) {
return;
}
snd_rawmidi_receive(dev->out_substream, data, length);
}
static void gmidi_handle_out_data(struct usb_ep *ep, struct usb_request *req)
{
unsigned i;
u8 *buf = req->buf;
for (i = 0; i + 3 < req->actual; i += 4) {
if (buf[i] != 0) {
int cable = buf[i] >> 4;
int length = gmidi_cin_length[buf[i] & 0x0f];
gmidi_read_data(ep, cable, &buf[i + 1], length);
}
}
}
static void gmidi_complete(struct usb_ep *ep, struct usb_request *req)
{
struct gmidi_device *dev = ep->driver_data;
int status = req->status;
switch (status) {
case 0:
if (ep == dev->out_ep) {
gmidi_handle_out_data(ep, req);
} else if (ep == dev->in_ep) {
gmidi_transmit(dev, req);
return;
}
break;
case -ECONNABORTED:
case -ECONNRESET:
case -ESHUTDOWN:
VDBG(dev, "%s gone (%d), %d/%d\n", ep->name, status,
req->actual, req->length);
if (ep == dev->out_ep) {
gmidi_handle_out_data(ep, req);
}
free_ep_req(ep, req);
return;
case -EOVERFLOW:
default:
DBG(dev, "%s complete --> %d, %d/%d\n", ep->name,
status, req->actual, req->length);
break;
case -EREMOTEIO:
break;
}
status = usb_ep_queue(ep, req, GFP_ATOMIC);
if (status) {
ERROR(dev, "kill %s: resubmit %d bytes --> %d\n",
ep->name, req->length, status);
usb_ep_set_halt(ep);
}
}
static int set_gmidi_config(struct gmidi_device *dev, gfp_t gfp_flags)
{
int err = 0;
struct usb_request *req;
struct usb_ep *ep;
unsigned i;
dev->in_ep->desc = &bulk_in_desc;
err = usb_ep_enable(dev->in_ep);
if (err) {
ERROR(dev, "can't start %s: %d\n", dev->in_ep->name, err);
goto fail;
}
dev->in_ep->driver_data = dev;
dev->out_ep->desc = &bulk_out_desc;
err = usb_ep_enable(dev->out_ep);
if (err) {
ERROR(dev, "can't start %s: %d\n", dev->out_ep->name, err);
goto fail;
}
dev->out_ep->driver_data = dev;
ep = dev->out_ep;
for (i = 0; i < qlen && err == 0; i++) {
req = alloc_ep_req(ep, buflen);
if (req) {
req->complete = gmidi_complete;
err = usb_ep_queue(ep, req, GFP_ATOMIC);
if (err) {
DBG(dev, "%s queue req: %d\n", ep->name, err);
}
} else {
err = -ENOMEM;
}
}
fail:
return err;
}
static void gmidi_reset_config(struct gmidi_device *dev)
{
if (dev->config == 0) {
return;
}
DBG(dev, "reset config\n");
usb_ep_disable(dev->in_ep);
usb_ep_disable(dev->out_ep);
dev->config = 0;
}
static int
gmidi_set_config(struct gmidi_device *dev, unsigned number, gfp_t gfp_flags)
{
int result = 0;
struct usb_gadget *gadget = dev->gadget;
#if 0
if (number == dev->config) {
return 0;
}
#endif
gmidi_reset_config(dev);
switch (number) {
case GMIDI_CONFIG:
result = set_gmidi_config(dev, gfp_flags);
break;
default:
result = -EINVAL;
case 0:
return result;
}
if (!result && (!dev->in_ep || !dev->out_ep)) {
result = -ENODEV;
}
if (result) {
gmidi_reset_config(dev);
} else {
char *speed;
switch (gadget->speed) {
case USB_SPEED_LOW: speed = "low"; break;
case USB_SPEED_FULL: speed = "full"; break;
case USB_SPEED_HIGH: speed = "high"; break;
default: speed = "?"; break;
}
dev->config = number;
INFO(dev, "%s speed\n", speed);
}
return result;
}
static void gmidi_setup_complete(struct usb_ep *ep, struct usb_request *req)
{
if (req->status || req->actual != req->length) {
DBG((struct gmidi_device *) ep->driver_data,
"setup complete --> %d, %d/%d\n",
req->status, req->actual, req->length);
}
}
static int gmidi_setup(struct usb_gadget *gadget,
const struct usb_ctrlrequest *ctrl)
{
struct gmidi_device *dev = get_gadget_data(gadget);
struct usb_request *req = dev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
req->zero = 0;
switch (ctrl->bRequest) {
case USB_REQ_GET_DESCRIPTOR:
if (ctrl->bRequestType != USB_DIR_IN) {
goto unknown;
}
switch (w_value >> 8) {
case USB_DT_DEVICE:
device_desc.bMaxPacketSize0 = gadget->ep0->maxpacket;
value = min(w_length, (u16) sizeof(device_desc));
memcpy(req->buf, &device_desc, value);
break;
case USB_DT_CONFIG:
value = config_buf(gadget, req->buf,
w_value >> 8,
w_value & 0xff);
if (value >= 0) {
value = min(w_length, (u16)value);
}
break;
case USB_DT_STRING:
value = usb_gadget_get_string(&stringtab,
w_value & 0xff, req->buf);
if (value >= 0) {
value = min(w_length, (u16)value);
}
break;
}
break;
case USB_REQ_SET_CONFIGURATION:
if (ctrl->bRequestType != 0) {
goto unknown;
}
if (gadget->a_hnp_support) {
DBG(dev, "HNP available\n");
} else if (gadget->a_alt_hnp_support) {
DBG(dev, "HNP needs a different root port\n");
} else {
VDBG(dev, "HNP inactive\n");
}
spin_lock(&dev->lock);
value = gmidi_set_config(dev, w_value, GFP_ATOMIC);
spin_unlock(&dev->lock);
break;
case USB_REQ_GET_CONFIGURATION:
if (ctrl->bRequestType != USB_DIR_IN) {
goto unknown;
}
*(u8 *)req->buf = dev->config;
value = min(w_length, (u16)1);
break;
case USB_REQ_SET_INTERFACE:
if (ctrl->bRequestType != USB_RECIP_INTERFACE) {
goto unknown;
}
spin_lock(&dev->lock);
if (dev->config && w_index < GMIDI_NUM_INTERFACES
&& w_value == 0)
{
u8 config = dev->config;
gmidi_reset_config(dev);
gmidi_set_config(dev, config, GFP_ATOMIC);
value = 0;
}
spin_unlock(&dev->lock);
break;
case USB_REQ_GET_INTERFACE:
if (ctrl->bRequestType != (USB_DIR_IN|USB_RECIP_INTERFACE)) {
goto unknown;
}
if (!dev->config) {
break;
}
if (w_index >= GMIDI_NUM_INTERFACES) {
value = -EDOM;
break;
}
*(u8 *)req->buf = 0;
value = min(w_length, (u16)1);
break;
default:
unknown:
VDBG(dev, "unknown control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
req->length = value;
req->zero = value < w_length;
value = usb_ep_queue(gadget->ep0, req, GFP_ATOMIC);
if (value < 0) {
DBG(dev, "ep_queue --> %d\n", value);
req->status = 0;
gmidi_setup_complete(gadget->ep0, req);
}
}
return value;
}
static void gmidi_disconnect(struct usb_gadget *gadget)
{
struct gmidi_device *dev = get_gadget_data(gadget);
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
gmidi_reset_config(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
static void gmidi_unbind(struct usb_gadget *gadget)
{
struct gmidi_device *dev = get_gadget_data(gadget);
struct snd_card *card;
DBG(dev, "unbind\n");
card = dev->card;
dev->card = NULL;
if (card) {
snd_card_free(card);
}
if (dev->req) {
dev->req->length = USB_BUFSIZ;
free_ep_req(gadget->ep0, dev->req);
}
kfree(dev);
set_gadget_data(gadget, NULL);
}
static int gmidi_snd_free(struct snd_device *device)
{
return 0;
}
static void gmidi_transmit_packet(struct usb_request *req, uint8_t p0,
uint8_t p1, uint8_t p2, uint8_t p3)
{
unsigned length = req->length;
u8 *buf = (u8 *)req->buf + length;
buf[0] = p0;
buf[1] = p1;
buf[2] = p2;
buf[3] = p3;
req->length = length + 4;
}
static void gmidi_transmit_byte(struct usb_request *req,
struct gmidi_in_port *port, uint8_t b)
{
uint8_t p0 = port->cable;
if (b >= 0xf8) {
gmidi_transmit_packet(req, p0 | 0x0f, b, 0, 0);
} else if (b >= 0xf0) {
switch (b) {
case 0xf0:
port->data[0] = b;
port->state = STATE_SYSEX_1;
break;
case 0xf1:
case 0xf3:
port->data[0] = b;
port->state = STATE_1PARAM;
break;
case 0xf2:
port->data[0] = b;
port->state = STATE_2PARAM_1;
break;
case 0xf4:
case 0xf5:
port->state = STATE_UNKNOWN;
break;
case 0xf6:
gmidi_transmit_packet(req, p0 | 0x05, 0xf6, 0, 0);
port->state = STATE_UNKNOWN;
break;
case 0xf7:
switch (port->state) {
case STATE_SYSEX_0:
gmidi_transmit_packet(req,
p0 | 0x05, 0xf7, 0, 0);
break;
case STATE_SYSEX_1:
gmidi_transmit_packet(req,
p0 | 0x06, port->data[0], 0xf7, 0);
break;
case STATE_SYSEX_2:
gmidi_transmit_packet(req,
p0 | 0x07, port->data[0],
port->data[1], 0xf7);
break;
}
port->state = STATE_UNKNOWN;
break;
}
} else if (b >= 0x80) {
port->data[0] = b;
if (b >= 0xc0 && b <= 0xdf)
port->state = STATE_1PARAM;
else
port->state = STATE_2PARAM_1;
} else {
switch (port->state) {
case STATE_1PARAM:
if (port->data[0] < 0xf0) {
p0 |= port->data[0] >> 4;
} else {
p0 |= 0x02;
port->state = STATE_UNKNOWN;
}
gmidi_transmit_packet(req, p0, port->data[0], b, 0);
break;
case STATE_2PARAM_1:
port->data[1] = b;
port->state = STATE_2PARAM_2;
break;
case STATE_2PARAM_2:
if (port->data[0] < 0xf0) {
p0 |= port->data[0] >> 4;
port->state = STATE_2PARAM_1;
} else {
p0 |= 0x03;
port->state = STATE_UNKNOWN;
}
gmidi_transmit_packet(req,
p0, port->data[0], port->data[1], b);
break;
case STATE_SYSEX_0:
port->data[0] = b;
port->state = STATE_SYSEX_1;
break;
case STATE_SYSEX_1:
port->data[1] = b;
port->state = STATE_SYSEX_2;
break;
case STATE_SYSEX_2:
gmidi_transmit_packet(req,
p0 | 0x04, port->data[0], port->data[1], b);
port->state = STATE_SYSEX_0;
break;
}
}
}
static void gmidi_transmit(struct gmidi_device *dev, struct usb_request *req)
{
struct usb_ep *ep = dev->in_ep;
struct gmidi_in_port *port = &dev->in_port;
if (!ep) {
return;
}
if (!req) {
req = alloc_ep_req(ep, buflen);
}
if (!req) {
ERROR(dev, "gmidi_transmit: alloc_ep_request failed\n");
return;
}
req->length = 0;
req->complete = gmidi_complete;
if (port->active) {
while (req->length + 3 < buflen) {
uint8_t b;
if (snd_rawmidi_transmit(dev->in_substream, &b, 1)
!= 1)
{
port->active = 0;
break;
}
gmidi_transmit_byte(req, port, b);
}
}
if (req->length > 0) {
usb_ep_queue(ep, req, GFP_ATOMIC);
} else {
free_ep_req(ep, req);
}
}
static void gmidi_in_tasklet(unsigned long data)
{
struct gmidi_device *dev = (struct gmidi_device *)data;
gmidi_transmit(dev, NULL);
}
static int gmidi_in_open(struct snd_rawmidi_substream *substream)
{
struct gmidi_device *dev = substream->rmidi->private_data;
VDBG(dev, "gmidi_in_open\n");
dev->in_substream = substream;
dev->in_port.state = STATE_UNKNOWN;
return 0;
}
static int gmidi_in_close(struct snd_rawmidi_substream *substream)
{
struct gmidi_device *dev = substream->rmidi->private_data;
VDBG(dev, "gmidi_in_close\n");
return 0;
}
static void gmidi_in_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct gmidi_device *dev = substream->rmidi->private_data;
VDBG(dev, "gmidi_in_trigger %d\n", up);
dev->in_port.active = up;
if (up) {
tasklet_hi_schedule(&dev->tasklet);
}
}
static int gmidi_out_open(struct snd_rawmidi_substream *substream)
{
struct gmidi_device *dev = substream->rmidi->private_data;
VDBG(dev, "gmidi_out_open\n");
dev->out_substream = substream;
return 0;
}
static int gmidi_out_close(struct snd_rawmidi_substream *substream)
{
struct gmidi_device *dev = substream->rmidi->private_data;
VDBG(dev, "gmidi_out_close\n");
return 0;
}
static void gmidi_out_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct gmidi_device *dev = substream->rmidi->private_data;
VDBG(dev, "gmidi_out_trigger %d\n", up);
if (up) {
set_bit(substream->number, &dev->out_triggered);
} else {
clear_bit(substream->number, &dev->out_triggered);
}
}
static int gmidi_register_card(struct gmidi_device *dev)
{
struct snd_card *card;
struct snd_rawmidi *rmidi;
int err;
int out_ports = 1;
int in_ports = 1;
static struct snd_device_ops ops = {
.dev_free = gmidi_snd_free,
};
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0) {
ERROR(dev, "snd_card_create failed\n");
goto fail;
}
dev->card = card;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, dev, &ops);
if (err < 0) {
ERROR(dev, "snd_device_new failed: error %d\n", err);
goto fail;
}
strcpy(card->driver, longname);
strcpy(card->longname, longname);
strcpy(card->shortname, shortname);
dev->in_port.dev = dev;
dev->in_port.active = 0;
snd_component_add(card, "MIDI");
err = snd_rawmidi_new(card, "USB MIDI Gadget", 0,
out_ports, in_ports, &rmidi);
if (err < 0) {
ERROR(dev, "snd_rawmidi_new failed: error %d\n", err);
goto fail;
}
dev->rmidi = rmidi;
strcpy(rmidi->name, card->shortname);
rmidi->info_flags = SNDRV_RAWMIDI_INFO_OUTPUT |
SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
rmidi->private_data = dev;
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &gmidi_in_ops);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &gmidi_out_ops);
snd_card_set_dev(card, &dev->gadget->dev);
err = snd_card_register(card);
if (err < 0) {
ERROR(dev, "snd_card_register failed\n");
goto fail;
}
VDBG(dev, "gmidi_register_card finished ok\n");
return 0;
fail:
if (dev->card) {
snd_card_free(dev->card);
dev->card = NULL;
}
return err;
}
static int __init gmidi_bind(struct usb_gadget *gadget)
{
struct gmidi_device *dev;
struct usb_ep *in_ep, *out_ep;
int gcnum, err = 0;
if (idVendor) {
if (!idProduct) {
pr_err("idVendor needs idProduct!\n");
return -ENODEV;
}
device_desc.idVendor = cpu_to_le16(idVendor);
device_desc.idProduct = cpu_to_le16(idProduct);
if (bcdDevice) {
device_desc.bcdDevice = cpu_to_le16(bcdDevice);
}
}
if (iManufacturer) {
strlcpy(manufacturer, iManufacturer, sizeof(manufacturer));
} else {
snprintf(manufacturer, sizeof(manufacturer), "%s %s with %s",
init_utsname()->sysname, init_utsname()->release,
gadget->name);
}
if (iProduct) {
strlcpy(product_desc, iProduct, sizeof(product_desc));
}
if (iSerialNumber) {
device_desc.iSerialNumber = STRING_SERIAL,
strlcpy(serial_number, iSerialNumber, sizeof(serial_number));
}
usb_ep_autoconfig_reset(gadget);
in_ep = usb_ep_autoconfig(gadget, &bulk_in_desc);
if (!in_ep) {
autoconf_fail:
pr_err("%s: can't autoconfigure on %s\n",
shortname, gadget->name);
return -ENODEV;
}
EP_IN_NAME = in_ep->name;
in_ep->driver_data = in_ep;
out_ep = usb_ep_autoconfig(gadget, &bulk_out_desc);
if (!out_ep) {
goto autoconf_fail;
}
EP_OUT_NAME = out_ep->name;
out_ep->driver_data = out_ep;
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0) {
device_desc.bcdDevice = cpu_to_le16(0x0200 + gcnum);
} else {
pr_warning("%s: controller '%s' not recognized\n",
shortname, gadget->name);
device_desc.bcdDevice = cpu_to_le16(0x9999);
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
return -ENOMEM;
}
spin_lock_init(&dev->lock);
dev->gadget = gadget;
dev->in_ep = in_ep;
dev->out_ep = out_ep;
set_gadget_data(gadget, dev);
tasklet_init(&dev->tasklet, gmidi_in_tasklet, (unsigned long)dev);
dev->req = alloc_ep_req(gadget->ep0, USB_BUFSIZ);
if (!dev->req) {
err = -ENOMEM;
goto fail;
}
dev->req->complete = gmidi_setup_complete;
gadget->ep0->driver_data = dev;
INFO(dev, "%s, version: " DRIVER_VERSION "\n", longname);
INFO(dev, "using %s, OUT %s IN %s\n", gadget->name,
EP_OUT_NAME, EP_IN_NAME);
err = gmidi_register_card(dev);
if (err < 0) {
goto fail;
}
VDBG(dev, "gmidi_bind finished ok\n");
return 0;
fail:
gmidi_unbind(gadget);
return err;
}
static void gmidi_suspend(struct usb_gadget *gadget)
{
struct gmidi_device *dev = get_gadget_data(gadget);
if (gadget->speed == USB_SPEED_UNKNOWN) {
return;
}
DBG(dev, "suspend\n");
}
static void gmidi_resume(struct usb_gadget *gadget)
{
struct gmidi_device *dev = get_gadget_data(gadget);
DBG(dev, "resume\n");
}
static int __init gmidi_init(void)
{
return usb_gadget_probe_driver(&gmidi_driver, gmidi_bind);
}
static void __exit gmidi_cleanup(void)
{
usb_gadget_unregister_driver(&gmidi_driver);
}
