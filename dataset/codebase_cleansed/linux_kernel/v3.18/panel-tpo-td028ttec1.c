static int jbt_ret_write_0(struct panel_drv_data *ddata, u8 reg)
{
int rc;
u16 tx_buf = JBT_COMMAND | reg;
rc = spi_write(ddata->spi_dev, (u8 *)&tx_buf,
1*sizeof(u16));
if (rc != 0)
dev_err(&ddata->spi_dev->dev,
"jbt_ret_write_0 spi_write ret %d\n", rc);
return rc;
}
static int jbt_reg_write_1(struct panel_drv_data *ddata, u8 reg, u8 data)
{
int rc;
u16 tx_buf[2];
tx_buf[0] = JBT_COMMAND | reg;
tx_buf[1] = JBT_DATA | data;
rc = spi_write(ddata->spi_dev, (u8 *)tx_buf,
2*sizeof(u16));
if (rc != 0)
dev_err(&ddata->spi_dev->dev,
"jbt_reg_write_1 spi_write ret %d\n", rc);
return rc;
}
static int jbt_reg_write_2(struct panel_drv_data *ddata, u8 reg, u16 data)
{
int rc;
u16 tx_buf[3];
tx_buf[0] = JBT_COMMAND | reg;
tx_buf[1] = JBT_DATA | (data >> 8);
tx_buf[2] = JBT_DATA | (data & 0xff);
rc = spi_write(ddata->spi_dev, (u8 *)tx_buf,
3*sizeof(u16));
if (rc != 0)
dev_err(&ddata->spi_dev->dev,
"jbt_reg_write_2 spi_write ret %d\n", rc);
return rc;
}
static int td028ttec1_panel_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.dpi->connect(in, dssdev);
if (r)
return r;
return 0;
}
static void td028ttec1_panel_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.dpi->disconnect(in, dssdev);
}
static int td028ttec1_panel_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
if (ddata->data_lines)
in->ops.dpi->set_data_lines(in, ddata->data_lines);
in->ops.dpi->set_timings(in, &ddata->videomode);
r = in->ops.dpi->enable(in);
if (r)
return r;
dev_dbg(dssdev->dev, "td028ttec1_panel_enable() - state %d\n",
dssdev->state);
r |= jbt_ret_write_0(ddata, 0x00);
usleep_range(1000, 2000);
r |= jbt_ret_write_0(ddata, 0x00);
usleep_range(1000, 2000);
r |= jbt_ret_write_0(ddata, 0x00);
usleep_range(1000, 2000);
if (r) {
dev_warn(dssdev->dev, "transfer error\n");
goto transfer_err;
}
r |= jbt_reg_write_1(ddata, JBT_REG_POWER_ON_OFF, 0x17);
r |= jbt_reg_write_1(ddata, JBT_REG_DISPLAY_MODE, 0x80);
r |= jbt_reg_write_1(ddata, JBT_REG_QUAD_RATE, 0x00);
r |= jbt_reg_write_1(ddata, JBT_REG_POWER_ON_OFF, 0x16);
r |= jbt_reg_write_2(ddata, JBT_REG_OUTPUT_CONTROL, 0xfff9);
r |= jbt_ret_write_0(ddata, JBT_REG_SLEEP_OUT);
r |= jbt_reg_write_1(ddata, JBT_REG_DISPLAY_MODE1, 0x01);
r |= jbt_reg_write_1(ddata, JBT_REG_DISPLAY_MODE2, 0x00);
r |= jbt_reg_write_1(ddata, JBT_REG_RGB_FORMAT, 0x60);
r |= jbt_reg_write_1(ddata, JBT_REG_DRIVE_SYSTEM, 0x10);
r |= jbt_reg_write_1(ddata, JBT_REG_BOOSTER_OP, 0x56);
r |= jbt_reg_write_1(ddata, JBT_REG_BOOSTER_MODE, 0x33);
r |= jbt_reg_write_1(ddata, JBT_REG_BOOSTER_FREQ, 0x11);
r |= jbt_reg_write_1(ddata, JBT_REG_BOOSTER_FREQ, 0x11);
r |= jbt_reg_write_1(ddata, JBT_REG_OPAMP_SYSCLK, 0x02);
r |= jbt_reg_write_1(ddata, JBT_REG_VSC_VOLTAGE, 0x2b);
r |= jbt_reg_write_1(ddata, JBT_REG_VCOM_VOLTAGE, 0x40);
r |= jbt_reg_write_1(ddata, JBT_REG_EXT_DISPL, 0x03);
r |= jbt_reg_write_1(ddata, JBT_REG_DCCLK_DCEV, 0x04);
r |= jbt_reg_write_1(ddata, JBT_REG_ASW_SLEW, 0x04);
r |= jbt_reg_write_1(ddata, JBT_REG_DUMMY_DISPLAY, 0x00);
r |= jbt_reg_write_1(ddata, JBT_REG_SLEEP_OUT_FR_A, 0x11);
r |= jbt_reg_write_1(ddata, JBT_REG_SLEEP_OUT_FR_B, 0x11);
r |= jbt_reg_write_1(ddata, JBT_REG_SLEEP_OUT_FR_C, 0x11);
r |= jbt_reg_write_2(ddata, JBT_REG_SLEEP_IN_LCCNT_D, 0x2040);
r |= jbt_reg_write_2(ddata, JBT_REG_SLEEP_IN_LCCNT_E, 0x60c0);
r |= jbt_reg_write_2(ddata, JBT_REG_SLEEP_IN_LCCNT_F, 0x1020);
r |= jbt_reg_write_2(ddata, JBT_REG_SLEEP_IN_LCCNT_G, 0x60c0);
r |= jbt_reg_write_2(ddata, JBT_REG_GAMMA1_FINE_1, 0x5533);
r |= jbt_reg_write_1(ddata, JBT_REG_GAMMA1_FINE_2, 0x00);
r |= jbt_reg_write_1(ddata, JBT_REG_GAMMA1_INCLINATION, 0x00);
r |= jbt_reg_write_1(ddata, JBT_REG_GAMMA1_BLUE_OFFSET, 0x00);
r |= jbt_reg_write_2(ddata, JBT_REG_HCLOCK_VGA, 0x1f0);
r |= jbt_reg_write_1(ddata, JBT_REG_BLANK_CONTROL, 0x02);
r |= jbt_reg_write_2(ddata, JBT_REG_BLANK_TH_TV, 0x0804);
r |= jbt_reg_write_1(ddata, JBT_REG_CKV_ON_OFF, 0x01);
r |= jbt_reg_write_2(ddata, JBT_REG_CKV_1_2, 0x0000);
r |= jbt_reg_write_2(ddata, JBT_REG_OEV_TIMING, 0x0d0e);
r |= jbt_reg_write_2(ddata, JBT_REG_ASW_TIMING_1, 0x11a4);
r |= jbt_reg_write_1(ddata, JBT_REG_ASW_TIMING_2, 0x0e);
r |= jbt_ret_write_0(ddata, JBT_REG_DISPLAY_ON);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
transfer_err:
return r ? -EIO : 0;
}
static void td028ttec1_panel_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
dev_dbg(dssdev->dev, "td028ttec1_panel_disable()\n");
jbt_ret_write_0(ddata, JBT_REG_DISPLAY_OFF);
jbt_reg_write_2(ddata, JBT_REG_OUTPUT_CONTROL, 0x8002);
jbt_ret_write_0(ddata, JBT_REG_SLEEP_IN);
jbt_reg_write_1(ddata, JBT_REG_POWER_ON_OFF, 0x00);
in->ops.dpi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void td028ttec1_panel_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->videomode = *timings;
dssdev->panel.timings = *timings;
in->ops.dpi->set_timings(in, timings);
}
static void td028ttec1_panel_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->videomode;
}
static int td028ttec1_panel_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.dpi->check_timings(in, timings);
}
static int td028ttec1_panel_probe_pdata(struct spi_device *spi)
{
const struct panel_tpo_td028ttec1_platform_data *pdata;
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev, *in;
pdata = dev_get_platdata(&spi->dev);
in = omap_dss_find_output(pdata->source);
if (in == NULL) {
dev_err(&spi->dev, "failed to find video source '%s'\n",
pdata->source);
return -EPROBE_DEFER;
}
ddata->in = in;
ddata->data_lines = pdata->data_lines;
dssdev = &ddata->dssdev;
dssdev->name = pdata->name;
return 0;
}
static int td028ttec1_probe_of(struct spi_device *spi)
{
struct device_node *node = spi->dev.of_node;
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *in;
in = omapdss_of_find_source_for_first_ep(node);
if (IS_ERR(in)) {
dev_err(&spi->dev, "failed to find video source\n");
return PTR_ERR(in);
}
ddata->in = in;
return 0;
}
static int td028ttec1_panel_probe(struct spi_device *spi)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
dev_dbg(&spi->dev, "%s\n", __func__);
spi->bits_per_word = 9;
spi->mode = SPI_MODE_3;
r = spi_setup(spi);
if (r < 0) {
dev_err(&spi->dev, "spi_setup failed: %d\n", r);
return r;
}
ddata = devm_kzalloc(&spi->dev, sizeof(*ddata), GFP_KERNEL);
if (ddata == NULL)
return -ENOMEM;
dev_set_drvdata(&spi->dev, ddata);
ddata->spi_dev = spi;
if (dev_get_platdata(&spi->dev)) {
r = td028ttec1_panel_probe_pdata(spi);
if (r)
return r;
} else if (spi->dev.of_node) {
r = td028ttec1_probe_of(spi);
if (r)
return r;
} else {
return -ENODEV;
}
ddata->videomode = td028ttec1_panel_timings;
dssdev = &ddata->dssdev;
dssdev->dev = &spi->dev;
dssdev->driver = &td028ttec1_ops;
dssdev->type = OMAP_DISPLAY_TYPE_DPI;
dssdev->owner = THIS_MODULE;
dssdev->panel.timings = ddata->videomode;
dssdev->phy.dpi.data_lines = ddata->data_lines;
r = omapdss_register_display(dssdev);
if (r) {
dev_err(&spi->dev, "Failed to register panel\n");
goto err_reg;
}
return 0;
err_reg:
omap_dss_put_device(ddata->in);
return r;
}
static int td028ttec1_panel_remove(struct spi_device *spi)
{
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
dev_dbg(&ddata->spi_dev->dev, "%s\n", __func__);
omapdss_unregister_display(dssdev);
td028ttec1_panel_disable(dssdev);
td028ttec1_panel_disconnect(dssdev);
omap_dss_put_device(in);
return 0;
}
