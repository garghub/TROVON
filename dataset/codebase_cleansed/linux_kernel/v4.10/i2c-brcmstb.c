static inline int brcmstb_i2c_get_xfersz(struct brcmstb_i2c_dev *dev)
{
return (N_DATA_REGS * dev->data_regsz);
}
static inline int brcmstb_i2c_get_data_regsz(struct brcmstb_i2c_dev *dev)
{
return dev->data_regsz;
}
static void brcmstb_i2c_enable_disable_irq(struct brcmstb_i2c_dev *dev,
bool int_en)
{
if (int_en)
dev->bsc_regmap->ctl_reg |= BSC_CTL_REG_INT_EN_MASK;
else
dev->bsc_regmap->ctl_reg &= ~BSC_CTL_REG_INT_EN_MASK;
barrier();
bsc_writel(dev, dev->bsc_regmap->ctl_reg, ctl_reg);
}
static irqreturn_t brcmstb_i2c_isr(int irq, void *devid)
{
struct brcmstb_i2c_dev *dev = devid;
u32 status_bsc_ctl = bsc_readl(dev, ctl_reg);
u32 status_iic_intrp = bsc_readl(dev, iic_enable);
dev_dbg(dev->device, "isr CTL_REG %x IIC_EN %x\n",
status_bsc_ctl, status_iic_intrp);
if (!(status_bsc_ctl & BSC_CTL_REG_INT_EN_MASK))
return IRQ_NONE;
brcmstb_i2c_enable_disable_irq(dev, INT_DISABLE);
complete(&dev->done);
dev_dbg(dev->device, "isr handled");
return IRQ_HANDLED;
}
static int brcmstb_i2c_wait_if_busy(struct brcmstb_i2c_dev *dev)
{
unsigned long timeout = jiffies + msecs_to_jiffies(I2C_TIMEOUT);
while ((bsc_readl(dev, iic_enable) & BSC_IIC_EN_INTRP_MASK)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cpu_relax();
}
return 0;
}
static int brcmstb_i2c_wait_for_completion(struct brcmstb_i2c_dev *dev)
{
int ret = 0;
unsigned long timeout = msecs_to_jiffies(I2C_TIMEOUT);
if (dev->irq >= 0) {
if (!wait_for_completion_timeout(&dev->done, timeout))
ret = -ETIMEDOUT;
} else {
u32 bsc_intrp;
unsigned long time_left = jiffies + timeout;
do {
bsc_intrp = bsc_readl(dev, iic_enable) &
BSC_IIC_EN_INTRP_MASK;
if (time_after(jiffies, time_left)) {
ret = -ETIMEDOUT;
break;
}
cpu_relax();
} while (!bsc_intrp);
}
if (dev->irq < 0 || ret == -ETIMEDOUT)
brcmstb_i2c_enable_disable_irq(dev, INT_DISABLE);
return ret;
}
static void brcmstb_set_i2c_start_stop(struct brcmstb_i2c_dev *dev,
u32 cond_flag)
{
u32 regval = dev->bsc_regmap->iic_enable;
dev->bsc_regmap->iic_enable = (regval & ~COND_START_STOP) | cond_flag;
}
static int brcmstb_send_i2c_cmd(struct brcmstb_i2c_dev *dev,
enum bsc_xfer_cmd cmd)
{
int rc = 0;
struct bsc_regs *pi2creg = dev->bsc_regmap;
rc = brcmstb_i2c_wait_if_busy(dev);
if (rc < 0)
return rc;
if (dev->irq >= 0)
reinit_completion(&dev->done);
brcmstb_i2c_enable_disable_irq(dev, INT_ENABLE);
pi2creg->iic_enable |= BSC_IIC_EN_ENABLE_MASK;
bsc_writel(dev, pi2creg->iic_enable, iic_enable);
rc = brcmstb_i2c_wait_for_completion(dev);
if (rc) {
dev_dbg(dev->device, "intr timeout for cmd %s\n",
cmd_string[cmd]);
goto cmd_out;
}
if ((CMD_RD || CMD_WR) &&
bsc_readl(dev, iic_enable) & BSC_IIC_EN_NOACK_MASK) {
rc = -EREMOTEIO;
dev_dbg(dev->device, "controller received NOACK intr for %s\n",
cmd_string[cmd]);
}
cmd_out:
bsc_writel(dev, 0, cnt_reg);
bsc_writel(dev, 0, iic_enable);
return rc;
}
static int brcmstb_i2c_xfer_bsc_data(struct brcmstb_i2c_dev *dev,
u8 *buf, unsigned int len,
struct i2c_msg *pmsg)
{
int cnt, byte, i, rc;
enum bsc_xfer_cmd cmd;
u32 ctl_reg;
struct bsc_regs *pi2creg = dev->bsc_regmap;
int no_ack = pmsg->flags & I2C_M_IGNORE_NAK;
int data_regsz = brcmstb_i2c_get_data_regsz(dev);
if (no_ack) {
cmd = (pmsg->flags & I2C_M_RD) ? CMD_RD_NOACK
: CMD_WR_NOACK;
pi2creg->ctlhi_reg |= BSC_CTLHI_REG_IGNORE_ACK_MASK;
} else {
cmd = (pmsg->flags & I2C_M_RD) ? CMD_RD : CMD_WR;
pi2creg->ctlhi_reg &= ~BSC_CTLHI_REG_IGNORE_ACK_MASK;
}
bsc_writel(dev, pi2creg->ctlhi_reg, ctlhi_reg);
ctl_reg = pi2creg->ctl_reg & ~BSC_CTL_REG_DTF_MASK;
if (cmd == CMD_WR || cmd == CMD_WR_NOACK)
pi2creg->ctl_reg = ctl_reg | DTF_WR_MASK;
else
pi2creg->ctl_reg = ctl_reg | DTF_RD_MASK;
bsc_writel(dev, BSC_CNT_REG1_MASK(data_regsz) &
(len << BSC_CNT_REG1_SHIFT), cnt_reg);
if (cmd == CMD_WR || cmd == CMD_WR_NOACK) {
for (cnt = 0, i = 0; cnt < len; cnt += data_regsz, i++) {
u32 word = 0;
for (byte = 0; byte < data_regsz; byte++) {
word >>= BITS_PER_BYTE;
if ((cnt + byte) < len)
word |= buf[cnt + byte] <<
(BITS_PER_BYTE * (data_regsz - 1));
}
bsc_writel(dev, word, data_in[i]);
}
}
rc = brcmstb_send_i2c_cmd(dev, cmd);
if (rc != 0) {
dev_dbg(dev->device, "%s failure", cmd_string[cmd]);
return rc;
}
if (cmd == CMD_RD || cmd == CMD_RD_NOACK) {
for (cnt = 0, i = 0; cnt < len; cnt += data_regsz, i++) {
u32 data = bsc_readl(dev, data_out[i]);
for (byte = 0; byte < data_regsz &&
(byte + cnt) < len; byte++) {
buf[cnt + byte] = data & 0xff;
data >>= BITS_PER_BYTE;
}
}
}
return 0;
}
static int brcmstb_i2c_write_data_byte(struct brcmstb_i2c_dev *dev,
u8 *buf, unsigned int nak_expected)
{
enum bsc_xfer_cmd cmd = nak_expected ? CMD_WR : CMD_WR_NOACK;
bsc_writel(dev, 1, cnt_reg);
bsc_writel(dev, *buf, data_in);
return brcmstb_send_i2c_cmd(dev, cmd);
}
static int brcmstb_i2c_do_addr(struct brcmstb_i2c_dev *dev,
struct i2c_msg *msg)
{
unsigned char addr;
if (msg->flags & I2C_M_TEN) {
addr = 0xF0 | ((msg->addr & 0x300) >> 7);
bsc_writel(dev, addr, chip_address);
addr = msg->addr & 0xFF;
if (brcmstb_i2c_write_data_byte(dev, &addr, 0) < 0)
return -EREMOTEIO;
if (msg->flags & I2C_M_RD) {
brcmstb_set_i2c_start_stop(dev, COND_RESTART
| COND_NOSTOP);
addr = 0xF0 | ((msg->addr & 0x300) >> 7) | 0x01;
if (brcmstb_i2c_write_data_byte(dev, &addr, 0) < 0)
return -EREMOTEIO;
}
} else {
addr = i2c_8bit_addr_from_msg(msg);
bsc_writel(dev, addr, chip_address);
}
return 0;
}
static int brcmstb_i2c_xfer(struct i2c_adapter *adapter,
struct i2c_msg msgs[], int num)
{
struct brcmstb_i2c_dev *dev = i2c_get_adapdata(adapter);
struct i2c_msg *pmsg;
int rc = 0;
int i;
int bytes_to_xfer;
u8 *tmp_buf;
int len = 0;
int xfersz = brcmstb_i2c_get_xfersz(dev);
if (dev->is_suspended)
return -EBUSY;
for (i = 0; i < num; i++) {
pmsg = &msgs[i];
len = pmsg->len;
tmp_buf = pmsg->buf;
dev_dbg(dev->device,
"msg# %d/%d flg %x buf %x len %d\n", i,
num - 1, pmsg->flags,
pmsg->buf ? pmsg->buf[0] : '0', pmsg->len);
if (i < (num - 1) && (msgs[i + 1].flags & I2C_M_NOSTART))
brcmstb_set_i2c_start_stop(dev, ~(COND_START_STOP));
else
brcmstb_set_i2c_start_stop(dev,
COND_RESTART | COND_NOSTOP);
if (!(pmsg->flags & I2C_M_NOSTART)) {
rc = brcmstb_i2c_do_addr(dev, pmsg);
if (rc < 0) {
dev_dbg(dev->device,
"NACK for addr %2.2x msg#%d rc = %d\n",
pmsg->addr, i, rc);
goto out;
}
}
while (len) {
bytes_to_xfer = min(len, xfersz);
if (len <= xfersz && i == (num - 1))
brcmstb_set_i2c_start_stop(dev,
~(COND_START_STOP));
rc = brcmstb_i2c_xfer_bsc_data(dev, tmp_buf,
bytes_to_xfer, pmsg);
if (rc < 0)
goto out;
len -= bytes_to_xfer;
tmp_buf += bytes_to_xfer;
}
}
rc = num;
out:
return rc;
}
static u32 brcmstb_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR
| I2C_FUNC_NOSTART | I2C_FUNC_PROTOCOL_MANGLING;
}
static void brcmstb_i2c_set_bus_speed(struct brcmstb_i2c_dev *dev)
{
int i = 0, num_speeds = ARRAY_SIZE(bsc_clk);
u32 clk_freq_hz = dev->clk_freq_hz;
for (i = 0; i < num_speeds; i++) {
if (bsc_clk[i].hz == clk_freq_hz) {
dev->bsc_regmap->ctl_reg &= ~(BSC_CTL_REG_SCL_SEL_MASK
| BSC_CTL_REG_DIV_CLK_MASK);
dev->bsc_regmap->ctl_reg |= (bsc_clk[i].scl_mask |
bsc_clk[i].div_mask);
bsc_writel(dev, dev->bsc_regmap->ctl_reg, ctl_reg);
break;
}
}
if (i == num_speeds) {
i = (bsc_readl(dev, ctl_reg) & BSC_CTL_REG_SCL_SEL_MASK) >>
BSC_CTL_REG_SCL_SEL_SHIFT;
dev_warn(dev->device, "leaving current clock-frequency @ %dHz\n",
bsc_clk[i].hz);
}
}
static void brcmstb_i2c_set_bsc_reg_defaults(struct brcmstb_i2c_dev *dev)
{
if (brcmstb_i2c_get_data_regsz(dev) == sizeof(u32))
dev->bsc_regmap->ctlhi_reg = BSC_CTLHI_REG_DATAREG_SIZE_MASK;
else
dev->bsc_regmap->ctlhi_reg &= ~BSC_CTLHI_REG_DATAREG_SIZE_MASK;
bsc_writel(dev, dev->bsc_regmap->ctlhi_reg, ctlhi_reg);
brcmstb_i2c_set_bus_speed(dev);
}
static int brcmstb_i2c_probe(struct platform_device *pdev)
{
int rc = 0;
struct brcmstb_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *iomem;
const char *int_name;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->bsc_regmap = devm_kzalloc(&pdev->dev, sizeof(*dev->bsc_regmap), GFP_KERNEL);
if (!dev->bsc_regmap)
return -ENOMEM;
platform_set_drvdata(pdev, dev);
dev->device = &pdev->dev;
init_completion(&dev->done);
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->base = devm_ioremap_resource(dev->device, iomem);
if (IS_ERR(dev->base)) {
rc = -ENOMEM;
goto probe_errorout;
}
rc = of_property_read_string(dev->device->of_node, "interrupt-names",
&int_name);
if (rc < 0)
int_name = NULL;
dev->irq = platform_get_irq(pdev, 0);
brcmstb_i2c_enable_disable_irq(dev, INT_DISABLE);
rc = devm_request_irq(&pdev->dev, dev->irq, brcmstb_i2c_isr,
IRQF_SHARED,
int_name ? int_name : pdev->name,
dev);
if (rc) {
dev_dbg(dev->device, "falling back to polling mode");
dev->irq = -1;
}
if (of_property_read_u32(dev->device->of_node,
"clock-frequency", &dev->clk_freq_hz)) {
dev_warn(dev->device, "setting clock-frequency@%dHz\n",
bsc_clk[0].hz);
dev->clk_freq_hz = bsc_clk[0].hz;
}
if (of_device_is_compatible(dev->device->of_node,
"brcmstb,brcmper-i2c"))
dev->data_regsz = sizeof(u8);
else
dev->data_regsz = sizeof(u32);
brcmstb_i2c_set_bsc_reg_defaults(dev);
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
strlcpy(adap->name, "Broadcom STB : ", sizeof(adap->name));
if (int_name)
strlcat(adap->name, int_name, sizeof(adap->name));
adap->algo = &brcmstb_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
rc = i2c_add_adapter(adap);
if (rc)
goto probe_errorout;
dev_info(dev->device, "%s@%dhz registered in %s mode\n",
int_name ? int_name : " ", dev->clk_freq_hz,
(dev->irq >= 0) ? "interrupt" : "polling");
return 0;
probe_errorout:
return rc;
}
static int brcmstb_i2c_remove(struct platform_device *pdev)
{
struct brcmstb_i2c_dev *dev = platform_get_drvdata(pdev);
i2c_del_adapter(&dev->adapter);
return 0;
}
static int brcmstb_i2c_suspend(struct device *dev)
{
struct brcmstb_i2c_dev *i2c_dev = dev_get_drvdata(dev);
i2c_lock_adapter(&i2c_dev->adapter);
i2c_dev->is_suspended = true;
i2c_unlock_adapter(&i2c_dev->adapter);
return 0;
}
static int brcmstb_i2c_resume(struct device *dev)
{
struct brcmstb_i2c_dev *i2c_dev = dev_get_drvdata(dev);
i2c_lock_adapter(&i2c_dev->adapter);
brcmstb_i2c_set_bsc_reg_defaults(i2c_dev);
i2c_dev->is_suspended = false;
i2c_unlock_adapter(&i2c_dev->adapter);
return 0;
}
