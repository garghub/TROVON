static const struct mips_cdmm_device_id *
mips_cdmm_lookup(const struct mips_cdmm_device_id *table,
struct mips_cdmm_device *dev)
{
int ret = 0;
for (; table->type; ++table) {
ret = (dev->type == table->type);
if (ret)
break;
}
return ret ? table : NULL;
}
static int mips_cdmm_match(struct device *dev, struct device_driver *drv)
{
struct mips_cdmm_device *cdev = to_mips_cdmm_device(dev);
struct mips_cdmm_driver *cdrv = to_mips_cdmm_driver(drv);
return mips_cdmm_lookup(cdrv->id_table, cdev) != NULL;
}
static int mips_cdmm_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct mips_cdmm_device *cdev = to_mips_cdmm_device(dev);
int retval = 0;
retval = add_uevent_var(env, "CDMM_CPU=%u", cdev->cpu);
if (retval)
return retval;
retval = add_uevent_var(env, "CDMM_TYPE=0x%02x", cdev->type);
if (retval)
return retval;
retval = add_uevent_var(env, "CDMM_REV=%u", cdev->rev);
if (retval)
return retval;
retval = add_uevent_var(env, "MODALIAS=mipscdmm:t%02X", cdev->type);
return retval;
}
static long mips_cdmm_void_work(void *data)
{
struct mips_cdmm_work_dev *work = data;
void (*fn)(struct mips_cdmm_device *) = work->fn;
fn(work->dev);
return 0;
}
static long mips_cdmm_int_work(void *data)
{
struct mips_cdmm_work_dev *work = data;
int (*fn)(struct mips_cdmm_device *) = work->fn;
return fn(work->dev);
}
int mips_cdmm_driver_register(struct mips_cdmm_driver *drv)
{
drv->drv.bus = &mips_cdmm_bustype;
if (drv->probe)
drv->drv.probe = mips_cdmm_probe;
if (drv->remove)
drv->drv.remove = mips_cdmm_remove;
if (drv->shutdown)
drv->drv.shutdown = mips_cdmm_shutdown;
return driver_register(&drv->drv);
}
void mips_cdmm_driver_unregister(struct mips_cdmm_driver *drv)
{
driver_unregister(&drv->drv);
}
static struct mips_cdmm_bus *mips_cdmm_get_bus(void)
{
struct mips_cdmm_bus *bus, **bus_p;
unsigned long flags;
unsigned int cpu;
if (!cpu_has_cdmm)
return ERR_PTR(-ENODEV);
cpu = smp_processor_id();
if (cpu == 0)
return &mips_cdmm_boot_bus;
bus_p = per_cpu_ptr(&mips_cdmm_buses, cpu);
local_irq_save(flags);
bus = *bus_p;
if (unlikely(!bus)) {
bus = kzalloc(sizeof(*bus), GFP_ATOMIC);
if (unlikely(!bus))
bus = ERR_PTR(-ENOMEM);
else
*bus_p = bus;
}
local_irq_restore(flags);
return bus;
}
static phys_addr_t mips_cdmm_cur_base(void)
{
unsigned long cdmmbase = read_c0_cdmmbase();
if (!(cdmmbase & MIPS_CDMMBASE_EN))
return 0;
return (cdmmbase >> MIPS_CDMMBASE_ADDR_SHIFT)
<< MIPS_CDMMBASE_ADDR_START;
}
phys_addr_t __weak mips_cdmm_phys_base(void)
{
return 0;
}
static int mips_cdmm_setup(struct mips_cdmm_bus *bus)
{
unsigned long cdmmbase, flags;
int ret = 0;
if (IS_ERR(bus))
return PTR_ERR(bus);
local_irq_save(flags);
if (bus->offline) {
if (bus->phys == mips_cdmm_cur_base())
goto out;
bus->offline = false;
} else if (bus->phys > 1) {
goto out;
}
if (!bus->phys)
bus->phys = mips_cdmm_cur_base();
if (!bus->phys)
bus->phys = mips_cdmm_phys_base();
if (!bus->phys)
bus->phys = mips_cdmm_default_base;
if (!bus->phys) {
bus->phys = 1;
pr_err("cdmm%u: Failed to choose a physical base\n",
smp_processor_id());
}
if (bus->phys == 1) {
ret = -ENOMEM;
goto out;
}
mips_cdmm_default_base = bus->phys;
pr_debug("cdmm%u: Enabling CDMM region at %pa\n",
smp_processor_id(), &bus->phys);
cdmmbase = read_c0_cdmmbase();
cdmmbase &= (1ul << MIPS_CDMMBASE_ADDR_SHIFT) - 1;
cdmmbase |= (bus->phys >> MIPS_CDMMBASE_ADDR_START)
<< MIPS_CDMMBASE_ADDR_SHIFT;
cdmmbase |= MIPS_CDMMBASE_EN;
write_c0_cdmmbase(cdmmbase);
tlbw_use_hazard();
bus->regs = (void __iomem *)CKSEG1ADDR(bus->phys);
bus->drbs = 1 + ((cdmmbase & MIPS_CDMMBASE_SIZE) >>
MIPS_CDMMBASE_SIZE_SHIFT);
bus->drbs_reserved = !!(cdmmbase & MIPS_CDMMBASE_CI);
out:
local_irq_restore(flags);
return ret;
}
void __iomem *mips_cdmm_early_probe(unsigned int dev_type)
{
struct mips_cdmm_bus *bus;
void __iomem *cdmm;
u32 acsr;
unsigned int drb, type, size;
int err;
if (WARN_ON(!dev_type))
return IOMEM_ERR_PTR(-ENODEV);
bus = mips_cdmm_get_bus();
err = mips_cdmm_setup(bus);
if (err)
return IOMEM_ERR_PTR(err);
drb = bus->drbs_reserved;
cdmm = bus->regs;
for (; drb < bus->drbs; drb += size + 1) {
acsr = __raw_readl(cdmm + drb * CDMM_DRB_SIZE);
type = (acsr & CDMM_ACSR_DEVTYPE) >> CDMM_ACSR_DEVTYPE_SHIFT;
if (type == dev_type)
return cdmm + drb * CDMM_DRB_SIZE;
size = (acsr & CDMM_ACSR_DEVSIZE) >> CDMM_ACSR_DEVSIZE_SHIFT;
}
return IOMEM_ERR_PTR(-ENODEV);
}
static void mips_cdmm_release(struct device *dev)
{
struct mips_cdmm_device *cdev = to_mips_cdmm_device(dev);
kfree(cdev);
}
static void mips_cdmm_bus_discover(struct mips_cdmm_bus *bus)
{
void __iomem *cdmm;
u32 acsr;
unsigned int drb, type, size, rev;
struct mips_cdmm_device *dev;
unsigned int cpu = smp_processor_id();
int ret = 0;
int id = 0;
drb = bus->drbs_reserved;
cdmm = bus->regs;
bus->discovered = true;
pr_info("cdmm%u discovery (%u blocks)\n", cpu, bus->drbs);
for (; drb < bus->drbs; drb += size + 1) {
acsr = __raw_readl(cdmm + drb * CDMM_DRB_SIZE);
type = (acsr & CDMM_ACSR_DEVTYPE) >> CDMM_ACSR_DEVTYPE_SHIFT;
size = (acsr & CDMM_ACSR_DEVSIZE) >> CDMM_ACSR_DEVSIZE_SHIFT;
rev = (acsr & CDMM_ACSR_DEVREV) >> CDMM_ACSR_DEVREV_SHIFT;
if (!type)
continue;
pr_info("cdmm%u-%u: @%u (%#x..%#x), type 0x%02x, rev %u\n",
cpu, id, drb, drb * CDMM_DRB_SIZE,
(drb + size + 1) * CDMM_DRB_SIZE - 1,
type, rev);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
break;
dev->cpu = cpu;
dev->res.start = bus->phys + drb * CDMM_DRB_SIZE;
dev->res.end = bus->phys +
(drb + size + 1) * CDMM_DRB_SIZE - 1;
dev->res.flags = IORESOURCE_MEM;
dev->type = type;
dev->rev = rev;
dev->dev.parent = get_cpu_device(cpu);
dev->dev.bus = &mips_cdmm_bustype;
dev->dev.id = atomic_inc_return(&mips_cdmm_next_id);
dev->dev.release = mips_cdmm_release;
dev_set_name(&dev->dev, "cdmm%u-%u", cpu, id);
++id;
ret = device_register(&dev->dev);
if (ret) {
put_device(&dev->dev);
kfree(dev);
}
}
}
static long mips_cdmm_bus_down(void *data)
{
struct mips_cdmm_bus *bus;
long ret;
ret = bus_for_each_dev(&mips_cdmm_bustype, NULL, data,
mips_cdmm_cpu_down_helper);
bus = mips_cdmm_get_bus();
if (!IS_ERR(bus))
bus->offline = true;
return ret;
}
static long mips_cdmm_bus_up(void *data)
{
struct mips_cdmm_bus *bus;
long ret;
bus = mips_cdmm_get_bus();
ret = mips_cdmm_setup(bus);
if (ret)
return ret;
bus->offline = false;
if (!bus->discovered)
mips_cdmm_bus_discover(bus);
else
ret = bus_for_each_dev(&mips_cdmm_bustype, NULL, data,
mips_cdmm_cpu_up_helper);
return ret;
}
static int mips_cdmm_cpu_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
unsigned int cpu = (unsigned int)data;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_ONLINE:
case CPU_DOWN_FAILED:
work_on_cpu(cpu, mips_cdmm_bus_up, &cpu);
break;
case CPU_DOWN_PREPARE:
work_on_cpu(cpu, mips_cdmm_bus_down, &cpu);
break;
default:
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static int __init mips_cdmm_init(void)
{
unsigned int cpu;
int ret;
ret = bus_register(&mips_cdmm_bustype);
if (ret)
return ret;
ret = register_cpu_notifier(&mips_cdmm_cpu_nb);
if (ret) {
pr_warn("cdmm: Failed to register CPU notifier\n");
goto out;
}
for_each_online_cpu(cpu)
work_on_cpu(cpu, mips_cdmm_bus_up, &cpu);
return 0;
out:
bus_unregister(&mips_cdmm_bustype);
return ret;
}
