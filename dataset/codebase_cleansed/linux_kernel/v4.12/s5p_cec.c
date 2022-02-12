static int s5p_cec_adap_enable(struct cec_adapter *adap, bool enable)
{
struct s5p_cec_dev *cec = cec_get_drvdata(adap);
if (enable) {
pm_runtime_get_sync(cec->dev);
s5p_cec_reset(cec);
s5p_cec_set_divider(cec);
s5p_cec_threshold(cec);
s5p_cec_unmask_tx_interrupts(cec);
s5p_cec_unmask_rx_interrupts(cec);
s5p_cec_enable_rx(cec);
} else {
s5p_cec_mask_tx_interrupts(cec);
s5p_cec_mask_rx_interrupts(cec);
pm_runtime_disable(cec->dev);
}
return 0;
}
static int s5p_cec_adap_log_addr(struct cec_adapter *adap, u8 addr)
{
struct s5p_cec_dev *cec = cec_get_drvdata(adap);
s5p_cec_set_addr(cec, addr);
return 0;
}
static int s5p_cec_adap_transmit(struct cec_adapter *adap, u8 attempts,
u32 signal_free_time, struct cec_msg *msg)
{
struct s5p_cec_dev *cec = cec_get_drvdata(adap);
s5p_cec_copy_packet(cec, msg->msg, msg->len, max(1, attempts - 1));
return 0;
}
static irqreturn_t s5p_cec_irq_handler(int irq, void *priv)
{
struct s5p_cec_dev *cec = priv;
u32 status = 0;
status = s5p_cec_get_status(cec);
dev_dbg(cec->dev, "irq received\n");
if (status & CEC_STATUS_TX_DONE) {
if (status & CEC_STATUS_TX_ERROR) {
dev_dbg(cec->dev, "CEC_STATUS_TX_ERROR set\n");
cec->tx = STATE_ERROR;
} else {
dev_dbg(cec->dev, "CEC_STATUS_TX_DONE\n");
cec->tx = STATE_DONE;
}
s5p_clr_pending_tx(cec);
}
if (status & CEC_STATUS_RX_DONE) {
if (status & CEC_STATUS_RX_ERROR) {
dev_dbg(cec->dev, "CEC_STATUS_RX_ERROR set\n");
s5p_cec_rx_reset(cec);
s5p_cec_enable_rx(cec);
} else {
dev_dbg(cec->dev, "CEC_STATUS_RX_DONE set\n");
if (cec->rx != STATE_IDLE)
dev_dbg(cec->dev, "Buffer overrun (worker did not process previous message)\n");
cec->rx = STATE_BUSY;
cec->msg.len = status >> 24;
cec->msg.rx_status = CEC_RX_STATUS_OK;
s5p_cec_get_rx_buf(cec, cec->msg.len,
cec->msg.msg);
cec->rx = STATE_DONE;
s5p_cec_enable_rx(cec);
}
s5p_clr_pending_rx(cec);
}
return IRQ_WAKE_THREAD;
}
static irqreturn_t s5p_cec_irq_handler_thread(int irq, void *priv)
{
struct s5p_cec_dev *cec = priv;
dev_dbg(cec->dev, "irq processing thread\n");
switch (cec->tx) {
case STATE_DONE:
cec_transmit_done(cec->adap, CEC_TX_STATUS_OK, 0, 0, 0, 0);
cec->tx = STATE_IDLE;
break;
case STATE_ERROR:
cec_transmit_done(cec->adap,
CEC_TX_STATUS_MAX_RETRIES | CEC_TX_STATUS_ERROR,
0, 0, 0, 1);
cec->tx = STATE_IDLE;
break;
case STATE_BUSY:
dev_err(cec->dev, "state set to busy, this should not occur here\n");
break;
default:
break;
}
switch (cec->rx) {
case STATE_DONE:
cec_received_msg(cec->adap, &cec->msg);
cec->rx = STATE_IDLE;
break;
default:
break;
}
return IRQ_HANDLED;
}
static int s5p_cec_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np;
struct platform_device *hdmi_dev;
struct resource *res;
struct s5p_cec_dev *cec;
int ret;
np = of_parse_phandle(pdev->dev.of_node, "hdmi-phandle", 0);
if (!np) {
dev_err(&pdev->dev, "Failed to find hdmi node in device tree\n");
return -ENODEV;
}
hdmi_dev = of_find_device_by_node(np);
if (hdmi_dev == NULL)
return -EPROBE_DEFER;
cec = devm_kzalloc(&pdev->dev, sizeof(*cec), GFP_KERNEL);
if (!cec)
return -ENOMEM;
cec->dev = dev;
cec->irq = platform_get_irq(pdev, 0);
if (cec->irq < 0)
return cec->irq;
ret = devm_request_threaded_irq(dev, cec->irq, s5p_cec_irq_handler,
s5p_cec_irq_handler_thread, 0, pdev->name, cec);
if (ret)
return ret;
cec->clk = devm_clk_get(dev, "hdmicec");
if (IS_ERR(cec->clk))
return PTR_ERR(cec->clk);
cec->pmu = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,syscon-phandle");
if (IS_ERR(cec->pmu))
return -EPROBE_DEFER;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
cec->reg = devm_ioremap_resource(dev, res);
if (IS_ERR(cec->reg))
return PTR_ERR(cec->reg);
cec->notifier = cec_notifier_get(&hdmi_dev->dev);
if (cec->notifier == NULL)
return -ENOMEM;
cec->adap = cec_allocate_adapter(&s5p_cec_adap_ops, cec,
CEC_NAME,
CEC_CAP_LOG_ADDRS | CEC_CAP_TRANSMIT |
CEC_CAP_PASSTHROUGH | CEC_CAP_RC, 1);
ret = PTR_ERR_OR_ZERO(cec->adap);
if (ret)
return ret;
ret = cec_register_adapter(cec->adap, &pdev->dev);
if (ret)
goto err_delete_adapter;
cec_register_cec_notifier(cec->adap, cec->notifier);
platform_set_drvdata(pdev, cec);
pm_runtime_enable(dev);
dev_dbg(dev, "successfuly probed\n");
return 0;
err_delete_adapter:
cec_delete_adapter(cec->adap);
return ret;
}
static int s5p_cec_remove(struct platform_device *pdev)
{
struct s5p_cec_dev *cec = platform_get_drvdata(pdev);
cec_unregister_adapter(cec->adap);
cec_notifier_put(cec->notifier);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __maybe_unused s5p_cec_runtime_suspend(struct device *dev)
{
struct s5p_cec_dev *cec = dev_get_drvdata(dev);
clk_disable_unprepare(cec->clk);
return 0;
}
static int __maybe_unused s5p_cec_runtime_resume(struct device *dev)
{
struct s5p_cec_dev *cec = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(cec->clk);
if (ret < 0)
return ret;
return 0;
}
