struct macio_chip *macio_find(struct device_node *child, int type)
{
while(child) {
int i;
for (i=0; i < MAX_MACIO_CHIPS && macio_chips[i].of_node; i++)
if (child == macio_chips[i].of_node &&
(!type || macio_chips[i].type == type))
return &macio_chips[i];
child = child->parent;
}
return NULL;
}
static inline int simple_feature_tweak(struct device_node *node, int type,
int reg, u32 mask, int value)
{
struct macio_chip* macio;
unsigned long flags;
macio = macio_find(node, type);
if (!macio)
return -ENODEV;
LOCK(flags);
if (value)
MACIO_BIS(reg, mask);
else
MACIO_BIC(reg, mask);
(void)MACIO_IN32(reg);
UNLOCK(flags);
return 0;
}
static long ohare_htw_scc_enable(struct device_node *node, long param,
long value)
{
struct macio_chip* macio;
unsigned long chan_mask;
unsigned long fcr;
unsigned long flags;
int htw, trans;
unsigned long rmask;
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
if (!strcmp(node->name, "ch-a"))
chan_mask = MACIO_FLAG_SCCA_ON;
else if (!strcmp(node->name, "ch-b"))
chan_mask = MACIO_FLAG_SCCB_ON;
else
return -ENODEV;
htw = (macio->type == macio_heathrow || macio->type == macio_paddington
|| macio->type == macio_gatwick);
trans = (pmac_mb.model_id != PMAC_TYPE_YOSEMITE &&
pmac_mb.model_id != PMAC_TYPE_YIKES);
if (value) {
#ifdef CONFIG_ADB_PMU
if ((param & 0xfff) == PMAC_SCC_IRDA)
pmu_enable_irled(1);
#endif
LOCK(flags);
fcr = MACIO_IN32(OHARE_FCR);
if (!(fcr & OH_SCC_ENABLE)) {
fcr |= OH_SCC_ENABLE;
if (htw) {
if (trans)
fcr &= ~HRW_SCC_TRANS_EN_N;
MACIO_OUT32(OHARE_FCR, fcr);
fcr |= (rmask = HRW_RESET_SCC);
MACIO_OUT32(OHARE_FCR, fcr);
} else {
fcr |= (rmask = OH_SCC_RESET);
MACIO_OUT32(OHARE_FCR, fcr);
}
UNLOCK(flags);
(void)MACIO_IN32(OHARE_FCR);
mdelay(15);
LOCK(flags);
fcr &= ~rmask;
MACIO_OUT32(OHARE_FCR, fcr);
}
if (chan_mask & MACIO_FLAG_SCCA_ON)
fcr |= OH_SCCA_IO;
if (chan_mask & MACIO_FLAG_SCCB_ON)
fcr |= OH_SCCB_IO;
MACIO_OUT32(OHARE_FCR, fcr);
macio->flags |= chan_mask;
UNLOCK(flags);
if (param & PMAC_SCC_FLAG_XMON)
macio->flags |= MACIO_FLAG_SCC_LOCKED;
} else {
if (macio->flags & MACIO_FLAG_SCC_LOCKED)
return -EPERM;
LOCK(flags);
fcr = MACIO_IN32(OHARE_FCR);
if (chan_mask & MACIO_FLAG_SCCA_ON)
fcr &= ~OH_SCCA_IO;
if (chan_mask & MACIO_FLAG_SCCB_ON)
fcr &= ~OH_SCCB_IO;
MACIO_OUT32(OHARE_FCR, fcr);
if ((fcr & (OH_SCCA_IO | OH_SCCB_IO)) == 0) {
fcr &= ~OH_SCC_ENABLE;
if (htw && trans)
fcr |= HRW_SCC_TRANS_EN_N;
MACIO_OUT32(OHARE_FCR, fcr);
}
macio->flags &= ~(chan_mask);
UNLOCK(flags);
mdelay(10);
#ifdef CONFIG_ADB_PMU
if ((param & 0xfff) == PMAC_SCC_IRDA)
pmu_enable_irled(0);
#endif
}
return 0;
}
static long ohare_floppy_enable(struct device_node *node, long param,
long value)
{
return simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_FLOPPY_ENABLE, value);
}
static long ohare_mesh_enable(struct device_node *node, long param, long value)
{
return simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_MESH_ENABLE, value);
}
static long ohare_ide_enable(struct device_node *node, long param, long value)
{
switch(param) {
case 0:
if (value)
simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_IOBUS_ENABLE, 1);
return simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_IDE0_ENABLE, value);
case 1:
return simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_BAY_IDE_ENABLE, value);
default:
return -ENODEV;
}
}
static long ohare_ide_reset(struct device_node *node, long param, long value)
{
switch(param) {
case 0:
return simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_IDE0_RESET_N, !value);
case 1:
return simple_feature_tweak(node, macio_ohare,
OHARE_FCR, OH_IDE1_RESET_N, !value);
default:
return -ENODEV;
}
}
static long ohare_sleep_state(struct device_node *node, long param, long value)
{
struct macio_chip* macio = &macio_chips[0];
if ((pmac_mb.board_flags & PMAC_MB_CAN_SLEEP) == 0)
return -EPERM;
if (value == 1) {
MACIO_BIC(OHARE_FCR, OH_IOBUS_ENABLE);
} else if (value == 0) {
MACIO_BIS(OHARE_FCR, OH_IOBUS_ENABLE);
}
return 0;
}
static long heathrow_modem_enable(struct device_node *node, long param,
long value)
{
struct macio_chip* macio;
u8 gpio;
unsigned long flags;
macio = macio_find(node, macio_unknown);
if (!macio)
return -ENODEV;
gpio = MACIO_IN8(HRW_GPIO_MODEM_RESET) & ~1;
if (!value) {
LOCK(flags);
MACIO_OUT8(HRW_GPIO_MODEM_RESET, gpio);
UNLOCK(flags);
(void)MACIO_IN8(HRW_GPIO_MODEM_RESET);
mdelay(250);
}
if (pmac_mb.model_id != PMAC_TYPE_YOSEMITE &&
pmac_mb.model_id != PMAC_TYPE_YIKES) {
LOCK(flags);
if (value)
MACIO_BIC(HEATHROW_FCR, HRW_SCC_TRANS_EN_N);
else
MACIO_BIS(HEATHROW_FCR, HRW_SCC_TRANS_EN_N);
UNLOCK(flags);
(void)MACIO_IN32(HEATHROW_FCR);
mdelay(250);
}
if (value) {
LOCK(flags);
MACIO_OUT8(HRW_GPIO_MODEM_RESET, gpio | 1);
(void)MACIO_IN8(HRW_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250); LOCK(flags);
MACIO_OUT8(HRW_GPIO_MODEM_RESET, gpio);
(void)MACIO_IN8(HRW_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250); LOCK(flags);
MACIO_OUT8(HRW_GPIO_MODEM_RESET, gpio | 1);
(void)MACIO_IN8(HRW_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250);
}
return 0;
}
static long heathrow_floppy_enable(struct device_node *node, long param,
long value)
{
return simple_feature_tweak(node, macio_unknown,
HEATHROW_FCR,
HRW_SWIM_ENABLE|HRW_BAY_FLOPPY_ENABLE,
value);
}
static long heathrow_mesh_enable(struct device_node *node, long param,
long value)
{
struct macio_chip* macio;
unsigned long flags;
macio = macio_find(node, macio_unknown);
if (!macio)
return -ENODEV;
LOCK(flags);
if (value)
MACIO_BIS(HEATHROW_FCR, HRW_MESH_ENABLE);
else
MACIO_BIC(HEATHROW_FCR, HRW_MESH_ENABLE);
(void)MACIO_IN32(HEATHROW_FCR);
udelay(10);
if (value)
MACIO_BIC(HEATHROW_MBCR, 0x04000000);
else
MACIO_BIS(HEATHROW_MBCR, 0x04000000);
(void)MACIO_IN32(HEATHROW_MBCR);
udelay(10);
UNLOCK(flags);
return 0;
}
static long heathrow_ide_enable(struct device_node *node, long param,
long value)
{
switch(param) {
case 0:
return simple_feature_tweak(node, macio_unknown,
HEATHROW_FCR, HRW_IDE0_ENABLE, value);
case 1:
return simple_feature_tweak(node, macio_unknown,
HEATHROW_FCR, HRW_BAY_IDE_ENABLE, value);
default:
return -ENODEV;
}
}
static long heathrow_ide_reset(struct device_node *node, long param,
long value)
{
switch(param) {
case 0:
return simple_feature_tweak(node, macio_unknown,
HEATHROW_FCR, HRW_IDE0_RESET_N, !value);
case 1:
return simple_feature_tweak(node, macio_unknown,
HEATHROW_FCR, HRW_IDE1_RESET_N, !value);
default:
return -ENODEV;
}
}
static long heathrow_bmac_enable(struct device_node *node, long param,
long value)
{
struct macio_chip* macio;
unsigned long flags;
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
if (value) {
LOCK(flags);
MACIO_BIS(HEATHROW_FCR, HRW_BMAC_IO_ENABLE);
MACIO_BIS(HEATHROW_FCR, HRW_BMAC_RESET);
UNLOCK(flags);
(void)MACIO_IN32(HEATHROW_FCR);
mdelay(10);
LOCK(flags);
MACIO_BIC(HEATHROW_FCR, HRW_BMAC_RESET);
UNLOCK(flags);
(void)MACIO_IN32(HEATHROW_FCR);
mdelay(10);
} else {
LOCK(flags);
MACIO_BIC(HEATHROW_FCR, HRW_BMAC_IO_ENABLE);
UNLOCK(flags);
}
return 0;
}
static long heathrow_sound_enable(struct device_node *node, long param,
long value)
{
struct macio_chip* macio;
unsigned long flags;
if (pmac_mb.model_id == PMAC_TYPE_YOSEMITE ||
pmac_mb.model_id == PMAC_TYPE_YIKES)
return 0;
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
if (value) {
LOCK(flags);
MACIO_BIS(HEATHROW_FCR, HRW_SOUND_CLK_ENABLE);
MACIO_BIC(HEATHROW_FCR, HRW_SOUND_POWER_N);
UNLOCK(flags);
(void)MACIO_IN32(HEATHROW_FCR);
} else {
LOCK(flags);
MACIO_BIS(HEATHROW_FCR, HRW_SOUND_POWER_N);
MACIO_BIC(HEATHROW_FCR, HRW_SOUND_CLK_ENABLE);
UNLOCK(flags);
}
return 0;
}
static void dbdma_save(struct macio_chip *macio, struct dbdma_regs *save)
{
int i;
for (i = 0; i < 13; i++) {
volatile struct dbdma_regs __iomem * chan = (void __iomem *)
(macio->base + ((0x8000+i*0x100)>>2));
save[i].cmdptr_hi = in_le32(&chan->cmdptr_hi);
save[i].cmdptr = in_le32(&chan->cmdptr);
save[i].intr_sel = in_le32(&chan->intr_sel);
save[i].br_sel = in_le32(&chan->br_sel);
save[i].wait_sel = in_le32(&chan->wait_sel);
}
}
static void dbdma_restore(struct macio_chip *macio, struct dbdma_regs *save)
{
int i;
for (i = 0; i < 13; i++) {
volatile struct dbdma_regs __iomem * chan = (void __iomem *)
(macio->base + ((0x8000+i*0x100)>>2));
out_le32(&chan->control, (ACTIVE|DEAD|WAKE|FLUSH|PAUSE|RUN)<<16);
while (in_le32(&chan->status) & ACTIVE)
mb();
out_le32(&chan->cmdptr_hi, save[i].cmdptr_hi);
out_le32(&chan->cmdptr, save[i].cmdptr);
out_le32(&chan->intr_sel, save[i].intr_sel);
out_le32(&chan->br_sel, save[i].br_sel);
out_le32(&chan->wait_sel, save[i].wait_sel);
}
}
static void heathrow_sleep(struct macio_chip *macio, int secondary)
{
if (secondary) {
dbdma_save(macio, save_alt_dbdma);
save_fcr[2] = MACIO_IN32(0x38);
save_fcr[3] = MACIO_IN32(0x3c);
} else {
dbdma_save(macio, save_dbdma);
save_fcr[0] = MACIO_IN32(0x38);
save_fcr[1] = MACIO_IN32(0x3c);
save_mbcr = MACIO_IN32(0x34);
MACIO_BIS(HEATHROW_FCR, HRW_SOUND_POWER_N);
MACIO_BIC(HEATHROW_FCR, HRW_SOUND_CLK_ENABLE);
MACIO_BIC(HEATHROW_FCR, HRW_IOBUS_ENABLE);
MACIO_BIC(HEATHROW_FCR, HRW_IDE0_RESET_N);
MACIO_BIC(HEATHROW_FCR, HRW_BMAC_IO_ENABLE | HRW_BMAC_RESET);
}
MACIO_OUT8(HRW_GPIO_MODEM_RESET,
MACIO_IN8(HRW_GPIO_MODEM_RESET) & ~1);
MACIO_BIS(HEATHROW_FCR, HRW_SCC_TRANS_EN_N);
MACIO_BIC(HEATHROW_FCR, OH_SCCA_IO|OH_SCCB_IO|HRW_SCC_ENABLE);
(void)MACIO_IN32(HEATHROW_FCR);
}
static void heathrow_wakeup(struct macio_chip *macio, int secondary)
{
if (secondary) {
MACIO_OUT32(0x38, save_fcr[2]);
(void)MACIO_IN32(0x38);
mdelay(1);
MACIO_OUT32(0x3c, save_fcr[3]);
(void)MACIO_IN32(0x38);
mdelay(10);
dbdma_restore(macio, save_alt_dbdma);
} else {
MACIO_OUT32(0x38, save_fcr[0] | HRW_IOBUS_ENABLE);
(void)MACIO_IN32(0x38);
mdelay(1);
MACIO_OUT32(0x3c, save_fcr[1]);
(void)MACIO_IN32(0x38);
mdelay(1);
MACIO_OUT32(0x34, save_mbcr);
(void)MACIO_IN32(0x38);
mdelay(10);
dbdma_restore(macio, save_dbdma);
}
}
static long heathrow_sleep_state(struct device_node *node, long param,
long value)
{
if ((pmac_mb.board_flags & PMAC_MB_CAN_SLEEP) == 0)
return -EPERM;
if (value == 1) {
if (macio_chips[1].type == macio_gatwick)
heathrow_sleep(&macio_chips[0], 1);
heathrow_sleep(&macio_chips[0], 0);
} else if (value == 0) {
heathrow_wakeup(&macio_chips[0], 0);
if (macio_chips[1].type == macio_gatwick)
heathrow_wakeup(&macio_chips[0], 1);
}
return 0;
}
static long core99_scc_enable(struct device_node *node, long param, long value)
{
struct macio_chip* macio;
unsigned long flags;
unsigned long chan_mask;
u32 fcr;
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
if (!strcmp(node->name, "ch-a"))
chan_mask = MACIO_FLAG_SCCA_ON;
else if (!strcmp(node->name, "ch-b"))
chan_mask = MACIO_FLAG_SCCB_ON;
else
return -ENODEV;
if (value) {
int need_reset_scc = 0;
int need_reset_irda = 0;
LOCK(flags);
fcr = MACIO_IN32(KEYLARGO_FCR0);
if (!(fcr & KL0_SCC_CELL_ENABLE)) {
fcr |= KL0_SCC_CELL_ENABLE;
need_reset_scc = 1;
}
if (chan_mask & MACIO_FLAG_SCCA_ON) {
fcr |= KL0_SCCA_ENABLE;
if ((param & 0xfff) == PMAC_SCC_I2S1)
fcr &= ~KL0_SCC_A_INTF_ENABLE;
else
fcr |= KL0_SCC_A_INTF_ENABLE;
}
if (chan_mask & MACIO_FLAG_SCCB_ON) {
fcr |= KL0_SCCB_ENABLE;
if ((param & 0xfff) == PMAC_SCC_IRDA) {
fcr &= ~KL0_SCC_B_INTF_ENABLE;
fcr |= KL0_IRDA_ENABLE;
fcr |= KL0_IRDA_CLK32_ENABLE | KL0_IRDA_CLK19_ENABLE;
fcr |= KL0_IRDA_SOURCE1_SEL;
fcr &= ~(KL0_IRDA_FAST_CONNECT|KL0_IRDA_DEFAULT1|KL0_IRDA_DEFAULT0);
fcr &= ~(KL0_IRDA_SOURCE2_SEL|KL0_IRDA_HIGH_BAND);
need_reset_irda = 1;
} else
fcr |= KL0_SCC_B_INTF_ENABLE;
}
MACIO_OUT32(KEYLARGO_FCR0, fcr);
macio->flags |= chan_mask;
if (need_reset_scc) {
MACIO_BIS(KEYLARGO_FCR0, KL0_SCC_RESET);
(void)MACIO_IN32(KEYLARGO_FCR0);
UNLOCK(flags);
mdelay(15);
LOCK(flags);
MACIO_BIC(KEYLARGO_FCR0, KL0_SCC_RESET);
}
if (need_reset_irda) {
MACIO_BIS(KEYLARGO_FCR0, KL0_IRDA_RESET);
(void)MACIO_IN32(KEYLARGO_FCR0);
UNLOCK(flags);
mdelay(15);
LOCK(flags);
MACIO_BIC(KEYLARGO_FCR0, KL0_IRDA_RESET);
}
UNLOCK(flags);
if (param & PMAC_SCC_FLAG_XMON)
macio->flags |= MACIO_FLAG_SCC_LOCKED;
} else {
if (macio->flags & MACIO_FLAG_SCC_LOCKED)
return -EPERM;
LOCK(flags);
fcr = MACIO_IN32(KEYLARGO_FCR0);
if (chan_mask & MACIO_FLAG_SCCA_ON)
fcr &= ~KL0_SCCA_ENABLE;
if (chan_mask & MACIO_FLAG_SCCB_ON) {
fcr &= ~KL0_SCCB_ENABLE;
if ((param & 0xfff) == PMAC_SCC_IRDA) {
fcr &= ~KL0_IRDA_ENABLE;
fcr &= ~(KL0_IRDA_CLK32_ENABLE | KL0_IRDA_CLK19_ENABLE);
fcr &= ~(KL0_IRDA_FAST_CONNECT|KL0_IRDA_DEFAULT1|KL0_IRDA_DEFAULT0);
fcr &= ~(KL0_IRDA_SOURCE1_SEL|KL0_IRDA_SOURCE2_SEL|KL0_IRDA_HIGH_BAND);
}
}
MACIO_OUT32(KEYLARGO_FCR0, fcr);
if ((fcr & (KL0_SCCA_ENABLE | KL0_SCCB_ENABLE)) == 0) {
fcr &= ~KL0_SCC_CELL_ENABLE;
MACIO_OUT32(KEYLARGO_FCR0, fcr);
}
macio->flags &= ~(chan_mask);
UNLOCK(flags);
mdelay(10);
}
return 0;
}
static long
core99_modem_enable(struct device_node *node, long param, long value)
{
struct macio_chip* macio;
u8 gpio;
unsigned long flags;
if (node == NULL) {
if (macio_chips[0].type != macio_keylargo)
return -ENODEV;
node = macio_chips[0].of_node;
}
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
gpio = MACIO_IN8(KL_GPIO_MODEM_RESET);
gpio |= KEYLARGO_GPIO_OUTPUT_ENABLE;
gpio &= ~KEYLARGO_GPIO_OUTOUT_DATA;
if (!value) {
LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio);
UNLOCK(flags);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
mdelay(250);
}
LOCK(flags);
if (value) {
MACIO_BIC(KEYLARGO_FCR2, KL2_ALT_DATA_OUT);
UNLOCK(flags);
(void)MACIO_IN32(KEYLARGO_FCR2);
mdelay(250);
} else {
MACIO_BIS(KEYLARGO_FCR2, KL2_ALT_DATA_OUT);
UNLOCK(flags);
}
if (value) {
LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio | KEYLARGO_GPIO_OUTOUT_DATA);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250); LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250); LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio | KEYLARGO_GPIO_OUTOUT_DATA);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250);
}
return 0;
}
static long
pangea_modem_enable(struct device_node *node, long param, long value)
{
struct macio_chip* macio;
u8 gpio;
unsigned long flags;
if (node == NULL) {
if (macio_chips[0].type != macio_pangea &&
macio_chips[0].type != macio_intrepid)
return -ENODEV;
node = macio_chips[0].of_node;
}
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
gpio = MACIO_IN8(KL_GPIO_MODEM_RESET);
gpio |= KEYLARGO_GPIO_OUTPUT_ENABLE;
gpio &= ~KEYLARGO_GPIO_OUTOUT_DATA;
if (!value) {
LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio);
UNLOCK(flags);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
mdelay(250);
}
LOCK(flags);
if (value) {
MACIO_OUT8(KL_GPIO_MODEM_POWER,
KEYLARGO_GPIO_OUTPUT_ENABLE);
UNLOCK(flags);
(void)MACIO_IN32(KEYLARGO_FCR2);
mdelay(250);
} else {
MACIO_OUT8(KL_GPIO_MODEM_POWER,
KEYLARGO_GPIO_OUTPUT_ENABLE | KEYLARGO_GPIO_OUTOUT_DATA);
UNLOCK(flags);
}
if (value) {
LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio | KEYLARGO_GPIO_OUTOUT_DATA);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250); LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250); LOCK(flags);
MACIO_OUT8(KL_GPIO_MODEM_RESET, gpio | KEYLARGO_GPIO_OUTOUT_DATA);
(void)MACIO_IN8(KL_GPIO_MODEM_RESET);
UNLOCK(flags); mdelay(250);
}
return 0;
}
static long
core99_ata100_enable(struct device_node *node, long value)
{
unsigned long flags;
struct pci_dev *pdev = NULL;
u8 pbus, pid;
int rc;
if (uninorth_rev < 0x24)
return -ENODEV;
LOCK(flags);
if (value)
UN_BIS(UNI_N_CLOCK_CNTL, UNI_N_CLOCK_CNTL_ATA100);
else
UN_BIC(UNI_N_CLOCK_CNTL, UNI_N_CLOCK_CNTL_ATA100);
(void)UN_IN(UNI_N_CLOCK_CNTL);
UNLOCK(flags);
udelay(20);
if (value) {
if (pci_device_from_OF_node(node, &pbus, &pid) == 0)
pdev = pci_get_bus_and_slot(pbus, pid);
if (pdev == NULL)
return 0;
rc = pci_enable_device(pdev);
if (rc == 0)
pci_set_master(pdev);
pci_dev_put(pdev);
if (rc)
return rc;
}
return 0;
}
static long
core99_ide_enable(struct device_node *node, long param, long value)
{
switch(param) {
case 0:
return simple_feature_tweak(node, macio_unknown,
KEYLARGO_FCR1, KL1_EIDE0_ENABLE, value);
case 1:
return simple_feature_tweak(node, macio_unknown,
KEYLARGO_FCR1, KL1_EIDE1_ENABLE, value);
case 2:
return simple_feature_tweak(node, macio_unknown,
KEYLARGO_FCR1, KL1_UIDE_ENABLE, value);
case 3:
return core99_ata100_enable(node, value);
default:
return -ENODEV;
}
}
static long
core99_ide_reset(struct device_node *node, long param, long value)
{
switch(param) {
case 0:
return simple_feature_tweak(node, macio_unknown,
KEYLARGO_FCR1, KL1_EIDE0_RESET_N, !value);
case 1:
return simple_feature_tweak(node, macio_unknown,
KEYLARGO_FCR1, KL1_EIDE1_RESET_N, !value);
case 2:
return simple_feature_tweak(node, macio_unknown,
KEYLARGO_FCR1, KL1_UIDE_RESET_N, !value);
default:
return -ENODEV;
}
}
static long
core99_gmac_enable(struct device_node *node, long param, long value)
{
unsigned long flags;
LOCK(flags);
if (value)
UN_BIS(UNI_N_CLOCK_CNTL, UNI_N_CLOCK_CNTL_GMAC);
else
UN_BIC(UNI_N_CLOCK_CNTL, UNI_N_CLOCK_CNTL_GMAC);
(void)UN_IN(UNI_N_CLOCK_CNTL);
UNLOCK(flags);
udelay(20);
return 0;
}
static long
core99_gmac_phy_reset(struct device_node *node, long param, long value)
{
unsigned long flags;
struct macio_chip *macio;
macio = &macio_chips[0];
if (macio->type != macio_keylargo && macio->type != macio_pangea &&
macio->type != macio_intrepid)
return -ENODEV;
LOCK(flags);
MACIO_OUT8(KL_GPIO_ETH_PHY_RESET, KEYLARGO_GPIO_OUTPUT_ENABLE);
(void)MACIO_IN8(KL_GPIO_ETH_PHY_RESET);
UNLOCK(flags);
mdelay(10);
LOCK(flags);
MACIO_OUT8(KL_GPIO_ETH_PHY_RESET,
KEYLARGO_GPIO_OUTOUT_DATA);
UNLOCK(flags);
mdelay(10);
return 0;
}
static long
core99_sound_chip_enable(struct device_node *node, long param, long value)
{
struct macio_chip* macio;
unsigned long flags;
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
if (pmac_mb.model_id == PMAC_TYPE_PISMO ||
pmac_mb.model_id == PMAC_TYPE_TITANIUM) {
LOCK(flags);
if (value)
MACIO_OUT8(KL_GPIO_SOUND_POWER,
KEYLARGO_GPIO_OUTPUT_ENABLE |
KEYLARGO_GPIO_OUTOUT_DATA);
else
MACIO_OUT8(KL_GPIO_SOUND_POWER,
KEYLARGO_GPIO_OUTPUT_ENABLE);
(void)MACIO_IN8(KL_GPIO_SOUND_POWER);
UNLOCK(flags);
}
return 0;
}
static long
core99_airport_enable(struct device_node *node, long param, long value)
{
struct macio_chip* macio;
unsigned long flags;
int state;
macio = macio_find(node, 0);
if (!macio)
return -ENODEV;
if (node != macio->of_node &&
(!node->parent || node->parent != macio->of_node))
return -ENODEV;
state = (macio->flags & MACIO_FLAG_AIRPORT_ON) != 0;
if (value == state)
return 0;
if (value) {
LOCK(flags);
MACIO_OUT8(KEYLARGO_GPIO_0+0xf, 5);
(void)MACIO_IN8(KEYLARGO_GPIO_0+0xf);
UNLOCK(flags);
mdelay(10);
LOCK(flags);
MACIO_OUT8(KEYLARGO_GPIO_0+0xf, 4);
(void)MACIO_IN8(KEYLARGO_GPIO_0+0xf);
UNLOCK(flags);
mdelay(10);
LOCK(flags);
MACIO_BIC(KEYLARGO_FCR2, KL2_CARDSEL_16);
(void)MACIO_IN32(KEYLARGO_FCR2);
udelay(10);
MACIO_OUT8(KEYLARGO_GPIO_EXTINT_0+0xb, 0);
(void)MACIO_IN8(KEYLARGO_GPIO_EXTINT_0+0xb);
udelay(10);
MACIO_OUT8(KEYLARGO_GPIO_EXTINT_0+0xa, 0x28);
(void)MACIO_IN8(KEYLARGO_GPIO_EXTINT_0+0xa);
udelay(10);
MACIO_OUT8(KEYLARGO_GPIO_EXTINT_0+0xd, 0x28);
(void)MACIO_IN8(KEYLARGO_GPIO_EXTINT_0+0xd);
udelay(10);
MACIO_OUT8(KEYLARGO_GPIO_0+0xd, 0x28);
(void)MACIO_IN8(KEYLARGO_GPIO_0+0xd);
udelay(10);
MACIO_OUT8(KEYLARGO_GPIO_0+0xe, 0x28);
(void)MACIO_IN8(KEYLARGO_GPIO_0+0xe);
UNLOCK(flags);
udelay(10);
MACIO_OUT32(0x1c000, 0);
mdelay(1);
MACIO_OUT8(0x1a3e0, 0x41);
(void)MACIO_IN8(0x1a3e0);
udelay(10);
LOCK(flags);
MACIO_BIS(KEYLARGO_FCR2, KL2_CARDSEL_16);
(void)MACIO_IN32(KEYLARGO_FCR2);
UNLOCK(flags);
mdelay(100);
macio->flags |= MACIO_FLAG_AIRPORT_ON;
} else {
LOCK(flags);
MACIO_BIC(KEYLARGO_FCR2, KL2_CARDSEL_16);
(void)MACIO_IN32(KEYLARGO_FCR2);
MACIO_OUT8(KL_GPIO_AIRPORT_0, 0);
MACIO_OUT8(KL_GPIO_AIRPORT_1, 0);
MACIO_OUT8(KL_GPIO_AIRPORT_2, 0);
MACIO_OUT8(KL_GPIO_AIRPORT_3, 0);
MACIO_OUT8(KL_GPIO_AIRPORT_4, 0);
(void)MACIO_IN8(KL_GPIO_AIRPORT_4);
UNLOCK(flags);
macio->flags &= ~MACIO_FLAG_AIRPORT_ON;
}
return 0;
}
static long
core99_reset_cpu(struct device_node *node, long param, long value)
{
unsigned int reset_io = 0;
unsigned long flags;
struct macio_chip *macio;
struct device_node *np;
struct device_node *cpus;
const int dflt_reset_lines[] = { KL_GPIO_RESET_CPU0,
KL_GPIO_RESET_CPU1,
KL_GPIO_RESET_CPU2,
KL_GPIO_RESET_CPU3 };
macio = &macio_chips[0];
if (macio->type != macio_keylargo)
return -ENODEV;
cpus = of_find_node_by_path("/cpus");
if (cpus == NULL)
return -ENODEV;
for (np = cpus->child; np != NULL; np = np->sibling) {
const u32 *num = of_get_property(np, "reg", NULL);
const u32 *rst = of_get_property(np, "soft-reset", NULL);
if (num == NULL || rst == NULL)
continue;
if (param == *num) {
reset_io = *rst;
break;
}
}
of_node_put(cpus);
if (np == NULL || reset_io == 0)
reset_io = dflt_reset_lines[param];
LOCK(flags);
MACIO_OUT8(reset_io, KEYLARGO_GPIO_OUTPUT_ENABLE);
(void)MACIO_IN8(reset_io);
udelay(1);
MACIO_OUT8(reset_io, 0);
(void)MACIO_IN8(reset_io);
UNLOCK(flags);
return 0;
}
static long
core99_usb_enable(struct device_node *node, long param, long value)
{
struct macio_chip *macio;
unsigned long flags;
const char *prop;
int number;
u32 reg;
macio = &macio_chips[0];
if (macio->type != macio_keylargo && macio->type != macio_pangea &&
macio->type != macio_intrepid)
return -ENODEV;
prop = of_get_property(node, "AAPL,clock-id", NULL);
if (!prop)
return -ENODEV;
if (strncmp(prop, "usb0u048", 8) == 0)
number = 0;
else if (strncmp(prop, "usb1u148", 8) == 0)
number = 2;
else if (strncmp(prop, "usb2u248", 8) == 0)
number = 4;
else
return -ENODEV;
LOCK(flags);
if (value) {
if (number == 0) {
MACIO_BIC(KEYLARGO_FCR0, (KL0_USB0_PAD_SUSPEND0 | KL0_USB0_PAD_SUSPEND1));
(void)MACIO_IN32(KEYLARGO_FCR0);
UNLOCK(flags);
mdelay(1);
LOCK(flags);
MACIO_BIS(KEYLARGO_FCR0, KL0_USB0_CELL_ENABLE);
} else if (number == 2) {
MACIO_BIC(KEYLARGO_FCR0, (KL0_USB1_PAD_SUSPEND0 | KL0_USB1_PAD_SUSPEND1));
UNLOCK(flags);
(void)MACIO_IN32(KEYLARGO_FCR0);
mdelay(1);
LOCK(flags);
MACIO_BIS(KEYLARGO_FCR0, KL0_USB1_CELL_ENABLE);
} else if (number == 4) {
MACIO_BIC(KEYLARGO_FCR1, (KL1_USB2_PAD_SUSPEND0 | KL1_USB2_PAD_SUSPEND1));
UNLOCK(flags);
(void)MACIO_IN32(KEYLARGO_FCR1);
mdelay(1);
LOCK(flags);
MACIO_BIS(KEYLARGO_FCR1, KL1_USB2_CELL_ENABLE);
}
if (number < 4) {
reg = MACIO_IN32(KEYLARGO_FCR4);
reg &= ~(KL4_PORT_WAKEUP_ENABLE(number) | KL4_PORT_RESUME_WAKE_EN(number) |
KL4_PORT_CONNECT_WAKE_EN(number) | KL4_PORT_DISCONNECT_WAKE_EN(number));
reg &= ~(KL4_PORT_WAKEUP_ENABLE(number+1) | KL4_PORT_RESUME_WAKE_EN(number+1) |
KL4_PORT_CONNECT_WAKE_EN(number+1) | KL4_PORT_DISCONNECT_WAKE_EN(number+1));
MACIO_OUT32(KEYLARGO_FCR4, reg);
(void)MACIO_IN32(KEYLARGO_FCR4);
udelay(10);
} else {
reg = MACIO_IN32(KEYLARGO_FCR3);
reg &= ~(KL3_IT_PORT_WAKEUP_ENABLE(0) | KL3_IT_PORT_RESUME_WAKE_EN(0) |
KL3_IT_PORT_CONNECT_WAKE_EN(0) | KL3_IT_PORT_DISCONNECT_WAKE_EN(0));
reg &= ~(KL3_IT_PORT_WAKEUP_ENABLE(1) | KL3_IT_PORT_RESUME_WAKE_EN(1) |
KL3_IT_PORT_CONNECT_WAKE_EN(1) | KL3_IT_PORT_DISCONNECT_WAKE_EN(1));
MACIO_OUT32(KEYLARGO_FCR3, reg);
(void)MACIO_IN32(KEYLARGO_FCR3);
udelay(10);
}
if (macio->type == macio_intrepid) {
u32 test0 = 0, test1 = 0;
u32 status0, status1;
int timeout = 1000;
UNLOCK(flags);
switch (number) {
case 0:
test0 = UNI_N_CLOCK_STOPPED_USB0;
test1 = UNI_N_CLOCK_STOPPED_USB0PCI;
break;
case 2:
test0 = UNI_N_CLOCK_STOPPED_USB1;
test1 = UNI_N_CLOCK_STOPPED_USB1PCI;
break;
case 4:
test0 = UNI_N_CLOCK_STOPPED_USB2;
test1 = UNI_N_CLOCK_STOPPED_USB2PCI;
break;
}
do {
if (--timeout <= 0) {
printk(KERN_ERR "core99_usb_enable: "
"Timeout waiting for clocks\n");
break;
}
mdelay(1);
status0 = UN_IN(UNI_N_CLOCK_STOP_STATUS0);
status1 = UN_IN(UNI_N_CLOCK_STOP_STATUS1);
} while ((status0 & test0) | (status1 & test1));
LOCK(flags);
}
} else {
if (number < 4) {
reg = MACIO_IN32(KEYLARGO_FCR4);
reg |= KL4_PORT_WAKEUP_ENABLE(number) | KL4_PORT_RESUME_WAKE_EN(number) |
KL4_PORT_CONNECT_WAKE_EN(number) | KL4_PORT_DISCONNECT_WAKE_EN(number);
reg |= KL4_PORT_WAKEUP_ENABLE(number+1) | KL4_PORT_RESUME_WAKE_EN(number+1) |
KL4_PORT_CONNECT_WAKE_EN(number+1) | KL4_PORT_DISCONNECT_WAKE_EN(number+1);
MACIO_OUT32(KEYLARGO_FCR4, reg);
(void)MACIO_IN32(KEYLARGO_FCR4);
udelay(1);
} else {
reg = MACIO_IN32(KEYLARGO_FCR3);
reg |= KL3_IT_PORT_WAKEUP_ENABLE(0) | KL3_IT_PORT_RESUME_WAKE_EN(0) |
KL3_IT_PORT_CONNECT_WAKE_EN(0) | KL3_IT_PORT_DISCONNECT_WAKE_EN(0);
reg |= KL3_IT_PORT_WAKEUP_ENABLE(1) | KL3_IT_PORT_RESUME_WAKE_EN(1) |
KL3_IT_PORT_CONNECT_WAKE_EN(1) | KL3_IT_PORT_DISCONNECT_WAKE_EN(1);
MACIO_OUT32(KEYLARGO_FCR3, reg);
(void)MACIO_IN32(KEYLARGO_FCR3);
udelay(1);
}
if (number == 0) {
if (macio->type != macio_intrepid)
MACIO_BIC(KEYLARGO_FCR0, KL0_USB0_CELL_ENABLE);
(void)MACIO_IN32(KEYLARGO_FCR0);
udelay(1);
MACIO_BIS(KEYLARGO_FCR0, (KL0_USB0_PAD_SUSPEND0 | KL0_USB0_PAD_SUSPEND1));
(void)MACIO_IN32(KEYLARGO_FCR0);
} else if (number == 2) {
if (macio->type != macio_intrepid)
MACIO_BIC(KEYLARGO_FCR0, KL0_USB1_CELL_ENABLE);
(void)MACIO_IN32(KEYLARGO_FCR0);
udelay(1);
MACIO_BIS(KEYLARGO_FCR0, (KL0_USB1_PAD_SUSPEND0 | KL0_USB1_PAD_SUSPEND1));
(void)MACIO_IN32(KEYLARGO_FCR0);
} else if (number == 4) {
udelay(1);
MACIO_BIS(KEYLARGO_FCR1, (KL1_USB2_PAD_SUSPEND0 | KL1_USB2_PAD_SUSPEND1));
(void)MACIO_IN32(KEYLARGO_FCR1);
}
udelay(1);
}
UNLOCK(flags);
return 0;
}
static long
core99_firewire_enable(struct device_node *node, long param, long value)
{
unsigned long flags;
struct macio_chip *macio;
macio = &macio_chips[0];
if (macio->type != macio_keylargo && macio->type != macio_pangea &&
macio->type != macio_intrepid)
return -ENODEV;
if (!(macio->flags & MACIO_FLAG_FW_SUPPORTED))
return -ENODEV;
LOCK(flags);
if (value) {
UN_BIS(UNI_N_CLOCK_CNTL, UNI_N_CLOCK_CNTL_FW);
(void)UN_IN(UNI_N_CLOCK_CNTL);
} else {
UN_BIC(UNI_N_CLOCK_CNTL, UNI_N_CLOCK_CNTL_FW);
(void)UN_IN(UNI_N_CLOCK_CNTL);
}
UNLOCK(flags);
mdelay(1);
return 0;
}
static long
core99_firewire_cable_power(struct device_node *node, long param, long value)
{
unsigned long flags;
struct macio_chip *macio;
if ((pmac_mb.board_flags & PMAC_MB_HAS_FW_POWER) == 0)
return -ENODEV;
macio = &macio_chips[0];
if (macio->type != macio_keylargo && macio->type != macio_pangea &&
macio->type != macio_intrepid)
return -ENODEV;
if (!(macio->flags & MACIO_FLAG_FW_SUPPORTED))
return -ENODEV;
LOCK(flags);
if (value) {
MACIO_OUT8(KL_GPIO_FW_CABLE_POWER , 0);
MACIO_IN8(KL_GPIO_FW_CABLE_POWER);
udelay(10);
} else {
MACIO_OUT8(KL_GPIO_FW_CABLE_POWER , 4);
MACIO_IN8(KL_GPIO_FW_CABLE_POWER); udelay(10);
}
UNLOCK(flags);
mdelay(1);
return 0;
}
static long
intrepid_aack_delay_enable(struct device_node *node, long param, long value)
{
unsigned long flags;
if (uninorth_rev < 0xd2)
return -ENODEV;
LOCK(flags);
if (param)
UN_BIS(UNI_N_AACK_DELAY, UNI_N_AACK_DELAY_ENABLE);
else
UN_BIC(UNI_N_AACK_DELAY, UNI_N_AACK_DELAY_ENABLE);
UNLOCK(flags);
return 0;
}
static long
core99_read_gpio(struct device_node *node, long param, long value)
{
struct macio_chip *macio = &macio_chips[0];
return MACIO_IN8(param);
}
static long
core99_write_gpio(struct device_node *node, long param, long value)
{
struct macio_chip *macio = &macio_chips[0];
MACIO_OUT8(param, (u8)(value & 0xff));
return 0;
}
static long g5_gmac_enable(struct device_node *node, long param, long value)
{
struct macio_chip *macio = &macio_chips[0];
unsigned long flags;
if (node == NULL)
return -ENODEV;
LOCK(flags);
if (value) {
MACIO_BIS(KEYLARGO_FCR1, K2_FCR1_GMAC_CLK_ENABLE);
mb();
k2_skiplist[0] = NULL;
} else {
k2_skiplist[0] = node;
mb();
MACIO_BIC(KEYLARGO_FCR1, K2_FCR1_GMAC_CLK_ENABLE);
}
UNLOCK(flags);
mdelay(1);
return 0;
}
static long g5_fw_enable(struct device_node *node, long param, long value)
{
struct macio_chip *macio = &macio_chips[0];
unsigned long flags;
if (node == NULL)
return -ENODEV;
LOCK(flags);
if (value) {
MACIO_BIS(KEYLARGO_FCR1, K2_FCR1_FW_CLK_ENABLE);
mb();
k2_skiplist[1] = NULL;
} else {
k2_skiplist[1] = node;
mb();
MACIO_BIC(KEYLARGO_FCR1, K2_FCR1_FW_CLK_ENABLE);
}
UNLOCK(flags);
mdelay(1);
return 0;
}
static long g5_mpic_enable(struct device_node *node, long param, long value)
{
unsigned long flags;
struct device_node *parent = of_get_parent(node);
int is_u3;
if (parent == NULL)
return 0;
is_u3 = strcmp(parent->name, "u3") == 0 ||
strcmp(parent->name, "u4") == 0;
of_node_put(parent);
if (!is_u3)
return 0;
LOCK(flags);
UN_BIS(U3_TOGGLE_REG, U3_MPIC_RESET | U3_MPIC_OUTPUT_ENABLE);
UNLOCK(flags);
return 0;
}
static long g5_eth_phy_reset(struct device_node *node, long param, long value)
{
struct macio_chip *macio = &macio_chips[0];
struct device_node *phy;
int need_reset;
phy = of_get_next_child(node, NULL);
if (!phy)
return -ENODEV;
need_reset = of_device_is_compatible(phy, "B5221");
of_node_put(phy);
if (!need_reset)
return 0;
MACIO_OUT8(K2_GPIO_EXTINT_0 + 29,
KEYLARGO_GPIO_OUTPUT_ENABLE | KEYLARGO_GPIO_OUTOUT_DATA);
msleep(10);
MACIO_OUT8(K2_GPIO_EXTINT_0 + 29, 0);
return 0;
}
static long g5_i2s_enable(struct device_node *node, long param, long value)
{
struct macio_chip *macio = &macio_chips[0];
unsigned long flags;
int cell;
u32 fcrs[3][3] = {
{ 0,
K2_FCR1_I2S0_CELL_ENABLE |
K2_FCR1_I2S0_CLK_ENABLE_BIT | K2_FCR1_I2S0_ENABLE,
KL3_I2S0_CLK18_ENABLE
},
{ KL0_SCC_A_INTF_ENABLE,
K2_FCR1_I2S1_CELL_ENABLE |
K2_FCR1_I2S1_CLK_ENABLE_BIT | K2_FCR1_I2S1_ENABLE,
KL3_I2S1_CLK18_ENABLE
},
{ KL0_SCC_B_INTF_ENABLE,
SH_FCR1_I2S2_CELL_ENABLE |
SH_FCR1_I2S2_CLK_ENABLE_BIT | SH_FCR1_I2S2_ENABLE,
SH_FCR3_I2S2_CLK18_ENABLE
},
};
if (macio->type != macio_keylargo2 && macio->type != macio_shasta)
return -ENODEV;
if (strncmp(node->name, "i2s-", 4))
return -ENODEV;
cell = node->name[4] - 'a';
switch(cell) {
case 0:
case 1:
break;
case 2:
if (macio->type == macio_shasta)
break;
default:
return -ENODEV;
}
LOCK(flags);
if (value) {
MACIO_BIC(KEYLARGO_FCR0, fcrs[cell][0]);
MACIO_BIS(KEYLARGO_FCR1, fcrs[cell][1]);
MACIO_BIS(KEYLARGO_FCR3, fcrs[cell][2]);
} else {
MACIO_BIC(KEYLARGO_FCR3, fcrs[cell][2]);
MACIO_BIC(KEYLARGO_FCR1, fcrs[cell][1]);
MACIO_BIS(KEYLARGO_FCR0, fcrs[cell][0]);
}
udelay(10);
UNLOCK(flags);
return 0;
}
static long g5_reset_cpu(struct device_node *node, long param, long value)
{
unsigned int reset_io = 0;
unsigned long flags;
struct macio_chip *macio;
struct device_node *np;
struct device_node *cpus;
macio = &macio_chips[0];
if (macio->type != macio_keylargo2 && macio->type != macio_shasta)
return -ENODEV;
cpus = of_find_node_by_path("/cpus");
if (cpus == NULL)
return -ENODEV;
for (np = cpus->child; np != NULL; np = np->sibling) {
const u32 *num = of_get_property(np, "reg", NULL);
const u32 *rst = of_get_property(np, "soft-reset", NULL);
if (num == NULL || rst == NULL)
continue;
if (param == *num) {
reset_io = *rst;
break;
}
}
of_node_put(cpus);
if (np == NULL || reset_io == 0)
return -ENODEV;
LOCK(flags);
MACIO_OUT8(reset_io, KEYLARGO_GPIO_OUTPUT_ENABLE);
(void)MACIO_IN8(reset_io);
udelay(1);
MACIO_OUT8(reset_io, 0);
(void)MACIO_IN8(reset_io);
UNLOCK(flags);
return 0;
}
void g5_phy_disable_cpu1(void)
{
if (uninorth_maj == 3)
UN_OUT(U3_API_PHY_CONFIG_1, 0);
}
static void keylargo_shutdown(struct macio_chip *macio, int sleep_mode)
{
u32 temp;
if (sleep_mode) {
mdelay(1);
MACIO_BIS(KEYLARGO_FCR0, KL0_USB_REF_SUSPEND);
(void)MACIO_IN32(KEYLARGO_FCR0);
mdelay(1);
}
MACIO_BIC(KEYLARGO_FCR0,KL0_SCCA_ENABLE | KL0_SCCB_ENABLE |
KL0_SCC_CELL_ENABLE |
KL0_IRDA_ENABLE | KL0_IRDA_CLK32_ENABLE |
KL0_IRDA_CLK19_ENABLE);
MACIO_BIC(KEYLARGO_MBCR, KL_MBCR_MB0_DEV_MASK);
MACIO_BIS(KEYLARGO_MBCR, KL_MBCR_MB0_IDE_ENABLE);
MACIO_BIC(KEYLARGO_FCR1,
KL1_AUDIO_SEL_22MCLK | KL1_AUDIO_CLK_ENABLE_BIT |
KL1_AUDIO_CLK_OUT_ENABLE | KL1_AUDIO_CELL_ENABLE |
KL1_I2S0_CELL_ENABLE | KL1_I2S0_CLK_ENABLE_BIT |
KL1_I2S0_ENABLE | KL1_I2S1_CELL_ENABLE |
KL1_I2S1_CLK_ENABLE_BIT | KL1_I2S1_ENABLE |
KL1_EIDE0_ENABLE | KL1_EIDE0_RESET_N |
KL1_EIDE1_ENABLE | KL1_EIDE1_RESET_N |
KL1_UIDE_ENABLE);
MACIO_BIS(KEYLARGO_FCR2, KL2_ALT_DATA_OUT);
MACIO_BIC(KEYLARGO_FCR2, KL2_IOBUS_ENABLE);
temp = MACIO_IN32(KEYLARGO_FCR3);
if (macio->rev >= 2) {
temp |= KL3_SHUTDOWN_PLL2X;
if (sleep_mode)
temp |= KL3_SHUTDOWN_PLL_TOTAL;
}
temp |= KL3_SHUTDOWN_PLLKW6 | KL3_SHUTDOWN_PLLKW4 |
KL3_SHUTDOWN_PLLKW35;
if (sleep_mode)
temp |= KL3_SHUTDOWN_PLLKW12;
temp &= ~(KL3_CLK66_ENABLE | KL3_CLK49_ENABLE | KL3_CLK45_ENABLE
| KL3_CLK31_ENABLE | KL3_I2S1_CLK18_ENABLE | KL3_I2S0_CLK18_ENABLE);
if (sleep_mode)
temp &= ~(KL3_TIMER_CLK18_ENABLE | KL3_VIA_CLK16_ENABLE);
MACIO_OUT32(KEYLARGO_FCR3, temp);
(void)MACIO_IN32(KEYLARGO_FCR0); mdelay(1);
}
static void pangea_shutdown(struct macio_chip *macio, int sleep_mode)
{
u32 temp;
MACIO_BIC(KEYLARGO_FCR0,KL0_SCCA_ENABLE | KL0_SCCB_ENABLE |
KL0_SCC_CELL_ENABLE |
KL0_USB0_CELL_ENABLE | KL0_USB1_CELL_ENABLE);
MACIO_BIC(KEYLARGO_FCR1,
KL1_AUDIO_SEL_22MCLK | KL1_AUDIO_CLK_ENABLE_BIT |
KL1_AUDIO_CLK_OUT_ENABLE | KL1_AUDIO_CELL_ENABLE |
KL1_I2S0_CELL_ENABLE | KL1_I2S0_CLK_ENABLE_BIT |
KL1_I2S0_ENABLE | KL1_I2S1_CELL_ENABLE |
KL1_I2S1_CLK_ENABLE_BIT | KL1_I2S1_ENABLE |
KL1_UIDE_ENABLE);
if (pmac_mb.board_flags & PMAC_MB_MOBILE)
MACIO_BIC(KEYLARGO_FCR1, KL1_UIDE_RESET_N);
MACIO_BIS(KEYLARGO_FCR2, KL2_ALT_DATA_OUT);
temp = MACIO_IN32(KEYLARGO_FCR3);
temp |= KL3_SHUTDOWN_PLLKW6 | KL3_SHUTDOWN_PLLKW4 |
KL3_SHUTDOWN_PLLKW35;
temp &= ~(KL3_CLK49_ENABLE | KL3_CLK45_ENABLE | KL3_CLK31_ENABLE
| KL3_I2S0_CLK18_ENABLE | KL3_I2S1_CLK18_ENABLE);
if (sleep_mode)
temp &= ~(KL3_VIA_CLK16_ENABLE | KL3_TIMER_CLK18_ENABLE);
MACIO_OUT32(KEYLARGO_FCR3, temp);
(void)MACIO_IN32(KEYLARGO_FCR0); mdelay(1);
}
static void intrepid_shutdown(struct macio_chip *macio, int sleep_mode)
{
u32 temp;
MACIO_BIC(KEYLARGO_FCR0,KL0_SCCA_ENABLE | KL0_SCCB_ENABLE |
KL0_SCC_CELL_ENABLE);
MACIO_BIC(KEYLARGO_FCR1,
KL1_I2S0_CELL_ENABLE | KL1_I2S0_CLK_ENABLE_BIT |
KL1_I2S0_ENABLE | KL1_I2S1_CELL_ENABLE |
KL1_I2S1_CLK_ENABLE_BIT | KL1_I2S1_ENABLE |
KL1_EIDE0_ENABLE);
if (pmac_mb.board_flags & PMAC_MB_MOBILE)
MACIO_BIC(KEYLARGO_FCR1, KL1_UIDE_RESET_N);
temp = MACIO_IN32(KEYLARGO_FCR3);
temp &= ~(KL3_CLK49_ENABLE | KL3_CLK45_ENABLE |
KL3_I2S1_CLK18_ENABLE | KL3_I2S0_CLK18_ENABLE);
if (sleep_mode)
temp &= ~(KL3_TIMER_CLK18_ENABLE | KL3_IT_VIA_CLK32_ENABLE);
MACIO_OUT32(KEYLARGO_FCR3, temp);
(void)MACIO_IN32(KEYLARGO_FCR0);
mdelay(10);
}
static int
core99_sleep(void)
{
struct macio_chip *macio;
int i;
macio = &macio_chips[0];
if (macio->type != macio_keylargo && macio->type != macio_pangea &&
macio->type != macio_intrepid)
return -ENODEV;
if (macio->flags & MACIO_FLAG_AIRPORT_ON)
core99_airport_enable(macio->of_node, 0, 0);
if (macio->flags & MACIO_FLAG_FW_SUPPORTED) {
core99_firewire_enable(NULL, 0, 0);
core99_firewire_cable_power(NULL, 0, 0);
}
if (macio->type == macio_keylargo)
core99_modem_enable(macio->of_node, 0, 0);
else
pangea_modem_enable(macio->of_node, 0, 0);
core99_sound_chip_enable(macio->of_node, 0, 0);
save_gpio_levels[0] = MACIO_IN32(KEYLARGO_GPIO_LEVELS0);
save_gpio_levels[1] = MACIO_IN32(KEYLARGO_GPIO_LEVELS1);
for (i=0; i<KEYLARGO_GPIO_EXTINT_CNT; i++)
save_gpio_extint[i] = MACIO_IN8(KEYLARGO_GPIO_EXTINT_0+i);
for (i=0; i<KEYLARGO_GPIO_CNT; i++)
save_gpio_normal[i] = MACIO_IN8(KEYLARGO_GPIO_0+i);
if (macio->type == macio_keylargo)
save_mbcr = MACIO_IN32(KEYLARGO_MBCR);
save_fcr[0] = MACIO_IN32(KEYLARGO_FCR0);
save_fcr[1] = MACIO_IN32(KEYLARGO_FCR1);
save_fcr[2] = MACIO_IN32(KEYLARGO_FCR2);
save_fcr[3] = MACIO_IN32(KEYLARGO_FCR3);
save_fcr[4] = MACIO_IN32(KEYLARGO_FCR4);
if (macio->type == macio_pangea || macio->type == macio_intrepid)
save_fcr[5] = MACIO_IN32(KEYLARGO_FCR5);
dbdma_save(macio, save_dbdma);
if (macio->type == macio_pangea)
pangea_shutdown(macio, 1);
else if (macio->type == macio_intrepid)
intrepid_shutdown(macio, 1);
else if (macio->type == macio_keylargo)
keylargo_shutdown(macio, 1);
save_unin_clock_ctl = UN_IN(UNI_N_CLOCK_CNTL);
UN_OUT(UNI_N_CLOCK_CNTL, save_unin_clock_ctl &
~(UNI_N_CLOCK_CNTL_FW));
udelay(100);
UN_OUT(UNI_N_HWINIT_STATE, UNI_N_HWINIT_STATE_SLEEPING);
UN_OUT(UNI_N_POWER_MGT, UNI_N_POWER_MGT_SLEEP);
mdelay(10);
if (pmac_mb.model_id == PMAC_TYPE_SAWTOOTH) {
MACIO_BIS(0x506e0, 0x00400000);
MACIO_BIS(0x506e0, 0x80000000);
}
return 0;
}
static int
core99_wake_up(void)
{
struct macio_chip *macio;
int i;
macio = &macio_chips[0];
if (macio->type != macio_keylargo && macio->type != macio_pangea &&
macio->type != macio_intrepid)
return -ENODEV;
UN_OUT(UNI_N_POWER_MGT, UNI_N_POWER_MGT_NORMAL);
udelay(10);
UN_OUT(UNI_N_HWINIT_STATE, UNI_N_HWINIT_STATE_RUNNING);
udelay(10);
if (macio->type == macio_keylargo) {
MACIO_OUT32(KEYLARGO_MBCR, save_mbcr);
(void)MACIO_IN32(KEYLARGO_MBCR); udelay(10);
}
MACIO_OUT32(KEYLARGO_FCR0, save_fcr[0]);
(void)MACIO_IN32(KEYLARGO_FCR0); udelay(10);
MACIO_OUT32(KEYLARGO_FCR1, save_fcr[1]);
(void)MACIO_IN32(KEYLARGO_FCR1); udelay(10);
MACIO_OUT32(KEYLARGO_FCR2, save_fcr[2]);
(void)MACIO_IN32(KEYLARGO_FCR2); udelay(10);
MACIO_OUT32(KEYLARGO_FCR3, save_fcr[3]);
(void)MACIO_IN32(KEYLARGO_FCR3); udelay(10);
MACIO_OUT32(KEYLARGO_FCR4, save_fcr[4]);
(void)MACIO_IN32(KEYLARGO_FCR4); udelay(10);
if (macio->type == macio_pangea || macio->type == macio_intrepid) {
MACIO_OUT32(KEYLARGO_FCR5, save_fcr[5]);
(void)MACIO_IN32(KEYLARGO_FCR5); udelay(10);
}
dbdma_restore(macio, save_dbdma);
MACIO_OUT32(KEYLARGO_GPIO_LEVELS0, save_gpio_levels[0]);
MACIO_OUT32(KEYLARGO_GPIO_LEVELS1, save_gpio_levels[1]);
for (i=0; i<KEYLARGO_GPIO_EXTINT_CNT; i++)
MACIO_OUT8(KEYLARGO_GPIO_EXTINT_0+i, save_gpio_extint[i]);
for (i=0; i<KEYLARGO_GPIO_CNT; i++)
MACIO_OUT8(KEYLARGO_GPIO_0+i, save_gpio_normal[i]);
if (pmac_mb.model_id == PMAC_TYPE_SAWTOOTH) {
MACIO_BIC(0x506e0, 0x00400000);
MACIO_BIC(0x506e0, 0x80000000);
}
UN_OUT(UNI_N_CLOCK_CNTL, save_unin_clock_ctl);
udelay(100);
return 0;
}
static long
core99_sleep_state(struct device_node *node, long param, long value)
{
if (param == 1) {
if (value == 1) {
UN_OUT(UNI_N_HWINIT_STATE, UNI_N_HWINIT_STATE_SLEEPING);
UN_OUT(UNI_N_POWER_MGT, UNI_N_POWER_MGT_IDLE2);
} else {
UN_OUT(UNI_N_POWER_MGT, UNI_N_POWER_MGT_NORMAL);
udelay(10);
UN_OUT(UNI_N_HWINIT_STATE, UNI_N_HWINIT_STATE_RUNNING);
udelay(10);
}
return 0;
}
if ((pmac_mb.board_flags & PMAC_MB_CAN_SLEEP) == 0)
return -EPERM;
#ifdef CONFIG_PM
if (value == 1)
return core99_sleep();
else if (value == 0)
return core99_wake_up();
#endif
return 0;
}
static long
generic_dev_can_wake(struct device_node *node, long param, long value)
{
if (pmac_mb.board_flags & PMAC_MB_MAY_SLEEP)
pmac_mb.board_flags |= PMAC_MB_CAN_SLEEP;
return 0;
}
static long generic_get_mb_info(struct device_node *node, long param, long value)
{
switch(param) {
case PMAC_MB_INFO_MODEL:
return pmac_mb.model_id;
case PMAC_MB_INFO_FLAGS:
return pmac_mb.board_flags;
case PMAC_MB_INFO_NAME:
*((const char **)value) = pmac_mb.model_name;
return 0;
}
return -EINVAL;
}
long pmac_do_feature_call(unsigned int selector, ...)
{
struct device_node *node;
long param, value;
int i;
feature_call func = NULL;
va_list args;
if (pmac_mb.features)
for (i=0; pmac_mb.features[i].function; i++)
if (pmac_mb.features[i].selector == selector) {
func = pmac_mb.features[i].function;
break;
}
if (!func)
for (i=0; any_features[i].function; i++)
if (any_features[i].selector == selector) {
func = any_features[i].function;
break;
}
if (!func)
return -ENODEV;
va_start(args, selector);
node = (struct device_node*)va_arg(args, void*);
param = va_arg(args, long);
value = va_arg(args, long);
va_end(args);
return func(node, param, value);
}
static int __init probe_motherboard(void)
{
int i;
struct macio_chip *macio = &macio_chips[0];
const char *model = NULL;
struct device_node *dt;
int ret = 0;
dt = of_find_node_by_name(NULL, "device-tree");
if (dt != NULL)
model = of_get_property(dt, "model", NULL);
for(i=0; model && i<ARRAY_SIZE(pmac_mb_defs); i++) {
if (strcmp(model, pmac_mb_defs[i].model_string) == 0) {
pmac_mb = pmac_mb_defs[i];
goto found;
}
}
for(i=0; i<ARRAY_SIZE(pmac_mb_defs); i++) {
if (of_machine_is_compatible(pmac_mb_defs[i].model_string)) {
pmac_mb = pmac_mb_defs[i];
goto found;
}
}
switch(macio->type) {
#ifndef CONFIG_PPC64
case macio_grand_central:
pmac_mb.model_id = PMAC_TYPE_PSURGE;
pmac_mb.model_name = "Unknown PowerSurge";
break;
case macio_ohare:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_OHARE;
pmac_mb.model_name = "Unknown OHare-based";
break;
case macio_heathrow:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_HEATHROW;
pmac_mb.model_name = "Unknown Heathrow-based";
pmac_mb.features = heathrow_desktop_features;
break;
case macio_paddington:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_PADDINGTON;
pmac_mb.model_name = "Unknown Paddington-based";
pmac_mb.features = paddington_features;
break;
case macio_keylargo:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_CORE99;
pmac_mb.model_name = "Unknown Keylargo-based";
pmac_mb.features = core99_features;
break;
case macio_pangea:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_PANGEA;
pmac_mb.model_name = "Unknown Pangea-based";
pmac_mb.features = pangea_features;
break;
case macio_intrepid:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_INTREPID;
pmac_mb.model_name = "Unknown Intrepid-based";
pmac_mb.features = intrepid_features;
break;
#else
case macio_keylargo2:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_K2;
pmac_mb.model_name = "Unknown K2-based";
pmac_mb.features = g5_features;
break;
case macio_shasta:
pmac_mb.model_id = PMAC_TYPE_UNKNOWN_SHASTA;
pmac_mb.model_name = "Unknown Shasta-based";
pmac_mb.features = g5_features;
break;
#endif
default:
ret = -ENODEV;
goto done;
}
found:
#ifndef CONFIG_PPC64
if (pmac_mb.model_id == PMAC_TYPE_HOOPER) {
u32 __iomem * mach_id_ptr = ioremap(0xf3000034, 4);
if (!mach_id_ptr) {
ret = -ENODEV;
goto done;
}
if (__raw_readl(mach_id_ptr) & 0x20000000UL)
pmac_mb.model_id = PMAC_TYPE_COMET;
iounmap(mach_id_ptr);
}
while (uninorth_base && uninorth_rev > 3) {
struct device_node *cpus = of_find_node_by_path("/cpus");
struct device_node *np;
if (!cpus || !cpus->child) {
printk(KERN_WARNING "Can't find CPU(s) in device tree !\n");
of_node_put(cpus);
break;
}
np = cpus->child;
if (np->sibling) {
of_node_put(cpus);
break;
}
if (of_get_property(np, "flush-on-lock", NULL)) {
of_node_put(cpus);
break;
}
of_node_put(cpus);
powersave_nap = 1;
printk(KERN_DEBUG "Processor NAP mode on idle enabled.\n");
break;
}
powersave_lowspeed = 1;
#else
powersave_nap = 1;
#endif
if (model && (strncmp(model, "PowerBook", 9) == 0
|| strncmp(model, "iBook", 5) == 0))
pmac_mb.board_flags |= PMAC_MB_MOBILE;
printk(KERN_INFO "PowerMac motherboard: %s\n", pmac_mb.model_name);
done:
of_node_put(dt);
return ret;
}
static void __init probe_uninorth(void)
{
const u32 *addrp;
phys_addr_t address;
unsigned long actrl;
uninorth_node = of_find_node_by_name(NULL, "uni-n");
uninorth_maj = 1;
if (uninorth_node == NULL) {
uninorth_node = of_find_node_by_name(NULL, "u3");
uninorth_maj = 3;
}
if (uninorth_node == NULL) {
uninorth_node = of_find_node_by_name(NULL, "u4");
uninorth_maj = 4;
}
if (uninorth_node == NULL) {
uninorth_maj = 0;
return;
}
addrp = of_get_property(uninorth_node, "reg", NULL);
if (addrp == NULL)
return;
address = of_translate_address(uninorth_node, addrp);
if (address == 0)
return;
uninorth_base = ioremap(address, 0x40000);
if (uninorth_base == NULL)
return;
uninorth_rev = in_be32(UN_REG(UNI_N_VERSION));
if (uninorth_maj == 3 || uninorth_maj == 4) {
u3_ht_base = ioremap(address + U3_HT_CONFIG_BASE, 0x1000);
if (u3_ht_base == NULL) {
iounmap(uninorth_base);
return;
}
}
printk(KERN_INFO "Found %s memory controller & host bridge"
" @ 0x%08x revision: 0x%02x\n", uninorth_maj == 3 ? "U3" :
uninorth_maj == 4 ? "U4" : "UniNorth",
(unsigned int)address, uninorth_rev);
printk(KERN_INFO "Mapped at 0x%08lx\n", (unsigned long)uninorth_base);
if (uninorth_rev < 0x11) {
actrl = UN_IN(UNI_N_ARB_CTRL) & ~UNI_N_ARB_CTRL_QACK_DELAY_MASK;
actrl |= ((uninorth_rev < 3) ? UNI_N_ARB_CTRL_QACK_DELAY105 :
UNI_N_ARB_CTRL_QACK_DELAY) <<
UNI_N_ARB_CTRL_QACK_DELAY_SHIFT;
UN_OUT(UNI_N_ARB_CTRL, actrl);
}
if ((uninorth_rev >= 0x11 && uninorth_rev <= 0x24) ||
uninorth_rev == 0xc0)
UN_OUT(0x2160, UN_IN(0x2160) & 0x00ffffff);
}
static void __init probe_one_macio(const char *name, const char *compat, int type)
{
struct device_node* node;
int i;
volatile u32 __iomem *base;
const u32 *addrp, *revp;
phys_addr_t addr;
u64 size;
for (node = NULL; (node = of_find_node_by_name(node, name)) != NULL;) {
if (!compat)
break;
if (of_device_is_compatible(node, compat))
break;
}
if (!node)
return;
for(i=0; i<MAX_MACIO_CHIPS; i++) {
if (!macio_chips[i].of_node)
break;
if (macio_chips[i].of_node == node)
return;
}
if (i >= MAX_MACIO_CHIPS) {
printk(KERN_ERR "pmac_feature: Please increase MAX_MACIO_CHIPS !\n");
printk(KERN_ERR "pmac_feature: %pOF skipped\n", node);
return;
}
addrp = of_get_pci_address(node, 0, &size, NULL);
if (addrp == NULL) {
printk(KERN_ERR "pmac_feature: %pOF: can't find base !\n",
node);
return;
}
addr = of_translate_address(node, addrp);
if (addr == 0) {
printk(KERN_ERR "pmac_feature: %pOF, can't translate base !\n",
node);
return;
}
base = ioremap(addr, (unsigned long)size);
if (!base) {
printk(KERN_ERR "pmac_feature: %pOF, can't map mac-io chip !\n",
node);
return;
}
if (type == macio_keylargo || type == macio_keylargo2) {
const u32 *did = of_get_property(node, "device-id", NULL);
if (*did == 0x00000025)
type = macio_pangea;
if (*did == 0x0000003e)
type = macio_intrepid;
if (*did == 0x0000004f)
type = macio_shasta;
}
macio_chips[i].of_node = node;
macio_chips[i].type = type;
macio_chips[i].base = base;
macio_chips[i].flags = MACIO_FLAG_SCCA_ON | MACIO_FLAG_SCCB_ON;
macio_chips[i].name = macio_names[type];
revp = of_get_property(node, "revision-id", NULL);
if (revp)
macio_chips[i].rev = *revp;
printk(KERN_INFO "Found a %s mac-io controller, rev: %d, mapped at 0x%p\n",
macio_names[type], macio_chips[i].rev, macio_chips[i].base);
}
static int __init
probe_macios(void)
{
probe_one_macio("gc", NULL, macio_grand_central);
probe_one_macio("ohare", NULL, macio_ohare);
probe_one_macio("pci106b,7", NULL, macio_ohareII);
probe_one_macio("mac-io", "keylargo", macio_keylargo);
probe_one_macio("mac-io", "paddington", macio_paddington);
probe_one_macio("mac-io", "gatwick", macio_gatwick);
probe_one_macio("mac-io", "heathrow", macio_heathrow);
probe_one_macio("mac-io", "K2-Keylargo", macio_keylargo2);
if (macio_chips[0].type == macio_gatwick
&& macio_chips[1].type == macio_heathrow) {
struct macio_chip temp = macio_chips[0];
macio_chips[0] = macio_chips[1];
macio_chips[1] = temp;
}
if (macio_chips[0].type == macio_ohareII
&& macio_chips[1].type == macio_ohare) {
struct macio_chip temp = macio_chips[0];
macio_chips[0] = macio_chips[1];
macio_chips[1] = temp;
}
macio_chips[0].lbus.index = 0;
macio_chips[1].lbus.index = 1;
return (macio_chips[0].of_node == NULL) ? -ENODEV : 0;
}
static void __init
initial_serial_shutdown(struct device_node *np)
{
int len;
const struct slot_names_prop {
int count;
char name[1];
} *slots;
const char *conn;
int port_type = PMAC_SCC_ASYNC;
int modem = 0;
slots = of_get_property(np, "slot-names", &len);
conn = of_get_property(np, "AAPL,connector", &len);
if (conn && (strcmp(conn, "infrared") == 0))
port_type = PMAC_SCC_IRDA;
else if (of_device_is_compatible(np, "cobalt"))
modem = 1;
else if (slots && slots->count > 0) {
if (strcmp(slots->name, "IrDA") == 0)
port_type = PMAC_SCC_IRDA;
else if (strcmp(slots->name, "Modem") == 0)
modem = 1;
}
if (modem)
pmac_call_feature(PMAC_FTR_MODEM_ENABLE, np, 0, 0);
pmac_call_feature(PMAC_FTR_SCC_ENABLE, np, port_type, 0);
}
static void __init
set_initial_features(void)
{
struct device_node *np;
if (macio_chips[0].type == macio_ohare) {
struct macio_chip *macio = &macio_chips[0];
np = of_find_node_by_name(NULL, "via-pmu");
if (np)
MACIO_BIS(OHARE_FCR, OH_IOBUS_ENABLE);
else
MACIO_OUT32(OHARE_FCR, STARMAX_FEATURES);
of_node_put(np);
} else if (macio_chips[1].type == macio_ohare) {
struct macio_chip *macio = &macio_chips[1];
MACIO_BIS(OHARE_FCR, OH_IOBUS_ENABLE);
}
#ifdef CONFIG_PPC64
if (macio_chips[0].type == macio_keylargo2 ||
macio_chips[0].type == macio_shasta) {
#ifndef CONFIG_SMP
np = of_find_node_by_type(NULL, "cpu");
if (np != NULL)
np = of_find_node_by_type(np, "cpu");
if (np != NULL) {
g5_phy_disable_cpu1();
of_node_put(np);
}
#endif
for_each_node_by_name(np, "ethernet")
if (of_device_is_compatible(np, "K2-GMAC"))
g5_gmac_enable(np, 0, 1);
for_each_node_by_name(np, "firewire") {
if (of_device_is_compatible(np, "pci106b,5811")) {
macio_chips[0].flags |= MACIO_FLAG_FW_SUPPORTED;
g5_fw_enable(np, 0, 1);
}
}
}
#else
if (macio_chips[0].type == macio_keylargo ||
macio_chips[0].type == macio_pangea ||
macio_chips[0].type == macio_intrepid) {
for_each_node_by_name(np, "ethernet") {
if (np->parent
&& of_device_is_compatible(np->parent, "uni-north")
&& of_device_is_compatible(np, "gmac"))
core99_gmac_enable(np, 0, 1);
}
for_each_node_by_name(np, "firewire") {
if (np->parent
&& of_device_is_compatible(np->parent, "uni-north")
&& (of_device_is_compatible(np, "pci106b,18") ||
of_device_is_compatible(np, "pci106b,30") ||
of_device_is_compatible(np, "pci11c1,5811"))) {
macio_chips[0].flags |= MACIO_FLAG_FW_SUPPORTED;
core99_firewire_enable(np, 0, 1);
}
}
np = of_find_node_by_name(NULL, "ata-6");
for_each_node_by_name(np, "ata-6") {
if (np->parent
&& of_device_is_compatible(np->parent, "uni-north")
&& of_device_is_compatible(np, "kauai-ata")) {
core99_ata100_enable(np, 1);
}
}
for_each_node_by_name(np, "radio") {
if (np->parent == macio_chips[0].of_node) {
macio_chips[0].flags |= MACIO_FLAG_AIRPORT_ON;
core99_airport_enable(np, 0, 0);
}
}
}
if (macio_chips[0].of_node)
pmac_do_feature_call(PMAC_FTR_SOUND_CHIP_ENABLE,
macio_chips[0].of_node, 0, 0);
if (macio_chips[0].of_node && macio_chips[0].type == macio_heathrow
&& (pmac_mb.model_id == PMAC_TYPE_GOSSAMER ||
pmac_mb.model_id == PMAC_TYPE_SILK)) {
struct macio_chip *macio = &macio_chips[0];
MACIO_BIS(HEATHROW_FCR, HRW_SOUND_CLK_ENABLE);
MACIO_BIC(HEATHROW_FCR, HRW_SOUND_POWER_N);
}
#endif
for_each_node_by_name(np, "ch-a")
initial_serial_shutdown(np);
of_node_put(np);
for_each_node_by_name(np, "ch-b")
initial_serial_shutdown(np);
of_node_put(np);
}
void __init
pmac_feature_init(void)
{
probe_uninorth();
if (probe_macios()) {
printk(KERN_WARNING "No mac-io chip found\n");
return;
}
if (probe_motherboard())
printk(KERN_WARNING "Unknown PowerMac !\n");
set_initial_features();
}
void pmac_set_early_video_resume(void (*proc)(void *data), void *data)
{
if (!machine_is(powermac))
return;
preempt_disable();
pmac_early_vresume_proc = proc;
pmac_early_vresume_data = data;
preempt_enable();
}
void pmac_call_early_video_resume(void)
{
if (pmac_early_vresume_proc)
pmac_early_vresume_proc(pmac_early_vresume_data);
}
void pmac_register_agp_pm(struct pci_dev *bridge,
int (*suspend)(struct pci_dev *bridge),
int (*resume)(struct pci_dev *bridge))
{
if (suspend || resume) {
pmac_agp_bridge = bridge;
pmac_agp_suspend = suspend;
pmac_agp_resume = resume;
return;
}
if (bridge != pmac_agp_bridge)
return;
pmac_agp_suspend = pmac_agp_resume = NULL;
return;
}
void pmac_suspend_agp_for_card(struct pci_dev *dev)
{
if (pmac_agp_bridge == NULL || pmac_agp_suspend == NULL)
return;
if (pmac_agp_bridge->bus != dev->bus)
return;
pmac_agp_suspend(pmac_agp_bridge);
}
void pmac_resume_agp_for_card(struct pci_dev *dev)
{
if (pmac_agp_bridge == NULL || pmac_agp_resume == NULL)
return;
if (pmac_agp_bridge->bus != dev->bus)
return;
pmac_agp_resume(pmac_agp_bridge);
}
int pmac_get_uninorth_variant(void)
{
return uninorth_maj;
}
