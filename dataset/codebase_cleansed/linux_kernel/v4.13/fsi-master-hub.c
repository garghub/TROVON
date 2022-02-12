static int hub_master_read(struct fsi_master *master, int link,
uint8_t id, uint32_t addr, void *val, size_t size)
{
struct fsi_master_hub *hub = to_fsi_master_hub(master);
if (id != 0)
return -EINVAL;
addr += hub->addr + (link * FSI_HUB_LINK_SIZE);
return fsi_slave_read(hub->upstream->slave, addr, val, size);
}
static int hub_master_write(struct fsi_master *master, int link,
uint8_t id, uint32_t addr, const void *val, size_t size)
{
struct fsi_master_hub *hub = to_fsi_master_hub(master);
if (id != 0)
return -EINVAL;
addr += hub->addr + (link * FSI_HUB_LINK_SIZE);
return fsi_slave_write(hub->upstream->slave, addr, val, size);
}
static int hub_master_break(struct fsi_master *master, int link)
{
uint32_t addr, cmd;
addr = 0x4;
cmd = cpu_to_be32(0xc0de0000);
return hub_master_write(master, link, 0, addr, &cmd, sizeof(cmd));
}
static int hub_master_link_enable(struct fsi_master *master, int link)
{
struct fsi_master_hub *hub = to_fsi_master_hub(master);
int idx, bit;
__be32 reg;
int rc;
idx = link / 32;
bit = link % 32;
reg = cpu_to_be32(0x80000000 >> bit);
rc = fsi_device_write(hub->upstream, FSI_MSENP0 + (4 * idx), &reg, 4);
mdelay(FSI_LINK_ENABLE_SETUP_TIME);
fsi_device_read(hub->upstream, FSI_MENP0 + (4 * idx), &reg, 4);
return rc;
}
static void hub_master_release(struct device *dev)
{
struct fsi_master_hub *hub = to_fsi_master_hub(dev_to_fsi_master(dev));
kfree(hub);
}
static inline u32 fsi_mmode_crs0(u32 x)
{
return (x & FSI_MMODE_CRS0MASK) << FSI_MMODE_CRS0SHFT;
}
static inline u32 fsi_mmode_crs1(u32 x)
{
return (x & FSI_MMODE_CRS1MASK) << FSI_MMODE_CRS1SHFT;
}
static int hub_master_init(struct fsi_master_hub *hub)
{
struct fsi_device *dev = hub->upstream;
__be32 reg;
int rc;
reg = cpu_to_be32(FSI_MRESP_RST_ALL_MASTER | FSI_MRESP_RST_ALL_LINK
| FSI_MRESP_RST_MCR | FSI_MRESP_RST_PYE);
rc = fsi_device_write(dev, FSI_MRESP0, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(FSI_MRESP_RST_ALL_MASTER | FSI_MRESP_RST_ALL_LINK
| FSI_MRESP_RST_MCR | FSI_MRESP_RST_PYE);
rc = fsi_device_write(dev, FSI_MRESP0, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(FSI_MECTRL_EOAE | FSI_MECTRL_P8_AUTO_TERM);
rc = fsi_device_write(dev, FSI_MECTRL, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(FSI_MMODE_EIP | FSI_MMODE_ECRC | FSI_MMODE_EPC
| fsi_mmode_crs0(1) | fsi_mmode_crs1(1)
| FSI_MMODE_P8_TO_LSB);
rc = fsi_device_write(dev, FSI_MMODE, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(0xffff0000);
rc = fsi_device_write(dev, FSI_MDLYR, &reg, sizeof(reg));
if (rc)
return rc;
reg = ~0;
rc = fsi_device_write(dev, FSI_MSENP0, &reg, sizeof(reg));
if (rc)
return rc;
mdelay(FSI_LINK_ENABLE_SETUP_TIME);
rc = fsi_device_write(dev, FSI_MCENP0, &reg, sizeof(reg));
if (rc)
return rc;
rc = fsi_device_read(dev, FSI_MAEB, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(FSI_MRESP_RST_ALL_MASTER | FSI_MRESP_RST_ALL_LINK);
rc = fsi_device_write(dev, FSI_MRESP0, &reg, sizeof(reg));
if (rc)
return rc;
rc = fsi_device_read(dev, FSI_MLEVP0, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(FSI_MRESB_RST_GEN);
rc = fsi_device_write(dev, FSI_MRESB0, &reg, sizeof(reg));
if (rc)
return rc;
reg = cpu_to_be32(FSI_MRESB_RST_ERR);
return fsi_device_write(dev, FSI_MRESB0, &reg, sizeof(reg));
}
static int hub_master_probe(struct device *dev)
{
struct fsi_device *fsi_dev = to_fsi_dev(dev);
struct fsi_master_hub *hub;
uint32_t reg, links;
__be32 __reg;
int rc;
rc = fsi_device_read(fsi_dev, FSI_MVER, &__reg, sizeof(__reg));
if (rc)
return rc;
reg = be32_to_cpu(__reg);
links = (reg >> 8) & 0xff;
dev_info(dev, "hub version %08x (%d links)\n", reg, links);
rc = fsi_slave_claim_range(fsi_dev->slave, FSI_HUB_LINK_OFFSET,
FSI_HUB_LINK_SIZE * links);
if (rc) {
dev_err(dev, "can't claim slave address range for links");
return rc;
}
hub = kzalloc(sizeof(*hub), GFP_KERNEL);
if (!hub) {
rc = -ENOMEM;
goto err_release;
}
hub->addr = FSI_HUB_LINK_OFFSET;
hub->size = FSI_HUB_LINK_SIZE * links;
hub->upstream = fsi_dev;
hub->master.dev.parent = dev;
hub->master.dev.release = hub_master_release;
hub->master.n_links = links;
hub->master.read = hub_master_read;
hub->master.write = hub_master_write;
hub->master.send_break = hub_master_break;
hub->master.link_enable = hub_master_link_enable;
dev_set_drvdata(dev, hub);
hub_master_init(hub);
rc = fsi_master_register(&hub->master);
if (!rc)
return 0;
kfree(hub);
err_release:
fsi_slave_release_range(fsi_dev->slave, FSI_HUB_LINK_OFFSET,
FSI_HUB_LINK_SIZE * links);
return rc;
}
static int hub_master_remove(struct device *dev)
{
struct fsi_master_hub *hub = dev_get_drvdata(dev);
fsi_master_unregister(&hub->master);
fsi_slave_release_range(hub->upstream->slave, hub->addr, hub->size);
return 0;
}
