int
snic_debugfs_init(void)
{
int rc = -1;
struct dentry *de = NULL;
de = debugfs_create_dir("snic", NULL);
if (!de) {
SNIC_DBG("Cannot create debugfs root\n");
return rc;
}
snic_glob->trc_root = de;
de = debugfs_create_dir("statistics", snic_glob->trc_root);
if (!de) {
SNIC_DBG("Cannot create Statistics directory\n");
return rc;
}
snic_glob->stats_root = de;
rc = 0;
return rc;
}
void
snic_debugfs_term(void)
{
debugfs_remove(snic_glob->stats_root);
snic_glob->stats_root = NULL;
debugfs_remove(snic_glob->trc_root);
snic_glob->trc_root = NULL;
}
static int
snic_reset_stats_open(struct inode *inode, struct file *filp)
{
SNIC_BUG_ON(!inode->i_private);
filp->private_data = inode->i_private;
return 0;
}
static ssize_t
snic_reset_stats_read(struct file *filp,
char __user *ubuf,
size_t cnt,
loff_t *ppos)
{
struct snic *snic = (struct snic *) filp->private_data;
char buf[64];
int len;
len = sprintf(buf, "%u\n", snic->reset_stats);
return simple_read_from_buffer(ubuf, cnt, ppos, buf, len);
}
static ssize_t
snic_reset_stats_write(struct file *filp,
const char __user *ubuf,
size_t cnt,
loff_t *ppos)
{
struct snic *snic = (struct snic *) filp->private_data;
struct snic_stats *stats = &snic->s_stats;
u64 *io_stats_p = (u64 *) &stats->io;
u64 *fw_stats_p = (u64 *) &stats->fw;
char buf[64];
unsigned long val;
int ret;
if (cnt >= sizeof(buf))
return -EINVAL;
if (copy_from_user(&buf, ubuf, cnt))
return -EFAULT;
buf[cnt] = '\0';
ret = kstrtoul(buf, 10, &val);
if (ret < 0)
return ret;
snic->reset_stats = val;
if (snic->reset_stats) {
atomic64_set(&snic->io_cmpl_skip,
atomic64_read(&stats->io.active));
memset(&stats->abts, 0, sizeof(struct snic_abort_stats));
memset(&stats->reset, 0, sizeof(struct snic_reset_stats));
memset(&stats->misc, 0, sizeof(struct snic_misc_stats));
memset(io_stats_p+1,
0,
sizeof(struct snic_io_stats) - sizeof(u64));
memset(fw_stats_p+1,
0,
sizeof(struct snic_fw_stats) - sizeof(u64));
}
(*ppos)++;
SNIC_HOST_INFO(snic->shost, "Reset Op: Driver statistics.\n");
return cnt;
}
static int
snic_reset_stats_release(struct inode *inode, struct file *filp)
{
filp->private_data = NULL;
return 0;
}
static int
snic_stats_show(struct seq_file *sfp, void *data)
{
struct snic *snic = (struct snic *) sfp->private;
struct snic_stats *stats = &snic->s_stats;
struct timespec last_isr_tms, last_ack_tms;
u64 maxio_tm;
int i;
seq_printf(sfp,
"------------------------------------------\n"
"\t\t IO Statistics\n"
"------------------------------------------\n");
maxio_tm = (u64) atomic64_read(&stats->io.max_time);
seq_printf(sfp,
"Active IOs : %lld\n"
"Max Active IOs : %lld\n"
"Total IOs : %lld\n"
"IOs Completed : %lld\n"
"IOs Failed : %lld\n"
"IOs Not Found : %lld\n"
"Memory Alloc Failures : %lld\n"
"REQs Null : %lld\n"
"SCSI Cmd Pointers Null : %lld\n"
"Max SGL for any IO : %lld\n"
"Max IO Size : %lld Sectors\n"
"Max Queuing Time : %lld\n"
"Max Completion Time : %lld\n"
"Max IO Process Time(FW) : %lld (%u msec)\n",
(u64) atomic64_read(&stats->io.active),
(u64) atomic64_read(&stats->io.max_active),
(u64) atomic64_read(&stats->io.num_ios),
(u64) atomic64_read(&stats->io.compl),
(u64) atomic64_read(&stats->io.fail),
(u64) atomic64_read(&stats->io.io_not_found),
(u64) atomic64_read(&stats->io.alloc_fail),
(u64) atomic64_read(&stats->io.req_null),
(u64) atomic64_read(&stats->io.sc_null),
(u64) atomic64_read(&stats->io.max_sgl),
(u64) atomic64_read(&stats->io.max_io_sz),
(u64) atomic64_read(&stats->io.max_qtime),
(u64) atomic64_read(&stats->io.max_cmpl_time),
maxio_tm,
jiffies_to_msecs(maxio_tm));
seq_puts(sfp, "\nSGL Counters\n");
for (i = 0; i < SNIC_MAX_SG_DESC_CNT; i++) {
seq_printf(sfp,
"%10lld ",
(u64) atomic64_read(&stats->io.sgl_cnt[i]));
if ((i + 1) % 8 == 0)
seq_puts(sfp, "\n");
}
seq_printf(sfp,
"\n-------------------------------------------\n"
"\t\t Abort Statistics\n"
"---------------------------------------------\n");
seq_printf(sfp,
"Aborts : %lld\n"
"Aborts Fail : %lld\n"
"Aborts Driver Timeout : %lld\n"
"Abort FW Timeout : %lld\n"
"Abort IO NOT Found : %lld\n",
(u64) atomic64_read(&stats->abts.num),
(u64) atomic64_read(&stats->abts.fail),
(u64) atomic64_read(&stats->abts.drv_tmo),
(u64) atomic64_read(&stats->abts.fw_tmo),
(u64) atomic64_read(&stats->abts.io_not_found));
seq_printf(sfp,
"\n-------------------------------------------\n"
"\t\t Reset Statistics\n"
"---------------------------------------------\n");
seq_printf(sfp,
"HBA Resets : %lld\n"
"HBA Reset Cmpls : %lld\n"
"HBA Reset Fail : %lld\n",
(u64) atomic64_read(&stats->reset.hba_resets),
(u64) atomic64_read(&stats->reset.hba_reset_cmpl),
(u64) atomic64_read(&stats->reset.hba_reset_fail));
seq_printf(sfp,
"\n-------------------------------------------\n"
"\t\t Firmware Statistics\n"
"---------------------------------------------\n");
seq_printf(sfp,
"Active FW Requests : %lld\n"
"Max FW Requests : %lld\n"
"FW Out Of Resource Errs : %lld\n"
"FW IO Errors : %lld\n"
"FW SCSI Errors : %lld\n",
(u64) atomic64_read(&stats->fw.actv_reqs),
(u64) atomic64_read(&stats->fw.max_actv_reqs),
(u64) atomic64_read(&stats->fw.out_of_res),
(u64) atomic64_read(&stats->fw.io_errs),
(u64) atomic64_read(&stats->fw.scsi_errs));
seq_printf(sfp,
"\n---------------------------------------------\n"
"\t\t Other Statistics\n"
"\n---------------------------------------------\n");
jiffies_to_timespec(stats->misc.last_isr_time, &last_isr_tms);
jiffies_to_timespec(stats->misc.last_ack_time, &last_ack_tms);
seq_printf(sfp,
"Last ISR Time : %llu (%8lu.%8lu)\n"
"Last Ack Time : %llu (%8lu.%8lu)\n"
"ISRs : %llu\n"
"Max CQ Entries : %lld\n"
"Data Count Mismatch : %lld\n"
"IOs w/ Timeout Status : %lld\n"
"IOs w/ Aborted Status : %lld\n"
"IOs w/ SGL Invalid Stat : %lld\n"
"WQ Desc Alloc Fail : %lld\n"
"Queue Full : %lld\n"
"Target Not Ready : %lld\n",
(u64) stats->misc.last_isr_time,
last_isr_tms.tv_sec, last_isr_tms.tv_nsec,
(u64)stats->misc.last_ack_time,
last_ack_tms.tv_sec, last_ack_tms.tv_nsec,
(u64) atomic64_read(&stats->misc.isr_cnt),
(u64) atomic64_read(&stats->misc.max_cq_ents),
(u64) atomic64_read(&stats->misc.data_cnt_mismat),
(u64) atomic64_read(&stats->misc.io_tmo),
(u64) atomic64_read(&stats->misc.io_aborted),
(u64) atomic64_read(&stats->misc.sgl_inval),
(u64) atomic64_read(&stats->misc.wq_alloc_fail),
(u64) atomic64_read(&stats->misc.qfull),
(u64) atomic64_read(&stats->misc.tgt_not_rdy));
return 0;
}
static int
snic_stats_open(struct inode *inode, struct file *filp)
{
return single_open(filp, snic_stats_show, inode->i_private);
}
int
snic_stats_debugfs_init(struct snic *snic)
{
int rc = -1;
char name[16];
struct dentry *de = NULL;
snprintf(name, sizeof(name), "host%d", snic->shost->host_no);
if (!snic_glob->stats_root) {
SNIC_DBG("snic_stats root doesn't exist\n");
return rc;
}
de = debugfs_create_dir(name, snic_glob->stats_root);
if (!de) {
SNIC_DBG("Cannot create host directory\n");
return rc;
}
snic->stats_host = de;
de = debugfs_create_file("stats",
S_IFREG|S_IRUGO,
snic->stats_host,
snic,
&snic_stats_fops);
if (!de) {
SNIC_DBG("Cannot create host's stats file\n");
return rc;
}
snic->stats_file = de;
de = debugfs_create_file("reset_stats",
S_IFREG|S_IRUGO|S_IWUSR,
snic->stats_host,
snic,
&snic_reset_stats_fops);
if (!de) {
SNIC_DBG("Cannot create host's reset_stats file\n");
return rc;
}
snic->reset_stats_file = de;
rc = 0;
return rc;
}
void
snic_stats_debugfs_remove(struct snic *snic)
{
debugfs_remove(snic->stats_file);
snic->stats_file = NULL;
debugfs_remove(snic->reset_stats_file);
snic->reset_stats_file = NULL;
debugfs_remove(snic->stats_host);
snic->stats_host = NULL;
}
static void *
snic_trc_seq_start(struct seq_file *sfp, loff_t *pos)
{
return &snic_glob->trc;
}
static void *
snic_trc_seq_next(struct seq_file *sfp, void *data, loff_t *pos)
{
return NULL;
}
static void
snic_trc_seq_stop(struct seq_file *sfp, void *data)
{
}
static int
snic_trc_seq_show(struct seq_file *sfp, void *data)
{
char buf[SNIC_TRC_PBLEN];
if (snic_get_trc_data(buf, SNIC_TRC_PBLEN) > 0)
seq_printf(sfp, "%s\n", buf);
return 0;
}
static int
snic_trc_open(struct inode *inode, struct file *filp)
{
return seq_open(filp, &snic_trc_seq_ops);
}
int
snic_trc_debugfs_init(void)
{
struct dentry *de = NULL;
int ret = -1;
if (!snic_glob->trc_root) {
SNIC_ERR("Debugfs root directory for snic doesn't exist.\n");
return ret;
}
de = debugfs_create_bool("tracing_enable",
S_IFREG | S_IRUGO | S_IWUSR,
snic_glob->trc_root,
&snic_glob->trc.enable);
if (!de) {
SNIC_ERR("Can't create trace_enable file.\n");
return ret;
}
snic_glob->trc.trc_enable = de;
de = debugfs_create_file("trace",
S_IFREG | S_IRUGO | S_IWUSR,
snic_glob->trc_root,
NULL,
&snic_trc_fops);
if (!de) {
SNIC_ERR("Cann't create trace file.\n");
return ret;
}
snic_glob->trc.trc_file = de;
ret = 0;
return ret;
}
void
snic_trc_debugfs_term(void)
{
debugfs_remove(snic_glob->trc.trc_file);
snic_glob->trc.trc_file = NULL;
debugfs_remove(snic_glob->trc.trc_enable);
snic_glob->trc.trc_enable = NULL;
}
