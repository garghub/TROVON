static sector_t cchh2blk(struct vtoc_cchh *ptr, struct hd_geometry *geo)
{
sector_t cyl;
__u16 head;
cyl = ptr->hh & 0xFFF0;
cyl <<= 12;
cyl |= ptr->cc;
head = ptr->hh & 0x000F;
return cyl * geo->heads * geo->sectors +
head * geo->sectors;
}
static sector_t cchhb2blk(struct vtoc_cchhb *ptr, struct hd_geometry *geo)
{
sector_t cyl;
__u16 head;
cyl = ptr->hh & 0xFFF0;
cyl <<= 12;
cyl |= ptr->cc;
head = ptr->hh & 0x000F;
return cyl * geo->heads * geo->sectors +
head * geo->sectors +
ptr->b;
}
static int find_label(struct parsed_partitions *state,
dasd_information2_t *info,
struct hd_geometry *geo,
int blocksize,
sector_t *labelsect,
char name[],
char type[],
union label_t *label)
{
Sector sect;
unsigned char *data;
sector_t testsect[3];
unsigned char temp[5];
int found = 0;
int i, testcount;
if (info) {
if ((info->cu_type == 0x6310 && info->dev_type == 0x9336) ||
(info->cu_type == 0x3880 && info->dev_type == 0x3370))
testsect[0] = info->label_block;
else
testsect[0] = info->label_block * (blocksize >> 9);
testcount = 1;
} else {
testsect[0] = 1;
testsect[1] = (blocksize >> 9);
testsect[2] = 2 * (blocksize >> 9);
testcount = 3;
}
for (i = 0; i < testcount; ++i) {
data = read_part_sector(state, testsect[i], &sect);
if (data == NULL)
continue;
memcpy(label, data, sizeof(*label));
memcpy(temp, data, 4);
temp[4] = 0;
EBCASC(temp, 4);
put_dev_sector(sect);
if (!strcmp(temp, "VOL1") ||
!strcmp(temp, "LNX1") ||
!strcmp(temp, "CMS1")) {
if (!strcmp(temp, "VOL1")) {
strncpy(type, label->vol.vollbl, 4);
strncpy(name, label->vol.volid, 6);
} else {
strncpy(type, label->lnx.vollbl, 4);
strncpy(name, label->lnx.volid, 6);
}
EBCASC(type, 4);
EBCASC(name, 6);
*labelsect = testsect[i];
found = 1;
break;
}
}
if (!found)
memset(label, 0, sizeof(*label));
return found;
}
static int find_vol1_partitions(struct parsed_partitions *state,
struct hd_geometry *geo,
int blocksize,
char name[],
union label_t *label)
{
sector_t blk;
int counter;
char tmp[64];
Sector sect;
unsigned char *data;
loff_t offset, size;
struct vtoc_format1_label f1;
int secperblk;
snprintf(tmp, sizeof(tmp), "VOL1/%8s:", name);
strlcat(state->pp_buf, tmp, PAGE_SIZE);
secperblk = blocksize >> 9;
blk = cchhb2blk(&label->vol.vtoc, geo) + 1;
counter = 0;
data = read_part_sector(state, blk * secperblk, &sect);
while (data != NULL) {
memcpy(&f1, data, sizeof(struct vtoc_format1_label));
put_dev_sector(sect);
if (f1.DS1FMTID == _ascebc['4']
|| f1.DS1FMTID == _ascebc['5']
|| f1.DS1FMTID == _ascebc['7']
|| f1.DS1FMTID == _ascebc['9']) {
blk++;
data = read_part_sector(state, blk * secperblk, &sect);
continue;
}
if (f1.DS1FMTID != _ascebc['1'] &&
f1.DS1FMTID != _ascebc['8'])
break;
offset = cchh2blk(&f1.DS1EXT1.llimit, geo);
size = cchh2blk(&f1.DS1EXT1.ulimit, geo) -
offset + geo->sectors;
offset *= secperblk;
size *= secperblk;
if (counter >= state->limit)
break;
put_partition(state, counter + 1, offset, size);
counter++;
blk++;
data = read_part_sector(state, blk * secperblk, &sect);
}
strlcat(state->pp_buf, "\n", PAGE_SIZE);
if (!data)
return -1;
return 1;
}
static int find_lnx1_partitions(struct parsed_partitions *state,
struct hd_geometry *geo,
int blocksize,
char name[],
union label_t *label,
sector_t labelsect,
loff_t i_size,
dasd_information2_t *info)
{
loff_t offset, geo_size, size;
char tmp[64];
int secperblk;
snprintf(tmp, sizeof(tmp), "LNX1/%8s:", name);
strlcat(state->pp_buf, tmp, PAGE_SIZE);
secperblk = blocksize >> 9;
if (label->lnx.ldl_version == 0xf2) {
size = label->lnx.formatted_blocks * secperblk;
} else {
geo_size = geo->cylinders * geo->heads
* geo->sectors * secperblk;
size = i_size >> 9;
if (size != geo_size) {
if (!info) {
strlcat(state->pp_buf, "\n", PAGE_SIZE);
return 1;
}
if (!strcmp(info->type, "ECKD"))
if (geo_size < size)
size = geo_size;
}
}
offset = labelsect + secperblk;
put_partition(state, 1, offset, size - offset);
strlcat(state->pp_buf, "\n", PAGE_SIZE);
return 1;
}
static int find_cms1_partitions(struct parsed_partitions *state,
struct hd_geometry *geo,
int blocksize,
char name[],
union label_t *label,
sector_t labelsect)
{
loff_t offset, size;
char tmp[64];
int secperblk;
blocksize = label->cms.block_size;
secperblk = blocksize >> 9;
if (label->cms.disk_offset != 0) {
snprintf(tmp, sizeof(tmp), "CMS1/%8s(MDSK):", name);
strlcat(state->pp_buf, tmp, PAGE_SIZE);
offset = label->cms.disk_offset * secperblk;
size = (label->cms.block_count - 1) * secperblk;
} else {
snprintf(tmp, sizeof(tmp), "CMS1/%8s:", name);
strlcat(state->pp_buf, tmp, PAGE_SIZE);
if (labelsect == 1)
offset = 2 * secperblk;
else
offset = labelsect + secperblk;
size = label->cms.block_count * secperblk;
}
put_partition(state, 1, offset, size-offset);
strlcat(state->pp_buf, "\n", PAGE_SIZE);
return 1;
}
int ibm_partition(struct parsed_partitions *state)
{
struct block_device *bdev = state->bdev;
int blocksize, res;
loff_t i_size, offset, size;
dasd_information2_t *info;
struct hd_geometry *geo;
char type[5] = {0,};
char name[7] = {0,};
sector_t labelsect;
union label_t *label;
res = 0;
blocksize = bdev_logical_block_size(bdev);
if (blocksize <= 0)
goto out_exit;
i_size = i_size_read(bdev->bd_inode);
if (i_size == 0)
goto out_exit;
info = kmalloc(sizeof(dasd_information2_t), GFP_KERNEL);
if (info == NULL)
goto out_exit;
geo = kmalloc(sizeof(struct hd_geometry), GFP_KERNEL);
if (geo == NULL)
goto out_nogeo;
label = kmalloc(sizeof(union label_t), GFP_KERNEL);
if (label == NULL)
goto out_nolab;
if (ioctl_by_bdev(bdev, HDIO_GETGEO, (unsigned long)geo) != 0)
goto out_freeall;
if (ioctl_by_bdev(bdev, BIODASDINFO2, (unsigned long)info) != 0) {
kfree(info);
info = NULL;
}
if (find_label(state, info, geo, blocksize, &labelsect, name, type,
label)) {
if (!strncmp(type, "VOL1", 4)) {
res = find_vol1_partitions(state, geo, blocksize, name,
label);
} else if (!strncmp(type, "LNX1", 4)) {
res = find_lnx1_partitions(state, geo, blocksize, name,
label, labelsect, i_size,
info);
} else if (!strncmp(type, "CMS1", 4)) {
res = find_cms1_partitions(state, geo, blocksize, name,
label, labelsect);
}
} else if (info) {
res = 1;
if (info->format == DASD_FORMAT_LDL) {
strlcat(state->pp_buf, "(nonl)", PAGE_SIZE);
size = i_size >> 9;
offset = (info->label_block + 1) * (blocksize >> 9);
put_partition(state, 1, offset, size-offset);
strlcat(state->pp_buf, "\n", PAGE_SIZE);
}
} else
res = 0;
out_freeall:
kfree(label);
out_nolab:
kfree(geo);
out_nogeo:
kfree(info);
out_exit:
return res;
}
