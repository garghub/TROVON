static inline int usb3613_hub_mode_ctrl(bool unused)
{
return 0;
}
static void arche_platform_set_state(struct arche_platform_drvdata *arche_pdata,
enum arche_platform_state state)
{
arche_pdata->state = state;
}
static void arche_platform_set_wake_detect_state(
struct arche_platform_drvdata *arche_pdata,
enum svc_wakedetect_state state)
{
arche_pdata->wake_detect_state = state;
}
static inline void svc_reset_onoff(unsigned int gpio, bool onoff)
{
gpio_set_value(gpio, onoff);
}
static int apb_cold_boot(struct device *dev, void *data)
{
int ret;
ret = apb_ctrl_coldboot(dev);
if (ret)
dev_warn(dev, "failed to coldboot\n");
return 0;
}
static int apb_poweroff(struct device *dev, void *data)
{
apb_ctrl_poweroff(dev);
if (usb3613_hub_mode_ctrl(false))
dev_warn(dev, "failed to control hub device\n");
return 0;
}
static void arche_platform_wd_irq_en(struct arche_platform_drvdata *arche_pdata)
{
gpio_direction_input(arche_pdata->wake_detect_gpio);
enable_irq(arche_pdata->wake_detect_irq);
}
static irqreturn_t arche_platform_wd_irq_thread(int irq, void *devid)
{
struct arche_platform_drvdata *arche_pdata = devid;
unsigned long flags;
spin_lock_irqsave(&arche_pdata->wake_lock, flags);
if (arche_pdata->wake_detect_state != WD_STATE_COLDBOOT_TRIG) {
spin_unlock_irqrestore(&arche_pdata->wake_lock, flags);
return IRQ_HANDLED;
}
arche_platform_set_wake_detect_state(arche_pdata,
WD_STATE_COLDBOOT_START);
spin_unlock_irqrestore(&arche_pdata->wake_lock, flags);
device_for_each_child(arche_pdata->dev, NULL, apb_poweroff);
device_for_each_child(arche_pdata->dev, NULL, apb_cold_boot);
if (usb3613_hub_mode_ctrl(true))
dev_warn(arche_pdata->dev, "failed to control hub device\n");
spin_lock_irqsave(&arche_pdata->wake_lock, flags);
arche_platform_set_wake_detect_state(arche_pdata, WD_STATE_IDLE);
spin_unlock_irqrestore(&arche_pdata->wake_lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t arche_platform_wd_irq(int irq, void *devid)
{
struct arche_platform_drvdata *arche_pdata = devid;
unsigned long flags;
spin_lock_irqsave(&arche_pdata->wake_lock, flags);
if (gpio_get_value(arche_pdata->wake_detect_gpio)) {
if (arche_pdata->wake_detect_state == WD_STATE_BOOT_INIT) {
if (time_before(jiffies,
arche_pdata->wake_detect_start +
msecs_to_jiffies(WD_COLDBOOT_PULSE_WIDTH_MS))) {
arche_platform_set_wake_detect_state(arche_pdata,
WD_STATE_IDLE);
} else {
if (arche_pdata->wake_detect_state !=
WD_STATE_COLDBOOT_START) {
arche_platform_set_wake_detect_state(arche_pdata,
WD_STATE_COLDBOOT_TRIG);
spin_unlock_irqrestore(
&arche_pdata->wake_lock,
flags);
return IRQ_WAKE_THREAD;
}
}
}
} else {
if (arche_pdata->wake_detect_state == WD_STATE_IDLE) {
arche_pdata->wake_detect_start = jiffies;
arche_platform_set_wake_detect_state(arche_pdata,
WD_STATE_BOOT_INIT);
}
}
spin_unlock_irqrestore(&arche_pdata->wake_lock, flags);
return IRQ_HANDLED;
}
static int
arche_platform_coldboot_seq(struct arche_platform_drvdata *arche_pdata)
{
int ret;
if (arche_pdata->state == ARCHE_PLATFORM_STATE_ACTIVE)
return 0;
dev_info(arche_pdata->dev, "Booting from cold boot state\n");
svc_reset_onoff(arche_pdata->svc_reset_gpio,
arche_pdata->is_reset_act_hi);
gpio_set_value(arche_pdata->svc_sysboot_gpio, 0);
usleep_range(100, 200);
ret = clk_prepare_enable(arche_pdata->svc_ref_clk);
if (ret) {
dev_err(arche_pdata->dev, "failed to enable svc_ref_clk: %d\n",
ret);
return ret;
}
svc_reset_onoff(arche_pdata->svc_reset_gpio,
!arche_pdata->is_reset_act_hi);
arche_platform_set_state(arche_pdata, ARCHE_PLATFORM_STATE_ACTIVE);
return 0;
}
static int
arche_platform_fw_flashing_seq(struct arche_platform_drvdata *arche_pdata)
{
int ret;
if (arche_pdata->state == ARCHE_PLATFORM_STATE_FW_FLASHING)
return 0;
dev_info(arche_pdata->dev, "Switching to FW flashing state\n");
svc_reset_onoff(arche_pdata->svc_reset_gpio,
arche_pdata->is_reset_act_hi);
gpio_set_value(arche_pdata->svc_sysboot_gpio, 1);
usleep_range(100, 200);
ret = clk_prepare_enable(arche_pdata->svc_ref_clk);
if (ret) {
dev_err(arche_pdata->dev, "failed to enable svc_ref_clk: %d\n",
ret);
return ret;
}
svc_reset_onoff(arche_pdata->svc_reset_gpio,
!arche_pdata->is_reset_act_hi);
arche_platform_set_state(arche_pdata, ARCHE_PLATFORM_STATE_FW_FLASHING);
return 0;
}
static void
arche_platform_poweroff_seq(struct arche_platform_drvdata *arche_pdata)
{
unsigned long flags;
if (arche_pdata->state == ARCHE_PLATFORM_STATE_OFF)
return;
if (arche_pdata->state != ARCHE_PLATFORM_STATE_FW_FLASHING) {
disable_irq(arche_pdata->wake_detect_irq);
spin_lock_irqsave(&arche_pdata->wake_lock, flags);
arche_platform_set_wake_detect_state(arche_pdata,
WD_STATE_IDLE);
spin_unlock_irqrestore(&arche_pdata->wake_lock, flags);
}
clk_disable_unprepare(arche_pdata->svc_ref_clk);
svc_reset_onoff(arche_pdata->svc_reset_gpio,
arche_pdata->is_reset_act_hi);
arche_platform_set_state(arche_pdata, ARCHE_PLATFORM_STATE_OFF);
}
static ssize_t state_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct arche_platform_drvdata *arche_pdata = platform_get_drvdata(pdev);
int ret = 0;
mutex_lock(&arche_pdata->platform_state_mutex);
if (sysfs_streq(buf, "off")) {
if (arche_pdata->state == ARCHE_PLATFORM_STATE_OFF)
goto exit;
device_for_each_child(arche_pdata->dev, NULL, apb_poweroff);
arche_platform_poweroff_seq(arche_pdata);
} else if (sysfs_streq(buf, "active")) {
if (arche_pdata->state == ARCHE_PLATFORM_STATE_ACTIVE)
goto exit;
device_for_each_child(arche_pdata->dev, NULL, apb_poweroff);
arche_platform_poweroff_seq(arche_pdata);
arche_platform_wd_irq_en(arche_pdata);
ret = arche_platform_coldboot_seq(arche_pdata);
if (ret)
goto exit;
} else if (sysfs_streq(buf, "standby")) {
if (arche_pdata->state == ARCHE_PLATFORM_STATE_STANDBY)
goto exit;
dev_warn(arche_pdata->dev, "standby state not supported\n");
} else if (sysfs_streq(buf, "fw_flashing")) {
if (arche_pdata->state == ARCHE_PLATFORM_STATE_FW_FLASHING)
goto exit;
arche_platform_poweroff_seq(arche_pdata);
ret = arche_platform_fw_flashing_seq(arche_pdata);
if (ret)
goto exit;
} else {
dev_err(arche_pdata->dev, "unknown state\n");
ret = -EINVAL;
}
exit:
mutex_unlock(&arche_pdata->platform_state_mutex);
return ret ? ret : count;
}
static ssize_t state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct arche_platform_drvdata *arche_pdata = dev_get_drvdata(dev);
switch (arche_pdata->state) {
case ARCHE_PLATFORM_STATE_OFF:
return sprintf(buf, "off\n");
case ARCHE_PLATFORM_STATE_ACTIVE:
return sprintf(buf, "active\n");
case ARCHE_PLATFORM_STATE_STANDBY:
return sprintf(buf, "standby\n");
case ARCHE_PLATFORM_STATE_FW_FLASHING:
return sprintf(buf, "fw_flashing\n");
default:
return sprintf(buf, "unknown state\n");
}
}
static int arche_platform_pm_notifier(struct notifier_block *notifier,
unsigned long pm_event, void *unused)
{
struct arche_platform_drvdata *arche_pdata =
container_of(notifier, struct arche_platform_drvdata,
pm_notifier);
int ret = NOTIFY_DONE;
mutex_lock(&arche_pdata->platform_state_mutex);
switch (pm_event) {
case PM_SUSPEND_PREPARE:
if (arche_pdata->state != ARCHE_PLATFORM_STATE_ACTIVE) {
ret = NOTIFY_STOP;
break;
}
device_for_each_child(arche_pdata->dev, NULL, apb_poweroff);
arche_platform_poweroff_seq(arche_pdata);
break;
case PM_POST_SUSPEND:
if (arche_pdata->state != ARCHE_PLATFORM_STATE_OFF)
break;
arche_platform_wd_irq_en(arche_pdata);
arche_platform_coldboot_seq(arche_pdata);
break;
default:
break;
}
mutex_unlock(&arche_pdata->platform_state_mutex);
return ret;
}
static int arche_platform_probe(struct platform_device *pdev)
{
struct arche_platform_drvdata *arche_pdata;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
int ret;
arche_pdata = devm_kzalloc(&pdev->dev, sizeof(*arche_pdata),
GFP_KERNEL);
if (!arche_pdata)
return -ENOMEM;
arche_pdata->is_reset_act_hi = of_property_read_bool(np,
"svc,reset-active-high");
arche_pdata->svc_reset_gpio = of_get_named_gpio(np,
"svc,reset-gpio",
0);
if (arche_pdata->svc_reset_gpio < 0) {
dev_err(dev, "failed to get reset-gpio\n");
return arche_pdata->svc_reset_gpio;
}
ret = devm_gpio_request(dev, arche_pdata->svc_reset_gpio, "svc-reset");
if (ret) {
dev_err(dev, "failed to request svc-reset gpio:%d\n", ret);
return ret;
}
ret = gpio_direction_output(arche_pdata->svc_reset_gpio,
arche_pdata->is_reset_act_hi);
if (ret) {
dev_err(dev, "failed to set svc-reset gpio dir:%d\n", ret);
return ret;
}
arche_platform_set_state(arche_pdata, ARCHE_PLATFORM_STATE_OFF);
arche_pdata->svc_sysboot_gpio = of_get_named_gpio(np,
"svc,sysboot-gpio", 0);
if (arche_pdata->svc_sysboot_gpio < 0) {
dev_err(dev, "failed to get sysboot gpio\n");
return arche_pdata->svc_sysboot_gpio;
}
ret = devm_gpio_request(dev, arche_pdata->svc_sysboot_gpio, "sysboot0");
if (ret) {
dev_err(dev, "failed to request sysboot0 gpio:%d\n", ret);
return ret;
}
ret = gpio_direction_output(arche_pdata->svc_sysboot_gpio, 0);
if (ret) {
dev_err(dev, "failed to set svc-reset gpio dir:%d\n", ret);
return ret;
}
arche_pdata->svc_refclk_req = of_get_named_gpio(np,
"svc,refclk-req-gpio", 0);
if (arche_pdata->svc_refclk_req < 0) {
dev_err(dev, "failed to get svc clock-req gpio\n");
return arche_pdata->svc_refclk_req;
}
ret = devm_gpio_request(dev, arche_pdata->svc_refclk_req,
"svc-clk-req");
if (ret) {
dev_err(dev, "failed to request svc-clk-req gpio: %d\n", ret);
return ret;
}
ret = gpio_direction_input(arche_pdata->svc_refclk_req);
if (ret) {
dev_err(dev, "failed to set svc-clk-req gpio dir :%d\n", ret);
return ret;
}
arche_pdata->svc_ref_clk = devm_clk_get(dev, "svc_ref_clk");
if (IS_ERR(arche_pdata->svc_ref_clk)) {
ret = PTR_ERR(arche_pdata->svc_ref_clk);
dev_err(dev, "failed to get svc_ref_clk: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, arche_pdata);
arche_pdata->num_apbs = of_get_child_count(np);
dev_dbg(dev, "Number of APB's available - %d\n", arche_pdata->num_apbs);
arche_pdata->wake_detect_gpio = of_get_named_gpio(np,
"svc,wake-detect-gpio",
0);
if (arche_pdata->wake_detect_gpio < 0) {
dev_err(dev, "failed to get wake detect gpio\n");
return arche_pdata->wake_detect_gpio;
}
ret = devm_gpio_request(dev, arche_pdata->wake_detect_gpio,
"wake detect");
if (ret) {
dev_err(dev, "Failed requesting wake_detect gpio %d\n",
arche_pdata->wake_detect_gpio);
return ret;
}
arche_platform_set_wake_detect_state(arche_pdata, WD_STATE_IDLE);
arche_pdata->dev = &pdev->dev;
spin_lock_init(&arche_pdata->wake_lock);
mutex_init(&arche_pdata->platform_state_mutex);
arche_pdata->wake_detect_irq =
gpio_to_irq(arche_pdata->wake_detect_gpio);
ret = devm_request_threaded_irq(dev, arche_pdata->wake_detect_irq,
arche_platform_wd_irq,
arche_platform_wd_irq_thread,
IRQF_TRIGGER_FALLING |
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(dev), arche_pdata);
if (ret) {
dev_err(dev, "failed to request wake detect IRQ %d\n", ret);
return ret;
}
disable_irq(arche_pdata->wake_detect_irq);
ret = device_create_file(dev, &dev_attr_state);
if (ret) {
dev_err(dev, "failed to create state file in sysfs\n");
return ret;
}
ret = of_platform_populate(np, NULL, NULL, dev);
if (ret) {
dev_err(dev, "failed to populate child nodes %d\n", ret);
goto err_device_remove;
}
arche_pdata->pm_notifier.notifier_call = arche_platform_pm_notifier;
ret = register_pm_notifier(&arche_pdata->pm_notifier);
if (ret) {
dev_err(dev, "failed to register pm notifier %d\n", ret);
goto err_device_remove;
}
if (!of_property_read_bool(pdev->dev.of_node, "arche,init-off")) {
mutex_lock(&arche_pdata->platform_state_mutex);
ret = arche_platform_coldboot_seq(arche_pdata);
if (ret) {
dev_err(dev, "Failed to cold boot svc %d\n", ret);
goto err_coldboot;
}
arche_platform_wd_irq_en(arche_pdata);
mutex_unlock(&arche_pdata->platform_state_mutex);
}
dev_info(dev, "Device registered successfully\n");
return 0;
err_coldboot:
mutex_unlock(&arche_pdata->platform_state_mutex);
err_device_remove:
device_remove_file(&pdev->dev, &dev_attr_state);
return ret;
}
static int arche_remove_child(struct device *dev, void *unused)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static int arche_platform_remove(struct platform_device *pdev)
{
struct arche_platform_drvdata *arche_pdata = platform_get_drvdata(pdev);
unregister_pm_notifier(&arche_pdata->pm_notifier);
device_remove_file(&pdev->dev, &dev_attr_state);
device_for_each_child(&pdev->dev, NULL, arche_remove_child);
arche_platform_poweroff_seq(arche_pdata);
if (usb3613_hub_mode_ctrl(false))
dev_warn(arche_pdata->dev, "failed to control hub device\n");
return 0;
}
static __maybe_unused int arche_platform_suspend(struct device *dev)
{
return 0;
}
static __maybe_unused int arche_platform_resume(struct device *dev)
{
return 0;
}
static void arche_platform_shutdown(struct platform_device *pdev)
{
struct arche_platform_drvdata *arche_pdata = platform_get_drvdata(pdev);
arche_platform_poweroff_seq(arche_pdata);
usb3613_hub_mode_ctrl(false);
}
static int __init arche_init(void)
{
int retval;
retval = platform_driver_register(&arche_platform_device_driver);
if (retval)
return retval;
retval = arche_apb_init();
if (retval)
platform_driver_unregister(&arche_platform_device_driver);
return retval;
}
static void __exit arche_exit(void)
{
arche_apb_exit();
platform_driver_unregister(&arche_platform_device_driver);
}
