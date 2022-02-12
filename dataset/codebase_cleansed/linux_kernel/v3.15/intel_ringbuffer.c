static inline int ring_space(struct intel_ring_buffer *ring)
{
int space = (ring->head & HEAD_ADDR) - (ring->tail + I915_RING_FREE_SPACE);
if (space < 0)
space += ring->size;
return space;
}
void __intel_ring_advance(struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
ring->tail &= ring->size - 1;
if (dev_priv->gpu_error.stop_rings & intel_ring_flag(ring))
return;
ring->write_tail(ring, ring->tail);
}
static int
gen2_render_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate_domains,
u32 flush_domains)
{
u32 cmd;
int ret;
cmd = MI_FLUSH;
if (((invalidate_domains|flush_domains) & I915_GEM_DOMAIN_RENDER) == 0)
cmd |= MI_NO_WRITE_FLUSH;
if (invalidate_domains & I915_GEM_DOMAIN_SAMPLER)
cmd |= MI_READ_FLUSH;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
gen4_render_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate_domains,
u32 flush_domains)
{
struct drm_device *dev = ring->dev;
u32 cmd;
int ret;
cmd = MI_FLUSH | MI_NO_WRITE_FLUSH;
if ((invalidate_domains|flush_domains) & I915_GEM_DOMAIN_RENDER)
cmd &= ~MI_NO_WRITE_FLUSH;
if (invalidate_domains & I915_GEM_DOMAIN_INSTRUCTION)
cmd |= MI_EXE_FLUSH;
if (invalidate_domains & I915_GEM_DOMAIN_COMMAND &&
(IS_G4X(dev) || IS_GEN5(dev)))
cmd |= MI_INVALIDATE_ISP;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
intel_emit_post_sync_nonzero_flush(struct intel_ring_buffer *ring)
{
u32 scratch_addr = ring->scratch.gtt_offset + 128;
int ret;
ret = intel_ring_begin(ring, 6);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(5));
intel_ring_emit(ring, PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_STALL_AT_SCOREBOARD);
intel_ring_emit(ring, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
ret = intel_ring_begin(ring, 6);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(5));
intel_ring_emit(ring, PIPE_CONTROL_QW_WRITE);
intel_ring_emit(ring, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
gen6_render_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate_domains, u32 flush_domains)
{
u32 flags = 0;
u32 scratch_addr = ring->scratch.gtt_offset + 128;
int ret;
ret = intel_emit_post_sync_nonzero_flush(ring);
if (ret)
return ret;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_CS_STALL;
}
if (invalidate_domains) {
flags |= PIPE_CONTROL_TLB_INVALIDATE;
flags |= PIPE_CONTROL_INSTRUCTION_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_VF_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_CONST_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_STATE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_QW_WRITE | PIPE_CONTROL_CS_STALL;
}
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(ring, flags);
intel_ring_emit(ring, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static int
gen7_render_ring_cs_stall_wa(struct intel_ring_buffer *ring)
{
int ret;
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(ring, PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_STALL_AT_SCOREBOARD);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static int gen7_ring_fbc_flush(struct intel_ring_buffer *ring, u32 value)
{
int ret;
if (!ring->fbc_dirty)
return 0;
ret = intel_ring_begin(ring, 6);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit(ring, MSG_FBC_REND_STATE);
intel_ring_emit(ring, value);
intel_ring_emit(ring, MI_STORE_REGISTER_MEM(1) | MI_SRM_LRM_GLOBAL_GTT);
intel_ring_emit(ring, MSG_FBC_REND_STATE);
intel_ring_emit(ring, ring->scratch.gtt_offset + 256);
intel_ring_advance(ring);
ring->fbc_dirty = false;
return 0;
}
static int
gen7_render_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate_domains, u32 flush_domains)
{
u32 flags = 0;
u32 scratch_addr = ring->scratch.gtt_offset + 128;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
}
if (invalidate_domains) {
flags |= PIPE_CONTROL_TLB_INVALIDATE;
flags |= PIPE_CONTROL_INSTRUCTION_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_VF_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_CONST_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_STATE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_QW_WRITE;
flags |= PIPE_CONTROL_GLOBAL_GTT_IVB;
gen7_render_ring_cs_stall_wa(ring);
}
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(ring, flags);
intel_ring_emit(ring, scratch_addr);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
if (!invalidate_domains && flush_domains)
return gen7_ring_fbc_flush(ring, FBC_REND_NUKE);
return 0;
}
static int
gen8_render_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate_domains, u32 flush_domains)
{
u32 flags = 0;
u32 scratch_addr = ring->scratch.gtt_offset + 128;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
}
if (invalidate_domains) {
flags |= PIPE_CONTROL_TLB_INVALIDATE;
flags |= PIPE_CONTROL_INSTRUCTION_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_VF_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_CONST_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_STATE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_QW_WRITE;
flags |= PIPE_CONTROL_GLOBAL_GTT_IVB;
}
ret = intel_ring_begin(ring, 6);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(ring, flags);
intel_ring_emit(ring, scratch_addr);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static void ring_write_tail(struct intel_ring_buffer *ring,
u32 value)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
I915_WRITE_TAIL(ring, value);
}
u64 intel_ring_get_active_head(struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
u64 acthd;
if (INTEL_INFO(ring->dev)->gen >= 8)
acthd = I915_READ64_2x32(RING_ACTHD(ring->mmio_base),
RING_ACTHD_UDW(ring->mmio_base));
else if (INTEL_INFO(ring->dev)->gen >= 4)
acthd = I915_READ(RING_ACTHD(ring->mmio_base));
else
acthd = I915_READ(ACTHD);
return acthd;
}
static void ring_setup_phys_status_page(struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
u32 addr;
addr = dev_priv->status_page_dmah->busaddr;
if (INTEL_INFO(ring->dev)->gen >= 4)
addr |= (dev_priv->status_page_dmah->busaddr >> 28) & 0xf0;
I915_WRITE(HWS_PGA, addr);
}
static bool stop_ring(struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv = to_i915(ring->dev);
if (!IS_GEN2(ring->dev)) {
I915_WRITE_MODE(ring, _MASKED_BIT_ENABLE(STOP_RING));
if (wait_for_atomic((I915_READ_MODE(ring) & MODE_IDLE) != 0, 1000)) {
DRM_ERROR("%s :timed out trying to stop ring\n", ring->name);
return false;
}
}
I915_WRITE_CTL(ring, 0);
I915_WRITE_HEAD(ring, 0);
ring->write_tail(ring, 0);
if (!IS_GEN2(ring->dev)) {
(void)I915_READ_CTL(ring);
I915_WRITE_MODE(ring, _MASKED_BIT_DISABLE(STOP_RING));
}
return (I915_READ_HEAD(ring) & HEAD_ADDR) == 0;
}
static int init_ring_common(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj = ring->obj;
int ret = 0;
gen6_gt_force_wake_get(dev_priv, FORCEWAKE_ALL);
if (!stop_ring(ring)) {
DRM_DEBUG_KMS("%s head not reset to zero "
"ctl %08x head %08x tail %08x start %08x\n",
ring->name,
I915_READ_CTL(ring),
I915_READ_HEAD(ring),
I915_READ_TAIL(ring),
I915_READ_START(ring));
if (!stop_ring(ring)) {
DRM_ERROR("failed to set %s head to zero "
"ctl %08x head %08x tail %08x start %08x\n",
ring->name,
I915_READ_CTL(ring),
I915_READ_HEAD(ring),
I915_READ_TAIL(ring),
I915_READ_START(ring));
ret = -EIO;
goto out;
}
}
if (I915_NEED_GFX_HWS(dev))
intel_ring_setup_status_page(ring);
else
ring_setup_phys_status_page(ring);
I915_WRITE_START(ring, i915_gem_obj_ggtt_offset(obj));
I915_WRITE_CTL(ring,
((ring->size - PAGE_SIZE) & RING_NR_PAGES)
| RING_VALID);
if (wait_for((I915_READ_CTL(ring) & RING_VALID) != 0 &&
I915_READ_START(ring) == i915_gem_obj_ggtt_offset(obj) &&
(I915_READ_HEAD(ring) & HEAD_ADDR) == 0, 50)) {
DRM_ERROR("%s initialization failed "
"ctl %08x head %08x tail %08x start %08x\n",
ring->name,
I915_READ_CTL(ring),
I915_READ_HEAD(ring),
I915_READ_TAIL(ring),
I915_READ_START(ring));
ret = -EIO;
goto out;
}
if (!drm_core_check_feature(ring->dev, DRIVER_MODESET))
i915_kernel_lost_context(ring->dev);
else {
ring->head = I915_READ_HEAD(ring);
ring->tail = I915_READ_TAIL(ring) & TAIL_ADDR;
ring->space = ring_space(ring);
ring->last_retired_head = -1;
}
memset(&ring->hangcheck, 0, sizeof(ring->hangcheck));
out:
gen6_gt_force_wake_put(dev_priv, FORCEWAKE_ALL);
return ret;
}
static int
init_pipe_control(struct intel_ring_buffer *ring)
{
int ret;
if (ring->scratch.obj)
return 0;
ring->scratch.obj = i915_gem_alloc_object(ring->dev, 4096);
if (ring->scratch.obj == NULL) {
DRM_ERROR("Failed to allocate seqno page\n");
ret = -ENOMEM;
goto err;
}
ret = i915_gem_object_set_cache_level(ring->scratch.obj, I915_CACHE_LLC);
if (ret)
goto err_unref;
ret = i915_gem_obj_ggtt_pin(ring->scratch.obj, 4096, 0);
if (ret)
goto err_unref;
ring->scratch.gtt_offset = i915_gem_obj_ggtt_offset(ring->scratch.obj);
ring->scratch.cpu_page = kmap(sg_page(ring->scratch.obj->pages->sgl));
if (ring->scratch.cpu_page == NULL) {
ret = -ENOMEM;
goto err_unpin;
}
DRM_DEBUG_DRIVER("%s pipe control offset: 0x%08x\n",
ring->name, ring->scratch.gtt_offset);
return 0;
err_unpin:
i915_gem_object_ggtt_unpin(ring->scratch.obj);
err_unref:
drm_gem_object_unreference(&ring->scratch.obj->base);
err:
return ret;
}
static int init_render_ring(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret = init_ring_common(ring);
if (INTEL_INFO(dev)->gen >= 4 && INTEL_INFO(dev)->gen < 7)
I915_WRITE(MI_MODE, _MASKED_BIT_ENABLE(VS_TIMER_DISPATCH));
if (INTEL_INFO(dev)->gen >= 6)
I915_WRITE(MI_MODE, _MASKED_BIT_ENABLE(ASYNC_FLIP_PERF_DISABLE));
if (INTEL_INFO(dev)->gen == 6)
I915_WRITE(GFX_MODE,
_MASKED_BIT_ENABLE(GFX_TLB_INVALIDATE_ALWAYS));
if (IS_GEN7(dev))
I915_WRITE(GFX_MODE_GEN7,
_MASKED_BIT_DISABLE(GFX_TLB_INVALIDATE_ALWAYS) |
_MASKED_BIT_ENABLE(GFX_REPLAY_MODE));
if (INTEL_INFO(dev)->gen >= 5) {
ret = init_pipe_control(ring);
if (ret)
return ret;
}
if (IS_GEN6(dev)) {
I915_WRITE(CACHE_MODE_0,
_MASKED_BIT_DISABLE(CM0_STC_EVICT_DISABLE_LRA_SNB));
ring->itlb_before_ctx_switch =
!!(I915_READ(GFX_MODE) & GFX_TLB_INVALIDATE_ALWAYS);
}
if (INTEL_INFO(dev)->gen >= 6)
I915_WRITE(INSTPM, _MASKED_BIT_ENABLE(INSTPM_FORCE_ORDERING));
if (HAS_L3_DPF(dev))
I915_WRITE_IMR(ring, ~GT_PARITY_ERROR(dev));
return ret;
}
static void render_ring_cleanup(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
if (ring->scratch.obj == NULL)
return;
if (INTEL_INFO(dev)->gen >= 5) {
kunmap(sg_page(ring->scratch.obj->pages->sgl));
i915_gem_object_ggtt_unpin(ring->scratch.obj);
}
drm_gem_object_unreference(&ring->scratch.obj->base);
ring->scratch.obj = NULL;
}
static void
update_mboxes(struct intel_ring_buffer *ring,
u32 mmio_offset)
{
#define MBOX_UPDATE_DWORDS 4
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit(ring, mmio_offset);
intel_ring_emit(ring, ring->outstanding_lazy_seqno);
intel_ring_emit(ring, MI_NOOP);
}
static int
gen6_add_request(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *useless;
int i, ret, num_dwords = 4;
if (i915_semaphore_is_enabled(dev))
num_dwords += ((I915_NUM_RINGS-1) * MBOX_UPDATE_DWORDS);
#undef MBOX_UPDATE_DWORDS
ret = intel_ring_begin(ring, num_dwords);
if (ret)
return ret;
if (i915_semaphore_is_enabled(dev)) {
for_each_ring(useless, dev_priv, i) {
u32 mbox_reg = ring->signal_mbox[i];
if (mbox_reg != GEN6_NOSYNC)
update_mboxes(ring, mbox_reg);
}
}
intel_ring_emit(ring, MI_STORE_DWORD_INDEX);
intel_ring_emit(ring, I915_GEM_HWS_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
intel_ring_emit(ring, ring->outstanding_lazy_seqno);
intel_ring_emit(ring, MI_USER_INTERRUPT);
__intel_ring_advance(ring);
return 0;
}
static inline bool i915_gem_has_seqno_wrapped(struct drm_device *dev,
u32 seqno)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return dev_priv->last_seqno < seqno;
}
static int
gen6_ring_sync(struct intel_ring_buffer *waiter,
struct intel_ring_buffer *signaller,
u32 seqno)
{
int ret;
u32 dw1 = MI_SEMAPHORE_MBOX |
MI_SEMAPHORE_COMPARE |
MI_SEMAPHORE_REGISTER;
seqno -= 1;
WARN_ON(signaller->semaphore_register[waiter->id] ==
MI_SEMAPHORE_SYNC_INVALID);
ret = intel_ring_begin(waiter, 4);
if (ret)
return ret;
if (likely(!i915_gem_has_seqno_wrapped(waiter->dev, seqno))) {
intel_ring_emit(waiter,
dw1 |
signaller->semaphore_register[waiter->id]);
intel_ring_emit(waiter, seqno);
intel_ring_emit(waiter, 0);
intel_ring_emit(waiter, MI_NOOP);
} else {
intel_ring_emit(waiter, MI_NOOP);
intel_ring_emit(waiter, MI_NOOP);
intel_ring_emit(waiter, MI_NOOP);
intel_ring_emit(waiter, MI_NOOP);
}
intel_ring_advance(waiter);
return 0;
}
static int
pc_render_add_request(struct intel_ring_buffer *ring)
{
u32 scratch_addr = ring->scratch.gtt_offset + 128;
int ret;
ret = intel_ring_begin(ring, 32);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4) | PIPE_CONTROL_QW_WRITE |
PIPE_CONTROL_WRITE_FLUSH |
PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE);
intel_ring_emit(ring, ring->scratch.gtt_offset | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(ring, ring->outstanding_lazy_seqno);
intel_ring_emit(ring, 0);
PIPE_CONTROL_FLUSH(ring, scratch_addr);
scratch_addr += 128;
PIPE_CONTROL_FLUSH(ring, scratch_addr);
scratch_addr += 128;
PIPE_CONTROL_FLUSH(ring, scratch_addr);
scratch_addr += 128;
PIPE_CONTROL_FLUSH(ring, scratch_addr);
scratch_addr += 128;
PIPE_CONTROL_FLUSH(ring, scratch_addr);
scratch_addr += 128;
PIPE_CONTROL_FLUSH(ring, scratch_addr);
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4) | PIPE_CONTROL_QW_WRITE |
PIPE_CONTROL_WRITE_FLUSH |
PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE |
PIPE_CONTROL_NOTIFY);
intel_ring_emit(ring, ring->scratch.gtt_offset | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(ring, ring->outstanding_lazy_seqno);
intel_ring_emit(ring, 0);
__intel_ring_advance(ring);
return 0;
}
static u32
gen6_ring_get_seqno(struct intel_ring_buffer *ring, bool lazy_coherency)
{
if (!lazy_coherency) {
struct drm_i915_private *dev_priv = ring->dev->dev_private;
POSTING_READ(RING_ACTHD(ring->mmio_base));
}
return intel_read_status_page(ring, I915_GEM_HWS_INDEX);
}
static u32
ring_get_seqno(struct intel_ring_buffer *ring, bool lazy_coherency)
{
return intel_read_status_page(ring, I915_GEM_HWS_INDEX);
}
static void
ring_set_seqno(struct intel_ring_buffer *ring, u32 seqno)
{
intel_write_status_page(ring, I915_GEM_HWS_INDEX, seqno);
}
static u32
pc_render_get_seqno(struct intel_ring_buffer *ring, bool lazy_coherency)
{
return ring->scratch.cpu_page[0];
}
static void
pc_render_set_seqno(struct intel_ring_buffer *ring, u32 seqno)
{
ring->scratch.cpu_page[0] = seqno;
}
static bool
gen5_ring_get_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0)
ilk_enable_gt_irq(dev_priv, ring->irq_enable_mask);
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void
gen5_ring_put_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0)
ilk_disable_gt_irq(dev_priv, ring->irq_enable_mask);
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
static bool
i9xx_ring_get_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0) {
dev_priv->irq_mask &= ~ring->irq_enable_mask;
I915_WRITE(IMR, dev_priv->irq_mask);
POSTING_READ(IMR);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void
i9xx_ring_put_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0) {
dev_priv->irq_mask |= ring->irq_enable_mask;
I915_WRITE(IMR, dev_priv->irq_mask);
POSTING_READ(IMR);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
static bool
i8xx_ring_get_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0) {
dev_priv->irq_mask &= ~ring->irq_enable_mask;
I915_WRITE16(IMR, dev_priv->irq_mask);
POSTING_READ16(IMR);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void
i8xx_ring_put_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0) {
dev_priv->irq_mask |= ring->irq_enable_mask;
I915_WRITE16(IMR, dev_priv->irq_mask);
POSTING_READ16(IMR);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
void intel_ring_setup_status_page(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = ring->dev->dev_private;
u32 mmio = 0;
if (IS_GEN7(dev)) {
switch (ring->id) {
case RCS:
mmio = RENDER_HWS_PGA_GEN7;
break;
case BCS:
mmio = BLT_HWS_PGA_GEN7;
break;
case VCS:
mmio = BSD_HWS_PGA_GEN7;
break;
case VECS:
mmio = VEBOX_HWS_PGA_GEN7;
break;
}
} else if (IS_GEN6(ring->dev)) {
mmio = RING_HWS_PGA_GEN6(ring->mmio_base);
} else {
mmio = RING_HWS_PGA(ring->mmio_base);
}
I915_WRITE(mmio, (u32)ring->status_page.gfx_addr);
POSTING_READ(mmio);
if (INTEL_INFO(dev)->gen >= 6 && INTEL_INFO(dev)->gen < 8) {
u32 reg = RING_INSTPM(ring->mmio_base);
WARN_ON((I915_READ_MODE(ring) & MODE_IDLE) == 0);
I915_WRITE(reg,
_MASKED_BIT_ENABLE(INSTPM_TLB_INVALIDATE |
INSTPM_SYNC_FLUSH));
if (wait_for((I915_READ(reg) & INSTPM_SYNC_FLUSH) == 0,
1000))
DRM_ERROR("%s: wait for SyncFlush to complete for TLB invalidation timed out\n",
ring->name);
}
}
static int
bsd_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate_domains,
u32 flush_domains)
{
int ret;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_FLUSH);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
i9xx_add_request(struct intel_ring_buffer *ring)
{
int ret;
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_STORE_DWORD_INDEX);
intel_ring_emit(ring, I915_GEM_HWS_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
intel_ring_emit(ring, ring->outstanding_lazy_seqno);
intel_ring_emit(ring, MI_USER_INTERRUPT);
__intel_ring_advance(ring);
return 0;
}
static bool
gen6_ring_get_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0) {
if (HAS_L3_DPF(dev) && ring->id == RCS)
I915_WRITE_IMR(ring,
~(ring->irq_enable_mask |
GT_PARITY_ERROR(dev)));
else
I915_WRITE_IMR(ring, ~ring->irq_enable_mask);
ilk_enable_gt_irq(dev_priv, ring->irq_enable_mask);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void
gen6_ring_put_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0) {
if (HAS_L3_DPF(dev) && ring->id == RCS)
I915_WRITE_IMR(ring, ~GT_PARITY_ERROR(dev));
else
I915_WRITE_IMR(ring, ~0);
ilk_disable_gt_irq(dev_priv, ring->irq_enable_mask);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
static bool
hsw_vebox_get_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0) {
I915_WRITE_IMR(ring, ~ring->irq_enable_mask);
snb_enable_pm_irq(dev_priv, ring->irq_enable_mask);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void
hsw_vebox_put_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0) {
I915_WRITE_IMR(ring, ~0);
snb_disable_pm_irq(dev_priv, ring->irq_enable_mask);
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
static bool
gen8_ring_get_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (!dev->irq_enabled)
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0) {
if (HAS_L3_DPF(dev) && ring->id == RCS) {
I915_WRITE_IMR(ring,
~(ring->irq_enable_mask |
GT_RENDER_L3_PARITY_ERROR_INTERRUPT));
} else {
I915_WRITE_IMR(ring, ~ring->irq_enable_mask);
}
POSTING_READ(RING_IMR(ring->mmio_base));
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void
gen8_ring_put_irq(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0) {
if (HAS_L3_DPF(dev) && ring->id == RCS) {
I915_WRITE_IMR(ring,
~GT_RENDER_L3_PARITY_ERROR_INTERRUPT);
} else {
I915_WRITE_IMR(ring, ~0);
}
POSTING_READ(RING_IMR(ring->mmio_base));
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
static int
i965_dispatch_execbuffer(struct intel_ring_buffer *ring,
u32 offset, u32 length,
unsigned flags)
{
int ret;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring,
MI_BATCH_BUFFER_START |
MI_BATCH_GTT |
(flags & I915_DISPATCH_SECURE ? 0 : MI_BATCH_NON_SECURE_I965));
intel_ring_emit(ring, offset);
intel_ring_advance(ring);
return 0;
}
static int
i830_dispatch_execbuffer(struct intel_ring_buffer *ring,
u32 offset, u32 len,
unsigned flags)
{
int ret;
if (flags & I915_DISPATCH_PINNED) {
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER);
intel_ring_emit(ring, offset | (flags & I915_DISPATCH_SECURE ? 0 : MI_BATCH_NON_SECURE));
intel_ring_emit(ring, offset + len - 8);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
} else {
u32 cs_offset = ring->scratch.gtt_offset;
if (len > I830_BATCH_LIMIT)
return -ENOSPC;
ret = intel_ring_begin(ring, 9+3);
if (ret)
return ret;
intel_ring_emit(ring, XY_SRC_COPY_BLT_CMD |
XY_SRC_COPY_BLT_WRITE_ALPHA |
XY_SRC_COPY_BLT_WRITE_RGB);
intel_ring_emit(ring, BLT_DEPTH_32 | BLT_ROP_GXCOPY | 4096);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, (DIV_ROUND_UP(len, 4096) << 16) | 1024);
intel_ring_emit(ring, cs_offset);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 4096);
intel_ring_emit(ring, offset);
intel_ring_emit(ring, MI_FLUSH);
intel_ring_emit(ring, MI_BATCH_BUFFER);
intel_ring_emit(ring, cs_offset | (flags & I915_DISPATCH_SECURE ? 0 : MI_BATCH_NON_SECURE));
intel_ring_emit(ring, cs_offset + len - 8);
intel_ring_advance(ring);
}
return 0;
}
static int
i915_dispatch_execbuffer(struct intel_ring_buffer *ring,
u32 offset, u32 len,
unsigned flags)
{
int ret;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER_START | MI_BATCH_GTT);
intel_ring_emit(ring, offset | (flags & I915_DISPATCH_SECURE ? 0 : MI_BATCH_NON_SECURE));
intel_ring_advance(ring);
return 0;
}
static void cleanup_status_page(struct intel_ring_buffer *ring)
{
struct drm_i915_gem_object *obj;
obj = ring->status_page.obj;
if (obj == NULL)
return;
kunmap(sg_page(obj->pages->sgl));
i915_gem_object_ggtt_unpin(obj);
drm_gem_object_unreference(&obj->base);
ring->status_page.obj = NULL;
}
static int init_status_page(struct intel_ring_buffer *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_gem_object *obj;
int ret;
obj = i915_gem_alloc_object(dev, 4096);
if (obj == NULL) {
DRM_ERROR("Failed to allocate status page\n");
ret = -ENOMEM;
goto err;
}
ret = i915_gem_object_set_cache_level(obj, I915_CACHE_LLC);
if (ret)
goto err_unref;
ret = i915_gem_obj_ggtt_pin(obj, 4096, 0);
if (ret)
goto err_unref;
ring->status_page.gfx_addr = i915_gem_obj_ggtt_offset(obj);
ring->status_page.page_addr = kmap(sg_page(obj->pages->sgl));
if (ring->status_page.page_addr == NULL) {
ret = -ENOMEM;
goto err_unpin;
}
ring->status_page.obj = obj;
memset(ring->status_page.page_addr, 0, PAGE_SIZE);
DRM_DEBUG_DRIVER("%s hws offset: 0x%08x\n",
ring->name, ring->status_page.gfx_addr);
return 0;
err_unpin:
i915_gem_object_ggtt_unpin(obj);
err_unref:
drm_gem_object_unreference(&obj->base);
err:
return ret;
}
static int init_phys_status_page(struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
if (!dev_priv->status_page_dmah) {
dev_priv->status_page_dmah =
drm_pci_alloc(ring->dev, PAGE_SIZE, PAGE_SIZE);
if (!dev_priv->status_page_dmah)
return -ENOMEM;
}
ring->status_page.page_addr = dev_priv->status_page_dmah->vaddr;
memset(ring->status_page.page_addr, 0, PAGE_SIZE);
return 0;
}
static int intel_init_ring_buffer(struct drm_device *dev,
struct intel_ring_buffer *ring)
{
struct drm_i915_gem_object *obj;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ring->dev = dev;
INIT_LIST_HEAD(&ring->active_list);
INIT_LIST_HEAD(&ring->request_list);
ring->size = 32 * PAGE_SIZE;
memset(ring->sync_seqno, 0, sizeof(ring->sync_seqno));
init_waitqueue_head(&ring->irq_queue);
if (I915_NEED_GFX_HWS(dev)) {
ret = init_status_page(ring);
if (ret)
return ret;
} else {
BUG_ON(ring->id != RCS);
ret = init_phys_status_page(ring);
if (ret)
return ret;
}
obj = NULL;
if (!HAS_LLC(dev))
obj = i915_gem_object_create_stolen(dev, ring->size);
if (obj == NULL)
obj = i915_gem_alloc_object(dev, ring->size);
if (obj == NULL) {
DRM_ERROR("Failed to allocate ringbuffer\n");
ret = -ENOMEM;
goto err_hws;
}
ring->obj = obj;
ret = i915_gem_obj_ggtt_pin(obj, PAGE_SIZE, PIN_MAPPABLE);
if (ret)
goto err_unref;
ret = i915_gem_object_set_to_gtt_domain(obj, true);
if (ret)
goto err_unpin;
ring->virtual_start =
ioremap_wc(dev_priv->gtt.mappable_base + i915_gem_obj_ggtt_offset(obj),
ring->size);
if (ring->virtual_start == NULL) {
DRM_ERROR("Failed to map ringbuffer.\n");
ret = -EINVAL;
goto err_unpin;
}
ret = ring->init(ring);
if (ret)
goto err_unmap;
ring->effective_size = ring->size;
if (IS_I830(ring->dev) || IS_845G(ring->dev))
ring->effective_size -= 128;
i915_cmd_parser_init_ring(ring);
return 0;
err_unmap:
iounmap(ring->virtual_start);
err_unpin:
i915_gem_object_ggtt_unpin(obj);
err_unref:
drm_gem_object_unreference(&obj->base);
ring->obj = NULL;
err_hws:
cleanup_status_page(ring);
return ret;
}
void intel_cleanup_ring_buffer(struct intel_ring_buffer *ring)
{
struct drm_i915_private *dev_priv;
int ret;
if (ring->obj == NULL)
return;
dev_priv = ring->dev->dev_private;
ret = intel_ring_idle(ring);
if (ret && !i915_reset_in_progress(&dev_priv->gpu_error))
DRM_ERROR("failed to quiesce %s whilst cleaning up: %d\n",
ring->name, ret);
I915_WRITE_CTL(ring, 0);
iounmap(ring->virtual_start);
i915_gem_object_ggtt_unpin(ring->obj);
drm_gem_object_unreference(&ring->obj->base);
ring->obj = NULL;
ring->preallocated_lazy_request = NULL;
ring->outstanding_lazy_seqno = 0;
if (ring->cleanup)
ring->cleanup(ring);
cleanup_status_page(ring);
}
static int intel_ring_wait_request(struct intel_ring_buffer *ring, int n)
{
struct drm_i915_gem_request *request;
u32 seqno = 0, tail;
int ret;
if (ring->last_retired_head != -1) {
ring->head = ring->last_retired_head;
ring->last_retired_head = -1;
ring->space = ring_space(ring);
if (ring->space >= n)
return 0;
}
list_for_each_entry(request, &ring->request_list, list) {
int space;
if (request->tail == -1)
continue;
space = request->tail - (ring->tail + I915_RING_FREE_SPACE);
if (space < 0)
space += ring->size;
if (space >= n) {
seqno = request->seqno;
tail = request->tail;
break;
}
request->tail = -1;
}
if (seqno == 0)
return -ENOSPC;
ret = i915_wait_seqno(ring, seqno);
if (ret)
return ret;
ring->head = tail;
ring->space = ring_space(ring);
if (WARN_ON(ring->space < n))
return -ENOSPC;
return 0;
}
static int ring_wait_for_space(struct intel_ring_buffer *ring, int n)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long end;
int ret;
ret = intel_ring_wait_request(ring, n);
if (ret != -ENOSPC)
return ret;
__intel_ring_advance(ring);
trace_i915_ring_wait_begin(ring);
end = jiffies + 60 * HZ;
do {
ring->head = I915_READ_HEAD(ring);
ring->space = ring_space(ring);
if (ring->space >= n) {
trace_i915_ring_wait_end(ring);
return 0;
}
if (!drm_core_check_feature(dev, DRIVER_MODESET) &&
dev->primary->master) {
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
if (master_priv->sarea_priv)
master_priv->sarea_priv->perf_boxes |= I915_BOX_WAIT;
}
msleep(1);
ret = i915_gem_check_wedge(&dev_priv->gpu_error,
dev_priv->mm.interruptible);
if (ret)
return ret;
} while (!time_after(jiffies, end));
trace_i915_ring_wait_end(ring);
return -EBUSY;
}
static int intel_wrap_ring_buffer(struct intel_ring_buffer *ring)
{
uint32_t __iomem *virt;
int rem = ring->size - ring->tail;
if (ring->space < rem) {
int ret = ring_wait_for_space(ring, rem);
if (ret)
return ret;
}
virt = ring->virtual_start + ring->tail;
rem /= 4;
while (rem--)
iowrite32(MI_NOOP, virt++);
ring->tail = 0;
ring->space = ring_space(ring);
return 0;
}
int intel_ring_idle(struct intel_ring_buffer *ring)
{
u32 seqno;
int ret;
if (ring->outstanding_lazy_seqno) {
ret = i915_add_request(ring, NULL);
if (ret)
return ret;
}
if (list_empty(&ring->request_list))
return 0;
seqno = list_entry(ring->request_list.prev,
struct drm_i915_gem_request,
list)->seqno;
return i915_wait_seqno(ring, seqno);
}
static int
intel_ring_alloc_seqno(struct intel_ring_buffer *ring)
{
if (ring->outstanding_lazy_seqno)
return 0;
if (ring->preallocated_lazy_request == NULL) {
struct drm_i915_gem_request *request;
request = kmalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
ring->preallocated_lazy_request = request;
}
return i915_gem_get_seqno(ring->dev, &ring->outstanding_lazy_seqno);
}
static int __intel_ring_prepare(struct intel_ring_buffer *ring,
int bytes)
{
int ret;
if (unlikely(ring->tail + bytes > ring->effective_size)) {
ret = intel_wrap_ring_buffer(ring);
if (unlikely(ret))
return ret;
}
if (unlikely(ring->space < bytes)) {
ret = ring_wait_for_space(ring, bytes);
if (unlikely(ret))
return ret;
}
return 0;
}
int intel_ring_begin(struct intel_ring_buffer *ring,
int num_dwords)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
int ret;
ret = i915_gem_check_wedge(&dev_priv->gpu_error,
dev_priv->mm.interruptible);
if (ret)
return ret;
ret = __intel_ring_prepare(ring, num_dwords * sizeof(uint32_t));
if (ret)
return ret;
ret = intel_ring_alloc_seqno(ring);
if (ret)
return ret;
ring->space -= num_dwords * sizeof(uint32_t);
return 0;
}
int intel_ring_cacheline_align(struct intel_ring_buffer *ring)
{
int num_dwords = (64 - (ring->tail & 63)) / sizeof(uint32_t);
int ret;
if (num_dwords == 0)
return 0;
ret = intel_ring_begin(ring, num_dwords);
if (ret)
return ret;
while (num_dwords--)
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
void intel_ring_init_seqno(struct intel_ring_buffer *ring, u32 seqno)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
BUG_ON(ring->outstanding_lazy_seqno);
if (INTEL_INFO(ring->dev)->gen >= 6) {
I915_WRITE(RING_SYNC_0(ring->mmio_base), 0);
I915_WRITE(RING_SYNC_1(ring->mmio_base), 0);
if (HAS_VEBOX(ring->dev))
I915_WRITE(RING_SYNC_2(ring->mmio_base), 0);
}
ring->set_seqno(ring, seqno);
ring->hangcheck.seqno = seqno;
}
static void gen6_bsd_ring_write_tail(struct intel_ring_buffer *ring,
u32 value)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
I915_WRITE(GEN6_BSD_SLEEP_PSMI_CONTROL,
_MASKED_BIT_ENABLE(GEN6_BSD_SLEEP_MSG_DISABLE));
I915_WRITE64(GEN6_BSD_RNCID, 0x0);
if (wait_for((I915_READ(GEN6_BSD_SLEEP_PSMI_CONTROL) &
GEN6_BSD_SLEEP_INDICATOR) == 0,
50))
DRM_ERROR("timed out waiting for the BSD ring to wake up\n");
I915_WRITE_TAIL(ring, value);
POSTING_READ(RING_TAIL(ring->mmio_base));
I915_WRITE(GEN6_BSD_SLEEP_PSMI_CONTROL,
_MASKED_BIT_DISABLE(GEN6_BSD_SLEEP_MSG_DISABLE));
}
static int gen6_bsd_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate, u32 flush)
{
uint32_t cmd;
int ret;
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW;
if (INTEL_INFO(ring->dev)->gen >= 8)
cmd += 1;
if (invalidate & I915_GEM_GPU_DOMAINS)
cmd |= MI_INVALIDATE_TLB | MI_INVALIDATE_BSD |
MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT);
if (INTEL_INFO(ring->dev)->gen >= 8) {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
} else {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
}
intel_ring_advance(ring);
return 0;
}
static int
gen8_ring_dispatch_execbuffer(struct intel_ring_buffer *ring,
u32 offset, u32 len,
unsigned flags)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
bool ppgtt = dev_priv->mm.aliasing_ppgtt != NULL &&
!(flags & I915_DISPATCH_SECURE);
int ret;
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER_START_GEN8 | (ppgtt<<8));
intel_ring_emit(ring, offset);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
hsw_ring_dispatch_execbuffer(struct intel_ring_buffer *ring,
u32 offset, u32 len,
unsigned flags)
{
int ret;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring,
MI_BATCH_BUFFER_START | MI_BATCH_PPGTT_HSW |
(flags & I915_DISPATCH_SECURE ? 0 : MI_BATCH_NON_SECURE_HSW));
intel_ring_emit(ring, offset);
intel_ring_advance(ring);
return 0;
}
static int
gen6_ring_dispatch_execbuffer(struct intel_ring_buffer *ring,
u32 offset, u32 len,
unsigned flags)
{
int ret;
ret = intel_ring_begin(ring, 2);
if (ret)
return ret;
intel_ring_emit(ring,
MI_BATCH_BUFFER_START |
(flags & I915_DISPATCH_SECURE ? 0 : MI_BATCH_NON_SECURE_I965));
intel_ring_emit(ring, offset);
intel_ring_advance(ring);
return 0;
}
static int gen6_ring_flush(struct intel_ring_buffer *ring,
u32 invalidate, u32 flush)
{
struct drm_device *dev = ring->dev;
uint32_t cmd;
int ret;
ret = intel_ring_begin(ring, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW;
if (INTEL_INFO(ring->dev)->gen >= 8)
cmd += 1;
if (invalidate & I915_GEM_DOMAIN_RENDER)
cmd |= MI_INVALIDATE_TLB | MI_FLUSH_DW_STORE_INDEX |
MI_FLUSH_DW_OP_STOREDW;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT);
if (INTEL_INFO(ring->dev)->gen >= 8) {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
} else {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
}
intel_ring_advance(ring);
if (IS_GEN7(dev) && !invalidate && flush)
return gen7_ring_fbc_flush(ring, FBC_REND_CACHE_CLEAN);
return 0;
}
int intel_init_render_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
ring->name = "render ring";
ring->id = RCS;
ring->mmio_base = RENDER_RING_BASE;
if (INTEL_INFO(dev)->gen >= 6) {
ring->add_request = gen6_add_request;
ring->flush = gen7_render_ring_flush;
if (INTEL_INFO(dev)->gen == 6)
ring->flush = gen6_render_ring_flush;
if (INTEL_INFO(dev)->gen >= 8) {
ring->flush = gen8_render_ring_flush;
ring->irq_get = gen8_ring_get_irq;
ring->irq_put = gen8_ring_put_irq;
} else {
ring->irq_get = gen6_ring_get_irq;
ring->irq_put = gen6_ring_put_irq;
}
ring->irq_enable_mask = GT_RENDER_USER_INTERRUPT;
ring->get_seqno = gen6_ring_get_seqno;
ring->set_seqno = ring_set_seqno;
ring->sync_to = gen6_ring_sync;
ring->semaphore_register[RCS] = MI_SEMAPHORE_SYNC_INVALID;
ring->semaphore_register[VCS] = MI_SEMAPHORE_SYNC_RV;
ring->semaphore_register[BCS] = MI_SEMAPHORE_SYNC_RB;
ring->semaphore_register[VECS] = MI_SEMAPHORE_SYNC_RVE;
ring->signal_mbox[RCS] = GEN6_NOSYNC;
ring->signal_mbox[VCS] = GEN6_VRSYNC;
ring->signal_mbox[BCS] = GEN6_BRSYNC;
ring->signal_mbox[VECS] = GEN6_VERSYNC;
} else if (IS_GEN5(dev)) {
ring->add_request = pc_render_add_request;
ring->flush = gen4_render_ring_flush;
ring->get_seqno = pc_render_get_seqno;
ring->set_seqno = pc_render_set_seqno;
ring->irq_get = gen5_ring_get_irq;
ring->irq_put = gen5_ring_put_irq;
ring->irq_enable_mask = GT_RENDER_USER_INTERRUPT |
GT_RENDER_PIPECTL_NOTIFY_INTERRUPT;
} else {
ring->add_request = i9xx_add_request;
if (INTEL_INFO(dev)->gen < 4)
ring->flush = gen2_render_ring_flush;
else
ring->flush = gen4_render_ring_flush;
ring->get_seqno = ring_get_seqno;
ring->set_seqno = ring_set_seqno;
if (IS_GEN2(dev)) {
ring->irq_get = i8xx_ring_get_irq;
ring->irq_put = i8xx_ring_put_irq;
} else {
ring->irq_get = i9xx_ring_get_irq;
ring->irq_put = i9xx_ring_put_irq;
}
ring->irq_enable_mask = I915_USER_INTERRUPT;
}
ring->write_tail = ring_write_tail;
if (IS_HASWELL(dev))
ring->dispatch_execbuffer = hsw_ring_dispatch_execbuffer;
else if (IS_GEN8(dev))
ring->dispatch_execbuffer = gen8_ring_dispatch_execbuffer;
else if (INTEL_INFO(dev)->gen >= 6)
ring->dispatch_execbuffer = gen6_ring_dispatch_execbuffer;
else if (INTEL_INFO(dev)->gen >= 4)
ring->dispatch_execbuffer = i965_dispatch_execbuffer;
else if (IS_I830(dev) || IS_845G(dev))
ring->dispatch_execbuffer = i830_dispatch_execbuffer;
else
ring->dispatch_execbuffer = i915_dispatch_execbuffer;
ring->init = init_render_ring;
ring->cleanup = render_ring_cleanup;
if (HAS_BROKEN_CS_TLB(dev)) {
struct drm_i915_gem_object *obj;
int ret;
obj = i915_gem_alloc_object(dev, I830_BATCH_LIMIT);
if (obj == NULL) {
DRM_ERROR("Failed to allocate batch bo\n");
return -ENOMEM;
}
ret = i915_gem_obj_ggtt_pin(obj, 0, 0);
if (ret != 0) {
drm_gem_object_unreference(&obj->base);
DRM_ERROR("Failed to ping batch bo\n");
return ret;
}
ring->scratch.obj = obj;
ring->scratch.gtt_offset = i915_gem_obj_ggtt_offset(obj);
}
return intel_init_ring_buffer(dev, ring);
}
int intel_render_ring_init_dri(struct drm_device *dev, u64 start, u32 size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
int ret;
ring->name = "render ring";
ring->id = RCS;
ring->mmio_base = RENDER_RING_BASE;
if (INTEL_INFO(dev)->gen >= 6) {
return -ENODEV;
}
ring->add_request = i9xx_add_request;
if (INTEL_INFO(dev)->gen < 4)
ring->flush = gen2_render_ring_flush;
else
ring->flush = gen4_render_ring_flush;
ring->get_seqno = ring_get_seqno;
ring->set_seqno = ring_set_seqno;
if (IS_GEN2(dev)) {
ring->irq_get = i8xx_ring_get_irq;
ring->irq_put = i8xx_ring_put_irq;
} else {
ring->irq_get = i9xx_ring_get_irq;
ring->irq_put = i9xx_ring_put_irq;
}
ring->irq_enable_mask = I915_USER_INTERRUPT;
ring->write_tail = ring_write_tail;
if (INTEL_INFO(dev)->gen >= 4)
ring->dispatch_execbuffer = i965_dispatch_execbuffer;
else if (IS_I830(dev) || IS_845G(dev))
ring->dispatch_execbuffer = i830_dispatch_execbuffer;
else
ring->dispatch_execbuffer = i915_dispatch_execbuffer;
ring->init = init_render_ring;
ring->cleanup = render_ring_cleanup;
ring->dev = dev;
INIT_LIST_HEAD(&ring->active_list);
INIT_LIST_HEAD(&ring->request_list);
ring->size = size;
ring->effective_size = ring->size;
if (IS_I830(ring->dev) || IS_845G(ring->dev))
ring->effective_size -= 128;
ring->virtual_start = ioremap_wc(start, size);
if (ring->virtual_start == NULL) {
DRM_ERROR("can not ioremap virtual address for"
" ring buffer\n");
return -ENOMEM;
}
if (!I915_NEED_GFX_HWS(dev)) {
ret = init_phys_status_page(ring);
if (ret)
return ret;
}
return 0;
}
int intel_init_bsd_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = &dev_priv->ring[VCS];
ring->name = "bsd ring";
ring->id = VCS;
ring->write_tail = ring_write_tail;
if (INTEL_INFO(dev)->gen >= 6) {
ring->mmio_base = GEN6_BSD_RING_BASE;
if (IS_GEN6(dev))
ring->write_tail = gen6_bsd_ring_write_tail;
ring->flush = gen6_bsd_ring_flush;
ring->add_request = gen6_add_request;
ring->get_seqno = gen6_ring_get_seqno;
ring->set_seqno = ring_set_seqno;
if (INTEL_INFO(dev)->gen >= 8) {
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VCS1_IRQ_SHIFT;
ring->irq_get = gen8_ring_get_irq;
ring->irq_put = gen8_ring_put_irq;
ring->dispatch_execbuffer =
gen8_ring_dispatch_execbuffer;
} else {
ring->irq_enable_mask = GT_BSD_USER_INTERRUPT;
ring->irq_get = gen6_ring_get_irq;
ring->irq_put = gen6_ring_put_irq;
ring->dispatch_execbuffer =
gen6_ring_dispatch_execbuffer;
}
ring->sync_to = gen6_ring_sync;
ring->semaphore_register[RCS] = MI_SEMAPHORE_SYNC_VR;
ring->semaphore_register[VCS] = MI_SEMAPHORE_SYNC_INVALID;
ring->semaphore_register[BCS] = MI_SEMAPHORE_SYNC_VB;
ring->semaphore_register[VECS] = MI_SEMAPHORE_SYNC_VVE;
ring->signal_mbox[RCS] = GEN6_RVSYNC;
ring->signal_mbox[VCS] = GEN6_NOSYNC;
ring->signal_mbox[BCS] = GEN6_BVSYNC;
ring->signal_mbox[VECS] = GEN6_VEVSYNC;
} else {
ring->mmio_base = BSD_RING_BASE;
ring->flush = bsd_ring_flush;
ring->add_request = i9xx_add_request;
ring->get_seqno = ring_get_seqno;
ring->set_seqno = ring_set_seqno;
if (IS_GEN5(dev)) {
ring->irq_enable_mask = ILK_BSD_USER_INTERRUPT;
ring->irq_get = gen5_ring_get_irq;
ring->irq_put = gen5_ring_put_irq;
} else {
ring->irq_enable_mask = I915_BSD_USER_INTERRUPT;
ring->irq_get = i9xx_ring_get_irq;
ring->irq_put = i9xx_ring_put_irq;
}
ring->dispatch_execbuffer = i965_dispatch_execbuffer;
}
ring->init = init_ring_common;
return intel_init_ring_buffer(dev, ring);
}
int intel_init_blt_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = &dev_priv->ring[BCS];
ring->name = "blitter ring";
ring->id = BCS;
ring->mmio_base = BLT_RING_BASE;
ring->write_tail = ring_write_tail;
ring->flush = gen6_ring_flush;
ring->add_request = gen6_add_request;
ring->get_seqno = gen6_ring_get_seqno;
ring->set_seqno = ring_set_seqno;
if (INTEL_INFO(dev)->gen >= 8) {
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_BCS_IRQ_SHIFT;
ring->irq_get = gen8_ring_get_irq;
ring->irq_put = gen8_ring_put_irq;
ring->dispatch_execbuffer = gen8_ring_dispatch_execbuffer;
} else {
ring->irq_enable_mask = GT_BLT_USER_INTERRUPT;
ring->irq_get = gen6_ring_get_irq;
ring->irq_put = gen6_ring_put_irq;
ring->dispatch_execbuffer = gen6_ring_dispatch_execbuffer;
}
ring->sync_to = gen6_ring_sync;
ring->semaphore_register[RCS] = MI_SEMAPHORE_SYNC_BR;
ring->semaphore_register[VCS] = MI_SEMAPHORE_SYNC_BV;
ring->semaphore_register[BCS] = MI_SEMAPHORE_SYNC_INVALID;
ring->semaphore_register[VECS] = MI_SEMAPHORE_SYNC_BVE;
ring->signal_mbox[RCS] = GEN6_RBSYNC;
ring->signal_mbox[VCS] = GEN6_VBSYNC;
ring->signal_mbox[BCS] = GEN6_NOSYNC;
ring->signal_mbox[VECS] = GEN6_VEBSYNC;
ring->init = init_ring_common;
return intel_init_ring_buffer(dev, ring);
}
int intel_init_vebox_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = &dev_priv->ring[VECS];
ring->name = "video enhancement ring";
ring->id = VECS;
ring->mmio_base = VEBOX_RING_BASE;
ring->write_tail = ring_write_tail;
ring->flush = gen6_ring_flush;
ring->add_request = gen6_add_request;
ring->get_seqno = gen6_ring_get_seqno;
ring->set_seqno = ring_set_seqno;
if (INTEL_INFO(dev)->gen >= 8) {
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VECS_IRQ_SHIFT;
ring->irq_get = gen8_ring_get_irq;
ring->irq_put = gen8_ring_put_irq;
ring->dispatch_execbuffer = gen8_ring_dispatch_execbuffer;
} else {
ring->irq_enable_mask = PM_VEBOX_USER_INTERRUPT;
ring->irq_get = hsw_vebox_get_irq;
ring->irq_put = hsw_vebox_put_irq;
ring->dispatch_execbuffer = gen6_ring_dispatch_execbuffer;
}
ring->sync_to = gen6_ring_sync;
ring->semaphore_register[RCS] = MI_SEMAPHORE_SYNC_VER;
ring->semaphore_register[VCS] = MI_SEMAPHORE_SYNC_VEV;
ring->semaphore_register[BCS] = MI_SEMAPHORE_SYNC_VEB;
ring->semaphore_register[VECS] = MI_SEMAPHORE_SYNC_INVALID;
ring->signal_mbox[RCS] = GEN6_RVESYNC;
ring->signal_mbox[VCS] = GEN6_VVESYNC;
ring->signal_mbox[BCS] = GEN6_BVESYNC;
ring->signal_mbox[VECS] = GEN6_NOSYNC;
ring->init = init_ring_common;
return intel_init_ring_buffer(dev, ring);
}
int
intel_ring_flush_all_caches(struct intel_ring_buffer *ring)
{
int ret;
if (!ring->gpu_caches_dirty)
return 0;
ret = ring->flush(ring, 0, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
trace_i915_gem_ring_flush(ring, 0, I915_GEM_GPU_DOMAINS);
ring->gpu_caches_dirty = false;
return 0;
}
int
intel_ring_invalidate_all_caches(struct intel_ring_buffer *ring)
{
uint32_t flush_domains;
int ret;
flush_domains = 0;
if (ring->gpu_caches_dirty)
flush_domains = I915_GEM_GPU_DOMAINS;
ret = ring->flush(ring, I915_GEM_GPU_DOMAINS, flush_domains);
if (ret)
return ret;
trace_i915_gem_ring_flush(ring, I915_GEM_GPU_DOMAINS, flush_domains);
ring->gpu_caches_dirty = false;
return 0;
}
