int _ossl_old_des_read_pw_string(char *buf,int length,const char *prompt,int verify)
{
return UI_UTIL_read_pw_string(buf, length, prompt, verify);
}
int _ossl_old_des_read_pw(char *buf,char *buff,int size,const char *prompt,int verify)
{
return UI_UTIL_read_pw(buf, buff, size, prompt, verify);
}
