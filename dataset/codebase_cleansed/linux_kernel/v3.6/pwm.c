int pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns)
{
unsigned long long c;
unsigned long period_cycles, prescale, pv, dc;
if (pwm == NULL || period_ns == 0 || duty_ns > period_ns)
return -EINVAL;
c = clk_get_rate(pwm->clk);
c = c * period_ns;
do_div(c, 1000000000);
period_cycles = c;
if (period_cycles < 1)
period_cycles = 1;
prescale = (period_cycles - 1) / 1024;
pv = period_cycles / (prescale + 1) - 1;
if (prescale > 63)
return -EINVAL;
if (duty_ns == period_ns)
dc = OST_PWMDCCR_FDCYCLE;
else
dc = (pv + 1) * duty_ns / period_ns;
clk_enable(pwm->clk);
OST_PWMPWCR = prescale;
OST_PWMDCCR = pv - dc;
OST_PWMPCR = pv;
clk_disable(pwm->clk);
return 0;
}
int pwm_enable(struct pwm_device *pwm)
{
int rc = 0;
if (!pwm->clk_enabled) {
rc = clk_enable(pwm->clk);
if (!rc)
pwm->clk_enabled = 1;
}
return rc;
}
void pwm_disable(struct pwm_device *pwm)
{
if (pwm->clk_enabled) {
clk_disable(pwm->clk);
pwm->clk_enabled = 0;
}
}
struct pwm_device *pwm_request(int pwm_id, const char *label)
{
struct pwm_device *pwm;
int found = 0;
mutex_lock(&pwm_lock);
list_for_each_entry(pwm, &pwm_list, node) {
if (pwm->pwm_id == pwm_id) {
found = 1;
break;
}
}
if (found) {
if (pwm->use_count == 0) {
pwm->use_count++;
pwm->label = label;
} else
pwm = ERR_PTR(-EBUSY);
} else
pwm = ERR_PTR(-ENOENT);
mutex_unlock(&pwm_lock);
return pwm;
}
void pwm_free(struct pwm_device *pwm)
{
mutex_lock(&pwm_lock);
if (pwm->use_count) {
pwm->use_count--;
pwm->label = NULL;
} else
pr_warning("PWM device already freed\n");
mutex_unlock(&pwm_lock);
}
static inline void __add_pwm(struct pwm_device *pwm)
{
mutex_lock(&pwm_lock);
list_add_tail(&pwm->node, &pwm_list);
mutex_unlock(&pwm_lock);
}
static struct pwm_device *pwm_probe(struct platform_device *pdev,
unsigned int pwm_id, struct pwm_device *parent_pwm)
{
struct pwm_device *pwm;
struct resource *r;
int ret = 0;
pwm = kzalloc(sizeof(struct pwm_device), GFP_KERNEL);
if (pwm == NULL) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return ERR_PTR(-ENOMEM);
}
pwm->clk = clk_get(NULL, "OST_CLK");
if (IS_ERR(pwm->clk)) {
ret = PTR_ERR(pwm->clk);
goto err_free;
}
pwm->clk_enabled = 0;
pwm->use_count = 0;
pwm->pwm_id = pwm_id;
pwm->pdev = pdev;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(&pdev->dev, "no memory resource defined\n");
ret = -ENODEV;
goto err_free_clk;
}
r = request_mem_region(r->start, resource_size(r), pdev->name);
if (r == NULL) {
dev_err(&pdev->dev, "failed to request memory resource\n");
ret = -EBUSY;
goto err_free_clk;
}
__add_pwm(pwm);
platform_set_drvdata(pdev, pwm);
return pwm;
err_free_clk:
clk_put(pwm->clk);
err_free:
kfree(pwm);
return ERR_PTR(ret);
}
static int __devinit puv3_pwm_probe(struct platform_device *pdev)
{
struct pwm_device *pwm = pwm_probe(pdev, pdev->id, NULL);
if (IS_ERR(pwm))
return PTR_ERR(pwm);
return 0;
}
static int __devexit pwm_remove(struct platform_device *pdev)
{
struct pwm_device *pwm;
struct resource *r;
pwm = platform_get_drvdata(pdev);
if (pwm == NULL)
return -ENODEV;
mutex_lock(&pwm_lock);
list_del(&pwm->node);
mutex_unlock(&pwm_lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(r->start, resource_size(r));
clk_put(pwm->clk);
kfree(pwm);
return 0;
}
static int __init pwm_init(void)
{
int ret = 0;
ret = platform_driver_register(&puv3_pwm_driver);
if (ret) {
printk(KERN_ERR "failed to register puv3_pwm_driver\n");
return ret;
}
return ret;
}
static void __exit pwm_exit(void)
{
platform_driver_unregister(&puv3_pwm_driver);
}
