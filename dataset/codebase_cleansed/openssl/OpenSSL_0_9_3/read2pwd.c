int des_read_password(des_cblock *key, const char *prompt, int verify)
{
int ok;
char buf[BUFSIZ],buff[BUFSIZ];
if ((ok=des_read_pw(buf,buff,BUFSIZ,prompt,verify)) == 0)
des_string_to_key(buf,key);
memset(buf,0,BUFSIZ);
memset(buff,0,BUFSIZ);
return(ok);
}
int des_read_2passwords(des_cblock *key1, des_cblock *key2, const char *prompt,
int verify)
{
int ok;
char buf[BUFSIZ],buff[BUFSIZ];
if ((ok=des_read_pw(buf,buff,BUFSIZ,prompt,verify)) == 0)
des_string_to_2keys(buf,key1,key2);
memset(buf,0,BUFSIZ);
memset(buff,0,BUFSIZ);
return(ok);
}
