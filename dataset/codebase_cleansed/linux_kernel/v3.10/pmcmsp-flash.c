static int __init init_msp_flash(void)
{
int i, j, ret = -ENOMEM;
int offset, coff;
char *env;
int pcnt;
char flash_name[] = "flash0";
char part_name[] = "flash0_0";
unsigned addr, size;
if ((*DEV_ID_REG & DEV_ID_SINGLE_PC) &&
(*ELB_1PC_EN_REG & SINGLE_PCCARD)) {
printk(KERN_NOTICE "Single PC Card mode: no flash access\n");
return -ENXIO;
}
for (fcnt = 0; (env = prom_getenv(flash_name)); fcnt++)
flash_name[5] = '0' + fcnt + 1;
if (fcnt < 1)
return -ENXIO;
printk(KERN_NOTICE "Found %d PMC flash devices\n", fcnt);
msp_flash = kmalloc(fcnt * sizeof(struct map_info *), GFP_KERNEL);
if (!msp_flash)
return -ENOMEM;
msp_parts = kmalloc(fcnt * sizeof(struct mtd_partition *), GFP_KERNEL);
if (!msp_parts)
goto free_msp_flash;
msp_maps = kcalloc(fcnt, sizeof(struct mtd_info), GFP_KERNEL);
if (!msp_maps)
goto free_msp_parts;
for (i = 0; i < fcnt; i++) {
part_name[5] = '0' + i;
part_name[7] = '0';
for (pcnt = 0; (env = prom_getenv(part_name)); pcnt++)
part_name[7] = '0' + pcnt + 1;
if (pcnt == 0) {
printk(KERN_NOTICE "Skipping flash device %d "
"(no partitions defined)\n", i);
continue;
}
msp_parts[i] = kcalloc(pcnt, sizeof(struct mtd_partition),
GFP_KERNEL);
if (!msp_parts[i])
goto cleanup_loop;
flash_name[5] = '0' + i;
env = prom_getenv(flash_name);
if (sscanf(env, "%x:%x", &addr, &size) < 2) {
ret = -ENXIO;
kfree(msp_parts[i]);
goto cleanup_loop;
}
addr = CPHYSADDR(addr);
printk(KERN_NOTICE
"MSP flash device \"%s\": 0x%08x at 0x%08x\n",
flash_name, size, addr);
msp_maps[i].size = size;
msp_maps[i].phys = addr;
if (size > CONFIG_MSP_FLASH_MAP_LIMIT)
size = CONFIG_MSP_FLASH_MAP_LIMIT;
msp_maps[i].virt = ioremap(addr, size);
if (msp_maps[i].virt == NULL) {
ret = -ENXIO;
kfree(msp_parts[i]);
goto cleanup_loop;
}
msp_maps[i].bankwidth = 1;
msp_maps[i].name = kmalloc(7, GFP_KERNEL);
if (!msp_maps[i].name) {
iounmap(msp_maps[i].virt);
kfree(msp_parts[i]);
goto cleanup_loop;
}
msp_maps[i].name = strncpy(msp_maps[i].name, flash_name, 7);
for (j = 0; j < pcnt; j++) {
part_name[5] = '0' + i;
part_name[7] = '0' + j;
env = prom_getenv(part_name);
if (sscanf(env, "%x:%x:%n", &offset, &size,
&coff) < 2) {
ret = -ENXIO;
kfree(msp_maps[i].name);
iounmap(msp_maps[i].virt);
kfree(msp_parts[i]);
goto cleanup_loop;
}
msp_parts[i][j].size = size;
msp_parts[i][j].offset = offset;
msp_parts[i][j].name = env + coff;
}
simple_map_init(&msp_maps[i]);
msp_flash[i] = do_map_probe("cfi_probe", &msp_maps[i]);
if (msp_flash[i]) {
msp_flash[i]->owner = THIS_MODULE;
mtd_device_register(msp_flash[i], msp_parts[i], pcnt);
} else {
printk(KERN_ERR "map probe failed for flash\n");
ret = -ENXIO;
kfree(msp_maps[i].name);
iounmap(msp_maps[i].virt);
kfree(msp_parts[i]);
goto cleanup_loop;
}
}
return 0;
cleanup_loop:
while (i--) {
mtd_device_unregister(msp_flash[i]);
map_destroy(msp_flash[i]);
kfree(msp_maps[i].name);
iounmap(msp_maps[i].virt);
kfree(msp_parts[i]);
}
kfree(msp_maps);
free_msp_parts:
kfree(msp_parts);
free_msp_flash:
kfree(msp_flash);
return ret;
}
static void __exit cleanup_msp_flash(void)
{
int i;
for (i = 0; i < fcnt; i++) {
mtd_device_unregister(msp_flash[i]);
map_destroy(msp_flash[i]);
iounmap((void *)msp_maps[i].virt);
kfree(msp_maps[i].name);
kfree(msp_parts[i]);
}
kfree(msp_flash);
kfree(msp_parts);
kfree(msp_maps);
}
