static void sdi_config_lcd_manager(struct omap_dss_device *dssdev)
{
sdi.mgr_config.io_pad_mode = DSS_IO_PAD_MODE_BYPASS;
sdi.mgr_config.stallmode = false;
sdi.mgr_config.fifohandcheck = false;
sdi.mgr_config.video_port_width = 24;
sdi.mgr_config.lcden_sig_polarity = 1;
dss_mgr_set_lcd_config(dssdev->manager, &sdi.mgr_config);
}
int omapdss_sdi_display_enable(struct omap_dss_device *dssdev)
{
struct omap_video_timings *t = &dssdev->panel.timings;
struct dss_clock_info dss_cinfo;
struct dispc_clock_info dispc_cinfo;
unsigned long pck;
int r;
if (dssdev->manager == NULL) {
DSSERR("failed to enable display: no manager\n");
return -ENODEV;
}
r = omap_dss_start_device(dssdev);
if (r) {
DSSERR("failed to start device\n");
goto err_start_dev;
}
r = regulator_enable(sdi.vdds_sdi_reg);
if (r)
goto err_reg_enable;
r = dispc_runtime_get();
if (r)
goto err_get_dispc;
dssdev->panel.timings.data_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
dssdev->panel.timings.sync_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
r = dss_calc_clock_div(t->pixel_clock * 1000, &dss_cinfo, &dispc_cinfo);
if (r)
goto err_calc_clock_div;
sdi.mgr_config.clock_info = dispc_cinfo;
pck = dss_cinfo.fck / dispc_cinfo.lck_div / dispc_cinfo.pck_div / 1000;
if (pck != t->pixel_clock) {
DSSWARN("Could not find exact pixel clock. Requested %d kHz, "
"got %lu kHz\n",
t->pixel_clock, pck);
t->pixel_clock = pck;
}
dss_mgr_set_timings(dssdev->manager, t);
r = dss_set_clock_div(&dss_cinfo);
if (r)
goto err_set_dss_clock_div;
sdi_config_lcd_manager(dssdev);
dispc_mgr_set_clock_div(dssdev->manager->id,
&sdi.mgr_config.clock_info);
dss_sdi_init(dssdev->phy.sdi.datapairs);
r = dss_sdi_enable();
if (r)
goto err_sdi_enable;
mdelay(2);
r = dss_mgr_enable(dssdev->manager);
if (r)
goto err_mgr_enable;
return 0;
err_mgr_enable:
dss_sdi_disable();
err_sdi_enable:
err_set_dss_clock_div:
err_calc_clock_div:
dispc_runtime_put();
err_get_dispc:
regulator_disable(sdi.vdds_sdi_reg);
err_reg_enable:
omap_dss_stop_device(dssdev);
err_start_dev:
return r;
}
void omapdss_sdi_display_disable(struct omap_dss_device *dssdev)
{
dss_mgr_disable(dssdev->manager);
dss_sdi_disable();
dispc_runtime_put();
regulator_disable(sdi.vdds_sdi_reg);
omap_dss_stop_device(dssdev);
}
static int __init sdi_init_display(struct omap_dss_device *dssdev)
{
DSSDBG("SDI init\n");
if (sdi.vdds_sdi_reg == NULL) {
struct regulator *vdds_sdi;
vdds_sdi = dss_get_vdds_sdi();
if (IS_ERR(vdds_sdi)) {
DSSERR("can't get VDDS_SDI regulator\n");
return PTR_ERR(vdds_sdi);
}
sdi.vdds_sdi_reg = vdds_sdi;
}
return 0;
}
static void __init sdi_probe_pdata(struct platform_device *pdev)
{
struct omap_dss_board_info *pdata = pdev->dev.platform_data;
int i, r;
for (i = 0; i < pdata->num_devices; ++i) {
struct omap_dss_device *dssdev = pdata->devices[i];
if (dssdev->type != OMAP_DISPLAY_TYPE_SDI)
continue;
r = sdi_init_display(dssdev);
if (r) {
DSSERR("device %s init failed: %d\n", dssdev->name, r);
continue;
}
r = omap_dss_register_device(dssdev, &pdev->dev, i);
if (r)
DSSERR("device %s register failed: %d\n",
dssdev->name, r);
}
}
static int __init omap_sdi_probe(struct platform_device *pdev)
{
sdi_probe_pdata(pdev);
return 0;
}
static int __exit omap_sdi_remove(struct platform_device *pdev)
{
omap_dss_unregister_child_devices(&pdev->dev);
return 0;
}
int __init sdi_init_platform_driver(void)
{
return platform_driver_probe(&omap_sdi_driver, omap_sdi_probe);
}
void __exit sdi_uninit_platform_driver(void)
{
platform_driver_unregister(&omap_sdi_driver);
}
