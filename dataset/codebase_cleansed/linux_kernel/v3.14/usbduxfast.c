static int usbduxfast_send_cmd(struct comedi_device *dev, int cmd_type)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbduxfast_private *devpriv = dev->private;
int nsent;
int ret;
devpriv->duxbuf[0] = cmd_type;
ret = usb_bulk_msg(usb, usb_sndbulkpipe(usb, CHANNELLISTEP),
devpriv->duxbuf, SIZEOFDUXBUF,
&nsent, 10000);
if (ret < 0)
dev_err(dev->class_dev,
"could not transmit command to the usb-device, err=%d\n",
ret);
return ret;
}
static void usbduxfast_cmd_data(struct comedi_device *dev, int index,
uint8_t len, uint8_t op, uint8_t out,
uint8_t log)
{
struct usbduxfast_private *devpriv = dev->private;
devpriv->duxbuf[1 + 0x00 + index] = len;
devpriv->duxbuf[1 + 0x08 + index] = op;
devpriv->duxbuf[1 + 0x10 + index] = out;
devpriv->duxbuf[1 + 0x18 + index] = log;
}
static int usbduxfast_ai_stop(struct comedi_device *dev, int do_unlink)
{
struct usbduxfast_private *devpriv = dev->private;
devpriv->ai_cmd_running = 0;
if (do_unlink && devpriv->urb) {
usb_kill_urb(devpriv->urb);
}
return 0;
}
static int usbduxfast_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbduxfast_private *devpriv = dev->private;
int ret;
if (!devpriv)
return -EFAULT;
down(&devpriv->sem);
ret = usbduxfast_ai_stop(dev, 1);
up(&devpriv->sem);
return ret;
}
static void usbduxfast_ai_interrupt(struct urb *urb)
{
struct comedi_device *dev = urb->context;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbduxfast_private *devpriv = dev->private;
int n, err;
if (unlikely(!devpriv->ai_cmd_running)) {
return;
}
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
async->events |= COMEDI_CB_EOA;
async->events |= COMEDI_CB_ERROR;
comedi_event(dev, s);
usbduxfast_ai_stop(dev, 0);
return;
default:
pr_err("non-zero urb status received in ai intr context: %d\n",
urb->status);
async->events |= COMEDI_CB_EOA;
async->events |= COMEDI_CB_ERROR;
comedi_event(dev, s);
usbduxfast_ai_stop(dev, 0);
return;
}
if (!devpriv->ignore) {
if (!devpriv->ai_continous) {
n = urb->actual_length / sizeof(uint16_t);
if (unlikely(devpriv->ai_sample_count < n)) {
unsigned int num_bytes;
num_bytes = devpriv->ai_sample_count *
sizeof(uint16_t);
cfc_write_array_to_buffer(s,
urb->transfer_buffer,
num_bytes);
usbduxfast_ai_stop(dev, 0);
async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
return;
}
devpriv->ai_sample_count -= n;
}
err = cfc_write_array_to_buffer(s, urb->transfer_buffer,
urb->actual_length);
if (unlikely(err == 0)) {
usbduxfast_ai_stop(dev, 0);
return;
}
comedi_event(dev, s);
} else {
devpriv->ignore--;
}
urb->dev = usb;
urb->status = 0;
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
dev_err(dev->class_dev,
"urb resubm failed: %d", err);
async->events |= COMEDI_CB_EOA;
async->events |= COMEDI_CB_ERROR;
comedi_event(dev, s);
usbduxfast_ai_stop(dev, 0);
}
}
static int usbduxfast_submit_urb(struct comedi_device *dev)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbduxfast_private *devpriv = dev->private;
int ret;
if (!devpriv)
return -EFAULT;
usb_fill_bulk_urb(devpriv->urb, usb, usb_rcvbulkpipe(usb, BULKINEP),
devpriv->inbuf, SIZEINBUF,
usbduxfast_ai_interrupt, dev);
ret = usb_submit_urb(devpriv->urb, GFP_ATOMIC);
if (ret) {
dev_err(dev->class_dev, "usb_submit_urb error %d\n", ret);
return ret;
}
return 0;
}
static int usbduxfast_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
long int steps, tmp;
int min_sample_period;
err |= cfc_check_trigger_src(&cmd->start_src,
TRIG_NOW | TRIG_EXT | TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->start_src == TRIG_EXT && cmd->stop_src == TRIG_EXT)
err |= -EINVAL;
if (err)
return 2;
if (cmd->start_src == TRIG_NOW)
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (!cmd->chanlist_len)
err |= -EINVAL;
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->chanlist_len == 1)
min_sample_period = 1;
else
min_sample_period = MIN_SAMPLING_PERIOD;
if (cmd->convert_src == TRIG_TIMER) {
steps = cmd->convert_arg * 30;
if (steps < (min_sample_period * 1000))
steps = min_sample_period * 1000;
if (steps > (MAX_SAMPLING_PERIOD * 1000))
steps = MAX_SAMPLING_PERIOD * 1000;
tmp = steps / 30;
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, tmp);
}
if (cmd->scan_begin_src == TRIG_TIMER)
err |= -EINVAL;
switch (cmd->stop_src) {
case TRIG_COUNT:
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
break;
case TRIG_NONE:
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
default:
break;
}
if (err)
return 3;
return 0;
}
static int usbduxfast_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trignum)
{
struct usbduxfast_private *devpriv = dev->private;
int ret;
if (!devpriv)
return -EFAULT;
down(&devpriv->sem);
if (trignum != 0) {
dev_err(dev->class_dev, "invalid trignum\n");
up(&devpriv->sem);
return -EINVAL;
}
if (!devpriv->ai_cmd_running) {
devpriv->ai_cmd_running = 1;
ret = usbduxfast_submit_urb(dev);
if (ret < 0) {
dev_err(dev->class_dev, "urbSubmit: err=%d\n", ret);
devpriv->ai_cmd_running = 0;
up(&devpriv->sem);
return ret;
}
s->async->inttrig = NULL;
} else {
dev_err(dev->class_dev, "ai is already running\n");
}
up(&devpriv->sem);
return 1;
}
static int usbduxfast_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbduxfast_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int chan, gain, rngmask = 0xff;
int i, j, ret;
int result;
long steps, steps_tmp;
if (!devpriv)
return -EFAULT;
down(&devpriv->sem);
if (devpriv->ai_cmd_running) {
dev_err(dev->class_dev, "ai_cmd not possible\n");
up(&devpriv->sem);
return -EBUSY;
}
s->async->cur_chan = 0;
devpriv->ignore = PACKETS_TO_IGNORE;
if (cmd->chanlist_len > 0) {
gain = CR_RANGE(cmd->chanlist[0]);
for (i = 0; i < cmd->chanlist_len; ++i) {
chan = CR_CHAN(cmd->chanlist[i]);
if (chan != i) {
dev_err(dev->class_dev,
"channels are not consecutive\n");
up(&devpriv->sem);
return -EINVAL;
}
if ((gain != CR_RANGE(cmd->chanlist[i]))
&& (cmd->chanlist_len > 3)) {
dev_err(dev->class_dev,
"gain must be the same for all channels\n");
up(&devpriv->sem);
return -EINVAL;
}
if (i >= NUMCHANNELS) {
dev_err(dev->class_dev, "chanlist too long\n");
break;
}
}
}
steps = 0;
if (cmd->scan_begin_src == TRIG_TIMER) {
dev_err(dev->class_dev,
"scan_begin_src==TRIG_TIMER not valid\n");
up(&devpriv->sem);
return -EINVAL;
}
if (cmd->convert_src == TRIG_TIMER)
steps = (cmd->convert_arg * 30) / 1000;
if ((steps < MIN_SAMPLING_PERIOD) && (cmd->chanlist_len != 1)) {
dev_err(dev->class_dev,
"steps=%ld, scan_begin_arg=%d. Not properly tested by cmdtest?\n",
steps, cmd->scan_begin_arg);
up(&devpriv->sem);
return -EINVAL;
}
if (steps > MAX_SAMPLING_PERIOD) {
dev_err(dev->class_dev, "sampling rate too low\n");
up(&devpriv->sem);
return -EINVAL;
}
if ((cmd->start_src == TRIG_EXT) && (cmd->chanlist_len != 1)
&& (cmd->chanlist_len != 16)) {
dev_err(dev->class_dev,
"TRIG_EXT only with 1 or 16 channels possible\n");
up(&devpriv->sem);
return -EINVAL;
}
switch (cmd->chanlist_len) {
case 1:
if (CR_RANGE(cmd->chanlist[0]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
if (cmd->start_src == TRIG_EXT) {
usbduxfast_cmd_data(dev, 0, 0x01, 0x01, rngmask, 0x00);
} else {
usbduxfast_cmd_data(dev, 0, 0x01, 0x00, rngmask, 0x00);
}
if (steps < MIN_SAMPLING_PERIOD) {
if (steps <= 1) {
usbduxfast_cmd_data(dev, 1,
0x89, 0x03, rngmask, 0xff);
} else {
usbduxfast_cmd_data(dev, 1, steps - 1,
0x02, rngmask, 0x00);
usbduxfast_cmd_data(dev, 2,
0x09, 0x01, rngmask, 0xff);
}
} else {
steps = steps - 1;
usbduxfast_cmd_data(dev, 1,
steps / 2, 0x00, rngmask, 0x00);
usbduxfast_cmd_data(dev, 2, steps - steps / 2,
0x00, rngmask, 0x00);
usbduxfast_cmd_data(dev, 3,
0x09, 0x03, rngmask, 0xff);
}
break;
case 2:
if (CR_RANGE(cmd->chanlist[0]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
usbduxfast_cmd_data(dev, 0, 0x01, 0x02, rngmask, 0x00);
steps_tmp = steps - 1;
if (CR_RANGE(cmd->chanlist[1]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
usbduxfast_cmd_data(dev, 1, steps_tmp / 2,
0x00, 0xfe & rngmask, 0x00);
usbduxfast_cmd_data(dev, 2, steps_tmp - steps_tmp / 2,
0x00, rngmask, 0x00);
usbduxfast_cmd_data(dev, 3, 0x01, 0x02, rngmask, 0x00);
steps_tmp = steps - 2;
if (CR_RANGE(cmd->chanlist[0]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
usbduxfast_cmd_data(dev, 4, steps_tmp / 2,
0x00, (0xff - 0x02) & rngmask, 0x00);
usbduxfast_cmd_data(dev, 5, steps_tmp - steps_tmp / 2,
0x00, rngmask, 0x00);
usbduxfast_cmd_data(dev, 6, 0x01, 0x00, rngmask, 0x00);
break;
case 3:
for (j = 0; j < 1; j++) {
int index = j * 2;
if (CR_RANGE(cmd->chanlist[j]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
usbduxfast_cmd_data(dev, index, steps / 2,
0x02, rngmask, 0x00);
if (CR_RANGE(cmd->chanlist[j + 1]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
usbduxfast_cmd_data(dev, index + 1, steps - steps / 2,
0x00, 0xfe & rngmask, 0x00);
}
steps_tmp = steps - 2;
usbduxfast_cmd_data(dev, 4, steps_tmp / 2,
0x02, rngmask, 0x00);
if (CR_RANGE(cmd->chanlist[0]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
usbduxfast_cmd_data(dev, 5, steps_tmp - steps_tmp / 2,
0x00, (0xff - 0x02) & rngmask, 0x00);
usbduxfast_cmd_data(dev, 6, 0x01, 0x00, rngmask, 0x00);
case 16:
if (CR_RANGE(cmd->chanlist[0]) > 0)
rngmask = 0xff - 0x04;
else
rngmask = 0xff;
if (cmd->start_src == TRIG_EXT) {
usbduxfast_cmd_data(dev, 0, 0x01, 0x01,
(0xff - 0x02) & rngmask, 0x00);
} else {
usbduxfast_cmd_data(dev, 0, 0xff, 0x00,
(0xff - 0x02) & rngmask, 0x00);
}
usbduxfast_cmd_data(dev, 1, 0x01, 0x02, rngmask, 0x00);
steps = steps - 2;
usbduxfast_cmd_data(dev, 2, steps / 2,
0x00, 0xfe & rngmask, 0x00);
usbduxfast_cmd_data(dev, 3, steps - steps / 2,
0x00, rngmask, 0x00);
usbduxfast_cmd_data(dev, 4, 0x09, 0x01, rngmask, 0xff);
break;
default:
dev_err(dev->class_dev, "unsupported combination of channels\n");
up(&devpriv->sem);
return -EFAULT;
}
result = usbduxfast_send_cmd(dev, SENDADCOMMANDS);
if (result < 0) {
up(&devpriv->sem);
return result;
}
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ai_sample_count = cmd->stop_arg * cmd->scan_end_arg;
if (devpriv->ai_sample_count < 1) {
dev_err(dev->class_dev,
"(cmd->stop_arg)*(cmd->scan_end_arg)<1, aborting\n");
up(&devpriv->sem);
return -EFAULT;
}
devpriv->ai_continous = 0;
} else {
devpriv->ai_continous = 1;
devpriv->ai_sample_count = 0;
}
if ((cmd->start_src == TRIG_NOW) || (cmd->start_src == TRIG_EXT)) {
devpriv->ai_cmd_running = 1;
ret = usbduxfast_submit_urb(dev);
if (ret < 0) {
devpriv->ai_cmd_running = 0;
up(&devpriv->sem);
return ret;
}
s->async->inttrig = NULL;
} else {
s->async->inttrig = usbduxfast_ai_inttrig;
}
up(&devpriv->sem);
return 0;
}
static int usbduxfast_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbduxfast_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
uint8_t rngmask = range ? (0xff - 0x04) : 0xff;
int i, j, n, actual_length;
int ret;
down(&devpriv->sem);
if (devpriv->ai_cmd_running) {
dev_err(dev->class_dev,
"ai_insn_read not possible, async cmd is running\n");
up(&devpriv->sem);
return -EBUSY;
}
usbduxfast_cmd_data(dev, 0, 0x01, 0x02, rngmask, 0x00);
usbduxfast_cmd_data(dev, 1, 0x0c, 0x00, 0xfe & rngmask, 0x00);
usbduxfast_cmd_data(dev, 2, 0x01, 0x00, 0xfe & rngmask, 0x00);
usbduxfast_cmd_data(dev, 3, 0x01, 0x00, 0xfe & rngmask, 0x00);
usbduxfast_cmd_data(dev, 4, 0x01, 0x00, 0xfe & rngmask, 0x00);
usbduxfast_cmd_data(dev, 5, 0x0c, 0x00, rngmask, 0x00);
usbduxfast_cmd_data(dev, 6, 0x01, 0x00, rngmask, 0x00);
ret = usbduxfast_send_cmd(dev, SENDADCOMMANDS);
if (ret < 0) {
up(&devpriv->sem);
return ret;
}
for (i = 0; i < PACKETS_TO_IGNORE; i++) {
ret = usb_bulk_msg(usb, usb_rcvbulkpipe(usb, BULKINEP),
devpriv->inbuf, SIZEINBUF,
&actual_length, 10000);
if (ret < 0) {
dev_err(dev->class_dev, "insn timeout, no data\n");
up(&devpriv->sem);
return ret;
}
}
for (i = 0; i < insn->n;) {
ret = usb_bulk_msg(usb, usb_rcvbulkpipe(usb, BULKINEP),
devpriv->inbuf, SIZEINBUF,
&actual_length, 10000);
if (ret < 0) {
dev_err(dev->class_dev, "insn data error: %d\n", ret);
up(&devpriv->sem);
return ret;
}
n = actual_length / sizeof(uint16_t);
if ((n % 16) != 0) {
dev_err(dev->class_dev, "insn data packet corrupted\n");
up(&devpriv->sem);
return -EINVAL;
}
for (j = chan; (j < n) && (i < insn->n); j = j + 16) {
data[i] = ((uint16_t *) (devpriv->inbuf))[j];
i++;
}
}
up(&devpriv->sem);
return insn->n;
}
static int usbduxfast_attach_common(struct comedi_device *dev)
{
struct usbduxfast_private *devpriv = dev->private;
struct comedi_subdevice *s;
int ret;
down(&devpriv->sem);
ret = comedi_alloc_subdevices(dev, 1);
if (ret) {
up(&devpriv->sem);
return ret;
}
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_CMD_READ;
s->n_chan = 16;
s->len_chanlist = 16;
s->insn_read = usbduxfast_ai_insn_read;
s->do_cmdtest = usbduxfast_ai_cmdtest;
s->do_cmd = usbduxfast_ai_cmd;
s->cancel = usbduxfast_ai_cancel;
s->maxdata = 0x1000;
s->range_table = &range_usbduxfast_ai_range;
up(&devpriv->sem);
return 0;
}
static int usbduxfast_upload_firmware(struct comedi_device *dev,
const u8 *data, size_t size,
unsigned long context)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
uint8_t *buf;
unsigned char *tmp;
int ret;
if (!data)
return 0;
if (size > FIRMWARE_MAX_LEN) {
dev_err(dev->class_dev, "firmware binary too large for FX2\n");
return -ENOMEM;
}
buf = kmemdup(data, size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
tmp = kmalloc(1, GFP_KERNEL);
if (!tmp) {
kfree(buf);
return -ENOMEM;
}
*tmp = 1;
ret = usb_control_msg(usb, usb_sndctrlpipe(usb, 0),
USBDUXFASTSUB_FIRMWARE,
VENDOR_DIR_OUT,
USBDUXFASTSUB_CPUCS, 0x0000,
tmp, 1,
EZTIMEOUT);
if (ret < 0) {
dev_err(dev->class_dev, "can not stop firmware\n");
goto done;
}
ret = usb_control_msg(usb, usb_sndctrlpipe(usb, 0),
USBDUXFASTSUB_FIRMWARE,
VENDOR_DIR_OUT,
0, 0x0000,
buf, size,
EZTIMEOUT);
if (ret < 0) {
dev_err(dev->class_dev, "firmware upload failed\n");
goto done;
}
*tmp = 0;
ret = usb_control_msg(usb, usb_sndctrlpipe(usb, 0),
USBDUXFASTSUB_FIRMWARE,
VENDOR_DIR_OUT,
USBDUXFASTSUB_CPUCS, 0x0000,
tmp, 1,
EZTIMEOUT);
if (ret < 0)
dev_err(dev->class_dev, "can not start firmware\n");
done:
kfree(tmp);
kfree(buf);
return ret;
}
static int usbduxfast_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbduxfast_private *devpriv;
int ret;
if (usb->speed != USB_SPEED_HIGH) {
dev_err(dev->class_dev,
"This driver needs USB 2.0 to operate. Aborting...\n");
return -ENODEV;
}
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
sema_init(&devpriv->sem, 1);
usb_set_intfdata(intf, devpriv);
devpriv->duxbuf = kmalloc(SIZEOFDUXBUF, GFP_KERNEL);
if (!devpriv->duxbuf)
return -ENOMEM;
ret = usb_set_interface(usb,
intf->altsetting->desc.bInterfaceNumber, 1);
if (ret < 0) {
dev_err(dev->class_dev,
"could not switch to alternate setting 1\n");
return -ENODEV;
}
devpriv->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!devpriv->urb) {
dev_err(dev->class_dev, "Could not alloc. urb\n");
return -ENOMEM;
}
devpriv->inbuf = kmalloc(SIZEINBUF, GFP_KERNEL);
if (!devpriv->inbuf)
return -ENOMEM;
ret = comedi_load_firmware(dev, &usb->dev, FIRMWARE,
usbduxfast_upload_firmware, 0);
if (ret)
return ret;
return usbduxfast_attach_common(dev);
}
static void usbduxfast_detach(struct comedi_device *dev)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct usbduxfast_private *devpriv = dev->private;
if (!devpriv)
return;
down(&devpriv->sem);
usb_set_intfdata(intf, NULL);
if (devpriv->urb) {
usb_kill_urb(devpriv->urb);
kfree(devpriv->inbuf);
devpriv->inbuf = NULL;
usb_free_urb(devpriv->urb);
devpriv->urb = NULL;
}
kfree(devpriv->duxbuf);
devpriv->duxbuf = NULL;
devpriv->ai_cmd_running = 0;
up(&devpriv->sem);
}
static int usbduxfast_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return comedi_usb_auto_config(intf, &usbduxfast_driver, 0);
}
