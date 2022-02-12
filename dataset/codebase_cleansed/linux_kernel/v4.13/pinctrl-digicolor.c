static int dc_get_groups_count(struct pinctrl_dev *pctldev)
{
return PINS_COUNT;
}
static const char *dc_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct dc_pinmap *pmap = pinctrl_dev_get_drvdata(pctldev);
return pmap->desc->pins[selector].name;
}
static int dc_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
struct dc_pinmap *pmap = pinctrl_dev_get_drvdata(pctldev);
*pins = &pmap->desc->pins[selector].number;
*num_pins = 1;
return 0;
}
static int dc_get_functions_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(dc_functions);
}
static const char *dc_get_fname(struct pinctrl_dev *pctldev, unsigned selector)
{
return dc_functions[selector];
}
static int dc_get_groups(struct pinctrl_dev *pctldev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct dc_pinmap *pmap = pinctrl_dev_get_drvdata(pctldev);
*groups = pmap->pin_names;
*num_groups = PINS_COUNT;
return 0;
}
static void dc_client_sel(int pin_num, int *reg, int *bit)
{
*bit = (pin_num % PINS_PER_COLLECTION) * 2;
*reg = GP_CLIENTSEL(pin_num/PINS_PER_COLLECTION);
if (*bit >= PINS_PER_COLLECTION) {
*bit -= PINS_PER_COLLECTION;
*reg += 1;
}
}
static int dc_set_mux(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct dc_pinmap *pmap = pinctrl_dev_get_drvdata(pctldev);
int bit_off, reg_off;
u8 reg;
dc_client_sel(group, &reg_off, &bit_off);
reg = readb_relaxed(pmap->regs + reg_off);
reg &= ~(3 << bit_off);
reg |= (selector << bit_off);
writeb_relaxed(reg, pmap->regs + reg_off);
return 0;
}
static int dc_pmx_request_gpio(struct pinctrl_dev *pcdev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct dc_pinmap *pmap = pinctrl_dev_get_drvdata(pcdev);
int bit_off, reg_off;
u8 reg;
dc_client_sel(offset, &reg_off, &bit_off);
reg = readb_relaxed(pmap->regs + reg_off);
if ((reg & (3 << bit_off)) != 0)
return -EBUSY;
return 0;
}
static int dc_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
struct dc_pinmap *pmap = gpiochip_get_data(chip);
int reg_off = GP_DRIVE0(gpio/PINS_PER_COLLECTION);
int bit_off = gpio % PINS_PER_COLLECTION;
u8 drive;
unsigned long flags;
spin_lock_irqsave(&pmap->lock, flags);
drive = readb_relaxed(pmap->regs + reg_off);
drive &= ~BIT(bit_off);
writeb_relaxed(drive, pmap->regs + reg_off);
spin_unlock_irqrestore(&pmap->lock, flags);
return 0;
}
static int dc_gpio_direction_output(struct gpio_chip *chip, unsigned gpio,
int value)
{
struct dc_pinmap *pmap = gpiochip_get_data(chip);
int reg_off = GP_DRIVE0(gpio/PINS_PER_COLLECTION);
int bit_off = gpio % PINS_PER_COLLECTION;
u8 drive;
unsigned long flags;
dc_gpio_set(chip, gpio, value);
spin_lock_irqsave(&pmap->lock, flags);
drive = readb_relaxed(pmap->regs + reg_off);
drive |= BIT(bit_off);
writeb_relaxed(drive, pmap->regs + reg_off);
spin_unlock_irqrestore(&pmap->lock, flags);
return 0;
}
static int dc_gpio_get(struct gpio_chip *chip, unsigned gpio)
{
struct dc_pinmap *pmap = gpiochip_get_data(chip);
int reg_off = GP_INPUT(gpio/PINS_PER_COLLECTION);
int bit_off = gpio % PINS_PER_COLLECTION;
u8 input;
input = readb_relaxed(pmap->regs + reg_off);
return !!(input & BIT(bit_off));
}
static void dc_gpio_set(struct gpio_chip *chip, unsigned gpio, int value)
{
struct dc_pinmap *pmap = gpiochip_get_data(chip);
int reg_off = GP_OUTPUT0(gpio/PINS_PER_COLLECTION);
int bit_off = gpio % PINS_PER_COLLECTION;
u8 output;
unsigned long flags;
spin_lock_irqsave(&pmap->lock, flags);
output = readb_relaxed(pmap->regs + reg_off);
if (value)
output |= BIT(bit_off);
else
output &= ~BIT(bit_off);
writeb_relaxed(output, pmap->regs + reg_off);
spin_unlock_irqrestore(&pmap->lock, flags);
}
static int dc_gpiochip_add(struct dc_pinmap *pmap, struct device_node *np)
{
struct gpio_chip *chip = &pmap->chip;
int ret;
chip->label = DRIVER_NAME;
chip->parent = pmap->dev;
chip->request = gpiochip_generic_request;
chip->free = gpiochip_generic_free;
chip->direction_input = dc_gpio_direction_input;
chip->direction_output = dc_gpio_direction_output;
chip->get = dc_gpio_get;
chip->set = dc_gpio_set;
chip->base = -1;
chip->ngpio = PINS_COUNT;
chip->of_node = np;
chip->of_gpio_n_cells = 2;
spin_lock_init(&pmap->lock);
ret = gpiochip_add_data(chip, pmap);
if (ret < 0)
return ret;
ret = gpiochip_add_pin_range(chip, dev_name(pmap->dev), 0, 0,
PINS_COUNT);
if (ret < 0) {
gpiochip_remove(chip);
return ret;
}
return 0;
}
static int dc_pinctrl_probe(struct platform_device *pdev)
{
struct dc_pinmap *pmap;
struct resource *r;
struct pinctrl_pin_desc *pins;
struct pinctrl_desc *pctl_desc;
char *pin_names;
int name_len = strlen("GP_xx") + 1;
int i, j;
pmap = devm_kzalloc(&pdev->dev, sizeof(*pmap), GFP_KERNEL);
if (!pmap)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pmap->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pmap->regs))
return PTR_ERR(pmap->regs);
pins = devm_kzalloc(&pdev->dev, sizeof(*pins)*PINS_COUNT, GFP_KERNEL);
if (!pins)
return -ENOMEM;
pin_names = devm_kzalloc(&pdev->dev, name_len * PINS_COUNT,
GFP_KERNEL);
if (!pin_names)
return -ENOMEM;
for (i = 0; i < PIN_COLLECTIONS; i++) {
for (j = 0; j < PINS_PER_COLLECTION; j++) {
int pin_id = i*PINS_PER_COLLECTION + j;
char *name = &pin_names[pin_id * name_len];
snprintf(name, name_len, "GP_%c%c", 'A'+i, '0'+j);
pins[pin_id].number = pin_id;
pins[pin_id].name = name;
pmap->pin_names[pin_id] = name;
}
}
pctl_desc = devm_kzalloc(&pdev->dev, sizeof(*pctl_desc), GFP_KERNEL);
if (!pctl_desc)
return -ENOMEM;
pctl_desc->name = DRIVER_NAME,
pctl_desc->owner = THIS_MODULE,
pctl_desc->pctlops = &dc_pinctrl_ops,
pctl_desc->pmxops = &dc_pmxops,
pctl_desc->npins = PINS_COUNT;
pctl_desc->pins = pins;
pmap->desc = pctl_desc;
pmap->dev = &pdev->dev;
pmap->pctl = devm_pinctrl_register(&pdev->dev, pctl_desc, pmap);
if (IS_ERR(pmap->pctl)) {
dev_err(&pdev->dev, "pinctrl driver registration failed\n");
return PTR_ERR(pmap->pctl);
}
return dc_gpiochip_add(pmap, pdev->dev.of_node);
}
