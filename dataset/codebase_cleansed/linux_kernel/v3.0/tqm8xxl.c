static int __init init_tqm_mtd(void)
{
int idx = 0, ret = 0;
unsigned long flash_addr, flash_size, mtd_size = 0;
bd_t *bd = (bd_t *)__res;
flash_addr = bd->bi_flashstart;
flash_size = bd->bi_flashsize;
start_scan_addr = ioremap(flash_addr, flash_size);
if (!start_scan_addr) {
printk(KERN_WARNING "%s:Failed to ioremap address:0x%x\n", __func__, flash_addr);
return -EIO;
}
for (idx = 0 ; idx < FLASH_BANK_MAX ; idx++) {
if(mtd_size >= flash_size)
break;
printk(KERN_INFO "%s: chip probing count %d\n", __func__, idx);
map_banks[idx] = kzalloc(sizeof(struct map_info), GFP_KERNEL);
if(map_banks[idx] == NULL) {
ret = -ENOMEM;
goto error_mem;
}
map_banks[idx]->name = kmalloc(16, GFP_KERNEL);
if (!map_banks[idx]->name) {
ret = -ENOMEM;
goto error_mem;
}
sprintf(map_banks[idx]->name, "TQM8xxL%d", idx);
map_banks[idx]->size = flash_size;
map_banks[idx]->bankwidth = 4;
simple_map_init(map_banks[idx]);
map_banks[idx]->virt = start_scan_addr;
map_banks[idx]->phys = flash_addr;
if (idx && mtd_banks[idx-1]) {
map_banks[idx]->virt += mtd_banks[idx-1]->size;
map_banks[idx]->phys += mtd_banks[idx-1]->size;
}
mtd_banks[idx] = do_map_probe("cfi_probe", map_banks[idx]);
if (mtd_banks[idx]) {
mtd_banks[idx]->owner = THIS_MODULE;
mtd_size += mtd_banks[idx]->size;
num_banks++;
printk(KERN_INFO "%s: bank%d, name:%s, size:%dbytes \n", __func__, num_banks,
mtd_banks[idx]->name, mtd_banks[idx]->size);
}
}
if (!num_banks) {
printk(KERN_NOTICE "TQM8xxL: No support flash chips found!\n");
ret = -ENXIO;
goto error_mem;
}
part_banks[0].mtd_part = tqm8xxl_partitions;
part_banks[0].type = "Static image";
part_banks[0].nums = ARRAY_SIZE(tqm8xxl_partitions);
part_banks[1].mtd_part = tqm8xxl_fs_partitions;
part_banks[1].type = "Static file system";
part_banks[1].nums = ARRAY_SIZE(tqm8xxl_fs_partitions);
for(idx = 0; idx < num_banks ; idx++) {
if (part_banks[idx].nums == 0)
printk(KERN_NOTICE "TQM flash%d: no partition info available, registering whole flash at once\n", idx);
else
printk(KERN_NOTICE "TQM flash%d: Using %s partition definition\n",
idx, part_banks[idx].type);
mtd_device_register(mtd_banks[idx], part_banks[idx].mtd_part,
part_banks[idx].nums);
}
return 0;
error_mem:
for(idx = 0 ; idx < FLASH_BANK_MAX ; idx++) {
if(map_banks[idx] != NULL) {
kfree(map_banks[idx]->name);
map_banks[idx]->name = NULL;
kfree(map_banks[idx]);
map_banks[idx] = NULL;
}
}
error:
iounmap(start_scan_addr);
return ret;
}
static void __exit cleanup_tqm_mtd(void)
{
unsigned int idx = 0;
for(idx = 0 ; idx < num_banks ; idx++) {
if (mtd_banks[idx]) {
mtd_device_unregister(mtd_banks[idx]);
map_destroy(mtd_banks[idx]);
}
kfree(map_banks[idx]->name);
kfree(map_banks[idx]);
}
if (start_scan_addr) {
iounmap(start_scan_addr);
start_scan_addr = 0;
}
}
