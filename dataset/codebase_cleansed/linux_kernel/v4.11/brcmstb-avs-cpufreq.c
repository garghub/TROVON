static char *__strtolower(char *s)
{
char *p;
for (p = s; *p; p++)
*p = tolower(*p);
return s;
}
static void __iomem *__map_region(const char *name)
{
struct device_node *np;
void __iomem *ptr;
np = of_find_compatible_node(NULL, NULL, name);
if (!np)
return NULL;
ptr = of_iomap(np, 0);
of_node_put(np);
return ptr;
}
static int __issue_avs_command(struct private_data *priv, int cmd, bool is_send,
u32 args[])
{
unsigned long time_left = msecs_to_jiffies(AVS_TIMEOUT);
void __iomem *base = priv->base;
unsigned int i;
int ret;
u32 val;
ret = down_interruptible(&priv->sem);
if (ret)
return ret;
for (i = 0, val = 1; val != 0 && i < AVS_LOOP_LIMIT; i++)
val = readl(base + AVS_MBOX_COMMAND);
if (i == AVS_LOOP_LIMIT) {
ret = -EAGAIN;
goto out;
}
writel(AVS_STATUS_CLEAR, base + AVS_MBOX_STATUS);
if (args && is_send) {
for (i = 0; i < AVS_MAX_CMD_ARGS; i++)
writel(args[i], base + AVS_MBOX_PARAM(i));
}
reinit_completion(&priv->done);
writel(cmd, base + AVS_MBOX_COMMAND);
writel(AVS_CPU_L2_INT_MASK, priv->avs_intr_base + AVS_CPU_L2_SET0);
time_left = wait_for_completion_timeout(&priv->done, time_left);
val = readl(base + AVS_MBOX_STATUS);
if (time_left == 0 || val == 0 || val > AVS_STATUS_MAX) {
dev_err(priv->dev, "AVS command %#x didn't complete in time\n",
cmd);
dev_err(priv->dev, " Time left: %u ms, AVS status: %#x\n",
jiffies_to_msecs(time_left), val);
ret = -ETIMEDOUT;
goto out;
}
if (args && !is_send) {
for (i = 0; i < AVS_MAX_CMD_ARGS; i++)
args[i] = readl(base + AVS_MBOX_PARAM(i));
}
writel(AVS_STATUS_CLEAR, base + AVS_MBOX_STATUS);
switch (val) {
case AVS_STATUS_INVALID:
ret = -EINVAL;
break;
case AVS_STATUS_NO_SUPP:
ret = -ENOTSUPP;
break;
case AVS_STATUS_NO_MAP:
ret = -ENOENT;
break;
case AVS_STATUS_MAP_SET:
ret = -EEXIST;
break;
case AVS_STATUS_FAILURE:
ret = -EIO;
break;
}
out:
up(&priv->sem);
return ret;
}
static irqreturn_t irq_handler(int irq, void *data)
{
struct private_data *priv = data;
complete(&priv->done);
return IRQ_HANDLED;
}
static char *brcm_avs_mode_to_string(unsigned int mode)
{
switch (mode) {
case AVS_MODE_AVS:
return "AVS";
case AVS_MODE_DFS:
return "DFS";
case AVS_MODE_DVS:
return "DVS";
case AVS_MODE_DVFS:
return "DVFS";
}
return NULL;
}
static void brcm_avs_parse_p1(u32 p1, unsigned int *mdiv_p0, unsigned int *pdiv,
unsigned int *ndiv)
{
*mdiv_p0 = (p1 >> MDIV_P0_SHIFT) & MDIV_P0_MASK;
*pdiv = (p1 >> PDIV_SHIFT) & PDIV_MASK;
*ndiv = (p1 >> NDIV_INT_SHIFT) & NDIV_INT_MASK;
}
static void brcm_avs_parse_p2(u32 p2, unsigned int *mdiv_p1,
unsigned int *mdiv_p2, unsigned int *mdiv_p3,
unsigned int *mdiv_p4)
{
*mdiv_p4 = (p2 >> MDIV_P4_SHIFT) & MDIV_P4_MASK;
*mdiv_p3 = (p2 >> MDIV_P3_SHIFT) & MDIV_P3_MASK;
*mdiv_p2 = (p2 >> MDIV_P2_SHIFT) & MDIV_P2_MASK;
*mdiv_p1 = (p2 >> MDIV_P1_SHIFT) & MDIV_P1_MASK;
}
static int brcm_avs_get_pmap(struct private_data *priv, struct pmap *pmap)
{
u32 args[AVS_MAX_CMD_ARGS];
int ret;
ret = __issue_avs_command(priv, AVS_CMD_GET_PMAP, false, args);
if (ret || !pmap)
return ret;
pmap->mode = args[0];
pmap->p1 = args[1];
pmap->p2 = args[2];
pmap->state = args[3];
return 0;
}
static int brcm_avs_set_pmap(struct private_data *priv, struct pmap *pmap)
{
u32 args[AVS_MAX_CMD_ARGS];
args[0] = pmap->mode;
args[1] = pmap->p1;
args[2] = pmap->p2;
args[3] = pmap->state;
return __issue_avs_command(priv, AVS_CMD_SET_PMAP, true, args);
}
static int brcm_avs_get_pstate(struct private_data *priv, unsigned int *pstate)
{
u32 args[AVS_MAX_CMD_ARGS];
int ret;
ret = __issue_avs_command(priv, AVS_CMD_GET_PSTATE, false, args);
if (ret)
return ret;
*pstate = args[0];
return 0;
}
static int brcm_avs_set_pstate(struct private_data *priv, unsigned int pstate)
{
u32 args[AVS_MAX_CMD_ARGS];
args[0] = pstate;
return __issue_avs_command(priv, AVS_CMD_SET_PSTATE, true, args);
}
static unsigned long brcm_avs_get_voltage(void __iomem *base)
{
return readl(base + AVS_MBOX_VOLTAGE1);
}
static unsigned long brcm_avs_get_frequency(void __iomem *base)
{
return readl(base + AVS_MBOX_FREQUENCY) * 1000;
}
static struct cpufreq_frequency_table *
brcm_avs_get_freq_table(struct device *dev, struct private_data *priv)
{
struct cpufreq_frequency_table *table;
unsigned int pstate;
int i, ret;
ret = brcm_avs_get_pstate(priv, &pstate);
if (ret)
return ERR_PTR(ret);
table = devm_kzalloc(dev, (AVS_PSTATE_MAX + 1) * sizeof(*table),
GFP_KERNEL);
if (!table)
return ERR_PTR(-ENOMEM);
for (i = AVS_PSTATE_P0; i <= AVS_PSTATE_MAX; i++) {
ret = brcm_avs_set_pstate(priv, i);
if (ret)
return ERR_PTR(ret);
table[i].frequency = brcm_avs_get_frequency(priv->base);
table[i].driver_data = i;
}
table[i].frequency = CPUFREQ_TABLE_END;
ret = brcm_avs_set_pstate(priv, pstate);
if (ret)
return ERR_PTR(ret);
return table;
}
static int brcm_avs_debug_show(struct seq_file *s, void *data)
{
struct debugfs_data *dbgfs = s->private;
void __iomem *base;
u32 val, offset;
if (!dbgfs) {
seq_puts(s, "No device pointer\n");
return 0;
}
base = dbgfs->priv->base;
offset = dbgfs->entry->offset;
val = readl(base + offset);
switch (dbgfs->entry->format) {
case DEBUGFS_NORMAL:
seq_printf(s, "%u\n", val);
break;
case DEBUGFS_FLOAT:
seq_printf(s, "%d.%03d\n", MANT(val), FRAC(val));
break;
case DEBUGFS_REV:
seq_printf(s, "%c.%c.%c.%c\n", (val >> 24 & 0xff),
(val >> 16 & 0xff), (val >> 8 & 0xff),
val & 0xff);
break;
}
seq_printf(s, "0x%08x\n", val);
return 0;
}
static ssize_t brcm_avs_seq_write(struct file *file, const char __user *buf,
size_t size, loff_t *ppos)
{
struct seq_file *s = file->private_data;
struct debugfs_data *dbgfs = s->private;
struct private_data *priv = dbgfs->priv;
void __iomem *base, *avs_intr_base;
bool use_issue_command = false;
unsigned long val, offset;
char str[128];
int ret;
char *str_ptr = str;
if (size >= sizeof(str))
return -E2BIG;
memset(str, 0, sizeof(str));
ret = copy_from_user(str, buf, size);
if (ret)
return ret;
base = priv->base;
avs_intr_base = priv->avs_intr_base;
offset = dbgfs->entry->offset;
if (str_ptr[0] == 'c' && offset == AVS_MBOX_COMMAND) {
use_issue_command = true;
str_ptr++;
}
if (kstrtoul(str_ptr, 0, &val) != 0)
return -EINVAL;
if (val == AVS_CMD_SET_PSTATE) {
struct cpufreq_policy *policy;
unsigned int pstate;
policy = cpufreq_cpu_get(smp_processor_id());
pstate = readl(base + AVS_MBOX_PARAM(0));
if (use_issue_command) {
ret = brcm_avs_target_index(policy, pstate);
return ret ? ret : size;
}
policy->cur = policy->freq_table[pstate].frequency;
}
if (use_issue_command) {
ret = __issue_avs_command(priv, val, false, NULL);
} else {
ret = down_interruptible(&priv->sem);
if (ret)
return ret;
writel(val, base + offset);
if (offset == AVS_MBOX_COMMAND)
writel(AVS_CPU_L2_INT_MASK,
avs_intr_base + AVS_CPU_L2_SET0);
up(&priv->sem);
}
return ret ? ret : size;
}
static struct debugfs_entry *__find_debugfs_entry(const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(debugfs_entries); i++)
if (strcasecmp(debugfs_entries[i].name, name) == 0)
return &debugfs_entries[i];
return NULL;
}
static int brcm_avs_debug_open(struct inode *inode, struct file *file)
{
struct debugfs_data *data;
fmode_t fmode;
int ret;
fmode = file->f_mode;
if ((fmode & FMODE_WRITER) && !(inode->i_mode & S_IWUSR))
return -EACCES;
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->entry = __find_debugfs_entry(file->f_path.dentry->d_iname);
data->priv = inode->i_private;
ret = single_open(file, brcm_avs_debug_show, data);
if (ret)
kfree(data);
file->f_mode = fmode;
return ret;
}
static int brcm_avs_debug_release(struct inode *inode, struct file *file)
{
struct seq_file *seq_priv = file->private_data;
struct debugfs_data *data = seq_priv->private;
kfree(data);
return single_release(inode, file);
}
static void brcm_avs_cpufreq_debug_init(struct platform_device *pdev)
{
struct private_data *priv = platform_get_drvdata(pdev);
struct dentry *dir;
int i;
if (!priv)
return;
dir = debugfs_create_dir(BRCM_AVS_CPUFREQ_NAME, NULL);
if (IS_ERR_OR_NULL(dir))
return;
priv->debugfs = dir;
for (i = 0; i < ARRAY_SIZE(debugfs_entries); i++) {
char *entry = __strtolower(debugfs_entries[i].name);
fmode_t mode = debugfs_entries[i].mode;
if (!debugfs_create_file(entry, S_IFREG | S_IRUGO | mode,
dir, priv, &brcm_avs_debug_ops)) {
priv->debugfs = NULL;
debugfs_remove_recursive(dir);
break;
}
}
}
static void brcm_avs_cpufreq_debug_exit(struct platform_device *pdev)
{
struct private_data *priv = platform_get_drvdata(pdev);
if (priv && priv->debugfs) {
debugfs_remove_recursive(priv->debugfs);
priv->debugfs = NULL;
}
}
static void brcm_avs_cpufreq_debug_init(struct platform_device *pdev) {}
static void brcm_avs_cpufreq_debug_exit(struct platform_device *pdev) {}
static bool brcm_avs_is_firmware_loaded(struct private_data *priv)
{
u32 magic;
int rc;
rc = brcm_avs_get_pmap(priv, NULL);
magic = readl(priv->base + AVS_MBOX_MAGIC);
return (magic == AVS_FIRMWARE_MAGIC) && (rc != -ENOTSUPP) &&
(rc != -EINVAL);
}
static unsigned int brcm_avs_cpufreq_get(unsigned int cpu)
{
struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
struct private_data *priv = policy->driver_data;
return brcm_avs_get_frequency(priv->base);
}
static int brcm_avs_target_index(struct cpufreq_policy *policy,
unsigned int index)
{
return brcm_avs_set_pstate(policy->driver_data,
policy->freq_table[index].driver_data);
}
static int brcm_avs_suspend(struct cpufreq_policy *policy)
{
struct private_data *priv = policy->driver_data;
int ret;
ret = brcm_avs_get_pmap(priv, &priv->pmap);
if (ret)
return ret;
return brcm_avs_get_pstate(priv, &priv->pmap.state);
}
static int brcm_avs_resume(struct cpufreq_policy *policy)
{
struct private_data *priv = policy->driver_data;
int ret;
ret = brcm_avs_set_pmap(priv, &priv->pmap);
if (ret == -EEXIST) {
struct platform_device *pdev = cpufreq_get_driver_data();
struct device *dev = &pdev->dev;
dev_warn(dev, "PMAP was already set\n");
ret = 0;
}
return ret;
}
static int brcm_avs_prepare_init(struct platform_device *pdev)
{
struct private_data *priv;
struct device *dev;
int host_irq, ret;
dev = &pdev->dev;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
sema_init(&priv->sem, 1);
init_completion(&priv->done);
platform_set_drvdata(pdev, priv);
priv->base = __map_region(BRCM_AVS_CPU_DATA);
if (!priv->base) {
dev_err(dev, "Couldn't find property %s in device tree.\n",
BRCM_AVS_CPU_DATA);
return -ENOENT;
}
priv->avs_intr_base = __map_region(BRCM_AVS_CPU_INTR);
if (!priv->avs_intr_base) {
dev_err(dev, "Couldn't find property %s in device tree.\n",
BRCM_AVS_CPU_INTR);
ret = -ENOENT;
goto unmap_base;
}
host_irq = platform_get_irq_byname(pdev, BRCM_AVS_HOST_INTR);
if (host_irq < 0) {
dev_err(dev, "Couldn't find interrupt %s -- %d\n",
BRCM_AVS_HOST_INTR, host_irq);
ret = host_irq;
goto unmap_intr_base;
}
ret = devm_request_irq(dev, host_irq, irq_handler, IRQF_TRIGGER_RISING,
BRCM_AVS_HOST_INTR, priv);
if (ret) {
dev_err(dev, "IRQ request failed: %s (%d) -- %d\n",
BRCM_AVS_HOST_INTR, host_irq, ret);
goto unmap_intr_base;
}
if (brcm_avs_is_firmware_loaded(priv))
return 0;
dev_err(dev, "AVS firmware is not loaded or doesn't support DVFS\n");
ret = -ENODEV;
unmap_intr_base:
iounmap(priv->avs_intr_base);
unmap_base:
iounmap(priv->base);
return ret;
}
static int brcm_avs_cpufreq_init(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *freq_table;
struct platform_device *pdev;
struct private_data *priv;
struct device *dev;
int ret;
pdev = cpufreq_get_driver_data();
priv = platform_get_drvdata(pdev);
policy->driver_data = priv;
dev = &pdev->dev;
freq_table = brcm_avs_get_freq_table(dev, priv);
if (IS_ERR(freq_table)) {
ret = PTR_ERR(freq_table);
dev_err(dev, "Couldn't determine frequency table (%d).\n", ret);
return ret;
}
ret = cpufreq_table_validate_and_show(policy, freq_table);
if (ret) {
dev_err(dev, "invalid frequency table: %d\n", ret);
return ret;
}
cpumask_setall(policy->cpus);
ret = __issue_avs_command(priv, AVS_CMD_ENABLE, false, NULL);
if (!ret) {
unsigned int pstate;
ret = brcm_avs_get_pstate(priv, &pstate);
if (!ret) {
policy->cur = freq_table[pstate].frequency;
dev_info(dev, "registered\n");
return 0;
}
}
dev_err(dev, "couldn't initialize driver (%d)\n", ret);
return ret;
}
static ssize_t show_brcm_avs_pstate(struct cpufreq_policy *policy, char *buf)
{
struct private_data *priv = policy->driver_data;
unsigned int pstate;
if (brcm_avs_get_pstate(priv, &pstate))
return sprintf(buf, "<unknown>\n");
return sprintf(buf, "%u\n", pstate);
}
static ssize_t show_brcm_avs_mode(struct cpufreq_policy *policy, char *buf)
{
struct private_data *priv = policy->driver_data;
struct pmap pmap;
if (brcm_avs_get_pmap(priv, &pmap))
return sprintf(buf, "<unknown>\n");
return sprintf(buf, "%s %u\n", brcm_avs_mode_to_string(pmap.mode),
pmap.mode);
}
static ssize_t show_brcm_avs_pmap(struct cpufreq_policy *policy, char *buf)
{
unsigned int mdiv_p0, mdiv_p1, mdiv_p2, mdiv_p3, mdiv_p4;
struct private_data *priv = policy->driver_data;
unsigned int ndiv, pdiv;
struct pmap pmap;
if (brcm_avs_get_pmap(priv, &pmap))
return sprintf(buf, "<unknown>\n");
brcm_avs_parse_p1(pmap.p1, &mdiv_p0, &pdiv, &ndiv);
brcm_avs_parse_p2(pmap.p2, &mdiv_p1, &mdiv_p2, &mdiv_p3, &mdiv_p4);
return sprintf(buf, "0x%08x 0x%08x %u %u %u %u %u %u %u %u %u\n",
pmap.p1, pmap.p2, ndiv, pdiv, mdiv_p0, mdiv_p1, mdiv_p2,
mdiv_p3, mdiv_p4, pmap.mode, pmap.state);
}
static ssize_t show_brcm_avs_voltage(struct cpufreq_policy *policy, char *buf)
{
struct private_data *priv = policy->driver_data;
return sprintf(buf, "0x%08lx\n", brcm_avs_get_voltage(priv->base));
}
static ssize_t show_brcm_avs_frequency(struct cpufreq_policy *policy, char *buf)
{
struct private_data *priv = policy->driver_data;
return sprintf(buf, "0x%08lx\n", brcm_avs_get_frequency(priv->base));
}
static int brcm_avs_cpufreq_probe(struct platform_device *pdev)
{
int ret;
ret = brcm_avs_prepare_init(pdev);
if (ret)
return ret;
brcm_avs_driver.driver_data = pdev;
ret = cpufreq_register_driver(&brcm_avs_driver);
if (!ret)
brcm_avs_cpufreq_debug_init(pdev);
return ret;
}
static int brcm_avs_cpufreq_remove(struct platform_device *pdev)
{
struct private_data *priv;
int ret;
ret = cpufreq_unregister_driver(&brcm_avs_driver);
if (ret)
return ret;
brcm_avs_cpufreq_debug_exit(pdev);
priv = platform_get_drvdata(pdev);
iounmap(priv->base);
iounmap(priv->avs_intr_base);
return 0;
}
