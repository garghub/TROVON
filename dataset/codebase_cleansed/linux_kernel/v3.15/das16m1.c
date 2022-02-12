static inline unsigned short munge_sample(unsigned short data)
{
return (data >> 4) & 0xfff;
}
static void munge_sample_array(unsigned short *array, unsigned int num_elements)
{
unsigned int i;
for (i = 0; i < num_elements; i++)
array[i] = munge_sample(array[i]);
}
static int das16m1_cmd_test(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
struct das16m1_private_struct *devpriv = dev->private;
unsigned int err = 0, tmp, i;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, 1000);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT) {
} else {
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_10MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&cmd->convert_arg, cmd->flags);
if (tmp != cmd->convert_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 1) {
for (i = 0; i < cmd->chanlist_len; i++) {
if ((i % 2) != (CR_CHAN(cmd->chanlist[i]) % 2)) {
comedi_error(dev, "bad chanlist:\n"
" even/odd channels must go have even/odd chanlist indices");
err++;
}
}
if ((cmd->chanlist_len % 2) != 0) {
comedi_error(dev,
"chanlist must be of even length or length 1");
err++;
}
}
if (err)
return 5;
return 0;
}
static unsigned int das16m1_set_pacer(struct comedi_device *dev,
unsigned int ns, int rounding_flags)
{
struct das16m1_private_struct *devpriv = dev->private;
i8253_cascade_ns_to_timer_2div(I8254_OSC_BASE_10MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&ns, rounding_flags);
i8254_load(dev->iobase + DAS16M1_8254_SECOND, 0, 1, devpriv->divisor1,
2);
i8254_load(dev->iobase + DAS16M1_8254_SECOND, 0, 2, devpriv->divisor2,
2);
return ns;
}
static int das16m1_cmd_exec(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das16m1_private_struct *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int byte, i;
devpriv->control_state &= ~INTE & ~PACER_MASK;
outb(devpriv->control_state, dev->iobase + DAS16M1_INTR_CONTROL);
devpriv->adc_count = 0;
i8254_load(dev->iobase + DAS16M1_8254_FIRST, 0, 1, 0, 2);
devpriv->initial_hw_count =
i8254_read(dev->iobase + DAS16M1_8254_FIRST, 0, 1);
for (i = 0; i < cmd->chanlist_len; i++) {
outb(i, dev->iobase + DAS16M1_QUEUE_ADDR);
byte =
Q_CHAN(CR_CHAN(cmd->chanlist[i])) |
Q_RANGE(CR_RANGE(cmd->chanlist[i]));
outb(byte, dev->iobase + DAS16M1_QUEUE_DATA);
}
cmd->convert_arg =
das16m1_set_pacer(dev, cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
byte = 0;
if (cmd->start_src == TRIG_EXT && cmd->convert_src != TRIG_EXT)
byte |= EXT_TRIG_BIT;
outb(byte, dev->iobase + DAS16M1_CS);
outb(0, dev->iobase + DAS16M1_CLEAR_INTR);
devpriv->control_state &= ~PACER_MASK;
if (cmd->convert_src == TRIG_TIMER)
devpriv->control_state |= INT_PACER;
else
devpriv->control_state |= EXT_PACER;
devpriv->control_state |= INTE;
outb(devpriv->control_state, dev->iobase + DAS16M1_INTR_CONTROL);
return 0;
}
static int das16m1_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct das16m1_private_struct *devpriv = dev->private;
devpriv->control_state &= ~INTE & ~PACER_MASK;
outb(devpriv->control_state, dev->iobase + DAS16M1_INTR_CONTROL);
return 0;
}
static int das16m1_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAS16M1_CS);
if (status & IRQDATA)
return 0;
return -EBUSY;
}
static int das16m1_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct das16m1_private_struct *devpriv = dev->private;
int ret;
int n;
int byte;
devpriv->control_state &= ~INTE & ~PACER_MASK;
outb(devpriv->control_state, dev->iobase + DAS16M1_INTR_CONTROL);
outb(0, dev->iobase + DAS16M1_QUEUE_ADDR);
byte =
Q_CHAN(CR_CHAN(insn->chanspec)) | Q_RANGE(CR_RANGE(insn->chanspec));
outb(byte, dev->iobase + DAS16M1_QUEUE_DATA);
for (n = 0; n < insn->n; n++) {
outb(0, dev->iobase + DAS16M1_CLEAR_INTR);
outb(0, dev->iobase);
ret = comedi_timeout(dev, s, insn, das16m1_ai_eoc, 0);
if (ret)
return ret;
data[n] = munge_sample(inw(dev->iobase));
}
return n;
}
static int das16m1_di_rbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int bits;
bits = inb(dev->iobase + DAS16M1_DIO) & 0xf;
data[1] = bits;
data[0] = 0;
return insn->n;
}
static int das16m1_do_wbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAS16M1_DIO);
data[1] = s->state;
return insn->n;
}
static void das16m1_handler(struct comedi_device *dev, unsigned int status)
{
struct das16m1_private_struct *devpriv = dev->private;
struct comedi_subdevice *s;
struct comedi_async *async;
struct comedi_cmd *cmd;
u16 num_samples;
u16 hw_counter;
s = dev->read_subdev;
async = s->async;
cmd = &async->cmd;
hw_counter = i8254_read(dev->iobase + DAS16M1_8254_FIRST, 0, 1);
if (devpriv->adc_count == 0 && hw_counter == devpriv->initial_hw_count) {
num_samples = 0;
} else {
num_samples = -hw_counter - devpriv->adc_count;
}
if (cmd->stop_src == TRIG_COUNT) {
if (num_samples > cmd->stop_arg * cmd->chanlist_len)
num_samples = cmd->stop_arg * cmd->chanlist_len;
}
if (num_samples > FIFO_SIZE)
num_samples = FIFO_SIZE;
insw(dev->iobase, devpriv->ai_buffer, num_samples);
munge_sample_array(devpriv->ai_buffer, num_samples);
cfc_write_array_to_buffer(s, devpriv->ai_buffer,
num_samples * sizeof(short));
devpriv->adc_count += num_samples;
if (cmd->stop_src == TRIG_COUNT) {
if (devpriv->adc_count >= cmd->stop_arg * cmd->chanlist_len) {
async->events |= COMEDI_CB_EOA;
}
}
if (status & OVRUN) {
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_error(dev, "fifo overflow");
}
cfc_handle_events(dev, s);
}
static int das16m1_poll(struct comedi_device *dev, struct comedi_subdevice *s)
{
unsigned long flags;
unsigned int status;
spin_lock_irqsave(&dev->spinlock, flags);
status = inb(dev->iobase + DAS16M1_CS);
das16m1_handler(dev, status);
spin_unlock_irqrestore(&dev->spinlock, flags);
return s->async->buf_write_count - s->async->buf_read_count;
}
static irqreturn_t das16m1_interrupt(int irq, void *d)
{
int status;
struct comedi_device *dev = d;
if (!dev->attached) {
comedi_error(dev, "premature interrupt");
return IRQ_HANDLED;
}
spin_lock(&dev->spinlock);
status = inb(dev->iobase + DAS16M1_CS);
if ((status & (IRQDATA | OVRUN)) == 0) {
comedi_error(dev, "spurious interrupt");
spin_unlock(&dev->spinlock);
return IRQ_NONE;
}
das16m1_handler(dev, status);
outb(0, dev->iobase + DAS16M1_CLEAR_INTR);
spin_unlock(&dev->spinlock);
return IRQ_HANDLED;
}
static int das16m1_irq_bits(unsigned int irq)
{
switch (irq) {
case 10:
return 0x0;
case 11:
return 0x1;
case 12:
return 0x2;
case 15:
return 0x3;
case 2:
return 0x4;
case 3:
return 0x5;
case 5:
return 0x6;
case 7:
return 0x7;
default:
return 0x0;
}
}
static int das16m1_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct das16m1_private_struct *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], DAS16M1_SIZE);
if (ret)
return ret;
ret = __comedi_request_region(dev, dev->iobase + DAS16M1_82C55,
DAS16M1_SIZE2);
if (ret)
return ret;
devpriv->extra_iobase = dev->iobase + DAS16M1_82C55;
if ((1 << it->options[1]) & 0xdcfc) {
ret = request_irq(it->options[1], das16m1_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF;
s->n_chan = 8;
s->maxdata = (1 << 12) - 1;
s->range_table = &range_das16m1;
s->insn_read = das16m1_ai_rinsn;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 256;
s->do_cmdtest = das16m1_cmd_test;
s->do_cmd = das16m1_cmd_exec;
s->cancel = das16m1_cancel;
s->poll = das16m1_poll;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das16m1_di_rbits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das16m1_do_wbits;
s = &dev->subdevices[3];
ret = subdev_8255_init(dev, s, NULL, devpriv->extra_iobase);
if (ret)
return ret;
outb(TOTAL_CLEAR, dev->iobase + DAS16M1_8254_FIRST_CNTRL);
outb(0, dev->iobase + DAS16M1_DIO);
devpriv->control_state = das16m1_irq_bits(dev->irq) << 4;
outb(devpriv->control_state, dev->iobase + DAS16M1_INTR_CONTROL);
return 0;
}
static void das16m1_detach(struct comedi_device *dev)
{
struct das16m1_private_struct *devpriv = dev->private;
if (devpriv && devpriv->extra_iobase)
release_region(devpriv->extra_iobase, DAS16M1_SIZE2);
comedi_legacy_detach(dev);
}
