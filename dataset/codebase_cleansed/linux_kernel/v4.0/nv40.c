static u32
nv40_instmem_rd32(struct nvkm_object *object, u64 addr)
{
struct nv04_instmem_priv *priv = (void *)object;
return ioread32_native(priv->iomem + addr);
}
static void
nv40_instmem_wr32(struct nvkm_object *object, u64 addr, u32 data)
{
struct nv04_instmem_priv *priv = (void *)object;
iowrite32_native(data, priv->iomem + addr);
}
static int
nv40_instmem_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_device *device = nv_device(parent);
struct nv04_instmem_priv *priv;
int ret, bar, vs;
ret = nvkm_instmem_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
if (nv_device_resource_len(device, 2))
bar = 2;
else
bar = 3;
priv->iomem = ioremap(nv_device_resource_start(device, bar),
nv_device_resource_len(device, bar));
if (!priv->iomem) {
nv_error(priv, "unable to map PRAMIN BAR\n");
return -EFAULT;
}
vs = hweight8((nv_rd32(priv, 0x001540) & 0x0000ff00) >> 8);
if (device->chipset == 0x40) priv->base.reserved = 0x6aa0 * vs;
else if (device->chipset < 0x43) priv->base.reserved = 0x4f00 * vs;
else if (nv44_gr_class(priv)) priv->base.reserved = 0x4980 * vs;
else priv->base.reserved = 0x4a40 * vs;
priv->base.reserved += 16 * 1024;
priv->base.reserved *= 32;
priv->base.reserved += 512 * 1024;
priv->base.reserved += 512 * 1024;
priv->base.reserved = round_up(priv->base.reserved, 4096);
ret = nvkm_mm_init(&priv->heap, 0, priv->base.reserved, 1);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), NULL, 0x10000, 0, 0,
&priv->vbios);
if (ret)
return ret;
ret = nvkm_ramht_new(nv_object(priv), NULL, 0x08000, 0, &priv->ramht);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), NULL, 0x08000, 0, 0,
&priv->ramro);
if (ret)
return ret;
ret = nvkm_gpuobj_new(nv_object(priv), NULL, 0x20000, 0,
NVOBJ_FLAG_ZERO_ALLOC, &priv->ramfc);
if (ret)
return ret;
return 0;
}
