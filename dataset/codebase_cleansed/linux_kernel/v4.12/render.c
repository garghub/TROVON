static void handle_tlb_pending_event(struct intel_vgpu *vgpu, int ring_id)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
enum forcewake_domains fw;
i915_reg_t reg;
u32 regs[] = {
[RCS] = 0x4260,
[VCS] = 0x4264,
[VCS2] = 0x4268,
[BCS] = 0x426c,
[VECS] = 0x4270,
};
if (WARN_ON(ring_id >= ARRAY_SIZE(regs)))
return;
if (!test_and_clear_bit(ring_id, (void *)vgpu->tlb_handle_pending))
return;
reg = _MMIO(regs[ring_id]);
fw = intel_uncore_forcewake_for_reg(dev_priv, reg,
FW_REG_READ | FW_REG_WRITE);
if (ring_id == RCS && (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)))
fw |= FORCEWAKE_RENDER;
intel_uncore_forcewake_get(dev_priv, fw);
I915_WRITE_FW(reg, 0x1);
if (wait_for_atomic((I915_READ_FW(reg) == 0), 50))
gvt_vgpu_err("timeout in invalidate ring (%d) tlb\n", ring_id);
else
vgpu_vreg(vgpu, regs[ring_id]) = 0;
intel_uncore_forcewake_put(dev_priv, fw);
gvt_dbg_core("invalidate TLB for ring %d\n", ring_id);
}
static void load_mocs(struct intel_vgpu *vgpu, int ring_id)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
i915_reg_t offset, l3_offset;
u32 regs[] = {
[RCS] = 0xc800,
[VCS] = 0xc900,
[VCS2] = 0xca00,
[BCS] = 0xcc00,
[VECS] = 0xcb00,
};
int i;
if (WARN_ON(ring_id >= ARRAY_SIZE(regs)))
return;
offset.reg = regs[ring_id];
for (i = 0; i < 64; i++) {
gen9_render_mocs[ring_id][i] = I915_READ(offset);
I915_WRITE(offset, vgpu_vreg(vgpu, offset));
POSTING_READ(offset);
offset.reg += 4;
}
if (ring_id == RCS) {
l3_offset.reg = 0xb020;
for (i = 0; i < 32; i++) {
gen9_render_mocs_L3[i] = I915_READ(l3_offset);
I915_WRITE(l3_offset, vgpu_vreg(vgpu, l3_offset));
POSTING_READ(l3_offset);
l3_offset.reg += 4;
}
}
}
static void restore_mocs(struct intel_vgpu *vgpu, int ring_id)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
i915_reg_t offset, l3_offset;
u32 regs[] = {
[RCS] = 0xc800,
[VCS] = 0xc900,
[VCS2] = 0xca00,
[BCS] = 0xcc00,
[VECS] = 0xcb00,
};
int i;
if (WARN_ON(ring_id >= ARRAY_SIZE(regs)))
return;
offset.reg = regs[ring_id];
for (i = 0; i < 64; i++) {
vgpu_vreg(vgpu, offset) = I915_READ(offset);
I915_WRITE(offset, gen9_render_mocs[ring_id][i]);
POSTING_READ(offset);
offset.reg += 4;
}
if (ring_id == RCS) {
l3_offset.reg = 0xb020;
for (i = 0; i < 32; i++) {
vgpu_vreg(vgpu, l3_offset) = I915_READ(l3_offset);
I915_WRITE(l3_offset, gen9_render_mocs_L3[i]);
POSTING_READ(l3_offset);
l3_offset.reg += 4;
}
}
}
void intel_gvt_load_render_mmio(struct intel_vgpu *vgpu, int ring_id)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
struct render_mmio *mmio;
u32 v;
int i, array_size;
u32 *reg_state = vgpu->shadow_ctx->engine[ring_id].lrc_reg_state;
u32 ctx_ctrl = reg_state[CTX_CONTEXT_CONTROL_VAL];
u32 inhibit_mask =
_MASKED_BIT_ENABLE(CTX_CTRL_ENGINE_CTX_RESTORE_INHIBIT);
if (IS_SKYLAKE(vgpu->gvt->dev_priv)
|| IS_KABYLAKE(vgpu->gvt->dev_priv)) {
mmio = gen9_render_mmio_list;
array_size = ARRAY_SIZE(gen9_render_mmio_list);
load_mocs(vgpu, ring_id);
} else {
mmio = gen8_render_mmio_list;
array_size = ARRAY_SIZE(gen8_render_mmio_list);
}
for (i = 0; i < array_size; i++, mmio++) {
if (mmio->ring_id != ring_id)
continue;
mmio->value = I915_READ(mmio->reg);
if (mmio->in_context &&
((ctx_ctrl & inhibit_mask) != inhibit_mask) &&
i915.enable_execlists)
continue;
if (mmio->mask)
v = vgpu_vreg(vgpu, mmio->reg) | (mmio->mask << 16);
else
v = vgpu_vreg(vgpu, mmio->reg);
I915_WRITE(mmio->reg, v);
POSTING_READ(mmio->reg);
gvt_dbg_render("load reg %x old %x new %x\n",
i915_mmio_reg_offset(mmio->reg),
mmio->value, v);
}
handle_tlb_pending_event(vgpu, ring_id);
}
void intel_gvt_restore_render_mmio(struct intel_vgpu *vgpu, int ring_id)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
struct render_mmio *mmio;
u32 v;
int i, array_size;
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
mmio = gen9_render_mmio_list;
array_size = ARRAY_SIZE(gen9_render_mmio_list);
restore_mocs(vgpu, ring_id);
} else {
mmio = gen8_render_mmio_list;
array_size = ARRAY_SIZE(gen8_render_mmio_list);
}
for (i = 0; i < array_size; i++, mmio++) {
if (mmio->ring_id != ring_id)
continue;
vgpu_vreg(vgpu, mmio->reg) = I915_READ(mmio->reg);
if (mmio->mask) {
vgpu_vreg(vgpu, mmio->reg) &= ~(mmio->mask << 16);
v = mmio->value | (mmio->mask << 16);
} else
v = mmio->value;
if (mmio->in_context)
continue;
I915_WRITE(mmio->reg, v);
POSTING_READ(mmio->reg);
gvt_dbg_render("restore reg %x old %x new %x\n",
i915_mmio_reg_offset(mmio->reg),
mmio->value, v);
}
}
