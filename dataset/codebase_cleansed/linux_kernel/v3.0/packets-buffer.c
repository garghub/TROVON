int iso_packets_buffer_init(struct iso_packets_buffer *b, struct fw_unit *unit,
unsigned int count, unsigned int packet_size,
enum dma_data_direction direction)
{
unsigned int packets_per_page, pages;
unsigned int i, page_index, offset_in_page;
void *p;
int err;
b->packets = kmalloc(count * sizeof(*b->packets), GFP_KERNEL);
if (!b->packets) {
err = -ENOMEM;
goto error;
}
packet_size = L1_CACHE_ALIGN(packet_size);
packets_per_page = PAGE_SIZE / packet_size;
if (WARN_ON(!packets_per_page)) {
err = -EINVAL;
goto error;
}
pages = DIV_ROUND_UP(count, packets_per_page);
err = fw_iso_buffer_init(&b->iso_buffer, fw_parent_device(unit)->card,
pages, direction);
if (err < 0)
goto err_packets;
for (i = 0; i < count; ++i) {
page_index = i / packets_per_page;
p = page_address(b->iso_buffer.pages[page_index]);
offset_in_page = (i % packets_per_page) * packet_size;
b->packets[i].buffer = p + offset_in_page;
b->packets[i].offset = page_index * PAGE_SIZE + offset_in_page;
}
return 0;
err_packets:
kfree(b->packets);
error:
return err;
}
void iso_packets_buffer_destroy(struct iso_packets_buffer *b,
struct fw_unit *unit)
{
fw_iso_buffer_destroy(&b->iso_buffer, fw_parent_device(unit)->card);
kfree(b->packets);
}
