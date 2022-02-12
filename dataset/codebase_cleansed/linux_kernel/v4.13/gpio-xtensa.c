static inline unsigned long enable_cp(unsigned long *cpenable)
{
unsigned long flags;
local_irq_save(flags);
RSR_CPENABLE(*cpenable);
WSR_CPENABLE(*cpenable | BIT(XCHAL_CP_ID_XTIOP));
return flags;
}
static inline void disable_cp(unsigned long flags, unsigned long cpenable)
{
WSR_CPENABLE(cpenable);
local_irq_restore(flags);
}
static inline unsigned long enable_cp(unsigned long *cpenable)
{
*cpenable = 0;
return 0;
}
static inline void disable_cp(unsigned long flags, unsigned long cpenable)
{
}
static int xtensa_impwire_get_direction(struct gpio_chip *gc, unsigned offset)
{
return 1;
}
static int xtensa_impwire_get_value(struct gpio_chip *gc, unsigned offset)
{
unsigned long flags, saved_cpenable;
u32 impwire;
flags = enable_cp(&saved_cpenable);
__asm__ __volatile__("read_impwire %0" : "=a" (impwire));
disable_cp(flags, saved_cpenable);
return !!(impwire & BIT(offset));
}
static void xtensa_impwire_set_value(struct gpio_chip *gc, unsigned offset,
int value)
{
BUG();
}
static int xtensa_expstate_get_direction(struct gpio_chip *gc, unsigned offset)
{
return 0;
}
static int xtensa_expstate_get_value(struct gpio_chip *gc, unsigned offset)
{
unsigned long flags, saved_cpenable;
u32 expstate;
flags = enable_cp(&saved_cpenable);
__asm__ __volatile__("rur.expstate %0" : "=a" (expstate));
disable_cp(flags, saved_cpenable);
return !!(expstate & BIT(offset));
}
static void xtensa_expstate_set_value(struct gpio_chip *gc, unsigned offset,
int value)
{
unsigned long flags, saved_cpenable;
u32 mask = BIT(offset);
u32 val = value ? BIT(offset) : 0;
flags = enable_cp(&saved_cpenable);
__asm__ __volatile__("wrmsk_expstate %0, %1"
:: "a" (val), "a" (mask));
disable_cp(flags, saved_cpenable);
}
static int xtensa_gpio_probe(struct platform_device *pdev)
{
int ret;
ret = gpiochip_add_data(&impwire_chip, NULL);
if (ret)
return ret;
return gpiochip_add_data(&expstate_chip, NULL);
}
static int __init xtensa_gpio_init(void)
{
struct platform_device *pdev;
pdev = platform_device_register_simple("xtensa-gpio", 0, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
return platform_driver_register(&xtensa_gpio_driver);
}
