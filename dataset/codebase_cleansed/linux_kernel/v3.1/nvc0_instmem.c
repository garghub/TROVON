int
nvc0_instmem_suspend(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
dev_priv->ramin_available = false;
return 0;
}
void
nvc0_instmem_resume(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvc0_instmem_priv *priv = dev_priv->engine.instmem.priv;
nv_mask(dev, 0x100c80, 0x00000001, 0x00000000);
nv_wr32(dev, 0x001704, 0x80000000 | priv->bar1->ramin->vinst >> 12);
nv_wr32(dev, 0x001714, 0xc0000000 | priv->bar3->ramin->vinst >> 12);
dev_priv->ramin_available = true;
}
static void
nvc0_channel_del(struct nouveau_channel **pchan)
{
struct nouveau_channel *chan;
chan = *pchan;
*pchan = NULL;
if (!chan)
return;
nouveau_vm_ref(NULL, &chan->vm, NULL);
if (drm_mm_initialized(&chan->ramin_heap))
drm_mm_takedown(&chan->ramin_heap);
nouveau_gpuobj_ref(NULL, &chan->ramin);
kfree(chan);
}
static int
nvc0_channel_new(struct drm_device *dev, u32 size, struct nouveau_vm *vm,
struct nouveau_channel **pchan,
struct nouveau_gpuobj *pgd, u64 vm_size)
{
struct nouveau_channel *chan;
int ret;
chan = kzalloc(sizeof(*chan), GFP_KERNEL);
if (!chan)
return -ENOMEM;
chan->dev = dev;
ret = nouveau_gpuobj_new(dev, NULL, size, 0x1000, 0, &chan->ramin);
if (ret) {
nvc0_channel_del(&chan);
return ret;
}
ret = drm_mm_init(&chan->ramin_heap, 0x1000, size - 0x1000);
if (ret) {
nvc0_channel_del(&chan);
return ret;
}
ret = nouveau_vm_ref(vm, &chan->vm, NULL);
if (ret) {
nvc0_channel_del(&chan);
return ret;
}
nv_wo32(chan->ramin, 0x0200, lower_32_bits(pgd->vinst));
nv_wo32(chan->ramin, 0x0204, upper_32_bits(pgd->vinst));
nv_wo32(chan->ramin, 0x0208, lower_32_bits(vm_size - 1));
nv_wo32(chan->ramin, 0x020c, upper_32_bits(vm_size - 1));
*pchan = chan;
return 0;
}
int
nvc0_instmem_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_instmem_engine *pinstmem = &dev_priv->engine.instmem;
struct pci_dev *pdev = dev->pdev;
struct nvc0_instmem_priv *priv;
struct nouveau_vm *vm = NULL;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
pinstmem->priv = priv;
ret = nouveau_vm_new(dev, 0, pci_resource_len(pdev, 3), 0,
&dev_priv->bar3_vm);
if (ret)
goto error;
ret = nouveau_gpuobj_new(dev, NULL,
(pci_resource_len(pdev, 3) >> 12) * 8, 0,
NVOBJ_FLAG_DONT_MAP |
NVOBJ_FLAG_ZERO_ALLOC,
&dev_priv->bar3_vm->pgt[0].obj[0]);
if (ret)
goto error;
dev_priv->bar3_vm->pgt[0].refcount[0] = 1;
nv50_instmem_map(dev_priv->bar3_vm->pgt[0].obj[0]);
ret = nouveau_gpuobj_new(dev, NULL, 0x8000, 4096,
NVOBJ_FLAG_ZERO_ALLOC, &priv->bar3_pgd);
if (ret)
goto error;
ret = nouveau_vm_ref(dev_priv->bar3_vm, &vm, priv->bar3_pgd);
if (ret)
goto error;
nouveau_vm_ref(NULL, &vm, NULL);
ret = nvc0_channel_new(dev, 8192, dev_priv->bar3_vm, &priv->bar3,
priv->bar3_pgd, pci_resource_len(dev->pdev, 3));
if (ret)
goto error;
ret = nouveau_vm_new(dev, 0, pci_resource_len(pdev, 1), 0, &vm);
if (ret)
goto error;
ret = nouveau_gpuobj_new(dev, NULL, 0x8000, 4096,
NVOBJ_FLAG_ZERO_ALLOC, &priv->bar1_pgd);
if (ret)
goto error;
ret = nouveau_vm_ref(vm, &dev_priv->bar1_vm, priv->bar1_pgd);
if (ret)
goto error;
nouveau_vm_ref(NULL, &vm, NULL);
ret = nvc0_channel_new(dev, 8192, dev_priv->bar1_vm, &priv->bar1,
priv->bar1_pgd, pci_resource_len(dev->pdev, 1));
if (ret)
goto error;
ret = nouveau_vm_new(dev, 0, (1ULL << 40), 0x0008000000ULL,
&dev_priv->chan_vm);
if (ret)
goto error;
nvc0_instmem_resume(dev);
return 0;
error:
nvc0_instmem_takedown(dev);
return ret;
}
void
nvc0_instmem_takedown(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvc0_instmem_priv *priv = dev_priv->engine.instmem.priv;
struct nouveau_vm *vm = NULL;
nvc0_instmem_suspend(dev);
nv_wr32(dev, 0x1704, 0x00000000);
nv_wr32(dev, 0x1714, 0x00000000);
nouveau_vm_ref(NULL, &dev_priv->chan_vm, NULL);
nvc0_channel_del(&priv->bar1);
nouveau_vm_ref(NULL, &dev_priv->bar1_vm, priv->bar1_pgd);
nouveau_gpuobj_ref(NULL, &priv->bar1_pgd);
nvc0_channel_del(&priv->bar3);
nouveau_vm_ref(dev_priv->bar3_vm, &vm, NULL);
nouveau_vm_ref(NULL, &vm, priv->bar3_pgd);
nouveau_gpuobj_ref(NULL, &priv->bar3_pgd);
nouveau_gpuobj_ref(NULL, &dev_priv->bar3_vm->pgt[0].obj[0]);
nouveau_vm_ref(NULL, &dev_priv->bar3_vm, NULL);
dev_priv->engine.instmem.priv = NULL;
kfree(priv);
}
