static int pmc551_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct mypriv *priv = mtd->priv;
u32 soff_hi, soff_lo;
u32 eoff_hi, eoff_lo;
unsigned long end;
u_char *ptr;
size_t retlen;
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_erase(pos:%ld, len:%ld)\n", (long)instr->addr,
(long)instr->len);
#endif
end = instr->addr + instr->len - 1;
eoff_hi = end & ~(priv->asize - 1);
soff_hi = instr->addr & ~(priv->asize - 1);
eoff_lo = end & (priv->asize - 1);
soff_lo = instr->addr & (priv->asize - 1);
pmc551_point(mtd, instr->addr, instr->len, &retlen,
(void **)&ptr, NULL);
if (soff_hi == eoff_hi || mtd->size == priv->asize) {
memset(ptr, 0xff, instr->len);
} else {
while (soff_hi != eoff_hi) {
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_erase() soff_hi: %ld, "
"eoff_hi: %ld\n", (long)soff_hi, (long)eoff_hi);
#endif
memset(ptr, 0xff, priv->asize);
if (soff_hi + priv->asize >= mtd->size) {
goto out;
}
soff_hi += priv->asize;
pmc551_point(mtd, (priv->base_map0 | soff_hi),
priv->asize, &retlen,
(void **)&ptr, NULL);
}
memset(ptr, 0xff, eoff_lo);
}
out:
instr->state = MTD_ERASE_DONE;
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_erase() done\n");
#endif
mtd_erase_callback(instr);
return 0;
}
static int pmc551_point(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, void **virt, resource_size_t *phys)
{
struct mypriv *priv = mtd->priv;
u32 soff_hi;
u32 soff_lo;
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_point(%ld, %ld)\n", (long)from, (long)len);
#endif
soff_hi = from & ~(priv->asize - 1);
soff_lo = from & (priv->asize - 1);
if (priv->curr_map0 != from) {
pci_write_config_dword(priv->dev, PMC551_PCI_MEM_MAP0,
(priv->base_map0 | soff_hi));
priv->curr_map0 = soff_hi;
}
*virt = priv->start + soff_lo;
*retlen = len;
return 0;
}
static int pmc551_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_unpoint()\n");
#endif
return 0;
}
static int pmc551_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t * retlen, u_char * buf)
{
struct mypriv *priv = mtd->priv;
u32 soff_hi, soff_lo;
u32 eoff_hi, eoff_lo;
unsigned long end;
u_char *ptr;
u_char *copyto = buf;
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_read(pos:%ld, len:%ld) asize: %ld\n",
(long)from, (long)len, (long)priv->asize);
#endif
end = from + len - 1;
soff_hi = from & ~(priv->asize - 1);
eoff_hi = end & ~(priv->asize - 1);
soff_lo = from & (priv->asize - 1);
eoff_lo = end & (priv->asize - 1);
pmc551_point(mtd, from, len, retlen, (void **)&ptr, NULL);
if (soff_hi == eoff_hi) {
memcpy(copyto, ptr, len);
copyto += len;
} else {
while (soff_hi != eoff_hi) {
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_read() soff_hi: %ld, "
"eoff_hi: %ld\n", (long)soff_hi, (long)eoff_hi);
#endif
memcpy(copyto, ptr, priv->asize);
copyto += priv->asize;
if (soff_hi + priv->asize >= mtd->size) {
goto out;
}
soff_hi += priv->asize;
pmc551_point(mtd, soff_hi, priv->asize, retlen,
(void **)&ptr, NULL);
}
memcpy(copyto, ptr, eoff_lo);
copyto += eoff_lo;
}
out:
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_read() done\n");
#endif
*retlen = copyto - buf;
return 0;
}
static int pmc551_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t * retlen, const u_char * buf)
{
struct mypriv *priv = mtd->priv;
u32 soff_hi, soff_lo;
u32 eoff_hi, eoff_lo;
unsigned long end;
u_char *ptr;
const u_char *copyfrom = buf;
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_write(pos:%ld, len:%ld) asize:%ld\n",
(long)to, (long)len, (long)priv->asize);
#endif
end = to + len - 1;
soff_hi = to & ~(priv->asize - 1);
eoff_hi = end & ~(priv->asize - 1);
soff_lo = to & (priv->asize - 1);
eoff_lo = end & (priv->asize - 1);
pmc551_point(mtd, to, len, retlen, (void **)&ptr, NULL);
if (soff_hi == eoff_hi) {
memcpy(ptr, copyfrom, len);
copyfrom += len;
} else {
while (soff_hi != eoff_hi) {
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_write() soff_hi: %ld, "
"eoff_hi: %ld\n", (long)soff_hi, (long)eoff_hi);
#endif
memcpy(ptr, copyfrom, priv->asize);
copyfrom += priv->asize;
if (soff_hi >= mtd->size) {
goto out;
}
soff_hi += priv->asize;
pmc551_point(mtd, soff_hi, priv->asize, retlen,
(void **)&ptr, NULL);
}
memcpy(ptr, copyfrom, eoff_lo);
copyfrom += eoff_lo;
}
out:
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551_write() done\n");
#endif
*retlen = copyfrom - buf;
return 0;
}
static int fixup_pmc551(struct pci_dev *dev)
{
#ifdef CONFIG_MTD_PMC551_BUGFIX
u32 dram_data;
#endif
u32 size, dcmd, cfg, dtmp;
u16 cmd, tmp, i;
u8 bcmd, counter;
if (!dev) {
return -ENODEV;
}
counter = 0;
pci_write_config_byte(dev, PMC551_SYS_CTRL_REG, 0xA5);
pci_read_config_byte(dev, PMC551_SYS_CTRL_REG, &bcmd);
for (i = 0; i < 10; i++) {
counter = 0;
bcmd &= ~0x80;
while (counter++ < 100) {
pci_write_config_byte(dev, PMC551_SYS_CTRL_REG, bcmd);
}
counter = 0;
bcmd |= 0x80;
while (counter++ < 100) {
pci_write_config_byte(dev, PMC551_SYS_CTRL_REG, bcmd);
}
}
bcmd |= (0x40 | 0x20);
pci_write_config_byte(dev, PMC551_SYS_CTRL_REG, bcmd);
pci_read_config_word(dev, PCI_COMMAND, &cmd);
tmp = cmd & ~(PCI_COMMAND_IO | PCI_COMMAND_MEMORY);
pci_write_config_word(dev, PCI_COMMAND, tmp);
pci_read_config_dword(dev, PMC551_PCI_MEM_MAP0, &dcmd);
dtmp = (dcmd | PMC551_PCI_MEM_MAP_ENABLE | PMC551_PCI_MEM_MAP_REG_EN);
pci_write_config_dword(dev, PMC551_PCI_MEM_MAP0, dtmp);
pci_read_config_dword(dev, PCI_BASE_ADDRESS_0, &cfg);
#ifndef CONFIG_MTD_PMC551_BUGFIX
pci_write_config_dword(dev, PCI_BASE_ADDRESS_0, ~0);
pci_read_config_dword(dev, PCI_BASE_ADDRESS_0, &size);
size = (size & PCI_BASE_ADDRESS_MEM_MASK);
size &= ~(size - 1);
pci_write_config_dword(dev, PCI_BASE_ADDRESS_0, cfg);
#else
pci_read_config_dword(dev, PMC551_DRAM_BLK0, &dram_data);
size = PMC551_DRAM_BLK_GET_SIZE(dram_data);
dram_data = PMC551_DRAM_BLK_SET_COL_MUX(dram_data, 0x5);
dram_data = PMC551_DRAM_BLK_SET_ROW_MUX(dram_data, 0x9);
pci_write_config_dword(dev, PMC551_DRAM_BLK0, dram_data);
pci_read_config_dword(dev, PMC551_DRAM_BLK1, &dram_data);
size += PMC551_DRAM_BLK_GET_SIZE(dram_data);
dram_data = PMC551_DRAM_BLK_SET_COL_MUX(dram_data, 0x5);
dram_data = PMC551_DRAM_BLK_SET_ROW_MUX(dram_data, 0x9);
pci_write_config_dword(dev, PMC551_DRAM_BLK1, dram_data);
pci_read_config_dword(dev, PMC551_DRAM_BLK2, &dram_data);
size += PMC551_DRAM_BLK_GET_SIZE(dram_data);
dram_data = PMC551_DRAM_BLK_SET_COL_MUX(dram_data, 0x5);
dram_data = PMC551_DRAM_BLK_SET_ROW_MUX(dram_data, 0x9);
pci_write_config_dword(dev, PMC551_DRAM_BLK2, dram_data);
pci_read_config_dword(dev, PMC551_DRAM_BLK3, &dram_data);
size += PMC551_DRAM_BLK_GET_SIZE(dram_data);
dram_data = PMC551_DRAM_BLK_SET_COL_MUX(dram_data, 0x5);
dram_data = PMC551_DRAM_BLK_SET_ROW_MUX(dram_data, 0x9);
pci_write_config_dword(dev, PMC551_DRAM_BLK3, dram_data);
if ((size &= PCI_BASE_ADDRESS_MEM_MASK) == 0) {
return -ENODEV;
}
#endif
if ((cfg & PCI_BASE_ADDRESS_SPACE) != PCI_BASE_ADDRESS_SPACE_MEMORY) {
return -ENODEV;
}
pci_write_config_word(dev, PMC551_SDRAM_MA, 0x0400);
pci_write_config_word(dev, PMC551_SDRAM_CMD, 0x00bf);
do {
pci_read_config_word(dev, PMC551_SDRAM_CMD, &cmd);
if (counter++ > 100)
break;
} while ((PCI_COMMAND_IO) & cmd);
for (i = 1; i <= 8; i++) {
pci_write_config_word(dev, PMC551_SDRAM_CMD, 0x0df);
counter = 0;
do {
pci_read_config_word(dev, PMC551_SDRAM_CMD, &cmd);
if (counter++ > 100)
break;
} while ((PCI_COMMAND_IO) & cmd);
}
pci_write_config_word(dev, PMC551_SDRAM_MA, 0x0020);
pci_write_config_word(dev, PMC551_SDRAM_CMD, 0x0ff);
counter = 0;
do {
pci_read_config_word(dev, PMC551_SDRAM_CMD, &cmd);
if (counter++ > 100)
break;
} while ((PCI_COMMAND_IO) & cmd);
pci_read_config_dword(dev, PMC551_DRAM_CFG, &dcmd);
dcmd |= 0x02000000;
pci_write_config_dword(dev, PMC551_DRAM_CFG, dcmd);
pci_read_config_word(dev, PCI_STATUS, &cmd);
if ((cmd & PCI_COMMAND_FAST_BACK) == 0) {
cmd |= PCI_COMMAND_FAST_BACK;
pci_write_config_word(dev, PCI_STATUS, cmd);
}
if ((cmd & PCI_STATUS_DEVSEL_MASK) != 0x0) {
cmd &= ~PCI_STATUS_DEVSEL_MASK;
pci_write_config_word(dev, PCI_STATUS, cmd);
}
pci_write_config_word(dev, PCI_COMMAND,
PCI_COMMAND_MEMORY | PCI_COMMAND_IO);
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551: %d%sB (0x%x) of %sprefetchable memory at "
"0x%llx\n", (size < 1024) ? size : (size < 1048576) ?
size >> 10 : size >> 20,
(size < 1024) ? "" : (size < 1048576) ? "Ki" : "Mi", size,
((dcmd & (0x1 << 3)) == 0) ? "non-" : "",
(unsigned long long)pci_resource_start(dev, 0));
pci_read_config_dword(dev, PMC551_DRAM_BLK0, &dcmd);
printk(KERN_DEBUG "pmc551: DRAM_BLK0 Flags: %s,%s\n"
"pmc551: DRAM_BLK0 Size: %d at %d\n"
"pmc551: DRAM_BLK0 Row MUX: %d, Col MUX: %d\n",
(((0x1 << 1) & dcmd) == 0) ? "RW" : "RO",
(((0x1 << 0) & dcmd) == 0) ? "Off" : "On",
PMC551_DRAM_BLK_GET_SIZE(dcmd),
((dcmd >> 20) & 0x7FF), ((dcmd >> 13) & 0x7),
((dcmd >> 9) & 0xF));
pci_read_config_dword(dev, PMC551_DRAM_BLK1, &dcmd);
printk(KERN_DEBUG "pmc551: DRAM_BLK1 Flags: %s,%s\n"
"pmc551: DRAM_BLK1 Size: %d at %d\n"
"pmc551: DRAM_BLK1 Row MUX: %d, Col MUX: %d\n",
(((0x1 << 1) & dcmd) == 0) ? "RW" : "RO",
(((0x1 << 0) & dcmd) == 0) ? "Off" : "On",
PMC551_DRAM_BLK_GET_SIZE(dcmd),
((dcmd >> 20) & 0x7FF), ((dcmd >> 13) & 0x7),
((dcmd >> 9) & 0xF));
pci_read_config_dword(dev, PMC551_DRAM_BLK2, &dcmd);
printk(KERN_DEBUG "pmc551: DRAM_BLK2 Flags: %s,%s\n"
"pmc551: DRAM_BLK2 Size: %d at %d\n"
"pmc551: DRAM_BLK2 Row MUX: %d, Col MUX: %d\n",
(((0x1 << 1) & dcmd) == 0) ? "RW" : "RO",
(((0x1 << 0) & dcmd) == 0) ? "Off" : "On",
PMC551_DRAM_BLK_GET_SIZE(dcmd),
((dcmd >> 20) & 0x7FF), ((dcmd >> 13) & 0x7),
((dcmd >> 9) & 0xF));
pci_read_config_dword(dev, PMC551_DRAM_BLK3, &dcmd);
printk(KERN_DEBUG "pmc551: DRAM_BLK3 Flags: %s,%s\n"
"pmc551: DRAM_BLK3 Size: %d at %d\n"
"pmc551: DRAM_BLK3 Row MUX: %d, Col MUX: %d\n",
(((0x1 << 1) & dcmd) == 0) ? "RW" : "RO",
(((0x1 << 0) & dcmd) == 0) ? "Off" : "On",
PMC551_DRAM_BLK_GET_SIZE(dcmd),
((dcmd >> 20) & 0x7FF), ((dcmd >> 13) & 0x7),
((dcmd >> 9) & 0xF));
pci_read_config_word(dev, PCI_COMMAND, &cmd);
printk(KERN_DEBUG "pmc551: Memory Access %s\n",
(((0x1 << 1) & cmd) == 0) ? "off" : "on");
printk(KERN_DEBUG "pmc551: I/O Access %s\n",
(((0x1 << 0) & cmd) == 0) ? "off" : "on");
pci_read_config_word(dev, PCI_STATUS, &cmd);
printk(KERN_DEBUG "pmc551: Devsel %s\n",
((PCI_STATUS_DEVSEL_MASK & cmd) == 0x000) ? "Fast" :
((PCI_STATUS_DEVSEL_MASK & cmd) == 0x200) ? "Medium" :
((PCI_STATUS_DEVSEL_MASK & cmd) == 0x400) ? "Slow" : "Invalid");
printk(KERN_DEBUG "pmc551: %sFast Back-to-Back\n",
((PCI_COMMAND_FAST_BACK & cmd) == 0) ? "Not " : "");
pci_read_config_byte(dev, PMC551_SYS_CTRL_REG, &bcmd);
printk(KERN_DEBUG "pmc551: EEPROM is under %s control\n"
"pmc551: System Control Register is %slocked to PCI access\n"
"pmc551: System Control Register is %slocked to EEPROM access\n",
(bcmd & 0x1) ? "software" : "hardware",
(bcmd & 0x20) ? "" : "un", (bcmd & 0x40) ? "" : "un");
#endif
return size;
}
static int __init init_pmc551(void)
{
struct pci_dev *PCI_Device = NULL;
struct mypriv *priv;
int found = 0;
struct mtd_info *mtd;
int length = 0;
if (msize) {
msize = (1 << (ffs(msize) - 1)) << 20;
if (msize > (1 << 30)) {
printk(KERN_NOTICE "pmc551: Invalid memory size [%d]\n",
msize);
return -EINVAL;
}
}
if (asize) {
asize = (1 << (ffs(asize) - 1)) << 20;
if (asize > (1 << 30)) {
printk(KERN_NOTICE "pmc551: Invalid aperture size "
"[%d]\n", asize);
return -EINVAL;
}
}
printk(KERN_INFO PMC551_VERSION);
for (;;) {
if ((PCI_Device = pci_get_device(PCI_VENDOR_ID_V3_SEMI,
PCI_DEVICE_ID_V3_SEMI_V370PDC,
PCI_Device)) == NULL) {
break;
}
printk(KERN_NOTICE "pmc551: Found PCI V370PDC at 0x%llx\n",
(unsigned long long)pci_resource_start(PCI_Device, 0));
if ((length = fixup_pmc551(PCI_Device)) <= 0) {
printk(KERN_NOTICE "pmc551: Cannot init SDRAM\n");
break;
}
if (msize) {
length = msize;
printk(KERN_NOTICE "pmc551: Using specified memory "
"size 0x%x\n", length);
} else {
msize = length;
}
mtd = kzalloc(sizeof(struct mtd_info), GFP_KERNEL);
if (!mtd)
break;
priv = kzalloc(sizeof(struct mypriv), GFP_KERNEL);
if (!priv) {
kfree(mtd);
break;
}
mtd->priv = priv;
priv->dev = PCI_Device;
if (asize > length) {
printk(KERN_NOTICE "pmc551: reducing aperture size to "
"fit %dM\n", length >> 20);
priv->asize = asize = length;
} else if (asize == 0 || asize == length) {
printk(KERN_NOTICE "pmc551: Using existing aperture "
"size %dM\n", length >> 20);
priv->asize = asize = length;
} else {
printk(KERN_NOTICE "pmc551: Using specified aperture "
"size %dM\n", asize >> 20);
priv->asize = asize;
}
priv->start = pci_iomap(PCI_Device, 0, priv->asize);
if (!priv->start) {
printk(KERN_NOTICE "pmc551: Unable to map IO space\n");
kfree(mtd->priv);
kfree(mtd);
break;
}
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551: setting aperture to %d\n",
ffs(priv->asize >> 20) - 1);
#endif
priv->base_map0 = (PMC551_PCI_MEM_MAP_REG_EN
| PMC551_PCI_MEM_MAP_ENABLE
| (ffs(priv->asize >> 20) - 1) << 4);
priv->curr_map0 = priv->base_map0;
pci_write_config_dword(priv->dev, PMC551_PCI_MEM_MAP0,
priv->curr_map0);
#ifdef CONFIG_MTD_PMC551_DEBUG
printk(KERN_DEBUG "pmc551: aperture set to %d\n",
(priv->base_map0 & 0xF0) >> 4);
#endif
mtd->size = msize;
mtd->flags = MTD_CAP_RAM;
mtd->_erase = pmc551_erase;
mtd->_read = pmc551_read;
mtd->_write = pmc551_write;
mtd->_point = pmc551_point;
mtd->_unpoint = pmc551_unpoint;
mtd->type = MTD_RAM;
mtd->name = "PMC551 RAM board";
mtd->erasesize = 0x10000;
mtd->writesize = 1;
mtd->owner = THIS_MODULE;
if (mtd_device_register(mtd, NULL, 0)) {
printk(KERN_NOTICE "pmc551: Failed to register new device\n");
pci_iounmap(PCI_Device, priv->start);
kfree(mtd->priv);
kfree(mtd);
break;
}
pci_dev_get(PCI_Device);
printk(KERN_NOTICE "Registered pmc551 memory device.\n");
printk(KERN_NOTICE "Mapped %dMiB of memory from 0x%p to 0x%p\n",
priv->asize >> 20,
priv->start, priv->start + priv->asize);
printk(KERN_NOTICE "Total memory is %d%sB\n",
(length < 1024) ? length :
(length < 1048576) ? length >> 10 : length >> 20,
(length < 1024) ? "" : (length < 1048576) ? "Ki" : "Mi");
priv->nextpmc551 = pmc551list;
pmc551list = mtd;
found++;
}
if (PCI_Device)
pci_dev_put(PCI_Device);
if (!pmc551list) {
printk(KERN_NOTICE "pmc551: not detected\n");
return -ENODEV;
} else {
printk(KERN_NOTICE "pmc551: %d pmc551 devices loaded\n", found);
return 0;
}
}
static void __exit cleanup_pmc551(void)
{
int found = 0;
struct mtd_info *mtd;
struct mypriv *priv;
while ((mtd = pmc551list)) {
priv = mtd->priv;
pmc551list = priv->nextpmc551;
if (priv->start) {
printk(KERN_DEBUG "pmc551: unmapping %dMiB starting at "
"0x%p\n", priv->asize >> 20, priv->start);
pci_iounmap(priv->dev, priv->start);
}
pci_dev_put(priv->dev);
kfree(mtd->priv);
mtd_device_unregister(mtd);
kfree(mtd);
found++;
}
printk(KERN_NOTICE "pmc551: %d pmc551 devices unloaded\n", found);
}
