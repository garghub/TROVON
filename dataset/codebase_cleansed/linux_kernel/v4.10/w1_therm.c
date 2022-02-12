static int w1_therm_add_slave(struct w1_slave *sl)
{
sl->family_data = kzalloc(sizeof(struct w1_therm_family_data),
GFP_KERNEL);
if (!sl->family_data)
return -ENOMEM;
atomic_set(THERM_REFCNT(sl->family_data), 1);
return 0;
}
static void w1_therm_remove_slave(struct w1_slave *sl)
{
int refcnt = atomic_sub_return(1, THERM_REFCNT(sl->family_data));
while (refcnt) {
msleep(1000);
refcnt = atomic_read(THERM_REFCNT(sl->family_data));
}
kfree(sl->family_data);
sl->family_data = NULL;
}
static inline int w1_therm_eeprom(struct device *device)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
u8 rom[9], external_power;
int ret, max_trying = 10;
u8 *family_data = sl->family_data;
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret != 0)
goto post_unlock;
if (!sl->family_data) {
ret = -ENODEV;
goto pre_unlock;
}
atomic_inc(THERM_REFCNT(family_data));
memset(rom, 0, sizeof(rom));
while (max_trying--) {
if (!w1_reset_select_slave(sl)) {
unsigned int tm = 10;
unsigned long sleep_rem;
w1_write_8(dev, W1_READ_PSUPPLY);
external_power = w1_read_8(dev);
if (w1_reset_select_slave(sl))
continue;
if (w1_strong_pullup == 2 ||
(!external_power && w1_strong_pullup))
w1_next_pullup(dev, tm);
w1_write_8(dev, W1_COPY_SCRATCHPAD);
if (external_power) {
mutex_unlock(&dev->bus_mutex);
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0) {
ret = -EINTR;
goto post_unlock;
}
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret != 0)
goto post_unlock;
} else if (!w1_strong_pullup) {
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0) {
ret = -EINTR;
goto pre_unlock;
}
}
break;
}
}
pre_unlock:
mutex_unlock(&dev->bus_mutex);
post_unlock:
atomic_dec(THERM_REFCNT(family_data));
return ret;
}
static inline int w1_DS18S20_precision(struct device *device, int val)
{
return 0;
}
static inline int w1_DS18B20_precision(struct device *device, int val)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
u8 rom[9], crc;
int ret, max_trying = 10;
u8 *family_data = sl->family_data;
uint8_t precision_bits;
uint8_t mask = 0x60;
if (val > 12 || val < 9) {
pr_warn("Unsupported precision\n");
return -1;
}
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret != 0)
goto post_unlock;
if (!sl->family_data) {
ret = -ENODEV;
goto pre_unlock;
}
atomic_inc(THERM_REFCNT(family_data));
memset(rom, 0, sizeof(rom));
switch (val) {
case 9:
precision_bits = 0x00;
break;
case 10:
precision_bits = 0x20;
break;
case 11:
precision_bits = 0x40;
break;
case 12:
default:
precision_bits = 0x60;
break;
}
while (max_trying--) {
crc = 0;
if (!w1_reset_select_slave(sl)) {
int count = 0;
w1_write_8(dev, W1_READ_SCRATCHPAD);
count = w1_read_block(dev, rom, 9);
if (count != 9)
dev_warn(device, "w1_read_block() returned %u instead of 9.\n", count);
crc = w1_calc_crc8(rom, 8);
if (rom[8] == crc) {
rom[4] = (rom[4] & ~mask) | (precision_bits & mask);
if (!w1_reset_select_slave(sl)) {
w1_write_8(dev, W1_WRITE_SCRATCHPAD);
w1_write_8(dev, rom[2]);
w1_write_8(dev, rom[3]);
w1_write_8(dev, rom[4]);
break;
}
}
}
}
pre_unlock:
mutex_unlock(&dev->bus_mutex);
post_unlock:
atomic_dec(THERM_REFCNT(family_data));
return ret;
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
static ssize_t w1_slave_store(struct device *device,
struct device_attribute *attr, const char *buf,
size_t size)
{
int val, ret;
struct w1_slave *sl = dev_to_w1_slave(device);
int i;
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(w1_therm_families); ++i) {
if (w1_therm_families[i].f->fid == sl->family->fid) {
if (val == 0)
ret = w1_therm_families[i].eeprom(device);
else
ret = w1_therm_families[i].precision(device, val);
break;
}
}
return ret ? : size;
}
static ssize_t w1_slave_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(device);
struct w1_master *dev = sl->master;
u8 rom[9], crc, verdict, external_power;
int i, ret, max_trying = 10;
ssize_t c = PAGE_SIZE;
u8 *family_data = sl->family_data;
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret != 0)
goto post_unlock;
if (!sl->family_data) {
ret = -ENODEV;
goto pre_unlock;
}
atomic_inc(THERM_REFCNT(family_data));
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
if (sleep_rem != 0) {
ret = -EINTR;
goto post_unlock;
}
ret = mutex_lock_interruptible(&dev->bus_mutex);
if (ret != 0)
goto post_unlock;
} else if (!w1_strong_pullup) {
sleep_rem = msleep_interruptible(tm);
if (sleep_rem != 0) {
ret = -EINTR;
goto pre_unlock;
}
}
if (!w1_reset_select_slave(sl)) {
w1_write_8(dev, W1_READ_SCRATCHPAD);
count = w1_read_block(dev, rom, 9);
if (count != 9) {
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
memcpy(family_data, rom, sizeof(rom));
else
dev_warn(device, "Read failed CRC check\n");
for (i = 0; i < 9; ++i)
c -= snprintf(buf + PAGE_SIZE - c, c, "%02x ",
((u8 *)family_data)[i]);
c -= snprintf(buf + PAGE_SIZE - c, c, "t=%d\n",
w1_convert_temp(rom, sl->family->fid));
ret = PAGE_SIZE - c;
pre_unlock:
mutex_unlock(&dev->bus_mutex);
post_unlock:
atomic_dec(THERM_REFCNT(family_data));
return ret;
}
static ssize_t w1_seq_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct w1_slave *sl = dev_to_w1_slave(device);
ssize_t c = PAGE_SIZE;
int rv;
int i;
u8 ack;
u64 rn;
struct w1_reg_num *reg_num;
int seq = 0;
mutex_lock(&sl->master->bus_mutex);
if (w1_reset_bus(sl->master))
goto error;
w1_write_8(sl->master, W1_SKIP_ROM);
w1_write_8(sl->master, W1_42_CHAIN);
w1_write_8(sl->master, W1_42_CHAIN_ON);
w1_write_8(sl->master, W1_42_CHAIN_ON_INV);
msleep(sl->master->pullup_duration);
ack = w1_read_8(sl->master);
if (ack != W1_42_SUCCESS_CONFIRM_BYTE)
goto error;
for (i = 0; i <= 64; i++) {
if (w1_reset_bus(sl->master))
goto error;
w1_write_8(sl->master, W1_42_COND_READ);
rv = w1_read_block(sl->master, (u8 *)&rn, 8);
reg_num = (struct w1_reg_num *) &rn;
if (reg_num->family == W1_42_FINISHED_BYTE)
break;
if (sl->reg_num.id == reg_num->id)
seq = i;
w1_write_8(sl->master, W1_42_CHAIN);
w1_write_8(sl->master, W1_42_CHAIN_DONE);
w1_write_8(sl->master, W1_42_CHAIN_DONE_INV);
w1_read_block(sl->master, &ack, sizeof(ack));
ack = w1_read_8(sl->master);
if (ack != W1_42_SUCCESS_CONFIRM_BYTE)
goto error;
}
if (w1_reset_bus(sl->master))
goto error;
w1_write_8(sl->master, W1_SKIP_ROM);
w1_write_8(sl->master, W1_42_CHAIN);
w1_write_8(sl->master, W1_42_CHAIN_OFF);
w1_write_8(sl->master, W1_42_CHAIN_OFF_INV);
ack = w1_read_8(sl->master);
if (ack != W1_42_SUCCESS_CONFIRM_BYTE)
goto error;
mutex_unlock(&sl->master->bus_mutex);
c -= snprintf(buf + PAGE_SIZE - c, c, "%d\n", seq);
return PAGE_SIZE - c;
error:
mutex_unlock(&sl->master->bus_mutex);
return -EIO;
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
