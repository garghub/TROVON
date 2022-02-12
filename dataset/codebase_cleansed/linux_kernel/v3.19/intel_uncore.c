static void
assert_device_not_suspended(struct drm_i915_private *dev_priv)
{
WARN_ONCE(HAS_RUNTIME_PM(dev_priv->dev) && dev_priv->pm.suspended,
"Device suspended\n");
}
static void __gen6_gt_wait_for_thread_c0(struct drm_i915_private *dev_priv)
{
if (wait_for_atomic_us((__raw_i915_read32(dev_priv, GEN6_GT_THREAD_STATUS_REG) &
GEN6_GT_THREAD_STATUS_CORE_MASK) == 0, 500))
DRM_ERROR("GT thread status wait timed out\n");
}
static void __gen6_gt_force_wake_reset(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE, 0);
__raw_posting_read(dev_priv, ECOBUS);
}
static void __gen6_gt_force_wake_get(struct drm_i915_private *dev_priv,
int fw_engine)
{
if (wait_for_atomic((__raw_i915_read32(dev_priv, FORCEWAKE_ACK) & 1) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE, 1);
__raw_posting_read(dev_priv, ECOBUS);
if (wait_for_atomic((__raw_i915_read32(dev_priv, FORCEWAKE_ACK) & 1),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake to ack request.\n");
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void __gen7_gt_force_wake_mt_reset(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE_MT, _MASKED_BIT_DISABLE(0xffff));
__raw_posting_read(dev_priv, ECOBUS);
}
static void __gen7_gt_force_wake_mt_get(struct drm_i915_private *dev_priv,
int fw_engine)
{
u32 forcewake_ack;
if (IS_HASWELL(dev_priv->dev) || IS_BROADWELL(dev_priv->dev))
forcewake_ack = FORCEWAKE_ACK_HSW;
else
forcewake_ack = FORCEWAKE_MT_ACK;
if (wait_for_atomic((__raw_i915_read32(dev_priv, forcewake_ack) & FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_MT,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
__raw_posting_read(dev_priv, ECOBUS);
if (wait_for_atomic((__raw_i915_read32(dev_priv, forcewake_ack) & FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake to ack request.\n");
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void gen6_gt_check_fifodbg(struct drm_i915_private *dev_priv)
{
u32 gtfifodbg;
gtfifodbg = __raw_i915_read32(dev_priv, GTFIFODBG);
if (WARN(gtfifodbg, "GT wake FIFO error 0x%x\n", gtfifodbg))
__raw_i915_write32(dev_priv, GTFIFODBG, gtfifodbg);
}
static void __gen6_gt_force_wake_put(struct drm_i915_private *dev_priv,
int fw_engine)
{
__raw_i915_write32(dev_priv, FORCEWAKE, 0);
__raw_posting_read(dev_priv, ECOBUS);
gen6_gt_check_fifodbg(dev_priv);
}
static void __gen7_gt_force_wake_mt_put(struct drm_i915_private *dev_priv,
int fw_engine)
{
__raw_i915_write32(dev_priv, FORCEWAKE_MT,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
__raw_posting_read(dev_priv, ECOBUS);
if (IS_GEN7(dev_priv->dev))
gen6_gt_check_fifodbg(dev_priv);
}
static int __gen6_gt_wait_for_fifo(struct drm_i915_private *dev_priv)
{
int ret = 0;
if (IS_VALLEYVIEW(dev_priv->dev))
dev_priv->uncore.fifo_count =
__raw_i915_read32(dev_priv, GTFIFOCTL) &
GT_FIFO_FREE_ENTRIES_MASK;
if (dev_priv->uncore.fifo_count < GT_FIFO_NUM_RESERVED_ENTRIES) {
int loop = 500;
u32 fifo = __raw_i915_read32(dev_priv, GTFIFOCTL) & GT_FIFO_FREE_ENTRIES_MASK;
while (fifo <= GT_FIFO_NUM_RESERVED_ENTRIES && loop--) {
udelay(10);
fifo = __raw_i915_read32(dev_priv, GTFIFOCTL) & GT_FIFO_FREE_ENTRIES_MASK;
}
if (WARN_ON(loop < 0 && fifo <= GT_FIFO_NUM_RESERVED_ENTRIES))
++ret;
dev_priv->uncore.fifo_count = fifo;
}
dev_priv->uncore.fifo_count--;
return ret;
}
static void vlv_force_wake_reset(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE_VLV,
_MASKED_BIT_DISABLE(0xffff));
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_DISABLE(0xffff));
__raw_posting_read(dev_priv, FORCEWAKE_ACK_VLV);
}
static void __vlv_force_wake_get(struct drm_i915_private *dev_priv,
int fw_engine)
{
if (FORCEWAKE_RENDER & fw_engine) {
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_VLV) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: Render forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_VLV,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_VLV) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: waiting for Render to ack.\n");
}
if (FORCEWAKE_MEDIA & fw_engine) {
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_MEDIA_VLV) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: Media forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_MEDIA_VLV) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: waiting for media to ack.\n");
}
}
static void __vlv_force_wake_put(struct drm_i915_private *dev_priv,
int fw_engine)
{
if (FORCEWAKE_RENDER & fw_engine)
__raw_i915_write32(dev_priv, FORCEWAKE_VLV,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
if (FORCEWAKE_MEDIA & fw_engine)
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
__raw_posting_read(dev_priv, FORCEWAKE_ACK_VLV);
if (!IS_CHERRYVIEW(dev_priv->dev))
gen6_gt_check_fifodbg(dev_priv);
}
static void vlv_force_wake_get(struct drm_i915_private *dev_priv, int fw_engine)
{
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (fw_engine & FORCEWAKE_RENDER &&
dev_priv->uncore.fw_rendercount++ != 0)
fw_engine &= ~FORCEWAKE_RENDER;
if (fw_engine & FORCEWAKE_MEDIA &&
dev_priv->uncore.fw_mediacount++ != 0)
fw_engine &= ~FORCEWAKE_MEDIA;
if (fw_engine)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw_engine);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void vlv_force_wake_put(struct drm_i915_private *dev_priv, int fw_engine)
{
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (fw_engine & FORCEWAKE_RENDER) {
WARN_ON(!dev_priv->uncore.fw_rendercount);
if (--dev_priv->uncore.fw_rendercount != 0)
fw_engine &= ~FORCEWAKE_RENDER;
}
if (fw_engine & FORCEWAKE_MEDIA) {
WARN_ON(!dev_priv->uncore.fw_mediacount);
if (--dev_priv->uncore.fw_mediacount != 0)
fw_engine &= ~FORCEWAKE_MEDIA;
}
if (fw_engine)
dev_priv->uncore.funcs.force_wake_put(dev_priv, fw_engine);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void __gen9_gt_force_wake_mt_reset(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE_RENDER_GEN9,
_MASKED_BIT_DISABLE(0xffff));
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_GEN9,
_MASKED_BIT_DISABLE(0xffff));
__raw_i915_write32(dev_priv, FORCEWAKE_BLITTER_GEN9,
_MASKED_BIT_DISABLE(0xffff));
}
static void
__gen9_force_wake_get(struct drm_i915_private *dev_priv, int fw_engine)
{
if (FORCEWAKE_RENDER & fw_engine) {
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_RENDER_GEN9) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: Render forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_RENDER_GEN9,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_RENDER_GEN9) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: waiting for Render to ack.\n");
}
if (FORCEWAKE_MEDIA & fw_engine) {
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_MEDIA_GEN9) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: Media forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_GEN9,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_MEDIA_GEN9) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: waiting for Media to ack.\n");
}
if (FORCEWAKE_BLITTER & fw_engine) {
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_BLITTER_GEN9) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: Blitter forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_BLITTER_GEN9,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((__raw_i915_read32(dev_priv,
FORCEWAKE_ACK_BLITTER_GEN9) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out: waiting for Blitter to ack.\n");
}
}
static void
__gen9_force_wake_put(struct drm_i915_private *dev_priv, int fw_engine)
{
if (FORCEWAKE_RENDER & fw_engine)
__raw_i915_write32(dev_priv, FORCEWAKE_RENDER_GEN9,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
if (FORCEWAKE_MEDIA & fw_engine)
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_GEN9,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
if (FORCEWAKE_BLITTER & fw_engine)
__raw_i915_write32(dev_priv, FORCEWAKE_BLITTER_GEN9,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
}
static void
gen9_force_wake_get(struct drm_i915_private *dev_priv, int fw_engine)
{
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (FORCEWAKE_RENDER & fw_engine) {
if (dev_priv->uncore.fw_rendercount++ == 0)
dev_priv->uncore.funcs.force_wake_get(dev_priv,
FORCEWAKE_RENDER);
}
if (FORCEWAKE_MEDIA & fw_engine) {
if (dev_priv->uncore.fw_mediacount++ == 0)
dev_priv->uncore.funcs.force_wake_get(dev_priv,
FORCEWAKE_MEDIA);
}
if (FORCEWAKE_BLITTER & fw_engine) {
if (dev_priv->uncore.fw_blittercount++ == 0)
dev_priv->uncore.funcs.force_wake_get(dev_priv,
FORCEWAKE_BLITTER);
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void
gen9_force_wake_put(struct drm_i915_private *dev_priv, int fw_engine)
{
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (FORCEWAKE_RENDER & fw_engine) {
WARN_ON(dev_priv->uncore.fw_rendercount == 0);
if (--dev_priv->uncore.fw_rendercount == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv,
FORCEWAKE_RENDER);
}
if (FORCEWAKE_MEDIA & fw_engine) {
WARN_ON(dev_priv->uncore.fw_mediacount == 0);
if (--dev_priv->uncore.fw_mediacount == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv,
FORCEWAKE_MEDIA);
}
if (FORCEWAKE_BLITTER & fw_engine) {
WARN_ON(dev_priv->uncore.fw_blittercount == 0);
if (--dev_priv->uncore.fw_blittercount == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv,
FORCEWAKE_BLITTER);
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void gen6_force_wake_timer(unsigned long arg)
{
struct drm_i915_private *dev_priv = (void *)arg;
unsigned long irqflags;
assert_device_not_suspended(dev_priv);
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
WARN_ON(!dev_priv->uncore.forcewake_count);
if (--dev_priv->uncore.forcewake_count == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv, FORCEWAKE_ALL);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
intel_runtime_pm_put(dev_priv);
}
void intel_uncore_forcewake_reset(struct drm_device *dev, bool restore)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
if (del_timer_sync(&dev_priv->uncore.force_wake_timer))
gen6_force_wake_timer((unsigned long)dev_priv);
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (IS_VALLEYVIEW(dev))
vlv_force_wake_reset(dev_priv);
else if (IS_GEN6(dev) || IS_GEN7(dev))
__gen6_gt_force_wake_reset(dev_priv);
if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev) || IS_BROADWELL(dev))
__gen7_gt_force_wake_mt_reset(dev_priv);
if (IS_GEN9(dev))
__gen9_gt_force_wake_mt_reset(dev_priv);
if (restore) {
unsigned fw = 0;
if (IS_VALLEYVIEW(dev)) {
if (dev_priv->uncore.fw_rendercount)
fw |= FORCEWAKE_RENDER;
if (dev_priv->uncore.fw_mediacount)
fw |= FORCEWAKE_MEDIA;
} else if (IS_GEN9(dev)) {
if (dev_priv->uncore.fw_rendercount)
fw |= FORCEWAKE_RENDER;
if (dev_priv->uncore.fw_mediacount)
fw |= FORCEWAKE_MEDIA;
if (dev_priv->uncore.fw_blittercount)
fw |= FORCEWAKE_BLITTER;
} else {
if (dev_priv->uncore.forcewake_count)
fw = FORCEWAKE_ALL;
}
if (fw)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw);
if (IS_GEN6(dev) || IS_GEN7(dev))
dev_priv->uncore.fifo_count =
__raw_i915_read32(dev_priv, GTFIFOCTL) &
GT_FIFO_FREE_ENTRIES_MASK;
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void __intel_uncore_early_sanitize(struct drm_device *dev,
bool restore_forcewake)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_FPGA_DBG_UNCLAIMED(dev))
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
if ((IS_HASWELL(dev) || IS_BROADWELL(dev)) &&
(__raw_i915_read32(dev_priv, HSW_EDRAM_PRESENT) == 1)) {
dev_priv->ellc_size = 128;
DRM_INFO("Found %zuMB of eLLC\n", dev_priv->ellc_size);
}
if (IS_GEN6(dev) || IS_GEN7(dev))
__raw_i915_write32(dev_priv, GTFIFODBG,
__raw_i915_read32(dev_priv, GTFIFODBG));
intel_uncore_forcewake_reset(dev, restore_forcewake);
}
void intel_uncore_early_sanitize(struct drm_device *dev, bool restore_forcewake)
{
__intel_uncore_early_sanitize(dev, restore_forcewake);
i915_check_and_clear_faults(dev);
}
void intel_uncore_sanitize(struct drm_device *dev)
{
intel_disable_gt_powersave(dev);
}
void gen6_gt_force_wake_get(struct drm_i915_private *dev_priv, int fw_engine)
{
unsigned long irqflags;
if (!dev_priv->uncore.funcs.force_wake_get)
return;
intel_runtime_pm_get(dev_priv);
if (IS_GEN9(dev_priv->dev))
return gen9_force_wake_get(dev_priv, fw_engine);
if (IS_VALLEYVIEW(dev_priv->dev))
return vlv_force_wake_get(dev_priv, fw_engine);
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (dev_priv->uncore.forcewake_count++ == 0)
dev_priv->uncore.funcs.force_wake_get(dev_priv, FORCEWAKE_ALL);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void gen6_gt_force_wake_put(struct drm_i915_private *dev_priv, int fw_engine)
{
unsigned long irqflags;
bool delayed = false;
if (!dev_priv->uncore.funcs.force_wake_put)
return;
if (IS_GEN9(dev_priv->dev)) {
gen9_force_wake_put(dev_priv, fw_engine);
goto out;
}
if (IS_VALLEYVIEW(dev_priv->dev)) {
vlv_force_wake_put(dev_priv, fw_engine);
goto out;
}
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
WARN_ON(!dev_priv->uncore.forcewake_count);
if (--dev_priv->uncore.forcewake_count == 0) {
dev_priv->uncore.forcewake_count++;
delayed = true;
mod_timer_pinned(&dev_priv->uncore.force_wake_timer,
jiffies + 1);
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
out:
if (!delayed)
intel_runtime_pm_put(dev_priv);
}
void assert_force_wake_inactive(struct drm_i915_private *dev_priv)
{
if (!dev_priv->uncore.funcs.force_wake_get)
return;
WARN_ON(dev_priv->uncore.forcewake_count > 0);
}
static void
ilk_dummy_write(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, MI_MODE, 0);
}
static void
hsw_unclaimed_reg_debug(struct drm_i915_private *dev_priv, u32 reg, bool read,
bool before)
{
const char *op = read ? "reading" : "writing to";
const char *when = before ? "before" : "after";
if (!i915.mmio_debug)
return;
if (__raw_i915_read32(dev_priv, FPGA_DBG) & FPGA_DBG_RM_NOCLAIM) {
WARN(1, "Unclaimed register detected %s %s register 0x%x\n",
when, op, reg);
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
}
}
static void
hsw_unclaimed_reg_detect(struct drm_i915_private *dev_priv)
{
if (i915.mmio_debug)
return;
if (__raw_i915_read32(dev_priv, FPGA_DBG) & FPGA_DBG_RM_NOCLAIM) {
DRM_ERROR("Unclaimed register detected. Please use the i915.mmio_debug=1 to debug this problem.");
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
}
}
static bool is_gen8_shadowed(struct drm_i915_private *dev_priv, u32 reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(gen8_shadowed_regs); i++)
if (reg == gen8_shadowed_regs[i])
return true;
return false;
}
static bool is_gen9_shadowed(struct drm_i915_private *dev_priv, u32 reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(gen9_shadowed_regs); i++)
if (reg == gen9_shadowed_regs[i])
return true;
return false;
}
void intel_uncore_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
setup_timer(&dev_priv->uncore.force_wake_timer,
gen6_force_wake_timer, (unsigned long)dev_priv);
__intel_uncore_early_sanitize(dev, false);
if (IS_GEN9(dev)) {
dev_priv->uncore.funcs.force_wake_get = __gen9_force_wake_get;
dev_priv->uncore.funcs.force_wake_put = __gen9_force_wake_put;
} else if (IS_VALLEYVIEW(dev)) {
dev_priv->uncore.funcs.force_wake_get = __vlv_force_wake_get;
dev_priv->uncore.funcs.force_wake_put = __vlv_force_wake_put;
} else if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
dev_priv->uncore.funcs.force_wake_get = __gen7_gt_force_wake_mt_get;
dev_priv->uncore.funcs.force_wake_put = __gen7_gt_force_wake_mt_put;
} else if (IS_IVYBRIDGE(dev)) {
u32 ecobus;
mutex_lock(&dev->struct_mutex);
__gen7_gt_force_wake_mt_get(dev_priv, FORCEWAKE_ALL);
ecobus = __raw_i915_read32(dev_priv, ECOBUS);
__gen7_gt_force_wake_mt_put(dev_priv, FORCEWAKE_ALL);
mutex_unlock(&dev->struct_mutex);
if (ecobus & FORCEWAKE_MT_ENABLE) {
dev_priv->uncore.funcs.force_wake_get =
__gen7_gt_force_wake_mt_get;
dev_priv->uncore.funcs.force_wake_put =
__gen7_gt_force_wake_mt_put;
} else {
DRM_INFO("No MT forcewake available on Ivybridge, this can result in issues\n");
DRM_INFO("when using vblank-synced partial screen updates.\n");
dev_priv->uncore.funcs.force_wake_get =
__gen6_gt_force_wake_get;
dev_priv->uncore.funcs.force_wake_put =
__gen6_gt_force_wake_put;
}
} else if (IS_GEN6(dev)) {
dev_priv->uncore.funcs.force_wake_get =
__gen6_gt_force_wake_get;
dev_priv->uncore.funcs.force_wake_put =
__gen6_gt_force_wake_put;
}
switch (INTEL_INFO(dev)->gen) {
default:
WARN_ON(1);
return;
case 9:
ASSIGN_WRITE_MMIO_VFUNCS(gen9);
ASSIGN_READ_MMIO_VFUNCS(gen9);
break;
case 8:
if (IS_CHERRYVIEW(dev)) {
ASSIGN_WRITE_MMIO_VFUNCS(chv);
ASSIGN_READ_MMIO_VFUNCS(chv);
} else {
ASSIGN_WRITE_MMIO_VFUNCS(gen8);
ASSIGN_READ_MMIO_VFUNCS(gen6);
}
break;
case 7:
case 6:
if (IS_HASWELL(dev)) {
ASSIGN_WRITE_MMIO_VFUNCS(hsw);
} else {
ASSIGN_WRITE_MMIO_VFUNCS(gen6);
}
if (IS_VALLEYVIEW(dev)) {
ASSIGN_READ_MMIO_VFUNCS(vlv);
} else {
ASSIGN_READ_MMIO_VFUNCS(gen6);
}
break;
case 5:
ASSIGN_WRITE_MMIO_VFUNCS(gen5);
ASSIGN_READ_MMIO_VFUNCS(gen5);
break;
case 4:
case 3:
case 2:
ASSIGN_WRITE_MMIO_VFUNCS(gen4);
ASSIGN_READ_MMIO_VFUNCS(gen4);
break;
}
i915_check_and_clear_faults(dev);
}
void intel_uncore_fini(struct drm_device *dev)
{
intel_uncore_sanitize(dev);
intel_uncore_forcewake_reset(dev, false);
}
int i915_reg_read_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_reg_read *reg = data;
struct register_whitelist const *entry = whitelist;
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(whitelist); i++, entry++) {
if (entry->offset == reg->offset &&
(1 << INTEL_INFO(dev)->gen & entry->gen_bitmask))
break;
}
if (i == ARRAY_SIZE(whitelist))
return -EINVAL;
intel_runtime_pm_get(dev_priv);
switch (entry->size) {
case 8:
reg->val = I915_READ64(reg->offset);
break;
case 4:
reg->val = I915_READ(reg->offset);
break;
case 2:
reg->val = I915_READ16(reg->offset);
break;
case 1:
reg->val = I915_READ8(reg->offset);
break;
default:
WARN_ON(1);
ret = -EINVAL;
goto out;
}
out:
intel_runtime_pm_put(dev_priv);
return ret;
}
int i915_get_reset_stats_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_reset_stats *args = data;
struct i915_ctx_hang_stats *hs;
struct intel_context *ctx;
int ret;
if (args->flags || args->pad)
return -EINVAL;
if (args->ctx_id == DEFAULT_CONTEXT_HANDLE && !capable(CAP_SYS_ADMIN))
return -EPERM;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
ctx = i915_gem_context_get(file->driver_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
hs = &ctx->hang_stats;
if (capable(CAP_SYS_ADMIN))
args->reset_count = i915_reset_count(&dev_priv->gpu_error);
else
args->reset_count = 0;
args->batch_active = hs->batch_active;
args->batch_pending = hs->batch_pending;
mutex_unlock(&dev->struct_mutex);
return 0;
}
static int i915_reset_complete(struct drm_device *dev)
{
u8 gdrst;
pci_read_config_byte(dev->pdev, I915_GDRST, &gdrst);
return (gdrst & GRDOM_RESET_STATUS) == 0;
}
static int i915_do_reset(struct drm_device *dev)
{
pci_write_config_byte(dev->pdev, I915_GDRST, GRDOM_RESET_ENABLE);
udelay(20);
pci_write_config_byte(dev->pdev, I915_GDRST, 0);
return wait_for(i915_reset_complete(dev), 500);
}
static int g4x_reset_complete(struct drm_device *dev)
{
u8 gdrst;
pci_read_config_byte(dev->pdev, I915_GDRST, &gdrst);
return (gdrst & GRDOM_RESET_ENABLE) == 0;
}
static int g33_do_reset(struct drm_device *dev)
{
pci_write_config_byte(dev->pdev, I915_GDRST, GRDOM_RESET_ENABLE);
return wait_for(g4x_reset_complete(dev), 500);
}
static int g4x_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
pci_write_config_byte(dev->pdev, I915_GDRST,
GRDOM_RENDER | GRDOM_RESET_ENABLE);
ret = wait_for(g4x_reset_complete(dev), 500);
if (ret)
return ret;
I915_WRITE(VDECCLK_GATE_D, I915_READ(VDECCLK_GATE_D) | VCP_UNIT_CLOCK_GATE_DISABLE);
POSTING_READ(VDECCLK_GATE_D);
pci_write_config_byte(dev->pdev, I915_GDRST,
GRDOM_MEDIA | GRDOM_RESET_ENABLE);
ret = wait_for(g4x_reset_complete(dev), 500);
if (ret)
return ret;
I915_WRITE(VDECCLK_GATE_D, I915_READ(VDECCLK_GATE_D) & ~VCP_UNIT_CLOCK_GATE_DISABLE);
POSTING_READ(VDECCLK_GATE_D);
pci_write_config_byte(dev->pdev, I915_GDRST, 0);
return 0;
}
static int ironlake_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR,
ILK_GRDOM_RENDER | ILK_GRDOM_RESET_ENABLE);
ret = wait_for((I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) &
ILK_GRDOM_RESET_ENABLE) == 0, 500);
if (ret)
return ret;
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR,
ILK_GRDOM_MEDIA | ILK_GRDOM_RESET_ENABLE);
ret = wait_for((I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) &
ILK_GRDOM_RESET_ENABLE) == 0, 500);
if (ret)
return ret;
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR, 0);
return 0;
}
static int gen6_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
__raw_i915_write32(dev_priv, GEN6_GDRST, GEN6_GRDOM_FULL);
ret = wait_for((__raw_i915_read32(dev_priv, GEN6_GDRST) & GEN6_GRDOM_FULL) == 0, 500);
intel_uncore_forcewake_reset(dev, true);
return ret;
}
int intel_gpu_reset(struct drm_device *dev)
{
if (INTEL_INFO(dev)->gen >= 6)
return gen6_do_reset(dev);
else if (IS_GEN5(dev))
return ironlake_do_reset(dev);
else if (IS_G4X(dev))
return g4x_do_reset(dev);
else if (IS_G33(dev))
return g33_do_reset(dev);
else if (INTEL_INFO(dev)->gen >= 3)
return i915_do_reset(dev);
else
return -ENODEV;
}
void intel_uncore_check_errors(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_FPGA_DBG_UNCLAIMED(dev) &&
(__raw_i915_read32(dev_priv, FPGA_DBG) & FPGA_DBG_RM_NOCLAIM)) {
DRM_ERROR("Unclaimed register before interrupt\n");
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
}
}
