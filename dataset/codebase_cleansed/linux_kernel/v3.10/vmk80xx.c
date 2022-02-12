static int vmk80xx_check_data_link(struct vmk80xx_private *devpriv)
{
struct usb_device *usb = devpriv->usb;
unsigned int tx_pipe;
unsigned int rx_pipe;
unsigned char tx[1];
unsigned char rx[2];
tx_pipe = usb_sndbulkpipe(usb, 0x01);
rx_pipe = usb_rcvbulkpipe(usb, 0x81);
tx[0] = VMK8061_CMD_RD_PWR_STAT;
usb_bulk_msg(usb, tx_pipe, tx, 1, NULL, devpriv->ep_tx->bInterval);
usb_bulk_msg(usb, rx_pipe, rx, 2, NULL, HZ * 10);
return (int)rx[1];
}
static void vmk80xx_read_eeprom(struct vmk80xx_private *devpriv, int flag)
{
struct usb_device *usb = devpriv->usb;
unsigned int tx_pipe;
unsigned int rx_pipe;
unsigned char tx[1];
unsigned char rx[64];
int cnt;
tx_pipe = usb_sndbulkpipe(usb, 0x01);
rx_pipe = usb_rcvbulkpipe(usb, 0x81);
tx[0] = VMK8061_CMD_RD_VERSION;
usb_bulk_msg(usb, tx_pipe, tx, 1, NULL, devpriv->ep_tx->bInterval);
usb_bulk_msg(usb, rx_pipe, rx, 64, &cnt, HZ * 10);
rx[cnt] = '\0';
if (flag & IC3_VERSION)
strncpy(devpriv->fw.ic3_vers, rx + 1, 24);
else
strncpy(devpriv->fw.ic6_vers, rx + 25, 24);
}
static void vmk80xx_do_bulk_msg(struct vmk80xx_private *devpriv)
{
struct usb_device *usb = devpriv->usb;
__u8 tx_addr;
__u8 rx_addr;
unsigned int tx_pipe;
unsigned int rx_pipe;
size_t size;
tx_addr = devpriv->ep_tx->bEndpointAddress;
rx_addr = devpriv->ep_rx->bEndpointAddress;
tx_pipe = usb_sndbulkpipe(usb, tx_addr);
rx_pipe = usb_rcvbulkpipe(usb, rx_addr);
size = le16_to_cpu(devpriv->ep_tx->wMaxPacketSize);
usb_bulk_msg(usb, tx_pipe, devpriv->usb_tx_buf,
size, NULL, devpriv->ep_tx->bInterval);
usb_bulk_msg(usb, rx_pipe, devpriv->usb_rx_buf, size, NULL, HZ * 10);
}
static int vmk80xx_read_packet(struct vmk80xx_private *devpriv)
{
struct usb_device *usb;
struct usb_endpoint_descriptor *ep;
unsigned int pipe;
if (!devpriv->intf)
return -ENODEV;
if (devpriv->model == VMK8061_MODEL) {
vmk80xx_do_bulk_msg(devpriv);
return 0;
}
usb = devpriv->usb;
ep = devpriv->ep_rx;
pipe = usb_rcvintpipe(usb, ep->bEndpointAddress);
return usb_interrupt_msg(usb, pipe, devpriv->usb_rx_buf,
le16_to_cpu(ep->wMaxPacketSize), NULL,
HZ * 10);
}
static int vmk80xx_write_packet(struct vmk80xx_private *devpriv, int cmd)
{
struct usb_device *usb;
struct usb_endpoint_descriptor *ep;
unsigned int pipe;
if (!devpriv->intf)
return -ENODEV;
devpriv->usb_tx_buf[0] = cmd;
if (devpriv->model == VMK8061_MODEL) {
vmk80xx_do_bulk_msg(devpriv);
return 0;
}
usb = devpriv->usb;
ep = devpriv->ep_tx;
pipe = usb_sndintpipe(usb, ep->bEndpointAddress);
return usb_interrupt_msg(usb, pipe, devpriv->usb_tx_buf,
le16_to_cpu(ep->wMaxPacketSize), NULL,
HZ * 10);
}
static int vmk80xx_reset_device(struct vmk80xx_private *devpriv)
{
size_t size;
int retval;
size = le16_to_cpu(devpriv->ep_tx->wMaxPacketSize);
memset(devpriv->usb_tx_buf, 0, size);
retval = vmk80xx_write_packet(devpriv, VMK8055_CMD_RST);
if (retval)
return retval;
return vmk80xx_write_packet(devpriv, VMK8055_CMD_WRT_AD);
}
static int vmk80xx_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
int chan;
int reg[2];
int n;
down(&devpriv->limit_sem);
chan = CR_CHAN(insn->chanspec);
switch (devpriv->model) {
case VMK8055_MODEL:
if (!chan)
reg[0] = VMK8055_AI1_REG;
else
reg[0] = VMK8055_AI2_REG;
break;
case VMK8061_MODEL:
default:
reg[0] = VMK8061_AI_REG1;
reg[1] = VMK8061_AI_REG2;
devpriv->usb_tx_buf[0] = VMK8061_CMD_RD_AI;
devpriv->usb_tx_buf[VMK8061_CH_REG] = chan;
break;
}
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(devpriv))
break;
if (devpriv->model == VMK8055_MODEL) {
data[n] = devpriv->usb_rx_buf[reg[0]];
continue;
}
data[n] = devpriv->usb_rx_buf[reg[0]] + 256 *
devpriv->usb_rx_buf[reg[1]];
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
int chan;
int cmd;
int reg;
int n;
down(&devpriv->limit_sem);
chan = CR_CHAN(insn->chanspec);
switch (devpriv->model) {
case VMK8055_MODEL:
cmd = VMK8055_CMD_WRT_AD;
if (!chan)
reg = VMK8055_AO1_REG;
else
reg = VMK8055_AO2_REG;
break;
default:
cmd = VMK8061_CMD_SET_AO;
reg = VMK8061_AO_REG;
devpriv->usb_tx_buf[VMK8061_CH_REG] = chan;
break;
}
for (n = 0; n < insn->n; n++) {
devpriv->usb_tx_buf[reg] = data[n];
if (vmk80xx_write_packet(devpriv, cmd))
break;
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
int chan;
int reg;
int n;
down(&devpriv->limit_sem);
chan = CR_CHAN(insn->chanspec);
reg = VMK8061_AO_REG - 1;
devpriv->usb_tx_buf[0] = VMK8061_CMD_RD_AO;
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(devpriv))
break;
data[n] = devpriv->usb_rx_buf[reg + chan];
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
unsigned char *rx_buf;
int reg;
int retval;
down(&devpriv->limit_sem);
rx_buf = devpriv->usb_rx_buf;
if (devpriv->model == VMK8061_MODEL) {
reg = VMK8061_DI_REG;
devpriv->usb_tx_buf[0] = VMK8061_CMD_RD_DI;
} else {
reg = VMK8055_DI_REG;
}
retval = vmk80xx_read_packet(devpriv);
if (!retval) {
if (devpriv->model == VMK8055_MODEL)
data[1] = (((rx_buf[reg] >> 4) & 0x03) |
((rx_buf[reg] << 2) & 0x04) |
((rx_buf[reg] >> 3) & 0x18));
else
data[1] = rx_buf[reg];
retval = 2;
}
up(&devpriv->limit_sem);
return retval;
}
static int vmk80xx_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
unsigned char *rx_buf, *tx_buf;
int reg, cmd;
int retval;
if (devpriv->model == VMK8061_MODEL) {
reg = VMK8061_DO_REG;
cmd = VMK8061_CMD_DO;
} else {
reg = VMK8055_DO_REG;
cmd = VMK8055_CMD_WRT_AD;
}
down(&devpriv->limit_sem);
rx_buf = devpriv->usb_rx_buf;
tx_buf = devpriv->usb_tx_buf;
if (data[0]) {
tx_buf[reg] &= ~data[0];
tx_buf[reg] |= (data[0] & data[1]);
retval = vmk80xx_write_packet(devpriv, cmd);
if (retval)
goto out;
}
if (devpriv->model == VMK8061_MODEL) {
tx_buf[0] = VMK8061_CMD_RD_DO;
retval = vmk80xx_read_packet(devpriv);
if (!retval) {
data[1] = rx_buf[reg];
retval = 2;
}
} else {
data[1] = tx_buf[reg];
retval = 2;
}
out:
up(&devpriv->limit_sem);
return retval;
}
static int vmk80xx_cnt_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
int chan;
int reg[2];
int n;
down(&devpriv->limit_sem);
chan = CR_CHAN(insn->chanspec);
switch (devpriv->model) {
case VMK8055_MODEL:
if (!chan)
reg[0] = VMK8055_CNT1_REG;
else
reg[0] = VMK8055_CNT2_REG;
break;
case VMK8061_MODEL:
default:
reg[0] = VMK8061_CNT_REG;
reg[1] = VMK8061_CNT_REG;
devpriv->usb_tx_buf[0] = VMK8061_CMD_RD_CNT;
break;
}
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(devpriv))
break;
if (devpriv->model == VMK8055_MODEL)
data[n] = devpriv->usb_rx_buf[reg[0]];
else
data[n] = devpriv->usb_rx_buf[reg[0] * (chan + 1) + 1]
+ 256 * devpriv->usb_rx_buf[reg[1] * 2 + 2];
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_cnt_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
unsigned int insn_cmd;
int chan;
int cmd;
int reg;
int n;
insn_cmd = data[0];
if (insn_cmd != INSN_CONFIG_RESET && insn_cmd != GPCT_RESET)
return -EINVAL;
down(&devpriv->limit_sem);
chan = CR_CHAN(insn->chanspec);
if (devpriv->model == VMK8055_MODEL) {
if (!chan) {
cmd = VMK8055_CMD_RST_CNT1;
reg = VMK8055_CNT1_REG;
} else {
cmd = VMK8055_CMD_RST_CNT2;
reg = VMK8055_CNT2_REG;
}
devpriv->usb_tx_buf[reg] = 0x00;
} else {
cmd = VMK8061_CMD_RST_CNT;
}
for (n = 0; n < insn->n; n++)
if (vmk80xx_write_packet(devpriv, cmd))
break;
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_cnt_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
unsigned long debtime;
unsigned long val;
int chan;
int cmd;
int n;
down(&devpriv->limit_sem);
chan = CR_CHAN(insn->chanspec);
if (!chan)
cmd = VMK8055_CMD_DEB1_TIME;
else
cmd = VMK8055_CMD_DEB2_TIME;
for (n = 0; n < insn->n; n++) {
debtime = data[n];
if (debtime == 0)
debtime = 1;
if (debtime > 7450)
debtime = 7450;
val = int_sqrt(debtime * 1000 / 115);
if (((val + 1) * val) < debtime * 1000 / 115)
val += 1;
devpriv->usb_tx_buf[6 + chan] = val;
if (vmk80xx_write_packet(devpriv, cmd))
break;
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_pwm_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
unsigned char *tx_buf;
unsigned char *rx_buf;
int reg[2];
int n;
down(&devpriv->limit_sem);
tx_buf = devpriv->usb_tx_buf;
rx_buf = devpriv->usb_rx_buf;
reg[0] = VMK8061_PWM_REG1;
reg[1] = VMK8061_PWM_REG2;
tx_buf[0] = VMK8061_CMD_RD_PWM;
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(devpriv))
break;
data[n] = rx_buf[reg[0]] + 4 * rx_buf[reg[1]];
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_pwm_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct vmk80xx_private *devpriv = dev->private;
unsigned char *tx_buf;
int reg[2];
int cmd;
int n;
down(&devpriv->limit_sem);
tx_buf = devpriv->usb_tx_buf;
reg[0] = VMK8061_PWM_REG1;
reg[1] = VMK8061_PWM_REG2;
cmd = VMK8061_CMD_OUT_PWM;
for (n = 0; n < insn->n; n++) {
tx_buf[reg[0]] = (unsigned char)(data[n] & 0x03);
tx_buf[reg[1]] = (unsigned char)(data[n] >> 2) & 0xff;
if (vmk80xx_write_packet(devpriv, cmd))
break;
}
up(&devpriv->limit_sem);
return n;
}
static int vmk80xx_find_usb_endpoints(struct comedi_device *dev)
{
struct vmk80xx_private *devpriv = dev->private;
struct usb_interface *intf = devpriv->intf;
struct usb_host_interface *iface_desc = intf->cur_altsetting;
struct usb_endpoint_descriptor *ep_desc;
int i;
if (iface_desc->desc.bNumEndpoints != 2)
return -ENODEV;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
ep_desc = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_int_in(ep_desc) ||
usb_endpoint_is_bulk_in(ep_desc)) {
if (!devpriv->ep_rx)
devpriv->ep_rx = ep_desc;
continue;
}
if (usb_endpoint_is_int_out(ep_desc) ||
usb_endpoint_is_bulk_out(ep_desc)) {
if (!devpriv->ep_tx)
devpriv->ep_tx = ep_desc;
continue;
}
}
if (!devpriv->ep_rx || !devpriv->ep_tx)
return -ENODEV;
return 0;
}
static int vmk80xx_alloc_usb_buffers(struct comedi_device *dev)
{
struct vmk80xx_private *devpriv = dev->private;
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
static int vmk80xx_init_subdevices(struct comedi_device *dev)
{
const struct vmk80xx_board *boardinfo = comedi_board(dev);
struct vmk80xx_private *devpriv = dev->private;
struct comedi_subdevice *s;
int n_subd;
int ret;
down(&devpriv->limit_sem);
if (devpriv->model == VMK8055_MODEL)
n_subd = 5;
else
n_subd = 6;
ret = comedi_alloc_subdevices(dev, n_subd);
if (ret) {
up(&devpriv->limit_sem);
return ret;
}
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = boardinfo->ai_nchans;
s->maxdata = boardinfo->ai_maxdata;
s->range_table = boardinfo->range;
s->insn_read = vmk80xx_ai_insn_read;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND;
s->n_chan = boardinfo->ao_nchans;
s->maxdata = 0x00ff;
s->range_table = boardinfo->range;
s->insn_write = vmk80xx_ao_insn_write;
if (devpriv->model == VMK8061_MODEL) {
s->subdev_flags |= SDF_READABLE;
s->insn_read = vmk80xx_ao_insn_read;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = boardinfo->di_nchans;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = vmk80xx_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = vmk80xx_do_insn_bits;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE;
s->n_chan = 2;
s->maxdata = boardinfo->cnt_maxdata;
s->insn_read = vmk80xx_cnt_insn_read;
s->insn_config = vmk80xx_cnt_insn_config;
if (devpriv->model == VMK8055_MODEL) {
s->subdev_flags |= SDF_WRITEABLE;
s->insn_write = vmk80xx_cnt_insn_write;
}
if (devpriv->model == VMK8061_MODEL) {
s = &dev->subdevices[5];
s->type = COMEDI_SUBD_PWM;
s->subdev_flags = SDF_READABLE | SDF_WRITEABLE;
s->n_chan = boardinfo->pwm_nchans;
s->maxdata = boardinfo->pwm_maxdata;
s->insn_read = vmk80xx_pwm_insn_read;
s->insn_write = vmk80xx_pwm_insn_write;
}
up(&devpriv->limit_sem);
return 0;
}
static int vmk80xx_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
const struct vmk80xx_board *boardinfo;
struct vmk80xx_private *devpriv;
int ret;
boardinfo = &vmk80xx_boardinfo[context];
dev->board_ptr = boardinfo;
dev->board_name = boardinfo->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
devpriv->usb = interface_to_usbdev(intf);
devpriv->intf = intf;
devpriv->model = boardinfo->model;
ret = vmk80xx_find_usb_endpoints(dev);
if (ret)
return ret;
ret = vmk80xx_alloc_usb_buffers(dev);
if (ret)
return ret;
sema_init(&devpriv->limit_sem, 8);
usb_set_intfdata(intf, devpriv);
if (devpriv->model == VMK8061_MODEL) {
vmk80xx_read_eeprom(devpriv, IC3_VERSION);
dev_info(&intf->dev, "%s\n", devpriv->fw.ic3_vers);
if (vmk80xx_check_data_link(devpriv)) {
vmk80xx_read_eeprom(devpriv, IC6_VERSION);
dev_info(&intf->dev, "%s\n", devpriv->fw.ic6_vers);
}
}
if (devpriv->model == VMK8055_MODEL)
vmk80xx_reset_device(devpriv);
return vmk80xx_init_subdevices(dev);
}
static void vmk80xx_detach(struct comedi_device *dev)
{
struct vmk80xx_private *devpriv = dev->private;
if (!devpriv)
return;
down(&devpriv->limit_sem);
usb_set_intfdata(devpriv->intf, NULL);
kfree(devpriv->usb_rx_buf);
kfree(devpriv->usb_tx_buf);
up(&devpriv->limit_sem);
}
static int vmk80xx_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return comedi_usb_auto_config(intf, &vmk80xx_driver, id->driver_info);
}
