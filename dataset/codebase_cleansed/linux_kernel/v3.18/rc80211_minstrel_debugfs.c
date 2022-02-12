int
minstrel_stats_open(struct inode *inode, struct file *file)
{
struct minstrel_sta_info *mi = inode->i_private;
struct minstrel_debugfs_info *ms;
unsigned int i, tp, prob, eprob;
char *p;
ms = kmalloc(2048, GFP_KERNEL);
if (!ms)
return -ENOMEM;
file->private_data = ms;
p = ms->buf;
p += sprintf(p, "rate tpt eprob *prob"
" *ok(*cum) ok( cum)\n");
for (i = 0; i < mi->n_rates; i++) {
struct minstrel_rate *mr = &mi->r[i];
struct minstrel_rate_stats *mrs = &mi->r[i].stats;
*(p++) = (i == mi->max_tp_rate[0]) ? 'A' : ' ';
*(p++) = (i == mi->max_tp_rate[1]) ? 'B' : ' ';
*(p++) = (i == mi->max_tp_rate[2]) ? 'C' : ' ';
*(p++) = (i == mi->max_tp_rate[3]) ? 'D' : ' ';
*(p++) = (i == mi->max_prob_rate) ? 'P' : ' ';
p += sprintf(p, "%3u%s", mr->bitrate / 2,
(mr->bitrate & 1 ? ".5" : " "));
tp = MINSTREL_TRUNC(mrs->cur_tp / 10);
prob = MINSTREL_TRUNC(mrs->cur_prob * 1000);
eprob = MINSTREL_TRUNC(mrs->probability * 1000);
p += sprintf(p, " %4u.%1u %3u.%1u %3u.%1u"
" %4u(%4u) %9llu(%9llu)\n",
tp / 10, tp % 10,
eprob / 10, eprob % 10,
prob / 10, prob % 10,
mrs->last_success,
mrs->last_attempts,
(unsigned long long)mrs->succ_hist,
(unsigned long long)mrs->att_hist);
}
p += sprintf(p, "\nTotal packet count:: ideal %d "
"lookaround %d\n\n",
mi->total_packets - mi->sample_packets,
mi->sample_packets);
ms->len = p - ms->buf;
WARN_ON(ms->len + sizeof(*ms) > 2048);
return 0;
}
ssize_t
minstrel_stats_read(struct file *file, char __user *buf, size_t len, loff_t *ppos)
{
struct minstrel_debugfs_info *ms;
ms = file->private_data;
return simple_read_from_buffer(buf, len, ppos, ms->buf, ms->len);
}
int
minstrel_stats_release(struct inode *inode, struct file *file)
{
kfree(file->private_data);
return 0;
}
void
minstrel_add_sta_debugfs(void *priv, void *priv_sta, struct dentry *dir)
{
struct minstrel_sta_info *mi = priv_sta;
mi->dbg_stats = debugfs_create_file("rc_stats", S_IRUGO, dir, mi,
&minstrel_stat_fops);
}
void
minstrel_remove_sta_debugfs(void *priv, void *priv_sta)
{
struct minstrel_sta_info *mi = priv_sta;
debugfs_remove(mi->dbg_stats);
}
