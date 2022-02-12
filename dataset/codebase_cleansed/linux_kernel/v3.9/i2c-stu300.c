static inline void stu300_wr8(u32 value, void __iomem *address)
{
writel((value << 16) | value, address);
}
static inline u32 stu300_r8(void __iomem *address)
{
return readl(address) & 0x000000FFU;
}
static void stu300_irq_enable(struct stu300_dev *dev)
{
u32 val;
val = stu300_r8(dev->virtbase + I2C_CR);
val |= I2C_CR_INTERRUPT_ENABLE;
stu300_wr8(val, dev->virtbase + I2C_CR);
stu300_wr8(val, dev->virtbase + I2C_CR);
}
static void stu300_irq_disable(struct stu300_dev *dev)
{
u32 val;
val = stu300_r8(dev->virtbase + I2C_CR);
val &= ~I2C_CR_INTERRUPT_ENABLE;
stu300_wr8(val, dev->virtbase + I2C_CR);
stu300_wr8(val, dev->virtbase + I2C_CR);
}
static int stu300_event_occurred(struct stu300_dev *dev,
enum stu300_event mr_event) {
u32 status1;
u32 status2;
status1 = stu300_r8(dev->virtbase + I2C_SR1);
if (!(status1 & I2C_SR1_EVF_IND))
return 0;
status2 = stu300_r8(dev->virtbase + I2C_SR2);
stu300_irq_disable(dev);
if (status2 & I2C_SR2_AF_IND) {
dev->cmd_err = STU300_ERROR_ACKNOWLEDGE_FAILURE;
return 1;
} else if (status2 & I2C_SR2_BERR_IND) {
dev->cmd_err = STU300_ERROR_BUS_ERROR;
return 1;
} else if (status2 & I2C_SR2_ARLO_IND) {
dev->cmd_err = STU300_ERROR_ARBITRATION_LOST;
return 1;
}
switch (mr_event) {
case STU300_EVENT_1:
if (status1 & I2C_SR1_ADSL_IND)
return 1;
break;
case STU300_EVENT_2:
case STU300_EVENT_3:
case STU300_EVENT_7:
case STU300_EVENT_8:
if (status1 & I2C_SR1_BTF_IND) {
return 1;
}
break;
case STU300_EVENT_4:
if (status2 & I2C_SR2_STOPF_IND)
return 1;
break;
case STU300_EVENT_5:
if (status1 & I2C_SR1_SB_IND)
return 1;
break;
case STU300_EVENT_6:
if (status2 & I2C_SR2_ENDAD_IND) {
return 1;
}
break;
case STU300_EVENT_9:
if (status1 & I2C_SR1_ADD10_IND)
return 1;
break;
default:
break;
}
dev->cmd_err = STU300_ERROR_UNKNOWN;
dev_err(&dev->pdev->dev,
"Unhandled interrupt! %d sr1: 0x%x sr2: 0x%x\n",
mr_event, status1, status2);
return 0;
}
static irqreturn_t stu300_irh(int irq, void *data)
{
struct stu300_dev *dev = data;
int res;
clk_enable(dev->clk);
spin_lock(&dev->cmd_issue_lock);
res = stu300_event_occurred(dev, dev->cmd_event);
if (res || dev->cmd_err != STU300_ERROR_NONE)
complete(&dev->cmd_complete);
spin_unlock(&dev->cmd_issue_lock);
clk_disable(dev->clk);
return IRQ_HANDLED;
}
static int stu300_start_and_await_event(struct stu300_dev *dev,
u8 cr_value,
enum stu300_event mr_event)
{
int ret;
if (unlikely(irqs_disabled())) {
WARN(1, "irqs are disabled, cannot poll for event\n");
return -EIO;
}
spin_lock_irq(&dev->cmd_issue_lock);
init_completion(&dev->cmd_complete);
dev->cmd_err = STU300_ERROR_NONE;
dev->cmd_event = mr_event;
spin_unlock_irq(&dev->cmd_issue_lock);
cr_value |= I2C_CR_INTERRUPT_ENABLE;
stu300_wr8(cr_value, dev->virtbase + I2C_CR);
ret = wait_for_completion_interruptible_timeout(&dev->cmd_complete,
STU300_TIMEOUT);
if (ret < 0) {
dev_err(&dev->pdev->dev,
"wait_for_completion_interruptible_timeout() "
"returned %d waiting for event %04x\n", ret, mr_event);
return ret;
}
if (ret == 0) {
dev_err(&dev->pdev->dev, "controller timed out "
"waiting for event %d, reinit hardware\n", mr_event);
(void) stu300_init_hw(dev);
return -ETIMEDOUT;
}
if (dev->cmd_err != STU300_ERROR_NONE) {
dev_err(&dev->pdev->dev, "controller (start) "
"error %d waiting for event %d, reinit hardware\n",
dev->cmd_err, mr_event);
(void) stu300_init_hw(dev);
return -EIO;
}
return 0;
}
static int stu300_await_event(struct stu300_dev *dev,
enum stu300_event mr_event)
{
int ret;
if (unlikely(irqs_disabled())) {
dev_err(&dev->pdev->dev, "irqs are disabled on this "
"system!\n");
return -EIO;
}
spin_lock_irq(&dev->cmd_issue_lock);
dev->cmd_err = STU300_ERROR_NONE;
dev->cmd_event = mr_event;
init_completion(&dev->cmd_complete);
stu300_irq_enable(dev);
spin_unlock_irq(&dev->cmd_issue_lock);
ret = wait_for_completion_interruptible_timeout(&dev->cmd_complete,
STU300_TIMEOUT);
if (ret < 0) {
dev_err(&dev->pdev->dev,
"wait_for_completion_interruptible_timeout()"
"returned %d waiting for event %04x\n", ret, mr_event);
return ret;
}
if (ret == 0) {
if (mr_event != STU300_EVENT_6) {
dev_err(&dev->pdev->dev, "controller "
"timed out waiting for event %d, reinit "
"hardware\n", mr_event);
(void) stu300_init_hw(dev);
}
return -ETIMEDOUT;
}
if (dev->cmd_err != STU300_ERROR_NONE) {
if (mr_event != STU300_EVENT_6) {
dev_err(&dev->pdev->dev, "controller "
"error (await_event) %d waiting for event %d, "
"reinit hardware\n", dev->cmd_err, mr_event);
(void) stu300_init_hw(dev);
}
return -EIO;
}
return 0;
}
static int stu300_wait_while_busy(struct stu300_dev *dev)
{
unsigned long timeout;
int i;
for (i = 0; i < BUSY_RELEASE_ATTEMPTS; i++) {
timeout = jiffies + STU300_TIMEOUT;
while (!time_after(jiffies, timeout)) {
if ((stu300_r8(dev->virtbase + I2C_SR1) &
I2C_SR1_BUSY_IND) == 0)
return 0;
msleep(1);
}
dev_err(&dev->pdev->dev, "transaction timed out "
"waiting for device to be free (not busy). "
"Attempt: %d\n", i+1);
dev_err(&dev->pdev->dev, "base address = "
"0x%08x, reinit hardware\n", (u32) dev->virtbase);
(void) stu300_init_hw(dev);
}
dev_err(&dev->pdev->dev, "giving up after %d attempts "
"to reset the bus.\n", BUSY_RELEASE_ATTEMPTS);
return -ETIMEDOUT;
}
static int stu300_set_clk(struct stu300_dev *dev, unsigned long clkrate)
{
u32 val;
int i = 0;
while (i < ARRAY_SIZE(stu300_clktable) - 1 &&
stu300_clktable[i].rate < clkrate)
i++;
if (stu300_clktable[i].setting == 0xFFU) {
dev_err(&dev->pdev->dev, "too %s clock rate requested "
"(%lu Hz).\n", i ? "high" : "low", clkrate);
return -EINVAL;
}
stu300_wr8(stu300_clktable[i].setting,
dev->virtbase + I2C_OAR2);
dev_dbg(&dev->pdev->dev, "Clock rate %lu Hz, I2C bus speed %d Hz "
"virtbase %p\n", clkrate, dev->speed, dev->virtbase);
if (dev->speed > 100000)
val = ((clkrate/dev->speed) - 9)/3 + 1;
else
val = ((clkrate/dev->speed) - 7)/2 + 1;
if (val < 0x002) {
dev_err(&dev->pdev->dev, "too low clock rate (%lu Hz).\n",
clkrate);
return -EINVAL;
}
if (val & 0xFFFFF000U) {
dev_err(&dev->pdev->dev, "too high clock rate (%lu Hz).\n",
clkrate);
return -EINVAL;
}
if (dev->speed > 100000) {
stu300_wr8((val & I2C_CCR_CC_MASK) | I2C_CCR_FMSM,
dev->virtbase + I2C_CCR);
dev_dbg(&dev->pdev->dev, "set clock divider to 0x%08x, "
"Fast Mode I2C\n", val);
} else {
stu300_wr8((val & I2C_CCR_CC_MASK),
dev->virtbase + I2C_CCR);
dev_dbg(&dev->pdev->dev, "set clock divider to "
"0x%08x, Standard Mode I2C\n", val);
}
stu300_wr8(((val >> 7) & 0x1F),
dev->virtbase + I2C_ECCR);
return 0;
}
static int stu300_init_hw(struct stu300_dev *dev)
{
u32 dummy;
unsigned long clkrate;
int ret;
stu300_wr8(0x00, dev->virtbase + I2C_CR);
stu300_wr8(0x00, dev->virtbase + I2C_OAR1);
clkrate = clk_get_rate(dev->clk);
ret = stu300_set_clk(dev, clkrate);
if (ret)
return ret;
stu300_wr8(I2C_CR_PERIPHERAL_ENABLE,
dev->virtbase + I2C_CR);
stu300_wr8(I2C_CR_PERIPHERAL_ENABLE,
dev->virtbase + I2C_CR);
dummy = stu300_r8(dev->virtbase + I2C_SR2);
dummy = stu300_r8(dev->virtbase + I2C_SR1);
return 0;
}
static int stu300_send_address(struct stu300_dev *dev,
struct i2c_msg *msg, int resend)
{
u32 val;
int ret;
if (msg->flags & I2C_M_TEN)
val = (0xf0 | (((u32) msg->addr & 0x300) >> 7)) &
I2C_DR_D_MASK;
else
val = ((msg->addr << 1) & I2C_DR_D_MASK);
if (msg->flags & I2C_M_RD) {
val |= 0x01;
if (resend)
dev_dbg(&dev->pdev->dev, "read resend\n");
} else if (resend)
dev_dbg(&dev->pdev->dev, "write resend\n");
stu300_wr8(val, dev->virtbase + I2C_DR);
if (msg->flags & I2C_M_TEN) {
ret = stu300_await_event(dev, STU300_EVENT_9);
val = msg->addr & I2C_DR_D_MASK;
stu300_wr8(val, dev->virtbase + I2C_DR);
if (ret != 0)
return ret;
}
if (resend)
dev_dbg(&dev->pdev->dev, "await event 6\n");
ret = stu300_await_event(dev, STU300_EVENT_6);
val = stu300_r8(dev->virtbase + I2C_CR);
val |= I2C_CR_PERIPHERAL_ENABLE;
stu300_wr8(val, dev->virtbase + I2C_CR);
return ret;
}
static int stu300_xfer_msg(struct i2c_adapter *adap,
struct i2c_msg *msg, int stop)
{
u32 cr;
u32 val;
u32 i;
int ret;
int attempts = 0;
struct stu300_dev *dev = i2c_get_adapdata(adap);
clk_enable(dev->clk);
if (0) {
dev_dbg(&dev->pdev->dev, "I2C message to: 0x%04x, len: %d, "
"flags: 0x%04x, stop: %d\n",
msg->addr, msg->len, msg->flags, stop);
}
if (msg->len == 0) {
ret = -EINVAL;
goto exit_disable;
}
do {
if (attempts)
dev_dbg(&dev->pdev->dev, "wait while busy\n");
ret = stu300_wait_while_busy(dev);
if (ret != 0)
goto exit_disable;
if (attempts)
dev_dbg(&dev->pdev->dev, "re-int hw\n");
ret = stu300_init_hw(dev);
if (ret)
goto exit_disable;
cr = I2C_CR_PERIPHERAL_ENABLE;
if (!(msg->flags & I2C_M_NOSTART))
cr |= I2C_CR_START_ENABLE;
if ((msg->flags & I2C_M_RD) && (msg->len > 1))
cr |= I2C_CR_ACK_ENABLE;
if (!(msg->flags & I2C_M_NOSTART)) {
if (attempts)
dev_dbg(&dev->pdev->dev, "send start event\n");
ret = stu300_start_and_await_event(dev, cr,
STU300_EVENT_5);
}
if (attempts)
dev_dbg(&dev->pdev->dev, "send address\n");
if (ret == 0)
ret = stu300_send_address(dev, msg, attempts != 0);
if (ret != 0) {
attempts++;
dev_dbg(&dev->pdev->dev, "failed sending address, "
"retrying. Attempt: %d msg_index: %d/%d\n",
attempts, dev->msg_index, dev->msg_len);
}
} while (ret != 0 && attempts < NUM_ADDR_RESEND_ATTEMPTS);
if (attempts < NUM_ADDR_RESEND_ATTEMPTS && attempts > 0) {
dev_dbg(&dev->pdev->dev, "managed to get address "
"through after %d attempts\n", attempts);
} else if (attempts == NUM_ADDR_RESEND_ATTEMPTS) {
dev_dbg(&dev->pdev->dev, "I give up, tried %d times "
"to resend address.\n",
NUM_ADDR_RESEND_ATTEMPTS);
goto exit_disable;
}
if (msg->flags & I2C_M_RD) {
for (i = 0; i < msg->len; i++) {
if (i == msg->len-1) {
val = I2C_CR_PERIPHERAL_ENABLE;
if (stop)
val |= I2C_CR_STOP_ENABLE;
stu300_wr8(val,
dev->virtbase + I2C_CR);
}
ret = stu300_await_event(dev, STU300_EVENT_7);
if (ret != 0)
goto exit_disable;
msg->buf[i] = (u8) stu300_r8(dev->virtbase + I2C_DR);
}
} else {
for (i = 0; i < msg->len; i++) {
stu300_wr8(msg->buf[i],
dev->virtbase + I2C_DR);
ret = stu300_await_event(dev, STU300_EVENT_8);
if (ret != 0) {
dev_err(&dev->pdev->dev, "error awaiting "
"event 8 (%d)\n", ret);
goto exit_disable;
}
}
if (!(msg->flags & I2C_M_IGNORE_NAK)) {
if (stu300_r8(dev->virtbase + I2C_SR2) &
I2C_SR2_AF_IND) {
dev_err(&dev->pdev->dev, "I2C payload "
"send returned NAK!\n");
ret = -EIO;
goto exit_disable;
}
}
if (stop) {
val = I2C_CR_PERIPHERAL_ENABLE;
val |= I2C_CR_STOP_ENABLE;
stu300_wr8(val, dev->virtbase + I2C_CR);
}
}
ret = stu300_wait_while_busy(dev);
if (ret != 0) {
dev_err(&dev->pdev->dev, "timout waiting for transfer "
"to commence.\n");
goto exit_disable;
}
val = stu300_r8(dev->virtbase + I2C_SR2);
val = stu300_r8(dev->virtbase + I2C_SR1);
ret = 0;
exit_disable:
stu300_wr8(0x00, dev->virtbase + I2C_CR);
clk_disable(dev->clk);
return ret;
}
static int stu300_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
int ret = -1;
int i;
struct stu300_dev *dev = i2c_get_adapdata(adap);
dev->msg_len = num;
for (i = 0; i < num; i++) {
dev->msg_index = i;
ret = stu300_xfer_msg(adap, &msgs[i], (i == (num - 1)));
if (ret != 0) {
num = ret;
break;
}
}
return num;
}
static u32 stu300_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR;
}
static int __init
stu300_probe(struct platform_device *pdev)
{
struct stu300_dev *dev;
struct i2c_adapter *adap;
struct resource *res;
int bus_nr;
int ret = 0;
char clk_name[] = "I2C0";
dev = devm_kzalloc(&pdev->dev, sizeof(struct stu300_dev), GFP_KERNEL);
if (!dev) {
dev_err(&pdev->dev, "could not allocate device struct\n");
return -ENOMEM;
}
bus_nr = pdev->id;
clk_name[3] += (char)bus_nr;
dev->clk = devm_clk_get(&pdev->dev, clk_name);
if (IS_ERR(dev->clk)) {
dev_err(&pdev->dev, "could not retrieve i2c bus clock\n");
return PTR_ERR(dev->clk);
}
dev->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
dev->virtbase = devm_ioremap_resource(&pdev->dev, res);
dev_dbg(&pdev->dev, "initialize bus device I2C%d on virtual "
"base %p\n", bus_nr, dev->virtbase);
if (IS_ERR(dev->virtbase))
return PTR_ERR(dev->virtbase);
dev->irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(&pdev->dev, dev->irq, stu300_irh, 0, NAME, dev);
if (ret < 0)
return ret;
dev->speed = scl_frequency;
clk_prepare_enable(dev->clk);
ret = stu300_init_hw(dev);
clk_disable(dev->clk);
if (ret != 0) {
dev_err(&dev->pdev->dev, "error initializing hardware.\n");
return -EIO;
}
spin_lock_init(&dev->cmd_issue_lock);
dev->cmd_event = STU300_EVENT_NONE;
dev->cmd_err = STU300_ERROR_NONE;
adap = &dev->adapter;
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DDC;
strlcpy(adap->name, "ST Microelectronics DDC I2C adapter",
sizeof(adap->name));
adap->nr = bus_nr;
adap->algo = &stu300_algo;
adap->dev.parent = &pdev->dev;
i2c_set_adapdata(adap, dev);
ret = i2c_add_numbered_adapter(adap);
if (ret) {
dev_err(&pdev->dev, "failure adding ST Micro DDC "
"I2C adapter\n");
return ret;
}
platform_set_drvdata(pdev, dev);
return 0;
}
static int stu300_suspend(struct device *device)
{
struct stu300_dev *dev = dev_get_drvdata(device);
stu300_wr8(0x00, dev->virtbase + I2C_CR);
return 0;
}
static int stu300_resume(struct device *device)
{
int ret = 0;
struct stu300_dev *dev = dev_get_drvdata(device);
clk_enable(dev->clk);
ret = stu300_init_hw(dev);
clk_disable(dev->clk);
if (ret != 0)
dev_err(device, "error re-initializing hardware.\n");
return ret;
}
static int __exit
stu300_remove(struct platform_device *pdev)
{
struct stu300_dev *dev = platform_get_drvdata(pdev);
i2c_del_adapter(&dev->adapter);
stu300_wr8(0x00, dev->virtbase + I2C_CR);
return 0;
}
static int __init stu300_init(void)
{
return platform_driver_probe(&stu300_i2c_driver, stu300_probe);
}
static void __exit stu300_exit(void)
{
platform_driver_unregister(&stu300_i2c_driver);
}
