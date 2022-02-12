static void
nvd0_disp_intr_vblank(struct nvd0_disp_priv *priv, int crtc)
{
struct nouveau_bar *bar = nouveau_bar(priv);
struct nouveau_disp *disp = &priv->base;
struct nouveau_software_chan *chan, *temp;
unsigned long flags;
spin_lock_irqsave(&disp->vblank.lock, flags);
list_for_each_entry_safe(chan, temp, &disp->vblank.list, vblank.head) {
if (chan->vblank.crtc != crtc)
continue;
nv_wr32(priv, 0x001718, 0x80000000 | chan->vblank.channel);
bar->flush(bar);
nv_wr32(priv, 0x06000c, upper_32_bits(chan->vblank.offset));
nv_wr32(priv, 0x060010, lower_32_bits(chan->vblank.offset));
nv_wr32(priv, 0x060014, chan->vblank.value);
list_del(&chan->vblank.head);
if (disp->vblank.put)
disp->vblank.put(disp->vblank.data, crtc);
}
spin_unlock_irqrestore(&disp->vblank.lock, flags);
if (disp->vblank.notify)
disp->vblank.notify(disp->vblank.data, crtc);
}
static void
nvd0_disp_intr(struct nouveau_subdev *subdev)
{
struct nvd0_disp_priv *priv = (void *)subdev;
u32 intr = nv_rd32(priv, 0x610088);
int i;
for (i = 0; i < 4; i++) {
u32 mask = 0x01000000 << i;
if (mask & intr) {
u32 stat = nv_rd32(priv, 0x6100bc + (i * 0x800));
if (stat & 0x00000001)
nvd0_disp_intr_vblank(priv, i);
nv_mask(priv, 0x6100bc + (i * 0x800), 0, 0);
nv_rd32(priv, 0x6100c0 + (i * 0x800));
}
}
}
static int
nvd0_disp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nvd0_disp_priv *priv;
int ret;
ret = nouveau_disp_create(parent, engine, oclass, "PDISP",
"display", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_engine(priv)->sclass = nvd0_disp_sclass;
nv_subdev(priv)->intr = nvd0_disp_intr;
INIT_LIST_HEAD(&priv->base.vblank.list);
spin_lock_init(&priv->base.vblank.lock);
return 0;
}
