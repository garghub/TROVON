static inline struct pluto *feed_to_pluto(struct dvb_demux_feed *feed)
{
return container_of(feed->demux, struct pluto, demux);
}
static inline struct pluto *frontend_to_pluto(struct dvb_frontend *fe)
{
return container_of(fe->dvb, struct pluto, dvb_adapter);
}
static inline u32 pluto_readreg(struct pluto *pluto, u32 reg)
{
return readl(&pluto->io_mem[reg]);
}
static inline void pluto_writereg(struct pluto *pluto, u32 reg, u32 val)
{
writel(val, &pluto->io_mem[reg]);
}
static inline void pluto_rw(struct pluto *pluto, u32 reg, u32 mask, u32 bits)
{
u32 val = readl(&pluto->io_mem[reg]);
val &= ~mask;
val |= bits;
writel(val, &pluto->io_mem[reg]);
}
static void pluto_write_tscr(struct pluto *pluto, u32 val)
{
val &= ~TSCR_ADEF;
val |= TS_DMA_PACKETS / 2;
pluto_writereg(pluto, REG_TSCR, val);
}
static void pluto_setsda(void *data, int state)
{
struct pluto *pluto = data;
if (state)
pluto_rw(pluto, REG_SLCS, SLCS_SDA, SLCS_SDA);
else
pluto_rw(pluto, REG_SLCS, SLCS_SDA, 0);
}
static void pluto_setscl(void *data, int state)
{
struct pluto *pluto = data;
if (state)
pluto_rw(pluto, REG_SLCS, SLCS_SCL, SLCS_SCL);
else
pluto_rw(pluto, REG_SLCS, SLCS_SCL, 0);
if ((state) && (pluto->i2cbug == 0)) {
pluto->i2cbug = 1;
} else {
if ((!state) && (pluto->i2cbug == 1))
pluto_setsda(pluto, 1);
pluto->i2cbug = 0;
}
}
static int pluto_getsda(void *data)
{
struct pluto *pluto = data;
return pluto_readreg(pluto, REG_SLCS) & SLCS_SDA;
}
static int pluto_getscl(void *data)
{
struct pluto *pluto = data;
return pluto_readreg(pluto, REG_SLCS) & SLCS_SCL;
}
static void pluto_reset_frontend(struct pluto *pluto, int reenable)
{
u32 val = pluto_readreg(pluto, REG_MISC);
if (val & MISC_FRST) {
val &= ~MISC_FRST;
pluto_writereg(pluto, REG_MISC, val);
}
if (reenable) {
val |= MISC_FRST;
pluto_writereg(pluto, REG_MISC, val);
}
}
static void pluto_reset_ts(struct pluto *pluto, int reenable)
{
u32 val = pluto_readreg(pluto, REG_TSCR);
if (val & TSCR_RSTN) {
val &= ~TSCR_RSTN;
pluto_write_tscr(pluto, val);
}
if (reenable) {
val |= TSCR_RSTN;
pluto_write_tscr(pluto, val);
}
}
static void pluto_set_dma_addr(struct pluto *pluto)
{
pluto_writereg(pluto, REG_PCAR, pluto->dma_addr);
}
static int __devinit pluto_dma_map(struct pluto *pluto)
{
pluto->dma_addr = pci_map_single(pluto->pdev, pluto->dma_buf,
TS_DMA_BYTES, PCI_DMA_FROMDEVICE);
return pci_dma_mapping_error(pluto->pdev, pluto->dma_addr);
}
static void pluto_dma_unmap(struct pluto *pluto)
{
pci_unmap_single(pluto->pdev, pluto->dma_addr,
TS_DMA_BYTES, PCI_DMA_FROMDEVICE);
}
static int pluto_start_feed(struct dvb_demux_feed *f)
{
struct pluto *pluto = feed_to_pluto(f);
if (pluto->users++ == 0)
pluto_rw(pluto, REG_PIDn(0), PID0_AFIL | PID0_NOFIL, 0);
if ((f->pid < 0x2000) && (f->index < NHWFILTERS))
pluto_rw(pluto, REG_PIDn(f->index), PIDn_ENP | PIDn_PID, PIDn_ENP | f->pid);
else if (pluto->full_ts_users++ == 0)
pluto_rw(pluto, REG_PIDn(0), PID0_NOFIL, PID0_NOFIL);
return 0;
}
static int pluto_stop_feed(struct dvb_demux_feed *f)
{
struct pluto *pluto = feed_to_pluto(f);
if (--pluto->users == 0)
pluto_rw(pluto, REG_PIDn(0), PID0_AFIL, PID0_AFIL);
if ((f->pid < 0x2000) && (f->index < NHWFILTERS))
pluto_rw(pluto, REG_PIDn(f->index), PIDn_ENP | PIDn_PID, 0x1fff);
else if (--pluto->full_ts_users == 0)
pluto_rw(pluto, REG_PIDn(0), PID0_NOFIL, 0);
return 0;
}
static void pluto_dma_end(struct pluto *pluto, unsigned int nbpackets)
{
pci_dma_sync_single_for_cpu(pluto->pdev, pluto->dma_addr,
TS_DMA_BYTES, PCI_DMA_FROMDEVICE);
if ((nbpackets == 0) || (nbpackets > TS_DMA_PACKETS)) {
unsigned int i = 0;
while (pluto->dma_buf[i] == 0x47)
i += 188;
nbpackets = i / 188;
if (i == 0) {
pluto_reset_ts(pluto, 1);
dev_printk(KERN_DEBUG, &pluto->pdev->dev, "resetting TS because of invalid packet counter\n");
}
}
dvb_dmx_swfilter_packets(&pluto->demux, pluto->dma_buf, nbpackets);
memset(pluto->dma_buf, 0, nbpackets * 188);
pluto_set_dma_addr(pluto);
pci_dma_sync_single_for_device(pluto->pdev, pluto->dma_addr,
TS_DMA_BYTES, PCI_DMA_FROMDEVICE);
}
static irqreturn_t pluto_irq(int irq, void *dev_id)
{
struct pluto *pluto = dev_id;
u32 tscr;
tscr = pluto_readreg(pluto, REG_TSCR);
if (!(tscr & (TSCR_DE | TSCR_OVR)))
return IRQ_NONE;
if (tscr == 0xffffffff) {
if (pluto->dead == 0)
dev_err(&pluto->pdev->dev, "card has hung or been ejected.\n");
pluto->dead = 1;
return IRQ_HANDLED;
}
if (tscr & TSCR_DE) {
pluto_dma_end(pluto, (tscr & TSCR_NBPACKETS) >> 24);
if (tscr & TSCR_OVR)
pluto->overflow++;
if (pluto->overflow) {
dev_err(&pluto->pdev->dev, "overflow irq (%d)\n",
pluto->overflow);
pluto_reset_ts(pluto, 1);
pluto->overflow = 0;
}
} else if (tscr & TSCR_OVR) {
pluto->overflow++;
}
pluto_write_tscr(pluto, tscr | TSCR_IACK);
return IRQ_HANDLED;
}
static void __devinit pluto_enable_irqs(struct pluto *pluto)
{
u32 val = pluto_readreg(pluto, REG_TSCR);
val |= (TSCR_MSKA | TSCR_MSKL);
val &= ~(TSCR_DEM | TSCR_MSKO);
val |= TSCR_IACK;
pluto_write_tscr(pluto, val);
}
static void pluto_disable_irqs(struct pluto *pluto)
{
u32 val = pluto_readreg(pluto, REG_TSCR);
val |= (TSCR_DEM | TSCR_MSKO | TSCR_MSKA | TSCR_MSKL);
val |= TSCR_IACK;
pluto_write_tscr(pluto, val);
}
static int __devinit pluto_hw_init(struct pluto *pluto)
{
pluto_reset_frontend(pluto, 1);
pluto_rw(pluto, REG_MISC, MISC_ALED, MISC_ALED);
#ifdef __LITTLE_ENDIAN
pluto_rw(pluto, REG_PIDn(0), PID0_END, PID0_END);
#else
pluto_rw(pluto, REG_PIDn(0), PID0_END, 0);
#endif
pluto_dma_map(pluto);
pluto_set_dma_addr(pluto);
pluto_enable_irqs(pluto);
pluto_reset_ts(pluto, 1);
return 0;
}
static void pluto_hw_exit(struct pluto *pluto)
{
pluto_disable_irqs(pluto);
pluto_reset_ts(pluto, 0);
pluto_rw(pluto, REG_MISC, MISC_ALED | MISC_LED1 | MISC_LED0, MISC_LED1);
pluto_dma_unmap(pluto);
pluto_reset_frontend(pluto, 0);
}
static inline u32 divide(u32 numerator, u32 denominator)
{
if (denominator == 0)
return ~0;
return DIV_ROUND_CLOSEST(numerator, denominator);
}
static int lg_tdtpe001p_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct pluto *pluto = frontend_to_pluto(fe);
struct i2c_msg msg;
int ret;
u8 buf[4];
u32 div;
div = divide(p->frequency * 3, 500000) + 217;
buf[0] = (div >> 8) & 0x7f;
buf[1] = (div >> 0) & 0xff;
if (p->frequency < 611000000)
buf[2] = 0xb4;
else if (p->frequency < 811000000)
buf[2] = 0xbc;
else
buf[2] = 0xf4;
if (p->frequency < 350000000)
buf[3] = 0x02;
else
buf[3] = 0x04;
if (p->bandwidth_hz == 8000000)
buf[3] |= 0x08;
if (sizeof(buf) == 6) {
buf[4] = buf[2];
buf[4] &= ~0x1c;
buf[4] |= 0x18;
buf[5] = (0 << 7) | (2 << 4);
}
msg.addr = I2C_ADDR_TUA6034 >> 1;
msg.flags = 0;
msg.buf = buf;
msg.len = sizeof(buf);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer(&pluto->i2c_adap, &msg, 1);
if (ret < 0)
return ret;
else if (ret == 0)
return -EREMOTEIO;
return 0;
}
static int pluto2_request_firmware(struct dvb_frontend *fe,
const struct firmware **fw, char *name)
{
struct pluto *pluto = frontend_to_pluto(fe);
return request_firmware(fw, name, &pluto->pdev->dev);
}
static int __devinit frontend_init(struct pluto *pluto)
{
int ret;
pluto->fe = tda10046_attach(&pluto2_fe_config, &pluto->i2c_adap);
if (!pluto->fe) {
dev_err(&pluto->pdev->dev, "could not attach frontend\n");
return -ENODEV;
}
pluto->fe->ops.tuner_ops.set_params = lg_tdtpe001p_tuner_set_params;
ret = dvb_register_frontend(&pluto->dvb_adapter, pluto->fe);
if (ret < 0) {
if (pluto->fe->ops.release)
pluto->fe->ops.release(pluto->fe);
return ret;
}
return 0;
}
static void __devinit pluto_read_rev(struct pluto *pluto)
{
u32 val = pluto_readreg(pluto, REG_MISC) & MISC_DVR;
dev_info(&pluto->pdev->dev, "board revision %d.%d\n",
(val >> 12) & 0x0f, (val >> 4) & 0xff);
}
static void __devinit pluto_read_mac(struct pluto *pluto, u8 *mac)
{
u32 val = pluto_readreg(pluto, REG_MMAC);
mac[0] = (val >> 8) & 0xff;
mac[1] = (val >> 0) & 0xff;
val = pluto_readreg(pluto, REG_IMAC);
mac[2] = (val >> 8) & 0xff;
mac[3] = (val >> 0) & 0xff;
val = pluto_readreg(pluto, REG_LMAC);
mac[4] = (val >> 8) & 0xff;
mac[5] = (val >> 0) & 0xff;
dev_info(&pluto->pdev->dev, "MAC %pM\n", mac);
}
static int __devinit pluto_read_serial(struct pluto *pluto)
{
struct pci_dev *pdev = pluto->pdev;
unsigned int i, j;
u8 __iomem *cis;
cis = pci_iomap(pdev, 1, 0);
if (!cis)
return -EIO;
dev_info(&pdev->dev, "S/N ");
for (i = 0xe0; i < 0x100; i += 4) {
u32 val = readl(&cis[i]);
for (j = 0; j < 32; j += 8) {
if ((val & 0xff) == 0xff)
goto out;
printk("%c", val & 0xff);
val >>= 8;
}
}
out:
printk("\n");
pci_iounmap(pdev, cis);
return 0;
}
static int __devinit pluto2_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct pluto *pluto;
struct dvb_adapter *dvb_adapter;
struct dvb_demux *dvbdemux;
struct dmx_demux *dmx;
int ret = -ENOMEM;
pluto = kzalloc(sizeof(struct pluto), GFP_KERNEL);
if (!pluto)
goto out;
pluto->pdev = pdev;
ret = pci_enable_device(pdev);
if (ret < 0)
goto err_kfree;
pci_write_config_dword(pdev, 0x6c, 0x8000);
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (ret < 0)
goto err_pci_disable_device;
pci_set_master(pdev);
ret = pci_request_regions(pdev, DRIVER_NAME);
if (ret < 0)
goto err_pci_disable_device;
pluto->io_mem = pci_iomap(pdev, 0, 0x40);
if (!pluto->io_mem) {
ret = -EIO;
goto err_pci_release_regions;
}
pci_set_drvdata(pdev, pluto);
ret = request_irq(pdev->irq, pluto_irq, IRQF_SHARED, DRIVER_NAME, pluto);
if (ret < 0)
goto err_pci_iounmap;
ret = pluto_hw_init(pluto);
if (ret < 0)
goto err_free_irq;
i2c_set_adapdata(&pluto->i2c_adap, pluto);
strcpy(pluto->i2c_adap.name, DRIVER_NAME);
pluto->i2c_adap.owner = THIS_MODULE;
pluto->i2c_adap.dev.parent = &pdev->dev;
pluto->i2c_adap.algo_data = &pluto->i2c_bit;
pluto->i2c_bit.data = pluto;
pluto->i2c_bit.setsda = pluto_setsda;
pluto->i2c_bit.setscl = pluto_setscl;
pluto->i2c_bit.getsda = pluto_getsda;
pluto->i2c_bit.getscl = pluto_getscl;
pluto->i2c_bit.udelay = 10;
pluto->i2c_bit.timeout = 10;
pluto_setsda(pluto, 1);
pluto_setscl(pluto, 1);
ret = i2c_bit_add_bus(&pluto->i2c_adap);
if (ret < 0)
goto err_pluto_hw_exit;
ret = dvb_register_adapter(&pluto->dvb_adapter, DRIVER_NAME,
THIS_MODULE, &pdev->dev, adapter_nr);
if (ret < 0)
goto err_i2c_del_adapter;
dvb_adapter = &pluto->dvb_adapter;
pluto_read_rev(pluto);
pluto_read_serial(pluto);
pluto_read_mac(pluto, dvb_adapter->proposed_mac);
dvbdemux = &pluto->demux;
dvbdemux->filternum = 256;
dvbdemux->feednum = 256;
dvbdemux->start_feed = pluto_start_feed;
dvbdemux->stop_feed = pluto_stop_feed;
dvbdemux->dmx.capabilities = (DMX_TS_FILTERING |
DMX_SECTION_FILTERING | DMX_MEMORY_BASED_FILTERING);
ret = dvb_dmx_init(dvbdemux);
if (ret < 0)
goto err_dvb_unregister_adapter;
dmx = &dvbdemux->dmx;
pluto->hw_frontend.source = DMX_FRONTEND_0;
pluto->mem_frontend.source = DMX_MEMORY_FE;
pluto->dmxdev.filternum = NHWFILTERS;
pluto->dmxdev.demux = dmx;
ret = dvb_dmxdev_init(&pluto->dmxdev, dvb_adapter);
if (ret < 0)
goto err_dvb_dmx_release;
ret = dmx->add_frontend(dmx, &pluto->hw_frontend);
if (ret < 0)
goto err_dvb_dmxdev_release;
ret = dmx->add_frontend(dmx, &pluto->mem_frontend);
if (ret < 0)
goto err_remove_hw_frontend;
ret = dmx->connect_frontend(dmx, &pluto->hw_frontend);
if (ret < 0)
goto err_remove_mem_frontend;
ret = frontend_init(pluto);
if (ret < 0)
goto err_disconnect_frontend;
dvb_net_init(dvb_adapter, &pluto->dvbnet, dmx);
out:
return ret;
err_disconnect_frontend:
dmx->disconnect_frontend(dmx);
err_remove_mem_frontend:
dmx->remove_frontend(dmx, &pluto->mem_frontend);
err_remove_hw_frontend:
dmx->remove_frontend(dmx, &pluto->hw_frontend);
err_dvb_dmxdev_release:
dvb_dmxdev_release(&pluto->dmxdev);
err_dvb_dmx_release:
dvb_dmx_release(dvbdemux);
err_dvb_unregister_adapter:
dvb_unregister_adapter(dvb_adapter);
err_i2c_del_adapter:
i2c_del_adapter(&pluto->i2c_adap);
err_pluto_hw_exit:
pluto_hw_exit(pluto);
err_free_irq:
free_irq(pdev->irq, pluto);
err_pci_iounmap:
pci_iounmap(pdev, pluto->io_mem);
err_pci_release_regions:
pci_release_regions(pdev);
err_pci_disable_device:
pci_disable_device(pdev);
err_kfree:
pci_set_drvdata(pdev, NULL);
kfree(pluto);
goto out;
}
static void __devexit pluto2_remove(struct pci_dev *pdev)
{
struct pluto *pluto = pci_get_drvdata(pdev);
struct dvb_adapter *dvb_adapter = &pluto->dvb_adapter;
struct dvb_demux *dvbdemux = &pluto->demux;
struct dmx_demux *dmx = &dvbdemux->dmx;
dmx->close(dmx);
dvb_net_release(&pluto->dvbnet);
if (pluto->fe)
dvb_unregister_frontend(pluto->fe);
dmx->disconnect_frontend(dmx);
dmx->remove_frontend(dmx, &pluto->mem_frontend);
dmx->remove_frontend(dmx, &pluto->hw_frontend);
dvb_dmxdev_release(&pluto->dmxdev);
dvb_dmx_release(dvbdemux);
dvb_unregister_adapter(dvb_adapter);
i2c_del_adapter(&pluto->i2c_adap);
pluto_hw_exit(pluto);
free_irq(pdev->irq, pluto);
pci_iounmap(pdev, pluto->io_mem);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
kfree(pluto);
}
static int __init pluto2_init(void)
{
return pci_register_driver(&pluto2_driver);
}
static void __exit pluto2_exit(void)
{
pci_unregister_driver(&pluto2_driver);
}
