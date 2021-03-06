static struct rb_node *release_next(struct tracer_stat *ts,
struct rb_node *node)
{
struct stat_node *snode;
struct rb_node *parent = rb_parent(node);
if (node->rb_left)
return node->rb_left;
else if (node->rb_right)
return node->rb_right;
else {
if (!parent)
;
else if (parent->rb_left == node)
parent->rb_left = NULL;
else
parent->rb_right = NULL;
snode = container_of(node, struct stat_node, node);
if (ts->stat_release)
ts->stat_release(snode->stat);
kfree(snode);
return parent;
}
}
static void __reset_stat_session(struct stat_session *session)
{
struct rb_node *node = session->stat_root.rb_node;
while (node)
node = release_next(session->ts, node);
session->stat_root = RB_ROOT;
}
static void reset_stat_session(struct stat_session *session)
{
mutex_lock(&session->stat_mutex);
__reset_stat_session(session);
mutex_unlock(&session->stat_mutex);
}
static void destroy_session(struct stat_session *session)
{
debugfs_remove(session->file);
__reset_stat_session(session);
mutex_destroy(&session->stat_mutex);
kfree(session);
}
static int insert_stat(struct rb_root *root, void *stat, cmp_stat_t cmp)
{
struct rb_node **new = &(root->rb_node), *parent = NULL;
struct stat_node *data;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->stat = stat;
while (*new) {
struct stat_node *this;
int result;
this = container_of(*new, struct stat_node, node);
result = cmp(data->stat, this->stat);
parent = *new;
if (result >= 0)
new = &((*new)->rb_left);
else
new = &((*new)->rb_right);
}
rb_link_node(&data->node, parent, new);
rb_insert_color(&data->node, root);
return 0;
}
static int dummy_cmp(void *p1, void *p2)
{
return -1;
}
static int stat_seq_init(struct stat_session *session)
{
struct tracer_stat *ts = session->ts;
struct rb_root *root = &session->stat_root;
void *stat;
int ret = 0;
int i;
mutex_lock(&session->stat_mutex);
__reset_stat_session(session);
if (!ts->stat_cmp)
ts->stat_cmp = dummy_cmp;
stat = ts->stat_start(ts);
if (!stat)
goto exit;
ret = insert_stat(root, stat, ts->stat_cmp);
if (ret)
goto exit;
for (i = 1; ; i++) {
stat = ts->stat_next(stat, i);
if (!stat)
break;
ret = insert_stat(root, stat, ts->stat_cmp);
if (ret)
goto exit_free_rbtree;
}
exit:
mutex_unlock(&session->stat_mutex);
return ret;
exit_free_rbtree:
__reset_stat_session(session);
mutex_unlock(&session->stat_mutex);
return ret;
}
static void *stat_seq_start(struct seq_file *s, loff_t *pos)
{
struct stat_session *session = s->private;
struct rb_node *node;
int n = *pos;
int i;
mutex_lock(&session->stat_mutex);
if (session->ts->stat_headers) {
if (n == 0)
return SEQ_START_TOKEN;
n--;
}
node = rb_first(&session->stat_root);
for (i = 0; node && i < n; i++)
node = rb_next(node);
return node;
}
static void *stat_seq_next(struct seq_file *s, void *p, loff_t *pos)
{
struct stat_session *session = s->private;
struct rb_node *node = p;
(*pos)++;
if (p == SEQ_START_TOKEN)
return rb_first(&session->stat_root);
return rb_next(node);
}
static void stat_seq_stop(struct seq_file *s, void *p)
{
struct stat_session *session = s->private;
mutex_unlock(&session->stat_mutex);
}
static int stat_seq_show(struct seq_file *s, void *v)
{
struct stat_session *session = s->private;
struct stat_node *l = container_of(v, struct stat_node, node);
if (v == SEQ_START_TOKEN)
return session->ts->stat_headers(s);
return session->ts->stat_show(s, l->stat);
}
static int tracing_stat_open(struct inode *inode, struct file *file)
{
int ret;
struct seq_file *m;
struct stat_session *session = inode->i_private;
ret = stat_seq_init(session);
if (ret)
return ret;
ret = seq_open(file, &trace_stat_seq_ops);
if (ret) {
reset_stat_session(session);
return ret;
}
m = file->private_data;
m->private = session;
return ret;
}
static int tracing_stat_release(struct inode *i, struct file *f)
{
struct stat_session *session = i->i_private;
reset_stat_session(session);
return seq_release(i, f);
}
static int tracing_stat_init(void)
{
struct dentry *d_tracing;
d_tracing = tracing_init_dentry();
if (!d_tracing)
return 0;
stat_dir = debugfs_create_dir("trace_stat", d_tracing);
if (!stat_dir)
pr_warning("Could not create debugfs "
"'trace_stat' entry\n");
return 0;
}
static int init_stat_file(struct stat_session *session)
{
if (!stat_dir && tracing_stat_init())
return -ENODEV;
session->file = debugfs_create_file(session->ts->name, 0644,
stat_dir,
session, &tracing_stat_fops);
if (!session->file)
return -ENOMEM;
return 0;
}
int register_stat_tracer(struct tracer_stat *trace)
{
struct stat_session *session, *node;
int ret;
if (!trace)
return -EINVAL;
if (!trace->stat_start || !trace->stat_next || !trace->stat_show)
return -EINVAL;
mutex_lock(&all_stat_sessions_mutex);
list_for_each_entry(node, &all_stat_sessions, session_list) {
if (node->ts == trace) {
mutex_unlock(&all_stat_sessions_mutex);
return -EINVAL;
}
}
mutex_unlock(&all_stat_sessions_mutex);
session = kzalloc(sizeof(*session), GFP_KERNEL);
if (!session)
return -ENOMEM;
session->ts = trace;
INIT_LIST_HEAD(&session->session_list);
mutex_init(&session->stat_mutex);
ret = init_stat_file(session);
if (ret) {
destroy_session(session);
return ret;
}
mutex_lock(&all_stat_sessions_mutex);
list_add_tail(&session->session_list, &all_stat_sessions);
mutex_unlock(&all_stat_sessions_mutex);
return 0;
}
void unregister_stat_tracer(struct tracer_stat *trace)
{
struct stat_session *node, *tmp;
mutex_lock(&all_stat_sessions_mutex);
list_for_each_entry_safe(node, tmp, &all_stat_sessions, session_list) {
if (node->ts == trace) {
list_del(&node->session_list);
destroy_session(node);
break;
}
}
mutex_unlock(&all_stat_sessions_mutex);
}
