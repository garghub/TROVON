static int
g84_cipher_object_ctor(struct nvkm_object *parent,
struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_gpuobj *obj;
int ret;
ret = nvkm_gpuobj_create(parent, engine, oclass, 0, parent,
16, 16, 0, &obj);
*pobject = nv_object(obj);
if (ret)
return ret;
nv_wo32(obj, 0x00, nv_mclass(obj));
nv_wo32(obj, 0x04, 0x00000000);
nv_wo32(obj, 0x08, 0x00000000);
nv_wo32(obj, 0x0c, 0x00000000);
return 0;
}
static void
g84_cipher_intr(struct nvkm_subdev *subdev)
{
struct nvkm_fifo *pfifo = nvkm_fifo(subdev);
struct nvkm_engine *engine = nv_engine(subdev);
struct nvkm_object *engctx;
struct g84_cipher_priv *priv = (void *)subdev;
u32 stat = nv_rd32(priv, 0x102130);
u32 mthd = nv_rd32(priv, 0x102190);
u32 data = nv_rd32(priv, 0x102194);
u32 inst = nv_rd32(priv, 0x102188) & 0x7fffffff;
int chid;
engctx = nvkm_engctx_get(engine, inst);
chid = pfifo->chid(pfifo, engctx);
if (stat) {
nv_error(priv, "%s", "");
nvkm_bitfield_print(g84_cipher_intr_mask, stat);
pr_cont(" ch %d [0x%010llx %s] mthd 0x%04x data 0x%08x\n",
chid, (u64)inst << 12, nvkm_client_name(engctx),
mthd, data);
}
nv_wr32(priv, 0x102130, stat);
nv_wr32(priv, 0x10200c, 0x10);
nvkm_engctx_put(engctx);
}
static int
g84_cipher_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct g84_cipher_priv *priv;
int ret;
ret = nvkm_engine_create(parent, engine, oclass, true,
"PCIPHER", "cipher", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00004000;
nv_subdev(priv)->intr = g84_cipher_intr;
nv_engine(priv)->cclass = &g84_cipher_cclass;
nv_engine(priv)->sclass = g84_cipher_sclass;
return 0;
}
static int
g84_cipher_init(struct nvkm_object *object)
{
struct g84_cipher_priv *priv = (void *)object;
int ret;
ret = nvkm_engine_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x102130, 0xffffffff);
nv_wr32(priv, 0x102140, 0xffffffbf);
nv_wr32(priv, 0x10200c, 0x00000010);
return 0;
}
