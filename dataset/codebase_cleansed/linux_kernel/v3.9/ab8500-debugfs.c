static irqreturn_t ab8500_debug_handler(int irq, void *data)
{
char buf[16];
struct kobject *kobj = (struct kobject *)data;
unsigned int irq_abb = irq - irq_first;
if (irq_abb < num_irqs)
irq_count[irq_abb]++;
sprintf(buf, "%d", irq);
sysfs_notify(kobj, NULL, buf);
return IRQ_HANDLED;
}
static int ab8500_registers_print(struct device *dev, u32 bank,
struct seq_file *s)
{
unsigned int i;
for (i = 0; i < debug_ranges[bank].num_ranges; i++) {
u32 reg;
for (reg = debug_ranges[bank].range[i].first;
reg <= debug_ranges[bank].range[i].last;
reg++) {
u8 value;
int err;
err = abx500_get_register_interruptible(dev,
(u8)bank, (u8)reg, &value);
if (err < 0) {
dev_err(dev, "ab->read fail %d\n", err);
return err;
}
if (s) {
err = seq_printf(s, " [%u/0x%02X]: 0x%02X\n",
bank, reg, value);
if (err < 0) {
dev_err(dev,
"seq_printf overflow bank=%d reg=%d\n",
bank, reg);
return 0;
}
} else {
printk(KERN_INFO" [%u/0x%02X]: 0x%02X\n", bank,
reg, value);
}
}
}
return 0;
}
static int ab8500_print_bank_registers(struct seq_file *s, void *p)
{
struct device *dev = s->private;
u32 bank = debug_bank;
seq_printf(s, AB8500_NAME_STRING " register values:\n");
seq_printf(s, " bank %u:\n", bank);
ab8500_registers_print(dev, bank, s);
return 0;
}
static int ab8500_registers_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_print_bank_registers, inode->i_private);
}
static int ab8500_print_all_banks(struct seq_file *s, void *p)
{
struct device *dev = s->private;
unsigned int i;
int err;
seq_printf(s, AB8500_NAME_STRING " register values:\n");
for (i = 1; i < AB8500_NUM_BANKS; i++) {
err = seq_printf(s, " bank %u:\n", i);
if (err < 0)
dev_err(dev, "seq_printf overflow, bank=%d\n", i);
ab8500_registers_print(dev, i, s);
}
return 0;
}
void ab8500_dump_all_banks(struct device *dev)
{
unsigned int i;
printk(KERN_INFO"ab8500 register values:\n");
for (i = 1; i < AB8500_NUM_BANKS; i++) {
printk(KERN_INFO" bank %u:\n", i);
ab8500_registers_print(dev, i, NULL);
}
}
static int ab8500_all_banks_open(struct inode *inode, struct file *file)
{
struct seq_file *s;
int err;
err = single_open(file, ab8500_print_all_banks, inode->i_private);
if (!err) {
s = (struct seq_file *)file->private_data;
s->size = (PAGE_SIZE * 2);
s->buf = kmalloc(s->size, GFP_KERNEL);
if (!s->buf) {
single_release(inode, file);
err = -ENOMEM;
}
}
return err;
}
static int ab8500_bank_print(struct seq_file *s, void *p)
{
return seq_printf(s, "%d\n", debug_bank);
}
static int ab8500_bank_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_bank_print, inode->i_private);
}
static ssize_t ab8500_bank_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
unsigned long user_bank;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_bank);
if (err)
return err;
if (user_bank >= AB8500_NUM_BANKS) {
dev_err(dev, "debugfs error input > number of banks\n");
return -EINVAL;
}
debug_bank = user_bank;
return count;
}
static int ab8500_address_print(struct seq_file *s, void *p)
{
return seq_printf(s, "0x%02X\n", debug_address);
}
static int ab8500_address_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_address_print, inode->i_private);
}
static ssize_t ab8500_address_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
unsigned long user_address;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_address);
if (err)
return err;
if (user_address > 0xff) {
dev_err(dev, "debugfs error input > 0xff\n");
return -EINVAL;
}
debug_address = user_address;
return count;
}
static int ab8500_val_print(struct seq_file *s, void *p)
{
struct device *dev = s->private;
int ret;
u8 regvalue;
ret = abx500_get_register_interruptible(dev,
(u8)debug_bank, (u8)debug_address, &regvalue);
if (ret < 0) {
dev_err(dev, "abx500_get_reg fail %d, %d\n",
ret, __LINE__);
return -EINVAL;
}
seq_printf(s, "0x%02X\n", regvalue);
return 0;
}
static int ab8500_val_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_val_print, inode->i_private);
}
static ssize_t ab8500_val_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
unsigned long user_val;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_val);
if (err)
return err;
if (user_val > 0xff) {
dev_err(dev, "debugfs error input > 0xff\n");
return -EINVAL;
}
err = abx500_set_register_interruptible(dev,
(u8)debug_bank, debug_address, (u8)user_val);
if (err < 0) {
printk(KERN_ERR "abx500_set_reg failed %d, %d", err, __LINE__);
return -EINVAL;
}
return count;
}
void ab8500_debug_register_interrupt(int line)
{
if (line < num_interrupt_lines)
num_interrupts[line]++;
}
static int ab8500_interrupts_print(struct seq_file *s, void *p)
{
int line;
seq_printf(s, "irq: number of\n");
for (line = 0; line < num_interrupt_lines; line++)
seq_printf(s, "%3i: %6i\n", line, num_interrupts[line]);
return 0;
}
static int ab8500_interrupts_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_interrupts_print, inode->i_private);
}
static int ab8500_hwreg_print(struct seq_file *s, void *d)
{
struct device *dev = s->private;
int ret;
u8 regvalue;
ret = abx500_get_register_interruptible(dev,
(u8)hwreg_cfg.bank, (u8)hwreg_cfg.addr, &regvalue);
if (ret < 0) {
dev_err(dev, "abx500_get_reg fail %d, %d\n",
ret, __LINE__);
return -EINVAL;
}
if (hwreg_cfg.shift >= 0)
regvalue >>= hwreg_cfg.shift;
else
regvalue <<= -hwreg_cfg.shift;
regvalue &= hwreg_cfg.mask;
if (REG_FMT_DEC(&hwreg_cfg))
seq_printf(s, "%d\n", regvalue);
else
seq_printf(s, "0x%02X\n", regvalue);
return 0;
}
static int ab8500_hwreg_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_hwreg_print, inode->i_private);
}
static int ab8500_gpadc_bat_ctrl_print(struct seq_file *s, void *p)
{
int bat_ctrl_raw;
int bat_ctrl_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
bat_ctrl_raw = ab8500_gpadc_read_raw(gpadc, BAT_CTRL);
bat_ctrl_convert = ab8500_gpadc_ad_to_voltage(gpadc,
BAT_CTRL, bat_ctrl_raw);
return seq_printf(s, "%d,0x%X\n",
bat_ctrl_convert, bat_ctrl_raw);
}
static int ab8500_gpadc_bat_ctrl_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_gpadc_bat_ctrl_print, inode->i_private);
}
static int ab8500_gpadc_btemp_ball_print(struct seq_file *s, void *p)
{
int btemp_ball_raw;
int btemp_ball_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
btemp_ball_raw = ab8500_gpadc_read_raw(gpadc, BTEMP_BALL);
btemp_ball_convert = ab8500_gpadc_ad_to_voltage(gpadc, BTEMP_BALL,
btemp_ball_raw);
return seq_printf(s,
"%d,0x%X\n", btemp_ball_convert, btemp_ball_raw);
}
static int ab8500_gpadc_btemp_ball_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_btemp_ball_print, inode->i_private);
}
static int ab8500_gpadc_main_charger_v_print(struct seq_file *s, void *p)
{
int main_charger_v_raw;
int main_charger_v_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
main_charger_v_raw = ab8500_gpadc_read_raw(gpadc, MAIN_CHARGER_V);
main_charger_v_convert = ab8500_gpadc_ad_to_voltage(gpadc,
MAIN_CHARGER_V, main_charger_v_raw);
return seq_printf(s, "%d,0x%X\n",
main_charger_v_convert, main_charger_v_raw);
}
static int ab8500_gpadc_main_charger_v_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_main_charger_v_print,
inode->i_private);
}
static int ab8500_gpadc_acc_detect1_print(struct seq_file *s, void *p)
{
int acc_detect1_raw;
int acc_detect1_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
acc_detect1_raw = ab8500_gpadc_read_raw(gpadc, ACC_DETECT1);
acc_detect1_convert = ab8500_gpadc_ad_to_voltage(gpadc, ACC_DETECT1,
acc_detect1_raw);
return seq_printf(s, "%d,0x%X\n",
acc_detect1_convert, acc_detect1_raw);
}
static int ab8500_gpadc_acc_detect1_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_acc_detect1_print,
inode->i_private);
}
static int ab8500_gpadc_acc_detect2_print(struct seq_file *s, void *p)
{
int acc_detect2_raw;
int acc_detect2_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
acc_detect2_raw = ab8500_gpadc_read_raw(gpadc, ACC_DETECT2);
acc_detect2_convert = ab8500_gpadc_ad_to_voltage(gpadc,
ACC_DETECT2, acc_detect2_raw);
return seq_printf(s, "%d,0x%X\n",
acc_detect2_convert, acc_detect2_raw);
}
static int ab8500_gpadc_acc_detect2_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_acc_detect2_print,
inode->i_private);
}
static int ab8500_gpadc_aux1_print(struct seq_file *s, void *p)
{
int aux1_raw;
int aux1_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
aux1_raw = ab8500_gpadc_read_raw(gpadc, ADC_AUX1);
aux1_convert = ab8500_gpadc_ad_to_voltage(gpadc, ADC_AUX1,
aux1_raw);
return seq_printf(s, "%d,0x%X\n",
aux1_convert, aux1_raw);
}
static int ab8500_gpadc_aux1_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_gpadc_aux1_print, inode->i_private);
}
static int ab8500_gpadc_aux2_print(struct seq_file *s, void *p)
{
int aux2_raw;
int aux2_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
aux2_raw = ab8500_gpadc_read_raw(gpadc, ADC_AUX2);
aux2_convert = ab8500_gpadc_ad_to_voltage(gpadc, ADC_AUX2,
aux2_raw);
return seq_printf(s, "%d,0x%X\n",
aux2_convert, aux2_raw);
}
static int ab8500_gpadc_aux2_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_gpadc_aux2_print, inode->i_private);
}
static int ab8500_gpadc_main_bat_v_print(struct seq_file *s, void *p)
{
int main_bat_v_raw;
int main_bat_v_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
main_bat_v_raw = ab8500_gpadc_read_raw(gpadc, MAIN_BAT_V);
main_bat_v_convert = ab8500_gpadc_ad_to_voltage(gpadc, MAIN_BAT_V,
main_bat_v_raw);
return seq_printf(s, "%d,0x%X\n",
main_bat_v_convert, main_bat_v_raw);
}
static int ab8500_gpadc_main_bat_v_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_main_bat_v_print, inode->i_private);
}
static int ab8500_gpadc_vbus_v_print(struct seq_file *s, void *p)
{
int vbus_v_raw;
int vbus_v_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
vbus_v_raw = ab8500_gpadc_read_raw(gpadc, VBUS_V);
vbus_v_convert = ab8500_gpadc_ad_to_voltage(gpadc, VBUS_V,
vbus_v_raw);
return seq_printf(s, "%d,0x%X\n",
vbus_v_convert, vbus_v_raw);
}
static int ab8500_gpadc_vbus_v_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_gpadc_vbus_v_print, inode->i_private);
}
static int ab8500_gpadc_main_charger_c_print(struct seq_file *s, void *p)
{
int main_charger_c_raw;
int main_charger_c_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
main_charger_c_raw = ab8500_gpadc_read_raw(gpadc, MAIN_CHARGER_C);
main_charger_c_convert = ab8500_gpadc_ad_to_voltage(gpadc,
MAIN_CHARGER_C, main_charger_c_raw);
return seq_printf(s, "%d,0x%X\n",
main_charger_c_convert, main_charger_c_raw);
}
static int ab8500_gpadc_main_charger_c_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_main_charger_c_print,
inode->i_private);
}
static int ab8500_gpadc_usb_charger_c_print(struct seq_file *s, void *p)
{
int usb_charger_c_raw;
int usb_charger_c_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
usb_charger_c_raw = ab8500_gpadc_read_raw(gpadc, USB_CHARGER_C);
usb_charger_c_convert = ab8500_gpadc_ad_to_voltage(gpadc,
USB_CHARGER_C, usb_charger_c_raw);
return seq_printf(s, "%d,0x%X\n",
usb_charger_c_convert, usb_charger_c_raw);
}
static int ab8500_gpadc_usb_charger_c_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_gpadc_usb_charger_c_print,
inode->i_private);
}
static int ab8500_gpadc_bk_bat_v_print(struct seq_file *s, void *p)
{
int bk_bat_v_raw;
int bk_bat_v_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
bk_bat_v_raw = ab8500_gpadc_read_raw(gpadc, BK_BAT_V);
bk_bat_v_convert = ab8500_gpadc_ad_to_voltage(gpadc,
BK_BAT_V, bk_bat_v_raw);
return seq_printf(s, "%d,0x%X\n",
bk_bat_v_convert, bk_bat_v_raw);
}
static int ab8500_gpadc_bk_bat_v_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_gpadc_bk_bat_v_print, inode->i_private);
}
static int ab8500_gpadc_die_temp_print(struct seq_file *s, void *p)
{
int die_temp_raw;
int die_temp_convert;
struct ab8500_gpadc *gpadc;
gpadc = ab8500_gpadc_get("ab8500-gpadc.0");
die_temp_raw = ab8500_gpadc_read_raw(gpadc, DIE_TEMP);
die_temp_convert = ab8500_gpadc_ad_to_voltage(gpadc, DIE_TEMP,
die_temp_raw);
return seq_printf(s, "%d,0x%X\n",
die_temp_convert, die_temp_raw);
}
static int ab8500_gpadc_die_temp_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_gpadc_die_temp_print, inode->i_private);
}
static int strval_len(char *b)
{
char *s = b;
if ((*s == '0') && ((*(s+1) == 'x') || (*(s+1) == 'X'))) {
s += 2;
for (; *s && (*s != ' ') && (*s != '\n'); s++) {
if (!isxdigit(*s))
return 0;
}
} else {
if (*s == '-')
s++;
for (; *s && (*s != ' ') && (*s != '\n'); s++) {
if (!isdigit(*s))
return 0;
}
}
return (int) (s-b);
}
static ssize_t hwreg_common_write(char *b, struct hwreg_cfg *cfg,
struct device *dev)
{
uint write, val = 0;
u8 regvalue;
int ret;
struct hwreg_cfg loc = {
.bank = 0,
.addr = 0,
.fmt = 0,
.mask = 0xFFFFFFFF,
.shift = 0,
};
if (!strncmp(b, "read ", 5)) {
write = 0;
b += 5;
} else if (!strncmp(b, "write ", 6)) {
write = 1;
b += 6;
} else
return -EINVAL;
while ((*b == ' ') || (*b == '-')) {
if (*(b-1) != ' ') {
b++;
continue;
}
if ((!strncmp(b, "-d ", 3)) ||
(!strncmp(b, "-dec ", 5))) {
b += (*(b+2) == ' ') ? 3 : 5;
loc.fmt |= (1<<0);
} else if ((!strncmp(b, "-h ", 3)) ||
(!strncmp(b, "-hex ", 5))) {
b += (*(b+2) == ' ') ? 3 : 5;
loc.fmt &= ~(1<<0);
} else if ((!strncmp(b, "-m ", 3)) ||
(!strncmp(b, "-mask ", 6))) {
b += (*(b+2) == ' ') ? 3 : 6;
if (strval_len(b) == 0)
return -EINVAL;
loc.mask = simple_strtoul(b, &b, 0);
} else if ((!strncmp(b, "-s ", 3)) ||
(!strncmp(b, "-shift ", 7))) {
b += (*(b+2) == ' ') ? 3 : 7;
if (strval_len(b) == 0)
return -EINVAL;
loc.shift = simple_strtol(b, &b, 0);
} else {
return -EINVAL;
}
}
if (strval_len(b) == 0)
return -EINVAL;
loc.bank = simple_strtoul(b, &b, 0);
while (*b == ' ')
b++;
if (strval_len(b) == 0)
return -EINVAL;
loc.addr = simple_strtoul(b, &b, 0);
if (write) {
while (*b == ' ')
b++;
if (strval_len(b) == 0)
return -EINVAL;
val = simple_strtoul(b, &b, 0);
}
*cfg = loc;
#ifdef ABB_HWREG_DEBUG
pr_warn("HWREG request: %s, %s, addr=0x%08X, mask=0x%X, shift=%d"
"value=0x%X\n", (write) ? "write" : "read",
REG_FMT_DEC(cfg) ? "decimal" : "hexa",
cfg->addr, cfg->mask, cfg->shift, val);
#endif
if (!write)
return 0;
ret = abx500_get_register_interruptible(dev,
(u8)cfg->bank, (u8)cfg->addr, &regvalue);
if (ret < 0) {
dev_err(dev, "abx500_get_reg fail %d, %d\n",
ret, __LINE__);
return -EINVAL;
}
if (cfg->shift >= 0) {
regvalue &= ~(cfg->mask << (cfg->shift));
val = (val & cfg->mask) << (cfg->shift);
} else {
regvalue &= ~(cfg->mask >> (-cfg->shift));
val = (val & cfg->mask) >> (-cfg->shift);
}
val = val | regvalue;
ret = abx500_set_register_interruptible(dev,
(u8)cfg->bank, (u8)cfg->addr, (u8)val);
if (ret < 0) {
pr_err("abx500_set_reg failed %d, %d", ret, __LINE__);
return -EINVAL;
}
return 0;
}
static ssize_t ab8500_hwreg_write(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
char buf[128];
int buf_size, ret;
buf_size = min(count, (sizeof(buf)-1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
ret = hwreg_common_write(buf, &hwreg_cfg, dev);
return (ret) ? ret : buf_size;
}
static int ab8500_subscribe_unsubscribe_print(struct seq_file *s, void *p)
{
seq_printf(s, "%d\n", irq_first);
return 0;
}
static int ab8500_subscribe_unsubscribe_open(struct inode *inode,
struct file *file)
{
return single_open(file, ab8500_subscribe_unsubscribe_print,
inode->i_private);
}
static ssize_t show_irq(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long name;
unsigned int irq_index;
int err;
err = strict_strtoul(attr->attr.name, 0, &name);
if (err)
return err;
irq_index = name - irq_first;
if (irq_index >= num_irqs)
return -EINVAL;
else
return sprintf(buf, "%u\n", irq_count[irq_index]);
}
static ssize_t ab8500_subscribe_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
char buf[32];
int buf_size;
unsigned long user_val;
int err;
unsigned int irq_index;
buf_size = min(count, (sizeof(buf)-1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
err = strict_strtoul(buf, 0, &user_val);
if (err)
return -EINVAL;
if (user_val < irq_first) {
dev_err(dev, "debugfs error input < %d\n", irq_first);
return -EINVAL;
}
if (user_val > irq_last) {
dev_err(dev, "debugfs error input > %d\n", irq_last);
return -EINVAL;
}
irq_index = user_val - irq_first;
if (irq_index >= num_irqs)
return -EINVAL;
dev_attr[irq_index] = kmalloc(sizeof(struct device_attribute),
GFP_KERNEL);
event_name[irq_index] = kmalloc(buf_size, GFP_KERNEL);
sprintf(event_name[irq_index], "%lu", user_val);
dev_attr[irq_index]->show = show_irq;
dev_attr[irq_index]->store = NULL;
dev_attr[irq_index]->attr.name = event_name[irq_index];
dev_attr[irq_index]->attr.mode = S_IRUGO;
err = sysfs_create_file(&dev->kobj, &dev_attr[irq_index]->attr);
if (err < 0) {
printk(KERN_ERR "sysfs_create_file failed %d\n", err);
return err;
}
err = request_threaded_irq(user_val, NULL, ab8500_debug_handler,
IRQF_SHARED | IRQF_NO_SUSPEND,
"ab8500-debug", &dev->kobj);
if (err < 0) {
printk(KERN_ERR "request_threaded_irq failed %d, %lu\n",
err, user_val);
sysfs_remove_file(&dev->kobj, &dev_attr[irq_index]->attr);
return err;
}
return buf_size;
}
static ssize_t ab8500_unsubscribe_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
char buf[32];
int buf_size;
unsigned long user_val;
int err;
unsigned int irq_index;
buf_size = min(count, (sizeof(buf)-1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
err = strict_strtoul(buf, 0, &user_val);
if (err)
return -EINVAL;
if (user_val < irq_first) {
dev_err(dev, "debugfs error input < %d\n", irq_first);
return -EINVAL;
}
if (user_val > irq_last) {
dev_err(dev, "debugfs error input > %d\n", irq_last);
return -EINVAL;
}
irq_index = user_val - irq_first;
if (irq_index >= num_irqs)
return -EINVAL;
irq_count[irq_index] = 0;
if (dev_attr[irq_index])
sysfs_remove_file(&dev->kobj, &dev_attr[irq_index]->attr);
free_irq(user_val, &dev->kobj);
kfree(event_name[irq_index]);
kfree(dev_attr[irq_index]);
return buf_size;
}
static int ab8500_debug_probe(struct platform_device *plf)
{
struct dentry *file;
int ret = -ENOMEM;
struct ab8500 *ab8500;
debug_bank = AB8500_MISC;
debug_address = AB8500_REV_REG & 0x00FF;
ab8500 = dev_get_drvdata(plf->dev.parent);
num_irqs = ab8500->mask_size;
irq_count = kzalloc(sizeof(*irq_count)*num_irqs, GFP_KERNEL);
if (!irq_count)
return -ENOMEM;
dev_attr = kzalloc(sizeof(*dev_attr)*num_irqs,GFP_KERNEL);
if (!dev_attr)
goto out_freeirq_count;
event_name = kzalloc(sizeof(*event_name)*num_irqs, GFP_KERNEL);
if (!event_name)
goto out_freedev_attr;
irq_first = platform_get_irq_byname(plf, "IRQ_FIRST");
if (irq_first < 0) {
dev_err(&plf->dev, "First irq not found, err %d\n",
irq_first);
ret = irq_first;
goto out_freeevent_name;
}
irq_last = platform_get_irq_byname(plf, "IRQ_LAST");
if (irq_last < 0) {
dev_err(&plf->dev, "Last irq not found, err %d\n",
irq_last);
ret = irq_last;
goto out_freeevent_name;
}
ab8500_dir = debugfs_create_dir(AB8500_NAME_STRING, NULL);
if (!ab8500_dir)
goto err;
ab8500_gpadc_dir = debugfs_create_dir(AB8500_ADC_NAME_STRING,
ab8500_dir);
if (!ab8500_gpadc_dir)
goto err;
file = debugfs_create_file("all-bank-registers", S_IRUGO,
ab8500_dir, &plf->dev, &ab8500_registers_fops);
if (!file)
goto err;
file = debugfs_create_file("all-banks", S_IRUGO,
ab8500_dir, &plf->dev, &ab8500_all_banks_fops);
if (!file)
goto err;
file = debugfs_create_file("register-bank", (S_IRUGO | S_IWUSR),
ab8500_dir, &plf->dev, &ab8500_bank_fops);
if (!file)
goto err;
file = debugfs_create_file("register-address", (S_IRUGO | S_IWUSR),
ab8500_dir, &plf->dev, &ab8500_address_fops);
if (!file)
goto err;
file = debugfs_create_file("register-value", (S_IRUGO | S_IWUSR),
ab8500_dir, &plf->dev, &ab8500_val_fops);
if (!file)
goto err;
file = debugfs_create_file("irq-subscribe", (S_IRUGO | S_IWUSR),
ab8500_dir, &plf->dev, &ab8500_subscribe_fops);
if (!file)
goto err;
if (is_ab8500(ab8500))
num_interrupt_lines = AB8500_NR_IRQS;
else if (is_ab8505(ab8500))
num_interrupt_lines = AB8505_NR_IRQS;
else if (is_ab9540(ab8500))
num_interrupt_lines = AB9540_NR_IRQS;
file = debugfs_create_file("interrupts", (S_IRUGO),
ab8500_dir, &plf->dev, &ab8500_interrupts_fops);
if (!file)
goto err;
file = debugfs_create_file("irq-unsubscribe", (S_IRUGO | S_IWUSR),
ab8500_dir, &plf->dev, &ab8500_unsubscribe_fops);
if (!file)
goto err;
file = debugfs_create_file("hwreg", (S_IRUGO | S_IWUSR),
ab8500_dir, &plf->dev, &ab8500_hwreg_fops);
if (!file)
goto err;
file = debugfs_create_file("bat_ctrl", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_bat_ctrl_fops);
if (!file)
goto err;
file = debugfs_create_file("btemp_ball", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_btemp_ball_fops);
if (!file)
goto err;
file = debugfs_create_file("main_charger_v", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_main_charger_v_fops);
if (!file)
goto err;
file = debugfs_create_file("acc_detect1", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_acc_detect1_fops);
if (!file)
goto err;
file = debugfs_create_file("acc_detect2", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_acc_detect2_fops);
if (!file)
goto err;
file = debugfs_create_file("adc_aux1", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_aux1_fops);
if (!file)
goto err;
file = debugfs_create_file("adc_aux2", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_aux2_fops);
if (!file)
goto err;
file = debugfs_create_file("main_bat_v", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_main_bat_v_fops);
if (!file)
goto err;
file = debugfs_create_file("vbus_v", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_vbus_v_fops);
if (!file)
goto err;
file = debugfs_create_file("main_charger_c", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_main_charger_c_fops);
if (!file)
goto err;
file = debugfs_create_file("usb_charger_c", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_usb_charger_c_fops);
if (!file)
goto err;
file = debugfs_create_file("bk_bat_v", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_bk_bat_v_fops);
if (!file)
goto err;
file = debugfs_create_file("die_temp", (S_IRUGO | S_IWUSR),
ab8500_gpadc_dir, &plf->dev, &ab8500_gpadc_die_temp_fops);
if (!file)
goto err;
return 0;
err:
if (ab8500_dir)
debugfs_remove_recursive(ab8500_dir);
dev_err(&plf->dev, "failed to create debugfs entries.\n");
out_freeevent_name:
kfree(event_name);
out_freedev_attr:
kfree(dev_attr);
out_freeirq_count:
kfree(irq_count);
return ret;
}
static int ab8500_debug_remove(struct platform_device *plf)
{
debugfs_remove_recursive(ab8500_dir);
kfree(event_name);
kfree(dev_attr);
kfree(irq_count);
return 0;
}
static int __init ab8500_debug_init(void)
{
return platform_driver_register(&ab8500_debug_driver);
}
static void __exit ab8500_debug_exit(void)
{
platform_driver_unregister(&ab8500_debug_driver);
}
