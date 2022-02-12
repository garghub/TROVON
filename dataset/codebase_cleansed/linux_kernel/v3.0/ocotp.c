const u32 *mxs_get_ocotp(void)
{
void __iomem *ocotp_base = MXS_IO_ADDRESS(MXS_OCOTP_BASE_ADDR);
int timeout = 0x400;
size_t i;
static int once = 0;
if (once)
return ocotp_words;
mutex_lock(&ocotp_mutex);
__mxs_clrl(BM_OCOTP_CTRL_ERROR, ocotp_base);
while ((__raw_readl(ocotp_base) &
(BM_OCOTP_CTRL_BUSY | BM_OCOTP_CTRL_ERROR)) && --timeout)
cpu_relax();
if (unlikely(!timeout))
goto error_unlock;
__mxs_setl(BM_OCOTP_CTRL_RD_BANK_OPEN, ocotp_base);
udelay(1);
timeout = 0x400;
while ((__raw_readl(ocotp_base) & BM_OCOTP_CTRL_BUSY) && --timeout)
cpu_relax();
if (unlikely(!timeout))
goto error_unlock;
for (i = 0; i < OCOTP_WORD_COUNT; i++)
ocotp_words[i] = __raw_readl(ocotp_base + OCOTP_WORD_OFFSET +
i * 0x10);
__mxs_clrl(BM_OCOTP_CTRL_RD_BANK_OPEN, ocotp_base);
once = 1;
mutex_unlock(&ocotp_mutex);
return ocotp_words;
error_unlock:
mutex_unlock(&ocotp_mutex);
pr_err("%s: timeout in reading OCOTP\n", __func__);
return NULL;
}
