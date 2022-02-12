static void
nv40_perfctr_init(struct nouveau_perfmon *ppm, struct nouveau_perfdom *dom,
struct nouveau_perfctr *ctr)
{
struct nv40_perfmon_priv *priv = (void *)ppm;
struct nv40_perfmon_cntr *cntr = (void *)ctr;
u32 log = ctr->logic_op;
u32 src = 0x00000000;
int i;
for (i = 0; i < 4 && ctr->signal[i]; i++)
src |= (ctr->signal[i] - dom->signal) << (i * 8);
nv_wr32(priv, 0x00a7c0 + dom->addr, 0x00000001);
nv_wr32(priv, 0x00a400 + dom->addr + (cntr->base.slot * 0x40), src);
nv_wr32(priv, 0x00a420 + dom->addr + (cntr->base.slot * 0x40), log);
}
static void
nv40_perfctr_read(struct nouveau_perfmon *ppm, struct nouveau_perfdom *dom,
struct nouveau_perfctr *ctr)
{
struct nv40_perfmon_priv *priv = (void *)ppm;
struct nv40_perfmon_cntr *cntr = (void *)ctr;
switch (cntr->base.slot) {
case 0: cntr->base.ctr = nv_rd32(priv, 0x00a700 + dom->addr); break;
case 1: cntr->base.ctr = nv_rd32(priv, 0x00a6c0 + dom->addr); break;
case 2: cntr->base.ctr = nv_rd32(priv, 0x00a680 + dom->addr); break;
case 3: cntr->base.ctr = nv_rd32(priv, 0x00a740 + dom->addr); break;
}
cntr->base.clk = nv_rd32(priv, 0x00a600 + dom->addr);
}
static void
nv40_perfctr_next(struct nouveau_perfmon *ppm, struct nouveau_perfdom *dom)
{
struct nv40_perfmon_priv *priv = (void *)ppm;
if (priv->sequence != ppm->sequence) {
nv_wr32(priv, 0x400084, 0x00000020);
priv->sequence = ppm->sequence;
}
}
int
nv40_perfmon_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv40_perfmon_oclass *mclass = (void *)oclass;
struct nv40_perfmon_priv *priv;
int ret;
ret = nouveau_perfmon_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
ret = nouveau_perfdom_new(&priv->base, "pm", 0, 0, 0, 4, mclass->doms);
if (ret)
return ret;
nv_engine(priv)->cclass = &nouveau_perfmon_cclass;
nv_engine(priv)->sclass = nouveau_perfmon_sclass;
return 0;
}
