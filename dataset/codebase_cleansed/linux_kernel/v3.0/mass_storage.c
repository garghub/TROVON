static int msg_thread_exits(struct fsg_common *common)
{
msg_cleanup();
return 0;
}
static int __init msg_do_config(struct usb_configuration *c)
{
static const struct fsg_operations ops = {
.thread_exits = msg_thread_exits,
};
static struct fsg_common common;
struct fsg_common *retp;
struct fsg_config config;
int ret;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
fsg_config_from_params(&config, &mod_data);
config.ops = &ops;
retp = fsg_common_init(&common, c->cdev, &config);
if (IS_ERR(retp))
return PTR_ERR(retp);
ret = fsg_bind_config(c->cdev, c, &common);
fsg_common_put(&common);
return ret;
}
static int __init msg_bind(struct usb_composite_dev *cdev)
{
int status;
status = usb_add_config(cdev, &msg_config_driver, msg_do_config);
if (status < 0)
return status;
dev_info(&cdev->gadget->dev,
DRIVER_DESC ", version: " DRIVER_VERSION "\n");
set_bit(0, &msg_registered);
return 0;
}
static int __init msg_init(void)
{
return usb_composite_probe(&msg_driver, msg_bind);
}
static void msg_cleanup(void)
{
if (test_and_clear_bit(0, &msg_registered))
usb_composite_unregister(&msg_driver);
}
