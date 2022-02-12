u16
dcb_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
struct nvkm_subdev *subdev = &bios->subdev;
struct nvkm_device *device = subdev->device;
u16 dcb = 0x0000;
if (device->card_type > NV_04)
dcb = nvbios_rd16(bios, 0x36);
if (!dcb) {
nvkm_warn(subdev, "DCB table not found\n");
return dcb;
}
*ver = nvbios_rd08(bios, dcb);
if (*ver >= 0x42) {
nvkm_warn(subdev, "DCB version 0x%02x unknown\n", *ver);
return 0x0000;
} else
if (*ver >= 0x30) {
if (nvbios_rd32(bios, dcb + 6) == 0x4edcbdcb) {
*hdr = nvbios_rd08(bios, dcb + 1);
*cnt = nvbios_rd08(bios, dcb + 2);
*len = nvbios_rd08(bios, dcb + 3);
return dcb;
}
} else
if (*ver >= 0x20) {
if (nvbios_rd32(bios, dcb + 4) == 0x4edcbdcb) {
u16 i2c = nvbios_rd16(bios, dcb + 2);
*hdr = 8;
*cnt = (i2c - dcb) / 8;
*len = 8;
return dcb;
}
} else
if (*ver >= 0x15) {
if (!nvbios_memcmp(bios, dcb - 7, "DEV_REC", 7)) {
u16 i2c = nvbios_rd16(bios, dcb + 2);
*hdr = 4;
*cnt = (i2c - dcb) / 10;
*len = 10;
return dcb;
}
} else {
nvkm_debug(subdev, "DCB contains no useful data\n");
return 0x0000;
}
nvkm_warn(subdev, "DCB header validation failed\n");
return 0x0000;
}
u16
dcb_outp(struct nvkm_bios *bios, u8 idx, u8 *ver, u8 *len)
{
u8 hdr, cnt;
u16 dcb = dcb_table(bios, ver, &hdr, &cnt, len);
if (dcb && idx < cnt)
return dcb + hdr + (idx * *len);
return 0x0000;
}
static inline u16
dcb_outp_hasht(struct dcb_output *outp)
{
return (outp->extdev << 8) | (outp->location << 4) | outp->type;
}
static inline u16
dcb_outp_hashm(struct dcb_output *outp)
{
return (outp->heads << 8) | (outp->link << 6) | outp->or;
}
u16
dcb_outp_parse(struct nvkm_bios *bios, u8 idx, u8 *ver, u8 *len,
struct dcb_output *outp)
{
u16 dcb = dcb_outp(bios, idx, ver, len);
memset(outp, 0x00, sizeof(*outp));
if (dcb) {
if (*ver >= 0x20) {
u32 conn = nvbios_rd32(bios, dcb + 0x00);
outp->or = (conn & 0x0f000000) >> 24;
outp->location = (conn & 0x00300000) >> 20;
outp->bus = (conn & 0x000f0000) >> 16;
outp->connector = (conn & 0x0000f000) >> 12;
outp->heads = (conn & 0x00000f00) >> 8;
outp->i2c_index = (conn & 0x000000f0) >> 4;
outp->type = (conn & 0x0000000f);
outp->link = 0;
} else {
dcb = 0x0000;
}
if (*ver >= 0x40) {
u32 conf = nvbios_rd32(bios, dcb + 0x04);
switch (outp->type) {
case DCB_OUTPUT_DP:
switch (conf & 0x00e00000) {
case 0x00000000:
outp->dpconf.link_bw = 0x06;
break;
case 0x00200000:
outp->dpconf.link_bw = 0x0a;
break;
case 0x00400000:
outp->dpconf.link_bw = 0x14;
break;
case 0x00600000:
default:
outp->dpconf.link_bw = 0x1e;
break;
}
switch ((conf & 0x0f000000) >> 24) {
case 0xf:
case 0x4:
outp->dpconf.link_nr = 4;
break;
case 0x3:
case 0x2:
outp->dpconf.link_nr = 2;
break;
case 0x1:
default:
outp->dpconf.link_nr = 1;
break;
}
case DCB_OUTPUT_TMDS:
case DCB_OUTPUT_LVDS:
outp->link = (conf & 0x00000030) >> 4;
outp->sorconf.link = outp->link;
outp->extdev = 0x00;
if (outp->location != 0)
outp->extdev = (conf & 0x0000ff00) >> 8;
break;
default:
break;
}
}
outp->hasht = dcb_outp_hasht(outp);
outp->hashm = dcb_outp_hashm(outp);
}
return dcb;
}
u16
dcb_outp_match(struct nvkm_bios *bios, u16 type, u16 mask,
u8 *ver, u8 *len, struct dcb_output *outp)
{
u16 dcb, idx = 0;
while ((dcb = dcb_outp_parse(bios, idx++, ver, len, outp))) {
if ((dcb_outp_hasht(outp) & 0x00ff) == (type & 0x00ff)) {
if ((dcb_outp_hashm(outp) & mask) == mask)
break;
}
}
return dcb;
}
int
dcb_outp_foreach(struct nvkm_bios *bios, void *data,
int (*exec)(struct nvkm_bios *, void *, int, u16))
{
int ret, idx = -1;
u8 ver, len;
u16 outp;
while ((outp = dcb_outp(bios, ++idx, &ver, &len))) {
if (nvbios_rd32(bios, outp) == 0x00000000)
break;
if (nvbios_rd32(bios, outp) == 0xffffffff)
break;
if (nvbios_rd08(bios, outp) == DCB_OUTPUT_UNUSED)
continue;
if (nvbios_rd08(bios, outp) == DCB_OUTPUT_EOL)
break;
ret = exec(bios, data, idx, outp);
if (ret)
return ret;
}
return 0;
}
