static void free_paths(struct list_head *paths)
{
struct path_info *pi, *next;
list_for_each_entry_safe(pi, next, paths, list) {
list_del(&pi->list);
kfree(pi);
}
}
static struct selector *alloc_selector(void)
{
struct selector *s = kmalloc(sizeof(*s), GFP_KERNEL);
if (s) {
INIT_LIST_HEAD(&s->valid_paths);
INIT_LIST_HEAD(&s->invalid_paths);
}
return s;
}
static int rr_create(struct path_selector *ps, unsigned argc, char **argv)
{
struct selector *s;
s = alloc_selector();
if (!s)
return -ENOMEM;
ps->context = s;
return 0;
}
static void rr_destroy(struct path_selector *ps)
{
struct selector *s = (struct selector *) ps->context;
free_paths(&s->valid_paths);
free_paths(&s->invalid_paths);
kfree(s);
ps->context = NULL;
}
static int rr_status(struct path_selector *ps, struct dm_path *path,
status_type_t type, char *result, unsigned int maxlen)
{
struct path_info *pi;
int sz = 0;
if (!path)
DMEMIT("0 ");
else {
switch(type) {
case STATUSTYPE_INFO:
break;
case STATUSTYPE_TABLE:
pi = path->pscontext;
DMEMIT("%u ", pi->repeat_count);
break;
}
}
return sz;
}
static int rr_add_path(struct path_selector *ps, struct dm_path *path,
int argc, char **argv, char **error)
{
struct selector *s = (struct selector *) ps->context;
struct path_info *pi;
unsigned repeat_count = RR_MIN_IO;
if (argc > 1) {
*error = "round-robin ps: incorrect number of arguments";
return -EINVAL;
}
if ((argc == 1) && (sscanf(argv[0], "%u", &repeat_count) != 1)) {
*error = "round-robin ps: invalid repeat count";
return -EINVAL;
}
pi = kmalloc(sizeof(*pi), GFP_KERNEL);
if (!pi) {
*error = "round-robin ps: Error allocating path context";
return -ENOMEM;
}
pi->path = path;
pi->repeat_count = repeat_count;
path->pscontext = pi;
list_add_tail(&pi->list, &s->valid_paths);
return 0;
}
static void rr_fail_path(struct path_selector *ps, struct dm_path *p)
{
struct selector *s = (struct selector *) ps->context;
struct path_info *pi = p->pscontext;
list_move(&pi->list, &s->invalid_paths);
}
static int rr_reinstate_path(struct path_selector *ps, struct dm_path *p)
{
struct selector *s = (struct selector *) ps->context;
struct path_info *pi = p->pscontext;
list_move(&pi->list, &s->valid_paths);
return 0;
}
static struct dm_path *rr_select_path(struct path_selector *ps,
unsigned *repeat_count, size_t nr_bytes)
{
struct selector *s = (struct selector *) ps->context;
struct path_info *pi = NULL;
if (!list_empty(&s->valid_paths)) {
pi = list_entry(s->valid_paths.next, struct path_info, list);
list_move_tail(&pi->list, &s->valid_paths);
*repeat_count = pi->repeat_count;
}
return pi ? pi->path : NULL;
}
static int __init dm_rr_init(void)
{
int r = dm_register_path_selector(&rr_ps);
if (r < 0)
DMERR("register failed %d", r);
DMINFO("version 1.0.0 loaded");
return r;
}
static void __exit dm_rr_exit(void)
{
int r = dm_unregister_path_selector(&rr_ps);
if (r < 0)
DMERR("unregister failed %d", r);
}
