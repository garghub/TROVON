static int pcl724_8255mapped_io(int dir, int port, int data,
unsigned long iobase)
{
int movport = SIZE_8255 * (iobase >> 12);
iobase &= 0x0fff;
if (dir) {
outb(port + movport, iobase);
outb(data, iobase + 1);
return 0;
} else {
outb(port + movport, iobase);
return inb(iobase + 1);
}
}
static int pcl724_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pcl724_board *board = comedi_board(dev);
struct comedi_subdevice *s;
unsigned long iobase;
unsigned int iorange;
int n_subdevices;
int ret;
int i;
iorange = board->io_range;
n_subdevices = board->numofports;
if (board->can_have96 &&
(it->options[2] == 1 || it->options[2] == 96)) {
iorange = 0x10;
n_subdevices = 4;
}
ret = comedi_request_region(dev, it->options[0], iorange);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, n_subdevices);
if (ret)
return ret;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
if (board->is_pet48) {
iobase = dev->iobase + (i * 0x1000);
ret = subdev_8255_init(dev, s, pcl724_8255mapped_io,
iobase);
} else {
iobase = dev->iobase + (i * SIZE_8255);
ret = subdev_8255_init(dev, s, NULL, iobase);
}
if (ret)
return ret;
}
return 0;
}
