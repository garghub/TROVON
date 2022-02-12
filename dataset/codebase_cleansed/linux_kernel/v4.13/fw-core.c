struct gb_connection *to_fw_mgmt_connection(struct device *dev)
{
struct gb_fw_core *fw_core = dev_get_drvdata(dev);
return fw_core->mgmt_connection;
}
static int gb_fw_spi_connection_init(struct gb_connection *connection)
{
int ret;
if (!connection)
return 0;
ret = gb_connection_enable(connection);
if (ret)
return ret;
ret = gb_spilib_master_init(connection, &connection->bundle->dev,
spilib_ops);
if (ret) {
gb_connection_disable(connection);
return ret;
}
return 0;
}
static void gb_fw_spi_connection_exit(struct gb_connection *connection)
{
if (!connection)
return;
gb_spilib_master_exit(connection);
gb_connection_disable(connection);
}
static int gb_fw_core_probe(struct gb_bundle *bundle,
const struct greybus_bundle_id *id)
{
struct greybus_descriptor_cport *cport_desc;
struct gb_connection *connection;
struct gb_fw_core *fw_core;
int ret, i;
u16 cport_id;
u8 protocol_id;
fw_core = kzalloc(sizeof(*fw_core), GFP_KERNEL);
if (!fw_core)
return -ENOMEM;
for (i = 0; i < bundle->num_cports; i++) {
cport_desc = &bundle->cport_desc[i];
cport_id = le16_to_cpu(cport_desc->id);
protocol_id = cport_desc->protocol_id;
switch (protocol_id) {
case GREYBUS_PROTOCOL_FW_MANAGEMENT:
if (fw_core->mgmt_connection) {
dev_err(&bundle->dev,
"multiple management CPorts found\n");
ret = -EINVAL;
goto err_destroy_connections;
}
connection = gb_connection_create(bundle, cport_id,
gb_fw_mgmt_request_handler);
if (IS_ERR(connection)) {
ret = PTR_ERR(connection);
dev_err(&bundle->dev,
"failed to create management connection (%d)\n",
ret);
goto err_destroy_connections;
}
fw_core->mgmt_connection = connection;
break;
case GREYBUS_PROTOCOL_FW_DOWNLOAD:
if (fw_core->download_connection) {
dev_err(&bundle->dev,
"multiple download CPorts found\n");
ret = -EINVAL;
goto err_destroy_connections;
}
connection = gb_connection_create(bundle, cport_id,
gb_fw_download_request_handler);
if (IS_ERR(connection)) {
dev_err(&bundle->dev, "failed to create download connection (%ld)\n",
PTR_ERR(connection));
} else {
fw_core->download_connection = connection;
}
break;
case GREYBUS_PROTOCOL_SPI:
if (fw_core->spi_connection) {
dev_err(&bundle->dev,
"multiple SPI CPorts found\n");
ret = -EINVAL;
goto err_destroy_connections;
}
connection = gb_connection_create(bundle, cport_id,
NULL);
if (IS_ERR(connection)) {
dev_err(&bundle->dev, "failed to create SPI connection (%ld)\n",
PTR_ERR(connection));
} else {
fw_core->spi_connection = connection;
}
break;
case GREYBUS_PROTOCOL_AUTHENTICATION:
if (fw_core->cap_connection) {
dev_err(&bundle->dev, "multiple Authentication CPorts found\n");
ret = -EINVAL;
goto err_destroy_connections;
}
connection = gb_connection_create(bundle, cport_id,
NULL);
if (IS_ERR(connection)) {
dev_err(&bundle->dev, "failed to create Authentication connection (%ld)\n",
PTR_ERR(connection));
} else {
fw_core->cap_connection = connection;
}
break;
default:
dev_err(&bundle->dev, "invalid protocol id (0x%02x)\n",
protocol_id);
ret = -EINVAL;
goto err_destroy_connections;
}
}
if (!fw_core->mgmt_connection) {
dev_err(&bundle->dev, "missing management connection\n");
ret = -ENODEV;
goto err_destroy_connections;
}
ret = gb_fw_download_connection_init(fw_core->download_connection);
if (ret) {
dev_err(&bundle->dev, "failed to initialize firmware download connection, disable it (%d)\n",
ret);
gb_connection_destroy(fw_core->download_connection);
fw_core->download_connection = NULL;
}
ret = gb_fw_spi_connection_init(fw_core->spi_connection);
if (ret) {
dev_err(&bundle->dev, "failed to initialize SPI connection, disable it (%d)\n",
ret);
gb_connection_destroy(fw_core->spi_connection);
fw_core->spi_connection = NULL;
}
ret = gb_cap_connection_init(fw_core->cap_connection);
if (ret) {
dev_err(&bundle->dev, "failed to initialize CAP connection, disable it (%d)\n",
ret);
gb_connection_destroy(fw_core->cap_connection);
fw_core->cap_connection = NULL;
}
ret = gb_fw_mgmt_connection_init(fw_core->mgmt_connection);
if (ret) {
dev_err(&bundle->dev, "failed to initialize firmware management connection, disable it (%d)\n",
ret);
goto err_exit_connections;
}
greybus_set_drvdata(bundle, fw_core);
if (!(bundle->intf->quirks & GB_INTERFACE_QUIRK_NO_PM))
gb_pm_runtime_put_autosuspend(bundle);
return 0;
err_exit_connections:
gb_cap_connection_exit(fw_core->cap_connection);
gb_fw_spi_connection_exit(fw_core->spi_connection);
gb_fw_download_connection_exit(fw_core->download_connection);
err_destroy_connections:
gb_connection_destroy(fw_core->mgmt_connection);
gb_connection_destroy(fw_core->cap_connection);
gb_connection_destroy(fw_core->spi_connection);
gb_connection_destroy(fw_core->download_connection);
kfree(fw_core);
return ret;
}
static void gb_fw_core_disconnect(struct gb_bundle *bundle)
{
struct gb_fw_core *fw_core = greybus_get_drvdata(bundle);
int ret;
if (!(bundle->intf->quirks & GB_INTERFACE_QUIRK_NO_PM)) {
ret = gb_pm_runtime_get_sync(bundle);
if (ret)
gb_pm_runtime_get_noresume(bundle);
}
gb_fw_mgmt_connection_exit(fw_core->mgmt_connection);
gb_cap_connection_exit(fw_core->cap_connection);
gb_fw_spi_connection_exit(fw_core->spi_connection);
gb_fw_download_connection_exit(fw_core->download_connection);
gb_connection_destroy(fw_core->mgmt_connection);
gb_connection_destroy(fw_core->cap_connection);
gb_connection_destroy(fw_core->spi_connection);
gb_connection_destroy(fw_core->download_connection);
kfree(fw_core);
}
static int fw_core_init(void)
{
int ret;
ret = fw_mgmt_init();
if (ret) {
pr_err("Failed to initialize fw-mgmt core (%d)\n", ret);
return ret;
}
ret = cap_init();
if (ret) {
pr_err("Failed to initialize component authentication core (%d)\n",
ret);
goto fw_mgmt_exit;
}
ret = greybus_register(&gb_fw_core_driver);
if (ret)
goto cap_exit;
return 0;
cap_exit:
cap_exit();
fw_mgmt_exit:
fw_mgmt_exit();
return ret;
}
static void __exit fw_core_exit(void)
{
greybus_deregister(&gb_fw_core_driver);
cap_exit();
fw_mgmt_exit();
}
