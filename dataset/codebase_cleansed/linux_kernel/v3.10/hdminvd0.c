int
nvd0_hdmi_ctrl(struct nv50_disp_priv *priv, int head, int or, u32 data)
{
const u32 hoff = (head * 0x800);
if (!(data & NV84_DISP_SOR_HDMI_PWR_STATE_ON)) {
nv_mask(priv, 0x616798 + hoff, 0x40000000, 0x00000000);
nv_mask(priv, 0x6167a4 + hoff, 0x00000001, 0x00000000);
nv_mask(priv, 0x616714 + hoff, 0x00000001, 0x00000000);
return 0;
}
nv_mask(priv, 0x616714 + hoff, 0x00000001, 0x00000000);
nv_wr32(priv, 0x61671c + hoff, 0x000d0282);
nv_wr32(priv, 0x616720 + hoff, 0x0000006f);
nv_wr32(priv, 0x616724 + hoff, 0x00000000);
nv_wr32(priv, 0x616728 + hoff, 0x00000000);
nv_wr32(priv, 0x61672c + hoff, 0x00000000);
nv_mask(priv, 0x616714 + hoff, 0x00000001, 0x00000001);
nv_mask(priv, 0x6167a4 + hoff, 0x00000001, 0x00000000);
nv_wr32(priv, 0x6167ac + hoff, 0x00000010);
nv_mask(priv, 0x6167a4 + hoff, 0x00000001, 0x00000001);
nv_mask(priv, 0x616798 + hoff, 0x401f007f, data);
nv_mask(priv, 0x616548 + hoff, 0x00000070, 0x00000000);
return 0;
}
