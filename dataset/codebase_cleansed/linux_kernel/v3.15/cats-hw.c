static int __init cats_hw_init(void)
{
if (machine_is_cats()) {
outb(0x51, CFG_PORT);
outb(0x23, CFG_PORT);
outb(0x07, INDEX_PORT);
outb(0x03, DATA_PORT);
outb(0x74, INDEX_PORT);
outb(0x03, DATA_PORT);
outb(0xf0, INDEX_PORT);
outb(0x0f, DATA_PORT);
outb(0xf1, INDEX_PORT);
outb(0x07, DATA_PORT);
outb(0x07, INDEX_PORT);
outb(0x04, DATA_PORT);
outb(0xf0, INDEX_PORT);
outb(0x02, DATA_PORT);
outb(0x07, INDEX_PORT);
outb(0x05, DATA_PORT);
outb(0xf0, INDEX_PORT);
outb(0x02, DATA_PORT);
outb(0xbb, CFG_PORT);
}
return 0;
}
static void __init
fixup_cats(struct tag *tags, char **cmdline, struct meminfo *mi)
{
#if defined(CONFIG_VGA_CONSOLE) || defined(CONFIG_DUMMY_CONSOLE)
screen_info.orig_video_lines = 25;
screen_info.orig_video_points = 16;
screen_info.orig_y = 24;
#endif
}
