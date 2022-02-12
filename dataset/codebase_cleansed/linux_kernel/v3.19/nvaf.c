static u64
nvaf_devinit_disable(struct nouveau_devinit *devinit)
{
struct nv50_devinit_priv *priv = (void *)devinit;
u32 r001540 = nv_rd32(priv, 0x001540);
u32 r00154c = nv_rd32(priv, 0x00154c);
u64 disable = 0;
if (!(r001540 & 0x40000000)) {
disable |= (1ULL << NVDEV_ENGINE_VP);
disable |= (1ULL << NVDEV_ENGINE_PPP);
}
if (!(r00154c & 0x00000004))
disable |= (1ULL << NVDEV_ENGINE_DISP);
if (!(r00154c & 0x00000020))
disable |= (1ULL << NVDEV_ENGINE_BSP);
if (!(r00154c & 0x00000040))
disable |= (1ULL << NVDEV_ENGINE_VIC);
if (!(r00154c & 0x00000200))
disable |= (1ULL << NVDEV_ENGINE_COPY0);
return disable;
}
