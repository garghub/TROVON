static int rmi_f55_detect(struct rmi_function *fn)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
struct rmi_driver_data *drv_data = dev_get_drvdata(&rmi_dev->dev);
struct f55_data *f55;
int error;
f55 = dev_get_drvdata(&fn->dev);
error = rmi_read_block(fn->rmi_dev, fn->fd.query_base_addr,
&f55->qry, sizeof(f55->qry));
if (error) {
dev_err(&fn->dev, "%s: Failed to query F55 properties\n",
__func__);
return error;
}
f55->num_rx_electrodes = f55->qry[F55_NUM_RX_OFFSET];
f55->num_tx_electrodes = f55->qry[F55_NUM_TX_OFFSET];
f55->cfg_num_rx_electrodes = f55->num_rx_electrodes;
f55->cfg_num_tx_electrodes = f55->num_rx_electrodes;
drv_data->num_rx_electrodes = f55->cfg_num_rx_electrodes;
drv_data->num_tx_electrodes = f55->cfg_num_rx_electrodes;
if (f55->qry[F55_PHYS_CHAR_OFFSET] & F55_CAP_SENSOR_ASSIGN) {
int i, total;
u8 buf[256];
error = rmi_read_block(fn->rmi_dev,
fn->fd.control_base_addr + 1,
buf, f55->num_rx_electrodes);
if (!error) {
total = 0;
for (i = 0; i < f55->num_rx_electrodes; i++) {
if (buf[i] != 0xff)
total++;
}
f55->cfg_num_rx_electrodes = total;
drv_data->num_rx_electrodes = total;
}
error = rmi_read_block(fn->rmi_dev,
fn->fd.control_base_addr + 2,
buf, f55->num_tx_electrodes);
if (!error) {
total = 0;
for (i = 0; i < f55->num_tx_electrodes; i++) {
if (buf[i] != 0xff)
total++;
}
f55->cfg_num_tx_electrodes = total;
drv_data->num_tx_electrodes = total;
}
}
rmi_dbg(RMI_DEBUG_FN, &fn->dev, "F55 num_rx_electrodes: %d (raw %d)\n",
f55->cfg_num_rx_electrodes, f55->num_rx_electrodes);
rmi_dbg(RMI_DEBUG_FN, &fn->dev, "F55 num_tx_electrodes: %d (raw %d)\n",
f55->cfg_num_tx_electrodes, f55->num_tx_electrodes);
return 0;
}
static int rmi_f55_probe(struct rmi_function *fn)
{
struct f55_data *f55;
f55 = devm_kzalloc(&fn->dev, sizeof(struct f55_data), GFP_KERNEL);
if (!f55)
return -ENOMEM;
f55->fn = fn;
dev_set_drvdata(&fn->dev, f55);
return rmi_f55_detect(fn);
}
