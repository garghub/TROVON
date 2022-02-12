static void amd76xrom_cleanup(struct amd76xrom_window *window)
{
struct amd76xrom_map_info *map, *scratch;
u8 byte;
if (window->pdev) {
pci_read_config_byte(window->pdev, 0x40, &byte);
pci_write_config_byte(window->pdev, 0x40, byte & ~1);
pci_dev_put(window->pdev);
}
list_for_each_entry_safe(map, scratch, &window->maps, list) {
if (map->rsrc.parent) {
release_resource(&map->rsrc);
}
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
window->pdev = NULL;
}
}
static int __devinit amd76xrom_init_one (struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static char *rom_probe_types[] = { "cfi_probe", "jedec_probe", NULL };
u8 byte;
struct amd76xrom_window *window = &amd76xrom_window;
struct amd76xrom_map_info *map = NULL;
unsigned long map_top;
window->pdev = pdev;
pci_read_config_byte(pdev, 0x43, &byte);
pci_write_config_byte(pdev, 0x43, byte | win_size_bits );
pci_read_config_byte(pdev, 0x43, &byte);
if ((byte & ((1<<7)|(1<<6))) == ((1<<7)|(1<<6))) {
window->phys = 0xffb00000;
}
else if ((byte & (1<<7)) == (1<<7)) {
window->phys = 0xffc00000;
}
else {
window->phys = 0xffff0000;
}
window->size = 0xffffffffUL - window->phys + 1UL;
window->rsrc.name = MOD_NAME;
window->rsrc.start = window->phys;
window->rsrc.end = window->phys + window->size - 1;
window->rsrc.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
if (request_resource(&iomem_resource, &window->rsrc)) {
window->rsrc.parent = NULL;
printk(KERN_ERR MOD_NAME
" %s(): Unable to register resource %pR - kernel bug?\n",
__func__, &window->rsrc);
return -EBUSY;
}
pci_read_config_byte(pdev, 0x40, &byte);
pci_write_config_byte(pdev, 0x40, byte | 1);
window->virt = ioremap_nocache(window->phys, window->size);
if (!window->virt) {
printk(KERN_ERR MOD_NAME ": ioremap(%08lx, %08lx) failed\n",
window->phys, window->size);
goto out;
}
map_top = window->phys;
#if 1
if (map_top < 0xffc00000) {
map_top = 0xffc00000;
}
#endif
while((map_top - 1) < 0xffffffffUL) {
struct cfi_private *cfi;
unsigned long offset;
int i;
if (!map) {
map = kmalloc(sizeof(*map), GFP_KERNEL);
}
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
map->map.bankwidth >>= 1)
{
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
for(i = 0; i < cfi->numchips; i++) {
cfi->chips[i].start += offset;
}
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
amd76xrom_cleanup(window);
return -ENODEV;
}
return 0;
}
static void __devexit amd76xrom_remove_one (struct pci_dev *pdev)
{
struct amd76xrom_window *window = &amd76xrom_window;
amd76xrom_cleanup(window);
}
static int __init init_amd76xrom(void)
{
struct pci_dev *pdev;
struct pci_device_id *id;
pdev = NULL;
for(id = amd76xrom_pci_tbl; id->vendor; id++) {
pdev = pci_get_device(id->vendor, id->device, NULL);
if (pdev) {
break;
}
}
if (pdev) {
return amd76xrom_init_one(pdev, &amd76xrom_pci_tbl[0]);
}
return -ENXIO;
#if 0
return pci_register_driver(&amd76xrom_driver);
#endif
}
static void __exit cleanup_amd76xrom(void)
{
amd76xrom_remove_one(amd76xrom_window.pdev);
}
