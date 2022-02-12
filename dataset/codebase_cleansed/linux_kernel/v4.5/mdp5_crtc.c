static struct mdp5_kms *get_kms(struct drm_crtc *crtc)
{
struct msm_drm_private *priv = crtc->dev->dev_private;
return to_mdp5_kms(to_mdp_kms(priv->kms));
}
static void request_pending(struct drm_crtc *crtc, uint32_t pending)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
atomic_or(pending, &mdp5_crtc->pending);
mdp_irq_register(&get_kms(crtc)->base, &mdp5_crtc->vblank);
}
static void request_pp_done_pending(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
reinit_completion(&mdp5_crtc->pp_completion);
}
static u32 crtc_flush(struct drm_crtc *crtc, u32 flush_mask)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
DBG("%s: flush=%08x", mdp5_crtc->name, flush_mask);
return mdp5_ctl_commit(mdp5_crtc->ctl, flush_mask);
}
static u32 crtc_flush_all(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_plane *plane;
uint32_t flush_mask = 0;
if (WARN_ON(!mdp5_crtc->ctl))
return 0;
drm_atomic_crtc_for_each_plane(plane, crtc) {
flush_mask |= mdp5_plane_get_flush(plane);
}
flush_mask |= mdp_ctl_flush_mask_lm(mdp5_crtc->lm);
return crtc_flush(crtc, flush_mask);
}
static void complete_flip(struct drm_crtc *crtc, struct drm_file *file)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct drm_pending_vblank_event *event;
struct drm_plane *plane;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
event = mdp5_crtc->event;
if (event) {
if (!file || (event->base.file_priv == file)) {
mdp5_crtc->event = NULL;
DBG("%s: send event: %p", mdp5_crtc->name, event);
drm_send_vblank_event(dev, mdp5_crtc->id, event);
}
}
spin_unlock_irqrestore(&dev->event_lock, flags);
drm_atomic_crtc_for_each_plane(plane, crtc) {
mdp5_plane_complete_flip(plane);
}
if (mdp5_crtc->ctl && !crtc->state->enable) {
mdp5_ctl_blend(mdp5_crtc->ctl, NULL, 0, 0);
mdp5_crtc->ctl = NULL;
}
}
static void unref_cursor_worker(struct drm_flip_work *work, void *val)
{
struct mdp5_crtc *mdp5_crtc =
container_of(work, struct mdp5_crtc, unref_cursor_work);
struct mdp5_kms *mdp5_kms = get_kms(&mdp5_crtc->base);
msm_gem_put_iova(val, mdp5_kms->id);
drm_gem_object_unreference_unlocked(val);
}
static void mdp5_crtc_destroy(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
drm_crtc_cleanup(crtc);
drm_flip_work_cleanup(&mdp5_crtc->unref_cursor_work);
kfree(mdp5_crtc);
}
static bool mdp5_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void blend_setup(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
struct drm_plane *plane;
const struct mdp5_cfg_hw *hw_cfg;
struct mdp5_plane_state *pstate, *pstates[STAGE_MAX + 1] = {NULL};
const struct mdp_format *format;
uint32_t lm = mdp5_crtc->lm;
uint32_t blend_op, fg_alpha, bg_alpha, ctl_blend_flags = 0;
unsigned long flags;
uint8_t stage[STAGE_MAX + 1];
int i, plane_cnt = 0;
#define blender(stage) ((stage) - STAGE0)
hw_cfg = mdp5_cfg_get_hw_config(mdp5_kms->cfg);
spin_lock_irqsave(&mdp5_crtc->lm_lock, flags);
if (!mdp5_crtc->ctl)
goto out;
drm_atomic_crtc_for_each_plane(plane, crtc) {
pstate = to_mdp5_plane_state(plane->state);
pstates[pstate->stage] = pstate;
stage[pstate->stage] = mdp5_plane_pipe(plane);
plane_cnt++;
}
if (!pstates[STAGE_BASE] && plane_cnt) {
ctl_blend_flags |= MDP5_CTL_BLEND_OP_FLAG_BORDER_OUT;
DBG("Border Color is enabled");
}
for (i = STAGE0; i <= STAGE_MAX; i++) {
if (!pstates[i])
continue;
format = to_mdp_format(
msm_framebuffer_format(pstates[i]->base.fb));
plane = pstates[i]->base.plane;
blend_op = MDP5_LM_BLEND_OP_MODE_FG_ALPHA(FG_CONST) |
MDP5_LM_BLEND_OP_MODE_BG_ALPHA(BG_CONST);
fg_alpha = pstates[i]->alpha;
bg_alpha = 0xFF - pstates[i]->alpha;
DBG("Stage %d fg_alpha %x bg_alpha %x", i, fg_alpha, bg_alpha);
if (format->alpha_enable && pstates[i]->premultiplied) {
blend_op = MDP5_LM_BLEND_OP_MODE_FG_ALPHA(FG_CONST) |
MDP5_LM_BLEND_OP_MODE_BG_ALPHA(FG_PIXEL);
if (fg_alpha != 0xff) {
bg_alpha = fg_alpha;
blend_op |=
MDP5_LM_BLEND_OP_MODE_BG_MOD_ALPHA |
MDP5_LM_BLEND_OP_MODE_BG_INV_MOD_ALPHA;
} else {
blend_op |= MDP5_LM_BLEND_OP_MODE_BG_INV_ALPHA;
}
} else if (format->alpha_enable) {
blend_op = MDP5_LM_BLEND_OP_MODE_FG_ALPHA(FG_PIXEL) |
MDP5_LM_BLEND_OP_MODE_BG_ALPHA(FG_PIXEL);
if (fg_alpha != 0xff) {
bg_alpha = fg_alpha;
blend_op |=
MDP5_LM_BLEND_OP_MODE_FG_MOD_ALPHA |
MDP5_LM_BLEND_OP_MODE_FG_INV_MOD_ALPHA |
MDP5_LM_BLEND_OP_MODE_BG_MOD_ALPHA |
MDP5_LM_BLEND_OP_MODE_BG_INV_MOD_ALPHA;
} else {
blend_op |= MDP5_LM_BLEND_OP_MODE_BG_INV_ALPHA;
}
}
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_OP_MODE(lm,
blender(i)), blend_op);
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_FG_ALPHA(lm,
blender(i)), fg_alpha);
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_BG_ALPHA(lm,
blender(i)), bg_alpha);
}
mdp5_ctl_blend(mdp5_crtc->ctl, stage, plane_cnt, ctl_blend_flags);
out:
spin_unlock_irqrestore(&mdp5_crtc->lm_lock, flags);
}
static void mdp5_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
unsigned long flags;
struct drm_display_mode *mode;
if (WARN_ON(!crtc->state))
return;
mode = &crtc->state->adjusted_mode;
DBG("%s: set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
mdp5_crtc->name, mode->base.id, mode->name,
mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start,
mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start,
mode->vsync_end, mode->vtotal,
mode->type, mode->flags);
spin_lock_irqsave(&mdp5_crtc->lm_lock, flags);
mdp5_write(mdp5_kms, REG_MDP5_LM_OUT_SIZE(mdp5_crtc->lm),
MDP5_LM_OUT_SIZE_WIDTH(mode->hdisplay) |
MDP5_LM_OUT_SIZE_HEIGHT(mode->vdisplay));
spin_unlock_irqrestore(&mdp5_crtc->lm_lock, flags);
}
static void mdp5_crtc_disable(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
DBG("%s", mdp5_crtc->name);
if (WARN_ON(!mdp5_crtc->enabled))
return;
if (mdp5_crtc->cmd_mode)
mdp_irq_unregister(&mdp5_kms->base, &mdp5_crtc->pp_done);
mdp_irq_unregister(&mdp5_kms->base, &mdp5_crtc->err);
mdp5_disable(mdp5_kms);
mdp5_crtc->enabled = false;
}
static void mdp5_crtc_enable(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
DBG("%s", mdp5_crtc->name);
if (WARN_ON(mdp5_crtc->enabled))
return;
mdp5_enable(mdp5_kms);
mdp_irq_register(&mdp5_kms->base, &mdp5_crtc->err);
if (mdp5_crtc->cmd_mode)
mdp_irq_register(&mdp5_kms->base, &mdp5_crtc->pp_done);
mdp5_crtc->enabled = true;
}
static int pstate_cmp(const void *a, const void *b)
{
struct plane_state *pa = (struct plane_state *)a;
struct plane_state *pb = (struct plane_state *)b;
return pa->state->zpos - pb->state->zpos;
}
static int mdp5_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
struct drm_plane *plane;
struct drm_device *dev = crtc->dev;
struct plane_state pstates[STAGE_MAX + 1];
const struct mdp5_cfg_hw *hw_cfg;
int cnt = 0, i;
DBG("%s: check", mdp5_crtc->name);
hw_cfg = mdp5_cfg_get_hw_config(mdp5_kms->cfg);
drm_atomic_crtc_state_for_each_plane(plane, state) {
struct drm_plane_state *pstate;
if (cnt >= (hw_cfg->lm.nb_stages)) {
dev_err(dev->dev, "too many planes!\n");
return -EINVAL;
}
pstate = state->state->plane_states[drm_plane_index(plane)];
if (!pstate)
pstate = plane->state;
pstates[cnt].plane = plane;
pstates[cnt].state = to_mdp5_plane_state(pstate);
cnt++;
}
sort(pstates, cnt, sizeof(pstates[0]), pstate_cmp, NULL);
for (i = 0; i < cnt; i++) {
pstates[i].state->stage = STAGE_BASE + i;
DBG("%s: assign pipe %s on stage=%d", mdp5_crtc->name,
pipe2name(mdp5_plane_pipe(pstates[i].plane)),
pstates[i].state->stage);
}
return 0;
}
static void mdp5_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
DBG("%s: begin", mdp5_crtc->name);
}
static void mdp5_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_device *dev = crtc->dev;
unsigned long flags;
DBG("%s: event: %p", mdp5_crtc->name, crtc->state->event);
WARN_ON(mdp5_crtc->event);
spin_lock_irqsave(&dev->event_lock, flags);
mdp5_crtc->event = crtc->state->event;
spin_unlock_irqrestore(&dev->event_lock, flags);
if (unlikely(!mdp5_crtc->ctl))
return;
blend_setup(crtc);
if (mdp5_crtc->cmd_mode)
request_pp_done_pending(crtc);
mdp5_crtc->flushed_mask = crtc_flush_all(crtc);
request_pending(crtc, PENDING_FLIP);
}
static int mdp5_crtc_set_property(struct drm_crtc *crtc,
struct drm_property *property, uint64_t val)
{
return -EINVAL;
}
static void get_roi(struct drm_crtc *crtc, uint32_t *roi_w, uint32_t *roi_h)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
uint32_t xres = crtc->mode.hdisplay;
uint32_t yres = crtc->mode.vdisplay;
*roi_w = min(mdp5_crtc->cursor.width, xres -
mdp5_crtc->cursor.x);
*roi_h = min(mdp5_crtc->cursor.height, yres -
mdp5_crtc->cursor.y);
}
static int mdp5_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file, uint32_t handle,
uint32_t width, uint32_t height)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct mdp5_kms *mdp5_kms = get_kms(crtc);
struct drm_gem_object *cursor_bo, *old_bo = NULL;
uint32_t blendcfg, cursor_addr, stride;
int ret, bpp, lm;
unsigned int depth;
enum mdp5_cursor_alpha cur_alpha = CURSOR_ALPHA_PER_PIXEL;
uint32_t flush_mask = mdp_ctl_flush_mask_cursor(0);
uint32_t roi_w, roi_h;
bool cursor_enable = true;
unsigned long flags;
if ((width > CURSOR_WIDTH) || (height > CURSOR_HEIGHT)) {
dev_err(dev->dev, "bad cursor size: %dx%d\n", width, height);
return -EINVAL;
}
if (NULL == mdp5_crtc->ctl)
return -EINVAL;
if (!handle) {
DBG("Cursor off");
cursor_enable = false;
goto set_cursor;
}
cursor_bo = drm_gem_object_lookup(dev, file, handle);
if (!cursor_bo)
return -ENOENT;
ret = msm_gem_get_iova(cursor_bo, mdp5_kms->id, &cursor_addr);
if (ret)
return -EINVAL;
lm = mdp5_crtc->lm;
drm_fb_get_bpp_depth(DRM_FORMAT_ARGB8888, &depth, &bpp);
stride = width * (bpp >> 3);
spin_lock_irqsave(&mdp5_crtc->cursor.lock, flags);
old_bo = mdp5_crtc->cursor.scanout_bo;
mdp5_crtc->cursor.scanout_bo = cursor_bo;
mdp5_crtc->cursor.width = width;
mdp5_crtc->cursor.height = height;
get_roi(crtc, &roi_w, &roi_h);
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_STRIDE(lm), stride);
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_FORMAT(lm),
MDP5_LM_CURSOR_FORMAT_FORMAT(CURSOR_FMT_ARGB8888));
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_IMG_SIZE(lm),
MDP5_LM_CURSOR_IMG_SIZE_SRC_H(height) |
MDP5_LM_CURSOR_IMG_SIZE_SRC_W(width));
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_SIZE(lm),
MDP5_LM_CURSOR_SIZE_ROI_H(roi_h) |
MDP5_LM_CURSOR_SIZE_ROI_W(roi_w));
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_BASE_ADDR(lm), cursor_addr);
blendcfg = MDP5_LM_CURSOR_BLEND_CONFIG_BLEND_EN;
blendcfg |= MDP5_LM_CURSOR_BLEND_CONFIG_BLEND_ALPHA_SEL(cur_alpha);
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_BLEND_CONFIG(lm), blendcfg);
spin_unlock_irqrestore(&mdp5_crtc->cursor.lock, flags);
set_cursor:
ret = mdp5_ctl_set_cursor(mdp5_crtc->ctl, 0, cursor_enable);
if (ret) {
dev_err(dev->dev, "failed to %sable cursor: %d\n",
cursor_enable ? "en" : "dis", ret);
goto end;
}
crtc_flush(crtc, flush_mask);
end:
if (old_bo) {
drm_flip_work_queue(&mdp5_crtc->unref_cursor_work, old_bo);
request_pending(crtc, PENDING_CURSOR);
}
return ret;
}
static int mdp5_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct mdp5_kms *mdp5_kms = get_kms(crtc);
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
uint32_t flush_mask = mdp_ctl_flush_mask_cursor(0);
uint32_t roi_w;
uint32_t roi_h;
unsigned long flags;
if (unlikely(!crtc->state->enable))
return 0;
mdp5_crtc->cursor.x = x = max(x, 0);
mdp5_crtc->cursor.y = y = max(y, 0);
get_roi(crtc, &roi_w, &roi_h);
spin_lock_irqsave(&mdp5_crtc->cursor.lock, flags);
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_SIZE(mdp5_crtc->lm),
MDP5_LM_CURSOR_SIZE_ROI_H(roi_h) |
MDP5_LM_CURSOR_SIZE_ROI_W(roi_w));
mdp5_write(mdp5_kms, REG_MDP5_LM_CURSOR_START_XY(mdp5_crtc->lm),
MDP5_LM_CURSOR_START_XY_Y_START(y) |
MDP5_LM_CURSOR_START_XY_X_START(x));
spin_unlock_irqrestore(&mdp5_crtc->cursor.lock, flags);
crtc_flush(crtc, flush_mask);
return 0;
}
static void mdp5_crtc_vblank_irq(struct mdp_irq *irq, uint32_t irqstatus)
{
struct mdp5_crtc *mdp5_crtc = container_of(irq, struct mdp5_crtc, vblank);
struct drm_crtc *crtc = &mdp5_crtc->base;
struct msm_drm_private *priv = crtc->dev->dev_private;
unsigned pending;
mdp_irq_unregister(&get_kms(crtc)->base, &mdp5_crtc->vblank);
pending = atomic_xchg(&mdp5_crtc->pending, 0);
if (pending & PENDING_FLIP) {
complete_flip(crtc, NULL);
}
if (pending & PENDING_CURSOR)
drm_flip_work_commit(&mdp5_crtc->unref_cursor_work, priv->wq);
}
static void mdp5_crtc_err_irq(struct mdp_irq *irq, uint32_t irqstatus)
{
struct mdp5_crtc *mdp5_crtc = container_of(irq, struct mdp5_crtc, err);
DBG("%s: error: %08x", mdp5_crtc->name, irqstatus);
}
static void mdp5_crtc_pp_done_irq(struct mdp_irq *irq, uint32_t irqstatus)
{
struct mdp5_crtc *mdp5_crtc = container_of(irq, struct mdp5_crtc,
pp_done);
complete(&mdp5_crtc->pp_completion);
}
static void mdp5_crtc_wait_for_pp_done(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
int ret;
ret = wait_for_completion_timeout(&mdp5_crtc->pp_completion,
msecs_to_jiffies(50));
if (ret == 0)
dev_warn(dev->dev, "pp done time out, lm=%d\n", mdp5_crtc->lm);
}
static void mdp5_crtc_wait_for_flush_done(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
int ret;
if (!mdp5_crtc->ctl)
return;
ret = drm_crtc_vblank_get(crtc);
if (ret)
return;
ret = wait_event_timeout(dev->vblank[drm_crtc_index(crtc)].queue,
((mdp5_ctl_get_commit_status(mdp5_crtc->ctl) &
mdp5_crtc->flushed_mask) == 0),
msecs_to_jiffies(50));
if (ret <= 0)
dev_warn(dev->dev, "vblank time out, crtc=%d\n", mdp5_crtc->id);
mdp5_crtc->flushed_mask = 0;
drm_crtc_vblank_put(crtc);
}
uint32_t mdp5_crtc_vblank(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
return mdp5_crtc->vblank.irqmask;
}
void mdp5_crtc_cancel_pending_flip(struct drm_crtc *crtc, struct drm_file *file)
{
DBG("cancel: %p", file);
complete_flip(crtc, file);
}
void mdp5_crtc_set_pipeline(struct drm_crtc *crtc,
struct mdp5_interface *intf, struct mdp5_ctl *ctl)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
int lm = mdp5_crtc_get_lm(crtc);
mdp5_crtc->err.irqmask = intf2err(intf->num);
mdp5_crtc->vblank.irqmask = intf2vblank(lm, intf);
if ((intf->type == INTF_DSI) &&
(intf->mode == MDP5_INTF_DSI_MODE_COMMAND)) {
mdp5_crtc->pp_done.irqmask = lm2ppdone(lm);
mdp5_crtc->pp_done.irq = mdp5_crtc_pp_done_irq;
mdp5_crtc->cmd_mode = true;
} else {
mdp5_crtc->pp_done.irqmask = 0;
mdp5_crtc->pp_done.irq = NULL;
mdp5_crtc->cmd_mode = false;
}
mdp_irq_update(&mdp5_kms->base);
mdp5_crtc->ctl = ctl;
mdp5_ctl_set_pipeline(ctl, intf, lm);
}
int mdp5_crtc_get_lm(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
return WARN_ON(!crtc) ? -EINVAL : mdp5_crtc->lm;
}
void mdp5_crtc_wait_for_commit_done(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
if (mdp5_crtc->cmd_mode)
mdp5_crtc_wait_for_pp_done(crtc);
else
mdp5_crtc_wait_for_flush_done(crtc);
}
struct drm_crtc *mdp5_crtc_init(struct drm_device *dev,
struct drm_plane *plane, int id)
{
struct drm_crtc *crtc = NULL;
struct mdp5_crtc *mdp5_crtc;
mdp5_crtc = kzalloc(sizeof(*mdp5_crtc), GFP_KERNEL);
if (!mdp5_crtc)
return ERR_PTR(-ENOMEM);
crtc = &mdp5_crtc->base;
mdp5_crtc->id = id;
mdp5_crtc->lm = GET_LM_ID(id);
spin_lock_init(&mdp5_crtc->lm_lock);
spin_lock_init(&mdp5_crtc->cursor.lock);
init_completion(&mdp5_crtc->pp_completion);
mdp5_crtc->vblank.irq = mdp5_crtc_vblank_irq;
mdp5_crtc->err.irq = mdp5_crtc_err_irq;
snprintf(mdp5_crtc->name, sizeof(mdp5_crtc->name), "%s:%d",
pipe2name(mdp5_plane_pipe(plane)), id);
drm_crtc_init_with_planes(dev, crtc, plane, NULL, &mdp5_crtc_funcs,
NULL);
drm_flip_work_init(&mdp5_crtc->unref_cursor_work,
"unref cursor", unref_cursor_worker);
drm_crtc_helper_add(crtc, &mdp5_crtc_helper_funcs);
plane->crtc = crtc;
return crtc;
}
