static int rcar_sysc_pwr_on_off(struct rcar_sysc_ch *sysc_ch,
int sr_bit, int reg_offs)
{
int k;
for (k = 0; k < SYSCSR_RETRIES; k++) {
if (ioread32(rcar_sysc_base + SYSCSR) & (1 << sr_bit))
break;
udelay(SYSCSR_DELAY_US);
}
if (k == SYSCSR_RETRIES)
return -EAGAIN;
iowrite32(1 << sysc_ch->chan_bit,
rcar_sysc_base + sysc_ch->chan_offs + reg_offs);
return 0;
}
static int rcar_sysc_pwr_off(struct rcar_sysc_ch *sysc_ch)
{
return rcar_sysc_pwr_on_off(sysc_ch, 0, PWROFFCR_OFFS);
}
static int rcar_sysc_pwr_on(struct rcar_sysc_ch *sysc_ch)
{
return rcar_sysc_pwr_on_off(sysc_ch, 1, PWRONCR_OFFS);
}
static int rcar_sysc_update(struct rcar_sysc_ch *sysc_ch,
int (*on_off_fn)(struct rcar_sysc_ch *))
{
unsigned int isr_mask = 1 << sysc_ch->isr_bit;
unsigned int chan_mask = 1 << sysc_ch->chan_bit;
unsigned int status;
unsigned long flags;
int ret = 0;
int k;
spin_lock_irqsave(&rcar_sysc_lock, flags);
iowrite32(isr_mask, rcar_sysc_base + SYSCISCR);
do {
ret = on_off_fn(sysc_ch);
if (ret)
goto out;
status = ioread32(rcar_sysc_base +
sysc_ch->chan_offs + PWRER_OFFS);
} while (status & chan_mask);
for (k = 0; k < SYSCISR_RETRIES; k++) {
if (ioread32(rcar_sysc_base + SYSCISR) & isr_mask)
break;
udelay(SYSCISR_DELAY_US);
}
if (k == SYSCISR_RETRIES)
ret = -EIO;
iowrite32(isr_mask, rcar_sysc_base + SYSCISCR);
out:
spin_unlock_irqrestore(&rcar_sysc_lock, flags);
pr_debug("sysc power domain %d: %08x -> %d\n",
sysc_ch->isr_bit, ioread32(rcar_sysc_base + SYSCISR), ret);
return ret;
}
int rcar_sysc_power_down(struct rcar_sysc_ch *sysc_ch)
{
return rcar_sysc_update(sysc_ch, rcar_sysc_pwr_off);
}
int rcar_sysc_power_up(struct rcar_sysc_ch *sysc_ch)
{
return rcar_sysc_update(sysc_ch, rcar_sysc_pwr_on);
}
bool rcar_sysc_power_is_off(struct rcar_sysc_ch *sysc_ch)
{
unsigned int st;
st = ioread32(rcar_sysc_base + sysc_ch->chan_offs + PWRSR_OFFS);
if (st & (1 << sysc_ch->chan_bit))
return true;
return false;
}
void __iomem *rcar_sysc_init(phys_addr_t base)
{
rcar_sysc_base = ioremap_nocache(base, PAGE_SIZE);
if (!rcar_sysc_base)
panic("unable to ioremap R-Car SYSC hardware block\n");
return rcar_sysc_base;
}
