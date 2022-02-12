static int
mcp77_ram_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 datasize,
struct nvkm_object **pobject)
{
u32 rsvd_head = ( 256 * 1024);
u32 rsvd_tail = (1024 * 1024);
struct nvkm_fb *pfb = nvkm_fb(parent);
struct mcp77_ram_priv *priv;
int ret;
ret = nvkm_ram_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.type = NV_MEM_TYPE_STOLEN;
priv->base.stolen = (u64)nv_rd32(pfb, 0x100e10) << 12;
priv->base.size = (u64)nv_rd32(pfb, 0x100e14) << 12;
rsvd_tail += 0x1000;
priv->poller_base = priv->base.size - rsvd_tail;
ret = nvkm_mm_init(&pfb->vram, rsvd_head >> 12,
(priv->base.size - (rsvd_head + rsvd_tail)) >> 12,
1);
if (ret)
return ret;
priv->base.get = nv50_ram_get;
priv->base.put = nv50_ram_put;
return 0;
}
static int
mcp77_ram_init(struct nvkm_object *object)
{
struct nvkm_fb *pfb = nvkm_fb(object);
struct mcp77_ram_priv *priv = (void *)object;
int ret;
u64 dniso, hostnb, flush;
ret = nvkm_ram_init(&priv->base);
if (ret)
return ret;
dniso = ((priv->base.size - (priv->poller_base + 0x00)) >> 5) - 1;
hostnb = ((priv->base.size - (priv->poller_base + 0x20)) >> 5) - 1;
flush = ((priv->base.size - (priv->poller_base + 0x40)) >> 5) - 1;
nv_wr32(pfb, 0x100c18, dniso);
nv_mask(pfb, 0x100c14, 0x00000000, 0x00000001);
nv_wr32(pfb, 0x100c1c, hostnb);
nv_mask(pfb, 0x100c14, 0x00000000, 0x00000002);
nv_wr32(pfb, 0x100c24, flush);
nv_mask(pfb, 0x100c14, 0x00000000, 0x00010000);
return 0;
}
