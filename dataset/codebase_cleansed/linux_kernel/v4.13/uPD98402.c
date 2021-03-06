static int fetch_stats(struct atm_dev *dev,struct sonet_stats __user *arg,int zero)
{
struct sonet_stats tmp;
int error = 0;
atomic_add(GET(HECCT),&PRIV(dev)->sonet_stats.uncorr_hcs);
sonet_copy_stats(&PRIV(dev)->sonet_stats,&tmp);
if (arg) error = copy_to_user(arg,&tmp,sizeof(tmp));
if (zero && !error) {
tmp.corr_hcs = tmp.tx_cells = tmp.rx_cells = 0;
sonet_subtract_stats(&PRIV(dev)->sonet_stats,&tmp);
}
return error ? -EFAULT : 0;
}
static int set_framing(struct atm_dev *dev,unsigned char framing)
{
static const unsigned char sonet[] = { 1,2,3,0 };
static const unsigned char sdh[] = { 1,0,0,2 };
const char *set;
unsigned long flags;
switch (framing) {
case SONET_FRAME_SONET:
set = sonet;
break;
case SONET_FRAME_SDH:
set = sdh;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&PRIV(dev)->lock, flags);
PUT(set[0],C11T);
PUT(set[1],C12T);
PUT(set[2],C13T);
PUT((GET(MDR) & ~uPD98402_MDR_SS_MASK) | (set[3] <<
uPD98402_MDR_SS_SHIFT),MDR);
spin_unlock_irqrestore(&PRIV(dev)->lock, flags);
return 0;
}
static int get_sense(struct atm_dev *dev,u8 __user *arg)
{
unsigned long flags;
unsigned char s[3];
spin_lock_irqsave(&PRIV(dev)->lock, flags);
s[0] = GET(C11R);
s[1] = GET(C12R);
s[2] = GET(C13R);
spin_unlock_irqrestore(&PRIV(dev)->lock, flags);
return (put_user(s[0], arg) || put_user(s[1], arg+1) ||
put_user(s[2], arg+2) || put_user(0xff, arg+3) ||
put_user(0xff, arg+4) || put_user(0xff, arg+5)) ? -EFAULT : 0;
}
static int set_loopback(struct atm_dev *dev,int mode)
{
unsigned char mode_reg;
mode_reg = GET(MDR) & ~(uPD98402_MDR_TPLP | uPD98402_MDR_ALP |
uPD98402_MDR_RPLP);
switch (__ATM_LM_XTLOC(mode)) {
case __ATM_LM_NONE:
break;
case __ATM_LM_PHY:
mode_reg |= uPD98402_MDR_TPLP;
break;
case __ATM_LM_ATM:
mode_reg |= uPD98402_MDR_ALP;
break;
default:
return -EINVAL;
}
switch (__ATM_LM_XTRMT(mode)) {
case __ATM_LM_NONE:
break;
case __ATM_LM_PHY:
mode_reg |= uPD98402_MDR_RPLP;
break;
default:
return -EINVAL;
}
PUT(mode_reg,MDR);
PRIV(dev)->loop_mode = mode;
return 0;
}
static int uPD98402_ioctl(struct atm_dev *dev,unsigned int cmd,void __user *arg)
{
switch (cmd) {
case SONET_GETSTATZ:
case SONET_GETSTAT:
return fetch_stats(dev,arg, cmd == SONET_GETSTATZ);
case SONET_SETFRAMING:
return set_framing(dev, (int)(unsigned long)arg);
case SONET_GETFRAMING:
return put_user(PRIV(dev)->framing,(int __user *)arg) ?
-EFAULT : 0;
case SONET_GETFRSENSE:
return get_sense(dev,arg);
case ATM_SETLOOP:
return set_loopback(dev, (int)(unsigned long)arg);
case ATM_GETLOOP:
return put_user(PRIV(dev)->loop_mode,(int __user *)arg) ?
-EFAULT : 0;
case ATM_QUERYLOOP:
return put_user(ATM_LM_LOC_PHY | ATM_LM_LOC_ATM |
ATM_LM_RMT_PHY,(int __user *)arg) ? -EFAULT : 0;
default:
return -ENOIOCTLCMD;
}
}
static void stat_event(struct atm_dev *dev)
{
unsigned char events;
events = GET(PCR);
if (events & uPD98402_PFM_PFEB) ADD_LIMITED(path_febe,PFECB);
if (events & uPD98402_PFM_LFEB) ADD_LIMITED(line_febe,LECCT);
if (events & uPD98402_PFM_B3E) ADD_LIMITED(path_bip,B3ECT);
if (events & uPD98402_PFM_B2E) ADD_LIMITED(line_bip,B2ECT);
if (events & uPD98402_PFM_B1E) ADD_LIMITED(section_bip,B1ECT);
}
static void uPD98402_int(struct atm_dev *dev)
{
static unsigned long silence = 0;
unsigned char reason;
while ((reason = GET(PICR))) {
if (reason & uPD98402_INT_LOS)
printk(KERN_NOTICE "%s(itf %d): signal lost\n",
dev->type,dev->number);
if (reason & uPD98402_INT_PFM) stat_event(dev);
if (reason & uPD98402_INT_PCO) {
(void) GET(PCOCR);
atomic_add(GET(HECCT),
&PRIV(dev)->sonet_stats.uncorr_hcs);
}
if ((reason & uPD98402_INT_RFO) &&
(time_after(jiffies, silence) || silence == 0)) {
printk(KERN_WARNING "%s(itf %d): uPD98402 receive "
"FIFO overflow\n",dev->type,dev->number);
silence = (jiffies+HZ/2)|1;
}
}
}
static int uPD98402_start(struct atm_dev *dev)
{
DPRINTK("phy_start\n");
if (!(dev->dev_data = kmalloc(sizeof(struct uPD98402_priv),GFP_KERNEL)))
return -ENOMEM;
spin_lock_init(&PRIV(dev)->lock);
memset(&PRIV(dev)->sonet_stats,0,sizeof(struct k_sonet_stats));
(void) GET(PCR);
PUT(uPD98402_PFM_FJ,PCMR);
(void) GET(PCOCR);
PUT(~uPD98402_PCO_HECC,PCOMR);
(void) GET(PICR);
PUT(~(uPD98402_INT_PFM | uPD98402_INT_ALM | uPD98402_INT_RFO |
uPD98402_INT_LOS),PIMR);
(void) fetch_stats(dev,NULL,1);
atomic_set(&PRIV(dev)->sonet_stats.corr_hcs,-1);
atomic_set(&PRIV(dev)->sonet_stats.tx_cells,-1);
atomic_set(&PRIV(dev)->sonet_stats.rx_cells,-1);
return 0;
}
static int uPD98402_stop(struct atm_dev *dev)
{
kfree(PRIV(dev));
return 0;
}
int uPD98402_init(struct atm_dev *dev)
{
DPRINTK("phy_init\n");
dev->phy = &uPD98402_ops;
return 0;
}
static __init int uPD98402_module_init(void)
{
return 0;
}
