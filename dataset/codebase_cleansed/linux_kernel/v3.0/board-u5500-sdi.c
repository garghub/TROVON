void __init u5500_sdi_init(void)
{
nmk_config_pins(u5500_sdi_pins, ARRAY_SIZE(u5500_sdi_pins));
db5500_add_sdi0(&u5500_sdi0_data);
}
