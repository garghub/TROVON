GSList *
wtap_get_compressed_file_extensions(void)
{
const char **extension;
GSList *extensions;
extensions = NULL;
for (extension = &compressed_file_extensions[0]; *extension != NULL;
extension++)
extensions = g_slist_append(extensions, (gpointer)(*extension));
return extensions;
}
static int
raw_read(FILE_T state, unsigned char *buf, unsigned int count, guint *have)
{
ssize_t ret;
*have = 0;
do {
ret = read(state->fd, buf + *have, count - *have);
if (ret <= 0)
break;
*have += (unsigned)ret;
state->raw_pos += ret;
} while (*have < count);
if (ret < 0) {
state->err = errno;
state->err_info = NULL;
return -1;
}
if (ret == 0)
state->eof = TRUE;
return 0;
}
static int
fill_in_buffer(FILE_T state)
{
if (state->err)
return -1;
if (state->eof == 0) {
if (raw_read(state, state->in, state->size, &(state->avail_in)) == -1)
return -1;
state->next_in = state->in;
}
return 0;
}
static struct fast_seek_point *
fast_seek_find(FILE_T file, gint64 pos)
{
struct fast_seek_point *smallest = NULL;
struct fast_seek_point *item;
guint low, i, max;
if (!file->fast_seek)
return NULL;
for (low = 0, max = file->fast_seek->len; low < max; ) {
i = (low + max) / 2;
item = (struct fast_seek_point *)file->fast_seek->pdata[i];
if (pos < item->out)
max = i;
else if (pos > item->out) {
smallest = item;
low = i + 1;
} else {
return item;
}
}
return smallest;
}
static void
fast_seek_header(FILE_T file, gint64 in_pos, gint64 out_pos,
compression_t compression)
{
struct fast_seek_point *item = NULL;
if (file->fast_seek->len != 0)
item = (struct fast_seek_point *)file->fast_seek->pdata[file->fast_seek->len - 1];
if (!item || item->out < out_pos) {
struct fast_seek_point *val = g_new(struct fast_seek_point,1);
val->in = in_pos;
val->out = out_pos;
val->compression = compression;
g_ptr_array_add(file->fast_seek, val);
}
}
static void
fast_seek_reset(FILE_T state _U_)
{
#ifdef HAVE_LIBZ
if (state->compression == ZLIB && state->fast_seek_cur) {
struct zlib_cur_seek_point *cur = (struct zlib_cur_seek_point *) state->fast_seek_cur;
cur->have = 0;
}
#endif
}
static int
gz_next1(FILE_T state, guint8 *ret)
{
int ch;
ch = GZ_GETC();
if (ch == -1) {
if (state->err == 0) {
state->err = WTAP_ERR_SHORT_READ;
state->err_info = NULL;
}
return -1;
}
*ret = ch;
return 0;
}
static int
gz_next2(FILE_T state, guint16 *ret)
{
guint16 val;
int ch;
val = GZ_GETC();
ch = GZ_GETC();
if (ch == -1) {
if (state->err == 0) {
state->err = WTAP_ERR_SHORT_READ;
state->err_info = NULL;
}
return -1;
}
val += (guint16)ch << 8;
*ret = val;
return 0;
}
static int
gz_next4(FILE_T state, guint32 *ret)
{
guint32 val;
int ch;
val = GZ_GETC();
val += (unsigned)GZ_GETC() << 8;
val += (guint32)GZ_GETC() << 16;
ch = GZ_GETC();
if (ch == -1) {
if (state->err == 0) {
state->err = WTAP_ERR_SHORT_READ;
state->err_info = NULL;
}
return -1;
}
val += (guint32)ch << 24;
*ret = val;
return 0;
}
static int
gz_skipn(FILE_T state, size_t n)
{
while (n != 0) {
if (GZ_GETC() == -1) {
if (state->err == 0) {
state->err = WTAP_ERR_SHORT_READ;
state->err_info = NULL;
}
return -1;
}
n--;
}
return 0;
}
static int
gz_skipzstr(FILE_T state)
{
int ch;
while ((ch = GZ_GETC()) > 0)
;
if (ch == -1) {
if (state->err == 0) {
state->err = WTAP_ERR_SHORT_READ;
state->err_info = NULL;
}
return -1;
}
return 0;
}
static void
zlib_fast_seek_add(FILE_T file, struct zlib_cur_seek_point *point, int bits, gint64 in_pos, gint64 out_pos)
{
struct fast_seek_point *item = (struct fast_seek_point *)file->fast_seek->pdata[file->fast_seek->len - 1];
#ifndef HAVE_INFLATEPRIME
if (bits)
return;
#endif
if (item->out + SPAN < out_pos) {
struct fast_seek_point *val = g_new(struct fast_seek_point,1);
val->in = in_pos;
val->out = out_pos;
val->compression = ZLIB;
#ifdef HAVE_INFLATEPRIME
val->data.zlib.bits = bits;
#endif
if (point->pos != 0) {
unsigned int left = ZLIB_WINSIZE - point->pos;
memcpy(val->data.zlib.window, point->window + point->pos, left);
memcpy(val->data.zlib.window + left, point->window, point->pos);
} else
memcpy(val->data.zlib.window, point->window, ZLIB_WINSIZE);
val->data.zlib.adler = (guint32) file->strm.adler;
val->data.zlib.total_out = (guint32) file->strm.total_out;
g_ptr_array_add(file->fast_seek, val);
}
}
static void
zlib_read(FILE_T state, unsigned char *buf, unsigned int count)
{
int ret = 0;
guint32 crc, len;
z_streamp strm = &(state->strm);
unsigned char *buf2 = buf;
unsigned int count2 = count;
strm->avail_out = count;
strm->next_out = buf;
do {
if (state->avail_in == 0 && fill_in_buffer(state) == -1)
break;
if (state->avail_in == 0) {
state->err = WTAP_ERR_SHORT_READ;
state->err_info = NULL;
break;
}
strm->avail_in = state->avail_in;
strm->next_in = state->next_in;
#ifdef Z_BLOCK
ret = inflate(strm, Z_BLOCK);
#else
ret = inflate(strm, Z_NO_FLUSH);
#endif
state->avail_in = strm->avail_in;
state->next_in = strm->next_in;
if (ret == Z_STREAM_ERROR) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = strm->msg;
break;
}
if (ret == Z_NEED_DICT) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = "preset dictionary needed";
break;
}
if (ret == Z_MEM_ERROR) {
state->err = ENOMEM;
state->err_info = NULL;
break;
}
if (ret == Z_DATA_ERROR) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = strm->msg;
break;
}
strm->adler = crc32(strm->adler, buf2, count2 - strm->avail_out);
#ifdef Z_BLOCK
if (state->fast_seek_cur) {
struct zlib_cur_seek_point *cur = (struct zlib_cur_seek_point *) state->fast_seek_cur;
unsigned int ready = count2 - strm->avail_out;
if (ready < ZLIB_WINSIZE) {
guint left = ZLIB_WINSIZE - cur->pos;
if (ready >= left) {
memcpy(cur->window + cur->pos, buf2, left);
if (ready != left)
memcpy(cur->window, buf2 + left, ready - left);
cur->pos = ready - left;
cur->have += ready;
} else {
memcpy(cur->window + cur->pos, buf2, ready);
cur->pos += ready;
cur->have += ready;
}
if (cur->have >= ZLIB_WINSIZE)
cur->have = ZLIB_WINSIZE;
} else {
memcpy(cur->window, buf2 + (ready - ZLIB_WINSIZE), ZLIB_WINSIZE);
cur->pos = 0;
cur->have = ZLIB_WINSIZE;
}
if (cur->have >= ZLIB_WINSIZE && ret != Z_STREAM_END && (strm->data_type & 128) && !(strm->data_type & 64))
zlib_fast_seek_add(state, cur, (strm->data_type & 7), state->raw_pos - strm->avail_in, state->pos + (count - strm->avail_out));
}
#endif
buf2 = (buf2 + count2 - strm->avail_out);
count2 = strm->avail_out;
} while (strm->avail_out && ret != Z_STREAM_END);
state->next = buf;
state->have = count - strm->avail_out;
if (ret == Z_STREAM_END) {
if (gz_next4(state, &crc) != -1 &&
gz_next4(state, &len) != -1) {
if (crc != strm->adler && !state->dont_check_crc) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = "bad CRC";
} else if (len != (strm->total_out & 0xffffffffL)) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = "length field wrong";
}
}
state->compression = UNKNOWN;
g_free(state->fast_seek_cur);
state->fast_seek_cur = NULL;
}
}
static int
gz_head(FILE_T state)
{
if (state->avail_in == 0) {
if (fill_in_buffer(state) == -1)
return -1;
if (state->avail_in == 0)
return 0;
}
#ifdef HAVE_LIBZ
if (state->next_in[0] == 31) {
state->avail_in--;
state->next_in++;
if (state->avail_in == 0 && fill_in_buffer(state) == -1)
return -1;
if (state->avail_in && state->next_in[0] == 139) {
guint8 cm;
guint8 flags;
guint16 len;
guint16 hcrc;
state->avail_in--;
state->next_in++;
if (gz_next1(state, &cm) == -1)
return -1;
if (cm != 8) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = "unknown compression method";
return -1;
}
if (gz_next1(state, &flags) == -1)
return -1;
if (flags & 0xe0) {
state->err = WTAP_ERR_DECOMPRESS;
state->err_info = "reserved flag bits set";
return -1;
}
if (gz_skipn(state, 4) == -1)
return -1;
if (gz_skipn(state, 1) == -1)
return -1;
if (gz_skipn(state, 1) == -1)
return -1;
if (flags & 4) {
if (gz_next2(state, &len) == -1)
return -1;
if (gz_skipn(state, len) == -1)
return -1;
}
if (flags & 8) {
if (gz_skipzstr(state) == -1)
return -1;
}
if (flags & 16) {
if (gz_skipzstr(state) == -1)
return -1;
}
if (flags & 2) {
if (gz_next2(state, &hcrc) == -1)
return -1;
}
inflateReset(&(state->strm));
state->strm.adler = crc32(0L, Z_NULL, 0);
state->compression = ZLIB;
state->is_compressed = TRUE;
#ifdef Z_BLOCK
if (state->fast_seek) {
struct zlib_cur_seek_point *cur = g_new(struct zlib_cur_seek_point,1);
cur->pos = cur->have = 0;
g_free(state->fast_seek_cur);
state->fast_seek_cur = cur;
fast_seek_header(state, state->raw_pos - state->avail_in, state->pos, GZIP_AFTER_HEADER);
}
#endif
return 0;
}
else {
state->out[0] = 31;
state->have = 1;
}
}
#endif
#ifdef HAVE_LIBXZ
#endif
if (state->fast_seek)
fast_seek_header(state, state->raw_pos - state->avail_in - state->have, state->pos, UNCOMPRESSED);
state->raw = state->pos;
state->next = state->out;
if (state->avail_in) {
memcpy(state->next + state->have, state->next_in, state->avail_in);
state->have += state->avail_in;
state->avail_in = 0;
}
state->compression = UNCOMPRESSED;
return 0;
}
static int
fill_out_buffer(FILE_T state)
{
if (state->compression == UNKNOWN) {
if (gz_head(state) == -1)
return -1;
if (state->have)
return 0;
}
if (state->compression == UNCOMPRESSED) {
if (raw_read(state, state->out, state->size , &(state->have)) == -1)
return -1;
state->next = state->out;
}
#ifdef HAVE_LIBZ
else if (state->compression == ZLIB) {
zlib_read(state, state->out, state->size << 1);
}
#endif
return 0;
}
static int
gz_skip(FILE_T state, gint64 len)
{
guint n;
while (len)
if (state->have) {
n = (gint64)state->have > len ? (unsigned)len : state->have;
state->have -= n;
state->next += n;
state->pos += n;
len -= n;
} else if (state->err) {
return -1;
} else if (state->eof && state->avail_in == 0) {
break;
} else {
if (fill_out_buffer(state) == -1)
return -1;
}
return 0;
}
static void
gz_reset(FILE_T state)
{
state->have = 0;
state->eof = FALSE;
state->compression = UNKNOWN;
state->seek_pending = FALSE;
state->err = 0;
state->err_info = NULL;
state->pos = 0;
state->avail_in = 0;
}
FILE_T
file_fdopen(int fd)
{
#ifdef _STATBUF_ST_BLKSIZE
struct stat st;
#endif
int want = GZBUFSIZE;
FILE_T state;
if (fd == -1)
return NULL;
state = (FILE_T)g_try_malloc(sizeof *state);
if (state == NULL)
return NULL;
state->fast_seek_cur = NULL;
state->fast_seek = NULL;
state->fd = fd;
state->is_compressed = FALSE;
state->start = ws_lseek64(state->fd, 0, SEEK_CUR);
if (state->start == -1) state->start = 0;
state->raw_pos = state->start;
gz_reset(state);
#ifdef _STATBUF_ST_BLKSIZE
if (fstat(fd, &st) >= 0) {
want = st.st_blksize;
}
#endif
state->in = (unsigned char *)g_try_malloc(want);
state->out = (unsigned char *)g_try_malloc(want << 1);
state->size = want;
if (state->in == NULL || state->out == NULL) {
g_free(state->out);
g_free(state->in);
g_free(state);
errno = ENOMEM;
return NULL;
}
#ifdef HAVE_LIBZ
state->strm.zalloc = Z_NULL;
state->strm.zfree = Z_NULL;
state->strm.opaque = Z_NULL;
state->strm.avail_in = 0;
state->strm.next_in = Z_NULL;
if (inflateInit2(&(state->strm), -15) != Z_OK) {
g_free(state->out);
g_free(state->in);
g_free(state);
errno = ENOMEM;
return NULL;
}
state->dont_check_crc = FALSE;
#endif
return state;
}
FILE_T
file_open(const char *path)
{
int fd;
FILE_T ft;
#ifdef HAVE_LIBZ
const char *suffixp;
#endif
if ((fd = ws_open(path, O_RDONLY|O_BINARY, 0000)) == -1)
return NULL;
ft = file_fdopen(fd);
if (ft == NULL) {
ws_close(fd);
return NULL;
}
#ifdef HAVE_LIBZ
suffixp = strrchr(path, '.');
if (suffixp != NULL) {
if (g_ascii_strcasecmp(suffixp, ".caz") == 0)
ft->dont_check_crc = TRUE;
}
#endif
return ft;
}
void
file_set_random_access(FILE_T stream, gboolean random_flag _U_, GPtrArray *seek)
{
stream->fast_seek = seek;
}
gint64
file_seek(FILE_T file, gint64 offset, int whence, int *err)
{
struct fast_seek_point *here;
guint n;
if (whence != SEEK_SET && whence != SEEK_CUR) {
g_assert_not_reached();
}
if (whence == SEEK_SET)
offset -= file->pos;
else if (file->seek_pending)
offset += file->skip;
file->seek_pending = FALSE;
if (offset < 0 && file->next) {
guint had = (unsigned)(file->next - file->out);
if (-offset <= had) {
guint adjustment = (unsigned)(-offset);
file->have += adjustment;
file->next -= adjustment;
file->pos -= adjustment;
return file->pos;
}
}
if ((here = fast_seek_find(file, file->pos + offset)) && (offset < 0 || offset > SPAN || here->compression == UNCOMPRESSED)) {
gint64 off, off2;
#ifdef HAVE_LIBZ
if (here->compression == ZLIB) {
#ifdef HAVE_INFLATEPRIME
off = here->in - (here->data.zlib.bits ? 1 : 0);
#else
off = here->in;
#endif
off2 = here->out;
} else if (here->compression == GZIP_AFTER_HEADER) {
off = here->in;
off2 = here->out;
} else
#endif
{
off2 = (file->pos + offset);
off = here->in + (off2 - here->out);
}
if (ws_lseek64(file->fd, off, SEEK_SET) == -1) {
*err = errno;
return -1;
}
fast_seek_reset(file);
file->raw_pos = off;
file->have = 0;
file->eof = FALSE;
file->seek_pending = FALSE;
file->err = 0;
file->err_info = NULL;
file->avail_in = 0;
#ifdef HAVE_LIBZ
if (here->compression == ZLIB) {
z_stream *strm = &file->strm;
inflateReset(strm);
strm->adler = here->data.zlib.adler;
strm->total_out = here->data.zlib.total_out;
#ifdef HAVE_INFLATEPRIME
if (here->data.zlib.bits) {
FILE_T state = file;
int ret = GZ_GETC();
if (ret == -1) {
if (state->err == 0) {
*err = WTAP_ERR_SHORT_READ;
} else
*err = state->err;
return -1;
}
(void)inflatePrime(strm, here->data.zlib.bits, ret >> (8 - here->data.zlib.bits));
}
#endif
(void)inflateSetDictionary(strm, here->data.zlib.window, ZLIB_WINSIZE);
file->compression = ZLIB;
} else if (here->compression == GZIP_AFTER_HEADER) {
z_stream *strm = &file->strm;
inflateReset(strm);
strm->adler = crc32(0L, Z_NULL, 0);
file->compression = ZLIB;
} else
#endif
file->compression = here->compression;
offset = (file->pos + offset) - off2;
file->pos = off2;
if (offset) {
file->seek_pending = TRUE;
file->skip = offset;
}
return file->pos + offset;
}
if (file->compression == UNCOMPRESSED && file->pos + offset >= file->raw
&& (offset < 0 || offset >= file->have) )
{
if (ws_lseek64(file->fd, offset - file->have, SEEK_CUR) == -1) {
*err = errno;
return -1;
}
file->raw_pos += (offset - file->have);
file->have = 0;
file->eof = FALSE;
file->seek_pending = FALSE;
file->err = 0;
file->err_info = NULL;
file->avail_in = 0;
file->pos += offset;
return file->pos;
}
if (offset < 0) {
offset += file->pos;
if (offset < 0) {
*err = EINVAL;
return -1;
}
if (ws_lseek64(file->fd, file->start, SEEK_SET) == -1) {
*err = errno;
return -1;
}
fast_seek_reset(file);
file->raw_pos = file->start;
gz_reset(file);
}
n = (gint64)file->have > offset ? (unsigned)offset : file->have;
file->have -= n;
file->next += n;
file->pos += n;
offset -= n;
if (offset) {
file->seek_pending = TRUE;
file->skip = offset;
}
return file->pos + offset;
}
gint64
file_skip(FILE_T file, gint64 delta, int *err)
{
return file_seek(file, delta, SEEK_CUR, err);
}
gint64
file_tell(FILE_T stream)
{
return stream->pos + (stream->seek_pending ? stream->skip : 0);
}
gint64
file_tell_raw(FILE_T stream)
{
return stream->raw_pos;
}
int
file_fstat(FILE_T stream, ws_statb64 *statb, int *err)
{
if (ws_fstat64(stream->fd, statb) == -1) {
if (err != NULL)
*err = errno;
return -1;
}
return 0;
}
gboolean
file_iscompressed(FILE_T stream)
{
return stream->is_compressed;
}
int
file_read(void *buf, unsigned int len, FILE_T file)
{
guint got, n;
if (len == 0)
return 0;
if (file->seek_pending) {
file->seek_pending = FALSE;
if (gz_skip(file, file->skip) == -1)
return -1;
}
got = 0;
do {
if (file->have) {
n = file->have > len ? len : file->have;
memcpy(buf, file->next, n);
file->next += n;
file->have -= n;
} else if (file->err) {
return -1;
} else if (file->eof && file->avail_in == 0) {
break;
} else {
if (fill_out_buffer(file) == -1)
return -1;
continue;
}
len -= n;
buf = (char *)buf + n;
got += n;
file->pos += n;
} while (len);
return (int)got;
}
int
file_getc(FILE_T file)
{
unsigned char buf[1];
int ret;
if (file->err)
return -1;
if (file->have) {
file->have--;
file->pos++;
return *(file->next)++;
}
ret = file_read(buf, 1, file);
return ret < 1 ? -1 : buf[0];
}
char *
file_gets(char *buf, int len, FILE_T file)
{
guint left, n;
char *str;
unsigned char *eol;
if (buf == NULL || len < 1)
return NULL;
if (file->err)
return NULL;
if (file->seek_pending) {
file->seek_pending = FALSE;
if (gz_skip(file, file->skip) == -1)
return NULL;
}
str = buf;
left = (unsigned)len - 1;
if (left) do {
if (file->have == 0) {
if (file->err) {
return NULL;
}
if (fill_out_buffer(file) == -1)
return NULL;
if (file->have == 0) {
if (buf == str)
return NULL;
break;
}
}
n = file->have > left ? left : file->have;
eol = (unsigned char *)memchr(file->next, '\n', n);
if (eol != NULL)
n = (unsigned)(eol - file->next) + 1;
memcpy(buf, file->next, n);
file->have -= n;
file->next += n;
file->pos += n;
left -= n;
buf += n;
} while (left && eol == NULL);
buf[0] = 0;
return str;
}
int
file_eof(FILE_T file)
{
return (file->eof && file->avail_in == 0 && file->have == 0);
}
int
file_error(FILE_T fh, gchar **err_info)
{
if (fh->err != 0) {
*err_info = (fh->err_info == NULL) ? NULL : g_strdup(fh->err_info);
return fh->err;
}
return 0;
}
void
file_clearerr(FILE_T stream)
{
stream->err = 0;
stream->err_info = NULL;
stream->eof = FALSE;
}
void
file_fdclose(FILE_T file)
{
ws_close(file->fd);
file->fd = -1;
}
gboolean
file_fdreopen(FILE_T file, const char *path)
{
int fd;
if ((fd = ws_open(path, O_RDONLY|O_BINARY, 0000)) == -1)
return FALSE;
file->fd = fd;
return TRUE;
}
void
file_close(FILE_T file)
{
int fd = file->fd;
if (file->size) {
#ifdef HAVE_LIBZ
inflateEnd(&(file->strm));
#endif
g_free(file->out);
g_free(file->in);
}
g_free(file->fast_seek_cur);
file->err = 0;
file->err_info = NULL;
g_free(file);
if (fd != -1)
ws_close(fd);
}
GZWFILE_T
gzwfile_open(const char *path)
{
int fd;
GZWFILE_T state;
int save_errno;
fd = ws_open(path, O_BINARY|O_WRONLY|O_CREAT|O_TRUNC, 0666);
if (fd == -1)
return NULL;
state = gzwfile_fdopen(fd);
if (state == NULL) {
save_errno = errno;
close(fd);
errno = save_errno;
}
return state;
}
GZWFILE_T
gzwfile_fdopen(int fd)
{
GZWFILE_T state;
state = (GZWFILE_T)g_try_malloc(sizeof *state);
if (state == NULL)
return NULL;
state->fd = fd;
state->size = 0;
state->want = GZBUFSIZE;
state->level = Z_DEFAULT_COMPRESSION;
state->strategy = Z_DEFAULT_STRATEGY;
state->err = Z_OK;
state->pos = 0;
state->strm.avail_in = 0;
return state;
}
static int
gz_init(GZWFILE_T state)
{
int ret;
z_streamp strm = &(state->strm);
state->in = (unsigned char *)g_try_malloc(state->want);
state->out = (unsigned char *)g_try_malloc(state->want);
if (state->in == NULL || state->out == NULL) {
g_free(state->out);
g_free(state->in);
state->err = ENOMEM;
return -1;
}
strm->zalloc = Z_NULL;
strm->zfree = Z_NULL;
strm->opaque = Z_NULL;
ret = deflateInit2(strm, state->level, Z_DEFLATED,
15 + 16, 8, state->strategy);
if (ret != Z_OK) {
g_free(state->out);
g_free(state->in);
if (ret == Z_MEM_ERROR) {
state->err = ENOMEM;
} else {
state->err = WTAP_ERR_INTERNAL;
}
return -1;
}
state->size = state->want;
strm->avail_out = state->size;
strm->next_out = state->out;
state->next = strm->next_out;
return 0;
}
static int
gz_comp(GZWFILE_T state, int flush)
{
int ret;
ssize_t got;
ptrdiff_t have;
z_streamp strm = &(state->strm);
if (state->size == 0 && gz_init(state) == -1)
return -1;
ret = Z_OK;
do {
if (strm->avail_out == 0 || (flush != Z_NO_FLUSH &&
(flush != Z_FINISH || ret == Z_STREAM_END))) {
have = strm->next_out - state->next;
if (have) {
got = write(state->fd, state->next, (unsigned int)have);
if (got < 0) {
state->err = errno;
return -1;
}
if ((ptrdiff_t)got != have) {
state->err = WTAP_ERR_SHORT_WRITE;
return -1;
}
}
if (strm->avail_out == 0) {
strm->avail_out = state->size;
strm->next_out = state->out;
}
state->next = strm->next_out;
}
have = strm->avail_out;
ret = deflate(strm, flush);
if (ret == Z_STREAM_ERROR) {
state->err = WTAP_ERR_INTERNAL;
return -1;
}
have -= strm->avail_out;
} while (have);
if (flush == Z_FINISH)
deflateReset(strm);
return 0;
}
unsigned
gzwfile_write(GZWFILE_T state, const void *buf, guint len)
{
guint put = len;
guint n;
z_streamp strm;
strm = &(state->strm);
if (state->err != Z_OK)
return 0;
if (len == 0)
return 0;
if (state->size == 0 && gz_init(state) == -1)
return 0;
if (len < state->size) {
do {
if (strm->avail_in == 0)
strm->next_in = state->in;
n = state->size - strm->avail_in;
if (n > len)
n = len;
memcpy(strm->next_in + strm->avail_in, buf, n);
strm->avail_in += n;
state->pos += n;
buf = (char *)buf + n;
len -= n;
if (len && gz_comp(state, Z_NO_FLUSH) == -1)
return 0;
} while (len);
}
else {
if (strm->avail_in && gz_comp(state, Z_NO_FLUSH) == -1)
return 0;
strm->avail_in = len;
strm->next_in = (Bytef *)buf;
state->pos += len;
if (gz_comp(state, Z_NO_FLUSH) == -1)
return 0;
}
return (int)put;
}
int
gzwfile_flush(GZWFILE_T state)
{
if (state->err != Z_OK)
return -1;
gz_comp(state, Z_SYNC_FLUSH);
if (state->err != Z_OK)
return -1;
return 0;
}
int
gzwfile_close(GZWFILE_T state)
{
int ret = 0;
if (gz_comp(state, Z_FINISH) == -1 && ret == 0)
ret = state->err;
(void)deflateEnd(&(state->strm));
g_free(state->out);
g_free(state->in);
state->err = Z_OK;
if (close(state->fd) == -1 && ret == 0)
ret = errno;
g_free(state);
return ret;
}
int
gzwfile_geterr(GZWFILE_T state)
{
return state->err;
}
