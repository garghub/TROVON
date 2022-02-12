static __u8 read8 (__u32 offset)
{
volatile __u8 *data = (__u8 *) (FLASH_OFFSET + offset);
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(): 0x%.8x -> 0x%.2x\n", __func__, offset, *data);
#endif
return (*data);
}
static __u32 read32 (__u32 offset)
{
volatile __u32 *data = (__u32 *) (FLASH_OFFSET + offset);
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(): 0x%.8x -> 0x%.8x\n", __func__, offset, *data);
#endif
return (*data);
}
static void write32 (__u32 x,__u32 offset)
{
volatile __u32 *data = (__u32 *) (FLASH_OFFSET + offset);
*data = x;
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(): 0x%.8x <- 0x%.8x\n", __func__, offset, *data);
#endif
}
static int flash_probe (void)
{
__u32 manufacturer,devtype;
write32 (DATA_TO_FLASH (READ_ID_CODES),0x00000000);
manufacturer = FLASH_TO_DATA (read32 (ADDR_TO_FLASH_U2 (0x00000000)));
devtype = FLASH_TO_DATA (read32 (ADDR_TO_FLASH_U2 (0x00000001)));
write32 (DATA_TO_FLASH (READ_ARRAY),0x00000000);
return (manufacturer == FLASH_MANUFACTURER && (devtype == FLASH_DEVICE_16mbit_TOP || devtype == FLASH_DEVICE_16mbit_BOTTOM));
}
static inline int erase_block (__u32 offset)
{
__u32 status;
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(): 0x%.8x\n", __func__, offset);
#endif
write32 (DATA_TO_FLASH (ERASE_SETUP),offset);
write32 (DATA_TO_FLASH (ERASE_CONFIRM),offset);
do
{
write32 (DATA_TO_FLASH (STATUS_READ),offset);
status = FLASH_TO_DATA (read32 (offset));
}
while ((~status & STATUS_BUSY) != 0);
write32 (DATA_TO_FLASH (READ_ARRAY),offset);
if ((status & STATUS_ERASE_ERR))
{
printk (KERN_WARNING "%s: erase error at address 0x%.8x.\n",module_name,offset);
return (0);
}
return (1);
}
static int flash_erase (struct mtd_info *mtd,struct erase_info *instr)
{
__u32 addr,len;
int i,first;
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(addr = 0x%.8x, len = %d)\n", __func__, instr->addr, instr->len);
#endif
if (instr->addr + instr->len > mtd->size) return (-EINVAL);
for (i = 0; i < mtd->numeraseregions && instr->addr >= mtd->eraseregions[i].offset; i++) ;
i--;
if (i < 0 || (instr->addr & (mtd->eraseregions[i].erasesize - 1)))
return -EINVAL;
first = i;
for (; i < mtd->numeraseregions && instr->addr + instr->len >= mtd->eraseregions[i].offset; i++) ;
i--;
if (i < 0 || ((instr->addr + instr->len) & (mtd->eraseregions[i].erasesize - 1)))
return -EINVAL;
addr = instr->addr;
len = instr->len;
i = first;
while (len)
{
if (!erase_block (addr))
{
instr->state = MTD_ERASE_FAILED;
return (-EIO);
}
addr += mtd->eraseregions[i].erasesize;
len -= mtd->eraseregions[i].erasesize;
if (addr == mtd->eraseregions[i].offset + (mtd->eraseregions[i].erasesize * mtd->eraseregions[i].numblocks)) i++;
}
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return (0);
}
static int flash_read (struct mtd_info *mtd,loff_t from,size_t len,size_t *retlen,u_char *buf)
{
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(from = 0x%.8x, len = %d)\n", __func__, (__u32)from, len);
#endif
if (!len) return (0);
if (from + len > mtd->size) return (-EINVAL);
*retlen = len;
if (from & (BUSWIDTH - 1))
{
int gap = BUSWIDTH - (from & (BUSWIDTH - 1));
while (len && gap--) *buf++ = read8 (from++), len--;
}
while (len >= BUSWIDTH)
{
*((__u32 *) buf) = read32 (from);
buf += BUSWIDTH;
from += BUSWIDTH;
len -= BUSWIDTH;
}
if (len & (BUSWIDTH - 1))
while (len--) *buf++ = read8 (from++);
return (0);
}
static inline int write_dword (__u32 offset,__u32 x)
{
__u32 status;
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(): 0x%.8x <- 0x%.8x\n", __func__, offset, x);
#endif
write32 (DATA_TO_FLASH (PGM_SETUP),offset);
write32 (x,offset);
do
{
write32 (DATA_TO_FLASH (STATUS_READ),offset);
status = FLASH_TO_DATA (read32 (offset));
}
while ((~status & STATUS_BUSY) != 0);
write32 (DATA_TO_FLASH (READ_ARRAY),offset);
if ((status & STATUS_PGM_ERR) || read32 (offset) != x)
{
printk (KERN_WARNING "%s: write error at address 0x%.8x.\n",module_name,offset);
return (0);
}
return (1);
}
static int flash_write (struct mtd_info *mtd,loff_t to,size_t len,size_t *retlen,const u_char *buf)
{
__u8 tmp[4];
int i,n;
#ifdef LART_DEBUG
printk (KERN_DEBUG "%s(to = 0x%.8x, len = %d)\n", __func__, (__u32)to, len);
#endif
*retlen = 0;
if (!len) return (0);
if (to + len > mtd->size) return (-EINVAL);
if (to & (BUSWIDTH - 1))
{
__u32 aligned = to & ~(BUSWIDTH - 1);
int gap = to - aligned;
i = n = 0;
while (gap--) tmp[i++] = 0xFF;
while (len && i < BUSWIDTH) tmp[i++] = buf[n++], len--;
while (i < BUSWIDTH) tmp[i++] = 0xFF;
if (!write_dword (aligned,*((__u32 *) tmp))) return (-EIO);
to += n;
buf += n;
*retlen += n;
}
while (len >= BUSWIDTH)
{
if (!write_dword (to,*((__u32 *) buf))) return (-EIO);
to += BUSWIDTH;
buf += BUSWIDTH;
*retlen += BUSWIDTH;
len -= BUSWIDTH;
}
if (len & (BUSWIDTH - 1))
{
i = n = 0;
while (len--) tmp[i++] = buf[n++];
while (i < BUSWIDTH) tmp[i++] = 0xFF;
if (!write_dword (to,*((__u32 *) tmp))) return (-EIO);
*retlen += n;
}
return (0);
}
static int __init lart_flash_init (void)
{
int result;
memset (&mtd,0,sizeof (mtd));
printk ("MTD driver for LART. Written by Abraham vd Merwe <abraham@2d3d.co.za>\n");
printk ("%s: Probing for 28F160x3 flash on LART...\n",module_name);
if (!flash_probe ())
{
printk (KERN_WARNING "%s: Found no LART compatible flash device\n",module_name);
return (-ENXIO);
}
printk ("%s: This looks like a LART board to me.\n",module_name);
mtd.name = module_name;
mtd.type = MTD_NORFLASH;
mtd.writesize = 1;
mtd.flags = MTD_CAP_NORFLASH;
mtd.size = FLASH_BLOCKSIZE_PARAM * FLASH_NUMBLOCKS_16m_PARAM + FLASH_BLOCKSIZE_MAIN * FLASH_NUMBLOCKS_16m_MAIN;
mtd.erasesize = FLASH_BLOCKSIZE_MAIN;
mtd.numeraseregions = ARRAY_SIZE(erase_regions);
mtd.eraseregions = erase_regions;
mtd.erase = flash_erase;
mtd.read = flash_read;
mtd.write = flash_write;
mtd.owner = THIS_MODULE;
#ifdef LART_DEBUG
printk (KERN_DEBUG
"mtd.name = %s\n"
"mtd.size = 0x%.8x (%uM)\n"
"mtd.erasesize = 0x%.8x (%uK)\n"
"mtd.numeraseregions = %d\n",
mtd.name,
mtd.size,mtd.size / (1024*1024),
mtd.erasesize,mtd.erasesize / 1024,
mtd.numeraseregions);
if (mtd.numeraseregions)
for (result = 0; result < mtd.numeraseregions; result++)
printk (KERN_DEBUG
"\n\n"
"mtd.eraseregions[%d].offset = 0x%.8x\n"
"mtd.eraseregions[%d].erasesize = 0x%.8x (%uK)\n"
"mtd.eraseregions[%d].numblocks = %d\n",
result,mtd.eraseregions[result].offset,
result,mtd.eraseregions[result].erasesize,mtd.eraseregions[result].erasesize / 1024,
result,mtd.eraseregions[result].numblocks);
printk ("\npartitions = %d\n", ARRAY_SIZE(lart_partitions));
for (result = 0; result < ARRAY_SIZE(lart_partitions); result++)
printk (KERN_DEBUG
"\n\n"
"lart_partitions[%d].name = %s\n"
"lart_partitions[%d].offset = 0x%.8x\n"
"lart_partitions[%d].size = 0x%.8x (%uK)\n",
result,lart_partitions[result].name,
result,lart_partitions[result].offset,
result,lart_partitions[result].size,lart_partitions[result].size / 1024);
#endif
result = mtd_device_register(&mtd, lart_partitions,
ARRAY_SIZE(lart_partitions));
return (result);
}
static void __exit lart_flash_exit (void)
{
mtd_device_unregister(&mtd);
}
