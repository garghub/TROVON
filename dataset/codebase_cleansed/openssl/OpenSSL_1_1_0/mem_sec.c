int CRYPTO_secure_malloc_init(size_t size, int minsize)
{
#ifdef IMPLEMENTED
int ret = 0;
if (!secure_mem_initialized) {
sec_malloc_lock = CRYPTO_THREAD_lock_new();
if (sec_malloc_lock == NULL)
return 0;
ret = sh_init(size, minsize);
secure_mem_initialized = 1;
}
return ret;
#else
return 0;
#endif
}
int CRYPTO_secure_malloc_done()
{
#ifdef IMPLEMENTED
if (secure_mem_used == 0) {
sh_done();
secure_mem_initialized = 0;
CRYPTO_THREAD_lock_free(sec_malloc_lock);
return 1;
}
#endif
return 0;
}
int CRYPTO_secure_malloc_initialized()
{
#ifdef IMPLEMENTED
return secure_mem_initialized;
#else
return 0;
#endif
}
void *CRYPTO_secure_malloc(size_t num, const char *file, int line)
{
#ifdef IMPLEMENTED
void *ret;
size_t actual_size;
if (!secure_mem_initialized) {
return CRYPTO_malloc(num, file, line);
}
CRYPTO_THREAD_write_lock(sec_malloc_lock);
ret = sh_malloc(num);
actual_size = ret ? sh_actual_size(ret) : 0;
secure_mem_used += actual_size;
CRYPTO_THREAD_unlock(sec_malloc_lock);
return ret;
#else
return CRYPTO_malloc(num, file, line);
#endif
}
void *CRYPTO_secure_zalloc(size_t num, const char *file, int line)
{
void *ret = CRYPTO_secure_malloc(num, file, line);
if (ret != NULL)
memset(ret, 0, num);
return ret;
}
void CRYPTO_secure_free(void *ptr, const char *file, int line)
{
#ifdef IMPLEMENTED
size_t actual_size;
if (ptr == NULL)
return;
if (!CRYPTO_secure_allocated(ptr)) {
CRYPTO_free(ptr, file, line);
return;
}
CRYPTO_THREAD_write_lock(sec_malloc_lock);
actual_size = sh_actual_size(ptr);
CLEAR(ptr, actual_size);
secure_mem_used -= actual_size;
sh_free(ptr);
CRYPTO_THREAD_unlock(sec_malloc_lock);
#else
CRYPTO_free(ptr, file, line);
#endif
}
int CRYPTO_secure_allocated(const void *ptr)
{
#ifdef IMPLEMENTED
int ret;
if (!secure_mem_initialized)
return 0;
CRYPTO_THREAD_write_lock(sec_malloc_lock);
ret = sh_allocated(ptr);
CRYPTO_THREAD_unlock(sec_malloc_lock);
return ret;
#else
return 0;
#endif
}
size_t CRYPTO_secure_used()
{
#ifdef IMPLEMENTED
return secure_mem_used;
#else
return 0;
#endif
}
size_t CRYPTO_secure_actual_size(void *ptr)
{
#ifdef IMPLEMENTED
size_t actual_size;
CRYPTO_THREAD_write_lock(sec_malloc_lock);
actual_size = sh_actual_size(ptr);
CRYPTO_THREAD_unlock(sec_malloc_lock);
return actual_size;
#else
return 0;
#endif
}
static size_t sh_getlist(char *ptr)
{
ossl_ssize_t list = sh.freelist_size - 1;
size_t bit = (sh.arena_size + ptr - sh.arena) / sh.minsize;
for (; bit; bit >>= 1, list--) {
if (TESTBIT(sh.bittable, bit))
break;
OPENSSL_assert((bit & 1) == 0);
}
return list;
}
static int sh_testbit(char *ptr, int list, unsigned char *table)
{
size_t bit;
OPENSSL_assert(list >= 0 && list < sh.freelist_size);
OPENSSL_assert(((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0);
bit = (ONE << list) + ((ptr - sh.arena) / (sh.arena_size >> list));
OPENSSL_assert(bit > 0 && bit < sh.bittable_size);
return TESTBIT(table, bit);
}
static void sh_clearbit(char *ptr, int list, unsigned char *table)
{
size_t bit;
OPENSSL_assert(list >= 0 && list < sh.freelist_size);
OPENSSL_assert(((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0);
bit = (ONE << list) + ((ptr - sh.arena) / (sh.arena_size >> list));
OPENSSL_assert(bit > 0 && bit < sh.bittable_size);
OPENSSL_assert(TESTBIT(table, bit));
CLEARBIT(table, bit);
}
static void sh_setbit(char *ptr, int list, unsigned char *table)
{
size_t bit;
OPENSSL_assert(list >= 0 && list < sh.freelist_size);
OPENSSL_assert(((ptr - sh.arena) & ((sh.arena_size >> list) - 1)) == 0);
bit = (ONE << list) + ((ptr - sh.arena) / (sh.arena_size >> list));
OPENSSL_assert(bit > 0 && bit < sh.bittable_size);
OPENSSL_assert(!TESTBIT(table, bit));
SETBIT(table, bit);
}
static void sh_add_to_list(char **list, char *ptr)
{
SH_LIST *temp;
OPENSSL_assert(WITHIN_FREELIST(list));
OPENSSL_assert(WITHIN_ARENA(ptr));
temp = (SH_LIST *)ptr;
temp->next = *(SH_LIST **)list;
OPENSSL_assert(temp->next == NULL || WITHIN_ARENA(temp->next));
temp->p_next = (SH_LIST **)list;
if (temp->next != NULL) {
OPENSSL_assert((char **)temp->next->p_next == list);
temp->next->p_next = &(temp->next);
}
*list = ptr;
}
static void sh_remove_from_list(char *ptr)
{
SH_LIST *temp, *temp2;
temp = (SH_LIST *)ptr;
if (temp->next != NULL)
temp->next->p_next = temp->p_next;
*temp->p_next = temp->next;
if (temp->next == NULL)
return;
temp2 = temp->next;
OPENSSL_assert(WITHIN_FREELIST(temp2->p_next) || WITHIN_ARENA(temp2->p_next));
}
static int sh_init(size_t size, int minsize)
{
int i, ret;
size_t pgsize;
size_t aligned;
memset(&sh, 0, sizeof sh);
OPENSSL_assert(size > 0);
OPENSSL_assert((size & (size - 1)) == 0);
OPENSSL_assert(minsize > 0);
OPENSSL_assert((minsize & (minsize - 1)) == 0);
if (size <= 0 || (size & (size - 1)) != 0)
goto err;
if (minsize <= 0 || (minsize & (minsize - 1)) != 0)
goto err;
sh.arena_size = size;
sh.minsize = minsize;
sh.bittable_size = (sh.arena_size / sh.minsize) * 2;
sh.freelist_size = -1;
for (i = sh.bittable_size; i; i >>= 1)
sh.freelist_size++;
sh.freelist = OPENSSL_zalloc(sh.freelist_size * sizeof (char *));
OPENSSL_assert(sh.freelist != NULL);
if (sh.freelist == NULL)
goto err;
sh.bittable = OPENSSL_zalloc(sh.bittable_size >> 3);
OPENSSL_assert(sh.bittable != NULL);
if (sh.bittable == NULL)
goto err;
sh.bitmalloc = OPENSSL_zalloc(sh.bittable_size >> 3);
OPENSSL_assert(sh.bitmalloc != NULL);
if (sh.bitmalloc == NULL)
goto err;
#if defined(_SC_PAGE_SIZE) || defined (_SC_PAGESIZE)
{
# if defined(_SC_PAGE_SIZE)
long tmppgsize = sysconf(_SC_PAGE_SIZE);
# else
long tmppgsize = sysconf(_SC_PAGESIZE);
# endif
if (tmppgsize < 1)
pgsize = PAGE_SIZE;
else
pgsize = (size_t)tmppgsize;
}
#else
pgsize = PAGE_SIZE;
#endif
sh.map_size = pgsize + sh.arena_size + pgsize;
if (1) {
#ifdef MAP_ANON
sh.map_result = mmap(NULL, sh.map_size,
PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
} else {
#endif
int fd;
sh.map_result = MAP_FAILED;
if ((fd = open("/dev/zero", O_RDWR)) >= 0) {
sh.map_result = mmap(NULL, sh.map_size,
PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
close(fd);
}
}
OPENSSL_assert(sh.map_result != MAP_FAILED);
if (sh.map_result == MAP_FAILED)
goto err;
sh.arena = (char *)(sh.map_result + pgsize);
sh_setbit(sh.arena, 0, sh.bittable);
sh_add_to_list(&sh.freelist[0], sh.arena);
ret = 1;
if (mprotect(sh.map_result, pgsize, PROT_NONE) < 0)
ret = 2;
aligned = (pgsize + sh.arena_size + (pgsize - 1)) & ~(pgsize - 1);
if (mprotect(sh.map_result + aligned, pgsize, PROT_NONE) < 0)
ret = 2;
if (mlock(sh.arena, sh.arena_size) < 0)
ret = 2;
#ifdef MADV_DONTDUMP
if (madvise(sh.arena, sh.arena_size, MADV_DONTDUMP) < 0)
ret = 2;
#endif
return ret;
err:
sh_done();
return 0;
}
static void sh_done()
{
OPENSSL_free(sh.freelist);
OPENSSL_free(sh.bittable);
OPENSSL_free(sh.bitmalloc);
if (sh.map_result != NULL && sh.map_size)
munmap(sh.map_result, sh.map_size);
memset(&sh, 0, sizeof sh);
}
static int sh_allocated(const char *ptr)
{
return WITHIN_ARENA(ptr) ? 1 : 0;
}
static char *sh_find_my_buddy(char *ptr, int list)
{
size_t bit;
char *chunk = NULL;
bit = (ONE << list) + (ptr - sh.arena) / (sh.arena_size >> list);
bit ^= 1;
if (TESTBIT(sh.bittable, bit) && !TESTBIT(sh.bitmalloc, bit))
chunk = sh.arena + ((bit & ((ONE << list) - 1)) * (sh.arena_size >> list));
return chunk;
}
static char *sh_malloc(size_t size)
{
ossl_ssize_t list, slist;
size_t i;
char *chunk;
list = sh.freelist_size - 1;
for (i = sh.minsize; i < size; i <<= 1)
list--;
if (list < 0)
return NULL;
for (slist = list; slist >= 0; slist--)
if (sh.freelist[slist] != NULL)
break;
if (slist < 0)
return NULL;
while (slist != list) {
char *temp = sh.freelist[slist];
OPENSSL_assert(!sh_testbit(temp, slist, sh.bitmalloc));
sh_clearbit(temp, slist, sh.bittable);
sh_remove_from_list(temp);
OPENSSL_assert(temp != sh.freelist[slist]);
slist++;
OPENSSL_assert(!sh_testbit(temp, slist, sh.bitmalloc));
sh_setbit(temp, slist, sh.bittable);
sh_add_to_list(&sh.freelist[slist], temp);
OPENSSL_assert(sh.freelist[slist] == temp);
temp += sh.arena_size >> slist;
OPENSSL_assert(!sh_testbit(temp, slist, sh.bitmalloc));
sh_setbit(temp, slist, sh.bittable);
sh_add_to_list(&sh.freelist[slist], temp);
OPENSSL_assert(sh.freelist[slist] == temp);
OPENSSL_assert(temp-(sh.arena_size >> slist) == sh_find_my_buddy(temp, slist));
}
chunk = sh.freelist[list];
OPENSSL_assert(sh_testbit(chunk, list, sh.bittable));
sh_setbit(chunk, list, sh.bitmalloc);
sh_remove_from_list(chunk);
OPENSSL_assert(WITHIN_ARENA(chunk));
return chunk;
}
static void sh_free(char *ptr)
{
size_t list;
char *buddy;
if (ptr == NULL)
return;
OPENSSL_assert(WITHIN_ARENA(ptr));
if (!WITHIN_ARENA(ptr))
return;
list = sh_getlist(ptr);
OPENSSL_assert(sh_testbit(ptr, list, sh.bittable));
sh_clearbit(ptr, list, sh.bitmalloc);
sh_add_to_list(&sh.freelist[list], ptr);
while ((buddy = sh_find_my_buddy(ptr, list)) != NULL) {
OPENSSL_assert(ptr == sh_find_my_buddy(buddy, list));
OPENSSL_assert(ptr != NULL);
OPENSSL_assert(!sh_testbit(ptr, list, sh.bitmalloc));
sh_clearbit(ptr, list, sh.bittable);
sh_remove_from_list(ptr);
OPENSSL_assert(!sh_testbit(ptr, list, sh.bitmalloc));
sh_clearbit(buddy, list, sh.bittable);
sh_remove_from_list(buddy);
list--;
if (ptr > buddy)
ptr = buddy;
OPENSSL_assert(!sh_testbit(ptr, list, sh.bitmalloc));
sh_setbit(ptr, list, sh.bittable);
sh_add_to_list(&sh.freelist[list], ptr);
OPENSSL_assert(sh.freelist[list] == ptr);
}
}
static size_t sh_actual_size(char *ptr)
{
int list;
OPENSSL_assert(WITHIN_ARENA(ptr));
if (!WITHIN_ARENA(ptr))
return 0;
list = sh_getlist(ptr);
OPENSSL_assert(sh_testbit(ptr, list, sh.bittable));
return sh.arena_size / (ONE << list);
}
