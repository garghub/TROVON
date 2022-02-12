static int
nvc0_clock_pll_set(struct nouveau_clock *clk, u32 type, u32 freq)
{
struct nvc0_clock_priv *priv = (void *)clk;
struct nouveau_bios *bios = nouveau_bios(priv);
struct nvbios_pll info;
int N, fN, M, P;
int ret;
ret = nvbios_pll_parse(bios, type, &info);
if (ret)
return ret;
ret = nva3_pll_calc(clk, &info, freq, &N, &fN, &M, &P);
if (ret < 0)
return ret;
switch (info.type) {
case PLL_VPLL0:
case PLL_VPLL1:
nv_mask(priv, info.reg + 0x0c, 0x00000000, 0x00000100);
nv_wr32(priv, info.reg + 0x04, (P << 16) | (N << 8) | M);
nv_wr32(priv, info.reg + 0x10, fN << 16);
break;
default:
nv_warn(priv, "0x%08x/%dKhz unimplemented\n", type, freq);
ret = -EINVAL;
break;
}
return ret;
}
static int
nvc0_clock_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nvc0_clock_priv *priv;
int ret;
ret = nouveau_clock_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.pll_set = nvc0_clock_pll_set;
priv->base.pll_calc = nva3_clock_pll_calc;
return 0;
}
