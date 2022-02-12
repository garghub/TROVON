int __init harmony_regulator_init(void)
{
regulator_register_always_on(0, "vdd_sys",
NULL, 0, 5000000);
if (machine_is_harmony()) {
i2c_register_board_info(3, harmony_regulators, 1);
} else {
struct device_node *np;
struct i2c_adapter *adapter;
np = of_find_node_by_path("/i2c@7000d000");
if (np == NULL) {
pr_err("Could not find device_node for DVC I2C\n");
return -ENODEV;
}
adapter = of_find_i2c_adapter_by_node(np);
if (!adapter) {
pr_err("Could not find i2c_adapter for DVC I2C\n");
return -ENODEV;
}
i2c_new_device(adapter, harmony_regulators);
}
return 0;
}
