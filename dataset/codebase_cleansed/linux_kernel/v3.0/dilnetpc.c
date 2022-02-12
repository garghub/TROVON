static inline void setcsc(int reg, unsigned char data)
{
outb(reg, CSC_INDEX);
outb(data, CSC_DATA);
}
static inline unsigned char getcsc(int reg)
{
outb(reg, CSC_INDEX);
return(inb(CSC_DATA));
}
static inline void setpcc(int reg, unsigned char data)
{
outb(reg, PCC_INDEX);
outb(data, PCC_DATA);
}
static inline unsigned char getpcc(int reg)
{
outb(reg, PCC_INDEX);
return(inb(PCC_DATA));
}
static void dnpc_map_flash(unsigned long flash_base, unsigned long flash_size)
{
unsigned long flash_end = flash_base + flash_size - 1;
setcsc(CSC_CR, getcsc(CSC_CR) | 0x2);
setcsc(CSC_PCCMDCR, getcsc(CSC_PCCMDCR) & ~1);
setpcc(PCC_MWSAR_1_Lo, (flash_base >> 12) & 0xff);
setpcc(PCC_MWSAR_1_Hi, (flash_base >> 20) & 0x3f);
setpcc(PCC_MWEAR_1_Lo, (flash_end >> 12) & 0xff);
setpcc(PCC_MWEAR_1_Hi, (flash_end >> 20) & 0x3f);
setpcc(PCC_MWAOR_1_Lo, ((0 - flash_base) >> 12) & 0xff);
setpcc(PCC_MWAOR_1_Hi, ((0 - flash_base)>> 20) & 0x3f);
setcsc(CSC_MMSWAR, getcsc(CSC_MMSWAR) & ~0x11);
setcsc(CSC_MMSWDSR, getcsc(CSC_MMSWDSR) & ~0x03);
setpcc(PCC_AWER_B, getpcc(PCC_AWER_B) | 0x02);
setcsc(CSC_CR, getcsc(CSC_CR) & ~0x2);
}
static void dnpc_unmap_flash(void)
{
setcsc(CSC_CR, getcsc(CSC_CR) | 0x2);
setpcc(PCC_AWER_B, getpcc(PCC_AWER_B) & ~0x02);
setcsc(CSC_CR, getcsc(CSC_CR) & ~0x2);
}
static void dnp_set_vpp(struct map_info *not_used, int on)
{
spin_lock_irq(&dnpc_spin);
if (on)
{
if(++vpp_counter == 1)
setcsc(CSC_RBWR, getcsc(CSC_RBWR) & ~0x4);
}
else
{
if(--vpp_counter == 0)
setcsc(CSC_RBWR, getcsc(CSC_RBWR) | 0x4);
else
BUG_ON(vpp_counter < 0);
}
spin_unlock_irq(&dnpc_spin);
}
static void adnp_set_vpp(struct map_info *not_used, int on)
{
spin_lock_irq(&dnpc_spin);
if (on)
{
if(++vpp_counter == 1)
setcsc(CSC_RBWR, getcsc(CSC_RBWR) & ~0x8);
}
else
{
if(--vpp_counter == 0)
setcsc(CSC_RBWR, getcsc(CSC_RBWR) | 0x8);
else
BUG_ON(vpp_counter < 0);
}
spin_unlock_irq(&dnpc_spin);
}
static int dnp_adnp_probe(void)
{
char *biosid, rc = -1;
biosid = (char*)ioremap(BIOSID_BASE, 16);
if(biosid)
{
if(!strcmp(biosid, ID_DNPC))
rc = 1;
else if(!strcmp(biosid, ID_ADNP))
rc = 0;
}
iounmap((void *)biosid);
return(rc);
}
static int __init init_dnpc(void)
{
int is_dnp;
if((is_dnp = dnp_adnp_probe()) < 0)
return -ENXIO;
if(is_dnp)
{
int i;
dnpc_map.size = DNP_WINDOW_SIZE;
dnpc_map.set_vpp = dnp_set_vpp;
partition_info[2].size = 0xf0000;
++dnpc_map.name;
for(i = 0; i < NUM_PARTITIONS; i++)
++partition_info[i].name;
higlvl_partition_info[1].size = DNP_WINDOW_SIZE -
CONFIG_MTD_DILNETPC_BOOTSIZE - 0x20000;
for(i = 0; i < NUM_HIGHLVL_PARTITIONS; i++)
++higlvl_partition_info[i].name;
}
printk(KERN_NOTICE "DIL/Net %s flash: 0x%lx at 0x%llx\n",
is_dnp ? "DNPC" : "ADNP", dnpc_map.size, (unsigned long long)dnpc_map.phys);
dnpc_map.virt = ioremap_nocache(dnpc_map.phys, dnpc_map.size);
dnpc_map_flash(dnpc_map.phys, dnpc_map.size);
if (!dnpc_map.virt) {
printk("Failed to ioremap_nocache\n");
return -EIO;
}
simple_map_init(&dnpc_map);
printk("FLASH virtual address: 0x%p\n", dnpc_map.virt);
mymtd = do_map_probe("jedec_probe", &dnpc_map);
if (!mymtd)
mymtd = do_map_probe("cfi_probe", &dnpc_map);
if (!mymtd)
if((mymtd = do_map_probe("map_rom", &dnpc_map)))
mymtd->erasesize = 0x10000;
if (!mymtd) {
iounmap(dnpc_map.virt);
return -ENXIO;
}
mymtd->owner = THIS_MODULE;
partition_info[0].mtdp = &lowlvl_parts[0];
partition_info[1].mtdp = &lowlvl_parts[2];
partition_info[2].mtdp = &lowlvl_parts[1];
partition_info[3].mtdp = &lowlvl_parts[3];
mtd_device_register(mymtd, partition_info, NUM_PARTITIONS);
merged_mtd = mtd_concat_create(lowlvl_parts, NUM_PARTITIONS, "(A)DNP Flash Concatenated");
if(merged_mtd)
{
mtd_device_register(merged_mtd, higlvl_partition_info,
NUM_HIGHLVL_PARTITIONS);
}
return 0;
}
static void __exit cleanup_dnpc(void)
{
if(merged_mtd) {
mtd_device_unregister(merged_mtd);
mtd_concat_destroy(merged_mtd);
}
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (dnpc_map.virt) {
iounmap(dnpc_map.virt);
dnpc_unmap_flash();
dnpc_map.virt = NULL;
}
}
