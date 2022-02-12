static irqreturn_t
snic_isr_msix_wq(int irq, void *data)
{
struct snic *snic = data;
unsigned long wq_work_done = 0;
snic->s_stats.misc.last_isr_time = jiffies;
atomic64_inc(&snic->s_stats.misc.ack_isr_cnt);
wq_work_done = snic_wq_cmpl_handler(snic, -1);
svnic_intr_return_credits(&snic->intr[SNIC_MSIX_WQ],
wq_work_done,
1 ,
1 );
return IRQ_HANDLED;
}
static irqreturn_t
snic_isr_msix_io_cmpl(int irq, void *data)
{
struct snic *snic = data;
unsigned long iocmpl_work_done = 0;
snic->s_stats.misc.last_isr_time = jiffies;
atomic64_inc(&snic->s_stats.misc.cmpl_isr_cnt);
iocmpl_work_done = snic_fwcq_cmpl_handler(snic, -1);
svnic_intr_return_credits(&snic->intr[SNIC_MSIX_IO_CMPL],
iocmpl_work_done,
1 ,
1 );
return IRQ_HANDLED;
}
static irqreturn_t
snic_isr_msix_err_notify(int irq, void *data)
{
struct snic *snic = data;
snic->s_stats.misc.last_isr_time = jiffies;
atomic64_inc(&snic->s_stats.misc.errnotify_isr_cnt);
svnic_intr_return_all_credits(&snic->intr[SNIC_MSIX_ERR_NOTIFY]);
snic_log_q_error(snic);
snic_handle_link_event(snic);
return IRQ_HANDLED;
}
void
snic_free_intr(struct snic *snic)
{
int i;
for (i = 0; i < ARRAY_SIZE(snic->msix); i++) {
if (snic->msix[i].requested) {
free_irq(snic->msix_entry[i].vector,
snic->msix[i].devid);
}
}
}
int
snic_request_intr(struct snic *snic)
{
int ret = 0, i;
enum vnic_dev_intr_mode intr_mode;
intr_mode = svnic_dev_get_intr_mode(snic->vdev);
SNIC_BUG_ON(intr_mode != VNIC_DEV_INTR_MODE_MSIX);
sprintf(snic->msix[SNIC_MSIX_WQ].devname,
"%.11s-scsi-wq",
snic->name);
snic->msix[SNIC_MSIX_WQ].isr = snic_isr_msix_wq;
snic->msix[SNIC_MSIX_WQ].devid = snic;
sprintf(snic->msix[SNIC_MSIX_IO_CMPL].devname,
"%.11s-io-cmpl",
snic->name);
snic->msix[SNIC_MSIX_IO_CMPL].isr = snic_isr_msix_io_cmpl;
snic->msix[SNIC_MSIX_IO_CMPL].devid = snic;
sprintf(snic->msix[SNIC_MSIX_ERR_NOTIFY].devname,
"%.11s-err-notify",
snic->name);
snic->msix[SNIC_MSIX_ERR_NOTIFY].isr = snic_isr_msix_err_notify;
snic->msix[SNIC_MSIX_ERR_NOTIFY].devid = snic;
for (i = 0; i < ARRAY_SIZE(snic->msix); i++) {
ret = request_irq(snic->msix_entry[i].vector,
snic->msix[i].isr,
0,
snic->msix[i].devname,
snic->msix[i].devid);
if (ret) {
SNIC_HOST_ERR(snic->shost,
"MSI-X: requrest_irq(%d) failed %d\n",
i,
ret);
snic_free_intr(snic);
break;
}
snic->msix[i].requested = 1;
}
return ret;
}
int
snic_set_intr_mode(struct snic *snic)
{
unsigned int n = ARRAY_SIZE(snic->wq);
unsigned int m = SNIC_CQ_IO_CMPL_MAX;
unsigned int i;
BUILD_BUG_ON((ARRAY_SIZE(snic->wq) + SNIC_CQ_IO_CMPL_MAX) >
ARRAY_SIZE(snic->intr));
SNIC_BUG_ON(ARRAY_SIZE(snic->msix_entry) < (n + m + 1));
for (i = 0; i < (n + m + 1); i++)
snic->msix_entry[i].entry = i;
if (snic->wq_count >= n && snic->cq_count >= (n + m)) {
if (!pci_enable_msix(snic->pdev,
snic->msix_entry,
(n + m + 1))) {
snic->wq_count = n;
snic->cq_count = n + m;
snic->intr_count = n + m + 1;
snic->err_intr_offset = SNIC_MSIX_ERR_NOTIFY;
SNIC_ISR_DBG(snic->shost,
"Using MSI-X Interrupts\n");
svnic_dev_set_intr_mode(snic->vdev,
VNIC_DEV_INTR_MODE_MSIX);
return 0;
}
}
svnic_dev_set_intr_mode(snic->vdev, VNIC_DEV_INTR_MODE_UNKNOWN);
return -EINVAL;
}
void
snic_clear_intr_mode(struct snic *snic)
{
pci_disable_msix(snic->pdev);
svnic_dev_set_intr_mode(snic->vdev, VNIC_DEV_INTR_MODE_INTX);
}
