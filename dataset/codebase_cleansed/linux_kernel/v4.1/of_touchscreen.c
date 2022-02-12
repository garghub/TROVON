static u32 of_get_optional_u32(struct device_node *np,
const char *property)
{
u32 val = 0;
of_property_read_u32(np, property, &val);
return val;
}
static void touchscreen_set_params(struct input_dev *dev,
unsigned long axis,
int max, int fuzz)
{
struct input_absinfo *absinfo;
if (!test_bit(axis, dev->absbit)) {
if (!input_is_mt_axis(axis))
dev_warn(&dev->dev,
"DT specifies parameters but the axis is not set up\n");
return;
}
absinfo = &dev->absinfo[axis];
absinfo->maximum = max;
absinfo->fuzz = fuzz;
}
void touchscreen_parse_of_params(struct input_dev *dev)
{
struct device_node *np = dev->dev.parent->of_node;
u32 maximum, fuzz;
input_alloc_absinfo(dev);
if (!dev->absinfo)
return;
maximum = of_get_optional_u32(np, "touchscreen-size-x");
fuzz = of_get_optional_u32(np, "touchscreen-fuzz-x");
if (maximum || fuzz) {
touchscreen_set_params(dev, ABS_X, maximum, fuzz);
touchscreen_set_params(dev, ABS_MT_POSITION_X, maximum, fuzz);
}
maximum = of_get_optional_u32(np, "touchscreen-size-y");
fuzz = of_get_optional_u32(np, "touchscreen-fuzz-y");
if (maximum || fuzz) {
touchscreen_set_params(dev, ABS_Y, maximum, fuzz);
touchscreen_set_params(dev, ABS_MT_POSITION_Y, maximum, fuzz);
}
maximum = of_get_optional_u32(np, "touchscreen-max-pressure");
fuzz = of_get_optional_u32(np, "touchscreen-fuzz-pressure");
if (maximum || fuzz) {
touchscreen_set_params(dev, ABS_PRESSURE, maximum, fuzz);
touchscreen_set_params(dev, ABS_MT_PRESSURE, maximum, fuzz);
}
}
