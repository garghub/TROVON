static flexcop_ibi_value flexcop_pci_read_ibi_reg(struct flexcop_device *fc,
flexcop_ibi_register r)
{
struct flexcop_pci *fc_pci = fc->bus_specific;
flexcop_ibi_value v;
v.raw = readl(fc_pci->io_mem + r);
if (lastrreg != r || lastrval != v.raw) {
lastrreg = r; lastrval = v.raw;
deb_reg("new rd: %3x: %08x\n", r, v.raw);
}
return v;
}
static int flexcop_pci_write_ibi_reg(struct flexcop_device *fc,
flexcop_ibi_register r, flexcop_ibi_value v)
{
struct flexcop_pci *fc_pci = fc->bus_specific;
if (lastwreg != r || lastwval != v.raw) {
lastwreg = r; lastwval = v.raw;
deb_reg("new wr: %3x: %08x\n", r, v.raw);
}
writel(v.raw, fc_pci->io_mem + r);
return 0;
}
static void flexcop_pci_irq_check_work(struct work_struct *work)
{
struct flexcop_pci *fc_pci =
container_of(work, struct flexcop_pci, irq_check_work.work);
struct flexcop_device *fc = fc_pci->fc_dev;
if (fc->feedcount) {
if (fc_pci->count == fc_pci->count_prev) {
deb_chk("no IRQ since the last check\n");
if (fc_pci->stream_problem++ == 3) {
struct dvb_demux_feed *feed;
deb_info("flexcop-pci: stream problem, resetting pid filter\n");
spin_lock_irq(&fc->demux.lock);
list_for_each_entry(feed, &fc->demux.feed_list,
list_head) {
flexcop_pid_feed_control(fc, feed, 0);
}
list_for_each_entry(feed, &fc->demux.feed_list,
list_head) {
flexcop_pid_feed_control(fc, feed, 1);
}
spin_unlock_irq(&fc->demux.lock);
fc_pci->stream_problem = 0;
}
} else {
fc_pci->stream_problem = 0;
fc_pci->count_prev = fc_pci->count;
}
}
schedule_delayed_work(&fc_pci->irq_check_work,
msecs_to_jiffies(irq_chk_intv < 100 ? 100 : irq_chk_intv));
}
static irqreturn_t flexcop_pci_isr(int irq, void *dev_id)
{
struct flexcop_pci *fc_pci = dev_id;
struct flexcop_device *fc = fc_pci->fc_dev;
unsigned long flags;
flexcop_ibi_value v;
irqreturn_t ret = IRQ_HANDLED;
spin_lock_irqsave(&fc_pci->irq_lock, flags);
v = fc->read_ibi_reg(fc, irq_20c);
if (v.irq_20c.Data_receiver_error)
deb_chk("data receiver error\n");
if (v.irq_20c.Continuity_error_flag)
deb_chk("Contunuity error flag is set\n");
if (v.irq_20c.LLC_SNAP_FLAG_set)
deb_chk("LLC_SNAP_FLAG_set is set\n");
if (v.irq_20c.Transport_Error)
deb_chk("Transport error\n");
if ((fc_pci->count % 1000) == 0)
deb_chk("%d valid irq took place so far\n", fc_pci->count);
if (v.irq_20c.DMA1_IRQ_Status == 1) {
if (fc_pci->active_dma1_addr == 0)
flexcop_pass_dmx_packets(fc_pci->fc_dev,
fc_pci->dma[0].cpu_addr0,
fc_pci->dma[0].size / 188);
else
flexcop_pass_dmx_packets(fc_pci->fc_dev,
fc_pci->dma[0].cpu_addr1,
fc_pci->dma[0].size / 188);
deb_irq("page change to page: %d\n",!fc_pci->active_dma1_addr);
fc_pci->active_dma1_addr = !fc_pci->active_dma1_addr;
} else if (v.irq_20c.DMA1_Timer_Status == 1) {
dma_addr_t cur_addr =
fc->read_ibi_reg(fc,dma1_008).dma_0x8.dma_cur_addr << 2;
u32 cur_pos = cur_addr - fc_pci->dma[0].dma_addr0;
deb_irq("%u irq: %08x cur_addr: %llx: cur_pos: %08x, last_cur_pos: %08x ",
jiffies_to_usecs(jiffies - fc_pci->last_irq),
v.raw, (unsigned long long)cur_addr, cur_pos,
fc_pci->last_dma1_cur_pos);
fc_pci->last_irq = jiffies;
if (cur_pos < fc_pci->last_dma1_cur_pos) {
deb_irq(" end was reached: passing %d bytes ",
(fc_pci->dma[0].size*2 - 1) -
fc_pci->last_dma1_cur_pos);
flexcop_pass_dmx_data(fc_pci->fc_dev,
fc_pci->dma[0].cpu_addr0 +
fc_pci->last_dma1_cur_pos,
(fc_pci->dma[0].size*2) -
fc_pci->last_dma1_cur_pos);
fc_pci->last_dma1_cur_pos = 0;
}
if (cur_pos > fc_pci->last_dma1_cur_pos) {
deb_irq(" passing %d bytes ",
cur_pos - fc_pci->last_dma1_cur_pos);
flexcop_pass_dmx_data(fc_pci->fc_dev,
fc_pci->dma[0].cpu_addr0 +
fc_pci->last_dma1_cur_pos,
cur_pos - fc_pci->last_dma1_cur_pos);
}
deb_irq("\n");
fc_pci->last_dma1_cur_pos = cur_pos;
fc_pci->count++;
} else {
deb_irq("isr for flexcop called, apparently without reason (%08x)\n",
v.raw);
ret = IRQ_NONE;
}
spin_unlock_irqrestore(&fc_pci->irq_lock, flags);
return ret;
}
static int flexcop_pci_stream_control(struct flexcop_device *fc, int onoff)
{
struct flexcop_pci *fc_pci = fc->bus_specific;
if (onoff) {
flexcop_dma_config(fc, &fc_pci->dma[0], FC_DMA_1);
flexcop_dma_config(fc, &fc_pci->dma[1], FC_DMA_2);
flexcop_dma_config_timer(fc, FC_DMA_1, 0);
flexcop_dma_xfer_control(fc, FC_DMA_1,
FC_DMA_SUBADDR_0 | FC_DMA_SUBADDR_1, 1);
deb_irq("DMA xfer enabled\n");
fc_pci->last_dma1_cur_pos = 0;
flexcop_dma_control_timer_irq(fc, FC_DMA_1, 1);
deb_irq("IRQ enabled\n");
fc_pci->count_prev = fc_pci->count;
} else {
flexcop_dma_control_timer_irq(fc, FC_DMA_1, 0);
deb_irq("IRQ disabled\n");
flexcop_dma_xfer_control(fc, FC_DMA_1,
FC_DMA_SUBADDR_0 | FC_DMA_SUBADDR_1, 0);
deb_irq("DMA xfer disabled\n");
}
return 0;
}
static int flexcop_pci_dma_init(struct flexcop_pci *fc_pci)
{
int ret;
ret = flexcop_dma_allocate(fc_pci->pdev, &fc_pci->dma[0],
FC_DEFAULT_DMA1_BUFSIZE);
if (ret != 0)
return ret;
ret = flexcop_dma_allocate(fc_pci->pdev, &fc_pci->dma[1],
FC_DEFAULT_DMA2_BUFSIZE);
if (ret != 0) {
flexcop_dma_free(&fc_pci->dma[0]);
return ret;
}
flexcop_sram_set_dest(fc_pci->fc_dev, FC_SRAM_DEST_MEDIA |
FC_SRAM_DEST_NET, FC_SRAM_DEST_TARGET_DMA1);
flexcop_sram_set_dest(fc_pci->fc_dev, FC_SRAM_DEST_CAO |
FC_SRAM_DEST_CAI, FC_SRAM_DEST_TARGET_DMA2);
fc_pci->init_state |= FC_PCI_DMA_INIT;
return ret;
}
static void flexcop_pci_dma_exit(struct flexcop_pci *fc_pci)
{
if (fc_pci->init_state & FC_PCI_DMA_INIT) {
flexcop_dma_free(&fc_pci->dma[0]);
flexcop_dma_free(&fc_pci->dma[1]);
}
fc_pci->init_state &= ~FC_PCI_DMA_INIT;
}
static int flexcop_pci_init(struct flexcop_pci *fc_pci)
{
int ret;
info("card revision %x", fc_pci->pdev->revision);
if ((ret = pci_enable_device(fc_pci->pdev)) != 0)
return ret;
pci_set_master(fc_pci->pdev);
if ((ret = pci_request_regions(fc_pci->pdev, DRIVER_NAME)) != 0)
goto err_pci_disable_device;
fc_pci->io_mem = pci_iomap(fc_pci->pdev, 0, 0x800);
if (!fc_pci->io_mem) {
err("cannot map io memory\n");
ret = -EIO;
goto err_pci_release_regions;
}
pci_set_drvdata(fc_pci->pdev, fc_pci);
spin_lock_init(&fc_pci->irq_lock);
if ((ret = request_irq(fc_pci->pdev->irq, flexcop_pci_isr,
IRQF_SHARED, DRIVER_NAME, fc_pci)) != 0)
goto err_pci_iounmap;
fc_pci->init_state |= FC_PCI_INIT;
return ret;
err_pci_iounmap:
pci_iounmap(fc_pci->pdev, fc_pci->io_mem);
err_pci_release_regions:
pci_release_regions(fc_pci->pdev);
err_pci_disable_device:
pci_disable_device(fc_pci->pdev);
return ret;
}
static void flexcop_pci_exit(struct flexcop_pci *fc_pci)
{
if (fc_pci->init_state & FC_PCI_INIT) {
free_irq(fc_pci->pdev->irq, fc_pci);
pci_iounmap(fc_pci->pdev, fc_pci->io_mem);
pci_release_regions(fc_pci->pdev);
pci_disable_device(fc_pci->pdev);
}
fc_pci->init_state &= ~FC_PCI_INIT;
}
static int flexcop_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct flexcop_device *fc;
struct flexcop_pci *fc_pci;
int ret = -ENOMEM;
if ((fc = flexcop_device_kmalloc(sizeof(struct flexcop_pci))) == NULL) {
err("out of memory\n");
return -ENOMEM;
}
fc_pci = fc->bus_specific;
fc_pci->fc_dev = fc;
fc->read_ibi_reg = flexcop_pci_read_ibi_reg;
fc->write_ibi_reg = flexcop_pci_write_ibi_reg;
fc->i2c_request = flexcop_i2c_request;
fc->get_mac_addr = flexcop_eeprom_check_mac_addr;
fc->stream_control = flexcop_pci_stream_control;
if (enable_pid_filtering)
info("will use the HW PID filter.");
else
info("will pass the complete TS to the demuxer.");
fc->pid_filtering = enable_pid_filtering;
fc->bus_type = FC_PCI;
fc->dev = &pdev->dev;
fc->owner = THIS_MODULE;
fc_pci->pdev = pdev;
if ((ret = flexcop_pci_init(fc_pci)) != 0)
goto err_kfree;
if ((ret = flexcop_device_initialize(fc)) != 0)
goto err_pci_exit;
if ((ret = flexcop_pci_dma_init(fc_pci)) != 0)
goto err_fc_exit;
INIT_DELAYED_WORK(&fc_pci->irq_check_work, flexcop_pci_irq_check_work);
if (irq_chk_intv > 0)
schedule_delayed_work(&fc_pci->irq_check_work,
msecs_to_jiffies(irq_chk_intv < 100 ?
100 :
irq_chk_intv));
return ret;
err_fc_exit:
flexcop_device_exit(fc);
err_pci_exit:
flexcop_pci_exit(fc_pci);
err_kfree:
flexcop_device_kfree(fc);
return ret;
}
static void flexcop_pci_remove(struct pci_dev *pdev)
{
struct flexcop_pci *fc_pci = pci_get_drvdata(pdev);
if (irq_chk_intv > 0)
cancel_delayed_work(&fc_pci->irq_check_work);
flexcop_pci_dma_exit(fc_pci);
flexcop_device_exit(fc_pci->fc_dev);
flexcop_pci_exit(fc_pci);
flexcop_device_kfree(fc_pci->fc_dev);
}
