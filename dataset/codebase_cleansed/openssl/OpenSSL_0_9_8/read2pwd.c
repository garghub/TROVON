int DES_read_password(DES_cblock *key, const char *prompt, int verify)
{
int ok;
char buf[BUFSIZ],buff[BUFSIZ];
if ((ok=UI_UTIL_read_pw(buf,buff,BUFSIZ,prompt,verify)) == 0)
DES_string_to_key(buf,key);
OPENSSL_cleanse(buf,BUFSIZ);
OPENSSL_cleanse(buff,BUFSIZ);
return(ok);
}
int DES_read_2passwords(DES_cblock *key1, DES_cblock *key2, const char *prompt,
int verify)
{
int ok;
char buf[BUFSIZ],buff[BUFSIZ];
if ((ok=UI_UTIL_read_pw(buf,buff,BUFSIZ,prompt,verify)) == 0)
DES_string_to_2keys(buf,key1,key2);
OPENSSL_cleanse(buf,BUFSIZ);
OPENSSL_cleanse(buff,BUFSIZ);
return(ok);
}
