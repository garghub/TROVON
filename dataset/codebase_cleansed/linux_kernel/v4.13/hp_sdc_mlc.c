static void hp_sdc_mlc_isr (int irq, void *dev_id,
uint8_t status, uint8_t data)
{
int idx;
hil_mlc *mlc = &hp_sdc_mlc;
write_lock(&mlc->lock);
if (mlc->icount < 0) {
printk(KERN_WARNING PREFIX "HIL Overflow!\n");
up(&mlc->isem);
goto out;
}
idx = 15 - mlc->icount;
if ((status & HP_SDC_STATUS_IRQMASK) == HP_SDC_STATUS_HILDATA) {
mlc->ipacket[idx] |= data | HIL_ERR_INT;
mlc->icount--;
if (hp_sdc_mlc_priv.got5x || !idx)
goto check;
if ((mlc->ipacket[idx - 1] & HIL_PKT_ADDR_MASK) !=
(mlc->ipacket[idx] & HIL_PKT_ADDR_MASK)) {
mlc->ipacket[idx] &= ~HIL_PKT_ADDR_MASK;
mlc->ipacket[idx] |= (mlc->ipacket[idx - 1]
& HIL_PKT_ADDR_MASK);
}
goto check;
}
if (data & HP_SDC_HIL_ISERR)
goto err;
mlc->ipacket[idx] =
(data & HP_SDC_HIL_R1MASK) << HIL_PKT_ADDR_SHIFT;
hp_sdc_mlc_priv.got5x = 1;
goto out;
check:
hp_sdc_mlc_priv.got5x = 0;
if (mlc->imatch == 0)
goto done;
if ((mlc->imatch == (HIL_ERR_INT | HIL_PKT_CMD | HIL_CMD_POL))
&& (mlc->ipacket[idx] == (mlc->imatch | idx)))
goto done;
if (mlc->ipacket[idx] == mlc->imatch)
goto done;
goto out;
err:
printk(KERN_DEBUG PREFIX "err code %x\n", data);
switch (data) {
case HP_SDC_HIL_RC_DONE:
printk(KERN_WARNING PREFIX "Bastard SDC reconfigured loop!\n");
break;
case HP_SDC_HIL_ERR:
mlc->ipacket[idx] |= HIL_ERR_INT | HIL_ERR_PERR |
HIL_ERR_FERR | HIL_ERR_FOF;
break;
case HP_SDC_HIL_TO:
mlc->ipacket[idx] |= HIL_ERR_INT | HIL_ERR_LERR;
break;
case HP_SDC_HIL_RC:
printk(KERN_WARNING PREFIX "Bastard SDC decided to reconfigure loop!\n");
break;
default:
printk(KERN_WARNING PREFIX "Unknown HIL Error status (%x)!\n", data);
break;
}
done:
tasklet_schedule(mlc->tasklet);
up(&mlc->isem);
out:
write_unlock(&mlc->lock);
}
static int hp_sdc_mlc_in(hil_mlc *mlc, suseconds_t timeout)
{
struct hp_sdc_mlc_priv_s *priv;
int rc = 2;
priv = mlc->priv;
if (down_trylock(&mlc->isem)) {
struct timeval tv;
if (priv->emtestmode) {
mlc->ipacket[0] =
HIL_ERR_INT | (mlc->opacket &
(HIL_PKT_CMD |
HIL_PKT_ADDR_MASK |
HIL_PKT_DATA_MASK));
mlc->icount = 14;
goto wasup;
}
do_gettimeofday(&tv);
tv.tv_usec += USEC_PER_SEC * (tv.tv_sec - mlc->instart.tv_sec);
if (tv.tv_usec - mlc->instart.tv_usec > mlc->intimeout) {
rc = 1;
up(&mlc->isem);
}
goto done;
}
wasup:
up(&mlc->isem);
rc = 0;
done:
return rc;
}
static int hp_sdc_mlc_cts(hil_mlc *mlc)
{
struct hp_sdc_mlc_priv_s *priv;
priv = mlc->priv;
BUG_ON(down_trylock(&mlc->isem));
BUG_ON(down_trylock(&mlc->osem));
up(&mlc->isem);
up(&mlc->osem);
if (down_trylock(&mlc->csem)) {
if (priv->trans.act.semaphore != &mlc->csem)
goto poll;
else
goto busy;
}
if (!(priv->tseq[4] & HP_SDC_USE_LOOP))
goto done;
poll:
priv->trans.act.semaphore = &mlc->csem;
priv->trans.actidx = 0;
priv->trans.idx = 1;
priv->trans.endidx = 5;
priv->tseq[0] =
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN | HP_SDC_ACT_SEMAPHORE;
priv->tseq[1] = HP_SDC_CMD_READ_USE;
priv->tseq[2] = 1;
priv->tseq[3] = 0;
priv->tseq[4] = 0;
__hp_sdc_enqueue_transaction(&priv->trans);
busy:
return 1;
done:
priv->trans.act.semaphore = &mlc->osem;
up(&mlc->csem);
return 0;
}
static void hp_sdc_mlc_out(hil_mlc *mlc)
{
struct hp_sdc_mlc_priv_s *priv;
priv = mlc->priv;
BUG_ON(down_trylock(&mlc->osem));
if (mlc->opacket & HIL_DO_ALTER_CTRL)
goto do_control;
do_data:
if (priv->emtestmode) {
up(&mlc->osem);
return;
}
BUG_ON(down_trylock(&mlc->csem));
up(&mlc->csem);
priv->trans.actidx = 0;
priv->trans.idx = 1;
priv->trans.act.semaphore = &mlc->osem;
priv->trans.endidx = 6;
priv->tseq[0] =
HP_SDC_ACT_DATAREG | HP_SDC_ACT_POSTCMD | HP_SDC_ACT_SEMAPHORE;
priv->tseq[1] = 0x7;
priv->tseq[2] =
(mlc->opacket &
(HIL_PKT_ADDR_MASK | HIL_PKT_CMD))
>> HIL_PKT_ADDR_SHIFT;
priv->tseq[3] =
(mlc->opacket & HIL_PKT_DATA_MASK)
>> HIL_PKT_DATA_SHIFT;
priv->tseq[4] = 0;
if (priv->tseq[3] == HIL_CMD_DHR)
priv->tseq[4] = 1;
priv->tseq[5] = HP_SDC_CMD_DO_HIL;
goto enqueue;
do_control:
priv->emtestmode = mlc->opacket & HIL_CTRL_TEST;
BUG_ON((mlc->opacket & (HIL_CTRL_APE | HIL_CTRL_IPF)) == HIL_CTRL_APE);
if ((mlc->opacket & HIL_CTRL_ONLY) == HIL_CTRL_ONLY)
goto control_only;
BUG_ON(mlc->opacket & HIL_CTRL_APE);
goto do_data;
control_only:
priv->trans.actidx = 0;
priv->trans.idx = 1;
priv->trans.act.semaphore = &mlc->osem;
priv->trans.endidx = 4;
priv->tseq[0] =
HP_SDC_ACT_PRECMD | HP_SDC_ACT_DATAOUT | HP_SDC_ACT_SEMAPHORE;
priv->tseq[1] = HP_SDC_CMD_SET_LPC;
priv->tseq[2] = 1;
priv->tseq[3] = 0;
if (mlc->opacket & HIL_CTRL_APE) {
priv->tseq[3] |= HP_SDC_LPC_APE_IPF;
BUG_ON(down_trylock(&mlc->csem));
}
enqueue:
hp_sdc_enqueue_transaction(&priv->trans);
}
static int __init hp_sdc_mlc_init(void)
{
hil_mlc *mlc = &hp_sdc_mlc;
int err;
#ifdef __mc68000__
if (!MACH_IS_HP300)
return -ENODEV;
#endif
printk(KERN_INFO PREFIX "Registering the System Domain Controller's HIL MLC.\n");
hp_sdc_mlc_priv.emtestmode = 0;
hp_sdc_mlc_priv.trans.seq = hp_sdc_mlc_priv.tseq;
hp_sdc_mlc_priv.trans.act.semaphore = &mlc->osem;
hp_sdc_mlc_priv.got5x = 0;
mlc->cts = &hp_sdc_mlc_cts;
mlc->in = &hp_sdc_mlc_in;
mlc->out = &hp_sdc_mlc_out;
mlc->priv = &hp_sdc_mlc_priv;
err = hil_mlc_register(mlc);
if (err) {
printk(KERN_WARNING PREFIX "Failed to register MLC structure with hil_mlc\n");
return err;
}
if (hp_sdc_request_hil_irq(&hp_sdc_mlc_isr)) {
printk(KERN_WARNING PREFIX "Request for raw HIL ISR hook denied\n");
if (hil_mlc_unregister(mlc))
printk(KERN_ERR PREFIX "Failed to unregister MLC structure with hil_mlc.\n"
"This is bad. Could cause an oops.\n");
return -EBUSY;
}
return 0;
}
static void __exit hp_sdc_mlc_exit(void)
{
hil_mlc *mlc = &hp_sdc_mlc;
if (hp_sdc_release_hil_irq(&hp_sdc_mlc_isr))
printk(KERN_ERR PREFIX "Failed to release the raw HIL ISR hook.\n"
"This is bad. Could cause an oops.\n");
if (hil_mlc_unregister(mlc))
printk(KERN_ERR PREFIX "Failed to unregister MLC structure with hil_mlc.\n"
"This is bad. Could cause an oops.\n");
}
