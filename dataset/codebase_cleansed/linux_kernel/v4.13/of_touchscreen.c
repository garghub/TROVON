static bool touchscreen_get_prop_u32(struct device *dev,
const char *property,
unsigned int default_value,
unsigned int *value)
{
u32 val;
int error;
error = device_property_read_u32(dev, property, &val);
if (error) {
*value = default_value;
return false;
}
*value = val;
return true;
}
static void touchscreen_set_params(struct input_dev *dev,
unsigned long axis,
int max, int fuzz)
{
struct input_absinfo *absinfo;
if (!test_bit(axis, dev->absbit)) {
dev_warn(&dev->dev,
"DT specifies parameters but the axis %lu is not set up\n",
axis);
return;
}
absinfo = &dev->absinfo[axis];
absinfo->maximum = max;
absinfo->fuzz = fuzz;
}
void touchscreen_parse_properties(struct input_dev *input, bool multitouch,
struct touchscreen_properties *prop)
{
struct device *dev = input->dev.parent;
unsigned int axis;
unsigned int maximum, fuzz;
bool data_present;
input_alloc_absinfo(input);
if (!input->absinfo)
return;
axis = multitouch ? ABS_MT_POSITION_X : ABS_X;
data_present = touchscreen_get_prop_u32(dev, "touchscreen-size-x",
input_abs_get_max(input,
axis) + 1,
&maximum) |
touchscreen_get_prop_u32(dev, "touchscreen-fuzz-x",
input_abs_get_fuzz(input, axis),
&fuzz);
if (data_present)
touchscreen_set_params(input, axis, maximum - 1, fuzz);
axis = multitouch ? ABS_MT_POSITION_Y : ABS_Y;
data_present = touchscreen_get_prop_u32(dev, "touchscreen-size-y",
input_abs_get_max(input,
axis) + 1,
&maximum) |
touchscreen_get_prop_u32(dev, "touchscreen-fuzz-y",
input_abs_get_fuzz(input, axis),
&fuzz);
if (data_present)
touchscreen_set_params(input, axis, maximum - 1, fuzz);
axis = multitouch ? ABS_MT_PRESSURE : ABS_PRESSURE;
data_present = touchscreen_get_prop_u32(dev,
"touchscreen-max-pressure",
input_abs_get_max(input, axis),
&maximum) |
touchscreen_get_prop_u32(dev,
"touchscreen-fuzz-pressure",
input_abs_get_fuzz(input, axis),
&fuzz);
if (data_present)
touchscreen_set_params(input, axis, maximum, fuzz);
if (!prop)
return;
axis = multitouch ? ABS_MT_POSITION_X : ABS_X;
prop->max_x = input_abs_get_max(input, axis);
prop->max_y = input_abs_get_max(input, axis + 1);
prop->invert_x =
device_property_read_bool(dev, "touchscreen-inverted-x");
prop->invert_y =
device_property_read_bool(dev, "touchscreen-inverted-y");
prop->swap_x_y =
device_property_read_bool(dev, "touchscreen-swapped-x-y");
if (prop->swap_x_y)
swap(input->absinfo[axis], input->absinfo[axis + 1]);
}
static void
touchscreen_apply_prop_to_x_y(const struct touchscreen_properties *prop,
unsigned int *x, unsigned int *y)
{
if (prop->invert_x)
*x = prop->max_x - *x;
if (prop->invert_y)
*y = prop->max_y - *y;
if (prop->swap_x_y)
swap(*x, *y);
}
void touchscreen_set_mt_pos(struct input_mt_pos *pos,
const struct touchscreen_properties *prop,
unsigned int x, unsigned int y)
{
touchscreen_apply_prop_to_x_y(prop, &x, &y);
pos->x = x;
pos->y = y;
}
void touchscreen_report_pos(struct input_dev *input,
const struct touchscreen_properties *prop,
unsigned int x, unsigned int y,
bool multitouch)
{
touchscreen_apply_prop_to_x_y(prop, &x, &y);
input_report_abs(input, multitouch ? ABS_MT_POSITION_X : ABS_X, x);
input_report_abs(input, multitouch ? ABS_MT_POSITION_Y : ABS_Y, y);
}
