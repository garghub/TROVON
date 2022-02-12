void callback(stage,count,arg)
int stage,count;
char *arg;
{
FILE *out;
out=(FILE *)arg;
fprintf(out,"%d",stage);
if (stage == 3)
fprintf(out,"\n");
fflush(out);
}
main()
{
RSA *rsa,*pub_rsa,*priv_rsa;
int len;
unsigned char buf[1024],*p;
rsa=RSA_generate_key(512,RSA_F4,callback,(char *)stdout);
p=buf;
len=i2d_RSAPublicKey(rsa,&p);
len+=i2d_RSAPrivateKey(rsa,&p);
printf("The public and private key are now both in a char array\n");
printf("and are taking up %d bytes\n",len);
RSA_free(rsa);
p=buf;
pub_rsa=d2i_RSAPublicKey(NULL,&p,(long)len);
len-=(p-buf);
priv_rsa=d2i_RSAPrivateKey(NULL,&p,(long)len);
if ((pub_rsa == NULL) || (priv_rsa == NULL))
ERR_print_errors_fp(stderr);
RSA_free(pub_rsa);
RSA_free(priv_rsa);
}
