static void
nv44_vm_fill(struct nvkm_memory *pgt, dma_addr_t null,
dma_addr_t *list, u32 pte, u32 cnt)
{
u32 base = (pte << 2) & ~0x0000000f;
u32 tmp[4];
tmp[0] = nvkm_ro32(pgt, base + 0x0);
tmp[1] = nvkm_ro32(pgt, base + 0x4);
tmp[2] = nvkm_ro32(pgt, base + 0x8);
tmp[3] = nvkm_ro32(pgt, base + 0xc);
while (cnt--) {
u32 addr = list ? (*list++ >> 12) : (null >> 12);
switch (pte++ & 0x3) {
case 0:
tmp[0] &= ~0x07ffffff;
tmp[0] |= addr;
break;
case 1:
tmp[0] &= ~0xf8000000;
tmp[0] |= addr << 27;
tmp[1] &= ~0x003fffff;
tmp[1] |= addr >> 5;
break;
case 2:
tmp[1] &= ~0xffc00000;
tmp[1] |= addr << 22;
tmp[2] &= ~0x0001ffff;
tmp[2] |= addr >> 10;
break;
case 3:
tmp[2] &= ~0xfffe0000;
tmp[2] |= addr << 17;
tmp[3] &= ~0x00000fff;
tmp[3] |= addr >> 15;
break;
}
}
nvkm_wo32(pgt, base + 0x0, tmp[0]);
nvkm_wo32(pgt, base + 0x4, tmp[1]);
nvkm_wo32(pgt, base + 0x8, tmp[2]);
nvkm_wo32(pgt, base + 0xc, tmp[3] | 0x40000000);
}
static void
nv44_vm_map_sg(struct nvkm_vma *vma, struct nvkm_memory *pgt,
struct nvkm_mem *mem, u32 pte, u32 cnt, dma_addr_t *list)
{
struct nv04_mmu *mmu = nv04_mmu(vma->vm->mmu);
u32 tmp[4];
int i;
nvkm_kmap(pgt);
if (pte & 3) {
u32 max = 4 - (pte & 3);
u32 part = (cnt > max) ? max : cnt;
nv44_vm_fill(pgt, mmu->null, list, pte, part);
pte += part;
list += part;
cnt -= part;
}
while (cnt >= 4) {
for (i = 0; i < 4; i++)
tmp[i] = *list++ >> 12;
nvkm_wo32(pgt, pte++ * 4, tmp[0] >> 0 | tmp[1] << 27);
nvkm_wo32(pgt, pte++ * 4, tmp[1] >> 5 | tmp[2] << 22);
nvkm_wo32(pgt, pte++ * 4, tmp[2] >> 10 | tmp[3] << 17);
nvkm_wo32(pgt, pte++ * 4, tmp[3] >> 15 | 0x40000000);
cnt -= 4;
}
if (cnt)
nv44_vm_fill(pgt, mmu->null, list, pte, cnt);
nvkm_done(pgt);
}
static void
nv44_vm_unmap(struct nvkm_vma *vma, struct nvkm_memory *pgt, u32 pte, u32 cnt)
{
struct nv04_mmu *mmu = nv04_mmu(vma->vm->mmu);
nvkm_kmap(pgt);
if (pte & 3) {
u32 max = 4 - (pte & 3);
u32 part = (cnt > max) ? max : cnt;
nv44_vm_fill(pgt, mmu->null, NULL, pte, part);
pte += part;
cnt -= part;
}
while (cnt >= 4) {
nvkm_wo32(pgt, pte++ * 4, 0x00000000);
nvkm_wo32(pgt, pte++ * 4, 0x00000000);
nvkm_wo32(pgt, pte++ * 4, 0x00000000);
nvkm_wo32(pgt, pte++ * 4, 0x00000000);
cnt -= 4;
}
if (cnt)
nv44_vm_fill(pgt, mmu->null, NULL, pte, cnt);
nvkm_done(pgt);
}
static void
nv44_vm_flush(struct nvkm_vm *vm)
{
struct nv04_mmu *mmu = nv04_mmu(vm->mmu);
struct nvkm_device *device = mmu->base.subdev.device;
nvkm_wr32(device, 0x100814, mmu->base.limit - NV44_GART_PAGE);
nvkm_wr32(device, 0x100808, 0x00000020);
nvkm_msec(device, 2000,
if (nvkm_rd32(device, 0x100808) & 0x00000001)
break;
);
nvkm_wr32(device, 0x100808, 0x00000000);
}
static int
nv44_mmu_oneinit(struct nvkm_mmu *base)
{
struct nv04_mmu *mmu = nv04_mmu(base);
struct nvkm_device *device = mmu->base.subdev.device;
int ret;
mmu->nullp = dma_alloc_coherent(device->dev, 16 * 1024,
&mmu->null, GFP_KERNEL);
if (!mmu->nullp) {
nvkm_warn(&mmu->base.subdev, "unable to allocate dummy pages\n");
mmu->null = 0;
}
ret = nvkm_vm_create(&mmu->base, 0, NV44_GART_SIZE, 0, 4096, NULL,
&mmu->vm);
if (ret)
return ret;
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST,
(NV44_GART_SIZE / NV44_GART_PAGE) * 4,
512 * 1024, true,
&mmu->vm->pgt[0].mem[0]);
mmu->vm->pgt[0].refcount[0] = 1;
return ret;
}
static void
nv44_mmu_init(struct nvkm_mmu *base)
{
struct nv04_mmu *mmu = nv04_mmu(base);
struct nvkm_device *device = mmu->base.subdev.device;
struct nvkm_memory *gart = mmu->vm->pgt[0].mem[0];
u32 addr;
addr = nvkm_rd32(device, 0x10020c);
addr -= ((nvkm_memory_addr(gart) >> 19) + 1) << 19;
nvkm_wr32(device, 0x100850, 0x80000000);
nvkm_wr32(device, 0x100818, mmu->null);
nvkm_wr32(device, 0x100804, NV44_GART_SIZE);
nvkm_wr32(device, 0x100850, 0x00008000);
nvkm_mask(device, 0x10008c, 0x00000200, 0x00000200);
nvkm_wr32(device, 0x100820, 0x00000000);
nvkm_wr32(device, 0x10082c, 0x00000001);
nvkm_wr32(device, 0x100800, addr | 0x00000010);
}
int
nv44_mmu_new(struct nvkm_device *device, int index, struct nvkm_mmu **pmmu)
{
if (device->type == NVKM_DEVICE_AGP ||
!nvkm_boolopt(device->cfgopt, "NvPCIE", true))
return nv04_mmu_new(device, index, pmmu);
return nv04_mmu_new_(&nv44_mmu, device, index, pmmu);
}
