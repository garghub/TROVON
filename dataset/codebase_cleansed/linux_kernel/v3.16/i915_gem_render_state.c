static struct i915_render_state *render_state_alloc(struct drm_device *dev)
{
struct i915_render_state *so;
struct page *page;
int ret;
so = kzalloc(sizeof(*so), GFP_KERNEL);
if (!so)
return ERR_PTR(-ENOMEM);
so->obj = i915_gem_alloc_object(dev, 4096);
if (so->obj == NULL) {
ret = -ENOMEM;
goto free;
}
so->size = 4096;
ret = i915_gem_obj_ggtt_pin(so->obj, 4096, 0);
if (ret)
goto free_gem;
BUG_ON(so->obj->pages->nents != 1);
page = sg_page(so->obj->pages->sgl);
so->batch = kmap(page);
if (!so->batch) {
ret = -ENOMEM;
goto unpin;
}
so->ggtt_offset = i915_gem_obj_ggtt_offset(so->obj);
return so;
unpin:
i915_gem_object_ggtt_unpin(so->obj);
free_gem:
drm_gem_object_unreference(&so->obj->base);
free:
kfree(so);
return ERR_PTR(ret);
}
static void render_state_free(struct i915_render_state *so)
{
kunmap(kmap_to_page(so->batch));
i915_gem_object_ggtt_unpin(so->obj);
drm_gem_object_unreference(&so->obj->base);
kfree(so);
}
static const struct intel_renderstate_rodata *
render_state_get_rodata(struct drm_device *dev, const int gen)
{
switch (gen) {
case 6:
return &gen6_null_state;
case 7:
return &gen7_null_state;
case 8:
return &gen8_null_state;
}
return NULL;
}
static int render_state_setup(const int gen,
const struct intel_renderstate_rodata *rodata,
struct i915_render_state *so)
{
const u64 goffset = i915_gem_obj_ggtt_offset(so->obj);
u32 reloc_index = 0;
u32 * const d = so->batch;
unsigned int i = 0;
int ret;
if (!rodata || rodata->batch_items * 4 > so->size)
return -EINVAL;
ret = i915_gem_object_set_to_cpu_domain(so->obj, true);
if (ret)
return ret;
while (i < rodata->batch_items) {
u32 s = rodata->batch[i];
if (reloc_index < rodata->reloc_items &&
i * 4 == rodata->reloc[reloc_index]) {
s += goffset & 0xffffffff;
if (gen >= 8) {
if (i + 1 >= rodata->batch_items ||
rodata->batch[i + 1] != 0)
return -EINVAL;
d[i] = s;
i++;
s = (goffset & 0xffffffff00000000ull) >> 32;
}
reloc_index++;
}
d[i] = s;
i++;
}
ret = i915_gem_object_set_to_gtt_domain(so->obj, false);
if (ret)
return ret;
if (rodata->reloc_items != reloc_index) {
DRM_ERROR("not all relocs resolved, %d out of %d\n",
reloc_index, rodata->reloc_items);
return -EINVAL;
}
so->len = rodata->batch_items * 4;
return 0;
}
int i915_gem_render_state_init(struct intel_engine_cs *ring)
{
const int gen = INTEL_INFO(ring->dev)->gen;
struct i915_render_state *so;
const struct intel_renderstate_rodata *rodata;
int ret;
if (WARN_ON(ring->id != RCS))
return -ENOENT;
rodata = render_state_get_rodata(ring->dev, gen);
if (rodata == NULL)
return 0;
so = render_state_alloc(ring->dev);
if (IS_ERR(so))
return PTR_ERR(so);
ret = render_state_setup(gen, rodata, so);
if (ret)
goto out;
ret = ring->dispatch_execbuffer(ring,
i915_gem_obj_ggtt_offset(so->obj),
so->len,
I915_DISPATCH_SECURE);
if (ret)
goto out;
i915_vma_move_to_active(i915_gem_obj_to_ggtt(so->obj), ring);
ret = __i915_add_request(ring, NULL, so->obj, NULL);
out:
render_state_free(so);
return ret;
}
