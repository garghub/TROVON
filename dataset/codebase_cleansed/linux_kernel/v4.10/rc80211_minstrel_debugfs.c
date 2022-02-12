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
int
minstrel_stats_open(struct inode *inode, struct file *file)
{
struct minstrel_sta_info *mi = inode->i_private;
struct minstrel_debugfs_info *ms;
unsigned int i, tp_max, tp_avg, prob, eprob;
char *p;
ms = kmalloc(2048, GFP_KERNEL);
if (!ms)
return -ENOMEM;
file->private_data = ms;
p = ms->buf;
p += sprintf(p, "\n");
p += sprintf(p,
"best __________rate_________ ________statistics________ ________last_______ ______sum-of________\n");
p += sprintf(p,
"rate [name idx airtime max_tp] [avg(tp) avg(prob) sd(prob)] [prob.|retry|suc|att] [#success | #attempts]\n");
for (i = 0; i < mi->n_rates; i++) {
struct minstrel_rate *mr = &mi->r[i];
struct minstrel_rate_stats *mrs = &mi->r[i].stats;
*(p++) = (i == mi->max_tp_rate[0]) ? 'A' : ' ';
*(p++) = (i == mi->max_tp_rate[1]) ? 'B' : ' ';
*(p++) = (i == mi->max_tp_rate[2]) ? 'C' : ' ';
*(p++) = (i == mi->max_tp_rate[3]) ? 'D' : ' ';
*(p++) = (i == mi->max_prob_rate) ? 'P' : ' ';
p += sprintf(p, " %3u%s ", mr->bitrate / 2,
(mr->bitrate & 1 ? ".5" : " "));
p += sprintf(p, "%3u ", i);
p += sprintf(p, "%6u ", mr->perfect_tx_time);
tp_max = minstrel_get_tp_avg(mr, MINSTREL_FRAC(100,100));
tp_avg = minstrel_get_tp_avg(mr, mrs->prob_ewma);
prob = MINSTREL_TRUNC(mrs->cur_prob * 1000);
eprob = MINSTREL_TRUNC(mrs->prob_ewma * 1000);
p += sprintf(p, "%4u.%1u %4u.%1u %3u.%1u %3u.%1u"
" %3u.%1u %3u %3u %-3u "
"%9llu %-9llu\n",
tp_max / 10, tp_max % 10,
tp_avg / 10, tp_avg % 10,
eprob / 10, eprob % 10,
mrs->prob_ewmsd / 10, mrs->prob_ewmsd % 10,
prob / 10, prob % 10,
mrs->retry_count,
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
int
minstrel_stats_csv_open(struct inode *inode, struct file *file)
{
struct minstrel_sta_info *mi = inode->i_private;
struct minstrel_debugfs_info *ms;
unsigned int i, tp_max, tp_avg, prob, eprob;
char *p;
ms = kmalloc(2048, GFP_KERNEL);
if (!ms)
return -ENOMEM;
file->private_data = ms;
p = ms->buf;
for (i = 0; i < mi->n_rates; i++) {
struct minstrel_rate *mr = &mi->r[i];
struct minstrel_rate_stats *mrs = &mi->r[i].stats;
p += sprintf(p, "%s" ,((i == mi->max_tp_rate[0]) ? "A" : ""));
p += sprintf(p, "%s" ,((i == mi->max_tp_rate[1]) ? "B" : ""));
p += sprintf(p, "%s" ,((i == mi->max_tp_rate[2]) ? "C" : ""));
p += sprintf(p, "%s" ,((i == mi->max_tp_rate[3]) ? "D" : ""));
p += sprintf(p, "%s" ,((i == mi->max_prob_rate) ? "P" : ""));
p += sprintf(p, ",%u%s", mr->bitrate / 2,
(mr->bitrate & 1 ? ".5," : ","));
p += sprintf(p, "%u,", i);
p += sprintf(p, "%u,",mr->perfect_tx_time);
tp_max = minstrel_get_tp_avg(mr, MINSTREL_FRAC(100,100));
tp_avg = minstrel_get_tp_avg(mr, mrs->prob_ewma);
prob = MINSTREL_TRUNC(mrs->cur_prob * 1000);
eprob = MINSTREL_TRUNC(mrs->prob_ewma * 1000);
p += sprintf(p, "%u.%u,%u.%u,%u.%u,%u.%u,%u.%u,%u,%u,%u,"
"%llu,%llu,%d,%d\n",
tp_max / 10, tp_max % 10,
tp_avg / 10, tp_avg % 10,
eprob / 10, eprob % 10,
mrs->prob_ewmsd / 10, mrs->prob_ewmsd % 10,
prob / 10, prob % 10,
mrs->retry_count,
mrs->last_success,
mrs->last_attempts,
(unsigned long long)mrs->succ_hist,
(unsigned long long)mrs->att_hist,
mi->total_packets - mi->sample_packets,
mi->sample_packets);
}
ms->len = p - ms->buf;
WARN_ON(ms->len + sizeof(*ms) > 2048);
return 0;
}
void
minstrel_add_sta_debugfs(void *priv, void *priv_sta, struct dentry *dir)
{
struct minstrel_sta_info *mi = priv_sta;
mi->dbg_stats = debugfs_create_file("rc_stats", S_IRUGO, dir, mi,
&minstrel_stat_fops);
mi->dbg_stats_csv = debugfs_create_file("rc_stats_csv", S_IRUGO, dir,
mi, &minstrel_stat_csv_fops);
}
void
minstrel_remove_sta_debugfs(void *priv, void *priv_sta)
{
struct minstrel_sta_info *mi = priv_sta;
debugfs_remove(mi->dbg_stats);
debugfs_remove(mi->dbg_stats_csv);
}
