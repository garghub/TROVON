static int __init do_config(struct usb_configuration *c)
{
struct hidg_func_node *e;
int func = 0, status = 0;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
list_for_each_entry(e, &hidg_func_list, node) {
status = hidg_bind_config(c, e->func, func++);
if (status)
break;
}
return status;
}
static int __init hid_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
struct list_head *tmp;
int status, funcs = 0;
list_for_each(tmp, &hidg_func_list)
funcs++;
if (!funcs)
return -ENODEV;
status = ghid_setup(cdev->gadget, funcs);
if (status < 0)
return status;
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
return status;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = usb_add_config(cdev, &config_driver, do_config);
if (status < 0)
return status;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, DRIVER_DESC ", version: " DRIVER_VERSION "\n");
return 0;
}
static int __exit hid_unbind(struct usb_composite_dev *cdev)
{
ghid_cleanup();
return 0;
}
static int __init hidg_plat_driver_probe(struct platform_device *pdev)
{
struct hidg_func_descriptor *func = pdev->dev.platform_data;
struct hidg_func_node *entry;
if (!func) {
dev_err(&pdev->dev, "Platform data missing\n");
return -ENODEV;
}
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->func = func;
list_add_tail(&entry->node, &hidg_func_list);
return 0;
}
static int hidg_plat_driver_remove(struct platform_device *pdev)
{
struct hidg_func_node *e, *n;
list_for_each_entry_safe(e, n, &hidg_func_list, node) {
list_del(&e->node);
kfree(e);
}
return 0;
}
static int __init hidg_init(void)
{
int status;
status = platform_driver_probe(&hidg_plat_driver,
hidg_plat_driver_probe);
if (status < 0)
return status;
status = usb_composite_probe(&hidg_driver);
if (status < 0)
platform_driver_unregister(&hidg_plat_driver);
return status;
}
static void __exit hidg_cleanup(void)
{
platform_driver_unregister(&hidg_plat_driver);
usb_composite_unregister(&hidg_driver);
}
