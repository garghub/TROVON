static inline u_int32_t gpi_i_bit(int i)
{
if (i < 10)
return 1 << i;
else
return 1 << (i + 14);
}
static inline u_int32_t gpo_o_bit(int i)
{
if (i < 11)
return 1 << i;
else
return 1 << (i + 14);
}
static inline u_int32_t gpio_i_bit(int i)
{
if (i < 14)
return 1 << (i + 10);
else
return 1 << (i + 14);
}
static inline u_int32_t gpio_o_bit(int i)
{
if (i < 14)
return 1 << (i + 11);
else
return 1 << (i + 13);
}
static int vx855gpio_direction_input(struct gpio_chip *gpio,
unsigned int nr)
{
struct vx855_gpio *vg = gpiochip_get_data(gpio);
unsigned long flags;
u_int32_t reg_out;
if (nr < NR_VX855_GPI)
return 0;
if (nr < NR_VX855_GPInO)
return -EINVAL;
spin_lock_irqsave(&vg->lock, flags);
reg_out = inl(vg->io_gpo);
reg_out |= gpio_o_bit(nr - NR_VX855_GPInO);
outl(reg_out, vg->io_gpo);
spin_unlock_irqrestore(&vg->lock, flags);
return 0;
}
static int vx855gpio_get(struct gpio_chip *gpio, unsigned int nr)
{
struct vx855_gpio *vg = gpiochip_get_data(gpio);
u_int32_t reg_in;
int ret = 0;
if (nr < NR_VX855_GPI) {
reg_in = inl(vg->io_gpi);
if (reg_in & gpi_i_bit(nr))
ret = 1;
} else if (nr < NR_VX855_GPInO) {
reg_in = inl(vg->io_gpo);
if (reg_in & gpo_o_bit(nr - NR_VX855_GPI))
ret = 1;
} else {
reg_in = inl(vg->io_gpi);
if (reg_in & gpio_i_bit(nr - NR_VX855_GPInO))
ret = 1;
}
return ret;
}
static void vx855gpio_set(struct gpio_chip *gpio, unsigned int nr,
int val)
{
struct vx855_gpio *vg = gpiochip_get_data(gpio);
unsigned long flags;
u_int32_t reg_out;
if (nr < NR_VX855_GPI)
return;
spin_lock_irqsave(&vg->lock, flags);
reg_out = inl(vg->io_gpo);
if (nr < NR_VX855_GPInO) {
if (val)
reg_out |= gpo_o_bit(nr - NR_VX855_GPI);
else
reg_out &= ~gpo_o_bit(nr - NR_VX855_GPI);
} else {
if (val)
reg_out |= gpio_o_bit(nr - NR_VX855_GPInO);
else
reg_out &= ~gpio_o_bit(nr - NR_VX855_GPInO);
}
outl(reg_out, vg->io_gpo);
spin_unlock_irqrestore(&vg->lock, flags);
}
static int vx855gpio_direction_output(struct gpio_chip *gpio,
unsigned int nr, int val)
{
if (nr < NR_VX855_GPI)
return -EINVAL;
vx855gpio_set(gpio, nr, val);
return 0;
}
static void vx855gpio_gpio_setup(struct vx855_gpio *vg)
{
struct gpio_chip *c = &vg->gpio;
c->label = "VX855 South Bridge";
c->owner = THIS_MODULE;
c->direction_input = vx855gpio_direction_input;
c->direction_output = vx855gpio_direction_output;
c->get = vx855gpio_get;
c->set = vx855gpio_set;
c->dbg_show = NULL;
c->base = 0;
c->ngpio = NR_VX855_GP;
c->can_sleep = false;
c->names = vx855gpio_names;
}
static int vx855gpio_probe(struct platform_device *pdev)
{
struct resource *res_gpi;
struct resource *res_gpo;
struct vx855_gpio *vg;
res_gpi = platform_get_resource(pdev, IORESOURCE_IO, 0);
res_gpo = platform_get_resource(pdev, IORESOURCE_IO, 1);
if (!res_gpi || !res_gpo)
return -EBUSY;
vg = devm_kzalloc(&pdev->dev, sizeof(*vg), GFP_KERNEL);
if (!vg)
return -ENOMEM;
platform_set_drvdata(pdev, vg);
dev_info(&pdev->dev, "found VX855 GPIO controller\n");
vg->io_gpi = res_gpi->start;
vg->io_gpo = res_gpo->start;
spin_lock_init(&vg->lock);
if (!devm_request_region(&pdev->dev, res_gpi->start,
resource_size(res_gpi), MODULE_NAME "_gpi"))
dev_warn(&pdev->dev,
"GPI I/O resource busy, probably claimed by ACPI\n");
if (!devm_request_region(&pdev->dev, res_gpo->start,
resource_size(res_gpo), MODULE_NAME "_gpo"))
dev_warn(&pdev->dev,
"GPO I/O resource busy, probably claimed by ACPI\n");
vx855gpio_gpio_setup(vg);
return gpiochip_add_data(&vg->gpio, vg);
}
static int vx855gpio_remove(struct platform_device *pdev)
{
struct vx855_gpio *vg = platform_get_drvdata(pdev);
gpiochip_remove(&vg->gpio);
return 0;
}
