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
if (pnp_device_attach(isapnp_dev) < 0)
continue;
if (pnp_activate_dev(isapnp_dev) < 0) {
pnp_device_detach(isapnp_dev);
return -EAGAIN;
}
if (!pnp_port_valid(isapnp_dev, 0) ||
!pnp_irq_valid(isapnp_dev, 0)) {
pnp_device_detach(isapnp_dev);
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
dev_err(dev->class_dev, "can't find board\n");
else if (device_id == 0)
dev_err(dev->class_dev,
"EEPROM read error (?) or device not found\n");
else
dev_err(dev->class_dev,
"unknown device ID %d -- contact author\n", device_id);
return -1;
}
static int ni_atmio_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct ni_board_struct *boardtype;
struct pnp_dev *isapnp_dev;
int ret;
unsigned long iobase;
int board;
unsigned int irq;
ret = ni_alloc_private(dev);
if (ret)
return ret;
iobase = it->options[0];
irq = it->options[1];
isapnp_dev = NULL;
if (iobase == 0) {
ret = ni_isapnp_find_board(&isapnp_dev);
if (ret < 0)
return ret;
iobase = pnp_port_start(isapnp_dev, 0);
irq = pnp_irq(isapnp_dev, 0);
comedi_set_hw_dev(dev, &isapnp_dev->dev);
}
ret = comedi_request_region(dev, iobase, 0x20);
if (ret)
return ret;
board = ni_getboardtype(dev);
if (board < 0)
return -EIO;
dev->board_ptr = ni_boards + board;
boardtype = dev->board_ptr;
dev->board_name = boardtype->name;
if (irq != 0) {
if (irq > 15 || ni_irqpin[irq] == -1)
return -EINVAL;
ret = request_irq(irq, ni_E_interrupt, 0,
dev->board_name, dev);
if (ret < 0)
return -EINVAL;
dev->irq = irq;
}
ret = ni_E_init(dev, ni_irqpin[dev->irq], 0);
if (ret < 0)
return ret;
return 0;
}
static void ni_atmio_detach(struct comedi_device *dev)
{
struct pnp_dev *isapnp_dev;
mio_common_detach(dev);
comedi_legacy_detach(dev);
isapnp_dev = dev->hw_dev ? to_pnp_dev(dev->hw_dev) : NULL;
if (isapnp_dev)
pnp_device_detach(isapnp_dev);
}
