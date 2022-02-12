static int xway_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *config)
{
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctldev);
enum ltq_pinconf_param param = LTQ_PINCONF_UNPACK_PARAM(*config);
int port = PORT(pin);
u32 reg;
switch (param) {
case LTQ_PINCONF_PARAM_OPEN_DRAIN:
if (port == PORT3)
reg = GPIO3_OD;
else
reg = GPIO_OD(pin);
*config = LTQ_PINCONF_PACK(param,
!gpio_getbit(info->membase[0], reg, PORT_PIN(pin)));
break;
case LTQ_PINCONF_PARAM_PULL:
if (port == PORT3)
reg = GPIO3_PUDEN;
else
reg = GPIO_PUDEN(pin);
if (!gpio_getbit(info->membase[0], reg, PORT_PIN(pin))) {
*config = LTQ_PINCONF_PACK(param, 0);
break;
}
if (port == PORT3)
reg = GPIO3_PUDSEL;
else
reg = GPIO_PUDSEL(pin);
if (!gpio_getbit(info->membase[0], reg, PORT_PIN(pin)))
*config = LTQ_PINCONF_PACK(param, 2);
else
*config = LTQ_PINCONF_PACK(param, 1);
break;
case LTQ_PINCONF_PARAM_OUTPUT:
reg = GPIO_DIR(pin);
*config = LTQ_PINCONF_PACK(param,
gpio_getbit(info->membase[0], reg, PORT_PIN(pin)));
break;
default:
dev_err(pctldev->dev, "Invalid config param %04x\n", param);
return -ENOTSUPP;
}
return 0;
}
static int xway_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs)
{
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctldev);
enum ltq_pinconf_param param;
int arg;
int port = PORT(pin);
u32 reg;
int i;
for (i = 0; i < num_configs; i++) {
param = LTQ_PINCONF_UNPACK_PARAM(configs[i]);
arg = LTQ_PINCONF_UNPACK_ARG(configs[i]);
switch (param) {
case LTQ_PINCONF_PARAM_OPEN_DRAIN:
if (port == PORT3)
reg = GPIO3_OD;
else
reg = GPIO_OD(pin);
if (arg == 0)
gpio_setbit(info->membase[0],
reg,
PORT_PIN(pin));
else
gpio_clearbit(info->membase[0],
reg,
PORT_PIN(pin));
break;
case LTQ_PINCONF_PARAM_PULL:
if (port == PORT3)
reg = GPIO3_PUDEN;
else
reg = GPIO_PUDEN(pin);
if (arg == 0) {
gpio_clearbit(info->membase[0],
reg,
PORT_PIN(pin));
break;
}
gpio_setbit(info->membase[0], reg, PORT_PIN(pin));
if (port == PORT3)
reg = GPIO3_PUDSEL;
else
reg = GPIO_PUDSEL(pin);
if (arg == 1)
gpio_clearbit(info->membase[0],
reg,
PORT_PIN(pin));
else if (arg == 2)
gpio_setbit(info->membase[0],
reg,
PORT_PIN(pin));
else
dev_err(pctldev->dev,
"Invalid pull value %d\n", arg);
break;
case LTQ_PINCONF_PARAM_OUTPUT:
reg = GPIO_DIR(pin);
if (arg == 0)
gpio_clearbit(info->membase[0],
reg,
PORT_PIN(pin));
else
gpio_setbit(info->membase[0],
reg,
PORT_PIN(pin));
break;
default:
dev_err(pctldev->dev,
"Invalid config param %04x\n", param);
return -ENOTSUPP;
}
}
return 0;
}
int xway_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned selector,
unsigned long *configs,
unsigned num_configs)
{
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctldev);
int i, ret = 0;
for (i = 0; i < info->grps[selector].npins && !ret; i++)
ret = xway_pinconf_set(pctldev,
info->grps[selector].pins[i],
configs,
num_configs);
return ret;
}
static inline int xway_mux_apply(struct pinctrl_dev *pctrldev,
int pin, int mux)
{
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);
int port = PORT(pin);
u32 alt1_reg = GPIO_ALT1(pin);
if (port == PORT3)
alt1_reg = GPIO3_ALT1;
if (mux & MUX_ALT0)
gpio_setbit(info->membase[0], GPIO_ALT0(pin), PORT_PIN(pin));
else
gpio_clearbit(info->membase[0], GPIO_ALT0(pin), PORT_PIN(pin));
if (mux & MUX_ALT1)
gpio_setbit(info->membase[0], alt1_reg, PORT_PIN(pin));
else
gpio_clearbit(info->membase[0], alt1_reg, PORT_PIN(pin));
return 0;
}
static void xway_gpio_set(struct gpio_chip *chip, unsigned int pin, int val)
{
struct ltq_pinmux_info *info = dev_get_drvdata(chip->dev);
if (val)
gpio_setbit(info->membase[0], GPIO_OUT(pin), PORT_PIN(pin));
else
gpio_clearbit(info->membase[0], GPIO_OUT(pin), PORT_PIN(pin));
}
static int xway_gpio_get(struct gpio_chip *chip, unsigned int pin)
{
struct ltq_pinmux_info *info = dev_get_drvdata(chip->dev);
return gpio_getbit(info->membase[0], GPIO_IN(pin), PORT_PIN(pin));
}
static int xway_gpio_dir_in(struct gpio_chip *chip, unsigned int pin)
{
struct ltq_pinmux_info *info = dev_get_drvdata(chip->dev);
gpio_clearbit(info->membase[0], GPIO_DIR(pin), PORT_PIN(pin));
return 0;
}
static int xway_gpio_dir_out(struct gpio_chip *chip, unsigned int pin, int val)
{
struct ltq_pinmux_info *info = dev_get_drvdata(chip->dev);
gpio_setbit(info->membase[0], GPIO_DIR(pin), PORT_PIN(pin));
xway_gpio_set(chip, pin, val);
return 0;
}
static int xway_gpio_req(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
return pinctrl_request_gpio(gpio);
}
static void xway_gpio_free(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
pinctrl_free_gpio(gpio);
}
static int pinmux_xway_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct pinctrl_xway_soc *xway_soc;
struct resource *res;
int ret, i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xway_info.membase[0] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xway_info.membase[0]))
return PTR_ERR(xway_info.membase[0]);
match = of_match_device(xway_match, &pdev->dev);
if (match)
xway_soc = (const struct pinctrl_xway_soc *) match->data;
else
xway_soc = &soc_cfg[0];
xway_chip.ngpio = xway_soc->pin_count;
xway_info.pads = devm_kzalloc(&pdev->dev,
sizeof(struct pinctrl_pin_desc) * xway_chip.ngpio,
GFP_KERNEL);
if (!xway_info.pads) {
dev_err(&pdev->dev, "Failed to allocate pads\n");
return -ENOMEM;
}
for (i = 0; i < xway_chip.ngpio; i++) {
char *name = devm_kzalloc(&pdev->dev, 5, GFP_KERNEL);
if (!name) {
dev_err(&pdev->dev, "Failed to allocate pad name\n");
return -ENOMEM;
}
snprintf(name, 5, "io%d", i);
xway_info.pads[i].number = GPIO0 + i;
xway_info.pads[i].name = name;
}
xway_pctrl_desc.pins = xway_info.pads;
xway_chip.dev = &pdev->dev;
of_gpiochip_add(&xway_chip);
ret = gpiochip_add(&xway_chip);
if (ret) {
of_gpiochip_remove(&xway_chip);
dev_err(&pdev->dev, "Failed to register gpio chip\n");
return ret;
}
xway_pctrl_desc.name = dev_name(&pdev->dev);
xway_pctrl_desc.npins = xway_chip.ngpio;
xway_info.num_pads = xway_chip.ngpio;
xway_info.num_mfp = xway_chip.ngpio;
xway_info.mfp = xway_soc->mfp;
xway_info.grps = xway_soc->grps;
xway_info.num_grps = xway_soc->num_grps;
xway_info.funcs = xway_soc->funcs;
xway_info.num_funcs = xway_soc->num_funcs;
xway_info.exin = xway_soc->exin;
xway_info.num_exin = xway_soc->num_exin;
ret = ltq_pinctrl_register(pdev, &xway_info);
if (ret) {
gpiochip_remove(&xway_chip);
dev_err(&pdev->dev, "Failed to register pinctrl driver\n");
return ret;
}
xway_gpio_range.npins = xway_chip.ngpio;
xway_gpio_range.base = xway_chip.base;
pinctrl_add_gpio_range(xway_info.pctrl, &xway_gpio_range);
dev_info(&pdev->dev, "Init done\n");
return 0;
}
static int __init pinmux_xway_init(void)
{
return platform_driver_register(&pinmux_xway_driver);
}
