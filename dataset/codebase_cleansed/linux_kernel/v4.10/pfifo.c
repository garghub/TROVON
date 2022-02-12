int pfifo_request(unsigned int pfifo_mask)
{
int err = 0;
unsigned int val;
mutex_lock(&pfifo_lock);
if (pfifo_mask & pfifo_used) {
err = -EBUSY;
goto out;
}
pfifo_used |= pfifo_mask;
val = readl(NETX_PFIFO_RESET);
writel(val | pfifo_mask, NETX_PFIFO_RESET);
writel(val, NETX_PFIFO_RESET);
out:
mutex_unlock(&pfifo_lock);
return err;
}
void pfifo_free(unsigned int pfifo_mask)
{
mutex_lock(&pfifo_lock);
pfifo_used &= ~pfifo_mask;
mutex_unlock(&pfifo_lock);
}
