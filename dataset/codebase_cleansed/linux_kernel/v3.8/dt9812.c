static inline struct usb_dt9812 *to_dt9812_dev(struct kref *d)
{
return container_of(d, struct usb_dt9812, kref);
}
static void dt9812_delete(struct kref *kref)
{
struct usb_dt9812 *dev = to_dt9812_dev(kref);
usb_put_dev(dev->udev);
kfree(dev);
}
static int dt9812_read_info(struct usb_dt9812 *dev, int offset, void *buf,
size_t buf_size)
{
struct dt9812_usb_cmd cmd;
int count, retval;
cmd.cmd = cpu_to_le32(DT9812_R_FLASH_DATA);
cmd.u.flash_data_info.address =
cpu_to_le16(DT9812_DIAGS_BOARD_INFO_ADDR + offset);
cmd.u.flash_data_info.numbytes = cpu_to_le16(buf_size);
count = 32;
retval = usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev,
dev->command_write.addr),
&cmd, 32, &count, HZ * 1);
if (retval)
return retval;
retval = usb_bulk_msg(dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->command_read.addr),
buf, buf_size, &count, HZ * 1);
return retval;
}
static int dt9812_read_multiple_registers(struct usb_dt9812 *dev, int reg_count,
u8 *address, u8 *value)
{
struct dt9812_usb_cmd cmd;
int i, count, retval;
cmd.cmd = cpu_to_le32(DT9812_R_MULTI_BYTE_REG);
cmd.u.read_multi_info.count = reg_count;
for (i = 0; i < reg_count; i++)
cmd.u.read_multi_info.address[i] = address[i];
count = 32;
retval = usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev,
dev->command_write.addr),
&cmd, 32, &count, HZ * 1);
if (retval)
return retval;
retval = usb_bulk_msg(dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->command_read.addr),
value, reg_count, &count, HZ * 1);
return retval;
}
static int dt9812_write_multiple_registers(struct usb_dt9812 *dev,
int reg_count, u8 *address,
u8 *value)
{
struct dt9812_usb_cmd cmd;
int i, count, retval;
cmd.cmd = cpu_to_le32(DT9812_W_MULTI_BYTE_REG);
cmd.u.read_multi_info.count = reg_count;
for (i = 0; i < reg_count; i++) {
cmd.u.write_multi_info.write[i].address = address[i];
cmd.u.write_multi_info.write[i].value = value[i];
}
retval = usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev,
dev->command_write.addr),
&cmd, 32, &count, HZ * 1);
return retval;
}
static int dt9812_rmw_multiple_registers(struct usb_dt9812 *dev, int reg_count,
struct dt9812_rmw_byte *rmw)
{
struct dt9812_usb_cmd cmd;
int i, count, retval;
cmd.cmd = cpu_to_le32(DT9812_RMW_MULTI_BYTE_REG);
cmd.u.rmw_multi_info.count = reg_count;
for (i = 0; i < reg_count; i++)
cmd.u.rmw_multi_info.rmw[i] = rmw[i];
retval = usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev,
dev->command_write.addr),
&cmd, 32, &count, HZ * 1);
return retval;
}
static int dt9812_digital_in(struct slot_dt9812 *slot, u8 *bits)
{
int result = -ENODEV;
down(&slot->mutex);
if (slot->usb) {
u8 reg[2] = { F020_SFR_P3, F020_SFR_P1 };
u8 value[2];
result = dt9812_read_multiple_registers(slot->usb, 2, reg,
value);
if (result == 0) {
*bits = (value[0] & 0x7f) | ((value[1] & 0x08) << 4);
}
}
up(&slot->mutex);
return result;
}
static int dt9812_digital_out(struct slot_dt9812 *slot, u8 bits)
{
int result = -ENODEV;
down(&slot->mutex);
if (slot->usb) {
u8 reg[1];
u8 value[1];
reg[0] = F020_SFR_P2;
value[0] = bits;
result = dt9812_write_multiple_registers(slot->usb, 1, reg,
value);
slot->usb->digital_out_shadow = bits;
}
up(&slot->mutex);
return result;
}
static int dt9812_digital_out_shadow(struct slot_dt9812 *slot, u8 *bits)
{
int result = -ENODEV;
down(&slot->mutex);
if (slot->usb) {
*bits = slot->usb->digital_out_shadow;
result = 0;
}
up(&slot->mutex);
return result;
}
static void dt9812_configure_mux(struct usb_dt9812 *dev,
struct dt9812_rmw_byte *rmw, int channel)
{
if (dev->device == DT9812_DEVID_DT9812_10) {
rmw->address = F020_SFR_P1;
rmw->and_mask = 0xe0;
rmw->or_value = channel << 5;
} else {
rmw->address = F020_SFR_AMX0SL;
rmw->and_mask = 0xff;
rmw->or_value = channel & 0x07;
}
}
static void dt9812_configure_gain(struct usb_dt9812 *dev,
struct dt9812_rmw_byte *rmw,
enum dt9812_gain gain)
{
if (dev->device == DT9812_DEVID_DT9812_10) {
gain <<= 1;
}
rmw->address = F020_SFR_ADC0CF;
rmw->and_mask = F020_MASK_ADC0CF_AMP0GN2 |
F020_MASK_ADC0CF_AMP0GN1 | F020_MASK_ADC0CF_AMP0GN0;
switch (gain) {
case DT9812_GAIN_0PT5:
rmw->or_value = F020_MASK_ADC0CF_AMP0GN2 |
F020_MASK_ADC0CF_AMP0GN1;
break;
case DT9812_GAIN_1:
rmw->or_value = 0x00;
break;
case DT9812_GAIN_2:
rmw->or_value = F020_MASK_ADC0CF_AMP0GN0;
break;
case DT9812_GAIN_4:
rmw->or_value = F020_MASK_ADC0CF_AMP0GN1;
break;
case DT9812_GAIN_8:
rmw->or_value = F020_MASK_ADC0CF_AMP0GN1 |
F020_MASK_ADC0CF_AMP0GN0;
break;
case DT9812_GAIN_16:
rmw->or_value = F020_MASK_ADC0CF_AMP0GN2;
break;
default:
dev_err(&dev->interface->dev, "Illegal gain %d\n", gain);
}
}
static int dt9812_analog_in(struct slot_dt9812 *slot, int channel, u16 *value,
enum dt9812_gain gain)
{
struct dt9812_rmw_byte rmw[3];
u8 reg[3] = {
F020_SFR_ADC0CN,
F020_SFR_ADC0H,
F020_SFR_ADC0L
};
u8 val[3];
int result = -ENODEV;
down(&slot->mutex);
if (!slot->usb)
goto exit;
dt9812_configure_gain(slot->usb, &rmw[0], gain);
dt9812_configure_mux(slot->usb, &rmw[1], channel);
rmw[2].address = F020_SFR_ADC0CN;
rmw[2].and_mask = 0xff;
rmw[2].or_value = F020_MASK_ADC0CN_AD0EN | F020_MASK_ADC0CN_AD0BUSY;
result = dt9812_rmw_multiple_registers(slot->usb, 3, rmw);
if (result)
goto exit;
result = dt9812_read_multiple_registers(slot->usb, 3, reg, val);
if (result)
goto exit;
if ((val[0] & (F020_MASK_ADC0CN_AD0INT | F020_MASK_ADC0CN_AD0BUSY)) ==
F020_MASK_ADC0CN_AD0INT) {
switch (slot->usb->device) {
case DT9812_DEVID_DT9812_10:
*value = ((val[1] << 8) | val[2]) + 0x800;
break;
case DT9812_DEVID_DT9812_2PT5:
*value = (val[1] << 8) | val[2];
break;
}
}
exit:
up(&slot->mutex);
return result;
}
static int dt9812_analog_out_shadow(struct slot_dt9812 *slot, int channel,
u16 *value)
{
int result = -ENODEV;
down(&slot->mutex);
if (slot->usb) {
*value = slot->usb->analog_out_shadow[channel];
result = 0;
}
up(&slot->mutex);
return result;
}
static int dt9812_analog_out(struct slot_dt9812 *slot, int channel, u16 value)
{
int result = -ENODEV;
down(&slot->mutex);
if (slot->usb) {
struct dt9812_rmw_byte rmw[3];
switch (channel) {
case 0:
rmw[0].address = F020_SFR_DAC0CN;
rmw[0].and_mask = 0xff;
rmw[0].or_value = F020_MASK_DACxCN_DACxEN;
rmw[1].address = F020_SFR_DAC0L;
rmw[1].and_mask = 0xff;
rmw[1].or_value = value & 0xff;
rmw[2].address = F020_SFR_DAC0H;
rmw[2].and_mask = 0xff;
rmw[2].or_value = (value >> 8) & 0xf;
break;
case 1:
rmw[0].address = F020_SFR_DAC1CN;
rmw[0].and_mask = 0xff;
rmw[0].or_value = F020_MASK_DACxCN_DACxEN;
rmw[1].address = F020_SFR_DAC1L;
rmw[1].and_mask = 0xff;
rmw[1].or_value = value & 0xff;
rmw[2].address = F020_SFR_DAC1H;
rmw[2].and_mask = 0xff;
rmw[2].or_value = (value >> 8) & 0xf;
break;
}
result = dt9812_rmw_multiple_registers(slot->usb, 3, rmw);
slot->usb->analog_out_shadow[channel] = value;
}
up(&slot->mutex);
return result;
}
static int dt9812_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
int retval = -ENOMEM;
struct usb_dt9812 *dev = NULL;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i;
u8 fw;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "Out of memory\n");
goto error;
}
kref_init(&dev->kref);
dev->udev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
iface_desc = interface->cur_altsetting;
if (iface_desc->desc.bNumEndpoints != 5) {
dev_err(&interface->dev, "Wrong number of endpoints.\n");
retval = -ENODEV;
goto error;
}
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
int direction = -1;
endpoint = &iface_desc->endpoint[i].desc;
switch (i) {
case 0:
direction = USB_DIR_IN;
dev->message_pipe.addr = endpoint->bEndpointAddress;
dev->message_pipe.size =
le16_to_cpu(endpoint->wMaxPacketSize);
break;
case 1:
direction = USB_DIR_OUT;
dev->command_write.addr = endpoint->bEndpointAddress;
dev->command_write.size =
le16_to_cpu(endpoint->wMaxPacketSize);
break;
case 2:
direction = USB_DIR_IN;
dev->command_read.addr = endpoint->bEndpointAddress;
dev->command_read.size =
le16_to_cpu(endpoint->wMaxPacketSize);
break;
case 3:
direction = USB_DIR_OUT;
dev->write_stream.addr = endpoint->bEndpointAddress;
dev->write_stream.size =
le16_to_cpu(endpoint->wMaxPacketSize);
break;
case 4:
direction = USB_DIR_IN;
dev->read_stream.addr = endpoint->bEndpointAddress;
dev->read_stream.size =
le16_to_cpu(endpoint->wMaxPacketSize);
break;
}
if ((endpoint->bEndpointAddress & USB_DIR_IN) != direction) {
dev_err(&interface->dev,
"Endpoint has wrong direction.\n");
retval = -ENODEV;
goto error;
}
}
if (dt9812_read_info(dev, 0, &fw, sizeof(fw)) != 0) {
usb_reset_configuration(dev->udev);
for (i = 0; i < 10; i++) {
retval = dt9812_read_info(dev, 1, &fw, sizeof(fw));
if (retval == 0) {
dev_info(&interface->dev,
"usb_reset_configuration succeeded "
"after %d iterations\n", i);
break;
}
}
}
if (dt9812_read_info(dev, 1, &dev->vendor, sizeof(dev->vendor)) != 0) {
dev_err(&interface->dev, "Failed to read vendor.\n");
retval = -ENODEV;
goto error;
}
if (dt9812_read_info(dev, 3, &dev->product, sizeof(dev->product)) != 0) {
dev_err(&interface->dev, "Failed to read product.\n");
retval = -ENODEV;
goto error;
}
if (dt9812_read_info(dev, 5, &dev->device, sizeof(dev->device)) != 0) {
dev_err(&interface->dev, "Failed to read device.\n");
retval = -ENODEV;
goto error;
}
if (dt9812_read_info(dev, 7, &dev->serial, sizeof(dev->serial)) != 0) {
dev_err(&interface->dev, "Failed to read serial.\n");
retval = -ENODEV;
goto error;
}
dev->vendor = le16_to_cpu(dev->vendor);
dev->product = le16_to_cpu(dev->product);
dev->device = le16_to_cpu(dev->device);
dev->serial = le32_to_cpu(dev->serial);
switch (dev->device) {
case DT9812_DEVID_DT9812_10:
dev->analog_out_shadow[0] = 0x0800;
dev->analog_out_shadow[1] = 0x800;
break;
case DT9812_DEVID_DT9812_2PT5:
dev->analog_out_shadow[0] = 0x0000;
dev->analog_out_shadow[1] = 0x0000;
break;
}
dev->digital_out_shadow = 0;
usb_set_intfdata(interface, dev);
dev_info(&interface->dev, "USB DT9812 (%4.4x.%4.4x.%4.4x) #0x%8.8x\n",
dev->vendor, dev->product, dev->device, dev->serial);
down(&dt9812_mutex);
{
struct slot_dt9812 *first = NULL;
struct slot_dt9812 *best = NULL;
for (i = 0; i < DT9812_NUM_SLOTS; i++) {
if (!first && !dt9812[i].usb && dt9812[i].serial == 0)
first = &dt9812[i];
if (!best && dt9812[i].serial == dev->serial)
best = &dt9812[i];
}
if (!best)
best = first;
if (best) {
down(&best->mutex);
best->usb = dev;
dev->slot = best;
up(&best->mutex);
}
}
up(&dt9812_mutex);
return 0;
error:
if (dev)
kref_put(&dev->kref, dt9812_delete);
return retval;
}
static void dt9812_disconnect(struct usb_interface *interface)
{
struct usb_dt9812 *dev;
int minor = interface->minor;
down(&dt9812_mutex);
dev = usb_get_intfdata(interface);
if (dev->slot) {
down(&dev->slot->mutex);
dev->slot->usb = NULL;
up(&dev->slot->mutex);
dev->slot = NULL;
}
usb_set_intfdata(interface, NULL);
up(&dt9812_mutex);
kref_put(&dev->kref, dt9812_delete);
dev_info(&interface->dev, "USB Dt9812 #%d now disconnected\n", minor);
}
static int dt9812_comedi_open(struct comedi_device *dev)
{
struct comedi_dt9812 *devpriv = dev->private;
int result = -ENODEV;
down(&devpriv->slot->mutex);
if (devpriv->slot->usb) {
struct comedi_subdevice *s;
s = &dev->subdevices[0];
s->n_chan = 8;
s->maxdata = 1;
s = &dev->subdevices[1];
s->n_chan = 8;
s->maxdata = 1;
s = &dev->subdevices[2];
s->n_chan = 8;
switch (devpriv->slot->usb->device) {
case 0:{
s->maxdata = 4095;
s->range_table = &dt9812_10_ain_range;
}
break;
case 1:{
s->maxdata = 4095;
s->range_table = &dt9812_2pt5_ain_range;
}
break;
}
s = &dev->subdevices[3];
s->n_chan = 2;
switch (devpriv->slot->usb->device) {
case 0:{
s->maxdata = 4095;
s->range_table = &dt9812_10_aout_range;
}
break;
case 1:{
s->maxdata = 4095;
s->range_table = &dt9812_2pt5_aout_range;
}
break;
}
result = 0;
}
up(&devpriv->slot->mutex);
return result;
}
static int dt9812_di_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_dt9812 *devpriv = dev->private;
int n;
u8 bits = 0;
dt9812_digital_in(devpriv->slot, &bits);
for (n = 0; n < insn->n; n++)
data[n] = ((1 << insn->chanspec) & bits) != 0;
return n;
}
static int dt9812_do_winsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_dt9812 *devpriv = dev->private;
int n;
u8 bits = 0;
dt9812_digital_out_shadow(devpriv->slot, &bits);
for (n = 0; n < insn->n; n++) {
u8 mask = 1 << insn->chanspec;
bits &= ~mask;
if (data[n])
bits |= mask;
}
dt9812_digital_out(devpriv->slot, bits);
return n;
}
static int dt9812_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_dt9812 *devpriv = dev->private;
int n;
for (n = 0; n < insn->n; n++) {
u16 value = 0;
dt9812_analog_in(devpriv->slot, insn->chanspec, &value,
DT9812_GAIN_1);
data[n] = value;
}
return n;
}
static int dt9812_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_dt9812 *devpriv = dev->private;
int n;
u16 value;
for (n = 0; n < insn->n; n++) {
value = 0;
dt9812_analog_out_shadow(devpriv->slot, insn->chanspec, &value);
data[n] = value;
}
return n;
}
static int dt9812_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_dt9812 *devpriv = dev->private;
int n;
for (n = 0; n < insn->n; n++)
dt9812_analog_out(devpriv->slot, insn->chanspec, data[n]);
return n;
}
static int dt9812_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_dt9812 *devpriv;
int i;
struct comedi_subdevice *s;
int ret;
dev->board_name = "dt9812";
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
dev->open = dt9812_comedi_open;
devpriv->serial = it->options[0];
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_read = &dt9812_di_rinsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_write = &dt9812_do_winsn;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = NULL;
s->insn_read = &dt9812_ai_rinsn;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = NULL;
s->insn_write = &dt9812_ao_winsn;
s->insn_read = &dt9812_ao_rinsn;
dev_info(dev->class_dev, "successfully attached to dt9812.\n");
down(&dt9812_mutex);
{
struct slot_dt9812 *first = NULL;
struct slot_dt9812 *best = NULL;
for (i = 0; i < DT9812_NUM_SLOTS; i++) {
if (!first && !dt9812[i].comedi) {
first = &dt9812[i];
}
if (!best &&
dt9812[i].usb &&
dt9812[i].usb->serial == devpriv->serial) {
best = &dt9812[i];
}
}
if (!best)
best = first;
if (best) {
down(&best->mutex);
best->comedi = devpriv;
best->serial = devpriv->serial;
devpriv->slot = best;
up(&best->mutex);
}
}
up(&dt9812_mutex);
return 0;
}
static void dt9812_detach(struct comedi_device *dev)
{
}
static int __init usb_dt9812_init(void)
{
int result, i;
for (i = 0; i < DT9812_NUM_SLOTS; i++) {
sema_init(&dt9812[i].mutex, 1);
dt9812[i].serial = 0;
dt9812[i].usb = NULL;
dt9812[i].comedi = NULL;
}
dt9812[12].serial = 0x0;
result = usb_register(&dt9812_usb_driver);
if (result) {
pr_err("usb_register failed. Error number %d\n", result);
return result;
}
result = comedi_driver_register(&dt9812_comedi_driver);
if (result) {
usb_deregister(&dt9812_usb_driver);
pr_err("comedi_driver_register failed. Error number %d\n",
result);
}
return result;
}
static void __exit usb_dt9812_exit(void)
{
comedi_driver_unregister(&dt9812_comedi_driver);
usb_deregister(&dt9812_usb_driver);
}
