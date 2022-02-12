static unsigned int bit_cfg_reg(unsigned int offset)
{
if (offset < 16)
return 8 * offset;
else
return 8 * (offset - 16) + 0x100;
}
static int octeon_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
struct octeon_gpio *gpio = container_of(chip, struct octeon_gpio, chip);
cvmx_write_csr(gpio->register_base + bit_cfg_reg(offset), 0);
return 0;
}
static void octeon_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct octeon_gpio *gpio = container_of(chip, struct octeon_gpio, chip);
u64 mask = 1ull << offset;
u64 reg = gpio->register_base + (value ? TX_SET : TX_CLEAR);
cvmx_write_csr(reg, mask);
}
static int octeon_gpio_dir_out(struct gpio_chip *chip, unsigned offset,
int value)
{
struct octeon_gpio *gpio = container_of(chip, struct octeon_gpio, chip);
union cvmx_gpio_bit_cfgx cfgx;
octeon_gpio_set(chip, offset, value);
cfgx.u64 = 0;
cfgx.s.tx_oe = 1;
cvmx_write_csr(gpio->register_base + bit_cfg_reg(offset), cfgx.u64);
return 0;
}
static int octeon_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct octeon_gpio *gpio = container_of(chip, struct octeon_gpio, chip);
u64 read_bits = cvmx_read_csr(gpio->register_base + RX_DAT);
return ((1ull << offset) & read_bits) != 0;
}
static int octeon_gpio_probe(struct platform_device *pdev)
{
struct octeon_gpio *gpio;
struct gpio_chip *chip;
struct resource *res_mem;
int err = 0;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
chip = &gpio->chip;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res_mem == NULL) {
dev_err(&pdev->dev, "found no memory resource\n");
err = -ENXIO;
goto out;
}
if (!devm_request_mem_region(&pdev->dev, res_mem->start,
resource_size(res_mem),
res_mem->name)) {
dev_err(&pdev->dev, "request_mem_region failed\n");
err = -ENXIO;
goto out;
}
gpio->register_base = (u64)devm_ioremap(&pdev->dev, res_mem->start,
resource_size(res_mem));
pdev->dev.platform_data = chip;
chip->label = "octeon-gpio";
chip->dev = &pdev->dev;
chip->owner = THIS_MODULE;
chip->base = 0;
chip->can_sleep = 0;
chip->ngpio = 20;
chip->direction_input = octeon_gpio_dir_in;
chip->get = octeon_gpio_get;
chip->direction_output = octeon_gpio_dir_out;
chip->set = octeon_gpio_set;
err = gpiochip_add(chip);
if (err)
goto out;
dev_info(&pdev->dev, "OCTEON GPIO driver probed.\n");
out:
return err;
}
static int octeon_gpio_remove(struct platform_device *pdev)
{
struct gpio_chip *chip = pdev->dev.platform_data;
return gpiochip_remove(chip);
}
