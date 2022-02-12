static int ibmvtpm_send_crq(struct vio_dev *vdev, u64 w1, u64 w2)
{
return plpar_hcall_norets(H_SEND_CRQ, vdev->unit_address, w1, w2);
}
static struct ibmvtpm_dev *ibmvtpm_get_data(const struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
if (chip)
return (struct ibmvtpm_dev *)TPM_VPRIV(chip);
return NULL;
}
static int tpm_ibmvtpm_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct ibmvtpm_dev *ibmvtpm;
u16 len;
int sig;
ibmvtpm = (struct ibmvtpm_dev *)TPM_VPRIV(chip);
if (!ibmvtpm->rtce_buf) {
dev_err(ibmvtpm->dev, "ibmvtpm device is not ready\n");
return 0;
}
sig = wait_event_interruptible(ibmvtpm->wq, ibmvtpm->res_len != 0);
if (sig)
return -EINTR;
len = ibmvtpm->res_len;
if (count < len) {
dev_err(ibmvtpm->dev,
"Invalid size in recv: count=%zd, crq_size=%d\n",
count, len);
return -EIO;
}
spin_lock(&ibmvtpm->rtce_lock);
memcpy((void *)buf, (void *)ibmvtpm->rtce_buf, len);
memset(ibmvtpm->rtce_buf, 0, len);
ibmvtpm->res_len = 0;
spin_unlock(&ibmvtpm->rtce_lock);
return len;
}
static int tpm_ibmvtpm_send(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct ibmvtpm_dev *ibmvtpm;
struct ibmvtpm_crq crq;
__be64 *word = (__be64 *)&crq;
int rc;
ibmvtpm = (struct ibmvtpm_dev *)TPM_VPRIV(chip);
if (!ibmvtpm->rtce_buf) {
dev_err(ibmvtpm->dev, "ibmvtpm device is not ready\n");
return 0;
}
if (count > ibmvtpm->rtce_size) {
dev_err(ibmvtpm->dev,
"Invalid size in send: count=%zd, rtce_size=%d\n",
count, ibmvtpm->rtce_size);
return -EIO;
}
spin_lock(&ibmvtpm->rtce_lock);
memcpy((void *)ibmvtpm->rtce_buf, (void *)buf, count);
crq.valid = (u8)IBMVTPM_VALID_CMD;
crq.msg = (u8)VTPM_TPM_COMMAND;
crq.len = cpu_to_be16(count);
crq.data = cpu_to_be32(ibmvtpm->rtce_dma_handle);
rc = ibmvtpm_send_crq(ibmvtpm->vdev, be64_to_cpu(word[0]),
be64_to_cpu(word[1]));
if (rc != H_SUCCESS) {
dev_err(ibmvtpm->dev, "tpm_ibmvtpm_send failed rc=%d\n", rc);
rc = 0;
} else
rc = count;
spin_unlock(&ibmvtpm->rtce_lock);
return rc;
}
static void tpm_ibmvtpm_cancel(struct tpm_chip *chip)
{
return;
}
static u8 tpm_ibmvtpm_status(struct tpm_chip *chip)
{
return 0;
}
static int ibmvtpm_crq_get_rtce_size(struct ibmvtpm_dev *ibmvtpm)
{
struct ibmvtpm_crq crq;
u64 *buf = (u64 *) &crq;
int rc;
crq.valid = (u8)IBMVTPM_VALID_CMD;
crq.msg = (u8)VTPM_GET_RTCE_BUFFER_SIZE;
rc = ibmvtpm_send_crq(ibmvtpm->vdev, cpu_to_be64(buf[0]),
cpu_to_be64(buf[1]));
if (rc != H_SUCCESS)
dev_err(ibmvtpm->dev,
"ibmvtpm_crq_get_rtce_size failed rc=%d\n", rc);
return rc;
}
static int ibmvtpm_crq_get_version(struct ibmvtpm_dev *ibmvtpm)
{
struct ibmvtpm_crq crq;
u64 *buf = (u64 *) &crq;
int rc;
crq.valid = (u8)IBMVTPM_VALID_CMD;
crq.msg = (u8)VTPM_GET_VERSION;
rc = ibmvtpm_send_crq(ibmvtpm->vdev, cpu_to_be64(buf[0]),
cpu_to_be64(buf[1]));
if (rc != H_SUCCESS)
dev_err(ibmvtpm->dev,
"ibmvtpm_crq_get_version failed rc=%d\n", rc);
return rc;
}
static int ibmvtpm_crq_send_init_complete(struct ibmvtpm_dev *ibmvtpm)
{
int rc;
rc = ibmvtpm_send_crq(ibmvtpm->vdev, INIT_CRQ_COMP_CMD, 0);
if (rc != H_SUCCESS)
dev_err(ibmvtpm->dev,
"ibmvtpm_crq_send_init_complete failed rc=%d\n", rc);
return rc;
}
static int ibmvtpm_crq_send_init(struct ibmvtpm_dev *ibmvtpm)
{
int rc;
rc = ibmvtpm_send_crq(ibmvtpm->vdev, INIT_CRQ_CMD, 0);
if (rc != H_SUCCESS)
dev_err(ibmvtpm->dev,
"ibmvtpm_crq_send_init failed rc=%d\n", rc);
return rc;
}
static int tpm_ibmvtpm_remove(struct vio_dev *vdev)
{
struct ibmvtpm_dev *ibmvtpm = ibmvtpm_get_data(&vdev->dev);
struct tpm_chip *chip = dev_get_drvdata(ibmvtpm->dev);
int rc = 0;
tpm_chip_unregister(chip);
free_irq(vdev->irq, ibmvtpm);
do {
if (rc)
msleep(100);
rc = plpar_hcall_norets(H_FREE_CRQ, vdev->unit_address);
} while (rc == H_BUSY || H_IS_LONG_BUSY(rc));
dma_unmap_single(ibmvtpm->dev, ibmvtpm->crq_dma_handle,
CRQ_RES_BUF_SIZE, DMA_BIDIRECTIONAL);
free_page((unsigned long)ibmvtpm->crq_queue.crq_addr);
if (ibmvtpm->rtce_buf) {
dma_unmap_single(ibmvtpm->dev, ibmvtpm->rtce_dma_handle,
ibmvtpm->rtce_size, DMA_BIDIRECTIONAL);
kfree(ibmvtpm->rtce_buf);
}
kfree(ibmvtpm);
return 0;
}
static unsigned long tpm_ibmvtpm_get_desired_dma(struct vio_dev *vdev)
{
struct ibmvtpm_dev *ibmvtpm = ibmvtpm_get_data(&vdev->dev);
if (!ibmvtpm)
return CRQ_RES_BUF_SIZE + PAGE_SIZE;
return CRQ_RES_BUF_SIZE + ibmvtpm->rtce_size;
}
static int tpm_ibmvtpm_suspend(struct device *dev)
{
struct ibmvtpm_dev *ibmvtpm = ibmvtpm_get_data(dev);
struct ibmvtpm_crq crq;
u64 *buf = (u64 *) &crq;
int rc = 0;
crq.valid = (u8)IBMVTPM_VALID_CMD;
crq.msg = (u8)VTPM_PREPARE_TO_SUSPEND;
rc = ibmvtpm_send_crq(ibmvtpm->vdev, cpu_to_be64(buf[0]),
cpu_to_be64(buf[1]));
if (rc != H_SUCCESS)
dev_err(ibmvtpm->dev,
"tpm_ibmvtpm_suspend failed rc=%d\n", rc);
return rc;
}
static int ibmvtpm_reset_crq(struct ibmvtpm_dev *ibmvtpm)
{
int rc = 0;
do {
if (rc)
msleep(100);
rc = plpar_hcall_norets(H_FREE_CRQ,
ibmvtpm->vdev->unit_address);
} while (rc == H_BUSY || H_IS_LONG_BUSY(rc));
memset(ibmvtpm->crq_queue.crq_addr, 0, CRQ_RES_BUF_SIZE);
ibmvtpm->crq_queue.index = 0;
return plpar_hcall_norets(H_REG_CRQ, ibmvtpm->vdev->unit_address,
ibmvtpm->crq_dma_handle, CRQ_RES_BUF_SIZE);
}
static int tpm_ibmvtpm_resume(struct device *dev)
{
struct ibmvtpm_dev *ibmvtpm = ibmvtpm_get_data(dev);
int rc = 0;
do {
if (rc)
msleep(100);
rc = plpar_hcall_norets(H_ENABLE_CRQ,
ibmvtpm->vdev->unit_address);
} while (rc == H_IN_PROGRESS || rc == H_BUSY || H_IS_LONG_BUSY(rc));
if (rc) {
dev_err(dev, "Error enabling ibmvtpm rc=%d\n", rc);
return rc;
}
rc = vio_enable_interrupts(ibmvtpm->vdev);
if (rc) {
dev_err(dev, "Error vio_enable_interrupts rc=%d\n", rc);
return rc;
}
rc = ibmvtpm_crq_send_init(ibmvtpm);
if (rc)
dev_err(dev, "Error send_init rc=%d\n", rc);
return rc;
}
static bool tpm_ibmvtpm_req_canceled(struct tpm_chip *chip, u8 status)
{
return (status == 0);
}
static struct ibmvtpm_crq *ibmvtpm_crq_get_next(struct ibmvtpm_dev *ibmvtpm)
{
struct ibmvtpm_crq_queue *crq_q = &ibmvtpm->crq_queue;
struct ibmvtpm_crq *crq = &crq_q->crq_addr[crq_q->index];
if (crq->valid & VTPM_MSG_RES) {
if (++crq_q->index == crq_q->num_entry)
crq_q->index = 0;
smp_rmb();
} else
crq = NULL;
return crq;
}
static void ibmvtpm_crq_process(struct ibmvtpm_crq *crq,
struct ibmvtpm_dev *ibmvtpm)
{
int rc = 0;
switch (crq->valid) {
case VALID_INIT_CRQ:
switch (crq->msg) {
case INIT_CRQ_RES:
dev_info(ibmvtpm->dev, "CRQ initialized\n");
rc = ibmvtpm_crq_send_init_complete(ibmvtpm);
if (rc)
dev_err(ibmvtpm->dev, "Unable to send CRQ init complete rc=%d\n", rc);
return;
case INIT_CRQ_COMP_RES:
dev_info(ibmvtpm->dev,
"CRQ initialization completed\n");
return;
default:
dev_err(ibmvtpm->dev, "Unknown crq message type: %d\n", crq->msg);
return;
}
case IBMVTPM_VALID_CMD:
switch (crq->msg) {
case VTPM_GET_RTCE_BUFFER_SIZE_RES:
if (be16_to_cpu(crq->len) <= 0) {
dev_err(ibmvtpm->dev, "Invalid rtce size\n");
return;
}
ibmvtpm->rtce_size = be16_to_cpu(crq->len);
ibmvtpm->rtce_buf = kmalloc(ibmvtpm->rtce_size,
GFP_KERNEL);
if (!ibmvtpm->rtce_buf) {
dev_err(ibmvtpm->dev, "Failed to allocate memory for rtce buffer\n");
return;
}
ibmvtpm->rtce_dma_handle = dma_map_single(ibmvtpm->dev,
ibmvtpm->rtce_buf, ibmvtpm->rtce_size,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(ibmvtpm->dev,
ibmvtpm->rtce_dma_handle)) {
kfree(ibmvtpm->rtce_buf);
ibmvtpm->rtce_buf = NULL;
dev_err(ibmvtpm->dev, "Failed to dma map rtce buffer\n");
}
return;
case VTPM_GET_VERSION_RES:
ibmvtpm->vtpm_version = be32_to_cpu(crq->data);
return;
case VTPM_TPM_COMMAND_RES:
ibmvtpm->res_len = be16_to_cpu(crq->len);
wake_up_interruptible(&ibmvtpm->wq);
return;
default:
return;
}
}
return;
}
static irqreturn_t ibmvtpm_interrupt(int irq, void *vtpm_instance)
{
struct ibmvtpm_dev *ibmvtpm = (struct ibmvtpm_dev *) vtpm_instance;
struct ibmvtpm_crq *crq;
while ((crq = ibmvtpm_crq_get_next(ibmvtpm)) != NULL) {
ibmvtpm_crq_process(crq, ibmvtpm);
crq->valid = 0;
smp_wmb();
}
return IRQ_HANDLED;
}
static int tpm_ibmvtpm_probe(struct vio_dev *vio_dev,
const struct vio_device_id *id)
{
struct ibmvtpm_dev *ibmvtpm;
struct device *dev = &vio_dev->dev;
struct ibmvtpm_crq_queue *crq_q;
struct tpm_chip *chip;
int rc = -ENOMEM, rc1;
chip = tpmm_chip_alloc(dev, &tpm_ibmvtpm);
if (IS_ERR(chip))
return PTR_ERR(chip);
ibmvtpm = kzalloc(sizeof(struct ibmvtpm_dev), GFP_KERNEL);
if (!ibmvtpm) {
dev_err(dev, "kzalloc for ibmvtpm failed\n");
goto cleanup;
}
ibmvtpm->dev = dev;
ibmvtpm->vdev = vio_dev;
crq_q = &ibmvtpm->crq_queue;
crq_q->crq_addr = (struct ibmvtpm_crq *)get_zeroed_page(GFP_KERNEL);
if (!crq_q->crq_addr) {
dev_err(dev, "Unable to allocate memory for crq_addr\n");
goto cleanup;
}
crq_q->num_entry = CRQ_RES_BUF_SIZE / sizeof(*crq_q->crq_addr);
ibmvtpm->crq_dma_handle = dma_map_single(dev, crq_q->crq_addr,
CRQ_RES_BUF_SIZE,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(dev, ibmvtpm->crq_dma_handle)) {
dev_err(dev, "dma mapping failed\n");
goto cleanup;
}
rc = plpar_hcall_norets(H_REG_CRQ, vio_dev->unit_address,
ibmvtpm->crq_dma_handle, CRQ_RES_BUF_SIZE);
if (rc == H_RESOURCE)
rc = ibmvtpm_reset_crq(ibmvtpm);
if (rc) {
dev_err(dev, "Unable to register CRQ rc=%d\n", rc);
goto reg_crq_cleanup;
}
rc = request_irq(vio_dev->irq, ibmvtpm_interrupt, 0,
tpm_ibmvtpm_driver_name, ibmvtpm);
if (rc) {
dev_err(dev, "Error %d register irq 0x%x\n", rc, vio_dev->irq);
goto init_irq_cleanup;
}
rc = vio_enable_interrupts(vio_dev);
if (rc) {
dev_err(dev, "Error %d enabling interrupts\n", rc);
goto init_irq_cleanup;
}
init_waitqueue_head(&ibmvtpm->wq);
crq_q->index = 0;
TPM_VPRIV(chip) = (void *)ibmvtpm;
spin_lock_init(&ibmvtpm->rtce_lock);
rc = ibmvtpm_crq_send_init(ibmvtpm);
if (rc)
goto init_irq_cleanup;
rc = ibmvtpm_crq_get_version(ibmvtpm);
if (rc)
goto init_irq_cleanup;
rc = ibmvtpm_crq_get_rtce_size(ibmvtpm);
if (rc)
goto init_irq_cleanup;
return tpm_chip_register(chip);
init_irq_cleanup:
do {
rc1 = plpar_hcall_norets(H_FREE_CRQ, vio_dev->unit_address);
} while (rc1 == H_BUSY || H_IS_LONG_BUSY(rc1));
reg_crq_cleanup:
dma_unmap_single(dev, ibmvtpm->crq_dma_handle, CRQ_RES_BUF_SIZE,
DMA_BIDIRECTIONAL);
cleanup:
if (ibmvtpm) {
if (crq_q->crq_addr)
free_page((unsigned long)crq_q->crq_addr);
kfree(ibmvtpm);
}
return rc;
}
static int __init ibmvtpm_module_init(void)
{
return vio_register_driver(&ibmvtpm_driver);
}
static void __exit ibmvtpm_module_exit(void)
{
vio_unregister_driver(&ibmvtpm_driver);
}
