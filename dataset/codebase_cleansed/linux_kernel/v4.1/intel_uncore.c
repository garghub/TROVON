const char *
intel_uncore_forcewake_domain_to_str(const enum forcewake_domain_id id)
{
BUILD_BUG_ON((sizeof(forcewake_domain_names)/sizeof(const char *)) !=
FW_DOMAIN_ID_COUNT);
if (id >= 0 && id < FW_DOMAIN_ID_COUNT)
return forcewake_domain_names[id];
WARN_ON(id);
return "unknown";
}
static void
assert_device_not_suspended(struct drm_i915_private *dev_priv)
{
WARN_ONCE(HAS_RUNTIME_PM(dev_priv->dev) && dev_priv->pm.suspended,
"Device suspended\n");
}
static inline void
fw_domain_reset(const struct intel_uncore_forcewake_domain *d)
{
WARN_ON(d->reg_set == 0);
__raw_i915_write32(d->i915, d->reg_set, d->val_reset);
}
static inline void
fw_domain_arm_timer(struct intel_uncore_forcewake_domain *d)
{
mod_timer_pinned(&d->timer, jiffies + 1);
}
static inline void
fw_domain_wait_ack_clear(const struct intel_uncore_forcewake_domain *d)
{
if (wait_for_atomic((__raw_i915_read32(d->i915, d->reg_ack) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("%s: timed out waiting for forcewake ack to clear.\n",
intel_uncore_forcewake_domain_to_str(d->id));
}
static inline void
fw_domain_get(const struct intel_uncore_forcewake_domain *d)
{
__raw_i915_write32(d->i915, d->reg_set, d->val_set);
}
static inline void
fw_domain_wait_ack(const struct intel_uncore_forcewake_domain *d)
{
if (wait_for_atomic((__raw_i915_read32(d->i915, d->reg_ack) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("%s: timed out waiting for forcewake ack request.\n",
intel_uncore_forcewake_domain_to_str(d->id));
}
static inline void
fw_domain_put(const struct intel_uncore_forcewake_domain *d)
{
__raw_i915_write32(d->i915, d->reg_set, d->val_clear);
}
static inline void
fw_domain_posting_read(const struct intel_uncore_forcewake_domain *d)
{
if (d->reg_post)
__raw_posting_read(d->i915, d->reg_post);
}
static void
fw_domains_get(struct drm_i915_private *dev_priv, enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *d;
enum forcewake_domain_id id;
for_each_fw_domain_mask(d, fw_domains, dev_priv, id) {
fw_domain_wait_ack_clear(d);
fw_domain_get(d);
fw_domain_wait_ack(d);
}
}
static void
fw_domains_put(struct drm_i915_private *dev_priv, enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *d;
enum forcewake_domain_id id;
for_each_fw_domain_mask(d, fw_domains, dev_priv, id) {
fw_domain_put(d);
fw_domain_posting_read(d);
}
}
static void
fw_domains_posting_read(struct drm_i915_private *dev_priv)
{
struct intel_uncore_forcewake_domain *d;
enum forcewake_domain_id id;
for_each_fw_domain(d, dev_priv, id) {
fw_domain_posting_read(d);
break;
}
}
static void
fw_domains_reset(struct drm_i915_private *dev_priv, enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *d;
enum forcewake_domain_id id;
if (dev_priv->uncore.fw_domains == 0)
return;
for_each_fw_domain_mask(d, fw_domains, dev_priv, id)
fw_domain_reset(d);
fw_domains_posting_read(dev_priv);
}
static void __gen6_gt_wait_for_thread_c0(struct drm_i915_private *dev_priv)
{
if (wait_for_atomic_us((__raw_i915_read32(dev_priv, GEN6_GT_THREAD_STATUS_REG) &
GEN6_GT_THREAD_STATUS_CORE_MASK) == 0, 500))
DRM_ERROR("GT thread status wait timed out\n");
}
static void fw_domains_get_with_thread_status(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
fw_domains_get(dev_priv, fw_domains);
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void gen6_gt_check_fifodbg(struct drm_i915_private *dev_priv)
{
u32 gtfifodbg;
gtfifodbg = __raw_i915_read32(dev_priv, GTFIFODBG);
if (WARN(gtfifodbg, "GT wake FIFO error 0x%x\n", gtfifodbg))
__raw_i915_write32(dev_priv, GTFIFODBG, gtfifodbg);
}
static void fw_domains_put_with_fifo(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
fw_domains_put(dev_priv, fw_domains);
gen6_gt_check_fifodbg(dev_priv);
}
static inline u32 fifo_free_entries(struct drm_i915_private *dev_priv)
{
u32 count = __raw_i915_read32(dev_priv, GTFIFOCTL);
return count & GT_FIFO_FREE_ENTRIES_MASK;
}
static int __gen6_gt_wait_for_fifo(struct drm_i915_private *dev_priv)
{
int ret = 0;
if (IS_VALLEYVIEW(dev_priv->dev))
dev_priv->uncore.fifo_count = fifo_free_entries(dev_priv);
if (dev_priv->uncore.fifo_count < GT_FIFO_NUM_RESERVED_ENTRIES) {
int loop = 500;
u32 fifo = fifo_free_entries(dev_priv);
while (fifo <= GT_FIFO_NUM_RESERVED_ENTRIES && loop--) {
udelay(10);
fifo = fifo_free_entries(dev_priv);
}
if (WARN_ON(loop < 0 && fifo <= GT_FIFO_NUM_RESERVED_ENTRIES))
++ret;
dev_priv->uncore.fifo_count = fifo;
}
dev_priv->uncore.fifo_count--;
return ret;
}
static void intel_uncore_fw_release_timer(unsigned long arg)
{
struct intel_uncore_forcewake_domain *domain = (void *)arg;
unsigned long irqflags;
assert_device_not_suspended(domain->i915);
spin_lock_irqsave(&domain->i915->uncore.lock, irqflags);
if (WARN_ON(domain->wake_count == 0))
domain->wake_count++;
if (--domain->wake_count == 0)
domain->i915->uncore.funcs.force_wake_put(domain->i915,
1 << domain->id);
spin_unlock_irqrestore(&domain->i915->uncore.lock, irqflags);
}
void intel_uncore_forcewake_reset(struct drm_device *dev, bool restore)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
struct intel_uncore_forcewake_domain *domain;
int retry_count = 100;
enum forcewake_domain_id id;
enum forcewake_domains fw = 0, active_domains;
while (1) {
active_domains = 0;
for_each_fw_domain(domain, dev_priv, id) {
if (del_timer_sync(&domain->timer) == 0)
continue;
intel_uncore_fw_release_timer((unsigned long)domain);
}
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
for_each_fw_domain(domain, dev_priv, id) {
if (timer_pending(&domain->timer))
active_domains |= (1 << id);
}
if (active_domains == 0)
break;
if (--retry_count == 0) {
DRM_ERROR("Timed out waiting for forcewake timers to finish\n");
break;
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
cond_resched();
}
WARN_ON(active_domains);
for_each_fw_domain(domain, dev_priv, id)
if (domain->wake_count)
fw |= 1 << id;
if (fw)
dev_priv->uncore.funcs.force_wake_put(dev_priv, fw);
fw_domains_reset(dev_priv, FORCEWAKE_ALL);
if (restore) {
if (fw)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw);
if (IS_GEN6(dev) || IS_GEN7(dev))
dev_priv->uncore.fifo_count =
fifo_free_entries(dev_priv);
}
if (!restore)
assert_forcewakes_inactive(dev_priv);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static void intel_uncore_ellc_detect(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if ((IS_HASWELL(dev) || IS_BROADWELL(dev) ||
INTEL_INFO(dev)->gen >= 9) &&
(__raw_i915_read32(dev_priv, HSW_EDRAM_PRESENT) & EDRAM_ENABLED)) {
dev_priv->ellc_size = 128;
DRM_INFO("Found %zuMB of eLLC\n", dev_priv->ellc_size);
}
}
static void __intel_uncore_early_sanitize(struct drm_device *dev,
bool restore_forcewake)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_FPGA_DBG_UNCLAIMED(dev))
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
if (IS_GEN6(dev) || IS_GEN7(dev))
__raw_i915_write32(dev_priv, GTFIFODBG,
__raw_i915_read32(dev_priv, GTFIFODBG));
if (IS_CHERRYVIEW(dev)) {
__raw_i915_write32(dev_priv, GTFIFOCTL,
__raw_i915_read32(dev_priv, GTFIFOCTL) |
GT_FIFO_CTL_BLOCK_ALL_POLICY_STALL |
GT_FIFO_CTL_RC6_POLICY_STALL);
}
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
void intel_uncore_forcewake_get(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
unsigned long irqflags;
struct intel_uncore_forcewake_domain *domain;
enum forcewake_domain_id id;
if (!dev_priv->uncore.funcs.force_wake_get)
return;
WARN_ON(dev_priv->pm.suspended);
fw_domains &= dev_priv->uncore.fw_domains;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
for_each_fw_domain_mask(domain, fw_domains, dev_priv, id) {
if (domain->wake_count++)
fw_domains &= ~(1 << id);
}
if (fw_domains)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw_domains);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void intel_uncore_forcewake_put(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
unsigned long irqflags;
struct intel_uncore_forcewake_domain *domain;
enum forcewake_domain_id id;
if (!dev_priv->uncore.funcs.force_wake_put)
return;
fw_domains &= dev_priv->uncore.fw_domains;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
for_each_fw_domain_mask(domain, fw_domains, dev_priv, id) {
if (WARN_ON(domain->wake_count == 0))
continue;
if (--domain->wake_count)
continue;
domain->wake_count++;
fw_domain_arm_timer(domain);
}
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void assert_forcewakes_inactive(struct drm_i915_private *dev_priv)
{
struct intel_uncore_forcewake_domain *domain;
enum forcewake_domain_id id;
if (!dev_priv->uncore.funcs.force_wake_get)
return;
for_each_fw_domain(domain, dev_priv, id)
WARN_ON(domain->wake_count);
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
i915.mmio_debug--;
}
}
static void
hsw_unclaimed_reg_detect(struct drm_i915_private *dev_priv)
{
static bool mmio_debug_once = true;
if (i915.mmio_debug || !mmio_debug_once)
return;
if (__raw_i915_read32(dev_priv, FPGA_DBG) & FPGA_DBG_RM_NOCLAIM) {
DRM_DEBUG("Unclaimed register detected, "
"enabling oneshot unclaimed register reporting. "
"Please use i915.mmio_debug=N for more information.\n");
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
i915.mmio_debug = mmio_debug_once--;
}
}
static inline void __force_wake_get(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *domain;
enum forcewake_domain_id id;
if (WARN_ON(!fw_domains))
return;
for_each_fw_domain_mask(domain, fw_domains, dev_priv, id) {
if (domain->wake_count) {
fw_domains &= ~(1 << id);
continue;
}
domain->wake_count++;
fw_domain_arm_timer(domain);
}
if (fw_domains)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw_domains);
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
static void fw_domain_init(struct drm_i915_private *dev_priv,
enum forcewake_domain_id domain_id,
u32 reg_set, u32 reg_ack)
{
struct intel_uncore_forcewake_domain *d;
if (WARN_ON(domain_id >= FW_DOMAIN_ID_COUNT))
return;
d = &dev_priv->uncore.fw_domain[domain_id];
WARN_ON(d->wake_count);
d->wake_count = 0;
d->reg_set = reg_set;
d->reg_ack = reg_ack;
if (IS_GEN6(dev_priv)) {
d->val_reset = 0;
d->val_set = FORCEWAKE_KERNEL;
d->val_clear = 0;
} else {
d->val_reset = _MASKED_BIT_DISABLE(0xffff);
d->val_set = _MASKED_BIT_ENABLE(FORCEWAKE_KERNEL);
d->val_clear = _MASKED_BIT_DISABLE(FORCEWAKE_KERNEL);
}
if (IS_VALLEYVIEW(dev_priv))
d->reg_post = FORCEWAKE_ACK_VLV;
else if (IS_GEN6(dev_priv) || IS_GEN7(dev_priv) || IS_GEN8(dev_priv))
d->reg_post = ECOBUS;
else
d->reg_post = 0;
d->i915 = dev_priv;
d->id = domain_id;
setup_timer(&d->timer, intel_uncore_fw_release_timer, (unsigned long)d);
dev_priv->uncore.fw_domains |= (1 << domain_id);
fw_domain_reset(d);
}
static void intel_uncore_fw_domains_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (INTEL_INFO(dev_priv->dev)->gen <= 5)
return;
if (IS_GEN9(dev)) {
dev_priv->uncore.funcs.force_wake_get = fw_domains_get;
dev_priv->uncore.funcs.force_wake_put = fw_domains_put;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_RENDER_GEN9,
FORCEWAKE_ACK_RENDER_GEN9);
fw_domain_init(dev_priv, FW_DOMAIN_ID_BLITTER,
FORCEWAKE_BLITTER_GEN9,
FORCEWAKE_ACK_BLITTER_GEN9);
fw_domain_init(dev_priv, FW_DOMAIN_ID_MEDIA,
FORCEWAKE_MEDIA_GEN9, FORCEWAKE_ACK_MEDIA_GEN9);
} else if (IS_VALLEYVIEW(dev)) {
dev_priv->uncore.funcs.force_wake_get = fw_domains_get;
if (!IS_CHERRYVIEW(dev))
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
else
dev_priv->uncore.funcs.force_wake_put = fw_domains_put;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_VLV, FORCEWAKE_ACK_VLV);
fw_domain_init(dev_priv, FW_DOMAIN_ID_MEDIA,
FORCEWAKE_MEDIA_VLV, FORCEWAKE_ACK_MEDIA_VLV);
} else if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
dev_priv->uncore.funcs.force_wake_get =
fw_domains_get_with_thread_status;
dev_priv->uncore.funcs.force_wake_put = fw_domains_put;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_MT, FORCEWAKE_ACK_HSW);
} else if (IS_IVYBRIDGE(dev)) {
u32 ecobus;
dev_priv->uncore.funcs.force_wake_get =
fw_domains_get_with_thread_status;
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
__raw_i915_write32(dev_priv, FORCEWAKE, 0);
__raw_posting_read(dev_priv, ECOBUS);
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_MT, FORCEWAKE_MT_ACK);
mutex_lock(&dev->struct_mutex);
fw_domains_get_with_thread_status(dev_priv, FORCEWAKE_ALL);
ecobus = __raw_i915_read32(dev_priv, ECOBUS);
fw_domains_put_with_fifo(dev_priv, FORCEWAKE_ALL);
mutex_unlock(&dev->struct_mutex);
if (!(ecobus & FORCEWAKE_MT_ENABLE)) {
DRM_INFO("No MT forcewake available on Ivybridge, this can result in issues\n");
DRM_INFO("when using vblank-synced partial screen updates.\n");
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE, FORCEWAKE_ACK);
}
} else if (IS_GEN6(dev)) {
dev_priv->uncore.funcs.force_wake_get =
fw_domains_get_with_thread_status;
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE, FORCEWAKE_ACK);
}
WARN_ON(dev_priv->uncore.fw_domains == 0);
}
void intel_uncore_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
i915_check_vgpu(dev);
intel_uncore_ellc_detect(dev);
intel_uncore_fw_domains_init(dev);
__intel_uncore_early_sanitize(dev, false);
switch (INTEL_INFO(dev)->gen) {
default:
MISSING_CASE(INTEL_INFO(dev)->gen);
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
ASSIGN_WRITE_MMIO_VFUNCS(gen2);
ASSIGN_READ_MMIO_VFUNCS(gen2);
break;
}
if (intel_vgpu_active(dev)) {
ASSIGN_WRITE_MMIO_VFUNCS(vgpu);
ASSIGN_READ_MMIO_VFUNCS(vgpu);
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
MISSING_CASE(entry->size);
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
