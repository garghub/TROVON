int opal_get_sensor_data(u32 sensor_hndl, u32 *sensor_data)
{
int ret, token;
struct opal_msg msg;
__be32 data;
token = opal_async_get_token_interruptible();
if (token < 0) {
pr_err("%s: Couldn't get the token, returning\n", __func__);
ret = token;
goto out;
}
mutex_lock(&opal_sensor_mutex);
ret = opal_sensor_read(sensor_hndl, token, &data);
if (ret != OPAL_ASYNC_COMPLETION)
goto out_token;
ret = opal_async_wait_response(token, &msg);
if (ret) {
pr_err("%s: Failed to wait for the async response, %d\n",
__func__, ret);
goto out_token;
}
*sensor_data = be32_to_cpu(data);
ret = be64_to_cpu(msg.params[1]);
out_token:
mutex_unlock(&opal_sensor_mutex);
opal_async_release_token(token);
out:
return ret;
}
static __init int opal_sensor_init(void)
{
struct platform_device *pdev;
struct device_node *sensor;
sensor = of_find_node_by_path("/ibm,opal/sensors");
if (!sensor) {
pr_err("Opal node 'sensors' not found\n");
return -ENODEV;
}
pdev = of_platform_device_create(sensor, "opal-sensor", NULL);
of_node_put(sensor);
return PTR_ERR_OR_ZERO(pdev);
}
