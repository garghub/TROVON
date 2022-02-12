int uwb_est_create(void)
{
int result;
uwb_est_size = 2;
uwb_est_used = 0;
uwb_est = kcalloc(uwb_est_size, sizeof(uwb_est[0]), GFP_KERNEL);
if (uwb_est == NULL)
return -ENOMEM;
result = uwb_est_register(UWB_RC_CET_GENERAL, 0, 0xffff, 0xffff,
uwb_est_00_00xx, ARRAY_SIZE(uwb_est_00_00xx));
if (result < 0)
goto out;
result = uwb_est_register(UWB_RC_CET_EX_TYPE_1, 0, 0xffff, 0xffff,
uwb_est_01_00xx, ARRAY_SIZE(uwb_est_01_00xx));
out:
return result;
}
void uwb_est_destroy(void)
{
kfree(uwb_est);
uwb_est = NULL;
uwb_est_size = uwb_est_used = 0;
}
static
int uwb_est_grow(void)
{
size_t actual_size = uwb_est_size * sizeof(uwb_est[0]);
void *new = kmalloc(2 * actual_size, GFP_ATOMIC);
if (new == NULL)
return -ENOMEM;
memcpy(new, uwb_est, actual_size);
memset(new + actual_size, 0, actual_size);
kfree(uwb_est);
uwb_est = new;
uwb_est_size *= 2;
return 0;
}
int uwb_est_register(u8 type, u8 event_high, u16 vendor, u16 product,
const struct uwb_est_entry *entry, size_t entries)
{
unsigned long flags;
unsigned itr;
u16 type_event_high;
int result = 0;
write_lock_irqsave(&uwb_est_lock, flags);
if (uwb_est_used == uwb_est_size) {
result = uwb_est_grow();
if (result < 0)
goto out;
}
type_event_high = type << 8 | event_high;
for (itr = 0; itr < uwb_est_used; itr++)
if (uwb_est[itr].type_event_high < type
&& uwb_est[itr].vendor < vendor
&& uwb_est[itr].product < product)
break;
if (itr < uwb_est_used)
memmove(&uwb_est[itr+1], &uwb_est[itr], uwb_est_used - itr);
uwb_est[itr].type_event_high = type << 8 | event_high;
uwb_est[itr].vendor = vendor;
uwb_est[itr].product = product;
uwb_est[itr].entry = entry;
uwb_est[itr].entries = entries;
uwb_est_used++;
out:
write_unlock_irqrestore(&uwb_est_lock, flags);
return result;
}
int uwb_est_unregister(u8 type, u8 event_high, u16 vendor, u16 product,
const struct uwb_est_entry *entry, size_t entries)
{
unsigned long flags;
unsigned itr;
struct uwb_est est_cmp = {
.type_event_high = type << 8 | event_high,
.vendor = vendor,
.product = product,
.entry = entry,
.entries = entries
};
write_lock_irqsave(&uwb_est_lock, flags);
for (itr = 0; itr < uwb_est_used; itr++)
if (!memcmp(&uwb_est[itr], &est_cmp, sizeof(est_cmp)))
goto found;
write_unlock_irqrestore(&uwb_est_lock, flags);
return -ENOENT;
found:
if (itr < uwb_est_used - 1)
memmove(&uwb_est[itr], &uwb_est[itr+1], uwb_est_used - itr - 1);
uwb_est_used--;
write_unlock_irqrestore(&uwb_est_lock, flags);
return 0;
}
static
ssize_t uwb_est_get_size(struct uwb_rc *uwb_rc, struct uwb_est *est,
u8 event_low, const struct uwb_rceb *rceb,
size_t rceb_size)
{
unsigned offset;
ssize_t size;
struct device *dev = &uwb_rc->uwb_dev.dev;
const struct uwb_est_entry *entry;
size = -ENOENT;
if (event_low >= est->entries) {
dev_err(dev, "EST %p 0x%04x/%04x/%04x[%u]: event %u out of range\n",
est, est->type_event_high, est->vendor, est->product,
est->entries, event_low);
goto out;
}
size = -ENOENT;
entry = &est->entry[event_low];
if (entry->size == 0 && entry->offset == 0) {
dev_err(dev, "EST %p 0x%04x/%04x/%04x[%u]: event %u unknown\n",
est, est->type_event_high, est->vendor, est->product,
est->entries, event_low);
goto out;
}
offset = entry->offset;
if (offset == 0)
size = entry->size;
else {
const void *ptr = rceb;
size_t type_size = 0;
offset--;
size = -ENOSPC;
switch (entry->type) {
case UWB_EST_16: type_size = sizeof(__le16); break;
case UWB_EST_8: type_size = sizeof(u8); break;
default: BUG();
}
if (offset + type_size > rceb_size) {
dev_err(dev, "EST %p 0x%04x/%04x/%04x[%u]: "
"not enough data to read extra size\n",
est, est->type_event_high, est->vendor,
est->product, est->entries);
goto out;
}
size = entry->size;
ptr += offset;
switch (entry->type) {
case UWB_EST_16: size += le16_to_cpu(*(__le16 *)ptr); break;
case UWB_EST_8: size += *(u8 *)ptr; break;
default: BUG();
}
}
out:
return size;
}
ssize_t uwb_est_find_size(struct uwb_rc *rc, const struct uwb_rceb *rceb,
size_t rceb_size)
{
ssize_t size;
struct device *dev = &rc->uwb_dev.dev;
unsigned long flags;
unsigned itr;
u16 type_event_high, event;
read_lock_irqsave(&uwb_est_lock, flags);
size = -ENOSPC;
if (rceb_size < sizeof(*rceb))
goto out;
event = le16_to_cpu(rceb->wEvent);
type_event_high = rceb->bEventType << 8 | (event & 0xff00) >> 8;
for (itr = 0; itr < uwb_est_used; itr++) {
if (uwb_est[itr].type_event_high != type_event_high)
continue;
size = uwb_est_get_size(rc, &uwb_est[itr],
event & 0x00ff, rceb, rceb_size);
if (size != -ENOENT)
goto out;
}
dev_dbg(dev,
"event 0x%02x/%04x/%02x: no handlers available; RCEB %4ph\n",
(unsigned) rceb->bEventType,
(unsigned) le16_to_cpu(rceb->wEvent),
(unsigned) rceb->bEventContext,
rceb);
size = -ENOENT;
out:
read_unlock_irqrestore(&uwb_est_lock, flags);
return size;
}
