static void smi_data_buf_free(void)
{
if (!smi_data_buf)
return;
dev_dbg(&dcdbas_pdev->dev, "%s: phys: %x size: %lu\n",
__func__, smi_data_buf_phys_addr, smi_data_buf_size);
dma_free_coherent(&dcdbas_pdev->dev, smi_data_buf_size, smi_data_buf,
smi_data_buf_handle);
smi_data_buf = NULL;
smi_data_buf_handle = 0;
smi_data_buf_phys_addr = 0;
smi_data_buf_size = 0;
}
static int smi_data_buf_realloc(unsigned long size)
{
void *buf;
dma_addr_t handle;
if (smi_data_buf_size >= size)
return 0;
if (size > MAX_SMI_DATA_BUF_SIZE)
return -EINVAL;
buf = dma_alloc_coherent(&dcdbas_pdev->dev, size, &handle, GFP_KERNEL);
if (!buf) {
dev_dbg(&dcdbas_pdev->dev,
"%s: failed to allocate memory size %lu\n",
__func__, size);
return -ENOMEM;
}
if (smi_data_buf)
memcpy(buf, smi_data_buf, smi_data_buf_size);
smi_data_buf_free();
smi_data_buf = buf;
smi_data_buf_handle = handle;
smi_data_buf_phys_addr = (u32) virt_to_phys(buf);
smi_data_buf_size = size;
dev_dbg(&dcdbas_pdev->dev, "%s: phys: %x size: %lu\n",
__func__, smi_data_buf_phys_addr, smi_data_buf_size);
return 0;
}
static ssize_t smi_data_buf_phys_addr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%x\n", smi_data_buf_phys_addr);
}
static ssize_t smi_data_buf_size_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n", smi_data_buf_size);
}
static ssize_t smi_data_buf_size_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long buf_size;
ssize_t ret;
buf_size = simple_strtoul(buf, NULL, 10);
mutex_lock(&smi_data_lock);
ret = smi_data_buf_realloc(buf_size);
mutex_unlock(&smi_data_lock);
if (ret)
return ret;
return count;
}
static ssize_t smi_data_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
ssize_t ret;
mutex_lock(&smi_data_lock);
ret = memory_read_from_buffer(buf, count, &pos, smi_data_buf,
smi_data_buf_size);
mutex_unlock(&smi_data_lock);
return ret;
}
static ssize_t smi_data_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
ssize_t ret;
if ((pos + count) > MAX_SMI_DATA_BUF_SIZE)
return -EINVAL;
mutex_lock(&smi_data_lock);
ret = smi_data_buf_realloc(pos + count);
if (ret)
goto out;
memcpy(smi_data_buf + pos, buf, count);
ret = count;
out:
mutex_unlock(&smi_data_lock);
return ret;
}
static ssize_t host_control_action_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", host_control_action);
}
static ssize_t host_control_action_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
ssize_t ret;
mutex_lock(&smi_data_lock);
ret = smi_data_buf_realloc(sizeof(struct apm_cmd));
mutex_unlock(&smi_data_lock);
if (ret)
return ret;
host_control_action = simple_strtoul(buf, NULL, 10);
return count;
}
static ssize_t host_control_smi_type_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", host_control_smi_type);
}
static ssize_t host_control_smi_type_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
host_control_smi_type = simple_strtoul(buf, NULL, 10);
return count;
}
static ssize_t host_control_on_shutdown_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", host_control_on_shutdown);
}
static ssize_t host_control_on_shutdown_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
host_control_on_shutdown = simple_strtoul(buf, NULL, 10);
return count;
}
int dcdbas_smi_request(struct smi_cmd *smi_cmd)
{
cpumask_var_t old_mask;
int ret = 0;
if (smi_cmd->magic != SMI_CMD_MAGIC) {
dev_info(&dcdbas_pdev->dev, "%s: invalid magic value\n",
__func__);
return -EBADR;
}
if (!alloc_cpumask_var(&old_mask, GFP_KERNEL))
return -ENOMEM;
cpumask_copy(old_mask, &current->cpus_allowed);
set_cpus_allowed_ptr(current, cpumask_of(0));
if (smp_processor_id() != 0) {
dev_dbg(&dcdbas_pdev->dev, "%s: failed to get CPU 0\n",
__func__);
ret = -EBUSY;
goto out;
}
asm volatile (
"outb %b0,%w1\n"
"inb %w1"
:
: "a" (smi_cmd->command_code),
"d" (smi_cmd->command_address),
"b" (smi_cmd->ebx),
"c" (smi_cmd->ecx)
: "memory"
);
out:
set_cpus_allowed_ptr(current, old_mask);
free_cpumask_var(old_mask);
return ret;
}
static ssize_t smi_request_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct smi_cmd *smi_cmd;
unsigned long val = simple_strtoul(buf, NULL, 10);
ssize_t ret;
mutex_lock(&smi_data_lock);
if (smi_data_buf_size < sizeof(struct smi_cmd)) {
ret = -ENODEV;
goto out;
}
smi_cmd = (struct smi_cmd *)smi_data_buf;
switch (val) {
case 2:
ret = dcdbas_smi_request(smi_cmd);
if (!ret)
ret = count;
break;
case 1:
smi_cmd->ebx = (u32) virt_to_phys(smi_cmd->command_buffer);
ret = dcdbas_smi_request(smi_cmd);
if (!ret)
ret = count;
break;
case 0:
memset(smi_data_buf, 0, smi_data_buf_size);
ret = count;
break;
default:
ret = -EINVAL;
break;
}
out:
mutex_unlock(&smi_data_lock);
return ret;
}
static int host_control_smi(void)
{
struct apm_cmd *apm_cmd;
u8 *data;
unsigned long flags;
u32 num_ticks;
s8 cmd_status;
u8 index;
apm_cmd = (struct apm_cmd *)smi_data_buf;
apm_cmd->status = ESM_STATUS_CMD_UNSUCCESSFUL;
switch (host_control_smi_type) {
case HC_SMITYPE_TYPE1:
spin_lock_irqsave(&rtc_lock, flags);
data = (u8 *)&smi_data_buf_phys_addr;
for (index = PE1300_CMOS_CMD_STRUCT_PTR;
index < (PE1300_CMOS_CMD_STRUCT_PTR + 4);
index++, data++) {
outb(index,
(CMOS_BASE_PORT + CMOS_PAGE2_INDEX_PORT_PIIX4));
outb(*data,
(CMOS_BASE_PORT + CMOS_PAGE2_DATA_PORT_PIIX4));
}
cmd_status = ESM_STATUS_CMD_UNSUCCESSFUL;
outb((u8) cmd_status, PCAT_APM_STATUS_PORT);
outb(ESM_APM_CMD, PCAT_APM_CONTROL_PORT);
spin_unlock_irqrestore(&rtc_lock, flags);
num_ticks = TIMEOUT_USEC_SHORT_SEMA_BLOCKING;
while ((cmd_status = inb(PCAT_APM_STATUS_PORT))
== ESM_STATUS_CMD_UNSUCCESSFUL) {
num_ticks--;
if (num_ticks == EXPIRED_TIMER)
return -ETIME;
}
break;
case HC_SMITYPE_TYPE2:
case HC_SMITYPE_TYPE3:
spin_lock_irqsave(&rtc_lock, flags);
data = (u8 *)&smi_data_buf_phys_addr;
for (index = PE1400_CMOS_CMD_STRUCT_PTR;
index < (PE1400_CMOS_CMD_STRUCT_PTR + 4);
index++, data++) {
outb(index, (CMOS_BASE_PORT + CMOS_PAGE1_INDEX_PORT));
outb(*data, (CMOS_BASE_PORT + CMOS_PAGE1_DATA_PORT));
}
if (host_control_smi_type == HC_SMITYPE_TYPE3)
outb(ESM_APM_CMD, PCAT_APM_CONTROL_PORT);
else
outb(ESM_APM_CMD, PE1400_APM_CONTROL_PORT);
CMOS_READ(RTC_REG_C);
spin_unlock_irqrestore(&rtc_lock, flags);
cmd_status = inb(PE1400_APM_CONTROL_PORT);
num_ticks = TIMEOUT_USEC_SHORT_SEMA_BLOCKING;
while (apm_cmd->status == ESM_STATUS_CMD_UNSUCCESSFUL) {
num_ticks--;
if (num_ticks == EXPIRED_TIMER)
return -ETIME;
}
break;
default:
dev_dbg(&dcdbas_pdev->dev, "%s: invalid SMI type %u\n",
__func__, host_control_smi_type);
return -ENOSYS;
}
return 0;
}
static void dcdbas_host_control(void)
{
struct apm_cmd *apm_cmd;
u8 action;
if (host_control_action == HC_ACTION_NONE)
return;
action = host_control_action;
host_control_action = HC_ACTION_NONE;
if (!smi_data_buf) {
dev_dbg(&dcdbas_pdev->dev, "%s: no SMI buffer\n", __func__);
return;
}
if (smi_data_buf_size < sizeof(struct apm_cmd)) {
dev_dbg(&dcdbas_pdev->dev, "%s: SMI buffer too small\n",
__func__);
return;
}
apm_cmd = (struct apm_cmd *)smi_data_buf;
if (action & HC_ACTION_HOST_CONTROL_POWEROFF) {
apm_cmd->command = ESM_APM_POWER_CYCLE;
apm_cmd->reserved = 0;
*((s16 *)&apm_cmd->parameters.shortreq.parm[0]) = (s16) 0;
host_control_smi();
} else if (action & HC_ACTION_HOST_CONTROL_POWERCYCLE) {
apm_cmd->command = ESM_APM_POWER_CYCLE;
apm_cmd->reserved = 0;
*((s16 *)&apm_cmd->parameters.shortreq.parm[0]) = (s16) 20;
host_control_smi();
}
}
static int dcdbas_reboot_notify(struct notifier_block *nb, unsigned long code,
void *unused)
{
switch (code) {
case SYS_DOWN:
case SYS_HALT:
case SYS_POWER_OFF:
if (host_control_on_shutdown) {
printk(KERN_WARNING "Please wait for shutdown "
"action to complete...\n");
dcdbas_host_control();
}
break;
}
return NOTIFY_DONE;
}
static int dcdbas_probe(struct platform_device *dev)
{
int error;
host_control_action = HC_ACTION_NONE;
host_control_smi_type = HC_SMITYPE_NONE;
dcdbas_pdev = dev;
error = dma_set_coherent_mask(&dcdbas_pdev->dev, DMA_BIT_MASK(32));
if (error)
return error;
error = sysfs_create_group(&dev->dev.kobj, &dcdbas_attr_group);
if (error)
return error;
register_reboot_notifier(&dcdbas_reboot_nb);
dev_info(&dev->dev, "%s (version %s)\n",
DRIVER_DESCRIPTION, DRIVER_VERSION);
return 0;
}
static int dcdbas_remove(struct platform_device *dev)
{
unregister_reboot_notifier(&dcdbas_reboot_nb);
sysfs_remove_group(&dev->dev.kobj, &dcdbas_attr_group);
return 0;
}
static int __init dcdbas_init(void)
{
int error;
error = platform_driver_register(&dcdbas_driver);
if (error)
return error;
dcdbas_pdev_reg = platform_device_register_full(&dcdbas_dev_info);
if (IS_ERR(dcdbas_pdev_reg)) {
error = PTR_ERR(dcdbas_pdev_reg);
goto err_unregister_driver;
}
return 0;
err_unregister_driver:
platform_driver_unregister(&dcdbas_driver);
return error;
}
static void __exit dcdbas_exit(void)
{
unregister_reboot_notifier(&dcdbas_reboot_nb);
if (dcdbas_pdev)
smi_data_buf_free();
platform_device_unregister(dcdbas_pdev_reg);
platform_driver_unregister(&dcdbas_driver);
}
