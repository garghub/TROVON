static void free_slots(unsigned long pos, uint16_t w, uint16_t h,
unsigned long *map, uint16_t stride)
{
int i;
for (i = 0; i < h; i++, pos += stride)
bitmap_clear(map, pos, w);
}
static int r2l_b2t_1d(uint16_t w, unsigned long *pos, unsigned long *map,
size_t num_bits)
{
unsigned long search_count = 0;
unsigned long bit;
bool area_found = false;
*pos = num_bits - w;
while (search_count < num_bits) {
bit = find_next_bit(map, num_bits, *pos);
if (bit - *pos >= w) {
bitmap_set(map, *pos, w);
area_found = true;
break;
}
search_count = num_bits - bit + w;
*pos = bit - w;
}
return (area_found) ? 0 : -ENOMEM;
}
static int l2r_t2b(uint16_t w, uint16_t h, uint16_t a, int16_t offset,
unsigned long *pos, unsigned long slot_bytes,
unsigned long *map, size_t num_bits, size_t slot_stride)
{
int i;
unsigned long index;
bool area_free;
unsigned long slots_per_band = PAGE_SIZE / slot_bytes;
unsigned long bit_offset = (offset > 0) ? offset / slot_bytes : 0;
unsigned long curr_bit = bit_offset;
a = (offset > 0) ? 0 : a - 1;
while (curr_bit < num_bits) {
*pos = bitmap_find_next_zero_area(map, num_bits, curr_bit, w,
a);
if (bit_offset > 0 && (*pos % slots_per_band != bit_offset)) {
curr_bit = ALIGN(*pos, slots_per_band) + bit_offset;
continue;
}
if ((*pos % slot_stride) + w > slot_stride) {
curr_bit = ALIGN(*pos, slot_stride) + bit_offset;
continue;
}
if ((*pos + slot_stride * h) > num_bits)
break;
bitmap_clear(mask, 0, slot_stride);
bitmap_set(mask, (*pos % BITS_PER_LONG), w);
area_free = true;
for (i = 1; i < h; i++) {
index = *pos / BITS_PER_LONG + i * 8;
if (bitmap_intersects(&map[index], mask,
(*pos % BITS_PER_LONG) + w)) {
area_free = false;
break;
}
}
if (area_free)
break;
if (bit_offset > 0)
curr_bit = ALIGN(*pos, slots_per_band) + bit_offset;
else
curr_bit = *pos + a + 1;
}
if (area_free) {
for (i = 0, index = *pos; i < h; i++, index += slot_stride)
bitmap_set(map, index, w);
}
return (area_free) ? 0 : -ENOMEM;
}
static s32 sita_reserve_1d(struct tcm *tcm, u32 num_slots,
struct tcm_area *area)
{
unsigned long pos;
int ret;
spin_lock(&(tcm->lock));
ret = r2l_b2t_1d(num_slots, &pos, tcm->bitmap, tcm->map_size);
if (!ret) {
area->p0.x = pos % tcm->width;
area->p0.y = pos / tcm->width;
area->p1.x = (pos + num_slots - 1) % tcm->width;
area->p1.y = (pos + num_slots - 1) / tcm->width;
}
spin_unlock(&(tcm->lock));
return ret;
}
static s32 sita_reserve_2d(struct tcm *tcm, u16 h, u16 w, u16 align,
int16_t offset, uint16_t slot_bytes,
struct tcm_area *area)
{
unsigned long pos;
int ret;
spin_lock(&(tcm->lock));
ret = l2r_t2b(w, h, align, offset, &pos, slot_bytes, tcm->bitmap,
tcm->map_size, tcm->width);
if (!ret) {
area->p0.x = pos % tcm->width;
area->p0.y = pos / tcm->width;
area->p1.x = area->p0.x + w - 1;
area->p1.y = area->p0.y + h - 1;
}
spin_unlock(&(tcm->lock));
return ret;
}
static void sita_deinit(struct tcm *tcm)
{
kfree(tcm);
}
static s32 sita_free(struct tcm *tcm, struct tcm_area *area)
{
unsigned long pos;
uint16_t w, h;
pos = area->p0.x + area->p0.y * tcm->width;
if (area->is2d) {
w = area->p1.x - area->p0.x + 1;
h = area->p1.y - area->p0.y + 1;
} else {
w = area->p1.x + area->p1.y * tcm->width - pos + 1;
h = 1;
}
spin_lock(&(tcm->lock));
free_slots(pos, w, h, tcm->bitmap, tcm->width);
spin_unlock(&(tcm->lock));
return 0;
}
struct tcm *sita_init(u16 width, u16 height)
{
struct tcm *tcm;
size_t map_size = BITS_TO_LONGS(width*height) * sizeof(unsigned long);
if (width == 0 || height == 0)
return NULL;
tcm = kzalloc(sizeof(*tcm) + map_size, GFP_KERNEL);
if (!tcm)
goto error;
tcm->height = height;
tcm->width = width;
tcm->reserve_2d = sita_reserve_2d;
tcm->reserve_1d = sita_reserve_1d;
tcm->free = sita_free;
tcm->deinit = sita_deinit;
spin_lock_init(&tcm->lock);
tcm->bitmap = (unsigned long *)(tcm + 1);
bitmap_clear(tcm->bitmap, 0, width*height);
tcm->map_size = width*height;
return tcm;
error:
kfree(tcm);
return NULL;
}
