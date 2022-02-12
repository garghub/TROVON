static int crypto_akcipher_report(struct sk_buff *skb, struct crypto_alg *alg)
{
struct crypto_report_akcipher rakcipher;
strncpy(rakcipher.type, "akcipher", sizeof(rakcipher.type));
if (nla_put(skb, CRYPTOCFGA_REPORT_AKCIPHER,
sizeof(struct crypto_report_akcipher), &rakcipher))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int crypto_akcipher_report(struct sk_buff *skb, struct crypto_alg *alg)
{
return -ENOSYS;
}
static void crypto_akcipher_show(struct seq_file *m, struct crypto_alg *alg)
{
seq_puts(m, "type : akcipher\n");
}
static void crypto_akcipher_exit_tfm(struct crypto_tfm *tfm)
{
struct crypto_akcipher *akcipher = __crypto_akcipher_tfm(tfm);
struct akcipher_alg *alg = crypto_akcipher_alg(akcipher);
alg->exit(akcipher);
}
static int crypto_akcipher_init_tfm(struct crypto_tfm *tfm)
{
struct crypto_akcipher *akcipher = __crypto_akcipher_tfm(tfm);
struct akcipher_alg *alg = crypto_akcipher_alg(akcipher);
if (alg->exit)
akcipher->base.exit = crypto_akcipher_exit_tfm;
if (alg->init)
return alg->init(akcipher);
return 0;
}
struct crypto_akcipher *crypto_alloc_akcipher(const char *alg_name, u32 type,
u32 mask)
{
return crypto_alloc_tfm(alg_name, &crypto_akcipher_type, type, mask);
}
int crypto_register_akcipher(struct akcipher_alg *alg)
{
struct crypto_alg *base = &alg->base;
base->cra_type = &crypto_akcipher_type;
base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
base->cra_flags |= CRYPTO_ALG_TYPE_AKCIPHER;
return crypto_register_alg(base);
}
void crypto_unregister_akcipher(struct akcipher_alg *alg)
{
crypto_unregister_alg(&alg->base);
}
