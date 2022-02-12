static void daqp_dump(struct comedi_device *dev)
{
printk(KERN_INFO "DAQP: status %02x; aux status %02x\n",
inb(dev->iobase + DAQP_STATUS), inb(dev->iobase + DAQP_AUX));
}
static void hex_dump(char *str, void *ptr, int len)
{
unsigned char *cptr = ptr;
int i;
printk(str);
for (i = 0; i < len; i++) {
if (i % 16 == 0)
printk("\n%p:", cptr);
printk(" %02x", *(cptr++));
}
printk("\n");
}
static int daqp_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct local_info_t *local = (struct local_info_t *)s->private;
if (local->stop)
return -EIO;
outb(DAQP_COMMAND_STOP, dev->iobase + DAQP_COMMAND);
local->interrupt_mode = semaphore;
return 0;
}
static enum irqreturn daqp_interrupt(int irq, void *dev_id)
{
struct local_info_t *local = (struct local_info_t *)dev_id;
struct comedi_device *dev;
struct comedi_subdevice *s;
int loop_limit = 10000;
int status;
if (local == NULL) {
printk(KERN_WARNING
"daqp_interrupt(): irq %d for unknown device.\n", irq);
return IRQ_NONE;
}
dev = local->dev;
if (dev == NULL) {
printk(KERN_WARNING "daqp_interrupt(): NULL comedi_device.\n");
return IRQ_NONE;
}
if (!dev->attached) {
printk(KERN_WARNING
"daqp_interrupt(): struct comedi_device not yet attached.\n");
return IRQ_NONE;
}
s = local->s;
if (s == NULL) {
printk(KERN_WARNING
"daqp_interrupt(): NULL comedi_subdevice.\n");
return IRQ_NONE;
}
if ((struct local_info_t *)s->private != local) {
printk(KERN_WARNING
"daqp_interrupt(): invalid comedi_subdevice.\n");
return IRQ_NONE;
}
switch (local->interrupt_mode) {
case semaphore:
complete(&local->eos);
break;
case buffer:
while (!((status = inb(dev->iobase + DAQP_STATUS))
& DAQP_STATUS_FIFO_EMPTY)) {
short data;
if (status & DAQP_STATUS_DATA_LOST) {
s->async->events |=
COMEDI_CB_EOA | COMEDI_CB_OVERFLOW;
printk("daqp: data lost\n");
daqp_ai_cancel(dev, s);
break;
}
data = inb(dev->iobase + DAQP_FIFO);
data |= inb(dev->iobase + DAQP_FIFO) << 8;
data ^= 0x8000;
comedi_buf_put(s->async, data);
if (local->count > 0) {
local->count--;
if (local->count == 0) {
daqp_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
break;
}
}
if ((loop_limit--) <= 0)
break;
}
if (loop_limit <= 0) {
printk(KERN_WARNING
"loop_limit reached in daqp_interrupt()\n");
daqp_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
}
s->async->events |= COMEDI_CB_BLOCK;
comedi_event(dev, s);
}
return IRQ_HANDLED;
}
static int daqp_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct local_info_t *local = (struct local_info_t *)s->private;
int i;
int v;
int counter = 10000;
if (local->stop)
return -EIO;
daqp_ai_cancel(dev, s);
outb(0, dev->iobase + DAQP_AUX);
outb(DAQP_COMMAND_RSTQ, dev->iobase + DAQP_COMMAND);
v = DAQP_SCANLIST_CHANNEL(CR_CHAN(insn->chanspec))
| DAQP_SCANLIST_GAIN(CR_RANGE(insn->chanspec));
if (CR_AREF(insn->chanspec) == AREF_DIFF)
v |= DAQP_SCANLIST_DIFFERENTIAL;
v |= DAQP_SCANLIST_START;
outb(v & 0xff, dev->iobase + DAQP_SCANLIST);
outb(v >> 8, dev->iobase + DAQP_SCANLIST);
outb(DAQP_COMMAND_RSTF, dev->iobase + DAQP_COMMAND);
v = DAQP_CONTROL_TRIGGER_ONESHOT | DAQP_CONTROL_TRIGGER_INTERNAL
| DAQP_CONTROL_PACER_100kHz | DAQP_CONTROL_EOS_INT_ENABLE;
outb(v, dev->iobase + DAQP_CONTROL);
while (--counter
&& (inb(dev->iobase + DAQP_STATUS) & DAQP_STATUS_EVENTS)) ;
if (!counter) {
printk("daqp: couldn't clear interrupts in status register\n");
return -1;
}
init_completion(&local->eos);
local->interrupt_mode = semaphore;
local->dev = dev;
local->s = s;
for (i = 0; i < insn->n; i++) {
outb(DAQP_COMMAND_ARM | DAQP_COMMAND_FIFO_DATA,
dev->iobase + DAQP_COMMAND);
if (wait_for_completion_interruptible(&local->eos))
return -EINTR;
data[i] = inb(dev->iobase + DAQP_FIFO);
data[i] |= inb(dev->iobase + DAQP_FIFO) << 8;
data[i] ^= 0x8000;
}
return insn->n;
}
static int daqp_ns_to_timer(unsigned int *ns, int round)
{
int timer;
timer = *ns / 200;
*ns = timer * 200;
return timer;
}
static int daqp_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
#define MAX_SPEED 10000
if (cmd->scan_begin_src == TRIG_TIMER
&& cmd->scan_begin_arg < MAX_SPEED) {
cmd->scan_begin_arg = MAX_SPEED;
err++;
}
if (cmd->scan_begin_src == TRIG_TIMER && cmd->convert_src == TRIG_TIMER
&& cmd->scan_begin_arg != cmd->convert_arg * cmd->scan_end_arg) {
err++;
}
if (cmd->convert_src == TRIG_TIMER && cmd->convert_arg < MAX_SPEED) {
cmd->convert_arg = MAX_SPEED;
err++;
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (cmd->stop_arg > 0x00ffffff) {
cmd->stop_arg = 0x00ffffff;
err++;
}
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
daqp_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
daqp_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
}
if (err)
return 4;
return 0;
}
static int daqp_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct local_info_t *local = (struct local_info_t *)s->private;
struct comedi_cmd *cmd = &s->async->cmd;
int counter;
int scanlist_start_on_every_entry;
int threshold;
int i;
int v;
if (local->stop)
return -EIO;
daqp_ai_cancel(dev, s);
outb(0, dev->iobase + DAQP_AUX);
outb(DAQP_COMMAND_RSTQ, dev->iobase + DAQP_COMMAND);
if (cmd->convert_src == TRIG_TIMER) {
counter = daqp_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
outb(counter & 0xff, dev->iobase + DAQP_PACER_LOW);
outb((counter >> 8) & 0xff, dev->iobase + DAQP_PACER_MID);
outb((counter >> 16) & 0xff, dev->iobase + DAQP_PACER_HIGH);
scanlist_start_on_every_entry = 1;
} else {
counter = daqp_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
outb(counter & 0xff, dev->iobase + DAQP_PACER_LOW);
outb((counter >> 8) & 0xff, dev->iobase + DAQP_PACER_MID);
outb((counter >> 16) & 0xff, dev->iobase + DAQP_PACER_HIGH);
scanlist_start_on_every_entry = 0;
}
for (i = 0; i < cmd->chanlist_len; i++) {
int chanspec = cmd->chanlist[i];
v = DAQP_SCANLIST_CHANNEL(CR_CHAN(chanspec))
| DAQP_SCANLIST_GAIN(CR_RANGE(chanspec));
if (CR_AREF(chanspec) == AREF_DIFF)
v |= DAQP_SCANLIST_DIFFERENTIAL;
if (i == 0 || scanlist_start_on_every_entry)
v |= DAQP_SCANLIST_START;
outb(v & 0xff, dev->iobase + DAQP_SCANLIST);
outb(v >> 8, dev->iobase + DAQP_SCANLIST);
}
if (cmd->stop_src == TRIG_COUNT) {
local->count = cmd->stop_arg * cmd->scan_end_arg;
threshold = 2 * local->count;
while (threshold > DAQP_FIFO_SIZE * 3 / 4)
threshold /= 2;
} else {
local->count = -1;
threshold = DAQP_FIFO_SIZE / 2;
}
outb(DAQP_COMMAND_RSTF, dev->iobase + DAQP_COMMAND);
outb(0x00, dev->iobase + DAQP_FIFO);
outb(0x00, dev->iobase + DAQP_FIFO);
outb((DAQP_FIFO_SIZE - threshold) & 0xff, dev->iobase + DAQP_FIFO);
outb((DAQP_FIFO_SIZE - threshold) >> 8, dev->iobase + DAQP_FIFO);
v = DAQP_CONTROL_TRIGGER_CONTINUOUS | DAQP_CONTROL_TRIGGER_INTERNAL
| DAQP_CONTROL_PACER_5MHz | DAQP_CONTROL_FIFO_INT_ENABLE;
outb(v, dev->iobase + DAQP_CONTROL);
counter = 100;
while (--counter
&& (inb(dev->iobase + DAQP_STATUS) & DAQP_STATUS_EVENTS)) ;
if (!counter) {
printk(KERN_ERR
"daqp: couldn't clear interrupts in status register\n");
return -1;
}
local->interrupt_mode = buffer;
local->dev = dev;
local->s = s;
outb(DAQP_COMMAND_ARM | DAQP_COMMAND_FIFO_DATA,
dev->iobase + DAQP_COMMAND);
return 0;
}
static int daqp_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct local_info_t *local = (struct local_info_t *)s->private;
int d;
unsigned int chan;
if (local->stop)
return -EIO;
chan = CR_CHAN(insn->chanspec);
d = data[0];
d &= 0x0fff;
d ^= 0x0800;
d |= chan << 12;
outb(0, dev->iobase + DAQP_AUX);
outw(d, dev->iobase + DAQP_DA);
return 1;
}
static int daqp_di_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct local_info_t *local = (struct local_info_t *)s->private;
if (local->stop)
return -EIO;
data[0] = inb(dev->iobase + DAQP_DIGITAL_IO);
return 1;
}
static int daqp_do_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct local_info_t *local = (struct local_info_t *)s->private;
if (local->stop)
return -EIO;
outw(data[0] & 0xf, dev->iobase + DAQP_DIGITAL_IO);
return 1;
}
static int daqp_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
int ret;
struct local_info_t *local = dev_table[it->options[0]];
struct comedi_subdevice *s;
if (it->options[0] < 0 || it->options[0] >= MAX_DEV || !local) {
printk("comedi%d: No such daqp device %d\n",
dev->minor, it->options[0]);
return -EIO;
}
strcpy(local->board_name, "DAQP");
dev->board_name = local->board_name;
if (local->link->prod_id[2]) {
if (strncmp(local->link->prod_id[2], "DAQP", 4) == 0) {
strncpy(local->board_name, local->link->prod_id[2],
sizeof(local->board_name));
}
}
dev->iobase = local->link->resource[0]->start;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
printk(KERN_INFO "comedi%d: attaching daqp%d (io 0x%04lx)\n",
dev->minor, it->options[0], dev->iobase);
s = &dev->subdevices[0];
dev->read_subdev = s;
s->private = local;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF | SDF_CMD_READ;
s->n_chan = 8;
s->len_chanlist = 2048;
s->maxdata = 0xffff;
s->range_table = &range_daqp_ai;
s->insn_read = daqp_ai_insn_read;
s->do_cmdtest = daqp_ai_cmdtest;
s->do_cmd = daqp_ai_cmd;
s->cancel = daqp_ai_cancel;
s = &dev->subdevices[1];
dev->write_subdev = s;
s->private = local;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 2;
s->len_chanlist = 1;
s->maxdata = 0x0fff;
s->range_table = &range_daqp_ao;
s->insn_write = daqp_ao_insn_write;
s = &dev->subdevices[2];
s->private = local;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 1;
s->len_chanlist = 1;
s->insn_read = daqp_di_insn_read;
s = &dev->subdevices[3];
s->private = local;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 1;
s->len_chanlist = 1;
s->insn_write = daqp_do_insn_write;
return 1;
}
static void daqp_detach(struct comedi_device *dev)
{
}
static int daqp_cs_attach(struct pcmcia_device *link)
{
struct local_info_t *local;
int i;
dev_dbg(&link->dev, "daqp_cs_attach()\n");
for (i = 0; i < MAX_DEV; i++)
if (dev_table[i] == NULL)
break;
if (i == MAX_DEV) {
printk(KERN_NOTICE "daqp_cs: no devices available\n");
return -ENODEV;
}
local = kzalloc(sizeof(struct local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
local->table_index = i;
dev_table[i] = local;
local->link = link;
link->priv = local;
daqp_cs_config(link);
return 0;
}
static void daqp_cs_detach(struct pcmcia_device *link)
{
struct local_info_t *dev = link->priv;
dev->stop = 1;
daqp_cs_release(link);
dev_table[dev->table_index] = NULL;
kfree(dev);
}
static int daqp_pcmcia_config_loop(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static void daqp_cs_config(struct pcmcia_device *link)
{
int ret;
dev_dbg(&link->dev, "daqp_cs_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, daqp_pcmcia_config_loop, NULL);
if (ret) {
dev_warn(&link->dev, "no configuration found\n");
goto failed;
}
ret = pcmcia_request_irq(link, daqp_interrupt);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
return;
failed:
daqp_cs_release(link);
}
static void daqp_cs_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "daqp_cs_release\n");
pcmcia_disable_device(link);
}
static int daqp_cs_suspend(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 1;
return 0;
}
static int daqp_cs_resume(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 0;
return 0;
}
int __init init_module(void)
{
pcmcia_register_driver(&daqp_cs_driver);
comedi_driver_register(&driver_daqp);
return 0;
}
void __exit cleanup_module(void)
{
comedi_driver_unregister(&driver_daqp);
pcmcia_unregister_driver(&daqp_cs_driver);
}
