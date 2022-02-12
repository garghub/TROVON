static inline int
ramxlat(const struct ramxlat *xlat, int id)
{
while (xlat->id >= 0) {
if (xlat->id == id)
return xlat->enc;
xlat++;
}
return -EINVAL;
}
int
nouveau_sddr3_calc(struct nouveau_ram *ram)
{
struct nouveau_bios *bios = nouveau_bios(ram);
int WL, CL, WR;
switch (!!ram->timing.data * ram->timing.version) {
case 0x20:
WL = (nv_ro16(bios, ram->timing.data + 0x04) & 0x0f80) >> 7;
CL = nv_ro08(bios, ram->timing.data + 0x04) & 0x1f;
WR = nv_ro08(bios, ram->timing.data + 0x0a) & 0x7f;
break;
default:
return -ENOSYS;
}
WL = ramxlat(ramddr3_cwl, WL);
CL = ramxlat(ramddr3_cl, CL);
WR = ramxlat(ramddr3_wr, WR);
if (WL < 0 || CL < 0 || WR < 0)
return -EINVAL;
ram->mr[0] &= ~0xe74;
ram->mr[0] |= (WR & 0x07) << 9;
ram->mr[0] |= (CL & 0x0e) << 3;
ram->mr[0] |= (CL & 0x01) << 2;
ram->mr[2] &= ~0x038;
ram->mr[2] |= (WL & 0x07) << 3;
return 0;
}
