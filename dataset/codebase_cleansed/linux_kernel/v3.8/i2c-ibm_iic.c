static void dump_iic_regs(const char* header, struct ibm_iic_private* dev)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
printk(KERN_DEBUG "ibm-iic%d: %s\n", dev->idx, header);
printk(KERN_DEBUG
" cntl = 0x%02x, mdcntl = 0x%02x\n"
" sts = 0x%02x, extsts = 0x%02x\n"
" clkdiv = 0x%02x, xfrcnt = 0x%02x\n"
" xtcntlss = 0x%02x, directcntl = 0x%02x\n",
in_8(&iic->cntl), in_8(&iic->mdcntl), in_8(&iic->sts),
in_8(&iic->extsts), in_8(&iic->clkdiv), in_8(&iic->xfrcnt),
in_8(&iic->xtcntlss), in_8(&iic->directcntl));
}
static inline void iic_interrupt_mode(struct ibm_iic_private* dev, int enable)
{
out_8(&dev->vaddr->intmsk, enable ? INTRMSK_EIMTC : 0);
}
static void iic_dev_init(struct ibm_iic_private* dev)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
DBG("%d: init\n", dev->idx);
out_8(&iic->lmadr, 0);
out_8(&iic->hmadr, 0);
out_8(&iic->lsadr, 0);
out_8(&iic->hsadr, 0);
out_8(&iic->sts, STS_SCMP | STS_IRQA);
out_8(&iic->extsts, EXTSTS_IRQP | EXTSTS_IRQD | EXTSTS_LA
| EXTSTS_ICT | EXTSTS_XFRA);
out_8(&iic->clkdiv, dev->clckdiv);
out_8(&iic->xfrcnt, 0);
out_8(&iic->xtcntlss, XTCNTLSS_SRC | XTCNTLSS_SRS | XTCNTLSS_SWC
| XTCNTLSS_SWS);
out_8(&iic->cntl, 0);
iic_interrupt_mode(dev, dev->irq >= 0);
out_8(&iic->mdcntl, MDCNTL_FMDB | MDCNTL_EINT | MDCNTL_EUBS
| (dev->fast_mode ? MDCNTL_FSM : 0));
DUMP_REGS("iic_init", dev);
}
static void iic_dev_reset(struct ibm_iic_private* dev)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
int i;
u8 dc;
DBG("%d: soft reset\n", dev->idx);
DUMP_REGS("reset", dev);
out_8(&iic->xtcntlss, XTCNTLSS_SRST);
dc = in_8(&iic->directcntl);
if (!DIRCTNL_FREE(dc)){
DBG("%d: trying to regain bus control\n", dev->idx);
out_8(&iic->directcntl, DIRCNTL_SDAC | DIRCNTL_SCC);
for (i = 0; i < 100; ++i){
dc = in_8(&iic->directcntl);
if (DIRCTNL_FREE(dc))
break;
dc ^= DIRCNTL_SCC;
out_8(&iic->directcntl, dc);
udelay(10);
dc ^= DIRCNTL_SCC;
out_8(&iic->directcntl, dc);
cond_resched();
}
}
out_8(&iic->xtcntlss, 0);
iic_dev_init(dev);
}
static int iic_dc_wait(volatile struct iic_regs __iomem *iic, u8 mask)
{
unsigned long x = jiffies + HZ / 28 + 2;
while ((in_8(&iic->directcntl) & mask) != mask){
if (unlikely(time_after(jiffies, x)))
return -1;
cond_resched();
}
return 0;
}
static int iic_smbus_quick(struct ibm_iic_private* dev, const struct i2c_msg* p)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
const struct i2c_timings* t = &timings[dev->fast_mode ? 1 : 0];
u8 mask, v, sda;
int i, res;
if (unlikely(p->flags & I2C_M_TEN)){
DBG("%d: smbus_quick - 10 bit addresses are not supported\n",
dev->idx);
return -EINVAL;
}
DBG("%d: smbus_quick(0x%02x)\n", dev->idx, p->addr);
out_8(&iic->xtcntlss, XTCNTLSS_SRST);
out_8(&iic->directcntl, DIRCNTL_SDAC | DIRCNTL_SCC);
if (unlikely(iic_dc_wait(iic, DIRCNTL_MSDA | DIRCNTL_MSC)))
goto err;
ndelay(t->buf);
out_8(&iic->directcntl, DIRCNTL_SCC);
sda = 0;
ndelay(t->hd_sta);
v = (u8)((p->addr << 1) | ((p->flags & I2C_M_RD) ? 1 : 0));
for (i = 0, mask = 0x80; i < 8; ++i, mask >>= 1){
out_8(&iic->directcntl, sda);
ndelay(t->low / 2);
sda = (v & mask) ? DIRCNTL_SDAC : 0;
out_8(&iic->directcntl, sda);
ndelay(t->low / 2);
out_8(&iic->directcntl, DIRCNTL_SCC | sda);
if (unlikely(iic_dc_wait(iic, DIRCNTL_MSC)))
goto err;
ndelay(t->high);
}
out_8(&iic->directcntl, sda);
ndelay(t->low / 2);
out_8(&iic->directcntl, DIRCNTL_SDAC);
ndelay(t->low / 2);
out_8(&iic->directcntl, DIRCNTL_SDAC | DIRCNTL_SCC);
if (unlikely(iic_dc_wait(iic, DIRCNTL_MSC)))
goto err;
res = (in_8(&iic->directcntl) & DIRCNTL_MSDA) ? -EREMOTEIO : 1;
ndelay(t->high);
out_8(&iic->directcntl, 0);
ndelay(t->low);
out_8(&iic->directcntl, DIRCNTL_SCC);
if (unlikely(iic_dc_wait(iic, DIRCNTL_MSC)))
goto err;
ndelay(t->su_sto);
out_8(&iic->directcntl, DIRCNTL_SDAC | DIRCNTL_SCC);
ndelay(t->buf);
DBG("%d: smbus_quick -> %s\n", dev->idx, res ? "NACK" : "ACK");
out:
out_8(&iic->xtcntlss, 0);
iic_dev_init(dev);
return res;
err:
DBG("%d: smbus_quick - bus is stuck\n", dev->idx);
res = -EREMOTEIO;
goto out;
}
static irqreturn_t iic_handler(int irq, void *dev_id)
{
struct ibm_iic_private* dev = (struct ibm_iic_private*)dev_id;
volatile struct iic_regs __iomem *iic = dev->vaddr;
DBG2("%d: irq handler, STS = 0x%02x, EXTSTS = 0x%02x\n",
dev->idx, in_8(&iic->sts), in_8(&iic->extsts));
out_8(&iic->sts, STS_IRQA | STS_SCMP);
wake_up_interruptible(&dev->wq);
return IRQ_HANDLED;
}
static int iic_xfer_result(struct ibm_iic_private* dev)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
if (unlikely(in_8(&iic->sts) & STS_ERR)){
DBG("%d: xfer error, EXTSTS = 0x%02x\n", dev->idx,
in_8(&iic->extsts));
out_8(&iic->extsts, EXTSTS_IRQP | EXTSTS_IRQD |
EXTSTS_LA | EXTSTS_ICT | EXTSTS_XFRA);
out_8(&iic->mdcntl, in_8(&iic->mdcntl) | MDCNTL_FMDB);
if ((in_8(&iic->extsts) & EXTSTS_BCS_MASK) != EXTSTS_BCS_FREE){
DBG("%d: bus is stuck, resetting\n", dev->idx);
iic_dev_reset(dev);
}
return -EREMOTEIO;
}
else
return in_8(&iic->xfrcnt) & XFRCNT_MTC_MASK;
}
static void iic_abort_xfer(struct ibm_iic_private* dev)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
unsigned long x;
DBG("%d: iic_abort_xfer\n", dev->idx);
out_8(&iic->cntl, CNTL_HMT);
x = jiffies + 2;
while ((in_8(&iic->extsts) & EXTSTS_BCS_MASK) != EXTSTS_BCS_FREE){
if (time_after(jiffies, x)){
DBG("%d: abort timeout, resetting...\n", dev->idx);
iic_dev_reset(dev);
return;
}
schedule();
}
iic_xfer_result(dev);
}
static int iic_wait_for_tc(struct ibm_iic_private* dev){
volatile struct iic_regs __iomem *iic = dev->vaddr;
int ret = 0;
if (dev->irq >= 0){
ret = wait_event_interruptible_timeout(dev->wq,
!(in_8(&iic->sts) & STS_PT), dev->adap.timeout);
if (unlikely(ret < 0))
DBG("%d: wait interrupted\n", dev->idx);
else if (unlikely(in_8(&iic->sts) & STS_PT)){
DBG("%d: wait timeout\n", dev->idx);
ret = -ETIMEDOUT;
}
}
else {
unsigned long x = jiffies + dev->adap.timeout;
while (in_8(&iic->sts) & STS_PT){
if (unlikely(time_after(jiffies, x))){
DBG("%d: poll timeout\n", dev->idx);
ret = -ETIMEDOUT;
break;
}
if (unlikely(signal_pending(current))){
DBG("%d: poll interrupted\n", dev->idx);
ret = -ERESTARTSYS;
break;
}
schedule();
}
}
if (unlikely(ret < 0))
iic_abort_xfer(dev);
else
ret = iic_xfer_result(dev);
DBG2("%d: iic_wait_for_tc -> %d\n", dev->idx, ret);
return ret;
}
static int iic_xfer_bytes(struct ibm_iic_private* dev, struct i2c_msg* pm,
int combined_xfer)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
char* buf = pm->buf;
int i, j, loops, ret = 0;
int len = pm->len;
u8 cntl = (in_8(&iic->cntl) & CNTL_AMD) | CNTL_PT;
if (pm->flags & I2C_M_RD)
cntl |= CNTL_RW;
loops = (len + 3) / 4;
for (i = 0; i < loops; ++i, len -= 4){
int count = len > 4 ? 4 : len;
u8 cmd = cntl | ((count - 1) << CNTL_TCT_SHIFT);
if (!(cntl & CNTL_RW))
for (j = 0; j < count; ++j)
out_8((void __iomem *)&iic->mdbuf, *buf++);
if (i < loops - 1)
cmd |= CNTL_CHT;
else if (combined_xfer)
cmd |= CNTL_RPST;
DBG2("%d: xfer_bytes, %d, CNTL = 0x%02x\n", dev->idx, count, cmd);
out_8(&iic->cntl, cmd);
ret = iic_wait_for_tc(dev);
if (unlikely(ret < 0))
break;
else if (unlikely(ret != count)){
DBG("%d: xfer_bytes, requested %d, transferred %d\n",
dev->idx, count, ret);
if (combined_xfer || (i < loops - 1))
iic_abort_xfer(dev);
ret = -EREMOTEIO;
break;
}
if (cntl & CNTL_RW)
for (j = 0; j < count; ++j)
*buf++ = in_8((void __iomem *)&iic->mdbuf);
}
return ret > 0 ? 0 : ret;
}
static inline void iic_address(struct ibm_iic_private* dev, struct i2c_msg* msg)
{
volatile struct iic_regs __iomem *iic = dev->vaddr;
u16 addr = msg->addr;
DBG2("%d: iic_address, 0x%03x (%d-bit)\n", dev->idx,
addr, msg->flags & I2C_M_TEN ? 10 : 7);
if (msg->flags & I2C_M_TEN){
out_8(&iic->cntl, CNTL_AMD);
out_8(&iic->lmadr, addr);
out_8(&iic->hmadr, 0xf0 | ((addr >> 7) & 0x06));
}
else {
out_8(&iic->cntl, 0);
out_8(&iic->lmadr, addr << 1);
}
}
static inline int iic_invalid_address(const struct i2c_msg* p)
{
return (p->addr > 0x3ff) || (!(p->flags & I2C_M_TEN) && (p->addr > 0x7f));
}
static inline int iic_address_neq(const struct i2c_msg* p1,
const struct i2c_msg* p2)
{
return (p1->addr != p2->addr)
|| ((p1->flags & I2C_M_TEN) != (p2->flags & I2C_M_TEN));
}
static int iic_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct ibm_iic_private* dev = (struct ibm_iic_private*)(i2c_get_adapdata(adap));
volatile struct iic_regs __iomem *iic = dev->vaddr;
int i, ret = 0;
DBG2("%d: iic_xfer, %d msg(s)\n", dev->idx, num);
if (!num)
return 0;
if (unlikely(iic_invalid_address(&msgs[0]))){
DBG("%d: invalid address 0x%03x (%d-bit)\n", dev->idx,
msgs[0].addr, msgs[0].flags & I2C_M_TEN ? 10 : 7);
return -EINVAL;
}
for (i = 0; i < num; ++i){
if (unlikely(msgs[i].len <= 0)){
if (num == 1 && !msgs[0].len){
return iic_smbus_quick(dev, &msgs[0]);
}
DBG("%d: invalid len %d in msg[%d]\n", dev->idx,
msgs[i].len, i);
return -EINVAL;
}
if (unlikely(iic_address_neq(&msgs[0], &msgs[i]))){
DBG("%d: invalid addr in msg[%d]\n", dev->idx, i);
return -EINVAL;
}
}
if (unlikely((in_8(&iic->extsts) & EXTSTS_BCS_MASK) != EXTSTS_BCS_FREE)){
DBG("%d: iic_xfer, bus is not free\n", dev->idx);
iic_dev_reset(dev);
if ((in_8(&iic->extsts) & EXTSTS_BCS_MASK) != EXTSTS_BCS_FREE){
DBG("%d: iic_xfer, bus is still not free\n", dev->idx);
return -EREMOTEIO;
}
}
else {
out_8(&iic->mdcntl, in_8(&iic->mdcntl) | MDCNTL_FMDB);
}
iic_address(dev, &msgs[0]);
for (i = 0; i < num && !ret; ++i)
ret = iic_xfer_bytes(dev, &msgs[i], i < num - 1);
return ret < 0 ? ret : num;
}
static u32 iic_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR;
}
static inline u8 iic_clckdiv(unsigned int opb)
{
if (!opb){
printk(KERN_WARNING "ibm-iic: using compatibility value for OPB freq,"
" fix your board specific setup\n");
opb = 50000000;
}
opb /= 1000000;
if (opb < 20 || opb > 150){
printk(KERN_WARNING "ibm-iic: invalid OPB clock frequency %u MHz\n",
opb);
opb = opb < 20 ? 20 : 150;
}
return (u8)((opb + 9) / 10 - 1);
}
static int iic_request_irq(struct platform_device *ofdev,
struct ibm_iic_private *dev)
{
struct device_node *np = ofdev->dev.of_node;
int irq;
if (iic_force_poll)
return 0;
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
dev_err(&ofdev->dev, "irq_of_parse_and_map failed\n");
return 0;
}
iic_interrupt_mode(dev, 0);
if (request_irq(irq, iic_handler, 0, "IBM IIC", dev)) {
dev_err(&ofdev->dev, "request_irq %d failed\n", irq);
return 0;
}
return irq;
}
static int iic_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct ibm_iic_private *dev;
struct i2c_adapter *adap;
const u32 *freq;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_err(&ofdev->dev, "failed to allocate device data\n");
return -ENOMEM;
}
dev_set_drvdata(&ofdev->dev, dev);
dev->vaddr = of_iomap(np, 0);
if (dev->vaddr == NULL) {
dev_err(&ofdev->dev, "failed to iomap device\n");
ret = -ENXIO;
goto error_cleanup;
}
init_waitqueue_head(&dev->wq);
dev->irq = iic_request_irq(ofdev, dev);
if (!dev->irq)
dev_warn(&ofdev->dev, "using polling mode\n");
if (iic_force_fast || of_get_property(np, "fast-mode", NULL))
dev->fast_mode = 1;
freq = of_get_property(np, "clock-frequency", NULL);
if (freq == NULL) {
freq = of_get_property(np->parent, "clock-frequency", NULL);
if (freq == NULL) {
dev_err(&ofdev->dev, "Unable to get bus frequency\n");
ret = -EINVAL;
goto error_cleanup;
}
}
dev->clckdiv = iic_clckdiv(*freq);
dev_dbg(&ofdev->dev, "clckdiv = %d\n", dev->clckdiv);
iic_dev_init(dev);
adap = &dev->adap;
adap->dev.parent = &ofdev->dev;
adap->dev.of_node = of_node_get(np);
strlcpy(adap->name, "IBM IIC", sizeof(adap->name));
i2c_set_adapdata(adap, dev);
adap->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
adap->algo = &iic_algo;
adap->timeout = HZ;
ret = i2c_add_adapter(adap);
if (ret < 0) {
dev_err(&ofdev->dev, "failed to register i2c adapter\n");
goto error_cleanup;
}
dev_info(&ofdev->dev, "using %s mode\n",
dev->fast_mode ? "fast (400 kHz)" : "standard (100 kHz)");
of_i2c_register_devices(adap);
return 0;
error_cleanup:
if (dev->irq) {
iic_interrupt_mode(dev, 0);
free_irq(dev->irq, dev);
}
if (dev->vaddr)
iounmap(dev->vaddr);
dev_set_drvdata(&ofdev->dev, NULL);
kfree(dev);
return ret;
}
static int iic_remove(struct platform_device *ofdev)
{
struct ibm_iic_private *dev = dev_get_drvdata(&ofdev->dev);
dev_set_drvdata(&ofdev->dev, NULL);
i2c_del_adapter(&dev->adap);
if (dev->irq) {
iic_interrupt_mode(dev, 0);
free_irq(dev->irq, dev);
}
iounmap(dev->vaddr);
kfree(dev);
return 0;
}
