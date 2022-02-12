void __init u5500_sdi_init(struct device *parent)
{
nmk_config_pins(u5500_sdi_pins, ARRAY_SIZE(u5500_sdi_pins));
db5500_add_sdi0(parent, &u5500_sdi0_data);
}
