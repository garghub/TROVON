static void dm1105_card_list(struct pci_dev *pci)
{
int i;
if (0 == pci->subsystem_vendor &&
0 == pci->subsystem_device) {
printk(KERN_ERR
"dm1105: Your board has no valid PCI Subsystem ID\n"
"dm1105: and thus can't be autodetected\n"
"dm1105: Please pass card=<n> insmod option to\n"
"dm1105: workaround that. Redirect complaints to\n"
"dm1105: the vendor of the TV card. Best regards,\n"
"dm1105: -- tux\n");
} else {
printk(KERN_ERR
"dm1105: Your board isn't known (yet) to the driver.\n"
"dm1105: You can try to pick one of the existing\n"
"dm1105: card configs via card=<n> insmod option.\n"
"dm1105: Updating to the latest version might help\n"
"dm1105: as well.\n");
}
printk(KERN_ERR "Here is a list of valid choices for the card=<n> "
"insmod option:\n");
for (i = 0; i < ARRAY_SIZE(dm1105_boards); i++)
printk(KERN_ERR "dm1105: card=%d -> %s\n",
i, dm1105_boards[i].name);
}
static void dm1105_gpio_set(struct dm1105_dev *dev, u32 mask)
{
if (mask & 0xfffc0000)
printk(KERN_ERR "%s: Only 18 GPIO's are allowed\n", __func__);
if (mask & 0x0003ffff)
dm_setl(DM1105_GPIOVAL, mask & 0x0003ffff);
}
static void dm1105_gpio_clear(struct dm1105_dev *dev, u32 mask)
{
if (mask & 0xfffc0000)
printk(KERN_ERR "%s: Only 18 GPIO's are allowed\n", __func__);
if (mask & 0x0003ffff)
dm_clearl(DM1105_GPIOVAL, mask & 0x0003ffff);
}
static void dm1105_gpio_andor(struct dm1105_dev *dev, u32 mask, u32 val)
{
if (mask & 0xfffc0000)
printk(KERN_ERR "%s: Only 18 GPIO's are allowed\n", __func__);
if (mask & 0x0003ffff)
dm_andorl(DM1105_GPIOVAL, mask & 0x0003ffff, val);
}
static u32 dm1105_gpio_get(struct dm1105_dev *dev, u32 mask)
{
if (mask & 0xfffc0000)
printk(KERN_ERR "%s: Only 18 GPIO's are allowed\n", __func__);
if (mask & 0x0003ffff)
return dm_readl(DM1105_GPIOVAL) & mask & 0x0003ffff;
return 0;
}
static void dm1105_gpio_enable(struct dm1105_dev *dev, u32 mask, int asoutput)
{
if (mask & 0xfffc0000)
printk(KERN_ERR "%s: Only 18 GPIO's are allowed\n", __func__);
if ((mask & 0x0003ffff) && asoutput)
dm_clearl(DM1105_GPIOCTR, mask & 0x0003ffff);
else if ((mask & 0x0003ffff) && !asoutput)
dm_setl(DM1105_GPIOCTR, mask & 0x0003ffff);
}
static void dm1105_setline(struct dm1105_dev *dev, u32 line, int state)
{
if (state)
dm1105_gpio_enable(dev, line, 0);
else {
dm1105_gpio_enable(dev, line, 1);
dm1105_gpio_clear(dev, line);
}
}
static void dm1105_setsda(void *data, int state)
{
struct dm1105_dev *dev = data;
dm1105_setline(dev, dm1105_boards[dev->boardnr].gpio_sda, state);
}
static void dm1105_setscl(void *data, int state)
{
struct dm1105_dev *dev = data;
dm1105_setline(dev, dm1105_boards[dev->boardnr].gpio_scl, state);
}
static int dm1105_getsda(void *data)
{
struct dm1105_dev *dev = data;
return dm1105_gpio_get(dev, dm1105_boards[dev->boardnr].gpio_sda)
? 1 : 0;
}
static int dm1105_getscl(void *data)
{
struct dm1105_dev *dev = data;
return dm1105_gpio_get(dev, dm1105_boards[dev->boardnr].gpio_scl)
? 1 : 0;
}
static int dm1105_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, int num)
{
struct dm1105_dev *dev ;
int addr, rc, i, j, k, len, byte, data;
u8 status;
dev = i2c_adap->algo_data;
for (i = 0; i < num; i++) {
dm_writeb(DM1105_I2CCTR, 0x00);
if (msgs[i].flags & I2C_M_RD) {
addr = msgs[i].addr << 1;
addr |= 1;
dm_writeb(DM1105_I2CDAT, addr);
for (byte = 0; byte < msgs[i].len; byte++)
dm_writeb(DM1105_I2CDAT + byte + 1, 0);
dm_writeb(DM1105_I2CCTR, 0x81 + msgs[i].len);
for (j = 0; j < 55; j++) {
mdelay(10);
status = dm_readb(DM1105_I2CSTS);
if ((status & 0xc0) == 0x40)
break;
}
if (j >= 55)
return -1;
for (byte = 0; byte < msgs[i].len; byte++) {
rc = dm_readb(DM1105_I2CDAT + byte + 1);
if (rc < 0)
goto err;
msgs[i].buf[byte] = rc;
}
} else if ((msgs[i].buf[0] == 0xf7) && (msgs[i].addr == 0x55)) {
len = msgs[i].len - 1;
k = 1;
do {
dm_writeb(DM1105_I2CDAT, msgs[i].addr << 1);
dm_writeb(DM1105_I2CDAT + 1, 0xf7);
for (byte = 0; byte < (len > 48 ? 48 : len); byte++) {
data = msgs[i].buf[k + byte];
dm_writeb(DM1105_I2CDAT + byte + 2, data);
}
dm_writeb(DM1105_I2CCTR, 0x82 + (len > 48 ? 48 : len));
for (j = 0; j < 25; j++) {
mdelay(10);
status = dm_readb(DM1105_I2CSTS);
if ((status & 0xc0) == 0x40)
break;
}
if (j >= 25)
return -1;
k += 48;
len -= 48;
} while (len > 0);
} else {
dm_writeb(DM1105_I2CDAT, msgs[i].addr << 1);
for (byte = 0; byte < msgs[i].len; byte++) {
data = msgs[i].buf[byte];
dm_writeb(DM1105_I2CDAT + byte + 1, data);
}
dm_writeb(DM1105_I2CCTR, 0x81 + msgs[i].len);
for (j = 0; j < 25; j++) {
mdelay(10);
status = dm_readb(DM1105_I2CSTS);
if ((status & 0xc0) == 0x40)
break;
}
if (j >= 25)
return -1;
}
}
return num;
err:
return rc;
}
static u32 functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C;
}
static inline struct dm1105_dev *feed_to_dm1105_dev(struct dvb_demux_feed *feed)
{
return container_of(feed->demux, struct dm1105_dev, demux);
}
static inline struct dm1105_dev *frontend_to_dm1105_dev(struct dvb_frontend *fe)
{
return container_of(fe->dvb, struct dm1105_dev, dvb_adapter);
}
static int dm1105_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
struct dm1105_dev *dev = frontend_to_dm1105_dev(fe);
dm1105_gpio_enable(dev, dm1105_boards[dev->boardnr].lnb.mask, 1);
if (voltage == SEC_VOLTAGE_18)
dm1105_gpio_andor(dev,
dm1105_boards[dev->boardnr].lnb.mask,
dm1105_boards[dev->boardnr].lnb.v18);
else if (voltage == SEC_VOLTAGE_13)
dm1105_gpio_andor(dev,
dm1105_boards[dev->boardnr].lnb.mask,
dm1105_boards[dev->boardnr].lnb.v13);
else
dm1105_gpio_andor(dev,
dm1105_boards[dev->boardnr].lnb.mask,
dm1105_boards[dev->boardnr].lnb.off);
return 0;
}
static void dm1105_set_dma_addr(struct dm1105_dev *dev)
{
dm_writel(DM1105_STADR, cpu_to_le32(dev->dma_addr));
}
static int dm1105_dma_map(struct dm1105_dev *dev)
{
dev->ts_buf = pci_alloc_consistent(dev->pdev,
6 * DM1105_DMA_BYTES,
&dev->dma_addr);
return !dev->ts_buf;
}
static void dm1105_dma_unmap(struct dm1105_dev *dev)
{
pci_free_consistent(dev->pdev,
6 * DM1105_DMA_BYTES,
dev->ts_buf,
dev->dma_addr);
}
static void dm1105_enable_irqs(struct dm1105_dev *dev)
{
dm_writeb(DM1105_INTMAK, INTMAK_ALLMASK);
dm_writeb(DM1105_CR, 1);
}
static void dm1105_disable_irqs(struct dm1105_dev *dev)
{
dm_writeb(DM1105_INTMAK, INTMAK_IRM);
dm_writeb(DM1105_CR, 0);
}
static int dm1105_start_feed(struct dvb_demux_feed *f)
{
struct dm1105_dev *dev = feed_to_dm1105_dev(f);
if (dev->full_ts_users++ == 0)
dm1105_enable_irqs(dev);
return 0;
}
static int dm1105_stop_feed(struct dvb_demux_feed *f)
{
struct dm1105_dev *dev = feed_to_dm1105_dev(f);
if (--dev->full_ts_users == 0)
dm1105_disable_irqs(dev);
return 0;
}
static void dm1105_emit_key(struct work_struct *work)
{
struct infrared *ir = container_of(work, struct infrared, work);
u32 ircom = ir->ir_command;
u8 data;
if (ir_debug)
printk(KERN_INFO "%s: received byte 0x%04x\n", __func__, ircom);
data = (ircom >> 8) & 0x7f;
rc_keydown(ir->dev, data, 0);
}
static void dm1105_dmx_buffer(struct work_struct *work)
{
struct dm1105_dev *dev = container_of(work, struct dm1105_dev, work);
unsigned int nbpackets;
u32 oldwrp = dev->wrp;
u32 nextwrp = dev->nextwrp;
if (!((dev->ts_buf[oldwrp] == 0x47) &&
(dev->ts_buf[oldwrp + 188] == 0x47) &&
(dev->ts_buf[oldwrp + 188 * 2] == 0x47))) {
dev->PacketErrorCount++;
if ((dev->PacketErrorCount >= 2) &&
(dev->dmarst == 0)) {
dm_writeb(DM1105_RST, 1);
dev->wrp = 0;
dev->PacketErrorCount = 0;
dev->dmarst = 0;
return;
}
}
if (nextwrp < oldwrp) {
memcpy(dev->ts_buf + dev->buffer_size, dev->ts_buf, nextwrp);
nbpackets = ((dev->buffer_size - oldwrp) + nextwrp) / 188;
} else
nbpackets = (nextwrp - oldwrp) / 188;
dev->wrp = nextwrp;
dvb_dmx_swfilter_packets(&dev->demux, &dev->ts_buf[oldwrp], nbpackets);
}
static irqreturn_t dm1105_irq(int irq, void *dev_id)
{
struct dm1105_dev *dev = dev_id;
unsigned int intsts = dm_readb(DM1105_INTSTS);
dm_writeb(DM1105_INTSTS, intsts);
switch (intsts) {
case INTSTS_TSIRQ:
case (INTSTS_TSIRQ | INTSTS_IR):
dev->nextwrp = dm_readl(DM1105_WRP) - dm_readl(DM1105_STADR);
queue_work(dev->wq, &dev->work);
break;
case INTSTS_IR:
dev->ir.ir_command = dm_readl(DM1105_IRCODE);
schedule_work(&dev->ir.work);
break;
}
return IRQ_HANDLED;
}
static int dm1105_ir_init(struct dm1105_dev *dm1105)
{
struct rc_dev *dev;
int err = -ENOMEM;
dev = rc_allocate_device();
if (!dev)
return -ENOMEM;
snprintf(dm1105->ir.input_phys, sizeof(dm1105->ir.input_phys),
"pci-%s/ir0", pci_name(dm1105->pdev));
dev->driver_name = MODULE_NAME;
dev->map_name = RC_MAP_DM1105_NEC;
dev->driver_type = RC_DRIVER_SCANCODE;
dev->input_name = "DVB on-card IR receiver";
dev->input_phys = dm1105->ir.input_phys;
dev->input_id.bustype = BUS_PCI;
dev->input_id.version = 1;
if (dm1105->pdev->subsystem_vendor) {
dev->input_id.vendor = dm1105->pdev->subsystem_vendor;
dev->input_id.product = dm1105->pdev->subsystem_device;
} else {
dev->input_id.vendor = dm1105->pdev->vendor;
dev->input_id.product = dm1105->pdev->device;
}
dev->dev.parent = &dm1105->pdev->dev;
INIT_WORK(&dm1105->ir.work, dm1105_emit_key);
err = rc_register_device(dev);
if (err < 0) {
rc_free_device(dev);
return err;
}
dm1105->ir.dev = dev;
return 0;
}
static void dm1105_ir_exit(struct dm1105_dev *dm1105)
{
rc_unregister_device(dm1105->ir.dev);
}
static int dm1105_hw_init(struct dm1105_dev *dev)
{
dm1105_disable_irqs(dev);
dm_writeb(DM1105_HOST_CTR, 0);
dm_writeb(DM1105_DTALENTH, 188);
dm_writew(DM1105_TSCTR, 0xc10a);
dm1105_dma_map(dev);
dm1105_set_dma_addr(dev);
dm_writel(DM1105_RLEN, 5 * DM1105_DMA_BYTES);
dm_writeb(DM1105_INTCNT, 47);
dm_writeb(DM1105_IRCTR, (DM1105_IR_EN | DM1105_SYS_CHK));
dm_writeb(DM1105_IRMODE, 0);
dm_writew(DM1105_SYSTEMCODE, 0);
return 0;
}
static void dm1105_hw_exit(struct dm1105_dev *dev)
{
dm1105_disable_irqs(dev);
dm_writeb(DM1105_IRCTR, 0);
dm_writeb(DM1105_INTMAK, INTMAK_NONEMASK);
dm1105_dma_unmap(dev);
}
static int frontend_init(struct dm1105_dev *dev)
{
int ret;
switch (dev->boardnr) {
case DM1105_BOARD_UNBRANDED_I2C_ON_GPIO:
dm1105_gpio_enable(dev, GPIO15, 1);
dm1105_gpio_clear(dev, GPIO15);
msleep(100);
dm1105_gpio_set(dev, GPIO15);
msleep(200);
dev->fe = dvb_attach(
stv0299_attach, &sharp_z0194a_config,
&dev->i2c_bb_adap);
if (dev->fe) {
dev->fe->ops.set_voltage = dm1105_set_voltage;
dvb_attach(dvb_pll_attach, dev->fe, 0x60,
&dev->i2c_bb_adap, DVB_PLL_OPERA1);
break;
}
dev->fe = dvb_attach(
stv0288_attach, &earda_config,
&dev->i2c_bb_adap);
if (dev->fe) {
dev->fe->ops.set_voltage = dm1105_set_voltage;
dvb_attach(stb6000_attach, dev->fe, 0x61,
&dev->i2c_bb_adap);
break;
}
dev->fe = dvb_attach(
si21xx_attach, &serit_config,
&dev->i2c_bb_adap);
if (dev->fe)
dev->fe->ops.set_voltage = dm1105_set_voltage;
break;
case DM1105_BOARD_DVBWORLD_2004:
dev->fe = dvb_attach(
cx24116_attach, &serit_sp2633_config,
&dev->i2c_adap);
if (dev->fe) {
dev->fe->ops.set_voltage = dm1105_set_voltage;
break;
}
dev->fe = dvb_attach(
ds3000_attach, &dvbworld_ds3000_config,
&dev->i2c_adap);
if (dev->fe) {
dvb_attach(ts2020_attach, dev->fe,
&dvbworld_ts2020_config, &dev->i2c_adap);
dev->fe->ops.set_voltage = dm1105_set_voltage;
}
break;
case DM1105_BOARD_DVBWORLD_2002:
case DM1105_BOARD_AXESS_DM05:
default:
dev->fe = dvb_attach(
stv0299_attach, &sharp_z0194a_config,
&dev->i2c_adap);
if (dev->fe) {
dev->fe->ops.set_voltage = dm1105_set_voltage;
dvb_attach(dvb_pll_attach, dev->fe, 0x60,
&dev->i2c_adap, DVB_PLL_OPERA1);
break;
}
dev->fe = dvb_attach(
stv0288_attach, &earda_config,
&dev->i2c_adap);
if (dev->fe) {
dev->fe->ops.set_voltage = dm1105_set_voltage;
dvb_attach(stb6000_attach, dev->fe, 0x61,
&dev->i2c_adap);
break;
}
dev->fe = dvb_attach(
si21xx_attach, &serit_config,
&dev->i2c_adap);
if (dev->fe)
dev->fe->ops.set_voltage = dm1105_set_voltage;
}
if (!dev->fe) {
dev_err(&dev->pdev->dev, "could not attach frontend\n");
return -ENODEV;
}
ret = dvb_register_frontend(&dev->dvb_adapter, dev->fe);
if (ret < 0) {
if (dev->fe->ops.release)
dev->fe->ops.release(dev->fe);
dev->fe = NULL;
return ret;
}
return 0;
}
static void dm1105_read_mac(struct dm1105_dev *dev, u8 *mac)
{
static u8 command[1] = { 0x28 };
struct i2c_msg msg[] = {
{
.addr = IIC_24C01_addr >> 1,
.flags = 0,
.buf = command,
.len = 1
}, {
.addr = IIC_24C01_addr >> 1,
.flags = I2C_M_RD,
.buf = mac,
.len = 6
},
};
dm1105_i2c_xfer(&dev->i2c_adap, msg , 2);
dev_info(&dev->pdev->dev, "MAC %pM\n", mac);
}
static int dm1105_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct dm1105_dev *dev;
struct dvb_adapter *dvb_adapter;
struct dvb_demux *dvbdemux;
struct dmx_demux *dmx;
int ret = -ENOMEM;
int i;
dev = kzalloc(sizeof(struct dm1105_dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->nr = dm1105_devcount;
dev->boardnr = UNSET;
if (card[dev->nr] < ARRAY_SIZE(dm1105_boards))
dev->boardnr = card[dev->nr];
for (i = 0; UNSET == dev->boardnr &&
i < ARRAY_SIZE(dm1105_subids); i++)
if (pdev->subsystem_vendor ==
dm1105_subids[i].subvendor &&
pdev->subsystem_device ==
dm1105_subids[i].subdevice)
dev->boardnr = dm1105_subids[i].card;
if (UNSET == dev->boardnr) {
dev->boardnr = DM1105_BOARD_UNKNOWN;
dm1105_card_list(pdev);
}
dm1105_devcount++;
dev->pdev = pdev;
dev->buffer_size = 5 * DM1105_DMA_BYTES;
dev->PacketErrorCount = 0;
dev->dmarst = 0;
ret = pci_enable_device(pdev);
if (ret < 0)
goto err_kfree;
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (ret < 0)
goto err_pci_disable_device;
pci_set_master(pdev);
ret = pci_request_regions(pdev, DRIVER_NAME);
if (ret < 0)
goto err_pci_disable_device;
dev->io_mem = pci_iomap(pdev, 0, pci_resource_len(pdev, 0));
if (!dev->io_mem) {
ret = -EIO;
goto err_pci_release_regions;
}
spin_lock_init(&dev->lock);
pci_set_drvdata(pdev, dev);
ret = dm1105_hw_init(dev);
if (ret < 0)
goto err_pci_iounmap;
i2c_set_adapdata(&dev->i2c_adap, dev);
strcpy(dev->i2c_adap.name, DRIVER_NAME);
dev->i2c_adap.owner = THIS_MODULE;
dev->i2c_adap.dev.parent = &pdev->dev;
dev->i2c_adap.algo = &dm1105_algo;
dev->i2c_adap.algo_data = dev;
ret = i2c_add_adapter(&dev->i2c_adap);
if (ret < 0)
goto err_dm1105_hw_exit;
i2c_set_adapdata(&dev->i2c_bb_adap, dev);
strcpy(dev->i2c_bb_adap.name, DM1105_I2C_GPIO_NAME);
dev->i2c_bb_adap.owner = THIS_MODULE;
dev->i2c_bb_adap.dev.parent = &pdev->dev;
dev->i2c_bb_adap.algo_data = &dev->i2c_bit;
dev->i2c_bit.data = dev;
dev->i2c_bit.setsda = dm1105_setsda;
dev->i2c_bit.setscl = dm1105_setscl;
dev->i2c_bit.getsda = dm1105_getsda;
dev->i2c_bit.getscl = dm1105_getscl;
dev->i2c_bit.udelay = 10;
dev->i2c_bit.timeout = 10;
dm1105_setsda(dev, 1);
dm1105_setscl(dev, 1);
ret = i2c_bit_add_bus(&dev->i2c_bb_adap);
if (ret < 0)
goto err_i2c_del_adapter;
ret = dvb_register_adapter(&dev->dvb_adapter, DRIVER_NAME,
THIS_MODULE, &pdev->dev, adapter_nr);
if (ret < 0)
goto err_i2c_del_adapters;
dvb_adapter = &dev->dvb_adapter;
dm1105_read_mac(dev, dvb_adapter->proposed_mac);
dvbdemux = &dev->demux;
dvbdemux->filternum = 256;
dvbdemux->feednum = 256;
dvbdemux->start_feed = dm1105_start_feed;
dvbdemux->stop_feed = dm1105_stop_feed;
dvbdemux->dmx.capabilities = (DMX_TS_FILTERING |
DMX_SECTION_FILTERING | DMX_MEMORY_BASED_FILTERING);
ret = dvb_dmx_init(dvbdemux);
if (ret < 0)
goto err_dvb_unregister_adapter;
dmx = &dvbdemux->dmx;
dev->dmxdev.filternum = 256;
dev->dmxdev.demux = dmx;
dev->dmxdev.capabilities = 0;
ret = dvb_dmxdev_init(&dev->dmxdev, dvb_adapter);
if (ret < 0)
goto err_dvb_dmx_release;
dev->hw_frontend.source = DMX_FRONTEND_0;
ret = dmx->add_frontend(dmx, &dev->hw_frontend);
if (ret < 0)
goto err_dvb_dmxdev_release;
dev->mem_frontend.source = DMX_MEMORY_FE;
ret = dmx->add_frontend(dmx, &dev->mem_frontend);
if (ret < 0)
goto err_remove_hw_frontend;
ret = dmx->connect_frontend(dmx, &dev->hw_frontend);
if (ret < 0)
goto err_remove_mem_frontend;
ret = dvb_net_init(dvb_adapter, &dev->dvbnet, dmx);
if (ret < 0)
goto err_disconnect_frontend;
ret = frontend_init(dev);
if (ret < 0)
goto err_dvb_net;
dm1105_ir_init(dev);
INIT_WORK(&dev->work, dm1105_dmx_buffer);
sprintf(dev->wqn, "%s/%d", dvb_adapter->name, dvb_adapter->num);
dev->wq = create_singlethread_workqueue(dev->wqn);
if (!dev->wq) {
ret = -ENOMEM;
goto err_dvb_net;
}
ret = request_irq(pdev->irq, dm1105_irq, IRQF_SHARED,
DRIVER_NAME, dev);
if (ret < 0)
goto err_workqueue;
return 0;
err_workqueue:
destroy_workqueue(dev->wq);
err_dvb_net:
dvb_net_release(&dev->dvbnet);
err_disconnect_frontend:
dmx->disconnect_frontend(dmx);
err_remove_mem_frontend:
dmx->remove_frontend(dmx, &dev->mem_frontend);
err_remove_hw_frontend:
dmx->remove_frontend(dmx, &dev->hw_frontend);
err_dvb_dmxdev_release:
dvb_dmxdev_release(&dev->dmxdev);
err_dvb_dmx_release:
dvb_dmx_release(dvbdemux);
err_dvb_unregister_adapter:
dvb_unregister_adapter(dvb_adapter);
err_i2c_del_adapters:
i2c_del_adapter(&dev->i2c_bb_adap);
err_i2c_del_adapter:
i2c_del_adapter(&dev->i2c_adap);
err_dm1105_hw_exit:
dm1105_hw_exit(dev);
err_pci_iounmap:
pci_iounmap(pdev, dev->io_mem);
err_pci_release_regions:
pci_release_regions(pdev);
err_pci_disable_device:
pci_disable_device(pdev);
err_kfree:
pci_set_drvdata(pdev, NULL);
kfree(dev);
return ret;
}
static void dm1105_remove(struct pci_dev *pdev)
{
struct dm1105_dev *dev = pci_get_drvdata(pdev);
struct dvb_adapter *dvb_adapter = &dev->dvb_adapter;
struct dvb_demux *dvbdemux = &dev->demux;
struct dmx_demux *dmx = &dvbdemux->dmx;
dm1105_ir_exit(dev);
dmx->close(dmx);
dvb_net_release(&dev->dvbnet);
if (dev->fe)
dvb_unregister_frontend(dev->fe);
dmx->disconnect_frontend(dmx);
dmx->remove_frontend(dmx, &dev->mem_frontend);
dmx->remove_frontend(dmx, &dev->hw_frontend);
dvb_dmxdev_release(&dev->dmxdev);
dvb_dmx_release(dvbdemux);
dvb_unregister_adapter(dvb_adapter);
if (&dev->i2c_adap)
i2c_del_adapter(&dev->i2c_adap);
dm1105_hw_exit(dev);
synchronize_irq(pdev->irq);
free_irq(pdev->irq, dev);
pci_iounmap(pdev, dev->io_mem);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
dm1105_devcount--;
kfree(dev);
}
