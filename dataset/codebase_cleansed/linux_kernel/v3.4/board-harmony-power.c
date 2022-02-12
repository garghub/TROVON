int __init harmony_regulator_init(void)
{
i2c_register_board_info(3, harmony_regulators, 1);
return 0;
}
