void
nva3_copy_intr(struct nouveau_subdev *subdev)
{
struct nouveau_fifo *pfifo = nouveau_fifo(subdev);
struct nouveau_engine *engine = nv_engine(subdev);
struct nouveau_falcon *falcon = (void *)subdev;
struct nouveau_object *engctx;
u32 dispatch = nv_ro32(falcon, 0x01c);
u32 stat = nv_ro32(falcon, 0x008) & dispatch & ~(dispatch >> 16);
u64 inst = nv_ro32(falcon, 0x050) & 0x3fffffff;
u32 ssta = nv_ro32(falcon, 0x040) & 0x0000ffff;
u32 addr = nv_ro32(falcon, 0x040) >> 16;
u32 mthd = (addr & 0x07ff) << 2;
u32 subc = (addr & 0x3800) >> 11;
u32 data = nv_ro32(falcon, 0x044);
int chid;
engctx = nouveau_engctx_get(engine, inst);
chid = pfifo->chid(pfifo, engctx);
if (stat & 0x00000040) {
nv_error(falcon, "DISPATCH_ERROR [");
nouveau_enum_print(nva3_copy_isr_error_name, ssta);
printk("] ch %d [0x%010llx] subc %d mthd 0x%04x data 0x%08x\n",
chid, inst << 12, subc, mthd, data);
nv_wo32(falcon, 0x004, 0x00000040);
stat &= ~0x00000040;
}
if (stat) {
nv_error(falcon, "unhandled intr 0x%08x\n", stat);
nv_wo32(falcon, 0x004, stat);
}
nouveau_engctx_put(engctx);
}
static int
nva3_copy_tlb_flush(struct nouveau_engine *engine)
{
nv50_vm_flush_engine(&engine->base, 0x0d);
return 0;
}
static int
nva3_copy_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
bool enable = (nv_device(parent)->chipset != 0xaf);
struct nva3_copy_priv *priv;
int ret;
ret = nouveau_falcon_create(parent, engine, oclass, 0x104000, enable,
"PCE0", "copy0", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00802000;
nv_subdev(priv)->intr = nva3_copy_intr;
nv_engine(priv)->cclass = &nva3_copy_cclass;
nv_engine(priv)->sclass = nva3_copy_sclass;
nv_engine(priv)->tlb_flush = nva3_copy_tlb_flush;
nv_falcon(priv)->code.data = nva3_pcopy_code;
nv_falcon(priv)->code.size = sizeof(nva3_pcopy_code);
nv_falcon(priv)->data.data = nva3_pcopy_data;
nv_falcon(priv)->data.size = sizeof(nva3_pcopy_data);
return 0;
}
