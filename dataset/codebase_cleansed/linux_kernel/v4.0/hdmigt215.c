int
gt215_hdmi_ctrl(NV50_DISP_MTHD_V1)
{
const u32 soff = outp->or * 0x800;
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
nv_mask(priv, 0x61c5d0 + soff, 0x00070001, 0x00010001);
nv_mask(priv, 0x61c568 + soff, 0x00010101, 0x00000000);
nv_mask(priv, 0x61c578 + soff, 0x80000000, 0x80000000);
nv_mask(priv, 0x61733c, 0x00100000, 0x00100000);
nv_mask(priv, 0x61733c, 0x10000000, 0x10000000);
nv_mask(priv, 0x61733c, 0x00100000, 0x00000000);
nv_mask(priv, 0x61c5a4 + soff, 0x5f1f007f, ctrl);
return 0;
}
