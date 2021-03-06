int exynos4_fimc_setup_gpio(enum s5p_camport_id id)
{
u32 gpio8, gpio5;
u32 sfn;
int ret;
switch (id) {
case S5P_CAMPORT_A:
gpio8 = EXYNOS4_GPJ0(0);
gpio5 = EXYNOS4_GPJ1(0);
sfn = S3C_GPIO_SFN(2);
break;
case S5P_CAMPORT_B:
gpio8 = EXYNOS4_GPE0(0);
gpio5 = EXYNOS4_GPE1(0);
sfn = S3C_GPIO_SFN(3);
break;
default:
WARN(1, "Wrong camport id: %d\n", id);
return -EINVAL;
}
ret = s3c_gpio_cfgall_range(gpio8, 8, sfn, S3C_GPIO_PULL_UP);
if (ret)
return ret;
return s3c_gpio_cfgall_range(gpio5, 5, sfn, S3C_GPIO_PULL_UP);
}
