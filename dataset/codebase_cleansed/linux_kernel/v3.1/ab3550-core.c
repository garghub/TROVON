static int ab3550_i2c_master_send(struct ab3550 *ab, u8 bank, u8 *data,
u8 count)
{
int err;
err = i2c_master_send(ab->i2c_client[bank], data, count);
if (err < 0) {
dev_err(&ab->i2c_client[0]->dev, "send error: %d\n", err);
return err;
}
return 0;
}
static int ab3550_i2c_master_recv(struct ab3550 *ab, u8 bank, u8 *data,
u8 count)
{
int err;
err = i2c_master_recv(ab->i2c_client[bank], data, count);
if (err < 0) {
dev_err(&ab->i2c_client[0]->dev, "receive error: %d\n", err);
return err;
}
return 0;
}
static int get_register_interruptible(struct ab3550 *ab, u8 bank, u8 reg,
u8 *value)
{
int err;
err = mutex_lock_interruptible(&ab->access_mutex);
if (err)
return err;
err = ab3550_i2c_master_send(ab, bank, &reg, 1);
if (!err)
err = ab3550_i2c_master_recv(ab, bank, value, 1);
mutex_unlock(&ab->access_mutex);
return err;
}
static int get_register_page_interruptible(struct ab3550 *ab, u8 bank,
u8 first_reg, u8 *regvals, u8 numregs)
{
int err;
err = mutex_lock_interruptible(&ab->access_mutex);
if (err)
return err;
err = ab3550_i2c_master_send(ab, bank, &first_reg, 1);
if (!err)
err = ab3550_i2c_master_recv(ab, bank, regvals, numregs);
mutex_unlock(&ab->access_mutex);
return err;
}
static int mask_and_set_register_interruptible(struct ab3550 *ab, u8 bank,
u8 reg, u8 bitmask, u8 bitvalues)
{
int err = 0;
if (likely(bitmask)) {
u8 reg_bits[2] = {reg, 0};
err = mutex_lock_interruptible(&ab->access_mutex);
if (err)
return err;
if (bitmask == 0xFF)
reg_bits[1] = bitvalues;
else {
u8 bits;
err = ab3550_i2c_master_send(ab, bank, &reg, 1);
if (err)
goto unlock_and_return;
err = ab3550_i2c_master_recv(ab, bank, &bits, 1);
if (err)
goto unlock_and_return;
reg_bits[1] = ((~bitmask & bits) |
(bitmask & bitvalues));
}
err = ab3550_i2c_master_send(ab, bank, reg_bits, 2);
unlock_and_return:
mutex_unlock(&ab->access_mutex);
}
return err;
}
static bool page_write_allowed(const struct ab3550_reg_ranges *ranges,
u8 first_reg, u8 last_reg)
{
u8 i;
if (last_reg < first_reg)
return false;
for (i = 0; i < ranges->count; i++) {
if (first_reg < ranges->range[i].first)
break;
if ((last_reg <= ranges->range[i].last) &&
(ranges->range[i].perm & AB3550_PERM_WR))
return true;
}
return false;
}
static bool reg_write_allowed(const struct ab3550_reg_ranges *ranges, u8 reg)
{
return page_write_allowed(ranges, reg, reg);
}
static bool page_read_allowed(const struct ab3550_reg_ranges *ranges,
u8 first_reg, u8 last_reg)
{
u8 i;
if (last_reg < first_reg)
return false;
for (i = 0; i < ranges->count; i++) {
if (first_reg < ranges->range[i].first)
return false;
if (first_reg <= ranges->range[i].last)
break;
}
while ((i < ranges->count) &&
(ranges->range[i].perm & AB3550_PERM_RD)) {
if (last_reg <= ranges->range[i].last)
return true;
if ((++i >= ranges->count) ||
(ranges->range[i].first !=
(ranges->range[i - 1].last + 1))) {
break;
}
}
return false;
}
static bool reg_read_allowed(const struct ab3550_reg_ranges *ranges, u8 reg)
{
return page_read_allowed(ranges, reg, reg);
}
static int ab3550_get_chip_id(struct device *dev)
{
struct ab3550 *ab = dev_get_drvdata(dev->parent);
return (int)ab->chip_id;
}
static int ab3550_mask_and_set_register_interruptible(struct device *dev,
u8 bank, u8 reg, u8 bitmask, u8 bitvalues)
{
struct ab3550 *ab;
struct platform_device *pdev = to_platform_device(dev);
if ((AB3550_NUM_BANKS <= bank) ||
!reg_write_allowed(&ab3550_reg_ranges[pdev->id][bank], reg))
return -EINVAL;
ab = dev_get_drvdata(dev->parent);
return mask_and_set_register_interruptible(ab, bank, reg,
bitmask, bitvalues);
}
static int ab3550_set_register_interruptible(struct device *dev, u8 bank,
u8 reg, u8 value)
{
return ab3550_mask_and_set_register_interruptible(dev, bank, reg, 0xFF,
value);
}
static int ab3550_get_register_interruptible(struct device *dev, u8 bank,
u8 reg, u8 *value)
{
struct ab3550 *ab;
struct platform_device *pdev = to_platform_device(dev);
if ((AB3550_NUM_BANKS <= bank) ||
!reg_read_allowed(&ab3550_reg_ranges[pdev->id][bank], reg))
return -EINVAL;
ab = dev_get_drvdata(dev->parent);
return get_register_interruptible(ab, bank, reg, value);
}
static int ab3550_get_register_page_interruptible(struct device *dev, u8 bank,
u8 first_reg, u8 *regvals, u8 numregs)
{
struct ab3550 *ab;
struct platform_device *pdev = to_platform_device(dev);
if ((AB3550_NUM_BANKS <= bank) ||
!page_read_allowed(&ab3550_reg_ranges[pdev->id][bank],
first_reg, (first_reg + numregs - 1)))
return -EINVAL;
ab = dev_get_drvdata(dev->parent);
return get_register_page_interruptible(ab, bank, first_reg, regvals,
numregs);
}
static int ab3550_event_registers_startup_state_get(struct device *dev,
u8 *event)
{
struct ab3550 *ab;
ab = dev_get_drvdata(dev->parent);
if (!ab->startup_events_read)
return -EAGAIN;
memcpy(event, ab->startup_events, AB3550_NUM_EVENT_REG);
return 0;
}
static int ab3550_startup_irq_enabled(struct device *dev, unsigned int irq)
{
struct ab3550 *ab;
struct ab3550_platform_data *plf_data;
bool val;
ab = irq_get_chip_data(irq);
plf_data = ab->i2c_client[0]->dev.platform_data;
irq -= plf_data->irq.base;
val = ((ab->startup_events[irq / 8] & BIT(irq % 8)) != 0);
return val;
}
static irqreturn_t ab3550_irq_handler(int irq, void *data)
{
struct ab3550 *ab = data;
int err;
unsigned int i;
u8 e[AB3550_NUM_EVENT_REG];
u8 *events;
unsigned long flags;
events = (ab->startup_events_read ? e : ab->startup_events);
err = get_register_page_interruptible(ab, AB3550_EVENT_BANK,
AB3550_EVENT_REG, events, AB3550_NUM_EVENT_REG);
if (err)
goto err_event_rd;
if (!ab->startup_events_read) {
dev_info(&ab->i2c_client[0]->dev,
"startup events 0x%x,0x%x,0x%x,0x%x,0x%x\n",
ab->startup_events[0], ab->startup_events[1],
ab->startup_events[2], ab->startup_events[3],
ab->startup_events[4]);
ab->startup_events_read = true;
goto out;
}
events[4] &= 0x3f;
spin_lock_irqsave(&ab->event_lock, flags);
for (i = 0; i < AB3550_NUM_EVENT_REG; i++)
events[i] &= ~ab->event_mask[i];
spin_unlock_irqrestore(&ab->event_lock, flags);
for (i = 0; i < AB3550_NUM_EVENT_REG; i++) {
u8 bit;
u8 event_reg;
dev_dbg(&ab->i2c_client[0]->dev, "IRQ Event[%d]: 0x%2x\n",
i, events[i]);
event_reg = events[i];
for (bit = 0; event_reg; bit++, event_reg /= 2) {
if (event_reg % 2) {
unsigned int irq;
struct ab3550_platform_data *plf_data;
plf_data = ab->i2c_client[0]->dev.platform_data;
irq = plf_data->irq.base + (i * 8) + bit;
handle_nested_irq(irq);
}
}
}
out:
return IRQ_HANDLED;
err_event_rd:
dev_dbg(&ab->i2c_client[0]->dev, "error reading event registers\n");
return IRQ_HANDLED;
}
static int ab3550_registers_print(struct seq_file *s, void *p)
{
struct ab3550 *ab = s->private;
int bank;
seq_printf(s, AB3550_NAME_STRING " register values:\n");
for (bank = 0; bank < AB3550_NUM_BANKS; bank++) {
unsigned int i;
seq_printf(s, " bank %d:\n", bank);
for (i = 0; i < debug_ranges[bank].count; i++) {
u8 reg;
for (reg = debug_ranges[bank].range[i].first;
reg <= debug_ranges[bank].range[i].last;
reg++) {
u8 value;
get_register_interruptible(ab, bank, reg,
&value);
seq_printf(s, " [%d/0x%02X]: 0x%02X\n", bank,
reg, value);
}
}
}
return 0;
}
static int ab3550_registers_open(struct inode *inode, struct file *file)
{
return single_open(file, ab3550_registers_print, inode->i_private);
}
static int ab3550_bank_print(struct seq_file *s, void *p)
{
struct ab3550 *ab = s->private;
seq_printf(s, "%d\n", ab->debug_bank);
return 0;
}
static int ab3550_bank_open(struct inode *inode, struct file *file)
{
return single_open(file, ab3550_bank_print, inode->i_private);
}
static ssize_t ab3550_bank_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab3550 *ab = ((struct seq_file *)(file->private_data))->private;
unsigned long user_bank;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_bank);
if (err)
return err;
if (user_bank >= AB3550_NUM_BANKS) {
dev_err(&ab->i2c_client[0]->dev,
"debugfs error input > number of banks\n");
return -EINVAL;
}
ab->debug_bank = user_bank;
return count;
}
static int ab3550_address_print(struct seq_file *s, void *p)
{
struct ab3550 *ab = s->private;
seq_printf(s, "0x%02X\n", ab->debug_address);
return 0;
}
static int ab3550_address_open(struct inode *inode, struct file *file)
{
return single_open(file, ab3550_address_print, inode->i_private);
}
static ssize_t ab3550_address_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab3550 *ab = ((struct seq_file *)(file->private_data))->private;
unsigned long user_address;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_address);
if (err)
return err;
if (user_address > 0xff) {
dev_err(&ab->i2c_client[0]->dev,
"debugfs error input > 0xff\n");
return -EINVAL;
}
ab->debug_address = user_address;
return count;
}
static int ab3550_val_print(struct seq_file *s, void *p)
{
struct ab3550 *ab = s->private;
int err;
u8 regvalue;
err = get_register_interruptible(ab, (u8)ab->debug_bank,
(u8)ab->debug_address, &regvalue);
if (err)
return -EINVAL;
seq_printf(s, "0x%02X\n", regvalue);
return 0;
}
static int ab3550_val_open(struct inode *inode, struct file *file)
{
return single_open(file, ab3550_val_print, inode->i_private);
}
static ssize_t ab3550_val_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab3550 *ab = ((struct seq_file *)(file->private_data))->private;
unsigned long user_val;
int err;
u8 regvalue;
err = kstrtoul_from_user(user_buf, count, 0, &user_val);
if (err)
return err;
if (user_val > 0xff) {
dev_err(&ab->i2c_client[0]->dev,
"debugfs error input > 0xff\n");
return -EINVAL;
}
err = mask_and_set_register_interruptible(
ab, (u8)ab->debug_bank,
(u8)ab->debug_address, 0xFF, (u8)user_val);
if (err)
return -EINVAL;
get_register_interruptible(ab, (u8)ab->debug_bank,
(u8)ab->debug_address, &regvalue);
if (err)
return -EINVAL;
return count;
}
static inline void ab3550_setup_debugfs(struct ab3550 *ab)
{
ab->debug_bank = 0;
ab->debug_address = 0x00;
ab3550_dir = debugfs_create_dir(AB3550_NAME_STRING, NULL);
if (!ab3550_dir)
goto exit_no_debugfs;
ab3550_reg_file = debugfs_create_file("all-registers",
S_IRUGO, ab3550_dir, ab, &ab3550_registers_fops);
if (!ab3550_reg_file)
goto exit_destroy_dir;
ab3550_bank_file = debugfs_create_file("register-bank",
(S_IRUGO | S_IWUSR), ab3550_dir, ab, &ab3550_bank_fops);
if (!ab3550_bank_file)
goto exit_destroy_reg;
ab3550_address_file = debugfs_create_file("register-address",
(S_IRUGO | S_IWUSR), ab3550_dir, ab, &ab3550_address_fops);
if (!ab3550_address_file)
goto exit_destroy_bank;
ab3550_val_file = debugfs_create_file("register-value",
(S_IRUGO | S_IWUSR), ab3550_dir, ab, &ab3550_val_fops);
if (!ab3550_val_file)
goto exit_destroy_address;
return;
exit_destroy_address:
debugfs_remove(ab3550_address_file);
exit_destroy_bank:
debugfs_remove(ab3550_bank_file);
exit_destroy_reg:
debugfs_remove(ab3550_reg_file);
exit_destroy_dir:
debugfs_remove(ab3550_dir);
exit_no_debugfs:
dev_err(&ab->i2c_client[0]->dev, "failed to create debugfs entries.\n");
return;
}
static inline void ab3550_remove_debugfs(void)
{
debugfs_remove(ab3550_val_file);
debugfs_remove(ab3550_address_file);
debugfs_remove(ab3550_bank_file);
debugfs_remove(ab3550_reg_file);
debugfs_remove(ab3550_dir);
}
static inline void ab3550_setup_debugfs(struct ab3550 *ab)
{
}
static inline void ab3550_remove_debugfs(void)
{
}
static int __init ab3550_setup(struct ab3550 *ab)
{
int err = 0;
int i;
struct ab3550_platform_data *plf_data;
struct abx500_init_settings *settings;
plf_data = ab->i2c_client[0]->dev.platform_data;
settings = plf_data->init_settings;
for (i = 0; i < plf_data->init_settings_sz; i++) {
err = mask_and_set_register_interruptible(ab,
settings[i].bank,
settings[i].reg,
0xFF, settings[i].setting);
if (err)
goto exit_no_setup;
if ((settings[i].bank == 0) &&
(AB3550_IMR1 <= settings[i].reg) &&
(settings[i].reg <= AB3550_IMR5)) {
ab->event_mask[settings[i].reg - AB3550_IMR1] =
settings[i].setting;
}
}
exit_no_setup:
return err;
}
static void ab3550_mask_work(struct work_struct *work)
{
struct ab3550 *ab = container_of(work, struct ab3550, mask_work);
int i;
unsigned long flags;
u8 mask[AB3550_NUM_EVENT_REG];
spin_lock_irqsave(&ab->event_lock, flags);
for (i = 0; i < AB3550_NUM_EVENT_REG; i++)
mask[i] = ab->event_mask[i];
spin_unlock_irqrestore(&ab->event_lock, flags);
for (i = 0; i < AB3550_NUM_EVENT_REG; i++) {
int err;
err = mask_and_set_register_interruptible(ab, 0,
(AB3550_IMR1 + i), ~0, mask[i]);
if (err)
dev_err(&ab->i2c_client[0]->dev,
"ab3550_mask_work failed 0x%x,0x%x\n",
(AB3550_IMR1 + i), mask[i]);
}
}
static void ab3550_mask(struct irq_data *data)
{
unsigned long flags;
struct ab3550 *ab;
struct ab3550_platform_data *plf_data;
int irq;
ab = irq_data_get_irq_chip_data(data);
plf_data = ab->i2c_client[0]->dev.platform_data;
irq = data->irq - plf_data->irq.base;
spin_lock_irqsave(&ab->event_lock, flags);
ab->event_mask[irq / 8] |= BIT(irq % 8);
spin_unlock_irqrestore(&ab->event_lock, flags);
schedule_work(&ab->mask_work);
}
static void ab3550_unmask(struct irq_data *data)
{
unsigned long flags;
struct ab3550 *ab;
struct ab3550_platform_data *plf_data;
int irq;
ab = irq_data_get_irq_chip_data(data);
plf_data = ab->i2c_client[0]->dev.platform_data;
irq = data->irq - plf_data->irq.base;
spin_lock_irqsave(&ab->event_lock, flags);
ab->event_mask[irq / 8] &= ~BIT(irq % 8);
spin_unlock_irqrestore(&ab->event_lock, flags);
schedule_work(&ab->mask_work);
}
static void noop(struct irq_data *data)
{
}
static int __init ab3550_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ab3550 *ab;
struct ab3550_platform_data *ab3550_plf_data =
client->dev.platform_data;
int err;
int i;
int num_i2c_clients = 0;
ab = kzalloc(sizeof(struct ab3550), GFP_KERNEL);
if (!ab) {
dev_err(&client->dev,
"could not allocate " AB3550_NAME_STRING " device\n");
return -ENOMEM;
}
mutex_init(&ab->access_mutex);
spin_lock_init(&ab->event_lock);
ab->i2c_client[0] = client;
i2c_set_clientdata(client, ab);
err = get_register_interruptible(ab, 0, AB3550_CID_REG, &ab->chip_id);
if (err) {
dev_err(&client->dev, "could not communicate with the analog "
"baseband chip\n");
goto exit_no_detect;
}
for (i = 0; ids[i].id != 0x0; i++) {
if (ids[i].id == ab->chip_id) {
snprintf(&ab->chip_name[0], sizeof(ab->chip_name) - 1,
AB3550_ID_FORMAT_STRING, ids[i].name);
break;
}
}
if (ids[i].id == 0x0) {
dev_err(&client->dev, "unknown analog baseband chip id: 0x%x\n",
ab->chip_id);
dev_err(&client->dev, "driver not started!\n");
goto exit_no_detect;
}
dev_info(&client->dev, "detected AB chip: %s\n", &ab->chip_name[0]);
while (++num_i2c_clients < AB3550_NUM_BANKS) {
ab->i2c_client[num_i2c_clients] =
i2c_new_dummy(client->adapter,
(client->addr + num_i2c_clients));
if (!ab->i2c_client[num_i2c_clients]) {
err = -ENOMEM;
goto exit_no_dummy_client;
}
strlcpy(ab->i2c_client[num_i2c_clients]->name, id->name,
sizeof(ab->i2c_client[num_i2c_clients]->name));
}
err = ab3550_setup(ab);
if (err)
goto exit_no_setup;
INIT_WORK(&ab->mask_work, ab3550_mask_work);
for (i = 0; i < ab3550_plf_data->irq.count; i++) {
unsigned int irq;
irq = ab3550_plf_data->irq.base + i;
irq_set_chip_data(irq, ab);
irq_set_chip_and_handler(irq, &ab3550_irq_chip,
handle_simple_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
err = request_threaded_irq(client->irq, NULL, ab3550_irq_handler,
IRQF_ONESHOT, "ab3550-core", ab);
rand_initialize_irq(client->irq);
if (err)
goto exit_no_irq;
err = abx500_register_ops(&client->dev, &ab3550_ops);
if (err)
goto exit_no_ops;
for (i = 0; i < AB3550_NUM_DEVICES; i++) {
ab3550_devs[i].platform_data = ab3550_plf_data->dev_data[i];
ab3550_devs[i].pdata_size = ab3550_plf_data->dev_data_sz[i];
}
err = mfd_add_devices(&client->dev, 0, ab3550_devs,
ARRAY_SIZE(ab3550_devs), NULL,
ab3550_plf_data->irq.base);
ab3550_setup_debugfs(ab);
return 0;
exit_no_ops:
exit_no_irq:
exit_no_setup:
exit_no_dummy_client:
while (--num_i2c_clients)
i2c_unregister_device(ab->i2c_client[num_i2c_clients]);
exit_no_detect:
kfree(ab);
return err;
}
static int __exit ab3550_remove(struct i2c_client *client)
{
struct ab3550 *ab = i2c_get_clientdata(client);
int num_i2c_clients = AB3550_NUM_BANKS;
mfd_remove_devices(&client->dev);
ab3550_remove_debugfs();
while (--num_i2c_clients)
i2c_unregister_device(ab->i2c_client[num_i2c_clients]);
free_irq(client->irq, ab);
kfree(ab);
return 0;
}
static int __init ab3550_i2c_init(void)
{
return i2c_add_driver(&ab3550_driver);
}
static void __exit ab3550_i2c_exit(void)
{
i2c_del_driver(&ab3550_driver);
}
