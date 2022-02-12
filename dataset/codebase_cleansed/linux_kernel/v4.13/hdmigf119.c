void
gf119_hdmi_ctrl(struct nvkm_ior *ior, int head, bool enable, u8 max_ac_packet,
u8 rekey, u8 *avi, u8 avi_size, u8 *vendor, u8 vendor_size)
{
struct nvkm_device *device = ior->disp->engine.subdev.device;
const u32 ctrl = 0x40000000 * enable |
max_ac_packet << 16 |
rekey;
const u32 hoff = head * 0x800;
struct packed_hdmi_infoframe avi_infoframe;
struct packed_hdmi_infoframe vendor_infoframe;
pack_hdmi_infoframe(&avi_infoframe, avi, avi_size);
pack_hdmi_infoframe(&vendor_infoframe, vendor, vendor_size);
if (!(ctrl & 0x40000000)) {
nvkm_mask(device, 0x616798 + hoff, 0x40000000, 0x00000000);
nvkm_mask(device, 0x616730 + hoff, 0x00000001, 0x00000000);
nvkm_mask(device, 0x6167a4 + hoff, 0x00000001, 0x00000000);
nvkm_mask(device, 0x616714 + hoff, 0x00000001, 0x00000000);
return;
}
nvkm_mask(device, 0x616714 + hoff, 0x00000001, 0x00000000);
if (avi_size) {
nvkm_wr32(device, 0x61671c + hoff, avi_infoframe.header);
nvkm_wr32(device, 0x616720 + hoff, avi_infoframe.subpack0_low);
nvkm_wr32(device, 0x616724 + hoff, avi_infoframe.subpack0_high);
nvkm_wr32(device, 0x616728 + hoff, avi_infoframe.subpack1_low);
nvkm_wr32(device, 0x61672c + hoff, avi_infoframe.subpack1_high);
nvkm_mask(device, 0x616714 + hoff, 0x00000001, 0x00000001);
}
nvkm_mask(device, 0x616730 + hoff, 0x00010001, 0x00010000);
if (vendor_size) {
nvkm_wr32(device, 0x616738 + hoff, vendor_infoframe.header);
nvkm_wr32(device, 0x61673c + hoff, vendor_infoframe.subpack0_low);
nvkm_wr32(device, 0x616740 + hoff, vendor_infoframe.subpack0_high);
nvkm_mask(device, 0x616730 + hoff, 0x00000001, 0x00000001);
}
nvkm_mask(device, 0x6167a4 + hoff, 0x00000001, 0x00000000);
nvkm_wr32(device, 0x6167ac + hoff, 0x00000010);
nvkm_mask(device, 0x6167a4 + hoff, 0x00000001, 0x00000001);
nvkm_mask(device, 0x616798 + hoff, 0x401f007f, ctrl);
}
