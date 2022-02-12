static int __init mlxplat_dmi_default_matched(const struct dmi_system_id *dmi)
{
int i;
for (i = 0; i < ARRAY_SIZE(mlxplat_mux_data); i++) {
mlxplat_mux_data[i].values = mlxplat_default_channels[i];
mlxplat_mux_data[i].n_values =
ARRAY_SIZE(mlxplat_default_channels[i]);
}
return 1;
}
static int __init mlxplat_dmi_msn21xx_matched(const struct dmi_system_id *dmi)
{
int i;
for (i = 0; i < ARRAY_SIZE(mlxplat_mux_data); i++) {
mlxplat_mux_data[i].values = mlxplat_msn21xx_channels;
mlxplat_mux_data[i].n_values =
ARRAY_SIZE(mlxplat_msn21xx_channels);
}
return 1;
}
static int __init mlxplat_init(void)
{
struct mlxplat_priv *priv;
int i, err;
if (!dmi_check_system(mlxplat_dmi_table))
return -ENODEV;
mlxplat_dev = platform_device_register_simple(MLX_PLAT_DEVICE_NAME, -1,
mlxplat_lpc_resources,
ARRAY_SIZE(mlxplat_lpc_resources));
if (IS_ERR(mlxplat_dev))
return PTR_ERR(mlxplat_dev);
priv = devm_kzalloc(&mlxplat_dev->dev, sizeof(struct mlxplat_priv),
GFP_KERNEL);
if (!priv) {
err = -ENOMEM;
goto fail_alloc;
}
platform_set_drvdata(mlxplat_dev, priv);
priv->pdev_i2c = platform_device_register_simple("i2c_mlxcpld", -1,
NULL, 0);
if (IS_ERR(priv->pdev_i2c)) {
err = PTR_ERR(priv->pdev_i2c);
goto fail_alloc;
};
for (i = 0; i < ARRAY_SIZE(mlxplat_mux_data); i++) {
priv->pdev_mux[i] = platform_device_register_resndata(
&mlxplat_dev->dev,
"i2c-mux-reg", i, NULL,
0, &mlxplat_mux_data[i],
sizeof(mlxplat_mux_data[i]));
if (IS_ERR(priv->pdev_mux[i])) {
err = PTR_ERR(priv->pdev_mux[i]);
goto fail_platform_mux_register;
}
}
return 0;
fail_platform_mux_register:
for (i--; i > 0 ; i--)
platform_device_unregister(priv->pdev_mux[i]);
platform_device_unregister(priv->pdev_i2c);
fail_alloc:
platform_device_unregister(mlxplat_dev);
return err;
}
static void __exit mlxplat_exit(void)
{
struct mlxplat_priv *priv = platform_get_drvdata(mlxplat_dev);
int i;
for (i = ARRAY_SIZE(mlxplat_mux_data) - 1; i >= 0 ; i--)
platform_device_unregister(priv->pdev_mux[i]);
platform_device_unregister(priv->pdev_i2c);
platform_device_unregister(mlxplat_dev);
}
