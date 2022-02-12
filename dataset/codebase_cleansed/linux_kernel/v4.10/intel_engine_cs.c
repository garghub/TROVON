static int
intel_engine_setup(struct drm_i915_private *dev_priv,
enum intel_engine_id id)
{
const struct engine_info *info = &intel_engines[id];
struct intel_engine_cs *engine;
GEM_BUG_ON(dev_priv->engine[id]);
engine = kzalloc(sizeof(*engine), GFP_KERNEL);
if (!engine)
return -ENOMEM;
engine->id = id;
engine->i915 = dev_priv;
engine->name = info->name;
engine->exec_id = info->exec_id;
engine->hw_id = engine->guc_id = info->hw_id;
engine->mmio_base = info->mmio_base;
engine->irq_shift = info->irq_shift;
engine->schedule = NULL;
dev_priv->engine[id] = engine;
return 0;
}
int intel_engines_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_device_info *device_info = mkwrite_device_info(dev_priv);
unsigned int ring_mask = INTEL_INFO(dev_priv)->ring_mask;
unsigned int mask = 0;
int (*init)(struct intel_engine_cs *engine);
struct intel_engine_cs *engine;
enum intel_engine_id id;
unsigned int i;
int ret;
WARN_ON(ring_mask == 0);
WARN_ON(ring_mask &
GENMASK(sizeof(mask) * BITS_PER_BYTE - 1, I915_NUM_ENGINES));
for (i = 0; i < ARRAY_SIZE(intel_engines); i++) {
if (!HAS_ENGINE(dev_priv, i))
continue;
if (i915.enable_execlists)
init = intel_engines[i].init_execlists;
else
init = intel_engines[i].init_legacy;
if (!init)
continue;
ret = intel_engine_setup(dev_priv, i);
if (ret)
goto cleanup;
ret = init(dev_priv->engine[i]);
if (ret)
goto cleanup;
mask |= ENGINE_MASK(i);
}
if (WARN_ON(mask != ring_mask))
device_info->ring_mask = mask;
device_info->num_rings = hweight32(mask);
return 0;
cleanup:
for_each_engine(engine, dev_priv, id) {
if (i915.enable_execlists)
intel_logical_ring_cleanup(engine);
else
intel_engine_cleanup(engine);
}
return ret;
}
void intel_engine_init_global_seqno(struct intel_engine_cs *engine, u32 seqno)
{
struct drm_i915_private *dev_priv = engine->i915;
if (IS_GEN6(dev_priv) || IS_GEN7(dev_priv)) {
I915_WRITE(RING_SYNC_0(engine->mmio_base), 0);
I915_WRITE(RING_SYNC_1(engine->mmio_base), 0);
if (HAS_VEBOX(dev_priv))
I915_WRITE(RING_SYNC_2(engine->mmio_base), 0);
}
if (dev_priv->semaphore) {
struct page *page = i915_vma_first_page(dev_priv->semaphore);
void *semaphores;
semaphores = kmap(page);
memset(semaphores + GEN8_SEMAPHORE_OFFSET(engine->id, 0),
0, I915_NUM_ENGINES * gen8_semaphore_seqno_size);
drm_clflush_virt_range(semaphores + GEN8_SEMAPHORE_OFFSET(engine->id, 0),
I915_NUM_ENGINES * gen8_semaphore_seqno_size);
kunmap(page);
}
intel_write_status_page(engine, I915_GEM_HWS_INDEX, seqno);
if (engine->irq_seqno_barrier)
engine->irq_seqno_barrier(engine);
GEM_BUG_ON(i915_gem_active_isset(&engine->timeline->last_request));
engine->timeline->last_submitted_seqno = seqno;
engine->hangcheck.seqno = seqno;
intel_engine_wakeup(engine);
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
obj = i915_gem_object_create_stolen(&engine->i915->drm, size);
if (!obj)
obj = i915_gem_object_create_internal(engine->i915, size);
if (IS_ERR(obj)) {
DRM_ERROR("Failed to allocate scratch page\n");
return PTR_ERR(obj);
}
vma = i915_vma_create(obj, &engine->i915->ggtt.base, NULL);
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
int ret;
ret = intel_engine_init_breadcrumbs(engine);
if (ret)
return ret;
ret = i915_gem_render_state_init(engine);
if (ret)
return ret;
return 0;
}
void intel_engine_cleanup_common(struct intel_engine_cs *engine)
{
intel_engine_cleanup_scratch(engine);
i915_gem_render_state_fini(engine);
intel_engine_fini_breadcrumbs(engine);
intel_engine_cleanup_cmd_parser(engine);
i915_gem_batch_pool_fini(&engine->batch_pool);
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
