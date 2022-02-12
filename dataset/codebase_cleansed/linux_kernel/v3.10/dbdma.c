static dbdev_tab_t *find_dbdev_id(u32 id)
{
int i;
dbdev_tab_t *p;
for (i = 0; i < DBDEV_TAB_SIZE; ++i) {
p = &dbdev_tab[i];
if (p->dev_id == id)
return p;
}
return NULL;
}
void *au1xxx_ddma_get_nextptr_virt(au1x_ddma_desc_t *dp)
{
return phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
}
u32 au1xxx_ddma_add_device(dbdev_tab_t *dev)
{
u32 ret = 0;
dbdev_tab_t *p;
static u16 new_id = 0x1000;
p = find_dbdev_id(~0);
if (NULL != p) {
memcpy(p, dev, sizeof(dbdev_tab_t));
p->dev_id = DSCR_DEV2CUSTOM_ID(new_id, dev->dev_id);
ret = p->dev_id;
new_id++;
#if 0
printk(KERN_DEBUG "add_device: id:%x flags:%x padd:%x\n",
p->dev_id, p->dev_flags, p->dev_physaddr);
#endif
}
return ret;
}
void au1xxx_ddma_del_device(u32 devid)
{
dbdev_tab_t *p = find_dbdev_id(devid);
if (p != NULL) {
memset(p, 0, sizeof(dbdev_tab_t));
p->dev_id = ~0;
}
}
u32 au1xxx_dbdma_chan_alloc(u32 srcid, u32 destid,
void (*callback)(int, void *), void *callparam)
{
unsigned long flags;
u32 used, chan;
u32 dcp;
int i;
dbdev_tab_t *stp, *dtp;
chan_tab_t *ctp;
au1x_dma_chan_t *cp;
if (!dbdma_initialized)
return 0;
stp = find_dbdev_id(srcid);
if (stp == NULL)
return 0;
dtp = find_dbdev_id(destid);
if (dtp == NULL)
return 0;
used = 0;
spin_lock_irqsave(&au1xxx_dbdma_spin_lock, flags);
if (!(stp->dev_flags & DEV_FLAGS_INUSE) ||
(stp->dev_flags & DEV_FLAGS_ANYUSE)) {
stp->dev_flags |= DEV_FLAGS_INUSE;
if (!(dtp->dev_flags & DEV_FLAGS_INUSE) ||
(dtp->dev_flags & DEV_FLAGS_ANYUSE)) {
dtp->dev_flags |= DEV_FLAGS_INUSE;
} else {
stp->dev_flags &= ~DEV_FLAGS_INUSE;
used++;
}
} else
used++;
spin_unlock_irqrestore(&au1xxx_dbdma_spin_lock, flags);
if (used)
return 0;
ctp = NULL;
chan = 0;
spin_lock_irqsave(&au1xxx_dbdma_spin_lock, flags);
for (i = 0; i < NUM_DBDMA_CHANS; i++)
if (chan_tab_ptr[i] == NULL) {
ctp = kmalloc(sizeof(chan_tab_t), GFP_ATOMIC);
chan_tab_ptr[i] = ctp;
break;
}
spin_unlock_irqrestore(&au1xxx_dbdma_spin_lock, flags);
if (ctp != NULL) {
memset(ctp, 0, sizeof(chan_tab_t));
ctp->chan_index = chan = i;
dcp = KSEG1ADDR(AU1550_DBDMA_PHYS_ADDR);
dcp += (0x0100 * chan);
ctp->chan_ptr = (au1x_dma_chan_t *)dcp;
cp = (au1x_dma_chan_t *)dcp;
ctp->chan_src = stp;
ctp->chan_dest = dtp;
ctp->chan_callback = callback;
ctp->chan_callparam = callparam;
i = 0;
if (stp->dev_intlevel)
i |= DDMA_CFG_SED;
if (stp->dev_intpolarity)
i |= DDMA_CFG_SP;
if (dtp->dev_intlevel)
i |= DDMA_CFG_DED;
if (dtp->dev_intpolarity)
i |= DDMA_CFG_DP;
if ((stp->dev_flags & DEV_FLAGS_SYNC) ||
(dtp->dev_flags & DEV_FLAGS_SYNC))
i |= DDMA_CFG_SYNC;
cp->ddma_cfg = i;
au_sync();
return (u32)(&chan_tab_ptr[chan]);
}
stp->dev_flags &= ~DEV_FLAGS_INUSE;
dtp->dev_flags &= ~DEV_FLAGS_INUSE;
return 0;
}
u32 au1xxx_dbdma_set_devwidth(u32 chanid, int bits)
{
u32 rv;
chan_tab_t *ctp;
dbdev_tab_t *stp, *dtp;
ctp = *((chan_tab_t **)chanid);
stp = ctp->chan_src;
dtp = ctp->chan_dest;
rv = 0;
if (stp->dev_flags & DEV_FLAGS_IN) {
rv = stp->dev_devwidth;
stp->dev_devwidth = bits;
}
if (dtp->dev_flags & DEV_FLAGS_OUT) {
rv = dtp->dev_devwidth;
dtp->dev_devwidth = bits;
}
return rv;
}
u32 au1xxx_dbdma_ring_alloc(u32 chanid, int entries)
{
int i;
u32 desc_base, srcid, destid;
u32 cmd0, cmd1, src1, dest1;
u32 src0, dest0;
chan_tab_t *ctp;
dbdev_tab_t *stp, *dtp;
au1x_ddma_desc_t *dp;
ctp = *((chan_tab_t **)chanid);
stp = ctp->chan_src;
dtp = ctp->chan_dest;
desc_base = (u32)kmalloc(entries * sizeof(au1x_ddma_desc_t),
GFP_KERNEL|GFP_DMA);
if (desc_base == 0)
return 0;
if (desc_base & 0x1f) {
kfree((const void *)desc_base);
i = entries * sizeof(au1x_ddma_desc_t);
i += (sizeof(au1x_ddma_desc_t) - 1);
desc_base = (u32)kmalloc(i, GFP_KERNEL|GFP_DMA);
if (desc_base == 0)
return 0;
ctp->cdb_membase = desc_base;
desc_base = ALIGN_ADDR(desc_base, sizeof(au1x_ddma_desc_t));
} else
ctp->cdb_membase = desc_base;
dp = (au1x_ddma_desc_t *)desc_base;
ctp->chan_desc_base = dp;
srcid = stp->dev_id;
destid = dtp->dev_id;
cmd0 = cmd1 = src1 = dest1 = 0;
src0 = dest0 = 0;
cmd0 |= DSCR_CMD0_SID(srcid);
cmd0 |= DSCR_CMD0_DID(destid);
cmd0 |= DSCR_CMD0_IE | DSCR_CMD0_CV;
cmd0 |= DSCR_CMD0_ST(DSCR_CMD0_ST_NOCHANGE);
if (((DSCR_CUSTOM2DEV_ID(srcid) == DSCR_CMD0_THROTTLE) ||
(DSCR_CUSTOM2DEV_ID(srcid) == DSCR_CMD0_ALWAYS)) &&
((DSCR_CUSTOM2DEV_ID(destid) == DSCR_CMD0_THROTTLE) ||
(DSCR_CUSTOM2DEV_ID(destid) == DSCR_CMD0_ALWAYS)))
cmd0 |= DSCR_CMD0_MEM;
switch (stp->dev_devwidth) {
case 8:
cmd0 |= DSCR_CMD0_SW(DSCR_CMD0_BYTE);
break;
case 16:
cmd0 |= DSCR_CMD0_SW(DSCR_CMD0_HALFWORD);
break;
case 32:
default:
cmd0 |= DSCR_CMD0_SW(DSCR_CMD0_WORD);
break;
}
switch (dtp->dev_devwidth) {
case 8:
cmd0 |= DSCR_CMD0_DW(DSCR_CMD0_BYTE);
break;
case 16:
cmd0 |= DSCR_CMD0_DW(DSCR_CMD0_HALFWORD);
break;
case 32:
default:
cmd0 |= DSCR_CMD0_DW(DSCR_CMD0_WORD);
break;
}
if (stp->dev_flags & DEV_FLAGS_IN)
cmd0 |= DSCR_CMD0_SN;
if (dtp->dev_flags & DEV_FLAGS_OUT)
cmd0 |= DSCR_CMD0_DN;
switch (stp->dev_tsize) {
case 1:
src1 |= DSCR_SRC1_STS(DSCR_xTS_SIZE1);
break;
case 2:
src1 |= DSCR_SRC1_STS(DSCR_xTS_SIZE2);
break;
case 4:
src1 |= DSCR_SRC1_STS(DSCR_xTS_SIZE4);
break;
case 8:
default:
src1 |= DSCR_SRC1_STS(DSCR_xTS_SIZE8);
break;
}
if (stp->dev_flags & DEV_FLAGS_IN) {
if (stp->dev_flags & DEV_FLAGS_BURSTABLE)
src1 |= DSCR_SRC1_SAM(DSCR_xAM_BURST);
else
src1 |= DSCR_SRC1_SAM(DSCR_xAM_STATIC);
}
if (stp->dev_physaddr)
src0 = stp->dev_physaddr;
switch (dtp->dev_tsize) {
case 1:
dest1 |= DSCR_DEST1_DTS(DSCR_xTS_SIZE1);
break;
case 2:
dest1 |= DSCR_DEST1_DTS(DSCR_xTS_SIZE2);
break;
case 4:
dest1 |= DSCR_DEST1_DTS(DSCR_xTS_SIZE4);
break;
case 8:
default:
dest1 |= DSCR_DEST1_DTS(DSCR_xTS_SIZE8);
break;
}
if (dtp->dev_flags & DEV_FLAGS_OUT) {
if (dtp->dev_flags & DEV_FLAGS_BURSTABLE)
dest1 |= DSCR_DEST1_DAM(DSCR_xAM_BURST);
else
dest1 |= DSCR_DEST1_DAM(DSCR_xAM_STATIC);
}
if (dtp->dev_physaddr)
dest0 = dtp->dev_physaddr;
#if 0
printk(KERN_DEBUG "did:%x sid:%x cmd0:%x cmd1:%x source0:%x "
"source1:%x dest0:%x dest1:%x\n",
dtp->dev_id, stp->dev_id, cmd0, cmd1, src0,
src1, dest0, dest1);
#endif
for (i = 0; i < entries; i++) {
dp->dscr_cmd0 = cmd0;
dp->dscr_cmd1 = cmd1;
dp->dscr_source0 = src0;
dp->dscr_source1 = src1;
dp->dscr_dest0 = dest0;
dp->dscr_dest1 = dest1;
dp->dscr_stat = 0;
dp->sw_context = 0;
dp->sw_status = 0;
dp->dscr_nxtptr = DSCR_NXTPTR(virt_to_phys(dp + 1));
dp++;
}
dp--;
dp->dscr_nxtptr = DSCR_NXTPTR(virt_to_phys(ctp->chan_desc_base));
ctp->get_ptr = ctp->put_ptr = ctp->cur_ptr = ctp->chan_desc_base;
return (u32)ctp->chan_desc_base;
}
u32 au1xxx_dbdma_put_source(u32 chanid, dma_addr_t buf, int nbytes, u32 flags)
{
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
ctp = *(chan_tab_t **)chanid;
dp = ctp->put_ptr;
if (dp->dscr_cmd0 & DSCR_CMD0_V)
return 0;
dp->dscr_source0 = buf & ~0UL;
dp->dscr_cmd1 = nbytes;
if (flags & DDMA_FLAGS_IE)
dp->dscr_cmd0 |= DSCR_CMD0_IE;
if (flags & DDMA_FLAGS_NOIE)
dp->dscr_cmd0 &= ~DSCR_CMD0_IE;
dma_cache_wback_inv((unsigned long)buf, nbytes);
dp->dscr_cmd0 |= DSCR_CMD0_V;
au_sync();
dma_cache_wback_inv((unsigned long)dp, sizeof(*dp));
ctp->chan_ptr->ddma_dbell = 0;
ctp->put_ptr = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
return nbytes;
}
u32 au1xxx_dbdma_put_dest(u32 chanid, dma_addr_t buf, int nbytes, u32 flags)
{
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
ctp = *((chan_tab_t **)chanid);
dp = ctp->put_ptr;
if (dp->dscr_cmd0 & DSCR_CMD0_V)
return 0;
if (flags & DDMA_FLAGS_IE)
dp->dscr_cmd0 |= DSCR_CMD0_IE;
if (flags & DDMA_FLAGS_NOIE)
dp->dscr_cmd0 &= ~DSCR_CMD0_IE;
dp->dscr_dest0 = buf & ~0UL;
dp->dscr_cmd1 = nbytes;
#if 0
printk(KERN_DEBUG "cmd0:%x cmd1:%x source0:%x source1:%x dest0:%x dest1:%x\n",
dp->dscr_cmd0, dp->dscr_cmd1, dp->dscr_source0,
dp->dscr_source1, dp->dscr_dest0, dp->dscr_dest1);
#endif
dma_cache_inv((unsigned long)buf, nbytes);
dp->dscr_cmd0 |= DSCR_CMD0_V;
au_sync();
dma_cache_wback_inv((unsigned long)dp, sizeof(*dp));
ctp->chan_ptr->ddma_dbell = 0;
ctp->put_ptr = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
return nbytes;
}
u32 au1xxx_dbdma_get_dest(u32 chanid, void **buf, int *nbytes)
{
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
u32 rv;
ctp = *((chan_tab_t **)chanid);
dp = ctp->get_ptr;
if (dp->dscr_cmd0 & DSCR_CMD0_V)
return 0;
*buf = (void *)(phys_to_virt(dp->dscr_dest0));
*nbytes = dp->dscr_cmd1;
rv = dp->dscr_stat;
ctp->get_ptr = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
return rv;
}
void au1xxx_dbdma_stop(u32 chanid)
{
chan_tab_t *ctp;
au1x_dma_chan_t *cp;
int halt_timeout = 0;
ctp = *((chan_tab_t **)chanid);
cp = ctp->chan_ptr;
cp->ddma_cfg &= ~DDMA_CFG_EN;
au_sync();
while (!(cp->ddma_stat & DDMA_STAT_H)) {
udelay(1);
halt_timeout++;
if (halt_timeout > 100) {
printk(KERN_WARNING "warning: DMA channel won't halt\n");
break;
}
}
cp->ddma_stat |= (DDMA_STAT_DB | DDMA_STAT_V);
au_sync();
}
void au1xxx_dbdma_start(u32 chanid)
{
chan_tab_t *ctp;
au1x_dma_chan_t *cp;
ctp = *((chan_tab_t **)chanid);
cp = ctp->chan_ptr;
cp->ddma_desptr = virt_to_phys(ctp->cur_ptr);
cp->ddma_cfg |= DDMA_CFG_EN;
au_sync();
cp->ddma_dbell = 0;
au_sync();
}
void au1xxx_dbdma_reset(u32 chanid)
{
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
au1xxx_dbdma_stop(chanid);
ctp = *((chan_tab_t **)chanid);
ctp->get_ptr = ctp->put_ptr = ctp->cur_ptr = ctp->chan_desc_base;
dp = ctp->chan_desc_base;
do {
dp->dscr_cmd0 &= ~DSCR_CMD0_V;
dp->sw_status = 0;
dp = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
} while (dp != ctp->chan_desc_base);
}
u32 au1xxx_get_dma_residue(u32 chanid)
{
chan_tab_t *ctp;
au1x_dma_chan_t *cp;
u32 rv;
ctp = *((chan_tab_t **)chanid);
cp = ctp->chan_ptr;
rv = cp->ddma_bytecnt;
au_sync();
return rv;
}
void au1xxx_dbdma_chan_free(u32 chanid)
{
chan_tab_t *ctp;
dbdev_tab_t *stp, *dtp;
ctp = *((chan_tab_t **)chanid);
stp = ctp->chan_src;
dtp = ctp->chan_dest;
au1xxx_dbdma_stop(chanid);
kfree((void *)ctp->cdb_membase);
stp->dev_flags &= ~DEV_FLAGS_INUSE;
dtp->dev_flags &= ~DEV_FLAGS_INUSE;
chan_tab_ptr[ctp->chan_index] = NULL;
kfree(ctp);
}
static irqreturn_t dbdma_interrupt(int irq, void *dev_id)
{
u32 intstat;
u32 chan_index;
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
au1x_dma_chan_t *cp;
intstat = dbdma_gptr->ddma_intstat;
au_sync();
chan_index = __ffs(intstat);
ctp = chan_tab_ptr[chan_index];
cp = ctp->chan_ptr;
dp = ctp->cur_ptr;
cp->ddma_irq = 0;
au_sync();
if (ctp->chan_callback)
ctp->chan_callback(irq, ctp->chan_callparam);
ctp->cur_ptr = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
return IRQ_RETVAL(1);
}
void au1xxx_dbdma_dump(u32 chanid)
{
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
dbdev_tab_t *stp, *dtp;
au1x_dma_chan_t *cp;
u32 i = 0;
ctp = *((chan_tab_t **)chanid);
stp = ctp->chan_src;
dtp = ctp->chan_dest;
cp = ctp->chan_ptr;
printk(KERN_DEBUG "Chan %x, stp %x (dev %d) dtp %x (dev %d)\n",
(u32)ctp, (u32)stp, stp - dbdev_tab, (u32)dtp,
dtp - dbdev_tab);
printk(KERN_DEBUG "desc base %x, get %x, put %x, cur %x\n",
(u32)(ctp->chan_desc_base), (u32)(ctp->get_ptr),
(u32)(ctp->put_ptr), (u32)(ctp->cur_ptr));
printk(KERN_DEBUG "dbdma chan %x\n", (u32)cp);
printk(KERN_DEBUG "cfg %08x, desptr %08x, statptr %08x\n",
cp->ddma_cfg, cp->ddma_desptr, cp->ddma_statptr);
printk(KERN_DEBUG "dbell %08x, irq %08x, stat %08x, bytecnt %08x\n",
cp->ddma_dbell, cp->ddma_irq, cp->ddma_stat,
cp->ddma_bytecnt);
dp = ctp->chan_desc_base;
do {
printk(KERN_DEBUG "Dp[%d]= %08x, cmd0 %08x, cmd1 %08x\n",
i++, (u32)dp, dp->dscr_cmd0, dp->dscr_cmd1);
printk(KERN_DEBUG "src0 %08x, src1 %08x, dest0 %08x, dest1 %08x\n",
dp->dscr_source0, dp->dscr_source1,
dp->dscr_dest0, dp->dscr_dest1);
printk(KERN_DEBUG "stat %08x, nxtptr %08x\n",
dp->dscr_stat, dp->dscr_nxtptr);
dp = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
} while (dp != ctp->chan_desc_base);
}
u32 au1xxx_dbdma_put_dscr(u32 chanid, au1x_ddma_desc_t *dscr)
{
chan_tab_t *ctp;
au1x_ddma_desc_t *dp;
u32 nbytes = 0;
ctp = *((chan_tab_t **)chanid);
dp = ctp->put_ptr;
if (dp->dscr_cmd0 & DSCR_CMD0_V)
return 0;
dp->dscr_dest0 = dscr->dscr_dest0;
dp->dscr_source0 = dscr->dscr_source0;
dp->dscr_dest1 = dscr->dscr_dest1;
dp->dscr_source1 = dscr->dscr_source1;
dp->dscr_cmd1 = dscr->dscr_cmd1;
nbytes = dscr->dscr_cmd1;
dp->dscr_cmd0 &= ~DSCR_CMD0_IE;
dp->dscr_cmd0 |= dscr->dscr_cmd0 | DSCR_CMD0_V;
ctp->chan_ptr->ddma_dbell = 0;
ctp->put_ptr = phys_to_virt(DSCR_GET_NXTPTR(dp->dscr_nxtptr));
return nbytes;
}
static int alchemy_dbdma_suspend(void)
{
int i;
void __iomem *addr;
addr = (void __iomem *)KSEG1ADDR(AU1550_DBDMA_CONF_PHYS_ADDR);
alchemy_dbdma_pm_data[0][0] = __raw_readl(addr + 0x00);
alchemy_dbdma_pm_data[0][1] = __raw_readl(addr + 0x04);
alchemy_dbdma_pm_data[0][2] = __raw_readl(addr + 0x08);
alchemy_dbdma_pm_data[0][3] = __raw_readl(addr + 0x0c);
addr = (void __iomem *)KSEG1ADDR(AU1550_DBDMA_PHYS_ADDR);
for (i = 1; i <= NUM_DBDMA_CHANS; i++) {
alchemy_dbdma_pm_data[i][0] = __raw_readl(addr + 0x00);
alchemy_dbdma_pm_data[i][1] = __raw_readl(addr + 0x04);
alchemy_dbdma_pm_data[i][2] = __raw_readl(addr + 0x08);
alchemy_dbdma_pm_data[i][3] = __raw_readl(addr + 0x0c);
alchemy_dbdma_pm_data[i][4] = __raw_readl(addr + 0x10);
alchemy_dbdma_pm_data[i][5] = __raw_readl(addr + 0x14);
__raw_writel(alchemy_dbdma_pm_data[i][0] & ~1, addr + 0x00);
wmb();
while (!(__raw_readl(addr + 0x14) & 1))
wmb();
addr += 0x100;
}
addr = (void __iomem *)KSEG1ADDR(AU1550_DBDMA_CONF_PHYS_ADDR);
__raw_writel(0, addr + 0x0c);
wmb();
return 0;
}
static void alchemy_dbdma_resume(void)
{
int i;
void __iomem *addr;
addr = (void __iomem *)KSEG1ADDR(AU1550_DBDMA_CONF_PHYS_ADDR);
__raw_writel(alchemy_dbdma_pm_data[0][0], addr + 0x00);
__raw_writel(alchemy_dbdma_pm_data[0][1], addr + 0x04);
__raw_writel(alchemy_dbdma_pm_data[0][2], addr + 0x08);
__raw_writel(alchemy_dbdma_pm_data[0][3], addr + 0x0c);
addr = (void __iomem *)KSEG1ADDR(AU1550_DBDMA_PHYS_ADDR);
for (i = 1; i <= NUM_DBDMA_CHANS; i++) {
__raw_writel(alchemy_dbdma_pm_data[i][0], addr + 0x00);
__raw_writel(alchemy_dbdma_pm_data[i][1], addr + 0x04);
__raw_writel(alchemy_dbdma_pm_data[i][2], addr + 0x08);
__raw_writel(alchemy_dbdma_pm_data[i][3], addr + 0x0c);
__raw_writel(alchemy_dbdma_pm_data[i][4], addr + 0x10);
__raw_writel(alchemy_dbdma_pm_data[i][5], addr + 0x14);
wmb();
addr += 0x100;
}
}
static int __init dbdma_setup(unsigned int irq, dbdev_tab_t *idtable)
{
int ret;
dbdev_tab = kzalloc(sizeof(dbdev_tab_t) * DBDEV_TAB_SIZE, GFP_KERNEL);
if (!dbdev_tab)
return -ENOMEM;
memcpy(dbdev_tab, idtable, 32 * sizeof(dbdev_tab_t));
for (ret = 32; ret < DBDEV_TAB_SIZE; ret++)
dbdev_tab[ret].dev_id = ~0;
dbdma_gptr->ddma_config = 0;
dbdma_gptr->ddma_throttle = 0;
dbdma_gptr->ddma_inten = 0xffff;
au_sync();
ret = request_irq(irq, dbdma_interrupt, 0, "dbdma", (void *)dbdma_gptr);
if (ret)
printk(KERN_ERR "Cannot grab DBDMA interrupt!\n");
else {
dbdma_initialized = 1;
register_syscore_ops(&alchemy_dbdma_syscore_ops);
}
return ret;
}
static int __init alchemy_dbdma_init(void)
{
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1550:
return dbdma_setup(AU1550_DDMA_INT, au1550_dbdev_tab);
case ALCHEMY_CPU_AU1200:
return dbdma_setup(AU1200_DDMA_INT, au1200_dbdev_tab);
case ALCHEMY_CPU_AU1300:
return dbdma_setup(AU1300_DDMA_INT, au1300_dbdev_tab);
}
return 0;
}
