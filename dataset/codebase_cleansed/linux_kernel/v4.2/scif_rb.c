void scif_rb_init(struct scif_rb *rb, u32 *read_ptr, u32 *write_ptr,
void *rb_base, u8 size)
{
rb->rb_base = rb_base;
rb->size = (1 << size);
rb->read_ptr = read_ptr;
rb->write_ptr = write_ptr;
rb->current_read_offset = *read_ptr;
rb->current_write_offset = *write_ptr;
}
static void memcpy_torb(struct scif_rb *rb, void *header,
void *msg, u32 size)
{
u32 size1, size2;
if (header + size >= rb->rb_base + rb->size) {
size1 = (u32)(rb->rb_base + rb->size - header);
size2 = size - size1;
memcpy_toio((void __iomem __force *)header, msg, size1);
memcpy_toio((void __iomem __force *)rb->rb_base,
msg + size1, size2);
} else {
memcpy_toio((void __iomem __force *)header, msg, size);
}
}
static void memcpy_fromrb(struct scif_rb *rb, void *header,
void *msg, u32 size)
{
u32 size1, size2;
if (header + size >= rb->rb_base + rb->size) {
size1 = (u32)(rb->rb_base + rb->size - header);
size2 = size - size1;
memcpy_fromio(msg, (void __iomem __force *)header, size1);
memcpy_fromio(msg + size1,
(void __iomem __force *)rb->rb_base, size2);
} else {
memcpy_fromio(msg, (void __iomem __force *)header, size);
}
}
u32 scif_rb_space(struct scif_rb *rb)
{
rb->current_read_offset = *rb->read_ptr;
mb();
return scif_rb_ring_space(rb->current_write_offset,
rb->current_read_offset, rb->size);
}
int scif_rb_write(struct scif_rb *rb, void *msg, u32 size)
{
void *header;
if (scif_rb_space(rb) < size)
return -ENOMEM;
header = rb->rb_base + rb->current_write_offset;
memcpy_torb(rb, header, msg, size);
rb->current_write_offset =
(rb->current_write_offset + size) & (rb->size - 1);
return 0;
}
void scif_rb_commit(struct scif_rb *rb)
{
wmb();
ACCESS_ONCE(*rb->write_ptr) = rb->current_write_offset;
#ifdef CONFIG_INTEL_MIC_CARD
ACCESS_ONCE(*rb->write_ptr) = rb->current_write_offset;
#endif
}
static void *scif_rb_get(struct scif_rb *rb, u32 size)
{
void *header = NULL;
if (scif_rb_count(rb, size) >= size)
header = rb->rb_base + rb->current_read_offset;
return header;
}
u32 scif_rb_get_next(struct scif_rb *rb, void *msg, u32 size)
{
void *header = NULL;
int read_size = 0;
header = scif_rb_get(rb, size);
if (header) {
u32 next_cmd_offset =
(rb->current_read_offset + size) & (rb->size - 1);
read_size = size;
rb->current_read_offset = next_cmd_offset;
memcpy_fromrb(rb, header, msg, size);
}
return read_size;
}
void scif_rb_update_read_ptr(struct scif_rb *rb)
{
u32 new_offset;
new_offset = rb->current_read_offset;
mb();
ACCESS_ONCE(*rb->read_ptr) = new_offset;
#ifdef CONFIG_INTEL_MIC_CARD
ACCESS_ONCE(*rb->read_ptr) = new_offset;
#endif
}
u32 scif_rb_count(struct scif_rb *rb, u32 size)
{
if (scif_rb_ring_cnt(rb->current_write_offset,
rb->current_read_offset,
rb->size) < size) {
rb->current_write_offset = *rb->write_ptr;
smp_rmb();
}
return scif_rb_ring_cnt(rb->current_write_offset,
rb->current_read_offset,
rb->size);
}
