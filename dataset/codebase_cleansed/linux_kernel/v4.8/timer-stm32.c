static int stm32_clock_event_shutdown(struct clock_event_device *evtdev)
{
struct stm32_clock_event_ddata *data =
container_of(evtdev, struct stm32_clock_event_ddata, evtdev);
void *base = data->base;
writel_relaxed(0, base + TIM_CR1);
return 0;
}
static int stm32_clock_event_set_periodic(struct clock_event_device *evtdev)
{
struct stm32_clock_event_ddata *data =
container_of(evtdev, struct stm32_clock_event_ddata, evtdev);
void *base = data->base;
writel_relaxed(data->periodic_top, base + TIM_ARR);
writel_relaxed(TIM_CR1_ARPE | TIM_CR1_CEN, base + TIM_CR1);
return 0;
}
static int stm32_clock_event_set_next_event(unsigned long evt,
struct clock_event_device *evtdev)
{
struct stm32_clock_event_ddata *data =
container_of(evtdev, struct stm32_clock_event_ddata, evtdev);
writel_relaxed(evt, data->base + TIM_ARR);
writel_relaxed(TIM_CR1_ARPE | TIM_CR1_OPM | TIM_CR1_CEN,
data->base + TIM_CR1);
return 0;
}
static irqreturn_t stm32_clock_event_handler(int irq, void *dev_id)
{
struct stm32_clock_event_ddata *data = dev_id;
writel_relaxed(0, data->base + TIM_SR);
data->evtdev.event_handler(&data->evtdev);
return IRQ_HANDLED;
}
static int __init stm32_clockevent_init(struct device_node *np)
{
struct stm32_clock_event_ddata *data = &clock_event_ddata;
struct clk *clk;
struct reset_control *rstc;
unsigned long rate, max_delta;
int irq, ret, bits, prescaler = 1;
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
pr_err("failed to get clock for clockevent (%d)\n", ret);
goto err_clk_get;
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("failed to enable timer clock for clockevent (%d)\n",
ret);
goto err_clk_enable;
}
rate = clk_get_rate(clk);
rstc = of_reset_control_get(np, NULL);
if (!IS_ERR(rstc)) {
reset_control_assert(rstc);
reset_control_deassert(rstc);
}
data->base = of_iomap(np, 0);
if (!data->base) {
ret = -ENXIO;
pr_err("failed to map registers for clockevent\n");
goto err_iomap;
}
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
ret = -EINVAL;
pr_err("%s: failed to get irq.\n", np->full_name);
goto err_get_irq;
}
writel_relaxed(~0U, data->base + TIM_ARR);
max_delta = readl_relaxed(data->base + TIM_ARR);
if (max_delta == ~0U) {
prescaler = 1;
bits = 32;
} else {
prescaler = 1024;
bits = 16;
}
writel_relaxed(0, data->base + TIM_ARR);
writel_relaxed(prescaler - 1, data->base + TIM_PSC);
writel_relaxed(TIM_EGR_UG, data->base + TIM_EGR);
writel_relaxed(TIM_DIER_UIE, data->base + TIM_DIER);
writel_relaxed(0, data->base + TIM_SR);
data->periodic_top = DIV_ROUND_CLOSEST(rate, prescaler * HZ);
clockevents_config_and_register(&data->evtdev,
DIV_ROUND_CLOSEST(rate, prescaler),
0x1, max_delta);
ret = request_irq(irq, stm32_clock_event_handler, IRQF_TIMER,
"stm32 clockevent", data);
if (ret) {
pr_err("%s: failed to request irq.\n", np->full_name);
goto err_get_irq;
}
pr_info("%s: STM32 clockevent driver initialized (%d bits)\n",
np->full_name, bits);
return ret;
err_get_irq:
iounmap(data->base);
err_iomap:
clk_disable_unprepare(clk);
err_clk_enable:
clk_put(clk);
err_clk_get:
return ret;
}
