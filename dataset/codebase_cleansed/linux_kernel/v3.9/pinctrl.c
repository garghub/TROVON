static int sh_pfc_get_groups_count(struct pinctrl_dev *pctldev)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->nr_pads;
}
static const char *sh_pfc_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->pads[selector].name;
}
static int sh_pfc_get_group_pins(struct pinctrl_dev *pctldev, unsigned group,
const unsigned **pins, unsigned *num_pins)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
*pins = &pmx->pads[group].number;
*num_pins = 1;
return 0;
}
static void sh_pfc_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
seq_printf(s, "%s", DRV_NAME);
}
static int sh_pfc_get_functions_count(struct pinctrl_dev *pctldev)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->nr_functions;
}
static const char *sh_pfc_get_function_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->functions[selector]->name;
}
static int sh_pfc_get_function_groups(struct pinctrl_dev *pctldev, unsigned func,
const char * const **groups,
unsigned * const num_groups)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
*groups = &pmx->functions[func]->name;
*num_groups = 1;
return 0;
}
static int sh_pfc_noop_enable(struct pinctrl_dev *pctldev, unsigned func,
unsigned group)
{
return 0;
}
static void sh_pfc_noop_disable(struct pinctrl_dev *pctldev, unsigned func,
unsigned group)
{
}
static int sh_pfc_config_function(struct sh_pfc *pfc, unsigned offset)
{
if (sh_pfc_config_gpio(pfc, offset,
PINMUX_TYPE_FUNCTION,
GPIO_CFG_DRYRUN) != 0)
return -EINVAL;
if (sh_pfc_config_gpio(pfc, offset,
PINMUX_TYPE_FUNCTION,
GPIO_CFG_REQ) != 0)
return -EINVAL;
return 0;
}
static int sh_pfc_reconfig_pin(struct sh_pfc *pfc, unsigned offset,
int new_type)
{
unsigned long flags;
int pinmux_type;
int ret = -EINVAL;
spin_lock_irqsave(&pfc->lock, flags);
pinmux_type = pfc->info->gpios[offset].flags & PINMUX_FLAG_TYPE;
switch (pinmux_type) {
case PINMUX_TYPE_GPIO:
break;
case PINMUX_TYPE_OUTPUT:
case PINMUX_TYPE_INPUT:
case PINMUX_TYPE_INPUT_PULLUP:
case PINMUX_TYPE_INPUT_PULLDOWN:
sh_pfc_config_gpio(pfc, offset, pinmux_type, GPIO_CFG_FREE);
break;
default:
goto err;
}
if (sh_pfc_config_gpio(pfc, offset, new_type,
GPIO_CFG_DRYRUN) != 0)
goto err;
if (sh_pfc_config_gpio(pfc, offset, new_type,
GPIO_CFG_REQ) != 0)
goto err;
pfc->info->gpios[offset].flags &= ~PINMUX_FLAG_TYPE;
pfc->info->gpios[offset].flags |= new_type;
ret = 0;
err:
spin_unlock_irqrestore(&pfc->lock, flags);
return ret;
}
static int sh_pfc_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
struct sh_pfc *pfc = pmx->pfc;
unsigned long flags;
int ret, pinmux_type;
spin_lock_irqsave(&pfc->lock, flags);
pinmux_type = pfc->info->gpios[offset].flags & PINMUX_FLAG_TYPE;
switch (pinmux_type) {
case PINMUX_TYPE_FUNCTION:
pr_notice_once("Use of GPIO API for function requests is "
"deprecated, convert to pinctrl\n");
ret = sh_pfc_config_function(pfc, offset);
if (unlikely(ret < 0))
goto err;
break;
case PINMUX_TYPE_GPIO:
case PINMUX_TYPE_INPUT:
case PINMUX_TYPE_OUTPUT:
break;
default:
pr_err("Unsupported mux type (%d), bailing...\n", pinmux_type);
ret = -ENOTSUPP;
goto err;
}
ret = 0;
err:
spin_unlock_irqrestore(&pfc->lock, flags);
return ret;
}
static void sh_pfc_gpio_disable_free(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
struct sh_pfc *pfc = pmx->pfc;
unsigned long flags;
int pinmux_type;
spin_lock_irqsave(&pfc->lock, flags);
pinmux_type = pfc->info->gpios[offset].flags & PINMUX_FLAG_TYPE;
sh_pfc_config_gpio(pfc, offset, pinmux_type, GPIO_CFG_FREE);
spin_unlock_irqrestore(&pfc->lock, flags);
}
static int sh_pfc_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset, bool input)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
int type = input ? PINMUX_TYPE_INPUT : PINMUX_TYPE_OUTPUT;
return sh_pfc_reconfig_pin(pmx->pfc, offset, type);
}
static int sh_pfc_pinconf_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
struct sh_pfc *pfc = pmx->pfc;
*config = pfc->info->gpios[pin].flags & PINMUX_FLAG_TYPE;
return 0;
}
static int sh_pfc_pinconf_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long config)
{
struct sh_pfc_pinctrl *pmx = pinctrl_dev_get_drvdata(pctldev);
if (config >= PINMUX_FLAG_TYPE)
return -EINVAL;
return sh_pfc_reconfig_pin(pmx->pfc, pin, config);
}
static void sh_pfc_pinconf_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned pin)
{
const char *pinmux_type_str[] = {
[PINMUX_TYPE_NONE] = "none",
[PINMUX_TYPE_FUNCTION] = "function",
[PINMUX_TYPE_GPIO] = "gpio",
[PINMUX_TYPE_OUTPUT] = "output",
[PINMUX_TYPE_INPUT] = "input",
[PINMUX_TYPE_INPUT_PULLUP] = "input bias pull up",
[PINMUX_TYPE_INPUT_PULLDOWN] = "input bias pull down",
};
unsigned long config;
int rc;
rc = sh_pfc_pinconf_get(pctldev, pin, &config);
if (unlikely(rc != 0))
return;
seq_printf(s, " %s", pinmux_type_str[config]);
}
static void sh_pfc_map_one_gpio(struct sh_pfc *pfc, struct sh_pfc_pinctrl *pmx,
struct pinmux_gpio *gpio, unsigned offset)
{
struct pinmux_data_reg *dummy;
unsigned long flags;
int bit;
gpio->flags &= ~PINMUX_FLAG_TYPE;
if (sh_pfc_get_data_reg(pfc, offset, &dummy, &bit) == 0)
gpio->flags |= PINMUX_TYPE_GPIO;
else {
gpio->flags |= PINMUX_TYPE_FUNCTION;
spin_lock_irqsave(&pmx->lock, flags);
pmx->nr_functions++;
spin_unlock_irqrestore(&pmx->lock, flags);
}
}
static int sh_pfc_map_gpios(struct sh_pfc *pfc, struct sh_pfc_pinctrl *pmx)
{
unsigned long flags;
int i;
pmx->nr_pads = pfc->info->last_gpio - pfc->info->first_gpio + 1;
pmx->pads = devm_kzalloc(pfc->dev, sizeof(*pmx->pads) * pmx->nr_pads,
GFP_KERNEL);
if (unlikely(!pmx->pads)) {
pmx->nr_pads = 0;
return -ENOMEM;
}
spin_lock_irqsave(&pfc->lock, flags);
for (i = 0; i < pmx->nr_pads; i++) {
struct pinctrl_pin_desc *pin = pmx->pads + i;
struct pinmux_gpio *gpio = pfc->info->gpios + i;
pin->number = pfc->info->first_gpio + i;
pin->name = gpio->name;
if (unlikely(!gpio->enum_id))
continue;
sh_pfc_map_one_gpio(pfc, pmx, gpio, i);
}
spin_unlock_irqrestore(&pfc->lock, flags);
sh_pfc_pinctrl_desc.pins = pmx->pads;
sh_pfc_pinctrl_desc.npins = pmx->nr_pads;
return 0;
}
static int sh_pfc_map_functions(struct sh_pfc *pfc, struct sh_pfc_pinctrl *pmx)
{
unsigned long flags;
int i, fn;
pmx->functions = devm_kzalloc(pfc->dev, pmx->nr_functions *
sizeof(*pmx->functions), GFP_KERNEL);
if (unlikely(!pmx->functions))
return -ENOMEM;
spin_lock_irqsave(&pmx->lock, flags);
for (i = fn = 0; i < pmx->nr_pads; i++) {
struct pinmux_gpio *gpio = pfc->info->gpios + i;
if ((gpio->flags & PINMUX_FLAG_TYPE) == PINMUX_TYPE_FUNCTION)
pmx->functions[fn++] = gpio;
}
spin_unlock_irqrestore(&pmx->lock, flags);
return 0;
}
int sh_pfc_register_pinctrl(struct sh_pfc *pfc)
{
struct sh_pfc_pinctrl *pmx;
int ret;
pmx = devm_kzalloc(pfc->dev, sizeof(*pmx), GFP_KERNEL);
if (unlikely(!pmx))
return -ENOMEM;
spin_lock_init(&pmx->lock);
pmx->pfc = pfc;
pfc->pinctrl = pmx;
ret = sh_pfc_map_gpios(pfc, pmx);
if (unlikely(ret != 0))
return ret;
ret = sh_pfc_map_functions(pfc, pmx);
if (unlikely(ret != 0))
return ret;
pmx->pctl = pinctrl_register(&sh_pfc_pinctrl_desc, pfc->dev, pmx);
if (IS_ERR(pmx->pctl))
return PTR_ERR(pmx->pctl);
sh_pfc_gpio_range.npins = pfc->info->last_gpio
- pfc->info->first_gpio + 1;
sh_pfc_gpio_range.base = pfc->info->first_gpio;
sh_pfc_gpio_range.pin_base = pfc->info->first_gpio;
pinctrl_add_gpio_range(pmx->pctl, &sh_pfc_gpio_range);
return 0;
}
int sh_pfc_unregister_pinctrl(struct sh_pfc *pfc)
{
struct sh_pfc_pinctrl *pmx = pfc->pinctrl;
pinctrl_unregister(pmx->pctl);
pfc->pinctrl = NULL;
return 0;
}
