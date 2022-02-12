static int usbduxsub_unlink_inurbs(struct usbduxsub *usbduxsub_tmp)
{
int i = 0;
int err = 0;
if (usbduxsub_tmp && usbduxsub_tmp->urb_in) {
for (i = 0; i < usbduxsub_tmp->num_in_buffers; i++) {
if (usbduxsub_tmp->urb_in[i]) {
usb_kill_urb(usbduxsub_tmp->urb_in[i]);
}
dev_dbg(&usbduxsub_tmp->interface->dev,
"comedi: usbdux: unlinked InURB %d, err=%d\n",
i, err);
}
}
return err;
}
static int usbdux_ai_stop(struct usbduxsub *this_usbduxsub, int do_unlink)
{
int ret = 0;
if (!this_usbduxsub) {
pr_err("comedi?: usbdux_ai_stop: this_usbduxsub=NULL!\n");
return -EFAULT;
}
dev_dbg(&this_usbduxsub->interface->dev, "comedi: usbdux_ai_stop\n");
if (do_unlink) {
ret = usbduxsub_unlink_inurbs(this_usbduxsub);
}
this_usbduxsub->ai_cmd_running = 0;
return ret;
}
static int usbdux_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbduxsub *this_usbduxsub;
int res = 0;
this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
dev_dbg(&this_usbduxsub->interface->dev, "comedi: usbdux_ai_cancel\n");
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
res = usbdux_ai_stop(this_usbduxsub, this_usbduxsub->ai_cmd_running);
up(&this_usbduxsub->sem);
return res;
}
static void usbduxsub_ai_isoc_irq(struct urb *urb)
{
int i, err, n;
struct usbduxsub *this_usbduxsub;
struct comedi_device *this_comedidev;
struct comedi_subdevice *s;
this_comedidev = urb->context;
this_usbduxsub = this_comedidev->private;
s = &this_comedidev->subdevices[SUBDEV_AD];
switch (urb->status) {
case 0:
memcpy(this_usbduxsub->in_buffer,
urb->transfer_buffer, SIZEINBUF);
break;
case -EILSEQ:
dev_dbg(&urb->dev->dev,
"comedi%d: usbdux: CRC error in ISO IN stream.\n",
this_usbduxsub->comedidev->minor);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
if (this_usbduxsub->ai_cmd_running) {
s->async->events |= COMEDI_CB_EOA;
s->async->events |= COMEDI_CB_ERROR;
comedi_event(this_usbduxsub->comedidev, s);
usbdux_ai_stop(this_usbduxsub, 0);
}
return;
default:
if (this_usbduxsub->ai_cmd_running) {
dev_err(&urb->dev->dev,
"Non-zero urb status received in ai intr "
"context: %d\n", urb->status);
s->async->events |= COMEDI_CB_EOA;
s->async->events |= COMEDI_CB_ERROR;
comedi_event(this_usbduxsub->comedidev, s);
usbdux_ai_stop(this_usbduxsub, 0);
}
return;
}
if (unlikely((!(this_usbduxsub->ai_cmd_running)))) {
return;
}
urb->dev = this_usbduxsub->usbdev;
err = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(err < 0)) {
dev_err(&urb->dev->dev,
"comedi_: urb resubmit failed in int-context! err=%d\n",
err);
if (err == -EL2NSYNC)
dev_err(&urb->dev->dev,
"buggy USB host controller or bug in IRQ "
"handler!\n");
s->async->events |= COMEDI_CB_EOA;
s->async->events |= COMEDI_CB_ERROR;
comedi_event(this_usbduxsub->comedidev, s);
usbdux_ai_stop(this_usbduxsub, 0);
return;
}
this_usbduxsub->ai_counter--;
if (likely(this_usbduxsub->ai_counter > 0))
return;
this_usbduxsub->ai_counter = this_usbduxsub->ai_timer;
if (!(this_usbduxsub->ai_continous)) {
this_usbduxsub->ai_sample_count--;
if (this_usbduxsub->ai_sample_count < 0) {
usbdux_ai_stop(this_usbduxsub, 0);
s->async->events |= COMEDI_CB_EOA;
comedi_event(this_usbduxsub->comedidev, s);
return;
}
}
n = s->async->cmd.chanlist_len;
for (i = 0; i < n; i++) {
if (CR_RANGE(s->async->cmd.chanlist[i]) <= 1) {
err = comedi_buf_put
(s->async,
le16_to_cpu(this_usbduxsub->in_buffer[i]) ^ 0x800);
} else {
err = comedi_buf_put
(s->async,
le16_to_cpu(this_usbduxsub->in_buffer[i]));
}
if (unlikely(err == 0)) {
usbdux_ai_stop(this_usbduxsub, 0);
return;
}
}
s->async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
comedi_event(this_usbduxsub->comedidev, s);
}
static int usbduxsub_unlink_outurbs(struct usbduxsub *usbduxsub_tmp)
{
int i = 0;
int err = 0;
if (usbduxsub_tmp && usbduxsub_tmp->urb_out) {
for (i = 0; i < usbduxsub_tmp->num_out_buffers; i++) {
if (usbduxsub_tmp->urb_out[i])
usb_kill_urb(usbduxsub_tmp->urb_out[i]);
dev_dbg(&usbduxsub_tmp->interface->dev,
"comedi: usbdux: unlinked OutURB %d: res=%d\n",
i, err);
}
}
return err;
}
static int usbdux_ao_stop(struct usbduxsub *this_usbduxsub, int do_unlink)
{
int ret = 0;
if (!this_usbduxsub)
return -EFAULT;
dev_dbg(&this_usbduxsub->interface->dev, "comedi: usbdux_ao_cancel\n");
if (do_unlink)
ret = usbduxsub_unlink_outurbs(this_usbduxsub);
this_usbduxsub->ao_cmd_running = 0;
return ret;
}
static int usbdux_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbduxsub *this_usbduxsub = dev->private;
int res = 0;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
res = usbdux_ao_stop(this_usbduxsub, this_usbduxsub->ao_cmd_running);
up(&this_usbduxsub->sem);
return res;
}
static void usbduxsub_ao_isoc_irq(struct urb *urb)
{
int i, ret;
int8_t *datap;
struct usbduxsub *this_usbduxsub;
struct comedi_device *this_comedidev;
struct comedi_subdevice *s;
this_comedidev = urb->context;
this_usbduxsub = this_comedidev->private;
s = &this_comedidev->subdevices[SUBDEV_DA];
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
if (this_usbduxsub->ao_cmd_running) {
s->async->events |= COMEDI_CB_EOA;
comedi_event(this_usbduxsub->comedidev, s);
usbdux_ao_stop(this_usbduxsub, 0);
}
return;
default:
if (this_usbduxsub->ao_cmd_running) {
dev_err(&urb->dev->dev,
"comedi_: Non-zero urb status received in ao "
"intr context: %d\n", urb->status);
s->async->events |= COMEDI_CB_ERROR;
s->async->events |= COMEDI_CB_EOA;
comedi_event(this_usbduxsub->comedidev, s);
usbdux_ao_stop(this_usbduxsub, 0);
}
return;
}
if (!(this_usbduxsub->ao_cmd_running))
return;
this_usbduxsub->ao_counter--;
if ((int)this_usbduxsub->ao_counter <= 0) {
this_usbduxsub->ao_counter = this_usbduxsub->ao_timer;
if (!(this_usbduxsub->ao_continous)) {
this_usbduxsub->ao_sample_count--;
if (this_usbduxsub->ao_sample_count < 0) {
usbdux_ao_stop(this_usbduxsub, 0);
s->async->events |= COMEDI_CB_EOA;
comedi_event(this_usbduxsub->comedidev, s);
return;
}
}
((uint8_t *) (urb->transfer_buffer))[0] =
s->async->cmd.chanlist_len;
for (i = 0; i < s->async->cmd.chanlist_len; i++) {
short temp;
if (i >= NUMOUTCHANNELS)
break;
datap =
(&(((int8_t *) urb->transfer_buffer)[i * 3 + 1]));
ret = comedi_buf_get(s->async, &temp);
datap[0] = temp;
datap[1] = temp >> 8;
datap[2] = this_usbduxsub->dac_commands[i];
if (ret < 0) {
dev_err(&urb->dev->dev,
"comedi: buffer underflow\n");
s->async->events |= COMEDI_CB_EOA;
s->async->events |= COMEDI_CB_OVERFLOW;
}
s->async->events |= COMEDI_CB_BLOCK;
comedi_event(this_usbduxsub->comedidev, s);
}
}
urb->transfer_buffer_length = SIZEOUTBUF;
urb->dev = this_usbduxsub->usbdev;
urb->status = 0;
if (this_usbduxsub->ao_cmd_running) {
if (this_usbduxsub->high_speed) {
urb->interval = 8;
} else {
urb->interval = 1;
}
urb->number_of_packets = 1;
urb->iso_frame_desc[0].offset = 0;
urb->iso_frame_desc[0].length = SIZEOUTBUF;
urb->iso_frame_desc[0].status = 0;
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret < 0) {
dev_err(&urb->dev->dev,
"comedi_: ao urb resubm failed in int-cont. "
"ret=%d", ret);
if (ret == EL2NSYNC)
dev_err(&urb->dev->dev,
"buggy USB host controller or bug in "
"IRQ handling!\n");
s->async->events |= COMEDI_CB_EOA;
s->async->events |= COMEDI_CB_ERROR;
comedi_event(this_usbduxsub->comedidev, s);
usbdux_ao_stop(this_usbduxsub, 0);
}
}
}
static int usbduxsub_start(struct usbduxsub *usbduxsub)
{
int errcode = 0;
uint8_t *local_transfer_buffer;
local_transfer_buffer = kmalloc(1, GFP_KERNEL);
if (!local_transfer_buffer)
return -ENOMEM;
*local_transfer_buffer = 0;
errcode = usb_control_msg(usbduxsub->usbdev,
usb_sndctrlpipe(usbduxsub->usbdev, 0),
USBDUXSUB_FIRMWARE,
VENDOR_DIR_OUT,
USBDUXSUB_CPUCS,
0x0000,
local_transfer_buffer,
1,
BULK_TIMEOUT);
if (errcode < 0)
dev_err(&usbduxsub->interface->dev,
"comedi_: control msg failed (start)\n");
kfree(local_transfer_buffer);
return errcode;
}
static int usbduxsub_stop(struct usbduxsub *usbduxsub)
{
int errcode = 0;
uint8_t *local_transfer_buffer;
local_transfer_buffer = kmalloc(1, GFP_KERNEL);
if (!local_transfer_buffer)
return -ENOMEM;
*local_transfer_buffer = 1;
errcode = usb_control_msg(usbduxsub->usbdev,
usb_sndctrlpipe(usbduxsub->usbdev, 0),
USBDUXSUB_FIRMWARE,
VENDOR_DIR_OUT,
USBDUXSUB_CPUCS,
0x0000, local_transfer_buffer,
1,
BULK_TIMEOUT);
if (errcode < 0)
dev_err(&usbduxsub->interface->dev,
"comedi_: control msg failed (stop)\n");
kfree(local_transfer_buffer);
return errcode;
}
static int usbduxsub_upload(struct usbduxsub *usbduxsub,
uint8_t *local_transfer_buffer,
unsigned int start_addr, unsigned int len)
{
int errcode;
errcode = usb_control_msg(usbduxsub->usbdev,
usb_sndctrlpipe(usbduxsub->usbdev, 0),
USBDUXSUB_FIRMWARE,
VENDOR_DIR_OUT,
start_addr,
0x0000,
local_transfer_buffer,
len,
BULK_TIMEOUT);
dev_dbg(&usbduxsub->interface->dev, "comedi_: result=%d\n", errcode);
if (errcode < 0) {
dev_err(&usbduxsub->interface->dev, "comedi_: upload failed\n");
return errcode;
}
return 0;
}
static int firmware_upload(struct usbduxsub *usbduxsub,
const u8 *firmware_binary, int size_firmware)
{
int ret;
uint8_t *fw_buf;
if (!firmware_binary)
return 0;
if (size_firmware > FIRMWARE_MAX_LEN) {
dev_err(&usbduxsub->interface->dev,
"usbdux firmware binary it too large for FX2.\n");
return -ENOMEM;
}
fw_buf = kmemdup(firmware_binary, size_firmware, GFP_KERNEL);
if (!fw_buf) {
dev_err(&usbduxsub->interface->dev,
"comedi_: mem alloc for firmware failed\n");
return -ENOMEM;
}
ret = usbduxsub_stop(usbduxsub);
if (ret < 0) {
dev_err(&usbduxsub->interface->dev,
"comedi_: can not stop firmware\n");
kfree(fw_buf);
return ret;
}
ret = usbduxsub_upload(usbduxsub, fw_buf, 0, size_firmware);
if (ret < 0) {
dev_err(&usbduxsub->interface->dev,
"comedi_: firmware upload failed\n");
kfree(fw_buf);
return ret;
}
ret = usbduxsub_start(usbduxsub);
if (ret < 0) {
dev_err(&usbduxsub->interface->dev,
"comedi_: can not start firmware\n");
kfree(fw_buf);
return ret;
}
kfree(fw_buf);
return 0;
}
static int usbduxsub_submit_inurbs(struct usbduxsub *usbduxsub)
{
int i, err_flag;
if (!usbduxsub)
return -EFAULT;
for (i = 0; i < usbduxsub->num_in_buffers; i++) {
usbduxsub->urb_in[i]->interval = usbduxsub->ai_interval;
usbduxsub->urb_in[i]->context = usbduxsub->comedidev;
usbduxsub->urb_in[i]->dev = usbduxsub->usbdev;
usbduxsub->urb_in[i]->status = 0;
usbduxsub->urb_in[i]->transfer_flags = URB_ISO_ASAP;
dev_dbg(&usbduxsub->interface->dev,
"comedi%d: submitting in-urb[%d]: %p,%p intv=%d\n",
usbduxsub->comedidev->minor, i,
(usbduxsub->urb_in[i]->context),
(usbduxsub->urb_in[i]->dev),
(usbduxsub->urb_in[i]->interval));
err_flag = usb_submit_urb(usbduxsub->urb_in[i], GFP_ATOMIC);
if (err_flag) {
dev_err(&usbduxsub->interface->dev,
"comedi_: ai: usb_submit_urb(%d) error %d\n",
i, err_flag);
return err_flag;
}
}
return 0;
}
static int usbduxsub_submit_outurbs(struct usbduxsub *usbduxsub)
{
int i, err_flag;
if (!usbduxsub)
return -EFAULT;
for (i = 0; i < usbduxsub->num_out_buffers; i++) {
dev_dbg(&usbduxsub->interface->dev,
"comedi_: submitting out-urb[%d]\n", i);
usbduxsub->urb_out[i]->context = usbduxsub->comedidev;
usbduxsub->urb_out[i]->dev = usbduxsub->usbdev;
usbduxsub->urb_out[i]->status = 0;
usbduxsub->urb_out[i]->transfer_flags = URB_ISO_ASAP;
err_flag = usb_submit_urb(usbduxsub->urb_out[i], GFP_ATOMIC);
if (err_flag) {
dev_err(&usbduxsub->interface->dev,
"comedi_: ao: usb_submit_urb(%d) error %d\n",
i, err_flag);
return err_flag;
}
}
return 0;
}
static int usbdux_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
struct usbduxsub *this_usbduxsub = dev->private;
int err = 0, i;
unsigned int tmp_timer;
if (!(this_usbduxsub->probed))
return -ENODEV;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
if (this_usbduxsub->high_speed) {
i = 1;
while (i < (cmd->chanlist_len))
i = i * 2;
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
1000000 / 8 * i);
tmp_timer =
((unsigned int)(cmd->scan_begin_arg / 125000)) *
125000;
} else {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
1000000);
tmp_timer = ((unsigned int)(cmd->scan_begin_arg /
1000000)) * 1000000;
}
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg,
tmp_timer);
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT) {
} else {
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
return 0;
}
static int8_t create_adc_command(unsigned int chan, int range)
{
int8_t p = (range <= 1);
int8_t r = ((range % 2) == 0);
return (chan << 4) | ((p == 1) << 2) | ((r == 1) << 3);
}
static int send_dux_commands(struct usbduxsub *this_usbduxsub, int cmd_type)
{
int result, nsent;
this_usbduxsub->dux_commands[0] = cmd_type;
#ifdef NOISY_DUX_DEBUGBUG
printk(KERN_DEBUG "comedi%d: usbdux: dux_commands: ",
this_usbduxsub->comedidev->minor);
for (result = 0; result < SIZEOFDUXBUFFER; result++)
printk(" %02x", this_usbduxsub->dux_commands[result]);
printk("\n");
#endif
result = usb_bulk_msg(this_usbduxsub->usbdev,
usb_sndbulkpipe(this_usbduxsub->usbdev,
COMMAND_OUT_EP),
this_usbduxsub->dux_commands, SIZEOFDUXBUFFER,
&nsent, BULK_TIMEOUT);
if (result < 0)
dev_err(&this_usbduxsub->interface->dev, "comedi%d: "
"could not transmit dux_command to the usb-device, "
"err=%d\n", this_usbduxsub->comedidev->minor, result);
return result;
}
static int receive_dux_commands(struct usbduxsub *this_usbduxsub, int command)
{
int result = (-EFAULT);
int nrec;
int i;
for (i = 0; i < RETRIES; i++) {
result = usb_bulk_msg(this_usbduxsub->usbdev,
usb_rcvbulkpipe(this_usbduxsub->usbdev,
COMMAND_IN_EP),
this_usbduxsub->insn_buffer, SIZEINSNBUF,
&nrec, BULK_TIMEOUT);
if (result < 0) {
dev_err(&this_usbduxsub->interface->dev, "comedi%d: "
"insn: USB error %d while receiving DUX command"
"\n", this_usbduxsub->comedidev->minor, result);
return result;
}
if (le16_to_cpu(this_usbduxsub->insn_buffer[0]) == command)
return result;
}
dev_err(&this_usbduxsub->interface->dev, "comedi%d: insn: "
"wrong data returned from firmware: want cmd %d, got cmd %d.\n",
this_usbduxsub->comedidev->minor, command,
le16_to_cpu(this_usbduxsub->insn_buffer[0]));
return -EFAULT;
}
static int usbdux_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int trignum)
{
int ret;
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: usbdux_ai_inttrig\n", dev->minor);
if (trignum != 0) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: usbdux_ai_inttrig: invalid trignum\n",
dev->minor);
up(&this_usbduxsub->sem);
return -EINVAL;
}
if (!(this_usbduxsub->ai_cmd_running)) {
this_usbduxsub->ai_cmd_running = 1;
ret = usbduxsub_submit_inurbs(this_usbduxsub);
if (ret < 0) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: usbdux_ai_inttrig: "
"urbSubmit: err=%d\n", dev->minor, ret);
this_usbduxsub->ai_cmd_running = 0;
up(&this_usbduxsub->sem);
return ret;
}
s->async->inttrig = NULL;
} else {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: ai_inttrig but acqu is already running\n",
dev->minor);
}
up(&this_usbduxsub->sem);
return 1;
}
static int usbdux_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int chan, range;
int i, ret;
struct usbduxsub *this_usbduxsub = dev->private;
int result;
if (!this_usbduxsub)
return -EFAULT;
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: usbdux_ai_cmd\n", dev->minor);
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
if (this_usbduxsub->ai_cmd_running) {
dev_err(&this_usbduxsub->interface->dev, "comedi%d: "
"ai_cmd not possible. Another ai_cmd is running.\n",
dev->minor);
up(&this_usbduxsub->sem);
return -EBUSY;
}
s->async->cur_chan = 0;
this_usbduxsub->dux_commands[1] = cmd->chanlist_len;
for (i = 0; i < cmd->chanlist_len; ++i) {
chan = CR_CHAN(cmd->chanlist[i]);
range = CR_RANGE(cmd->chanlist[i]);
if (i >= NUMCHANNELS) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: channel list too long\n",
dev->minor);
break;
}
this_usbduxsub->dux_commands[i + 2] =
create_adc_command(chan, range);
}
dev_dbg(&this_usbduxsub->interface->dev,
"comedi %d: sending commands to the usb device: size=%u\n",
dev->minor, NUMCHANNELS);
result = send_dux_commands(this_usbduxsub, SENDADCOMMANDS);
if (result < 0) {
up(&this_usbduxsub->sem);
return result;
}
if (this_usbduxsub->high_speed) {
this_usbduxsub->ai_interval = 1;
while ((this_usbduxsub->ai_interval) < (cmd->chanlist_len)) {
this_usbduxsub->ai_interval =
(this_usbduxsub->ai_interval) * 2;
}
this_usbduxsub->ai_timer = cmd->scan_begin_arg / (125000 *
(this_usbduxsub->
ai_interval));
} else {
this_usbduxsub->ai_interval = 1;
this_usbduxsub->ai_timer = cmd->scan_begin_arg / 1000000;
}
if (this_usbduxsub->ai_timer < 1) {
dev_err(&this_usbduxsub->interface->dev, "comedi%d: ai_cmd: "
"timer=%d, scan_begin_arg=%d. "
"Not properly tested by cmdtest?\n", dev->minor,
this_usbduxsub->ai_timer, cmd->scan_begin_arg);
up(&this_usbduxsub->sem);
return -EINVAL;
}
this_usbduxsub->ai_counter = this_usbduxsub->ai_timer;
if (cmd->stop_src == TRIG_COUNT) {
this_usbduxsub->ai_sample_count = cmd->stop_arg;
this_usbduxsub->ai_continous = 0;
} else {
this_usbduxsub->ai_continous = 1;
this_usbduxsub->ai_sample_count = 0;
}
if (cmd->start_src == TRIG_NOW) {
this_usbduxsub->ai_cmd_running = 1;
ret = usbduxsub_submit_inurbs(this_usbduxsub);
if (ret < 0) {
this_usbduxsub->ai_cmd_running = 0;
up(&this_usbduxsub->sem);
return ret;
}
s->async->inttrig = NULL;
} else {
s->async->inttrig = usbdux_ai_inttrig;
}
up(&this_usbduxsub->sem);
return 0;
}
static int usbdux_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
unsigned int one = 0;
int chan, range;
int err;
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return 0;
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: ai_insn_read, insn->n=%d, insn->subdev=%d\n",
dev->minor, insn->n, insn->subdev);
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
if (this_usbduxsub->ai_cmd_running) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: ai_insn_read not possible. "
"Async Command is running.\n", dev->minor);
up(&this_usbduxsub->sem);
return 0;
}
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
this_usbduxsub->dux_commands[1] = create_adc_command(chan, range);
err = send_dux_commands(this_usbduxsub, SENDSINGLEAD);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
for (i = 0; i < insn->n; i++) {
err = receive_dux_commands(this_usbduxsub, SENDSINGLEAD);
if (err < 0) {
up(&this_usbduxsub->sem);
return 0;
}
one = le16_to_cpu(this_usbduxsub->insn_buffer[1]);
if (CR_RANGE(insn->chanspec) <= 1)
one = one ^ 0x800;
data[i] = one;
}
up(&this_usbduxsub->sem);
return i;
}
static int usbdux_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
for (i = 0; i < insn->n; i++)
data[i] = this_usbduxsub->out_buffer[chan];
up(&this_usbduxsub->sem);
return i;
}
static int usbdux_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i, err;
int chan = CR_CHAN(insn->chanspec);
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: ao_insn_write\n", dev->minor);
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
if (this_usbduxsub->ao_cmd_running) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: ao_insn_write: "
"ERROR: asynchronous ao_cmd is running\n", dev->minor);
up(&this_usbduxsub->sem);
return 0;
}
for (i = 0; i < insn->n; i++) {
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: ao_insn_write: data[chan=%d,i=%d]=%d\n",
dev->minor, chan, i, data[i]);
this_usbduxsub->dux_commands[1] = 1;
*((int16_t *) (this_usbduxsub->dux_commands + 2)) =
cpu_to_le16(data[i]);
this_usbduxsub->out_buffer[chan] = data[i];
this_usbduxsub->dux_commands[4] = (chan << 6);
err = send_dux_commands(this_usbduxsub, SENDDACOMMANDS);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
}
up(&this_usbduxsub->sem);
return i;
}
static int usbdux_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int trignum)
{
int ret;
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
if (trignum != 0) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: usbdux_ao_inttrig: invalid trignum\n",
dev->minor);
up(&this_usbduxsub->sem);
return -EINVAL;
}
if (!(this_usbduxsub->ao_cmd_running)) {
this_usbduxsub->ao_cmd_running = 1;
ret = usbduxsub_submit_outurbs(this_usbduxsub);
if (ret < 0) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: usbdux_ao_inttrig: submitURB: "
"err=%d\n", dev->minor, ret);
this_usbduxsub->ao_cmd_running = 0;
up(&this_usbduxsub->sem);
return ret;
}
s->async->inttrig = NULL;
} else {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: ao_inttrig but acqu is already running.\n",
dev->minor);
}
up(&this_usbduxsub->sem);
return 1;
}
static int usbdux_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
struct usbduxsub *this_usbduxsub = dev->private;
int err = 0;
unsigned int flags;
if (!this_usbduxsub)
return -EFAULT;
if (!(this_usbduxsub->probed))
return -ENODEV;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
if (0) {
flags = TRIG_FOLLOW;
} else {
flags = TRIG_TIMER;
}
err |= cfc_check_trigger_src(&cmd->scan_begin_src, flags);
if (0) {
flags = TRIG_TIMER;
} else {
flags = TRIG_NOW;
}
err |= cfc_check_trigger_src(&cmd->convert_src, flags);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
1000000);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, 125000);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT) {
} else {
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
return 0;
}
static int usbdux_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int chan, gain;
int i, ret;
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: %s\n", dev->minor, __func__);
s->async->cur_chan = 0;
for (i = 0; i < cmd->chanlist_len; ++i) {
chan = CR_CHAN(cmd->chanlist[i]);
gain = CR_RANGE(cmd->chanlist[i]);
if (i >= NUMOUTCHANNELS) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: %s: channel list too long\n",
dev->minor, __func__);
break;
}
this_usbduxsub->dac_commands[i] = (chan << 6);
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: dac command for ch %d is %x\n",
dev->minor, i, this_usbduxsub->dac_commands[i]);
}
if (0) {
this_usbduxsub->ao_timer = cmd->convert_arg / 125000;
} else {
this_usbduxsub->ao_timer = cmd->scan_begin_arg / 1000000;
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: scan_begin_src=%d, scan_begin_arg=%d, "
"convert_src=%d, convert_arg=%d\n", dev->minor,
cmd->scan_begin_src, cmd->scan_begin_arg,
cmd->convert_src, cmd->convert_arg);
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: ao_timer=%d (ms)\n",
dev->minor, this_usbduxsub->ao_timer);
if (this_usbduxsub->ao_timer < 1) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: usbdux: ao_timer=%d, "
"scan_begin_arg=%d. "
"Not properly tested by cmdtest?\n",
dev->minor, this_usbduxsub->ao_timer,
cmd->scan_begin_arg);
up(&this_usbduxsub->sem);
return -EINVAL;
}
}
this_usbduxsub->ao_counter = this_usbduxsub->ao_timer;
if (cmd->stop_src == TRIG_COUNT) {
if (0) {
this_usbduxsub->ao_sample_count =
(cmd->stop_arg) * (cmd->scan_end_arg);
} else {
this_usbduxsub->ao_sample_count = cmd->stop_arg;
}
this_usbduxsub->ao_continous = 0;
} else {
this_usbduxsub->ao_continous = 1;
this_usbduxsub->ao_sample_count = 0;
}
if (cmd->start_src == TRIG_NOW) {
this_usbduxsub->ao_cmd_running = 1;
ret = usbduxsub_submit_outurbs(this_usbduxsub);
if (ret < 0) {
this_usbduxsub->ao_cmd_running = 0;
up(&this_usbduxsub->sem);
return ret;
}
s->async->inttrig = NULL;
} else {
s->async->inttrig = usbdux_ao_inttrig;
}
up(&this_usbduxsub->sem);
return 0;
}
static int usbdux_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= 1 << chan;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~(1 << chan);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
break;
default:
return -EINVAL;
break;
}
return insn->n;
}
static int usbdux_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct usbduxsub *this_usbduxsub = dev->private;
int err;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
s->state &= ~data[0];
s->state |= data[0] & data[1];
this_usbduxsub->dux_commands[1] = s->io_bits;
this_usbduxsub->dux_commands[2] = s->state;
err = send_dux_commands(this_usbduxsub, SENDDIOBITSCOMMAND);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
err = receive_dux_commands(this_usbduxsub, SENDDIOBITSCOMMAND);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
data[1] = le16_to_cpu(this_usbduxsub->insn_buffer[1]);
up(&this_usbduxsub->sem);
return insn->n;
}
static int usbdux_counter_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct usbduxsub *this_usbduxsub = dev->private;
int chan = insn->chanspec;
int err;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
err = send_dux_commands(this_usbduxsub, READCOUNTERCOMMAND);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
err = receive_dux_commands(this_usbduxsub, READCOUNTERCOMMAND);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
data[0] = le16_to_cpu(this_usbduxsub->insn_buffer[chan + 1]);
up(&this_usbduxsub->sem);
return 1;
}
static int usbdux_counter_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct usbduxsub *this_usbduxsub = dev->private;
int err;
if (!this_usbduxsub)
return -EFAULT;
down(&this_usbduxsub->sem);
if (!(this_usbduxsub->probed)) {
up(&this_usbduxsub->sem);
return -ENODEV;
}
this_usbduxsub->dux_commands[1] = insn->chanspec;
*((int16_t *) (this_usbduxsub->dux_commands + 2)) = cpu_to_le16(*data);
err = send_dux_commands(this_usbduxsub, WRITECOUNTERCOMMAND);
if (err < 0) {
up(&this_usbduxsub->sem);
return err;
}
up(&this_usbduxsub->sem);
return 1;
}
static int usbdux_counter_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
return 2;
}
static int usbduxsub_unlink_pwm_urbs(struct usbduxsub *usbduxsub_tmp)
{
int err = 0;
if (usbduxsub_tmp && usbduxsub_tmp->urb_pwm) {
if (usbduxsub_tmp->urb_pwm)
usb_kill_urb(usbduxsub_tmp->urb_pwm);
dev_dbg(&usbduxsub_tmp->interface->dev,
"comedi: unlinked PwmURB: res=%d\n", err);
}
return err;
}
static int usbdux_pwm_stop(struct usbduxsub *this_usbduxsub, int do_unlink)
{
int ret = 0;
if (!this_usbduxsub)
return -EFAULT;
dev_dbg(&this_usbduxsub->interface->dev, "comedi: %s\n", __func__);
if (do_unlink)
ret = usbduxsub_unlink_pwm_urbs(this_usbduxsub);
this_usbduxsub->pwm_cmd_running = 0;
return ret;
}
static int usbdux_pwm_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct usbduxsub *this_usbduxsub = dev->private;
int res = 0;
res = usbdux_pwm_stop(this_usbduxsub, this_usbduxsub->pwm_cmd_running);
dev_dbg(&this_usbduxsub->interface->dev,
"comedi %d: sending pwm off command to the usb device.\n",
dev->minor);
return send_dux_commands(this_usbduxsub, SENDPWMOFF);
}
static void usbduxsub_pwm_irq(struct urb *urb)
{
int ret;
struct usbduxsub *this_usbduxsub;
struct comedi_device *this_comedidev;
struct comedi_subdevice *s;
this_comedidev = urb->context;
this_usbduxsub = this_comedidev->private;
s = &this_comedidev->subdevices[SUBDEV_DA];
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNABORTED:
if (this_usbduxsub->pwm_cmd_running)
usbdux_pwm_stop(this_usbduxsub, 0);
return;
default:
if (this_usbduxsub->pwm_cmd_running) {
dev_err(&this_usbduxsub->interface->dev,
"comedi_: Non-zero urb status received in "
"pwm intr context: %d\n", urb->status);
usbdux_pwm_stop(this_usbduxsub, 0);
}
return;
}
if (!(this_usbduxsub->pwm_cmd_running))
return;
urb->transfer_buffer_length = this_usbduxsub->size_pwm_buf;
urb->dev = this_usbduxsub->usbdev;
urb->status = 0;
if (this_usbduxsub->pwm_cmd_running) {
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret < 0) {
dev_err(&this_usbduxsub->interface->dev,
"comedi_: pwm urb resubm failed in int-cont. "
"ret=%d", ret);
if (ret == EL2NSYNC)
dev_err(&this_usbduxsub->interface->dev,
"buggy USB host controller or bug in "
"IRQ handling!\n");
usbdux_pwm_stop(this_usbduxsub, 0);
}
}
}
static int usbduxsub_submit_pwm_urbs(struct usbduxsub *usbduxsub)
{
int err_flag;
if (!usbduxsub)
return -EFAULT;
dev_dbg(&usbduxsub->interface->dev, "comedi_: submitting pwm-urb\n");
usb_fill_bulk_urb(usbduxsub->urb_pwm,
usbduxsub->usbdev,
usb_sndbulkpipe(usbduxsub->usbdev, PWM_EP),
usbduxsub->urb_pwm->transfer_buffer,
usbduxsub->size_pwm_buf, usbduxsub_pwm_irq,
usbduxsub->comedidev);
err_flag = usb_submit_urb(usbduxsub->urb_pwm, GFP_ATOMIC);
if (err_flag) {
dev_err(&usbduxsub->interface->dev,
"comedi_: usbdux: pwm: usb_submit_urb error %d\n",
err_flag);
return err_flag;
}
return 0;
}
static int usbdux_pwm_period(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int period)
{
struct usbduxsub *this_usbduxsub = dev->private;
int fx2delay = 255;
if (period < MIN_PWM_PERIOD) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: illegal period setting for pwm.\n",
dev->minor);
return -EAGAIN;
} else {
fx2delay = period / ((int)(6 * 512 * (1.0 / 0.033))) - 6;
if (fx2delay > 255) {
dev_err(&this_usbduxsub->interface->dev,
"comedi%d: period %d for pwm is too low.\n",
dev->minor, period);
return -EAGAIN;
}
}
this_usbduxsub->pwn_delay = fx2delay;
this_usbduxsub->pwm_period = period;
dev_dbg(&this_usbduxsub->interface->dev, "%s: frequ=%d, period=%d\n",
__func__, period, fx2delay);
return 0;
}
static int usbdux_pwm_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
int ret, i;
struct usbduxsub *this_usbduxsub = dev->private;
dev_dbg(&this_usbduxsub->interface->dev, "comedi%d: %s\n",
dev->minor, __func__);
if (this_usbduxsub->pwm_cmd_running) {
return 0;
}
this_usbduxsub->dux_commands[1] = ((int8_t) this_usbduxsub->pwn_delay);
ret = send_dux_commands(this_usbduxsub, SENDPWMON);
if (ret < 0)
return ret;
for (i = 0; i < this_usbduxsub->size_pwm_buf; i++)
((char *)(this_usbduxsub->urb_pwm->transfer_buffer))[i] = 0;
this_usbduxsub->pwm_cmd_running = 1;
ret = usbduxsub_submit_pwm_urbs(this_usbduxsub);
if (ret < 0) {
this_usbduxsub->pwm_cmd_running = 0;
return ret;
}
return 0;
}
static int usbdux_pwm_pattern(struct comedi_device *dev,
struct comedi_subdevice *s, int channel,
unsigned int value, unsigned int sign)
{
struct usbduxsub *this_usbduxsub = dev->private;
int i, szbuf;
char *p_buf;
char pwm_mask;
char sgn_mask;
char c;
if (!this_usbduxsub)
return -EFAULT;
pwm_mask = (1 << channel);
sgn_mask = (16 << channel);
szbuf = this_usbduxsub->size_pwm_buf;
p_buf = (char *)(this_usbduxsub->urb_pwm->transfer_buffer);
for (i = 0; i < szbuf; i++) {
c = *p_buf;
c = c & (~pwm_mask);
if (i < value)
c = c | pwm_mask;
if (!sign) {
c = c & (~sgn_mask);
} else {
c = c | sgn_mask;
}
*(p_buf++) = c;
}
return 1;
}
static int usbdux_pwm_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct usbduxsub *this_usbduxsub = dev->private;
if (!this_usbduxsub)
return -EFAULT;
if ((insn->n) != 1) {
return -EINVAL;
}
return usbdux_pwm_pattern(dev, s, CR_CHAN(insn->chanspec), data[0], 0);
}
static int usbdux_pwm_read(struct comedi_device *x1,
struct comedi_subdevice *x2, struct comedi_insn *x3,
unsigned int *x4)
{
return -EINVAL;
}
static int usbdux_pwm_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct usbduxsub *this_usbduxsub = dev->private;
switch (data[0]) {
case INSN_CONFIG_ARM:
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: %s: pwm on\n", dev->minor, __func__);
if (data[1] != 0)
return -EINVAL;
return usbdux_pwm_start(dev, s);
case INSN_CONFIG_DISARM:
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: %s: pwm off\n", dev->minor, __func__);
return usbdux_pwm_cancel(dev, s);
case INSN_CONFIG_GET_PWM_STATUS:
data[1] = this_usbduxsub->pwm_cmd_running;
return 0;
case INSN_CONFIG_PWM_SET_PERIOD:
dev_dbg(&this_usbduxsub->interface->dev,
"comedi%d: %s: setting period\n", dev->minor, __func__);
return usbdux_pwm_period(dev, s, data[1]);
case INSN_CONFIG_PWM_GET_PERIOD:
data[1] = this_usbduxsub->pwm_period;
return 0;
case INSN_CONFIG_PWM_SET_H_BRIDGE:
return usbdux_pwm_pattern(dev, s,
CR_CHAN(insn->chanspec),
data[1],
(data[2] != 0));
case INSN_CONFIG_PWM_GET_H_BRIDGE:
return -EINVAL;
}
return -EINVAL;
}
static void tidy_up(struct usbduxsub *usbduxsub_tmp)
{
int i;
if (!usbduxsub_tmp)
return;
dev_dbg(&usbduxsub_tmp->interface->dev, "comedi_: tiding up\n");
if (usbduxsub_tmp->interface)
usb_set_intfdata(usbduxsub_tmp->interface, NULL);
usbduxsub_tmp->probed = 0;
if (usbduxsub_tmp->urb_in) {
if (usbduxsub_tmp->ai_cmd_running) {
usbduxsub_tmp->ai_cmd_running = 0;
usbduxsub_unlink_inurbs(usbduxsub_tmp);
}
for (i = 0; i < usbduxsub_tmp->num_in_buffers; i++) {
kfree(usbduxsub_tmp->urb_in[i]->transfer_buffer);
usbduxsub_tmp->urb_in[i]->transfer_buffer = NULL;
usb_kill_urb(usbduxsub_tmp->urb_in[i]);
usb_free_urb(usbduxsub_tmp->urb_in[i]);
usbduxsub_tmp->urb_in[i] = NULL;
}
kfree(usbduxsub_tmp->urb_in);
usbduxsub_tmp->urb_in = NULL;
}
if (usbduxsub_tmp->urb_out) {
if (usbduxsub_tmp->ao_cmd_running) {
usbduxsub_tmp->ao_cmd_running = 0;
usbduxsub_unlink_outurbs(usbduxsub_tmp);
}
for (i = 0; i < usbduxsub_tmp->num_out_buffers; i++) {
kfree(usbduxsub_tmp->urb_out[i]->transfer_buffer);
usbduxsub_tmp->urb_out[i]->transfer_buffer = NULL;
if (usbduxsub_tmp->urb_out[i]) {
usb_kill_urb(usbduxsub_tmp->urb_out[i]);
usb_free_urb(usbduxsub_tmp->urb_out[i]);
usbduxsub_tmp->urb_out[i] = NULL;
}
}
kfree(usbduxsub_tmp->urb_out);
usbduxsub_tmp->urb_out = NULL;
}
if (usbduxsub_tmp->urb_pwm) {
if (usbduxsub_tmp->pwm_cmd_running) {
usbduxsub_tmp->pwm_cmd_running = 0;
usbduxsub_unlink_pwm_urbs(usbduxsub_tmp);
}
kfree(usbduxsub_tmp->urb_pwm->transfer_buffer);
usbduxsub_tmp->urb_pwm->transfer_buffer = NULL;
usb_kill_urb(usbduxsub_tmp->urb_pwm);
usb_free_urb(usbduxsub_tmp->urb_pwm);
usbduxsub_tmp->urb_pwm = NULL;
}
kfree(usbduxsub_tmp->in_buffer);
usbduxsub_tmp->in_buffer = NULL;
kfree(usbduxsub_tmp->insn_buffer);
usbduxsub_tmp->insn_buffer = NULL;
kfree(usbduxsub_tmp->out_buffer);
usbduxsub_tmp->out_buffer = NULL;
kfree(usbduxsub_tmp->dac_commands);
usbduxsub_tmp->dac_commands = NULL;
kfree(usbduxsub_tmp->dux_commands);
usbduxsub_tmp->dux_commands = NULL;
usbduxsub_tmp->ai_cmd_running = 0;
usbduxsub_tmp->ao_cmd_running = 0;
usbduxsub_tmp->pwm_cmd_running = 0;
}
static int usbdux_attach_common(struct comedi_device *dev,
struct usbduxsub *udev)
{
int ret;
struct comedi_subdevice *s = NULL;
int n_subdevs;
down(&udev->sem);
udev->comedidev = dev;
if (udev->high_speed) {
n_subdevs = 5;
} else {
n_subdevs = 4;
}
ret = comedi_alloc_subdevices(dev, n_subdevs);
if (ret) {
up(&udev->sem);
return ret;
}
dev->private = udev;
s = &dev->subdevices[SUBDEV_AD];
dev->read_subdev = s;
s->private = NULL;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_CMD_READ;
s->n_chan = 8;
s->len_chanlist = 8;
s->insn_read = usbdux_ai_insn_read;
s->do_cmdtest = usbdux_ai_cmdtest;
s->do_cmd = usbdux_ai_cmd;
s->cancel = usbdux_ai_cancel;
s->maxdata = 0xfff;
s->range_table = (&range_usbdux_ai_range);
s = &dev->subdevices[SUBDEV_DA];
s->type = COMEDI_SUBD_AO;
dev->write_subdev = s;
s->private = NULL;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_CMD_WRITE;
s->n_chan = 4;
s->len_chanlist = 4;
s->maxdata = 0x0fff;
s->range_table = (&range_usbdux_ao_range);
s->do_cmdtest = usbdux_ao_cmdtest;
s->do_cmd = usbdux_ao_cmd;
s->cancel = usbdux_ao_cancel;
s->insn_read = usbdux_ao_insn_read;
s->insn_write = usbdux_ao_insn_write;
s = &dev->subdevices[SUBDEV_DIO];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = (&range_digital);
s->insn_bits = usbdux_dio_insn_bits;
s->insn_config = usbdux_dio_insn_config;
s->private = NULL;
s = &dev->subdevices[SUBDEV_COUNTER];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 4;
s->maxdata = 0xFFFF;
s->insn_read = usbdux_counter_read;
s->insn_write = usbdux_counter_write;
s->insn_config = usbdux_counter_config;
if (udev->high_speed) {
s = &dev->subdevices[SUBDEV_PWM];
s->type = COMEDI_SUBD_PWM;
s->subdev_flags = SDF_WRITABLE | SDF_PWM_HBRIDGE;
s->n_chan = 8;
s->maxdata = udev->size_pwm_buf;
s->insn_write = usbdux_pwm_write;
s->insn_read = usbdux_pwm_read;
s->insn_config = usbdux_pwm_config;
usbdux_pwm_period(dev, s, PWM_DEFAULT_PERIOD);
}
udev->attached = 1;
up(&udev->sem);
dev_info(&udev->interface->dev, "comedi%d: attached to usbdux.\n",
dev->minor);
return 0;
}
static int usbdux_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct usb_interface *uinterf = comedi_to_usb_interface(dev);
int ret;
struct usbduxsub *this_usbduxsub;
dev->private = NULL;
down(&start_stop_sem);
this_usbduxsub = usb_get_intfdata(uinterf);
if (!this_usbduxsub || !this_usbduxsub->probed) {
dev_err(dev->class_dev,
"usbdux: error: auto_attach failed, not connected\n");
ret = -ENODEV;
} else if (this_usbduxsub->attached) {
dev_err(dev->class_dev,
"error: auto_attach failed, already attached\n");
ret = -ENODEV;
} else
ret = usbdux_attach_common(dev, this_usbduxsub);
up(&start_stop_sem);
return ret;
}
static void usbdux_detach(struct comedi_device *dev)
{
struct usbduxsub *usb = dev->private;
if (usb) {
down(&usb->sem);
dev->private = NULL;
usb->attached = 0;
usb->comedidev = NULL;
up(&usb->sem);
}
}
static void usbdux_firmware_request_complete_handler(const struct firmware *fw,
void *context)
{
struct usbduxsub *usbduxsub_tmp = context;
struct usb_interface *uinterf = usbduxsub_tmp->interface;
int ret;
if (fw == NULL) {
dev_err(&uinterf->dev,
"Firmware complete handler without firmware!\n");
return;
}
ret = firmware_upload(usbduxsub_tmp, fw->data, fw->size);
if (ret) {
dev_err(&uinterf->dev,
"Could not upload firmware (err=%d)\n", ret);
goto out;
}
comedi_usb_auto_config(uinterf, &usbdux_driver, 0);
out:
release_firmware(fw);
}
static int usbdux_usb_probe(struct usb_interface *uinterf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(uinterf);
struct device *dev = &uinterf->dev;
int i;
int index;
int ret;
dev_dbg(dev, "comedi_: usbdux_: "
"finding a free structure for the usb-device\n");
down(&start_stop_sem);
index = -1;
for (i = 0; i < NUMUSBDUX; i++) {
if (!(usbduxsub[i].probed)) {
index = i;
break;
}
}
if (index == -1) {
dev_err(dev, "Too many usbdux-devices connected.\n");
up(&start_stop_sem);
return -EMFILE;
}
dev_dbg(dev, "comedi_: usbdux: "
"usbduxsub[%d] is ready to connect to comedi.\n", index);
sema_init(&(usbduxsub[index].sem), 1);
usbduxsub[index].usbdev = udev;
usbduxsub[index].interface = uinterf;
usbduxsub[index].ifnum = uinterf->altsetting->desc.bInterfaceNumber;
usb_set_intfdata(uinterf, &(usbduxsub[index]));
dev_dbg(dev, "comedi_: usbdux: ifnum=%d\n", usbduxsub[index].ifnum);
usbduxsub[index].high_speed =
(usbduxsub[index].usbdev->speed == USB_SPEED_HIGH);
usbduxsub[index].dac_commands = kzalloc(NUMOUTCHANNELS, GFP_KERNEL);
if (!usbduxsub[index].dac_commands) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].dux_commands = kzalloc(SIZEOFDUXBUFFER, GFP_KERNEL);
if (!usbduxsub[index].dux_commands) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].in_buffer = kzalloc(SIZEINBUF, GFP_KERNEL);
if (!(usbduxsub[index].in_buffer)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].insn_buffer = kzalloc(SIZEINSNBUF, GFP_KERNEL);
if (!(usbduxsub[index].insn_buffer)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].out_buffer = kzalloc(SIZEOUTBUF, GFP_KERNEL);
if (!(usbduxsub[index].out_buffer)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
i = usb_set_interface(usbduxsub[index].usbdev,
usbduxsub[index].ifnum, 3);
if (i < 0) {
dev_err(dev, "comedi_: usbdux%d: "
"could not set alternate setting 3 in high speed.\n",
index);
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENODEV;
}
if (usbduxsub[index].high_speed)
usbduxsub[index].num_in_buffers = NUMOFINBUFFERSHIGH;
else
usbduxsub[index].num_in_buffers = NUMOFINBUFFERSFULL;
usbduxsub[index].urb_in =
kcalloc(usbduxsub[index].num_in_buffers, sizeof(struct urb *),
GFP_KERNEL);
if (!(usbduxsub[index].urb_in)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
for (i = 0; i < usbduxsub[index].num_in_buffers; i++) {
usbduxsub[index].urb_in[i] = usb_alloc_urb(1, GFP_KERNEL);
if (usbduxsub[index].urb_in[i] == NULL) {
dev_err(dev, "comedi_: usbdux%d: "
"Could not alloc. urb(%d)\n", index, i);
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].urb_in[i]->dev = usbduxsub[index].usbdev;
usbduxsub[index].urb_in[i]->context = NULL;
usbduxsub[index].urb_in[i]->pipe =
usb_rcvisocpipe(usbduxsub[index].usbdev, ISOINEP);
usbduxsub[index].urb_in[i]->transfer_flags = URB_ISO_ASAP;
usbduxsub[index].urb_in[i]->transfer_buffer =
kzalloc(SIZEINBUF, GFP_KERNEL);
if (!(usbduxsub[index].urb_in[i]->transfer_buffer)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].urb_in[i]->complete = usbduxsub_ai_isoc_irq;
usbduxsub[index].urb_in[i]->number_of_packets = 1;
usbduxsub[index].urb_in[i]->transfer_buffer_length = SIZEINBUF;
usbduxsub[index].urb_in[i]->iso_frame_desc[0].offset = 0;
usbduxsub[index].urb_in[i]->iso_frame_desc[0].length = SIZEINBUF;
}
if (usbduxsub[index].high_speed)
usbduxsub[index].num_out_buffers = NUMOFOUTBUFFERSHIGH;
else
usbduxsub[index].num_out_buffers = NUMOFOUTBUFFERSFULL;
usbduxsub[index].urb_out =
kcalloc(usbduxsub[index].num_out_buffers, sizeof(struct urb *),
GFP_KERNEL);
if (!(usbduxsub[index].urb_out)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
for (i = 0; i < usbduxsub[index].num_out_buffers; i++) {
usbduxsub[index].urb_out[i] = usb_alloc_urb(1, GFP_KERNEL);
if (usbduxsub[index].urb_out[i] == NULL) {
dev_err(dev, "comedi_: usbdux%d: "
"Could not alloc. urb(%d)\n", index, i);
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].urb_out[i]->dev = usbduxsub[index].usbdev;
usbduxsub[index].urb_out[i]->context = NULL;
usbduxsub[index].urb_out[i]->pipe =
usb_sndisocpipe(usbduxsub[index].usbdev, ISOOUTEP);
usbduxsub[index].urb_out[i]->transfer_flags = URB_ISO_ASAP;
usbduxsub[index].urb_out[i]->transfer_buffer =
kzalloc(SIZEOUTBUF, GFP_KERNEL);
if (!(usbduxsub[index].urb_out[i]->transfer_buffer)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].urb_out[i]->complete = usbduxsub_ao_isoc_irq;
usbduxsub[index].urb_out[i]->number_of_packets = 1;
usbduxsub[index].urb_out[i]->transfer_buffer_length = SIZEOUTBUF;
usbduxsub[index].urb_out[i]->iso_frame_desc[0].offset = 0;
usbduxsub[index].urb_out[i]->iso_frame_desc[0].length =
SIZEOUTBUF;
if (usbduxsub[index].high_speed) {
usbduxsub[index].urb_out[i]->interval = 8;
} else {
usbduxsub[index].urb_out[i]->interval = 1;
}
}
if (usbduxsub[index].high_speed) {
usbduxsub[index].size_pwm_buf = 512;
usbduxsub[index].urb_pwm = usb_alloc_urb(0, GFP_KERNEL);
if (usbduxsub[index].urb_pwm == NULL) {
dev_err(dev, "comedi_: usbdux%d: "
"Could not alloc. pwm urb\n", index);
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
usbduxsub[index].urb_pwm->transfer_buffer =
kzalloc(usbduxsub[index].size_pwm_buf, GFP_KERNEL);
if (!(usbduxsub[index].urb_pwm->transfer_buffer)) {
tidy_up(&(usbduxsub[index]));
up(&start_stop_sem);
return -ENOMEM;
}
} else {
usbduxsub[index].urb_pwm = NULL;
usbduxsub[index].size_pwm_buf = 0;
}
usbduxsub[index].ai_cmd_running = 0;
usbduxsub[index].ao_cmd_running = 0;
usbduxsub[index].pwm_cmd_running = 0;
usbduxsub[index].probed = 1;
up(&start_stop_sem);
ret = request_firmware_nowait(THIS_MODULE,
FW_ACTION_HOTPLUG,
FIRMWARE,
&udev->dev,
GFP_KERNEL,
usbduxsub + index,
usbdux_firmware_request_complete_handler);
if (ret) {
dev_err(dev, "Could not load firmware (err=%d)\n", ret);
return ret;
}
dev_info(dev, "comedi_: usbdux%d "
"has been successfully initialised.\n", index);
return 0;
}
static void usbdux_usb_disconnect(struct usb_interface *intf)
{
struct usbduxsub *usbduxsub_tmp = usb_get_intfdata(intf);
struct usb_device *udev = interface_to_usbdev(intf);
if (!usbduxsub_tmp) {
dev_err(&intf->dev,
"comedi_: disconnect called with null pointer.\n");
return;
}
if (usbduxsub_tmp->usbdev != udev) {
dev_err(&intf->dev, "comedi_: BUG! called with wrong ptr!!!\n");
return;
}
comedi_usb_auto_unconfig(intf);
down(&start_stop_sem);
down(&usbduxsub_tmp->sem);
tidy_up(usbduxsub_tmp);
up(&usbduxsub_tmp->sem);
up(&start_stop_sem);
dev_dbg(&intf->dev, "comedi_: disconnected from the usb\n");
}
