static struct genwqe_dev *genwqe_dev_alloc(void)
{
unsigned int i = 0, j;
struct genwqe_dev *cd;
for (i = 0; i < GENWQE_CARD_NO_MAX; i++) {
if (genwqe_devices[i] == NULL)
break;
}
if (i >= GENWQE_CARD_NO_MAX)
return ERR_PTR(-ENODEV);
cd = kzalloc(sizeof(struct genwqe_dev), GFP_KERNEL);
if (!cd)
return ERR_PTR(-ENOMEM);
cd->card_idx = i;
cd->class_genwqe = class_genwqe;
cd->debugfs_genwqe = debugfs_genwqe;
init_waitqueue_head(&cd->queue_waitq);
spin_lock_init(&cd->file_lock);
INIT_LIST_HEAD(&cd->file_list);
cd->card_state = GENWQE_CARD_UNUSED;
spin_lock_init(&cd->print_lock);
cd->ddcb_software_timeout = genwqe_ddcb_software_timeout;
cd->kill_timeout = genwqe_kill_timeout;
for (j = 0; j < GENWQE_MAX_VFS; j++)
cd->vf_jobtimeout_msec[j] = genwqe_vf_jobtimeout_msec;
genwqe_devices[i] = cd;
return cd;
}
static void genwqe_dev_free(struct genwqe_dev *cd)
{
if (!cd)
return;
genwqe_devices[cd->card_idx] = NULL;
kfree(cd);
}
static int genwqe_bus_reset(struct genwqe_dev *cd)
{
int bars, rc = 0;
struct pci_dev *pci_dev = cd->pci_dev;
void __iomem *mmio;
if (cd->err_inject & GENWQE_INJECT_BUS_RESET_FAILURE)
return -EIO;
mmio = cd->mmio;
cd->mmio = NULL;
pci_iounmap(pci_dev, mmio);
bars = pci_select_bars(pci_dev, IORESOURCE_MEM);
pci_release_selected_regions(pci_dev, bars);
dev_dbg(&pci_dev->dev, "[%s] pci_reset function ...\n", __func__);
rc = pci_reset_function(pci_dev);
if (rc) {
dev_err(&pci_dev->dev,
"[%s] err: failed reset func (rc %d)\n", __func__, rc);
return rc;
}
dev_dbg(&pci_dev->dev, "[%s] done with rc=%d\n", __func__, rc);
cd->err_inject &= ~(GENWQE_INJECT_HARDWARE_FAILURE |
GENWQE_INJECT_GFIR_FATAL |
GENWQE_INJECT_GFIR_INFO);
rc = pci_request_selected_regions(pci_dev, bars, genwqe_driver_name);
if (rc) {
dev_err(&pci_dev->dev,
"[%s] err: request bars failed (%d)\n", __func__, rc);
return -EIO;
}
cd->mmio = pci_iomap(pci_dev, 0, 0);
if (cd->mmio == NULL) {
dev_err(&pci_dev->dev,
"[%s] err: mapping BAR0 failed\n", __func__);
return -ENOMEM;
}
return 0;
}
bool genwqe_need_err_masking(struct genwqe_dev *cd)
{
return (cd->slu_unitcfg & 0xFFFF0ull) < 0x32170ull;
}
static void genwqe_tweak_hardware(struct genwqe_dev *cd)
{
struct pci_dev *pci_dev = cd->pci_dev;
if (((cd->slu_unitcfg & 0xFFFF0ull) >= 0x32000ull) &&
((cd->slu_unitcfg & 0xFFFF0ull) <= 0x33250ull)) {
dev_warn(&pci_dev->dev,
"FIRs masked due to bitstream %016llx.%016llx\n",
cd->slu_unitcfg, cd->app_unitcfg);
__genwqe_writeq(cd, IO_APP_SEC_LEM_DEBUG_OVR,
0xFFFFFFFFFFFFFFFFull);
__genwqe_writeq(cd, IO_APP_ERR_ACT_MASK,
0x0000000000000000ull);
}
}
int genwqe_recovery_on_fatal_gfir_required(struct genwqe_dev *cd)
{
return (cd->slu_unitcfg & 0xFFFF0ull) >= 0x32170ull;
}
int genwqe_flash_readback_fails(struct genwqe_dev *cd)
{
return (cd->slu_unitcfg & 0xFFFF0ull) < 0x32170ull;
}
static int genwqe_T_psec(struct genwqe_dev *cd)
{
u16 speed;
static const int T[] = { 4000, 5000, 6000, 5714 };
speed = (u16)((cd->slu_unitcfg >> 28) & 0x0full);
if (speed >= ARRAY_SIZE(T))
return -1;
return T[speed];
}
static bool genwqe_setup_pf_jtimer(struct genwqe_dev *cd)
{
u32 T = genwqe_T_psec(cd);
u64 x;
if (genwqe_pf_jobtimeout_msec == 0)
return false;
x = ilog2(genwqe_pf_jobtimeout_msec *
16000000000uL/(T * 15)) - 10;
genwqe_write_vreg(cd, IO_SLC_VF_APPJOB_TIMEOUT,
0xff00 | (x & 0xff), 0);
return true;
}
static bool genwqe_setup_vf_jtimer(struct genwqe_dev *cd)
{
struct pci_dev *pci_dev = cd->pci_dev;
unsigned int vf;
u32 T = genwqe_T_psec(cd);
u64 x;
for (vf = 0; vf < pci_sriov_get_totalvfs(pci_dev); vf++) {
if (cd->vf_jobtimeout_msec[vf] == 0)
continue;
x = ilog2(cd->vf_jobtimeout_msec[vf] *
16000000000uL/(T * 15)) - 10;
genwqe_write_vreg(cd, IO_SLC_VF_APPJOB_TIMEOUT,
0xff00 | (x & 0xff), vf + 1);
}
return true;
}
static int genwqe_ffdc_buffs_alloc(struct genwqe_dev *cd)
{
unsigned int type, e = 0;
for (type = 0; type < GENWQE_DBG_UNITS; type++) {
switch (type) {
case GENWQE_DBG_UNIT0:
e = genwqe_ffdc_buff_size(cd, 0);
break;
case GENWQE_DBG_UNIT1:
e = genwqe_ffdc_buff_size(cd, 1);
break;
case GENWQE_DBG_UNIT2:
e = genwqe_ffdc_buff_size(cd, 2);
break;
case GENWQE_DBG_REGS:
e = GENWQE_FFDC_REGS;
break;
}
cd->ffdc[type].entries = e;
cd->ffdc[type].regs = kmalloc(e * sizeof(struct genwqe_reg),
GFP_KERNEL);
}
return 0;
}
static void genwqe_ffdc_buffs_free(struct genwqe_dev *cd)
{
unsigned int type;
for (type = 0; type < GENWQE_DBG_UNITS; type++) {
kfree(cd->ffdc[type].regs);
cd->ffdc[type].regs = NULL;
}
}
static int genwqe_read_ids(struct genwqe_dev *cd)
{
int err = 0;
int slu_id;
struct pci_dev *pci_dev = cd->pci_dev;
cd->slu_unitcfg = __genwqe_readq(cd, IO_SLU_UNITCFG);
if (cd->slu_unitcfg == IO_ILLEGAL_VALUE) {
dev_err(&pci_dev->dev,
"err: SLUID=%016llx\n", cd->slu_unitcfg);
err = -EIO;
goto out_err;
}
slu_id = genwqe_get_slu_id(cd);
if (slu_id < GENWQE_SLU_ARCH_REQ || slu_id == 0xff) {
dev_err(&pci_dev->dev,
"err: incompatible SLU Architecture %u\n", slu_id);
err = -ENOENT;
goto out_err;
}
cd->app_unitcfg = __genwqe_readq(cd, IO_APP_UNITCFG);
if (cd->app_unitcfg == IO_ILLEGAL_VALUE) {
dev_err(&pci_dev->dev,
"err: APPID=%016llx\n", cd->app_unitcfg);
err = -EIO;
goto out_err;
}
genwqe_read_app_id(cd, cd->app_name, sizeof(cd->app_name));
if (pci_dev->is_virtfn)
cd->is_privileged = 0;
else
cd->is_privileged = (__genwqe_readq(cd, IO_SLU_BITSTREAM)
!= IO_ILLEGAL_VALUE);
out_err:
return err;
}
static int genwqe_start(struct genwqe_dev *cd)
{
int err;
struct pci_dev *pci_dev = cd->pci_dev;
err = genwqe_read_ids(cd);
if (err)
return err;
if (genwqe_is_privileged(cd)) {
genwqe_ffdc_buffs_alloc(cd);
genwqe_stop_traps(cd);
genwqe_read_ffdc_regs(cd, cd->ffdc[GENWQE_DBG_REGS].regs,
cd->ffdc[GENWQE_DBG_REGS].entries, 0);
genwqe_ffdc_buff_read(cd, GENWQE_DBG_UNIT0,
cd->ffdc[GENWQE_DBG_UNIT0].regs,
cd->ffdc[GENWQE_DBG_UNIT0].entries);
genwqe_ffdc_buff_read(cd, GENWQE_DBG_UNIT1,
cd->ffdc[GENWQE_DBG_UNIT1].regs,
cd->ffdc[GENWQE_DBG_UNIT1].entries);
genwqe_ffdc_buff_read(cd, GENWQE_DBG_UNIT2,
cd->ffdc[GENWQE_DBG_UNIT2].regs,
cd->ffdc[GENWQE_DBG_UNIT2].entries);
genwqe_start_traps(cd);
if (cd->card_state == GENWQE_CARD_FATAL_ERROR) {
dev_warn(&pci_dev->dev,
"[%s] chip reload/recovery!\n", __func__);
cd->softreset = 0x7Cull;
__genwqe_writeq(cd, IO_SLC_CFGREG_SOFTRESET,
cd->softreset);
err = genwqe_bus_reset(cd);
if (err != 0) {
dev_err(&pci_dev->dev,
"[%s] err: bus reset failed!\n",
__func__);
goto out;
}
err = genwqe_read_ids(cd);
if (err)
goto out;
}
}
err = genwqe_setup_service_layer(cd);
if (err != 0) {
dev_err(&pci_dev->dev,
"[%s] err: could not setup servicelayer!\n", __func__);
err = -ENODEV;
goto out;
}
if (genwqe_is_privileged(cd)) {
genwqe_tweak_hardware(cd);
genwqe_setup_pf_jtimer(cd);
genwqe_setup_vf_jtimer(cd);
}
err = genwqe_device_create(cd);
if (err < 0) {
dev_err(&pci_dev->dev,
"err: chdev init failed! (err=%d)\n", err);
goto out_release_service_layer;
}
return 0;
out_release_service_layer:
genwqe_release_service_layer(cd);
out:
if (genwqe_is_privileged(cd))
genwqe_ffdc_buffs_free(cd);
return -EIO;
}
static int genwqe_stop(struct genwqe_dev *cd)
{
genwqe_finish_queue(cd);
genwqe_device_remove(cd);
genwqe_release_service_layer(cd);
if (genwqe_is_privileged(cd)) {
pci_disable_sriov(cd->pci_dev);
genwqe_ffdc_buffs_free(cd);
}
return 0;
}
static int genwqe_recover_card(struct genwqe_dev *cd, int fatal_err)
{
int rc;
struct pci_dev *pci_dev = cd->pci_dev;
genwqe_stop(cd);
if (!fatal_err) {
cd->softreset = 0x70ull;
__genwqe_writeq(cd, IO_SLC_CFGREG_SOFTRESET, cd->softreset);
}
rc = genwqe_bus_reset(cd);
if (rc != 0) {
dev_err(&pci_dev->dev,
"[%s] err: card recovery impossible!\n", __func__);
return rc;
}
rc = genwqe_start(cd);
if (rc < 0) {
dev_err(&pci_dev->dev,
"[%s] err: failed to launch device!\n", __func__);
return rc;
}
return 0;
}
static int genwqe_health_check_cond(struct genwqe_dev *cd, u64 *gfir)
{
*gfir = __genwqe_readq(cd, IO_SLC_CFGREG_GFIR);
return (*gfir & GFIR_ERR_TRIGGER) &&
genwqe_recovery_on_fatal_gfir_required(cd);
}
static u64 genwqe_fir_checking(struct genwqe_dev *cd)
{
int j, iterations = 0;
u64 mask, fir, fec, uid, gfir, gfir_masked, sfir, sfec;
u32 fir_addr, fir_clr_addr, fec_addr, sfir_addr, sfec_addr;
struct pci_dev *pci_dev = cd->pci_dev;
healthMonitor:
iterations++;
if (iterations > 16) {
dev_err(&pci_dev->dev, "* exit looping after %d times\n",
iterations);
goto fatal_error;
}
gfir = __genwqe_readq(cd, IO_SLC_CFGREG_GFIR);
if (gfir != 0x0)
dev_err(&pci_dev->dev, "* 0x%08x 0x%016llx\n",
IO_SLC_CFGREG_GFIR, gfir);
if (gfir == IO_ILLEGAL_VALUE)
goto fatal_error;
if (gfir == 0)
return 0;
gfir_masked = gfir & GFIR_ERR_TRIGGER;
for (uid = 0; uid < GENWQE_MAX_UNITS; uid++) {
fir_addr = (uid << 24) + 0x08;
fir = __genwqe_readq(cd, fir_addr);
if (fir == 0x0)
continue;
dev_err(&pci_dev->dev, "* 0x%08x 0x%016llx\n", fir_addr, fir);
if (fir == IO_ILLEGAL_VALUE)
goto fatal_error;
fec_addr = (uid << 24) + 0x18;
fec = __genwqe_readq(cd, fec_addr);
dev_err(&pci_dev->dev, "* 0x%08x 0x%016llx\n", fec_addr, fec);
if (fec == IO_ILLEGAL_VALUE)
goto fatal_error;
for (j = 0, mask = 1ULL; j < 64; j++, mask <<= 1) {
if ((fir & mask) == 0x0)
continue;
sfir_addr = (uid << 24) + 0x100 + 0x08 * j;
sfir = __genwqe_readq(cd, sfir_addr);
if (sfir == IO_ILLEGAL_VALUE)
goto fatal_error;
dev_err(&pci_dev->dev,
"* 0x%08x 0x%016llx\n", sfir_addr, sfir);
sfec_addr = (uid << 24) + 0x300 + 0x08 * j;
sfec = __genwqe_readq(cd, sfec_addr);
if (sfec == IO_ILLEGAL_VALUE)
goto fatal_error;
dev_err(&pci_dev->dev,
"* 0x%08x 0x%016llx\n", sfec_addr, sfec);
gfir = __genwqe_readq(cd, IO_SLC_CFGREG_GFIR);
if (gfir == IO_ILLEGAL_VALUE)
goto fatal_error;
if ((gfir_masked == 0x0) &&
(gfir & GFIR_ERR_TRIGGER)) {
goto healthMonitor;
}
if (gfir_masked == 0x0) {
sfir_addr = (uid << 24) + 0x100 + 0x08 * j;
__genwqe_writeq(cd, sfir_addr, sfir);
dev_dbg(&pci_dev->dev,
"[HM] Clearing 2ndary FIR 0x%08x "
"with 0x%016llx\n", sfir_addr, sfir);
fir_clr_addr = (uid << 24) + 0x10;
__genwqe_writeq(cd, fir_clr_addr, mask);
dev_dbg(&pci_dev->dev,
"[HM] Clearing primary FIR 0x%08x "
"with 0x%016llx\n", fir_clr_addr,
mask);
}
}
}
gfir = __genwqe_readq(cd, IO_SLC_CFGREG_GFIR);
if (gfir == IO_ILLEGAL_VALUE)
goto fatal_error;
if ((gfir_masked == 0x0) && (gfir & GFIR_ERR_TRIGGER)) {
dev_dbg(&pci_dev->dev, "ACK! Another FIR! Recursing %d!\n",
iterations);
goto healthMonitor;
}
return gfir_masked;
fatal_error:
return IO_ILLEGAL_VALUE;
}
static int genwqe_health_thread(void *data)
{
int rc, should_stop = 0;
struct genwqe_dev *cd = data;
struct pci_dev *pci_dev = cd->pci_dev;
u64 gfir, gfir_masked, slu_unitcfg, app_unitcfg;
while (!kthread_should_stop()) {
rc = wait_event_interruptible_timeout(cd->health_waitq,
(genwqe_health_check_cond(cd, &gfir) ||
(should_stop = kthread_should_stop())),
genwqe_health_check_interval * HZ);
if (should_stop)
break;
if (gfir == IO_ILLEGAL_VALUE) {
dev_err(&pci_dev->dev,
"[%s] GFIR=%016llx\n", __func__, gfir);
goto fatal_error;
}
slu_unitcfg = __genwqe_readq(cd, IO_SLU_UNITCFG);
if (slu_unitcfg == IO_ILLEGAL_VALUE) {
dev_err(&pci_dev->dev,
"[%s] SLU_UNITCFG=%016llx\n",
__func__, slu_unitcfg);
goto fatal_error;
}
app_unitcfg = __genwqe_readq(cd, IO_APP_UNITCFG);
if (app_unitcfg == IO_ILLEGAL_VALUE) {
dev_err(&pci_dev->dev,
"[%s] APP_UNITCFG=%016llx\n",
__func__, app_unitcfg);
goto fatal_error;
}
gfir = __genwqe_readq(cd, IO_SLC_CFGREG_GFIR);
if (gfir == IO_ILLEGAL_VALUE) {
dev_err(&pci_dev->dev,
"[%s] %s: GFIR=%016llx\n", __func__,
(gfir & GFIR_ERR_TRIGGER) ? "err" : "info",
gfir);
goto fatal_error;
}
gfir_masked = genwqe_fir_checking(cd);
if (gfir_masked == IO_ILLEGAL_VALUE)
goto fatal_error;
if ((gfir_masked) && !cd->skip_recovery &&
genwqe_recovery_on_fatal_gfir_required(cd)) {
cd->card_state = GENWQE_CARD_FATAL_ERROR;
rc = genwqe_recover_card(cd, 0);
if (rc < 0) {
goto fatal_error;
}
}
cd->last_gfir = gfir;
cond_resched();
}
return 0;
fatal_error:
dev_err(&pci_dev->dev,
"[%s] card unusable. Please trigger unbind!\n", __func__);
cd->card_state = GENWQE_CARD_FATAL_ERROR;
genwqe_stop(cd);
while (!kthread_should_stop())
cond_resched();
return -EIO;
}
static int genwqe_health_check_start(struct genwqe_dev *cd)
{
int rc;
if (genwqe_health_check_interval <= 0)
return 0;
cd->health_thread = kthread_run(genwqe_health_thread, cd,
GENWQE_DEVNAME "%d_health",
cd->card_idx);
if (IS_ERR(cd->health_thread)) {
rc = PTR_ERR(cd->health_thread);
cd->health_thread = NULL;
return rc;
}
return 0;
}
static int genwqe_health_thread_running(struct genwqe_dev *cd)
{
return cd->health_thread != NULL;
}
static int genwqe_health_check_stop(struct genwqe_dev *cd)
{
int rc;
if (!genwqe_health_thread_running(cd))
return -EIO;
rc = kthread_stop(cd->health_thread);
cd->health_thread = NULL;
return 0;
}
static int genwqe_pci_setup(struct genwqe_dev *cd)
{
int err, bars;
struct pci_dev *pci_dev = cd->pci_dev;
bars = pci_select_bars(pci_dev, IORESOURCE_MEM);
err = pci_enable_device_mem(pci_dev);
if (err) {
dev_err(&pci_dev->dev,
"err: failed to enable pci memory (err=%d)\n", err);
goto err_out;
}
err = pci_request_selected_regions(pci_dev, bars, genwqe_driver_name);
if (err) {
dev_err(&pci_dev->dev,
"[%s] err: request bars failed (%d)\n", __func__, err);
err = -EIO;
goto err_disable_device;
}
if (!pci_set_dma_mask(pci_dev, DMA_BIT_MASK(64))) {
err = pci_set_consistent_dma_mask(pci_dev, DMA_BIT_MASK(64));
if (err) {
dev_err(&pci_dev->dev,
"err: DMA64 consistent mask error\n");
err = -EIO;
goto out_release_resources;
}
} else if (!pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32))) {
err = pci_set_consistent_dma_mask(pci_dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pci_dev->dev,
"err: DMA32 consistent mask error\n");
err = -EIO;
goto out_release_resources;
}
} else {
dev_err(&pci_dev->dev,
"err: neither DMA32 nor DMA64 supported\n");
err = -EIO;
goto out_release_resources;
}
pci_set_master(pci_dev);
pci_enable_pcie_error_reporting(pci_dev);
cd->mmio_len = pci_resource_len(pci_dev, 0);
cd->mmio = pci_iomap(pci_dev, 0, 0);
if (cd->mmio == NULL) {
dev_err(&pci_dev->dev,
"[%s] err: mapping BAR0 failed\n", __func__);
err = -ENOMEM;
goto out_release_resources;
}
cd->num_vfs = pci_sriov_get_totalvfs(pci_dev);
err = genwqe_read_ids(cd);
if (err)
goto out_iounmap;
return 0;
out_iounmap:
pci_iounmap(pci_dev, cd->mmio);
out_release_resources:
pci_release_selected_regions(pci_dev, bars);
err_disable_device:
pci_disable_device(pci_dev);
err_out:
return err;
}
static void genwqe_pci_remove(struct genwqe_dev *cd)
{
int bars;
struct pci_dev *pci_dev = cd->pci_dev;
if (cd->mmio)
pci_iounmap(pci_dev, cd->mmio);
bars = pci_select_bars(pci_dev, IORESOURCE_MEM);
pci_release_selected_regions(pci_dev, bars);
pci_disable_device(pci_dev);
}
static int genwqe_probe(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
int err;
struct genwqe_dev *cd;
genwqe_init_crc32();
cd = genwqe_dev_alloc();
if (IS_ERR(cd)) {
dev_err(&pci_dev->dev, "err: could not alloc mem (err=%d)!\n",
(int)PTR_ERR(cd));
return PTR_ERR(cd);
}
dev_set_drvdata(&pci_dev->dev, cd);
cd->pci_dev = pci_dev;
err = genwqe_pci_setup(cd);
if (err < 0) {
dev_err(&pci_dev->dev,
"err: problems with PCI setup (err=%d)\n", err);
goto out_free_dev;
}
err = genwqe_start(cd);
if (err < 0) {
dev_err(&pci_dev->dev,
"err: cannot start card services! (err=%d)\n", err);
goto out_pci_remove;
}
if (genwqe_is_privileged(cd)) {
err = genwqe_health_check_start(cd);
if (err < 0) {
dev_err(&pci_dev->dev,
"err: cannot start health checking! "
"(err=%d)\n", err);
goto out_stop_services;
}
}
return 0;
out_stop_services:
genwqe_stop(cd);
out_pci_remove:
genwqe_pci_remove(cd);
out_free_dev:
genwqe_dev_free(cd);
return err;
}
static void genwqe_remove(struct pci_dev *pci_dev)
{
struct genwqe_dev *cd = dev_get_drvdata(&pci_dev->dev);
genwqe_health_check_stop(cd);
genwqe_stop(cd);
genwqe_pci_remove(cd);
genwqe_dev_free(cd);
}
static pci_ers_result_t genwqe_err_error_detected(struct pci_dev *pci_dev,
enum pci_channel_state state)
{
struct genwqe_dev *cd;
dev_err(&pci_dev->dev, "[%s] state=%d\n", __func__, state);
if (pci_dev == NULL)
return PCI_ERS_RESULT_NEED_RESET;
cd = dev_get_drvdata(&pci_dev->dev);
if (cd == NULL)
return PCI_ERS_RESULT_NEED_RESET;
switch (state) {
case pci_channel_io_normal:
return PCI_ERS_RESULT_CAN_RECOVER;
case pci_channel_io_frozen:
return PCI_ERS_RESULT_NEED_RESET;
case pci_channel_io_perm_failure:
return PCI_ERS_RESULT_DISCONNECT;
}
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t genwqe_err_result_none(struct pci_dev *dev)
{
return PCI_ERS_RESULT_NONE;
}
static void genwqe_err_resume(struct pci_dev *dev)
{
}
static int genwqe_sriov_configure(struct pci_dev *dev, int numvfs)
{
struct genwqe_dev *cd = dev_get_drvdata(&dev->dev);
if (numvfs > 0) {
genwqe_setup_vf_jtimer(cd);
pci_enable_sriov(dev, numvfs);
return numvfs;
}
if (numvfs == 0) {
pci_disable_sriov(dev);
return 0;
}
return 0;
}
static int __init genwqe_init_module(void)
{
int rc;
class_genwqe = class_create(THIS_MODULE, GENWQE_DEVNAME);
if (IS_ERR(class_genwqe)) {
pr_err("[%s] create class failed\n", __func__);
return -ENOMEM;
}
debugfs_genwqe = debugfs_create_dir(GENWQE_DEVNAME, NULL);
if (!debugfs_genwqe) {
rc = -ENOMEM;
goto err_out;
}
rc = pci_register_driver(&genwqe_driver);
if (rc != 0) {
pr_err("[%s] pci_reg_driver (rc=%d)\n", __func__, rc);
goto err_out0;
}
return rc;
err_out0:
debugfs_remove(debugfs_genwqe);
err_out:
class_destroy(class_genwqe);
return rc;
}
static void __exit genwqe_exit_module(void)
{
pci_unregister_driver(&genwqe_driver);
debugfs_remove(debugfs_genwqe);
class_destroy(class_genwqe);
}
