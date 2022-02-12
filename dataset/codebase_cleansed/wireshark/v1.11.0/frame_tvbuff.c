static gboolean
frame_read(struct tvb_frame *frame_tvb, struct wtap_pkthdr *phdr, Buffer *buf)
{
int err;
gchar *err_info;
if (cfile.wth != frame_tvb->wth)
return FALSE;
if (!wtap_seek_read(frame_tvb->wth, frame_tvb->file_off, phdr, buf, frame_tvb->tvb.length + frame_tvb->offset, &err, &err_info)) {
switch (err) {
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
g_free(err_info);
break;
}
return FALSE;
}
return TRUE;
}
static void
frame_cache(struct tvb_frame *frame_tvb)
{
struct wtap_pkthdr phdr;
if (frame_tvb->buf == NULL) {
frame_tvb->buf = (struct Buffer *) g_malloc(sizeof(struct Buffer));
buffer_init(frame_tvb->buf, frame_tvb->tvb.length + frame_tvb->offset);
if (!frame_read(frame_tvb, &phdr, frame_tvb->buf))
{ }
}
frame_tvb->tvb.real_data = buffer_start_ptr(frame_tvb->buf) + frame_tvb->offset;
}
static void
frame_free(tvbuff_t *tvb)
{
struct tvb_frame *frame_tvb = (struct tvb_frame *) tvb;
if (frame_tvb->buf) {
buffer_free(frame_tvb->buf);
g_free(frame_tvb->buf);
}
}
static const guint8 *
frame_get_ptr(tvbuff_t *tvb, guint abs_offset, guint abs_length _U_)
{
struct tvb_frame *frame_tvb = (struct tvb_frame *) tvb;
frame_cache(frame_tvb);
return tvb->real_data + abs_offset;
}
static void *
frame_memcpy(tvbuff_t *tvb, void *target, guint abs_offset, guint abs_length)
{
struct tvb_frame *frame_tvb = (struct tvb_frame *) tvb;
frame_cache(frame_tvb);
return memcpy(target, tvb->real_data + abs_offset, abs_length);
}
static gint
frame_find_guint8(tvbuff_t *tvb, guint abs_offset, guint limit, guint8 needle)
{
struct tvb_frame *frame_tvb = (struct tvb_frame *) tvb;
const guint8 *result;
frame_cache(frame_tvb);
result = (const guint8 *)memchr(tvb->real_data + abs_offset, needle, limit);
if (result)
return (gint) (result - tvb->real_data);
else
return -1;
}
static gint
frame_pbrk_guint8(tvbuff_t *tvb, guint abs_offset, guint limit, const guint8 *needles, guchar *found_needle)
{
struct tvb_frame *frame_tvb = (struct tvb_frame *) tvb;
frame_cache(frame_tvb);
return tvb_pbrk_guint8(tvb, abs_offset, limit, needles, found_needle);
}
static guint
frame_offset(const tvbuff_t *tvb _U_, const guint counter)
{
return counter;
}
tvbuff_t *
frame_tvbuff_new(const frame_data *fd, const guint8 *buf)
{
struct tvb_frame *frame_tvb;
tvbuff_t *tvb;
tvb = tvb_new(&tvb_frame_ops);
tvb->real_data = buf;
tvb->length = fd->cap_len;
tvb->reported_length = fd->pkt_len > G_MAXINT ? G_MAXINT : fd->pkt_len;
tvb->initialized = TRUE;
tvb->ds_tvb = tvb;
frame_tvb = (struct tvb_frame *) tvb;
if (cfile.wth && cfile.wth->random_fh
#ifdef WANT_PACKET_EDITOR
&& fd->file_off != -1
#endif
) {
frame_tvb->wth = cfile.wth;
frame_tvb->file_off = fd->file_off;
frame_tvb->offset = 0;
} else
frame_tvb->wth = NULL;
frame_tvb->buf = NULL;
return tvb;
}
tvbuff_t *
frame_tvbuff_new_buffer(const frame_data *fd, Buffer *buf)
{
return frame_tvbuff_new(fd, buffer_start_ptr(buf));
}
static tvbuff_t *
frame_clone(tvbuff_t *tvb, guint abs_offset, guint abs_length)
{
struct tvb_frame *frame_tvb = (struct tvb_frame *) tvb;
tvbuff_t *cloned_tvb;
struct tvb_frame *cloned_frame_tvb;
if (!frame_tvb->wth)
return NULL;
abs_offset += frame_tvb->offset;
cloned_tvb = tvb_new(&tvb_frame_ops);
cloned_tvb->real_data = NULL;
cloned_tvb->length = abs_length;
cloned_tvb->reported_length = abs_length;
cloned_tvb->initialized = TRUE;
cloned_tvb->ds_tvb = cloned_tvb;
cloned_frame_tvb = (struct tvb_frame *) cloned_tvb;
cloned_frame_tvb->wth = frame_tvb->wth;
cloned_frame_tvb->file_off = frame_tvb->file_off;
cloned_frame_tvb->offset = abs_offset;
cloned_frame_tvb->buf = NULL;
return cloned_tvb;
}
