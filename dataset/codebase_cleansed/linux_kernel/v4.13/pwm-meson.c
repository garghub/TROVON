static inline struct meson_pwm *to_meson_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct meson_pwm, chip);
}
static int meson_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct meson_pwm_channel *channel = pwm_get_chip_data(pwm);
struct device *dev = chip->dev;
int err;
if (!channel)
return -ENODEV;
if (channel->clk_parent) {
err = clk_set_parent(channel->clk, channel->clk_parent);
if (err < 0) {
dev_err(dev, "failed to set parent %s for %s: %d\n",
__clk_get_name(channel->clk_parent),
__clk_get_name(channel->clk), err);
return err;
}
}
err = clk_prepare_enable(channel->clk);
if (err < 0) {
dev_err(dev, "failed to enable clock %s: %d\n",
__clk_get_name(channel->clk), err);
return err;
}
chip->ops->get_state(chip, pwm, &channel->state);
return 0;
}
static void meson_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct meson_pwm_channel *channel = pwm_get_chip_data(pwm);
if (channel)
clk_disable_unprepare(channel->clk);
}
static int meson_pwm_calc(struct meson_pwm *meson,
struct meson_pwm_channel *channel, unsigned int id,
unsigned int duty, unsigned int period)
{
unsigned int pre_div, cnt, duty_cnt;
unsigned long fin_freq = -1;
u64 fin_ps;
if (~(meson->inverter_mask >> id) & 0x1)
duty = period - duty;
if (period == channel->state.period &&
duty == channel->state.duty_cycle)
return 0;
fin_freq = clk_get_rate(channel->clk);
if (fin_freq == 0) {
dev_err(meson->chip.dev, "invalid source clock frequency\n");
return -EINVAL;
}
dev_dbg(meson->chip.dev, "fin_freq: %lu Hz\n", fin_freq);
fin_ps = (u64)NSEC_PER_SEC * 1000;
do_div(fin_ps, fin_freq);
for (pre_div = 0; pre_div < MISC_CLK_DIV_MASK; pre_div++) {
cnt = DIV_ROUND_CLOSEST_ULL((u64)period * 1000,
fin_ps * (pre_div + 1));
dev_dbg(meson->chip.dev, "fin_ps=%llu pre_div=%u cnt=%u\n",
fin_ps, pre_div, cnt);
if (cnt <= 0xffff)
break;
}
if (pre_div == MISC_CLK_DIV_MASK) {
dev_err(meson->chip.dev, "unable to get period pre_div\n");
return -EINVAL;
}
dev_dbg(meson->chip.dev, "period=%u pre_div=%u cnt=%u\n", period,
pre_div, cnt);
if (duty == period) {
channel->pre_div = pre_div;
channel->hi = cnt;
channel->lo = 0;
} else if (duty == 0) {
channel->pre_div = pre_div;
channel->hi = 0;
channel->lo = cnt;
} else {
duty_cnt = DIV_ROUND_CLOSEST_ULL((u64)duty * 1000,
fin_ps * (pre_div + 1));
if (duty_cnt > 0xffff) {
dev_err(meson->chip.dev, "unable to get duty cycle\n");
return -EINVAL;
}
dev_dbg(meson->chip.dev, "duty=%u pre_div=%u duty_cnt=%u\n",
duty, pre_div, duty_cnt);
channel->pre_div = pre_div;
channel->hi = duty_cnt;
channel->lo = cnt - duty_cnt;
}
return 0;
}
static void meson_pwm_enable(struct meson_pwm *meson,
struct meson_pwm_channel *channel,
unsigned int id)
{
u32 value, clk_shift, clk_enable, enable;
unsigned int offset;
switch (id) {
case 0:
clk_shift = MISC_A_CLK_DIV_SHIFT;
clk_enable = MISC_A_CLK_EN;
enable = MISC_A_EN;
offset = REG_PWM_A;
break;
case 1:
clk_shift = MISC_B_CLK_DIV_SHIFT;
clk_enable = MISC_B_CLK_EN;
enable = MISC_B_EN;
offset = REG_PWM_B;
break;
default:
return;
}
value = readl(meson->base + REG_MISC_AB);
value &= ~(MISC_CLK_DIV_MASK << clk_shift);
value |= channel->pre_div << clk_shift;
value |= clk_enable;
writel(value, meson->base + REG_MISC_AB);
value = (channel->hi << PWM_HIGH_SHIFT) | channel->lo;
writel(value, meson->base + offset);
value = readl(meson->base + REG_MISC_AB);
value |= enable;
writel(value, meson->base + REG_MISC_AB);
}
static void meson_pwm_disable(struct meson_pwm *meson, unsigned int id)
{
u32 value, enable;
switch (id) {
case 0:
enable = MISC_A_EN;
break;
case 1:
enable = MISC_B_EN;
break;
default:
return;
}
value = readl(meson->base + REG_MISC_AB);
value &= ~enable;
writel(value, meson->base + REG_MISC_AB);
}
static int meson_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct meson_pwm_channel *channel = pwm_get_chip_data(pwm);
struct meson_pwm *meson = to_meson_pwm(chip);
unsigned long flags;
int err = 0;
if (!state)
return -EINVAL;
spin_lock_irqsave(&meson->lock, flags);
if (!state->enabled) {
meson_pwm_disable(meson, pwm->hwpwm);
channel->state.enabled = false;
goto unlock;
}
if (state->period != channel->state.period ||
state->duty_cycle != channel->state.duty_cycle ||
state->polarity != channel->state.polarity) {
if (channel->state.enabled) {
meson_pwm_disable(meson, pwm->hwpwm);
channel->state.enabled = false;
}
if (state->polarity != channel->state.polarity) {
if (state->polarity == PWM_POLARITY_NORMAL)
meson->inverter_mask |= BIT(pwm->hwpwm);
else
meson->inverter_mask &= ~BIT(pwm->hwpwm);
}
err = meson_pwm_calc(meson, channel, pwm->hwpwm,
state->duty_cycle, state->period);
if (err < 0)
goto unlock;
channel->state.polarity = state->polarity;
channel->state.period = state->period;
channel->state.duty_cycle = state->duty_cycle;
}
if (state->enabled && !channel->state.enabled) {
meson_pwm_enable(meson, channel, pwm->hwpwm);
channel->state.enabled = true;
}
unlock:
spin_unlock_irqrestore(&meson->lock, flags);
return err;
}
static void meson_pwm_get_state(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct meson_pwm *meson = to_meson_pwm(chip);
u32 value, mask;
if (!state)
return;
switch (pwm->hwpwm) {
case 0:
mask = MISC_A_EN;
break;
case 1:
mask = MISC_B_EN;
break;
default:
return;
}
value = readl(meson->base + REG_MISC_AB);
state->enabled = (value & mask) != 0;
}
static int meson_pwm_init_channels(struct meson_pwm *meson,
struct meson_pwm_channel *channels)
{
struct device *dev = meson->chip.dev;
struct device_node *np = dev->of_node;
struct clk_init_data init;
unsigned int i;
char name[255];
int err;
for (i = 0; i < meson->chip.npwm; i++) {
struct meson_pwm_channel *channel = &channels[i];
snprintf(name, sizeof(name), "%s#mux%u", np->full_name, i);
init.name = name;
init.ops = &clk_mux_ops;
init.flags = CLK_IS_BASIC;
init.parent_names = meson->data->parent_names;
init.num_parents = meson->data->num_parents;
channel->mux.reg = meson->base + REG_MISC_AB;
channel->mux.shift = mux_reg_shifts[i];
channel->mux.mask = BIT(MISC_CLK_SEL_WIDTH) - 1;
channel->mux.flags = 0;
channel->mux.lock = &meson->lock;
channel->mux.table = NULL;
channel->mux.hw.init = &init;
channel->clk = devm_clk_register(dev, &channel->mux.hw);
if (IS_ERR(channel->clk)) {
err = PTR_ERR(channel->clk);
dev_err(dev, "failed to register %s: %d\n", name, err);
return err;
}
snprintf(name, sizeof(name), "clkin%u", i);
channel->clk_parent = devm_clk_get(dev, name);
if (IS_ERR(channel->clk_parent)) {
err = PTR_ERR(channel->clk_parent);
if (err == -EPROBE_DEFER)
return err;
channel->clk_parent = NULL;
}
}
return 0;
}
static void meson_pwm_add_channels(struct meson_pwm *meson,
struct meson_pwm_channel *channels)
{
unsigned int i;
for (i = 0; i < meson->chip.npwm; i++)
pwm_set_chip_data(&meson->chip.pwms[i], &channels[i]);
}
static int meson_pwm_probe(struct platform_device *pdev)
{
struct meson_pwm_channel *channels;
struct meson_pwm *meson;
struct resource *regs;
int err;
meson = devm_kzalloc(&pdev->dev, sizeof(*meson), GFP_KERNEL);
if (!meson)
return -ENOMEM;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
meson->base = devm_ioremap_resource(&pdev->dev, regs);
if (IS_ERR(meson->base))
return PTR_ERR(meson->base);
spin_lock_init(&meson->lock);
meson->chip.dev = &pdev->dev;
meson->chip.ops = &meson_pwm_ops;
meson->chip.base = -1;
meson->chip.npwm = 2;
meson->chip.of_xlate = of_pwm_xlate_with_flags;
meson->chip.of_pwm_n_cells = 3;
meson->data = of_device_get_match_data(&pdev->dev);
meson->inverter_mask = BIT(meson->chip.npwm) - 1;
channels = devm_kcalloc(&pdev->dev, meson->chip.npwm, sizeof(*meson),
GFP_KERNEL);
if (!channels)
return -ENOMEM;
err = meson_pwm_init_channels(meson, channels);
if (err < 0)
return err;
err = pwmchip_add(&meson->chip);
if (err < 0) {
dev_err(&pdev->dev, "failed to register PWM chip: %d\n", err);
return err;
}
meson_pwm_add_channels(meson, channels);
platform_set_drvdata(pdev, meson);
return 0;
}
static int meson_pwm_remove(struct platform_device *pdev)
{
struct meson_pwm *meson = platform_get_drvdata(pdev);
return pwmchip_remove(&meson->chip);
}
