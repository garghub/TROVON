static void dw_hdmi_write(struct dw_hdmi_cec *cec, u8 val, int offset)
{
cec->ops->write(cec->hdmi, val, offset);
}
static u8 dw_hdmi_read(struct dw_hdmi_cec *cec, int offset)
{
return cec->ops->read(cec->hdmi, offset);
}
static int dw_hdmi_cec_log_addr(struct cec_adapter *adap, u8 logical_addr)
{
struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
if (logical_addr == CEC_LOG_ADDR_INVALID)
cec->addresses = 0;
else
cec->addresses |= BIT(logical_addr) | BIT(15);
dw_hdmi_write(cec, cec->addresses & 255, HDMI_CEC_ADDR_L);
dw_hdmi_write(cec, cec->addresses >> 8, HDMI_CEC_ADDR_H);
return 0;
}
static int dw_hdmi_cec_transmit(struct cec_adapter *adap, u8 attempts,
u32 signal_free_time, struct cec_msg *msg)
{
struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
unsigned int i, ctrl;
switch (signal_free_time) {
case CEC_SIGNAL_FREE_TIME_RETRY:
ctrl = CEC_CTRL_RETRY;
break;
case CEC_SIGNAL_FREE_TIME_NEW_INITIATOR:
default:
ctrl = CEC_CTRL_NORMAL;
break;
case CEC_SIGNAL_FREE_TIME_NEXT_XFER:
ctrl = CEC_CTRL_IMMED;
break;
}
for (i = 0; i < msg->len; i++)
dw_hdmi_write(cec, msg->msg[i], HDMI_CEC_TX_DATA0 + i);
dw_hdmi_write(cec, msg->len, HDMI_CEC_TX_CNT);
dw_hdmi_write(cec, ctrl | CEC_CTRL_START, HDMI_CEC_CTRL);
return 0;
}
static irqreturn_t dw_hdmi_cec_hardirq(int irq, void *data)
{
struct cec_adapter *adap = data;
struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
unsigned int stat = dw_hdmi_read(cec, HDMI_IH_CEC_STAT0);
irqreturn_t ret = IRQ_HANDLED;
if (stat == 0)
return IRQ_NONE;
dw_hdmi_write(cec, stat, HDMI_IH_CEC_STAT0);
if (stat & CEC_STAT_ERROR_INIT) {
cec->tx_status = CEC_TX_STATUS_ERROR;
cec->tx_done = true;
ret = IRQ_WAKE_THREAD;
} else if (stat & CEC_STAT_DONE) {
cec->tx_status = CEC_TX_STATUS_OK;
cec->tx_done = true;
ret = IRQ_WAKE_THREAD;
} else if (stat & CEC_STAT_NACK) {
cec->tx_status = CEC_TX_STATUS_NACK;
cec->tx_done = true;
ret = IRQ_WAKE_THREAD;
}
if (stat & CEC_STAT_EOM) {
unsigned int len, i;
len = dw_hdmi_read(cec, HDMI_CEC_RX_CNT);
if (len > sizeof(cec->rx_msg.msg))
len = sizeof(cec->rx_msg.msg);
for (i = 0; i < len; i++)
cec->rx_msg.msg[i] =
dw_hdmi_read(cec, HDMI_CEC_RX_DATA0 + i);
dw_hdmi_write(cec, 0, HDMI_CEC_LOCK);
cec->rx_msg.len = len;
smp_wmb();
cec->rx_done = true;
ret = IRQ_WAKE_THREAD;
}
return ret;
}
static irqreturn_t dw_hdmi_cec_thread(int irq, void *data)
{
struct cec_adapter *adap = data;
struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
if (cec->tx_done) {
cec->tx_done = false;
cec_transmit_attempt_done(adap, cec->tx_status);
}
if (cec->rx_done) {
cec->rx_done = false;
smp_rmb();
cec_received_msg(adap, &cec->rx_msg);
}
return IRQ_HANDLED;
}
static int dw_hdmi_cec_enable(struct cec_adapter *adap, bool enable)
{
struct dw_hdmi_cec *cec = cec_get_drvdata(adap);
if (!enable) {
dw_hdmi_write(cec, ~0, HDMI_CEC_MASK);
dw_hdmi_write(cec, ~0, HDMI_IH_MUTE_CEC_STAT0);
dw_hdmi_write(cec, 0, HDMI_CEC_POLARITY);
cec->ops->disable(cec->hdmi);
} else {
unsigned int irqs;
dw_hdmi_write(cec, 0, HDMI_CEC_CTRL);
dw_hdmi_write(cec, ~0, HDMI_IH_CEC_STAT0);
dw_hdmi_write(cec, 0, HDMI_CEC_LOCK);
dw_hdmi_cec_log_addr(cec->adap, CEC_LOG_ADDR_INVALID);
cec->ops->enable(cec->hdmi);
irqs = CEC_STAT_ERROR_INIT | CEC_STAT_NACK | CEC_STAT_EOM |
CEC_STAT_DONE;
dw_hdmi_write(cec, irqs, HDMI_CEC_POLARITY);
dw_hdmi_write(cec, ~irqs, HDMI_CEC_MASK);
dw_hdmi_write(cec, ~irqs, HDMI_IH_MUTE_CEC_STAT0);
}
return 0;
}
static void dw_hdmi_cec_del(void *data)
{
struct dw_hdmi_cec *cec = data;
cec_delete_adapter(cec->adap);
}
static int dw_hdmi_cec_probe(struct platform_device *pdev)
{
struct dw_hdmi_cec_data *data = dev_get_platdata(&pdev->dev);
struct dw_hdmi_cec *cec;
int ret;
if (!data)
return -ENXIO;
cec = devm_kzalloc(&pdev->dev, sizeof(*cec), GFP_KERNEL);
if (!cec)
return -ENOMEM;
cec->irq = data->irq;
cec->ops = data->ops;
cec->hdmi = data->hdmi;
platform_set_drvdata(pdev, cec);
dw_hdmi_write(cec, 0, HDMI_CEC_TX_CNT);
dw_hdmi_write(cec, ~0, HDMI_CEC_MASK);
dw_hdmi_write(cec, ~0, HDMI_IH_MUTE_CEC_STAT0);
dw_hdmi_write(cec, 0, HDMI_CEC_POLARITY);
cec->adap = cec_allocate_adapter(&dw_hdmi_cec_ops, cec, "dw_hdmi",
CEC_CAP_LOG_ADDRS | CEC_CAP_TRANSMIT |
CEC_CAP_RC | CEC_CAP_PASSTHROUGH,
CEC_MAX_LOG_ADDRS);
if (IS_ERR(cec->adap))
return PTR_ERR(cec->adap);
cec->adap->owner = THIS_MODULE;
ret = devm_add_action(&pdev->dev, dw_hdmi_cec_del, cec);
if (ret) {
cec_delete_adapter(cec->adap);
return ret;
}
ret = devm_request_threaded_irq(&pdev->dev, cec->irq,
dw_hdmi_cec_hardirq,
dw_hdmi_cec_thread, IRQF_SHARED,
"dw-hdmi-cec", cec->adap);
if (ret < 0)
return ret;
cec->notify = cec_notifier_get(pdev->dev.parent);
if (!cec->notify)
return -ENOMEM;
ret = cec_register_adapter(cec->adap, pdev->dev.parent);
if (ret < 0) {
cec_notifier_put(cec->notify);
return ret;
}
devm_remove_action(&pdev->dev, dw_hdmi_cec_del, cec);
cec_register_cec_notifier(cec->adap, cec->notify);
return 0;
}
static int dw_hdmi_cec_remove(struct platform_device *pdev)
{
struct dw_hdmi_cec *cec = platform_get_drvdata(pdev);
cec_unregister_adapter(cec->adap);
cec_notifier_put(cec->notify);
return 0;
}
