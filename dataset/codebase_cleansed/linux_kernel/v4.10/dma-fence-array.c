static const char *dma_fence_array_get_driver_name(struct dma_fence *fence)
{
return "dma_fence_array";
}
static const char *dma_fence_array_get_timeline_name(struct dma_fence *fence)
{
return "unbound";
}
static void dma_fence_array_cb_func(struct dma_fence *f,
struct dma_fence_cb *cb)
{
struct dma_fence_array_cb *array_cb =
container_of(cb, struct dma_fence_array_cb, cb);
struct dma_fence_array *array = array_cb->array;
if (atomic_dec_and_test(&array->num_pending))
dma_fence_signal(&array->base);
dma_fence_put(&array->base);
}
static bool dma_fence_array_enable_signaling(struct dma_fence *fence)
{
struct dma_fence_array *array = to_dma_fence_array(fence);
struct dma_fence_array_cb *cb = (void *)(&array[1]);
unsigned i;
for (i = 0; i < array->num_fences; ++i) {
cb[i].array = array;
dma_fence_get(&array->base);
if (dma_fence_add_callback(array->fences[i], &cb[i].cb,
dma_fence_array_cb_func)) {
dma_fence_put(&array->base);
if (atomic_dec_and_test(&array->num_pending))
return false;
}
}
return true;
}
static bool dma_fence_array_signaled(struct dma_fence *fence)
{
struct dma_fence_array *array = to_dma_fence_array(fence);
return atomic_read(&array->num_pending) <= 0;
}
static void dma_fence_array_release(struct dma_fence *fence)
{
struct dma_fence_array *array = to_dma_fence_array(fence);
unsigned i;
for (i = 0; i < array->num_fences; ++i)
dma_fence_put(array->fences[i]);
kfree(array->fences);
dma_fence_free(fence);
}
struct dma_fence_array *dma_fence_array_create(int num_fences,
struct dma_fence **fences,
u64 context, unsigned seqno,
bool signal_on_any)
{
struct dma_fence_array *array;
size_t size = sizeof(*array);
size += num_fences * sizeof(struct dma_fence_array_cb);
array = kzalloc(size, GFP_KERNEL);
if (!array)
return NULL;
spin_lock_init(&array->lock);
dma_fence_init(&array->base, &dma_fence_array_ops, &array->lock,
context, seqno);
array->num_fences = num_fences;
atomic_set(&array->num_pending, signal_on_any ? 1 : num_fences);
array->fences = fences;
return array;
}
