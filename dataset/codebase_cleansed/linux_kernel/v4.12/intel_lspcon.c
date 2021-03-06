static struct intel_dp *lspcon_to_intel_dp(struct intel_lspcon *lspcon)
{
struct intel_digital_port *dig_port =
container_of(lspcon, struct intel_digital_port, lspcon);
return &dig_port->dp;
}
static const char *lspcon_mode_name(enum drm_lspcon_mode mode)
{
switch (mode) {
case DRM_LSPCON_MODE_PCON:
return "PCON";
case DRM_LSPCON_MODE_LS:
return "LS";
case DRM_LSPCON_MODE_INVALID:
return "INVALID";
default:
MISSING_CASE(mode);
return "INVALID";
}
}
static enum drm_lspcon_mode lspcon_get_current_mode(struct intel_lspcon *lspcon)
{
enum drm_lspcon_mode current_mode;
struct i2c_adapter *adapter = &lspcon_to_intel_dp(lspcon)->aux.ddc;
if (drm_lspcon_get_mode(adapter, &current_mode)) {
DRM_ERROR("Error reading LSPCON mode\n");
return DRM_LSPCON_MODE_INVALID;
}
return current_mode;
}
static enum drm_lspcon_mode lspcon_wait_mode(struct intel_lspcon *lspcon,
enum drm_lspcon_mode mode)
{
enum drm_lspcon_mode current_mode;
current_mode = lspcon_get_current_mode(lspcon);
if (current_mode == mode || current_mode == DRM_LSPCON_MODE_INVALID)
goto out;
DRM_DEBUG_KMS("Waiting for LSPCON mode %s to settle\n",
lspcon_mode_name(mode));
wait_for((current_mode = lspcon_get_current_mode(lspcon)) == mode ||
current_mode == DRM_LSPCON_MODE_INVALID, 100);
if (current_mode != mode)
DRM_DEBUG_KMS("LSPCON mode hasn't settled\n");
out:
DRM_DEBUG_KMS("Current LSPCON mode %s\n",
lspcon_mode_name(current_mode));
return current_mode;
}
static int lspcon_change_mode(struct intel_lspcon *lspcon,
enum drm_lspcon_mode mode)
{
int err;
enum drm_lspcon_mode current_mode;
struct i2c_adapter *adapter = &lspcon_to_intel_dp(lspcon)->aux.ddc;
err = drm_lspcon_get_mode(adapter, &current_mode);
if (err) {
DRM_ERROR("Error reading LSPCON mode\n");
return err;
}
if (current_mode == mode) {
DRM_DEBUG_KMS("Current mode = desired LSPCON mode\n");
return 0;
}
err = drm_lspcon_set_mode(adapter, mode);
if (err < 0) {
DRM_ERROR("LSPCON mode change failed\n");
return err;
}
lspcon->mode = mode;
DRM_DEBUG_KMS("LSPCON mode changed done\n");
return 0;
}
static bool lspcon_wake_native_aux_ch(struct intel_lspcon *lspcon)
{
uint8_t rev;
if (drm_dp_dpcd_readb(&lspcon_to_intel_dp(lspcon)->aux, DP_DPCD_REV,
&rev) != 1) {
DRM_DEBUG_KMS("Native AUX CH down\n");
return false;
}
DRM_DEBUG_KMS("Native AUX CH up, DPCD version: %d.%d\n",
rev >> 4, rev & 0xf);
return true;
}
static bool lspcon_probe(struct intel_lspcon *lspcon)
{
enum drm_dp_dual_mode_type adaptor_type;
struct i2c_adapter *adapter = &lspcon_to_intel_dp(lspcon)->aux.ddc;
enum drm_lspcon_mode expected_mode;
expected_mode = lspcon_wake_native_aux_ch(lspcon) ?
DRM_LSPCON_MODE_PCON : DRM_LSPCON_MODE_LS;
adaptor_type = drm_dp_dual_mode_detect(adapter);
if (adaptor_type != DRM_DP_DUAL_MODE_LSPCON) {
DRM_DEBUG_KMS("No LSPCON detected, found %s\n",
drm_dp_get_dual_mode_type_name(adaptor_type));
return false;
}
DRM_DEBUG_KMS("LSPCON detected\n");
lspcon->mode = lspcon_wait_mode(lspcon, expected_mode);
lspcon->active = true;
return true;
}
static void lspcon_resume_in_pcon_wa(struct intel_lspcon *lspcon)
{
struct intel_dp *intel_dp = lspcon_to_intel_dp(lspcon);
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_i915_private *dev_priv = to_i915(dig_port->base.base.dev);
unsigned long start = jiffies;
while (1) {
if (intel_digital_port_connected(dev_priv, dig_port)) {
DRM_DEBUG_KMS("LSPCON recovering in PCON mode after %u ms\n",
jiffies_to_msecs(jiffies - start));
return;
}
if (time_after(jiffies, start + msecs_to_jiffies(1000)))
break;
usleep_range(10000, 15000);
}
DRM_DEBUG_KMS("LSPCON DP descriptor mismatch after resume\n");
}
void lspcon_resume(struct intel_lspcon *lspcon)
{
enum drm_lspcon_mode expected_mode;
if (lspcon_wake_native_aux_ch(lspcon)) {
expected_mode = DRM_LSPCON_MODE_PCON;
lspcon_resume_in_pcon_wa(lspcon);
} else {
expected_mode = DRM_LSPCON_MODE_LS;
}
if (lspcon_wait_mode(lspcon, expected_mode) == DRM_LSPCON_MODE_PCON)
return;
if (lspcon_change_mode(lspcon, DRM_LSPCON_MODE_PCON))
DRM_ERROR("LSPCON resume failed\n");
else
DRM_DEBUG_KMS("LSPCON resume success\n");
}
void lspcon_wait_pcon_mode(struct intel_lspcon *lspcon)
{
lspcon_wait_mode(lspcon, DRM_LSPCON_MODE_PCON);
}
bool lspcon_init(struct intel_digital_port *intel_dig_port)
{
struct intel_dp *dp = &intel_dig_port->dp;
struct intel_lspcon *lspcon = &intel_dig_port->lspcon;
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (!IS_GEN9(dev_priv)) {
DRM_ERROR("LSPCON is supported on GEN9 only\n");
return false;
}
lspcon->active = false;
lspcon->mode = DRM_LSPCON_MODE_INVALID;
if (!lspcon_probe(lspcon)) {
DRM_ERROR("Failed to probe lspcon\n");
return false;
}
if (lspcon->active && lspcon->mode != DRM_LSPCON_MODE_PCON) {
if (lspcon_change_mode(lspcon, DRM_LSPCON_MODE_PCON) < 0) {
DRM_ERROR("LSPCON mode change to PCON failed\n");
return false;
}
}
if (!intel_dp_read_dpcd(dp)) {
DRM_ERROR("LSPCON DPCD read failed\n");
return false;
}
drm_dp_read_desc(&dp->aux, &dp->desc, drm_dp_is_branch(dp->dpcd));
DRM_DEBUG_KMS("Success: LSPCON init\n");
return true;
}
