static const struct mrfld_family *mrfld_get_family(struct mrfld_pinctrl *mp,
unsigned int pin)
{
const struct mrfld_family *family;
unsigned int i;
for (i = 0; i < mp->nfamilies; i++) {
family = &mp->families[i];
if (pin >= family->pin_base &&
pin < family->pin_base + family->npins)
return family;
}
dev_warn(mp->dev, "failed to find family for pin %u\n", pin);
return NULL;
}
static bool mrfld_buf_available(struct mrfld_pinctrl *mp, unsigned int pin)
{
const struct mrfld_family *family;
family = mrfld_get_family(mp, pin);
if (!family)
return false;
return !family->protected;
}
static void __iomem *mrfld_get_bufcfg(struct mrfld_pinctrl *mp, unsigned int pin)
{
const struct mrfld_family *family;
unsigned int bufno;
family = mrfld_get_family(mp, pin);
if (!family)
return NULL;
bufno = pin_to_bufno(family, pin);
return family->regs + BUFCFG_OFFSET + bufno * 4;
}
static int mrfld_get_groups_count(struct pinctrl_dev *pctldev)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
return mp->ngroups;
}
static const char *mrfld_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
return mp->groups[group].name;
}
static int mrfld_get_group_pins(struct pinctrl_dev *pctldev, unsigned int group,
const unsigned int **pins, unsigned int *npins)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
*pins = mp->groups[group].pins;
*npins = mp->groups[group].npins;
return 0;
}
static void mrfld_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned int pin)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
void __iomem *bufcfg;
u32 value, mode;
if (!mrfld_buf_available(mp, pin)) {
seq_puts(s, "not available");
return;
}
bufcfg = mrfld_get_bufcfg(mp, pin);
value = readl(bufcfg);
mode = (value & BUFCFG_PINMODE_MASK) >> BUFCFG_PINMODE_SHIFT;
if (!mode)
seq_puts(s, "GPIO ");
else
seq_printf(s, "mode %d ", mode);
seq_printf(s, "0x%08x", value);
}
static int mrfld_get_functions_count(struct pinctrl_dev *pctldev)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
return mp->nfunctions;
}
static const char *mrfld_get_function_name(struct pinctrl_dev *pctldev,
unsigned int function)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
return mp->functions[function].name;
}
static int mrfld_get_function_groups(struct pinctrl_dev *pctldev,
unsigned int function,
const char * const **groups,
unsigned int * const ngroups)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
*groups = mp->functions[function].groups;
*ngroups = mp->functions[function].ngroups;
return 0;
}
static void mrfld_update_bufcfg(struct mrfld_pinctrl *mp, unsigned int pin,
u32 bits, u32 mask)
{
void __iomem *bufcfg;
u32 value;
bufcfg = mrfld_get_bufcfg(mp, pin);
value = readl(bufcfg);
value &= ~mask;
value |= bits & mask;
writel(value, bufcfg);
}
static int mrfld_pinmux_set_mux(struct pinctrl_dev *pctldev,
unsigned int function,
unsigned int group)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
const struct intel_pingroup *grp = &mp->groups[group];
u32 bits = grp->mode << BUFCFG_PINMODE_SHIFT;
u32 mask = BUFCFG_PINMODE_MASK;
unsigned long flags;
unsigned int i;
for (i = 0; i < grp->npins; i++) {
if (!mrfld_buf_available(mp, grp->pins[i]))
return -EBUSY;
}
raw_spin_lock_irqsave(&mp->lock, flags);
for (i = 0; i < grp->npins; i++)
mrfld_update_bufcfg(mp, grp->pins[i], bits, mask);
raw_spin_unlock_irqrestore(&mp->lock, flags);
return 0;
}
static int mrfld_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
u32 bits = BUFCFG_PINMODE_GPIO << BUFCFG_PINMODE_SHIFT;
u32 mask = BUFCFG_PINMODE_MASK;
unsigned long flags;
if (!mrfld_buf_available(mp, pin))
return -EBUSY;
raw_spin_lock_irqsave(&mp->lock, flags);
mrfld_update_bufcfg(mp, pin, bits, mask);
raw_spin_unlock_irqrestore(&mp->lock, flags);
return 0;
}
static int mrfld_config_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
u32 value, term;
u16 arg = 0;
if (!mrfld_buf_available(mp, pin))
return -ENOTSUPP;
value = readl(mrfld_get_bufcfg(mp, pin));
term = (value & BUFCFG_PUPD_VAL_MASK) >> BUFCFG_PUPD_VAL_SHIFT;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (value & BUFCFG_Px_EN_MASK)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if ((value & BUFCFG_Px_EN_MASK) != BUFCFG_PU_EN)
return -EINVAL;
switch (term) {
case BUFCFG_PUPD_VAL_910:
arg = 910;
break;
case BUFCFG_PUPD_VAL_2K:
arg = 2000;
break;
case BUFCFG_PUPD_VAL_20K:
arg = 20000;
break;
case BUFCFG_PUPD_VAL_50K:
arg = 50000;
break;
}
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if ((value & BUFCFG_Px_EN_MASK) != BUFCFG_PD_EN)
return -EINVAL;
switch (term) {
case BUFCFG_PUPD_VAL_910:
arg = 910;
break;
case BUFCFG_PUPD_VAL_2K:
arg = 2000;
break;
case BUFCFG_PUPD_VAL_20K:
arg = 20000;
break;
case BUFCFG_PUPD_VAL_50K:
arg = 50000;
break;
}
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (!(value & BUFCFG_OD_EN))
return -EINVAL;
break;
case PIN_CONFIG_SLEW_RATE:
if (!(value & BUFCFG_SLEWSEL))
arg = 0;
else
arg = 1;
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int mrfld_config_set_pin(struct mrfld_pinctrl *mp, unsigned int pin,
unsigned long config)
{
unsigned int param = pinconf_to_config_param(config);
unsigned int arg = pinconf_to_config_argument(config);
u32 bits = 0, mask = 0;
unsigned long flags;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
mask |= BUFCFG_Px_EN_MASK | BUFCFG_PUPD_VAL_MASK;
break;
case PIN_CONFIG_BIAS_PULL_UP:
mask |= BUFCFG_Px_EN_MASK | BUFCFG_PUPD_VAL_MASK;
bits |= BUFCFG_PU_EN;
switch (arg) {
case 50000:
bits |= BUFCFG_PUPD_VAL_50K << BUFCFG_PUPD_VAL_SHIFT;
break;
case 20000:
bits |= BUFCFG_PUPD_VAL_20K << BUFCFG_PUPD_VAL_SHIFT;
break;
case 2000:
bits |= BUFCFG_PUPD_VAL_2K << BUFCFG_PUPD_VAL_SHIFT;
break;
default:
return -EINVAL;
}
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
mask |= BUFCFG_Px_EN_MASK | BUFCFG_PUPD_VAL_MASK;
bits |= BUFCFG_PD_EN;
switch (arg) {
case 50000:
bits |= BUFCFG_PUPD_VAL_50K << BUFCFG_PUPD_VAL_SHIFT;
break;
case 20000:
bits |= BUFCFG_PUPD_VAL_20K << BUFCFG_PUPD_VAL_SHIFT;
break;
case 2000:
bits |= BUFCFG_PUPD_VAL_2K << BUFCFG_PUPD_VAL_SHIFT;
break;
default:
return -EINVAL;
}
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
mask |= BUFCFG_OD_EN;
if (arg)
bits |= BUFCFG_OD_EN;
break;
case PIN_CONFIG_SLEW_RATE:
mask |= BUFCFG_SLEWSEL;
if (arg)
bits |= BUFCFG_SLEWSEL;
break;
}
raw_spin_lock_irqsave(&mp->lock, flags);
mrfld_update_bufcfg(mp, pin, bits, mask);
raw_spin_unlock_irqrestore(&mp->lock, flags);
return 0;
}
static int mrfld_config_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned int nconfigs)
{
struct mrfld_pinctrl *mp = pinctrl_dev_get_drvdata(pctldev);
unsigned int i;
int ret;
if (!mrfld_buf_available(mp, pin))
return -ENOTSUPP;
for (i = 0; i < nconfigs; i++) {
switch (pinconf_to_config_param(configs[i])) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
case PIN_CONFIG_SLEW_RATE:
ret = mrfld_config_set_pin(mp, pin, configs[i]);
if (ret)
return ret;
break;
default:
return -ENOTSUPP;
}
}
return 0;
}
static int mrfld_config_group_get(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *config)
{
const unsigned int *pins;
unsigned int npins;
int ret;
ret = mrfld_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
ret = mrfld_config_get(pctldev, pins[0], config);
if (ret)
return ret;
return 0;
}
static int mrfld_config_group_set(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *configs,
unsigned int num_configs)
{
const unsigned int *pins;
unsigned int npins;
int i, ret;
ret = mrfld_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
for (i = 0; i < npins; i++) {
ret = mrfld_config_set(pctldev, pins[i], configs, num_configs);
if (ret)
return ret;
}
return 0;
}
static int mrfld_pinctrl_probe(struct platform_device *pdev)
{
struct mrfld_family *families;
struct mrfld_pinctrl *mp;
struct resource *mem;
void __iomem *regs;
size_t nfamilies;
unsigned int i;
mp = devm_kzalloc(&pdev->dev, sizeof(*mp), GFP_KERNEL);
if (!mp)
return -ENOMEM;
mp->dev = &pdev->dev;
raw_spin_lock_init(&mp->lock);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(regs))
return PTR_ERR(regs);
nfamilies = ARRAY_SIZE(mrfld_families),
families = devm_kmemdup(&pdev->dev, mrfld_families,
sizeof(mrfld_families),
GFP_KERNEL);
if (!families)
return -ENOMEM;
for (i = 0; i < nfamilies; i++) {
struct mrfld_family *family = &families[i];
family->regs = regs + family->barno * MRFLD_FAMILY_LEN;
}
mp->families = families;
mp->nfamilies = nfamilies;
mp->functions = mrfld_functions;
mp->nfunctions = ARRAY_SIZE(mrfld_functions);
mp->groups = mrfld_groups;
mp->ngroups = ARRAY_SIZE(mrfld_groups);
mp->pctldesc = mrfld_pinctrl_desc;
mp->pctldesc.name = dev_name(&pdev->dev);
mp->pctldesc.pins = mrfld_pins;
mp->pctldesc.npins = ARRAY_SIZE(mrfld_pins);
mp->pctldev = devm_pinctrl_register(&pdev->dev, &mp->pctldesc, mp);
if (IS_ERR(mp->pctldev)) {
dev_err(&pdev->dev, "failed to register pinctrl driver\n");
return PTR_ERR(mp->pctldev);
}
platform_set_drvdata(pdev, mp);
return 0;
}
static int __init mrfld_pinctrl_init(void)
{
return platform_driver_register(&mrfld_pinctrl_driver);
}
static void __exit mrfld_pinctrl_exit(void)
{
platform_driver_unregister(&mrfld_pinctrl_driver);
}
