static void
_set_debug(struct inf_hw *card)
{
card->ipac.isac.dch.debug = debug;
card->ipac.hscx[0].bch.debug = debug;
card->ipac.hscx[1].bch.debug = debug;
}
static int
set_debug(const char *val, struct kernel_param *kp)
{
int ret;
struct inf_hw *card;
ret = param_set_uint(val, kp);
if (!ret) {
read_lock(&card_lock);
list_for_each_entry(card, &Cards, list)
_set_debug(card);
read_unlock(&card_lock);
}
return ret;
}
static irqreturn_t
diva_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
u8 val;
spin_lock(&hw->lock);
val = inb((u32)hw->cfg.start + DIVA_PCI_CTRL);
if (!(val & DIVA_IRQ_BIT)) {
spin_unlock(&hw->lock);
return IRQ_NONE;
}
hw->irqcnt++;
mISDNipac_irq(&hw->ipac, irqloops);
spin_unlock(&hw->lock);
return IRQ_HANDLED;
}
static irqreturn_t
diva20x_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
u8 val;
spin_lock(&hw->lock);
val = readb(hw->cfg.p);
if (!(val & PITA_INT0_STATUS)) {
spin_unlock(&hw->lock);
return IRQ_NONE;
}
hw->irqcnt++;
mISDNipac_irq(&hw->ipac, irqloops);
writeb(PITA_INT0_STATUS, hw->cfg.p);
spin_unlock(&hw->lock);
return IRQ_HANDLED;
}
static irqreturn_t
tiger_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
u8 val;
spin_lock(&hw->lock);
val = inb((u32)hw->cfg.start + TIGER_AUX_STATUS);
if (val & TIGER_IRQ_BIT) {
spin_unlock(&hw->lock);
return IRQ_NONE;
}
hw->irqcnt++;
mISDNipac_irq(&hw->ipac, irqloops);
spin_unlock(&hw->lock);
return IRQ_HANDLED;
}
static irqreturn_t
elsa_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
u8 val;
spin_lock(&hw->lock);
val = inb((u32)hw->cfg.start + ELSA_IRQ_ADDR);
if (!(val & ELSA_IRQ_MASK)) {
spin_unlock(&hw->lock);
return IRQ_NONE;
}
hw->irqcnt++;
mISDNipac_irq(&hw->ipac, irqloops);
spin_unlock(&hw->lock);
return IRQ_HANDLED;
}
static irqreturn_t
niccy_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
u32 val;
spin_lock(&hw->lock);
val = inl((u32)hw->cfg.start + NICCY_IRQ_CTRL_REG);
if (!(val & NICCY_IRQ_BIT)) {
spin_unlock(&hw->lock);
return IRQ_NONE;
}
outl(val, (u32)hw->cfg.start + NICCY_IRQ_CTRL_REG);
hw->irqcnt++;
mISDNipac_irq(&hw->ipac, irqloops);
spin_unlock(&hw->lock);
return IRQ_HANDLED;
}
static irqreturn_t
gazel_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
irqreturn_t ret;
spin_lock(&hw->lock);
ret = mISDNipac_irq(&hw->ipac, irqloops);
spin_unlock(&hw->lock);
return ret;
}
static irqreturn_t
ipac_irq(int intno, void *dev_id)
{
struct inf_hw *hw = dev_id;
u8 val;
spin_lock(&hw->lock);
val = hw->ipac.read_reg(hw, IPAC_ISTA);
if (!(val & 0x3f)) {
spin_unlock(&hw->lock);
return IRQ_NONE;
}
hw->irqcnt++;
mISDNipac_irq(&hw->ipac, irqloops);
spin_unlock(&hw->lock);
return IRQ_HANDLED;
}
static void
enable_hwirq(struct inf_hw *hw)
{
u16 w;
u32 val;
switch (hw->ci->typ) {
case INF_DIVA201:
case INF_DIVA202:
writel(PITA_INT0_ENABLE, hw->cfg.p);
break;
case INF_SPEEDWIN:
case INF_SAPHIR3:
outb(TIGER_IRQ_BIT, (u32)hw->cfg.start + TIGER_AUX_IRQMASK);
break;
case INF_QS1000:
outb(QS1000_IRQ_ON, (u32)hw->cfg.start + ELSA_IRQ_ADDR);
break;
case INF_QS3000:
outb(QS3000_IRQ_ON, (u32)hw->cfg.start + ELSA_IRQ_ADDR);
break;
case INF_NICCY:
val = inl((u32)hw->cfg.start + NICCY_IRQ_CTRL_REG);
val |= NICCY_IRQ_ENABLE;
outl(val, (u32)hw->cfg.start + NICCY_IRQ_CTRL_REG);
break;
case INF_SCT_1:
w = inw((u32)hw->cfg.start + SCT_PLX_IRQ_ADDR);
w |= SCT_PLX_IRQ_ENABLE;
outw(w, (u32)hw->cfg.start + SCT_PLX_IRQ_ADDR);
break;
case INF_GAZEL_R685:
outb(GAZEL_ISAC_EN + GAZEL_HSCX_EN + GAZEL_PCI_EN,
(u32)hw->cfg.start + GAZEL_INCSR);
break;
case INF_GAZEL_R753:
outb(GAZEL_IPAC_EN + GAZEL_PCI_EN,
(u32)hw->cfg.start + GAZEL_INCSR);
break;
default:
break;
}
}
static void
disable_hwirq(struct inf_hw *hw)
{
u16 w;
u32 val;
switch (hw->ci->typ) {
case INF_DIVA201:
case INF_DIVA202:
writel(0, hw->cfg.p);
break;
case INF_SPEEDWIN:
case INF_SAPHIR3:
outb(0, (u32)hw->cfg.start + TIGER_AUX_IRQMASK);
break;
case INF_QS1000:
outb(QS1000_IRQ_OFF, (u32)hw->cfg.start + ELSA_IRQ_ADDR);
break;
case INF_QS3000:
outb(QS3000_IRQ_OFF, (u32)hw->cfg.start + ELSA_IRQ_ADDR);
break;
case INF_NICCY:
val = inl((u32)hw->cfg.start + NICCY_IRQ_CTRL_REG);
val &= NICCY_IRQ_DISABLE;
outl(val, (u32)hw->cfg.start + NICCY_IRQ_CTRL_REG);
break;
case INF_SCT_1:
w = inw((u32)hw->cfg.start + SCT_PLX_IRQ_ADDR);
w &= (~SCT_PLX_IRQ_ENABLE);
outw(w, (u32)hw->cfg.start + SCT_PLX_IRQ_ADDR);
break;
case INF_GAZEL_R685:
case INF_GAZEL_R753:
outb(0, (u32)hw->cfg.start + GAZEL_INCSR);
break;
default:
break;
}
}
static void
ipac_chip_reset(struct inf_hw *hw)
{
hw->ipac.write_reg(hw, IPAC_POTA2, 0x20);
mdelay(5);
hw->ipac.write_reg(hw, IPAC_POTA2, 0x00);
mdelay(5);
hw->ipac.write_reg(hw, IPAC_CONF, hw->ipac.conf);
hw->ipac.write_reg(hw, IPAC_MASK, 0xc0);
}
static void
reset_inf(struct inf_hw *hw)
{
u16 w;
u32 val;
if (debug & DEBUG_HW)
pr_notice("%s: resetting card\n", hw->name);
switch (hw->ci->typ) {
case INF_DIVA20:
case INF_DIVA20U:
outb(0, (u32)hw->cfg.start + DIVA_PCI_CTRL);
mdelay(10);
outb(DIVA_RESET_BIT, (u32)hw->cfg.start + DIVA_PCI_CTRL);
mdelay(10);
outb(9, (u32)hw->cfg.start + 0x69);
outb(DIVA_RESET_BIT | DIVA_LED_A,
(u32)hw->cfg.start + DIVA_PCI_CTRL);
break;
case INF_DIVA201:
writel(PITA_PARA_SOFTRESET | PITA_PARA_MPX_MODE,
hw->cfg.p + PITA_MISC_REG);
mdelay(1);
writel(PITA_PARA_MPX_MODE, hw->cfg.p + PITA_MISC_REG);
mdelay(10);
break;
case INF_DIVA202:
writel(PITA_PARA_SOFTRESET | PITA_PARA_MPX_MODE,
hw->cfg.p + PITA_MISC_REG);
mdelay(1);
writel(PITA_PARA_MPX_MODE | PITA_SER_SOFTRESET,
hw->cfg.p + PITA_MISC_REG);
mdelay(10);
break;
case INF_SPEEDWIN:
case INF_SAPHIR3:
ipac_chip_reset(hw);
hw->ipac.write_reg(hw, IPAC_ACFG, 0xff);
hw->ipac.write_reg(hw, IPAC_AOE, 0x00);
hw->ipac.write_reg(hw, IPAC_PCFG, 0x12);
break;
case INF_QS1000:
case INF_QS3000:
ipac_chip_reset(hw);
hw->ipac.write_reg(hw, IPAC_ACFG, 0x00);
hw->ipac.write_reg(hw, IPAC_AOE, 0x3c);
hw->ipac.write_reg(hw, IPAC_ATX, 0xff);
break;
case INF_NICCY:
break;
case INF_SCT_1:
w = inw((u32)hw->cfg.start + SCT_PLX_RESET_ADDR);
w &= (~SCT_PLX_RESET_BIT);
outw(w, (u32)hw->cfg.start + SCT_PLX_RESET_ADDR);
mdelay(10);
w = inw((u32)hw->cfg.start + SCT_PLX_RESET_ADDR);
w |= SCT_PLX_RESET_BIT;
outw(w, (u32)hw->cfg.start + SCT_PLX_RESET_ADDR);
mdelay(10);
break;
case INF_GAZEL_R685:
val = inl((u32)hw->cfg.start + GAZEL_CNTRL);
val |= (GAZEL_RESET_9050 + GAZEL_RESET);
outl(val, (u32)hw->cfg.start + GAZEL_CNTRL);
val &= ~(GAZEL_RESET_9050 + GAZEL_RESET);
mdelay(4);
outl(val, (u32)hw->cfg.start + GAZEL_CNTRL);
mdelay(10);
hw->ipac.isac.adf2 = 0x87;
hw->ipac.hscx[0].slot = 0x1f;
hw->ipac.hscx[1].slot = 0x23;
break;
case INF_GAZEL_R753:
val = inl((u32)hw->cfg.start + GAZEL_CNTRL);
val |= (GAZEL_RESET_9050 + GAZEL_RESET);
outl(val, (u32)hw->cfg.start + GAZEL_CNTRL);
val &= ~(GAZEL_RESET_9050 + GAZEL_RESET);
mdelay(4);
outl(val, (u32)hw->cfg.start + GAZEL_CNTRL);
mdelay(10);
ipac_chip_reset(hw);
hw->ipac.write_reg(hw, IPAC_ACFG, 0xff);
hw->ipac.write_reg(hw, IPAC_AOE, 0x00);
hw->ipac.conf = 0x01;
break;
default:
return;
}
enable_hwirq(hw);
}
static int
inf_ctrl(struct inf_hw *hw, u32 cmd, u_long arg)
{
int ret = 0;
switch (cmd) {
case HW_RESET_REQ:
reset_inf(hw);
break;
default:
pr_info("%s: %s unknown command %x %lx\n",
hw->name, __func__, cmd, arg);
ret = -EINVAL;
break;
}
return ret;
}
static int __devinit
init_irq(struct inf_hw *hw)
{
int ret, cnt = 3;
u_long flags;
if (!hw->ci->irqfunc)
return -EINVAL;
ret = request_irq(hw->irq, hw->ci->irqfunc, IRQF_SHARED, hw->name, hw);
if (ret) {
pr_info("%s: couldn't get interrupt %d\n", hw->name, hw->irq);
return ret;
}
while (cnt--) {
spin_lock_irqsave(&hw->lock, flags);
reset_inf(hw);
ret = hw->ipac.init(&hw->ipac);
if (ret) {
spin_unlock_irqrestore(&hw->lock, flags);
pr_info("%s: ISAC init failed with %d\n",
hw->name, ret);
break;
}
spin_unlock_irqrestore(&hw->lock, flags);
msleep_interruptible(10);
if (debug & DEBUG_HW)
pr_notice("%s: IRQ %d count %d\n", hw->name,
hw->irq, hw->irqcnt);
if (!hw->irqcnt) {
pr_info("%s: IRQ(%d) got no requests during init %d\n",
hw->name, hw->irq, 3 - cnt);
} else
return 0;
}
free_irq(hw->irq, hw);
return -EIO;
}
static void
release_io(struct inf_hw *hw)
{
if (hw->cfg.mode) {
if (hw->cfg.p) {
release_mem_region(hw->cfg.start, hw->cfg.size);
iounmap(hw->cfg.p);
} else
release_region(hw->cfg.start, hw->cfg.size);
hw->cfg.mode = AM_NONE;
}
if (hw->addr.mode) {
if (hw->addr.p) {
release_mem_region(hw->addr.start, hw->addr.size);
iounmap(hw->addr.p);
} else
release_region(hw->addr.start, hw->addr.size);
hw->addr.mode = AM_NONE;
}
}
static int __devinit
setup_io(struct inf_hw *hw)
{
int err = 0;
if (hw->ci->cfg_mode) {
hw->cfg.start = pci_resource_start(hw->pdev, hw->ci->cfg_bar);
hw->cfg.size = pci_resource_len(hw->pdev, hw->ci->cfg_bar);
if (hw->ci->cfg_mode == AM_MEMIO) {
if (!request_mem_region(hw->cfg.start, hw->cfg.size,
hw->name))
err = -EBUSY;
} else {
if (!request_region(hw->cfg.start, hw->cfg.size,
hw->name))
err = -EBUSY;
}
if (err) {
pr_info("mISDN: %s config port %lx (%lu bytes)"
"already in use\n", hw->name,
(ulong)hw->cfg.start, (ulong)hw->cfg.size);
return err;
}
if (hw->ci->cfg_mode == AM_MEMIO)
hw->cfg.p = ioremap(hw->cfg.start, hw->cfg.size);
hw->cfg.mode = hw->ci->cfg_mode;
if (debug & DEBUG_HW)
pr_notice("%s: IO cfg %lx (%lu bytes) mode%d\n",
hw->name, (ulong)hw->cfg.start,
(ulong)hw->cfg.size, hw->ci->cfg_mode);
}
if (hw->ci->addr_mode) {
hw->addr.start = pci_resource_start(hw->pdev, hw->ci->addr_bar);
hw->addr.size = pci_resource_len(hw->pdev, hw->ci->addr_bar);
if (hw->ci->addr_mode == AM_MEMIO) {
if (!request_mem_region(hw->addr.start, hw->addr.size,
hw->name))
err = -EBUSY;
} else {
if (!request_region(hw->addr.start, hw->addr.size,
hw->name))
err = -EBUSY;
}
if (err) {
pr_info("mISDN: %s address port %lx (%lu bytes)"
"already in use\n", hw->name,
(ulong)hw->addr.start, (ulong)hw->addr.size);
return err;
}
if (hw->ci->addr_mode == AM_MEMIO)
hw->addr.p = ioremap(hw->addr.start, hw->addr.size);
hw->addr.mode = hw->ci->addr_mode;
if (debug & DEBUG_HW)
pr_notice("%s: IO addr %lx (%lu bytes) mode%d\n",
hw->name, (ulong)hw->addr.start,
(ulong)hw->addr.size, hw->ci->addr_mode);
}
switch (hw->ci->typ) {
case INF_DIVA20:
case INF_DIVA20U:
hw->ipac.type = IPAC_TYPE_ISAC | IPAC_TYPE_HSCX;
hw->isac.mode = hw->cfg.mode;
hw->isac.a.io.ale = (u32)hw->cfg.start + DIVA_ISAC_ALE;
hw->isac.a.io.port = (u32)hw->cfg.start + DIVA_ISAC_PORT;
hw->hscx.mode = hw->cfg.mode;
hw->hscx.a.io.ale = (u32)hw->cfg.start + DIVA_HSCX_ALE;
hw->hscx.a.io.port = (u32)hw->cfg.start + DIVA_HSCX_PORT;
break;
case INF_DIVA201:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.mode = hw->addr.mode;
hw->isac.a.p = hw->addr.p;
hw->hscx.mode = hw->addr.mode;
hw->hscx.a.p = hw->addr.p;
break;
case INF_DIVA202:
hw->ipac.type = IPAC_TYPE_IPACX;
hw->isac.mode = hw->addr.mode;
hw->isac.a.p = hw->addr.p;
hw->hscx.mode = hw->addr.mode;
hw->hscx.a.p = hw->addr.p;
break;
case INF_SPEEDWIN:
case INF_SAPHIR3:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.mode = hw->cfg.mode;
hw->isac.a.io.ale = (u32)hw->cfg.start + TIGER_IPAC_ALE;
hw->isac.a.io.port = (u32)hw->cfg.start + TIGER_IPAC_PORT;
hw->hscx.mode = hw->cfg.mode;
hw->hscx.a.io.ale = (u32)hw->cfg.start + TIGER_IPAC_ALE;
hw->hscx.a.io.port = (u32)hw->cfg.start + TIGER_IPAC_PORT;
outb(0xff, (ulong)hw->cfg.start);
mdelay(1);
outb(0x00, (ulong)hw->cfg.start);
mdelay(1);
outb(TIGER_IOMASK, (ulong)hw->cfg.start + TIGER_AUX_CTRL);
break;
case INF_QS1000:
case INF_QS3000:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.a.io.ale = (u32)hw->addr.start;
hw->isac.a.io.port = (u32)hw->addr.start + 1;
hw->isac.mode = hw->addr.mode;
hw->hscx.a.io.ale = (u32)hw->addr.start;
hw->hscx.a.io.port = (u32)hw->addr.start + 1;
hw->hscx.mode = hw->addr.mode;
break;
case INF_NICCY:
hw->ipac.type = IPAC_TYPE_ISAC | IPAC_TYPE_HSCX;
hw->isac.mode = hw->addr.mode;
hw->isac.a.io.ale = (u32)hw->addr.start + NICCY_ISAC_ALE;
hw->isac.a.io.port = (u32)hw->addr.start + NICCY_ISAC_PORT;
hw->hscx.mode = hw->addr.mode;
hw->hscx.a.io.ale = (u32)hw->addr.start + NICCY_HSCX_ALE;
hw->hscx.a.io.port = (u32)hw->addr.start + NICCY_HSCX_PORT;
break;
case INF_SCT_1:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.a.io.ale = (u32)hw->addr.start;
hw->isac.a.io.port = hw->isac.a.io.ale + 4;
hw->isac.mode = hw->addr.mode;
hw->hscx.a.io.ale = hw->isac.a.io.ale;
hw->hscx.a.io.port = hw->isac.a.io.port;
hw->hscx.mode = hw->addr.mode;
break;
case INF_SCT_2:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.a.io.ale = (u32)hw->addr.start + 0x08;
hw->isac.a.io.port = hw->isac.a.io.ale + 4;
hw->isac.mode = hw->addr.mode;
hw->hscx.a.io.ale = hw->isac.a.io.ale;
hw->hscx.a.io.port = hw->isac.a.io.port;
hw->hscx.mode = hw->addr.mode;
break;
case INF_SCT_3:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.a.io.ale = (u32)hw->addr.start + 0x10;
hw->isac.a.io.port = hw->isac.a.io.ale + 4;
hw->isac.mode = hw->addr.mode;
hw->hscx.a.io.ale = hw->isac.a.io.ale;
hw->hscx.a.io.port = hw->isac.a.io.port;
hw->hscx.mode = hw->addr.mode;
break;
case INF_SCT_4:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.a.io.ale = (u32)hw->addr.start + 0x20;
hw->isac.a.io.port = hw->isac.a.io.ale + 4;
hw->isac.mode = hw->addr.mode;
hw->hscx.a.io.ale = hw->isac.a.io.ale;
hw->hscx.a.io.port = hw->isac.a.io.port;
hw->hscx.mode = hw->addr.mode;
break;
case INF_GAZEL_R685:
hw->ipac.type = IPAC_TYPE_ISAC | IPAC_TYPE_HSCX;
hw->ipac.isac.off = 0x80;
hw->isac.mode = hw->addr.mode;
hw->isac.a.io.port = (u32)hw->addr.start;
hw->hscx.mode = hw->addr.mode;
hw->hscx.a.io.port = hw->isac.a.io.port;
break;
case INF_GAZEL_R753:
hw->ipac.type = IPAC_TYPE_IPAC;
hw->ipac.isac.off = 0x80;
hw->isac.mode = hw->addr.mode;
hw->isac.a.io.ale = (u32)hw->addr.start;
hw->isac.a.io.port = (u32)hw->addr.start + GAZEL_IPAC_DATA_PORT;
hw->hscx.mode = hw->addr.mode;
hw->hscx.a.io.ale = hw->isac.a.io.ale;
hw->hscx.a.io.port = hw->isac.a.io.port;
break;
default:
return -EINVAL;
}
switch (hw->isac.mode) {
case AM_MEMIO:
ASSIGN_FUNC_IPAC(MIO, hw->ipac);
break;
case AM_IND_IO:
ASSIGN_FUNC_IPAC(IND, hw->ipac);
break;
case AM_IO:
ASSIGN_FUNC_IPAC(IO, hw->ipac);
break;
default:
return -EINVAL;
}
return 0;
}
static void
release_card(struct inf_hw *card) {
ulong flags;
int i;
spin_lock_irqsave(&card->lock, flags);
disable_hwirq(card);
spin_unlock_irqrestore(&card->lock, flags);
card->ipac.isac.release(&card->ipac.isac);
free_irq(card->irq, card);
mISDN_unregister_device(&card->ipac.isac.dch.dev);
release_io(card);
write_lock_irqsave(&card_lock, flags);
list_del(&card->list);
write_unlock_irqrestore(&card_lock, flags);
switch (card->ci->typ) {
case INF_SCT_2:
case INF_SCT_3:
case INF_SCT_4:
break;
case INF_SCT_1:
for (i = 0; i < 3; i++) {
if (card->sc[i])
release_card(card->sc[i]);
card->sc[i] = NULL;
}
default:
pci_disable_device(card->pdev);
pci_set_drvdata(card->pdev, NULL);
break;
}
kfree(card);
inf_cnt--;
}
static int __devinit
setup_instance(struct inf_hw *card)
{
int err;
ulong flags;
snprintf(card->name, MISDN_MAX_IDLEN - 1, "%s.%d", card->ci->name,
inf_cnt + 1);
write_lock_irqsave(&card_lock, flags);
list_add_tail(&card->list, &Cards);
write_unlock_irqrestore(&card_lock, flags);
_set_debug(card);
card->ipac.isac.name = card->name;
card->ipac.name = card->name;
card->ipac.owner = THIS_MODULE;
spin_lock_init(&card->lock);
card->ipac.isac.hwlock = &card->lock;
card->ipac.hwlock = &card->lock;
card->ipac.ctrl = (void *)&inf_ctrl;
err = setup_io(card);
if (err)
goto error_setup;
card->ipac.isac.dch.dev.Bprotocols =
mISDNipac_init(&card->ipac, card);
if (card->ipac.isac.dch.dev.Bprotocols == 0)
goto error_setup;
err = mISDN_register_device(&card->ipac.isac.dch.dev,
&card->pdev->dev, card->name);
if (err)
goto error;
err = init_irq(card);
if (!err) {
inf_cnt++;
pr_notice("Infineon %d cards installed\n", inf_cnt);
return 0;
}
mISDN_unregister_device(&card->ipac.isac.dch.dev);
error:
card->ipac.release(&card->ipac);
error_setup:
release_io(card);
write_lock_irqsave(&card_lock, flags);
list_del(&card->list);
write_unlock_irqrestore(&card_lock, flags);
return err;
}
static const struct inf_cinfo * __devinit
get_card_info(enum inf_types typ)
{
const struct inf_cinfo *ci = inf_card_info;
while (ci->typ != INF_NONE) {
if (ci->typ == typ)
return ci;
ci++;
}
return NULL;
}
static int __devinit
inf_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int err = -ENOMEM;
struct inf_hw *card;
card = kzalloc(sizeof(struct inf_hw), GFP_KERNEL);
if (!card) {
pr_info("No memory for Infineon ISDN card\n");
return err;
}
card->pdev = pdev;
err = pci_enable_device(pdev);
if (err) {
kfree(card);
return err;
}
card->ci = get_card_info(ent->driver_data);
if (!card->ci) {
pr_info("mISDN: do not have informations about adapter at %s\n",
pci_name(pdev));
kfree(card);
pci_disable_device(pdev);
return -EINVAL;
} else
pr_notice("mISDN: found adapter %s at %s\n",
card->ci->full, pci_name(pdev));
card->irq = pdev->irq;
pci_set_drvdata(pdev, card);
err = setup_instance(card);
if (err) {
pci_disable_device(pdev);
kfree(card);
pci_set_drvdata(pdev, NULL);
} else if (ent->driver_data == INF_SCT_1) {
int i;
struct inf_hw *sc;
for (i = 1; i < 4; i++) {
sc = kzalloc(sizeof(struct inf_hw), GFP_KERNEL);
if (!sc) {
release_card(card);
pci_disable_device(pdev);
return -ENOMEM;
}
sc->irq = card->irq;
sc->pdev = card->pdev;
sc->ci = card->ci + i;
err = setup_instance(sc);
if (err) {
pci_disable_device(pdev);
kfree(sc);
release_card(card);
break;
} else
card->sc[i - 1] = sc;
}
}
return err;
}
static void __devexit
inf_remove(struct pci_dev *pdev)
{
struct inf_hw *card = pci_get_drvdata(pdev);
if (card)
release_card(card);
else
pr_debug("%s: drvdata already removed\n", __func__);
}
static int __init
infineon_init(void)
{
int err;
pr_notice("Infineon ISDN Driver Rev. %s\n", INFINEON_REV);
err = pci_register_driver(&infineon_driver);
return err;
}
static void __exit
infineon_cleanup(void)
{
pci_unregister_driver(&infineon_driver);
}
