static void meson_i2c_set_mask(struct meson_i2c *i2c, int reg, u32 mask,
u32 val)
{
u32 data;
data = readl(i2c->regs + reg);
data &= ~mask;
data |= val & mask;
writel(data, i2c->regs + reg);
}
static void meson_i2c_reset_tokens(struct meson_i2c *i2c)
{
i2c->tokens[0] = 0;
i2c->tokens[1] = 0;
i2c->num_tokens = 0;
}
static void meson_i2c_add_token(struct meson_i2c *i2c, int token)
{
if (i2c->num_tokens < 8)
i2c->tokens[0] |= (token & 0xf) << (i2c->num_tokens * 4);
else
i2c->tokens[1] |= (token & 0xf) << ((i2c->num_tokens % 8) * 4);
i2c->num_tokens++;
}
static void meson_i2c_set_clk_div(struct meson_i2c *i2c, unsigned int freq)
{
unsigned long clk_rate = clk_get_rate(i2c->clk);
unsigned int div;
div = DIV_ROUND_UP(clk_rate, freq * 4);
if (div >= (1 << 12)) {
dev_err(i2c->dev, "requested bus frequency too low\n");
div = (1 << 12) - 1;
}
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_CLKDIV_MASK,
(div & GENMASK(9, 0)) << REG_CTRL_CLKDIV_SHIFT);
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_CLKDIVEXT_MASK,
(div >> 10) << REG_CTRL_CLKDIVEXT_SHIFT);
dev_dbg(i2c->dev, "%s: clk %lu, freq %u, div %u\n", __func__,
clk_rate, freq, div);
}
static void meson_i2c_get_data(struct meson_i2c *i2c, char *buf, int len)
{
u32 rdata0, rdata1;
int i;
rdata0 = readl(i2c->regs + REG_TOK_RDATA0);
rdata1 = readl(i2c->regs + REG_TOK_RDATA1);
dev_dbg(i2c->dev, "%s: data %08x %08x len %d\n", __func__,
rdata0, rdata1, len);
for (i = 0; i < min(4, len); i++)
*buf++ = (rdata0 >> i * 8) & 0xff;
for (i = 4; i < min(8, len); i++)
*buf++ = (rdata1 >> (i - 4) * 8) & 0xff;
}
static void meson_i2c_put_data(struct meson_i2c *i2c, char *buf, int len)
{
u32 wdata0 = 0, wdata1 = 0;
int i;
for (i = 0; i < min(4, len); i++)
wdata0 |= *buf++ << (i * 8);
for (i = 4; i < min(8, len); i++)
wdata1 |= *buf++ << ((i - 4) * 8);
writel(wdata0, i2c->regs + REG_TOK_WDATA0);
writel(wdata1, i2c->regs + REG_TOK_WDATA1);
dev_dbg(i2c->dev, "%s: data %08x %08x len %d\n", __func__,
wdata0, wdata1, len);
}
static void meson_i2c_prepare_xfer(struct meson_i2c *i2c)
{
bool write = !(i2c->msg->flags & I2C_M_RD);
int i;
i2c->count = min(i2c->msg->len - i2c->pos, 8);
for (i = 0; i < i2c->count - 1; i++)
meson_i2c_add_token(i2c, TOKEN_DATA);
if (i2c->count) {
if (write || i2c->pos + i2c->count < i2c->msg->len)
meson_i2c_add_token(i2c, TOKEN_DATA);
else
meson_i2c_add_token(i2c, TOKEN_DATA_LAST);
}
if (write)
meson_i2c_put_data(i2c, i2c->msg->buf + i2c->pos, i2c->count);
if (i2c->last && i2c->pos + i2c->count >= i2c->msg->len)
meson_i2c_add_token(i2c, TOKEN_STOP);
writel(i2c->tokens[0], i2c->regs + REG_TOK_LIST0);
writel(i2c->tokens[1], i2c->regs + REG_TOK_LIST1);
}
static irqreturn_t meson_i2c_irq(int irqno, void *dev_id)
{
struct meson_i2c *i2c = dev_id;
unsigned int ctrl;
spin_lock(&i2c->lock);
meson_i2c_reset_tokens(i2c);
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_START, 0);
ctrl = readl(i2c->regs + REG_CTRL);
dev_dbg(i2c->dev, "irq: state %d, pos %d, count %d, ctrl %08x\n",
i2c->state, i2c->pos, i2c->count, ctrl);
if (i2c->state == STATE_IDLE) {
spin_unlock(&i2c->lock);
return IRQ_NONE;
}
if (ctrl & REG_CTRL_ERROR) {
dev_dbg(i2c->dev, "error bit set\n");
i2c->error = -ENXIO;
i2c->state = STATE_IDLE;
complete(&i2c->done);
goto out;
}
if (i2c->state == STATE_READ && i2c->count)
meson_i2c_get_data(i2c, i2c->msg->buf + i2c->pos, i2c->count);
i2c->pos += i2c->count;
if (i2c->pos >= i2c->msg->len) {
i2c->state = STATE_IDLE;
complete(&i2c->done);
goto out;
}
meson_i2c_prepare_xfer(i2c);
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_START, REG_CTRL_START);
out:
spin_unlock(&i2c->lock);
return IRQ_HANDLED;
}
static void meson_i2c_do_start(struct meson_i2c *i2c, struct i2c_msg *msg)
{
int token;
token = (msg->flags & I2C_M_RD) ? TOKEN_SLAVE_ADDR_READ :
TOKEN_SLAVE_ADDR_WRITE;
writel(msg->addr << 1, i2c->regs + REG_SLAVE_ADDR);
meson_i2c_add_token(i2c, TOKEN_START);
meson_i2c_add_token(i2c, token);
}
static int meson_i2c_xfer_msg(struct meson_i2c *i2c, struct i2c_msg *msg,
int last)
{
unsigned long time_left, flags;
int ret = 0;
i2c->msg = msg;
i2c->last = last;
i2c->pos = 0;
i2c->count = 0;
i2c->error = 0;
meson_i2c_reset_tokens(i2c);
flags = (msg->flags & I2C_M_IGNORE_NAK) ? REG_CTRL_ACK_IGNORE : 0;
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_ACK_IGNORE, flags);
if (!(msg->flags & I2C_M_NOSTART))
meson_i2c_do_start(i2c, msg);
i2c->state = (msg->flags & I2C_M_RD) ? STATE_READ : STATE_WRITE;
meson_i2c_prepare_xfer(i2c);
reinit_completion(&i2c->done);
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_START, REG_CTRL_START);
time_left = msecs_to_jiffies(I2C_TIMEOUT_MS);
time_left = wait_for_completion_timeout(&i2c->done, time_left);
spin_lock_irqsave(&i2c->lock, flags);
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_START, 0);
if (!time_left) {
i2c->state = STATE_IDLE;
ret = -ETIMEDOUT;
}
if (i2c->error)
ret = i2c->error;
spin_unlock_irqrestore(&i2c->lock, flags);
return ret;
}
static int meson_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct meson_i2c *i2c = adap->algo_data;
int i, ret = 0;
clk_enable(i2c->clk);
for (i = 0; i < num; i++) {
ret = meson_i2c_xfer_msg(i2c, msgs + i, i == num - 1);
if (ret)
break;
}
clk_disable(i2c->clk);
return ret ?: i;
}
static u32 meson_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int meson_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct meson_i2c *i2c;
struct resource *mem;
struct i2c_timings timings;
int irq, ret = 0;
i2c = devm_kzalloc(&pdev->dev, sizeof(struct meson_i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
i2c_parse_fw_timings(&pdev->dev, &timings, true);
i2c->dev = &pdev->dev;
platform_set_drvdata(pdev, i2c);
spin_lock_init(&i2c->lock);
init_completion(&i2c->done);
i2c->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c->clk)) {
dev_err(&pdev->dev, "can't get device clock\n");
return PTR_ERR(i2c->clk);
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(i2c->regs))
return PTR_ERR(i2c->regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "can't find IRQ\n");
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, meson_i2c_irq, 0, NULL, i2c);
if (ret < 0) {
dev_err(&pdev->dev, "can't request IRQ\n");
return ret;
}
ret = clk_prepare(i2c->clk);
if (ret < 0) {
dev_err(&pdev->dev, "can't prepare clock\n");
return ret;
}
strlcpy(i2c->adap.name, "Meson I2C adapter",
sizeof(i2c->adap.name));
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &meson_i2c_algorithm;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = np;
i2c->adap.algo_data = i2c;
meson_i2c_set_mask(i2c, REG_CTRL, REG_CTRL_START, 0);
ret = i2c_add_adapter(&i2c->adap);
if (ret < 0) {
clk_unprepare(i2c->clk);
return ret;
}
meson_i2c_set_clk_div(i2c, timings.bus_freq_hz);
return 0;
}
static int meson_i2c_remove(struct platform_device *pdev)
{
struct meson_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
clk_unprepare(i2c->clk);
return 0;
}
