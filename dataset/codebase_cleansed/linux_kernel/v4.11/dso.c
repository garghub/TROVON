char dso__symtab_origin(const struct dso *dso)
{
static const char origin[] = {
[DSO_BINARY_TYPE__KALLSYMS] = 'k',
[DSO_BINARY_TYPE__VMLINUX] = 'v',
[DSO_BINARY_TYPE__JAVA_JIT] = 'j',
[DSO_BINARY_TYPE__DEBUGLINK] = 'l',
[DSO_BINARY_TYPE__BUILD_ID_CACHE] = 'B',
[DSO_BINARY_TYPE__FEDORA_DEBUGINFO] = 'f',
[DSO_BINARY_TYPE__UBUNTU_DEBUGINFO] = 'u',
[DSO_BINARY_TYPE__OPENEMBEDDED_DEBUGINFO] = 'o',
[DSO_BINARY_TYPE__BUILDID_DEBUGINFO] = 'b',
[DSO_BINARY_TYPE__SYSTEM_PATH_DSO] = 'd',
[DSO_BINARY_TYPE__SYSTEM_PATH_KMODULE] = 'K',
[DSO_BINARY_TYPE__SYSTEM_PATH_KMODULE_COMP] = 'm',
[DSO_BINARY_TYPE__GUEST_KALLSYMS] = 'g',
[DSO_BINARY_TYPE__GUEST_KMODULE] = 'G',
[DSO_BINARY_TYPE__GUEST_KMODULE_COMP] = 'M',
[DSO_BINARY_TYPE__GUEST_VMLINUX] = 'V',
};
if (dso == NULL || dso->symtab_type == DSO_BINARY_TYPE__NOT_FOUND)
return '!';
return origin[dso->symtab_type];
}
int dso__read_binary_type_filename(const struct dso *dso,
enum dso_binary_type type,
char *root_dir, char *filename, size_t size)
{
char build_id_hex[SBUILD_ID_SIZE];
int ret = 0;
size_t len;
switch (type) {
case DSO_BINARY_TYPE__DEBUGLINK:
{
const char *last_slash;
char dso_dir[PATH_MAX];
char symfile[PATH_MAX];
unsigned int i;
len = __symbol__join_symfs(filename, size, dso->long_name);
last_slash = filename + len;
while (last_slash != filename && *last_slash != '/')
last_slash--;
strncpy(dso_dir, filename, last_slash - filename);
dso_dir[last_slash-filename] = '\0';
if (!is_regular_file(filename)) {
ret = -1;
break;
}
ret = filename__read_debuglink(filename, symfile, PATH_MAX);
if (ret)
break;
ret = -1;
for (i = 0; i < ARRAY_SIZE(debuglink_paths); i++) {
snprintf(filename, size,
debuglink_paths[i], dso_dir, symfile);
if (is_regular_file(filename)) {
ret = 0;
break;
}
}
break;
}
case DSO_BINARY_TYPE__BUILD_ID_CACHE:
if (dso__build_id_filename(dso, filename, size) == NULL)
ret = -1;
break;
case DSO_BINARY_TYPE__FEDORA_DEBUGINFO:
len = __symbol__join_symfs(filename, size, "/usr/lib/debug");
snprintf(filename + len, size - len, "%s.debug", dso->long_name);
break;
case DSO_BINARY_TYPE__UBUNTU_DEBUGINFO:
len = __symbol__join_symfs(filename, size, "/usr/lib/debug");
snprintf(filename + len, size - len, "%s", dso->long_name);
break;
case DSO_BINARY_TYPE__OPENEMBEDDED_DEBUGINFO:
{
const char *last_slash;
size_t dir_size;
last_slash = dso->long_name + dso->long_name_len;
while (last_slash != dso->long_name && *last_slash != '/')
last_slash--;
len = __symbol__join_symfs(filename, size, "");
dir_size = last_slash - dso->long_name + 2;
if (dir_size > (size - len)) {
ret = -1;
break;
}
len += scnprintf(filename + len, dir_size, "%s", dso->long_name);
len += scnprintf(filename + len , size - len, ".debug%s",
last_slash);
break;
}
case DSO_BINARY_TYPE__BUILDID_DEBUGINFO:
if (!dso->has_build_id) {
ret = -1;
break;
}
build_id__sprintf(dso->build_id,
sizeof(dso->build_id),
build_id_hex);
len = __symbol__join_symfs(filename, size, "/usr/lib/debug/.build-id/");
snprintf(filename + len, size - len, "%.2s/%s.debug",
build_id_hex, build_id_hex + 2);
break;
case DSO_BINARY_TYPE__VMLINUX:
case DSO_BINARY_TYPE__GUEST_VMLINUX:
case DSO_BINARY_TYPE__SYSTEM_PATH_DSO:
__symbol__join_symfs(filename, size, dso->long_name);
break;
case DSO_BINARY_TYPE__GUEST_KMODULE:
case DSO_BINARY_TYPE__GUEST_KMODULE_COMP:
path__join3(filename, size, symbol_conf.symfs,
root_dir, dso->long_name);
break;
case DSO_BINARY_TYPE__SYSTEM_PATH_KMODULE:
case DSO_BINARY_TYPE__SYSTEM_PATH_KMODULE_COMP:
__symbol__join_symfs(filename, size, dso->long_name);
break;
case DSO_BINARY_TYPE__KCORE:
case DSO_BINARY_TYPE__GUEST_KCORE:
snprintf(filename, size, "%s", dso->long_name);
break;
default:
case DSO_BINARY_TYPE__KALLSYMS:
case DSO_BINARY_TYPE__GUEST_KALLSYMS:
case DSO_BINARY_TYPE__JAVA_JIT:
case DSO_BINARY_TYPE__NOT_FOUND:
ret = -1;
break;
}
return ret;
}
bool is_supported_compression(const char *ext)
{
unsigned i;
for (i = 0; compressions[i].fmt; i++) {
if (!strcmp(ext, compressions[i].fmt))
return true;
}
return false;
}
bool is_kernel_module(const char *pathname, int cpumode)
{
struct kmod_path m;
int mode = cpumode & PERF_RECORD_MISC_CPUMODE_MASK;
WARN_ONCE(mode != cpumode,
"Internal error: passing unmasked cpumode (%x) to is_kernel_module",
cpumode);
switch (mode) {
case PERF_RECORD_MISC_USER:
case PERF_RECORD_MISC_HYPERVISOR:
case PERF_RECORD_MISC_GUEST_USER:
return false;
default:
if (kmod_path__parse(&m, pathname)) {
pr_err("Failed to check whether %s is a kernel module or not. Assume it is.",
pathname);
return true;
}
}
return m.kmod;
}
bool decompress_to_file(const char *ext, const char *filename, int output_fd)
{
unsigned i;
for (i = 0; compressions[i].fmt; i++) {
if (!strcmp(ext, compressions[i].fmt))
return !compressions[i].decompress(filename,
output_fd);
}
return false;
}
bool dso__needs_decompress(struct dso *dso)
{
return dso->symtab_type == DSO_BINARY_TYPE__SYSTEM_PATH_KMODULE_COMP ||
dso->symtab_type == DSO_BINARY_TYPE__GUEST_KMODULE_COMP;
}
int __kmod_path__parse(struct kmod_path *m, const char *path,
bool alloc_name, bool alloc_ext)
{
const char *name = strrchr(path, '/');
const char *ext = strrchr(path, '.');
bool is_simple_name = false;
memset(m, 0x0, sizeof(*m));
name = name ? name + 1 : path;
if (name[0] == '[') {
is_simple_name = true;
if ((strncmp(name, "[kernel.kallsyms]", 17) == 0) ||
(strncmp(name, "[guest.kernel.kallsyms", 22) == 0) ||
(strncmp(name, "[vdso]", 6) == 0) ||
(strncmp(name, "[vsyscall]", 10) == 0)) {
m->kmod = false;
} else
m->kmod = true;
}
if ((ext == NULL) || is_simple_name) {
if (alloc_name) {
m->name = strdup(name);
return m->name ? 0 : -ENOMEM;
}
return 0;
}
if (is_supported_compression(ext + 1)) {
m->comp = true;
ext -= 3;
}
if (ext > name)
m->kmod = !strncmp(ext, ".ko", 3);
if (alloc_name) {
if (m->kmod) {
if (asprintf(&m->name, "[%.*s]", (int) (ext - name), name) == -1)
return -ENOMEM;
} else {
if (asprintf(&m->name, "%s", name) == -1)
return -ENOMEM;
}
strxfrchar(m->name, '-', '_');
}
if (alloc_ext && m->comp) {
m->ext = strdup(ext + 4);
if (!m->ext) {
free((void *) m->name);
return -ENOMEM;
}
}
return 0;
}
static void dso__list_add(struct dso *dso)
{
list_add_tail(&dso->data.open_entry, &dso__data_open);
dso__data_open_cnt++;
}
static void dso__list_del(struct dso *dso)
{
list_del(&dso->data.open_entry);
WARN_ONCE(dso__data_open_cnt <= 0,
"DSO data fd counter out of bounds.");
dso__data_open_cnt--;
}
static int do_open(char *name)
{
int fd;
char sbuf[STRERR_BUFSIZE];
do {
fd = open(name, O_RDONLY);
if (fd >= 0)
return fd;
pr_debug("dso open failed: %s\n",
str_error_r(errno, sbuf, sizeof(sbuf)));
if (!dso__data_open_cnt || errno != EMFILE)
break;
close_first_dso();
} while (1);
return -1;
}
static int __open_dso(struct dso *dso, struct machine *machine)
{
int fd;
char *root_dir = (char *)"";
char *name = malloc(PATH_MAX);
if (!name)
return -ENOMEM;
if (machine)
root_dir = machine->root_dir;
if (dso__read_binary_type_filename(dso, dso->binary_type,
root_dir, name, PATH_MAX)) {
free(name);
return -EINVAL;
}
if (!is_regular_file(name))
return -EINVAL;
fd = do_open(name);
free(name);
return fd;
}
static int open_dso(struct dso *dso, struct machine *machine)
{
int fd = __open_dso(dso, machine);
if (fd >= 0) {
dso__list_add(dso);
check_data_close();
}
return fd;
}
static void close_data_fd(struct dso *dso)
{
if (dso->data.fd >= 0) {
close(dso->data.fd);
dso->data.fd = -1;
dso->data.file_size = 0;
dso__list_del(dso);
}
}
static void close_dso(struct dso *dso)
{
close_data_fd(dso);
}
static void close_first_dso(void)
{
struct dso *dso;
dso = list_first_entry(&dso__data_open, struct dso, data.open_entry);
close_dso(dso);
}
static rlim_t get_fd_limit(void)
{
struct rlimit l;
rlim_t limit = 0;
if (getrlimit(RLIMIT_NOFILE, &l) == 0) {
if (l.rlim_cur == RLIM_INFINITY)
limit = l.rlim_cur;
else
limit = l.rlim_cur / 2;
} else {
pr_err("failed to get fd limit\n");
limit = 1;
}
return limit;
}
void reset_fd_limit(void)
{
fd_limit = 0;
}
static bool may_cache_fd(void)
{
if (!fd_limit)
fd_limit = get_fd_limit();
if (fd_limit == RLIM_INFINITY)
return true;
return fd_limit > (rlim_t) dso__data_open_cnt;
}
static void check_data_close(void)
{
bool cache_fd = may_cache_fd();
if (!cache_fd)
close_first_dso();
}
void dso__data_close(struct dso *dso)
{
pthread_mutex_lock(&dso__data_open_lock);
close_dso(dso);
pthread_mutex_unlock(&dso__data_open_lock);
}
static void try_to_open_dso(struct dso *dso, struct machine *machine)
{
enum dso_binary_type binary_type_data[] = {
DSO_BINARY_TYPE__BUILD_ID_CACHE,
DSO_BINARY_TYPE__SYSTEM_PATH_DSO,
DSO_BINARY_TYPE__NOT_FOUND,
};
int i = 0;
if (dso->data.fd >= 0)
return;
if (dso->binary_type != DSO_BINARY_TYPE__NOT_FOUND) {
dso->data.fd = open_dso(dso, machine);
goto out;
}
do {
dso->binary_type = binary_type_data[i++];
dso->data.fd = open_dso(dso, machine);
if (dso->data.fd >= 0)
goto out;
} while (dso->binary_type != DSO_BINARY_TYPE__NOT_FOUND);
out:
if (dso->data.fd >= 0)
dso->data.status = DSO_DATA_STATUS_OK;
else
dso->data.status = DSO_DATA_STATUS_ERROR;
}
int dso__data_get_fd(struct dso *dso, struct machine *machine)
{
if (dso->data.status == DSO_DATA_STATUS_ERROR)
return -1;
if (pthread_mutex_lock(&dso__data_open_lock) < 0)
return -1;
try_to_open_dso(dso, machine);
if (dso->data.fd < 0)
pthread_mutex_unlock(&dso__data_open_lock);
return dso->data.fd;
}
void dso__data_put_fd(struct dso *dso __maybe_unused)
{
pthread_mutex_unlock(&dso__data_open_lock);
}
bool dso__data_status_seen(struct dso *dso, enum dso_data_status_seen by)
{
u32 flag = 1 << by;
if (dso->data.status_seen & flag)
return true;
dso->data.status_seen |= flag;
return false;
}
static void
dso_cache__free(struct dso *dso)
{
struct rb_root *root = &dso->data.cache;
struct rb_node *next = rb_first(root);
pthread_mutex_lock(&dso->lock);
while (next) {
struct dso_cache *cache;
cache = rb_entry(next, struct dso_cache, rb_node);
next = rb_next(&cache->rb_node);
rb_erase(&cache->rb_node, root);
free(cache);
}
pthread_mutex_unlock(&dso->lock);
}
static struct dso_cache *dso_cache__find(struct dso *dso, u64 offset)
{
const struct rb_root *root = &dso->data.cache;
struct rb_node * const *p = &root->rb_node;
const struct rb_node *parent = NULL;
struct dso_cache *cache;
while (*p != NULL) {
u64 end;
parent = *p;
cache = rb_entry(parent, struct dso_cache, rb_node);
end = cache->offset + DSO__DATA_CACHE_SIZE;
if (offset < cache->offset)
p = &(*p)->rb_left;
else if (offset >= end)
p = &(*p)->rb_right;
else
return cache;
}
return NULL;
}
static struct dso_cache *
dso_cache__insert(struct dso *dso, struct dso_cache *new)
{
struct rb_root *root = &dso->data.cache;
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct dso_cache *cache;
u64 offset = new->offset;
pthread_mutex_lock(&dso->lock);
while (*p != NULL) {
u64 end;
parent = *p;
cache = rb_entry(parent, struct dso_cache, rb_node);
end = cache->offset + DSO__DATA_CACHE_SIZE;
if (offset < cache->offset)
p = &(*p)->rb_left;
else if (offset >= end)
p = &(*p)->rb_right;
else
goto out;
}
rb_link_node(&new->rb_node, parent, p);
rb_insert_color(&new->rb_node, root);
cache = NULL;
out:
pthread_mutex_unlock(&dso->lock);
return cache;
}
static ssize_t
dso_cache__memcpy(struct dso_cache *cache, u64 offset,
u8 *data, u64 size)
{
u64 cache_offset = offset - cache->offset;
u64 cache_size = min(cache->size - cache_offset, size);
memcpy(data, cache->data + cache_offset, cache_size);
return cache_size;
}
static ssize_t
dso_cache__read(struct dso *dso, struct machine *machine,
u64 offset, u8 *data, ssize_t size)
{
struct dso_cache *cache;
struct dso_cache *old;
ssize_t ret;
do {
u64 cache_offset;
cache = zalloc(sizeof(*cache) + DSO__DATA_CACHE_SIZE);
if (!cache)
return -ENOMEM;
pthread_mutex_lock(&dso__data_open_lock);
try_to_open_dso(dso, machine);
if (dso->data.fd < 0) {
ret = -errno;
dso->data.status = DSO_DATA_STATUS_ERROR;
break;
}
cache_offset = offset & DSO__DATA_CACHE_MASK;
ret = pread(dso->data.fd, cache->data, DSO__DATA_CACHE_SIZE, cache_offset);
if (ret <= 0)
break;
cache->offset = cache_offset;
cache->size = ret;
} while (0);
pthread_mutex_unlock(&dso__data_open_lock);
if (ret > 0) {
old = dso_cache__insert(dso, cache);
if (old) {
free(cache);
cache = old;
}
ret = dso_cache__memcpy(cache, offset, data, size);
}
if (ret <= 0)
free(cache);
return ret;
}
static ssize_t dso_cache_read(struct dso *dso, struct machine *machine,
u64 offset, u8 *data, ssize_t size)
{
struct dso_cache *cache;
cache = dso_cache__find(dso, offset);
if (cache)
return dso_cache__memcpy(cache, offset, data, size);
else
return dso_cache__read(dso, machine, offset, data, size);
}
static ssize_t cached_read(struct dso *dso, struct machine *machine,
u64 offset, u8 *data, ssize_t size)
{
ssize_t r = 0;
u8 *p = data;
do {
ssize_t ret;
ret = dso_cache_read(dso, machine, offset, p, size);
if (ret < 0)
return ret;
if (!ret)
break;
BUG_ON(ret > size);
r += ret;
p += ret;
offset += ret;
size -= ret;
} while (size);
return r;
}
static int data_file_size(struct dso *dso, struct machine *machine)
{
int ret = 0;
struct stat st;
char sbuf[STRERR_BUFSIZE];
if (dso->data.file_size)
return 0;
if (dso->data.status == DSO_DATA_STATUS_ERROR)
return -1;
pthread_mutex_lock(&dso__data_open_lock);
try_to_open_dso(dso, machine);
if (dso->data.fd < 0) {
ret = -errno;
dso->data.status = DSO_DATA_STATUS_ERROR;
goto out;
}
if (fstat(dso->data.fd, &st) < 0) {
ret = -errno;
pr_err("dso cache fstat failed: %s\n",
str_error_r(errno, sbuf, sizeof(sbuf)));
dso->data.status = DSO_DATA_STATUS_ERROR;
goto out;
}
dso->data.file_size = st.st_size;
out:
pthread_mutex_unlock(&dso__data_open_lock);
return ret;
}
off_t dso__data_size(struct dso *dso, struct machine *machine)
{
if (data_file_size(dso, machine))
return -1;
return dso->data.file_size;
}
static ssize_t data_read_offset(struct dso *dso, struct machine *machine,
u64 offset, u8 *data, ssize_t size)
{
if (data_file_size(dso, machine))
return -1;
if (offset > dso->data.file_size)
return -1;
if (offset + size < offset)
return -1;
return cached_read(dso, machine, offset, data, size);
}
ssize_t dso__data_read_offset(struct dso *dso, struct machine *machine,
u64 offset, u8 *data, ssize_t size)
{
if (dso->data.status == DSO_DATA_STATUS_ERROR)
return -1;
return data_read_offset(dso, machine, offset, data, size);
}
ssize_t dso__data_read_addr(struct dso *dso, struct map *map,
struct machine *machine, u64 addr,
u8 *data, ssize_t size)
{
u64 offset = map->map_ip(map, addr);
return dso__data_read_offset(dso, machine, offset, data, size);
}
struct map *dso__new_map(const char *name)
{
struct map *map = NULL;
struct dso *dso = dso__new(name);
if (dso)
map = map__new2(0, dso, MAP__FUNCTION);
return map;
}
struct dso *machine__findnew_kernel(struct machine *machine, const char *name,
const char *short_name, int dso_type)
{
struct dso *dso = machine__findnew_dso(machine, name);
if (dso != NULL) {
dso__set_short_name(dso, short_name, false);
dso->kernel = dso_type;
}
return dso;
}
static struct dso *__dso__findlink_by_longname(struct rb_root *root,
struct dso *dso, const char *name)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
if (!name)
name = dso->long_name;
while (*p) {
struct dso *this = rb_entry(*p, struct dso, rb_node);
int rc = strcmp(name, this->long_name);
parent = *p;
if (rc == 0) {
if (!dso || (dso == this))
return this;
rc = strcmp(dso->short_name, this->short_name);
if (rc == 0) {
pr_err("Duplicated dso name: %s\n", name);
return NULL;
}
}
if (rc < 0)
p = &parent->rb_left;
else
p = &parent->rb_right;
}
if (dso) {
rb_link_node(&dso->rb_node, parent, p);
rb_insert_color(&dso->rb_node, root);
dso->root = root;
}
return NULL;
}
static inline struct dso *__dso__find_by_longname(struct rb_root *root,
const char *name)
{
return __dso__findlink_by_longname(root, NULL, name);
}
void dso__set_long_name(struct dso *dso, const char *name, bool name_allocated)
{
struct rb_root *root = dso->root;
if (name == NULL)
return;
if (dso->long_name_allocated)
free((char *)dso->long_name);
if (root) {
rb_erase(&dso->rb_node, root);
RB_CLEAR_NODE(&dso->rb_node);
dso->root = NULL;
}
dso->long_name = name;
dso->long_name_len = strlen(name);
dso->long_name_allocated = name_allocated;
if (root)
__dso__findlink_by_longname(root, dso, NULL);
}
void dso__set_short_name(struct dso *dso, const char *name, bool name_allocated)
{
if (name == NULL)
return;
if (dso->short_name_allocated)
free((char *)dso->short_name);
dso->short_name = name;
dso->short_name_len = strlen(name);
dso->short_name_allocated = name_allocated;
}
static void dso__set_basename(struct dso *dso)
{
char *base, *lname = strdup(dso->long_name);
if (!lname)
return;
base = strdup(basename(lname));
free(lname);
if (!base)
return;
dso__set_short_name(dso, base, true);
}
int dso__name_len(const struct dso *dso)
{
if (!dso)
return strlen("[unknown]");
if (verbose > 0)
return dso->long_name_len;
return dso->short_name_len;
}
bool dso__loaded(const struct dso *dso, enum map_type type)
{
return dso->loaded & (1 << type);
}
bool dso__sorted_by_name(const struct dso *dso, enum map_type type)
{
return dso->sorted_by_name & (1 << type);
}
void dso__set_sorted_by_name(struct dso *dso, enum map_type type)
{
dso->sorted_by_name |= (1 << type);
}
struct dso *dso__new(const char *name)
{
struct dso *dso = calloc(1, sizeof(*dso) + strlen(name) + 1);
if (dso != NULL) {
int i;
strcpy(dso->name, name);
dso__set_long_name(dso, dso->name, false);
dso__set_short_name(dso, dso->name, false);
for (i = 0; i < MAP__NR_TYPES; ++i)
dso->symbols[i] = dso->symbol_names[i] = RB_ROOT;
dso->data.cache = RB_ROOT;
dso->data.fd = -1;
dso->data.status = DSO_DATA_STATUS_UNKNOWN;
dso->symtab_type = DSO_BINARY_TYPE__NOT_FOUND;
dso->binary_type = DSO_BINARY_TYPE__NOT_FOUND;
dso->is_64_bit = (sizeof(void *) == 8);
dso->loaded = 0;
dso->rel = 0;
dso->sorted_by_name = 0;
dso->has_build_id = 0;
dso->has_srcline = 1;
dso->a2l_fails = 1;
dso->kernel = DSO_TYPE_USER;
dso->needs_swap = DSO_SWAP__UNSET;
RB_CLEAR_NODE(&dso->rb_node);
dso->root = NULL;
INIT_LIST_HEAD(&dso->node);
INIT_LIST_HEAD(&dso->data.open_entry);
pthread_mutex_init(&dso->lock, NULL);
atomic_set(&dso->refcnt, 1);
}
return dso;
}
void dso__delete(struct dso *dso)
{
int i;
if (!RB_EMPTY_NODE(&dso->rb_node))
pr_err("DSO %s is still in rbtree when being deleted!\n",
dso->long_name);
for (i = 0; i < MAP__NR_TYPES; ++i)
symbols__delete(&dso->symbols[i]);
if (dso->short_name_allocated) {
zfree((char **)&dso->short_name);
dso->short_name_allocated = false;
}
if (dso->long_name_allocated) {
zfree((char **)&dso->long_name);
dso->long_name_allocated = false;
}
dso__data_close(dso);
auxtrace_cache__free(dso->auxtrace_cache);
dso_cache__free(dso);
dso__free_a2l(dso);
zfree(&dso->symsrc_filename);
pthread_mutex_destroy(&dso->lock);
free(dso);
}
struct dso *dso__get(struct dso *dso)
{
if (dso)
atomic_inc(&dso->refcnt);
return dso;
}
void dso__put(struct dso *dso)
{
if (dso && atomic_dec_and_test(&dso->refcnt))
dso__delete(dso);
}
void dso__set_build_id(struct dso *dso, void *build_id)
{
memcpy(dso->build_id, build_id, sizeof(dso->build_id));
dso->has_build_id = 1;
}
bool dso__build_id_equal(const struct dso *dso, u8 *build_id)
{
return memcmp(dso->build_id, build_id, sizeof(dso->build_id)) == 0;
}
void dso__read_running_kernel_build_id(struct dso *dso, struct machine *machine)
{
char path[PATH_MAX];
if (machine__is_default_guest(machine))
return;
sprintf(path, "%s/sys/kernel/notes", machine->root_dir);
if (sysfs__read_build_id(path, dso->build_id,
sizeof(dso->build_id)) == 0)
dso->has_build_id = true;
}
int dso__kernel_module_get_build_id(struct dso *dso,
const char *root_dir)
{
char filename[PATH_MAX];
const char *name = dso->short_name + 1;
snprintf(filename, sizeof(filename),
"%s/sys/module/%.*s/notes/.note.gnu.build-id",
root_dir, (int)strlen(name) - 1, name);
if (sysfs__read_build_id(filename, dso->build_id,
sizeof(dso->build_id)) == 0)
dso->has_build_id = true;
return 0;
}
bool __dsos__read_build_ids(struct list_head *head, bool with_hits)
{
bool have_build_id = false;
struct dso *pos;
list_for_each_entry(pos, head, node) {
if (with_hits && !pos->hit && !dso__is_vdso(pos))
continue;
if (pos->has_build_id) {
have_build_id = true;
continue;
}
if (filename__read_build_id(pos->long_name, pos->build_id,
sizeof(pos->build_id)) > 0) {
have_build_id = true;
pos->has_build_id = true;
}
}
return have_build_id;
}
void __dsos__add(struct dsos *dsos, struct dso *dso)
{
list_add_tail(&dso->node, &dsos->head);
__dso__findlink_by_longname(&dsos->root, dso, NULL);
dso__get(dso);
}
void dsos__add(struct dsos *dsos, struct dso *dso)
{
pthread_rwlock_wrlock(&dsos->lock);
__dsos__add(dsos, dso);
pthread_rwlock_unlock(&dsos->lock);
}
struct dso *__dsos__find(struct dsos *dsos, const char *name, bool cmp_short)
{
struct dso *pos;
if (cmp_short) {
list_for_each_entry(pos, &dsos->head, node)
if (strcmp(pos->short_name, name) == 0)
return pos;
return NULL;
}
return __dso__find_by_longname(&dsos->root, name);
}
struct dso *dsos__find(struct dsos *dsos, const char *name, bool cmp_short)
{
struct dso *dso;
pthread_rwlock_rdlock(&dsos->lock);
dso = __dsos__find(dsos, name, cmp_short);
pthread_rwlock_unlock(&dsos->lock);
return dso;
}
struct dso *__dsos__addnew(struct dsos *dsos, const char *name)
{
struct dso *dso = dso__new(name);
if (dso != NULL) {
__dsos__add(dsos, dso);
dso__set_basename(dso);
dso__put(dso);
}
return dso;
}
struct dso *__dsos__findnew(struct dsos *dsos, const char *name)
{
struct dso *dso = __dsos__find(dsos, name, false);
return dso ? dso : __dsos__addnew(dsos, name);
}
struct dso *dsos__findnew(struct dsos *dsos, const char *name)
{
struct dso *dso;
pthread_rwlock_wrlock(&dsos->lock);
dso = dso__get(__dsos__findnew(dsos, name));
pthread_rwlock_unlock(&dsos->lock);
return dso;
}
size_t __dsos__fprintf_buildid(struct list_head *head, FILE *fp,
bool (skip)(struct dso *dso, int parm), int parm)
{
struct dso *pos;
size_t ret = 0;
list_for_each_entry(pos, head, node) {
if (skip && skip(pos, parm))
continue;
ret += dso__fprintf_buildid(pos, fp);
ret += fprintf(fp, " %s\n", pos->long_name);
}
return ret;
}
size_t __dsos__fprintf(struct list_head *head, FILE *fp)
{
struct dso *pos;
size_t ret = 0;
list_for_each_entry(pos, head, node) {
int i;
for (i = 0; i < MAP__NR_TYPES; ++i)
ret += dso__fprintf(pos, i, fp);
}
return ret;
}
size_t dso__fprintf_buildid(struct dso *dso, FILE *fp)
{
char sbuild_id[SBUILD_ID_SIZE];
build_id__sprintf(dso->build_id, sizeof(dso->build_id), sbuild_id);
return fprintf(fp, "%s", sbuild_id);
}
size_t dso__fprintf(struct dso *dso, enum map_type type, FILE *fp)
{
struct rb_node *nd;
size_t ret = fprintf(fp, "dso: %s (", dso->short_name);
if (dso->short_name != dso->long_name)
ret += fprintf(fp, "%s, ", dso->long_name);
ret += fprintf(fp, "%s, %sloaded, ", map_type__name[type],
dso__loaded(dso, type) ? "" : "NOT ");
ret += dso__fprintf_buildid(dso, fp);
ret += fprintf(fp, ")\n");
for (nd = rb_first(&dso->symbols[type]); nd; nd = rb_next(nd)) {
struct symbol *pos = rb_entry(nd, struct symbol, rb_node);
ret += symbol__fprintf(pos, fp);
}
return ret;
}
enum dso_type dso__type(struct dso *dso, struct machine *machine)
{
int fd;
enum dso_type type = DSO__TYPE_UNKNOWN;
fd = dso__data_get_fd(dso, machine);
if (fd >= 0) {
type = dso__type_fd(fd);
dso__data_put_fd(dso);
}
return type;
}
int dso__strerror_load(struct dso *dso, char *buf, size_t buflen)
{
int idx, errnum = dso->load_errno;
static const char *dso_load__error_str[] = {
"Internal tools/perf/ library error",
"Invalid ELF file",
"Can not read build id",
"Mismatching build id",
"Decompression failure",
};
BUG_ON(buflen == 0);
if (errnum >= 0) {
const char *err = str_error_r(errnum, buf, buflen);
if (err != buf)
scnprintf(buf, buflen, "%s", err);
return 0;
}
if (errnum < __DSO_LOAD_ERRNO__START || errnum >= __DSO_LOAD_ERRNO__END)
return -1;
idx = errnum - __DSO_LOAD_ERRNO__START;
scnprintf(buf, buflen, "%s", dso_load__error_str[idx]);
return 0;
}
