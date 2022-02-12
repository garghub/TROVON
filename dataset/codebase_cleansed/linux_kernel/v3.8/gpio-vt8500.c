static int vt8500_gpio_request(struct gpio_chip *chip, unsigned offset)
{
u32 val;
struct vt8500_gpio_chip *vt8500_chip = to_vt8500(chip);
if (vt8500_chip->regs->en == NO_REG)
return 0;
val = readl_relaxed(vt8500_chip->base + vt8500_chip->regs->en);
val |= BIT(offset);
writel_relaxed(val, vt8500_chip->base + vt8500_chip->regs->en);
return 0;
}
static void vt8500_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct vt8500_gpio_chip *vt8500_chip = to_vt8500(chip);
u32 val;
if (vt8500_chip->regs->en == NO_REG)
return;
val = readl_relaxed(vt8500_chip->base + vt8500_chip->regs->en);
val &= ~BIT(offset);
writel_relaxed(val, vt8500_chip->base + vt8500_chip->regs->en);
}
static int vt8500_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct vt8500_gpio_chip *vt8500_chip = to_vt8500(chip);
u32 val = readl_relaxed(vt8500_chip->base + vt8500_chip->regs->dir);
val &= ~BIT(offset);
writel_relaxed(val, vt8500_chip->base + vt8500_chip->regs->dir);
return 0;
}
static int vt8500_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct vt8500_gpio_chip *vt8500_chip = to_vt8500(chip);
u32 val = readl_relaxed(vt8500_chip->base + vt8500_chip->regs->dir);
val |= BIT(offset);
writel_relaxed(val, vt8500_chip->base + vt8500_chip->regs->dir);
if (value) {
val = readl_relaxed(vt8500_chip->base +
vt8500_chip->regs->data_out);
val |= BIT(offset);
writel_relaxed(val, vt8500_chip->base +
vt8500_chip->regs->data_out);
}
return 0;
}
static int vt8500_gpio_get_value(struct gpio_chip *chip, unsigned offset)
{
struct vt8500_gpio_chip *vt8500_chip = to_vt8500(chip);
return (readl_relaxed(vt8500_chip->base + vt8500_chip->regs->data_in) >>
offset) & 1;
}
static void vt8500_gpio_set_value(struct gpio_chip *chip, unsigned offset,
int value)
{
struct vt8500_gpio_chip *vt8500_chip = to_vt8500(chip);
u32 val = readl_relaxed(vt8500_chip->base +
vt8500_chip->regs->data_out);
if (value)
val |= BIT(offset);
else
val &= ~BIT(offset);
writel_relaxed(val, vt8500_chip->base + vt8500_chip->regs->data_out);
}
static int vt8500_of_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec, u32 *flags)
{
if (flags)
*flags = gpiospec->args[2];
return gpiospec->args[1];
}
static int vt8500_add_chips(struct platform_device *pdev, void __iomem *base,
const struct vt8500_gpio_data *data)
{
struct vt8500_gpio_chip *vtchip;
struct gpio_chip *chip;
int i;
int pin_cnt = 0;
vtchip = devm_kzalloc(&pdev->dev,
sizeof(struct vt8500_gpio_chip) * data->num_banks,
GFP_KERNEL);
if (!vtchip) {
pr_err("%s: failed to allocate chip memory\n", __func__);
return -ENOMEM;
}
for (i = 0; i < data->num_banks; i++) {
vtchip[i].base = base;
vtchip[i].regs = &data->banks[i];
chip = &vtchip[i].chip;
chip->of_xlate = vt8500_of_xlate;
chip->of_gpio_n_cells = 3;
chip->of_node = pdev->dev.of_node;
chip->request = vt8500_gpio_request;
chip->free = vt8500_gpio_free;
chip->direction_input = vt8500_gpio_direction_input;
chip->direction_output = vt8500_gpio_direction_output;
chip->get = vt8500_gpio_get_value;
chip->set = vt8500_gpio_set_value;
chip->can_sleep = 0;
chip->base = pin_cnt;
chip->ngpio = data->banks[i].ngpio;
pin_cnt += data->banks[i].ngpio;
gpiochip_add(chip);
}
return 0;
}
static int vt8500_gpio_probe(struct platform_device *pdev)
{
void __iomem *gpio_base;
struct device_node *np;
const struct of_device_id *of_id =
of_match_device(vt8500_gpio_dt_ids, &pdev->dev);
if (!of_id) {
dev_err(&pdev->dev, "Failed to find gpio controller\n");
return -ENODEV;
}
np = pdev->dev.of_node;
if (!np) {
dev_err(&pdev->dev, "Missing GPIO description in devicetree\n");
return -EFAULT;
}
gpio_base = of_iomap(np, 0);
if (!gpio_base) {
dev_err(&pdev->dev, "Unable to map GPIO registers\n");
of_node_put(np);
return -ENOMEM;
}
vt8500_add_chips(pdev, gpio_base, of_id->data);
return 0;
}
