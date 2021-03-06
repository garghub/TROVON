static u16
nvbios_iccsense_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt,
u8 *len)
{
struct bit_entry bit_P;
u16 iccsense;
if (bit_entry(bios, 'P', &bit_P) || bit_P.version != 2 ||
bit_P.length < 0x2c)
return 0;
iccsense = nvbios_rd16(bios, bit_P.offset + 0x28);
if (!iccsense)
return 0;
*ver = nvbios_rd08(bios, iccsense + 0);
switch (*ver) {
case 0x10:
case 0x20:
*hdr = nvbios_rd08(bios, iccsense + 1);
*len = nvbios_rd08(bios, iccsense + 2);
*cnt = nvbios_rd08(bios, iccsense + 3);
return iccsense;
default:
break;
}
return 0;
}
int
nvbios_iccsense_parse(struct nvkm_bios *bios, struct nvbios_iccsense *iccsense)
{
struct nvkm_subdev *subdev = &bios->subdev;
u8 ver, hdr, cnt, len, i;
u16 table, entry;
table = nvbios_iccsense_table(bios, &ver, &hdr, &cnt, &len);
if (!table || !cnt)
return -EINVAL;
if (ver != 0x10 && ver != 0x20) {
nvkm_error(subdev, "ICCSENSE version 0x%02x unknown\n", ver);
return -EINVAL;
}
iccsense->nr_entry = cnt;
iccsense->rail = kmalloc(sizeof(struct pwr_rail_t) * cnt, GFP_KERNEL);
if (!iccsense->rail)
return -ENOMEM;
for (i = 0; i < cnt; ++i) {
struct pwr_rail_t *rail = &iccsense->rail[i];
entry = table + hdr + i * len;
switch(ver) {
case 0x10:
rail->mode = nvbios_rd08(bios, entry + 0x1);
rail->extdev_id = nvbios_rd08(bios, entry + 0x2);
rail->resistor_mohm = nvbios_rd08(bios, entry + 0x3);
rail->rail = nvbios_rd08(bios, entry + 0x4);
break;
case 0x20:
rail->mode = nvbios_rd08(bios, entry);
rail->extdev_id = nvbios_rd08(bios, entry + 0x1);
rail->resistor_mohm = nvbios_rd08(bios, entry + 0x5);
rail->rail = nvbios_rd08(bios, entry + 0x6);
break;
};
}
return 0;
}
