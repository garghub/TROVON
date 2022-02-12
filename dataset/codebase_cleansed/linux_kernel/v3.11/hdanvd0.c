int
nvd0_hda_eld(struct nv50_disp_priv *priv, int or, u8 *data, u32 size)
{
const u32 soff = (or * 0x030);
int i;
if (data && data[0]) {
for (i = 0; i < size; i++)
nv_wr32(priv, 0x10ec00 + soff, (i << 8) | data[i]);
for (; i < 0x60; i++)
nv_wr32(priv, 0x10ec00 + soff, (i << 8));
nv_mask(priv, 0x10ec10 + soff, 0x80000003, 0x80000003);
} else
if (data) {
nv_mask(priv, 0x10ec10 + soff, 0x80000003, 0x80000001);
} else {
nv_mask(priv, 0x10ec10 + soff, 0x80000003, 0x80000000);
}
return 0;
}
