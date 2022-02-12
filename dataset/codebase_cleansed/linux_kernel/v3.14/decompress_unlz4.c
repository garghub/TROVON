STATIC inline int INIT unlz4(u8 *input, int in_len,
int (*fill) (void *, unsigned int),
int (*flush) (void *, unsigned int),
u8 *output, int *posp,
void (*error) (char *x))
{
int ret = -1;
size_t chunksize = 0;
size_t uncomp_chunksize = LZ4_DEFAULT_UNCOMPRESSED_CHUNK_SIZE;
u8 *inp;
u8 *inp_start;
u8 *outp;
int size = in_len;
#ifdef PREBOOT
size_t out_len = get_unaligned_le32(input + in_len);
#endif
size_t dest_len;
if (output) {
outp = output;
} else if (!flush) {
error("NULL output pointer and no flush function provided");
goto exit_0;
} else {
outp = large_malloc(uncomp_chunksize);
if (!outp) {
error("Could not allocate output buffer");
goto exit_0;
}
}
if (input && fill) {
error("Both input pointer and fill function provided,");
goto exit_1;
} else if (input) {
inp = input;
} else if (!fill) {
error("NULL input pointer and missing fill function");
goto exit_1;
} else {
inp = large_malloc(lz4_compressbound(uncomp_chunksize));
if (!inp) {
error("Could not allocate input buffer");
goto exit_1;
}
}
inp_start = inp;
if (posp)
*posp = 0;
if (fill)
fill(inp, 4);
chunksize = get_unaligned_le32(inp);
if (chunksize == ARCHIVE_MAGICNUMBER) {
inp += 4;
size -= 4;
} else {
error("invalid header");
goto exit_2;
}
if (posp)
*posp += 4;
for (;;) {
if (fill)
fill(inp, 4);
chunksize = get_unaligned_le32(inp);
if (chunksize == ARCHIVE_MAGICNUMBER) {
inp += 4;
size -= 4;
if (posp)
*posp += 4;
continue;
}
inp += 4;
size -= 4;
if (posp)
*posp += 4;
if (fill) {
if (chunksize > lz4_compressbound(uncomp_chunksize)) {
error("chunk length is longer than allocated");
goto exit_2;
}
fill(inp, chunksize);
}
#ifdef PREBOOT
if (out_len >= uncomp_chunksize) {
dest_len = uncomp_chunksize;
out_len -= dest_len;
} else
dest_len = out_len;
ret = lz4_decompress(inp, &chunksize, outp, dest_len);
#else
dest_len = uncomp_chunksize;
ret = lz4_decompress_unknownoutputsize(inp, chunksize, outp,
&dest_len);
#endif
if (ret < 0) {
error("Decoding failed");
goto exit_2;
}
ret = -1;
if (flush && flush(outp, dest_len) != dest_len)
goto exit_2;
if (output)
outp += dest_len;
if (posp)
*posp += chunksize;
size -= chunksize;
if (size == 0)
break;
else if (size < 0) {
error("data corrupted");
goto exit_2;
}
inp += chunksize;
if (fill)
inp = inp_start;
}
ret = 0;
exit_2:
if (!input)
large_free(inp_start);
exit_1:
if (!output)
large_free(outp);
exit_0:
return ret;
}
STATIC int INIT decompress(unsigned char *buf, int in_len,
int(*fill)(void*, unsigned int),
int(*flush)(void*, unsigned int),
unsigned char *output,
int *posp,
void(*error)(char *x)
)
{
return unlz4(buf, in_len - 4, fill, flush, output, posp, error);
}
