int RSA_padding_add_PKCS1_type_1(unsigned char *to, int tlen,
const unsigned char *from, int flen)
{
int j;
unsigned char *p;
if (flen > (tlen - RSA_PKCS1_PADDING_SIZE)) {
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_TYPE_1,
RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
return (0);
}
p = (unsigned char *)to;
*(p++) = 0;
*(p++) = 1;
j = tlen - 3 - flen;
memset(p, 0xff, j);
p += j;
*(p++) = '\0';
memcpy(p, from, (unsigned int)flen);
return (1);
}
int RSA_padding_check_PKCS1_type_1(unsigned char *to, int tlen,
const unsigned char *from, int flen,
int num)
{
int i, j;
const unsigned char *p;
p = from;
if ((num != (flen + 1)) || (*(p++) != 01)) {
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_1,
RSA_R_BLOCK_TYPE_IS_NOT_01);
return (-1);
}
j = flen - 1;
for (i = 0; i < j; i++) {
if (*p != 0xff) {
if (*p == 0) {
p++;
break;
} else {
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_1,
RSA_R_BAD_FIXED_HEADER_DECRYPT);
return (-1);
}
}
p++;
}
if (i == j) {
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_1,
RSA_R_NULL_BEFORE_BLOCK_MISSING);
return (-1);
}
if (i < 8) {
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_1,
RSA_R_BAD_PAD_BYTE_COUNT);
return (-1);
}
i++;
j -= i;
if (j > tlen) {
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_1, RSA_R_DATA_TOO_LARGE);
return (-1);
}
memcpy(to, p, (unsigned int)j);
return (j);
}
int RSA_padding_add_PKCS1_type_2(unsigned char *to, int tlen,
const unsigned char *from, int flen)
{
int i, j;
unsigned char *p;
if (flen > (tlen - 11)) {
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_TYPE_2,
RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
return (0);
}
p = (unsigned char *)to;
*(p++) = 0;
*(p++) = 2;
j = tlen - 3 - flen;
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
*(p++) = '\0';
memcpy(p, from, (unsigned int)flen);
return (1);
}
int RSA_padding_check_PKCS1_type_2(unsigned char *to, int tlen,
const unsigned char *from, int flen,
int num)
{
int i;
unsigned char *em = NULL;
unsigned int good, found_zero_byte;
int zero_index = 0, msg_index, mlen = -1;
if (tlen < 0 || flen < 0)
return -1;
if (flen > num)
goto err;
if (num < 11)
goto err;
em = OPENSSL_malloc(num);
if (em == NULL) {
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_2, ERR_R_MALLOC_FAILURE);
return -1;
}
memset(em, 0, num);
memcpy(em + num - flen, from, flen);
good = constant_time_is_zero(em[0]);
good &= constant_time_eq(em[1], 2);
found_zero_byte = 0;
for (i = 2; i < num; i++) {
unsigned int equals0 = constant_time_is_zero(em[i]);
zero_index =
constant_time_select_int(~found_zero_byte & equals0, i,
zero_index);
found_zero_byte |= equals0;
}
good &= constant_time_ge((unsigned int)(zero_index), 2 + 8);
msg_index = zero_index + 1;
mlen = num - msg_index;
good &= constant_time_ge((unsigned int)(tlen), (unsigned int)(mlen));
if (!good) {
mlen = -1;
goto err;
}
memcpy(to, em + msg_index, mlen);
err:
if (em != NULL)
OPENSSL_free(em);
if (mlen == -1)
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_TYPE_2,
RSA_R_PKCS_DECODING_ERROR);
return mlen;
}
