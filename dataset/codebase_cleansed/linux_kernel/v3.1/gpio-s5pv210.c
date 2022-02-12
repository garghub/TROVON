static __init int s5pv210_gpiolib_init(void)
{
struct s3c_gpio_chip *chip = s5pv210_gpio_4bit;
int nr_chips = ARRAY_SIZE(s5pv210_gpio_4bit);
int gpioint_group = 0;
int i = 0;
for (i = 0; i < nr_chips; i++, chip++) {
if (chip->config == NULL) {
chip->config = &gpio_cfg;
chip->group = gpioint_group++;
}
if (chip->base == NULL)
chip->base = S5PV210_BANK_BASE(i);
}
samsung_gpiolib_add_4bit_chips(s5pv210_gpio_4bit, nr_chips);
s5p_register_gpioint_bank(IRQ_GPIOINT, 0, S5P_GPIOINT_GROUP_MAXNR);
return 0;
}
