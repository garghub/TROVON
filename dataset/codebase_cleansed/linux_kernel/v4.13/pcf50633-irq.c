int pcf50633_register_irq(struct pcf50633 *pcf, int irq,
void (*handler) (int, void *), void *data)
{
if (irq < 0 || irq >= PCF50633_NUM_IRQ || !handler)
return -EINVAL;
if (WARN_ON(pcf->irq_handler[irq].handler))
return -EBUSY;
mutex_lock(&pcf->lock);
pcf->irq_handler[irq].handler = handler;
pcf->irq_handler[irq].data = data;
mutex_unlock(&pcf->lock);
return 0;
}
int pcf50633_free_irq(struct pcf50633 *pcf, int irq)
{
if (irq < 0 || irq >= PCF50633_NUM_IRQ)
return -EINVAL;
mutex_lock(&pcf->lock);
pcf->irq_handler[irq].handler = NULL;
mutex_unlock(&pcf->lock);
return 0;
}
static int __pcf50633_irq_mask_set(struct pcf50633 *pcf, int irq, u8 mask)
{
u8 reg, bit;
int idx;
idx = irq >> 3;
reg = PCF50633_REG_INT1M + idx;
bit = 1 << (irq & 0x07);
pcf50633_reg_set_bit_mask(pcf, reg, bit, mask ? bit : 0);
mutex_lock(&pcf->lock);
if (mask)
pcf->mask_regs[idx] |= bit;
else
pcf->mask_regs[idx] &= ~bit;
mutex_unlock(&pcf->lock);
return 0;
}
int pcf50633_irq_mask(struct pcf50633 *pcf, int irq)
{
dev_dbg(pcf->dev, "Masking IRQ %d\n", irq);
return __pcf50633_irq_mask_set(pcf, irq, 1);
}
int pcf50633_irq_unmask(struct pcf50633 *pcf, int irq)
{
dev_dbg(pcf->dev, "Unmasking IRQ %d\n", irq);
return __pcf50633_irq_mask_set(pcf, irq, 0);
}
int pcf50633_irq_mask_get(struct pcf50633 *pcf, int irq)
{
u8 reg, bits;
reg = irq >> 3;
bits = 1 << (irq & 0x07);
return pcf->mask_regs[reg] & bits;
}
static void pcf50633_irq_call_handler(struct pcf50633 *pcf, int irq)
{
if (pcf->irq_handler[irq].handler)
pcf->irq_handler[irq].handler(irq, pcf->irq_handler[irq].data);
}
static irqreturn_t pcf50633_irq(int irq, void *data)
{
struct pcf50633 *pcf = data;
int ret, i, j;
u8 pcf_int[5], chgstat;
ret = pcf50633_read_block(pcf, PCF50633_REG_INT1,
ARRAY_SIZE(pcf_int), pcf_int);
if (ret != ARRAY_SIZE(pcf_int)) {
dev_err(pcf->dev, "Error reading INT registers\n");
goto out;
}
pcf50633_reg_write(pcf, PCF50633_REG_OOCSHDWN, 0x04);
if (pcf_int[0] & (PCF50633_INT1_USBINS | PCF50633_INT1_USBREM)) {
chgstat = pcf50633_reg_read(pcf, PCF50633_REG_MBCS2);
if (chgstat & (0x3 << 4))
pcf_int[0] &= ~PCF50633_INT1_USBREM;
else
pcf_int[0] &= ~PCF50633_INT1_USBINS;
}
if (pcf_int[0] & (PCF50633_INT1_ADPINS | PCF50633_INT1_ADPREM)) {
chgstat = pcf50633_reg_read(pcf, PCF50633_REG_MBCS2);
if (chgstat & (0x3 << 4))
pcf_int[0] &= ~PCF50633_INT1_ADPREM;
else
pcf_int[0] &= ~PCF50633_INT1_ADPINS;
}
dev_dbg(pcf->dev, "INT1=0x%02x INT2=0x%02x INT3=0x%02x "
"INT4=0x%02x INT5=0x%02x\n", pcf_int[0],
pcf_int[1], pcf_int[2], pcf_int[3], pcf_int[4]);
if ((pcf_int[0] & PCF50633_INT1_SECOND) && pcf->onkey1s_held) {
dev_info(pcf->dev, "ONKEY1S held for %d secs\n",
pcf->onkey1s_held);
if (pcf->onkey1s_held++ == PCF50633_ONKEY1S_TIMEOUT)
if (pcf->pdata->force_shutdown)
pcf->pdata->force_shutdown(pcf);
}
if (pcf_int[2] & PCF50633_INT3_ONKEY1S) {
dev_info(pcf->dev, "ONKEY1S held\n");
pcf->onkey1s_held = 1 ;
pcf50633_reg_clear_bits(pcf, PCF50633_REG_INT1M,
PCF50633_INT1_SECOND);
pcf50633_reg_clear_bits(pcf, PCF50633_REG_INT2M,
PCF50633_INT2_ONKEYR);
}
if ((pcf_int[1] & PCF50633_INT2_ONKEYR) && pcf->onkey1s_held) {
pcf->onkey1s_held = 0;
if (pcf->mask_regs[0] & PCF50633_INT1_SECOND)
pcf50633_reg_set_bit_mask(pcf,
PCF50633_REG_INT1M,
PCF50633_INT1_SECOND,
PCF50633_INT1_SECOND);
if (pcf->mask_regs[1] & PCF50633_INT2_ONKEYR)
pcf50633_reg_set_bit_mask(pcf,
PCF50633_REG_INT2M,
PCF50633_INT2_ONKEYR,
PCF50633_INT2_ONKEYR);
}
if (pcf->is_suspended) {
pcf->is_suspended = 0;
for (i = 0; i < ARRAY_SIZE(pcf_int); i++)
pcf->resume_reason[i] = pcf_int[i] &
pcf->pdata->resumers[i];
pcf_int[1] &= ~(PCF50633_INT2_ONKEYR | PCF50633_INT2_ONKEYF);
}
for (i = 0; i < ARRAY_SIZE(pcf_int); i++) {
pcf_int[i] &= ~pcf->mask_regs[i];
for (j = 0; j < 8 ; j++)
if (pcf_int[i] & (1 << j))
pcf50633_irq_call_handler(pcf, (i * 8) + j);
}
out:
return IRQ_HANDLED;
}
int pcf50633_irq_suspend(struct pcf50633 *pcf)
{
int ret;
int i;
u8 res[5];
disable_irq(pcf->irq);
ret = pcf50633_read_block(pcf, PCF50633_REG_INT1M,
ARRAY_SIZE(pcf->suspend_irq_masks),
pcf->suspend_irq_masks);
if (ret < 0) {
dev_err(pcf->dev, "error saving irq masks\n");
goto out;
}
for (i = 0; i < ARRAY_SIZE(res); i++)
res[i] = ~pcf->pdata->resumers[i];
ret = pcf50633_write_block(pcf, PCF50633_REG_INT1M,
ARRAY_SIZE(res), &res[0]);
if (ret < 0) {
dev_err(pcf->dev, "error writing wakeup irq masks\n");
goto out;
}
pcf->is_suspended = 1;
out:
return ret;
}
int pcf50633_irq_resume(struct pcf50633 *pcf)
{
int ret;
ret = pcf50633_write_block(pcf, PCF50633_REG_INT1M,
ARRAY_SIZE(pcf->suspend_irq_masks),
pcf->suspend_irq_masks);
if (ret < 0)
dev_err(pcf->dev, "Error restoring saved suspend masks\n");
enable_irq(pcf->irq);
return ret;
}
int pcf50633_irq_init(struct pcf50633 *pcf, int irq)
{
int ret;
pcf->irq = irq;
pcf->mask_regs[0] = 0x80;
pcf50633_reg_write(pcf, PCF50633_REG_INT1M, pcf->mask_regs[0]);
pcf50633_reg_write(pcf, PCF50633_REG_INT2M, 0x00);
pcf50633_reg_write(pcf, PCF50633_REG_INT3M, 0x00);
pcf50633_reg_write(pcf, PCF50633_REG_INT4M, 0x00);
pcf50633_reg_write(pcf, PCF50633_REG_INT5M, 0x00);
ret = request_threaded_irq(irq, NULL, pcf50633_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"pcf50633", pcf);
if (ret)
dev_err(pcf->dev, "Failed to request IRQ %d\n", ret);
if (enable_irq_wake(irq) < 0)
dev_err(pcf->dev, "IRQ %u cannot be enabled as wake-up source"
"in this hardware revision", irq);
return ret;
}
void pcf50633_irq_free(struct pcf50633 *pcf)
{
free_irq(pcf->irq, pcf);
}
