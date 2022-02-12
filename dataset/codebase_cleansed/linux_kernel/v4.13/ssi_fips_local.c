static enum ssi_fips_error ssi_fips_get_tee_error(struct ssi_drvdata *drvdata)
{
u32 regVal;
void __iomem *cc_base = drvdata->cc_base;
regVal = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, GPR_HOST));
if (regVal == (CC_FIPS_SYNC_TEE_STATUS | CC_FIPS_SYNC_MODULE_OK))
return CC_REE_FIPS_ERROR_OK;
return CC_REE_FIPS_ERROR_FROM_TEE;
}
static void ssi_fips_update_tee_upon_ree_status(struct ssi_drvdata *drvdata, enum cc_fips_error err)
{
void __iomem *cc_base = drvdata->cc_base;
if (err == CC_REE_FIPS_ERROR_OK)
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_GPR0), (CC_FIPS_SYNC_REE_STATUS | CC_FIPS_SYNC_MODULE_OK));
else
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_GPR0), (CC_FIPS_SYNC_REE_STATUS | CC_FIPS_SYNC_MODULE_ERROR));
}
void ssi_fips_fini(struct ssi_drvdata *drvdata)
{
struct ssi_fips_handle *fips_h = drvdata->fips_handle;
if (!fips_h)
return;
#ifdef COMP_IN_WQ
if (fips_h->workq) {
flush_workqueue(fips_h->workq);
destroy_workqueue(fips_h->workq);
}
#else
tasklet_kill(&fips_h->fipstask);
#endif
memset(fips_h, 0, sizeof(struct ssi_fips_handle));
kfree(fips_h);
drvdata->fips_handle = NULL;
}
void fips_handler(struct ssi_drvdata *drvdata)
{
struct ssi_fips_handle *fips_handle_ptr =
drvdata->fips_handle;
#ifdef COMP_IN_WQ
queue_delayed_work(fips_handle_ptr->workq, &fips_handle_ptr->fipswork, 0);
#else
tasklet_schedule(&fips_handle_ptr->fipstask);
#endif
}
static void fips_wq_handler(struct work_struct *work)
{
struct ssi_drvdata *drvdata =
container_of(work, struct ssi_drvdata, fipswork.work);
fips_dsr((unsigned long)drvdata);
}
static void fips_dsr(unsigned long devarg)
{
struct ssi_drvdata *drvdata = (struct ssi_drvdata *)devarg;
void __iomem *cc_base = drvdata->cc_base;
u32 irq;
u32 teeFipsError = 0;
irq = (drvdata->irq & (SSI_GPR0_IRQ_MASK));
if (irq & SSI_GPR0_IRQ_MASK) {
teeFipsError = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, GPR_HOST));
if (teeFipsError != (CC_FIPS_SYNC_TEE_STATUS | CC_FIPS_SYNC_MODULE_OK))
ssi_fips_set_error(drvdata, CC_REE_FIPS_ERROR_FROM_TEE);
}
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR),
CC_HAL_READ_REGISTER(
CC_REG_OFFSET(HOST_RGF, HOST_IMR)) & ~irq);
}
enum cc_fips_error cc_fips_run_power_up_tests(struct ssi_drvdata *drvdata)
{
enum cc_fips_error fips_error = CC_REE_FIPS_ERROR_OK;
void *cpu_addr_buffer = NULL;
dma_addr_t dma_handle;
size_t alloc_buff_size = ssi_fips_max_mem_alloc_size();
struct device *dev = &drvdata->plat_dev->dev;
FIPS_DBG("dma_alloc_coherent \n");
cpu_addr_buffer = dma_alloc_coherent(dev, alloc_buff_size, &dma_handle, GFP_KERNEL);
if (!cpu_addr_buffer)
return CC_REE_FIPS_ERROR_GENERAL;
FIPS_DBG("allocated coherent buffer - addr 0x%08X , size = %d \n", (size_t)cpu_addr_buffer, alloc_buff_size);
#if FIPS_POWER_UP_TEST_CIPHER
FIPS_DBG("ssi_cipher_fips_power_up_tests ...\n");
fips_error = ssi_cipher_fips_power_up_tests(drvdata, cpu_addr_buffer, dma_handle);
FIPS_DBG("ssi_cipher_fips_power_up_tests - done. (fips_error = %d) \n", fips_error);
#endif
#if FIPS_POWER_UP_TEST_CMAC
if (likely(fips_error == CC_REE_FIPS_ERROR_OK)) {
FIPS_DBG("ssi_cmac_fips_power_up_tests ...\n");
fips_error = ssi_cmac_fips_power_up_tests(drvdata, cpu_addr_buffer, dma_handle);
FIPS_DBG("ssi_cmac_fips_power_up_tests - done. (fips_error = %d) \n", fips_error);
}
#endif
#if FIPS_POWER_UP_TEST_HASH
if (likely(fips_error == CC_REE_FIPS_ERROR_OK)) {
FIPS_DBG("ssi_hash_fips_power_up_tests ...\n");
fips_error = ssi_hash_fips_power_up_tests(drvdata, cpu_addr_buffer, dma_handle);
FIPS_DBG("ssi_hash_fips_power_up_tests - done. (fips_error = %d) \n", fips_error);
}
#endif
#if FIPS_POWER_UP_TEST_HMAC
if (likely(fips_error == CC_REE_FIPS_ERROR_OK)) {
FIPS_DBG("ssi_hmac_fips_power_up_tests ...\n");
fips_error = ssi_hmac_fips_power_up_tests(drvdata, cpu_addr_buffer, dma_handle);
FIPS_DBG("ssi_hmac_fips_power_up_tests - done. (fips_error = %d) \n", fips_error);
}
#endif
#if FIPS_POWER_UP_TEST_CCM
if (likely(fips_error == CC_REE_FIPS_ERROR_OK)) {
FIPS_DBG("ssi_ccm_fips_power_up_tests ...\n");
fips_error = ssi_ccm_fips_power_up_tests(drvdata, cpu_addr_buffer, dma_handle);
FIPS_DBG("ssi_ccm_fips_power_up_tests - done. (fips_error = %d) \n", fips_error);
}
#endif
#if FIPS_POWER_UP_TEST_GCM
if (likely(fips_error == CC_REE_FIPS_ERROR_OK)) {
FIPS_DBG("ssi_gcm_fips_power_up_tests ...\n");
fips_error = ssi_gcm_fips_power_up_tests(drvdata, cpu_addr_buffer, dma_handle);
FIPS_DBG("ssi_gcm_fips_power_up_tests - done. (fips_error = %d) \n", fips_error);
}
#endif
FIPS_DBG("dma_free_coherent \n");
dma_free_coherent(dev, alloc_buff_size, cpu_addr_buffer, dma_handle);
return fips_error;
}
int ssi_fips_check_fips_error(void)
{
enum cc_fips_state_t fips_state;
if (ssi_fips_get_state(&fips_state) != 0) {
FIPS_LOG("ssi_fips_get_state FAILED, returning.. \n");
return -ENOEXEC;
}
if (fips_state == CC_FIPS_STATE_ERROR) {
FIPS_LOG("ssi_fips_get_state: fips_state is %d, returning.. \n", fips_state);
return -ENOEXEC;
}
return 0;
}
int ssi_fips_set_state(enum cc_fips_state_t state)
{
return ssi_fips_ext_set_state(state);
}
int ssi_fips_set_error(struct ssi_drvdata *p_drvdata, enum cc_fips_error err)
{
int rc = 0;
enum cc_fips_error current_err;
FIPS_LOG("ssi_fips_set_error - fips_error = %d \n", err);
if (err == CC_REE_FIPS_ERROR_OK)
return -ENOEXEC;
if (ssi_fips_get_error(&current_err) != 0)
return -ENOEXEC;
if (current_err != CC_REE_FIPS_ERROR_OK)
return -ENOEXEC;
rc = ssi_fips_ext_set_error(err);
if (rc != 0)
return -ENOEXEC;
rc = ssi_fips_ext_set_state(CC_FIPS_STATE_ERROR);
if (rc != 0)
return -ENOEXEC;
if (err != CC_REE_FIPS_ERROR_FROM_TEE)
ssi_fips_update_tee_upon_ree_status(p_drvdata, err);
return rc;
}
int ssi_fips_init(struct ssi_drvdata *p_drvdata)
{
enum cc_fips_error rc = CC_REE_FIPS_ERROR_OK;
struct ssi_fips_handle *fips_h;
FIPS_DBG("CC FIPS code .. (fips=%d) \n", ssi_fips_support);
fips_h = kzalloc(sizeof(struct ssi_fips_handle), GFP_KERNEL);
if (!fips_h) {
ssi_fips_set_error(p_drvdata, CC_REE_FIPS_ERROR_GENERAL);
return -ENOMEM;
}
p_drvdata->fips_handle = fips_h;
#ifdef COMP_IN_WQ
SSI_LOG_DEBUG("Initializing fips workqueue\n");
fips_h->workq = create_singlethread_workqueue("arm_cc7x_fips_wq");
if (unlikely(!fips_h->workq)) {
SSI_LOG_ERR("Failed creating fips work queue\n");
ssi_fips_set_error(p_drvdata, CC_REE_FIPS_ERROR_GENERAL);
rc = -ENOMEM;
goto ssi_fips_init_err;
}
INIT_DELAYED_WORK(&fips_h->fipswork, fips_wq_handler);
#else
SSI_LOG_DEBUG("Initializing fips tasklet\n");
tasklet_init(&fips_h->fipstask, fips_dsr, (unsigned long)p_drvdata);
#endif
rc = ssi_fips_set_state((ssi_fips_support == 0) ? CC_FIPS_STATE_NOT_SUPPORTED : CC_FIPS_STATE_SUPPORTED);
if (unlikely(rc != 0)) {
ssi_fips_set_error(p_drvdata, CC_REE_FIPS_ERROR_GENERAL);
rc = -EAGAIN;
goto ssi_fips_init_err;
}
FIPS_DBG("ssi_fips_get_tee_error \n");
rc = ssi_fips_get_tee_error(p_drvdata);
if (unlikely(rc != CC_REE_FIPS_ERROR_OK)) {
ssi_fips_set_error(p_drvdata, CC_REE_FIPS_ERROR_FROM_TEE);
rc = -EAGAIN;
goto ssi_fips_init_err;
}
FIPS_DBG("cc_fips_run_power_up_tests \n");
rc = cc_fips_run_power_up_tests(p_drvdata);
if (unlikely(rc != CC_REE_FIPS_ERROR_OK)) {
ssi_fips_set_error(p_drvdata, rc);
rc = -EAGAIN;
goto ssi_fips_init_err;
}
FIPS_LOG("cc_fips_run_power_up_tests - done ... fips_error = %d \n", rc);
ssi_fips_update_tee_upon_ree_status(p_drvdata, CC_REE_FIPS_ERROR_OK);
if (unlikely(rc != 0)) {
rc = -EAGAIN;
ssi_fips_set_error(p_drvdata, CC_REE_FIPS_ERROR_GENERAL);
goto ssi_fips_init_err;
}
return 0;
ssi_fips_init_err:
ssi_fips_fini(p_drvdata);
return rc;
}
