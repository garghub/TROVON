static int crypto_pcomp_init(struct crypto_tfm *tfm, u32 type, u32 mask)
{
return 0;
}
static unsigned int crypto_pcomp_extsize(struct crypto_alg *alg)
{
return alg->cra_ctxsize;
}
static int crypto_pcomp_init_tfm(struct crypto_tfm *tfm)
{
return 0;
}
static int crypto_pcomp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
struct crypto_report_comp rpcomp;
strncpy(rpcomp.type, "pcomp", sizeof(rpcomp.type));
if (nla_put(skb, CRYPTOCFGA_REPORT_COMPRESS,
sizeof(struct crypto_report_comp), &rpcomp))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int crypto_pcomp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
return -ENOSYS;
}
static void crypto_pcomp_show(struct seq_file *m, struct crypto_alg *alg)
{
seq_printf(m, "type : pcomp\n");
}
struct crypto_pcomp *crypto_alloc_pcomp(const char *alg_name, u32 type,
u32 mask)
{
return crypto_alloc_tfm(alg_name, &crypto_pcomp_type, type, mask);
}
int crypto_register_pcomp(struct pcomp_alg *alg)
{
struct crypto_alg *base = &alg->base;
base->cra_type = &crypto_pcomp_type;
base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
base->cra_flags |= CRYPTO_ALG_TYPE_PCOMPRESS;
return crypto_register_alg(base);
}
int crypto_unregister_pcomp(struct pcomp_alg *alg)
{
return crypto_unregister_alg(&alg->base);
}
