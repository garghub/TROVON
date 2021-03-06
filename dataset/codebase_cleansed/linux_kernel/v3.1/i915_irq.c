static void
ironlake_enable_display_irq(drm_i915_private_t *dev_priv, u32 mask)
{
if ((dev_priv->irq_mask & mask) != 0) {
dev_priv->irq_mask &= ~mask;
I915_WRITE(DEIMR, dev_priv->irq_mask);
POSTING_READ(DEIMR);
}
}
static inline void
ironlake_disable_display_irq(drm_i915_private_t *dev_priv, u32 mask)
{
if ((dev_priv->irq_mask & mask) != mask) {
dev_priv->irq_mask |= mask;
I915_WRITE(DEIMR, dev_priv->irq_mask);
POSTING_READ(DEIMR);
}
}
void
i915_enable_pipestat(drm_i915_private_t *dev_priv, int pipe, u32 mask)
{
if ((dev_priv->pipestat[pipe] & mask) != mask) {
u32 reg = PIPESTAT(pipe);
dev_priv->pipestat[pipe] |= mask;
I915_WRITE(reg, dev_priv->pipestat[pipe] | (mask >> 16));
POSTING_READ(reg);
}
}
void
i915_disable_pipestat(drm_i915_private_t *dev_priv, int pipe, u32 mask)
{
if ((dev_priv->pipestat[pipe] & mask) != 0) {
u32 reg = PIPESTAT(pipe);
dev_priv->pipestat[pipe] &= ~mask;
I915_WRITE(reg, dev_priv->pipestat[pipe]);
POSTING_READ(reg);
}
}
void intel_enable_asle(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
if (HAS_PCH_SPLIT(dev))
ironlake_enable_display_irq(dev_priv, DE_GSE);
else {
i915_enable_pipestat(dev_priv, 1,
PIPE_LEGACY_BLC_EVENT_ENABLE);
if (INTEL_INFO(dev)->gen >= 4)
i915_enable_pipestat(dev_priv, 0,
PIPE_LEGACY_BLC_EVENT_ENABLE);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static int
i915_pipe_enabled(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
return I915_READ(PIPECONF(pipe)) & PIPECONF_ENABLE;
}
static u32 i915_get_vblank_counter(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long high_frame;
unsigned long low_frame;
u32 high1, high2, low;
if (!i915_pipe_enabled(dev, pipe)) {
DRM_DEBUG_DRIVER("trying to get vblank count for disabled "
"pipe %c\n", pipe_name(pipe));
return 0;
}
high_frame = PIPEFRAME(pipe);
low_frame = PIPEFRAMEPIXEL(pipe);
do {
high1 = I915_READ(high_frame) & PIPE_FRAME_HIGH_MASK;
low = I915_READ(low_frame) & PIPE_FRAME_LOW_MASK;
high2 = I915_READ(high_frame) & PIPE_FRAME_HIGH_MASK;
} while (high1 != high2);
high1 >>= PIPE_FRAME_HIGH_SHIFT;
low >>= PIPE_FRAME_LOW_SHIFT;
return (high1 << 8) | low;
}
static u32 gm45_get_vblank_counter(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
int reg = PIPE_FRMCOUNT_GM45(pipe);
if (!i915_pipe_enabled(dev, pipe)) {
DRM_DEBUG_DRIVER("trying to get vblank count for disabled "
"pipe %c\n", pipe_name(pipe));
return 0;
}
return I915_READ(reg);
}
static int i915_get_crtc_scanoutpos(struct drm_device *dev, int pipe,
int *vpos, int *hpos)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
u32 vbl = 0, position = 0;
int vbl_start, vbl_end, htotal, vtotal;
bool in_vbl = true;
int ret = 0;
if (!i915_pipe_enabled(dev, pipe)) {
DRM_DEBUG_DRIVER("trying to get scanoutpos for disabled "
"pipe %c\n", pipe_name(pipe));
return 0;
}
vtotal = 1 + ((I915_READ(VTOTAL(pipe)) >> 16) & 0x1fff);
if (INTEL_INFO(dev)->gen >= 4) {
position = I915_READ(PIPEDSL(pipe));
*vpos = position & 0x1fff;
*hpos = 0;
} else {
position = (I915_READ(PIPEFRAMEPIXEL(pipe)) & PIPE_PIXEL_MASK) >> PIPE_PIXEL_SHIFT;
htotal = 1 + ((I915_READ(HTOTAL(pipe)) >> 16) & 0x1fff);
*vpos = position / htotal;
*hpos = position - (*vpos * htotal);
}
vbl = I915_READ(VBLANK(pipe));
vbl_start = vbl & 0x1fff;
vbl_end = (vbl >> 16) & 0x1fff;
if ((*vpos < vbl_start) || (*vpos > vbl_end))
in_vbl = false;
if (in_vbl && (*vpos >= vbl_start))
*vpos = *vpos - vtotal;
if (vbl > 0)
ret |= DRM_SCANOUTPOS_VALID | DRM_SCANOUTPOS_ACCURATE;
if (in_vbl)
ret |= DRM_SCANOUTPOS_INVBL;
return ret;
}
static int i915_get_vblank_timestamp(struct drm_device *dev, int pipe,
int *max_error,
struct timeval *vblank_time,
unsigned flags)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
if (pipe < 0 || pipe >= dev_priv->num_pipe) {
DRM_ERROR("Invalid crtc %d\n", pipe);
return -EINVAL;
}
crtc = intel_get_crtc_for_pipe(dev, pipe);
if (crtc == NULL) {
DRM_ERROR("Invalid crtc %d\n", pipe);
return -EINVAL;
}
if (!crtc->enabled) {
DRM_DEBUG_KMS("crtc %d is disabled\n", pipe);
return -EBUSY;
}
return drm_calc_vbltimestamp_from_scanoutpos(dev, pipe, max_error,
vblank_time, flags,
crtc);
}
static void i915_hotplug_work_func(struct work_struct *work)
{
drm_i915_private_t *dev_priv = container_of(work, drm_i915_private_t,
hotplug_work);
struct drm_device *dev = dev_priv->dev;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
mutex_lock(&mode_config->mutex);
DRM_DEBUG_KMS("running encoder hotplug functions\n");
list_for_each_entry(encoder, &mode_config->encoder_list, base.head)
if (encoder->hot_plug)
encoder->hot_plug(encoder);
mutex_unlock(&mode_config->mutex);
drm_helper_hpd_irq_event(dev);
}
static void i915_handle_rps_change(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 busy_up, busy_down, max_avg, min_avg;
u8 new_delay = dev_priv->cur_delay;
I915_WRITE16(MEMINTRSTS, MEMINT_EVAL_CHG);
busy_up = I915_READ(RCPREVBSYTUPAVG);
busy_down = I915_READ(RCPREVBSYTDNAVG);
max_avg = I915_READ(RCBMAXAVG);
min_avg = I915_READ(RCBMINAVG);
if (busy_up > max_avg) {
if (dev_priv->cur_delay != dev_priv->max_delay)
new_delay = dev_priv->cur_delay - 1;
if (new_delay < dev_priv->max_delay)
new_delay = dev_priv->max_delay;
} else if (busy_down < min_avg) {
if (dev_priv->cur_delay != dev_priv->min_delay)
new_delay = dev_priv->cur_delay + 1;
if (new_delay > dev_priv->min_delay)
new_delay = dev_priv->min_delay;
}
if (ironlake_set_drps(dev, new_delay))
dev_priv->cur_delay = new_delay;
return;
}
static void notify_ring(struct drm_device *dev,
struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 seqno;
if (ring->obj == NULL)
return;
seqno = ring->get_seqno(ring);
trace_i915_gem_request_complete(ring, seqno);
ring->irq_seqno = seqno;
wake_up_all(&ring->irq_queue);
if (i915_enable_hangcheck) {
dev_priv->hangcheck_count = 0;
mod_timer(&dev_priv->hangcheck_timer,
jiffies +
msecs_to_jiffies(DRM_I915_HANGCHECK_PERIOD));
}
}
static void gen6_pm_rps_work(struct work_struct *work)
{
drm_i915_private_t *dev_priv = container_of(work, drm_i915_private_t,
rps_work);
u8 new_delay = dev_priv->cur_delay;
u32 pm_iir, pm_imr;
spin_lock_irq(&dev_priv->rps_lock);
pm_iir = dev_priv->pm_iir;
dev_priv->pm_iir = 0;
pm_imr = I915_READ(GEN6_PMIMR);
spin_unlock_irq(&dev_priv->rps_lock);
if (!pm_iir)
return;
mutex_lock(&dev_priv->dev->struct_mutex);
if (pm_iir & GEN6_PM_RP_UP_THRESHOLD) {
if (dev_priv->cur_delay != dev_priv->max_delay)
new_delay = dev_priv->cur_delay + 1;
if (new_delay > dev_priv->max_delay)
new_delay = dev_priv->max_delay;
} else if (pm_iir & (GEN6_PM_RP_DOWN_THRESHOLD | GEN6_PM_RP_DOWN_TIMEOUT)) {
gen6_gt_force_wake_get(dev_priv);
if (dev_priv->cur_delay != dev_priv->min_delay)
new_delay = dev_priv->cur_delay - 1;
if (new_delay < dev_priv->min_delay) {
new_delay = dev_priv->min_delay;
I915_WRITE(GEN6_RP_INTERRUPT_LIMITS,
I915_READ(GEN6_RP_INTERRUPT_LIMITS) |
((new_delay << 16) & 0x3f0000));
} else {
I915_WRITE(GEN6_RP_INTERRUPT_LIMITS,
I915_READ(GEN6_RP_INTERRUPT_LIMITS) & ~0x3f0000);
}
gen6_gt_force_wake_put(dev_priv);
}
gen6_set_rps(dev_priv->dev, new_delay);
dev_priv->cur_delay = new_delay;
I915_WRITE(GEN6_PMIMR, pm_imr & ~pm_iir);
mutex_unlock(&dev_priv->dev->struct_mutex);
}
static void pch_irq_handler(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
u32 pch_iir;
int pipe;
pch_iir = I915_READ(SDEIIR);
if (pch_iir & SDE_AUDIO_POWER_MASK)
DRM_DEBUG_DRIVER("PCH audio power change on port %d\n",
(pch_iir & SDE_AUDIO_POWER_MASK) >>
SDE_AUDIO_POWER_SHIFT);
if (pch_iir & SDE_GMBUS)
DRM_DEBUG_DRIVER("PCH GMBUS interrupt\n");
if (pch_iir & SDE_AUDIO_HDCP_MASK)
DRM_DEBUG_DRIVER("PCH HDCP audio interrupt\n");
if (pch_iir & SDE_AUDIO_TRANS_MASK)
DRM_DEBUG_DRIVER("PCH transcoder audio interrupt\n");
if (pch_iir & SDE_POISON)
DRM_ERROR("PCH poison interrupt\n");
if (pch_iir & SDE_FDI_MASK)
for_each_pipe(pipe)
DRM_DEBUG_DRIVER(" pipe %c FDI IIR: 0x%08x\n",
pipe_name(pipe),
I915_READ(FDI_RX_IIR(pipe)));
if (pch_iir & (SDE_TRANSB_CRC_DONE | SDE_TRANSA_CRC_DONE))
DRM_DEBUG_DRIVER("PCH transcoder CRC done interrupt\n");
if (pch_iir & (SDE_TRANSB_CRC_ERR | SDE_TRANSA_CRC_ERR))
DRM_DEBUG_DRIVER("PCH transcoder CRC error interrupt\n");
if (pch_iir & SDE_TRANSB_FIFO_UNDER)
DRM_DEBUG_DRIVER("PCH transcoder B underrun interrupt\n");
if (pch_iir & SDE_TRANSA_FIFO_UNDER)
DRM_DEBUG_DRIVER("PCH transcoder A underrun interrupt\n");
}
static irqreturn_t ivybridge_irq_handler(DRM_IRQ_ARGS)
{
struct drm_device *dev = (struct drm_device *) arg;
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
int ret = IRQ_NONE;
u32 de_iir, gt_iir, de_ier, pch_iir, pm_iir;
struct drm_i915_master_private *master_priv;
atomic_inc(&dev_priv->irq_received);
de_ier = I915_READ(DEIER);
I915_WRITE(DEIER, de_ier & ~DE_MASTER_IRQ_CONTROL);
POSTING_READ(DEIER);
de_iir = I915_READ(DEIIR);
gt_iir = I915_READ(GTIIR);
pch_iir = I915_READ(SDEIIR);
pm_iir = I915_READ(GEN6_PMIIR);
if (de_iir == 0 && gt_iir == 0 && pch_iir == 0 && pm_iir == 0)
goto done;
ret = IRQ_HANDLED;
if (dev->primary->master) {
master_priv = dev->primary->master->driver_priv;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_dispatch =
READ_BREADCRUMB(dev_priv);
}
if (gt_iir & (GT_USER_INTERRUPT | GT_PIPE_NOTIFY))
notify_ring(dev, &dev_priv->ring[RCS]);
if (gt_iir & GT_GEN6_BSD_USER_INTERRUPT)
notify_ring(dev, &dev_priv->ring[VCS]);
if (gt_iir & GT_BLT_USER_INTERRUPT)
notify_ring(dev, &dev_priv->ring[BCS]);
if (de_iir & DE_GSE_IVB)
intel_opregion_gse_intr(dev);
if (de_iir & DE_PLANEA_FLIP_DONE_IVB) {
intel_prepare_page_flip(dev, 0);
intel_finish_page_flip_plane(dev, 0);
}
if (de_iir & DE_PLANEB_FLIP_DONE_IVB) {
intel_prepare_page_flip(dev, 1);
intel_finish_page_flip_plane(dev, 1);
}
if (de_iir & DE_PIPEA_VBLANK_IVB)
drm_handle_vblank(dev, 0);
if (de_iir & DE_PIPEB_VBLANK_IVB)
drm_handle_vblank(dev, 1);
if (de_iir & DE_PCH_EVENT_IVB) {
if (pch_iir & SDE_HOTPLUG_MASK_CPT)
queue_work(dev_priv->wq, &dev_priv->hotplug_work);
pch_irq_handler(dev);
}
if (pm_iir & GEN6_PM_DEFERRED_EVENTS) {
unsigned long flags;
spin_lock_irqsave(&dev_priv->rps_lock, flags);
WARN(dev_priv->pm_iir & pm_iir, "Missed a PM interrupt\n");
I915_WRITE(GEN6_PMIMR, pm_iir);
dev_priv->pm_iir |= pm_iir;
spin_unlock_irqrestore(&dev_priv->rps_lock, flags);
queue_work(dev_priv->wq, &dev_priv->rps_work);
}
I915_WRITE(SDEIIR, pch_iir);
I915_WRITE(GTIIR, gt_iir);
I915_WRITE(DEIIR, de_iir);
I915_WRITE(GEN6_PMIIR, pm_iir);
done:
I915_WRITE(DEIER, de_ier);
POSTING_READ(DEIER);
return ret;
}
static irqreturn_t ironlake_irq_handler(DRM_IRQ_ARGS)
{
struct drm_device *dev = (struct drm_device *) arg;
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
int ret = IRQ_NONE;
u32 de_iir, gt_iir, de_ier, pch_iir, pm_iir;
u32 hotplug_mask;
struct drm_i915_master_private *master_priv;
u32 bsd_usr_interrupt = GT_BSD_USER_INTERRUPT;
atomic_inc(&dev_priv->irq_received);
if (IS_GEN6(dev))
bsd_usr_interrupt = GT_GEN6_BSD_USER_INTERRUPT;
de_ier = I915_READ(DEIER);
I915_WRITE(DEIER, de_ier & ~DE_MASTER_IRQ_CONTROL);
POSTING_READ(DEIER);
de_iir = I915_READ(DEIIR);
gt_iir = I915_READ(GTIIR);
pch_iir = I915_READ(SDEIIR);
pm_iir = I915_READ(GEN6_PMIIR);
if (de_iir == 0 && gt_iir == 0 && pch_iir == 0 &&
(!IS_GEN6(dev) || pm_iir == 0))
goto done;
if (HAS_PCH_CPT(dev))
hotplug_mask = SDE_HOTPLUG_MASK_CPT;
else
hotplug_mask = SDE_HOTPLUG_MASK;
ret = IRQ_HANDLED;
if (dev->primary->master) {
master_priv = dev->primary->master->driver_priv;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_dispatch =
READ_BREADCRUMB(dev_priv);
}
if (gt_iir & (GT_USER_INTERRUPT | GT_PIPE_NOTIFY))
notify_ring(dev, &dev_priv->ring[RCS]);
if (gt_iir & bsd_usr_interrupt)
notify_ring(dev, &dev_priv->ring[VCS]);
if (gt_iir & GT_BLT_USER_INTERRUPT)
notify_ring(dev, &dev_priv->ring[BCS]);
if (de_iir & DE_GSE)
intel_opregion_gse_intr(dev);
if (de_iir & DE_PLANEA_FLIP_DONE) {
intel_prepare_page_flip(dev, 0);
intel_finish_page_flip_plane(dev, 0);
}
if (de_iir & DE_PLANEB_FLIP_DONE) {
intel_prepare_page_flip(dev, 1);
intel_finish_page_flip_plane(dev, 1);
}
if (de_iir & DE_PIPEA_VBLANK)
drm_handle_vblank(dev, 0);
if (de_iir & DE_PIPEB_VBLANK)
drm_handle_vblank(dev, 1);
if (de_iir & DE_PCH_EVENT) {
if (pch_iir & hotplug_mask)
queue_work(dev_priv->wq, &dev_priv->hotplug_work);
pch_irq_handler(dev);
}
if (de_iir & DE_PCU_EVENT) {
I915_WRITE16(MEMINTRSTS, I915_READ(MEMINTRSTS));
i915_handle_rps_change(dev);
}
if (IS_GEN6(dev) && pm_iir & GEN6_PM_DEFERRED_EVENTS) {
unsigned long flags;
spin_lock_irqsave(&dev_priv->rps_lock, flags);
WARN(dev_priv->pm_iir & pm_iir, "Missed a PM interrupt\n");
I915_WRITE(GEN6_PMIMR, pm_iir);
dev_priv->pm_iir |= pm_iir;
spin_unlock_irqrestore(&dev_priv->rps_lock, flags);
queue_work(dev_priv->wq, &dev_priv->rps_work);
}
I915_WRITE(SDEIIR, pch_iir);
I915_WRITE(GTIIR, gt_iir);
I915_WRITE(DEIIR, de_iir);
I915_WRITE(GEN6_PMIIR, pm_iir);
done:
I915_WRITE(DEIER, de_ier);
POSTING_READ(DEIER);
return ret;
}
static void i915_error_work_func(struct work_struct *work)
{
drm_i915_private_t *dev_priv = container_of(work, drm_i915_private_t,
error_work);
struct drm_device *dev = dev_priv->dev;
char *error_event[] = { "ERROR=1", NULL };
char *reset_event[] = { "RESET=1", NULL };
char *reset_done_event[] = { "ERROR=0", NULL };
kobject_uevent_env(&dev->primary->kdev.kobj, KOBJ_CHANGE, error_event);
if (atomic_read(&dev_priv->mm.wedged)) {
DRM_DEBUG_DRIVER("resetting chip\n");
kobject_uevent_env(&dev->primary->kdev.kobj, KOBJ_CHANGE, reset_event);
if (!i915_reset(dev, GRDOM_RENDER)) {
atomic_set(&dev_priv->mm.wedged, 0);
kobject_uevent_env(&dev->primary->kdev.kobj, KOBJ_CHANGE, reset_done_event);
}
complete_all(&dev_priv->error_completion);
}
}
static struct drm_i915_error_object *
i915_error_object_create(struct drm_i915_private *dev_priv,
struct drm_i915_gem_object *src)
{
struct drm_i915_error_object *dst;
int page, page_count;
u32 reloc_offset;
if (src == NULL || src->pages == NULL)
return NULL;
page_count = src->base.size / PAGE_SIZE;
dst = kmalloc(sizeof(*dst) + page_count * sizeof (u32 *), GFP_ATOMIC);
if (dst == NULL)
return NULL;
reloc_offset = src->gtt_offset;
for (page = 0; page < page_count; page++) {
unsigned long flags;
void __iomem *s;
void *d;
d = kmalloc(PAGE_SIZE, GFP_ATOMIC);
if (d == NULL)
goto unwind;
local_irq_save(flags);
s = io_mapping_map_atomic_wc(dev_priv->mm.gtt_mapping,
reloc_offset);
memcpy_fromio(d, s, PAGE_SIZE);
io_mapping_unmap_atomic(s);
local_irq_restore(flags);
dst->pages[page] = d;
reloc_offset += PAGE_SIZE;
}
dst->page_count = page_count;
dst->gtt_offset = src->gtt_offset;
return dst;
unwind:
while (page--)
kfree(dst->pages[page]);
kfree(dst);
return NULL;
}
static void
i915_error_object_free(struct drm_i915_error_object *obj)
{
int page;
if (obj == NULL)
return;
for (page = 0; page < obj->page_count; page++)
kfree(obj->pages[page]);
kfree(obj);
}
static void
i915_error_state_free(struct drm_device *dev,
struct drm_i915_error_state *error)
{
int i;
for (i = 0; i < ARRAY_SIZE(error->batchbuffer); i++)
i915_error_object_free(error->batchbuffer[i]);
for (i = 0; i < ARRAY_SIZE(error->ringbuffer); i++)
i915_error_object_free(error->ringbuffer[i]);
kfree(error->active_bo);
kfree(error->overlay);
kfree(error);
}
static u32 capture_bo_list(struct drm_i915_error_buffer *err,
int count,
struct list_head *head)
{
struct drm_i915_gem_object *obj;
int i = 0;
list_for_each_entry(obj, head, mm_list) {
err->size = obj->base.size;
err->name = obj->base.name;
err->seqno = obj->last_rendering_seqno;
err->gtt_offset = obj->gtt_offset;
err->read_domains = obj->base.read_domains;
err->write_domain = obj->base.write_domain;
err->fence_reg = obj->fence_reg;
err->pinned = 0;
if (obj->pin_count > 0)
err->pinned = 1;
if (obj->user_pin_count > 0)
err->pinned = -1;
err->tiling = obj->tiling_mode;
err->dirty = obj->dirty;
err->purgeable = obj->madv != I915_MADV_WILLNEED;
err->ring = obj->ring ? obj->ring->id : 0;
err->cache_level = obj->cache_level;
if (++i == count)
break;
err++;
}
return i;
}
static void i915_gem_record_fences(struct drm_device *dev,
struct drm_i915_error_state *error)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
switch (INTEL_INFO(dev)->gen) {
case 6:
for (i = 0; i < 16; i++)
error->fence[i] = I915_READ64(FENCE_REG_SANDYBRIDGE_0 + (i * 8));
break;
case 5:
case 4:
for (i = 0; i < 16; i++)
error->fence[i] = I915_READ64(FENCE_REG_965_0 + (i * 8));
break;
case 3:
if (IS_I945G(dev) || IS_I945GM(dev) || IS_G33(dev))
for (i = 0; i < 8; i++)
error->fence[i+8] = I915_READ(FENCE_REG_945_8 + (i * 4));
case 2:
for (i = 0; i < 8; i++)
error->fence[i] = I915_READ(FENCE_REG_830_0 + (i * 4));
break;
}
}
static struct drm_i915_error_object *
i915_error_first_batchbuffer(struct drm_i915_private *dev_priv,
struct intel_ring_buffer *ring)
{
struct drm_i915_gem_object *obj;
u32 seqno;
if (!ring->get_seqno)
return NULL;
seqno = ring->get_seqno(ring);
list_for_each_entry(obj, &dev_priv->mm.active_list, mm_list) {
if (obj->ring != ring)
continue;
if (i915_seqno_passed(seqno, obj->last_rendering_seqno))
continue;
if ((obj->base.read_domains & I915_GEM_DOMAIN_COMMAND) == 0)
continue;
return i915_error_object_create(dev_priv, obj);
}
return NULL;
}
static void i915_capture_error_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct drm_i915_error_state *error;
unsigned long flags;
int i, pipe;
spin_lock_irqsave(&dev_priv->error_lock, flags);
error = dev_priv->first_error;
spin_unlock_irqrestore(&dev_priv->error_lock, flags);
if (error)
return;
error = kmalloc(sizeof(*error), GFP_ATOMIC);
if (!error) {
DRM_DEBUG_DRIVER("out of memory, not capturing error state\n");
return;
}
DRM_INFO("capturing error event; look for more information in /debug/dri/%d/i915_error_state\n",
dev->primary->index);
error->seqno = dev_priv->ring[RCS].get_seqno(&dev_priv->ring[RCS]);
error->eir = I915_READ(EIR);
error->pgtbl_er = I915_READ(PGTBL_ER);
for_each_pipe(pipe)
error->pipestat[pipe] = I915_READ(PIPESTAT(pipe));
error->instpm = I915_READ(INSTPM);
error->error = 0;
if (INTEL_INFO(dev)->gen >= 6) {
error->error = I915_READ(ERROR_GEN6);
error->bcs_acthd = I915_READ(BCS_ACTHD);
error->bcs_ipehr = I915_READ(BCS_IPEHR);
error->bcs_ipeir = I915_READ(BCS_IPEIR);
error->bcs_instdone = I915_READ(BCS_INSTDONE);
error->bcs_seqno = 0;
if (dev_priv->ring[BCS].get_seqno)
error->bcs_seqno = dev_priv->ring[BCS].get_seqno(&dev_priv->ring[BCS]);
error->vcs_acthd = I915_READ(VCS_ACTHD);
error->vcs_ipehr = I915_READ(VCS_IPEHR);
error->vcs_ipeir = I915_READ(VCS_IPEIR);
error->vcs_instdone = I915_READ(VCS_INSTDONE);
error->vcs_seqno = 0;
if (dev_priv->ring[VCS].get_seqno)
error->vcs_seqno = dev_priv->ring[VCS].get_seqno(&dev_priv->ring[VCS]);
}
if (INTEL_INFO(dev)->gen >= 4) {
error->ipeir = I915_READ(IPEIR_I965);
error->ipehr = I915_READ(IPEHR_I965);
error->instdone = I915_READ(INSTDONE_I965);
error->instps = I915_READ(INSTPS);
error->instdone1 = I915_READ(INSTDONE1);
error->acthd = I915_READ(ACTHD_I965);
error->bbaddr = I915_READ64(BB_ADDR);
} else {
error->ipeir = I915_READ(IPEIR);
error->ipehr = I915_READ(IPEHR);
error->instdone = I915_READ(INSTDONE);
error->acthd = I915_READ(ACTHD);
error->bbaddr = 0;
}
i915_gem_record_fences(dev, error);
for (i = 0; i < I915_NUM_RINGS; i++) {
error->batchbuffer[i] =
i915_error_first_batchbuffer(dev_priv,
&dev_priv->ring[i]);
error->ringbuffer[i] =
i915_error_object_create(dev_priv,
dev_priv->ring[i].obj);
}
error->active_bo = NULL;
error->pinned_bo = NULL;
i = 0;
list_for_each_entry(obj, &dev_priv->mm.active_list, mm_list)
i++;
error->active_bo_count = i;
list_for_each_entry(obj, &dev_priv->mm.pinned_list, mm_list)
i++;
error->pinned_bo_count = i - error->active_bo_count;
error->active_bo = NULL;
error->pinned_bo = NULL;
if (i) {
error->active_bo = kmalloc(sizeof(*error->active_bo)*i,
GFP_ATOMIC);
if (error->active_bo)
error->pinned_bo =
error->active_bo + error->active_bo_count;
}
if (error->active_bo)
error->active_bo_count =
capture_bo_list(error->active_bo,
error->active_bo_count,
&dev_priv->mm.active_list);
if (error->pinned_bo)
error->pinned_bo_count =
capture_bo_list(error->pinned_bo,
error->pinned_bo_count,
&dev_priv->mm.pinned_list);
do_gettimeofday(&error->time);
error->overlay = intel_overlay_capture_error_state(dev);
error->display = intel_display_capture_error_state(dev);
spin_lock_irqsave(&dev_priv->error_lock, flags);
if (dev_priv->first_error == NULL) {
dev_priv->first_error = error;
error = NULL;
}
spin_unlock_irqrestore(&dev_priv->error_lock, flags);
if (error)
i915_error_state_free(dev, error);
}
void i915_destroy_error_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_error_state *error;
spin_lock(&dev_priv->error_lock);
error = dev_priv->first_error;
dev_priv->first_error = NULL;
spin_unlock(&dev_priv->error_lock);
if (error)
i915_error_state_free(dev, error);
}
static void i915_report_and_clear_eir(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 eir = I915_READ(EIR);
int pipe;
if (!eir)
return;
printk(KERN_ERR "render error detected, EIR: 0x%08x\n",
eir);
if (IS_G4X(dev)) {
if (eir & (GM45_ERROR_MEM_PRIV | GM45_ERROR_CP_PRIV)) {
u32 ipeir = I915_READ(IPEIR_I965);
printk(KERN_ERR " IPEIR: 0x%08x\n",
I915_READ(IPEIR_I965));
printk(KERN_ERR " IPEHR: 0x%08x\n",
I915_READ(IPEHR_I965));
printk(KERN_ERR " INSTDONE: 0x%08x\n",
I915_READ(INSTDONE_I965));
printk(KERN_ERR " INSTPS: 0x%08x\n",
I915_READ(INSTPS));
printk(KERN_ERR " INSTDONE1: 0x%08x\n",
I915_READ(INSTDONE1));
printk(KERN_ERR " ACTHD: 0x%08x\n",
I915_READ(ACTHD_I965));
I915_WRITE(IPEIR_I965, ipeir);
POSTING_READ(IPEIR_I965);
}
if (eir & GM45_ERROR_PAGE_TABLE) {
u32 pgtbl_err = I915_READ(PGTBL_ER);
printk(KERN_ERR "page table error\n");
printk(KERN_ERR " PGTBL_ER: 0x%08x\n",
pgtbl_err);
I915_WRITE(PGTBL_ER, pgtbl_err);
POSTING_READ(PGTBL_ER);
}
}
if (!IS_GEN2(dev)) {
if (eir & I915_ERROR_PAGE_TABLE) {
u32 pgtbl_err = I915_READ(PGTBL_ER);
printk(KERN_ERR "page table error\n");
printk(KERN_ERR " PGTBL_ER: 0x%08x\n",
pgtbl_err);
I915_WRITE(PGTBL_ER, pgtbl_err);
POSTING_READ(PGTBL_ER);
}
}
if (eir & I915_ERROR_MEMORY_REFRESH) {
printk(KERN_ERR "memory refresh error:\n");
for_each_pipe(pipe)
printk(KERN_ERR "pipe %c stat: 0x%08x\n",
pipe_name(pipe), I915_READ(PIPESTAT(pipe)));
}
if (eir & I915_ERROR_INSTRUCTION) {
printk(KERN_ERR "instruction error\n");
printk(KERN_ERR " INSTPM: 0x%08x\n",
I915_READ(INSTPM));
if (INTEL_INFO(dev)->gen < 4) {
u32 ipeir = I915_READ(IPEIR);
printk(KERN_ERR " IPEIR: 0x%08x\n",
I915_READ(IPEIR));
printk(KERN_ERR " IPEHR: 0x%08x\n",
I915_READ(IPEHR));
printk(KERN_ERR " INSTDONE: 0x%08x\n",
I915_READ(INSTDONE));
printk(KERN_ERR " ACTHD: 0x%08x\n",
I915_READ(ACTHD));
I915_WRITE(IPEIR, ipeir);
POSTING_READ(IPEIR);
} else {
u32 ipeir = I915_READ(IPEIR_I965);
printk(KERN_ERR " IPEIR: 0x%08x\n",
I915_READ(IPEIR_I965));
printk(KERN_ERR " IPEHR: 0x%08x\n",
I915_READ(IPEHR_I965));
printk(KERN_ERR " INSTDONE: 0x%08x\n",
I915_READ(INSTDONE_I965));
printk(KERN_ERR " INSTPS: 0x%08x\n",
I915_READ(INSTPS));
printk(KERN_ERR " INSTDONE1: 0x%08x\n",
I915_READ(INSTDONE1));
printk(KERN_ERR " ACTHD: 0x%08x\n",
I915_READ(ACTHD_I965));
I915_WRITE(IPEIR_I965, ipeir);
POSTING_READ(IPEIR_I965);
}
}
I915_WRITE(EIR, eir);
POSTING_READ(EIR);
eir = I915_READ(EIR);
if (eir) {
DRM_ERROR("EIR stuck: 0x%08x, masking\n", eir);
I915_WRITE(EMR, I915_READ(EMR) | eir);
I915_WRITE(IIR, I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT);
}
}
void i915_handle_error(struct drm_device *dev, bool wedged)
{
struct drm_i915_private *dev_priv = dev->dev_private;
i915_capture_error_state(dev);
i915_report_and_clear_eir(dev);
if (wedged) {
INIT_COMPLETION(dev_priv->error_completion);
atomic_set(&dev_priv->mm.wedged, 1);
wake_up_all(&dev_priv->ring[RCS].irq_queue);
if (HAS_BSD(dev))
wake_up_all(&dev_priv->ring[VCS].irq_queue);
if (HAS_BLT(dev))
wake_up_all(&dev_priv->ring[BCS].irq_queue);
}
queue_work(dev_priv->wq, &dev_priv->error_work);
}
static void i915_pageflip_stall_check(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_i915_gem_object *obj;
struct intel_unpin_work *work;
unsigned long flags;
bool stall_detected;
if (intel_crtc == NULL)
return;
spin_lock_irqsave(&dev->event_lock, flags);
work = intel_crtc->unpin_work;
if (work == NULL || work->pending || !work->enable_stall_check) {
spin_unlock_irqrestore(&dev->event_lock, flags);
return;
}
obj = work->pending_flip_obj;
if (INTEL_INFO(dev)->gen >= 4) {
int dspsurf = DSPSURF(intel_crtc->plane);
stall_detected = I915_READ(dspsurf) == obj->gtt_offset;
} else {
int dspaddr = DSPADDR(intel_crtc->plane);
stall_detected = I915_READ(dspaddr) == (obj->gtt_offset +
crtc->y * crtc->fb->pitch +
crtc->x * crtc->fb->bits_per_pixel/8);
}
spin_unlock_irqrestore(&dev->event_lock, flags);
if (stall_detected) {
DRM_DEBUG_DRIVER("Pageflip stall detected\n");
intel_prepare_page_flip(dev, intel_crtc->plane);
}
}
static irqreturn_t i915_driver_irq_handler(DRM_IRQ_ARGS)
{
struct drm_device *dev = (struct drm_device *) arg;
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct drm_i915_master_private *master_priv;
u32 iir, new_iir;
u32 pipe_stats[I915_MAX_PIPES];
u32 vblank_status;
int vblank = 0;
unsigned long irqflags;
int irq_received;
int ret = IRQ_NONE, pipe;
bool blc_event = false;
atomic_inc(&dev_priv->irq_received);
iir = I915_READ(IIR);
if (INTEL_INFO(dev)->gen >= 4)
vblank_status = PIPE_START_VBLANK_INTERRUPT_STATUS;
else
vblank_status = PIPE_VBLANK_INTERRUPT_STATUS;
for (;;) {
irq_received = iir != 0;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
if (iir & I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT)
i915_handle_error(dev, false);
for_each_pipe(pipe) {
int reg = PIPESTAT(pipe);
pipe_stats[pipe] = I915_READ(reg);
if (pipe_stats[pipe] & 0x8000ffff) {
if (pipe_stats[pipe] & PIPE_FIFO_UNDERRUN_STATUS)
DRM_DEBUG_DRIVER("pipe %c underrun\n",
pipe_name(pipe));
I915_WRITE(reg, pipe_stats[pipe]);
irq_received = 1;
}
}
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
if (!irq_received)
break;
ret = IRQ_HANDLED;
if ((I915_HAS_HOTPLUG(dev)) &&
(iir & I915_DISPLAY_PORT_INTERRUPT)) {
u32 hotplug_status = I915_READ(PORT_HOTPLUG_STAT);
DRM_DEBUG_DRIVER("hotplug event received, stat 0x%08x\n",
hotplug_status);
if (hotplug_status & dev_priv->hotplug_supported_mask)
queue_work(dev_priv->wq,
&dev_priv->hotplug_work);
I915_WRITE(PORT_HOTPLUG_STAT, hotplug_status);
I915_READ(PORT_HOTPLUG_STAT);
}
I915_WRITE(IIR, iir);
new_iir = I915_READ(IIR);
if (dev->primary->master) {
master_priv = dev->primary->master->driver_priv;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_dispatch =
READ_BREADCRUMB(dev_priv);
}
if (iir & I915_USER_INTERRUPT)
notify_ring(dev, &dev_priv->ring[RCS]);
if (iir & I915_BSD_USER_INTERRUPT)
notify_ring(dev, &dev_priv->ring[VCS]);
if (iir & I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT) {
intel_prepare_page_flip(dev, 0);
if (dev_priv->flip_pending_is_done)
intel_finish_page_flip_plane(dev, 0);
}
if (iir & I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT) {
intel_prepare_page_flip(dev, 1);
if (dev_priv->flip_pending_is_done)
intel_finish_page_flip_plane(dev, 1);
}
for_each_pipe(pipe) {
if (pipe_stats[pipe] & vblank_status &&
drm_handle_vblank(dev, pipe)) {
vblank++;
if (!dev_priv->flip_pending_is_done) {
i915_pageflip_stall_check(dev, pipe);
intel_finish_page_flip(dev, pipe);
}
}
if (pipe_stats[pipe] & PIPE_LEGACY_BLC_EVENT_STATUS)
blc_event = true;
}
if (blc_event || (iir & I915_ASLE_INTERRUPT))
intel_opregion_asle_intr(dev);
iir = new_iir;
}
return ret;
}
static int i915_emit_irq(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
i915_kernel_lost_context(dev);
DRM_DEBUG_DRIVER("\n");
dev_priv->counter++;
if (dev_priv->counter > 0x7FFFFFFFUL)
dev_priv->counter = 1;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_enqueue = dev_priv->counter;
if (BEGIN_LP_RING(4) == 0) {
OUT_RING(MI_STORE_DWORD_INDEX);
OUT_RING(I915_BREADCRUMB_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
OUT_RING(dev_priv->counter);
OUT_RING(MI_USER_INTERRUPT);
ADVANCE_LP_RING();
}
return dev_priv->counter;
}
static int i915_wait_irq(struct drm_device * dev, int irq_nr)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
int ret = 0;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
DRM_DEBUG_DRIVER("irq_nr=%d breadcrumb=%d\n", irq_nr,
READ_BREADCRUMB(dev_priv));
if (READ_BREADCRUMB(dev_priv) >= irq_nr) {
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_dispatch = READ_BREADCRUMB(dev_priv);
return 0;
}
if (master_priv->sarea_priv)
master_priv->sarea_priv->perf_boxes |= I915_BOX_WAIT;
if (ring->irq_get(ring)) {
DRM_WAIT_ON(ret, ring->irq_queue, 3 * DRM_HZ,
READ_BREADCRUMB(dev_priv) >= irq_nr);
ring->irq_put(ring);
} else if (wait_for(READ_BREADCRUMB(dev_priv) >= irq_nr, 3000))
ret = -EBUSY;
if (ret == -EBUSY) {
DRM_ERROR("EBUSY -- rec: %d emitted: %d\n",
READ_BREADCRUMB(dev_priv), (int)dev_priv->counter);
}
return ret;
}
int i915_irq_emit(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_irq_emit_t *emit = data;
int result;
if (!dev_priv || !LP_RING(dev_priv)->virtual_start) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
RING_LOCK_TEST_WITH_RETURN(dev, file_priv);
mutex_lock(&dev->struct_mutex);
result = i915_emit_irq(dev);
mutex_unlock(&dev->struct_mutex);
if (DRM_COPY_TO_USER(emit->irq_seq, &result, sizeof(int))) {
DRM_ERROR("copy_to_user\n");
return -EFAULT;
}
return 0;
}
int i915_irq_wait(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_irq_wait_t *irqwait = data;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
return i915_wait_irq(dev, irqwait->irq_seq);
}
static int i915_enable_vblank(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long irqflags;
if (!i915_pipe_enabled(dev, pipe))
return -EINVAL;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
if (INTEL_INFO(dev)->gen >= 4)
i915_enable_pipestat(dev_priv, pipe,
PIPE_START_VBLANK_INTERRUPT_ENABLE);
else
i915_enable_pipestat(dev_priv, pipe,
PIPE_VBLANK_INTERRUPT_ENABLE);
if (dev_priv->info->gen == 3)
I915_WRITE(INSTPM, INSTPM_AGPBUSY_DIS << 16);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static int ironlake_enable_vblank(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long irqflags;
if (!i915_pipe_enabled(dev, pipe))
return -EINVAL;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
ironlake_enable_display_irq(dev_priv, (pipe == 0) ?
DE_PIPEA_VBLANK: DE_PIPEB_VBLANK);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static int ivybridge_enable_vblank(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long irqflags;
if (!i915_pipe_enabled(dev, pipe))
return -EINVAL;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
ironlake_enable_display_irq(dev_priv, (pipe == 0) ?
DE_PIPEA_VBLANK_IVB : DE_PIPEB_VBLANK_IVB);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static void i915_disable_vblank(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
if (dev_priv->info->gen == 3)
I915_WRITE(INSTPM,
INSTPM_AGPBUSY_DIS << 16 | INSTPM_AGPBUSY_DIS);
i915_disable_pipestat(dev_priv, pipe,
PIPE_VBLANK_INTERRUPT_ENABLE |
PIPE_START_VBLANK_INTERRUPT_ENABLE);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static void ironlake_disable_vblank(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
ironlake_disable_display_irq(dev_priv, (pipe == 0) ?
DE_PIPEA_VBLANK: DE_PIPEB_VBLANK);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static void ivybridge_disable_vblank(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
ironlake_disable_display_irq(dev_priv, (pipe == 0) ?
DE_PIPEA_VBLANK_IVB : DE_PIPEB_VBLANK_IVB);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
int i915_vblank_pipe_set(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
return 0;
}
int i915_vblank_pipe_get(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_vblank_pipe_t *pipe = data;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
pipe->pipe = DRM_I915_VBLANK_PIPE_A | DRM_I915_VBLANK_PIPE_B;
return 0;
}
int i915_vblank_swap(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return -EINVAL;
}
static u32
ring_last_seqno(struct intel_ring_buffer *ring)
{
return list_entry(ring->request_list.prev,
struct drm_i915_gem_request, list)->seqno;
}
static bool i915_hangcheck_ring_idle(struct intel_ring_buffer *ring, bool *err)
{
if (list_empty(&ring->request_list) ||
i915_seqno_passed(ring->get_seqno(ring), ring_last_seqno(ring))) {
if (ring->waiting_seqno && waitqueue_active(&ring->irq_queue)) {
DRM_ERROR("Hangcheck timer elapsed... %s idle [waiting on %d, at %d], missed IRQ?\n",
ring->name,
ring->waiting_seqno,
ring->get_seqno(ring));
wake_up_all(&ring->irq_queue);
*err = true;
}
return true;
}
return false;
}
static bool kick_ring(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp = I915_READ_CTL(ring);
if (tmp & RING_WAIT) {
DRM_ERROR("Kicking stuck wait on %s\n",
ring->name);
I915_WRITE_CTL(ring, tmp);
return true;
}
if (IS_GEN6(dev) &&
(tmp & RING_WAIT_SEMAPHORE)) {
DRM_ERROR("Kicking stuck semaphore on %s\n",
ring->name);
I915_WRITE_CTL(ring, tmp);
return true;
}
return false;
}
void i915_hangcheck_elapsed(unsigned long data)
{
struct drm_device *dev = (struct drm_device *)data;
drm_i915_private_t *dev_priv = dev->dev_private;
uint32_t acthd, instdone, instdone1;
bool err = false;
if (!i915_enable_hangcheck)
return;
if (i915_hangcheck_ring_idle(&dev_priv->ring[RCS], &err) &&
i915_hangcheck_ring_idle(&dev_priv->ring[VCS], &err) &&
i915_hangcheck_ring_idle(&dev_priv->ring[BCS], &err)) {
dev_priv->hangcheck_count = 0;
if (err)
goto repeat;
return;
}
if (INTEL_INFO(dev)->gen < 4) {
acthd = I915_READ(ACTHD);
instdone = I915_READ(INSTDONE);
instdone1 = 0;
} else {
acthd = I915_READ(ACTHD_I965);
instdone = I915_READ(INSTDONE_I965);
instdone1 = I915_READ(INSTDONE1);
}
if (dev_priv->last_acthd == acthd &&
dev_priv->last_instdone == instdone &&
dev_priv->last_instdone1 == instdone1) {
if (dev_priv->hangcheck_count++ > 1) {
DRM_ERROR("Hangcheck timer elapsed... GPU hung\n");
if (!IS_GEN2(dev)) {
if (kick_ring(&dev_priv->ring[RCS]))
goto repeat;
if (HAS_BSD(dev) &&
kick_ring(&dev_priv->ring[VCS]))
goto repeat;
if (HAS_BLT(dev) &&
kick_ring(&dev_priv->ring[BCS]))
goto repeat;
}
i915_handle_error(dev, true);
return;
}
} else {
dev_priv->hangcheck_count = 0;
dev_priv->last_acthd = acthd;
dev_priv->last_instdone = instdone;
dev_priv->last_instdone1 = instdone1;
}
repeat:
mod_timer(&dev_priv->hangcheck_timer,
jiffies + msecs_to_jiffies(DRM_I915_HANGCHECK_PERIOD));
}
static void ironlake_irq_preinstall(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
atomic_set(&dev_priv->irq_received, 0);
INIT_WORK(&dev_priv->hotplug_work, i915_hotplug_work_func);
INIT_WORK(&dev_priv->error_work, i915_error_work_func);
if (IS_GEN6(dev) || IS_IVYBRIDGE(dev))
INIT_WORK(&dev_priv->rps_work, gen6_pm_rps_work);
I915_WRITE(HWSTAM, 0xeffe);
if (IS_GEN6(dev) || IS_GEN7(dev)) {
I915_WRITE(GEN6_BLITTER_HWSTAM, ~GEN6_BLITTER_USER_INTERRUPT);
I915_WRITE(GEN6_BSD_HWSTAM, ~GEN6_BSD_USER_INTERRUPT);
}
I915_WRITE(DEIMR, 0xffffffff);
I915_WRITE(DEIER, 0x0);
POSTING_READ(DEIER);
I915_WRITE(GTIMR, 0xffffffff);
I915_WRITE(GTIER, 0x0);
POSTING_READ(GTIER);
I915_WRITE(SDEIMR, 0xffffffff);
I915_WRITE(SDEIER, 0x0);
POSTING_READ(SDEIER);
}
static int ironlake_irq_postinstall(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
u32 display_mask = DE_MASTER_IRQ_CONTROL | DE_GSE | DE_PCH_EVENT |
DE_PLANEA_FLIP_DONE | DE_PLANEB_FLIP_DONE;
u32 render_irqs;
u32 hotplug_mask;
DRM_INIT_WAITQUEUE(&dev_priv->ring[RCS].irq_queue);
if (HAS_BSD(dev))
DRM_INIT_WAITQUEUE(&dev_priv->ring[VCS].irq_queue);
if (HAS_BLT(dev))
DRM_INIT_WAITQUEUE(&dev_priv->ring[BCS].irq_queue);
dev_priv->vblank_pipe = DRM_I915_VBLANK_PIPE_A | DRM_I915_VBLANK_PIPE_B;
dev_priv->irq_mask = ~display_mask;
I915_WRITE(DEIIR, I915_READ(DEIIR));
I915_WRITE(DEIMR, dev_priv->irq_mask);
I915_WRITE(DEIER, display_mask | DE_PIPEA_VBLANK | DE_PIPEB_VBLANK);
POSTING_READ(DEIER);
dev_priv->gt_irq_mask = ~0;
I915_WRITE(GTIIR, I915_READ(GTIIR));
I915_WRITE(GTIMR, dev_priv->gt_irq_mask);
if (IS_GEN6(dev))
render_irqs =
GT_USER_INTERRUPT |
GT_GEN6_BSD_USER_INTERRUPT |
GT_BLT_USER_INTERRUPT;
else
render_irqs =
GT_USER_INTERRUPT |
GT_PIPE_NOTIFY |
GT_BSD_USER_INTERRUPT;
I915_WRITE(GTIER, render_irqs);
POSTING_READ(GTIER);
if (HAS_PCH_CPT(dev)) {
hotplug_mask = (SDE_CRT_HOTPLUG_CPT |
SDE_PORTB_HOTPLUG_CPT |
SDE_PORTC_HOTPLUG_CPT |
SDE_PORTD_HOTPLUG_CPT);
} else {
hotplug_mask = (SDE_CRT_HOTPLUG |
SDE_PORTB_HOTPLUG |
SDE_PORTC_HOTPLUG |
SDE_PORTD_HOTPLUG |
SDE_AUX_MASK);
}
dev_priv->pch_irq_mask = ~hotplug_mask;
I915_WRITE(SDEIIR, I915_READ(SDEIIR));
I915_WRITE(SDEIMR, dev_priv->pch_irq_mask);
I915_WRITE(SDEIER, hotplug_mask);
POSTING_READ(SDEIER);
if (IS_IRONLAKE_M(dev)) {
I915_WRITE(DEIIR, DE_PCU_EVENT);
I915_WRITE(DEIER, I915_READ(DEIER) | DE_PCU_EVENT);
ironlake_enable_display_irq(dev_priv, DE_PCU_EVENT);
}
return 0;
}
static int ivybridge_irq_postinstall(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
u32 display_mask = DE_MASTER_IRQ_CONTROL | DE_GSE_IVB |
DE_PCH_EVENT_IVB | DE_PLANEA_FLIP_DONE_IVB |
DE_PLANEB_FLIP_DONE_IVB;
u32 render_irqs;
u32 hotplug_mask;
DRM_INIT_WAITQUEUE(&dev_priv->ring[RCS].irq_queue);
if (HAS_BSD(dev))
DRM_INIT_WAITQUEUE(&dev_priv->ring[VCS].irq_queue);
if (HAS_BLT(dev))
DRM_INIT_WAITQUEUE(&dev_priv->ring[BCS].irq_queue);
dev_priv->vblank_pipe = DRM_I915_VBLANK_PIPE_A | DRM_I915_VBLANK_PIPE_B;
dev_priv->irq_mask = ~display_mask;
I915_WRITE(DEIIR, I915_READ(DEIIR));
I915_WRITE(DEIMR, dev_priv->irq_mask);
I915_WRITE(DEIER, display_mask | DE_PIPEA_VBLANK_IVB |
DE_PIPEB_VBLANK_IVB);
POSTING_READ(DEIER);
dev_priv->gt_irq_mask = ~0;
I915_WRITE(GTIIR, I915_READ(GTIIR));
I915_WRITE(GTIMR, dev_priv->gt_irq_mask);
render_irqs = GT_USER_INTERRUPT | GT_GEN6_BSD_USER_INTERRUPT |
GT_BLT_USER_INTERRUPT;
I915_WRITE(GTIER, render_irqs);
POSTING_READ(GTIER);
hotplug_mask = (SDE_CRT_HOTPLUG_CPT |
SDE_PORTB_HOTPLUG_CPT |
SDE_PORTC_HOTPLUG_CPT |
SDE_PORTD_HOTPLUG_CPT);
dev_priv->pch_irq_mask = ~hotplug_mask;
I915_WRITE(SDEIIR, I915_READ(SDEIIR));
I915_WRITE(SDEIMR, dev_priv->pch_irq_mask);
I915_WRITE(SDEIER, hotplug_mask);
POSTING_READ(SDEIER);
return 0;
}
static void i915_driver_irq_preinstall(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
int pipe;
atomic_set(&dev_priv->irq_received, 0);
INIT_WORK(&dev_priv->hotplug_work, i915_hotplug_work_func);
INIT_WORK(&dev_priv->error_work, i915_error_work_func);
if (I915_HAS_HOTPLUG(dev)) {
I915_WRITE(PORT_HOTPLUG_EN, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
}
I915_WRITE(HWSTAM, 0xeffe);
for_each_pipe(pipe)
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(IMR, 0xffffffff);
I915_WRITE(IER, 0x0);
POSTING_READ(IER);
}
static int i915_driver_irq_postinstall(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
u32 enable_mask = I915_INTERRUPT_ENABLE_FIX | I915_INTERRUPT_ENABLE_VAR;
u32 error_mask;
dev_priv->vblank_pipe = DRM_I915_VBLANK_PIPE_A | DRM_I915_VBLANK_PIPE_B;
dev_priv->irq_mask = ~I915_INTERRUPT_ENABLE_FIX;
dev_priv->pipestat[0] = 0;
dev_priv->pipestat[1] = 0;
if (I915_HAS_HOTPLUG(dev)) {
enable_mask |= I915_DISPLAY_PORT_INTERRUPT;
dev_priv->irq_mask &= ~I915_DISPLAY_PORT_INTERRUPT;
}
if (IS_G4X(dev)) {
error_mask = ~(GM45_ERROR_PAGE_TABLE |
GM45_ERROR_MEM_PRIV |
GM45_ERROR_CP_PRIV |
I915_ERROR_MEMORY_REFRESH);
} else {
error_mask = ~(I915_ERROR_PAGE_TABLE |
I915_ERROR_MEMORY_REFRESH);
}
I915_WRITE(EMR, error_mask);
I915_WRITE(IMR, dev_priv->irq_mask);
I915_WRITE(IER, enable_mask);
POSTING_READ(IER);
if (I915_HAS_HOTPLUG(dev)) {
u32 hotplug_en = I915_READ(PORT_HOTPLUG_EN);
if (dev_priv->hotplug_supported_mask & HDMIB_HOTPLUG_INT_STATUS)
hotplug_en |= HDMIB_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & HDMIC_HOTPLUG_INT_STATUS)
hotplug_en |= HDMIC_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & HDMID_HOTPLUG_INT_STATUS)
hotplug_en |= HDMID_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & SDVOC_HOTPLUG_INT_STATUS)
hotplug_en |= SDVOC_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & SDVOB_HOTPLUG_INT_STATUS)
hotplug_en |= SDVOB_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & CRT_HOTPLUG_INT_STATUS) {
hotplug_en |= CRT_HOTPLUG_INT_EN;
if (IS_G4X(dev))
hotplug_en |= CRT_HOTPLUG_ACTIVATION_PERIOD_64;
hotplug_en |= CRT_HOTPLUG_VOLTAGE_COMPARE_50;
}
I915_WRITE(PORT_HOTPLUG_EN, hotplug_en);
}
intel_opregion_enable_asle(dev);
return 0;
}
static void ironlake_irq_uninstall(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
if (!dev_priv)
return;
dev_priv->vblank_pipe = 0;
I915_WRITE(HWSTAM, 0xffffffff);
I915_WRITE(DEIMR, 0xffffffff);
I915_WRITE(DEIER, 0x0);
I915_WRITE(DEIIR, I915_READ(DEIIR));
I915_WRITE(GTIMR, 0xffffffff);
I915_WRITE(GTIER, 0x0);
I915_WRITE(GTIIR, I915_READ(GTIIR));
}
static void i915_driver_irq_uninstall(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
int pipe;
if (!dev_priv)
return;
dev_priv->vblank_pipe = 0;
if (I915_HAS_HOTPLUG(dev)) {
I915_WRITE(PORT_HOTPLUG_EN, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
}
I915_WRITE(HWSTAM, 0xffffffff);
for_each_pipe(pipe)
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(IMR, 0xffffffff);
I915_WRITE(IER, 0x0);
for_each_pipe(pipe)
I915_WRITE(PIPESTAT(pipe),
I915_READ(PIPESTAT(pipe)) & 0x8000ffff);
I915_WRITE(IIR, I915_READ(IIR));
}
void intel_irq_init(struct drm_device *dev)
{
dev->driver->get_vblank_counter = i915_get_vblank_counter;
dev->max_vblank_count = 0xffffff;
if (IS_G4X(dev) || IS_GEN5(dev) || IS_GEN6(dev) || IS_IVYBRIDGE(dev)) {
dev->max_vblank_count = 0xffffffff;
dev->driver->get_vblank_counter = gm45_get_vblank_counter;
}
if (drm_core_check_feature(dev, DRIVER_MODESET))
dev->driver->get_vblank_timestamp = i915_get_vblank_timestamp;
else
dev->driver->get_vblank_timestamp = NULL;
dev->driver->get_scanout_position = i915_get_crtc_scanoutpos;
if (IS_IVYBRIDGE(dev)) {
dev->driver->irq_handler = ivybridge_irq_handler;
dev->driver->irq_preinstall = ironlake_irq_preinstall;
dev->driver->irq_postinstall = ivybridge_irq_postinstall;
dev->driver->irq_uninstall = ironlake_irq_uninstall;
dev->driver->enable_vblank = ivybridge_enable_vblank;
dev->driver->disable_vblank = ivybridge_disable_vblank;
} else if (HAS_PCH_SPLIT(dev)) {
dev->driver->irq_handler = ironlake_irq_handler;
dev->driver->irq_preinstall = ironlake_irq_preinstall;
dev->driver->irq_postinstall = ironlake_irq_postinstall;
dev->driver->irq_uninstall = ironlake_irq_uninstall;
dev->driver->enable_vblank = ironlake_enable_vblank;
dev->driver->disable_vblank = ironlake_disable_vblank;
} else {
dev->driver->irq_preinstall = i915_driver_irq_preinstall;
dev->driver->irq_postinstall = i915_driver_irq_postinstall;
dev->driver->irq_uninstall = i915_driver_irq_uninstall;
dev->driver->irq_handler = i915_driver_irq_handler;
dev->driver->enable_vblank = i915_enable_vblank;
dev->driver->disable_vblank = i915_disable_vblank;
}
}
