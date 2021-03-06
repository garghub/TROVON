static void
bfa_fcpim_meminfo(struct bfa_iocfc_cfg_s *cfg, u32 *km_len,
u32 *dm_len)
{
bfa_itnim_meminfo(cfg, km_len, dm_len);
if (cfg->fwcfg.num_ioim_reqs < BFA_IOIM_MIN)
cfg->fwcfg.num_ioim_reqs = BFA_IOIM_MIN;
else if (cfg->fwcfg.num_ioim_reqs > BFA_IOIM_MAX)
cfg->fwcfg.num_ioim_reqs = BFA_IOIM_MAX;
*km_len += cfg->fwcfg.num_ioim_reqs *
(sizeof(struct bfa_ioim_s) + sizeof(struct bfa_ioim_sp_s));
*dm_len += cfg->fwcfg.num_ioim_reqs * BFI_IOIM_SNSLEN;
if (cfg->fwcfg.num_tskim_reqs < BFA_TSKIM_MIN)
cfg->fwcfg.num_tskim_reqs = BFA_TSKIM_MIN;
*km_len += cfg->fwcfg.num_tskim_reqs * sizeof(struct bfa_tskim_s);
}
static void
bfa_fcpim_attach(struct bfa_s *bfa, void *bfad, struct bfa_iocfc_cfg_s *cfg,
struct bfa_meminfo_s *meminfo, struct bfa_pcidev_s *pcidev)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
bfa_trc(bfa, cfg->drvcfg.path_tov);
bfa_trc(bfa, cfg->fwcfg.num_rports);
bfa_trc(bfa, cfg->fwcfg.num_ioim_reqs);
bfa_trc(bfa, cfg->fwcfg.num_tskim_reqs);
fcpim->bfa = bfa;
fcpim->num_itnims = cfg->fwcfg.num_rports;
fcpim->num_ioim_reqs = cfg->fwcfg.num_ioim_reqs;
fcpim->num_tskim_reqs = cfg->fwcfg.num_tskim_reqs;
fcpim->path_tov = cfg->drvcfg.path_tov;
fcpim->delay_comp = cfg->drvcfg.delay_comp;
fcpim->profile_comp = NULL;
fcpim->profile_start = NULL;
bfa_itnim_attach(fcpim, meminfo);
bfa_tskim_attach(fcpim, meminfo);
bfa_ioim_attach(fcpim, meminfo);
}
static void
bfa_fcpim_detach(struct bfa_s *bfa)
{
}
static void
bfa_fcpim_start(struct bfa_s *bfa)
{
}
static void
bfa_fcpim_stop(struct bfa_s *bfa)
{
}
static void
bfa_fcpim_iocdisable(struct bfa_s *bfa)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfa_itnim_s *itnim;
struct list_head *qe, *qen;
list_for_each_safe(qe, qen, &fcpim->itnim_q) {
itnim = (struct bfa_itnim_s *) qe;
bfa_itnim_iocdisable(itnim);
}
}
void
bfa_fcpim_path_tov_set(struct bfa_s *bfa, u16 path_tov)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
fcpim->path_tov = path_tov * 1000;
if (fcpim->path_tov > BFA_FCPIM_PATHTOV_MAX)
fcpim->path_tov = BFA_FCPIM_PATHTOV_MAX;
}
u16
bfa_fcpim_path_tov_get(struct bfa_s *bfa)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
return fcpim->path_tov / 1000;
}
u16
bfa_fcpim_qdepth_get(struct bfa_s *bfa)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
return fcpim->q_depth;
}
static void
bfa_itnim_sm_uninit(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_CREATE:
bfa_sm_set_state(itnim, bfa_itnim_sm_created);
itnim->is_online = BFA_FALSE;
bfa_fcpim_additn(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_created(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_ONLINE:
if (bfa_itnim_send_fwcreate(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate_qfull);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_fcpim_delitn(itnim);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_fwcreate(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_FWRSP:
bfa_sm_set_state(itnim, bfa_itnim_sm_online);
itnim->is_online = BFA_TRUE;
bfa_itnim_iotov_online(itnim);
bfa_itnim_online_cb(itnim);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_delete_pending);
break;
case BFA_ITNIM_SM_OFFLINE:
if (bfa_itnim_send_fwdelete(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_fwdelete);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_fwdelete_qfull);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_fwcreate_qfull(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_QRESUME:
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate);
bfa_itnim_send_fwcreate(itnim);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_reqq_wcancel(&itnim->reqq_wait);
bfa_fcpim_delitn(itnim);
break;
case BFA_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_itnim_sm_offline);
bfa_reqq_wcancel(&itnim->reqq_wait);
bfa_itnim_offline_cb(itnim);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
bfa_reqq_wcancel(&itnim->reqq_wait);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_delete_pending(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_FWRSP:
if (bfa_itnim_send_fwdelete(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting_qfull);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_fcpim_delitn(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_online(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_itnim_sm_cleanup_offline);
itnim->is_online = BFA_FALSE;
bfa_itnim_iotov_start(itnim);
bfa_itnim_cleanup(itnim);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_cleanup_delete);
itnim->is_online = BFA_FALSE;
bfa_itnim_cleanup(itnim);
break;
case BFA_ITNIM_SM_SLER:
bfa_sm_set_state(itnim, bfa_itnim_sm_sler);
itnim->is_online = BFA_FALSE;
bfa_itnim_iotov_start(itnim);
bfa_itnim_sler_cb(itnim);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
itnim->is_online = BFA_FALSE;
bfa_itnim_iotov_start(itnim);
bfa_itnim_iocdisable_cleanup(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_sler(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_OFFLINE:
bfa_sm_set_state(itnim, bfa_itnim_sm_cleanup_offline);
bfa_itnim_cleanup(itnim);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_cleanup_delete);
bfa_itnim_cleanup(itnim);
bfa_itnim_iotov_delete(itnim);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
bfa_itnim_iocdisable_cleanup(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_cleanup_offline(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_CLEANUP:
if (bfa_itnim_send_fwdelete(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_fwdelete);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_fwdelete_qfull);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_cleanup_delete);
bfa_itnim_iotov_delete(itnim);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
bfa_itnim_iocdisable_cleanup(itnim);
bfa_itnim_offline_cb(itnim);
break;
case BFA_ITNIM_SM_SLER:
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_cleanup_delete(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_CLEANUP:
if (bfa_itnim_send_fwdelete(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting_qfull);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
bfa_itnim_iocdisable_cleanup(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_fwdelete(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_FWRSP:
bfa_sm_set_state(itnim, bfa_itnim_sm_offline);
bfa_itnim_offline_cb(itnim);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
bfa_itnim_offline_cb(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_fwdelete_qfull(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_QRESUME:
bfa_sm_set_state(itnim, bfa_itnim_sm_fwdelete);
bfa_itnim_send_fwdelete(itnim);
break;
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting_qfull);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
bfa_reqq_wcancel(&itnim->reqq_wait);
bfa_itnim_offline_cb(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_offline(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_itnim_iotov_delete(itnim);
bfa_fcpim_delitn(itnim);
break;
case BFA_ITNIM_SM_ONLINE:
if (bfa_itnim_send_fwcreate(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate_qfull);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_iocdisable);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_iocdisable(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_DELETE:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_itnim_iotov_delete(itnim);
bfa_fcpim_delitn(itnim);
break;
case BFA_ITNIM_SM_OFFLINE:
bfa_itnim_offline_cb(itnim);
break;
case BFA_ITNIM_SM_ONLINE:
if (bfa_itnim_send_fwcreate(itnim))
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate);
else
bfa_sm_set_state(itnim, bfa_itnim_sm_fwcreate_qfull);
break;
case BFA_ITNIM_SM_HWFAIL:
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_deleting(struct bfa_itnim_s *itnim, enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_FWRSP:
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_fcpim_delitn(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_sm_deleting_qfull(struct bfa_itnim_s *itnim,
enum bfa_itnim_event event)
{
bfa_trc(itnim->bfa, itnim->rport->rport_tag);
bfa_trc(itnim->bfa, event);
switch (event) {
case BFA_ITNIM_SM_QRESUME:
bfa_sm_set_state(itnim, bfa_itnim_sm_deleting);
bfa_itnim_send_fwdelete(itnim);
break;
case BFA_ITNIM_SM_HWFAIL:
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
bfa_reqq_wcancel(&itnim->reqq_wait);
bfa_fcpim_delitn(itnim);
break;
default:
bfa_sm_fault(itnim->bfa, event);
}
}
static void
bfa_itnim_iocdisable_cleanup(struct bfa_itnim_s *itnim)
{
struct bfa_tskim_s *tskim;
struct bfa_ioim_s *ioim;
struct list_head *qe, *qen;
list_for_each_safe(qe, qen, &itnim->tsk_q) {
tskim = (struct bfa_tskim_s *) qe;
bfa_tskim_iocdisable(tskim);
}
list_for_each_safe(qe, qen, &itnim->io_q) {
ioim = (struct bfa_ioim_s *) qe;
bfa_ioim_iocdisable(ioim);
}
list_for_each_safe(qe, qen, &itnim->pending_q) {
ioim = (struct bfa_ioim_s *) qe;
bfa_ioim_tov(ioim);
}
list_for_each_safe(qe, qen, &itnim->io_cleanup_q) {
ioim = (struct bfa_ioim_s *) qe;
bfa_ioim_iocdisable(ioim);
}
}
static void
bfa_itnim_cleanp_comp(void *itnim_cbarg)
{
struct bfa_itnim_s *itnim = itnim_cbarg;
bfa_stats(itnim, cleanup_comps);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_CLEANUP);
}
static void
bfa_itnim_cleanup(struct bfa_itnim_s *itnim)
{
struct bfa_ioim_s *ioim;
struct bfa_tskim_s *tskim;
struct list_head *qe, *qen;
bfa_wc_init(&itnim->wc, bfa_itnim_cleanp_comp, itnim);
list_for_each_safe(qe, qen, &itnim->io_q) {
ioim = (struct bfa_ioim_s *) qe;
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &itnim->io_cleanup_q);
bfa_wc_up(&itnim->wc);
bfa_ioim_cleanup(ioim);
}
list_for_each_safe(qe, qen, &itnim->tsk_q) {
tskim = (struct bfa_tskim_s *) qe;
bfa_wc_up(&itnim->wc);
bfa_tskim_cleanup(tskim);
}
bfa_wc_wait(&itnim->wc);
}
static void
__bfa_cb_itnim_online(void *cbarg, bfa_boolean_t complete)
{
struct bfa_itnim_s *itnim = cbarg;
if (complete)
bfa_cb_itnim_online(itnim->ditn);
}
static void
__bfa_cb_itnim_offline(void *cbarg, bfa_boolean_t complete)
{
struct bfa_itnim_s *itnim = cbarg;
if (complete)
bfa_cb_itnim_offline(itnim->ditn);
}
static void
__bfa_cb_itnim_sler(void *cbarg, bfa_boolean_t complete)
{
struct bfa_itnim_s *itnim = cbarg;
if (complete)
bfa_cb_itnim_sler(itnim->ditn);
}
static void
bfa_itnim_qresume(void *cbarg)
{
struct bfa_itnim_s *itnim = cbarg;
bfa_sm_send_event(itnim, BFA_ITNIM_SM_QRESUME);
}
void
bfa_itnim_iodone(struct bfa_itnim_s *itnim)
{
bfa_wc_down(&itnim->wc);
}
void
bfa_itnim_tskdone(struct bfa_itnim_s *itnim)
{
bfa_wc_down(&itnim->wc);
}
void
bfa_itnim_meminfo(struct bfa_iocfc_cfg_s *cfg, u32 *km_len,
u32 *dm_len)
{
*km_len += cfg->fwcfg.num_rports * sizeof(struct bfa_itnim_s);
}
void
bfa_itnim_attach(struct bfa_fcpim_mod_s *fcpim, struct bfa_meminfo_s *minfo)
{
struct bfa_s *bfa = fcpim->bfa;
struct bfa_itnim_s *itnim;
int i, j;
INIT_LIST_HEAD(&fcpim->itnim_q);
itnim = (struct bfa_itnim_s *) bfa_meminfo_kva(minfo);
fcpim->itnim_arr = itnim;
for (i = 0; i < fcpim->num_itnims; i++, itnim++) {
memset(itnim, 0, sizeof(struct bfa_itnim_s));
itnim->bfa = bfa;
itnim->fcpim = fcpim;
itnim->reqq = BFA_REQQ_QOS_LO;
itnim->rport = BFA_RPORT_FROM_TAG(bfa, i);
itnim->iotov_active = BFA_FALSE;
bfa_reqq_winit(&itnim->reqq_wait, bfa_itnim_qresume, itnim);
INIT_LIST_HEAD(&itnim->io_q);
INIT_LIST_HEAD(&itnim->io_cleanup_q);
INIT_LIST_HEAD(&itnim->pending_q);
INIT_LIST_HEAD(&itnim->tsk_q);
INIT_LIST_HEAD(&itnim->delay_comp_q);
for (j = 0; j < BFA_IOBUCKET_MAX; j++)
itnim->ioprofile.io_latency.min[j] = ~0;
bfa_sm_set_state(itnim, bfa_itnim_sm_uninit);
}
bfa_meminfo_kva(minfo) = (u8 *) itnim;
}
void
bfa_itnim_iocdisable(struct bfa_itnim_s *itnim)
{
bfa_stats(itnim, ioc_disabled);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_HWFAIL);
}
static bfa_boolean_t
bfa_itnim_send_fwcreate(struct bfa_itnim_s *itnim)
{
struct bfi_itnim_create_req_s *m;
itnim->msg_no++;
m = bfa_reqq_next(itnim->bfa, itnim->reqq);
if (!m) {
bfa_reqq_wait(itnim->bfa, itnim->reqq, &itnim->reqq_wait);
return BFA_FALSE;
}
bfi_h2i_set(m->mh, BFI_MC_ITNIM, BFI_ITNIM_H2I_CREATE_REQ,
bfa_lpuid(itnim->bfa));
m->fw_handle = itnim->rport->fw_handle;
m->class = FC_CLASS_3;
m->seq_rec = itnim->seq_rec;
m->msg_no = itnim->msg_no;
bfa_stats(itnim, fw_create);
bfa_reqq_produce(itnim->bfa, itnim->reqq);
return BFA_TRUE;
}
static bfa_boolean_t
bfa_itnim_send_fwdelete(struct bfa_itnim_s *itnim)
{
struct bfi_itnim_delete_req_s *m;
m = bfa_reqq_next(itnim->bfa, itnim->reqq);
if (!m) {
bfa_reqq_wait(itnim->bfa, itnim->reqq, &itnim->reqq_wait);
return BFA_FALSE;
}
bfi_h2i_set(m->mh, BFI_MC_ITNIM, BFI_ITNIM_H2I_DELETE_REQ,
bfa_lpuid(itnim->bfa));
m->fw_handle = itnim->rport->fw_handle;
bfa_stats(itnim, fw_delete);
bfa_reqq_produce(itnim->bfa, itnim->reqq);
return BFA_TRUE;
}
static void
bfa_itnim_delayed_comp(struct bfa_itnim_s *itnim, bfa_boolean_t iotov)
{
struct bfa_ioim_s *ioim;
struct list_head *qe, *qen;
list_for_each_safe(qe, qen, &itnim->delay_comp_q) {
ioim = (struct bfa_ioim_s *)qe;
bfa_ioim_delayed_comp(ioim, iotov);
}
}
static void
bfa_itnim_iotov_online(struct bfa_itnim_s *itnim)
{
struct bfa_ioim_s *ioim;
bfa_itnim_iotov_stop(itnim);
bfa_itnim_delayed_comp(itnim, BFA_FALSE);
while (!list_empty(&itnim->pending_q)) {
bfa_q_deq(&itnim->pending_q, &ioim);
list_add_tail(&ioim->qe, &itnim->io_q);
bfa_ioim_start(ioim);
}
}
static void
bfa_itnim_iotov_cleanup(struct bfa_itnim_s *itnim)
{
struct bfa_ioim_s *ioim;
bfa_itnim_delayed_comp(itnim, BFA_TRUE);
while (!list_empty(&itnim->pending_q)) {
bfa_q_deq(&itnim->pending_q, &ioim);
list_add_tail(&ioim->qe, &ioim->fcpim->ioim_comp_q);
bfa_ioim_tov(ioim);
}
}
static void
bfa_itnim_iotov(void *itnim_arg)
{
struct bfa_itnim_s *itnim = itnim_arg;
itnim->iotov_active = BFA_FALSE;
bfa_cb_itnim_tov_begin(itnim->ditn);
bfa_itnim_iotov_cleanup(itnim);
bfa_cb_itnim_tov(itnim->ditn);
}
static void
bfa_itnim_iotov_start(struct bfa_itnim_s *itnim)
{
if (itnim->fcpim->path_tov > 0) {
itnim->iotov_active = BFA_TRUE;
WARN_ON(!bfa_itnim_hold_io(itnim));
bfa_timer_start(itnim->bfa, &itnim->timer,
bfa_itnim_iotov, itnim, itnim->fcpim->path_tov);
}
}
static void
bfa_itnim_iotov_stop(struct bfa_itnim_s *itnim)
{
if (itnim->iotov_active) {
itnim->iotov_active = BFA_FALSE;
bfa_timer_stop(&itnim->timer);
}
}
static void
bfa_itnim_iotov_delete(struct bfa_itnim_s *itnim)
{
bfa_boolean_t pathtov_active = BFA_FALSE;
if (itnim->iotov_active)
pathtov_active = BFA_TRUE;
bfa_itnim_iotov_stop(itnim);
if (pathtov_active)
bfa_cb_itnim_tov_begin(itnim->ditn);
bfa_itnim_iotov_cleanup(itnim);
if (pathtov_active)
bfa_cb_itnim_tov(itnim->ditn);
}
static void
bfa_itnim_update_del_itn_stats(struct bfa_itnim_s *itnim)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(itnim->bfa);
fcpim->del_itn_stats.del_itn_iocomp_aborted +=
itnim->stats.iocomp_aborted;
fcpim->del_itn_stats.del_itn_iocomp_timedout +=
itnim->stats.iocomp_timedout;
fcpim->del_itn_stats.del_itn_iocom_sqer_needed +=
itnim->stats.iocom_sqer_needed;
fcpim->del_itn_stats.del_itn_iocom_res_free +=
itnim->stats.iocom_res_free;
fcpim->del_itn_stats.del_itn_iocom_hostabrts +=
itnim->stats.iocom_hostabrts;
fcpim->del_itn_stats.del_itn_total_ios += itnim->stats.total_ios;
fcpim->del_itn_stats.del_io_iocdowns += itnim->stats.io_iocdowns;
fcpim->del_itn_stats.del_tm_iocdowns += itnim->stats.tm_iocdowns;
}
void
bfa_itnim_isr(struct bfa_s *bfa, struct bfi_msg_s *m)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
union bfi_itnim_i2h_msg_u msg;
struct bfa_itnim_s *itnim;
bfa_trc(bfa, m->mhdr.msg_id);
msg.msg = m;
switch (m->mhdr.msg_id) {
case BFI_ITNIM_I2H_CREATE_RSP:
itnim = BFA_ITNIM_FROM_TAG(fcpim,
msg.create_rsp->bfa_handle);
WARN_ON(msg.create_rsp->status != BFA_STATUS_OK);
bfa_stats(itnim, create_comps);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_FWRSP);
break;
case BFI_ITNIM_I2H_DELETE_RSP:
itnim = BFA_ITNIM_FROM_TAG(fcpim,
msg.delete_rsp->bfa_handle);
WARN_ON(msg.delete_rsp->status != BFA_STATUS_OK);
bfa_stats(itnim, delete_comps);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_FWRSP);
break;
case BFI_ITNIM_I2H_SLER_EVENT:
itnim = BFA_ITNIM_FROM_TAG(fcpim,
msg.sler_event->bfa_handle);
bfa_stats(itnim, sler_events);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_SLER);
break;
default:
bfa_trc(bfa, m->mhdr.msg_id);
WARN_ON(1);
}
}
struct bfa_itnim_s *
bfa_itnim_create(struct bfa_s *bfa, struct bfa_rport_s *rport, void *ditn)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfa_itnim_s *itnim;
itnim = BFA_ITNIM_FROM_TAG(fcpim, rport->rport_tag);
WARN_ON(itnim->rport != rport);
itnim->ditn = ditn;
bfa_stats(itnim, creates);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_CREATE);
return itnim;
}
void
bfa_itnim_delete(struct bfa_itnim_s *itnim)
{
bfa_stats(itnim, deletes);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_DELETE);
}
void
bfa_itnim_online(struct bfa_itnim_s *itnim, bfa_boolean_t seq_rec)
{
itnim->seq_rec = seq_rec;
bfa_stats(itnim, onlines);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_ONLINE);
}
void
bfa_itnim_offline(struct bfa_itnim_s *itnim)
{
bfa_stats(itnim, offlines);
bfa_sm_send_event(itnim, BFA_ITNIM_SM_OFFLINE);
}
bfa_boolean_t
bfa_itnim_hold_io(struct bfa_itnim_s *itnim)
{
return itnim->fcpim->path_tov && itnim->iotov_active &&
(bfa_sm_cmp_state(itnim, bfa_itnim_sm_fwcreate) ||
bfa_sm_cmp_state(itnim, bfa_itnim_sm_sler) ||
bfa_sm_cmp_state(itnim, bfa_itnim_sm_cleanup_offline) ||
bfa_sm_cmp_state(itnim, bfa_itnim_sm_fwdelete) ||
bfa_sm_cmp_state(itnim, bfa_itnim_sm_offline) ||
bfa_sm_cmp_state(itnim, bfa_itnim_sm_iocdisable));
}
void
bfa_itnim_clear_stats(struct bfa_itnim_s *itnim)
{
int j;
memset(&itnim->stats, 0, sizeof(itnim->stats));
memset(&itnim->ioprofile, 0, sizeof(itnim->ioprofile));
for (j = 0; j < BFA_IOBUCKET_MAX; j++)
itnim->ioprofile.io_latency.min[j] = ~0;
}
static void
bfa_ioim_sm_uninit(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
switch (event) {
case BFA_IOIM_SM_START:
if (!bfa_itnim_is_online(ioim->itnim)) {
if (!bfa_itnim_hold_io(ioim->itnim)) {
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
list_del(&ioim->qe);
list_add_tail(&ioim->qe,
&ioim->fcpim->ioim_comp_q);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe,
__bfa_cb_ioim_pathtov, ioim);
} else {
list_del(&ioim->qe);
list_add_tail(&ioim->qe,
&ioim->itnim->pending_q);
}
break;
}
if (ioim->nsges > BFI_SGE_INLINE) {
if (!bfa_ioim_sgpg_alloc(ioim)) {
bfa_sm_set_state(ioim, bfa_ioim_sm_sgalloc);
return;
}
}
if (!bfa_ioim_send_ioreq(ioim)) {
bfa_sm_set_state(ioim, bfa_ioim_sm_qfull);
break;
}
bfa_sm_set_state(ioim, bfa_ioim_sm_active);
break;
case BFA_IOIM_SM_IOTOV:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe,
__bfa_cb_ioim_pathtov, ioim);
break;
case BFA_IOIM_SM_ABORT:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
WARN_ON(!bfa_q_is_on_q(&ioim->itnim->pending_q, ioim));
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe,
__bfa_cb_ioim_abort, ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_sgalloc(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_SGALLOCED:
if (!bfa_ioim_send_ioreq(ioim)) {
bfa_sm_set_state(ioim, bfa_ioim_sm_qfull);
break;
}
bfa_sm_set_state(ioim, bfa_ioim_sm_active);
break;
case BFA_IOIM_SM_CLEANUP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_sgpg_wcancel(ioim->bfa, &ioim->iosp->sgpg_wqe);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_ABORT:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_sgpg_wcancel(ioim->bfa, &ioim->iosp->sgpg_wqe);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_sgpg_wcancel(ioim->bfa, &ioim->iosp->sgpg_wqe);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_active(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
switch (event) {
case BFA_IOIM_SM_COMP_GOOD:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe,
__bfa_cb_ioim_good_comp, ioim);
break;
case BFA_IOIM_SM_COMP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_comp,
ioim);
break;
case BFA_IOIM_SM_DONE:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_comp,
ioim);
break;
case BFA_IOIM_SM_ABORT:
ioim->iosp->abort_explicit = BFA_TRUE;
ioim->io_cbfn = __bfa_cb_ioim_abort;
if (bfa_ioim_send_abort(ioim))
bfa_sm_set_state(ioim, bfa_ioim_sm_abort);
else {
bfa_sm_set_state(ioim, bfa_ioim_sm_abort_qfull);
bfa_stats(ioim->itnim, qwait);
bfa_reqq_wait(ioim->bfa, ioim->reqq,
&ioim->iosp->reqq_wait);
}
break;
case BFA_IOIM_SM_CLEANUP:
ioim->iosp->abort_explicit = BFA_FALSE;
ioim->io_cbfn = __bfa_cb_ioim_failed;
if (bfa_ioim_send_abort(ioim))
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup);
else {
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup_qfull);
bfa_stats(ioim->itnim, qwait);
bfa_reqq_wait(ioim->bfa, ioim->reqq,
&ioim->iosp->reqq_wait);
}
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
case BFA_IOIM_SM_SQRETRY:
if (bfa_ioim_maxretry_reached(ioim)) {
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe,
__bfa_cb_ioim_failed, ioim);
break;
}
bfa_sm_set_state(ioim, bfa_ioim_sm_cmnd_retry);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_cmnd_retry(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
switch (event) {
case BFA_IOIM_SM_FREE:
bfa_ioim_update_iotag(ioim);
if (!bfa_ioim_send_ioreq(ioim)) {
bfa_sm_set_state(ioim, bfa_ioim_sm_qfull);
break;
}
bfa_sm_set_state(ioim, bfa_ioim_sm_active);
break;
case BFA_IOIM_SM_CLEANUP:
ioim->iosp->abort_explicit = BFA_FALSE;
ioim->io_cbfn = __bfa_cb_ioim_failed;
if (bfa_ioim_send_abort(ioim))
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup);
else {
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup_qfull);
bfa_stats(ioim->itnim, qwait);
bfa_reqq_wait(ioim->bfa, ioim->reqq,
&ioim->iosp->reqq_wait);
}
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe,
__bfa_cb_ioim_failed, ioim);
break;
case BFA_IOIM_SM_ABORT:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_abort(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_COMP_GOOD:
case BFA_IOIM_SM_COMP:
case BFA_IOIM_SM_DONE:
case BFA_IOIM_SM_FREE:
break;
case BFA_IOIM_SM_ABORT_DONE:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_ABORT_COMP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_COMP_UTAG:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_CLEANUP:
WARN_ON(ioim->iosp->abort_explicit != BFA_TRUE);
ioim->iosp->abort_explicit = BFA_FALSE;
if (bfa_ioim_send_abort(ioim))
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup);
else {
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup_qfull);
bfa_stats(ioim->itnim, qwait);
bfa_reqq_wait(ioim->bfa, ioim->reqq,
&ioim->iosp->reqq_wait);
}
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_cleanup(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_COMP_GOOD:
case BFA_IOIM_SM_COMP:
case BFA_IOIM_SM_DONE:
case BFA_IOIM_SM_FREE:
break;
case BFA_IOIM_SM_ABORT:
ioim->io_cbfn = __bfa_cb_ioim_abort;
break;
case BFA_IOIM_SM_ABORT_DONE:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, ioim->io_cbfn, ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_ABORT_COMP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, ioim->io_cbfn, ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_COMP_UTAG:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, ioim->io_cbfn, ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
case BFA_IOIM_SM_CLEANUP:
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_qfull(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_QRESUME:
bfa_sm_set_state(ioim, bfa_ioim_sm_active);
bfa_ioim_send_ioreq(ioim);
break;
case BFA_IOIM_SM_ABORT:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_CLEANUP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_abort_qfull(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_QRESUME:
bfa_sm_set_state(ioim, bfa_ioim_sm_abort);
bfa_ioim_send_abort(ioim);
break;
case BFA_IOIM_SM_CLEANUP:
WARN_ON(ioim->iosp->abort_explicit != BFA_TRUE);
ioim->iosp->abort_explicit = BFA_FALSE;
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup_qfull);
break;
case BFA_IOIM_SM_COMP_GOOD:
case BFA_IOIM_SM_COMP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_DONE:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_abort,
ioim);
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_cleanup_qfull(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_QRESUME:
bfa_sm_set_state(ioim, bfa_ioim_sm_cleanup);
bfa_ioim_send_abort(ioim);
break;
case BFA_IOIM_SM_ABORT:
ioim->io_cbfn = __bfa_cb_ioim_abort;
break;
case BFA_IOIM_SM_COMP_GOOD:
case BFA_IOIM_SM_COMP:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, ioim->io_cbfn, ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_DONE:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb_free);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, ioim->io_cbfn, ioim);
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
bfa_reqq_wcancel(&ioim->iosp->reqq_wait);
bfa_ioim_move_to_comp_q(ioim);
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, __bfa_cb_ioim_failed,
ioim);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_hcb(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
switch (event) {
case BFA_IOIM_SM_HCB:
bfa_sm_set_state(ioim, bfa_ioim_sm_uninit);
bfa_ioim_free(ioim);
break;
case BFA_IOIM_SM_CLEANUP:
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_HWFAIL:
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_hcb_free(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_HCB:
bfa_sm_set_state(ioim, bfa_ioim_sm_resfree);
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &ioim->fcpim->ioim_resfree_q);
break;
case BFA_IOIM_SM_FREE:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
break;
case BFA_IOIM_SM_CLEANUP:
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_HWFAIL:
bfa_sm_set_state(ioim, bfa_ioim_sm_hcb);
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
bfa_ioim_sm_resfree(struct bfa_ioim_s *ioim, enum bfa_ioim_event event)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, event);
switch (event) {
case BFA_IOIM_SM_FREE:
bfa_sm_set_state(ioim, bfa_ioim_sm_uninit);
bfa_ioim_free(ioim);
break;
case BFA_IOIM_SM_CLEANUP:
bfa_ioim_notify_cleanup(ioim);
break;
case BFA_IOIM_SM_HWFAIL:
break;
default:
bfa_sm_fault(ioim->bfa, event);
}
}
static void
__bfa_cb_ioim_good_comp(void *cbarg, bfa_boolean_t complete)
{
struct bfa_ioim_s *ioim = cbarg;
if (!complete) {
bfa_sm_send_event(ioim, BFA_IOIM_SM_HCB);
return;
}
bfa_cb_ioim_good_comp(ioim->bfa->bfad, ioim->dio);
}
static void
__bfa_cb_ioim_comp(void *cbarg, bfa_boolean_t complete)
{
struct bfa_ioim_s *ioim = cbarg;
struct bfi_ioim_rsp_s *m;
u8 *snsinfo = NULL;
u8 sns_len = 0;
s32 residue = 0;
if (!complete) {
bfa_sm_send_event(ioim, BFA_IOIM_SM_HCB);
return;
}
m = (struct bfi_ioim_rsp_s *) &ioim->iosp->comp_rspmsg;
if (m->io_status == BFI_IOIM_STS_OK) {
if ((m->scsi_status == SCSI_STATUS_CHECK_CONDITION) &&
m->sns_len) {
sns_len = m->sns_len;
snsinfo = ioim->iosp->snsinfo;
}
if (m->resid_flags == FCP_RESID_UNDER) {
residue = be32_to_cpu(m->residue);
bfa_stats(ioim->itnim, iocomp_underrun);
}
if (m->resid_flags == FCP_RESID_OVER) {
residue = be32_to_cpu(m->residue);
residue = -residue;
bfa_stats(ioim->itnim, iocomp_overrun);
}
}
bfa_cb_ioim_done(ioim->bfa->bfad, ioim->dio, m->io_status,
m->scsi_status, sns_len, snsinfo, residue);
}
static void
__bfa_cb_ioim_failed(void *cbarg, bfa_boolean_t complete)
{
struct bfa_ioim_s *ioim = cbarg;
if (!complete) {
bfa_sm_send_event(ioim, BFA_IOIM_SM_HCB);
return;
}
bfa_cb_ioim_done(ioim->bfa->bfad, ioim->dio, BFI_IOIM_STS_ABORTED,
0, 0, NULL, 0);
}
static void
__bfa_cb_ioim_pathtov(void *cbarg, bfa_boolean_t complete)
{
struct bfa_ioim_s *ioim = cbarg;
bfa_stats(ioim->itnim, path_tov_expired);
if (!complete) {
bfa_sm_send_event(ioim, BFA_IOIM_SM_HCB);
return;
}
bfa_cb_ioim_done(ioim->bfa->bfad, ioim->dio, BFI_IOIM_STS_PATHTOV,
0, 0, NULL, 0);
}
static void
__bfa_cb_ioim_abort(void *cbarg, bfa_boolean_t complete)
{
struct bfa_ioim_s *ioim = cbarg;
if (!complete) {
bfa_sm_send_event(ioim, BFA_IOIM_SM_HCB);
return;
}
bfa_cb_ioim_abort(ioim->bfa->bfad, ioim->dio);
}
static void
bfa_ioim_sgpg_alloced(void *cbarg)
{
struct bfa_ioim_s *ioim = cbarg;
ioim->nsgpgs = BFA_SGPG_NPAGE(ioim->nsges);
list_splice_tail_init(&ioim->iosp->sgpg_wqe.sgpg_q, &ioim->sgpg_q);
ioim->sgpg = bfa_q_first(&ioim->sgpg_q);
bfa_sm_send_event(ioim, BFA_IOIM_SM_SGALLOCED);
}
static bfa_boolean_t
bfa_ioim_send_ioreq(struct bfa_ioim_s *ioim)
{
struct bfa_itnim_s *itnim = ioim->itnim;
struct bfi_ioim_req_s *m;
static struct fcp_cmnd_s cmnd_z0 = { { { 0 } } };
struct bfi_sge_s *sge, *sgpge;
u32 pgdlen = 0;
u32 fcp_dl;
u64 addr;
struct scatterlist *sg;
struct bfa_sgpg_s *sgpg;
struct scsi_cmnd *cmnd = (struct scsi_cmnd *) ioim->dio;
u32 i, sge_id, pgcumsz;
enum dma_data_direction dmadir;
m = bfa_reqq_next(ioim->bfa, ioim->reqq);
if (!m) {
bfa_stats(ioim->itnim, qwait);
bfa_reqq_wait(ioim->bfa, ioim->reqq,
&ioim->iosp->reqq_wait);
return BFA_FALSE;
}
m->io_tag = cpu_to_be16(ioim->iotag);
m->rport_hdl = ioim->itnim->rport->fw_handle;
m->io_timeout = 0;
sge = &m->sges[0];
sgpg = ioim->sgpg;
sge_id = 0;
sgpge = NULL;
pgcumsz = 0;
scsi_for_each_sg(cmnd, sg, ioim->nsges, i) {
if (i == 0) {
addr = bfa_sgaddr_le(sg_dma_address(sg));
sge->sga = *(union bfi_addr_u *) &addr;
pgdlen = sg_dma_len(sg);
sge->sg_len = pgdlen;
sge->flags = (ioim->nsges > BFI_SGE_INLINE) ?
BFI_SGE_DATA_CPL : BFI_SGE_DATA_LAST;
bfa_sge_to_be(sge);
sge++;
} else {
if (sge_id == 0)
sgpge = sgpg->sgpg->sges;
addr = bfa_sgaddr_le(sg_dma_address(sg));
sgpge->sga = *(union bfi_addr_u *) &addr;
sgpge->sg_len = sg_dma_len(sg);
pgcumsz += sgpge->sg_len;
if (i < (ioim->nsges - 1) &&
sge_id < (BFI_SGPG_DATA_SGES - 1))
sgpge->flags = BFI_SGE_DATA;
else if (i < (ioim->nsges - 1))
sgpge->flags = BFI_SGE_DATA_CPL;
else
sgpge->flags = BFI_SGE_DATA_LAST;
bfa_sge_to_le(sgpge);
sgpge++;
if (i == (ioim->nsges - 1)) {
sgpge->flags = BFI_SGE_PGDLEN;
sgpge->sga.a32.addr_lo = 0;
sgpge->sga.a32.addr_hi = 0;
sgpge->sg_len = pgcumsz;
bfa_sge_to_le(sgpge);
} else if (++sge_id == BFI_SGPG_DATA_SGES) {
sgpg = (struct bfa_sgpg_s *) bfa_q_next(sgpg);
sgpge->flags = BFI_SGE_LINK;
sgpge->sga = sgpg->sgpg_pa;
sgpge->sg_len = pgcumsz;
bfa_sge_to_le(sgpge);
sge_id = 0;
pgcumsz = 0;
}
}
}
if (ioim->nsges > BFI_SGE_INLINE) {
sge->sga = ioim->sgpg->sgpg_pa;
} else {
sge->sga.a32.addr_lo = 0;
sge->sga.a32.addr_hi = 0;
}
sge->sg_len = pgdlen;
sge->flags = BFI_SGE_PGDLEN;
bfa_sge_to_be(sge);
m->cmnd = cmnd_z0;
int_to_scsilun(cmnd->device->lun, &m->cmnd.lun);
dmadir = cmnd->sc_data_direction;
if (dmadir == DMA_TO_DEVICE)
m->cmnd.iodir = FCP_IODIR_WRITE;
else if (dmadir == DMA_FROM_DEVICE)
m->cmnd.iodir = FCP_IODIR_READ;
else
m->cmnd.iodir = FCP_IODIR_NONE;
m->cmnd.cdb = *(struct scsi_cdb_s *) cmnd->cmnd;
fcp_dl = scsi_bufflen(cmnd);
m->cmnd.fcp_dl = cpu_to_be32(fcp_dl);
switch (m->cmnd.iodir) {
case FCP_IODIR_READ:
bfi_h2i_set(m->mh, BFI_MC_IOIM_READ, 0, bfa_lpuid(ioim->bfa));
bfa_stats(itnim, input_reqs);
ioim->itnim->stats.rd_throughput += fcp_dl;
break;
case FCP_IODIR_WRITE:
bfi_h2i_set(m->mh, BFI_MC_IOIM_WRITE, 0, bfa_lpuid(ioim->bfa));
bfa_stats(itnim, output_reqs);
ioim->itnim->stats.wr_throughput += fcp_dl;
break;
case FCP_IODIR_RW:
bfa_stats(itnim, input_reqs);
bfa_stats(itnim, output_reqs);
default:
bfi_h2i_set(m->mh, BFI_MC_IOIM_IO, 0, bfa_lpuid(ioim->bfa));
}
if (itnim->seq_rec ||
(scsi_bufflen(cmnd) & (sizeof(u32) - 1)))
bfi_h2i_set(m->mh, BFI_MC_IOIM_IO, 0, bfa_lpuid(ioim->bfa));
bfa_reqq_produce(ioim->bfa, ioim->reqq);
return BFA_TRUE;
}
static bfa_boolean_t
bfa_ioim_sgpg_alloc(struct bfa_ioim_s *ioim)
{
u16 nsgpgs;
WARN_ON(ioim->nsges <= BFI_SGE_INLINE);
nsgpgs = BFA_SGPG_NPAGE(ioim->nsges);
if (!nsgpgs)
return BFA_TRUE;
if (bfa_sgpg_malloc(ioim->bfa, &ioim->sgpg_q, nsgpgs)
!= BFA_STATUS_OK) {
bfa_sgpg_wait(ioim->bfa, &ioim->iosp->sgpg_wqe, nsgpgs);
return BFA_FALSE;
}
ioim->nsgpgs = nsgpgs;
ioim->sgpg = bfa_q_first(&ioim->sgpg_q);
return BFA_TRUE;
}
static bfa_boolean_t
bfa_ioim_send_abort(struct bfa_ioim_s *ioim)
{
struct bfi_ioim_abort_req_s *m;
enum bfi_ioim_h2i msgop;
m = bfa_reqq_next(ioim->bfa, ioim->reqq);
if (!m)
return BFA_FALSE;
if (ioim->iosp->abort_explicit)
msgop = BFI_IOIM_H2I_IOABORT_REQ;
else
msgop = BFI_IOIM_H2I_IOCLEANUP_REQ;
bfi_h2i_set(m->mh, BFI_MC_IOIM, msgop, bfa_lpuid(ioim->bfa));
m->io_tag = cpu_to_be16(ioim->iotag);
m->abort_tag = ++ioim->abort_tag;
bfa_reqq_produce(ioim->bfa, ioim->reqq);
return BFA_TRUE;
}
static void
bfa_ioim_qresume(void *cbarg)
{
struct bfa_ioim_s *ioim = cbarg;
bfa_stats(ioim->itnim, qresumes);
bfa_sm_send_event(ioim, BFA_IOIM_SM_QRESUME);
}
static void
bfa_ioim_notify_cleanup(struct bfa_ioim_s *ioim)
{
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &ioim->fcpim->ioim_comp_q);
if (!ioim->iosp->tskim) {
if (ioim->fcpim->delay_comp && ioim->itnim->iotov_active) {
bfa_cb_dequeue(&ioim->hcb_qe);
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &ioim->itnim->delay_comp_q);
}
bfa_itnim_iodone(ioim->itnim);
} else
bfa_wc_down(&ioim->iosp->tskim->wc);
}
static bfa_boolean_t
bfa_ioim_is_abortable(struct bfa_ioim_s *ioim)
{
if ((bfa_sm_cmp_state(ioim, bfa_ioim_sm_uninit) &&
(!bfa_q_is_on_q(&ioim->itnim->pending_q, ioim))) ||
(bfa_sm_cmp_state(ioim, bfa_ioim_sm_abort)) ||
(bfa_sm_cmp_state(ioim, bfa_ioim_sm_abort_qfull)) ||
(bfa_sm_cmp_state(ioim, bfa_ioim_sm_hcb)) ||
(bfa_sm_cmp_state(ioim, bfa_ioim_sm_hcb_free)) ||
(bfa_sm_cmp_state(ioim, bfa_ioim_sm_resfree)))
return BFA_FALSE;
return BFA_TRUE;
}
void
bfa_ioim_delayed_comp(struct bfa_ioim_s *ioim, bfa_boolean_t iotov)
{
if (iotov)
ioim->io_cbfn = __bfa_cb_ioim_pathtov;
else {
ioim->io_cbfn = __bfa_cb_ioim_failed;
bfa_stats(ioim->itnim, iocom_nexus_abort);
}
bfa_cb_queue(ioim->bfa, &ioim->hcb_qe, ioim->io_cbfn, ioim);
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &ioim->fcpim->ioim_comp_q);
}
void
bfa_ioim_attach(struct bfa_fcpim_mod_s *fcpim, struct bfa_meminfo_s *minfo)
{
struct bfa_ioim_s *ioim;
struct bfa_ioim_sp_s *iosp;
u16 i;
u8 *snsinfo;
u32 snsbufsz;
ioim = (struct bfa_ioim_s *) bfa_meminfo_kva(minfo);
fcpim->ioim_arr = ioim;
bfa_meminfo_kva(minfo) = (u8 *) (ioim + fcpim->num_ioim_reqs);
iosp = (struct bfa_ioim_sp_s *) bfa_meminfo_kva(minfo);
fcpim->ioim_sp_arr = iosp;
bfa_meminfo_kva(minfo) = (u8 *) (iosp + fcpim->num_ioim_reqs);
snsbufsz = fcpim->num_ioim_reqs * BFI_IOIM_SNSLEN;
fcpim->snsbase.pa = bfa_meminfo_dma_phys(minfo);
bfa_meminfo_dma_phys(minfo) += snsbufsz;
fcpim->snsbase.kva = bfa_meminfo_dma_virt(minfo);
bfa_meminfo_dma_virt(minfo) += snsbufsz;
snsinfo = fcpim->snsbase.kva;
bfa_iocfc_set_snsbase(fcpim->bfa, fcpim->snsbase.pa);
INIT_LIST_HEAD(&fcpim->ioim_free_q);
INIT_LIST_HEAD(&fcpim->ioim_resfree_q);
INIT_LIST_HEAD(&fcpim->ioim_comp_q);
for (i = 0; i < fcpim->num_ioim_reqs;
i++, ioim++, iosp++, snsinfo += BFI_IOIM_SNSLEN) {
memset(ioim, 0, sizeof(struct bfa_ioim_s));
ioim->iotag = i;
ioim->bfa = fcpim->bfa;
ioim->fcpim = fcpim;
ioim->iosp = iosp;
iosp->snsinfo = snsinfo;
INIT_LIST_HEAD(&ioim->sgpg_q);
bfa_reqq_winit(&ioim->iosp->reqq_wait,
bfa_ioim_qresume, ioim);
bfa_sgpg_winit(&ioim->iosp->sgpg_wqe,
bfa_ioim_sgpg_alloced, ioim);
bfa_sm_set_state(ioim, bfa_ioim_sm_uninit);
list_add_tail(&ioim->qe, &fcpim->ioim_free_q);
}
}
void
bfa_ioim_isr(struct bfa_s *bfa, struct bfi_msg_s *m)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfi_ioim_rsp_s *rsp = (struct bfi_ioim_rsp_s *) m;
struct bfa_ioim_s *ioim;
u16 iotag;
enum bfa_ioim_event evt = BFA_IOIM_SM_COMP;
iotag = be16_to_cpu(rsp->io_tag);
ioim = BFA_IOIM_FROM_TAG(fcpim, iotag);
WARN_ON(ioim->iotag != iotag);
bfa_trc(ioim->bfa, ioim->iotag);
bfa_trc(ioim->bfa, rsp->io_status);
bfa_trc(ioim->bfa, rsp->reuse_io_tag);
if (bfa_sm_cmp_state(ioim, bfa_ioim_sm_active))
ioim->iosp->comp_rspmsg = *m;
switch (rsp->io_status) {
case BFI_IOIM_STS_OK:
bfa_stats(ioim->itnim, iocomp_ok);
if (rsp->reuse_io_tag == 0)
evt = BFA_IOIM_SM_DONE;
else
evt = BFA_IOIM_SM_COMP;
break;
case BFI_IOIM_STS_TIMEDOUT:
bfa_stats(ioim->itnim, iocomp_timedout);
case BFI_IOIM_STS_ABORTED:
rsp->io_status = BFI_IOIM_STS_ABORTED;
bfa_stats(ioim->itnim, iocomp_aborted);
if (rsp->reuse_io_tag == 0)
evt = BFA_IOIM_SM_DONE;
else
evt = BFA_IOIM_SM_COMP;
break;
case BFI_IOIM_STS_PROTO_ERR:
bfa_stats(ioim->itnim, iocom_proto_err);
WARN_ON(!rsp->reuse_io_tag);
evt = BFA_IOIM_SM_COMP;
break;
case BFI_IOIM_STS_SQER_NEEDED:
bfa_stats(ioim->itnim, iocom_sqer_needed);
WARN_ON(rsp->reuse_io_tag != 0);
evt = BFA_IOIM_SM_SQRETRY;
break;
case BFI_IOIM_STS_RES_FREE:
bfa_stats(ioim->itnim, iocom_res_free);
evt = BFA_IOIM_SM_FREE;
break;
case BFI_IOIM_STS_HOST_ABORTED:
bfa_stats(ioim->itnim, iocom_hostabrts);
if (rsp->abort_tag != ioim->abort_tag) {
bfa_trc(ioim->bfa, rsp->abort_tag);
bfa_trc(ioim->bfa, ioim->abort_tag);
return;
}
if (rsp->reuse_io_tag)
evt = BFA_IOIM_SM_ABORT_COMP;
else
evt = BFA_IOIM_SM_ABORT_DONE;
break;
case BFI_IOIM_STS_UTAG:
bfa_stats(ioim->itnim, iocom_utags);
evt = BFA_IOIM_SM_COMP_UTAG;
break;
default:
WARN_ON(1);
}
bfa_sm_send_event(ioim, evt);
}
void
bfa_ioim_good_comp_isr(struct bfa_s *bfa, struct bfi_msg_s *m)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfi_ioim_rsp_s *rsp = (struct bfi_ioim_rsp_s *) m;
struct bfa_ioim_s *ioim;
u16 iotag;
iotag = be16_to_cpu(rsp->io_tag);
ioim = BFA_IOIM_FROM_TAG(fcpim, iotag);
WARN_ON(BFA_IOIM_TAG_2_ID(ioim->iotag) != iotag);
bfa_ioim_cb_profile_comp(fcpim, ioim);
bfa_sm_send_event(ioim, BFA_IOIM_SM_COMP_GOOD);
}
void
bfa_ioim_cleanup(struct bfa_ioim_s *ioim)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_stats(ioim->itnim, io_cleanups);
ioim->iosp->tskim = NULL;
bfa_sm_send_event(ioim, BFA_IOIM_SM_CLEANUP);
}
void
bfa_ioim_cleanup_tm(struct bfa_ioim_s *ioim, struct bfa_tskim_s *tskim)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_stats(ioim->itnim, io_tmaborts);
ioim->iosp->tskim = tskim;
bfa_sm_send_event(ioim, BFA_IOIM_SM_CLEANUP);
}
void
bfa_ioim_iocdisable(struct bfa_ioim_s *ioim)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_stats(ioim->itnim, io_iocdowns);
bfa_sm_send_event(ioim, BFA_IOIM_SM_HWFAIL);
}
void
bfa_ioim_tov(struct bfa_ioim_s *ioim)
{
bfa_trc(ioim->bfa, ioim->iotag);
bfa_sm_send_event(ioim, BFA_IOIM_SM_IOTOV);
}
struct bfa_ioim_s *
bfa_ioim_alloc(struct bfa_s *bfa, struct bfad_ioim_s *dio,
struct bfa_itnim_s *itnim, u16 nsges)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfa_ioim_s *ioim;
bfa_q_deq(&fcpim->ioim_free_q, &ioim);
if (!ioim) {
bfa_stats(itnim, no_iotags);
return NULL;
}
ioim->dio = dio;
ioim->itnim = itnim;
ioim->nsges = nsges;
ioim->nsgpgs = 0;
bfa_stats(itnim, total_ios);
fcpim->ios_active++;
list_add_tail(&ioim->qe, &itnim->io_q);
return ioim;
}
void
bfa_ioim_free(struct bfa_ioim_s *ioim)
{
struct bfa_fcpim_mod_s *fcpim = ioim->fcpim;
if (ioim->nsgpgs > 0)
bfa_sgpg_mfree(ioim->bfa, &ioim->sgpg_q, ioim->nsgpgs);
bfa_stats(ioim->itnim, io_comps);
fcpim->ios_active--;
ioim->iotag &= BFA_IOIM_IOTAG_MASK;
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &fcpim->ioim_free_q);
}
void
bfa_ioim_start(struct bfa_ioim_s *ioim)
{
bfa_ioim_cb_profile_start(ioim->fcpim, ioim);
ioim->reqq = bfa_fcpim_ioredirect_enabled(ioim->bfa) ?
BFA_FALSE : bfa_itnim_get_reqq(ioim);
bfa_sm_send_event(ioim, BFA_IOIM_SM_START);
}
bfa_status_t
bfa_ioim_abort(struct bfa_ioim_s *ioim)
{
bfa_trc(ioim->bfa, ioim->iotag);
if (!bfa_ioim_is_abortable(ioim))
return BFA_STATUS_FAILED;
bfa_stats(ioim->itnim, io_aborts);
bfa_sm_send_event(ioim, BFA_IOIM_SM_ABORT);
return BFA_STATUS_OK;
}
static void
bfa_tskim_sm_uninit(struct bfa_tskim_s *tskim, enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_START:
bfa_sm_set_state(tskim, bfa_tskim_sm_active);
bfa_tskim_gather_ios(tskim);
if (!bfa_itnim_is_online(tskim->itnim)) {
bfa_sm_set_state(tskim, bfa_tskim_sm_iocleanup);
tskim->tsk_status = BFI_TSKIM_STS_OK;
bfa_tskim_cleanup_ios(tskim);
return;
}
if (!bfa_tskim_send(tskim)) {
bfa_sm_set_state(tskim, bfa_tskim_sm_qfull);
bfa_stats(tskim->itnim, tm_qwait);
bfa_reqq_wait(tskim->bfa, tskim->itnim->reqq,
&tskim->reqq_wait);
}
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
bfa_tskim_sm_active(struct bfa_tskim_s *tskim, enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_DONE:
bfa_sm_set_state(tskim, bfa_tskim_sm_iocleanup);
bfa_tskim_cleanup_ios(tskim);
break;
case BFA_TSKIM_SM_CLEANUP:
bfa_sm_set_state(tskim, bfa_tskim_sm_cleanup);
if (!bfa_tskim_send_abort(tskim)) {
bfa_sm_set_state(tskim, bfa_tskim_sm_cleanup_qfull);
bfa_stats(tskim->itnim, tm_qwait);
bfa_reqq_wait(tskim->bfa, tskim->itnim->reqq,
&tskim->reqq_wait);
}
break;
case BFA_TSKIM_SM_HWFAIL:
bfa_sm_set_state(tskim, bfa_tskim_sm_hcb);
bfa_tskim_iocdisable_ios(tskim);
bfa_tskim_qcomp(tskim, __bfa_cb_tskim_failed);
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
bfa_tskim_sm_cleanup(struct bfa_tskim_s *tskim, enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_DONE:
break;
case BFA_TSKIM_SM_CLEANUP_DONE:
bfa_sm_set_state(tskim, bfa_tskim_sm_iocleanup);
bfa_tskim_cleanup_ios(tskim);
break;
case BFA_TSKIM_SM_HWFAIL:
bfa_sm_set_state(tskim, bfa_tskim_sm_hcb);
bfa_tskim_iocdisable_ios(tskim);
bfa_tskim_qcomp(tskim, __bfa_cb_tskim_failed);
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
bfa_tskim_sm_iocleanup(struct bfa_tskim_s *tskim, enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_IOS_DONE:
bfa_sm_set_state(tskim, bfa_tskim_sm_hcb);
bfa_tskim_qcomp(tskim, __bfa_cb_tskim_done);
break;
case BFA_TSKIM_SM_CLEANUP:
break;
case BFA_TSKIM_SM_HWFAIL:
bfa_sm_set_state(tskim, bfa_tskim_sm_hcb);
bfa_tskim_iocdisable_ios(tskim);
bfa_tskim_qcomp(tskim, __bfa_cb_tskim_failed);
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
bfa_tskim_sm_qfull(struct bfa_tskim_s *tskim, enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_QRESUME:
bfa_sm_set_state(tskim, bfa_tskim_sm_active);
bfa_tskim_send(tskim);
break;
case BFA_TSKIM_SM_CLEANUP:
bfa_sm_set_state(tskim, bfa_tskim_sm_iocleanup);
bfa_reqq_wcancel(&tskim->reqq_wait);
bfa_tskim_cleanup_ios(tskim);
break;
case BFA_TSKIM_SM_HWFAIL:
bfa_sm_set_state(tskim, bfa_tskim_sm_hcb);
bfa_reqq_wcancel(&tskim->reqq_wait);
bfa_tskim_iocdisable_ios(tskim);
bfa_tskim_qcomp(tskim, __bfa_cb_tskim_failed);
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
bfa_tskim_sm_cleanup_qfull(struct bfa_tskim_s *tskim,
enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_DONE:
bfa_reqq_wcancel(&tskim->reqq_wait);
case BFA_TSKIM_SM_QRESUME:
bfa_sm_set_state(tskim, bfa_tskim_sm_cleanup);
bfa_tskim_send_abort(tskim);
break;
case BFA_TSKIM_SM_HWFAIL:
bfa_sm_set_state(tskim, bfa_tskim_sm_hcb);
bfa_reqq_wcancel(&tskim->reqq_wait);
bfa_tskim_iocdisable_ios(tskim);
bfa_tskim_qcomp(tskim, __bfa_cb_tskim_failed);
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
bfa_tskim_sm_hcb(struct bfa_tskim_s *tskim, enum bfa_tskim_event event)
{
bfa_trc(tskim->bfa, event);
switch (event) {
case BFA_TSKIM_SM_HCB:
bfa_sm_set_state(tskim, bfa_tskim_sm_uninit);
bfa_tskim_free(tskim);
break;
case BFA_TSKIM_SM_CLEANUP:
bfa_tskim_notify_comp(tskim);
break;
case BFA_TSKIM_SM_HWFAIL:
break;
default:
bfa_sm_fault(tskim->bfa, event);
}
}
static void
__bfa_cb_tskim_done(void *cbarg, bfa_boolean_t complete)
{
struct bfa_tskim_s *tskim = cbarg;
if (!complete) {
bfa_sm_send_event(tskim, BFA_TSKIM_SM_HCB);
return;
}
bfa_stats(tskim->itnim, tm_success);
bfa_cb_tskim_done(tskim->bfa->bfad, tskim->dtsk, tskim->tsk_status);
}
static void
__bfa_cb_tskim_failed(void *cbarg, bfa_boolean_t complete)
{
struct bfa_tskim_s *tskim = cbarg;
if (!complete) {
bfa_sm_send_event(tskim, BFA_TSKIM_SM_HCB);
return;
}
bfa_stats(tskim->itnim, tm_failures);
bfa_cb_tskim_done(tskim->bfa->bfad, tskim->dtsk,
BFI_TSKIM_STS_FAILED);
}
static bfa_boolean_t
bfa_tskim_match_scope(struct bfa_tskim_s *tskim, struct scsi_lun lun)
{
switch (tskim->tm_cmnd) {
case FCP_TM_TARGET_RESET:
return BFA_TRUE;
case FCP_TM_ABORT_TASK_SET:
case FCP_TM_CLEAR_TASK_SET:
case FCP_TM_LUN_RESET:
case FCP_TM_CLEAR_ACA:
return !memcmp(&tskim->lun, &lun, sizeof(lun));
default:
WARN_ON(1);
}
return BFA_FALSE;
}
static void
bfa_tskim_gather_ios(struct bfa_tskim_s *tskim)
{
struct bfa_itnim_s *itnim = tskim->itnim;
struct bfa_ioim_s *ioim;
struct list_head *qe, *qen;
struct scsi_cmnd *cmnd;
struct scsi_lun scsilun;
INIT_LIST_HEAD(&tskim->io_q);
list_for_each_safe(qe, qen, &itnim->io_q) {
ioim = (struct bfa_ioim_s *) qe;
cmnd = (struct scsi_cmnd *) ioim->dio;
int_to_scsilun(cmnd->device->lun, &scsilun);
if (bfa_tskim_match_scope(tskim, scsilun)) {
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &tskim->io_q);
}
}
list_for_each_safe(qe, qen, &itnim->pending_q) {
ioim = (struct bfa_ioim_s *) qe;
cmnd = (struct scsi_cmnd *) ioim->dio;
int_to_scsilun(cmnd->device->lun, &scsilun);
if (bfa_tskim_match_scope(tskim, scsilun)) {
list_del(&ioim->qe);
list_add_tail(&ioim->qe, &ioim->fcpim->ioim_comp_q);
bfa_ioim_tov(ioim);
}
}
}
static void
bfa_tskim_cleanp_comp(void *tskim_cbarg)
{
struct bfa_tskim_s *tskim = tskim_cbarg;
bfa_stats(tskim->itnim, tm_io_comps);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_IOS_DONE);
}
static void
bfa_tskim_cleanup_ios(struct bfa_tskim_s *tskim)
{
struct bfa_ioim_s *ioim;
struct list_head *qe, *qen;
bfa_wc_init(&tskim->wc, bfa_tskim_cleanp_comp, tskim);
list_for_each_safe(qe, qen, &tskim->io_q) {
ioim = (struct bfa_ioim_s *) qe;
bfa_wc_up(&tskim->wc);
bfa_ioim_cleanup_tm(ioim, tskim);
}
bfa_wc_wait(&tskim->wc);
}
static bfa_boolean_t
bfa_tskim_send(struct bfa_tskim_s *tskim)
{
struct bfa_itnim_s *itnim = tskim->itnim;
struct bfi_tskim_req_s *m;
m = bfa_reqq_next(tskim->bfa, itnim->reqq);
if (!m)
return BFA_FALSE;
bfi_h2i_set(m->mh, BFI_MC_TSKIM, BFI_TSKIM_H2I_TM_REQ,
bfa_lpuid(tskim->bfa));
m->tsk_tag = cpu_to_be16(tskim->tsk_tag);
m->itn_fhdl = tskim->itnim->rport->fw_handle;
m->t_secs = tskim->tsecs;
m->lun = tskim->lun;
m->tm_flags = tskim->tm_cmnd;
bfa_reqq_produce(tskim->bfa, itnim->reqq);
return BFA_TRUE;
}
static bfa_boolean_t
bfa_tskim_send_abort(struct bfa_tskim_s *tskim)
{
struct bfa_itnim_s *itnim = tskim->itnim;
struct bfi_tskim_abortreq_s *m;
m = bfa_reqq_next(tskim->bfa, itnim->reqq);
if (!m)
return BFA_FALSE;
bfi_h2i_set(m->mh, BFI_MC_TSKIM, BFI_TSKIM_H2I_ABORT_REQ,
bfa_lpuid(tskim->bfa));
m->tsk_tag = cpu_to_be16(tskim->tsk_tag);
bfa_reqq_produce(tskim->bfa, itnim->reqq);
return BFA_TRUE;
}
static void
bfa_tskim_qresume(void *cbarg)
{
struct bfa_tskim_s *tskim = cbarg;
bfa_stats(tskim->itnim, tm_qresumes);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_QRESUME);
}
static void
bfa_tskim_iocdisable_ios(struct bfa_tskim_s *tskim)
{
struct bfa_ioim_s *ioim;
struct list_head *qe, *qen;
list_for_each_safe(qe, qen, &tskim->io_q) {
ioim = (struct bfa_ioim_s *) qe;
bfa_ioim_iocdisable(ioim);
}
}
void
bfa_tskim_iodone(struct bfa_tskim_s *tskim)
{
bfa_wc_down(&tskim->wc);
}
void
bfa_tskim_iocdisable(struct bfa_tskim_s *tskim)
{
tskim->notify = BFA_FALSE;
bfa_stats(tskim->itnim, tm_iocdowns);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_HWFAIL);
}
void
bfa_tskim_cleanup(struct bfa_tskim_s *tskim)
{
tskim->notify = BFA_TRUE;
bfa_stats(tskim->itnim, tm_cleanups);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_CLEANUP);
}
void
bfa_tskim_attach(struct bfa_fcpim_mod_s *fcpim, struct bfa_meminfo_s *minfo)
{
struct bfa_tskim_s *tskim;
u16 i;
INIT_LIST_HEAD(&fcpim->tskim_free_q);
tskim = (struct bfa_tskim_s *) bfa_meminfo_kva(minfo);
fcpim->tskim_arr = tskim;
for (i = 0; i < fcpim->num_tskim_reqs; i++, tskim++) {
memset(tskim, 0, sizeof(struct bfa_tskim_s));
tskim->tsk_tag = i;
tskim->bfa = fcpim->bfa;
tskim->fcpim = fcpim;
tskim->notify = BFA_FALSE;
bfa_reqq_winit(&tskim->reqq_wait, bfa_tskim_qresume,
tskim);
bfa_sm_set_state(tskim, bfa_tskim_sm_uninit);
list_add_tail(&tskim->qe, &fcpim->tskim_free_q);
}
bfa_meminfo_kva(minfo) = (u8 *) tskim;
}
void
bfa_tskim_isr(struct bfa_s *bfa, struct bfi_msg_s *m)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfi_tskim_rsp_s *rsp = (struct bfi_tskim_rsp_s *) m;
struct bfa_tskim_s *tskim;
u16 tsk_tag = be16_to_cpu(rsp->tsk_tag);
tskim = BFA_TSKIM_FROM_TAG(fcpim, tsk_tag);
WARN_ON(tskim->tsk_tag != tsk_tag);
tskim->tsk_status = rsp->tsk_status;
if (rsp->tsk_status == BFI_TSKIM_STS_ABORTED) {
bfa_stats(tskim->itnim, tm_cleanup_comps);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_CLEANUP_DONE);
} else {
bfa_stats(tskim->itnim, tm_fw_rsps);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_DONE);
}
}
struct bfa_tskim_s *
bfa_tskim_alloc(struct bfa_s *bfa, struct bfad_tskim_s *dtsk)
{
struct bfa_fcpim_mod_s *fcpim = BFA_FCPIM_MOD(bfa);
struct bfa_tskim_s *tskim;
bfa_q_deq(&fcpim->tskim_free_q, &tskim);
if (tskim)
tskim->dtsk = dtsk;
return tskim;
}
void
bfa_tskim_free(struct bfa_tskim_s *tskim)
{
WARN_ON(!bfa_q_is_on_q_func(&tskim->itnim->tsk_q, &tskim->qe));
list_del(&tskim->qe);
list_add_tail(&tskim->qe, &tskim->fcpim->tskim_free_q);
}
void
bfa_tskim_start(struct bfa_tskim_s *tskim, struct bfa_itnim_s *itnim,
struct scsi_lun lun,
enum fcp_tm_cmnd tm_cmnd, u8 tsecs)
{
tskim->itnim = itnim;
tskim->lun = lun;
tskim->tm_cmnd = tm_cmnd;
tskim->tsecs = tsecs;
tskim->notify = BFA_FALSE;
bfa_stats(itnim, tm_cmnds);
list_add_tail(&tskim->qe, &itnim->tsk_q);
bfa_sm_send_event(tskim, BFA_TSKIM_SM_START);
}
