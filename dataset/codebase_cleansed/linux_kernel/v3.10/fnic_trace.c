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
