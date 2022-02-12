struct usb_interface *comedi_to_usb_interface(struct comedi_device *dev)
{
return dev->hw_dev ? to_usb_interface(dev->hw_dev) : NULL;
}
int comedi_usb_auto_config(struct usb_interface *intf,
struct comedi_driver *driver,
unsigned long context)
{
return comedi_auto_config(&intf->dev, driver, context);
}
void comedi_usb_auto_unconfig(struct usb_interface *intf)
{
comedi_auto_unconfig(&intf->dev);
}
int comedi_usb_driver_register(struct comedi_driver *comedi_driver,
struct usb_driver *usb_driver)
{
int ret;
ret = comedi_driver_register(comedi_driver);
if (ret < 0)
return ret;
ret = usb_register(usb_driver);
if (ret < 0) {
comedi_driver_unregister(comedi_driver);
return ret;
}
return 0;
}
void comedi_usb_driver_unregister(struct comedi_driver *comedi_driver,
struct usb_driver *usb_driver)
{
usb_deregister(usb_driver);
comedi_driver_unregister(comedi_driver);
}
