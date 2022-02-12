main()
{
int i;
BIO *mbio,*b64bio,*bio;
char buf[512];
char *p;
mbio=BIO_new(BIO_s_mem());
b64bio=BIO_new(BIO_f_base64());
bio=BIO_push(b64bio,mbio);
for (;;)
{
i=fread(buf,1,512,stdin);
if (i <= 0) break;
BIO_write(bio,buf,i);
}
BIO_flush(bio);
printf("We have %d bytes available\n",BIO_pending(mbio));
i=(int)BIO_ctrl(mbio,BIO_CTRL_INFO,0,(char *)&p);
printf("%d\n",i);
fwrite("---\n",1,4,stdout);
fwrite(p,1,i,stdout);
fwrite("---\n",1,4,stdout);
BIO_free_all(bio);
}
