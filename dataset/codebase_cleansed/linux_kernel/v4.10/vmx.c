int __init p8_init(void)
{
int ret = 0;
struct crypto_alg **alg_it;
for (alg_it = algs; *alg_it; alg_it++) {
ret = crypto_register_alg(*alg_it);
printk(KERN_INFO "crypto_register_alg '%s' = %d\n",
(*alg_it)->cra_name, ret);
if (ret) {
for (alg_it--; alg_it >= algs; alg_it--)
crypto_unregister_alg(*alg_it);
break;
}
}
if (ret)
return ret;
ret = crypto_register_shash(&p8_ghash_alg);
if (ret) {
for (alg_it = algs; *alg_it; alg_it++)
crypto_unregister_alg(*alg_it);
}
return ret;
}
void __exit p8_exit(void)
{
struct crypto_alg **alg_it;
for (alg_it = algs; *alg_it; alg_it++) {
printk(KERN_INFO "Removing '%s'\n", (*alg_it)->cra_name);
crypto_unregister_alg(*alg_it);
}
crypto_unregister_shash(&p8_ghash_alg);
}
