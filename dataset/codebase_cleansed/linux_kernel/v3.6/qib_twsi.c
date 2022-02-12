static void i2c_wait_for_writes(struct qib_devdata *dd)
{
dd->f_gpio_mod(dd, 0, 0, 0);
rmb();
}
static void scl_out(struct qib_devdata *dd, u8 bit)
{
u32 mask;
udelay(1);
mask = 1UL << dd->gpio_scl_num;
dd->f_gpio_mod(dd, 0, bit ? 0 : mask, mask);
if (!bit)
udelay(2);
else {
int rise_usec;
for (rise_usec = SCL_WAIT_USEC; rise_usec > 0; rise_usec -= 2) {
if (mask & dd->f_gpio_mod(dd, 0, 0, 0))
break;
udelay(2);
}
if (rise_usec <= 0)
qib_dev_err(dd, "SCL interface stuck low > %d uSec\n",
SCL_WAIT_USEC);
}
i2c_wait_for_writes(dd);
}
static void sda_out(struct qib_devdata *dd, u8 bit)
{
u32 mask;
mask = 1UL << dd->gpio_sda_num;
dd->f_gpio_mod(dd, 0, bit ? 0 : mask, mask);
i2c_wait_for_writes(dd);
udelay(2);
}
static u8 sda_in(struct qib_devdata *dd, int wait)
{
int bnum;
u32 read_val, mask;
bnum = dd->gpio_sda_num;
mask = (1UL << bnum);
dd->f_gpio_mod(dd, 0, 0, mask);
read_val = dd->f_gpio_mod(dd, 0, 0, 0);
if (wait)
i2c_wait_for_writes(dd);
return (read_val & mask) >> bnum;
}
static int i2c_ackrcv(struct qib_devdata *dd)
{
u8 ack_received;
ack_received = sda_in(dd, 1);
scl_out(dd, 1);
ack_received = sda_in(dd, 1) == 0;
scl_out(dd, 0);
return ack_received;
}
static int rd_byte(struct qib_devdata *dd, int last)
{
int bit_cntr, data;
data = 0;
for (bit_cntr = 7; bit_cntr >= 0; --bit_cntr) {
data <<= 1;
scl_out(dd, 1);
data |= sda_in(dd, 0);
scl_out(dd, 0);
}
if (last) {
scl_out(dd, 1);
stop_cmd(dd);
} else {
sda_out(dd, 0);
scl_out(dd, 1);
scl_out(dd, 0);
sda_out(dd, 1);
}
return data;
}
static int wr_byte(struct qib_devdata *dd, u8 data)
{
int bit_cntr;
u8 bit;
for (bit_cntr = 7; bit_cntr >= 0; bit_cntr--) {
bit = (data >> bit_cntr) & 1;
sda_out(dd, bit);
scl_out(dd, 1);
scl_out(dd, 0);
}
return (!i2c_ackrcv(dd)) ? 1 : 0;
}
static void start_seq(struct qib_devdata *dd)
{
sda_out(dd, 1);
scl_out(dd, 1);
sda_out(dd, 0);
udelay(1);
scl_out(dd, 0);
}
static void stop_seq(struct qib_devdata *dd)
{
scl_out(dd, 0);
sda_out(dd, 0);
scl_out(dd, 1);
sda_out(dd, 1);
}
static void stop_cmd(struct qib_devdata *dd)
{
stop_seq(dd);
udelay(TWSI_BUF_WAIT_USEC);
}
int qib_twsi_reset(struct qib_devdata *dd)
{
int clock_cycles_left = 9;
int was_high = 0;
u32 pins, mask;
mask = (1UL << dd->gpio_scl_num) | (1UL << dd->gpio_sda_num);
dd->f_gpio_mod(dd, 0, 0, mask);
while (clock_cycles_left--) {
scl_out(dd, 0);
scl_out(dd, 1);
was_high |= sda_in(dd, 0);
}
if (was_high) {
pins = dd->f_gpio_mod(dd, 0, 0, 0);
if ((pins & mask) != mask)
qib_dev_err(dd, "GPIO pins not at rest: %d\n",
pins & mask);
udelay(1);
sda_out(dd, 0);
udelay(1);
sda_out(dd, 1);
udelay(TWSI_BUF_WAIT_USEC);
}
return !was_high;
}
static int qib_twsi_wr(struct qib_devdata *dd, int data, int flags)
{
int ret = 1;
if (flags & QIB_TWSI_START)
start_seq(dd);
ret = wr_byte(dd, data);
if (flags & QIB_TWSI_STOP)
stop_cmd(dd);
return ret;
}
int qib_twsi_blk_rd(struct qib_devdata *dd, int dev, int addr,
void *buffer, int len)
{
int ret;
u8 *bp = buffer;
ret = 1;
if (dev == QIB_TWSI_NO_DEV) {
addr = (addr << 1) | READ_CMD;
ret = qib_twsi_wr(dd, addr, QIB_TWSI_START);
} else {
ret = qib_twsi_wr(dd, dev | WRITE_CMD, QIB_TWSI_START);
if (ret) {
stop_cmd(dd);
ret = 1;
goto bail;
}
ret = qib_twsi_wr(dd, addr, 0);
udelay(TWSI_BUF_WAIT_USEC);
if (ret) {
qib_dev_err(dd,
"Failed to write interface read addr %02X\n",
addr);
ret = 1;
goto bail;
}
ret = qib_twsi_wr(dd, dev | READ_CMD, QIB_TWSI_START);
}
if (ret) {
stop_cmd(dd);
ret = 1;
goto bail;
}
while (len-- > 0) {
*bp++ = rd_byte(dd, !len);
}
ret = 0;
bail:
return ret;
}
int qib_twsi_blk_wr(struct qib_devdata *dd, int dev, int addr,
const void *buffer, int len)
{
int sub_len;
const u8 *bp = buffer;
int max_wait_time, i;
int ret;
ret = 1;
while (len > 0) {
if (dev == QIB_TWSI_NO_DEV) {
if (qib_twsi_wr(dd, (addr << 1) | WRITE_CMD,
QIB_TWSI_START)) {
goto failed_write;
}
} else {
if (qib_twsi_wr(dd, dev | WRITE_CMD, QIB_TWSI_START))
goto failed_write;
ret = qib_twsi_wr(dd, addr, 0);
if (ret) {
qib_dev_err(dd,
"Failed to write interface write addr %02X\n",
addr);
goto failed_write;
}
}
sub_len = min(len, 4);
addr += sub_len;
len -= sub_len;
for (i = 0; i < sub_len; i++)
if (qib_twsi_wr(dd, *bp++, 0))
goto failed_write;
stop_cmd(dd);
max_wait_time = 100;
while (qib_twsi_wr(dd, dev | READ_CMD, QIB_TWSI_START)) {
stop_cmd(dd);
if (!--max_wait_time)
goto failed_write;
}
rd_byte(dd, 1);
}
ret = 0;
goto bail;
failed_write:
stop_cmd(dd);
ret = 1;
bail:
return ret;
}
