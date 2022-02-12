BIO_METHOD *BIO_s_accept(void)
{
return(&methods_acceptp);
}
static int acpt_new(BIO *bi)
{
BIO_ACCEPT *ba;
bi->init=0;
bi->num=INVALID_SOCKET;
bi->flags=0;
if ((ba=BIO_ACCEPT_new()) == NULL)
return(0);
bi->ptr=(char *)ba;
ba->state=ACPT_S_BEFORE;
bi->shutdown=1;
return(1);
}
static BIO_ACCEPT *BIO_ACCEPT_new(void)
{
BIO_ACCEPT *ret;
if ((ret=(BIO_ACCEPT *)OPENSSL_malloc(sizeof(BIO_ACCEPT))) == NULL)
return(NULL);
memset(ret,0,sizeof(BIO_ACCEPT));
ret->accept_sock=INVALID_SOCKET;
ret->bind_mode=BIO_BIND_NORMAL;
return(ret);
}
static void BIO_ACCEPT_free(BIO_ACCEPT *a)
{
if(a == NULL)
return;
if (a->param_addr != NULL) OPENSSL_free(a->param_addr);
if (a->addr != NULL) OPENSSL_free(a->addr);
if (a->bio_chain != NULL) BIO_free(a->bio_chain);
OPENSSL_free(a);
}
static void acpt_close_socket(BIO *bio)
{
BIO_ACCEPT *c;
c=(BIO_ACCEPT *)bio->ptr;
if (c->accept_sock != INVALID_SOCKET)
{
shutdown(c->accept_sock,2);
closesocket(c->accept_sock);
c->accept_sock=INVALID_SOCKET;
bio->num=INVALID_SOCKET;
}
}
static int acpt_free(BIO *a)
{
BIO_ACCEPT *data;
if (a == NULL) return(0);
data=(BIO_ACCEPT *)a->ptr;
if (a->shutdown)
{
acpt_close_socket(a);
BIO_ACCEPT_free(data);
a->ptr=NULL;
a->flags=0;
a->init=0;
}
return(1);
}
static int acpt_state(BIO *b, BIO_ACCEPT *c)
{
BIO *bio=NULL,*dbio;
int s= -1;
int i;
again:
switch (c->state)
{
case ACPT_S_BEFORE:
if (c->param_addr == NULL)
{
BIOerr(BIO_F_ACPT_STATE,BIO_R_NO_ACCEPT_PORT_SPECIFIED);
return(-1);
}
s=BIO_get_accept_socket(c->param_addr,c->bind_mode);
if (s == INVALID_SOCKET)
return(-1);
if (c->accept_nbio)
{
if (!BIO_socket_nbio(s,1))
{
closesocket(s);
BIOerr(BIO_F_ACPT_STATE,BIO_R_ERROR_SETTING_NBIO_ON_ACCEPT_SOCKET);
return(-1);
}
}
c->accept_sock=s;
b->num=s;
c->state=ACPT_S_GET_ACCEPT_SOCKET;
return(1);
case ACPT_S_GET_ACCEPT_SOCKET:
if (b->next_bio != NULL)
{
c->state=ACPT_S_OK;
goto again;
}
BIO_clear_retry_flags(b);
b->retry_reason=0;
i=BIO_accept(c->accept_sock,&(c->addr));
if(i == -2)
{
BIO_set_retry_special(b);
b->retry_reason=BIO_RR_ACCEPT;
return -1;
}
if (i < 0) return(i);
bio=BIO_new_socket(i,BIO_CLOSE);
if (bio == NULL) goto err;
BIO_set_callback(bio,BIO_get_callback(b));
BIO_set_callback_arg(bio,BIO_get_callback_arg(b));
if (c->nbio)
{
if (!BIO_socket_nbio(i,1))
{
BIOerr(BIO_F_ACPT_STATE,BIO_R_ERROR_SETTING_NBIO_ON_ACCEPTED_SOCKET);
goto err;
}
}
if (c->bio_chain != NULL)
{
if ((dbio=BIO_dup_chain(c->bio_chain)) == NULL)
goto err;
if (!BIO_push(dbio,bio)) goto err;
bio=dbio;
}
if (BIO_push(b,bio) == NULL) goto err;
c->state=ACPT_S_OK;
return(1);
err:
if (bio != NULL)
BIO_free(bio);
else if (s >= 0)
closesocket(s);
return(0);
case ACPT_S_OK:
if (b->next_bio == NULL)
{
c->state=ACPT_S_GET_ACCEPT_SOCKET;
goto again;
}
return(1);
default:
return(0);
}
}
static int acpt_read(BIO *b, char *out, int outl)
{
int ret=0;
BIO_ACCEPT *data;
BIO_clear_retry_flags(b);
data=(BIO_ACCEPT *)b->ptr;
while (b->next_bio == NULL)
{
ret=acpt_state(b,data);
if (ret <= 0) return(ret);
}
ret=BIO_read(b->next_bio,out,outl);
BIO_copy_next_retry(b);
return(ret);
}
static int acpt_write(BIO *b, const char *in, int inl)
{
int ret;
BIO_ACCEPT *data;
BIO_clear_retry_flags(b);
data=(BIO_ACCEPT *)b->ptr;
while (b->next_bio == NULL)
{
ret=acpt_state(b,data);
if (ret <= 0) return(ret);
}
ret=BIO_write(b->next_bio,in,inl);
BIO_copy_next_retry(b);
return(ret);
}
static long acpt_ctrl(BIO *b, int cmd, long num, void *ptr)
{
BIO *dbio;
int *ip;
long ret=1;
BIO_ACCEPT *data;
char **pp;
data=(BIO_ACCEPT *)b->ptr;
switch (cmd)
{
case BIO_CTRL_RESET:
ret=0;
data->state=ACPT_S_BEFORE;
acpt_close_socket(b);
b->flags=0;
break;
case BIO_C_DO_STATE_MACHINE:
ret=(long)acpt_state(b,data);
break;
case BIO_C_SET_ACCEPT:
if (ptr != NULL)
{
if (num == 0)
{
b->init=1;
if (data->param_addr != NULL)
OPENSSL_free(data->param_addr);
data->param_addr=BUF_strdup(ptr);
}
else if (num == 1)
{
data->accept_nbio=(ptr != NULL);
}
else if (num == 2)
{
if (data->bio_chain != NULL)
BIO_free(data->bio_chain);
data->bio_chain=(BIO *)ptr;
}
}
break;
case BIO_C_SET_NBIO:
data->nbio=(int)num;
break;
case BIO_C_SET_FD:
b->init=1;
b->num= *((int *)ptr);
data->accept_sock=b->num;
data->state=ACPT_S_GET_ACCEPT_SOCKET;
b->shutdown=(int)num;
b->init=1;
break;
case BIO_C_GET_FD:
if (b->init)
{
ip=(int *)ptr;
if (ip != NULL)
*ip=data->accept_sock;
ret=data->accept_sock;
}
else
ret= -1;
break;
case BIO_C_GET_ACCEPT:
if (b->init)
{
if (ptr != NULL)
{
pp=(char **)ptr;
*pp=data->param_addr;
}
else
ret= -1;
}
else
ret= -1;
break;
case BIO_CTRL_GET_CLOSE:
ret=b->shutdown;
break;
case BIO_CTRL_SET_CLOSE:
b->shutdown=(int)num;
break;
case BIO_CTRL_PENDING:
case BIO_CTRL_WPENDING:
ret=0;
break;
case BIO_CTRL_FLUSH:
break;
case BIO_C_SET_BIND_MODE:
data->bind_mode=(int)num;
break;
case BIO_C_GET_BIND_MODE:
ret=(long)data->bind_mode;
break;
case BIO_CTRL_DUP:
dbio=(BIO *)ptr;
break;
default:
ret=0;
break;
}
return(ret);
}
static int acpt_puts(BIO *bp, const char *str)
{
int n,ret;
n=strlen(str);
ret=acpt_write(bp,str,n);
return(ret);
}
BIO *BIO_new_accept(char *str)
{
BIO *ret;
ret=BIO_new(BIO_s_accept());
if (ret == NULL) return(NULL);
if (BIO_set_accept_port(ret,str))
return(ret);
else
{
BIO_free(ret);
return(NULL);
}
}
