static void soc_ac97_device_release(struct device *dev)
{
kfree(to_ac97_t(dev));
}
struct snd_ac97 *snd_soc_alloc_ac97_codec(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
ac97 = kzalloc(sizeof(struct snd_ac97), GFP_KERNEL);
if (ac97 == NULL)
return ERR_PTR(-ENOMEM);
ac97->bus = &soc_ac97_bus;
ac97->num = 0;
ac97->dev.bus = &ac97_bus_type;
ac97->dev.parent = codec->component.card->dev;
ac97->dev.release = soc_ac97_device_release;
dev_set_name(&ac97->dev, "%d-%d:%s",
codec->component.card->snd_card->number, 0,
codec->component.name);
device_initialize(&ac97->dev);
return ac97;
}
struct snd_ac97 *snd_soc_new_ac97_codec(struct snd_soc_codec *codec,
unsigned int id, unsigned int id_mask)
{
struct snd_ac97 *ac97;
int ret;
ac97 = snd_soc_alloc_ac97_codec(codec);
if (IS_ERR(ac97))
return ac97;
if (id) {
ret = snd_ac97_reset(ac97, false, id, id_mask);
if (ret < 0) {
dev_err(codec->dev, "Failed to reset AC97 device: %d\n",
ret);
goto err_put_device;
}
}
ret = device_add(&ac97->dev);
if (ret)
goto err_put_device;
return ac97;
err_put_device:
put_device(&ac97->dev);
return ERR_PTR(ret);
}
void snd_soc_free_ac97_codec(struct snd_ac97 *ac97)
{
device_del(&ac97->dev);
ac97->bus = NULL;
put_device(&ac97->dev);
}
static void snd_soc_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct pinctrl *pctl = snd_ac97_rst_cfg.pctl;
pinctrl_select_state(pctl, snd_ac97_rst_cfg.pstate_warm_reset);
gpio_direction_output(snd_ac97_rst_cfg.gpio_sync, 1);
udelay(10);
gpio_direction_output(snd_ac97_rst_cfg.gpio_sync, 0);
pinctrl_select_state(pctl, snd_ac97_rst_cfg.pstate_run);
msleep(2);
}
static void snd_soc_ac97_reset(struct snd_ac97 *ac97)
{
struct pinctrl *pctl = snd_ac97_rst_cfg.pctl;
pinctrl_select_state(pctl, snd_ac97_rst_cfg.pstate_reset);
gpio_direction_output(snd_ac97_rst_cfg.gpio_sync, 0);
gpio_direction_output(snd_ac97_rst_cfg.gpio_sdata, 0);
gpio_direction_output(snd_ac97_rst_cfg.gpio_reset, 0);
udelay(10);
gpio_direction_output(snd_ac97_rst_cfg.gpio_reset, 1);
pinctrl_select_state(pctl, snd_ac97_rst_cfg.pstate_run);
msleep(2);
}
static int snd_soc_ac97_parse_pinctl(struct device *dev,
struct snd_ac97_reset_cfg *cfg)
{
struct pinctrl *p;
struct pinctrl_state *state;
int gpio;
int ret;
p = devm_pinctrl_get(dev);
if (IS_ERR(p)) {
dev_err(dev, "Failed to get pinctrl\n");
return PTR_ERR(p);
}
cfg->pctl = p;
state = pinctrl_lookup_state(p, "ac97-reset");
if (IS_ERR(state)) {
dev_err(dev, "Can't find pinctrl state ac97-reset\n");
return PTR_ERR(state);
}
cfg->pstate_reset = state;
state = pinctrl_lookup_state(p, "ac97-warm-reset");
if (IS_ERR(state)) {
dev_err(dev, "Can't find pinctrl state ac97-warm-reset\n");
return PTR_ERR(state);
}
cfg->pstate_warm_reset = state;
state = pinctrl_lookup_state(p, "ac97-running");
if (IS_ERR(state)) {
dev_err(dev, "Can't find pinctrl state ac97-running\n");
return PTR_ERR(state);
}
cfg->pstate_run = state;
gpio = of_get_named_gpio(dev->of_node, "ac97-gpios", 0);
if (gpio < 0) {
dev_err(dev, "Can't find ac97-sync gpio\n");
return gpio;
}
ret = devm_gpio_request(dev, gpio, "AC97 link sync");
if (ret) {
dev_err(dev, "Failed requesting ac97-sync gpio\n");
return ret;
}
cfg->gpio_sync = gpio;
gpio = of_get_named_gpio(dev->of_node, "ac97-gpios", 1);
if (gpio < 0) {
dev_err(dev, "Can't find ac97-sdata gpio %d\n", gpio);
return gpio;
}
ret = devm_gpio_request(dev, gpio, "AC97 link sdata");
if (ret) {
dev_err(dev, "Failed requesting ac97-sdata gpio\n");
return ret;
}
cfg->gpio_sdata = gpio;
gpio = of_get_named_gpio(dev->of_node, "ac97-gpios", 2);
if (gpio < 0) {
dev_err(dev, "Can't find ac97-reset gpio\n");
return gpio;
}
ret = devm_gpio_request(dev, gpio, "AC97 link reset");
if (ret) {
dev_err(dev, "Failed requesting ac97-reset gpio\n");
return ret;
}
cfg->gpio_reset = gpio;
return 0;
}
int snd_soc_set_ac97_ops(struct snd_ac97_bus_ops *ops)
{
if (ops == soc_ac97_ops)
return 0;
if (soc_ac97_ops && ops)
return -EBUSY;
soc_ac97_ops = ops;
soc_ac97_bus.ops = ops;
return 0;
}
int snd_soc_set_ac97_ops_of_reset(struct snd_ac97_bus_ops *ops,
struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct snd_ac97_reset_cfg cfg;
int ret;
ret = snd_soc_ac97_parse_pinctl(dev, &cfg);
if (ret)
return ret;
ret = snd_soc_set_ac97_ops(ops);
if (ret)
return ret;
ops->warm_reset = snd_soc_ac97_warm_reset;
ops->reset = snd_soc_ac97_reset;
snd_ac97_rst_cfg = cfg;
return 0;
}
