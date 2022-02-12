static const struct intel_renderstate_rodata *
render_state_get_rodata(const struct drm_i915_gem_request *req)
{
switch (INTEL_GEN(req->i915)) {
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
static int render_state_setup(struct render_state *so)
{
struct drm_device *dev = so->vma->vm->dev;
const struct intel_renderstate_rodata *rodata = so->rodata;
const bool has_64bit_reloc = INTEL_GEN(dev) >= 8;
unsigned int i = 0, reloc_index = 0;
struct page *page;
u32 *d;
int ret;
ret = i915_gem_object_set_to_cpu_domain(so->vma->obj, true);
if (ret)
return ret;
page = i915_gem_object_get_dirty_page(so->vma->obj, 0);
d = kmap(page);
while (i < rodata->batch_items) {
u32 s = rodata->batch[i];
if (i * 4 == rodata->reloc[reloc_index]) {
u64 r = s + so->vma->node.start;
s = lower_32_bits(r);
if (has_64bit_reloc) {
if (i + 1 >= rodata->batch_items ||
rodata->batch[i + 1] != 0) {
ret = -EINVAL;
goto err_out;
}
d[i++] = s;
s = upper_32_bits(r);
}
reloc_index++;
}
d[i++] = s;
}
while (i % CACHELINE_DWORDS)
OUT_BATCH(d, i, MI_NOOP);
so->aux_batch_offset = i * sizeof(u32);
if (HAS_POOLED_EU(dev)) {
u32 eu_pool_config = 0x00777000;
OUT_BATCH(d, i, GEN9_MEDIA_POOL_STATE);
OUT_BATCH(d, i, GEN9_MEDIA_POOL_ENABLE);
OUT_BATCH(d, i, eu_pool_config);
OUT_BATCH(d, i, 0);
OUT_BATCH(d, i, 0);
OUT_BATCH(d, i, 0);
}
OUT_BATCH(d, i, MI_BATCH_BUFFER_END);
so->aux_batch_size = (i * sizeof(u32)) - so->aux_batch_offset;
so->aux_batch_size = ALIGN(so->aux_batch_size, 8);
kunmap(page);
ret = i915_gem_object_set_to_gtt_domain(so->vma->obj, false);
if (ret)
return ret;
if (rodata->reloc[reloc_index] != -1) {
DRM_ERROR("only %d relocs resolved\n", reloc_index);
return -EINVAL;
}
return 0;
err_out:
kunmap(page);
return ret;
}
int i915_gem_render_state_init(struct drm_i915_gem_request *req)
{
struct render_state so;
struct drm_i915_gem_object *obj;
int ret;
if (WARN_ON(req->engine->id != RCS))
return -ENOENT;
so.rodata = render_state_get_rodata(req);
if (!so.rodata)
return 0;
if (so.rodata->batch_items * 4 > 4096)
return -EINVAL;
obj = i915_gem_object_create(&req->i915->drm, 4096);
if (IS_ERR(obj))
return PTR_ERR(obj);
so.vma = i915_vma_create(obj, &req->i915->ggtt.base, NULL);
if (IS_ERR(so.vma)) {
ret = PTR_ERR(so.vma);
goto err_obj;
}
ret = i915_vma_pin(so.vma, 0, 0, PIN_GLOBAL);
if (ret)
goto err_obj;
ret = render_state_setup(&so);
if (ret)
goto err_unpin;
ret = req->engine->emit_bb_start(req, so.vma->node.start,
so.rodata->batch_items * 4,
I915_DISPATCH_SECURE);
if (ret)
goto err_unpin;
if (so.aux_batch_size > 8) {
ret = req->engine->emit_bb_start(req,
(so.vma->node.start +
so.aux_batch_offset),
so.aux_batch_size,
I915_DISPATCH_SECURE);
if (ret)
goto err_unpin;
}
i915_vma_move_to_active(so.vma, req, 0);
err_unpin:
i915_vma_unpin(so.vma);
err_obj:
i915_gem_object_put(obj);
return ret;
}
