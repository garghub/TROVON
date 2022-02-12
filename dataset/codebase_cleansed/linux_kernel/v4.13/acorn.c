static struct adfs_discrecord *
adfs_partition(struct parsed_partitions *state, char *name, char *data,
unsigned long first_sector, int slot)
{
struct adfs_discrecord *dr;
unsigned int nr_sects;
if (adfs_checkbblk(data))
return NULL;
dr = (struct adfs_discrecord *)(data + 0x1c0);
if (dr->disc_size == 0 && dr->disc_size_high == 0)
return NULL;
nr_sects = (le32_to_cpu(dr->disc_size_high) << 23) |
(le32_to_cpu(dr->disc_size) >> 9);
if (name) {
strlcat(state->pp_buf, " [", PAGE_SIZE);
strlcat(state->pp_buf, name, PAGE_SIZE);
strlcat(state->pp_buf, "]", PAGE_SIZE);
}
put_partition(state, slot, first_sector, nr_sects);
return dr;
}
static int riscix_partition(struct parsed_partitions *state,
unsigned long first_sect, int slot,
unsigned long nr_sects)
{
Sector sect;
struct riscix_record *rr;
rr = read_part_sector(state, first_sect, &sect);
if (!rr)
return -1;
strlcat(state->pp_buf, " [RISCiX]", PAGE_SIZE);
if (rr->magic == RISCIX_MAGIC) {
unsigned long size = nr_sects > 2 ? 2 : nr_sects;
int part;
strlcat(state->pp_buf, " <", PAGE_SIZE);
put_partition(state, slot++, first_sect, size);
for (part = 0; part < 8; part++) {
if (rr->part[part].one &&
memcmp(rr->part[part].name, "All\0", 4)) {
put_partition(state, slot++,
le32_to_cpu(rr->part[part].start),
le32_to_cpu(rr->part[part].length));
strlcat(state->pp_buf, "(", PAGE_SIZE);
strlcat(state->pp_buf, rr->part[part].name, PAGE_SIZE);
strlcat(state->pp_buf, ")", PAGE_SIZE);
}
}
strlcat(state->pp_buf, " >\n", PAGE_SIZE);
} else {
put_partition(state, slot++, first_sect, nr_sects);
}
put_dev_sector(sect);
return slot;
}
static int linux_partition(struct parsed_partitions *state,
unsigned long first_sect, int slot,
unsigned long nr_sects)
{
Sector sect;
struct linux_part *linuxp;
unsigned long size = nr_sects > 2 ? 2 : nr_sects;
strlcat(state->pp_buf, " [Linux]", PAGE_SIZE);
put_partition(state, slot++, first_sect, size);
linuxp = read_part_sector(state, first_sect, &sect);
if (!linuxp)
return -1;
strlcat(state->pp_buf, " <", PAGE_SIZE);
while (linuxp->magic == cpu_to_le32(LINUX_NATIVE_MAGIC) ||
linuxp->magic == cpu_to_le32(LINUX_SWAP_MAGIC)) {
if (slot == state->limit)
break;
put_partition(state, slot++, first_sect +
le32_to_cpu(linuxp->start_sect),
le32_to_cpu(linuxp->nr_sects));
linuxp ++;
}
strlcat(state->pp_buf, " >", PAGE_SIZE);
put_dev_sector(sect);
return slot;
}
int adfspart_check_CUMANA(struct parsed_partitions *state)
{
unsigned long first_sector = 0;
unsigned int start_blk = 0;
Sector sect;
unsigned char *data;
char *name = "CUMANA/ADFS";
int first = 1;
int slot = 1;
do {
struct adfs_discrecord *dr;
unsigned int nr_sects;
data = read_part_sector(state, start_blk * 2 + 6, &sect);
if (!data)
return -1;
if (slot == state->limit)
break;
dr = adfs_partition(state, name, data, first_sector, slot++);
if (!dr)
break;
name = NULL;
nr_sects = (data[0x1fd] + (data[0x1fe] << 8)) *
(dr->heads + (dr->lowsector & 0x40 ? 1 : 0)) *
dr->secspertrack;
if (!nr_sects)
break;
first = 0;
first_sector += nr_sects;
start_blk += nr_sects >> (BLOCK_SIZE_BITS - 9);
nr_sects = 0;
switch (data[0x1fc] & 15) {
case 0:
break;
#ifdef CONFIG_ACORN_PARTITION_RISCIX
case PARTITION_RISCIX_SCSI:
slot = riscix_partition(state, first_sector, slot,
nr_sects);
break;
#endif
case PARTITION_LINUX:
slot = linux_partition(state, first_sector, slot,
nr_sects);
break;
}
put_dev_sector(sect);
if (slot == -1)
return -1;
} while (1);
put_dev_sector(sect);
return first ? 0 : 1;
}
int adfspart_check_ADFS(struct parsed_partitions *state)
{
unsigned long start_sect, nr_sects, sectscyl, heads;
Sector sect;
unsigned char *data;
struct adfs_discrecord *dr;
unsigned char id;
int slot = 1;
data = read_part_sector(state, 6, &sect);
if (!data)
return -1;
dr = adfs_partition(state, "ADFS", data, 0, slot++);
if (!dr) {
put_dev_sector(sect);
return 0;
}
heads = dr->heads + ((dr->lowsector >> 6) & 1);
sectscyl = dr->secspertrack * heads;
start_sect = ((data[0x1fe] << 8) + data[0x1fd]) * sectscyl;
id = data[0x1fc] & 15;
put_dev_sector(sect);
nr_sects = (state->bdev->bd_inode->i_size >> 9) - start_sect;
if (start_sect) {
switch (id) {
#ifdef CONFIG_ACORN_PARTITION_RISCIX
case PARTITION_RISCIX_SCSI:
case PARTITION_RISCIX_MFM:
slot = riscix_partition(state, start_sect, slot,
nr_sects);
break;
#endif
case PARTITION_LINUX:
slot = linux_partition(state, start_sect, slot,
nr_sects);
break;
}
}
strlcat(state->pp_buf, "\n", PAGE_SIZE);
return 1;
}
static int adfspart_check_ICSLinux(struct parsed_partitions *state,
unsigned long block)
{
Sector sect;
unsigned char *data = read_part_sector(state, block, &sect);
int result = 0;
if (data) {
if (memcmp(data, "LinuxPart", 9) == 0)
result = 1;
put_dev_sector(sect);
}
return result;
}
static inline int valid_ics_sector(const unsigned char *data)
{
unsigned long sum;
int i;
for (i = 0, sum = 0x50617274; i < 508; i++)
sum += data[i];
sum -= le32_to_cpu(*(__le32 *)(&data[508]));
return sum == 0;
}
int adfspart_check_ICS(struct parsed_partitions *state)
{
const unsigned char *data;
const struct ics_part *p;
int slot;
Sector sect;
data = read_part_sector(state, 0, &sect);
if (!data)
return -1;
if (!valid_ics_sector(data)) {
put_dev_sector(sect);
return 0;
}
strlcat(state->pp_buf, " [ICS]", PAGE_SIZE);
for (slot = 1, p = (const struct ics_part *)data; p->size; p++) {
u32 start = le32_to_cpu(p->start);
s32 size = le32_to_cpu(p->size);
if (slot == state->limit)
break;
if (size < 0) {
size = -size;
if (size > 1 && adfspart_check_ICSLinux(state, start)) {
start += 1;
size -= 1;
}
}
if (size)
put_partition(state, slot++, start, size);
}
put_dev_sector(sect);
strlcat(state->pp_buf, "\n", PAGE_SIZE);
return 1;
}
static inline int valid_ptec_sector(const unsigned char *data)
{
unsigned char checksum = 0x2a;
int i;
if (data[510] == 0x55 && data[511] == 0xaa)
return 0;
for (i = 0; i < 511; i++)
checksum += data[i];
return checksum == data[511];
}
int adfspart_check_POWERTEC(struct parsed_partitions *state)
{
Sector sect;
const unsigned char *data;
const struct ptec_part *p;
int slot = 1;
int i;
data = read_part_sector(state, 0, &sect);
if (!data)
return -1;
if (!valid_ptec_sector(data)) {
put_dev_sector(sect);
return 0;
}
strlcat(state->pp_buf, " [POWERTEC]", PAGE_SIZE);
for (i = 0, p = (const struct ptec_part *)data; i < 12; i++, p++) {
u32 start = le32_to_cpu(p->start);
u32 size = le32_to_cpu(p->size);
if (size)
put_partition(state, slot++, start, size);
}
put_dev_sector(sect);
strlcat(state->pp_buf, "\n", PAGE_SIZE);
return 1;
}
int adfspart_check_EESOX(struct parsed_partitions *state)
{
Sector sect;
const unsigned char *data;
unsigned char buffer[256];
struct eesox_part *p;
sector_t start = 0;
int i, slot = 1;
data = read_part_sector(state, 7, &sect);
if (!data)
return -1;
for (i = 0; i < 256; i++)
buffer[i] = data[i] ^ eesox_name[i & 15];
put_dev_sector(sect);
for (i = 0, p = (struct eesox_part *)buffer; i < 8; i++, p++) {
sector_t next;
if (memcmp(p->magic, "Eesox", 6))
break;
next = le32_to_cpu(p->start);
if (i)
put_partition(state, slot++, start, next - start);
start = next;
}
if (i != 0) {
sector_t size;
size = get_capacity(state->bdev->bd_disk);
put_partition(state, slot++, start, size - start);
strlcat(state->pp_buf, "\n", PAGE_SIZE);
}
return i ? 1 : 0;
}
