static void ni_atmio_win_out(struct comedi_device *dev, uint16_t data, int addr)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->window_lock, flags);
if ((addr) < 8) {
ni_writew(data, addr * 2);
} else {
ni_writew(addr, Window_Address);
ni_writew(data, Window_Data);
}
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
static uint16_t ni_atmio_win_in(struct comedi_device *dev, int addr)
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
static int ni_isapnp_find_board(struct pnp_dev **dev)
{
struct pnp_dev *isapnp_dev = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(ni_boards); i++) {
isapnp_dev = pnp_find_dev(NULL,
ISAPNP_VENDOR('N', 'I', 'C'),
ISAPNP_FUNCTION(ni_boards[i].
isapnp_id), NULL);
if (isapnp_dev == NULL || isapnp_dev->card == NULL)
continue;
if (pnp_device_attach(isapnp_dev) < 0) {
printk
("ni_atmio: %s found but already active, skipping.\n",
ni_boards[i].name);
continue;
}
if (pnp_activate_dev(isapnp_dev) < 0) {
pnp_device_detach(isapnp_dev);
return -EAGAIN;
}
if (!pnp_port_valid(isapnp_dev, 0)
|| !pnp_irq_valid(isapnp_dev, 0)) {
pnp_device_detach(isapnp_dev);
printk("ni_atmio: pnp invalid port or irq, aborting\n");
return -ENOMEM;
}
break;
}
if (i == ARRAY_SIZE(ni_boards))
return -ENODEV;
*dev = isapnp_dev;
return 0;
}
static int ni_getboardtype(struct comedi_device *dev)
{
int device_id = ni_read_eeprom(dev, 511);
int i;
for (i = 0; i < ARRAY_SIZE(ni_boards); i++) {
if (ni_boards[i].device_id == device_id)
return i;
}
if (device_id == 255)
printk(" can't find board\n");
else if (device_id == 0)
printk(" EEPROM read error (?) or device not found\n");
else
printk(" unknown device ID %d -- contact author\n", device_id);
return -1;
}
static int ni_atmio_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct ni_board_struct *boardtype;
struct ni_private *devpriv;
struct pnp_dev *isapnp_dev;
int ret;
unsigned long iobase;
int board;
unsigned int irq;
ret = ni_alloc_private(dev);
if (ret)
return ret;
devpriv = dev->private;
devpriv->stc_writew = &ni_atmio_win_out;
devpriv->stc_readw = &ni_atmio_win_in;
devpriv->stc_writel = &win_out2;
devpriv->stc_readl = &win_in2;
iobase = it->options[0];
irq = it->options[1];
isapnp_dev = NULL;
if (iobase == 0) {
ret = ni_isapnp_find_board(&isapnp_dev);
if (ret < 0)
return ret;
iobase = pnp_port_start(isapnp_dev, 0);
irq = pnp_irq(isapnp_dev, 0);
devpriv->isapnp_dev = isapnp_dev;
}
ret = comedi_request_region(dev, iobase, NI_SIZE);
if (ret)
return ret;
board = ni_getboardtype(dev);
if (board < 0)
return -EIO;
dev->board_ptr = ni_boards + board;
boardtype = comedi_board(dev);
printk(" %s", boardtype->name);
dev->board_name = boardtype->name;
if (irq != 0) {
if (irq > 15 || ni_irqpin[irq] == -1) {
printk(" invalid irq %u\n", irq);
return -EINVAL;
}
printk(" ( irq = %u )", irq);
ret = request_irq(irq, ni_E_interrupt, NI_E_IRQ_FLAGS,
"ni_atmio", dev);
if (ret < 0) {
printk(" irq not available\n");
return -EINVAL;
}
dev->irq = irq;
}
ret = ni_E_init(dev);
if (ret < 0)
return ret;
return 0;
}
static void ni_atmio_detach(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
mio_common_detach(dev);
comedi_legacy_detach(dev);
if (devpriv->isapnp_dev)
pnp_device_detach(devpriv->isapnp_dev);
}
