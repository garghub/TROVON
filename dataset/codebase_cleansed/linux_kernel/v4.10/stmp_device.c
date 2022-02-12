static int stmp_clear_poll_bit(void __iomem *addr, u32 mask)
{
int timeout = 0x400;
writel(mask, addr + STMP_OFFSET_REG_CLR);
udelay(1);
while ((readl(addr) & mask) && --timeout)
;
return !timeout;
}
int stmp_reset_block(void __iomem *reset_addr)
{
int ret;
int timeout = 0x400;
ret = stmp_clear_poll_bit(reset_addr, STMP_MODULE_SFTRST);
if (unlikely(ret))
goto error;
writel(STMP_MODULE_CLKGATE, reset_addr + STMP_OFFSET_REG_CLR);
writel(STMP_MODULE_SFTRST, reset_addr + STMP_OFFSET_REG_SET);
udelay(1);
while ((!(readl(reset_addr) & STMP_MODULE_CLKGATE)) && --timeout)
;
if (unlikely(!timeout))
goto error;
ret = stmp_clear_poll_bit(reset_addr, STMP_MODULE_SFTRST);
if (unlikely(ret))
goto error;
ret = stmp_clear_poll_bit(reset_addr, STMP_MODULE_CLKGATE);
if (unlikely(ret))
goto error;
return 0;
error:
pr_err("%s(%p): module reset timeout\n", __func__, reset_addr);
return -ETIMEDOUT;
}
