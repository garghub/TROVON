static void sc520cdp_setup_par(void)
{
unsigned long __iomem *mmcr;
unsigned long mmcr_val;
int i, j;
mmcr = ioremap_nocache(SC520_MMCR_BASE, SC520_MMCR_EXTENT);
if(!mmcr) {
for(i = 0; i < NUM_FLASH_BANKS; i++)
sc520cdp_map[i].phys = par_table[i].default_address;
return;
}
for(i = 0; i < NUM_FLASH_BANKS; i++) {
for(j = 0; j < NUM_SC520_PAR; j++) {
mmcr_val = readl(&mmcr[SC520_PAR(j)]);
if((mmcr_val & SC520_PAR_TRGDEV) == par_table[i].trgdev)
{
writel(par_table[i].new_par, &mmcr[SC520_PAR(j)]);
break;
}
}
if(j == NUM_SC520_PAR)
{
printk(KERN_NOTICE "Could not find PAR responsible for %s\n",
sc520cdp_map[i].name);
printk(KERN_NOTICE "Trying default address 0x%lx\n",
par_table[i].default_address);
sc520cdp_map[i].phys = par_table[i].default_address;
}
}
iounmap(mmcr);
}
static int __init init_sc520cdp(void)
{
int i, j, devices_found = 0;
#ifdef REPROGRAM_PAR
sc520cdp_setup_par();
#endif
for (i = 0; i < NUM_FLASH_BANKS; i++) {
printk(KERN_NOTICE "SC520 CDP flash device: 0x%Lx at 0x%Lx\n",
(unsigned long long)sc520cdp_map[i].size,
(unsigned long long)sc520cdp_map[i].phys);
sc520cdp_map[i].virt = ioremap_nocache(sc520cdp_map[i].phys, sc520cdp_map[i].size);
if (!sc520cdp_map[i].virt) {
printk("Failed to ioremap_nocache\n");
for (j = 0; j < i; j++) {
if (mymtd[j]) {
map_destroy(mymtd[j]);
iounmap(sc520cdp_map[j].virt);
}
}
return -EIO;
}
simple_map_init(&sc520cdp_map[i]);
mymtd[i] = do_map_probe("cfi_probe", &sc520cdp_map[i]);
if(!mymtd[i])
mymtd[i] = do_map_probe("jedec_probe", &sc520cdp_map[i]);
if(!mymtd[i])
mymtd[i] = do_map_probe("map_rom", &sc520cdp_map[i]);
if (mymtd[i]) {
mymtd[i]->owner = THIS_MODULE;
++devices_found;
}
else {
iounmap(sc520cdp_map[i].virt);
}
}
if(devices_found >= 2) {
merged_mtd = mtd_concat_create(mymtd, 2, "SC520CDP Flash Banks #0 and #1");
if(merged_mtd)
mtd_device_register(merged_mtd, NULL, 0);
}
if(devices_found == 3)
mtd_device_register(mymtd[2], NULL, 0);
return(devices_found ? 0 : -ENXIO);
}
static void __exit cleanup_sc520cdp(void)
{
int i;
if (merged_mtd) {
mtd_device_unregister(merged_mtd);
mtd_concat_destroy(merged_mtd);
}
if (mymtd[2])
mtd_device_unregister(mymtd[2]);
for (i = 0; i < NUM_FLASH_BANKS; i++) {
if (mymtd[i])
map_destroy(mymtd[i]);
if (sc520cdp_map[i].virt) {
iounmap(sc520cdp_map[i].virt);
sc520cdp_map[i].virt = NULL;
}
}
}
