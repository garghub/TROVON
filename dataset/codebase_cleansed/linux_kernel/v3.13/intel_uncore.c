static void __gen6_gt_wait_for_thread_c0(struct drm_i915_private *dev_priv)
{
u32 gt_thread_status_mask;
if (IS_HASWELL(dev_priv->dev))
gt_thread_status_mask = GEN6_GT_THREAD_STATUS_CORE_MASK_HSW;
else
gt_thread_status_mask = GEN6_GT_THREAD_STATUS_CORE_MASK;
if (wait_for_atomic_us((__raw_i915_read32(dev_priv, GEN6_GT_THREAD_STATUS_REG) & gt_thread_status_mask) == 0, 500))
DRM_ERROR("GT thread status wait timed out\n");
}
static void __gen6_gt_force_wake_reset(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE, 0);
__raw_posting_read(dev_priv, ECOBUS);
}
static void __gen6_gt_force_wake_get(struct drm_i915_private *dev_priv)
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
static void __gen6_gt_force_wake_mt_reset(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE_MT, _MASKED_BIT_DISABLE(0xffff));
__raw_posting_read(dev_priv, ECOBUS);
}
static void __gen6_gt_force_wake_mt_get(struct drm_i915_private *dev_priv)
{
u32 forcewake_ack;
if (IS_HASWELL(dev_priv->dev) || IS_GEN8(dev_priv->dev))
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
if (INTEL_INFO(dev_priv->dev)->gen < 8)
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void gen6_gt_check_fifodbg(struct drm_i915_private *dev_priv)
{
u32 gtfifodbg;
gtfifodbg = __raw_i915_read32(dev_priv, GTFIFODBG);
if (WARN(gtfifodbg & GT_FIFO_CPU_ERROR_MASK,
"MMIO read or write has been dropped %x\n", gtfifodbg))
__raw_i915_write32(dev_priv, GTFIFODBG, GT_FIFO_CPU_ERROR_MASK);
}
static void __gen6_gt_force_wake_put(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE, 0);
__raw_posting_read(dev_priv, ECOBUS);
gen6_gt_check_fifodbg(dev_priv);
}
static void __gen6_gt_force_wake_mt_put(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE_MT,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
__raw_posting_read(dev_priv, ECOBUS);
gen6_gt_check_fifodbg(dev_priv);
}
static int __gen6_gt_wait_for_fifo(struct drm_i915_private *dev_priv)
{
int ret = 0;
if (dev_priv->uncore.fifo_count < GT_FIFO_NUM_RESERVED_ENTRIES) {
int loop = 500;
u32 fifo = __raw_i915_read32(dev_priv, GT_FIFO_FREE_ENTRIES);
while (fifo <= GT_FIFO_NUM_RESERVED_ENTRIES && loop--) {
udelay(10);
fifo = __raw_i915_read32(dev_priv, GT_FIFO_FREE_ENTRIES);
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
__raw_posting_read(dev_priv, FORCEWAKE_ACK_VLV);
}
static void vlv_force_wake_get(struct drm_i915_private *dev_priv)
{
if (wait_for_atomic((__raw_i915_read32(dev_priv, FORCEWAKE_ACK_VLV) & FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake old ack to clear.\n");
__raw_i915_write32(dev_priv, FORCEWAKE_VLV,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((__raw_i915_read32(dev_priv, FORCEWAKE_ACK_VLV) & FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for GT to ack forcewake request.\n");
if (wait_for_atomic((__raw_i915_read32(dev_priv, FORCEWAKE_ACK_MEDIA_VLV) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for media to ack forcewake request.\n");
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void vlv_force_wake_put(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, FORCEWAKE_VLV,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
__raw_i915_write32(dev_priv, FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
gen6_gt_check_fifodbg(dev_priv);
}
static void gen6_force_wake_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), uncore.force_wake_work.work);
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (--dev_priv->uncore.forcewake_count == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void intel_uncore_forcewake_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_VALLEYVIEW(dev)) {
vlv_force_wake_reset(dev_priv);
} else if (INTEL_INFO(dev)->gen >= 6) {
__gen6_gt_force_wake_reset(dev_priv);
if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev))
__gen6_gt_force_wake_mt_reset(dev_priv);
}
}
void intel_uncore_early_sanitize(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_FPGA_DBG_UNCLAIMED(dev))
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
if (IS_HASWELL(dev) &&
(__raw_i915_read32(dev_priv, HSW_EDRAM_PRESENT) == 1)) {
dev_priv->ellc_size = 128;
DRM_INFO("Found %zuMB of eLLC\n", dev_priv->ellc_size);
}
intel_uncore_forcewake_reset(dev);
}
void intel_uncore_sanitize(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg_val;
intel_uncore_forcewake_reset(dev);
intel_disable_gt_powersave(dev);
if (IS_VALLEYVIEW(dev)) {
mutex_lock(&dev_priv->rps.hw_lock);
reg_val = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS);
if (reg_val & (RENDER_PWRGT | MEDIA_PWRGT | DISP2D_PWRGT))
vlv_punit_write(dev_priv, PUNIT_REG_PWRGT_CTRL, 0x0);
mutex_unlock(&dev_priv->rps.hw_lock);
}
}
void gen6_gt_force_wake_get(struct drm_i915_private *dev_priv)
{
unsigned long irqflags;
if (!dev_priv->uncore.funcs.force_wake_get)
return;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (dev_priv->uncore.forcewake_count++ == 0)
dev_priv->uncore.funcs.force_wake_get(dev_priv);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void gen6_gt_force_wake_put(struct drm_i915_private *dev_priv)
{
unsigned long irqflags;
if (!dev_priv->uncore.funcs.force_wake_put)
return;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (--dev_priv->uncore.forcewake_count == 0) {
dev_priv->uncore.forcewake_count++;
mod_delayed_work(dev_priv->wq,
&dev_priv->uncore.force_wake_work,
1);
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void
ilk_dummy_write(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, MI_MODE, 0);
}
static void
hsw_unclaimed_reg_clear(struct drm_i915_private *dev_priv, u32 reg)
{
if (__raw_i915_read32(dev_priv, FPGA_DBG) & FPGA_DBG_RM_NOCLAIM) {
DRM_ERROR("Unknown unclaimed register before writing to %x\n",
reg);
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
}
}
static void
hsw_unclaimed_reg_check(struct drm_i915_private *dev_priv, u32 reg)
{
if (__raw_i915_read32(dev_priv, FPGA_DBG) & FPGA_DBG_RM_NOCLAIM) {
DRM_ERROR("Unclaimed write to %x\n", reg);
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
void intel_uncore_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
INIT_DELAYED_WORK(&dev_priv->uncore.force_wake_work,
gen6_force_wake_work);
if (IS_VALLEYVIEW(dev)) {
dev_priv->uncore.funcs.force_wake_get = vlv_force_wake_get;
dev_priv->uncore.funcs.force_wake_put = vlv_force_wake_put;
} else if (IS_HASWELL(dev) || IS_GEN8(dev)) {
dev_priv->uncore.funcs.force_wake_get = __gen6_gt_force_wake_mt_get;
dev_priv->uncore.funcs.force_wake_put = __gen6_gt_force_wake_mt_put;
} else if (IS_IVYBRIDGE(dev)) {
u32 ecobus;
mutex_lock(&dev->struct_mutex);
__gen6_gt_force_wake_mt_get(dev_priv);
ecobus = __raw_i915_read32(dev_priv, ECOBUS);
__gen6_gt_force_wake_mt_put(dev_priv);
mutex_unlock(&dev->struct_mutex);
if (ecobus & FORCEWAKE_MT_ENABLE) {
dev_priv->uncore.funcs.force_wake_get =
__gen6_gt_force_wake_mt_get;
dev_priv->uncore.funcs.force_wake_put =
__gen6_gt_force_wake_mt_put;
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
dev_priv->uncore.funcs.mmio_writeb = gen8_write8;
dev_priv->uncore.funcs.mmio_writew = gen8_write16;
dev_priv->uncore.funcs.mmio_writel = gen8_write32;
dev_priv->uncore.funcs.mmio_writeq = gen8_write64;
dev_priv->uncore.funcs.mmio_readb = gen6_read8;
dev_priv->uncore.funcs.mmio_readw = gen6_read16;
dev_priv->uncore.funcs.mmio_readl = gen6_read32;
dev_priv->uncore.funcs.mmio_readq = gen6_read64;
break;
case 7:
case 6:
if (IS_HASWELL(dev)) {
dev_priv->uncore.funcs.mmio_writeb = hsw_write8;
dev_priv->uncore.funcs.mmio_writew = hsw_write16;
dev_priv->uncore.funcs.mmio_writel = hsw_write32;
dev_priv->uncore.funcs.mmio_writeq = hsw_write64;
} else {
dev_priv->uncore.funcs.mmio_writeb = gen6_write8;
dev_priv->uncore.funcs.mmio_writew = gen6_write16;
dev_priv->uncore.funcs.mmio_writel = gen6_write32;
dev_priv->uncore.funcs.mmio_writeq = gen6_write64;
}
dev_priv->uncore.funcs.mmio_readb = gen6_read8;
dev_priv->uncore.funcs.mmio_readw = gen6_read16;
dev_priv->uncore.funcs.mmio_readl = gen6_read32;
dev_priv->uncore.funcs.mmio_readq = gen6_read64;
break;
case 5:
dev_priv->uncore.funcs.mmio_writeb = gen5_write8;
dev_priv->uncore.funcs.mmio_writew = gen5_write16;
dev_priv->uncore.funcs.mmio_writel = gen5_write32;
dev_priv->uncore.funcs.mmio_writeq = gen5_write64;
dev_priv->uncore.funcs.mmio_readb = gen5_read8;
dev_priv->uncore.funcs.mmio_readw = gen5_read16;
dev_priv->uncore.funcs.mmio_readl = gen5_read32;
dev_priv->uncore.funcs.mmio_readq = gen5_read64;
break;
case 4:
case 3:
case 2:
dev_priv->uncore.funcs.mmio_writeb = gen4_write8;
dev_priv->uncore.funcs.mmio_writew = gen4_write16;
dev_priv->uncore.funcs.mmio_writel = gen4_write32;
dev_priv->uncore.funcs.mmio_writeq = gen4_write64;
dev_priv->uncore.funcs.mmio_readb = gen4_read8;
dev_priv->uncore.funcs.mmio_readw = gen4_read16;
dev_priv->uncore.funcs.mmio_readl = gen4_read32;
dev_priv->uncore.funcs.mmio_readq = gen4_read64;
break;
}
}
void intel_uncore_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
flush_delayed_work(&dev_priv->uncore.force_wake_work);
intel_uncore_sanitize(dev);
}
int i915_reg_read_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_reg_read *reg = data;
struct register_whitelist const *entry = whitelist;
int i;
for (i = 0; i < ARRAY_SIZE(whitelist); i++, entry++) {
if (entry->offset == reg->offset &&
(1 << INTEL_INFO(dev)->gen & entry->gen_bitmask))
break;
}
if (i == ARRAY_SIZE(whitelist))
return -EINVAL;
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
return -EINVAL;
}
return 0;
}
static int i965_reset_complete(struct drm_device *dev)
{
u8 gdrst;
pci_read_config_byte(dev->pdev, I965_GDRST, &gdrst);
return (gdrst & GRDOM_RESET_ENABLE) == 0;
}
static int i965_do_reset(struct drm_device *dev)
{
int ret;
pci_write_config_byte(dev->pdev, I965_GDRST,
GRDOM_RENDER | GRDOM_RESET_ENABLE);
ret = wait_for(i965_reset_complete(dev), 500);
if (ret)
return ret;
pci_write_config_byte(dev->pdev, I965_GDRST,
GRDOM_MEDIA | GRDOM_RESET_ENABLE);
ret = wait_for(i965_reset_complete(dev), 500);
if (ret)
return ret;
pci_write_config_byte(dev->pdev, I965_GDRST, 0);
return 0;
}
static int ironlake_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 gdrst;
int ret;
gdrst = I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR);
gdrst &= ~GRDOM_MASK;
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR,
gdrst | GRDOM_RENDER | GRDOM_RESET_ENABLE);
ret = wait_for(I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) & 0x1, 500);
if (ret)
return ret;
gdrst = I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR);
gdrst &= ~GRDOM_MASK;
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR,
gdrst | GRDOM_MEDIA | GRDOM_RESET_ENABLE);
return wait_for(I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) & 0x1, 500);
}
static int gen6_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
__raw_i915_write32(dev_priv, GEN6_GDRST, GEN6_GRDOM_FULL);
ret = wait_for((__raw_i915_read32(dev_priv, GEN6_GDRST) & GEN6_GRDOM_FULL) == 0, 500);
intel_uncore_forcewake_reset(dev);
if (dev_priv->uncore.forcewake_count)
dev_priv->uncore.funcs.force_wake_get(dev_priv);
else
dev_priv->uncore.funcs.force_wake_put(dev_priv);
dev_priv->uncore.fifo_count = __raw_i915_read32(dev_priv, GT_FIFO_FREE_ENTRIES);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
return ret;
}
int intel_gpu_reset(struct drm_device *dev)
{
switch (INTEL_INFO(dev)->gen) {
case 8:
case 7:
case 6: return gen6_do_reset(dev);
case 5: return ironlake_do_reset(dev);
case 4: return i965_do_reset(dev);
default: return -ENODEV;
}
}
void intel_uncore_clear_errors(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_FPGA_DBG_UNCLAIMED(dev))
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
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
