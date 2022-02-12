static void usbdux_unlink_urbs(struct urb **urbs, int num_urbs)
{
int i;
for (i = 0; i < num_urbs; i++)
usb_kill_urb(urbs[i]);
}
static void usbdux_ai_stop(struct comedi_device *dev, int do_unlink)
{
struct usbdux_private *devpriv = dev->private;
if (do_unlink && devpriv->ai_urbs)
usbdux_unlink_urbs(devpriv->ai_urbs, devpriv->n_ai_urbs);
devpriv->ai_cmd_running = 0;
}
static int usbdux_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbdux_private *devpriv = dev->private;
mutex_lock(&devpriv->mut);
usbdux_ai_stop(dev, devpriv->ai_cmd_running);
mutex_unlock(&devpriv->mut);
return 0;
}
static void usbduxsub_ai_handle_urb(struct comedi_device *dev,
struct comedi_subdevice *s,
struct urb *urb)
{
struct usbdux_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
int ret;
int i;
devpriv->ai_counter--;
if (devpriv->ai_counter == 0) {
devpriv->ai_counter = devpriv->ai_timer;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int range = CR_RANGE(cmd->chanlist[i]);
u16 val = le16_to_cpu(devpriv->in_buf[i]);
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
if (!comedi_buf_write_samples(s, &val, 1))
return;
}
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
}
if (!(async->events & COMEDI_CB_CANCEL_MASK)) {
urb->dev = comedi_to_usb_dev(dev);
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret < 0) {
dev_err(dev->class_dev,
"urb resubmit failed in int-context! err=%d\n",
ret);
if (ret == -EL2NSYNC)
dev_err(dev->class_dev,
"buggy USB host controller or bug in IRQ handler!\n");
async->events |= COMEDI_CB_ERROR;
}
}
}
static void usbduxsub_ai_isoc_irq(struct urb *urb)
{
struct comedi_device *dev = urb->context;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct usbdux_private *devpriv = dev->private;
if (!devpriv->ai_cmd_running)
return;
switch (urb->status) {
case 0:
memcpy(devpriv->in_buf, urb->transfer_buffer, SIZEINBUF);
usbduxsub_ai_handle_urb(dev, s, urb);
break;
case -EILSEQ:
dev_dbg(dev->class_dev, "CRC error in ISO IN stream\n");
usbduxsub_ai_handle_urb(dev, s, urb);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
async->events |= COMEDI_CB_ERROR;
break;
default:
dev_err(dev->class_dev,
"Non-zero urb status received in ai intr context: %d\n",
urb->status);
async->events |= COMEDI_CB_ERROR;
break;
}
if (async->events & COMEDI_CB_CANCEL_MASK)
usbdux_ai_stop(dev, 0);
comedi_event(dev, s);
}
static void usbdux_ao_stop(struct comedi_device *dev, int do_unlink)
{
struct usbdux_private *devpriv = dev->private;
if (do_unlink && devpriv->ao_urbs)
usbdux_unlink_urbs(devpriv->ao_urbs, devpriv->n_ao_urbs);
devpriv->ao_cmd_running = 0;
}
static int usbdux_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbdux_private *devpriv = dev->private;
mutex_lock(&devpriv->mut);
usbdux_ao_stop(dev, devpriv->ao_cmd_running);
mutex_unlock(&devpriv->mut);
return 0;
}
static void usbduxsub_ao_handle_urb(struct comedi_device *dev,
struct comedi_subdevice *s,
struct urb *urb)
{
struct usbdux_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
u8 *datap;
int ret;
int i;
devpriv->ao_counter--;
if (devpriv->ao_counter == 0) {
devpriv->ao_counter = devpriv->ao_timer;
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
return;
}
datap = urb->transfer_buffer;
*datap++ = cmd->chanlist_len;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned short val;
if (!comedi_buf_read_samples(s, &val, 1)) {
dev_err(dev->class_dev, "buffer underflow\n");
async->events |= COMEDI_CB_OVERFLOW;
return;
}
*datap++ = val & 0xff;
*datap++ = (val >> 8) & 0xff;
*datap++ = chan << 6;
s->readback[chan] = val;
}
}
if (!(async->events & COMEDI_CB_CANCEL_MASK)) {
urb->transfer_buffer_length = SIZEOUTBUF;
urb->dev = comedi_to_usb_dev(dev);
urb->status = 0;
if (devpriv->high_speed)
urb->interval = 8;
else
urb->interval = 1;
urb->number_of_packets = 1;
urb->iso_frame_desc[0].offset = 0;
urb->iso_frame_desc[0].length = SIZEOUTBUF;
urb->iso_frame_desc[0].status = 0;
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret < 0) {
dev_err(dev->class_dev,
"ao urb resubm failed in int-cont. ret=%d",
ret);
if (ret == -EL2NSYNC)
dev_err(dev->class_dev,
"buggy USB host controller or bug in IRQ handling!\n");
async->events |= COMEDI_CB_ERROR;
}
}
}
static void usbduxsub_ao_isoc_irq(struct urb *urb)
{
struct comedi_device *dev = urb->context;
struct comedi_subdevice *s = dev->write_subdev;
struct comedi_async *async = s->async;
struct usbdux_private *devpriv = dev->private;
if (!devpriv->ao_cmd_running)
return;
switch (urb->status) {
case 0:
usbduxsub_ao_handle_urb(dev, s, urb);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
async->events |= COMEDI_CB_ERROR;
break;
default:
dev_err(dev->class_dev,
"Non-zero urb status received in ao intr context: %d\n",
urb->status);
async->events |= COMEDI_CB_ERROR;
break;
}
if (async->events & COMEDI_CB_CANCEL_MASK)
usbdux_ao_stop(dev, 0);
comedi_event(dev, s);
}
static int usbdux_submit_urbs(struct comedi_device *dev,
struct urb **urbs, int num_urbs,
int input_urb)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbdux_private *devpriv = dev->private;
struct urb *urb;
int ret;
int i;
for (i = 0; i < num_urbs; i++) {
urb = urbs[i];
if (input_urb)
urb->interval = devpriv->ai_interval;
urb->context = dev;
urb->dev = usb;
urb->status = 0;
urb->transfer_flags = URB_ISO_ASAP;
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret)
return ret;
}
return 0;
}
static int usbdux_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
struct usbdux_private *devpriv = dev->private;
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
unsigned int arg = 1000000;
unsigned int min_arg = arg;
if (devpriv->high_speed) {
int i = 1;
while (i < cmd->chanlist_len)
i = i * 2;
arg /= 8;
min_arg = arg * i;
}
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
min_arg);
arg = (cmd->scan_begin_arg / arg) * arg;
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static u8 create_adc_command(unsigned int chan, unsigned int range)
{
u8 p = (range <= 1);
u8 r = ((range % 2) == 0);
return (chan << 4) | ((p == 1) << 2) | ((r == 1) << 3);
}
static int send_dux_commands(struct comedi_device *dev, unsigned int cmd_type)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbdux_private *devpriv = dev->private;
int nsent;
devpriv->dux_commands[0] = cmd_type;
return usb_bulk_msg(usb, usb_sndbulkpipe(usb, 1),
devpriv->dux_commands, SIZEOFDUXBUFFER,
&nsent, BULK_TIMEOUT);
}
static int receive_dux_commands(struct comedi_device *dev, unsigned int command)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbdux_private *devpriv = dev->private;
int ret;
int nrec;
int i;
for (i = 0; i < RETRIES; i++) {
ret = usb_bulk_msg(usb, usb_rcvbulkpipe(usb, 8),
devpriv->insn_buf, SIZEINSNBUF,
&nrec, BULK_TIMEOUT);
if (ret < 0)
return ret;
if (le16_to_cpu(devpriv->insn_buf[0]) == command)
return ret;
}
return -EFAULT;
}
static int usbdux_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct usbdux_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int ret;
if (trig_num != cmd->start_arg)
return -EINVAL;
mutex_lock(&devpriv->mut);
if (!devpriv->ai_cmd_running) {
devpriv->ai_cmd_running = 1;
ret = usbdux_submit_urbs(dev, devpriv->ai_urbs,
devpriv->n_ai_urbs, 1);
if (ret < 0) {
devpriv->ai_cmd_running = 0;
goto ai_trig_exit;
}
s->async->inttrig = NULL;
} else {
ret = -EBUSY;
}
ai_trig_exit:
mutex_unlock(&devpriv->mut);
return ret;
}
static int usbdux_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct usbdux_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int len = cmd->chanlist_len;
int ret = -EBUSY;
int i;
mutex_lock(&devpriv->mut);
if (devpriv->ai_cmd_running)
goto ai_cmd_exit;
devpriv->dux_commands[1] = len;
for (i = 0; i < len; ++i) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
devpriv->dux_commands[i + 2] = create_adc_command(chan, range);
}
ret = send_dux_commands(dev, USBDUX_CMD_MULT_AI);
if (ret < 0)
goto ai_cmd_exit;
if (devpriv->high_speed) {
devpriv->ai_interval = 1;
while (devpriv->ai_interval < len)
devpriv->ai_interval *= 2;
devpriv->ai_timer = cmd->scan_begin_arg /
(125000 * devpriv->ai_interval);
} else {
devpriv->ai_interval = 1;
devpriv->ai_timer = cmd->scan_begin_arg / 1000000;
}
if (devpriv->ai_timer < 1) {
ret = -EINVAL;
goto ai_cmd_exit;
}
devpriv->ai_counter = devpriv->ai_timer;
if (cmd->start_src == TRIG_NOW) {
devpriv->ai_cmd_running = 1;
ret = usbdux_submit_urbs(dev, devpriv->ai_urbs,
devpriv->n_ai_urbs, 1);
if (ret < 0) {
devpriv->ai_cmd_running = 0;
goto ai_cmd_exit;
}
s->async->inttrig = NULL;
} else {
s->async->inttrig = usbdux_ai_inttrig;
}
ai_cmd_exit:
mutex_unlock(&devpriv->mut);
return ret;
}
static int usbdux_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int ret = -EBUSY;
int i;
mutex_lock(&devpriv->mut);
if (devpriv->ai_cmd_running)
goto ai_read_exit;
devpriv->dux_commands[1] = create_adc_command(chan, range);
ret = send_dux_commands(dev, USBDUX_CMD_SINGLE_AI);
if (ret < 0)
goto ai_read_exit;
for (i = 0; i < insn->n; i++) {
ret = receive_dux_commands(dev, USBDUX_CMD_SINGLE_AI);
if (ret < 0)
goto ai_read_exit;
val = le16_to_cpu(devpriv->insn_buf[1]);
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
data[i] = val;
}
ai_read_exit:
mutex_unlock(&devpriv->mut);
return ret ? ret : insn->n;
}
static int usbdux_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
int ret;
mutex_lock(&devpriv->mut);
ret = comedi_readback_insn_read(dev, s, insn, data);
mutex_unlock(&devpriv->mut);
return ret;
}
static int usbdux_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
__le16 *p = (__le16 *)&devpriv->dux_commands[2];
int ret = -EBUSY;
int i;
mutex_lock(&devpriv->mut);
if (devpriv->ao_cmd_running)
goto ao_write_exit;
devpriv->dux_commands[1] = 1;
devpriv->dux_commands[4] = chan << 6;
for (i = 0; i < insn->n; i++) {
val = data[i];
*p = cpu_to_le16(val);
ret = send_dux_commands(dev, USBDUX_CMD_AO);
if (ret < 0)
goto ao_write_exit;
s->readback[chan] = val;
}
ao_write_exit:
mutex_unlock(&devpriv->mut);
return ret ? ret : insn->n;
}
static int usbdux_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct usbdux_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int ret;
if (trig_num != cmd->start_arg)
return -EINVAL;
mutex_lock(&devpriv->mut);
if (!devpriv->ao_cmd_running) {
devpriv->ao_cmd_running = 1;
ret = usbdux_submit_urbs(dev, devpriv->ao_urbs,
devpriv->n_ao_urbs, 0);
if (ret < 0) {
devpriv->ao_cmd_running = 0;
goto ao_trig_exit;
}
s->async->inttrig = NULL;
} else {
ret = -EBUSY;
}
ao_trig_exit:
mutex_unlock(&devpriv->mut);
return ret;
}
static int usbdux_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
unsigned int flags;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
if (0) {
flags = TRIG_FOLLOW;
} else {
flags = TRIG_TIMER;
}
err |= comedi_check_trigger_src(&cmd->scan_begin_src, flags);
if (0) {
flags = TRIG_TIMER;
} else {
flags = TRIG_NOW;
}
err |= comedi_check_trigger_src(&cmd->convert_src, flags);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
1000000);
}
if (cmd->convert_src == TRIG_TIMER)
err |= comedi_check_trigger_arg_min(&cmd->convert_arg, 125000);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static int usbdux_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct usbdux_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int ret = -EBUSY;
mutex_lock(&devpriv->mut);
if (devpriv->ao_cmd_running)
goto ao_cmd_exit;
if (0) {
devpriv->ao_timer = cmd->convert_arg / 125000;
} else {
devpriv->ao_timer = cmd->scan_begin_arg / 1000000;
if (devpriv->ao_timer < 1) {
ret = -EINVAL;
goto ao_cmd_exit;
}
}
devpriv->ao_counter = devpriv->ao_timer;
if (cmd->start_src == TRIG_NOW) {
devpriv->ao_cmd_running = 1;
ret = usbdux_submit_urbs(dev, devpriv->ao_urbs,
devpriv->n_ao_urbs, 0);
if (ret < 0) {
devpriv->ao_cmd_running = 0;
goto ao_cmd_exit;
}
s->async->inttrig = NULL;
} else {
s->async->inttrig = usbdux_ao_inttrig;
}
ao_cmd_exit:
mutex_unlock(&devpriv->mut);
return ret;
}
static int usbdux_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
return insn->n;
}
static int usbdux_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
int ret;
mutex_lock(&devpriv->mut);
comedi_dio_update_state(s, data);
devpriv->dux_commands[1] = s->io_bits;
devpriv->dux_commands[2] = s->state;
ret = send_dux_commands(dev, USBDUX_CMD_DIO_BITS);
if (ret < 0)
goto dio_exit;
ret = receive_dux_commands(dev, USBDUX_CMD_DIO_BITS);
if (ret < 0)
goto dio_exit;
data[1] = le16_to_cpu(devpriv->insn_buf[1]);
dio_exit:
mutex_unlock(&devpriv->mut);
return ret ? ret : insn->n;
}
static int usbdux_counter_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int ret = 0;
int i;
mutex_lock(&devpriv->mut);
for (i = 0; i < insn->n; i++) {
ret = send_dux_commands(dev, USBDUX_CMD_TIMER_RD);
if (ret < 0)
goto counter_read_exit;
ret = receive_dux_commands(dev, USBDUX_CMD_TIMER_RD);
if (ret < 0)
goto counter_read_exit;
data[i] = le16_to_cpu(devpriv->insn_buf[chan + 1]);
}
counter_read_exit:
mutex_unlock(&devpriv->mut);
return ret ? ret : insn->n;
}
static int usbdux_counter_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
__le16 *p = (__le16 *)&devpriv->dux_commands[2];
int ret = 0;
int i;
mutex_lock(&devpriv->mut);
devpriv->dux_commands[1] = chan;
for (i = 0; i < insn->n; i++) {
*p = cpu_to_le16(data[i]);
ret = send_dux_commands(dev, USBDUX_CMD_TIMER_WR);
if (ret < 0)
break;
}
mutex_unlock(&devpriv->mut);
return ret ? ret : insn->n;
}
static int usbdux_counter_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
return 2;
}
static void usbduxsub_unlink_pwm_urbs(struct comedi_device *dev)
{
struct usbdux_private *devpriv = dev->private;
usb_kill_urb(devpriv->pwm_urb);
}
static void usbdux_pwm_stop(struct comedi_device *dev, int do_unlink)
{
struct usbdux_private *devpriv = dev->private;
if (do_unlink)
usbduxsub_unlink_pwm_urbs(dev);
devpriv->pwm_cmd_running = 0;
}
static int usbdux_pwm_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbdux_private *devpriv = dev->private;
int ret;
mutex_lock(&devpriv->mut);
usbdux_pwm_stop(dev, devpriv->pwm_cmd_running);
ret = send_dux_commands(dev, USBDUX_CMD_PWM_OFF);
mutex_unlock(&devpriv->mut);
return ret;
}
static void usbduxsub_pwm_irq(struct urb *urb)
{
struct comedi_device *dev = urb->context;
struct usbdux_private *devpriv = dev->private;
int ret;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
if (devpriv->pwm_cmd_running)
usbdux_pwm_stop(dev, 0);
return;
default:
if (devpriv->pwm_cmd_running) {
dev_err(dev->class_dev,
"Non-zero urb status received in pwm intr context: %d\n",
urb->status);
usbdux_pwm_stop(dev, 0);
}
return;
}
if (!devpriv->pwm_cmd_running)
return;
urb->transfer_buffer_length = devpriv->pwm_buf_sz;
urb->dev = comedi_to_usb_dev(dev);
urb->status = 0;
if (devpriv->pwm_cmd_running) {
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret < 0) {
dev_err(dev->class_dev,
"pwm urb resubm failed in int-cont. ret=%d",
ret);
if (ret == -EL2NSYNC)
dev_err(dev->class_dev,
"buggy USB host controller or bug in IRQ handling!\n");
usbdux_pwm_stop(dev, 0);
}
}
}
static int usbduxsub_submit_pwm_urbs(struct comedi_device *dev)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbdux_private *devpriv = dev->private;
struct urb *urb = devpriv->pwm_urb;
usb_fill_bulk_urb(urb, usb, usb_sndbulkpipe(usb, 4),
urb->transfer_buffer,
devpriv->pwm_buf_sz,
usbduxsub_pwm_irq,
dev);
return usb_submit_urb(urb, GFP_ATOMIC);
}
static int usbdux_pwm_period(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int period)
{
struct usbdux_private *devpriv = dev->private;
int fx2delay = 255;
if (period < MIN_PWM_PERIOD)
return -EAGAIN;
fx2delay = (period / (6 * 512 * 1000 / 33)) - 6;
if (fx2delay > 255)
return -EAGAIN;
devpriv->pwm_delay = fx2delay;
devpriv->pwm_period = period;
return 0;
}
static int usbdux_pwm_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbdux_private *devpriv = dev->private;
int ret = 0;
mutex_lock(&devpriv->mut);
if (devpriv->pwm_cmd_running)
goto pwm_start_exit;
devpriv->dux_commands[1] = devpriv->pwm_delay;
ret = send_dux_commands(dev, USBDUX_CMD_PWM_ON);
if (ret < 0)
goto pwm_start_exit;
memset(devpriv->pwm_urb->transfer_buffer, 0, devpriv->pwm_buf_sz);
devpriv->pwm_cmd_running = 1;
ret = usbduxsub_submit_pwm_urbs(dev);
if (ret < 0)
devpriv->pwm_cmd_running = 0;
pwm_start_exit:
mutex_unlock(&devpriv->mut);
return ret;
}
static void usbdux_pwm_pattern(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chan,
unsigned int value,
unsigned int sign)
{
struct usbdux_private *devpriv = dev->private;
char pwm_mask = (1 << chan);
char sgn_mask = (16 << chan);
char *buf = (char *)(devpriv->pwm_urb->transfer_buffer);
int szbuf = devpriv->pwm_buf_sz;
int i;
for (i = 0; i < szbuf; i++) {
char c = *buf;
c &= ~pwm_mask;
if (i < value)
c |= pwm_mask;
if (!sign)
c &= ~sgn_mask;
else
c |= sgn_mask;
*buf++ = c;
}
}
static int usbdux_pwm_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n != 1)
return -EINVAL;
usbdux_pwm_pattern(dev, s, chan, data[0], 0);
return insn->n;
}
static int usbdux_pwm_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct usbdux_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_ARM:
if (data[1] != 0)
return -EINVAL;
return usbdux_pwm_start(dev, s);
case INSN_CONFIG_DISARM:
return usbdux_pwm_cancel(dev, s);
case INSN_CONFIG_GET_PWM_STATUS:
data[1] = devpriv->pwm_cmd_running;
return 0;
case INSN_CONFIG_PWM_SET_PERIOD:
return usbdux_pwm_period(dev, s, data[1]);
case INSN_CONFIG_PWM_GET_PERIOD:
data[1] = devpriv->pwm_period;
return 0;
case INSN_CONFIG_PWM_SET_H_BRIDGE:
usbdux_pwm_pattern(dev, s, chan, data[1], (data[2] != 0));
return 0;
case INSN_CONFIG_PWM_GET_H_BRIDGE:
return -EINVAL;
}
return -EINVAL;
}
static int usbdux_firmware_upload(struct comedi_device *dev,
const u8 *data, size_t size,
unsigned long context)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
u8 *buf;
u8 *tmp;
int ret;
if (!data)
return 0;
if (size > USBDUX_FIRMWARE_MAX_LEN) {
dev_err(dev->class_dev,
"usbdux firmware binary it too large for FX2.\n");
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
USBDUX_FIRMWARE_CMD,
VENDOR_DIR_OUT,
USBDUX_CPU_CS, 0x0000,
tmp, 1,
BULK_TIMEOUT);
if (ret < 0) {
dev_err(dev->class_dev, "can not stop firmware\n");
goto done;
}
ret = usb_control_msg(usb, usb_sndctrlpipe(usb, 0),
USBDUX_FIRMWARE_CMD,
VENDOR_DIR_OUT,
0, 0x0000,
buf, size,
BULK_TIMEOUT);
if (ret < 0) {
dev_err(dev->class_dev, "firmware upload failed\n");
goto done;
}
*tmp = 0;
ret = usb_control_msg(usb, usb_sndctrlpipe(usb, 0),
USBDUX_FIRMWARE_CMD,
VENDOR_DIR_OUT,
USBDUX_CPU_CS, 0x0000,
tmp, 1,
BULK_TIMEOUT);
if (ret < 0)
dev_err(dev->class_dev, "can not start firmware\n");
done:
kfree(tmp);
kfree(buf);
return ret;
}
static int usbdux_alloc_usb_buffers(struct comedi_device *dev)
{
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbdux_private *devpriv = dev->private;
struct urb *urb;
int i;
devpriv->dux_commands = kzalloc(SIZEOFDUXBUFFER, GFP_KERNEL);
devpriv->in_buf = kzalloc(SIZEINBUF, GFP_KERNEL);
devpriv->insn_buf = kzalloc(SIZEINSNBUF, GFP_KERNEL);
devpriv->ai_urbs = kcalloc(devpriv->n_ai_urbs, sizeof(void *),
GFP_KERNEL);
devpriv->ao_urbs = kcalloc(devpriv->n_ao_urbs, sizeof(void *),
GFP_KERNEL);
if (!devpriv->dux_commands || !devpriv->in_buf || !devpriv->insn_buf ||
!devpriv->ai_urbs || !devpriv->ao_urbs)
return -ENOMEM;
for (i = 0; i < devpriv->n_ai_urbs; i++) {
urb = usb_alloc_urb(1, GFP_KERNEL);
if (!urb)
return -ENOMEM;
devpriv->ai_urbs[i] = urb;
urb->dev = usb;
urb->context = dev;
urb->pipe = usb_rcvisocpipe(usb, 6);
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = kzalloc(SIZEINBUF, GFP_KERNEL);
if (!urb->transfer_buffer)
return -ENOMEM;
urb->complete = usbduxsub_ai_isoc_irq;
urb->number_of_packets = 1;
urb->transfer_buffer_length = SIZEINBUF;
urb->iso_frame_desc[0].offset = 0;
urb->iso_frame_desc[0].length = SIZEINBUF;
}
for (i = 0; i < devpriv->n_ao_urbs; i++) {
urb = usb_alloc_urb(1, GFP_KERNEL);
if (!urb)
return -ENOMEM;
devpriv->ao_urbs[i] = urb;
urb->dev = usb;
urb->context = dev;
urb->pipe = usb_sndisocpipe(usb, 2);
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = kzalloc(SIZEOUTBUF, GFP_KERNEL);
if (!urb->transfer_buffer)
return -ENOMEM;
urb->complete = usbduxsub_ao_isoc_irq;
urb->number_of_packets = 1;
urb->transfer_buffer_length = SIZEOUTBUF;
urb->iso_frame_desc[0].offset = 0;
urb->iso_frame_desc[0].length = SIZEOUTBUF;
if (devpriv->high_speed)
urb->interval = 8;
else
urb->interval = 1;
}
if (devpriv->pwm_buf_sz) {
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return -ENOMEM;
devpriv->pwm_urb = urb;
urb->transfer_buffer = kzalloc(devpriv->pwm_buf_sz,
GFP_KERNEL);
if (!urb->transfer_buffer)
return -ENOMEM;
}
return 0;
}
static void usbdux_free_usb_buffers(struct comedi_device *dev)
{
struct usbdux_private *devpriv = dev->private;
struct urb *urb;
int i;
urb = devpriv->pwm_urb;
if (urb) {
kfree(urb->transfer_buffer);
usb_free_urb(urb);
}
if (devpriv->ao_urbs) {
for (i = 0; i < devpriv->n_ao_urbs; i++) {
urb = devpriv->ao_urbs[i];
if (urb) {
kfree(urb->transfer_buffer);
usb_free_urb(urb);
}
}
kfree(devpriv->ao_urbs);
}
if (devpriv->ai_urbs) {
for (i = 0; i < devpriv->n_ai_urbs; i++) {
urb = devpriv->ai_urbs[i];
if (urb) {
kfree(urb->transfer_buffer);
usb_free_urb(urb);
}
}
kfree(devpriv->ai_urbs);
}
kfree(devpriv->insn_buf);
kfree(devpriv->in_buf);
kfree(devpriv->dux_commands);
}
static int usbdux_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct usb_device *usb = comedi_to_usb_dev(dev);
struct usbdux_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
mutex_init(&devpriv->mut);
usb_set_intfdata(intf, devpriv);
devpriv->high_speed = (usb->speed == USB_SPEED_HIGH);
if (devpriv->high_speed) {
devpriv->n_ai_urbs = NUMOFINBUFFERSHIGH;
devpriv->n_ao_urbs = NUMOFOUTBUFFERSHIGH;
devpriv->pwm_buf_sz = 512;
} else {
devpriv->n_ai_urbs = NUMOFINBUFFERSFULL;
devpriv->n_ao_urbs = NUMOFOUTBUFFERSFULL;
}
ret = usbdux_alloc_usb_buffers(dev);
if (ret)
return ret;
ret = usb_set_interface(usb, intf->altsetting->desc.bInterfaceNumber,
3);
if (ret < 0) {
dev_err(dev->class_dev,
"could not set alternate setting 3 in high speed\n");
return ret;
}
ret = comedi_load_firmware(dev, &usb->dev, USBDUX_FIRMWARE,
usbdux_firmware_upload, 0);
if (ret < 0)
return ret;
ret = comedi_alloc_subdevices(dev, (devpriv->high_speed) ? 5 : 4);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_CMD_READ;
s->n_chan = 8;
s->maxdata = 0x0fff;
s->len_chanlist = 8;
s->range_table = &range_usbdux_ai_range;
s->insn_read = usbdux_ai_insn_read;
s->do_cmdtest = usbdux_ai_cmdtest;
s->do_cmd = usbdux_ai_cmd;
s->cancel = usbdux_ai_cancel;
s = &dev->subdevices[1];
dev->write_subdev = s;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_CMD_WRITE;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->len_chanlist = s->n_chan;
s->range_table = &range_usbdux_ao_range;
s->do_cmdtest = usbdux_ao_cmdtest;
s->do_cmd = usbdux_ao_cmd;
s->cancel = usbdux_ao_cancel;
s->insn_read = usbdux_ao_insn_read;
s->insn_write = usbdux_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = usbdux_dio_insn_bits;
s->insn_config = usbdux_dio_insn_config;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->insn_read = usbdux_counter_read;
s->insn_write = usbdux_counter_write;
s->insn_config = usbdux_counter_config;
if (devpriv->high_speed) {
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_PWM;
s->subdev_flags = SDF_WRITABLE | SDF_PWM_HBRIDGE;
s->n_chan = 8;
s->maxdata = devpriv->pwm_buf_sz;
s->insn_write = usbdux_pwm_write;
s->insn_config = usbdux_pwm_config;
usbdux_pwm_period(dev, s, PWM_DEFAULT_PERIOD);
}
return 0;
}
static void usbdux_detach(struct comedi_device *dev)
{
struct usb_interface *intf = comedi_to_usb_interface(dev);
struct usbdux_private *devpriv = dev->private;
usb_set_intfdata(intf, NULL);
if (!devpriv)
return;
mutex_lock(&devpriv->mut);
usbdux_pwm_stop(dev, 1);
usbdux_ao_stop(dev, 1);
usbdux_ai_stop(dev, 1);
usbdux_free_usb_buffers(dev);
mutex_unlock(&devpriv->mut);
}
static int usbdux_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return comedi_usb_auto_config(intf, &usbdux_driver, 0);
}
