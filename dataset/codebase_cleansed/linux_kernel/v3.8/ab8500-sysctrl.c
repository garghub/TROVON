static inline bool valid_bank(u8 bank)
{
return ((bank == AB8500_SYS_CTRL1_BLOCK) ||
(bank == AB8500_SYS_CTRL2_BLOCK));
}
int ab8500_sysctrl_read(u16 reg, u8 *value)
{
u8 bank;
if (sysctrl_dev == NULL)
return -EAGAIN;
bank = (reg >> 8);
if (!valid_bank(bank))
return -EINVAL;
return abx500_get_register_interruptible(sysctrl_dev, bank,
(u8)(reg & 0xFF), value);
}
int ab8500_sysctrl_write(u16 reg, u8 mask, u8 value)
{
u8 bank;
if (sysctrl_dev == NULL)
return -EAGAIN;
bank = (reg >> 8);
if (!valid_bank(bank))
return -EINVAL;
return abx500_mask_and_set_register_interruptible(sysctrl_dev, bank,
(u8)(reg & 0xFF), mask, value);
}
static int ab8500_sysctrl_probe(struct platform_device *pdev)
{
sysctrl_dev = &pdev->dev;
return 0;
}
static int ab8500_sysctrl_remove(struct platform_device *pdev)
{
sysctrl_dev = NULL;
return 0;
}
static int __init ab8500_sysctrl_init(void)
{
return platform_driver_register(&ab8500_sysctrl_driver);
}
