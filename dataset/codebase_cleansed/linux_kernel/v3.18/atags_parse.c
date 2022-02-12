static int __init parse_tag_core(const struct tag *tag)
{
if (tag->hdr.size > 2) {
if ((tag->u.core.flags & 1) == 0)
root_mountflags &= ~MS_RDONLY;
ROOT_DEV = old_decode_dev(tag->u.core.rootdev);
}
return 0;
}
static int __init parse_tag_mem32(const struct tag *tag)
{
return arm_add_memory(tag->u.mem.start, tag->u.mem.size);
}
static int __init parse_tag_videotext(const struct tag *tag)
{
screen_info.orig_x = tag->u.videotext.x;
screen_info.orig_y = tag->u.videotext.y;
screen_info.orig_video_page = tag->u.videotext.video_page;
screen_info.orig_video_mode = tag->u.videotext.video_mode;
screen_info.orig_video_cols = tag->u.videotext.video_cols;
screen_info.orig_video_ega_bx = tag->u.videotext.video_ega_bx;
screen_info.orig_video_lines = tag->u.videotext.video_lines;
screen_info.orig_video_isVGA = tag->u.videotext.video_isvga;
screen_info.orig_video_points = tag->u.videotext.video_points;
return 0;
}
static int __init parse_tag_ramdisk(const struct tag *tag)
{
extern int rd_size, rd_image_start, rd_prompt, rd_doload;
rd_image_start = tag->u.ramdisk.start;
rd_doload = (tag->u.ramdisk.flags & 1) == 0;
rd_prompt = (tag->u.ramdisk.flags & 2) == 0;
if (tag->u.ramdisk.size)
rd_size = tag->u.ramdisk.size;
return 0;
}
static int __init parse_tag_serialnr(const struct tag *tag)
{
system_serial_low = tag->u.serialnr.low;
system_serial_high = tag->u.serialnr.high;
return 0;
}
static int __init parse_tag_revision(const struct tag *tag)
{
system_rev = tag->u.revision.rev;
return 0;
}
static int __init parse_tag_cmdline(const struct tag *tag)
{
#if defined(CONFIG_CMDLINE_EXTEND)
strlcat(default_command_line, " ", COMMAND_LINE_SIZE);
strlcat(default_command_line, tag->u.cmdline.cmdline,
COMMAND_LINE_SIZE);
#elif defined(CONFIG_CMDLINE_FORCE)
pr_warn("Ignoring tag cmdline (using the default kernel command line)\n");
#else
strlcpy(default_command_line, tag->u.cmdline.cmdline,
COMMAND_LINE_SIZE);
#endif
return 0;
}
static int __init parse_tag(const struct tag *tag)
{
extern struct tagtable __tagtable_begin, __tagtable_end;
struct tagtable *t;
for (t = &__tagtable_begin; t < &__tagtable_end; t++)
if (tag->hdr.tag == t->tag) {
t->parse(tag);
break;
}
return t < &__tagtable_end;
}
static void __init parse_tags(const struct tag *t)
{
for (; t->hdr.size; t = tag_next(t))
if (!parse_tag(t))
printk(KERN_WARNING
"Ignoring unrecognised tag 0x%08x\n",
t->hdr.tag);
}
static void __init squash_mem_tags(struct tag *tag)
{
for (; tag->hdr.size; tag = tag_next(tag))
if (tag->hdr.tag == ATAG_MEM)
tag->hdr.tag = ATAG_NONE;
}
const struct machine_desc * __init
setup_machine_tags(phys_addr_t __atags_pointer, unsigned int machine_nr)
{
struct tag *tags = (struct tag *)&default_tags;
const struct machine_desc *mdesc = NULL, *p;
char *from = default_command_line;
default_tags.mem.start = PHYS_OFFSET;
for_each_machine_desc(p)
if (machine_nr == p->nr) {
printk("Machine: %s\n", p->name);
mdesc = p;
break;
}
if (!mdesc) {
early_print("\nError: unrecognized/unsupported machine ID"
" (r1 = 0x%08x).\n\n", machine_nr);
dump_machine_table();
}
if (__atags_pointer)
tags = phys_to_virt(__atags_pointer);
else if (mdesc->atag_offset)
tags = (void *)(PAGE_OFFSET + mdesc->atag_offset);
#if defined(CONFIG_DEPRECATED_PARAM_STRUCT)
if (tags->hdr.tag != ATAG_CORE)
convert_to_tag_list(tags);
#endif
if (tags->hdr.tag != ATAG_CORE) {
early_print("Warning: Neither atags nor dtb found\n");
tags = (struct tag *)&default_tags;
}
if (mdesc->fixup)
mdesc->fixup(tags, &from);
if (tags->hdr.tag == ATAG_CORE) {
if (memblock_phys_mem_size())
squash_mem_tags(tags);
save_atags(tags);
parse_tags(tags);
}
strlcpy(boot_command_line, from, COMMAND_LINE_SIZE);
return mdesc;
}
