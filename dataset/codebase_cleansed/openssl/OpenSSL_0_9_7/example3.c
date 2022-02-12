int main(int argc, char *argv[])
{
if ((argc == 2))
{
do_cipher(argv[1],ENCRYPT);
}
else if ((argc == 3) && !strcmp(argv[1],"-d"))
{
do_cipher(argv[2],DECRYPT);
}
else
{
fprintf(stderr,"%s", usage);
exit(1);
}
return 0;
}
void do_cipher(char *pw, int operation)
{
char buf[BUFLEN];
char ebuf[BUFLEN + 8];
unsigned int ebuflen;
unsigned char iv[EVP_MAX_IV_LENGTH], key[EVP_MAX_KEY_LENGTH];
EVP_CIPHER_CTX ectx;
memcpy(iv, INIT_VECTOR, sizeof(iv));
EVP_BytesToKey(ALG, EVP_md5(), "salu", pw, strlen(pw), 1, key, iv);
EVP_CIPHER_CTX_init(&ectx);
EVP_CipherInit_ex(&ectx, ALG, NULL, key, iv, operation);
while(1)
{
int readlen = read(STDIN, buf, sizeof(buf));
if (readlen <= 0)
{
if (!readlen)
break;
else
{
perror("read");
exit(1);
}
}
EVP_CipherUpdate(&ectx, ebuf, &ebuflen, buf, readlen);
write(STDOUT, ebuf, ebuflen);
}
EVP_CipherFinal_ex(&ectx, ebuf, &ebuflen);
EVP_CIPHER_CTX_cleanup(&ectx);
write(STDOUT, ebuf, ebuflen);
}
