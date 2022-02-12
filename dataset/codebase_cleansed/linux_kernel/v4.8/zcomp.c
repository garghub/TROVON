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
static int __zcomp_cpu_notifier(struct zcomp *comp,
unsigned long action, unsigned long cpu)
{
struct zcomp_strm *zstrm;
switch (action) {
case CPU_UP_PREPARE:
if (WARN_ON(*per_cpu_ptr(comp->stream, cpu)))
break;
zstrm = zcomp_strm_alloc(comp);
if (IS_ERR_OR_NULL(zstrm)) {
pr_err("Can't allocate a compression stream\n");
return NOTIFY_BAD;
}
*per_cpu_ptr(comp->stream, cpu) = zstrm;
break;
case CPU_DEAD:
case CPU_UP_CANCELED:
zstrm = *per_cpu_ptr(comp->stream, cpu);
if (!IS_ERR_OR_NULL(zstrm))
zcomp_strm_free(zstrm);
*per_cpu_ptr(comp->stream, cpu) = NULL;
break;
default:
break;
}
return NOTIFY_OK;
}
static int zcomp_cpu_notifier(struct notifier_block *nb,
unsigned long action, void *pcpu)
{
unsigned long cpu = (unsigned long)pcpu;
struct zcomp *comp = container_of(nb, typeof(*comp), notifier);
return __zcomp_cpu_notifier(comp, action, cpu);
}
static int zcomp_init(struct zcomp *comp)
{
unsigned long cpu;
int ret;
comp->notifier.notifier_call = zcomp_cpu_notifier;
comp->stream = alloc_percpu(struct zcomp_strm *);
if (!comp->stream)
return -ENOMEM;
cpu_notifier_register_begin();
for_each_online_cpu(cpu) {
ret = __zcomp_cpu_notifier(comp, CPU_UP_PREPARE, cpu);
if (ret == NOTIFY_BAD)
goto cleanup;
}
__register_cpu_notifier(&comp->notifier);
cpu_notifier_register_done();
return 0;
cleanup:
for_each_online_cpu(cpu)
__zcomp_cpu_notifier(comp, CPU_UP_CANCELED, cpu);
cpu_notifier_register_done();
return -ENOMEM;
}
void zcomp_destroy(struct zcomp *comp)
{
unsigned long cpu;
cpu_notifier_register_begin();
for_each_online_cpu(cpu)
__zcomp_cpu_notifier(comp, CPU_UP_CANCELED, cpu);
__unregister_cpu_notifier(&comp->notifier);
cpu_notifier_register_done();
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
