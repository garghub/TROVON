struct mpc8xxx_spi_probe_info *to_of_pinfo(struct fsl_spi_platform_data *pdata)
{
return container_of(pdata, struct mpc8xxx_spi_probe_info, pdata);
}
static void mpc8xxx_spi_work(struct work_struct *work)
{
struct mpc8xxx_spi *mpc8xxx_spi = container_of(work, struct mpc8xxx_spi,
work);
spin_lock_irq(&mpc8xxx_spi->lock);
while (!list_empty(&mpc8xxx_spi->queue)) {
struct spi_message *m = container_of(mpc8xxx_spi->queue.next,
struct spi_message, queue);
list_del_init(&m->queue);
spin_unlock_irq(&mpc8xxx_spi->lock);
if (mpc8xxx_spi->spi_do_one_msg)
mpc8xxx_spi->spi_do_one_msg(m);
spin_lock_irq(&mpc8xxx_spi->lock);
}
spin_unlock_irq(&mpc8xxx_spi->lock);
}
int mpc8xxx_spi_transfer(struct spi_device *spi,
struct spi_message *m)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
unsigned long flags;
m->actual_length = 0;
m->status = -EINPROGRESS;
spin_lock_irqsave(&mpc8xxx_spi->lock, flags);
list_add_tail(&m->queue, &mpc8xxx_spi->queue);
queue_work(mpc8xxx_spi->workqueue, &mpc8xxx_spi->work);
spin_unlock_irqrestore(&mpc8xxx_spi->lock, flags);
return 0;
}
void mpc8xxx_spi_cleanup(struct spi_device *spi)
{
kfree(spi->controller_state);
}
const char *mpc8xxx_spi_strmode(unsigned int flags)
{
if (flags & SPI_QE_CPU_MODE) {
return "QE CPU";
} else if (flags & SPI_CPM_MODE) {
if (flags & SPI_QE)
return "QE";
else if (flags & SPI_CPM2)
return "CPM2";
else
return "CPM1";
}
return "CPU";
}
int mpc8xxx_spi_probe(struct device *dev, struct resource *mem,
unsigned int irq)
{
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
struct spi_master *master;
struct mpc8xxx_spi *mpc8xxx_spi;
int ret = 0;
master = dev_get_drvdata(dev);
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH
| SPI_LSB_FIRST | SPI_LOOP;
master->transfer = mpc8xxx_spi_transfer;
master->cleanup = mpc8xxx_spi_cleanup;
master->dev.of_node = dev->of_node;
mpc8xxx_spi = spi_master_get_devdata(master);
mpc8xxx_spi->dev = dev;
mpc8xxx_spi->get_rx = mpc8xxx_spi_rx_buf_u8;
mpc8xxx_spi->get_tx = mpc8xxx_spi_tx_buf_u8;
mpc8xxx_spi->flags = pdata->flags;
mpc8xxx_spi->spibrg = pdata->sysclk;
mpc8xxx_spi->irq = irq;
mpc8xxx_spi->rx_shift = 0;
mpc8xxx_spi->tx_shift = 0;
init_completion(&mpc8xxx_spi->done);
master->bus_num = pdata->bus_num;
master->num_chipselect = pdata->max_chipselect;
spin_lock_init(&mpc8xxx_spi->lock);
init_completion(&mpc8xxx_spi->done);
INIT_WORK(&mpc8xxx_spi->work, mpc8xxx_spi_work);
INIT_LIST_HEAD(&mpc8xxx_spi->queue);
mpc8xxx_spi->workqueue = create_singlethread_workqueue(
dev_name(master->dev.parent));
if (mpc8xxx_spi->workqueue == NULL) {
ret = -EBUSY;
goto err;
}
return 0;
err:
return ret;
}
int mpc8xxx_spi_remove(struct device *dev)
{
struct mpc8xxx_spi *mpc8xxx_spi;
struct spi_master *master;
master = dev_get_drvdata(dev);
mpc8xxx_spi = spi_master_get_devdata(master);
flush_workqueue(mpc8xxx_spi->workqueue);
destroy_workqueue(mpc8xxx_spi->workqueue);
spi_unregister_master(master);
free_irq(mpc8xxx_spi->irq, mpc8xxx_spi);
if (mpc8xxx_spi->spi_remove)
mpc8xxx_spi->spi_remove(mpc8xxx_spi);
return 0;
}
int of_mpc8xxx_spi_probe(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct device_node *np = ofdev->dev.of_node;
struct mpc8xxx_spi_probe_info *pinfo;
struct fsl_spi_platform_data *pdata;
const void *prop;
int ret = -ENOMEM;
pinfo = kzalloc(sizeof(*pinfo), GFP_KERNEL);
if (!pinfo)
return -ENOMEM;
pdata = &pinfo->pdata;
dev->platform_data = pdata;
pdata->bus_num = -1;
#ifdef CONFIG_FSL_SOC
pdata->sysclk = get_brgfreq();
if (pdata->sysclk == -1) {
pdata->sysclk = fsl_get_sys_freq();
if (pdata->sysclk == -1) {
ret = -ENODEV;
goto err;
}
}
#else
ret = of_property_read_u32(np, "clock-frequency", &pdata->sysclk);
if (ret)
goto err;
#endif
prop = of_get_property(np, "mode", NULL);
if (prop && !strcmp(prop, "cpu-qe"))
pdata->flags = SPI_QE_CPU_MODE;
else if (prop && !strcmp(prop, "qe"))
pdata->flags = SPI_CPM_MODE | SPI_QE;
else if (of_device_is_compatible(np, "fsl,cpm2-spi"))
pdata->flags = SPI_CPM_MODE | SPI_CPM2;
else if (of_device_is_compatible(np, "fsl,cpm1-spi"))
pdata->flags = SPI_CPM_MODE | SPI_CPM1;
return 0;
err:
kfree(pinfo);
return ret;
}
