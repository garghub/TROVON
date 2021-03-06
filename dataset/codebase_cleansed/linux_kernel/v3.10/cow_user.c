void cow_sizes(int version, __u64 size, int sectorsize, int align,
int bitmap_offset, unsigned long *bitmap_len_out,
int *data_offset_out)
{
if (version < 3) {
*bitmap_len_out = (size + sectorsize - 1) / (8 * sectorsize);
*data_offset_out = bitmap_offset + *bitmap_len_out;
*data_offset_out = (*data_offset_out + sectorsize - 1) /
sectorsize;
*data_offset_out *= sectorsize;
}
else {
*bitmap_len_out = DIV_ROUND(size, sectorsize);
*bitmap_len_out = DIV_ROUND(*bitmap_len_out, 8);
*data_offset_out = bitmap_offset + *bitmap_len_out;
*data_offset_out = ROUND_UP(*data_offset_out, align);
}
}
static int absolutize(char *to, int size, char *from)
{
char save_cwd[256], *slash;
int remaining;
if (getcwd(save_cwd, sizeof(save_cwd)) == NULL) {
cow_printf("absolutize : unable to get cwd - errno = %d\n",
errno);
return -1;
}
slash = strrchr(from, '/');
if (slash != NULL) {
*slash = '\0';
if (chdir(from)) {
*slash = '/';
cow_printf("absolutize : Can't cd to '%s' - "
"errno = %d\n", from, errno);
return -1;
}
*slash = '/';
if (getcwd(to, size) == NULL) {
cow_printf("absolutize : unable to get cwd of '%s' - "
"errno = %d\n", from, errno);
return -1;
}
remaining = size - strlen(to);
if (strlen(slash) + 1 > remaining) {
cow_printf("absolutize : unable to fit '%s' into %d "
"chars\n", from, size);
return -1;
}
strcat(to, slash);
}
else {
if (strlen(save_cwd) + 1 + strlen(from) + 1 > size) {
cow_printf("absolutize : unable to fit '%s' into %d "
"chars\n", from, size);
return -1;
}
strcpy(to, save_cwd);
strcat(to, "/");
strcat(to, from);
}
if (chdir(save_cwd)) {
cow_printf("absolutize : Can't cd to '%s' - "
"errno = %d\n", save_cwd, errno);
return -1;
}
return 0;
}
int write_cow_header(char *cow_file, int fd, char *backing_file,
int sectorsize, int alignment, unsigned long long *size)
{
struct cow_header_v3 *header;
unsigned long modtime;
int err;
err = cow_seek_file(fd, 0);
if (err < 0) {
cow_printf("write_cow_header - lseek failed, err = %d\n", -err);
goto out;
}
err = -ENOMEM;
header = cow_malloc(sizeof(*header));
if (header == NULL) {
cow_printf("write_cow_header - failed to allocate COW V3 "
"header\n");
goto out;
}
header->magic = htobe32(COW_MAGIC);
header->version = htobe32(COW_VERSION);
err = -EINVAL;
if (strlen(backing_file) > sizeof(header->backing_file) - 1) {
cow_printf("Backing file name \"%s\" is too long - names are "
"limited to %zd characters\n", backing_file,
sizeof(header->backing_file) - 1);
goto out_free;
}
if (absolutize(header->backing_file, sizeof(header->backing_file),
backing_file))
goto out_free;
err = os_file_modtime(header->backing_file, &modtime);
if (err < 0) {
cow_printf("write_cow_header - backing file '%s' mtime "
"request failed, err = %d\n", header->backing_file,
-err);
goto out_free;
}
err = cow_file_size(header->backing_file, size);
if (err < 0) {
cow_printf("write_cow_header - couldn't get size of "
"backing file '%s', err = %d\n",
header->backing_file, -err);
goto out_free;
}
header->mtime = htobe32(modtime);
header->size = htobe64(*size);
header->sectorsize = htobe32(sectorsize);
header->alignment = htobe32(alignment);
header->cow_format = COW_BITMAP;
err = cow_write_file(fd, header, sizeof(*header));
if (err != sizeof(*header)) {
cow_printf("write_cow_header - write of header to "
"new COW file '%s' failed, err = %d\n", cow_file,
-err);
goto out_free;
}
err = 0;
out_free:
cow_free(header);
out:
return err;
}
int file_reader(__u64 offset, char *buf, int len, void *arg)
{
int fd = *((int *) arg);
return pread(fd, buf, len, offset);
}
int read_cow_header(int (*reader)(__u64, char *, int, void *), void *arg,
__u32 *version_out, char **backing_file_out,
time_t *mtime_out, unsigned long long *size_out,
int *sectorsize_out, __u32 *align_out,
int *bitmap_offset_out)
{
union cow_header *header;
char *file;
int err, n;
unsigned long version, magic;
header = cow_malloc(sizeof(*header));
if (header == NULL) {
cow_printf("read_cow_header - Failed to allocate header\n");
return -ENOMEM;
}
err = -EINVAL;
n = (*reader)(0, (char *) header, sizeof(*header), arg);
if (n < offsetof(typeof(header->v1), backing_file)) {
cow_printf("read_cow_header - short header\n");
goto out;
}
magic = header->v1.magic;
if (magic == COW_MAGIC)
version = header->v1.version;
else if (magic == be32toh(COW_MAGIC))
version = be32toh(header->v1.version);
else goto out;
*version_out = version;
if (version == 1) {
if (n < sizeof(header->v1)) {
cow_printf("read_cow_header - failed to read V1 "
"header\n");
goto out;
}
*mtime_out = header->v1.mtime;
*size_out = header->v1.size;
*sectorsize_out = header->v1.sectorsize;
*bitmap_offset_out = sizeof(header->v1);
*align_out = *sectorsize_out;
file = header->v1.backing_file;
}
else if (version == 2) {
if (n < sizeof(header->v2)) {
cow_printf("read_cow_header - failed to read V2 "
"header\n");
goto out;
}
*mtime_out = be32toh(header->v2.mtime);
*size_out = be64toh(header->v2.size);
*sectorsize_out = be32toh(header->v2.sectorsize);
*bitmap_offset_out = sizeof(header->v2);
*align_out = *sectorsize_out;
file = header->v2.backing_file;
}
else if (version == 3 && (*((int*)header->v3.backing_file) != 0)) {
if (n < sizeof(header->v3)) {
cow_printf("read_cow_header - failed to read V3 "
"header\n");
goto out;
}
*mtime_out = be32toh(header->v3.mtime);
*size_out = be64toh(header->v3.size);
*sectorsize_out = be32toh(header->v3.sectorsize);
*align_out = be32toh(header->v3.alignment);
if (*align_out == 0) {
cow_printf("read_cow_header - invalid COW header, "
"align == 0\n");
}
*bitmap_offset_out = ROUND_UP(sizeof(header->v3), *align_out);
file = header->v3.backing_file;
}
else if (version == 3) {
cow_printf("read_cow_header - broken V3 file with"
" 64-bit layout - recovering content.\n");
if (n < sizeof(header->v3_b)) {
cow_printf("read_cow_header - failed to read V3 "
"header\n");
goto out;
}
*mtime_out = (time32_t) be32toh(header->v3_b.mtime);
*size_out = be64toh(header->v3_b.size);
*sectorsize_out = be32toh(header->v3_b.sectorsize);
*align_out = be32toh(header->v3_b.alignment);
if (*align_out == 0) {
cow_printf("read_cow_header - invalid COW header, "
"align == 0\n");
}
*bitmap_offset_out = ROUND_UP(sizeof(header->v3_b), *align_out);
file = header->v3_b.backing_file;
}
else {
cow_printf("read_cow_header - invalid COW version\n");
goto out;
}
err = -ENOMEM;
*backing_file_out = cow_strdup(file);
if (*backing_file_out == NULL) {
cow_printf("read_cow_header - failed to allocate backing "
"file\n");
goto out;
}
err = 0;
out:
cow_free(header);
return err;
}
int init_cow_file(int fd, char *cow_file, char *backing_file, int sectorsize,
int alignment, int *bitmap_offset_out,
unsigned long *bitmap_len_out, int *data_offset_out)
{
unsigned long long size, offset;
char zero = 0;
int err;
err = write_cow_header(cow_file, fd, backing_file, sectorsize,
alignment, &size);
if (err)
goto out;
*bitmap_offset_out = ROUND_UP(sizeof(struct cow_header_v3), alignment);
cow_sizes(COW_VERSION, size, sectorsize, alignment, *bitmap_offset_out,
bitmap_len_out, data_offset_out);
offset = *data_offset_out + size - sizeof(zero);
err = cow_seek_file(fd, offset);
if (err < 0) {
cow_printf("cow bitmap lseek failed : err = %d\n", -err);
goto out;
}
err = cow_write_file(fd, &zero, sizeof(zero));
if (err != sizeof(zero)) {
cow_printf("Write of bitmap to new COW file '%s' failed, "
"err = %d\n", cow_file, -err);
if (err >= 0)
err = -EINVAL;
goto out;
}
return 0;
out:
return err;
}
