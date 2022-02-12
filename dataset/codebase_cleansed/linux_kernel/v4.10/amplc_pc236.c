static int pc236_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pc236_private *devpriv;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x4);
if (ret)
return ret;
return amplc_pc236_common_attach(dev, dev->iobase, it->options[1], 0);
}
