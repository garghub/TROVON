static int
gk104_ltc_init(struct nouveau_object *object)
{
struct nvkm_ltc_priv *priv = (void *)object;
u32 lpg128 = !(nv_rd32(priv, 0x100c80) & 0x00000001);
int ret;
ret = nvkm_ltc_init(priv);
if (ret)
return ret;
nv_wr32(priv, 0x17e8d8, priv->ltc_nr);
nv_wr32(priv, 0x17e000, priv->ltc_nr);
nv_wr32(priv, 0x17e8d4, priv->tag_base);
nv_mask(priv, 0x17e8c0, 0x00000002, lpg128 ? 0x00000002 : 0x00000000);
return 0;
}
