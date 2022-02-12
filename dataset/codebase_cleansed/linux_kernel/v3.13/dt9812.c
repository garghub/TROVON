static int dt9812_read_info(struct comedi_device *dev,
int offset, void *buf, size_t buf_size)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct dt9812_private *devpriv = dev->private;
struct dt9812_usb_cmd cmd;
int count, ret;
cmd.cmd = cpu_to_le32(DT9812_R_FLASH_DATA);
cmd.u.flash_data_info.address =
cpu_to_le16(DT9812_DIAGS_BOARD_INFO_ADDR + offset);
cmd.u.flash_data_info.numbytes = cpu_to_le16(buf_size);
ret = usb_bulk_msg(usb, usb_sndbulkpipe(usb, devpriv->cmd_wr.addr),
&cmd, 32, &count, DT9812_USB_TIMEOUT);
if (ret)
return ret;
return usb_bulk_msg(usb, usb_rcvbulkpipe(usb, devpriv->cmd_rd.addr),
buf, buf_size, &count, DT9812_USB_TIMEOUT);
}
static int dt9812_read_multiple_registers(struct comedi_device *dev,
int reg_count, u8 *address,
u8 *value)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct dt9812_private *devpriv = dev->private;
struct dt9812_usb_cmd cmd;
int i, count, ret;
cmd.cmd = cpu_to_le32(DT9812_R_MULTI_BYTE_REG);
cmd.u.read_multi_info.count = reg_count;
for (i = 0; i < reg_count; i++)
cmd.u.read_multi_info.address[i] = address[i];
ret = usb_bulk_msg(usb, usb_sndbulkpipe(usb, devpriv->cmd_wr.addr),
&cmd, 32, &count, DT9812_USB_TIMEOUT);
if (ret)
return ret;
return usb_bulk_msg(usb, usb_rcvbulkpipe(usb, devpriv->cmd_rd.addr),
value, reg_count, &count, DT9812_USB_TIMEOUT);
}
static int dt9812_write_multiple_registers(struct comedi_device *dev,
int reg_count, u8 *address,
u8 *value)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct dt9812_private *devpriv = dev->private;
struct dt9812_usb_cmd cmd;
int i, count;
cmd.cmd = cpu_to_le32(DT9812_W_MULTI_BYTE_REG);
cmd.u.read_multi_info.count = reg_count;
for (i = 0; i < reg_count; i++) {
cmd.u.write_multi_info.write[i].address = address[i];
cmd.u.write_multi_info.write[i].value = value[i];
}
return usb_bulk_msg(usb, usb_sndbulkpipe(usb, devpriv->cmd_wr.addr),
&cmd, 32, &count, DT9812_USB_TIMEOUT);
}
static int dt9812_rmw_multiple_registers(struct comedi_device *dev,
int reg_count,
struct dt9812_rmw_byte *rmw)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct dt9812_private *devpriv = dev->private;
struct dt9812_usb_cmd cmd;
int i, count;
cmd.cmd = cpu_to_le32(DT9812_RMW_MULTI_BYTE_REG);
cmd.u.rmw_multi_info.count = reg_count;
for (i = 0; i < reg_count; i++)
cmd.u.rmw_multi_info.rmw[i] = rmw[i];
return usb_bulk_msg(usb, usb_sndbulkpipe(usb, devpriv->cmd_wr.addr),
&cmd, 32, &count, DT9812_USB_TIMEOUT);
}
static int dt9812_digital_in(struct comedi_device *dev, u8 *bits)
{
struct dt9812_private *devpriv = dev->private;
u8 reg[2] = { F020_SFR_P3, F020_SFR_P1 };
u8 value[2];
int ret;
down(&devpriv->sem);
ret = dt9812_read_multiple_registers(dev, 2, reg, value);
if (ret == 0) {
*bits = (value[0] & 0x7f) | ((value[1] & 0x08) << 4);
}
up(&devpriv->sem);
return ret;
}
static int dt9812_digital_out(struct comedi_device *dev, u8 bits)
{
struct dt9812_private *devpriv = dev->private;
u8 reg[1] = { F020_SFR_P2 };
u8 value[1] = { bits };
int ret;
down(&devpriv->sem);
ret = dt9812_write_multiple_registers(dev, 1, reg, value);
up(&devpriv->sem);
return ret;
}
static void dt9812_configure_mux(struct comedi_device *dev,
struct dt9812_rmw_byte *rmw, int channel)
{
struct dt9812_private *devpriv = dev->private;
if (devpriv->device == DT9812_DEVID_DT9812_10) {
rmw->address = F020_SFR_P1;
rmw->and_mask = 0xe0;
rmw->or_value = channel << 5;
} else {
rmw->address = F020_SFR_AMX0SL;
rmw->and_mask = 0xff;
rmw->or_value = channel & 0x07;
}
}
static void dt9812_configure_gain(struct comedi_device *dev,
struct dt9812_rmw_byte *rmw,
enum dt9812_gain gain)
{
struct dt9812_private *devpriv = dev->private;
if (devpriv->device == DT9812_DEVID_DT9812_10)
gain <<= 1;
rmw->address = F020_SFR_ADC0CF;
rmw->and_mask = F020_MASK_ADC0CF_AMP0GN2 |
F020_MASK_ADC0CF_AMP0GN1 |
F020_MASK_ADC0CF_AMP0GN0;
switch (gain) {
case DT9812_GAIN_0PT5:
rmw->or_value = F020_MASK_ADC0CF_AMP0GN2 |
F020_MASK_ADC0CF_AMP0GN1;
break;
default:
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
}
}
static int dt9812_analog_in(struct comedi_device *dev,
int channel, u16 *value, enum dt9812_gain gain)
{
struct dt9812_private *devpriv = dev->private;
struct dt9812_rmw_byte rmw[3];
u8 reg[3] = {
F020_SFR_ADC0CN,
F020_SFR_ADC0H,
F020_SFR_ADC0L
};
u8 val[3];
int ret;
down(&devpriv->sem);
dt9812_configure_gain(dev, &rmw[0], gain);
dt9812_configure_mux(dev, &rmw[1], channel);
rmw[2].address = F020_SFR_ADC0CN;
rmw[2].and_mask = 0xff;
rmw[2].or_value = F020_MASK_ADC0CN_AD0EN | F020_MASK_ADC0CN_AD0BUSY;
ret = dt9812_rmw_multiple_registers(dev, 3, rmw);
if (ret)
goto exit;
ret = dt9812_read_multiple_registers(dev, 3, reg, val);
if (ret)
goto exit;
if ((val[0] & (F020_MASK_ADC0CN_AD0INT | F020_MASK_ADC0CN_AD0BUSY)) ==
F020_MASK_ADC0CN_AD0INT) {
switch (devpriv->device) {
case DT9812_DEVID_DT9812_10:
*value = ((val[1] << 8) | val[2]) + 0x800;
break;
case DT9812_DEVID_DT9812_2PT5:
*value = (val[1] << 8) | val[2];
break;
}
}
exit:
up(&devpriv->sem);
return ret;
}
static int dt9812_analog_out(struct comedi_device *dev, int channel, u16 value)
{
struct dt9812_private *devpriv = dev->private;
struct dt9812_rmw_byte rmw[3];
int ret;
down(&devpriv->sem);
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
ret = dt9812_rmw_multiple_registers(dev, 3, rmw);
devpriv->ao_shadow[channel] = value;
up(&devpriv->sem);
return ret;
}
static int dt9812_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
u8 bits = 0;
int ret;
ret = dt9812_digital_in(dev, &bits);
if (ret)
return ret;
data[1] = bits;
return insn->n;
}
static int dt9812_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
dt9812_digital_out(dev, s->state);
data[1] = s->state;
return insn->n;
}
static int dt9812_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
u16 val = 0;
int ret;
int i;
for (i = 0; i < insn->n; i++) {
ret = dt9812_analog_in(dev, chan, &val, DT9812_GAIN_1);
if (ret)
return ret;
data[i] = val;
}
return insn->n;
}
static int dt9812_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dt9812_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
down(&devpriv->sem);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_shadow[chan];
up(&devpriv->sem);
return insn->n;
}
static int dt9812_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int ret;
int i;
for (i = 0; i < insn->n; i++) {
ret = dt9812_analog_out(dev, chan, data[i]);
if (ret)
return ret;
}
return insn->n;
}
static int dt9812_find_endpoints(struct comedi_device *dev)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct usb_host_interface *host = intf->cur_altsetting;
struct dt9812_private *devpriv = dev->private;
struct usb_endpoint_descriptor *ep;
int i;
if (host->desc.bNumEndpoints != 5) {
dev_err(dev->class_dev, "Wrong number of endpoints\n");
return -ENODEV;
}
for (i = 0; i < host->desc.bNumEndpoints; ++i) {
int dir = -1;
ep = &host->endpoint[i].desc;
switch (i) {
case 0:
dir = USB_DIR_IN;
break;
case 1:
dir = USB_DIR_OUT;
devpriv->cmd_wr.addr = ep->bEndpointAddress;
devpriv->cmd_wr.size = le16_to_cpu(ep->wMaxPacketSize);
break;
case 2:
dir = USB_DIR_IN;
devpriv->cmd_rd.addr = ep->bEndpointAddress;
devpriv->cmd_rd.size = le16_to_cpu(ep->wMaxPacketSize);
break;
case 3:
dir = USB_DIR_OUT;
break;
case 4:
dir = USB_DIR_IN;
break;
}
if ((ep->bEndpointAddress & USB_DIR_IN) != dir) {
dev_err(dev->class_dev,
"Endpoint has wrong direction\n");
return -ENODEV;
}
}
return 0;
}
static int dt9812_reset_device(struct comedi_device *dev)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct dt9812_private *devpriv = dev->private;
u32 serial;
u16 vendor;
u16 product;
u8 tmp8;
__le16 tmp16;
__le32 tmp32;
int ret;
int i;
ret = dt9812_read_info(dev, 0, &tmp8, sizeof(tmp8));
if (ret) {
usb_reset_configuration(usb);
for (i = 0; i < 10; i++) {
ret = dt9812_read_info(dev, 1, &tmp8, sizeof(tmp8));
if (ret == 0)
break;
}
if (ret) {
dev_err(dev->class_dev,
"unable to reset configuration\n");
return ret;
}
}
ret = dt9812_read_info(dev, 1, &tmp16, sizeof(tmp16));
if (ret) {
dev_err(dev->class_dev, "failed to read vendor id\n");
return ret;
}
vendor = le16_to_cpu(tmp16);
ret = dt9812_read_info(dev, 3, &tmp16, sizeof(tmp16));
if (ret) {
dev_err(dev->class_dev, "failed to read product id\n");
return ret;
}
product = le16_to_cpu(tmp16);
ret = dt9812_read_info(dev, 5, &tmp16, sizeof(tmp16));
if (ret) {
dev_err(dev->class_dev, "failed to read device id\n");
return ret;
}
devpriv->device = le16_to_cpu(tmp16);
ret = dt9812_read_info(dev, 7, &tmp32, sizeof(tmp32));
if (ret) {
dev_err(dev->class_dev, "failed to read serial number\n");
return ret;
}
serial = le32_to_cpu(tmp32);
dev_info(dev->class_dev, "USB DT9812 (%4.4x.%4.4x.%4.4x) #0x%8.8x\n",
vendor, product, devpriv->device, serial);
if (devpriv->device != DT9812_DEVID_DT9812_10 &&
devpriv->device != DT9812_DEVID_DT9812_2PT5) {
dev_err(dev->class_dev, "Unsupported device!\n");
return -EINVAL;
}
return 0;
}
static int dt9812_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct dt9812_private *devpriv;
struct comedi_subdevice *s;
bool is_unipolar;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
sema_init(&devpriv->sem, 1);
usb_set_intfdata(intf, devpriv);
ret = dt9812_find_endpoints(dev);
if (ret)
return ret;
ret = dt9812_reset_device(dev);
if (ret)
return ret;
is_unipolar = (devpriv->device == DT9812_DEVID_DT9812_2PT5);
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt9812_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt9812_do_insn_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->maxdata = 0x0fff;
s->range_table = is_unipolar ? &range_unipolar2_5 : &range_bipolar10;
s->insn_read = dt9812_ai_insn_read;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = is_unipolar ? &range_unipolar2_5 : &range_bipolar10;
s->insn_write = dt9812_ao_insn_write;
s->insn_read = dt9812_ao_insn_read;
devpriv->ao_shadow[0] = is_unipolar ? 0x0000 : 0x0800;
devpriv->ao_shadow[1] = is_unipolar ? 0x0000 : 0x0800;
return 0;
}
static void dt9812_detach(struct comedi_device *dev)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct dt9812_private *devpriv = dev->private;
if (!devpriv)
return;
down(&devpriv->sem);
usb_set_intfdata(intf, NULL);
up(&devpriv->sem);
}
static int dt9812_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return comedi_usb_auto_config(intf, &dt9812_driver, id->driver_info);
}
