static void rs5c313_init_port(void)
{
__raw_writeb(__raw_readb(SCSMR1) & ~SCSMR1_CA, SCSMR1);
__raw_writeb(__raw_readb(SCSCR1) & ~SCSCR1_CKE, SCSCR1);
scsptr1_data = __raw_readb(SCSPTR1) | SCL;
__raw_writeb(scsptr1_data, SCSPTR1);
scsptr1_data = __raw_readb(SCSPTR1) | SCL_OEN;
__raw_writeb(scsptr1_data, SCSPTR1);
RS5C313_CEDISABLE;
}
static void rs5c313_write_data(unsigned char data)
{
int i;
for (i = 0; i < 8; i++) {
scsptr1_data = (scsptr1_data & ~SDA) |
((((0x80 >> i) & data) >> (7 - i)) << 2);
__raw_writeb(scsptr1_data, SCSPTR1);
if (i == 0) {
scsptr1_data |= SDA_OEN;
__raw_writeb(scsptr1_data, SCSPTR1);
}
ndelay(700);
scsptr1_data &= ~SCL;
__raw_writeb(scsptr1_data, SCSPTR1);
ndelay(700);
scsptr1_data |= SCL;
__raw_writeb(scsptr1_data, SCSPTR1);
}
scsptr1_data &= ~SDA_OEN;
__raw_writeb(scsptr1_data, SCSPTR1);
}
static unsigned char rs5c313_read_data(void)
{
int i;
unsigned char data = 0;
for (i = 0; i < 8; i++) {
ndelay(700);
data |= ((__raw_readb(SCSPTR1) & SDA) >> 2) << (7 - i);
scsptr1_data &= ~SCL;
__raw_writeb(scsptr1_data, SCSPTR1);
ndelay(700);
scsptr1_data |= SCL;
__raw_writeb(scsptr1_data, SCSPTR1);
}
return data & 0x0F;
}
static unsigned char rs5c313_read_reg(unsigned char addr)
{
rs5c313_write_data(addr | RS5C313_CNTBIT_READ | RS5C313_CNTBIT_AD);
return rs5c313_read_data();
}
static void rs5c313_write_reg(unsigned char addr, unsigned char data)
{
data &= 0x0f;
rs5c313_write_data(addr | RS5C313_CNTBIT_AD);
rs5c313_write_data(data | RS5C313_CNTBIT_DT);
return;
}
static inline unsigned char rs5c313_read_cntreg(void)
{
return rs5c313_read_reg(RS5C313_ADDR_CNTREG);
}
static inline void rs5c313_write_cntreg(unsigned char data)
{
rs5c313_write_reg(RS5C313_ADDR_CNTREG, data);
}
static inline void rs5c313_write_intintvreg(unsigned char data)
{
rs5c313_write_reg(RS5C313_ADDR_INTINTVREG, data);
}
static int rs5c313_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
int data;
int cnt;
cnt = 0;
while (1) {
RS5C313_CEENABLE;
rs5c313_write_cntreg(0x04);
if (!(rs5c313_read_cntreg() & RS5C313_CNTREG_ADJ_BSY))
break;
RS5C313_CEDISABLE;
ndelay(700);
if (cnt++ > 100) {
dev_err(dev, "%s: timeout error\n", __func__);
return -EIO;
}
}
data = rs5c313_read_reg(RS5C313_ADDR_SEC);
data |= (rs5c313_read_reg(RS5C313_ADDR_SEC10) << 4);
tm->tm_sec = bcd2bin(data);
data = rs5c313_read_reg(RS5C313_ADDR_MIN);
data |= (rs5c313_read_reg(RS5C313_ADDR_MIN10) << 4);
tm->tm_min = bcd2bin(data);
data = rs5c313_read_reg(RS5C313_ADDR_HOUR);
data |= (rs5c313_read_reg(RS5C313_ADDR_HOUR10) << 4);
tm->tm_hour = bcd2bin(data);
data = rs5c313_read_reg(RS5C313_ADDR_DAY);
data |= (rs5c313_read_reg(RS5C313_ADDR_DAY10) << 4);
tm->tm_mday = bcd2bin(data);
data = rs5c313_read_reg(RS5C313_ADDR_MON);
data |= (rs5c313_read_reg(RS5C313_ADDR_MON10) << 4);
tm->tm_mon = bcd2bin(data) - 1;
data = rs5c313_read_reg(RS5C313_ADDR_YEAR);
data |= (rs5c313_read_reg(RS5C313_ADDR_YEAR10) << 4);
tm->tm_year = bcd2bin(data);
if (tm->tm_year < 70)
tm->tm_year += 100;
data = rs5c313_read_reg(RS5C313_ADDR_WEEK);
tm->tm_wday = bcd2bin(data);
RS5C313_CEDISABLE;
ndelay(700);
return 0;
}
static int rs5c313_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
int data;
int cnt;
cnt = 0;
while (1) {
RS5C313_CEENABLE;
rs5c313_write_cntreg(0x04);
if (!(rs5c313_read_cntreg() & RS5C313_CNTREG_ADJ_BSY))
break;
RS5C313_MISCOP;
RS5C313_CEDISABLE;
ndelay(700);
if (cnt++ > 100) {
dev_err(dev, "%s: timeout error\n", __func__);
return -EIO;
}
}
data = bin2bcd(tm->tm_sec);
rs5c313_write_reg(RS5C313_ADDR_SEC, data);
rs5c313_write_reg(RS5C313_ADDR_SEC10, (data >> 4));
data = bin2bcd(tm->tm_min);
rs5c313_write_reg(RS5C313_ADDR_MIN, data);
rs5c313_write_reg(RS5C313_ADDR_MIN10, (data >> 4));
data = bin2bcd(tm->tm_hour);
rs5c313_write_reg(RS5C313_ADDR_HOUR, data);
rs5c313_write_reg(RS5C313_ADDR_HOUR10, (data >> 4));
data = bin2bcd(tm->tm_mday);
rs5c313_write_reg(RS5C313_ADDR_DAY, data);
rs5c313_write_reg(RS5C313_ADDR_DAY10, (data >> 4));
data = bin2bcd(tm->tm_mon + 1);
rs5c313_write_reg(RS5C313_ADDR_MON, data);
rs5c313_write_reg(RS5C313_ADDR_MON10, (data >> 4));
data = bin2bcd(tm->tm_year % 100);
rs5c313_write_reg(RS5C313_ADDR_YEAR, data);
rs5c313_write_reg(RS5C313_ADDR_YEAR10, (data >> 4));
data = bin2bcd(tm->tm_wday);
rs5c313_write_reg(RS5C313_ADDR_WEEK, data);
RS5C313_CEDISABLE;
ndelay(700);
return 0;
}
static void rs5c313_check_xstp_bit(void)
{
struct rtc_time tm;
int cnt;
RS5C313_CEENABLE;
if (rs5c313_read_cntreg() & RS5C313_CNTREG_WTEN_XSTP) {
rs5c313_write_intintvreg(0x00);
rs5c313_write_cntreg(0x07);
for (cnt = 0; cnt < 100; cnt++) {
if (!(rs5c313_read_cntreg() & RS5C313_CNTREG_ADJ_BSY))
break;
RS5C313_MISCOP;
}
memset(&tm, 0, sizeof(struct rtc_time));
tm.tm_mday = 1;
tm.tm_mon = 1 - 1;
tm.tm_year = 2000 - 1900;
rs5c313_rtc_set_time(NULL, &tm);
pr_err("invalid value, resetting to 1 Jan 2000\n");
}
RS5C313_CEDISABLE;
ndelay(700);
}
static int rs5c313_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc = devm_rtc_device_register(&pdev->dev, "rs5c313",
&rs5c313_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(pdev, rtc);
return 0;
}
static int __init rs5c313_rtc_init(void)
{
int err;
err = platform_driver_register(&rs5c313_rtc_platform_driver);
if (err)
return err;
rs5c313_init_port();
rs5c313_check_xstp_bit();
return 0;
}
static void __exit rs5c313_rtc_exit(void)
{
platform_driver_unregister(&rs5c313_rtc_platform_driver);
}
