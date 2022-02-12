static void zcomp_strm_free(struct zcomp_strm *zstrm)
{
if (!IS_ERR_OR_NULL(zstrm->tfm))
crypto_free_comp(zstrm->tfm);
free_pages((unsigned long)zstrm->buffer, 1);
kfree(zstrm);
}
static struct zcomp_strm *zcomp_strm_alloc(struct zcomp *comp)
{
struct zcomp_strm *zstrm = kmalloc(sizeof(*zstrm), GFP_KERNEL);
if (!zstrm)
return NULL;
zstrm->tfm = crypto_alloc_comp(comp->name, 0, 0);
zstrm->buffer = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO, 1);
if (IS_ERR_OR_NULL(zstrm->tfm) || !zstrm->buffer) {
zcomp_strm_free(zstrm);
zstrm = NULL;
}
return zstrm;
}
bool zcomp_available_algorithm(const char *comp)
{
int i = 0;
while (backends[i]) {
if (sysfs_streq(comp, backends[i]))
return true;
i++;
}
return crypto_has_comp(comp, 0, 0) == 1;
}
ssize_t zcomp_available_show(const char *comp, char *buf)
{
bool known_algorithm = false;
ssize_t sz = 0;
int i = 0;
for (; backends[i]; i++) {
if (!strcmp(comp, backends[i])) {
known_algorithm = true;
sz += scnprintf(buf + sz, PAGE_SIZE - sz - 2,
"[%s] ", backends[i]);
} else {
sz += scnprintf(buf + sz, PAGE_SIZE - sz - 2,
"%s ", backends[i]);
}
}
if (!known_algorithm && crypto_has_comp(comp, 0, 0) == 1)
sz += scnprintf(buf + sz, PAGE_SIZE - sz - 2,
"[%s] ", comp);
sz += scnprintf(buf + sz, PAGE_SIZE - sz, "\n");
return sz;
}
struct zcomp_strm *zcomp_stream_get(struct zcomp *comp)
{
return *get_cpu_ptr(comp->stream);
}
void zcomp_stream_put(struct zcomp *comp)
{
put_cpu_ptr(comp->stream);
}
int zcomp_compress(struct zcomp_strm *zstrm,
const void *src, unsigned int *dst_len)
{
*dst_len = PAGE_SIZE * 2;
return crypto_comp_compress(zstrm->tfm,
src, PAGE_SIZE,
zstrm->buffer, dst_len);
}
int zcomp_decompress(struct zcomp_strm *zstrm,
const void *src, unsigned int src_len, void *dst)
{
unsigned int dst_len = PAGE_SIZE;
return crypto_comp_decompress(zstrm->tfm,
src, src_len,
dst, &dst_len);
}
int zcomp_cpu_up_prepare(unsigned int cpu, struct hlist_node *node)
{
struct zcomp *comp = hlist_entry(node, struct zcomp, node);
struct zcomp_strm *zstrm;
if (WARN_ON(*per_cpu_ptr(comp->stream, cpu)))
return 0;
zstrm = zcomp_strm_alloc(comp);
if (IS_ERR_OR_NULL(zstrm)) {
pr_err("Can't allocate a compression stream\n");
return -ENOMEM;
}
*per_cpu_ptr(comp->stream, cpu) = zstrm;
return 0;
}
int zcomp_cpu_dead(unsigned int cpu, struct hlist_node *node)
{
struct zcomp *comp = hlist_entry(node, struct zcomp, node);
struct zcomp_strm *zstrm;
zstrm = *per_cpu_ptr(comp->stream, cpu);
if (!IS_ERR_OR_NULL(zstrm))
zcomp_strm_free(zstrm);
*per_cpu_ptr(comp->stream, cpu) = NULL;
return 0;
}
static int zcomp_init(struct zcomp *comp)
{
int ret;
comp->stream = alloc_percpu(struct zcomp_strm *);
if (!comp->stream)
return -ENOMEM;
ret = cpuhp_state_add_instance(CPUHP_ZCOMP_PREPARE, &comp->node);
if (ret < 0)
goto cleanup;
return 0;
cleanup:
free_percpu(comp->stream);
return ret;
}
void zcomp_destroy(struct zcomp *comp)
{
cpuhp_state_remove_instance(CPUHP_ZCOMP_PREPARE, &comp->node);
free_percpu(comp->stream);
kfree(comp);
}
struct zcomp *zcomp_create(const char *compress)
{
struct zcomp *comp;
int error;
if (!zcomp_available_algorithm(compress))
return ERR_PTR(-EINVAL);
comp = kzalloc(sizeof(struct zcomp), GFP_KERNEL);
if (!comp)
return ERR_PTR(-ENOMEM);
comp->name = compress;
error = zcomp_init(comp);
if (error) {
kfree(comp);
return ERR_PTR(error);
}
return comp;
}
