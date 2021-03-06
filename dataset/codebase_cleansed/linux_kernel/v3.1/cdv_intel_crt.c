static void cdv_intel_crt_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
u32 temp, reg;
reg = ADPA;
temp = REG_READ(reg);
temp &= ~(ADPA_HSYNC_CNTL_DISABLE | ADPA_VSYNC_CNTL_DISABLE);
temp &= ~ADPA_DAC_ENABLE;
switch (mode) {
case DRM_MODE_DPMS_ON:
temp |= ADPA_DAC_ENABLE;
break;
case DRM_MODE_DPMS_STANDBY:
temp |= ADPA_DAC_ENABLE | ADPA_HSYNC_CNTL_DISABLE;
break;
case DRM_MODE_DPMS_SUSPEND:
temp |= ADPA_DAC_ENABLE | ADPA_VSYNC_CNTL_DISABLE;
break;
case DRM_MODE_DPMS_OFF:
temp |= ADPA_HSYNC_CNTL_DISABLE | ADPA_VSYNC_CNTL_DISABLE;
break;
}
REG_WRITE(reg, temp);
}
static int cdv_intel_crt_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
int max_clock = 0;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
if (mode->clock < 20000)
return MODE_CLOCK_LOW;
max_clock = 355000;
if (mode->clock > max_clock)
return MODE_CLOCK_HIGH;
if (mode->hdisplay > 1680 || mode->vdisplay > 1050)
return MODE_PANEL;
return MODE_OK;
}
static bool cdv_intel_crt_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void cdv_intel_crt_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_crtc *crtc = encoder->crtc;
struct psb_intel_crtc *psb_intel_crtc =
to_psb_intel_crtc(crtc);
int dpll_md_reg;
u32 adpa, dpll_md;
u32 adpa_reg;
if (psb_intel_crtc->pipe == 0)
dpll_md_reg = DPLL_A_MD;
else
dpll_md_reg = DPLL_B_MD;
adpa_reg = ADPA;
{
dpll_md = REG_READ(dpll_md_reg);
REG_WRITE(dpll_md_reg,
dpll_md & ~DPLL_MD_UDI_MULTIPLIER_MASK);
}
adpa = 0;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
adpa |= ADPA_HSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
adpa |= ADPA_VSYNC_ACTIVE_HIGH;
if (psb_intel_crtc->pipe == 0)
adpa |= ADPA_PIPE_A_SELECT;
else
adpa |= ADPA_PIPE_B_SELECT;
REG_WRITE(adpa_reg, adpa);
}
static bool cdv_intel_crt_detect_hotplug(struct drm_connector *connector,
bool force)
{
struct drm_device *dev = connector->dev;
u32 hotplug_en;
int i, tries = 0, ret = false;
u32 adpa_orig;
adpa_orig = REG_READ(ADPA);
REG_WRITE(ADPA, adpa_orig & ~(ADPA_DAC_ENABLE));
tries = 2;
hotplug_en = REG_READ(PORT_HOTPLUG_EN);
hotplug_en &= ~(CRT_HOTPLUG_DETECT_MASK);
hotplug_en |= CRT_HOTPLUG_FORCE_DETECT;
hotplug_en |= CRT_HOTPLUG_ACTIVATION_PERIOD_64;
hotplug_en |= CRT_HOTPLUG_VOLTAGE_COMPARE_50;
for (i = 0; i < tries ; i++) {
unsigned long timeout;
REG_WRITE(PORT_HOTPLUG_EN, hotplug_en);
timeout = jiffies + msecs_to_jiffies(1000);
do {
if (!(REG_READ(PORT_HOTPLUG_EN) &
CRT_HOTPLUG_FORCE_DETECT))
break;
msleep(1);
} while (time_after(timeout, jiffies));
}
if ((REG_READ(PORT_HOTPLUG_STAT) & CRT_HOTPLUG_MONITOR_MASK) !=
CRT_HOTPLUG_MONITOR_NONE)
ret = true;
REG_WRITE(ADPA, adpa_orig);
return ret;
}
static enum drm_connector_status cdv_intel_crt_detect(
struct drm_connector *connector, bool force)
{
if (cdv_intel_crt_detect_hotplug(connector, force))
return connector_status_connected;
else
return connector_status_disconnected;
}
static void cdv_intel_crt_destroy(struct drm_connector *connector)
{
struct psb_intel_output *intel_output = to_psb_intel_output(connector);
psb_intel_i2c_destroy(intel_output->ddc_bus);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int cdv_intel_crt_get_modes(struct drm_connector *connector)
{
struct psb_intel_output *intel_output =
to_psb_intel_output(connector);
return psb_intel_ddc_get_modes(intel_output);
}
static int cdv_intel_crt_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
return 0;
}
static void cdv_intel_crt_enc_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
void cdv_intel_crt_init(struct drm_device *dev,
struct psb_intel_mode_device *mode_dev)
{
struct psb_intel_output *psb_intel_output;
struct drm_connector *connector;
struct drm_encoder *encoder;
u32 i2c_reg;
psb_intel_output = kzalloc(sizeof(struct psb_intel_output), GFP_KERNEL);
if (!psb_intel_output)
return;
psb_intel_output->mode_dev = mode_dev;
connector = &psb_intel_output->base;
drm_connector_init(dev, connector,
&cdv_intel_crt_connector_funcs, DRM_MODE_CONNECTOR_VGA);
encoder = &psb_intel_output->enc;
drm_encoder_init(dev, encoder,
&cdv_intel_crt_enc_funcs, DRM_MODE_ENCODER_DAC);
drm_mode_connector_attach_encoder(&psb_intel_output->base,
&psb_intel_output->enc);
i2c_reg = GPIOA;
psb_intel_output->ddc_bus = psb_intel_i2c_create(dev,
i2c_reg, "CRTDDC_A");
if (!psb_intel_output->ddc_bus) {
dev_printk(KERN_ERR, &dev->pdev->dev, "DDC bus registration "
"failed.\n");
goto failed_ddc;
}
psb_intel_output->type = INTEL_OUTPUT_ANALOG;
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
drm_encoder_helper_add(encoder, &cdv_intel_crt_helper_funcs);
drm_connector_helper_add(connector,
&cdv_intel_crt_connector_helper_funcs);
drm_sysfs_connector_add(connector);
return;
failed_ddc:
drm_encoder_cleanup(&psb_intel_output->enc);
drm_connector_cleanup(&psb_intel_output->base);
kfree(psb_intel_output);
return;
}
