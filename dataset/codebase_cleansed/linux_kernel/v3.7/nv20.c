static void
nv20_devinit_meminit(struct nouveau_devinit *devinit)
{
struct nv20_devinit_priv *priv = (void *)devinit;
struct nouveau_device *device = nv_device(priv);
uint32_t mask = (device->chipset >= 0x25 ? 0x300 : 0x900);
uint32_t amount, off;
struct io_mapping *fb;
fb = fbmem_init(nv_device(priv)->pdev);
if (!fb) {
nv_error(priv, "failed to map fb\n");
return;
}
nv_wr32(priv, NV10_PFB_REFCTRL, NV10_PFB_REFCTRL_VALID_1);
nv_mask(priv, NV04_PFB_CFG0, 0, mask);
amount = nv_rd32(priv, 0x10020c);
for (off = amount; off > 0x2000000; off -= 0x2000000)
fbmem_poke(fb, off - 4, off);
amount = nv_rd32(priv, 0x10020c);
if (amount != fbmem_peek(fb, amount - 4))
nv_mask(priv, NV04_PFB_CFG0, mask, 0);
fbmem_fini(fb);
}
static int
nv20_devinit_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv20_devinit_priv *priv;
int ret;
ret = nouveau_devinit_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.meminit = nv20_devinit_meminit;
return 0;
}
