static void sdi_basic_init(struct omap_dss_device *dssdev)
{
dispc_mgr_set_io_pad_mode(DSS_IO_PAD_MODE_BYPASS);
dispc_mgr_enable_stallmode(dssdev->manager->id, false);
dispc_mgr_set_lcd_display_type(dssdev->manager->id,
OMAP_DSS_LCD_DISPLAY_TFT);
dispc_mgr_set_tft_data_lines(dssdev->manager->id, 24);
dispc_lcd_enable_signal_polarity(1);
}
int omapdss_sdi_display_enable(struct omap_dss_device *dssdev)
{
struct omap_video_timings *t = &dssdev->panel.timings;
struct dss_clock_info dss_cinfo;
struct dispc_clock_info dispc_cinfo;
u16 lck_div, pck_div;
unsigned long fck;
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
r = dss_runtime_get();
if (r)
goto err_get_dss;
r = dispc_runtime_get();
if (r)
goto err_get_dispc;
sdi_basic_init(dssdev);
dssdev->panel.config |= OMAP_DSS_LCD_RF | OMAP_DSS_LCD_ONOFF;
dispc_mgr_set_pol_freq(dssdev->manager->id, dssdev->panel.config,
dssdev->panel.acbi, dssdev->panel.acb);
r = dss_calc_clock_div(1, t->pixel_clock * 1000,
&dss_cinfo, &dispc_cinfo);
if (r)
goto err_calc_clock_div;
fck = dss_cinfo.fck;
lck_div = dispc_cinfo.lck_div;
pck_div = dispc_cinfo.pck_div;
pck = fck / lck_div / pck_div / 1000;
if (pck != t->pixel_clock) {
DSSWARN("Could not find exact pixel clock. Requested %d kHz, "
"got %lu kHz\n",
t->pixel_clock, pck);
t->pixel_clock = pck;
}
dispc_mgr_set_lcd_timings(dssdev->manager->id, t);
r = dss_set_clock_div(&dss_cinfo);
if (r)
goto err_set_dss_clock_div;
r = dispc_mgr_set_clock_div(dssdev->manager->id, &dispc_cinfo);
if (r)
goto err_set_dispc_clock_div;
dss_sdi_init(dssdev->phy.sdi.datapairs);
r = dss_sdi_enable();
if (r)
goto err_sdi_enable;
mdelay(2);
dssdev->manager->enable(dssdev->manager);
return 0;
err_sdi_enable:
err_set_dispc_clock_div:
err_set_dss_clock_div:
err_calc_clock_div:
dispc_runtime_put();
err_get_dispc:
dss_runtime_put();
err_get_dss:
regulator_disable(sdi.vdds_sdi_reg);
err_reg_enable:
omap_dss_stop_device(dssdev);
err_start_dev:
return r;
}
void omapdss_sdi_display_disable(struct omap_dss_device *dssdev)
{
dssdev->manager->disable(dssdev->manager);
dss_sdi_disable();
dispc_runtime_put();
dss_runtime_put();
regulator_disable(sdi.vdds_sdi_reg);
omap_dss_stop_device(dssdev);
}
int sdi_init_display(struct omap_dss_device *dssdev)
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
int sdi_init(void)
{
return 0;
}
void sdi_exit(void)
{
}
