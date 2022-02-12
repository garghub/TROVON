int s3c_gpio_setpull_exynos4(struct s3c_gpio_chip *chip,
unsigned int off, s3c_gpio_pull_t pull)
{
if (pull == S3C_GPIO_PULL_UP)
pull = 3;
return s3c_gpio_setpull_updown(chip, off, pull);
}
s3c_gpio_pull_t s3c_gpio_getpull_exynos4(struct s3c_gpio_chip *chip,
unsigned int off)
{
s3c_gpio_pull_t pull;
pull = s3c_gpio_getpull_updown(chip, off);
if (pull == 3)
pull = S3C_GPIO_PULL_UP;
return pull;
}
static __init int exynos4_gpiolib_init(void)
{
struct s3c_gpio_chip *chip;
int i;
int group = 0;
int nr_chips;
chip = exynos4_gpio_part1_4bit;
nr_chips = ARRAY_SIZE(exynos4_gpio_part1_4bit);
for (i = 0; i < nr_chips; i++, chip++) {
if (chip->config == NULL) {
chip->config = &gpio_cfg;
chip->group = group++;
}
if (chip->base == NULL)
chip->base = S5P_VA_GPIO1 + (i) * 0x20;
}
samsung_gpiolib_add_4bit_chips(exynos4_gpio_part1_4bit, nr_chips);
chip = exynos4_gpio_part2_4bit;
nr_chips = ARRAY_SIZE(exynos4_gpio_part2_4bit);
for (i = 0; i < nr_chips; i++, chip++) {
if (chip->config == NULL) {
chip->config = &gpio_cfg;
chip->group = group++;
}
if (chip->base == NULL)
chip->base = S5P_VA_GPIO2 + (i) * 0x20;
}
samsung_gpiolib_add_4bit_chips(exynos4_gpio_part2_4bit, nr_chips);
chip = exynos4_gpio_part3_4bit;
nr_chips = ARRAY_SIZE(exynos4_gpio_part3_4bit);
for (i = 0; i < nr_chips; i++, chip++) {
if (chip->config == NULL) {
chip->config = &gpio_cfg;
chip->group = group++;
}
if (chip->base == NULL)
chip->base = S5P_VA_GPIO3 + (i) * 0x20;
}
samsung_gpiolib_add_4bit_chips(exynos4_gpio_part3_4bit, nr_chips);
s5p_register_gpioint_bank(IRQ_GPIO_XA, 0, IRQ_GPIO1_NR_GROUPS);
s5p_register_gpioint_bank(IRQ_GPIO_XB, IRQ_GPIO1_NR_GROUPS, IRQ_GPIO2_NR_GROUPS);
return 0;
}
