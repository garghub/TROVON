static int prng_open(struct inode *inode, struct file *file)
{
return nonseekable_open(inode, file);
}
static void prng_add_entropy(void)
{
__u64 entropy[4];
unsigned int i;
int ret;
for (i = 0; i < 16; i++) {
ret = crypt_s390_kmc(KMC_PRNG, parm_block, (char *)entropy,
(char *)entropy, sizeof(entropy));
BUG_ON(ret < 0 || ret != sizeof(entropy));
memcpy(parm_block, entropy, sizeof(entropy));
}
}
static void prng_seed(int nbytes)
{
char buf[16];
int i = 0;
BUG_ON(nbytes > 16);
get_random_bytes(buf, nbytes);
while (nbytes >= 8) {
*((__u64 *)parm_block) ^= *((__u64 *)(buf+i));
prng_add_entropy();
i += 8;
nbytes -= 8;
}
prng_add_entropy();
}
static ssize_t prng_read(struct file *file, char __user *ubuf, size_t nbytes,
loff_t *ppos)
{
int chunk, n;
int ret = 0;
int tmp;
while (nbytes) {
if (need_resched()) {
if (signal_pending(current)) {
if (ret == 0)
ret = -ERESTARTSYS;
break;
}
schedule();
}
chunk = min_t(int, nbytes, prng_chunk_size);
n = (chunk + 7) & -8;
if (p->count > prng_entropy_limit)
prng_seed(8);
asm volatile(".insn s,0xb27c0000,%0"
: "=m" (*((unsigned long long *)p->buf)) : : "cc");
tmp = crypt_s390_kmc(KMC_PRNG, parm_block, p->buf, p->buf, n);
BUG_ON((tmp < 0) || (tmp != n));
p->count += n;
if (copy_to_user(ubuf, p->buf, chunk))
return -EFAULT;
nbytes -= chunk;
ret += chunk;
ubuf += chunk;
}
return ret;
}
static int __init prng_init(void)
{
int ret;
if (!crypt_s390_func_available(KMC_PRNG, CRYPT_S390_MSA))
return -EOPNOTSUPP;
if (prng_chunk_size < 8)
return -EINVAL;
p = kmalloc(sizeof(struct s390_prng_data), GFP_KERNEL);
if (!p)
return -ENOMEM;
p->count = 0;
p->buf = kmalloc(prng_chunk_size, GFP_KERNEL);
if (!p->buf) {
ret = -ENOMEM;
goto out_free;
}
prng_seed(16);
ret = misc_register(&prng_dev);
if (ret)
goto out_buf;
return 0;
out_buf:
kfree(p->buf);
out_free:
kfree(p);
return ret;
}
static void __exit prng_exit(void)
{
kzfree(p->buf);
kfree(p);
misc_deregister(&prng_dev);
}
