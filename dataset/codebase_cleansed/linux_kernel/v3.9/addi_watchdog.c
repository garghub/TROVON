static int addi_watchdog_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_watchdog_private *spriv = s->private;
unsigned int reload;
switch (data[0]) {
case INSN_CONFIG_ARM:
spriv->wdog_ctrl = ADDI_WDOG_CTRL_ENABLE;
reload = data[1] & s->maxdata;
outl(reload, spriv->iobase + ADDI_WDOG_RELOAD_REG);
dev_info(dev->class_dev, "watchdog enabled, timeout:%dms\n",
20 * reload + 20);
break;
case INSN_CONFIG_DISARM:
spriv->wdog_ctrl = 0;
break;
default:
return -EINVAL;
}
outl(spriv->wdog_ctrl, spriv->iobase + ADDI_WDOG_CTRL_REG);
return insn->n;
}
static int addi_watchdog_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_watchdog_private *spriv = s->private;
int i;
for (i = 0; i < insn->n; i++)
data[i] = inl(spriv->iobase + ADDI_WDOG_STATUS_REG);
return insn->n;
}
static int addi_watchdog_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_watchdog_private *spriv = s->private;
int i;
if (spriv->wdog_ctrl == 0) {
dev_warn(dev->class_dev, "watchdog is disabled\n");
return -EINVAL;
}
for (i = 0; i < insn->n; i++) {
outl(spriv->wdog_ctrl | ADDI_WDOG_CTRL_SW_TRIG,
spriv->iobase + ADDI_WDOG_CTRL_REG);
}
return insn->n;
}
void addi_watchdog_reset(unsigned long iobase)
{
outl(0x0, iobase + ADDI_WDOG_CTRL_REG);
outl(0x0, iobase + ADDI_WDOG_RELOAD_REG);
}
int addi_watchdog_init(struct comedi_subdevice *s, unsigned long iobase)
{
struct addi_watchdog_private *spriv;
spriv = kzalloc(sizeof(*spriv), GFP_KERNEL);
if (!spriv)
return -ENOMEM;
spriv->iobase = iobase;
s->private = spriv;
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 1;
s->maxdata = 0xff;
s->insn_config = addi_watchdog_insn_config;
s->insn_read = addi_watchdog_insn_read;
s->insn_write = addi_watchdog_insn_write;
return 0;
}
void addi_watchdog_cleanup(struct comedi_subdevice *s)
{
kfree(s->private);
}
static int __init addi_watchdog_module_init(void)
{
return 0;
}
static void __exit addi_watchdog_module_exit(void)
{
}
