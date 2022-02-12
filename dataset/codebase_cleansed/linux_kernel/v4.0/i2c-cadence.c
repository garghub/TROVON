static void cdns_i2c_clear_bus_hold(struct cdns_i2c *id)
{
u32 reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
if (reg & CDNS_I2C_CR_HOLD)
cdns_i2c_writereg(reg & ~CDNS_I2C_CR_HOLD, CDNS_I2C_CR_OFFSET);
}
static irqreturn_t cdns_i2c_isr(int irq, void *ptr)
{
unsigned int isr_status, avail_bytes, updatetx;
unsigned int bytes_to_send;
struct cdns_i2c *id = ptr;
int done_flag = 0;
irqreturn_t status = IRQ_NONE;
isr_status = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
cdns_i2c_writereg(isr_status, CDNS_I2C_ISR_OFFSET);
if (isr_status & (CDNS_I2C_IXR_NACK | CDNS_I2C_IXR_ARB_LOST)) {
done_flag = 1;
status = IRQ_HANDLED;
}
updatetx = 0;
if (id->recv_count > id->curr_recv_count)
updatetx = 1;
if (id->p_recv_buf &&
((isr_status & CDNS_I2C_IXR_COMP) ||
(isr_status & CDNS_I2C_IXR_DATA))) {
while (cdns_i2c_readreg(CDNS_I2C_SR_OFFSET) &
CDNS_I2C_SR_RXDV) {
if ((id->recv_count < CDNS_I2C_FIFO_DEPTH) &&
!id->bus_hold_flag)
cdns_i2c_clear_bus_hold(id);
*(id->p_recv_buf)++ =
cdns_i2c_readreg(CDNS_I2C_DATA_OFFSET);
id->recv_count--;
id->curr_recv_count--;
if (updatetx &&
(id->curr_recv_count == CDNS_I2C_FIFO_DEPTH + 1))
break;
}
if (updatetx &&
(id->curr_recv_count == CDNS_I2C_FIFO_DEPTH + 1)) {
while (cdns_i2c_readreg(CDNS_I2C_XFER_SIZE_OFFSET) !=
(id->curr_recv_count - CDNS_I2C_FIFO_DEPTH))
;
if (((int)(id->recv_count) - CDNS_I2C_FIFO_DEPTH) >
CDNS_I2C_TRANSFER_SIZE) {
cdns_i2c_writereg(CDNS_I2C_TRANSFER_SIZE,
CDNS_I2C_XFER_SIZE_OFFSET);
id->curr_recv_count = CDNS_I2C_TRANSFER_SIZE +
CDNS_I2C_FIFO_DEPTH;
} else {
cdns_i2c_writereg(id->recv_count -
CDNS_I2C_FIFO_DEPTH,
CDNS_I2C_XFER_SIZE_OFFSET);
id->curr_recv_count = id->recv_count;
}
}
if ((isr_status & CDNS_I2C_IXR_COMP) && !id->recv_count) {
if (!id->bus_hold_flag)
cdns_i2c_clear_bus_hold(id);
done_flag = 1;
}
status = IRQ_HANDLED;
}
if ((isr_status & CDNS_I2C_IXR_COMP) && !id->p_recv_buf) {
if (id->send_count) {
avail_bytes = CDNS_I2C_FIFO_DEPTH -
cdns_i2c_readreg(CDNS_I2C_XFER_SIZE_OFFSET);
if (id->send_count > avail_bytes)
bytes_to_send = avail_bytes;
else
bytes_to_send = id->send_count;
while (bytes_to_send--) {
cdns_i2c_writereg(
(*(id->p_send_buf)++),
CDNS_I2C_DATA_OFFSET);
id->send_count--;
}
} else {
done_flag = 1;
}
if (!id->send_count && !id->bus_hold_flag)
cdns_i2c_clear_bus_hold(id);
status = IRQ_HANDLED;
}
id->err_status = isr_status & CDNS_I2C_IXR_ERR_INTR_MASK;
if (id->err_status)
status = IRQ_HANDLED;
if (done_flag)
complete(&id->xfer_done);
return status;
}
static void cdns_i2c_mrecv(struct cdns_i2c *id)
{
unsigned int ctrl_reg;
unsigned int isr_status;
id->p_recv_buf = id->p_msg->buf;
id->recv_count = id->p_msg->len;
ctrl_reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
ctrl_reg |= CDNS_I2C_CR_RW | CDNS_I2C_CR_CLR_FIFO;
if (id->p_msg->flags & I2C_M_RECV_LEN)
id->recv_count = I2C_SMBUS_BLOCK_MAX + 1;
id->curr_recv_count = id->recv_count;
if (id->recv_count > CDNS_I2C_FIFO_DEPTH)
ctrl_reg |= CDNS_I2C_CR_HOLD;
cdns_i2c_writereg(ctrl_reg, CDNS_I2C_CR_OFFSET);
isr_status = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
cdns_i2c_writereg(isr_status, CDNS_I2C_ISR_OFFSET);
if (id->recv_count > CDNS_I2C_TRANSFER_SIZE) {
cdns_i2c_writereg(CDNS_I2C_TRANSFER_SIZE,
CDNS_I2C_XFER_SIZE_OFFSET);
id->curr_recv_count = CDNS_I2C_TRANSFER_SIZE;
} else {
cdns_i2c_writereg(id->recv_count, CDNS_I2C_XFER_SIZE_OFFSET);
}
if (!id->bus_hold_flag &&
((id->p_msg->flags & I2C_M_RECV_LEN) != I2C_M_RECV_LEN) &&
(id->recv_count <= CDNS_I2C_FIFO_DEPTH))
cdns_i2c_clear_bus_hold(id);
cdns_i2c_writereg(id->p_msg->addr & CDNS_I2C_ADDR_MASK,
CDNS_I2C_ADDR_OFFSET);
cdns_i2c_writereg(CDNS_I2C_ENABLED_INTR_MASK, CDNS_I2C_IER_OFFSET);
}
static void cdns_i2c_msend(struct cdns_i2c *id)
{
unsigned int avail_bytes;
unsigned int bytes_to_send;
unsigned int ctrl_reg;
unsigned int isr_status;
id->p_recv_buf = NULL;
id->p_send_buf = id->p_msg->buf;
id->send_count = id->p_msg->len;
ctrl_reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
ctrl_reg &= ~CDNS_I2C_CR_RW;
ctrl_reg |= CDNS_I2C_CR_CLR_FIFO;
if (id->send_count > CDNS_I2C_FIFO_DEPTH)
ctrl_reg |= CDNS_I2C_CR_HOLD;
cdns_i2c_writereg(ctrl_reg, CDNS_I2C_CR_OFFSET);
isr_status = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
cdns_i2c_writereg(isr_status, CDNS_I2C_ISR_OFFSET);
avail_bytes = CDNS_I2C_FIFO_DEPTH -
cdns_i2c_readreg(CDNS_I2C_XFER_SIZE_OFFSET);
if (id->send_count > avail_bytes)
bytes_to_send = avail_bytes;
else
bytes_to_send = id->send_count;
while (bytes_to_send--) {
cdns_i2c_writereg((*(id->p_send_buf)++), CDNS_I2C_DATA_OFFSET);
id->send_count--;
}
if (!id->bus_hold_flag && !id->send_count)
cdns_i2c_clear_bus_hold(id);
cdns_i2c_writereg(id->p_msg->addr & CDNS_I2C_ADDR_MASK,
CDNS_I2C_ADDR_OFFSET);
cdns_i2c_writereg(CDNS_I2C_ENABLED_INTR_MASK, CDNS_I2C_IER_OFFSET);
}
static void cdns_i2c_master_reset(struct i2c_adapter *adap)
{
struct cdns_i2c *id = adap->algo_data;
u32 regval;
cdns_i2c_writereg(CDNS_I2C_IXR_ALL_INTR_MASK, CDNS_I2C_IDR_OFFSET);
regval = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
regval &= ~CDNS_I2C_CR_HOLD;
regval |= CDNS_I2C_CR_CLR_FIFO;
cdns_i2c_writereg(regval, CDNS_I2C_CR_OFFSET);
cdns_i2c_writereg(0, CDNS_I2C_XFER_SIZE_OFFSET);
regval = cdns_i2c_readreg(CDNS_I2C_ISR_OFFSET);
cdns_i2c_writereg(regval, CDNS_I2C_ISR_OFFSET);
regval = cdns_i2c_readreg(CDNS_I2C_SR_OFFSET);
cdns_i2c_writereg(regval, CDNS_I2C_SR_OFFSET);
}
static int cdns_i2c_process_msg(struct cdns_i2c *id, struct i2c_msg *msg,
struct i2c_adapter *adap)
{
int ret;
u32 reg;
id->p_msg = msg;
id->err_status = 0;
reinit_completion(&id->xfer_done);
reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
if (msg->flags & I2C_M_TEN) {
if (reg & CDNS_I2C_CR_NEA)
cdns_i2c_writereg(reg & ~CDNS_I2C_CR_NEA,
CDNS_I2C_CR_OFFSET);
} else {
if (!(reg & CDNS_I2C_CR_NEA))
cdns_i2c_writereg(reg | CDNS_I2C_CR_NEA,
CDNS_I2C_CR_OFFSET);
}
if (msg->flags & I2C_M_RD)
cdns_i2c_mrecv(id);
else
cdns_i2c_msend(id);
ret = wait_for_completion_timeout(&id->xfer_done, adap->timeout);
if (!ret) {
cdns_i2c_master_reset(adap);
dev_err(id->adap.dev.parent,
"timeout waiting on completion\n");
return -ETIMEDOUT;
}
cdns_i2c_writereg(CDNS_I2C_IXR_ALL_INTR_MASK,
CDNS_I2C_IDR_OFFSET);
if (id->err_status & CDNS_I2C_IXR_ARB_LOST)
return -EAGAIN;
return 0;
}
static int cdns_i2c_master_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
int ret, count;
u32 reg;
struct cdns_i2c *id = adap->algo_data;
if (cdns_i2c_readreg(CDNS_I2C_SR_OFFSET) & CDNS_I2C_SR_BA)
return -EAGAIN;
if (num > 1) {
for (count = 0; count < num - 1; count++) {
if (msgs[count].flags & I2C_M_RD) {
dev_warn(adap->dev.parent,
"Can't do repeated start after a receive message\n");
return -EOPNOTSUPP;
}
}
id->bus_hold_flag = 1;
reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
reg |= CDNS_I2C_CR_HOLD;
cdns_i2c_writereg(reg, CDNS_I2C_CR_OFFSET);
} else {
id->bus_hold_flag = 0;
}
for (count = 0; count < num; count++, msgs++) {
if (count == (num - 1))
id->bus_hold_flag = 0;
ret = cdns_i2c_process_msg(id, msgs, adap);
if (ret)
return ret;
if (id->err_status) {
cdns_i2c_master_reset(adap);
if (id->err_status & CDNS_I2C_IXR_NACK)
return -ENXIO;
return -EIO;
}
}
return num;
}
static u32 cdns_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR |
(I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK) |
I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int cdns_i2c_calc_divs(unsigned long *f, unsigned long input_clk,
unsigned int *a, unsigned int *b)
{
unsigned long fscl = *f, best_fscl = *f, actual_fscl, temp;
unsigned int div_a, div_b, calc_div_a = 0, calc_div_b = 0;
unsigned int last_error, current_error;
temp = input_clk / (22 * fscl);
if (!temp || (temp > (CDNS_I2C_DIVA_MAX * CDNS_I2C_DIVB_MAX)))
return -EINVAL;
last_error = -1;
for (div_a = 0; div_a < CDNS_I2C_DIVA_MAX; div_a++) {
div_b = DIV_ROUND_UP(input_clk, 22 * fscl * (div_a + 1));
if ((div_b < 1) || (div_b > CDNS_I2C_DIVB_MAX))
continue;
div_b--;
actual_fscl = input_clk / (22 * (div_a + 1) * (div_b + 1));
if (actual_fscl > fscl)
continue;
current_error = ((actual_fscl > fscl) ? (actual_fscl - fscl) :
(fscl - actual_fscl));
if (last_error > current_error) {
calc_div_a = div_a;
calc_div_b = div_b;
best_fscl = actual_fscl;
last_error = current_error;
}
}
*a = calc_div_a;
*b = calc_div_b;
*f = best_fscl;
return 0;
}
static int cdns_i2c_setclk(unsigned long clk_in, struct cdns_i2c *id)
{
unsigned int div_a, div_b;
unsigned int ctrl_reg;
int ret = 0;
unsigned long fscl = id->i2c_clk;
ret = cdns_i2c_calc_divs(&fscl, clk_in, &div_a, &div_b);
if (ret)
return ret;
ctrl_reg = cdns_i2c_readreg(CDNS_I2C_CR_OFFSET);
ctrl_reg &= ~(CDNS_I2C_CR_DIVA_MASK | CDNS_I2C_CR_DIVB_MASK);
ctrl_reg |= ((div_a << CDNS_I2C_CR_DIVA_SHIFT) |
(div_b << CDNS_I2C_CR_DIVB_SHIFT));
cdns_i2c_writereg(ctrl_reg, CDNS_I2C_CR_OFFSET);
return 0;
}
static int cdns_i2c_clk_notifier_cb(struct notifier_block *nb, unsigned long
event, void *data)
{
struct clk_notifier_data *ndata = data;
struct cdns_i2c *id = to_cdns_i2c(nb);
if (id->suspended)
return NOTIFY_OK;
switch (event) {
case PRE_RATE_CHANGE:
{
unsigned long input_clk = ndata->new_rate;
unsigned long fscl = id->i2c_clk;
unsigned int div_a, div_b;
int ret;
ret = cdns_i2c_calc_divs(&fscl, input_clk, &div_a, &div_b);
if (ret) {
dev_warn(id->adap.dev.parent,
"clock rate change rejected\n");
return NOTIFY_STOP;
}
if (ndata->new_rate > ndata->old_rate)
cdns_i2c_setclk(ndata->new_rate, id);
return NOTIFY_OK;
}
case POST_RATE_CHANGE:
id->input_clk = ndata->new_rate;
if (ndata->new_rate < ndata->old_rate)
cdns_i2c_setclk(ndata->new_rate, id);
return NOTIFY_OK;
case ABORT_RATE_CHANGE:
if (ndata->new_rate > ndata->old_rate)
cdns_i2c_setclk(ndata->old_rate, id);
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static int __maybe_unused cdns_i2c_suspend(struct device *_dev)
{
struct platform_device *pdev = container_of(_dev,
struct platform_device, dev);
struct cdns_i2c *xi2c = platform_get_drvdata(pdev);
clk_disable(xi2c->clk);
xi2c->suspended = 1;
return 0;
}
static int __maybe_unused cdns_i2c_resume(struct device *_dev)
{
struct platform_device *pdev = container_of(_dev,
struct platform_device, dev);
struct cdns_i2c *xi2c = platform_get_drvdata(pdev);
int ret;
ret = clk_enable(xi2c->clk);
if (ret) {
dev_err(_dev, "Cannot enable clock.\n");
return ret;
}
xi2c->suspended = 0;
return 0;
}
static int cdns_i2c_probe(struct platform_device *pdev)
{
struct resource *r_mem;
struct cdns_i2c *id;
int ret;
id = devm_kzalloc(&pdev->dev, sizeof(*id), GFP_KERNEL);
if (!id)
return -ENOMEM;
platform_set_drvdata(pdev, id);
r_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
id->membase = devm_ioremap_resource(&pdev->dev, r_mem);
if (IS_ERR(id->membase))
return PTR_ERR(id->membase);
id->irq = platform_get_irq(pdev, 0);
id->adap.dev.of_node = pdev->dev.of_node;
id->adap.algo = &cdns_i2c_algo;
id->adap.timeout = CDNS_I2C_TIMEOUT;
id->adap.retries = 3;
id->adap.algo_data = id;
id->adap.dev.parent = &pdev->dev;
init_completion(&id->xfer_done);
snprintf(id->adap.name, sizeof(id->adap.name),
"Cadence I2C at %08lx", (unsigned long)r_mem->start);
id->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(id->clk)) {
dev_err(&pdev->dev, "input clock not found.\n");
return PTR_ERR(id->clk);
}
ret = clk_prepare_enable(id->clk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable clock.\n");
return ret;
}
id->clk_rate_change_nb.notifier_call = cdns_i2c_clk_notifier_cb;
if (clk_notifier_register(id->clk, &id->clk_rate_change_nb))
dev_warn(&pdev->dev, "Unable to register clock notifier.\n");
id->input_clk = clk_get_rate(id->clk);
ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&id->i2c_clk);
if (ret || (id->i2c_clk > CDNS_I2C_SPEED_MAX))
id->i2c_clk = CDNS_I2C_SPEED_DEFAULT;
cdns_i2c_writereg(CDNS_I2C_CR_ACK_EN | CDNS_I2C_CR_NEA | CDNS_I2C_CR_MS,
CDNS_I2C_CR_OFFSET);
ret = cdns_i2c_setclk(id->input_clk, id);
if (ret) {
dev_err(&pdev->dev, "invalid SCL clock: %u Hz\n", id->i2c_clk);
ret = -EINVAL;
goto err_clk_dis;
}
ret = devm_request_irq(&pdev->dev, id->irq, cdns_i2c_isr, 0,
DRIVER_NAME, id);
if (ret) {
dev_err(&pdev->dev, "cannot get irq %d\n", id->irq);
goto err_clk_dis;
}
ret = i2c_add_adapter(&id->adap);
if (ret < 0) {
dev_err(&pdev->dev, "reg adap failed: %d\n", ret);
goto err_clk_dis;
}
cdns_i2c_writereg(CDNS_I2C_TIMEOUT_MAX, CDNS_I2C_TIME_OUT_OFFSET);
dev_info(&pdev->dev, "%u kHz mmio %08lx irq %d\n",
id->i2c_clk / 1000, (unsigned long)r_mem->start, id->irq);
return 0;
err_clk_dis:
clk_disable_unprepare(id->clk);
return ret;
}
static int cdns_i2c_remove(struct platform_device *pdev)
{
struct cdns_i2c *id = platform_get_drvdata(pdev);
i2c_del_adapter(&id->adap);
clk_notifier_unregister(id->clk, &id->clk_rate_change_nb);
clk_disable_unprepare(id->clk);
return 0;
}
