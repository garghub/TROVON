static int afu_control(struct cxl_afu *afu, u64 command,
u64 result, u64 mask, bool enabled)
{
u64 AFU_Cntl = cxl_p2n_read(afu, CXL_AFU_Cntl_An);
unsigned long timeout = jiffies + (HZ * CXL_TIMEOUT);
int rc = 0;
spin_lock(&afu->afu_cntl_lock);
pr_devel("AFU command starting: %llx\n", command);
trace_cxl_afu_ctrl(afu, command);
cxl_p2n_write(afu, CXL_AFU_Cntl_An, AFU_Cntl | command);
AFU_Cntl = cxl_p2n_read(afu, CXL_AFU_Cntl_An);
while ((AFU_Cntl & mask) != result) {
if (time_after_eq(jiffies, timeout)) {
dev_warn(&afu->dev, "WARNING: AFU control timed out!\n");
rc = -EBUSY;
goto out;
}
if (!cxl_ops->link_ok(afu->adapter, afu)) {
afu->enabled = enabled;
rc = -EIO;
goto out;
}
pr_devel_ratelimited("AFU control... (0x%016llx)\n",
AFU_Cntl | command);
cpu_relax();
AFU_Cntl = cxl_p2n_read(afu, CXL_AFU_Cntl_An);
};
pr_devel("AFU command complete: %llx\n", command);
afu->enabled = enabled;
out:
trace_cxl_afu_ctrl_done(afu, command, rc);
spin_unlock(&afu->afu_cntl_lock);
return rc;
}
static int afu_enable(struct cxl_afu *afu)
{
pr_devel("AFU enable request\n");
return afu_control(afu, CXL_AFU_Cntl_An_E,
CXL_AFU_Cntl_An_ES_Enabled,
CXL_AFU_Cntl_An_ES_MASK, true);
}
int cxl_afu_disable(struct cxl_afu *afu)
{
pr_devel("AFU disable request\n");
return afu_control(afu, 0, CXL_AFU_Cntl_An_ES_Disabled,
CXL_AFU_Cntl_An_ES_MASK, false);
}
static int native_afu_reset(struct cxl_afu *afu)
{
pr_devel("AFU reset request\n");
return afu_control(afu, CXL_AFU_Cntl_An_RA,
CXL_AFU_Cntl_An_RS_Complete | CXL_AFU_Cntl_An_ES_Disabled,
CXL_AFU_Cntl_An_RS_MASK | CXL_AFU_Cntl_An_ES_MASK,
false);
}
static int native_afu_check_and_enable(struct cxl_afu *afu)
{
if (!cxl_ops->link_ok(afu->adapter, afu)) {
WARN(1, "Refusing to enable afu while link down!\n");
return -EIO;
}
if (afu->enabled)
return 0;
return afu_enable(afu);
}
int cxl_psl_purge(struct cxl_afu *afu)
{
u64 PSL_CNTL = cxl_p1n_read(afu, CXL_PSL_SCNTL_An);
u64 AFU_Cntl = cxl_p2n_read(afu, CXL_AFU_Cntl_An);
u64 dsisr, dar;
u64 start, end;
unsigned long timeout = jiffies + (HZ * CXL_TIMEOUT);
int rc = 0;
trace_cxl_psl_ctrl(afu, CXL_PSL_SCNTL_An_Pc);
pr_devel("PSL purge request\n");
if (!cxl_ops->link_ok(afu->adapter, afu)) {
dev_warn(&afu->dev, "PSL Purge called with link down, ignoring\n");
rc = -EIO;
goto out;
}
if ((AFU_Cntl & CXL_AFU_Cntl_An_ES_MASK) != CXL_AFU_Cntl_An_ES_Disabled) {
WARN(1, "psl_purge request while AFU not disabled!\n");
cxl_afu_disable(afu);
}
cxl_p1n_write(afu, CXL_PSL_SCNTL_An,
PSL_CNTL | CXL_PSL_SCNTL_An_Pc);
start = local_clock();
PSL_CNTL = cxl_p1n_read(afu, CXL_PSL_SCNTL_An);
while ((PSL_CNTL & CXL_PSL_SCNTL_An_Ps_MASK)
== CXL_PSL_SCNTL_An_Ps_Pending) {
if (time_after_eq(jiffies, timeout)) {
dev_warn(&afu->dev, "WARNING: PSL Purge timed out!\n");
rc = -EBUSY;
goto out;
}
if (!cxl_ops->link_ok(afu->adapter, afu)) {
rc = -EIO;
goto out;
}
dsisr = cxl_p2n_read(afu, CXL_PSL_DSISR_An);
pr_devel_ratelimited("PSL purging... PSL_CNTL: 0x%016llx PSL_DSISR: 0x%016llx\n", PSL_CNTL, dsisr);
if (dsisr & CXL_PSL_DSISR_TRANS) {
dar = cxl_p2n_read(afu, CXL_PSL_DAR_An);
dev_notice(&afu->dev, "PSL purge terminating pending translation, DSISR: 0x%016llx, DAR: 0x%016llx\n", dsisr, dar);
cxl_p2n_write(afu, CXL_PSL_TFC_An, CXL_PSL_TFC_An_AE);
} else if (dsisr) {
dev_notice(&afu->dev, "PSL purge acknowledging pending non-translation fault, DSISR: 0x%016llx\n", dsisr);
cxl_p2n_write(afu, CXL_PSL_TFC_An, CXL_PSL_TFC_An_A);
} else {
cpu_relax();
}
PSL_CNTL = cxl_p1n_read(afu, CXL_PSL_SCNTL_An);
};
end = local_clock();
pr_devel("PSL purged in %lld ns\n", end - start);
cxl_p1n_write(afu, CXL_PSL_SCNTL_An,
PSL_CNTL & ~CXL_PSL_SCNTL_An_Pc);
out:
trace_cxl_psl_ctrl_done(afu, CXL_PSL_SCNTL_An_Pc, rc);
return rc;
}
static int spa_max_procs(int spa_size)
{
return ((spa_size / 8) - 96) / 17;
}
int cxl_alloc_spa(struct cxl_afu *afu)
{
unsigned spa_size;
afu->native->spa_order = 0;
do {
afu->native->spa_order++;
spa_size = (1 << afu->native->spa_order) * PAGE_SIZE;
if (spa_size > 0x100000) {
dev_warn(&afu->dev, "num_of_processes too large for the SPA, limiting to %i (0x%x)\n",
afu->native->spa_max_procs, afu->native->spa_size);
afu->num_procs = afu->native->spa_max_procs;
break;
}
afu->native->spa_size = spa_size;
afu->native->spa_max_procs = spa_max_procs(afu->native->spa_size);
} while (afu->native->spa_max_procs < afu->num_procs);
if (!(afu->native->spa = (struct cxl_process_element *)
__get_free_pages(GFP_KERNEL | __GFP_ZERO, afu->native->spa_order))) {
pr_err("cxl_alloc_spa: Unable to allocate scheduled process area\n");
return -ENOMEM;
}
pr_devel("spa pages: %i afu->spa_max_procs: %i afu->num_procs: %i\n",
1<<afu->native->spa_order, afu->native->spa_max_procs, afu->num_procs);
return 0;
}
static void attach_spa(struct cxl_afu *afu)
{
u64 spap;
afu->native->sw_command_status = (__be64 *)((char *)afu->native->spa +
((afu->native->spa_max_procs + 3) * 128));
spap = virt_to_phys(afu->native->spa) & CXL_PSL_SPAP_Addr;
spap |= ((afu->native->spa_size >> (12 - CXL_PSL_SPAP_Size_Shift)) - 1) & CXL_PSL_SPAP_Size;
spap |= CXL_PSL_SPAP_V;
pr_devel("cxl: SPA allocated at 0x%p. Max processes: %i, sw_command_status: 0x%p CXL_PSL_SPAP_An=0x%016llx\n",
afu->native->spa, afu->native->spa_max_procs,
afu->native->sw_command_status, spap);
cxl_p1n_write(afu, CXL_PSL_SPAP_An, spap);
}
static inline void detach_spa(struct cxl_afu *afu)
{
cxl_p1n_write(afu, CXL_PSL_SPAP_An, 0);
}
void cxl_release_spa(struct cxl_afu *afu)
{
if (afu->native->spa) {
free_pages((unsigned long) afu->native->spa,
afu->native->spa_order);
afu->native->spa = NULL;
}
}
int cxl_tlb_slb_invalidate(struct cxl *adapter)
{
unsigned long timeout = jiffies + (HZ * CXL_TIMEOUT);
pr_devel("CXL adapter wide TLBIA & SLBIA\n");
cxl_p1_write(adapter, CXL_PSL_AFUSEL, CXL_PSL_AFUSEL_A);
cxl_p1_write(adapter, CXL_PSL_TLBIA, CXL_TLB_SLB_IQ_ALL);
while (cxl_p1_read(adapter, CXL_PSL_TLBIA) & CXL_TLB_SLB_P) {
if (time_after_eq(jiffies, timeout)) {
dev_warn(&adapter->dev, "WARNING: CXL adapter wide TLBIA timed out!\n");
return -EBUSY;
}
if (!cxl_ops->link_ok(adapter, NULL))
return -EIO;
cpu_relax();
}
cxl_p1_write(adapter, CXL_PSL_SLBIA, CXL_TLB_SLB_IQ_ALL);
while (cxl_p1_read(adapter, CXL_PSL_SLBIA) & CXL_TLB_SLB_P) {
if (time_after_eq(jiffies, timeout)) {
dev_warn(&adapter->dev, "WARNING: CXL adapter wide SLBIA timed out!\n");
return -EBUSY;
}
if (!cxl_ops->link_ok(adapter, NULL))
return -EIO;
cpu_relax();
}
return 0;
}
static int cxl_write_sstp(struct cxl_afu *afu, u64 sstp0, u64 sstp1)
{
int rc;
cxl_p2n_write(afu, CXL_SSTP1_An, 0);
if ((rc = cxl_afu_slbia(afu)))
return rc;
cxl_p2n_write(afu, CXL_SSTP0_An, sstp0);
cxl_p2n_write(afu, CXL_SSTP1_An, sstp1);
return 0;
}
static void slb_invalid(struct cxl_context *ctx)
{
struct cxl *adapter = ctx->afu->adapter;
u64 slbia;
WARN_ON(!mutex_is_locked(&ctx->afu->native->spa_mutex));
cxl_p1_write(adapter, CXL_PSL_LBISEL,
((u64)be32_to_cpu(ctx->elem->common.pid) << 32) |
be32_to_cpu(ctx->elem->lpid));
cxl_p1_write(adapter, CXL_PSL_SLBIA, CXL_TLB_SLB_IQ_LPIDPID);
while (1) {
if (!cxl_ops->link_ok(adapter, NULL))
break;
slbia = cxl_p1_read(adapter, CXL_PSL_SLBIA);
if (!(slbia & CXL_TLB_SLB_P))
break;
cpu_relax();
}
}
static int do_process_element_cmd(struct cxl_context *ctx,
u64 cmd, u64 pe_state)
{
u64 state;
unsigned long timeout = jiffies + (HZ * CXL_TIMEOUT);
int rc = 0;
trace_cxl_llcmd(ctx, cmd);
WARN_ON(!ctx->afu->enabled);
ctx->elem->software_state = cpu_to_be32(pe_state);
smp_wmb();
*(ctx->afu->native->sw_command_status) = cpu_to_be64(cmd | 0 | ctx->pe);
smp_mb();
cxl_p1n_write(ctx->afu, CXL_PSL_LLCMD_An, cmd | ctx->pe);
while (1) {
if (time_after_eq(jiffies, timeout)) {
dev_warn(&ctx->afu->dev, "WARNING: Process Element Command timed out!\n");
rc = -EBUSY;
goto out;
}
if (!cxl_ops->link_ok(ctx->afu->adapter, ctx->afu)) {
dev_warn(&ctx->afu->dev, "WARNING: Device link down, aborting Process Element Command!\n");
rc = -EIO;
goto out;
}
state = be64_to_cpup(ctx->afu->native->sw_command_status);
if (state == ~0ULL) {
pr_err("cxl: Error adding process element to AFU\n");
rc = -1;
goto out;
}
if ((state & (CXL_SPA_SW_CMD_MASK | CXL_SPA_SW_STATE_MASK | CXL_SPA_SW_LINK_MASK)) ==
(cmd | (cmd >> 16) | ctx->pe))
break;
schedule();
}
out:
trace_cxl_llcmd_done(ctx, cmd, rc);
return rc;
}
static int add_process_element(struct cxl_context *ctx)
{
int rc = 0;
mutex_lock(&ctx->afu->native->spa_mutex);
pr_devel("%s Adding pe: %i started\n", __func__, ctx->pe);
if (!(rc = do_process_element_cmd(ctx, CXL_SPA_SW_CMD_ADD, CXL_PE_SOFTWARE_STATE_V)))
ctx->pe_inserted = true;
pr_devel("%s Adding pe: %i finished\n", __func__, ctx->pe);
mutex_unlock(&ctx->afu->native->spa_mutex);
return rc;
}
static int terminate_process_element(struct cxl_context *ctx)
{
int rc = 0;
if (!(ctx->elem->software_state & cpu_to_be32(CXL_PE_SOFTWARE_STATE_V)))
return rc;
mutex_lock(&ctx->afu->native->spa_mutex);
pr_devel("%s Terminate pe: %i started\n", __func__, ctx->pe);
if (cxl_ops->link_ok(ctx->afu->adapter, ctx->afu))
rc = do_process_element_cmd(ctx, CXL_SPA_SW_CMD_TERMINATE,
CXL_PE_SOFTWARE_STATE_V | CXL_PE_SOFTWARE_STATE_T);
ctx->elem->software_state = 0;
pr_devel("%s Terminate pe: %i finished\n", __func__, ctx->pe);
mutex_unlock(&ctx->afu->native->spa_mutex);
return rc;
}
static int remove_process_element(struct cxl_context *ctx)
{
int rc = 0;
mutex_lock(&ctx->afu->native->spa_mutex);
pr_devel("%s Remove pe: %i started\n", __func__, ctx->pe);
if (cxl_ops->link_ok(ctx->afu->adapter, ctx->afu))
rc = do_process_element_cmd(ctx, CXL_SPA_SW_CMD_REMOVE, 0);
if (!rc)
ctx->pe_inserted = false;
slb_invalid(ctx);
pr_devel("%s Remove pe: %i finished\n", __func__, ctx->pe);
mutex_unlock(&ctx->afu->native->spa_mutex);
return rc;
}
void cxl_assign_psn_space(struct cxl_context *ctx)
{
if (!ctx->afu->pp_size || ctx->master) {
ctx->psn_phys = ctx->afu->psn_phys;
ctx->psn_size = ctx->afu->adapter->ps_size;
} else {
ctx->psn_phys = ctx->afu->psn_phys +
(ctx->afu->native->pp_offset + ctx->afu->pp_size * ctx->pe);
ctx->psn_size = ctx->afu->pp_size;
}
}
static int activate_afu_directed(struct cxl_afu *afu)
{
int rc;
dev_info(&afu->dev, "Activating AFU directed mode\n");
afu->num_procs = afu->max_procs_virtualised;
if (afu->native->spa == NULL) {
if (cxl_alloc_spa(afu))
return -ENOMEM;
}
attach_spa(afu);
cxl_p1n_write(afu, CXL_PSL_SCNTL_An, CXL_PSL_SCNTL_An_PM_AFU);
cxl_p1n_write(afu, CXL_PSL_AMOR_An, 0xFFFFFFFFFFFFFFFFULL);
cxl_p1n_write(afu, CXL_PSL_ID_An, CXL_PSL_ID_An_F | CXL_PSL_ID_An_L);
afu->current_mode = CXL_MODE_DIRECTED;
if ((rc = cxl_chardev_m_afu_add(afu)))
return rc;
if ((rc = cxl_sysfs_afu_m_add(afu)))
goto err;
if ((rc = cxl_chardev_s_afu_add(afu)))
goto err1;
return 0;
err1:
cxl_sysfs_afu_m_remove(afu);
err:
cxl_chardev_afu_remove(afu);
return rc;
}
static u64 calculate_sr(struct cxl_context *ctx)
{
u64 sr = 0;
set_endian(sr);
if (ctx->master)
sr |= CXL_PSL_SR_An_MP;
if (mfspr(SPRN_LPCR) & LPCR_TC)
sr |= CXL_PSL_SR_An_TC;
if (ctx->kernel) {
if (!ctx->real_mode)
sr |= CXL_PSL_SR_An_R;
sr |= (mfmsr() & MSR_SF) | CXL_PSL_SR_An_HV;
} else {
sr |= CXL_PSL_SR_An_PR | CXL_PSL_SR_An_R;
sr &= ~(CXL_PSL_SR_An_HV);
if (!test_tsk_thread_flag(current, TIF_32BIT))
sr |= CXL_PSL_SR_An_SF;
}
return sr;
}
static int attach_afu_directed(struct cxl_context *ctx, u64 wed, u64 amr)
{
u32 pid;
int r, result;
cxl_assign_psn_space(ctx);
ctx->elem->ctxtime = 0;
ctx->elem->lpid = cpu_to_be32(mfspr(SPRN_LPID));
ctx->elem->haurp = 0;
ctx->elem->sdr = cpu_to_be64(mfspr(SPRN_SDR1));
pid = current->pid;
if (ctx->kernel)
pid = 0;
ctx->elem->common.tid = 0;
ctx->elem->common.pid = cpu_to_be32(pid);
ctx->elem->sr = cpu_to_be64(calculate_sr(ctx));
ctx->elem->common.csrp = 0;
ctx->elem->common.aurp0 = 0;
ctx->elem->common.aurp1 = 0;
cxl_prefault(ctx, wed);
ctx->elem->common.sstp0 = cpu_to_be64(ctx->sstp0);
ctx->elem->common.sstp1 = cpu_to_be64(ctx->sstp1);
if (ctx->irqs.range[0] == 0) {
ctx->irqs.offset[0] = ctx->afu->native->psl_hwirq;
ctx->irqs.range[0] = 1;
}
for (r = 0; r < CXL_IRQ_RANGES; r++) {
ctx->elem->ivte_offsets[r] = cpu_to_be16(ctx->irqs.offset[r]);
ctx->elem->ivte_ranges[r] = cpu_to_be16(ctx->irqs.range[r]);
}
ctx->elem->common.amr = cpu_to_be64(amr);
ctx->elem->common.wed = cpu_to_be64(wed);
if ((result = cxl_ops->afu_check_and_enable(ctx->afu)))
return result;
return add_process_element(ctx);
}
static int deactivate_afu_directed(struct cxl_afu *afu)
{
dev_info(&afu->dev, "Deactivating AFU directed mode\n");
afu->current_mode = 0;
afu->num_procs = 0;
cxl_sysfs_afu_m_remove(afu);
cxl_chardev_afu_remove(afu);
cxl_ops->afu_reset(afu);
cxl_afu_disable(afu);
cxl_psl_purge(afu);
return 0;
}
static int activate_dedicated_process(struct cxl_afu *afu)
{
dev_info(&afu->dev, "Activating dedicated process mode\n");
cxl_p1n_write(afu, CXL_PSL_SCNTL_An, CXL_PSL_SCNTL_An_PM_Process);
cxl_p1n_write(afu, CXL_PSL_CtxTime_An, 0);
cxl_p1n_write(afu, CXL_PSL_SPAP_An, 0);
cxl_p1n_write(afu, CXL_PSL_AMOR_An, 0xFFFFFFFFFFFFFFFFULL);
cxl_p1n_write(afu, CXL_PSL_LPID_An, mfspr(SPRN_LPID));
cxl_p1n_write(afu, CXL_HAURP_An, 0);
cxl_p1n_write(afu, CXL_PSL_SDR_An, mfspr(SPRN_SDR1));
cxl_p2n_write(afu, CXL_CSRP_An, 0);
cxl_p2n_write(afu, CXL_AURP0_An, 0);
cxl_p2n_write(afu, CXL_AURP1_An, 0);
afu->current_mode = CXL_MODE_DEDICATED;
afu->num_procs = 1;
return cxl_chardev_d_afu_add(afu);
}
static int attach_dedicated(struct cxl_context *ctx, u64 wed, u64 amr)
{
struct cxl_afu *afu = ctx->afu;
u64 pid;
int rc;
pid = (u64)current->pid << 32;
if (ctx->kernel)
pid = 0;
cxl_p2n_write(afu, CXL_PSL_PID_TID_An, pid);
cxl_p1n_write(afu, CXL_PSL_SR_An, calculate_sr(ctx));
if ((rc = cxl_write_sstp(afu, ctx->sstp0, ctx->sstp1)))
return rc;
cxl_prefault(ctx, wed);
cxl_p1n_write(afu, CXL_PSL_IVTE_Offset_An,
(((u64)ctx->irqs.offset[0] & 0xffff) << 48) |
(((u64)ctx->irqs.offset[1] & 0xffff) << 32) |
(((u64)ctx->irqs.offset[2] & 0xffff) << 16) |
((u64)ctx->irqs.offset[3] & 0xffff));
cxl_p1n_write(afu, CXL_PSL_IVTE_Limit_An, (u64)
(((u64)ctx->irqs.range[0] & 0xffff) << 48) |
(((u64)ctx->irqs.range[1] & 0xffff) << 32) |
(((u64)ctx->irqs.range[2] & 0xffff) << 16) |
((u64)ctx->irqs.range[3] & 0xffff));
cxl_p2n_write(afu, CXL_PSL_AMR_An, amr);
cxl_assign_psn_space(ctx);
if ((rc = cxl_ops->afu_reset(afu)))
return rc;
cxl_p2n_write(afu, CXL_PSL_WED_An, wed);
return afu_enable(afu);
}
static int deactivate_dedicated_process(struct cxl_afu *afu)
{
dev_info(&afu->dev, "Deactivating dedicated process mode\n");
afu->current_mode = 0;
afu->num_procs = 0;
cxl_chardev_afu_remove(afu);
return 0;
}
static int native_afu_deactivate_mode(struct cxl_afu *afu, int mode)
{
if (mode == CXL_MODE_DIRECTED)
return deactivate_afu_directed(afu);
if (mode == CXL_MODE_DEDICATED)
return deactivate_dedicated_process(afu);
return 0;
}
static int native_afu_activate_mode(struct cxl_afu *afu, int mode)
{
if (!mode)
return 0;
if (!(mode & afu->modes_supported))
return -EINVAL;
if (!cxl_ops->link_ok(afu->adapter, afu)) {
WARN(1, "Device link is down, refusing to activate!\n");
return -EIO;
}
if (mode == CXL_MODE_DIRECTED)
return activate_afu_directed(afu);
if (mode == CXL_MODE_DEDICATED)
return activate_dedicated_process(afu);
return -EINVAL;
}
static int native_attach_process(struct cxl_context *ctx, bool kernel,
u64 wed, u64 amr)
{
if (!cxl_ops->link_ok(ctx->afu->adapter, ctx->afu)) {
WARN(1, "Device link is down, refusing to attach process!\n");
return -EIO;
}
ctx->kernel = kernel;
if (ctx->afu->current_mode == CXL_MODE_DIRECTED)
return attach_afu_directed(ctx, wed, amr);
if (ctx->afu->current_mode == CXL_MODE_DEDICATED)
return attach_dedicated(ctx, wed, amr);
return -EINVAL;
}
static inline int detach_process_native_dedicated(struct cxl_context *ctx)
{
cxl_ops->afu_reset(ctx->afu);
cxl_afu_disable(ctx->afu);
cxl_psl_purge(ctx->afu);
return 0;
}
static inline int detach_process_native_afu_directed(struct cxl_context *ctx)
{
if (!ctx->pe_inserted)
return 0;
if (terminate_process_element(ctx))
return -1;
if (remove_process_element(ctx))
return -1;
return 0;
}
static int native_detach_process(struct cxl_context *ctx)
{
trace_cxl_detach(ctx);
if (ctx->afu->current_mode == CXL_MODE_DEDICATED)
return detach_process_native_dedicated(ctx);
return detach_process_native_afu_directed(ctx);
}
static int native_get_irq_info(struct cxl_afu *afu, struct cxl_irq_info *info)
{
u64 pidtid;
if (!cxl_ops->link_ok(afu->adapter, afu))
return -EIO;
info->dsisr = cxl_p2n_read(afu, CXL_PSL_DSISR_An);
info->dar = cxl_p2n_read(afu, CXL_PSL_DAR_An);
info->dsr = cxl_p2n_read(afu, CXL_PSL_DSR_An);
pidtid = cxl_p2n_read(afu, CXL_PSL_PID_TID_An);
info->pid = pidtid >> 32;
info->tid = pidtid & 0xffffffff;
info->afu_err = cxl_p2n_read(afu, CXL_AFU_ERR_An);
info->errstat = cxl_p2n_read(afu, CXL_PSL_ErrStat_An);
info->proc_handle = 0;
return 0;
}
static irqreturn_t native_handle_psl_slice_error(struct cxl_context *ctx,
u64 dsisr, u64 errstat)
{
u64 fir1, fir2, fir_slice, serr, afu_debug;
fir1 = cxl_p1_read(ctx->afu->adapter, CXL_PSL_FIR1);
fir2 = cxl_p1_read(ctx->afu->adapter, CXL_PSL_FIR2);
fir_slice = cxl_p1n_read(ctx->afu, CXL_PSL_FIR_SLICE_An);
serr = cxl_p1n_read(ctx->afu, CXL_PSL_SERR_An);
afu_debug = cxl_p1n_read(ctx->afu, CXL_AFU_DEBUG_An);
dev_crit(&ctx->afu->dev, "PSL ERROR STATUS: 0x%016llx\n", errstat);
dev_crit(&ctx->afu->dev, "PSL_FIR1: 0x%016llx\n", fir1);
dev_crit(&ctx->afu->dev, "PSL_FIR2: 0x%016llx\n", fir2);
dev_crit(&ctx->afu->dev, "PSL_SERR_An: 0x%016llx\n", serr);
dev_crit(&ctx->afu->dev, "PSL_FIR_SLICE_An: 0x%016llx\n", fir_slice);
dev_crit(&ctx->afu->dev, "CXL_PSL_AFU_DEBUG_An: 0x%016llx\n", afu_debug);
dev_crit(&ctx->afu->dev, "STOPPING CXL TRACE\n");
cxl_stop_trace(ctx->afu->adapter);
return cxl_ops->ack_irq(ctx, 0, errstat);
}
static irqreturn_t fail_psl_irq(struct cxl_afu *afu, struct cxl_irq_info *irq_info)
{
if (irq_info->dsisr & CXL_PSL_DSISR_TRANS)
cxl_p2n_write(afu, CXL_PSL_TFC_An, CXL_PSL_TFC_An_AE);
else
cxl_p2n_write(afu, CXL_PSL_TFC_An, CXL_PSL_TFC_An_A);
return IRQ_HANDLED;
}
static irqreturn_t native_irq_multiplexed(int irq, void *data)
{
struct cxl_afu *afu = data;
struct cxl_context *ctx;
struct cxl_irq_info irq_info;
int ph = cxl_p2n_read(afu, CXL_PSL_PEHandle_An) & 0xffff;
int ret;
if ((ret = native_get_irq_info(afu, &irq_info))) {
WARN(1, "Unable to get CXL IRQ Info: %i\n", ret);
return fail_psl_irq(afu, &irq_info);
}
rcu_read_lock();
ctx = idr_find(&afu->contexts_idr, ph);
if (ctx) {
ret = cxl_irq(irq, ctx, &irq_info);
rcu_read_unlock();
return ret;
}
rcu_read_unlock();
WARN(1, "Unable to demultiplex CXL PSL IRQ for PE %i DSISR %016llx DAR"
" %016llx\n(Possible AFU HW issue - was a term/remove acked"
" with outstanding transactions?)\n", ph, irq_info.dsisr,
irq_info.dar);
return fail_psl_irq(afu, &irq_info);
}
void native_irq_wait(struct cxl_context *ctx)
{
u64 dsisr;
int timeout = 1000;
int ph;
while (timeout--) {
ph = cxl_p2n_read(ctx->afu, CXL_PSL_PEHandle_An) & 0xffff;
if (ph != ctx->pe)
return;
dsisr = cxl_p2n_read(ctx->afu, CXL_PSL_DSISR_An);
if ((dsisr & CXL_PSL_DSISR_PENDING) == 0)
return;
msleep(1);
}
dev_warn(&ctx->afu->dev, "WARNING: waiting on DSI for PE %i"
" DSISR %016llx!\n", ph, dsisr);
return;
}
static irqreturn_t native_slice_irq_err(int irq, void *data)
{
struct cxl_afu *afu = data;
u64 fir_slice, errstat, serr, afu_debug;
WARN(irq, "CXL SLICE ERROR interrupt %i\n", irq);
serr = cxl_p1n_read(afu, CXL_PSL_SERR_An);
fir_slice = cxl_p1n_read(afu, CXL_PSL_FIR_SLICE_An);
errstat = cxl_p2n_read(afu, CXL_PSL_ErrStat_An);
afu_debug = cxl_p1n_read(afu, CXL_AFU_DEBUG_An);
dev_crit(&afu->dev, "PSL_SERR_An: 0x%016llx\n", serr);
dev_crit(&afu->dev, "PSL_FIR_SLICE_An: 0x%016llx\n", fir_slice);
dev_crit(&afu->dev, "CXL_PSL_ErrStat_An: 0x%016llx\n", errstat);
dev_crit(&afu->dev, "CXL_PSL_AFU_DEBUG_An: 0x%016llx\n", afu_debug);
cxl_p1n_write(afu, CXL_PSL_SERR_An, serr);
return IRQ_HANDLED;
}
static irqreturn_t native_irq_err(int irq, void *data)
{
struct cxl *adapter = data;
u64 fir1, fir2, err_ivte;
WARN(1, "CXL ERROR interrupt %i\n", irq);
err_ivte = cxl_p1_read(adapter, CXL_PSL_ErrIVTE);
dev_crit(&adapter->dev, "PSL_ErrIVTE: 0x%016llx\n", err_ivte);
dev_crit(&adapter->dev, "STOPPING CXL TRACE\n");
cxl_stop_trace(adapter);
fir1 = cxl_p1_read(adapter, CXL_PSL_FIR1);
fir2 = cxl_p1_read(adapter, CXL_PSL_FIR2);
dev_crit(&adapter->dev, "PSL_FIR1: 0x%016llx\nPSL_FIR2: 0x%016llx\n", fir1, fir2);
return IRQ_HANDLED;
}
int cxl_native_register_psl_err_irq(struct cxl *adapter)
{
int rc;
adapter->irq_name = kasprintf(GFP_KERNEL, "cxl-%s-err",
dev_name(&adapter->dev));
if (!adapter->irq_name)
return -ENOMEM;
if ((rc = cxl_register_one_irq(adapter, native_irq_err, adapter,
&adapter->native->err_hwirq,
&adapter->native->err_virq,
adapter->irq_name))) {
kfree(adapter->irq_name);
adapter->irq_name = NULL;
return rc;
}
cxl_p1_write(adapter, CXL_PSL_ErrIVTE, adapter->native->err_hwirq & 0xffff);
return 0;
}
void cxl_native_release_psl_err_irq(struct cxl *adapter)
{
if (adapter->native->err_virq != irq_find_mapping(NULL, adapter->native->err_hwirq))
return;
cxl_p1_write(adapter, CXL_PSL_ErrIVTE, 0x0000000000000000);
cxl_unmap_irq(adapter->native->err_virq, adapter);
cxl_ops->release_one_irq(adapter, adapter->native->err_hwirq);
kfree(adapter->irq_name);
}
int cxl_native_register_serr_irq(struct cxl_afu *afu)
{
u64 serr;
int rc;
afu->err_irq_name = kasprintf(GFP_KERNEL, "cxl-%s-err",
dev_name(&afu->dev));
if (!afu->err_irq_name)
return -ENOMEM;
if ((rc = cxl_register_one_irq(afu->adapter, native_slice_irq_err, afu,
&afu->serr_hwirq,
&afu->serr_virq, afu->err_irq_name))) {
kfree(afu->err_irq_name);
afu->err_irq_name = NULL;
return rc;
}
serr = cxl_p1n_read(afu, CXL_PSL_SERR_An);
serr = (serr & 0x00ffffffffff0000ULL) | (afu->serr_hwirq & 0xffff);
cxl_p1n_write(afu, CXL_PSL_SERR_An, serr);
return 0;
}
void cxl_native_release_serr_irq(struct cxl_afu *afu)
{
if (afu->serr_virq != irq_find_mapping(NULL, afu->serr_hwirq))
return;
cxl_p1n_write(afu, CXL_PSL_SERR_An, 0x0000000000000000);
cxl_unmap_irq(afu->serr_virq, afu);
cxl_ops->release_one_irq(afu->adapter, afu->serr_hwirq);
kfree(afu->err_irq_name);
}
int cxl_native_register_psl_irq(struct cxl_afu *afu)
{
int rc;
afu->psl_irq_name = kasprintf(GFP_KERNEL, "cxl-%s",
dev_name(&afu->dev));
if (!afu->psl_irq_name)
return -ENOMEM;
if ((rc = cxl_register_one_irq(afu->adapter, native_irq_multiplexed,
afu, &afu->native->psl_hwirq, &afu->native->psl_virq,
afu->psl_irq_name))) {
kfree(afu->psl_irq_name);
afu->psl_irq_name = NULL;
}
return rc;
}
void cxl_native_release_psl_irq(struct cxl_afu *afu)
{
if (afu->native->psl_virq != irq_find_mapping(NULL, afu->native->psl_hwirq))
return;
cxl_unmap_irq(afu->native->psl_virq, afu);
cxl_ops->release_one_irq(afu->adapter, afu->native->psl_hwirq);
kfree(afu->psl_irq_name);
}
static void recover_psl_err(struct cxl_afu *afu, u64 errstat)
{
u64 dsisr;
pr_devel("RECOVERING FROM PSL ERROR... (0x%016llx)\n", errstat);
dsisr = cxl_p2n_read(afu, CXL_PSL_DSISR_An);
cxl_p2n_write(afu, CXL_PSL_DSISR_An, dsisr & ~CXL_PSL_DSISR_An_PE);
cxl_p2n_write(afu, CXL_PSL_ErrStat_An, errstat);
}
static int native_ack_irq(struct cxl_context *ctx, u64 tfc, u64 psl_reset_mask)
{
trace_cxl_psl_irq_ack(ctx, tfc);
if (tfc)
cxl_p2n_write(ctx->afu, CXL_PSL_TFC_An, tfc);
if (psl_reset_mask)
recover_psl_err(ctx->afu, psl_reset_mask);
return 0;
}
int cxl_check_error(struct cxl_afu *afu)
{
return (cxl_p1n_read(afu, CXL_PSL_SCNTL_An) == ~0ULL);
}
static bool native_support_attributes(const char *attr_name,
enum cxl_attrs type)
{
return true;
}
static int native_afu_cr_read64(struct cxl_afu *afu, int cr, u64 off, u64 *out)
{
if (unlikely(!cxl_ops->link_ok(afu->adapter, afu)))
return -EIO;
if (unlikely(off >= afu->crs_len))
return -ERANGE;
*out = in_le64(afu->native->afu_desc_mmio + afu->crs_offset +
(cr * afu->crs_len) + off);
return 0;
}
static int native_afu_cr_read32(struct cxl_afu *afu, int cr, u64 off, u32 *out)
{
if (unlikely(!cxl_ops->link_ok(afu->adapter, afu)))
return -EIO;
if (unlikely(off >= afu->crs_len))
return -ERANGE;
*out = in_le32(afu->native->afu_desc_mmio + afu->crs_offset +
(cr * afu->crs_len) + off);
return 0;
}
static int native_afu_cr_read16(struct cxl_afu *afu, int cr, u64 off, u16 *out)
{
u64 aligned_off = off & ~0x3L;
u32 val;
int rc;
rc = native_afu_cr_read32(afu, cr, aligned_off, &val);
if (!rc)
*out = (val >> ((off & 0x3) * 8)) & 0xffff;
return rc;
}
static int native_afu_cr_read8(struct cxl_afu *afu, int cr, u64 off, u8 *out)
{
u64 aligned_off = off & ~0x3L;
u32 val;
int rc;
rc = native_afu_cr_read32(afu, cr, aligned_off, &val);
if (!rc)
*out = (val >> ((off & 0x3) * 8)) & 0xff;
return rc;
}
static int native_afu_cr_write32(struct cxl_afu *afu, int cr, u64 off, u32 in)
{
if (unlikely(!cxl_ops->link_ok(afu->adapter, afu)))
return -EIO;
if (unlikely(off >= afu->crs_len))
return -ERANGE;
out_le32(afu->native->afu_desc_mmio + afu->crs_offset +
(cr * afu->crs_len) + off, in);
return 0;
}
static int native_afu_cr_write16(struct cxl_afu *afu, int cr, u64 off, u16 in)
{
u64 aligned_off = off & ~0x3L;
u32 val32, mask, shift;
int rc;
rc = native_afu_cr_read32(afu, cr, aligned_off, &val32);
if (rc)
return rc;
shift = (off & 0x3) * 8;
WARN_ON(shift == 24);
mask = 0xffff << shift;
val32 = (val32 & ~mask) | (in << shift);
rc = native_afu_cr_write32(afu, cr, aligned_off, val32);
return rc;
}
static int native_afu_cr_write8(struct cxl_afu *afu, int cr, u64 off, u8 in)
{
u64 aligned_off = off & ~0x3L;
u32 val32, mask, shift;
int rc;
rc = native_afu_cr_read32(afu, cr, aligned_off, &val32);
if (rc)
return rc;
shift = (off & 0x3) * 8;
mask = 0xff << shift;
val32 = (val32 & ~mask) | (in << shift);
rc = native_afu_cr_write32(afu, cr, aligned_off, val32);
return rc;
}
