static inline void oc_setreg(struct ocores_i2c *i2c, int reg, u8 value)
{
if (i2c->reg_io_width == 4)
iowrite32(value, i2c->base + (reg << i2c->reg_shift));
else if (i2c->reg_io_width == 2)
iowrite16(value, i2c->base + (reg << i2c->reg_shift));
else
iowrite8(value, i2c->base + (reg << i2c->reg_shift));
}
static inline u8 oc_getreg(struct ocores_i2c *i2c, int reg)
{
if (i2c->reg_io_width == 4)
return ioread32(i2c->base + (reg << i2c->reg_shift));
else if (i2c->reg_io_width == 2)
return ioread16(i2c->base + (reg << i2c->reg_shift));
else
return ioread8(i2c->base + (reg << i2c->reg_shift));
}
static void ocores_process(struct ocores_i2c *i2c)
{
struct i2c_msg *msg = i2c->msg;
u8 stat = oc_getreg(i2c, OCI2C_STATUS);
if ((i2c->state == STATE_DONE) || (i2c->state == STATE_ERROR)) {
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_IACK);
wake_up(&i2c->wait);
return;
}
if (stat & OCI2C_STAT_ARBLOST) {
i2c->state = STATE_ERROR;
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_STOP);
return;
}
if ((i2c->state == STATE_START) || (i2c->state == STATE_WRITE)) {
i2c->state =
(msg->flags & I2C_M_RD) ? STATE_READ : STATE_WRITE;
if (stat & OCI2C_STAT_NACK) {
i2c->state = STATE_ERROR;
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_STOP);
return;
}
} else
msg->buf[i2c->pos++] = oc_getreg(i2c, OCI2C_DATA);
if (i2c->pos == msg->len) {
i2c->nmsgs--;
i2c->msg++;
i2c->pos = 0;
msg = i2c->msg;
if (i2c->nmsgs) {
if (!(msg->flags & I2C_M_NOSTART)) {
u8 addr = (msg->addr << 1);
if (msg->flags & I2C_M_RD)
addr |= 1;
i2c->state = STATE_START;
oc_setreg(i2c, OCI2C_DATA, addr);
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_START);
return;
} else
i2c->state = (msg->flags & I2C_M_RD)
? STATE_READ : STATE_WRITE;
} else {
i2c->state = STATE_DONE;
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_STOP);
return;
}
}
if (i2c->state == STATE_READ) {
oc_setreg(i2c, OCI2C_CMD, i2c->pos == (msg->len-1) ?
OCI2C_CMD_READ_NACK : OCI2C_CMD_READ_ACK);
} else {
oc_setreg(i2c, OCI2C_DATA, msg->buf[i2c->pos++]);
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_WRITE);
}
}
static irqreturn_t ocores_isr(int irq, void *dev_id)
{
struct ocores_i2c *i2c = dev_id;
ocores_process(i2c);
return IRQ_HANDLED;
}
static int ocores_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct ocores_i2c *i2c = i2c_get_adapdata(adap);
i2c->msg = msgs;
i2c->pos = 0;
i2c->nmsgs = num;
i2c->state = STATE_START;
oc_setreg(i2c, OCI2C_DATA,
(i2c->msg->addr << 1) |
((i2c->msg->flags & I2C_M_RD) ? 1:0));
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_START);
if (wait_event_timeout(i2c->wait, (i2c->state == STATE_ERROR) ||
(i2c->state == STATE_DONE), HZ))
return (i2c->state == STATE_DONE) ? num : -EIO;
else
return -ETIMEDOUT;
}
static void ocores_init(struct ocores_i2c *i2c)
{
int prescale;
u8 ctrl = oc_getreg(i2c, OCI2C_CONTROL);
oc_setreg(i2c, OCI2C_CONTROL, ctrl & ~(OCI2C_CTRL_EN|OCI2C_CTRL_IEN));
prescale = (i2c->clock_khz / (5*100)) - 1;
oc_setreg(i2c, OCI2C_PRELOW, prescale & 0xff);
oc_setreg(i2c, OCI2C_PREHIGH, prescale >> 8);
oc_setreg(i2c, OCI2C_CMD, OCI2C_CMD_IACK);
oc_setreg(i2c, OCI2C_CONTROL, ctrl | OCI2C_CTRL_IEN | OCI2C_CTRL_EN);
}
static u32 ocores_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int ocores_i2c_of_probe(struct platform_device *pdev,
struct ocores_i2c *i2c)
{
struct device_node *np = pdev->dev.of_node;
u32 val;
if (of_property_read_u32(np, "reg-shift", &i2c->reg_shift)) {
if (!of_property_read_u32(np, "regstep", &val)) {
if (!is_power_of_2(val)) {
dev_err(&pdev->dev, "invalid regstep %d\n",
val);
return -EINVAL;
}
i2c->reg_shift = ilog2(val);
dev_warn(&pdev->dev,
"regstep property deprecated, use reg-shift\n");
}
}
if (of_property_read_u32(np, "clock-frequency", &val)) {
dev_err(&pdev->dev,
"Missing required parameter 'clock-frequency'\n");
return -ENODEV;
}
i2c->clock_khz = val / 1000;
of_property_read_u32(pdev->dev.of_node, "reg-io-width",
&i2c->reg_io_width);
return 0;
}
static int __devinit ocores_i2c_probe(struct platform_device *pdev)
{
struct ocores_i2c *i2c;
struct ocores_i2c_platform_data *pdata;
struct resource *res, *res2;
int ret;
int i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res2)
return -ENODEV;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "Memory region busy\n");
return -EBUSY;
}
i2c->base = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!i2c->base) {
dev_err(&pdev->dev, "Unable to map registers\n");
return -EIO;
}
pdata = pdev->dev.platform_data;
if (pdata) {
i2c->reg_shift = pdata->reg_shift;
i2c->reg_io_width = pdata->reg_io_width;
i2c->clock_khz = pdata->clock_khz;
} else {
ret = ocores_i2c_of_probe(pdev, i2c);
if (ret)
return ret;
}
if (i2c->reg_io_width == 0)
i2c->reg_io_width = 1;
ocores_init(i2c);
init_waitqueue_head(&i2c->wait);
ret = devm_request_irq(&pdev->dev, res2->start, ocores_isr, 0,
pdev->name, i2c);
if (ret) {
dev_err(&pdev->dev, "Cannot claim IRQ\n");
return ret;
}
platform_set_drvdata(pdev, i2c);
i2c->adap = ocores_adapter;
i2c_set_adapdata(&i2c->adap, i2c);
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = pdev->dev.of_node;
ret = i2c_add_adapter(&i2c->adap);
if (ret) {
dev_err(&pdev->dev, "Failed to add adapter\n");
return ret;
}
if (pdata) {
for (i = 0; i < pdata->num_devices; i++)
i2c_new_device(&i2c->adap, pdata->devices + i);
} else {
of_i2c_register_devices(&i2c->adap);
}
return 0;
}
static int __devexit ocores_i2c_remove(struct platform_device *pdev)
{
struct ocores_i2c *i2c = platform_get_drvdata(pdev);
oc_setreg(i2c, OCI2C_CONTROL, oc_getreg(i2c, OCI2C_CONTROL)
& ~(OCI2C_CTRL_EN|OCI2C_CTRL_IEN));
i2c_del_adapter(&i2c->adap);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int ocores_i2c_suspend(struct device *dev)
{
struct ocores_i2c *i2c = dev_get_drvdata(dev);
u8 ctrl = oc_getreg(i2c, OCI2C_CONTROL);
oc_setreg(i2c, OCI2C_CONTROL, ctrl & ~(OCI2C_CTRL_EN|OCI2C_CTRL_IEN));
return 0;
}
static int ocores_i2c_resume(struct device *dev)
{
struct ocores_i2c *i2c = dev_get_drvdata(dev);
ocores_init(i2c);
return 0;
}
