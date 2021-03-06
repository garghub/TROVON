int
nouveau_abi16_ioctl_getparam(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct drm_nouveau_getparam *getparam = data;
switch (getparam->param) {
case NOUVEAU_GETPARAM_CHIPSET_ID:
getparam->value = dev_priv->chipset;
break;
case NOUVEAU_GETPARAM_PCI_VENDOR:
getparam->value = dev->pci_vendor;
break;
case NOUVEAU_GETPARAM_PCI_DEVICE:
getparam->value = dev->pci_device;
break;
case NOUVEAU_GETPARAM_BUS_TYPE:
if (drm_pci_device_is_agp(dev))
getparam->value = 0;
else
if (!pci_is_pcie(dev->pdev))
getparam->value = 1;
else
getparam->value = 2;
break;
case NOUVEAU_GETPARAM_FB_SIZE:
getparam->value = dev_priv->fb_available_size;
break;
case NOUVEAU_GETPARAM_AGP_SIZE:
getparam->value = dev_priv->gart_info.aper_size;
break;
case NOUVEAU_GETPARAM_VM_VRAM_BASE:
getparam->value = 0;
break;
case NOUVEAU_GETPARAM_PTIMER_TIME:
getparam->value = dev_priv->engine.timer.read(dev);
break;
case NOUVEAU_GETPARAM_HAS_BO_USAGE:
getparam->value = 1;
break;
case NOUVEAU_GETPARAM_HAS_PAGEFLIP:
getparam->value = 1;
break;
case NOUVEAU_GETPARAM_GRAPH_UNITS:
if (dev_priv->chipset >= 0x40) {
getparam->value = nv_rd32(dev, NV40_PMC_GRAPH_UNITS);
break;
}
default:
NV_DEBUG(dev, "unknown parameter %lld\n", getparam->param);
return -EINVAL;
}
return 0;
}
int
nouveau_abi16_ioctl_setparam(ABI16_IOCTL_ARGS)
{
return -EINVAL;
}
int
nouveau_abi16_ioctl_channel_alloc(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct drm_nouveau_channel_alloc *init = data;
struct nouveau_channel *chan;
int ret;
if (!dev_priv->eng[NVOBJ_ENGINE_GR])
return -ENODEV;
if (init->fb_ctxdma_handle == ~0 || init->tt_ctxdma_handle == ~0)
return -EINVAL;
ret = nouveau_channel_alloc(dev, &chan, file_priv,
init->fb_ctxdma_handle,
init->tt_ctxdma_handle);
if (ret)
return ret;
init->channel = chan->id;
if (nouveau_vram_pushbuf == 0) {
if (chan->dma.ib_max)
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM |
NOUVEAU_GEM_DOMAIN_GART;
else if (chan->pushbuf_bo->bo.mem.mem_type == TTM_PL_VRAM)
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM;
else
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_GART;
} else {
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM;
}
if (dev_priv->card_type < NV_C0) {
init->subchan[0].handle = 0x00000000;
init->subchan[0].grclass = 0x0000;
init->subchan[1].handle = NvSw;
init->subchan[1].grclass = NV_SW;
init->nr_subchan = 2;
}
ret = drm_gem_handle_create(file_priv, chan->notifier_bo->gem,
&init->notifier_handle);
if (ret == 0)
atomic_inc(&chan->users);
nouveau_channel_put(&chan);
return ret;
}
int
nouveau_abi16_ioctl_channel_free(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_channel_free *req = data;
struct nouveau_channel *chan;
chan = nouveau_channel_get(file_priv, req->channel);
if (IS_ERR(chan))
return PTR_ERR(chan);
list_del(&chan->list);
atomic_dec(&chan->users);
nouveau_channel_put(&chan);
return 0;
}
int
nouveau_abi16_ioctl_grobj_alloc(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_grobj_alloc *init = data;
struct nouveau_channel *chan;
int ret;
if (init->handle == ~0)
return -EINVAL;
if (init->class == 0x506e) {
init->class = nouveau_software_class(dev);
if (init->class == 0x906e)
return 0;
} else
if (init->class == 0x906e) {
NV_DEBUG(dev, "906e not supported yet\n");
return -EINVAL;
}
chan = nouveau_channel_get(file_priv, init->channel);
if (IS_ERR(chan))
return PTR_ERR(chan);
if (nouveau_ramht_find(chan, init->handle)) {
ret = -EEXIST;
goto out;
}
ret = nouveau_gpuobj_gr_new(chan, init->handle, init->class);
if (ret) {
NV_ERROR(dev, "Error creating object: %d (%d/0x%08x)\n",
ret, init->channel, init->handle);
}
out:
nouveau_channel_put(&chan);
return ret;
}
int
nouveau_abi16_ioctl_notifierobj_alloc(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct drm_nouveau_notifierobj_alloc *na = data;
struct nouveau_channel *chan;
int ret;
if (unlikely(dev_priv->card_type >= NV_C0))
return -EINVAL;
chan = nouveau_channel_get(file_priv, na->channel);
if (IS_ERR(chan))
return PTR_ERR(chan);
ret = nouveau_notifier_alloc(chan, na->handle, na->size, 0, 0x1000,
&na->offset);
nouveau_channel_put(&chan);
return ret;
}
int
nouveau_abi16_ioctl_gpuobj_free(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_gpuobj_free *objfree = data;
struct nouveau_channel *chan;
int ret;
chan = nouveau_channel_get(file_priv, objfree->channel);
if (IS_ERR(chan))
return PTR_ERR(chan);
nouveau_channel_idle(chan);
ret = nouveau_ramht_remove(chan, objfree->handle);
nouveau_channel_put(&chan);
return ret;
}
