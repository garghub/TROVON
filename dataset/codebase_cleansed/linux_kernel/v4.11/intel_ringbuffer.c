int __intel_ring_space(int head, int tail, int size)
{
int space = head - tail;
if (space <= 0)
space += size;
return space - I915_RING_FREE_SPACE;
}
void intel_ring_update_space(struct intel_ring *ring)
{
if (ring->last_retired_head != -1) {
ring->head = ring->last_retired_head;
ring->last_retired_head = -1;
}
ring->space = __intel_ring_space(ring->head & HEAD_ADDR,
ring->tail, ring->size);
}
static int
gen2_render_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
u32 cmd;
int ret;
cmd = MI_FLUSH;
if (mode & EMIT_INVALIDATE)
cmd |= MI_READ_FLUSH;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
gen4_render_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
u32 cmd;
int ret;
cmd = MI_FLUSH;
if (mode & EMIT_INVALIDATE) {
cmd |= MI_EXE_FLUSH;
if (IS_G4X(req->i915) || IS_GEN5(req->i915))
cmd |= MI_INVALIDATE_ISP;
}
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
intel_emit_post_sync_nonzero_flush(struct drm_i915_gem_request *req)
{
struct intel_ring *ring = req->ring;
u32 scratch_addr =
i915_ggtt_offset(req->engine->scratch) + 2 * CACHELINE_BYTES;
int ret;
ret = intel_ring_begin(req, 6);
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
ret = intel_ring_begin(req, 6);
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
gen6_render_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
u32 scratch_addr =
i915_ggtt_offset(req->engine->scratch) + 2 * CACHELINE_BYTES;
u32 flags = 0;
int ret;
ret = intel_emit_post_sync_nonzero_flush(req);
if (ret)
return ret;
if (mode & EMIT_FLUSH) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_CS_STALL;
}
if (mode & EMIT_INVALIDATE) {
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
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(ring, flags);
intel_ring_emit(ring, scratch_addr | PIPE_CONTROL_GLOBAL_GTT);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static int
gen7_render_ring_cs_stall_wa(struct drm_i915_gem_request *req)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(ring,
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_STALL_AT_SCOREBOARD);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static int
gen7_render_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
u32 scratch_addr =
i915_ggtt_offset(req->engine->scratch) + 2 * CACHELINE_BYTES;
u32 flags = 0;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (mode & EMIT_FLUSH) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_DC_FLUSH_ENABLE;
flags |= PIPE_CONTROL_FLUSH_ENABLE;
}
if (mode & EMIT_INVALIDATE) {
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
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(4));
intel_ring_emit(ring, flags);
intel_ring_emit(ring, scratch_addr);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static int
gen8_emit_pipe_control(struct drm_i915_gem_request *req,
u32 flags, u32 scratch_addr)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 6);
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
static int
gen8_render_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
u32 scratch_addr =
i915_ggtt_offset(req->engine->scratch) + 2 * CACHELINE_BYTES;
u32 flags = 0;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (mode & EMIT_FLUSH) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_DC_FLUSH_ENABLE;
flags |= PIPE_CONTROL_FLUSH_ENABLE;
}
if (mode & EMIT_INVALIDATE) {
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
I915_WRITE(mmio, engine->status_page.ggtt_offset);
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
if (INTEL_GEN(dev_priv) > 2) {
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
I915_WRITE_TAIL(engine, 0);
if (INTEL_GEN(dev_priv) > 2) {
(void)I915_READ_CTL(engine);
I915_WRITE_MODE(engine, _MASKED_BIT_DISABLE(STOP_RING));
}
return (I915_READ_HEAD(engine) & HEAD_ADDR) == 0;
}
static int init_ring_common(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct intel_ring *ring = engine->buffer;
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
if (HWS_NEEDS_PHYSICAL(dev_priv))
ring_setup_phys_status_page(engine);
else
intel_ring_setup_status_page(engine);
intel_engine_reset_breadcrumbs(engine);
I915_READ_HEAD(engine);
I915_WRITE_START(engine, i915_ggtt_offset(ring->vma));
if (I915_READ_HEAD(engine))
DRM_DEBUG("%s initialization failed [head=%08x], fudging\n",
engine->name, I915_READ_HEAD(engine));
intel_ring_update_space(ring);
I915_WRITE_HEAD(engine, ring->head);
I915_WRITE_TAIL(engine, ring->tail);
(void)I915_READ_TAIL(engine);
I915_WRITE_CTL(engine, RING_CTL_SIZE(ring->size) | RING_VALID);
if (intel_wait_for_register_fw(dev_priv, RING_CTL(engine->mmio_base),
RING_VALID, RING_VALID,
50)) {
DRM_ERROR("%s initialization failed "
"ctl %08x (valid? %d) head %08x [%08x] tail %08x [%08x] start %08x [expected %08x]\n",
engine->name,
I915_READ_CTL(engine),
I915_READ_CTL(engine) & RING_VALID,
I915_READ_HEAD(engine), ring->head,
I915_READ_TAIL(engine), ring->tail,
I915_READ_START(engine),
i915_ggtt_offset(ring->vma));
ret = -EIO;
goto out;
}
intel_engine_init_hangcheck(engine);
out:
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
return ret;
}
static void reset_ring_common(struct intel_engine_cs *engine,
struct drm_i915_gem_request *request)
{
if (request) {
struct drm_i915_private *dev_priv = request->i915;
struct intel_context *ce = &request->ctx->engine[engine->id];
struct i915_hw_ppgtt *ppgtt;
if (ce->state) {
I915_WRITE(CCID,
i915_ggtt_offset(ce->state) |
BIT(8) |
CCID_EXTENDED_STATE_SAVE |
CCID_EXTENDED_STATE_RESTORE |
CCID_EN);
}
ppgtt = request->ctx->ppgtt ?: engine->i915->mm.aliasing_ppgtt;
if (ppgtt) {
u32 pd_offset = ppgtt->pd.base.ggtt_offset << 10;
I915_WRITE(RING_PP_DIR_DCLV(engine), PP_DIR_DCLV_2G);
I915_WRITE(RING_PP_DIR_BASE(engine), pd_offset);
if (intel_wait_for_register(dev_priv,
RING_PP_DIR_BASE(engine),
BIT(0), 0,
10))
DRM_ERROR("Wait for reload of ppgtt page-directory timed out\n");
ppgtt->pd_dirty_rings &= ~intel_engine_flag(engine);
}
if (request->fence.error == -EIO) {
struct intel_ring *ring = request->ring;
ring->head = request->postfix;
ring->last_retired_head = -1;
}
} else {
engine->legacy_active_context = NULL;
}
}
static int intel_ring_workarounds_emit(struct drm_i915_gem_request *req)
{
struct intel_ring *ring = req->ring;
struct i915_workarounds *w = &req->i915->workarounds;
int ret, i;
if (w->count == 0)
return 0;
ret = req->engine->emit_flush(req, EMIT_BARRIER);
if (ret)
return ret;
ret = intel_ring_begin(req, (w->count * 2 + 2));
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(w->count));
for (i = 0; i < w->count; i++) {
intel_ring_emit_reg(ring, w->reg[i].addr);
intel_ring_emit(ring, w->reg[i].value);
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
ret = req->engine->emit_flush(req, EMIT_BARRIER);
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
ret = i915_gem_render_state_emit(req);
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
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
WA_CLR_BIT_MASKED(GEN9_HALF_SLICE_CHICKEN5,
GEN9_DG_MIRROR_FIX_ENABLE);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) {
WA_SET_BIT_MASKED(GEN7_COMMON_SLICE_CHICKEN1,
GEN9_RHWO_OPTIMIZATION_DISABLE);
}
WA_SET_BIT_MASKED(GEN9_HALF_SLICE_CHICKEN7,
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
i915_vma_unpin_and_release(&dev_priv->semaphore);
}
static u32 *gen8_rcs_signal(struct drm_i915_gem_request *req, u32 *out)
{
struct drm_i915_private *dev_priv = req->i915;
struct intel_engine_cs *waiter;
enum intel_engine_id id;
for_each_engine(waiter, dev_priv, id) {
u64 gtt_offset = req->engine->semaphore.signal_ggtt[id];
if (gtt_offset == MI_SEMAPHORE_SYNC_INVALID)
continue;
*out++ = GFX_OP_PIPE_CONTROL(6);
*out++ = (PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_QW_WRITE |
PIPE_CONTROL_CS_STALL);
*out++ = lower_32_bits(gtt_offset);
*out++ = upper_32_bits(gtt_offset);
*out++ = req->global_seqno;
*out++ = 0;
*out++ = (MI_SEMAPHORE_SIGNAL |
MI_SEMAPHORE_TARGET(waiter->hw_id));
*out++ = 0;
}
return out;
}
static u32 *gen8_xcs_signal(struct drm_i915_gem_request *req, u32 *out)
{
struct drm_i915_private *dev_priv = req->i915;
struct intel_engine_cs *waiter;
enum intel_engine_id id;
for_each_engine(waiter, dev_priv, id) {
u64 gtt_offset = req->engine->semaphore.signal_ggtt[id];
if (gtt_offset == MI_SEMAPHORE_SYNC_INVALID)
continue;
*out++ = (MI_FLUSH_DW + 1) | MI_FLUSH_DW_OP_STOREDW;
*out++ = lower_32_bits(gtt_offset) | MI_FLUSH_DW_USE_GTT;
*out++ = upper_32_bits(gtt_offset);
*out++ = req->global_seqno;
*out++ = (MI_SEMAPHORE_SIGNAL |
MI_SEMAPHORE_TARGET(waiter->hw_id));
*out++ = 0;
}
return out;
}
static u32 *gen6_signal(struct drm_i915_gem_request *req, u32 *out)
{
struct drm_i915_private *dev_priv = req->i915;
struct intel_engine_cs *engine;
enum intel_engine_id id;
int num_rings = 0;
for_each_engine(engine, dev_priv, id) {
i915_reg_t mbox_reg;
if (!(BIT(engine->hw_id) & GEN6_SEMAPHORES_MASK))
continue;
mbox_reg = req->engine->semaphore.mbox.signal[engine->hw_id];
if (i915_mmio_reg_valid(mbox_reg)) {
*out++ = MI_LOAD_REGISTER_IMM(1);
*out++ = i915_mmio_reg_offset(mbox_reg);
*out++ = req->global_seqno;
num_rings++;
}
}
if (num_rings & 1)
*out++ = MI_NOOP;
return out;
}
static void i9xx_submit_request(struct drm_i915_gem_request *request)
{
struct drm_i915_private *dev_priv = request->i915;
i915_gem_request_submit(request);
I915_WRITE_TAIL(request->engine, request->tail);
}
static void i9xx_emit_breadcrumb(struct drm_i915_gem_request *req,
u32 *out)
{
*out++ = MI_STORE_DWORD_INDEX;
*out++ = I915_GEM_HWS_INDEX << MI_STORE_DWORD_INDEX_SHIFT;
*out++ = req->global_seqno;
*out++ = MI_USER_INTERRUPT;
req->tail = intel_ring_offset(req->ring, out);
}
static void gen6_sema_emit_breadcrumb(struct drm_i915_gem_request *req,
u32 *out)
{
return i9xx_emit_breadcrumb(req,
req->engine->semaphore.signal(req, out));
}
static void gen8_render_emit_breadcrumb(struct drm_i915_gem_request *req,
u32 *out)
{
struct intel_engine_cs *engine = req->engine;
if (engine->semaphore.signal)
out = engine->semaphore.signal(req, out);
*out++ = GFX_OP_PIPE_CONTROL(6);
*out++ = (PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE);
*out++ = intel_hws_seqno_address(engine);
*out++ = 0;
*out++ = req->global_seqno;
*out++ = 0;
*out++ = MI_USER_INTERRUPT;
*out++ = MI_NOOP;
req->tail = intel_ring_offset(req->ring, out);
}
static int
gen8_ring_sync_to(struct drm_i915_gem_request *req,
struct drm_i915_gem_request *signal)
{
struct intel_ring *ring = req->ring;
struct drm_i915_private *dev_priv = req->i915;
u64 offset = GEN8_WAIT_OFFSET(req->engine, signal->engine->id);
struct i915_hw_ppgtt *ppgtt;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring,
MI_SEMAPHORE_WAIT |
MI_SEMAPHORE_GLOBAL_GTT |
MI_SEMAPHORE_SAD_GTE_SDD);
intel_ring_emit(ring, signal->global_seqno);
intel_ring_emit(ring, lower_32_bits(offset));
intel_ring_emit(ring, upper_32_bits(offset));
intel_ring_advance(ring);
ppgtt = req->ctx->ppgtt;
if (ppgtt && req->engine->id != RCS)
ppgtt->pd_dirty_rings |= intel_engine_flag(req->engine);
return 0;
}
static int
gen6_ring_sync_to(struct drm_i915_gem_request *req,
struct drm_i915_gem_request *signal)
{
struct intel_ring *ring = req->ring;
u32 dw1 = MI_SEMAPHORE_MBOX |
MI_SEMAPHORE_COMPARE |
MI_SEMAPHORE_REGISTER;
u32 wait_mbox = signal->engine->semaphore.mbox.wait[req->engine->hw_id];
int ret;
WARN_ON(wait_mbox == MI_SEMAPHORE_SYNC_INVALID);
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring, dw1 | wait_mbox);
intel_ring_emit(ring, signal->global_seqno - 1);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static void
gen5_seqno_barrier(struct intel_engine_cs *engine)
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
bsd_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_FLUSH);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
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
gen6_unmask_pm_irq(dev_priv, engine->irq_enable_mask);
}
static void
hsw_vebox_irq_disable(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine, ~0);
gen6_mask_pm_irq(dev_priv, engine->irq_enable_mask);
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
i965_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 length,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring,
MI_BATCH_BUFFER_START |
MI_BATCH_GTT |
(dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE_I965));
intel_ring_emit(ring, offset);
intel_ring_advance(ring);
return 0;
}
static int
i830_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
u32 cs_offset = i915_ggtt_offset(req->engine->scratch);
int ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(ring, COLOR_BLT_CMD | BLT_WRITE_RGBA);
intel_ring_emit(ring, BLT_DEPTH_32 | BLT_ROP_COLOR_COPY | 4096);
intel_ring_emit(ring, I830_TLB_ENTRIES << 16 | 4);
intel_ring_emit(ring, cs_offset);
intel_ring_emit(ring, 0xdeadbeef);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
if ((dispatch_flags & I915_DISPATCH_PINNED) == 0) {
if (len > I830_BATCH_LIMIT)
return -ENOSPC;
ret = intel_ring_begin(req, 6 + 2);
if (ret)
return ret;
intel_ring_emit(ring, SRC_COPY_BLT_CMD | BLT_WRITE_RGBA);
intel_ring_emit(ring,
BLT_DEPTH_32 | BLT_ROP_SRC_COPY | 4096);
intel_ring_emit(ring, DIV_ROUND_UP(len, 4096) << 16 | 4096);
intel_ring_emit(ring, cs_offset);
intel_ring_emit(ring, 4096);
intel_ring_emit(ring, offset);
intel_ring_emit(ring, MI_FLUSH);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
offset = cs_offset;
}
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER_START | MI_BATCH_GTT);
intel_ring_emit(ring, offset | (dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE));
intel_ring_advance(ring);
return 0;
}
static int
i915_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER_START | MI_BATCH_GTT);
intel_ring_emit(ring, offset | (dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE));
intel_ring_advance(ring);
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
struct i915_vma *vma;
struct drm_i915_gem_object *obj;
vma = fetch_and_zero(&engine->status_page.vma);
if (!vma)
return;
obj = vma->obj;
i915_vma_unpin(vma);
i915_vma_close(vma);
i915_gem_object_unpin_map(obj);
__i915_gem_object_release_unless_active(obj);
}
static int init_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
unsigned int flags;
void *vaddr;
int ret;
obj = i915_gem_object_create_internal(engine->i915, PAGE_SIZE);
if (IS_ERR(obj)) {
DRM_ERROR("Failed to allocate status page\n");
return PTR_ERR(obj);
}
ret = i915_gem_object_set_cache_level(obj, I915_CACHE_LLC);
if (ret)
goto err;
vma = i915_vma_instance(obj, &engine->i915->ggtt.base, NULL);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto err;
}
flags = PIN_GLOBAL;
if (!HAS_LLC(engine->i915))
flags |= PIN_MAPPABLE;
ret = i915_vma_pin(vma, 0, 4096, flags);
if (ret)
goto err;
vaddr = i915_gem_object_pin_map(obj, I915_MAP_WB);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
goto err_unpin;
}
engine->status_page.vma = vma;
engine->status_page.ggtt_offset = i915_ggtt_offset(vma);
engine->status_page.page_addr = memset(vaddr, 0, PAGE_SIZE);
DRM_DEBUG_DRIVER("%s hws offset: 0x%08x\n",
engine->name, i915_ggtt_offset(vma));
return 0;
err_unpin:
i915_vma_unpin(vma);
err:
i915_gem_object_put(obj);
return ret;
}
static int init_phys_status_page(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->status_page_dmah =
drm_pci_alloc(&dev_priv->drm, PAGE_SIZE, PAGE_SIZE);
if (!dev_priv->status_page_dmah)
return -ENOMEM;
engine->status_page.page_addr = dev_priv->status_page_dmah->vaddr;
memset(engine->status_page.page_addr, 0, PAGE_SIZE);
return 0;
}
int intel_ring_pin(struct intel_ring *ring, unsigned int offset_bias)
{
unsigned int flags;
enum i915_map_type map;
struct i915_vma *vma = ring->vma;
void *addr;
int ret;
GEM_BUG_ON(ring->vaddr);
map = HAS_LLC(ring->engine->i915) ? I915_MAP_WB : I915_MAP_WC;
flags = PIN_GLOBAL;
if (offset_bias)
flags |= PIN_OFFSET_BIAS | offset_bias;
if (vma->obj->stolen)
flags |= PIN_MAPPABLE;
if (!(vma->flags & I915_VMA_GLOBAL_BIND)) {
if (flags & PIN_MAPPABLE || map == I915_MAP_WC)
ret = i915_gem_object_set_to_gtt_domain(vma->obj, true);
else
ret = i915_gem_object_set_to_cpu_domain(vma->obj, true);
if (unlikely(ret))
return ret;
}
ret = i915_vma_pin(vma, 0, PAGE_SIZE, flags);
if (unlikely(ret))
return ret;
if (i915_vma_is_map_and_fenceable(vma))
addr = (void __force *)i915_vma_pin_iomap(vma);
else
addr = i915_gem_object_pin_map(vma->obj, map);
if (IS_ERR(addr))
goto err;
ring->vaddr = addr;
return 0;
err:
i915_vma_unpin(vma);
return PTR_ERR(addr);
}
void intel_ring_unpin(struct intel_ring *ring)
{
GEM_BUG_ON(!ring->vma);
GEM_BUG_ON(!ring->vaddr);
if (i915_vma_is_map_and_fenceable(ring->vma))
i915_vma_unpin_iomap(ring->vma);
else
i915_gem_object_unpin_map(ring->vma->obj);
ring->vaddr = NULL;
i915_vma_unpin(ring->vma);
}
static struct i915_vma *
intel_ring_create_vma(struct drm_i915_private *dev_priv, int size)
{
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
obj = i915_gem_object_create_stolen(dev_priv, size);
if (!obj)
obj = i915_gem_object_create(dev_priv, size);
if (IS_ERR(obj))
return ERR_CAST(obj);
obj->gt_ro = 1;
vma = i915_vma_instance(obj, &dev_priv->ggtt.base, NULL);
if (IS_ERR(vma))
goto err;
return vma;
err:
i915_gem_object_put(obj);
return vma;
}
struct intel_ring *
intel_engine_create_ring(struct intel_engine_cs *engine, int size)
{
struct intel_ring *ring;
struct i915_vma *vma;
GEM_BUG_ON(!is_power_of_2(size));
GEM_BUG_ON(RING_CTL_SIZE(size) & ~RING_NR_PAGES);
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring)
return ERR_PTR(-ENOMEM);
ring->engine = engine;
INIT_LIST_HEAD(&ring->request_list);
ring->size = size;
ring->effective_size = size;
if (IS_I830(engine->i915) || IS_I845G(engine->i915))
ring->effective_size -= 2 * CACHELINE_BYTES;
ring->last_retired_head = -1;
intel_ring_update_space(ring);
vma = intel_ring_create_vma(engine->i915, size);
if (IS_ERR(vma)) {
kfree(ring);
return ERR_CAST(vma);
}
ring->vma = vma;
return ring;
}
void
intel_ring_free(struct intel_ring *ring)
{
struct drm_i915_gem_object *obj = ring->vma->obj;
i915_vma_close(ring->vma);
__i915_gem_object_release_unless_active(obj);
kfree(ring);
}
static int context_pin(struct i915_gem_context *ctx, unsigned int flags)
{
struct i915_vma *vma = ctx->engine[RCS].state;
int ret;
if (!(vma->flags & I915_VMA_GLOBAL_BIND)) {
ret = i915_gem_object_set_to_gtt_domain(vma->obj, false);
if (ret)
return ret;
}
return i915_vma_pin(vma, 0, ctx->ggtt_alignment, PIN_GLOBAL | flags);
}
static int intel_ring_context_pin(struct intel_engine_cs *engine,
struct i915_gem_context *ctx)
{
struct intel_context *ce = &ctx->engine[engine->id];
int ret;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
if (ce->pin_count++)
return 0;
if (ce->state) {
unsigned int flags;
flags = 0;
if (i915_gem_context_is_kernel(ctx))
flags = PIN_HIGH;
ret = context_pin(ctx, flags);
if (ret)
goto error;
ce->state->obj->mm.dirty = true;
}
if (i915_gem_context_is_kernel(ctx))
ce->initialised = true;
i915_gem_context_get(ctx);
return 0;
error:
ce->pin_count = 0;
return ret;
}
static void intel_ring_context_unpin(struct intel_engine_cs *engine,
struct i915_gem_context *ctx)
{
struct intel_context *ce = &ctx->engine[engine->id];
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
GEM_BUG_ON(ce->pin_count == 0);
if (--ce->pin_count)
return;
if (ce->state)
i915_vma_unpin(ce->state);
i915_gem_context_put(ctx);
}
static int intel_init_ring_buffer(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct intel_ring *ring;
int ret;
WARN_ON(engine->buffer);
intel_engine_setup_common(engine);
ret = intel_engine_init_common(engine);
if (ret)
goto error;
ring = intel_engine_create_ring(engine, 32 * PAGE_SIZE);
if (IS_ERR(ring)) {
ret = PTR_ERR(ring);
goto error;
}
if (HWS_NEEDS_PHYSICAL(dev_priv)) {
WARN_ON(engine->id != RCS);
ret = init_phys_status_page(engine);
if (ret)
goto error;
} else {
ret = init_status_page(engine);
if (ret)
goto error;
}
ret = intel_ring_pin(ring, I915_GTT_PAGE_SIZE);
if (ret) {
intel_ring_free(ring);
goto error;
}
engine->buffer = ring;
return 0;
error:
intel_engine_cleanup(engine);
return ret;
}
void intel_engine_cleanup(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv;
dev_priv = engine->i915;
if (engine->buffer) {
WARN_ON(INTEL_GEN(dev_priv) > 2 &&
(I915_READ_MODE(engine) & MODE_IDLE) == 0);
intel_ring_unpin(engine->buffer);
intel_ring_free(engine->buffer);
engine->buffer = NULL;
}
if (engine->cleanup)
engine->cleanup(engine);
if (HWS_NEEDS_PHYSICAL(dev_priv)) {
WARN_ON(engine->id != RCS);
cleanup_phys_status_page(engine);
} else {
cleanup_status_page(engine);
}
intel_engine_cleanup_common(engine);
engine->i915 = NULL;
dev_priv->engine[engine->id] = NULL;
kfree(engine);
}
void intel_legacy_submission_resume(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
for_each_engine(engine, dev_priv, id) {
engine->buffer->head = engine->buffer->tail;
engine->buffer->last_retired_head = -1;
}
}
static int ring_request_alloc(struct drm_i915_gem_request *request)
{
int ret;
GEM_BUG_ON(!request->ctx->engine[request->engine->id].pin_count);
request->reserved_space += LEGACY_REQUEST_SIZE;
GEM_BUG_ON(!request->engine->buffer);
request->ring = request->engine->buffer;
ret = intel_ring_begin(request, 0);
if (ret)
return ret;
request->reserved_space -= LEGACY_REQUEST_SIZE;
return 0;
}
static int wait_for_space(struct drm_i915_gem_request *req, int bytes)
{
struct intel_ring *ring = req->ring;
struct drm_i915_gem_request *target;
long timeout;
lockdep_assert_held(&req->i915->drm.struct_mutex);
intel_ring_update_space(ring);
if (ring->space >= bytes)
return 0;
GEM_BUG_ON(!req->reserved_space);
list_for_each_entry(target, &ring->request_list, ring_link) {
unsigned space;
space = __intel_ring_space(target->postfix, ring->tail,
ring->size);
if (space >= bytes)
break;
}
if (WARN_ON(&target->ring_link == &ring->request_list))
return -ENOSPC;
timeout = i915_wait_request(target,
I915_WAIT_INTERRUPTIBLE | I915_WAIT_LOCKED,
MAX_SCHEDULE_TIMEOUT);
if (timeout < 0)
return timeout;
i915_gem_request_retire_upto(target);
intel_ring_update_space(ring);
GEM_BUG_ON(ring->space < bytes);
return 0;
}
int intel_ring_begin(struct drm_i915_gem_request *req, int num_dwords)
{
struct intel_ring *ring = req->ring;
int remain_actual = ring->size - ring->tail;
int remain_usable = ring->effective_size - ring->tail;
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
if (wait_bytes > ring->space) {
int ret = wait_for_space(req, wait_bytes);
if (unlikely(ret))
return ret;
}
if (unlikely(need_wrap)) {
GEM_BUG_ON(remain_actual > ring->space);
GEM_BUG_ON(ring->tail + remain_actual > ring->size);
memset(ring->vaddr + ring->tail, 0, remain_actual);
ring->tail = 0;
ring->space -= remain_actual;
}
ring->space -= bytes;
GEM_BUG_ON(ring->space < 0);
return 0;
}
int intel_ring_cacheline_align(struct drm_i915_gem_request *req)
{
struct intel_ring *ring = req->ring;
int num_dwords =
(ring->tail & (CACHELINE_BYTES - 1)) / sizeof(uint32_t);
int ret;
if (num_dwords == 0)
return 0;
num_dwords = CACHELINE_BYTES / sizeof(uint32_t) - num_dwords;
ret = intel_ring_begin(req, num_dwords);
if (ret)
return ret;
while (num_dwords--)
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static void gen6_bsd_submit_request(struct drm_i915_gem_request *request)
{
struct drm_i915_private *dev_priv = request->i915;
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
i9xx_submit_request(request);
I915_WRITE_FW(GEN6_BSD_SLEEP_PSMI_CONTROL,
_MASKED_BIT_DISABLE(GEN6_BSD_SLEEP_MSG_DISABLE));
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
}
static int gen6_bsd_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
uint32_t cmd;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW;
if (INTEL_GEN(req->i915) >= 8)
cmd += 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (mode & EMIT_INVALIDATE)
cmd |= MI_INVALIDATE_TLB | MI_INVALIDATE_BSD;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring, I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT);
if (INTEL_GEN(req->i915) >= 8) {
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
gen8_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
bool ppgtt = USES_PPGTT(req->i915) &&
!(dispatch_flags & I915_DISPATCH_SECURE);
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER_START_GEN8 | (ppgtt<<8) |
(dispatch_flags & I915_DISPATCH_RS ?
MI_BATCH_RESOURCE_STREAMER : 0));
intel_ring_emit(ring, lower_32_bits(offset));
intel_ring_emit(ring, upper_32_bits(offset));
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int
hsw_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring,
MI_BATCH_BUFFER_START |
(dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_PPGTT_HSW | MI_BATCH_NON_SECURE_HSW) |
(dispatch_flags & I915_DISPATCH_RS ?
MI_BATCH_RESOURCE_STREAMER : 0));
intel_ring_emit(ring, offset);
intel_ring_advance(ring);
return 0;
}
static int
gen6_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
int ret;
ret = intel_ring_begin(req, 2);
if (ret)
return ret;
intel_ring_emit(ring,
MI_BATCH_BUFFER_START |
(dispatch_flags & I915_DISPATCH_SECURE ?
0 : MI_BATCH_NON_SECURE_I965));
intel_ring_emit(ring, offset);
intel_ring_advance(ring);
return 0;
}
static int gen6_ring_flush(struct drm_i915_gem_request *req, u32 mode)
{
struct intel_ring *ring = req->ring;
uint32_t cmd;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW;
if (INTEL_GEN(req->i915) >= 8)
cmd += 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (mode & EMIT_INVALIDATE)
cmd |= MI_INVALIDATE_TLB;
intel_ring_emit(ring, cmd);
intel_ring_emit(ring,
I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT);
if (INTEL_GEN(req->i915) >= 8) {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
} else {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
}
intel_ring_advance(ring);
return 0;
}
static void intel_ring_init_semaphores(struct drm_i915_private *dev_priv,
struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *obj;
int ret, i;
if (!i915.semaphores)
return;
if (INTEL_GEN(dev_priv) >= 8 && !dev_priv->semaphore) {
struct i915_vma *vma;
obj = i915_gem_object_create(dev_priv, PAGE_SIZE);
if (IS_ERR(obj))
goto err;
vma = i915_vma_instance(obj, &dev_priv->ggtt.base, NULL);
if (IS_ERR(vma))
goto err_obj;
ret = i915_gem_object_set_to_gtt_domain(obj, false);
if (ret)
goto err_obj;
ret = i915_vma_pin(vma, 0, 0, PIN_GLOBAL | PIN_HIGH);
if (ret)
goto err_obj;
dev_priv->semaphore = vma;
}
if (INTEL_GEN(dev_priv) >= 8) {
u32 offset = i915_ggtt_offset(dev_priv->semaphore);
engine->semaphore.sync_to = gen8_ring_sync_to;
engine->semaphore.signal = gen8_xcs_signal;
for (i = 0; i < I915_NUM_ENGINES; i++) {
u32 ring_offset;
if (i != engine->id)
ring_offset = offset + GEN8_SEMAPHORE_OFFSET(engine->id, i);
else
ring_offset = MI_SEMAPHORE_SYNC_INVALID;
engine->semaphore.signal_ggtt[i] = ring_offset;
}
} else if (INTEL_GEN(dev_priv) >= 6) {
engine->semaphore.sync_to = gen6_ring_sync_to;
engine->semaphore.signal = gen6_signal;
for (i = 0; i < GEN6_NUM_SEMAPHORES; i++) {
static const struct {
u32 wait_mbox;
i915_reg_t mbox_reg;
} sem_data[GEN6_NUM_SEMAPHORES][GEN6_NUM_SEMAPHORES] = {
[RCS_HW] = {
[VCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_RV, .mbox_reg = GEN6_VRSYNC },
[BCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_RB, .mbox_reg = GEN6_BRSYNC },
[VECS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_RVE, .mbox_reg = GEN6_VERSYNC },
},
[VCS_HW] = {
[RCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_VR, .mbox_reg = GEN6_RVSYNC },
[BCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_VB, .mbox_reg = GEN6_BVSYNC },
[VECS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_VVE, .mbox_reg = GEN6_VEVSYNC },
},
[BCS_HW] = {
[RCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_BR, .mbox_reg = GEN6_RBSYNC },
[VCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_BV, .mbox_reg = GEN6_VBSYNC },
[VECS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_BVE, .mbox_reg = GEN6_VEBSYNC },
},
[VECS_HW] = {
[RCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_VER, .mbox_reg = GEN6_RVESYNC },
[VCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_VEV, .mbox_reg = GEN6_VVESYNC },
[BCS_HW] = { .wait_mbox = MI_SEMAPHORE_SYNC_VEB, .mbox_reg = GEN6_BVESYNC },
},
};
u32 wait_mbox;
i915_reg_t mbox_reg;
if (i == engine->hw_id) {
wait_mbox = MI_SEMAPHORE_SYNC_INVALID;
mbox_reg = GEN6_NOSYNC;
} else {
wait_mbox = sem_data[engine->hw_id][i].wait_mbox;
mbox_reg = sem_data[engine->hw_id][i].mbox_reg;
}
engine->semaphore.mbox.wait[i] = wait_mbox;
engine->semaphore.mbox.signal[i] = mbox_reg;
}
}
return;
err_obj:
i915_gem_object_put(obj);
err:
DRM_DEBUG_DRIVER("Failed to allocate space for semaphores, disabling\n");
i915.semaphores = 0;
}
static void intel_ring_init_irq(struct drm_i915_private *dev_priv,
struct intel_engine_cs *engine)
{
engine->irq_enable_mask = GT_RENDER_USER_INTERRUPT << engine->irq_shift;
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
intel_ring_init_irq(dev_priv, engine);
intel_ring_init_semaphores(dev_priv, engine);
engine->init_hw = init_ring_common;
engine->reset_hw = reset_ring_common;
engine->context_pin = intel_ring_context_pin;
engine->context_unpin = intel_ring_context_unpin;
engine->request_alloc = ring_request_alloc;
engine->emit_breadcrumb = i9xx_emit_breadcrumb;
engine->emit_breadcrumb_sz = i9xx_emit_breadcrumb_sz;
if (i915.semaphores) {
int num_rings;
engine->emit_breadcrumb = gen6_sema_emit_breadcrumb;
num_rings = hweight32(INTEL_INFO(dev_priv)->ring_mask) - 1;
if (INTEL_GEN(dev_priv) >= 8) {
engine->emit_breadcrumb_sz += num_rings * 6;
} else {
engine->emit_breadcrumb_sz += num_rings * 3;
if (num_rings & 1)
engine->emit_breadcrumb_sz++;
}
}
engine->submit_request = i9xx_submit_request;
if (INTEL_GEN(dev_priv) >= 8)
engine->emit_bb_start = gen8_emit_bb_start;
else if (INTEL_GEN(dev_priv) >= 6)
engine->emit_bb_start = gen6_emit_bb_start;
else if (INTEL_GEN(dev_priv) >= 4)
engine->emit_bb_start = i965_emit_bb_start;
else if (IS_I830(dev_priv) || IS_I845G(dev_priv))
engine->emit_bb_start = i830_emit_bb_start;
else
engine->emit_bb_start = i915_emit_bb_start;
}
int intel_init_render_ring_buffer(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
intel_ring_default_vfuncs(dev_priv, engine);
if (HAS_L3_DPF(dev_priv))
engine->irq_keep_mask = GT_RENDER_L3_PARITY_ERROR_INTERRUPT;
if (INTEL_GEN(dev_priv) >= 8) {
engine->init_context = intel_rcs_ctx_init;
engine->emit_breadcrumb = gen8_render_emit_breadcrumb;
engine->emit_breadcrumb_sz = gen8_render_emit_breadcrumb_sz;
engine->emit_flush = gen8_render_ring_flush;
if (i915.semaphores) {
int num_rings;
engine->semaphore.signal = gen8_rcs_signal;
num_rings =
hweight32(INTEL_INFO(dev_priv)->ring_mask) - 1;
engine->emit_breadcrumb_sz += num_rings * 6;
}
} else if (INTEL_GEN(dev_priv) >= 6) {
engine->init_context = intel_rcs_ctx_init;
engine->emit_flush = gen7_render_ring_flush;
if (IS_GEN6(dev_priv))
engine->emit_flush = gen6_render_ring_flush;
} else if (IS_GEN5(dev_priv)) {
engine->emit_flush = gen4_render_ring_flush;
} else {
if (INTEL_GEN(dev_priv) < 4)
engine->emit_flush = gen2_render_ring_flush;
else
engine->emit_flush = gen4_render_ring_flush;
engine->irq_enable_mask = I915_USER_INTERRUPT;
}
if (IS_HASWELL(dev_priv))
engine->emit_bb_start = hsw_emit_bb_start;
engine->init_hw = init_render_ring;
engine->cleanup = render_ring_cleanup;
ret = intel_init_ring_buffer(engine);
if (ret)
return ret;
if (INTEL_GEN(dev_priv) >= 6) {
ret = intel_engine_create_scratch(engine, PAGE_SIZE);
if (ret)
return ret;
} else if (HAS_BROKEN_CS_TLB(dev_priv)) {
ret = intel_engine_create_scratch(engine, I830_WA_SIZE);
if (ret)
return ret;
}
return 0;
}
int intel_init_bsd_ring_buffer(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
intel_ring_default_vfuncs(dev_priv, engine);
if (INTEL_GEN(dev_priv) >= 6) {
if (IS_GEN6(dev_priv))
engine->submit_request = gen6_bsd_submit_request;
engine->emit_flush = gen6_bsd_ring_flush;
if (INTEL_GEN(dev_priv) < 8)
engine->irq_enable_mask = GT_BSD_USER_INTERRUPT;
} else {
engine->mmio_base = BSD_RING_BASE;
engine->emit_flush = bsd_ring_flush;
if (IS_GEN5(dev_priv))
engine->irq_enable_mask = ILK_BSD_USER_INTERRUPT;
else
engine->irq_enable_mask = I915_BSD_USER_INTERRUPT;
}
return intel_init_ring_buffer(engine);
}
int intel_init_bsd2_ring_buffer(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
intel_ring_default_vfuncs(dev_priv, engine);
engine->emit_flush = gen6_bsd_ring_flush;
return intel_init_ring_buffer(engine);
}
int intel_init_blt_ring_buffer(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
intel_ring_default_vfuncs(dev_priv, engine);
engine->emit_flush = gen6_ring_flush;
if (INTEL_GEN(dev_priv) < 8)
engine->irq_enable_mask = GT_BLT_USER_INTERRUPT;
return intel_init_ring_buffer(engine);
}
int intel_init_vebox_ring_buffer(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
intel_ring_default_vfuncs(dev_priv, engine);
engine->emit_flush = gen6_ring_flush;
if (INTEL_GEN(dev_priv) < 8) {
engine->irq_enable_mask = PM_VEBOX_USER_INTERRUPT;
engine->irq_enable = hsw_vebox_irq_enable;
engine->irq_disable = hsw_vebox_irq_disable;
}
return intel_init_ring_buffer(engine);
}
