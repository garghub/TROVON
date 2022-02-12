int __init harmony_regulator_init(void)\r\n{\r\ni2c_register_board_info(3, harmony_regulators, 1);\r\nreturn 0;\r\n}
