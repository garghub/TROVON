static int gfs_init(void)
{
ENTER();
return functionfs_init();
}
static void gfs_exit(void)
{
ENTER();
if (test_and_clear_bit(0, &gfs_registered))
usb_composite_unregister(&gfs_driver);
functionfs_cleanup();
}
static int functionfs_ready_callback(struct ffs_data *ffs)
{
int ret;
ENTER();
if (WARN_ON(test_and_set_bit(0, &gfs_registered)))
return -EBUSY;
gfs_ffs_data = ffs;
ret = usb_composite_probe(&gfs_driver, gfs_bind);
if (unlikely(ret < 0))
clear_bit(0, &gfs_registered);
return ret;
}
static void functionfs_closed_callback(struct ffs_data *ffs)
{
ENTER();
if (test_and_clear_bit(0, &gfs_registered))
usb_composite_unregister(&gfs_driver);
}
static int functionfs_check_dev_callback(const char *dev_name)
{
return 0;
}
static int gfs_bind(struct usb_composite_dev *cdev)
{
int ret, i;
ENTER();
if (WARN_ON(!gfs_ffs_data))
return -ENODEV;
ret = gether_setup(cdev->gadget, gfs_hostaddr);
if (unlikely(ret < 0))
goto error_quick;
ret = usb_string_ids_tab(cdev, gfs_strings);
if (unlikely(ret < 0))
goto error;
ret = functionfs_bind(gfs_ffs_data, cdev);
if (unlikely(ret < 0))
goto error;
for (i = 0; i < ARRAY_SIZE(gfs_configurations); ++i) {
struct gfs_configuration *c = gfs_configurations + i;
c->c.label = gfs_strings[i].s;
c->c.iConfiguration = gfs_strings[i].id;
c->c.bConfigurationValue = 1 + i;
c->c.bmAttributes = USB_CONFIG_ATT_SELFPOWER;
ret = usb_add_config(cdev, &c->c, gfs_do_config);
if (unlikely(ret < 0))
goto error_unbind;
}
return 0;
error_unbind:
functionfs_unbind(gfs_ffs_data);
error:
gether_cleanup();
error_quick:
gfs_ffs_data = NULL;
return ret;
}
static int gfs_unbind(struct usb_composite_dev *cdev)
{
ENTER();
if (gfs_ffs_data) {
gether_cleanup();
functionfs_unbind(gfs_ffs_data);
gfs_ffs_data = NULL;
}
return 0;
}
static int gfs_do_config(struct usb_configuration *c)
{
struct gfs_configuration *gc =
container_of(c, struct gfs_configuration, c);
int ret;
if (WARN_ON(!gfs_ffs_data))
return -ENODEV;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = gfs_otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
if (gc->eth) {
ret = gc->eth(c, gfs_hostaddr);
if (unlikely(ret < 0))
return ret;
}
ret = functionfs_bind_config(c->cdev, c, gfs_ffs_data);
if (unlikely(ret < 0))
return ret;
if (c->next_interface_id < ARRAY_SIZE(c->interface))
c->interface[c->next_interface_id] = NULL;
return 0;
}
static int eth_bind_config(struct usb_configuration *c, u8 ethaddr[ETH_ALEN])
{
return can_support_ecm(c->cdev->gadget)
? ecm_bind_config(c, ethaddr)
: geth_bind_config(c, ethaddr);
}
