static void esb2rom_cleanup(struct esb2rom_window *window)
{
struct esb2rom_map_info *map, *scratch;
u8 byte;
pci_read_config_byte(window->pdev, BIOS_CNTL, &byte);
pci_write_config_byte(window->pdev, BIOS_CNTL,
byte & ~BIOS_WRITE_ENABLE);
list_for_each_entry_safe(map, scratch, &window->maps, list) {
if (map->rsrc.parent)
release_resource(&map->rsrc);
mtd_device_unregister(map->mtd);
map_destroy(map->mtd);
list_del(&map->list);
kfree(map);
}
if (window->rsrc.parent)
release_resource(&window->rsrc);
if (window->virt) {
iounmap(window->virt);
window->virt = NULL;
window->phys = 0;
window->size = 0;
}
pci_dev_put(window->pdev);
}
static int __devinit esb2rom_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static char *rom_probe_types[] = { "cfi_probe", "jedec_probe", NULL };
struct esb2rom_window *window = &esb2rom_window;
struct esb2rom_map_info *map = NULL;
unsigned long map_top;
u8 byte;
u16 word;
window->pdev = pci_dev_get(pdev);
window->phys = 0;
pci_read_config_word(pdev, FWH_DEC_EN1, &word);
printk(KERN_DEBUG "pci_read_config_word : %x\n", word);
if ((word & FWH_8MiB) == FWH_8MiB)
window->phys = 0xff400000;
else if ((word & FWH_7MiB) == FWH_7MiB)
window->phys = 0xff500000;
else if ((word & FWH_6MiB) == FWH_6MiB)
window->phys = 0xff600000;
else if ((word & FWH_5MiB) == FWH_5MiB)
window->phys = 0xFF700000;
else if ((word & FWH_4MiB) == FWH_4MiB)
window->phys = 0xffc00000;
else if ((word & FWH_3_5MiB) == FWH_3_5MiB)
window->phys = 0xffc80000;
else if ((word & FWH_3MiB) == FWH_3MiB)
window->phys = 0xffd00000;
else if ((word & FWH_2_5MiB) == FWH_2_5MiB)
window->phys = 0xffd80000;
else if ((word & FWH_2MiB) == FWH_2MiB)
window->phys = 0xffe00000;
else if ((word & FWH_1_5MiB) == FWH_1_5MiB)
window->phys = 0xffe80000;
else if ((word & FWH_1MiB) == FWH_1MiB)
window->phys = 0xfff00000;
else if ((word & FWH_0_5MiB) == FWH_0_5MiB)
window->phys = 0xfff80000;
if (window->phys == 0) {
printk(KERN_ERR MOD_NAME ": Rom window is closed\n");
goto out;
}
window->phys -= 0x400000UL;
window->size = (0xffffffffUL - window->phys) + 1UL;
pci_read_config_byte(pdev, BIOS_CNTL, &byte);
if (!(byte & BIOS_WRITE_ENABLE) && (byte & (BIOS_LOCK_ENABLE))) {
printk(KERN_ERR MOD_NAME ": firmware access control, I can't enable writes\n");
goto out;
}
pci_write_config_byte(pdev, BIOS_CNTL, byte | BIOS_WRITE_ENABLE);
window->rsrc.name = MOD_NAME;
window->rsrc.start = window->phys;
window->rsrc.end = window->phys + window->size - 1;
window->rsrc.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
if (request_resource(&iomem_resource, &window->rsrc)) {
window->rsrc.parent = NULL;
printk(KERN_DEBUG MOD_NAME ": "
"%s(): Unable to register resource %pR - kernel bug?\n",
__func__, &window->rsrc);
}
window->virt = ioremap_nocache(window->phys, window->size);
if (!window->virt) {
printk(KERN_ERR MOD_NAME ": ioremap(%08lx, %08lx) failed\n",
window->phys, window->size);
goto out;
}
map_top = window->phys;
if ((window->phys & 0x3fffff) != 0) {
map_top = window->phys + 0x400000;
}
#if 1
if (map_top < 0xffc00000)
map_top = 0xffc00000;
#endif
while ((map_top - 1) < 0xffffffffUL) {
struct cfi_private *cfi;
unsigned long offset;
int i;
if (!map)
map = kmalloc(sizeof(*map), GFP_KERNEL);
if (!map) {
printk(KERN_ERR MOD_NAME ": kmalloc failed");
goto out;
}
memset(map, 0, sizeof(*map));
INIT_LIST_HEAD(&map->list);
map->map.name = map->map_name;
map->map.phys = map_top;
offset = map_top - window->phys;
map->map.virt = (void __iomem *)
(((unsigned long)(window->virt)) + offset);
map->map.size = 0xffffffffUL - map_top + 1UL;
sprintf(map->map_name, "%s @%08Lx",
MOD_NAME, (unsigned long long)map->map.phys);
for(map->map.bankwidth = 32; map->map.bankwidth;
map->map.bankwidth >>= 1) {
char **probe_type;
if (!map_bankwidth_supported(map->map.bankwidth))
continue;
simple_map_init(&map->map);
probe_type = rom_probe_types;
for(; *probe_type; probe_type++) {
map->mtd = do_map_probe(*probe_type, &map->map);
if (map->mtd)
goto found;
}
}
map_top += ROM_PROBE_STEP_SIZE;
continue;
found:
if (map->mtd->size > map->map.size) {
printk(KERN_WARNING MOD_NAME
" rom(%llu) larger than window(%lu). fixing...\n",
(unsigned long long)map->mtd->size, map->map.size);
map->mtd->size = map->map.size;
}
if (window->rsrc.parent) {
map->rsrc.name = map->map_name;
map->rsrc.start = map->map.phys;
map->rsrc.end = map->map.phys + map->mtd->size - 1;
map->rsrc.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
if (request_resource(&window->rsrc, &map->rsrc)) {
printk(KERN_ERR MOD_NAME
": cannot reserve MTD resource\n");
map->rsrc.parent = NULL;
}
}
map->map.virt = window->virt;
map->map.phys = window->phys;
cfi = map->map.fldrv_priv;
for(i = 0; i < cfi->numchips; i++)
cfi->chips[i].start += offset;
map->mtd->owner = THIS_MODULE;
if (mtd_device_register(map->mtd, NULL, 0)) {
map_destroy(map->mtd);
map->mtd = NULL;
goto out;
}
map_top += map->mtd->size;
list_add(&map->list, &window->maps);
map = NULL;
}
out:
kfree(map);
if (list_empty(&window->maps)) {
esb2rom_cleanup(window);
return -ENODEV;
}
return 0;
}
static void __devexit esb2rom_remove_one (struct pci_dev *pdev)
{
struct esb2rom_window *window = &esb2rom_window;
esb2rom_cleanup(window);
}
static int __init init_esb2rom(void)
{
struct pci_dev *pdev;
struct pci_device_id *id;
int retVal;
pdev = NULL;
for (id = esb2rom_pci_tbl; id->vendor; id++) {
printk(KERN_DEBUG "device id = %x\n", id->device);
pdev = pci_get_device(id->vendor, id->device, NULL);
if (pdev) {
printk(KERN_DEBUG "matched device = %x\n", id->device);
break;
}
}
if (pdev) {
printk(KERN_DEBUG "matched device id %x\n", id->device);
retVal = esb2rom_init_one(pdev, &esb2rom_pci_tbl[0]);
pci_dev_put(pdev);
printk(KERN_DEBUG "retVal = %d\n", retVal);
return retVal;
}
return -ENXIO;
#if 0
return pci_register_driver(&esb2rom_driver);
#endif
}
static void __exit cleanup_esb2rom(void)
{
esb2rom_remove_one(esb2rom_window.pdev);
}
