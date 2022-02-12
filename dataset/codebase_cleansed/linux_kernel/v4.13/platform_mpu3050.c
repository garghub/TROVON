static void *mpu3050_platform_data(void *info)
{
struct i2c_board_info *i2c_info = info;
int intr = get_gpio_by_name("mpu3050_int");
if (intr < 0)
return NULL;
i2c_info->irq = intr + INTEL_MID_IRQ_OFFSET;
return NULL;
}
