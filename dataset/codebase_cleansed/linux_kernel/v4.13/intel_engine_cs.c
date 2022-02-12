static u32
__intel_engine_context_size(struct drm_i915_private *dev_priv, u8 class)
{
u32 cxt_size;
BUILD_BUG_ON(I915_GTT_PAGE_SIZE != PAGE_SIZE);
switch (class) {
case RENDER_CLASS:
switch (INTEL_GEN(dev_priv)) {
default:
MISSING_CASE(INTEL_GEN(dev_priv));
case 9:
return GEN9_LR_CONTEXT_RENDER_SIZE;
case 8:
return i915.enable_execlists ?
GEN8_LR_CONTEXT_RENDER_SIZE :
GEN8_CXT_TOTAL_SIZE;
case 7:
if (IS_HASWELL(dev_priv))
return HSW_CXT_TOTAL_SIZE;
cxt_size = I915_READ(GEN7_CXT_SIZE);
return round_up(GEN7_CXT_TOTAL_SIZE(cxt_size) * 64,
PAGE_SIZE);
case 6:
cxt_size = I915_READ(CXT_SIZE);
return round_up(GEN6_CXT_TOTAL_SIZE(cxt_size) * 64,
PAGE_SIZE);
case 5:
case 4:
case 3:
case 2:
case 1:
return 0;
}
break;
default:
MISSING_CASE(class);
case VIDEO_DECODE_CLASS:
case VIDEO_ENHANCEMENT_CLASS:
case COPY_ENGINE_CLASS:
if (INTEL_GEN(dev_priv) < 8)
return 0;
return GEN8_LR_CONTEXT_OTHER_SIZE;
}
}
static int
intel_engine_setup(struct drm_i915_private *dev_priv,
enum intel_engine_id id)
{
const struct engine_info *info = &intel_engines[id];
const struct engine_class_info *class_info;
struct intel_engine_cs *engine;
GEM_BUG_ON(info->class >= ARRAY_SIZE(intel_engine_classes));
class_info = &intel_engine_classes[info->class];
GEM_BUG_ON(dev_priv->engine[id]);
engine = kzalloc(sizeof(*engine), GFP_KERNEL);
if (!engine)
return -ENOMEM;
engine->id = id;
engine->i915 = dev_priv;
WARN_ON(snprintf(engine->name, sizeof(engine->name), "%s%u",
class_info->name, info->instance) >=
sizeof(engine->name));
engine->uabi_id = info->uabi_id;
engine->hw_id = engine->guc_id = info->hw_id;
engine->mmio_base = info->mmio_base;
engine->irq_shift = info->irq_shift;
engine->class = info->class;
engine->instance = info->instance;
engine->context_size = __intel_engine_context_size(dev_priv,
engine->class);
if (WARN_ON(engine->context_size > BIT(20)))
engine->context_size = 0;
engine->schedule = NULL;
ATOMIC_INIT_NOTIFIER_HEAD(&engine->context_status_notifier);
dev_priv->engine[id] = engine;
return 0;
}
int intel_engines_init_mmio(struct drm_i915_private *dev_priv)
{
struct intel_device_info *device_info = mkwrite_device_info(dev_priv);
const unsigned int ring_mask = INTEL_INFO(dev_priv)->ring_mask;
struct intel_engine_cs *engine;
enum intel_engine_id id;
unsigned int mask = 0;
unsigned int i;
int err;
WARN_ON(ring_mask == 0);
WARN_ON(ring_mask &
GENMASK(sizeof(mask) * BITS_PER_BYTE - 1, I915_NUM_ENGINES));
for (i = 0; i < ARRAY_SIZE(intel_engines); i++) {
if (!HAS_ENGINE(dev_priv, i))
continue;
err = intel_engine_setup(dev_priv, i);
if (err)
goto cleanup;
mask |= ENGINE_MASK(i);
}
if (WARN_ON(mask != ring_mask))
device_info->ring_mask = mask;
if (WARN_ON(!HAS_ENGINE(dev_priv, RCS))) {
err = -ENODEV;
goto cleanup;
}
device_info->num_rings = hweight32(mask);
return 0;
cleanup:
for_each_engine(engine, dev_priv, id)
kfree(engine);
return err;
}
int intel_engines_init(struct drm_i915_private *dev_priv)
{
struct intel_device_info *device_info = mkwrite_device_info(dev_priv);
struct intel_engine_cs *engine;
enum intel_engine_id id, err_id;
unsigned int mask = 0;
int err = 0;
for_each_engine(engine, dev_priv, id) {
const struct engine_class_info *class_info =
&intel_engine_classes[engine->class];
int (*init)(struct intel_engine_cs *engine);
if (i915.enable_execlists)
init = class_info->init_execlists;
else
init = class_info->init_legacy;
if (!init) {
kfree(engine);
dev_priv->engine[id] = NULL;
continue;
}
err = init(engine);
if (err) {
err_id = id;
goto cleanup;
}
GEM_BUG_ON(!engine->submit_request);
mask |= ENGINE_MASK(id);
}
if (WARN_ON(mask != INTEL_INFO(dev_priv)->ring_mask))
device_info->ring_mask = mask;
device_info->num_rings = hweight32(mask);
return 0;
cleanup:
for_each_engine(engine, dev_priv, id) {
if (id >= err_id)
kfree(engine);
else
dev_priv->gt.cleanup_engine(engine);
}
return err;
}
void intel_engine_init_global_seqno(struct intel_engine_cs *engine, u32 seqno)
{
struct drm_i915_private *dev_priv = engine->i915;
GEM_BUG_ON(!intel_engine_is_idle(engine));
GEM_BUG_ON(i915_gem_active_isset(&engine->timeline->last_request));
if (IS_GEN6(dev_priv) || IS_GEN7(dev_priv)) {
I915_WRITE(RING_SYNC_0(engine->mmio_base), 0);
I915_WRITE(RING_SYNC_1(engine->mmio_base), 0);
if (HAS_VEBOX(dev_priv))
I915_WRITE(RING_SYNC_2(engine->mmio_base), 0);
}
if (dev_priv->semaphore) {
struct page *page = i915_vma_first_page(dev_priv->semaphore);
void *semaphores;
semaphores = kmap_atomic(page);
memset(semaphores + GEN8_SEMAPHORE_OFFSET(engine->id, 0),
0, I915_NUM_ENGINES * gen8_semaphore_seqno_size);
drm_clflush_virt_range(semaphores + GEN8_SEMAPHORE_OFFSET(engine->id, 0),
I915_NUM_ENGINES * gen8_semaphore_seqno_size);
kunmap_atomic(semaphores);
}
intel_write_status_page(engine, I915_GEM_HWS_INDEX, seqno);
clear_bit(ENGINE_IRQ_BREADCRUMB, &engine->irq_posted);
intel_engine_wakeup(engine);
GEM_BUG_ON(intel_engine_get_seqno(engine) != seqno);
}
static void intel_engine_init_timeline(struct intel_engine_cs *engine)
{
engine->timeline = &engine->i915->gt.global_timeline.engine[engine->id];
}
void intel_engine_setup_common(struct intel_engine_cs *engine)
{
engine->execlist_queue = RB_ROOT;
engine->execlist_first = NULL;
intel_engine_init_timeline(engine);
intel_engine_init_hangcheck(engine);
i915_gem_batch_pool_init(engine, &engine->batch_pool);
intel_engine_init_cmd_parser(engine);
}
int intel_engine_create_scratch(struct intel_engine_cs *engine, int size)
{
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
int ret;
WARN_ON(engine->scratch);
obj = i915_gem_object_create_stolen(engine->i915, size);
if (!obj)
obj = i915_gem_object_create_internal(engine->i915, size);
if (IS_ERR(obj)) {
DRM_ERROR("Failed to allocate scratch page\n");
return PTR_ERR(obj);
}
vma = i915_vma_instance(obj, &engine->i915->ggtt.base, NULL);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto err_unref;
}
ret = i915_vma_pin(vma, 0, 4096, PIN_GLOBAL | PIN_HIGH);
if (ret)
goto err_unref;
engine->scratch = vma;
DRM_DEBUG_DRIVER("%s pipe control offset: 0x%08x\n",
engine->name, i915_ggtt_offset(vma));
return 0;
err_unref:
i915_gem_object_put(obj);
return ret;
}
static void intel_engine_cleanup_scratch(struct intel_engine_cs *engine)
{
i915_vma_unpin_and_release(&engine->scratch);
}
int intel_engine_init_common(struct intel_engine_cs *engine)
{
struct intel_ring *ring;
int ret;
engine->set_default_submission(engine);
ring = engine->context_pin(engine, engine->i915->kernel_context);
if (IS_ERR(ring))
return PTR_ERR(ring);
ret = intel_engine_init_breadcrumbs(engine);
if (ret)
goto err_unpin;
ret = i915_gem_render_state_init(engine);
if (ret)
goto err_unpin;
return 0;
err_unpin:
engine->context_unpin(engine, engine->i915->kernel_context);
return ret;
}
void intel_engine_cleanup_common(struct intel_engine_cs *engine)
{
intel_engine_cleanup_scratch(engine);
i915_gem_render_state_fini(engine);
intel_engine_fini_breadcrumbs(engine);
intel_engine_cleanup_cmd_parser(engine);
i915_gem_batch_pool_fini(&engine->batch_pool);
engine->context_unpin(engine, engine->i915->kernel_context);
}
u64 intel_engine_get_active_head(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
u64 acthd;
if (INTEL_GEN(dev_priv) >= 8)
acthd = I915_READ64_2x32(RING_ACTHD(engine->mmio_base),
RING_ACTHD_UDW(engine->mmio_base));
else if (INTEL_GEN(dev_priv) >= 4)
acthd = I915_READ(RING_ACTHD(engine->mmio_base));
else
acthd = I915_READ(ACTHD);
return acthd;
}
u64 intel_engine_get_last_batch_head(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
u64 bbaddr;
if (INTEL_GEN(dev_priv) >= 8)
bbaddr = I915_READ64_2x32(RING_BBADDR(engine->mmio_base),
RING_BBADDR_UDW(engine->mmio_base));
else
bbaddr = I915_READ(RING_BBADDR(engine->mmio_base));
return bbaddr;
}
const char *i915_cache_level_str(struct drm_i915_private *i915, int type)
{
switch (type) {
case I915_CACHE_NONE: return " uncached";
case I915_CACHE_LLC: return HAS_LLC(i915) ? " LLC" : " snooped";
case I915_CACHE_L3_LLC: return " L3+LLC";
case I915_CACHE_WT: return " WT";
default: return "";
}
}
static inline uint32_t
read_subslice_reg(struct drm_i915_private *dev_priv, int slice,
int subslice, i915_reg_t reg)
{
uint32_t mcr;
uint32_t ret;
enum forcewake_domains fw_domains;
fw_domains = intel_uncore_forcewake_for_reg(dev_priv, reg,
FW_REG_READ);
fw_domains |= intel_uncore_forcewake_for_reg(dev_priv,
GEN8_MCR_SELECTOR,
FW_REG_READ | FW_REG_WRITE);
spin_lock_irq(&dev_priv->uncore.lock);
intel_uncore_forcewake_get__locked(dev_priv, fw_domains);
mcr = I915_READ_FW(GEN8_MCR_SELECTOR);
WARN_ON_ONCE(mcr & (GEN8_MCR_SLICE_MASK | GEN8_MCR_SUBSLICE_MASK));
mcr &= ~(GEN8_MCR_SLICE_MASK | GEN8_MCR_SUBSLICE_MASK);
mcr |= GEN8_MCR_SLICE(slice) | GEN8_MCR_SUBSLICE(subslice);
I915_WRITE_FW(GEN8_MCR_SELECTOR, mcr);
ret = I915_READ_FW(reg);
mcr &= ~(GEN8_MCR_SLICE_MASK | GEN8_MCR_SUBSLICE_MASK);
I915_WRITE_FW(GEN8_MCR_SELECTOR, mcr);
intel_uncore_forcewake_put__locked(dev_priv, fw_domains);
spin_unlock_irq(&dev_priv->uncore.lock);
return ret;
}
void intel_engine_get_instdone(struct intel_engine_cs *engine,
struct intel_instdone *instdone)
{
struct drm_i915_private *dev_priv = engine->i915;
u32 mmio_base = engine->mmio_base;
int slice;
int subslice;
memset(instdone, 0, sizeof(*instdone));
switch (INTEL_GEN(dev_priv)) {
default:
instdone->instdone = I915_READ(RING_INSTDONE(mmio_base));
if (engine->id != RCS)
break;
instdone->slice_common = I915_READ(GEN7_SC_INSTDONE);
for_each_instdone_slice_subslice(dev_priv, slice, subslice) {
instdone->sampler[slice][subslice] =
read_subslice_reg(dev_priv, slice, subslice,
GEN7_SAMPLER_INSTDONE);
instdone->row[slice][subslice] =
read_subslice_reg(dev_priv, slice, subslice,
GEN7_ROW_INSTDONE);
}
break;
case 7:
instdone->instdone = I915_READ(RING_INSTDONE(mmio_base));
if (engine->id != RCS)
break;
instdone->slice_common = I915_READ(GEN7_SC_INSTDONE);
instdone->sampler[0][0] = I915_READ(GEN7_SAMPLER_INSTDONE);
instdone->row[0][0] = I915_READ(GEN7_ROW_INSTDONE);
break;
case 6:
case 5:
case 4:
instdone->instdone = I915_READ(RING_INSTDONE(mmio_base));
if (engine->id == RCS)
instdone->slice_common = I915_READ(GEN4_INSTDONE1);
break;
case 3:
case 2:
instdone->instdone = I915_READ(GEN2_INSTDONE);
break;
}
}
static int wa_add(struct drm_i915_private *dev_priv,
i915_reg_t addr,
const u32 mask, const u32 val)
{
const u32 idx = dev_priv->workarounds.count;
if (WARN_ON(idx >= I915_MAX_WA_REGS))
return -ENOSPC;
dev_priv->workarounds.reg[idx].addr = addr;
dev_priv->workarounds.reg[idx].value = val;
dev_priv->workarounds.reg[idx].mask = mask;
dev_priv->workarounds.count++;
return 0;
}
static int wa_ring_whitelist_reg(struct intel_engine_cs *engine,
i915_reg_t reg)
{
struct drm_i915_private *dev_priv = engine->i915;
struct i915_workarounds *wa = &dev_priv->workarounds;
const uint32_t index = wa->hw_whitelist_count[engine->id];
if (WARN_ON(index >= RING_MAX_NONPRIV_SLOTS))
return -EINVAL;
WA_WRITE(RING_FORCE_TO_NONPRIV(engine->mmio_base, index),
i915_mmio_reg_offset(reg));
wa->hw_whitelist_count[engine->id]++;
return 0;
}
static int gen8_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
WA_SET_BIT_MASKED(INSTPM, INSTPM_FORCE_ORDERING);
WA_SET_BIT_MASKED(MI_MODE, ASYNC_FLIP_PERF_DISABLE);
WA_SET_BIT_MASKED(GEN8_ROW_CHICKEN,
PARTIAL_INSTRUCTION_SHOOTDOWN_DISABLE);
WA_SET_BIT_MASKED(HDC_CHICKEN0,
HDC_DONOT_FETCH_MEM_WHEN_MASKED |
HDC_FORCE_NON_COHERENT);
WA_CLR_BIT_MASKED(CACHE_MODE_0_GEN7, HIZ_RAW_STALL_OPT_DISABLE);
WA_SET_BIT_MASKED(CACHE_MODE_1, GEN8_4x4_STC_OPTIMIZATION_DISABLE);
WA_SET_FIELD_MASKED(GEN7_GT_MODE,
GEN6_WIZ_HASHING_MASK,
GEN6_WIZ_HASHING_16x4);
return 0;
}
static int bdw_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen8_init_workarounds(engine);
if (ret)
return ret;
WA_SET_BIT_MASKED(GEN8_ROW_CHICKEN, STALL_DOP_GATING_DISABLE);
WA_SET_BIT_MASKED(GEN7_ROW_CHICKEN2,
DOP_CLOCK_GATING_DISABLE);
WA_SET_BIT_MASKED(HALF_SLICE_CHICKEN3,
GEN8_SAMPLER_POWER_BYPASS_DIS);
WA_SET_BIT_MASKED(HDC_CHICKEN0,
HDC_FORCE_CONTEXT_SAVE_RESTORE_NON_COHERENT |
(IS_BDW_GT3(dev_priv) ? HDC_FENCE_DEST_SLM_DISABLE : 0));
return 0;
}
static int chv_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen8_init_workarounds(engine);
if (ret)
return ret;
WA_SET_BIT_MASKED(GEN8_ROW_CHICKEN, STALL_DOP_GATING_DISABLE);
WA_SET_BIT_MASKED(HIZ_CHICKEN, CHV_HZ_8X8_MODE_IN_1X);
return 0;
}
static int gen9_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
I915_WRITE(GEN9_CSFE_CHICKEN1_RCS, _MASKED_BIT_ENABLE(GEN9_PREEMPT_GPGPU_SYNC_SWITCH_DISABLE));
I915_WRITE(BDW_SCRATCH1, I915_READ(BDW_SCRATCH1) |
GEN9_LBS_SLA_RETRY_TIMER_DECREMENT_ENABLE);
if (!IS_COFFEELAKE(dev_priv))
I915_WRITE(GAM_ECOCHK, I915_READ(GAM_ECOCHK) |
ECOCHK_DIS_TLB);
WA_SET_BIT_MASKED(GEN8_ROW_CHICKEN,
FLOW_CONTROL_ENABLE |
PARTIAL_INSTRUCTION_SHOOTDOWN_DISABLE);
if (!IS_COFFEELAKE(dev_priv))
WA_SET_BIT_MASKED(HALF_SLICE_CHICKEN3,
GEN9_DISABLE_OCL_OOB_SUPPRESS_LOGIC);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
WA_CLR_BIT_MASKED(GEN9_HALF_SLICE_CHICKEN5,
GEN9_DG_MIRROR_FIX_ENABLE);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) {
WA_SET_BIT_MASKED(GEN7_COMMON_SLICE_CHICKEN1,
GEN9_RHWO_OPTIMIZATION_DISABLE);
}
WA_SET_BIT_MASKED(GEN9_HALF_SLICE_CHICKEN7,
GEN9_ENABLE_YV12_BUGFIX |
GEN9_ENABLE_GPGPU_PREEMPTION);
WA_SET_BIT_MASKED(CACHE_MODE_1, (GEN8_4x4_STC_OPTIMIZATION_DISABLE |
GEN9_PARTIAL_RESOLVE_IN_VC_DISABLE));
WA_CLR_BIT_MASKED(GEN9_HALF_SLICE_CHICKEN5,
GEN9_CCS_TLB_PREFETCH_ENABLE);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
WA_SET_BIT_MASKED(SLICE_ECO_CHICKEN0,
PIXEL_MASK_CAMMING_DISABLE);
WA_SET_BIT_MASKED(HDC_CHICKEN0,
HDC_FORCE_CONTEXT_SAVE_RESTORE_NON_COHERENT |
HDC_FORCE_CSR_NON_COHERENT_OVR_DISABLE);
WA_SET_BIT_MASKED(HDC_CHICKEN0,
HDC_FORCE_NON_COHERENT);
I915_WRITE(GAM_ECOCHK, I915_READ(GAM_ECOCHK) |
BDW_DISABLE_HDC_INVALIDATION);
if (IS_SKYLAKE(dev_priv) ||
IS_KABYLAKE(dev_priv) ||
IS_COFFEELAKE(dev_priv) ||
IS_BXT_REVID(dev_priv, 0, BXT_REVID_B0))
WA_SET_BIT_MASKED(HALF_SLICE_CHICKEN3,
GEN8_SAMPLER_POWER_BYPASS_DIS);
WA_SET_BIT_MASKED(HALF_SLICE_CHICKEN2, GEN8_ST_PO_DISABLE);
I915_WRITE(GEN8_L3SQCREG4, (I915_READ(GEN8_L3SQCREG4) |
GEN8_LQSC_FLUSH_COHERENT_LINES));
ret = wa_ring_whitelist_reg(engine, GEN9_CTX_PREEMPT_REG);
if (ret)
return ret;
ret= wa_ring_whitelist_reg(engine, GEN8_CS_CHICKEN1);
if (ret)
return ret;
ret = wa_ring_whitelist_reg(engine, GEN8_HDC_CHICKEN1);
if (ret)
return ret;
return 0;
}
static int skl_tune_iz_hashing(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
u8 vals[3] = { 0, 0, 0 };
unsigned int i;
for (i = 0; i < 3; i++) {
u8 ss;
if (!is_power_of_2(INTEL_INFO(dev_priv)->sseu.subslice_7eu[i]))
continue;
ss = ffs(INTEL_INFO(dev_priv)->sseu.subslice_7eu[i]) - 1;
vals[i] = 3 - ss;
}
if (vals[0] == 0 && vals[1] == 0 && vals[2] == 0)
return 0;
WA_SET_FIELD_MASKED(GEN7_GT_MODE,
GEN9_IZ_HASHING_MASK(2) |
GEN9_IZ_HASHING_MASK(1) |
GEN9_IZ_HASHING_MASK(0),
GEN9_IZ_HASHING(2, vals[2]) |
GEN9_IZ_HASHING(1, vals[1]) |
GEN9_IZ_HASHING(0, vals[0]));
return 0;
}
static int skl_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen9_init_workarounds(engine);
if (ret)
return ret;
I915_WRITE(GEN7_FF_SLICE_CS_CHICKEN1,
_MASKED_BIT_ENABLE(GEN9_FFSC_PERCTX_PREEMPT_CTRL));
I915_WRITE(GEN8_GARBCNTL, (I915_READ(GEN8_GARBCNTL) |
GEN9_GAPS_TSV_CREDIT_DISABLE));
WA_SET_BIT(GEN7_UCGCTL4, GEN8_EU_GAUNIT_CLOCK_GATE_DISABLE);
if (IS_SKL_REVID(dev_priv, SKL_REVID_H0, REVID_FOREVER))
WA_SET_BIT(GEN9_GAMT_ECO_REG_RW_IA,
GAMT_ECO_ENABLE_IN_PLACE_DECOMPRESS);
ret = wa_ring_whitelist_reg(engine, GEN8_L3SQCREG4);
if (ret)
return ret;
return skl_tune_iz_hashing(engine);
}
static int bxt_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen9_init_workarounds(engine);
if (ret)
return ret;
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
I915_WRITE(TILECTL, I915_READ(TILECTL) | TILECTL_TLBPF);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) {
I915_WRITE(GEN7_MISCCPCTL, (I915_READ(GEN7_MISCCPCTL) &
~GEN8_DOP_CLOCK_GATE_MEDIA_ENABLE));
}
WA_SET_BIT_MASKED(GEN8_ROW_CHICKEN,
STALL_DOP_GATING_DISABLE);
if (IS_BXT_REVID(dev_priv, BXT_REVID_B0, REVID_FOREVER)) {
WA_SET_BIT_MASKED(FF_SLICE_CS_CHICKEN2,
GEN9_POOLED_EU_LOAD_BALANCING_FIX_DISABLE);
}
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_B0)) {
WA_SET_BIT_MASKED(
GEN7_HALF_SLICE_CHICKEN1,
GEN7_SBE_SS_CACHE_DISPATCH_PORT_SHARING_DISABLE);
}
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) {
ret = wa_ring_whitelist_reg(engine, GEN9_CS_DEBUG_MODE1);
if (ret)
return ret;
ret = wa_ring_whitelist_reg(engine, GEN8_L3SQCREG4);
if (ret)
return ret;
}
if (IS_BXT_REVID(dev_priv, BXT_REVID_B0, REVID_FOREVER))
I915_WRITE(GEN8_L3SQCREG1, L3_GENERAL_PRIO_CREDITS(62) |
L3_HIGH_PRIO_CREDITS(2));
if (IS_BXT_REVID(dev_priv, BXT_REVID_C0, REVID_FOREVER))
WA_SET_BIT_MASKED(COMMON_SLICE_CHICKEN2,
GEN8_SBE_DISABLE_REPLAY_BUF_OPTIMIZATION);
if (IS_BXT_REVID(dev_priv, BXT_REVID_C0, REVID_FOREVER))
WA_SET_BIT(GEN9_GAMT_ECO_REG_RW_IA,
GAMT_ECO_ENABLE_IN_PLACE_DECOMPRESS);
return 0;
}
static int kbl_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen9_init_workarounds(engine);
if (ret)
return ret;
I915_WRITE(GEN8_GARBCNTL, (I915_READ(GEN8_GARBCNTL) |
GEN9_GAPS_TSV_CREDIT_DISABLE));
if (IS_KBL_REVID(dev_priv, 0, KBL_REVID_B0))
WA_SET_BIT(GAMT_CHKN_BIT_REG,
GAMT_CHKN_DISABLE_DYNAMIC_CREDIT_SHARING);
if (IS_KBL_REVID(dev_priv, KBL_REVID_A0, KBL_REVID_A0))
WA_SET_BIT_MASKED(HDC_CHICKEN0,
HDC_FENCE_DEST_SLM_DISABLE);
if (IS_KBL_REVID(dev_priv, KBL_REVID_C0, REVID_FOREVER))
WA_SET_BIT_MASKED(COMMON_SLICE_CHICKEN2,
GEN8_SBE_DISABLE_REPLAY_BUF_OPTIMIZATION);
WA_SET_BIT(GEN7_UCGCTL4, GEN8_EU_GAUNIT_CLOCK_GATE_DISABLE);
WA_SET_BIT_MASKED(
GEN7_HALF_SLICE_CHICKEN1,
GEN7_SBE_SS_CACHE_DISPATCH_PORT_SHARING_DISABLE);
WA_SET_BIT(GEN9_GAMT_ECO_REG_RW_IA,
GAMT_ECO_ENABLE_IN_PLACE_DECOMPRESS);
ret = wa_ring_whitelist_reg(engine, GEN8_L3SQCREG4);
if (ret)
return ret;
return 0;
}
static int glk_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen9_init_workarounds(engine);
if (ret)
return ret;
WA_SET_BIT_MASKED(COMMON_SLICE_CHICKEN2,
GEN8_SBE_DISABLE_REPLAY_BUF_OPTIMIZATION);
return 0;
}
static int cfl_init_workarounds(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen9_init_workarounds(engine);
if (ret)
return ret;
I915_WRITE(GEN8_GARBCNTL, (I915_READ(GEN8_GARBCNTL) |
GEN9_GAPS_TSV_CREDIT_DISABLE));
WA_SET_BIT_MASKED(COMMON_SLICE_CHICKEN2,
GEN8_SBE_DISABLE_REPLAY_BUF_OPTIMIZATION);
WA_SET_BIT(GEN7_UCGCTL4, GEN8_EU_GAUNIT_CLOCK_GATE_DISABLE);
WA_SET_BIT_MASKED(
GEN7_HALF_SLICE_CHICKEN1,
GEN7_SBE_SS_CACHE_DISPATCH_PORT_SHARING_DISABLE);
WA_SET_BIT(GEN9_GAMT_ECO_REG_RW_IA,
GAMT_ECO_ENABLE_IN_PLACE_DECOMPRESS);
return 0;
}
int init_workarounds_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int err;
WARN_ON(engine->id != RCS);
dev_priv->workarounds.count = 0;
dev_priv->workarounds.hw_whitelist_count[engine->id] = 0;
if (IS_BROADWELL(dev_priv))
err = bdw_init_workarounds(engine);
else if (IS_CHERRYVIEW(dev_priv))
err = chv_init_workarounds(engine);
else if (IS_SKYLAKE(dev_priv))
err = skl_init_workarounds(engine);
else if (IS_BROXTON(dev_priv))
err = bxt_init_workarounds(engine);
else if (IS_KABYLAKE(dev_priv))
err = kbl_init_workarounds(engine);
else if (IS_GEMINILAKE(dev_priv))
err = glk_init_workarounds(engine);
else if (IS_COFFEELAKE(dev_priv))
err = cfl_init_workarounds(engine);
else
err = 0;
if (err)
return err;
DRM_DEBUG_DRIVER("%s: Number of context specific w/a: %d\n",
engine->name, dev_priv->workarounds.count);
return 0;
}
int intel_ring_workarounds_emit(struct drm_i915_gem_request *req)
{
struct i915_workarounds *w = &req->i915->workarounds;
u32 *cs;
int ret, i;
if (w->count == 0)
return 0;
ret = req->engine->emit_flush(req, EMIT_BARRIER);
if (ret)
return ret;
cs = intel_ring_begin(req, (w->count * 2 + 2));
if (IS_ERR(cs))
return PTR_ERR(cs);
*cs++ = MI_LOAD_REGISTER_IMM(w->count);
for (i = 0; i < w->count; i++) {
*cs++ = i915_mmio_reg_offset(w->reg[i].addr);
*cs++ = w->reg[i].value;
}
*cs++ = MI_NOOP;
intel_ring_advance(req, cs);
ret = req->engine->emit_flush(req, EMIT_BARRIER);
if (ret)
return ret;
return 0;
}
static bool ring_is_idle(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
bool idle = true;
intel_runtime_pm_get(dev_priv);
if ((I915_READ_HEAD(engine) & HEAD_ADDR) !=
(I915_READ_TAIL(engine) & TAIL_ADDR))
idle = false;
if (INTEL_GEN(dev_priv) > 2 && !(I915_READ_MODE(engine) & MODE_IDLE))
idle = false;
intel_runtime_pm_put(dev_priv);
return idle;
}
bool intel_engine_is_idle(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
if (i915_terminally_wedged(&dev_priv->gpu_error))
return true;
if (!i915_seqno_passed(intel_engine_get_seqno(engine),
intel_engine_last_submit(engine)))
return false;
if (I915_SELFTEST_ONLY(engine->breadcrumbs.mock))
return true;
if (test_bit(ENGINE_IRQ_EXECLIST, &engine->irq_posted))
return false;
if (port_request(&engine->execlist_port[0]))
return false;
if (!ring_is_idle(engine))
return false;
return true;
}
bool intel_engines_are_idle(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
if (READ_ONCE(dev_priv->gt.active_requests))
return false;
if (i915_terminally_wedged(&dev_priv->gpu_error))
return true;
for_each_engine(engine, dev_priv, id) {
if (!intel_engine_is_idle(engine))
return false;
}
return true;
}
void intel_engines_reset_default_submission(struct drm_i915_private *i915)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
for_each_engine(engine, i915, id)
engine->set_default_submission(engine);
}
void intel_engines_mark_idle(struct drm_i915_private *i915)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
for_each_engine(engine, i915, id) {
intel_engine_disarm_breadcrumbs(engine);
i915_gem_batch_pool_fini(&engine->batch_pool);
engine->no_priolist = false;
}
}
