static struct mtd_partition * newpart(char *s,
char **retptr,
int *num_parts,
int this_part,
unsigned char **extra_mem_ptr,
int extra_mem_size)
{
struct mtd_partition *parts;
unsigned long long size, offset = OFFSET_CONTINUOUS;
char *name;
int name_len;
unsigned char *extra_mem;
char delim;
unsigned int mask_flags;
if (*s == '-') {
size = SIZE_REMAINING;
s++;
} else {
size = memparse(s, &s);
if (size < PAGE_SIZE) {
printk(KERN_ERR ERRP "partition size too small (%llx)\n",
size);
return ERR_PTR(-EINVAL);
}
}
mask_flags = 0;
delim = 0;
if (*s == '@') {
s++;
offset = memparse(s, &s);
}
if (*s == '(')
delim = ')';
if (delim) {
char *p;
name = ++s;
p = strchr(name, delim);
if (!p) {
printk(KERN_ERR ERRP "no closing %c found in partition name\n", delim);
return ERR_PTR(-EINVAL);
}
name_len = p - name;
s = p + 1;
} else {
name = NULL;
name_len = 13;
}
extra_mem_size += name_len + 1;
if (strncmp(s, "ro", 2) == 0) {
mask_flags |= MTD_WRITEABLE;
s += 2;
}
if (strncmp(s, "lk", 2) == 0) {
mask_flags |= MTD_POWERUP_LOCK;
s += 2;
}
if (*s == ',') {
if (size == SIZE_REMAINING) {
printk(KERN_ERR ERRP "no partitions allowed after a fill-up partition\n");
return ERR_PTR(-EINVAL);
}
parts = newpart(s + 1, &s, num_parts, this_part + 1,
&extra_mem, extra_mem_size);
if (IS_ERR(parts))
return parts;
} else {
int alloc_size;
*num_parts = this_part + 1;
alloc_size = *num_parts * sizeof(struct mtd_partition) +
extra_mem_size;
parts = kzalloc(alloc_size, GFP_KERNEL);
if (!parts)
return ERR_PTR(-ENOMEM);
extra_mem = (unsigned char *)(parts + *num_parts);
}
parts[this_part].size = size;
parts[this_part].offset = offset;
parts[this_part].mask_flags = mask_flags;
if (name)
strlcpy(extra_mem, name, name_len + 1);
else
sprintf(extra_mem, "Partition_%03d", this_part);
parts[this_part].name = extra_mem;
extra_mem += name_len + 1;
dbg(("partition %d: name <%s>, offset %llx, size %llx, mask flags %x\n",
this_part, parts[this_part].name, parts[this_part].offset,
parts[this_part].size, parts[this_part].mask_flags));
if (extra_mem_ptr)
*extra_mem_ptr = extra_mem;
*retptr = s;
return parts;
}
static int mtdpart_setup_real(char *s)
{
cmdline_parsed = 1;
for( ; s != NULL; )
{
struct cmdline_mtd_partition *this_mtd;
struct mtd_partition *parts;
int mtd_id_len, num_parts;
char *p, *mtd_id;
mtd_id = s;
p = strchr(s, ':');
if (!p) {
printk(KERN_ERR ERRP "no mtd-id\n");
return -EINVAL;
}
mtd_id_len = p - mtd_id;
dbg(("parsing <%s>\n", p+1));
parts = newpart(p + 1,
&s,
&num_parts,
0,
(unsigned char**)&this_mtd,
mtd_id_len + 1 + sizeof(*this_mtd) +
sizeof(void*)-1 );
if (IS_ERR(parts)) {
return PTR_ERR(parts);
}
this_mtd = (struct cmdline_mtd_partition *)
ALIGN((unsigned long)this_mtd, sizeof(void *));
this_mtd->parts = parts;
this_mtd->num_parts = num_parts;
this_mtd->mtd_id = (char*)(this_mtd + 1);
strlcpy(this_mtd->mtd_id, mtd_id, mtd_id_len + 1);
this_mtd->next = partitions;
partitions = this_mtd;
dbg(("mtdid=<%s> num_parts=<%d>\n",
this_mtd->mtd_id, this_mtd->num_parts));
if (*s == 0)
break;
if (*s != ';') {
printk(KERN_ERR ERRP "bad character after partition (%c)\n", *s);
return -EINVAL;
}
s++;
}
return 0;
}
static int parse_cmdline_partitions(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
unsigned long long offset;
int i, err;
struct cmdline_mtd_partition *part;
const char *mtd_id = master->name;
if (!cmdline_parsed) {
err = mtdpart_setup_real(cmdline);
if (err)
return err;
}
for (part = partitions; part; part = part->next) {
if ((!mtd_id) || (!strcmp(part->mtd_id, mtd_id)))
break;
}
if (!part)
return 0;
for (i = 0, offset = 0; i < part->num_parts; i++) {
if (part->parts[i].offset == OFFSET_CONTINUOUS)
part->parts[i].offset = offset;
else
offset = part->parts[i].offset;
if (part->parts[i].size == SIZE_REMAINING)
part->parts[i].size = master->size - offset;
if (offset + part->parts[i].size > master->size) {
printk(KERN_WARNING ERRP
"%s: partitioning exceeds flash size, truncating\n",
part->mtd_id);
part->parts[i].size = master->size - offset;
}
offset += part->parts[i].size;
if (part->parts[i].size == 0) {
printk(KERN_WARNING ERRP
"%s: skipping zero sized partition\n",
part->mtd_id);
part->num_parts--;
memmove(&part->parts[i], &part->parts[i + 1],
sizeof(*part->parts) * (part->num_parts - i));
i--;
}
}
*pparts = kmemdup(part->parts, sizeof(*part->parts) * part->num_parts,
GFP_KERNEL);
if (!*pparts)
return -ENOMEM;
return part->num_parts;
}
static int __init mtdpart_setup(char *s)
{
cmdline = s;
return 1;
}
static int __init cmdline_parser_init(void)
{
if (mtdparts)
mtdpart_setup(mtdparts);
register_mtd_parser(&cmdline_parser);
return 0;
}
static void __exit cmdline_parser_exit(void)
{
deregister_mtd_parser(&cmdline_parser);
}
