int RSA_padding_add_X931(unsigned char *to, int tlen,
const unsigned char *from, int flen)
{
int j;
unsigned char *p;
j = tlen - flen - 2;
if (j < 0) {
RSAerr(RSA_F_RSA_PADDING_ADD_X931, RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
return -1;
}
p = (unsigned char *)to;
if (j == 0)
*p++ = 0x6A;
else {
*p++ = 0x6B;
if (j > 1) {
memset(p, 0xBB, j - 1);
p += j - 1;
}
*p++ = 0xBA;
}
memcpy(p, from, (unsigned int)flen);
p += flen;
*p = 0xCC;
return (1);
}
int RSA_padding_check_X931(unsigned char *to, int tlen,
const unsigned char *from, int flen, int num)
{
int i = 0, j;
const unsigned char *p;
p = from;
if ((num != flen) || ((*p != 0x6A) && (*p != 0x6B))) {
RSAerr(RSA_F_RSA_PADDING_CHECK_X931, RSA_R_INVALID_HEADER);
return -1;
}
if (*p++ == 0x6B) {
j = flen - 3;
for (i = 0; i < j; i++) {
unsigned char c = *p++;
if (c == 0xBA)
break;
if (c != 0xBB) {
RSAerr(RSA_F_RSA_PADDING_CHECK_X931, RSA_R_INVALID_PADDING);
return -1;
}
}
j -= i;
if (i == 0) {
RSAerr(RSA_F_RSA_PADDING_CHECK_X931, RSA_R_INVALID_PADDING);
return -1;
}
} else
j = flen - 2;
if (p[j] != 0xCC) {
RSAerr(RSA_F_RSA_PADDING_CHECK_X931, RSA_R_INVALID_TRAILER);
return -1;
}
memcpy(to, p, (unsigned int)j);
return (j);
}
int RSA_X931_hash_id(int nid)
{
switch (nid) {
case NID_sha1:
return 0x33;
case NID_sha256:
return 0x34;
case NID_sha384:
return 0x36;
case NID_sha512:
return 0x35;
}
return -1;
}
