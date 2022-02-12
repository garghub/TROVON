static int n_null_open(struct tty_struct *tty)
{
return 0;
}
static void n_null_close(struct tty_struct *tty)
{
}
static ssize_t n_null_read(struct tty_struct *tty, struct file *file,
unsigned char __user * buf, size_t nr)
{
return -EOPNOTSUPP;
}
static ssize_t n_null_write(struct tty_struct *tty, struct file *file,
const unsigned char *buf, size_t nr)
{
return -EOPNOTSUPP;
}
static void n_null_receivebuf(struct tty_struct *tty,
const unsigned char *cp, char *fp,
int cnt)
{
}
static int __init n_null_init(void)
{
BUG_ON(tty_register_ldisc(N_NULL, &null_ldisc));
return 0;
}
static void __exit n_null_exit(void)
{
tty_unregister_ldisc(N_NULL);
}
