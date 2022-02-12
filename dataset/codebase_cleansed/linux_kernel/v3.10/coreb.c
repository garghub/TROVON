static long
coreb_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int ret = 0;
switch (cmd) {
case CMD_COREB_START:
bfin_write_SYSCR(bfin_read_SYSCR() & ~0x0020);
break;
case CMD_COREB_STOP:
bfin_write_SYSCR(bfin_read_SYSCR() | 0x0020);
bfin_write_SICB_SYSCR(bfin_read_SICB_SYSCR() | 0x0080);
break;
case CMD_COREB_RESET:
bfin_write_SICB_SYSCR(bfin_read_SICB_SYSCR() | 0x0080);
break;
default:
ret = -EINVAL;
break;
}
CSYNC();
return ret;
}
static int __init bf561_coreb_init(void)
{
return misc_register(&coreb_dev);
}
static void __exit bf561_coreb_exit(void)
{
misc_deregister(&coreb_dev);
}
