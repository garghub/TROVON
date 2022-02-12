u64
gm107_devinit_disable(struct nvkm_devinit *devinit)
{
struct nv50_devinit_priv *priv = (void *)devinit;
u32 r021c00 = nv_rd32(priv, 0x021c00);
u32 r021c04 = nv_rd32(priv, 0x021c04);
u64 disable = 0ULL;
if (r021c00 & 0x00000001)
disable |= (1ULL << NVDEV_ENGINE_CE0);
if (r021c00 & 0x00000004)
disable |= (1ULL << NVDEV_ENGINE_CE2);
if (r021c04 & 0x00000001)
disable |= (1ULL << NVDEV_ENGINE_DISP);
return disable;
}
