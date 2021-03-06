static int mrstouch_nec_adc_read_prepare(struct mrstouch_dev *tsdev)
{
return intel_scu_ipc_update_register(PMIC_REG_MADCINT, 0, 0x20);
}
static int mrstouch_nec_adc_read_finish(struct mrstouch_dev *tsdev)
{
int err;
err = intel_scu_ipc_update_register(PMIC_REG_MADCINT, 0x20, 0x20);
if (!err)
err = intel_scu_ipc_update_register(PMIC_REG_ADCCNTL1, 0, 0x05);
return err;
}
static int mrstouch_ts_chan_read(u16 offset, u16 chan, u16 *vp, u16 *vm)
{
int err;
u16 result;
u32 res;
result = PMIC_REG_ADCSNS0H + offset;
if (chan == MRST_TS_CHAN12)
result += 4;
err = intel_scu_ipc_ioread32(result, &res);
if (err)
return err;
*vp = (res & 0xFF) << 3;
*vp |= (res >> 8) & 0x07;
*vp &= 0x3FF;
res >>= 16;
*vm = (res & 0xFF) << 3;
*vm |= (res >> 8) & 0x07;
*vm &= 0x3FF;
return 0;
}
static int mrstouch_ts_bias_set(uint offset, uint bias)
{
int count;
u16 chan, start;
u16 reg[4];
u8 data[4];
chan = PMICADDR0 + offset;
start = MRST_TS_CHAN10;
for (count = 0; count <= 3; count++) {
reg[count] = chan++;
data[count] = bias | (start + count);
}
return intel_scu_ipc_writev(reg, data, 4);
}
static int mrstouch_nec_adc_read(struct mrstouch_dev *tsdev,
u16 *x, u16 *y, u16 *z)
{
int err;
u16 xm, ym, zm;
err = mrstouch_ts_bias_set(tsdev->asr, MRST_YBIAS);
if (err)
goto ipc_error;
msleep(WAIT_ADC_COMPLETION);
err = mrstouch_ts_chan_read(tsdev->asr, MRST_TS_CHAN10, x, &xm);
if (err)
goto ipc_error;
err = mrstouch_ts_bias_set(tsdev->asr, MRST_XBIAS);
if (err)
goto ipc_error;
msleep(WAIT_ADC_COMPLETION);
err = mrstouch_ts_chan_read(tsdev->asr, MRST_TS_CHAN12, y, &ym);
if (err)
goto ipc_error;
err = mrstouch_ts_bias_set(tsdev->asr, MRST_ZBIAS);
if (err)
goto ipc_error;
msleep(WAIT_ADC_COMPLETION);
err = mrstouch_ts_chan_read(tsdev->asr, MRST_TS_CHAN10, z, &zm);
if (err)
goto ipc_error;
return 0;
ipc_error:
dev_err(tsdev->dev, "ipc error during adc read\n");
return err;
}
static int mrstouch_fs_adc_read_prepare(struct mrstouch_dev *tsdev)
{
int err, count;
u16 chan;
u16 reg[5];
u8 data[5];
err = intel_scu_ipc_update_register(PMIC_REG_MADCINT, 0x00, 0x02);
if (err)
goto ipc_error;
chan = PMICADDR0 + tsdev->asr;
for (count = 0; count <= 3; count++) {
reg[count] = chan++;
data[count] = 0x2A;
}
reg[count] = chan++;
data[count] = 0;
err = intel_scu_ipc_writev(reg, data, 5);
if (err)
goto ipc_error;
msleep(WAIT_ADC_COMPLETION);
for (count = 0; count <= 3; count++) {
reg[count] = chan++;
data[count] = 0x4A;
}
reg[count] = chan++;
data[count] = 0;
err = intel_scu_ipc_writev(reg, data, 5);
if (err)
goto ipc_error;
msleep(WAIT_ADC_COMPLETION);
err = intel_scu_ipc_iowrite32(chan + 2, 0x8A8A8A8A);
if (err)
goto ipc_error;
msleep(WAIT_ADC_COMPLETION);
return 0;
ipc_error:
dev_err(tsdev->dev, "ipc error during %s\n", __func__);
return err;
}
static int mrstouch_fs_adc_read(struct mrstouch_dev *tsdev,
u16 *x, u16 *y, u16 *z)
{
int err;
u16 result;
u16 reg[4];
u8 data[4];
result = PMIC_REG_ADCSNS0H + tsdev->asr;
reg[0] = result + 4;
reg[1] = result + 5;
reg[2] = result + 16;
reg[3] = result + 17;
err = intel_scu_ipc_readv(reg, data, 4);
if (err)
goto ipc_error;
*x = data[0] << 3;
*x |= data[1] & 0x7;
*x &= 0x3FF;
*y = data[2] << 3;
*y |= data[3] & 0x7;
*y &= 0x3FF;
reg[0] = result + 28;
reg[1] = result + 29;
err = intel_scu_ipc_readv(reg, data, 4);
if (err)
goto ipc_error;
*z = data[0] << 3;
*z |= data[1] & 0x7;
*z &= 0x3FF;
return 0;
ipc_error:
dev_err(tsdev->dev, "ipc error during %s\n", __func__);
return err;
}
static int mrstouch_fs_adc_read_finish(struct mrstouch_dev *tsdev)
{
int err, count;
u16 chan;
u16 reg[5];
u8 data[5];
chan = PMICADDR0 + tsdev->asr;
for (count = 0; count <= 4; count++) {
reg[count] = chan++;
data[count] = 0;
}
err = intel_scu_ipc_writev(reg, data, 5);
if (err)
goto ipc_error;
for (count = 0; count <= 4; count++) {
reg[count] = chan++;
data[count] = 0;
}
err = intel_scu_ipc_writev(reg, data, 5);
if (err)
goto ipc_error;
err = intel_scu_ipc_iowrite32(chan + 2, 0x00000000);
if (err)
goto ipc_error;
err = intel_scu_ipc_update_register(PMIC_REG_MADCINT, 0x02, 0x02);
if (err)
goto ipc_error;
return 0;
ipc_error:
dev_err(tsdev->dev, "ipc error during %s\n", __func__);
return err;
}
static void mrstouch_report_event(struct input_dev *input,
unsigned int x, unsigned int y, unsigned int z)
{
if (z > MRST_PRESSURE_NOMINAL) {
input_report_key(input, BTN_TOUCH, 1);
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
} else {
input_report_key(input, BTN_TOUCH, 0);
}
input_report_abs(input, ABS_PRESSURE, z);
input_sync(input);
}
static irqreturn_t mrstouch_pendet_irq(int irq, void *dev_id)
{
struct mrstouch_dev *tsdev = dev_id;
u16 x, y, z;
if (tsdev->read_prepare(tsdev))
goto out;
do {
if (tsdev->read(tsdev, &x, &y, &z))
break;
mrstouch_report_event(tsdev->input, x, y, z);
} while (z > MRST_PRESSURE_NOMINAL);
tsdev->read_finish(tsdev);
out:
return IRQ_HANDLED;
}
static int __devinit mrstouch_read_pmic_id(uint *vendor, uint *rev)
{
int err;
u8 r;
err = intel_scu_ipc_ioread8(PMIC_REG_ID1, &r);
if (err)
return err;
*vendor = r & 0x7;
*rev = (r >> 3) & 0x7;
return 0;
}
static int __devinit mrstouch_chan_parse(struct mrstouch_dev *tsdev)
{
int found = 0;
int err, i;
u8 r8;
for (i = 0; i < MRSTOUCH_MAX_CHANNELS; i++) {
err = intel_scu_ipc_ioread8(PMICADDR0 + i, &r8);
if (err)
return err;
if (r8 == END_OF_CHANNEL) {
found = i;
break;
}
}
if (tsdev->vendor == PMIC_VENDOR_FS) {
if (found > MRSTOUCH_MAX_CHANNELS - 18)
return -ENOSPC;
} else {
if (found > MRSTOUCH_MAX_CHANNELS - 4)
return -ENOSPC;
}
return found;
}
static int __devinit mrstouch_ts_chan_set(uint offset)
{
u16 chan;
int ret, count;
chan = PMICADDR0 + offset;
for (count = 0; count <= 3; count++) {
ret = intel_scu_ipc_iowrite8(chan++, MRST_TS_CHAN10 + count);
if (ret)
return ret;
}
return intel_scu_ipc_iowrite8(chan++, END_OF_CHANNEL);
}
static int __devinit mrstouch_adc_init(struct mrstouch_dev *tsdev)
{
int err, start;
u8 ra, rm;
err = mrstouch_read_pmic_id(&tsdev->vendor, &tsdev->rev);
if (err) {
dev_err(tsdev->dev, "Unable to read PMIC id\n");
return err;
}
switch (tsdev->vendor) {
case PMIC_VENDOR_NEC:
case PMIC_VENDOR_MAXIM:
tsdev->read_prepare = mrstouch_nec_adc_read_prepare;
tsdev->read = mrstouch_nec_adc_read;
tsdev->read_finish = mrstouch_nec_adc_read_finish;
break;
case PMIC_VENDOR_FS:
tsdev->read_prepare = mrstouch_fs_adc_read_prepare;
tsdev->read = mrstouch_fs_adc_read;
tsdev->read_finish = mrstouch_fs_adc_read_finish;
break;
default:
dev_err(tsdev->dev,
"Unsupported touchscreen: %d\n", tsdev->vendor);
return -ENXIO;
}
start = mrstouch_chan_parse(tsdev);
if (start < 0) {
dev_err(tsdev->dev, "Unable to parse channels\n");
return start;
}
tsdev->asr = start;
if (tsdev->vendor == PMIC_VENDOR_FS) {
ra = 0xE0 | ADC_LOOP_DELAY0;
rm = 0x5;
} else {
ra = 0xE0 | ADC_LOOP_DELAY1;
rm = 0x0;
err = mrstouch_ts_chan_set(tsdev->asr);
if (err)
return err;
}
err = intel_scu_ipc_update_register(PMIC_REG_ADCCNTL1, ra, 0xE7);
if (err)
return err;
err = intel_scu_ipc_update_register(PMIC_REG_MADCINT, rm, 0x03);
if (err)
return err;
return 0;
}
static int __devinit mrstouch_probe(struct platform_device *pdev)
{
struct mrstouch_dev *tsdev;
struct input_dev *input;
int err;
int irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no interrupt assigned\n");
return -EINVAL;
}
tsdev = kzalloc(sizeof(struct mrstouch_dev), GFP_KERNEL);
input = input_allocate_device();
if (!tsdev || !input) {
dev_err(&pdev->dev, "unable to allocate memory\n");
err = -ENOMEM;
goto err_free_mem;
}
tsdev->dev = &pdev->dev;
tsdev->input = input;
tsdev->irq = irq;
snprintf(tsdev->phys, sizeof(tsdev->phys),
"%s/input0", dev_name(tsdev->dev));
err = mrstouch_adc_init(tsdev);
if (err) {
dev_err(&pdev->dev, "ADC initialization failed\n");
goto err_free_mem;
}
input->name = "mrst_touchscreen";
input->phys = tsdev->phys;
input->dev.parent = tsdev->dev;
input->id.vendor = tsdev->vendor;
input->id.version = tsdev->rev;
input->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(tsdev->input, ABS_X,
MRST_X_MIN, MRST_X_MAX, MRST_X_FUZZ, 0);
input_set_abs_params(tsdev->input, ABS_Y,
MRST_Y_MIN, MRST_Y_MAX, MRST_Y_FUZZ, 0);
input_set_abs_params(tsdev->input, ABS_PRESSURE,
MRST_PRESSURE_MIN, MRST_PRESSURE_MAX, 0, 0);
err = request_threaded_irq(tsdev->irq, NULL, mrstouch_pendet_irq,
0, "mrstouch", tsdev);
if (err) {
dev_err(tsdev->dev, "unable to allocate irq\n");
goto err_free_mem;
}
err = input_register_device(tsdev->input);
if (err) {
dev_err(tsdev->dev, "unable to register input device\n");
goto err_free_irq;
}
platform_set_drvdata(pdev, tsdev);
return 0;
err_free_irq:
free_irq(tsdev->irq, tsdev);
err_free_mem:
input_free_device(input);
kfree(tsdev);
return err;
}
static int __devexit mrstouch_remove(struct platform_device *pdev)
{
struct mrstouch_dev *tsdev = platform_get_drvdata(pdev);
free_irq(tsdev->irq, tsdev);
input_unregister_device(tsdev->input);
kfree(tsdev);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init mrstouch_init(void)
{
return platform_driver_register(&mrstouch_driver);
}
static void __exit mrstouch_exit(void)
{
platform_driver_unregister(&mrstouch_driver);
}
