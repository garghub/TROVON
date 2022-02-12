static void img_i2c_writel(struct img_i2c *i2c, u32 offset, u32 value)
{
writel(value, i2c->base + offset);
}
static u32 img_i2c_readl(struct img_i2c *i2c, u32 offset)
{
return readl(i2c->base + offset);
}
static void img_i2c_wr_rd_fence(struct img_i2c *i2c)
{
if (i2c->need_wr_rd_fence) {
img_i2c_writel(i2c, SCB_CORE_REV_REG, 0);
img_i2c_writel(i2c, SCB_CORE_REV_REG, 0);
}
}
static void img_i2c_switch_mode(struct img_i2c *i2c, enum img_i2c_mode mode)
{
i2c->mode = mode;
i2c->int_enable = img_i2c_int_enable_by_mode[mode];
i2c->line_status = 0;
}
static void img_i2c_raw_op(struct img_i2c *i2c)
{
i2c->raw_timeout = 0;
img_i2c_writel(i2c, SCB_OVERRIDE_REG,
OVERRIDE_SCLKEN_OVR |
OVERRIDE_SDATEN_OVR |
OVERRIDE_MASTER |
OVERRIDE_LINE_OVR_EN |
OVERRIDE_DIRECT |
((i2c->at_cur_cmd & OVERRIDE_CMD_MASK) << OVERRIDE_CMD_SHIFT) |
(i2c->at_cur_data << OVERRIDE_DATA_SHIFT));
}
static const char *img_i2c_atomic_op_name(unsigned int cmd)
{
if (unlikely(cmd >= ARRAY_SIZE(img_i2c_atomic_cmd_names)))
return "UNKNOWN";
return img_i2c_atomic_cmd_names[cmd];
}
static void img_i2c_atomic_op(struct img_i2c *i2c, int cmd, u8 data)
{
i2c->at_cur_cmd = cmd;
i2c->at_cur_data = data;
if (cmd == CMD_GEN_DATA && i2c->mode == MODE_ATOMIC) {
u32 line_status = img_i2c_readl(i2c, SCB_STATUS_REG);
if (line_status & LINESTAT_SDAT_LINE_STATUS && !(data & 0x80)) {
img_i2c_switch_mode(i2c, MODE_RAW);
img_i2c_raw_op(i2c);
return;
}
}
dev_dbg(i2c->adap.dev.parent,
"atomic cmd=%s (%d) data=%#x\n",
img_i2c_atomic_op_name(cmd), cmd, data);
i2c->at_t_done = (cmd == CMD_RET_DATA || cmd == CMD_RET_ACK);
i2c->at_slave_event = false;
i2c->line_status = 0;
img_i2c_writel(i2c, SCB_OVERRIDE_REG,
((cmd & OVERRIDE_CMD_MASK) << OVERRIDE_CMD_SHIFT) |
OVERRIDE_MASTER |
OVERRIDE_DIRECT |
(data << OVERRIDE_DATA_SHIFT));
}
static void img_i2c_atomic_start(struct img_i2c *i2c)
{
img_i2c_switch_mode(i2c, MODE_ATOMIC);
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
img_i2c_atomic_op(i2c, CMD_GEN_START, 0x00);
}
static void img_i2c_soft_reset(struct img_i2c *i2c)
{
i2c->t_halt = false;
img_i2c_writel(i2c, SCB_CONTROL_REG, 0);
img_i2c_writel(i2c, SCB_CONTROL_REG,
SCB_CONTROL_CLK_ENABLE | SCB_CONTROL_SOFT_RESET);
}
static void img_i2c_transaction_halt(struct img_i2c *i2c, bool t_halt)
{
u32 val;
if (i2c->t_halt == t_halt)
return;
i2c->t_halt = t_halt;
val = img_i2c_readl(i2c, SCB_CONTROL_REG);
if (t_halt)
val |= SCB_CONTROL_TRANSACTION_HALT;
else
val &= ~SCB_CONTROL_TRANSACTION_HALT;
img_i2c_writel(i2c, SCB_CONTROL_REG, val);
}
static void img_i2c_read_fifo(struct img_i2c *i2c)
{
while (i2c->msg.len) {
u32 fifo_status;
u8 data;
fifo_status = img_i2c_readl(i2c, SCB_FIFO_STATUS_REG);
if (fifo_status & FIFO_READ_EMPTY)
break;
data = img_i2c_readl(i2c, SCB_READ_DATA_REG);
*i2c->msg.buf = data;
img_i2c_writel(i2c, SCB_READ_FIFO_REG, 0xff);
img_i2c_wr_rd_fence(i2c);
i2c->msg.len--;
i2c->msg.buf++;
}
}
static void img_i2c_write_fifo(struct img_i2c *i2c)
{
while (i2c->msg.len) {
u32 fifo_status;
fifo_status = img_i2c_readl(i2c, SCB_FIFO_STATUS_REG);
if (fifo_status & FIFO_WRITE_FULL)
break;
img_i2c_writel(i2c, SCB_WRITE_DATA_REG, *i2c->msg.buf);
img_i2c_wr_rd_fence(i2c);
i2c->msg.len--;
i2c->msg.buf++;
}
if (!i2c->msg.len)
i2c->int_enable &= ~INT_FIFO_EMPTYING;
}
static void img_i2c_read(struct img_i2c *i2c)
{
img_i2c_switch_mode(i2c, MODE_AUTOMATIC);
if (!i2c->last_msg)
i2c->int_enable |= INT_SLAVE_EVENT;
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
img_i2c_writel(i2c, SCB_READ_ADDR_REG, i2c->msg.addr);
img_i2c_writel(i2c, SCB_READ_COUNT_REG, i2c->msg.len);
img_i2c_transaction_halt(i2c, false);
mod_timer(&i2c->check_timer, jiffies + msecs_to_jiffies(1));
}
static void img_i2c_write(struct img_i2c *i2c)
{
img_i2c_switch_mode(i2c, MODE_AUTOMATIC);
if (!i2c->last_msg)
i2c->int_enable |= INT_SLAVE_EVENT;
img_i2c_writel(i2c, SCB_WRITE_ADDR_REG, i2c->msg.addr);
img_i2c_writel(i2c, SCB_WRITE_COUNT_REG, i2c->msg.len);
img_i2c_transaction_halt(i2c, false);
mod_timer(&i2c->check_timer, jiffies + msecs_to_jiffies(1));
img_i2c_write_fifo(i2c);
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
}
static void img_i2c_complete_transaction(struct img_i2c *i2c, int status)
{
img_i2c_switch_mode(i2c, MODE_INACTIVE);
if (status) {
i2c->msg_status = status;
img_i2c_transaction_halt(i2c, false);
}
complete(&i2c->msg_complete);
}
static unsigned int img_i2c_raw_atomic_delay_handler(struct img_i2c *i2c,
u32 int_status, u32 line_status)
{
img_i2c_atomic_op(i2c, i2c->at_cur_cmd, i2c->at_cur_data);
img_i2c_switch_mode(i2c, MODE_ATOMIC);
return 0;
}
static unsigned int img_i2c_raw(struct img_i2c *i2c, u32 int_status,
u32 line_status)
{
if (int_status & INT_TIMING) {
if (i2c->raw_timeout == 0)
return img_i2c_raw_atomic_delay_handler(i2c,
int_status, line_status);
--i2c->raw_timeout;
}
return 0;
}
static unsigned int img_i2c_sequence(struct img_i2c *i2c, u32 int_status)
{
static const unsigned int continue_bits[] = {
[CMD_GEN_START] = LINESTAT_START_BIT_DET,
[CMD_GEN_DATA] = LINESTAT_INPUT_HELD_V,
[CMD_RET_ACK] = LINESTAT_ACK_DET | LINESTAT_NACK_DET,
[CMD_RET_DATA] = LINESTAT_INPUT_HELD_V,
[CMD_GEN_STOP] = LINESTAT_STOP_BIT_DET,
};
int next_cmd = -1;
u8 next_data = 0x00;
if (int_status & INT_SLAVE_EVENT)
i2c->at_slave_event = true;
if (int_status & INT_TRANSACTION_DONE)
i2c->at_t_done = true;
if (!i2c->at_slave_event || !i2c->at_t_done)
return 0;
if (i2c->at_cur_cmd >= 0 &&
i2c->at_cur_cmd < ARRAY_SIZE(continue_bits)) {
unsigned int cont_bits = continue_bits[i2c->at_cur_cmd];
if (cont_bits) {
cont_bits |= LINESTAT_ABORT_DET;
if (!(i2c->line_status & cont_bits))
return 0;
}
}
next_cmd = *i2c->seq;
if (!next_cmd) {
img_i2c_writel(i2c, SCB_OVERRIDE_REG, 0);
return ISR_COMPLETE(0);
}
if (next_cmd == CMD_GEN_DATA) {
++i2c->seq;
next_data = *i2c->seq;
}
++i2c->seq;
img_i2c_atomic_op(i2c, next_cmd, next_data);
return 0;
}
static void img_i2c_reset_start(struct img_i2c *i2c)
{
img_i2c_switch_mode(i2c, MODE_SEQUENCE);
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
i2c->seq = img_i2c_reset_seq;
i2c->at_slave_event = true;
i2c->at_t_done = true;
i2c->at_cur_cmd = -1;
img_i2c_sequence(i2c, 0);
}
static void img_i2c_stop_start(struct img_i2c *i2c)
{
img_i2c_switch_mode(i2c, MODE_SEQUENCE);
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
i2c->seq = img_i2c_stop_seq;
i2c->at_slave_event = true;
i2c->at_t_done = true;
i2c->at_cur_cmd = -1;
img_i2c_sequence(i2c, 0);
}
static unsigned int img_i2c_atomic(struct img_i2c *i2c,
u32 int_status,
u32 line_status)
{
int next_cmd = -1;
u8 next_data = 0x00;
if (int_status & INT_SLAVE_EVENT)
i2c->at_slave_event = true;
if (int_status & INT_TRANSACTION_DONE)
i2c->at_t_done = true;
if (!i2c->at_slave_event || !i2c->at_t_done)
goto next_atomic_cmd;
if (i2c->line_status & LINESTAT_ABORT_DET) {
dev_dbg(i2c->adap.dev.parent, "abort condition detected\n");
next_cmd = CMD_GEN_STOP;
i2c->msg_status = -EIO;
goto next_atomic_cmd;
}
switch (i2c->at_cur_cmd) {
case CMD_GEN_START:
next_cmd = CMD_GEN_DATA;
next_data = (i2c->msg.addr << 1);
if (i2c->msg.flags & I2C_M_RD)
next_data |= 0x1;
break;
case CMD_GEN_DATA:
if (i2c->line_status & LINESTAT_INPUT_HELD_V)
next_cmd = CMD_RET_ACK;
break;
case CMD_RET_ACK:
if (i2c->line_status & LINESTAT_ACK_DET) {
if (i2c->msg.len == 0) {
next_cmd = CMD_GEN_STOP;
} else if (i2c->msg.flags & I2C_M_RD) {
next_cmd = CMD_RET_DATA;
} else {
next_cmd = CMD_GEN_DATA;
next_data = *i2c->msg.buf;
--i2c->msg.len;
++i2c->msg.buf;
}
} else if (i2c->line_status & LINESTAT_NACK_DET) {
i2c->msg_status = -EIO;
next_cmd = CMD_GEN_STOP;
}
break;
case CMD_RET_DATA:
if (i2c->line_status & LINESTAT_INPUT_HELD_V) {
*i2c->msg.buf = (i2c->line_status &
LINESTAT_INPUT_DATA)
>> LINESTAT_INPUT_DATA_SHIFT;
--i2c->msg.len;
++i2c->msg.buf;
if (i2c->msg.len)
next_cmd = CMD_GEN_ACK;
else
next_cmd = CMD_GEN_NACK;
}
break;
case CMD_GEN_ACK:
if (i2c->line_status & LINESTAT_ACK_DET) {
next_cmd = CMD_RET_DATA;
} else {
i2c->msg_status = -EIO;
next_cmd = CMD_GEN_STOP;
}
break;
case CMD_GEN_NACK:
next_cmd = CMD_GEN_STOP;
break;
case CMD_GEN_STOP:
img_i2c_writel(i2c, SCB_OVERRIDE_REG, 0);
return ISR_COMPLETE(0);
default:
dev_err(i2c->adap.dev.parent, "bad atomic command %d\n",
i2c->at_cur_cmd);
i2c->msg_status = -EIO;
next_cmd = CMD_GEN_STOP;
break;
}
next_atomic_cmd:
if (next_cmd != -1) {
if (next_cmd == CMD_GEN_STOP && !i2c->msg_status &&
!i2c->last_msg)
return ISR_COMPLETE(0);
img_i2c_atomic_op(i2c, next_cmd, next_data);
}
return 0;
}
static void img_i2c_check_timer(unsigned long arg)
{
struct img_i2c *i2c = (struct img_i2c *)arg;
unsigned long flags;
unsigned int line_status;
spin_lock_irqsave(&i2c->lock, flags);
line_status = img_i2c_readl(i2c, SCB_STATUS_REG);
if (line_status & LINESTAT_ABORT_DET) {
dev_dbg(i2c->adap.dev.parent,
"abort condition detected by check timer\n");
img_i2c_writel(i2c, SCB_INT_MASK_REG,
i2c->int_enable | INT_SLAVE_EVENT);
}
spin_unlock_irqrestore(&i2c->lock, flags);
}
static unsigned int img_i2c_auto(struct img_i2c *i2c,
unsigned int int_status,
unsigned int line_status)
{
if (int_status & (INT_WRITE_ACK_ERR | INT_ADDR_ACK_ERR))
return ISR_COMPLETE(EIO);
if (line_status & LINESTAT_ABORT_DET) {
dev_dbg(i2c->adap.dev.parent, "abort condition detected\n");
if ((i2c->msg.flags & I2C_M_RD) &&
(int_status & INT_FIFO_FULL_FILLING))
img_i2c_read_fifo(i2c);
i2c->msg_status = -EIO;
img_i2c_stop_start(i2c);
return 0;
}
if (!i2c->last_msg && i2c->line_status & LINESTAT_START_BIT_DET) {
img_i2c_transaction_halt(i2c, true);
i2c->int_enable &= ~INT_SLAVE_EVENT;
}
mod_timer(&i2c->check_timer, jiffies + msecs_to_jiffies(1));
if (i2c->msg.flags & I2C_M_RD) {
if (int_status & INT_FIFO_FULL_FILLING) {
img_i2c_read_fifo(i2c);
if (i2c->msg.len == 0)
return ISR_WAITSTOP;
}
} else {
if (int_status & INT_FIFO_EMPTY_EMPTYING) {
if ((int_status & INT_FIFO_EMPTY) &&
i2c->msg.len == 0)
return ISR_WAITSTOP;
img_i2c_write_fifo(i2c);
}
}
return 0;
}
static irqreturn_t img_i2c_isr(int irq, void *dev_id)
{
struct img_i2c *i2c = (struct img_i2c *)dev_id;
u32 int_status, line_status;
unsigned int hret;
int_status = img_i2c_readl(i2c, SCB_INT_STATUS_REG);
img_i2c_writel(i2c, SCB_INT_CLEAR_REG, int_status);
line_status = img_i2c_readl(i2c, SCB_STATUS_REG);
if (line_status & LINESTAT_LATCHED) {
img_i2c_writel(i2c, SCB_CLEAR_REG,
(line_status & LINESTAT_LATCHED)
>> LINESTAT_CLEAR_SHIFT);
img_i2c_wr_rd_fence(i2c);
}
spin_lock(&i2c->lock);
i2c->line_status &= ~LINESTAT_INPUT_DATA;
i2c->line_status |= line_status;
if ((int_status & INT_SCLK_LOW_TIMEOUT) &&
!(int_status & (INT_SLAVE_EVENT |
INT_FIFO_EMPTY |
INT_FIFO_FULL))) {
dev_crit(i2c->adap.dev.parent,
"fatal: clock low timeout occurred %s addr 0x%02x\n",
(i2c->msg.flags & I2C_M_RD) ? "reading" : "writing",
i2c->msg.addr);
hret = ISR_FATAL(EIO);
goto out;
}
if (i2c->mode == MODE_ATOMIC)
hret = img_i2c_atomic(i2c, int_status, line_status);
else if (i2c->mode == MODE_AUTOMATIC)
hret = img_i2c_auto(i2c, int_status, line_status);
else if (i2c->mode == MODE_SEQUENCE)
hret = img_i2c_sequence(i2c, int_status);
else if (i2c->mode == MODE_WAITSTOP && (int_status & INT_SLAVE_EVENT) &&
(line_status & LINESTAT_STOP_BIT_DET))
hret = ISR_COMPLETE(0);
else if (i2c->mode == MODE_RAW)
hret = img_i2c_raw(i2c, int_status, line_status);
else
hret = 0;
img_i2c_writel(i2c, SCB_INT_CLEAR_REG, int_status & INT_LEVEL);
out:
if (hret & ISR_WAITSTOP) {
if (!i2c->last_msg || i2c->line_status & LINESTAT_STOP_BIT_DET)
hret = ISR_COMPLETE(0);
else
img_i2c_switch_mode(i2c, MODE_WAITSTOP);
}
if (hret & ISR_COMPLETE_M) {
int status = -(hret & ISR_STATUS_M);
img_i2c_complete_transaction(i2c, status);
if (hret & ISR_FATAL_M)
img_i2c_switch_mode(i2c, MODE_FATAL);
}
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
spin_unlock(&i2c->lock);
return IRQ_HANDLED;
}
static int img_i2c_reset_bus(struct img_i2c *i2c)
{
unsigned long flags;
unsigned long time_left;
spin_lock_irqsave(&i2c->lock, flags);
reinit_completion(&i2c->msg_complete);
img_i2c_reset_start(i2c);
spin_unlock_irqrestore(&i2c->lock, flags);
time_left = wait_for_completion_timeout(&i2c->msg_complete,
IMG_I2C_TIMEOUT);
if (time_left == 0)
return -ETIMEDOUT;
return 0;
}
static int img_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct img_i2c *i2c = i2c_get_adapdata(adap);
bool atomic = false;
int i, ret;
unsigned long time_left;
if (i2c->mode == MODE_SUSPEND) {
WARN(1, "refusing to service transaction in suspended state\n");
return -EIO;
}
if (i2c->mode == MODE_FATAL)
return -EIO;
for (i = 0; i < num; i++) {
if (likely(msgs[i].len))
continue;
if (unlikely(msgs[i].flags & I2C_M_RD))
return -EIO;
atomic = true;
}
ret = clk_prepare_enable(i2c->scb_clk);
if (ret)
return ret;
for (i = 0; i < num; i++) {
struct i2c_msg *msg = &msgs[i];
unsigned long flags;
spin_lock_irqsave(&i2c->lock, flags);
i2c->msg = *msg;
i2c->msg_status = 0;
i2c->last_msg = (i == num - 1);
reinit_completion(&i2c->msg_complete);
if (atomic)
img_i2c_atomic_start(i2c);
else if (msg->flags & I2C_M_RD)
img_i2c_read(i2c);
else
img_i2c_write(i2c);
spin_unlock_irqrestore(&i2c->lock, flags);
time_left = wait_for_completion_timeout(&i2c->msg_complete,
IMG_I2C_TIMEOUT);
del_timer_sync(&i2c->check_timer);
if (time_left == 0) {
dev_err(adap->dev.parent, "i2c transfer timed out\n");
i2c->msg_status = -ETIMEDOUT;
break;
}
if (i2c->msg_status)
break;
}
clk_disable_unprepare(i2c->scb_clk);
return i2c->msg_status ? i2c->msg_status : num;
}
static u32 img_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int img_i2c_init(struct img_i2c *i2c)
{
unsigned int clk_khz, bitrate_khz, clk_period, tckh, tckl, tsdh;
unsigned int i, ret, data, prescale, inc, int_bitrate, filt;
struct img_i2c_timings timing;
u32 rev;
ret = clk_prepare_enable(i2c->scb_clk);
if (ret)
return ret;
rev = img_i2c_readl(i2c, SCB_CORE_REV_REG);
if ((rev & 0x00ffffff) < 0x00020200) {
dev_info(i2c->adap.dev.parent,
"Unknown hardware revision (%d.%d.%d.%d)\n",
(rev >> 24) & 0xff, (rev >> 16) & 0xff,
(rev >> 8) & 0xff, rev & 0xff);
clk_disable_unprepare(i2c->scb_clk);
return -EINVAL;
}
if (rev == REL_SOC_IP_SCB_2_2_1) {
i2c->need_wr_rd_fence = true;
dev_info(i2c->adap.dev.parent, "fence quirk enabled");
}
bitrate_khz = i2c->bitrate / 1000;
clk_khz = clk_get_rate(i2c->scb_clk) / 1000;
timing = timings[0];
for (i = 0; i < ARRAY_SIZE(timings); i++) {
if (i2c->bitrate <= timings[i].max_bitrate) {
timing = timings[i];
break;
}
}
prescale = SCB_OPT_INC * clk_khz / (256 * 16 * bitrate_khz);
prescale = clamp_t(unsigned int, prescale, 1, 8);
clk_khz /= prescale;
inc = (256 * 16 * bitrate_khz) / clk_khz;
if (clk_khz < 20000) {
filt = SCB_FILT_DISABLE;
} else if (clk_khz < 40000) {
filt = SCB_FILT_BYPASS;
} else {
filt = (64000 / ((clk_khz / 1000) * SCB_FILT_GLITCH));
if (64000 % ((clk_khz / 1000) * SCB_FILT_GLITCH))
inc++;
if (filt > SCB_FILT_INC_MASK)
filt = SCB_FILT_INC_MASK;
filt = (filt & SCB_FILT_INC_MASK) << SCB_FILT_INC_SHIFT;
}
data = filt | ((inc & SCB_INC_MASK) << SCB_INC_SHIFT) | (prescale - 1);
img_i2c_writel(i2c, SCB_CLK_SET_REG, data);
clk_period = (256 * 1000000) / (clk_khz * inc);
int_bitrate = 1000000 / (bitrate_khz * clk_period);
if ((1000000 % (bitrate_khz * clk_period)) >=
((bitrate_khz * clk_period) / 2))
int_bitrate++;
tckh = timing.tckh / clk_period;
if (timing.tckh % clk_period)
tckh++;
if (tckh > 0)
data = tckh - 1;
else
data = 0;
img_i2c_writel(i2c, SCB_TIME_TCKH_REG, data);
tckl = int_bitrate - tckh;
if (tckl > 0)
data = tckl - 1;
else
data = 0;
img_i2c_writel(i2c, SCB_TIME_TCKL_REG, data);
tsdh = timing.tsdh / clk_period;
if (timing.tsdh % clk_period)
tsdh++;
if (tsdh > 1)
data = tsdh - 1;
else
data = 0x01;
img_i2c_writel(i2c, SCB_TIME_TSDH_REG, data);
tsdh = data;
data = timing.tpl / clk_period;
if (data > 0)
--data;
img_i2c_writel(i2c, SCB_TIME_TPL_REG, data);
data = timing.tph / clk_period;
if (data > 0)
--data;
img_i2c_writel(i2c, SCB_TIME_TPH_REG, data);
img_i2c_writel(i2c, SCB_TIME_TSDL_REG, data + tsdh + 2);
data = timing.tp2s / clk_period;
if (data > 0)
--data;
img_i2c_writel(i2c, SCB_TIME_TP2S_REG, data);
img_i2c_writel(i2c, SCB_TIME_TBI_REG, TIMEOUT_TBI);
img_i2c_writel(i2c, SCB_TIME_TSL_REG, TIMEOUT_TSL);
img_i2c_writel(i2c, SCB_TIME_TDL_REG, TIMEOUT_TDL);
img_i2c_soft_reset(i2c);
img_i2c_writel(i2c, SCB_INT_MASK_REG, 0);
img_i2c_writel(i2c, SCB_INT_CLEAR_REG, ~0);
img_i2c_writel(i2c, SCB_CLEAR_REG, ~0);
img_i2c_writel(i2c, SCB_INT_MASK_REG, i2c->int_enable);
ret = img_i2c_reset_bus(i2c);
clk_disable_unprepare(i2c->scb_clk);
return ret;
}
static int img_i2c_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct img_i2c *i2c;
struct resource *res;
int irq, ret;
u32 val;
i2c = devm_kzalloc(&pdev->dev, sizeof(struct img_i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->base))
return PTR_ERR(i2c->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "can't get irq number\n");
return irq;
}
i2c->sys_clk = devm_clk_get(&pdev->dev, "sys");
if (IS_ERR(i2c->sys_clk)) {
dev_err(&pdev->dev, "can't get system clock\n");
return PTR_ERR(i2c->sys_clk);
}
i2c->scb_clk = devm_clk_get(&pdev->dev, "scb");
if (IS_ERR(i2c->scb_clk)) {
dev_err(&pdev->dev, "can't get core clock\n");
return PTR_ERR(i2c->scb_clk);
}
ret = devm_request_irq(&pdev->dev, irq, img_i2c_isr, 0,
pdev->name, i2c);
if (ret) {
dev_err(&pdev->dev, "can't request irq %d\n", irq);
return ret;
}
init_timer(&i2c->check_timer);
i2c->check_timer.function = img_i2c_check_timer;
i2c->check_timer.data = (unsigned long)i2c;
i2c->bitrate = timings[0].max_bitrate;
if (!of_property_read_u32(node, "clock-frequency", &val))
i2c->bitrate = val;
i2c_set_adapdata(&i2c->adap, i2c);
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = node;
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &img_i2c_algo;
i2c->adap.retries = 5;
i2c->adap.nr = pdev->id;
snprintf(i2c->adap.name, sizeof(i2c->adap.name), "IMG SCB I2C");
img_i2c_switch_mode(i2c, MODE_INACTIVE);
spin_lock_init(&i2c->lock);
init_completion(&i2c->msg_complete);
platform_set_drvdata(pdev, i2c);
ret = clk_prepare_enable(i2c->sys_clk);
if (ret)
return ret;
ret = img_i2c_init(i2c);
if (ret)
goto disable_clk;
ret = i2c_add_numbered_adapter(&i2c->adap);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add adapter\n");
goto disable_clk;
}
return 0;
disable_clk:
clk_disable_unprepare(i2c->sys_clk);
return ret;
}
static int img_i2c_remove(struct platform_device *dev)
{
struct img_i2c *i2c = platform_get_drvdata(dev);
i2c_del_adapter(&i2c->adap);
clk_disable_unprepare(i2c->sys_clk);
return 0;
}
static int img_i2c_suspend(struct device *dev)
{
struct img_i2c *i2c = dev_get_drvdata(dev);
img_i2c_switch_mode(i2c, MODE_SUSPEND);
clk_disable_unprepare(i2c->sys_clk);
return 0;
}
static int img_i2c_resume(struct device *dev)
{
struct img_i2c *i2c = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(i2c->sys_clk);
if (ret)
return ret;
img_i2c_init(i2c);
return 0;
}
