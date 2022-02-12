static u32
gf100_fuse_rd32(struct nouveau_object *object, u64 addr)
{
struct gf100_fuse_priv *priv = (void *)object;
unsigned long flags;
u32 fuse_enable, unk, val;
spin_lock_irqsave(&priv->fuse_enable_lock, flags);
fuse_enable = nv_mask(priv, 0x22400, 0x800, 0x800);
unk = nv_mask(priv, 0x21000, 0x1, 0x1);
val = nv_rd32(priv, 0x21100 + addr);
nv_wr32(priv, 0x21000, unk);
nv_wr32(priv, 0x22400, fuse_enable);
spin_unlock_irqrestore(&priv->fuse_enable_lock, flags);
return val;
}
static int
gf100_fuse_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct gf100_fuse_priv *priv;
int ret;
ret = nouveau_fuse_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
spin_lock_init(&priv->fuse_enable_lock);
return 0;
}
