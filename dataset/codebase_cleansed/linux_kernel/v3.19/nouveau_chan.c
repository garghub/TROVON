int
nouveau_channel_idle(struct nouveau_channel *chan)
{
struct nouveau_cli *cli = (void *)nvif_client(chan->object);
struct nouveau_fence *fence = NULL;
int ret;
ret = nouveau_fence_new(chan, false, &fence);
if (!ret) {
ret = nouveau_fence_wait(fence, false, false);
nouveau_fence_unref(&fence);
}
if (ret)
NV_PRINTK(error, cli, "failed to idle channel 0x%08x [%s]\n",
chan->object->handle, nvkm_client(&cli->base)->name);
return ret;
}
void
nouveau_channel_del(struct nouveau_channel **pchan)
{
struct nouveau_channel *chan = *pchan;
if (chan) {
if (chan->fence) {
nouveau_channel_idle(chan);
nouveau_fence(chan->drm)->context_del(chan);
}
nvif_object_fini(&chan->nvsw);
nvif_object_fini(&chan->gart);
nvif_object_fini(&chan->vram);
nvif_object_ref(NULL, &chan->object);
nvif_object_fini(&chan->push.ctxdma);
nouveau_bo_vma_del(chan->push.buffer, &chan->push.vma);
nouveau_bo_unmap(chan->push.buffer);
if (chan->push.buffer && chan->push.buffer->pin_refcnt)
nouveau_bo_unpin(chan->push.buffer);
nouveau_bo_ref(NULL, &chan->push.buffer);
nvif_device_ref(NULL, &chan->device);
kfree(chan);
}
*pchan = NULL;
}
static int
nouveau_channel_prep(struct nouveau_drm *drm, struct nvif_device *device,
u32 handle, u32 size, struct nouveau_channel **pchan)
{
struct nouveau_cli *cli = (void *)nvif_client(&device->base);
struct nouveau_vmmgr *vmm = nvkm_vmmgr(device);
struct nv_dma_v0 args = {};
struct nouveau_channel *chan;
u32 target;
int ret;
chan = *pchan = kzalloc(sizeof(*chan), GFP_KERNEL);
if (!chan)
return -ENOMEM;
nvif_device_ref(device, &chan->device);
chan->drm = drm;
target = TTM_PL_FLAG_TT | TTM_PL_FLAG_UNCACHED;
if (nouveau_vram_pushbuf)
target = TTM_PL_FLAG_VRAM;
ret = nouveau_bo_new(drm->dev, size, 0, target, 0, 0, NULL, NULL,
&chan->push.buffer);
if (ret == 0) {
ret = nouveau_bo_pin(chan->push.buffer, target, false);
if (ret == 0)
ret = nouveau_bo_map(chan->push.buffer);
}
if (ret) {
nouveau_channel_del(pchan);
return ret;
}
chan->push.vma.offset = chan->push.buffer->bo.offset;
if (device->info.family >= NV_DEVICE_INFO_V0_TESLA) {
ret = nouveau_bo_vma_add(chan->push.buffer, cli->vm,
&chan->push.vma);
if (ret) {
nouveau_channel_del(pchan);
return ret;
}
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_VM;
args.start = 0;
args.limit = cli->vm->vmm->limit - 1;
} else
if (chan->push.buffer->bo.mem.mem_type == TTM_PL_VRAM) {
if (device->info.family == NV_DEVICE_INFO_V0_TNT) {
args.target = NV_DMA_V0_TARGET_PCI;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = nv_device_resource_start(nvkm_device(device), 1);
args.limit = args.start + device->info.ram_user - 1;
} else {
args.target = NV_DMA_V0_TARGET_VRAM;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = 0;
args.limit = device->info.ram_user - 1;
}
} else {
if (chan->drm->agp.stat == ENABLED) {
args.target = NV_DMA_V0_TARGET_AGP;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = chan->drm->agp.base;
args.limit = chan->drm->agp.base +
chan->drm->agp.size - 1;
} else {
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = 0;
args.limit = vmm->limit - 1;
}
}
ret = nvif_object_init(nvif_object(device), NULL, NVDRM_PUSH |
(handle & 0xffff), NV_DMA_FROM_MEMORY,
&args, sizeof(args), &chan->push.ctxdma);
if (ret) {
nouveau_channel_del(pchan);
return ret;
}
return 0;
}
static int
nouveau_channel_ind(struct nouveau_drm *drm, struct nvif_device *device,
u32 handle, u32 engine, struct nouveau_channel **pchan)
{
static const u16 oclasses[] = { KEPLER_CHANNEL_GPFIFO_A,
FERMI_CHANNEL_GPFIFO,
G82_CHANNEL_GPFIFO,
NV50_CHANNEL_GPFIFO,
0 };
const u16 *oclass = oclasses;
union {
struct nv50_channel_gpfifo_v0 nv50;
struct kepler_channel_gpfifo_a_v0 kepler;
} args, *retn;
struct nouveau_channel *chan;
u32 size;
int ret;
ret = nouveau_channel_prep(drm, device, handle, 0x12000, &chan);
*pchan = chan;
if (ret)
return ret;
do {
if (oclass[0] >= KEPLER_CHANNEL_GPFIFO_A) {
args.kepler.version = 0;
args.kepler.engine = engine;
args.kepler.pushbuf = chan->push.ctxdma.handle;
args.kepler.ilength = 0x02000;
args.kepler.ioffset = 0x10000 + chan->push.vma.offset;
size = sizeof(args.kepler);
} else {
args.nv50.version = 0;
args.nv50.pushbuf = chan->push.ctxdma.handle;
args.nv50.ilength = 0x02000;
args.nv50.ioffset = 0x10000 + chan->push.vma.offset;
size = sizeof(args.nv50);
}
ret = nvif_object_new(nvif_object(device), handle, *oclass++,
&args, size, &chan->object);
if (ret == 0) {
retn = chan->object->data;
if (chan->object->oclass >= KEPLER_CHANNEL_GPFIFO_A)
chan->chid = retn->kepler.chid;
else
chan->chid = retn->nv50.chid;
return ret;
}
} while (*oclass);
nouveau_channel_del(pchan);
return ret;
}
static int
nouveau_channel_dma(struct nouveau_drm *drm, struct nvif_device *device,
u32 handle, struct nouveau_channel **pchan)
{
static const u16 oclasses[] = { NV40_CHANNEL_DMA,
NV17_CHANNEL_DMA,
NV10_CHANNEL_DMA,
NV03_CHANNEL_DMA,
0 };
const u16 *oclass = oclasses;
struct nv03_channel_dma_v0 args, *retn;
struct nouveau_channel *chan;
int ret;
ret = nouveau_channel_prep(drm, device, handle, 0x10000, &chan);
*pchan = chan;
if (ret)
return ret;
args.version = 0;
args.pushbuf = chan->push.ctxdma.handle;
args.offset = chan->push.vma.offset;
do {
ret = nvif_object_new(nvif_object(device), handle, *oclass++,
&args, sizeof(args), &chan->object);
if (ret == 0) {
retn = chan->object->data;
chan->chid = retn->chid;
return ret;
}
} while (ret && *oclass);
nouveau_channel_del(pchan);
return ret;
}
static int
nouveau_channel_init(struct nouveau_channel *chan, u32 vram, u32 gart)
{
struct nvif_device *device = chan->device;
struct nouveau_cli *cli = (void *)nvif_client(&device->base);
struct nouveau_vmmgr *vmm = nvkm_vmmgr(device);
struct nouveau_software_chan *swch;
struct nv_dma_v0 args = {};
int ret, i;
nvif_object_map(chan->object);
if (device->info.family < NV_DEVICE_INFO_V0_FERMI) {
if (device->info.family >= NV_DEVICE_INFO_V0_TESLA) {
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_VM;
args.start = 0;
args.limit = cli->vm->vmm->limit - 1;
} else {
args.target = NV_DMA_V0_TARGET_VRAM;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = 0;
args.limit = device->info.ram_user - 1;
}
ret = nvif_object_init(chan->object, NULL, vram,
NV_DMA_IN_MEMORY, &args,
sizeof(args), &chan->vram);
if (ret)
return ret;
if (device->info.family >= NV_DEVICE_INFO_V0_TESLA) {
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_VM;
args.start = 0;
args.limit = cli->vm->vmm->limit - 1;
} else
if (chan->drm->agp.stat == ENABLED) {
args.target = NV_DMA_V0_TARGET_AGP;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = chan->drm->agp.base;
args.limit = chan->drm->agp.base +
chan->drm->agp.size - 1;
} else {
args.target = NV_DMA_V0_TARGET_VM;
args.access = NV_DMA_V0_ACCESS_RDWR;
args.start = 0;
args.limit = vmm->limit - 1;
}
ret = nvif_object_init(chan->object, NULL, gart,
NV_DMA_IN_MEMORY, &args,
sizeof(args), &chan->gart);
if (ret)
return ret;
}
switch (chan->object->oclass & 0x00ff) {
case 0x006b:
case 0x006e:
chan->user_put = 0x40;
chan->user_get = 0x44;
chan->dma.max = (0x10000 / 4) - 2;
break;
default:
chan->user_put = 0x40;
chan->user_get = 0x44;
chan->user_get_hi = 0x60;
chan->dma.ib_base = 0x10000 / 4;
chan->dma.ib_max = (0x02000 / 8) - 1;
chan->dma.ib_put = 0;
chan->dma.ib_free = chan->dma.ib_max - chan->dma.ib_put;
chan->dma.max = chan->dma.ib_base;
break;
}
chan->dma.put = 0;
chan->dma.cur = chan->dma.put;
chan->dma.free = chan->dma.max - chan->dma.cur;
ret = RING_SPACE(chan, NOUVEAU_DMA_SKIPS);
if (ret)
return ret;
for (i = 0; i < NOUVEAU_DMA_SKIPS; i++)
OUT_RING(chan, 0x00000000);
if (device->info.family < NV_DEVICE_INFO_V0_CELSIUS) {
ret = nvif_object_init(chan->object, NULL, 0x006e, 0x006e,
NULL, 0, &chan->nvsw);
if (ret)
return ret;
swch = (void *)nvkm_object(&chan->nvsw)->parent;
swch->flip = nouveau_flip_complete;
swch->flip_data = chan;
ret = RING_SPACE(chan, 2);
if (ret)
return ret;
BEGIN_NV04(chan, NvSubSw, 0x0000, 1);
OUT_RING (chan, chan->nvsw.handle);
FIRE_RING (chan);
}
return nouveau_fence(chan->drm)->context_new(chan);
}
int
nouveau_channel_new(struct nouveau_drm *drm, struct nvif_device *device,
u32 handle, u32 arg0, u32 arg1,
struct nouveau_channel **pchan)
{
struct nouveau_cli *cli = (void *)nvif_client(&device->base);
bool super;
int ret;
super = cli->base.super;
cli->base.super = true;
ret = nouveau_channel_ind(drm, device, handle, arg0, pchan);
if (ret) {
NV_PRINTK(debug, cli, "ib channel create, %d\n", ret);
ret = nouveau_channel_dma(drm, device, handle, pchan);
if (ret) {
NV_PRINTK(debug, cli, "dma channel create, %d\n", ret);
goto done;
}
}
ret = nouveau_channel_init(*pchan, arg0, arg1);
if (ret) {
NV_PRINTK(error, cli, "channel failed to initialise, %d\n", ret);
nouveau_channel_del(pchan);
}
done:
cli->base.super = super;
return ret;
}
