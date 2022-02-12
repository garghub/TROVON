static inline void stm32f7_i2c_set_bits(void __iomem *reg, u32 mask)
{
writel_relaxed(readl_relaxed(reg) | mask, reg);
}
static inline void stm32f7_i2c_clr_bits(void __iomem *reg, u32 mask)
{
writel_relaxed(readl_relaxed(reg) & ~mask, reg);
}
static int stm32f7_i2c_compute_timing(struct stm32f7_i2c_dev *i2c_dev,
struct stm32f7_i2c_setup *setup,
struct stm32f7_i2c_timings *output)
{
u32 p_prev = STM32F7_PRESC_MAX;
u32 i2cclk = DIV_ROUND_CLOSEST(NSEC_PER_SEC,
setup->clock_src);
u32 i2cbus = DIV_ROUND_CLOSEST(NSEC_PER_SEC,
setup->speed_freq);
u32 clk_error_prev = i2cbus;
u32 tsync;
u32 af_delay_min, af_delay_max;
u32 dnf_delay;
u32 clk_min, clk_max;
int sdadel_min, sdadel_max;
int scldel_min;
struct stm32f7_i2c_timings *v, *_v, *s;
struct list_head solutions;
u16 p, l, a, h;
int ret = 0;
if (setup->speed >= STM32_I2C_SPEED_END) {
dev_err(i2c_dev->dev, "speed out of bound {%d/%d}\n",
setup->speed, STM32_I2C_SPEED_END - 1);
return -EINVAL;
}
if ((setup->rise_time > i2c_specs[setup->speed].rise_max) ||
(setup->fall_time > i2c_specs[setup->speed].fall_max)) {
dev_err(i2c_dev->dev,
"timings out of bound Rise{%d>%d}/Fall{%d>%d}\n",
setup->rise_time, i2c_specs[setup->speed].rise_max,
setup->fall_time, i2c_specs[setup->speed].fall_max);
return -EINVAL;
}
if (setup->dnf > STM32F7_I2C_DNF_MAX) {
dev_err(i2c_dev->dev,
"DNF out of bound %d/%d\n",
setup->dnf, STM32F7_I2C_DNF_MAX);
return -EINVAL;
}
if (setup->speed_freq > i2c_specs[setup->speed].rate) {
dev_err(i2c_dev->dev, "ERROR: Freq {%d/%d}\n",
setup->speed_freq, i2c_specs[setup->speed].rate);
return -EINVAL;
}
af_delay_min =
(setup->analog_filter ?
STM32F7_I2C_ANALOG_FILTER_DELAY_MIN : 0);
af_delay_max =
(setup->analog_filter ?
STM32F7_I2C_ANALOG_FILTER_DELAY_MAX : 0);
dnf_delay = setup->dnf * i2cclk;
sdadel_min = setup->fall_time - i2c_specs[setup->speed].hddat_min -
af_delay_min - (setup->dnf + 3) * i2cclk;
sdadel_max = i2c_specs[setup->speed].vddat_max - setup->rise_time -
af_delay_max - (setup->dnf + 4) * i2cclk;
scldel_min = setup->rise_time + i2c_specs[setup->speed].sudat_min;
if (sdadel_min < 0)
sdadel_min = 0;
if (sdadel_max < 0)
sdadel_max = 0;
dev_dbg(i2c_dev->dev, "SDADEL(min/max): %i/%i, SCLDEL(Min): %i\n",
sdadel_min, sdadel_max, scldel_min);
INIT_LIST_HEAD(&solutions);
for (p = 0; p < STM32F7_PRESC_MAX; p++) {
for (l = 0; l < STM32F7_SCLDEL_MAX; l++) {
u32 scldel = (l + 1) * (p + 1) * i2cclk;
if (scldel < scldel_min)
continue;
for (a = 0; a < STM32F7_SDADEL_MAX; a++) {
u32 sdadel = (a * (p + 1) + 1) * i2cclk;
if (((sdadel >= sdadel_min) &&
(sdadel <= sdadel_max)) &&
(p != p_prev)) {
v = kmalloc(sizeof(*v), GFP_KERNEL);
if (!v) {
ret = -ENOMEM;
goto exit;
}
v->presc = p;
v->scldel = l;
v->sdadel = a;
p_prev = p;
list_add_tail(&v->node,
&solutions);
}
}
}
}
if (list_empty(&solutions)) {
dev_err(i2c_dev->dev, "no Prescaler solution\n");
ret = -EPERM;
goto exit;
}
tsync = af_delay_min + dnf_delay + (2 * i2cclk);
s = NULL;
clk_max = NSEC_PER_SEC / i2c_specs[setup->speed].rate_min;
clk_min = NSEC_PER_SEC / i2c_specs[setup->speed].rate_max;
list_for_each_entry(v, &solutions, node) {
u32 prescaler = (v->presc + 1) * i2cclk;
for (l = 0; l < STM32F7_SCLL_MAX; l++) {
u32 tscl_l = (l + 1) * prescaler + tsync;
if ((tscl_l < i2c_specs[setup->speed].l_min) ||
(i2cclk >=
((tscl_l - af_delay_min - dnf_delay) / 4))) {
continue;
}
for (h = 0; h < STM32F7_SCLH_MAX; h++) {
u32 tscl_h = (h + 1) * prescaler + tsync;
u32 tscl = tscl_l + tscl_h +
setup->rise_time + setup->fall_time;
if ((tscl >= clk_min) && (tscl <= clk_max) &&
(tscl_h >= i2c_specs[setup->speed].h_min) &&
(i2cclk < tscl_h)) {
int clk_error = tscl - i2cbus;
if (clk_error < 0)
clk_error = -clk_error;
if (clk_error < clk_error_prev) {
clk_error_prev = clk_error;
v->scll = l;
v->sclh = h;
s = v;
}
}
}
}
}
if (!s) {
dev_err(i2c_dev->dev, "no solution at all\n");
ret = -EPERM;
goto exit;
}
output->presc = s->presc;
output->scldel = s->scldel;
output->sdadel = s->sdadel;
output->scll = s->scll;
output->sclh = s->sclh;
dev_dbg(i2c_dev->dev,
"Presc: %i, scldel: %i, sdadel: %i, scll: %i, sclh: %i\n",
output->presc,
output->scldel, output->sdadel,
output->scll, output->sclh);
exit:
list_for_each_entry_safe(v, _v, &solutions, node) {
list_del(&v->node);
kfree(v);
}
return ret;
}
static int stm32f7_i2c_setup_timing(struct stm32f7_i2c_dev *i2c_dev,
struct stm32f7_i2c_setup *setup)
{
int ret = 0;
setup->speed = i2c_dev->speed;
setup->speed_freq = i2c_specs[setup->speed].rate;
setup->clock_src = clk_get_rate(i2c_dev->clk);
if (!setup->clock_src) {
dev_err(i2c_dev->dev, "clock rate is 0\n");
return -EINVAL;
}
do {
ret = stm32f7_i2c_compute_timing(i2c_dev, setup,
&i2c_dev->timing);
if (ret) {
dev_err(i2c_dev->dev,
"failed to compute I2C timings.\n");
if (i2c_dev->speed > STM32_I2C_SPEED_STANDARD) {
i2c_dev->speed--;
setup->speed = i2c_dev->speed;
setup->speed_freq =
i2c_specs[setup->speed].rate;
dev_warn(i2c_dev->dev,
"downgrade I2C Speed Freq to (%i)\n",
i2c_specs[setup->speed].rate);
} else {
break;
}
}
} while (ret);
if (ret) {
dev_err(i2c_dev->dev, "Impossible to compute I2C timings.\n");
return ret;
}
dev_dbg(i2c_dev->dev, "I2C Speed(%i), Freq(%i), Clk Source(%i)\n",
setup->speed, setup->speed_freq, setup->clock_src);
dev_dbg(i2c_dev->dev, "I2C Rise(%i) and Fall(%i) Time\n",
setup->rise_time, setup->fall_time);
dev_dbg(i2c_dev->dev, "I2C Analog Filter(%s), DNF(%i)\n",
(setup->analog_filter ? "On" : "Off"), setup->dnf);
return 0;
}
static void stm32f7_i2c_hw_config(struct stm32f7_i2c_dev *i2c_dev)
{
struct stm32f7_i2c_timings *t = &i2c_dev->timing;
u32 timing = 0;
timing |= STM32F7_I2C_TIMINGR_PRESC(t->presc);
timing |= STM32F7_I2C_TIMINGR_SCLDEL(t->scldel);
timing |= STM32F7_I2C_TIMINGR_SDADEL(t->sdadel);
timing |= STM32F7_I2C_TIMINGR_SCLH(t->sclh);
timing |= STM32F7_I2C_TIMINGR_SCLL(t->scll);
writel_relaxed(timing, i2c_dev->base + STM32F7_I2C_TIMINGR);
if (i2c_dev->setup.analog_filter)
stm32f7_i2c_clr_bits(i2c_dev->base + STM32F7_I2C_CR1,
STM32F7_I2C_CR1_ANFOFF);
else
stm32f7_i2c_set_bits(i2c_dev->base + STM32F7_I2C_CR1,
STM32F7_I2C_CR1_ANFOFF);
stm32f7_i2c_set_bits(i2c_dev->base + STM32F7_I2C_CR1,
STM32F7_I2C_CR1_PE);
}
static void stm32f7_i2c_write_tx_data(struct stm32f7_i2c_dev *i2c_dev)
{
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
void __iomem *base = i2c_dev->base;
if (f7_msg->count) {
writeb_relaxed(*f7_msg->buf++, base + STM32F7_I2C_TXDR);
f7_msg->count--;
}
}
static void stm32f7_i2c_read_rx_data(struct stm32f7_i2c_dev *i2c_dev)
{
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
void __iomem *base = i2c_dev->base;
if (f7_msg->count) {
*f7_msg->buf++ = readb_relaxed(base + STM32F7_I2C_RXDR);
f7_msg->count--;
}
}
static void stm32f7_i2c_reload(struct stm32f7_i2c_dev *i2c_dev)
{
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
u32 cr2;
cr2 = readl_relaxed(i2c_dev->base + STM32F7_I2C_CR2);
cr2 &= ~STM32F7_I2C_CR2_NBYTES_MASK;
if (f7_msg->count > STM32F7_I2C_MAX_LEN) {
cr2 |= STM32F7_I2C_CR2_NBYTES(STM32F7_I2C_MAX_LEN);
} else {
cr2 &= ~STM32F7_I2C_CR2_RELOAD;
cr2 |= STM32F7_I2C_CR2_NBYTES(f7_msg->count);
}
writel_relaxed(cr2, i2c_dev->base + STM32F7_I2C_CR2);
}
static int stm32f7_i2c_wait_free_bus(struct stm32f7_i2c_dev *i2c_dev)
{
u32 status;
int ret;
ret = readl_relaxed_poll_timeout(i2c_dev->base + STM32F7_I2C_ISR,
status,
!(status & STM32F7_I2C_ISR_BUSY),
10, 1000);
if (ret) {
dev_dbg(i2c_dev->dev, "bus busy\n");
ret = -EBUSY;
}
return ret;
}
static void stm32f7_i2c_xfer_msg(struct stm32f7_i2c_dev *i2c_dev,
struct i2c_msg *msg)
{
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
void __iomem *base = i2c_dev->base;
u32 cr1, cr2;
f7_msg->addr = msg->addr;
f7_msg->buf = msg->buf;
f7_msg->count = msg->len;
f7_msg->result = 0;
f7_msg->stop = (i2c_dev->msg_id >= i2c_dev->msg_num - 1);
reinit_completion(&i2c_dev->complete);
cr1 = readl_relaxed(base + STM32F7_I2C_CR1);
cr2 = readl_relaxed(base + STM32F7_I2C_CR2);
cr2 &= ~STM32F7_I2C_CR2_RD_WRN;
if (msg->flags & I2C_M_RD)
cr2 |= STM32F7_I2C_CR2_RD_WRN;
cr2 &= ~STM32F7_I2C_CR2_SADD7_MASK;
cr2 |= STM32F7_I2C_CR2_SADD7(f7_msg->addr);
cr2 &= ~(STM32F7_I2C_CR2_NBYTES_MASK | STM32F7_I2C_CR2_RELOAD);
if (f7_msg->count > STM32F7_I2C_MAX_LEN) {
cr2 |= STM32F7_I2C_CR2_NBYTES(STM32F7_I2C_MAX_LEN);
cr2 |= STM32F7_I2C_CR2_RELOAD;
} else {
cr2 |= STM32F7_I2C_CR2_NBYTES(f7_msg->count);
}
cr1 |= STM32F7_I2C_CR1_ERRIE | STM32F7_I2C_CR1_TCIE |
STM32F7_I2C_CR1_STOPIE | STM32F7_I2C_CR1_NACKIE;
cr1 &= ~(STM32F7_I2C_CR1_RXIE | STM32F7_I2C_CR1_TXIE);
if (msg->flags & I2C_M_RD)
cr1 |= STM32F7_I2C_CR1_RXIE;
else
cr1 |= STM32F7_I2C_CR1_TXIE;
cr2 |= STM32F7_I2C_CR2_START;
writel_relaxed(cr1, base + STM32F7_I2C_CR1);
writel_relaxed(cr2, base + STM32F7_I2C_CR2);
}
static void stm32f7_i2c_disable_irq(struct stm32f7_i2c_dev *i2c_dev, u32 mask)
{
stm32f7_i2c_clr_bits(i2c_dev->base + STM32F7_I2C_CR1, mask);
}
static irqreturn_t stm32f7_i2c_isr_event(int irq, void *data)
{
struct stm32f7_i2c_dev *i2c_dev = data;
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
void __iomem *base = i2c_dev->base;
u32 status, mask;
status = readl_relaxed(i2c_dev->base + STM32F7_I2C_ISR);
if (status & STM32F7_I2C_ISR_TXIS)
stm32f7_i2c_write_tx_data(i2c_dev);
if (status & STM32F7_I2C_ISR_RXNE)
stm32f7_i2c_read_rx_data(i2c_dev);
if (status & STM32F7_I2C_ISR_NACKF) {
dev_dbg(i2c_dev->dev, "<%s>: Receive NACK\n", __func__);
writel_relaxed(STM32F7_I2C_ICR_NACKCF, base + STM32F7_I2C_ICR);
f7_msg->result = -ENXIO;
}
if (status & STM32F7_I2C_ISR_STOPF) {
stm32f7_i2c_disable_irq(i2c_dev, STM32F7_I2C_ALL_IRQ_MASK);
writel_relaxed(STM32F7_I2C_ICR_STOPCF, base + STM32F7_I2C_ICR);
complete(&i2c_dev->complete);
}
if (status & STM32F7_I2C_ISR_TC) {
if (f7_msg->stop) {
mask = STM32F7_I2C_CR2_STOP;
stm32f7_i2c_set_bits(base + STM32F7_I2C_CR2, mask);
} else {
i2c_dev->msg_id++;
i2c_dev->msg++;
stm32f7_i2c_xfer_msg(i2c_dev, i2c_dev->msg);
}
}
if (status & STM32F7_I2C_ISR_TCR)
stm32f7_i2c_reload(i2c_dev);
return IRQ_HANDLED;
}
static irqreturn_t stm32f7_i2c_isr_error(int irq, void *data)
{
struct stm32f7_i2c_dev *i2c_dev = data;
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
void __iomem *base = i2c_dev->base;
struct device *dev = i2c_dev->dev;
u32 status;
status = readl_relaxed(i2c_dev->base + STM32F7_I2C_ISR);
if (status & STM32F7_I2C_ISR_BERR) {
dev_err(dev, "<%s>: Bus error\n", __func__);
writel_relaxed(STM32F7_I2C_ICR_BERRCF, base + STM32F7_I2C_ICR);
f7_msg->result = -EIO;
}
if (status & STM32F7_I2C_ISR_ARLO) {
dev_dbg(dev, "<%s>: Arbitration loss\n", __func__);
writel_relaxed(STM32F7_I2C_ICR_ARLOCF, base + STM32F7_I2C_ICR);
f7_msg->result = -EAGAIN;
}
stm32f7_i2c_disable_irq(i2c_dev, STM32F7_I2C_ALL_IRQ_MASK);
complete(&i2c_dev->complete);
return IRQ_HANDLED;
}
static int stm32f7_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msgs[], int num)
{
struct stm32f7_i2c_dev *i2c_dev = i2c_get_adapdata(i2c_adap);
struct stm32f7_i2c_msg *f7_msg = &i2c_dev->f7_msg;
unsigned long time_left;
int ret;
i2c_dev->msg = msgs;
i2c_dev->msg_num = num;
i2c_dev->msg_id = 0;
ret = clk_enable(i2c_dev->clk);
if (ret) {
dev_err(i2c_dev->dev, "Failed to enable clock\n");
return ret;
}
ret = stm32f7_i2c_wait_free_bus(i2c_dev);
if (ret)
goto clk_free;
stm32f7_i2c_xfer_msg(i2c_dev, msgs);
time_left = wait_for_completion_timeout(&i2c_dev->complete,
i2c_dev->adap.timeout);
ret = f7_msg->result;
if (!time_left) {
dev_dbg(i2c_dev->dev, "Access to slave 0x%x timed out\n",
i2c_dev->msg->addr);
ret = -ETIMEDOUT;
}
clk_free:
clk_disable(i2c_dev->clk);
return (ret < 0) ? ret : num;
}
static u32 stm32f7_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int stm32f7_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct stm32f7_i2c_dev *i2c_dev;
const struct stm32f7_i2c_setup *setup;
struct resource *res;
u32 irq_error, irq_event, clk_rate, rise_time, fall_time;
struct i2c_adapter *adap;
struct reset_control *rst;
int ret;
i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
if (!i2c_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c_dev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c_dev->base))
return PTR_ERR(i2c_dev->base);
irq_event = irq_of_parse_and_map(np, 0);
if (!irq_event) {
dev_err(&pdev->dev, "IRQ event missing or invalid\n");
return -EINVAL;
}
irq_error = irq_of_parse_and_map(np, 1);
if (!irq_error) {
dev_err(&pdev->dev, "IRQ error missing or invalid\n");
return -EINVAL;
}
i2c_dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c_dev->clk)) {
dev_err(&pdev->dev, "Error: Missing controller clock\n");
return PTR_ERR(i2c_dev->clk);
}
ret = clk_prepare_enable(i2c_dev->clk);
if (ret) {
dev_err(&pdev->dev, "Failed to prepare_enable clock\n");
return ret;
}
i2c_dev->speed = STM32_I2C_SPEED_STANDARD;
ret = device_property_read_u32(&pdev->dev, "clock-frequency",
&clk_rate);
if (!ret && clk_rate >= 1000000)
i2c_dev->speed = STM32_I2C_SPEED_FAST_PLUS;
else if (!ret && clk_rate >= 400000)
i2c_dev->speed = STM32_I2C_SPEED_FAST;
else if (!ret && clk_rate >= 100000)
i2c_dev->speed = STM32_I2C_SPEED_STANDARD;
rst = devm_reset_control_get(&pdev->dev, NULL);
if (IS_ERR(rst)) {
dev_err(&pdev->dev, "Error: Missing controller reset\n");
ret = PTR_ERR(rst);
goto clk_free;
}
reset_control_assert(rst);
udelay(2);
reset_control_deassert(rst);
i2c_dev->dev = &pdev->dev;
ret = devm_request_irq(&pdev->dev, irq_event, stm32f7_i2c_isr_event, 0,
pdev->name, i2c_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq event %i\n",
irq_event);
goto clk_free;
}
ret = devm_request_irq(&pdev->dev, irq_error, stm32f7_i2c_isr_error, 0,
pdev->name, i2c_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq error %i\n",
irq_error);
goto clk_free;
}
setup = of_device_get_match_data(&pdev->dev);
i2c_dev->setup = *setup;
ret = device_property_read_u32(i2c_dev->dev, "i2c-scl-rising-time-ns",
&rise_time);
if (!ret)
i2c_dev->setup.rise_time = rise_time;
ret = device_property_read_u32(i2c_dev->dev, "i2c-scl-falling-time-ns",
&fall_time);
if (!ret)
i2c_dev->setup.fall_time = fall_time;
ret = stm32f7_i2c_setup_timing(i2c_dev, &i2c_dev->setup);
if (ret)
goto clk_free;
stm32f7_i2c_hw_config(i2c_dev);
adap = &i2c_dev->adap;
i2c_set_adapdata(adap, i2c_dev);
snprintf(adap->name, sizeof(adap->name), "STM32F7 I2C(%pa)",
&res->start);
adap->owner = THIS_MODULE;
adap->timeout = 2 * HZ;
adap->retries = 3;
adap->algo = &stm32f7_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
init_completion(&i2c_dev->complete);
ret = i2c_add_adapter(adap);
if (ret)
goto clk_free;
platform_set_drvdata(pdev, i2c_dev);
clk_disable(i2c_dev->clk);
dev_info(i2c_dev->dev, "STM32F7 I2C-%d bus adapter\n", adap->nr);
return 0;
clk_free:
clk_disable_unprepare(i2c_dev->clk);
return ret;
}
static int stm32f7_i2c_remove(struct platform_device *pdev)
{
struct stm32f7_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c_dev->adap);
clk_unprepare(i2c_dev->clk);
return 0;
}
