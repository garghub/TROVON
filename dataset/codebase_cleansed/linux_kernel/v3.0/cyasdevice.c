static void cyasdevice_deinit(cyasdevice *cy_as_dev)
{
cy_as_hal_print_message("<1>_cy_as_device deinitialize called\n");
if (!cy_as_dev) {
cy_as_hal_print_message("<1>_cy_as_device_deinit: "
"device handle %x is invalid\n", (uint32_t)cy_as_dev);
return;
}
if (cy_as_dev->dev_handle) {
cy_as_hal_print_message("<1>_cy_as_device: "
"cy_as_misc_destroy_device called\n");
if (cy_as_misc_destroy_device(cy_as_dev->dev_handle) !=
CY_AS_ERROR_SUCCESS) {
cy_as_hal_print_message(
"<1>_cy_as_device: destroying failed\n");
}
}
if (cy_as_dev->hal_tag) {
#ifdef CONFIG_MACH_OMAP3_WESTBRIDGE_AST_PNAND_HAL
if (stop_o_m_a_p_kernel(dev_handle_name,
cy_as_dev->hal_tag) != 0)
cy_as_hal_print_message("<1>_cy_as_device: stopping "
"OMAP kernel HAL failed\n");
#endif
}
cy_as_hal_print_message("<1>_cy_as_device:HAL layer stopped\n");
kfree(cy_as_dev);
cy_as_device_controller = NULL;
cy_as_hal_print_message("<1>_cy_as_device: deinitialized\n");
}
static void cy_misc_callback(cy_as_device_handle h,
cy_as_misc_event_type evtype, void *evdata)
{
(void)h;
(void)evdata;
switch (evtype) {
case cy_as_event_misc_initialized:
cy_as_hal_print_message("<1>_cy_as_device: "
"initialization done callback triggered\n");
cy_as_device_init_done = 1;
break;
case cy_as_event_misc_awake:
cy_as_hal_print_message("<1>_cy_as_device: "
"cy_as_event_misc_awake event callback triggered\n");
cy_as_device_init_done = 1;
break;
default:
break;
}
}
void cy_as_acquire_common_lock()
{
spin_lock_irqsave(&cy_as_device_controller->common_lock,
cy_as_device_controller->flags);
}
void cy_as_release_common_lock()
{
spin_unlock_irqrestore(&cy_as_device_controller->common_lock,
cy_as_device_controller->flags);
}
void hal_reset(cy_as_hal_device_tag tag)
{
cy_as_hal_print_message("<1> send soft hard rst: "
"MEM_RST_CTRL_REG_HARD...\n");
cy_as_hal_write_register(tag, CY_AS_MEM_RST_CTRL_REG,
CY_AS_MEM_RST_CTRL_REG_HARD);
mdelay(60);
cy_as_hal_print_message("<1> after RST: si_rev_REG:%x, "
"PNANDCFG_reg:%x\n",
cy_as_hal_read_register(tag, CY_AS_MEM_CM_WB_CFG_ID),
cy_as_hal_read_register(tag, CY_AS_MEM_PNAND_CFG)
);
cy_as_hal_write_register(tag, CY_AS_MEM_PNAND_CFG,
PNAND_REG_CFG_INIT_VAL);
}
static int __devinit wb_probe(struct platform_device *devptr)
{
cy_as_hal_print_message("%s called\n", __func__);
return 0;
}
static int __devexit wb_remove(struct platform_device *devptr)
{
cy_as_hal_print_message("%s called\n", __func__);
return 0;
}
static int cyasdevice_initialize(void)
{
cyasdevice *cy_as_dev = 0;
int ret = 0;
int retval = 0;
cy_as_device_config config;
cy_as_hal_sleep_channel channel;
cy_as_get_firmware_version_data ver_data = {0};
const char *str = "";
int spin_lim;
const struct firmware *fw_entry;
cy_as_device_init_done = 0;
cy_as_misc_set_log_level(8);
cy_as_hal_print_message("<1>_cy_as_device initialize called\n");
if (cy_as_device_controller != 0) {
cy_as_hal_print_message("<1>_cy_as_device: the device "
"has already been initilaized. ignoring\n");
return -EBUSY;
}
cy_as_dev = cy_as_hal_alloc(sizeof(cyasdevice));
if (cy_as_dev == NULL) {
cy_as_hal_print_message("<1>_cy_as_device: "
"memory allocation failed\n");
return -ENOMEM;
}
memset(cy_as_dev, 0, sizeof(cyasdevice));
#ifdef CONFIG_MACH_OMAP3_WESTBRIDGE_AST_PNAND_HAL
if (!start_o_m_a_p_kernel(dev_handle_name,
&(cy_as_dev->hal_tag), cy_false)) {
cy_as_hal_print_message(
"<1>_cy_as_device: start OMAP34xx HAL failed\n");
goto done;
}
#endif
if (cy_as_misc_create_device(&(cy_as_dev->dev_handle),
cy_as_dev->hal_tag) != CY_AS_ERROR_SUCCESS) {
cy_as_hal_print_message(
"<1>_cy_as_device: create device failed\n");
goto done;
}
memset(&config, 0, sizeof(config));
config.dmaintr = cy_true;
ret = cy_as_misc_configure_device(cy_as_dev->dev_handle, &config);
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_hal_print_message(
"<1>_cy_as_device: configure device "
"failed. reason code: %d\n", ret);
goto done;
}
ret = cy_as_misc_register_callback(cy_as_dev->dev_handle,
cy_misc_callback);
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_hal_print_message("<1>_cy_as_device: "
"cy_as_misc_register_callback failed. "
"reason code: %d\n", ret);
goto done;
}
ret = platform_driver_register(&west_bridge_driver);
if (unlikely(ret < 0))
return ret;
westbridge_pd = platform_device_register_simple(
"west_bridge_dev", -1, NULL, 0);
if (IS_ERR(westbridge_pd)) {
platform_driver_unregister(&west_bridge_driver);
return PTR_ERR(westbridge_pd);
}
ret = request_firmware(&fw_entry,
"west bridge fw", &westbridge_pd->dev);
if (ret) {
cy_as_hal_print_message("cy_as_device: "
"request_firmware failed return val = %d\n", ret);
} else {
cy_as_hal_print_message("cy_as_device: "
"got the firmware %d size=0x%x\n", ret, fw_entry->size);
ret = cy_as_misc_download_firmware(
cy_as_dev->dev_handle,
fw_entry->data,
fw_entry->size ,
0, 0);
}
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_hal_print_message("<1>_cy_as_device: cannot download "
"firmware. reason code: %d\n", ret);
goto done;
}
spin_lim = 50;
cy_as_hal_create_sleep_channel(&channel);
while (!cy_as_device_init_done) {
cy_as_hal_sleep_on(&channel, 100);
if (spin_lim-- <= 0) {
cy_as_hal_print_message(
"<1>\n_e_r_r_o_r!: "
"wait for FW init has timed out !!!");
break;
}
}
cy_as_hal_destroy_sleep_channel(&channel);
if (spin_lim > 0)
cy_as_hal_print_message(
"cy_as_device: astoria firmware is loaded\n");
ret = cy_as_misc_get_firmware_version(cy_as_dev->dev_handle,
&ver_data, 0, 0);
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_hal_print_message("<1>_cy_as_device: cannot get firmware "
"version. reason code: %d\n", ret);
goto done;
}
if ((ver_data.media_type & 0x01) && (ver_data.media_type & 0x06))
str = "nand and SD/MMC.";
else if ((ver_data.media_type & 0x01) && (ver_data.media_type & 0x08))
str = "nand and CEATA.";
else if (ver_data.media_type & 0x01)
str = "nand.";
else if (ver_data.media_type & 0x08)
str = "CEATA.";
else
str = "SD/MMC.";
cy_as_hal_print_message("<1> cy_as_device:_firmware version: %s "
"major=%d minor=%d build=%d,\n_media types supported:%s\n",
((ver_data.is_debug_mode) ? "debug" : "release"),
ver_data.major, ver_data.minor, ver_data.build, str);
spin_lock_init(&cy_as_dev->common_lock);
cy_as_device_controller = cy_as_dev;
return 0;
done:
if (cy_as_dev)
cyasdevice_deinit(cy_as_dev);
return -EINVAL;
}
cy_as_device_handle cyasdevice_getdevhandle(void)
{
if (cy_as_device_controller) {
#ifdef CONFIG_MACH_OMAP3_WESTBRIDGE_AST_PNAND_HAL
cy_as_hal_config_c_s_mux();
#endif
return cy_as_device_controller->dev_handle;
}
return NULL;
}
cy_as_hal_device_tag cyasdevice_gethaltag(void)
{
if (cy_as_device_controller)
return (cy_as_hal_device_tag)
cy_as_device_controller->hal_tag;
return NULL;
}
static int __init cyasdevice_init(void)
{
if (cyasdevice_initialize() != 0)
return -ENODEV;
return 0;
}
static void __exit cyasdevice_cleanup(void)
{
cyasdevice_deinit(cy_as_device_controller);
}
