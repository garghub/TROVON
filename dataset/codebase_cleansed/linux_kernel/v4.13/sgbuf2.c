static bool sg_dwiter_next(struct sg_mapping_iter *miter)
{
if (sg_miter_next(miter)) {
miter->consumed = 0;
return true;
} else
return false;
}
static bool sg_dwiter_is_at_end(struct sg_mapping_iter *miter)
{
return miter->length == miter->consumed && !sg_dwiter_next(miter);
}
static uint32_t sg_dwiter_read_buffer(struct sg_mapping_iter *miter)
{
size_t len, left = 4;
uint32_t data;
void *addr = &data;
do {
len = min(miter->length - miter->consumed, left);
memcpy(addr, miter->addr + miter->consumed, len);
miter->consumed += len;
left -= len;
if (!left)
return data;
addr += len;
} while (sg_dwiter_next(miter));
memset(addr, 0, left);
return data;
}
static inline bool needs_unaligned_copy(const void *ptr)
{
#ifdef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS
return false;
#else
return ((ptr - NULL) & 3) != 0;
#endif
}
static bool sg_dwiter_get_next_block(struct sg_mapping_iter *miter, uint32_t **ptr)
{
size_t len;
if (sg_dwiter_is_at_end(miter))
return true;
len = miter->length - miter->consumed;
if (likely(len >= 4 && !needs_unaligned_copy(
miter->addr + miter->consumed))) {
*ptr = miter->addr + miter->consumed;
miter->consumed += 4;
return true;
}
return false;
}
uint32_t cb710_sg_dwiter_read_next_block(struct sg_mapping_iter *miter)
{
uint32_t *ptr = NULL;
if (likely(sg_dwiter_get_next_block(miter, &ptr)))
return ptr ? *ptr : 0;
return sg_dwiter_read_buffer(miter);
}
static void sg_dwiter_write_slow(struct sg_mapping_iter *miter, uint32_t data)
{
size_t len, left = 4;
void *addr = &data;
do {
len = min(miter->length - miter->consumed, left);
memcpy(miter->addr, addr, len);
miter->consumed += len;
left -= len;
if (!left)
return;
addr += len;
} while (sg_dwiter_next(miter));
}
void cb710_sg_dwiter_write_next_block(struct sg_mapping_iter *miter, uint32_t data)
{
uint32_t *ptr = NULL;
if (likely(sg_dwiter_get_next_block(miter, &ptr))) {
if (ptr)
*ptr = data;
else
return;
} else
sg_dwiter_write_slow(miter, data);
}
