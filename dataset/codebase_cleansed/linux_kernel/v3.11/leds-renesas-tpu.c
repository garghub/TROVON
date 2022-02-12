static inline u16 r_tpu_read(struct r_tpu_priv *p, int reg_nr)
{
struct led_renesas_tpu_config *cfg = p->pdev->dev.platform_data;
void __iomem *base = p->mapbase;
unsigned long offs = reg_nr << 2;
if (reg_nr == TSTR)
return ioread16(base - cfg->channel_offset);
return ioread16(base + offs);
}
static inline void r_tpu_write(struct r_tpu_priv *p, int reg_nr, u16 value)
{
struct led_renesas_tpu_config *cfg = p->pdev->dev.platform_data;
void __iomem *base = p->mapbase;
unsigned long offs = reg_nr << 2;
if (reg_nr == TSTR) {
iowrite16(value, base - cfg->channel_offset);
return;
}
iowrite16(value, base + offs);
}
static void r_tpu_start_stop_ch(struct r_tpu_priv *p, int start)
{
struct led_renesas_tpu_config *cfg = p->pdev->dev.platform_data;
unsigned long flags;
u16 value;
spin_lock_irqsave(&r_tpu_lock, flags);
value = r_tpu_read(p, TSTR);
if (start)
value |= 1 << cfg->timer_bit;
else
value &= ~(1 << cfg->timer_bit);
r_tpu_write(p, TSTR, value);
spin_unlock_irqrestore(&r_tpu_lock, flags);
}
static int r_tpu_enable(struct r_tpu_priv *p, enum led_brightness brightness)
{
struct led_renesas_tpu_config *cfg = p->pdev->dev.platform_data;
int prescaler[] = { 1, 4, 16, 64 };
int k, ret;
unsigned long rate, tmp;
if (p->timer_state == R_TPU_TIMER_ON)
return 0;
pm_runtime_get_sync(&p->pdev->dev);
ret = clk_enable(p->clk);
if (ret) {
dev_err(&p->pdev->dev, "cannot enable clock\n");
return ret;
}
r_tpu_start_stop_ch(p, 0);
rate = clk_get_rate(p->clk);
for (k = ARRAY_SIZE(prescaler) - 1; k >= 0; k--)
if ((rate / prescaler[k]) >= p->min_rate)
break;
if (k < 0) {
dev_err(&p->pdev->dev, "clock rate mismatch\n");
goto err0;
}
dev_dbg(&p->pdev->dev, "rate = %lu, prescaler %u\n",
rate, prescaler[k]);
r_tpu_write(p, TCR, 0x0040 | k);
r_tpu_write(p, TIOR, 0x0002);
rate /= prescaler[k] * p->refresh_rate;
r_tpu_write(p, TGRB, rate);
dev_dbg(&p->pdev->dev, "TRGB = 0x%04lx\n", rate);
tmp = (cfg->max_brightness - brightness) * rate;
r_tpu_write(p, TGRA, tmp / cfg->max_brightness);
dev_dbg(&p->pdev->dev, "TRGA = 0x%04lx\n", tmp / cfg->max_brightness);
r_tpu_write(p, TMDR, 0x0002);
r_tpu_start_stop_ch(p, 1);
p->timer_state = R_TPU_TIMER_ON;
return 0;
err0:
clk_disable(p->clk);
pm_runtime_put_sync(&p->pdev->dev);
return -ENOTSUPP;
}
static void r_tpu_disable(struct r_tpu_priv *p)
{
if (p->timer_state == R_TPU_TIMER_UNUSED)
return;
r_tpu_start_stop_ch(p, 0);
clk_disable(p->clk);
pm_runtime_put_sync(&p->pdev->dev);
p->timer_state = R_TPU_TIMER_UNUSED;
}
static void r_tpu_set_pin(struct r_tpu_priv *p, enum r_tpu_pin new_state,
enum led_brightness brightness)
{
struct led_renesas_tpu_config *cfg = p->pdev->dev.platform_data;
if (p->pin_state == new_state) {
if (p->pin_state == R_TPU_PIN_GPIO)
gpio_set_value(cfg->pin_gpio, brightness);
return;
}
if (p->pin_state == R_TPU_PIN_GPIO)
gpio_free(cfg->pin_gpio);
if (p->pin_state == R_TPU_PIN_GPIO_FN)
gpio_free(cfg->pin_gpio_fn);
if (new_state == R_TPU_PIN_GPIO)
gpio_request_one(cfg->pin_gpio, !!brightness ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW,
cfg->name);
if (new_state == R_TPU_PIN_GPIO_FN)
gpio_request(cfg->pin_gpio_fn, cfg->name);
p->pin_state = new_state;
}
static void r_tpu_work(struct work_struct *work)
{
struct r_tpu_priv *p = container_of(work, struct r_tpu_priv, work);
enum led_brightness brightness = p->new_brightness;
r_tpu_disable(p);
if ((brightness == 0) || (brightness == p->ldev.max_brightness))
r_tpu_set_pin(p, R_TPU_PIN_GPIO, brightness);
else {
r_tpu_set_pin(p, R_TPU_PIN_GPIO_FN, 0);
r_tpu_enable(p, brightness);
}
}
static void r_tpu_set_brightness(struct led_classdev *ldev,
enum led_brightness brightness)
{
struct r_tpu_priv *p = container_of(ldev, struct r_tpu_priv, ldev);
p->new_brightness = brightness;
schedule_work(&p->work);
}
static int r_tpu_probe(struct platform_device *pdev)
{
struct led_renesas_tpu_config *cfg = pdev->dev.platform_data;
struct r_tpu_priv *p;
struct resource *res;
int ret;
if (!cfg) {
dev_err(&pdev->dev, "missing platform data\n");
return -ENODEV;
}
p = devm_kzalloc(&pdev->dev, sizeof(*p), GFP_KERNEL);
if (p == NULL) {
dev_err(&pdev->dev, "failed to allocate driver data\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
p->mapbase = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (p->mapbase == NULL) {
dev_err(&pdev->dev, "failed to remap I/O memory\n");
return -ENXIO;
}
p->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(p->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return PTR_ERR(p->clk);
}
p->pdev = pdev;
p->pin_state = R_TPU_PIN_UNUSED;
p->timer_state = R_TPU_TIMER_UNUSED;
p->refresh_rate = cfg->refresh_rate ? cfg->refresh_rate : 100;
r_tpu_set_pin(p, R_TPU_PIN_GPIO, LED_OFF);
platform_set_drvdata(pdev, p);
INIT_WORK(&p->work, r_tpu_work);
p->ldev.name = cfg->name;
p->ldev.brightness = LED_OFF;
p->ldev.max_brightness = cfg->max_brightness;
p->ldev.brightness_set = r_tpu_set_brightness;
p->ldev.flags |= LED_CORE_SUSPENDRESUME;
ret = led_classdev_register(&pdev->dev, &p->ldev);
if (ret < 0)
goto err0;
p->min_rate = p->ldev.max_brightness * p->refresh_rate;
pm_runtime_enable(&pdev->dev);
return 0;
err0:
r_tpu_set_pin(p, R_TPU_PIN_UNUSED, LED_OFF);
return ret;
}
static int r_tpu_remove(struct platform_device *pdev)
{
struct r_tpu_priv *p = platform_get_drvdata(pdev);
r_tpu_set_brightness(&p->ldev, LED_OFF);
led_classdev_unregister(&p->ldev);
cancel_work_sync(&p->work);
r_tpu_disable(p);
r_tpu_set_pin(p, R_TPU_PIN_UNUSED, LED_OFF);
pm_runtime_disable(&pdev->dev);
return 0;
}
