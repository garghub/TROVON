static int get_sem(struct device *dev, u32 *sem)
{
u32 data;
int ret;
ret = iosf_mbi_read(BT_MBI_UNIT_PMC, MBI_REG_READ, PUNIT_SEMAPHORE, &data);
if (ret) {
dev_err(dev, "iosf failed to read punit semaphore\n");
return ret;
}
*sem = data & PUNIT_SEMAPHORE_BIT;
return 0;
}
static void reset_semaphore(struct device *dev)
{
u32 data;
if (iosf_mbi_read(BT_MBI_UNIT_PMC, MBI_REG_READ, PUNIT_SEMAPHORE, &data)) {
dev_err(dev, "iosf failed to reset punit semaphore during read\n");
return;
}
data &= ~PUNIT_SEMAPHORE_BIT;
if (iosf_mbi_write(BT_MBI_UNIT_PMC, MBI_REG_WRITE, PUNIT_SEMAPHORE, data))
dev_err(dev, "iosf failed to reset punit semaphore during write\n");
}
static int baytrail_i2c_acquire(struct dw_i2c_dev *dev)
{
u32 sem = PUNIT_SEMAPHORE_ACQUIRE;
int ret;
unsigned long start, end;
might_sleep();
if (!dev || !dev->dev)
return -ENODEV;
if (!dev->release_lock)
return 0;
ret = iosf_mbi_write(BT_MBI_UNIT_PMC, MBI_REG_WRITE, PUNIT_SEMAPHORE, sem);
if (ret) {
dev_err(dev->dev, "iosf punit semaphore request failed\n");
return ret;
}
start = jiffies;
end = start + msecs_to_jiffies(SEMAPHORE_TIMEOUT);
do {
ret = get_sem(dev->dev, &sem);
if (!ret && sem) {
acquired = jiffies;
dev_dbg(dev->dev, "punit semaphore acquired after %ums\n",
jiffies_to_msecs(jiffies - start));
return 0;
}
usleep_range(1000, 2000);
} while (time_before(jiffies, end));
dev_err(dev->dev, "punit semaphore timed out, resetting\n");
reset_semaphore(dev->dev);
ret = iosf_mbi_read(BT_MBI_UNIT_PMC, MBI_REG_READ, PUNIT_SEMAPHORE, &sem);
if (ret)
dev_err(dev->dev, "iosf failed to read punit semaphore\n");
else
dev_err(dev->dev, "PUNIT SEM: %d\n", sem);
WARN_ON(1);
return -ETIMEDOUT;
}
static void baytrail_i2c_release(struct dw_i2c_dev *dev)
{
if (!dev || !dev->dev)
return;
if (!dev->acquire_lock)
return;
reset_semaphore(dev->dev);
dev_dbg(dev->dev, "punit semaphore held for %ums\n",
jiffies_to_msecs(jiffies - acquired));
}
int i2c_dw_eval_lock_support(struct dw_i2c_dev *dev)
{
acpi_status status;
unsigned long long shared_host = 0;
acpi_handle handle;
if (!dev || !dev->dev)
return 0;
handle = ACPI_HANDLE(dev->dev);
if (!handle)
return 0;
status = acpi_evaluate_integer(handle, "_SEM", NULL, &shared_host);
if (ACPI_FAILURE(status))
return 0;
if (shared_host) {
dev_info(dev->dev, "I2C bus managed by PUNIT\n");
dev->acquire_lock = baytrail_i2c_acquire;
dev->release_lock = baytrail_i2c_release;
dev->pm_runtime_disabled = true;
}
if (!iosf_mbi_available())
return -EPROBE_DEFER;
return 0;
}
