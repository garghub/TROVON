static void __init *lis331dl_platform_data(void *info)
{
static short intr2nd_pdata;
struct i2c_board_info *i2c_info = info;
int intr = get_gpio_by_name("accel_int");
int intr2nd = get_gpio_by_name("accel_2");
if (intr == -1 || intr2nd == -1)
return NULL;
i2c_info->irq = intr + INTEL_MID_IRQ_OFFSET;
intr2nd_pdata = intr2nd + INTEL_MID_IRQ_OFFSET;
return &intr2nd_pdata;
}
