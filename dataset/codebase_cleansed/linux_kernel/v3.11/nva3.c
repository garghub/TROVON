static int
nva3_devinit_pll_set(struct nouveau_devinit *devinit, u32 type, u32 freq)
{
struct nva3_devinit_priv *priv = (void *)devinit;
struct nouveau_bios *bios = nouveau_bios(priv);
struct nvbios_pll info;
int N, fN, M, P;
int ret;
ret = nvbios_pll_parse(bios, type, &info);
if (ret)
return ret;
ret = nva3_pll_calc(nv_subdev(devinit), &info, freq, &N, &fN, &M, &P);
if (ret < 0)
return ret;
switch (info.type) {
case PLL_VPLL0:
case PLL_VPLL1:
nv_wr32(priv, info.reg + 0, 0x50000610);
nv_mask(priv, info.reg + 4, 0x003fffff,
(P << 16) | (M << 8) | N);
nv_wr32(priv, info.reg + 8, fN);
break;
default:
nv_warn(priv, "0x%08x/%dKhz unimplemented\n", type, freq);
ret = -EINVAL;
break;
}
return ret;
}
static int
nva3_devinit_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_devinit_priv *priv;
int ret;
ret = nouveau_devinit_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.pll_set = nva3_devinit_pll_set;
return 0;
}
