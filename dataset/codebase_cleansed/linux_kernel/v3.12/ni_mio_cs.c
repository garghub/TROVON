static void mio_cs_win_out(struct comedi_device *dev, uint16_t data, int addr)
{
struct ni_private *devpriv = dev->private;
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
struct ni_private *devpriv = dev->private;
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
static const void *ni_getboardtype(struct comedi_device *dev,
struct pcmcia_device *link)
{
static const struct ni_board_struct *board;
int i;
for (i = 0; i < ARRAY_SIZE(ni_boards); i++) {
board = &ni_boards[i];
if (board->device_id == link->card_id)
return board;
}
return NULL;
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
static int mio_cs_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
static const struct ni_board_struct *board;
struct ni_private *devpriv;
int ret;
board = ni_getboardtype(dev, link);
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
link->config_flags |= CONF_AUTO_SET_IO | CONF_ENABLE_IRQ;
ret = comedi_pcmcia_enable(dev, mio_pcmcia_config_loop);
if (ret)
return ret;
dev->iobase = link->resource[0]->start;
link->priv = dev;
ret = pcmcia_request_irq(link, ni_E_interrupt);
if (ret)
return ret;
dev->irq = link->irq;
ret = ni_alloc_private(dev);
if (ret)
return ret;
devpriv = dev->private;
devpriv->stc_writew = mio_cs_win_out;
devpriv->stc_readw = mio_cs_win_in;
devpriv->stc_writel = win_out2;
devpriv->stc_readl = win_in2;
return ni_E_init(dev);
}
static void mio_cs_detach(struct comedi_device *dev)
{
mio_common_detach(dev);
comedi_pcmcia_disable(dev);
}
static int cs_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_ni_mio_cs);
}
