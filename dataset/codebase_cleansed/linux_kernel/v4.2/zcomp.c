static struct zcomp_backend *find_backend(const char *compress)
{
int i = 0;
while (backends[i]) {
if (sysfs_streq(compress, backends[i]->name))
break;
i++;
}
return backends[i];
}
static void zcomp_strm_free(struct zcomp *comp, struct zcomp_strm *zstrm)
{
if (zstrm->private)
comp->backend->destroy(zstrm->private);
free_pages((unsigned long)zstrm->buffer, 1);
kfree(zstrm);
}
static struct zcomp_strm *zcomp_strm_alloc(struct zcomp *comp)
{
struct zcomp_strm *zstrm = kmalloc(sizeof(*zstrm), GFP_KERNEL);
if (!zstrm)
return NULL;
zstrm->private = comp->backend->create();
zstrm->buffer = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO, 1);
if (!zstrm->private || !zstrm->buffer) {
zcomp_strm_free(comp, zstrm);
zstrm = NULL;
}
return zstrm;
}
static struct zcomp_strm *zcomp_strm_multi_find(struct zcomp *comp)
{
struct zcomp_strm_multi *zs = comp->stream;
struct zcomp_strm *zstrm;
while (1) {
spin_lock(&zs->strm_lock);
if (!list_empty(&zs->idle_strm)) {
zstrm = list_entry(zs->idle_strm.next,
struct zcomp_strm, list);
list_del(&zstrm->list);
spin_unlock(&zs->strm_lock);
return zstrm;
}
if (zs->avail_strm >= zs->max_strm) {
spin_unlock(&zs->strm_lock);
wait_event(zs->strm_wait, !list_empty(&zs->idle_strm));
continue;
}
zs->avail_strm++;
spin_unlock(&zs->strm_lock);
zstrm = zcomp_strm_alloc(comp);
if (!zstrm) {
spin_lock(&zs->strm_lock);
zs->avail_strm--;
spin_unlock(&zs->strm_lock);
wait_event(zs->strm_wait, !list_empty(&zs->idle_strm));
continue;
}
break;
}
return zstrm;
}
static void zcomp_strm_multi_release(struct zcomp *comp, struct zcomp_strm *zstrm)
{
struct zcomp_strm_multi *zs = comp->stream;
spin_lock(&zs->strm_lock);
if (zs->avail_strm <= zs->max_strm) {
list_add(&zstrm->list, &zs->idle_strm);
spin_unlock(&zs->strm_lock);
wake_up(&zs->strm_wait);
return;
}
zs->avail_strm--;
spin_unlock(&zs->strm_lock);
zcomp_strm_free(comp, zstrm);
}
static bool zcomp_strm_multi_set_max_streams(struct zcomp *comp, int num_strm)
{
struct zcomp_strm_multi *zs = comp->stream;
struct zcomp_strm *zstrm;
spin_lock(&zs->strm_lock);
zs->max_strm = num_strm;
while (zs->avail_strm > num_strm && !list_empty(&zs->idle_strm)) {
zstrm = list_entry(zs->idle_strm.next,
struct zcomp_strm, list);
list_del(&zstrm->list);
zcomp_strm_free(comp, zstrm);
zs->avail_strm--;
}
spin_unlock(&zs->strm_lock);
return true;
}
static void zcomp_strm_multi_destroy(struct zcomp *comp)
{
struct zcomp_strm_multi *zs = comp->stream;
struct zcomp_strm *zstrm;
while (!list_empty(&zs->idle_strm)) {
zstrm = list_entry(zs->idle_strm.next,
struct zcomp_strm, list);
list_del(&zstrm->list);
zcomp_strm_free(comp, zstrm);
}
kfree(zs);
}
static int zcomp_strm_multi_create(struct zcomp *comp, int max_strm)
{
struct zcomp_strm *zstrm;
struct zcomp_strm_multi *zs;
comp->destroy = zcomp_strm_multi_destroy;
comp->strm_find = zcomp_strm_multi_find;
comp->strm_release = zcomp_strm_multi_release;
comp->set_max_streams = zcomp_strm_multi_set_max_streams;
zs = kmalloc(sizeof(struct zcomp_strm_multi), GFP_KERNEL);
if (!zs)
return -ENOMEM;
comp->stream = zs;
spin_lock_init(&zs->strm_lock);
INIT_LIST_HEAD(&zs->idle_strm);
init_waitqueue_head(&zs->strm_wait);
zs->max_strm = max_strm;
zs->avail_strm = 1;
zstrm = zcomp_strm_alloc(comp);
if (!zstrm) {
kfree(zs);
return -ENOMEM;
}
list_add(&zstrm->list, &zs->idle_strm);
return 0;
}
static struct zcomp_strm *zcomp_strm_single_find(struct zcomp *comp)
{
struct zcomp_strm_single *zs = comp->stream;
mutex_lock(&zs->strm_lock);
return zs->zstrm;
}
static void zcomp_strm_single_release(struct zcomp *comp,
struct zcomp_strm *zstrm)
{
struct zcomp_strm_single *zs = comp->stream;
mutex_unlock(&zs->strm_lock);
}
static bool zcomp_strm_single_set_max_streams(struct zcomp *comp, int num_strm)
{
return false;
}
static void zcomp_strm_single_destroy(struct zcomp *comp)
{
struct zcomp_strm_single *zs = comp->stream;
zcomp_strm_free(comp, zs->zstrm);
kfree(zs);
}
static int zcomp_strm_single_create(struct zcomp *comp)
{
struct zcomp_strm_single *zs;
comp->destroy = zcomp_strm_single_destroy;
comp->strm_find = zcomp_strm_single_find;
comp->strm_release = zcomp_strm_single_release;
comp->set_max_streams = zcomp_strm_single_set_max_streams;
zs = kmalloc(sizeof(struct zcomp_strm_single), GFP_KERNEL);
if (!zs)
return -ENOMEM;
comp->stream = zs;
mutex_init(&zs->strm_lock);
zs->zstrm = zcomp_strm_alloc(comp);
if (!zs->zstrm) {
kfree(zs);
return -ENOMEM;
}
return 0;
}
ssize_t zcomp_available_show(const char *comp, char *buf)
{
ssize_t sz = 0;
int i = 0;
while (backends[i]) {
if (!strcmp(comp, backends[i]->name))
sz += scnprintf(buf + sz, PAGE_SIZE - sz - 2,
"[%s] ", backends[i]->name);
else
sz += scnprintf(buf + sz, PAGE_SIZE - sz - 2,
"%s ", backends[i]->name);
i++;
}
sz += scnprintf(buf + sz, PAGE_SIZE - sz, "\n");
return sz;
}
bool zcomp_available_algorithm(const char *comp)
{
return find_backend(comp) != NULL;
}
bool zcomp_set_max_streams(struct zcomp *comp, int num_strm)
{
return comp->set_max_streams(comp, num_strm);
}
struct zcomp_strm *zcomp_strm_find(struct zcomp *comp)
{
return comp->strm_find(comp);
}
void zcomp_strm_release(struct zcomp *comp, struct zcomp_strm *zstrm)
{
comp->strm_release(comp, zstrm);
}
int zcomp_compress(struct zcomp *comp, struct zcomp_strm *zstrm,
const unsigned char *src, size_t *dst_len)
{
return comp->backend->compress(src, zstrm->buffer, dst_len,
zstrm->private);
}
int zcomp_decompress(struct zcomp *comp, const unsigned char *src,
size_t src_len, unsigned char *dst)
{
return comp->backend->decompress(src, src_len, dst);
}
void zcomp_destroy(struct zcomp *comp)
{
comp->destroy(comp);
kfree(comp);
}
struct zcomp *zcomp_create(const char *compress, int max_strm)
{
struct zcomp *comp;
struct zcomp_backend *backend;
backend = find_backend(compress);
if (!backend)
return ERR_PTR(-EINVAL);
comp = kzalloc(sizeof(struct zcomp), GFP_KERNEL);
if (!comp)
return ERR_PTR(-ENOMEM);
comp->backend = backend;
if (max_strm > 1)
zcomp_strm_multi_create(comp, max_strm);
else
zcomp_strm_single_create(comp);
if (!comp->stream) {
kfree(comp);
return ERR_PTR(-ENOMEM);
}
return comp;
}
