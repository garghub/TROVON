static SSL_METHOD *ssl23_get_client_method(int ver)
{
if (ver == SSL2_VERSION)
return(SSLv2_client_method());
if (ver == SSL3_VERSION)
return(SSLv3_client_method());
else if (ver == TLS1_VERSION)
return(TLSv1_client_method());
else
return(NULL);
}
SSL_METHOD *SSLv23_client_method(void)
{
static int init=1;
static SSL_METHOD SSLv23_client_data;
if (init)
{
memcpy((char *)&SSLv23_client_data,
(char *)sslv23_base_method(),sizeof(SSL_METHOD));
SSLv23_client_data.ssl_connect=ssl23_connect;
SSLv23_client_data.get_ssl_method=ssl23_get_client_method;
init=0;
}
return(&SSLv23_client_data);
}
int ssl23_connect(SSL *s)
{
BUF_MEM *buf;
unsigned long Time=time(NULL);
void (*cb)()=NULL;
int ret= -1;
int new_state,state;
RAND_seed(&Time,sizeof(Time));
ERR_clear_error();
clear_sys_error();
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
if (!SSL_in_init(s) || SSL_in_before(s)) SSL_clear(s);
s->in_handshake++;
for (;;)
{
state=s->state;
switch(s->state)
{
case SSL_ST_BEFORE:
case SSL_ST_CONNECT:
case SSL_ST_BEFORE|SSL_ST_CONNECT:
case SSL_ST_OK|SSL_ST_CONNECT:
if (s->session != NULL)
{
SSLerr(SSL_F_SSL23_CONNECT,SSL_R_SSL23_DOING_SESSION_ID_REUSE);
ret= -1;
goto end;
}
s->server=0;
if (cb != NULL) cb(s,SSL_CB_HANDSHAKE_START,1);
s->type=SSL_ST_CONNECT;
if (s->init_buf == NULL)
{
if ((buf=BUF_MEM_new()) == NULL)
{
ret= -1;
goto end;
}
if (!BUF_MEM_grow(buf,SSL3_RT_MAX_PLAIN_LENGTH))
{
ret= -1;
goto end;
}
s->init_buf=buf;
}
if (!ssl3_setup_buffers(s)) { ret= -1; goto end; }
ssl3_init_finished_mac(s);
s->state=SSL23_ST_CW_CLNT_HELLO_A;
s->ctx->stats.sess_connect++;
s->init_num=0;
break;
case SSL23_ST_CW_CLNT_HELLO_A:
case SSL23_ST_CW_CLNT_HELLO_B:
s->shutdown=0;
ret=ssl23_client_hello(s);
if (ret <= 0) goto end;
s->state=SSL23_ST_CR_SRVR_HELLO_A;
s->init_num=0;
break;
case SSL23_ST_CR_SRVR_HELLO_A:
case SSL23_ST_CR_SRVR_HELLO_B:
ret=ssl23_get_server_hello(s);
if (ret >= 0) cb=NULL;
goto end;
default:
SSLerr(SSL_F_SSL23_CONNECT,SSL_R_UNKNOWN_STATE);
ret= -1;
goto end;
}
if (s->debug) { (void)BIO_flush(s->wbio); }
if ((cb != NULL) && (s->state != state))
{
new_state=s->state;
s->state=state;
cb(s,SSL_CB_CONNECT_LOOP,1);
s->state=new_state;
}
}
end:
s->in_handshake--;
if (cb != NULL)
cb(s,SSL_CB_CONNECT_EXIT,ret);
return(ret);
}
static int ssl23_client_hello(SSL *s)
{
unsigned char *buf;
unsigned char *p,*d;
int i,ch_len;
buf=(unsigned char *)s->init_buf->data;
if (s->state == SSL23_ST_CW_CLNT_HELLO_A)
{
#if 0
if (!ssl_get_new_session(s,0))
{
return(-1);
}
#endif
p=s->s3->client_random;
RAND_bytes(p,SSL3_RANDOM_SIZE);
d= &(buf[2]);
p=d+9;
*(d++)=SSL2_MT_CLIENT_HELLO;
if (!(s->options & SSL_OP_NO_TLSv1))
{
*(d++)=TLS1_VERSION_MAJOR;
*(d++)=TLS1_VERSION_MINOR;
s->client_version=TLS1_VERSION;
}
else if (!(s->options & SSL_OP_NO_SSLv3))
{
*(d++)=SSL3_VERSION_MAJOR;
*(d++)=SSL3_VERSION_MINOR;
s->client_version=SSL3_VERSION;
}
else if (!(s->options & SSL_OP_NO_SSLv2))
{
*(d++)=SSL2_VERSION_MAJOR;
*(d++)=SSL2_VERSION_MINOR;
s->client_version=SSL2_VERSION;
}
else
{
SSLerr(SSL_F_SSL23_CLIENT_HELLO,SSL_R_NO_PROTOCOLS_AVAILABLE);
return(-1);
}
i=ssl_cipher_list_to_bytes(s,SSL_get_ciphers(s),p);
if (i == 0)
{
SSLerr(SSL_F_SSL23_CLIENT_HELLO,SSL_R_NO_CIPHERS_AVAILABLE);
return(-1);
}
s2n(i,d);
p+=i;
#if 0
s->session->session_id_length=0;
#endif
s2n(0,d);
if (s->options & SSL_OP_NETSCAPE_CHALLENGE_BUG)
ch_len=SSL2_CHALLENGE_LENGTH;
else
ch_len=SSL2_MAX_CHALLENGE_LENGTH;
if (SSL3_RANDOM_SIZE < ch_len)
i=SSL3_RANDOM_SIZE;
else
i=ch_len;
s2n(i,d);
memset(&(s->s3->client_random[0]),0,SSL3_RANDOM_SIZE);
RAND_bytes(&(s->s3->client_random[SSL3_RANDOM_SIZE-i]),i);
memcpy(p,&(s->s3->client_random[SSL3_RANDOM_SIZE-i]),i);
p+=i;
i= p- &(buf[2]);
buf[0]=((i>>8)&0xff)|0x80;
buf[1]=(i&0xff);
s->state=SSL23_ST_CW_CLNT_HELLO_B;
s->init_num=i+2;
s->init_off=0;
ssl3_finish_mac(s,&(buf[2]),i);
}
return(ssl23_write_bytes(s));
}
static int ssl23_get_server_hello(SSL *s)
{
char buf[8];
unsigned char *p;
int i,ch_len;
int n;
n=ssl23_read_bytes(s,7);
if (n != 7) return(n);
p=s->packet;
memcpy(buf,p,n);
if ((p[0] & 0x80) && (p[2] == SSL2_MT_SERVER_HELLO) &&
(p[5] == 0x00) && (p[6] == 0x02))
{
if (s->options & SSL_OP_NO_SSLv2)
{
SSLerr(SSL_F_SSL23_GET_SERVER_HELLO,SSL_R_UNSUPPORTED_PROTOCOL);
goto err;
}
if (s->s2 == NULL)
{
if (!ssl2_new(s))
goto err;
}
else
ssl2_clear(s);
if (s->options & SSL_OP_NETSCAPE_CHALLENGE_BUG)
ch_len=SSL2_CHALLENGE_LENGTH;
else
ch_len=SSL2_MAX_CHALLENGE_LENGTH;
i=(SSL3_RANDOM_SIZE < ch_len)
?SSL3_RANDOM_SIZE:ch_len;
s->s2->challenge_length=i;
memcpy(s->s2->challenge,
&(s->s3->client_random[SSL3_RANDOM_SIZE-i]),i);
if (s->s3 != NULL) ssl3_free(s);
if (!BUF_MEM_grow(s->init_buf,
SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER))
{
SSLerr(SSL_F_SSL23_GET_SERVER_HELLO,ERR_R_BUF_LIB);
goto err;
}
s->state=SSL2_ST_GET_SERVER_HELLO_A;
s->s2->ssl2_rollback=1;
s->rstate=SSL_ST_READ_HEADER;
s->packet_length=n;
s->packet= &(s->s2->rbuf[0]);
memcpy(s->packet,buf,n);
s->s2->rbuf_left=n;
s->s2->rbuf_offs=0;
s->s2->write_sequence=1;
s->method=SSLv2_client_method();
s->handshake_func=s->method->ssl_connect;
}
else if ((p[0] == SSL3_RT_HANDSHAKE) &&
(p[1] == SSL3_VERSION_MAJOR) &&
((p[2] == SSL3_VERSION_MINOR) ||
(p[2] == TLS1_VERSION_MINOR)) &&
(p[5] == SSL3_MT_SERVER_HELLO))
{
if (!ssl_init_wbio_buffer(s,1)) goto err;
s->state=SSL3_ST_CR_SRVR_HELLO_A;
s->rstate=SSL_ST_READ_HEADER;
s->packet_length=n;
s->packet= &(s->s3->rbuf.buf[0]);
memcpy(s->packet,buf,n);
s->s3->rbuf.left=n;
s->s3->rbuf.offset=0;
if ((p[2] == SSL3_VERSION_MINOR) &&
!(s->options & SSL_OP_NO_SSLv3))
{
s->version=SSL3_VERSION;
s->method=SSLv3_client_method();
}
else if ((p[2] == TLS1_VERSION_MINOR) &&
!(s->options & SSL_OP_NO_TLSv1))
{
s->version=TLS1_VERSION;
s->method=TLSv1_client_method();
}
else
{
SSLerr(SSL_F_SSL23_GET_SERVER_HELLO,SSL_R_UNSUPPORTED_PROTOCOL);
goto err;
}
s->handshake_func=s->method->ssl_connect;
}
else if ((p[0] == SSL3_RT_ALERT) &&
(p[1] == SSL3_VERSION_MAJOR) &&
((p[2] == SSL3_VERSION_MINOR) ||
(p[2] == TLS1_VERSION_MINOR)) &&
(p[3] == 0) &&
(p[4] == 2))
{
void (*cb)()=NULL;
int j;
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
i=p[5];
if (cb != NULL)
{
j=(i<<8)|p[6];
cb(s,SSL_CB_READ_ALERT,j);
}
s->rwstate=SSL_NOTHING;
SSLerr(SSL_F_SSL23_GET_SERVER_HELLO,SSL_AD_REASON_OFFSET+p[6]);
goto err;
}
else
{
SSLerr(SSL_F_SSL23_GET_SERVER_HELLO,SSL_R_UNKNOWN_PROTOCOL);
goto err;
}
s->init_num=0;
if (!ssl_get_new_session(s,0))
goto err;
s->first_packet=1;
return(SSL_connect(s));
err:
return(-1);
}
