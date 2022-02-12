static void pcmcia_check_driver(struct pcmcia_driver *p_drv)
{
const struct pcmcia_device_id *did = p_drv->id_table;
unsigned int i;
u32 hash;
if (!p_drv->probe || !p_drv->remove)
printk(KERN_DEBUG "pcmcia: %s lacks a requisite callback "
"function\n", p_drv->name);
while (did && did->match_flags) {
for (i = 0; i < 4; i++) {
if (!did->prod_id[i])
continue;
hash = crc32(0, did->prod_id[i], strlen(did->prod_id[i]));
if (hash == did->prod_id_hash[i])
continue;
printk(KERN_DEBUG "pcmcia: %s: invalid hash for "
"product string \"%s\": is 0x%x, should "
"be 0x%x\n", p_drv->name, did->prod_id[i],
did->prod_id_hash[i], hash);
printk(KERN_DEBUG "pcmcia: see "
"Documentation/pcmcia/devicetable.txt for "
"details\n");
}
did++;
}
return;
}
static ssize_t
pcmcia_store_new_id(struct device_driver *driver, const char *buf, size_t count)
{
struct pcmcia_dynid *dynid;
struct pcmcia_driver *pdrv = to_pcmcia_drv(driver);
__u16 match_flags, manf_id, card_id;
__u8 func_id, function, device_no;
__u32 prod_id_hash[4] = {0, 0, 0, 0};
int fields = 0;
int retval = 0;
fields = sscanf(buf, "%hx %hx %hx %hhx %hhx %hhx %x %x %x %x",
&match_flags, &manf_id, &card_id, &func_id, &function, &device_no,
&prod_id_hash[0], &prod_id_hash[1], &prod_id_hash[2], &prod_id_hash[3]);
if (fields < 6)
return -EINVAL;
dynid = kzalloc(sizeof(struct pcmcia_dynid), GFP_KERNEL);
if (!dynid)
return -ENOMEM;
dynid->id.match_flags = match_flags;
dynid->id.manf_id = manf_id;
dynid->id.card_id = card_id;
dynid->id.func_id = func_id;
dynid->id.function = function;
dynid->id.device_no = device_no;
memcpy(dynid->id.prod_id_hash, prod_id_hash, sizeof(__u32) * 4);
mutex_lock(&pdrv->dynids.lock);
list_add_tail(&dynid->node, &pdrv->dynids.list);
mutex_unlock(&pdrv->dynids.lock);
retval = driver_attach(&pdrv->drv);
if (retval)
return retval;
return count;
}
static void
pcmcia_free_dynids(struct pcmcia_driver *drv)
{
struct pcmcia_dynid *dynid, *n;
mutex_lock(&drv->dynids.lock);
list_for_each_entry_safe(dynid, n, &drv->dynids.list, node) {
list_del(&dynid->node);
kfree(dynid);
}
mutex_unlock(&drv->dynids.lock);
}
static int
pcmcia_create_newid_file(struct pcmcia_driver *drv)
{
int error = 0;
if (drv->probe != NULL)
error = driver_create_file(&drv->drv, &driver_attr_new_id);
return error;
}
static void
pcmcia_remove_newid_file(struct pcmcia_driver *drv)
{
driver_remove_file(&drv->drv, &driver_attr_new_id);
}
int pcmcia_register_driver(struct pcmcia_driver *driver)
{
int error;
if (!driver)
return -EINVAL;
pcmcia_check_driver(driver);
driver->drv.bus = &pcmcia_bus_type;
driver->drv.owner = driver->owner;
driver->drv.name = driver->name;
mutex_init(&driver->dynids.lock);
INIT_LIST_HEAD(&driver->dynids.list);
pr_debug("registering driver %s\n", driver->name);
error = driver_register(&driver->drv);
if (error < 0)
return error;
error = pcmcia_create_newid_file(driver);
if (error)
driver_unregister(&driver->drv);
return error;
}
void pcmcia_unregister_driver(struct pcmcia_driver *driver)
{
pr_debug("unregistering driver %s\n", driver->name);
pcmcia_remove_newid_file(driver);
driver_unregister(&driver->drv);
pcmcia_free_dynids(driver);
}
static struct pcmcia_device *pcmcia_get_dev(struct pcmcia_device *p_dev)
{
struct device *tmp_dev;
tmp_dev = get_device(&p_dev->dev);
if (!tmp_dev)
return NULL;
return to_pcmcia_dev(tmp_dev);
}
static void pcmcia_put_dev(struct pcmcia_device *p_dev)
{
if (p_dev)
put_device(&p_dev->dev);
}
static void pcmcia_release_function(struct kref *ref)
{
struct config_t *c = container_of(ref, struct config_t, ref);
pr_debug("releasing config_t\n");
kfree(c);
}
static void pcmcia_release_dev(struct device *dev)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
int i;
dev_dbg(dev, "releasing device\n");
pcmcia_put_socket(p_dev->socket);
for (i = 0; i < 4; i++)
kfree(p_dev->prod_id[i]);
kfree(p_dev->devname);
kref_put(&p_dev->function_config->ref, pcmcia_release_function);
kfree(p_dev);
}
static int pcmcia_device_probe(struct device *dev)
{
struct pcmcia_device *p_dev;
struct pcmcia_driver *p_drv;
struct pcmcia_socket *s;
cistpl_config_t cis_config;
int ret = 0;
dev = get_device(dev);
if (!dev)
return -ENODEV;
p_dev = to_pcmcia_dev(dev);
p_drv = to_pcmcia_drv(dev->driver);
s = p_dev->socket;
dev_dbg(dev, "trying to bind to %s\n", p_drv->name);
if ((!p_drv->probe) || (!p_dev->function_config) ||
(!try_module_get(p_drv->owner))) {
ret = -EINVAL;
goto put_dev;
}
ret = pccard_read_tuple(p_dev->socket, p_dev->func, CISTPL_CONFIG,
&cis_config);
if (!ret) {
p_dev->config_base = cis_config.base;
p_dev->config_regs = cis_config.rmask[0];
dev_dbg(dev, "base %x, regs %x", p_dev->config_base,
p_dev->config_regs);
} else {
dev_info(dev,
"pcmcia: could not parse base and rmask0 of CIS\n");
p_dev->config_base = 0;
p_dev->config_regs = 0;
}
ret = p_drv->probe(p_dev);
if (ret) {
dev_dbg(dev, "binding to %s failed with %d\n",
p_drv->name, ret);
goto put_module;
}
dev_dbg(dev, "%s bound: Vpp %d.%d, idx %x, IRQ %d", p_drv->name,
p_dev->vpp/10, p_dev->vpp%10, p_dev->config_index, p_dev->irq);
dev_dbg(dev, "resources: ioport %pR %pR iomem %pR %pR %pR",
p_dev->resource[0], p_dev->resource[1], p_dev->resource[2],
p_dev->resource[3], p_dev->resource[4]);
mutex_lock(&s->ops_mutex);
if ((s->pcmcia_pfc) &&
(p_dev->socket->device_count == 1) && (p_dev->device_no == 0))
pcmcia_parse_uevents(s, PCMCIA_UEVENT_REQUERY);
mutex_unlock(&s->ops_mutex);
put_module:
if (ret)
module_put(p_drv->owner);
put_dev:
if (ret)
put_device(dev);
return ret;
}
static void pcmcia_card_remove(struct pcmcia_socket *s, struct pcmcia_device *leftover)
{
struct pcmcia_device *p_dev;
struct pcmcia_device *tmp;
dev_dbg(leftover ? &leftover->dev : &s->dev,
"pcmcia_card_remove(%d) %s\n", s->sock,
leftover ? leftover->devname : "");
mutex_lock(&s->ops_mutex);
if (!leftover)
s->device_count = 0;
else
s->device_count = 1;
mutex_unlock(&s->ops_mutex);
list_for_each_entry_safe(p_dev, tmp, &s->devices_list, socket_device_list) {
if (p_dev == leftover)
continue;
mutex_lock(&s->ops_mutex);
list_del(&p_dev->socket_device_list);
mutex_unlock(&s->ops_mutex);
dev_dbg(&p_dev->dev, "unregistering device\n");
device_unregister(&p_dev->dev);
}
return;
}
static int pcmcia_device_remove(struct device *dev)
{
struct pcmcia_device *p_dev;
struct pcmcia_driver *p_drv;
int i;
p_dev = to_pcmcia_dev(dev);
p_drv = to_pcmcia_drv(dev->driver);
dev_dbg(dev, "removing device\n");
if ((p_dev->socket->pcmcia_pfc) &&
(p_dev->socket->device_count > 0) &&
(p_dev->device_no == 0))
pcmcia_card_remove(p_dev->socket, p_dev);
if (!p_drv)
return 0;
if (p_drv->remove)
p_drv->remove(p_dev);
if (p_dev->_irq || p_dev->_io || p_dev->_locked)
dev_info(dev,
"pcmcia: driver %s did not release config properly\n",
p_drv->name);
for (i = 0; i < MAX_WIN; i++)
if (p_dev->_win & CLIENT_WIN_REQ(i))
dev_info(dev,
"pcmcia: driver %s did not release window properly\n",
p_drv->name);
pcmcia_put_dev(p_dev);
module_put(p_drv->owner);
return 0;
}
static int pcmcia_device_query(struct pcmcia_device *p_dev)
{
cistpl_manfid_t manf_id;
cistpl_funcid_t func_id;
cistpl_vers_1_t *vers1;
unsigned int i;
vers1 = kmalloc(sizeof(*vers1), GFP_KERNEL);
if (!vers1)
return -ENOMEM;
if (!pccard_read_tuple(p_dev->socket, BIND_FN_ALL,
CISTPL_MANFID, &manf_id)) {
mutex_lock(&p_dev->socket->ops_mutex);
p_dev->manf_id = manf_id.manf;
p_dev->card_id = manf_id.card;
p_dev->has_manf_id = 1;
p_dev->has_card_id = 1;
mutex_unlock(&p_dev->socket->ops_mutex);
}
if (!pccard_read_tuple(p_dev->socket, p_dev->func,
CISTPL_FUNCID, &func_id)) {
mutex_lock(&p_dev->socket->ops_mutex);
p_dev->func_id = func_id.func;
p_dev->has_func_id = 1;
mutex_unlock(&p_dev->socket->ops_mutex);
} else {
cistpl_device_geo_t *devgeo;
devgeo = kmalloc(sizeof(*devgeo), GFP_KERNEL);
if (!devgeo) {
kfree(vers1);
return -ENOMEM;
}
if (!pccard_read_tuple(p_dev->socket, p_dev->func,
CISTPL_DEVICE_GEO, devgeo)) {
dev_dbg(&p_dev->dev,
"mem device geometry probably means "
"FUNCID_MEMORY\n");
mutex_lock(&p_dev->socket->ops_mutex);
p_dev->func_id = CISTPL_FUNCID_MEMORY;
p_dev->has_func_id = 1;
mutex_unlock(&p_dev->socket->ops_mutex);
}
kfree(devgeo);
}
if (!pccard_read_tuple(p_dev->socket, BIND_FN_ALL, CISTPL_VERS_1,
vers1)) {
mutex_lock(&p_dev->socket->ops_mutex);
for (i = 0; i < min_t(unsigned int, 4, vers1->ns); i++) {
char *tmp;
unsigned int length;
char *new;
tmp = vers1->str + vers1->ofs[i];
length = strlen(tmp) + 1;
if ((length < 2) || (length > 255))
continue;
new = kstrdup(tmp, GFP_KERNEL);
if (!new)
continue;
tmp = p_dev->prod_id[i];
p_dev->prod_id[i] = new;
kfree(tmp);
}
mutex_unlock(&p_dev->socket->ops_mutex);
}
kfree(vers1);
return 0;
}
static struct pcmcia_device *pcmcia_device_add(struct pcmcia_socket *s,
unsigned int function)
{
struct pcmcia_device *p_dev, *tmp_dev;
int i;
s = pcmcia_get_socket(s);
if (!s)
return NULL;
pr_debug("adding device to %d, function %d\n", s->sock, function);
p_dev = kzalloc(sizeof(struct pcmcia_device), GFP_KERNEL);
if (!p_dev)
goto err_put;
mutex_lock(&s->ops_mutex);
p_dev->device_no = (s->device_count++);
mutex_unlock(&s->ops_mutex);
if ((p_dev->device_no >= 2) && (function == 0))
goto err_free;
if (p_dev->device_no >= 4)
goto err_free;
p_dev->socket = s;
p_dev->func = function;
p_dev->dev.bus = &pcmcia_bus_type;
p_dev->dev.parent = s->dev.parent;
p_dev->dev.release = pcmcia_release_dev;
p_dev->dma_mask = DMA_MASK_NONE;
p_dev->dev.dma_mask = &p_dev->dma_mask;
dev_set_name(&p_dev->dev, "%d.%d", p_dev->socket->sock, p_dev->device_no);
if (!dev_name(&p_dev->dev))
goto err_free;
p_dev->devname = kasprintf(GFP_KERNEL, "pcmcia%s", dev_name(&p_dev->dev));
if (!p_dev->devname)
goto err_free;
dev_dbg(&p_dev->dev, "devname is %s\n", p_dev->devname);
mutex_lock(&s->ops_mutex);
list_for_each_entry(tmp_dev, &s->devices_list, socket_device_list)
if (p_dev->func == tmp_dev->func) {
p_dev->function_config = tmp_dev->function_config;
p_dev->irq = tmp_dev->irq;
kref_get(&p_dev->function_config->ref);
}
list_add(&p_dev->socket_device_list, &s->devices_list);
if (pcmcia_setup_irq(p_dev))
dev_warn(&p_dev->dev,
"IRQ setup failed -- device might not work\n");
if (!p_dev->function_config) {
config_t *c;
dev_dbg(&p_dev->dev, "creating config_t\n");
c = kzalloc(sizeof(struct config_t), GFP_KERNEL);
if (!c) {
mutex_unlock(&s->ops_mutex);
goto err_unreg;
}
p_dev->function_config = c;
kref_init(&c->ref);
for (i = 0; i < MAX_IO_WIN; i++) {
c->io[i].name = p_dev->devname;
c->io[i].flags = IORESOURCE_IO;
}
for (i = 0; i < MAX_WIN; i++) {
c->mem[i].name = p_dev->devname;
c->mem[i].flags = IORESOURCE_MEM;
}
}
for (i = 0; i < MAX_IO_WIN; i++)
p_dev->resource[i] = &p_dev->function_config->io[i];
for (; i < (MAX_IO_WIN + MAX_WIN); i++)
p_dev->resource[i] = &p_dev->function_config->mem[i-MAX_IO_WIN];
mutex_unlock(&s->ops_mutex);
dev_notice(&p_dev->dev, "pcmcia: registering new device %s (IRQ: %d)\n",
p_dev->devname, p_dev->irq);
pcmcia_device_query(p_dev);
if (device_register(&p_dev->dev))
goto err_unreg;
return p_dev;
err_unreg:
mutex_lock(&s->ops_mutex);
list_del(&p_dev->socket_device_list);
mutex_unlock(&s->ops_mutex);
err_free:
mutex_lock(&s->ops_mutex);
s->device_count--;
mutex_unlock(&s->ops_mutex);
for (i = 0; i < 4; i++)
kfree(p_dev->prod_id[i]);
kfree(p_dev->devname);
kfree(p_dev);
err_put:
pcmcia_put_socket(s);
return NULL;
}
static int pcmcia_card_add(struct pcmcia_socket *s)
{
cistpl_longlink_mfc_t mfc;
unsigned int no_funcs, i, no_chains;
int ret = -EAGAIN;
mutex_lock(&s->ops_mutex);
if (!(s->resource_setup_done)) {
dev_dbg(&s->dev,
"no resources available, delaying card_add\n");
mutex_unlock(&s->ops_mutex);
return -EAGAIN;
}
if (pcmcia_validate_mem(s)) {
dev_dbg(&s->dev, "validating mem resources failed, "
"delaying card_add\n");
mutex_unlock(&s->ops_mutex);
return -EAGAIN;
}
mutex_unlock(&s->ops_mutex);
ret = pccard_validate_cis(s, &no_chains);
if (ret || !no_chains) {
#if defined(CONFIG_MTD_PCMCIA_ANONYMOUS)
if (ret == -EIO) {
dev_info(&s->dev, "no CIS, assuming an anonymous memory card.\n");
pcmcia_replace_cis(s, "\xFF", 1);
no_chains = 1;
ret = 0;
} else
#endif
{
dev_dbg(&s->dev, "invalid CIS or invalid resources\n");
return -ENODEV;
}
}
if (!pccard_read_tuple(s, BIND_FN_ALL, CISTPL_LONGLINK_MFC, &mfc))
no_funcs = mfc.nfn;
else
no_funcs = 1;
s->functions = no_funcs;
for (i = 0; i < no_funcs; i++)
pcmcia_device_add(s, i);
return ret;
}
static int pcmcia_requery_callback(struct device *dev, void *_data)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
if (!p_dev->dev.driver) {
dev_dbg(dev, "update device information\n");
pcmcia_device_query(p_dev);
}
return 0;
}
static void pcmcia_requery(struct pcmcia_socket *s)
{
int has_pfc;
if (!(s->state & SOCKET_PRESENT))
return;
if (s->functions == 0) {
pcmcia_card_add(s);
return;
}
bus_for_each_dev(&pcmcia_bus_type, NULL, NULL, pcmcia_requery_callback);
if (s->fake_cis) {
int old_funcs, new_funcs;
cistpl_longlink_mfc_t mfc;
old_funcs = s->functions;
if (!pccard_read_tuple(s, BIND_FN_ALL, CISTPL_LONGLINK_MFC,
&mfc))
new_funcs = mfc.nfn;
else
new_funcs = 1;
if (old_funcs != new_funcs) {
pcmcia_card_remove(s, NULL);
s->functions = 0;
pcmcia_card_add(s);
}
}
mutex_lock(&s->ops_mutex);
has_pfc = s->pcmcia_pfc;
mutex_unlock(&s->ops_mutex);
if (has_pfc)
pcmcia_device_add(s, 0);
if (bus_rescan_devices(&pcmcia_bus_type))
dev_warn(&s->dev, "rescanning the bus failed\n");
}
static int pcmcia_load_firmware(struct pcmcia_device *dev, char *filename)
{
struct pcmcia_socket *s = dev->socket;
const struct firmware *fw;
int ret = -ENOMEM;
cistpl_longlink_mfc_t mfc;
int old_funcs, new_funcs = 1;
if (!filename)
return -EINVAL;
dev_dbg(&dev->dev, "trying to load CIS file %s\n", filename);
if (request_firmware(&fw, filename, &dev->dev) == 0) {
if (fw->size >= CISTPL_MAX_CIS_SIZE) {
ret = -EINVAL;
dev_err(&dev->dev, "pcmcia: CIS override is too big\n");
goto release;
}
if (!pcmcia_replace_cis(s, fw->data, fw->size))
ret = 0;
else {
dev_err(&dev->dev, "pcmcia: CIS override failed\n");
goto release;
}
old_funcs = s->functions;
if (!pccard_read_tuple(s, BIND_FN_ALL, CISTPL_LONGLINK_MFC,
&mfc))
new_funcs = mfc.nfn;
if (old_funcs != new_funcs)
ret = -EBUSY;
pcmcia_device_query(dev);
pcmcia_parse_uevents(s, PCMCIA_UEVENT_REQUERY);
}
release:
release_firmware(fw);
return ret;
}
static inline int pcmcia_load_firmware(struct pcmcia_device *dev,
char *filename)
{
return -ENODEV;
}
static inline int pcmcia_devmatch(struct pcmcia_device *dev,
const struct pcmcia_device_id *did)
{
if (did->match_flags & PCMCIA_DEV_ID_MATCH_MANF_ID) {
if ((!dev->has_manf_id) || (dev->manf_id != did->manf_id))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_CARD_ID) {
if ((!dev->has_card_id) || (dev->card_id != did->card_id))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_FUNCTION) {
if (dev->func != did->function)
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_PROD_ID1) {
if (!dev->prod_id[0])
return 0;
if (strcmp(did->prod_id[0], dev->prod_id[0]))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_PROD_ID2) {
if (!dev->prod_id[1])
return 0;
if (strcmp(did->prod_id[1], dev->prod_id[1]))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_PROD_ID3) {
if (!dev->prod_id[2])
return 0;
if (strcmp(did->prod_id[2], dev->prod_id[2]))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_PROD_ID4) {
if (!dev->prod_id[3])
return 0;
if (strcmp(did->prod_id[3], dev->prod_id[3]))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_DEVICE_NO) {
dev_dbg(&dev->dev, "this is a pseudo-multi-function device\n");
mutex_lock(&dev->socket->ops_mutex);
dev->socket->pcmcia_pfc = 1;
mutex_unlock(&dev->socket->ops_mutex);
if (dev->device_no != did->device_no)
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_FUNC_ID) {
int ret;
if ((!dev->has_func_id) || (dev->func_id != did->func_id))
return 0;
if (dev->socket->pcmcia_pfc)
return 0;
if (dev->device_no)
return 0;
mutex_lock(&dev->socket->ops_mutex);
ret = dev->allow_func_id_match;
mutex_unlock(&dev->socket->ops_mutex);
if (!ret) {
dev_dbg(&dev->dev,
"skipping FUNC_ID match until userspace ACK\n");
return 0;
}
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_FAKE_CIS) {
dev_dbg(&dev->dev, "device needs a fake CIS\n");
if (!dev->socket->fake_cis)
if (pcmcia_load_firmware(dev, did->cisfile))
return 0;
}
if (did->match_flags & PCMCIA_DEV_ID_MATCH_ANONYMOUS) {
int i;
for (i = 0; i < 4; i++)
if (dev->prod_id[i])
return 0;
if (dev->has_manf_id || dev->has_card_id || dev->has_func_id)
return 0;
}
return 1;
}
static int pcmcia_bus_match(struct device *dev, struct device_driver *drv)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
struct pcmcia_driver *p_drv = to_pcmcia_drv(drv);
const struct pcmcia_device_id *did = p_drv->id_table;
struct pcmcia_dynid *dynid;
mutex_lock(&p_drv->dynids.lock);
list_for_each_entry(dynid, &p_drv->dynids.list, node) {
dev_dbg(dev, "trying to match to %s\n", drv->name);
if (pcmcia_devmatch(p_dev, &dynid->id)) {
dev_dbg(dev, "matched to %s\n", drv->name);
mutex_unlock(&p_drv->dynids.lock);
return 1;
}
}
mutex_unlock(&p_drv->dynids.lock);
while (did && did->match_flags) {
dev_dbg(dev, "trying to match to %s\n", drv->name);
if (pcmcia_devmatch(p_dev, did)) {
dev_dbg(dev, "matched to %s\n", drv->name);
return 1;
}
did++;
}
return 0;
}
static int pcmcia_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct pcmcia_device *p_dev;
int i;
u32 hash[4] = { 0, 0, 0, 0};
if (!dev)
return -ENODEV;
p_dev = to_pcmcia_dev(dev);
for (i = 0; i < 4; i++) {
if (!p_dev->prod_id[i])
continue;
hash[i] = crc32(0, p_dev->prod_id[i], strlen(p_dev->prod_id[i]));
}
if (add_uevent_var(env, "SOCKET_NO=%u", p_dev->socket->sock))
return -ENOMEM;
if (add_uevent_var(env, "DEVICE_NO=%02X", p_dev->device_no))
return -ENOMEM;
if (add_uevent_var(env, "MODALIAS=pcmcia:m%04Xc%04Xf%02Xfn%02Xpfn%02X"
"pa%08Xpb%08Xpc%08Xpd%08X",
p_dev->has_manf_id ? p_dev->manf_id : 0,
p_dev->has_card_id ? p_dev->card_id : 0,
p_dev->has_func_id ? p_dev->func_id : 0,
p_dev->func,
p_dev->device_no,
hash[0],
hash[1],
hash[2],
hash[3]))
return -ENOMEM;
return 0;
}
static int runtime_suspend(struct device *dev)
{
int rc;
device_lock(dev);
rc = pcmcia_dev_suspend(dev, PMSG_SUSPEND);
device_unlock(dev);
return rc;
}
static int runtime_resume(struct device *dev)
{
int rc;
device_lock(dev);
rc = pcmcia_dev_resume(dev);
device_unlock(dev);
return rc;
}
static ssize_t function_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
return p_dev->socket ? sprintf(buf, "0x%02x\n", p_dev->func) : -ENODEV;
}
static ssize_t resources_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
char *str = buf;
int i;
for (i = 0; i < PCMCIA_NUM_RESOURCES; i++)
str += sprintf(str, "%pr\n", p_dev->resource[i]);
return str - buf;
}
static ssize_t pm_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
if (p_dev->suspended)
return sprintf(buf, "off\n");
else
return sprintf(buf, "on\n");
}
static ssize_t pm_state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
int ret = 0;
if (!count)
return -EINVAL;
if ((!p_dev->suspended) && !strncmp(buf, "off", 3))
ret = runtime_suspend(dev);
else if (p_dev->suspended && !strncmp(buf, "on", 2))
ret = runtime_resume(dev);
return ret ? ret : count;
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
int i;
u32 hash[4] = { 0, 0, 0, 0};
for (i = 0; i < 4; i++) {
if (!p_dev->prod_id[i])
continue;
hash[i] = crc32(0, p_dev->prod_id[i],
strlen(p_dev->prod_id[i]));
}
return sprintf(buf, "pcmcia:m%04Xc%04Xf%02Xfn%02Xpfn%02X"
"pa%08Xpb%08Xpc%08Xpd%08X\n",
p_dev->has_manf_id ? p_dev->manf_id : 0,
p_dev->has_card_id ? p_dev->card_id : 0,
p_dev->has_func_id ? p_dev->func_id : 0,
p_dev->func, p_dev->device_no,
hash[0], hash[1], hash[2], hash[3]);
}
static ssize_t allow_func_id_match_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
if (!count)
return -EINVAL;
mutex_lock(&p_dev->socket->ops_mutex);
p_dev->allow_func_id_match = 1;
mutex_unlock(&p_dev->socket->ops_mutex);
pcmcia_parse_uevents(p_dev->socket, PCMCIA_UEVENT_REQUERY);
return count;
}
static int pcmcia_dev_suspend(struct device *dev, pm_message_t state)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
struct pcmcia_driver *p_drv = NULL;
int ret = 0;
mutex_lock(&p_dev->socket->ops_mutex);
if (p_dev->suspended) {
mutex_unlock(&p_dev->socket->ops_mutex);
return 0;
}
p_dev->suspended = 1;
mutex_unlock(&p_dev->socket->ops_mutex);
dev_dbg(dev, "suspending\n");
if (dev->driver)
p_drv = to_pcmcia_drv(dev->driver);
if (!p_drv)
goto out;
if (p_drv->suspend) {
ret = p_drv->suspend(p_dev);
if (ret) {
dev_err(dev,
"pcmcia: device %s (driver %s) did not want to go to sleep (%d)\n",
p_dev->devname, p_drv->name, ret);
mutex_lock(&p_dev->socket->ops_mutex);
p_dev->suspended = 0;
mutex_unlock(&p_dev->socket->ops_mutex);
goto out;
}
}
if (p_dev->device_no == p_dev->func) {
dev_dbg(dev, "releasing configuration\n");
pcmcia_release_configuration(p_dev);
}
out:
return ret;
}
static int pcmcia_dev_resume(struct device *dev)
{
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
struct pcmcia_driver *p_drv = NULL;
int ret = 0;
mutex_lock(&p_dev->socket->ops_mutex);
if (!p_dev->suspended) {
mutex_unlock(&p_dev->socket->ops_mutex);
return 0;
}
p_dev->suspended = 0;
mutex_unlock(&p_dev->socket->ops_mutex);
dev_dbg(dev, "resuming\n");
if (dev->driver)
p_drv = to_pcmcia_drv(dev->driver);
if (!p_drv)
goto out;
if (p_dev->device_no == p_dev->func) {
dev_dbg(dev, "requesting configuration\n");
ret = pcmcia_enable_device(p_dev);
if (ret)
goto out;
}
if (p_drv->resume)
ret = p_drv->resume(p_dev);
out:
return ret;
}
static int pcmcia_bus_suspend_callback(struct device *dev, void *_data)
{
struct pcmcia_socket *skt = _data;
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
if (p_dev->socket != skt || p_dev->suspended)
return 0;
return runtime_suspend(dev);
}
static int pcmcia_bus_resume_callback(struct device *dev, void *_data)
{
struct pcmcia_socket *skt = _data;
struct pcmcia_device *p_dev = to_pcmcia_dev(dev);
if (p_dev->socket != skt || !p_dev->suspended)
return 0;
runtime_resume(dev);
return 0;
}
static int pcmcia_bus_resume(struct pcmcia_socket *skt)
{
dev_dbg(&skt->dev, "resuming socket %d\n", skt->sock);
bus_for_each_dev(&pcmcia_bus_type, NULL, skt, pcmcia_bus_resume_callback);
return 0;
}
static int pcmcia_bus_suspend(struct pcmcia_socket *skt)
{
dev_dbg(&skt->dev, "suspending socket %d\n", skt->sock);
if (bus_for_each_dev(&pcmcia_bus_type, NULL, skt,
pcmcia_bus_suspend_callback)) {
pcmcia_bus_resume(skt);
return -EIO;
}
return 0;
}
static int pcmcia_bus_remove(struct pcmcia_socket *skt)
{
atomic_set(&skt->present, 0);
pcmcia_card_remove(skt, NULL);
mutex_lock(&skt->ops_mutex);
destroy_cis_cache(skt);
pcmcia_cleanup_irq(skt);
mutex_unlock(&skt->ops_mutex);
return 0;
}
static int pcmcia_bus_add(struct pcmcia_socket *skt)
{
atomic_set(&skt->present, 1);
mutex_lock(&skt->ops_mutex);
skt->pcmcia_pfc = 0;
destroy_cis_cache(skt);
mutex_unlock(&skt->ops_mutex);
pcmcia_card_add(skt);
return 0;
}
static int pcmcia_bus_early_resume(struct pcmcia_socket *skt)
{
if (!verify_cis_cache(skt))
return 0;
dev_dbg(&skt->dev, "cis mismatch - different card\n");
pcmcia_bus_remove(skt);
mutex_lock(&skt->ops_mutex);
destroy_cis_cache(skt);
kfree(skt->fake_cis);
skt->fake_cis = NULL;
skt->functions = 0;
mutex_unlock(&skt->ops_mutex);
pcmcia_bus_add(skt);
return 0;
}
struct pcmcia_device *pcmcia_dev_present(struct pcmcia_device *_p_dev)
{
struct pcmcia_device *p_dev;
struct pcmcia_device *ret = NULL;
p_dev = pcmcia_get_dev(_p_dev);
if (!p_dev)
return NULL;
if (atomic_read(&p_dev->socket->present) != 0)
ret = p_dev;
pcmcia_put_dev(p_dev);
return ret;
}
static int pcmcia_bus_add_socket(struct device *dev,
struct class_interface *class_intf)
{
struct pcmcia_socket *socket = dev_get_drvdata(dev);
int ret;
socket = pcmcia_get_socket(socket);
if (!socket) {
dev_err(dev, "PCMCIA obtaining reference to socket failed\n");
return -ENODEV;
}
ret = sysfs_create_bin_file(&dev->kobj, &pccard_cis_attr);
if (ret) {
dev_err(dev, "PCMCIA registration failed\n");
pcmcia_put_socket(socket);
return ret;
}
INIT_LIST_HEAD(&socket->devices_list);
socket->pcmcia_pfc = 0;
socket->device_count = 0;
atomic_set(&socket->present, 0);
ret = pccard_register_pcmcia(socket, &pcmcia_bus_callback);
if (ret) {
dev_err(dev, "PCMCIA registration failed\n");
pcmcia_put_socket(socket);
return ret;
}
return 0;
}
static void pcmcia_bus_remove_socket(struct device *dev,
struct class_interface *class_intf)
{
struct pcmcia_socket *socket = dev_get_drvdata(dev);
if (!socket)
return;
pccard_register_pcmcia(socket, NULL);
mutex_lock(&socket->skt_mutex);
pcmcia_card_remove(socket, NULL);
release_cis_mem(socket);
mutex_unlock(&socket->skt_mutex);
sysfs_remove_bin_file(&dev->kobj, &pccard_cis_attr);
pcmcia_put_socket(socket);
return;
}
static int __init init_pcmcia_bus(void)
{
int ret;
ret = bus_register(&pcmcia_bus_type);
if (ret < 0) {
printk(KERN_WARNING "pcmcia: bus_register error: %d\n", ret);
return ret;
}
ret = class_interface_register(&pcmcia_bus_interface);
if (ret < 0) {
printk(KERN_WARNING
"pcmcia: class_interface_register error: %d\n", ret);
bus_unregister(&pcmcia_bus_type);
return ret;
}
return 0;
}
static void __exit exit_pcmcia_bus(void)
{
class_interface_unregister(&pcmcia_bus_interface);
bus_unregister(&pcmcia_bus_type);
}
