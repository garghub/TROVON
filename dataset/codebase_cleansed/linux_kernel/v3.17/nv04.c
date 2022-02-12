static int
nv04_software_set_ref(struct nouveau_object *object, u32 mthd,
void *data, u32 size)
{
struct nouveau_object *channel = (void *)nv_engctx(object->parent);
struct nouveau_fifo_chan *fifo = (void *)channel->parent;
atomic_set(&fifo->refcnt, *(u32*)data);
return 0;
}
static int
nv04_software_flip(struct nouveau_object *object, u32 mthd,
void *args, u32 size)
{
struct nv04_software_chan *chan = (void *)nv_engctx(object->parent);
if (chan->base.flip)
return chan->base.flip(chan->base.flip_data);
return -EINVAL;
}
static int
nv04_software_context_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv04_software_chan *chan;
int ret;
ret = nouveau_software_context_create(parent, engine, oclass, &chan);
*pobject = nv_object(chan);
if (ret)
return ret;
return 0;
}
void
nv04_software_intr(struct nouveau_subdev *subdev)
{
nv_mask(subdev, 0x000100, 0x80000000, 0x00000000);
}
static int
nv04_software_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv04_software_priv *priv;
int ret;
ret = nouveau_software_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_engine(priv)->cclass = &nv04_software_cclass;
nv_engine(priv)->sclass = nv04_software_sclass;
nv_subdev(priv)->intr = nv04_software_intr;
return 0;
}
