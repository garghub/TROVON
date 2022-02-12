static inline void pcf2123_delay_trec(void)
{
ndelay(30);
}
static int pcf2123_read(struct device *dev, u8 reg, u8 *rxbuf, size_t size)
{
struct spi_device *spi = to_spi_device(dev);
int ret;
reg |= PCF2123_READ;
ret = spi_write_then_read(spi, &reg, 1, rxbuf, size);
pcf2123_delay_trec();
return ret;
}
static int pcf2123_write(struct device *dev, u8 *txbuf, size_t size)
{
struct spi_device *spi = to_spi_device(dev);
int ret;
txbuf[0] |= PCF2123_WRITE;
ret = spi_write(spi, txbuf, size);
pcf2123_delay_trec();
return ret;
}
static int pcf2123_write_reg(struct device *dev, u8 reg, u8 val)
{
u8 txbuf[2];
txbuf[0] = reg;
txbuf[1] = val;
return pcf2123_write(dev, txbuf, sizeof(txbuf));
}
static ssize_t pcf2123_show(struct device *dev, struct device_attribute *attr,
char *buffer)
{
struct pcf2123_sysfs_reg *r;
u8 rxbuf[1];
unsigned long reg;
int ret;
r = container_of(attr, struct pcf2123_sysfs_reg, attr);
ret = kstrtoul(r->name, 16, &reg);
if (ret)
return ret;
ret = pcf2123_read(dev, reg, rxbuf, 1);
if (ret < 0)
return -EIO;
return sprintf(buffer, "0x%x\n", rxbuf[0]);
}
static ssize_t pcf2123_store(struct device *dev, struct device_attribute *attr,
const char *buffer, size_t count)
{
struct pcf2123_sysfs_reg *r;
unsigned long reg;
unsigned long val;
int ret;
r = container_of(attr, struct pcf2123_sysfs_reg, attr);
ret = kstrtoul(r->name, 16, &reg);
if (ret)
return ret;
ret = kstrtoul(buffer, 10, &val);
if (ret)
return ret;
ret = pcf2123_write_reg(dev, reg, val);
if (ret < 0)
return -EIO;
return count;
}
static int pcf2123_read_offset(struct device *dev, long *offset)
{
int ret;
s8 reg;
ret = pcf2123_read(dev, PCF2123_REG_OFFSET, &reg, 1);
if (ret < 0)
return ret;
if (reg & OFFSET_COARSE)
reg <<= 1;
else
reg = sign_extend32(reg, OFFSET_SIGN_BIT);
*offset = ((long)reg) * OFFSET_STEP;
return 0;
}
static int pcf2123_set_offset(struct device *dev, long offset)
{
s8 reg;
if (offset > OFFSET_STEP * 127)
reg = 127;
else if (offset < OFFSET_STEP * -128)
reg = -128;
else
reg = (s8)((offset + (OFFSET_STEP >> 1)) / OFFSET_STEP);
if (reg & 1 && reg <= 63 && reg >= -64) {
reg &= ~OFFSET_COARSE;
} else {
reg >>= 1;
reg |= OFFSET_COARSE;
}
return pcf2123_write_reg(dev, PCF2123_REG_OFFSET, reg);
}
static int pcf2123_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
u8 rxbuf[7];
int ret;
ret = pcf2123_read(dev, PCF2123_REG_SC, rxbuf, sizeof(rxbuf));
if (ret < 0)
return ret;
if (rxbuf[0] & OSC_HAS_STOPPED) {
dev_info(dev, "clock was stopped. Time is not valid\n");
return -EINVAL;
}
tm->tm_sec = bcd2bin(rxbuf[0] & 0x7F);
tm->tm_min = bcd2bin(rxbuf[1] & 0x7F);
tm->tm_hour = bcd2bin(rxbuf[2] & 0x3F);
tm->tm_mday = bcd2bin(rxbuf[3] & 0x3F);
tm->tm_wday = rxbuf[4] & 0x07;
tm->tm_mon = bcd2bin(rxbuf[5] & 0x1F) - 1;
tm->tm_year = bcd2bin(rxbuf[6]);
if (tm->tm_year < 70)
tm->tm_year += 100;
dev_dbg(dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
return rtc_valid_tm(tm);
}
static int pcf2123_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
u8 txbuf[8];
int ret;
dev_dbg(dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
ret = pcf2123_write_reg(dev, PCF2123_REG_CTRL1, CTRL1_STOP);
if (ret < 0)
return ret;
txbuf[0] = PCF2123_REG_SC;
txbuf[1] = bin2bcd(tm->tm_sec & 0x7F);
txbuf[2] = bin2bcd(tm->tm_min & 0x7F);
txbuf[3] = bin2bcd(tm->tm_hour & 0x3F);
txbuf[4] = bin2bcd(tm->tm_mday & 0x3F);
txbuf[5] = tm->tm_wday & 0x07;
txbuf[6] = bin2bcd((tm->tm_mon + 1) & 0x1F);
txbuf[7] = bin2bcd(tm->tm_year < 100 ? tm->tm_year : tm->tm_year - 100);
ret = pcf2123_write(dev, txbuf, sizeof(txbuf));
if (ret < 0)
return ret;
ret = pcf2123_write_reg(dev, PCF2123_REG_CTRL1, CTRL1_CLEAR);
if (ret < 0)
return ret;
return 0;
}
static int pcf2123_reset(struct device *dev)
{
int ret;
u8 rxbuf[2];
ret = pcf2123_write_reg(dev, PCF2123_REG_CTRL1, CTRL1_SW_RESET);
if (ret < 0)
return ret;
dev_dbg(dev, "stopping RTC\n");
ret = pcf2123_write_reg(dev, PCF2123_REG_CTRL1, CTRL1_STOP);
if (ret < 0)
return ret;
dev_dbg(dev, "checking for presence of RTC\n");
ret = pcf2123_read(dev, PCF2123_REG_CTRL1, rxbuf, sizeof(rxbuf));
if (ret < 0)
return ret;
dev_dbg(dev, "received data from RTC (0x%02X 0x%02X)\n",
rxbuf[0], rxbuf[1]);
if (!(rxbuf[0] & CTRL1_STOP))
return -ENODEV;
ret = pcf2123_write_reg(dev, PCF2123_REG_CTRL1, CTRL1_CLEAR);
if (ret < 0)
return ret;
return 0;
}
static int pcf2123_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
struct rtc_time tm;
struct pcf2123_plat_data *pdata;
int ret, i;
pdata = devm_kzalloc(&spi->dev, sizeof(struct pcf2123_plat_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
spi->dev.platform_data = pdata;
ret = pcf2123_rtc_read_time(&spi->dev, &tm);
if (ret < 0) {
ret = pcf2123_reset(&spi->dev);
if (ret < 0) {
dev_err(&spi->dev, "chip not found\n");
goto kfree_exit;
}
}
dev_info(&spi->dev, "spiclk %u KHz.\n",
(spi->max_speed_hz + 500) / 1000);
rtc = devm_rtc_device_register(&spi->dev, pcf2123_driver.driver.name,
&pcf2123_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
dev_err(&spi->dev, "failed to register.\n");
ret = PTR_ERR(rtc);
goto kfree_exit;
}
pdata->rtc = rtc;
for (i = 0; i < 16; i++) {
sysfs_attr_init(&pdata->regs[i].attr.attr);
sprintf(pdata->regs[i].name, "%1x", i);
pdata->regs[i].attr.attr.mode = S_IRUGO | S_IWUSR;
pdata->regs[i].attr.attr.name = pdata->regs[i].name;
pdata->regs[i].attr.show = pcf2123_show;
pdata->regs[i].attr.store = pcf2123_store;
ret = device_create_file(&spi->dev, &pdata->regs[i].attr);
if (ret) {
dev_err(&spi->dev, "Unable to create sysfs %s\n",
pdata->regs[i].name);
goto sysfs_exit;
}
}
return 0;
sysfs_exit:
for (i--; i >= 0; i--)
device_remove_file(&spi->dev, &pdata->regs[i].attr);
kfree_exit:
spi->dev.platform_data = NULL;
return ret;
}
static int pcf2123_remove(struct spi_device *spi)
{
struct pcf2123_plat_data *pdata = dev_get_platdata(&spi->dev);
int i;
if (pdata) {
for (i = 0; i < 16; i++)
if (pdata->regs[i].name[0])
device_remove_file(&spi->dev,
&pdata->regs[i].attr);
}
return 0;
}
