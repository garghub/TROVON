static void
nv41_vm_map_sg(struct nvkm_vma *vma, struct nvkm_memory *pgt,
struct nvkm_mem *mem, u32 pte, u32 cnt, dma_addr_t *list)
{
pte = pte * 4;
nvkm_kmap(pgt);
while (cnt) {
u32 page = PAGE_SIZE / NV41_GART_PAGE;
u64 phys = (u64)*list++;
while (cnt && page--) {
nvkm_wo32(pgt, pte, (phys >> 7) | 1);
phys += NV41_GART_PAGE;
pte += 4;
cnt -= 1;
}
}
nvkm_done(pgt);
}
static void
nv41_vm_unmap(struct nvkm_vma *vma, struct nvkm_memory *pgt, u32 pte, u32 cnt)
{
pte = pte * 4;
nvkm_kmap(pgt);
while (cnt--) {
nvkm_wo32(pgt, pte, 0x00000000);
pte += 4;
}
nvkm_done(pgt);
}
static void
nv41_vm_flush(struct nvkm_vm *vm)
{
struct nv04_mmu *mmu = nv04_mmu(vm->mmu);
struct nvkm_device *device = mmu->base.subdev.device;
mutex_lock(&mmu->base.subdev.mutex);
nvkm_wr32(device, 0x100810, 0x00000022);
nvkm_msec(device, 2000,
if (nvkm_rd32(device, 0x100810) & 0x00000020)
break;
);
nvkm_wr32(device, 0x100810, 0x00000000);
mutex_unlock(&mmu->base.subdev.mutex);
}
static int
nv41_mmu_oneinit(struct nvkm_mmu *base)
{
struct nv04_mmu *mmu = nv04_mmu(base);
struct nvkm_device *device = mmu->base.subdev.device;
int ret;
ret = nvkm_vm_create(&mmu->base, 0, NV41_GART_SIZE, 0, 4096, NULL,
&mmu->vm);
if (ret)
return ret;
ret = nvkm_memory_new(device, NVKM_MEM_TARGET_INST,
(NV41_GART_SIZE / NV41_GART_PAGE) * 4, 16, true,
&mmu->vm->pgt[0].mem[0]);
mmu->vm->pgt[0].refcount[0] = 1;
return ret;
}
static void
nv41_mmu_init(struct nvkm_mmu *base)
{
struct nv04_mmu *mmu = nv04_mmu(base);
struct nvkm_device *device = mmu->base.subdev.device;
struct nvkm_memory *dma = mmu->vm->pgt[0].mem[0];
nvkm_wr32(device, 0x100800, 0x00000002 | nvkm_memory_addr(dma));
nvkm_mask(device, 0x10008c, 0x00000100, 0x00000100);
nvkm_wr32(device, 0x100820, 0x00000000);
}
int
nv41_mmu_new(struct nvkm_device *device, int index, struct nvkm_mmu **pmmu)
{
if (device->type == NVKM_DEVICE_AGP ||
!nvkm_boolopt(device->cfgopt, "NvPCIE", true))
return nv04_mmu_new(device, index, pmmu);
return nv04_mmu_new_(&nv41_mmu, device, index, pmmu);
}
