static void octeon_i2c_writeq_flush(u64 val, void __iomem *addr)
{
__raw_writeq(val, addr);
__raw_readq(addr);
}
static void octeon_i2c_reg_write(struct octeon_i2c *i2c, u64 eop_reg, u8 data)
{
u64 tmp;
__raw_writeq(SW_TWSI_V | eop_reg | data, i2c->twsi_base + SW_TWSI);
do {
tmp = __raw_readq(i2c->twsi_base + SW_TWSI);
} while ((tmp & SW_TWSI_V) != 0);
}
static u8 octeon_i2c_reg_read(struct octeon_i2c *i2c, u64 eop_reg)
{
u64 tmp;
__raw_writeq(SW_TWSI_V | eop_reg | SW_TWSI_R, i2c->twsi_base + SW_TWSI);
do {
tmp = __raw_readq(i2c->twsi_base + SW_TWSI);
} while ((tmp & SW_TWSI_V) != 0);
return tmp & 0xFF;
}
static u64 octeon_i2c_read_int(struct octeon_i2c *i2c)
{
return __raw_readq(i2c->twsi_base + TWSI_INT);
}
static void octeon_i2c_write_int(struct octeon_i2c *i2c, u64 data)
{
octeon_i2c_writeq_flush(data, i2c->twsi_base + TWSI_INT);
}
static void octeon_i2c_int_enable(struct octeon_i2c *i2c)
{
octeon_i2c_write_int(i2c, TWSI_INT_CORE_EN);
}
static void octeon_i2c_int_disable(struct octeon_i2c *i2c)
{
octeon_i2c_write_int(i2c, 0);
}
static void octeon_i2c_int_enable78(struct octeon_i2c *i2c)
{
atomic_inc_return(&i2c->int_enable_cnt);
enable_irq(i2c->irq);
}
static void __octeon_i2c_irq_disable(atomic_t *cnt, int irq)
{
int count;
count = atomic_dec_if_positive(cnt);
if (count >= 0)
disable_irq_nosync(irq);
}
static void octeon_i2c_int_disable78(struct octeon_i2c *i2c)
{
__octeon_i2c_irq_disable(&i2c->int_enable_cnt, i2c->irq);
}
static void octeon_i2c_hlc_int_enable78(struct octeon_i2c *i2c)
{
atomic_inc_return(&i2c->hlc_int_enable_cnt);
enable_irq(i2c->hlc_irq);
}
static void octeon_i2c_hlc_int_disable78(struct octeon_i2c *i2c)
{
__octeon_i2c_irq_disable(&i2c->hlc_int_enable_cnt, i2c->hlc_irq);
}
static void octeon_i2c_hlc_enable(struct octeon_i2c *i2c)
{
int try = 0;
u64 val;
if (i2c->hlc_enabled)
return;
i2c->hlc_enabled = true;
while (1) {
val = octeon_i2c_ctl_read(i2c);
if (!(val & (TWSI_CTL_STA | TWSI_CTL_STP)))
break;
if (val & TWSI_CTL_IFLG)
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB);
if (try++ > 100) {
pr_err("%s: giving up\n", __func__);
break;
}
udelay(10);
}
octeon_i2c_ctl_write(i2c, TWSI_CTL_CE | TWSI_CTL_AAK | TWSI_CTL_ENAB);
}
static void octeon_i2c_hlc_disable(struct octeon_i2c *i2c)
{
if (!i2c->hlc_enabled)
return;
i2c->hlc_enabled = false;
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB);
}
static irqreturn_t octeon_i2c_isr(int irq, void *dev_id)
{
struct octeon_i2c *i2c = dev_id;
i2c->int_disable(i2c);
wake_up(&i2c->queue);
return IRQ_HANDLED;
}
static irqreturn_t octeon_i2c_hlc_isr78(int irq, void *dev_id)
{
struct octeon_i2c *i2c = dev_id;
i2c->hlc_int_disable(i2c);
wake_up(&i2c->queue);
return IRQ_HANDLED;
}
static bool octeon_i2c_test_iflg(struct octeon_i2c *i2c)
{
return (octeon_i2c_ctl_read(i2c) & TWSI_CTL_IFLG);
}
static bool octeon_i2c_test_ready(struct octeon_i2c *i2c, bool *first)
{
if (octeon_i2c_test_iflg(i2c))
return true;
if (*first) {
*first = false;
return false;
}
usleep_range(I2C_OCTEON_EVENT_WAIT, 2 * I2C_OCTEON_EVENT_WAIT);
return octeon_i2c_test_iflg(i2c);
}
static int octeon_i2c_wait(struct octeon_i2c *i2c)
{
long time_left;
bool first = 1;
if (i2c->broken_irq_mode) {
u64 end = get_jiffies_64() + i2c->adap.timeout;
while (!octeon_i2c_test_iflg(i2c) &&
time_before64(get_jiffies_64(), end))
usleep_range(I2C_OCTEON_EVENT_WAIT / 2, I2C_OCTEON_EVENT_WAIT);
return octeon_i2c_test_iflg(i2c) ? 0 : -ETIMEDOUT;
}
i2c->int_enable(i2c);
time_left = wait_event_timeout(i2c->queue, octeon_i2c_test_ready(i2c, &first),
i2c->adap.timeout);
i2c->int_disable(i2c);
if (i2c->broken_irq_check && !time_left &&
octeon_i2c_test_iflg(i2c)) {
dev_err(i2c->dev, "broken irq connection detected, switching to polling mode.\n");
i2c->broken_irq_mode = true;
return 0;
}
if (!time_left)
return -ETIMEDOUT;
return 0;
}
static int octeon_i2c_check_status(struct octeon_i2c *i2c, int final_read)
{
u8 stat = octeon_i2c_stat_read(i2c);
switch (stat) {
case STAT_IDLE:
case STAT_AD2W_ACK:
case STAT_RXADDR_ACK:
case STAT_TXADDR_ACK:
case STAT_TXDATA_ACK:
return 0;
case STAT_RXDATA_ACK:
if (!final_read)
return 0;
return -EIO;
case STAT_RXDATA_NAK:
if (final_read)
return 0;
return -EIO;
case STAT_LOST_ARB_38:
case STAT_LOST_ARB_68:
case STAT_LOST_ARB_78:
case STAT_LOST_ARB_B0:
return -EAGAIN;
case STAT_SLAVE_60:
case STAT_SLAVE_70:
case STAT_GENDATA_ACK:
case STAT_GENDATA_NAK:
return -EOPNOTSUPP;
case STAT_SLAVE_80:
case STAT_SLAVE_88:
case STAT_SLAVE_A0:
case STAT_SLAVE_A8:
case STAT_SLAVE_LOST:
case STAT_SLAVE_NAK:
case STAT_SLAVE_ACK:
return -EOPNOTSUPP;
case STAT_TXDATA_NAK:
return -EIO;
case STAT_TXADDR_NAK:
case STAT_RXADDR_NAK:
case STAT_AD2W_NAK:
return -ENXIO;
default:
dev_err(i2c->dev, "unhandled state: %d\n", stat);
return -EIO;
}
}
static bool octeon_i2c_hlc_test_valid(struct octeon_i2c *i2c)
{
return (__raw_readq(i2c->twsi_base + SW_TWSI) & SW_TWSI_V) == 0;
}
static bool octeon_i2c_hlc_test_ready(struct octeon_i2c *i2c, bool *first)
{
if (octeon_i2c_hlc_test_valid(i2c))
return true;
if (*first) {
*first = false;
return false;
}
usleep_range(I2C_OCTEON_EVENT_WAIT, 2 * I2C_OCTEON_EVENT_WAIT);
return octeon_i2c_hlc_test_valid(i2c);
}
static void octeon_i2c_hlc_int_enable(struct octeon_i2c *i2c)
{
octeon_i2c_write_int(i2c, TWSI_INT_ST_EN);
}
static void octeon_i2c_hlc_int_clear(struct octeon_i2c *i2c)
{
octeon_i2c_write_int(i2c, TWSI_INT_ST_INT | TWSI_INT_TS_INT);
}
static int octeon_i2c_hlc_wait(struct octeon_i2c *i2c)
{
bool first = 1;
int time_left;
if (i2c->broken_irq_mode) {
u64 end = get_jiffies_64() + i2c->adap.timeout;
while (!octeon_i2c_hlc_test_valid(i2c) &&
time_before64(get_jiffies_64(), end))
usleep_range(I2C_OCTEON_EVENT_WAIT / 2, I2C_OCTEON_EVENT_WAIT);
return octeon_i2c_hlc_test_valid(i2c) ? 0 : -ETIMEDOUT;
}
i2c->hlc_int_enable(i2c);
time_left = wait_event_timeout(i2c->queue,
octeon_i2c_hlc_test_ready(i2c, &first),
i2c->adap.timeout);
i2c->hlc_int_disable(i2c);
if (!time_left)
octeon_i2c_hlc_int_clear(i2c);
if (i2c->broken_irq_check && !time_left &&
octeon_i2c_hlc_test_valid(i2c)) {
dev_err(i2c->dev, "broken irq connection detected, switching to polling mode.\n");
i2c->broken_irq_mode = true;
return 0;
}
if (!time_left)
return -ETIMEDOUT;
return 0;
}
static int octeon_i2c_hlc_read(struct octeon_i2c *i2c, struct i2c_msg *msgs)
{
int i, j, ret = 0;
u64 cmd;
octeon_i2c_hlc_enable(i2c);
octeon_i2c_hlc_int_clear(i2c);
cmd = SW_TWSI_V | SW_TWSI_R | SW_TWSI_SOVR;
cmd |= (u64)(msgs[0].len - 1) << SW_TWSI_SIZE_SHIFT;
cmd |= (u64)(msgs[0].addr & 0x7full) << SW_TWSI_ADDR_SHIFT;
if (msgs[0].flags & I2C_M_TEN)
cmd |= SW_TWSI_OP_10;
else
cmd |= SW_TWSI_OP_7;
octeon_i2c_writeq_flush(cmd, i2c->twsi_base + SW_TWSI);
ret = octeon_i2c_hlc_wait(i2c);
if (ret)
goto err;
cmd = __raw_readq(i2c->twsi_base + SW_TWSI);
if ((cmd & SW_TWSI_R) == 0)
return -EAGAIN;
for (i = 0, j = msgs[0].len - 1; i < msgs[0].len && i < 4; i++, j--)
msgs[0].buf[j] = (cmd >> (8 * i)) & 0xff;
if (msgs[0].len > 4) {
cmd = __raw_readq(i2c->twsi_base + SW_TWSI_EXT);
for (i = 0; i < msgs[0].len - 4 && i < 4; i++, j--)
msgs[0].buf[j] = (cmd >> (8 * i)) & 0xff;
}
err:
return ret;
}
static int octeon_i2c_hlc_write(struct octeon_i2c *i2c, struct i2c_msg *msgs)
{
int i, j, ret = 0;
u64 cmd;
octeon_i2c_hlc_enable(i2c);
octeon_i2c_hlc_int_clear(i2c);
cmd = SW_TWSI_V | SW_TWSI_SOVR;
cmd |= (u64)(msgs[0].len - 1) << SW_TWSI_SIZE_SHIFT;
cmd |= (u64)(msgs[0].addr & 0x7full) << SW_TWSI_ADDR_SHIFT;
if (msgs[0].flags & I2C_M_TEN)
cmd |= SW_TWSI_OP_10;
else
cmd |= SW_TWSI_OP_7;
for (i = 0, j = msgs[0].len - 1; i < msgs[0].len && i < 4; i++, j--)
cmd |= (u64)msgs[0].buf[j] << (8 * i);
if (msgs[0].len > 4) {
u64 ext = 0;
for (i = 0; i < msgs[0].len - 4 && i < 4; i++, j--)
ext |= (u64)msgs[0].buf[j] << (8 * i);
octeon_i2c_writeq_flush(ext, i2c->twsi_base + SW_TWSI_EXT);
}
octeon_i2c_writeq_flush(cmd, i2c->twsi_base + SW_TWSI);
ret = octeon_i2c_hlc_wait(i2c);
if (ret)
goto err;
cmd = __raw_readq(i2c->twsi_base + SW_TWSI);
if ((cmd & SW_TWSI_R) == 0)
return -EAGAIN;
ret = octeon_i2c_check_status(i2c, false);
err:
return ret;
}
static int octeon_i2c_hlc_comp_read(struct octeon_i2c *i2c, struct i2c_msg *msgs)
{
int i, j, ret = 0;
u64 cmd;
octeon_i2c_hlc_enable(i2c);
cmd = SW_TWSI_V | SW_TWSI_R | SW_TWSI_SOVR;
cmd |= (u64)(msgs[1].len - 1) << SW_TWSI_SIZE_SHIFT;
cmd |= (u64)(msgs[0].addr & 0x7full) << SW_TWSI_ADDR_SHIFT;
if (msgs[0].flags & I2C_M_TEN)
cmd |= SW_TWSI_OP_10_IA;
else
cmd |= SW_TWSI_OP_7_IA;
if (msgs[0].len == 2) {
u64 ext = 0;
cmd |= SW_TWSI_EIA;
ext = (u64)msgs[0].buf[0] << SW_TWSI_IA_SHIFT;
cmd |= (u64)msgs[0].buf[1] << SW_TWSI_IA_SHIFT;
octeon_i2c_writeq_flush(ext, i2c->twsi_base + SW_TWSI_EXT);
} else {
cmd |= (u64)msgs[0].buf[0] << SW_TWSI_IA_SHIFT;
}
octeon_i2c_hlc_int_clear(i2c);
octeon_i2c_writeq_flush(cmd, i2c->twsi_base + SW_TWSI);
ret = octeon_i2c_hlc_wait(i2c);
if (ret)
goto err;
cmd = __raw_readq(i2c->twsi_base + SW_TWSI);
if ((cmd & SW_TWSI_R) == 0)
return -EAGAIN;
for (i = 0, j = msgs[1].len - 1; i < msgs[1].len && i < 4; i++, j--)
msgs[1].buf[j] = (cmd >> (8 * i)) & 0xff;
if (msgs[1].len > 4) {
cmd = __raw_readq(i2c->twsi_base + SW_TWSI_EXT);
for (i = 0; i < msgs[1].len - 4 && i < 4; i++, j--)
msgs[1].buf[j] = (cmd >> (8 * i)) & 0xff;
}
err:
return ret;
}
static int octeon_i2c_hlc_comp_write(struct octeon_i2c *i2c, struct i2c_msg *msgs)
{
bool set_ext = false;
int i, j, ret = 0;
u64 cmd, ext = 0;
octeon_i2c_hlc_enable(i2c);
cmd = SW_TWSI_V | SW_TWSI_SOVR;
cmd |= (u64)(msgs[1].len - 1) << SW_TWSI_SIZE_SHIFT;
cmd |= (u64)(msgs[0].addr & 0x7full) << SW_TWSI_ADDR_SHIFT;
if (msgs[0].flags & I2C_M_TEN)
cmd |= SW_TWSI_OP_10_IA;
else
cmd |= SW_TWSI_OP_7_IA;
if (msgs[0].len == 2) {
cmd |= SW_TWSI_EIA;
ext |= (u64)msgs[0].buf[0] << SW_TWSI_IA_SHIFT;
set_ext = true;
cmd |= (u64)msgs[0].buf[1] << SW_TWSI_IA_SHIFT;
} else {
cmd |= (u64)msgs[0].buf[0] << SW_TWSI_IA_SHIFT;
}
for (i = 0, j = msgs[1].len - 1; i < msgs[1].len && i < 4; i++, j--)
cmd |= (u64)msgs[1].buf[j] << (8 * i);
if (msgs[1].len > 4) {
for (i = 0; i < msgs[1].len - 4 && i < 4; i++, j--)
ext |= (u64)msgs[1].buf[j] << (8 * i);
set_ext = true;
}
if (set_ext)
octeon_i2c_writeq_flush(ext, i2c->twsi_base + SW_TWSI_EXT);
octeon_i2c_hlc_int_clear(i2c);
octeon_i2c_writeq_flush(cmd, i2c->twsi_base + SW_TWSI);
ret = octeon_i2c_hlc_wait(i2c);
if (ret)
goto err;
cmd = __raw_readq(i2c->twsi_base + SW_TWSI);
if ((cmd & SW_TWSI_R) == 0)
return -EAGAIN;
ret = octeon_i2c_check_status(i2c, false);
err:
return ret;
}
static void octeon_i2c_set_clock(struct octeon_i2c *i2c)
{
int tclk, thp_base, inc, thp_idx, mdiv_idx, ndiv_idx, foscl, diff;
int thp = 0x18, mdiv = 2, ndiv = 0, delta_hz = 1000000;
for (ndiv_idx = 0; ndiv_idx < 8 && delta_hz != 0; ndiv_idx++) {
for (mdiv_idx = 15; mdiv_idx >= 2 && delta_hz != 0; mdiv_idx--) {
tclk = i2c->twsi_freq * (mdiv_idx + 1) * 10;
tclk *= (1 << ndiv_idx);
thp_base = (i2c->sys_freq / (tclk * 2)) - 1;
for (inc = 0; inc <= 1; inc++) {
thp_idx = thp_base + inc;
if (thp_idx < 5 || thp_idx > 0xff)
continue;
foscl = i2c->sys_freq / (2 * (thp_idx + 1));
foscl = foscl / (1 << ndiv_idx);
foscl = foscl / (mdiv_idx + 1) / 10;
diff = abs(foscl - i2c->twsi_freq);
if (diff < delta_hz) {
delta_hz = diff;
thp = thp_idx;
mdiv = mdiv_idx;
ndiv = ndiv_idx;
}
}
}
}
octeon_i2c_reg_write(i2c, SW_TWSI_OP_TWSI_CLK, thp);
octeon_i2c_reg_write(i2c, SW_TWSI_EOP_TWSI_CLKCTL, (mdiv << 3) | ndiv);
}
static int octeon_i2c_init_lowlevel(struct octeon_i2c *i2c)
{
u8 status = 0;
int tries;
octeon_i2c_reg_write(i2c, SW_TWSI_EOP_TWSI_RST, 0);
for (tries = 10; tries && status != STAT_IDLE; tries--) {
udelay(1);
status = octeon_i2c_stat_read(i2c);
if (status == STAT_IDLE)
break;
}
if (status != STAT_IDLE) {
dev_err(i2c->dev, "%s: TWSI_RST failed! (0x%x)\n",
__func__, status);
return -EIO;
}
octeon_i2c_hlc_enable(i2c);
octeon_i2c_hlc_disable(i2c);
return 0;
}
static int octeon_i2c_recovery(struct octeon_i2c *i2c)
{
int ret;
ret = i2c_recover_bus(&i2c->adap);
if (ret)
ret = octeon_i2c_init_lowlevel(i2c);
return ret;
}
static int octeon_i2c_start(struct octeon_i2c *i2c)
{
int ret;
u8 stat;
octeon_i2c_hlc_disable(i2c);
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB | TWSI_CTL_STA);
ret = octeon_i2c_wait(i2c);
if (ret)
goto error;
stat = octeon_i2c_stat_read(i2c);
if (stat == STAT_START || stat == STAT_REP_START)
return 0;
error:
ret = octeon_i2c_recovery(i2c);
return (ret) ? ret : -EAGAIN;
}
static void octeon_i2c_stop(struct octeon_i2c *i2c)
{
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB | TWSI_CTL_STP);
}
static int octeon_i2c_write(struct octeon_i2c *i2c, int target,
const u8 *data, int length)
{
int i, result;
octeon_i2c_data_write(i2c, target << 1);
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
for (i = 0; i < length; i++) {
result = octeon_i2c_check_status(i2c, false);
if (result)
return result;
octeon_i2c_data_write(i2c, data[i]);
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
}
return 0;
}
static int octeon_i2c_read(struct octeon_i2c *i2c, int target,
u8 *data, u16 *rlength, bool recv_len)
{
int i, result, length = *rlength;
bool final_read = false;
octeon_i2c_data_write(i2c, (target << 1) | 1);
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
result = octeon_i2c_check_status(i2c, false);
if (result)
return result;
for (i = 0; i < length; i++) {
if ((i + 1 == length) && !(recv_len && i == 0))
final_read = true;
if (final_read)
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB);
else
octeon_i2c_ctl_write(i2c, TWSI_CTL_ENAB | TWSI_CTL_AAK);
result = octeon_i2c_wait(i2c);
if (result)
return result;
data[i] = octeon_i2c_data_read(i2c);
if (recv_len && i == 0) {
if (data[i] > I2C_SMBUS_BLOCK_MAX + 1)
return -EPROTO;
length += data[i];
}
result = octeon_i2c_check_status(i2c, final_read);
if (result)
return result;
}
*rlength = length;
return 0;
}
static int octeon_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
int i, ret = 0;
if (num == 1) {
if (msgs[0].len > 0 && msgs[0].len <= 8) {
if (msgs[0].flags & I2C_M_RD)
ret = octeon_i2c_hlc_read(i2c, msgs);
else
ret = octeon_i2c_hlc_write(i2c, msgs);
goto out;
}
} else if (num == 2) {
if ((msgs[0].flags & I2C_M_RD) == 0 &&
(msgs[1].flags & I2C_M_RECV_LEN) == 0 &&
msgs[0].len > 0 && msgs[0].len <= 2 &&
msgs[1].len > 0 && msgs[1].len <= 8 &&
msgs[0].addr == msgs[1].addr) {
if (msgs[1].flags & I2C_M_RD)
ret = octeon_i2c_hlc_comp_read(i2c, msgs);
else
ret = octeon_i2c_hlc_comp_write(i2c, msgs);
goto out;
}
}
for (i = 0; ret == 0 && i < num; i++) {
struct i2c_msg *pmsg = &msgs[i];
if (!pmsg->len) {
ret = -EOPNOTSUPP;
break;
}
ret = octeon_i2c_start(i2c);
if (ret)
return ret;
if (pmsg->flags & I2C_M_RD)
ret = octeon_i2c_read(i2c, pmsg->addr, pmsg->buf,
&pmsg->len, pmsg->flags & I2C_M_RECV_LEN);
else
ret = octeon_i2c_write(i2c, pmsg->addr, pmsg->buf,
pmsg->len);
}
octeon_i2c_stop(i2c);
out:
return (ret != 0) ? ret : num;
}
static int octeon_i2c_get_scl(struct i2c_adapter *adap)
{
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
u64 state;
state = octeon_i2c_read_int(i2c);
return state & TWSI_INT_SCL;
}
static void octeon_i2c_set_scl(struct i2c_adapter *adap, int val)
{
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
octeon_i2c_write_int(i2c, TWSI_INT_SCL_OVR);
}
static int octeon_i2c_get_sda(struct i2c_adapter *adap)
{
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
u64 state;
state = octeon_i2c_read_int(i2c);
return state & TWSI_INT_SDA;
}
static void octeon_i2c_prepare_recovery(struct i2c_adapter *adap)
{
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
octeon_i2c_stop(i2c);
octeon_i2c_hlc_disable(i2c);
octeon_i2c_write_int(i2c, 0);
}
static void octeon_i2c_unprepare_recovery(struct i2c_adapter *adap)
{
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
octeon_i2c_write_int(i2c, 0);
}
static u32 octeon_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK) |
I2C_FUNC_SMBUS_READ_BLOCK_DATA | I2C_SMBUS_BLOCK_PROC_CALL;
}
static int octeon_i2c_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
int irq, result = 0, hlc_irq = 0;
struct resource *res_mem;
struct octeon_i2c *i2c;
bool cn78xx_style;
cn78xx_style = of_device_is_compatible(node, "cavium,octeon-7890-twsi");
if (cn78xx_style) {
hlc_irq = platform_get_irq(pdev, 0);
if (hlc_irq < 0)
return hlc_irq;
irq = platform_get_irq(pdev, 2);
if (irq < 0)
return irq;
} else {
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
}
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c) {
result = -ENOMEM;
goto out;
}
i2c->dev = &pdev->dev;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->twsi_base = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(i2c->twsi_base)) {
result = PTR_ERR(i2c->twsi_base);
goto out;
}
if (of_property_read_u32(node, "clock-frequency", &i2c->twsi_freq) &&
of_property_read_u32(node, "clock-rate", &i2c->twsi_freq)) {
dev_err(i2c->dev,
"no I2C 'clock-rate' or 'clock-frequency' property\n");
result = -ENXIO;
goto out;
}
i2c->sys_freq = octeon_get_io_clock_rate();
init_waitqueue_head(&i2c->queue);
i2c->irq = irq;
if (cn78xx_style) {
i2c->hlc_irq = hlc_irq;
i2c->int_enable = octeon_i2c_int_enable78;
i2c->int_disable = octeon_i2c_int_disable78;
i2c->hlc_int_enable = octeon_i2c_hlc_int_enable78;
i2c->hlc_int_disable = octeon_i2c_hlc_int_disable78;
irq_set_status_flags(i2c->irq, IRQ_NOAUTOEN);
irq_set_status_flags(i2c->hlc_irq, IRQ_NOAUTOEN);
result = devm_request_irq(&pdev->dev, i2c->hlc_irq,
octeon_i2c_hlc_isr78, 0,
DRV_NAME, i2c);
if (result < 0) {
dev_err(i2c->dev, "failed to attach interrupt\n");
goto out;
}
} else {
i2c->int_enable = octeon_i2c_int_enable;
i2c->int_disable = octeon_i2c_int_disable;
i2c->hlc_int_enable = octeon_i2c_hlc_int_enable;
i2c->hlc_int_disable = octeon_i2c_int_disable;
}
result = devm_request_irq(&pdev->dev, i2c->irq,
octeon_i2c_isr, 0, DRV_NAME, i2c);
if (result < 0) {
dev_err(i2c->dev, "failed to attach interrupt\n");
goto out;
}
if (OCTEON_IS_MODEL(OCTEON_CN38XX))
i2c->broken_irq_check = true;
result = octeon_i2c_init_lowlevel(i2c);
if (result) {
dev_err(i2c->dev, "init low level failed\n");
goto out;
}
octeon_i2c_set_clock(i2c);
i2c->adap = octeon_i2c_ops;
i2c->adap.timeout = msecs_to_jiffies(2);
i2c->adap.retries = 5;
i2c->adap.bus_recovery_info = &octeon_i2c_recovery_info;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = node;
i2c_set_adapdata(&i2c->adap, i2c);
platform_set_drvdata(pdev, i2c);
result = i2c_add_adapter(&i2c->adap);
if (result < 0) {
dev_err(i2c->dev, "failed to add adapter\n");
goto out;
}
dev_info(i2c->dev, "probed\n");
return 0;
out:
return result;
}
static int octeon_i2c_remove(struct platform_device *pdev)
{
struct octeon_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
return 0;
}
