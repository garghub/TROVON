static inline void __mfp_config_run(struct mfp_pin *p)
{
if (mfp_configured(p))
mfpr_writel(p->mfpr_off, p->mfpr_run);
}
static inline void __mfp_config_lpm(struct mfp_pin *p)
{
if (mfp_configured(p)) {
unsigned long mfpr_clr = (p->mfpr_run & ~MFPR_EDGE_BOTH) | MFPR_EDGE_CLEAR;
if (mfpr_clr != p->mfpr_run)
mfpr_writel(p->mfpr_off, mfpr_clr);
if (p->mfpr_lpm != mfpr_clr)
mfpr_writel(p->mfpr_off, p->mfpr_lpm);
}
}
void mfp_config(unsigned long *mfp_cfgs, int num)
{
unsigned long flags;
int i;
spin_lock_irqsave(&mfp_spin_lock, flags);
for (i = 0; i < num; i++, mfp_cfgs++) {
unsigned long tmp, c = *mfp_cfgs;
struct mfp_pin *p;
int pin, af, drv, lpm, edge, pull;
pin = MFP_PIN(c);
BUG_ON(pin >= MFP_PIN_MAX);
p = &mfp_table[pin];
af = MFP_AF(c);
drv = MFP_DS(c);
lpm = MFP_LPM_STATE(c);
edge = MFP_LPM_EDGE(c);
pull = MFP_PULL(c);
tmp = MFPR_AF_SEL(af) | MFPR_DRIVE(drv);
if (likely(pull == MFP_PULL_NONE)) {
p->mfpr_run = tmp | mfpr_lpm[lpm] | mfpr_edge[edge];
p->mfpr_lpm = p->mfpr_run;
} else {
p->mfpr_lpm = tmp | mfpr_lpm[lpm] | mfpr_edge[edge];
p->mfpr_run = tmp | mfpr_pull[pull];
}
p->config = c; __mfp_config_run(p);
}
mfpr_sync();
spin_unlock_irqrestore(&mfp_spin_lock, flags);
}
unsigned long mfp_read(int mfp)
{
unsigned long val, flags;
BUG_ON(mfp < 0 || mfp >= MFP_PIN_MAX);
spin_lock_irqsave(&mfp_spin_lock, flags);
val = mfpr_readl(mfp_table[mfp].mfpr_off);
spin_unlock_irqrestore(&mfp_spin_lock, flags);
return val;
}
void mfp_write(int mfp, unsigned long val)
{
unsigned long flags;
BUG_ON(mfp < 0 || mfp >= MFP_PIN_MAX);
spin_lock_irqsave(&mfp_spin_lock, flags);
mfpr_writel(mfp_table[mfp].mfpr_off, val);
mfpr_sync();
spin_unlock_irqrestore(&mfp_spin_lock, flags);
}
void __init mfp_init_base(void __iomem *mfpr_base)
{
int i;
for (i = 0; i < ARRAY_SIZE(mfp_table); i++)
mfp_table[i].config = -1;
mfpr_mmio_base = mfpr_base;
}
void __init mfp_init_addr(struct mfp_addr_map *map)
{
struct mfp_addr_map *p;
unsigned long offset, flags;
int i;
spin_lock_irqsave(&mfp_spin_lock, flags);
mfpr_off_readback = map[0].offset;
for (p = map; p->start != MFP_PIN_INVALID; p++) {
offset = p->offset;
i = p->start;
do {
mfp_table[i].mfpr_off = offset;
mfp_table[i].mfpr_run = 0;
mfp_table[i].mfpr_lpm = 0;
offset += 4; i++;
} while ((i <= p->end) && (p->end != -1));
}
spin_unlock_irqrestore(&mfp_spin_lock, flags);
}
void mfp_config_lpm(void)
{
struct mfp_pin *p = &mfp_table[0];
int pin;
for (pin = 0; pin < ARRAY_SIZE(mfp_table); pin++, p++)
__mfp_config_lpm(p);
}
void mfp_config_run(void)
{
struct mfp_pin *p = &mfp_table[0];
int pin;
for (pin = 0; pin < ARRAY_SIZE(mfp_table); pin++, p++)
__mfp_config_run(p);
}
