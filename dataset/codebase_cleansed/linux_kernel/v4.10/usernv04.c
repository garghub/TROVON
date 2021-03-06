static int
nv04_dmaobj_bind(struct nvkm_dmaobj *base, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
struct nv04_dmaobj *dmaobj = nv04_dmaobj(base);
struct nvkm_device *device = dmaobj->base.dma->engine.subdev.device;
u64 offset = dmaobj->base.start & 0xfffff000;
u64 adjust = dmaobj->base.start & 0x00000fff;
u32 length = dmaobj->base.limit - dmaobj->base.start;
int ret;
if (dmaobj->clone) {
struct nv04_mmu *mmu = nv04_mmu(device->mmu);
struct nvkm_memory *pgt = mmu->vm->pgt[0].mem[0];
if (!dmaobj->base.start)
return nvkm_gpuobj_wrap(pgt, pgpuobj);
nvkm_kmap(pgt);
offset = nvkm_ro32(pgt, 8 + (offset >> 10));
offset &= 0xfffff000;
nvkm_done(pgt);
}
ret = nvkm_gpuobj_new(device, 16, align, false, parent, pgpuobj);
if (ret == 0) {
nvkm_kmap(*pgpuobj);
nvkm_wo32(*pgpuobj, 0x00, dmaobj->flags0 | (adjust << 20));
nvkm_wo32(*pgpuobj, 0x04, length);
nvkm_wo32(*pgpuobj, 0x08, dmaobj->flags2 | offset);
nvkm_wo32(*pgpuobj, 0x0c, dmaobj->flags2 | offset);
nvkm_done(*pgpuobj);
}
return ret;
}
int
nv04_dmaobj_new(struct nvkm_dma *dma, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_dmaobj **pdmaobj)
{
struct nvkm_device *device = dma->engine.subdev.device;
struct nv04_dmaobj *dmaobj;
int ret;
if (!(dmaobj = kzalloc(sizeof(*dmaobj), GFP_KERNEL)))
return -ENOMEM;
*pdmaobj = &dmaobj->base;
ret = nvkm_dmaobj_ctor(&nv04_dmaobj_func, dma, oclass,
&data, &size, &dmaobj->base);
if (ret)
return ret;
if (dmaobj->base.target == NV_MEM_TARGET_VM) {
if (device->mmu->func == &nv04_mmu)
dmaobj->clone = true;
dmaobj->base.target = NV_MEM_TARGET_PCI;
dmaobj->base.access = NV_MEM_ACCESS_RW;
}
dmaobj->flags0 = oclass->base.oclass;
switch (dmaobj->base.target) {
case NV_MEM_TARGET_VRAM:
dmaobj->flags0 |= 0x00003000;
break;
case NV_MEM_TARGET_PCI:
dmaobj->flags0 |= 0x00023000;
break;
case NV_MEM_TARGET_PCI_NOSNOOP:
dmaobj->flags0 |= 0x00033000;
break;
default:
return -EINVAL;
}
switch (dmaobj->base.access) {
case NV_MEM_ACCESS_RO:
dmaobj->flags0 |= 0x00004000;
break;
case NV_MEM_ACCESS_WO:
dmaobj->flags0 |= 0x00008000;
case NV_MEM_ACCESS_RW:
dmaobj->flags2 |= 0x00000002;
break;
default:
return -EINVAL;
}
return 0;
}
