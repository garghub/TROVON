static inline int superio_enter(void)
{
if (!request_muxed_region(REG, 2, KBUILD_MODNAME))
return -EBUSY;
outb(0x87, REG);
outb(0x01, REG);
outb(0x55, REG);
outb(0x55, REG);
return 0;
}
static inline void superio_exit(void)
{
outb(0x02, REG);
outb(0x02, VAL);
release_region(REG, 2);
}
static inline void superio_select(int ldn)
{
outb(LDNREG, REG);
outb(ldn, VAL);
}
static inline int superio_inb(int reg)
{
outb(reg, REG);
return inb(VAL);
}
static inline void superio_outb(int val, int reg)
{
outb(reg, REG);
outb(val, VAL);
}
static inline int superio_inw(int reg)
{
int val;
outb(reg++, REG);
val = inb(VAL) << 8;
outb(reg, REG);
val |= inb(VAL);
return val;
}
static inline void superio_outw(int val, int reg)
{
outb(reg++, REG);
outb(val >> 8, VAL);
outb(reg, REG);
outb(val, VAL);
}
static inline void superio_set_mask(int mask, int reg)
{
u8 curr_val = superio_inb(reg);
u8 new_val = curr_val | mask;
if (curr_val != new_val)
superio_outb(new_val, reg);
}
static inline void superio_clear_mask(int mask, int reg)
{
u8 curr_val = superio_inb(reg);
u8 new_val = curr_val & ~mask;
if (curr_val != new_val)
superio_outb(new_val, reg);
}
static int it87_gpio_request(struct gpio_chip *chip, unsigned gpio_num)
{
u8 mask, group;
int rc = 0;
struct it87_gpio *it87_gpio = gpiochip_get_data(chip);
mask = 1 << (gpio_num % 8);
group = (gpio_num / 8);
spin_lock(&it87_gpio->lock);
rc = superio_enter();
if (rc)
goto exit;
if (group < it87_gpio->simple_size)
superio_set_mask(mask, group + it87_gpio->simple_base);
superio_clear_mask(mask, group + it87_gpio->output_base);
superio_exit();
exit:
spin_unlock(&it87_gpio->lock);
return rc;
}
static int it87_gpio_get(struct gpio_chip *chip, unsigned gpio_num)
{
u16 reg;
u8 mask;
struct it87_gpio *it87_gpio = gpiochip_get_data(chip);
mask = 1 << (gpio_num % 8);
reg = (gpio_num / 8) + it87_gpio->io_base;
return !!(inb(reg) & mask);
}
static int it87_gpio_direction_in(struct gpio_chip *chip, unsigned gpio_num)
{
u8 mask, group;
int rc = 0;
struct it87_gpio *it87_gpio = gpiochip_get_data(chip);
mask = 1 << (gpio_num % 8);
group = (gpio_num / 8);
spin_lock(&it87_gpio->lock);
rc = superio_enter();
if (rc)
goto exit;
superio_clear_mask(mask, group + it87_gpio->output_base);
superio_exit();
exit:
spin_unlock(&it87_gpio->lock);
return rc;
}
static void it87_gpio_set(struct gpio_chip *chip,
unsigned gpio_num, int val)
{
u8 mask, curr_vals;
u16 reg;
struct it87_gpio *it87_gpio = gpiochip_get_data(chip);
mask = 1 << (gpio_num % 8);
reg = (gpio_num / 8) + it87_gpio->io_base;
curr_vals = inb(reg);
if (val)
outb(curr_vals | mask, reg);
else
outb(curr_vals & ~mask, reg);
}
static int it87_gpio_direction_out(struct gpio_chip *chip,
unsigned gpio_num, int val)
{
u8 mask, group;
int rc = 0;
struct it87_gpio *it87_gpio = gpiochip_get_data(chip);
mask = 1 << (gpio_num % 8);
group = (gpio_num / 8);
spin_lock(&it87_gpio->lock);
rc = superio_enter();
if (rc)
goto exit;
superio_set_mask(mask, group + it87_gpio->output_base);
it87_gpio_set(chip, gpio_num, val);
superio_exit();
exit:
spin_unlock(&it87_gpio->lock);
return rc;
}
static int __init it87_gpio_init(void)
{
int rc = 0, i;
u16 chip_type;
u8 chip_rev, gpio_ba_reg;
char *labels, **labels_table;
struct it87_gpio *it87_gpio = &it87_gpio_chip;
rc = superio_enter();
if (rc)
return rc;
chip_type = superio_inw(CHIPID);
chip_rev = superio_inb(CHIPREV) & 0x0f;
superio_exit();
it87_gpio->chip = it87_template_chip;
switch (chip_type) {
case IT8620_ID:
case IT8628_ID:
gpio_ba_reg = 0x62;
it87_gpio->io_size = 11;
it87_gpio->output_base = 0xc8;
it87_gpio->simple_size = 0;
it87_gpio->chip.ngpio = 64;
break;
case IT8728_ID:
case IT8732_ID:
case IT8772_ID:
gpio_ba_reg = 0x62;
it87_gpio->io_size = 8;
it87_gpio->output_base = 0xc8;
it87_gpio->simple_base = 0xc0;
it87_gpio->simple_size = 5;
it87_gpio->chip.ngpio = 64;
break;
case IT8761_ID:
gpio_ba_reg = 0x60;
it87_gpio->io_size = 4;
it87_gpio->output_base = 0xf0;
it87_gpio->simple_size = 0;
it87_gpio->chip.ngpio = 16;
break;
case NO_DEV_ID:
pr_err("no device\n");
return -ENODEV;
default:
pr_err("Unknown Chip found, Chip %04x Revision %x\n",
chip_type, chip_rev);
return -ENODEV;
}
rc = superio_enter();
if (rc)
return rc;
superio_select(GPIO);
it87_gpio->io_base = superio_inw(gpio_ba_reg);
superio_exit();
pr_info("Found Chip IT%04x rev %x. %u GPIO lines starting at %04xh\n",
chip_type, chip_rev, it87_gpio->chip.ngpio,
it87_gpio->io_base);
if (!request_region(it87_gpio->io_base, it87_gpio->io_size,
KBUILD_MODNAME))
return -EBUSY;
labels = kcalloc(it87_gpio->chip.ngpio, sizeof("it87_gpXY"),
GFP_KERNEL);
labels_table = kcalloc(it87_gpio->chip.ngpio, sizeof(const char *),
GFP_KERNEL);
if (!labels || !labels_table) {
rc = -ENOMEM;
goto labels_free;
}
for (i = 0; i < it87_gpio->chip.ngpio; i++) {
char *label = &labels[i * sizeof("it87_gpXY")];
sprintf(label, "it87_gp%u%u", 1+(i/8), i%8);
labels_table[i] = label;
}
it87_gpio->chip.names = (const char *const*)labels_table;
rc = gpiochip_add_data(&it87_gpio->chip, it87_gpio);
if (rc)
goto labels_free;
return 0;
labels_free:
kfree(labels_table);
kfree(labels);
release_region(it87_gpio->io_base, it87_gpio->io_size);
return rc;
}
static void __exit it87_gpio_exit(void)
{
struct it87_gpio *it87_gpio = &it87_gpio_chip;
gpiochip_remove(&it87_gpio->chip);
release_region(it87_gpio->io_base, it87_gpio->io_size);
kfree(it87_gpio->chip.names[0]);
kfree(it87_gpio->chip.names);
}
