static u32
nvbios_iccsense_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt,
u8 *len)
{
struct bit_entry bit_P;
u32 iccsense;
if (bit_entry(bios, 'P', &bit_P) || bit_P.version != 2 ||
bit_P.length < 0x2c)
return 0;
iccsense = nvbios_rd32(bios, bit_P.offset + 0x28);
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
u32 table, entry;
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
struct nvbios_extdev_func extdev;
struct pwr_rail_t *rail = &iccsense->rail[i];
u8 res_start = 0;
int r;
entry = table + hdr + i * len;
switch(ver) {
case 0x10:
if ((nvbios_rd08(bios, entry + 0x1) & 0xf8) == 0xf8)
rail->mode = 1;
else
rail->mode = 0;
rail->extdev_id = nvbios_rd08(bios, entry + 0x2);
res_start = 0x3;
break;
case 0x20:
rail->mode = nvbios_rd08(bios, entry);
rail->extdev_id = nvbios_rd08(bios, entry + 0x1);
res_start = 0x5;
break;
};
if (nvbios_extdev_parse(bios, rail->extdev_id, &extdev))
continue;
switch (extdev.type) {
case NVBIOS_EXTDEV_INA209:
case NVBIOS_EXTDEV_INA219:
rail->resistor_count = 1;
break;
case NVBIOS_EXTDEV_INA3221:
rail->resistor_count = 3;
break;
default:
rail->resistor_count = 0;
break;
};
for (r = 0; r < rail->resistor_count; ++r) {
rail->resistors[r].mohm = nvbios_rd08(bios, entry + res_start + r * 2);
rail->resistors[r].enabled = !(nvbios_rd08(bios, entry + res_start + r * 2 + 1) & 0x40);
}
rail->config = nvbios_rd16(bios, entry + res_start + rail->resistor_count * 2);
}
return 0;
}
