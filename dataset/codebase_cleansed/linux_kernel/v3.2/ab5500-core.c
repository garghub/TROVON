int ab5500_get_register_interruptible_raw(struct ab5500 *ab,
u8 bank, u8 reg,
u8 *value)
{
int err;
if (bank >= AB5500_NUM_BANKS)
return -EINVAL;
err = mutex_lock_interruptible(&ab->access_mutex);
if (err)
return err;
err = db5500_prcmu_abb_read(bankinfo[bank].slave_addr, reg, value, 1);
mutex_unlock(&ab->access_mutex);
return err;
}
static int get_register_page_interruptible(struct ab5500 *ab, u8 bank,
u8 first_reg, u8 *regvals, u8 numregs)
{
int err;
if (bank >= AB5500_NUM_BANKS)
return -EINVAL;
err = mutex_lock_interruptible(&ab->access_mutex);
if (err)
return err;
while (numregs) {
u8 curnum = min_t(u8, numregs, 4u);
err = db5500_prcmu_abb_read(bankinfo[bank].slave_addr,
first_reg, regvals, curnum);
if (err)
goto out;
numregs -= curnum;
first_reg += curnum;
regvals += curnum;
}
out:
mutex_unlock(&ab->access_mutex);
return err;
}
int ab5500_mask_and_set_register_interruptible_raw(struct ab5500 *ab, u8 bank,
u8 reg, u8 bitmask, u8 bitvalues)
{
int err = 0;
if (bank >= AB5500_NUM_BANKS)
return -EINVAL;
if (bitmask) {
u8 buf;
err = mutex_lock_interruptible(&ab->access_mutex);
if (err)
return err;
if (bitmask == 0xFF)
buf = bitvalues;
else {
err = db5500_prcmu_abb_read(bankinfo[bank].slave_addr,
reg, &buf, 1);
if (err)
return err;
buf = ((~bitmask & buf) | (bitmask & bitvalues));
}
err = db5500_prcmu_abb_write(bankinfo[bank].slave_addr, reg,
&buf, 1);
mutex_unlock(&ab->access_mutex);
}
return err;
}
static int
set_register_interruptible(struct ab5500 *ab, u8 bank, u8 reg, u8 value)
{
return ab5500_mask_and_set_register_interruptible_raw(ab, bank, reg,
0xff, value);
}
static const struct ab5500_i2c_ranges *get_bankref(u8 devid, u8 bank)
{
u8 i;
if (devid < AB5500_NUM_DEVICES) {
for (i = 0; i < ab5500_bank_ranges[devid].nbanks; i++) {
if (ab5500_bank_ranges[devid].bank[i].bankid == bank)
return &ab5500_bank_ranges[devid].bank[i];
}
}
return NULL;
}
static bool page_write_allowed(u8 devid, u8 bank, u8 first_reg, u8 last_reg)
{
u8 i;
const struct ab5500_i2c_ranges *bankref;
bankref = get_bankref(devid, bank);
if (bankref == NULL || last_reg < first_reg)
return false;
for (i = 0; i < bankref->nranges; i++) {
if (first_reg < bankref->range[i].first)
break;
if ((last_reg <= bankref->range[i].last) &&
(bankref->range[i].perm & AB5500_PERM_WR))
return true;
}
return false;
}
static bool reg_write_allowed(u8 devid, u8 bank, u8 reg)
{
return page_write_allowed(devid, bank, reg, reg);
}
static bool page_read_allowed(u8 devid, u8 bank, u8 first_reg, u8 last_reg)
{
u8 i;
const struct ab5500_i2c_ranges *bankref;
bankref = get_bankref(devid, bank);
if (bankref == NULL || last_reg < first_reg)
return false;
for (i = 0; i < bankref->nranges; i++) {
if (first_reg < bankref->range[i].first)
return false;
if (first_reg <= bankref->range[i].last)
break;
}
while ((i < bankref->nranges) &&
(bankref->range[i].perm & AB5500_PERM_RD)) {
if (last_reg <= bankref->range[i].last)
return true;
if ((++i >= bankref->nranges) ||
(bankref->range[i].first !=
(bankref->range[i - 1].last + 1))) {
break;
}
}
return false;
}
static bool reg_read_allowed(u8 devid, u8 bank, u8 reg)
{
return page_read_allowed(devid, bank, reg, reg);
}
static int ab5500_get_chip_id(struct device *dev)
{
struct ab5500 *ab = dev_get_drvdata(dev->parent);
return (int)ab->chip_id;
}
static int ab5500_mask_and_set_register_interruptible(struct device *dev,
u8 bank, u8 reg, u8 bitmask, u8 bitvalues)
{
struct ab5500 *ab;
struct platform_device *pdev = to_platform_device(dev);
if ((AB5500_NUM_BANKS <= bank) ||
!reg_write_allowed(pdev->id, bank, reg))
return -EINVAL;
ab = dev_get_drvdata(dev->parent);
return ab5500_mask_and_set_register_interruptible_raw(ab, bank, reg,
bitmask, bitvalues);
}
static int ab5500_set_register_interruptible(struct device *dev, u8 bank,
u8 reg, u8 value)
{
return ab5500_mask_and_set_register_interruptible(dev, bank, reg, 0xFF,
value);
}
static int ab5500_get_register_interruptible(struct device *dev, u8 bank,
u8 reg, u8 *value)
{
struct ab5500 *ab;
struct platform_device *pdev = to_platform_device(dev);
if ((AB5500_NUM_BANKS <= bank) ||
!reg_read_allowed(pdev->id, bank, reg))
return -EINVAL;
ab = dev_get_drvdata(dev->parent);
return ab5500_get_register_interruptible_raw(ab, bank, reg, value);
}
static int ab5500_get_register_page_interruptible(struct device *dev, u8 bank,
u8 first_reg, u8 *regvals, u8 numregs)
{
struct ab5500 *ab;
struct platform_device *pdev = to_platform_device(dev);
if ((AB5500_NUM_BANKS <= bank) ||
!page_read_allowed(pdev->id, bank,
first_reg, (first_reg + numregs - 1)))
return -EINVAL;
ab = dev_get_drvdata(dev->parent);
return get_register_page_interruptible(ab, bank, first_reg, regvals,
numregs);
}
static int
ab5500_event_registers_startup_state_get(struct device *dev, u8 *event)
{
struct ab5500 *ab;
ab = dev_get_drvdata(dev->parent);
if (!ab->startup_events_read)
return -EAGAIN;
memcpy(event, ab->startup_events, AB5500_NUM_EVENT_REG);
return 0;
}
static int __init ab5500_setup(struct ab5500 *ab,
struct abx500_init_settings *settings, unsigned int size)
{
int err = 0;
int i;
for (i = 0; i < size; i++) {
err = ab5500_mask_and_set_register_interruptible_raw(ab,
settings[i].bank,
settings[i].reg,
0xFF, settings[i].setting);
if (err)
goto exit_no_setup;
if ((settings[i].bank == AB5500_BANK_IT) &&
(AB5500_MASK_BASE <= settings[i].reg) &&
(settings[i].reg <= AB5500_MASK_END)) {
ab->mask[settings[i].reg - AB5500_MASK_BASE] =
settings[i].setting;
}
}
exit_no_setup:
return err;
}
static int __init ab5500_probe(struct platform_device *pdev)
{
struct ab5500 *ab;
struct ab5500_platform_data *ab5500_plf_data =
pdev->dev.platform_data;
int err;
int i;
ab = kzalloc(sizeof(struct ab5500), GFP_KERNEL);
if (!ab) {
dev_err(&pdev->dev,
"could not allocate ab5500 device\n");
return -ENOMEM;
}
mutex_init(&ab->access_mutex);
mutex_init(&ab->irq_lock);
ab->dev = &pdev->dev;
platform_set_drvdata(pdev, ab);
err = ab5500_get_register_interruptible_raw(ab,
AB5500_BANK_VIT_IO_I2C_CLK_TST_OTP,
AB5500_CHIP_ID, &ab->chip_id);
if (err) {
dev_err(&pdev->dev, "could not communicate with the analog "
"baseband chip\n");
goto exit_no_detect;
}
for (i = 0; ids[i].id != 0x0; i++) {
if (ids[i].id == ab->chip_id) {
snprintf(&ab->chip_name[0], sizeof(ab->chip_name) - 1,
"AB5500 %s", ids[i].name);
break;
}
}
if (ids[i].id == 0x0) {
dev_err(&pdev->dev, "unknown analog baseband chip id: 0x%x\n",
ab->chip_id);
dev_err(&pdev->dev, "driver not started!\n");
goto exit_no_detect;
}
for (i = 0; i < AB5500_NUM_IRQ_REGS; i++) {
u8 latchreg = AB5500_IT_LATCH0_REG + i;
u8 maskreg = AB5500_IT_MASK0_REG + i;
u8 val;
ab5500_get_register_interruptible_raw(ab, AB5500_BANK_IT,
latchreg, &val);
set_register_interruptible(ab, AB5500_BANK_IT, maskreg, 0xff);
ab->mask[i] = ab->oldmask[i] = 0xff;
}
err = abx500_register_ops(&pdev->dev, &ab5500_ops);
if (err) {
dev_err(&pdev->dev, "ab5500_register ops error\n");
goto exit_no_detect;
}
for (i = 0; i < AB5500_NUM_DEVICES; i++) {
ab5500_devs[i].platform_data = ab5500_plf_data->dev_data[i];
ab5500_devs[i].pdata_size =
sizeof(ab5500_plf_data->dev_data[i]);
}
err = mfd_add_devices(&pdev->dev, 0, ab5500_devs,
ARRAY_SIZE(ab5500_devs), NULL,
ab5500_plf_data->irq.base);
if (err) {
dev_err(&pdev->dev, "ab5500_mfd_add_device error\n");
goto exit_no_detect;
}
err = ab5500_setup(ab, ab5500_plf_data->init_settings,
ab5500_plf_data->init_settings_sz);
if (err) {
dev_err(&pdev->dev, "ab5500_setup error\n");
goto exit_no_detect;
}
ab5500_setup_debugfs(ab);
dev_info(&pdev->dev, "detected AB chip: %s\n", &ab->chip_name[0]);
return 0;
exit_no_detect:
kfree(ab);
return err;
}
static int __exit ab5500_remove(struct platform_device *pdev)
{
struct ab5500 *ab = platform_get_drvdata(pdev);
ab5500_remove_debugfs();
mfd_remove_devices(&pdev->dev);
kfree(ab);
return 0;
}
static int __init ab5500_core_init(void)
{
return platform_driver_probe(&ab5500_driver, ab5500_probe);
}
static void __exit ab5500_core_exit(void)
{
platform_driver_unregister(&ab5500_driver);
}
