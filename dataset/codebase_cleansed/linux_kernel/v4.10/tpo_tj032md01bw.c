static void tpohvga_onoff(struct mmp_panel *panel, int status)
{
struct tpohvga_plat_data *plat = panel->plat_data;
int ret;
if (status) {
plat->plat_onoff(1);
ret = spi_write(plat->spi, init, sizeof(init));
if (ret < 0)
dev_warn(panel->dev, "init cmd failed(%d)\n", ret);
} else {
ret = spi_write(plat->spi, poweroff, sizeof(poweroff));
if (ret < 0)
dev_warn(panel->dev, "poweroff cmd failed(%d)\n", ret);
plat->plat_onoff(0);
}
}
static int tpohvga_get_modelist(struct mmp_panel *panel,
struct mmp_mode **modelist)
{
*modelist = mmp_modes_tpohvga;
return 1;
}
static int tpohvga_probe(struct spi_device *spi)
{
struct mmp_mach_panel_info *mi;
int ret;
struct tpohvga_plat_data *plat_data;
mi = spi->dev.platform_data;
if (mi == NULL) {
dev_err(&spi->dev, "%s: no platform data defined\n", __func__);
return -EINVAL;
}
spi->bits_per_word = 16;
ret = spi_setup(spi);
if (ret < 0) {
dev_err(&spi->dev, "spi setup failed %d", ret);
return ret;
}
plat_data = kzalloc(sizeof(*plat_data), GFP_KERNEL);
if (plat_data == NULL)
return -ENOMEM;
plat_data->spi = spi;
plat_data->plat_onoff = mi->plat_set_onoff;
panel_tpohvga.plat_data = plat_data;
panel_tpohvga.plat_path_name = mi->plat_path_name;
panel_tpohvga.dev = &spi->dev;
mmp_register_panel(&panel_tpohvga);
return 0;
}
