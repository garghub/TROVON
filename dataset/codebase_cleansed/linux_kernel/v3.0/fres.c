int
fres(void *frD, void *frB)
{
#ifdef DEBUG
printk("%s: %p %p\n", __func__, frD, frB);
#endif
return -ENOSYS;
}
