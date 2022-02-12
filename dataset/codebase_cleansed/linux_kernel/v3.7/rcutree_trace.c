static int show_rcubarrier(struct seq_file *m, void *unused)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
seq_printf(m, "%s: bcc: %d nbd: %lu\n",
rsp->name,
atomic_read(&rsp->barrier_cpu_count),
rsp->n_barrier_done);
return 0;
}
static int rcubarrier_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcubarrier, NULL);
}
static char convert_kthread_status(unsigned int kthread_status)
{
if (kthread_status > RCU_KTHREAD_MAX)
return '?';
return "SRWOY"[kthread_status];
}
static void print_one_rcu_data(struct seq_file *m, struct rcu_data *rdp)
{
if (!rdp->beenonline)
return;
seq_printf(m, "%3d%cc=%lu g=%lu pq=%d qp=%d",
rdp->cpu,
cpu_is_offline(rdp->cpu) ? '!' : ' ',
rdp->completed, rdp->gpnum,
rdp->passed_quiesce, rdp->qs_pending);
seq_printf(m, " dt=%d/%llx/%d df=%lu",
atomic_read(&rdp->dynticks->dynticks),
rdp->dynticks->dynticks_nesting,
rdp->dynticks->dynticks_nmi_nesting,
rdp->dynticks_fqs);
seq_printf(m, " of=%lu", rdp->offline_fqs);
seq_printf(m, " ql=%ld/%ld qs=%c%c%c%c",
rdp->qlen_lazy, rdp->qlen,
".N"[rdp->nxttail[RCU_NEXT_READY_TAIL] !=
rdp->nxttail[RCU_NEXT_TAIL]],
".R"[rdp->nxttail[RCU_WAIT_TAIL] !=
rdp->nxttail[RCU_NEXT_READY_TAIL]],
".W"[rdp->nxttail[RCU_DONE_TAIL] !=
rdp->nxttail[RCU_WAIT_TAIL]],
".D"[&rdp->nxtlist != rdp->nxttail[RCU_DONE_TAIL]]);
#ifdef CONFIG_RCU_BOOST
seq_printf(m, " kt=%d/%c ktl=%x",
per_cpu(rcu_cpu_has_work, rdp->cpu),
convert_kthread_status(per_cpu(rcu_cpu_kthread_status,
rdp->cpu)),
per_cpu(rcu_cpu_kthread_loops, rdp->cpu) & 0xffff);
#endif
seq_printf(m, " b=%ld", rdp->blimit);
seq_printf(m, " ci=%lu co=%lu ca=%lu\n",
rdp->n_cbs_invoked, rdp->n_cbs_orphaned, rdp->n_cbs_adopted);
}
static int show_rcudata(struct seq_file *m, void *unused)
{
int cpu;
struct rcu_state *rsp;
for_each_rcu_flavor(rsp) {
seq_printf(m, "%s:\n", rsp->name);
for_each_possible_cpu(cpu)
print_one_rcu_data(m, per_cpu_ptr(rsp->rda, cpu));
}
return 0;
}
static int rcudata_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcudata, NULL);
}
static void print_one_rcu_data_csv(struct seq_file *m, struct rcu_data *rdp)
{
if (!rdp->beenonline)
return;
seq_printf(m, "%d,%s,%lu,%lu,%d,%d",
rdp->cpu,
cpu_is_offline(rdp->cpu) ? "\"N\"" : "\"Y\"",
rdp->completed, rdp->gpnum,
rdp->passed_quiesce, rdp->qs_pending);
seq_printf(m, ",%d,%llx,%d,%lu",
atomic_read(&rdp->dynticks->dynticks),
rdp->dynticks->dynticks_nesting,
rdp->dynticks->dynticks_nmi_nesting,
rdp->dynticks_fqs);
seq_printf(m, ",%lu", rdp->offline_fqs);
seq_printf(m, ",%ld,%ld,\"%c%c%c%c\"", rdp->qlen_lazy, rdp->qlen,
".N"[rdp->nxttail[RCU_NEXT_READY_TAIL] !=
rdp->nxttail[RCU_NEXT_TAIL]],
".R"[rdp->nxttail[RCU_WAIT_TAIL] !=
rdp->nxttail[RCU_NEXT_READY_TAIL]],
".W"[rdp->nxttail[RCU_DONE_TAIL] !=
rdp->nxttail[RCU_WAIT_TAIL]],
".D"[&rdp->nxtlist != rdp->nxttail[RCU_DONE_TAIL]]);
#ifdef CONFIG_RCU_BOOST
seq_printf(m, ",%d,\"%c\"",
per_cpu(rcu_cpu_has_work, rdp->cpu),
convert_kthread_status(per_cpu(rcu_cpu_kthread_status,
rdp->cpu)));
#endif
seq_printf(m, ",%ld", rdp->blimit);
seq_printf(m, ",%lu,%lu,%lu\n",
rdp->n_cbs_invoked, rdp->n_cbs_orphaned, rdp->n_cbs_adopted);
}
static int show_rcudata_csv(struct seq_file *m, void *unused)
{
int cpu;
struct rcu_state *rsp;
seq_puts(m, "\"CPU\",\"Online?\",\"c\",\"g\",\"pq\",\"pq\",");
seq_puts(m, "\"dt\",\"dt nesting\",\"dt NMI nesting\",\"df\",");
seq_puts(m, "\"of\",\"qll\",\"ql\",\"qs\"");
#ifdef CONFIG_RCU_BOOST
seq_puts(m, "\"kt\",\"ktl\"");
#endif
seq_puts(m, ",\"b\",\"ci\",\"co\",\"ca\"\n");
for_each_rcu_flavor(rsp) {
seq_printf(m, "\"%s:\"\n", rsp->name);
for_each_possible_cpu(cpu)
print_one_rcu_data_csv(m, per_cpu_ptr(rsp->rda, cpu));
}
return 0;
}
static int rcudata_csv_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcudata_csv, NULL);
}
static void print_one_rcu_node_boost(struct seq_file *m, struct rcu_node *rnp)
{
seq_printf(m, "%d:%d tasks=%c%c%c%c kt=%c ntb=%lu neb=%lu nnb=%lu ",
rnp->grplo, rnp->grphi,
"T."[list_empty(&rnp->blkd_tasks)],
"N."[!rnp->gp_tasks],
"E."[!rnp->exp_tasks],
"B."[!rnp->boost_tasks],
convert_kthread_status(rnp->boost_kthread_status),
rnp->n_tasks_boosted, rnp->n_exp_boosts,
rnp->n_normal_boosts);
seq_printf(m, "j=%04x bt=%04x\n",
(int)(jiffies & 0xffff),
(int)(rnp->boost_time & 0xffff));
seq_printf(m, " balk: nt=%lu egt=%lu bt=%lu nb=%lu ny=%lu nos=%lu\n",
rnp->n_balk_blkd_tasks,
rnp->n_balk_exp_gp_tasks,
rnp->n_balk_boost_tasks,
rnp->n_balk_notblocked,
rnp->n_balk_notyet,
rnp->n_balk_nos);
}
static int show_rcu_node_boost(struct seq_file *m, void *unused)
{
struct rcu_node *rnp;
rcu_for_each_leaf_node(&rcu_preempt_state, rnp)
print_one_rcu_node_boost(m, rnp);
return 0;
}
static int rcu_node_boost_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcu_node_boost, NULL);
}
static int rcu_boost_trace_create_file(struct dentry *rcudir)
{
return !debugfs_create_file("rcuboost", 0444, rcudir, NULL,
&rcu_node_boost_fops);
}
static int rcu_boost_trace_create_file(struct dentry *rcudir)
{
return 0;
}
static void print_one_rcu_state(struct seq_file *m, struct rcu_state *rsp)
{
unsigned long gpnum;
int level = 0;
struct rcu_node *rnp;
gpnum = rsp->gpnum;
seq_printf(m, "%s: c=%lu g=%lu s=%d jfq=%ld j=%x ",
rsp->name, rsp->completed, gpnum, rsp->fqs_state,
(long)(rsp->jiffies_force_qs - jiffies),
(int)(jiffies & 0xffff));
seq_printf(m, "nfqs=%lu/nfqsng=%lu(%lu) fqlh=%lu oqlen=%ld/%ld\n",
rsp->n_force_qs, rsp->n_force_qs_ngp,
rsp->n_force_qs - rsp->n_force_qs_ngp,
rsp->n_force_qs_lh, rsp->qlen_lazy, rsp->qlen);
for (rnp = &rsp->node[0]; rnp - &rsp->node[0] < rcu_num_nodes; rnp++) {
if (rnp->level != level) {
seq_puts(m, "\n");
level = rnp->level;
}
seq_printf(m, "%lx/%lx %c%c>%c %d:%d ^%d ",
rnp->qsmask, rnp->qsmaskinit,
".G"[rnp->gp_tasks != NULL],
".E"[rnp->exp_tasks != NULL],
".T"[!list_empty(&rnp->blkd_tasks)],
rnp->grplo, rnp->grphi, rnp->grpnum);
}
seq_puts(m, "\n");
}
static int show_rcuhier(struct seq_file *m, void *unused)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
print_one_rcu_state(m, rsp);
return 0;
}
static int rcuhier_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcuhier, NULL);
}
static void show_one_rcugp(struct seq_file *m, struct rcu_state *rsp)
{
unsigned long flags;
unsigned long completed;
unsigned long gpnum;
unsigned long gpage;
unsigned long gpmax;
struct rcu_node *rnp = &rsp->node[0];
raw_spin_lock_irqsave(&rnp->lock, flags);
completed = rsp->completed;
gpnum = rsp->gpnum;
if (rsp->completed == rsp->gpnum)
gpage = 0;
else
gpage = jiffies - rsp->gp_start;
gpmax = rsp->gp_max;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
seq_printf(m, "%s: completed=%ld gpnum=%lu age=%ld max=%ld\n",
rsp->name, completed, gpnum, gpage, gpmax);
}
static int show_rcugp(struct seq_file *m, void *unused)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
show_one_rcugp(m, rsp);
return 0;
}
static int rcugp_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcugp, NULL);
}
static void print_one_rcu_pending(struct seq_file *m, struct rcu_data *rdp)
{
seq_printf(m, "%3d%cnp=%ld ",
rdp->cpu,
cpu_is_offline(rdp->cpu) ? '!' : ' ',
rdp->n_rcu_pending);
seq_printf(m, "qsp=%ld rpq=%ld cbr=%ld cng=%ld ",
rdp->n_rp_qs_pending,
rdp->n_rp_report_qs,
rdp->n_rp_cb_ready,
rdp->n_rp_cpu_needs_gp);
seq_printf(m, "gpc=%ld gps=%ld nn=%ld\n",
rdp->n_rp_gp_completed,
rdp->n_rp_gp_started,
rdp->n_rp_need_nothing);
}
static int show_rcu_pending(struct seq_file *m, void *unused)
{
int cpu;
struct rcu_data *rdp;
struct rcu_state *rsp;
for_each_rcu_flavor(rsp) {
seq_printf(m, "%s:\n", rsp->name);
for_each_possible_cpu(cpu) {
rdp = per_cpu_ptr(rsp->rda, cpu);
if (rdp->beenonline)
print_one_rcu_pending(m, rdp);
}
}
return 0;
}
static int rcu_pending_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcu_pending, NULL);
}
static int show_rcutorture(struct seq_file *m, void *unused)
{
seq_printf(m, "rcutorture test sequence: %lu %s\n",
rcutorture_testseq >> 1,
(rcutorture_testseq & 0x1) ? "(test in progress)" : "");
seq_printf(m, "rcutorture update version number: %lu\n",
rcutorture_vernum);
return 0;
}
static int rcutorture_open(struct inode *inode, struct file *file)
{
return single_open(file, show_rcutorture, NULL);
}
static int __init rcutree_trace_init(void)
{
struct dentry *retval;
rcudir = debugfs_create_dir("rcu", NULL);
if (!rcudir)
goto free_out;
retval = debugfs_create_file("rcubarrier", 0444, rcudir,
NULL, &rcubarrier_fops);
if (!retval)
goto free_out;
retval = debugfs_create_file("rcudata", 0444, rcudir,
NULL, &rcudata_fops);
if (!retval)
goto free_out;
retval = debugfs_create_file("rcudata.csv", 0444, rcudir,
NULL, &rcudata_csv_fops);
if (!retval)
goto free_out;
if (rcu_boost_trace_create_file(rcudir))
goto free_out;
retval = debugfs_create_file("rcugp", 0444, rcudir, NULL, &rcugp_fops);
if (!retval)
goto free_out;
retval = debugfs_create_file("rcuhier", 0444, rcudir,
NULL, &rcuhier_fops);
if (!retval)
goto free_out;
retval = debugfs_create_file("rcu_pending", 0444, rcudir,
NULL, &rcu_pending_fops);
if (!retval)
goto free_out;
retval = debugfs_create_file("rcutorture", 0444, rcudir,
NULL, &rcutorture_fops);
if (!retval)
goto free_out;
return 0;
free_out:
debugfs_remove_recursive(rcudir);
return 1;
}
static void __exit rcutree_trace_cleanup(void)
{
debugfs_remove_recursive(rcudir);
}
