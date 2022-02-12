static int probe_st5481(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct st5481_adapter *adapter;
struct hisax_b_if *b_if[2];
int retval, i;
printk(KERN_INFO "st541: found adapter VendorId %04x, ProductId %04x, LEDs %d\n",
le16_to_cpu(dev->descriptor.idVendor),
le16_to_cpu(dev->descriptor.idProduct),
number_of_leds);
adapter = kzalloc(sizeof(struct st5481_adapter), GFP_KERNEL);
if (!adapter)
return -ENOMEM;
adapter->number_of_leds = number_of_leds;
adapter->usb_dev = dev;
adapter->hisax_d_if.owner = THIS_MODULE;
adapter->hisax_d_if.ifc.priv = adapter;
adapter->hisax_d_if.ifc.l2l1 = st5481_d_l2l1;
for (i = 0; i < 2; i++) {
adapter->bcs[i].adapter = adapter;
adapter->bcs[i].channel = i;
adapter->bcs[i].b_if.ifc.priv = &adapter->bcs[i];
adapter->bcs[i].b_if.ifc.l2l1 = st5481_b_l2l1;
}
retval = st5481_setup_usb(adapter);
if (retval < 0)
goto err;
retval = st5481_setup_d(adapter);
if (retval < 0)
goto err_usb;
retval = st5481_setup_b(&adapter->bcs[0]);
if (retval < 0)
goto err_d;
retval = st5481_setup_b(&adapter->bcs[1]);
if (retval < 0)
goto err_b;
for (i = 0; i < 2; i++)
b_if[i] = &adapter->bcs[i].b_if;
if (hisax_register(&adapter->hisax_d_if, b_if, "st5481_usb",
protocol) != 0)
goto err_b1;
st5481_start(adapter);
usb_set_intfdata(intf, adapter);
return 0;
err_b1:
st5481_release_b(&adapter->bcs[1]);
err_b:
st5481_release_b(&adapter->bcs[0]);
err_d:
st5481_release_d(adapter);
err_usb:
st5481_release_usb(adapter);
err:
kfree(adapter);
return -EIO;
}
static void disconnect_st5481(struct usb_interface *intf)
{
struct st5481_adapter *adapter = usb_get_intfdata(intf);
DBG(1,"");
usb_set_intfdata(intf, NULL);
if (!adapter)
return;
st5481_stop(adapter);
st5481_release_b(&adapter->bcs[1]);
st5481_release_b(&adapter->bcs[0]);
st5481_release_d(adapter);
mdelay(2);
st5481_release_usb(adapter);
hisax_unregister(&adapter->hisax_d_if);
kfree(adapter);
}
static int __init st5481_usb_init(void)
{
int retval;
#ifdef CONFIG_HISAX_DEBUG
st5481_debug = debug;
#endif
printk(KERN_INFO "hisax_st5481: ST5481 USB ISDN driver $Revision: 2.4.2.3 $\n");
retval = st5481_d_init();
if (retval < 0)
goto out;
retval = usb_register(&st5481_usb_driver);
if (retval < 0)
goto out_d_exit;
return 0;
out_d_exit:
st5481_d_exit();
out:
return retval;
}
static void __exit st5481_usb_exit(void)
{
usb_deregister(&st5481_usb_driver);
st5481_d_exit();
}
