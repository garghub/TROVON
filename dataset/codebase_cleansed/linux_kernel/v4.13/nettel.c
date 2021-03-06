static int nettel_reboot_notifier(struct notifier_block *nb, unsigned long val, void *v)
{
struct cfi_private *cfi = nettel_intel_map.fldrv_priv;
unsigned long b;
for (b = 0; (b < nettel_intel_partitions[3].size); b += 0x100000) {
cfi_send_gen_cmd(0xff, 0x55, b, &nettel_intel_map, cfi,
cfi->device_type, NULL);
}
return(NOTIFY_OK);
}
static int __init nettel_init(void)
{
volatile unsigned long *amdpar;
unsigned long amdaddr, maxsize;
int num_amd_partitions=0;
#ifdef CONFIG_MTD_CFI_INTELEXT
volatile unsigned long *intel0par, *intel1par;
unsigned long orig_bootcspar, orig_romcs1par;
unsigned long intel0addr, intel0size;
unsigned long intel1addr, intel1size;
int intelboot, intel0cs, intel1cs;
int num_intel_partitions;
#endif
int rc = 0;
nettel_mmcrp = (void *) ioremap_nocache(0xfffef000, 4096);
if (nettel_mmcrp == NULL) {
printk("SNAPGEAR: failed to disable MMCR cache??\n");
return(-EIO);
}
*((unsigned char *) (nettel_mmcrp + 0xc64)) = 0x01;
amdpar = (volatile unsigned long *) (nettel_mmcrp + 0xc4);
#ifdef CONFIG_MTD_CFI_INTELEXT
intelboot = 0;
intel0cs = SC520_PAR_ROMCS1;
intel0par = (volatile unsigned long *) (nettel_mmcrp + 0xc0);
intel1cs = SC520_PAR_ROMCS2;
intel1par = (volatile unsigned long *) (nettel_mmcrp + 0xbc);
orig_bootcspar = *amdpar;
orig_romcs1par = *intel0par;
*intel0par = 0;
*intel1par = 0;
#endif
amdaddr = 0x20000000;
maxsize = AMD_WINDOW_MAXSIZE;
*amdpar = SC520_PAR(SC520_PAR_BOOTCS, amdaddr, maxsize);
__asm__ ("wbinvd");
nettel_amd_map.phys = amdaddr;
nettel_amd_map.virt = ioremap_nocache(amdaddr, maxsize);
if (!nettel_amd_map.virt) {
printk("SNAPGEAR: failed to ioremap() BOOTCS\n");
iounmap(nettel_mmcrp);
return(-EIO);
}
simple_map_init(&nettel_amd_map);
if ((amd_mtd = do_map_probe("jedec_probe", &nettel_amd_map))) {
printk(KERN_NOTICE "SNAPGEAR: AMD flash device size = %dK\n",
(int)(amd_mtd->size>>10));
amd_mtd->owner = THIS_MODULE;
num_amd_partitions = NUM_AMD_PARTITIONS;
if (amd_mtd->size < AMD_WINDOW_MAXSIZE)
num_amd_partitions--;
#ifdef CONFIG_MTD_CFI_INTELEXT
maxsize = SC520_PAR_TO_SIZE(orig_romcs1par);
if (maxsize < (32 * 1024 * 1024))
maxsize = (32 * 1024 * 1024);
intel0addr = amdaddr + maxsize;
#endif
} else {
#ifdef CONFIG_MTD_CFI_INTELEXT
intelboot++;
if (!orig_romcs1par) {
intel0cs = SC520_PAR_BOOTCS;
intel0par = (volatile unsigned long *)
(nettel_mmcrp + 0xc4);
intel1cs = SC520_PAR_ROMCS1;
intel1par = (volatile unsigned long *)
(nettel_mmcrp + 0xc0);
intel0addr = SC520_PAR_TO_ADDR(orig_bootcspar);
maxsize = SC520_PAR_TO_SIZE(orig_bootcspar);
} else {
intel0cs = SC520_PAR_ROMCS1;
intel0par = (volatile unsigned long *)
(nettel_mmcrp + 0xc0);
intel1cs = SC520_PAR_BOOTCS;
intel1par = (volatile unsigned long *)
(nettel_mmcrp + 0xc4);
intel0addr = SC520_PAR_TO_ADDR(orig_romcs1par);
maxsize = SC520_PAR_TO_SIZE(orig_romcs1par);
}
amd_mtd = NULL;
iounmap(nettel_amd_map.virt);
nettel_amd_map.virt = NULL;
#else
rc = -ENXIO;
goto out_unmap2;
#endif
}
#ifdef CONFIG_MTD_CFI_INTELEXT
if (maxsize < (32 * 1024 * 1024))
maxsize = (32 * 1024 * 1024);
*intel0par = SC520_PAR(intel0cs, intel0addr, maxsize);
*intel1par = 0;
nettel_intel_map.size = maxsize;
nettel_intel_map.phys = intel0addr;
nettel_intel_map.virt = ioremap_nocache(intel0addr, maxsize);
if (!nettel_intel_map.virt) {
printk("SNAPGEAR: failed to ioremap() ROMCS1\n");
rc = -EIO;
goto out_unmap2;
}
simple_map_init(&nettel_intel_map);
intel_mtd = do_map_probe("cfi_probe", &nettel_intel_map);
if (!intel_mtd) {
rc = -ENXIO;
goto out_unmap1;
}
intel0size = intel_mtd->size;
*intel0par = SC520_PAR(intel0cs, intel0addr, intel0size);
intel1addr = intel0addr + intel0size;
*intel1par = SC520_PAR(intel1cs, intel1addr, maxsize);
__asm__ ("wbinvd");
maxsize += intel0size;
map_destroy(intel_mtd);
intel_mtd = NULL;
iounmap(nettel_intel_map.virt);
nettel_intel_map.size = maxsize;
nettel_intel_map.virt = ioremap_nocache(intel0addr, maxsize);
if (!nettel_intel_map.virt) {
printk("SNAPGEAR: failed to ioremap() ROMCS1/2\n");
rc = -EIO;
goto out_unmap2;
}
intel_mtd = do_map_probe("cfi_probe", &nettel_intel_map);
if (! intel_mtd) {
rc = -ENXIO;
goto out_unmap1;
}
intel1size = intel_mtd->size - intel0size;
if (intel1size > 0) {
*intel1par = SC520_PAR(intel1cs, intel1addr, intel1size);
__asm__ ("wbinvd");
} else {
*intel1par = 0;
}
printk(KERN_NOTICE "SNAPGEAR: Intel flash device size = %lldKiB\n",
(unsigned long long)(intel_mtd->size >> 10));
intel_mtd->owner = THIS_MODULE;
num_intel_partitions = ARRAY_SIZE(nettel_intel_partitions);
if (intelboot) {
nettel_intel_partitions[1].size = (intel0size + intel1size) -
(1024*1024 + intel_mtd->erasesize);
nettel_intel_partitions[3].size = intel0size + intel1size;
nettel_intel_partitions[4].offset =
(intel0size + intel1size) - intel_mtd->erasesize;
nettel_intel_partitions[4].size = intel_mtd->erasesize;
nettel_intel_partitions[5].offset =
nettel_intel_partitions[4].offset;
nettel_intel_partitions[5].size =
nettel_intel_partitions[4].size;
} else {
num_intel_partitions -= 2;
}
rc = mtd_device_register(intel_mtd, nettel_intel_partitions,
num_intel_partitions);
if (rc)
goto out_map_destroy;
#endif
if (amd_mtd) {
rc = mtd_device_register(amd_mtd, nettel_amd_partitions,
num_amd_partitions);
if (rc)
goto out_mtd_unreg;
}
#ifdef CONFIG_MTD_CFI_INTELEXT
register_reboot_notifier(&nettel_notifier_block);
#endif
return rc;
out_mtd_unreg:
#ifdef CONFIG_MTD_CFI_INTELEXT
mtd_device_unregister(intel_mtd);
out_map_destroy:
map_destroy(intel_mtd);
out_unmap1:
iounmap(nettel_intel_map.virt);
#endif
out_unmap2:
iounmap(nettel_mmcrp);
iounmap(nettel_amd_map.virt);
return rc;
}
static void __exit nettel_cleanup(void)
{
#ifdef CONFIG_MTD_CFI_INTELEXT
unregister_reboot_notifier(&nettel_notifier_block);
#endif
if (amd_mtd) {
mtd_device_unregister(amd_mtd);
map_destroy(amd_mtd);
}
if (nettel_mmcrp) {
iounmap(nettel_mmcrp);
nettel_mmcrp = NULL;
}
if (nettel_amd_map.virt) {
iounmap(nettel_amd_map.virt);
nettel_amd_map.virt = NULL;
}
#ifdef CONFIG_MTD_CFI_INTELEXT
if (intel_mtd) {
mtd_device_unregister(intel_mtd);
map_destroy(intel_mtd);
}
if (nettel_intel_map.virt) {
iounmap(nettel_intel_map.virt);
nettel_intel_map.virt = NULL;
}
#endif
}
