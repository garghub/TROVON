int RSA_padding_add_SSLv23(unsigned char *to, int tlen,
const unsigned char *from, int flen)
{
int i, j;
unsigned char *p;
if (flen > (tlen - 11)) {
RSAerr(RSA_F_RSA_PADDING_ADD_SSLV23,
RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
return (0);
}
p = (unsigned char *)to;
*(p++) = 0;
*(p++) = 2;
j = tlen - 3 - 8 - flen;
if (RAND_bytes(p, j) <= 0)
return (0);
for (i = 0; i < j; i++) {
if (*p == '\0')
do {
if (RAND_bytes(p, 1) <= 0)
return (0);
} while (*p == '\0');
p++;
}
memset(p, 3, 8);
p += 8;
*(p++) = '\0';
memcpy(p, from, (unsigned int)flen);
return (1);
}
int RSA_padding_check_SSLv23(unsigned char *to, int tlen,
const unsigned char *from, int flen, int num)
{
int i, j, k;
const unsigned char *p;
p = from;
if (flen < 10) {
RSAerr(RSA_F_RSA_PADDING_CHECK_SSLV23, RSA_R_DATA_TOO_SMALL);
return (-1);
}
if ((num != (flen + 1)) || (*(p++) != 02)) {
RSAerr(RSA_F_RSA_PADDING_CHECK_SSLV23, RSA_R_BLOCK_TYPE_IS_NOT_02);
return (-1);
}
j = flen - 1;
for (i = 0; i < j; i++)
if (*(p++) == 0)
break;
if ((i == j) || (i < 8)) {
RSAerr(RSA_F_RSA_PADDING_CHECK_SSLV23,
RSA_R_NULL_BEFORE_BLOCK_MISSING);
return (-1);
}
for (k = -9; k < -1; k++) {
if (p[k] != 0x03)
break;
}
if (k == -1) {
RSAerr(RSA_F_RSA_PADDING_CHECK_SSLV23, RSA_R_SSLV3_ROLLBACK_ATTACK);
return (-1);
}
i++;
j -= i;
if (j > tlen) {
RSAerr(RSA_F_RSA_PADDING_CHECK_SSLV23, RSA_R_DATA_TOO_LARGE);
return (-1);
}
memcpy(to, p, (unsigned int)j);
return (j);
}
