static int
gf100_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
struct gf100_dmaobj *dmaobj = gf100_dmaobj(base);
struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
int ret;
ret = nvkm_gpuobj_new(device, 24, align, false, parent, pgpuobj);
if (ret == 0) {
nvkm_kmap(*pgpuobj);
nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0);
nvkm_wo32(*pgpuobj, 0x04, lower_32_bits(dmaobj->base.limit));
nvkm_wo32(*pgpuobj, 0x08, lower_32_bits(dmaobj->base.start));
nvkm_wo32(*pgpuobj, 0x0c, upper_32_bits(dmaobj->base.limit) << 24 |
upper_32_bits(dmaobj->base.start));
nvkm_wo32(*pgpuobj, 0x10, 0x00000000);
nvkm_wo32(*pgpuobj, 0x14, dmaobj->flags5);
nvkm_done(*pgpuobj);
}
return ret;
}
int
gf100_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
union {
struct gf100_dma_v0 v0;
} *args;
struct nvkm_object *parent = oclass->parent;
struct gf100_dmaobj *dmaobj;
u32 kind, user, unkn;
int ret;
if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
return -ENOMEM;
*pdmaobj = &dmaobj->base;
ret = nvkm_dmaobj_ctor(&gf100_dmaobj_func, dma, oclass,
&data, &size, &dmaobj->base);
if (ret)
return ret;
ret = -ENOSYS;
args = data;
nvif_ioctl(parent, "create gf100 dma size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent,
"create gf100 dma vers %d priv %d kind %02x\n",
args->v0.version, args->v0.priv, args->v0.kind);
kind = args->v0.kind;
user = args->v0.priv;
unkn = 0;
} else
if (size == 0) {
if (dmaobj->base.target != NV_MEM_TARGET_VM) {
kind = GF100_DMA_V0_KIND_PITCH;
user = GF100_DMA_V0_PRIV_US;
unkn = 2;
} else {
kind = GF100_DMA_V0_KIND_VM;
user = GF100_DMA_V0_PRIV_VM;
unkn = 0;
}
} else
return ret;
if (user > 2)
return -EINVAL;
dmaobj->flags0 |= (kind << 22) | (user << 20) | oclass->base.oclass;
dmaobj->flags5 |= (unkn << 16);
switch (dmaobj->base.target) {
case NV_MEM_TARGET_VM:
dmaobj->flags0 |= 0x00000000;
break;
case NV_MEM_TARGET_VRAM:
dmaobj->flags0 |= 0x00010000;
break;
case NV_MEM_TARGET_PCI:
dmaobj->flags0 |= 0x00020000;
break;
case NV_MEM_TARGET_PCI_NOSNOOP:
dmaobj->flags0 |= 0x00030000;
break;
default:
return -EINVAL;
}
switch (dmaobj->base.access) {
case NV_MEM_ACCESS_VM:
break;
case NV_MEM_ACCESS_RO:
dmaobj->flags0 |= 0x00040000;
break;
case NV_MEM_ACCESS_WO:
case NV_MEM_ACCESS_RW:
dmaobj->flags0 |= 0x00080000;
break;
}
return 0;
}
