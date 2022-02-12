static void amdgpu_flip_wait_fence(struct amdgpu_device *adev,
struct fence **f)
{
struct amdgpu_fence *fence;
long r;
if (*f == NULL)
return;
fence = to_amdgpu_fence(*f);
if (fence) {
r = fence_wait(&fence->base, false);
if (r == -EDEADLK) {
up_read(&adev->exclusive_lock);
r = amdgpu_gpu_reset(adev);
down_read(&adev->exclusive_lock);
}
} else
r = fence_wait(*f, false);
if (r)
DRM_ERROR("failed to wait on page flip fence (%ld)!\n", r);
fence_put(*f);
*f = NULL;
}
static void amdgpu_flip_work_func(struct work_struct *__work)
{
struct amdgpu_flip_work *work =
container_of(__work, struct amdgpu_flip_work, flip_work);
struct amdgpu_device *adev = work->adev;
struct amdgpu_crtc *amdgpuCrtc = adev->mode_info.crtcs[work->crtc_id];
struct drm_crtc *crtc = &amdgpuCrtc->base;
unsigned long flags;
unsigned i;
down_read(&adev->exclusive_lock);
amdgpu_flip_wait_fence(adev, &work->excl);
for (i = 0; i < work->shared_count; ++i)
amdgpu_flip_wait_fence(adev, &work->shared[i]);
spin_lock_irqsave(&crtc->dev->event_lock, flags);
adev->mode_info.funcs->page_flip(adev, work->crtc_id, work->base);
amdgpuCrtc->pflip_status = AMDGPU_FLIP_SUBMITTED;
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
up_read(&adev->exclusive_lock);
}
static void amdgpu_unpin_work_func(struct work_struct *__work)
{
struct amdgpu_flip_work *work =
container_of(__work, struct amdgpu_flip_work, unpin_work);
int r;
r = amdgpu_bo_reserve(work->old_rbo, false);
if (likely(r == 0)) {
r = amdgpu_bo_unpin(work->old_rbo);
if (unlikely(r != 0)) {
DRM_ERROR("failed to unpin buffer after flip\n");
}
amdgpu_bo_unreserve(work->old_rbo);
} else
DRM_ERROR("failed to reserve buffer after flip\n");
drm_gem_object_unreference_unlocked(&work->old_rbo->gem_base);
kfree(work->shared);
kfree(work);
}
int amdgpu_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct drm_device *dev = crtc->dev;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
struct amdgpu_framebuffer *old_amdgpu_fb;
struct amdgpu_framebuffer *new_amdgpu_fb;
struct drm_gem_object *obj;
struct amdgpu_flip_work *work;
struct amdgpu_bo *new_rbo;
unsigned long flags;
u64 tiling_flags;
u64 base;
int i, r;
work = kzalloc(sizeof *work, GFP_KERNEL);
if (work == NULL)
return -ENOMEM;
INIT_WORK(&work->flip_work, amdgpu_flip_work_func);
INIT_WORK(&work->unpin_work, amdgpu_unpin_work_func);
work->event = event;
work->adev = adev;
work->crtc_id = amdgpu_crtc->crtc_id;
old_amdgpu_fb = to_amdgpu_framebuffer(crtc->primary->fb);
obj = old_amdgpu_fb->obj;
drm_gem_object_reference(obj);
work->old_rbo = gem_to_amdgpu_bo(obj);
new_amdgpu_fb = to_amdgpu_framebuffer(fb);
obj = new_amdgpu_fb->obj;
new_rbo = gem_to_amdgpu_bo(obj);
r = amdgpu_bo_reserve(new_rbo, false);
if (unlikely(r != 0)) {
DRM_ERROR("failed to reserve new rbo buffer before flip\n");
goto cleanup;
}
r = amdgpu_bo_pin_restricted(new_rbo, AMDGPU_GEM_DOMAIN_VRAM, 0, 0, &base);
if (unlikely(r != 0)) {
amdgpu_bo_unreserve(new_rbo);
r = -EINVAL;
DRM_ERROR("failed to pin new rbo buffer before flip\n");
goto cleanup;
}
r = reservation_object_get_fences_rcu(new_rbo->tbo.resv, &work->excl,
&work->shared_count,
&work->shared);
if (unlikely(r != 0)) {
amdgpu_bo_unreserve(new_rbo);
DRM_ERROR("failed to get fences for buffer\n");
goto cleanup;
}
amdgpu_bo_get_tiling_flags(new_rbo, &tiling_flags);
amdgpu_bo_unreserve(new_rbo);
work->base = base;
r = drm_vblank_get(crtc->dev, amdgpu_crtc->crtc_id);
if (r) {
DRM_ERROR("failed to get vblank before flip\n");
goto pflip_cleanup;
}
spin_lock_irqsave(&crtc->dev->event_lock, flags);
if (amdgpu_crtc->pflip_status != AMDGPU_FLIP_NONE) {
DRM_DEBUG_DRIVER("flip queue: crtc already busy\n");
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
r = -EBUSY;
goto vblank_cleanup;
}
amdgpu_crtc->pflip_status = AMDGPU_FLIP_PENDING;
amdgpu_crtc->pflip_works = work;
crtc->primary->fb = fb;
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
queue_work(amdgpu_crtc->pflip_queue, &work->flip_work);
return 0;
vblank_cleanup:
drm_vblank_put(crtc->dev, amdgpu_crtc->crtc_id);
pflip_cleanup:
if (unlikely(amdgpu_bo_reserve(new_rbo, false) != 0)) {
DRM_ERROR("failed to reserve new rbo in error path\n");
goto cleanup;
}
if (unlikely(amdgpu_bo_unpin(new_rbo) != 0)) {
DRM_ERROR("failed to unpin new rbo in error path\n");
}
amdgpu_bo_unreserve(new_rbo);
cleanup:
drm_gem_object_unreference_unlocked(&work->old_rbo->gem_base);
fence_put(work->excl);
for (i = 0; i < work->shared_count; ++i)
fence_put(work->shared[i]);
kfree(work->shared);
kfree(work);
return r;
}
int amdgpu_crtc_set_config(struct drm_mode_set *set)
{
struct drm_device *dev;
struct amdgpu_device *adev;
struct drm_crtc *crtc;
bool active = false;
int ret;
if (!set || !set->crtc)
return -EINVAL;
dev = set->crtc->dev;
ret = pm_runtime_get_sync(dev->dev);
if (ret < 0)
return ret;
ret = drm_crtc_helper_set_config(set);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
if (crtc->enabled)
active = true;
pm_runtime_mark_last_busy(dev->dev);
adev = dev->dev_private;
if (active && !adev->have_disp_power_ref) {
adev->have_disp_power_ref = true;
return ret;
}
if (!active && adev->have_disp_power_ref) {
pm_runtime_put_autosuspend(dev->dev);
adev->have_disp_power_ref = false;
}
pm_runtime_put_autosuspend(dev->dev);
return ret;
}
void amdgpu_print_display_setup(struct drm_device *dev)
{
struct drm_connector *connector;
struct amdgpu_connector *amdgpu_connector;
struct drm_encoder *encoder;
struct amdgpu_encoder *amdgpu_encoder;
uint32_t devices;
int i = 0;
DRM_INFO("AMDGPU Display Connectors\n");
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
amdgpu_connector = to_amdgpu_connector(connector);
DRM_INFO("Connector %d:\n", i);
DRM_INFO(" %s\n", connector->name);
if (amdgpu_connector->hpd.hpd != AMDGPU_HPD_NONE)
DRM_INFO(" %s\n", hpd_names[amdgpu_connector->hpd.hpd]);
if (amdgpu_connector->ddc_bus) {
DRM_INFO(" DDC: 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",
amdgpu_connector->ddc_bus->rec.mask_clk_reg,
amdgpu_connector->ddc_bus->rec.mask_data_reg,
amdgpu_connector->ddc_bus->rec.a_clk_reg,
amdgpu_connector->ddc_bus->rec.a_data_reg,
amdgpu_connector->ddc_bus->rec.en_clk_reg,
amdgpu_connector->ddc_bus->rec.en_data_reg,
amdgpu_connector->ddc_bus->rec.y_clk_reg,
amdgpu_connector->ddc_bus->rec.y_data_reg);
if (amdgpu_connector->router.ddc_valid)
DRM_INFO(" DDC Router 0x%x/0x%x\n",
amdgpu_connector->router.ddc_mux_control_pin,
amdgpu_connector->router.ddc_mux_state);
if (amdgpu_connector->router.cd_valid)
DRM_INFO(" Clock/Data Router 0x%x/0x%x\n",
amdgpu_connector->router.cd_mux_control_pin,
amdgpu_connector->router.cd_mux_state);
} else {
if (connector->connector_type == DRM_MODE_CONNECTOR_VGA ||
connector->connector_type == DRM_MODE_CONNECTOR_DVII ||
connector->connector_type == DRM_MODE_CONNECTOR_DVID ||
connector->connector_type == DRM_MODE_CONNECTOR_DVIA ||
connector->connector_type == DRM_MODE_CONNECTOR_HDMIA ||
connector->connector_type == DRM_MODE_CONNECTOR_HDMIB)
DRM_INFO(" DDC: no ddc bus - possible BIOS bug - please report to xorg-driver-ati@lists.x.org\n");
}
DRM_INFO(" Encoders:\n");
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
amdgpu_encoder = to_amdgpu_encoder(encoder);
devices = amdgpu_encoder->devices & amdgpu_connector->devices;
if (devices) {
if (devices & ATOM_DEVICE_CRT1_SUPPORT)
DRM_INFO(" CRT1: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_CRT2_SUPPORT)
DRM_INFO(" CRT2: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_LCD1_SUPPORT)
DRM_INFO(" LCD1: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_DFP1_SUPPORT)
DRM_INFO(" DFP1: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_DFP2_SUPPORT)
DRM_INFO(" DFP2: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_DFP3_SUPPORT)
DRM_INFO(" DFP3: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_DFP4_SUPPORT)
DRM_INFO(" DFP4: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_DFP5_SUPPORT)
DRM_INFO(" DFP5: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_DFP6_SUPPORT)
DRM_INFO(" DFP6: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_TV1_SUPPORT)
DRM_INFO(" TV1: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
if (devices & ATOM_DEVICE_CV_SUPPORT)
DRM_INFO(" CV: %s\n", encoder_names[amdgpu_encoder->encoder_id]);
}
}
i++;
}
}
bool amdgpu_ddc_probe(struct amdgpu_connector *amdgpu_connector,
bool use_aux)
{
u8 out = 0x0;
u8 buf[8];
int ret;
struct i2c_msg msgs[] = {
{
.addr = DDC_ADDR,
.flags = 0,
.len = 1,
.buf = &out,
},
{
.addr = DDC_ADDR,
.flags = I2C_M_RD,
.len = 8,
.buf = buf,
}
};
if (amdgpu_connector->router.ddc_valid)
amdgpu_i2c_router_select_ddc_port(amdgpu_connector);
if (use_aux) {
ret = i2c_transfer(&amdgpu_connector->ddc_bus->aux.ddc, msgs, 2);
} else {
ret = i2c_transfer(&amdgpu_connector->ddc_bus->adapter, msgs, 2);
}
if (ret != 2)
return false;
if (drm_edid_header_is_valid(buf) < 6) {
return false;
}
return true;
}
static void amdgpu_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct amdgpu_framebuffer *amdgpu_fb = to_amdgpu_framebuffer(fb);
if (amdgpu_fb->obj) {
drm_gem_object_unreference_unlocked(amdgpu_fb->obj);
}
drm_framebuffer_cleanup(fb);
kfree(amdgpu_fb);
}
static int amdgpu_user_framebuffer_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct amdgpu_framebuffer *amdgpu_fb = to_amdgpu_framebuffer(fb);
return drm_gem_handle_create(file_priv, amdgpu_fb->obj, handle);
}
int
amdgpu_framebuffer_init(struct drm_device *dev,
struct amdgpu_framebuffer *rfb,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object *obj)
{
int ret;
rfb->obj = obj;
drm_helper_mode_fill_fb_struct(&rfb->base, mode_cmd);
ret = drm_framebuffer_init(dev, &rfb->base, &amdgpu_fb_funcs);
if (ret) {
rfb->obj = NULL;
return ret;
}
return 0;
}
static struct drm_framebuffer *
amdgpu_user_framebuffer_create(struct drm_device *dev,
struct drm_file *file_priv,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj;
struct amdgpu_framebuffer *amdgpu_fb;
int ret;
obj = drm_gem_object_lookup(dev, file_priv, mode_cmd->handles[0]);
if (obj == NULL) {
dev_err(&dev->pdev->dev, "No GEM object associated to handle 0x%08X, "
"can't create framebuffer\n", mode_cmd->handles[0]);
return ERR_PTR(-ENOENT);
}
amdgpu_fb = kzalloc(sizeof(*amdgpu_fb), GFP_KERNEL);
if (amdgpu_fb == NULL) {
drm_gem_object_unreference_unlocked(obj);
return ERR_PTR(-ENOMEM);
}
ret = amdgpu_framebuffer_init(dev, amdgpu_fb, mode_cmd, obj);
if (ret) {
kfree(amdgpu_fb);
drm_gem_object_unreference_unlocked(obj);
return ERR_PTR(ret);
}
return &amdgpu_fb->base;
}
static void amdgpu_output_poll_changed(struct drm_device *dev)
{
struct amdgpu_device *adev = dev->dev_private;
amdgpu_fb_output_poll_changed(adev);
}
int amdgpu_modeset_create_props(struct amdgpu_device *adev)
{
int sz;
if (adev->is_atom_bios) {
adev->mode_info.coherent_mode_property =
drm_property_create_range(adev->ddev, 0 , "coherent", 0, 1);
if (!adev->mode_info.coherent_mode_property)
return -ENOMEM;
}
adev->mode_info.load_detect_property =
drm_property_create_range(adev->ddev, 0, "load detection", 0, 1);
if (!adev->mode_info.load_detect_property)
return -ENOMEM;
drm_mode_create_scaling_mode_property(adev->ddev);
sz = ARRAY_SIZE(amdgpu_underscan_enum_list);
adev->mode_info.underscan_property =
drm_property_create_enum(adev->ddev, 0,
"underscan",
amdgpu_underscan_enum_list, sz);
adev->mode_info.underscan_hborder_property =
drm_property_create_range(adev->ddev, 0,
"underscan hborder", 0, 128);
if (!adev->mode_info.underscan_hborder_property)
return -ENOMEM;
adev->mode_info.underscan_vborder_property =
drm_property_create_range(adev->ddev, 0,
"underscan vborder", 0, 128);
if (!adev->mode_info.underscan_vborder_property)
return -ENOMEM;
sz = ARRAY_SIZE(amdgpu_audio_enum_list);
adev->mode_info.audio_property =
drm_property_create_enum(adev->ddev, 0,
"audio",
amdgpu_audio_enum_list, sz);
sz = ARRAY_SIZE(amdgpu_dither_enum_list);
adev->mode_info.dither_property =
drm_property_create_enum(adev->ddev, 0,
"dither",
amdgpu_dither_enum_list, sz);
return 0;
}
void amdgpu_update_display_priority(struct amdgpu_device *adev)
{
if ((amdgpu_disp_priority == 0) || (amdgpu_disp_priority > 2))
adev->mode_info.disp_priority = 0;
else
adev->mode_info.disp_priority = amdgpu_disp_priority;
}
static bool is_hdtv_mode(const struct drm_display_mode *mode)
{
if ((mode->vdisplay == 480 && mode->hdisplay == 720) ||
(mode->vdisplay == 576) ||
(mode->vdisplay == 720) ||
(mode->vdisplay == 1080))
return true;
else
return false;
}
bool amdgpu_crtc_scaling_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = crtc->dev;
struct drm_encoder *encoder;
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
struct amdgpu_encoder *amdgpu_encoder;
struct drm_connector *connector;
struct amdgpu_connector *amdgpu_connector;
u32 src_v = 1, dst_v = 1;
u32 src_h = 1, dst_h = 1;
amdgpu_crtc->h_border = 0;
amdgpu_crtc->v_border = 0;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
if (encoder->crtc != crtc)
continue;
amdgpu_encoder = to_amdgpu_encoder(encoder);
connector = amdgpu_get_connector_for_encoder(encoder);
amdgpu_connector = to_amdgpu_connector(connector);
if (amdgpu_encoder->rmx_type == RMX_OFF)
amdgpu_crtc->rmx_type = RMX_OFF;
else if (mode->hdisplay < amdgpu_encoder->native_mode.hdisplay ||
mode->vdisplay < amdgpu_encoder->native_mode.vdisplay)
amdgpu_crtc->rmx_type = amdgpu_encoder->rmx_type;
else
amdgpu_crtc->rmx_type = RMX_OFF;
memcpy(&amdgpu_crtc->native_mode,
&amdgpu_encoder->native_mode,
sizeof(struct drm_display_mode));
src_v = crtc->mode.vdisplay;
dst_v = amdgpu_crtc->native_mode.vdisplay;
src_h = crtc->mode.hdisplay;
dst_h = amdgpu_crtc->native_mode.hdisplay;
if ((!(mode->flags & DRM_MODE_FLAG_INTERLACE)) &&
((amdgpu_encoder->underscan_type == UNDERSCAN_ON) ||
((amdgpu_encoder->underscan_type == UNDERSCAN_AUTO) &&
drm_detect_hdmi_monitor(amdgpu_connector_edid(connector)) &&
is_hdtv_mode(mode)))) {
if (amdgpu_encoder->underscan_hborder != 0)
amdgpu_crtc->h_border = amdgpu_encoder->underscan_hborder;
else
amdgpu_crtc->h_border = (mode->hdisplay >> 5) + 16;
if (amdgpu_encoder->underscan_vborder != 0)
amdgpu_crtc->v_border = amdgpu_encoder->underscan_vborder;
else
amdgpu_crtc->v_border = (mode->vdisplay >> 5) + 16;
amdgpu_crtc->rmx_type = RMX_FULL;
src_v = crtc->mode.vdisplay;
dst_v = crtc->mode.vdisplay - (amdgpu_crtc->v_border * 2);
src_h = crtc->mode.hdisplay;
dst_h = crtc->mode.hdisplay - (amdgpu_crtc->h_border * 2);
}
}
if (amdgpu_crtc->rmx_type != RMX_OFF) {
fixed20_12 a, b;
a.full = dfixed_const(src_v);
b.full = dfixed_const(dst_v);
amdgpu_crtc->vsc.full = dfixed_div(a, b);
a.full = dfixed_const(src_h);
b.full = dfixed_const(dst_h);
amdgpu_crtc->hsc.full = dfixed_div(a, b);
} else {
amdgpu_crtc->vsc.full = dfixed_const(1);
amdgpu_crtc->hsc.full = dfixed_const(1);
}
return true;
}
int amdgpu_get_crtc_scanoutpos(struct drm_device *dev, int crtc, unsigned int flags,
int *vpos, int *hpos, ktime_t *stime, ktime_t *etime)
{
u32 vbl = 0, position = 0;
int vbl_start, vbl_end, vtotal, ret = 0;
bool in_vbl = true;
struct amdgpu_device *adev = dev->dev_private;
if (stime)
*stime = ktime_get();
if (amdgpu_display_page_flip_get_scanoutpos(adev, crtc, &vbl, &position) == 0)
ret |= DRM_SCANOUTPOS_VALID;
if (etime)
*etime = ktime_get();
*vpos = position & 0x1fff;
*hpos = (position >> 16) & 0x1fff;
if (vbl > 0) {
ret |= DRM_SCANOUTPOS_ACCURATE;
vbl_start = vbl & 0x1fff;
vbl_end = (vbl >> 16) & 0x1fff;
}
else {
vbl_start = adev->mode_info.crtcs[crtc]->base.hwmode.crtc_vdisplay;
vbl_end = 0;
}
if ((*vpos < vbl_start) && (*vpos >= vbl_end))
in_vbl = false;
if (in_vbl && (*vpos >= vbl_start)) {
vtotal = adev->mode_info.crtcs[crtc]->base.hwmode.crtc_vtotal;
*vpos = *vpos - vtotal;
}
*vpos = *vpos - vbl_end;
if (in_vbl)
ret |= DRM_SCANOUTPOS_IN_VBLANK;
if ((flags & DRM_CALLED_FROM_VBLIRQ) && !in_vbl) {
vbl_start = adev->mode_info.crtcs[crtc]->base.hwmode.crtc_vdisplay;
vtotal = adev->mode_info.crtcs[crtc]->base.hwmode.crtc_vtotal;
if (vbl_start - *vpos < vtotal / 100) {
*vpos -= vtotal;
ret |= 0x8;
}
}
return ret;
}
int amdgpu_crtc_idx_to_irq_type(struct amdgpu_device *adev, int crtc)
{
if (crtc < 0 || crtc >= adev->mode_info.num_crtc)
return AMDGPU_CRTC_IRQ_NONE;
switch (crtc) {
case 0:
return AMDGPU_CRTC_IRQ_VBLANK1;
case 1:
return AMDGPU_CRTC_IRQ_VBLANK2;
case 2:
return AMDGPU_CRTC_IRQ_VBLANK3;
case 3:
return AMDGPU_CRTC_IRQ_VBLANK4;
case 4:
return AMDGPU_CRTC_IRQ_VBLANK5;
case 5:
return AMDGPU_CRTC_IRQ_VBLANK6;
default:
return AMDGPU_CRTC_IRQ_NONE;
}
}
