void cfi_udelay(int us)
{
if (us >= 1000) {
msleep((us+999)/1000);
} else {
udelay(us);
cond_resched();
}
}
uint32_t cfi_build_cmd_addr(uint32_t cmd_ofs,
struct map_info *map, struct cfi_private *cfi)
{
unsigned bankwidth = map_bankwidth(map);
unsigned interleave = cfi_interleave(cfi);
unsigned type = cfi->device_type;
uint32_t addr;
addr = (cmd_ofs * type) * interleave;
if (((type * interleave) > bankwidth) && ((cmd_ofs & 0xff) == 0xaa))
addr |= (type >> 1)*interleave;
return addr;
}
map_word cfi_build_cmd(u_long cmd, struct map_info *map, struct cfi_private *cfi)
{
map_word val = { {0} };
int wordwidth, words_per_bus, chip_mode, chips_per_word;
unsigned long onecmd;
int i;
if (map_bankwidth_is_large(map)) {
wordwidth = sizeof(unsigned long);
words_per_bus = (map_bankwidth(map)) / wordwidth;
} else {
wordwidth = map_bankwidth(map);
words_per_bus = 1;
}
chip_mode = map_bankwidth(map) / cfi_interleave(cfi);
chips_per_word = wordwidth * cfi_interleave(cfi) / map_bankwidth(map);
switch (chip_mode) {
default: BUG();
case 1:
onecmd = cmd;
break;
case 2:
onecmd = cpu_to_cfi16(map, cmd);
break;
case 4:
onecmd = cpu_to_cfi32(map, cmd);
break;
}
switch (chips_per_word) {
default: BUG();
#if BITS_PER_LONG >= 64
case 8:
onecmd |= (onecmd << (chip_mode * 32));
#endif
case 4:
onecmd |= (onecmd << (chip_mode * 16));
case 2:
onecmd |= (onecmd << (chip_mode * 8));
case 1:
;
}
for (i=0; i < words_per_bus; i++) {
val.x[i] = onecmd;
}
return val;
}
unsigned long cfi_merge_status(map_word val, struct map_info *map,
struct cfi_private *cfi)
{
int wordwidth, words_per_bus, chip_mode, chips_per_word;
unsigned long onestat, res = 0;
int i;
if (map_bankwidth_is_large(map)) {
wordwidth = sizeof(unsigned long);
words_per_bus = (map_bankwidth(map)) / wordwidth;
} else {
wordwidth = map_bankwidth(map);
words_per_bus = 1;
}
chip_mode = map_bankwidth(map) / cfi_interleave(cfi);
chips_per_word = wordwidth * cfi_interleave(cfi) / map_bankwidth(map);
onestat = val.x[0];
for (i=1; i < words_per_bus; i++) {
onestat |= val.x[i];
}
res = onestat;
switch(chips_per_word) {
default: BUG();
#if BITS_PER_LONG >= 64
case 8:
res |= (onestat >> (chip_mode * 32));
#endif
case 4:
res |= (onestat >> (chip_mode * 16));
case 2:
res |= (onestat >> (chip_mode * 8));
case 1:
;
}
switch (chip_mode) {
case 1:
break;
case 2:
res = cfi16_to_cpu(map, res);
break;
case 4:
res = cfi32_to_cpu(map, res);
break;
default: BUG();
}
return res;
}
uint32_t cfi_send_gen_cmd(u_char cmd, uint32_t cmd_addr, uint32_t base,
struct map_info *map, struct cfi_private *cfi,
int type, map_word *prev_val)
{
map_word val;
uint32_t addr = base + cfi_build_cmd_addr(cmd_addr, map, cfi);
val = cfi_build_cmd(cmd, map, cfi);
if (prev_val)
*prev_val = map_read(map, addr);
map_write(map, val, addr);
return addr - base;
}
int __xipram cfi_qry_present(struct map_info *map, __u32 base,
struct cfi_private *cfi)
{
int osf = cfi->interleave * cfi->device_type;
map_word val[3];
map_word qry[3];
qry[0] = cfi_build_cmd('Q', map, cfi);
qry[1] = cfi_build_cmd('R', map, cfi);
qry[2] = cfi_build_cmd('Y', map, cfi);
val[0] = map_read(map, base + osf*0x10);
val[1] = map_read(map, base + osf*0x11);
val[2] = map_read(map, base + osf*0x12);
if (!map_word_equal(map, qry[0], val[0]))
return 0;
if (!map_word_equal(map, qry[1], val[1]))
return 0;
if (!map_word_equal(map, qry[2], val[2]))
return 0;
return 1;
}
int __xipram cfi_qry_mode_on(uint32_t base, struct map_info *map,
struct cfi_private *cfi)
{
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x98, 0x55, base, map, cfi, cfi->device_type, NULL);
if (cfi_qry_present(map, base, cfi))
return 1;
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0xFF, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x98, 0x55, base, map, cfi, cfi->device_type, NULL);
if (cfi_qry_present(map, base, cfi))
return 1;
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x98, 0x555, base, map, cfi, cfi->device_type, NULL);
if (cfi_qry_present(map, base, cfi))
return 1;
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0xAA, 0x5555, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x55, 0x2AAA, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x98, 0x5555, base, map, cfi, cfi->device_type, NULL);
if (cfi_qry_present(map, base, cfi))
return 1;
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0xAA, 0x555, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x55, 0x2AA, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x98, 0x555, base, map, cfi, cfi->device_type, NULL);
if (cfi_qry_present(map, base, cfi))
return 1;
return 0;
}
void __xipram cfi_qry_mode_off(uint32_t base, struct map_info *map,
struct cfi_private *cfi)
{
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0xFF, 0, base, map, cfi, cfi->device_type, NULL);
if ((cfi->mfr == CFI_MFR_ST) && (cfi->id == 0x227E || cfi->id == 0x7E))
cfi_send_gen_cmd(0xF0, 0, base, map, cfi, cfi->device_type, NULL);
}
struct cfi_extquery *
__xipram cfi_read_pri(struct map_info *map, __u16 adr, __u16 size, const char* name)
{
struct cfi_private *cfi = map->fldrv_priv;
__u32 base = 0;
int ofs_factor = cfi->interleave * cfi->device_type;
int i;
struct cfi_extquery *extp = NULL;
if (!adr)
goto out;
printk(KERN_INFO "%s Extended Query Table at 0x%4.4X\n", name, adr);
extp = kmalloc(size, GFP_KERNEL);
if (!extp)
goto out;
#ifdef CONFIG_MTD_XIP
local_irq_disable();
#endif
cfi_qry_mode_on(base, map, cfi);
for (i=0; i<size; i++) {
((unsigned char *)extp)[i] =
cfi_read_query(map, base+((adr+i)*ofs_factor));
}
cfi_qry_mode_off(base, map, cfi);
#ifdef CONFIG_MTD_XIP
(void) map_read(map, base);
xip_iprefetch();
local_irq_enable();
#endif
out: return extp;
}
void cfi_fixup(struct mtd_info *mtd, struct cfi_fixup *fixups)
{
struct map_info *map = mtd->priv;
struct cfi_private *cfi = map->fldrv_priv;
struct cfi_fixup *f;
for (f=fixups; f->fixup; f++) {
if (((f->mfr == CFI_MFR_ANY) || (f->mfr == cfi->mfr)) &&
((f->id == CFI_ID_ANY) || (f->id == cfi->id))) {
f->fixup(mtd);
}
}
}
int cfi_varsize_frob(struct mtd_info *mtd, varsize_frob_t frob,
loff_t ofs, size_t len, void *thunk)
{
struct map_info *map = mtd->priv;
struct cfi_private *cfi = map->fldrv_priv;
unsigned long adr;
int chipnum, ret = 0;
int i, first;
struct mtd_erase_region_info *regions = mtd->eraseregions;
i = 0;
while (i < mtd->numeraseregions && ofs >= regions[i].offset)
i++;
i--;
if (ofs & (regions[i].erasesize-1))
return -EINVAL;
first = i;
while (i<mtd->numeraseregions && (ofs + len) >= regions[i].offset)
i++;
i--;
if ((ofs + len) & (regions[i].erasesize-1))
return -EINVAL;
chipnum = ofs >> cfi->chipshift;
adr = ofs - (chipnum << cfi->chipshift);
i=first;
while(len) {
int size = regions[i].erasesize;
ret = (*frob)(map, &cfi->chips[chipnum], adr, size, thunk);
if (ret)
return ret;
adr += size;
ofs += size;
len -= size;
if (ofs == regions[i].offset + size * regions[i].numblocks)
i++;
if (adr >> cfi->chipshift) {
adr = 0;
chipnum++;
if (chipnum >= cfi->numchips)
break;
}
}
return 0;
}
