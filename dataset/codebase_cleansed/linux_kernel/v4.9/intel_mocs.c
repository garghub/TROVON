static bool get_mocs_settings(struct drm_i915_private *dev_priv,
struct drm_i915_mocs_table *table)
{
bool result = false;
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
table->size = ARRAY_SIZE(skylake_mocs_table);
table->table = skylake_mocs_table;
result = true;
} else if (IS_BROXTON(dev_priv)) {
table->size = ARRAY_SIZE(broxton_mocs_table);
table->table = broxton_mocs_table;
result = true;
} else {
WARN_ONCE(INTEL_INFO(dev_priv)->gen >= 9,
"Platform that should have a MOCS table does not.\n");
}
if (IS_GEN9(dev_priv)) {
int i;
for (i = 0; i < table->size; i++)
if (WARN_ON(table->table[i].l3cc_value &
(L3_ESC(1) | L3_SCC(0x7))))
return false;
}
return result;
}
static i915_reg_t mocs_register(enum intel_engine_id engine_id, int index)
{
switch (engine_id) {
case RCS:
return GEN9_GFX_MOCS(index);
case VCS:
return GEN9_MFX0_MOCS(index);
case BCS:
return GEN9_BLT_MOCS(index);
case VECS:
return GEN9_VEBOX_MOCS(index);
case VCS2:
return GEN9_MFX1_MOCS(index);
default:
MISSING_CASE(engine_id);
return INVALID_MMIO_REG;
}
}
int intel_mocs_init_engine(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct drm_i915_mocs_table table;
unsigned int index;
if (!get_mocs_settings(dev_priv, &table))
return 0;
if (WARN_ON(table.size > GEN9_NUM_MOCS_ENTRIES))
return -ENODEV;
for (index = 0; index < table.size; index++)
I915_WRITE(mocs_register(engine->id, index),
table.table[index].control_value);
for (; index < GEN9_NUM_MOCS_ENTRIES; index++)
I915_WRITE(mocs_register(engine->id, index),
table.table[0].control_value);
return 0;
}
static int emit_mocs_control_table(struct drm_i915_gem_request *req,
const struct drm_i915_mocs_table *table)
{
struct intel_ring *ring = req->ring;
enum intel_engine_id engine = req->engine->id;
unsigned int index;
int ret;
if (WARN_ON(table->size > GEN9_NUM_MOCS_ENTRIES))
return -ENODEV;
ret = intel_ring_begin(req, 2 + 2 * GEN9_NUM_MOCS_ENTRIES);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(GEN9_NUM_MOCS_ENTRIES));
for (index = 0; index < table->size; index++) {
intel_ring_emit_reg(ring, mocs_register(engine, index));
intel_ring_emit(ring, table->table[index].control_value);
}
for (; index < GEN9_NUM_MOCS_ENTRIES; index++) {
intel_ring_emit_reg(ring, mocs_register(engine, index));
intel_ring_emit(ring, table->table[0].control_value);
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static inline u32 l3cc_combine(const struct drm_i915_mocs_table *table,
u16 low,
u16 high)
{
return table->table[low].l3cc_value |
table->table[high].l3cc_value << 16;
}
static int emit_mocs_l3cc_table(struct drm_i915_gem_request *req,
const struct drm_i915_mocs_table *table)
{
struct intel_ring *ring = req->ring;
unsigned int i;
int ret;
if (WARN_ON(table->size > GEN9_NUM_MOCS_ENTRIES))
return -ENODEV;
ret = intel_ring_begin(req, 2 + GEN9_NUM_MOCS_ENTRIES);
if (ret)
return ret;
intel_ring_emit(ring,
MI_LOAD_REGISTER_IMM(GEN9_NUM_MOCS_ENTRIES / 2));
for (i = 0; i < table->size/2; i++) {
intel_ring_emit_reg(ring, GEN9_LNCFCMOCS(i));
intel_ring_emit(ring, l3cc_combine(table, 2*i, 2*i+1));
}
if (table->size & 0x01) {
intel_ring_emit_reg(ring, GEN9_LNCFCMOCS(i));
intel_ring_emit(ring, l3cc_combine(table, 2*i, 0));
i++;
}
for (; i < GEN9_NUM_MOCS_ENTRIES / 2; i++) {
intel_ring_emit_reg(ring, GEN9_LNCFCMOCS(i));
intel_ring_emit(ring, l3cc_combine(table, 0, 0));
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
void intel_mocs_init_l3cc_table(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_mocs_table table;
unsigned int i;
if (!get_mocs_settings(dev_priv, &table))
return;
for (i = 0; i < table.size/2; i++)
I915_WRITE(GEN9_LNCFCMOCS(i), l3cc_combine(&table, 2*i, 2*i+1));
if (table.size & 0x01) {
I915_WRITE(GEN9_LNCFCMOCS(i), l3cc_combine(&table, 2*i, 0));
i++;
}
for (; i < (GEN9_NUM_MOCS_ENTRIES / 2); i++)
I915_WRITE(GEN9_LNCFCMOCS(i), l3cc_combine(&table, 0, 0));
}
int intel_rcs_context_init_mocs(struct drm_i915_gem_request *req)
{
struct drm_i915_mocs_table t;
int ret;
if (get_mocs_settings(req->i915, &t)) {
ret = emit_mocs_control_table(req, &t);
if (ret)
return ret;
ret = emit_mocs_l3cc_table(req, &t);
if (ret)
return ret;
}
return 0;
}
