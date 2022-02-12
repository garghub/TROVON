static int w1_therm_add_slave(struct w1_slave *sl)
{
sl->family_data = kzalloc(9, GFP_KERNEL);
if (!sl->family_data)
return -ENOMEM;
return 0;
}
static void w1_therm_remove_slave(struct w1_slave *sl)
{
kfree(sl->family_data);
sl->family_data = NULL;
}
static inline int w1_DS18B20_convert_temp(u8 rom[9])
{
s16 t = le16_to_cpup((__le16 *)rom);
return t*1000/16;
}
static inline int w1_DS18S20_convert_temp(u8 rom[9])
{
int t, h;
if (!rom[7])
return 0;
if (rom[1] == 0)
t = ((s32)rom[0] >> 1)*1000;
else
t = 1000*(-1*(s32)(0x100-rom[0]) >> 1);
t -= 250;
h = 1000*((s32)rom[7] - (s32)rom[6]);
h /= (s32)rom[7];
t += h;
return t;
}
static inline int w1_convert_temp(u8 rom[9], u8 fid)
{
int i;
for (i = 0; i < ARRAY_SIZE(w1_therm_families); ++i)
if (w1_therm_families[i].f->fid == fid)
return w1_therm_families[i].convert(rom);
return 0;
}
static ssize_t w1_slave_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
u8 rom[9], crc, verdict, external_power;
int i, max_trying = 10;
ssize_t c = PAGE_SIZE;
i = mutex_lock_interruptible(&dev->bus_mutex);
if (i != 0)
return i;
memset(rom, 0, sizeof(rom));
while (max_trying--) {
verdict = 0;
crc = 0;
if (!w1_reset_select_slave(sl)) {
int count = 0;
unsigned int tm = 750;
unsigned long sleep_rem;
w1_write_8(dev, W1_READ_PSUPPLY);
external_power = w1_read_8(dev);
if (w1_reset_select_slave(sl))
continue;
if (w1_strong_pullup == 2 ||
(!external_power && w1_strong_pullup))
w1_next_pullup(dev, tm);
w1_write_8(dev, W1_CONVERT_TEMP);
if (external_power) {
mutex_unlock(&dev->bus_mutex);
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0)
return -EINTR;
i = mutex_lock_interruptible(&dev->bus_mutex);
if (i != 0)
return i;
} else if (!w1_strong_pullup) {
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0) {
mutex_unlock(&dev->bus_mutex);
return -EINTR;
}
}
if (!w1_reset_select_slave(sl)) {
w1_write_8(dev, W1_READ_SCRATCHPAD);
if ((count = w1_read_block(dev, rom, 9)) != 9) {
dev_warn(device, "w1_read_block() "
"returned %u instead of 9.\n",
count);
}
crc = w1_calc_crc8(rom, 8);
if (rom[8] == crc)
verdict = 1;
}
}
if (verdict)
break;
}
for (i = 0; i < 9; ++i)
c -= snprintf(buf + PAGE_SIZE - c, c, "%02x ", rom[i]);
c -= snprintf(buf + PAGE_SIZE - c, c, ": crc=%02x %s\n",
crc, (verdict) ? "YES" : "NO");
if (verdict)
memcpy(sl->family_data, rom, sizeof(rom));
else
dev_warn(device, "Read failed CRC check\n");
for (i = 0; i < 9; ++i)
c -= snprintf(buf + PAGE_SIZE - c, c, "%02x ",
((u8 *)sl->family_data)[i]);
c -= snprintf(buf + PAGE_SIZE - c, c, "t=%d\n",
w1_convert_temp(rom, sl->family->fid));
mutex_unlock(&dev->bus_mutex);
return PAGE_SIZE - c;
}
static int __init w1_therm_init(void)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(w1_therm_families); ++i) {
err = w1_register_family(w1_therm_families[i].f);
if (err)
w1_therm_families[i].broken = 1;
}
return 0;
}
static void __exit w1_therm_fini(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(w1_therm_families); ++i)
if (!w1_therm_families[i].broken)
w1_unregister_family(w1_therm_families[i].f);
}
