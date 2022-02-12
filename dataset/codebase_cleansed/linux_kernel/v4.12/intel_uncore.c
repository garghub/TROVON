const char *
intel_uncore_forcewake_domain_to_str(const enum forcewake_domain_id id)
{
BUILD_BUG_ON(ARRAY_SIZE(forcewake_domain_names) != FW_DOMAIN_ID_COUNT);
if (id >= 0 && id < FW_DOMAIN_ID_COUNT)
return forcewake_domain_names[id];
WARN_ON(id);
return "unknown";
}
static inline void
fw_domain_reset(struct drm_i915_private *i915,
const struct intel_uncore_forcewake_domain *d)
{
__raw_i915_write32(i915, d->reg_set, i915->uncore.fw_reset);
}
static inline void
fw_domain_arm_timer(struct intel_uncore_forcewake_domain *d)
{
d->wake_count++;
hrtimer_start_range_ns(&d->timer,
NSEC_PER_MSEC,
NSEC_PER_MSEC,
HRTIMER_MODE_REL);
}
static inline void
fw_domain_wait_ack_clear(const struct drm_i915_private *i915,
const struct intel_uncore_forcewake_domain *d)
{
if (wait_for_atomic((__raw_i915_read32(i915, d->reg_ack) &
FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("%s: timed out waiting for forcewake ack to clear.\n",
intel_uncore_forcewake_domain_to_str(d->id));
}
static inline void
fw_domain_get(struct drm_i915_private *i915,
const struct intel_uncore_forcewake_domain *d)
{
__raw_i915_write32(i915, d->reg_set, i915->uncore.fw_set);
}
static inline void
fw_domain_wait_ack(const struct drm_i915_private *i915,
const struct intel_uncore_forcewake_domain *d)
{
if (wait_for_atomic((__raw_i915_read32(i915, d->reg_ack) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("%s: timed out waiting for forcewake ack request.\n",
intel_uncore_forcewake_domain_to_str(d->id));
}
static inline void
fw_domain_put(const struct drm_i915_private *i915,
const struct intel_uncore_forcewake_domain *d)
{
__raw_i915_write32(i915, d->reg_set, i915->uncore.fw_clear);
}
static void
fw_domains_get(struct drm_i915_private *i915, enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *d;
unsigned int tmp;
GEM_BUG_ON(fw_domains & ~i915->uncore.fw_domains);
for_each_fw_domain_masked(d, fw_domains, i915, tmp) {
fw_domain_wait_ack_clear(i915, d);
fw_domain_get(i915, d);
}
for_each_fw_domain_masked(d, fw_domains, i915, tmp)
fw_domain_wait_ack(i915, d);
i915->uncore.fw_domains_active |= fw_domains;
}
static void
fw_domains_put(struct drm_i915_private *i915, enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *d;
unsigned int tmp;
GEM_BUG_ON(fw_domains & ~i915->uncore.fw_domains);
for_each_fw_domain_masked(d, fw_domains, i915, tmp)
fw_domain_put(i915, d);
i915->uncore.fw_domains_active &= ~fw_domains;
}
static void
fw_domains_reset(struct drm_i915_private *i915,
enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *d;
unsigned int tmp;
if (!fw_domains)
return;
GEM_BUG_ON(fw_domains & ~i915->uncore.fw_domains);
for_each_fw_domain_masked(d, fw_domains, i915, tmp)
fw_domain_reset(i915, d);
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
if (IS_VALLEYVIEW(dev_priv))
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
static enum hrtimer_restart
intel_uncore_fw_release_timer(struct hrtimer *timer)
{
struct intel_uncore_forcewake_domain *domain =
container_of(timer, struct intel_uncore_forcewake_domain, timer);
struct drm_i915_private *dev_priv =
container_of(domain, struct drm_i915_private, uncore.fw_domain[domain->id]);
unsigned long irqflags;
assert_rpm_device_not_suspended(dev_priv);
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (WARN_ON(domain->wake_count == 0))
domain->wake_count++;
if (--domain->wake_count == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv, domain->mask);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
return HRTIMER_NORESTART;
}
static void intel_uncore_forcewake_reset(struct drm_i915_private *dev_priv,
bool restore)
{
unsigned long irqflags;
struct intel_uncore_forcewake_domain *domain;
int retry_count = 100;
enum forcewake_domains fw, active_domains;
while (1) {
unsigned int tmp;
active_domains = 0;
for_each_fw_domain(domain, dev_priv, tmp) {
if (hrtimer_cancel(&domain->timer) == 0)
continue;
intel_uncore_fw_release_timer(&domain->timer);
}
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
for_each_fw_domain(domain, dev_priv, tmp) {
if (hrtimer_active(&domain->timer))
active_domains |= domain->mask;
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
fw = dev_priv->uncore.fw_domains_active;
if (fw)
dev_priv->uncore.funcs.force_wake_put(dev_priv, fw);
fw_domains_reset(dev_priv, dev_priv->uncore.fw_domains);
if (restore) {
if (fw)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw);
if (IS_GEN6(dev_priv) || IS_GEN7(dev_priv))
dev_priv->uncore.fifo_count =
fifo_free_entries(dev_priv);
}
if (!restore)
assert_forcewakes_inactive(dev_priv);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
static u64 gen9_edram_size(struct drm_i915_private *dev_priv)
{
const unsigned int ways[8] = { 4, 8, 12, 16, 16, 16, 16, 16 };
const unsigned int sets[4] = { 1, 1, 2, 2 };
const u32 cap = dev_priv->edram_cap;
return EDRAM_NUM_BANKS(cap) *
ways[EDRAM_WAYS_IDX(cap)] *
sets[EDRAM_SETS_IDX(cap)] *
1024 * 1024;
}
u64 intel_uncore_edram_size(struct drm_i915_private *dev_priv)
{
if (!HAS_EDRAM(dev_priv))
return 0;
if (INTEL_GEN(dev_priv) < 9)
return 128 * 1024 * 1024;
return gen9_edram_size(dev_priv);
}
static void intel_uncore_edram_detect(struct drm_i915_private *dev_priv)
{
if (IS_HASWELL(dev_priv) ||
IS_BROADWELL(dev_priv) ||
INTEL_GEN(dev_priv) >= 9) {
dev_priv->edram_cap = __raw_i915_read32(dev_priv,
HSW_EDRAM_CAP);
} else {
dev_priv->edram_cap = 0;
}
if (HAS_EDRAM(dev_priv))
DRM_INFO("Found %lluMB of eDRAM\n",
intel_uncore_edram_size(dev_priv) / (1024 * 1024));
}
static bool
fpga_check_for_unclaimed_mmio(struct drm_i915_private *dev_priv)
{
u32 dbg;
dbg = __raw_i915_read32(dev_priv, FPGA_DBG);
if (likely(!(dbg & FPGA_DBG_RM_NOCLAIM)))
return false;
__raw_i915_write32(dev_priv, FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
return true;
}
static bool
vlv_check_for_unclaimed_mmio(struct drm_i915_private *dev_priv)
{
u32 cer;
cer = __raw_i915_read32(dev_priv, CLAIM_ER);
if (likely(!(cer & (CLAIM_ER_OVERFLOW | CLAIM_ER_CTR_MASK))))
return false;
__raw_i915_write32(dev_priv, CLAIM_ER, CLAIM_ER_CLR);
return true;
}
static bool
check_for_unclaimed_mmio(struct drm_i915_private *dev_priv)
{
if (HAS_FPGA_DBG_UNCLAIMED(dev_priv))
return fpga_check_for_unclaimed_mmio(dev_priv);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
return vlv_check_for_unclaimed_mmio(dev_priv);
return false;
}
static void __intel_uncore_early_sanitize(struct drm_i915_private *dev_priv,
bool restore_forcewake)
{
struct intel_device_info *info = mkwrite_device_info(dev_priv);
if (check_for_unclaimed_mmio(dev_priv))
DRM_DEBUG("unclaimed mmio detected on uncore init, clearing\n");
if (IS_GEN6(dev_priv) || IS_GEN7(dev_priv))
__raw_i915_write32(dev_priv, GTFIFODBG,
__raw_i915_read32(dev_priv, GTFIFODBG));
if (IS_CHERRYVIEW(dev_priv)) {
__raw_i915_write32(dev_priv, GTFIFOCTL,
__raw_i915_read32(dev_priv, GTFIFOCTL) |
GT_FIFO_CTL_BLOCK_ALL_POLICY_STALL |
GT_FIFO_CTL_RC6_POLICY_STALL);
}
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_B_LAST))
info->has_decoupled_mmio = false;
intel_uncore_forcewake_reset(dev_priv, restore_forcewake);
}
void intel_uncore_suspend(struct drm_i915_private *dev_priv)
{
iosf_mbi_unregister_pmic_bus_access_notifier(
&dev_priv->uncore.pmic_bus_access_nb);
intel_uncore_forcewake_reset(dev_priv, false);
}
void intel_uncore_resume_early(struct drm_i915_private *dev_priv)
{
__intel_uncore_early_sanitize(dev_priv, true);
iosf_mbi_register_pmic_bus_access_notifier(
&dev_priv->uncore.pmic_bus_access_nb);
i915_check_and_clear_faults(dev_priv);
}
void intel_uncore_sanitize(struct drm_i915_private *dev_priv)
{
i915.enable_rc6 = sanitize_rc6_option(dev_priv, i915.enable_rc6);
intel_sanitize_gt_powersave(dev_priv);
}
static void __intel_uncore_forcewake_get(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *domain;
unsigned int tmp;
fw_domains &= dev_priv->uncore.fw_domains;
for_each_fw_domain_masked(domain, fw_domains, dev_priv, tmp)
if (domain->wake_count++)
fw_domains &= ~domain->mask;
if (fw_domains)
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw_domains);
}
void intel_uncore_forcewake_get(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
unsigned long irqflags;
if (!dev_priv->uncore.funcs.force_wake_get)
return;
assert_rpm_wakelock_held(dev_priv);
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
__intel_uncore_forcewake_get(dev_priv, fw_domains);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void intel_uncore_forcewake_get__locked(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
lockdep_assert_held(&dev_priv->uncore.lock);
if (!dev_priv->uncore.funcs.force_wake_get)
return;
__intel_uncore_forcewake_get(dev_priv, fw_domains);
}
static void __intel_uncore_forcewake_put(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *domain;
unsigned int tmp;
fw_domains &= dev_priv->uncore.fw_domains;
for_each_fw_domain_masked(domain, fw_domains, dev_priv, tmp) {
if (WARN_ON(domain->wake_count == 0))
continue;
if (--domain->wake_count)
continue;
fw_domain_arm_timer(domain);
}
}
void intel_uncore_forcewake_put(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
unsigned long irqflags;
if (!dev_priv->uncore.funcs.force_wake_put)
return;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
__intel_uncore_forcewake_put(dev_priv, fw_domains);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void intel_uncore_forcewake_put__locked(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
lockdep_assert_held(&dev_priv->uncore.lock);
if (!dev_priv->uncore.funcs.force_wake_put)
return;
__intel_uncore_forcewake_put(dev_priv, fw_domains);
}
void assert_forcewakes_inactive(struct drm_i915_private *dev_priv)
{
if (!dev_priv->uncore.funcs.force_wake_get)
return;
WARN_ON(dev_priv->uncore.fw_domains_active);
}
static int fw_range_cmp(u32 offset, const struct intel_forcewake_range *entry)
{
if (offset < entry->start)
return -1;
else if (offset > entry->end)
return 1;
else
return 0;
}
static enum forcewake_domains
find_fw_domain(struct drm_i915_private *dev_priv, u32 offset)
{
const struct intel_forcewake_range *entry;
entry = BSEARCH(offset,
dev_priv->uncore.fw_domains_table,
dev_priv->uncore.fw_domains_table_entries,
fw_range_cmp);
if (!entry)
return 0;
WARN(entry->domains & ~dev_priv->uncore.fw_domains,
"Uninitialized forcewake domain(s) 0x%x accessed at 0x%x\n",
entry->domains & ~dev_priv->uncore.fw_domains, offset);
return entry->domains;
}
static int mmio_reg_cmp(u32 key, const i915_reg_t *reg)
{
u32 offset = i915_mmio_reg_offset(*reg);
if (key < offset)
return -1;
else if (key > offset)
return 1;
else
return 0;
}
static bool is_gen8_shadowed(u32 offset)
{
const i915_reg_t *regs = gen8_shadowed_regs;
return BSEARCH(offset, regs, ARRAY_SIZE(gen8_shadowed_regs),
mmio_reg_cmp);
}
static void
ilk_dummy_write(struct drm_i915_private *dev_priv)
{
__raw_i915_write32(dev_priv, MI_MODE, 0);
}
static void
__unclaimed_reg_debug(struct drm_i915_private *dev_priv,
const i915_reg_t reg,
const bool read,
const bool before)
{
if (WARN(check_for_unclaimed_mmio(dev_priv) && !before,
"Unclaimed %s register 0x%x\n",
read ? "read from" : "write to",
i915_mmio_reg_offset(reg)))
i915.mmio_debug--;
}
static inline void
unclaimed_reg_debug(struct drm_i915_private *dev_priv,
const i915_reg_t reg,
const bool read,
const bool before)
{
if (likely(!i915.mmio_debug))
return;
__unclaimed_reg_debug(dev_priv, reg, read, before);
}
static void __gen9_decoupled_mmio_access(struct drm_i915_private *dev_priv,
u32 reg,
enum forcewake_domains fw_domain,
enum decoupled_ops operation)
{
enum decoupled_power_domain dp_domain;
u32 ctrl_reg_data = 0;
dp_domain = fw2dpd_domain[fw_domain - 1];
ctrl_reg_data |= reg;
ctrl_reg_data |= (operation << GEN9_DECOUPLED_OP_SHIFT);
ctrl_reg_data |= (dp_domain << GEN9_DECOUPLED_PD_SHIFT);
ctrl_reg_data |= GEN9_DECOUPLED_DW1_GO;
__raw_i915_write32(dev_priv, GEN9_DECOUPLED_REG0_DW1, ctrl_reg_data);
if (wait_for_atomic((__raw_i915_read32(dev_priv,
GEN9_DECOUPLED_REG0_DW1) &
GEN9_DECOUPLED_DW1_GO) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Decoupled MMIO wait timed out\n");
}
static inline u32
__gen9_decoupled_mmio_read32(struct drm_i915_private *dev_priv,
u32 reg,
enum forcewake_domains fw_domain)
{
__gen9_decoupled_mmio_access(dev_priv, reg, fw_domain,
GEN9_DECOUPLED_OP_READ);
return __raw_i915_read32(dev_priv, GEN9_DECOUPLED_REG0_DW0);
}
static inline void
__gen9_decoupled_mmio_write(struct drm_i915_private *dev_priv,
u32 reg, u32 data,
enum forcewake_domains fw_domain)
{
__raw_i915_write32(dev_priv, GEN9_DECOUPLED_REG0_DW0, data);
__gen9_decoupled_mmio_access(dev_priv, reg, fw_domain,
GEN9_DECOUPLED_OP_WRITE);
}
static noinline void ___force_wake_auto(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
struct intel_uncore_forcewake_domain *domain;
unsigned int tmp;
GEM_BUG_ON(fw_domains & ~dev_priv->uncore.fw_domains);
for_each_fw_domain_masked(domain, fw_domains, dev_priv, tmp)
fw_domain_arm_timer(domain);
dev_priv->uncore.funcs.force_wake_get(dev_priv, fw_domains);
}
static inline void __force_wake_auto(struct drm_i915_private *dev_priv,
enum forcewake_domains fw_domains)
{
if (WARN_ON(!fw_domains))
return;
fw_domains &= dev_priv->uncore.fw_domains;
fw_domains &= ~dev_priv->uncore.fw_domains_active;
if (fw_domains)
___force_wake_auto(dev_priv, fw_domains);
}
static void fw_domain_init(struct drm_i915_private *dev_priv,
enum forcewake_domain_id domain_id,
i915_reg_t reg_set,
i915_reg_t reg_ack)
{
struct intel_uncore_forcewake_domain *d;
if (WARN_ON(domain_id >= FW_DOMAIN_ID_COUNT))
return;
d = &dev_priv->uncore.fw_domain[domain_id];
WARN_ON(d->wake_count);
WARN_ON(!i915_mmio_reg_valid(reg_set));
WARN_ON(!i915_mmio_reg_valid(reg_ack));
d->wake_count = 0;
d->reg_set = reg_set;
d->reg_ack = reg_ack;
d->id = domain_id;
BUILD_BUG_ON(FORCEWAKE_RENDER != (1 << FW_DOMAIN_ID_RENDER));
BUILD_BUG_ON(FORCEWAKE_BLITTER != (1 << FW_DOMAIN_ID_BLITTER));
BUILD_BUG_ON(FORCEWAKE_MEDIA != (1 << FW_DOMAIN_ID_MEDIA));
d->mask = BIT(domain_id);
hrtimer_init(&d->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
d->timer.function = intel_uncore_fw_release_timer;
dev_priv->uncore.fw_domains |= BIT(domain_id);
fw_domain_reset(dev_priv, d);
}
static void intel_uncore_fw_domains_init(struct drm_i915_private *dev_priv)
{
if (INTEL_GEN(dev_priv) <= 5 || intel_vgpu_active(dev_priv))
return;
if (IS_GEN6(dev_priv)) {
dev_priv->uncore.fw_reset = 0;
dev_priv->uncore.fw_set = FORCEWAKE_KERNEL;
dev_priv->uncore.fw_clear = 0;
} else {
dev_priv->uncore.fw_reset = _MASKED_BIT_DISABLE(0xffff);
dev_priv->uncore.fw_set = _MASKED_BIT_ENABLE(FORCEWAKE_KERNEL);
dev_priv->uncore.fw_clear = _MASKED_BIT_DISABLE(FORCEWAKE_KERNEL);
}
if (IS_GEN9(dev_priv)) {
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
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
dev_priv->uncore.funcs.force_wake_get = fw_domains_get;
if (!IS_CHERRYVIEW(dev_priv))
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
else
dev_priv->uncore.funcs.force_wake_put = fw_domains_put;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_VLV, FORCEWAKE_ACK_VLV);
fw_domain_init(dev_priv, FW_DOMAIN_ID_MEDIA,
FORCEWAKE_MEDIA_VLV, FORCEWAKE_ACK_MEDIA_VLV);
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
dev_priv->uncore.funcs.force_wake_get =
fw_domains_get_with_thread_status;
if (IS_HASWELL(dev_priv))
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
else
dev_priv->uncore.funcs.force_wake_put = fw_domains_put;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_MT, FORCEWAKE_ACK_HSW);
} else if (IS_IVYBRIDGE(dev_priv)) {
u32 ecobus;
dev_priv->uncore.funcs.force_wake_get =
fw_domains_get_with_thread_status;
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
__raw_i915_write32(dev_priv, FORCEWAKE, 0);
__raw_posting_read(dev_priv, ECOBUS);
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE_MT, FORCEWAKE_MT_ACK);
spin_lock_irq(&dev_priv->uncore.lock);
fw_domains_get_with_thread_status(dev_priv, FORCEWAKE_RENDER);
ecobus = __raw_i915_read32(dev_priv, ECOBUS);
fw_domains_put_with_fifo(dev_priv, FORCEWAKE_RENDER);
spin_unlock_irq(&dev_priv->uncore.lock);
if (!(ecobus & FORCEWAKE_MT_ENABLE)) {
DRM_INFO("No MT forcewake available on Ivybridge, this can result in issues\n");
DRM_INFO("when using vblank-synced partial screen updates.\n");
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE, FORCEWAKE_ACK);
}
} else if (IS_GEN6(dev_priv)) {
dev_priv->uncore.funcs.force_wake_get =
fw_domains_get_with_thread_status;
dev_priv->uncore.funcs.force_wake_put =
fw_domains_put_with_fifo;
fw_domain_init(dev_priv, FW_DOMAIN_ID_RENDER,
FORCEWAKE, FORCEWAKE_ACK);
}
WARN_ON(dev_priv->uncore.fw_domains == 0);
}
static int i915_pmic_bus_access_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct drm_i915_private *dev_priv = container_of(nb,
struct drm_i915_private, uncore.pmic_bus_access_nb);
switch (action) {
case MBI_PMIC_BUS_ACCESS_BEGIN:
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
break;
case MBI_PMIC_BUS_ACCESS_END:
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
break;
}
return NOTIFY_OK;
}
void intel_uncore_init(struct drm_i915_private *dev_priv)
{
i915_check_vgpu(dev_priv);
intel_uncore_edram_detect(dev_priv);
intel_uncore_fw_domains_init(dev_priv);
__intel_uncore_early_sanitize(dev_priv, false);
dev_priv->uncore.unclaimed_mmio_check = 1;
dev_priv->uncore.pmic_bus_access_nb.notifier_call =
i915_pmic_bus_access_notifier;
if (IS_GEN(dev_priv, 2, 4) || intel_vgpu_active(dev_priv)) {
ASSIGN_WRITE_MMIO_VFUNCS(gen2);
ASSIGN_READ_MMIO_VFUNCS(gen2);
} else if (IS_GEN5(dev_priv)) {
ASSIGN_WRITE_MMIO_VFUNCS(gen5);
ASSIGN_READ_MMIO_VFUNCS(gen5);
} else if (IS_GEN(dev_priv, 6, 7)) {
ASSIGN_WRITE_MMIO_VFUNCS(gen6);
if (IS_VALLEYVIEW(dev_priv)) {
ASSIGN_FW_DOMAINS_TABLE(__vlv_fw_ranges);
ASSIGN_READ_MMIO_VFUNCS(fwtable);
} else {
ASSIGN_READ_MMIO_VFUNCS(gen6);
}
} else if (IS_GEN8(dev_priv)) {
if (IS_CHERRYVIEW(dev_priv)) {
ASSIGN_FW_DOMAINS_TABLE(__chv_fw_ranges);
ASSIGN_WRITE_MMIO_VFUNCS(fwtable);
ASSIGN_READ_MMIO_VFUNCS(fwtable);
} else {
ASSIGN_WRITE_MMIO_VFUNCS(gen8);
ASSIGN_READ_MMIO_VFUNCS(gen6);
}
} else {
ASSIGN_FW_DOMAINS_TABLE(__gen9_fw_ranges);
ASSIGN_WRITE_MMIO_VFUNCS(fwtable);
ASSIGN_READ_MMIO_VFUNCS(fwtable);
if (HAS_DECOUPLED_MMIO(dev_priv)) {
dev_priv->uncore.funcs.mmio_readl =
gen9_decoupled_read32;
dev_priv->uncore.funcs.mmio_readq =
gen9_decoupled_read64;
dev_priv->uncore.funcs.mmio_writel =
gen9_decoupled_write32;
}
}
iosf_mbi_register_pmic_bus_access_notifier(
&dev_priv->uncore.pmic_bus_access_nb);
i915_check_and_clear_faults(dev_priv);
}
void intel_uncore_fini(struct drm_i915_private *dev_priv)
{
iosf_mbi_unregister_pmic_bus_access_notifier(
&dev_priv->uncore.pmic_bus_access_nb);
intel_uncore_sanitize(dev_priv);
intel_uncore_forcewake_reset(dev_priv, false);
}
int i915_reg_read_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_reg_read *reg = data;
struct register_whitelist const *entry = whitelist;
unsigned size;
i915_reg_t offset_ldw, offset_udw;
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(whitelist); i++, entry++) {
if (i915_mmio_reg_offset(entry->offset_ldw) == (reg->offset & -entry->size) &&
(INTEL_INFO(dev_priv)->gen_mask & entry->gen_bitmask))
break;
}
if (i == ARRAY_SIZE(whitelist))
return -EINVAL;
offset_ldw = entry->offset_ldw;
offset_udw = entry->offset_udw;
size = entry->size;
size |= reg->offset ^ i915_mmio_reg_offset(offset_ldw);
intel_runtime_pm_get(dev_priv);
switch (size) {
case 8 | 1:
reg->val = I915_READ64_2x32(offset_ldw, offset_udw);
break;
case 8:
reg->val = I915_READ64(offset_ldw);
break;
case 4:
reg->val = I915_READ(offset_ldw);
break;
case 2:
reg->val = I915_READ16(offset_ldw);
break;
case 1:
reg->val = I915_READ8(offset_ldw);
break;
default:
ret = -EINVAL;
goto out;
}
out:
intel_runtime_pm_put(dev_priv);
return ret;
}
static int i915_reset_complete(struct pci_dev *pdev)
{
u8 gdrst;
pci_read_config_byte(pdev, I915_GDRST, &gdrst);
return (gdrst & GRDOM_RESET_STATUS) == 0;
}
static int i915_do_reset(struct drm_i915_private *dev_priv, unsigned engine_mask)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
pci_write_config_byte(pdev, I915_GDRST, GRDOM_RESET_ENABLE);
udelay(20);
pci_write_config_byte(pdev, I915_GDRST, 0);
return wait_for(i915_reset_complete(pdev), 500);
}
static int g4x_reset_complete(struct pci_dev *pdev)
{
u8 gdrst;
pci_read_config_byte(pdev, I915_GDRST, &gdrst);
return (gdrst & GRDOM_RESET_ENABLE) == 0;
}
static int g33_do_reset(struct drm_i915_private *dev_priv, unsigned engine_mask)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
pci_write_config_byte(pdev, I915_GDRST, GRDOM_RESET_ENABLE);
return wait_for(g4x_reset_complete(pdev), 500);
}
static int g4x_do_reset(struct drm_i915_private *dev_priv, unsigned engine_mask)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
int ret;
pci_write_config_byte(pdev, I915_GDRST,
GRDOM_RENDER | GRDOM_RESET_ENABLE);
ret = wait_for(g4x_reset_complete(pdev), 500);
if (ret)
return ret;
I915_WRITE(VDECCLK_GATE_D, I915_READ(VDECCLK_GATE_D) | VCP_UNIT_CLOCK_GATE_DISABLE);
POSTING_READ(VDECCLK_GATE_D);
pci_write_config_byte(pdev, I915_GDRST,
GRDOM_MEDIA | GRDOM_RESET_ENABLE);
ret = wait_for(g4x_reset_complete(pdev), 500);
if (ret)
return ret;
I915_WRITE(VDECCLK_GATE_D, I915_READ(VDECCLK_GATE_D) & ~VCP_UNIT_CLOCK_GATE_DISABLE);
POSTING_READ(VDECCLK_GATE_D);
pci_write_config_byte(pdev, I915_GDRST, 0);
return 0;
}
static int ironlake_do_reset(struct drm_i915_private *dev_priv,
unsigned engine_mask)
{
int ret;
I915_WRITE(ILK_GDSR,
ILK_GRDOM_RENDER | ILK_GRDOM_RESET_ENABLE);
ret = intel_wait_for_register(dev_priv,
ILK_GDSR, ILK_GRDOM_RESET_ENABLE, 0,
500);
if (ret)
return ret;
I915_WRITE(ILK_GDSR,
ILK_GRDOM_MEDIA | ILK_GRDOM_RESET_ENABLE);
ret = intel_wait_for_register(dev_priv,
ILK_GDSR, ILK_GRDOM_RESET_ENABLE, 0,
500);
if (ret)
return ret;
I915_WRITE(ILK_GDSR, 0);
return 0;
}
static int gen6_hw_domain_reset(struct drm_i915_private *dev_priv,
u32 hw_domain_mask)
{
__raw_i915_write32(dev_priv, GEN6_GDRST, hw_domain_mask);
return intel_wait_for_register_fw(dev_priv,
GEN6_GDRST, hw_domain_mask, 0,
500);
}
static int gen6_reset_engines(struct drm_i915_private *dev_priv,
unsigned engine_mask)
{
struct intel_engine_cs *engine;
const u32 hw_engine_mask[I915_NUM_ENGINES] = {
[RCS] = GEN6_GRDOM_RENDER,
[BCS] = GEN6_GRDOM_BLT,
[VCS] = GEN6_GRDOM_MEDIA,
[VCS2] = GEN8_GRDOM_MEDIA2,
[VECS] = GEN6_GRDOM_VECS,
};
u32 hw_mask;
int ret;
if (engine_mask == ALL_ENGINES) {
hw_mask = GEN6_GRDOM_FULL;
} else {
unsigned int tmp;
hw_mask = 0;
for_each_engine_masked(engine, dev_priv, engine_mask, tmp)
hw_mask |= hw_engine_mask[engine->id];
}
ret = gen6_hw_domain_reset(dev_priv, hw_mask);
intel_uncore_forcewake_reset(dev_priv, true);
return ret;
}
int intel_wait_for_register_fw(struct drm_i915_private *dev_priv,
i915_reg_t reg,
const u32 mask,
const u32 value,
const unsigned long timeout_ms)
{
#define done ((I915_READ_FW(reg) & mask) == value)
int ret = wait_for_us(done, 2);
if (ret)
ret = wait_for(done, timeout_ms);
return ret;
#undef done
}
int intel_wait_for_register(struct drm_i915_private *dev_priv,
i915_reg_t reg,
const u32 mask,
const u32 value,
const unsigned long timeout_ms)
{
unsigned fw =
intel_uncore_forcewake_for_reg(dev_priv, reg, FW_REG_READ);
int ret;
intel_uncore_forcewake_get(dev_priv, fw);
ret = wait_for_us((I915_READ_FW(reg) & mask) == value, 2);
intel_uncore_forcewake_put(dev_priv, fw);
if (ret)
ret = wait_for((I915_READ_NOTRACE(reg) & mask) == value,
timeout_ms);
return ret;
}
static int gen8_request_engine_reset(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
I915_WRITE_FW(RING_RESET_CTL(engine->mmio_base),
_MASKED_BIT_ENABLE(RESET_CTL_REQUEST_RESET));
ret = intel_wait_for_register_fw(dev_priv,
RING_RESET_CTL(engine->mmio_base),
RESET_CTL_READY_TO_RESET,
RESET_CTL_READY_TO_RESET,
700);
if (ret)
DRM_ERROR("%s: reset request timeout\n", engine->name);
return ret;
}
static void gen8_unrequest_engine_reset(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_FW(RING_RESET_CTL(engine->mmio_base),
_MASKED_BIT_DISABLE(RESET_CTL_REQUEST_RESET));
}
static int gen8_reset_engines(struct drm_i915_private *dev_priv,
unsigned engine_mask)
{
struct intel_engine_cs *engine;
unsigned int tmp;
for_each_engine_masked(engine, dev_priv, engine_mask, tmp)
if (gen8_request_engine_reset(engine))
goto not_ready;
return gen6_reset_engines(dev_priv, engine_mask);
not_ready:
for_each_engine_masked(engine, dev_priv, engine_mask, tmp)
gen8_unrequest_engine_reset(engine);
return -EIO;
}
static reset_func intel_get_gpu_reset(struct drm_i915_private *dev_priv)
{
if (!i915.reset)
return NULL;
if (INTEL_INFO(dev_priv)->gen >= 8)
return gen8_reset_engines;
else if (INTEL_INFO(dev_priv)->gen >= 6)
return gen6_reset_engines;
else if (IS_GEN5(dev_priv))
return ironlake_do_reset;
else if (IS_G4X(dev_priv))
return g4x_do_reset;
else if (IS_G33(dev_priv) || IS_PINEVIEW(dev_priv))
return g33_do_reset;
else if (INTEL_INFO(dev_priv)->gen >= 3)
return i915_do_reset;
else
return NULL;
}
int intel_gpu_reset(struct drm_i915_private *dev_priv, unsigned engine_mask)
{
reset_func reset;
int ret;
reset = intel_get_gpu_reset(dev_priv);
if (reset == NULL)
return -ENODEV;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
ret = reset(dev_priv, engine_mask);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
return ret;
}
bool intel_has_gpu_reset(struct drm_i915_private *dev_priv)
{
return intel_get_gpu_reset(dev_priv) != NULL;
}
int intel_guc_reset(struct drm_i915_private *dev_priv)
{
int ret;
unsigned long irqflags;
if (!HAS_GUC(dev_priv))
return -EINVAL;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
ret = gen6_hw_domain_reset(dev_priv, GEN9_GRDOM_GUC);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
return ret;
}
bool intel_uncore_unclaimed_mmio(struct drm_i915_private *dev_priv)
{
return check_for_unclaimed_mmio(dev_priv);
}
bool
intel_uncore_arm_unclaimed_mmio_detection(struct drm_i915_private *dev_priv)
{
if (unlikely(i915.mmio_debug ||
dev_priv->uncore.unclaimed_mmio_check <= 0))
return false;
if (unlikely(intel_uncore_unclaimed_mmio(dev_priv))) {
DRM_DEBUG("Unclaimed register detected, "
"enabling oneshot unclaimed register reporting. "
"Please use i915.mmio_debug=N for more information.\n");
i915.mmio_debug++;
dev_priv->uncore.unclaimed_mmio_check--;
return true;
}
return false;
}
static enum forcewake_domains
intel_uncore_forcewake_for_read(struct drm_i915_private *dev_priv,
i915_reg_t reg)
{
u32 offset = i915_mmio_reg_offset(reg);
enum forcewake_domains fw_domains;
if (HAS_FWTABLE(dev_priv)) {
fw_domains = __fwtable_reg_read_fw_domains(offset);
} else if (INTEL_GEN(dev_priv) >= 6) {
fw_domains = __gen6_reg_read_fw_domains(offset);
} else {
WARN_ON(!IS_GEN(dev_priv, 2, 5));
fw_domains = 0;
}
WARN_ON(fw_domains & ~dev_priv->uncore.fw_domains);
return fw_domains;
}
static enum forcewake_domains
intel_uncore_forcewake_for_write(struct drm_i915_private *dev_priv,
i915_reg_t reg)
{
u32 offset = i915_mmio_reg_offset(reg);
enum forcewake_domains fw_domains;
if (HAS_FWTABLE(dev_priv) && !IS_VALLEYVIEW(dev_priv)) {
fw_domains = __fwtable_reg_write_fw_domains(offset);
} else if (IS_GEN8(dev_priv)) {
fw_domains = __gen8_reg_write_fw_domains(offset);
} else if (IS_GEN(dev_priv, 6, 7)) {
fw_domains = FORCEWAKE_RENDER;
} else {
WARN_ON(!IS_GEN(dev_priv, 2, 5));
fw_domains = 0;
}
WARN_ON(fw_domains & ~dev_priv->uncore.fw_domains);
return fw_domains;
}
enum forcewake_domains
intel_uncore_forcewake_for_reg(struct drm_i915_private *dev_priv,
i915_reg_t reg, unsigned int op)
{
enum forcewake_domains fw_domains = 0;
WARN_ON(!op);
if (intel_vgpu_active(dev_priv))
return 0;
if (op & FW_REG_READ)
fw_domains = intel_uncore_forcewake_for_read(dev_priv, reg);
if (op & FW_REG_WRITE)
fw_domains |= intel_uncore_forcewake_for_write(dev_priv, reg);
return fw_domains;
}
