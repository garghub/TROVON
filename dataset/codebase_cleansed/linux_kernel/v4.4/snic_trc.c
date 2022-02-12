struct snic_trc_data *
snic_get_trc_buf(void)
{
struct snic_trc *trc = &snic_glob->trc;
struct snic_trc_data *td = NULL;
unsigned long flags;
spin_lock_irqsave(&trc->lock, flags);
td = &trc->buf[trc->wr_idx];
trc->wr_idx++;
if (trc->wr_idx == trc->max_idx)
trc->wr_idx = 0;
if (trc->wr_idx != trc->rd_idx) {
spin_unlock_irqrestore(&trc->lock, flags);
goto end;
}
trc->rd_idx++;
if (trc->rd_idx == trc->max_idx)
trc->rd_idx = 0;
td->ts = 0;
spin_unlock_irqrestore(&trc->lock, flags);
end:
return td;
}
static int
snic_fmt_trc_data(struct snic_trc_data *td, char *buf, int buf_sz)
{
int len = 0;
struct timespec tmspec;
jiffies_to_timespec(td->ts, &tmspec);
len += snprintf(buf, buf_sz,
"%lu.%10lu %-25s %3d %4x %16llx %16llx %16llx %16llx %16llx\n",
tmspec.tv_sec,
tmspec.tv_nsec,
td->fn,
td->hno,
td->tag,
td->data[0], td->data[1], td->data[2], td->data[3],
td->data[4]);
return len;
}
int
snic_get_trc_data(char *buf, int buf_sz)
{
struct snic_trc_data *td = NULL;
struct snic_trc *trc = &snic_glob->trc;
unsigned long flags;
spin_lock_irqsave(&trc->lock, flags);
if (trc->rd_idx == trc->wr_idx) {
spin_unlock_irqrestore(&trc->lock, flags);
return -1;
}
td = &trc->buf[trc->rd_idx];
if (td->ts == 0) {
spin_unlock_irqrestore(&trc->lock, flags);
return -1;
}
trc->rd_idx++;
if (trc->rd_idx == trc->max_idx)
trc->rd_idx = 0;
spin_unlock_irqrestore(&trc->lock, flags);
return snic_fmt_trc_data(td, buf, buf_sz);
}
int
snic_trc_init(void)
{
struct snic_trc *trc = &snic_glob->trc;
void *tbuf = NULL;
int tbuf_sz = 0, ret;
tbuf_sz = (snic_trace_max_pages * PAGE_SIZE);
tbuf = vmalloc(tbuf_sz);
if (!tbuf) {
SNIC_ERR("Failed to Allocate Trace Buffer Size. %d\n", tbuf_sz);
SNIC_ERR("Trace Facility not enabled.\n");
ret = -ENOMEM;
return ret;
}
memset(tbuf, 0, tbuf_sz);
trc->buf = (struct snic_trc_data *) tbuf;
spin_lock_init(&trc->lock);
ret = snic_trc_debugfs_init();
if (ret) {
SNIC_ERR("Failed to create Debugfs Files.\n");
goto error;
}
trc->max_idx = (tbuf_sz / SNIC_TRC_ENTRY_SZ);
trc->rd_idx = trc->wr_idx = 0;
trc->enable = true;
SNIC_INFO("Trace Facility Enabled.\n Trace Buffer SZ %lu Pages.\n",
tbuf_sz / PAGE_SIZE);
ret = 0;
return ret;
error:
snic_trc_free();
return ret;
}
void
snic_trc_free(void)
{
struct snic_trc *trc = &snic_glob->trc;
trc->enable = false;
snic_trc_debugfs_term();
if (trc->buf) {
vfree(trc->buf);
trc->buf = NULL;
}
SNIC_INFO("Trace Facility Disabled.\n");
}
