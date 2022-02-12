void __init u5500_sdi_init(void)\r\n{\r\nnmk_config_pins(u5500_sdi_pins, ARRAY_SIZE(u5500_sdi_pins));\r\ndb5500_add_sdi0(&u5500_sdi0_data);\r\n}
