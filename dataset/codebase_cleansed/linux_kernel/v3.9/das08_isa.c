static int das08_isa_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das08_board_struct *thisboard = comedi_board(dev);
struct das08_private_struct *devpriv;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
if (!request_region(it->options[0], thisboard->iosize,
thisboard->name))
return -EIO;
return das08_common_attach(dev, it->options[0]);
}
static void das08_isa_detach(struct comedi_device *dev)
{
const struct das08_board_struct *thisboard = comedi_board(dev);
das08_common_detach(dev);
if (dev->iobase)
release_region(dev->iobase, thisboard->iosize);
}
