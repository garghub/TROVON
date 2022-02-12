static inline struct vc4_crtc *
to_vc4_crtc(struct drm_crtc *crtc)
{
return (struct vc4_crtc *)crtc;
}
static inline struct vc4_crtc_state *
to_vc4_crtc_state(struct drm_crtc_state *crtc_state)
{
return (struct vc4_crtc_state *)crtc_state;
}
static void vc4_crtc_dump_regs(struct vc4_crtc *vc4_crtc)
{
int i;
for (i = 0; i < ARRAY_SIZE(crtc_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
crtc_regs[i].reg, crtc_regs[i].name,
CRTC_READ(crtc_regs[i].reg));
}
}
int vc4_crtc_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
int crtc_index = (uintptr_t)node->info_ent->data;
struct drm_crtc *crtc;
struct vc4_crtc *vc4_crtc;
int i;
i = 0;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (i == crtc_index)
break;
i++;
}
if (!crtc)
return 0;
vc4_crtc = to_vc4_crtc(crtc);
for (i = 0; i < ARRAY_SIZE(crtc_regs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
crtc_regs[i].name, crtc_regs[i].reg,
CRTC_READ(crtc_regs[i].reg));
}
return 0;
}
static void vc4_crtc_destroy(struct drm_crtc *crtc)
{
drm_crtc_cleanup(crtc);
}
static u32 vc4_get_fifo_full_level(u32 format)
{
static const u32 fifo_len_bytes = 64;
static const u32 hvs_latency_pix = 6;
switch (format) {
case PV_CONTROL_FORMAT_DSIV_16:
case PV_CONTROL_FORMAT_DSIC_16:
return fifo_len_bytes - 2 * hvs_latency_pix;
case PV_CONTROL_FORMAT_DSIV_18:
return fifo_len_bytes - 14;
case PV_CONTROL_FORMAT_24:
case PV_CONTROL_FORMAT_DSIV_24:
default:
return fifo_len_bytes - 3 * hvs_latency_pix;
}
}
static int vc4_get_clock_select(struct drm_crtc *crtc)
{
struct drm_connector *connector;
drm_for_each_connector(connector, crtc->dev) {
if (connector->state->crtc == crtc) {
struct drm_encoder *encoder = connector->encoder;
struct vc4_encoder *vc4_encoder =
to_vc4_encoder(encoder);
return vc4_encoder->clock_select;
}
}
return -1;
}
static void vc4_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_crtc *vc4_crtc = to_vc4_crtc(crtc);
struct drm_crtc_state *state = crtc->state;
struct drm_display_mode *mode = &state->adjusted_mode;
bool interlace = mode->flags & DRM_MODE_FLAG_INTERLACE;
u32 vactive = (mode->vdisplay >> (interlace ? 1 : 0));
u32 format = PV_CONTROL_FORMAT_24;
bool debug_dump_regs = false;
int clock_select = vc4_get_clock_select(crtc);
if (debug_dump_regs) {
DRM_INFO("CRTC %d regs before:\n", drm_crtc_index(crtc));
vc4_crtc_dump_regs(vc4_crtc);
}
CRTC_WRITE(PV_CONTROL, 0);
CRTC_WRITE(PV_CONTROL, PV_CONTROL_FIFO_CLR | PV_CONTROL_EN);
CRTC_WRITE(PV_CONTROL, 0);
CRTC_WRITE(PV_HORZA,
VC4_SET_FIELD(mode->htotal - mode->hsync_end,
PV_HORZA_HBP) |
VC4_SET_FIELD(mode->hsync_end - mode->hsync_start,
PV_HORZA_HSYNC));
CRTC_WRITE(PV_HORZB,
VC4_SET_FIELD(mode->hsync_start - mode->hdisplay,
PV_HORZB_HFP) |
VC4_SET_FIELD(mode->hdisplay, PV_HORZB_HACTIVE));
CRTC_WRITE(PV_VERTA,
VC4_SET_FIELD(mode->vtotal - mode->vsync_end,
PV_VERTA_VBP) |
VC4_SET_FIELD(mode->vsync_end - mode->vsync_start,
PV_VERTA_VSYNC));
CRTC_WRITE(PV_VERTB,
VC4_SET_FIELD(mode->vsync_start - mode->vdisplay,
PV_VERTB_VFP) |
VC4_SET_FIELD(vactive, PV_VERTB_VACTIVE));
if (interlace) {
CRTC_WRITE(PV_VERTA_EVEN,
VC4_SET_FIELD(mode->vtotal - mode->vsync_end - 1,
PV_VERTA_VBP) |
VC4_SET_FIELD(mode->vsync_end - mode->vsync_start,
PV_VERTA_VSYNC));
CRTC_WRITE(PV_VERTB_EVEN,
VC4_SET_FIELD(mode->vsync_start - mode->vdisplay,
PV_VERTB_VFP) |
VC4_SET_FIELD(vactive, PV_VERTB_VACTIVE));
}
CRTC_WRITE(PV_HACT_ACT, mode->hdisplay);
CRTC_WRITE(PV_V_CONTROL,
PV_VCONTROL_CONTINUOUS |
(interlace ? PV_VCONTROL_INTERLACE : 0));
CRTC_WRITE(PV_CONTROL,
VC4_SET_FIELD(format, PV_CONTROL_FORMAT) |
VC4_SET_FIELD(vc4_get_fifo_full_level(format),
PV_CONTROL_FIFO_LEVEL) |
PV_CONTROL_CLR_AT_START |
PV_CONTROL_TRIGGER_UNDERFLOW |
PV_CONTROL_WAIT_HSTART |
VC4_SET_FIELD(clock_select, PV_CONTROL_CLK_SELECT) |
PV_CONTROL_FIFO_CLR |
PV_CONTROL_EN);
HVS_WRITE(SCALER_DISPBKGNDX(vc4_crtc->channel),
SCALER_DISPBKGND_AUTOHS |
(interlace ? SCALER_DISPBKGND_INTERLACE : 0));
if (debug_dump_regs) {
DRM_INFO("CRTC %d regs after:\n", drm_crtc_index(crtc));
vc4_crtc_dump_regs(vc4_crtc);
}
}
static void require_hvs_enabled(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
WARN_ON_ONCE((HVS_READ(SCALER_DISPCTRL) & SCALER_DISPCTRL_ENABLE) !=
SCALER_DISPCTRL_ENABLE);
}
static void vc4_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_crtc *vc4_crtc = to_vc4_crtc(crtc);
u32 chan = vc4_crtc->channel;
int ret;
require_hvs_enabled(dev);
CRTC_WRITE(PV_V_CONTROL,
CRTC_READ(PV_V_CONTROL) & ~PV_VCONTROL_VIDEN);
ret = wait_for(!(CRTC_READ(PV_V_CONTROL) & PV_VCONTROL_VIDEN), 1);
WARN_ONCE(ret, "Timeout waiting for !PV_VCONTROL_VIDEN\n");
if (HVS_READ(SCALER_DISPCTRLX(chan)) &
SCALER_DISPCTRLX_ENABLE) {
HVS_WRITE(SCALER_DISPCTRLX(chan),
SCALER_DISPCTRLX_RESET);
HVS_WRITE(SCALER_DISPCTRLX(chan), 0);
}
WARN_ON_ONCE(HVS_READ(SCALER_DISPCTRLX(chan)) & SCALER_DISPCTRLX_RESET);
WARN_ON_ONCE(VC4_GET_FIELD(HVS_READ(SCALER_DISPSTATX(chan)),
SCALER_DISPSTATX_MODE) !=
SCALER_DISPSTATX_MODE_DISABLED);
WARN_ON_ONCE((HVS_READ(SCALER_DISPSTATX(chan)) &
(SCALER_DISPSTATX_FULL | SCALER_DISPSTATX_EMPTY)) !=
SCALER_DISPSTATX_EMPTY);
}
static void vc4_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_crtc *vc4_crtc = to_vc4_crtc(crtc);
struct drm_crtc_state *state = crtc->state;
struct drm_display_mode *mode = &state->adjusted_mode;
require_hvs_enabled(dev);
HVS_WRITE(SCALER_DISPCTRLX(vc4_crtc->channel),
VC4_SET_FIELD(mode->hdisplay, SCALER_DISPCTRLX_WIDTH) |
VC4_SET_FIELD(mode->vdisplay, SCALER_DISPCTRLX_HEIGHT) |
SCALER_DISPCTRLX_ENABLE);
CRTC_WRITE(PV_V_CONTROL,
CRTC_READ(PV_V_CONTROL) | PV_VCONTROL_VIDEN);
}
static int vc4_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct vc4_crtc_state *vc4_state = to_vc4_crtc_state(state);
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct drm_plane *plane;
unsigned long flags;
u32 dlist_count = 0;
int ret;
if (hweight32(state->connector_mask) > 1)
return -EINVAL;
drm_atomic_crtc_state_for_each_plane(plane, state) {
struct drm_plane_state *plane_state =
state->state->plane_states[drm_plane_index(plane)];
if (!plane_state)
plane_state = plane->state;
dlist_count += vc4_plane_dlist_size(plane_state);
}
dlist_count++;
spin_lock_irqsave(&vc4->hvs->mm_lock, flags);
ret = drm_mm_insert_node(&vc4->hvs->dlist_mm, &vc4_state->mm,
dlist_count, 1, 0);
spin_unlock_irqrestore(&vc4->hvs->mm_lock, flags);
if (ret)
return ret;
return 0;
}
static void vc4_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_crtc *vc4_crtc = to_vc4_crtc(crtc);
struct vc4_crtc_state *vc4_state = to_vc4_crtc_state(crtc->state);
struct drm_plane *plane;
bool debug_dump_regs = false;
u32 __iomem *dlist_start = vc4->hvs->dlist + vc4_state->mm.start;
u32 __iomem *dlist_next = dlist_start;
if (debug_dump_regs) {
DRM_INFO("CRTC %d HVS before:\n", drm_crtc_index(crtc));
vc4_hvs_dump_state(dev);
}
drm_atomic_crtc_for_each_plane(plane, crtc) {
dlist_next += vc4_plane_write_dlist(plane, dlist_next);
}
writel(SCALER_CTL0_END, dlist_next);
dlist_next++;
WARN_ON_ONCE(dlist_next - dlist_start != vc4_state->mm.size);
HVS_WRITE(SCALER_DISPLISTX(vc4_crtc->channel),
vc4_state->mm.start);
if (debug_dump_regs) {
DRM_INFO("CRTC %d HVS after:\n", drm_crtc_index(crtc));
vc4_hvs_dump_state(dev);
}
if (crtc->state->event) {
unsigned long flags;
crtc->state->event->pipe = drm_crtc_index(crtc);
WARN_ON(drm_crtc_vblank_get(crtc) != 0);
spin_lock_irqsave(&dev->event_lock, flags);
vc4_crtc->event = crtc->state->event;
spin_unlock_irqrestore(&dev->event_lock, flags);
crtc->state->event = NULL;
}
}
int vc4_enable_vblank(struct drm_device *dev, unsigned int crtc_id)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_crtc *vc4_crtc = vc4->crtc[crtc_id];
CRTC_WRITE(PV_INTEN, PV_INT_VFP_START);
return 0;
}
void vc4_disable_vblank(struct drm_device *dev, unsigned int crtc_id)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_crtc *vc4_crtc = vc4->crtc[crtc_id];
CRTC_WRITE(PV_INTEN, 0);
}
static void vc4_crtc_handle_page_flip(struct vc4_crtc *vc4_crtc)
{
struct drm_crtc *crtc = &vc4_crtc->base;
struct drm_device *dev = crtc->dev;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (vc4_crtc->event) {
drm_crtc_send_vblank_event(crtc, vc4_crtc->event);
vc4_crtc->event = NULL;
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static irqreturn_t vc4_crtc_irq_handler(int irq, void *data)
{
struct vc4_crtc *vc4_crtc = data;
u32 stat = CRTC_READ(PV_INTSTAT);
irqreturn_t ret = IRQ_NONE;
if (stat & PV_INT_VFP_START) {
CRTC_WRITE(PV_INTSTAT, PV_INT_VFP_START);
drm_crtc_handle_vblank(&vc4_crtc->base);
vc4_crtc_handle_page_flip(vc4_crtc);
ret = IRQ_HANDLED;
}
return ret;
}
static void
vc4_async_page_flip_complete(struct vc4_seqno_cb *cb)
{
struct vc4_async_flip_state *flip_state =
container_of(cb, struct vc4_async_flip_state, cb);
struct drm_crtc *crtc = flip_state->crtc;
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct drm_plane *plane = crtc->primary;
vc4_plane_async_set_fb(plane, flip_state->fb);
if (flip_state->event) {
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
drm_crtc_send_vblank_event(crtc, flip_state->event);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
drm_framebuffer_unreference(flip_state->fb);
kfree(flip_state);
up(&vc4->async_modeset);
}
static int vc4_async_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t flags)
{
struct drm_device *dev = crtc->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct drm_plane *plane = crtc->primary;
int ret = 0;
struct vc4_async_flip_state *flip_state;
struct drm_gem_cma_object *cma_bo = drm_fb_cma_get_gem_obj(fb, 0);
struct vc4_bo *bo = to_vc4_bo(&cma_bo->base);
flip_state = kzalloc(sizeof(*flip_state), GFP_KERNEL);
if (!flip_state)
return -ENOMEM;
drm_framebuffer_reference(fb);
flip_state->fb = fb;
flip_state->crtc = crtc;
flip_state->event = event;
ret = down_interruptible(&vc4->async_modeset);
if (ret) {
drm_framebuffer_unreference(fb);
kfree(flip_state);
return ret;
}
drm_atomic_set_fb_for_plane(plane->state, fb);
plane->fb = fb;
vc4_queue_seqno_cb(dev, &flip_state->cb, bo->seqno,
vc4_async_page_flip_complete);
return 0;
}
static int vc4_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t flags)
{
if (flags & DRM_MODE_PAGE_FLIP_ASYNC)
return vc4_async_page_flip(crtc, fb, event, flags);
else
return drm_atomic_helper_page_flip(crtc, fb, event, flags);
}
static struct drm_crtc_state *vc4_crtc_duplicate_state(struct drm_crtc *crtc)
{
struct vc4_crtc_state *vc4_state;
vc4_state = kzalloc(sizeof(*vc4_state), GFP_KERNEL);
if (!vc4_state)
return NULL;
__drm_atomic_helper_crtc_duplicate_state(crtc, &vc4_state->base);
return &vc4_state->base;
}
static void vc4_crtc_destroy_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct vc4_dev *vc4 = to_vc4_dev(crtc->dev);
struct vc4_crtc_state *vc4_state = to_vc4_crtc_state(state);
if (vc4_state->mm.allocated) {
unsigned long flags;
spin_lock_irqsave(&vc4->hvs->mm_lock, flags);
drm_mm_remove_node(&vc4_state->mm);
spin_unlock_irqrestore(&vc4->hvs->mm_lock, flags);
}
__drm_atomic_helper_crtc_destroy_state(crtc, state);
}
static void vc4_set_crtc_possible_masks(struct drm_device *drm,
struct drm_crtc *crtc)
{
struct vc4_crtc *vc4_crtc = to_vc4_crtc(crtc);
struct drm_encoder *encoder;
drm_for_each_encoder(encoder, drm) {
struct vc4_encoder *vc4_encoder = to_vc4_encoder(encoder);
if (vc4_encoder->type == vc4_crtc->data->encoder0_type) {
vc4_encoder->clock_select = 0;
encoder->possible_crtcs |= drm_crtc_mask(crtc);
} else if (vc4_encoder->type == vc4_crtc->data->encoder1_type) {
vc4_encoder->clock_select = 1;
encoder->possible_crtcs |= drm_crtc_mask(crtc);
}
}
}
static int vc4_crtc_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_crtc *vc4_crtc;
struct drm_crtc *crtc;
struct drm_plane *primary_plane, *cursor_plane, *destroy_plane, *temp;
const struct of_device_id *match;
int ret, i;
vc4_crtc = devm_kzalloc(dev, sizeof(*vc4_crtc), GFP_KERNEL);
if (!vc4_crtc)
return -ENOMEM;
crtc = &vc4_crtc->base;
match = of_match_device(vc4_crtc_dt_match, dev);
if (!match)
return -ENODEV;
vc4_crtc->data = match->data;
vc4_crtc->regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(vc4_crtc->regs))
return PTR_ERR(vc4_crtc->regs);
primary_plane = vc4_plane_init(drm, DRM_PLANE_TYPE_PRIMARY);
if (IS_ERR(primary_plane)) {
dev_err(dev, "failed to construct primary plane\n");
ret = PTR_ERR(primary_plane);
goto err;
}
drm_crtc_init_with_planes(drm, crtc, primary_plane, NULL,
&vc4_crtc_funcs, NULL);
drm_crtc_helper_add(crtc, &vc4_crtc_helper_funcs);
primary_plane->crtc = crtc;
vc4->crtc[drm_crtc_index(crtc)] = vc4_crtc;
vc4_crtc->channel = vc4_crtc->data->hvs_channel;
for (i = 0; i < 8; i++) {
struct drm_plane *plane =
vc4_plane_init(drm, DRM_PLANE_TYPE_OVERLAY);
if (IS_ERR(plane))
continue;
plane->possible_crtcs = 1 << drm_crtc_index(crtc);
}
cursor_plane = vc4_plane_init(drm, DRM_PLANE_TYPE_CURSOR);
if (!IS_ERR(cursor_plane)) {
cursor_plane->possible_crtcs = 1 << drm_crtc_index(crtc);
cursor_plane->crtc = crtc;
crtc->cursor = cursor_plane;
}
CRTC_WRITE(PV_INTEN, 0);
CRTC_WRITE(PV_INTSTAT, PV_INT_VFP_START);
ret = devm_request_irq(dev, platform_get_irq(pdev, 0),
vc4_crtc_irq_handler, 0, "vc4 crtc", vc4_crtc);
if (ret)
goto err_destroy_planes;
vc4_set_crtc_possible_masks(drm, crtc);
platform_set_drvdata(pdev, vc4_crtc);
return 0;
err_destroy_planes:
list_for_each_entry_safe(destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if (destroy_plane->possible_crtcs == 1 << drm_crtc_index(crtc))
destroy_plane->funcs->destroy(destroy_plane);
}
err:
return ret;
}
static void vc4_crtc_unbind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct vc4_crtc *vc4_crtc = dev_get_drvdata(dev);
vc4_crtc_destroy(&vc4_crtc->base);
CRTC_WRITE(PV_INTEN, 0);
platform_set_drvdata(pdev, NULL);
}
static int vc4_crtc_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_crtc_ops);
}
static int vc4_crtc_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_crtc_ops);
return 0;
}
