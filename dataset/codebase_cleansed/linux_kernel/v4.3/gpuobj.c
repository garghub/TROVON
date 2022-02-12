static u32
nvkm_gpuobj_rd32_fast(struct nvkm_gpuobj *gpuobj, u32 offset)
{
return ioread32_native(gpuobj->map + offset);
}
static void
nvkm_gpuobj_wr32_fast(struct nvkm_gpuobj *gpuobj, u32 offset, u32 data)
{
iowrite32_native(data, gpuobj->map + offset);
}
static u32
nvkm_gpuobj_heap_rd32(struct nvkm_gpuobj *gpuobj, u32 offset)
{
return nvkm_ro32(gpuobj->memory, offset);
}
static void
nvkm_gpuobj_heap_wr32(struct nvkm_gpuobj *gpuobj, u32 offset, u32 data)
{
nvkm_wo32(gpuobj->memory, offset, data);
}
static void
nvkm_gpuobj_heap_release(struct nvkm_gpuobj *gpuobj)
{
gpuobj->func = &nvkm_gpuobj_heap;
nvkm_done(gpuobj->memory);
}
static void *
nvkm_gpuobj_heap_acquire(struct nvkm_gpuobj *gpuobj)
{
gpuobj->map = nvkm_kmap(gpuobj->memory);
if (likely(gpuobj->map))
gpuobj->func = &nvkm_gpuobj_heap_fast;
else
gpuobj->func = &nvkm_gpuobj_heap_slow;
return gpuobj->map;
}
static u32
nvkm_gpuobj_rd32(struct nvkm_gpuobj *gpuobj, u32 offset)
{
return nvkm_ro32(gpuobj->parent, gpuobj->node->offset + offset);
}
static void
nvkm_gpuobj_wr32(struct nvkm_gpuobj *gpuobj, u32 offset, u32 data)
{
nvkm_wo32(gpuobj->parent, gpuobj->node->offset + offset, data);
}
static void
nvkm_gpuobj_release(struct nvkm_gpuobj *gpuobj)
{
gpuobj->func = &nvkm_gpuobj_func;
nvkm_done(gpuobj->parent);
}
static void *
nvkm_gpuobj_acquire(struct nvkm_gpuobj *gpuobj)
{
gpuobj->map = nvkm_kmap(gpuobj->parent);
if (likely(gpuobj->map)) {
gpuobj->map = (u8 *)gpuobj->map + gpuobj->node->offset;
gpuobj->func = &nvkm_gpuobj_fast;
} else {
gpuobj->func = &nvkm_gpuobj_slow;
}
return gpuobj->map;
}
static int
nvkm_gpuobj_ctor(struct nvkm_device *device, u32 size, int align, bool zero,
struct nvkm_gpuobj *parent, struct nvkm_gpuobj *gpuobj)
{
u32 offset;
int ret;
if (parent) {
if (align >= 0) {
ret = nvkm_mm_head(&parent->heap, 0, 1, size, size,
max(align, 1), &gpuobj->node);
} else {
ret = nvkm_mm_tail(&parent->heap, 0, 1, size, size,
-align, &gpuobj->node);
}
if (ret)
return ret;
gpuobj->parent = parent;
gpuobj->func = &nvkm_gpuobj_func;
gpuobj->addr = parent->addr + gpuobj->node->offset;
gpuobj->size = gpuobj->node->length;
if (zero) {
nvkm_kmap(gpuobj);
for (offset = 0; offset < gpuobj->size; offset += 4)
nvkm_wo32(gpuobj, offset, 0x00000000);
nvkm_done(gpuobj);
}
} else {
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST, size,
abs(align), zero, &gpuobj->memory);
if (ret)
return ret;
gpuobj->func = &nvkm_gpuobj_heap;
gpuobj->addr = nvkm_memory_addr(gpuobj->memory);
gpuobj->size = nvkm_memory_size(gpuobj->memory);
}
return nvkm_mm_init(&gpuobj->heap, 0, gpuobj->size, 1);
}
void
nvkm_gpuobj_del(struct nvkm_gpuobj **pgpuobj)
{
struct nvkm_gpuobj *gpuobj = *pgpuobj;
if (gpuobj) {
if (gpuobj->parent)
nvkm_mm_free(&gpuobj->parent->heap, &gpuobj->node);
nvkm_mm_fini(&gpuobj->heap);
nvkm_memory_del(&gpuobj->memory);
kfree(*pgpuobj);
*pgpuobj = NULL;
}
}
int
nvkm_gpuobj_new(struct nvkm_device *device, u32 size, int align, bool zero,
struct nvkm_gpuobj *parent, struct nvkm_gpuobj **pgpuobj)
{
struct nvkm_gpuobj *gpuobj;
int ret;
if (!(gpuobj = *pgpuobj = kzalloc(sizeof(*gpuobj), GFP_KERNEL)))
return -ENOMEM;
ret = nvkm_gpuobj_ctor(device, size, align, zero, parent, gpuobj);
if (ret)
nvkm_gpuobj_del(pgpuobj);
return ret;
}
int
nvkm_gpuobj_map(struct nvkm_gpuobj *gpuobj, struct nvkm_vm *vm,
u32 access, struct nvkm_vma *vma)
{
struct nvkm_memory *memory = gpuobj->memory;
int ret = nvkm_vm_get(vm, gpuobj->size, 12, access, vma);
if (ret == 0)
nvkm_memory_map(memory, vma, 0);
return ret;
}
void
nvkm_gpuobj_unmap(struct nvkm_vma *vma)
{
if (vma->node) {
nvkm_vm_unmap(vma);
nvkm_vm_put(vma);
}
}
int
nvkm_gpuobj_wrap(struct nvkm_memory *memory, struct nvkm_gpuobj **pgpuobj)
{
if (!(*pgpuobj = kzalloc(sizeof(**pgpuobj), GFP_KERNEL)))
return -ENOMEM;
(*pgpuobj)->addr = nvkm_memory_addr(memory);
(*pgpuobj)->size = nvkm_memory_size(memory);
return 0;
}
