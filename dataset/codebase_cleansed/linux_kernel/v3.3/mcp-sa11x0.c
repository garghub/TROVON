static void
mcp_sa11x0_set_telecom_divisor(struct mcp *mcp, unsigned int divisor)
{
unsigned int mccr0;
divisor /= 32;
mccr0 = Ser4MCCR0 & ~0x00007f00;
mccr0 |= divisor << 8;
Ser4MCCR0 = mccr0;
}
static void
mcp_sa11x0_set_audio_divisor(struct mcp *mcp, unsigned int divisor)
{
unsigned int mccr0;
divisor /= 32;
mccr0 = Ser4MCCR0 & ~0x0000007f;
mccr0 |= divisor;
Ser4MCCR0 = mccr0;
}
static void
mcp_sa11x0_write(struct mcp *mcp, unsigned int reg, unsigned int val)
{
int ret = -ETIME;
int i;
Ser4MCDR2 = reg << 17 | MCDR2_Wr | (val & 0xffff);
for (i = 0; i < 2; i++) {
udelay(mcp->rw_timeout);
if (Ser4MCSR & MCSR_CWC) {
ret = 0;
break;
}
}
if (ret < 0)
printk(KERN_WARNING "mcp: write timed out\n");
}
static unsigned int
mcp_sa11x0_read(struct mcp *mcp, unsigned int reg)
{
int ret = -ETIME;
int i;
Ser4MCDR2 = reg << 17 | MCDR2_Rd;
for (i = 0; i < 2; i++) {
udelay(mcp->rw_timeout);
if (Ser4MCSR & MCSR_CRC) {
ret = Ser4MCDR2 & 0xffff;
break;
}
}
if (ret < 0)
printk(KERN_WARNING "mcp: read timed out\n");
return ret;
}
static void mcp_sa11x0_enable(struct mcp *mcp)
{
Ser4MCSR = -1;
Ser4MCCR0 |= MCCR0_MCE;
}
static void mcp_sa11x0_disable(struct mcp *mcp)
{
Ser4MCCR0 &= ~MCCR0_MCE;
}
static int mcp_sa11x0_probe(struct platform_device *pdev)
{
struct mcp_plat_data *data = pdev->dev.platform_data;
struct mcp *mcp;
int ret;
if (!data)
return -ENODEV;
if (!request_mem_region(0x80060000, 0x60, "sa11x0-mcp"))
return -EBUSY;
mcp = mcp_host_alloc(&pdev->dev, sizeof(struct mcp_sa11x0));
if (!mcp) {
ret = -ENOMEM;
goto release;
}
mcp->owner = THIS_MODULE;
mcp->ops = &mcp_sa11x0;
mcp->sclk_rate = data->sclk_rate;
mcp->dma_audio_rd = DMA_Ser4MCP0Rd;
mcp->dma_audio_wr = DMA_Ser4MCP0Wr;
mcp->dma_telco_rd = DMA_Ser4MCP1Rd;
mcp->dma_telco_wr = DMA_Ser4MCP1Wr;
mcp->gpio_base = data->gpio_base;
platform_set_drvdata(pdev, mcp);
if (machine_is_assabet()) {
ASSABET_BCR_set(ASSABET_BCR_CODEC_RST);
}
PPDR &= ~PPC_RXD4;
PPDR |= PPC_TXD4 | PPC_SCLK | PPC_SFRM;
PSDR |= PPC_RXD4;
PSDR &= ~(PPC_TXD4 | PPC_SCLK | PPC_SFRM);
PPSR &= ~(PPC_TXD4 | PPC_SCLK | PPC_SFRM);
Ser4MCSR = -1;
Ser4MCCR1 = data->mccr1;
Ser4MCCR0 = data->mccr0 | 0x7f7f;
mcp->rw_timeout = (64 * 3 * 1000000 + mcp->sclk_rate - 1) /
mcp->sclk_rate;
ret = mcp_host_register(mcp);
if (ret == 0)
goto out;
release:
release_mem_region(0x80060000, 0x60);
platform_set_drvdata(pdev, NULL);
out:
return ret;
}
static int mcp_sa11x0_remove(struct platform_device *dev)
{
struct mcp *mcp = platform_get_drvdata(dev);
platform_set_drvdata(dev, NULL);
mcp_host_unregister(mcp);
release_mem_region(0x80060000, 0x60);
return 0;
}
static int mcp_sa11x0_suspend(struct platform_device *dev, pm_message_t state)
{
struct mcp *mcp = platform_get_drvdata(dev);
priv(mcp)->mccr0 = Ser4MCCR0;
priv(mcp)->mccr1 = Ser4MCCR1;
Ser4MCCR0 &= ~MCCR0_MCE;
return 0;
}
static int mcp_sa11x0_resume(struct platform_device *dev)
{
struct mcp *mcp = platform_get_drvdata(dev);
Ser4MCCR1 = priv(mcp)->mccr1;
Ser4MCCR0 = priv(mcp)->mccr0;
return 0;
}
