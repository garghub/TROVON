static int yuan_mpc718_mt352_reqfw(struct cx18_stream *stream,
const struct firmware **fw)
{
struct cx18 *cx = stream->cx;
const char *fn = FWFILE;
int ret;
ret = request_firmware(fw, fn, &cx->pci_dev->dev);
if (ret)
CX18_ERR("Unable to open firmware file %s\n", fn);
else {
size_t sz = (*fw)->size;
if (sz < 2 || sz > 64 || (sz % 2) != 0) {
CX18_ERR("Firmware %s has a bad size: %lu bytes\n",
fn, (unsigned long) sz);
ret = -EILSEQ;
release_firmware(*fw);
*fw = NULL;
}
}
if (ret) {
CX18_ERR("The MPC718 board variant with the MT352 DVB-Tdemodualtor will not work without it\n");
CX18_ERR("Run 'linux/Documentation/dvb/get_dvb_firmware mpc718' if you need the firmware\n");
}
return ret;
}
static int yuan_mpc718_mt352_init(struct dvb_frontend *fe)
{
struct cx18_dvb *dvb = container_of(fe->dvb,
struct cx18_dvb, dvb_adapter);
struct cx18_stream *stream = dvb->stream;
const struct firmware *fw = NULL;
int ret;
int i;
u8 buf[3];
ret = yuan_mpc718_mt352_reqfw(stream, &fw);
if (ret)
return ret;
for (i = 0; i < fw->size; i += 2) {
buf[0] = fw->data[i];
switch (buf[0]) {
case TRL_NOMINAL_RATE_0:
break;
case TRL_NOMINAL_RATE_1:
buf[1] = 0x72;
buf[2] = 0x49;
mt352_write(fe, buf, 3);
break;
case INPUT_FREQ_0:
break;
case INPUT_FREQ_1:
buf[1] = 0x31;
buf[2] = 0xc0;
mt352_write(fe, buf, 3);
break;
default:
buf[1] = fw->data[i+1];
mt352_write(fe, buf, 2);
break;
}
}
buf[0] = (u8) TUNER_GO;
buf[1] = 0x01;
mt352_write(fe, buf, 2);
release_firmware(fw);
return 0;
}
static int cx18_dvb_start_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct cx18_stream *stream = (struct cx18_stream *) demux->priv;
struct cx18 *cx;
int ret;
u32 v;
if (!stream)
return -EINVAL;
cx = stream->cx;
CX18_DEBUG_INFO("Start feed: pid = 0x%x index = %d\n",
feed->pid, feed->index);
mutex_lock(&cx->serialize_lock);
ret = cx18_init_on_first_open(cx);
mutex_unlock(&cx->serialize_lock);
if (ret) {
CX18_ERR("Failed to initialize firmware starting DVB feed\n");
return ret;
}
ret = -EINVAL;
switch (cx->card->type) {
case CX18_CARD_HVR_1600_ESMT:
case CX18_CARD_HVR_1600_SAMSUNG:
case CX18_CARD_HVR_1600_S5H1411:
v = cx18_read_reg(cx, CX18_REG_DMUX_NUM_PORT_0_CONTROL);
v |= 0x00400000;
v |= 0x00002000;
v |= 0x00010000;
v |= 0x00020000;
v |= 0x000c0000;
cx18_write_reg(cx, v, CX18_REG_DMUX_NUM_PORT_0_CONTROL);
break;
case CX18_CARD_LEADTEK_DVR3100H:
case CX18_CARD_YUAN_MPC718:
case CX18_CARD_GOTVIEW_PCI_DVD3:
default:
break;
}
if (!demux->dmx.frontend)
return -EINVAL;
mutex_lock(&stream->dvb->feedlock);
if (stream->dvb->feeding++ == 0) {
CX18_DEBUG_INFO("Starting Transport DMA\n");
mutex_lock(&cx->serialize_lock);
set_bit(CX18_F_S_STREAMING, &stream->s_flags);
ret = cx18_start_v4l2_encode_stream(stream);
if (ret < 0) {
CX18_DEBUG_INFO("Failed to start Transport DMA\n");
stream->dvb->feeding--;
if (stream->dvb->feeding == 0)
clear_bit(CX18_F_S_STREAMING, &stream->s_flags);
}
mutex_unlock(&cx->serialize_lock);
} else
ret = 0;
mutex_unlock(&stream->dvb->feedlock);
return ret;
}
static int cx18_dvb_stop_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct cx18_stream *stream = (struct cx18_stream *)demux->priv;
struct cx18 *cx;
int ret = -EINVAL;
if (stream) {
cx = stream->cx;
CX18_DEBUG_INFO("Stop feed: pid = 0x%x index = %d\n",
feed->pid, feed->index);
mutex_lock(&stream->dvb->feedlock);
if (--stream->dvb->feeding == 0) {
CX18_DEBUG_INFO("Stopping Transport DMA\n");
mutex_lock(&cx->serialize_lock);
ret = cx18_stop_v4l2_encode_stream(stream, 0);
mutex_unlock(&cx->serialize_lock);
} else
ret = 0;
mutex_unlock(&stream->dvb->feedlock);
}
return ret;
}
int cx18_dvb_register(struct cx18_stream *stream)
{
struct cx18 *cx = stream->cx;
struct cx18_dvb *dvb = stream->dvb;
struct dvb_adapter *dvb_adapter;
struct dvb_demux *dvbdemux;
struct dmx_demux *dmx;
int ret;
if (!dvb)
return -EINVAL;
dvb->enabled = 0;
dvb->stream = stream;
ret = dvb_register_adapter(&dvb->dvb_adapter,
CX18_DRIVER_NAME,
THIS_MODULE, &cx->pci_dev->dev, adapter_nr);
if (ret < 0)
goto err_out;
dvb_adapter = &dvb->dvb_adapter;
dvbdemux = &dvb->demux;
dvbdemux->priv = (void *)stream;
dvbdemux->filternum = 256;
dvbdemux->feednum = 256;
dvbdemux->start_feed = cx18_dvb_start_feed;
dvbdemux->stop_feed = cx18_dvb_stop_feed;
dvbdemux->dmx.capabilities = (DMX_TS_FILTERING |
DMX_SECTION_FILTERING | DMX_MEMORY_BASED_FILTERING);
ret = dvb_dmx_init(dvbdemux);
if (ret < 0)
goto err_dvb_unregister_adapter;
dmx = &dvbdemux->dmx;
dvb->hw_frontend.source = DMX_FRONTEND_0;
dvb->mem_frontend.source = DMX_MEMORY_FE;
dvb->dmxdev.filternum = 256;
dvb->dmxdev.demux = dmx;
ret = dvb_dmxdev_init(&dvb->dmxdev, dvb_adapter);
if (ret < 0)
goto err_dvb_dmx_release;
ret = dmx->add_frontend(dmx, &dvb->hw_frontend);
if (ret < 0)
goto err_dvb_dmxdev_release;
ret = dmx->add_frontend(dmx, &dvb->mem_frontend);
if (ret < 0)
goto err_remove_hw_frontend;
ret = dmx->connect_frontend(dmx, &dvb->hw_frontend);
if (ret < 0)
goto err_remove_mem_frontend;
ret = dvb_register(stream);
if (ret < 0)
goto err_disconnect_frontend;
dvb_net_init(dvb_adapter, &dvb->dvbnet, dmx);
CX18_INFO("DVB Frontend registered\n");
CX18_INFO("Registered DVB adapter%d for %s (%d x %d.%02d kB)\n",
stream->dvb->dvb_adapter.num, stream->name,
stream->buffers, stream->buf_size/1024,
(stream->buf_size * 100 / 1024) % 100);
mutex_init(&dvb->feedlock);
dvb->enabled = 1;
return ret;
err_disconnect_frontend:
dmx->disconnect_frontend(dmx);
err_remove_mem_frontend:
dmx->remove_frontend(dmx, &dvb->mem_frontend);
err_remove_hw_frontend:
dmx->remove_frontend(dmx, &dvb->hw_frontend);
err_dvb_dmxdev_release:
dvb_dmxdev_release(&dvb->dmxdev);
err_dvb_dmx_release:
dvb_dmx_release(dvbdemux);
err_dvb_unregister_adapter:
dvb_unregister_adapter(dvb_adapter);
err_out:
return ret;
}
void cx18_dvb_unregister(struct cx18_stream *stream)
{
struct cx18 *cx = stream->cx;
struct cx18_dvb *dvb = stream->dvb;
struct dvb_adapter *dvb_adapter;
struct dvb_demux *dvbdemux;
struct dmx_demux *dmx;
CX18_INFO("unregister DVB\n");
if (dvb == NULL || !dvb->enabled)
return;
dvb_adapter = &dvb->dvb_adapter;
dvbdemux = &dvb->demux;
dmx = &dvbdemux->dmx;
dmx->close(dmx);
dvb_net_release(&dvb->dvbnet);
dmx->remove_frontend(dmx, &dvb->mem_frontend);
dmx->remove_frontend(dmx, &dvb->hw_frontend);
dvb_dmxdev_release(&dvb->dmxdev);
dvb_dmx_release(dvbdemux);
dvb_unregister_frontend(dvb->fe);
dvb_frontend_detach(dvb->fe);
dvb_unregister_adapter(dvb_adapter);
}
static int dvb_register(struct cx18_stream *stream)
{
struct cx18_dvb *dvb = stream->dvb;
struct cx18 *cx = stream->cx;
int ret = 0;
switch (cx->card->type) {
case CX18_CARD_HVR_1600_ESMT:
case CX18_CARD_HVR_1600_SAMSUNG:
dvb->fe = dvb_attach(s5h1409_attach,
&hauppauge_hvr1600_config,
&cx->i2c_adap[0]);
if (dvb->fe != NULL) {
dvb_attach(mxl5005s_attach, dvb->fe,
&cx->i2c_adap[0],
&hauppauge_hvr1600_tuner);
ret = 0;
}
break;
case CX18_CARD_HVR_1600_S5H1411:
dvb->fe = dvb_attach(s5h1411_attach,
&hcw_s5h1411_config,
&cx->i2c_adap[0]);
if (dvb->fe != NULL)
dvb_attach(tda18271_attach, dvb->fe,
0x60, &cx->i2c_adap[0],
&hauppauge_tda18271_config);
break;
case CX18_CARD_LEADTEK_DVR3100H:
dvb->fe = dvb_attach(zl10353_attach,
&leadtek_dvr3100h_demod,
&cx->i2c_adap[1]);
if (dvb->fe != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &cx->i2c_adap[1],
.i2c_addr = 0xc2 >> 1,
.ctrl = NULL,
};
static struct xc2028_ctrl ctrl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_ZARLINK456,
.type = XC2028_AUTO,
};
fe = dvb_attach(xc2028_attach, dvb->fe, &cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctrl);
}
break;
case CX18_CARD_YUAN_MPC718:
dvb->fe = dvb_attach(mt352_attach,
&yuan_mpc718_mt352_demod,
&cx->i2c_adap[1]);
if (dvb->fe == NULL)
dvb->fe = dvb_attach(zl10353_attach,
&yuan_mpc718_zl10353_demod,
&cx->i2c_adap[1]);
if (dvb->fe != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &cx->i2c_adap[1],
.i2c_addr = 0xc2 >> 1,
.ctrl = NULL,
};
static struct xc2028_ctrl ctrl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_ZARLINK456,
.type = XC2028_AUTO,
};
fe = dvb_attach(xc2028_attach, dvb->fe, &cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctrl);
}
break;
case CX18_CARD_GOTVIEW_PCI_DVD3:
dvb->fe = dvb_attach(zl10353_attach,
&gotview_dvd3_zl10353_demod,
&cx->i2c_adap[1]);
if (dvb->fe != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &cx->i2c_adap[1],
.i2c_addr = 0xc2 >> 1,
.ctrl = NULL,
};
static struct xc2028_ctrl ctrl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_ZARLINK456,
.type = XC2028_AUTO,
};
fe = dvb_attach(xc2028_attach, dvb->fe, &cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctrl);
}
break;
default:
break;
}
if (dvb->fe == NULL) {
CX18_ERR("frontend initialization failed\n");
return -1;
}
dvb->fe->callback = cx18_reset_tuner_gpio;
ret = dvb_register_frontend(&dvb->dvb_adapter, dvb->fe);
if (ret < 0) {
if (dvb->fe->ops.release)
dvb->fe->ops.release(dvb->fe);
return ret;
}
cx18_write_reg_expect(cx,
(CX18_DMUX_CLK_MASK << 16) | CX18_DMUX_CLK_MASK,
CX18_CLOCK_ENABLE2,
CX18_DMUX_CLK_MASK,
(CX18_DMUX_CLK_MASK << 16) | CX18_DMUX_CLK_MASK);
return ret;
}
