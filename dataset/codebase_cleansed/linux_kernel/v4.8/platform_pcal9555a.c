static void __init *pcal9555a_platform_data(void *info)
{
struct i2c_board_info *i2c_info = info;
char *type = i2c_info->type;
struct pca953x_platform_data *pcal9555a;
char base_pin_name[SFI_NAME_LEN + 1];
char intr_pin_name[SFI_NAME_LEN + 1];
int gpio_base, intr;
snprintf(base_pin_name, sizeof(base_pin_name), "%s_base", type);
snprintf(intr_pin_name, sizeof(intr_pin_name), "%s_int", type);
gpio_base = get_gpio_by_name(base_pin_name);
intr = get_gpio_by_name(intr_pin_name);
if (gpio_base == -1)
return NULL;
if (nr >= PCAL9555A_NUM) {
pr_err("%s: Too many instances, only %d supported\n", __func__,
PCAL9555A_NUM);
return NULL;
}
pcal9555a = &pcal9555a_pdata[nr++];
pcal9555a->gpio_base = gpio_base;
if (intr >= 0) {
i2c_info->irq = intr + INTEL_MID_IRQ_OFFSET;
pcal9555a->irq_base = gpio_base + INTEL_MID_IRQ_OFFSET;
} else {
i2c_info->irq = -1;
pcal9555a->irq_base = -1;
}
strcpy(type, "pcal9555a");
return pcal9555a;
}
