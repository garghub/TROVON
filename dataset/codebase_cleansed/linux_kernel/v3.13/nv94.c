static int
nv94_bus_hwsq_exec(struct nouveau_bus *pbus, u32 *data, u32 size)
{
struct nv50_bus_priv *priv = (void *)pbus;
int i;
nv_mask(pbus, 0x001098, 0x00000008, 0x00000000);
nv_wr32(pbus, 0x001304, 0x00000000);
nv_wr32(pbus, 0x001318, 0x00000000);
for (i = 0; i < size; i++)
nv_wr32(priv, 0x080000 + (i * 4), data[i]);
nv_mask(pbus, 0x001098, 0x00000018, 0x00000018);
nv_wr32(pbus, 0x00130c, 0x00000001);
return nv_wait(pbus, 0x001308, 0x00000100, 0x00000000) ? 0 : -ETIMEDOUT;
}
