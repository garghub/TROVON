static bool cc_get_tee_fips_status(struct ssi_drvdata *drvdata)
{
u32 reg;
void __iomem *cc_base = drvdata->cc_base;
reg = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, GPR_HOST));
return (reg == (CC_FIPS_SYNC_TEE_STATUS | CC_FIPS_SYNC_MODULE_OK));
}
void cc_set_ree_fips_status(struct ssi_drvdata *drvdata, bool status)
{
void __iomem *cc_base = drvdata->cc_base;
int val = CC_FIPS_SYNC_REE_STATUS;
val |= (status ? CC_FIPS_SYNC_MODULE_OK : CC_FIPS_SYNC_MODULE_ERROR);
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_GPR0), val);
}
void ssi_fips_fini(struct ssi_drvdata *drvdata)
{
struct ssi_fips_handle *fips_h = drvdata->fips_handle;
if (!fips_h)
return;
tasklet_kill(&fips_h->tasklet);
kfree(fips_h);
drvdata->fips_handle = NULL;
}
void fips_handler(struct ssi_drvdata *drvdata)
{
struct ssi_fips_handle *fips_handle_ptr =
drvdata->fips_handle;
tasklet_schedule(&fips_handle_ptr->tasklet);
}
static inline void tee_fips_error(void)
{
if (fips_enabled)
panic("ccree: TEE reported cryptographic error in fips mode!\n");
else
SSI_LOG_ERR("TEE reported error!\n");
}
static void fips_dsr(unsigned long devarg)
{
struct ssi_drvdata *drvdata = (struct ssi_drvdata *)devarg;
void __iomem *cc_base = drvdata->cc_base;
u32 irq, state, val;
irq = (drvdata->irq & (SSI_GPR0_IRQ_MASK));
if (irq) {
state = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, GPR_HOST));
if (state != (CC_FIPS_SYNC_TEE_STATUS | CC_FIPS_SYNC_MODULE_OK))
tee_fips_error();
}
val = (CC_REG_OFFSET(HOST_RGF, HOST_IMR) & ~irq);
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR), val);
}
int ssi_fips_init(struct ssi_drvdata *p_drvdata)
{
struct ssi_fips_handle *fips_h;
fips_h = kzalloc(sizeof(*fips_h), GFP_KERNEL);
if (!fips_h)
return -ENOMEM;
p_drvdata->fips_handle = fips_h;
SSI_LOG_DEBUG("Initializing fips tasklet\n");
tasklet_init(&fips_h->tasklet, fips_dsr, (unsigned long)p_drvdata);
if (!cc_get_tee_fips_status(p_drvdata))
tee_fips_error();
return 0;
}
