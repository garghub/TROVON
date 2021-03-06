static enum nvkm_memory_target
nv40_instobj_target(struct nvkm_memory *memory)
{
return NVKM_MEM_TARGET_INST;
}
static u64
nv40_instobj_addr(struct nvkm_memory *memory)
{
return nv40_instobj(memory)->node->offset;
}
static u64
nv40_instobj_size(struct nvkm_memory *memory)
{
return nv40_instobj(memory)->node->length;
}
static void __iomem *
nv40_instobj_acquire(struct nvkm_memory *memory)
{
struct nv40_instobj *iobj = nv40_instobj(memory);
return iobj->imem->iomem + iobj->node->offset;
}
static void
nv40_instobj_release(struct nvkm_memory *memory)
{
}
static u32
nv40_instobj_rd32(struct nvkm_memory *memory, u64 offset)
{
struct nv40_instobj *iobj = nv40_instobj(memory);
return ioread32_native(iobj->imem->iomem + iobj->node->offset + offset);
}
static void
nv40_instobj_wr32(struct nvkm_memory *memory, u64 offset, u32 data)
{
struct nv40_instobj *iobj = nv40_instobj(memory);
iowrite32_native(data, iobj->imem->iomem + iobj->node->offset + offset);
}
static void *
nv40_instobj_dtor(struct nvkm_memory *memory)
{
struct nv40_instobj *iobj = nv40_instobj(memory);
mutex_lock(&iobj->imem->base.subdev.mutex);
nvkm_mm_free(&iobj->imem->heap, &iobj->node);
mutex_unlock(&iobj->imem->base.subdev.mutex);
return iobj;
}
static int
nv40_instobj_new(struct nvkm_instmem *base, u32 size, u32 align, bool zero,
struct nvkm_memory **pmemory)
{
struct nv40_instmem *imem = nv40_instmem(base);
struct nv40_instobj *iobj;
int ret;
if (!(iobj = kzalloc(sizeof(*iobj), GFP_KERNEL)))
return -ENOMEM;
*pmemory = &iobj->memory;
nvkm_memory_ctor(&nv40_instobj_func, &iobj->memory);
iobj->imem = imem;
mutex_lock(&imem->base.subdev.mutex);
ret = nvkm_mm_head(&imem->heap, 0, 1, size, size,
align ? align : 1, &iobj->node);
mutex_unlock(&imem->base.subdev.mutex);
return ret;
}
static u32
nv40_instmem_rd32(struct nvkm_instmem *base, u32 addr)
{
return ioread32_native(nv40_instmem(base)->iomem + addr);
}
static void
nv40_instmem_wr32(struct nvkm_instmem *base, u32 addr, u32 data)
{
iowrite32_native(data, nv40_instmem(base)->iomem + addr);
}
static int
nv40_instmem_oneinit(struct nvkm_instmem *base)
{
struct nv40_instmem *imem = nv40_instmem(base);
struct nvkm_device *device = imem->base.subdev.device;
int ret, vs;
vs = hweight8((nvkm_rd32(device, 0x001540) & 0x0000ff00) >> 8);
if (device->chipset == 0x40) imem->base.reserved = 0x6aa0 * vs;
else if (device->chipset < 0x43) imem->base.reserved = 0x4f00 * vs;
else if (nv44_gr_class(device)) imem->base.reserved = 0x4980 * vs;
else imem->base.reserved = 0x4a40 * vs;
imem->base.reserved += 16 * 1024;
imem->base.reserved *= 32;
imem->base.reserved += 512 * 1024;
imem->base.reserved += 512 * 1024;
imem->base.reserved = round_up(imem->base.reserved, 4096);
ret = nvkm_mm_init(&imem->heap, 0, imem->base.reserved, 1);
if (ret)
return ret;
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST, 0x10000, 0, false,
&imem->base.vbios);
if (ret)
return ret;
ret = nvkm_ramht_new(device, 0x08000, 0, NULL, &imem->base.ramht);
if (ret)
return ret;
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST, 0x08000, 0, false,
&imem->base.ramro);
if (ret)
return ret;
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST, 0x20000, 0, true,
&imem->base.ramfc);
if (ret)
return ret;
return 0;
}
static void *
nv40_instmem_dtor(struct nvkm_instmem *base)
{
struct nv40_instmem *imem = nv40_instmem(base);
nvkm_memory_del(&imem->base.ramfc);
nvkm_memory_del(&imem->base.ramro);
nvkm_ramht_del(&imem->base.ramht);
nvkm_memory_del(&imem->base.vbios);
nvkm_mm_fini(&imem->heap);
if (imem->iomem)
iounmap(imem->iomem);
return imem;
}
int
nv40_instmem_new(struct nvkm_device *device, int index,
struct nvkm_instmem **pimem)
{
struct nv40_instmem *imem;
int bar;
if (!(imem = kzalloc(sizeof(*imem), GFP_KERNEL)))
return -ENOMEM;
nvkm_instmem_ctor(&nv40_instmem, device, index, &imem->base);
*pimem = &imem->base;
if (device->func->resource_size(device, 2))
bar = 2;
else
bar = 3;
imem->iomem = ioremap(device->func->resource_addr(device, bar),
device->func->resource_size(device, bar));
if (!imem->iomem) {
nvkm_error(&imem->base.subdev, "unable to map PRAMIN BAR\n");
return -EFAULT;
}
return 0;
}
