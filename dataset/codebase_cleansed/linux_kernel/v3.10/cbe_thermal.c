static inline u8 reg_to_temp(u8 reg_value)
{
return ((reg_value & 0x3f) << 1) + TEMP_MIN;
}
static inline u8 temp_to_reg(u8 temp)
{
return ((temp - TEMP_MIN) >> 1) & 0x3f;
}
static struct cbe_pmd_regs __iomem *get_pmd_regs(struct device *dev)
{
struct spu *spu;
spu = container_of(dev, struct spu, dev);
return cbe_get_pmd_regs(spu_devnode(spu));
}
static u8 spu_read_register_value(struct device *dev, union spe_reg __iomem *reg)
{
union spe_reg value;
struct spu *spu;
spu = container_of(dev, struct spu, dev);
value.val = in_be64(&reg->val);
return value.spe[spu->spe_id];
}
static ssize_t spu_show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
u8 value;
struct cbe_pmd_regs __iomem *pmd_regs;
pmd_regs = get_pmd_regs(dev);
value = spu_read_register_value(dev, &pmd_regs->ts_ctsr1);
return sprintf(buf, "%d\n", reg_to_temp(value));
}
static ssize_t show_throttle(struct cbe_pmd_regs __iomem *pmd_regs, char *buf, int pos)
{
u64 value;
value = in_be64(&pmd_regs->tm_tpr.val);
value >>= pos;
value &= 0x3F;
return sprintf(buf, "%d\n", reg_to_temp(value));
}
static ssize_t store_throttle(struct cbe_pmd_regs __iomem *pmd_regs, const char *buf, size_t size, int pos)
{
u64 reg_value;
int temp;
u64 new_value;
int ret;
ret = sscanf(buf, "%u", &temp);
if (ret != 1 || temp < TEMP_MIN || temp > TEMP_MAX)
return -EINVAL;
new_value = temp_to_reg(temp);
reg_value = in_be64(&pmd_regs->tm_tpr.val);
reg_value &= ~(0xffull << pos);
reg_value |= new_value << pos;
out_be64(&pmd_regs->tm_tpr.val, reg_value);
return size;
}
static ssize_t spu_show_throttle_end(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_throttle(get_pmd_regs(dev), buf, 0);
}
static ssize_t spu_show_throttle_begin(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_throttle(get_pmd_regs(dev), buf, 8);
}
static ssize_t spu_show_throttle_full_stop(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_throttle(get_pmd_regs(dev), buf, 16);
}
static ssize_t spu_store_throttle_end(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
return store_throttle(get_pmd_regs(dev), buf, size, 0);
}
static ssize_t spu_store_throttle_begin(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
return store_throttle(get_pmd_regs(dev), buf, size, 8);
}
static ssize_t spu_store_throttle_full_stop(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
return store_throttle(get_pmd_regs(dev), buf, size, 16);
}
static ssize_t ppe_show_temp(struct device *dev, char *buf, int pos)
{
struct cbe_pmd_regs __iomem *pmd_regs;
u64 value;
pmd_regs = cbe_get_cpu_pmd_regs(dev->id);
value = in_be64(&pmd_regs->ts_ctsr2);
value = (value >> pos) & 0x3f;
return sprintf(buf, "%d\n", reg_to_temp(value));
}
static ssize_t ppe_show_temp0(struct device *dev,
struct device_attribute *attr, char *buf)
{
return ppe_show_temp(dev, buf, 32);
}
static ssize_t ppe_show_temp1(struct device *dev,
struct device_attribute *attr, char *buf)
{
return ppe_show_temp(dev, buf, 0);
}
static ssize_t ppe_show_throttle_end(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_throttle(cbe_get_cpu_pmd_regs(dev->id), buf, 32);
}
static ssize_t ppe_show_throttle_begin(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_throttle(cbe_get_cpu_pmd_regs(dev->id), buf, 40);
}
static ssize_t ppe_show_throttle_full_stop(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_throttle(cbe_get_cpu_pmd_regs(dev->id), buf, 48);
}
static ssize_t ppe_store_throttle_end(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
return store_throttle(cbe_get_cpu_pmd_regs(dev->id), buf, size, 32);
}
static ssize_t ppe_store_throttle_begin(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
return store_throttle(cbe_get_cpu_pmd_regs(dev->id), buf, size, 40);
}
static ssize_t ppe_store_throttle_full_stop(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
return store_throttle(cbe_get_cpu_pmd_regs(dev->id), buf, size, 48);
}
static int __init init_default_values(void)
{
int cpu;
struct cbe_pmd_regs __iomem *pmd_regs;
struct device *dev;
union ppe_spe_reg tpr;
union spe_reg str1;
u64 str2;
union spe_reg cr1;
u64 cr2;
tpr.ppe = 0x1F0803;
tpr.spe = 0x100803;
str1.val = 0x1010101010101010ull;
str2 = 0x10;
cr1.val = 0x0404040404040404ull;
cr2 = 0x04;
for_each_possible_cpu (cpu) {
pr_debug("processing cpu %d\n", cpu);
dev = get_cpu_device(cpu);
if (!dev) {
pr_info("invalid dev pointer for cbe_thermal\n");
return -EINVAL;
}
pmd_regs = cbe_get_cpu_pmd_regs(dev->id);
if (!pmd_regs) {
pr_info("invalid CBE regs pointer for cbe_thermal\n");
return -EINVAL;
}
out_be64(&pmd_regs->tm_str2, str2);
out_be64(&pmd_regs->tm_str1.val, str1.val);
out_be64(&pmd_regs->tm_tpr.val, tpr.val);
out_be64(&pmd_regs->tm_cr1.val, cr1.val);
out_be64(&pmd_regs->tm_cr2, cr2);
}
return 0;
}
static int __init thermal_init(void)
{
int rc = init_default_values();
if (rc == 0) {
spu_add_dev_attr_group(&spu_attribute_group);
cpu_add_dev_attr_group(&ppe_attribute_group);
}
return rc;
}
static void __exit thermal_exit(void)
{
spu_remove_dev_attr_group(&spu_attribute_group);
cpu_remove_dev_attr_group(&ppe_attribute_group);
}
