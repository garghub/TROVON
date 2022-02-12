static void __init
fixup_p720t(struct machine_desc *desc, struct tag *tag,
char **cmdline, struct meminfo *mi)
{
if (tag->hdr.tag != ATAG_CORE) {
tag->hdr.tag = ATAG_CORE;
tag->hdr.size = tag_size(tag_core);
tag->u.core.flags = 0;
tag->u.core.pagesize = PAGE_SIZE;
tag->u.core.rootdev = 0x0100;
tag = tag_next(tag);
tag->hdr.tag = ATAG_MEM;
tag->hdr.size = tag_size(tag_mem32);
tag->u.mem.size = 4096;
tag->u.mem.start = PHYS_OFFSET;
tag = tag_next(tag);
tag->hdr.tag = ATAG_NONE;
tag->hdr.size = 0;
}
}
static void __init p720t_map_io(void)
{
clps711x_map_io();
iotable_init(p720t_io_desc, ARRAY_SIZE(p720t_io_desc));
}
