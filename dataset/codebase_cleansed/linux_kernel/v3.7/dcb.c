u16
dcb_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
struct nouveau_device *device = nv_device(bios);
u16 dcb = 0x0000;
if (device->card_type > NV_04)
dcb = nv_ro16(bios, 0x36);
if (!dcb) {
nv_warn(bios, "DCB table not found\n");
return dcb;
}
*ver = nv_ro08(bios, dcb);
if (*ver >= 0x41) {
nv_warn(bios, "DCB version 0x%02x unknown\n", *ver);
return 0x0000;
} else
if (*ver >= 0x30) {
if (nv_ro32(bios, dcb + 6) == 0x4edcbdcb) {
*hdr = nv_ro08(bios, dcb + 1);
*cnt = nv_ro08(bios, dcb + 2);
*len = nv_ro08(bios, dcb + 3);
return dcb;
}
} else
if (*ver >= 0x20) {
if (nv_ro32(bios, dcb + 4) == 0x4edcbdcb) {
u16 i2c = nv_ro16(bios, dcb + 2);
*hdr = 8;
*cnt = (i2c - dcb) / 8;
*len = 8;
return dcb;
}
} else
if (*ver >= 0x15) {
if (!nv_memcmp(bios, dcb - 7, "DEV_REC", 7)) {
u16 i2c = nv_ro16(bios, dcb + 2);
*hdr = 4;
*cnt = (i2c - dcb) / 10;
*len = 10;
return dcb;
}
} else {
nv_warn(bios, "DCB contains no useful data\n");
return 0x0000;
}
nv_warn(bios, "DCB header validation failed\n");
return 0x0000;
}
u16
dcb_outp(struct nouveau_bios *bios, u8 idx, u8 *ver, u8 *len)
{
u8 hdr, cnt;
u16 dcb = dcb_table(bios, ver, &hdr, &cnt, len);
if (dcb && idx < cnt)
return dcb + hdr + (idx * *len);
return 0x0000;
}
int
dcb_outp_foreach(struct nouveau_bios *bios, void *data,
int (*exec)(struct nouveau_bios *, void *, int, u16))
{
int ret, idx = -1;
u8 ver, len;
u16 outp;
while ((outp = dcb_outp(bios, ++idx, &ver, &len))) {
if (nv_ro32(bios, outp) == 0x00000000)
break;
if (nv_ro32(bios, outp) == 0xffffffff)
break;
if (nv_ro08(bios, outp) == DCB_OUTPUT_UNUSED)
continue;
if (nv_ro08(bios, outp) == DCB_OUTPUT_EOL)
break;
ret = exec(bios, data, idx, outp);
if (ret)
return ret;
}
return 0;
}
