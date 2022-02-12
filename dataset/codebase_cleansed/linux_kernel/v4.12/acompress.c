static int crypto_acomp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
struct crypto_report_acomp racomp;
strncpy(racomp.type, "acomp", sizeof(racomp.type));
if (nla_put(skb, CRYPTOCFGA_REPORT_ACOMP,
sizeof(struct crypto_report_acomp), &racomp))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int crypto_acomp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
return -ENOSYS;
}
static void crypto_acomp_show(struct seq_file *m, struct crypto_alg *alg)
{
seq_puts(m, "type : acomp\n");
}
static void crypto_acomp_exit_tfm(struct crypto_tfm *tfm)
{
struct crypto_acomp *acomp = __crypto_acomp_tfm(tfm);
struct acomp_alg *alg = crypto_acomp_alg(acomp);
alg->exit(acomp);
}
static int crypto_acomp_init_tfm(struct crypto_tfm *tfm)
{
struct crypto_acomp *acomp = __crypto_acomp_tfm(tfm);
struct acomp_alg *alg = crypto_acomp_alg(acomp);
if (tfm->__crt_alg->cra_type != &crypto_acomp_type)
return crypto_init_scomp_ops_async(tfm);
acomp->compress = alg->compress;
acomp->decompress = alg->decompress;
acomp->dst_free = alg->dst_free;
acomp->reqsize = alg->reqsize;
if (alg->exit)
acomp->base.exit = crypto_acomp_exit_tfm;
if (alg->init)
return alg->init(acomp);
return 0;
}
static unsigned int crypto_acomp_extsize(struct crypto_alg *alg)
{
int extsize = crypto_alg_extsize(alg);
if (alg->cra_type != &crypto_acomp_type)
extsize += sizeof(struct crypto_scomp *);
return extsize;
}
struct crypto_acomp *crypto_alloc_acomp(const char *alg_name, u32 type,
u32 mask)
{
return crypto_alloc_tfm(alg_name, &crypto_acomp_type, type, mask);
}
struct acomp_req *acomp_request_alloc(struct crypto_acomp *acomp)
{
struct crypto_tfm *tfm = crypto_acomp_tfm(acomp);
struct acomp_req *req;
req = __acomp_request_alloc(acomp);
if (req && (tfm->__crt_alg->cra_type != &crypto_acomp_type))
return crypto_acomp_scomp_alloc_ctx(req);
return req;
}
void acomp_request_free(struct acomp_req *req)
{
struct crypto_acomp *acomp = crypto_acomp_reqtfm(req);
struct crypto_tfm *tfm = crypto_acomp_tfm(acomp);
if (tfm->__crt_alg->cra_type != &crypto_acomp_type)
crypto_acomp_scomp_free_ctx(req);
if (req->flags & CRYPTO_ACOMP_ALLOC_OUTPUT) {
acomp->dst_free(req->dst);
req->dst = NULL;
}
__acomp_request_free(req);
}
int crypto_register_acomp(struct acomp_alg *alg)
{
struct crypto_alg *base = &alg->base;
base->cra_type = &crypto_acomp_type;
base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
base->cra_flags |= CRYPTO_ALG_TYPE_ACOMPRESS;
return crypto_register_alg(base);
}
int crypto_unregister_acomp(struct acomp_alg *alg)
{
return crypto_unregister_alg(&alg->base);
}
int crypto_register_acomps(struct acomp_alg *algs, int count)
{
int i, ret;
for (i = 0; i < count; i++) {
ret = crypto_register_acomp(&algs[i]);
if (ret)
goto err;
}
return 0;
err:
for (--i; i >= 0; --i)
crypto_unregister_acomp(&algs[i]);
return ret;
}
void crypto_unregister_acomps(struct acomp_alg *algs, int count)
{
int i;
for (i = count - 1; i >= 0; --i)
crypto_unregister_acomp(&algs[i]);
}
