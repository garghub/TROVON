static int dio200_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv;
unsigned int irq;
int ret;
irq = it->options[1];
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_request_region(dev, it->options[0], thisboard->mainsize);
if (ret)
return ret;
devpriv->io.u.iobase = dev->iobase;
devpriv->io.regtype = io_regtype;
return amplc_dio200_common_attach(dev, irq, 0);
}
static void dio200_detach(struct comedi_device *dev)
{
amplc_dio200_common_detach(dev);
comedi_legacy_detach(dev);
}
