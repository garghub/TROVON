static struct resource *
claim_region(struct pcmcia_socket *s, resource_size_t base,
resource_size_t size, int type, char *name)
{
struct resource *res, *parent;
parent = type & IORESOURCE_MEM ? &iomem_resource : &ioport_resource;
res = pcmcia_make_resource(base, size, type | IORESOURCE_BUSY, name);
if (res) {
#ifdef CONFIG_PCI
if (s && s->cb_dev)
parent = pci_find_parent_resource(s->cb_dev, res);
#endif
if (!parent || request_resource(parent, res)) {
kfree(res);
res = NULL;
}
}
return res;
}
static void free_region(struct resource *res)
{
if (res) {
release_resource(res);
kfree(res);
}
}
static int add_interval(struct resource_map *map, u_long base, u_long num)
{
struct resource_map *p, *q;
for (p = map; ; p = p->next) {
if ((p != map) && (p->base+p->num >= base)) {
p->num = max(num + base - p->base, p->num);
return 0;
}
if ((p->next == map) || (p->next->base > base+num-1))
break;
}
q = kmalloc(sizeof(struct resource_map), GFP_KERNEL);
if (!q) {
printk(KERN_WARNING "out of memory to update resources\n");
return -ENOMEM;
}
q->base = base; q->num = num;
q->next = p->next; p->next = q;
return 0;
}
static int sub_interval(struct resource_map *map, u_long base, u_long num)
{
struct resource_map *p, *q;
for (p = map; ; p = q) {
q = p->next;
if (q == map)
break;
if ((q->base+q->num > base) && (base+num > q->base)) {
if (q->base >= base) {
if (q->base+q->num <= base+num) {
p->next = q->next;
kfree(q);
q = p;
} else {
q->num = q->base + q->num - base - num;
q->base = base + num;
}
} else if (q->base+q->num <= base+num) {
q->num = base - q->base;
} else {
p = kmalloc(sizeof(struct resource_map),
GFP_KERNEL);
if (!p) {
printk(KERN_WARNING "out of memory to update resources\n");
return -ENOMEM;
}
p->base = base+num;
p->num = q->base+q->num - p->base;
q->num = base - q->base;
p->next = q->next ; q->next = p;
}
}
}
return 0;
}
static void do_io_probe(struct pcmcia_socket *s, unsigned int base,
unsigned int num)
{
struct resource *res;
struct socket_data *s_data = s->resource_data;
unsigned int i, j, bad;
int any;
u_char *b, hole, most;
dev_info(&s->dev, "cs: IO port probe %#x-%#x:", base, base+num-1);
b = kzalloc(256, GFP_KERNEL);
if (!b) {
pr_cont("\n");
dev_err(&s->dev, "do_io_probe: unable to kmalloc 256 bytes\n");
return;
}
for (i = base, most = 0; i < base+num; i += 8) {
res = claim_region(s, i, 8, IORESOURCE_IO, "PCMCIA ioprobe");
if (!res)
continue;
hole = inb(i);
for (j = 1; j < 8; j++)
if (inb(i+j) != hole)
break;
free_region(res);
if ((j == 8) && (++b[hole] > b[most]))
most = hole;
if (b[most] == 127)
break;
}
kfree(b);
bad = any = 0;
for (i = base; i < base+num; i += 8) {
res = claim_region(s, i, 8, IORESOURCE_IO, "PCMCIA ioprobe");
if (!res) {
if (!any)
pr_cont(" excluding");
if (!bad)
bad = any = i;
continue;
}
for (j = 0; j < 8; j++)
if (inb(i+j) != most)
break;
free_region(res);
if (j < 8) {
if (!any)
pr_cont(" excluding");
if (!bad)
bad = any = i;
} else {
if (bad) {
sub_interval(&s_data->io_db, bad, i-bad);
pr_cont(" %#x-%#x", bad, i-1);
bad = 0;
}
}
}
if (bad) {
if ((num > 16) && (bad == base) && (i == base+num)) {
sub_interval(&s_data->io_db, bad, i-bad);
pr_cont(" nothing: probe failed.\n");
return;
} else {
sub_interval(&s_data->io_db, bad, i-bad);
pr_cont(" %#x-%#x", bad, i-1);
}
}
pr_cont("%s\n", !any ? " clean" : "");
}
static int readable(struct pcmcia_socket *s, struct resource *res,
unsigned int *count)
{
int ret = -EINVAL;
if (s->fake_cis) {
dev_dbg(&s->dev, "fake CIS is being used: can't validate mem\n");
return 0;
}
s->cis_mem.res = res;
s->cis_virt = ioremap(res->start, s->map_size);
if (s->cis_virt) {
mutex_unlock(&s->ops_mutex);
if (s->callback->validate)
ret = s->callback->validate(s, count);
mutex_lock(&s->ops_mutex);
iounmap(s->cis_virt);
s->cis_virt = NULL;
}
s->cis_mem.res = NULL;
if ((ret) || (*count == 0))
return -EINVAL;
return 0;
}
static int checksum(struct pcmcia_socket *s, struct resource *res,
unsigned int *value)
{
pccard_mem_map map;
int i, a = 0, b = -1, d;
void __iomem *virt;
virt = ioremap(res->start, s->map_size);
if (virt) {
map.map = 0;
map.flags = MAP_ACTIVE;
map.speed = 0;
map.res = res;
map.card_start = 0;
s->ops->set_mem_map(s, &map);
for (i = 0; i < s->map_size; i += 44) {
d = readl(virt+i);
a += d;
b &= d;
}
map.flags = 0;
s->ops->set_mem_map(s, &map);
iounmap(virt);
}
if (b == -1)
return -EINVAL;
*value = a;
return 0;
}
static int do_validate_mem(struct pcmcia_socket *s,
unsigned long base, unsigned long size,
int validate (struct pcmcia_socket *s,
struct resource *res,
unsigned int *value))
{
struct socket_data *s_data = s->resource_data;
struct resource *res1, *res2;
unsigned int info1 = 1, info2 = 1;
int ret = -EINVAL;
res1 = claim_region(s, base, size/2, IORESOURCE_MEM, "PCMCIA memprobe");
res2 = claim_region(s, base + size/2, size/2, IORESOURCE_MEM,
"PCMCIA memprobe");
if (res1 && res2) {
ret = 0;
if (validate) {
ret = validate(s, res1, &info1);
ret += validate(s, res2, &info2);
}
}
dev_dbg(&s->dev, "cs: memory probe 0x%06lx-0x%06lx: %p %p %u %u %u",
base, base+size-1, res1, res2, ret, info1, info2);
free_region(res2);
free_region(res1);
if ((ret) || (info1 != info2) || (info1 == 0))
return -EINVAL;
if (validate && !s->fake_cis) {
add_interval(&s_data->mem_db_valid, base, size);
sub_interval(&s_data->mem_db, base, size);
}
return 0;
}
static int do_mem_probe(struct pcmcia_socket *s, u_long base, u_long num,
int validate (struct pcmcia_socket *s,
struct resource *res,
unsigned int *value),
int fallback (struct pcmcia_socket *s,
struct resource *res,
unsigned int *value))
{
struct socket_data *s_data = s->resource_data;
u_long i, j, bad, fail, step;
dev_info(&s->dev, "cs: memory probe 0x%06lx-0x%06lx:",
base, base+num-1);
bad = fail = 0;
step = (num < 0x20000) ? 0x2000 : ((num>>4) & ~0x1fff);
if (step > 0x800000)
step = 0x800000;
if (step < 2 * s->map_size)
step = 2 * s->map_size;
for (i = j = base; i < base+num; i = j + step) {
if (!fail) {
for (j = i; j < base+num; j += step) {
if (!do_validate_mem(s, j, step, validate))
break;
}
fail = ((i == base) && (j == base+num));
}
if ((fail) && (fallback)) {
for (j = i; j < base+num; j += step)
if (!do_validate_mem(s, j, step, fallback))
break;
}
if (i != j) {
if (!bad)
pr_cont(" excluding");
pr_cont(" %#05lx-%#05lx", i, j-1);
sub_interval(&s_data->mem_db, i, j-i);
bad += j-i;
}
}
pr_cont("%s\n", !bad ? " clean" : "");
return num - bad;
}
static u_long inv_probe(struct resource_map *m, struct pcmcia_socket *s)
{
struct socket_data *s_data = s->resource_data;
u_long ok;
if (m == &s_data->mem_db)
return 0;
ok = inv_probe(m->next, s);
if (ok) {
if (m->base >= 0x100000)
sub_interval(&s_data->mem_db, m->base, m->num);
return ok;
}
if (m->base < 0x100000)
return 0;
return do_mem_probe(s, m->base, m->num, readable, checksum);
}
static int validate_mem(struct pcmcia_socket *s, unsigned int probe_mask)
{
struct resource_map *m, mm;
static unsigned char order[] = { 0xd0, 0xe0, 0xc0, 0xf0 };
unsigned long b, i, ok = 0;
struct socket_data *s_data = s->resource_data;
if (probe_mask & MEM_PROBE_HIGH) {
if (inv_probe(s_data->mem_db.next, s) > 0)
return 0;
if (s_data->mem_db_valid.next != &s_data->mem_db_valid)
return 0;
dev_notice(&s->dev,
"cs: warning: no high memory space available!\n");
return -ENODEV;
}
for (m = s_data->mem_db.next; m != &s_data->mem_db; m = mm.next) {
mm = *m;
if (mm.base >= 0x100000)
continue;
if ((mm.base | mm.num) & 0xffff) {
ok += do_mem_probe(s, mm.base, mm.num, readable,
checksum);
continue;
}
for (i = 0; i < 4; i++) {
b = order[i] << 12;
if ((b >= mm.base) && (b+0x10000 <= mm.base+mm.num)) {
if (ok >= mem_limit)
sub_interval(&s_data->mem_db, b, 0x10000);
else
ok += do_mem_probe(s, b, 0x10000,
readable, checksum);
}
}
}
if (ok > 0)
return 0;
return -ENODEV;
}
static int validate_mem(struct pcmcia_socket *s, unsigned int probe_mask)
{
struct resource_map *m, mm;
struct socket_data *s_data = s->resource_data;
unsigned long ok = 0;
for (m = s_data->mem_db.next; m != &s_data->mem_db; m = mm.next) {
mm = *m;
ok += do_mem_probe(s, mm.base, mm.num, readable, checksum);
}
if (ok > 0)
return 0;
return -ENODEV;
}
static int pcmcia_nonstatic_validate_mem(struct pcmcia_socket *s)
{
struct socket_data *s_data = s->resource_data;
unsigned int probe_mask = MEM_PROBE_LOW;
int ret;
if (!probe_mem || !(s->state & SOCKET_PRESENT))
return 0;
if (s->features & SS_CAP_PAGE_REGS)
probe_mask = MEM_PROBE_HIGH;
ret = validate_mem(s, probe_mask);
if (s_data->mem_db_valid.next != &s_data->mem_db_valid)
return 0;
return ret;
}
static resource_size_t pcmcia_common_align(struct pcmcia_align_data *align_data,
resource_size_t start)
{
resource_size_t ret;
ret = (start & ~align_data->mask) + align_data->offset;
if (ret < start)
ret += align_data->mask + 1;
return ret;
}
static resource_size_t
pcmcia_align(void *align_data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
struct pcmcia_align_data *data = align_data;
struct resource_map *m;
resource_size_t start;
start = pcmcia_common_align(data, res->start);
for (m = data->map->next; m != data->map; m = m->next) {
unsigned long map_start = m->base;
unsigned long map_end = m->base + m->num - 1;
if (start < map_start)
start = pcmcia_common_align(data, map_start);
if (start >= res->end)
break;
if ((start + size - 1) <= map_end)
break;
}
if (m == data->map)
start = res->end;
return start;
}
static int __nonstatic_adjust_io_region(struct pcmcia_socket *s,
unsigned long r_start,
unsigned long r_end)
{
struct resource_map *m;
struct socket_data *s_data = s->resource_data;
int ret = -ENOMEM;
for (m = s_data->io_db.next; m != &s_data->io_db; m = m->next) {
unsigned long start = m->base;
unsigned long end = m->base + m->num - 1;
if (start > r_start || r_end > end)
continue;
ret = 0;
}
return ret;
}
static struct resource *__nonstatic_find_io_region(struct pcmcia_socket *s,
unsigned long base, int num,
unsigned long align)
{
struct resource *res = pcmcia_make_resource(0, num, IORESOURCE_IO,
dev_name(&s->dev));
struct socket_data *s_data = s->resource_data;
struct pcmcia_align_data data;
unsigned long min = base;
int ret;
data.mask = align - 1;
data.offset = base & data.mask;
data.map = &s_data->io_db;
#ifdef CONFIG_PCI
if (s->cb_dev) {
ret = pci_bus_alloc_resource(s->cb_dev->bus, res, num, 1,
min, 0, pcmcia_align, &data);
} else
#endif
ret = allocate_resource(&ioport_resource, res, num, min, ~0UL,
1, pcmcia_align, &data);
if (ret != 0) {
kfree(res);
res = NULL;
}
return res;
}
static int nonstatic_find_io(struct pcmcia_socket *s, unsigned int attr,
unsigned int *base, unsigned int num,
unsigned int align, struct resource **parent)
{
int i, ret = 0;
for (i = 0; i < MAX_IO_WIN; i++) {
if (!s->io[i].res)
continue;
if (!*base)
continue;
if ((s->io[i].res->start & (align-1)) == *base)
return -EBUSY;
}
for (i = 0; i < MAX_IO_WIN; i++) {
struct resource *res = s->io[i].res;
unsigned int try;
if (res && (res->flags & IORESOURCE_BITS) !=
(attr & IORESOURCE_BITS))
continue;
if (!res) {
if (align == 0)
align = 0x10000;
res = s->io[i].res = __nonstatic_find_io_region(s,
*base, num,
align);
if (!res)
return -EINVAL;
*base = res->start;
s->io[i].res->flags =
((res->flags & ~IORESOURCE_BITS) |
(attr & IORESOURCE_BITS));
s->io[i].InUse = num;
*parent = res;
return 0;
}
try = res->end + 1;
if ((*base == 0) || (*base == try)) {
ret = __nonstatic_adjust_io_region(s, res->start,
res->end + num);
if (!ret) {
ret = adjust_resource(s->io[i].res, res->start,
resource_size(res) + num);
if (ret)
continue;
*base = try;
s->io[i].InUse += num;
*parent = res;
return 0;
}
}
try = res->start - num;
if ((*base == 0) || (*base == try)) {
ret = __nonstatic_adjust_io_region(s,
res->start - num,
res->end);
if (!ret) {
ret = adjust_resource(s->io[i].res,
res->start - num,
resource_size(res) + num);
if (ret)
continue;
*base = try;
s->io[i].InUse += num;
*parent = res;
return 0;
}
}
}
return -EINVAL;
}
static struct resource *nonstatic_find_mem_region(u_long base, u_long num,
u_long align, int low, struct pcmcia_socket *s)
{
struct resource *res = pcmcia_make_resource(0, num, IORESOURCE_MEM,
dev_name(&s->dev));
struct socket_data *s_data = s->resource_data;
struct pcmcia_align_data data;
unsigned long min, max;
int ret, i, j;
low = low || !(s->features & SS_CAP_PAGE_REGS);
data.mask = align - 1;
data.offset = base & data.mask;
for (i = 0; i < 2; i++) {
data.map = &s_data->mem_db_valid;
if (low) {
max = 0x100000UL;
min = base < max ? base : 0;
} else {
max = ~0UL;
min = 0x100000UL + base;
}
for (j = 0; j < 2; j++) {
#ifdef CONFIG_PCI
if (s->cb_dev) {
ret = pci_bus_alloc_resource(s->cb_dev->bus,
res, num, 1, min, 0,
pcmcia_align, &data);
} else
#endif
{
ret = allocate_resource(&iomem_resource,
res, num, min, max, 1,
pcmcia_align, &data);
}
if (ret == 0)
break;
data.map = &s_data->mem_db;
}
if (ret == 0 || low)
break;
low = 1;
}
if (ret != 0) {
kfree(res);
res = NULL;
}
return res;
}
static int adjust_memory(struct pcmcia_socket *s, unsigned int action, unsigned long start, unsigned long end)
{
struct socket_data *data = s->resource_data;
unsigned long size = end - start + 1;
int ret = 0;
if (end < start)
return -EINVAL;
switch (action) {
case ADD_MANAGED_RESOURCE:
ret = add_interval(&data->mem_db, start, size);
if (!ret)
do_mem_probe(s, start, size, NULL, NULL);
break;
case REMOVE_MANAGED_RESOURCE:
ret = sub_interval(&data->mem_db, start, size);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int adjust_io(struct pcmcia_socket *s, unsigned int action, unsigned long start, unsigned long end)
{
struct socket_data *data = s->resource_data;
unsigned long size;
int ret = 0;
#if defined(CONFIG_X86)
if (start < 0x100)
start = 0x100;
#endif
size = end - start + 1;
if (end < start)
return -EINVAL;
if (end > IO_SPACE_LIMIT)
return -EINVAL;
switch (action) {
case ADD_MANAGED_RESOURCE:
if (add_interval(&data->io_db, start, size) != 0) {
ret = -EBUSY;
break;
}
#ifdef CONFIG_PCMCIA_PROBE
if (probe_io)
do_io_probe(s, start, size);
#endif
break;
case REMOVE_MANAGED_RESOURCE:
sub_interval(&data->io_db, start, size);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static inline int nonstatic_autoadd_resources(struct pcmcia_socket *s)
{
return -ENODEV;
}
static int nonstatic_init(struct pcmcia_socket *s)
{
struct socket_data *data;
data = kzalloc(sizeof(struct socket_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->mem_db.next = &data->mem_db;
data->mem_db_valid.next = &data->mem_db_valid;
data->io_db.next = &data->io_db;
s->resource_data = (void *) data;
nonstatic_autoadd_resources(s);
return 0;
}
static void nonstatic_release_resource_db(struct pcmcia_socket *s)
{
struct socket_data *data = s->resource_data;
struct resource_map *p, *q;
for (p = data->mem_db_valid.next; p != &data->mem_db_valid; p = q) {
q = p->next;
kfree(p);
}
for (p = data->mem_db.next; p != &data->mem_db; p = q) {
q = p->next;
kfree(p);
}
for (p = data->io_db.next; p != &data->io_db; p = q) {
q = p->next;
kfree(p);
}
}
static ssize_t show_io_db(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pcmcia_socket *s = dev_get_drvdata(dev);
struct socket_data *data;
struct resource_map *p;
ssize_t ret = 0;
mutex_lock(&s->ops_mutex);
data = s->resource_data;
for (p = data->io_db.next; p != &data->io_db; p = p->next) {
if (ret > (PAGE_SIZE - 10))
continue;
ret += snprintf(&buf[ret], (PAGE_SIZE - ret - 1),
"0x%08lx - 0x%08lx\n",
((unsigned long) p->base),
((unsigned long) p->base + p->num - 1));
}
mutex_unlock(&s->ops_mutex);
return ret;
}
static ssize_t store_io_db(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_socket *s = dev_get_drvdata(dev);
unsigned long start_addr, end_addr;
unsigned int add = ADD_MANAGED_RESOURCE;
ssize_t ret = 0;
ret = sscanf(buf, "+ 0x%lx - 0x%lx", &start_addr, &end_addr);
if (ret != 2) {
ret = sscanf(buf, "- 0x%lx - 0x%lx", &start_addr, &end_addr);
add = REMOVE_MANAGED_RESOURCE;
if (ret != 2) {
ret = sscanf(buf, "0x%lx - 0x%lx", &start_addr,
&end_addr);
add = ADD_MANAGED_RESOURCE;
if (ret != 2)
return -EINVAL;
}
}
if (end_addr < start_addr)
return -EINVAL;
mutex_lock(&s->ops_mutex);
ret = adjust_io(s, add, start_addr, end_addr);
mutex_unlock(&s->ops_mutex);
return ret ? ret : count;
}
static ssize_t show_mem_db(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pcmcia_socket *s = dev_get_drvdata(dev);
struct socket_data *data;
struct resource_map *p;
ssize_t ret = 0;
mutex_lock(&s->ops_mutex);
data = s->resource_data;
for (p = data->mem_db_valid.next; p != &data->mem_db_valid;
p = p->next) {
if (ret > (PAGE_SIZE - 10))
continue;
ret += snprintf(&buf[ret], (PAGE_SIZE - ret - 1),
"0x%08lx - 0x%08lx\n",
((unsigned long) p->base),
((unsigned long) p->base + p->num - 1));
}
for (p = data->mem_db.next; p != &data->mem_db; p = p->next) {
if (ret > (PAGE_SIZE - 10))
continue;
ret += snprintf(&buf[ret], (PAGE_SIZE - ret - 1),
"0x%08lx - 0x%08lx\n",
((unsigned long) p->base),
((unsigned long) p->base + p->num - 1));
}
mutex_unlock(&s->ops_mutex);
return ret;
}
static ssize_t store_mem_db(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_socket *s = dev_get_drvdata(dev);
unsigned long start_addr, end_addr;
unsigned int add = ADD_MANAGED_RESOURCE;
ssize_t ret = 0;
ret = sscanf(buf, "+ 0x%lx - 0x%lx", &start_addr, &end_addr);
if (ret != 2) {
ret = sscanf(buf, "- 0x%lx - 0x%lx", &start_addr, &end_addr);
add = REMOVE_MANAGED_RESOURCE;
if (ret != 2) {
ret = sscanf(buf, "0x%lx - 0x%lx", &start_addr,
&end_addr);
add = ADD_MANAGED_RESOURCE;
if (ret != 2)
return -EINVAL;
}
}
if (end_addr < start_addr)
return -EINVAL;
mutex_lock(&s->ops_mutex);
ret = adjust_memory(s, add, start_addr, end_addr);
mutex_unlock(&s->ops_mutex);
return ret ? ret : count;
}
static int pccard_sysfs_add_rsrc(struct device *dev,
struct class_interface *class_intf)
{
struct pcmcia_socket *s = dev_get_drvdata(dev);
if (s->resource_ops != &pccard_nonstatic_ops)
return 0;
return sysfs_create_group(&dev->kobj, &rsrc_attributes);
}
static void pccard_sysfs_remove_rsrc(struct device *dev,
struct class_interface *class_intf)
{
struct pcmcia_socket *s = dev_get_drvdata(dev);
if (s->resource_ops != &pccard_nonstatic_ops)
return;
sysfs_remove_group(&dev->kobj, &rsrc_attributes);
}
static int __init nonstatic_sysfs_init(void)
{
return class_interface_register(&pccard_rsrc_interface);
}
static void __exit nonstatic_sysfs_exit(void)
{
class_interface_unregister(&pccard_rsrc_interface);
}
