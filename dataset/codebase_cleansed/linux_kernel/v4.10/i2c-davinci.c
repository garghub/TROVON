static inline void davinci_i2c_write_reg(struct davinci_i2c_dev *i2c_dev,
int reg, u16 val)
{
writew_relaxed(val, i2c_dev->base + reg);
}
static inline u16 davinci_i2c_read_reg(struct davinci_i2c_dev *i2c_dev, int reg)
{
return readw_relaxed(i2c_dev->base + reg);
}
static inline void davinci_i2c_reset_ctrl(struct davinci_i2c_dev *i2c_dev,
int val)
{
u16 w;
w = davinci_i2c_read_reg(i2c_dev, DAVINCI_I2C_MDR_REG);
if (!val)
w &= ~DAVINCI_I2C_MDR_IRS;
else
w |= DAVINCI_I2C_MDR_IRS;
davinci_i2c_write_reg(i2c_dev, DAVINCI_I2C_MDR_REG, w);
}
static void i2c_davinci_calc_clk_dividers(struct davinci_i2c_dev *dev)
{
struct davinci_i2c_platform_data *pdata = dev->pdata;
u16 psc;
u32 clk;
u32 d;
u32 clkh;
u32 clkl;
u32 input_clock = clk_get_rate(dev->clk);
struct device_node *of_node = dev->dev->of_node;
psc = (input_clock / 12000000) - 1;
if ((input_clock / (psc + 1)) > 12000000)
psc++;
d = (psc >= 2) ? 5 : 7 - psc;
if (of_node && of_device_is_compatible(of_node, "ti,keystone-i2c"))
d = 6;
clk = ((input_clock / (psc + 1)) / (pdata->bus_freq * 1000));
if (input_clock / (psc + 1) / clk > pdata->bus_freq * 1000)
clk++;
if (pdata->bus_freq > 100)
clkl = (clk << 1) / 3;
else
clkl = (clk >> 1);
if (clk >= clkl + d) {
clkh = clk - clkl - d;
clkl -= d;
} else {
clkh = 0;
clkl = clk - (d << 1);
}
davinci_i2c_write_reg(dev, DAVINCI_I2C_PSC_REG, psc);
davinci_i2c_write_reg(dev, DAVINCI_I2C_CLKH_REG, clkh);
davinci_i2c_write_reg(dev, DAVINCI_I2C_CLKL_REG, clkl);
dev_dbg(dev->dev, "input_clock = %d, CLK = %d\n", input_clock, clk);
}
static int i2c_davinci_init(struct davinci_i2c_dev *dev)
{
struct davinci_i2c_platform_data *pdata = dev->pdata;
davinci_i2c_reset_ctrl(dev, 0);
i2c_davinci_calc_clk_dividers(dev);
davinci_i2c_write_reg(dev, DAVINCI_I2C_OAR_REG, DAVINCI_I2C_OWN_ADDRESS);
dev_dbg(dev->dev, "PSC = %d\n",
davinci_i2c_read_reg(dev, DAVINCI_I2C_PSC_REG));
dev_dbg(dev->dev, "CLKL = %d\n",
davinci_i2c_read_reg(dev, DAVINCI_I2C_CLKL_REG));
dev_dbg(dev->dev, "CLKH = %d\n",
davinci_i2c_read_reg(dev, DAVINCI_I2C_CLKH_REG));
dev_dbg(dev->dev, "bus_freq = %dkHz, bus_delay = %d\n",
pdata->bus_freq, pdata->bus_delay);
davinci_i2c_reset_ctrl(dev, 1);
davinci_i2c_write_reg(dev, DAVINCI_I2C_IMR_REG, I2C_DAVINCI_INTR_ALL);
return 0;
}
static void davinci_i2c_prepare_recovery(struct i2c_adapter *adap)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
davinci_i2c_write_reg(dev, DAVINCI_I2C_IMR_REG, 0);
davinci_i2c_reset_ctrl(dev, 0);
}
static void davinci_i2c_unprepare_recovery(struct i2c_adapter *adap)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
i2c_davinci_init(dev);
}
static void davinci_i2c_set_scl(struct i2c_adapter *adap, int val)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
if (val)
davinci_i2c_write_reg(dev, DAVINCI_I2C_DSET_REG,
DAVINCI_I2C_DSET_PDSET0);
else
davinci_i2c_write_reg(dev, DAVINCI_I2C_DCLR_REG,
DAVINCI_I2C_DCLR_PDCLR0);
}
static int davinci_i2c_get_scl(struct i2c_adapter *adap)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
int val;
val = davinci_i2c_read_reg(dev, DAVINCI_I2C_DIN_REG);
return val & DAVINCI_I2C_DIN_PDIN0;
}
static int davinci_i2c_get_sda(struct i2c_adapter *adap)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
int val;
val = davinci_i2c_read_reg(dev, DAVINCI_I2C_DIN_REG);
return val & DAVINCI_I2C_DIN_PDIN1;
}
static void davinci_i2c_scl_prepare_recovery(struct i2c_adapter *adap)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
davinci_i2c_prepare_recovery(adap);
davinci_i2c_write_reg(dev, DAVINCI_I2C_DIR_REG, DAVINCI_I2C_DIR_PDIR0);
davinci_i2c_write_reg(dev, DAVINCI_I2C_FUNC_REG,
DAVINCI_I2C_FUNC_PFUNC0);
}
static void davinci_i2c_scl_unprepare_recovery(struct i2c_adapter *adap)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
davinci_i2c_write_reg(dev, DAVINCI_I2C_FUNC_REG, 0);
davinci_i2c_unprepare_recovery(adap);
}
static int i2c_davinci_wait_bus_not_busy(struct davinci_i2c_dev *dev)
{
unsigned long timeout = jiffies + dev->adapter.timeout;
do {
if (!(davinci_i2c_read_reg(dev, DAVINCI_I2C_STR_REG) & DAVINCI_I2C_STR_BB))
return 0;
schedule_timeout_uninterruptible(1);
} while (time_before_eq(jiffies, timeout));
dev_warn(dev->dev, "timeout waiting for bus ready\n");
i2c_recover_bus(&dev->adapter);
if (davinci_i2c_read_reg(dev, DAVINCI_I2C_STR_REG) & DAVINCI_I2C_STR_BB)
return -EIO;
return 0;
}
static int
i2c_davinci_xfer_msg(struct i2c_adapter *adap, struct i2c_msg *msg, int stop)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
struct davinci_i2c_platform_data *pdata = dev->pdata;
u32 flag;
u16 w;
unsigned long time_left;
if (msg->addr == DAVINCI_I2C_OWN_ADDRESS) {
dev_warn(dev->dev, "transfer to own address aborted\n");
return -EADDRNOTAVAIL;
}
if (pdata->bus_delay)
udelay(pdata->bus_delay);
davinci_i2c_write_reg(dev, DAVINCI_I2C_SAR_REG, msg->addr);
dev->buf = msg->buf;
dev->buf_len = msg->len;
dev->stop = stop;
davinci_i2c_write_reg(dev, DAVINCI_I2C_CNT_REG, dev->buf_len);
reinit_completion(&dev->cmd_complete);
dev->cmd_err = 0;
flag = DAVINCI_I2C_MDR_IRS | DAVINCI_I2C_MDR_MST;
if (msg->flags & I2C_M_TEN)
flag |= DAVINCI_I2C_MDR_XA;
if (!(msg->flags & I2C_M_RD))
flag |= DAVINCI_I2C_MDR_TRX;
if (msg->len == 0)
flag |= DAVINCI_I2C_MDR_RM;
w = davinci_i2c_read_reg(dev, DAVINCI_I2C_IMR_REG);
if (msg->flags & I2C_M_RD)
w |= DAVINCI_I2C_IMR_RRDY;
else
w |= DAVINCI_I2C_IMR_XRDY;
davinci_i2c_write_reg(dev, DAVINCI_I2C_IMR_REG, w);
dev->terminate = 0;
davinci_i2c_write_reg(dev, DAVINCI_I2C_MDR_REG, flag);
if ((!(msg->flags & I2C_M_RD)) && dev->buf_len) {
davinci_i2c_write_reg(dev, DAVINCI_I2C_DXR_REG, *dev->buf++);
dev->buf_len--;
}
flag |= DAVINCI_I2C_MDR_STT;
if (stop && msg->len != 0)
flag |= DAVINCI_I2C_MDR_STP;
davinci_i2c_write_reg(dev, DAVINCI_I2C_MDR_REG, flag);
time_left = wait_for_completion_timeout(&dev->cmd_complete,
dev->adapter.timeout);
if (!time_left) {
dev_err(dev->dev, "controller timed out\n");
i2c_recover_bus(adap);
dev->buf_len = 0;
return -ETIMEDOUT;
}
if (dev->buf_len) {
dev_err(dev->dev, "abnormal termination buf_len=%i\n",
dev->buf_len);
dev->terminate = 1;
wmb();
dev->buf_len = 0;
return -EREMOTEIO;
}
if (likely(!dev->cmd_err))
return msg->len;
if (dev->cmd_err & DAVINCI_I2C_STR_AL) {
i2c_davinci_init(dev);
return -EIO;
}
if (dev->cmd_err & DAVINCI_I2C_STR_NACK) {
if (msg->flags & I2C_M_IGNORE_NAK)
return msg->len;
w = davinci_i2c_read_reg(dev, DAVINCI_I2C_MDR_REG);
w |= DAVINCI_I2C_MDR_STP;
davinci_i2c_write_reg(dev, DAVINCI_I2C_MDR_REG, w);
return -EREMOTEIO;
}
return -EIO;
}
static int
i2c_davinci_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct davinci_i2c_dev *dev = i2c_get_adapdata(adap);
int i;
int ret;
dev_dbg(dev->dev, "%s: msgs: %d\n", __func__, num);
ret = i2c_davinci_wait_bus_not_busy(dev);
if (ret < 0) {
dev_warn(dev->dev, "timeout waiting for bus ready\n");
return ret;
}
for (i = 0; i < num; i++) {
ret = i2c_davinci_xfer_msg(adap, &msgs[i], (i == (num - 1)));
dev_dbg(dev->dev, "%s [%d/%d] ret: %d\n", __func__, i + 1, num,
ret);
if (ret < 0)
return ret;
}
#ifdef CONFIG_CPU_FREQ
complete(&dev->xfr_complete);
#endif
return num;
}
static u32 i2c_davinci_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static void terminate_read(struct davinci_i2c_dev *dev)
{
u16 w = davinci_i2c_read_reg(dev, DAVINCI_I2C_MDR_REG);
w |= DAVINCI_I2C_MDR_NACK;
davinci_i2c_write_reg(dev, DAVINCI_I2C_MDR_REG, w);
davinci_i2c_read_reg(dev, DAVINCI_I2C_DRR_REG);
if (!dev->terminate)
dev_err(dev->dev, "RDR IRQ while no data requested\n");
}
static void terminate_write(struct davinci_i2c_dev *dev)
{
u16 w = davinci_i2c_read_reg(dev, DAVINCI_I2C_MDR_REG);
w |= DAVINCI_I2C_MDR_RM | DAVINCI_I2C_MDR_STP;
davinci_i2c_write_reg(dev, DAVINCI_I2C_MDR_REG, w);
if (!dev->terminate)
dev_dbg(dev->dev, "TDR IRQ while no data to send\n");
}
static irqreturn_t i2c_davinci_isr(int this_irq, void *dev_id)
{
struct davinci_i2c_dev *dev = dev_id;
u32 stat;
int count = 0;
u16 w;
while ((stat = davinci_i2c_read_reg(dev, DAVINCI_I2C_IVR_REG))) {
dev_dbg(dev->dev, "%s: stat=0x%x\n", __func__, stat);
if (count++ == 100) {
dev_warn(dev->dev, "Too much work in one IRQ\n");
break;
}
switch (stat) {
case DAVINCI_I2C_IVR_AL:
dev->cmd_err |= DAVINCI_I2C_STR_AL;
dev->buf_len = 0;
complete(&dev->cmd_complete);
break;
case DAVINCI_I2C_IVR_NACK:
dev->cmd_err |= DAVINCI_I2C_STR_NACK;
dev->buf_len = 0;
complete(&dev->cmd_complete);
break;
case DAVINCI_I2C_IVR_ARDY:
davinci_i2c_write_reg(dev,
DAVINCI_I2C_STR_REG, DAVINCI_I2C_STR_ARDY);
if (((dev->buf_len == 0) && (dev->stop != 0)) ||
(dev->cmd_err & DAVINCI_I2C_STR_NACK)) {
w = davinci_i2c_read_reg(dev,
DAVINCI_I2C_MDR_REG);
w |= DAVINCI_I2C_MDR_STP;
davinci_i2c_write_reg(dev,
DAVINCI_I2C_MDR_REG, w);
}
complete(&dev->cmd_complete);
break;
case DAVINCI_I2C_IVR_RDR:
if (dev->buf_len) {
*dev->buf++ =
davinci_i2c_read_reg(dev,
DAVINCI_I2C_DRR_REG);
dev->buf_len--;
if (dev->buf_len)
continue;
davinci_i2c_write_reg(dev,
DAVINCI_I2C_STR_REG,
DAVINCI_I2C_IMR_RRDY);
} else {
terminate_read(dev);
}
break;
case DAVINCI_I2C_IVR_XRDY:
if (dev->buf_len) {
davinci_i2c_write_reg(dev, DAVINCI_I2C_DXR_REG,
*dev->buf++);
dev->buf_len--;
if (dev->buf_len)
continue;
w = davinci_i2c_read_reg(dev,
DAVINCI_I2C_IMR_REG);
w &= ~DAVINCI_I2C_IMR_XRDY;
davinci_i2c_write_reg(dev,
DAVINCI_I2C_IMR_REG,
w);
} else {
terminate_write(dev);
}
break;
case DAVINCI_I2C_IVR_SCD:
davinci_i2c_write_reg(dev,
DAVINCI_I2C_STR_REG, DAVINCI_I2C_STR_SCD);
complete(&dev->cmd_complete);
break;
case DAVINCI_I2C_IVR_AAS:
dev_dbg(dev->dev, "Address as slave interrupt\n");
break;
default:
dev_warn(dev->dev, "Unrecognized irq stat %d\n", stat);
break;
}
}
return count ? IRQ_HANDLED : IRQ_NONE;
}
static int i2c_davinci_cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
struct davinci_i2c_dev *dev;
dev = container_of(nb, struct davinci_i2c_dev, freq_transition);
if (val == CPUFREQ_PRECHANGE) {
wait_for_completion(&dev->xfr_complete);
davinci_i2c_reset_ctrl(dev, 0);
} else if (val == CPUFREQ_POSTCHANGE) {
i2c_davinci_calc_clk_dividers(dev);
davinci_i2c_reset_ctrl(dev, 1);
}
return 0;
}
static inline int i2c_davinci_cpufreq_register(struct davinci_i2c_dev *dev)
{
dev->freq_transition.notifier_call = i2c_davinci_cpufreq_transition;
return cpufreq_register_notifier(&dev->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline void i2c_davinci_cpufreq_deregister(struct davinci_i2c_dev *dev)
{
cpufreq_unregister_notifier(&dev->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline int i2c_davinci_cpufreq_register(struct davinci_i2c_dev *dev)
{
return 0;
}
static inline void i2c_davinci_cpufreq_deregister(struct davinci_i2c_dev *dev)
{
}
static int davinci_i2c_probe(struct platform_device *pdev)
{
struct davinci_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem;
int r, irq;
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
if (!irq)
irq = -ENXIO;
if (irq != -EPROBE_DEFER)
dev_err(&pdev->dev,
"can't get irq resource ret=%d\n", irq);
return irq;
}
dev = devm_kzalloc(&pdev->dev, sizeof(struct davinci_i2c_dev),
GFP_KERNEL);
if (!dev) {
dev_err(&pdev->dev, "Memory allocation failed\n");
return -ENOMEM;
}
init_completion(&dev->cmd_complete);
#ifdef CONFIG_CPU_FREQ
init_completion(&dev->xfr_complete);
#endif
dev->dev = &pdev->dev;
dev->irq = irq;
dev->pdata = dev_get_platdata(&pdev->dev);
platform_set_drvdata(pdev, dev);
if (!dev->pdata && pdev->dev.of_node) {
u32 prop;
dev->pdata = devm_kzalloc(&pdev->dev,
sizeof(struct davinci_i2c_platform_data), GFP_KERNEL);
if (!dev->pdata)
return -ENOMEM;
memcpy(dev->pdata, &davinci_i2c_platform_data_default,
sizeof(struct davinci_i2c_platform_data));
if (!of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&prop))
dev->pdata->bus_freq = prop / 1000;
dev->pdata->has_pfunc =
of_property_read_bool(pdev->dev.of_node,
"ti,has-pfunc");
} else if (!dev->pdata) {
dev->pdata = &davinci_i2c_platform_data_default;
}
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk))
return -ENODEV;
clk_prepare_enable(dev->clk);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dev->base)) {
r = PTR_ERR(dev->base);
goto err_unuse_clocks;
}
i2c_davinci_init(dev);
r = devm_request_irq(&pdev->dev, dev->irq, i2c_davinci_isr, 0,
pdev->name, dev);
if (r) {
dev_err(&pdev->dev, "failure requesting irq %i\n", dev->irq);
goto err_unuse_clocks;
}
r = i2c_davinci_cpufreq_register(dev);
if (r) {
dev_err(&pdev->dev, "failed to register cpufreq\n");
goto err_unuse_clocks;
}
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
strlcpy(adap->name, "DaVinci I2C adapter", sizeof(adap->name));
adap->algo = &i2c_davinci_algo;
adap->dev.parent = &pdev->dev;
adap->timeout = DAVINCI_I2C_TIMEOUT;
adap->dev.of_node = pdev->dev.of_node;
if (dev->pdata->has_pfunc)
adap->bus_recovery_info = &davinci_i2c_scl_recovery_info;
else if (dev->pdata->scl_pin) {
adap->bus_recovery_info = &davinci_i2c_gpio_recovery_info;
adap->bus_recovery_info->scl_gpio = dev->pdata->scl_pin;
adap->bus_recovery_info->sda_gpio = dev->pdata->sda_pin;
}
adap->nr = pdev->id;
r = i2c_add_numbered_adapter(adap);
if (r)
goto err_unuse_clocks;
return 0;
err_unuse_clocks:
clk_disable_unprepare(dev->clk);
dev->clk = NULL;
return r;
}
static int davinci_i2c_remove(struct platform_device *pdev)
{
struct davinci_i2c_dev *dev = platform_get_drvdata(pdev);
i2c_davinci_cpufreq_deregister(dev);
i2c_del_adapter(&dev->adapter);
clk_disable_unprepare(dev->clk);
dev->clk = NULL;
davinci_i2c_write_reg(dev, DAVINCI_I2C_MDR_REG, 0);
return 0;
}
static int davinci_i2c_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct davinci_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
davinci_i2c_reset_ctrl(i2c_dev, 0);
clk_disable_unprepare(i2c_dev->clk);
return 0;
}
static int davinci_i2c_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct davinci_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
clk_prepare_enable(i2c_dev->clk);
davinci_i2c_reset_ctrl(i2c_dev, 1);
return 0;
}
static int __init davinci_i2c_init_driver(void)
{
return platform_driver_register(&davinci_i2c_driver);
}
static void __exit davinci_i2c_exit_driver(void)
{
platform_driver_unregister(&davinci_i2c_driver);
}
