static void
bfa_ioc_sm_uninit_entry(struct bfa_ioc_s *ioc)
{
}
static void
bfa_ioc_sm_uninit(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_RESET:
bfa_fsm_set_state(ioc, bfa_ioc_sm_reset);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_reset_entry(struct bfa_ioc_s *ioc)
{
bfa_fsm_set_state(&ioc->iocpf, bfa_iocpf_sm_reset);
}
static void
bfa_ioc_sm_reset(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_ENABLE:
bfa_fsm_set_state(ioc, bfa_ioc_sm_enabling);
break;
case IOC_E_DISABLE:
bfa_ioc_disable_comp(ioc);
break;
case IOC_E_DETACH:
bfa_fsm_set_state(ioc, bfa_ioc_sm_uninit);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_enabling_entry(struct bfa_ioc_s *ioc)
{
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_ENABLE);
}
static void
bfa_ioc_sm_enabling(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_ENABLED:
bfa_fsm_set_state(ioc, bfa_ioc_sm_getattr);
break;
case IOC_E_PFFAILED:
case IOC_E_HWERROR:
ioc->cbfn->enable_cbfn(ioc->bfa, BFA_STATUS_IOC_FAILURE);
bfa_fsm_set_state(ioc, bfa_ioc_sm_fail_retry);
if (event != IOC_E_PFFAILED)
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_INITFAIL);
break;
case IOC_E_DISABLE:
bfa_fsm_set_state(ioc, bfa_ioc_sm_disabling);
break;
case IOC_E_DETACH:
bfa_fsm_set_state(ioc, bfa_ioc_sm_uninit);
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_STOP);
break;
case IOC_E_ENABLE:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_getattr_entry(struct bfa_ioc_s *ioc)
{
bfa_ioc_timer_start(ioc);
bfa_ioc_send_getattr(ioc);
}
static void
bfa_ioc_sm_getattr(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_FWRSP_GETATTR:
bfa_ioc_timer_stop(ioc);
bfa_ioc_check_attr_wwns(ioc);
bfa_fsm_set_state(ioc, bfa_ioc_sm_op);
break;
break;
case IOC_E_PFFAILED:
case IOC_E_HWERROR:
bfa_ioc_timer_stop(ioc);
case IOC_E_TIMEOUT:
ioc->cbfn->enable_cbfn(ioc->bfa, BFA_STATUS_IOC_FAILURE);
bfa_fsm_set_state(ioc, bfa_ioc_sm_fail_retry);
if (event != IOC_E_PFFAILED)
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_GETATTRFAIL);
break;
case IOC_E_DISABLE:
bfa_ioc_timer_stop(ioc);
bfa_fsm_set_state(ioc, bfa_ioc_sm_disabling);
break;
case IOC_E_ENABLE:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_op_entry(struct bfa_ioc_s *ioc)
{
struct bfad_s *bfad = (struct bfad_s *)ioc->bfa->bfad;
ioc->cbfn->enable_cbfn(ioc->bfa, BFA_STATUS_OK);
bfa_ioc_hb_monitor(ioc);
BFA_LOG(KERN_INFO, bfad, bfa_log_level, "IOC enabled\n");
}
static void
bfa_ioc_sm_op(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_ENABLE:
break;
case IOC_E_DISABLE:
bfa_hb_timer_stop(ioc);
bfa_fsm_set_state(ioc, bfa_ioc_sm_disabling);
break;
case IOC_E_PFFAILED:
case IOC_E_HWERROR:
bfa_hb_timer_stop(ioc);
case IOC_E_HBFAIL:
bfa_ioc_fail_notify(ioc);
if (ioc->iocpf.auto_recover)
bfa_fsm_set_state(ioc, bfa_ioc_sm_fail_retry);
else
bfa_fsm_set_state(ioc, bfa_ioc_sm_fail);
if (event != IOC_E_PFFAILED)
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_FAIL);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_disabling_entry(struct bfa_ioc_s *ioc)
{
struct bfad_s *bfad = (struct bfad_s *)ioc->bfa->bfad;
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_DISABLE);
BFA_LOG(KERN_INFO, bfad, bfa_log_level, "IOC disabled\n");
}
static void
bfa_ioc_sm_disabling(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_DISABLED:
bfa_fsm_set_state(ioc, bfa_ioc_sm_disabled);
break;
case IOC_E_HWERROR:
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_FAIL);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_disabled_entry(struct bfa_ioc_s *ioc)
{
bfa_ioc_disable_comp(ioc);
}
static void
bfa_ioc_sm_disabled(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_ENABLE:
bfa_fsm_set_state(ioc, bfa_ioc_sm_enabling);
break;
case IOC_E_DISABLE:
ioc->cbfn->disable_cbfn(ioc->bfa);
break;
case IOC_E_DETACH:
bfa_fsm_set_state(ioc, bfa_ioc_sm_uninit);
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_STOP);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_fail_retry_entry(struct bfa_ioc_s *ioc)
{
bfa_trc(ioc, 0);
}
static void
bfa_ioc_sm_fail_retry(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_ENABLED:
bfa_fsm_set_state(ioc, bfa_ioc_sm_getattr);
break;
case IOC_E_PFFAILED:
case IOC_E_HWERROR:
ioc->cbfn->enable_cbfn(ioc->bfa, BFA_STATUS_IOC_FAILURE);
if (event != IOC_E_PFFAILED)
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_INITFAIL);
break;
case IOC_E_INITFAILED:
bfa_fsm_set_state(ioc, bfa_ioc_sm_fail);
break;
case IOC_E_ENABLE:
break;
case IOC_E_DISABLE:
bfa_fsm_set_state(ioc, bfa_ioc_sm_disabling);
break;
case IOC_E_DETACH:
bfa_fsm_set_state(ioc, bfa_ioc_sm_uninit);
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_STOP);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_sm_fail_entry(struct bfa_ioc_s *ioc)
{
bfa_trc(ioc, 0);
}
static void
bfa_ioc_sm_fail(struct bfa_ioc_s *ioc, enum ioc_event event)
{
bfa_trc(ioc, event);
switch (event) {
case IOC_E_ENABLE:
ioc->cbfn->enable_cbfn(ioc->bfa, BFA_STATUS_IOC_FAILURE);
break;
case IOC_E_DISABLE:
bfa_fsm_set_state(ioc, bfa_ioc_sm_disabling);
break;
case IOC_E_DETACH:
bfa_fsm_set_state(ioc, bfa_ioc_sm_uninit);
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_STOP);
break;
case IOC_E_HWERROR:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_reset_entry(struct bfa_iocpf_s *iocpf)
{
iocpf->retry_count = 0;
iocpf->auto_recover = bfa_auto_recover;
}
static void
bfa_iocpf_sm_reset(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_ENABLE:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_fwcheck);
break;
case IOCPF_E_STOP:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_fwcheck_entry(struct bfa_iocpf_s *iocpf)
{
bfa_ioc_hw_sem_get(iocpf->ioc);
}
static void
bfa_iocpf_sm_fwcheck(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_SEMLOCKED:
if (bfa_ioc_firmware_lock(ioc)) {
if (bfa_ioc_sync_start(ioc)) {
iocpf->retry_count = 0;
bfa_ioc_sync_join(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_hwinit);
} else {
bfa_ioc_firmware_unlock(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_sem_timer_start(ioc);
}
} else {
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_mismatch);
}
break;
case IOCPF_E_DISABLE:
bfa_sem_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
bfa_fsm_send_event(ioc, IOC_E_DISABLED);
break;
case IOCPF_E_STOP:
bfa_sem_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_mismatch_entry(struct bfa_iocpf_s *iocpf)
{
if (iocpf->retry_count == 0)
bfa_ioc_pf_fwmismatch(iocpf->ioc);
iocpf->retry_count++;
bfa_iocpf_timer_start(iocpf->ioc);
}
static void
bfa_iocpf_sm_mismatch(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_TIMEOUT:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_fwcheck);
break;
case IOCPF_E_DISABLE:
bfa_iocpf_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
bfa_fsm_send_event(ioc, IOC_E_DISABLED);
break;
case IOCPF_E_STOP:
bfa_iocpf_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_semwait_entry(struct bfa_iocpf_s *iocpf)
{
bfa_ioc_hw_sem_get(iocpf->ioc);
}
static void
bfa_iocpf_sm_semwait(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_SEMLOCKED:
if (bfa_ioc_sync_complete(ioc)) {
bfa_ioc_sync_join(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_hwinit);
} else {
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_sem_timer_start(ioc);
}
break;
case IOCPF_E_DISABLE:
bfa_sem_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling_sync);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_hwinit_entry(struct bfa_iocpf_s *iocpf)
{
bfa_iocpf_timer_start(iocpf->ioc);
bfa_ioc_hwinit(iocpf->ioc, BFA_FALSE);
}
static void
bfa_iocpf_sm_hwinit(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_FWREADY:
bfa_iocpf_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_enabling);
break;
case IOCPF_E_INITFAIL:
bfa_iocpf_timer_stop(ioc);
case IOCPF_E_TIMEOUT:
writel(1, ioc->ioc_regs.ioc_sem_reg);
if (event == IOCPF_E_TIMEOUT)
bfa_fsm_send_event(ioc, IOC_E_PFFAILED);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_initfail_sync);
break;
case IOCPF_E_DISABLE:
bfa_iocpf_timer_stop(ioc);
bfa_ioc_sync_leave(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabled);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_enabling_entry(struct bfa_iocpf_s *iocpf)
{
bfa_iocpf_timer_start(iocpf->ioc);
bfa_ioc_send_enable(iocpf->ioc);
}
static void
bfa_iocpf_sm_enabling(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_FWRSP_ENABLE:
bfa_iocpf_timer_stop(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_ready);
break;
case IOCPF_E_INITFAIL:
bfa_iocpf_timer_stop(ioc);
case IOCPF_E_TIMEOUT:
writel(1, ioc->ioc_regs.ioc_sem_reg);
if (event == IOCPF_E_TIMEOUT)
bfa_fsm_send_event(ioc, IOC_E_PFFAILED);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_initfail_sync);
break;
case IOCPF_E_DISABLE:
bfa_iocpf_timer_stop(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling);
break;
case IOCPF_E_FWREADY:
bfa_ioc_send_enable(ioc);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_ready_entry(struct bfa_iocpf_s *iocpf)
{
bfa_fsm_send_event(iocpf->ioc, IOC_E_ENABLED);
}
static void
bfa_iocpf_sm_ready(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_DISABLE:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling);
break;
case IOCPF_E_GETATTRFAIL:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_initfail_sync);
break;
case IOCPF_E_FAIL:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_fail_sync);
break;
case IOCPF_E_FWREADY:
if (bfa_ioc_is_operational(ioc)) {
bfa_fsm_send_event(ioc, IOC_E_PFFAILED);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_fail_sync);
} else {
bfa_fsm_send_event(ioc, IOC_E_PFFAILED);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_initfail_sync);
}
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_disabling_entry(struct bfa_iocpf_s *iocpf)
{
bfa_iocpf_timer_start(iocpf->ioc);
bfa_ioc_send_disable(iocpf->ioc);
}
static void
bfa_iocpf_sm_disabling(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_FWRSP_DISABLE:
case IOCPF_E_FWREADY:
bfa_iocpf_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling_sync);
break;
case IOCPF_E_FAIL:
bfa_iocpf_timer_stop(ioc);
case IOCPF_E_TIMEOUT:
writel(BFI_IOC_FAIL, ioc->ioc_regs.ioc_fwstate);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling_sync);
break;
case IOCPF_E_FWRSP_ENABLE:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_disabling_sync_entry(struct bfa_iocpf_s *iocpf)
{
bfa_ioc_hw_sem_get(iocpf->ioc);
}
static void
bfa_iocpf_sm_disabling_sync(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_SEMLOCKED:
bfa_ioc_sync_leave(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabled);
break;
case IOCPF_E_FAIL:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_disabled_entry(struct bfa_iocpf_s *iocpf)
{
bfa_fsm_send_event(iocpf->ioc, IOC_E_DISABLED);
}
static void
bfa_iocpf_sm_disabled(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_ENABLE:
iocpf->retry_count = 0;
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_semwait);
break;
case IOCPF_E_STOP:
bfa_ioc_firmware_unlock(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_initfail_sync_entry(struct bfa_iocpf_s *iocpf)
{
bfa_ioc_hw_sem_get(iocpf->ioc);
}
static void
bfa_iocpf_sm_initfail_sync(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_SEMLOCKED:
bfa_ioc_notify_fail(ioc);
bfa_ioc_sync_ack(ioc);
iocpf->retry_count++;
if (iocpf->retry_count >= BFA_IOC_HWINIT_MAX) {
bfa_ioc_sync_leave(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_initfail);
} else {
if (bfa_ioc_sync_complete(ioc))
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_hwinit);
else {
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_semwait);
}
}
break;
case IOCPF_E_DISABLE:
bfa_sem_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling_sync);
break;
case IOCPF_E_STOP:
bfa_sem_timer_stop(ioc);
bfa_ioc_firmware_unlock(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
break;
case IOCPF_E_FAIL:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_initfail_entry(struct bfa_iocpf_s *iocpf)
{
bfa_fsm_send_event(iocpf->ioc, IOC_E_INITFAILED);
}
static void
bfa_iocpf_sm_initfail(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_DISABLE:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabled);
break;
case IOCPF_E_STOP:
bfa_ioc_firmware_unlock(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_reset);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_fail_sync_entry(struct bfa_iocpf_s *iocpf)
{
bfa_ioc_lpu_stop(iocpf->ioc);
bfa_ioc_mbox_hbfail(iocpf->ioc);
bfa_ioc_hw_sem_get(iocpf->ioc);
}
static void
bfa_iocpf_sm_fail_sync(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_SEMLOCKED:
iocpf->retry_count = 0;
bfa_ioc_sync_ack(ioc);
bfa_ioc_notify_fail(ioc);
if (!iocpf->auto_recover) {
bfa_ioc_sync_leave(ioc);
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_fail);
} else {
if (bfa_ioc_sync_complete(ioc))
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_hwinit);
else {
writel(1, ioc->ioc_regs.ioc_sem_reg);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_semwait);
}
}
break;
case IOCPF_E_DISABLE:
bfa_sem_timer_stop(ioc);
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabling_sync);
break;
case IOCPF_E_FAIL:
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_iocpf_sm_fail_entry(struct bfa_iocpf_s *iocpf)
{
}
static void
bfa_iocpf_sm_fail(struct bfa_iocpf_s *iocpf, enum iocpf_event event)
{
struct bfa_ioc_s *ioc = iocpf->ioc;
bfa_trc(ioc, event);
switch (event) {
case IOCPF_E_DISABLE:
bfa_fsm_set_state(iocpf, bfa_iocpf_sm_disabled);
break;
default:
bfa_sm_fault(ioc, event);
}
}
static void
bfa_ioc_disable_comp(struct bfa_ioc_s *ioc)
{
struct list_head *qe;
struct bfa_ioc_hbfail_notify_s *notify;
ioc->cbfn->disable_cbfn(ioc->bfa);
list_for_each(qe, &ioc->hb_notify_q) {
notify = (struct bfa_ioc_hbfail_notify_s *) qe;
notify->cbfn(notify->cbarg);
}
}
bfa_boolean_t
bfa_ioc_sem_get(void __iomem *sem_reg)
{
u32 r32;
int cnt = 0;
#define BFA_SEM_SPINCNT 3000
r32 = readl(sem_reg);
while (r32 && (cnt < BFA_SEM_SPINCNT)) {
cnt++;
udelay(2);
r32 = readl(sem_reg);
}
if (r32 == 0)
return BFA_TRUE;
WARN_ON(cnt >= BFA_SEM_SPINCNT);
return BFA_FALSE;
}
static void
bfa_ioc_hw_sem_get(struct bfa_ioc_s *ioc)
{
u32 r32;
r32 = readl(ioc->ioc_regs.ioc_sem_reg);
if (r32 == 0) {
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_SEMLOCKED);
return;
}
bfa_sem_timer_start(ioc);
}
static void
bfa_ioc_lmem_init(struct bfa_ioc_s *ioc)
{
u32 pss_ctl;
int i;
#define PSS_LMEM_INIT_TIME 10000
pss_ctl = readl(ioc->ioc_regs.pss_ctl_reg);
pss_ctl &= ~__PSS_LMEM_RESET;
pss_ctl |= __PSS_LMEM_INIT_EN;
pss_ctl |= __PSS_I2C_CLK_DIV(3UL);
writel(pss_ctl, ioc->ioc_regs.pss_ctl_reg);
i = 0;
do {
pss_ctl = readl(ioc->ioc_regs.pss_ctl_reg);
i++;
} while (!(pss_ctl & __PSS_LMEM_INIT_DONE) && (i < PSS_LMEM_INIT_TIME));
WARN_ON(!(pss_ctl & __PSS_LMEM_INIT_DONE));
bfa_trc(ioc, pss_ctl);
pss_ctl &= ~(__PSS_LMEM_INIT_DONE | __PSS_LMEM_INIT_EN);
writel(pss_ctl, ioc->ioc_regs.pss_ctl_reg);
}
static void
bfa_ioc_lpu_start(struct bfa_ioc_s *ioc)
{
u32 pss_ctl;
pss_ctl = readl(ioc->ioc_regs.pss_ctl_reg);
pss_ctl &= ~__PSS_LPU0_RESET;
writel(pss_ctl, ioc->ioc_regs.pss_ctl_reg);
}
static void
bfa_ioc_lpu_stop(struct bfa_ioc_s *ioc)
{
u32 pss_ctl;
pss_ctl = readl(ioc->ioc_regs.pss_ctl_reg);
pss_ctl |= (__PSS_LPU0_RESET | __PSS_LPU1_RESET);
writel(pss_ctl, ioc->ioc_regs.pss_ctl_reg);
}
void
bfa_ioc_fwver_get(struct bfa_ioc_s *ioc, struct bfi_ioc_image_hdr_s *fwhdr)
{
u32 pgnum, pgoff;
u32 loff = 0;
int i;
u32 *fwsig = (u32 *) fwhdr;
pgnum = PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, loff);
pgoff = PSS_SMEM_PGOFF(loff);
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
for (i = 0; i < (sizeof(struct bfi_ioc_image_hdr_s) / sizeof(u32));
i++) {
fwsig[i] =
bfa_mem_read(ioc->ioc_regs.smem_page_start, loff);
loff += sizeof(u32);
}
}
bfa_boolean_t
bfa_ioc_fwver_cmp(struct bfa_ioc_s *ioc, struct bfi_ioc_image_hdr_s *fwhdr)
{
struct bfi_ioc_image_hdr_s *drv_fwhdr;
int i;
drv_fwhdr = (struct bfi_ioc_image_hdr_s *)
bfa_cb_image_get_chunk(BFA_IOC_FWIMG_TYPE(ioc), 0);
for (i = 0; i < BFI_IOC_MD5SUM_SZ; i++) {
if (fwhdr->md5sum[i] != drv_fwhdr->md5sum[i]) {
bfa_trc(ioc, i);
bfa_trc(ioc, fwhdr->md5sum[i]);
bfa_trc(ioc, drv_fwhdr->md5sum[i]);
return BFA_FALSE;
}
}
bfa_trc(ioc, fwhdr->md5sum[0]);
return BFA_TRUE;
}
static bfa_boolean_t
bfa_ioc_fwver_valid(struct bfa_ioc_s *ioc, u32 boot_env)
{
struct bfi_ioc_image_hdr_s fwhdr, *drv_fwhdr;
bfa_ioc_fwver_get(ioc, &fwhdr);
drv_fwhdr = (struct bfi_ioc_image_hdr_s *)
bfa_cb_image_get_chunk(BFA_IOC_FWIMG_TYPE(ioc), 0);
if (fwhdr.signature != drv_fwhdr->signature) {
bfa_trc(ioc, fwhdr.signature);
bfa_trc(ioc, drv_fwhdr->signature);
return BFA_FALSE;
}
if (swab32(fwhdr.param) != boot_env) {
bfa_trc(ioc, fwhdr.param);
bfa_trc(ioc, boot_env);
return BFA_FALSE;
}
return bfa_ioc_fwver_cmp(ioc, &fwhdr);
}
static void
bfa_ioc_msgflush(struct bfa_ioc_s *ioc)
{
u32 r32;
r32 = readl(ioc->ioc_regs.lpu_mbox_cmd);
if (r32)
writel(1, ioc->ioc_regs.lpu_mbox_cmd);
}
static void
bfa_ioc_hwinit(struct bfa_ioc_s *ioc, bfa_boolean_t force)
{
enum bfi_ioc_state ioc_fwstate;
bfa_boolean_t fwvalid;
u32 boot_type;
u32 boot_env;
ioc_fwstate = readl(ioc->ioc_regs.ioc_fwstate);
if (force)
ioc_fwstate = BFI_IOC_UNINIT;
bfa_trc(ioc, ioc_fwstate);
boot_type = BFI_BOOT_TYPE_NORMAL;
boot_env = BFI_BOOT_LOADER_OS;
fwvalid = (ioc_fwstate == BFI_IOC_UNINIT) ?
BFA_FALSE : bfa_ioc_fwver_valid(ioc, boot_env);
if (!fwvalid) {
bfa_ioc_boot(ioc, boot_type, boot_env);
return;
}
if (ioc_fwstate == BFI_IOC_INITING) {
ioc->cbfn->reset_cbfn(ioc->bfa);
return;
}
if (ioc_fwstate == BFI_IOC_DISABLED || ioc_fwstate == BFI_IOC_OP) {
bfa_ioc_msgflush(ioc);
ioc->cbfn->reset_cbfn(ioc->bfa);
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_FWREADY);
return;
}
bfa_ioc_boot(ioc, boot_type, boot_env);
}
static void
bfa_ioc_timeout(void *ioc_arg)
{
struct bfa_ioc_s *ioc = (struct bfa_ioc_s *) ioc_arg;
bfa_trc(ioc, 0);
bfa_fsm_send_event(ioc, IOC_E_TIMEOUT);
}
void
bfa_ioc_mbox_send(struct bfa_ioc_s *ioc, void *ioc_msg, int len)
{
u32 *msgp = (u32 *) ioc_msg;
u32 i;
bfa_trc(ioc, msgp[0]);
bfa_trc(ioc, len);
WARN_ON(len > BFI_IOC_MSGLEN_MAX);
for (i = 0; i < len / sizeof(u32); i++)
writel(cpu_to_le32(msgp[i]),
ioc->ioc_regs.hfn_mbox + i * sizeof(u32));
for (; i < BFI_IOC_MSGLEN_MAX / sizeof(u32); i++)
writel(0, ioc->ioc_regs.hfn_mbox + i * sizeof(u32));
writel(1, ioc->ioc_regs.hfn_mbox_cmd);
(void) readl(ioc->ioc_regs.hfn_mbox_cmd);
}
static void
bfa_ioc_send_enable(struct bfa_ioc_s *ioc)
{
struct bfi_ioc_ctrl_req_s enable_req;
struct timeval tv;
bfi_h2i_set(enable_req.mh, BFI_MC_IOC, BFI_IOC_H2I_ENABLE_REQ,
bfa_ioc_portid(ioc));
enable_req.ioc_class = ioc->ioc_mc;
do_gettimeofday(&tv);
enable_req.tv_sec = be32_to_cpu(tv.tv_sec);
bfa_ioc_mbox_send(ioc, &enable_req, sizeof(struct bfi_ioc_ctrl_req_s));
}
static void
bfa_ioc_send_disable(struct bfa_ioc_s *ioc)
{
struct bfi_ioc_ctrl_req_s disable_req;
bfi_h2i_set(disable_req.mh, BFI_MC_IOC, BFI_IOC_H2I_DISABLE_REQ,
bfa_ioc_portid(ioc));
bfa_ioc_mbox_send(ioc, &disable_req, sizeof(struct bfi_ioc_ctrl_req_s));
}
static void
bfa_ioc_send_getattr(struct bfa_ioc_s *ioc)
{
struct bfi_ioc_getattr_req_s attr_req;
bfi_h2i_set(attr_req.mh, BFI_MC_IOC, BFI_IOC_H2I_GETATTR_REQ,
bfa_ioc_portid(ioc));
bfa_dma_be_addr_set(attr_req.attr_addr, ioc->attr_dma.pa);
bfa_ioc_mbox_send(ioc, &attr_req, sizeof(attr_req));
}
static void
bfa_ioc_hb_check(void *cbarg)
{
struct bfa_ioc_s *ioc = cbarg;
u32 hb_count;
hb_count = readl(ioc->ioc_regs.heartbeat);
if (ioc->hb_count == hb_count) {
bfa_ioc_recover(ioc);
return;
} else {
ioc->hb_count = hb_count;
}
bfa_ioc_mbox_poll(ioc);
bfa_hb_timer_start(ioc);
}
static void
bfa_ioc_hb_monitor(struct bfa_ioc_s *ioc)
{
ioc->hb_count = readl(ioc->ioc_regs.heartbeat);
bfa_hb_timer_start(ioc);
}
static void
bfa_ioc_download_fw(struct bfa_ioc_s *ioc, u32 boot_type,
u32 boot_env)
{
u32 *fwimg;
u32 pgnum, pgoff;
u32 loff = 0;
u32 chunkno = 0;
u32 i;
bfa_ioc_lmem_init(ioc);
bfa_trc(ioc, bfa_cb_image_get_size(BFA_IOC_FWIMG_TYPE(ioc)));
fwimg = bfa_cb_image_get_chunk(BFA_IOC_FWIMG_TYPE(ioc), chunkno);
pgnum = PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, loff);
pgoff = PSS_SMEM_PGOFF(loff);
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
for (i = 0; i < bfa_cb_image_get_size(BFA_IOC_FWIMG_TYPE(ioc)); i++) {
if (BFA_IOC_FLASH_CHUNK_NO(i) != chunkno) {
chunkno = BFA_IOC_FLASH_CHUNK_NO(i);
fwimg = bfa_cb_image_get_chunk(BFA_IOC_FWIMG_TYPE(ioc),
BFA_IOC_FLASH_CHUNK_ADDR(chunkno));
}
bfa_mem_write(ioc->ioc_regs.smem_page_start, loff,
fwimg[BFA_IOC_FLASH_OFFSET_IN_CHUNK(i)]);
loff += sizeof(u32);
loff = PSS_SMEM_PGOFF(loff);
if (loff == 0) {
pgnum++;
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
}
}
writel(PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, 0),
ioc->ioc_regs.host_page_num_fn);
bfa_mem_write(ioc->ioc_regs.smem_page_start, BFI_BOOT_TYPE_OFF,
swab32(boot_type));
bfa_mem_write(ioc->ioc_regs.smem_page_start, BFI_BOOT_LOADER_OFF,
swab32(boot_env));
}
static void
bfa_ioc_getattr_reply(struct bfa_ioc_s *ioc)
{
struct bfi_ioc_attr_s *attr = ioc->attr;
attr->adapter_prop = be32_to_cpu(attr->adapter_prop);
attr->card_type = be32_to_cpu(attr->card_type);
attr->maxfrsize = be16_to_cpu(attr->maxfrsize);
bfa_fsm_send_event(ioc, IOC_E_FWRSP_GETATTR);
}
static void
bfa_ioc_mbox_attach(struct bfa_ioc_s *ioc)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
int mc;
INIT_LIST_HEAD(&mod->cmd_q);
for (mc = 0; mc < BFI_MC_MAX; mc++) {
mod->mbhdlr[mc].cbfn = NULL;
mod->mbhdlr[mc].cbarg = ioc->bfa;
}
}
static void
bfa_ioc_mbox_poll(struct bfa_ioc_s *ioc)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
struct bfa_mbox_cmd_s *cmd;
u32 stat;
if (list_empty(&mod->cmd_q))
return;
stat = readl(ioc->ioc_regs.hfn_mbox_cmd);
if (stat)
return;
bfa_q_deq(&mod->cmd_q, &cmd);
bfa_ioc_mbox_send(ioc, cmd->msg, sizeof(cmd->msg));
}
static void
bfa_ioc_mbox_hbfail(struct bfa_ioc_s *ioc)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
struct bfa_mbox_cmd_s *cmd;
while (!list_empty(&mod->cmd_q))
bfa_q_deq(&mod->cmd_q, &cmd);
}
static bfa_status_t
bfa_ioc_smem_read(struct bfa_ioc_s *ioc, void *tbuf, u32 soff, u32 sz)
{
u32 pgnum, loff;
__be32 r32;
int i, len;
u32 *buf = tbuf;
pgnum = PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, soff);
loff = PSS_SMEM_PGOFF(soff);
bfa_trc(ioc, pgnum);
bfa_trc(ioc, loff);
bfa_trc(ioc, sz);
if (BFA_FALSE == bfa_ioc_sem_get(ioc->ioc_regs.ioc_init_sem_reg)) {
bfa_trc(ioc, 0);
return BFA_STATUS_FAILED;
}
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
len = sz/sizeof(u32);
bfa_trc(ioc, len);
for (i = 0; i < len; i++) {
r32 = bfa_mem_read(ioc->ioc_regs.smem_page_start, loff);
buf[i] = be32_to_cpu(r32);
loff += sizeof(u32);
loff = PSS_SMEM_PGOFF(loff);
if (loff == 0) {
pgnum++;
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
}
}
writel(PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, 0),
ioc->ioc_regs.host_page_num_fn);
writel(1, ioc->ioc_regs.ioc_init_sem_reg);
bfa_trc(ioc, pgnum);
return BFA_STATUS_OK;
}
static bfa_status_t
bfa_ioc_smem_clr(struct bfa_ioc_s *ioc, u32 soff, u32 sz)
{
int i, len;
u32 pgnum, loff;
pgnum = PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, soff);
loff = PSS_SMEM_PGOFF(soff);
bfa_trc(ioc, pgnum);
bfa_trc(ioc, loff);
bfa_trc(ioc, sz);
if (BFA_FALSE == bfa_ioc_sem_get(ioc->ioc_regs.ioc_init_sem_reg)) {
bfa_trc(ioc, 0);
return BFA_STATUS_FAILED;
}
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
len = sz/sizeof(u32);
bfa_trc(ioc, len);
for (i = 0; i < len; i++) {
bfa_mem_write(ioc->ioc_regs.smem_page_start, loff, 0);
loff += sizeof(u32);
loff = PSS_SMEM_PGOFF(loff);
if (loff == 0) {
pgnum++;
writel(pgnum, ioc->ioc_regs.host_page_num_fn);
}
}
writel(PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, 0),
ioc->ioc_regs.host_page_num_fn);
writel(1, ioc->ioc_regs.ioc_init_sem_reg);
bfa_trc(ioc, pgnum);
return BFA_STATUS_OK;
}
static void
bfa_ioc_fail_notify(struct bfa_ioc_s *ioc)
{
struct list_head *qe;
struct bfa_ioc_hbfail_notify_s *notify;
struct bfad_s *bfad = (struct bfad_s *)ioc->bfa->bfad;
ioc->cbfn->hbfail_cbfn(ioc->bfa);
list_for_each(qe, &ioc->hb_notify_q) {
notify = (struct bfa_ioc_hbfail_notify_s *) qe;
notify->cbfn(notify->cbarg);
}
bfa_ioc_debug_save_ftrc(ioc);
BFA_LOG(KERN_CRIT, bfad, bfa_log_level,
"Heart Beat of IOC has failed\n");
}
static void
bfa_ioc_pf_fwmismatch(struct bfa_ioc_s *ioc)
{
struct bfad_s *bfad = (struct bfad_s *)ioc->bfa->bfad;
ioc->cbfn->enable_cbfn(ioc->bfa, BFA_STATUS_IOC_FAILURE);
BFA_LOG(KERN_WARNING, bfad, bfa_log_level,
"Running firmware version is incompatible "
"with the driver version\n");
}
bfa_status_t
bfa_ioc_pll_init(struct bfa_ioc_s *ioc)
{
bfa_ioc_sem_get(ioc->ioc_regs.ioc_init_sem_reg);
bfa_ioc_pll_init_asic(ioc);
ioc->pllinit = BFA_TRUE;
writel(1, ioc->ioc_regs.ioc_init_sem_reg);
return BFA_STATUS_OK;
}
void
bfa_ioc_boot(struct bfa_ioc_s *ioc, u32 boot_type, u32 boot_env)
{
void __iomem *rb;
bfa_ioc_stats(ioc, ioc_boots);
if (bfa_ioc_pll_init(ioc) != BFA_STATUS_OK)
return;
rb = ioc->pcidev.pci_bar_kva;
if (boot_type == BFI_BOOT_TYPE_MEMTEST) {
writel(BFI_IOC_MEMTEST, (rb + BFA_IOC0_STATE_REG));
writel(BFI_IOC_MEMTEST, (rb + BFA_IOC1_STATE_REG));
} else {
writel(BFI_IOC_INITING, (rb + BFA_IOC0_STATE_REG));
writel(BFI_IOC_INITING, (rb + BFA_IOC1_STATE_REG));
}
bfa_ioc_msgflush(ioc);
bfa_ioc_download_fw(ioc, boot_type, boot_env);
ioc->cbfn->reset_cbfn(ioc->bfa);
bfa_ioc_lpu_start(ioc);
}
void
bfa_ioc_auto_recover(bfa_boolean_t auto_recover)
{
bfa_auto_recover = auto_recover;
}
bfa_boolean_t
bfa_ioc_is_operational(struct bfa_ioc_s *ioc)
{
return bfa_fsm_cmp_state(ioc, bfa_ioc_sm_op);
}
bfa_boolean_t
bfa_ioc_is_initialized(struct bfa_ioc_s *ioc)
{
u32 r32 = readl(ioc->ioc_regs.ioc_fwstate);
return ((r32 != BFI_IOC_UNINIT) &&
(r32 != BFI_IOC_INITING) &&
(r32 != BFI_IOC_MEMTEST));
}
void
bfa_ioc_msgget(struct bfa_ioc_s *ioc, void *mbmsg)
{
__be32 *msgp = mbmsg;
u32 r32;
int i;
for (i = 0; i < (sizeof(union bfi_ioc_i2h_msg_u) / sizeof(u32));
i++) {
r32 = readl(ioc->ioc_regs.lpu_mbox +
i * sizeof(u32));
msgp[i] = cpu_to_be32(r32);
}
writel(1, ioc->ioc_regs.lpu_mbox_cmd);
readl(ioc->ioc_regs.lpu_mbox_cmd);
}
void
bfa_ioc_isr(struct bfa_ioc_s *ioc, struct bfi_mbmsg_s *m)
{
union bfi_ioc_i2h_msg_u *msg;
struct bfa_iocpf_s *iocpf = &ioc->iocpf;
msg = (union bfi_ioc_i2h_msg_u *) m;
bfa_ioc_stats(ioc, ioc_isrs);
switch (msg->mh.msg_id) {
case BFI_IOC_I2H_HBEAT:
break;
case BFI_IOC_I2H_READY_EVENT:
bfa_fsm_send_event(iocpf, IOCPF_E_FWREADY);
break;
case BFI_IOC_I2H_ENABLE_REPLY:
bfa_fsm_send_event(iocpf, IOCPF_E_FWRSP_ENABLE);
break;
case BFI_IOC_I2H_DISABLE_REPLY:
bfa_fsm_send_event(iocpf, IOCPF_E_FWRSP_DISABLE);
break;
case BFI_IOC_I2H_GETATTR_REPLY:
bfa_ioc_getattr_reply(ioc);
break;
default:
bfa_trc(ioc, msg->mh.msg_id);
WARN_ON(1);
}
}
void
bfa_ioc_attach(struct bfa_ioc_s *ioc, void *bfa, struct bfa_ioc_cbfn_s *cbfn,
struct bfa_timer_mod_s *timer_mod)
{
ioc->bfa = bfa;
ioc->cbfn = cbfn;
ioc->timer_mod = timer_mod;
ioc->fcmode = BFA_FALSE;
ioc->pllinit = BFA_FALSE;
ioc->dbg_fwsave_once = BFA_TRUE;
ioc->iocpf.ioc = ioc;
bfa_ioc_mbox_attach(ioc);
INIT_LIST_HEAD(&ioc->hb_notify_q);
bfa_fsm_set_state(ioc, bfa_ioc_sm_uninit);
bfa_fsm_send_event(ioc, IOC_E_RESET);
}
void
bfa_ioc_detach(struct bfa_ioc_s *ioc)
{
bfa_fsm_send_event(ioc, IOC_E_DETACH);
}
void
bfa_ioc_pci_init(struct bfa_ioc_s *ioc, struct bfa_pcidev_s *pcidev,
enum bfi_mclass mc)
{
ioc->ioc_mc = mc;
ioc->pcidev = *pcidev;
ioc->ctdev = bfa_asic_id_ct(ioc->pcidev.device_id);
ioc->cna = ioc->ctdev && !ioc->fcmode;
if (ioc->ctdev)
bfa_ioc_set_ct_hwif(ioc);
else
bfa_ioc_set_cb_hwif(ioc);
bfa_ioc_map_port(ioc);
bfa_ioc_reg_init(ioc);
}
void
bfa_ioc_mem_claim(struct bfa_ioc_s *ioc, u8 *dm_kva, u64 dm_pa)
{
ioc->attr_dma.kva = dm_kva;
ioc->attr_dma.pa = dm_pa;
ioc->attr = (struct bfi_ioc_attr_s *) dm_kva;
}
void
bfa_ioc_enable(struct bfa_ioc_s *ioc)
{
bfa_ioc_stats(ioc, ioc_enables);
ioc->dbg_fwsave_once = BFA_TRUE;
bfa_fsm_send_event(ioc, IOC_E_ENABLE);
}
void
bfa_ioc_disable(struct bfa_ioc_s *ioc)
{
bfa_ioc_stats(ioc, ioc_disables);
bfa_fsm_send_event(ioc, IOC_E_DISABLE);
}
void
bfa_ioc_debug_memclaim(struct bfa_ioc_s *ioc, void *dbg_fwsave)
{
ioc->dbg_fwsave = dbg_fwsave;
ioc->dbg_fwsave_len = (ioc->iocpf.auto_recover) ? BFA_DBG_FWTRC_LEN : 0;
}
void
bfa_ioc_mbox_register(struct bfa_ioc_s *ioc, bfa_ioc_mbox_mcfunc_t *mcfuncs)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
int mc;
for (mc = 0; mc < BFI_MC_MAX; mc++)
mod->mbhdlr[mc].cbfn = mcfuncs[mc];
}
void
bfa_ioc_mbox_regisr(struct bfa_ioc_s *ioc, enum bfi_mclass mc,
bfa_ioc_mbox_mcfunc_t cbfn, void *cbarg)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
mod->mbhdlr[mc].cbfn = cbfn;
mod->mbhdlr[mc].cbarg = cbarg;
}
void
bfa_ioc_mbox_queue(struct bfa_ioc_s *ioc, struct bfa_mbox_cmd_s *cmd)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
u32 stat;
if (!list_empty(&mod->cmd_q)) {
list_add_tail(&cmd->qe, &mod->cmd_q);
return;
}
stat = readl(ioc->ioc_regs.hfn_mbox_cmd);
if (stat) {
list_add_tail(&cmd->qe, &mod->cmd_q);
return;
}
bfa_ioc_mbox_send(ioc, cmd->msg, sizeof(cmd->msg));
}
void
bfa_ioc_mbox_isr(struct bfa_ioc_s *ioc)
{
struct bfa_ioc_mbox_mod_s *mod = &ioc->mbox_mod;
struct bfi_mbmsg_s m;
int mc;
bfa_ioc_msgget(ioc, &m);
mc = m.mh.msg_class;
if (mc == BFI_MC_IOC) {
bfa_ioc_isr(ioc, &m);
return;
}
if ((mc > BFI_MC_MAX) || (mod->mbhdlr[mc].cbfn == NULL))
return;
mod->mbhdlr[mc].cbfn(mod->mbhdlr[mc].cbarg, &m);
}
void
bfa_ioc_error_isr(struct bfa_ioc_s *ioc)
{
bfa_fsm_send_event(ioc, IOC_E_HWERROR);
}
void
bfa_ioc_set_fcmode(struct bfa_ioc_s *ioc)
{
ioc->fcmode = BFA_TRUE;
ioc->port_id = bfa_ioc_pcifn(ioc);
}
bfa_boolean_t
bfa_ioc_is_disabled(struct bfa_ioc_s *ioc)
{
return bfa_fsm_cmp_state(ioc, bfa_ioc_sm_disabling) ||
bfa_fsm_cmp_state(ioc, bfa_ioc_sm_disabled);
}
bfa_boolean_t
bfa_ioc_fw_mismatch(struct bfa_ioc_s *ioc)
{
return bfa_fsm_cmp_state(ioc, bfa_ioc_sm_reset) ||
bfa_fsm_cmp_state(&ioc->iocpf, bfa_iocpf_sm_fwcheck) ||
bfa_fsm_cmp_state(&ioc->iocpf, bfa_iocpf_sm_mismatch);
}
bfa_boolean_t
bfa_ioc_adapter_is_disabled(struct bfa_ioc_s *ioc)
{
u32 ioc_state;
void __iomem *rb = ioc->pcidev.pci_bar_kva;
if (!bfa_fsm_cmp_state(ioc, bfa_ioc_sm_disabled))
return BFA_FALSE;
ioc_state = readl(rb + BFA_IOC0_STATE_REG);
if (!bfa_ioc_state_disabled(ioc_state))
return BFA_FALSE;
if (ioc->pcidev.device_id != BFA_PCI_DEVICE_ID_FC_8G1P) {
ioc_state = readl(rb + BFA_IOC1_STATE_REG);
if (!bfa_ioc_state_disabled(ioc_state))
return BFA_FALSE;
}
return BFA_TRUE;
}
void
bfa_ioc_reset_fwstate(struct bfa_ioc_s *ioc)
{
writel(BFI_IOC_UNINIT, ioc->ioc_regs.ioc_fwstate);
writel(BFI_IOC_UNINIT, ioc->ioc_regs.alt_ioc_fwstate);
}
void
bfa_ioc_get_adapter_attr(struct bfa_ioc_s *ioc,
struct bfa_adapter_attr_s *ad_attr)
{
struct bfi_ioc_attr_s *ioc_attr;
ioc_attr = ioc->attr;
bfa_ioc_get_adapter_serial_num(ioc, ad_attr->serial_num);
bfa_ioc_get_adapter_fw_ver(ioc, ad_attr->fw_ver);
bfa_ioc_get_adapter_optrom_ver(ioc, ad_attr->optrom_ver);
bfa_ioc_get_adapter_manufacturer(ioc, ad_attr->manufacturer);
memcpy(&ad_attr->vpd, &ioc_attr->vpd,
sizeof(struct bfa_mfg_vpd_s));
ad_attr->nports = bfa_ioc_get_nports(ioc);
ad_attr->max_speed = bfa_ioc_speed_sup(ioc);
bfa_ioc_get_adapter_model(ioc, ad_attr->model);
bfa_ioc_get_adapter_model(ioc, ad_attr->model_descr);
ad_attr->card_type = ioc_attr->card_type;
ad_attr->is_mezz = bfa_mfg_is_mezz(ioc_attr->card_type);
if (BFI_ADAPTER_IS_SPECIAL(ioc_attr->adapter_prop))
ad_attr->prototype = 1;
else
ad_attr->prototype = 0;
ad_attr->pwwn = ioc->attr->pwwn;
ad_attr->mac = bfa_ioc_get_mac(ioc);
ad_attr->pcie_gen = ioc_attr->pcie_gen;
ad_attr->pcie_lanes = ioc_attr->pcie_lanes;
ad_attr->pcie_lanes_orig = ioc_attr->pcie_lanes_orig;
ad_attr->asic_rev = ioc_attr->asic_rev;
bfa_ioc_get_pci_chip_rev(ioc, ad_attr->hw_ver);
ad_attr->cna_capable = ioc->cna;
ad_attr->trunk_capable = (ad_attr->nports > 1) && !ioc->cna &&
!ad_attr->is_mezz;
}
enum bfa_ioc_type_e
bfa_ioc_get_type(struct bfa_ioc_s *ioc)
{
if (!ioc->ctdev || ioc->fcmode)
return BFA_IOC_TYPE_FC;
else if (ioc->ioc_mc == BFI_MC_IOCFC)
return BFA_IOC_TYPE_FCoE;
else if (ioc->ioc_mc == BFI_MC_LL)
return BFA_IOC_TYPE_LL;
else {
WARN_ON(ioc->ioc_mc != BFI_MC_LL);
return BFA_IOC_TYPE_LL;
}
}
void
bfa_ioc_get_adapter_serial_num(struct bfa_ioc_s *ioc, char *serial_num)
{
memset((void *)serial_num, 0, BFA_ADAPTER_SERIAL_NUM_LEN);
memcpy((void *)serial_num,
(void *)ioc->attr->brcd_serialnum,
BFA_ADAPTER_SERIAL_NUM_LEN);
}
void
bfa_ioc_get_adapter_fw_ver(struct bfa_ioc_s *ioc, char *fw_ver)
{
memset((void *)fw_ver, 0, BFA_VERSION_LEN);
memcpy(fw_ver, ioc->attr->fw_version, BFA_VERSION_LEN);
}
void
bfa_ioc_get_pci_chip_rev(struct bfa_ioc_s *ioc, char *chip_rev)
{
WARN_ON(!chip_rev);
memset((void *)chip_rev, 0, BFA_IOC_CHIP_REV_LEN);
chip_rev[0] = 'R';
chip_rev[1] = 'e';
chip_rev[2] = 'v';
chip_rev[3] = '-';
chip_rev[4] = ioc->attr->asic_rev;
chip_rev[5] = '\0';
}
void
bfa_ioc_get_adapter_optrom_ver(struct bfa_ioc_s *ioc, char *optrom_ver)
{
memset((void *)optrom_ver, 0, BFA_VERSION_LEN);
memcpy(optrom_ver, ioc->attr->optrom_version,
BFA_VERSION_LEN);
}
void
bfa_ioc_get_adapter_manufacturer(struct bfa_ioc_s *ioc, char *manufacturer)
{
memset((void *)manufacturer, 0, BFA_ADAPTER_MFG_NAME_LEN);
memcpy(manufacturer, BFA_MFG_NAME, BFA_ADAPTER_MFG_NAME_LEN);
}
void
bfa_ioc_get_adapter_model(struct bfa_ioc_s *ioc, char *model)
{
struct bfi_ioc_attr_s *ioc_attr;
WARN_ON(!model);
memset((void *)model, 0, BFA_ADAPTER_MODEL_NAME_LEN);
ioc_attr = ioc->attr;
snprintf(model, BFA_ADAPTER_MODEL_NAME_LEN, "%s-%u",
BFA_MFG_NAME, ioc_attr->card_type);
}
enum bfa_ioc_state
bfa_ioc_get_state(struct bfa_ioc_s *ioc)
{
enum bfa_iocpf_state iocpf_st;
enum bfa_ioc_state ioc_st = bfa_sm_to_state(ioc_sm_table, ioc->fsm);
if (ioc_st == BFA_IOC_ENABLING ||
ioc_st == BFA_IOC_FAIL || ioc_st == BFA_IOC_INITFAIL) {
iocpf_st = bfa_sm_to_state(iocpf_sm_table, ioc->iocpf.fsm);
switch (iocpf_st) {
case BFA_IOCPF_SEMWAIT:
ioc_st = BFA_IOC_SEMWAIT;
break;
case BFA_IOCPF_HWINIT:
ioc_st = BFA_IOC_HWINIT;
break;
case BFA_IOCPF_FWMISMATCH:
ioc_st = BFA_IOC_FWMISMATCH;
break;
case BFA_IOCPF_FAIL:
ioc_st = BFA_IOC_FAIL;
break;
case BFA_IOCPF_INITFAIL:
ioc_st = BFA_IOC_INITFAIL;
break;
default:
break;
}
}
return ioc_st;
}
void
bfa_ioc_get_attr(struct bfa_ioc_s *ioc, struct bfa_ioc_attr_s *ioc_attr)
{
memset((void *)ioc_attr, 0, sizeof(struct bfa_ioc_attr_s));
ioc_attr->state = bfa_ioc_get_state(ioc);
ioc_attr->port_id = ioc->port_id;
ioc_attr->ioc_type = bfa_ioc_get_type(ioc);
bfa_ioc_get_adapter_attr(ioc, &ioc_attr->adapter_attr);
ioc_attr->pci_attr.device_id = ioc->pcidev.device_id;
ioc_attr->pci_attr.pcifn = ioc->pcidev.pci_func;
bfa_ioc_get_pci_chip_rev(ioc, ioc_attr->pci_attr.chip_rev);
}
mac_t
bfa_ioc_get_mac(struct bfa_ioc_s *ioc)
{
if (bfa_ioc_get_type(ioc) == BFA_IOC_TYPE_FCoE)
return ioc->attr->fcoe_mac;
else
return ioc->attr->mac;
}
mac_t
bfa_ioc_get_mfg_mac(struct bfa_ioc_s *ioc)
{
mac_t m;
m = ioc->attr->mfg_mac;
if (bfa_mfg_is_old_wwn_mac_model(ioc->attr->card_type))
m.mac[MAC_ADDRLEN - 1] += bfa_ioc_pcifn(ioc);
else
bfa_mfg_increment_wwn_mac(&(m.mac[MAC_ADDRLEN-3]),
bfa_ioc_pcifn(ioc));
return m;
}
bfa_boolean_t
bfa_ioc_get_fcmode(struct bfa_ioc_s *ioc)
{
return ioc->fcmode || !bfa_asic_id_ct(ioc->pcidev.device_id);
}
bfa_status_t
bfa_ioc_debug_fwsave(struct bfa_ioc_s *ioc, void *trcdata, int *trclen)
{
int tlen;
if (ioc->dbg_fwsave_len == 0)
return BFA_STATUS_ENOFSAVE;
tlen = *trclen;
if (tlen > ioc->dbg_fwsave_len)
tlen = ioc->dbg_fwsave_len;
memcpy(trcdata, ioc->dbg_fwsave, tlen);
*trclen = tlen;
return BFA_STATUS_OK;
}
bfa_status_t
bfa_ioc_debug_fwtrc(struct bfa_ioc_s *ioc, void *trcdata, int *trclen)
{
u32 loff = BFA_DBG_FWTRC_OFF(bfa_ioc_portid(ioc));
int tlen;
bfa_status_t status;
bfa_trc(ioc, *trclen);
tlen = *trclen;
if (tlen > BFA_DBG_FWTRC_LEN)
tlen = BFA_DBG_FWTRC_LEN;
status = bfa_ioc_smem_read(ioc, trcdata, loff, tlen);
*trclen = tlen;
return status;
}
static void
bfa_ioc_send_fwsync(struct bfa_ioc_s *ioc)
{
struct bfa_mbox_cmd_s cmd;
struct bfi_ioc_ctrl_req_s *req = (struct bfi_ioc_ctrl_req_s *) cmd.msg;
bfi_h2i_set(req->mh, BFI_MC_IOC, BFI_IOC_H2I_DBG_SYNC,
bfa_ioc_portid(ioc));
req->ioc_class = ioc->ioc_mc;
bfa_ioc_mbox_queue(ioc, &cmd);
}
static void
bfa_ioc_fwsync(struct bfa_ioc_s *ioc)
{
u32 fwsync_iter = 1000;
bfa_ioc_send_fwsync(ioc);
while (bfa_ioc_mbox_cmd_pending(ioc) && fwsync_iter > 0)
fwsync_iter--;
}
bfa_status_t
bfa_ioc_debug_fwcore(struct bfa_ioc_s *ioc, void *buf,
u32 *offset, int *buflen)
{
u32 loff;
int dlen;
bfa_status_t status;
u32 smem_len = BFA_IOC_FW_SMEM_SIZE(ioc);
if (*offset >= smem_len) {
*offset = *buflen = 0;
return BFA_STATUS_EINVAL;
}
loff = *offset;
dlen = *buflen;
if (loff == 0)
bfa_ioc_fwsync(ioc);
if ((loff + dlen) >= smem_len)
dlen = smem_len - loff;
status = bfa_ioc_smem_read(ioc, buf, loff, dlen);
if (status != BFA_STATUS_OK) {
*offset = *buflen = 0;
return status;
}
*offset += dlen;
if (*offset >= smem_len)
*offset = 0;
*buflen = dlen;
return status;
}
bfa_status_t
bfa_ioc_fw_stats_get(struct bfa_ioc_s *ioc, void *stats)
{
u32 loff = BFI_IOC_FWSTATS_OFF + \
BFI_IOC_FWSTATS_SZ * (bfa_ioc_portid(ioc));
int tlen;
bfa_status_t status;
if (ioc->stats_busy) {
bfa_trc(ioc, ioc->stats_busy);
return BFA_STATUS_DEVBUSY;
}
ioc->stats_busy = BFA_TRUE;
tlen = sizeof(struct bfa_fw_stats_s);
status = bfa_ioc_smem_read(ioc, stats, loff, tlen);
ioc->stats_busy = BFA_FALSE;
return status;
}
bfa_status_t
bfa_ioc_fw_stats_clear(struct bfa_ioc_s *ioc)
{
u32 loff = BFI_IOC_FWSTATS_OFF + \
BFI_IOC_FWSTATS_SZ * (bfa_ioc_portid(ioc));
int tlen;
bfa_status_t status;
if (ioc->stats_busy) {
bfa_trc(ioc, ioc->stats_busy);
return BFA_STATUS_DEVBUSY;
}
ioc->stats_busy = BFA_TRUE;
tlen = sizeof(struct bfa_fw_stats_s);
status = bfa_ioc_smem_clr(ioc, loff, tlen);
ioc->stats_busy = BFA_FALSE;
return status;
}
static void
bfa_ioc_debug_save_ftrc(struct bfa_ioc_s *ioc)
{
int tlen;
if (ioc->dbg_fwsave_once) {
ioc->dbg_fwsave_once = BFA_FALSE;
if (ioc->dbg_fwsave_len) {
tlen = ioc->dbg_fwsave_len;
bfa_ioc_debug_fwtrc(ioc, ioc->dbg_fwsave, &tlen);
}
}
}
static void
bfa_ioc_recover(struct bfa_ioc_s *ioc)
{
bfa_ioc_stats(ioc, ioc_hbfails);
bfa_fsm_send_event(ioc, IOC_E_HBFAIL);
}
static void
bfa_ioc_check_attr_wwns(struct bfa_ioc_s *ioc)
{
if (bfa_ioc_get_type(ioc) == BFA_IOC_TYPE_LL)
return;
}
static void
bfa_iocpf_timeout(void *ioc_arg)
{
struct bfa_ioc_s *ioc = (struct bfa_ioc_s *) ioc_arg;
bfa_trc(ioc, 0);
bfa_fsm_send_event(&ioc->iocpf, IOCPF_E_TIMEOUT);
}
static void
bfa_iocpf_sem_timeout(void *ioc_arg)
{
struct bfa_ioc_s *ioc = (struct bfa_ioc_s *) ioc_arg;
bfa_ioc_hw_sem_get(ioc);
}
void
bfa_timer_beat(struct bfa_timer_mod_s *mod)
{
struct list_head *qh = &mod->timer_q;
struct list_head *qe, *qe_next;
struct bfa_timer_s *elem;
struct list_head timedout_q;
INIT_LIST_HEAD(&timedout_q);
qe = bfa_q_next(qh);
while (qe != qh) {
qe_next = bfa_q_next(qe);
elem = (struct bfa_timer_s *) qe;
if (elem->timeout <= BFA_TIMER_FREQ) {
elem->timeout = 0;
list_del(&elem->qe);
list_add_tail(&elem->qe, &timedout_q);
} else {
elem->timeout -= BFA_TIMER_FREQ;
}
qe = qe_next;
}
while (!list_empty(&timedout_q)) {
bfa_q_deq(&timedout_q, &elem);
elem->timercb(elem->arg);
}
}
void
bfa_timer_begin(struct bfa_timer_mod_s *mod, struct bfa_timer_s *timer,
void (*timercb) (void *), void *arg, unsigned int timeout)
{
WARN_ON(timercb == NULL);
WARN_ON(bfa_q_is_on_q(&mod->timer_q, timer));
timer->timeout = timeout;
timer->timercb = timercb;
timer->arg = arg;
list_add_tail(&timer->qe, &mod->timer_q);
}
void
bfa_timer_stop(struct bfa_timer_s *timer)
{
WARN_ON(list_empty(&timer->qe));
list_del(&timer->qe);
}
