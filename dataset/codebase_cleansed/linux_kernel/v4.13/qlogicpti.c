static inline void qlogicpti_enable_irqs(struct qlogicpti *qpti)
{
sbus_writew(SBUS_CTRL_ERIRQ | SBUS_CTRL_GENAB,
qpti->qregs + SBUS_CTRL);
}
static inline void qlogicpti_disable_irqs(struct qlogicpti *qpti)
{
sbus_writew(0, qpti->qregs + SBUS_CTRL);
}
static inline void set_sbus_cfg1(struct qlogicpti *qpti)
{
u16 val;
u8 bursts = qpti->bursts;
#if 0
if (sbus_can_burst64() && (bursts & DMA_BURST64)) {
val = (SBUS_CFG1_BENAB | SBUS_CFG1_B64);
} else
#endif
if (bursts & DMA_BURST32) {
val = (SBUS_CFG1_BENAB | SBUS_CFG1_B32);
} else if (bursts & DMA_BURST16) {
val = (SBUS_CFG1_BENAB | SBUS_CFG1_B16);
} else if (bursts & DMA_BURST8) {
val = (SBUS_CFG1_BENAB | SBUS_CFG1_B8);
} else {
val = 0;
}
sbus_writew(val, qpti->qregs + SBUS_CFG1);
}
static int qlogicpti_mbox_command(struct qlogicpti *qpti, u_short param[], int force)
{
int loop_count;
u16 tmp;
if (mbox_param[param[0]] == 0)
return 1;
tmp = sbus_readw(qpti->qregs + SBUS_SEMAPHORE);
tmp |= SBUS_SEMAPHORE_LCK;
sbus_writew(tmp, qpti->qregs + SBUS_SEMAPHORE);
loop_count = DEFAULT_LOOP_COUNT;
while (--loop_count && (sbus_readw(qpti->qregs + HCCTRL) & HCCTRL_HIRQ)) {
barrier();
cpu_relax();
}
if (!loop_count)
printk(KERN_EMERG "qlogicpti%d: mbox_command loop timeout #1\n",
qpti->qpti_id);
switch (mbox_param[param[0]] >> 4) {
case 6: sbus_writew(param[5], qpti->qregs + MBOX5);
case 5: sbus_writew(param[4], qpti->qregs + MBOX4);
case 4: sbus_writew(param[3], qpti->qregs + MBOX3);
case 3: sbus_writew(param[2], qpti->qregs + MBOX2);
case 2: sbus_writew(param[1], qpti->qregs + MBOX1);
case 1: sbus_writew(param[0], qpti->qregs + MBOX0);
}
tmp = sbus_readw(qpti->qregs + HCCTRL);
tmp |= HCCTRL_CRIRQ;
sbus_writew(tmp, qpti->qregs + HCCTRL);
sbus_writew(0, qpti->qregs + SBUS_SEMAPHORE);
tmp = sbus_readw(qpti->qregs + HCCTRL);
tmp |= HCCTRL_SHIRQ;
sbus_writew(tmp, qpti->qregs + HCCTRL);
loop_count = DEFAULT_LOOP_COUNT;
while (--loop_count &&
(sbus_readw(qpti->qregs + HCCTRL) & HCCTRL_CRIRQ))
udelay(20);
if (!loop_count)
printk(KERN_EMERG "qlogicpti%d: mbox_command[%04x] loop timeout #2\n",
qpti->qpti_id, param[0]);
loop_count = DEFAULT_LOOP_COUNT;
while (--loop_count &&
!(sbus_readw(qpti->qregs + SBUS_SEMAPHORE) & SBUS_SEMAPHORE_LCK)) {
udelay(20);
if (sbus_readw(qpti->qregs + MBOX0) & 0x4000)
break;
}
if (!loop_count)
printk(KERN_EMERG "qlogicpti%d: mbox_command[%04x] loop timeout #3\n",
qpti->qpti_id, param[0]);
loop_count = DEFAULT_LOOP_COUNT;
while (--loop_count && (sbus_readw(qpti->qregs + MBOX0) == 0x04))
udelay(20);
if (!loop_count)
printk(KERN_EMERG "qlogicpti%d: mbox_command[%04x] loop timeout #4\n",
qpti->qpti_id, param[0]);
switch (mbox_param[param[0]] & 0xf) {
case 6: param[5] = sbus_readw(qpti->qregs + MBOX5);
case 5: param[4] = sbus_readw(qpti->qregs + MBOX4);
case 4: param[3] = sbus_readw(qpti->qregs + MBOX3);
case 3: param[2] = sbus_readw(qpti->qregs + MBOX2);
case 2: param[1] = sbus_readw(qpti->qregs + MBOX1);
case 1: param[0] = sbus_readw(qpti->qregs + MBOX0);
}
tmp = sbus_readw(qpti->qregs + HCCTRL);
tmp |= HCCTRL_CRIRQ;
sbus_writew(tmp, qpti->qregs + HCCTRL);
tmp = sbus_readw(qpti->qregs + SBUS_SEMAPHORE);
tmp &= ~(SBUS_SEMAPHORE_LCK);
sbus_writew(tmp, qpti->qregs + SBUS_SEMAPHORE);
return 0;
}
static inline void qlogicpti_set_hostdev_defaults(struct qlogicpti *qpti)
{
int i;
qpti->host_param.initiator_scsi_id = qpti->scsi_id;
qpti->host_param.bus_reset_delay = 3;
qpti->host_param.retry_count = 0;
qpti->host_param.retry_delay = 5;
qpti->host_param.async_data_setup_time = 3;
qpti->host_param.req_ack_active_negation = 1;
qpti->host_param.data_line_active_negation = 1;
qpti->host_param.data_dma_burst_enable = 1;
qpti->host_param.command_dma_burst_enable = 1;
qpti->host_param.tag_aging = 8;
qpti->host_param.selection_timeout = 250;
qpti->host_param.max_queue_depth = 256;
for(i = 0; i < MAX_TARGETS; i++) {
qpti->dev_param[i].device_flags = 0xcd;
qpti->dev_param[i].execution_throttle = 16;
if (qpti->ultra) {
qpti->dev_param[i].synchronous_period = 12;
qpti->dev_param[i].synchronous_offset = 8;
} else {
qpti->dev_param[i].synchronous_period = 25;
qpti->dev_param[i].synchronous_offset = 12;
}
qpti->dev_param[i].device_enable = 1;
}
}
static int qlogicpti_reset_hardware(struct Scsi_Host *host)
{
struct qlogicpti *qpti = (struct qlogicpti *) host->hostdata;
u_short param[6];
unsigned short risc_code_addr;
int loop_count, i;
unsigned long flags;
risc_code_addr = 0x1000;
spin_lock_irqsave(host->host_lock, flags);
sbus_writew(HCCTRL_PAUSE, qpti->qregs + HCCTRL);
if (sbus_readw(qpti->qregs + CPU_PCTRL) & CPU_PCTRL_BSY) {
sbus_writew(CPU_ORIDE_RMOD, qpti->qregs + CPU_ORIDE);
sbus_writew(CPU_CMD_BRESET, qpti->qregs + CPU_CMD);
udelay(400);
}
sbus_writew(SBUS_CTRL_RESET, qpti->qregs + SBUS_CTRL);
sbus_writew((DMA_CTRL_CCLEAR | DMA_CTRL_CIRQ), qpti->qregs + CMD_DMA_CTRL);
sbus_writew((DMA_CTRL_CCLEAR | DMA_CTRL_CIRQ), qpti->qregs + DATA_DMA_CTRL);
loop_count = DEFAULT_LOOP_COUNT;
while (--loop_count && ((sbus_readw(qpti->qregs + MBOX0) & 0xff) == 0x04))
udelay(20);
if (!loop_count)
printk(KERN_EMERG "qlogicpti%d: reset_hardware loop timeout\n",
qpti->qpti_id);
sbus_writew(HCCTRL_PAUSE, qpti->qregs + HCCTRL);
set_sbus_cfg1(qpti);
qlogicpti_enable_irqs(qpti);
if (sbus_readw(qpti->qregs + RISC_PSR) & RISC_PSR_ULTRA) {
qpti->ultra = 1;
sbus_writew((RISC_MTREG_P0ULTRA | RISC_MTREG_P1ULTRA),
qpti->qregs + RISC_MTREG);
} else {
qpti->ultra = 0;
sbus_writew((RISC_MTREG_P0DFLT | RISC_MTREG_P1DFLT),
qpti->qregs + RISC_MTREG);
}
qlogicpti_set_hostdev_defaults(qpti);
sbus_writew(HCCTRL_REL, qpti->qregs + HCCTRL);
param[0] = MBOX_EXEC_FIRMWARE;
param[1] = risc_code_addr;
if (qlogicpti_mbox_command(qpti, param, 1)) {
printk(KERN_EMERG "qlogicpti%d: Cannot execute ISP firmware.\n",
qpti->qpti_id);
spin_unlock_irqrestore(host->host_lock, flags);
return 1;
}
param[0] = MBOX_SET_INIT_SCSI_ID;
param[1] = qpti->host_param.initiator_scsi_id;
if (qlogicpti_mbox_command(qpti, param, 1) ||
(param[0] != MBOX_COMMAND_COMPLETE)) {
printk(KERN_EMERG "qlogicpti%d: Cannot set initiator SCSI ID.\n",
qpti->qpti_id);
spin_unlock_irqrestore(host->host_lock, flags);
return 1;
}
qpti->req_in_ptr = qpti->res_out_ptr = 0;
param[0] = MBOX_INIT_RES_QUEUE;
param[1] = RES_QUEUE_LEN + 1;
param[2] = (u_short) (qpti->res_dvma >> 16);
param[3] = (u_short) (qpti->res_dvma & 0xffff);
param[4] = param[5] = 0;
if (qlogicpti_mbox_command(qpti, param, 1)) {
printk(KERN_EMERG "qlogicpti%d: Cannot init response queue.\n",
qpti->qpti_id);
spin_unlock_irqrestore(host->host_lock, flags);
return 1;
}
param[0] = MBOX_INIT_REQ_QUEUE;
param[1] = QLOGICPTI_REQ_QUEUE_LEN + 1;
param[2] = (u_short) (qpti->req_dvma >> 16);
param[3] = (u_short) (qpti->req_dvma & 0xffff);
param[4] = param[5] = 0;
if (qlogicpti_mbox_command(qpti, param, 1)) {
printk(KERN_EMERG "qlogicpti%d: Cannot init request queue.\n",
qpti->qpti_id);
spin_unlock_irqrestore(host->host_lock, flags);
return 1;
}
param[0] = MBOX_SET_RETRY_COUNT;
param[1] = qpti->host_param.retry_count;
param[2] = qpti->host_param.retry_delay;
qlogicpti_mbox_command(qpti, param, 0);
param[0] = MBOX_SET_TAG_AGE_LIMIT;
param[1] = qpti->host_param.tag_aging;
qlogicpti_mbox_command(qpti, param, 0);
for (i = 0; i < MAX_TARGETS; i++) {
param[0] = MBOX_GET_DEV_QUEUE_PARAMS;
param[1] = (i << 8);
qlogicpti_mbox_command(qpti, param, 0);
}
param[0] = MBOX_GET_FIRMWARE_STATUS;
qlogicpti_mbox_command(qpti, param, 0);
param[0] = MBOX_SET_SELECT_TIMEOUT;
param[1] = qpti->host_param.selection_timeout;
qlogicpti_mbox_command(qpti, param, 0);
for (i = 0; i < MAX_TARGETS; i++) {
param[0] = MBOX_SET_TARGET_PARAMS;
param[1] = (i << 8);
param[2] = (qpti->dev_param[i].device_flags << 8);
param[2] |= 0xc0;
param[3] = 0;
qlogicpti_mbox_command(qpti, param, 0);
}
param[0] = MBOX_BUS_RESET;
param[1] = qpti->host_param.bus_reset_delay;
qlogicpti_mbox_command(qpti, param, 0);
qpti->send_marker = 1;
spin_unlock_irqrestore(host->host_lock, flags);
return 0;
}
static int qlogicpti_load_firmware(struct qlogicpti *qpti)
{
const struct firmware *fw;
const char fwname[] = "qlogic/isp1000.bin";
const __le16 *fw_data;
struct Scsi_Host *host = qpti->qhost;
unsigned short csum = 0;
unsigned short param[6];
unsigned short risc_code_addr, risc_code_length;
int err;
unsigned long flags;
int i, timeout;
err = request_firmware(&fw, fwname, &qpti->op->dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fwname, err);
return err;
}
if (fw->size % 2) {
printk(KERN_ERR "Bogus length %zu in image \"%s\"\n",
fw->size, fwname);
err = -EINVAL;
goto outfirm;
}
fw_data = (const __le16 *)&fw->data[0];
risc_code_addr = 0x1000;
risc_code_length = fw->size / 2;
spin_lock_irqsave(host->host_lock, flags);
for (i = 0; i < risc_code_length; i++)
csum += __le16_to_cpu(fw_data[i]);
if (csum) {
printk(KERN_EMERG "qlogicpti%d: Aieee, firmware checksum failed!",
qpti->qpti_id);
err = 1;
goto out;
}
sbus_writew(SBUS_CTRL_RESET, qpti->qregs + SBUS_CTRL);
sbus_writew((DMA_CTRL_CCLEAR | DMA_CTRL_CIRQ), qpti->qregs + CMD_DMA_CTRL);
sbus_writew((DMA_CTRL_CCLEAR | DMA_CTRL_CIRQ), qpti->qregs + DATA_DMA_CTRL);
timeout = PTI_RESET_LIMIT;
while (--timeout && (sbus_readw(qpti->qregs + SBUS_CTRL) & SBUS_CTRL_RESET))
udelay(20);
if (!timeout) {
printk(KERN_EMERG "qlogicpti%d: Cannot reset the ISP.", qpti->qpti_id);
err = 1;
goto out;
}
sbus_writew(HCCTRL_RESET, qpti->qregs + HCCTRL);
mdelay(1);
sbus_writew((SBUS_CTRL_GENAB | SBUS_CTRL_ERIRQ), qpti->qregs + SBUS_CTRL);
set_sbus_cfg1(qpti);
sbus_writew(0, qpti->qregs + SBUS_SEMAPHORE);
if (sbus_readw(qpti->qregs + RISC_PSR) & RISC_PSR_ULTRA) {
qpti->ultra = 1;
sbus_writew((RISC_MTREG_P0ULTRA | RISC_MTREG_P1ULTRA),
qpti->qregs + RISC_MTREG);
} else {
qpti->ultra = 0;
sbus_writew((RISC_MTREG_P0DFLT | RISC_MTREG_P1DFLT),
qpti->qregs + RISC_MTREG);
}
sbus_writew(HCCTRL_REL, qpti->qregs + HCCTRL);
sbus_writew(HCCTRL_PAUSE, qpti->qregs + HCCTRL);
if (sbus_readw(qpti->qregs + CPU_PDIFF) & CPU_PDIFF_MODE)
qpti->differential = 1;
else
qpti->differential = 0;
sbus_writew(HCCTRL_REL, qpti->qregs + HCCTRL);
param[0] = MBOX_STOP_FIRMWARE;
param[1] = param[2] = param[3] = param[4] = param[5] = 0;
if (qlogicpti_mbox_command(qpti, param, 1)) {
printk(KERN_EMERG "qlogicpti%d: Cannot stop firmware for reload.\n",
qpti->qpti_id);
err = 1;
goto out;
}
for (i = 0; i < risc_code_length; i++) {
param[0] = MBOX_WRITE_RAM_WORD;
param[1] = risc_code_addr + i;
param[2] = __le16_to_cpu(fw_data[i]);
if (qlogicpti_mbox_command(qpti, param, 1) ||
param[0] != MBOX_COMMAND_COMPLETE) {
printk("qlogicpti%d: Firmware dload failed, I'm bolixed!\n",
qpti->qpti_id);
err = 1;
goto out;
}
}
sbus_writew(HCCTRL_RESET, qpti->qregs + HCCTRL);
mdelay(1);
qlogicpti_enable_irqs(qpti);
sbus_writew(0, qpti->qregs + SBUS_SEMAPHORE);
sbus_writew(HCCTRL_REL, qpti->qregs + HCCTRL);
param[0] = MBOX_VERIFY_CHECKSUM;
param[1] = risc_code_addr;
if (qlogicpti_mbox_command(qpti, param, 1) ||
(param[0] != MBOX_COMMAND_COMPLETE)) {
printk(KERN_EMERG "qlogicpti%d: New firmware csum failure!\n",
qpti->qpti_id);
err = 1;
goto out;
}
param[0] = MBOX_EXEC_FIRMWARE;
param[1] = risc_code_addr;
qlogicpti_mbox_command(qpti, param, 1);
param[0] = MBOX_ABOUT_FIRMWARE;
if (qlogicpti_mbox_command(qpti, param, 1) ||
(param[0] != MBOX_COMMAND_COMPLETE)) {
printk(KERN_EMERG "qlogicpti%d: AboutFirmware cmd fails.\n",
qpti->qpti_id);
err = 1;
goto out;
}
qpti->fware_majrev = param[1];
qpti->fware_minrev = param[2];
qpti->fware_micrev = param[3];
param[0] = MBOX_SET_CLOCK_RATE;
param[1] = qpti->clock;
if (qlogicpti_mbox_command(qpti, param, 1) ||
(param[0] != MBOX_COMMAND_COMPLETE)) {
printk(KERN_EMERG "qlogicpti%d: could not set clock rate.\n",
qpti->qpti_id);
err = 1;
goto out;
}
if (qpti->is_pti != 0) {
param[0] = MBOX_WRITE_RAM_WORD;
param[1] = 0xff80;
param[2] = (unsigned short) qpti->scsi_id;
qlogicpti_mbox_command(qpti, param, 1);
param[0] = MBOX_WRITE_RAM_WORD;
param[1] = 0xff00;
param[2] = (unsigned short) 3;
qlogicpti_mbox_command(qpti, param, 1);
}
out:
spin_unlock_irqrestore(host->host_lock, flags);
outfirm:
release_firmware(fw);
return err;
}
static int qlogicpti_verify_tmon(struct qlogicpti *qpti)
{
int curstat = sbus_readb(qpti->sreg);
curstat &= 0xf0;
if (!(curstat & SREG_FUSE) && (qpti->swsreg & SREG_FUSE))
printk("qlogicpti%d: Fuse returned to normal state.\n", qpti->qpti_id);
if (!(curstat & SREG_TPOWER) && (qpti->swsreg & SREG_TPOWER))
printk("qlogicpti%d: termpwr back to normal state.\n", qpti->qpti_id);
if (curstat != qpti->swsreg) {
int error = 0;
if (curstat & SREG_FUSE) {
error++;
printk("qlogicpti%d: Fuse is open!\n", qpti->qpti_id);
}
if (curstat & SREG_TPOWER) {
error++;
printk("qlogicpti%d: termpwr failure\n", qpti->qpti_id);
}
if (qpti->differential &&
(curstat & SREG_DSENSE) != SREG_DSENSE) {
error++;
printk("qlogicpti%d: You have a single ended device on a "
"differential bus! Please fix!\n", qpti->qpti_id);
}
qpti->swsreg = curstat;
return error;
}
return 0;
}
static void qpti_chain_add(struct qlogicpti *qpti)
{
spin_lock_irq(&qptichain_lock);
if (qptichain != NULL) {
struct qlogicpti *qlink = qptichain;
while(qlink->next)
qlink = qlink->next;
qlink->next = qpti;
} else {
qptichain = qpti;
}
qpti->next = NULL;
spin_unlock_irq(&qptichain_lock);
}
static void qpti_chain_del(struct qlogicpti *qpti)
{
spin_lock_irq(&qptichain_lock);
if (qptichain == qpti) {
qptichain = qpti->next;
} else {
struct qlogicpti *qlink = qptichain;
while(qlink->next != qpti)
qlink = qlink->next;
qlink->next = qpti->next;
}
qpti->next = NULL;
spin_unlock_irq(&qptichain_lock);
}
static int qpti_map_regs(struct qlogicpti *qpti)
{
struct platform_device *op = qpti->op;
qpti->qregs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]),
"PTI Qlogic/ISP");
if (!qpti->qregs) {
printk("PTI: Qlogic/ISP registers are unmappable\n");
return -ENODEV;
}
if (qpti->is_pti) {
qpti->sreg = of_ioremap(&op->resource[0], (16 * 4096),
sizeof(unsigned char),
"PTI Qlogic/ISP statreg");
if (!qpti->sreg) {
printk("PTI: Qlogic/ISP status register is unmappable\n");
return -ENODEV;
}
}
return 0;
}
static int qpti_register_irq(struct qlogicpti *qpti)
{
struct platform_device *op = qpti->op;
qpti->qhost->irq = qpti->irq = op->archdata.irqs[0];
if (request_irq(qpti->irq, qpti_intr,
IRQF_SHARED, "QlogicPTI", qpti))
goto fail;
printk("qlogicpti%d: IRQ %d ", qpti->qpti_id, qpti->irq);
return 0;
fail:
printk("qlogicpti%d: Cannot acquire irq line\n", qpti->qpti_id);
return -1;
}
static void qpti_get_scsi_id(struct qlogicpti *qpti)
{
struct platform_device *op = qpti->op;
struct device_node *dp;
dp = op->dev.of_node;
qpti->scsi_id = of_getintprop_default(dp, "initiator-id", -1);
if (qpti->scsi_id == -1)
qpti->scsi_id = of_getintprop_default(dp, "scsi-initiator-id",
-1);
if (qpti->scsi_id == -1)
qpti->scsi_id =
of_getintprop_default(dp->parent,
"scsi-initiator-id", 7);
qpti->qhost->this_id = qpti->scsi_id;
qpti->qhost->max_sectors = 64;
printk("SCSI ID %d ", qpti->scsi_id);
}
static void qpti_get_bursts(struct qlogicpti *qpti)
{
struct platform_device *op = qpti->op;
u8 bursts, bmask;
bursts = of_getintprop_default(op->dev.of_node, "burst-sizes", 0xff);
bmask = of_getintprop_default(op->dev.of_node->parent, "burst-sizes", 0xff);
if (bmask != 0xff)
bursts &= bmask;
if (bursts == 0xff ||
(bursts & DMA_BURST16) == 0 ||
(bursts & DMA_BURST32) == 0)
bursts = (DMA_BURST32 - 1);
qpti->bursts = bursts;
}
static void qpti_get_clock(struct qlogicpti *qpti)
{
unsigned int cfreq;
cfreq = prom_getintdefault(qpti->prom_node,"clock-frequency",40000000);
qpti->clock = (cfreq + 500000)/1000000;
if (qpti->clock == 0)
qpti->clock = 40;
}
static int qpti_map_queues(struct qlogicpti *qpti)
{
struct platform_device *op = qpti->op;
#define QSIZE(entries) (((entries) + 1) * QUEUE_ENTRY_LEN)
qpti->res_cpu = dma_alloc_coherent(&op->dev,
QSIZE(RES_QUEUE_LEN),
&qpti->res_dvma, GFP_ATOMIC);
if (qpti->res_cpu == NULL ||
qpti->res_dvma == 0) {
printk("QPTI: Cannot map response queue.\n");
return -1;
}
qpti->req_cpu = dma_alloc_coherent(&op->dev,
QSIZE(QLOGICPTI_REQ_QUEUE_LEN),
&qpti->req_dvma, GFP_ATOMIC);
if (qpti->req_cpu == NULL ||
qpti->req_dvma == 0) {
dma_free_coherent(&op->dev, QSIZE(RES_QUEUE_LEN),
qpti->res_cpu, qpti->res_dvma);
printk("QPTI: Cannot map request queue.\n");
return -1;
}
memset(qpti->res_cpu, 0, QSIZE(RES_QUEUE_LEN));
memset(qpti->req_cpu, 0, QSIZE(QLOGICPTI_REQ_QUEUE_LEN));
return 0;
}
const char *qlogicpti_info(struct Scsi_Host *host)
{
static char buf[80];
struct qlogicpti *qpti = (struct qlogicpti *) host->hostdata;
sprintf(buf, "PTI Qlogic,ISP SBUS SCSI irq %d regs at %p",
qpti->qhost->irq, qpti->qregs);
return buf;
}
static inline void marker_frob(struct Command_Entry *cmd)
{
struct Marker_Entry *marker = (struct Marker_Entry *) cmd;
memset(marker, 0, sizeof(struct Marker_Entry));
marker->hdr.entry_cnt = 1;
marker->hdr.entry_type = ENTRY_MARKER;
marker->modifier = SYNC_ALL;
marker->rsvd = 0;
}
static inline void cmd_frob(struct Command_Entry *cmd, struct scsi_cmnd *Cmnd,
struct qlogicpti *qpti)
{
memset(cmd, 0, sizeof(struct Command_Entry));
cmd->hdr.entry_cnt = 1;
cmd->hdr.entry_type = ENTRY_COMMAND;
cmd->target_id = Cmnd->device->id;
cmd->target_lun = Cmnd->device->lun;
cmd->cdb_length = Cmnd->cmd_len;
cmd->control_flags = 0;
if (Cmnd->device->tagged_supported) {
if (qpti->cmd_count[Cmnd->device->id] == 0)
qpti->tag_ages[Cmnd->device->id] = jiffies;
if (time_after(jiffies, qpti->tag_ages[Cmnd->device->id] + (5*HZ))) {
cmd->control_flags = CFLAG_ORDERED_TAG;
qpti->tag_ages[Cmnd->device->id] = jiffies;
} else
cmd->control_flags = CFLAG_SIMPLE_TAG;
}
if ((Cmnd->cmnd[0] == WRITE_6) ||
(Cmnd->cmnd[0] == WRITE_10) ||
(Cmnd->cmnd[0] == WRITE_12))
cmd->control_flags |= CFLAG_WRITE;
else
cmd->control_flags |= CFLAG_READ;
cmd->time_out = Cmnd->request->timeout/HZ;
memcpy(cmd->cdb, Cmnd->cmnd, Cmnd->cmd_len);
}
static inline int load_cmd(struct scsi_cmnd *Cmnd, struct Command_Entry *cmd,
struct qlogicpti *qpti, u_int in_ptr, u_int out_ptr)
{
struct dataseg *ds;
struct scatterlist *sg, *s;
int i, n;
if (scsi_bufflen(Cmnd)) {
int sg_count;
sg = scsi_sglist(Cmnd);
sg_count = dma_map_sg(&qpti->op->dev, sg,
scsi_sg_count(Cmnd),
Cmnd->sc_data_direction);
ds = cmd->dataseg;
cmd->segment_cnt = sg_count;
n = sg_count;
if (n > 4)
n = 4;
for_each_sg(sg, s, n, i) {
ds[i].d_base = sg_dma_address(s);
ds[i].d_count = sg_dma_len(s);
}
sg_count -= 4;
sg = s;
while (sg_count > 0) {
struct Continuation_Entry *cont;
++cmd->hdr.entry_cnt;
cont = (struct Continuation_Entry *) &qpti->req_cpu[in_ptr];
in_ptr = NEXT_REQ_PTR(in_ptr);
if (in_ptr == out_ptr)
return -1;
cont->hdr.entry_type = ENTRY_CONTINUATION;
cont->hdr.entry_cnt = 0;
cont->hdr.sys_def_1 = 0;
cont->hdr.flags = 0;
cont->reserved = 0;
ds = cont->dataseg;
n = sg_count;
if (n > 7)
n = 7;
for_each_sg(sg, s, n, i) {
ds[i].d_base = sg_dma_address(s);
ds[i].d_count = sg_dma_len(s);
}
sg_count -= n;
sg = s;
}
} else {
cmd->dataseg[0].d_base = 0;
cmd->dataseg[0].d_count = 0;
cmd->segment_cnt = 1;
}
cmd->handle = in_ptr;
qpti->cmd_slots[in_ptr] = Cmnd;
qpti->cmd_count[Cmnd->device->id]++;
sbus_writew(in_ptr, qpti->qregs + MBOX4);
qpti->req_in_ptr = in_ptr;
return in_ptr;
}
static inline void update_can_queue(struct Scsi_Host *host, u_int in_ptr, u_int out_ptr)
{
int num_free = QLOGICPTI_REQ_QUEUE_LEN - REQ_QUEUE_DEPTH(in_ptr, out_ptr) - 64;
host->can_queue = atomic_read(&host->host_busy) + num_free;
host->sg_tablesize = QLOGICPTI_MAX_SG(num_free);
}
static int qlogicpti_slave_configure(struct scsi_device *sdev)
{
struct qlogicpti *qpti = shost_priv(sdev->host);
int tgt = sdev->id;
u_short param[6];
if (sdev->sdtr) {
qpti->dev_param[tgt].device_flags |= 0x10;
} else {
qpti->dev_param[tgt].synchronous_offset = 0;
qpti->dev_param[tgt].synchronous_period = 0;
}
if (sdev->wdtr)
qpti->dev_param[tgt].device_flags |= 0x20;
param[0] = MBOX_SET_TARGET_PARAMS;
param[1] = (tgt << 8);
param[2] = (qpti->dev_param[tgt].device_flags << 8);
if (qpti->dev_param[tgt].device_flags & 0x10) {
param[3] = (qpti->dev_param[tgt].synchronous_offset << 8) |
qpti->dev_param[tgt].synchronous_period;
} else {
param[3] = 0;
}
qlogicpti_mbox_command(qpti, param, 0);
return 0;
}
static int qlogicpti_queuecommand_lck(struct scsi_cmnd *Cmnd, void (*done)(struct scsi_cmnd *))
{
struct Scsi_Host *host = Cmnd->device->host;
struct qlogicpti *qpti = (struct qlogicpti *) host->hostdata;
struct Command_Entry *cmd;
u_int out_ptr;
int in_ptr;
Cmnd->scsi_done = done;
in_ptr = qpti->req_in_ptr;
cmd = (struct Command_Entry *) &qpti->req_cpu[in_ptr];
out_ptr = sbus_readw(qpti->qregs + MBOX4);
in_ptr = NEXT_REQ_PTR(in_ptr);
if (in_ptr == out_ptr)
goto toss_command;
if (qpti->send_marker) {
marker_frob(cmd);
qpti->send_marker = 0;
if (NEXT_REQ_PTR(in_ptr) == out_ptr) {
sbus_writew(in_ptr, qpti->qregs + MBOX4);
qpti->req_in_ptr = in_ptr;
goto toss_command;
}
cmd = (struct Command_Entry *) &qpti->req_cpu[in_ptr];
in_ptr = NEXT_REQ_PTR(in_ptr);
}
cmd_frob(cmd, Cmnd, qpti);
if ((in_ptr = load_cmd(Cmnd, cmd, qpti, in_ptr, out_ptr)) == -1)
goto toss_command;
update_can_queue(host, in_ptr, out_ptr);
return 0;
toss_command:
printk(KERN_EMERG "qlogicpti%d: request queue overflow\n",
qpti->qpti_id);
Cmnd->result = DID_BUS_BUSY;
done(Cmnd);
return 1;
}
struct scsi_cmnd *qlogicpti_intr_handler(struct qlogicpti *qpti)
{
struct scsi_cmnd *Cmnd, *done_queue = NULL;
struct Status_Entry *sts;
u_int in_ptr, out_ptr;
if (!(sbus_readw(qpti->qregs + SBUS_STAT) & SBUS_STAT_RINT))
return NULL;
in_ptr = sbus_readw(qpti->qregs + MBOX5);
sbus_writew(HCCTRL_CRIRQ, qpti->qregs + HCCTRL);
if (sbus_readw(qpti->qregs + SBUS_SEMAPHORE) & SBUS_SEMAPHORE_LCK) {
switch (sbus_readw(qpti->qregs + MBOX0)) {
case ASYNC_SCSI_BUS_RESET:
case EXECUTION_TIMEOUT_RESET:
qpti->send_marker = 1;
break;
case INVALID_COMMAND:
case HOST_INTERFACE_ERROR:
case COMMAND_ERROR:
case COMMAND_PARAM_ERROR:
break;
};
sbus_writew(0, qpti->qregs + SBUS_SEMAPHORE);
}
out_ptr = qpti->res_out_ptr;
while (out_ptr != in_ptr) {
u_int cmd_slot;
sts = (struct Status_Entry *) &qpti->res_cpu[out_ptr];
out_ptr = NEXT_RES_PTR(out_ptr);
cmd_slot = sts->handle;
Cmnd = qpti->cmd_slots[cmd_slot];
qpti->cmd_slots[cmd_slot] = NULL;
if (sts->completion_status == CS_RESET_OCCURRED ||
sts->completion_status == CS_ABORTED ||
(sts->status_flags & STF_BUS_RESET))
qpti->send_marker = 1;
if (sts->state_flags & SF_GOT_SENSE)
memcpy(Cmnd->sense_buffer, sts->req_sense_data,
SCSI_SENSE_BUFFERSIZE);
if (sts->hdr.entry_type == ENTRY_STATUS)
Cmnd->result =
qlogicpti_return_status(sts, qpti->qpti_id);
else
Cmnd->result = DID_ERROR << 16;
if (scsi_bufflen(Cmnd))
dma_unmap_sg(&qpti->op->dev,
scsi_sglist(Cmnd), scsi_sg_count(Cmnd),
Cmnd->sc_data_direction);
qpti->cmd_count[Cmnd->device->id]--;
sbus_writew(out_ptr, qpti->qregs + MBOX5);
Cmnd->host_scribble = (unsigned char *) done_queue;
done_queue = Cmnd;
}
qpti->res_out_ptr = out_ptr;
return done_queue;
}
static irqreturn_t qpti_intr(int irq, void *dev_id)
{
struct qlogicpti *qpti = dev_id;
unsigned long flags;
struct scsi_cmnd *dq;
spin_lock_irqsave(qpti->qhost->host_lock, flags);
dq = qlogicpti_intr_handler(qpti);
if (dq != NULL) {
do {
struct scsi_cmnd *next;
next = (struct scsi_cmnd *) dq->host_scribble;
dq->scsi_done(dq);
dq = next;
} while (dq != NULL);
}
spin_unlock_irqrestore(qpti->qhost->host_lock, flags);
return IRQ_HANDLED;
}
static int qlogicpti_abort(struct scsi_cmnd *Cmnd)
{
u_short param[6];
struct Scsi_Host *host = Cmnd->device->host;
struct qlogicpti *qpti = (struct qlogicpti *) host->hostdata;
int return_status = SUCCESS;
u32 cmd_cookie;
int i;
printk(KERN_WARNING "qlogicpti%d: Aborting cmd for tgt[%d] lun[%d]\n",
qpti->qpti_id, (int)Cmnd->device->id, (int)Cmnd->device->lun);
qlogicpti_disable_irqs(qpti);
for (i = 0; i < QLOGICPTI_REQ_QUEUE_LEN + 1; i++)
if (qpti->cmd_slots[i] == Cmnd)
break;
cmd_cookie = i;
param[0] = MBOX_ABORT;
param[1] = (((u_short) Cmnd->device->id) << 8) | Cmnd->device->lun;
param[2] = cmd_cookie >> 16;
param[3] = cmd_cookie & 0xffff;
if (qlogicpti_mbox_command(qpti, param, 0) ||
(param[0] != MBOX_COMMAND_COMPLETE)) {
printk(KERN_EMERG "qlogicpti%d: scsi abort failure: %x\n",
qpti->qpti_id, param[0]);
return_status = FAILED;
}
qlogicpti_enable_irqs(qpti);
return return_status;
}
static int qlogicpti_reset(struct scsi_cmnd *Cmnd)
{
u_short param[6];
struct Scsi_Host *host = Cmnd->device->host;
struct qlogicpti *qpti = (struct qlogicpti *) host->hostdata;
int return_status = SUCCESS;
printk(KERN_WARNING "qlogicpti%d: Resetting SCSI bus!\n",
qpti->qpti_id);
qlogicpti_disable_irqs(qpti);
param[0] = MBOX_BUS_RESET;
param[1] = qpti->host_param.bus_reset_delay;
if (qlogicpti_mbox_command(qpti, param, 0) ||
(param[0] != MBOX_COMMAND_COMPLETE)) {
printk(KERN_EMERG "qlogicisp%d: scsi bus reset failure: %x\n",
qpti->qpti_id, param[0]);
return_status = FAILED;
}
qlogicpti_enable_irqs(qpti);
return return_status;
}
static int qpti_sbus_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct Scsi_Host *host;
struct qlogicpti *qpti;
static int nqptis;
const char *fcode;
if (op->archdata.irqs[0] == 0)
return -ENODEV;
host = scsi_host_alloc(&qpti_template, sizeof(struct qlogicpti));
if (!host)
return -ENOMEM;
qpti = shost_priv(host);
host->max_id = MAX_TARGETS;
qpti->qhost = host;
qpti->op = op;
qpti->qpti_id = nqptis;
strcpy(qpti->prom_name, op->dev.of_node->name);
qpti->is_pti = strcmp(qpti->prom_name, "QLGC,isp");
if (qpti_map_regs(qpti) < 0)
goto fail_unlink;
if (qpti_register_irq(qpti) < 0)
goto fail_unmap_regs;
qpti_get_scsi_id(qpti);
qpti_get_bursts(qpti);
qpti_get_clock(qpti);
memset(qpti->cmd_slots, 0, sizeof(qpti->cmd_slots));
if (qpti_map_queues(qpti) < 0)
goto fail_free_irq;
if (qlogicpti_load_firmware(qpti))
goto fail_unmap_queues;
if (qpti->is_pti) {
if (qlogicpti_verify_tmon(qpti))
goto fail_unmap_queues;
}
if (qlogicpti_reset_hardware(host))
goto fail_unmap_queues;
printk("(Firmware v%d.%d.%d)", qpti->fware_majrev,
qpti->fware_minrev, qpti->fware_micrev);
fcode = of_get_property(dp, "isp-fcode", NULL);
if (fcode && fcode[0])
printk("(FCode %s)", fcode);
if (of_find_property(dp, "differential", NULL) != NULL)
qpti->differential = 1;
printk("\nqlogicpti%d: [%s Wide, using %s interface]\n",
qpti->qpti_id,
(qpti->ultra ? "Ultra" : "Fast"),
(qpti->differential ? "differential" : "single ended"));
if (scsi_add_host(host, &op->dev)) {
printk("qlogicpti%d: Failed scsi_add_host\n", qpti->qpti_id);
goto fail_unmap_queues;
}
dev_set_drvdata(&op->dev, qpti);
qpti_chain_add(qpti);
scsi_scan_host(host);
nqptis++;
return 0;
fail_unmap_queues:
#define QSIZE(entries) (((entries) + 1) * QUEUE_ENTRY_LEN)
dma_free_coherent(&op->dev,
QSIZE(RES_QUEUE_LEN),
qpti->res_cpu, qpti->res_dvma);
dma_free_coherent(&op->dev,
QSIZE(QLOGICPTI_REQ_QUEUE_LEN),
qpti->req_cpu, qpti->req_dvma);
#undef QSIZE
fail_unmap_regs:
of_iounmap(&op->resource[0], qpti->qregs,
resource_size(&op->resource[0]));
if (qpti->is_pti)
of_iounmap(&op->resource[0], qpti->sreg,
sizeof(unsigned char));
fail_free_irq:
free_irq(qpti->irq, qpti);
fail_unlink:
scsi_host_put(host);
return -ENODEV;
}
static int qpti_sbus_remove(struct platform_device *op)
{
struct qlogicpti *qpti = dev_get_drvdata(&op->dev);
qpti_chain_del(qpti);
scsi_remove_host(qpti->qhost);
sbus_writew(0, qpti->qregs + SBUS_CTRL);
free_irq(qpti->irq, qpti);
#define QSIZE(entries) (((entries) + 1) * QUEUE_ENTRY_LEN)
dma_free_coherent(&op->dev,
QSIZE(RES_QUEUE_LEN),
qpti->res_cpu, qpti->res_dvma);
dma_free_coherent(&op->dev,
QSIZE(QLOGICPTI_REQ_QUEUE_LEN),
qpti->req_cpu, qpti->req_dvma);
#undef QSIZE
of_iounmap(&op->resource[0], qpti->qregs,
resource_size(&op->resource[0]));
if (qpti->is_pti)
of_iounmap(&op->resource[0], qpti->sreg, sizeof(unsigned char));
scsi_host_put(qpti->qhost);
return 0;
}
static int __init qpti_init(void)
{
return platform_driver_register(&qpti_sbus_driver);
}
static void __exit qpti_exit(void)
{
platform_driver_unregister(&qpti_sbus_driver);
}
