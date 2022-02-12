static int telemetry_debugfs_check_evts(void)
{
if ((debugfs_conf->pss_idle_evts > TELEM_PSS_IDLE_EVTS) ||
(debugfs_conf->pcs_idle_blkd_evts > TELEM_PSS_IDLE_BLOCKED_EVTS) ||
(debugfs_conf->pcs_s0ix_blkd_evts > TELEM_PSS_S0IX_BLOCKED_EVTS) ||
(debugfs_conf->pss_ltr_evts > TELEM_PSS_LTR_BLOCKING_EVTS) ||
(debugfs_conf->pss_wakeup_evts > TELEM_PSS_S0IX_WAKEUP_EVTS) ||
(debugfs_conf->ioss_d0ix_evts > TELEM_IOSS_DX_D0IX_EVTS) ||
(debugfs_conf->ioss_pg_evts > TELEM_IOSS_PG_EVTS))
return -EINVAL;
return 0;
}
static int telem_pss_states_show(struct seq_file *s, void *unused)
{
struct telemetry_evtlog evtlog[TELEM_MAX_OS_ALLOCATED_EVENTS];
struct telemetry_debugfs_conf *conf = debugfs_conf;
const char *name[TELEM_MAX_OS_ALLOCATED_EVENTS];
u32 pcs_idle_blkd[TELEM_PSS_IDLE_BLOCKED_EVTS],
pcs_s0ix_blkd[TELEM_PSS_S0IX_BLOCKED_EVTS],
pss_s0ix_wakeup[TELEM_PSS_S0IX_WAKEUP_EVTS],
pss_ltr_blkd[TELEM_PSS_LTR_BLOCKING_EVTS],
pss_idle[TELEM_PSS_IDLE_EVTS];
int index, idx, ret, err = 0;
u64 pstates = 0;
ret = telemetry_read_eventlog(TELEM_PSS, evtlog,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (ret < 0)
return ret;
err = telemetry_get_evtname(TELEM_PSS, name,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (err < 0)
return err;
seq_puts(s, "\n----------------------------------------------------\n");
seq_puts(s, "\tPSS TELEM EVENTLOG (Residency = field/19.2 us\n");
seq_puts(s, "----------------------------------------------------\n");
for (index = 0; index < ret; index++) {
seq_printf(s, "%-32s %llu\n",
name[index], evtlog[index].telem_evtlog);
if (evtlog[index].telem_evtid == conf->pss_idle_id) {
pss_idle[conf->pss_idle_evts - 1] =
(evtlog[index].telem_evtlog >>
conf->pss_idle_data[conf->pss_idle_evts - 1].bit_pos) &
TELEM_APL_MASK_PCS_STATE;
}
TELEM_CHECK_AND_PARSE_EVTS(conf->pss_idle_id,
conf->pss_idle_evts - 1,
pss_idle, evtlog[index].telem_evtlog,
conf->pss_idle_data, TELEM_MASK_BIT);
TELEM_CHECK_AND_PARSE_EVTS(conf->pcs_idle_blkd_id,
conf->pcs_idle_blkd_evts,
pcs_idle_blkd,
evtlog[index].telem_evtlog,
conf->pcs_idle_blkd_data,
TELEM_MASK_BYTE);
TELEM_CHECK_AND_PARSE_EVTS(conf->pcs_s0ix_blkd_id,
conf->pcs_s0ix_blkd_evts,
pcs_s0ix_blkd,
evtlog[index].telem_evtlog,
conf->pcs_s0ix_blkd_data,
TELEM_MASK_BYTE);
TELEM_CHECK_AND_PARSE_EVTS(conf->pss_wakeup_id,
conf->pss_wakeup_evts,
pss_s0ix_wakeup,
evtlog[index].telem_evtlog,
conf->pss_wakeup, TELEM_MASK_BYTE);
TELEM_CHECK_AND_PARSE_EVTS(conf->pss_ltr_blocking_id,
conf->pss_ltr_evts, pss_ltr_blkd,
evtlog[index].telem_evtlog,
conf->pss_ltr_data, TELEM_MASK_BYTE);
if (evtlog[index].telem_evtid == debugfs_conf->pstates_id)
pstates = evtlog[index].telem_evtlog;
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "PStates\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Domain\t\t\t\tFreq(Mhz)\n");
seq_printf(s, " IA\t\t\t\t %llu\n GT\t\t\t\t %llu\n",
(pstates & TELEM_MASK_BYTE)*100,
((pstates >> 8) & TELEM_MASK_BYTE)*50/3);
seq_printf(s, " IUNIT\t\t\t\t %llu\n SA\t\t\t\t %llu\n",
((pstates >> 16) & TELEM_MASK_BYTE)*25,
((pstates >> 24) & TELEM_MASK_BYTE)*50/3);
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "PSS IDLE Status\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Device\t\t\t\t\tIDLE\n");
for (index = 0; index < debugfs_conf->pss_idle_evts; index++) {
seq_printf(s, "%-32s\t%u\n",
debugfs_conf->pss_idle_data[index].name,
pss_idle[index]);
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "PSS Idle blkd Status (~1ms saturating bucket)\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Blocker\t\t\t\t\tCount\n");
for (index = 0; index < debugfs_conf->pcs_idle_blkd_evts; index++) {
seq_printf(s, "%-32s\t%u\n",
debugfs_conf->pcs_idle_blkd_data[index].name,
pcs_idle_blkd[index]);
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "PSS S0ix blkd Status (~1ms saturating bucket)\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Blocker\t\t\t\t\tCount\n");
for (index = 0; index < debugfs_conf->pcs_s0ix_blkd_evts; index++) {
seq_printf(s, "%-32s\t%u\n",
debugfs_conf->pcs_s0ix_blkd_data[index].name,
pcs_s0ix_blkd[index]);
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "LTR Blocking Status (~1ms saturating bucket)\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Blocker\t\t\t\t\tCount\n");
for (index = 0; index < debugfs_conf->pss_ltr_evts; index++) {
seq_printf(s, "%-32s\t%u\n",
debugfs_conf->pss_ltr_data[index].name,
pss_s0ix_wakeup[index]);
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "Wakes Status (~1ms saturating bucket)\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Wakes\t\t\t\t\tCount\n");
for (index = 0; index < debugfs_conf->pss_wakeup_evts; index++) {
seq_printf(s, "%-32s\t%u\n",
debugfs_conf->pss_wakeup[index].name,
pss_ltr_blkd[index]);
}
return 0;
}
static int telem_pss_state_open(struct inode *inode, struct file *file)
{
return single_open(file, telem_pss_states_show, inode->i_private);
}
static int telem_ioss_states_show(struct seq_file *s, void *unused)
{
struct telemetry_evtlog evtlog[TELEM_MAX_OS_ALLOCATED_EVENTS];
const char *name[TELEM_MAX_OS_ALLOCATED_EVENTS];
int index, ret, err;
ret = telemetry_read_eventlog(TELEM_IOSS, evtlog,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (ret < 0)
return ret;
err = telemetry_get_evtname(TELEM_IOSS, name,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (err < 0)
return err;
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "\tI0SS TELEMETRY EVENTLOG\n");
seq_puts(s, "--------------------------------------\n");
for (index = 0; index < ret; index++) {
seq_printf(s, "%-32s 0x%llx\n",
name[index], evtlog[index].telem_evtlog);
}
return 0;
}
static int telem_ioss_state_open(struct inode *inode, struct file *file)
{
return single_open(file, telem_ioss_states_show, inode->i_private);
}
static int telem_soc_states_show(struct seq_file *s, void *unused)
{
u32 d3_sts[TELEM_IOSS_DX_D0IX_EVTS], d0ix_sts[TELEM_IOSS_DX_D0IX_EVTS];
u32 pg_sts[TELEM_IOSS_PG_EVTS], pss_idle[TELEM_PSS_IDLE_EVTS];
struct telemetry_evtlog evtlog[TELEM_MAX_OS_ALLOCATED_EVENTS];
u32 s0ix_total_ctr = 0, s0ix_shlw_ctr = 0, s0ix_deep_ctr = 0;
u64 s0ix_total_res = 0, s0ix_shlw_res = 0, s0ix_deep_res = 0;
struct telemetry_debugfs_conf *conf = debugfs_conf;
struct pci_dev *dev = NULL;
int index, idx, ret;
u32 d3_state;
u16 pmcsr;
ret = telemetry_read_eventlog(TELEM_IOSS, evtlog,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (ret < 0)
return ret;
for (index = 0; index < ret; index++) {
TELEM_CHECK_AND_PARSE_EVTS(conf->ioss_d3_id,
conf->ioss_d0ix_evts,
d3_sts, evtlog[index].telem_evtlog,
conf->ioss_d0ix_data,
TELEM_MASK_BIT);
TELEM_CHECK_AND_PARSE_EVTS(conf->ioss_pg_id, conf->ioss_pg_evts,
pg_sts, evtlog[index].telem_evtlog,
conf->ioss_pg_data, TELEM_MASK_BIT);
TELEM_CHECK_AND_PARSE_EVTS(conf->ioss_d0ix_id,
conf->ioss_d0ix_evts,
d0ix_sts, evtlog[index].telem_evtlog,
conf->ioss_d0ix_data,
TELEM_MASK_BIT);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_total_occ_id,
s0ix_total_ctr);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_shlw_occ_id,
s0ix_shlw_ctr);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_deep_occ_id,
s0ix_deep_ctr);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_total_res_id,
s0ix_total_res);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_shlw_res_id,
s0ix_shlw_res);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_deep_res_id,
s0ix_deep_res);
}
seq_puts(s, "\n---------------------------------------------------\n");
seq_puts(s, "S0IX Type\t\t\t Occurrence\t\t Residency(us)\n");
seq_puts(s, "---------------------------------------------------\n");
seq_printf(s, "S0IX Shallow\t\t\t %10u\t %10llu\n",
s0ix_shlw_ctr -
conf->suspend_stats.shlw_ctr -
conf->suspend_stats.shlw_swake_ctr,
(u64)((s0ix_shlw_res -
conf->suspend_stats.shlw_res -
conf->suspend_stats.shlw_swake_res)*10/192));
seq_printf(s, "S0IX Deep\t\t\t %10u\t %10llu\n",
s0ix_deep_ctr -
conf->suspend_stats.deep_ctr -
conf->suspend_stats.deep_swake_ctr,
(u64)((s0ix_deep_res -
conf->suspend_stats.deep_res -
conf->suspend_stats.deep_swake_res)*10/192));
seq_printf(s, "Suspend(With S0ixShallow)\t %10u\t %10llu\n",
conf->suspend_stats.shlw_ctr,
(u64)(conf->suspend_stats.shlw_res*10)/192);
seq_printf(s, "Suspend(With S0ixDeep)\t\t %10u\t %10llu\n",
conf->suspend_stats.deep_ctr,
(u64)(conf->suspend_stats.deep_res*10)/192);
seq_printf(s, "Suspend(With Shallow-Wakes)\t %10u\t %10llu\n",
conf->suspend_stats.shlw_swake_ctr +
conf->suspend_stats.deep_swake_ctr,
(u64)((conf->suspend_stats.shlw_swake_res +
conf->suspend_stats.deep_swake_res)*10/192));
seq_printf(s, "S0IX+Suspend Total\t\t %10u\t %10llu\n", s0ix_total_ctr,
(u64)(s0ix_total_res*10/192));
seq_puts(s, "\n-------------------------------------------------\n");
seq_puts(s, "\t\tDEVICE STATES\n");
seq_puts(s, "-------------------------------------------------\n");
for_each_pci_dev(dev) {
pci_read_config_word(dev, dev->pm_cap + PCI_PM_CTRL, &pmcsr);
d3_state = ((pmcsr & PCI_PM_CTRL_STATE_MASK) ==
(__force int)PCI_D3hot) ? 1 : 0;
seq_printf(s, "pci %04x %04X %s %20.20s: ",
dev->vendor, dev->device, dev_name(&dev->dev),
dev_driver_string(&dev->dev));
seq_printf(s, " d3:%x\n", d3_state);
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "D3/D0i3 Status\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Block\t\t D3\t D0i3\n");
for (index = 0; index < conf->ioss_d0ix_evts; index++) {
seq_printf(s, "%-10s\t %u\t %u\n",
conf->ioss_d0ix_data[index].name,
d3_sts[index], d0ix_sts[index]);
}
seq_puts(s, "\n--------------------------------------\n");
seq_puts(s, "South Complex PowerGate Status\n");
seq_puts(s, "--------------------------------------\n");
seq_puts(s, "Device\t\t PG\n");
for (index = 0; index < conf->ioss_pg_evts; index++) {
seq_printf(s, "%-10s\t %u\n",
conf->ioss_pg_data[index].name,
pg_sts[index]);
}
evtlog->telem_evtid = conf->pss_idle_id;
ret = telemetry_read_events(TELEM_PSS, evtlog, 1);
if (ret < 0)
return ret;
seq_puts(s, "\n-----------------------------------------\n");
seq_puts(s, "North Idle Status\n");
seq_puts(s, "-----------------------------------------\n");
for (idx = 0; idx < conf->pss_idle_evts - 1; idx++) {
pss_idle[idx] = (evtlog->telem_evtlog >>
conf->pss_idle_data[idx].bit_pos) &
TELEM_MASK_BIT;
}
pss_idle[idx] = (evtlog->telem_evtlog >>
conf->pss_idle_data[idx].bit_pos) &
TELEM_APL_MASK_PCS_STATE;
for (index = 0; index < conf->pss_idle_evts; index++) {
seq_printf(s, "%-30s %u\n",
conf->pss_idle_data[index].name,
pss_idle[index]);
}
seq_puts(s, "\nPCS_STATUS Code\n");
seq_puts(s, "0:C0 1:C1 2:C1_DN_WT_DEV 3:C2 4:C2_WT_DE_MEM_UP\n");
seq_puts(s, "5:C2_WT_DE_MEM_DOWN 6:C2_UP_WT_DEV 7:C2_DN 8:C2_VOA\n");
seq_puts(s, "9:C2_VOA_UP 10:S0IX_PRE 11:S0IX\n");
return 0;
}
static int telem_soc_state_open(struct inode *inode, struct file *file)
{
return single_open(file, telem_soc_states_show, inode->i_private);
}
static int telem_pss_trc_verb_show(struct seq_file *s, void *unused)
{
u32 verbosity;
int err;
err = telemetry_get_trace_verbosity(TELEM_PSS, &verbosity);
if (err) {
pr_err("Get PSS Trace Verbosity Failed with Error %d\n", err);
return -EFAULT;
}
seq_printf(s, "PSS Trace Verbosity %u\n", verbosity);
return 0;
}
static ssize_t telem_pss_trc_verb_write(struct file *file,
const char __user *userbuf,
size_t count, loff_t *ppos)
{
u32 verbosity;
int err;
if (kstrtou32_from_user(userbuf, count, 0, &verbosity))
return -EFAULT;
err = telemetry_set_trace_verbosity(TELEM_PSS, verbosity);
if (err) {
pr_err("Changing PSS Trace Verbosity Failed. Error %d\n", err);
count = err;
}
return count;
}
static int telem_pss_trc_verb_open(struct inode *inode, struct file *file)
{
return single_open(file, telem_pss_trc_verb_show, inode->i_private);
}
static int telem_ioss_trc_verb_show(struct seq_file *s, void *unused)
{
u32 verbosity;
int err;
err = telemetry_get_trace_verbosity(TELEM_IOSS, &verbosity);
if (err) {
pr_err("Get IOSS Trace Verbosity Failed with Error %d\n", err);
return -EFAULT;
}
seq_printf(s, "IOSS Trace Verbosity %u\n", verbosity);
return 0;
}
static ssize_t telem_ioss_trc_verb_write(struct file *file,
const char __user *userbuf,
size_t count, loff_t *ppos)
{
u32 verbosity;
int err;
if (kstrtou32_from_user(userbuf, count, 0, &verbosity))
return -EFAULT;
err = telemetry_set_trace_verbosity(TELEM_IOSS, verbosity);
if (err) {
pr_err("Changing IOSS Trace Verbosity Failed. Error %d\n", err);
count = err;
}
return count;
}
static int telem_ioss_trc_verb_open(struct inode *inode, struct file *file)
{
return single_open(file, telem_ioss_trc_verb_show, inode->i_private);
}
static int pm_suspend_prep_cb(void)
{
struct telemetry_evtlog evtlog[TELEM_MAX_OS_ALLOCATED_EVENTS];
struct telemetry_debugfs_conf *conf = debugfs_conf;
int ret, index;
ret = telemetry_raw_read_eventlog(TELEM_IOSS, evtlog,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (ret < 0) {
suspend_prep_ok = 0;
goto out;
}
for (index = 0; index < ret; index++) {
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_shlw_occ_id,
suspend_shlw_ctr_temp);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_deep_occ_id,
suspend_deep_ctr_temp);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_shlw_res_id,
suspend_shlw_res_temp);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_deep_res_id,
suspend_deep_res_temp);
}
suspend_prep_ok = 1;
out:
return NOTIFY_OK;
}
static int pm_suspend_exit_cb(void)
{
struct telemetry_evtlog evtlog[TELEM_MAX_OS_ALLOCATED_EVENTS];
static u32 suspend_shlw_ctr_exit, suspend_deep_ctr_exit;
static u64 suspend_shlw_res_exit, suspend_deep_res_exit;
struct telemetry_debugfs_conf *conf = debugfs_conf;
int ret, index;
if (!suspend_prep_ok)
goto out;
ret = telemetry_raw_read_eventlog(TELEM_IOSS, evtlog,
TELEM_MAX_OS_ALLOCATED_EVENTS);
if (ret < 0)
goto out;
for (index = 0; index < ret; index++) {
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_shlw_occ_id,
suspend_shlw_ctr_exit);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_deep_occ_id,
suspend_deep_ctr_exit);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_shlw_res_id,
suspend_shlw_res_exit);
TELEM_CHECK_AND_PARSE_CTRS(conf->s0ix_deep_res_id,
suspend_deep_res_exit);
}
if ((suspend_shlw_ctr_exit < suspend_shlw_ctr_temp) ||
(suspend_deep_ctr_exit < suspend_deep_ctr_temp) ||
(suspend_shlw_res_exit < suspend_shlw_res_temp) ||
(suspend_deep_res_exit < suspend_deep_res_temp)) {
pr_err("Wrong s0ix counters detected\n");
goto out;
}
suspend_shlw_ctr_exit -= suspend_shlw_ctr_temp;
suspend_deep_ctr_exit -= suspend_deep_ctr_temp;
suspend_shlw_res_exit -= suspend_shlw_res_temp;
suspend_deep_res_exit -= suspend_deep_res_temp;
if (suspend_shlw_ctr_exit == 1) {
conf->suspend_stats.shlw_ctr +=
suspend_shlw_ctr_exit;
conf->suspend_stats.shlw_res +=
suspend_shlw_res_exit;
}
else if (suspend_shlw_ctr_exit > 1) {
conf->suspend_stats.shlw_swake_ctr +=
suspend_shlw_ctr_exit;
conf->suspend_stats.shlw_swake_res +=
suspend_shlw_res_exit;
}
if (suspend_deep_ctr_exit == 1) {
conf->suspend_stats.deep_ctr +=
suspend_deep_ctr_exit;
conf->suspend_stats.deep_res +=
suspend_deep_res_exit;
}
else if (suspend_deep_ctr_exit > 1) {
conf->suspend_stats.deep_swake_ctr +=
suspend_deep_ctr_exit;
conf->suspend_stats.deep_swake_res +=
suspend_deep_res_exit;
}
out:
suspend_prep_ok = 0;
return NOTIFY_OK;
}
static int pm_notification(struct notifier_block *this,
unsigned long event, void *ptr)
{
switch (event) {
case PM_SUSPEND_PREPARE:
return pm_suspend_prep_cb();
case PM_POST_SUSPEND:
return pm_suspend_exit_cb();
}
return NOTIFY_DONE;
}
static int __init telemetry_debugfs_init(void)
{
const struct x86_cpu_id *id;
int err = -ENOMEM;
struct dentry *f;
id = x86_match_cpu(telemetry_debugfs_cpu_ids);
if (!id)
return -ENODEV;
debugfs_conf = (struct telemetry_debugfs_conf *)id->driver_data;
err = telemetry_pltconfig_valid();
if (err < 0)
return -ENODEV;
err = telemetry_debugfs_check_evts();
if (err < 0)
return -EINVAL;
#ifdef CONFIG_PM_SLEEP
register_pm_notifier(&pm_notifier);
#endif
debugfs_conf->telemetry_dbg_dir = debugfs_create_dir("telemetry", NULL);
if (!debugfs_conf->telemetry_dbg_dir)
return -ENOMEM;
f = debugfs_create_file("pss_info", S_IFREG | S_IRUGO,
debugfs_conf->telemetry_dbg_dir, NULL,
&telem_pss_ops);
if (!f) {
pr_err("pss_sample_info debugfs register failed\n");
goto out;
}
f = debugfs_create_file("ioss_info", S_IFREG | S_IRUGO,
debugfs_conf->telemetry_dbg_dir, NULL,
&telem_ioss_ops);
if (!f) {
pr_err("ioss_sample_info debugfs register failed\n");
goto out;
}
f = debugfs_create_file("soc_states", S_IFREG | S_IRUGO,
debugfs_conf->telemetry_dbg_dir,
NULL, &telem_socstate_ops);
if (!f) {
pr_err("ioss_sample_info debugfs register failed\n");
goto out;
}
f = debugfs_create_file("pss_trace_verbosity", S_IFREG | S_IRUGO,
debugfs_conf->telemetry_dbg_dir, NULL,
&telem_pss_trc_verb_ops);
if (!f) {
pr_err("pss_trace_verbosity debugfs register failed\n");
goto out;
}
f = debugfs_create_file("ioss_trace_verbosity", S_IFREG | S_IRUGO,
debugfs_conf->telemetry_dbg_dir, NULL,
&telem_ioss_trc_verb_ops);
if (!f) {
pr_err("ioss_trace_verbosity debugfs register failed\n");
goto out;
}
return 0;
out:
debugfs_remove_recursive(debugfs_conf->telemetry_dbg_dir);
debugfs_conf->telemetry_dbg_dir = NULL;
return err;
}
static void __exit telemetry_debugfs_exit(void)
{
debugfs_remove_recursive(debugfs_conf->telemetry_dbg_dir);
debugfs_conf->telemetry_dbg_dir = NULL;
}
