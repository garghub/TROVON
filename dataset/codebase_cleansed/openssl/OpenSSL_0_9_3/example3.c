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
unsigned int ebuflen, rc;
unsigned char iv[EVP_MAX_IV_LENGTH], key[EVP_MAX_KEY_LENGTH];
unsigned int ekeylen, net_ekeylen;
EVP_CIPHER_CTX ectx;
memcpy(iv, INIT_VECTOR, sizeof(iv));
EVP_BytesToKey(ALG, EVP_md5(), "salu", pw, strlen(pw), 1, key, iv);
EVP_CipherInit(&ectx, ALG, key, iv, operation);
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
EVP_CipherFinal(&ectx, ebuf, &ebuflen);
write(STDOUT, ebuf, ebuflen);
}
