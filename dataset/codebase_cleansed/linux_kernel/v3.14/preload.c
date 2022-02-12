static void try_init_preload(void)
{
if (!__init_state != done)
init_preload();
}
static struct rb_node **__get_lock_node(void *lock, struct rb_node **parent)
{
struct rb_node **node = &locks.rb_node;
struct lock_lookup *l;
*parent = NULL;
while (*node) {
l = rb_entry(*node, struct lock_lookup, node);
*parent = *node;
if (lock < l->orig)
node = &l->node.rb_left;
else if (lock > l->orig)
node = &l->node.rb_right;
else
return node;
}
return node;
}
static inline bool is_static_lock(struct lock_lookup *lock)
{
return lock >= __locks && lock < __locks + ARRAY_SIZE(__locks);
}
static struct lock_lookup *alloc_lock(void)
{
if (__init_state != done) {
int idx = __locks_nr++;
if (idx >= ARRAY_SIZE(__locks)) {
fprintf(stderr,
"LOCKDEP error: insufficient LIBLOCKDEP_STATIC_ENTRIES\n");
exit(EX_UNAVAILABLE);
}
return __locks + idx;
}
return malloc(sizeof(struct lock_lookup));
}
static inline void free_lock(struct lock_lookup *lock)
{
if (likely(!is_static_lock(lock)))
free(lock);
}
static struct lock_lookup *__get_lock(void *lock)
{
struct rb_node **node, *parent;
struct lock_lookup *l;
ll_pthread_rwlock_rdlock(&locks_rwlock);
node = __get_lock_node(lock, &parent);
ll_pthread_rwlock_unlock(&locks_rwlock);
if (*node) {
return rb_entry(*node, struct lock_lookup, node);
}
l = alloc_lock();
if (l == NULL)
return NULL;
l->orig = lock;
sprintf(l->name, "%p", lock);
lockdep_init_map(&l->dep_map, l->name, &l->key, 0);
ll_pthread_rwlock_wrlock(&locks_rwlock);
node = __get_lock_node(lock, &parent);
rb_link_node(&l->node, parent, node);
rb_insert_color(&l->node, &locks);
ll_pthread_rwlock_unlock(&locks_rwlock);
return l;
}
static void __del_lock(struct lock_lookup *lock)
{
ll_pthread_rwlock_wrlock(&locks_rwlock);
rb_erase(&lock->node, &locks);
ll_pthread_rwlock_unlock(&locks_rwlock);
free_lock(lock);
}
int pthread_mutex_init(pthread_mutex_t *mutex,
const pthread_mutexattr_t *attr)
{
int r;
try_init_preload();
r = ll_pthread_mutex_init(mutex, attr);
if (r == 0)
__get_lock(mutex);
return r;
}
int pthread_mutex_lock(pthread_mutex_t *mutex)
{
int r;
try_init_preload();
lock_acquire(&__get_lock(mutex)->dep_map, 0, 0, 0, 2, NULL,
(unsigned long)_RET_IP_);
r = ll_pthread_mutex_lock(mutex);
if (r)
lock_release(&__get_lock(mutex)->dep_map, 0, (unsigned long)_RET_IP_);
return r;
}
int pthread_mutex_trylock(pthread_mutex_t *mutex)
{
int r;
try_init_preload();
lock_acquire(&__get_lock(mutex)->dep_map, 0, 1, 0, 2, NULL, (unsigned long)_RET_IP_);
r = ll_pthread_mutex_trylock(mutex);
if (r)
lock_release(&__get_lock(mutex)->dep_map, 0, (unsigned long)_RET_IP_);
return r;
}
int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
int r;
try_init_preload();
lock_release(&__get_lock(mutex)->dep_map, 0, (unsigned long)_RET_IP_);
r = ll_pthread_mutex_unlock(mutex);
if (r)
lock_acquire(&__get_lock(mutex)->dep_map, 0, 0, 0, 2, NULL, (unsigned long)_RET_IP_);
return r;
}
int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
try_init_preload();
debug_check_no_locks_freed(mutex, mutex + sizeof(*mutex));
__del_lock(__get_lock(mutex));
return ll_pthread_mutex_destroy(mutex);
}
int pthread_rwlock_init(pthread_rwlock_t *rwlock,
const pthread_rwlockattr_t *attr)
{
int r;
try_init_preload();
r = ll_pthread_rwlock_init(rwlock, attr);
if (r == 0)
__get_lock(rwlock);
return r;
}
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock)
{
try_init_preload();
debug_check_no_locks_freed(rwlock, rwlock + sizeof(*rwlock));
__del_lock(__get_lock(rwlock));
return ll_pthread_rwlock_destroy(rwlock);
}
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock)
{
int r;
init_preload();
lock_acquire(&__get_lock(rwlock)->dep_map, 0, 0, 2, 2, NULL, (unsigned long)_RET_IP_);
r = ll_pthread_rwlock_rdlock(rwlock);
if (r)
lock_release(&__get_lock(rwlock)->dep_map, 0, (unsigned long)_RET_IP_);
return r;
}
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock)
{
int r;
init_preload();
lock_acquire(&__get_lock(rwlock)->dep_map, 0, 1, 2, 2, NULL, (unsigned long)_RET_IP_);
r = ll_pthread_rwlock_tryrdlock(rwlock);
if (r)
lock_release(&__get_lock(rwlock)->dep_map, 0, (unsigned long)_RET_IP_);
return r;
}
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock)
{
int r;
init_preload();
lock_acquire(&__get_lock(rwlock)->dep_map, 0, 1, 0, 2, NULL, (unsigned long)_RET_IP_);
r = ll_pthread_rwlock_trywrlock(rwlock);
if (r)
lock_release(&__get_lock(rwlock)->dep_map, 0, (unsigned long)_RET_IP_);
return r;
}
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock)
{
int r;
init_preload();
lock_acquire(&__get_lock(rwlock)->dep_map, 0, 0, 0, 2, NULL, (unsigned long)_RET_IP_);
r = ll_pthread_rwlock_wrlock(rwlock);
if (r)
lock_release(&__get_lock(rwlock)->dep_map, 0, (unsigned long)_RET_IP_);
return r;
}
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock)
{
int r;
init_preload();
lock_release(&__get_lock(rwlock)->dep_map, 0, (unsigned long)_RET_IP_);
r = ll_pthread_rwlock_unlock(rwlock);
if (r)
lock_acquire(&__get_lock(rwlock)->dep_map, 0, 0, 0, 2, NULL, (unsigned long)_RET_IP_);
return r;
}
static void init_preload(void)
{
if (__init_state == done)
return;
#ifndef __GLIBC__
__init_state = prepare;
ll_pthread_mutex_init = dlsym(RTLD_NEXT, "pthread_mutex_init");
ll_pthread_mutex_lock = dlsym(RTLD_NEXT, "pthread_mutex_lock");
ll_pthread_mutex_trylock = dlsym(RTLD_NEXT, "pthread_mutex_trylock");
ll_pthread_mutex_unlock = dlsym(RTLD_NEXT, "pthread_mutex_unlock");
ll_pthread_mutex_destroy = dlsym(RTLD_NEXT, "pthread_mutex_destroy");
ll_pthread_rwlock_init = dlsym(RTLD_NEXT, "pthread_rwlock_init");
ll_pthread_rwlock_destroy = dlsym(RTLD_NEXT, "pthread_rwlock_destroy");
ll_pthread_rwlock_rdlock = dlsym(RTLD_NEXT, "pthread_rwlock_rdlock");
ll_pthread_rwlock_tryrdlock = dlsym(RTLD_NEXT, "pthread_rwlock_tryrdlock");
ll_pthread_rwlock_wrlock = dlsym(RTLD_NEXT, "pthread_rwlock_wrlock");
ll_pthread_rwlock_trywrlock = dlsym(RTLD_NEXT, "pthread_rwlock_trywrlock");
ll_pthread_rwlock_unlock = dlsym(RTLD_NEXT, "pthread_rwlock_unlock");
#endif
printf("%p\n", ll_pthread_mutex_trylock);fflush(stdout);
lockdep_init();
__init_state = done;
}
