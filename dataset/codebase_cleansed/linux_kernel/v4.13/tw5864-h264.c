static void bs_init(struct bs *s, void *buf, int size)
{
s->buf = buf;
s->ptr = buf;
s->buf_end = s->ptr + size;
s->bits_left = 8;
}
static int bs_len(struct bs *s)
{
return s->ptr - s->buf;
}
static void bs_write(struct bs *s, int count, u32 bits)
{
if (s->ptr >= s->buf_end - 4)
return;
while (count > 0) {
if (count < 32)
bits &= (1 << count) - 1;
if (count < s->bits_left) {
*s->ptr = (*s->ptr << count) | bits;
s->bits_left -= count;
break;
}
*s->ptr = (*s->ptr << s->bits_left) |
(bits >> (count - s->bits_left));
count -= s->bits_left;
s->ptr++;
s->bits_left = 8;
}
}
static void bs_write1(struct bs *s, u32 bit)
{
if (s->ptr < s->buf_end) {
*s->ptr <<= 1;
*s->ptr |= bit;
s->bits_left--;
if (s->bits_left == 0) {
s->ptr++;
s->bits_left = 8;
}
}
}
static void bs_write_ue(struct bs *s, u32 val)
{
if (val == 0) {
bs_write1(s, 1);
} else {
val++;
bs_write(s, 2 * fls(val) - 1, val);
}
}
static void bs_write_se(struct bs *s, int val)
{
bs_write_ue(s, val <= 0 ? -val * 2 : val * 2 - 1);
}
static void bs_rbsp_trailing(struct bs *s)
{
bs_write1(s, 1);
if (s->bits_left != 8)
bs_write(s, s->bits_left, 0x00);
}
static int tw5864_h264_gen_sps_rbsp(u8 *buf, size_t size, int width, int height)
{
struct bs bs, *s;
s = &bs;
bs_init(s, buf, size);
bs_write(s, 8, 0x42);
bs_write(s, 1, 1);
bs_write(s, 1, 1);
bs_write(s, 1, 0);
bs_write(s, 5, 0);
bs_write(s, 8, 0x1e);
bs_write_ue(s, 0);
bs_write_ue(s, ilog2(MAX_GOP_SIZE) - 4);
bs_write_ue(s, 0);
bs_write_ue(s, ilog2(MAX_GOP_SIZE) - 4);
bs_write_ue(s, 1);
bs_write(s, 1, 0);
bs_write_ue(s, width / 16 - 1);
bs_write_ue(s, height / 16 - 1);
bs_write(s, 1, 1);
bs_write(s, 1, 0);
bs_write(s, 1, 0);
bs_write(s, 1, 0);
bs_rbsp_trailing(s);
return bs_len(s);
}
static int tw5864_h264_gen_pps_rbsp(u8 *buf, size_t size, int qp)
{
struct bs bs, *s;
s = &bs;
bs_init(s, buf, size);
bs_write_ue(s, 0);
bs_write_ue(s, 0);
bs_write(s, 1, 0);
bs_write(s, 1, 0);
bs_write_ue(s, 0);
bs_write_ue(s, 0);
bs_write_ue(s, 0);
bs_write(s, 1, 0);
bs_write(s, 2, 0);
bs_write_se(s, qp - 26);
bs_write_se(s, qp - 26);
bs_write_se(s, 0);
bs_write(s, 1, 0);
bs_write(s, 1, 0);
bs_write(s, 1, 0);
bs_rbsp_trailing(s);
return bs_len(s);
}
static int tw5864_h264_gen_slice_head(u8 *buf, size_t size,
unsigned int idr_pic_id,
unsigned int frame_gop_seqno,
int *tail_nb_bits, u8 *tail)
{
struct bs bs, *s;
int is_i_frame = frame_gop_seqno == 0;
s = &bs;
bs_init(s, buf, size);
bs_write_ue(s, 0);
bs_write_ue(s, is_i_frame ? 2 : 5);
bs_write_ue(s, 0);
bs_write(s, ilog2(MAX_GOP_SIZE), frame_gop_seqno);
if (is_i_frame)
bs_write_ue(s, idr_pic_id);
bs_write(s, ilog2(MAX_GOP_SIZE), frame_gop_seqno);
if (is_i_frame) {
bs_write1(s, 0);
bs_write1(s, 0);
} else {
bs_write1(s, 0);
bs_write1(s, 0);
bs_write1(s, 0);
}
bs_write_se(s, 0);
if (s->bits_left != 8) {
*tail = ((s->ptr[0]) << s->bits_left);
*tail_nb_bits = 8 - s->bits_left;
} else {
*tail = 0;
*tail_nb_bits = 0;
}
return bs_len(s);
}
void tw5864_h264_put_stream_header(u8 **buf, size_t *space_left, int qp,
int width, int height)
{
int nal_len;
memcpy(*buf, marker, sizeof(marker));
*buf += 4;
*space_left -= 4;
**buf = 0x67;
*buf += 1;
*space_left -= 1;
nal_len = tw5864_h264_gen_sps_rbsp(*buf, *space_left, width, height);
*buf += nal_len;
*space_left -= nal_len;
memcpy(*buf, marker, sizeof(marker));
*buf += 4;
*space_left -= 4;
**buf = 0x68;
*buf += 1;
*space_left -= 1;
nal_len = tw5864_h264_gen_pps_rbsp(*buf, *space_left, qp);
*buf += nal_len;
*space_left -= nal_len;
}
void tw5864_h264_put_slice_header(u8 **buf, size_t *space_left,
unsigned int idr_pic_id,
unsigned int frame_gop_seqno,
int *tail_nb_bits, u8 *tail)
{
int nal_len;
memcpy(*buf, marker, sizeof(marker));
*buf += 4;
*space_left -= 4;
**buf = (frame_gop_seqno == 0) ? 0x25 : 0x21;
*buf += 1;
*space_left -= 1;
nal_len = tw5864_h264_gen_slice_head(*buf, *space_left, idr_pic_id,
frame_gop_seqno, tail_nb_bits,
tail);
*buf += nal_len;
*space_left -= nal_len;
}
