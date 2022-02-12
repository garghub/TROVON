static void
nv05_devinit_meminit(struct nouveau_devinit *devinit)
{
static const u8 default_config_tab[][2] = {
{ 0x24, 0x00 },
{ 0x28, 0x00 },
{ 0x24, 0x01 },
{ 0x1f, 0x00 },
{ 0x0f, 0x00 },
{ 0x17, 0x00 },
{ 0x06, 0x00 },
{ 0x00, 0x00 }
};
struct nv05_devinit_priv *priv = (void *)devinit;
struct nouveau_bios *bios = nouveau_bios(priv);
struct io_mapping *fb;
u32 patt = 0xdeadbeef;
u16 data;
u8 strap, ramcfg[2];
int i, v;
fb = fbmem_init(nv_device(priv)->pdev);
if (!fb) {
nv_error(priv, "failed to map fb\n");
return;
}
strap = (nv_rd32(priv, 0x101000) & 0x0000003c) >> 2;
if ((data = bmp_mem_init_table(bios))) {
ramcfg[0] = nv_ro08(bios, data + 2 * strap + 0);
ramcfg[1] = nv_ro08(bios, data + 2 * strap + 1);
} else {
ramcfg[0] = default_config_tab[strap][0];
ramcfg[1] = default_config_tab[strap][1];
}
nv_wrvgas(priv, 0, 1, nv_rdvgas(priv, 0, 1) | 0x20);
if (nv_rd32(priv, NV04_PFB_BOOT_0) & NV04_PFB_BOOT_0_UMA_ENABLE)
goto out;
nv_mask(priv, NV04_PFB_DEBUG_0, NV04_PFB_DEBUG_0_REFRESH_OFF, 0);
if (data) {
for (i = 0, data += 0x10; i < 8; i++, data += 4) {
u32 scramble = nv_ro32(bios, data);
nv_wr32(priv, NV04_PFB_SCRAMBLE(i), scramble);
}
}
nv_mask(priv, NV04_PFB_BOOT_0, 0x3f, ramcfg[0]);
if (ramcfg[1] & 0x80)
nv_mask(priv, NV04_PFB_CFG0, 0, NV04_PFB_CFG0_SCRAMBLE);
nv_mask(priv, NV04_PFB_CFG1, 0x700001, (ramcfg[1] & 1) << 20);
nv_mask(priv, NV04_PFB_CFG1, 0, 1);
for (i = 0; i < 4; i++)
fbmem_poke(fb, 4 * i, patt);
if (fbmem_peek(fb, 0xc) != patt)
nv_mask(priv, NV04_PFB_BOOT_0,
NV04_PFB_BOOT_0_RAM_WIDTH_128, 0);
v = nv_rd32(priv, NV04_PFB_BOOT_0) & NV04_PFB_BOOT_0_RAM_AMOUNT;
if (v == NV04_PFB_BOOT_0_RAM_AMOUNT_32MB &&
(!fbmem_readback(fb, 0x1000000, ++patt) ||
!fbmem_readback(fb, 0, ++patt)))
nv_mask(priv, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_16MB);
if (v == NV04_PFB_BOOT_0_RAM_AMOUNT_16MB &&
!fbmem_readback(fb, 0x800000, ++patt))
nv_mask(priv, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_8MB);
if (!fbmem_readback(fb, 0x400000, ++patt))
nv_mask(priv, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_4MB);
out:
nv_wrvgas(priv, 0, 1, nv_rdvgas(priv, 0, 1) & ~0x20);
fbmem_fini(fb);
}
static int
nv05_devinit_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv05_devinit_priv *priv;
int ret;
ret = nouveau_devinit_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.meminit = nv05_devinit_meminit;
priv->base.pll_set = nv04_devinit_pll_set;
return 0;
}
