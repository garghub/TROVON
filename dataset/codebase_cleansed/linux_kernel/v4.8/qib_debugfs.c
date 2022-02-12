static void *_opcode_stats_seq_start(struct seq_file *s, loff_t *pos)
{
struct qib_opcode_stats_perctx *opstats;
if (*pos >= ARRAY_SIZE(opstats->stats))
return NULL;
return pos;
}
static void *_opcode_stats_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
struct qib_opcode_stats_perctx *opstats;
++*pos;
if (*pos >= ARRAY_SIZE(opstats->stats))
return NULL;
return pos;
}
static void _opcode_stats_seq_stop(struct seq_file *s, void *v)
{
}
static int _opcode_stats_seq_show(struct seq_file *s, void *v)
{
loff_t *spos = v;
loff_t i = *spos, j;
u64 n_packets = 0, n_bytes = 0;
struct qib_ibdev *ibd = (struct qib_ibdev *)s->private;
struct qib_devdata *dd = dd_from_dev(ibd);
for (j = 0; j < dd->first_user_ctxt; j++) {
if (!dd->rcd[j])
continue;
n_packets += dd->rcd[j]->opstats->stats[i].n_packets;
n_bytes += dd->rcd[j]->opstats->stats[i].n_bytes;
}
if (!n_packets && !n_bytes)
return SEQ_SKIP;
seq_printf(s, "%02llx %llu/%llu\n", i,
(unsigned long long) n_packets,
(unsigned long long) n_bytes);
return 0;
}
static void *_ctx_stats_seq_start(struct seq_file *s, loff_t *pos)
{
struct qib_ibdev *ibd = (struct qib_ibdev *)s->private;
struct qib_devdata *dd = dd_from_dev(ibd);
if (!*pos)
return SEQ_START_TOKEN;
if (*pos >= dd->first_user_ctxt)
return NULL;
return pos;
}
static void *_ctx_stats_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
struct qib_ibdev *ibd = (struct qib_ibdev *)s->private;
struct qib_devdata *dd = dd_from_dev(ibd);
if (v == SEQ_START_TOKEN)
return pos;
++*pos;
if (*pos >= dd->first_user_ctxt)
return NULL;
return pos;
}
static void _ctx_stats_seq_stop(struct seq_file *s, void *v)
{
}
static int _ctx_stats_seq_show(struct seq_file *s, void *v)
{
loff_t *spos;
loff_t i, j;
u64 n_packets = 0;
struct qib_ibdev *ibd = (struct qib_ibdev *)s->private;
struct qib_devdata *dd = dd_from_dev(ibd);
if (v == SEQ_START_TOKEN) {
seq_puts(s, "Ctx:npkts\n");
return 0;
}
spos = v;
i = *spos;
if (!dd->rcd[i])
return SEQ_SKIP;
for (j = 0; j < ARRAY_SIZE(dd->rcd[i]->opstats->stats); j++)
n_packets += dd->rcd[i]->opstats->stats[j].n_packets;
if (!n_packets)
return SEQ_SKIP;
seq_printf(s, " %llu:%llu\n", i, n_packets);
return 0;
}
static void *_qp_stats_seq_start(struct seq_file *s, loff_t *pos)
__acquires(RCU)
{
struct qib_qp_iter *iter;
loff_t n = *pos;
iter = qib_qp_iter_init(s->private);
rcu_read_lock();
if (!iter)
return NULL;
do {
if (qib_qp_iter_next(iter)) {
kfree(iter);
return NULL;
}
} while (n--);
return iter;
}
static void *_qp_stats_seq_next(struct seq_file *s, void *iter_ptr,
loff_t *pos)
__must_hold(RCU)
{
struct qib_qp_iter *iter = iter_ptr;
(*pos)++;
if (qib_qp_iter_next(iter)) {
kfree(iter);
return NULL;
}
return iter;
}
static void _qp_stats_seq_stop(struct seq_file *s, void *iter_ptr)
__releases(RCU)
{
rcu_read_unlock();
}
static int _qp_stats_seq_show(struct seq_file *s, void *iter_ptr)
{
struct qib_qp_iter *iter = iter_ptr;
if (!iter)
return 0;
qib_qp_iter_print(s, iter);
return 0;
}
void qib_dbg_ibdev_init(struct qib_ibdev *ibd)
{
char name[10];
snprintf(name, sizeof(name), "qib%d", dd_from_dev(ibd)->unit);
ibd->qib_ibdev_dbg = debugfs_create_dir(name, qib_dbg_root);
if (!ibd->qib_ibdev_dbg) {
pr_warn("create of %s failed\n", name);
return;
}
DEBUGFS_FILE_CREATE(opcode_stats);
DEBUGFS_FILE_CREATE(ctx_stats);
DEBUGFS_FILE_CREATE(qp_stats);
}
void qib_dbg_ibdev_exit(struct qib_ibdev *ibd)
{
if (!qib_dbg_root)
goto out;
debugfs_remove_recursive(ibd->qib_ibdev_dbg);
out:
ibd->qib_ibdev_dbg = NULL;
}
void qib_dbg_init(void)
{
qib_dbg_root = debugfs_create_dir(QIB_DRV_NAME, NULL);
if (!qib_dbg_root)
pr_warn("init of debugfs failed\n");
}
void qib_dbg_exit(void)
{
debugfs_remove_recursive(qib_dbg_root);
qib_dbg_root = NULL;
}
