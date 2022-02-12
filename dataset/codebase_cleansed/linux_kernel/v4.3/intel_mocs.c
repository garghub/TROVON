static bool get_mocs_settings(struct drm_device *dev,
struct drm_i915_mocs_table *table)
{
bool result = false;
if (IS_SKYLAKE(dev)) {
table->size = ARRAY_SIZE(skylake_mocs_table);
table->table = skylake_mocs_table;
result = true;
} else if (IS_BROXTON(dev)) {
table->size = ARRAY_SIZE(broxton_mocs_table);
table->table = broxton_mocs_table;
result = true;
} else {
WARN_ONCE(INTEL_INFO(dev)->gen >= 9,
"Platform that should have a MOCS table does not.\n");
}
return result;
}
static int emit_mocs_control_table(struct drm_i915_gem_request *req,
const struct drm_i915_mocs_table *table,
u32 reg_base)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
unsigned int index;
int ret;
if (WARN_ON(table->size > GEN9_NUM_MOCS_ENTRIES))
return -ENODEV;
ret = intel_logical_ring_begin(req, 2 + 2 * GEN9_NUM_MOCS_ENTRIES);
if (ret) {
DRM_DEBUG("intel_logical_ring_begin failed %d\n", ret);
return ret;
}
intel_logical_ring_emit(ringbuf,
MI_LOAD_REGISTER_IMM(GEN9_NUM_MOCS_ENTRIES));
for (index = 0; index < table->size; index++) {
intel_logical_ring_emit(ringbuf, reg_base + index * 4);
intel_logical_ring_emit(ringbuf,
table->table[index].control_value);
}
for (; index < GEN9_NUM_MOCS_ENTRIES; index++) {
intel_logical_ring_emit(ringbuf, reg_base + index * 4);
intel_logical_ring_emit(ringbuf, table->table[0].control_value);
}
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
return 0;
}
static int emit_mocs_l3cc_table(struct drm_i915_gem_request *req,
const struct drm_i915_mocs_table *table)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
unsigned int count;
unsigned int i;
u32 value;
u32 filler = (table->table[0].l3cc_value & 0xffff) |
((table->table[0].l3cc_value & 0xffff) << 16);
int ret;
if (WARN_ON(table->size > GEN9_NUM_MOCS_ENTRIES))
return -ENODEV;
ret = intel_logical_ring_begin(req, 2 + GEN9_NUM_MOCS_ENTRIES);
if (ret) {
DRM_DEBUG("intel_logical_ring_begin failed %d\n", ret);
return ret;
}
intel_logical_ring_emit(ringbuf,
MI_LOAD_REGISTER_IMM(GEN9_NUM_MOCS_ENTRIES / 2));
for (i = 0, count = 0; i < table->size / 2; i++, count += 2) {
value = (table->table[count].l3cc_value & 0xffff) |
((table->table[count + 1].l3cc_value & 0xffff) << 16);
intel_logical_ring_emit(ringbuf, GEN9_LNCFCMOCS0 + i * 4);
intel_logical_ring_emit(ringbuf, value);
}
if (table->size & 0x01) {
value = (table->table[count].l3cc_value & 0xffff) |
((table->table[0].l3cc_value & 0xffff) << 16);
} else
value = filler;
for (; i < GEN9_NUM_MOCS_ENTRIES / 2; i++) {
intel_logical_ring_emit(ringbuf, GEN9_LNCFCMOCS0 + i * 4);
intel_logical_ring_emit(ringbuf, value);
value = filler;
}
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
return 0;
}
int intel_rcs_context_init_mocs(struct drm_i915_gem_request *req)
{
struct drm_i915_mocs_table t;
int ret;
if (get_mocs_settings(req->ring->dev, &t)) {
ret = emit_mocs_control_table(req, &t, GEN9_GFX_MOCS_0);
if (ret)
return ret;
ret = emit_mocs_control_table(req, &t, GEN9_MFX0_MOCS_0);
if (ret)
return ret;
ret = emit_mocs_control_table(req, &t, GEN9_MFX1_MOCS_0);
if (ret)
return ret;
ret = emit_mocs_control_table(req, &t, GEN9_VEBOX_MOCS_0);
if (ret)
return ret;
ret = emit_mocs_control_table(req, &t, GEN9_BLT_MOCS_0);
if (ret)
return ret;
ret = emit_mocs_l3cc_table(req, &t);
if (ret)
return ret;
}
return 0;
}
