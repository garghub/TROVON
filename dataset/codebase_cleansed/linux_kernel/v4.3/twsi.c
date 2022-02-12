static void i2c_wait_for_writes(struct hfi1_devdata *dd, u32 target)
{
hfi1_gpio_mod(dd, target, 0, 0, 0);
rmb();
}
static void scl_out(struct hfi1_devdata *dd, u32 target, u8 bit)
{
u32 mask;
udelay(1);
mask = QSFP_HFI0_I2CCLK;
hfi1_gpio_mod(dd, target, 0, bit ? 0 : mask, mask);
if (!bit)
udelay(2);
else {
int rise_usec;
for (rise_usec = SCL_WAIT_USEC; rise_usec > 0; rise_usec -= 2) {
if (mask & hfi1_gpio_mod(dd, target, 0, 0, 0))
break;
udelay(2);
}
if (rise_usec <= 0)
dd_dev_err(dd, "SCL interface stuck low > %d uSec\n",
SCL_WAIT_USEC);
}
i2c_wait_for_writes(dd, target);
}
static void sda_out(struct hfi1_devdata *dd, u32 target, u8 bit)
{
u32 mask;
mask = QSFP_HFI0_I2CDAT;
hfi1_gpio_mod(dd, target, 0, bit ? 0 : mask, mask);
i2c_wait_for_writes(dd, target);
udelay(2);
}
static u8 sda_in(struct hfi1_devdata *dd, u32 target, int wait)
{
u32 read_val, mask;
mask = QSFP_HFI0_I2CDAT;
hfi1_gpio_mod(dd, target, 0, 0, mask);
read_val = hfi1_gpio_mod(dd, target, 0, 0, 0);
if (wait)
i2c_wait_for_writes(dd, target);
return (read_val & mask) >> GPIO_SDA_NUM;
}
static int i2c_ackrcv(struct hfi1_devdata *dd, u32 target)
{
u8 ack_received;
ack_received = sda_in(dd, target, 1);
scl_out(dd, target, 1);
ack_received = sda_in(dd, target, 1) == 0;
scl_out(dd, target, 0);
return ack_received;
}
static int rd_byte(struct hfi1_devdata *dd, u32 target, int last)
{
int bit_cntr, data;
data = 0;
for (bit_cntr = 7; bit_cntr >= 0; --bit_cntr) {
data <<= 1;
scl_out(dd, target, 1);
data |= sda_in(dd, target, 0);
scl_out(dd, target, 0);
}
if (last) {
scl_out(dd, target, 1);
stop_cmd(dd, target);
} else {
sda_out(dd, target, 0);
scl_out(dd, target, 1);
scl_out(dd, target, 0);
sda_out(dd, target, 1);
}
return data;
}
static int wr_byte(struct hfi1_devdata *dd, u32 target, u8 data)
{
int bit_cntr;
u8 bit;
for (bit_cntr = 7; bit_cntr >= 0; bit_cntr--) {
bit = (data >> bit_cntr) & 1;
sda_out(dd, target, bit);
scl_out(dd, target, 1);
scl_out(dd, target, 0);
}
return (!i2c_ackrcv(dd, target)) ? 1 : 0;
}
static void start_seq(struct hfi1_devdata *dd, u32 target)
{
sda_out(dd, target, 1);
scl_out(dd, target, 1);
sda_out(dd, target, 0);
udelay(1);
scl_out(dd, target, 0);
}
static void stop_seq(struct hfi1_devdata *dd, u32 target)
{
scl_out(dd, target, 0);
sda_out(dd, target, 0);
scl_out(dd, target, 1);
sda_out(dd, target, 1);
}
static void stop_cmd(struct hfi1_devdata *dd, u32 target)
{
stop_seq(dd, target);
udelay(TWSI_BUF_WAIT_USEC);
}
int hfi1_twsi_reset(struct hfi1_devdata *dd, u32 target)
{
int clock_cycles_left = 9;
int was_high = 0;
u32 pins, mask;
mask = QSFP_HFI0_I2CCLK | QSFP_HFI0_I2CDAT;
hfi1_gpio_mod(dd, target, 0, 0, mask);
while (clock_cycles_left--) {
scl_out(dd, target, 0);
scl_out(dd, target, 1);
was_high |= sda_in(dd, target, 0);
}
if (was_high) {
pins = hfi1_gpio_mod(dd, target, 0, 0, 0);
if ((pins & mask) != mask)
dd_dev_err(dd, "GPIO pins not at rest: %d\n",
pins & mask);
udelay(1);
sda_out(dd, target, 0);
udelay(1);
sda_out(dd, target, 1);
udelay(TWSI_BUF_WAIT_USEC);
}
return !was_high;
}
static int twsi_wr(struct hfi1_devdata *dd, u32 target, int data, int flags)
{
int ret = 1;
if (flags & HFI1_TWSI_START)
start_seq(dd, target);
ret = wr_byte(dd, target, data);
if (flags & HFI1_TWSI_STOP)
stop_cmd(dd, target);
return ret;
}
int hfi1_twsi_blk_rd(struct hfi1_devdata *dd, u32 target, int dev, int addr,
void *buffer, int len)
{
int ret;
u8 *bp = buffer;
ret = 1;
if (dev == HFI1_TWSI_NO_DEV) {
addr = (addr << 1) | READ_CMD;
ret = twsi_wr(dd, target, addr, HFI1_TWSI_START);
} else {
ret = twsi_wr(dd, target, dev | WRITE_CMD, HFI1_TWSI_START);
if (ret) {
stop_cmd(dd, target);
ret = 1;
goto bail;
}
ret = twsi_wr(dd, target, addr, 0);
udelay(TWSI_BUF_WAIT_USEC);
if (ret) {
dd_dev_err(dd,
"Failed to write interface read addr %02X\n",
addr);
ret = 1;
goto bail;
}
ret = twsi_wr(dd, target, dev | READ_CMD, HFI1_TWSI_START);
}
if (ret) {
stop_cmd(dd, target);
ret = 1;
goto bail;
}
while (len-- > 0) {
*bp++ = rd_byte(dd, target, !len);
}
ret = 0;
bail:
return ret;
}
int hfi1_twsi_blk_wr(struct hfi1_devdata *dd, u32 target, int dev, int addr,
const void *buffer, int len)
{
int sub_len;
const u8 *bp = buffer;
int max_wait_time, i;
int ret = 1;
while (len > 0) {
if (dev == HFI1_TWSI_NO_DEV) {
if (twsi_wr(dd, target, (addr << 1) | WRITE_CMD,
HFI1_TWSI_START)) {
goto failed_write;
}
} else {
if (twsi_wr(dd, target,
dev | WRITE_CMD, HFI1_TWSI_START))
goto failed_write;
ret = twsi_wr(dd, target, addr, 0);
if (ret) {
dd_dev_err(dd,
"Failed to write interface write addr %02X\n",
addr);
goto failed_write;
}
}
sub_len = min(len, 4);
addr += sub_len;
len -= sub_len;
for (i = 0; i < sub_len; i++)
if (twsi_wr(dd, target, *bp++, 0))
goto failed_write;
stop_cmd(dd, target);
max_wait_time = 100;
while (twsi_wr(dd, target,
dev | READ_CMD, HFI1_TWSI_START)) {
stop_cmd(dd, target);
if (!--max_wait_time)
goto failed_write;
}
rd_byte(dd, target, 1);
}
ret = 0;
goto bail;
failed_write:
stop_cmd(dd, target);
ret = 1;
bail:
return ret;
}
