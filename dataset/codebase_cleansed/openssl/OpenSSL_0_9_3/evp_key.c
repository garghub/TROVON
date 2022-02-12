void EVP_set_pw_prompt(char *prompt)
{
if (prompt == NULL)
prompt_string[0]='\0';
else
strncpy(prompt_string,prompt,79);
}
char *EVP_get_pw_prompt(void)
{
if (prompt_string[0] == '\0')
return(NULL);
else
return(prompt_string);
}
int EVP_read_pw_string(char *buf, int len, const char *prompt, int verify)
{
if ((prompt == NULL) && (prompt_string[0] != '\0'))
prompt=prompt_string;
return(des_read_pw_string(buf,len,prompt,verify));
}
int EVP_BytesToKey(const EVP_CIPHER *type, EVP_MD *md, unsigned char *salt,
unsigned char *data, int datal, int count, unsigned char *key,
unsigned char *iv)
{
EVP_MD_CTX c;
unsigned char md_buf[EVP_MAX_MD_SIZE];
int niv,nkey,addmd=0;
unsigned int mds=0,i;
nkey=type->key_len;
niv=type->iv_len;
if (data == NULL) return(nkey);
for (;;)
{
EVP_DigestInit(&c,md);
if (addmd++)
EVP_DigestUpdate(&c,&(md_buf[0]),mds);
EVP_DigestUpdate(&c,data,datal);
if (salt != NULL)
EVP_DigestUpdate(&c,salt,8);
EVP_DigestFinal(&c,&(md_buf[0]),&mds);
for (i=1; i<(unsigned int)count; i++)
{
EVP_DigestInit(&c,md);
EVP_DigestUpdate(&c,&(md_buf[0]),mds);
EVP_DigestFinal(&c,&(md_buf[0]),&mds);
}
i=0;
if (nkey)
{
for (;;)
{
if (nkey == 0) break;
if (i == mds) break;
if (key != NULL)
*(key++)=md_buf[i];
nkey--;
i++;
}
}
if (niv && (i != mds))
{
for (;;)
{
if (niv == 0) break;
if (i == mds) break;
if (iv != NULL)
*(iv++)=md_buf[i];
niv--;
i++;
}
}
if ((nkey == 0) && (niv == 0)) break;
}
memset(&c,0,sizeof(c));
memset(&(md_buf[0]),0,EVP_MAX_MD_SIZE);
return(type->key_len);
}
