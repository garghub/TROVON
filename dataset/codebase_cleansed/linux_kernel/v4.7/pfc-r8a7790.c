static int r8a7790_get_io_voltage(struct sh_pfc *pfc, unsigned int pin)
{
u32 data, mask;
if (WARN(pin < RCAR_GP_PIN(3, 0) || pin > RCAR_GP_PIN(3, 31), "invalid pin %#x", pin))
return -EINVAL;
data = ioread32(pfc->windows->virt + IOCTRL6),
mask = 0x80000000 >> (pin & 0x1f);
return (data & mask) ? 3300 : 1800;
}
static int r8a7790_set_io_voltage(struct sh_pfc *pfc, unsigned int pin, u16 mV)
{
u32 data, mask;
if (WARN(pin < RCAR_GP_PIN(3, 0) || pin > RCAR_GP_PIN(3, 31), "invalid pin %#x", pin))
return -EINVAL;
if (mV != 1800 && mV != 3300)
return -EINVAL;
data = ioread32(pfc->windows->virt + IOCTRL6);
mask = 0x80000000 >> (pin & 0x1f);
if (mV == 3300)
data |= mask;
else
data &= ~mask;
iowrite32(~data, pfc->windows->virt);
iowrite32(data, pfc->windows->virt + IOCTRL6);
return 0;
}
