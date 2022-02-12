int badblocks_check(struct badblocks *bb, sector_t s, int sectors,
sector_t *first_bad, int *bad_sectors)
{
int hi;
int lo;
u64 *p = bb->page;
int rv;
sector_t target = s + sectors;
unsigned seq;
if (bb->shift > 0) {
s >>= bb->shift;
target += (1<<bb->shift) - 1;
target >>= bb->shift;
sectors = target - s;
}
retry:
seq = read_seqbegin(&bb->lock);
lo = 0;
rv = 0;
hi = bb->count;
while (hi - lo > 1) {
int mid = (lo + hi) / 2;
sector_t a = BB_OFFSET(p[mid]);
if (a < target)
lo = mid;
else
hi = mid;
}
if (hi > lo) {
while (lo >= 0 &&
BB_OFFSET(p[lo]) + BB_LEN(p[lo]) > s) {
if (BB_OFFSET(p[lo]) < target) {
if (rv != -1 && BB_ACK(p[lo]))
rv = 1;
else
rv = -1;
*first_bad = BB_OFFSET(p[lo]);
*bad_sectors = BB_LEN(p[lo]);
}
lo--;
}
}
if (read_seqretry(&bb->lock, seq))
goto retry;
return rv;
}
int badblocks_set(struct badblocks *bb, sector_t s, int sectors,
int acknowledged)
{
u64 *p;
int lo, hi;
int rv = 0;
unsigned long flags;
if (bb->shift < 0)
return 0;
if (bb->shift) {
sector_t next = s + sectors;
s >>= bb->shift;
next += (1<<bb->shift) - 1;
next >>= bb->shift;
sectors = next - s;
}
write_seqlock_irqsave(&bb->lock, flags);
p = bb->page;
lo = 0;
hi = bb->count;
while (hi - lo > 1) {
int mid = (lo + hi) / 2;
sector_t a = BB_OFFSET(p[mid]);
if (a <= s)
lo = mid;
else
hi = mid;
}
if (hi > lo && BB_OFFSET(p[lo]) > s)
hi = lo;
if (hi > lo) {
sector_t a = BB_OFFSET(p[lo]);
sector_t e = a + BB_LEN(p[lo]);
int ack = BB_ACK(p[lo]);
if (e >= s) {
if (s == a && s + sectors >= e)
ack = acknowledged;
else
ack = ack && acknowledged;
if (e < s + sectors)
e = s + sectors;
if (e - a <= BB_MAX_LEN) {
p[lo] = BB_MAKE(a, e-a, ack);
s = e;
} else {
if (BB_LEN(p[lo]) != BB_MAX_LEN)
p[lo] = BB_MAKE(a, BB_MAX_LEN, ack);
s = a + BB_MAX_LEN;
}
sectors = e - s;
}
}
if (sectors && hi < bb->count) {
sector_t a = BB_OFFSET(p[hi]);
sector_t e = a + BB_LEN(p[hi]);
int ack = BB_ACK(p[hi]);
if (a <= s + sectors) {
if (e <= s + sectors) {
e = s + sectors;
ack = acknowledged;
} else
ack = ack && acknowledged;
a = s;
if (e - a <= BB_MAX_LEN) {
p[hi] = BB_MAKE(a, e-a, ack);
s = e;
} else {
p[hi] = BB_MAKE(a, BB_MAX_LEN, ack);
s = a + BB_MAX_LEN;
}
sectors = e - s;
lo = hi;
hi++;
}
}
if (sectors == 0 && hi < bb->count) {
sector_t a = BB_OFFSET(p[hi]);
int lolen = BB_LEN(p[lo]);
int hilen = BB_LEN(p[hi]);
int newlen = lolen + hilen - (s - a);
if (s >= a && newlen < BB_MAX_LEN) {
int ack = BB_ACK(p[lo]) && BB_ACK(p[hi]);
p[lo] = BB_MAKE(BB_OFFSET(p[lo]), newlen, ack);
memmove(p + hi, p + hi + 1,
(bb->count - hi - 1) * 8);
bb->count--;
}
}
while (sectors) {
if (bb->count >= MAX_BADBLOCKS) {
rv = 1;
break;
} else {
int this_sectors = sectors;
memmove(p + hi + 1, p + hi,
(bb->count - hi) * 8);
bb->count++;
if (this_sectors > BB_MAX_LEN)
this_sectors = BB_MAX_LEN;
p[hi] = BB_MAKE(s, this_sectors, acknowledged);
sectors -= this_sectors;
s += this_sectors;
}
}
bb->changed = 1;
if (!acknowledged)
bb->unacked_exist = 1;
write_sequnlock_irqrestore(&bb->lock, flags);
return rv;
}
int badblocks_clear(struct badblocks *bb, sector_t s, int sectors)
{
u64 *p;
int lo, hi;
sector_t target = s + sectors;
int rv = 0;
if (bb->shift > 0) {
s += (1<<bb->shift) - 1;
s >>= bb->shift;
target >>= bb->shift;
sectors = target - s;
}
write_seqlock_irq(&bb->lock);
p = bb->page;
lo = 0;
hi = bb->count;
while (hi - lo > 1) {
int mid = (lo + hi) / 2;
sector_t a = BB_OFFSET(p[mid]);
if (a < target)
lo = mid;
else
hi = mid;
}
if (hi > lo) {
if (BB_OFFSET(p[lo]) + BB_LEN(p[lo]) > target) {
int ack = BB_ACK(p[lo]);
sector_t a = BB_OFFSET(p[lo]);
sector_t end = a + BB_LEN(p[lo]);
if (a < s) {
if (bb->count >= MAX_BADBLOCKS) {
rv = -ENOSPC;
goto out;
}
memmove(p+lo+1, p+lo, (bb->count - lo) * 8);
bb->count++;
p[lo] = BB_MAKE(a, s-a, ack);
lo++;
}
p[lo] = BB_MAKE(target, end - target, ack);
hi = lo;
lo--;
}
while (lo >= 0 &&
BB_OFFSET(p[lo]) + BB_LEN(p[lo]) > s) {
if (BB_OFFSET(p[lo]) < s) {
int ack = BB_ACK(p[lo]);
sector_t start = BB_OFFSET(p[lo]);
p[lo] = BB_MAKE(start, s - start, ack);
break;
}
lo--;
}
if (hi - lo > 1) {
memmove(p+lo+1, p+hi, (bb->count - hi) * 8);
bb->count -= (hi - lo - 1);
}
}
bb->changed = 1;
out:
write_sequnlock_irq(&bb->lock);
return rv;
}
void ack_all_badblocks(struct badblocks *bb)
{
if (bb->page == NULL || bb->changed)
return;
write_seqlock_irq(&bb->lock);
if (bb->changed == 0 && bb->unacked_exist) {
u64 *p = bb->page;
int i;
for (i = 0; i < bb->count ; i++) {
if (!BB_ACK(p[i])) {
sector_t start = BB_OFFSET(p[i]);
int len = BB_LEN(p[i]);
p[i] = BB_MAKE(start, len, 1);
}
}
bb->unacked_exist = 0;
}
write_sequnlock_irq(&bb->lock);
}
ssize_t badblocks_show(struct badblocks *bb, char *page, int unack)
{
size_t len;
int i;
u64 *p = bb->page;
unsigned seq;
if (bb->shift < 0)
return 0;
retry:
seq = read_seqbegin(&bb->lock);
len = 0;
i = 0;
while (len < PAGE_SIZE && i < bb->count) {
sector_t s = BB_OFFSET(p[i]);
unsigned int length = BB_LEN(p[i]);
int ack = BB_ACK(p[i]);
i++;
if (unack && ack)
continue;
len += snprintf(page+len, PAGE_SIZE-len, "%llu %u\n",
(unsigned long long)s << bb->shift,
length << bb->shift);
}
if (unack && len == 0)
bb->unacked_exist = 0;
if (read_seqretry(&bb->lock, seq))
goto retry;
return len;
}
ssize_t badblocks_store(struct badblocks *bb, const char *page, size_t len,
int unack)
{
unsigned long long sector;
int length;
char newline;
switch (sscanf(page, "%llu %d%c", &sector, &length, &newline)) {
case 3:
if (newline != '\n')
return -EINVAL;
case 2:
if (length <= 0)
return -EINVAL;
break;
default:
return -EINVAL;
}
if (badblocks_set(bb, sector, length, !unack))
return -ENOSPC;
else
return len;
}
static int __badblocks_init(struct device *dev, struct badblocks *bb,
int enable)
{
bb->dev = dev;
bb->count = 0;
if (enable)
bb->shift = 0;
else
bb->shift = -1;
if (dev)
bb->page = devm_kzalloc(dev, PAGE_SIZE, GFP_KERNEL);
else
bb->page = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!bb->page) {
bb->shift = -1;
return -ENOMEM;
}
seqlock_init(&bb->lock);
return 0;
}
int badblocks_init(struct badblocks *bb, int enable)
{
return __badblocks_init(NULL, bb, enable);
}
int devm_init_badblocks(struct device *dev, struct badblocks *bb)
{
if (!bb)
return -EINVAL;
return __badblocks_init(dev, bb, 1);
}
void badblocks_exit(struct badblocks *bb)
{
if (!bb)
return;
if (bb->dev)
devm_kfree(bb->dev, bb->page);
else
kfree(bb->page);
bb->page = NULL;
}
