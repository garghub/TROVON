static unsigned int bit_cfg_reg(unsigned int offset)
{
if (offset < 16)
return 8 * offset;
else
return 8 * (offset - 16) + 0x100;
}
static int octeon_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
struct octeon_gpio *gpio = gpiochip_get_data(chip);
cvmx_write_csr(gpio->register_base + bit_cfg_reg(offset), 0);
return 0;
}
static void octeon_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct octeon_gpio *gpio = gpiochip_get_data(chip);
u64 mask = 1ull << offset;
u64 reg = gpio->register_base + (value ? TX_SET : TX_CLEAR);
cvmx_write_csr(reg, mask);
}
static int octeon_gpio_dir_out(struct gpio_chip *chip, unsigned offset,
int value)
{
struct octeon_gpio *gpio = gpiochip_get_data(chip);
union cvmx_gpio_bit_cfgx cfgx;
octeon_gpio_set(chip, offset, value);
cfgx.u64 = 0;
cfgx.s.tx_oe = 1;
cvmx_write_csr(gpio->register_base + bit_cfg_reg(offset), cfgx.u64);
return 0;
}
static int octeon_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct octeon_gpio *gpio = gpiochip_get_data(chip);
u64 read_bits = cvmx_read_csr(gpio->register_base + RX_DAT);
return ((1ull << offset) & read_bits) != 0;
}
static int octeon_gpio_probe(struct platform_device *pdev)
{
struct octeon_gpio *gpio;
struct gpio_chip *chip;
struct resource *res_mem;
void __iomem *reg_base;
int err = 0;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
chip = &gpio->chip;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg_base = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(reg_base))
return PTR_ERR(reg_base);
gpio->register_base = (u64)reg_base;
pdev->dev.platform_data = chip;
chip->label = "octeon-gpio";
chip->parent = &pdev->dev;
chip->owner = THIS_MODULE;
chip->base = 0;
chip->can_sleep = false;
chip->ngpio = 20;
chip->direction_input = octeon_gpio_dir_in;
chip->get = octeon_gpio_get;
chip->direction_output = octeon_gpio_dir_out;
chip->set = octeon_gpio_set;
err = devm_gpiochip_add_data(&pdev->dev, chip, gpio);
if (err)
return err;
dev_info(&pdev->dev, "OCTEON GPIO driver probed.\n");
return 0;
}
