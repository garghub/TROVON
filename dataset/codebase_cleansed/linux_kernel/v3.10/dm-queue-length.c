static struct selector *alloc_selector(void)
{
struct selector *s = kmalloc(sizeof(*s), GFP_KERNEL);
if (s) {
INIT_LIST_HEAD(&s->valid_paths);
INIT_LIST_HEAD(&s->failed_paths);
}
return s;
}
static int ql_create(struct path_selector *ps, unsigned argc, char **argv)
{
struct selector *s = alloc_selector();
if (!s)
return -ENOMEM;
ps->context = s;
return 0;
}
static void ql_free_paths(struct list_head *paths)
{
struct path_info *pi, *next;
list_for_each_entry_safe(pi, next, paths, list) {
list_del(&pi->list);
kfree(pi);
}
}
static void ql_destroy(struct path_selector *ps)
{
struct selector *s = ps->context;
ql_free_paths(&s->valid_paths);
ql_free_paths(&s->failed_paths);
kfree(s);
ps->context = NULL;
}
static int ql_status(struct path_selector *ps, struct dm_path *path,
status_type_t type, char *result, unsigned maxlen)
{
unsigned sz = 0;
struct path_info *pi;
if (!path)
DMEMIT("0 ");
else {
pi = path->pscontext;
switch (type) {
case STATUSTYPE_INFO:
DMEMIT("%d ", atomic_read(&pi->qlen));
break;
case STATUSTYPE_TABLE:
DMEMIT("%u ", pi->repeat_count);
break;
}
}
return sz;
}
static int ql_add_path(struct path_selector *ps, struct dm_path *path,
int argc, char **argv, char **error)
{
struct selector *s = ps->context;
struct path_info *pi;
unsigned repeat_count = QL_MIN_IO;
char dummy;
if (argc > 1) {
*error = "queue-length ps: incorrect number of arguments";
return -EINVAL;
}
if ((argc == 1) && (sscanf(argv[0], "%u%c", &repeat_count, &dummy) != 1)) {
*error = "queue-length ps: invalid repeat count";
return -EINVAL;
}
pi = kmalloc(sizeof(*pi), GFP_KERNEL);
if (!pi) {
*error = "queue-length ps: Error allocating path information";
return -ENOMEM;
}
pi->path = path;
pi->repeat_count = repeat_count;
atomic_set(&pi->qlen, 0);
path->pscontext = pi;
list_add_tail(&pi->list, &s->valid_paths);
return 0;
}
static void ql_fail_path(struct path_selector *ps, struct dm_path *path)
{
struct selector *s = ps->context;
struct path_info *pi = path->pscontext;
list_move(&pi->list, &s->failed_paths);
}
static int ql_reinstate_path(struct path_selector *ps, struct dm_path *path)
{
struct selector *s = ps->context;
struct path_info *pi = path->pscontext;
list_move_tail(&pi->list, &s->valid_paths);
return 0;
}
static struct dm_path *ql_select_path(struct path_selector *ps,
unsigned *repeat_count, size_t nr_bytes)
{
struct selector *s = ps->context;
struct path_info *pi = NULL, *best = NULL;
if (list_empty(&s->valid_paths))
return NULL;
list_move_tail(s->valid_paths.next, &s->valid_paths);
list_for_each_entry(pi, &s->valid_paths, list) {
if (!best ||
(atomic_read(&pi->qlen) < atomic_read(&best->qlen)))
best = pi;
if (!atomic_read(&best->qlen))
break;
}
if (!best)
return NULL;
*repeat_count = best->repeat_count;
return best->path;
}
static int ql_start_io(struct path_selector *ps, struct dm_path *path,
size_t nr_bytes)
{
struct path_info *pi = path->pscontext;
atomic_inc(&pi->qlen);
return 0;
}
static int ql_end_io(struct path_selector *ps, struct dm_path *path,
size_t nr_bytes)
{
struct path_info *pi = path->pscontext;
atomic_dec(&pi->qlen);
return 0;
}
static int __init dm_ql_init(void)
{
int r = dm_register_path_selector(&ql_ps);
if (r < 0)
DMERR("register failed %d", r);
DMINFO("version " QL_VERSION " loaded");
return r;
}
static void __exit dm_ql_exit(void)
{
int r = dm_unregister_path_selector(&ql_ps);
if (r < 0)
DMERR("unregister failed %d", r);
}
