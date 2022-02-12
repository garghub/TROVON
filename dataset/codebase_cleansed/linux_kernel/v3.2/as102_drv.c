static void as102_stop_stream(struct as102_dev_t *dev)
{
struct as102_bus_adapter_t *bus_adap;
if (dev != NULL)
bus_adap = &dev->bus_adap;
else
return;
if (bus_adap->ops->stop_stream != NULL)
bus_adap->ops->stop_stream(dev);
if (ts_auto_disable) {
if (mutex_lock_interruptible(&dev->bus_adap.lock))
return;
if (as10x_cmd_stop_streaming(bus_adap) < 0)
dprintk(debug, "as10x_cmd_stop_streaming failed\n");
mutex_unlock(&dev->bus_adap.lock);
}
}
static int as102_start_stream(struct as102_dev_t *dev)
{
struct as102_bus_adapter_t *bus_adap;
int ret = -EFAULT;
if (dev != NULL)
bus_adap = &dev->bus_adap;
else
return ret;
if (bus_adap->ops->start_stream != NULL)
ret = bus_adap->ops->start_stream(dev);
if (ts_auto_disable) {
if (mutex_lock_interruptible(&dev->bus_adap.lock))
return -EFAULT;
ret = as10x_cmd_start_streaming(bus_adap);
mutex_unlock(&dev->bus_adap.lock);
}
return ret;
}
static int as10x_pid_filter(struct as102_dev_t *dev,
int index, u16 pid, int onoff) {
struct as102_bus_adapter_t *bus_adap = &dev->bus_adap;
int ret = -EFAULT;
ENTER();
if (mutex_lock_interruptible(&dev->bus_adap.lock)) {
dprintk(debug, "mutex_lock_interruptible(lock) failed !\n");
return -EBUSY;
}
switch (onoff) {
case 0:
ret = as10x_cmd_del_PID_filter(bus_adap, (uint16_t) pid);
dprintk(debug, "DEL_PID_FILTER([%02d] 0x%04x) ret = %d\n",
index, pid, ret);
break;
case 1:
{
struct as10x_ts_filter filter;
filter.type = TS_PID_TYPE_TS;
filter.idx = 0xFF;
filter.pid = pid;
ret = as10x_cmd_add_PID_filter(bus_adap, &filter);
dprintk(debug, "ADD_PID_FILTER([%02d -> %02d], 0x%04x) ret = %d\n",
index, filter.idx, filter.pid, ret);
break;
}
}
mutex_unlock(&dev->bus_adap.lock);
LEAVE();
return ret;
}
static int as102_dvb_dmx_start_feed(struct dvb_demux_feed *dvbdmxfeed)
{
int ret = 0;
struct dvb_demux *demux = dvbdmxfeed->demux;
struct as102_dev_t *as102_dev = demux->priv;
ENTER();
if (mutex_lock_interruptible(&as102_dev->sem))
return -ERESTARTSYS;
if (pid_filtering) {
as10x_pid_filter(as102_dev,
dvbdmxfeed->index, dvbdmxfeed->pid, 1);
}
if (as102_dev->streaming++ == 0)
ret = as102_start_stream(as102_dev);
mutex_unlock(&as102_dev->sem);
LEAVE();
return ret;
}
static int as102_dvb_dmx_stop_feed(struct dvb_demux_feed *dvbdmxfeed)
{
struct dvb_demux *demux = dvbdmxfeed->demux;
struct as102_dev_t *as102_dev = demux->priv;
ENTER();
if (mutex_lock_interruptible(&as102_dev->sem))
return -ERESTARTSYS;
if (--as102_dev->streaming == 0)
as102_stop_stream(as102_dev);
if (pid_filtering) {
as10x_pid_filter(as102_dev,
dvbdmxfeed->index, dvbdmxfeed->pid, 0);
}
mutex_unlock(&as102_dev->sem);
LEAVE();
return 0;
}
int as102_dvb_register(struct as102_dev_t *as102_dev)
{
int ret = 0;
ENTER();
ret = dvb_register_adapter(&as102_dev->dvb_adap,
as102_dev->name,
THIS_MODULE,
#if defined(CONFIG_AS102_USB)
&as102_dev->bus_adap.usb_dev->dev
#elif defined(CONFIG_AS102_SPI)
&as102_dev->bus_adap.spi_dev->dev
#else
#error >>> dvb_register_adapter <<<
#endif
#ifdef DVB_DEFINE_MOD_OPT_ADAPTER_NR
, adapter_nr
#endif
);
if (ret < 0) {
err("%s: dvb_register_adapter() failed (errno = %d)",
__func__, ret);
goto failed;
}
as102_dev->dvb_dmx.priv = as102_dev;
as102_dev->dvb_dmx.filternum = pid_filtering ? 16 : 256;
as102_dev->dvb_dmx.feednum = 256;
as102_dev->dvb_dmx.start_feed = as102_dvb_dmx_start_feed;
as102_dev->dvb_dmx.stop_feed = as102_dvb_dmx_stop_feed;
as102_dev->dvb_dmx.dmx.capabilities = DMX_TS_FILTERING |
DMX_SECTION_FILTERING;
as102_dev->dvb_dmxdev.filternum = as102_dev->dvb_dmx.filternum;
as102_dev->dvb_dmxdev.demux = &as102_dev->dvb_dmx.dmx;
as102_dev->dvb_dmxdev.capabilities = 0;
ret = dvb_dmx_init(&as102_dev->dvb_dmx);
if (ret < 0) {
err("%s: dvb_dmx_init() failed (errno = %d)", __func__, ret);
goto failed;
}
ret = dvb_dmxdev_init(&as102_dev->dvb_dmxdev, &as102_dev->dvb_adap);
if (ret < 0) {
err("%s: dvb_dmxdev_init() failed (errno = %d)", __func__,
ret);
goto failed;
}
ret = as102_dvb_register_fe(as102_dev, &as102_dev->dvb_fe);
if (ret < 0) {
err("%s: as102_dvb_register_frontend() failed (errno = %d)",
__func__, ret);
goto failed;
}
mutex_init(&as102_dev->bus_adap.lock);
mutex_init(&as102_dev->sem);
#if defined(CONFIG_FW_LOADER) || defined(CONFIG_FW_LOADER_MODULE)
if (fw_upload)
try_then_request_module(as102_fw_upload(&as102_dev->bus_adap),
"firmware_class");
#endif
failed:
LEAVE();
return ret;
}
void as102_dvb_unregister(struct as102_dev_t *as102_dev)
{
ENTER();
as102_dvb_unregister_fe(&as102_dev->dvb_fe);
dvb_dmxdev_release(&as102_dev->dvb_dmxdev);
dvb_dmx_release(&as102_dev->dvb_dmx);
dvb_unregister_adapter(&as102_dev->dvb_adap);
LEAVE();
}
static int __init as102_driver_init(void)
{
int ret = 0;
ENTER();
#if defined(CONFIG_AS102_USB)
ret = usb_register(&as102_usb_driver);
if (ret)
err("usb_register failed (ret = %d)", ret);
#endif
#if defined(CONFIG_AS102_SPI)
ret = spi_register_driver(&as102_spi_driver);
if (ret)
printk(KERN_ERR "spi_register failed (ret = %d)", ret);
#endif
LEAVE();
return ret;
}
static void __exit as102_driver_exit(void)
{
ENTER();
#if defined(CONFIG_AS102_USB)
usb_deregister(&as102_usb_driver);
#endif
#if defined(CONFIG_AS102_SPI)
spi_unregister_driver(&as102_spi_driver);
#endif
LEAVE();
}
