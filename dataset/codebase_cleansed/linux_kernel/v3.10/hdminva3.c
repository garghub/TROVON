int
nva3_hdmi_ctrl(struct nv50_disp_priv *priv, int head, int or, u32 data)
{
const u32 soff = (or * 0x800);
if (!(data & NV84_DISP_SOR_HDMI_PWR_STATE_ON)) {
nv_mask(priv, 0x61c5a4 + soff, 0x40000000, 0x00000000);
nv_mask(priv, 0x61c520 + soff, 0x00000001, 0x00000000);
nv_mask(priv, 0x61c500 + soff, 0x00000001, 0x00000000);
return 0;
}
nv_mask(priv, 0x61c520 + soff, 0x00000001, 0x00000000);
nv_wr32(priv, 0x61c528 + soff, 0x000d0282);
nv_wr32(priv, 0x61c52c + soff, 0x0000006f);
nv_wr32(priv, 0x61c530 + soff, 0x00000000);
nv_wr32(priv, 0x61c534 + soff, 0x00000000);
nv_wr32(priv, 0x61c538 + soff, 0x00000000);
nv_mask(priv, 0x61c520 + soff, 0x00000001, 0x00000001);
nv_mask(priv, 0x61c500 + soff, 0x00000001, 0x00000000);
nv_wr32(priv, 0x61c508 + soff, 0x000a0184);
nv_wr32(priv, 0x61c50c + soff, 0x00000071);
nv_wr32(priv, 0x61c510 + soff, 0x00000000);
nv_mask(priv, 0x61c500 + soff, 0x00000001, 0x00000001);
nv_mask(priv, 0x61733c, 0x00100000, 0x00100000);
nv_mask(priv, 0x61733c, 0x10000000, 0x10000000);
nv_mask(priv, 0x61733c, 0x00100000, 0x00000000);
nv_mask(priv, 0x61c5a4 + soff, 0x5f1f007f, data | 0x1f000000 );
return 0;
}
