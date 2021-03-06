static struct nouveau_abi16 *
nouveau_abi16(struct drm_file *file_priv)
{
struct nouveau_cli *cli = nouveau_cli(file_priv);
if (!cli->abi16) {
struct nouveau_abi16 *abi16;
cli->abi16 = abi16 = kzalloc(sizeof(*abi16), GFP_KERNEL);
if (cli->abi16) {
struct nv_device_v0 args = {
.device = ~0ULL,
};
INIT_LIST_HEAD(&abi16->channels);
if (nvif_device_init(&cli->base.object, 0, NV_DEVICE,
&args, sizeof(args),
&abi16->device) == 0)
return cli->abi16;
kfree(cli->abi16);
cli->abi16 = NULL;
}
}
return cli->abi16;
}
struct nouveau_abi16 *
nouveau_abi16_get(struct drm_file *file_priv)
{
struct nouveau_cli *cli = nouveau_cli(file_priv);
mutex_lock(&cli->mutex);
if (nouveau_abi16(file_priv))
return cli->abi16;
mutex_unlock(&cli->mutex);
return NULL;
}
int
nouveau_abi16_put(struct nouveau_abi16 *abi16, int ret)
{
struct nouveau_cli *cli = (void *)abi16->device.object.client;
mutex_unlock(&cli->mutex);
return ret;
}
s32
nouveau_abi16_swclass(struct nouveau_drm *drm)
{
switch (drm->device.info.family) {
case NV_DEVICE_INFO_V0_TNT:
return NVIF_CLASS_SW_NV04;
case NV_DEVICE_INFO_V0_CELSIUS:
case NV_DEVICE_INFO_V0_KELVIN:
case NV_DEVICE_INFO_V0_RANKINE:
case NV_DEVICE_INFO_V0_CURIE:
return NVIF_CLASS_SW_NV10;
case NV_DEVICE_INFO_V0_TESLA:
return NVIF_CLASS_SW_NV50;
case NV_DEVICE_INFO_V0_FERMI:
case NV_DEVICE_INFO_V0_KEPLER:
case NV_DEVICE_INFO_V0_MAXWELL:
return NVIF_CLASS_SW_GF100;
}
return 0x0000;
}
static void
nouveau_abi16_ntfy_fini(struct nouveau_abi16_chan *chan,
struct nouveau_abi16_ntfy *ntfy)
{
nvif_object_fini(&ntfy->object);
nvkm_mm_free(&chan->heap, &ntfy->node);
list_del(&ntfy->head);
kfree(ntfy);
}
static void
nouveau_abi16_chan_fini(struct nouveau_abi16 *abi16,
struct nouveau_abi16_chan *chan)
{
struct nouveau_abi16_ntfy *ntfy, *temp;
if (chan->chan && chan->ntfy)
nouveau_channel_idle(chan->chan);
list_for_each_entry_safe(ntfy, temp, &chan->notifiers, head) {
nouveau_abi16_ntfy_fini(chan, ntfy);
}
if (chan->ntfy) {
nouveau_bo_vma_del(chan->ntfy, &chan->ntfy_vma);
nouveau_bo_unpin(chan->ntfy);
drm_gem_object_unreference_unlocked(&chan->ntfy->gem);
}
if (chan->heap.block_size)
nvkm_mm_fini(&chan->heap);
if (chan->chan) {
nouveau_channel_idle(chan->chan);
nouveau_channel_del(&chan->chan);
}
list_del(&chan->head);
kfree(chan);
}
void
nouveau_abi16_fini(struct nouveau_abi16 *abi16)
{
struct nouveau_cli *cli = (void *)abi16->device.object.client;
struct nouveau_abi16_chan *chan, *temp;
list_for_each_entry_safe(chan, temp, &abi16->channels, head) {
nouveau_abi16_chan_fini(abi16, chan);
}
nvif_device_fini(&abi16->device);
kfree(cli->abi16);
cli->abi16 = NULL;
}
int
nouveau_abi16_ioctl_getparam(ABI16_IOCTL_ARGS)
{
struct nouveau_cli *cli = nouveau_cli(file_priv);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_device *device = &drm->device;
struct nvkm_gr *gr = nvxx_gr(device);
struct drm_nouveau_getparam *getparam = data;
switch (getparam->param) {
case NOUVEAU_GETPARAM_CHIPSET_ID:
getparam->value = device->info.chipset;
break;
case NOUVEAU_GETPARAM_PCI_VENDOR:
if (nvxx_device(device)->func->pci)
getparam->value = dev->pdev->vendor;
else
getparam->value = 0;
break;
case NOUVEAU_GETPARAM_PCI_DEVICE:
if (nvxx_device(device)->func->pci)
getparam->value = dev->pdev->device;
else
getparam->value = 0;
break;
case NOUVEAU_GETPARAM_BUS_TYPE:
if (!nvxx_device(device)->func->pci)
getparam->value = 3;
else
if (drm_pci_device_is_agp(dev))
getparam->value = 0;
else
if (!pci_is_pcie(dev->pdev))
getparam->value = 1;
else
getparam->value = 2;
break;
case NOUVEAU_GETPARAM_FB_SIZE:
getparam->value = drm->gem.vram_available;
break;
case NOUVEAU_GETPARAM_AGP_SIZE:
getparam->value = drm->gem.gart_available;
break;
case NOUVEAU_GETPARAM_VM_VRAM_BASE:
getparam->value = 0;
break;
case NOUVEAU_GETPARAM_PTIMER_TIME:
getparam->value = nvif_device_time(device);
break;
case NOUVEAU_GETPARAM_HAS_BO_USAGE:
getparam->value = 1;
break;
case NOUVEAU_GETPARAM_HAS_PAGEFLIP:
getparam->value = 1;
break;
case NOUVEAU_GETPARAM_GRAPH_UNITS:
getparam->value = nvkm_gr_units(gr);
break;
default:
NV_PRINTK(dbg, cli, "unknown parameter %lld\n", getparam->param);
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
struct drm_nouveau_channel_alloc *init = data;
struct nouveau_cli *cli = nouveau_cli(file_priv);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_abi16 *abi16 = nouveau_abi16_get(file_priv);
struct nouveau_abi16_chan *chan;
struct nvif_device *device;
int ret;
if (unlikely(!abi16))
return -ENOMEM;
if (!drm->channel)
return nouveau_abi16_put(abi16, -ENODEV);
device = &abi16->device;
if (device->info.family >= NV_DEVICE_INFO_V0_KEPLER) {
if (init->fb_ctxdma_handle != ~0)
init->fb_ctxdma_handle = KEPLER_CHANNEL_GPFIFO_A_V0_ENGINE_GR;
else
init->fb_ctxdma_handle = init->tt_ctxdma_handle;
init->tt_ctxdma_handle = 0;
if (init->fb_ctxdma_handle == KEPLER_CHANNEL_GPFIFO_A_V0_ENGINE_GR)
init->tt_ctxdma_handle = 1;
}
if (init->fb_ctxdma_handle == ~0 || init->tt_ctxdma_handle == ~0)
return nouveau_abi16_put(abi16, -EINVAL);
chan = kzalloc(sizeof(*chan), GFP_KERNEL);
if (!chan)
return nouveau_abi16_put(abi16, -ENOMEM);
INIT_LIST_HEAD(&chan->notifiers);
list_add(&chan->head, &abi16->channels);
ret = nouveau_channel_new(drm, device, init->fb_ctxdma_handle,
init->tt_ctxdma_handle, &chan->chan);
if (ret)
goto done;
init->channel = chan->chan->chid;
if (device->info.family >= NV_DEVICE_INFO_V0_TESLA)
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM |
NOUVEAU_GEM_DOMAIN_GART;
else
if (chan->chan->push.buffer->bo.mem.mem_type == TTM_PL_VRAM)
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM;
else
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_GART;
if (device->info.family < NV_DEVICE_INFO_V0_CELSIUS) {
init->subchan[0].handle = 0x00000000;
init->subchan[0].grclass = 0x0000;
init->subchan[1].handle = chan->chan->nvsw.handle;
init->subchan[1].grclass = 0x506e;
init->nr_subchan = 2;
}
ret = nouveau_gem_new(dev, PAGE_SIZE, 0, NOUVEAU_GEM_DOMAIN_GART,
0, 0, &chan->ntfy);
if (ret == 0)
ret = nouveau_bo_pin(chan->ntfy, TTM_PL_FLAG_TT, false);
if (ret)
goto done;
if (device->info.family >= NV_DEVICE_INFO_V0_TESLA) {
ret = nouveau_bo_vma_add(chan->ntfy, cli->vm,
&chan->ntfy_vma);
if (ret)
goto done;
}
ret = drm_gem_handle_create(file_priv, &chan->ntfy->gem,
&init->notifier_handle);
if (ret)
goto done;
ret = nvkm_mm_init(&chan->heap, 0, PAGE_SIZE, 1);
done:
if (ret)
nouveau_abi16_chan_fini(abi16, chan);
return nouveau_abi16_put(abi16, ret);
}
static struct nouveau_abi16_chan *
nouveau_abi16_chan(struct nouveau_abi16 *abi16, int channel)
{
struct nouveau_abi16_chan *chan;
list_for_each_entry(chan, &abi16->channels, head) {
if (chan->chan->chid == channel)
return chan;
}
return NULL;
}
int
nouveau_abi16_usif(struct drm_file *file_priv, void *data, u32 size)
{
union {
struct nvif_ioctl_v0 v0;
} *args = data;
struct nouveau_abi16_chan *chan;
struct nouveau_abi16 *abi16;
int ret = -ENOSYS;
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, true))) {
switch (args->v0.type) {
case NVIF_IOCTL_V0_NEW:
case NVIF_IOCTL_V0_MTHD:
case NVIF_IOCTL_V0_SCLASS:
break;
default:
return -EACCES;
}
} else
return ret;
if (!(abi16 = nouveau_abi16(file_priv)))
return -ENOMEM;
if (args->v0.token != ~0ULL) {
if (!(chan = nouveau_abi16_chan(abi16, args->v0.token)))
return -EINVAL;
args->v0.object = nvif_handle(&chan->chan->user);
args->v0.owner = NVIF_IOCTL_V0_OWNER_ANY;
return 0;
}
args->v0.object = nvif_handle(&abi16->device.object);
args->v0.owner = NVIF_IOCTL_V0_OWNER_ANY;
return 0;
}
int
nouveau_abi16_ioctl_channel_free(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_channel_free *req = data;
struct nouveau_abi16 *abi16 = nouveau_abi16_get(file_priv);
struct nouveau_abi16_chan *chan;
if (unlikely(!abi16))
return -ENOMEM;
chan = nouveau_abi16_chan(abi16, req->channel);
if (!chan)
return nouveau_abi16_put(abi16, -ENOENT);
nouveau_abi16_chan_fini(abi16, chan);
return nouveau_abi16_put(abi16, 0);
}
int
nouveau_abi16_ioctl_grobj_alloc(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_grobj_alloc *init = data;
struct nouveau_abi16 *abi16 = nouveau_abi16_get(file_priv);
struct nouveau_abi16_chan *chan;
struct nouveau_abi16_ntfy *ntfy;
struct nvif_client *client;
struct nvif_sclass *sclass;
s32 oclass = 0;
int ret, i;
if (unlikely(!abi16))
return -ENOMEM;
if (init->handle == ~0)
return nouveau_abi16_put(abi16, -EINVAL);
client = abi16->device.object.client;
chan = nouveau_abi16_chan(abi16, init->channel);
if (!chan)
return nouveau_abi16_put(abi16, -ENOENT);
ret = nvif_object_sclass_get(&chan->chan->user, &sclass);
if (ret < 0)
return nouveau_abi16_put(abi16, ret);
if ((init->class & 0x00ff) == 0x006e) {
for (i = 0; !oclass && i < ret; i++) {
switch (sclass[i].oclass) {
case NVIF_CLASS_SW_NV04:
case NVIF_CLASS_SW_NV10:
case NVIF_CLASS_SW_NV50:
case NVIF_CLASS_SW_GF100:
oclass = sclass[i].oclass;
break;
default:
break;
}
}
} else
if ((init->class & 0x00ff) == 0x00b1) {
for (i = 0; i < ret; i++) {
if ((sclass[i].oclass & 0x00ff) == 0x00b1) {
oclass = sclass[i].oclass;
break;
}
}
} else
if ((init->class & 0x00ff) == 0x00b2) {
for (i = 0; i < ret; i++) {
if ((sclass[i].oclass & 0x00ff) == 0x00b2) {
oclass = sclass[i].oclass;
break;
}
}
} else
if ((init->class & 0x00ff) == 0x00b3) {
for (i = 0; i < ret; i++) {
if ((sclass[i].oclass & 0x00ff) == 0x00b3) {
oclass = sclass[i].oclass;
break;
}
}
} else {
oclass = init->class;
}
nvif_object_sclass_put(&sclass);
if (!oclass)
return nouveau_abi16_put(abi16, -EINVAL);
ntfy = kzalloc(sizeof(*ntfy), GFP_KERNEL);
if (!ntfy)
return nouveau_abi16_put(abi16, -ENOMEM);
list_add(&ntfy->head, &chan->notifiers);
client->route = NVDRM_OBJECT_ABI16;
ret = nvif_object_init(&chan->chan->user, init->handle, oclass,
NULL, 0, &ntfy->object);
client->route = NVDRM_OBJECT_NVIF;
if (ret)
nouveau_abi16_ntfy_fini(chan, ntfy);
return nouveau_abi16_put(abi16, ret);
}
int
nouveau_abi16_ioctl_notifierobj_alloc(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_notifierobj_alloc *info = data;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_abi16 *abi16 = nouveau_abi16_get(file_priv);
struct nouveau_abi16_chan *chan;
struct nouveau_abi16_ntfy *ntfy;
struct nvif_device *device = &abi16->device;
struct nvif_client *client;
struct nv_dma_v0 args = {};
int ret;
if (unlikely(!abi16))
return -ENOMEM;
if (unlikely(device->info.family >= NV_DEVICE_INFO_V0_FERMI))
return nouveau_abi16_put(abi16, -EINVAL);
client = abi16->device.object.client;
chan = nouveau_abi16_chan(abi16, info->channel);
if (!chan)
return nouveau_abi16_put(abi16, -ENOENT);
ntfy = kzalloc(sizeof(*ntfy), GFP_KERNEL);
if (!ntfy)
return nouveau_abi16_put(abi16, -ENOMEM);
list_add(&ntfy->head, &chan->notifiers);
ret = nvkm_mm_head(&chan->heap, 0, 1, info->size, info->size, 1,
&ntfy->node);
if (ret)
goto done;
args.start = ntfy->node->offset;
args.limit = ntfy->node->offset + ntfy->node->length - 1;
if (device->info.family >= NV_DEVICE_INFO_V0_TESLA) {
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_VM;
args.start += chan->ntfy_vma.offset;
args.limit += chan->ntfy_vma.offset;
} else
if (drm->agp.bridge) {
args.target = NV_DMA_V0_TARGET_AGP;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start += drm->agp.base + chan->ntfy->bo.offset;
args.limit += drm->agp.base + chan->ntfy->bo.offset;
} else {
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start += chan->ntfy->bo.offset;
args.limit += chan->ntfy->bo.offset;
}
client->route = NVDRM_OBJECT_ABI16;
client->super = true;
ret = nvif_object_init(&chan->chan->user, info->handle,
NV_DMA_IN_MEMORY, &args, sizeof(args),
&ntfy->object);
client->super = false;
client->route = NVDRM_OBJECT_NVIF;
if (ret)
goto done;
info->offset = ntfy->node->offset;
done:
if (ret)
nouveau_abi16_ntfy_fini(chan, ntfy);
return nouveau_abi16_put(abi16, ret);
}
int
nouveau_abi16_ioctl_gpuobj_free(ABI16_IOCTL_ARGS)
{
struct drm_nouveau_gpuobj_free *fini = data;
struct nouveau_abi16 *abi16 = nouveau_abi16_get(file_priv);
struct nouveau_abi16_chan *chan;
struct nouveau_abi16_ntfy *ntfy;
int ret = -ENOENT;
if (unlikely(!abi16))
return -ENOMEM;
chan = nouveau_abi16_chan(abi16, fini->channel);
if (!chan)
return nouveau_abi16_put(abi16, -EINVAL);
nouveau_channel_idle(chan->chan);
list_for_each_entry(ntfy, &chan->notifiers, head) {
if (ntfy->object.handle == fini->handle) {
nouveau_abi16_ntfy_fini(chan, ntfy);
ret = 0;
break;
}
}
return nouveau_abi16_put(abi16, ret);
}
