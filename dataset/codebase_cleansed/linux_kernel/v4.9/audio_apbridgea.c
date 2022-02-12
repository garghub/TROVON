int gb_audio_apbridgea_set_config(struct gb_connection *connection,
__u16 i2s_port, __u32 format, __u32 rate,
__u32 mclk_freq)
{
struct audio_apbridgea_set_config_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_SET_CONFIG;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
req.format = cpu_to_le32(format);
req.rate = cpu_to_le32(rate);
req.mclk_freq = cpu_to_le32(mclk_freq);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_register_cport(struct gb_connection *connection,
__u16 i2s_port, __u16 cportid,
__u8 direction)
{
struct audio_apbridgea_register_cport_request req;
int ret;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_REGISTER_CPORT;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
req.cport = cpu_to_le16(cportid);
req.direction = direction;
ret = gb_pm_runtime_get_sync(connection->bundle);
if (ret)
return ret;
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_unregister_cport(struct gb_connection *connection,
__u16 i2s_port, __u16 cportid,
__u8 direction)
{
struct audio_apbridgea_unregister_cport_request req;
int ret;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_UNREGISTER_CPORT;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
req.cport = cpu_to_le16(cportid);
req.direction = direction;
ret = gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
gb_pm_runtime_put_autosuspend(connection->bundle);
return ret;
}
int gb_audio_apbridgea_set_tx_data_size(struct gb_connection *connection,
__u16 i2s_port, __u16 size)
{
struct audio_apbridgea_set_tx_data_size_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_SET_TX_DATA_SIZE;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
req.size = cpu_to_le16(size);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_prepare_tx(struct gb_connection *connection,
__u16 i2s_port)
{
struct audio_apbridgea_prepare_tx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_PREPARE_TX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_start_tx(struct gb_connection *connection,
__u16 i2s_port, __u64 timestamp)
{
struct audio_apbridgea_start_tx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_START_TX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
req.timestamp = cpu_to_le64(timestamp);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_stop_tx(struct gb_connection *connection, __u16 i2s_port)
{
struct audio_apbridgea_stop_tx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_STOP_TX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_shutdown_tx(struct gb_connection *connection,
__u16 i2s_port)
{
struct audio_apbridgea_shutdown_tx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_SHUTDOWN_TX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_set_rx_data_size(struct gb_connection *connection,
__u16 i2s_port, __u16 size)
{
struct audio_apbridgea_set_rx_data_size_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_SET_RX_DATA_SIZE;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
req.size = cpu_to_le16(size);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_prepare_rx(struct gb_connection *connection,
__u16 i2s_port)
{
struct audio_apbridgea_prepare_rx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_PREPARE_RX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_start_rx(struct gb_connection *connection,
__u16 i2s_port)
{
struct audio_apbridgea_start_rx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_START_RX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_stop_rx(struct gb_connection *connection, __u16 i2s_port)
{
struct audio_apbridgea_stop_rx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_STOP_RX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
int gb_audio_apbridgea_shutdown_rx(struct gb_connection *connection,
__u16 i2s_port)
{
struct audio_apbridgea_shutdown_rx_request req;
req.hdr.type = AUDIO_APBRIDGEA_TYPE_SHUTDOWN_RX;
req.hdr.i2s_port = cpu_to_le16(i2s_port);
return gb_hd_output(connection->hd, &req, sizeof(req),
GB_APB_REQUEST_AUDIO_CONTROL, true);
}
