static struct rar_device *alloc_rar_device(void)
{
if (my_rar_device.allocated)
return NULL;
my_rar_device.allocated = 1;
return &my_rar_device;
}
static void free_rar_device(struct rar_device *rar)
{
pci_dev_put(rar->rar_dev);
rar->allocated = 0;
}
static struct rar_device *_rar_to_device(int rar, int *off)
{
if (rar >= 0 && rar < MRST_NUM_RAR) {
*off = rar;
return &my_rar_device;
}
return NULL;
}
static struct rar_device *rar_to_device(int rar, int *off)
{
struct rar_device *rar_dev = _rar_to_device(rar, off);
if (rar_dev == NULL || !rar_dev->registered)
return NULL;
return rar_dev;
}
static struct client *rar_to_client(int rar)
{
int idx;
struct rar_device *r = _rar_to_device(rar, &idx);
if (r != NULL)
return &r->client[idx];
return NULL;
}
static int rar_read_addr(struct pci_dev *pdev, int offset, dma_addr_t *addr)
{
int result;
u32 addr32;
u32 const message =
(LNC_MESSAGE_READ_OPCODE << 24)
| (LNC_BUNIT_PORT << 16)
| (offset << 8)
| (LNC_MESSAGE_BYTE_WRITE_ENABLES << 4);
dev_dbg(&pdev->dev, "Offset for 'get' LNC MSG is %x\n", offset);
mutex_lock(&lnc_reg_mutex);
result = pci_write_config_dword(pdev, LNC_MCR_OFFSET, message);
if (!result) {
result = pci_read_config_dword(pdev, LNC_MDR_OFFSET, &addr32);
*addr = (dma_addr_t)addr32;
}
mutex_unlock(&lnc_reg_mutex);
return result;
}
static int rar_set_addr(struct pci_dev *pdev,
int offset,
dma_addr_t addr)
{
int result;
u32 const message = (LNC_MESSAGE_WRITE_OPCODE << 24)
| (LNC_BUNIT_PORT << 16)
| (offset << 8)
| (LNC_MESSAGE_BYTE_WRITE_ENABLES << 4);
mutex_lock(&lnc_reg_mutex);
result = pci_write_config_dword(pdev, LNC_MDR_OFFSET, addr);
if (!result)
result = pci_write_config_dword(pdev, LNC_MCR_OFFSET, message);
mutex_unlock(&lnc_reg_mutex);
return result;
}
static int init_rar_params(struct rar_device *rar)
{
struct pci_dev *pdev = rar->rar_dev;
unsigned int i;
int result = 0;
int offset = 0x10;
for (i = 0; i < MRST_NUM_RAR; ++i) {
struct rar_addr *addr = &rar->rar_addr[i];
result = rar_read_addr(pdev, offset++, &addr->low);
if (result != 0)
return result;
result = rar_read_addr(pdev, offset++, &addr->high);
if (result != 0)
return result;
addr->low &= (dma_addr_t)0xfffffc00u;
if ((addr->high & 0xfffffc00u) == 0)
addr->high = 0;
else
addr->high |= 0x3ffu;
}
if (result == 0) {
for (i = 0; i != MRST_NUM_RAR; ++i) {
dev_info(&pdev->dev, "BRAR[%u] bus address range = "
"[%lx, %lx]\n", i,
(unsigned long)rar->rar_addr[i].low,
(unsigned long)rar->rar_addr[i].high);
}
}
return result;
}
int rar_get_address(int rar_index, dma_addr_t *start, dma_addr_t *end)
{
int idx;
struct rar_device *rar = rar_to_device(rar_index, &idx);
if (rar == NULL) {
WARN_ON(1);
return -ENODEV;
}
*start = rar->rar_addr[idx].low;
*end = rar->rar_addr[idx].high;
return 0;
}
int rar_lock(int rar_index)
{
struct rar_device *rar;
int result;
int idx;
dma_addr_t low, high;
rar = rar_to_device(rar_index, &idx);
if (rar == NULL) {
WARN_ON(1);
return -EINVAL;
}
low = rar->rar_addr[idx].low & 0xfffffc00u;
high = rar->rar_addr[idx].high & 0xfffffc00u;
if (rar_index == RAR_TYPE_VIDEO) {
low |= 0x00000009;
high |= 0x00000015;
} else if (rar_index == RAR_TYPE_AUDIO) {
low |= 0x00000008;
high |= 0x00000018;
} else
high |= 0x00000018;
result = rar_set_addr(rar->rar_dev,
2 * idx, low);
if (result == 0)
result = rar_set_addr(rar->rar_dev,
2 * idx + 1, high);
return result;
}
int register_rar(int num, int (*callback)(unsigned long data),
unsigned long data)
{
struct rar_device *rar;
struct client *c;
int idx;
int retval = 0;
mutex_lock(&rar_mutex);
c = rar_to_client(num);
if (c == NULL) {
retval = -ERANGE;
goto done;
}
if (c->busy) {
retval = -EBUSY;
goto done;
}
c->busy = 1;
rar = rar_to_device(num, &idx);
if (rar) {
(*callback)(data);
goto done;
}
c->callback = callback;
c->driver_priv = data;
done:
mutex_unlock(&rar_mutex);
return retval;
}
void unregister_rar(int num)
{
struct client *c;
mutex_lock(&rar_mutex);
c = rar_to_client(num);
if (c == NULL || !c->busy)
WARN_ON(1);
else
c->busy = 0;
mutex_unlock(&rar_mutex);
}
static void rar_callback(struct rar_device *rar)
{
struct client *c = &rar->client[0];
int i;
mutex_lock(&rar_mutex);
rar->registered = 1;
for (i = 0; i < MRST_NUM_RAR; i++) {
if (c->callback && c->busy) {
c->callback(c->driver_priv);
c->callback = NULL;
}
c++;
}
mutex_unlock(&rar_mutex);
}
static int rar_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int error;
struct rar_device *rar;
dev_dbg(&dev->dev, "PCI probe starting\n");
rar = alloc_rar_device();
if (rar == NULL)
return -EBUSY;
error = pci_enable_device(dev);
if (error) {
dev_err(&dev->dev,
"Error enabling RAR register PCI device\n");
goto end_function;
}
rar->rar_dev = pci_dev_get(dev);
pci_set_drvdata(dev, rar);
error = init_rar_params(rar);
if (error) {
pci_disable_device(dev);
dev_err(&dev->dev, "Error retrieving RAR addresses\n");
goto end_function;
}
rar_callback(rar);
return 0;
end_function:
free_rar_device(rar);
return error;
}
static int __init rar_init_handler(void)
{
return pci_register_driver(&rar_pci_driver);
}
static void __exit rar_exit_handler(void)
{
pci_unregister_driver(&rar_pci_driver);
}
