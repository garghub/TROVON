int
g84_hdmi_ctrl(NV50_DISP_MTHD_V1)
{
const u32 hoff = (head * 0x800);
union {
struct nv50_disp_sor_hdmi_pwr_v0 v0;
} *args = data;
u32 ctrl;
int ret;
nv_ioctl(object, "disp sor hdmi ctrl size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nv_ioctl(object, "disp sor hdmi ctrl vers %d state %d "
"max_ac_packet %d rekey %d\n",
args->v0.version, args->v0.state,
args->v0.max_ac_packet, args->v0.rekey);
if (args->v0.max_ac_packet > 0x1f || args->v0.rekey > 0x7f)
return -EINVAL;
ctrl = 0x40000000 * !!args->v0.state;
ctrl |= args->v0.max_ac_packet << 16;
ctrl |= args->v0.rekey;
ctrl |= 0x1f000000;
} else
return ret;
if (!(ctrl & 0x40000000)) {
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
nv_mask(priv, 0x6165d0 + hoff, 0x00070001, 0x00010001);
nv_mask(priv, 0x616568 + hoff, 0x00010101, 0x00000000);
nv_mask(priv, 0x616578 + hoff, 0x80000000, 0x80000000);
nv_mask(priv, 0x61733c, 0x00100000, 0x00100000);
nv_mask(priv, 0x61733c, 0x10000000, 0x10000000);
nv_mask(priv, 0x61733c, 0x00100000, 0x00000000);
nv_mask(priv, 0x6165a4 + hoff, 0x5f1f007f, ctrl);
return 0;
}
