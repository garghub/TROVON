int
gf119_hdmi_ctrl(NV50_DISP_MTHD_V1)
{
struct nvkm_device *device = disp->base.engine.subdev.device;
const u32 hoff = (head * 0x800);
union {
struct nv50_disp_sor_hdmi_pwr_v0 v0;
} *args = data;
u32 ctrl;
int ret = -ENOSYS;
nvif_ioctl(object, "disp sor hdmi ctrl size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp sor hdmi ctrl vers %d state %d "
"max_ac_packet %d rekey %d\n",
args->v0.version, args->v0.state,
args->v0.max_ac_packet, args->v0.rekey);
if (args->v0.max_ac_packet > 0x1f || args->v0.rekey > 0x7f)
return -EINVAL;
ctrl = 0x40000000 * !!args->v0.state;
ctrl |= args->v0.max_ac_packet << 16;
ctrl |= args->v0.rekey;
} else
return ret;
if (!(ctrl & 0x40000000)) {
nvkm_mask(device, 0x616798 + hoff, 0x40000000, 0x00000000);
nvkm_mask(device, 0x6167a4 + hoff, 0x00000001, 0x00000000);
nvkm_mask(device, 0x616714 + hoff, 0x00000001, 0x00000000);
return 0;
}
nvkm_mask(device, 0x616714 + hoff, 0x00000001, 0x00000000);
nvkm_wr32(device, 0x61671c + hoff, 0x000d0282);
nvkm_wr32(device, 0x616720 + hoff, 0x0000006f);
nvkm_wr32(device, 0x616724 + hoff, 0x00000000);
nvkm_wr32(device, 0x616728 + hoff, 0x00000000);
nvkm_wr32(device, 0x61672c + hoff, 0x00000000);
nvkm_mask(device, 0x616714 + hoff, 0x00000001, 0x00000001);
nvkm_mask(device, 0x6167a4 + hoff, 0x00000001, 0x00000000);
nvkm_wr32(device, 0x6167ac + hoff, 0x00000010);
nvkm_mask(device, 0x6167a4 + hoff, 0x00000001, 0x00000001);
nvkm_mask(device, 0x616798 + hoff, 0x401f007f, ctrl);
return 0;
}
