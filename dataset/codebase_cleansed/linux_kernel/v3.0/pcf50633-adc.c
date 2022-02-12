static inline struct pcf50633_adc *__to_adc(struct pcf50633 *pcf)
{
return platform_get_drvdata(pcf->adc_pdev);
}
static void adc_setup(struct pcf50633 *pcf, int channel, int avg)
{
channel &= PCF50633_ADCC1_ADCMUX_MASK;
pcf50633_reg_write(pcf, PCF50633_REG_ADCC2, 0x00);
pcf50633_reg_write(pcf, PCF50633_REG_ADCC3, 0x01);
pcf50633_reg_write(pcf, PCF50633_REG_ADCC1, channel | avg |
PCF50633_ADCC1_ADCSTART | PCF50633_ADCC1_RES_10BIT);
}
static void trigger_next_adc_job_if_any(struct pcf50633 *pcf)
{
struct pcf50633_adc *adc = __to_adc(pcf);
int head;
head = adc->queue_head;
if (!adc->queue[head])
return;
adc_setup(pcf, adc->queue[head]->mux, adc->queue[head]->avg);
}
static int
adc_enqueue_request(struct pcf50633 *pcf, struct pcf50633_adc_request *req)
{
struct pcf50633_adc *adc = __to_adc(pcf);
int head, tail;
mutex_lock(&adc->queue_mutex);
head = adc->queue_head;
tail = adc->queue_tail;
if (adc->queue[tail]) {
mutex_unlock(&adc->queue_mutex);
dev_err(pcf->dev, "ADC queue is full, dropping request\n");
return -EBUSY;
}
adc->queue[tail] = req;
if (head == tail)
trigger_next_adc_job_if_any(pcf);
adc->queue_tail = (tail + 1) & (PCF50633_MAX_ADC_FIFO_DEPTH - 1);
mutex_unlock(&adc->queue_mutex);
return 0;
}
static void pcf50633_adc_sync_read_callback(struct pcf50633 *pcf, void *param,
int result)
{
struct pcf50633_adc_sync_request *req = param;
req->result = result;
complete(&req->completion);
}
int pcf50633_adc_sync_read(struct pcf50633 *pcf, int mux, int avg)
{
struct pcf50633_adc_sync_request req;
int ret;
init_completion(&req.completion);
ret = pcf50633_adc_async_read(pcf, mux, avg,
pcf50633_adc_sync_read_callback, &req);
if (ret)
return ret;
wait_for_completion(&req.completion);
return req.result;
}
int pcf50633_adc_async_read(struct pcf50633 *pcf, int mux, int avg,
void (*callback)(struct pcf50633 *, void *, int),
void *callback_param)
{
struct pcf50633_adc_request *req;
req = kmalloc(sizeof(*req), GFP_KERNEL);
if (!req)
return -ENOMEM;
req->mux = mux;
req->avg = avg;
req->callback = callback;
req->callback_param = callback_param;
return adc_enqueue_request(pcf, req);
}
static int adc_result(struct pcf50633 *pcf)
{
u8 adcs1, adcs3;
u16 result;
adcs1 = pcf50633_reg_read(pcf, PCF50633_REG_ADCS1);
adcs3 = pcf50633_reg_read(pcf, PCF50633_REG_ADCS3);
result = (adcs1 << 2) | (adcs3 & PCF50633_ADCS3_ADCDAT1L_MASK);
dev_dbg(pcf->dev, "adc result = %d\n", result);
return result;
}
static void pcf50633_adc_irq(int irq, void *data)
{
struct pcf50633_adc *adc = data;
struct pcf50633 *pcf = adc->pcf;
struct pcf50633_adc_request *req;
int head, res;
mutex_lock(&adc->queue_mutex);
head = adc->queue_head;
req = adc->queue[head];
if (WARN_ON(!req)) {
dev_err(pcf->dev, "pcf50633-adc irq: ADC queue empty!\n");
mutex_unlock(&adc->queue_mutex);
return;
}
adc->queue[head] = NULL;
adc->queue_head = (head + 1) &
(PCF50633_MAX_ADC_FIFO_DEPTH - 1);
res = adc_result(pcf);
trigger_next_adc_job_if_any(pcf);
mutex_unlock(&adc->queue_mutex);
req->callback(pcf, req->callback_param, res);
kfree(req);
}
static int __devinit pcf50633_adc_probe(struct platform_device *pdev)
{
struct pcf50633_adc *adc;
adc = kzalloc(sizeof(*adc), GFP_KERNEL);
if (!adc)
return -ENOMEM;
adc->pcf = dev_to_pcf50633(pdev->dev.parent);
platform_set_drvdata(pdev, adc);
pcf50633_register_irq(adc->pcf, PCF50633_IRQ_ADCRDY,
pcf50633_adc_irq, adc);
mutex_init(&adc->queue_mutex);
return 0;
}
static int __devexit pcf50633_adc_remove(struct platform_device *pdev)
{
struct pcf50633_adc *adc = platform_get_drvdata(pdev);
int i, head;
pcf50633_free_irq(adc->pcf, PCF50633_IRQ_ADCRDY);
mutex_lock(&adc->queue_mutex);
head = adc->queue_head;
if (WARN_ON(adc->queue[head]))
dev_err(adc->pcf->dev,
"adc driver removed with request pending\n");
for (i = 0; i < PCF50633_MAX_ADC_FIFO_DEPTH; i++)
kfree(adc->queue[i]);
mutex_unlock(&adc->queue_mutex);
kfree(adc);
return 0;
}
static int __init pcf50633_adc_init(void)
{
return platform_driver_register(&pcf50633_adc_driver);
}
static void __exit pcf50633_adc_exit(void)
{
platform_driver_unregister(&pcf50633_adc_driver);
}
