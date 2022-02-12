int ws_base32_decode(guint8* output, const guint32 outputLength,
const guint8* in, const guint32 inputLength)
{
guint32 outIndex = 0;
guint32 inIndex = 0;
guint32 work = 0;
guint32 bits = 0;
static const guint8* kChars = (guint8*) "0123456789bcdfghjklmnpqrstuvwxyz";
while (inIndex < inputLength) {
work |= ((unsigned) in[inIndex++]) << bits;
bits += 8;
while (bits >= 5) {
if (outIndex >= outputLength) {
return Base32_TOO_BIG;
}
output[outIndex++] = kChars[work & 31];
bits -= 5;
work >>= 5;
}
}
if (bits) {
if (outIndex >= outputLength) {
return Base32_TOO_BIG;
}
output[outIndex++] = kChars[work & 31];
}
if (outIndex < outputLength) {
output[outIndex] = '\0';
}
return outIndex;
}
