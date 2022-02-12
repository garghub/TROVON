static int __init mlxsw_minimal_module_init(void)
{
int err;
err = mlxsw_core_driver_register(&mlxsw_minimal_driver);
if (err)
return err;
err = mlxsw_i2c_driver_register(&mlxsw_minimal_i2c_driver);
if (err)
goto err_i2c_driver_register;
return 0;
err_i2c_driver_register:
mlxsw_core_driver_unregister(&mlxsw_minimal_driver);
return err;
}
static void __exit mlxsw_minimal_module_exit(void)
{
mlxsw_i2c_driver_unregister(&mlxsw_minimal_i2c_driver);
mlxsw_core_driver_unregister(&mlxsw_minimal_driver);
}
