static int samsung_gpiolib_4bit_input(struct gpio_chip *chip,
unsigned int offset)
{
struct s3c_gpio_chip *ourchip = to_s3c_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long con;
con = __raw_readl(base + GPIOCON_OFF);
con &= ~(0xf << con_4bit_shift(offset));
__raw_writel(con, base + GPIOCON_OFF);
gpio_dbg("%s: %p: CON now %08lx\n", __func__, base, con);
return 0;
}
static int samsung_gpiolib_4bit_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct s3c_gpio_chip *ourchip = to_s3c_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long con;
unsigned long dat;
con = __raw_readl(base + GPIOCON_OFF);
con &= ~(0xf << con_4bit_shift(offset));
con |= 0x1 << con_4bit_shift(offset);
dat = __raw_readl(base + GPIODAT_OFF);
if (value)
dat |= 1 << offset;
else
dat &= ~(1 << offset);
__raw_writel(dat, base + GPIODAT_OFF);
__raw_writel(con, base + GPIOCON_OFF);
__raw_writel(dat, base + GPIODAT_OFF);
gpio_dbg("%s: %p: CON %08lx, DAT %08lx\n", __func__, base, con, dat);
return 0;
}
static int samsung_gpiolib_4bit2_input(struct gpio_chip *chip,
unsigned int offset)
{
struct s3c_gpio_chip *ourchip = to_s3c_gpio(chip);
void __iomem *base = ourchip->base;
void __iomem *regcon = base;
unsigned long con;
if (offset > 7)
offset -= 8;
else
regcon -= 4;
con = __raw_readl(regcon);
con &= ~(0xf << con_4bit_shift(offset));
__raw_writel(con, regcon);
gpio_dbg("%s: %p: CON %08lx\n", __func__, base, con);
return 0;
}
static int samsung_gpiolib_4bit2_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct s3c_gpio_chip *ourchip = to_s3c_gpio(chip);
void __iomem *base = ourchip->base;
void __iomem *regcon = base;
unsigned long con;
unsigned long dat;
unsigned con_offset = offset;
if (con_offset > 7)
con_offset -= 8;
else
regcon -= 4;
con = __raw_readl(regcon);
con &= ~(0xf << con_4bit_shift(con_offset));
con |= 0x1 << con_4bit_shift(con_offset);
dat = __raw_readl(base + GPIODAT_OFF);
if (value)
dat |= 1 << offset;
else
dat &= ~(1 << offset);
__raw_writel(dat, base + GPIODAT_OFF);
__raw_writel(con, regcon);
__raw_writel(dat, base + GPIODAT_OFF);
gpio_dbg("%s: %p: CON %08lx, DAT %08lx\n", __func__, base, con, dat);
return 0;
}
void __init samsung_gpiolib_add_4bit(struct s3c_gpio_chip *chip)
{
chip->chip.direction_input = samsung_gpiolib_4bit_input;
chip->chip.direction_output = samsung_gpiolib_4bit_output;
chip->pm = __gpio_pm(&s3c_gpio_pm_4bit);
}
void __init samsung_gpiolib_add_4bit2(struct s3c_gpio_chip *chip)
{
chip->chip.direction_input = samsung_gpiolib_4bit2_input;
chip->chip.direction_output = samsung_gpiolib_4bit2_output;
chip->pm = __gpio_pm(&s3c_gpio_pm_4bit);
}
void __init samsung_gpiolib_add_4bit_chips(struct s3c_gpio_chip *chip,
int nr_chips)
{
for (; nr_chips > 0; nr_chips--, chip++) {
samsung_gpiolib_add_4bit(chip);
s3c_gpiolib_add(chip);
}
}
void __init samsung_gpiolib_add_4bit2_chips(struct s3c_gpio_chip *chip,
int nr_chips)
{
for (; nr_chips > 0; nr_chips--, chip++) {
samsung_gpiolib_add_4bit2(chip);
s3c_gpiolib_add(chip);
}
}
void __init samsung_gpiolib_add_2bit_chips(struct s3c_gpio_chip *chip,
int nr_chips)
{
for (; nr_chips > 0; nr_chips--, chip++)
s3c_gpiolib_add(chip);
}
