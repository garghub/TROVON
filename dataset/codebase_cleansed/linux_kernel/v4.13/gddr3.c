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
nvkm_gddr3_calc(struct nvkm_ram *ram)
{
int CL, WR, CWL, DLL = 0, ODT = 0, RON, hi;
switch (ram->next->bios.timing_ver) {
case 0x10:
CWL = ram->next->bios.timing_10_CWL;
CL = ram->next->bios.timing_10_CL;
WR = ram->next->bios.timing_10_WR;
DLL = !ram->next->bios.ramcfg_DLLoff;
ODT = ram->next->bios.timing_10_ODT;
RON = ram->next->bios.ramcfg_RON;
break;
case 0x20:
CWL = (ram->next->bios.timing[1] & 0x00000f80) >> 7;
CL = (ram->next->bios.timing[1] & 0x0000001f) >> 0;
WR = (ram->next->bios.timing[2] & 0x007f0000) >> 16;
DLL = !(ram->mr[1] & 0x1);
RON = !(ram->mr[1] & 0x300) >> 8;
break;
default:
return -ENOSYS;
}
if (ram->next->bios.timing_ver == 0x20 ||
ram->next->bios.ramcfg_timing == 0xff) {
ODT = (ram->mr[1] & 0xc) >> 2;
}
hi = ram->mr[2] & 0x1;
CL = ramxlat(hi ? ramgddr3_cl_hi : ramgddr3_cl_lo, CL);
WR = ramxlat(ramgddr3_wr_lo, WR);
if (CL < 0 || CWL < 1 || CWL > 7 || WR < 0)
return -EINVAL;
ram->mr[0] &= ~0xf74;
ram->mr[0] |= (CWL & 0x07) << 9;
ram->mr[0] |= (CL & 0x07) << 4;
ram->mr[0] |= (CL & 0x08) >> 1;
ram->mr[1] &= ~0x3fc;
ram->mr[1] |= (ODT & 0x03) << 2;
ram->mr[1] |= (RON & 0x03) << 8;
ram->mr[1] |= (WR & 0x03) << 4;
ram->mr[1] |= (WR & 0x04) << 5;
ram->mr[1] |= !DLL << 6;
return 0;
}
