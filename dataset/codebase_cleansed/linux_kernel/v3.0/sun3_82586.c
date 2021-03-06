static int sun3_82586_close(struct net_device *dev)
{
free_irq(dev->irq, dev);
sun3_reset586();
netif_stop_queue(dev);
return 0;
}
static int sun3_82586_open(struct net_device *dev)
{
int ret;
sun3_disint();
alloc586(dev);
init586(dev);
startrecv586(dev);
sun3_enaint();
ret = request_irq(dev->irq, sun3_82586_interrupt,0,dev->name,dev);
if (ret)
{
sun3_reset586();
return ret;
}
netif_start_queue(dev);
return 0;
}
static int check586(struct net_device *dev,char *where,unsigned size)
{
struct priv pb;
struct priv *p = &pb;
char *iscp_addr;
int i;
p->base = (unsigned long) dvma_btov(0);
p->memtop = (char *)dvma_btov((unsigned long)where);
p->scp = (struct scp_struct *)(p->base + SCP_DEFAULT_ADDRESS);
memset((char *)p->scp,0, sizeof(struct scp_struct));
for(i=0;i<sizeof(struct scp_struct);i++)
if(((char *)p->scp)[i])
return 0;
p->scp->sysbus = SYSBUSVAL;
if(p->scp->sysbus != SYSBUSVAL)
return 0;
iscp_addr = (char *)dvma_btov((unsigned long)where);
p->iscp = (struct iscp_struct *) iscp_addr;
memset((char *)p->iscp,0, sizeof(struct iscp_struct));
p->scp->iscp = make24(p->iscp);
p->iscp->busy = 1;
sun3_reset586();
sun3_attn586();
DELAY(1);
if(p->iscp->busy)
return 0;
return 1;
}
static void alloc586(struct net_device *dev)
{
struct priv *p = netdev_priv(dev);
sun3_reset586();
DELAY(1);
p->scp = (struct scp_struct *) (p->base + SCP_DEFAULT_ADDRESS);
p->iscp = (struct iscp_struct *) dvma_btov(dev->mem_start);
p->scb = (struct scb_struct *) ((char *)p->iscp + sizeof(struct iscp_struct));
memset((char *) p->iscp,0,sizeof(struct iscp_struct));
memset((char *) p->scp ,0,sizeof(struct scp_struct));
p->scp->iscp = make24(p->iscp);
p->scp->sysbus = SYSBUSVAL;
p->iscp->scb_offset = make16(p->scb);
p->iscp->scb_base = make24(dvma_btov(dev->mem_start));
p->iscp->busy = 1;
sun3_reset586();
sun3_attn586();
DELAY(1);
if(p->iscp->busy)
printk("%s: Init-Problems (alloc).\n",dev->name);
p->reseted = 0;
memset((char *)p->scb,0,sizeof(struct scb_struct));
}
struct net_device * __init sun3_82586_probe(int unit)
{
struct net_device *dev;
unsigned long ioaddr;
static int found = 0;
int err = -ENOMEM;
switch(idprom->id_machtype) {
case SM_SUN3|SM_3_160:
case SM_SUN3|SM_3_260:
break;
default:
return ERR_PTR(-ENODEV);
}
if (found)
return ERR_PTR(-ENODEV);
ioaddr = (unsigned long)ioremap(IE_OBIO, SUN3_82586_TOTAL_SIZE);
if (!ioaddr)
return ERR_PTR(-ENOMEM);
found = 1;
dev = alloc_etherdev(sizeof(struct priv));
if (!dev)
goto out;
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
}
dev->irq = IE_IRQ;
dev->base_addr = ioaddr;
err = sun3_82586_probe1(dev, ioaddr);
if (err)
goto out1;
err = register_netdev(dev);
if (err)
goto out2;
return dev;
out2:
release_region(ioaddr, SUN3_82586_TOTAL_SIZE);
out1:
free_netdev(dev);
out:
iounmap((void __iomem *)ioaddr);
return ERR_PTR(err);
}
static int __init sun3_82586_probe1(struct net_device *dev,int ioaddr)
{
int i, size, retval;
if (!request_region(ioaddr, SUN3_82586_TOTAL_SIZE, DRV_NAME))
return -EBUSY;
for(i = 0; i < 6 ; i++)
dev->dev_addr[i] = idprom->id_ethaddr[i];
printk("%s: SUN3 Intel 82586 found at %lx, ",dev->name,dev->base_addr);
size = 0x8000;
dev->mem_start = (unsigned long)dvma_malloc_align(0x8000, 0x1000);
dev->mem_end = dev->mem_start + size;
if(size != 0x2000 && size != 0x4000 && size != 0x8000) {
printk("\n%s: Illegal memory size %d. Allowed is 0x2000 or 0x4000 or 0x8000 bytes.\n",dev->name,size);
retval = -ENODEV;
goto out;
}
if(!check586(dev,(char *) dev->mem_start,size)) {
printk("?memcheck, Can't find memory at 0x%lx with size %d!\n",dev->mem_start,size);
retval = -ENODEV;
goto out;
}
((struct priv *)netdev_priv(dev))->memtop =
(char *)dvma_btov(dev->mem_start);
((struct priv *)netdev_priv(dev))->base = (unsigned long) dvma_btov(0);
alloc586(dev);
if(size == 0x2000)
((struct priv *)netdev_priv(dev))->num_recv_buffs =
NUM_RECV_BUFFS_8;
else if(size == 0x4000)
((struct priv *)netdev_priv(dev))->num_recv_buffs =
NUM_RECV_BUFFS_16;
else
((struct priv *)netdev_priv(dev))->num_recv_buffs =
NUM_RECV_BUFFS_32;
printk("Memaddr: 0x%lx, Memsize: %d, IRQ %d\n",dev->mem_start,size, dev->irq);
dev->netdev_ops = &sun3_82586_netdev_ops;
dev->watchdog_timeo = HZ/20;
dev->if_port = 0;
return 0;
out:
release_region(ioaddr, SUN3_82586_TOTAL_SIZE);
return retval;
}
static int init586(struct net_device *dev)
{
void *ptr;
int i,result=0;
struct priv *p = netdev_priv(dev);
volatile struct configure_cmd_struct *cfg_cmd;
volatile struct iasetup_cmd_struct *ias_cmd;
volatile struct tdr_cmd_struct *tdr_cmd;
volatile struct mcsetup_cmd_struct *mc_cmd;
struct netdev_hw_addr *ha;
int num_addrs=netdev_mc_count(dev);
ptr = (void *) ((char *)p->scb + sizeof(struct scb_struct));
cfg_cmd = (struct configure_cmd_struct *)ptr;
cfg_cmd->cmd_status = 0;
cfg_cmd->cmd_cmd = swab16(CMD_CONFIGURE | CMD_LAST);
cfg_cmd->cmd_link = 0xffff;
cfg_cmd->byte_cnt = 0x0a;
cfg_cmd->fifo = fifo;
cfg_cmd->sav_bf = 0x40;
cfg_cmd->adr_len = 0x2e;
cfg_cmd->priority = 0x00;
cfg_cmd->ifs = 0x60;
cfg_cmd->time_low = 0x00;
cfg_cmd->time_high = 0xf2;
cfg_cmd->promisc = 0;
if(dev->flags & IFF_ALLMULTI) {
int len = ((char *) p->iscp - (char *) ptr - 8) / 6;
if(num_addrs > len) {
printk("%s: switching to promisc. mode\n",dev->name);
cfg_cmd->promisc = 1;
}
}
if(dev->flags&IFF_PROMISC)
cfg_cmd->promisc = 1;
cfg_cmd->carr_coll = 0x00;
p->scb->cbl_offset = make16(cfg_cmd);
p->scb->cmd_ruc = 0;
p->scb->cmd_cuc = CUC_START;
sun3_attn586();
WAIT_4_STAT_COMPL(cfg_cmd);
if((swab16(cfg_cmd->cmd_status) & (STAT_OK|STAT_COMPL)) != (STAT_COMPL|STAT_OK))
{
printk("%s: configure command failed: %x\n",dev->name,swab16(cfg_cmd->cmd_status));
return 1;
}
ias_cmd = (struct iasetup_cmd_struct *)ptr;
ias_cmd->cmd_status = 0;
ias_cmd->cmd_cmd = swab16(CMD_IASETUP | CMD_LAST);
ias_cmd->cmd_link = 0xffff;
memcpy((char *)&ias_cmd->iaddr,(char *) dev->dev_addr,ETH_ALEN);
p->scb->cbl_offset = make16(ias_cmd);
p->scb->cmd_cuc = CUC_START;
sun3_attn586();
WAIT_4_STAT_COMPL(ias_cmd);
if((swab16(ias_cmd->cmd_status) & (STAT_OK|STAT_COMPL)) != (STAT_OK|STAT_COMPL)) {
printk("%s (82586): individual address setup command failed: %04x\n",dev->name,swab16(ias_cmd->cmd_status));
return 1;
}
tdr_cmd = (struct tdr_cmd_struct *)ptr;
tdr_cmd->cmd_status = 0;
tdr_cmd->cmd_cmd = swab16(CMD_TDR | CMD_LAST);
tdr_cmd->cmd_link = 0xffff;
tdr_cmd->status = 0;
p->scb->cbl_offset = make16(tdr_cmd);
p->scb->cmd_cuc = CUC_START;
sun3_attn586();
WAIT_4_STAT_COMPL(tdr_cmd);
if(!(swab16(tdr_cmd->cmd_status) & STAT_COMPL))
{
printk("%s: Problems while running the TDR.\n",dev->name);
}
else
{
DELAY_16();
result = swab16(tdr_cmd->status);
p->scb->cmd_cuc = p->scb->cus & STAT_MASK;
sun3_attn586();
if(result & TDR_LNK_OK)
;
else if(result & TDR_XCVR_PRB)
printk("%s: TDR: Transceiver problem. Check the cable(s)!\n",dev->name);
else if(result & TDR_ET_OPN)
printk("%s: TDR: No correct termination %d clocks away.\n",dev->name,result & TDR_TIMEMASK);
else if(result & TDR_ET_SRT)
{
if (result & TDR_TIMEMASK)
printk("%s: TDR: Detected a short circuit %d clocks away.\n",dev->name,result & TDR_TIMEMASK);
}
else
printk("%s: TDR: Unknown status %04x\n",dev->name,result);
}
if(num_addrs && !(dev->flags & IFF_PROMISC) )
{
mc_cmd = (struct mcsetup_cmd_struct *) ptr;
mc_cmd->cmd_status = 0;
mc_cmd->cmd_cmd = swab16(CMD_MCSETUP | CMD_LAST);
mc_cmd->cmd_link = 0xffff;
mc_cmd->mc_cnt = swab16(num_addrs * 6);
i = 0;
netdev_for_each_mc_addr(ha, dev)
memcpy((char *) mc_cmd->mc_list[i++],
ha->addr, ETH_ALEN);
p->scb->cbl_offset = make16(mc_cmd);
p->scb->cmd_cuc = CUC_START;
sun3_attn586();
WAIT_4_STAT_COMPL(mc_cmd);
if( (swab16(mc_cmd->cmd_status) & (STAT_COMPL|STAT_OK)) != (STAT_COMPL|STAT_OK) )
printk("%s: Can't apply multicast-address-list.\n",dev->name);
}
#if (NUM_XMIT_BUFFS == 1)
for(i=0;i<2;i++)
{
p->nop_cmds[i] = (struct nop_cmd_struct *)ptr;
p->nop_cmds[i]->cmd_cmd = swab16(CMD_NOP);
p->nop_cmds[i]->cmd_status = 0;
p->nop_cmds[i]->cmd_link = make16((p->nop_cmds[i]));
ptr = (char *) ptr + sizeof(struct nop_cmd_struct);
}
#else
for(i=0;i<NUM_XMIT_BUFFS;i++)
{
p->nop_cmds[i] = (struct nop_cmd_struct *)ptr;
p->nop_cmds[i]->cmd_cmd = swab16(CMD_NOP);
p->nop_cmds[i]->cmd_status = 0;
p->nop_cmds[i]->cmd_link = make16((p->nop_cmds[i]));
ptr = (char *) ptr + sizeof(struct nop_cmd_struct);
}
#endif
ptr = alloc_rfa(dev,(void *)ptr);
for(i=0;i<NUM_XMIT_BUFFS;i++)
{
p->xmit_cmds[i] = (struct transmit_cmd_struct *)ptr;
ptr = (char *) ptr + sizeof(struct transmit_cmd_struct);
p->xmit_cbuffs[i] = (char *)ptr;
ptr = (char *) ptr + XMIT_BUFF_SIZE;
p->xmit_buffs[i] = (struct tbd_struct *)ptr;
ptr = (char *) ptr + sizeof(struct tbd_struct);
if((void *)ptr > (void *)dev->mem_end)
{
printk("%s: not enough shared-mem for your configuration!\n",dev->name);
return 1;
}
memset((char *)(p->xmit_cmds[i]) ,0, sizeof(struct transmit_cmd_struct));
memset((char *)(p->xmit_buffs[i]),0, sizeof(struct tbd_struct));
p->xmit_cmds[i]->cmd_link = make16(p->nop_cmds[(i+1)%NUM_XMIT_BUFFS]);
p->xmit_cmds[i]->cmd_status = swab16(STAT_COMPL);
p->xmit_cmds[i]->cmd_cmd = swab16(CMD_XMIT | CMD_INT);
p->xmit_cmds[i]->tbd_offset = make16((p->xmit_buffs[i]));
p->xmit_buffs[i]->next = 0xffff;
p->xmit_buffs[i]->buffer = make24((p->xmit_cbuffs[i]));
}
p->xmit_count = 0;
p->xmit_last = 0;
#ifndef NO_NOPCOMMANDS
p->nop_point = 0;
#endif
#ifndef NO_NOPCOMMANDS
p->scb->cbl_offset = make16(p->nop_cmds[0]);
p->scb->cmd_cuc = CUC_START;
sun3_attn586();
WAIT_4_SCB_CMD();
#else
p->xmit_cmds[0]->cmd_link = make16(p->xmit_cmds[0]);
p->xmit_cmds[0]->cmd_cmd = swab16(CMD_XMIT | CMD_SUSPEND | CMD_INT);
#endif
p->scb->cmd_cuc = p->scb->cus & STAT_MASK;
sun3_attn586();
DELAY_16();
sun3_enaint();
sun3_active();
return 0;
}
static void *alloc_rfa(struct net_device *dev,void *ptr)
{
volatile struct rfd_struct *rfd = (struct rfd_struct *)ptr;
volatile struct rbd_struct *rbd;
int i;
struct priv *p = netdev_priv(dev);
memset((char *) rfd,0,sizeof(struct rfd_struct)*(p->num_recv_buffs+rfdadd));
p->rfd_first = rfd;
for(i = 0; i < (p->num_recv_buffs+rfdadd); i++) {
rfd[i].next = make16(rfd + (i+1) % (p->num_recv_buffs+rfdadd) );
rfd[i].rbd_offset = 0xffff;
}
rfd[p->num_recv_buffs-1+rfdadd].last = RFD_SUSP;
ptr = (void *) (rfd + (p->num_recv_buffs + rfdadd) );
rbd = (struct rbd_struct *) ptr;
ptr = (void *) (rbd + p->num_recv_buffs);
memset((char *) rbd,0,sizeof(struct rbd_struct)*(p->num_recv_buffs));
for(i=0;i<p->num_recv_buffs;i++)
{
rbd[i].next = make16((rbd + (i+1) % p->num_recv_buffs));
rbd[i].size = swab16(RECV_BUFF_SIZE);
rbd[i].buffer = make24(ptr);
ptr = (char *) ptr + RECV_BUFF_SIZE;
}
p->rfd_top = p->rfd_first;
p->rfd_last = p->rfd_first + (p->num_recv_buffs - 1 + rfdadd);
p->scb->rfa_offset = make16(p->rfd_first);
p->rfd_first->rbd_offset = make16(rbd);
return ptr;
}
static irqreturn_t sun3_82586_interrupt(int irq,void *dev_id)
{
struct net_device *dev = dev_id;
unsigned short stat;
int cnt=0;
struct priv *p;
if (!dev) {
printk ("sun3_82586-interrupt: irq %d for unknown device.\n",irq);
return IRQ_NONE;
}
p = netdev_priv(dev);
if(debuglevel > 1)
printk("I");
WAIT_4_SCB_CMD();
while((stat=p->scb->cus & STAT_MASK))
{
p->scb->cmd_cuc = stat;
sun3_attn586();
if(stat & STAT_FR)
sun3_82586_rcv_int(dev);
if(stat & STAT_RNR)
{
printk("(R)");
if(p->scb->rus & RU_SUSPEND)
{
WAIT_4_SCB_CMD();
p->scb->cmd_ruc = RUC_RESUME;
sun3_attn586();
WAIT_4_SCB_CMD_RUC();
}
else
{
printk("%s: Receiver-Unit went 'NOT READY': %04x/%02x.\n",dev->name,(int) stat,(int) p->scb->rus);
sun3_82586_rnr_int(dev);
}
}
if(stat & STAT_CX)
sun3_82586_xmt_int(dev);
#ifndef NO_NOPCOMMANDS
if(stat & STAT_CNA)
{
if(netif_running(dev))
printk("%s: oops! CU has left active state. stat: %04x/%02x.\n",dev->name,(int) stat,(int) p->scb->cus);
}
#endif
if(debuglevel > 1)
printk("%d",cnt++);
WAIT_4_SCB_CMD();
if(p->scb->cmd_cuc)
{
printk("%s: Acknowledge timed out.\n",dev->name);
sun3_disint();
break;
}
}
if(debuglevel > 1)
printk("i");
return IRQ_HANDLED;
}
static void sun3_82586_rcv_int(struct net_device *dev)
{
int status,cnt=0;
unsigned short totlen;
struct sk_buff *skb;
struct rbd_struct *rbd;
struct priv *p = netdev_priv(dev);
if(debuglevel > 0)
printk("R");
for(;(status = p->rfd_top->stat_high) & RFD_COMPL;)
{
rbd = (struct rbd_struct *) make32(p->rfd_top->rbd_offset);
if(status & RFD_OK)
{
if( (totlen = swab16(rbd->status)) & RBD_LAST)
{
totlen &= RBD_MASK;
rbd->status = 0;
skb = (struct sk_buff *) dev_alloc_skb(totlen+2);
if(skb != NULL)
{
skb_reserve(skb,2);
skb_put(skb,totlen);
skb_copy_to_linear_data(skb,(char *) p->base+swab32((unsigned long) rbd->buffer),totlen);
skb->protocol=eth_type_trans(skb,dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
else
dev->stats.rx_dropped++;
}
else
{
int rstat;
totlen = 0;
while(!((rstat=swab16(rbd->status)) & RBD_LAST))
{
totlen += rstat & RBD_MASK;
if(!rstat)
{
printk("%s: Whoops .. no end mark in RBD list\n",dev->name);
break;
}
rbd->status = 0;
rbd = (struct rbd_struct *) make32(rbd->next);
}
totlen += rstat & RBD_MASK;
rbd->status = 0;
printk("%s: received oversized frame! length: %d\n",dev->name,totlen);
dev->stats.rx_dropped++;
}
}
else
{
printk("%s: oops! rfd-error-status: %04x\n",dev->name,status);
dev->stats.rx_errors++;
}
p->rfd_top->stat_high = 0;
p->rfd_top->last = RFD_SUSP;
p->rfd_top->rbd_offset = 0xffff;
p->rfd_last->last = 0;
p->rfd_last = p->rfd_top;
p->rfd_top = (struct rfd_struct *) make32(p->rfd_top->next);
p->scb->rfa_offset = make16(p->rfd_top);
if(debuglevel > 0)
printk("%d",cnt++);
}
if(automatic_resume)
{
WAIT_4_SCB_CMD();
p->scb->cmd_ruc = RUC_RESUME;
sun3_attn586();
WAIT_4_SCB_CMD_RUC();
}
#ifdef WAIT_4_BUSY
{
int i;
for(i=0;i<1024;i++)
{
if(p->rfd_top->status)
break;
DELAY_16();
if(i == 1023)
printk("%s: RU hasn't fetched next RFD (not busy/complete)\n",dev->name);
}
}
#endif
#if 0
if(!at_least_one)
{
int i;
volatile struct rfd_struct *rfds=p->rfd_top;
volatile struct rbd_struct *rbds;
printk("%s: received a FC intr. without having a frame: %04x %d\n",dev->name,status,old_at_least);
for(i=0;i< (p->num_recv_buffs+4);i++)
{
rbds = (struct rbd_struct *) make32(rfds->rbd_offset);
printk("%04x:%04x ",rfds->status,rbds->status);
rfds = (struct rfd_struct *) make32(rfds->next);
}
printk("\nerrs: %04x %04x stat: %04x\n",(int)p->scb->rsc_errs,(int)p->scb->ovrn_errs,(int)p->scb->status);
printk("\nerrs: %04x %04x rus: %02x, cus: %02x\n",(int)p->scb->rsc_errs,(int)p->scb->ovrn_errs,(int)p->scb->rus,(int)p->scb->cus);
}
old_at_least = at_least_one;
#endif
if(debuglevel > 0)
printk("r");
}
static void sun3_82586_rnr_int(struct net_device *dev)
{
struct priv *p = netdev_priv(dev);
dev->stats.rx_errors++;
WAIT_4_SCB_CMD();
p->scb->cmd_ruc = RUC_ABORT;
sun3_attn586();
WAIT_4_SCB_CMD_RUC();
alloc_rfa(dev,(char *)p->rfd_first);
startrecv586(dev);
printk("%s: Receive-Unit restarted. Status: %04x\n",dev->name,p->scb->rus);
}
static void sun3_82586_xmt_int(struct net_device *dev)
{
int status;
struct priv *p = netdev_priv(dev);
if(debuglevel > 0)
printk("X");
status = swab16(p->xmit_cmds[p->xmit_last]->cmd_status);
if(!(status & STAT_COMPL))
printk("%s: strange .. xmit-int without a 'COMPLETE'\n",dev->name);
if(status & STAT_OK)
{
dev->stats.tx_packets++;
dev->stats.collisions += (status & TCMD_MAXCOLLMASK);
}
else
{
dev->stats.tx_errors++;
if(status & TCMD_LATECOLL) {
printk("%s: late collision detected.\n",dev->name);
dev->stats.collisions++;
}
else if(status & TCMD_NOCARRIER) {
dev->stats.tx_carrier_errors++;
printk("%s: no carrier detected.\n",dev->name);
}
else if(status & TCMD_LOSTCTS)
printk("%s: loss of CTS detected.\n",dev->name);
else if(status & TCMD_UNDERRUN) {
dev->stats.tx_fifo_errors++;
printk("%s: DMA underrun detected.\n",dev->name);
}
else if(status & TCMD_MAXCOLL) {
printk("%s: Max. collisions exceeded.\n",dev->name);
dev->stats.collisions += 16;
}
}
#if (NUM_XMIT_BUFFS > 1)
if( (++p->xmit_last) == NUM_XMIT_BUFFS)
p->xmit_last = 0;
#endif
netif_wake_queue(dev);
}
static void startrecv586(struct net_device *dev)
{
struct priv *p = netdev_priv(dev);
WAIT_4_SCB_CMD();
WAIT_4_SCB_CMD_RUC();
p->scb->rfa_offset = make16(p->rfd_first);
p->scb->cmd_ruc = RUC_START;
sun3_attn586();
WAIT_4_SCB_CMD_RUC();
}
static void sun3_82586_timeout(struct net_device *dev)
{
struct priv *p = netdev_priv(dev);
#ifndef NO_NOPCOMMANDS
if(p->scb->cus & CU_ACTIVE)
{
netif_wake_queue(dev);
#ifdef DEBUG
printk("%s: strange ... timeout with CU active?!?\n",dev->name);
printk("%s: X0: %04x N0: %04x N1: %04x %d\n",dev->name,(int)swab16(p->xmit_cmds[0]->cmd_status),(int)swab16(p->nop_cmds[0]->cmd_status),(int)swab16(p->nop_cmds[1]->cmd_status),(int)p->nop_point);
#endif
p->scb->cmd_cuc = CUC_ABORT;
sun3_attn586();
WAIT_4_SCB_CMD();
p->scb->cbl_offset = make16(p->nop_cmds[p->nop_point]);
p->scb->cmd_cuc = CUC_START;
sun3_attn586();
WAIT_4_SCB_CMD();
dev->trans_start = jiffies;
return 0;
}
#endif
{
#ifdef DEBUG
printk("%s: xmitter timed out, try to restart! stat: %02x\n",dev->name,p->scb->cus);
printk("%s: command-stats: %04x %04x\n",dev->name,swab16(p->xmit_cmds[0]->cmd_status),swab16(p->xmit_cmds[1]->cmd_status));
printk("%s: check, whether you set the right interrupt number!\n",dev->name);
#endif
sun3_82586_close(dev);
sun3_82586_open(dev);
}
dev->trans_start = jiffies;
}
static int sun3_82586_send_packet(struct sk_buff *skb, struct net_device *dev)
{
int len,i;
#ifndef NO_NOPCOMMANDS
int next_nop;
#endif
struct priv *p = netdev_priv(dev);
if(skb->len > XMIT_BUFF_SIZE)
{
printk("%s: Sorry, max. framelength is %d bytes. The length of your frame is %d bytes.\n",dev->name,XMIT_BUFF_SIZE,skb->len);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
#if(NUM_XMIT_BUFFS > 1)
if(test_and_set_bit(0,(void *) &p->lock)) {
printk("%s: Queue was locked\n",dev->name);
return NETDEV_TX_BUSY;
}
else
#endif
{
len = skb->len;
if (len < ETH_ZLEN) {
memset((void *)p->xmit_cbuffs[p->xmit_count], 0,
ETH_ZLEN);
len = ETH_ZLEN;
}
skb_copy_from_linear_data(skb, (void *)p->xmit_cbuffs[p->xmit_count], skb->len);
#if (NUM_XMIT_BUFFS == 1)
# ifdef NO_NOPCOMMANDS
#ifdef DEBUG
if(p->scb->cus & CU_ACTIVE)
{
printk("%s: Hmmm .. CU is still running and we wanna send a new packet.\n",dev->name);
printk("%s: stat: %04x %04x\n",dev->name,p->scb->cus,swab16(p->xmit_cmds[0]->cmd_status));
}
#endif
p->xmit_buffs[0]->size = swab16(TBD_LAST | len);
for(i=0;i<16;i++)
{
p->xmit_cmds[0]->cmd_status = 0;
WAIT_4_SCB_CMD();
if( (p->scb->cus & CU_STATUS) == CU_SUSPEND)
p->scb->cmd_cuc = CUC_RESUME;
else
{
p->scb->cbl_offset = make16(p->xmit_cmds[0]);
p->scb->cmd_cuc = CUC_START;
}
sun3_attn586();
if(!i)
dev_kfree_skb(skb);
WAIT_4_SCB_CMD();
if( (p->scb->cus & CU_ACTIVE))
break;
if(p->xmit_cmds[0]->cmd_status)
break;
if(i==15)
printk("%s: Can't start transmit-command.\n",dev->name);
}
# else
next_nop = (p->nop_point + 1) & 0x1;
p->xmit_buffs[0]->size = swab16(TBD_LAST | len);
p->xmit_cmds[0]->cmd_link = p->nop_cmds[next_nop]->cmd_link
= make16((p->nop_cmds[next_nop]));
p->xmit_cmds[0]->cmd_status = p->nop_cmds[next_nop]->cmd_status = 0;
p->nop_cmds[p->nop_point]->cmd_link = make16((p->xmit_cmds[0]));
p->nop_point = next_nop;
dev_kfree_skb(skb);
# endif
#else
p->xmit_buffs[p->xmit_count]->size = swab16(TBD_LAST | len);
if( (next_nop = p->xmit_count + 1) == NUM_XMIT_BUFFS )
next_nop = 0;
p->xmit_cmds[p->xmit_count]->cmd_status = 0;
p->nop_cmds[next_nop]->cmd_link = make16((p->nop_cmds[next_nop]));
p->nop_cmds[next_nop]->cmd_status = 0;
p->nop_cmds[p->xmit_count]->cmd_link = make16((p->xmit_cmds[p->xmit_count]));
p->xmit_count = next_nop;
{
unsigned long flags;
local_irq_save(flags);
if(p->xmit_count != p->xmit_last)
netif_wake_queue(dev);
p->lock = 0;
local_irq_restore(flags);
}
dev_kfree_skb(skb);
#endif
}
return NETDEV_TX_OK;
}
static struct net_device_stats *sun3_82586_get_stats(struct net_device *dev)
{
struct priv *p = netdev_priv(dev);
unsigned short crc,aln,rsc,ovrn;
crc = swab16(p->scb->crc_errs);
p->scb->crc_errs = 0;
aln = swab16(p->scb->aln_errs);
p->scb->aln_errs = 0;
rsc = swab16(p->scb->rsc_errs);
p->scb->rsc_errs = 0;
ovrn = swab16(p->scb->ovrn_errs);
p->scb->ovrn_errs = 0;
dev->stats.rx_crc_errors += crc;
dev->stats.rx_fifo_errors += ovrn;
dev->stats.rx_frame_errors += aln;
dev->stats.rx_dropped += rsc;
return &dev->stats;
}
static void set_multicast_list(struct net_device *dev)
{
netif_stop_queue(dev);
sun3_disint();
alloc586(dev);
init586(dev);
startrecv586(dev);
sun3_enaint();
netif_wake_queue(dev);
}
int init_module(void)
{
dev_sun3_82586 = sun3_82586_probe(-1);
if (IS_ERR(dev_sun3_82586))
return PTR_ERR(dev_sun3_82586);
return 0;
}
void cleanup_module(void)
{
unsigned long ioaddr = dev_sun3_82586->base_addr;
unregister_netdev(dev_sun3_82586);
release_region(ioaddr, SUN3_82586_TOTAL_SIZE);
iounmap((void *)ioaddr);
free_netdev(dev_sun3_82586);
}
