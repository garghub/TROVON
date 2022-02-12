static inline void i2c_writel(struct rk3x_i2c *i2c, u32 value,
unsigned int offset)
{
writel(value, i2c->regs + offset);
}
static inline u32 i2c_readl(struct rk3x_i2c *i2c, unsigned int offset)
{
return readl(i2c->regs + offset);
}
static inline void rk3x_i2c_clean_ipd(struct rk3x_i2c *i2c)
{
i2c_writel(i2c, REG_INT_ALL, REG_IPD);
}
static void rk3x_i2c_start(struct rk3x_i2c *i2c)
{
u32 val = i2c_readl(i2c, REG_CON) & REG_CON_TUNING_MASK;
i2c_writel(i2c, REG_INT_START, REG_IEN);
val |= REG_CON_EN | REG_CON_MOD(i2c->mode) | REG_CON_START;
if (!(i2c->msg->flags & I2C_M_IGNORE_NAK))
val |= REG_CON_ACTACK;
i2c_writel(i2c, val, REG_CON);
}
static void rk3x_i2c_stop(struct rk3x_i2c *i2c, int error)
{
unsigned int ctrl;
i2c->processed = 0;
i2c->msg = NULL;
i2c->error = error;
if (i2c->is_last_msg) {
i2c_writel(i2c, REG_INT_STOP, REG_IEN);
i2c->state = STATE_STOP;
ctrl = i2c_readl(i2c, REG_CON);
ctrl |= REG_CON_STOP;
i2c_writel(i2c, ctrl, REG_CON);
} else {
i2c->busy = false;
i2c->state = STATE_IDLE;
ctrl = i2c_readl(i2c, REG_CON) & REG_CON_TUNING_MASK;
i2c_writel(i2c, ctrl, REG_CON);
wake_up(&i2c->wait);
}
}
static void rk3x_i2c_prepare_read(struct rk3x_i2c *i2c)
{
unsigned int len = i2c->msg->len - i2c->processed;
u32 con;
con = i2c_readl(i2c, REG_CON);
if (len > 32) {
len = 32;
con &= ~REG_CON_LASTACK;
} else {
con |= REG_CON_LASTACK;
}
if (i2c->processed != 0) {
con &= ~REG_CON_MOD_MASK;
con |= REG_CON_MOD(REG_CON_MOD_RX);
}
i2c_writel(i2c, con, REG_CON);
i2c_writel(i2c, len, REG_MRXCNT);
}
static void rk3x_i2c_fill_transmit_buf(struct rk3x_i2c *i2c)
{
unsigned int i, j;
u32 cnt = 0;
u32 val;
u8 byte;
for (i = 0; i < 8; ++i) {
val = 0;
for (j = 0; j < 4; ++j) {
if ((i2c->processed == i2c->msg->len) && (cnt != 0))
break;
if (i2c->processed == 0 && cnt == 0)
byte = (i2c->addr & 0x7f) << 1;
else
byte = i2c->msg->buf[i2c->processed++];
val |= byte << (j * 8);
cnt++;
}
i2c_writel(i2c, val, TXBUFFER_BASE + 4 * i);
if (i2c->processed == i2c->msg->len)
break;
}
i2c_writel(i2c, cnt, REG_MTXCNT);
}
static void rk3x_i2c_handle_start(struct rk3x_i2c *i2c, unsigned int ipd)
{
if (!(ipd & REG_INT_START)) {
rk3x_i2c_stop(i2c, -EIO);
dev_warn(i2c->dev, "unexpected irq in START: 0x%x\n", ipd);
rk3x_i2c_clean_ipd(i2c);
return;
}
i2c_writel(i2c, REG_INT_START, REG_IPD);
i2c_writel(i2c, i2c_readl(i2c, REG_CON) & ~REG_CON_START, REG_CON);
if (i2c->mode == REG_CON_MOD_TX) {
i2c_writel(i2c, REG_INT_MBTF | REG_INT_NAKRCV, REG_IEN);
i2c->state = STATE_WRITE;
rk3x_i2c_fill_transmit_buf(i2c);
} else {
i2c_writel(i2c, REG_INT_MBRF | REG_INT_NAKRCV, REG_IEN);
i2c->state = STATE_READ;
rk3x_i2c_prepare_read(i2c);
}
}
static void rk3x_i2c_handle_write(struct rk3x_i2c *i2c, unsigned int ipd)
{
if (!(ipd & REG_INT_MBTF)) {
rk3x_i2c_stop(i2c, -EIO);
dev_err(i2c->dev, "unexpected irq in WRITE: 0x%x\n", ipd);
rk3x_i2c_clean_ipd(i2c);
return;
}
i2c_writel(i2c, REG_INT_MBTF, REG_IPD);
if (i2c->processed == i2c->msg->len)
rk3x_i2c_stop(i2c, i2c->error);
else
rk3x_i2c_fill_transmit_buf(i2c);
}
static void rk3x_i2c_handle_read(struct rk3x_i2c *i2c, unsigned int ipd)
{
unsigned int i;
unsigned int len = i2c->msg->len - i2c->processed;
u32 uninitialized_var(val);
u8 byte;
if (!(ipd & REG_INT_MBRF))
return;
i2c_writel(i2c, REG_INT_MBRF, REG_IPD);
if (len > 32)
len = 32;
for (i = 0; i < len; ++i) {
if (i % 4 == 0)
val = i2c_readl(i2c, RXBUFFER_BASE + (i / 4) * 4);
byte = (val >> ((i % 4) * 8)) & 0xff;
i2c->msg->buf[i2c->processed++] = byte;
}
if (i2c->processed == i2c->msg->len)
rk3x_i2c_stop(i2c, i2c->error);
else
rk3x_i2c_prepare_read(i2c);
}
static void rk3x_i2c_handle_stop(struct rk3x_i2c *i2c, unsigned int ipd)
{
unsigned int con;
if (!(ipd & REG_INT_STOP)) {
rk3x_i2c_stop(i2c, -EIO);
dev_err(i2c->dev, "unexpected irq in STOP: 0x%x\n", ipd);
rk3x_i2c_clean_ipd(i2c);
return;
}
i2c_writel(i2c, REG_INT_STOP, REG_IPD);
con = i2c_readl(i2c, REG_CON);
con &= ~REG_CON_STOP;
i2c_writel(i2c, con, REG_CON);
i2c->busy = false;
i2c->state = STATE_IDLE;
wake_up(&i2c->wait);
}
static irqreturn_t rk3x_i2c_irq(int irqno, void *dev_id)
{
struct rk3x_i2c *i2c = dev_id;
unsigned int ipd;
spin_lock(&i2c->lock);
ipd = i2c_readl(i2c, REG_IPD);
if (i2c->state == STATE_IDLE) {
dev_warn(i2c->dev, "irq in STATE_IDLE, ipd = 0x%x\n", ipd);
rk3x_i2c_clean_ipd(i2c);
goto out;
}
dev_dbg(i2c->dev, "IRQ: state %d, ipd: %x\n", i2c->state, ipd);
ipd &= ~(REG_INT_BRF | REG_INT_BTF);
if (ipd & REG_INT_NAKRCV) {
i2c_writel(i2c, REG_INT_NAKRCV, REG_IPD);
ipd &= ~REG_INT_NAKRCV;
if (!(i2c->msg->flags & I2C_M_IGNORE_NAK))
rk3x_i2c_stop(i2c, -ENXIO);
}
if ((ipd & REG_INT_ALL) == 0)
goto out;
switch (i2c->state) {
case STATE_START:
rk3x_i2c_handle_start(i2c, ipd);
break;
case STATE_WRITE:
rk3x_i2c_handle_write(i2c, ipd);
break;
case STATE_READ:
rk3x_i2c_handle_read(i2c, ipd);
break;
case STATE_STOP:
rk3x_i2c_handle_stop(i2c, ipd);
break;
case STATE_IDLE:
break;
}
out:
spin_unlock(&i2c->lock);
return IRQ_HANDLED;
}
static const struct i2c_spec_values *rk3x_i2c_get_spec(unsigned int speed)
{
if (speed <= 100000)
return &standard_mode_spec;
else if (speed <= 400000)
return &fast_mode_spec;
else
return &fast_mode_plus_spec;
}
static int rk3x_i2c_v0_calc_timings(unsigned long clk_rate,
struct i2c_timings *t,
struct rk3x_i2c_calced_timings *t_calc)
{
unsigned long min_low_ns, min_high_ns;
unsigned long max_low_ns, min_total_ns;
unsigned long clk_rate_khz, scl_rate_khz;
unsigned long min_low_div, min_high_div;
unsigned long max_low_div;
unsigned long min_div_for_hold, min_total_div;
unsigned long extra_div, extra_low_div, ideal_low_div;
unsigned long data_hold_buffer_ns = 50;
const struct i2c_spec_values *spec;
int ret = 0;
if (WARN_ON(t->bus_freq_hz > 400000))
t->bus_freq_hz = 400000;
if (WARN_ON(t->bus_freq_hz < 1000))
t->bus_freq_hz = 1000;
spec = rk3x_i2c_get_spec(t->bus_freq_hz);
min_high_ns = t->scl_rise_ns + spec->min_high_ns;
min_high_ns = max(min_high_ns, DIV_ROUND_UP(
(t->scl_rise_ns + spec->min_setup_start_ns) * 1000, 875));
min_high_ns = max(min_high_ns, DIV_ROUND_UP(
(t->scl_rise_ns + spec->min_setup_start_ns + t->sda_fall_ns +
spec->min_high_ns), 2));
min_low_ns = t->scl_fall_ns + spec->min_low_ns;
max_low_ns = spec->max_data_hold_ns * 2 - data_hold_buffer_ns;
min_total_ns = min_low_ns + min_high_ns;
clk_rate_khz = DIV_ROUND_UP(clk_rate, 1000);
scl_rate_khz = t->bus_freq_hz / 1000;
min_total_div = DIV_ROUND_UP(clk_rate_khz, scl_rate_khz * 8);
min_low_div = DIV_ROUND_UP(clk_rate_khz * min_low_ns, 8 * 1000000);
min_high_div = DIV_ROUND_UP(clk_rate_khz * min_high_ns, 8 * 1000000);
min_div_for_hold = (min_low_div + min_high_div);
max_low_div = clk_rate_khz * max_low_ns / (8 * 1000000);
if (min_low_div > max_low_div) {
WARN_ONCE(true,
"Conflicting, min_low_div %lu, max_low_div %lu\n",
min_low_div, max_low_div);
max_low_div = min_low_div;
}
if (min_div_for_hold > min_total_div) {
t_calc->div_low = min_low_div;
t_calc->div_high = min_high_div;
} else {
extra_div = min_total_div - min_div_for_hold;
ideal_low_div = DIV_ROUND_UP(clk_rate_khz * min_low_ns,
scl_rate_khz * 8 * min_total_ns);
if (ideal_low_div > max_low_div)
ideal_low_div = max_low_div;
if (ideal_low_div > min_low_div + extra_div)
ideal_low_div = min_low_div + extra_div;
extra_low_div = ideal_low_div - min_low_div;
t_calc->div_low = ideal_low_div;
t_calc->div_high = min_high_div + (extra_div - extra_low_div);
}
t_calc->div_low--;
t_calc->div_high--;
t_calc->tuning = 0;
if (t_calc->div_low > 0xffff) {
t_calc->div_low = 0xffff;
ret = -EINVAL;
}
if (t_calc->div_high > 0xffff) {
t_calc->div_high = 0xffff;
ret = -EINVAL;
}
return ret;
}
static int rk3x_i2c_v1_calc_timings(unsigned long clk_rate,
struct i2c_timings *t,
struct rk3x_i2c_calced_timings *t_calc)
{
unsigned long min_low_ns, min_high_ns;
unsigned long min_setup_start_ns, min_setup_data_ns;
unsigned long min_setup_stop_ns, max_hold_data_ns;
unsigned long clk_rate_khz, scl_rate_khz;
unsigned long min_low_div, min_high_div;
unsigned long min_div_for_hold, min_total_div;
unsigned long extra_div, extra_low_div;
unsigned long sda_update_cfg, stp_sta_cfg, stp_sto_cfg;
const struct i2c_spec_values *spec;
int ret = 0;
if (WARN_ON(t->bus_freq_hz > 1000000))
t->bus_freq_hz = 1000000;
if (WARN_ON(t->bus_freq_hz < 1000))
t->bus_freq_hz = 1000;
spec = rk3x_i2c_get_spec(t->bus_freq_hz);
clk_rate_khz = DIV_ROUND_UP(clk_rate, 1000);
scl_rate_khz = t->bus_freq_hz / 1000;
min_total_div = DIV_ROUND_UP(clk_rate_khz, scl_rate_khz * 8);
min_high_ns = t->scl_rise_ns + spec->min_high_ns;
min_high_div = DIV_ROUND_UP(clk_rate_khz * min_high_ns, 8 * 1000000);
min_low_ns = t->scl_fall_ns + spec->min_low_ns;
min_low_div = DIV_ROUND_UP(clk_rate_khz * min_low_ns, 8 * 1000000);
min_high_div = (min_high_div < 1) ? 2 : min_high_div;
min_low_div = (min_low_div < 1) ? 2 : min_low_div;
min_div_for_hold = (min_low_div + min_high_div);
if (min_div_for_hold >= min_total_div) {
t_calc->div_low = min_low_div;
t_calc->div_high = min_high_div;
} else {
extra_div = min_total_div - min_div_for_hold;
extra_low_div = DIV_ROUND_UP(min_low_div * extra_div,
min_div_for_hold);
t_calc->div_low = min_low_div + extra_low_div;
t_calc->div_high = min_high_div + (extra_div - extra_low_div);
}
for (sda_update_cfg = 3; sda_update_cfg > 0; sda_update_cfg--) {
max_hold_data_ns = DIV_ROUND_UP((sda_update_cfg
* (t_calc->div_low) + 1)
* 1000000, clk_rate_khz);
min_setup_data_ns = DIV_ROUND_UP(((8 - sda_update_cfg)
* (t_calc->div_low) + 1)
* 1000000, clk_rate_khz);
if ((max_hold_data_ns < spec->max_data_hold_ns) &&
(min_setup_data_ns > spec->min_data_setup_ns))
break;
}
min_setup_start_ns = t->scl_rise_ns + spec->min_setup_start_ns;
stp_sta_cfg = DIV_ROUND_UP(clk_rate_khz * min_setup_start_ns
- 1000000, 8 * 1000000 * (t_calc->div_high));
min_setup_stop_ns = t->scl_rise_ns + spec->min_setup_stop_ns;
stp_sto_cfg = DIV_ROUND_UP(clk_rate_khz * min_setup_stop_ns
- 1000000, 8 * 1000000 * (t_calc->div_high));
t_calc->tuning = REG_CON_SDA_CFG(--sda_update_cfg) |
REG_CON_STA_CFG(--stp_sta_cfg) |
REG_CON_STO_CFG(--stp_sto_cfg);
t_calc->div_low--;
t_calc->div_high--;
if (t_calc->div_low > 0xffff) {
t_calc->div_low = 0xffff;
ret = -EINVAL;
}
if (t_calc->div_high > 0xffff) {
t_calc->div_high = 0xffff;
ret = -EINVAL;
}
return ret;
}
static void rk3x_i2c_adapt_div(struct rk3x_i2c *i2c, unsigned long clk_rate)
{
struct i2c_timings *t = &i2c->t;
struct rk3x_i2c_calced_timings calc;
u64 t_low_ns, t_high_ns;
unsigned long flags;
u32 val;
int ret;
ret = i2c->soc_data->calc_timings(clk_rate, t, &calc);
WARN_ONCE(ret != 0, "Could not reach SCL freq %u", t->bus_freq_hz);
clk_enable(i2c->pclk);
spin_lock_irqsave(&i2c->lock, flags);
val = i2c_readl(i2c, REG_CON);
val &= ~REG_CON_TUNING_MASK;
val |= calc.tuning;
i2c_writel(i2c, val, REG_CON);
i2c_writel(i2c, (calc.div_high << 16) | (calc.div_low & 0xffff),
REG_CLKDIV);
spin_unlock_irqrestore(&i2c->lock, flags);
clk_disable(i2c->pclk);
t_low_ns = div_u64(((u64)calc.div_low + 1) * 8 * 1000000000, clk_rate);
t_high_ns = div_u64(((u64)calc.div_high + 1) * 8 * 1000000000,
clk_rate);
dev_dbg(i2c->dev,
"CLK %lukhz, Req %uns, Act low %lluns high %lluns\n",
clk_rate / 1000,
1000000000 / t->bus_freq_hz,
t_low_ns, t_high_ns);
}
static int rk3x_i2c_clk_notifier_cb(struct notifier_block *nb, unsigned long
event, void *data)
{
struct clk_notifier_data *ndata = data;
struct rk3x_i2c *i2c = container_of(nb, struct rk3x_i2c, clk_rate_nb);
struct rk3x_i2c_calced_timings calc;
switch (event) {
case PRE_RATE_CHANGE:
if (i2c->soc_data->calc_timings(ndata->new_rate, &i2c->t,
&calc) != 0)
return NOTIFY_STOP;
if (ndata->new_rate > ndata->old_rate)
rk3x_i2c_adapt_div(i2c, ndata->new_rate);
return NOTIFY_OK;
case POST_RATE_CHANGE:
if (ndata->new_rate < ndata->old_rate)
rk3x_i2c_adapt_div(i2c, ndata->new_rate);
return NOTIFY_OK;
case ABORT_RATE_CHANGE:
if (ndata->new_rate > ndata->old_rate)
rk3x_i2c_adapt_div(i2c, ndata->old_rate);
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static int rk3x_i2c_setup(struct rk3x_i2c *i2c, struct i2c_msg *msgs, int num)
{
u32 addr = (msgs[0].addr & 0x7f) << 1;
int ret = 0;
if (num >= 2 && msgs[0].len < 4 &&
!(msgs[0].flags & I2C_M_RD) && (msgs[1].flags & I2C_M_RD)) {
u32 reg_addr = 0;
int i;
dev_dbg(i2c->dev, "Combined write/read from addr 0x%x\n",
addr >> 1);
for (i = 0; i < msgs[0].len; ++i) {
reg_addr |= msgs[0].buf[i] << (i * 8);
reg_addr |= REG_MRXADDR_VALID(i);
}
i2c->msg = &msgs[1];
i2c->mode = REG_CON_MOD_REGISTER_TX;
i2c_writel(i2c, addr | REG_MRXADDR_VALID(0), REG_MRXADDR);
i2c_writel(i2c, reg_addr, REG_MRXRADDR);
ret = 2;
} else {
if (msgs[0].flags & I2C_M_RD) {
addr |= 1;
i2c->mode = REG_CON_MOD_REGISTER_TX;
i2c_writel(i2c, addr | REG_MRXADDR_VALID(0),
REG_MRXADDR);
i2c_writel(i2c, 0, REG_MRXRADDR);
} else {
i2c->mode = REG_CON_MOD_TX;
}
i2c->msg = &msgs[0];
ret = 1;
}
i2c->addr = msgs[0].addr;
i2c->busy = true;
i2c->state = STATE_START;
i2c->processed = 0;
i2c->error = 0;
rk3x_i2c_clean_ipd(i2c);
return ret;
}
static int rk3x_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct rk3x_i2c *i2c = (struct rk3x_i2c *)adap->algo_data;
unsigned long timeout, flags;
u32 val;
int ret = 0;
int i;
spin_lock_irqsave(&i2c->lock, flags);
clk_enable(i2c->clk);
clk_enable(i2c->pclk);
i2c->is_last_msg = false;
for (i = 0; i < num; i += ret) {
ret = rk3x_i2c_setup(i2c, msgs + i, num - i);
if (ret < 0) {
dev_err(i2c->dev, "rk3x_i2c_setup() failed\n");
break;
}
if (i + ret >= num)
i2c->is_last_msg = true;
spin_unlock_irqrestore(&i2c->lock, flags);
rk3x_i2c_start(i2c);
timeout = wait_event_timeout(i2c->wait, !i2c->busy,
msecs_to_jiffies(WAIT_TIMEOUT));
spin_lock_irqsave(&i2c->lock, flags);
if (timeout == 0) {
dev_err(i2c->dev, "timeout, ipd: 0x%02x, state: %d\n",
i2c_readl(i2c, REG_IPD), i2c->state);
i2c_writel(i2c, 0, REG_IEN);
val = i2c_readl(i2c, REG_CON) & REG_CON_TUNING_MASK;
val |= REG_CON_EN | REG_CON_STOP;
i2c_writel(i2c, val, REG_CON);
i2c->state = STATE_IDLE;
ret = -ETIMEDOUT;
break;
}
if (i2c->error) {
ret = i2c->error;
break;
}
}
clk_disable(i2c->pclk);
clk_disable(i2c->clk);
spin_unlock_irqrestore(&i2c->lock, flags);
return ret < 0 ? ret : num;
}
static __maybe_unused int rk3x_i2c_resume(struct device *dev)
{
struct rk3x_i2c *i2c = dev_get_drvdata(dev);
rk3x_i2c_adapt_div(i2c, clk_get_rate(i2c->clk));
return 0;
}
static u32 rk3x_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_PROTOCOL_MANGLING;
}
static int rk3x_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct rk3x_i2c *i2c;
struct resource *mem;
int ret = 0;
int bus_nr;
u32 value;
int irq;
unsigned long clk_rate;
i2c = devm_kzalloc(&pdev->dev, sizeof(struct rk3x_i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
match = of_match_node(rk3x_i2c_match, np);
i2c->soc_data = (struct rk3x_i2c_soc_data *)match->data;
i2c_parse_fw_timings(&pdev->dev, &i2c->t, true);
strlcpy(i2c->adap.name, "rk3x-i2c", sizeof(i2c->adap.name));
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &rk3x_i2c_algorithm;
i2c->adap.retries = 3;
i2c->adap.dev.of_node = np;
i2c->adap.algo_data = i2c;
i2c->adap.dev.parent = &pdev->dev;
i2c->dev = &pdev->dev;
spin_lock_init(&i2c->lock);
init_waitqueue_head(&i2c->wait);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(i2c->regs))
return PTR_ERR(i2c->regs);
bus_nr = of_alias_get_id(np, "i2c");
if (i2c->soc_data->grf_offset >= 0) {
struct regmap *grf;
grf = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(grf)) {
dev_err(&pdev->dev,
"rk3x-i2c needs 'rockchip,grf' property\n");
return PTR_ERR(grf);
}
if (bus_nr < 0) {
dev_err(&pdev->dev, "rk3x-i2c needs i2cX alias");
return -EINVAL;
}
value = BIT(27 + bus_nr) | BIT(11 + bus_nr);
ret = regmap_write(grf, i2c->soc_data->grf_offset, value);
if (ret != 0) {
dev_err(i2c->dev, "Could not write to GRF: %d\n", ret);
return ret;
}
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "cannot find rk3x IRQ\n");
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, rk3x_i2c_irq,
0, dev_name(&pdev->dev), i2c);
if (ret < 0) {
dev_err(&pdev->dev, "cannot request IRQ\n");
return ret;
}
platform_set_drvdata(pdev, i2c);
if (i2c->soc_data->calc_timings == rk3x_i2c_v0_calc_timings) {
i2c->clk = devm_clk_get(&pdev->dev, NULL);
i2c->pclk = i2c->clk;
} else {
i2c->clk = devm_clk_get(&pdev->dev, "i2c");
i2c->pclk = devm_clk_get(&pdev->dev, "pclk");
}
if (IS_ERR(i2c->clk)) {
ret = PTR_ERR(i2c->clk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Can't get bus clk: %d\n", ret);
return ret;
}
if (IS_ERR(i2c->pclk)) {
ret = PTR_ERR(i2c->pclk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Can't get periph clk: %d\n", ret);
return ret;
}
ret = clk_prepare(i2c->clk);
if (ret < 0) {
dev_err(&pdev->dev, "Can't prepare bus clk: %d\n", ret);
return ret;
}
ret = clk_prepare(i2c->pclk);
if (ret < 0) {
dev_err(&pdev->dev, "Can't prepare periph clock: %d\n", ret);
goto err_clk;
}
i2c->clk_rate_nb.notifier_call = rk3x_i2c_clk_notifier_cb;
ret = clk_notifier_register(i2c->clk, &i2c->clk_rate_nb);
if (ret != 0) {
dev_err(&pdev->dev, "Unable to register clock notifier\n");
goto err_pclk;
}
clk_rate = clk_get_rate(i2c->clk);
rk3x_i2c_adapt_div(i2c, clk_rate);
ret = i2c_add_adapter(&i2c->adap);
if (ret < 0)
goto err_clk_notifier;
dev_info(&pdev->dev, "Initialized RK3xxx I2C bus at %p\n", i2c->regs);
return 0;
err_clk_notifier:
clk_notifier_unregister(i2c->clk, &i2c->clk_rate_nb);
err_pclk:
clk_unprepare(i2c->pclk);
err_clk:
clk_unprepare(i2c->clk);
return ret;
}
static int rk3x_i2c_remove(struct platform_device *pdev)
{
struct rk3x_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
clk_notifier_unregister(i2c->clk, &i2c->clk_rate_nb);
clk_unprepare(i2c->pclk);
clk_unprepare(i2c->clk);
return 0;
}
