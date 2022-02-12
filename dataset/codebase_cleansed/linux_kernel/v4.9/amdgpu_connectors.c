void amdgpu_connector_hotplug(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_connector->hpd.hpd == AMDGPU_HPD_NONE)
return;
amdgpu_display_hpd_set_polarity(adev, amdgpu_connector->hpd.hpd);
if (connector->dpms != DRM_MODE_DPMS_ON)
return;
if (connector->connector_type == DRM_MODE_CONNECTOR_DisplayPort) {
struct amdgpu_connector_atom_dig *dig_connector =
amdgpu_connector->con_priv;
if (dig_connector->dp_sink_type != CONNECTOR_OBJECT_ID_DISPLAYPORT)
return;
dig_connector->dp_sink_type = amdgpu_atombios_dp_get_sinktype(amdgpu_connector);
if (dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) {
int saved_dpms = connector->dpms;
if (!amdgpu_display_hpd_sense(adev, amdgpu_connector->hpd.hpd)) {
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_OFF);
} else if (amdgpu_atombios_dp_needs_link_train(amdgpu_connector)) {
if (amdgpu_atombios_dp_get_dpcd(amdgpu_connector))
return;
connector->dpms = DRM_MODE_DPMS_OFF;
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_ON);
}
connector->dpms = saved_dpms;
}
}
}
static void amdgpu_connector_property_change_mode(struct drm_encoder *encoder)
{
struct drm_crtc *crtc = encoder->crtc;
if (crtc && crtc->enabled) {
drm_crtc_helper_set_mode(crtc, &crtc->mode,
crtc->x, crtc->y, crtc->primary->fb);
}
}
int amdgpu_connector_get_monitor_bpc(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *dig_connector;
int bpc = 8;
unsigned mode_clock, max_tmds_clock;
switch (connector->connector_type) {
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_HDMIB:
if (amdgpu_connector->use_digital) {
if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector))) {
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
}
}
break;
case DRM_MODE_CONNECTOR_DVID:
case DRM_MODE_CONNECTOR_HDMIA:
if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector))) {
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
}
break;
case DRM_MODE_CONNECTOR_DisplayPort:
dig_connector = amdgpu_connector->con_priv;
if ((dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) ||
(dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_eDP) ||
drm_detect_hdmi_monitor(amdgpu_connector_edid(connector))) {
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
}
break;
case DRM_MODE_CONNECTOR_eDP:
case DRM_MODE_CONNECTOR_LVDS:
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
else {
const struct drm_connector_helper_funcs *connector_funcs =
connector->helper_private;
struct drm_encoder *encoder = connector_funcs->best_encoder(connector);
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct amdgpu_encoder_atom_dig *dig = amdgpu_encoder->enc_priv;
if (dig->lcd_misc & ATOM_PANEL_MISC_V13_6BIT_PER_COLOR)
bpc = 6;
else if (dig->lcd_misc & ATOM_PANEL_MISC_V13_8BIT_PER_COLOR)
bpc = 8;
}
break;
}
if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector))) {
if (bpc > 12) {
DRM_DEBUG("%s: HDMI deep color %d bpc unsupported. Using 12 bpc.\n",
connector->name, bpc);
bpc = 12;
}
if (connector->display_info.max_tmds_clock > 0) {
mode_clock = amdgpu_connector->pixelclock_for_modeset;
max_tmds_clock = connector->display_info.max_tmds_clock;
DRM_DEBUG("%s: hdmi mode dotclock %d kHz, max tmds input clock %d kHz.\n",
connector->name, mode_clock, max_tmds_clock);
if ((bpc == 12) && (mode_clock * 3/2 > max_tmds_clock)) {
if ((connector->display_info.edid_hdmi_dc_modes & DRM_EDID_HDMI_DC_30) &&
(mode_clock * 5/4 <= max_tmds_clock))
bpc = 10;
else
bpc = 8;
DRM_DEBUG("%s: HDMI deep color 12 bpc exceeds max tmds clock. Using %d bpc.\n",
connector->name, bpc);
}
if ((bpc == 10) && (mode_clock * 5/4 > max_tmds_clock)) {
bpc = 8;
DRM_DEBUG("%s: HDMI deep color 10 bpc exceeds max tmds clock. Using %d bpc.\n",
connector->name, bpc);
}
} else if (bpc > 8) {
DRM_DEBUG("%s: Required max tmds clock for HDMI deep color missing. Using 8 bpc.\n",
connector->name);
bpc = 8;
}
}
if ((amdgpu_deep_color == 0) && (bpc > 8)) {
DRM_DEBUG("%s: Deep color disabled. Set amdgpu module param deep_color=1 to enable.\n",
connector->name);
bpc = 8;
}
DRM_DEBUG("%s: Display bpc=%d, returned bpc=%d\n",
connector->name, connector->display_info.bpc, bpc);
return bpc;
}
static void
amdgpu_connector_update_scratch_regs(struct drm_connector *connector,
enum drm_connector_status status)
{
struct drm_encoder *best_encoder = NULL;
struct drm_encoder *encoder = NULL;
const struct drm_connector_helper_funcs *connector_funcs = connector->helper_private;
bool connected;
int i;
best_encoder = connector_funcs->best_encoder(connector);
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev,
connector->encoder_ids[i]);
if (!encoder)
continue;
if ((encoder == best_encoder) && (status == connector_status_connected))
connected = true;
else
connected = false;
amdgpu_atombios_encoder_set_bios_scratch_regs(connector, encoder, connected);
}
}
static struct drm_encoder *
amdgpu_connector_find_encoder(struct drm_connector *connector,
int encoder_type)
{
struct drm_encoder *encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev,
connector->encoder_ids[i]);
if (!encoder)
continue;
if (encoder->encoder_type == encoder_type)
return encoder;
}
return NULL;
}
struct edid *amdgpu_connector_edid(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct drm_property_blob *edid_blob = connector->edid_blob_ptr;
if (amdgpu_connector->edid) {
return amdgpu_connector->edid;
} else if (edid_blob) {
struct edid *edid = kmemdup(edid_blob->data, edid_blob->length, GFP_KERNEL);
if (edid)
amdgpu_connector->edid = edid;
}
return amdgpu_connector->edid;
}
static struct edid *
amdgpu_connector_get_hardcoded_edid(struct amdgpu_device *adev)
{
struct edid *edid;
if (adev->mode_info.bios_hardcoded_edid) {
edid = kmalloc(adev->mode_info.bios_hardcoded_edid_size, GFP_KERNEL);
if (edid) {
memcpy((unsigned char *)edid,
(unsigned char *)adev->mode_info.bios_hardcoded_edid,
adev->mode_info.bios_hardcoded_edid_size);
return edid;
}
}
return NULL;
}
static void amdgpu_connector_get_edid(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_connector->edid)
return;
if (amdgpu_connector->router.ddc_valid)
amdgpu_i2c_router_select_ddc_port(amdgpu_connector);
if ((amdgpu_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) &&
amdgpu_connector->ddc_bus->has_aux) {
amdgpu_connector->edid = drm_get_edid(connector,
&amdgpu_connector->ddc_bus->aux.ddc);
} else if ((connector->connector_type == DRM_MODE_CONNECTOR_DisplayPort) ||
(connector->connector_type == DRM_MODE_CONNECTOR_eDP)) {
struct amdgpu_connector_atom_dig *dig = amdgpu_connector->con_priv;
if ((dig->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT ||
dig->dp_sink_type == CONNECTOR_OBJECT_ID_eDP) &&
amdgpu_connector->ddc_bus->has_aux)
amdgpu_connector->edid = drm_get_edid(connector,
&amdgpu_connector->ddc_bus->aux.ddc);
else if (amdgpu_connector->ddc_bus)
amdgpu_connector->edid = drm_get_edid(connector,
&amdgpu_connector->ddc_bus->adapter);
} else if (amdgpu_connector->ddc_bus) {
amdgpu_connector->edid = drm_get_edid(connector,
&amdgpu_connector->ddc_bus->adapter);
}
if (!amdgpu_connector->edid) {
if (((connector->connector_type == DRM_MODE_CONNECTOR_LVDS) ||
(connector->connector_type == DRM_MODE_CONNECTOR_eDP)))
amdgpu_connector->edid = amdgpu_connector_get_hardcoded_edid(adev);
}
}
static void amdgpu_connector_free_edid(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_connector->edid) {
kfree(amdgpu_connector->edid);
amdgpu_connector->edid = NULL;
}
}
static int amdgpu_connector_ddc_get_modes(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
int ret;
if (amdgpu_connector->edid) {
drm_mode_connector_update_edid_property(connector, amdgpu_connector->edid);
ret = drm_add_edid_modes(connector, amdgpu_connector->edid);
drm_edid_to_eld(connector, amdgpu_connector->edid);
return ret;
}
drm_mode_connector_update_edid_property(connector, NULL);
return 0;
}
static struct drm_encoder *
amdgpu_connector_best_single_encoder(struct drm_connector *connector)
{
int enc_id = connector->encoder_ids[0];
if (enc_id)
return drm_encoder_find(connector->dev, enc_id);
return NULL;
}
static void amdgpu_get_native_mode(struct drm_connector *connector)
{
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
struct amdgpu_encoder *amdgpu_encoder;
if (encoder == NULL)
return;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (!list_empty(&connector->probed_modes)) {
struct drm_display_mode *preferred_mode =
list_first_entry(&connector->probed_modes,
struct drm_display_mode, head);
amdgpu_encoder->native_mode = *preferred_mode;
} else {
amdgpu_encoder->native_mode.clock = 0;
}
}
static struct drm_display_mode *
amdgpu_connector_lcd_native_mode(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *mode = NULL;
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
if (native_mode->hdisplay != 0 &&
native_mode->vdisplay != 0 &&
native_mode->clock != 0) {
mode = drm_mode_duplicate(dev, native_mode);
mode->type = DRM_MODE_TYPE_PREFERRED | DRM_MODE_TYPE_DRIVER;
drm_mode_set_name(mode);
DRM_DEBUG_KMS("Adding native panel mode %s\n", mode->name);
} else if (native_mode->hdisplay != 0 &&
native_mode->vdisplay != 0) {
mode = drm_cvt_mode(dev, native_mode->hdisplay, native_mode->vdisplay, 60, true, false, false);
mode->type = DRM_MODE_TYPE_PREFERRED | DRM_MODE_TYPE_DRIVER;
DRM_DEBUG_KMS("Adding cvt approximation of native panel mode %s\n", mode->name);
}
return mode;
}
static void amdgpu_connector_add_common_modes(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct drm_device *dev = encoder->dev;
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *mode = NULL;
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
int i;
static const struct mode_size {
int w;
int h;
} common_modes[17] = {
{ 640, 480},
{ 720, 480},
{ 800, 600},
{ 848, 480},
{1024, 768},
{1152, 768},
{1280, 720},
{1280, 800},
{1280, 854},
{1280, 960},
{1280, 1024},
{1440, 900},
{1400, 1050},
{1680, 1050},
{1600, 1200},
{1920, 1080},
{1920, 1200}
};
for (i = 0; i < 17; i++) {
if (amdgpu_encoder->devices & (ATOM_DEVICE_TV_SUPPORT)) {
if (common_modes[i].w > 1024 ||
common_modes[i].h > 768)
continue;
}
if (amdgpu_encoder->devices & (ATOM_DEVICE_LCD_SUPPORT)) {
if (common_modes[i].w > native_mode->hdisplay ||
common_modes[i].h > native_mode->vdisplay ||
(common_modes[i].w == native_mode->hdisplay &&
common_modes[i].h == native_mode->vdisplay))
continue;
}
if (common_modes[i].w < 320 || common_modes[i].h < 200)
continue;
mode = drm_cvt_mode(dev, common_modes[i].w, common_modes[i].h, 60, false, false, false);
drm_mode_probed_add(connector, mode);
}
}
static int amdgpu_connector_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct drm_encoder *encoder;
struct amdgpu_encoder *amdgpu_encoder;
if (property == adev->mode_info.coherent_mode_property) {
struct amdgpu_encoder_atom_dig *dig;
bool new_coherent_mode;
encoder = amdgpu_connector_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (!amdgpu_encoder->enc_priv)
return 0;
dig = amdgpu_encoder->enc_priv;
new_coherent_mode = val ? true : false;
if (dig->coherent_mode != new_coherent_mode) {
dig->coherent_mode = new_coherent_mode;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
}
if (property == adev->mode_info.audio_property) {
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
encoder = amdgpu_connector_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_connector->audio != val) {
amdgpu_connector->audio = val;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
}
if (property == adev->mode_info.dither_property) {
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
encoder = amdgpu_connector_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_connector->dither != val) {
amdgpu_connector->dither = val;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
}
if (property == adev->mode_info.underscan_property) {
encoder = amdgpu_connector_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_encoder->underscan_type != val) {
amdgpu_encoder->underscan_type = val;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
}
if (property == adev->mode_info.underscan_hborder_property) {
encoder = amdgpu_connector_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_encoder->underscan_hborder != val) {
amdgpu_encoder->underscan_hborder = val;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
}
if (property == adev->mode_info.underscan_vborder_property) {
encoder = amdgpu_connector_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_encoder->underscan_vborder != val) {
amdgpu_encoder->underscan_vborder = val;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
}
if (property == adev->mode_info.load_detect_property) {
struct amdgpu_connector *amdgpu_connector =
to_amdgpu_connector(connector);
if (val == 0)
amdgpu_connector->dac_load_detect = false;
else
amdgpu_connector->dac_load_detect = true;
}
if (property == dev->mode_config.scaling_mode_property) {
enum amdgpu_rmx_type rmx_type;
if (connector->encoder) {
amdgpu_encoder = to_amdgpu_encoder(connector->encoder);
} else {
const struct drm_connector_helper_funcs *connector_funcs = connector->helper_private;
amdgpu_encoder = to_amdgpu_encoder(connector_funcs->best_encoder(connector));
}
switch (val) {
default:
case DRM_MODE_SCALE_NONE: rmx_type = RMX_OFF; break;
case DRM_MODE_SCALE_CENTER: rmx_type = RMX_CENTER; break;
case DRM_MODE_SCALE_ASPECT: rmx_type = RMX_ASPECT; break;
case DRM_MODE_SCALE_FULLSCREEN: rmx_type = RMX_FULL; break;
}
if (amdgpu_encoder->rmx_type == rmx_type)
return 0;
if ((rmx_type != DRM_MODE_SCALE_NONE) &&
(amdgpu_encoder->native_mode.clock == 0))
return 0;
amdgpu_encoder->rmx_type = rmx_type;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
}
return 0;
}
static void
amdgpu_connector_fixup_lcd_native_mode(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
struct drm_display_mode *t, *mode;
list_for_each_entry_safe(mode, t, &connector->probed_modes, head) {
if (mode->type & DRM_MODE_TYPE_PREFERRED) {
if (mode->hdisplay != native_mode->hdisplay ||
mode->vdisplay != native_mode->vdisplay)
memcpy(native_mode, mode, sizeof(*mode));
}
}
if (!native_mode->clock) {
list_for_each_entry_safe(mode, t, &connector->probed_modes, head) {
if (mode->hdisplay == native_mode->hdisplay &&
mode->vdisplay == native_mode->vdisplay) {
*native_mode = *mode;
drm_mode_set_crtcinfo(native_mode, CRTC_INTERLACE_HALVE_V);
DRM_DEBUG_KMS("Determined LVDS native mode details from EDID\n");
break;
}
}
}
if (!native_mode->clock) {
DRM_DEBUG_KMS("No LVDS native mode details, disabling RMX\n");
amdgpu_encoder->rmx_type = RMX_OFF;
}
}
static int amdgpu_connector_lvds_get_modes(struct drm_connector *connector)
{
struct drm_encoder *encoder;
int ret = 0;
struct drm_display_mode *mode;
amdgpu_connector_get_edid(connector);
ret = amdgpu_connector_ddc_get_modes(connector);
if (ret > 0) {
encoder = amdgpu_connector_best_single_encoder(connector);
if (encoder) {
amdgpu_connector_fixup_lcd_native_mode(encoder, connector);
amdgpu_connector_add_common_modes(encoder, connector);
}
return ret;
}
encoder = amdgpu_connector_best_single_encoder(connector);
if (!encoder)
return 0;
mode = amdgpu_connector_lcd_native_mode(encoder);
if (mode) {
ret = 1;
drm_mode_probed_add(connector, mode);
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
amdgpu_connector_add_common_modes(encoder, connector);
}
return ret;
}
static int amdgpu_connector_lvds_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
if ((mode->hdisplay < 320) || (mode->vdisplay < 240))
return MODE_PANEL;
if (encoder) {
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
if ((mode->hdisplay > native_mode->hdisplay) ||
(mode->vdisplay > native_mode->vdisplay))
return MODE_PANEL;
if (amdgpu_encoder->rmx_type == RMX_OFF) {
if ((mode->hdisplay != native_mode->hdisplay) ||
(mode->vdisplay != native_mode->vdisplay))
return MODE_PANEL;
}
}
return MODE_OK;
}
static enum drm_connector_status
amdgpu_connector_lvds_detect(struct drm_connector *connector, bool force)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
enum drm_connector_status ret = connector_status_disconnected;
int r;
r = pm_runtime_get_sync(connector->dev->dev);
if (r < 0)
return connector_status_disconnected;
if (encoder) {
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
if (native_mode->hdisplay >= 320 && native_mode->vdisplay >= 240)
ret = connector_status_connected;
}
amdgpu_connector_get_edid(connector);
if (amdgpu_connector->edid)
ret = connector_status_connected;
amdgpu_connector_update_scratch_regs(connector, ret);
pm_runtime_mark_last_busy(connector->dev->dev);
pm_runtime_put_autosuspend(connector->dev->dev);
return ret;
}
static void amdgpu_connector_unregister(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_connector->ddc_bus && amdgpu_connector->ddc_bus->has_aux) {
drm_dp_aux_unregister(&amdgpu_connector->ddc_bus->aux);
amdgpu_connector->ddc_bus->has_aux = false;
}
}
static void amdgpu_connector_destroy(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
amdgpu_connector_free_edid(connector);
kfree(amdgpu_connector->con_priv);
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int amdgpu_connector_set_lcd_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
struct drm_device *dev = connector->dev;
struct amdgpu_encoder *amdgpu_encoder;
enum amdgpu_rmx_type rmx_type;
DRM_DEBUG_KMS("\n");
if (property != dev->mode_config.scaling_mode_property)
return 0;
if (connector->encoder)
amdgpu_encoder = to_amdgpu_encoder(connector->encoder);
else {
const struct drm_connector_helper_funcs *connector_funcs = connector->helper_private;
amdgpu_encoder = to_amdgpu_encoder(connector_funcs->best_encoder(connector));
}
switch (value) {
case DRM_MODE_SCALE_NONE: rmx_type = RMX_OFF; break;
case DRM_MODE_SCALE_CENTER: rmx_type = RMX_CENTER; break;
case DRM_MODE_SCALE_ASPECT: rmx_type = RMX_ASPECT; break;
default:
case DRM_MODE_SCALE_FULLSCREEN: rmx_type = RMX_FULL; break;
}
if (amdgpu_encoder->rmx_type == rmx_type)
return 0;
amdgpu_encoder->rmx_type = rmx_type;
amdgpu_connector_property_change_mode(&amdgpu_encoder->base);
return 0;
}
static int amdgpu_connector_vga_get_modes(struct drm_connector *connector)
{
int ret;
amdgpu_connector_get_edid(connector);
ret = amdgpu_connector_ddc_get_modes(connector);
return ret;
}
static int amdgpu_connector_vga_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
if ((mode->clock / 10) > adev->clock.max_pixel_clock)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static enum drm_connector_status
amdgpu_connector_vga_detect(struct drm_connector *connector, bool force)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct drm_encoder *encoder;
const struct drm_encoder_helper_funcs *encoder_funcs;
bool dret = false;
enum drm_connector_status ret = connector_status_disconnected;
int r;
r = pm_runtime_get_sync(connector->dev->dev);
if (r < 0)
return connector_status_disconnected;
encoder = amdgpu_connector_best_single_encoder(connector);
if (!encoder)
ret = connector_status_disconnected;
if (amdgpu_connector->ddc_bus)
dret = amdgpu_ddc_probe(amdgpu_connector, false);
if (dret) {
amdgpu_connector->detected_by_load = false;
amdgpu_connector_free_edid(connector);
amdgpu_connector_get_edid(connector);
if (!amdgpu_connector->edid) {
DRM_ERROR("%s: probed a monitor but no|invalid EDID\n",
connector->name);
ret = connector_status_connected;
} else {
amdgpu_connector->use_digital =
!!(amdgpu_connector->edid->input & DRM_EDID_INPUT_DIGITAL);
if (amdgpu_connector->use_digital && amdgpu_connector->shared_ddc) {
amdgpu_connector_free_edid(connector);
ret = connector_status_disconnected;
} else {
ret = connector_status_connected;
}
}
} else {
if (!force) {
if (amdgpu_connector->detected_by_load)
ret = connector->status;
goto out;
}
if (amdgpu_connector->dac_load_detect && encoder) {
encoder_funcs = encoder->helper_private;
ret = encoder_funcs->detect(encoder, connector);
if (ret != connector_status_disconnected)
amdgpu_connector->detected_by_load = true;
}
}
amdgpu_connector_update_scratch_regs(connector, ret);
out:
pm_runtime_mark_last_busy(connector->dev->dev);
pm_runtime_put_autosuspend(connector->dev->dev);
return ret;
}
static bool
amdgpu_connector_check_hpd_status_unchanged(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
enum drm_connector_status status;
if (amdgpu_connector->hpd.hpd != AMDGPU_HPD_NONE) {
if (amdgpu_display_hpd_sense(adev, amdgpu_connector->hpd.hpd))
status = connector_status_connected;
else
status = connector_status_disconnected;
if (connector->status == status)
return true;
}
return false;
}
static enum drm_connector_status
amdgpu_connector_dvi_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct drm_encoder *encoder = NULL;
const struct drm_encoder_helper_funcs *encoder_funcs;
int i, r;
enum drm_connector_status ret = connector_status_disconnected;
bool dret = false, broken_edid = false;
r = pm_runtime_get_sync(connector->dev->dev);
if (r < 0)
return connector_status_disconnected;
if (!force && amdgpu_connector_check_hpd_status_unchanged(connector)) {
ret = connector->status;
goto exit;
}
if (amdgpu_connector->ddc_bus)
dret = amdgpu_ddc_probe(amdgpu_connector, false);
if (dret) {
amdgpu_connector->detected_by_load = false;
amdgpu_connector_free_edid(connector);
amdgpu_connector_get_edid(connector);
if (!amdgpu_connector->edid) {
DRM_ERROR("%s: probed a monitor but no|invalid EDID\n",
connector->name);
ret = connector_status_connected;
broken_edid = true;
} else {
amdgpu_connector->use_digital =
!!(amdgpu_connector->edid->input & DRM_EDID_INPUT_DIGITAL);
if ((!amdgpu_connector->use_digital) && amdgpu_connector->shared_ddc) {
amdgpu_connector_free_edid(connector);
ret = connector_status_disconnected;
} else {
ret = connector_status_connected;
}
if (amdgpu_connector->shared_ddc && (ret == connector_status_connected)) {
struct drm_connector *list_connector;
struct amdgpu_connector *list_amdgpu_connector;
list_for_each_entry(list_connector, &dev->mode_config.connector_list, head) {
if (connector == list_connector)
continue;
list_amdgpu_connector = to_amdgpu_connector(list_connector);
if (list_amdgpu_connector->shared_ddc &&
(list_amdgpu_connector->ddc_bus->rec.i2c_id ==
amdgpu_connector->ddc_bus->rec.i2c_id)) {
if (list_connector->connector_type != DRM_MODE_CONNECTOR_VGA) {
if (!amdgpu_display_hpd_sense(adev, amdgpu_connector->hpd.hpd)) {
amdgpu_connector_free_edid(connector);
ret = connector_status_disconnected;
}
}
}
}
}
}
}
if ((ret == connector_status_connected) && (amdgpu_connector->use_digital == true))
goto out;
if ((connector->connector_type == DRM_MODE_CONNECTOR_DVID) ||
(connector->connector_type == DRM_MODE_CONNECTOR_HDMIA))
goto out;
if (!force) {
if (amdgpu_connector->detected_by_load)
ret = connector->status;
goto out;
}
if (amdgpu_connector->dac_load_detect) {
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev, connector->encoder_ids[i]);
if (!encoder)
continue;
if (encoder->encoder_type != DRM_MODE_ENCODER_DAC &&
encoder->encoder_type != DRM_MODE_ENCODER_TVDAC)
continue;
encoder_funcs = encoder->helper_private;
if (encoder_funcs->detect) {
if (!broken_edid) {
if (ret != connector_status_connected) {
ret = encoder_funcs->detect(encoder, connector);
if (ret == connector_status_connected) {
amdgpu_connector->use_digital = false;
}
if (ret != connector_status_disconnected)
amdgpu_connector->detected_by_load = true;
}
} else {
enum drm_connector_status lret;
amdgpu_connector->use_digital = true;
lret = encoder_funcs->detect(encoder, connector);
DRM_DEBUG_KMS("load_detect %x returned: %x\n",encoder->encoder_type,lret);
if (lret == connector_status_connected)
amdgpu_connector->use_digital = false;
}
break;
}
}
}
out:
amdgpu_connector_update_scratch_regs(connector, ret);
exit:
pm_runtime_mark_last_busy(connector->dev->dev);
pm_runtime_put_autosuspend(connector->dev->dev);
return ret;
}
static struct drm_encoder *
amdgpu_connector_dvi_encoder(struct drm_connector *connector)
{
int enc_id = connector->encoder_ids[0];
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct drm_encoder *encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev, connector->encoder_ids[i]);
if (!encoder)
continue;
if (amdgpu_connector->use_digital == true) {
if (encoder->encoder_type == DRM_MODE_ENCODER_TMDS)
return encoder;
} else {
if (encoder->encoder_type == DRM_MODE_ENCODER_DAC ||
encoder->encoder_type == DRM_MODE_ENCODER_TVDAC)
return encoder;
}
}
if (enc_id)
return drm_encoder_find(connector->dev, enc_id);
return NULL;
}
static void amdgpu_connector_dvi_force(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
if (connector->force == DRM_FORCE_ON)
amdgpu_connector->use_digital = false;
if (connector->force == DRM_FORCE_ON_DIGITAL)
amdgpu_connector->use_digital = true;
}
static int amdgpu_connector_dvi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_connector->use_digital && (mode->clock > 165000)) {
if ((amdgpu_connector->connector_object_id == CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I) ||
(amdgpu_connector->connector_object_id == CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D) ||
(amdgpu_connector->connector_object_id == CONNECTOR_OBJECT_ID_HDMI_TYPE_B)) {
return MODE_OK;
} else if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector))) {
if (mode->clock > 340000)
return MODE_CLOCK_HIGH;
else
return MODE_OK;
} else {
return MODE_CLOCK_HIGH;
}
}
if ((mode->clock / 10) > adev->clock.max_pixel_clock)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static int amdgpu_connector_dp_get_modes(struct drm_connector *connector)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *amdgpu_dig_connector = amdgpu_connector->con_priv;
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
int ret;
if ((connector->connector_type == DRM_MODE_CONNECTOR_eDP) ||
(connector->connector_type == DRM_MODE_CONNECTOR_LVDS)) {
struct drm_display_mode *mode;
if (connector->connector_type == DRM_MODE_CONNECTOR_eDP) {
if (!amdgpu_dig_connector->edp_on)
amdgpu_atombios_encoder_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_ON);
amdgpu_connector_get_edid(connector);
ret = amdgpu_connector_ddc_get_modes(connector);
if (!amdgpu_dig_connector->edp_on)
amdgpu_atombios_encoder_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_OFF);
} else {
if (amdgpu_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) {
if (encoder)
amdgpu_atombios_encoder_setup_ext_encoder_ddc(encoder);
}
amdgpu_connector_get_edid(connector);
ret = amdgpu_connector_ddc_get_modes(connector);
}
if (ret > 0) {
if (encoder) {
amdgpu_connector_fixup_lcd_native_mode(encoder, connector);
amdgpu_connector_add_common_modes(encoder, connector);
}
return ret;
}
if (!encoder)
return 0;
mode = amdgpu_connector_lcd_native_mode(encoder);
if (mode) {
ret = 1;
drm_mode_probed_add(connector, mode);
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
amdgpu_connector_add_common_modes(encoder, connector);
}
} else {
if (amdgpu_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) {
if (encoder)
amdgpu_atombios_encoder_setup_ext_encoder_ddc(encoder);
}
amdgpu_connector_get_edid(connector);
ret = amdgpu_connector_ddc_get_modes(connector);
amdgpu_get_native_mode(connector);
}
return ret;
}
u16 amdgpu_connector_encoder_get_dp_bridge_encoder_id(struct drm_connector *connector)
{
struct drm_encoder *encoder;
struct amdgpu_encoder *amdgpu_encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev,
connector->encoder_ids[i]);
if (!encoder)
continue;
amdgpu_encoder = to_amdgpu_encoder(encoder);
switch (amdgpu_encoder->encoder_id) {
case ENCODER_OBJECT_ID_TRAVIS:
case ENCODER_OBJECT_ID_NUTMEG:
return amdgpu_encoder->encoder_id;
default:
break;
}
}
return ENCODER_OBJECT_ID_NONE;
}
static bool amdgpu_connector_encoder_is_hbr2(struct drm_connector *connector)
{
struct drm_encoder *encoder;
struct amdgpu_encoder *amdgpu_encoder;
int i;
bool found = false;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev,
connector->encoder_ids[i]);
if (!encoder)
continue;
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_encoder->caps & ATOM_ENCODER_CAP_RECORD_HBR2)
found = true;
}
return found;
}
bool amdgpu_connector_is_dp12_capable(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
if ((adev->clock.default_dispclk >= 53900) &&
amdgpu_connector_encoder_is_hbr2(connector)) {
return true;
}
return false;
}
static enum drm_connector_status
amdgpu_connector_dp_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
enum drm_connector_status ret = connector_status_disconnected;
struct amdgpu_connector_atom_dig *amdgpu_dig_connector = amdgpu_connector->con_priv;
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
int r;
r = pm_runtime_get_sync(connector->dev->dev);
if (r < 0)
return connector_status_disconnected;
if (!force && amdgpu_connector_check_hpd_status_unchanged(connector)) {
ret = connector->status;
goto out;
}
amdgpu_connector_free_edid(connector);
if ((connector->connector_type == DRM_MODE_CONNECTOR_eDP) ||
(connector->connector_type == DRM_MODE_CONNECTOR_LVDS)) {
if (encoder) {
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
if (native_mode->hdisplay >= 320 && native_mode->vdisplay >= 240)
ret = connector_status_connected;
}
amdgpu_dig_connector->dp_sink_type = CONNECTOR_OBJECT_ID_DISPLAYPORT;
if (!amdgpu_dig_connector->edp_on)
amdgpu_atombios_encoder_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_ON);
if (!amdgpu_atombios_dp_get_dpcd(amdgpu_connector))
ret = connector_status_connected;
if (!amdgpu_dig_connector->edp_on)
amdgpu_atombios_encoder_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_OFF);
} else if (amdgpu_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) {
amdgpu_dig_connector->dp_sink_type = CONNECTOR_OBJECT_ID_DISPLAYPORT;
amdgpu_atombios_dp_get_dpcd(amdgpu_connector);
if (encoder) {
amdgpu_atombios_encoder_setup_ext_encoder_ddc(encoder);
if (amdgpu_ddc_probe(amdgpu_connector, true))
ret = connector_status_connected;
else if (amdgpu_connector->dac_load_detect) {
const struct drm_encoder_helper_funcs *encoder_funcs = encoder->helper_private;
ret = encoder_funcs->detect(encoder, connector);
}
}
} else {
amdgpu_dig_connector->dp_sink_type =
amdgpu_atombios_dp_get_sinktype(amdgpu_connector);
if (amdgpu_display_hpd_sense(adev, amdgpu_connector->hpd.hpd)) {
ret = connector_status_connected;
if (amdgpu_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT)
amdgpu_atombios_dp_get_dpcd(amdgpu_connector);
} else {
if (amdgpu_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) {
if (!amdgpu_atombios_dp_get_dpcd(amdgpu_connector))
ret = connector_status_connected;
} else {
if (amdgpu_ddc_probe(amdgpu_connector, false))
ret = connector_status_connected;
}
}
}
amdgpu_connector_update_scratch_regs(connector, ret);
out:
pm_runtime_mark_last_busy(connector->dev->dev);
pm_runtime_put_autosuspend(connector->dev->dev);
return ret;
}
static int amdgpu_connector_dp_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct amdgpu_connector *amdgpu_connector = to_amdgpu_connector(connector);
struct amdgpu_connector_atom_dig *amdgpu_dig_connector = amdgpu_connector->con_priv;
if ((connector->connector_type == DRM_MODE_CONNECTOR_eDP) ||
(connector->connector_type == DRM_MODE_CONNECTOR_LVDS)) {
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
if ((mode->hdisplay < 320) || (mode->vdisplay < 240))
return MODE_PANEL;
if (encoder) {
struct amdgpu_encoder *amdgpu_encoder = to_amdgpu_encoder(encoder);
struct drm_display_mode *native_mode = &amdgpu_encoder->native_mode;
if ((mode->hdisplay > native_mode->hdisplay) ||
(mode->vdisplay > native_mode->vdisplay))
return MODE_PANEL;
if (amdgpu_encoder->rmx_type == RMX_OFF) {
if ((mode->hdisplay != native_mode->hdisplay) ||
(mode->vdisplay != native_mode->vdisplay))
return MODE_PANEL;
}
}
return MODE_OK;
} else {
if ((amdgpu_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) ||
(amdgpu_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_eDP)) {
return amdgpu_atombios_dp_mode_valid_helper(connector, mode);
} else {
if (drm_detect_hdmi_monitor(amdgpu_connector_edid(connector))) {
if (mode->clock > 340000)
return MODE_CLOCK_HIGH;
} else {
if (mode->clock > 165000)
return MODE_CLOCK_HIGH;
}
}
}
return MODE_OK;
}
static struct drm_encoder *
amdgpu_connector_virtual_encoder(struct drm_connector *connector)
{
int enc_id = connector->encoder_ids[0];
struct drm_encoder *encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
encoder = drm_encoder_find(connector->dev, connector->encoder_ids[i]);
if (!encoder)
continue;
if (encoder->encoder_type == DRM_MODE_ENCODER_VIRTUAL)
return encoder;
}
if (enc_id)
return drm_encoder_find(connector->dev, enc_id);
return NULL;
}
static int amdgpu_connector_virtual_get_modes(struct drm_connector *connector)
{
struct drm_encoder *encoder = amdgpu_connector_best_single_encoder(connector);
if (encoder) {
amdgpu_connector_add_common_modes(encoder, connector);
}
return 0;
}
static int amdgpu_connector_virtual_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static int
amdgpu_connector_virtual_dpms(struct drm_connector *connector, int mode)
{
return 0;
}
static enum drm_connector_status
amdgpu_connector_virtual_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static int
amdgpu_connector_virtual_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
return 0;
}
static void amdgpu_connector_virtual_force(struct drm_connector *connector)
{
return;
}
void
amdgpu_connector_add(struct amdgpu_device *adev,
uint32_t connector_id,
uint32_t supported_device,
int connector_type,
struct amdgpu_i2c_bus_rec *i2c_bus,
uint16_t connector_object_id,
struct amdgpu_hpd *hpd,
struct amdgpu_router *router)
{
struct drm_device *dev = adev->ddev;
struct drm_connector *connector;
struct amdgpu_connector *amdgpu_connector;
struct amdgpu_connector_atom_dig *amdgpu_dig_connector;
struct drm_encoder *encoder;
struct amdgpu_encoder *amdgpu_encoder;
uint32_t subpixel_order = SubPixelNone;
bool shared_ddc = false;
bool is_dp_bridge = false;
bool has_aux = false;
if (connector_type == DRM_MODE_CONNECTOR_Unknown)
return;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_connector->connector_id == connector_id) {
amdgpu_connector->devices |= supported_device;
return;
}
if (amdgpu_connector->ddc_bus && i2c_bus->valid) {
if (amdgpu_connector->ddc_bus->rec.i2c_id == i2c_bus->i2c_id) {
amdgpu_connector->shared_ddc = true;
shared_ddc = true;
}
if (amdgpu_connector->router_bus && router->ddc_valid &&
(amdgpu_connector->router.router_id == router->router_id)) {
amdgpu_connector->shared_ddc = false;
shared_ddc = false;
}
}
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
amdgpu_encoder = to_amdgpu_encoder(encoder);
if (amdgpu_encoder->devices & supported_device) {
switch (amdgpu_encoder->encoder_id) {
case ENCODER_OBJECT_ID_TRAVIS:
case ENCODER_OBJECT_ID_NUTMEG:
is_dp_bridge = true;
break;
default:
break;
}
}
}
amdgpu_connector = kzalloc(sizeof(struct amdgpu_connector), GFP_KERNEL);
if (!amdgpu_connector)
return;
connector = &amdgpu_connector->base;
amdgpu_connector->connector_id = connector_id;
amdgpu_connector->devices = supported_device;
amdgpu_connector->shared_ddc = shared_ddc;
amdgpu_connector->connector_object_id = connector_object_id;
amdgpu_connector->hpd = *hpd;
amdgpu_connector->router = *router;
if (router->ddc_valid || router->cd_valid) {
amdgpu_connector->router_bus = amdgpu_i2c_lookup(adev, &router->i2c_info);
if (!amdgpu_connector->router_bus)
DRM_ERROR("Failed to assign router i2c bus! Check dmesg for i2c errors.\n");
}
if (is_dp_bridge) {
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (amdgpu_connector->ddc_bus)
has_aux = true;
else
DRM_ERROR("DP: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
switch (connector_type) {
case DRM_MODE_CONNECTOR_VGA:
case DRM_MODE_CONNECTOR_DVIA:
default:
drm_connector_init(dev, &amdgpu_connector->base,
&amdgpu_connector_dp_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base,
&amdgpu_connector_dp_helper_funcs);
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
amdgpu_connector->dac_load_detect = true;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.load_detect_property,
1);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
case DRM_MODE_CONNECTOR_HDMIA:
case DRM_MODE_CONNECTOR_HDMIB:
case DRM_MODE_CONNECTOR_DisplayPort:
drm_connector_init(dev, &amdgpu_connector->base,
&amdgpu_connector_dp_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base,
&amdgpu_connector_dp_helper_funcs);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_vborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.dither_property,
AMDGPU_FMT_DITHER_DISABLE);
if (amdgpu_audio != 0)
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.audio_property,
AMDGPU_AUDIO_AUTO);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = true;
if (connector_type == DRM_MODE_CONNECTOR_HDMIB)
connector->doublescan_allowed = true;
else
connector->doublescan_allowed = false;
if (connector_type == DRM_MODE_CONNECTOR_DVII) {
amdgpu_connector->dac_load_detect = true;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.load_detect_property,
1);
}
break;
case DRM_MODE_CONNECTOR_LVDS:
case DRM_MODE_CONNECTOR_eDP:
drm_connector_init(dev, &amdgpu_connector->base,
&amdgpu_connector_edp_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base,
&amdgpu_connector_dp_helper_funcs);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
}
} else {
switch (connector_type) {
case DRM_MODE_CONNECTOR_VGA:
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_vga_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_vga_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (!amdgpu_connector->ddc_bus)
DRM_ERROR("VGA: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
amdgpu_connector->dac_load_detect = true;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.load_detect_property,
1);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
amdgpu_connector->hpd.hpd = AMDGPU_HPD_NONE;
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
break;
case DRM_MODE_CONNECTOR_DVIA:
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_vga_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_vga_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (!amdgpu_connector->ddc_bus)
DRM_ERROR("DVIA: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
amdgpu_connector->dac_load_detect = true;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.load_detect_property,
1);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
amdgpu_connector->hpd.hpd = AMDGPU_HPD_NONE;
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_dvi_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_dvi_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (!amdgpu_connector->ddc_bus)
DRM_ERROR("DVI: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
subpixel_order = SubPixelHorizontalRGB;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.coherent_mode_property,
1);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_vborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
if (amdgpu_audio != 0) {
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.audio_property,
AMDGPU_AUDIO_AUTO);
}
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.dither_property,
AMDGPU_FMT_DITHER_DISABLE);
if (connector_type == DRM_MODE_CONNECTOR_DVII) {
amdgpu_connector->dac_load_detect = true;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.load_detect_property,
1);
}
connector->interlace_allowed = true;
if (connector_type == DRM_MODE_CONNECTOR_DVII)
connector->doublescan_allowed = true;
else
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_HDMIA:
case DRM_MODE_CONNECTOR_HDMIB:
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_dvi_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_dvi_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (!amdgpu_connector->ddc_bus)
DRM_ERROR("HDMI: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.coherent_mode_property,
1);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_vborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
if (amdgpu_audio != 0) {
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.audio_property,
AMDGPU_AUDIO_AUTO);
}
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.dither_property,
AMDGPU_FMT_DITHER_DISABLE);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = true;
if (connector_type == DRM_MODE_CONNECTOR_HDMIB)
connector->doublescan_allowed = true;
else
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_DisplayPort:
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_dp_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_dp_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (amdgpu_connector->ddc_bus)
has_aux = true;
else
DRM_ERROR("DP: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
subpixel_order = SubPixelHorizontalRGB;
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.coherent_mode_property,
1);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.underscan_vborder_property,
0);
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_NONE);
if (amdgpu_audio != 0) {
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.audio_property,
AMDGPU_AUDIO_AUTO);
}
drm_object_attach_property(&amdgpu_connector->base.base,
adev->mode_info.dither_property,
AMDGPU_FMT_DITHER_DISABLE);
connector->interlace_allowed = true;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_eDP:
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_edp_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_dp_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (amdgpu_connector->ddc_bus)
has_aux = true;
else
DRM_ERROR("DP: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_LVDS:
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_lvds_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_lvds_helper_funcs);
if (i2c_bus->valid) {
amdgpu_connector->ddc_bus = amdgpu_i2c_lookup(adev, i2c_bus);
if (!amdgpu_connector->ddc_bus)
DRM_ERROR("LVDS: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&amdgpu_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_VIRTUAL:
amdgpu_dig_connector = kzalloc(sizeof(struct amdgpu_connector_atom_dig), GFP_KERNEL);
if (!amdgpu_dig_connector)
goto failed;
amdgpu_connector->con_priv = amdgpu_dig_connector;
drm_connector_init(dev, &amdgpu_connector->base, &amdgpu_connector_virtual_funcs, connector_type);
drm_connector_helper_add(&amdgpu_connector->base, &amdgpu_connector_virtual_helper_funcs);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
}
}
if (amdgpu_connector->hpd.hpd == AMDGPU_HPD_NONE) {
if (i2c_bus->valid) {
connector->polled = DRM_CONNECTOR_POLL_CONNECT |
DRM_CONNECTOR_POLL_DISCONNECT;
}
} else
connector->polled = DRM_CONNECTOR_POLL_HPD;
connector->display_info.subpixel_order = subpixel_order;
drm_connector_register(connector);
if (has_aux)
amdgpu_atombios_dp_aux_init(amdgpu_connector);
return;
failed:
drm_connector_cleanup(connector);
kfree(connector);
}
