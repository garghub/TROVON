void page_counter_cancel(struct page_counter *counter, unsigned long nr_pages)
{
long new;
new = atomic_long_sub_return(nr_pages, &counter->count);
WARN_ON_ONCE(new < 0);
}
void page_counter_charge(struct page_counter *counter, unsigned long nr_pages)
{
struct page_counter *c;
for (c = counter; c; c = c->parent) {
long new;
new = atomic_long_add_return(nr_pages, &c->count);
if (new > c->watermark)
c->watermark = new;
}
}
bool page_counter_try_charge(struct page_counter *counter,
unsigned long nr_pages,
struct page_counter **fail)
{
struct page_counter *c;
for (c = counter; c; c = c->parent) {
long new;
new = atomic_long_add_return(nr_pages, &c->count);
if (new > c->limit) {
atomic_long_sub(nr_pages, &c->count);
c->failcnt++;
*fail = c;
goto failed;
}
if (new > c->watermark)
c->watermark = new;
}
return true;
failed:
for (c = counter; c != *fail; c = c->parent)
page_counter_cancel(c, nr_pages);
return false;
}
void page_counter_uncharge(struct page_counter *counter, unsigned long nr_pages)
{
struct page_counter *c;
for (c = counter; c; c = c->parent)
page_counter_cancel(c, nr_pages);
}
int page_counter_limit(struct page_counter *counter, unsigned long limit)
{
for (;;) {
unsigned long old;
long count;
count = atomic_long_read(&counter->count);
if (count > limit)
return -EBUSY;
old = xchg(&counter->limit, limit);
if (atomic_long_read(&counter->count) <= count)
return 0;
counter->limit = old;
cond_resched();
}
}
int page_counter_memparse(const char *buf, const char *max,
unsigned long *nr_pages)
{
char *end;
u64 bytes;
if (!strcmp(buf, max)) {
*nr_pages = PAGE_COUNTER_MAX;
return 0;
}
bytes = memparse(buf, &end);
if (*end != '\0')
return -EINVAL;
*nr_pages = min(bytes / PAGE_SIZE, (u64)PAGE_COUNTER_MAX);
return 0;
}
