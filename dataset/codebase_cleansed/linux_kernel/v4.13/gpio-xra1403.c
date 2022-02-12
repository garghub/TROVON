static unsigned int to_reg(unsigned int reg, unsigned int offset)
{
return reg + (offset > 7);
}
static int xra1403_direction_input(struct gpio_chip *chip, unsigned int offset)
{
struct xra1403 *xra = gpiochip_get_data(chip);
return regmap_update_bits(xra->regmap, to_reg(XRA_GCR, offset),
BIT(offset % 8), BIT(offset % 8));
}
static int xra1403_direction_output(struct gpio_chip *chip, unsigned int offset,
int value)
{
int ret;
struct xra1403 *xra = gpiochip_get_data(chip);
ret = regmap_update_bits(xra->regmap, to_reg(XRA_GCR, offset),
BIT(offset % 8), 0);
if (ret)
return ret;
ret = regmap_update_bits(xra->regmap, to_reg(XRA_OCR, offset),
BIT(offset % 8), value ? BIT(offset % 8) : 0);
return ret;
}
static int xra1403_get_direction(struct gpio_chip *chip, unsigned int offset)
{
int ret;
unsigned int val;
struct xra1403 *xra = gpiochip_get_data(chip);
ret = regmap_read(xra->regmap, to_reg(XRA_GCR, offset), &val);
if (ret)
return ret;
return !!(val & BIT(offset % 8));
}
static int xra1403_get(struct gpio_chip *chip, unsigned int offset)
{
int ret;
unsigned int val;
struct xra1403 *xra = gpiochip_get_data(chip);
ret = regmap_read(xra->regmap, to_reg(XRA_GSR, offset), &val);
if (ret)
return ret;
return !!(val & BIT(offset % 8));
}
static void xra1403_set(struct gpio_chip *chip, unsigned int offset, int value)
{
int ret;
struct xra1403 *xra = gpiochip_get_data(chip);
ret = regmap_update_bits(xra->regmap, to_reg(XRA_OCR, offset),
BIT(offset % 8), value ? BIT(offset % 8) : 0);
if (ret)
dev_err(chip->parent, "Failed to set pin: %d, ret: %d\n",
offset, ret);
}
static void xra1403_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
int reg;
struct xra1403 *xra = gpiochip_get_data(chip);
int value[xra1403_regmap_cfg.max_register];
int i;
unsigned int gcr;
unsigned int gsr;
seq_puts(s, "xra reg:");
for (reg = 0; reg <= xra1403_regmap_cfg.max_register; reg++)
seq_printf(s, " %2.2x", reg);
seq_puts(s, "\n value:");
for (reg = 0; reg < xra1403_regmap_cfg.max_register; reg++) {
regmap_read(xra->regmap, reg, &value[reg]);
seq_printf(s, " %2.2x", value[reg]);
}
seq_puts(s, "\n");
gcr = value[XRA_GCR + 1] << 8 | value[XRA_GCR];
gsr = value[XRA_GSR + 1] << 8 | value[XRA_GSR];
for (i = 0; i < chip->ngpio; i++) {
const char *label = gpiochip_is_requested(chip, i);
if (!label)
continue;
seq_printf(s, " gpio-%-3d (%-12s) %s %s\n",
chip->base + i, label,
(gcr & BIT(i)) ? "in" : "out",
(gsr & BIT(i)) ? "hi" : "lo");
}
}
static int xra1403_probe(struct spi_device *spi)
{
struct xra1403 *xra;
struct gpio_desc *reset_gpio;
int ret;
xra = devm_kzalloc(&spi->dev, sizeof(*xra), GFP_KERNEL);
if (!xra)
return -ENOMEM;
reset_gpio = devm_gpiod_get_optional(&spi->dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(reset_gpio))
dev_warn(&spi->dev, "Could not get reset-gpios\n");
xra->chip.direction_input = xra1403_direction_input;
xra->chip.direction_output = xra1403_direction_output;
xra->chip.get_direction = xra1403_get_direction;
xra->chip.get = xra1403_get;
xra->chip.set = xra1403_set;
xra->chip.dbg_show = xra1403_dbg_show;
xra->chip.ngpio = 16;
xra->chip.label = "xra1403";
xra->chip.base = -1;
xra->chip.can_sleep = true;
xra->chip.parent = &spi->dev;
xra->chip.owner = THIS_MODULE;
xra->regmap = devm_regmap_init_spi(spi, &xra1403_regmap_cfg);
if (IS_ERR(xra->regmap)) {
ret = PTR_ERR(xra->regmap);
dev_err(&spi->dev, "Failed to allocate regmap: %d\n", ret);
return ret;
}
ret = devm_gpiochip_add_data(&spi->dev, &xra->chip, xra);
if (ret < 0) {
dev_err(&spi->dev, "Unable to register gpiochip\n");
return ret;
}
spi_set_drvdata(spi, xra);
return 0;
}
