static void octeon_i2c_write_sw(struct octeon_i2c *i2c,
u64 eop_reg,
u8 data)
{
u64 tmp;
__raw_writeq(SW_TWSI_V | eop_reg | data, i2c->twsi_base + SW_TWSI);
do {
tmp = __raw_readq(i2c->twsi_base + SW_TWSI);
} while ((tmp & SW_TWSI_V) != 0);
}
static u8 octeon_i2c_read_sw(struct octeon_i2c *i2c, u64 eop_reg)
{
u64 tmp;
__raw_writeq(SW_TWSI_V | eop_reg | SW_TWSI_R, i2c->twsi_base + SW_TWSI);
do {
tmp = __raw_readq(i2c->twsi_base + SW_TWSI);
} while ((tmp & SW_TWSI_V) != 0);
return tmp & 0xFF;
}
static void octeon_i2c_write_int(struct octeon_i2c *i2c, u64 data)
{
__raw_writeq(data, i2c->twsi_base + TWSI_INT);
__raw_readq(i2c->twsi_base + TWSI_INT);
}
static void octeon_i2c_int_enable(struct octeon_i2c *i2c)
{
octeon_i2c_write_int(i2c, 0x40);
}
static void octeon_i2c_int_disable(struct octeon_i2c *i2c)
{
octeon_i2c_write_int(i2c, 0);
}
static void octeon_i2c_unblock(struct octeon_i2c *i2c)
{
int i;
dev_dbg(i2c->dev, "%s\n", __func__);
for (i = 0; i < 9; i++) {
octeon_i2c_write_int(i2c, 0x0);
udelay(5);
octeon_i2c_write_int(i2c, 0x200);
udelay(5);
}
octeon_i2c_write_int(i2c, 0x300);
udelay(5);
octeon_i2c_write_int(i2c, 0x100);
udelay(5);
octeon_i2c_write_int(i2c, 0x0);
}
static irqreturn_t octeon_i2c_isr(int irq, void *dev_id)
{
struct octeon_i2c *i2c = dev_id;
octeon_i2c_int_disable(i2c);
wake_up_interruptible(&i2c->queue);
return IRQ_HANDLED;
}
static int octeon_i2c_test_iflg(struct octeon_i2c *i2c)
{
return (octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_CTL) & TWSI_CTL_IFLG) != 0;
}
static int octeon_i2c_wait(struct octeon_i2c *i2c)
{
int result;
octeon_i2c_int_enable(i2c);
result = wait_event_interruptible_timeout(i2c->queue,
octeon_i2c_test_iflg(i2c),
i2c->adap.timeout);
octeon_i2c_int_disable(i2c);
if (result < 0) {
dev_dbg(i2c->dev, "%s: wait interrupted\n", __func__);
return result;
} else if (result == 0) {
dev_dbg(i2c->dev, "%s: timeout\n", __func__);
return -ETIMEDOUT;
}
return 0;
}
static int octeon_i2c_start(struct octeon_i2c *i2c)
{
u8 data;
int result;
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL,
TWSI_CTL_ENAB | TWSI_CTL_STA);
result = octeon_i2c_wait(i2c);
if (result) {
if (octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_STAT) == STAT_IDLE) {
octeon_i2c_unblock(i2c);
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL,
TWSI_CTL_ENAB | TWSI_CTL_STA);
result = octeon_i2c_wait(i2c);
}
if (result)
return result;
}
data = octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_STAT);
if ((data != STAT_START) && (data != STAT_RSTART)) {
dev_err(i2c->dev, "%s: bad status (0x%x)\n", __func__, data);
return -EIO;
}
return 0;
}
static int octeon_i2c_stop(struct octeon_i2c *i2c)
{
u8 data;
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL,
TWSI_CTL_ENAB | TWSI_CTL_STP);
data = octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_STAT);
if (data != STAT_IDLE) {
dev_err(i2c->dev, "%s: bad status(0x%x)\n", __func__, data);
return -EIO;
}
return 0;
}
static int octeon_i2c_write(struct octeon_i2c *i2c, int target,
const u8 *data, int length)
{
int i, result;
u8 tmp;
result = octeon_i2c_start(i2c);
if (result)
return result;
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_DATA, target << 1);
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL, TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
for (i = 0; i < length; i++) {
tmp = octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_STAT);
if ((tmp != STAT_TXADDR_ACK) && (tmp != STAT_TXDATA_ACK)) {
dev_err(i2c->dev,
"%s: bad status before write (0x%x)\n",
__func__, tmp);
return -EIO;
}
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_DATA, data[i]);
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL, TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
}
return 0;
}
static int octeon_i2c_read(struct octeon_i2c *i2c, int target,
u8 *data, int length)
{
int i, result;
u8 tmp;
if (length < 1)
return -EINVAL;
result = octeon_i2c_start(i2c);
if (result)
return result;
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_DATA, (target<<1) | 1);
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL, TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
for (i = 0; i < length; i++) {
tmp = octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_STAT);
if ((tmp != STAT_RXDATA_ACK) && (tmp != STAT_RXADDR_ACK)) {
dev_err(i2c->dev,
"%s: bad status before read (0x%x)\n",
__func__, tmp);
return -EIO;
}
if (i+1 < length)
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL,
TWSI_CTL_ENAB | TWSI_CTL_AAK);
else
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL,
TWSI_CTL_ENAB);
result = octeon_i2c_wait(i2c);
if (result)
return result;
data[i] = octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_DATA);
}
return 0;
}
static int octeon_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs,
int num)
{
struct i2c_msg *pmsg;
int i;
int ret = 0;
struct octeon_i2c *i2c = i2c_get_adapdata(adap);
for (i = 0; ret == 0 && i < num; i++) {
pmsg = &msgs[i];
dev_dbg(i2c->dev,
"Doing %s %d byte(s) to/from 0x%02x - %d of %d messages\n",
pmsg->flags & I2C_M_RD ? "read" : "write",
pmsg->len, pmsg->addr, i + 1, num);
if (pmsg->flags & I2C_M_RD)
ret = octeon_i2c_read(i2c, pmsg->addr, pmsg->buf,
pmsg->len);
else
ret = octeon_i2c_write(i2c, pmsg->addr, pmsg->buf,
pmsg->len);
}
octeon_i2c_stop(i2c);
return (ret != 0) ? ret : num;
}
static u32 octeon_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int octeon_i2c_setclock(struct octeon_i2c *i2c)
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
octeon_i2c_write_sw(i2c, SW_TWSI_OP_TWSI_CLK, thp);
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CLKCTL, (mdiv << 3) | ndiv);
return 0;
}
static int octeon_i2c_initlowlevel(struct octeon_i2c *i2c)
{
u8 status;
int tries;
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_CTL, TWSI_CTL_ENAB);
octeon_i2c_write_sw(i2c, SW_TWSI_EOP_TWSI_RST, 0);
for (tries = 10; tries; tries--) {
udelay(1);
status = octeon_i2c_read_sw(i2c, SW_TWSI_EOP_TWSI_STAT);
if (status == STAT_IDLE)
return 0;
}
dev_err(i2c->dev, "%s: TWSI_RST failed! (0x%x)\n", __func__, status);
return -EIO;
}
static int octeon_i2c_probe(struct platform_device *pdev)
{
int irq, result = 0;
struct octeon_i2c *i2c;
struct resource *res_mem;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c) {
dev_err(&pdev->dev, "kzalloc failed\n");
result = -ENOMEM;
goto out;
}
i2c->dev = &pdev->dev;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res_mem == NULL) {
dev_err(i2c->dev, "found no memory resource\n");
result = -ENXIO;
goto out;
}
i2c->twsi_phys = res_mem->start;
i2c->regsize = resource_size(res_mem);
if (of_property_read_u32(pdev->dev.of_node,
"clock-frequency", &i2c->twsi_freq) &&
of_property_read_u32(pdev->dev.of_node,
"clock-rate", &i2c->twsi_freq)) {
dev_err(i2c->dev,
"no I2C 'clock-rate' or 'clock-frequency' property\n");
result = -ENXIO;
goto out;
}
i2c->sys_freq = octeon_get_io_clock_rate();
if (!devm_request_mem_region(&pdev->dev, i2c->twsi_phys, i2c->regsize,
res_mem->name)) {
dev_err(i2c->dev, "request_mem_region failed\n");
goto out;
}
i2c->twsi_base = devm_ioremap(&pdev->dev, i2c->twsi_phys, i2c->regsize);
init_waitqueue_head(&i2c->queue);
i2c->irq = irq;
result = devm_request_irq(&pdev->dev, i2c->irq,
octeon_i2c_isr, 0, DRV_NAME, i2c);
if (result < 0) {
dev_err(i2c->dev, "failed to attach interrupt\n");
goto out;
}
result = octeon_i2c_initlowlevel(i2c);
if (result) {
dev_err(i2c->dev, "init low level failed\n");
goto out;
}
result = octeon_i2c_setclock(i2c);
if (result) {
dev_err(i2c->dev, "clock init failed\n");
goto out;
}
i2c->adap = octeon_i2c_ops;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = pdev->dev.of_node;
i2c_set_adapdata(&i2c->adap, i2c);
platform_set_drvdata(pdev, i2c);
result = i2c_add_adapter(&i2c->adap);
if (result < 0) {
dev_err(i2c->dev, "failed to add adapter\n");
goto out;
}
dev_info(i2c->dev, "version %s\n", DRV_VERSION);
of_i2c_register_devices(&i2c->adap);
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
