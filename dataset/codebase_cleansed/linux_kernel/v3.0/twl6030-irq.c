static int twl6030_irq_thread(void *data)
{
long irq = (long)data;
static unsigned i2c_errors;
static const unsigned max_i2c_errors = 100;
int ret;
current->flags |= PF_NOFREEZE;
while (!kthread_should_stop()) {
int i;
union {
u8 bytes[4];
u32 int_sts;
} sts;
wait_for_completion_interruptible(&irq_event);
ret = twl_i2c_read(TWL_MODULE_PIH, sts.bytes,
REG_INT_STS_A, 3);
if (ret) {
pr_warning("twl6030: I2C error %d reading PIH ISR\n",
ret);
if (++i2c_errors >= max_i2c_errors) {
printk(KERN_ERR "Maximum I2C error count"
" exceeded. Terminating %s.\n",
__func__);
break;
}
complete(&irq_event);
continue;
}
sts.bytes[3] = 0;
if (sts.bytes[2] & 0x10)
sts.bytes[2] |= 0x08;
for (i = 0; sts.int_sts; sts.int_sts >>= 1, i++) {
local_irq_disable();
if (sts.int_sts & 0x1) {
int module_irq = twl6030_irq_base +
twl6030_interrupt_mapping[i];
generic_handle_irq(module_irq);
}
local_irq_enable();
}
ret = twl_i2c_write(TWL_MODULE_PIH, sts.bytes,
REG_INT_STS_A, 3);
if (ret)
pr_warning("twl6030: I2C error in clearing PIH ISR\n");
enable_irq(irq);
}
return 0;
}
static irqreturn_t handle_twl6030_pih(int irq, void *devid)
{
disable_irq_nosync(irq);
complete(devid);
return IRQ_HANDLED;
}
static inline void activate_irq(int irq)
{
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
int twl6030_interrupt_unmask(u8 bit_mask, u8 offset)
{
int ret;
u8 unmask_value;
ret = twl_i2c_read_u8(TWL_MODULE_PIH, &unmask_value,
REG_INT_STS_A + offset);
unmask_value &= (~(bit_mask));
ret |= twl_i2c_write_u8(TWL_MODULE_PIH, unmask_value,
REG_INT_STS_A + offset);
return ret;
}
int twl6030_interrupt_mask(u8 bit_mask, u8 offset)
{
int ret;
u8 mask_value;
ret = twl_i2c_read_u8(TWL_MODULE_PIH, &mask_value,
REG_INT_STS_A + offset);
mask_value |= (bit_mask);
ret |= twl_i2c_write_u8(TWL_MODULE_PIH, mask_value,
REG_INT_STS_A + offset);
return ret;
}
int twl6030_mmc_card_detect_config(void)
{
int ret;
u8 reg_val = 0;
twl6030_interrupt_unmask(TWL6030_MMCDETECT_INT_MASK,
REG_INT_MSK_LINE_B);
twl6030_interrupt_unmask(TWL6030_MMCDETECT_INT_MASK,
REG_INT_MSK_STS_B);
ret = twl_i2c_read_u8(TWL6030_MODULE_ID0, &reg_val, TWL6030_MMCCTRL);
if (ret < 0) {
pr_err("twl6030: Failed to read MMCCTRL, error %d\n", ret);
return ret;
}
reg_val &= ~VMMC_AUTO_OFF;
reg_val |= SW_FC;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID0, reg_val, TWL6030_MMCCTRL);
if (ret < 0) {
pr_err("twl6030: Failed to write MMCCTRL, error %d\n", ret);
return ret;
}
ret = twl_i2c_read_u8(TWL6030_MODULE_ID0, &reg_val,
TWL6030_CFG_INPUT_PUPD3);
if (ret < 0) {
pr_err("twl6030: Failed to read CFG_INPUT_PUPD3, error %d\n",
ret);
return ret;
}
reg_val &= ~(MMC_PU | MMC_PD);
ret = twl_i2c_write_u8(TWL6030_MODULE_ID0, reg_val,
TWL6030_CFG_INPUT_PUPD3);
if (ret < 0) {
pr_err("twl6030: Failed to write CFG_INPUT_PUPD3, error %d\n",
ret);
return ret;
}
return 0;
}
int twl6030_mmc_card_detect(struct device *dev, int slot)
{
int ret = -EIO;
u8 read_reg = 0;
struct platform_device *pdev = to_platform_device(dev);
if (pdev->id) {
pr_err("Unknown MMC controller %d in %s\n", pdev->id, __func__);
return ret;
}
ret = twl_i2c_read_u8(TWL6030_MODULE_ID0, &read_reg,
TWL6030_MMCCTRL);
if (ret >= 0)
ret = read_reg & STS_MMC;
return ret;
}
int twl6030_init_irq(int irq_num, unsigned irq_base, unsigned irq_end)
{
int status = 0;
int i;
struct task_struct *task;
int ret;
u8 mask[4];
static struct irq_chip twl6030_irq_chip;
mask[1] = 0xFF;
mask[2] = 0xFF;
mask[3] = 0xFF;
ret = twl_i2c_write(TWL_MODULE_PIH, &mask[0],
REG_INT_MSK_LINE_A, 3);
ret = twl_i2c_write(TWL_MODULE_PIH, &mask[0],
REG_INT_MSK_STS_A, 3);
ret = twl_i2c_write(TWL_MODULE_PIH, &mask[0],
REG_INT_STS_A, 3);
twl6030_irq_base = irq_base;
twl6030_irq_chip = dummy_irq_chip;
twl6030_irq_chip.name = "twl6030";
twl6030_irq_chip.irq_set_type = NULL;
for (i = irq_base; i < irq_end; i++) {
irq_set_chip_and_handler(i, &twl6030_irq_chip,
handle_simple_irq);
activate_irq(i);
}
twl6030_irq_next = i;
pr_info("twl6030: %s (irq %d) chaining IRQs %d..%d\n", "PIH",
irq_num, irq_base, twl6030_irq_next - 1);
init_completion(&irq_event);
task = kthread_run(twl6030_irq_thread, (void *)irq_num, "twl6030-irq");
if (IS_ERR(task)) {
pr_err("twl6030: could not create irq %d thread!\n", irq_num);
status = PTR_ERR(task);
goto fail_kthread;
}
status = request_irq(irq_num, handle_twl6030_pih, IRQF_DISABLED,
"TWL6030-PIH", &irq_event);
if (status < 0) {
pr_err("twl6030: could not claim irq%d: %d\n", irq_num, status);
goto fail_irq;
}
return status;
fail_irq:
free_irq(irq_num, &irq_event);
fail_kthread:
for (i = irq_base; i < irq_end; i++)
irq_set_chip_and_handler(i, NULL, NULL);
return status;
}
int twl6030_exit_irq(void)
{
if (twl6030_irq_base) {
pr_err("twl6030: can't yet clean up IRQs?\n");
return -ENOSYS;
}
return 0;
}
