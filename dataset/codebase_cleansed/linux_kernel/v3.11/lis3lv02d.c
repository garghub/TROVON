static int param_set_axis(const char *val, const struct kernel_param *kp)
{
int ret = param_set_int(val, kp);
if (!ret) {
int val = *(int *)kp->arg;
if (val < 0)
val = -val;
if (!val || val > 3)
return -EINVAL;
}
return ret;
}
static s16 lis3lv02d_read_8(struct lis3lv02d *lis3, int reg)
{
s8 lo;
if (lis3->read(lis3, reg, &lo) < 0)
return 0;
return lo;
}
static s16 lis3lv02d_read_12(struct lis3lv02d *lis3, int reg)
{
u8 lo, hi;
lis3->read(lis3, reg - 1, &lo);
lis3->read(lis3, reg, &hi);
return (s16)((hi << 8) | lo);
}
static s16 lis331dlh_read_data(struct lis3lv02d *lis3, int reg)
{
u8 lo, hi;
int v;
lis3->read(lis3, reg - 1, &lo);
lis3->read(lis3, reg, &hi);
v = (int) ((hi << 8) | lo);
return (s16) v >> lis3->shift_adj;
}
static inline int lis3lv02d_get_axis(s8 axis, int hw_values[3])
{
if (axis > 0)
return hw_values[axis - 1];
else
return -hw_values[-axis - 1];
}
static void lis3lv02d_get_xyz(struct lis3lv02d *lis3, int *x, int *y, int *z)
{
int position[3];
int i;
if (lis3->blkread) {
if (lis3->whoami == WAI_12B) {
u16 data[3];
lis3->blkread(lis3, OUTX_L, 6, (u8 *)data);
for (i = 0; i < 3; i++)
position[i] = (s16)le16_to_cpu(data[i]);
} else {
u8 data[5];
lis3->blkread(lis3, OUTX, 5, data);
for (i = 0; i < 3; i++)
position[i] = (s8)data[i * 2];
}
} else {
position[0] = lis3->read_data(lis3, OUTX);
position[1] = lis3->read_data(lis3, OUTY);
position[2] = lis3->read_data(lis3, OUTZ);
}
for (i = 0; i < 3; i++)
position[i] = (position[i] * lis3->scale) / LIS3_ACCURACY;
*x = lis3lv02d_get_axis(lis3->ac.x, position);
*y = lis3lv02d_get_axis(lis3->ac.y, position);
*z = lis3lv02d_get_axis(lis3->ac.z, position);
}
static int lis3lv02d_get_odr(struct lis3lv02d *lis3)
{
u8 ctrl;
int shift;
lis3->read(lis3, CTRL_REG1, &ctrl);
ctrl &= lis3->odr_mask;
shift = ffs(lis3->odr_mask) - 1;
return lis3->odrs[(ctrl >> shift)];
}
static int lis3lv02d_get_pwron_wait(struct lis3lv02d *lis3)
{
int div = lis3lv02d_get_odr(lis3);
if (WARN_ONCE(div == 0, "device returned spurious data"))
return -ENXIO;
msleep(lis3->pwron_delay / div);
return 0;
}
static int lis3lv02d_set_odr(struct lis3lv02d *lis3, int rate)
{
u8 ctrl;
int i, len, shift;
if (!rate)
return -EINVAL;
lis3->read(lis3, CTRL_REG1, &ctrl);
ctrl &= ~lis3->odr_mask;
len = 1 << hweight_long(lis3->odr_mask);
shift = ffs(lis3->odr_mask) - 1;
for (i = 0; i < len; i++)
if (lis3->odrs[i] == rate) {
lis3->write(lis3, CTRL_REG1,
ctrl | (i << shift));
return 0;
}
return -EINVAL;
}
static int lis3lv02d_selftest(struct lis3lv02d *lis3, s16 results[3])
{
u8 ctlreg, reg;
s16 x, y, z;
u8 selftest;
int ret;
u8 ctrl_reg_data;
unsigned char irq_cfg;
mutex_lock(&lis3->mutex);
irq_cfg = lis3->irq_cfg;
if (lis3->whoami == WAI_8B) {
lis3->data_ready_count[IRQ_LINE0] = 0;
lis3->data_ready_count[IRQ_LINE1] = 0;
atomic_inc(&lis3->wake_thread);
lis3->irq_cfg = LIS3_IRQ1_DATA_READY | LIS3_IRQ2_DATA_READY;
lis3->read(lis3, CTRL_REG3, &ctrl_reg_data);
lis3->write(lis3, CTRL_REG3, (ctrl_reg_data &
~(LIS3_IRQ1_MASK | LIS3_IRQ2_MASK)) |
(LIS3_IRQ1_DATA_READY | LIS3_IRQ2_DATA_READY));
}
if ((lis3->whoami == WAI_3DC) || (lis3->whoami == WAI_3DLH)) {
ctlreg = CTRL_REG4;
selftest = CTRL4_ST0;
} else {
ctlreg = CTRL_REG1;
if (lis3->whoami == WAI_12B)
selftest = CTRL1_ST;
else
selftest = CTRL1_STP;
}
lis3->read(lis3, ctlreg, &reg);
lis3->write(lis3, ctlreg, (reg | selftest));
ret = lis3lv02d_get_pwron_wait(lis3);
if (ret)
goto fail;
x = lis3->read_data(lis3, OUTX);
y = lis3->read_data(lis3, OUTY);
z = lis3->read_data(lis3, OUTZ);
lis3->write(lis3, ctlreg, reg);
ret = lis3lv02d_get_pwron_wait(lis3);
if (ret)
goto fail;
results[0] = x - lis3->read_data(lis3, OUTX);
results[1] = y - lis3->read_data(lis3, OUTY);
results[2] = z - lis3->read_data(lis3, OUTZ);
ret = 0;
if (lis3->whoami == WAI_8B) {
atomic_dec(&lis3->wake_thread);
lis3->write(lis3, CTRL_REG3, ctrl_reg_data);
lis3->irq_cfg = irq_cfg;
if ((irq_cfg & LIS3_IRQ1_MASK) &&
lis3->data_ready_count[IRQ_LINE0] < 2) {
ret = SELFTEST_IRQ;
goto fail;
}
if ((irq_cfg & LIS3_IRQ2_MASK) &&
lis3->data_ready_count[IRQ_LINE1] < 2) {
ret = SELFTEST_IRQ;
goto fail;
}
}
if (lis3->pdata) {
int i;
for (i = 0; i < 3; i++) {
if ((results[i] < lis3->pdata->st_min_limits[i]) ||
(results[i] > lis3->pdata->st_max_limits[i])) {
ret = SELFTEST_FAIL;
goto fail;
}
}
}
fail:
mutex_unlock(&lis3->mutex);
return ret;
}
static inline void lis3_context_save(struct lis3lv02d *lis3)
{
int i;
for (i = 0; i < lis3->regs_size; i++)
lis3->read(lis3, lis3->regs[i], &lis3->reg_cache[i]);
lis3->regs_stored = true;
}
static inline void lis3_context_restore(struct lis3lv02d *lis3)
{
int i;
if (lis3->regs_stored)
for (i = 0; i < lis3->regs_size; i++)
lis3->write(lis3, lis3->regs[i], lis3->reg_cache[i]);
}
void lis3lv02d_poweroff(struct lis3lv02d *lis3)
{
if (lis3->reg_ctrl)
lis3_context_save(lis3);
lis3->write(lis3, CTRL_REG1, 0x00);
if (lis3->reg_ctrl)
lis3->reg_ctrl(lis3, LIS3_REG_OFF);
}
int lis3lv02d_poweron(struct lis3lv02d *lis3)
{
int err;
u8 reg;
lis3->init(lis3);
if (lis3->pdata) {
lis3->read(lis3, CTRL_REG2, &reg);
if (lis3->whoami == WAI_12B)
reg |= CTRL2_BDU | CTRL2_BOOT;
else if (lis3->whoami == WAI_3DLH)
reg |= CTRL2_BOOT_3DLH;
else
reg |= CTRL2_BOOT_8B;
lis3->write(lis3, CTRL_REG2, reg);
if (lis3->whoami == WAI_3DLH) {
lis3->read(lis3, CTRL_REG4, &reg);
reg |= CTRL4_BDU;
lis3->write(lis3, CTRL_REG4, reg);
}
}
err = lis3lv02d_get_pwron_wait(lis3);
if (err)
return err;
if (lis3->reg_ctrl)
lis3_context_restore(lis3);
return 0;
}
static void lis3lv02d_joystick_poll(struct input_polled_dev *pidev)
{
struct lis3lv02d *lis3 = pidev->private;
int x, y, z;
mutex_lock(&lis3->mutex);
lis3lv02d_get_xyz(lis3, &x, &y, &z);
input_report_abs(pidev->input, ABS_X, x);
input_report_abs(pidev->input, ABS_Y, y);
input_report_abs(pidev->input, ABS_Z, z);
input_sync(pidev->input);
mutex_unlock(&lis3->mutex);
}
static void lis3lv02d_joystick_open(struct input_polled_dev *pidev)
{
struct lis3lv02d *lis3 = pidev->private;
if (lis3->pm_dev)
pm_runtime_get_sync(lis3->pm_dev);
if (lis3->pdata && lis3->whoami == WAI_8B && lis3->idev)
atomic_set(&lis3->wake_thread, 1);
lis3lv02d_joystick_poll(pidev);
}
static void lis3lv02d_joystick_close(struct input_polled_dev *pidev)
{
struct lis3lv02d *lis3 = pidev->private;
atomic_set(&lis3->wake_thread, 0);
if (lis3->pm_dev)
pm_runtime_put(lis3->pm_dev);
}
static irqreturn_t lis302dl_interrupt(int irq, void *data)
{
struct lis3lv02d *lis3 = data;
if (!test_bit(0, &lis3->misc_opened))
goto out;
atomic_inc(&lis3->count);
wake_up_interruptible(&lis3->misc_wait);
kill_fasync(&lis3->async_queue, SIGIO, POLL_IN);
out:
if (atomic_read(&lis3->wake_thread))
return IRQ_WAKE_THREAD;
return IRQ_HANDLED;
}
static void lis302dl_interrupt_handle_click(struct lis3lv02d *lis3)
{
struct input_dev *dev = lis3->idev->input;
u8 click_src;
mutex_lock(&lis3->mutex);
lis3->read(lis3, CLICK_SRC, &click_src);
if (click_src & CLICK_SINGLE_X) {
input_report_key(dev, lis3->mapped_btns[0], 1);
input_report_key(dev, lis3->mapped_btns[0], 0);
}
if (click_src & CLICK_SINGLE_Y) {
input_report_key(dev, lis3->mapped_btns[1], 1);
input_report_key(dev, lis3->mapped_btns[1], 0);
}
if (click_src & CLICK_SINGLE_Z) {
input_report_key(dev, lis3->mapped_btns[2], 1);
input_report_key(dev, lis3->mapped_btns[2], 0);
}
input_sync(dev);
mutex_unlock(&lis3->mutex);
}
static inline void lis302dl_data_ready(struct lis3lv02d *lis3, int index)
{
int dummy;
lis3lv02d_get_xyz(lis3, &dummy, &dummy, &dummy);
lis3->data_ready_count[index]++;
}
static irqreturn_t lis302dl_interrupt_thread1_8b(int irq, void *data)
{
struct lis3lv02d *lis3 = data;
u8 irq_cfg = lis3->irq_cfg & LIS3_IRQ1_MASK;
if (irq_cfg == LIS3_IRQ1_CLICK)
lis302dl_interrupt_handle_click(lis3);
else if (unlikely(irq_cfg == LIS3_IRQ1_DATA_READY))
lis302dl_data_ready(lis3, IRQ_LINE0);
else
lis3lv02d_joystick_poll(lis3->idev);
return IRQ_HANDLED;
}
static irqreturn_t lis302dl_interrupt_thread2_8b(int irq, void *data)
{
struct lis3lv02d *lis3 = data;
u8 irq_cfg = lis3->irq_cfg & LIS3_IRQ2_MASK;
if (irq_cfg == LIS3_IRQ2_CLICK)
lis302dl_interrupt_handle_click(lis3);
else if (unlikely(irq_cfg == LIS3_IRQ2_DATA_READY))
lis302dl_data_ready(lis3, IRQ_LINE1);
else
lis3lv02d_joystick_poll(lis3->idev);
return IRQ_HANDLED;
}
static int lis3lv02d_misc_open(struct inode *inode, struct file *file)
{
struct lis3lv02d *lis3 = container_of(file->private_data,
struct lis3lv02d, miscdev);
if (test_and_set_bit(0, &lis3->misc_opened))
return -EBUSY;
if (lis3->pm_dev)
pm_runtime_get_sync(lis3->pm_dev);
atomic_set(&lis3->count, 0);
return 0;
}
static int lis3lv02d_misc_release(struct inode *inode, struct file *file)
{
struct lis3lv02d *lis3 = container_of(file->private_data,
struct lis3lv02d, miscdev);
clear_bit(0, &lis3->misc_opened);
if (lis3->pm_dev)
pm_runtime_put(lis3->pm_dev);
return 0;
}
static ssize_t lis3lv02d_misc_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
struct lis3lv02d *lis3 = container_of(file->private_data,
struct lis3lv02d, miscdev);
DECLARE_WAITQUEUE(wait, current);
u32 data;
unsigned char byte_data;
ssize_t retval = 1;
if (count < 1)
return -EINVAL;
add_wait_queue(&lis3->misc_wait, &wait);
while (true) {
set_current_state(TASK_INTERRUPTIBLE);
data = atomic_xchg(&lis3->count, 0);
if (data)
break;
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto out;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
goto out;
}
schedule();
}
if (data < 255)
byte_data = data;
else
byte_data = 255;
set_current_state(TASK_RUNNING);
if (copy_to_user(buf, &byte_data, sizeof(byte_data)))
retval = -EFAULT;
out:
__set_current_state(TASK_RUNNING);
remove_wait_queue(&lis3->misc_wait, &wait);
return retval;
}
static unsigned int lis3lv02d_misc_poll(struct file *file, poll_table *wait)
{
struct lis3lv02d *lis3 = container_of(file->private_data,
struct lis3lv02d, miscdev);
poll_wait(file, &lis3->misc_wait, wait);
if (atomic_read(&lis3->count))
return POLLIN | POLLRDNORM;
return 0;
}
static int lis3lv02d_misc_fasync(int fd, struct file *file, int on)
{
struct lis3lv02d *lis3 = container_of(file->private_data,
struct lis3lv02d, miscdev);
return fasync_helper(fd, file, on, &lis3->async_queue);
}
int lis3lv02d_joystick_enable(struct lis3lv02d *lis3)
{
struct input_dev *input_dev;
int err;
int max_val, fuzz, flat;
int btns[] = {BTN_X, BTN_Y, BTN_Z};
if (lis3->idev)
return -EINVAL;
lis3->idev = input_allocate_polled_device();
if (!lis3->idev)
return -ENOMEM;
lis3->idev->poll = lis3lv02d_joystick_poll;
lis3->idev->open = lis3lv02d_joystick_open;
lis3->idev->close = lis3lv02d_joystick_close;
lis3->idev->poll_interval = MDPS_POLL_INTERVAL;
lis3->idev->poll_interval_min = MDPS_POLL_MIN;
lis3->idev->poll_interval_max = MDPS_POLL_MAX;
lis3->idev->private = lis3;
input_dev = lis3->idev->input;
input_dev->name = "ST LIS3LV02DL Accelerometer";
input_dev->phys = DRIVER_NAME "/input0";
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0;
input_dev->dev.parent = &lis3->pdev->dev;
set_bit(EV_ABS, input_dev->evbit);
max_val = (lis3->mdps_max_val * lis3->scale) / LIS3_ACCURACY;
if (lis3->whoami == WAI_12B) {
fuzz = LIS3_DEFAULT_FUZZ_12B;
flat = LIS3_DEFAULT_FLAT_12B;
} else {
fuzz = LIS3_DEFAULT_FUZZ_8B;
flat = LIS3_DEFAULT_FLAT_8B;
}
fuzz = (fuzz * lis3->scale) / LIS3_ACCURACY;
flat = (flat * lis3->scale) / LIS3_ACCURACY;
input_set_abs_params(input_dev, ABS_X, -max_val, max_val, fuzz, flat);
input_set_abs_params(input_dev, ABS_Y, -max_val, max_val, fuzz, flat);
input_set_abs_params(input_dev, ABS_Z, -max_val, max_val, fuzz, flat);
lis3->mapped_btns[0] = lis3lv02d_get_axis(abs(lis3->ac.x), btns);
lis3->mapped_btns[1] = lis3lv02d_get_axis(abs(lis3->ac.y), btns);
lis3->mapped_btns[2] = lis3lv02d_get_axis(abs(lis3->ac.z), btns);
err = input_register_polled_device(lis3->idev);
if (err) {
input_free_polled_device(lis3->idev);
lis3->idev = NULL;
}
return err;
}
void lis3lv02d_joystick_disable(struct lis3lv02d *lis3)
{
if (lis3->irq)
free_irq(lis3->irq, lis3);
if (lis3->pdata && lis3->pdata->irq2)
free_irq(lis3->pdata->irq2, lis3);
if (!lis3->idev)
return;
if (lis3->irq)
misc_deregister(&lis3->miscdev);
input_unregister_polled_device(lis3->idev);
input_free_polled_device(lis3->idev);
lis3->idev = NULL;
}
static void lis3lv02d_sysfs_poweron(struct lis3lv02d *lis3)
{
if (lis3->pm_dev) {
pm_runtime_get_sync(lis3->pm_dev);
pm_runtime_put_noidle(lis3->pm_dev);
pm_schedule_suspend(lis3->pm_dev, LIS3_SYSFS_POWERDOWN_DELAY);
}
}
static ssize_t lis3lv02d_selftest_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lis3lv02d *lis3 = dev_get_drvdata(dev);
s16 values[3];
static const char ok[] = "OK";
static const char fail[] = "FAIL";
static const char irq[] = "FAIL_IRQ";
const char *res;
lis3lv02d_sysfs_poweron(lis3);
switch (lis3lv02d_selftest(lis3, values)) {
case SELFTEST_FAIL:
res = fail;
break;
case SELFTEST_IRQ:
res = irq;
break;
case SELFTEST_OK:
default:
res = ok;
break;
}
return sprintf(buf, "%s %d %d %d\n", res,
values[0], values[1], values[2]);
}
static ssize_t lis3lv02d_position_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lis3lv02d *lis3 = dev_get_drvdata(dev);
int x, y, z;
lis3lv02d_sysfs_poweron(lis3);
mutex_lock(&lis3->mutex);
lis3lv02d_get_xyz(lis3, &x, &y, &z);
mutex_unlock(&lis3->mutex);
return sprintf(buf, "(%d,%d,%d)\n", x, y, z);
}
static ssize_t lis3lv02d_rate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lis3lv02d *lis3 = dev_get_drvdata(dev);
lis3lv02d_sysfs_poweron(lis3);
return sprintf(buf, "%d\n", lis3lv02d_get_odr(lis3));
}
static ssize_t lis3lv02d_rate_set(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct lis3lv02d *lis3 = dev_get_drvdata(dev);
unsigned long rate;
int ret;
ret = kstrtoul(buf, 0, &rate);
if (ret)
return ret;
lis3lv02d_sysfs_poweron(lis3);
if (lis3lv02d_set_odr(lis3, rate))
return -EINVAL;
return count;
}
static int lis3lv02d_add_fs(struct lis3lv02d *lis3)
{
lis3->pdev = platform_device_register_simple(DRIVER_NAME, -1, NULL, 0);
if (IS_ERR(lis3->pdev))
return PTR_ERR(lis3->pdev);
platform_set_drvdata(lis3->pdev, lis3);
return sysfs_create_group(&lis3->pdev->dev.kobj, &lis3lv02d_attribute_group);
}
int lis3lv02d_remove_fs(struct lis3lv02d *lis3)
{
sysfs_remove_group(&lis3->pdev->dev.kobj, &lis3lv02d_attribute_group);
platform_device_unregister(lis3->pdev);
if (lis3->pm_dev) {
pm_runtime_barrier(lis3->pm_dev);
if (!pm_runtime_suspended(lis3->pm_dev))
lis3lv02d_poweroff(lis3);
pm_runtime_disable(lis3->pm_dev);
pm_runtime_set_suspended(lis3->pm_dev);
}
kfree(lis3->reg_cache);
return 0;
}
static void lis3lv02d_8b_configure(struct lis3lv02d *lis3,
struct lis3lv02d_platform_data *p)
{
int err;
int ctrl2 = p->hipass_ctrl;
if (p->click_flags) {
lis3->write(lis3, CLICK_CFG, p->click_flags);
lis3->write(lis3, CLICK_TIMELIMIT, p->click_time_limit);
lis3->write(lis3, CLICK_LATENCY, p->click_latency);
lis3->write(lis3, CLICK_WINDOW, p->click_window);
lis3->write(lis3, CLICK_THSZ, p->click_thresh_z & 0xf);
lis3->write(lis3, CLICK_THSY_X,
(p->click_thresh_x & 0xf) |
(p->click_thresh_y << 4));
if (lis3->idev) {
struct input_dev *input_dev = lis3->idev->input;
input_set_capability(input_dev, EV_KEY, BTN_X);
input_set_capability(input_dev, EV_KEY, BTN_Y);
input_set_capability(input_dev, EV_KEY, BTN_Z);
}
}
if (p->wakeup_flags) {
lis3->write(lis3, FF_WU_CFG_1, p->wakeup_flags);
lis3->write(lis3, FF_WU_THS_1, p->wakeup_thresh & 0x7f);
lis3->write(lis3, FF_WU_DURATION_1, p->duration1 + 1);
ctrl2 ^= HP_FF_WU1;
}
if (p->wakeup_flags2) {
lis3->write(lis3, FF_WU_CFG_2, p->wakeup_flags2);
lis3->write(lis3, FF_WU_THS_2, p->wakeup_thresh2 & 0x7f);
lis3->write(lis3, FF_WU_DURATION_2, p->duration2 + 1);
ctrl2 ^= HP_FF_WU2;
}
lis3->write(lis3, CTRL_REG2, ctrl2);
if (p->irq2) {
err = request_threaded_irq(p->irq2,
NULL,
lis302dl_interrupt_thread2_8b,
IRQF_TRIGGER_RISING | IRQF_ONESHOT |
(p->irq_flags2 & IRQF_TRIGGER_MASK),
DRIVER_NAME, lis3);
if (err < 0)
pr_err("No second IRQ. Limited functionality\n");
}
}
int lis3lv02d_init_dt(struct lis3lv02d *lis3)
{
struct lis3lv02d_platform_data *pdata;
struct device_node *np = lis3->of_node;
u32 val;
if (!lis3->of_node)
return 0;
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (of_get_property(np, "st,click-single-x", NULL))
pdata->click_flags |= LIS3_CLICK_SINGLE_X;
if (of_get_property(np, "st,click-double-x", NULL))
pdata->click_flags |= LIS3_CLICK_DOUBLE_X;
if (of_get_property(np, "st,click-single-y", NULL))
pdata->click_flags |= LIS3_CLICK_SINGLE_Y;
if (of_get_property(np, "st,click-double-y", NULL))
pdata->click_flags |= LIS3_CLICK_DOUBLE_Y;
if (of_get_property(np, "st,click-single-z", NULL))
pdata->click_flags |= LIS3_CLICK_SINGLE_Z;
if (of_get_property(np, "st,click-double-z", NULL))
pdata->click_flags |= LIS3_CLICK_DOUBLE_Z;
if (!of_property_read_u32(np, "st,click-threshold-x", &val))
pdata->click_thresh_x = val;
if (!of_property_read_u32(np, "st,click-threshold-y", &val))
pdata->click_thresh_y = val;
if (!of_property_read_u32(np, "st,click-threshold-z", &val))
pdata->click_thresh_z = val;
if (!of_property_read_u32(np, "st,click-time-limit", &val))
pdata->click_time_limit = val;
if (!of_property_read_u32(np, "st,click-latency", &val))
pdata->click_latency = val;
if (!of_property_read_u32(np, "st,click-window", &val))
pdata->click_window = val;
if (of_get_property(np, "st,irq1-disable", NULL))
pdata->irq_cfg |= LIS3_IRQ1_DISABLE;
if (of_get_property(np, "st,irq1-ff-wu-1", NULL))
pdata->irq_cfg |= LIS3_IRQ1_FF_WU_1;
if (of_get_property(np, "st,irq1-ff-wu-2", NULL))
pdata->irq_cfg |= LIS3_IRQ1_FF_WU_2;
if (of_get_property(np, "st,irq1-data-ready", NULL))
pdata->irq_cfg |= LIS3_IRQ1_DATA_READY;
if (of_get_property(np, "st,irq1-click", NULL))
pdata->irq_cfg |= LIS3_IRQ1_CLICK;
if (of_get_property(np, "st,irq2-disable", NULL))
pdata->irq_cfg |= LIS3_IRQ2_DISABLE;
if (of_get_property(np, "st,irq2-ff-wu-1", NULL))
pdata->irq_cfg |= LIS3_IRQ2_FF_WU_1;
if (of_get_property(np, "st,irq2-ff-wu-2", NULL))
pdata->irq_cfg |= LIS3_IRQ2_FF_WU_2;
if (of_get_property(np, "st,irq2-data-ready", NULL))
pdata->irq_cfg |= LIS3_IRQ2_DATA_READY;
if (of_get_property(np, "st,irq2-click", NULL))
pdata->irq_cfg |= LIS3_IRQ2_CLICK;
if (of_get_property(np, "st,irq-open-drain", NULL))
pdata->irq_cfg |= LIS3_IRQ_OPEN_DRAIN;
if (of_get_property(np, "st,irq-active-low", NULL))
pdata->irq_cfg |= LIS3_IRQ_ACTIVE_LOW;
if (!of_property_read_u32(np, "st,wu-duration-1", &val))
pdata->duration1 = val;
if (!of_property_read_u32(np, "st,wu-duration-2", &val))
pdata->duration2 = val;
if (of_get_property(np, "st,wakeup-x-lo", NULL))
pdata->wakeup_flags |= LIS3_WAKEUP_X_LO;
if (of_get_property(np, "st,wakeup-x-hi", NULL))
pdata->wakeup_flags |= LIS3_WAKEUP_X_HI;
if (of_get_property(np, "st,wakeup-y-lo", NULL))
pdata->wakeup_flags |= LIS3_WAKEUP_Y_LO;
if (of_get_property(np, "st,wakeup-y-hi", NULL))
pdata->wakeup_flags |= LIS3_WAKEUP_Y_HI;
if (of_get_property(np, "st,wakeup-z-lo", NULL))
pdata->wakeup_flags |= LIS3_WAKEUP_Z_LO;
if (of_get_property(np, "st,wakeup-z-hi", NULL))
pdata->wakeup_flags |= LIS3_WAKEUP_Z_HI;
if (!of_property_read_u32(np, "st,highpass-cutoff-hz", &val)) {
switch (val) {
case 1:
pdata->hipass_ctrl = LIS3_HIPASS_CUTFF_1HZ;
break;
case 2:
pdata->hipass_ctrl = LIS3_HIPASS_CUTFF_2HZ;
break;
case 4:
pdata->hipass_ctrl = LIS3_HIPASS_CUTFF_4HZ;
break;
case 8:
pdata->hipass_ctrl = LIS3_HIPASS_CUTFF_8HZ;
break;
}
}
if (of_get_property(np, "st,hipass1-disable", NULL))
pdata->hipass_ctrl |= LIS3_HIPASS1_DISABLE;
if (of_get_property(np, "st,hipass2-disable", NULL))
pdata->hipass_ctrl |= LIS3_HIPASS2_DISABLE;
if (of_get_property(np, "st,axis-x", &val))
pdata->axis_x = val;
if (of_get_property(np, "st,axis-y", &val))
pdata->axis_y = val;
if (of_get_property(np, "st,axis-z", &val))
pdata->axis_z = val;
if (of_get_property(np, "st,default-rate", NULL))
pdata->default_rate = val;
if (of_get_property(np, "st,min-limit-x", &val))
pdata->st_min_limits[0] = val;
if (of_get_property(np, "st,min-limit-y", &val))
pdata->st_min_limits[1] = val;
if (of_get_property(np, "st,min-limit-z", &val))
pdata->st_min_limits[2] = val;
if (of_get_property(np, "st,max-limit-x", &val))
pdata->st_max_limits[0] = val;
if (of_get_property(np, "st,max-limit-y", &val))
pdata->st_max_limits[1] = val;
if (of_get_property(np, "st,max-limit-z", &val))
pdata->st_max_limits[2] = val;
lis3->pdata = pdata;
return 0;
}
int lis3lv02d_init_dt(struct lis3lv02d *lis3)
{
return 0;
}
int lis3lv02d_init_device(struct lis3lv02d *lis3)
{
int err;
irq_handler_t thread_fn;
int irq_flags = 0;
lis3->whoami = lis3lv02d_read_8(lis3, WHO_AM_I);
switch (lis3->whoami) {
case WAI_12B:
pr_info("12 bits sensor found\n");
lis3->read_data = lis3lv02d_read_12;
lis3->mdps_max_val = 2048;
lis3->pwron_delay = LIS3_PWRON_DELAY_WAI_12B;
lis3->odrs = lis3_12_rates;
lis3->odr_mask = CTRL1_DF0 | CTRL1_DF1;
lis3->scale = LIS3_SENSITIVITY_12B;
lis3->regs = lis3_wai12_regs;
lis3->regs_size = ARRAY_SIZE(lis3_wai12_regs);
break;
case WAI_8B:
pr_info("8 bits sensor found\n");
lis3->read_data = lis3lv02d_read_8;
lis3->mdps_max_val = 128;
lis3->pwron_delay = LIS3_PWRON_DELAY_WAI_8B;
lis3->odrs = lis3_8_rates;
lis3->odr_mask = CTRL1_DR;
lis3->scale = LIS3_SENSITIVITY_8B;
lis3->regs = lis3_wai8_regs;
lis3->regs_size = ARRAY_SIZE(lis3_wai8_regs);
break;
case WAI_3DC:
pr_info("8 bits 3DC sensor found\n");
lis3->read_data = lis3lv02d_read_8;
lis3->mdps_max_val = 128;
lis3->pwron_delay = LIS3_PWRON_DELAY_WAI_8B;
lis3->odrs = lis3_3dc_rates;
lis3->odr_mask = CTRL1_ODR0|CTRL1_ODR1|CTRL1_ODR2|CTRL1_ODR3;
lis3->scale = LIS3_SENSITIVITY_8B;
break;
case WAI_3DLH:
pr_info("16 bits lis331dlh sensor found\n");
lis3->read_data = lis331dlh_read_data;
lis3->mdps_max_val = 2048;
lis3->shift_adj = SHIFT_ADJ_2G;
lis3->pwron_delay = LIS3_PWRON_DELAY_WAI_8B;
lis3->odrs = lis3_3dlh_rates;
lis3->odr_mask = CTRL1_DR0 | CTRL1_DR1;
lis3->scale = LIS3DLH_SENSITIVITY_2G;
break;
default:
pr_err("unknown sensor type 0x%X\n", lis3->whoami);
return -EINVAL;
}
lis3->reg_cache = kzalloc(max(sizeof(lis3_wai8_regs),
sizeof(lis3_wai12_regs)), GFP_KERNEL);
if (lis3->reg_cache == NULL) {
printk(KERN_ERR DRIVER_NAME "out of memory\n");
return -ENOMEM;
}
mutex_init(&lis3->mutex);
atomic_set(&lis3->wake_thread, 0);
lis3lv02d_add_fs(lis3);
err = lis3lv02d_poweron(lis3);
if (err) {
lis3lv02d_remove_fs(lis3);
return err;
}
if (lis3->pm_dev) {
pm_runtime_set_active(lis3->pm_dev);
pm_runtime_enable(lis3->pm_dev);
}
if (lis3lv02d_joystick_enable(lis3))
pr_err("joystick initialization failed\n");
if (lis3->pdata) {
struct lis3lv02d_platform_data *p = lis3->pdata;
if (lis3->whoami == WAI_8B)
lis3lv02d_8b_configure(lis3, p);
irq_flags = p->irq_flags1 & IRQF_TRIGGER_MASK;
lis3->irq_cfg = p->irq_cfg;
if (p->irq_cfg)
lis3->write(lis3, CTRL_REG3, p->irq_cfg);
if (p->default_rate)
lis3lv02d_set_odr(lis3, p->default_rate);
}
if (!lis3->irq) {
pr_debug("No IRQ. Disabling /dev/freefall\n");
goto out;
}
if (lis3->pdata && lis3->whoami == WAI_8B)
thread_fn = lis302dl_interrupt_thread1_8b;
else
thread_fn = NULL;
err = request_threaded_irq(lis3->irq, lis302dl_interrupt,
thread_fn,
IRQF_TRIGGER_RISING | IRQF_ONESHOT |
irq_flags,
DRIVER_NAME, lis3);
if (err < 0) {
pr_err("Cannot get IRQ\n");
goto out;
}
lis3->miscdev.minor = MISC_DYNAMIC_MINOR;
lis3->miscdev.name = "freefall";
lis3->miscdev.fops = &lis3lv02d_misc_fops;
if (misc_register(&lis3->miscdev))
pr_err("misc_register failed\n");
out:
return 0;
}
