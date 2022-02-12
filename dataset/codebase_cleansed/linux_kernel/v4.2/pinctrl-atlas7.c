static inline struct atlas7_gpio_chip *to_atlas7_gpio(struct gpio_chip *gc)
{
return container_of(gc, struct atlas7_gpio_chip, chip);
}
static inline u32 atlas7_pin_to_bank(u32 pin)
{
return (pin >= ATLAS7_PINCTRL_BANK_0_PINS) ? 1 : 0;
}
static int atlas7_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->pctl_data->funcs_cnt;
}
static const char *atlas7_pmx_get_func_name(struct pinctrl_dev *pctldev,
u32 selector)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->pctl_data->funcs[selector].name;
}
static int atlas7_pmx_get_func_groups(struct pinctrl_dev *pctldev,
u32 selector, const char * const **groups,
u32 * const num_groups)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
*groups = pmx->pctl_data->funcs[selector].groups;
*num_groups = pmx->pctl_data->funcs[selector].num_groups;
return 0;
}
static void __atlas7_pmx_pin_input_disable_set(struct atlas7_pmx *pmx,
const struct atlas7_pad_mux *mux)
{
if (mux->dinput_reg && mux->dinput_val_reg) {
writel(DI_MASK << mux->dinput_bit,
pmx->regs[BANK_DS] + CLR_REG(mux->dinput_reg));
writel(DI_DISABLE << mux->dinput_bit,
pmx->regs[BANK_DS] + mux->dinput_reg);
writel(DIV_MASK << mux->dinput_val_bit,
pmx->regs[BANK_DS] + CLR_REG(mux->dinput_val_reg));
writel(DIV_DISABLE << mux->dinput_val_bit,
pmx->regs[BANK_DS] + mux->dinput_val_reg);
}
}
static void __atlas7_pmx_pin_input_disable_clr(struct atlas7_pmx *pmx,
const struct atlas7_pad_mux *mux)
{
if (mux->dinput_reg && mux->dinput_val_reg) {
writel(DI_MASK << mux->dinput_bit,
pmx->regs[BANK_DS] + CLR_REG(mux->dinput_reg));
writel(DI_ENABLE << mux->dinput_bit,
pmx->regs[BANK_DS] + mux->dinput_reg);
writel(DIV_MASK << mux->dinput_val_bit,
pmx->regs[BANK_DS] + CLR_REG(mux->dinput_val_reg));
writel(DIV_ENABLE << mux->dinput_val_bit,
pmx->regs[BANK_DS] + mux->dinput_val_reg);
}
}
static int __atlas7_pmx_pin_ad_sel(struct atlas7_pmx *pmx,
struct atlas7_pad_config *conf,
u32 bank, u32 ad_sel)
{
unsigned long regv;
writel(ANA_CLEAR_MASK << conf->ad_ctrl_bit,
pmx->regs[bank] + CLR_REG(conf->ad_ctrl_reg));
regv = readl(pmx->regs[bank] + conf->ad_ctrl_reg);
regv &= ~(ANA_CLEAR_MASK << conf->ad_ctrl_bit);
writel(regv | (ad_sel << conf->ad_ctrl_bit),
pmx->regs[bank] + conf->ad_ctrl_reg);
regv = readl(pmx->regs[bank] + conf->ad_ctrl_reg);
pr_debug("bank:%d reg:0x%04x val:0x%08lx\n",
bank, conf->ad_ctrl_reg, regv);
return 0;
}
static int __atlas7_pmx_pin_analog_enable(struct atlas7_pmx *pmx,
struct atlas7_pad_config *conf, u32 bank)
{
if (conf->type != PAD_T_AD)
return -EINVAL;
return __atlas7_pmx_pin_ad_sel(pmx, conf, bank, 0);
}
static int __atlas7_pmx_pin_digital_enable(struct atlas7_pmx *pmx,
struct atlas7_pad_config *conf, u32 bank)
{
if (conf->type != PAD_T_AD)
return 0;
return __atlas7_pmx_pin_ad_sel(pmx, conf, bank, 1);
}
static int __atlas7_pmx_pin_enable(struct atlas7_pmx *pmx,
u32 pin, u32 func)
{
struct atlas7_pad_config *conf;
u32 bank;
int ret;
unsigned long regv;
pr_debug("PMX DUMP ### pin#%d func:%d #### START >>>\n",
pin, func);
conf = &pmx->pctl_data->confs[pin];
bank = atlas7_pin_to_bank(pin);
if (FUNC_ANALOGUE == func) {
ret = __atlas7_pmx_pin_analog_enable(pmx, conf, bank);
if (ret)
dev_err(pmx->dev,
"Convert pad#%d to analog failed, ret=%d\n",
pin, ret);
return ret;
}
ret = __atlas7_pmx_pin_digital_enable(pmx, conf, bank);
if (ret) {
dev_err(pmx->dev,
"Convert pad#%d to digital failed, ret=%d\n",
pin, ret);
return ret;
}
writel(FUNC_CLEAR_MASK << conf->mux_bit,
pmx->regs[bank] + CLR_REG(conf->mux_reg));
regv = readl(pmx->regs[bank] + conf->mux_reg);
regv &= ~(FUNC_CLEAR_MASK << conf->mux_bit);
writel(regv | (func << conf->mux_bit),
pmx->regs[bank] + conf->mux_reg);
regv = readl(pmx->regs[bank] + conf->mux_reg);
pr_debug("bank:%d reg:0x%04x val:0x%08lx\n",
bank, conf->mux_reg, regv);
return 0;
}
static int atlas7_pmx_set_mux(struct pinctrl_dev *pctldev,
u32 func_selector, u32 group_selector)
{
int idx, ret;
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
struct atlas7_pmx_func *pmx_func;
struct atlas7_pin_group *pin_grp;
const struct atlas7_grp_mux *grp_mux;
const struct atlas7_pad_mux *mux;
pmx_func = &pmx->pctl_data->funcs[func_selector];
pin_grp = &pmx->pctl_data->grps[group_selector];
pr_debug("PMX DUMP ### Function:[%s] Group:[%s] #### START >>>\n",
pmx_func->name, pin_grp->name);
grp_mux = pmx_func->grpmux;
for (idx = 0; idx < grp_mux->pad_mux_count; idx++) {
mux = &grp_mux->pad_mux_list[idx];
__atlas7_pmx_pin_input_disable_set(pmx, mux);
ret = __atlas7_pmx_pin_enable(pmx, mux->pin, mux->func);
if (ret) {
dev_err(pmx->dev,
"FUNC:%s GRP:%s PIN#%d.%d failed, ret=%d\n",
pmx_func->name, pin_grp->name,
mux->pin, mux->func, ret);
BUG_ON(1);
}
__atlas7_pmx_pin_input_disable_clr(pmx, mux);
}
pr_debug("PMX DUMP ### Function:[%s] Group:[%s] #### END <<<\n",
pmx_func->name, pin_grp->name);
return 0;
}
static u32 convert_current_to_drive_strength(u32 type, u32 ma)
{
int idx;
for (idx = 0; idx < ARRAY_SIZE(atlas7_ds_map); idx++) {
if (atlas7_ds_map[idx].ma != ma)
continue;
if (type == PAD_T_4WE_PD || type == PAD_T_4WE_PU)
return atlas7_ds_map[idx].ds_4we;
else if (type == PAD_T_16ST)
return atlas7_ds_map[idx].ds_16st;
else if (type == PAD_T_M31_0204_PD || type == PAD_T_M31_0204_PU)
return atlas7_ds_map[idx].ds_0204m31;
else if (type == PAD_T_M31_0610_PD || type == PAD_T_M31_0610_PU)
return atlas7_ds_map[idx].ds_0610m31;
}
return DS_NULL;
}
static int altas7_pinctrl_set_pull_sel(struct pinctrl_dev *pctldev,
u32 pin, u32 sel)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
struct atlas7_pad_config *conf = &pmx->pctl_data->confs[pin];
u32 type = conf->type;
u32 shift = conf->pupd_bit;
u32 bank = atlas7_pin_to_bank(pin);
void __iomem *pull_sel_reg, *pull_clr_reg;
pull_sel_reg = pmx->regs[bank] + conf->pupd_reg;
pull_clr_reg = CLR_REG(pull_sel_reg);
if (type == PAD_T_4WE_PD || type == PAD_T_4WE_PU) {
writel(P4WE_PULL_MASK << shift, pull_clr_reg);
if (sel == PULL_UP)
writel(P4WE_PULL_UP << shift, pull_sel_reg);
else if (sel == HIGH_HYSTERESIS)
writel(P4WE_HIGH_HYSTERESIS << shift, pull_sel_reg);
else if (sel == HIGH_Z)
writel(P4WE_HIGH_Z << shift, pull_sel_reg);
else if (sel == PULL_DOWN)
writel(P4WE_PULL_DOWN << shift, pull_sel_reg);
else {
pr_err("Unknown Pull select type for 4WEPAD#%d\n",
pin);
return -ENOTSUPP;
}
} else if (type == PAD_T_16ST) {
writel(P16ST_PULL_MASK << shift, pull_clr_reg);
if (sel == PULL_UP)
writel(P16ST_PULL_UP << shift, pull_sel_reg);
else if (sel == HIGH_Z)
writel(P16ST_HIGH_Z << shift, pull_sel_reg);
else if (sel == PULL_DOWN)
writel(P16ST_PULL_DOWN << shift, pull_sel_reg);
else {
pr_err("Unknown Pull select type for 16STPAD#%d\n",
pin);
return -ENOTSUPP;
}
} else if (type == PAD_T_M31_0204_PD ||
type == PAD_T_M31_0204_PU ||
type == PAD_T_M31_0610_PD ||
type == PAD_T_M31_0610_PU) {
writel(PM31_PULL_MASK << shift, pull_clr_reg);
if (sel == PULL_UP)
writel(PM31_PULL_ENABLED << shift, pull_sel_reg);
else if (sel == PULL_DOWN)
writel(PM31_PULL_DISABLED << shift, pull_sel_reg);
else {
pr_err("Unknown Pull select type for M31PAD#%d\n",
pin);
return -ENOTSUPP;
}
} else if (type == PAD_T_AD) {
writel(PANGD_PULL_MASK << shift, pull_clr_reg);
if (sel == PULL_UP)
writel(PANGD_PULL_UP << shift, pull_sel_reg);
else if (sel == HIGH_Z)
writel(PANGD_HIGH_Z << shift, pull_sel_reg);
else if (sel == PULL_DOWN)
writel(PANGD_PULL_DOWN << shift, pull_sel_reg);
else {
pr_err("Unknown Pull select type for A/D PAD#%d\n",
pin);
return -ENOTSUPP;
}
} else {
pr_err("Unknown Pad type[%d] for pull select PAD#%d\n",
type, pin);
return -ENOTSUPP;
}
pr_debug("PIN_CFG ### SET PIN#%d PULL SELECTOR:%d == OK ####\n",
pin, sel);
return 0;
}
static int __altas7_pinctrl_set_drive_strength_sel(struct pinctrl_dev *pctldev,
u32 pin, u32 sel)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
struct atlas7_pad_config *conf = &pmx->pctl_data->confs[pin];
u32 type = conf->type;
u32 shift = conf->drvstr_bit;
u32 bank = atlas7_pin_to_bank(pin);
void __iomem *ds_sel_reg, *ds_clr_reg;
ds_sel_reg = pmx->regs[bank] + conf->drvstr_reg;
ds_clr_reg = CLR_REG(ds_sel_reg);
if (type == PAD_T_4WE_PD || type == PAD_T_4WE_PU) {
if (sel & (~DS_2BIT_MASK))
goto unsupport;
writel(DS_2BIT_IM_VAL << shift, ds_clr_reg);
writel(sel << shift, ds_sel_reg);
return 0;
} else if (type == PAD_T_16ST) {
if (sel & (~DS_4BIT_MASK))
goto unsupport;
writel(DS_4BIT_IM_VAL << shift, ds_clr_reg);
writel(sel << shift, ds_sel_reg);
return 0;
} else if (type == PAD_T_M31_0204_PD || type == PAD_T_M31_0204_PU ||
type == PAD_T_M31_0610_PD || type == PAD_T_M31_0610_PU) {
if (sel & (~DS_1BIT_MASK))
goto unsupport;
writel(DS_1BIT_IM_VAL << shift, ds_clr_reg);
writel(sel << shift, ds_sel_reg);
return 0;
}
unsupport:
pr_err("Pad#%d type[%d] doesn't support ds code[%d]!\n",
pin, type, sel);
return -ENOTSUPP;
}
static int altas7_pinctrl_set_drive_strength_sel(struct pinctrl_dev *pctldev,
u32 pin, u32 ma)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
struct atlas7_pad_config *conf = &pmx->pctl_data->confs[pin];
u32 type = conf->type;
u32 sel;
int ret;
sel = convert_current_to_drive_strength(conf->type, ma);
if (DS_NULL == sel) {
pr_err("Pad#%d type[%d] doesn't support ds current[%d]!\n",
pin, type, ma);
return -ENOTSUPP;
}
ret = __altas7_pinctrl_set_drive_strength_sel(pctldev,
pin, sel);
pr_debug("PIN_CFG ### SET PIN#%d DS:%d MA:%d == %s ####\n",
pin, sel, ma, ret?"FAILED":"OK");
return ret;
}
static int atlas7_pmx_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, u32 pin)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
u32 idx;
dev_dbg(pmx->dev,
"atlas7_pmx_gpio_request_enable: pin=%d\n", pin);
for (idx = 0; idx < range->npins; idx++) {
if (pin == range->pins[idx])
break;
}
if (idx >= range->npins) {
dev_err(pmx->dev,
"The pin#%d could not be requested as GPIO!!\n",
pin);
return -EPERM;
}
__atlas7_pmx_pin_enable(pmx, pin, FUNC_GPIO);
return 0;
}
static int atlas7_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->pctl_data->grps_cnt;
}
static const char *atlas7_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
u32 group)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->pctl_data->grps[group].name;
}
static int atlas7_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
u32 group, const u32 **pins, u32 *num_pins)
{
struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
*num_pins = pmx->pctl_data->grps[group].num_pins;
*pins = pmx->pctl_data->grps[group].pins;
return 0;
}
static int atlas7_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map,
u32 *num_maps)
{
return pinconf_generic_dt_node_to_map(pctldev, np_config, map,
num_maps, PIN_MAP_TYPE_INVALID);
}
static void atlas7_pinctrl_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, u32 num_maps)
{
kfree(map);
}
static int atlas7_pin_config_set(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *configs,
unsigned num_configs)
{
u16 param, arg;
int idx, err;
for (idx = 0; idx < num_configs; idx++) {
param = pinconf_to_config_param(configs[idx]);
arg = pinconf_to_config_argument(configs[idx]);
pr_debug("PMX CFG###### ATLAS7 PIN#%d [%s] CONFIG PARAM:%d ARG:%d >>>>>\n",
pin, atlas7_ioc_pads[pin].name, param, arg);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
err = altas7_pinctrl_set_pull_sel(pctldev,
pin, PULL_UP);
if (err)
return err;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
err = altas7_pinctrl_set_pull_sel(pctldev,
pin, PULL_DOWN);
if (err)
return err;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
err = altas7_pinctrl_set_pull_sel(pctldev,
pin, HIGH_HYSTERESIS);
if (err)
return err;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
err = altas7_pinctrl_set_pull_sel(pctldev,
pin, HIGH_Z);
if (err)
return err;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
err = altas7_pinctrl_set_drive_strength_sel(pctldev,
pin, arg);
if (err)
return err;
break;
default:
return -ENOTSUPP;
}
pr_debug("PMX CFG###### ATLAS7 PIN#%d [%s] CONFIG PARAM:%d ARG:%d <<<<\n",
pin, atlas7_ioc_pads[pin].name, param, arg);
}
return 0;
}
static int atlas7_pin_config_group_set(struct pinctrl_dev *pctldev,
unsigned group, unsigned long *configs,
unsigned num_configs)
{
const unsigned *pins;
unsigned npins;
int i, ret;
ret = atlas7_pinctrl_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
for (i = 0; i < npins; i++) {
if (atlas7_pin_config_set(pctldev, pins[i],
configs, num_configs))
return -ENOTSUPP;
}
return 0;
}
static int atlas7_pinmux_probe(struct platform_device *pdev)
{
int ret, idx;
struct atlas7_pmx *pmx;
struct device_node *np = pdev->dev.of_node;
u32 banks = ATLAS7_PINCTRL_REG_BANKS;
pmx = devm_kzalloc(&pdev->dev, sizeof(*pmx), GFP_KERNEL);
if (!pmx)
return -ENOMEM;
pmx->dev = &pdev->dev;
pmx->pctl_data = &atlas7_ioc_data;
pmx->pctl_desc.name = "pinctrl-atlas7";
pmx->pctl_desc.pins = pmx->pctl_data->pads;
pmx->pctl_desc.npins = pmx->pctl_data->pads_cnt;
pmx->pctl_desc.pctlops = &atlas7_pinctrl_ops;
pmx->pctl_desc.pmxops = &atlas7_pinmux_ops;
pmx->pctl_desc.confops = &atlas7_pinconf_ops;
for (idx = 0; idx < banks; idx++) {
pmx->regs[idx] = of_iomap(np, idx);
if (!pmx->regs[idx]) {
dev_err(&pdev->dev,
"can't map ioc bank#%d registers\n", idx);
ret = -ENOMEM;
goto unmap_io;
}
}
pmx->pctl = pinctrl_register(&pmx->pctl_desc, &pdev->dev, pmx);
if (IS_ERR(pmx->pctl)) {
dev_err(&pdev->dev, "could not register atlas7 pinmux driver\n");
ret = PTR_ERR(pmx->pctl);
goto unmap_io;
}
platform_set_drvdata(pdev, pmx);
dev_info(&pdev->dev, "initialized atlas7 pinmux driver\n");
return 0;
unmap_io:
for (idx = 0; idx < banks; idx++) {
if (!pmx->regs[idx])
break;
iounmap(pmx->regs[idx]);
}
return ret;
}
static int __init atlas7_pinmux_init(void)
{
return platform_driver_register(&atlas7_pinmux_driver);
}
static inline struct
atlas7_gpio_bank *atlas7_gpio_to_bank(struct atlas7_gpio_chip *a7gc, u32 gpio)
{
return &a7gc->banks[GPIO_TO_BANK(gpio)];
}
static int __atlas7_gpio_to_pin(struct atlas7_gpio_chip *a7gc, u32 gpio)
{
struct atlas7_gpio_bank *bank;
u32 ofs;
bank = atlas7_gpio_to_bank(a7gc, gpio);
ofs = gpio - bank->gpio_offset;
if (ofs >= bank->ngpio)
return -ENODEV;
return bank->gpio_pins[ofs];
}
static void atlas7_gpio_irq_ack(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(gc);
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 val, pin_in_bank;
unsigned long flags;
bank = atlas7_gpio_to_bank(a7gc, d->hwirq);
pin_in_bank = d->hwirq - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
spin_lock_irqsave(&a7gc->lock, flags);
val = readl(ctrl_reg);
writel(val, ctrl_reg);
spin_unlock_irqrestore(&a7gc->lock, flags);
}
static void __atlas7_gpio_irq_mask(struct atlas7_gpio_chip *a7gc, int idx)
{
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 val, pin_in_bank;
bank = atlas7_gpio_to_bank(a7gc, idx);
pin_in_bank = idx - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
val = readl(ctrl_reg);
val &= ~(ATLAS7_GPIO_CTL_INTR_EN_MASK |
ATLAS7_GPIO_CTL_INTR_STATUS_MASK);
writel(val, ctrl_reg);
}
static void atlas7_gpio_irq_mask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(gc);
unsigned long flags;
spin_lock_irqsave(&a7gc->lock, flags);
__atlas7_gpio_irq_mask(a7gc, d->hwirq);
spin_unlock_irqrestore(&a7gc->lock, flags);
}
static void atlas7_gpio_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(gc);
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 val, pin_in_bank;
unsigned long flags;
bank = atlas7_gpio_to_bank(a7gc, d->hwirq);
pin_in_bank = d->hwirq - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
spin_lock_irqsave(&a7gc->lock, flags);
val = readl(ctrl_reg);
val &= ~ATLAS7_GPIO_CTL_INTR_STATUS_MASK;
val |= ATLAS7_GPIO_CTL_INTR_EN_MASK;
writel(val, ctrl_reg);
spin_unlock_irqrestore(&a7gc->lock, flags);
}
static int atlas7_gpio_irq_type(struct irq_data *d,
unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(gc);
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 val, pin_in_bank;
unsigned long flags;
bank = atlas7_gpio_to_bank(a7gc, d->hwirq);
pin_in_bank = d->hwirq - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
spin_lock_irqsave(&a7gc->lock, flags);
val = readl(ctrl_reg);
val &= ~(ATLAS7_GPIO_CTL_INTR_STATUS_MASK |
ATLAS7_GPIO_CTL_INTR_EN_MASK);
switch (type) {
case IRQ_TYPE_NONE:
break;
case IRQ_TYPE_EDGE_RISING:
val |= ATLAS7_GPIO_CTL_INTR_HIGH_MASK |
ATLAS7_GPIO_CTL_INTR_TYPE_MASK;
val &= ~ATLAS7_GPIO_CTL_INTR_LOW_MASK;
break;
case IRQ_TYPE_EDGE_FALLING:
val &= ~ATLAS7_GPIO_CTL_INTR_HIGH_MASK;
val |= ATLAS7_GPIO_CTL_INTR_LOW_MASK |
ATLAS7_GPIO_CTL_INTR_TYPE_MASK;
break;
case IRQ_TYPE_EDGE_BOTH:
val |= ATLAS7_GPIO_CTL_INTR_HIGH_MASK |
ATLAS7_GPIO_CTL_INTR_LOW_MASK |
ATLAS7_GPIO_CTL_INTR_TYPE_MASK;
break;
case IRQ_TYPE_LEVEL_LOW:
val &= ~(ATLAS7_GPIO_CTL_INTR_HIGH_MASK |
ATLAS7_GPIO_CTL_INTR_TYPE_MASK);
val |= ATLAS7_GPIO_CTL_INTR_LOW_MASK;
break;
case IRQ_TYPE_LEVEL_HIGH:
val |= ATLAS7_GPIO_CTL_INTR_HIGH_MASK;
val &= ~(ATLAS7_GPIO_CTL_INTR_LOW_MASK |
ATLAS7_GPIO_CTL_INTR_TYPE_MASK);
break;
}
writel(val, ctrl_reg);
spin_unlock_irqrestore(&a7gc->lock, flags);
return 0;
}
static void atlas7_gpio_handle_irq(unsigned int irq, struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(gc);
struct atlas7_gpio_bank *bank = NULL;
u32 status, ctrl;
int pin_in_bank = 0, idx;
struct irq_chip *chip = irq_get_chip(irq);
for (idx = 0; idx < a7gc->nbank; idx++) {
bank = &a7gc->banks[idx];
if (bank->irq == irq)
break;
}
BUG_ON(idx == a7gc->nbank);
chained_irq_enter(chip, desc);
status = readl(ATLAS7_GPIO_INT_STATUS(bank));
if (!status) {
pr_warn("%s: gpio [%s] status %#x no interrupt is flaged\n",
__func__, gc->label, status);
handle_bad_irq(irq, desc);
return;
}
while (status) {
ctrl = readl(ATLAS7_GPIO_CTRL(bank, pin_in_bank));
if ((status & 0x1) && (ctrl & ATLAS7_GPIO_CTL_INTR_EN_MASK)) {
pr_debug("%s: chip[%s] gpio:%d happens\n",
__func__, gc->label,
bank->gpio_offset + pin_in_bank);
generic_handle_irq(
irq_find_mapping(gc->irqdomain,
bank->gpio_offset + pin_in_bank));
}
if (++pin_in_bank >= bank->ngpio)
break;
status = status >> 1;
}
chained_irq_exit(chip, desc);
}
static void __atlas7_gpio_set_input(struct atlas7_gpio_chip *a7gc,
unsigned int gpio)
{
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 val, pin_in_bank;
bank = atlas7_gpio_to_bank(a7gc, gpio);
pin_in_bank = gpio - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
val = readl(ctrl_reg);
val &= ~ATLAS7_GPIO_CTL_OUT_EN_MASK;
writel(val, ctrl_reg);
}
static int atlas7_gpio_request(struct gpio_chip *chip,
unsigned int gpio)
{
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(chip);
int ret;
unsigned long flags;
ret = __atlas7_gpio_to_pin(a7gc, gpio);
if (ret < 0)
return ret;
if (pinctrl_request_gpio(chip->base + gpio))
return -ENODEV;
spin_lock_irqsave(&a7gc->lock, flags);
__atlas7_gpio_set_input(a7gc, gpio);
__atlas7_gpio_irq_mask(a7gc, gpio);
spin_unlock_irqrestore(&a7gc->lock, flags);
return 0;
}
static void atlas7_gpio_free(struct gpio_chip *chip,
unsigned int gpio)
{
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(chip);
unsigned long flags;
spin_lock_irqsave(&a7gc->lock, flags);
__atlas7_gpio_irq_mask(a7gc, gpio);
__atlas7_gpio_set_input(a7gc, gpio);
spin_unlock_irqrestore(&a7gc->lock, flags);
pinctrl_free_gpio(chip->base + gpio);
}
static int atlas7_gpio_direction_input(struct gpio_chip *chip,
unsigned int gpio)
{
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(chip);
unsigned long flags;
spin_lock_irqsave(&a7gc->lock, flags);
__atlas7_gpio_set_input(a7gc, gpio);
spin_unlock_irqrestore(&a7gc->lock, flags);
return 0;
}
static void __atlas7_gpio_set_output(struct atlas7_gpio_chip *a7gc,
unsigned int gpio, int value)
{
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 out_ctrl, pin_in_bank;
bank = atlas7_gpio_to_bank(a7gc, gpio);
pin_in_bank = gpio - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
out_ctrl = readl(ctrl_reg);
if (value)
out_ctrl |= ATLAS7_GPIO_CTL_DATAOUT_MASK;
else
out_ctrl &= ~ATLAS7_GPIO_CTL_DATAOUT_MASK;
out_ctrl &= ~ATLAS7_GPIO_CTL_INTR_EN_MASK;
out_ctrl |= ATLAS7_GPIO_CTL_OUT_EN_MASK;
writel(out_ctrl, ctrl_reg);
}
static int atlas7_gpio_direction_output(struct gpio_chip *chip,
unsigned int gpio, int value)
{
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(chip);
unsigned long flags;
spin_lock_irqsave(&a7gc->lock, flags);
__atlas7_gpio_set_output(a7gc, gpio, value);
spin_unlock_irqrestore(&a7gc->lock, flags);
return 0;
}
static int atlas7_gpio_get_value(struct gpio_chip *chip,
unsigned int gpio)
{
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(chip);
struct atlas7_gpio_bank *bank;
u32 val, pin_in_bank;
unsigned long flags;
bank = atlas7_gpio_to_bank(a7gc, gpio);
pin_in_bank = gpio - bank->gpio_offset;
spin_lock_irqsave(&a7gc->lock, flags);
val = readl(ATLAS7_GPIO_CTRL(bank, pin_in_bank));
spin_unlock_irqrestore(&a7gc->lock, flags);
return !!(val & ATLAS7_GPIO_CTL_DATAIN_MASK);
}
static void atlas7_gpio_set_value(struct gpio_chip *chip,
unsigned int gpio, int value)
{
struct atlas7_gpio_chip *a7gc = to_atlas7_gpio(chip);
struct atlas7_gpio_bank *bank;
void __iomem *ctrl_reg;
u32 ctrl, pin_in_bank;
unsigned long flags;
bank = atlas7_gpio_to_bank(a7gc, gpio);
pin_in_bank = gpio - bank->gpio_offset;
ctrl_reg = ATLAS7_GPIO_CTRL(bank, pin_in_bank);
spin_lock_irqsave(&a7gc->lock, flags);
ctrl = readl(ctrl_reg);
if (value)
ctrl |= ATLAS7_GPIO_CTL_DATAOUT_MASK;
else
ctrl &= ~ATLAS7_GPIO_CTL_DATAOUT_MASK;
writel(ctrl, ctrl_reg);
spin_unlock_irqrestore(&a7gc->lock, flags);
}
static int atlas7_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct atlas7_gpio_chip *a7gc;
struct gpio_chip *chip;
u32 nbank;
int ret, idx;
ret = of_property_read_u32(np, "gpio-banks", &nbank);
if (ret) {
dev_err(&pdev->dev,
"Could not find GPIO bank info,ret=%d!\n",
ret);
return ret;
}
a7gc = devm_kzalloc(&pdev->dev, sizeof(*a7gc) +
sizeof(struct atlas7_gpio_bank) * nbank, GFP_KERNEL);
if (!a7gc)
return -ENOMEM;
a7gc->clk = of_clk_get(np, 0);
if (!IS_ERR(a7gc->clk)) {
ret = clk_prepare_enable(a7gc->clk);
if (ret) {
dev_err(&pdev->dev,
"Could not enable clock!\n");
return ret;
}
}
a7gc->reg = of_iomap(np, 0);
if (!a7gc->reg) {
dev_err(&pdev->dev, "Could not map GPIO Registers!\n");
return -ENOMEM;
}
a7gc->nbank = nbank;
spin_lock_init(&a7gc->lock);
chip = &a7gc->chip;
chip->request = atlas7_gpio_request;
chip->free = atlas7_gpio_free;
chip->direction_input = atlas7_gpio_direction_input;
chip->get = atlas7_gpio_get_value;
chip->direction_output = atlas7_gpio_direction_output;
chip->set = atlas7_gpio_set_value;
chip->base = -1;
chip->ngpio = NGPIO_OF_BANK * nbank;
chip->label = kstrdup(np->name, GFP_KERNEL);
chip->of_node = np;
chip->of_gpio_n_cells = 2;
chip->dev = &pdev->dev;
ret = gpiochip_add(chip);
if (ret) {
dev_err(&pdev->dev,
"%s: error in probe function with status %d\n",
np->name, ret);
goto failed;
}
ret = gpiochip_irqchip_add(chip, &atlas7_gpio_irq_chip,
0, handle_level_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(&pdev->dev,
"could not connect irqchip to gpiochip\n");
goto failed;
}
for (idx = 0; idx < nbank; idx++) {
struct gpio_pin_range *pin_range;
struct atlas7_gpio_bank *bank;
bank = &a7gc->banks[idx];
bank->base = ATLAS7_GPIO_BASE(a7gc, idx);
ret = of_irq_get(np, idx);
if (ret == -EPROBE_DEFER) {
dev_err(&pdev->dev,
"Unable to find IRQ number. ret=%d\n", ret);
goto failed;
}
bank->irq = ret;
gpiochip_set_chained_irqchip(chip, &atlas7_gpio_irq_chip,
bank->irq, atlas7_gpio_handle_irq);
list_for_each_entry(pin_range, &chip->pin_ranges, node) {
struct pinctrl_gpio_range *range;
range = &pin_range->range;
if (range->id == NGPIO_OF_BANK * idx) {
bank->gpio_offset = range->id;
bank->ngpio = range->npins;
bank->gpio_pins = range->pins;
bank->pctldev = pin_range->pctldev;
break;
}
}
BUG_ON(!bank->pctldev);
}
dev_info(&pdev->dev, "add to system.\n");
return 0;
failed:
return ret;
}
static int __init atlas7_gpio_init(void)
{
return platform_driver_register(&atlas7_gpio_driver);
}
