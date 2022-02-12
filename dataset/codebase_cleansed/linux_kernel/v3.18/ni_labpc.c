static int labpc_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct labpc_private *devpriv;
unsigned int irq = it->options[1];
unsigned int dma_chan = it->options[2];
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x20);
if (ret)
return ret;
ret = labpc_common_attach(dev, irq, 0);
if (ret)
return ret;
if (dev->irq)
labpc_init_dma_chan(dev, dma_chan);
return 0;
}
static void labpc_detach(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
if (devpriv)
labpc_free_dma_chan(dev);
comedi_legacy_detach(dev);
}
