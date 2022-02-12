BIO_METHOD *BIO_s_rtcp(void)
{
return(&rtcp_method);
}
static int get ( io_channel chan, char *buffer, int maxlen, int *length )
{
int status;
struct io_status iosb;
status = sys$qiow ( 0, chan, IO$_READVBLK, &iosb, 0, 0,
buffer, maxlen, 0, 0, 0, 0 );
if ( (status&1) == 1 ) status = iosb.status;
if ( (status&1) == 1 ) *length = iosb.count;
return status;
}
static int put ( io_channel chan, char *buffer, int length )
{
int status;
struct io_status iosb;
status = sys$qiow ( 0, chan, IO$_WRITEVBLK, &iosb, 0, 0,
buffer, length, 0, 0, 0, 0 );
if ( (status&1) == 1 ) status = iosb.status;
return status;
}
static int rtcp_new(BIO *bi)
{
struct rpc_ctx *ctx;
bi->init=1;
bi->num=0;
bi->flags = 0;
bi->ptr=Malloc(sizeof(struct rpc_ctx));
ctx = (struct rpc_ctx *) bi->ptr;
ctx->filled = 0;
ctx->pos = 0;
return(1);
}
static int rtcp_free(BIO *a)
{
if (a == NULL) return(0);
if ( a->ptr ) Free ( a->ptr );
a->ptr = NULL;
return(1);
}
static int rtcp_read(BIO *b, char *out, int outl)
{
int status, length;
struct rpc_ctx *ctx;
ctx = (struct rpc_ctx *) b->ptr;
if ( ctx->pos < ctx->filled ) {
length = ctx->filled - ctx->pos;
if ( length > outl ) length = outl;
memmove ( out, &ctx->msg.data[ctx->pos], length );
ctx->pos += length;
return length;
}
ctx->msg.channel = 'R';
ctx->msg.function = 'G';
ctx->msg.length = sizeof(ctx->msg.data);
status = put ( b->num, (char *) &ctx->msg, RPC_HDR_SIZE );
if ( (status&1) == 0 ) {
return -1;
}
ctx->pos = ctx->filled = 0;
status = get ( b->num, (char *) &ctx->msg, sizeof(ctx->msg), &length );
if ( (status&1) == 0 ) length = -1;
if ( ctx->msg.channel != 'R' || ctx->msg.function != 'C' ) {
length = -1;
}
ctx->filled = length - RPC_HDR_SIZE;
if ( ctx->pos < ctx->filled ) {
length = ctx->filled - ctx->pos;
if ( length > outl ) length = outl;
memmove ( out, ctx->msg.data, length );
ctx->pos += length;
return length;
}
return length;
}
static int rtcp_write(BIO *b, char *in, int inl)
{
int status, i, segment, length;
struct rpc_ctx *ctx;
ctx = (struct rpc_ctx *) b->ptr;
for ( i = 0; i < inl; i += segment ) {
segment = inl - i;
if ( segment > sizeof(ctx->msg.data) ) segment = sizeof(ctx->msg.data);
ctx->msg.channel = 'R';
ctx->msg.function = 'P';
ctx->msg.length = segment;
memmove ( ctx->msg.data, &in[i], segment );
status = put ( b->num, (char *) &ctx->msg, segment + RPC_HDR_SIZE );
if ((status&1) == 0 ) { i = -1; break; }
status = get ( b->num, (char *) &ctx->msg, sizeof(ctx->msg), &length );
if ( ((status&1) == 0) || (length < RPC_HDR_SIZE) ) { i = -1; break; }
if ( (ctx->msg.channel != 'R') || (ctx->msg.function != 'C') ) {
printf("unexpected response when confirming put %c %c\n",
ctx->msg.channel, ctx->msg.function );
}
}
return(i);
}
static long rtcp_ctrl(BIO *b, int cmd, long num, char *ptr)
{
long ret=1;
switch (cmd)
{
case BIO_CTRL_RESET:
case BIO_CTRL_EOF:
ret = 1;
break;
case BIO_C_SET_FD:
b->num = num;
ret = 1;
break;
case BIO_CTRL_SET_CLOSE:
case BIO_CTRL_FLUSH:
case BIO_CTRL_DUP:
ret=1;
break;
case BIO_CTRL_GET_CLOSE:
case BIO_CTRL_INFO:
case BIO_CTRL_GET:
case BIO_CTRL_PENDING:
case BIO_CTRL_WPENDING:
default:
ret=0;
break;
}
return(ret);
}
static int rtcp_gets(BIO *bp, char *buf, int size)
{
return(0);
}
static int rtcp_puts(BIO *bp, char *str)
{
int length;
if (str == NULL) return(0);
length = strlen ( str );
if ( length == 0 ) return (0);
return rtcp_write ( bp,str, length );
}
