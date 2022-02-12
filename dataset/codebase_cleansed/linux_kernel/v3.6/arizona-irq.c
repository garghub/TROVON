static int arizona_map_irq(struct arizona *arizona, int irq)
{
int ret;
ret = regmap_irq_get_virq(arizona->aod_irq_chip, irq);
if (ret < 0)
ret = regmap_irq_get_virq(arizona->irq_chip, irq);
return ret;
}
int arizona_request_irq(struct arizona *arizona, int irq, char *name,
irq_handler_t handler, void *data)
{
irq = arizona_map_irq(arizona, irq);
if (irq < 0)
return irq;
return request_threaded_irq(irq, NULL, handler, IRQF_ONESHOT,
name, data);
}
void arizona_free_irq(struct arizona *arizona, int irq, void *data)
{
irq = arizona_map_irq(arizona, irq);
if (irq < 0)
return;
free_irq(irq, data);
}
int arizona_set_irq_wake(struct arizona *arizona, int irq, int on)
{
irq = arizona_map_irq(arizona, irq);
if (irq < 0)
return irq;
return irq_set_irq_wake(irq, on);
}
static irqreturn_t arizona_boot_done(int irq, void *data)
{
struct arizona *arizona = data;
dev_dbg(arizona->dev, "Boot done\n");
return IRQ_HANDLED;
}
static irqreturn_t arizona_ctrlif_err(int irq, void *data)
{
struct arizona *arizona = data;
dev_err(arizona->dev, "Control interface error\n");
return IRQ_HANDLED;
}
static irqreturn_t arizona_irq_thread(int irq, void *data)
{
struct arizona *arizona = data;
int i, ret;
ret = pm_runtime_get_sync(arizona->dev);
if (ret < 0) {
dev_err(arizona->dev, "Failed to resume device: %d\n", ret);
return IRQ_NONE;
}
for (i = 0; i < 2; i++)
handle_nested_irq(irq_find_mapping(arizona->virq, i));
pm_runtime_mark_last_busy(arizona->dev);
pm_runtime_put_autosuspend(arizona->dev);
return IRQ_HANDLED;
}
static void arizona_irq_enable(struct irq_data *data)
{
}
static void arizona_irq_disable(struct irq_data *data)
{
}
static int arizona_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct regmap_irq_chip_data *data = h->host_data;
irq_set_chip_data(virq, data);
irq_set_chip_and_handler(virq, &arizona_irq_chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
int arizona_irq_init(struct arizona *arizona)
{
int flags = IRQF_ONESHOT;
int ret, i;
const struct regmap_irq_chip *aod, *irq;
switch (arizona->type) {
#ifdef CONFIG_MFD_WM5102
case WM5102:
aod = &wm5102_aod;
irq = &wm5102_irq;
break;
#endif
#ifdef CONFIG_MFD_WM5110
case WM5110:
aod = &wm5110_aod;
irq = &wm5110_irq;
break;
#endif
default:
BUG_ON("Unknown Arizona class device" == NULL);
return -EINVAL;
}
if (arizona->pdata.irq_active_high) {
ret = regmap_update_bits(arizona->regmap, ARIZONA_IRQ_CTRL_1,
ARIZONA_IRQ_POL, 0);
if (ret != 0) {
dev_err(arizona->dev, "Couldn't set IRQ polarity: %d\n",
ret);
goto err;
}
flags |= IRQF_TRIGGER_HIGH;
} else {
flags |= IRQF_TRIGGER_LOW;
}
arizona->virq = irq_domain_add_linear(NULL, 2, &arizona_domain_ops,
arizona);
if (!arizona->virq) {
ret = -EINVAL;
goto err;
}
ret = regmap_add_irq_chip(arizona->regmap,
irq_create_mapping(arizona->virq, 0),
IRQF_ONESHOT, -1, aod,
&arizona->aod_irq_chip);
if (ret != 0) {
dev_err(arizona->dev, "Failed to add AOD IRQs: %d\n", ret);
goto err_domain;
}
ret = regmap_add_irq_chip(arizona->regmap,
irq_create_mapping(arizona->virq, 1),
IRQF_ONESHOT, -1, irq,
&arizona->irq_chip);
if (ret != 0) {
dev_err(arizona->dev, "Failed to add AOD IRQs: %d\n", ret);
goto err_aod;
}
i = arizona_map_irq(arizona, ARIZONA_IRQ_BOOT_DONE);
ret = request_threaded_irq(i, NULL, arizona_boot_done, IRQF_ONESHOT,
"Boot done", arizona);
if (ret != 0) {
dev_err(arizona->dev, "Failed to request boot done %d: %d\n",
arizona->irq, ret);
goto err_boot_done;
}
i = arizona_map_irq(arizona, ARIZONA_IRQ_CTRLIF_ERR);
ret = request_threaded_irq(i, NULL, arizona_ctrlif_err, IRQF_ONESHOT,
"Control interface error", arizona);
if (ret != 0) {
dev_err(arizona->dev, "Failed to request boot done %d: %d\n",
arizona->irq, ret);
goto err_ctrlif;
}
ret = request_threaded_irq(arizona->irq, NULL, arizona_irq_thread,
flags, "arizona", arizona);
if (ret != 0) {
dev_err(arizona->dev, "Failed to request IRQ %d: %d\n",
arizona->irq, ret);
goto err_main_irq;
}
return 0;
err_main_irq:
free_irq(arizona_map_irq(arizona, ARIZONA_IRQ_CTRLIF_ERR), arizona);
err_ctrlif:
free_irq(arizona_map_irq(arizona, ARIZONA_IRQ_BOOT_DONE), arizona);
err_boot_done:
regmap_del_irq_chip(irq_create_mapping(arizona->virq, 1),
arizona->irq_chip);
err_aod:
regmap_del_irq_chip(irq_create_mapping(arizona->virq, 0),
arizona->aod_irq_chip);
err_domain:
err:
return ret;
}
int arizona_irq_exit(struct arizona *arizona)
{
free_irq(arizona_map_irq(arizona, ARIZONA_IRQ_CTRLIF_ERR), arizona);
free_irq(arizona_map_irq(arizona, ARIZONA_IRQ_BOOT_DONE), arizona);
regmap_del_irq_chip(irq_create_mapping(arizona->virq, 1),
arizona->irq_chip);
regmap_del_irq_chip(irq_create_mapping(arizona->virq, 0),
arizona->aod_irq_chip);
free_irq(arizona->irq, arizona);
return 0;
}
