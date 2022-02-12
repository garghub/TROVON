static u32
nv50_instobj_rd32(struct nouveau_object *object, u64 offset)
{
struct nv50_instmem_priv *priv = (void *)object->engine;
struct nv50_instobj_priv *node = (void *)object;
unsigned long flags;
u64 base = (node->mem->offset + offset) & 0xffffff00000ULL;
u64 addr = (node->mem->offset + offset) & 0x000000fffffULL;
u32 data;
spin_lock_irqsave(&priv->lock, flags);
if (unlikely(priv->addr != base)) {
nv_wr32(priv, 0x001700, base >> 16);
priv->addr = base;
}
data = nv_rd32(priv, 0x700000 + addr);
spin_unlock_irqrestore(&priv->lock, flags);
return data;
}
static void
nv50_instobj_wr32(struct nouveau_object *object, u64 offset, u32 data)
{
struct nv50_instmem_priv *priv = (void *)object->engine;
struct nv50_instobj_priv *node = (void *)object;
unsigned long flags;
u64 base = (node->mem->offset + offset) & 0xffffff00000ULL;
u64 addr = (node->mem->offset + offset) & 0x000000fffffULL;
spin_lock_irqsave(&priv->lock, flags);
if (unlikely(priv->addr != base)) {
nv_wr32(priv, 0x001700, base >> 16);
priv->addr = base;
}
nv_wr32(priv, 0x700000 + addr, data);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void
nv50_instobj_dtor(struct nouveau_object *object)
{
struct nv50_instobj_priv *node = (void *)object;
struct nouveau_fb *pfb = nouveau_fb(object);
pfb->ram->put(pfb, &node->mem);
nouveau_instobj_destroy(&node->base);
}
static int
nv50_instobj_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_instobj_args *args = data;
struct nv50_instobj_priv *node;
int ret;
args->size = max((args->size + 4095) & ~4095, (u32)4096);
args->align = max((args->align + 4095) & ~4095, (u32)4096);
ret = nouveau_instobj_create(parent, engine, oclass, &node);
*pobject = nv_object(node);
if (ret)
return ret;
ret = pfb->ram->get(pfb, args->size, args->align, 0, 0x800, &node->mem);
if (ret)
return ret;
node->base.addr = node->mem->offset;
node->base.size = node->mem->size << 12;
node->mem->page_shift = 12;
return 0;
}
static int
nv50_instmem_fini(struct nouveau_object *object, bool suspend)
{
struct nv50_instmem_priv *priv = (void *)object;
priv->addr = ~0ULL;
return nouveau_instmem_fini(&priv->base, suspend);
}
static int
nv50_instmem_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_instmem_priv *priv;
int ret;
ret = nouveau_instmem_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
spin_lock_init(&priv->lock);
return 0;
}
