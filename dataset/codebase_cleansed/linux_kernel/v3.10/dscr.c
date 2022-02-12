static struct locked_reg *find_locked_reg(u32 reg)
{
int i;
for (i = 0; i < MAX_LOCKED_REGS; i++)
if (dscr.locked[i].key && reg == dscr.locked[i].reg)
return &dscr.locked[i];
return NULL;
}
static void dscr_write_locked1(u32 reg, u32 val,
u32 lock, u32 key)
{
void __iomem *reg_addr = dscr.base + reg;
void __iomem *lock_addr = dscr.base + lock;
asm volatile ("b .s2 0f\n"
"nop 5\n"
" .align 5\n"
"0:\n"
"stw .D1T2 %3,*%2\n"
"stw .D1T2 %1,*%0\n"
:
: "a"(reg_addr), "b"(val), "a"(lock_addr), "b"(key)
);
soc_writel(0, lock_addr);
}
static void dscr_write_locked2(u32 reg, u32 val,
u32 lock0, u32 key0,
u32 lock1, u32 key1)
{
soc_writel(key0, dscr.base + lock0);
soc_writel(key1, dscr.base + lock1);
soc_writel(val, dscr.base + reg);
soc_writel(0, dscr.base + lock0);
soc_writel(0, dscr.base + lock1);
}
static void dscr_write(u32 reg, u32 val)
{
struct locked_reg *lock;
lock = find_locked_reg(reg);
if (lock)
dscr_write_locked1(reg, val, lock->lockreg, lock->key);
else if (dscr.kick_key[0])
dscr_write_locked2(reg, val, dscr.kick_reg[0], dscr.kick_key[0],
dscr.kick_reg[1], dscr.kick_key[1]);
else
soc_writel(val, dscr.base + reg);
}
void dscr_set_devstate(int id, enum dscr_devstate_t state)
{
struct devstate_ctl_reg *ctl;
struct devstate_stat_reg *stat;
struct devstate_info *info;
u32 ctl_val, val;
int ctl_shift, ctl_mask;
unsigned long flags;
if (!dscr.base)
return;
if (id < 0 || id >= MAX_DEVSTATE_IDS)
return;
info = &dscr.devstate_info[id];
ctl = info->ctl;
stat = info->stat;
if (ctl == NULL)
return;
ctl_shift = ctl->shift + ctl->nbits * (id - ctl->start_id);
ctl_mask = ((1 << ctl->nbits) - 1) << ctl_shift;
switch (state) {
case DSCR_DEVSTATE_ENABLED:
ctl_val = ctl->enable << ctl_shift;
break;
case DSCR_DEVSTATE_DISABLED:
if (ctl->enable_only)
return;
ctl_val = ctl->disable << ctl_shift;
break;
default:
return;
}
spin_lock_irqsave(&dscr.lock, flags);
val = soc_readl(dscr.base + ctl->reg);
val &= ~ctl_mask;
val |= ctl_val;
dscr_write(ctl->reg, val);
spin_unlock_irqrestore(&dscr.lock, flags);
if (!stat)
return;
ctl_shift = stat->shift + stat->nbits * (id - stat->start_id);
if (state == DSCR_DEVSTATE_ENABLED)
ctl_val = stat->enable;
else
ctl_val = stat->disable;
do {
val = soc_readl(dscr.base + stat->reg);
val >>= ctl_shift;
val &= ((1 << stat->nbits) - 1);
} while (val != ctl_val);
}
void dscr_rmii_reset(int id, int assert)
{
struct rmii_reset_reg *r;
unsigned long flags;
u32 val;
if (id < 0 || id >= MAX_SOC_EMACS)
return;
r = &dscr.rmii_resets[id];
if (r->mask == 0)
return;
spin_lock_irqsave(&dscr.lock, flags);
val = soc_readl(dscr.base + r->reg);
if (assert)
dscr_write(r->reg, val | r->mask);
else
dscr_write(r->reg, val & ~(r->mask));
spin_unlock_irqrestore(&dscr.lock, flags);
}
static void __init dscr_parse_devstat(struct device_node *node,
void __iomem *base)
{
u32 val;
int err;
err = of_property_read_u32_array(node, "ti,dscr-devstat", &val, 1);
if (!err)
c6x_devstat = soc_readl(base + val);
printk(KERN_INFO "DEVSTAT: %08x\n", c6x_devstat);
}
static void __init dscr_parse_silicon_rev(struct device_node *node,
void __iomem *base)
{
u32 vals[3];
int err;
err = of_property_read_u32_array(node, "ti,dscr-silicon-rev", vals, 3);
if (!err) {
c6x_silicon_rev = soc_readl(base + vals[0]);
c6x_silicon_rev >>= vals[1];
c6x_silicon_rev &= vals[2];
}
}
static void __init dscr_parse_mac_fuse(struct device_node *node,
void __iomem *base)
{
u32 vals[10], fuse;
int f, i, j, err;
err = of_property_read_u32_array(node, "ti,dscr-mac-fuse-regs",
vals, 10);
if (err)
return;
for (f = 0; f < 2; f++) {
fuse = soc_readl(base + vals[f * 5]);
for (j = (f * 5) + 1, i = 24; i >= 0; i -= 8, j++)
if (vals[j] && vals[j] <= 6)
c6x_fuse_mac[vals[j] - 1] = fuse >> i;
}
}
static void __init dscr_parse_rmii_resets(struct device_node *node,
void __iomem *base)
{
const __be32 *p;
int i, size;
p = of_get_property(node, "ti,dscr-rmii-resets", &size);
if (p) {
size /= (sizeof(*p) * 2);
if (size > MAX_SOC_EMACS)
size = MAX_SOC_EMACS;
for (i = 0; i < size; i++) {
dscr.rmii_resets[i].reg = be32_to_cpup(p++);
dscr.rmii_resets[i].mask = be32_to_cpup(p++);
}
}
}
static void __init dscr_parse_privperm(struct device_node *node,
void __iomem *base)
{
u32 vals[2];
int err;
err = of_property_read_u32_array(node, "ti,dscr-privperm", vals, 2);
if (err)
return;
dscr_write(vals[0], vals[1]);
}
static void __init dscr_parse_locked_regs(struct device_node *node,
void __iomem *base)
{
struct locked_reg *r;
const __be32 *p;
int i, size;
p = of_get_property(node, "ti,dscr-locked-regs", &size);
if (p) {
size /= (sizeof(*p) * 3);
if (size > MAX_LOCKED_REGS)
size = MAX_LOCKED_REGS;
for (i = 0; i < size; i++) {
r = &dscr.locked[i];
r->reg = be32_to_cpup(p++);
r->lockreg = be32_to_cpup(p++);
r->key = be32_to_cpup(p++);
}
}
}
static void __init dscr_parse_kick_regs(struct device_node *node,
void __iomem *base)
{
u32 vals[4];
int err;
err = of_property_read_u32_array(node, "ti,dscr-kick-regs", vals, 4);
if (!err) {
dscr.kick_reg[0] = vals[0];
dscr.kick_key[0] = vals[1];
dscr.kick_reg[1] = vals[2];
dscr.kick_key[1] = vals[3];
}
}
static void __init dscr_parse_devstate_ctl_regs(struct device_node *node,
void __iomem *base)
{
struct devstate_ctl_reg *r;
const __be32 *p;
int i, j, size;
p = of_get_property(node, "ti,dscr-devstate-ctl-regs", &size);
if (p) {
size /= (sizeof(*p) * 7);
if (size > MAX_DEVCTL_REGS)
size = MAX_DEVCTL_REGS;
for (i = 0; i < size; i++) {
r = &dscr.devctl[i];
r->start_id = be32_to_cpup(p++);
r->num_ids = be32_to_cpup(p++);
r->reg = be32_to_cpup(p++);
r->enable = be32_to_cpup(p++);
r->disable = be32_to_cpup(p++);
if (r->disable == 0xffffffff)
r->enable_only = 1;
r->shift = be32_to_cpup(p++);
r->nbits = be32_to_cpup(p++);
for (j = r->start_id;
j < (r->start_id + r->num_ids);
j++)
dscr.devstate_info[j].ctl = r;
}
}
}
static void __init dscr_parse_devstate_stat_regs(struct device_node *node,
void __iomem *base)
{
struct devstate_stat_reg *r;
const __be32 *p;
int i, j, size;
p = of_get_property(node, "ti,dscr-devstate-stat-regs", &size);
if (p) {
size /= (sizeof(*p) * 7);
if (size > MAX_DEVSTAT_REGS)
size = MAX_DEVSTAT_REGS;
for (i = 0; i < size; i++) {
r = &dscr.devstat[i];
r->start_id = be32_to_cpup(p++);
r->num_ids = be32_to_cpup(p++);
r->reg = be32_to_cpup(p++);
r->enable = be32_to_cpup(p++);
r->disable = be32_to_cpup(p++);
r->shift = be32_to_cpup(p++);
r->nbits = be32_to_cpup(p++);
for (j = r->start_id;
j < (r->start_id + r->num_ids);
j++)
dscr.devstate_info[j].stat = r;
}
}
}
void __init dscr_probe(void)
{
struct device_node *node;
void __iomem *base;
spin_lock_init(&dscr.lock);
node = of_find_matching_node(NULL, dscr_ids);
if (!node)
return;
base = of_iomap(node, 0);
if (!base) {
of_node_put(node);
return;
}
dscr.base = base;
dscr_parse_devstat(node, base);
dscr_parse_silicon_rev(node, base);
dscr_parse_mac_fuse(node, base);
dscr_parse_rmii_resets(node, base);
dscr_parse_locked_regs(node, base);
dscr_parse_kick_regs(node, base);
dscr_parse_devstate_ctl_regs(node, base);
dscr_parse_devstate_stat_regs(node, base);
dscr_parse_privperm(node, base);
}
