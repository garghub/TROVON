int __intel_ring_space(int head, int tail, int size)
{
int space = head - tail;
if (space <= 0)
space += size;
return space - I915_RING_FREE_SPACE;
}
void intel_ring_update_space(struct intel_ringbuffer *ringbuf)
{
if (ringbuf->last_retired_head != -1) {
ringbuf->head = ringbuf->last_retired_head;
ringbuf->last_retired_head = -1;
}
ringbuf->space = __intel_ring_space(ringbuf->head & HEAD_ADDR,
ringbuf->tail, ringbuf->size);
}
static void __intel_ring_advance(struct intel_engine_cs *engine)
{
struct intel_ringbuffer *ringbuf = engine->buffer;
ringbuf->tail &= ringbuf->size - 1;
engine->write_tail(engine, ringbuf->tail);
}
static int
gen2_render_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate_domains,
u32 flush_domains)
{
struct intel_engine_cs *engine = req->engine;
u32 cmd;
int ret;
cmd = MI_FLUSH;
if (((invalidate_domains|flush_domains) & I915_GEM_DOMAIN_RENDER) == 0)
cmd |= MI_NO_WRITE_FLUSH;
if (invalidate_domains & I915_GEM_DOMAIN_SAMPLER)
cmd |= MI_READ_FLUSH;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine, cmd);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
return 0;
}
static int
gen4_render_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate_domains,
u32 flush_domains)
{
struct intel_engine_cs *engine = req->engine;
u32 cmd;
int ret;
cmd = MI_FLUSH | MI_NO_WRITE_FLUSH;
if ((invalidate_domains|flush_domains) & I915_GEM_DOMAIN_RENDER)
cmd &= ~MI_NO_WRITE_FLUSH;
if (invalidate_domains & I915_GEM_DOMAIN_INSTRUCTION)
cmd |= MI_EXE_FLUSH;
if (invalidate_domains & I915_GEM_DOMAIN_COMMAND &&
(IS_G4X(req->i915) || IS_GEN5(req->i915)))
cmd |= MI_INVALIDATE_ISP;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine, cmd);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
return 0;
}
static int
intel_emit_post_sync_nonzero_flush(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
u32 scratch_addr = engine->scratch.gtt_offset + 2 * CACHELINE_BYTES;
int ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(5));
intel_ring_emit(engine, PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_STALL_AT_SCOREBOARD);
intel_ring_emit(engine, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(5));
intel_ring_emit(engine, PIPE_CONTROL_QW_WRITE);
intel_ring_emit(engine, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
return 0;
}
static int
gen6_render_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate_domains, u32 flush_domains)
{
struct intel_engine_cs *engine = req->engine;
u32 flags = 0;
u32 scratch_addr = engine->scratch.gtt_offset + 2 * CACHELINE_BYTES;
int ret;
ret = intel_emit_post_sync_nonzero_flush(req);
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
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(engine, flags);
intel_ring_emit(engine, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(engine, 0);
intel_ring_advance(engine);
return 0;
}
static int
gen7_render_ring_cs_stall_wa(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(engine, PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_STALL_AT_SCOREBOARD);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
intel_ring_advance(engine);
return 0;
}
static int
gen7_render_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate_domains, u32 flush_domains)
{
struct intel_engine_cs *engine = req->engine;
u32 flags = 0;
u32 scratch_addr = engine->scratch.gtt_offset + 2 * CACHELINE_BYTES;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_DC_FLUSH_ENABLE;
flags |= PIPE_CONTROL_FLUSH_ENABLE;
}
if (invalidate_domains) {
flags |= PIPE_CONTROL_TLB_INVALIDATE;
flags |= PIPE_CONTROL_INSTRUCTION_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_VF_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_CONST_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_STATE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_MEDIA_STATE_CLEAR;
flags |= PIPE_CONTROL_QW_WRITE;
flags |= PIPE_CONTROL_GLOBAL_GTT_IVB;
flags |= PIPE_CONTROL_STALL_AT_SCOREBOARD;
gen7_render_ring_cs_stall_wa(req);
}
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(engine, flags);
intel_ring_emit(engine, scratch_addr);
intel_ring_emit(engine, 0);
intel_ring_advance(engine);
return 0;
}
static int
gen8_emit_pipe_control(struct drm_i915_gem_request *req,
u32 flags, u32 scratch_addr)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(engine, flags);
intel_ring_emit(engine, scratch_addr);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
intel_ring_advance(engine);
return 0;
}
static int
gen8_render_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate_domains, u32 flush_domains)
{
u32 flags = 0;
u32 scratch_addr = req->engine->scratch.gtt_offset + 2 * CACHELINE_BYTES;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_DC_FLUSH_ENABLE;
flags |= PIPE_CONTROL_FLUSH_ENABLE;
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
ret = gen8_emit_pipe_control(req,
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_STALL_AT_SCOREBOARD,
0);
if (ret)
return ret;
}
return gen8_emit_pipe_control(req, flags, scratch_addr);
}
static void ring_write_tail(struct intel_engine_cs *engine,
u32 value)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_TAIL(engine, value);
}
u64 intel_ring_get_active_head(struct intel_engine_cs *engine)
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
static void ring_setup_phys_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
u32 addr;
addr = dev_priv->status_page_dmah->busaddr;
if (INTEL_GEN(dev_priv) >= 4)
addr |= (dev_priv->status_page_dmah->busaddr >> 28) & 0xf0;
I915_WRITE(HWS_PGA, addr);
}
static void intel_ring_setup_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
i915_reg_t mmio;
if (IS_GEN7(dev_priv)) {
switch (engine->id) {
case RCS:
mmio = RENDER_HWS_PGA_GEN7;
break;
case BCS:
mmio = BLT_HWS_PGA_GEN7;
break;
case VCS2:
case VCS:
mmio = BSD_HWS_PGA_GEN7;
break;
case VECS:
mmio = VEBOX_HWS_PGA_GEN7;
break;
}
} else if (IS_GEN6(dev_priv)) {
mmio = RING_HWS_PGA_GEN6(engine->mmio_base);
} else {
mmio = RING_HWS_PGA(engine->mmio_base);
}
I915_WRITE(mmio, (u32)engine->status_page.gfx_addr);
POSTING_READ(mmio);
if (IS_GEN(dev_priv, 6, 7)) {
i915_reg_t reg = RING_INSTPM(engine->mmio_base);
WARN_ON((I915_READ_MODE(engine) & MODE_IDLE) == 0);
I915_WRITE(reg,
_MASKED_BIT_ENABLE(INSTPM_TLB_INVALIDATE |
INSTPM_SYNC_FLUSH));
if (intel_wait_for_register(dev_priv,
reg, INSTPM_SYNC_FLUSH, 0,
1000))
DRM_ERROR("%s: wait for SyncFlush to complete for TLB invalidation timed out\n",
engine->name);
}
}
static bool stop_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
if (!IS_GEN2(dev_priv)) {
I915_WRITE_MODE(engine, _MASKED_BIT_ENABLE(STOP_RING));
if (intel_wait_for_register(dev_priv,
RING_MI_MODE(engine->mmio_base),
MODE_IDLE,
MODE_IDLE,
1000)) {
DRM_ERROR("%s : timed out trying to stop ring\n",
engine->name);
if (I915_READ_HEAD(engine) != I915_READ_TAIL(engine))
return false;
}
}
I915_WRITE_CTL(engine, 0);
I915_WRITE_HEAD(engine, 0);
engine->write_tail(engine, 0);
if (!IS_GEN2(dev_priv)) {
(void)I915_READ_CTL(engine);
I915_WRITE_MODE(engine, _MASKED_BIT_DISABLE(STOP_RING));
}
return (I915_READ_HEAD(engine) & HEAD_ADDR) == 0;
}
void intel_engine_init_hangcheck(struct intel_engine_cs *engine)
{
memset(&engine->hangcheck, 0, sizeof(engine->hangcheck));
}
static int init_ring_common(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct intel_ringbuffer *ringbuf = engine->buffer;
struct drm_i915_gem_object *obj = ringbuf->obj;
int ret = 0;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
if (!stop_ring(engine)) {
DRM_DEBUG_KMS("%s head not reset to zero "
"ctl %08x head %08x tail %08x start %08x\n",
engine->name,
I915_READ_CTL(engine),
I915_READ_HEAD(engine),
I915_READ_TAIL(engine),
I915_READ_START(engine));
if (!stop_ring(engine)) {
DRM_ERROR("failed to set %s head to zero "
"ctl %08x head %08x tail %08x start %08x\n",
engine->name,
I915_READ_CTL(engine),
I915_READ_HEAD(engine),
I915_READ_TAIL(engine),
I915_READ_START(engine));
ret = -EIO;
goto out;
}
}
if (I915_NEED_GFX_HWS(dev_priv))
intel_ring_setup_status_page(engine);
else
ring_setup_phys_status_page(engine);
I915_READ_HEAD(engine);
I915_WRITE_START(engine, i915_gem_obj_ggtt_offset(obj));
if (I915_READ_HEAD(engine))
DRM_DEBUG("%s initialization failed [head=%08x], fudging\n",
engine->name, I915_READ_HEAD(engine));
I915_WRITE_HEAD(engine, 0);
(void)I915_READ_HEAD(engine);
I915_WRITE_CTL(engine,
((ringbuf->size - PAGE_SIZE) & RING_NR_PAGES)
| RING_VALID);
if (wait_for((I915_READ_CTL(engine) & RING_VALID) != 0 &&
I915_READ_START(engine) == i915_gem_obj_ggtt_offset(obj) &&
(I915_READ_HEAD(engine) & HEAD_ADDR) == 0, 50)) {
DRM_ERROR("%s initialization failed "
"ctl %08x (valid? %d) head %08x tail %08x start %08x [expected %08lx]\n",
engine->name,
I915_READ_CTL(engine),
I915_READ_CTL(engine) & RING_VALID,
I915_READ_HEAD(engine), I915_READ_TAIL(engine),
I915_READ_START(engine),
(unsigned long)i915_gem_obj_ggtt_offset(obj));
ret = -EIO;
goto out;
}
ringbuf->last_retired_head = -1;
ringbuf->head = I915_READ_HEAD(engine);
ringbuf->tail = I915_READ_TAIL(engine) & TAIL_ADDR;
intel_ring_update_space(ringbuf);
intel_engine_init_hangcheck(engine);
out:
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
return ret;
}
void intel_fini_pipe_control(struct intel_engine_cs *engine)
{
if (engine->scratch.obj == NULL)
return;
i915_gem_object_ggtt_unpin(engine->scratch.obj);
drm_gem_object_unreference(&engine->scratch.obj->base);
engine->scratch.obj = NULL;
}
int intel_init_pipe_control(struct intel_engine_cs *engine, int size)
{
struct drm_i915_gem_object *obj;
int ret;
WARN_ON(engine->scratch.obj);
obj = i915_gem_object_create_stolen(&engine->i915->drm, size);
if (!obj)
obj = i915_gem_object_create(&engine->i915->drm, size);
if (IS_ERR(obj)) {
DRM_ERROR("Failed to allocate scratch page\n");
ret = PTR_ERR(obj);
goto err;
}
ret = i915_gem_obj_ggtt_pin(obj, 4096, PIN_HIGH);
if (ret)
goto err_unref;
engine->scratch.obj = obj;
engine->scratch.gtt_offset = i915_gem_obj_ggtt_offset(obj);
DRM_DEBUG_DRIVER("%s pipe control offset: 0x%08x\n",
engine->name, engine->scratch.gtt_offset);
return 0;
err_unref:
drm_gem_object_unreference(&engine->scratch.obj->base);
err:
return ret;
}
static int intel_ring_workarounds_emit(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
struct i915_workarounds *w = &req->i915->workarounds;
int ret, i;
if (w->count == 0)
return 0;
engine->gpu_caches_dirty = true;
ret = intel_ring_flush_all_caches(req);
if (ret)
return ret;
ret = intel_ring_begin(req, (w->count * 2 + 2));
if (ret)
return ret;
intel_ring_emit(engine, MI_LOAD_REGISTER_IMM(w->count));
for (i = 0; i < w->count; i++) {
intel_ring_emit_reg(engine, w->reg[i].addr);
intel_ring_emit(engine, w->reg[i].value);
}
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
engine->gpu_caches_dirty = true;
ret = intel_ring_flush_all_caches(req);
if (ret)
return ret;
DRM_DEBUG_DRIVER("Number of Workarounds emitted: %d\n", w->count);
return 0;
}
static int intel_rcs_ctx_init(struct drm_i915_gem_request *req)
{
int ret;
ret = intel_ring_workarounds_emit(req);
if (ret != 0)
return ret;
ret = i915_gem_render_state_init(req);
if (ret)
return ret;
return 0;
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
I915_WRITE(GAM_ECOCHK, I915_READ(GAM_ECOCHK) |
ECOCHK_DIS_TLB);
WA_SET_BIT_MASKED(GEN8_ROW_CHICKEN,
FLOW_CONTROL_ENABLE |
PARTIAL_INSTRUCTION_SHOOTDOWN_DISABLE);
WA_SET_BIT_MASKED(HALF_SLICE_CHICKEN3,
GEN9_DISABLE_OCL_OOB_SUPPRESS_LOGIC);
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_B0) ||
IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
WA_CLR_BIT_MASKED(GEN9_HALF_SLICE_CHICKEN5,
GEN9_DG_MIRROR_FIX_ENABLE);
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_B0) ||
IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) {
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
if (IS_SKL_REVID(dev_priv, SKL_REVID_C0, SKL_REVID_C0) ||
IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
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
if (!is_power_of_2(dev_priv->info.subslice_7eu[i]))
continue;
ss = ffs(dev_priv->info.subslice_7eu[i]) - 1;
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
if (IS_SKL_REVID(dev_priv, SKL_REVID_E0, REVID_FOREVER)) {
I915_WRITE(GEN7_FF_SLICE_CS_CHICKEN1,
_MASKED_BIT_ENABLE(GEN9_FFSC_PERCTX_PREEMPT_CTRL));
}
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_E0)) {
I915_WRITE(FF_SLICE_CS_CHICKEN2,
_MASKED_BIT_ENABLE(GEN9_TSG_BARRIER_ACK_DISABLE));
}
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_E0))
I915_WRITE(GEN8_L3SQCREG4, I915_READ(GEN8_L3SQCREG4) |
GEN8_LQSC_RO_PERF_DIS);
if (IS_SKL_REVID(dev_priv, SKL_REVID_C0, REVID_FOREVER)) {
I915_WRITE(GEN8_GARBCNTL, (I915_READ(GEN8_GARBCNTL) |
GEN9_GAPS_TSV_CREDIT_DISABLE));
}
if (IS_SKL_REVID(dev_priv, SKL_REVID_B0, SKL_REVID_B0))
WA_SET_BIT_MASKED(HIZ_CHICKEN,
BDW_HIZ_POWER_COMPILER_CLOCK_GATING_DISABLE);
if (IS_SKL_REVID(dev_priv, SKL_REVID_C0, SKL_REVID_D0))
WA_SET_BIT_MASKED(HDC_CHICKEN0,
HDC_FENCE_DEST_SLM_DISABLE |
HDC_BARRIER_PERFORMANCE_DISABLE);
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_F0))
WA_SET_BIT_MASKED(
GEN7_HALF_SLICE_CHICKEN1,
GEN7_SBE_SS_CACHE_DISPATCH_PORT_SHARING_DISABLE);
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
if (IS_KBL_REVID(dev_priv, 0, KBL_REVID_E0))
I915_WRITE(GEN8_L3SQCREG4, I915_READ(GEN8_L3SQCREG4) |
GEN8_LQSC_RO_PERF_DIS);
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
int init_workarounds_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
WARN_ON(engine->id != RCS);
dev_priv->workarounds.count = 0;
dev_priv->workarounds.hw_whitelist_count[RCS] = 0;
if (IS_BROADWELL(dev_priv))
return bdw_init_workarounds(engine);
if (IS_CHERRYVIEW(dev_priv))
return chv_init_workarounds(engine);
if (IS_SKYLAKE(dev_priv))
return skl_init_workarounds(engine);
if (IS_BROXTON(dev_priv))
return bxt_init_workarounds(engine);
if (IS_KABYLAKE(dev_priv))
return kbl_init_workarounds(engine);
return 0;
}
static int init_render_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret = init_ring_common(engine);
if (ret)
return ret;
if (IS_GEN(dev_priv, 4, 6))
I915_WRITE(MI_MODE, _MASKED_BIT_ENABLE(VS_TIMER_DISPATCH));
if (IS_GEN(dev_priv, 6, 7))
I915_WRITE(MI_MODE, _MASKED_BIT_ENABLE(ASYNC_FLIP_PERF_DISABLE));
if (IS_GEN6(dev_priv))
I915_WRITE(GFX_MODE,
_MASKED_BIT_ENABLE(GFX_TLB_INVALIDATE_EXPLICIT));
if (IS_GEN7(dev_priv))
I915_WRITE(GFX_MODE_GEN7,
_MASKED_BIT_ENABLE(GFX_TLB_INVALIDATE_EXPLICIT) |
_MASKED_BIT_ENABLE(GFX_REPLAY_MODE));
if (IS_GEN6(dev_priv)) {
I915_WRITE(CACHE_MODE_0,
_MASKED_BIT_DISABLE(CM0_STC_EVICT_DISABLE_LRA_SNB));
}
if (IS_GEN(dev_priv, 6, 7))
I915_WRITE(INSTPM, _MASKED_BIT_ENABLE(INSTPM_FORCE_ORDERING));
if (INTEL_INFO(dev_priv)->gen >= 6)
I915_WRITE_IMR(engine, ~engine->irq_keep_mask);
return init_workarounds_ring(engine);
}
static void render_ring_cleanup(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
if (dev_priv->semaphore_obj) {
i915_gem_object_ggtt_unpin(dev_priv->semaphore_obj);
drm_gem_object_unreference(&dev_priv->semaphore_obj->base);
dev_priv->semaphore_obj = NULL;
}
intel_fini_pipe_control(engine);
}
static int gen8_rcs_signal(struct drm_i915_gem_request *signaller_req,
unsigned int num_dwords)
{
#define MBOX_UPDATE_DWORDS 8
struct intel_engine_cs *signaller = signaller_req->engine;
struct drm_i915_private *dev_priv = signaller_req->i915;
struct intel_engine_cs *waiter;
enum intel_engine_id id;
int ret, num_rings;
num_rings = hweight32(INTEL_INFO(dev_priv)->ring_mask);
num_dwords += (num_rings-1) * MBOX_UPDATE_DWORDS;
#undef MBOX_UPDATE_DWORDS
ret = intel_ring_begin(signaller_req, num_dwords);
if (ret)
return ret;
for_each_engine_id(waiter, dev_priv, id) {
u64 gtt_offset = signaller->semaphore.signal_ggtt[id];
if (gtt_offset == MI_SEMAPHORE_SYNC_INVALID)
continue;
intel_ring_emit(signaller, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(signaller, PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_QW_WRITE |
PIPE_CONTROL_CS_STALL);
intel_ring_emit(signaller, lower_32_bits(gtt_offset));
intel_ring_emit(signaller, upper_32_bits(gtt_offset));
intel_ring_emit(signaller, signaller_req->seqno);
intel_ring_emit(signaller, 0);
intel_ring_emit(signaller, MI_SEMAPHORE_SIGNAL |
MI_SEMAPHORE_TARGET(waiter->hw_id));
intel_ring_emit(signaller, 0);
}
return 0;
}
static int gen8_xcs_signal(struct drm_i915_gem_request *signaller_req,
unsigned int num_dwords)
{
#define MBOX_UPDATE_DWORDS 6
struct intel_engine_cs *signaller = signaller_req->engine;
struct drm_i915_private *dev_priv = signaller_req->i915;
struct intel_engine_cs *waiter;
enum intel_engine_id id;
int ret, num_rings;
num_rings = hweight32(INTEL_INFO(dev_priv)->ring_mask);
num_dwords += (num_rings-1) * MBOX_UPDATE_DWORDS;
#undef MBOX_UPDATE_DWORDS
ret = intel_ring_begin(signaller_req, num_dwords);
if (ret)
return ret;
for_each_engine_id(waiter, dev_priv, id) {
u64 gtt_offset = signaller->semaphore.signal_ggtt[id];
if (gtt_offset == MI_SEMAPHORE_SYNC_INVALID)
continue;
intel_ring_emit(signaller, (MI_FLUSH_DW + 1) |
MI_FLUSH_DW_OP_STOREDW);
intel_ring_emit(signaller, lower_32_bits(gtt_offset) |
MI_FLUSH_DW_USE_GTT);
intel_ring_emit(signaller, upper_32_bits(gtt_offset));
intel_ring_emit(signaller, signaller_req->seqno);
intel_ring_emit(signaller, MI_SEMAPHORE_SIGNAL |
MI_SEMAPHORE_TARGET(waiter->hw_id));
intel_ring_emit(signaller, 0);
}
return 0;
}
static int gen6_signal(struct drm_i915_gem_request *signaller_req,
unsigned int num_dwords)
{
struct intel_engine_cs *signaller = signaller_req->engine;
struct drm_i915_private *dev_priv = signaller_req->i915;
struct intel_engine_cs *useless;
enum intel_engine_id id;
int ret, num_rings;
#define MBOX_UPDATE_DWORDS 3
num_rings = hweight32(INTEL_INFO(dev_priv)->ring_mask);
num_dwords += round_up((num_rings-1) * MBOX_UPDATE_DWORDS, 2);
#undef MBOX_UPDATE_DWORDS
ret = intel_ring_begin(signaller_req, num_dwords);
if (ret)
return ret;
for_each_engine_id(useless, dev_priv, id) {
i915_reg_t mbox_reg = signaller->semaphore.mbox.signal[id];
if (i915_mmio_reg_valid(mbox_reg)) {
intel_ring_emit(signaller, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit_reg(signaller, mbox_reg);
intel_ring_emit(signaller, signaller_req->seqno);
}
}
if (num_rings % 2 == 0)
intel_ring_emit(signaller, MI_NOOP);
return 0;
}
static int
gen6_add_request(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
if (engine->semaphore.signal)
ret = engine->semaphore.signal(req, 4);
else
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(engine, MI_STORE_DWORD_INDEX);
intel_ring_emit(engine,
I915_GEM_HWS_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
intel_ring_emit(engine, req->seqno);
intel_ring_emit(engine, MI_USER_INTERRUPT);
__intel_ring_advance(engine);
return 0;
}
static int
gen8_render_add_request(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
if (engine->semaphore.signal)
ret = engine->semaphore.signal(req, 8);
else
ret = intel_ring_begin(req, 8);
if (ret)
return ret;
intel_ring_emit(engine, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(engine, (PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE));
intel_ring_emit(engine, intel_hws_seqno_address(req->engine));
intel_ring_emit(engine, 0);
intel_ring_emit(engine, i915_gem_request_get_seqno(req));
intel_ring_emit(engine, 0);
intel_ring_emit(engine, MI_USER_INTERRUPT);
intel_ring_emit(engine, MI_NOOP);
__intel_ring_advance(engine);
return 0;
}
static inline bool i915_gem_has_seqno_wrapped(struct drm_i915_private *dev_priv,
u32 seqno)
{
return dev_priv->last_seqno < seqno;
}
static int
gen8_ring_sync(struct drm_i915_gem_request *waiter_req,
struct intel_engine_cs *signaller,
u32 seqno)
{
struct intel_engine_cs *waiter = waiter_req->engine;
struct drm_i915_private *dev_priv = waiter_req->i915;
u64 offset = GEN8_WAIT_OFFSET(waiter, signaller->id);
struct i915_hw_ppgtt *ppgtt;
int ret;
ret = intel_ring_begin(waiter_req, 4);
if (ret)
return ret;
intel_ring_emit(waiter, MI_SEMAPHORE_WAIT |
MI_SEMAPHORE_GLOBAL_GTT |
MI_SEMAPHORE_SAD_GTE_SDD);
intel_ring_emit(waiter, seqno);
intel_ring_emit(waiter, lower_32_bits(offset));
intel_ring_emit(waiter, upper_32_bits(offset));
intel_ring_advance(waiter);
ppgtt = waiter_req->ctx->ppgtt;
if (ppgtt && waiter_req->engine->id != RCS)
ppgtt->pd_dirty_rings |= intel_engine_flag(waiter_req->engine);
return 0;
}
static int
gen6_ring_sync(struct drm_i915_gem_request *waiter_req,
struct intel_engine_cs *signaller,
u32 seqno)
{
struct intel_engine_cs *waiter = waiter_req->engine;
u32 dw1 = MI_SEMAPHORE_MBOX |
MI_SEMAPHORE_COMPARE |
MI_SEMAPHORE_REGISTER;
u32 wait_mbox = signaller->semaphore.mbox.wait[waiter->id];
int ret;
seqno -= 1;
WARN_ON(wait_mbox == MI_SEMAPHORE_SYNC_INVALID);
ret = intel_ring_begin(waiter_req, 4);
if (ret)
return ret;
if (likely(!i915_gem_has_seqno_wrapped(waiter_req->i915, seqno))) {
intel_ring_emit(waiter, dw1 | wait_mbox);
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
static void
gen5_seqno_barrier(struct intel_engine_cs *ring)
{
usleep_range(125, 250);
}
static void
gen6_seqno_barrier(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
spin_lock_irq(&dev_priv->uncore.lock);
POSTING_READ_FW(RING_ACTHD(engine->mmio_base));
spin_unlock_irq(&dev_priv->uncore.lock);
}
static void
gen5_irq_enable(struct intel_engine_cs *engine)
{
gen5_enable_gt_irq(engine->i915, engine->irq_enable_mask);
}
static void
gen5_irq_disable(struct intel_engine_cs *engine)
{
gen5_disable_gt_irq(engine->i915, engine->irq_enable_mask);
}
static void
i9xx_irq_enable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->irq_mask &= ~engine->irq_enable_mask;
I915_WRITE(IMR, dev_priv->irq_mask);
POSTING_READ_FW(RING_IMR(engine->mmio_base));
}
static void
i9xx_irq_disable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->irq_mask |= engine->irq_enable_mask;
I915_WRITE(IMR, dev_priv->irq_mask);
}
static void
i8xx_irq_enable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->irq_mask &= ~engine->irq_enable_mask;
I915_WRITE16(IMR, dev_priv->irq_mask);
POSTING_READ16(RING_IMR(engine->mmio_base));
}
static void
i8xx_irq_disable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->irq_mask |= engine->irq_enable_mask;
I915_WRITE16(IMR, dev_priv->irq_mask);
}
static int
bsd_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate_domains,
u32 flush_domains)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine, MI_FLUSH);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
return 0;
}
static int
i9xx_add_request(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(engine, MI_STORE_DWORD_INDEX);
intel_ring_emit(engine,
I915_GEM_HWS_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
intel_ring_emit(engine, req->seqno);
intel_ring_emit(engine, MI_USER_INTERRUPT);
__intel_ring_advance(engine);
return 0;
}
static void
gen6_irq_enable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine,
~(engine->irq_enable_mask |
engine->irq_keep_mask));
gen5_enable_gt_irq(dev_priv, engine->irq_enable_mask);
}
static void
gen6_irq_disable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine, ~engine->irq_keep_mask);
gen5_disable_gt_irq(dev_priv, engine->irq_enable_mask);
}
static void
hsw_vebox_irq_enable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine, ~engine->irq_enable_mask);
gen6_enable_pm_irq(dev_priv, engine->irq_enable_mask);
}
static void
hsw_vebox_irq_disable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine, ~0);
gen6_disable_pm_irq(dev_priv, engine->irq_enable_mask);
}
static void
gen8_irq_enable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine,
~(engine->irq_enable_mask |
engine->irq_keep_mask));
POSTING_READ_FW(RING_IMR(engine->mmio_base));
}
static void
gen8_irq_disable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine, ~engine->irq_keep_mask);
}
static int
i965_dispatch_execbuffer(struct drm_i915_gem_request *req,
u64 offset, u32 length,
unsigned dispatch_flags)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine,
MI_BATCH_BUFFER_START |
MI_BATCH_GTT |
(dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE_I965));
intel_ring_emit(engine, offset);
intel_ring_advance(engine);
return 0;
}
static int
i830_dispatch_execbuffer(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned dispatch_flags)
{
struct intel_engine_cs *engine = req->engine;
u32 cs_offset = engine->scratch.gtt_offset;
int ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(engine, COLOR_BLT_CMD | BLT_WRITE_RGBA);
intel_ring_emit(engine, BLT_DEPTH_32 | BLT_ROP_COLOR_COPY | 4096);
intel_ring_emit(engine, I830_TLB_ENTRIES << 16 | 4);
intel_ring_emit(engine, cs_offset);
intel_ring_emit(engine, 0xdeadbeef);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
if ((dispatch_flags & I915_DISPATCH_PINNED) == 0) {
if (len > I830_BATCH_LIMIT)
return -ENOSPC;
ret = intel_ring_begin(req, 6 + 2);
if (ret)
return ret;
intel_ring_emit(engine, SRC_COPY_BLT_CMD | BLT_WRITE_RGBA);
intel_ring_emit(engine,
BLT_DEPTH_32 | BLT_ROP_SRC_COPY | 4096);
intel_ring_emit(engine, DIV_ROUND_UP(len, 4096) << 16 | 4096);
intel_ring_emit(engine, cs_offset);
intel_ring_emit(engine, 4096);
intel_ring_emit(engine, offset);
intel_ring_emit(engine, MI_FLUSH);
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
offset = cs_offset;
}
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine, MI_BATCH_BUFFER_START | MI_BATCH_GTT);
intel_ring_emit(engine, offset | (dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE));
intel_ring_advance(engine);
return 0;
}
static int
i915_dispatch_execbuffer(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned dispatch_flags)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine, MI_BATCH_BUFFER_START | MI_BATCH_GTT);
intel_ring_emit(engine, offset | (dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE));
intel_ring_advance(engine);
return 0;
}
static void cleanup_phys_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
if (!dev_priv->status_page_dmah)
return;
drm_pci_free(&dev_priv->drm, dev_priv->status_page_dmah);
engine->status_page.page_addr = NULL;
}
static void cleanup_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *obj;
obj = engine->status_page.obj;
if (obj == NULL)
return;
kunmap(sg_page(obj->pages->sgl));
i915_gem_object_ggtt_unpin(obj);
drm_gem_object_unreference(&obj->base);
engine->status_page.obj = NULL;
}
static int init_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *obj = engine->status_page.obj;
if (obj == NULL) {
unsigned flags;
int ret;
obj = i915_gem_object_create(&engine->i915->drm, 4096);
if (IS_ERR(obj)) {
DRM_ERROR("Failed to allocate status page\n");
return PTR_ERR(obj);
}
ret = i915_gem_object_set_cache_level(obj, I915_CACHE_LLC);
if (ret)
goto err_unref;
flags = 0;
if (!HAS_LLC(engine->i915))
flags |= PIN_MAPPABLE;
ret = i915_gem_obj_ggtt_pin(obj, 4096, flags);
if (ret) {
err_unref:
drm_gem_object_unreference(&obj->base);
return ret;
}
engine->status_page.obj = obj;
}
engine->status_page.gfx_addr = i915_gem_obj_ggtt_offset(obj);
engine->status_page.page_addr = kmap(sg_page(obj->pages->sgl));
memset(engine->status_page.page_addr, 0, PAGE_SIZE);
DRM_DEBUG_DRIVER("%s hws offset: 0x%08x\n",
engine->name, engine->status_page.gfx_addr);
return 0;
}
static int init_phys_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
if (!dev_priv->status_page_dmah) {
dev_priv->status_page_dmah =
drm_pci_alloc(&dev_priv->drm, PAGE_SIZE, PAGE_SIZE);
if (!dev_priv->status_page_dmah)
return -ENOMEM;
}
engine->status_page.page_addr = dev_priv->status_page_dmah->vaddr;
memset(engine->status_page.page_addr, 0, PAGE_SIZE);
return 0;
}
void intel_unpin_ringbuffer_obj(struct intel_ringbuffer *ringbuf)
{
GEM_BUG_ON(ringbuf->vma == NULL);
GEM_BUG_ON(ringbuf->virtual_start == NULL);
if (HAS_LLC(ringbuf->obj->base.dev) && !ringbuf->obj->stolen)
i915_gem_object_unpin_map(ringbuf->obj);
else
i915_vma_unpin_iomap(ringbuf->vma);
ringbuf->virtual_start = NULL;
i915_gem_object_ggtt_unpin(ringbuf->obj);
ringbuf->vma = NULL;
}
int intel_pin_and_map_ringbuffer_obj(struct drm_i915_private *dev_priv,
struct intel_ringbuffer *ringbuf)
{
struct drm_i915_gem_object *obj = ringbuf->obj;
unsigned flags = PIN_OFFSET_BIAS | 4096;
void *addr;
int ret;
if (HAS_LLC(dev_priv) && !obj->stolen) {
ret = i915_gem_obj_ggtt_pin(obj, PAGE_SIZE, flags);
if (ret)
return ret;
ret = i915_gem_object_set_to_cpu_domain(obj, true);
if (ret)
goto err_unpin;
addr = i915_gem_object_pin_map(obj);
if (IS_ERR(addr)) {
ret = PTR_ERR(addr);
goto err_unpin;
}
} else {
ret = i915_gem_obj_ggtt_pin(obj, PAGE_SIZE,
flags | PIN_MAPPABLE);
if (ret)
return ret;
ret = i915_gem_object_set_to_gtt_domain(obj, true);
if (ret)
goto err_unpin;
assert_rpm_wakelock_held(dev_priv);
addr = i915_vma_pin_iomap(i915_gem_obj_to_ggtt(obj));
if (IS_ERR(addr)) {
ret = PTR_ERR(addr);
goto err_unpin;
}
}
ringbuf->virtual_start = addr;
ringbuf->vma = i915_gem_obj_to_ggtt(obj);
return 0;
err_unpin:
i915_gem_object_ggtt_unpin(obj);
return ret;
}
static void intel_destroy_ringbuffer_obj(struct intel_ringbuffer *ringbuf)
{
drm_gem_object_unreference(&ringbuf->obj->base);
ringbuf->obj = NULL;
}
static int intel_alloc_ringbuffer_obj(struct drm_device *dev,
struct intel_ringbuffer *ringbuf)
{
struct drm_i915_gem_object *obj;
obj = NULL;
if (!HAS_LLC(dev))
obj = i915_gem_object_create_stolen(dev, ringbuf->size);
if (obj == NULL)
obj = i915_gem_object_create(dev, ringbuf->size);
if (IS_ERR(obj))
return PTR_ERR(obj);
obj->gt_ro = 1;
ringbuf->obj = obj;
return 0;
}
struct intel_ringbuffer *
intel_engine_create_ringbuffer(struct intel_engine_cs *engine, int size)
{
struct intel_ringbuffer *ring;
int ret;
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (ring == NULL) {
DRM_DEBUG_DRIVER("Failed to allocate ringbuffer %s\n",
engine->name);
return ERR_PTR(-ENOMEM);
}
ring->engine = engine;
list_add(&ring->link, &engine->buffers);
ring->size = size;
ring->effective_size = size;
if (IS_I830(engine->i915) || IS_845G(engine->i915))
ring->effective_size -= 2 * CACHELINE_BYTES;
ring->last_retired_head = -1;
intel_ring_update_space(ring);
ret = intel_alloc_ringbuffer_obj(&engine->i915->drm, ring);
if (ret) {
DRM_DEBUG_DRIVER("Failed to allocate ringbuffer %s: %d\n",
engine->name, ret);
list_del(&ring->link);
kfree(ring);
return ERR_PTR(ret);
}
return ring;
}
void
intel_ringbuffer_free(struct intel_ringbuffer *ring)
{
intel_destroy_ringbuffer_obj(ring);
list_del(&ring->link);
kfree(ring);
}
static int intel_ring_context_pin(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct intel_context *ce = &ctx->engine[engine->id];
int ret;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
if (ce->pin_count++)
return 0;
if (ce->state) {
ret = i915_gem_obj_ggtt_pin(ce->state, ctx->ggtt_alignment, 0);
if (ret)
goto error;
}
if (ctx == ctx->i915->kernel_context)
ce->initialised = true;
i915_gem_context_reference(ctx);
return 0;
error:
ce->pin_count = 0;
return ret;
}
static void intel_ring_context_unpin(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct intel_context *ce = &ctx->engine[engine->id];
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
if (--ce->pin_count)
return;
if (ce->state)
i915_gem_object_ggtt_unpin(ce->state);
i915_gem_context_unreference(ctx);
}
static int intel_init_ring_buffer(struct drm_device *dev,
struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_ringbuffer *ringbuf;
int ret;
WARN_ON(engine->buffer);
engine->i915 = dev_priv;
INIT_LIST_HEAD(&engine->active_list);
INIT_LIST_HEAD(&engine->request_list);
INIT_LIST_HEAD(&engine->execlist_queue);
INIT_LIST_HEAD(&engine->buffers);
i915_gem_batch_pool_init(dev, &engine->batch_pool);
memset(engine->semaphore.sync_seqno, 0,
sizeof(engine->semaphore.sync_seqno));
ret = intel_engine_init_breadcrumbs(engine);
if (ret)
goto error;
ret = intel_ring_context_pin(dev_priv->kernel_context, engine);
if (ret)
goto error;
ringbuf = intel_engine_create_ringbuffer(engine, 32 * PAGE_SIZE);
if (IS_ERR(ringbuf)) {
ret = PTR_ERR(ringbuf);
goto error;
}
engine->buffer = ringbuf;
if (I915_NEED_GFX_HWS(dev_priv)) {
ret = init_status_page(engine);
if (ret)
goto error;
} else {
WARN_ON(engine->id != RCS);
ret = init_phys_status_page(engine);
if (ret)
goto error;
}
ret = intel_pin_and_map_ringbuffer_obj(dev_priv, ringbuf);
if (ret) {
DRM_ERROR("Failed to pin and map ringbuffer %s: %d\n",
engine->name, ret);
intel_destroy_ringbuffer_obj(ringbuf);
goto error;
}
ret = i915_cmd_parser_init_ring(engine);
if (ret)
goto error;
return 0;
error:
intel_cleanup_engine(engine);
return ret;
}
void intel_cleanup_engine(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv;
if (!intel_engine_initialized(engine))
return;
dev_priv = engine->i915;
if (engine->buffer) {
intel_stop_engine(engine);
WARN_ON(!IS_GEN2(dev_priv) && (I915_READ_MODE(engine) & MODE_IDLE) == 0);
intel_unpin_ringbuffer_obj(engine->buffer);
intel_ringbuffer_free(engine->buffer);
engine->buffer = NULL;
}
if (engine->cleanup)
engine->cleanup(engine);
if (I915_NEED_GFX_HWS(dev_priv)) {
cleanup_status_page(engine);
} else {
WARN_ON(engine->id != RCS);
cleanup_phys_status_page(engine);
}
i915_cmd_parser_fini_ring(engine);
i915_gem_batch_pool_fini(&engine->batch_pool);
intel_engine_fini_breadcrumbs(engine);
intel_ring_context_unpin(dev_priv->kernel_context, engine);
engine->i915 = NULL;
}
int intel_engine_idle(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *req;
if (list_empty(&engine->request_list))
return 0;
req = list_entry(engine->request_list.prev,
struct drm_i915_gem_request,
list);
return __i915_wait_request(req,
req->i915->mm.interruptible,
NULL, NULL);
}
int intel_ring_alloc_request_extras(struct drm_i915_gem_request *request)
{
int ret;
request->reserved_space += LEGACY_REQUEST_SIZE;
request->ringbuf = request->engine->buffer;
ret = intel_ring_begin(request, 0);
if (ret)
return ret;
request->reserved_space -= LEGACY_REQUEST_SIZE;
return 0;
}
static int wait_for_space(struct drm_i915_gem_request *req, int bytes)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
struct intel_engine_cs *engine = req->engine;
struct drm_i915_gem_request *target;
intel_ring_update_space(ringbuf);
if (ringbuf->space >= bytes)
return 0;
GEM_BUG_ON(!req->reserved_space);
list_for_each_entry(target, &engine->request_list, list) {
unsigned space;
if (target->ringbuf != ringbuf)
continue;
space = __intel_ring_space(target->postfix, ringbuf->tail,
ringbuf->size);
if (space >= bytes)
break;
}
if (WARN_ON(&target->list == &engine->request_list))
return -ENOSPC;
return i915_wait_request(target);
}
int intel_ring_begin(struct drm_i915_gem_request *req, int num_dwords)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
int remain_actual = ringbuf->size - ringbuf->tail;
int remain_usable = ringbuf->effective_size - ringbuf->tail;
int bytes = num_dwords * sizeof(u32);
int total_bytes, wait_bytes;
bool need_wrap = false;
total_bytes = bytes + req->reserved_space;
if (unlikely(bytes > remain_usable)) {
wait_bytes = remain_actual + total_bytes;
need_wrap = true;
} else if (unlikely(total_bytes > remain_usable)) {
wait_bytes = remain_actual + req->reserved_space;
} else {
wait_bytes = total_bytes;
}
if (wait_bytes > ringbuf->space) {
int ret = wait_for_space(req, wait_bytes);
if (unlikely(ret))
return ret;
intel_ring_update_space(ringbuf);
if (unlikely(ringbuf->space < wait_bytes))
return -EAGAIN;
}
if (unlikely(need_wrap)) {
GEM_BUG_ON(remain_actual > ringbuf->space);
GEM_BUG_ON(ringbuf->tail + remain_actual > ringbuf->size);
memset(ringbuf->virtual_start + ringbuf->tail,
0, remain_actual);
ringbuf->tail = 0;
ringbuf->space -= remain_actual;
}
ringbuf->space -= bytes;
GEM_BUG_ON(ringbuf->space < 0);
return 0;
}
int intel_ring_cacheline_align(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int num_dwords = (engine->buffer->tail & (CACHELINE_BYTES - 1)) / sizeof(uint32_t);
int ret;
if (num_dwords == 0)
return 0;
num_dwords = CACHELINE_BYTES / sizeof(uint32_t) - num_dwords;
ret = intel_ring_begin(req, num_dwords);
if (ret)
return ret;
while (num_dwords--)
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
return 0;
}
void intel_ring_init_seqno(struct intel_engine_cs *engine, u32 seqno)
{
struct drm_i915_private *dev_priv = engine->i915;
if (IS_GEN6(dev_priv) || IS_GEN7(dev_priv)) {
I915_WRITE(RING_SYNC_0(engine->mmio_base), 0);
I915_WRITE(RING_SYNC_1(engine->mmio_base), 0);
if (HAS_VEBOX(dev_priv))
I915_WRITE(RING_SYNC_2(engine->mmio_base), 0);
}
if (dev_priv->semaphore_obj) {
struct drm_i915_gem_object *obj = dev_priv->semaphore_obj;
struct page *page = i915_gem_object_get_dirty_page(obj, 0);
void *semaphores = kmap(page);
memset(semaphores + GEN8_SEMAPHORE_OFFSET(engine->id, 0),
0, I915_NUM_ENGINES * gen8_semaphore_seqno_size);
kunmap(page);
}
memset(engine->semaphore.sync_seqno, 0,
sizeof(engine->semaphore.sync_seqno));
intel_write_status_page(engine, I915_GEM_HWS_INDEX, seqno);
if (engine->irq_seqno_barrier)
engine->irq_seqno_barrier(engine);
engine->last_submitted_seqno = seqno;
engine->hangcheck.seqno = seqno;
rcu_read_lock();
intel_engine_wakeup(engine);
rcu_read_unlock();
}
static void gen6_bsd_ring_write_tail(struct intel_engine_cs *engine,
u32 value)
{
struct drm_i915_private *dev_priv = engine->i915;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
I915_WRITE_FW(GEN6_BSD_SLEEP_PSMI_CONTROL,
_MASKED_BIT_ENABLE(GEN6_BSD_SLEEP_MSG_DISABLE));
I915_WRITE64_FW(GEN6_BSD_RNCID, 0x0);
if (intel_wait_for_register_fw(dev_priv,
GEN6_BSD_SLEEP_PSMI_CONTROL,
GEN6_BSD_SLEEP_INDICATOR,
0,
50))
DRM_ERROR("timed out waiting for the BSD ring to wake up\n");
I915_WRITE_FW(RING_TAIL(engine->mmio_base), value);
POSTING_READ_FW(RING_TAIL(engine->mmio_base));
I915_WRITE_FW(GEN6_BSD_SLEEP_PSMI_CONTROL,
_MASKED_BIT_DISABLE(GEN6_BSD_SLEEP_MSG_DISABLE));
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
}
static int gen6_bsd_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate, u32 flush)
{
struct intel_engine_cs *engine = req->engine;
uint32_t cmd;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW;
if (INTEL_GEN(req->i915) >= 8)
cmd += 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (invalidate & I915_GEM_GPU_DOMAINS)
cmd |= MI_INVALIDATE_TLB | MI_INVALIDATE_BSD;
intel_ring_emit(engine, cmd);
intel_ring_emit(engine,
I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT);
if (INTEL_GEN(req->i915) >= 8) {
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
} else {
intel_ring_emit(engine, 0);
intel_ring_emit(engine, MI_NOOP);
}
intel_ring_advance(engine);
return 0;
}
static int
gen8_ring_dispatch_execbuffer(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned dispatch_flags)
{
struct intel_engine_cs *engine = req->engine;
bool ppgtt = USES_PPGTT(engine->dev) &&
!(dispatch_flags & I915_DISPATCH_SECURE);
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(engine, MI_BATCH_BUFFER_START_GEN8 | (ppgtt<<8) |
(dispatch_flags & I915_DISPATCH_RS ?
MI_BATCH_RESOURCE_STREAMER : 0));
intel_ring_emit(engine, lower_32_bits(offset));
intel_ring_emit(engine, upper_32_bits(offset));
intel_ring_emit(engine, MI_NOOP);
intel_ring_advance(engine);
return 0;
}
static int
hsw_ring_dispatch_execbuffer(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned dispatch_flags)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine,
MI_BATCH_BUFFER_START |
(dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_PPGTT_HSW | MI_BATCH_NON_SECURE_HSW) |
(dispatch_flags & I915_DISPATCH_RS ?
MI_BATCH_RESOURCE_STREAMER : 0));
intel_ring_emit(engine, offset);
intel_ring_advance(engine);
return 0;
}
static int
gen6_ring_dispatch_execbuffer(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned dispatch_flags)
{
struct intel_engine_cs *engine = req->engine;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(engine,
MI_BATCH_BUFFER_START |
(dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE_I965));
intel_ring_emit(engine, offset);
intel_ring_advance(engine);
return 0;
}
static int gen6_ring_flush(struct drm_i915_gem_request *req,
u32 invalidate, u32 flush)
{
struct intel_engine_cs *engine = req->engine;
uint32_t cmd;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW;
if (INTEL_GEN(req->i915) >= 8)
cmd += 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (invalidate & I915_GEM_DOMAIN_RENDER)
cmd |= MI_INVALIDATE_TLB;
intel_ring_emit(engine, cmd);
intel_ring_emit(engine,
I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT);
if (INTEL_GEN(req->i915) >= 8) {
intel_ring_emit(engine, 0);
intel_ring_emit(engine, 0);
} else {
intel_ring_emit(engine, 0);
intel_ring_emit(engine, MI_NOOP);
}
intel_ring_advance(engine);
return 0;
}
static void intel_ring_init_semaphores(struct drm_i915_private *dev_priv,
struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *obj;
int ret, i;
if (!i915_semaphore_is_enabled(dev_priv))
return;
if (INTEL_GEN(dev_priv) >= 8 && !dev_priv->semaphore_obj) {
obj = i915_gem_object_create(&dev_priv->drm, 4096);
if (IS_ERR(obj)) {
DRM_ERROR("Failed to allocate semaphore bo. Disabling semaphores\n");
i915.semaphores = 0;
} else {
i915_gem_object_set_cache_level(obj, I915_CACHE_LLC);
ret = i915_gem_obj_ggtt_pin(obj, 0, PIN_NONBLOCK);
if (ret != 0) {
drm_gem_object_unreference(&obj->base);
DRM_ERROR("Failed to pin semaphore bo. Disabling semaphores\n");
i915.semaphores = 0;
} else {
dev_priv->semaphore_obj = obj;
}
}
}
if (!i915_semaphore_is_enabled(dev_priv))
return;
if (INTEL_GEN(dev_priv) >= 8) {
u64 offset = i915_gem_obj_ggtt_offset(dev_priv->semaphore_obj);
engine->semaphore.sync_to = gen8_ring_sync;
engine->semaphore.signal = gen8_xcs_signal;
for (i = 0; i < I915_NUM_ENGINES; i++) {
u64 ring_offset;
if (i != engine->id)
ring_offset = offset + GEN8_SEMAPHORE_OFFSET(engine->id, i);
else
ring_offset = MI_SEMAPHORE_SYNC_INVALID;
engine->semaphore.signal_ggtt[i] = ring_offset;
}
} else if (INTEL_GEN(dev_priv) >= 6) {
engine->semaphore.sync_to = gen6_ring_sync;
engine->semaphore.signal = gen6_signal;
for (i = 0; i < I915_NUM_ENGINES; i++) {
static const struct {
u32 wait_mbox;
i915_reg_t mbox_reg;
} sem_data[I915_NUM_ENGINES][I915_NUM_ENGINES] = {
[RCS] = {
[VCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_RV, .mbox_reg = GEN6_VRSYNC },
[BCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_RB, .mbox_reg = GEN6_BRSYNC },
[VECS] = { .wait_mbox = MI_SEMAPHORE_SYNC_RVE, .mbox_reg = GEN6_VERSYNC },
},
[VCS] = {
[RCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_VR, .mbox_reg = GEN6_RVSYNC },
[BCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_VB, .mbox_reg = GEN6_BVSYNC },
[VECS] = { .wait_mbox = MI_SEMAPHORE_SYNC_VVE, .mbox_reg = GEN6_VEVSYNC },
},
[BCS] = {
[RCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_BR, .mbox_reg = GEN6_RBSYNC },
[VCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_BV, .mbox_reg = GEN6_VBSYNC },
[VECS] = { .wait_mbox = MI_SEMAPHORE_SYNC_BVE, .mbox_reg = GEN6_VEBSYNC },
},
[VECS] = {
[RCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_VER, .mbox_reg = GEN6_RVESYNC },
[VCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_VEV, .mbox_reg = GEN6_VVESYNC },
[BCS] = { .wait_mbox = MI_SEMAPHORE_SYNC_VEB, .mbox_reg = GEN6_BVESYNC },
},
};
u32 wait_mbox;
i915_reg_t mbox_reg;
if (i == engine->id || i == VCS2) {
wait_mbox = MI_SEMAPHORE_SYNC_INVALID;
mbox_reg = GEN6_NOSYNC;
} else {
wait_mbox = sem_data[engine->id][i].wait_mbox;
mbox_reg = sem_data[engine->id][i].mbox_reg;
}
engine->semaphore.mbox.wait[i] = wait_mbox;
engine->semaphore.mbox.signal[i] = mbox_reg;
}
}
}
static void intel_ring_init_irq(struct drm_i915_private *dev_priv,
struct intel_engine_cs *engine)
{
if (INTEL_GEN(dev_priv) >= 8) {
engine->irq_enable = gen8_irq_enable;
engine->irq_disable = gen8_irq_disable;
engine->irq_seqno_barrier = gen6_seqno_barrier;
} else if (INTEL_GEN(dev_priv) >= 6) {
engine->irq_enable = gen6_irq_enable;
engine->irq_disable = gen6_irq_disable;
engine->irq_seqno_barrier = gen6_seqno_barrier;
} else if (INTEL_GEN(dev_priv) >= 5) {
engine->irq_enable = gen5_irq_enable;
engine->irq_disable = gen5_irq_disable;
engine->irq_seqno_barrier = gen5_seqno_barrier;
} else if (INTEL_GEN(dev_priv) >= 3) {
engine->irq_enable = i9xx_irq_enable;
engine->irq_disable = i9xx_irq_disable;
} else {
engine->irq_enable = i8xx_irq_enable;
engine->irq_disable = i8xx_irq_disable;
}
}
static void intel_ring_default_vfuncs(struct drm_i915_private *dev_priv,
struct intel_engine_cs *engine)
{
engine->init_hw = init_ring_common;
engine->write_tail = ring_write_tail;
engine->add_request = i9xx_add_request;
if (INTEL_GEN(dev_priv) >= 6)
engine->add_request = gen6_add_request;
if (INTEL_GEN(dev_priv) >= 8)
engine->dispatch_execbuffer = gen8_ring_dispatch_execbuffer;
else if (INTEL_GEN(dev_priv) >= 6)
engine->dispatch_execbuffer = gen6_ring_dispatch_execbuffer;
else if (INTEL_GEN(dev_priv) >= 4)
engine->dispatch_execbuffer = i965_dispatch_execbuffer;
else if (IS_I830(dev_priv) || IS_845G(dev_priv))
engine->dispatch_execbuffer = i830_dispatch_execbuffer;
else
engine->dispatch_execbuffer = i915_dispatch_execbuffer;
intel_ring_init_irq(dev_priv, engine);
intel_ring_init_semaphores(dev_priv, engine);
}
int intel_init_render_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine = &dev_priv->engine[RCS];
int ret;
engine->name = "render ring";
engine->id = RCS;
engine->exec_id = I915_EXEC_RENDER;
engine->hw_id = 0;
engine->mmio_base = RENDER_RING_BASE;
intel_ring_default_vfuncs(dev_priv, engine);
engine->irq_enable_mask = GT_RENDER_USER_INTERRUPT;
if (HAS_L3_DPF(dev_priv))
engine->irq_keep_mask = GT_RENDER_L3_PARITY_ERROR_INTERRUPT;
if (INTEL_GEN(dev_priv) >= 8) {
engine->init_context = intel_rcs_ctx_init;
engine->add_request = gen8_render_add_request;
engine->flush = gen8_render_ring_flush;
if (i915_semaphore_is_enabled(dev_priv))
engine->semaphore.signal = gen8_rcs_signal;
} else if (INTEL_GEN(dev_priv) >= 6) {
engine->init_context = intel_rcs_ctx_init;
engine->flush = gen7_render_ring_flush;
if (IS_GEN6(dev_priv))
engine->flush = gen6_render_ring_flush;
} else if (IS_GEN5(dev_priv)) {
engine->flush = gen4_render_ring_flush;
} else {
if (INTEL_GEN(dev_priv) < 4)
engine->flush = gen2_render_ring_flush;
else
engine->flush = gen4_render_ring_flush;
engine->irq_enable_mask = I915_USER_INTERRUPT;
}
if (IS_HASWELL(dev_priv))
engine->dispatch_execbuffer = hsw_ring_dispatch_execbuffer;
engine->init_hw = init_render_ring;
engine->cleanup = render_ring_cleanup;
ret = intel_init_ring_buffer(dev, engine);
if (ret)
return ret;
if (INTEL_GEN(dev_priv) >= 6) {
ret = intel_init_pipe_control(engine, 4096);
if (ret)
return ret;
} else if (HAS_BROKEN_CS_TLB(dev_priv)) {
ret = intel_init_pipe_control(engine, I830_WA_SIZE);
if (ret)
return ret;
}
return 0;
}
int intel_init_bsd_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine = &dev_priv->engine[VCS];
engine->name = "bsd ring";
engine->id = VCS;
engine->exec_id = I915_EXEC_BSD;
engine->hw_id = 1;
intel_ring_default_vfuncs(dev_priv, engine);
if (INTEL_GEN(dev_priv) >= 6) {
engine->mmio_base = GEN6_BSD_RING_BASE;
if (IS_GEN6(dev_priv))
engine->write_tail = gen6_bsd_ring_write_tail;
engine->flush = gen6_bsd_ring_flush;
if (INTEL_GEN(dev_priv) >= 8)
engine->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VCS1_IRQ_SHIFT;
else
engine->irq_enable_mask = GT_BSD_USER_INTERRUPT;
} else {
engine->mmio_base = BSD_RING_BASE;
engine->flush = bsd_ring_flush;
if (IS_GEN5(dev_priv))
engine->irq_enable_mask = ILK_BSD_USER_INTERRUPT;
else
engine->irq_enable_mask = I915_BSD_USER_INTERRUPT;
}
return intel_init_ring_buffer(dev, engine);
}
int intel_init_bsd2_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine = &dev_priv->engine[VCS2];
engine->name = "bsd2 ring";
engine->id = VCS2;
engine->exec_id = I915_EXEC_BSD;
engine->hw_id = 4;
engine->mmio_base = GEN8_BSD2_RING_BASE;
intel_ring_default_vfuncs(dev_priv, engine);
engine->flush = gen6_bsd_ring_flush;
engine->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VCS2_IRQ_SHIFT;
return intel_init_ring_buffer(dev, engine);
}
int intel_init_blt_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine = &dev_priv->engine[BCS];
engine->name = "blitter ring";
engine->id = BCS;
engine->exec_id = I915_EXEC_BLT;
engine->hw_id = 2;
engine->mmio_base = BLT_RING_BASE;
intel_ring_default_vfuncs(dev_priv, engine);
engine->flush = gen6_ring_flush;
if (INTEL_GEN(dev_priv) >= 8)
engine->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_BCS_IRQ_SHIFT;
else
engine->irq_enable_mask = GT_BLT_USER_INTERRUPT;
return intel_init_ring_buffer(dev, engine);
}
int intel_init_vebox_ring_buffer(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_engine_cs *engine = &dev_priv->engine[VECS];
engine->name = "video enhancement ring";
engine->id = VECS;
engine->exec_id = I915_EXEC_VEBOX;
engine->hw_id = 3;
engine->mmio_base = VEBOX_RING_BASE;
intel_ring_default_vfuncs(dev_priv, engine);
engine->flush = gen6_ring_flush;
if (INTEL_GEN(dev_priv) >= 8) {
engine->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VECS_IRQ_SHIFT;
} else {
engine->irq_enable_mask = PM_VEBOX_USER_INTERRUPT;
engine->irq_enable = hsw_vebox_irq_enable;
engine->irq_disable = hsw_vebox_irq_disable;
}
return intel_init_ring_buffer(dev, engine);
}
int
intel_ring_flush_all_caches(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
if (!engine->gpu_caches_dirty)
return 0;
ret = engine->flush(req, 0, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
trace_i915_gem_ring_flush(req, 0, I915_GEM_GPU_DOMAINS);
engine->gpu_caches_dirty = false;
return 0;
}
int
intel_ring_invalidate_all_caches(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
uint32_t flush_domains;
int ret;
flush_domains = 0;
if (engine->gpu_caches_dirty)
flush_domains = I915_GEM_GPU_DOMAINS;
ret = engine->flush(req, I915_GEM_GPU_DOMAINS, flush_domains);
if (ret)
return ret;
trace_i915_gem_ring_flush(req, I915_GEM_GPU_DOMAINS, flush_domains);
engine->gpu_caches_dirty = false;
return 0;
}
void
intel_stop_engine(struct intel_engine_cs *engine)
{
int ret;
if (!intel_engine_initialized(engine))
return;
ret = intel_engine_idle(engine);
if (ret)
DRM_ERROR("failed to quiesce %s whilst cleaning up: %d\n",
engine->name, ret);
stop_ring(engine);
}
