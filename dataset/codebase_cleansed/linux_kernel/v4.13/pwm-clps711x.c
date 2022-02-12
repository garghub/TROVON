static inline struct clps711x_chip *to_clps711x_chip(struct pwm_chip *chip)
{
return container_of(chip, struct clps711x_chip, chip);
}
static void clps711x_pwm_update_val(struct clps711x_chip *priv, u32 n, u32 v)
{
u32 shift = (n + 1) * 4;
unsigned long flags;
u32 tmp;
spin_lock_irqsave(&priv->lock, flags);
tmp = readl(priv->pmpcon);
tmp &= ~(0xf << shift);
tmp |= v << shift;
writel(tmp, priv->pmpcon);
spin_unlock_irqrestore(&priv->lock, flags);
}
static unsigned int clps711x_get_duty(struct pwm_device *pwm, unsigned int v)
{
return DIV_ROUND_CLOSEST(v * 0xf, pwm_get_period(pwm));
}
static int clps711x_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct clps711x_chip *priv = to_clps711x_chip(chip);
unsigned int freq = clk_get_rate(priv->clk);
if (!freq)
return -EINVAL;
pwm->args.period = DIV_ROUND_CLOSEST(NSEC_PER_SEC, freq);
return 0;
}
static int clps711x_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct clps711x_chip *priv = to_clps711x_chip(chip);
unsigned int duty;
if (period_ns != pwm_get_period(pwm))
return -EINVAL;
duty = clps711x_get_duty(pwm, duty_ns);
clps711x_pwm_update_val(priv, pwm->hwpwm, duty);
return 0;
}
static int clps711x_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct clps711x_chip *priv = to_clps711x_chip(chip);
unsigned int duty;
duty = clps711x_get_duty(pwm, pwm_get_duty_cycle(pwm));
clps711x_pwm_update_val(priv, pwm->hwpwm, duty);
return 0;
}
static void clps711x_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct clps711x_chip *priv = to_clps711x_chip(chip);
clps711x_pwm_update_val(priv, pwm->hwpwm, 0);
}
static struct pwm_device *clps711x_pwm_xlate(struct pwm_chip *chip,
const struct of_phandle_args *args)
{
if (args->args[0] >= chip->npwm)
return ERR_PTR(-EINVAL);
return pwm_request_from_chip(chip, args->args[0], NULL);
}
static int clps711x_pwm_probe(struct platform_device *pdev)
{
struct clps711x_chip *priv;
struct resource *res;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->pmpcon = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->pmpcon))
return PTR_ERR(priv->pmpcon);
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
priv->chip.ops = &clps711x_pwm_ops;
priv->chip.dev = &pdev->dev;
priv->chip.base = -1;
priv->chip.npwm = 2;
priv->chip.of_xlate = clps711x_pwm_xlate;
priv->chip.of_pwm_n_cells = 1;
spin_lock_init(&priv->lock);
platform_set_drvdata(pdev, priv);
return pwmchip_add(&priv->chip);
}
static int clps711x_pwm_remove(struct platform_device *pdev)
{
struct clps711x_chip *priv = platform_get_drvdata(pdev);
return pwmchip_remove(&priv->chip);
}
