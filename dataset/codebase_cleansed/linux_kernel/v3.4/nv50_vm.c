void
nv50_vm_map_pgt(struct nouveau_gpuobj *pgd, u32 pde,
struct nouveau_gpuobj *pgt[2])
{
u64 phys = 0xdeadcafe00000000ULL;
u32 coverage = 0;
if (pgt[0]) {
phys = 0x00000003 | pgt[0]->vinst;
coverage = (pgt[0]->size >> 3) << 12;
} else
if (pgt[1]) {
phys = 0x00000001 | pgt[1]->vinst;
coverage = (pgt[1]->size >> 3) << 16;
}
if (phys & 1) {
if (coverage <= 32 * 1024 * 1024)
phys |= 0x60;
else if (coverage <= 64 * 1024 * 1024)
phys |= 0x40;
else if (coverage <= 128 * 1024 * 1024)
phys |= 0x20;
}
nv_wo32(pgd, (pde * 8) + 0, lower_32_bits(phys));
nv_wo32(pgd, (pde * 8) + 4, upper_32_bits(phys));
}
static inline u64
vm_addr(struct nouveau_vma *vma, u64 phys, u32 memtype, u32 target)
{
phys |= 1;
phys |= (u64)memtype << 40;
phys |= target << 4;
if (vma->access & NV_MEM_ACCESS_SYS)
phys |= (1 << 6);
if (!(vma->access & NV_MEM_ACCESS_WO))
phys |= (1 << 3);
return phys;
}
void
nv50_vm_map(struct nouveau_vma *vma, struct nouveau_gpuobj *pgt,
struct nouveau_mem *mem, u32 pte, u32 cnt, u64 phys, u64 delta)
{
struct drm_nouveau_private *dev_priv = vma->vm->dev->dev_private;
u32 comp = (mem->memtype & 0x180) >> 7;
u32 block, target;
int i;
target = 0;
if (dev_priv->vram_sys_base) {
phys += dev_priv->vram_sys_base;
target = 3;
}
phys = vm_addr(vma, phys, mem->memtype, target);
pte <<= 3;
cnt <<= 3;
while (cnt) {
u32 offset_h = upper_32_bits(phys);
u32 offset_l = lower_32_bits(phys);
for (i = 7; i >= 0; i--) {
block = 1 << (i + 3);
if (cnt >= block && !(pte & (block - 1)))
break;
}
offset_l |= (i << 7);
phys += block << (vma->node->type - 3);
cnt -= block;
if (comp) {
u32 tag = mem->tag->start + ((delta >> 16) * comp);
offset_h |= (tag << 17);
delta += block << (vma->node->type - 3);
}
while (block) {
nv_wo32(pgt, pte + 0, offset_l);
nv_wo32(pgt, pte + 4, offset_h);
pte += 8;
block -= 8;
}
}
}
void
nv50_vm_map_sg(struct nouveau_vma *vma, struct nouveau_gpuobj *pgt,
struct nouveau_mem *mem, u32 pte, u32 cnt, dma_addr_t *list)
{
u32 target = (vma->access & NV_MEM_ACCESS_NOSNOOP) ? 3 : 2;
pte <<= 3;
while (cnt--) {
u64 phys = vm_addr(vma, (u64)*list++, mem->memtype, target);
nv_wo32(pgt, pte + 0, lower_32_bits(phys));
nv_wo32(pgt, pte + 4, upper_32_bits(phys));
pte += 8;
}
}
void
nv50_vm_unmap(struct nouveau_gpuobj *pgt, u32 pte, u32 cnt)
{
pte <<= 3;
while (cnt--) {
nv_wo32(pgt, pte + 0, 0x00000000);
nv_wo32(pgt, pte + 4, 0x00000000);
pte += 8;
}
}
void
nv50_vm_flush(struct nouveau_vm *vm)
{
struct drm_nouveau_private *dev_priv = vm->dev->dev_private;
struct nouveau_instmem_engine *pinstmem = &dev_priv->engine.instmem;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
int i;
pinstmem->flush(vm->dev);
if (vm == dev_priv->bar1_vm || vm == dev_priv->bar3_vm) {
nv50_vm_flush_engine(vm->dev, 6);
return;
}
pfifo->tlb_flush(vm->dev);
for (i = 0; i < NVOBJ_ENGINE_NR; i++) {
if (atomic_read(&vm->engref[i]))
dev_priv->eng[i]->tlb_flush(vm->dev, i);
}
}
void
nv50_vm_flush_engine(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->vm_lock, flags);
nv_wr32(dev, 0x100c80, (engine << 16) | 1);
if (!nv_wait(dev, 0x100c80, 0x00000001, 0x00000000))
NV_ERROR(dev, "vm flush timeout: engine %d\n", engine);
spin_unlock_irqrestore(&dev_priv->vm_lock, flags);
}
