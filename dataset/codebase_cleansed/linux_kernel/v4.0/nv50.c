static int
nv50_bar_kmap(struct nvkm_bar *bar, struct nvkm_mem *mem, u32 flags,
struct nvkm_vma *vma)
{
struct nv50_bar_priv *priv = (void *)bar;
int ret;
ret = nvkm_vm_get(priv->bar3_vm, mem->size << 12, 12, flags, vma);
if (ret)
return ret;
nvkm_vm_map(vma, mem);
return 0;
}
static int
nv50_bar_umap(struct nvkm_bar *bar, struct nvkm_mem *mem, u32 flags,
struct nvkm_vma *vma)
{
struct nv50_bar_priv *priv = (void *)bar;
int ret;
ret = nvkm_vm_get(priv->bar1_vm, mem->size << 12, 12, flags, vma);
if (ret)
return ret;
nvkm_vm_map(vma, mem);
return 0;
}
static void
nv50_bar_unmap(struct nvkm_bar *bar, struct nvkm_vma *vma)
{
nvkm_vm_unmap(vma);
nvkm_vm_put(vma);
}
static void
nv50_bar_flush(struct nvkm_bar *bar)
{
struct nv50_bar_priv *priv = (void *)bar;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
nv_wr32(priv, 0x00330c, 0x00000001);
if (!nv_wait(priv, 0x00330c, 0x00000002, 0x00000000))
nv_warn(priv, "flush timeout\n");
spin_unlock_irqrestore(&priv->lock, flags);
}
void
g84_bar_flush(struct nvkm_bar *bar)
{
struct nv50_bar_priv *priv = (void *)bar;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
nv_wr32(bar, 0x070000, 0x00000001);
if (!nv_wait(priv, 0x070000, 0x00000002, 0x00000000))
nv_warn(priv, "flush timeout\n");
spin_unlock_irqrestore(&priv->lock, flags);
}
static int
nv50_bar_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_device *device = nv_device(parent);
struct nvkm_object *heap;
struct nvkm_vm *vm;
struct nv50_bar_priv *priv;
u64 start, limit;
int ret;
ret = nvkm_bar_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), NULL, 0x20000, 0,
NVOBJ_FLAG_HEAP, &priv->mem);
heap = nv_object(priv->mem);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), heap,
(device->chipset == 0x50) ? 0x1400 : 0x0200,
0, 0, &priv->pad);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), heap, 0x4000, 0, 0, &priv->pgd);
if (ret)
return ret;
start = 0x0100000000ULL;
limit = start + nv_device_resource_len(device, 3);
ret = nvkm_vm_new(device, start, limit, start, &vm);
if (ret)
return ret;
atomic_inc(&vm->engref[NVDEV_SUBDEV_BAR]);
ret = nvkm_gpuobj_new(nv_object(priv), heap,
((limit-- - start) >> 12) * 8, 0x1000,
NVOBJ_FLAG_ZERO_ALLOC, &vm->pgt[0].obj[0]);
vm->pgt[0].refcount[0] = 1;
if (ret)
return ret;
ret = nvkm_vm_ref(vm, &priv->bar3_vm, priv->pgd);
nvkm_vm_ref(NULL, &vm, NULL);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), heap, 24, 16, 0, &priv->bar3);
if (ret)
return ret;
nv_wo32(priv->bar3, 0x00, 0x7fc00000);
nv_wo32(priv->bar3, 0x04, lower_32_bits(limit));
nv_wo32(priv->bar3, 0x08, lower_32_bits(start));
nv_wo32(priv->bar3, 0x0c, upper_32_bits(limit) << 24 |
upper_32_bits(start));
nv_wo32(priv->bar3, 0x10, 0x00000000);
nv_wo32(priv->bar3, 0x14, 0x00000000);
start = 0x0000000000ULL;
limit = start + nv_device_resource_len(device, 1);
ret = nvkm_vm_new(device, start, limit--, start, &vm);
if (ret)
return ret;
atomic_inc(&vm->engref[NVDEV_SUBDEV_BAR]);
ret = nvkm_vm_ref(vm, &priv->bar1_vm, priv->pgd);
nvkm_vm_ref(NULL, &vm, NULL);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), heap, 24, 16, 0, &priv->bar1);
if (ret)
return ret;
nv_wo32(priv->bar1, 0x00, 0x7fc00000);
nv_wo32(priv->bar1, 0x04, lower_32_bits(limit));
nv_wo32(priv->bar1, 0x08, lower_32_bits(start));
nv_wo32(priv->bar1, 0x0c, upper_32_bits(limit) << 24 |
upper_32_bits(start));
nv_wo32(priv->bar1, 0x10, 0x00000000);
nv_wo32(priv->bar1, 0x14, 0x00000000);
priv->base.alloc = nvkm_bar_alloc;
priv->base.kmap = nv50_bar_kmap;
priv->base.umap = nv50_bar_umap;
priv->base.unmap = nv50_bar_unmap;
if (device->chipset == 0x50)
priv->base.flush = nv50_bar_flush;
else
priv->base.flush = g84_bar_flush;
spin_lock_init(&priv->lock);
return 0;
}
static void
nv50_bar_dtor(struct nvkm_object *object)
{
struct nv50_bar_priv *priv = (void *)object;
nvkm_gpuobj_ref(NULL, &priv->bar1);
nvkm_vm_ref(NULL, &priv->bar1_vm, priv->pgd);
nvkm_gpuobj_ref(NULL, &priv->bar3);
if (priv->bar3_vm) {
nvkm_gpuobj_ref(NULL, &priv->bar3_vm->pgt[0].obj[0]);
nvkm_vm_ref(NULL, &priv->bar3_vm, priv->pgd);
}
nvkm_gpuobj_ref(NULL, &priv->pgd);
nvkm_gpuobj_ref(NULL, &priv->pad);
nvkm_gpuobj_ref(NULL, &priv->mem);
nvkm_bar_destroy(&priv->base);
}
static int
nv50_bar_init(struct nvkm_object *object)
{
struct nv50_bar_priv *priv = (void *)object;
int ret, i;
ret = nvkm_bar_init(&priv->base);
if (ret)
return ret;
nv_mask(priv, 0x000200, 0x00000100, 0x00000000);
nv_mask(priv, 0x000200, 0x00000100, 0x00000100);
nv_wr32(priv, 0x100c80, 0x00060001);
if (!nv_wait(priv, 0x100c80, 0x00000001, 0x00000000)) {
nv_error(priv, "vm flush timeout\n");
return -EBUSY;
}
nv_wr32(priv, 0x001704, 0x00000000 | priv->mem->addr >> 12);
nv_wr32(priv, 0x001704, 0x40000000 | priv->mem->addr >> 12);
nv_wr32(priv, 0x001708, 0x80000000 | priv->bar1->node->offset >> 4);
nv_wr32(priv, 0x00170c, 0x80000000 | priv->bar3->node->offset >> 4);
for (i = 0; i < 8; i++)
nv_wr32(priv, 0x001900 + (i * 4), 0x00000000);
return 0;
}
static int
nv50_bar_fini(struct nvkm_object *object, bool suspend)
{
struct nv50_bar_priv *priv = (void *)object;
return nvkm_bar_fini(&priv->base, suspend);
}
