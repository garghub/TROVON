static void __init
fixup_p720t(struct tag *tag, char **cmdline, struct meminfo *mi)
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
static void __init p720t_init_early(void)
{
PLD_LCDEN = 0;
PLD_PWR &= ~(PLD_S4_ON|PLD_S3_ON|PLD_S2_ON|PLD_S1_ON);
PLD_KBD = 0;
PLD_IO = 0;
PLD_IRDA = 0;
PLD_CODEC = 0;
PLD_TCH = 0;
PLD_SPI = 0;
if (!IS_ENABLED(CONFIG_DEBUG_LL)) {
PLD_COM2 = 0;
PLD_COM1 = 0;
}
}
