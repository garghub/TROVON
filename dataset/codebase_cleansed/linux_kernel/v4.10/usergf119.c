static int
gf119_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
struct gf119_dmaobj *dmaobj = gf119_dmaobj(base);
struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
int ret;
ret = nvkm_gpuobj_new(device, 24, align, false, parent, pgpuobj);
if (ret == 0) {
nvkm_kmap(*pgpuobj);
nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0);
nvkm_wo32(*pgpuobj, 0x04, dmaobj->base.start >> 8);
nvkm_wo32(*pgpuobj, 0x08, dmaobj->base.limit >> 8);
nvkm_wo32(*pgpuobj, 0x0c, 0x00000000);
nvkm_wo32(*pgpuobj, 0x10, 0x00000000);
nvkm_wo32(*pgpuobj, 0x14, 0x00000000);
nvkm_done(*pgpuobj);
}
return ret;
}
int
gf119_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
union {
struct gf119_dma_v0 v0;
} *args;
struct nvkm_object *parent = oclass->parent;
struct gf119_dmaobj *dmaobj;
u32 kind, page;
int ret;
if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
return -ENOMEM;
*pdmaobj = &dmaobj->base;
ret = nvkm_dmaobj_ctor(&gf119_dmaobj_func, dma, oclass,
&data, &size, &dmaobj->base);
if (ret)
return ret;
ret = -ENOSYS;
args = data;
nvif_ioctl(parent, "create gf119 dma size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent,
"create gf100 dma vers %d page %d kind %02x\n",
args->v0.version, args->v0.page, args->v0.kind);
kind = args->v0.kind;
page = args->v0.page;
} else
if (size == 0) {
if (dmaobj->base.target != NV_MEM_TARGET_VM) {
kind = GF119_DMA_V0_KIND_PITCH;
page = GF119_DMA_V0_PAGE_SP;
} else {
kind = GF119_DMA_V0_KIND_VM;
page = GF119_DMA_V0_PAGE_LP;
}
} else
return ret;
if (page > 1)
return -EINVAL;
dmaobj->flags0 = (kind << 20) | (page << 6);
switch (dmaobj->base.target) {
case NV_MEM_TARGET_VRAM:
dmaobj->flags0 |= 0x00000009;
break;
case NV_MEM_TARGET_VM:
case NV_MEM_TARGET_PCI:
case NV_MEM_TARGET_PCI_NOSNOOP:
break;
default:
return -EINVAL;
}
return 0;
}
