fnic_trace_data_t *fnic_trace_get_buf(void)
{
unsigned long fnic_buf_head;
unsigned long flags;
spin_lock_irqsave(&fnic_trace_lock, flags);
fnic_buf_head =
fnic_trace_entries.page_offset[fnic_trace_entries.wr_idx];
fnic_trace_entries.wr_idx++;
if (fnic_trace_entries.wr_idx >= fnic_max_trace_entries)
fnic_trace_entries.wr_idx = 0;
if (fnic_trace_entries.wr_idx == fnic_trace_entries.rd_idx) {
fnic_trace_entries.rd_idx++;
if (fnic_trace_entries.rd_idx >= fnic_max_trace_entries)
fnic_trace_entries.rd_idx = 0;
}
spin_unlock_irqrestore(&fnic_trace_lock, flags);
return (fnic_trace_data_t *)fnic_buf_head;
}
int fnic_get_trace_data(fnic_dbgfs_t *fnic_dbgfs_prt)
{
int rd_idx;
int wr_idx;
int len = 0;
unsigned long flags;
char str[KSYM_SYMBOL_LEN];
struct timespec val;
fnic_trace_data_t *tbp;
spin_lock_irqsave(&fnic_trace_lock, flags);
rd_idx = fnic_trace_entries.rd_idx;
wr_idx = fnic_trace_entries.wr_idx;
if (wr_idx < rd_idx) {
while (1) {
tbp = (fnic_trace_data_t *)
fnic_trace_entries.page_offset[rd_idx];
if (!tbp) {
spin_unlock_irqrestore(&fnic_trace_lock, flags);
return 0;
}
if (sizeof(unsigned long) < 8) {
sprint_symbol(str, tbp->fnaddr.low);
jiffies_to_timespec(tbp->timestamp.low, &val);
} else {
sprint_symbol(str, tbp->fnaddr.val);
jiffies_to_timespec(tbp->timestamp.val, &val);
}
len += snprintf(fnic_dbgfs_prt->buffer + len,
(trace_max_pages * PAGE_SIZE * 3) - len,
"%16lu.%16lu %-50s %8x %8x %16llx %16llx "
"%16llx %16llx %16llx\n", val.tv_sec,
val.tv_nsec, str, tbp->host_no, tbp->tag,
tbp->data[0], tbp->data[1], tbp->data[2],
tbp->data[3], tbp->data[4]);
rd_idx++;
if (rd_idx > (fnic_max_trace_entries-1))
rd_idx = 0;
if (rd_idx == wr_idx)
break;
}
} else if (wr_idx > rd_idx) {
while (1) {
tbp = (fnic_trace_data_t *)
fnic_trace_entries.page_offset[rd_idx];
if (!tbp) {
spin_unlock_irqrestore(&fnic_trace_lock, flags);
return 0;
}
if (sizeof(unsigned long) < 8) {
sprint_symbol(str, tbp->fnaddr.low);
jiffies_to_timespec(tbp->timestamp.low, &val);
} else {
sprint_symbol(str, tbp->fnaddr.val);
jiffies_to_timespec(tbp->timestamp.val, &val);
}
len += snprintf(fnic_dbgfs_prt->buffer + len,
(trace_max_pages * PAGE_SIZE * 3) - len,
"%16lu.%16lu %-50s %8x %8x %16llx %16llx "
"%16llx %16llx %16llx\n", val.tv_sec,
val.tv_nsec, str, tbp->host_no, tbp->tag,
tbp->data[0], tbp->data[1], tbp->data[2],
tbp->data[3], tbp->data[4]);
rd_idx++;
if (rd_idx == wr_idx)
break;
}
}
spin_unlock_irqrestore(&fnic_trace_lock, flags);
return len;
}
int fnic_get_stats_data(struct stats_debug_info *debug,
struct fnic_stats *stats)
{
int len = 0;
int buf_size = debug->buf_size;
struct timespec val1, val2;
len = snprintf(debug->debug_buffer + len, buf_size - len,
"------------------------------------------\n"
"\t\tIO Statistics\n"
"------------------------------------------\n");
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Number of Active IOs: %lld\nMaximum Active IOs: %lld\n"
"Number of IOs: %lld\nNumber of IO Completions: %lld\n"
"Number of IO Failures: %lld\nNumber of IO NOT Found: %lld\n"
"Number of Memory alloc Failures: %lld\n"
"Number of IOREQ Null: %lld\n"
"Number of SCSI cmd pointer Null: %lld\n",
(u64)atomic64_read(&stats->io_stats.active_ios),
(u64)atomic64_read(&stats->io_stats.max_active_ios),
(u64)atomic64_read(&stats->io_stats.num_ios),
(u64)atomic64_read(&stats->io_stats.io_completions),
(u64)atomic64_read(&stats->io_stats.io_failures),
(u64)atomic64_read(&stats->io_stats.io_not_found),
(u64)atomic64_read(&stats->io_stats.alloc_failures),
(u64)atomic64_read(&stats->io_stats.ioreq_null),
(u64)atomic64_read(&stats->io_stats.sc_null));
len += snprintf(debug->debug_buffer + len, buf_size - len,
"\n------------------------------------------\n"
"\t\tAbort Statistics\n"
"------------------------------------------\n");
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Number of Aborts: %lld\n"
"Number of Abort Failures: %lld\n"
"Number of Abort Driver Timeouts: %lld\n"
"Number of Abort FW Timeouts: %lld\n"
"Number of Abort IO NOT Found: %lld\n",
(u64)atomic64_read(&stats->abts_stats.aborts),
(u64)atomic64_read(&stats->abts_stats.abort_failures),
(u64)atomic64_read(&stats->abts_stats.abort_drv_timeouts),
(u64)atomic64_read(&stats->abts_stats.abort_fw_timeouts),
(u64)atomic64_read(&stats->abts_stats.abort_io_not_found));
len += snprintf(debug->debug_buffer + len, buf_size - len,
"\n------------------------------------------\n"
"\t\tTerminate Statistics\n"
"------------------------------------------\n");
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Number of Terminates: %lld\n"
"Maximum Terminates: %lld\n"
"Number of Terminate Driver Timeouts: %lld\n"
"Number of Terminate FW Timeouts: %lld\n"
"Number of Terminate IO NOT Found: %lld\n"
"Number of Terminate Failures: %lld\n",
(u64)atomic64_read(&stats->term_stats.terminates),
(u64)atomic64_read(&stats->term_stats.max_terminates),
(u64)atomic64_read(&stats->term_stats.terminate_drv_timeouts),
(u64)atomic64_read(&stats->term_stats.terminate_fw_timeouts),
(u64)atomic64_read(&stats->term_stats.terminate_io_not_found),
(u64)atomic64_read(&stats->term_stats.terminate_failures));
len += snprintf(debug->debug_buffer + len, buf_size - len,
"\n------------------------------------------\n"
"\t\tReset Statistics\n"
"------------------------------------------\n");
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Number of Device Resets: %lld\n"
"Number of Device Reset Failures: %lld\n"
"Number of Device Reset Aborts: %lld\n"
"Number of Device Reset Timeouts: %lld\n"
"Number of Device Reset Terminates: %lld\n"
"Number of FW Resets: %lld\n"
"Number of FW Reset Completions: %lld\n"
"Number of FW Reset Failures: %lld\n"
"Number of Fnic Reset: %lld\n"
"Number of Fnic Reset Completions: %lld\n"
"Number of Fnic Reset Failures: %lld\n",
(u64)atomic64_read(&stats->reset_stats.device_resets),
(u64)atomic64_read(&stats->reset_stats.device_reset_failures),
(u64)atomic64_read(&stats->reset_stats.device_reset_aborts),
(u64)atomic64_read(&stats->reset_stats.device_reset_timeouts),
(u64)atomic64_read(
&stats->reset_stats.device_reset_terminates),
(u64)atomic64_read(&stats->reset_stats.fw_resets),
(u64)atomic64_read(&stats->reset_stats.fw_reset_completions),
(u64)atomic64_read(&stats->reset_stats.fw_reset_failures),
(u64)atomic64_read(&stats->reset_stats.fnic_resets),
(u64)atomic64_read(
&stats->reset_stats.fnic_reset_completions),
(u64)atomic64_read(&stats->reset_stats.fnic_reset_failures));
len += snprintf(debug->debug_buffer + len, buf_size - len,
"\n------------------------------------------\n"
"\t\tFirmware Statistics\n"
"------------------------------------------\n");
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Number of Active FW Requests %lld\n"
"Maximum FW Requests: %lld\n"
"Number of FW out of resources: %lld\n"
"Number of FW IO errors: %lld\n",
(u64)atomic64_read(&stats->fw_stats.active_fw_reqs),
(u64)atomic64_read(&stats->fw_stats.max_fw_reqs),
(u64)atomic64_read(&stats->fw_stats.fw_out_of_resources),
(u64)atomic64_read(&stats->fw_stats.io_fw_errs));
len += snprintf(debug->debug_buffer + len, buf_size - len,
"\n------------------------------------------\n"
"\t\tVlan Discovery Statistics\n"
"------------------------------------------\n");
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Number of Vlan Discovery Requests Sent %lld\n"
"Vlan Response Received with no FCF VLAN ID: %lld\n"
"No solicitations recvd after vlan set, expiry count: %lld\n"
"Flogi rejects count: %lld\n",
(u64)atomic64_read(&stats->vlan_stats.vlan_disc_reqs),
(u64)atomic64_read(&stats->vlan_stats.resp_withno_vlanID),
(u64)atomic64_read(&stats->vlan_stats.sol_expiry_count),
(u64)atomic64_read(&stats->vlan_stats.flogi_rejects));
len += snprintf(debug->debug_buffer + len, buf_size - len,
"\n------------------------------------------\n"
"\t\tOther Important Statistics\n"
"------------------------------------------\n");
jiffies_to_timespec(stats->misc_stats.last_isr_time, &val1);
jiffies_to_timespec(stats->misc_stats.last_ack_time, &val2);
len += snprintf(debug->debug_buffer + len, buf_size - len,
"Last ISR time: %llu (%8lu.%8lu)\n"
"Last ACK time: %llu (%8lu.%8lu)\n"
"Number of ISRs: %lld\n"
"Maximum CQ Entries: %lld\n"
"Number of ACK index out of range: %lld\n"
"Number of data count mismatch: %lld\n"
"Number of FCPIO Timeouts: %lld\n"
"Number of FCPIO Aborted: %lld\n"
"Number of SGL Invalid: %lld\n"
"Number of Copy WQ Alloc Failures for ABTs: %lld\n"
"Number of Copy WQ Alloc Failures for Device Reset: %lld\n"
"Number of Copy WQ Alloc Failures for IOs: %lld\n"
"Number of no icmnd itmf Completions: %lld\n"
"Number of QUEUE Fulls: %lld\n"
"Number of rport not ready: %lld\n"
"Number of receive frame errors: %lld\n",
(u64)stats->misc_stats.last_isr_time,
val1.tv_sec, val1.tv_nsec,
(u64)stats->misc_stats.last_ack_time,
val2.tv_sec, val2.tv_nsec,
(u64)atomic64_read(&stats->misc_stats.isr_count),
(u64)atomic64_read(&stats->misc_stats.max_cq_entries),
(u64)atomic64_read(&stats->misc_stats.ack_index_out_of_range),
(u64)atomic64_read(&stats->misc_stats.data_count_mismatch),
(u64)atomic64_read(&stats->misc_stats.fcpio_timeout),
(u64)atomic64_read(&stats->misc_stats.fcpio_aborted),
(u64)atomic64_read(&stats->misc_stats.sgl_invalid),
(u64)atomic64_read(
&stats->misc_stats.abts_cpwq_alloc_failures),
(u64)atomic64_read(
&stats->misc_stats.devrst_cpwq_alloc_failures),
(u64)atomic64_read(&stats->misc_stats.io_cpwq_alloc_failures),
(u64)atomic64_read(&stats->misc_stats.no_icmnd_itmf_cmpls),
(u64)atomic64_read(&stats->misc_stats.queue_fulls),
(u64)atomic64_read(&stats->misc_stats.rport_not_ready),
(u64)atomic64_read(&stats->misc_stats.frame_errors));
return len;
}
int fnic_trace_buf_init(void)
{
unsigned long fnic_buf_head;
int i;
int err = 0;
trace_max_pages = fnic_trace_max_pages;
fnic_max_trace_entries = (trace_max_pages * PAGE_SIZE)/
FNIC_ENTRY_SIZE_BYTES;
fnic_trace_buf_p = (unsigned long)vmalloc((trace_max_pages * PAGE_SIZE));
if (!fnic_trace_buf_p) {
printk(KERN_ERR PFX "Failed to allocate memory "
"for fnic_trace_buf_p\n");
err = -ENOMEM;
goto err_fnic_trace_buf_init;
}
memset((void *)fnic_trace_buf_p, 0, (trace_max_pages * PAGE_SIZE));
fnic_trace_entries.page_offset = vmalloc(fnic_max_trace_entries *
sizeof(unsigned long));
if (!fnic_trace_entries.page_offset) {
printk(KERN_ERR PFX "Failed to allocate memory for"
" page_offset\n");
if (fnic_trace_buf_p) {
vfree((void *)fnic_trace_buf_p);
fnic_trace_buf_p = 0;
}
err = -ENOMEM;
goto err_fnic_trace_buf_init;
}
memset((void *)fnic_trace_entries.page_offset, 0,
(fnic_max_trace_entries * sizeof(unsigned long)));
fnic_trace_entries.wr_idx = fnic_trace_entries.rd_idx = 0;
fnic_buf_head = fnic_trace_buf_p;
for (i = 0; i < fnic_max_trace_entries; i++) {
fnic_trace_entries.page_offset[i] = fnic_buf_head;
fnic_buf_head += FNIC_ENTRY_SIZE_BYTES;
}
err = fnic_trace_debugfs_init();
if (err < 0) {
printk(KERN_ERR PFX "Failed to initialize debugfs for tracing\n");
goto err_fnic_trace_debugfs_init;
}
printk(KERN_INFO PFX "Successfully Initialized Trace Buffer\n");
return err;
err_fnic_trace_debugfs_init:
fnic_trace_free();
err_fnic_trace_buf_init:
return err;
}
void fnic_trace_free(void)
{
fnic_tracing_enabled = 0;
fnic_trace_debugfs_terminate();
if (fnic_trace_entries.page_offset) {
vfree((void *)fnic_trace_entries.page_offset);
fnic_trace_entries.page_offset = NULL;
}
if (fnic_trace_buf_p) {
vfree((void *)fnic_trace_buf_p);
fnic_trace_buf_p = 0;
}
printk(KERN_INFO PFX "Successfully Freed Trace Buffer\n");
}
