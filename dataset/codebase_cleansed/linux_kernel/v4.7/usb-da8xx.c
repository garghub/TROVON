int __init da8xx_register_usb20(unsigned int mA, unsigned int potpgt)
{
usb_data.power = mA > 510 ? 255 : mA / 2;
usb_data.potpgt = (potpgt + 1) / 2;
return platform_device_register(&usb_dev);
}
int __init da8xx_register_usb20(unsigned int mA, unsigned int potpgt)
{
return 0;
}
int __init da8xx_register_usb11(struct da8xx_ohci_root_hub *pdata)
{
da8xx_usb11_device.dev.platform_data = pdata;
return platform_device_register(&da8xx_usb11_device);
}
