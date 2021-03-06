static u16
therm_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr, u8 *len, u8 *cnt)
{
struct bit_entry bit_P;
u16 therm = 0;
if (!bit_entry(bios, 'P', &bit_P)) {
if (bit_P.version == 1)
therm = nv_ro16(bios, bit_P.offset + 12);
else if (bit_P.version == 2)
therm = nv_ro16(bios, bit_P.offset + 16);
else
nv_error(bios,
"unknown offset for thermal in BIT P %d\n",
bit_P.version);
}
if (!therm)
return 0x0000;
*ver = nv_ro08(bios, therm + 0);
*hdr = nv_ro08(bios, therm + 1);
*len = nv_ro08(bios, therm + 2);
*cnt = nv_ro08(bios, therm + 3);
return therm + nv_ro08(bios, therm + 1);
}
u16
nvbios_therm_entry(struct nouveau_bios *bios, int idx, u8 *ver, u8 *len)
{
u8 hdr, cnt;
u16 therm = therm_table(bios, ver, &hdr, len, &cnt);
if (therm && idx < cnt)
return therm + idx * *len;
return 0x0000;
}
int
nvbios_therm_sensor_parse(struct nouveau_bios *bios,
enum nvbios_therm_domain domain,
struct nvbios_therm_sensor *sensor)
{
s8 thrs_section, sensor_section, offset;
u8 ver, len, i;
u16 entry;
if (domain != NVBIOS_THERM_DOMAIN_CORE)
return -EINVAL;
thrs_section = 0;
sensor_section = -1;
i = 0;
while ((entry = nvbios_therm_entry(bios, i++, &ver, &len))) {
s16 value = nv_ro16(bios, entry + 1);
switch (nv_ro08(bios, entry + 0)) {
case 0x0:
thrs_section = value;
if (value > 0)
return 0;
break;
case 0x01:
sensor_section++;
if (sensor_section == 0) {
offset = ((s8) nv_ro08(bios, entry + 2)) / 2;
sensor->offset_constant = offset;
}
break;
case 0x04:
if (thrs_section == 0) {
sensor->thrs_critical.temp = (value & 0xff0) >> 4;
sensor->thrs_critical.hysteresis = value & 0xf;
}
break;
case 0x07:
if (thrs_section == 0) {
sensor->thrs_down_clock.temp = (value & 0xff0) >> 4;
sensor->thrs_down_clock.hysteresis = value & 0xf;
}
break;
case 0x08:
if (thrs_section == 0) {
sensor->thrs_fan_boost.temp = (value & 0xff0) >> 4;
sensor->thrs_fan_boost.hysteresis = value & 0xf;
}
break;
case 0x10:
if (sensor_section == 0)
sensor->offset_num = value;
break;
case 0x11:
if (sensor_section == 0)
sensor->offset_den = value;
break;
case 0x12:
if (sensor_section == 0)
sensor->slope_mult = value;
break;
case 0x13:
if (sensor_section == 0)
sensor->slope_div = value;
break;
case 0x32:
if (thrs_section == 0) {
sensor->thrs_shutdown.temp = (value & 0xff0) >> 4;
sensor->thrs_shutdown.hysteresis = value & 0xf;
}
break;
}
}
return 0;
}
int
nvbios_therm_fan_parse(struct nouveau_bios *bios,
struct nvbios_therm_fan *fan)
{
u8 ver, len, i;
u16 entry;
i = 0;
while ((entry = nvbios_therm_entry(bios, i++, &ver, &len))) {
s16 value = nv_ro16(bios, entry + 1);
switch (nv_ro08(bios, entry + 0)) {
case 0x22:
fan->min_duty = value & 0xff;
fan->max_duty = (value & 0xff00) >> 8;
break;
case 0x26:
fan->pwm_freq = value;
break;
}
}
return 0;
}
