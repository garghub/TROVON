static ssize_t adt7316_show_enabled(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", !!(chip->config1 & ADT7316_EN));
}
static ssize_t _adt7316_store_enabled(struct adt7316_chip_info *chip,
int enable)
{
u8 config1;
int ret;
if (enable)
config1 = chip->config1 | ADT7316_EN;
else
config1 = chip->config1 & ~ADT7316_EN;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
if (ret)
return -EIO;
chip->config1 = config1;
return ret;
}
static ssize_t adt7316_store_enabled(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
int enable;
if (buf[0] == '1')
enable = 1;
else
enable = 0;
if (_adt7316_store_enabled(chip, enable) < 0)
return -EIO;
else
return len;
}
static ssize_t adt7316_show_select_ex_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
return -EPERM;
return sprintf(buf, "%d\n", !!(chip->config1 & ADT7516_SEL_EX_TEMP));
}
static ssize_t adt7316_store_select_ex_temp(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config1;
int ret;
if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
return -EPERM;
config1 = chip->config1 & (~ADT7516_SEL_EX_TEMP);
if (buf[0] == '1')
config1 |= ADT7516_SEL_EX_TEMP;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
if (ret)
return -EIO;
chip->config1 = config1;
return len;
}
static ssize_t adt7316_show_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if (chip->config2 & ADT7316_AD_SINGLE_CH_MODE)
return sprintf(buf, "single_channel\n");
else
return sprintf(buf, "round_robin\n");
}
static ssize_t adt7316_store_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config2;
int ret;
config2 = chip->config2 & (~ADT7316_AD_SINGLE_CH_MODE);
if (!memcmp(buf, "single_channel", 14))
config2 |= ADT7316_AD_SINGLE_CH_MODE;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
if (ret)
return -EIO;
chip->config2 = config2;
return len;
}
static ssize_t adt7316_show_all_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "single_channel\nround_robin\n");
}
static ssize_t adt7316_show_ad_channel(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if (!(chip->config2 & ADT7316_AD_SINGLE_CH_MODE))
return -EPERM;
switch (chip->config2 & ADT7516_AD_SINGLE_CH_MASK) {
case ADT7316_AD_SINGLE_CH_VDD:
return sprintf(buf, "0 - VDD\n");
case ADT7316_AD_SINGLE_CH_IN:
return sprintf(buf, "1 - Internal Temperature\n");
case ADT7316_AD_SINGLE_CH_EX:
if (((chip->id & ID_FAMILY_MASK) == ID_ADT75XX) &&
(chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0)
return sprintf(buf, "2 - AIN1\n");
else
return sprintf(buf, "2 - External Temperature\n");
case ADT7516_AD_SINGLE_CH_AIN2:
if ((chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0)
return sprintf(buf, "3 - AIN2\n");
else
return sprintf(buf, "N/A\n");
case ADT7516_AD_SINGLE_CH_AIN3:
if (chip->config1 & ADT7516_SEL_AIN3)
return sprintf(buf, "4 - AIN3\n");
else
return sprintf(buf, "N/A\n");
case ADT7516_AD_SINGLE_CH_AIN4:
return sprintf(buf, "5 - AIN4\n");
default:
return sprintf(buf, "N/A\n");
}
}
static ssize_t adt7316_store_ad_channel(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config2;
u8 data;
int ret;
if (!(chip->config2 & ADT7316_AD_SINGLE_CH_MODE))
return -EPERM;
ret = kstrtou8(buf, 10, &data);
if (ret)
return -EINVAL;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX) {
if (data > 5)
return -EINVAL;
config2 = chip->config2 & (~ADT7516_AD_SINGLE_CH_MASK);
} else {
if (data > 2)
return -EINVAL;
config2 = chip->config2 & (~ADT7316_AD_SINGLE_CH_MASK);
}
config2 |= data;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
if (ret)
return -EIO;
chip->config2 = config2;
return len;
}
static ssize_t adt7316_show_all_ad_channels(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if (!(chip->config2 & ADT7316_AD_SINGLE_CH_MODE))
return -EPERM;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return sprintf(buf, "0 - VDD\n1 - Internal Temperature\n"
"2 - External Temperature or AIN1\n"
"3 - AIN2\n4 - AIN3\n5 - AIN4\n");
else
return sprintf(buf, "0 - VDD\n1 - Internal Temperature\n"
"2 - External Temperature\n");
}
static ssize_t adt7316_show_disable_averaging(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n",
!!(chip->config2 & ADT7316_DISABLE_AVERAGING));
}
static ssize_t adt7316_store_disable_averaging(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config2;
int ret;
config2 = chip->config2 & (~ADT7316_DISABLE_AVERAGING);
if (buf[0] == '1')
config2 |= ADT7316_DISABLE_AVERAGING;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
if (ret)
return -EIO;
chip->config2 = config2;
return len;
}
static ssize_t adt7316_show_enable_smbus_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n",
!!(chip->config2 & ADT7316_EN_SMBUS_TIMEOUT));
}
static ssize_t adt7316_store_enable_smbus_timeout(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config2;
int ret;
config2 = chip->config2 & (~ADT7316_EN_SMBUS_TIMEOUT);
if (buf[0] == '1')
config2 |= ADT7316_EN_SMBUS_TIMEOUT;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
if (ret)
return -EIO;
chip->config2 = config2;
return len;
}
static ssize_t adt7316_show_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", !!(chip->config1 & ADT7316_PD));
}
static ssize_t adt7316_store_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config1;
int ret;
config1 = chip->config1 & (~ADT7316_PD);
if (buf[0] == '1')
config1 |= ADT7316_PD;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
if (ret)
return -EIO;
chip->config1 = config1;
return len;
}
static ssize_t adt7316_show_fast_ad_clock(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", !!(chip->config3 & ADT7316_ADCLK_22_5));
}
static ssize_t adt7316_store_fast_ad_clock(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config3;
int ret;
config3 = chip->config3 & (~ADT7316_ADCLK_22_5);
if (buf[0] == '1')
config3 |= ADT7316_ADCLK_22_5;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
if (ret)
return -EIO;
chip->config3 = config3;
return len;
}
static ssize_t adt7316_show_da_high_resolution(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if (chip->config3 & ADT7316_DA_HIGH_RESOLUTION) {
if (chip->id == ID_ADT7316 || chip->id == ID_ADT7516)
return sprintf(buf, "1 (12 bits)\n");
else if (chip->id == ID_ADT7317 || chip->id == ID_ADT7517)
return sprintf(buf, "1 (10 bits)\n");
}
return sprintf(buf, "0 (8 bits)\n");
}
static ssize_t adt7316_store_da_high_resolution(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config3;
int ret;
chip->dac_bits = 8;
if (buf[0] == '1') {
config3 = chip->config3 | ADT7316_DA_HIGH_RESOLUTION;
if (chip->id == ID_ADT7316 || chip->id == ID_ADT7516)
chip->dac_bits = 12;
else if (chip->id == ID_ADT7317 || chip->id == ID_ADT7517)
chip->dac_bits = 10;
} else
config3 = chip->config3 & (~ADT7316_DA_HIGH_RESOLUTION);
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
if (ret)
return -EIO;
chip->config3 = config3;
return len;
}
static ssize_t adt7316_show_AIN_internal_Vref(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
return -EPERM;
return sprintf(buf, "%d\n",
!!(chip->config3 & ADT7516_AIN_IN_VREF));
}
static ssize_t adt7316_store_AIN_internal_Vref(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config3;
int ret;
if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
return -EPERM;
if (buf[0] != '1')
config3 = chip->config3 & (~ADT7516_AIN_IN_VREF);
else
config3 = chip->config3 | ADT7516_AIN_IN_VREF;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
if (ret)
return -EIO;
chip->config3 = config3;
return len;
}
static ssize_t adt7316_show_enable_prop_DACA(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n",
!!(chip->config3 & ADT7316_EN_IN_TEMP_PROP_DACA));
}
static ssize_t adt7316_store_enable_prop_DACA(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config3;
int ret;
config3 = chip->config3 & (~ADT7316_EN_IN_TEMP_PROP_DACA);
if (buf[0] == '1')
config3 |= ADT7316_EN_IN_TEMP_PROP_DACA;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
if (ret)
return -EIO;
chip->config3 = config3;
return len;
}
static ssize_t adt7316_show_enable_prop_DACB(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n",
!!(chip->config3 & ADT7316_EN_EX_TEMP_PROP_DACB));
}
static ssize_t adt7316_store_enable_prop_DACB(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config3;
int ret;
config3 = chip->config3 & (~ADT7316_EN_EX_TEMP_PROP_DACB);
if (buf[0] == '1')
config3 |= ADT7316_EN_EX_TEMP_PROP_DACB;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
if (ret)
return -EIO;
chip->config3 = config3;
return len;
}
static ssize_t adt7316_show_DAC_2Vref_ch_mask(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%x\n",
chip->dac_config & ADT7316_DA_2VREF_CH_MASK);
}
static ssize_t adt7316_store_DAC_2Vref_ch_mask(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 dac_config;
u8 data;
int ret;
ret = kstrtou8(buf, 16, &data);
if (ret || data > ADT7316_DA_2VREF_CH_MASK)
return -EINVAL;
dac_config = chip->dac_config & (~ADT7316_DA_2VREF_CH_MASK);
dac_config |= data;
ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
if (ret)
return -EIO;
chip->dac_config = dac_config;
return len;
}
static ssize_t adt7316_show_DAC_update_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if (!(chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA))
return sprintf(buf, "manual\n");
else {
switch (chip->dac_config & ADT7316_DA_EN_MODE_MASK) {
case ADT7316_DA_EN_MODE_SINGLE:
return sprintf(buf, "0 - auto at any MSB DAC writing\n");
case ADT7316_DA_EN_MODE_AB_CD:
return sprintf(buf, "1 - auto at MSB DAC AB and CD writing\n");
case ADT7316_DA_EN_MODE_ABCD:
return sprintf(buf, "2 - auto at MSB DAC ABCD writing\n");
default:
return sprintf(buf, "3 - manual\n");
}
}
}
static ssize_t adt7316_store_DAC_update_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 dac_config;
u8 data;
int ret;
if (!(chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA))
return -EPERM;
ret = kstrtou8(buf, 10, &data);
if (ret || data > ADT7316_DA_EN_MODE_MASK)
return -EINVAL;
dac_config = chip->dac_config & (~ADT7316_DA_EN_MODE_MASK);
dac_config |= data;
ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
if (ret)
return -EIO;
chip->dac_config = dac_config;
return len;
}
static ssize_t adt7316_show_all_DAC_update_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if (chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA)
return sprintf(buf, "0 - auto at any MSB DAC writing\n"
"1 - auto at MSB DAC AB and CD writing\n"
"2 - auto at MSB DAC ABCD writing\n"
"3 - manual\n");
else
return sprintf(buf, "manual\n");
}
static ssize_t adt7316_store_update_DAC(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 ldac_config;
u8 data;
int ret;
if (chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA) {
if ((chip->dac_config & ADT7316_DA_EN_MODE_MASK) !=
ADT7316_DA_EN_MODE_LDAC)
return -EPERM;
ret = kstrtou8(buf, 16, &data);
if (ret || data > ADT7316_LDAC_EN_DA_MASK)
return -EINVAL;
ldac_config = chip->ldac_config & (~ADT7316_LDAC_EN_DA_MASK);
ldac_config |= data;
ret = chip->bus.write(chip->bus.client, ADT7316_LDAC_CONFIG,
ldac_config);
if (ret)
return -EIO;
} else {
gpio_set_value(chip->ldac_pin, 0);
gpio_set_value(chip->ldac_pin, 1);
}
return len;
}
static ssize_t adt7316_show_DA_AB_Vref_bypass(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return -EPERM;
return sprintf(buf, "%d\n",
!!(chip->dac_config & ADT7316_VREF_BYPASS_DAC_AB));
}
static ssize_t adt7316_store_DA_AB_Vref_bypass(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 dac_config;
int ret;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return -EPERM;
dac_config = chip->dac_config & (~ADT7316_VREF_BYPASS_DAC_AB);
if (buf[0] == '1')
dac_config |= ADT7316_VREF_BYPASS_DAC_AB;
ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
if (ret)
return -EIO;
chip->dac_config = dac_config;
return len;
}
static ssize_t adt7316_show_DA_CD_Vref_bypass(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return -EPERM;
return sprintf(buf, "%d\n",
!!(chip->dac_config & ADT7316_VREF_BYPASS_DAC_CD));
}
static ssize_t adt7316_store_DA_CD_Vref_bypass(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 dac_config;
int ret;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return -EPERM;
dac_config = chip->dac_config & (~ADT7316_VREF_BYPASS_DAC_CD);
if (buf[0] == '1')
dac_config |= ADT7316_VREF_BYPASS_DAC_CD;
ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
if (ret)
return -EIO;
chip->dac_config = dac_config;
return len;
}
static ssize_t adt7316_show_DAC_internal_Vref(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return sprintf(buf, "0x%x\n",
(chip->dac_config & ADT7516_DAC_IN_VREF_MASK) >>
ADT7516_DAC_IN_VREF_OFFSET);
else
return sprintf(buf, "%d\n",
!!(chip->dac_config & ADT7316_DAC_IN_VREF));
}
static ssize_t adt7316_store_DAC_internal_Vref(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 ldac_config;
u8 data;
int ret;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX) {
ret = kstrtou8(buf, 16, &data);
if (ret || data > 3)
return -EINVAL;
ldac_config = chip->ldac_config & (~ADT7516_DAC_IN_VREF_MASK);
if (data & 0x1)
ldac_config |= ADT7516_DAC_AB_IN_VREF;
else if (data & 0x2)
ldac_config |= ADT7516_DAC_CD_IN_VREF;
} else {
ret = kstrtou8(buf, 16, &data);
if (ret)
return -EINVAL;
ldac_config = chip->ldac_config & (~ADT7316_DAC_IN_VREF);
if (data)
ldac_config = chip->ldac_config | ADT7316_DAC_IN_VREF;
}
ret = chip->bus.write(chip->bus.client, ADT7316_LDAC_CONFIG, ldac_config);
if (ret)
return -EIO;
chip->ldac_config = ldac_config;
return len;
}
static ssize_t adt7316_show_ad(struct adt7316_chip_info *chip,
int channel, char *buf)
{
u16 data;
u8 msb, lsb;
char sign = ' ';
int ret;
if ((chip->config2 & ADT7316_AD_SINGLE_CH_MODE) &&
channel != (chip->config2 & ADT7516_AD_SINGLE_CH_MASK))
return -EPERM;
switch (channel) {
case ADT7316_AD_SINGLE_CH_IN:
ret = chip->bus.read(chip->bus.client,
ADT7316_LSB_IN_TEMP_VDD, &lsb);
if (ret)
return -EIO;
ret = chip->bus.read(chip->bus.client,
ADT7316_AD_MSB_DATA_BASE + channel, &msb);
if (ret)
return -EIO;
data = msb << ADT7316_T_VALUE_FLOAT_OFFSET;
data |= lsb & ADT7316_LSB_IN_TEMP_MASK;
break;
case ADT7316_AD_SINGLE_CH_VDD:
ret = chip->bus.read(chip->bus.client,
ADT7316_LSB_IN_TEMP_VDD, &lsb);
if (ret)
return -EIO;
ret = chip->bus.read(chip->bus.client,
ADT7316_AD_MSB_DATA_BASE + channel, &msb);
if (ret)
return -EIO;
data = msb << ADT7316_T_VALUE_FLOAT_OFFSET;
data |= (lsb & ADT7316_LSB_VDD_MASK) >> ADT7316_LSB_VDD_OFFSET;
return sprintf(buf, "%d\n", data);
default:
ret = chip->bus.read(chip->bus.client,
ADT7316_LSB_EX_TEMP_AIN, &lsb);
if (ret)
return -EIO;
ret = chip->bus.read(chip->bus.client,
ADT7316_AD_MSB_DATA_BASE + channel, &msb);
if (ret)
return -EIO;
data = msb << ADT7316_T_VALUE_FLOAT_OFFSET;
data |= lsb & (ADT7316_LSB_EX_TEMP_MASK <<
(ADT7516_LSB_AIN_SHIFT * (channel -
(ADT7316_MSB_EX_TEMP - ADT7316_AD_MSB_DATA_BASE))));
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
return sprintf(buf, "%d\n", data);
else
break;
}
if (data & ADT7316_T_VALUE_SIGN) {
data = (ADT7316_T_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.2d\n", sign,
(data >> ADT7316_T_VALUE_FLOAT_OFFSET),
(data & ADT7316_T_VALUE_FLOAT_MASK) * 25);
}
static ssize_t adt7316_show_VDD(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_ad(chip, ADT7316_AD_SINGLE_CH_VDD, buf);
}
static ssize_t adt7316_show_in_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_ad(chip, ADT7316_AD_SINGLE_CH_IN, buf);
}
static ssize_t adt7316_show_ex_temp_AIN1(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_ad(chip, ADT7316_AD_SINGLE_CH_EX, buf);
}
static ssize_t adt7316_show_AIN2(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_ad(chip, ADT7516_AD_SINGLE_CH_AIN2, buf);
}
static ssize_t adt7316_show_AIN3(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_ad(chip, ADT7516_AD_SINGLE_CH_AIN3, buf);
}
static ssize_t adt7316_show_AIN4(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_ad(chip, ADT7516_AD_SINGLE_CH_AIN4, buf);
}
static ssize_t adt7316_show_temp_offset(struct adt7316_chip_info *chip,
int offset_addr, char *buf)
{
int data;
u8 val;
int ret;
ret = chip->bus.read(chip->bus.client, offset_addr, &val);
if (ret)
return -EIO;
data = (int)val;
if (val & 0x80)
data -= 256;
return sprintf(buf, "%d\n", data);
}
static ssize_t adt7316_store_temp_offset(struct adt7316_chip_info *chip,
int offset_addr, const char *buf, size_t len)
{
int data;
u8 val;
int ret;
ret = kstrtoint(buf, 10, &data);
if (ret || data > 127 || data < -128)
return -EINVAL;
if (data < 0)
data += 256;
val = (u8)data;
ret = chip->bus.write(chip->bus.client, offset_addr, val);
if (ret)
return -EIO;
return len;
}
static ssize_t adt7316_show_in_temp_offset(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_temp_offset(chip, ADT7316_IN_TEMP_OFFSET, buf);
}
static ssize_t adt7316_store_in_temp_offset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_temp_offset(chip, ADT7316_IN_TEMP_OFFSET, buf, len);
}
static ssize_t adt7316_show_ex_temp_offset(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_temp_offset(chip, ADT7316_EX_TEMP_OFFSET, buf);
}
static ssize_t adt7316_store_ex_temp_offset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_temp_offset(chip, ADT7316_EX_TEMP_OFFSET, buf, len);
}
static ssize_t adt7316_show_in_analog_temp_offset(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_temp_offset(chip,
ADT7316_IN_ANALOG_TEMP_OFFSET, buf);
}
static ssize_t adt7316_store_in_analog_temp_offset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_temp_offset(chip,
ADT7316_IN_ANALOG_TEMP_OFFSET, buf, len);
}
static ssize_t adt7316_show_ex_analog_temp_offset(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_temp_offset(chip,
ADT7316_EX_ANALOG_TEMP_OFFSET, buf);
}
static ssize_t adt7316_store_ex_analog_temp_offset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_temp_offset(chip,
ADT7316_EX_ANALOG_TEMP_OFFSET, buf, len);
}
static ssize_t adt7316_show_DAC(struct adt7316_chip_info *chip,
int channel, char *buf)
{
u16 data;
u8 msb, lsb, offset;
int ret;
if (channel >= ADT7316_DA_MSB_DATA_REGS ||
(channel == 0 &&
(chip->config3 & ADT7316_EN_IN_TEMP_PROP_DACA)) ||
(channel == 1 &&
(chip->config3 & ADT7316_EN_EX_TEMP_PROP_DACB)))
return -EPERM;
offset = chip->dac_bits - 8;
if (chip->dac_bits > 8) {
ret = chip->bus.read(chip->bus.client,
ADT7316_DA_DATA_BASE + channel * 2, &lsb);
if (ret)
return -EIO;
}
ret = chip->bus.read(chip->bus.client,
ADT7316_DA_DATA_BASE + 1 + channel * 2, &msb);
if (ret)
return -EIO;
data = (msb << offset) + (lsb & ((1 << offset) - 1));
return sprintf(buf, "%d\n", data);
}
static ssize_t adt7316_store_DAC(struct adt7316_chip_info *chip,
int channel, const char *buf, size_t len)
{
u8 msb, lsb, offset;
u16 data;
int ret;
if (channel >= ADT7316_DA_MSB_DATA_REGS ||
(channel == 0 &&
(chip->config3 & ADT7316_EN_IN_TEMP_PROP_DACA)) ||
(channel == 1 &&
(chip->config3 & ADT7316_EN_EX_TEMP_PROP_DACB)))
return -EPERM;
offset = chip->dac_bits - 8;
ret = kstrtou16(buf, 10, &data);
if (ret || data >= (1 << chip->dac_bits))
return -EINVAL;
if (chip->dac_bits > 8) {
lsb = data & (1 << offset);
ret = chip->bus.write(chip->bus.client,
ADT7316_DA_DATA_BASE + channel * 2, lsb);
if (ret)
return -EIO;
}
msb = data >> offset;
ret = chip->bus.write(chip->bus.client,
ADT7316_DA_DATA_BASE + 1 + channel * 2, msb);
if (ret)
return -EIO;
return len;
}
static ssize_t adt7316_show_DAC_A(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_DAC(chip, 0, buf);
}
static ssize_t adt7316_store_DAC_A(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_DAC(chip, 0, buf, len);
}
static ssize_t adt7316_show_DAC_B(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_DAC(chip, 1, buf);
}
static ssize_t adt7316_store_DAC_B(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_DAC(chip, 1, buf, len);
}
static ssize_t adt7316_show_DAC_C(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_DAC(chip, 2, buf);
}
static ssize_t adt7316_store_DAC_C(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_DAC(chip, 2, buf, len);
}
static ssize_t adt7316_show_DAC_D(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_show_DAC(chip, 3, buf);
}
static ssize_t adt7316_store_DAC_D(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return adt7316_store_DAC(chip, 3, buf, len);
}
static ssize_t adt7316_show_device_id(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 id;
int ret;
ret = chip->bus.read(chip->bus.client, ADT7316_DEVICE_ID, &id);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", id);
}
static ssize_t adt7316_show_manufactorer_id(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 id;
int ret;
ret = chip->bus.read(chip->bus.client, ADT7316_MANUFACTURE_ID, &id);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", id);
}
static ssize_t adt7316_show_device_rev(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 rev;
int ret;
ret = chip->bus.read(chip->bus.client, ADT7316_DEVICE_REV, &rev);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", rev);
}
static ssize_t adt7316_show_bus_type(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 stat;
int ret;
ret = chip->bus.read(chip->bus.client, ADT7316_SPI_LOCK_STAT, &stat);
if (ret)
return -EIO;
if (stat)
return sprintf(buf, "spi\n");
else
return sprintf(buf, "i2c\n");
}
static irqreturn_t adt7316_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct adt7316_chip_info *chip = iio_priv(indio_dev);
u8 stat1, stat2;
int ret;
s64 time;
ret = chip->bus.read(chip->bus.client, ADT7316_INT_STAT1, &stat1);
if (!ret) {
if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
stat1 &= 0x1F;
time = iio_get_time_ns();
if (stat1 & (1 << 0))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
time);
if (stat1 & (1 << 1))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
time);
if (stat1 & (1 << 2))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
time);
if (stat1 & (1 << 3))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
time);
if (stat1 & (1 << 5))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, 1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
time);
if (stat1 & (1 << 6))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, 2,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
time);
if (stat1 & (1 << 7))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, 3,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
time);
}
ret = chip->bus.read(chip->bus.client, ADT7316_INT_STAT2, &stat2);
if (!ret) {
if (stat2 & ADT7316_INT_MASK2_VDD)
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
iio_get_time_ns());
}
return IRQ_HANDLED;
}
static ssize_t adt7316_show_int_mask(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%x\n", chip->int_mask);
}
static ssize_t adt7316_set_int_mask(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u16 data;
int ret;
u8 mask;
ret = kstrtou16(buf, 16, &data);
if (ret || data >= ADT7316_VDD_INT_MASK + 1)
return -EINVAL;
if (data & ADT7316_VDD_INT_MASK)
mask = 0;
else
mask = ADT7316_INT_MASK2_VDD;
ret = chip->bus.write(chip->bus.client, ADT7316_INT_MASK2, mask);
if (!ret) {
chip->int_mask &= ~ADT7316_VDD_INT_MASK;
chip->int_mask |= data & ADT7316_VDD_INT_MASK;
}
if (data & ADT7316_TEMP_AIN_INT_MASK) {
if ((chip->id & ID_FAMILY_MASK) == ID_ADT73XX)
mask = (~data) & ADT7316_TEMP_INT_MASK;
else
mask = (~data) & ADT7316_TEMP_AIN_INT_MASK;
}
ret = chip->bus.write(chip->bus.client, ADT7316_INT_MASK1, mask);
chip->int_mask = mask;
return len;
}
static inline ssize_t adt7316_show_ad_bound(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 val;
int data;
int ret;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT73XX &&
this_attr->address > ADT7316_EX_TEMP_LOW)
return -EPERM;
ret = chip->bus.read(chip->bus.client, this_attr->address, &val);
if (ret)
return -EIO;
data = (int)val;
if (!((chip->id & ID_FAMILY_MASK) == ID_ADT75XX &&
(chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0)) {
if (data & 0x80)
data -= 256;
}
return sprintf(buf, "%d\n", data);
}
static inline ssize_t adt7316_set_ad_bound(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
int data;
u8 val;
int ret;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT73XX &&
this_attr->address > ADT7316_EX_TEMP_LOW)
return -EPERM;
ret = kstrtoint(buf, 10, &data);
if (ret)
return -EINVAL;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX &&
(chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0) {
if (data > 255 || data < 0)
return -EINVAL;
} else {
if (data > 127 || data < -128)
return -EINVAL;
if (data < 0)
data += 256;
}
val = (u8)data;
ret = chip->bus.write(chip->bus.client, this_attr->address, val);
if (ret)
return -EIO;
return len;
}
static ssize_t adt7316_show_int_enabled(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", !!(chip->config1 & ADT7316_INT_EN));
}
static ssize_t adt7316_set_int_enabled(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_to_iio_dev(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
u8 config1;
int ret;
config1 = chip->config1 & (~ADT7316_INT_EN);
if (buf[0] == '1')
config1 |= ADT7316_INT_EN;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
if (ret)
return -EIO;
chip->config1 = config1;
return len;
}
static int adt7316_disable(struct device *dev)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return _adt7316_store_enabled(chip, 0);
}
static int adt7316_enable(struct device *dev)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7316_chip_info *chip = iio_priv(dev_info);
return _adt7316_store_enabled(chip, 1);
}
int adt7316_probe(struct device *dev, struct adt7316_bus *bus,
const char *name)
{
struct adt7316_chip_info *chip;
struct iio_dev *indio_dev;
unsigned short *adt7316_platform_data = dev->platform_data;
int ret = 0;
indio_dev = devm_iio_device_alloc(dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
dev_set_drvdata(dev, indio_dev);
chip->bus = *bus;
if (name[4] == '3')
chip->id = ID_ADT7316 + (name[6] - '6');
else if (name[4] == '5')
chip->id = ID_ADT7516 + (name[6] - '6');
else
return -ENODEV;
chip->ldac_pin = adt7316_platform_data[1];
if (chip->ldac_pin) {
chip->config3 |= ADT7316_DA_EN_VIA_DAC_LDCA;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
chip->config1 |= ADT7516_SEL_AIN3;
}
chip->int_mask = ADT7316_TEMP_INT_MASK | ADT7316_VDD_INT_MASK;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
chip->int_mask |= ADT7516_AIN_INT_MASK;
indio_dev->dev.parent = dev;
if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
indio_dev->info = &adt7516_info;
else
indio_dev->info = &adt7316_info;
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
if (chip->bus.irq > 0) {
if (adt7316_platform_data[0])
chip->bus.irq_flags = adt7316_platform_data[0];
ret = devm_request_threaded_irq(dev, chip->bus.irq,
NULL,
&adt7316_event_handler,
chip->bus.irq_flags |
IRQF_ONESHOT,
indio_dev->name,
indio_dev);
if (ret)
return ret;
if (chip->bus.irq_flags & IRQF_TRIGGER_HIGH)
chip->config1 |= ADT7316_INT_POLARITY;
}
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, chip->config1);
if (ret)
return -EIO;
ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, chip->config3);
if (ret)
return -EIO;
ret = iio_device_register(indio_dev);
if (ret)
return ret;
dev_info(dev, "%s temperature sensor, ADC and DAC registered.\n",
indio_dev->name);
return 0;
}
int adt7316_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
iio_device_unregister(indio_dev);
return 0;
}
