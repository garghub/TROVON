static int sigma_action_write_regmap(void *control_data,
const struct sigma_action *sa, size_t len)
{
return regmap_raw_write(control_data, be16_to_cpu(sa->addr),
sa->payload, len - 2);
}
int process_sigma_firmware_regmap(struct device *dev, struct regmap *regmap,
const char *name)
{
struct sigma_firmware ssfw;
ssfw.control_data = regmap;
ssfw.write = sigma_action_write_regmap;
return _process_sigma_firmware(dev, &ssfw, name);
}
