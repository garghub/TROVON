static void __intel_timeline_init(struct intel_timeline *tl,
struct i915_gem_timeline *parent,
u64 context,
struct lock_class_key *lockclass,
const char *lockname)
{
tl->fence_context = context;
tl->common = parent;
#ifdef CONFIG_DEBUG_SPINLOCK
__raw_spin_lock_init(&tl->lock.rlock, lockname, lockclass);
#else
spin_lock_init(&tl->lock);
#endif
init_request_active(&tl->last_request, NULL);
INIT_LIST_HEAD(&tl->requests);
i915_syncmap_init(&tl->sync);
}
static void __intel_timeline_fini(struct intel_timeline *tl)
{
GEM_BUG_ON(!list_empty(&tl->requests));
i915_syncmap_free(&tl->sync);
}
static int __i915_gem_timeline_init(struct drm_i915_private *i915,
struct i915_gem_timeline *timeline,
const char *name,
struct lock_class_key *lockclass,
const char *lockname)
{
unsigned int i;
u64 fences;
lockdep_assert_held(&i915->drm.struct_mutex);
BUILD_BUG_ON(KSYNCMAP < I915_NUM_ENGINES);
timeline->i915 = i915;
timeline->name = kstrdup(name ?: "[kernel]", GFP_KERNEL);
if (!timeline->name)
return -ENOMEM;
list_add(&timeline->link, &i915->gt.timelines);
fences = dma_fence_context_alloc(ARRAY_SIZE(timeline->engine));
for (i = 0; i < ARRAY_SIZE(timeline->engine); i++)
__intel_timeline_init(&timeline->engine[i],
timeline, fences++,
lockclass, lockname);
return 0;
}
int i915_gem_timeline_init(struct drm_i915_private *i915,
struct i915_gem_timeline *timeline,
const char *name)
{
static struct lock_class_key class;
return __i915_gem_timeline_init(i915, timeline, name,
&class, "&timeline->lock");
}
int i915_gem_timeline_init__global(struct drm_i915_private *i915)
{
static struct lock_class_key class;
return __i915_gem_timeline_init(i915,
&i915->gt.global_timeline,
"[execution]",
&class, "&global_timeline->lock");
}
void i915_gem_timelines_mark_idle(struct drm_i915_private *i915)
{
struct i915_gem_timeline *timeline;
int i;
lockdep_assert_held(&i915->drm.struct_mutex);
list_for_each_entry(timeline, &i915->gt.timelines, link) {
for (i = 0; i < ARRAY_SIZE(timeline->engine); i++) {
struct intel_timeline *tl = &timeline->engine[i];
i915_syncmap_free(&tl->sync);
}
}
}
void i915_gem_timeline_fini(struct i915_gem_timeline *timeline)
{
int i;
lockdep_assert_held(&timeline->i915->drm.struct_mutex);
for (i = 0; i < ARRAY_SIZE(timeline->engine); i++)
__intel_timeline_fini(&timeline->engine[i]);
list_del(&timeline->link);
kfree(timeline->name);
}
