const char *_ossl_old_des_options(void)
{
return DES_options();
}
void _ossl_old_des_ecb3_encrypt(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,
des_key_schedule ks1,des_key_schedule ks2,
des_key_schedule ks3, int enc)
{
DES_ecb3_encrypt((const_DES_cblock *)input, output,
(DES_key_schedule *)ks1, (DES_key_schedule *)ks2,
(DES_key_schedule *)ks3, enc);
}
DES_LONG _ossl_old_des_cbc_cksum(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,
long length,des_key_schedule schedule,_ossl_old_des_cblock *ivec)
{
return DES_cbc_cksum((unsigned char *)input, output, length,
(DES_key_schedule *)schedule, ivec);
}
void _ossl_old_des_cbc_encrypt(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,long length,
des_key_schedule schedule,_ossl_old_des_cblock *ivec,int enc)
{
DES_cbc_encrypt((unsigned char *)input, (unsigned char *)output,
length, (DES_key_schedule *)schedule, ivec, enc);
}
void _ossl_old_des_ncbc_encrypt(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,long length,
des_key_schedule schedule,_ossl_old_des_cblock *ivec,int enc)
{
DES_ncbc_encrypt((unsigned char *)input, (unsigned char *)output,
length, (DES_key_schedule *)schedule, ivec, enc);
}
void _ossl_old_des_xcbc_encrypt(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,long length,
des_key_schedule schedule,_ossl_old_des_cblock *ivec,
_ossl_old_des_cblock *inw,_ossl_old_des_cblock *outw,int enc)
{
DES_xcbc_encrypt((unsigned char *)input, (unsigned char *)output,
length, (DES_key_schedule *)schedule, ivec, inw, outw, enc);
}
void _ossl_old_des_cfb_encrypt(unsigned char *in,unsigned char *out,int numbits,
long length,des_key_schedule schedule,_ossl_old_des_cblock *ivec,int enc)
{
DES_cfb_encrypt(in, out, numbits, length,
(DES_key_schedule *)schedule, ivec, enc);
}
void _ossl_old_des_ecb_encrypt(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,
des_key_schedule ks,int enc)
{
DES_ecb_encrypt(input, output, (DES_key_schedule *)ks, enc);
}
void _ossl_old_des_encrypt(DES_LONG *data,des_key_schedule ks, int enc)
{
DES_encrypt1(data, (DES_key_schedule *)ks, enc);
}
void _ossl_old_des_encrypt2(DES_LONG *data,des_key_schedule ks, int enc)
{
DES_encrypt2(data, (DES_key_schedule *)ks, enc);
}
void _ossl_old_des_encrypt3(DES_LONG *data, des_key_schedule ks1,
des_key_schedule ks2, des_key_schedule ks3)
{
DES_encrypt3(data, (DES_key_schedule *)ks1, (DES_key_schedule *)ks2,
(DES_key_schedule *)ks3);
}
void _ossl_old_des_decrypt3(DES_LONG *data, des_key_schedule ks1,
des_key_schedule ks2, des_key_schedule ks3)
{
DES_decrypt3(data, (DES_key_schedule *)ks1, (DES_key_schedule *)ks2,
(DES_key_schedule *)ks3);
}
void _ossl_old_des_ede3_cbc_encrypt(_ossl_old_des_cblock *input, _ossl_old_des_cblock *output,
long length, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3, _ossl_old_des_cblock *ivec, int enc)
{
DES_ede3_cbc_encrypt((unsigned char *)input, (unsigned char *)output,
length, (DES_key_schedule *)ks1, (DES_key_schedule *)ks2,
(DES_key_schedule *)ks3, ivec, enc);
}
void _ossl_old_des_ede3_cfb64_encrypt(unsigned char *in, unsigned char *out,
long length, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3, _ossl_old_des_cblock *ivec, int *num, int enc)
{
DES_ede3_cfb64_encrypt(in, out, length,
(DES_key_schedule *)ks1, (DES_key_schedule *)ks2,
(DES_key_schedule *)ks3, ivec, num, enc);
}
void _ossl_old_des_ede3_ofb64_encrypt(unsigned char *in, unsigned char *out,
long length, des_key_schedule ks1, des_key_schedule ks2,
des_key_schedule ks3, _ossl_old_des_cblock *ivec, int *num)
{
DES_ede3_ofb64_encrypt(in, out, length,
(DES_key_schedule *)ks1, (DES_key_schedule *)ks2,
(DES_key_schedule *)ks3, ivec, num);
}
int _ossl_old_des_enc_read(int fd,char *buf,int len,des_key_schedule sched,
_ossl_old_des_cblock *iv)
{
return DES_enc_read(fd, buf, len, (DES_key_schedule *)sched, iv);
}
int _ossl_old_des_enc_write(int fd,char *buf,int len,des_key_schedule sched,
_ossl_old_des_cblock *iv)
{
return DES_enc_write(fd, buf, len, (DES_key_schedule *)sched, iv);
}
char *_ossl_old_des_fcrypt(const char *buf,const char *salt, char *ret)
{
return DES_fcrypt(buf, salt, ret);
}
char *_ossl_old_des_crypt(const char *buf,const char *salt)
{
return DES_crypt(buf, salt);
}
char *_ossl_old_crypt(const char *buf,const char *salt)
{
return DES_crypt(buf, salt);
}
void _ossl_old_des_ofb_encrypt(unsigned char *in,unsigned char *out,
int numbits,long length,des_key_schedule schedule,_ossl_old_des_cblock *ivec)
{
DES_ofb_encrypt(in, out, numbits, length, (DES_key_schedule *)schedule,
ivec);
}
void _ossl_old_des_pcbc_encrypt(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,long length,
des_key_schedule schedule,_ossl_old_des_cblock *ivec,int enc)
{
DES_pcbc_encrypt((unsigned char *)input, (unsigned char *)output,
length, (DES_key_schedule *)schedule, ivec, enc);
}
DES_LONG _ossl_old_des_quad_cksum(_ossl_old_des_cblock *input,_ossl_old_des_cblock *output,
long length,int out_count,_ossl_old_des_cblock *seed)
{
return DES_quad_cksum((unsigned char *)input, output, length,
out_count, seed);
}
void _ossl_old_des_random_seed(_ossl_old_des_cblock key)
{
RAND_seed(key, sizeof(_ossl_old_des_cblock));
}
void _ossl_old_des_random_key(_ossl_old_des_cblock ret)
{
DES_random_key((DES_cblock *)ret);
}
int _ossl_old_des_read_password(_ossl_old_des_cblock *key, const char *prompt,
int verify)
{
return DES_read_password(key, prompt, verify);
}
int _ossl_old_des_read_2passwords(_ossl_old_des_cblock *key1, _ossl_old_des_cblock *key2,
const char *prompt, int verify)
{
return DES_read_2passwords(key1, key2, prompt, verify);
}
void _ossl_old_des_set_odd_parity(_ossl_old_des_cblock *key)
{
DES_set_odd_parity(key);
}
int _ossl_old_des_is_weak_key(_ossl_old_des_cblock *key)
{
return DES_is_weak_key(key);
}
int _ossl_old_des_set_key(_ossl_old_des_cblock *key,des_key_schedule schedule)
{
return DES_set_key(key, (DES_key_schedule *)schedule);
}
int _ossl_old_des_key_sched(_ossl_old_des_cblock *key,des_key_schedule schedule)
{
return DES_key_sched(key, (DES_key_schedule *)schedule);
}
void _ossl_old_des_string_to_key(char *str,_ossl_old_des_cblock *key)
{
DES_string_to_key(str, key);
}
void _ossl_old_des_string_to_2keys(char *str,_ossl_old_des_cblock *key1,_ossl_old_des_cblock *key2)
{
DES_string_to_2keys(str, key1, key2);
}
void _ossl_old_des_cfb64_encrypt(unsigned char *in, unsigned char *out, long length,
des_key_schedule schedule, _ossl_old_des_cblock *ivec, int *num, int enc)
{
DES_cfb64_encrypt(in, out, length, (DES_key_schedule *)schedule,
ivec, num, enc);
}
void _ossl_old_des_ofb64_encrypt(unsigned char *in, unsigned char *out, long length,
des_key_schedule schedule, _ossl_old_des_cblock *ivec, int *num)
{
DES_ofb64_encrypt(in, out, length, (DES_key_schedule *)schedule,
ivec, num);
}
