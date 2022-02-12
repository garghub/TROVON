static int ms02nv_read(struct mtd_info *mtd, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct ms02nv_private *mp = mtd->priv;
memcpy(buf, mp->uaddr + from, len);
*retlen = len;
return 0;
}
static int ms02nv_write(struct mtd_info *mtd, loff_t to,
size_t len, size_t *retlen, const u_char *buf)
{
struct ms02nv_private *mp = mtd->priv;
memcpy(mp->uaddr + to, buf, len);
*retlen = len;
return 0;
}
static inline uint ms02nv_probe_one(ulong addr)
{
ms02nv_uint *ms02nv_diagp;
ms02nv_uint *ms02nv_magicp;
uint ms02nv_diag;
uint ms02nv_magic;
size_t size;
int err;
ms02nv_diagp = (ms02nv_uint *)(CKSEG1ADDR(addr + MS02NV_DIAG));
ms02nv_magicp = (ms02nv_uint *)(CKSEG1ADDR(addr + MS02NV_MAGIC));
err = get_dbe(ms02nv_magic, ms02nv_magicp);
if (err)
return 0;
if (ms02nv_magic != MS02NV_ID)
return 0;
ms02nv_diag = *ms02nv_diagp;
size = (ms02nv_diag & MS02NV_DIAG_SIZE_MASK) << MS02NV_DIAG_SIZE_SHIFT;
if (size > MS02NV_CSR)
size = MS02NV_CSR;
return size;
}
static int __init ms02nv_init_one(ulong addr)
{
struct mtd_info *mtd;
struct ms02nv_private *mp;
struct resource *mod_res;
struct resource *diag_res;
struct resource *user_res;
struct resource *csr_res;
ulong fixaddr;
size_t size, fixsize;
static int version_printed;
int ret = -ENODEV;
mod_res = kzalloc(sizeof(*mod_res), GFP_KERNEL);
if (!mod_res)
return -ENOMEM;
mod_res->name = ms02nv_name;
mod_res->start = addr;
mod_res->end = addr + MS02NV_SLOT_SIZE - 1;
mod_res->flags = IORESOURCE_MEM | IORESOURCE_BUSY;
if (request_resource(&iomem_resource, mod_res) < 0)
goto err_out_mod_res;
size = ms02nv_probe_one(addr);
if (!size)
goto err_out_mod_res_rel;
if (!version_printed) {
printk(KERN_INFO "%s", version);
version_printed = 1;
}
ret = -ENOMEM;
mtd = kzalloc(sizeof(*mtd), GFP_KERNEL);
if (!mtd)
goto err_out_mod_res_rel;
mp = kzalloc(sizeof(*mp), GFP_KERNEL);
if (!mp)
goto err_out_mtd;
mtd->priv = mp;
mp->resource.module = mod_res;
diag_res = kzalloc(sizeof(*diag_res), GFP_KERNEL);
if (!diag_res)
goto err_out_mp;
diag_res->name = ms02nv_res_diag_ram;
diag_res->start = addr;
diag_res->end = addr + MS02NV_RAM - 1;
diag_res->flags = IORESOURCE_BUSY;
request_resource(mod_res, diag_res);
mp->resource.diag_ram = diag_res;
user_res = kzalloc(sizeof(*user_res), GFP_KERNEL);
if (!user_res)
goto err_out_diag_res;
user_res->name = ms02nv_res_user_ram;
user_res->start = addr + MS02NV_RAM;
user_res->end = addr + size - 1;
user_res->flags = IORESOURCE_BUSY;
request_resource(mod_res, user_res);
mp->resource.user_ram = user_res;
csr_res = kzalloc(sizeof(*csr_res), GFP_KERNEL);
if (!csr_res)
goto err_out_user_res;
csr_res->name = ms02nv_res_csr;
csr_res->start = addr + MS02NV_CSR;
csr_res->end = addr + MS02NV_CSR + 3;
csr_res->flags = IORESOURCE_BUSY;
request_resource(mod_res, csr_res);
mp->resource.csr = csr_res;
mp->addr = phys_to_virt(addr);
mp->size = size;
fixaddr = (addr + MS02NV_RAM + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1);
fixsize = (size - (fixaddr - addr)) & ~(PAGE_SIZE - 1);
mp->uaddr = phys_to_virt(fixaddr);
mtd->type = MTD_RAM;
mtd->flags = MTD_CAP_RAM;
mtd->size = fixsize;
mtd->name = (char *)ms02nv_name;
mtd->owner = THIS_MODULE;
mtd->_read = ms02nv_read;
mtd->_write = ms02nv_write;
mtd->writesize = 1;
ret = -EIO;
if (mtd_device_register(mtd, NULL, 0)) {
printk(KERN_ERR
"ms02-nv: Unable to register MTD device, aborting!\n");
goto err_out_csr_res;
}
printk(KERN_INFO "mtd%d: %s at 0x%08lx, size %zuMiB.\n",
mtd->index, ms02nv_name, addr, size >> 20);
mp->next = root_ms02nv_mtd;
root_ms02nv_mtd = mtd;
return 0;
err_out_csr_res:
release_resource(csr_res);
kfree(csr_res);
err_out_user_res:
release_resource(user_res);
kfree(user_res);
err_out_diag_res:
release_resource(diag_res);
kfree(diag_res);
err_out_mp:
kfree(mp);
err_out_mtd:
kfree(mtd);
err_out_mod_res_rel:
release_resource(mod_res);
err_out_mod_res:
kfree(mod_res);
return ret;
}
static void __exit ms02nv_remove_one(void)
{
struct mtd_info *mtd = root_ms02nv_mtd;
struct ms02nv_private *mp = mtd->priv;
root_ms02nv_mtd = mp->next;
mtd_device_unregister(mtd);
release_resource(mp->resource.csr);
kfree(mp->resource.csr);
release_resource(mp->resource.user_ram);
kfree(mp->resource.user_ram);
release_resource(mp->resource.diag_ram);
kfree(mp->resource.diag_ram);
release_resource(mp->resource.module);
kfree(mp->resource.module);
kfree(mp);
kfree(mtd);
}
static int __init ms02nv_init(void)
{
volatile u32 *csr;
uint stride = 0;
int count = 0;
int i;
switch (mips_machtype) {
case MACH_DS5000_200:
csr = (volatile u32 *)CKSEG1ADDR(KN02_SLOT_BASE + KN02_CSR);
if (*csr & KN02_CSR_BNK32M)
stride = 2;
break;
case MACH_DS5000_2X0:
case MACH_DS5900:
csr = (volatile u32 *)CKSEG1ADDR(KN03_SLOT_BASE + IOASIC_MCR);
if (*csr & KN03_MCR_BNK32M)
stride = 2;
break;
default:
return -ENODEV;
break;
}
for (i = 0; i < ARRAY_SIZE(ms02nv_addrs); i++)
if (!ms02nv_init_one(ms02nv_addrs[i] << stride))
count++;
return (count > 0) ? 0 : -ENODEV;
}
static void __exit ms02nv_cleanup(void)
{
while (root_ms02nv_mtd)
ms02nv_remove_one();
}
