BIO *BIO_new(BIO_METHOD *method)
{
BIO *ret=NULL;
ret=(BIO *)OPENSSL_malloc(sizeof(BIO));
if (ret == NULL)
{
BIOerr(BIO_F_BIO_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
if (!BIO_set(ret,method))
{
OPENSSL_free(ret);
ret=NULL;
}
return(ret);
}
int BIO_set(BIO *bio, BIO_METHOD *method)
{
bio->method=method;
bio->callback=NULL;
bio->cb_arg=NULL;
bio->init=0;
bio->shutdown=1;
bio->flags=0;
bio->retry_reason=0;
bio->num=0;
bio->ptr=NULL;
bio->prev_bio=NULL;
bio->next_bio=NULL;
bio->references=1;
bio->num_read=0L;
bio->num_write=0L;
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_BIO, bio, &bio->ex_data);
if (method->create != NULL)
if (!method->create(bio))
{
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, bio,
&bio->ex_data);
return(0);
}
return(1);
}
int BIO_free(BIO *a)
{
int i;
if (a == NULL) return(0);
i=CRYPTO_add(&a->references,-1,CRYPTO_LOCK_BIO);
#ifdef REF_PRINT
REF_PRINT("BIO",a);
#endif
if (i > 0) return(1);
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"BIO_free, bad reference count\n");
abort();
}
#endif
if ((a->callback != NULL) &&
((i=(int)a->callback(a,BIO_CB_FREE,NULL,0,0L,1L)) <= 0))
return(i);
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
if ((a->method == NULL) || (a->method->destroy == NULL)) return(1);
a->method->destroy(a);
OPENSSL_free(a);
return(1);
}
void BIO_vfree(BIO *a)
{ BIO_free(a); }
void BIO_clear_flags(BIO *b, int flags)
{
b->flags &= ~flags;
}
int BIO_test_flags(const BIO *b, int flags)
{
return (b->flags & flags);
}
void BIO_set_flags(BIO *b, int flags)
{
b->flags |= flags;
}
void BIO_set_callback(BIO *b, long (*cb)(struct bio_st *,int,const char *,int, long,long))
{
b->callback = cb;
}
void BIO_set_callback_arg(BIO *b, char *arg)
{
b->cb_arg = arg;
}
char * BIO_get_callback_arg(const BIO *b)
{
return b->cb_arg;
}
const char * BIO_method_name(const BIO *b)
{
return b->method->name;
}
int BIO_method_type(const BIO *b)
{
return b->method->type;
}
int BIO_read(BIO *b, void *out, int outl)
{
int i;
long (*cb)(BIO *,int,const char *,int,long,long);
if ((b == NULL) || (b->method == NULL) || (b->method->bread == NULL))
{
BIOerr(BIO_F_BIO_READ,BIO_R_UNSUPPORTED_METHOD);
return(-2);
}
cb=b->callback;
if ((cb != NULL) &&
((i=(int)cb(b,BIO_CB_READ,out,outl,0L,1L)) <= 0))
return(i);
if (!b->init)
{
BIOerr(BIO_F_BIO_READ,BIO_R_UNINITIALIZED);
return(-2);
}
i=b->method->bread(b,out,outl);
if (i > 0) b->num_read+=(unsigned long)i;
if (cb != NULL)
i=(int)cb(b,BIO_CB_READ|BIO_CB_RETURN,out,outl,
0L,(long)i);
return(i);
}
int BIO_write(BIO *b, const void *in, int inl)
{
int i;
long (*cb)(BIO *,int,const char *,int,long,long);
if (b == NULL)
return(0);
cb=b->callback;
if ((b->method == NULL) || (b->method->bwrite == NULL))
{
BIOerr(BIO_F_BIO_WRITE,BIO_R_UNSUPPORTED_METHOD);
return(-2);
}
if ((cb != NULL) &&
((i=(int)cb(b,BIO_CB_WRITE,in,inl,0L,1L)) <= 0))
return(i);
if (!b->init)
{
BIOerr(BIO_F_BIO_WRITE,BIO_R_UNINITIALIZED);
return(-2);
}
i=b->method->bwrite(b,in,inl);
if (i > 0) b->num_write+=(unsigned long)i;
if (cb != NULL)
i=(int)cb(b,BIO_CB_WRITE|BIO_CB_RETURN,in,inl,
0L,(long)i);
return(i);
}
int BIO_puts(BIO *b, const char *in)
{
int i;
long (*cb)(BIO *,int,const char *,int,long,long);
if ((b == NULL) || (b->method == NULL) || (b->method->bputs == NULL))
{
BIOerr(BIO_F_BIO_PUTS,BIO_R_UNSUPPORTED_METHOD);
return(-2);
}
cb=b->callback;
if ((cb != NULL) &&
((i=(int)cb(b,BIO_CB_PUTS,in,0,0L,1L)) <= 0))
return(i);
if (!b->init)
{
BIOerr(BIO_F_BIO_PUTS,BIO_R_UNINITIALIZED);
return(-2);
}
i=b->method->bputs(b,in);
if (i > 0) b->num_write+=(unsigned long)i;
if (cb != NULL)
i=(int)cb(b,BIO_CB_PUTS|BIO_CB_RETURN,in,0,
0L,(long)i);
return(i);
}
int BIO_gets(BIO *b, char *in, int inl)
{
int i;
long (*cb)(BIO *,int,const char *,int,long,long);
if ((b == NULL) || (b->method == NULL) || (b->method->bgets == NULL))
{
BIOerr(BIO_F_BIO_GETS,BIO_R_UNSUPPORTED_METHOD);
return(-2);
}
cb=b->callback;
if ((cb != NULL) &&
((i=(int)cb(b,BIO_CB_GETS,in,inl,0L,1L)) <= 0))
return(i);
if (!b->init)
{
BIOerr(BIO_F_BIO_GETS,BIO_R_UNINITIALIZED);
return(-2);
}
i=b->method->bgets(b,in,inl);
if (cb != NULL)
i=(int)cb(b,BIO_CB_GETS|BIO_CB_RETURN,in,inl,
0L,(long)i);
return(i);
}
int BIO_indent(BIO *b,int indent,int max)
{
if(indent < 0)
indent=0;
if(indent > max)
indent=max;
while(indent--)
if(BIO_puts(b," ") != 1)
return 0;
return 1;
}
long BIO_int_ctrl(BIO *b, int cmd, long larg, int iarg)
{
int i;
i=iarg;
return(BIO_ctrl(b,cmd,larg,(char *)&i));
}
char *BIO_ptr_ctrl(BIO *b, int cmd, long larg)
{
char *p=NULL;
if (BIO_ctrl(b,cmd,larg,(char *)&p) <= 0)
return(NULL);
else
return(p);
}
long BIO_ctrl(BIO *b, int cmd, long larg, void *parg)
{
long ret;
long (*cb)(BIO *,int,const char *,int,long,long);
if (b == NULL) return(0);
if ((b->method == NULL) || (b->method->ctrl == NULL))
{
BIOerr(BIO_F_BIO_CTRL,BIO_R_UNSUPPORTED_METHOD);
return(-2);
}
cb=b->callback;
if ((cb != NULL) &&
((ret=cb(b,BIO_CB_CTRL,parg,cmd,larg,1L)) <= 0))
return(ret);
ret=b->method->ctrl(b,cmd,larg,parg);
if (cb != NULL)
ret=cb(b,BIO_CB_CTRL|BIO_CB_RETURN,parg,cmd,
larg,ret);
return(ret);
}
long BIO_callback_ctrl(BIO *b, int cmd, void (*fp)(struct bio_st *, int, const char *, int, long, long))
{
long ret;
long (*cb)(BIO *,int,const char *,int,long,long);
if (b == NULL) return(0);
if ((b->method == NULL) || (b->method->callback_ctrl == NULL))
{
BIOerr(BIO_F_BIO_CALLBACK_CTRL,BIO_R_UNSUPPORTED_METHOD);
return(-2);
}
cb=b->callback;
if ((cb != NULL) &&
((ret=cb(b,BIO_CB_CTRL,(void *)&fp,cmd,0,1L)) <= 0))
return(ret);
ret=b->method->callback_ctrl(b,cmd,fp);
if (cb != NULL)
ret=cb(b,BIO_CB_CTRL|BIO_CB_RETURN,(void *)&fp,cmd,
0,ret);
return(ret);
}
size_t BIO_ctrl_pending(BIO *bio)
{
return BIO_ctrl(bio, BIO_CTRL_PENDING, 0, NULL);
}
size_t BIO_ctrl_wpending(BIO *bio)
{
return BIO_ctrl(bio, BIO_CTRL_WPENDING, 0, NULL);
}
BIO *BIO_push(BIO *b, BIO *bio)
{
BIO *lb;
if (b == NULL) return(bio);
lb=b;
while (lb->next_bio != NULL)
lb=lb->next_bio;
lb->next_bio=bio;
if (bio != NULL)
bio->prev_bio=lb;
BIO_ctrl(b,BIO_CTRL_PUSH,0,lb);
return(b);
}
BIO *BIO_pop(BIO *b)
{
BIO *ret;
if (b == NULL) return(NULL);
ret=b->next_bio;
BIO_ctrl(b,BIO_CTRL_POP,0,b);
if (b->prev_bio != NULL)
b->prev_bio->next_bio=b->next_bio;
if (b->next_bio != NULL)
b->next_bio->prev_bio=b->prev_bio;
b->next_bio=NULL;
b->prev_bio=NULL;
return(ret);
}
BIO *BIO_get_retry_BIO(BIO *bio, int *reason)
{
BIO *b,*last;
b=last=bio;
for (;;)
{
if (!BIO_should_retry(b)) break;
last=b;
b=b->next_bio;
if (b == NULL) break;
}
if (reason != NULL) *reason=last->retry_reason;
return(last);
}
int BIO_get_retry_reason(BIO *bio)
{
return(bio->retry_reason);
}
BIO *BIO_find_type(BIO *bio, int type)
{
int mt,mask;
if(!bio) return NULL;
mask=type&0xff;
do {
if (bio->method != NULL)
{
mt=bio->method->type;
if (!mask)
{
if (mt & type) return(bio);
}
else if (mt == type)
return(bio);
}
bio=bio->next_bio;
} while (bio != NULL);
return(NULL);
}
BIO *BIO_next(BIO *b)
{
if(!b) return NULL;
return b->next_bio;
}
void BIO_free_all(BIO *bio)
{
BIO *b;
int ref;
while (bio != NULL)
{
b=bio;
ref=b->references;
bio=bio->next_bio;
BIO_free(b);
if (ref > 1) break;
}
}
BIO *BIO_dup_chain(BIO *in)
{
BIO *ret=NULL,*eoc=NULL,*bio,*new;
for (bio=in; bio != NULL; bio=bio->next_bio)
{
if ((new=BIO_new(bio->method)) == NULL) goto err;
new->callback=bio->callback;
new->cb_arg=bio->cb_arg;
new->init=bio->init;
new->shutdown=bio->shutdown;
new->flags=bio->flags;
new->num=bio->num;
if (!BIO_dup_state(bio,(char *)new))
{
BIO_free(new);
goto err;
}
if (!CRYPTO_dup_ex_data(CRYPTO_EX_INDEX_BIO, &new->ex_data,
&bio->ex_data))
goto err;
if (ret == NULL)
{
eoc=new;
ret=eoc;
}
else
{
BIO_push(eoc,new);
eoc=new;
}
}
return(ret);
err:
if (ret != NULL)
BIO_free(ret);
return(NULL);
}
void BIO_copy_next_retry(BIO *b)
{
BIO_set_flags(b,BIO_get_retry_flags(b->next_bio));
b->retry_reason=b->next_bio->retry_reason;
}
int BIO_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_BIO, argl, argp,
new_func, dup_func, free_func);
}
int BIO_set_ex_data(BIO *bio, int idx, void *data)
{
return(CRYPTO_set_ex_data(&(bio->ex_data),idx,data));
}
void *BIO_get_ex_data(BIO *bio, int idx)
{
return(CRYPTO_get_ex_data(&(bio->ex_data),idx));
}
unsigned long BIO_number_read(BIO *bio)
{
if(bio) return bio->num_read;
return 0;
}
unsigned long BIO_number_written(BIO *bio)
{
if(bio) return bio->num_write;
return 0;
}
