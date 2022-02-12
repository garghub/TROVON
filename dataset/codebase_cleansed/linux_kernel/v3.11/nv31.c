static int
nv31_mpeg_object_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_gpuobj *obj;
int ret;
ret = nouveau_gpuobj_create(parent, engine, oclass, 0, parent,
20, 16, 0, &obj);
*pobject = nv_object(obj);
if (ret)
return ret;
nv_wo32(obj, 0x00, nv_mclass(obj));
nv_wo32(obj, 0x04, 0x00000000);
nv_wo32(obj, 0x08, 0x00000000);
nv_wo32(obj, 0x0c, 0x00000000);
return 0;
}
static int
nv31_mpeg_mthd_dma(struct nouveau_object *object, u32 mthd, void *arg, u32 len)
{
struct nouveau_instmem *imem = nouveau_instmem(object);
struct nv31_mpeg_priv *priv = (void *)object->engine;
u32 inst = *(u32 *)arg << 4;
u32 dma0 = nv_ro32(imem, inst + 0);
u32 dma1 = nv_ro32(imem, inst + 4);
u32 dma2 = nv_ro32(imem, inst + 8);
u32 base = (dma2 & 0xfffff000) | (dma0 >> 20);
u32 size = dma1 + 1;
if (!(dma0 & 0x00002000))
return -EINVAL;
if (mthd == 0x0190) {
nv_mask(priv, 0x00b300, 0x00030000, (dma0 & 0x00030000));
nv_wr32(priv, 0x00b334, base);
nv_wr32(priv, 0x00b324, size);
} else
if (mthd == 0x01a0) {
nv_mask(priv, 0x00b300, 0x000c0000, (dma0 & 0x00030000) << 2);
nv_wr32(priv, 0x00b360, base);
nv_wr32(priv, 0x00b364, size);
} else {
if (dma0 & 0x000c0000)
return -EINVAL;
nv_wr32(priv, 0x00b370, base);
nv_wr32(priv, 0x00b374, size);
}
return 0;
}
static int
nv31_mpeg_context_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv31_mpeg_priv *priv = (void *)engine;
struct nv31_mpeg_chan *chan;
int ret;
if (!atomic_add_unless(&priv->refcount, 1, 1))
return -EBUSY;
ret = nouveau_object_create(parent, engine, oclass, 0, &chan);
*pobject = nv_object(chan);
if (ret)
return ret;
return 0;
}
static void
nv31_mpeg_context_dtor(struct nouveau_object *object)
{
struct nv31_mpeg_priv *priv = (void *)object->engine;
struct nv31_mpeg_chan *chan = (void *)object;
atomic_dec(&priv->refcount);
nouveau_object_destroy(&chan->base);
}
void
nv31_mpeg_tile_prog(struct nouveau_engine *engine, int i)
{
struct nouveau_fb_tile *tile = &nouveau_fb(engine)->tile.region[i];
struct nv31_mpeg_priv *priv = (void *)engine;
nv_wr32(priv, 0x00b008 + (i * 0x10), tile->pitch);
nv_wr32(priv, 0x00b004 + (i * 0x10), tile->limit);
nv_wr32(priv, 0x00b000 + (i * 0x10), tile->addr);
}
void
nv31_mpeg_intr(struct nouveau_subdev *subdev)
{
struct nouveau_fifo *pfifo = nouveau_fifo(subdev);
struct nouveau_engine *engine = nv_engine(subdev);
struct nouveau_object *engctx;
struct nouveau_handle *handle;
struct nv31_mpeg_priv *priv = (void *)subdev;
u32 inst = nv_rd32(priv, 0x00b318) & 0x000fffff;
u32 stat = nv_rd32(priv, 0x00b100);
u32 type = nv_rd32(priv, 0x00b230);
u32 mthd = nv_rd32(priv, 0x00b234);
u32 data = nv_rd32(priv, 0x00b238);
u32 show = stat;
int chid;
engctx = nouveau_engctx_get(engine, inst);
chid = pfifo->chid(pfifo, engctx);
if (stat & 0x01000000) {
if (type == 0x00000020 && mthd == 0x0000) {
nv_mask(priv, 0x00b308, 0x00000000, 0x00000000);
show &= ~0x01000000;
}
if (type == 0x00000010) {
handle = nouveau_handle_get_class(engctx, 0x3174);
if (handle && !nv_call(handle->object, mthd, data))
show &= ~0x01000000;
nouveau_handle_put(handle);
}
}
nv_wr32(priv, 0x00b100, stat);
nv_wr32(priv, 0x00b230, 0x00000001);
if (show) {
nv_error(priv,
"ch %d [0x%08x %s] 0x%08x 0x%08x 0x%08x 0x%08x\n",
chid, inst << 4, nouveau_client_name(engctx), stat,
type, mthd, data);
}
nouveau_engctx_put(engctx);
}
static int
nv31_mpeg_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv31_mpeg_priv *priv;
int ret;
ret = nouveau_mpeg_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00000002;
nv_subdev(priv)->intr = nv31_mpeg_intr;
nv_engine(priv)->cclass = &nv31_mpeg_cclass;
nv_engine(priv)->sclass = nv31_mpeg_sclass;
nv_engine(priv)->tile_prog = nv31_mpeg_tile_prog;
return 0;
}
int
nv31_mpeg_init(struct nouveau_object *object)
{
struct nouveau_engine *engine = nv_engine(object);
struct nv31_mpeg_priv *priv = (void *)object;
struct nouveau_fb *pfb = nouveau_fb(object);
int ret, i;
ret = nouveau_mpeg_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x00b0e0, 0x00000020);
nv_wr32(priv, 0x00b0e8, 0x00000020);
for (i = 0; i < pfb->tile.regions; i++)
engine->tile_prog(engine, i);
nv_wr32(priv, 0x00b32c, 0x00000000);
nv_wr32(priv, 0x00b314, 0x00000100);
if (nv_device(priv)->chipset >= 0x40 && nv44_graph_class(priv))
nv_wr32(priv, 0x00b220, 0x00000044);
else
nv_wr32(priv, 0x00b220, 0x00000031);
nv_wr32(priv, 0x00b300, 0x02001ec1);
nv_mask(priv, 0x00b32c, 0x00000001, 0x00000001);
nv_wr32(priv, 0x00b100, 0xffffffff);
nv_wr32(priv, 0x00b140, 0xffffffff);
if (!nv_wait(priv, 0x00b200, 0x00000001, 0x00000000)) {
nv_error(priv, "timeout 0x%08x\n", nv_rd32(priv, 0x00b200));
return -EBUSY;
}
return 0;
}
