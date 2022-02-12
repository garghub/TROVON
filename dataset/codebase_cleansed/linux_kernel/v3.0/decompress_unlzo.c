STATIC inline int INIT parse_header(u8 *input, int *skip, int in_len)
{
int l;
u8 *parse = input;
u8 *end = input + in_len;
u8 level = 0;
u16 version;
if (in_len < HEADER_SIZE_MIN)
return 0;
for (l = 0; l < 9; l++) {
if (*parse++ != lzop_magic[l])
return 0;
}
version = get_unaligned_be16(parse);
parse += 7;
if (version >= 0x0940)
level = *parse++;
if (get_unaligned_be32(parse) & HEADER_HAS_FILTER)
parse += 8;
else
parse += 4;
if (end - parse < 8 + 1 + 4)
return 0;
parse += 8;
if (version >= 0x0940)
parse += 4;
l = *parse++;
if (end - parse < l + 4)
return 0;
parse += l + 4;
*skip = parse - input;
return 1;
}
STATIC inline int INIT unlzo(u8 *input, int in_len,
int (*fill) (void *, unsigned int),
int (*flush) (void *, unsigned int),
u8 *output, int *posp,
void (*error) (char *x))
{
u8 r = 0;
int skip = 0;
u32 src_len, dst_len;
size_t tmp;
u8 *in_buf, *in_buf_save, *out_buf;
int ret = -1;
if (output) {
out_buf = output;
} else if (!flush) {
error("NULL output pointer and no flush function provided");
goto exit;
} else {
out_buf = malloc(LZO_BLOCK_SIZE);
if (!out_buf) {
error("Could not allocate output buffer");
goto exit;
}
}
if (input && fill) {
error("Both input pointer and fill function provided, don't know what to do");
goto exit_1;
} else if (input) {
in_buf = input;
} else if (!fill) {
error("NULL input pointer and missing fill function");
goto exit_1;
} else {
in_buf = malloc(lzo1x_worst_compress(LZO_BLOCK_SIZE));
if (!in_buf) {
error("Could not allocate input buffer");
goto exit_1;
}
}
in_buf_save = in_buf;
if (posp)
*posp = 0;
if (fill) {
in_buf += HEADER_SIZE_MAX;
in_len = fill(in_buf, HEADER_SIZE_MAX);
}
if (!parse_header(in_buf, &skip, in_len)) {
error("invalid header");
goto exit_2;
}
in_buf += skip;
in_len -= skip;
if (fill) {
memcpy(in_buf_save, in_buf, in_len);
in_buf = in_buf_save;
}
if (posp)
*posp = skip;
for (;;) {
if (fill && in_len < 4) {
skip = fill(in_buf + in_len, 4 - in_len);
if (skip > 0)
in_len += skip;
}
if (in_len < 4) {
error("file corrupted");
goto exit_2;
}
dst_len = get_unaligned_be32(in_buf);
in_buf += 4;
in_len -= 4;
if (dst_len == 0) {
if (posp)
*posp += 4;
break;
}
if (dst_len > LZO_BLOCK_SIZE) {
error("dest len longer than block size");
goto exit_2;
}
if (fill && in_len < 8) {
skip = fill(in_buf + in_len, 8 - in_len);
if (skip > 0)
in_len += skip;
}
if (in_len < 8) {
error("file corrupted");
goto exit_2;
}
src_len = get_unaligned_be32(in_buf);
in_buf += 8;
in_len -= 8;
if (src_len <= 0 || src_len > dst_len) {
error("file corrupted");
goto exit_2;
}
if (fill && in_len < src_len) {
skip = fill(in_buf + in_len, src_len - in_len);
if (skip > 0)
in_len += skip;
}
if (in_len < src_len) {
error("file corrupted");
goto exit_2;
}
tmp = dst_len;
if (unlikely(dst_len == src_len))
memcpy(out_buf, in_buf, src_len);
else {
r = lzo1x_decompress_safe((u8 *) in_buf, src_len,
out_buf, &tmp);
if (r != LZO_E_OK || dst_len != tmp) {
error("Compressed data violation");
goto exit_2;
}
}
if (flush && flush(out_buf, dst_len) != dst_len)
goto exit_2;
if (output)
out_buf += dst_len;
if (posp)
*posp += src_len + 12;
in_buf += src_len;
in_len -= src_len;
if (fill) {
if (in_len > 0)
for (skip = 0; skip < in_len; ++skip)
in_buf_save[skip] = in_buf[skip];
in_buf = in_buf_save;
}
}
ret = 0;
exit_2:
if (!input)
free(in_buf);
exit_1:
if (!output)
free(out_buf);
exit:
return ret;
}
