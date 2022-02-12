const struct sensor_drv_data *fimc_is_sensor_get_drvdata(
struct device_node *node)
{
const struct of_device_id *of_id;
of_id = of_match_node(fimc_is_sensor_of_ids, node);
return of_id ? of_id->data : NULL;
}
