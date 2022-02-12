static int sigmadsp_write_regmap(void *control_data,
unsigned int addr, const uint8_t data[], size_t len)
{
return regmap_raw_write(control_data, addr,
data, len);
}
static int sigmadsp_read_regmap(void *control_data,
unsigned int addr, uint8_t data[], size_t len)
{
return regmap_raw_read(control_data, addr,
data, len);
}
struct sigmadsp *devm_sigmadsp_init_regmap(struct device *dev,
struct regmap *regmap, const struct sigmadsp_ops *ops,
const char *firmware_name)
{
struct sigmadsp *sigmadsp;
sigmadsp = devm_sigmadsp_init(dev, ops, firmware_name);
if (IS_ERR(sigmadsp))
return sigmadsp;
sigmadsp->control_data = regmap;
sigmadsp->write = sigmadsp_write_regmap;
sigmadsp->read = sigmadsp_read_regmap;
return sigmadsp;
}
