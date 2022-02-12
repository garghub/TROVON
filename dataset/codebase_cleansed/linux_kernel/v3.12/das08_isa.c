static int das08_isa_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das08_board_struct *thisboard = comedi_board(dev);
struct das08_private_struct *devpriv;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], thisboard->iosize);
if (ret)
return ret;
return das08_common_attach(dev, dev->iobase);
}
