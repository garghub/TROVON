static u32 word_sum(void *words, int num)
{
u32 *p = words;
u32 sum = 0;
while (num--)
sum += *p++;
return sum;
}
static int
afs_read_footer(struct mtd_info *mtd, u_int *img_start, u_int *iis_start,
u_int off, u_int mask)
{
struct footer_struct fs;
u_int ptr = off + mtd->erasesize - sizeof(fs);
size_t sz;
int ret;
ret = mtd_read(mtd, ptr, sizeof(fs), &sz, (u_char *)&fs);
if (ret >= 0 && sz != sizeof(fs))
ret = -EINVAL;
if (ret < 0) {
printk(KERN_ERR "AFS: mtd read failed at 0x%x: %d\n",
ptr, ret);
return ret;
}
ret = 1;
if (fs.signature != 0xa0ffff9f)
ret = 0;
if (word_sum(&fs, sizeof(fs) / sizeof(u32)) != 0xffffffff)
ret = 0;
if (fs.type == 2)
ret = 0;
*iis_start = fs.image_info_base & mask;
*img_start = fs.image_start & mask;
if (*iis_start >= ptr)
ret = 0;
if (*img_start > off)
ret = 0;
return ret;
}
static int
afs_read_iis(struct mtd_info *mtd, struct image_info_struct *iis, u_int ptr)
{
size_t sz;
int ret, i;
memset(iis, 0, sizeof(*iis));
ret = mtd_read(mtd, ptr, sizeof(*iis), &sz, (u_char *)iis);
if (ret < 0)
goto failed;
if (sz != sizeof(*iis)) {
ret = -EINVAL;
goto failed;
}
ret = 0;
for (i = 0; i < sizeof(iis->name); i++)
if (iis->name[i] == '\0')
break;
if (i < sizeof(iis->name))
ret = 1;
return ret;
failed:
printk(KERN_ERR "AFS: mtd read failed at 0x%x: %d\n",
ptr, ret);
return ret;
}
static int parse_afs_partitions(struct mtd_info *mtd,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct mtd_partition *parts;
u_int mask, off, idx, sz;
int ret = 0;
char *str;
mask = mtd->size - 1;
for (idx = off = sz = 0; off < mtd->size; off += mtd->erasesize) {
struct image_info_struct iis;
u_int iis_ptr, img_ptr;
ret = afs_read_footer(mtd, &img_ptr, &iis_ptr, off, mask);
if (ret < 0)
break;
if (ret == 0)
continue;
ret = afs_read_iis(mtd, &iis, iis_ptr);
if (ret < 0)
break;
if (ret == 0)
continue;
sz += sizeof(struct mtd_partition);
sz += strlen(iis.name) + 1;
idx += 1;
}
if (!sz)
return ret;
parts = kzalloc(sz, GFP_KERNEL);
if (!parts)
return -ENOMEM;
str = (char *)(parts + idx);
for (idx = off = 0; off < mtd->size; off += mtd->erasesize) {
struct image_info_struct iis;
u_int iis_ptr, img_ptr;
ret = afs_read_footer(mtd, &img_ptr, &iis_ptr, off, mask);
if (ret < 0)
break;
if (ret == 0)
continue;
ret = afs_read_iis(mtd, &iis, iis_ptr);
if (ret < 0)
break;
if (ret == 0)
continue;
strcpy(str, iis.name);
parts[idx].name = str;
parts[idx].size = (iis.length + mtd->erasesize - 1) & ~(mtd->erasesize - 1);
parts[idx].offset = img_ptr;
parts[idx].mask_flags = 0;
printk(" mtd%d: at 0x%08x, %5lluKiB, %8u, %s\n",
idx, img_ptr, parts[idx].size / 1024,
iis.imageNumber, str);
idx += 1;
str = str + strlen(iis.name) + 1;
}
if (!idx) {
kfree(parts);
parts = NULL;
}
*pparts = parts;
return idx ? idx : ret;
}
static int __init afs_parser_init(void)
{
register_mtd_parser(&afs_parser);
return 0;
}
static void __exit afs_parser_exit(void)
{
deregister_mtd_parser(&afs_parser);
}
