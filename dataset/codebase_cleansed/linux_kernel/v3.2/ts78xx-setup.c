void __init ts78xx_map_io(void)
{
orion5x_map_io();
iotable_init(ts78xx_io_desc, ARRAY_SIZE(ts78xx_io_desc));
}
static unsigned char ts78xx_ts_rtc_readbyte(unsigned long addr)
{
writeb(addr, TS_RTC_CTRL);
return readb(TS_RTC_DATA);
}
static void ts78xx_ts_rtc_writebyte(unsigned char value, unsigned long addr)
{
writeb(addr, TS_RTC_CTRL);
writeb(value, TS_RTC_DATA);
}
static int ts78xx_ts_rtc_load(void)
{
int rc;
unsigned char tmp_rtc0, tmp_rtc1;
tmp_rtc0 = ts78xx_ts_rtc_readbyte(126);
tmp_rtc1 = ts78xx_ts_rtc_readbyte(127);
ts78xx_ts_rtc_writebyte(0x00, 126);
ts78xx_ts_rtc_writebyte(0x55, 127);
if (ts78xx_ts_rtc_readbyte(127) == 0x55) {
ts78xx_ts_rtc_writebyte(0xaa, 127);
if (ts78xx_ts_rtc_readbyte(127) == 0xaa
&& ts78xx_ts_rtc_readbyte(126) == 0x00) {
ts78xx_ts_rtc_writebyte(tmp_rtc0, 126);
ts78xx_ts_rtc_writebyte(tmp_rtc1, 127);
if (ts78xx_fpga.supports.ts_rtc.init == 0) {
rc = platform_device_register(&ts78xx_ts_rtc_device);
if (!rc)
ts78xx_fpga.supports.ts_rtc.init = 1;
} else
rc = platform_device_add(&ts78xx_ts_rtc_device);
return rc;
}
}
return -ENODEV;
}
static void ts78xx_ts_rtc_unload(void)
{
platform_device_del(&ts78xx_ts_rtc_device);
}
static void ts78xx_ts_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
if (ctrl & NAND_CTRL_CHANGE) {
unsigned char bits;
bits = (ctrl & NAND_NCE) << 2;
bits |= ctrl & NAND_CLE;
bits |= (ctrl & NAND_ALE) >> 2;
writeb((readb(TS_NAND_CTRL) & ~0x7) | bits, TS_NAND_CTRL);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, this->IO_ADDR_W);
}
static int ts78xx_ts_nand_dev_ready(struct mtd_info *mtd)
{
return readb(TS_NAND_CTRL) & 0x20;
}
static void ts78xx_ts_nand_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
void __iomem *io_base = chip->IO_ADDR_W;
unsigned long off = ((unsigned long)buf & 3);
int sz;
if (off) {
sz = min_t(int, 4 - off, len);
writesb(io_base, buf, sz);
buf += sz;
len -= sz;
}
sz = len >> 2;
if (sz) {
u32 *buf32 = (u32 *)buf;
writesl(io_base, buf32, sz);
buf += sz << 2;
len -= sz << 2;
}
if (len)
writesb(io_base, buf, len);
}
static void ts78xx_ts_nand_read_buf(struct mtd_info *mtd,
uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
void __iomem *io_base = chip->IO_ADDR_R;
unsigned long off = ((unsigned long)buf & 3);
int sz;
if (off) {
sz = min_t(int, 4 - off, len);
readsb(io_base, buf, sz);
buf += sz;
len -= sz;
}
sz = len >> 2;
if (sz) {
u32 *buf32 = (u32 *)buf;
readsl(io_base, buf32, sz);
buf += sz << 2;
len -= sz << 2;
}
if (len)
readsb(io_base, buf, len);
}
static int ts78xx_ts_nand_load(void)
{
int rc;
if (ts78xx_fpga.supports.ts_nand.init == 0) {
rc = platform_device_register(&ts78xx_ts_nand_device);
if (!rc)
ts78xx_fpga.supports.ts_nand.init = 1;
} else
rc = platform_device_add(&ts78xx_ts_nand_device);
return rc;
}
static void ts78xx_ts_nand_unload(void)
{
platform_device_del(&ts78xx_ts_nand_device);
}
static int ts78xx_ts_rng_load(void)
{
int rc;
if (ts78xx_fpga.supports.ts_rng.init == 0) {
rc = platform_device_register(&ts78xx_ts_rng_device);
if (!rc)
ts78xx_fpga.supports.ts_rng.init = 1;
} else
rc = platform_device_add(&ts78xx_ts_rng_device);
return rc;
}
static void ts78xx_ts_rng_unload(void)
{
platform_device_del(&ts78xx_ts_rng_device);
}
static void ts78xx_fpga_devices_zero_init(void)
{
ts78xx_fpga.supports.ts_rtc.init = 0;
ts78xx_fpga.supports.ts_nand.init = 0;
ts78xx_fpga.supports.ts_rng.init = 0;
}
static void ts78xx_fpga_supports(void)
{
switch (ts78xx_fpga.id) {
case TS7800_REV_1:
case TS7800_REV_2:
case TS7800_REV_3:
case TS7800_REV_4:
case TS7800_REV_5:
case TS7800_REV_6:
case TS7800_REV_7:
case TS7800_REV_8:
case TS7800_REV_9:
ts78xx_fpga.supports.ts_rtc.present = 1;
ts78xx_fpga.supports.ts_nand.present = 1;
ts78xx_fpga.supports.ts_rng.present = 1;
break;
default:
switch ((ts78xx_fpga.id >> 8) & 0xffffff) {
case TS7800_FPGA_MAGIC:
pr_warning("TS-7800 FPGA: unrecognized revision 0x%.2x\n",
ts78xx_fpga.id & 0xff);
ts78xx_fpga.supports.ts_rtc.present = 1;
ts78xx_fpga.supports.ts_nand.present = 1;
ts78xx_fpga.supports.ts_rng.present = 1;
break;
default:
ts78xx_fpga.supports.ts_rtc.present = 0;
ts78xx_fpga.supports.ts_nand.present = 0;
ts78xx_fpga.supports.ts_rng.present = 0;
}
}
}
static int ts78xx_fpga_load_devices(void)
{
int tmp, ret = 0;
if (ts78xx_fpga.supports.ts_rtc.present == 1) {
tmp = ts78xx_ts_rtc_load();
if (tmp) {
pr_info("TS-78xx: RTC not registered\n");
ts78xx_fpga.supports.ts_rtc.present = 0;
}
ret |= tmp;
}
if (ts78xx_fpga.supports.ts_nand.present == 1) {
tmp = ts78xx_ts_nand_load();
if (tmp) {
pr_info("TS-78xx: NAND not registered\n");
ts78xx_fpga.supports.ts_nand.present = 0;
}
ret |= tmp;
}
if (ts78xx_fpga.supports.ts_rng.present == 1) {
tmp = ts78xx_ts_rng_load();
if (tmp) {
pr_info("TS-78xx: RNG not registered\n");
ts78xx_fpga.supports.ts_rng.present = 0;
}
ret |= tmp;
}
return ret;
}
static int ts78xx_fpga_unload_devices(void)
{
int ret = 0;
if (ts78xx_fpga.supports.ts_rtc.present == 1)
ts78xx_ts_rtc_unload();
if (ts78xx_fpga.supports.ts_nand.present == 1)
ts78xx_ts_nand_unload();
if (ts78xx_fpga.supports.ts_rng.present == 1)
ts78xx_ts_rng_unload();
return ret;
}
static int ts78xx_fpga_load(void)
{
ts78xx_fpga.id = readl(TS78XX_FPGA_REGS_VIRT_BASE);
pr_info("TS-78xx FPGA: magic=0x%.6x, rev=0x%.2x\n",
(ts78xx_fpga.id >> 8) & 0xffffff,
ts78xx_fpga.id & 0xff);
ts78xx_fpga_supports();
if (ts78xx_fpga_load_devices()) {
ts78xx_fpga.state = -1;
return -EBUSY;
}
return 0;
}
static int ts78xx_fpga_unload(void)
{
unsigned int fpga_id;
fpga_id = readl(TS78XX_FPGA_REGS_VIRT_BASE);
if (ts78xx_fpga.id != fpga_id) {
pr_err("TS-78xx FPGA: magic/rev mismatch\n"
"TS-78xx FPGA: was 0x%.6x/%.2x but now 0x%.6x/%.2x\n",
(ts78xx_fpga.id >> 8) & 0xffffff, ts78xx_fpga.id & 0xff,
(fpga_id >> 8) & 0xffffff, fpga_id & 0xff);
ts78xx_fpga.state = -1;
return -EBUSY;
}
if (ts78xx_fpga_unload_devices()) {
ts78xx_fpga.state = -1;
return -EBUSY;
}
return 0;
}
static ssize_t ts78xx_fpga_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
if (ts78xx_fpga.state < 0)
return sprintf(buf, "borked\n");
return sprintf(buf, "%s\n", (ts78xx_fpga.state) ? "online" : "offline");
}
static ssize_t ts78xx_fpga_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t n)
{
int value, ret;
if (ts78xx_fpga.state < 0) {
pr_err("TS-78xx FPGA: borked, you must powercycle asap\n");
return -EBUSY;
}
if (strncmp(buf, "online", sizeof("online") - 1) == 0)
value = 1;
else if (strncmp(buf, "offline", sizeof("offline") - 1) == 0)
value = 0;
else {
pr_err("ts78xx_fpga_store: Invalid value\n");
return -EINVAL;
}
if (ts78xx_fpga.state == value)
return n;
ret = (ts78xx_fpga.state == 0)
? ts78xx_fpga_load()
: ts78xx_fpga_unload();
if (!(ret < 0))
ts78xx_fpga.state = value;
return n;
}
static void __init ts78xx_init(void)
{
int ret;
orion5x_init();
orion5x_mpp_conf(ts78xx_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&ts78xx_eth_data);
orion5x_sata_init(&ts78xx_sata_data);
orion5x_uart0_init();
orion5x_uart1_init();
orion5x_xor_init();
ts78xx_fpga_devices_zero_init();
ret = ts78xx_fpga_load();
ret = sysfs_create_file(power_kobj, &ts78xx_fpga_attr.attr);
if (ret)
pr_err("sysfs_create_file failed: %d\n", ret);
}
