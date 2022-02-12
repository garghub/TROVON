static inline void writeccr(struct mpc_i2c *i2c, u32 x)
{
writeb(x, i2c->base + MPC_I2C_CR);
}
static irqreturn_t mpc_i2c_isr(int irq, void *dev_id)
{
struct mpc_i2c *i2c = dev_id;
if (readb(i2c->base + MPC_I2C_SR) & CSR_MIF) {
i2c->interrupt = readb(i2c->base + MPC_I2C_SR);
writeb(0, i2c->base + MPC_I2C_SR);
wake_up(&i2c->queue);
}
return IRQ_HANDLED;
}
static void mpc_i2c_fixup(struct mpc_i2c *i2c)
{
int k;
u32 delay_val = 1000000 / i2c->real_clk + 1;
if (delay_val < 2)
delay_val = 2;
for (k = 9; k; k--) {
writeccr(i2c, 0);
writeccr(i2c, CCR_MSTA | CCR_MTX | CCR_MEN);
udelay(delay_val);
writeccr(i2c, CCR_MEN);
udelay(delay_val << 1);
}
}
static int i2c_wait(struct mpc_i2c *i2c, unsigned timeout, int writing)
{
unsigned long orig_jiffies = jiffies;
u32 x;
int result = 0;
if (!i2c->irq) {
while (!(readb(i2c->base + MPC_I2C_SR) & CSR_MIF)) {
schedule();
if (time_after(jiffies, orig_jiffies + timeout)) {
dev_dbg(i2c->dev, "timeout\n");
writeccr(i2c, 0);
result = -EIO;
break;
}
}
x = readb(i2c->base + MPC_I2C_SR);
writeb(0, i2c->base + MPC_I2C_SR);
} else {
result = wait_event_timeout(i2c->queue,
(i2c->interrupt & CSR_MIF), timeout);
if (unlikely(!(i2c->interrupt & CSR_MIF))) {
dev_dbg(i2c->dev, "wait timeout\n");
writeccr(i2c, 0);
result = -ETIMEDOUT;
}
x = i2c->interrupt;
i2c->interrupt = 0;
}
if (result < 0)
return result;
if (!(x & CSR_MCF)) {
dev_dbg(i2c->dev, "unfinished\n");
return -EIO;
}
if (x & CSR_MAL) {
dev_dbg(i2c->dev, "MAL\n");
return -EIO;
}
if (writing && (x & CSR_RXAK)) {
dev_dbg(i2c->dev, "No RXAK\n");
writeccr(i2c, CCR_MEN);
return -EIO;
}
return 0;
}
static int mpc_i2c_get_fdr_52xx(struct device_node *node, u32 clock,
int prescaler, u32 *real_clk)
{
const struct mpc_i2c_divider *div = NULL;
unsigned int pvr = mfspr(SPRN_PVR);
u32 divider;
int i;
if (clock == MPC_I2C_CLOCK_LEGACY) {
*real_clk = mpc5xxx_get_bus_frequency(node) / 2048;
return -EINVAL;
}
divider = mpc5xxx_get_bus_frequency(node) / clock;
for (i = 0; i < ARRAY_SIZE(mpc_i2c_dividers_52xx); i++) {
div = &mpc_i2c_dividers_52xx[i];
if (div->fdr & 0xc0 && pvr == 0x80822011)
continue;
if (div->divider >= divider)
break;
}
*real_clk = mpc5xxx_get_bus_frequency(node) / div->divider;
return (int)div->fdr;
}
static void mpc_i2c_setup_52xx(struct device_node *node,
struct mpc_i2c *i2c,
u32 clock, u32 prescaler)
{
int ret, fdr;
if (clock == MPC_I2C_CLOCK_PRESERVE) {
dev_dbg(i2c->dev, "using fdr %d\n",
readb(i2c->base + MPC_I2C_FDR));
return;
}
ret = mpc_i2c_get_fdr_52xx(node, clock, prescaler, &i2c->real_clk);
fdr = (ret >= 0) ? ret : 0x3f;
writeb(fdr & 0xff, i2c->base + MPC_I2C_FDR);
if (ret >= 0)
dev_info(i2c->dev, "clock %u Hz (fdr=%d)\n", i2c->real_clk,
fdr);
}
static void mpc_i2c_setup_52xx(struct device_node *node,
struct mpc_i2c *i2c,
u32 clock, u32 prescaler)
{
}
static void mpc_i2c_setup_512x(struct device_node *node,
struct mpc_i2c *i2c,
u32 clock, u32 prescaler)
{
struct device_node *node_ctrl;
void __iomem *ctrl;
const u32 *pval;
u32 idx;
node_ctrl = of_find_compatible_node(NULL, NULL,
"fsl,mpc5121-i2c-ctrl");
if (node_ctrl) {
ctrl = of_iomap(node_ctrl, 0);
if (ctrl) {
pval = of_get_property(node, "reg", NULL);
idx = (*pval & 0xff) / 0x20;
setbits32(ctrl, 1 << (24 + idx * 2));
iounmap(ctrl);
}
of_node_put(node_ctrl);
}
mpc_i2c_setup_52xx(node, i2c, clock, prescaler);
}
static void mpc_i2c_setup_512x(struct device_node *node,
struct mpc_i2c *i2c,
u32 clock, u32 prescaler)
{
}
static u32 mpc_i2c_get_sec_cfg_8xxx(void)
{
struct device_node *node = NULL;
u32 __iomem *reg;
u32 val = 0;
node = of_find_node_by_name(NULL, "global-utilities");
if (node) {
const u32 *prop = of_get_property(node, "reg", NULL);
if (prop) {
reg = ioremap(get_immrbase() + *prop + 0x14, 0x4);
if (!reg)
printk(KERN_ERR
"Error: couldn't map PORDEVSR2\n");
else
val = in_be32(reg) & 0x00000080;
iounmap(reg);
}
}
if (node)
of_node_put(node);
return val;
}
static int mpc_i2c_get_fdr_8xxx(struct device_node *node, u32 clock,
u32 prescaler, u32 *real_clk)
{
const struct mpc_i2c_divider *div = NULL;
u32 divider;
int i;
if (clock == MPC_I2C_CLOCK_LEGACY) {
*real_clk = fsl_get_sys_freq() / prescaler / (16 * 3072);
return -EINVAL;
}
if (of_device_is_compatible(node, "fsl,mpc8544-i2c"))
prescaler = mpc_i2c_get_sec_cfg_8xxx() ? 3 : 2;
if (!prescaler)
prescaler = 1;
divider = fsl_get_sys_freq() / clock / prescaler;
pr_debug("I2C: src_clock=%d clock=%d divider=%d\n",
fsl_get_sys_freq(), clock, divider);
for (i = 0; i < ARRAY_SIZE(mpc_i2c_dividers_8xxx); i++) {
div = &mpc_i2c_dividers_8xxx[i];
if (div->divider >= divider)
break;
}
*real_clk = fsl_get_sys_freq() / prescaler / div->divider;
return div ? (int)div->fdr : -EINVAL;
}
static void mpc_i2c_setup_8xxx(struct device_node *node,
struct mpc_i2c *i2c,
u32 clock, u32 prescaler)
{
int ret, fdr;
if (clock == MPC_I2C_CLOCK_PRESERVE) {
dev_dbg(i2c->dev, "using dfsrr %d, fdr %d\n",
readb(i2c->base + MPC_I2C_DFSRR),
readb(i2c->base + MPC_I2C_FDR));
return;
}
ret = mpc_i2c_get_fdr_8xxx(node, clock, prescaler, &i2c->real_clk);
fdr = (ret >= 0) ? ret : 0x1031;
writeb(fdr & 0xff, i2c->base + MPC_I2C_FDR);
writeb((fdr >> 8) & 0xff, i2c->base + MPC_I2C_DFSRR);
if (ret >= 0)
dev_info(i2c->dev, "clock %d Hz (dfsrr=%d fdr=%d)\n",
i2c->real_clk, fdr >> 8, fdr & 0xff);
}
static void mpc_i2c_setup_8xxx(struct device_node *node,
struct mpc_i2c *i2c,
u32 clock, u32 prescaler)
{
}
static void mpc_i2c_start(struct mpc_i2c *i2c)
{
writeb(0, i2c->base + MPC_I2C_SR);
writeccr(i2c, CCR_MEN);
}
static void mpc_i2c_stop(struct mpc_i2c *i2c)
{
writeccr(i2c, CCR_MEN);
}
static int mpc_write(struct mpc_i2c *i2c, int target,
const u8 *data, int length, int restart)
{
int i, result;
unsigned timeout = i2c->adap.timeout;
u32 flags = restart ? CCR_RSTA : 0;
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_MTX | flags);
writeb((target << 1), i2c->base + MPC_I2C_DR);
result = i2c_wait(i2c, timeout, 1);
if (result < 0)
return result;
for (i = 0; i < length; i++) {
writeb(data[i], i2c->base + MPC_I2C_DR);
result = i2c_wait(i2c, timeout, 1);
if (result < 0)
return result;
}
return 0;
}
static int mpc_read(struct mpc_i2c *i2c, int target,
u8 *data, int length, int restart, bool recv_len)
{
unsigned timeout = i2c->adap.timeout;
int i, result;
u32 flags = restart ? CCR_RSTA : 0;
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_MTX | flags);
writeb((target << 1) | 1, i2c->base + MPC_I2C_DR);
result = i2c_wait(i2c, timeout, 1);
if (result < 0)
return result;
if (length) {
if (length == 1 && !recv_len)
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA | CCR_TXAK);
else
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA);
readb(i2c->base + MPC_I2C_DR);
}
for (i = 0; i < length; i++) {
u8 byte;
result = i2c_wait(i2c, timeout, 0);
if (result < 0)
return result;
if (i || !recv_len) {
if (i == length - 2)
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
| CCR_TXAK);
if (i == length - 1)
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
| CCR_MTX);
}
byte = readb(i2c->base + MPC_I2C_DR);
if (i == 0 && recv_len) {
if (byte == 0 || byte > I2C_SMBUS_BLOCK_MAX)
return -EPROTO;
length += byte;
if (length == 2)
writeccr(i2c, CCR_MIEN | CCR_MEN | CCR_MSTA
| CCR_TXAK);
}
data[i] = byte;
}
return length;
}
static int mpc_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct i2c_msg *pmsg;
int i;
int ret = 0;
unsigned long orig_jiffies = jiffies;
struct mpc_i2c *i2c = i2c_get_adapdata(adap);
mpc_i2c_start(i2c);
while (readb(i2c->base + MPC_I2C_SR) & CSR_MBB) {
if (signal_pending(current)) {
dev_dbg(i2c->dev, "Interrupted\n");
writeccr(i2c, 0);
return -EINTR;
}
if (time_after(jiffies, orig_jiffies + HZ)) {
u8 status = readb(i2c->base + MPC_I2C_SR);
dev_dbg(i2c->dev, "timeout\n");
if ((status & (CSR_MCF | CSR_MBB | CSR_RXAK)) != 0) {
writeb(status & ~CSR_MAL,
i2c->base + MPC_I2C_SR);
mpc_i2c_fixup(i2c);
}
return -EIO;
}
schedule();
}
for (i = 0; ret >= 0 && i < num; i++) {
pmsg = &msgs[i];
dev_dbg(i2c->dev,
"Doing %s %d bytes to 0x%02x - %d of %d messages\n",
pmsg->flags & I2C_M_RD ? "read" : "write",
pmsg->len, pmsg->addr, i + 1, num);
if (pmsg->flags & I2C_M_RD) {
bool recv_len = pmsg->flags & I2C_M_RECV_LEN;
ret = mpc_read(i2c, pmsg->addr, pmsg->buf, pmsg->len, i,
recv_len);
if (recv_len && ret > 0)
pmsg->len = ret;
} else {
ret =
mpc_write(i2c, pmsg->addr, pmsg->buf, pmsg->len, i);
}
}
mpc_i2c_stop(i2c);
orig_jiffies = jiffies;
while (readb(i2c->base + MPC_I2C_SR) & CSR_MBB) {
if (time_after(jiffies, orig_jiffies + HZ)) {
u8 status = readb(i2c->base + MPC_I2C_SR);
dev_dbg(i2c->dev, "timeout\n");
if ((status & (CSR_MCF | CSR_MBB | CSR_RXAK)) != 0) {
writeb(status & ~CSR_MAL,
i2c->base + MPC_I2C_SR);
mpc_i2c_fixup(i2c);
}
return -EIO;
}
cond_resched();
}
return (ret < 0) ? ret : num;
}
static u32 mpc_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL
| I2C_FUNC_SMBUS_READ_BLOCK_DATA | I2C_FUNC_SMBUS_BLOCK_PROC_CALL;
}
static int fsl_i2c_probe(struct platform_device *op)
{
const struct of_device_id *match;
struct mpc_i2c *i2c;
const u32 *prop;
u32 clock = MPC_I2C_CLOCK_LEGACY;
int result = 0;
int plen;
match = of_match_device(mpc_i2c_of_match, &op->dev);
if (!match)
return -EINVAL;
i2c = kzalloc(sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
i2c->dev = &op->dev;
init_waitqueue_head(&i2c->queue);
i2c->base = of_iomap(op->dev.of_node, 0);
if (!i2c->base) {
dev_err(i2c->dev, "failed to map controller\n");
result = -ENOMEM;
goto fail_map;
}
i2c->irq = irq_of_parse_and_map(op->dev.of_node, 0);
if (i2c->irq) {
result = request_irq(i2c->irq, mpc_i2c_isr,
IRQF_SHARED, "i2c-mpc", i2c);
if (result < 0) {
dev_err(i2c->dev, "failed to attach interrupt\n");
goto fail_request;
}
}
if (of_get_property(op->dev.of_node, "fsl,preserve-clocking", NULL)) {
clock = MPC_I2C_CLOCK_PRESERVE;
} else {
prop = of_get_property(op->dev.of_node, "clock-frequency",
&plen);
if (prop && plen == sizeof(u32))
clock = *prop;
}
if (match->data) {
const struct mpc_i2c_data *data = match->data;
data->setup(op->dev.of_node, i2c, clock, data->prescaler);
} else {
if (of_get_property(op->dev.of_node, "dfsrr", NULL))
mpc_i2c_setup_8xxx(op->dev.of_node, i2c, clock, 0);
}
prop = of_get_property(op->dev.of_node, "fsl,timeout", &plen);
if (prop && plen == sizeof(u32)) {
mpc_ops.timeout = *prop * HZ / 1000000;
if (mpc_ops.timeout < 5)
mpc_ops.timeout = 5;
}
dev_info(i2c->dev, "timeout %u us\n", mpc_ops.timeout * 1000000 / HZ);
platform_set_drvdata(op, i2c);
i2c->adap = mpc_ops;
i2c_set_adapdata(&i2c->adap, i2c);
i2c->adap.dev.parent = &op->dev;
i2c->adap.dev.of_node = of_node_get(op->dev.of_node);
result = i2c_add_adapter(&i2c->adap);
if (result < 0) {
dev_err(i2c->dev, "failed to add adapter\n");
goto fail_add;
}
of_i2c_register_devices(&i2c->adap);
return result;
fail_add:
free_irq(i2c->irq, i2c);
fail_request:
irq_dispose_mapping(i2c->irq);
iounmap(i2c->base);
fail_map:
kfree(i2c);
return result;
}
static int fsl_i2c_remove(struct platform_device *op)
{
struct mpc_i2c *i2c = platform_get_drvdata(op);
i2c_del_adapter(&i2c->adap);
if (i2c->irq)
free_irq(i2c->irq, i2c);
irq_dispose_mapping(i2c->irq);
iounmap(i2c->base);
kfree(i2c);
return 0;
}
static int mpc_i2c_suspend(struct device *dev)
{
struct mpc_i2c *i2c = dev_get_drvdata(dev);
i2c->fdr = readb(i2c->base + MPC_I2C_FDR);
i2c->dfsrr = readb(i2c->base + MPC_I2C_DFSRR);
return 0;
}
static int mpc_i2c_resume(struct device *dev)
{
struct mpc_i2c *i2c = dev_get_drvdata(dev);
writeb(i2c->fdr, i2c->base + MPC_I2C_FDR);
writeb(i2c->dfsrr, i2c->base + MPC_I2C_DFSRR);
return 0;
}
