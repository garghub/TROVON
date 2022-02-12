static int dio200_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
int ret;
ret = comedi_request_region(dev, it->options[0], 0x20);
if (ret)
return ret;
return amplc_dio200_common_attach(dev, it->options[1], 0);
}
