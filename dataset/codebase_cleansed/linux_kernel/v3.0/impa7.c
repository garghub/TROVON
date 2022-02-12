static int __init init_impa7(void)
{
static const char *rom_probe_types[] = PROBETYPES;
const char **type;
const char *part_type = 0;
int i;
static struct { u_long addr; u_long size; } pt[NUM_FLASHBANKS] = {
{ WINDOW_ADDR0, WINDOW_SIZE0 },
{ WINDOW_ADDR1, WINDOW_SIZE1 },
};
int devicesfound = 0;
for(i=0; i<NUM_FLASHBANKS; i++)
{
printk(KERN_NOTICE MSG_PREFIX "probing 0x%08lx at 0x%08lx\n",
pt[i].size, pt[i].addr);
impa7_map[i].phys = pt[i].addr;
impa7_map[i].virt = ioremap(pt[i].addr, pt[i].size);
if (!impa7_map[i].virt) {
printk(MSG_PREFIX "failed to ioremap\n");
return -EIO;
}
simple_map_init(&impa7_map[i]);
impa7_mtd[i] = 0;
type = rom_probe_types;
for(; !impa7_mtd[i] && *type; type++) {
impa7_mtd[i] = do_map_probe(*type, &impa7_map[i]);
}
if (impa7_mtd[i]) {
impa7_mtd[i]->owner = THIS_MODULE;
devicesfound++;
mtd_parts_nb[i] = parse_mtd_partitions(impa7_mtd[i],
probes,
&mtd_parts[i],
0);
if (mtd_parts_nb[i] > 0) {
part_type = "command line";
} else {
mtd_parts[i] = static_partitions;
mtd_parts_nb[i] = ARRAY_SIZE(static_partitions);
part_type = "static";
}
printk(KERN_NOTICE MSG_PREFIX
"using %s partition definition\n",
part_type);
mtd_device_register(impa7_mtd[i],
mtd_parts[i], mtd_parts_nb[i]);
}
else
iounmap((void *)impa7_map[i].virt);
}
return devicesfound == 0 ? -ENXIO : 0;
}
static void __exit cleanup_impa7(void)
{
int i;
for (i=0; i<NUM_FLASHBANKS; i++) {
if (impa7_mtd[i]) {
mtd_device_unregister(impa7_mtd[i]);
map_destroy(impa7_mtd[i]);
iounmap((void *)impa7_map[i].virt);
impa7_map[i].virt = 0;
}
}
}
