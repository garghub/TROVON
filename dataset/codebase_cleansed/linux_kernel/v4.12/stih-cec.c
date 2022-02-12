static int stih_cec_adap_enable(struct cec_adapter *adap, bool enable)
{
struct stih_cec *cec = cec_get_drvdata(adap);
if (enable) {
unsigned long clk_freq = clk_get_rate(cec->clk);
u32 cec_clk_div = clk_freq / 10000;
writel(cec_clk_div, cec->regs + CEC_CLK_DIV);
writel(CEC_SBIT_TOUT_47MS | (CEC_DBIT_TOUT_28MS << 4),
cec->regs + CEC_BIT_TOUT_THRESH);
writel(CEC_BIT_LPULSE_03MS | CEC_BIT_HPULSE_03MS,
cec->regs + CEC_BIT_PULSE_THRESH);
writel(BIT(5) | BIT(7), cec->regs + CEC_TX_CTRL);
writel(CEC_TX_ARRAY_EN | CEC_RX_ARRAY_EN | CEC_TX_STOP_ON_NACK,
cec->regs + CEC_DATA_ARRAY_CTRL);
writel(CEC_IN_FILTER_EN | CEC_EN | CEC_RX_RESET_EN,
cec->regs + CEC_CTRL);
writel(0, cec->regs + CEC_ADDR_TABLE);
writel(0x0, cec->regs + CEC_STATUS);
writel(CEC_TX_DONE_IRQ_EN | CEC_RX_DONE_IRQ_EN |
CEC_RX_SOM_IRQ_EN | CEC_RX_EOM_IRQ_EN |
CEC_ERROR_IRQ_EN,
cec->regs + CEC_IRQ_CTRL);
} else {
writel(0, cec->regs + CEC_ADDR_TABLE);
writel(0x0, cec->regs + CEC_STATUS);
writel(0, cec->regs + CEC_IRQ_CTRL);
}
return 0;
}
static int stih_cec_adap_log_addr(struct cec_adapter *adap, u8 logical_addr)
{
struct stih_cec *cec = cec_get_drvdata(adap);
u32 reg = readl(cec->regs + CEC_ADDR_TABLE);
reg |= 1 << logical_addr;
if (logical_addr == CEC_LOG_ADDR_INVALID)
reg = 0;
writel(reg, cec->regs + CEC_ADDR_TABLE);
return 0;
}
static int stih_cec_adap_transmit(struct cec_adapter *adap, u8 attempts,
u32 signal_free_time, struct cec_msg *msg)
{
struct stih_cec *cec = cec_get_drvdata(adap);
int i;
for (i = 0; i < msg->len; i++)
writeb(msg->msg[i], cec->regs + CEC_TX_DATA_BASE + i);
writel(CEC_TX_AUTO_SOM_EN | CEC_TX_AUTO_EOM_EN | CEC_TX_START |
msg->len, cec->regs + CEC_TX_ARRAY_CTRL);
return 0;
}
static void stih_tx_done(struct stih_cec *cec, u32 status)
{
if (status & CEC_TX_ERROR) {
cec_transmit_done(cec->adap, CEC_TX_STATUS_ERROR, 0, 0, 0, 1);
return;
}
if (status & CEC_TX_ARB_ERROR) {
cec_transmit_done(cec->adap,
CEC_TX_STATUS_ARB_LOST, 1, 0, 0, 0);
return;
}
if (!(status & CEC_TX_ACK_GET_STS)) {
cec_transmit_done(cec->adap, CEC_TX_STATUS_NACK, 0, 1, 0, 0);
return;
}
cec_transmit_done(cec->adap, CEC_TX_STATUS_OK, 0, 0, 0, 0);
}
static void stih_rx_done(struct stih_cec *cec, u32 status)
{
struct cec_msg msg = {};
u8 i;
if (status & CEC_RX_ERROR_MIN)
return;
if (status & CEC_RX_ERROR_MAX)
return;
msg.len = readl(cec->regs + CEC_DATA_ARRAY_STATUS) & 0x1f;
if (!msg.len)
return;
if (msg.len > 16)
msg.len = 16;
for (i = 0; i < msg.len; i++)
msg.msg[i] = readl(cec->regs + CEC_RX_DATA_BASE + i);
cec_received_msg(cec->adap, &msg);
}
static irqreturn_t stih_cec_irq_handler_thread(int irq, void *priv)
{
struct stih_cec *cec = priv;
if (cec->irq_status & CEC_TX_DONE_STS)
stih_tx_done(cec, cec->irq_status);
if (cec->irq_status & CEC_RX_DONE_STS)
stih_rx_done(cec, cec->irq_status);
cec->irq_status = 0;
return IRQ_HANDLED;
}
static irqreturn_t stih_cec_irq_handler(int irq, void *priv)
{
struct stih_cec *cec = priv;
cec->irq_status = readl(cec->regs + CEC_STATUS);
writel(cec->irq_status, cec->regs + CEC_STATUS);
return IRQ_WAKE_THREAD;
}
static int stih_cec_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct stih_cec *cec;
struct device_node *np;
struct platform_device *hdmi_dev;
int ret;
cec = devm_kzalloc(dev, sizeof(*cec), GFP_KERNEL);
if (!cec)
return -ENOMEM;
np = of_parse_phandle(pdev->dev.of_node, "hdmi-phandle", 0);
if (!np) {
dev_err(&pdev->dev, "Failed to find hdmi node in device tree\n");
return -ENODEV;
}
hdmi_dev = of_find_device_by_node(np);
if (!hdmi_dev)
return -EPROBE_DEFER;
cec->notifier = cec_notifier_get(&hdmi_dev->dev);
if (!cec->notifier)
return -ENOMEM;
cec->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
cec->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(cec->regs))
return PTR_ERR(cec->regs);
cec->irq = platform_get_irq(pdev, 0);
if (cec->irq < 0)
return cec->irq;
ret = devm_request_threaded_irq(dev, cec->irq, stih_cec_irq_handler,
stih_cec_irq_handler_thread, 0,
pdev->name, cec);
if (ret)
return ret;
cec->clk = devm_clk_get(dev, "cec-clk");
if (IS_ERR(cec->clk)) {
dev_err(dev, "Cannot get cec clock\n");
return PTR_ERR(cec->clk);
}
cec->adap = cec_allocate_adapter(&sti_cec_adap_ops, cec,
CEC_NAME,
CEC_CAP_LOG_ADDRS | CEC_CAP_PASSTHROUGH |
CEC_CAP_TRANSMIT, 1);
ret = PTR_ERR_OR_ZERO(cec->adap);
if (ret)
return ret;
ret = cec_register_adapter(cec->adap, &pdev->dev);
if (ret) {
cec_delete_adapter(cec->adap);
return ret;
}
cec_register_cec_notifier(cec->adap, cec->notifier);
platform_set_drvdata(pdev, cec);
return 0;
}
static int stih_cec_remove(struct platform_device *pdev)
{
struct stih_cec *cec = platform_get_drvdata(pdev);
cec_unregister_adapter(cec->adap);
cec_notifier_put(cec->notifier);
return 0;
}
