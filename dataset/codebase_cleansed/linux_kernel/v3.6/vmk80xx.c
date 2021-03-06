static void vmk80xx_tx_callback(struct urb *urb)
{
struct vmk80xx_usb *dev = urb->context;
int stat = urb->status;
if (stat && !(stat == -ENOENT
|| stat == -ECONNRESET || stat == -ESHUTDOWN))
dbgcm("comedi#: vmk80xx: %s - nonzero urb status (%d)\n",
__func__, stat);
if (!test_bit(TRANS_OUT_BUSY, &dev->flags))
return;
clear_bit(TRANS_OUT_BUSY, &dev->flags);
wake_up_interruptible(&dev->write_wait);
}
static void vmk80xx_rx_callback(struct urb *urb)
{
struct vmk80xx_usb *dev = urb->context;
int stat = urb->status;
switch (stat) {
case 0:
break;
case -ENOENT:
case -ECONNRESET:
case -ESHUTDOWN:
break;
default:
dbgcm("comedi#: vmk80xx: %s - nonzero urb status (%d)\n",
__func__, stat);
goto resubmit;
}
goto exit;
resubmit:
if (test_bit(TRANS_IN_RUNNING, &dev->flags) && dev->intf) {
usb_anchor_urb(urb, &dev->rx_anchor);
if (!usb_submit_urb(urb, GFP_KERNEL))
goto exit;
dev_err(&urb->dev->dev,
"comedi#: vmk80xx: %s - submit urb failed\n",
__func__);
usb_unanchor_urb(urb);
}
exit:
clear_bit(TRANS_IN_BUSY, &dev->flags);
wake_up_interruptible(&dev->read_wait);
}
static int vmk80xx_check_data_link(struct vmk80xx_usb *dev)
{
unsigned int tx_pipe;
unsigned int rx_pipe;
unsigned char tx[1];
unsigned char rx[2];
tx_pipe = usb_sndbulkpipe(dev->udev, 0x01);
rx_pipe = usb_rcvbulkpipe(dev->udev, 0x81);
tx[0] = VMK8061_CMD_RD_PWR_STAT;
usb_bulk_msg(dev->udev, tx_pipe, tx, 1, NULL, dev->ep_tx->bInterval);
usb_bulk_msg(dev->udev, rx_pipe, rx, 2, NULL, HZ * 10);
return (int)rx[1];
}
static void vmk80xx_read_eeprom(struct vmk80xx_usb *dev, int flag)
{
unsigned int tx_pipe;
unsigned int rx_pipe;
unsigned char tx[1];
unsigned char rx[64];
int cnt;
tx_pipe = usb_sndbulkpipe(dev->udev, 0x01);
rx_pipe = usb_rcvbulkpipe(dev->udev, 0x81);
tx[0] = VMK8061_CMD_RD_VERSION;
usb_bulk_msg(dev->udev, tx_pipe, tx, 1, NULL, dev->ep_tx->bInterval);
usb_bulk_msg(dev->udev, rx_pipe, rx, 64, &cnt, HZ * 10);
rx[cnt] = '\0';
if (flag & IC3_VERSION)
strncpy(dev->fw.ic3_vers, rx + 1, 24);
else
strncpy(dev->fw.ic6_vers, rx + 25, 24);
}
static int vmk80xx_reset_device(struct vmk80xx_usb *dev)
{
struct urb *urb;
unsigned int tx_pipe;
int ival;
size_t size;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return -ENOMEM;
tx_pipe = usb_sndintpipe(dev->udev, 0x01);
ival = dev->ep_tx->bInterval;
size = le16_to_cpu(dev->ep_tx->wMaxPacketSize);
dev->usb_tx_buf[0] = VMK8055_CMD_RST;
dev->usb_tx_buf[1] = 0x00;
dev->usb_tx_buf[2] = 0x00;
dev->usb_tx_buf[3] = 0x00;
dev->usb_tx_buf[4] = 0x00;
dev->usb_tx_buf[5] = 0x00;
dev->usb_tx_buf[6] = 0x00;
dev->usb_tx_buf[7] = 0x00;
usb_fill_int_urb(urb, dev->udev, tx_pipe, dev->usb_tx_buf,
size, vmk80xx_tx_callback, dev, ival);
usb_anchor_urb(urb, &dev->tx_anchor);
return usb_submit_urb(urb, GFP_KERNEL);
}
static void vmk80xx_build_int_urb(struct urb *urb, int flag)
{
struct vmk80xx_usb *dev = urb->context;
__u8 rx_addr;
__u8 tx_addr;
unsigned int pipe;
unsigned char *buf;
size_t size;
void (*callback) (struct urb *);
int ival;
if (flag & URB_RCV_FLAG) {
rx_addr = dev->ep_rx->bEndpointAddress;
pipe = usb_rcvintpipe(dev->udev, rx_addr);
buf = dev->usb_rx_buf;
size = le16_to_cpu(dev->ep_rx->wMaxPacketSize);
callback = vmk80xx_rx_callback;
ival = dev->ep_rx->bInterval;
} else {
tx_addr = dev->ep_tx->bEndpointAddress;
pipe = usb_sndintpipe(dev->udev, tx_addr);
buf = dev->usb_tx_buf;
size = le16_to_cpu(dev->ep_tx->wMaxPacketSize);
callback = vmk80xx_tx_callback;
ival = dev->ep_tx->bInterval;
}
usb_fill_int_urb(urb, dev->udev, pipe, buf, size, callback, dev, ival);
}
static void vmk80xx_do_bulk_msg(struct vmk80xx_usb *dev)
{
__u8 tx_addr;
__u8 rx_addr;
unsigned int tx_pipe;
unsigned int rx_pipe;
size_t size;
set_bit(TRANS_IN_BUSY, &dev->flags);
set_bit(TRANS_OUT_BUSY, &dev->flags);
tx_addr = dev->ep_tx->bEndpointAddress;
rx_addr = dev->ep_rx->bEndpointAddress;
tx_pipe = usb_sndbulkpipe(dev->udev, tx_addr);
rx_pipe = usb_rcvbulkpipe(dev->udev, rx_addr);
size = le16_to_cpu(dev->ep_tx->wMaxPacketSize);
usb_bulk_msg(dev->udev, tx_pipe, dev->usb_tx_buf,
size, NULL, dev->ep_tx->bInterval);
usb_bulk_msg(dev->udev, rx_pipe, dev->usb_rx_buf, size, NULL, HZ * 10);
clear_bit(TRANS_OUT_BUSY, &dev->flags);
clear_bit(TRANS_IN_BUSY, &dev->flags);
}
static int vmk80xx_read_packet(struct vmk80xx_usb *dev)
{
struct urb *urb;
int retval;
if (!dev->intf)
return -ENODEV;
if (test_bit(TRANS_IN_BUSY, &dev->flags))
if (wait_event_interruptible(dev->read_wait,
!test_bit(TRANS_IN_BUSY,
&dev->flags)))
return -ERESTART;
if (dev->board.model == VMK8061_MODEL) {
vmk80xx_do_bulk_msg(dev);
return 0;
}
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return -ENOMEM;
urb->context = dev;
vmk80xx_build_int_urb(urb, URB_RCV_FLAG);
set_bit(TRANS_IN_RUNNING, &dev->flags);
set_bit(TRANS_IN_BUSY, &dev->flags);
usb_anchor_urb(urb, &dev->rx_anchor);
retval = usb_submit_urb(urb, GFP_KERNEL);
if (!retval)
goto exit;
clear_bit(TRANS_IN_RUNNING, &dev->flags);
usb_unanchor_urb(urb);
exit:
usb_free_urb(urb);
return retval;
}
static int vmk80xx_write_packet(struct vmk80xx_usb *dev, int cmd)
{
struct urb *urb;
int retval;
if (!dev->intf)
return -ENODEV;
if (test_bit(TRANS_OUT_BUSY, &dev->flags))
if (wait_event_interruptible(dev->write_wait,
!test_bit(TRANS_OUT_BUSY,
&dev->flags)))
return -ERESTART;
if (dev->board.model == VMK8061_MODEL) {
dev->usb_tx_buf[0] = cmd;
vmk80xx_do_bulk_msg(dev);
return 0;
}
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return -ENOMEM;
urb->context = dev;
vmk80xx_build_int_urb(urb, URB_SND_FLAG);
set_bit(TRANS_OUT_BUSY, &dev->flags);
usb_anchor_urb(urb, &dev->tx_anchor);
dev->usb_tx_buf[0] = cmd;
retval = usb_submit_urb(urb, GFP_KERNEL);
if (!retval)
goto exit;
clear_bit(TRANS_OUT_BUSY, &dev->flags);
usb_unanchor_urb(urb);
exit:
usb_free_urb(urb);
return retval;
}
static int rudimentary_check(struct vmk80xx_usb *dev, int dir)
{
if (!dev)
return -EFAULT;
if (!dev->probed)
return -ENODEV;
if (!dev->attached)
return -ENODEV;
if (dir & DIR_IN) {
if (test_bit(TRANS_IN_BUSY, &dev->flags))
return -EBUSY;
}
if (dir & DIR_OUT) {
if (test_bit(TRANS_OUT_BUSY, &dev->flags))
return -EBUSY;
}
return 0;
}
static int vmk80xx_ai_rinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
int reg[2];
int n;
n = rudimentary_check(dev, DIR_IN);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
switch (dev->board.model) {
case VMK8055_MODEL:
if (!chan)
reg[0] = VMK8055_AI1_REG;
else
reg[0] = VMK8055_AI2_REG;
break;
case VMK8061_MODEL:
reg[0] = VMK8061_AI_REG1;
reg[1] = VMK8061_AI_REG2;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_AI;
dev->usb_tx_buf[VMK8061_CH_REG] = chan;
break;
}
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(dev))
break;
if (dev->board.model == VMK8055_MODEL) {
data[n] = dev->usb_rx_buf[reg[0]];
continue;
}
data[n] = dev->usb_rx_buf[reg[0]] + 256 *
dev->usb_rx_buf[reg[1]];
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_ao_winsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
int cmd;
int reg;
int n;
n = rudimentary_check(dev, DIR_OUT);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
switch (dev->board.model) {
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
dev->usb_tx_buf[VMK8061_CH_REG] = chan;
break;
}
for (n = 0; n < insn->n; n++) {
dev->usb_tx_buf[reg] = data[n];
if (vmk80xx_write_packet(dev, cmd))
break;
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_ao_rinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
int reg;
int n;
n = rudimentary_check(dev, DIR_IN);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
reg = VMK8061_AO_REG - 1;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_AO;
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(dev))
break;
data[n] = dev->usb_rx_buf[reg + chan];
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_di_bits(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
unsigned char *rx_buf;
int reg;
int retval;
retval = rudimentary_check(dev, DIR_IN);
if (retval)
return retval;
down(&dev->limit_sem);
rx_buf = dev->usb_rx_buf;
if (dev->board.model == VMK8061_MODEL) {
reg = VMK8061_DI_REG;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_DI;
} else {
reg = VMK8055_DI_REG;
}
retval = vmk80xx_read_packet(dev);
if (!retval) {
if (dev->board.model == VMK8055_MODEL)
data[1] = (((rx_buf[reg] >> 4) & 0x03) |
((rx_buf[reg] << 2) & 0x04) |
((rx_buf[reg] >> 3) & 0x18));
else
data[1] = rx_buf[reg];
retval = 2;
}
up(&dev->limit_sem);
return retval;
}
static int vmk80xx_di_rinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
unsigned char *rx_buf;
int reg;
int inp;
int n;
n = rudimentary_check(dev, DIR_IN);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
rx_buf = dev->usb_rx_buf;
if (dev->board.model == VMK8061_MODEL) {
reg = VMK8061_DI_REG;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_DI;
} else {
reg = VMK8055_DI_REG;
}
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(dev))
break;
if (dev->board.model == VMK8055_MODEL)
inp = (((rx_buf[reg] >> 4) & 0x03) |
((rx_buf[reg] << 2) & 0x04) |
((rx_buf[reg] >> 3) & 0x18));
else
inp = rx_buf[reg];
data[n] = (inp >> chan) & 1;
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_do_winsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
unsigned char *tx_buf;
int reg;
int cmd;
int n;
n = rudimentary_check(dev, DIR_OUT);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
tx_buf = dev->usb_tx_buf;
for (n = 0; n < insn->n; n++) {
if (dev->board.model == VMK8055_MODEL) {
reg = VMK8055_DO_REG;
cmd = VMK8055_CMD_WRT_AD;
if (data[n] == 1)
tx_buf[reg] |= (1 << chan);
else
tx_buf[reg] ^= (1 << chan);
} else {
reg = VMK8061_DO_REG;
if (data[n] == 1) {
cmd = VMK8061_CMD_SET_DO;
tx_buf[reg] = 1 << chan;
} else {
cmd = VMK8061_CMD_CLR_DO;
tx_buf[reg] = 0xff - (1 << chan);
}
}
if (vmk80xx_write_packet(dev, cmd))
break;
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_do_rinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
int reg;
int n;
n = rudimentary_check(dev, DIR_IN);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
reg = VMK8061_DO_REG;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_DO;
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(dev))
break;
data[n] = (dev->usb_rx_buf[reg] >> chan) & 1;
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_do_bits(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
unsigned char *rx_buf, *tx_buf;
int dir, reg, cmd;
int retval;
dir = 0;
if (data[0])
dir |= DIR_OUT;
if (dev->board.model == VMK8061_MODEL)
dir |= DIR_IN;
retval = rudimentary_check(dev, dir);
if (retval)
return retval;
down(&dev->limit_sem);
rx_buf = dev->usb_rx_buf;
tx_buf = dev->usb_tx_buf;
if (data[0]) {
if (dev->board.model == VMK8055_MODEL) {
reg = VMK8055_DO_REG;
cmd = VMK8055_CMD_WRT_AD;
} else {
reg = VMK8061_DO_REG;
cmd = VMK8061_CMD_DO;
}
tx_buf[reg] &= ~data[0];
tx_buf[reg] |= (data[0] & data[1]);
retval = vmk80xx_write_packet(dev, cmd);
if (retval)
goto out;
}
if (dev->board.model == VMK8061_MODEL) {
reg = VMK8061_DO_REG;
tx_buf[0] = VMK8061_CMD_RD_DO;
retval = vmk80xx_read_packet(dev);
if (!retval) {
data[1] = rx_buf[reg];
retval = 2;
}
} else {
data[1] = tx_buf[reg];
retval = 2;
}
out:
up(&dev->limit_sem);
return retval;
}
static int vmk80xx_cnt_rinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int chan;
int reg[2];
int n;
n = rudimentary_check(dev, DIR_IN);
if (n)
return n;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
switch (dev->board.model) {
case VMK8055_MODEL:
if (!chan)
reg[0] = VMK8055_CNT1_REG;
else
reg[0] = VMK8055_CNT2_REG;
break;
case VMK8061_MODEL:
reg[0] = VMK8061_CNT_REG;
reg[1] = VMK8061_CNT_REG;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_CNT;
break;
}
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(dev))
break;
if (dev->board.model == VMK8055_MODEL)
data[n] = dev->usb_rx_buf[reg[0]];
else
data[n] = dev->usb_rx_buf[reg[0] * (chan + 1) + 1]
+ 256 * dev->usb_rx_buf[reg[1] * 2 + 2];
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_cnt_cinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
unsigned int insn_cmd;
int chan;
int cmd;
int reg;
int n;
n = rudimentary_check(dev, DIR_OUT);
if (n)
return n;
insn_cmd = data[0];
if (insn_cmd != INSN_CONFIG_RESET && insn_cmd != GPCT_RESET)
return -EINVAL;
down(&dev->limit_sem);
chan = CR_CHAN(insn->chanspec);
if (dev->board.model == VMK8055_MODEL) {
if (!chan) {
cmd = VMK8055_CMD_RST_CNT1;
reg = VMK8055_CNT1_REG;
} else {
cmd = VMK8055_CMD_RST_CNT2;
reg = VMK8055_CNT2_REG;
}
dev->usb_tx_buf[reg] = 0x00;
} else {
cmd = VMK8061_CMD_RST_CNT;
}
for (n = 0; n < insn->n; n++)
if (vmk80xx_write_packet(dev, cmd))
break;
up(&dev->limit_sem);
return n;
}
static int vmk80xx_cnt_winsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
unsigned long debtime;
unsigned long val;
int chan;
int cmd;
int n;
n = rudimentary_check(dev, DIR_OUT);
if (n)
return n;
down(&dev->limit_sem);
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
dev->usb_tx_buf[6 + chan] = val;
if (vmk80xx_write_packet(dev, cmd))
break;
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_pwm_rinsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
int reg[2];
int n;
n = rudimentary_check(dev, DIR_IN);
if (n)
return n;
down(&dev->limit_sem);
reg[0] = VMK8061_PWM_REG1;
reg[1] = VMK8061_PWM_REG2;
dev->usb_tx_buf[0] = VMK8061_CMD_RD_PWM;
for (n = 0; n < insn->n; n++) {
if (vmk80xx_read_packet(dev))
break;
data[n] = dev->usb_rx_buf[reg[0]] + 4 * dev->usb_rx_buf[reg[1]];
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_pwm_winsn(struct comedi_device *cdev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct vmk80xx_usb *dev = cdev->private;
unsigned char *tx_buf;
int reg[2];
int cmd;
int n;
n = rudimentary_check(dev, DIR_OUT);
if (n)
return n;
down(&dev->limit_sem);
tx_buf = dev->usb_tx_buf;
reg[0] = VMK8061_PWM_REG1;
reg[1] = VMK8061_PWM_REG2;
cmd = VMK8061_CMD_OUT_PWM;
for (n = 0; n < insn->n; n++) {
tx_buf[reg[0]] = (unsigned char)(data[n] & 0x03);
tx_buf[reg[1]] = (unsigned char)(data[n] >> 2) & 0xff;
if (vmk80xx_write_packet(dev, cmd))
break;
}
up(&dev->limit_sem);
return n;
}
static int vmk80xx_attach_common(struct comedi_device *cdev,
struct vmk80xx_usb *dev)
{
int n_subd;
struct comedi_subdevice *s;
int ret;
down(&dev->limit_sem);
cdev->board_name = dev->board.name;
cdev->private = dev;
if (dev->board.model == VMK8055_MODEL)
n_subd = 5;
else
n_subd = 6;
ret = comedi_alloc_subdevices(cdev, n_subd);
if (ret) {
up(&dev->limit_sem);
return ret;
}
s = cdev->subdevices + VMK80XX_SUBD_AI;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = dev->board.ai_chans;
s->maxdata = (1 << dev->board.ai_bits) - 1;
s->range_table = dev->board.range;
s->insn_read = vmk80xx_ai_rinsn;
s = cdev->subdevices + VMK80XX_SUBD_AO;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND;
s->n_chan = dev->board.ao_chans;
s->maxdata = (1 << dev->board.ao_bits) - 1;
s->range_table = dev->board.range;
s->insn_write = vmk80xx_ao_winsn;
if (dev->board.model == VMK8061_MODEL) {
s->subdev_flags |= SDF_READABLE;
s->insn_read = vmk80xx_ao_rinsn;
}
s = cdev->subdevices + VMK80XX_SUBD_DI;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = dev->board.di_chans;
s->maxdata = 1;
s->insn_read = vmk80xx_di_rinsn;
s->insn_bits = vmk80xx_di_bits;
s = cdev->subdevices + VMK80XX_SUBD_DO;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND;
s->n_chan = dev->board.do_chans;
s->maxdata = 1;
s->insn_write = vmk80xx_do_winsn;
s->insn_bits = vmk80xx_do_bits;
if (dev->board.model == VMK8061_MODEL) {
s->subdev_flags |= SDF_READABLE;
s->insn_read = vmk80xx_do_rinsn;
}
s = cdev->subdevices + VMK80XX_SUBD_CNT;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE;
s->n_chan = dev->board.cnt_chans;
s->insn_read = vmk80xx_cnt_rinsn;
s->insn_config = vmk80xx_cnt_cinsn;
if (dev->board.model == VMK8055_MODEL) {
s->subdev_flags |= SDF_WRITEABLE;
s->maxdata = (1 << dev->board.cnt_bits) - 1;
s->insn_write = vmk80xx_cnt_winsn;
}
if (dev->board.model == VMK8061_MODEL) {
s = cdev->subdevices + VMK80XX_SUBD_PWM;
s->type = COMEDI_SUBD_PWM;
s->subdev_flags = SDF_READABLE | SDF_WRITEABLE;
s->n_chan = dev->board.pwm_chans;
s->maxdata = (1 << dev->board.pwm_bits) - 1;
s->insn_read = vmk80xx_pwm_rinsn;
s->insn_write = vmk80xx_pwm_winsn;
}
dev->attached = 1;
dev_info(cdev->class_dev, "vmk80xx: board #%d [%s] attached\n",
dev->count, dev->board.name);
up(&dev->limit_sem);
return 0;
}
static int vmk80xx_attach(struct comedi_device *cdev,
struct comedi_devconfig *it)
{
int i;
int ret;
mutex_lock(&glb_mutex);
for (i = 0; i < VMK80XX_MAX_BOARDS; i++)
if (vmb[i].probed && !vmb[i].attached)
break;
if (i == VMK80XX_MAX_BOARDS)
ret = -ENODEV;
else
ret = vmk80xx_attach_common(cdev, &vmb[i]);
mutex_unlock(&glb_mutex);
return ret;
}
static int vmk80xx_attach_usb(struct comedi_device *cdev,
struct usb_interface *intf)
{
int i;
int ret;
mutex_lock(&glb_mutex);
for (i = 0; i < VMK80XX_MAX_BOARDS; i++)
if (vmb[i].probed && vmb[i].intf == intf)
break;
if (i == VMK80XX_MAX_BOARDS)
ret = -ENODEV;
else if (vmb[i].attached)
ret = -EBUSY;
else
ret = vmk80xx_attach_common(cdev, &vmb[i]);
mutex_unlock(&glb_mutex);
return ret;
}
static void vmk80xx_detach(struct comedi_device *dev)
{
struct vmk80xx_usb *usb = dev->private;
if (usb) {
down(&usb->limit_sem);
dev->private = NULL;
usb->attached = 0;
up(&usb->limit_sem);
}
}
static int vmk80xx_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int i;
struct vmk80xx_usb *dev;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *ep_desc;
size_t size;
mutex_lock(&glb_mutex);
for (i = 0; i < VMK80XX_MAX_BOARDS; i++)
if (!vmb[i].probed)
break;
if (i == VMK80XX_MAX_BOARDS) {
mutex_unlock(&glb_mutex);
return -EMFILE;
}
dev = &vmb[i];
memset(dev, 0x00, sizeof(struct vmk80xx_usb));
dev->count = i;
iface_desc = intf->cur_altsetting;
if (iface_desc->desc.bNumEndpoints != 2)
goto error;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
ep_desc = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_int_in(ep_desc)) {
dev->ep_rx = ep_desc;
continue;
}
if (usb_endpoint_is_int_out(ep_desc)) {
dev->ep_tx = ep_desc;
continue;
}
if (usb_endpoint_is_bulk_in(ep_desc)) {
dev->ep_rx = ep_desc;
continue;
}
if (usb_endpoint_is_bulk_out(ep_desc)) {
dev->ep_tx = ep_desc;
continue;
}
}
if (!dev->ep_rx || !dev->ep_tx)
goto error;
size = le16_to_cpu(dev->ep_rx->wMaxPacketSize);
dev->usb_rx_buf = kmalloc(size, GFP_KERNEL);
if (!dev->usb_rx_buf) {
mutex_unlock(&glb_mutex);
return -ENOMEM;
}
size = le16_to_cpu(dev->ep_tx->wMaxPacketSize);
dev->usb_tx_buf = kmalloc(size, GFP_KERNEL);
if (!dev->usb_tx_buf) {
kfree(dev->usb_rx_buf);
mutex_unlock(&glb_mutex);
return -ENOMEM;
}
dev->udev = interface_to_usbdev(intf);
dev->intf = intf;
sema_init(&dev->limit_sem, 8);
init_waitqueue_head(&dev->read_wait);
init_waitqueue_head(&dev->write_wait);
init_usb_anchor(&dev->rx_anchor);
init_usb_anchor(&dev->tx_anchor);
usb_set_intfdata(intf, dev);
switch (id->driver_info) {
case DEVICE_VMK8055:
dev->board.name = "K8055 (VM110)";
dev->board.model = VMK8055_MODEL;
dev->board.range = &vmk8055_range;
dev->board.ai_chans = 2;
dev->board.ai_bits = 8;
dev->board.ao_chans = 2;
dev->board.ao_bits = 8;
dev->board.di_chans = 5;
dev->board.di_bits = 1;
dev->board.do_chans = 8;
dev->board.do_bits = 1;
dev->board.cnt_chans = 2;
dev->board.cnt_bits = 16;
dev->board.pwm_chans = 0;
dev->board.pwm_bits = 0;
break;
case DEVICE_VMK8061:
dev->board.name = "K8061 (VM140)";
dev->board.model = VMK8061_MODEL;
dev->board.range = &vmk8061_range;
dev->board.ai_chans = 8;
dev->board.ai_bits = 10;
dev->board.ao_chans = 8;
dev->board.ao_bits = 8;
dev->board.di_chans = 8;
dev->board.di_bits = 1;
dev->board.do_chans = 8;
dev->board.do_bits = 1;
dev->board.cnt_chans = 2;
dev->board.cnt_bits = 0;
dev->board.pwm_chans = 1;
dev->board.pwm_bits = 10;
break;
}
if (dev->board.model == VMK8061_MODEL) {
vmk80xx_read_eeprom(dev, IC3_VERSION);
printk(KERN_INFO "comedi#: vmk80xx: %s\n", dev->fw.ic3_vers);
if (vmk80xx_check_data_link(dev)) {
vmk80xx_read_eeprom(dev, IC6_VERSION);
printk(KERN_INFO "comedi#: vmk80xx: %s\n",
dev->fw.ic6_vers);
} else {
dbgcm("comedi#: vmk80xx: no conn. to CPU\n");
}
}
if (dev->board.model == VMK8055_MODEL)
vmk80xx_reset_device(dev);
dev->probed = 1;
printk(KERN_INFO "comedi#: vmk80xx: board #%d [%s] now attached\n",
dev->count, dev->board.name);
mutex_unlock(&glb_mutex);
comedi_usb_auto_config(intf, &vmk80xx_driver);
return 0;
error:
mutex_unlock(&glb_mutex);
return -ENODEV;
}
static void vmk80xx_usb_disconnect(struct usb_interface *intf)
{
struct vmk80xx_usb *dev = usb_get_intfdata(intf);
if (!dev)
return;
comedi_usb_auto_unconfig(intf);
mutex_lock(&glb_mutex);
down(&dev->limit_sem);
dev->probed = 0;
usb_set_intfdata(dev->intf, NULL);
usb_kill_anchored_urbs(&dev->rx_anchor);
usb_kill_anchored_urbs(&dev->tx_anchor);
kfree(dev->usb_rx_buf);
kfree(dev->usb_tx_buf);
printk(KERN_INFO "comedi#: vmk80xx: board #%d [%s] now detached\n",
dev->count, dev->board.name);
up(&dev->limit_sem);
mutex_unlock(&glb_mutex);
}
