static void decode_mg(struct cma3000_accl_data *data, int *datax,
int *datay, int *dataz)
{
*datax = ((s8)*datax) * data->bit_to_mg;
*datay = ((s8)*datay) * data->bit_to_mg;
*dataz = ((s8)*dataz) * data->bit_to_mg;
}
static irqreturn_t cma3000_thread_irq(int irq, void *dev_id)
{
struct cma3000_accl_data *data = dev_id;
int datax, datay, dataz;
u8 ctrl, mode, range, intr_status;
intr_status = CMA3000_READ(data, CMA3000_INTSTATUS, "interrupt status");
if (intr_status < 0)
return IRQ_NONE;
if (intr_status & CMA3000_INTSTATUS_FFDET) {
input_report_abs(data->input_dev, ABS_MISC, 1);
input_sync(data->input_dev);
} else {
input_report_abs(data->input_dev, ABS_MISC, 0);
}
datax = CMA3000_READ(data, CMA3000_DOUTX, "X");
datay = CMA3000_READ(data, CMA3000_DOUTY, "Y");
dataz = CMA3000_READ(data, CMA3000_DOUTZ, "Z");
ctrl = CMA3000_READ(data, CMA3000_CTRL, "ctrl");
mode = (ctrl & CMA3000_MODEMASK) >> 1;
range = (ctrl & CMA3000_GRANGEMASK) >> 7;
data->bit_to_mg = mode_to_mg[mode][range];
if (data->bit_to_mg == 0)
return IRQ_NONE;
decode_mg(data, &datax, &datay, &dataz);
input_report_abs(data->input_dev, ABS_X, datax);
input_report_abs(data->input_dev, ABS_Y, datay);
input_report_abs(data->input_dev, ABS_Z, dataz);
input_sync(data->input_dev);
return IRQ_HANDLED;
}
static int cma3000_reset(struct cma3000_accl_data *data)
{
int val;
CMA3000_SET(data, CMA3000_RSTR, 0x02, "Reset");
CMA3000_SET(data, CMA3000_RSTR, 0x0A, "Reset");
CMA3000_SET(data, CMA3000_RSTR, 0x04, "Reset");
mdelay(10);
val = CMA3000_READ(data, CMA3000_STATUS, "Status");
if (val < 0) {
dev_err(data->dev, "Reset failed\n");
return val;
}
if (val & CMA3000_STATUS_PERR) {
dev_err(data->dev, "Parity Error\n");
return -EIO;
}
return 0;
}
static int cma3000_poweron(struct cma3000_accl_data *data)
{
const struct cma3000_platform_data *pdata = data->pdata;
u8 ctrl = 0;
int ret;
if (data->g_range == CMARANGE_2G) {
ctrl = (data->mode << 1) | CMA3000_RANGE2G;
} else if (data->g_range == CMARANGE_8G) {
ctrl = (data->mode << 1) | CMA3000_RANGE8G;
} else {
dev_info(data->dev,
"Invalid G range specified, assuming 8G\n");
ctrl = (data->mode << 1) | CMA3000_RANGE8G;
}
ctrl |= data->bus_ops->ctrl_mod;
CMA3000_SET(data, CMA3000_MDTHR, pdata->mdthr,
"Motion Detect Threshold");
CMA3000_SET(data, CMA3000_MDFFTMR, pdata->mdfftmr,
"Time register");
CMA3000_SET(data, CMA3000_FFTHR, pdata->ffthr,
"Free fall threshold");
ret = CMA3000_SET(data, CMA3000_CTRL, ctrl, "Mode setting");
if (ret < 0)
return -EIO;
msleep(CMA3000_SETDELAY);
return 0;
}
static int cma3000_poweroff(struct cma3000_accl_data *data)
{
int ret;
ret = CMA3000_SET(data, CMA3000_CTRL, CMAMODE_POFF, "Mode setting");
msleep(CMA3000_SETDELAY);
return ret;
}
static int cma3000_open(struct input_dev *input_dev)
{
struct cma3000_accl_data *data = input_get_drvdata(input_dev);
mutex_lock(&data->mutex);
if (!data->suspended)
cma3000_poweron(data);
data->opened = true;
mutex_unlock(&data->mutex);
return 0;
}
static void cma3000_close(struct input_dev *input_dev)
{
struct cma3000_accl_data *data = input_get_drvdata(input_dev);
mutex_lock(&data->mutex);
if (!data->suspended)
cma3000_poweroff(data);
data->opened = false;
mutex_unlock(&data->mutex);
}
void cma3000_suspend(struct cma3000_accl_data *data)
{
mutex_lock(&data->mutex);
if (!data->suspended && data->opened)
cma3000_poweroff(data);
data->suspended = true;
mutex_unlock(&data->mutex);
}
void cma3000_resume(struct cma3000_accl_data *data)
{
mutex_lock(&data->mutex);
if (data->suspended && data->opened)
cma3000_poweron(data);
data->suspended = false;
mutex_unlock(&data->mutex);
}
struct cma3000_accl_data *cma3000_init(struct device *dev, int irq,
const struct cma3000_bus_ops *bops)
{
const struct cma3000_platform_data *pdata = dev->platform_data;
struct cma3000_accl_data *data;
struct input_dev *input_dev;
int rev;
int error;
if (!pdata) {
dev_err(dev, "platform data not found\n");
error = -EINVAL;
goto err_out;
}
if (irq == 0) {
error = -EINVAL;
goto err_out;
}
data = kzalloc(sizeof(struct cma3000_accl_data), GFP_KERNEL);
input_dev = input_allocate_device();
if (!data || !input_dev) {
error = -ENOMEM;
goto err_free_mem;
}
data->dev = dev;
data->input_dev = input_dev;
data->bus_ops = bops;
data->pdata = pdata;
data->irq = irq;
mutex_init(&data->mutex);
data->mode = pdata->mode;
if (data->mode < CMAMODE_DEFAULT || data->mode > CMAMODE_POFF) {
data->mode = CMAMODE_MOTDET;
dev_warn(dev,
"Invalid mode specified, assuming Motion Detect\n");
}
data->g_range = pdata->g_range;
if (data->g_range != CMARANGE_2G && data->g_range != CMARANGE_8G) {
dev_info(dev,
"Invalid G range specified, assuming 8G\n");
data->g_range = CMARANGE_8G;
}
input_dev->name = "cma3000-accelerometer";
input_dev->id.bustype = bops->bustype;
input_dev->open = cma3000_open;
input_dev->close = cma3000_close;
__set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_X,
-data->g_range, data->g_range, pdata->fuzz_x, 0);
input_set_abs_params(input_dev, ABS_Y,
-data->g_range, data->g_range, pdata->fuzz_y, 0);
input_set_abs_params(input_dev, ABS_Z,
-data->g_range, data->g_range, pdata->fuzz_z, 0);
input_set_abs_params(input_dev, ABS_MISC, 0, 1, 0, 0);
input_set_drvdata(input_dev, data);
error = cma3000_reset(data);
if (error)
goto err_free_mem;
rev = CMA3000_READ(data, CMA3000_REVID, "Revid");
if (rev < 0) {
error = rev;
goto err_free_mem;
}
pr_info("CMA3000 Accelerometer: Revision %x\n", rev);
error = request_threaded_irq(irq, NULL, cma3000_thread_irq,
pdata->irqflags | IRQF_ONESHOT,
"cma3000_d0x", data);
if (error) {
dev_err(dev, "request_threaded_irq failed\n");
goto err_free_mem;
}
error = input_register_device(data->input_dev);
if (error) {
dev_err(dev, "Unable to register input device\n");
goto err_free_irq;
}
return data;
err_free_irq:
free_irq(irq, data);
err_free_mem:
input_free_device(input_dev);
kfree(data);
err_out:
return ERR_PTR(error);
}
void cma3000_exit(struct cma3000_accl_data *data)
{
free_irq(data->irq, data);
input_unregister_device(data->input_dev);
kfree(data);
}
