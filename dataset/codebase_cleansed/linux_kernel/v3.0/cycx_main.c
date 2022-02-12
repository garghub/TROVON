static int __init cycx_init(void)
{
int cnt, err = -ENOMEM;
printk(KERN_INFO "%s v%u.%u %s\n",
cycx_fullname, CYCX_DRV_VERSION, CYCX_DRV_RELEASE,
cycx_copyright);
cycx_ncards = min_t(int, cycx_ncards, CYCX_MAX_CARDS);
cycx_ncards = max_t(int, cycx_ncards, 1);
cycx_card_array = kcalloc(cycx_ncards, sizeof(struct cycx_device), GFP_KERNEL);
if (!cycx_card_array)
goto out;
for (cnt = 0; cnt < cycx_ncards; ++cnt) {
struct cycx_device *card = &cycx_card_array[cnt];
struct wan_device *wandev = &card->wandev;
sprintf(card->devname, "%s%d", cycx_drvname, cnt + 1);
wandev->magic = ROUTER_MAGIC;
wandev->name = card->devname;
wandev->private = card;
wandev->setup = cycx_wan_setup;
wandev->shutdown = cycx_wan_shutdown;
err = register_wan_device(wandev);
if (err) {
printk(KERN_ERR "%s: %s registration failed with "
"error %d!\n",
cycx_drvname, card->devname, err);
break;
}
}
err = -ENODEV;
if (!cnt) {
kfree(cycx_card_array);
goto out;
}
err = 0;
cycx_ncards = cnt;
out: return err;
}
static void __exit cycx_exit(void)
{
int i = 0;
for (; i < cycx_ncards; ++i) {
struct cycx_device *card = &cycx_card_array[i];
unregister_wan_device(card->devname);
}
kfree(cycx_card_array);
}
static int cycx_wan_setup(struct wan_device *wandev, wandev_conf_t *conf)
{
int rc = -EFAULT;
struct cycx_device *card;
int irq;
if (!wandev || !wandev->private || !conf)
goto out;
card = wandev->private;
rc = -EBUSY;
if (wandev->state != WAN_UNCONFIGURED)
goto out;
rc = -EINVAL;
if (!conf->data_size || !conf->data) {
printk(KERN_ERR "%s: firmware not found in configuration "
"data!\n", wandev->name);
goto out;
}
if (conf->irq <= 0) {
printk(KERN_ERR "%s: can't configure without IRQ!\n",
wandev->name);
goto out;
}
irq = conf->irq == 2 ? 9 : conf->irq;
if (request_irq(irq, cycx_isr, 0, wandev->name, card)) {
printk(KERN_ERR "%s: can't reserve IRQ %d!\n",
wandev->name, irq);
goto out;
}
memset(&card->hw, 0, sizeof(card->hw));
card->hw.irq = irq;
card->hw.dpmsize = CYCX_WINDOWSIZE;
card->hw.fwid = CFID_X25_2X;
spin_lock_init(&card->lock);
init_waitqueue_head(&card->wait_stats);
rc = cycx_setup(&card->hw, conf->data, conf->data_size, conf->maddr);
if (rc)
goto out_irq;
wandev->irq = irq;
wandev->dma = wandev->ioport = 0;
wandev->maddr = (unsigned long)card->hw.dpmbase;
wandev->msize = card->hw.dpmsize;
wandev->hw_opt[2] = 0;
wandev->hw_opt[3] = card->hw.fwid;
switch (card->hw.fwid) {
#ifdef CONFIG_CYCLOMX_X25
case CFID_X25_2X:
rc = cycx_x25_wan_init(card, conf);
break;
#endif
default:
printk(KERN_ERR "%s: this firmware is not supported!\n",
wandev->name);
rc = -EINVAL;
}
if (rc) {
cycx_down(&card->hw);
goto out_irq;
}
rc = 0;
out:
return rc;
out_irq:
free_irq(irq, card);
goto out;
}
static int cycx_wan_shutdown(struct wan_device *wandev)
{
int ret = -EFAULT;
struct cycx_device *card;
if (!wandev || !wandev->private)
goto out;
ret = 0;
if (wandev->state == WAN_UNCONFIGURED)
goto out;
card = wandev->private;
wandev->state = WAN_UNCONFIGURED;
cycx_down(&card->hw);
printk(KERN_INFO "%s: irq %d being freed!\n", wandev->name,
wandev->irq);
free_irq(wandev->irq, card);
out: return ret;
}
static irqreturn_t cycx_isr(int irq, void *dev_id)
{
struct cycx_device *card = dev_id;
if (card->wandev.state == WAN_UNCONFIGURED)
goto out;
if (card->in_isr) {
printk(KERN_WARNING "%s: interrupt re-entrancy on IRQ %d!\n",
card->devname, card->wandev.irq);
goto out;
}
if (card->isr)
card->isr(card);
return IRQ_HANDLED;
out:
return IRQ_NONE;
}
void cycx_set_state(struct cycx_device *card, int state)
{
unsigned long flags;
char *string_state = NULL;
spin_lock_irqsave(&card->lock, flags);
if (card->wandev.state != state) {
switch (state) {
case WAN_CONNECTED:
string_state = "connected!";
break;
case WAN_DISCONNECTED:
string_state = "disconnected!";
break;
}
printk(KERN_INFO "%s: link %s\n", card->devname, string_state);
card->wandev.state = state;
}
card->state_tick = jiffies;
spin_unlock_irqrestore(&card->lock, flags);
}
