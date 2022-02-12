static void dce_virtual_vblank_wait(struct amdgpu_device *adev, int crtc)
{
return;
}
static u32 dce_virtual_vblank_get_counter(struct amdgpu_device *adev, int crtc)
{
return 0;
}
static void dce_virtual_page_flip(struct amdgpu_device *adev,
int crtc_id, u64 crtc_base, bool async)
{
return;
}
static int dce_virtual_crtc_get_scanoutpos(struct amdgpu_device *adev, int crtc,
u32 *vbl, u32 *position)
{
*vbl = 0;
*position = 0;
return -EINVAL;
}
static bool dce_virtual_hpd_sense(struct amdgpu_device *adev,
enum amdgpu_hpd_id hpd)
{
return true;
}
static void dce_virtual_hpd_set_polarity(struct amdgpu_device *adev,
enum amdgpu_hpd_id hpd)
{
return;
}
static u32 dce_virtual_hpd_get_gpio_reg(struct amdgpu_device *adev)
{
return 0;
}
static void dce_virtual_bandwidth_update(struct amdgpu_device *adev)
{
return;
}
static int dce_virtual_crtc_gamma_set(struct drm_crtc *crtc, u16 *red,
u16 *green, u16 *blue, uint32_t size,
struct drm_modeset_acquire_ctx *ctx)
{
return 0;
}
static void dce_virtual_crtc_destroy(struct drm_crtc *crtc)
{
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
drm_crtc_cleanup(crtc);
kfree(amdgpu_crtc);
}
static void dce_virtual_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
unsigned type;
if (amdgpu_sriov_vf(adev))
return;
switch (mode) {
case DRM_MODE_DPMS_ON:
amdgpu_crtc->enabled = true;
type = amdgpu_crtc_idx_to_irq_type(adev, amdgpu_crtc->crtc_id);
amdgpu_irq_update(adev, &adev->crtc_irq, type);
drm_crtc_vblank_on(crtc);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
drm_crtc_vblank_off(crtc);
amdgpu_crtc->enabled = false;
break;
}
}
static void dce_virtual_crtc_prepare(struct drm_crtc *crtc)
{
dce_virtual_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void dce_virtual_crtc_commit(struct drm_crtc *crtc)
{
dce_virtual_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
}
static void dce_virtual_crtc_disable(struct drm_crtc *crtc)
{
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
dce_virtual_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
if (crtc->primary->fb) {
int r;
struct amdgpu_framebuffer *amdgpu_fb;
struct amdgpu_bo *abo;
amdgpu_fb = to_amdgpu_framebuffer(crtc->primary->fb);
abo = gem_to_amdgpu_bo(amdgpu_fb->obj);
r = amdgpu_bo_reserve(abo, true);
if (unlikely(r))
DRM_ERROR("failed to reserve abo before unpin\n");
else {
amdgpu_bo_unpin(abo);
amdgpu_bo_unreserve(abo);
}
}
amdgpu_crtc->pll_id = ATOM_PPLL_INVALID;
amdgpu_crtc->encoder = NULL;
amdgpu_crtc->connector = NULL;
}
static int dce_virtual_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y, struct drm_framebuffer *old_fb)
{
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
amdgpu_crtc->hw_mode = *adjusted_mode;
return 0;
}
static bool dce_virtual_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static int dce_virtual_crtc_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
return 0;
}
static int dce_virtual_crtc_set_base_atomic(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int x, int y, enum mode_set_atomic state)
{
return 0;
}
static int dce_virtual_crtc_init(struct amdgpu_device *adev, int index)
{
struct amdgpu_crtc *amdgpu_crtc;
amdgpu_crtc = kzalloc(sizeof(struct amdgpu_crtc) +
(AMDGPUFB_CONN_LIMIT * sizeof(struct drm_connector *)), GFP_KERNEL);
if (amdgpu_crtc == NULL)
return -ENOMEM;
drm_crtc_init(adev->ddev, &amdgpu_crtc->base, &dce_virtual_crtc_funcs);
drm_mode_crtc_set_gamma_size(&amdgpu_crtc->base, 256);
amdgpu_crtc->crtc_id = index;
adev->mode_info.crtcs[index] = amdgpu_crtc;
amdgpu_crtc->pll_id = ATOM_PPLL_INVALID;
amdgpu_crtc->encoder = NULL;
amdgpu_crtc->connector = NULL;
amdgpu_crtc->vsync_timer_enabled = AMDGPU_IRQ_STATE_DISABLE;
drm_crtc_helper_add(&amdgpu_crtc->base, &dce_virtual_crtc_helper_funcs);
return 0;
}
static int dce_virtual_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
dce_virtual_set_display_funcs(adev);
dce_virtual_set_irq_funcs(adev);
adev->mode_info.num_hpd = 1;
adev->mode_info.num_dig = 1;
return 0;
}
static struct drm_encoder *
dce_virtual_encoder(struct drm_connector *connector)
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
static int dce_virtual_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode = NULL;
unsigned i;
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
mode = drm_cvt_mode(dev, common_modes[i].w, common_modes[i].h, 60, false, false, false);
drm_mode_probed_add(connector, mode);
}
return 0;
}
static int dce_virtual_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static int
dce_virtual_dpms(struct drm_connector *connector, int mode)
{
return 0;
}
static int
dce_virtual_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
return 0;
}
static void dce_virtual_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static void dce_virtual_force(struct drm_connector *connector)
{
return;
}
static int dce_virtual_sw_init(void *handle)
{
int r, i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_LEGACY, 229, &adev->crtc_irq);
if (r)
return r;
adev->ddev->max_vblank_count = 0;
adev->ddev->mode_config.funcs = &amdgpu_mode_funcs;
adev->ddev->mode_config.max_width = 16384;
adev->ddev->mode_config.max_height = 16384;
adev->ddev->mode_config.preferred_depth = 24;
adev->ddev->mode_config.prefer_shadow = 1;
adev->ddev->mode_config.fb_base = adev->mc.aper_base;
r = amdgpu_modeset_create_props(adev);
if (r)
return r;
adev->ddev->mode_config.max_width = 16384;
adev->ddev->mode_config.max_height = 16384;
for (i = 0; i < adev->mode_info.num_crtc; i++) {
r = dce_virtual_crtc_init(adev, i);
if (r)
return r;
r = dce_virtual_connector_encoder_init(adev, i);
if (r)
return r;
}
drm_kms_helper_poll_init(adev->ddev);
adev->mode_info.mode_config_initialized = true;
return 0;
}
static int dce_virtual_sw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
kfree(adev->mode_info.bios_hardcoded_edid);
drm_kms_helper_poll_fini(adev->ddev);
drm_mode_config_cleanup(adev->ddev);
adev->mode_info.mode_config_initialized = false;
return 0;
}
static int dce_virtual_hw_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
switch (adev->asic_type) {
#ifdef CONFIG_DRM_AMDGPU_SI
case CHIP_TAHITI:
case CHIP_PITCAIRN:
case CHIP_VERDE:
case CHIP_OLAND:
dce_v6_0_disable_dce(adev);
break;
#endif
#ifdef CONFIG_DRM_AMDGPU_CIK
case CHIP_BONAIRE:
case CHIP_HAWAII:
case CHIP_KAVERI:
case CHIP_KABINI:
case CHIP_MULLINS:
dce_v8_0_disable_dce(adev);
break;
#endif
case CHIP_FIJI:
case CHIP_TONGA:
dce_v10_0_disable_dce(adev);
break;
case CHIP_CARRIZO:
case CHIP_STONEY:
case CHIP_POLARIS11:
case CHIP_POLARIS10:
dce_v11_0_disable_dce(adev);
break;
case CHIP_TOPAZ:
#ifdef CONFIG_DRM_AMDGPU_SI
case CHIP_HAINAN:
#endif
break;
case CHIP_VEGA10:
break;
default:
DRM_ERROR("Virtual display unsupported ASIC type: 0x%X\n", adev->asic_type);
}
return 0;
}
static int dce_virtual_hw_fini(void *handle)
{
return 0;
}
static int dce_virtual_suspend(void *handle)
{
return dce_virtual_hw_fini(handle);
}
static int dce_virtual_resume(void *handle)
{
return dce_virtual_hw_init(handle);
}
static bool dce_virtual_is_idle(void *handle)
{
return true;
}
static int dce_virtual_wait_for_idle(void *handle)
{
return 0;
}
static int dce_virtual_soft_reset(void *handle)
{
return 0;
}
static int dce_virtual_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int dce_virtual_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static void dce_virtual_encoder_prepare(struct drm_encoder *encoder)
{
return;
}
static void dce_virtual_encoder_commit(struct drm_encoder *encoder)
{
return;
}
static void
dce_virtual_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return;
}
static void dce_virtual_encoder_disable(struct drm_encoder *encoder)
{
return;
}
static void
dce_virtual_encoder_dpms(struct drm_encoder *encoder, int mode)
{
return;
}
static bool dce_virtual_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void dce_virtual_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
kfree(encoder);
}
static int dce_virtual_connector_encoder_init(struct amdgpu_device *adev,
int index)
{
struct drm_encoder *encoder;
struct drm_connector *connector;
encoder = kzalloc(sizeof(struct drm_encoder), GFP_KERNEL);
if (!encoder)
return -ENOMEM;
encoder->possible_crtcs = 1 << index;
drm_encoder_init(adev->ddev, encoder, &dce_virtual_encoder_funcs,
DRM_MODE_ENCODER_VIRTUAL, NULL);
drm_encoder_helper_add(encoder, &dce_virtual_encoder_helper_funcs);
connector = kzalloc(sizeof(struct drm_connector), GFP_KERNEL);
if (!connector) {
kfree(encoder);
return -ENOMEM;
}
drm_connector_init(adev->ddev, connector, &dce_virtual_connector_funcs,
DRM_MODE_CONNECTOR_VIRTUAL);
drm_connector_helper_add(connector, &dce_virtual_connector_helper_funcs);
connector->display_info.subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
drm_connector_register(connector);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
static void dce_virtual_set_display_funcs(struct amdgpu_device *adev)
{
if (adev->mode_info.funcs == NULL)
adev->mode_info.funcs = &dce_virtual_display_funcs;
}
static int dce_virtual_pageflip(struct amdgpu_device *adev,
unsigned crtc_id)
{
unsigned long flags;
struct amdgpu_crtc *amdgpu_crtc;
struct amdgpu_flip_work *works;
amdgpu_crtc = adev->mode_info.crtcs[crtc_id];
if (crtc_id >= adev->mode_info.num_crtc) {
DRM_ERROR("invalid pageflip crtc %d\n", crtc_id);
return -EINVAL;
}
if (amdgpu_crtc == NULL)
return 0;
spin_lock_irqsave(&adev->ddev->event_lock, flags);
works = amdgpu_crtc->pflip_works;
if (amdgpu_crtc->pflip_status != AMDGPU_FLIP_SUBMITTED) {
DRM_DEBUG_DRIVER("amdgpu_crtc->pflip_status = %d != "
"AMDGPU_FLIP_SUBMITTED(%d)\n",
amdgpu_crtc->pflip_status,
AMDGPU_FLIP_SUBMITTED);
spin_unlock_irqrestore(&adev->ddev->event_lock, flags);
return 0;
}
amdgpu_crtc->pflip_status = AMDGPU_FLIP_NONE;
amdgpu_crtc->pflip_works = NULL;
if (works->event)
drm_crtc_send_vblank_event(&amdgpu_crtc->base, works->event);
spin_unlock_irqrestore(&adev->ddev->event_lock, flags);
drm_crtc_vblank_put(&amdgpu_crtc->base);
schedule_work(&works->unpin_work);
return 0;
}
static enum hrtimer_restart dce_virtual_vblank_timer_handle(struct hrtimer *vblank_timer)
{
struct amdgpu_crtc *amdgpu_crtc = container_of(vblank_timer,
struct amdgpu_crtc, vblank_timer);
struct drm_device *ddev = amdgpu_crtc->base.dev;
struct amdgpu_device *adev = ddev->dev_private;
drm_handle_vblank(ddev, amdgpu_crtc->crtc_id);
dce_virtual_pageflip(adev, amdgpu_crtc->crtc_id);
hrtimer_start(vblank_timer, DCE_VIRTUAL_VBLANK_PERIOD,
HRTIMER_MODE_REL);
return HRTIMER_NORESTART;
}
static void dce_virtual_set_crtc_vblank_interrupt_state(struct amdgpu_device *adev,
int crtc,
enum amdgpu_interrupt_state state)
{
if (crtc >= adev->mode_info.num_crtc) {
DRM_DEBUG("invalid crtc %d\n", crtc);
return;
}
if (state && !adev->mode_info.crtcs[crtc]->vsync_timer_enabled) {
DRM_DEBUG("Enable software vsync timer\n");
hrtimer_init(&adev->mode_info.crtcs[crtc]->vblank_timer,
CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hrtimer_set_expires(&adev->mode_info.crtcs[crtc]->vblank_timer,
DCE_VIRTUAL_VBLANK_PERIOD);
adev->mode_info.crtcs[crtc]->vblank_timer.function =
dce_virtual_vblank_timer_handle;
hrtimer_start(&adev->mode_info.crtcs[crtc]->vblank_timer,
DCE_VIRTUAL_VBLANK_PERIOD, HRTIMER_MODE_REL);
} else if (!state && adev->mode_info.crtcs[crtc]->vsync_timer_enabled) {
DRM_DEBUG("Disable software vsync timer\n");
hrtimer_cancel(&adev->mode_info.crtcs[crtc]->vblank_timer);
}
adev->mode_info.crtcs[crtc]->vsync_timer_enabled = state;
DRM_DEBUG("[FM]set crtc %d vblank interrupt state %d\n", crtc, state);
}
static int dce_virtual_set_crtc_irq_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
if (type > AMDGPU_CRTC_IRQ_VBLANK6)
return -EINVAL;
dce_virtual_set_crtc_vblank_interrupt_state(adev, type, state);
return 0;
}
static void dce_virtual_set_irq_funcs(struct amdgpu_device *adev)
{
adev->crtc_irq.num_types = AMDGPU_CRTC_IRQ_VBLANK6 + 1;
adev->crtc_irq.funcs = &dce_virtual_crtc_irq_funcs;
}
