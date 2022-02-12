void touchscreen_parse_of_params(struct input_dev *dev)
{
struct device_node *np = dev->dev.parent->of_node;
struct input_absinfo *absinfo;
input_alloc_absinfo(dev);
if (!dev->absinfo)
return;
absinfo = &dev->absinfo[ABS_X];
of_property_read_u32(np, "touchscreen-size-x", &absinfo->maximum);
of_property_read_u32(np, "touchscreen-fuzz-x", &absinfo->fuzz);
absinfo = &dev->absinfo[ABS_Y];
of_property_read_u32(np, "touchscreen-size-y", &absinfo->maximum);
of_property_read_u32(np, "touchscreen-fuzz-y", &absinfo->fuzz);
absinfo = &dev->absinfo[ABS_PRESSURE];
of_property_read_u32(np, "touchscreen-max-pressure", &absinfo->maximum);
of_property_read_u32(np, "touchscreen-fuzz-pressure", &absinfo->fuzz);
}
