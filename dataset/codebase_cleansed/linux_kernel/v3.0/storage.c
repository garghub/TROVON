static int romfs_mtd_read(struct super_block *sb, unsigned long pos,
void *buf, size_t buflen)
{
size_t rlen;
int ret;
ret = ROMFS_MTD_READ(sb, pos, buflen, &rlen, buf);
return (ret < 0 || rlen != buflen) ? -EIO : 0;
}
static ssize_t romfs_mtd_strnlen(struct super_block *sb,
unsigned long pos, size_t maxlen)
{
ssize_t n = 0;
size_t segment;
u_char buf[16], *p;
size_t len;
int ret;
while (maxlen > 0) {
segment = min_t(size_t, maxlen, 16);
ret = ROMFS_MTD_READ(sb, pos, segment, &len, buf);
if (ret < 0)
return ret;
p = memchr(buf, 0, len);
if (p)
return n + (p - buf);
maxlen -= len;
pos += len;
n += len;
}
return n;
}
static int romfs_mtd_strcmp(struct super_block *sb, unsigned long pos,
const char *str, size_t size)
{
u_char buf[17];
size_t len, segment;
int ret;
buf[0] = 0xff;
while (size > 0) {
segment = min_t(size_t, size + 1, 17);
ret = ROMFS_MTD_READ(sb, pos, segment, &len, buf);
if (ret < 0)
return ret;
len--;
if (memcmp(buf, str, len) != 0)
return 0;
buf[0] = buf[len];
size -= len;
pos += len;
str += len;
}
if (buf[0])
return 0;
return 1;
}
static int romfs_blk_read(struct super_block *sb, unsigned long pos,
void *buf, size_t buflen)
{
struct buffer_head *bh;
unsigned long offset;
size_t segment;
while (buflen > 0) {
offset = pos & (ROMBSIZE - 1);
segment = min_t(size_t, buflen, ROMBSIZE - offset);
bh = sb_bread(sb, pos >> ROMBSBITS);
if (!bh)
return -EIO;
memcpy(buf, bh->b_data + offset, segment);
brelse(bh);
buf += segment;
buflen -= segment;
pos += segment;
}
return 0;
}
static ssize_t romfs_blk_strnlen(struct super_block *sb,
unsigned long pos, size_t limit)
{
struct buffer_head *bh;
unsigned long offset;
ssize_t n = 0;
size_t segment;
u_char *buf, *p;
while (limit > 0) {
offset = pos & (ROMBSIZE - 1);
segment = min_t(size_t, limit, ROMBSIZE - offset);
bh = sb_bread(sb, pos >> ROMBSBITS);
if (!bh)
return -EIO;
buf = bh->b_data + offset;
p = memchr(buf, 0, segment);
brelse(bh);
if (p)
return n + (p - buf);
limit -= segment;
pos += segment;
n += segment;
}
return n;
}
static int romfs_blk_strcmp(struct super_block *sb, unsigned long pos,
const char *str, size_t size)
{
struct buffer_head *bh;
unsigned long offset;
size_t segment;
bool matched, terminated = false;
while (size > 0) {
offset = pos & (ROMBSIZE - 1);
segment = min_t(size_t, size, ROMBSIZE - offset);
bh = sb_bread(sb, pos >> ROMBSBITS);
if (!bh)
return -EIO;
matched = (memcmp(bh->b_data + offset, str, segment) == 0);
size -= segment;
pos += segment;
str += segment;
if (matched && size == 0 && offset + segment < ROMBSIZE) {
if (!bh->b_data[offset + segment])
terminated = true;
else
matched = false;
}
brelse(bh);
if (!matched)
return 0;
}
if (!terminated) {
BUG_ON((pos & (ROMBSIZE - 1)) != 0);
bh = sb_bread(sb, pos >> ROMBSBITS);
if (!bh)
return -EIO;
matched = !bh->b_data[0];
brelse(bh);
if (!matched)
return 0;
}
return 1;
}
int romfs_dev_read(struct super_block *sb, unsigned long pos,
void *buf, size_t buflen)
{
size_t limit;
limit = romfs_maxsize(sb);
if (pos >= limit)
return -EIO;
if (buflen > limit - pos)
buflen = limit - pos;
#ifdef CONFIG_ROMFS_ON_MTD
if (sb->s_mtd)
return romfs_mtd_read(sb, pos, buf, buflen);
#endif
#ifdef CONFIG_ROMFS_ON_BLOCK
if (sb->s_bdev)
return romfs_blk_read(sb, pos, buf, buflen);
#endif
return -EIO;
}
ssize_t romfs_dev_strnlen(struct super_block *sb,
unsigned long pos, size_t maxlen)
{
size_t limit;
limit = romfs_maxsize(sb);
if (pos >= limit)
return -EIO;
if (maxlen > limit - pos)
maxlen = limit - pos;
#ifdef CONFIG_ROMFS_ON_MTD
if (sb->s_mtd)
return romfs_mtd_strnlen(sb, pos, maxlen);
#endif
#ifdef CONFIG_ROMFS_ON_BLOCK
if (sb->s_bdev)
return romfs_blk_strnlen(sb, pos, maxlen);
#endif
return -EIO;
}
int romfs_dev_strcmp(struct super_block *sb, unsigned long pos,
const char *str, size_t size)
{
size_t limit;
limit = romfs_maxsize(sb);
if (pos >= limit)
return -EIO;
if (size > ROMFS_MAXFN)
return -ENAMETOOLONG;
if (size + 1 > limit - pos)
return -EIO;
#ifdef CONFIG_ROMFS_ON_MTD
if (sb->s_mtd)
return romfs_mtd_strcmp(sb, pos, str, size);
#endif
#ifdef CONFIG_ROMFS_ON_BLOCK
if (sb->s_bdev)
return romfs_blk_strcmp(sb, pos, str, size);
#endif
return -EIO;
}
