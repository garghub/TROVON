static inline void print_err_status(struct cx231xx *dev, int packet, int status)
{
char *errmsg = "Unknown";
switch (status) {
case -ENOENT:
errmsg = "unlinked synchronuously";
break;
case -ECONNRESET:
errmsg = "unlinked asynchronuously";
break;
case -ENOSR:
errmsg = "Buffer error (overrun)";
break;
case -EPIPE:
errmsg = "Stalled (device not responding)";
break;
case -EOVERFLOW:
errmsg = "Babble (bad cable?)";
break;
case -EPROTO:
errmsg = "Bit-stuff error (bad cable?)";
break;
case -EILSEQ:
errmsg = "CRC/Timeout (could be anything)";
break;
case -ETIME:
errmsg = "Device does not respond";
break;
}
if (packet < 0) {
dev_dbg(dev->dev,
"URB status %d [%s].\n", status, errmsg);
} else {
dev_dbg(dev->dev,
"URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static inline int dvb_isoc_copy(struct cx231xx *dev, struct urb *urb)
{
int i;
if (!dev)
return 0;
if (dev->state & DEV_DISCONNECTED)
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
for (i = 0; i < urb->number_of_packets; i++) {
int status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
dvb_dmx_swfilter(&dev->dvb->demux,
urb->transfer_buffer +
urb->iso_frame_desc[i].offset,
urb->iso_frame_desc[i].actual_length);
}
return 0;
}
static inline int dvb_bulk_copy(struct cx231xx *dev, struct urb *urb)
{
if (!dev)
return 0;
if (dev->state & DEV_DISCONNECTED)
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
dvb_dmx_swfilter(&dev->dvb->demux,
urb->transfer_buffer, urb->actual_length);
return 0;
}
static int start_streaming(struct cx231xx_dvb *dvb)
{
int rc;
struct cx231xx *dev = dvb->adapter.priv;
if (dev->USE_ISO) {
dev_dbg(dev->dev, "DVB transfer mode is ISO.\n");
cx231xx_set_alt_setting(dev, INDEX_TS1, 4);
rc = cx231xx_set_mode(dev, CX231XX_DIGITAL_MODE);
if (rc < 0)
return rc;
dev->mode_tv = 1;
return cx231xx_init_isoc(dev, CX231XX_DVB_MAX_PACKETS,
CX231XX_DVB_NUM_BUFS,
dev->ts1_mode.max_pkt_size,
dvb_isoc_copy);
} else {
dev_dbg(dev->dev, "DVB transfer mode is BULK.\n");
cx231xx_set_alt_setting(dev, INDEX_TS1, 0);
rc = cx231xx_set_mode(dev, CX231XX_DIGITAL_MODE);
if (rc < 0)
return rc;
dev->mode_tv = 1;
return cx231xx_init_bulk(dev, CX231XX_DVB_MAX_PACKETS,
CX231XX_DVB_NUM_BUFS,
dev->ts1_mode.max_pkt_size,
dvb_bulk_copy);
}
}
static int stop_streaming(struct cx231xx_dvb *dvb)
{
struct cx231xx *dev = dvb->adapter.priv;
if (dev->USE_ISO)
cx231xx_uninit_isoc(dev);
else
cx231xx_uninit_bulk(dev);
cx231xx_set_mode(dev, CX231XX_SUSPEND);
return 0;
}
static int start_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct cx231xx_dvb *dvb = demux->priv;
int rc, ret;
if (!demux->dmx.frontend)
return -EINVAL;
mutex_lock(&dvb->lock);
dvb->nfeeds++;
rc = dvb->nfeeds;
if (dvb->nfeeds == 1) {
ret = start_streaming(dvb);
if (ret < 0)
rc = ret;
}
mutex_unlock(&dvb->lock);
return rc;
}
static int stop_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct cx231xx_dvb *dvb = demux->priv;
int err = 0;
mutex_lock(&dvb->lock);
dvb->nfeeds--;
if (0 == dvb->nfeeds)
err = stop_streaming(dvb);
mutex_unlock(&dvb->lock);
return err;
}
static int cx231xx_dvb_bus_ctrl(struct dvb_frontend *fe, int acquire)
{
struct cx231xx *dev = fe->dvb->priv;
if (acquire)
return cx231xx_set_mode(dev, CX231XX_DIGITAL_MODE);
else
return cx231xx_set_mode(dev, CX231XX_SUSPEND);
}
int cx231xx_set_analog_freq(struct cx231xx *dev, u32 freq)
{
if ((dev->dvb != NULL) && (dev->dvb->frontend != NULL)) {
struct dvb_tuner_ops *dops = &dev->dvb->frontend->ops.tuner_ops;
if (dops->set_analog_params != NULL) {
struct analog_parameters params;
params.frequency = freq;
params.std = dev->norm;
params.mode = 0;
dops->set_analog_params(dev->dvb->frontend, &params);
}
}
return 0;
}
int cx231xx_reset_analog_tuner(struct cx231xx *dev)
{
int status = 0;
if ((dev->dvb != NULL) && (dev->dvb->frontend != NULL)) {
struct dvb_tuner_ops *dops = &dev->dvb->frontend->ops.tuner_ops;
if (dops->init != NULL && !dev->xc_fw_load_done) {
dev_dbg(dev->dev,
"Reloading firmware for XC5000\n");
status = dops->init(dev->dvb->frontend);
if (status == 0) {
dev->xc_fw_load_done = 1;
dev_dbg(dev->dev,
"XC5000 firmware download completed\n");
} else {
dev->xc_fw_load_done = 0;
dev_dbg(dev->dev,
"XC5000 firmware download failed !!!\n");
}
}
}
return status;
}
static int register_dvb(struct cx231xx_dvb *dvb,
struct module *module,
struct cx231xx *dev, struct device *device)
{
int result;
mutex_init(&dvb->lock);
result = dvb_register_adapter(&dvb->adapter, dev->name, module, device,
adapter_nr);
if (result < 0) {
dev_warn(dev->dev,
"%s: dvb_register_adapter failed (errno = %d)\n",
dev->name, result);
goto fail_adapter;
}
dvb->frontend->ops.ts_bus_ctrl = cx231xx_dvb_bus_ctrl;
dvb->adapter.priv = dev;
result = dvb_register_frontend(&dvb->adapter, dvb->frontend);
if (result < 0) {
dev_warn(dev->dev,
"%s: dvb_register_frontend failed (errno = %d)\n",
dev->name, result);
goto fail_frontend;
}
dvb->demux.dmx.capabilities =
DMX_TS_FILTERING | DMX_SECTION_FILTERING |
DMX_MEMORY_BASED_FILTERING;
dvb->demux.priv = dvb;
dvb->demux.filternum = 256;
dvb->demux.feednum = 256;
dvb->demux.start_feed = start_feed;
dvb->demux.stop_feed = stop_feed;
result = dvb_dmx_init(&dvb->demux);
if (result < 0) {
dev_warn(dev->dev,
"%s: dvb_dmx_init failed (errno = %d)\n",
dev->name, result);
goto fail_dmx;
}
dvb->dmxdev.filternum = 256;
dvb->dmxdev.demux = &dvb->demux.dmx;
dvb->dmxdev.capabilities = 0;
result = dvb_dmxdev_init(&dvb->dmxdev, &dvb->adapter);
if (result < 0) {
dev_warn(dev->dev,
"%s: dvb_dmxdev_init failed (errno = %d)\n",
dev->name, result);
goto fail_dmxdev;
}
dvb->fe_hw.source = DMX_FRONTEND_0;
result = dvb->demux.dmx.add_frontend(&dvb->demux.dmx, &dvb->fe_hw);
if (result < 0) {
dev_warn(dev->dev,
"%s: add_frontend failed (DMX_FRONTEND_0, errno = %d)\n",
dev->name, result);
goto fail_fe_hw;
}
dvb->fe_mem.source = DMX_MEMORY_FE;
result = dvb->demux.dmx.add_frontend(&dvb->demux.dmx, &dvb->fe_mem);
if (result < 0) {
dev_warn(dev->dev,
"%s: add_frontend failed (DMX_MEMORY_FE, errno = %d)\n",
dev->name, result);
goto fail_fe_mem;
}
result = dvb->demux.dmx.connect_frontend(&dvb->demux.dmx, &dvb->fe_hw);
if (result < 0) {
dev_warn(dev->dev,
"%s: connect_frontend failed (errno = %d)\n",
dev->name, result);
goto fail_fe_conn;
}
dvb_net_init(&dvb->adapter, &dvb->net, &dvb->demux.dmx);
return 0;
fail_fe_conn:
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_mem);
fail_fe_mem:
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_hw);
fail_fe_hw:
dvb_dmxdev_release(&dvb->dmxdev);
fail_dmxdev:
dvb_dmx_release(&dvb->demux);
fail_dmx:
dvb_unregister_frontend(dvb->frontend);
fail_frontend:
dvb_frontend_detach(dvb->frontend);
dvb_unregister_adapter(&dvb->adapter);
fail_adapter:
return result;
}
static void unregister_dvb(struct cx231xx_dvb *dvb)
{
struct i2c_client *client;
dvb_net_release(&dvb->net);
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_mem);
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_hw);
dvb_dmxdev_release(&dvb->dmxdev);
dvb_dmx_release(&dvb->demux);
client = dvb->i2c_client_tuner;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
dvb_unregister_frontend(dvb->frontend);
dvb_frontend_detach(dvb->frontend);
dvb_unregister_adapter(&dvb->adapter);
}
static int dvb_init(struct cx231xx *dev)
{
int result = 0;
struct cx231xx_dvb *dvb;
struct i2c_adapter *tuner_i2c;
struct i2c_adapter *demod_i2c;
if (!dev->board.has_dvb) {
return 0;
}
dvb = kzalloc(sizeof(struct cx231xx_dvb), GFP_KERNEL);
if (dvb == NULL) {
dev_info(dev->dev,
"cx231xx_dvb: memory allocation failed\n");
return -ENOMEM;
}
dev->dvb = dvb;
dev->cx231xx_set_analog_freq = cx231xx_set_analog_freq;
dev->cx231xx_reset_analog_tuner = cx231xx_reset_analog_tuner;
tuner_i2c = cx231xx_get_i2c_adap(dev, dev->board.tuner_i2c_master);
demod_i2c = cx231xx_get_i2c_adap(dev, dev->board.demod_i2c_master);
mutex_lock(&dev->lock);
cx231xx_set_mode(dev, CX231XX_DIGITAL_MODE);
cx231xx_demod_reset(dev);
switch (dev->model) {
case CX231XX_BOARD_CNXT_CARRAERA:
case CX231XX_BOARD_CNXT_RDE_250:
dev->dvb->frontend = dvb_attach(s5h1432_attach,
&dvico_s5h1432_config,
demod_i2c);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach s5h1432 front end\n");
result = -EINVAL;
goto out_free;
}
dvb->frontend->callback = cx231xx_tuner_callback;
if (!dvb_attach(xc5000_attach, dev->dvb->frontend,
tuner_i2c,
&cnxt_rde250_tunerconfig)) {
result = -EINVAL;
goto out_free;
}
break;
case CX231XX_BOARD_CNXT_SHELBY:
case CX231XX_BOARD_CNXT_RDU_250:
dev->dvb->frontend = dvb_attach(s5h1411_attach,
&xc5000_s5h1411_config,
demod_i2c);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach s5h1411 front end\n");
result = -EINVAL;
goto out_free;
}
dvb->frontend->callback = cx231xx_tuner_callback;
if (!dvb_attach(xc5000_attach, dev->dvb->frontend,
tuner_i2c,
&cnxt_rdu250_tunerconfig)) {
result = -EINVAL;
goto out_free;
}
break;
case CX231XX_BOARD_CNXT_RDE_253S:
dev->dvb->frontend = dvb_attach(s5h1432_attach,
&dvico_s5h1432_config,
demod_i2c);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach s5h1432 front end\n");
result = -EINVAL;
goto out_free;
}
dvb->frontend->callback = cx231xx_tuner_callback;
if (!dvb_attach(tda18271_attach, dev->dvb->frontend,
0x60, tuner_i2c,
&cnxt_rde253s_tunerconfig)) {
result = -EINVAL;
goto out_free;
}
break;
case CX231XX_BOARD_CNXT_RDU_253S:
case CX231XX_BOARD_KWORLD_UB445_USB_HYBRID:
dev->dvb->frontend = dvb_attach(s5h1411_attach,
&tda18271_s5h1411_config,
demod_i2c);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach s5h1411 front end\n");
result = -EINVAL;
goto out_free;
}
dvb->frontend->callback = cx231xx_tuner_callback;
if (!dvb_attach(tda18271_attach, dev->dvb->frontend,
0x60, tuner_i2c,
&cnxt_rde253s_tunerconfig)) {
result = -EINVAL;
goto out_free;
}
break;
case CX231XX_BOARD_HAUPPAUGE_EXETER:
dev_info(dev->dev,
"%s: looking for tuner / demod on i2c bus: %d\n",
__func__, i2c_adapter_id(tuner_i2c));
dev->dvb->frontend = dvb_attach(lgdt3305_attach,
&hcw_lgdt3305_config,
tuner_i2c);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach LG3305 front end\n");
result = -EINVAL;
goto out_free;
}
dvb->frontend->callback = cx231xx_tuner_callback;
dvb_attach(tda18271_attach, dev->dvb->frontend,
0x60, tuner_i2c,
&hcw_tda18271_config);
break;
case CX231XX_BOARD_HAUPPAUGE_930C_HD_1113xx:
dev->dvb->frontend = dvb_attach(si2165_attach,
&hauppauge_930C_HD_1113xx_si2165_config,
tuner_i2c
);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach SI2165 front end\n");
result = -EINVAL;
goto out_free;
}
dev->dvb->frontend->ops.i2c_gate_ctrl = NULL;
dvb->frontend->callback = cx231xx_tuner_callback;
dvb_attach(tda18271_attach, dev->dvb->frontend,
0x60,
tuner_i2c,
&hcw_tda18271_config);
dev->cx231xx_reset_analog_tuner = NULL;
break;
case CX231XX_BOARD_HAUPPAUGE_930C_HD_1114xx:
{
struct i2c_client *client;
struct i2c_board_info info;
struct si2157_config si2157_config;
memset(&info, 0, sizeof(struct i2c_board_info));
dev->dvb->frontend = dvb_attach(si2165_attach,
&pctv_quatro_stick_1114xx_si2165_config,
tuner_i2c
);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach SI2165 front end\n");
result = -EINVAL;
goto out_free;
}
dev->dvb->frontend->ops.i2c_gate_ctrl = NULL;
dvb->frontend->callback = cx231xx_tuner_callback;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = dev->dvb->frontend;
si2157_config.inversion = true;
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module("si2157");
client = i2c_new_device(
tuner_i2c,
&info);
if (client == NULL || client->dev.driver == NULL) {
dvb_frontend_detach(dev->dvb->frontend);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dvb_frontend_detach(dev->dvb->frontend);
result = -ENODEV;
goto out_free;
}
dev->cx231xx_reset_analog_tuner = NULL;
dev->dvb->i2c_client_tuner = client;
break;
}
case CX231XX_BOARD_PV_PLAYTV_USB_HYBRID:
case CX231XX_BOARD_KWORLD_UB430_USB_HYBRID:
dev_info(dev->dev,
"%s: looking for demod on i2c bus: %d\n",
__func__, i2c_adapter_id(tuner_i2c));
dev->dvb->frontend = dvb_attach(mb86a20s_attach,
&pv_mb86a20s_config,
demod_i2c);
if (dev->dvb->frontend == NULL) {
dev_err(dev->dev,
"Failed to attach mb86a20s demod\n");
result = -EINVAL;
goto out_free;
}
dvb->frontend->callback = cx231xx_tuner_callback;
dvb_attach(tda18271_attach, dev->dvb->frontend,
0x60, tuner_i2c,
&pv_tda18271_config);
break;
default:
dev_err(dev->dev,
"%s/2: The frontend of your DVB/ATSC card isn't supported yet\n",
dev->name);
break;
}
if (NULL == dvb->frontend) {
dev_err(dev->dev,
"%s/2: frontend initialization failed\n", dev->name);
result = -EINVAL;
goto out_free;
}
result = register_dvb(dvb, THIS_MODULE, dev, dev->dev);
if (result < 0)
goto out_free;
dev_info(dev->dev, "Successfully loaded cx231xx-dvb\n");
ret:
cx231xx_set_mode(dev, CX231XX_SUSPEND);
mutex_unlock(&dev->lock);
return result;
out_free:
kfree(dvb);
dev->dvb = NULL;
goto ret;
}
static int dvb_fini(struct cx231xx *dev)
{
if (!dev->board.has_dvb) {
return 0;
}
if (dev->dvb) {
unregister_dvb(dev->dvb);
dev->dvb = NULL;
}
return 0;
}
static int __init cx231xx_dvb_register(void)
{
return cx231xx_register_extension(&dvb_ops);
}
static void __exit cx231xx_dvb_unregister(void)
{
cx231xx_unregister_extension(&dvb_ops);
}
