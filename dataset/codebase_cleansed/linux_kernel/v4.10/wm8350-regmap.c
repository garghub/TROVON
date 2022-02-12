static bool wm8350_readable(struct device *dev, unsigned int reg)
{
return wm8350_reg_io_map[reg].readable;
}
static bool wm8350_writeable(struct device *dev, unsigned int reg)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
if (!wm8350->unlocked) {
if ((reg >= WM8350_GPIO_FUNCTION_SELECT_1 &&
reg <= WM8350_GPIO_FUNCTION_SELECT_4) ||
(reg >= WM8350_BATTERY_CHARGER_CONTROL_1 &&
reg <= WM8350_BATTERY_CHARGER_CONTROL_3))
return false;
}
return wm8350_reg_io_map[reg].writable;
}
static bool wm8350_volatile(struct device *dev, unsigned int reg)
{
return wm8350_reg_io_map[reg].vol;
}
static bool wm8350_precious(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8350_SYSTEM_INTERRUPTS:
case WM8350_INT_STATUS_1:
case WM8350_INT_STATUS_2:
case WM8350_POWER_UP_INT_STATUS:
case WM8350_UNDER_VOLTAGE_INT_STATUS:
case WM8350_OVER_CURRENT_INT_STATUS:
case WM8350_GPIO_INT_STATUS:
case WM8350_COMPARATOR_INT_STATUS:
return true;
default:
return false;
}
}
