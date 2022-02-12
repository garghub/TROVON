static int ni6501_port_command(struct comedi_device *dev, int command,
const u8 *port, u8 *bitmap)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct ni6501_private *devpriv = dev->private;
int request_size, response_size;
u8 *tx = devpriv->usb_tx_buf;
int ret;
if (command != SET_PORT_DIR && !bitmap)
return -EINVAL;
down(&devpriv->sem);
switch (command) {
case READ_PORT:
request_size = sizeof(READ_PORT_REQUEST);
response_size = sizeof(READ_PORT_RESPONSE);
memcpy(tx, READ_PORT_REQUEST, request_size);
tx[14] = port[0];
break;
case WRITE_PORT:
request_size = sizeof(WRITE_PORT_REQUEST);
response_size = sizeof(GENERIC_RESPONSE);
memcpy(tx, WRITE_PORT_REQUEST, request_size);
tx[14] = port[0];
tx[17] = bitmap[0];
break;
case SET_PORT_DIR:
request_size = sizeof(SET_PORT_DIR_REQUEST);
response_size = sizeof(GENERIC_RESPONSE);
memcpy(tx, SET_PORT_DIR_REQUEST, request_size);
tx[14] = port[0];
tx[15] = port[1];
tx[16] = port[2];
break;
default:
ret = -EINVAL;
goto end;
}
ret = usb_bulk_msg(usb,
usb_sndbulkpipe(usb,
devpriv->ep_tx->bEndpointAddress),
devpriv->usb_tx_buf,
request_size,
NULL,
NI6501_TIMEOUT);
if (ret)
goto end;
ret = usb_bulk_msg(usb,
usb_rcvbulkpipe(usb,
devpriv->ep_rx->bEndpointAddress),
devpriv->usb_rx_buf,
response_size,
NULL,
NI6501_TIMEOUT);
if (ret)
goto end;
if (command == READ_PORT) {
bitmap[0] = devpriv->usb_rx_buf[14];
devpriv->usb_rx_buf[14] = 0x00;
if (memcmp(devpriv->usb_rx_buf, READ_PORT_RESPONSE,
sizeof(READ_PORT_RESPONSE))) {
ret = -EINVAL;
}
} else if (memcmp(devpriv->usb_rx_buf, GENERIC_RESPONSE,
sizeof(GENERIC_RESPONSE))) {
ret = -EINVAL;
}
end:
up(&devpriv->sem);
return ret;
}
static int ni6501_counter_command(struct comedi_device *dev, int command,
u32 *val)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct ni6501_private *devpriv = dev->private;
int request_size, response_size;
u8 *tx = devpriv->usb_tx_buf;
int ret;
if ((command == READ_COUNTER || command == WRITE_COUNTER) && !val)
return -EINVAL;
down(&devpriv->sem);
switch (command) {
case START_COUNTER:
request_size = sizeof(START_COUNTER_REQUEST);
response_size = sizeof(GENERIC_RESPONSE);
memcpy(tx, START_COUNTER_REQUEST, request_size);
break;
case STOP_COUNTER:
request_size = sizeof(STOP_COUNTER_REQUEST);
response_size = sizeof(GENERIC_RESPONSE);
memcpy(tx, STOP_COUNTER_REQUEST, request_size);
break;
case READ_COUNTER:
request_size = sizeof(READ_COUNTER_REQUEST);
response_size = sizeof(READ_COUNTER_RESPONSE);
memcpy(tx, READ_COUNTER_REQUEST, request_size);
break;
case WRITE_COUNTER:
request_size = sizeof(WRITE_COUNTER_REQUEST);
response_size = sizeof(GENERIC_RESPONSE);
memcpy(tx, WRITE_COUNTER_REQUEST, request_size);
*((__be32 *)&tx[12]) = cpu_to_be32(*val);
break;
default:
ret = -EINVAL;
goto end;
}
ret = usb_bulk_msg(usb,
usb_sndbulkpipe(usb,
devpriv->ep_tx->bEndpointAddress),
devpriv->usb_tx_buf,
request_size,
NULL,
NI6501_TIMEOUT);
if (ret)
goto end;
ret = usb_bulk_msg(usb,
usb_rcvbulkpipe(usb,
devpriv->ep_rx->bEndpointAddress),
devpriv->usb_rx_buf,
response_size,
NULL,
NI6501_TIMEOUT);
if (ret)
goto end;
if (command == READ_COUNTER) {
int i;
*val = be32_to_cpu(*((__be32 *)&devpriv->usb_rx_buf[12]));
for (i = 12; i < sizeof(READ_COUNTER_RESPONSE); ++i)
devpriv->usb_rx_buf[i] = 0x00;
if (memcmp(devpriv->usb_rx_buf, READ_COUNTER_RESPONSE,
sizeof(READ_COUNTER_RESPONSE))) {
ret = -EINVAL;
}
} else if (memcmp(devpriv->usb_rx_buf, GENERIC_RESPONSE,
sizeof(GENERIC_RESPONSE))) {
ret = -EINVAL;
}
end:
up(&devpriv->sem);
return ret;
}
static int ni6501_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
u8 port[3];
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
port[0] = (s->io_bits) & 0xff;
port[1] = (s->io_bits >> 8) & 0xff;
port[2] = (s->io_bits >> 16) & 0xff;
ret = ni6501_port_command(dev, SET_PORT_DIR, port, NULL);
if (ret)
return ret;
return insn->n;
}
static int ni6501_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask;
int ret;
u8 port;
u8 bitmap;
mask = comedi_dio_update_state(s, data);
for (port = 0; port < 3; port++) {
if (mask & (0xFF << port * 8)) {
bitmap = (s->state >> port * 8) & 0xFF;
ret = ni6501_port_command(dev, WRITE_PORT,
&port, &bitmap);
if (ret)
return ret;
}
}
data[1] = 0;
for (port = 0; port < 3; port++) {
ret = ni6501_port_command(dev, READ_PORT, &port, &bitmap);
if (ret)
return ret;
data[1] |= bitmap << port * 8;
}
return insn->n;
}
static int ni6501_cnt_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
u32 val = 0;
switch (data[0]) {
case INSN_CONFIG_ARM:
ret = ni6501_counter_command(dev, START_COUNTER, NULL);
break;
case INSN_CONFIG_DISARM:
ret = ni6501_counter_command(dev, STOP_COUNTER, NULL);
break;
case INSN_CONFIG_RESET:
ret = ni6501_counter_command(dev, STOP_COUNTER, NULL);
if (ret)
break;
ret = ni6501_counter_command(dev, WRITE_COUNTER, &val);
break;
default:
return -EINVAL;
}
return ret ? ret : insn->n;
}
static int ni6501_cnt_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
u32 val;
unsigned int i;
for (i = 0; i < insn->n; i++) {
ret = ni6501_counter_command(dev, READ_COUNTER, &val);
if (ret)
return ret;
data[i] = val;
}
return insn->n;
}
static int ni6501_cnt_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
if (insn->n) {
u32 val = data[insn->n - 1];
ret = ni6501_counter_command(dev, WRITE_COUNTER, &val);
if (ret)
return ret;
}
return insn->n;
}
static int ni6501_alloc_usb_buffers(struct comedi_device *dev)
{
struct ni6501_private *devpriv = dev->private;
size_t size;
size = le16_to_cpu(devpriv->ep_rx->wMaxPacketSize);
devpriv->usb_rx_buf = kzalloc(size, GFP_KERNEL);
if (!devpriv->usb_rx_buf)
return -ENOMEM;
size = le16_to_cpu(devpriv->ep_tx->wMaxPacketSize);
devpriv->usb_tx_buf = kzalloc(size, GFP_KERNEL);
if (!devpriv->usb_tx_buf) {
kfree(devpriv->usb_rx_buf);
return -ENOMEM;
}
return 0;
}
static int ni6501_find_endpoints(struct comedi_device *dev)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct ni6501_private *devpriv = dev->private;
struct usb_host_interface *iface_desc = intf->cur_altsetting;
struct usb_endpoint_descriptor *ep_desc;
int i;
if (iface_desc->desc.bNumEndpoints != 2) {
dev_err(dev->class_dev, "Wrong number of endpoints\n");
return -ENODEV;
}
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
ep_desc = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_bulk_in(ep_desc)) {
if (!devpriv->ep_rx)
devpriv->ep_rx = ep_desc;
continue;
}
if (usb_endpoint_is_bulk_out(ep_desc)) {
if (!devpriv->ep_tx)
devpriv->ep_tx = ep_desc;
continue;
}
}
if (!devpriv->ep_rx || !devpriv->ep_tx)
return -ENODEV;
return 0;
}
static int ni6501_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct ni6501_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = ni6501_find_endpoints(dev);
if (ret)
return ret;
ret = ni6501_alloc_usb_buffers(dev);
if (ret)
return ret;
sema_init(&devpriv->sem, 1);
usb_set_intfdata(intf, devpriv);
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni6501_dio_insn_bits;
s->insn_config = ni6501_dio_insn_config;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITEABLE | SDF_LSAMPL;
s->n_chan = 1;
s->maxdata = 0xffffffff;
s->insn_read = ni6501_cnt_insn_read;
s->insn_write = ni6501_cnt_insn_write;
s->insn_config = ni6501_cnt_insn_config;
return 0;
}
static void ni6501_detach(struct comedi_device *dev)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct ni6501_private *devpriv = dev->private;
if (!devpriv)
return;
down(&devpriv->sem);
usb_set_intfdata(intf, NULL);
kfree(devpriv->usb_rx_buf);
kfree(devpriv->usb_tx_buf);
up(&devpriv->sem);
}
static int ni6501_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return comedi_usb_auto_config(intf, &ni6501_driver, id->driver_info);
}
