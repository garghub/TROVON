int samsung_gpio_setpull_updown(struct samsung_gpio_chip *chip,
unsigned int off, samsung_gpio_pull_t pull)
{
void __iomem *reg = chip->base + 0x08;
int shift = off * 2;
u32 pup;
pup = __raw_readl(reg);
pup &= ~(3 << shift);
pup |= pull << shift;
__raw_writel(pup, reg);
return 0;
}
samsung_gpio_pull_t samsung_gpio_getpull_updown(struct samsung_gpio_chip *chip,
unsigned int off)
{
void __iomem *reg = chip->base + 0x08;
int shift = off * 2;
u32 pup = __raw_readl(reg);
pup >>= shift;
pup &= 0x3;
return (__force samsung_gpio_pull_t)pup;
}
int s3c2443_gpio_setpull(struct samsung_gpio_chip *chip,
unsigned int off, samsung_gpio_pull_t pull)
{
switch (pull) {
case S3C_GPIO_PULL_NONE:
pull = 0x01;
break;
case S3C_GPIO_PULL_UP:
pull = 0x00;
break;
case S3C_GPIO_PULL_DOWN:
pull = 0x02;
break;
}
return samsung_gpio_setpull_updown(chip, off, pull);
}
samsung_gpio_pull_t s3c2443_gpio_getpull(struct samsung_gpio_chip *chip,
unsigned int off)
{
samsung_gpio_pull_t pull;
pull = samsung_gpio_getpull_updown(chip, off);
switch (pull) {
case 0x00:
pull = S3C_GPIO_PULL_UP;
break;
case 0x01:
case 0x03:
pull = S3C_GPIO_PULL_NONE;
break;
case 0x02:
pull = S3C_GPIO_PULL_DOWN;
break;
}
return pull;
}
static int s3c24xx_gpio_setpull_1(struct samsung_gpio_chip *chip,
unsigned int off, samsung_gpio_pull_t pull,
samsung_gpio_pull_t updown)
{
void __iomem *reg = chip->base + 0x08;
u32 pup = __raw_readl(reg);
if (pull == updown)
pup &= ~(1 << off);
else if (pull == S3C_GPIO_PULL_NONE)
pup |= (1 << off);
else
return -EINVAL;
__raw_writel(pup, reg);
return 0;
}
static samsung_gpio_pull_t s3c24xx_gpio_getpull_1(struct samsung_gpio_chip *chip,
unsigned int off,
samsung_gpio_pull_t updown)
{
void __iomem *reg = chip->base + 0x08;
u32 pup = __raw_readl(reg);
pup &= (1 << off);
return pup ? S3C_GPIO_PULL_NONE : updown;
}
samsung_gpio_pull_t s3c24xx_gpio_getpull_1up(struct samsung_gpio_chip *chip,
unsigned int off)
{
return s3c24xx_gpio_getpull_1(chip, off, S3C_GPIO_PULL_UP);
}
int s3c24xx_gpio_setpull_1up(struct samsung_gpio_chip *chip,
unsigned int off, samsung_gpio_pull_t pull)
{
return s3c24xx_gpio_setpull_1(chip, off, pull, S3C_GPIO_PULL_UP);
}
samsung_gpio_pull_t s3c24xx_gpio_getpull_1down(struct samsung_gpio_chip *chip,
unsigned int off)
{
return s3c24xx_gpio_getpull_1(chip, off, S3C_GPIO_PULL_DOWN);
}
int s3c24xx_gpio_setpull_1down(struct samsung_gpio_chip *chip,
unsigned int off, samsung_gpio_pull_t pull)
{
return s3c24xx_gpio_setpull_1(chip, off, pull, S3C_GPIO_PULL_DOWN);
}
static int exynos_gpio_setpull(struct samsung_gpio_chip *chip,
unsigned int off, samsung_gpio_pull_t pull)
{
if (pull == S3C_GPIO_PULL_UP)
pull = 3;
return samsung_gpio_setpull_updown(chip, off, pull);
}
static samsung_gpio_pull_t exynos_gpio_getpull(struct samsung_gpio_chip *chip,
unsigned int off)
{
samsung_gpio_pull_t pull;
pull = samsung_gpio_getpull_updown(chip, off);
if (pull == 3)
pull = S3C_GPIO_PULL_UP;
return pull;
}
static int samsung_gpio_setcfg_2bit(struct samsung_gpio_chip *chip,
unsigned int off, unsigned int cfg)
{
void __iomem *reg = chip->base;
unsigned int shift = off * 2;
u32 con;
if (samsung_gpio_is_cfg_special(cfg)) {
cfg &= 0xf;
if (cfg > 3)
return -EINVAL;
cfg <<= shift;
}
con = __raw_readl(reg);
con &= ~(0x3 << shift);
con |= cfg;
__raw_writel(con, reg);
return 0;
}
static unsigned int samsung_gpio_getcfg_2bit(struct samsung_gpio_chip *chip,
unsigned int off)
{
u32 con;
con = __raw_readl(chip->base);
con >>= off * 2;
con &= 3;
return S3C_GPIO_SPECIAL(con);
}
static int samsung_gpio_setcfg_4bit(struct samsung_gpio_chip *chip,
unsigned int off, unsigned int cfg)
{
void __iomem *reg = chip->base;
unsigned int shift = (off & 7) * 4;
u32 con;
if (off < 8 && chip->chip.ngpio > 8)
reg -= 4;
if (samsung_gpio_is_cfg_special(cfg)) {
cfg &= 0xf;
cfg <<= shift;
}
con = __raw_readl(reg);
con &= ~(0xf << shift);
con |= cfg;
__raw_writel(con, reg);
return 0;
}
static unsigned samsung_gpio_getcfg_4bit(struct samsung_gpio_chip *chip,
unsigned int off)
{
void __iomem *reg = chip->base;
unsigned int shift = (off & 7) * 4;
u32 con;
if (off < 8 && chip->chip.ngpio > 8)
reg -= 4;
con = __raw_readl(reg);
con >>= shift;
con &= 0xf;
return S3C_GPIO_SPECIAL(con);
}
static int s3c24xx_gpio_setcfg_abank(struct samsung_gpio_chip *chip,
unsigned int off, unsigned int cfg)
{
void __iomem *reg = chip->base;
unsigned int shift = off;
u32 con;
if (samsung_gpio_is_cfg_special(cfg)) {
cfg &= 0xf;
cfg -= 1;
if (cfg > 1)
return -EINVAL;
cfg <<= shift;
}
con = __raw_readl(reg);
con &= ~(0x1 << shift);
con |= cfg;
__raw_writel(con, reg);
return 0;
}
static unsigned s3c24xx_gpio_getcfg_abank(struct samsung_gpio_chip *chip,
unsigned int off)
{
u32 con;
con = __raw_readl(chip->base);
con >>= off;
con &= 1;
con++;
return S3C_GPIO_SFN(con);
}
static int s5p64x0_gpio_setcfg_rbank(struct samsung_gpio_chip *chip,
unsigned int off, unsigned int cfg)
{
void __iomem *reg = chip->base;
unsigned int shift;
u32 con;
switch (off) {
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
shift = (off & 7) * 4;
reg -= 4;
break;
case 6:
shift = ((off + 1) & 7) * 4;
reg -= 4;
default:
shift = ((off + 1) & 7) * 4;
break;
}
if (samsung_gpio_is_cfg_special(cfg)) {
cfg &= 0xf;
cfg <<= shift;
}
con = __raw_readl(reg);
con &= ~(0xf << shift);
con |= cfg;
__raw_writel(con, reg);
return 0;
}
static void __init samsung_gpiolib_set_cfg(struct samsung_gpio_cfg *chipcfg,
int nr_chips)
{
for (; nr_chips > 0; nr_chips--, chipcfg++) {
if (!chipcfg->set_config)
chipcfg->set_config = samsung_gpio_setcfg_4bit;
if (!chipcfg->get_config)
chipcfg->get_config = samsung_gpio_getcfg_4bit;
if (!chipcfg->set_pull)
chipcfg->set_pull = samsung_gpio_setpull_updown;
if (!chipcfg->get_pull)
chipcfg->get_pull = samsung_gpio_getpull_updown;
}
}
static int samsung_gpiolib_2bit_input(struct gpio_chip *chip, unsigned offset)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long flags;
unsigned long con;
samsung_gpio_lock(ourchip, flags);
con = __raw_readl(base + 0x00);
con &= ~(3 << (offset * 2));
__raw_writel(con, base + 0x00);
samsung_gpio_unlock(ourchip, flags);
return 0;
}
static int samsung_gpiolib_2bit_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long flags;
unsigned long dat;
unsigned long con;
samsung_gpio_lock(ourchip, flags);
dat = __raw_readl(base + 0x04);
dat &= ~(1 << offset);
if (value)
dat |= 1 << offset;
__raw_writel(dat, base + 0x04);
con = __raw_readl(base + 0x00);
con &= ~(3 << (offset * 2));
con |= 1 << (offset * 2);
__raw_writel(con, base + 0x00);
__raw_writel(dat, base + 0x04);
samsung_gpio_unlock(ourchip, flags);
return 0;
}
static int samsung_gpiolib_4bit_input(struct gpio_chip *chip,
unsigned int offset)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long con;
con = __raw_readl(base + GPIOCON_OFF);
if (ourchip->bitmap_gpio_int & BIT(offset))
con |= 0xf << con_4bit_shift(offset);
else
con &= ~(0xf << con_4bit_shift(offset));
__raw_writel(con, base + GPIOCON_OFF);
pr_debug("%s: %p: CON now %08lx\n", __func__, base, con);
return 0;
}
static int samsung_gpiolib_4bit_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
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
pr_debug("%s: %p: CON %08lx, DAT %08lx\n", __func__, base, con, dat);
return 0;
}
static int samsung_gpiolib_4bit2_input(struct gpio_chip *chip,
unsigned int offset)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
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
pr_debug("%s: %p: CON %08lx\n", __func__, base, con);
return 0;
}
static int samsung_gpiolib_4bit2_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
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
pr_debug("%s: %p: CON %08lx, DAT %08lx\n", __func__, base, con, dat);
return 0;
}
static int s3c24xx_gpiolib_banka_input(struct gpio_chip *chip, unsigned offset)
{
return -EINVAL;
}
static int s3c24xx_gpiolib_banka_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long flags;
unsigned long dat;
unsigned long con;
local_irq_save(flags);
con = __raw_readl(base + 0x00);
dat = __raw_readl(base + 0x04);
dat &= ~(1 << offset);
if (value)
dat |= 1 << offset;
__raw_writel(dat, base + 0x04);
con &= ~(1 << offset);
__raw_writel(con, base + 0x00);
__raw_writel(dat, base + 0x04);
local_irq_restore(flags);
return 0;
}
static int s5p64x0_gpiolib_rbank_input(struct gpio_chip *chip,
unsigned int offset)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
void __iomem *regcon = base;
unsigned long con;
unsigned long flags;
switch (offset) {
case 6:
offset += 1;
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
regcon -= 4;
break;
default:
offset -= 7;
break;
}
samsung_gpio_lock(ourchip, flags);
con = __raw_readl(regcon);
con &= ~(0xf << con_4bit_shift(offset));
__raw_writel(con, regcon);
samsung_gpio_unlock(ourchip, flags);
return 0;
}
static int s5p64x0_gpiolib_rbank_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
void __iomem *regcon = base;
unsigned long con;
unsigned long dat;
unsigned long flags;
unsigned con_offset = offset;
switch (con_offset) {
case 6:
con_offset += 1;
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
regcon -= 4;
break;
default:
con_offset -= 7;
break;
}
samsung_gpio_lock(ourchip, flags);
con = __raw_readl(regcon);
con &= ~(0xf << con_4bit_shift(con_offset));
con |= 0x1 << con_4bit_shift(con_offset);
dat = __raw_readl(base + GPIODAT_OFF);
if (value)
dat |= 1 << offset;
else
dat &= ~(1 << offset);
__raw_writel(con, regcon);
__raw_writel(dat, base + GPIODAT_OFF);
samsung_gpio_unlock(ourchip, flags);
return 0;
}
static void samsung_gpiolib_set(struct gpio_chip *chip,
unsigned offset, int value)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
void __iomem *base = ourchip->base;
unsigned long flags;
unsigned long dat;
samsung_gpio_lock(ourchip, flags);
dat = __raw_readl(base + 0x04);
dat &= ~(1 << offset);
if (value)
dat |= 1 << offset;
__raw_writel(dat, base + 0x04);
samsung_gpio_unlock(ourchip, flags);
}
static int samsung_gpiolib_get(struct gpio_chip *chip, unsigned offset)
{
struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
unsigned long val;
val = __raw_readl(ourchip->base + 0x04);
val >>= offset;
val &= 1;
return val;
}
static __init void s3c_gpiolib_track(struct samsung_gpio_chip *chip)
{
unsigned int gpn;
int i;
gpn = chip->chip.base;
for (i = 0; i < chip->chip.ngpio; i++, gpn++) {
BUG_ON(gpn >= ARRAY_SIZE(s3c_gpios));
s3c_gpios[gpn] = chip;
}
}
static void __init samsung_gpiolib_add(struct samsung_gpio_chip *chip)
{
struct gpio_chip *gc = &chip->chip;
int ret;
BUG_ON(!chip->base);
BUG_ON(!gc->label);
BUG_ON(!gc->ngpio);
spin_lock_init(&chip->lock);
if (!gc->direction_input)
gc->direction_input = samsung_gpiolib_2bit_input;
if (!gc->direction_output)
gc->direction_output = samsung_gpiolib_2bit_output;
if (!gc->set)
gc->set = samsung_gpiolib_set;
if (!gc->get)
gc->get = samsung_gpiolib_get;
#ifdef CONFIG_PM
if (chip->pm != NULL) {
if (!chip->pm->save || !chip->pm->resume)
pr_err("gpio: %s has missing PM functions\n",
gc->label);
} else
pr_err("gpio: %s has no PM function\n", gc->label);
#endif
ret = gpiochip_add(gc);
if (ret >= 0)
s3c_gpiolib_track(chip);
}
static void __init s3c24xx_gpiolib_add_chips(struct samsung_gpio_chip *chip,
int nr_chips, void __iomem *base)
{
int i;
struct gpio_chip *gc = &chip->chip;
for (i = 0 ; i < nr_chips; i++, chip++) {
if (chip->chip.base >= S3C_GPIO_END)
continue;
if (!chip->config)
chip->config = &s3c24xx_gpiocfg_default;
if (!chip->pm)
chip->pm = __gpio_pm(&samsung_gpio_pm_2bit);
if ((base != NULL) && (chip->base == NULL))
chip->base = base + ((i) * 0x10);
if (!gc->direction_input)
gc->direction_input = samsung_gpiolib_2bit_input;
if (!gc->direction_output)
gc->direction_output = samsung_gpiolib_2bit_output;
samsung_gpiolib_add(chip);
}
}
static void __init samsung_gpiolib_add_2bit_chips(struct samsung_gpio_chip *chip,
int nr_chips, void __iomem *base,
unsigned int offset)
{
int i;
for (i = 0 ; i < nr_chips; i++, chip++) {
chip->chip.direction_input = samsung_gpiolib_2bit_input;
chip->chip.direction_output = samsung_gpiolib_2bit_output;
if (!chip->config)
chip->config = &samsung_gpio_cfgs[7];
if (!chip->pm)
chip->pm = __gpio_pm(&samsung_gpio_pm_2bit);
if ((base != NULL) && (chip->base == NULL))
chip->base = base + ((i) * offset);
samsung_gpiolib_add(chip);
}
}
static void __init samsung_gpiolib_add_4bit_chips(struct samsung_gpio_chip *chip,
int nr_chips, void __iomem *base)
{
int i;
for (i = 0 ; i < nr_chips; i++, chip++) {
chip->chip.direction_input = samsung_gpiolib_4bit_input;
chip->chip.direction_output = samsung_gpiolib_4bit_output;
if (!chip->config)
chip->config = &samsung_gpio_cfgs[2];
if (!chip->pm)
chip->pm = __gpio_pm(&samsung_gpio_pm_4bit);
if ((base != NULL) && (chip->base == NULL))
chip->base = base + ((i) * 0x20);
chip->bitmap_gpio_int = 0;
samsung_gpiolib_add(chip);
}
}
static void __init samsung_gpiolib_add_4bit2_chips(struct samsung_gpio_chip *chip,
int nr_chips)
{
for (; nr_chips > 0; nr_chips--, chip++) {
chip->chip.direction_input = samsung_gpiolib_4bit2_input;
chip->chip.direction_output = samsung_gpiolib_4bit2_output;
if (!chip->config)
chip->config = &samsung_gpio_cfgs[2];
if (!chip->pm)
chip->pm = __gpio_pm(&samsung_gpio_pm_4bit);
samsung_gpiolib_add(chip);
}
}
static void __init s5p64x0_gpiolib_add_rbank(struct samsung_gpio_chip *chip,
int nr_chips)
{
for (; nr_chips > 0; nr_chips--, chip++) {
chip->chip.direction_input = s5p64x0_gpiolib_rbank_input;
chip->chip.direction_output = s5p64x0_gpiolib_rbank_output;
if (!chip->pm)
chip->pm = __gpio_pm(&samsung_gpio_pm_4bit);
samsung_gpiolib_add(chip);
}
}
int samsung_gpiolib_to_irq(struct gpio_chip *chip, unsigned int offset)
{
struct samsung_gpio_chip *samsung_chip = container_of(chip, struct samsung_gpio_chip, chip);
return samsung_chip->irq_base + offset;
}
static int s3c24xx_gpiolib_fbank_to_irq(struct gpio_chip *chip, unsigned offset)
{
if (offset < 4) {
if (soc_is_s3c2412())
return IRQ_EINT0_2412 + offset;
else
return IRQ_EINT0 + offset;
}
if (offset < 8)
return IRQ_EINT4 + offset - 4;
return -EINVAL;
}
static int s3c64xx_gpiolib_mbank_to_irq(struct gpio_chip *chip, unsigned pin)
{
return pin < 5 ? IRQ_EINT(23) + pin : -ENXIO;
}
static int s3c64xx_gpiolib_lbank_to_irq(struct gpio_chip *chip, unsigned pin)
{
return pin >= 8 ? IRQ_EINT(16) + pin - 8 : -ENXIO;
}
static int exynos_gpio_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec, u32 *flags)
{
unsigned int pin;
if (WARN_ON(gc->of_gpio_n_cells < 4))
return -EINVAL;
if (WARN_ON(gpiospec->args_count < gc->of_gpio_n_cells))
return -EINVAL;
if (gpiospec->args[0] > gc->ngpio)
return -EINVAL;
pin = gc->base + gpiospec->args[0];
if (s3c_gpio_cfgpin(pin, S3C_GPIO_SFN(gpiospec->args[1])))
pr_warn("gpio_xlate: failed to set pin function\n");
if (s3c_gpio_setpull(pin, gpiospec->args[2] & 0xffff))
pr_warn("gpio_xlate: failed to set pin pull up/down\n");
if (s5p_gpio_set_drvstr(pin, gpiospec->args[3]))
pr_warn("gpio_xlate: failed to set pin drive strength\n");
if (flags)
*flags = gpiospec->args[2] >> 16;
return gpiospec->args[0];
}
static __init void exynos_gpiolib_attach_ofnode(struct samsung_gpio_chip *chip,
u64 base, u64 offset)
{
struct gpio_chip *gc = &chip->chip;
u64 address;
if (!of_have_populated_dt())
return;
address = chip->base ? base + ((u32)chip->base & 0xfff) : base + offset;
gc->of_node = of_find_matching_node_by_address(NULL,
exynos_gpio_dt_match, address);
if (!gc->of_node) {
pr_info("gpio: device tree node not found for gpio controller"
" with base address %08llx\n", address);
return;
}
gc->of_gpio_n_cells = 4;
gc->of_xlate = exynos_gpio_xlate;
}
static __init void exynos_gpiolib_attach_ofnode(struct samsung_gpio_chip *chip,
u64 base, u64 offset)
{
return;
}
static __init void exynos4_gpiolib_init(void)
{
#ifdef CONFIG_CPU_EXYNOS4210
struct samsung_gpio_chip *chip;
int i, nr_chips;
void __iomem *gpio_base1, *gpio_base2, *gpio_base3;
int group = 0;
void __iomem *gpx_base;
gpio_base1 = ioremap(EXYNOS4_PA_GPIO1, SZ_4K);
if (gpio_base1 == NULL) {
pr_err("unable to ioremap for gpio_base1\n");
goto err_ioremap1;
}
chip = exynos4_gpios_1;
nr_chips = ARRAY_SIZE(exynos4_gpios_1);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS4_PA_GPIO1, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos4_gpios_1,
nr_chips, gpio_base1);
gpio_base2 = ioremap(EXYNOS4_PA_GPIO2, SZ_4K);
if (gpio_base2 == NULL) {
pr_err("unable to ioremap for gpio_base2\n");
goto err_ioremap2;
}
chip = &exynos4_gpios_2[16];
gpx_base = gpio_base2 + 0xC00;
for (i = 0; i < 4; i++, chip++, gpx_base += 0x20)
chip->base = gpx_base;
chip = exynos4_gpios_2;
nr_chips = ARRAY_SIZE(exynos4_gpios_2);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS4_PA_GPIO2, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos4_gpios_2,
nr_chips, gpio_base2);
gpio_base3 = ioremap(EXYNOS4_PA_GPIO3, SZ_256);
if (gpio_base3 == NULL) {
pr_err("unable to ioremap for gpio_base3\n");
goto err_ioremap3;
}
chip = exynos4_gpios_3;
nr_chips = ARRAY_SIZE(exynos4_gpios_3);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS4_PA_GPIO3, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos4_gpios_3,
nr_chips, gpio_base3);
#if defined(CONFIG_CPU_EXYNOS4210) && defined(CONFIG_S5P_GPIO_INT)
s5p_register_gpioint_bank(IRQ_GPIO_XA, 0, IRQ_GPIO1_NR_GROUPS);
s5p_register_gpioint_bank(IRQ_GPIO_XB, IRQ_GPIO1_NR_GROUPS, IRQ_GPIO2_NR_GROUPS);
#endif
return;
err_ioremap3:
iounmap(gpio_base2);
err_ioremap2:
iounmap(gpio_base1);
err_ioremap1:
return;
#endif
}
static __init void exynos5_gpiolib_init(void)
{
#ifdef CONFIG_SOC_EXYNOS5250
struct samsung_gpio_chip *chip;
int i, nr_chips;
void __iomem *gpio_base1, *gpio_base2, *gpio_base3, *gpio_base4;
int group = 0;
void __iomem *gpx_base;
gpio_base1 = ioremap(EXYNOS5_PA_GPIO1, SZ_4K);
if (gpio_base1 == NULL) {
pr_err("unable to ioremap for gpio_base1\n");
goto err_ioremap1;
}
exynos5_gpios_1[20].base = gpio_base1 + 0x2E0;
chip = &exynos5_gpios_1[21];
gpx_base = gpio_base1 + 0xC00;
for (i = 0; i < 4; i++, chip++, gpx_base += 0x20)
chip->base = gpx_base;
chip = exynos5_gpios_1;
nr_chips = ARRAY_SIZE(exynos5_gpios_1);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS5_PA_GPIO1, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos5_gpios_1,
nr_chips, gpio_base1);
gpio_base2 = ioremap(EXYNOS5_PA_GPIO2, SZ_4K);
if (gpio_base2 == NULL) {
pr_err("unable to ioremap for gpio_base2\n");
goto err_ioremap2;
}
chip = exynos5_gpios_2;
nr_chips = ARRAY_SIZE(exynos5_gpios_2);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS5_PA_GPIO2, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos5_gpios_2,
nr_chips, gpio_base2);
gpio_base3 = ioremap(EXYNOS5_PA_GPIO3, SZ_4K);
if (gpio_base3 == NULL) {
pr_err("unable to ioremap for gpio_base3\n");
goto err_ioremap3;
}
exynos5_gpios_3[0].base = gpio_base3;
exynos5_gpios_3[1].base = gpio_base3 + 0x20;
exynos5_gpios_3[2].base = gpio_base3 + 0x60;
exynos5_gpios_3[3].base = gpio_base3 + 0x80;
exynos5_gpios_3[4].base = gpio_base3 + 0xC0;
chip = exynos5_gpios_3;
nr_chips = ARRAY_SIZE(exynos5_gpios_3);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS5_PA_GPIO3, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos5_gpios_3,
nr_chips, gpio_base3);
gpio_base4 = ioremap(EXYNOS5_PA_GPIO4, SZ_4K);
if (gpio_base4 == NULL) {
pr_err("unable to ioremap for gpio_base4\n");
goto err_ioremap4;
}
chip = exynos5_gpios_4;
nr_chips = ARRAY_SIZE(exynos5_gpios_4);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &exynos_gpio_cfg;
chip->group = group++;
}
exynos_gpiolib_attach_ofnode(chip,
EXYNOS5_PA_GPIO4, i * 0x20);
}
samsung_gpiolib_add_4bit_chips(exynos5_gpios_4,
nr_chips, gpio_base4);
return;
err_ioremap4:
iounmap(gpio_base3);
err_ioremap3:
iounmap(gpio_base2);
err_ioremap2:
iounmap(gpio_base1);
err_ioremap1:
return;
#endif
}
static __init int samsung_gpiolib_init(void)
{
struct samsung_gpio_chip *chip;
int i, nr_chips;
int group = 0;
#if defined(CONFIG_PINCTRL_EXYNOS) || defined(CONFIG_PINCTRL_EXYNOS5440)
struct device_node *pctrl_np;
static const struct of_device_id exynos_pinctrl_ids[] = {
{ .compatible = "samsung,s3c2412-pinctrl", },
{ .compatible = "samsung,s3c2416-pinctrl", },
{ .compatible = "samsung,s3c2440-pinctrl", },
{ .compatible = "samsung,s3c2450-pinctrl", },
{ .compatible = "samsung,exynos4210-pinctrl", },
{ .compatible = "samsung,exynos4x12-pinctrl", },
{ .compatible = "samsung,exynos5250-pinctrl", },
{ .compatible = "samsung,exynos5440-pinctrl", },
{ }
};
for_each_matching_node(pctrl_np, exynos_pinctrl_ids)
if (pctrl_np && of_device_is_available(pctrl_np))
return -ENODEV;
#endif
samsung_gpiolib_set_cfg(samsung_gpio_cfgs, ARRAY_SIZE(samsung_gpio_cfgs));
if (soc_is_s3c24xx()) {
s3c24xx_gpiolib_add_chips(s3c24xx_gpios,
ARRAY_SIZE(s3c24xx_gpios), S3C24XX_VA_GPIO);
} else if (soc_is_s3c64xx()) {
samsung_gpiolib_add_2bit_chips(s3c64xx_gpios_2bit,
ARRAY_SIZE(s3c64xx_gpios_2bit),
S3C64XX_VA_GPIO + 0xE0, 0x20);
samsung_gpiolib_add_4bit_chips(s3c64xx_gpios_4bit,
ARRAY_SIZE(s3c64xx_gpios_4bit),
S3C64XX_VA_GPIO);
samsung_gpiolib_add_4bit2_chips(s3c64xx_gpios_4bit2,
ARRAY_SIZE(s3c64xx_gpios_4bit2));
} else if (soc_is_s5p6440()) {
samsung_gpiolib_add_2bit_chips(s5p6440_gpios_2bit,
ARRAY_SIZE(s5p6440_gpios_2bit), NULL, 0x0);
samsung_gpiolib_add_4bit_chips(s5p6440_gpios_4bit,
ARRAY_SIZE(s5p6440_gpios_4bit), S5P_VA_GPIO);
samsung_gpiolib_add_4bit2_chips(s5p6440_gpios_4bit2,
ARRAY_SIZE(s5p6440_gpios_4bit2));
s5p64x0_gpiolib_add_rbank(s5p6440_gpios_rbank,
ARRAY_SIZE(s5p6440_gpios_rbank));
} else if (soc_is_s5p6450()) {
samsung_gpiolib_add_2bit_chips(s5p6450_gpios_2bit,
ARRAY_SIZE(s5p6450_gpios_2bit), NULL, 0x0);
samsung_gpiolib_add_4bit_chips(s5p6450_gpios_4bit,
ARRAY_SIZE(s5p6450_gpios_4bit), S5P_VA_GPIO);
samsung_gpiolib_add_4bit2_chips(s5p6450_gpios_4bit2,
ARRAY_SIZE(s5p6450_gpios_4bit2));
s5p64x0_gpiolib_add_rbank(s5p6450_gpios_rbank,
ARRAY_SIZE(s5p6450_gpios_rbank));
} else if (soc_is_s5pc100()) {
group = 0;
chip = s5pc100_gpios_4bit;
nr_chips = ARRAY_SIZE(s5pc100_gpios_4bit);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &samsung_gpio_cfgs[3];
chip->group = group++;
}
}
samsung_gpiolib_add_4bit_chips(s5pc100_gpios_4bit, nr_chips, S5P_VA_GPIO);
#if defined(CONFIG_CPU_S5PC100) && defined(CONFIG_S5P_GPIO_INT)
s5p_register_gpioint_bank(IRQ_GPIOINT, 0, S5P_GPIOINT_GROUP_MAXNR);
#endif
} else if (soc_is_s5pv210()) {
group = 0;
chip = s5pv210_gpios_4bit;
nr_chips = ARRAY_SIZE(s5pv210_gpios_4bit);
for (i = 0; i < nr_chips; i++, chip++) {
if (!chip->config) {
chip->config = &samsung_gpio_cfgs[3];
chip->group = group++;
}
}
samsung_gpiolib_add_4bit_chips(s5pv210_gpios_4bit, nr_chips, S5P_VA_GPIO);
#if defined(CONFIG_CPU_S5PV210) && defined(CONFIG_S5P_GPIO_INT)
s5p_register_gpioint_bank(IRQ_GPIOINT, 0, S5P_GPIOINT_GROUP_MAXNR);
#endif
} else if (soc_is_exynos4210()) {
exynos4_gpiolib_init();
} else if (soc_is_exynos5250()) {
exynos5_gpiolib_init();
} else {
WARN(1, "Unknown SoC in gpio-samsung, no GPIOs added\n");
return -ENODEV;
}
return 0;
}
int s3c_gpio_cfgpin(unsigned int pin, unsigned int config)
{
struct samsung_gpio_chip *chip = samsung_gpiolib_getchip(pin);
unsigned long flags;
int offset;
int ret;
if (!chip)
return -EINVAL;
offset = pin - chip->chip.base;
samsung_gpio_lock(chip, flags);
ret = samsung_gpio_do_setcfg(chip, offset, config);
samsung_gpio_unlock(chip, flags);
return ret;
}
int s3c_gpio_cfgpin_range(unsigned int start, unsigned int nr,
unsigned int cfg)
{
int ret;
for (; nr > 0; nr--, start++) {
ret = s3c_gpio_cfgpin(start, cfg);
if (ret != 0)
return ret;
}
return 0;
}
int s3c_gpio_cfgall_range(unsigned int start, unsigned int nr,
unsigned int cfg, samsung_gpio_pull_t pull)
{
int ret;
for (; nr > 0; nr--, start++) {
s3c_gpio_setpull(start, pull);
ret = s3c_gpio_cfgpin(start, cfg);
if (ret != 0)
return ret;
}
return 0;
}
unsigned s3c_gpio_getcfg(unsigned int pin)
{
struct samsung_gpio_chip *chip = samsung_gpiolib_getchip(pin);
unsigned long flags;
unsigned ret = 0;
int offset;
if (chip) {
offset = pin - chip->chip.base;
samsung_gpio_lock(chip, flags);
ret = samsung_gpio_do_getcfg(chip, offset);
samsung_gpio_unlock(chip, flags);
}
return ret;
}
int s3c_gpio_setpull(unsigned int pin, samsung_gpio_pull_t pull)
{
struct samsung_gpio_chip *chip = samsung_gpiolib_getchip(pin);
unsigned long flags;
int offset, ret;
if (!chip)
return -EINVAL;
offset = pin - chip->chip.base;
samsung_gpio_lock(chip, flags);
ret = samsung_gpio_do_setpull(chip, offset, pull);
samsung_gpio_unlock(chip, flags);
return ret;
}
samsung_gpio_pull_t s3c_gpio_getpull(unsigned int pin)
{
struct samsung_gpio_chip *chip = samsung_gpiolib_getchip(pin);
unsigned long flags;
int offset;
u32 pup = 0;
if (chip) {
offset = pin - chip->chip.base;
samsung_gpio_lock(chip, flags);
pup = samsung_gpio_do_getpull(chip, offset);
samsung_gpio_unlock(chip, flags);
}
return (__force samsung_gpio_pull_t)pup;
}
s5p_gpio_drvstr_t s5p_gpio_get_drvstr(unsigned int pin)
{
struct samsung_gpio_chip *chip = samsung_gpiolib_getchip(pin);
unsigned int off;
void __iomem *reg;
int shift;
u32 drvstr;
if (!chip)
return -EINVAL;
off = pin - chip->chip.base;
shift = off * 2;
reg = chip->base + 0x0C;
drvstr = __raw_readl(reg);
drvstr = drvstr >> shift;
drvstr &= 0x3;
return (__force s5p_gpio_drvstr_t)drvstr;
}
int s5p_gpio_set_drvstr(unsigned int pin, s5p_gpio_drvstr_t drvstr)
{
struct samsung_gpio_chip *chip = samsung_gpiolib_getchip(pin);
unsigned int off;
void __iomem *reg;
int shift;
u32 tmp;
if (!chip)
return -EINVAL;
off = pin - chip->chip.base;
shift = off * 2;
reg = chip->base + 0x0C;
tmp = __raw_readl(reg);
tmp &= ~(0x3 << shift);
tmp |= drvstr << shift;
__raw_writel(tmp, reg);
return 0;
}
unsigned int s3c2410_modify_misccr(unsigned int clear, unsigned int change)
{
unsigned long flags;
unsigned long misccr;
local_irq_save(flags);
misccr = __raw_readl(S3C24XX_MISCCR);
misccr &= ~clear;
misccr ^= change;
__raw_writel(misccr, S3C24XX_MISCCR);
local_irq_restore(flags);
return misccr;
}
