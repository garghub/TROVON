static void mvebu_armada_xp_gp_pm_enter(void __iomem *sdram_reg, u32 srcmd)
{
u32 reg, ackcmd;
int i;
reg = readl(gpio_ctrl);
for (i = 0; i < ARMADA_XP_GP_PIC_NR_GPIOS; i++)
reg &= ~BIT(pic_raw_gpios[i]);
reg |= BIT(pic_raw_gpios[0]);
writel(reg, gpio_ctrl);
ackcmd = readl(gpio_ctrl);
for (i = 0; i < ARMADA_XP_GP_PIC_NR_GPIOS; i++)
ackcmd |= BIT(pic_raw_gpios[i]);
srcmd = cpu_to_le32(srcmd);
ackcmd = cpu_to_le32(ackcmd);
mdelay(3000);
asm volatile (
".balign 32\n\t"
"str %[srcmd], [%[sdram_reg]]\n\t"
"mov r1, #50\n\t"
"1: subs r1, r1, #1\n\t"
"bne 1b\n\t"
"str %[ackcmd], [%[gpio_ctrl]]\n\t"
"b .\n\t"
: : [srcmd] "r" (srcmd), [sdram_reg] "r" (sdram_reg),
[ackcmd] "r" (ackcmd), [gpio_ctrl] "r" (gpio_ctrl) : "r1");
}
static int mvebu_armada_xp_gp_pm_init(void)
{
struct device_node *np;
struct device_node *gpio_ctrl_np;
int ret = 0, i;
if (!of_machine_is_compatible("marvell,axp-gp"))
return -ENODEV;
np = of_find_node_by_name(NULL, "pm_pic");
if (!np)
return -ENODEV;
for (i = 0; i < ARMADA_XP_GP_PIC_NR_GPIOS; i++) {
char *name;
struct of_phandle_args args;
pic_gpios[i] = of_get_named_gpio(np, "ctrl-gpios", i);
if (pic_gpios[i] < 0) {
ret = -ENODEV;
goto out;
}
name = kasprintf(GFP_KERNEL, "pic-pin%d", i);
if (!name) {
ret = -ENOMEM;
goto out;
}
ret = gpio_request(pic_gpios[i], name);
if (ret < 0) {
kfree(name);
goto out;
}
ret = gpio_direction_output(pic_gpios[i], 0);
if (ret < 0) {
gpio_free(pic_gpios[i]);
kfree(name);
goto out;
}
ret = of_parse_phandle_with_fixed_args(np, "ctrl-gpios", 2,
i, &args);
if (ret < 0) {
gpio_free(pic_gpios[i]);
kfree(name);
goto out;
}
gpio_ctrl_np = args.np;
pic_raw_gpios[i] = args.args[0];
}
gpio_ctrl = of_iomap(gpio_ctrl_np, 0);
if (!gpio_ctrl)
return -ENOMEM;
mvebu_pm_init(mvebu_armada_xp_gp_pm_enter);
out:
of_node_put(np);
return ret;
}
