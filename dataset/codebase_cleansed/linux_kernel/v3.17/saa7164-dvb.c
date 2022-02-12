static int saa7164_dvb_stop_port(struct saa7164_port *port)
{
struct saa7164_dev *dev = port->dev;
int ret;
ret = saa7164_api_transition_port(port, SAA_DMASTATE_STOP);
if ((ret != SAA_OK) && (ret != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() stop transition failed, ret = 0x%x\n",
__func__, ret);
ret = -EIO;
} else {
dprintk(DBGLVL_DVB, "%s() Stopped\n", __func__);
ret = 0;
}
return ret;
}
static int saa7164_dvb_acquire_port(struct saa7164_port *port)
{
struct saa7164_dev *dev = port->dev;
int ret;
ret = saa7164_api_transition_port(port, SAA_DMASTATE_ACQUIRE);
if ((ret != SAA_OK) && (ret != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() acquire transition failed, ret = 0x%x\n",
__func__, ret);
ret = -EIO;
} else {
dprintk(DBGLVL_DVB, "%s() Acquired\n", __func__);
ret = 0;
}
return ret;
}
static int saa7164_dvb_pause_port(struct saa7164_port *port)
{
struct saa7164_dev *dev = port->dev;
int ret;
ret = saa7164_api_transition_port(port, SAA_DMASTATE_PAUSE);
if ((ret != SAA_OK) && (ret != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() pause transition failed, ret = 0x%x\n",
__func__, ret);
ret = -EIO;
} else {
dprintk(DBGLVL_DVB, "%s() Paused\n", __func__);
ret = 0;
}
return ret;
}
static int saa7164_dvb_stop_streaming(struct saa7164_port *port)
{
struct saa7164_dev *dev = port->dev;
struct saa7164_buffer *buf;
struct list_head *p, *q;
int ret;
dprintk(DBGLVL_DVB, "%s(port=%d)\n", __func__, port->nr);
ret = saa7164_dvb_pause_port(port);
ret = saa7164_dvb_acquire_port(port);
ret = saa7164_dvb_stop_port(port);
mutex_lock(&port->dmaqueue_lock);
list_for_each_safe(p, q, &port->dmaqueue.list) {
buf = list_entry(p, struct saa7164_buffer, list);
buf->flags = SAA7164_BUFFER_FREE;
}
mutex_unlock(&port->dmaqueue_lock);
return ret;
}
static int saa7164_dvb_start_port(struct saa7164_port *port)
{
struct saa7164_dev *dev = port->dev;
int ret = 0, result;
dprintk(DBGLVL_DVB, "%s(port=%d)\n", __func__, port->nr);
saa7164_buffer_cfg_port(port);
result = saa7164_api_transition_port(port, SAA_DMASTATE_ACQUIRE);
if ((result != SAA_OK) && (result != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() acquire transition failed, res = 0x%x\n",
__func__, result);
result = saa7164_api_transition_port(port, SAA_DMASTATE_STOP);
if ((result != SAA_OK) && (result != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() acquire/forced stop transition "
"failed, res = 0x%x\n", __func__, result);
}
ret = -EIO;
goto out;
} else
dprintk(DBGLVL_DVB, "%s() Acquired\n", __func__);
result = saa7164_api_transition_port(port, SAA_DMASTATE_PAUSE);
if ((result != SAA_OK) && (result != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() pause transition failed, res = 0x%x\n",
__func__, result);
result = saa7164_api_transition_port(port, SAA_DMASTATE_STOP);
if ((result != SAA_OK) && (result != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() pause/forced stop transition "
"failed, res = 0x%x\n", __func__, result);
}
ret = -EIO;
goto out;
} else
dprintk(DBGLVL_DVB, "%s() Paused\n", __func__);
result = saa7164_api_transition_port(port, SAA_DMASTATE_RUN);
if ((result != SAA_OK) && (result != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() run transition failed, result = 0x%x\n",
__func__, result);
result = saa7164_api_transition_port(port, SAA_DMASTATE_STOP);
if ((result != SAA_OK) && (result != SAA_ERR_ALREADY_STOPPED)) {
printk(KERN_ERR "%s() run/forced stop transition "
"failed, res = 0x%x\n", __func__, result);
}
ret = -EIO;
} else
dprintk(DBGLVL_DVB, "%s() Running\n", __func__);
out:
return ret;
}
static int saa7164_dvb_start_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct saa7164_port *port = (struct saa7164_port *) demux->priv;
struct saa7164_dvb *dvb = &port->dvb;
struct saa7164_dev *dev = port->dev;
int ret = 0;
dprintk(DBGLVL_DVB, "%s(port=%d)\n", __func__, port->nr);
if (!demux->dmx.frontend)
return -EINVAL;
mutex_lock(&dvb->lock);
if (dvb->feeding++ == 0) {
ret = saa7164_dvb_start_port(port);
}
mutex_unlock(&dvb->lock);
dprintk(DBGLVL_DVB, "%s(port=%d) now feeding = %d\n",
__func__, port->nr, dvb->feeding);
return ret;
}
static int saa7164_dvb_stop_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct saa7164_port *port = (struct saa7164_port *) demux->priv;
struct saa7164_dvb *dvb = &port->dvb;
struct saa7164_dev *dev = port->dev;
int ret = 0;
dprintk(DBGLVL_DVB, "%s(port=%d)\n", __func__, port->nr);
mutex_lock(&dvb->lock);
if (--dvb->feeding == 0) {
ret = saa7164_dvb_stop_streaming(port);
}
mutex_unlock(&dvb->lock);
dprintk(DBGLVL_DVB, "%s(port=%d) now feeding = %d\n",
__func__, port->nr, dvb->feeding);
return ret;
}
static int dvb_register(struct saa7164_port *port)
{
struct saa7164_dvb *dvb = &port->dvb;
struct saa7164_dev *dev = port->dev;
struct saa7164_buffer *buf;
int result, i;
dprintk(DBGLVL_DVB, "%s(port=%d)\n", __func__, port->nr);
if (port->type != SAA7164_MPEG_DVB)
BUG();
if (port->hwcfg.BARLocation == 0) {
result = -ENOMEM;
printk(KERN_ERR "%s: dvb_register_adapter failed "
"(errno = %d), NO PCI configuration\n",
DRIVER_NAME, result);
goto fail_adapter;
}
port->hw_streamingparams.bitspersample = 8;
port->hw_streamingparams.samplesperline = 188;
port->hw_streamingparams.numberoflines =
(SAA7164_TS_NUMBER_OF_LINES * 188) / 188;
port->hw_streamingparams.pitch = 188;
port->hw_streamingparams.linethreshold = 0;
port->hw_streamingparams.pagetablelistvirt = NULL;
port->hw_streamingparams.pagetablelistphys = NULL;
port->hw_streamingparams.numpagetables = 2 +
((SAA7164_TS_NUMBER_OF_LINES * 188) / PAGE_SIZE);
port->hw_streamingparams.numpagetableentries = port->hwcfg.buffercount;
for (i = 0; i < port->hwcfg.buffercount; i++) {
buf = saa7164_buffer_alloc(port,
port->hw_streamingparams.numberoflines *
port->hw_streamingparams.pitch);
if (!buf) {
result = -ENOMEM;
printk(KERN_ERR "%s: dvb_register_adapter failed "
"(errno = %d), unable to allocate buffers\n",
DRIVER_NAME, result);
goto fail_adapter;
}
mutex_lock(&port->dmaqueue_lock);
list_add_tail(&buf->list, &port->dmaqueue.list);
mutex_unlock(&port->dmaqueue_lock);
}
result = dvb_register_adapter(&dvb->adapter, DRIVER_NAME, THIS_MODULE,
&dev->pci->dev, adapter_nr);
if (result < 0) {
printk(KERN_ERR "%s: dvb_register_adapter failed "
"(errno = %d)\n", DRIVER_NAME, result);
goto fail_adapter;
}
dvb->adapter.priv = port;
result = dvb_register_frontend(&dvb->adapter, dvb->frontend);
if (result < 0) {
printk(KERN_ERR "%s: dvb_register_frontend failed "
"(errno = %d)\n", DRIVER_NAME, result);
goto fail_frontend;
}
dvb->demux.dmx.capabilities =
DMX_TS_FILTERING | DMX_SECTION_FILTERING |
DMX_MEMORY_BASED_FILTERING;
dvb->demux.priv = port;
dvb->demux.filternum = 256;
dvb->demux.feednum = 256;
dvb->demux.start_feed = saa7164_dvb_start_feed;
dvb->demux.stop_feed = saa7164_dvb_stop_feed;
result = dvb_dmx_init(&dvb->demux);
if (result < 0) {
printk(KERN_ERR "%s: dvb_dmx_init failed (errno = %d)\n",
DRIVER_NAME, result);
goto fail_dmx;
}
dvb->dmxdev.filternum = 256;
dvb->dmxdev.demux = &dvb->demux.dmx;
dvb->dmxdev.capabilities = 0;
result = dvb_dmxdev_init(&dvb->dmxdev, &dvb->adapter);
if (result < 0) {
printk(KERN_ERR "%s: dvb_dmxdev_init failed (errno = %d)\n",
DRIVER_NAME, result);
goto fail_dmxdev;
}
dvb->fe_hw.source = DMX_FRONTEND_0;
result = dvb->demux.dmx.add_frontend(&dvb->demux.dmx, &dvb->fe_hw);
if (result < 0) {
printk(KERN_ERR "%s: add_frontend failed "
"(DMX_FRONTEND_0, errno = %d)\n", DRIVER_NAME, result);
goto fail_fe_hw;
}
dvb->fe_mem.source = DMX_MEMORY_FE;
result = dvb->demux.dmx.add_frontend(&dvb->demux.dmx, &dvb->fe_mem);
if (result < 0) {
printk(KERN_ERR "%s: add_frontend failed "
"(DMX_MEMORY_FE, errno = %d)\n", DRIVER_NAME, result);
goto fail_fe_mem;
}
result = dvb->demux.dmx.connect_frontend(&dvb->demux.dmx, &dvb->fe_hw);
if (result < 0) {
printk(KERN_ERR "%s: connect_frontend failed (errno = %d)\n",
DRIVER_NAME, result);
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
int saa7164_dvb_unregister(struct saa7164_port *port)
{
struct saa7164_dvb *dvb = &port->dvb;
struct saa7164_dev *dev = port->dev;
struct saa7164_buffer *b;
struct list_head *c, *n;
dprintk(DBGLVL_DVB, "%s()\n", __func__);
if (port->type != SAA7164_MPEG_DVB)
BUG();
mutex_lock(&port->dmaqueue_lock);
list_for_each_safe(c, n, &port->dmaqueue.list) {
b = list_entry(c, struct saa7164_buffer, list);
list_del(c);
saa7164_buffer_dealloc(b);
}
mutex_unlock(&port->dmaqueue_lock);
if (dvb->frontend == NULL)
return 0;
dvb_net_release(&dvb->net);
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_mem);
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_hw);
dvb_dmxdev_release(&dvb->dmxdev);
dvb_dmx_release(&dvb->demux);
dvb_unregister_frontend(dvb->frontend);
dvb_frontend_detach(dvb->frontend);
dvb_unregister_adapter(&dvb->adapter);
return 0;
}
int saa7164_dvb_register(struct saa7164_port *port)
{
struct saa7164_dev *dev = port->dev;
struct saa7164_dvb *dvb = &port->dvb;
struct saa7164_i2c *i2c_bus = NULL;
int ret;
dprintk(DBGLVL_DVB, "%s()\n", __func__);
switch (dev->board) {
case SAA7164_BOARD_HAUPPAUGE_HVR2200:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_2:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_3:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_4:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_5:
i2c_bus = &dev->i2c_bus[port->nr + 1];
switch (port->nr) {
case 0:
port->dvb.frontend = dvb_attach(tda10048_attach,
&hauppauge_hvr2200_1_config,
&i2c_bus->i2c_adap);
if (port->dvb.frontend != NULL) {
dvb_attach(tda18271_attach, port->dvb.frontend,
0xc0 >> 1, &i2c_bus->i2c_adap,
&hauppauge_hvr22x0_tuner_config);
}
break;
case 1:
port->dvb.frontend = dvb_attach(tda10048_attach,
&hauppauge_hvr2200_2_config,
&i2c_bus->i2c_adap);
if (port->dvb.frontend != NULL) {
dvb_attach(tda18271_attach, port->dvb.frontend,
0xc0 >> 1, &i2c_bus->i2c_adap,
&hauppauge_hvr22x0s_tuner_config);
}
break;
}
break;
case SAA7164_BOARD_HAUPPAUGE_HVR2250:
case SAA7164_BOARD_HAUPPAUGE_HVR2250_2:
case SAA7164_BOARD_HAUPPAUGE_HVR2250_3:
i2c_bus = &dev->i2c_bus[port->nr + 1];
port->dvb.frontend = dvb_attach(s5h1411_attach,
&hauppauge_s5h1411_config,
&i2c_bus->i2c_adap);
if (port->dvb.frontend != NULL) {
if (port->nr == 0) {
dvb_attach(tda18271_attach, port->dvb.frontend,
0xc0 >> 1, &i2c_bus->i2c_adap,
&hauppauge_hvr22x0_tuner_config);
} else {
dvb_attach(tda18271_attach, port->dvb.frontend,
0xc0 >> 1, &i2c_bus->i2c_adap,
&hauppauge_hvr22x0s_tuner_config);
}
}
break;
default:
printk(KERN_ERR "%s: The frontend isn't supported\n",
dev->name);
break;
}
if (NULL == dvb->frontend) {
printk(KERN_ERR "%s() Frontend initialization failed\n",
__func__);
return -1;
}
ret = dvb_register(port);
if (ret < 0) {
if (dvb->frontend->ops.release)
dvb->frontend->ops.release(dvb->frontend);
return ret;
}
return 0;
}
