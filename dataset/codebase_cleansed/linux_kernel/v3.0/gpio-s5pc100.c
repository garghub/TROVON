static __init int s5pc100_gpiolib_init(void)
{
struct s3c_gpio_chip *chip = s5pc100_gpio_chips;
int nr_chips = ARRAY_SIZE(s5pc100_gpio_chips);
int gpioint_group = 0;
int i;
for (i = 0; i < nr_chips; i++, chip++) {
if (chip->config == NULL) {
chip->config = &gpio_cfg;
chip->group = gpioint_group++;
}
if (chip->base == NULL)
chip->base = S5PC100_BANK_BASE(i);
}
samsung_gpiolib_add_4bit_chips(s5pc100_gpio_chips, nr_chips);
s5p_register_gpioint_bank(IRQ_GPIOINT, 0, S5P_GPIOINT_GROUP_MAXNR);
return 0;
}
