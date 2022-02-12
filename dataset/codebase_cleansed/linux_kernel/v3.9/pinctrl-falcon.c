static void lantiq_load_pin_desc(struct pinctrl_pin_desc *d, int bank, int len)
{
int base = bank * PINS;
int i;
for (i = 0; i < len; i++) {
char *name = kzalloc(6, GFP_KERNEL);
snprintf(name, 6, "io%d", base + i);
d[i].number = base + i;
d[i].name = name;
}
pad_count[bank] = len;
}
static int falcon_pinconf_group_get(struct pinctrl_dev *pctrldev,
unsigned group, unsigned long *config)
{
return -ENOTSUPP;
}
static int falcon_pinconf_group_set(struct pinctrl_dev *pctrldev,
unsigned group, unsigned long config)
{
return -ENOTSUPP;
}
static int falcon_pinconf_get(struct pinctrl_dev *pctrldev,
unsigned pin, unsigned long *config)
{
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);
enum ltq_pinconf_param param = LTQ_PINCONF_UNPACK_PARAM(*config);
void __iomem *mem = info->membase[PORT(pin)];
switch (param) {
case LTQ_PINCONF_PARAM_DRIVE_CURRENT:
*config = LTQ_PINCONF_PACK(param,
!!pad_getbit(mem, LTQ_PADC_DCC, PORT_PIN(pin)));
break;
case LTQ_PINCONF_PARAM_SLEW_RATE:
*config = LTQ_PINCONF_PACK(param,
!!pad_getbit(mem, LTQ_PADC_SRC, PORT_PIN(pin)));
break;
case LTQ_PINCONF_PARAM_PULL:
if (pad_getbit(mem, LTQ_PADC_PDEN, PORT_PIN(pin)))
*config = LTQ_PINCONF_PACK(param, 1);
else if (pad_getbit(mem, LTQ_PADC_PUEN, PORT_PIN(pin)))
*config = LTQ_PINCONF_PACK(param, 2);
else
*config = LTQ_PINCONF_PACK(param, 0);
break;
default:
return -ENOTSUPP;
}
return 0;
}
static int falcon_pinconf_set(struct pinctrl_dev *pctrldev,
unsigned pin, unsigned long config)
{
enum ltq_pinconf_param param = LTQ_PINCONF_UNPACK_PARAM(config);
int arg = LTQ_PINCONF_UNPACK_ARG(config);
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);
void __iomem *mem = info->membase[PORT(pin)];
u32 reg;
switch (param) {
case LTQ_PINCONF_PARAM_DRIVE_CURRENT:
reg = LTQ_PADC_DCC;
break;
case LTQ_PINCONF_PARAM_SLEW_RATE:
reg = LTQ_PADC_SRC;
break;
case LTQ_PINCONF_PARAM_PULL:
if (arg == 1)
reg = LTQ_PADC_PDEN;
else
reg = LTQ_PADC_PUEN;
break;
default:
pr_err("%s: Invalid config param %04x\n",
pinctrl_dev_get_name(pctrldev), param);
return -ENOTSUPP;
}
pad_w32(mem, BIT(PORT_PIN(pin)), reg);
if (!(pad_r32(mem, reg) & BIT(PORT_PIN(pin))))
return -ENOTSUPP;
return 0;
}
static void falcon_pinconf_dbg_show(struct pinctrl_dev *pctrldev,
struct seq_file *s, unsigned offset)
{
unsigned long config;
struct pin_desc *desc;
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);
int port = PORT(offset);
seq_printf(s, " (port %d) mux %d -- ", port,
pad_r32(info->membase[port], LTQ_PADC_MUX(PORT_PIN(offset))));
config = LTQ_PINCONF_PACK(LTQ_PINCONF_PARAM_PULL, 0);
if (!falcon_pinconf_get(pctrldev, offset, &config))
seq_printf(s, "pull %d ",
(int)LTQ_PINCONF_UNPACK_ARG(config));
config = LTQ_PINCONF_PACK(LTQ_PINCONF_PARAM_DRIVE_CURRENT, 0);
if (!falcon_pinconf_get(pctrldev, offset, &config))
seq_printf(s, "drive-current %d ",
(int)LTQ_PINCONF_UNPACK_ARG(config));
config = LTQ_PINCONF_PACK(LTQ_PINCONF_PARAM_SLEW_RATE, 0);
if (!falcon_pinconf_get(pctrldev, offset, &config))
seq_printf(s, "slew-rate %d ",
(int)LTQ_PINCONF_UNPACK_ARG(config));
desc = pin_desc_get(pctrldev, offset);
if (desc) {
if (desc->gpio_owner)
seq_printf(s, " owner: %s", desc->gpio_owner);
} else {
seq_printf(s, " not registered");
}
}
static void falcon_pinconf_group_dbg_show(struct pinctrl_dev *pctrldev,
struct seq_file *s, unsigned selector)
{
}
static inline int falcon_mux_apply(struct pinctrl_dev *pctrldev,
int mfp, int mux)
{
struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);
int port = PORT(info->mfp[mfp].pin);
if ((port >= PORTS) || (!info->membase[port]))
return -ENODEV;
pad_w32(info->membase[port], mux,
LTQ_PADC_MUX(PORT_PIN(info->mfp[mfp].pin)));
return 0;
}
int pinctrl_falcon_get_range_size(int id)
{
u32 avail;
if ((id >= PORTS) || (!falcon_info.membase[id]))
return -EINVAL;
avail = pad_r32(falcon_info.membase[id], LTQ_PADC_AVAIL);
return fls(avail);
}
void pinctrl_falcon_add_gpio_range(struct pinctrl_gpio_range *range)
{
pinctrl_add_gpio_range(falcon_info.pctrl, range);
}
static int pinctrl_falcon_probe(struct platform_device *pdev)
{
struct device_node *np;
int pad_count = 0;
int ret = 0;
for_each_compatible_node(np, NULL, "lantiq,pad-falcon") {
struct platform_device *ppdev = of_find_device_by_node(np);
const __be32 *bank = of_get_property(np, "lantiq,bank", NULL);
struct resource res;
u32 avail;
int pins;
if (!of_device_is_available(np))
continue;
if (!ppdev) {
dev_err(&pdev->dev, "failed to find pad pdev\n");
continue;
}
if (!bank || *bank >= PORTS)
continue;
if (of_address_to_resource(np, 0, &res))
continue;
falcon_info.clk[*bank] = clk_get(&ppdev->dev, NULL);
if (IS_ERR(falcon_info.clk[*bank])) {
dev_err(&ppdev->dev, "failed to get clock\n");
return PTR_ERR(falcon_info.clk[*bank]);
}
falcon_info.membase[*bank] = devm_ioremap_resource(&pdev->dev,
&res);
if (IS_ERR(falcon_info.membase[*bank]))
return PTR_ERR(falcon_info.membase[*bank]);
avail = pad_r32(falcon_info.membase[*bank],
LTQ_PADC_AVAIL);
pins = fls(avail);
lantiq_load_pin_desc(&falcon_pads[pad_count], *bank, pins);
pad_count += pins;
clk_enable(falcon_info.clk[*bank]);
dev_dbg(&pdev->dev, "found %s with %d pads\n",
res.name, pins);
}
dev_dbg(&pdev->dev, "found a total of %d pads\n", pad_count);
falcon_pctrl_desc.name = dev_name(&pdev->dev);
falcon_pctrl_desc.npins = pad_count;
falcon_info.mfp = falcon_mfp;
falcon_info.num_mfp = ARRAY_SIZE(falcon_mfp);
falcon_info.grps = falcon_grps;
falcon_info.num_grps = ARRAY_SIZE(falcon_grps);
falcon_info.funcs = falcon_funcs;
falcon_info.num_funcs = ARRAY_SIZE(falcon_funcs);
ret = ltq_pinctrl_register(pdev, &falcon_info);
if (!ret)
dev_info(&pdev->dev, "Init done\n");
return ret;
}
int __init pinctrl_falcon_init(void)
{
return platform_driver_register(&pinctrl_falcon_driver);
}
