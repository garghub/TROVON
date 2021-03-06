static void
_set_debug(struct sfax_hw *card)
{
card->isac.dch.debug = debug;
card->isar.ch[0].bch.debug = debug;
card->isar.ch[1].bch.debug = debug;
}
static int
set_debug(const char *val, struct kernel_param *kp)
{
int ret;
struct sfax_hw *card;
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
speedfax_irq(int intno, void *dev_id)
{
struct sfax_hw *sf = dev_id;
u8 val;
int cnt = irqloops;
spin_lock(&sf->lock);
val = inb(sf->cfg + TIGER_AUX_STATUS);
if (val & SFAX_TIGER_IRQ_BIT) {
spin_unlock(&sf->lock);
return IRQ_NONE;
}
sf->irqcnt++;
val = ReadISAR_IND(sf, ISAR_IRQBIT);
Start_ISAR:
if (val & ISAR_IRQSTA)
mISDNisar_irq(&sf->isar);
val = ReadISAC_IND(sf, ISAC_ISTA);
if (val)
mISDNisac_irq(&sf->isac, val);
val = ReadISAR_IND(sf, ISAR_IRQBIT);
if ((val & ISAR_IRQSTA) && cnt--)
goto Start_ISAR;
if (cnt < irqloops)
pr_debug("%s: %d irqloops cpu%d\n", sf->name,
irqloops - cnt, smp_processor_id());
if (irqloops && !cnt)
pr_notice("%s: %d IRQ LOOP cpu%d\n", sf->name,
irqloops, smp_processor_id());
spin_unlock(&sf->lock);
return IRQ_HANDLED;
}
static void
enable_hwirq(struct sfax_hw *sf)
{
WriteISAC_IND(sf, ISAC_MASK, 0);
WriteISAR_IND(sf, ISAR_IRQBIT, ISAR_IRQMSK);
outb(SFAX_TIGER_IRQ_BIT, sf->cfg + TIGER_AUX_IRQMASK);
}
static void
disable_hwirq(struct sfax_hw *sf)
{
WriteISAC_IND(sf, ISAC_MASK, 0xFF);
WriteISAR_IND(sf, ISAR_IRQBIT, 0);
outb(0, sf->cfg + TIGER_AUX_IRQMASK);
}
static void
reset_speedfax(struct sfax_hw *sf)
{
pr_debug("%s: resetting card\n", sf->name);
outb(TIGER_EXTERN_RESET_ON, sf->cfg + TIGER_RESET_ADDR);
outb(SFAX_PCI_RESET_ON, sf->cfg + TIGER_AUX_DATA);
mdelay(1);
outb(TIGER_EXTERN_RESET_OFF, sf->cfg + TIGER_RESET_ADDR);
sf->aux_data = SFAX_PCI_RESET_OFF;
outb(sf->aux_data, sf->cfg + TIGER_AUX_DATA);
mdelay(1);
}
static int
sfax_ctrl(struct sfax_hw *sf, u32 cmd, u_long arg)
{
int ret = 0;
switch (cmd) {
case HW_RESET_REQ:
reset_speedfax(sf);
break;
case HW_ACTIVATE_IND:
if (arg & 1)
sf->aux_data &= ~SFAX_LED1_BIT;
if (arg & 2)
sf->aux_data &= ~SFAX_LED2_BIT;
outb(sf->aux_data, sf->cfg + TIGER_AUX_DATA);
break;
case HW_DEACT_IND:
if (arg & 1)
sf->aux_data |= SFAX_LED1_BIT;
if (arg & 2)
sf->aux_data |= SFAX_LED2_BIT;
outb(sf->aux_data, sf->cfg + TIGER_AUX_DATA);
break;
default:
pr_info("%s: %s unknown command %x %lx\n",
sf->name, __func__, cmd, arg);
ret = -EINVAL;
break;
}
return ret;
}
static int
channel_ctrl(struct sfax_hw *sf, struct mISDN_ctrl_req *cq)
{
int ret = 0;
switch (cq->op) {
case MISDN_CTRL_GETOP:
cq->op = MISDN_CTRL_LOOP | MISDN_CTRL_L1_TIMER3;
break;
case MISDN_CTRL_LOOP:
if (cq->channel < 0 || cq->channel > 3) {
ret = -EINVAL;
break;
}
ret = sf->isac.ctrl(&sf->isac, HW_TESTLOOP, cq->channel);
break;
case MISDN_CTRL_L1_TIMER3:
ret = sf->isac.ctrl(&sf->isac, HW_TIMER3_VALUE, cq->p1);
break;
default:
pr_info("%s: unknown Op %x\n", sf->name, cq->op);
ret = -EINVAL;
break;
}
return ret;
}
static int
sfax_dctrl(struct mISDNchannel *ch, u32 cmd, void *arg)
{
struct mISDNdevice *dev = container_of(ch, struct mISDNdevice, D);
struct dchannel *dch = container_of(dev, struct dchannel, dev);
struct sfax_hw *sf = dch->hw;
struct channel_req *rq;
int err = 0;
pr_debug("%s: cmd:%x %p\n", sf->name, cmd, arg);
switch (cmd) {
case OPEN_CHANNEL:
rq = arg;
if (rq->protocol == ISDN_P_TE_S0)
err = sf->isac.open(&sf->isac, rq);
else
err = sf->isar.open(&sf->isar, rq);
if (err)
break;
if (!try_module_get(THIS_MODULE))
pr_info("%s: cannot get module\n", sf->name);
break;
case CLOSE_CHANNEL:
pr_debug("%s: dev(%d) close from %p\n", sf->name,
dch->dev.id, __builtin_return_address(0));
module_put(THIS_MODULE);
break;
case CONTROL_CHANNEL:
err = channel_ctrl(sf, arg);
break;
default:
pr_debug("%s: unknown command %x\n", sf->name, cmd);
return -EINVAL;
}
return err;
}
static int __devinit
init_card(struct sfax_hw *sf)
{
int ret, cnt = 3;
u_long flags;
ret = request_irq(sf->irq, speedfax_irq, IRQF_SHARED, sf->name, sf);
if (ret) {
pr_info("%s: couldn't get interrupt %d\n", sf->name, sf->irq);
return ret;
}
while (cnt--) {
spin_lock_irqsave(&sf->lock, flags);
ret = sf->isac.init(&sf->isac);
if (ret) {
spin_unlock_irqrestore(&sf->lock, flags);
pr_info("%s: ISAC init failed with %d\n",
sf->name, ret);
break;
}
enable_hwirq(sf);
WriteISAC_IND(sf, ISAC_CMDR, 0x41);
spin_unlock_irqrestore(&sf->lock, flags);
msleep_interruptible(10);
if (debug & DEBUG_HW)
pr_notice("%s: IRQ %d count %d\n", sf->name,
sf->irq, sf->irqcnt);
if (!sf->irqcnt) {
pr_info("%s: IRQ(%d) got no requests during init %d\n",
sf->name, sf->irq, 3 - cnt);
} else
return 0;
}
free_irq(sf->irq, sf);
return -EIO;
}
static int __devinit
setup_speedfax(struct sfax_hw *sf)
{
u_long flags;
if (!request_region(sf->cfg, 256, sf->name)) {
pr_info("mISDN: %s config port %x-%x already in use\n",
sf->name, sf->cfg, sf->cfg + 255);
return -EIO;
}
outb(0xff, sf->cfg);
outb(0, sf->cfg);
outb(0xdd, sf->cfg + TIGER_AUX_CTRL);
outb(0, sf->cfg + TIGER_AUX_IRQMASK);
sf->isac.type = IPAC_TYPE_ISAC;
sf->p_isac.ale = sf->cfg + SFAX_PCI_ADDR;
sf->p_isac.port = sf->cfg + SFAX_PCI_ISAC;
sf->p_isar.ale = sf->cfg + SFAX_PCI_ADDR;
sf->p_isar.port = sf->cfg + SFAX_PCI_ISAR;
ASSIGN_FUNC(IND, ISAC, sf->isac);
ASSIGN_FUNC(IND, ISAR, sf->isar);
spin_lock_irqsave(&sf->lock, flags);
reset_speedfax(sf);
disable_hwirq(sf);
spin_unlock_irqrestore(&sf->lock, flags);
return 0;
}
static void
release_card(struct sfax_hw *card) {
u_long flags;
spin_lock_irqsave(&card->lock, flags);
disable_hwirq(card);
spin_unlock_irqrestore(&card->lock, flags);
card->isac.release(&card->isac);
free_irq(card->irq, card);
card->isar.release(&card->isar);
mISDN_unregister_device(&card->isac.dch.dev);
release_region(card->cfg, 256);
pci_disable_device(card->pdev);
pci_set_drvdata(card->pdev, NULL);
write_lock_irqsave(&card_lock, flags);
list_del(&card->list);
write_unlock_irqrestore(&card_lock, flags);
kfree(card);
sfax_cnt--;
}
static int __devinit
setup_instance(struct sfax_hw *card)
{
const struct firmware *firmware;
int i, err;
u_long flags;
snprintf(card->name, MISDN_MAX_IDLEN - 1, "Speedfax.%d", sfax_cnt + 1);
write_lock_irqsave(&card_lock, flags);
list_add_tail(&card->list, &Cards);
write_unlock_irqrestore(&card_lock, flags);
_set_debug(card);
spin_lock_init(&card->lock);
card->isac.hwlock = &card->lock;
card->isar.hwlock = &card->lock;
card->isar.ctrl = (void *)&sfax_ctrl;
card->isac.name = card->name;
card->isar.name = card->name;
card->isar.owner = THIS_MODULE;
err = request_firmware(&firmware, "isdn/ISAR.BIN", &card->pdev->dev);
if (err < 0) {
pr_info("%s: firmware request failed %d\n",
card->name, err);
goto error_fw;
}
if (debug & DEBUG_HW)
pr_notice("%s: got firmware %zu bytes\n",
card->name, firmware->size);
mISDNisac_init(&card->isac, card);
card->isac.dch.dev.D.ctrl = sfax_dctrl;
card->isac.dch.dev.Bprotocols =
mISDNisar_init(&card->isar, card);
for (i = 0; i < 2; i++) {
set_channelmap(i + 1, card->isac.dch.dev.channelmap);
list_add(&card->isar.ch[i].bch.ch.list,
&card->isac.dch.dev.bchannels);
}
err = setup_speedfax(card);
if (err)
goto error_setup;
err = card->isar.init(&card->isar);
if (err)
goto error;
err = mISDN_register_device(&card->isac.dch.dev,
&card->pdev->dev, card->name);
if (err)
goto error;
err = init_card(card);
if (err)
goto error_init;
err = card->isar.firmware(&card->isar, firmware->data, firmware->size);
if (!err) {
release_firmware(firmware);
sfax_cnt++;
pr_notice("SpeedFax %d cards installed\n", sfax_cnt);
return 0;
}
disable_hwirq(card);
free_irq(card->irq, card);
error_init:
mISDN_unregister_device(&card->isac.dch.dev);
error:
release_region(card->cfg, 256);
error_setup:
card->isac.release(&card->isac);
card->isar.release(&card->isar);
release_firmware(firmware);
error_fw:
pci_disable_device(card->pdev);
write_lock_irqsave(&card_lock, flags);
list_del(&card->list);
write_unlock_irqrestore(&card_lock, flags);
kfree(card);
return err;
}
static int __devinit
sfaxpci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int err = -ENOMEM;
struct sfax_hw *card = kzalloc(sizeof(struct sfax_hw), GFP_KERNEL);
if (!card) {
pr_info("No memory for Speedfax+ PCI\n");
return err;
}
card->pdev = pdev;
err = pci_enable_device(pdev);
if (err) {
kfree(card);
return err;
}
pr_notice("mISDN: Speedfax found adapter %s at %s\n",
(char *)ent->driver_data, pci_name(pdev));
card->cfg = pci_resource_start(pdev, 0);
card->irq = pdev->irq;
pci_set_drvdata(pdev, card);
err = setup_instance(card);
if (err)
pci_set_drvdata(pdev, NULL);
return err;
}
static void __devexit
sfax_remove_pci(struct pci_dev *pdev)
{
struct sfax_hw *card = pci_get_drvdata(pdev);
if (card)
release_card(card);
else
pr_debug("%s: drvdata already removed\n", __func__);
}
static int __init
Speedfax_init(void)
{
int err;
pr_notice("Sedlbauer Speedfax+ Driver Rev. %s\n",
SPEEDFAX_REV);
err = pci_register_driver(&sfaxpci_driver);
return err;
}
static void __exit
Speedfax_cleanup(void)
{
pci_unregister_driver(&sfaxpci_driver);
}
