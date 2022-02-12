static inline struct lpc32xx_gpio_chip *to_lpc32xx_gpio(
struct gpio_chip *gpc)
{
return container_of(gpc, struct lpc32xx_gpio_chip, chip);
}
static void __set_gpio_dir_p012(struct lpc32xx_gpio_chip *group,
unsigned pin, int input)
{
if (input)
__raw_writel(GPIO012_PIN_TO_BIT(pin),
group->gpio_grp->dir_clr);
else
__raw_writel(GPIO012_PIN_TO_BIT(pin),
group->gpio_grp->dir_set);
}
static void __set_gpio_dir_p3(struct lpc32xx_gpio_chip *group,
unsigned pin, int input)
{
u32 u = GPIO3_PIN_TO_BIT(pin);
if (input)
__raw_writel(u, group->gpio_grp->dir_clr);
else
__raw_writel(u, group->gpio_grp->dir_set);
}
static void __set_gpio_level_p012(struct lpc32xx_gpio_chip *group,
unsigned pin, int high)
{
if (high)
__raw_writel(GPIO012_PIN_TO_BIT(pin),
group->gpio_grp->outp_set);
else
__raw_writel(GPIO012_PIN_TO_BIT(pin),
group->gpio_grp->outp_clr);
}
static void __set_gpio_level_p3(struct lpc32xx_gpio_chip *group,
unsigned pin, int high)
{
u32 u = GPIO3_PIN_TO_BIT(pin);
if (high)
__raw_writel(u, group->gpio_grp->outp_set);
else
__raw_writel(u, group->gpio_grp->outp_clr);
}
static void __set_gpo_level_p3(struct lpc32xx_gpio_chip *group,
unsigned pin, int high)
{
if (high)
__raw_writel(GPO3_PIN_TO_BIT(pin), group->gpio_grp->outp_set);
else
__raw_writel(GPO3_PIN_TO_BIT(pin), group->gpio_grp->outp_clr);
}
static int __get_gpio_state_p012(struct lpc32xx_gpio_chip *group,
unsigned pin)
{
return GPIO012_PIN_IN_SEL(__raw_readl(group->gpio_grp->inp_state),
pin);
}
static int __get_gpio_state_p3(struct lpc32xx_gpio_chip *group,
unsigned pin)
{
int state = __raw_readl(group->gpio_grp->inp_state);
return GPIO3_PIN_IN_SEL(state, pin);
}
static int __get_gpi_state_p3(struct lpc32xx_gpio_chip *group,
unsigned pin)
{
return GPI3_PIN_IN_SEL(__raw_readl(group->gpio_grp->inp_state), pin);
}
static int lpc32xx_gpio_dir_input_p012(struct gpio_chip *chip,
unsigned pin)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpio_dir_p012(group, pin, 1);
return 0;
}
static int lpc32xx_gpio_dir_input_p3(struct gpio_chip *chip,
unsigned pin)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpio_dir_p3(group, pin, 1);
return 0;
}
static int lpc32xx_gpio_dir_in_always(struct gpio_chip *chip,
unsigned pin)
{
return 0;
}
static int lpc32xx_gpio_get_value_p012(struct gpio_chip *chip, unsigned pin)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
return __get_gpio_state_p012(group, pin);
}
static int lpc32xx_gpio_get_value_p3(struct gpio_chip *chip, unsigned pin)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
return __get_gpio_state_p3(group, pin);
}
static int lpc32xx_gpi_get_value(struct gpio_chip *chip, unsigned pin)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
return __get_gpi_state_p3(group, pin);
}
static int lpc32xx_gpio_dir_output_p012(struct gpio_chip *chip, unsigned pin,
int value)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpio_dir_p012(group, pin, 0);
return 0;
}
static int lpc32xx_gpio_dir_output_p3(struct gpio_chip *chip, unsigned pin,
int value)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpio_dir_p3(group, pin, 0);
return 0;
}
static int lpc32xx_gpio_dir_out_always(struct gpio_chip *chip, unsigned pin,
int value)
{
return 0;
}
static void lpc32xx_gpio_set_value_p012(struct gpio_chip *chip, unsigned pin,
int value)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpio_level_p012(group, pin, value);
}
static void lpc32xx_gpio_set_value_p3(struct gpio_chip *chip, unsigned pin,
int value)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpio_level_p3(group, pin, value);
}
static void lpc32xx_gpo_set_value(struct gpio_chip *chip, unsigned pin,
int value)
{
struct lpc32xx_gpio_chip *group = to_lpc32xx_gpio(chip);
__set_gpo_level_p3(group, pin, value);
}
static int lpc32xx_gpio_request(struct gpio_chip *chip, unsigned pin)
{
if (pin < chip->ngpio)
return 0;
return -EINVAL;
}
void __init lpc32xx_gpio_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(lpc32xx_gpiochip); i++)
gpiochip_add(&lpc32xx_gpiochip[i].chip);
}
