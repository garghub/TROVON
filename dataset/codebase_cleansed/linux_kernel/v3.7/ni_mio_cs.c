static void mio_cs_win_out(struct comedi_device *dev, uint16_t data, int addr)
{
unsigned long flags;
spin_lock_irqsave(&devpriv->window_lock, flags);
if (addr < 8) {
ni_writew(data, addr * 2);
} else {
ni_writew(addr, Window_Address);
ni_writew(data, Window_Data);
}
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
static uint16_t mio_cs_win_in(struct comedi_device *dev, int addr)
{
unsigned long flags;
uint16_t ret;
spin_lock_irqsave(&devpriv->window_lock, flags);
if (addr < 8) {
ret = ni_readw(addr * 2);
} else {
ni_writew(addr, Window_Address);
ret = ni_readw(Window_Data);
}
spin_unlock_irqrestore(&devpriv->window_lock, flags);
return ret;
}
static void mio_cs_detach(struct comedi_device *dev)
{
mio_common_detach(dev);
if (dev->irq)
free_irq(dev->irq, dev);
}
static int cs_attach(struct pcmcia_device *link)
{
cur_dev = link;
mio_cs_config(link);
return 0;
}
static void cs_release(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
}
static void cs_detach(struct pcmcia_device *link)
{
cs_release(link);
}
static int mio_cs_suspend(struct pcmcia_device *link)
{
DPRINTK("pm suspend\n");
return 0;
}
static int mio_cs_resume(struct pcmcia_device *link)
{
DPRINTK("pm resume\n");
return 0;
}
static int mio_pcmcia_config_loop(struct pcmcia_device *p_dev, void *priv_data)
{
int base, ret;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_16;
for (base = 0x000; base < 0x400; base += 0x20) {
p_dev->resource[0]->start = base;
ret = pcmcia_request_io(p_dev);
if (!ret)
return 0;
}
return -ENODEV;
}
static void mio_cs_config(struct pcmcia_device *link)
{
int ret;
DPRINTK("mio_cs_config(link=%p)\n", link);
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, mio_pcmcia_config_loop, NULL);
if (ret) {
dev_warn(&link->dev, "no configuration found\n");
return;
}
if (!link->irq)
dev_info(&link->dev, "no IRQ available\n");
ret = pcmcia_enable_device(link);
}
static int mio_cs_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pcmcia_device *link;
unsigned int irq;
int ret;
DPRINTK("mio_cs_attach(dev=%p,it=%p)\n", dev, it);
link = cur_dev;
if (!link)
return -EIO;
dev->driver = &driver_ni_mio_cs;
dev->iobase = link->resource[0]->start;
irq = link->irq;
printk("comedi%d: %s: DAQCard: io 0x%04lx, irq %u, ",
dev->minor, dev->driver->driver_name, dev->iobase, irq);
#if 0
{
int i;
printk(" board fingerprint:");
for (i = 0; i < 32; i += 2) {
printk(" %04x %02x", inw(dev->iobase + i),
inb(dev->iobase + i + 1));
}
printk("\n");
printk(" board fingerprint (windowed):");
for (i = 0; i < 10; i++)
printk(" 0x%04x", win_in(i));
printk("\n");
}
#endif
dev->board_ptr = ni_boards + ni_getboardtype(dev, link);
printk(" %s", boardtype.name);
dev->board_name = boardtype.name;
ret = request_irq(irq, ni_E_interrupt, NI_E_IRQ_FLAGS,
"ni_mio_cs", dev);
if (ret < 0) {
printk(" irq not available\n");
return -EINVAL;
}
dev->irq = irq;
ret = ni_alloc_private(dev);
if (ret < 0)
return ret;
devpriv->stc_writew = &mio_cs_win_out;
devpriv->stc_readw = &mio_cs_win_in;
devpriv->stc_writel = &win_out2;
devpriv->stc_readl = &win_in2;
ret = ni_E_init(dev);
if (ret < 0)
return ret;
return 0;
}
static int ni_getboardtype(struct comedi_device *dev,
struct pcmcia_device *link)
{
int i;
for (i = 0; i < n_ni_boards; i++) {
if (ni_boards[i].device_id == link->card_id)
return i;
}
printk("unknown board 0x%04x -- pretend it is a ", link->card_id);
return 0;
}
int init_module(void)
{
pcmcia_register_driver(&ni_mio_cs_driver);
comedi_driver_register(&driver_ni_mio_cs);
return 0;
}
void cleanup_module(void)
{
pcmcia_unregister_driver(&ni_mio_cs_driver);
#if 0
while (cur_dev != NULL)
cs_detach(cur_dev->handle);
#endif
comedi_driver_unregister(&driver_ni_mio_cs);
}
