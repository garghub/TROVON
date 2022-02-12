static inline void xiic_setreg8(struct xiic_i2c *i2c, int reg, u8 value)
{
if (i2c->endianness == LITTLE)
iowrite8(value, i2c->base + reg);
else
iowrite8(value, i2c->base + reg + 3);
}
static inline u8 xiic_getreg8(struct xiic_i2c *i2c, int reg)
{
u8 ret;
if (i2c->endianness == LITTLE)
ret = ioread8(i2c->base + reg);
else
ret = ioread8(i2c->base + reg + 3);
return ret;
}
static inline void xiic_setreg16(struct xiic_i2c *i2c, int reg, u16 value)
{
if (i2c->endianness == LITTLE)
iowrite16(value, i2c->base + reg);
else
iowrite16be(value, i2c->base + reg + 2);
}
static inline void xiic_setreg32(struct xiic_i2c *i2c, int reg, int value)
{
if (i2c->endianness == LITTLE)
iowrite32(value, i2c->base + reg);
else
iowrite32be(value, i2c->base + reg);
}
static inline int xiic_getreg32(struct xiic_i2c *i2c, int reg)
{
u32 ret;
if (i2c->endianness == LITTLE)
ret = ioread32(i2c->base + reg);
else
ret = ioread32be(i2c->base + reg);
return ret;
}
static inline void xiic_irq_dis(struct xiic_i2c *i2c, u32 mask)
{
u32 ier = xiic_getreg32(i2c, XIIC_IIER_OFFSET);
xiic_setreg32(i2c, XIIC_IIER_OFFSET, ier & ~mask);
}
static inline void xiic_irq_en(struct xiic_i2c *i2c, u32 mask)
{
u32 ier = xiic_getreg32(i2c, XIIC_IIER_OFFSET);
xiic_setreg32(i2c, XIIC_IIER_OFFSET, ier | mask);
}
static inline void xiic_irq_clr(struct xiic_i2c *i2c, u32 mask)
{
u32 isr = xiic_getreg32(i2c, XIIC_IISR_OFFSET);
xiic_setreg32(i2c, XIIC_IISR_OFFSET, isr & mask);
}
static inline void xiic_irq_clr_en(struct xiic_i2c *i2c, u32 mask)
{
xiic_irq_clr(i2c, mask);
xiic_irq_en(i2c, mask);
}
static void xiic_clear_rx_fifo(struct xiic_i2c *i2c)
{
u8 sr;
for (sr = xiic_getreg8(i2c, XIIC_SR_REG_OFFSET);
!(sr & XIIC_SR_RX_FIFO_EMPTY_MASK);
sr = xiic_getreg8(i2c, XIIC_SR_REG_OFFSET))
xiic_getreg8(i2c, XIIC_DRR_REG_OFFSET);
}
static void xiic_reinit(struct xiic_i2c *i2c)
{
xiic_setreg32(i2c, XIIC_RESETR_OFFSET, XIIC_RESET_MASK);
xiic_setreg8(i2c, XIIC_RFD_REG_OFFSET, IIC_RX_FIFO_DEPTH - 1);
xiic_setreg8(i2c, XIIC_CR_REG_OFFSET, XIIC_CR_TX_FIFO_RESET_MASK);
xiic_setreg8(i2c, XIIC_CR_REG_OFFSET, XIIC_CR_ENABLE_DEVICE_MASK);
xiic_clear_rx_fifo(i2c);
xiic_setreg32(i2c, XIIC_DGIER_OFFSET, XIIC_GINTR_ENABLE_MASK);
xiic_irq_clr_en(i2c, XIIC_INTR_AAS_MASK | XIIC_INTR_ARB_LOST_MASK);
}
static void xiic_deinit(struct xiic_i2c *i2c)
{
u8 cr;
xiic_setreg32(i2c, XIIC_RESETR_OFFSET, XIIC_RESET_MASK);
cr = xiic_getreg8(i2c, XIIC_CR_REG_OFFSET);
xiic_setreg8(i2c, XIIC_CR_REG_OFFSET, cr & ~XIIC_CR_ENABLE_DEVICE_MASK);
}
static void xiic_read_rx(struct xiic_i2c *i2c)
{
u8 bytes_in_fifo;
int i;
bytes_in_fifo = xiic_getreg8(i2c, XIIC_RFO_REG_OFFSET) + 1;
dev_dbg(i2c->adap.dev.parent,
"%s entry, bytes in fifo: %d, msg: %d, SR: 0x%x, CR: 0x%x\n",
__func__, bytes_in_fifo, xiic_rx_space(i2c),
xiic_getreg8(i2c, XIIC_SR_REG_OFFSET),
xiic_getreg8(i2c, XIIC_CR_REG_OFFSET));
if (bytes_in_fifo > xiic_rx_space(i2c))
bytes_in_fifo = xiic_rx_space(i2c);
for (i = 0; i < bytes_in_fifo; i++)
i2c->rx_msg->buf[i2c->rx_pos++] =
xiic_getreg8(i2c, XIIC_DRR_REG_OFFSET);
xiic_setreg8(i2c, XIIC_RFD_REG_OFFSET,
(xiic_rx_space(i2c) > IIC_RX_FIFO_DEPTH) ?
IIC_RX_FIFO_DEPTH - 1 : xiic_rx_space(i2c) - 1);
}
static int xiic_tx_fifo_space(struct xiic_i2c *i2c)
{
return IIC_TX_FIFO_DEPTH - xiic_getreg8(i2c, XIIC_TFO_REG_OFFSET) - 1;
}
static void xiic_fill_tx_fifo(struct xiic_i2c *i2c)
{
u8 fifo_space = xiic_tx_fifo_space(i2c);
int len = xiic_tx_space(i2c);
len = (len > fifo_space) ? fifo_space : len;
dev_dbg(i2c->adap.dev.parent, "%s entry, len: %d, fifo space: %d\n",
__func__, len, fifo_space);
while (len--) {
u16 data = i2c->tx_msg->buf[i2c->tx_pos++];
if ((xiic_tx_space(i2c) == 0) && (i2c->nmsgs == 1)) {
data |= XIIC_TX_DYN_STOP_MASK;
dev_dbg(i2c->adap.dev.parent, "%s TX STOP\n", __func__);
}
xiic_setreg16(i2c, XIIC_DTR_REG_OFFSET, data);
}
}
static void xiic_wakeup(struct xiic_i2c *i2c, int code)
{
i2c->tx_msg = NULL;
i2c->rx_msg = NULL;
i2c->nmsgs = 0;
i2c->state = code;
wake_up(&i2c->wait);
}
static void xiic_process(struct xiic_i2c *i2c)
{
u32 pend, isr, ier;
u32 clr = 0;
isr = xiic_getreg32(i2c, XIIC_IISR_OFFSET);
ier = xiic_getreg32(i2c, XIIC_IIER_OFFSET);
pend = isr & ier;
dev_dbg(i2c->adap.dev.parent, "%s: IER: 0x%x, ISR: 0x%x, pend: 0x%x\n",
__func__, ier, isr, pend);
dev_dbg(i2c->adap.dev.parent, "%s: SR: 0x%x, msg: %p, nmsgs: %d\n",
__func__, xiic_getreg8(i2c, XIIC_SR_REG_OFFSET),
i2c->tx_msg, i2c->nmsgs);
if (!pend)
return;
if ((pend & XIIC_INTR_ARB_LOST_MASK) ||
((pend & XIIC_INTR_TX_ERROR_MASK) &&
!(pend & XIIC_INTR_RX_FULL_MASK))) {
dev_dbg(i2c->adap.dev.parent, "%s error\n", __func__);
xiic_reinit(i2c);
if (i2c->tx_msg)
xiic_wakeup(i2c, STATE_ERROR);
} else if (pend & XIIC_INTR_RX_FULL_MASK) {
clr = XIIC_INTR_RX_FULL_MASK;
if (!i2c->rx_msg) {
dev_dbg(i2c->adap.dev.parent,
"%s unexpexted RX IRQ\n", __func__);
xiic_clear_rx_fifo(i2c);
goto out;
}
xiic_read_rx(i2c);
if (xiic_rx_space(i2c) == 0) {
i2c->rx_msg = NULL;
clr |= (isr & XIIC_INTR_TX_ERROR_MASK);
dev_dbg(i2c->adap.dev.parent,
"%s end of message, nmsgs: %d\n",
__func__, i2c->nmsgs);
if (i2c->nmsgs > 1) {
i2c->nmsgs--;
i2c->tx_msg++;
dev_dbg(i2c->adap.dev.parent,
"%s will start next...\n", __func__);
__xiic_start_xfer(i2c);
}
}
} else if (pend & XIIC_INTR_BNB_MASK) {
clr = XIIC_INTR_BNB_MASK;
xiic_irq_dis(i2c, XIIC_INTR_BNB_MASK);
if (!i2c->tx_msg)
goto out;
if ((i2c->nmsgs == 1) && !i2c->rx_msg &&
xiic_tx_space(i2c) == 0)
xiic_wakeup(i2c, STATE_DONE);
else
xiic_wakeup(i2c, STATE_ERROR);
} else if (pend & (XIIC_INTR_TX_EMPTY_MASK | XIIC_INTR_TX_HALF_MASK)) {
clr = pend &
(XIIC_INTR_TX_EMPTY_MASK | XIIC_INTR_TX_HALF_MASK);
if (!i2c->tx_msg) {
dev_dbg(i2c->adap.dev.parent,
"%s unexpexted TX IRQ\n", __func__);
goto out;
}
xiic_fill_tx_fifo(i2c);
if (!xiic_tx_space(i2c) && xiic_tx_fifo_space(i2c) >= 2) {
dev_dbg(i2c->adap.dev.parent,
"%s end of message sent, nmsgs: %d\n",
__func__, i2c->nmsgs);
if (i2c->nmsgs > 1) {
i2c->nmsgs--;
i2c->tx_msg++;
__xiic_start_xfer(i2c);
} else {
xiic_irq_dis(i2c, XIIC_INTR_TX_HALF_MASK);
dev_dbg(i2c->adap.dev.parent,
"%s Got TX IRQ but no more to do...\n",
__func__);
}
} else if (!xiic_tx_space(i2c) && (i2c->nmsgs == 1))
xiic_irq_dis(i2c, XIIC_INTR_TX_HALF_MASK);
} else {
dev_err(i2c->adap.dev.parent, "%s Got unexpected IRQ\n",
__func__);
clr = pend;
}
out:
dev_dbg(i2c->adap.dev.parent, "%s clr: 0x%x\n", __func__, clr);
xiic_setreg32(i2c, XIIC_IISR_OFFSET, clr);
}
static int xiic_bus_busy(struct xiic_i2c *i2c)
{
u8 sr = xiic_getreg8(i2c, XIIC_SR_REG_OFFSET);
return (sr & XIIC_SR_BUS_BUSY_MASK) ? -EBUSY : 0;
}
static int xiic_busy(struct xiic_i2c *i2c)
{
int tries = 3;
int err;
if (i2c->tx_msg)
return -EBUSY;
err = xiic_bus_busy(i2c);
while (err && tries--) {
mdelay(1);
err = xiic_bus_busy(i2c);
}
return err;
}
static void xiic_start_recv(struct xiic_i2c *i2c)
{
u8 rx_watermark;
struct i2c_msg *msg = i2c->rx_msg = i2c->tx_msg;
xiic_irq_clr_en(i2c, XIIC_INTR_RX_FULL_MASK | XIIC_INTR_TX_ERROR_MASK);
rx_watermark = msg->len;
if (rx_watermark > IIC_RX_FIFO_DEPTH)
rx_watermark = IIC_RX_FIFO_DEPTH;
xiic_setreg8(i2c, XIIC_RFD_REG_OFFSET, rx_watermark - 1);
if (!(msg->flags & I2C_M_NOSTART))
xiic_setreg16(i2c, XIIC_DTR_REG_OFFSET,
(msg->addr << 1) | XIIC_READ_OPERATION |
XIIC_TX_DYN_START_MASK);
xiic_irq_clr_en(i2c, XIIC_INTR_BNB_MASK);
xiic_setreg16(i2c, XIIC_DTR_REG_OFFSET,
msg->len | ((i2c->nmsgs == 1) ? XIIC_TX_DYN_STOP_MASK : 0));
if (i2c->nmsgs == 1)
xiic_irq_clr_en(i2c, XIIC_INTR_BNB_MASK);
i2c->tx_pos = msg->len;
}
static void xiic_start_send(struct xiic_i2c *i2c)
{
struct i2c_msg *msg = i2c->tx_msg;
xiic_irq_clr(i2c, XIIC_INTR_TX_ERROR_MASK);
dev_dbg(i2c->adap.dev.parent, "%s entry, msg: %p, len: %d",
__func__, msg, msg->len);
dev_dbg(i2c->adap.dev.parent, "%s entry, ISR: 0x%x, CR: 0x%x\n",
__func__, xiic_getreg32(i2c, XIIC_IISR_OFFSET),
xiic_getreg8(i2c, XIIC_CR_REG_OFFSET));
if (!(msg->flags & I2C_M_NOSTART)) {
u16 data = ((msg->addr << 1) & 0xfe) | XIIC_WRITE_OPERATION |
XIIC_TX_DYN_START_MASK;
if ((i2c->nmsgs == 1) && msg->len == 0)
data |= XIIC_TX_DYN_STOP_MASK;
xiic_setreg16(i2c, XIIC_DTR_REG_OFFSET, data);
}
xiic_fill_tx_fifo(i2c);
xiic_irq_clr_en(i2c, XIIC_INTR_TX_EMPTY_MASK | XIIC_INTR_TX_ERROR_MASK |
XIIC_INTR_BNB_MASK);
}
static irqreturn_t xiic_isr(int irq, void *dev_id)
{
struct xiic_i2c *i2c = dev_id;
spin_lock(&i2c->lock);
xiic_setreg32(i2c, XIIC_DGIER_OFFSET, 0);
dev_dbg(i2c->adap.dev.parent, "%s entry\n", __func__);
xiic_process(i2c);
xiic_setreg32(i2c, XIIC_DGIER_OFFSET, XIIC_GINTR_ENABLE_MASK);
spin_unlock(&i2c->lock);
return IRQ_HANDLED;
}
static void __xiic_start_xfer(struct xiic_i2c *i2c)
{
int first = 1;
int fifo_space = xiic_tx_fifo_space(i2c);
dev_dbg(i2c->adap.dev.parent, "%s entry, msg: %p, fifos space: %d\n",
__func__, i2c->tx_msg, fifo_space);
if (!i2c->tx_msg)
return;
i2c->rx_pos = 0;
i2c->tx_pos = 0;
i2c->state = STATE_START;
while ((fifo_space >= 2) && (first || (i2c->nmsgs > 1))) {
if (!first) {
i2c->nmsgs--;
i2c->tx_msg++;
i2c->tx_pos = 0;
} else
first = 0;
if (i2c->tx_msg->flags & I2C_M_RD) {
xiic_start_recv(i2c);
return;
} else {
xiic_start_send(i2c);
if (xiic_tx_space(i2c) != 0) {
break;
}
}
fifo_space = xiic_tx_fifo_space(i2c);
}
if (i2c->nmsgs > 1 || xiic_tx_space(i2c))
xiic_irq_clr_en(i2c, XIIC_INTR_TX_HALF_MASK);
}
static void xiic_start_xfer(struct xiic_i2c *i2c)
{
unsigned long flags;
spin_lock_irqsave(&i2c->lock, flags);
xiic_reinit(i2c);
xiic_setreg32(i2c, XIIC_DGIER_OFFSET, 0);
spin_unlock_irqrestore(&i2c->lock, flags);
__xiic_start_xfer(i2c);
xiic_setreg32(i2c, XIIC_DGIER_OFFSET, XIIC_GINTR_ENABLE_MASK);
}
static int xiic_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct xiic_i2c *i2c = i2c_get_adapdata(adap);
int err;
dev_dbg(adap->dev.parent, "%s entry SR: 0x%x\n", __func__,
xiic_getreg8(i2c, XIIC_SR_REG_OFFSET));
err = xiic_busy(i2c);
if (err)
return err;
i2c->tx_msg = msgs;
i2c->nmsgs = num;
xiic_start_xfer(i2c);
if (wait_event_timeout(i2c->wait, (i2c->state == STATE_ERROR) ||
(i2c->state == STATE_DONE), HZ))
return (i2c->state == STATE_DONE) ? num : -EIO;
else {
i2c->tx_msg = NULL;
i2c->rx_msg = NULL;
i2c->nmsgs = 0;
return -ETIMEDOUT;
}
}
static u32 xiic_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int xiic_i2c_probe(struct platform_device *pdev)
{
struct xiic_i2c *i2c;
struct xiic_i2c_platform_data *pdata;
struct resource *res;
int ret, irq;
u8 i;
u32 sr;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->base))
return PTR_ERR(i2c->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
pdata = dev_get_platdata(&pdev->dev);
platform_set_drvdata(pdev, i2c);
i2c->adap = xiic_adapter;
i2c_set_adapdata(&i2c->adap, i2c);
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = pdev->dev.of_node;
spin_lock_init(&i2c->lock);
init_waitqueue_head(&i2c->wait);
ret = devm_request_irq(&pdev->dev, irq, xiic_isr, 0, pdev->name, i2c);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot claim IRQ\n");
return ret;
}
i2c->endianness = LITTLE;
xiic_setreg32(i2c, XIIC_CR_REG_OFFSET, XIIC_CR_TX_FIFO_RESET_MASK);
sr = xiic_getreg32(i2c, XIIC_SR_REG_OFFSET);
if (!(sr & XIIC_SR_TX_FIFO_EMPTY_MASK))
i2c->endianness = BIG;
xiic_reinit(i2c);
ret = i2c_add_adapter(&i2c->adap);
if (ret) {
dev_err(&pdev->dev, "Failed to add adapter\n");
xiic_deinit(i2c);
return ret;
}
if (pdata) {
for (i = 0; i < pdata->num_devices; i++)
i2c_new_device(&i2c->adap, pdata->devices + i);
}
return 0;
}
static int xiic_i2c_remove(struct platform_device *pdev)
{
struct xiic_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
xiic_deinit(i2c);
return 0;
}
