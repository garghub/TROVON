static inline struct target_type *__find_target_type(const char *name)
{
struct target_type *tt;
list_for_each_entry(tt, &_targets, list)
if (!strcmp(name, tt->name))
return tt;
return NULL;
}
static struct target_type *get_target_type(const char *name)
{
struct target_type *tt;
down_read(&_lock);
tt = __find_target_type(name);
if (tt && !try_module_get(tt->module))
tt = NULL;
up_read(&_lock);
return tt;
}
static void load_module(const char *name)
{
request_module("dm-%s", name);
}
struct target_type *dm_get_target_type(const char *name)
{
struct target_type *tt = get_target_type(name);
if (!tt) {
load_module(name);
tt = get_target_type(name);
}
return tt;
}
void dm_put_target_type(struct target_type *tt)
{
down_read(&_lock);
module_put(tt->module);
up_read(&_lock);
}
int dm_target_iterate(void (*iter_func)(struct target_type *tt,
void *param), void *param)
{
struct target_type *tt;
down_read(&_lock);
list_for_each_entry(tt, &_targets, list)
iter_func(tt, param);
up_read(&_lock);
return 0;
}
int dm_register_target(struct target_type *tt)
{
int rv = 0;
down_write(&_lock);
if (__find_target_type(tt->name))
rv = -EEXIST;
else
list_add(&tt->list, &_targets);
up_write(&_lock);
return rv;
}
void dm_unregister_target(struct target_type *tt)
{
down_write(&_lock);
if (!__find_target_type(tt->name)) {
DMCRIT("Unregistering unrecognised target: %s", tt->name);
BUG();
}
list_del(&tt->list);
up_write(&_lock);
}
static int io_err_ctr(struct dm_target *tt, unsigned int argc, char **args)
{
tt->num_discard_bios = 1;
return 0;
}
static void io_err_dtr(struct dm_target *tt)
{
}
static int io_err_map(struct dm_target *tt, struct bio *bio)
{
return -EIO;
}
static int io_err_clone_and_map_rq(struct dm_target *ti, struct request *rq,
union map_info *map_context,
struct request **clone)
{
return DM_MAPIO_KILL;
}
static void io_err_release_clone_rq(struct request *clone)
{
}
static long io_err_dax_direct_access(struct dm_target *ti, pgoff_t pgoff,
long nr_pages, void **kaddr, pfn_t *pfn)
{
return -EIO;
}
int __init dm_target_init(void)
{
return dm_register_target(&error_target);
}
void dm_target_exit(void)
{
dm_unregister_target(&error_target);
}
