int
nv84_hdmi_ctrl(struct nv50_disp_priv *priv, int head, int or, u32 data)
{
const u32 hoff = (head * 0x800);
if (!(data & NV84_DISP_SOR_HDMI_PWR_STATE_ON)) {
nv_mask(priv, 0x6165a4 + hoff, 0x40000000, 0x00000000);
nv_mask(priv, 0x616520 + hoff, 0x00000001, 0x00000000);
nv_mask(priv, 0x616500 + hoff, 0x00000001, 0x00000000);
return 0;
}
nv_mask(priv, 0x616520 + hoff, 0x00000001, 0x00000000);
nv_wr32(priv, 0x616528 + hoff, 0x000d0282);
nv_wr32(priv, 0x61652c + hoff, 0x0000006f);
nv_wr32(priv, 0x616530 + hoff, 0x00000000);
nv_wr32(priv, 0x616534 + hoff, 0x00000000);
nv_wr32(priv, 0x616538 + hoff, 0x00000000);
nv_mask(priv, 0x616520 + hoff, 0x00000001, 0x00000001);
nv_mask(priv, 0x616500 + hoff, 0x00000001, 0x00000000);
nv_wr32(priv, 0x616508 + hoff, 0x000a0184);
nv_wr32(priv, 0x61650c + hoff, 0x00000071);
nv_wr32(priv, 0x616510 + hoff, 0x00000000);
nv_mask(priv, 0x616500 + hoff, 0x00000001, 0x00000001);
nv_mask(priv, 0x61733c, 0x00100000, 0x00100000);
nv_mask(priv, 0x61733c, 0x10000000, 0x10000000);
nv_mask(priv, 0x61733c, 0x00100000, 0x00000000);
nv_mask(priv, 0x6165a4 + hoff, 0x5f1f007f, data | 0x1f000000 );
return 0;
}
