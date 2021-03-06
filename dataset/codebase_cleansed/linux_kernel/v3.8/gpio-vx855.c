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
struct vx855_gpio *vg = container_of(gpio, struct vx855_gpio, gpio);
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
struct vx855_gpio *vg = container_of(gpio, struct vx855_gpio, gpio);
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
struct vx855_gpio *vg = container_of(gpio, struct vx855_gpio, gpio);
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
c->can_sleep = 0;
c->names = vx855gpio_names;
}
static int vx855gpio_probe(struct platform_device *pdev)
{
struct resource *res_gpi;
struct resource *res_gpo;
struct vx855_gpio *vg;
int ret;
res_gpi = platform_get_resource(pdev, IORESOURCE_IO, 0);
res_gpo = platform_get_resource(pdev, IORESOURCE_IO, 1);
if (!res_gpi || !res_gpo)
return -EBUSY;
vg = kzalloc(sizeof(*vg), GFP_KERNEL);
if (!vg)
return -ENOMEM;
platform_set_drvdata(pdev, vg);
dev_info(&pdev->dev, "found VX855 GPIO controller\n");
vg->io_gpi = res_gpi->start;
vg->io_gpo = res_gpo->start;
spin_lock_init(&vg->lock);
if (!request_region(res_gpi->start, resource_size(res_gpi),
MODULE_NAME "_gpi"))
dev_warn(&pdev->dev,
"GPI I/O resource busy, probably claimed by ACPI\n");
else
vg->gpi_reserved = true;
if (!request_region(res_gpo->start, resource_size(res_gpo),
MODULE_NAME "_gpo"))
dev_warn(&pdev->dev,
"GPO I/O resource busy, probably claimed by ACPI\n");
else
vg->gpo_reserved = true;
vx855gpio_gpio_setup(vg);
ret = gpiochip_add(&vg->gpio);
if (ret) {
dev_err(&pdev->dev, "failed to register GPIOs\n");
goto out_release;
}
return 0;
out_release:
if (vg->gpi_reserved)
release_region(res_gpi->start, resource_size(res_gpi));
if (vg->gpo_reserved)
release_region(res_gpi->start, resource_size(res_gpo));
platform_set_drvdata(pdev, NULL);
kfree(vg);
return ret;
}
static int vx855gpio_remove(struct platform_device *pdev)
{
struct vx855_gpio *vg = platform_get_drvdata(pdev);
struct resource *res;
if (gpiochip_remove(&vg->gpio))
dev_err(&pdev->dev, "unable to remove gpio_chip?\n");
if (vg->gpi_reserved) {
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
release_region(res->start, resource_size(res));
}
if (vg->gpo_reserved) {
res = platform_get_resource(pdev, IORESOURCE_IO, 1);
release_region(res->start, resource_size(res));
}
platform_set_drvdata(pdev, NULL);
kfree(vg);
return 0;
}
