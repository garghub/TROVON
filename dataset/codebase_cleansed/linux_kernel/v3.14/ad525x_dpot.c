static inline int dpot_read_d8(struct dpot_data *dpot)
{
return dpot->bdata.bops->read_d8(dpot->bdata.client);
}
static inline int dpot_read_r8d8(struct dpot_data *dpot, u8 reg)
{
return dpot->bdata.bops->read_r8d8(dpot->bdata.client, reg);
}
static inline int dpot_read_r8d16(struct dpot_data *dpot, u8 reg)
{
return dpot->bdata.bops->read_r8d16(dpot->bdata.client, reg);
}
static inline int dpot_write_d8(struct dpot_data *dpot, u8 val)
{
return dpot->bdata.bops->write_d8(dpot->bdata.client, val);
}
static inline int dpot_write_r8d8(struct dpot_data *dpot, u8 reg, u16 val)
{
return dpot->bdata.bops->write_r8d8(dpot->bdata.client, reg, val);
}
static inline int dpot_write_r8d16(struct dpot_data *dpot, u8 reg, u16 val)
{
return dpot->bdata.bops->write_r8d16(dpot->bdata.client, reg, val);
}
static s32 dpot_read_spi(struct dpot_data *dpot, u8 reg)
{
unsigned ctrl = 0;
int value;
if (!(reg & (DPOT_ADDR_EEPROM | DPOT_ADDR_CMD))) {
if (dpot->feat & F_RDACS_WONLY)
return dpot->rdac_cache[reg & DPOT_RDAC_MASK];
if (dpot->uid == DPOT_UID(AD5291_ID) ||
dpot->uid == DPOT_UID(AD5292_ID) ||
dpot->uid == DPOT_UID(AD5293_ID)) {
value = dpot_read_r8d8(dpot,
DPOT_AD5291_READ_RDAC << 2);
if (dpot->uid == DPOT_UID(AD5291_ID))
value = value >> 2;
return value;
} else if (dpot->uid == DPOT_UID(AD5270_ID) ||
dpot->uid == DPOT_UID(AD5271_ID)) {
value = dpot_read_r8d8(dpot,
DPOT_AD5270_1_2_4_READ_RDAC << 2);
if (value < 0)
return value;
if (dpot->uid == DPOT_UID(AD5271_ID))
value = value >> 2;
return value;
}
ctrl = DPOT_SPI_READ_RDAC;
} else if (reg & DPOT_ADDR_EEPROM) {
ctrl = DPOT_SPI_READ_EEPROM;
}
if (dpot->feat & F_SPI_16BIT)
return dpot_read_r8d8(dpot, ctrl);
else if (dpot->feat & F_SPI_24BIT)
return dpot_read_r8d16(dpot, ctrl);
return -EFAULT;
}
static s32 dpot_read_i2c(struct dpot_data *dpot, u8 reg)
{
int value;
unsigned ctrl = 0;
switch (dpot->uid) {
case DPOT_UID(AD5246_ID):
case DPOT_UID(AD5247_ID):
return dpot_read_d8(dpot);
case DPOT_UID(AD5245_ID):
case DPOT_UID(AD5241_ID):
case DPOT_UID(AD5242_ID):
case DPOT_UID(AD5243_ID):
case DPOT_UID(AD5248_ID):
case DPOT_UID(AD5280_ID):
case DPOT_UID(AD5282_ID):
ctrl = ((reg & DPOT_RDAC_MASK) == DPOT_RDAC0) ?
0 : DPOT_AD5282_RDAC_AB;
return dpot_read_r8d8(dpot, ctrl);
case DPOT_UID(AD5170_ID):
case DPOT_UID(AD5171_ID):
case DPOT_UID(AD5273_ID):
return dpot_read_d8(dpot);
case DPOT_UID(AD5172_ID):
case DPOT_UID(AD5173_ID):
ctrl = ((reg & DPOT_RDAC_MASK) == DPOT_RDAC0) ?
0 : DPOT_AD5172_3_A0;
return dpot_read_r8d8(dpot, ctrl);
case DPOT_UID(AD5272_ID):
case DPOT_UID(AD5274_ID):
dpot_write_r8d8(dpot,
(DPOT_AD5270_1_2_4_READ_RDAC << 2), 0);
value = dpot_read_r8d16(dpot,
DPOT_AD5270_1_2_4_RDAC << 2);
if (value < 0)
return value;
value = swab16(value);
if (dpot->uid == DPOT_UID(AD5271_ID))
value = value >> 2;
return value;
default:
if ((reg & DPOT_REG_TOL) || (dpot->max_pos > 256))
return dpot_read_r8d16(dpot, (reg & 0xF8) |
((reg & 0x7) << 1));
else
return dpot_read_r8d8(dpot, reg);
}
}
static s32 dpot_read(struct dpot_data *dpot, u8 reg)
{
if (dpot->feat & F_SPI)
return dpot_read_spi(dpot, reg);
else
return dpot_read_i2c(dpot, reg);
}
static s32 dpot_write_spi(struct dpot_data *dpot, u8 reg, u16 value)
{
unsigned val = 0;
if (!(reg & (DPOT_ADDR_EEPROM | DPOT_ADDR_CMD | DPOT_ADDR_OTP))) {
if (dpot->feat & F_RDACS_WONLY)
dpot->rdac_cache[reg & DPOT_RDAC_MASK] = value;
if (dpot->feat & F_AD_APPDATA) {
if (dpot->feat & F_SPI_8BIT) {
val = ((reg & DPOT_RDAC_MASK) <<
DPOT_MAX_POS(dpot->devid)) |
value;
return dpot_write_d8(dpot, val);
} else if (dpot->feat & F_SPI_16BIT) {
val = ((reg & DPOT_RDAC_MASK) <<
DPOT_MAX_POS(dpot->devid)) |
value;
return dpot_write_r8d8(dpot, val >> 8,
val & 0xFF);
} else
BUG();
} else {
if (dpot->uid == DPOT_UID(AD5291_ID) ||
dpot->uid == DPOT_UID(AD5292_ID) ||
dpot->uid == DPOT_UID(AD5293_ID)) {
dpot_write_r8d8(dpot, DPOT_AD5291_CTRLREG << 2,
DPOT_AD5291_UNLOCK_CMD);
if (dpot->uid == DPOT_UID(AD5291_ID))
value = value << 2;
return dpot_write_r8d8(dpot,
(DPOT_AD5291_RDAC << 2) |
(value >> 8), value & 0xFF);
} else if (dpot->uid == DPOT_UID(AD5270_ID) ||
dpot->uid == DPOT_UID(AD5271_ID)) {
dpot_write_r8d8(dpot,
DPOT_AD5270_1_2_4_CTRLREG << 2,
DPOT_AD5270_1_2_4_UNLOCK_CMD);
if (dpot->uid == DPOT_UID(AD5271_ID))
value = value << 2;
return dpot_write_r8d8(dpot,
(DPOT_AD5270_1_2_4_RDAC << 2) |
(value >> 8), value & 0xFF);
}
val = DPOT_SPI_RDAC | (reg & DPOT_RDAC_MASK);
}
} else if (reg & DPOT_ADDR_EEPROM) {
val = DPOT_SPI_EEPROM | (reg & DPOT_RDAC_MASK);
} else if (reg & DPOT_ADDR_CMD) {
switch (reg) {
case DPOT_DEC_ALL_6DB:
val = DPOT_SPI_DEC_ALL_6DB;
break;
case DPOT_INC_ALL_6DB:
val = DPOT_SPI_INC_ALL_6DB;
break;
case DPOT_DEC_ALL:
val = DPOT_SPI_DEC_ALL;
break;
case DPOT_INC_ALL:
val = DPOT_SPI_INC_ALL;
break;
}
} else if (reg & DPOT_ADDR_OTP) {
if (dpot->uid == DPOT_UID(AD5291_ID) ||
dpot->uid == DPOT_UID(AD5292_ID)) {
return dpot_write_r8d8(dpot,
DPOT_AD5291_STORE_XTPM << 2, 0);
} else if (dpot->uid == DPOT_UID(AD5270_ID) ||
dpot->uid == DPOT_UID(AD5271_ID)) {
return dpot_write_r8d8(dpot,
DPOT_AD5270_1_2_4_STORE_XTPM << 2, 0);
}
} else
BUG();
if (dpot->feat & F_SPI_16BIT)
return dpot_write_r8d8(dpot, val, value);
else if (dpot->feat & F_SPI_24BIT)
return dpot_write_r8d16(dpot, val, value);
return -EFAULT;
}
static s32 dpot_write_i2c(struct dpot_data *dpot, u8 reg, u16 value)
{
unsigned tmp = 0, ctrl = 0;
switch (dpot->uid) {
case DPOT_UID(AD5246_ID):
case DPOT_UID(AD5247_ID):
return dpot_write_d8(dpot, value);
break;
case DPOT_UID(AD5245_ID):
case DPOT_UID(AD5241_ID):
case DPOT_UID(AD5242_ID):
case DPOT_UID(AD5243_ID):
case DPOT_UID(AD5248_ID):
case DPOT_UID(AD5280_ID):
case DPOT_UID(AD5282_ID):
ctrl = ((reg & DPOT_RDAC_MASK) == DPOT_RDAC0) ?
0 : DPOT_AD5282_RDAC_AB;
return dpot_write_r8d8(dpot, ctrl, value);
break;
case DPOT_UID(AD5171_ID):
case DPOT_UID(AD5273_ID):
if (reg & DPOT_ADDR_OTP) {
tmp = dpot_read_d8(dpot);
if (tmp >> 6)
return -EFAULT;
ctrl = DPOT_AD5273_FUSE;
}
return dpot_write_r8d8(dpot, ctrl, value);
break;
case DPOT_UID(AD5172_ID):
case DPOT_UID(AD5173_ID):
ctrl = ((reg & DPOT_RDAC_MASK) == DPOT_RDAC0) ?
0 : DPOT_AD5172_3_A0;
if (reg & DPOT_ADDR_OTP) {
tmp = dpot_read_r8d16(dpot, ctrl);
if (tmp >> 14)
return -EFAULT;
ctrl |= DPOT_AD5170_2_3_FUSE;
}
return dpot_write_r8d8(dpot, ctrl, value);
break;
case DPOT_UID(AD5170_ID):
if (reg & DPOT_ADDR_OTP) {
tmp = dpot_read_r8d16(dpot, tmp);
if (tmp >> 14)
return -EFAULT;
ctrl = DPOT_AD5170_2_3_FUSE;
}
return dpot_write_r8d8(dpot, ctrl, value);
break;
case DPOT_UID(AD5272_ID):
case DPOT_UID(AD5274_ID):
dpot_write_r8d8(dpot, DPOT_AD5270_1_2_4_CTRLREG << 2,
DPOT_AD5270_1_2_4_UNLOCK_CMD);
if (reg & DPOT_ADDR_OTP)
return dpot_write_r8d8(dpot,
DPOT_AD5270_1_2_4_STORE_XTPM << 2, 0);
if (dpot->uid == DPOT_UID(AD5274_ID))
value = value << 2;
return dpot_write_r8d8(dpot, (DPOT_AD5270_1_2_4_RDAC << 2) |
(value >> 8), value & 0xFF);
break;
default:
if (reg & DPOT_ADDR_CMD)
return dpot_write_d8(dpot, reg);
if (dpot->max_pos > 256)
return dpot_write_r8d16(dpot, (reg & 0xF8) |
((reg & 0x7) << 1), value);
else
return dpot_write_r8d8(dpot, reg, value);
}
}
static s32 dpot_write(struct dpot_data *dpot, u8 reg, u16 value)
{
if (dpot->feat & F_SPI)
return dpot_write_spi(dpot, reg, value);
else
return dpot_write_i2c(dpot, reg, value);
}
static ssize_t sysfs_show_reg(struct device *dev,
struct device_attribute *attr,
char *buf, u32 reg)
{
struct dpot_data *data = dev_get_drvdata(dev);
s32 value;
if (reg & DPOT_ADDR_OTP_EN)
return sprintf(buf, "%s\n",
test_bit(DPOT_RDAC_MASK & reg, data->otp_en_mask) ?
"enabled" : "disabled");
mutex_lock(&data->update_lock);
value = dpot_read(data, reg);
mutex_unlock(&data->update_lock);
if (value < 0)
return -EINVAL;
if (reg & DPOT_REG_TOL)
return sprintf(buf, "0x%04x\n", value & 0xFFFF);
else
return sprintf(buf, "%u\n", value & data->rdac_mask);
}
static ssize_t sysfs_set_reg(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count, u32 reg)
{
struct dpot_data *data = dev_get_drvdata(dev);
unsigned long value;
int err;
if (reg & DPOT_ADDR_OTP_EN) {
if (!strncmp(buf, "enabled", sizeof("enabled")))
set_bit(DPOT_RDAC_MASK & reg, data->otp_en_mask);
else
clear_bit(DPOT_RDAC_MASK & reg, data->otp_en_mask);
return count;
}
if ((reg & DPOT_ADDR_OTP) &&
!test_bit(DPOT_RDAC_MASK & reg, data->otp_en_mask))
return -EPERM;
err = kstrtoul(buf, 10, &value);
if (err)
return err;
if (value > data->rdac_mask)
value = data->rdac_mask;
mutex_lock(&data->update_lock);
dpot_write(data, reg, value);
if (reg & DPOT_ADDR_EEPROM)
msleep(26);
else if (reg & DPOT_ADDR_OTP)
msleep(400);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t sysfs_do_cmd(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count, u32 reg)
{
struct dpot_data *data = dev_get_drvdata(dev);
mutex_lock(&data->update_lock);
dpot_write(data, reg, 0);
mutex_unlock(&data->update_lock);
return count;
}
static int ad_dpot_add_files(struct device *dev,
unsigned features, unsigned rdac)
{
int err = sysfs_create_file(&dev->kobj,
dpot_attrib_wipers[rdac]);
if (features & F_CMD_EEP)
err |= sysfs_create_file(&dev->kobj,
dpot_attrib_eeprom[rdac]);
if (features & F_CMD_TOL)
err |= sysfs_create_file(&dev->kobj,
dpot_attrib_tolerance[rdac]);
if (features & F_CMD_OTP) {
err |= sysfs_create_file(&dev->kobj,
dpot_attrib_otp_en[rdac]);
err |= sysfs_create_file(&dev->kobj,
dpot_attrib_otp[rdac]);
}
if (err)
dev_err(dev, "failed to register sysfs hooks for RDAC%d\n",
rdac);
return err;
}
static inline void ad_dpot_remove_files(struct device *dev,
unsigned features, unsigned rdac)
{
sysfs_remove_file(&dev->kobj,
dpot_attrib_wipers[rdac]);
if (features & F_CMD_EEP)
sysfs_remove_file(&dev->kobj,
dpot_attrib_eeprom[rdac]);
if (features & F_CMD_TOL)
sysfs_remove_file(&dev->kobj,
dpot_attrib_tolerance[rdac]);
if (features & F_CMD_OTP) {
sysfs_remove_file(&dev->kobj,
dpot_attrib_otp_en[rdac]);
sysfs_remove_file(&dev->kobj,
dpot_attrib_otp[rdac]);
}
}
int ad_dpot_probe(struct device *dev,
struct ad_dpot_bus_data *bdata, unsigned long devid,
const char *name)
{
struct dpot_data *data;
int i, err = 0;
data = kzalloc(sizeof(struct dpot_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
dev_set_drvdata(dev, data);
mutex_init(&data->update_lock);
data->bdata = *bdata;
data->devid = devid;
data->max_pos = 1 << DPOT_MAX_POS(devid);
data->rdac_mask = data->max_pos - 1;
data->feat = DPOT_FEAT(devid);
data->uid = DPOT_UID(devid);
data->wipers = DPOT_WIPERS(devid);
for (i = DPOT_RDAC0; i < MAX_RDACS; i++)
if (data->wipers & (1 << i)) {
err = ad_dpot_add_files(dev, data->feat, i);
if (err)
goto exit_remove_files;
if (data->feat & F_RDACS_WONLY)
data->rdac_cache[i] = data->max_pos / 2;
}
if (data->feat & F_CMD_INC)
err = sysfs_create_group(&dev->kobj, &ad525x_group_commands);
if (err) {
dev_err(dev, "failed to register sysfs hooks\n");
goto exit_free;
}
dev_info(dev, "%s %d-Position Digital Potentiometer registered\n",
name, data->max_pos);
return 0;
exit_remove_files:
for (i = DPOT_RDAC0; i < MAX_RDACS; i++)
if (data->wipers & (1 << i))
ad_dpot_remove_files(dev, data->feat, i);
exit_free:
kfree(data);
dev_set_drvdata(dev, NULL);
exit:
dev_err(dev, "failed to create client for %s ID 0x%lX\n",
name, devid);
return err;
}
int ad_dpot_remove(struct device *dev)
{
struct dpot_data *data = dev_get_drvdata(dev);
int i;
for (i = DPOT_RDAC0; i < MAX_RDACS; i++)
if (data->wipers & (1 << i))
ad_dpot_remove_files(dev, data->feat, i);
kfree(data);
return 0;
}
