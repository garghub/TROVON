u32
nvbios_npdeTe(struct nvkm_bios *bios, u32 base)
{
struct nvbios_pcirT pcir;
u8 ver; u16 hdr;
u32 data = nvbios_pcirTp(bios, base, &ver, &hdr, &pcir);
if (data = (data + hdr + 0x0f) & ~0x0f, data) {
switch (nvbios_rd32(bios, data + 0x00)) {
case 0x4544504e:
break;
default:
nvkm_debug(&bios->subdev,
"%08x: NPDE signature (%08x) unknown\n",
data, nvbios_rd32(bios, data + 0x00));
data = 0;
break;
}
}
return data;
}
u32
nvbios_npdeTp(struct nvkm_bios *bios, u32 base, struct nvbios_npdeT *info)
{
u32 data = nvbios_npdeTe(bios, base);
memset(info, 0x00, sizeof(*info));
if (data) {
info->image_size = nvbios_rd16(bios, data + 0x08) * 512;
info->last = nvbios_rd08(bios, data + 0x0a) & 0x80;
}
return data;
}
