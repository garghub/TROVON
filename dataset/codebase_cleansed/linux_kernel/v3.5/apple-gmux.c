static inline u8 gmux_read8(struct apple_gmux_data *gmux_data, int port)
{
return inb(gmux_data->iostart + port);
}
static inline void gmux_write8(struct apple_gmux_data *gmux_data, int port,
u8 val)
{
outb(val, gmux_data->iostart + port);
}
static inline u32 gmux_read32(struct apple_gmux_data *gmux_data, int port)
{
return inl(gmux_data->iostart + port);
}
static int gmux_get_brightness(struct backlight_device *bd)
{
struct apple_gmux_data *gmux_data = bl_get_data(bd);
return gmux_read32(gmux_data, GMUX_PORT_BRIGHTNESS) &
GMUX_BRIGHTNESS_MASK;
}
static int gmux_update_status(struct backlight_device *bd)
{
struct apple_gmux_data *gmux_data = bl_get_data(bd);
u32 brightness = bd->props.brightness;
if (bd->props.state & BL_CORE_SUSPENDED)
return 0;
gmux_write8(gmux_data, GMUX_PORT_BRIGHTNESS, brightness);
gmux_write8(gmux_data, GMUX_PORT_BRIGHTNESS + 1, brightness >> 8);
gmux_write8(gmux_data, GMUX_PORT_BRIGHTNESS + 2, brightness >> 16);
gmux_write8(gmux_data, GMUX_PORT_BRIGHTNESS + 3, 0);
return 0;
}
static int __devinit gmux_probe(struct pnp_dev *pnp,
const struct pnp_device_id *id)
{
struct apple_gmux_data *gmux_data;
struct resource *res;
struct backlight_properties props;
struct backlight_device *bdev;
u8 ver_major, ver_minor, ver_release;
int ret = -ENXIO;
gmux_data = kzalloc(sizeof(*gmux_data), GFP_KERNEL);
if (!gmux_data)
return -ENOMEM;
pnp_set_drvdata(pnp, gmux_data);
res = pnp_get_resource(pnp, IORESOURCE_IO, 0);
if (!res) {
pr_err("Failed to find gmux I/O resource\n");
goto err_free;
}
gmux_data->iostart = res->start;
gmux_data->iolen = res->end - res->start;
if (gmux_data->iolen < GMUX_MIN_IO_LEN) {
pr_err("gmux I/O region too small (%lu < %u)\n",
gmux_data->iolen, GMUX_MIN_IO_LEN);
goto err_free;
}
if (!request_region(gmux_data->iostart, gmux_data->iolen,
"Apple gmux")) {
pr_err("gmux I/O already in use\n");
goto err_free;
}
ver_major = gmux_read8(gmux_data, GMUX_PORT_VERSION_MAJOR);
ver_minor = gmux_read8(gmux_data, GMUX_PORT_VERSION_MINOR);
ver_release = gmux_read8(gmux_data, GMUX_PORT_VERSION_RELEASE);
if (ver_major == 0xff && ver_minor == 0xff && ver_release == 0xff) {
pr_info("gmux device not present\n");
ret = -ENODEV;
goto err_release;
}
pr_info("Found gmux version %d.%d.%d\n", ver_major, ver_minor,
ver_release);
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = gmux_read32(gmux_data, GMUX_PORT_MAX_BRIGHTNESS);
if (WARN_ON(props.max_brightness > GMUX_MAX_BRIGHTNESS))
props.max_brightness = GMUX_MAX_BRIGHTNESS;
bdev = backlight_device_register("gmux_backlight", &pnp->dev,
gmux_data, &gmux_bl_ops, &props);
if (IS_ERR(bdev)) {
ret = PTR_ERR(bdev);
goto err_release;
}
gmux_data->bdev = bdev;
bdev->props.brightness = gmux_get_brightness(bdev);
backlight_update_status(bdev);
acpi_video_unregister();
apple_bl_unregister();
return 0;
err_release:
release_region(gmux_data->iostart, gmux_data->iolen);
err_free:
kfree(gmux_data);
return ret;
}
static void __devexit gmux_remove(struct pnp_dev *pnp)
{
struct apple_gmux_data *gmux_data = pnp_get_drvdata(pnp);
backlight_device_unregister(gmux_data->bdev);
release_region(gmux_data->iostart, gmux_data->iolen);
kfree(gmux_data);
acpi_video_register();
apple_bl_register();
}
static int __init apple_gmux_init(void)
{
return pnp_register_driver(&gmux_pnp_driver);
}
static void __exit apple_gmux_exit(void)
{
pnp_unregister_driver(&gmux_pnp_driver);
}
