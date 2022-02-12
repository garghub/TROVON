static inline void riic_clear_set_bit(struct riic_dev *riic, u8 clear, u8 set, u8 reg)
{
writeb((readb(riic->base + reg) & ~clear) | set, riic->base + reg);
}
static int riic_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct riic_dev *riic = i2c_get_adapdata(adap);
unsigned long time_left;
int i, ret;
u8 start_bit;
ret = clk_prepare_enable(riic->clk);
if (ret)
return ret;
if (readb(riic->base + RIIC_ICCR2) & ICCR2_BBSY) {
riic->err = -EBUSY;
goto out;
}
reinit_completion(&riic->msg_done);
riic->err = 0;
writeb(0, riic->base + RIIC_ICSR2);
for (i = 0, start_bit = ICCR2_ST; i < num; i++) {
riic->bytes_left = RIIC_INIT_MSG;
riic->buf = msgs[i].buf;
riic->msg = &msgs[i];
riic->is_last = (i == num - 1);
writeb(ICIER_NAKIE | ICIER_TIE, riic->base + RIIC_ICIER);
writeb(start_bit, riic->base + RIIC_ICCR2);
time_left = wait_for_completion_timeout(&riic->msg_done, riic->adapter.timeout);
if (time_left == 0)
riic->err = -ETIMEDOUT;
if (riic->err)
break;
start_bit = ICCR2_RS;
}
out:
clk_disable_unprepare(riic->clk);
return riic->err ?: num;
}
static irqreturn_t riic_tdre_isr(int irq, void *data)
{
struct riic_dev *riic = data;
u8 val;
if (!riic->bytes_left)
return IRQ_NONE;
if (riic->bytes_left == RIIC_INIT_MSG) {
val = !!(riic->msg->flags & I2C_M_RD);
if (val)
riic_clear_set_bit(riic, ICIER_TIE, ICIER_RIE, RIIC_ICIER);
else
riic->bytes_left = riic->msg->len;
val |= (riic->msg->addr << 1);
} else {
val = *riic->buf;
riic->buf++;
riic->bytes_left--;
}
if (riic->bytes_left == 0)
riic_clear_set_bit(riic, ICIER_TIE, ICIER_TEIE, RIIC_ICIER);
writeb(val, riic->base + RIIC_ICDRT);
return IRQ_HANDLED;
}
static irqreturn_t riic_tend_isr(int irq, void *data)
{
struct riic_dev *riic = data;
if (readb(riic->base + RIIC_ICSR2) & ICSR2_NACKF) {
readb(riic->base + RIIC_ICDRR);
riic->err = -ENXIO;
} else if (riic->bytes_left) {
return IRQ_NONE;
}
if (riic->is_last || riic->err) {
riic_clear_set_bit(riic, ICIER_TEIE, ICIER_SPIE, RIIC_ICIER);
writeb(ICCR2_SP, riic->base + RIIC_ICCR2);
} else {
riic_clear_set_bit(riic, ICIER_TEIE, 0, RIIC_ICIER);
complete(&riic->msg_done);
}
return IRQ_HANDLED;
}
static irqreturn_t riic_rdrf_isr(int irq, void *data)
{
struct riic_dev *riic = data;
if (!riic->bytes_left)
return IRQ_NONE;
if (riic->bytes_left == RIIC_INIT_MSG) {
riic->bytes_left = riic->msg->len;
readb(riic->base + RIIC_ICDRR);
return IRQ_HANDLED;
}
if (riic->bytes_left == 1) {
if (riic->is_last) {
riic_clear_set_bit(riic, 0, ICIER_SPIE, RIIC_ICIER);
writeb(ICCR2_SP, riic->base + RIIC_ICCR2);
}
riic_clear_set_bit(riic, 0, ICMR3_ACKBT, RIIC_ICMR3);
} else {
riic_clear_set_bit(riic, ICMR3_ACKBT, 0, RIIC_ICMR3);
}
*riic->buf = readb(riic->base + RIIC_ICDRR);
riic->buf++;
riic->bytes_left--;
return IRQ_HANDLED;
}
static irqreturn_t riic_stop_isr(int irq, void *data)
{
struct riic_dev *riic = data;
writeb(0, riic->base + RIIC_ICSR2);
readb(riic->base + RIIC_ICSR2);
writeb(0, riic->base + RIIC_ICIER);
readb(riic->base + RIIC_ICIER);
complete(&riic->msg_done);
return IRQ_HANDLED;
}
static u32 riic_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int riic_init_hw(struct riic_dev *riic, u32 spd)
{
int ret;
unsigned long rate;
ret = clk_prepare_enable(riic->clk);
if (ret)
return ret;
rate = clk_get_rate(riic->clk);
if (rate != 33325000) {
dev_err(&riic->adapter.dev,
"invalid parent clk (%lu). Must be 33325000Hz\n", rate);
clk_disable_unprepare(riic->clk);
return -EINVAL;
}
writeb(ICCR1_IICRST | ICCR1_SOWP, riic->base + RIIC_ICCR1);
riic_clear_set_bit(riic, 0, ICCR1_ICE, RIIC_ICCR1);
switch (spd) {
case 100000:
writeb(ICMR1_CKS(3), riic->base + RIIC_ICMR1);
writeb(ICBRH_SP100K, riic->base + RIIC_ICBRH);
writeb(ICBRL_SP100K, riic->base + RIIC_ICBRL);
break;
case 400000:
writeb(ICMR1_CKS(1), riic->base + RIIC_ICMR1);
writeb(ICBRH_SP400K, riic->base + RIIC_ICBRH);
writeb(ICBRL_SP400K, riic->base + RIIC_ICBRL);
break;
default:
dev_err(&riic->adapter.dev,
"unsupported bus speed (%dHz). Use 100000 or 400000\n", spd);
clk_disable_unprepare(riic->clk);
return -EINVAL;
}
writeb(0, riic->base + RIIC_ICSER);
writeb(ICMR3_ACKWP | ICMR3_RDRFS, riic->base + RIIC_ICMR3);
riic_clear_set_bit(riic, ICCR1_IICRST, 0, RIIC_ICCR1);
clk_disable_unprepare(riic->clk);
return 0;
}
static int riic_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct riic_dev *riic;
struct i2c_adapter *adap;
struct resource *res;
u32 bus_rate = 0;
int i, ret;
riic = devm_kzalloc(&pdev->dev, sizeof(*riic), GFP_KERNEL);
if (!riic)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
riic->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(riic->base))
return PTR_ERR(riic->base);
riic->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(riic->clk)) {
dev_err(&pdev->dev, "missing controller clock");
return PTR_ERR(riic->clk);
}
for (i = 0; i < ARRAY_SIZE(riic_irqs); i++) {
res = platform_get_resource(pdev, IORESOURCE_IRQ, riic_irqs[i].res_num);
if (!res)
return -ENODEV;
ret = devm_request_irq(&pdev->dev, res->start, riic_irqs[i].isr,
0, riic_irqs[i].name, riic);
if (ret) {
dev_err(&pdev->dev, "failed to request irq %s\n", riic_irqs[i].name);
return ret;
}
}
adap = &riic->adapter;
i2c_set_adapdata(adap, riic);
strlcpy(adap->name, "Renesas RIIC adapter", sizeof(adap->name));
adap->owner = THIS_MODULE;
adap->algo = &riic_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
init_completion(&riic->msg_done);
of_property_read_u32(np, "clock-frequency", &bus_rate);
ret = riic_init_hw(riic, bus_rate);
if (ret)
return ret;
ret = i2c_add_adapter(adap);
if (ret)
return ret;
platform_set_drvdata(pdev, riic);
dev_info(&pdev->dev, "registered with %dHz bus speed\n", bus_rate);
return 0;
}
static int riic_i2c_remove(struct platform_device *pdev)
{
struct riic_dev *riic = platform_get_drvdata(pdev);
writeb(0, riic->base + RIIC_ICIER);
i2c_del_adapter(&riic->adapter);
return 0;
}
