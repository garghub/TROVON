static void deactivate_swap_slots_cache(void)
{
mutex_lock(&swap_slots_cache_mutex);
swap_slot_cache_active = false;
__drain_swap_slots_cache(SLOTS_CACHE|SLOTS_CACHE_RET);
mutex_unlock(&swap_slots_cache_mutex);
}
static void reactivate_swap_slots_cache(void)
{
mutex_lock(&swap_slots_cache_mutex);
swap_slot_cache_active = true;
mutex_unlock(&swap_slots_cache_mutex);
}
void disable_swap_slots_cache_lock(void)
{
mutex_lock(&swap_slots_cache_enable_mutex);
swap_slot_cache_enabled = false;
if (swap_slot_cache_initialized) {
get_online_cpus();
__drain_swap_slots_cache(SLOTS_CACHE|SLOTS_CACHE_RET);
put_online_cpus();
}
}
static void __reenable_swap_slots_cache(void)
{
swap_slot_cache_enabled = has_usable_swap();
}
void reenable_swap_slots_cache_unlock(void)
{
__reenable_swap_slots_cache();
mutex_unlock(&swap_slots_cache_enable_mutex);
}
static bool check_cache_active(void)
{
long pages;
if (!swap_slot_cache_enabled || !swap_slot_cache_initialized)
return false;
pages = get_nr_swap_pages();
if (!swap_slot_cache_active) {
if (pages > num_online_cpus() *
THRESHOLD_ACTIVATE_SWAP_SLOTS_CACHE)
reactivate_swap_slots_cache();
goto out;
}
if (pages < num_online_cpus() * THRESHOLD_DEACTIVATE_SWAP_SLOTS_CACHE)
deactivate_swap_slots_cache();
out:
return swap_slot_cache_active;
}
static int alloc_swap_slot_cache(unsigned int cpu)
{
struct swap_slots_cache *cache;
swp_entry_t *slots, *slots_ret;
slots = vzalloc(sizeof(swp_entry_t) * SWAP_SLOTS_CACHE_SIZE);
if (!slots)
return -ENOMEM;
slots_ret = vzalloc(sizeof(swp_entry_t) * SWAP_SLOTS_CACHE_SIZE);
if (!slots_ret) {
vfree(slots);
return -ENOMEM;
}
mutex_lock(&swap_slots_cache_mutex);
cache = &per_cpu(swp_slots, cpu);
if (cache->slots || cache->slots_ret)
goto out;
if (!cache->lock_initialized) {
mutex_init(&cache->alloc_lock);
spin_lock_init(&cache->free_lock);
cache->lock_initialized = true;
}
cache->nr = 0;
cache->cur = 0;
cache->n_ret = 0;
cache->slots = slots;
slots = NULL;
cache->slots_ret = slots_ret;
slots_ret = NULL;
out:
mutex_unlock(&swap_slots_cache_mutex);
if (slots)
vfree(slots);
if (slots_ret)
vfree(slots_ret);
return 0;
}
static void drain_slots_cache_cpu(unsigned int cpu, unsigned int type,
bool free_slots)
{
struct swap_slots_cache *cache;
swp_entry_t *slots = NULL;
cache = &per_cpu(swp_slots, cpu);
if ((type & SLOTS_CACHE) && cache->slots) {
mutex_lock(&cache->alloc_lock);
swapcache_free_entries(cache->slots + cache->cur, cache->nr);
cache->cur = 0;
cache->nr = 0;
if (free_slots && cache->slots) {
vfree(cache->slots);
cache->slots = NULL;
}
mutex_unlock(&cache->alloc_lock);
}
if ((type & SLOTS_CACHE_RET) && cache->slots_ret) {
spin_lock_irq(&cache->free_lock);
swapcache_free_entries(cache->slots_ret, cache->n_ret);
cache->n_ret = 0;
if (free_slots && cache->slots_ret) {
slots = cache->slots_ret;
cache->slots_ret = NULL;
}
spin_unlock_irq(&cache->free_lock);
if (slots)
vfree(slots);
}
}
static void __drain_swap_slots_cache(unsigned int type)
{
unsigned int cpu;
for_each_online_cpu(cpu)
drain_slots_cache_cpu(cpu, type, false);
}
static int free_slot_cache(unsigned int cpu)
{
mutex_lock(&swap_slots_cache_mutex);
drain_slots_cache_cpu(cpu, SLOTS_CACHE | SLOTS_CACHE_RET, true);
mutex_unlock(&swap_slots_cache_mutex);
return 0;
}
int enable_swap_slots_cache(void)
{
int ret = 0;
mutex_lock(&swap_slots_cache_enable_mutex);
if (swap_slot_cache_initialized) {
__reenable_swap_slots_cache();
goto out_unlock;
}
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "swap_slots_cache",
alloc_swap_slot_cache, free_slot_cache);
if (ret < 0)
goto out_unlock;
swap_slot_cache_initialized = true;
__reenable_swap_slots_cache();
out_unlock:
mutex_unlock(&swap_slots_cache_enable_mutex);
return 0;
}
static int refill_swap_slots_cache(struct swap_slots_cache *cache)
{
if (!use_swap_slot_cache || cache->nr)
return 0;
cache->cur = 0;
if (swap_slot_cache_active)
cache->nr = get_swap_pages(SWAP_SLOTS_CACHE_SIZE, cache->slots);
return cache->nr;
}
int free_swap_slot(swp_entry_t entry)
{
struct swap_slots_cache *cache;
cache = &get_cpu_var(swp_slots);
if (use_swap_slot_cache && cache->slots_ret) {
spin_lock_irq(&cache->free_lock);
if (!use_swap_slot_cache) {
spin_unlock_irq(&cache->free_lock);
goto direct_free;
}
if (cache->n_ret >= SWAP_SLOTS_CACHE_SIZE) {
swapcache_free_entries(cache->slots_ret, cache->n_ret);
cache->n_ret = 0;
}
cache->slots_ret[cache->n_ret++] = entry;
spin_unlock_irq(&cache->free_lock);
} else {
direct_free:
swapcache_free_entries(&entry, 1);
}
put_cpu_var(swp_slots);
return 0;
}
swp_entry_t get_swap_page(void)
{
swp_entry_t entry, *pentry;
struct swap_slots_cache *cache;
cache = raw_cpu_ptr(&swp_slots);
entry.val = 0;
if (check_cache_active()) {
mutex_lock(&cache->alloc_lock);
if (cache->slots) {
repeat:
if (cache->nr) {
pentry = &cache->slots[cache->cur++];
entry = *pentry;
pentry->val = 0;
cache->nr--;
} else {
if (refill_swap_slots_cache(cache))
goto repeat;
}
}
mutex_unlock(&cache->alloc_lock);
if (entry.val)
return entry;
}
get_swap_pages(1, &entry);
return entry;
}
