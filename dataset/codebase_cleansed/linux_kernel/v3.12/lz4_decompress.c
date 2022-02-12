static int lz4_uncompress(const char *source, char *dest, int osize)
{
const BYTE *ip = (const BYTE *) source;
const BYTE *ref;
BYTE *op = (BYTE *) dest;
BYTE * const oend = op + osize;
BYTE *cpy;
unsigned token;
size_t length;
size_t dec32table[] = {0, 3, 2, 3, 0, 0, 0, 0};
#if LZ4_ARCH64
size_t dec64table[] = {0, 0, 0, -1, 0, 1, 2, 3};
#endif
while (1) {
token = *ip++;
length = (token >> ML_BITS);
if (length == RUN_MASK) {
size_t len;
len = *ip++;
for (; len == 255; length += 255)
len = *ip++;
length += len;
}
cpy = op + length;
if (unlikely(cpy > oend - COPYLENGTH)) {
if (cpy != oend)
goto _output_error;
memcpy(op, ip, length);
ip += length;
break;
}
LZ4_WILDCOPY(ip, op, cpy);
ip -= (op - cpy);
op = cpy;
LZ4_READ_LITTLEENDIAN_16(ref, cpy, ip);
ip += 2;
if (unlikely(ref < (BYTE *const) dest))
goto _output_error;
length = token & ML_MASK;
if (length == ML_MASK) {
for (; *ip == 255; length += 255)
ip++;
length += *ip++;
}
if (unlikely((op - ref) < STEPSIZE)) {
#if LZ4_ARCH64
size_t dec64 = dec64table[op - ref];
#else
const int dec64 = 0;
#endif
op[0] = ref[0];
op[1] = ref[1];
op[2] = ref[2];
op[3] = ref[3];
op += 4;
ref += 4;
ref -= dec32table[op-ref];
PUT4(ref, op);
op += STEPSIZE - 4;
ref -= dec64;
} else {
LZ4_COPYSTEP(ref, op);
}
cpy = op + length - (STEPSIZE - 4);
if (cpy > (oend - COPYLENGTH)) {
if (cpy > oend)
goto _output_error;
LZ4_SECURECOPY(ref, op, (oend - COPYLENGTH));
while (op < cpy)
*op++ = *ref++;
op = cpy;
if (op == oend)
goto _output_error;
continue;
}
LZ4_SECURECOPY(ref, op, cpy);
op = cpy;
}
return (int) (((char *)ip) - source);
_output_error:
return (int) (-(((char *)ip) - source));
}
static int lz4_uncompress_unknownoutputsize(const char *source, char *dest,
int isize, size_t maxoutputsize)
{
const BYTE *ip = (const BYTE *) source;
const BYTE *const iend = ip + isize;
const BYTE *ref;
BYTE *op = (BYTE *) dest;
BYTE * const oend = op + maxoutputsize;
BYTE *cpy;
size_t dec32table[] = {0, 3, 2, 3, 0, 0, 0, 0};
#if LZ4_ARCH64
size_t dec64table[] = {0, 0, 0, -1, 0, 1, 2, 3};
#endif
while (ip < iend) {
unsigned token;
size_t length;
token = *ip++;
length = (token >> ML_BITS);
if (length == RUN_MASK) {
int s = 255;
while ((ip < iend) && (s == 255)) {
s = *ip++;
length += s;
}
}
cpy = op + length;
if ((cpy > oend - COPYLENGTH) ||
(ip + length > iend - COPYLENGTH)) {
if (cpy > oend)
goto _output_error;
if (ip + length != iend)
goto _output_error;
memcpy(op, ip, length);
op += length;
break;
}
LZ4_WILDCOPY(ip, op, cpy);
ip -= (op - cpy);
op = cpy;
LZ4_READ_LITTLEENDIAN_16(ref, cpy, ip);
ip += 2;
if (ref < (BYTE * const) dest)
goto _output_error;
length = (token & ML_MASK);
if (length == ML_MASK) {
while (ip < iend) {
int s = *ip++;
length += s;
if (s == 255)
continue;
break;
}
}
if (unlikely((op - ref) < STEPSIZE)) {
#if LZ4_ARCH64
size_t dec64 = dec64table[op - ref];
#else
const int dec64 = 0;
#endif
op[0] = ref[0];
op[1] = ref[1];
op[2] = ref[2];
op[3] = ref[3];
op += 4;
ref += 4;
ref -= dec32table[op - ref];
PUT4(ref, op);
op += STEPSIZE - 4;
ref -= dec64;
} else {
LZ4_COPYSTEP(ref, op);
}
cpy = op + length - (STEPSIZE-4);
if (cpy > oend - COPYLENGTH) {
if (cpy > oend)
goto _output_error;
LZ4_SECURECOPY(ref, op, (oend - COPYLENGTH));
while (op < cpy)
*op++ = *ref++;
op = cpy;
if (op == oend)
goto _output_error;
continue;
}
LZ4_SECURECOPY(ref, op, cpy);
op = cpy;
}
return (int) (((char *) op) - dest);
_output_error:
return (int) (-(((char *) ip) - source));
}
int lz4_decompress(const unsigned char *src, size_t *src_len,
unsigned char *dest, size_t actual_dest_len)
{
int ret = -1;
int input_len = 0;
input_len = lz4_uncompress(src, dest, actual_dest_len);
if (input_len < 0)
goto exit_0;
*src_len = input_len;
return 0;
exit_0:
return ret;
}
int lz4_decompress_unknownoutputsize(const unsigned char *src, size_t src_len,
unsigned char *dest, size_t *dest_len)
{
int ret = -1;
int out_len = 0;
out_len = lz4_uncompress_unknownoutputsize(src, dest, src_len,
*dest_len);
if (out_len < 0)
goto exit_0;
*dest_len = out_len;
return 0;
exit_0:
return ret;
}
