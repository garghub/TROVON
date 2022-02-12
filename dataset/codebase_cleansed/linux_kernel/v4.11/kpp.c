static int crypto_kpp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
struct crypto_report_kpp rkpp;
strncpy(rkpp.type, "kpp", sizeof(rkpp.type));
if (nla_put(skb, CRYPTOCFGA_REPORT_KPP,
sizeof(struct crypto_report_kpp), &rkpp))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int crypto_kpp_report(struct sk_buff *skb, struct crypto_alg *alg)
{
return -ENOSYS;
}
static void crypto_kpp_show(struct seq_file *m, struct crypto_alg *alg)
{
seq_puts(m, "type : kpp\n");
}
static void crypto_kpp_exit_tfm(struct crypto_tfm *tfm)
{
struct crypto_kpp *kpp = __crypto_kpp_tfm(tfm);
struct kpp_alg *alg = crypto_kpp_alg(kpp);
alg->exit(kpp);
}
static int crypto_kpp_init_tfm(struct crypto_tfm *tfm)
{
struct crypto_kpp *kpp = __crypto_kpp_tfm(tfm);
struct kpp_alg *alg = crypto_kpp_alg(kpp);
if (alg->exit)
kpp->base.exit = crypto_kpp_exit_tfm;
if (alg->init)
return alg->init(kpp);
return 0;
}
struct crypto_kpp *crypto_alloc_kpp(const char *alg_name, u32 type, u32 mask)
{
return crypto_alloc_tfm(alg_name, &crypto_kpp_type, type, mask);
}
static void kpp_prepare_alg(struct kpp_alg *alg)
{
struct crypto_alg *base = &alg->base;
base->cra_type = &crypto_kpp_type;
base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
base->cra_flags |= CRYPTO_ALG_TYPE_KPP;
}
int crypto_register_kpp(struct kpp_alg *alg)
{
struct crypto_alg *base = &alg->base;
kpp_prepare_alg(alg);
return crypto_register_alg(base);
}
void crypto_unregister_kpp(struct kpp_alg *alg)
{
crypto_unregister_alg(&alg->base);
}
