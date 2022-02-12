static u32
pramin_read(void *data, u32 offset, u32 length, struct nouveau_bios *bios)
{
u32 i;
if (offset + length <= 0x00100000) {
for (i = offset; i < offset + length; i += 4)
*(u32 *)&bios->data[i] = nv_rd32(bios, 0x700000 + i);
return length;
}
return 0;
}
static void
pramin_fini(void *data)
{
struct priv *priv = data;
if (priv) {
nv_wr32(priv->bios, 0x001700, priv->bar0);
kfree(priv);
}
}
static void *
pramin_init(struct nouveau_bios *bios, const char *name)
{
struct priv *priv = NULL;
u64 addr = 0;
if (nv_device(bios)->card_type < NV_50)
return NULL;
if (nv_device(bios)->card_type >= GM100)
addr = nv_rd32(bios, 0x021c04);
else
if (nv_device(bios)->card_type >= NV_C0)
addr = nv_rd32(bios, 0x022500);
if (addr & 0x00000001) {
nv_debug(bios, "... display disabled\n");
return ERR_PTR(-ENODEV);
}
addr = nv_rd32(bios, 0x619f04);
if (!(addr & 0x00000008)) {
nv_debug(bios, "... not enabled\n");
return ERR_PTR(-ENODEV);
}
if ( (addr & 0x00000003) != 1) {
nv_debug(bios, "... not in vram\n");
return ERR_PTR(-ENODEV);
}
addr = (addr & 0xffffff00) << 8;
if (!addr) {
addr = (u64)nv_rd32(bios, 0x001700) << 16;
addr += 0xf0000;
}
if (!(priv = kmalloc(sizeof(*priv), GFP_KERNEL))) {
nv_error(bios, "... out of memory\n");
return ERR_PTR(-ENOMEM);
}
priv->bios = bios;
priv->bar0 = nv_rd32(bios, 0x001700);
nv_wr32(bios, 0x001700, addr >> 16);
return priv;
}
