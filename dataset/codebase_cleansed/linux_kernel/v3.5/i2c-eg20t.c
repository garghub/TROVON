static inline void pch_setbit(void __iomem *addr, u32 offset, u32 bitmask)
{
u32 val;
val = ioread32(addr + offset);
val |= bitmask;
iowrite32(val, addr + offset);
}
static inline void pch_clrbit(void __iomem *addr, u32 offset, u32 bitmask)
{
u32 val;
val = ioread32(addr + offset);
val &= (~bitmask);
iowrite32(val, addr + offset);
}
static void pch_i2c_init(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
u32 pch_i2cbc;
u32 pch_i2ctmr;
u32 reg_value;
iowrite32(0x01, p + PCH_I2CSRST);
msleep(20);
iowrite32(0x0, p + PCH_I2CSRST);
iowrite32(0x21, p + PCH_I2CNF);
pch_setbit(adap->pch_base_address, PCH_I2CCTL, PCH_I2CCTL_I2CMEN);
if (pch_i2c_speed != 400)
pch_i2c_speed = 100;
reg_value = PCH_I2CCTL_I2CMEN;
if (pch_i2c_speed == FAST_MODE_CLK) {
reg_value |= FAST_MODE_EN;
pch_dbg(adap, "Fast mode enabled\n");
}
if (pch_clk > PCH_MAX_CLK)
pch_clk = 62500;
pch_i2cbc = (pch_clk + (pch_i2c_speed * 4)) / (pch_i2c_speed * 8);
iowrite32(pch_i2cbc, p + PCH_I2CBC);
pch_i2ctmr = (pch_clk) / 8;
iowrite32(pch_i2ctmr, p + PCH_I2CTMR);
reg_value |= NORMAL_INTR_ENBL;
iowrite32(reg_value, p + PCH_I2CCTL);
pch_dbg(adap,
"I2CCTL=%x pch_i2cbc=%x pch_i2ctmr=%x Enable interrupts\n",
ioread32(p + PCH_I2CCTL), pch_i2cbc, pch_i2ctmr);
init_waitqueue_head(&pch_event);
}
static s32 pch_i2c_wait_for_bus_idle(struct i2c_algo_pch_data *adap,
s32 timeout)
{
void __iomem *p = adap->pch_base_address;
int schedule = 0;
unsigned long end = jiffies + msecs_to_jiffies(timeout);
while (ioread32(p + PCH_I2CSR) & I2CMBB_BIT) {
if (time_after(jiffies, end)) {
pch_dbg(adap, "I2CSR = %x\n", ioread32(p + PCH_I2CSR));
pch_err(adap, "%s: Timeout Error.return%d\n",
__func__, -ETIME);
pch_i2c_init(adap);
return -ETIME;
}
if (!schedule)
udelay(5);
else
usleep_range(20, 1000);
schedule = 1;
}
return 0;
}
static void pch_i2c_start(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_dbg(adap, "I2CCTL = %x\n", ioread32(p + PCH_I2CCTL));
pch_setbit(adap->pch_base_address, PCH_I2CCTL, PCH_START);
}
static s32 pch_i2c_getack(struct i2c_algo_pch_data *adap)
{
u32 reg_val;
void __iomem *p = adap->pch_base_address;
reg_val = ioread32(p + PCH_I2CSR) & PCH_GETACK;
if (reg_val != 0) {
pch_err(adap, "return%d\n", -EPROTO);
return -EPROTO;
}
return 0;
}
static void pch_i2c_stop(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_dbg(adap, "I2CCTL = %x\n", ioread32(p + PCH_I2CCTL));
pch_clrbit(adap->pch_base_address, PCH_I2CCTL, PCH_START);
}
static int pch_i2c_wait_for_check_xfer(struct i2c_algo_pch_data *adap)
{
long ret;
ret = wait_event_timeout(pch_event,
(adap->pch_event_flag != 0), msecs_to_jiffies(1000));
if (!ret) {
pch_err(adap, "%s:wait-event timeout\n", __func__);
adap->pch_event_flag = 0;
pch_i2c_stop(adap);
pch_i2c_init(adap);
return -ETIMEDOUT;
}
if (adap->pch_event_flag & I2C_ERROR_MASK) {
pch_err(adap, "Lost Arbitration\n");
adap->pch_event_flag = 0;
pch_clrbit(adap->pch_base_address, PCH_I2CSR, I2CMAL_BIT);
pch_clrbit(adap->pch_base_address, PCH_I2CSR, I2CMIF_BIT);
pch_i2c_init(adap);
return -EAGAIN;
}
adap->pch_event_flag = 0;
if (pch_i2c_getack(adap)) {
pch_dbg(adap, "Receive NACK for slave address"
"setting\n");
return -EIO;
}
return 0;
}
static void pch_i2c_repstart(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_dbg(adap, "I2CCTL = %x\n", ioread32(p + PCH_I2CCTL));
pch_setbit(adap->pch_base_address, PCH_I2CCTL, PCH_REPSTART);
}
static s32 pch_i2c_writebytes(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, u32 last, u32 first)
{
struct i2c_algo_pch_data *adap = i2c_adap->algo_data;
u8 *buf;
u32 length;
u32 addr;
u32 addr_2_msb;
u32 addr_8_lsb;
s32 wrcount;
s32 rtn;
void __iomem *p = adap->pch_base_address;
length = msgs->len;
buf = msgs->buf;
addr = msgs->addr;
pch_setbit(adap->pch_base_address, PCH_I2CCTL, I2C_TX_MODE);
pch_dbg(adap, "I2CCTL = %x msgs->len = %d\n", ioread32(p + PCH_I2CCTL),
length);
if (first) {
if (pch_i2c_wait_for_bus_idle(adap, BUS_IDLE_TIMEOUT) == -ETIME)
return -ETIME;
}
if (msgs->flags & I2C_M_TEN) {
addr_2_msb = ((addr & I2C_MSB_2B_MSK) >> 7) & 0x06;
iowrite32(addr_2_msb | TEN_BIT_ADDR_MASK, p + PCH_I2CDR);
if (first)
pch_i2c_start(adap);
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
addr_8_lsb = (addr & I2C_ADDR_MSK);
iowrite32(addr_8_lsb, p + PCH_I2CDR);
} else {
iowrite32(addr << 1, p + PCH_I2CDR);
if (first)
pch_i2c_start(adap);
}
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
for (wrcount = 0; wrcount < length; ++wrcount) {
iowrite32(buf[wrcount], p + PCH_I2CDR);
pch_dbg(adap, "writing %x to Data register\n", buf[wrcount]);
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
pch_clrbit(adap->pch_base_address, PCH_I2CSR, I2CMCF_BIT);
pch_clrbit(adap->pch_base_address, PCH_I2CSR, I2CMIF_BIT);
}
if (last)
pch_i2c_stop(adap);
else
pch_i2c_repstart(adap);
pch_dbg(adap, "return=%d\n", wrcount);
return wrcount;
}
static void pch_i2c_sendack(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_dbg(adap, "I2CCTL = %x\n", ioread32(p + PCH_I2CCTL));
pch_clrbit(adap->pch_base_address, PCH_I2CCTL, PCH_ACK);
}
static void pch_i2c_sendnack(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_dbg(adap, "I2CCTL = %x\n", ioread32(p + PCH_I2CCTL));
pch_setbit(adap->pch_base_address, PCH_I2CCTL, PCH_ACK);
}
static void pch_i2c_restart(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_dbg(adap, "I2CCTL = %x\n", ioread32(p + PCH_I2CCTL));
pch_setbit(adap->pch_base_address, PCH_I2CCTL, PCH_RESTART);
}
static s32 pch_i2c_readbytes(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs,
u32 last, u32 first)
{
struct i2c_algo_pch_data *adap = i2c_adap->algo_data;
u8 *buf;
u32 count;
u32 length;
u32 addr;
u32 addr_2_msb;
u32 addr_8_lsb;
void __iomem *p = adap->pch_base_address;
s32 rtn;
length = msgs->len;
buf = msgs->buf;
addr = msgs->addr;
pch_clrbit(adap->pch_base_address, PCH_I2CCTL, I2C_TX_MODE);
if (first) {
if (pch_i2c_wait_for_bus_idle(adap, BUS_IDLE_TIMEOUT) == -ETIME)
return -ETIME;
}
if (msgs->flags & I2C_M_TEN) {
addr_2_msb = ((addr & I2C_MSB_2B_MSK) >> 7);
iowrite32(addr_2_msb | TEN_BIT_ADDR_MASK, p + PCH_I2CDR);
if (first)
pch_i2c_start(adap);
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
addr_8_lsb = (addr & I2C_ADDR_MSK);
iowrite32(addr_8_lsb, p + PCH_I2CDR);
pch_i2c_restart(adap);
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
addr_2_msb |= I2C_RD;
iowrite32(addr_2_msb | TEN_BIT_ADDR_MASK, p + PCH_I2CDR);
} else {
addr = (((addr) << 1) | (I2C_RD));
iowrite32(addr, p + PCH_I2CDR);
}
if (first)
pch_i2c_start(adap);
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
if (length == 0) {
pch_i2c_stop(adap);
ioread32(p + PCH_I2CDR);
count = length;
} else {
int read_index;
int loop;
pch_i2c_sendack(adap);
for (loop = 1, read_index = 0; loop < length; loop++) {
buf[read_index] = ioread32(p + PCH_I2CDR);
if (loop != 1)
read_index++;
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
}
pch_i2c_sendnack(adap);
buf[read_index] = ioread32(p + PCH_I2CDR);
if (length != 1)
read_index++;
rtn = pch_i2c_wait_for_check_xfer(adap);
if (rtn)
return rtn;
if (last)
pch_i2c_stop(adap);
else
pch_i2c_repstart(adap);
buf[read_index++] = ioread32(p + PCH_I2CDR);
count = read_index;
}
return count;
}
static void pch_i2c_cb(struct i2c_algo_pch_data *adap)
{
u32 sts;
void __iomem *p = adap->pch_base_address;
sts = ioread32(p + PCH_I2CSR);
sts &= (I2CMAL_BIT | I2CMCF_BIT | I2CMIF_BIT);
if (sts & I2CMAL_BIT)
adap->pch_event_flag |= I2CMAL_EVENT;
if (sts & I2CMCF_BIT)
adap->pch_event_flag |= I2CMCF_EVENT;
pch_clrbit(adap->pch_base_address, PCH_I2CSR, sts);
pch_dbg(adap, "PCH_I2CSR = %x\n", ioread32(p + PCH_I2CSR));
wake_up(&pch_event);
}
static irqreturn_t pch_i2c_handler(int irq, void *pData)
{
u32 reg_val;
int flag;
int i;
struct adapter_info *adap_info = pData;
void __iomem *p;
u32 mode;
for (i = 0, flag = 0; i < adap_info->ch_num; i++) {
p = adap_info->pch_data[i].pch_base_address;
mode = ioread32(p + PCH_I2CMOD);
mode &= BUFFER_MODE | EEPROM_SR_MODE;
if (mode != NORMAL_MODE) {
pch_err(adap_info->pch_data,
"I2C-%d mode(%d) is not supported\n", mode, i);
continue;
}
reg_val = ioread32(p + PCH_I2CSR);
if (reg_val & (I2CMAL_BIT | I2CMCF_BIT | I2CMIF_BIT)) {
pch_i2c_cb(&adap_info->pch_data[i]);
flag = 1;
}
}
return flag ? IRQ_HANDLED : IRQ_NONE;
}
static s32 pch_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, s32 num)
{
struct i2c_msg *pmsg;
u32 i = 0;
u32 status;
s32 ret;
struct i2c_algo_pch_data *adap = i2c_adap->algo_data;
ret = mutex_lock_interruptible(&pch_mutex);
if (ret)
return ret;
if (adap->p_adapter_info->pch_i2c_suspended) {
mutex_unlock(&pch_mutex);
return -EBUSY;
}
pch_dbg(adap, "adap->p_adapter_info->pch_i2c_suspended is %d\n",
adap->p_adapter_info->pch_i2c_suspended);
adap->pch_i2c_xfer_in_progress = true;
for (i = 0; i < num && ret >= 0; i++) {
pmsg = &msgs[i];
pmsg->flags |= adap->pch_buff_mode_en;
status = pmsg->flags;
pch_dbg(adap,
"After invoking I2C_MODE_SEL :flag= 0x%x\n", status);
if ((status & (I2C_M_RD)) != false) {
ret = pch_i2c_readbytes(i2c_adap, pmsg, (i + 1 == num),
(i == 0));
} else {
ret = pch_i2c_writebytes(i2c_adap, pmsg, (i + 1 == num),
(i == 0));
}
}
adap->pch_i2c_xfer_in_progress = false;
mutex_unlock(&pch_mutex);
return (ret < 0) ? ret : num;
}
static u32 pch_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR;
}
static void pch_i2c_disbl_int(struct i2c_algo_pch_data *adap)
{
void __iomem *p = adap->pch_base_address;
pch_clrbit(adap->pch_base_address, PCH_I2CCTL, NORMAL_INTR_ENBL);
iowrite32(EEPROM_RST_INTR_DISBL, p + PCH_I2CESRMSK);
iowrite32(BUFFER_MODE_INTR_DISBL, p + PCH_I2CBUFMSK);
}
static int __devinit pch_i2c_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
void __iomem *base_addr;
int ret;
int i, j;
struct adapter_info *adap_info;
struct i2c_adapter *pch_adap;
pch_pci_dbg(pdev, "Entered.\n");
adap_info = kzalloc((sizeof(struct adapter_info)), GFP_KERNEL);
if (adap_info == NULL) {
pch_pci_err(pdev, "Memory allocation FAILED\n");
return -ENOMEM;
}
ret = pci_enable_device(pdev);
if (ret) {
pch_pci_err(pdev, "pci_enable_device FAILED\n");
goto err_pci_enable;
}
ret = pci_request_regions(pdev, KBUILD_MODNAME);
if (ret) {
pch_pci_err(pdev, "pci_request_regions FAILED\n");
goto err_pci_req;
}
base_addr = pci_iomap(pdev, 1, 0);
if (base_addr == NULL) {
pch_pci_err(pdev, "pci_iomap FAILED\n");
ret = -ENOMEM;
goto err_pci_iomap;
}
adap_info->ch_num = id->driver_data;
ret = request_irq(pdev->irq, pch_i2c_handler, IRQF_SHARED,
KBUILD_MODNAME, adap_info);
if (ret) {
pch_pci_err(pdev, "request_irq FAILED\n");
goto err_request_irq;
}
for (i = 0; i < adap_info->ch_num; i++) {
pch_adap = &adap_info->pch_data[i].pch_adapter;
adap_info->pch_i2c_suspended = false;
adap_info->pch_data[i].p_adapter_info = adap_info;
pch_adap->owner = THIS_MODULE;
pch_adap->class = I2C_CLASS_HWMON;
strlcpy(pch_adap->name, KBUILD_MODNAME, sizeof(pch_adap->name));
pch_adap->algo = &pch_algorithm;
pch_adap->algo_data = &adap_info->pch_data[i];
adap_info->pch_data[i].pch_base_address = base_addr + 0x100 * i;
pch_adap->dev.parent = &pdev->dev;
pch_i2c_init(&adap_info->pch_data[i]);
pch_adap->nr = i;
ret = i2c_add_numbered_adapter(pch_adap);
if (ret) {
pch_pci_err(pdev, "i2c_add_adapter[ch:%d] FAILED\n", i);
goto err_add_adapter;
}
}
pci_set_drvdata(pdev, adap_info);
pch_pci_dbg(pdev, "returns %d.\n", ret);
return 0;
err_add_adapter:
for (j = 0; j < i; j++)
i2c_del_adapter(&adap_info->pch_data[j].pch_adapter);
free_irq(pdev->irq, adap_info);
err_request_irq:
pci_iounmap(pdev, base_addr);
err_pci_iomap:
pci_release_regions(pdev);
err_pci_req:
pci_disable_device(pdev);
err_pci_enable:
kfree(adap_info);
return ret;
}
static void __devexit pch_i2c_remove(struct pci_dev *pdev)
{
int i;
struct adapter_info *adap_info = pci_get_drvdata(pdev);
free_irq(pdev->irq, adap_info);
for (i = 0; i < adap_info->ch_num; i++) {
pch_i2c_disbl_int(&adap_info->pch_data[i]);
i2c_del_adapter(&adap_info->pch_data[i].pch_adapter);
}
if (adap_info->pch_data[0].pch_base_address)
pci_iounmap(pdev, adap_info->pch_data[0].pch_base_address);
for (i = 0; i < adap_info->ch_num; i++)
adap_info->pch_data[i].pch_base_address = NULL;
pci_set_drvdata(pdev, NULL);
pci_release_regions(pdev);
pci_disable_device(pdev);
kfree(adap_info);
}
static int pch_i2c_suspend(struct pci_dev *pdev, pm_message_t state)
{
int ret;
int i;
struct adapter_info *adap_info = pci_get_drvdata(pdev);
void __iomem *p = adap_info->pch_data[0].pch_base_address;
adap_info->pch_i2c_suspended = true;
for (i = 0; i < adap_info->ch_num; i++) {
while ((adap_info->pch_data[i].pch_i2c_xfer_in_progress)) {
msleep(20);
}
}
for (i = 0; i < adap_info->ch_num; i++)
pch_i2c_disbl_int(&adap_info->pch_data[i]);
pch_pci_dbg(pdev, "I2CSR = %x I2CBUFSTA = %x I2CESRSTA = %x "
"invoked function pch_i2c_disbl_int successfully\n",
ioread32(p + PCH_I2CSR), ioread32(p + PCH_I2CBUFSTA),
ioread32(p + PCH_I2CESRSTA));
ret = pci_save_state(pdev);
if (ret) {
pch_pci_err(pdev, "pci_save_state\n");
return ret;
}
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int pch_i2c_resume(struct pci_dev *pdev)
{
int i;
struct adapter_info *adap_info = pci_get_drvdata(pdev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if (pci_enable_device(pdev) < 0) {
pch_pci_err(pdev, "pch_i2c_resume:pci_enable_device FAILED\n");
return -EIO;
}
pci_enable_wake(pdev, PCI_D3hot, 0);
for (i = 0; i < adap_info->ch_num; i++)
pch_i2c_init(&adap_info->pch_data[i]);
adap_info->pch_i2c_suspended = false;
return 0;
}
static int __init pch_pci_init(void)
{
return pci_register_driver(&pch_pcidriver);
}
static void __exit pch_pci_exit(void)
{
pci_unregister_driver(&pch_pcidriver);
}
