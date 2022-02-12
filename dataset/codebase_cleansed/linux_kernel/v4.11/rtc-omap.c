static inline u8 rtc_read(struct omap_rtc *rtc, unsigned int reg)
{
return readb(rtc->base + reg);
}
static inline u32 rtc_readl(struct omap_rtc *rtc, unsigned int reg)
{
return readl(rtc->base + reg);
}
static inline void rtc_write(struct omap_rtc *rtc, unsigned int reg, u8 val)
{
writeb(val, rtc->base + reg);
}
static inline void rtc_writel(struct omap_rtc *rtc, unsigned int reg, u32 val)
{
writel(val, rtc->base + reg);
}
static void am3352_rtc_unlock(struct omap_rtc *rtc)
{
rtc_writel(rtc, OMAP_RTC_KICK0_REG, KICK0_VALUE);
rtc_writel(rtc, OMAP_RTC_KICK1_REG, KICK1_VALUE);
}
static void am3352_rtc_lock(struct omap_rtc *rtc)
{
rtc_writel(rtc, OMAP_RTC_KICK0_REG, 0);
rtc_writel(rtc, OMAP_RTC_KICK1_REG, 0);
}
static void default_rtc_unlock(struct omap_rtc *rtc)
{
}
static void default_rtc_lock(struct omap_rtc *rtc)
{
}
static void rtc_wait_not_busy(struct omap_rtc *rtc)
{
int count;
u8 status;
for (count = 0; count < 50; count++) {
status = rtc_read(rtc, OMAP_RTC_STATUS_REG);
if (!(status & OMAP_RTC_STATUS_BUSY))
break;
udelay(1);
}
}
static irqreturn_t rtc_irq(int irq, void *dev_id)
{
struct omap_rtc *rtc = dev_id;
unsigned long events = 0;
u8 irq_data;
irq_data = rtc_read(rtc, OMAP_RTC_STATUS_REG);
if (irq_data & OMAP_RTC_STATUS_ALARM) {
rtc->type->unlock(rtc);
rtc_write(rtc, OMAP_RTC_STATUS_REG, OMAP_RTC_STATUS_ALARM);
rtc->type->lock(rtc);
events |= RTC_IRQF | RTC_AF;
}
if (irq_data & OMAP_RTC_STATUS_1S_EVENT)
events |= RTC_IRQF | RTC_UF;
rtc_update_irq(rtc->rtc, 1, events);
return IRQ_HANDLED;
}
static int omap_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
u8 reg, irqwake_reg = 0;
local_irq_disable();
rtc_wait_not_busy(rtc);
reg = rtc_read(rtc, OMAP_RTC_INTERRUPTS_REG);
if (rtc->type->has_irqwakeen)
irqwake_reg = rtc_read(rtc, OMAP_RTC_IRQWAKEEN);
if (enabled) {
reg |= OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg |= OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
} else {
reg &= ~OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg &= ~OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
}
rtc_wait_not_busy(rtc);
rtc->type->unlock(rtc);
rtc_write(rtc, OMAP_RTC_INTERRUPTS_REG, reg);
if (rtc->type->has_irqwakeen)
rtc_write(rtc, OMAP_RTC_IRQWAKEEN, irqwake_reg);
rtc->type->lock(rtc);
local_irq_enable();
return 0;
}
static int tm2bcd(struct rtc_time *tm)
{
if (rtc_valid_tm(tm) != 0)
return -EINVAL;
tm->tm_sec = bin2bcd(tm->tm_sec);
tm->tm_min = bin2bcd(tm->tm_min);
tm->tm_hour = bin2bcd(tm->tm_hour);
tm->tm_mday = bin2bcd(tm->tm_mday);
tm->tm_mon = bin2bcd(tm->tm_mon + 1);
if (tm->tm_year < 100 || tm->tm_year > 199)
return -EINVAL;
tm->tm_year = bin2bcd(tm->tm_year - 100);
return 0;
}
static void bcd2tm(struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(tm->tm_sec);
tm->tm_min = bcd2bin(tm->tm_min);
tm->tm_hour = bcd2bin(tm->tm_hour);
tm->tm_mday = bcd2bin(tm->tm_mday);
tm->tm_mon = bcd2bin(tm->tm_mon) - 1;
tm->tm_year = bcd2bin(tm->tm_year) + 100;
}
static void omap_rtc_read_time_raw(struct omap_rtc *rtc, struct rtc_time *tm)
{
tm->tm_sec = rtc_read(rtc, OMAP_RTC_SECONDS_REG);
tm->tm_min = rtc_read(rtc, OMAP_RTC_MINUTES_REG);
tm->tm_hour = rtc_read(rtc, OMAP_RTC_HOURS_REG);
tm->tm_mday = rtc_read(rtc, OMAP_RTC_DAYS_REG);
tm->tm_mon = rtc_read(rtc, OMAP_RTC_MONTHS_REG);
tm->tm_year = rtc_read(rtc, OMAP_RTC_YEARS_REG);
}
static int omap_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
local_irq_disable();
rtc_wait_not_busy(rtc);
omap_rtc_read_time_raw(rtc, tm);
local_irq_enable();
bcd2tm(tm);
return 0;
}
static int omap_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
if (tm2bcd(tm) < 0)
return -EINVAL;
local_irq_disable();
rtc_wait_not_busy(rtc);
rtc->type->unlock(rtc);
rtc_write(rtc, OMAP_RTC_YEARS_REG, tm->tm_year);
rtc_write(rtc, OMAP_RTC_MONTHS_REG, tm->tm_mon);
rtc_write(rtc, OMAP_RTC_DAYS_REG, tm->tm_mday);
rtc_write(rtc, OMAP_RTC_HOURS_REG, tm->tm_hour);
rtc_write(rtc, OMAP_RTC_MINUTES_REG, tm->tm_min);
rtc_write(rtc, OMAP_RTC_SECONDS_REG, tm->tm_sec);
rtc->type->lock(rtc);
local_irq_enable();
return 0;
}
static int omap_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
u8 interrupts;
local_irq_disable();
rtc_wait_not_busy(rtc);
alm->time.tm_sec = rtc_read(rtc, OMAP_RTC_ALARM_SECONDS_REG);
alm->time.tm_min = rtc_read(rtc, OMAP_RTC_ALARM_MINUTES_REG);
alm->time.tm_hour = rtc_read(rtc, OMAP_RTC_ALARM_HOURS_REG);
alm->time.tm_mday = rtc_read(rtc, OMAP_RTC_ALARM_DAYS_REG);
alm->time.tm_mon = rtc_read(rtc, OMAP_RTC_ALARM_MONTHS_REG);
alm->time.tm_year = rtc_read(rtc, OMAP_RTC_ALARM_YEARS_REG);
local_irq_enable();
bcd2tm(&alm->time);
interrupts = rtc_read(rtc, OMAP_RTC_INTERRUPTS_REG);
alm->enabled = !!(interrupts & OMAP_RTC_INTERRUPTS_IT_ALARM);
return 0;
}
static int omap_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
u8 reg, irqwake_reg = 0;
if (tm2bcd(&alm->time) < 0)
return -EINVAL;
local_irq_disable();
rtc_wait_not_busy(rtc);
rtc->type->unlock(rtc);
rtc_write(rtc, OMAP_RTC_ALARM_YEARS_REG, alm->time.tm_year);
rtc_write(rtc, OMAP_RTC_ALARM_MONTHS_REG, alm->time.tm_mon);
rtc_write(rtc, OMAP_RTC_ALARM_DAYS_REG, alm->time.tm_mday);
rtc_write(rtc, OMAP_RTC_ALARM_HOURS_REG, alm->time.tm_hour);
rtc_write(rtc, OMAP_RTC_ALARM_MINUTES_REG, alm->time.tm_min);
rtc_write(rtc, OMAP_RTC_ALARM_SECONDS_REG, alm->time.tm_sec);
reg = rtc_read(rtc, OMAP_RTC_INTERRUPTS_REG);
if (rtc->type->has_irqwakeen)
irqwake_reg = rtc_read(rtc, OMAP_RTC_IRQWAKEEN);
if (alm->enabled) {
reg |= OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg |= OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
} else {
reg &= ~OMAP_RTC_INTERRUPTS_IT_ALARM;
irqwake_reg &= ~OMAP_RTC_IRQWAKEEN_ALARM_WAKEEN;
}
rtc_write(rtc, OMAP_RTC_INTERRUPTS_REG, reg);
if (rtc->type->has_irqwakeen)
rtc_write(rtc, OMAP_RTC_IRQWAKEEN, irqwake_reg);
rtc->type->lock(rtc);
local_irq_enable();
return 0;
}
static void omap_rtc_power_off(void)
{
struct omap_rtc *rtc = omap_rtc_power_off_rtc;
struct rtc_time tm;
unsigned long now;
u32 val;
rtc->type->unlock(rtc);
val = rtc_readl(rtc, OMAP_RTC_PMIC_REG);
rtc_writel(rtc, OMAP_RTC_PMIC_REG, val | OMAP_RTC_PMIC_POWER_EN_EN);
omap_rtc_read_time_raw(rtc, &tm);
bcd2tm(&tm);
rtc_tm_to_time(&tm, &now);
rtc_time_to_tm(now + 2, &tm);
if (tm2bcd(&tm) < 0) {
dev_err(&rtc->rtc->dev, "power off failed\n");
return;
}
rtc_wait_not_busy(rtc);
rtc_write(rtc, OMAP_RTC_ALARM2_SECONDS_REG, tm.tm_sec);
rtc_write(rtc, OMAP_RTC_ALARM2_MINUTES_REG, tm.tm_min);
rtc_write(rtc, OMAP_RTC_ALARM2_HOURS_REG, tm.tm_hour);
rtc_write(rtc, OMAP_RTC_ALARM2_DAYS_REG, tm.tm_mday);
rtc_write(rtc, OMAP_RTC_ALARM2_MONTHS_REG, tm.tm_mon);
rtc_write(rtc, OMAP_RTC_ALARM2_YEARS_REG, tm.tm_year);
val = rtc_read(rtc, OMAP_RTC_INTERRUPTS_REG);
rtc_writel(rtc, OMAP_RTC_INTERRUPTS_REG,
val | OMAP_RTC_INTERRUPTS_IT_ALARM2);
rtc->type->lock(rtc);
mdelay(2500);
}
static int rtc_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
return 0;
}
static const char *rtc_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
return NULL;
}
static int rtc_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct omap_rtc *rtc = pinctrl_dev_get_drvdata(pctldev);
unsigned int param = pinconf_to_config_param(*config);
u32 val;
u16 arg = 0;
rtc->type->unlock(rtc);
val = rtc_readl(rtc, OMAP_RTC_PMIC_REG);
rtc->type->lock(rtc);
switch (param) {
case PIN_CONFIG_INPUT_ENABLE:
if (!(val & OMAP_RTC_PMIC_EXT_WKUP_EN(pin)))
return -EINVAL;
break;
case PIN_CONFIG_ACTIVE_HIGH:
if (val & OMAP_RTC_PMIC_EXT_WKUP_POL(pin))
return -EINVAL;
break;
default:
return -ENOTSUPP;
};
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int rtc_pinconf_set(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *configs,
unsigned int num_configs)
{
struct omap_rtc *rtc = pinctrl_dev_get_drvdata(pctldev);
u32 val;
unsigned int param;
u32 param_val;
int i;
rtc->type->unlock(rtc);
val = rtc_readl(rtc, OMAP_RTC_PMIC_REG);
rtc->type->lock(rtc);
val |= OMAP_RTC_PMIC_EXT_WKUP_POL(pin);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
param_val = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_INPUT_ENABLE:
if (param_val)
val |= OMAP_RTC_PMIC_EXT_WKUP_EN(pin);
else
val &= ~OMAP_RTC_PMIC_EXT_WKUP_EN(pin);
break;
case PIN_CONFIG_ACTIVE_HIGH:
val &= ~OMAP_RTC_PMIC_EXT_WKUP_POL(pin);
break;
default:
dev_err(&rtc->rtc->dev, "Property %u not supported\n",
param);
return -ENOTSUPP;
}
}
rtc->type->unlock(rtc);
rtc_writel(rtc, OMAP_RTC_PMIC_REG, val);
rtc->type->lock(rtc);
return 0;
}
static int omap_rtc_probe(struct platform_device *pdev)
{
struct omap_rtc *rtc;
struct resource *res;
u8 reg, mask, new_ctrl;
const struct platform_device_id *id_entry;
const struct of_device_id *of_id;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
of_id = of_match_device(omap_rtc_of_match, &pdev->dev);
if (of_id) {
rtc->type = of_id->data;
rtc->is_pmic_controller = rtc->type->has_pmic_mode &&
of_property_read_bool(pdev->dev.of_node,
"system-power-controller");
} else {
id_entry = platform_get_device_id(pdev);
rtc->type = (void *)id_entry->driver_data;
}
rtc->irq_timer = platform_get_irq(pdev, 0);
if (rtc->irq_timer <= 0)
return -ENOENT;
rtc->irq_alarm = platform_get_irq(pdev, 1);
if (rtc->irq_alarm <= 0)
return -ENOENT;
rtc->clk = devm_clk_get(&pdev->dev, "ext-clk");
if (!IS_ERR(rtc->clk))
rtc->has_ext_clk = true;
else
rtc->clk = devm_clk_get(&pdev->dev, "int-clk");
if (!IS_ERR(rtc->clk))
clk_prepare_enable(rtc->clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rtc->base))
return PTR_ERR(rtc->base);
platform_set_drvdata(pdev, rtc);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
rtc->type->unlock(rtc);
rtc_writel(rtc, OMAP_RTC_INTERRUPTS_REG, 0);
if (rtc->type->has_32kclk_en) {
reg = rtc_read(rtc, OMAP_RTC_OSC_REG);
rtc_writel(rtc, OMAP_RTC_OSC_REG,
reg | OMAP_RTC_OSC_32KCLK_EN);
}
reg = rtc_read(rtc, OMAP_RTC_STATUS_REG);
mask = OMAP_RTC_STATUS_ALARM;
if (rtc->type->has_pmic_mode)
mask |= OMAP_RTC_STATUS_ALARM2;
if (rtc->type->has_power_up_reset) {
mask |= OMAP_RTC_STATUS_POWER_UP;
if (reg & OMAP_RTC_STATUS_POWER_UP)
dev_info(&pdev->dev, "RTC power up reset detected\n");
}
if (reg & mask)
rtc_write(rtc, OMAP_RTC_STATUS_REG, reg & mask);
reg = rtc_read(rtc, OMAP_RTC_CTRL_REG);
if (reg & OMAP_RTC_CTRL_STOP)
dev_info(&pdev->dev, "already running\n");
new_ctrl = reg & (OMAP_RTC_CTRL_SPLIT | OMAP_RTC_CTRL_AUTO_COMP);
new_ctrl |= OMAP_RTC_CTRL_STOP;
if (new_ctrl & OMAP_RTC_CTRL_SPLIT)
dev_info(&pdev->dev, "split power mode\n");
if (reg != new_ctrl)
rtc_write(rtc, OMAP_RTC_CTRL_REG, new_ctrl);
if (rtc->has_ext_clk) {
reg = rtc_read(rtc, OMAP_RTC_OSC_REG);
reg &= ~OMAP_RTC_OSC_OSC32K_GZ_DISABLE;
reg |= OMAP_RTC_OSC_32KCLK_EN | OMAP_RTC_OSC_SEL_32KCLK_SRC;
rtc_writel(rtc, OMAP_RTC_OSC_REG, reg);
}
rtc->type->lock(rtc);
device_init_wakeup(&pdev->dev, true);
rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&omap_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
ret = PTR_ERR(rtc->rtc);
goto err;
}
ret = devm_request_irq(&pdev->dev, rtc->irq_timer, rtc_irq, 0,
dev_name(&rtc->rtc->dev), rtc);
if (ret)
goto err;
if (rtc->irq_timer != rtc->irq_alarm) {
ret = devm_request_irq(&pdev->dev, rtc->irq_alarm, rtc_irq, 0,
dev_name(&rtc->rtc->dev), rtc);
if (ret)
goto err;
}
if (rtc->is_pmic_controller) {
if (!pm_power_off) {
omap_rtc_power_off_rtc = rtc;
pm_power_off = omap_rtc_power_off;
}
}
rtc_pinctrl_desc.name = dev_name(&pdev->dev);
rtc->pctldev = pinctrl_register(&rtc_pinctrl_desc, &pdev->dev, rtc);
if (IS_ERR(rtc->pctldev)) {
dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
return PTR_ERR(rtc->pctldev);
}
return 0;
err:
device_init_wakeup(&pdev->dev, false);
rtc->type->lock(rtc);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int __exit omap_rtc_remove(struct platform_device *pdev)
{
struct omap_rtc *rtc = platform_get_drvdata(pdev);
u8 reg;
if (pm_power_off == omap_rtc_power_off &&
omap_rtc_power_off_rtc == rtc) {
pm_power_off = NULL;
omap_rtc_power_off_rtc = NULL;
}
device_init_wakeup(&pdev->dev, 0);
if (!IS_ERR(rtc->clk))
clk_disable_unprepare(rtc->clk);
rtc->type->unlock(rtc);
rtc_write(rtc, OMAP_RTC_INTERRUPTS_REG, 0);
if (rtc->has_ext_clk) {
reg = rtc_read(rtc, OMAP_RTC_OSC_REG);
reg &= ~OMAP_RTC_OSC_SEL_32KCLK_SRC;
rtc_write(rtc, OMAP_RTC_OSC_REG, reg);
}
rtc->type->lock(rtc);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
pinctrl_unregister(rtc->pctldev);
return 0;
}
static int omap_rtc_suspend(struct device *dev)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
rtc->interrupts_reg = rtc_read(rtc, OMAP_RTC_INTERRUPTS_REG);
rtc->type->unlock(rtc);
if (device_may_wakeup(dev))
enable_irq_wake(rtc->irq_alarm);
else
rtc_write(rtc, OMAP_RTC_INTERRUPTS_REG, 0);
rtc->type->lock(rtc);
rtc->is_suspending = true;
return 0;
}
static int omap_rtc_resume(struct device *dev)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
rtc->type->unlock(rtc);
if (device_may_wakeup(dev))
disable_irq_wake(rtc->irq_alarm);
else
rtc_write(rtc, OMAP_RTC_INTERRUPTS_REG, rtc->interrupts_reg);
rtc->type->lock(rtc);
rtc->is_suspending = false;
return 0;
}
static int omap_rtc_runtime_suspend(struct device *dev)
{
struct omap_rtc *rtc = dev_get_drvdata(dev);
if (rtc->is_suspending && !rtc->has_ext_clk)
return -EBUSY;
return 0;
}
static int omap_rtc_runtime_resume(struct device *dev)
{
return 0;
}
static void omap_rtc_shutdown(struct platform_device *pdev)
{
struct omap_rtc *rtc = platform_get_drvdata(pdev);
u8 mask;
rtc->type->unlock(rtc);
mask = rtc_read(rtc, OMAP_RTC_INTERRUPTS_REG);
mask &= OMAP_RTC_INTERRUPTS_IT_ALARM;
rtc_write(rtc, OMAP_RTC_INTERRUPTS_REG, mask);
rtc->type->lock(rtc);
}
