static const struct intel_renderstate_rodata *
render_state_get_rodata(const struct intel_engine_cs *engine)
{
switch (INTEL_GEN(engine->i915)) {
case 6:
return &gen6_null_state;
case 7:
return &gen7_null_state;
case 8:
return &gen8_null_state;
case 9:
return &gen9_null_state;
}
return NULL;
}
static int render_state_setup(struct intel_render_state *so,
struct drm_i915_private *i915)
{
const struct intel_renderstate_rodata *rodata = so->rodata;
struct drm_i915_gem_object *obj = so->vma->obj;
unsigned int i = 0, reloc_index = 0;
unsigned int needs_clflush;
u32 *d;
int ret;
ret = i915_gem_obj_prepare_shmem_write(obj, &needs_clflush);
if (ret)
return ret;
d = kmap_atomic(i915_gem_object_get_dirty_page(obj, 0));
while (i < rodata->batch_items) {
u32 s = rodata->batch[i];
if (i * 4 == rodata->reloc[reloc_index]) {
u64 r = s + so->vma->node.start;
s = lower_32_bits(r);
if (HAS_64BIT_RELOC(i915)) {
if (i + 1 >= rodata->batch_items ||
rodata->batch[i + 1] != 0)
goto err;
d[i++] = s;
s = upper_32_bits(r);
}
reloc_index++;
}
d[i++] = s;
}
if (rodata->reloc[reloc_index] != -1) {
DRM_ERROR("only %d relocs resolved\n", reloc_index);
goto err;
}
so->batch_offset = so->vma->node.start;
so->batch_size = rodata->batch_items * sizeof(u32);
while (i % CACHELINE_DWORDS)
OUT_BATCH(d, i, MI_NOOP);
so->aux_offset = i * sizeof(u32);
if (HAS_POOLED_EU(i915)) {
u32 eu_pool_config = 0x00777000;
OUT_BATCH(d, i, GEN9_MEDIA_POOL_STATE);
OUT_BATCH(d, i, GEN9_MEDIA_POOL_ENABLE);
OUT_BATCH(d, i, eu_pool_config);
OUT_BATCH(d, i, 0);
OUT_BATCH(d, i, 0);
OUT_BATCH(d, i, 0);
}
OUT_BATCH(d, i, MI_BATCH_BUFFER_END);
so->aux_size = i * sizeof(u32) - so->aux_offset;
so->aux_offset += so->batch_offset;
so->aux_size = ALIGN(so->aux_size, 8);
if (needs_clflush)
drm_clflush_virt_range(d, i * sizeof(u32));
kunmap_atomic(d);
ret = i915_gem_object_set_to_gtt_domain(obj, false);
out:
i915_gem_obj_finish_shmem_access(obj);
return ret;
err:
kunmap_atomic(d);
ret = -EINVAL;
goto out;
}
int i915_gem_render_state_init(struct intel_engine_cs *engine)
{
struct intel_render_state *so;
const struct intel_renderstate_rodata *rodata;
struct drm_i915_gem_object *obj;
int ret;
if (engine->id != RCS)
return 0;
rodata = render_state_get_rodata(engine);
if (!rodata)
return 0;
if (rodata->batch_items * 4 > PAGE_SIZE)
return -EINVAL;
so = kmalloc(sizeof(*so), GFP_KERNEL);
if (!so)
return -ENOMEM;
obj = i915_gem_object_create_internal(engine->i915, PAGE_SIZE);
if (IS_ERR(obj)) {
ret = PTR_ERR(obj);
goto err_free;
}
so->vma = i915_vma_instance(obj, &engine->i915->ggtt.base, NULL);
if (IS_ERR(so->vma)) {
ret = PTR_ERR(so->vma);
goto err_obj;
}
so->rodata = rodata;
engine->render_state = so;
return 0;
err_obj:
i915_gem_object_put(obj);
err_free:
kfree(so);
return ret;
}
int i915_gem_render_state_emit(struct drm_i915_gem_request *req)
{
struct intel_render_state *so;
int ret;
lockdep_assert_held(&req->i915->drm.struct_mutex);
so = req->engine->render_state;
if (!so)
return 0;
if (!so->vma->obj->mm.pages)
so->batch_offset = -1;
ret = i915_vma_pin(so->vma, 0, 0, PIN_GLOBAL | PIN_HIGH);
if (ret)
return ret;
if (so->vma->node.start != so->batch_offset) {
ret = render_state_setup(so, req->i915);
if (ret)
goto err_unpin;
}
ret = req->engine->emit_bb_start(req,
so->batch_offset, so->batch_size,
I915_DISPATCH_SECURE);
if (ret)
goto err_unpin;
if (so->aux_size > 8) {
ret = req->engine->emit_bb_start(req,
so->aux_offset, so->aux_size,
I915_DISPATCH_SECURE);
if (ret)
goto err_unpin;
}
i915_vma_move_to_active(so->vma, req, 0);
err_unpin:
i915_vma_unpin(so->vma);
return ret;
}
void i915_gem_render_state_fini(struct intel_engine_cs *engine)
{
struct intel_render_state *so;
struct drm_i915_gem_object *obj;
so = fetch_and_zero(&engine->render_state);
if (!so)
return;
obj = so->vma->obj;
i915_vma_close(so->vma);
__i915_gem_object_release_unless_active(obj);
kfree(so);
}
