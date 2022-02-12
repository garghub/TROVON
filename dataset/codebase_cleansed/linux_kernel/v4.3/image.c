static bool
nvbios_imagen(struct nvkm_bios *bios, struct nvbios_image *image)
{
struct nvkm_subdev *subdev = &bios->subdev;
struct nvbios_pcirT pcir;
struct nvbios_npdeT npde;
u8 ver;
u16 hdr;
u32 data;
switch ((data = nvbios_rd16(bios, image->base + 0x00))) {
case 0xaa55:
case 0xbb77:
case 0x4e56:
break;
default:
nvkm_debug(subdev, "%08x: ROM signature (%04x) unknown\n",
image->base, data);
return false;
}
if (!(data = nvbios_pcirTp(bios, image->base, &ver, &hdr, &pcir)))
return false;
image->size = pcir.image_size;
image->type = pcir.image_type;
image->last = pcir.last;
if (image->type != 0x70) {
if (!(data = nvbios_npdeTp(bios, image->base, &npde)))
return true;
image->size = npde.image_size;
image->last = npde.last;
} else {
image->last = true;
}
return true;
}
bool
nvbios_image(struct nvkm_bios *bios, int idx, struct nvbios_image *image)
{
memset(image, 0x00, sizeof(*image));
do {
image->base += image->size;
if (image->last || !nvbios_imagen(bios, image))
return false;
} while(idx--);
return true;
}
