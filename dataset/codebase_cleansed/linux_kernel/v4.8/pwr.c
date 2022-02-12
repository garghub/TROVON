static u32 mid_pwr_get_state(struct mid_pwr *pwr, int reg)
{
return readl(pwr->regs + PM_SSS(reg));
}
static void mid_pwr_set_state(struct mid_pwr *pwr, int reg, u32 value)
{
writel(value, pwr->regs + PM_SSC(reg));
}
static void mid_pwr_set_wake(struct mid_pwr *pwr, int reg, u32 value)
{
writel(value, pwr->regs + PM_WKC(reg));
}
static void mid_pwr_interrupt_disable(struct mid_pwr *pwr)
{
writel(~PM_ICS_IE, pwr->regs + PM_ICS);
}
static bool mid_pwr_is_busy(struct mid_pwr *pwr)
{
return !!(readl(pwr->regs + PM_STS) & PM_STS_BUSY);
}
static int mid_pwr_wait(struct mid_pwr *pwr)
{
unsigned int count = 500000;
bool busy;
do {
busy = mid_pwr_is_busy(pwr);
if (!busy)
return 0;
udelay(1);
} while (--count);
return -EBUSY;
}
static int mid_pwr_wait_for_cmd(struct mid_pwr *pwr, u8 cmd)
{
writel(PM_CMD_CMD(cmd), pwr->regs + PM_CMD);
return mid_pwr_wait(pwr);
}
static int __update_power_state(struct mid_pwr *pwr, int reg, int bit, int new)
{
int curstate;
u32 power;
int ret;
power = mid_pwr_get_state(pwr, reg);
curstate = (power >> bit) & 3;
if (curstate == new)
return 0;
mid_pwr_set_state(pwr, reg, (power & ~(3 << bit)) | (new << bit));
ret = mid_pwr_wait_for_cmd(pwr, CMD_SET_CFG);
if (ret)
return ret;
power = mid_pwr_get_state(pwr, reg);
curstate = (power >> bit) & 3;
if (curstate != new)
return -EAGAIN;
return 0;
}
static pci_power_t __find_weakest_power_state(struct mid_pwr_dev *lss,
struct pci_dev *pdev,
pci_power_t state)
{
pci_power_t weakest = PCI_D3hot;
unsigned int j;
for (j = 0; j < LSS_MAX_SHARED_DEVS; j++) {
if (lss[j].pdev == pdev || !lss[j].pdev)
break;
}
if (j < LSS_MAX_SHARED_DEVS) {
lss[j].pdev = pdev;
lss[j].state = state;
} else {
dev_WARN(&pdev->dev, "No room for device in PWRMU LSS cache\n");
weakest = state;
}
for (j = 0; j < LSS_MAX_SHARED_DEVS; j++) {
if (lss[j].state < weakest)
weakest = lss[j].state;
}
return weakest;
}
static int __set_power_state(struct mid_pwr *pwr, struct pci_dev *pdev,
pci_power_t state, int id, int reg, int bit)
{
const char *name;
int ret;
state = __find_weakest_power_state(pwr->lss[id], pdev, state);
name = pci_power_name(state);
ret = __update_power_state(pwr, reg, bit, (__force int)state);
if (ret) {
dev_warn(&pdev->dev, "Can't set power state %s: %d\n", name, ret);
return ret;
}
dev_vdbg(&pdev->dev, "Set power state %s\n", name);
return 0;
}
static int mid_pwr_set_power_state(struct mid_pwr *pwr, struct pci_dev *pdev,
pci_power_t state)
{
int id, reg, bit;
int ret;
id = intel_mid_pwr_get_lss_id(pdev);
if (id < 0)
return id;
reg = (id * LSS_PWS_BITS) / 32;
bit = (id * LSS_PWS_BITS) % 32;
if (state < PCI_D0)
state = PCI_D0;
if (state > PCI_D3hot)
state = PCI_D3hot;
mutex_lock(&pwr->lock);
ret = __set_power_state(pwr, pdev, state, id, reg, bit);
mutex_unlock(&pwr->lock);
return ret;
}
int intel_mid_pci_set_power_state(struct pci_dev *pdev, pci_power_t state)
{
struct mid_pwr *pwr = midpwr;
int ret = 0;
might_sleep();
if (pwr && pwr->available)
ret = mid_pwr_set_power_state(pwr, pdev, state);
dev_vdbg(&pdev->dev, "set_power_state() returns %d\n", ret);
return 0;
}
int intel_mid_pwr_get_lss_id(struct pci_dev *pdev)
{
int vndr;
u8 id;
vndr = pci_find_capability(pdev, PCI_CAP_ID_VNDR);
if (!vndr)
return -EINVAL;
pci_read_config_byte(pdev, vndr + INTEL_MID_PWR_LSS_OFFSET, &id);
if (!(id & INTEL_MID_PWR_LSS_TYPE))
return -ENODEV;
id &= ~INTEL_MID_PWR_LSS_TYPE;
if (id >= LSS_MAX_DEVS)
return -ERANGE;
return id;
}
static irqreturn_t mid_pwr_irq_handler(int irq, void *dev_id)
{
struct mid_pwr *pwr = dev_id;
u32 ics;
ics = readl(pwr->regs + PM_ICS);
if (!(ics & PM_ICS_IP))
return IRQ_NONE;
writel(ics | PM_ICS_IP, pwr->regs + PM_ICS);
dev_warn(pwr->dev, "Unexpected IRQ: %#x\n", PM_ICS_INT_STATUS(ics));
return IRQ_HANDLED;
}
static int mid_pwr_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct mid_pwr_device_info *info = (void *)id->driver_data;
struct device *dev = &pdev->dev;
struct mid_pwr *pwr;
int ret;
ret = pcim_enable_device(pdev);
if (ret < 0) {
dev_err(&pdev->dev, "error: could not enable device\n");
return ret;
}
ret = pcim_iomap_regions(pdev, 1 << 0, pci_name(pdev));
if (ret) {
dev_err(&pdev->dev, "I/O memory remapping failed\n");
return ret;
}
pwr = devm_kzalloc(dev, sizeof(*pwr), GFP_KERNEL);
if (!pwr)
return -ENOMEM;
pwr->dev = dev;
pwr->regs = pcim_iomap_table(pdev)[0];
pwr->irq = pdev->irq;
mutex_init(&pwr->lock);
mid_pwr_interrupt_disable(pwr);
if (info && info->set_initial_state) {
ret = info->set_initial_state(pwr);
if (ret)
dev_warn(dev, "Can't set initial state: %d\n", ret);
}
ret = devm_request_irq(dev, pdev->irq, mid_pwr_irq_handler,
IRQF_NO_SUSPEND, pci_name(pdev), pwr);
if (ret)
return ret;
pwr->available = true;
midpwr = pwr;
pci_set_drvdata(pdev, pwr);
return 0;
}
static int mid_set_initial_state(struct mid_pwr *pwr)
{
unsigned int i, j;
int ret;
mid_pwr_set_wake(pwr, 0, 0xffffffff);
mid_pwr_set_wake(pwr, 1, 0xffffffff);
mid_pwr_set_state(pwr, 0, 0xffffffff);
mid_pwr_set_state(pwr, 1, 0xffffffff);
mid_pwr_set_state(pwr, 2, 0xffffffff);
mid_pwr_set_state(pwr, 3, 0xffffffff);
ret = mid_pwr_wait_for_cmd(pwr, CMD_SET_CFG);
if (ret)
return ret;
for (i = 0; i < LSS_MAX_DEVS; i++) {
for (j = 0; j < LSS_MAX_SHARED_DEVS; j++)
pwr->lss[i][j].state = PCI_D3hot;
}
return 0;
}
