void radeon_connector_hotplug(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
if (radeon_connector->hpd.hpd == RADEON_HPD_NONE)
return;
radeon_hpd_set_polarity(rdev, radeon_connector->hpd.hpd);
if (connector->dpms != DRM_MODE_DPMS_ON)
return;
if (connector->connector_type == DRM_MODE_CONNECTOR_DisplayPort) {
struct radeon_connector_atom_dig *dig_connector =
radeon_connector->con_priv;
if (dig_connector->dp_sink_type != CONNECTOR_OBJECT_ID_DISPLAYPORT)
return;
dig_connector->dp_sink_type = radeon_dp_getsinktype(radeon_connector);
if (dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) {
int saved_dpms = connector->dpms;
if (!radeon_hpd_sense(rdev, radeon_connector->hpd.hpd)) {
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_OFF);
} else if (radeon_dp_needs_link_train(radeon_connector)) {
connector->dpms = DRM_MODE_DPMS_OFF;
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_ON);
}
connector->dpms = saved_dpms;
}
}
}
static void radeon_property_change_mode(struct drm_encoder *encoder)
{
struct drm_crtc *crtc = encoder->crtc;
if (crtc && crtc->enabled) {
drm_crtc_helper_set_mode(crtc, &crtc->mode,
crtc->x, crtc->y, crtc->fb);
}
}
int radeon_get_monitor_bpc(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct radeon_connector_atom_dig *dig_connector;
int bpc = 8;
switch (connector->connector_type) {
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_HDMIB:
if (radeon_connector->use_digital) {
if (drm_detect_hdmi_monitor(radeon_connector->edid)) {
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
}
}
break;
case DRM_MODE_CONNECTOR_DVID:
case DRM_MODE_CONNECTOR_HDMIA:
if (drm_detect_hdmi_monitor(radeon_connector->edid)) {
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
}
break;
case DRM_MODE_CONNECTOR_DisplayPort:
dig_connector = radeon_connector->con_priv;
if ((dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) ||
(dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_eDP) ||
drm_detect_hdmi_monitor(radeon_connector->edid)) {
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
}
break;
case DRM_MODE_CONNECTOR_eDP:
case DRM_MODE_CONNECTOR_LVDS:
if (connector->display_info.bpc)
bpc = connector->display_info.bpc;
else if (ASIC_IS_DCE41(rdev) || ASIC_IS_DCE5(rdev)) {
struct drm_connector_helper_funcs *connector_funcs =
connector->helper_private;
struct drm_encoder *encoder = connector_funcs->best_encoder(connector);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
if (dig->lcd_misc & ATOM_PANEL_MISC_V13_6BIT_PER_COLOR)
bpc = 6;
else if (dig->lcd_misc & ATOM_PANEL_MISC_V13_8BIT_PER_COLOR)
bpc = 8;
}
break;
}
return bpc;
}
static void
radeon_connector_update_scratch_regs(struct drm_connector *connector, enum drm_connector_status status)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct drm_encoder *best_encoder = NULL;
struct drm_encoder *encoder = NULL;
struct drm_connector_helper_funcs *connector_funcs = connector->helper_private;
struct drm_mode_object *obj;
bool connected;
int i;
best_encoder = connector_funcs->best_encoder(connector);
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
obj = drm_mode_object_find(connector->dev,
connector->encoder_ids[i],
DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
encoder = obj_to_encoder(obj);
if ((encoder == best_encoder) && (status == connector_status_connected))
connected = true;
else
connected = false;
if (rdev->is_atom_bios)
radeon_atombios_connected_scratch_regs(connector, encoder, connected);
else
radeon_combios_connected_scratch_regs(connector, encoder, connected);
}
}
static struct drm_encoder *radeon_find_encoder(struct drm_connector *connector, int encoder_type)
{
struct drm_mode_object *obj;
struct drm_encoder *encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
obj = drm_mode_object_find(connector->dev, connector->encoder_ids[i], DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
encoder = obj_to_encoder(obj);
if (encoder->encoder_type == encoder_type)
return encoder;
}
return NULL;
}
static struct drm_encoder *radeon_best_single_encoder(struct drm_connector *connector)
{
int enc_id = connector->encoder_ids[0];
struct drm_mode_object *obj;
struct drm_encoder *encoder;
if (enc_id) {
obj = drm_mode_object_find(connector->dev, enc_id, DRM_MODE_OBJECT_ENCODER);
if (!obj)
return NULL;
encoder = obj_to_encoder(obj);
return encoder;
}
return NULL;
}
static enum drm_connector_status
radeon_connector_analog_encoder_conflict_solve(struct drm_connector *connector,
struct drm_encoder *encoder,
enum drm_connector_status current_status,
bool priority)
{
struct drm_device *dev = connector->dev;
struct drm_connector *conflict;
struct radeon_connector *radeon_conflict;
int i;
list_for_each_entry(conflict, &dev->mode_config.connector_list, head) {
if (conflict == connector)
continue;
radeon_conflict = to_radeon_connector(conflict);
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (conflict->encoder_ids[i] == 0)
break;
if (conflict->encoder_ids[i] == encoder->base.id) {
if (conflict->status != connector_status_connected)
continue;
if (radeon_conflict->use_digital)
continue;
if (priority == true) {
DRM_DEBUG_KMS("1: conflicting encoders switching off %s\n", drm_get_connector_name(conflict));
DRM_DEBUG_KMS("in favor of %s\n", drm_get_connector_name(connector));
conflict->status = connector_status_disconnected;
radeon_connector_update_scratch_regs(conflict, connector_status_disconnected);
} else {
DRM_DEBUG_KMS("2: conflicting encoders switching off %s\n", drm_get_connector_name(connector));
DRM_DEBUG_KMS("in favor of %s\n", drm_get_connector_name(conflict));
current_status = connector_status_disconnected;
}
break;
}
}
}
return current_status;
}
static struct drm_display_mode *radeon_fp_native_mode(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *mode = NULL;
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
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
static void radeon_add_common_modes(struct drm_encoder *encoder, struct drm_connector *connector)
{
struct drm_device *dev = encoder->dev;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *mode = NULL;
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
int i;
struct mode_size {
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
if (radeon_encoder->devices & (ATOM_DEVICE_TV_SUPPORT)) {
if (common_modes[i].w > 1024 ||
common_modes[i].h > 768)
continue;
}
if (radeon_encoder->devices & (ATOM_DEVICE_LCD_SUPPORT)) {
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
static int radeon_connector_set_property(struct drm_connector *connector, struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct drm_encoder *encoder;
struct radeon_encoder *radeon_encoder;
if (property == rdev->mode_info.coherent_mode_property) {
struct radeon_encoder_atom_dig *dig;
bool new_coherent_mode;
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
radeon_encoder = to_radeon_encoder(encoder);
if (!radeon_encoder->enc_priv)
return 0;
dig = radeon_encoder->enc_priv;
new_coherent_mode = val ? true : false;
if (dig->coherent_mode != new_coherent_mode) {
dig->coherent_mode = new_coherent_mode;
radeon_property_change_mode(&radeon_encoder->base);
}
}
if (property == rdev->mode_info.underscan_property) {
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->underscan_type != val) {
radeon_encoder->underscan_type = val;
radeon_property_change_mode(&radeon_encoder->base);
}
}
if (property == rdev->mode_info.underscan_hborder_property) {
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->underscan_hborder != val) {
radeon_encoder->underscan_hborder = val;
radeon_property_change_mode(&radeon_encoder->base);
}
}
if (property == rdev->mode_info.underscan_vborder_property) {
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->underscan_vborder != val) {
radeon_encoder->underscan_vborder = val;
radeon_property_change_mode(&radeon_encoder->base);
}
}
if (property == rdev->mode_info.tv_std_property) {
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_TVDAC);
if (!encoder) {
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_DAC);
}
if (!encoder)
return 0;
radeon_encoder = to_radeon_encoder(encoder);
if (!radeon_encoder->enc_priv)
return 0;
if (ASIC_IS_AVIVO(rdev) || radeon_r4xx_atom) {
struct radeon_encoder_atom_dac *dac_int;
dac_int = radeon_encoder->enc_priv;
dac_int->tv_std = val;
} else {
struct radeon_encoder_tv_dac *dac_int;
dac_int = radeon_encoder->enc_priv;
dac_int->tv_std = val;
}
radeon_property_change_mode(&radeon_encoder->base);
}
if (property == rdev->mode_info.load_detect_property) {
struct radeon_connector *radeon_connector =
to_radeon_connector(connector);
if (val == 0)
radeon_connector->dac_load_detect = false;
else
radeon_connector->dac_load_detect = true;
}
if (property == rdev->mode_info.tmds_pll_property) {
struct radeon_encoder_int_tmds *tmds = NULL;
bool ret = false;
encoder = radeon_find_encoder(connector, DRM_MODE_ENCODER_TMDS);
if (!encoder)
return 0;
radeon_encoder = to_radeon_encoder(encoder);
tmds = radeon_encoder->enc_priv;
if (!tmds)
return 0;
if (val == 0) {
if (rdev->is_atom_bios)
ret = radeon_atombios_get_tmds_info(radeon_encoder, tmds);
else
ret = radeon_legacy_get_tmds_info_from_combios(radeon_encoder, tmds);
}
if (val == 1 || ret == false) {
radeon_legacy_get_tmds_info_from_table(radeon_encoder, tmds);
}
radeon_property_change_mode(&radeon_encoder->base);
}
return 0;
}
static void radeon_fixup_lvds_native_mode(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
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
radeon_encoder->rmx_type = RMX_OFF;
}
}
static int radeon_lvds_get_modes(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct drm_encoder *encoder;
int ret = 0;
struct drm_display_mode *mode;
if (radeon_connector->ddc_bus) {
ret = radeon_ddc_get_modes(radeon_connector);
if (ret > 0) {
encoder = radeon_best_single_encoder(connector);
if (encoder) {
radeon_fixup_lvds_native_mode(encoder, connector);
radeon_add_common_modes(encoder, connector);
}
return ret;
}
}
encoder = radeon_best_single_encoder(connector);
if (!encoder)
return 0;
mode = radeon_fp_native_mode(encoder);
if (mode) {
ret = 1;
drm_mode_probed_add(connector, mode);
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
radeon_add_common_modes(encoder, connector);
}
return ret;
}
static int radeon_lvds_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_encoder *encoder = radeon_best_single_encoder(connector);
if ((mode->hdisplay < 320) || (mode->vdisplay < 240))
return MODE_PANEL;
if (encoder) {
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
if ((mode->hdisplay > native_mode->hdisplay) ||
(mode->vdisplay > native_mode->vdisplay))
return MODE_PANEL;
if (radeon_encoder->rmx_type == RMX_OFF) {
if ((mode->hdisplay != native_mode->hdisplay) ||
(mode->vdisplay != native_mode->vdisplay))
return MODE_PANEL;
}
}
return MODE_OK;
}
static enum drm_connector_status
radeon_lvds_detect(struct drm_connector *connector, bool force)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct drm_encoder *encoder = radeon_best_single_encoder(connector);
enum drm_connector_status ret = connector_status_disconnected;
if (encoder) {
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
if (native_mode->hdisplay >= 320 && native_mode->vdisplay >= 240)
ret = connector_status_connected;
}
if (radeon_connector->edid)
ret = connector_status_connected;
else {
if (radeon_connector->ddc_bus) {
radeon_connector->edid = drm_get_edid(&radeon_connector->base,
&radeon_connector->ddc_bus->adapter);
if (radeon_connector->edid)
ret = connector_status_connected;
}
}
radeon_connector_update_scratch_regs(connector, ret);
return ret;
}
static void radeon_connector_destroy(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
if (radeon_connector->edid)
kfree(radeon_connector->edid);
kfree(radeon_connector->con_priv);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int radeon_lvds_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
struct drm_device *dev = connector->dev;
struct radeon_encoder *radeon_encoder;
enum radeon_rmx_type rmx_type;
DRM_DEBUG_KMS("\n");
if (property != dev->mode_config.scaling_mode_property)
return 0;
if (connector->encoder)
radeon_encoder = to_radeon_encoder(connector->encoder);
else {
struct drm_connector_helper_funcs *connector_funcs = connector->helper_private;
radeon_encoder = to_radeon_encoder(connector_funcs->best_encoder(connector));
}
switch (value) {
case DRM_MODE_SCALE_NONE: rmx_type = RMX_OFF; break;
case DRM_MODE_SCALE_CENTER: rmx_type = RMX_CENTER; break;
case DRM_MODE_SCALE_ASPECT: rmx_type = RMX_ASPECT; break;
default:
case DRM_MODE_SCALE_FULLSCREEN: rmx_type = RMX_FULL; break;
}
if (radeon_encoder->rmx_type == rmx_type)
return 0;
radeon_encoder->rmx_type = rmx_type;
radeon_property_change_mode(&radeon_encoder->base);
return 0;
}
static int radeon_vga_get_modes(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
int ret;
ret = radeon_ddc_get_modes(radeon_connector);
return ret;
}
static int radeon_vga_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
if ((mode->clock / 10) > rdev->clock.max_pixel_clock)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static enum drm_connector_status
radeon_vga_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct drm_encoder *encoder;
struct drm_encoder_helper_funcs *encoder_funcs;
bool dret = false;
enum drm_connector_status ret = connector_status_disconnected;
encoder = radeon_best_single_encoder(connector);
if (!encoder)
ret = connector_status_disconnected;
if (radeon_connector->ddc_bus)
dret = radeon_ddc_probe(radeon_connector, false);
if (dret) {
radeon_connector->detected_by_load = false;
if (radeon_connector->edid) {
kfree(radeon_connector->edid);
radeon_connector->edid = NULL;
}
radeon_connector->edid = drm_get_edid(&radeon_connector->base, &radeon_connector->ddc_bus->adapter);
if (!radeon_connector->edid) {
DRM_ERROR("%s: probed a monitor but no|invalid EDID\n",
drm_get_connector_name(connector));
ret = connector_status_connected;
} else {
radeon_connector->use_digital = !!(radeon_connector->edid->input & DRM_EDID_INPUT_DIGITAL);
if (radeon_connector->use_digital && radeon_connector->shared_ddc) {
kfree(radeon_connector->edid);
radeon_connector->edid = NULL;
ret = connector_status_disconnected;
} else
ret = connector_status_connected;
}
} else {
if (!force) {
if (radeon_connector->detected_by_load)
return connector->status;
else
return ret;
}
if (radeon_connector->dac_load_detect && encoder) {
encoder_funcs = encoder->helper_private;
ret = encoder_funcs->detect(encoder, connector);
if (ret != connector_status_disconnected)
radeon_connector->detected_by_load = true;
}
}
if (ret == connector_status_connected)
ret = radeon_connector_analog_encoder_conflict_solve(connector, encoder, ret, true);
if ((!rdev->is_atom_bios) &&
(ret == connector_status_disconnected) &&
rdev->mode_info.bios_hardcoded_edid_size) {
ret = connector_status_connected;
}
radeon_connector_update_scratch_regs(connector, ret);
return ret;
}
static int radeon_tv_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct drm_display_mode *tv_mode;
struct drm_encoder *encoder;
encoder = radeon_best_single_encoder(connector);
if (!encoder)
return 0;
if (rdev->family >= CHIP_RS600)
radeon_add_common_modes(encoder, connector);
else {
tv_mode = drm_cvt_mode(dev, 800, 600, 60, false, false, false);
tv_mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, tv_mode);
}
return 1;
}
static int radeon_tv_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
if ((mode->hdisplay > 1024) || (mode->vdisplay > 768))
return MODE_CLOCK_RANGE;
return MODE_OK;
}
static enum drm_connector_status
radeon_tv_detect(struct drm_connector *connector, bool force)
{
struct drm_encoder *encoder;
struct drm_encoder_helper_funcs *encoder_funcs;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
enum drm_connector_status ret = connector_status_disconnected;
if (!radeon_connector->dac_load_detect)
return ret;
encoder = radeon_best_single_encoder(connector);
if (!encoder)
ret = connector_status_disconnected;
else {
encoder_funcs = encoder->helper_private;
ret = encoder_funcs->detect(encoder, connector);
}
if (ret == connector_status_connected)
ret = radeon_connector_analog_encoder_conflict_solve(connector, encoder, ret, false);
radeon_connector_update_scratch_regs(connector, ret);
return ret;
}
static int radeon_dvi_get_modes(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
int ret;
ret = radeon_ddc_get_modes(radeon_connector);
return ret;
}
static bool radeon_check_hpd_status_unchanged(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
enum drm_connector_status status;
if (rdev->family >= CHIP_R600
&& radeon_connector->hpd.hpd != RADEON_HPD_NONE) {
if (radeon_hpd_sense(rdev, radeon_connector->hpd.hpd))
status = connector_status_connected;
else
status = connector_status_disconnected;
if (connector->status == status)
return true;
}
return false;
}
static enum drm_connector_status
radeon_dvi_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct drm_encoder *encoder = NULL;
struct drm_encoder_helper_funcs *encoder_funcs;
struct drm_mode_object *obj;
int i;
enum drm_connector_status ret = connector_status_disconnected;
bool dret = false, broken_edid = false;
if (!force && radeon_check_hpd_status_unchanged(connector))
return connector->status;
if (radeon_connector->ddc_bus)
dret = radeon_ddc_probe(radeon_connector, false);
if (dret) {
radeon_connector->detected_by_load = false;
if (radeon_connector->edid) {
kfree(radeon_connector->edid);
radeon_connector->edid = NULL;
}
radeon_connector->edid = drm_get_edid(&radeon_connector->base, &radeon_connector->ddc_bus->adapter);
if (!radeon_connector->edid) {
DRM_ERROR("%s: probed a monitor but no|invalid EDID\n",
drm_get_connector_name(connector));
if ((rdev->family == CHIP_RS690 || rdev->family == CHIP_RS740) && radeon_connector->base.null_edid_counter) {
ret = connector_status_disconnected;
DRM_ERROR("%s: detected RS690 floating bus bug, stopping ddc detect\n", drm_get_connector_name(connector));
radeon_connector->ddc_bus = NULL;
} else {
ret = connector_status_connected;
broken_edid = true;
}
} else {
radeon_connector->use_digital = !!(radeon_connector->edid->input & DRM_EDID_INPUT_DIGITAL);
if ((!radeon_connector->use_digital) && radeon_connector->shared_ddc) {
kfree(radeon_connector->edid);
radeon_connector->edid = NULL;
ret = connector_status_disconnected;
} else
ret = connector_status_connected;
if (radeon_connector->shared_ddc && (ret == connector_status_connected)) {
struct drm_connector *list_connector;
struct radeon_connector *list_radeon_connector;
list_for_each_entry(list_connector, &dev->mode_config.connector_list, head) {
if (connector == list_connector)
continue;
list_radeon_connector = to_radeon_connector(list_connector);
if (list_radeon_connector->shared_ddc &&
(list_radeon_connector->ddc_bus->rec.i2c_id ==
radeon_connector->ddc_bus->rec.i2c_id)) {
if (list_connector->connector_type != DRM_MODE_CONNECTOR_VGA) {
if (!radeon_hpd_sense(rdev, radeon_connector->hpd.hpd)) {
kfree(radeon_connector->edid);
radeon_connector->edid = NULL;
ret = connector_status_disconnected;
}
}
}
}
}
}
}
if ((ret == connector_status_connected) && (radeon_connector->use_digital == true))
goto out;
if ((connector->connector_type == DRM_MODE_CONNECTOR_DVID) ||
(connector->connector_type == DRM_MODE_CONNECTOR_HDMIA))
goto out;
if (!force) {
if (radeon_connector->detected_by_load)
ret = connector->status;
goto out;
}
if (radeon_connector->dac_load_detect) {
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
obj = drm_mode_object_find(connector->dev,
connector->encoder_ids[i],
DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
encoder = obj_to_encoder(obj);
if (encoder->encoder_type != DRM_MODE_ENCODER_DAC &&
encoder->encoder_type != DRM_MODE_ENCODER_TVDAC)
continue;
encoder_funcs = encoder->helper_private;
if (encoder_funcs->detect) {
if (!broken_edid) {
if (ret != connector_status_connected) {
ret = encoder_funcs->detect(encoder, connector);
if (ret == connector_status_connected) {
radeon_connector->use_digital = false;
}
if (ret != connector_status_disconnected)
radeon_connector->detected_by_load = true;
}
} else {
enum drm_connector_status lret;
radeon_connector->use_digital = true;
lret = encoder_funcs->detect(encoder, connector);
DRM_DEBUG_KMS("load_detect %x returned: %x\n",encoder->encoder_type,lret);
if (lret == connector_status_connected)
radeon_connector->use_digital = false;
}
break;
}
}
}
if ((ret == connector_status_connected) && (radeon_connector->use_digital == false) &&
encoder) {
ret = radeon_connector_analog_encoder_conflict_solve(connector, encoder, ret, true);
}
out:
if ((!rdev->is_atom_bios) &&
(ret == connector_status_disconnected) &&
rdev->mode_info.bios_hardcoded_edid_size) {
radeon_connector->use_digital = true;
ret = connector_status_connected;
}
radeon_connector_update_scratch_regs(connector, ret);
return ret;
}
static struct drm_encoder *radeon_dvi_encoder(struct drm_connector *connector)
{
int enc_id = connector->encoder_ids[0];
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct drm_mode_object *obj;
struct drm_encoder *encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
obj = drm_mode_object_find(connector->dev, connector->encoder_ids[i], DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
encoder = obj_to_encoder(obj);
if (radeon_connector->use_digital == true) {
if (encoder->encoder_type == DRM_MODE_ENCODER_TMDS)
return encoder;
} else {
if (encoder->encoder_type == DRM_MODE_ENCODER_DAC ||
encoder->encoder_type == DRM_MODE_ENCODER_TVDAC)
return encoder;
}
}
if (enc_id) {
obj = drm_mode_object_find(connector->dev, enc_id, DRM_MODE_OBJECT_ENCODER);
if (!obj)
return NULL;
encoder = obj_to_encoder(obj);
return encoder;
}
return NULL;
}
static void radeon_dvi_force(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
if (connector->force == DRM_FORCE_ON)
radeon_connector->use_digital = false;
if (connector->force == DRM_FORCE_ON_DIGITAL)
radeon_connector->use_digital = true;
}
static int radeon_dvi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
if (radeon_connector->use_digital &&
(rdev->family == CHIP_RV100) &&
(mode->clock > 135000))
return MODE_CLOCK_HIGH;
if (radeon_connector->use_digital && (mode->clock > 165000)) {
if ((radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I) ||
(radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D) ||
(radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_HDMI_TYPE_B))
return MODE_OK;
else if (radeon_connector->connector_object_id == CONNECTOR_OBJECT_ID_HDMI_TYPE_A) {
if (ASIC_IS_DCE6(rdev)) {
if (mode->clock > 340000)
return MODE_CLOCK_HIGH;
else
return MODE_OK;
} else
return MODE_CLOCK_HIGH;
} else
return MODE_CLOCK_HIGH;
}
if ((mode->clock / 10) > rdev->clock.max_pixel_clock)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static void radeon_dp_connector_destroy(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct radeon_connector_atom_dig *radeon_dig_connector = radeon_connector->con_priv;
if (radeon_connector->edid)
kfree(radeon_connector->edid);
if (radeon_dig_connector->dp_i2c_bus)
radeon_i2c_destroy(radeon_dig_connector->dp_i2c_bus);
kfree(radeon_connector->con_priv);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int radeon_dp_get_modes(struct drm_connector *connector)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct radeon_connector_atom_dig *radeon_dig_connector = radeon_connector->con_priv;
struct drm_encoder *encoder = radeon_best_single_encoder(connector);
int ret;
if ((connector->connector_type == DRM_MODE_CONNECTOR_eDP) ||
(connector->connector_type == DRM_MODE_CONNECTOR_LVDS)) {
struct drm_display_mode *mode;
if (connector->connector_type == DRM_MODE_CONNECTOR_eDP) {
if (!radeon_dig_connector->edp_on)
atombios_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_ON);
ret = radeon_ddc_get_modes(radeon_connector);
if (!radeon_dig_connector->edp_on)
atombios_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_OFF);
} else {
if (radeon_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) {
if (encoder)
radeon_atom_ext_encoder_setup_ddc(encoder);
}
ret = radeon_ddc_get_modes(radeon_connector);
}
if (ret > 0) {
if (encoder) {
radeon_fixup_lvds_native_mode(encoder, connector);
radeon_add_common_modes(encoder, connector);
}
return ret;
}
if (!encoder)
return 0;
mode = radeon_fp_native_mode(encoder);
if (mode) {
ret = 1;
drm_mode_probed_add(connector, mode);
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
radeon_add_common_modes(encoder, connector);
}
} else {
if (radeon_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) {
if (encoder)
radeon_atom_ext_encoder_setup_ddc(encoder);
}
ret = radeon_ddc_get_modes(radeon_connector);
}
return ret;
}
u16 radeon_connector_encoder_get_dp_bridge_encoder_id(struct drm_connector *connector)
{
struct drm_mode_object *obj;
struct drm_encoder *encoder;
struct radeon_encoder *radeon_encoder;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
obj = drm_mode_object_find(connector->dev, connector->encoder_ids[i], DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
encoder = obj_to_encoder(obj);
radeon_encoder = to_radeon_encoder(encoder);
switch (radeon_encoder->encoder_id) {
case ENCODER_OBJECT_ID_TRAVIS:
case ENCODER_OBJECT_ID_NUTMEG:
return radeon_encoder->encoder_id;
default:
break;
}
}
return ENCODER_OBJECT_ID_NONE;
}
bool radeon_connector_encoder_is_hbr2(struct drm_connector *connector)
{
struct drm_mode_object *obj;
struct drm_encoder *encoder;
struct radeon_encoder *radeon_encoder;
int i;
bool found = false;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0)
break;
obj = drm_mode_object_find(connector->dev, connector->encoder_ids[i], DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
encoder = obj_to_encoder(obj);
radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->caps & ATOM_ENCODER_CAP_RECORD_HBR2)
found = true;
}
return found;
}
bool radeon_connector_is_dp12_capable(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
if (ASIC_IS_DCE5(rdev) &&
(rdev->clock.dp_extclk >= 53900) &&
radeon_connector_encoder_is_hbr2(connector)) {
return true;
}
return false;
}
static enum drm_connector_status
radeon_dp_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
enum drm_connector_status ret = connector_status_disconnected;
struct radeon_connector_atom_dig *radeon_dig_connector = radeon_connector->con_priv;
struct drm_encoder *encoder = radeon_best_single_encoder(connector);
if (!force && radeon_check_hpd_status_unchanged(connector))
return connector->status;
if (radeon_connector->edid) {
kfree(radeon_connector->edid);
radeon_connector->edid = NULL;
}
if ((connector->connector_type == DRM_MODE_CONNECTOR_eDP) ||
(connector->connector_type == DRM_MODE_CONNECTOR_LVDS)) {
if (encoder) {
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
if (native_mode->hdisplay >= 320 && native_mode->vdisplay >= 240)
ret = connector_status_connected;
}
radeon_dig_connector->dp_sink_type = CONNECTOR_OBJECT_ID_DISPLAYPORT;
if (!radeon_dig_connector->edp_on)
atombios_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_ON);
if (radeon_dp_getdpcd(radeon_connector))
ret = connector_status_connected;
if (!radeon_dig_connector->edp_on)
atombios_set_edp_panel_power(connector,
ATOM_TRANSMITTER_ACTION_POWER_OFF);
} else if (radeon_connector_encoder_get_dp_bridge_encoder_id(connector) !=
ENCODER_OBJECT_ID_NONE) {
radeon_dig_connector->dp_sink_type = CONNECTOR_OBJECT_ID_DISPLAYPORT;
radeon_dp_getdpcd(radeon_connector);
if (encoder) {
radeon_atom_ext_encoder_setup_ddc(encoder);
if (radeon_ddc_probe(radeon_connector, true))
ret = connector_status_connected;
else if (radeon_connector->dac_load_detect) {
struct drm_encoder_helper_funcs *encoder_funcs = encoder->helper_private;
ret = encoder_funcs->detect(encoder, connector);
}
}
} else {
radeon_dig_connector->dp_sink_type = radeon_dp_getsinktype(radeon_connector);
if (radeon_hpd_sense(rdev, radeon_connector->hpd.hpd)) {
ret = connector_status_connected;
if (radeon_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT)
radeon_dp_getdpcd(radeon_connector);
} else {
if (radeon_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) {
if (radeon_dp_getdpcd(radeon_connector))
ret = connector_status_connected;
} else {
if (radeon_ddc_probe(radeon_connector, false))
ret = connector_status_connected;
}
}
}
radeon_connector_update_scratch_regs(connector, ret);
return ret;
}
static int radeon_dp_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct radeon_connector_atom_dig *radeon_dig_connector = radeon_connector->con_priv;
if ((connector->connector_type == DRM_MODE_CONNECTOR_eDP) ||
(connector->connector_type == DRM_MODE_CONNECTOR_LVDS)) {
struct drm_encoder *encoder = radeon_best_single_encoder(connector);
if ((mode->hdisplay < 320) || (mode->vdisplay < 240))
return MODE_PANEL;
if (encoder) {
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct drm_display_mode *native_mode = &radeon_encoder->native_mode;
if ((mode->hdisplay > native_mode->hdisplay) ||
(mode->vdisplay > native_mode->vdisplay))
return MODE_PANEL;
if (radeon_encoder->rmx_type == RMX_OFF) {
if ((mode->hdisplay != native_mode->hdisplay) ||
(mode->vdisplay != native_mode->vdisplay))
return MODE_PANEL;
}
}
return MODE_OK;
} else {
if ((radeon_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_DISPLAYPORT) ||
(radeon_dig_connector->dp_sink_type == CONNECTOR_OBJECT_ID_eDP))
return radeon_dp_mode_valid_helper(connector, mode);
else
return MODE_OK;
}
}
void
radeon_add_atom_connector(struct drm_device *dev,
uint32_t connector_id,
uint32_t supported_device,
int connector_type,
struct radeon_i2c_bus_rec *i2c_bus,
uint32_t igp_lane_info,
uint16_t connector_object_id,
struct radeon_hpd *hpd,
struct radeon_router *router)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_connector *connector;
struct radeon_connector *radeon_connector;
struct radeon_connector_atom_dig *radeon_dig_connector;
struct drm_encoder *encoder;
struct radeon_encoder *radeon_encoder;
uint32_t subpixel_order = SubPixelNone;
bool shared_ddc = false;
bool is_dp_bridge = false;
if (connector_type == DRM_MODE_CONNECTOR_Unknown)
return;
if (((connector_type == DRM_MODE_CONNECTOR_SVIDEO) ||
(connector_type == DRM_MODE_CONNECTOR_Composite) ||
(connector_type == DRM_MODE_CONNECTOR_9PinDIN)) &&
(radeon_tv == 0))
return;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
radeon_connector = to_radeon_connector(connector);
if (radeon_connector->connector_id == connector_id) {
radeon_connector->devices |= supported_device;
return;
}
if (radeon_connector->ddc_bus && i2c_bus->valid) {
if (radeon_connector->ddc_bus->rec.i2c_id == i2c_bus->i2c_id) {
radeon_connector->shared_ddc = true;
shared_ddc = true;
}
if (radeon_connector->router_bus && router->ddc_valid &&
(radeon_connector->router.router_id == router->router_id)) {
radeon_connector->shared_ddc = false;
shared_ddc = false;
}
}
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->devices & supported_device) {
switch (radeon_encoder->encoder_id) {
case ENCODER_OBJECT_ID_TRAVIS:
case ENCODER_OBJECT_ID_NUTMEG:
is_dp_bridge = true;
break;
default:
break;
}
}
}
radeon_connector = kzalloc(sizeof(struct radeon_connector), GFP_KERNEL);
if (!radeon_connector)
return;
connector = &radeon_connector->base;
radeon_connector->connector_id = connector_id;
radeon_connector->devices = supported_device;
radeon_connector->shared_ddc = shared_ddc;
radeon_connector->connector_object_id = connector_object_id;
radeon_connector->hpd = *hpd;
radeon_connector->router = *router;
if (router->ddc_valid || router->cd_valid) {
radeon_connector->router_bus = radeon_i2c_lookup(rdev, &router->i2c_info);
if (!radeon_connector->router_bus)
DRM_ERROR("Failed to assign router i2c bus! Check dmesg for i2c errors.\n");
}
if (is_dp_bridge) {
radeon_dig_connector = kzalloc(sizeof(struct radeon_connector_atom_dig), GFP_KERNEL);
if (!radeon_dig_connector)
goto failed;
radeon_dig_connector->igp_lane_info = igp_lane_info;
radeon_connector->con_priv = radeon_dig_connector;
drm_connector_init(dev, &radeon_connector->base, &radeon_dp_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_dp_connector_helper_funcs);
if (i2c_bus->valid) {
if (connector_type == DRM_MODE_CONNECTOR_eDP)
radeon_dig_connector->dp_i2c_bus = radeon_i2c_create_dp(dev, i2c_bus, "eDP-auxch");
else
radeon_dig_connector->dp_i2c_bus = radeon_i2c_create_dp(dev, i2c_bus, "DP-auxch");
if (!radeon_dig_connector->dp_i2c_bus)
DRM_ERROR("DP: Failed to assign dp ddc bus! Check dmesg for i2c errors.\n");
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DP: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
switch (connector_type) {
case DRM_MODE_CONNECTOR_VGA:
case DRM_MODE_CONNECTOR_DVIA:
default:
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
case DRM_MODE_CONNECTOR_HDMIA:
case DRM_MODE_CONNECTOR_HDMIB:
case DRM_MODE_CONNECTOR_DisplayPort:
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_vborder_property,
0);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = true;
if (connector_type == DRM_MODE_CONNECTOR_HDMIB)
connector->doublescan_allowed = true;
else
connector->doublescan_allowed = false;
if (connector_type == DRM_MODE_CONNECTOR_DVII) {
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
}
break;
case DRM_MODE_CONNECTOR_LVDS:
case DRM_MODE_CONNECTOR_eDP:
drm_object_attach_property(&radeon_connector->base.base,
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
drm_connector_init(dev, &radeon_connector->base, &radeon_vga_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_vga_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("VGA: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
radeon_connector->hpd.hpd = RADEON_HPD_NONE;
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
break;
case DRM_MODE_CONNECTOR_DVIA:
drm_connector_init(dev, &radeon_connector->base, &radeon_vga_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_vga_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DVIA: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
radeon_connector->hpd.hpd = RADEON_HPD_NONE;
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
radeon_dig_connector = kzalloc(sizeof(struct radeon_connector_atom_dig), GFP_KERNEL);
if (!radeon_dig_connector)
goto failed;
radeon_dig_connector->igp_lane_info = igp_lane_info;
radeon_connector->con_priv = radeon_dig_connector;
drm_connector_init(dev, &radeon_connector->base, &radeon_dvi_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_dvi_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DVI: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
subpixel_order = SubPixelHorizontalRGB;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.coherent_mode_property,
1);
if (ASIC_IS_AVIVO(rdev)) {
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_vborder_property,
0);
}
if (connector_type == DRM_MODE_CONNECTOR_DVII) {
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
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
radeon_dig_connector = kzalloc(sizeof(struct radeon_connector_atom_dig), GFP_KERNEL);
if (!radeon_dig_connector)
goto failed;
radeon_dig_connector->igp_lane_info = igp_lane_info;
radeon_connector->con_priv = radeon_dig_connector;
drm_connector_init(dev, &radeon_connector->base, &radeon_dvi_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_dvi_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("HDMI: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.coherent_mode_property,
1);
if (ASIC_IS_AVIVO(rdev)) {
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_vborder_property,
0);
}
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = true;
if (connector_type == DRM_MODE_CONNECTOR_HDMIB)
connector->doublescan_allowed = true;
else
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_DisplayPort:
radeon_dig_connector = kzalloc(sizeof(struct radeon_connector_atom_dig), GFP_KERNEL);
if (!radeon_dig_connector)
goto failed;
radeon_dig_connector->igp_lane_info = igp_lane_info;
radeon_connector->con_priv = radeon_dig_connector;
drm_connector_init(dev, &radeon_connector->base, &radeon_dp_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_dp_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_dig_connector->dp_i2c_bus = radeon_i2c_create_dp(dev, i2c_bus, "DP-auxch");
if (!radeon_dig_connector->dp_i2c_bus)
DRM_ERROR("DP: Failed to assign dp ddc bus! Check dmesg for i2c errors.\n");
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DP: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
subpixel_order = SubPixelHorizontalRGB;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.coherent_mode_property,
1);
if (ASIC_IS_AVIVO(rdev)) {
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_property,
UNDERSCAN_OFF);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_hborder_property,
0);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.underscan_vborder_property,
0);
}
connector->interlace_allowed = true;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_eDP:
radeon_dig_connector = kzalloc(sizeof(struct radeon_connector_atom_dig), GFP_KERNEL);
if (!radeon_dig_connector)
goto failed;
radeon_dig_connector->igp_lane_info = igp_lane_info;
radeon_connector->con_priv = radeon_dig_connector;
drm_connector_init(dev, &radeon_connector->base, &radeon_dp_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_dp_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_dig_connector->dp_i2c_bus = radeon_i2c_create_dp(dev, i2c_bus, "eDP-auxch");
if (!radeon_dig_connector->dp_i2c_bus)
DRM_ERROR("DP: Failed to assign dp ddc bus! Check dmesg for i2c errors.\n");
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DP: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&radeon_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_SVIDEO:
case DRM_MODE_CONNECTOR_Composite:
case DRM_MODE_CONNECTOR_9PinDIN:
drm_connector_init(dev, &radeon_connector->base, &radeon_tv_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_tv_connector_helper_funcs);
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.tv_std_property,
radeon_atombios_get_tv_info(rdev));
radeon_connector->hpd.hpd = RADEON_HPD_NONE;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_LVDS:
radeon_dig_connector = kzalloc(sizeof(struct radeon_connector_atom_dig), GFP_KERNEL);
if (!radeon_dig_connector)
goto failed;
radeon_dig_connector->igp_lane_info = igp_lane_info;
radeon_connector->con_priv = radeon_dig_connector;
drm_connector_init(dev, &radeon_connector->base, &radeon_lvds_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_lvds_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("LVDS: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&radeon_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
}
}
if (radeon_connector->hpd.hpd == RADEON_HPD_NONE) {
if (i2c_bus->valid)
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
} else
connector->polled = DRM_CONNECTOR_POLL_HPD;
connector->display_info.subpixel_order = subpixel_order;
drm_sysfs_connector_add(connector);
return;
failed:
drm_connector_cleanup(connector);
kfree(connector);
}
void
radeon_add_legacy_connector(struct drm_device *dev,
uint32_t connector_id,
uint32_t supported_device,
int connector_type,
struct radeon_i2c_bus_rec *i2c_bus,
uint16_t connector_object_id,
struct radeon_hpd *hpd)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_connector *connector;
struct radeon_connector *radeon_connector;
uint32_t subpixel_order = SubPixelNone;
if (connector_type == DRM_MODE_CONNECTOR_Unknown)
return;
if (((connector_type == DRM_MODE_CONNECTOR_SVIDEO) ||
(connector_type == DRM_MODE_CONNECTOR_Composite) ||
(connector_type == DRM_MODE_CONNECTOR_9PinDIN)) &&
(radeon_tv == 0))
return;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
radeon_connector = to_radeon_connector(connector);
if (radeon_connector->connector_id == connector_id) {
radeon_connector->devices |= supported_device;
return;
}
}
radeon_connector = kzalloc(sizeof(struct radeon_connector), GFP_KERNEL);
if (!radeon_connector)
return;
connector = &radeon_connector->base;
radeon_connector->connector_id = connector_id;
radeon_connector->devices = supported_device;
radeon_connector->connector_object_id = connector_object_id;
radeon_connector->hpd = *hpd;
switch (connector_type) {
case DRM_MODE_CONNECTOR_VGA:
drm_connector_init(dev, &radeon_connector->base, &radeon_vga_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_vga_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("VGA: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
radeon_connector->hpd.hpd = RADEON_HPD_NONE;
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
break;
case DRM_MODE_CONNECTOR_DVIA:
drm_connector_init(dev, &radeon_connector->base, &radeon_vga_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_vga_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DVIA: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
radeon_connector->hpd.hpd = RADEON_HPD_NONE;
connector->interlace_allowed = true;
connector->doublescan_allowed = true;
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
drm_connector_init(dev, &radeon_connector->base, &radeon_dvi_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_dvi_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("DVI: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
if (connector_type == DRM_MODE_CONNECTOR_DVII) {
radeon_connector->dac_load_detect = true;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
1);
}
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = true;
if (connector_type == DRM_MODE_CONNECTOR_DVII)
connector->doublescan_allowed = true;
else
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_SVIDEO:
case DRM_MODE_CONNECTOR_Composite:
case DRM_MODE_CONNECTOR_9PinDIN:
drm_connector_init(dev, &radeon_connector->base, &radeon_tv_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_tv_connector_helper_funcs);
radeon_connector->dac_load_detect = true;
if (rdev->family == CHIP_RS400 || rdev->family == CHIP_RS480)
radeon_connector->dac_load_detect = false;
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.load_detect_property,
radeon_connector->dac_load_detect);
drm_object_attach_property(&radeon_connector->base.base,
rdev->mode_info.tv_std_property,
radeon_combios_get_tv_info(rdev));
radeon_connector->hpd.hpd = RADEON_HPD_NONE;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
case DRM_MODE_CONNECTOR_LVDS:
drm_connector_init(dev, &radeon_connector->base, &radeon_lvds_connector_funcs, connector_type);
drm_connector_helper_add(&radeon_connector->base, &radeon_lvds_connector_helper_funcs);
if (i2c_bus->valid) {
radeon_connector->ddc_bus = radeon_i2c_lookup(rdev, i2c_bus);
if (!radeon_connector->ddc_bus)
DRM_ERROR("LVDS: Failed to assign ddc bus! Check dmesg for i2c errors.\n");
}
drm_object_attach_property(&radeon_connector->base.base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
break;
}
if (radeon_connector->hpd.hpd == RADEON_HPD_NONE) {
if (i2c_bus->valid)
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
} else
connector->polled = DRM_CONNECTOR_POLL_HPD;
connector->display_info.subpixel_order = subpixel_order;
drm_sysfs_connector_add(connector);
}
