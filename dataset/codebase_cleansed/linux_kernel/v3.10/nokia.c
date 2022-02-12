static int __init nokia_bind_config(struct usb_configuration *c)
{
struct usb_function *f_acm;
int status = 0;
status = phonet_bind_config(c);
if (status)
printk(KERN_DEBUG "could not bind phonet config\n");
status = obex_bind_config(c, tty_lines[TTY_PORT_OBEX0]);
if (status)
printk(KERN_DEBUG "could not bind obex config %d\n", 0);
status = obex_bind_config(c, tty_lines[TTY_PORT_OBEX1]);
if (status)
printk(KERN_DEBUG "could not bind obex config %d\n", 0);
f_acm = usb_get_function(fi_acm);
if (IS_ERR(f_acm))
return PTR_ERR(f_acm);
status = usb_add_function(c, f_acm);
if (status)
goto err_conf;
status = ecm_bind_config(c, hostaddr, the_dev);
if (status) {
pr_debug("could not bind ecm config %d\n", status);
goto err_ecm;
}
if (c == &nokia_config_500ma_driver)
f_acm_cfg1 = f_acm;
else
f_acm_cfg2 = f_acm;
return status;
err_ecm:
usb_remove_function(c, f_acm);
err_conf:
usb_put_function(f_acm);
return status;
}
static int __init nokia_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
int status;
int cur_line;
status = gphonet_setup(cdev->gadget);
if (status < 0)
goto err_phonet;
for (cur_line = 0; cur_line < TTY_PORTS_MAX; cur_line++) {
status = gserial_alloc_line(&tty_lines[cur_line]);
if (status)
goto err_ether;
}
the_dev = gether_setup(cdev->gadget, hostaddr);
if (IS_ERR(the_dev)) {
status = PTR_ERR(the_dev);
goto err_ether;
}
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto err_usb;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = strings_dev[STRING_DESCRIPTION_IDX].id;
nokia_config_500ma_driver.iConfiguration = status;
nokia_config_100ma_driver.iConfiguration = status;
if (!gadget_supports_altsettings(gadget))
goto err_usb;
fi_acm = usb_get_function_instance("acm");
if (IS_ERR(fi_acm))
goto err_usb;
status = usb_add_config(cdev, &nokia_config_500ma_driver,
nokia_bind_config);
if (status < 0)
goto err_acm_inst;
status = usb_add_config(cdev, &nokia_config_100ma_driver,
nokia_bind_config);
if (status < 0)
goto err_put_cfg1;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s\n", NOKIA_LONG_NAME);
return 0;
err_put_cfg1:
usb_put_function(f_acm_cfg1);
err_acm_inst:
usb_put_function_instance(fi_acm);
err_usb:
gether_cleanup(the_dev);
err_ether:
cur_line--;
while (cur_line >= 0)
gserial_free_line(tty_lines[cur_line--]);
gphonet_cleanup();
err_phonet:
return status;
}
static int __exit nokia_unbind(struct usb_composite_dev *cdev)
{
int i;
usb_put_function(f_acm_cfg1);
usb_put_function(f_acm_cfg2);
usb_put_function_instance(fi_acm);
gphonet_cleanup();
for (i = 0; i < TTY_PORTS_MAX; i++)
gserial_free_line(tty_lines[i]);
gether_cleanup(the_dev);
return 0;
}
static int __init nokia_init(void)
{
return usb_composite_probe(&nokia_driver);
}
static void __exit nokia_cleanup(void)
{
usb_composite_unregister(&nokia_driver);
}
