static void ctxdbg(BN_CTX *ctx)
{
unsigned int bnidx = 0, fpidx = 0;
BN_POOL_ITEM *item = ctx->pool.head;
BN_STACK *stack = &ctx->stack;
fprintf(stderr,"(%08x): ", (unsigned int)ctx);
while(bnidx < ctx->used)
{
fprintf(stderr,"%03x ", item->vals[bnidx++ % BN_CTX_POOL_SIZE].dmax);
if(!(bnidx % BN_CTX_POOL_SIZE))
item = item->next;
}
fprintf(stderr,"\n");
bnidx = 0;
fprintf(stderr," : ");
while(fpidx < stack->depth)
{
while(bnidx++ < stack->indexes[fpidx])
fprintf(stderr," ");
fprintf(stderr,"^^^ ");
bnidx++;
fpidx++;
}
fprintf(stderr,"\n");
}
void BN_CTX_init(BN_CTX *ctx)
{
BN_POOL_reset(&ctx->pool);
BN_STACK_reset(&ctx->stack);
ctx->used = 0;
ctx->err_stack = 0;
ctx->too_many = 0;
}
BN_CTX *BN_CTX_new(void)
{
BN_CTX *ret = OPENSSL_malloc(sizeof(BN_CTX));
if(!ret)
{
BNerr(BN_F_BN_CTX_NEW,ERR_R_MALLOC_FAILURE);
return NULL;
}
BN_POOL_init(&ret->pool);
BN_STACK_init(&ret->stack);
ret->used = 0;
ret->err_stack = 0;
ret->too_many = 0;
return ret;
}
void BN_CTX_free(BN_CTX *ctx)
{
if (ctx == NULL)
return;
#ifdef BN_CTX_DEBUG
{
BN_POOL_ITEM *pool = ctx->pool.head;
fprintf(stderr,"BN_CTX_free, stack-size=%d, pool-bignums=%d\n",
ctx->stack.size, ctx->pool.size);
fprintf(stderr,"dmaxs: ");
while(pool) {
unsigned loop = 0;
while(loop < BN_CTX_POOL_SIZE)
fprintf(stderr,"%02x ", pool->vals[loop++].dmax);
pool = pool->next;
}
fprintf(stderr,"\n");
}
#endif
BN_STACK_finish(&ctx->stack);
BN_POOL_finish(&ctx->pool);
OPENSSL_free(ctx);
}
void BN_CTX_start(BN_CTX *ctx)
{
CTXDBG_ENTRY("BN_CTX_start", ctx);
if(ctx->err_stack || ctx->too_many)
ctx->err_stack++;
else if(!BN_STACK_push(&ctx->stack, ctx->used))
{
BNerr(BN_F_BN_CTX_START,BN_R_TOO_MANY_TEMPORARY_VARIABLES);
ctx->err_stack++;
}
CTXDBG_EXIT(ctx);
}
void BN_CTX_end(BN_CTX *ctx)
{
CTXDBG_ENTRY("BN_CTX_end", ctx);
if(ctx->err_stack)
ctx->err_stack--;
else
{
unsigned int fp = BN_STACK_pop(&ctx->stack);
if(fp < ctx->used)
BN_POOL_release(&ctx->pool, ctx->used - fp);
ctx->used = fp;
ctx->too_many = 0;
}
CTXDBG_EXIT(ctx);
}
BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
BIGNUM *ret;
CTXDBG_ENTRY("BN_CTX_get", ctx);
if(ctx->err_stack || ctx->too_many) return NULL;
if((ret = BN_POOL_get(&ctx->pool)) == NULL)
{
ctx->too_many = 1;
BNerr(BN_F_BN_CTX_GET,BN_R_TOO_MANY_TEMPORARY_VARIABLES);
return NULL;
}
BN_zero(ret);
ctx->used++;
CTXDBG_RET(ctx, ret);
return ret;
}
static void BN_STACK_init(BN_STACK *st)
{
st->indexes = NULL;
st->depth = st->size = 0;
}
static void BN_STACK_finish(BN_STACK *st)
{
if(st->size) OPENSSL_free(st->indexes);
}
static void BN_STACK_reset(BN_STACK *st)
{
st->depth = 0;
}
static int BN_STACK_push(BN_STACK *st, unsigned int idx)
{
if(st->depth == st->size)
{
unsigned int newsize = (st->size ?
(st->size * 3 / 2) : BN_CTX_START_FRAMES);
unsigned int *newitems = OPENSSL_malloc(newsize *
sizeof(unsigned int));
if(!newitems) return 0;
if(st->depth)
memcpy(newitems, st->indexes, st->depth *
sizeof(unsigned int));
if(st->size) OPENSSL_free(st->indexes);
st->indexes = newitems;
st->size = newsize;
}
st->indexes[(st->depth)++] = idx;
return 1;
}
static unsigned int BN_STACK_pop(BN_STACK *st)
{
return st->indexes[--(st->depth)];
}
static void BN_POOL_init(BN_POOL *p)
{
p->head = p->current = p->tail = NULL;
p->used = p->size = 0;
}
static void BN_POOL_finish(BN_POOL *p)
{
while(p->head)
{
unsigned int loop = 0;
BIGNUM *bn = p->head->vals;
while(loop++ < BN_CTX_POOL_SIZE)
{
if(bn->d) BN_clear_free(bn);
bn++;
}
p->current = p->head->next;
OPENSSL_free(p->head);
p->head = p->current;
}
}
static void BN_POOL_reset(BN_POOL *p)
{
BN_POOL_ITEM *item = p->head;
while(item)
{
unsigned int loop = 0;
BIGNUM *bn = item->vals;
while(loop++ < BN_CTX_POOL_SIZE)
{
if(bn->d) BN_clear(bn);
bn++;
}
item = item->next;
}
p->current = p->head;
p->used = 0;
}
static BIGNUM *BN_POOL_get(BN_POOL *p)
{
if(p->used == p->size)
{
BIGNUM *bn;
unsigned int loop = 0;
BN_POOL_ITEM *item = OPENSSL_malloc(sizeof(BN_POOL_ITEM));
if(!item) return NULL;
bn = item->vals;
while(loop++ < BN_CTX_POOL_SIZE)
BN_init(bn++);
item->prev = p->tail;
item->next = NULL;
if(!p->head)
p->head = p->current = p->tail = item;
else
{
p->tail->next = item;
p->tail = item;
p->current = item;
}
p->size += BN_CTX_POOL_SIZE;
p->used++;
return item->vals;
}
if(!p->used)
p->current = p->head;
else if((p->used % BN_CTX_POOL_SIZE) == 0)
p->current = p->current->next;
return p->current->vals + ((p->used++) % BN_CTX_POOL_SIZE);
}
static void BN_POOL_release(BN_POOL *p, unsigned int num)
{
unsigned int offset = (p->used - 1) % BN_CTX_POOL_SIZE;
p->used -= num;
while(num--)
{
bn_check_top(p->current->vals + offset);
if(!offset)
{
offset = BN_CTX_POOL_SIZE - 1;
p->current = p->current->prev;
}
else
offset--;
}
}
