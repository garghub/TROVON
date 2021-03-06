void subdev_700_interrupt(struct comedi_device *dev, struct comedi_subdevice *s)
{
short d;
d = CALLBACK_FUNC(0, _700_DATA, 0, CALLBACK_ARG);
comedi_buf_put(s->async, d);
s->async->events |= COMEDI_CB_EOS;
comedi_event(dev, s);
}
static int subdev_700_cb(int dir, int port, int data, unsigned long arg)
{
unsigned long iobase = arg;
if (dir) {
outb(data, iobase + DIO_W);
return 0;
} else {
return inb(iobase + DIO_R);
}
}
static int subdev_700_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
if (data[0] & 0xff)
CALLBACK_FUNC(1, _700_DATA, s->state & 0xff,
CALLBACK_ARG);
}
data[1] = s->state & 0xff;
data[1] |= CALLBACK_FUNC(0, _700_DATA, 0, CALLBACK_ARG) << 8;
return 2;
}
static int subdev_700_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
break;
case INSN_CONFIG_DIO_OUTPUT:
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->
io_bits & (1 << CR_CHAN(insn->chanspec))) ? COMEDI_OUTPUT :
COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
}
return 1;
}
static void do_config(struct comedi_device *dev, struct comedi_subdevice *s)
{
return;
}
static int subdev_700_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
unsigned int tmp;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_EXT;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_FOLLOW;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
cmd->stop_src &= TRIG_NONE;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
if (cmd->convert_arg != 0) {
cmd->convert_arg = 0;
err++;
}
if (cmd->scan_end_arg != 1) {
cmd->scan_end_arg = 1;
err++;
}
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
if (err)
return 3;
if (err)
return 4;
return 0;
}
static int subdev_700_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
return 0;
}
static int subdev_700_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
return 0;
}
int subdev_700_init(struct comedi_device *dev, struct comedi_subdevice *s,
int (*cb) (int, int, int, unsigned long), unsigned long arg)
{
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->range_table = &range_digital;
s->maxdata = 1;
s->private = kmalloc(sizeof(struct subdev_700_struct), GFP_KERNEL);
if (!s->private)
return -ENOMEM;
CALLBACK_ARG = arg;
if (cb == NULL)
CALLBACK_FUNC = subdev_700_cb;
else
CALLBACK_FUNC = cb;
s->insn_bits = subdev_700_insn;
s->insn_config = subdev_700_insn_config;
s->state = 0;
s->io_bits = 0x00ff;
do_config(dev, s);
return 0;
}
int subdev_700_init_irq(struct comedi_device *dev, struct comedi_subdevice *s,
int (*cb) (int, int, int, unsigned long),
unsigned long arg)
{
int ret;
ret = subdev_700_init(dev, s, cb, arg);
if (ret < 0)
return ret;
s->do_cmdtest = subdev_700_cmdtest;
s->do_cmd = subdev_700_cmd;
s->cancel = subdev_700_cancel;
subdevpriv->have_irq = 1;
return 0;
}
void subdev_700_cleanup(struct comedi_device *dev, struct comedi_subdevice *s)
{
if (s->private)
if (subdevpriv->have_irq)
kfree(s->private);
}
static int dio700_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase = 0;
#ifdef incomplete
unsigned int irq = 0;
#endif
struct pcmcia_device *link;
if (alloc_private(dev, sizeof(struct dio700_private)) < 0)
return -ENOMEM;
switch (thisboard->bustype) {
case pcmcia_bustype:
link = pcmcia_cur_dev;
if (!link)
return -EIO;
iobase = link->resource[0]->start;
#ifdef incomplete
irq = link->irq;
#endif
break;
default:
printk(KERN_ERR "bug! couldn't determine board type\n");
return -EINVAL;
break;
}
printk(KERN_ERR "comedi%d: ni_daq_700: %s, io 0x%lx", dev->minor,
thisboard->name, iobase);
#ifdef incomplete
if (irq)
printk(", irq %u", irq);
#endif
printk("\n");
if (iobase == 0) {
printk(KERN_ERR "io base address is zero!\n");
return -EINVAL;
}
dev->iobase = iobase;
#ifdef incomplete
dev->irq = irq;
#endif
dev->board_name = thisboard->name;
if (alloc_subdevices(dev, 1) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
subdev_700_init(dev, s, NULL, dev->iobase);
return 0;
}
static void dio700_detach(struct comedi_device *dev)
{
if (dev->subdevices)
subdev_700_cleanup(dev, dev->subdevices + 0);
if (thisboard->bustype != pcmcia_bustype && dev->iobase)
release_region(dev->iobase, DIO700_SIZE);
if (dev->irq)
free_irq(dev->irq, dev);
}
static int dio700_cs_attach(struct pcmcia_device *link)
{
struct local_info_t *local;
printk(KERN_INFO "ni_daq_700: cs-attach\n");
dev_dbg(&link->dev, "dio700_cs_attach()\n");
local = kzalloc(sizeof(struct local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
local->link = link;
link->priv = local;
pcmcia_cur_dev = link;
dio700_config(link);
return 0;
}
static void dio700_cs_detach(struct pcmcia_device *link)
{
((struct local_info_t *)link->priv)->stop = 1;
dio700_release(link);
kfree(link->priv);
}
static int dio700_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static void dio700_config(struct pcmcia_device *link)
{
int ret;
printk(KERN_INFO "ni_daq_700: cs-config\n");
dev_dbg(&link->dev, "dio700_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_AUDIO |
CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, dio700_pcmcia_config_loop, NULL);
if (ret) {
dev_warn(&link->dev, "no configuration found\n");
goto failed;
}
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret != 0)
goto failed;
return;
failed:
printk(KERN_INFO "ni_daq_700 cs failed");
dio700_release(link);
}
static void dio700_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "dio700_release\n");
pcmcia_disable_device(link);
}
static int dio700_cs_suspend(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 1;
return 0;
}
static int dio700_cs_resume(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 0;
return 0;
}
static int __init init_dio700_cs(void)
{
pcmcia_register_driver(&dio700_cs_driver);
return 0;
}
static void __exit exit_dio700_cs(void)
{
pr_debug("ni_daq_700: unloading\n");
pcmcia_unregister_driver(&dio700_cs_driver);
}
int __init init_module(void)
{
int ret;
ret = init_dio700_cs();
if (ret < 0)
return ret;
return comedi_driver_register(&driver_dio700);
}
void __exit cleanup_module(void)
{
exit_dio700_cs();
comedi_driver_unregister(&driver_dio700);
}
