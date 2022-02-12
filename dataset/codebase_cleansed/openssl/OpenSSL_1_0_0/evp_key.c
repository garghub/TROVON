void EVP_set_pw_prompt(const char *prompt)
{
if (prompt == NULL)
prompt_string[0]='\0';
else
{
strncpy(prompt_string,prompt,79);
prompt_string[79]='\0';
}
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
return EVP_read_pw_string_min(buf, 0, len, prompt, verify);
}
int EVP_read_pw_string_min(char *buf, int min, int len, const char *prompt, int verify)
{
int ret;
char buff[BUFSIZ];
UI *ui;
if ((prompt == NULL) && (prompt_string[0] != '\0'))
prompt=prompt_string;
ui = UI_new();
UI_add_input_string(ui,prompt,0,buf,min,(len>=BUFSIZ)?BUFSIZ-1:len);
if (verify)
UI_add_verify_string(ui,prompt,0,
buff,min,(len>=BUFSIZ)?BUFSIZ-1:len,buf);
ret = UI_process(ui);
UI_free(ui);
OPENSSL_cleanse(buff,BUFSIZ);
return ret;
}
int EVP_BytesToKey(const EVP_CIPHER *type, const EVP_MD *md,
const unsigned char *salt, const unsigned char *data, int datal,
int count, unsigned char *key, unsigned char *iv)
{
EVP_MD_CTX c;
unsigned char md_buf[EVP_MAX_MD_SIZE];
int niv,nkey,addmd=0;
unsigned int mds=0,i;
nkey=type->key_len;
niv=type->iv_len;
OPENSSL_assert(nkey <= EVP_MAX_KEY_LENGTH);
OPENSSL_assert(niv <= EVP_MAX_IV_LENGTH);
if (data == NULL) return(nkey);
EVP_MD_CTX_init(&c);
for (;;)
{
if (!EVP_DigestInit_ex(&c,md, NULL))
return 0;
if (addmd++)
EVP_DigestUpdate(&c,&(md_buf[0]),mds);
EVP_DigestUpdate(&c,data,datal);
if (salt != NULL)
EVP_DigestUpdate(&c,salt,PKCS5_SALT_LEN);
EVP_DigestFinal_ex(&c,&(md_buf[0]),&mds);
for (i=1; i<(unsigned int)count; i++)
{
EVP_DigestInit_ex(&c,md, NULL);
EVP_DigestUpdate(&c,&(md_buf[0]),mds);
EVP_DigestFinal_ex(&c,&(md_buf[0]),&mds);
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
EVP_MD_CTX_cleanup(&c);
OPENSSL_cleanse(&(md_buf[0]),EVP_MAX_MD_SIZE);
return(type->key_len);
}
