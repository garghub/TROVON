int ssl23_write_bytes(SSL *s)
{
int i,num,tot;
char *buf;
buf=s->init_buf->data;
tot=s->init_off;
num=s->init_num;
for (;;)
{
s->rwstate=SSL_WRITING;
i=BIO_write(s->wbio,&(buf[tot]),num);
if (i <= 0)
{
s->init_off=tot;
s->init_num=num;
return(i);
}
s->rwstate=SSL_NOTHING;
if (i == num) return(tot+i);
num-=i;
tot+=i;
}
}
int ssl23_read_bytes(SSL *s, int n)
{
unsigned char *p;
int j;
if (s->packet_length < (unsigned int)n)
{
p=s->packet;
for (;;)
{
s->rwstate=SSL_READING;
j=BIO_read(s->rbio,(char *)&(p[s->packet_length]),
n-s->packet_length);
if (j <= 0)
return(j);
s->rwstate=SSL_NOTHING;
s->packet_length+=j;
if (s->packet_length >= (unsigned int)n)
return(s->packet_length);
}
}
return(n);
}
