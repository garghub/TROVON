static int __init msp_usb_setup(void)
{
char *strp;
char envstr[32];
struct platform_device *msp_devs[NUM_USB_DEVS];
unsigned int val;
snprintf((char *)&envstr[0], sizeof(envstr), "usbmode");
val = 1;
strp = prom_getenv((char *)&envstr[0]);
if (strp) {
if (!strcmp(strp, "device"))
val = 0;
}
if (val) {
#if defined(CONFIG_USB_EHCI_HCD)
msp_devs[0] = &msp_usbhost0_device.dev;
ppfinit("platform add USB HOST done %s.\n", msp_devs[0]->name);
#else
ppfinit("%s: echi_hcd not supported\n", __FILE__);
#endif
} else {
#if defined(CONFIG_USB_GADGET)
msp_devs[0] = &msp_usbdev0_device.dev;
ppfinit("platform add USB DEVICE done %s.\n"
, msp_devs[0]->name);
#else
ppfinit("%s: usb_gadget not supported\n", __FILE__);
#endif
}
platform_add_devices(msp_devs, ARRAY_SIZE(msp_devs));
return 0;
}
