u16
nvbios_fan_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
struct bit_entry bit_P;
u16 fan = 0x0000;
if (!bit_entry(bios, 'P', &bit_P)) {
if (bit_P.version == 2 && bit_P.length >= 0x5a)
fan = nv_ro16(bios, bit_P.offset + 0x58);
if (fan) {
*ver = nv_ro08(bios, fan + 0);
switch (*ver) {
case 0x10:
*hdr = nv_ro08(bios, fan + 1);
*len = nv_ro08(bios, fan + 2);
*cnt = nv_ro08(bios, fan + 3);
return fan;
default:
break;
}
}
}
return 0x0000;
}
u16
nvbios_fan_entry(struct nouveau_bios *bios, int idx, u8 *ver, u8 *hdr,
u8 *cnt, u8 *len)
{
u16 data = nvbios_fan_table(bios, ver, hdr, cnt, len);
if (data && idx < *cnt)
return data + *hdr + (idx * (*len));
return 0x0000;
}
u16
nvbios_fan_parse(struct nouveau_bios *bios, struct nvbios_therm_fan *fan)
{
u8 ver, hdr, cnt, len;
u16 data = nvbios_fan_entry(bios, 0, &ver, &hdr, &cnt, &len);
if (data) {
u8 type = nv_ro08(bios, data + 0x00);
switch (type) {
case 0:
fan->type = NVBIOS_THERM_FAN_TOGGLE;
break;
case 1:
case 2:
fan->type = NVBIOS_THERM_FAN_PWM;
break;
default:
fan->type = NVBIOS_THERM_FAN_UNK;
}
fan->min_duty = nv_ro08(bios, data + 0x02);
fan->max_duty = nv_ro08(bios, data + 0x03);
fan->pwm_freq = nv_ro32(bios, data + 0x0b) & 0xffffff;
}
return data;
}
