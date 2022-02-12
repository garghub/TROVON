static void rmi_free_function_list(struct rmi_device *rmi_dev)
{
struct rmi_function *fn, *tmp;
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
data->f01_container = NULL;
list_for_each_entry_safe_reverse(fn, tmp,
&data->function_list, node) {
list_del(&fn->node);
rmi_unregister_function(fn);
}
}
static int reset_one_function(struct rmi_function *fn)
{
struct rmi_function_handler *fh;
int retval = 0;
if (!fn || !fn->dev.driver)
return 0;
fh = to_rmi_function_handler(fn->dev.driver);
if (fh->reset) {
retval = fh->reset(fn);
if (retval < 0)
dev_err(&fn->dev, "Reset failed with code %d.\n",
retval);
}
return retval;
}
static int configure_one_function(struct rmi_function *fn)
{
struct rmi_function_handler *fh;
int retval = 0;
if (!fn || !fn->dev.driver)
return 0;
fh = to_rmi_function_handler(fn->dev.driver);
if (fh->config) {
retval = fh->config(fn);
if (retval < 0)
dev_err(&fn->dev, "Config failed with code %d.\n",
retval);
}
return retval;
}
static int rmi_driver_process_reset_requests(struct rmi_device *rmi_dev)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct rmi_function *entry;
int retval;
list_for_each_entry(entry, &data->function_list, node) {
retval = reset_one_function(entry);
if (retval < 0)
return retval;
}
return 0;
}
static int rmi_driver_process_config_requests(struct rmi_device *rmi_dev)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct rmi_function *entry;
int retval;
list_for_each_entry(entry, &data->function_list, node) {
retval = configure_one_function(entry);
if (retval < 0)
return retval;
}
return 0;
}
static void process_one_interrupt(struct rmi_driver_data *data,
struct rmi_function *fn)
{
struct rmi_function_handler *fh;
if (!fn || !fn->dev.driver)
return;
fh = to_rmi_function_handler(fn->dev.driver);
if (fh->attention) {
bitmap_and(data->fn_irq_bits, data->irq_status, fn->irq_mask,
data->irq_count);
if (!bitmap_empty(data->fn_irq_bits, data->irq_count))
fh->attention(fn, data->fn_irq_bits);
}
}
int rmi_process_interrupt_requests(struct rmi_device *rmi_dev)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct device *dev = &rmi_dev->dev;
struct rmi_function *entry;
int error;
if (!data)
return 0;
if (!rmi_dev->xport->attn_data) {
error = rmi_read_block(rmi_dev,
data->f01_container->fd.data_base_addr + 1,
data->irq_status, data->num_of_irq_regs);
if (error < 0) {
dev_err(dev, "Failed to read irqs, code=%d\n", error);
return error;
}
}
mutex_lock(&data->irq_mutex);
bitmap_and(data->irq_status, data->irq_status, data->current_irq_mask,
data->irq_count);
mutex_unlock(&data->irq_mutex);
list_for_each_entry(entry, &data->function_list, node)
process_one_interrupt(data, entry);
if (data->input)
input_sync(data->input);
return 0;
}
static int suspend_one_function(struct rmi_function *fn)
{
struct rmi_function_handler *fh;
int retval = 0;
if (!fn || !fn->dev.driver)
return 0;
fh = to_rmi_function_handler(fn->dev.driver);
if (fh->suspend) {
retval = fh->suspend(fn);
if (retval < 0)
dev_err(&fn->dev, "Suspend failed with code %d.\n",
retval);
}
return retval;
}
static int rmi_suspend_functions(struct rmi_device *rmi_dev)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct rmi_function *entry;
int retval;
list_for_each_entry(entry, &data->function_list, node) {
retval = suspend_one_function(entry);
if (retval < 0)
return retval;
}
return 0;
}
static int resume_one_function(struct rmi_function *fn)
{
struct rmi_function_handler *fh;
int retval = 0;
if (!fn || !fn->dev.driver)
return 0;
fh = to_rmi_function_handler(fn->dev.driver);
if (fh->resume) {
retval = fh->resume(fn);
if (retval < 0)
dev_err(&fn->dev, "Resume failed with code %d.\n",
retval);
}
return retval;
}
static int rmi_resume_functions(struct rmi_device *rmi_dev)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct rmi_function *entry;
int retval;
list_for_each_entry(entry, &data->function_list, node) {
retval = resume_one_function(entry);
if (retval < 0)
return retval;
}
return 0;
}
static int enable_sensor(struct rmi_device *rmi_dev)
{
int retval = 0;
retval = rmi_driver_process_config_requests(rmi_dev);
if (retval < 0)
return retval;
return rmi_process_interrupt_requests(rmi_dev);
}
static int rmi_driver_set_input_params(struct rmi_device *rmi_dev,
struct input_dev *input)
{
input->name = SYNAPTICS_INPUT_DEVICE_NAME;
input->id.vendor = SYNAPTICS_VENDOR_ID;
input->id.bustype = BUS_RMI;
return 0;
}
static void rmi_driver_set_input_name(struct rmi_device *rmi_dev,
struct input_dev *input)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
char *device_name = rmi_f01_get_product_ID(data->f01_container);
char *name;
name = devm_kasprintf(&rmi_dev->dev, GFP_KERNEL,
"Synaptics %s", device_name);
if (!name)
return;
input->name = name;
}
static int rmi_driver_set_irq_bits(struct rmi_device *rmi_dev,
unsigned long *mask)
{
int error = 0;
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct device *dev = &rmi_dev->dev;
mutex_lock(&data->irq_mutex);
bitmap_or(data->new_irq_mask,
data->current_irq_mask, mask, data->irq_count);
error = rmi_write_block(rmi_dev,
data->f01_container->fd.control_base_addr + 1,
data->new_irq_mask, data->num_of_irq_regs);
if (error < 0) {
dev_err(dev, "%s: Failed to change enabled interrupts!",
__func__);
goto error_unlock;
}
bitmap_copy(data->current_irq_mask, data->new_irq_mask,
data->num_of_irq_regs);
error_unlock:
mutex_unlock(&data->irq_mutex);
return error;
}
static int rmi_driver_clear_irq_bits(struct rmi_device *rmi_dev,
unsigned long *mask)
{
int error = 0;
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct device *dev = &rmi_dev->dev;
mutex_lock(&data->irq_mutex);
bitmap_andnot(data->new_irq_mask,
data->current_irq_mask, mask, data->irq_count);
error = rmi_write_block(rmi_dev,
data->f01_container->fd.control_base_addr + 1,
data->new_irq_mask, data->num_of_irq_regs);
if (error < 0) {
dev_err(dev, "%s: Failed to change enabled interrupts!",
__func__);
goto error_unlock;
}
bitmap_copy(data->current_irq_mask, data->new_irq_mask,
data->num_of_irq_regs);
error_unlock:
mutex_unlock(&data->irq_mutex);
return error;
}
static int rmi_driver_reset_handler(struct rmi_device *rmi_dev)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
int error;
if (!data || !data->f01_container) {
dev_warn(&rmi_dev->dev,
"Not ready to handle reset yet!\n");
return 0;
}
error = rmi_read_block(rmi_dev,
data->f01_container->fd.control_base_addr + 1,
data->current_irq_mask, data->num_of_irq_regs);
if (error < 0) {
dev_err(&rmi_dev->dev, "%s: Failed to read current IRQ mask.\n",
__func__);
return error;
}
error = rmi_driver_process_reset_requests(rmi_dev);
if (error < 0)
return error;
error = rmi_driver_process_config_requests(rmi_dev);
if (error < 0)
return error;
return 0;
}
int rmi_read_pdt_entry(struct rmi_device *rmi_dev, struct pdt_entry *entry,
u16 pdt_address)
{
u8 buf[RMI_PDT_ENTRY_SIZE];
int error;
error = rmi_read_block(rmi_dev, pdt_address, buf, RMI_PDT_ENTRY_SIZE);
if (error) {
dev_err(&rmi_dev->dev, "Read PDT entry at %#06x failed, code: %d.\n",
pdt_address, error);
return error;
}
entry->page_start = pdt_address & RMI4_PAGE_MASK;
entry->query_base_addr = buf[0];
entry->command_base_addr = buf[1];
entry->control_base_addr = buf[2];
entry->data_base_addr = buf[3];
entry->interrupt_source_count = buf[4] & RMI_PDT_INT_SOURCE_COUNT_MASK;
entry->function_version = (buf[4] & RMI_PDT_FUNCTION_VERSION_MASK) >> 5;
entry->function_number = buf[5];
return 0;
}
static void rmi_driver_copy_pdt_to_fd(const struct pdt_entry *pdt,
struct rmi_function_descriptor *fd)
{
fd->query_base_addr = pdt->query_base_addr + pdt->page_start;
fd->command_base_addr = pdt->command_base_addr + pdt->page_start;
fd->control_base_addr = pdt->control_base_addr + pdt->page_start;
fd->data_base_addr = pdt->data_base_addr + pdt->page_start;
fd->function_number = pdt->function_number;
fd->interrupt_source_count = pdt->interrupt_source_count;
fd->function_version = pdt->function_version;
}
static int rmi_scan_pdt_page(struct rmi_device *rmi_dev,
int page,
void *ctx,
int (*callback)(struct rmi_device *rmi_dev,
void *ctx,
const struct pdt_entry *entry))
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
struct pdt_entry pdt_entry;
u16 page_start = RMI4_PAGE_SIZE * page;
u16 pdt_start = page_start + PDT_START_SCAN_LOCATION;
u16 pdt_end = page_start + PDT_END_SCAN_LOCATION;
u16 addr;
int error;
int retval;
for (addr = pdt_start; addr >= pdt_end; addr -= RMI_PDT_ENTRY_SIZE) {
error = rmi_read_pdt_entry(rmi_dev, &pdt_entry, addr);
if (error)
return error;
if (RMI4_END_OF_PDT(pdt_entry.function_number))
break;
retval = callback(rmi_dev, ctx, &pdt_entry);
if (retval != RMI_SCAN_CONTINUE)
return retval;
}
return (data->f01_bootloader_mode || addr == pdt_start) ?
RMI_SCAN_DONE : RMI_SCAN_CONTINUE;
}
static int rmi_scan_pdt(struct rmi_device *rmi_dev, void *ctx,
int (*callback)(struct rmi_device *rmi_dev,
void *ctx,
const struct pdt_entry *entry))
{
int page;
int retval = RMI_SCAN_DONE;
for (page = 0; page <= RMI4_MAX_PAGE; page++) {
retval = rmi_scan_pdt_page(rmi_dev, page, ctx, callback);
if (retval != RMI_SCAN_CONTINUE)
break;
}
return retval < 0 ? retval : 0;
}
int rmi_read_register_desc(struct rmi_device *d, u16 addr,
struct rmi_register_descriptor *rdesc)
{
int ret;
u8 size_presence_reg;
u8 buf[35];
int presense_offset = 1;
u8 *struct_buf;
int reg;
int offset = 0;
int map_offset = 0;
int i;
int b;
ret = rmi_read(d, addr, &size_presence_reg);
if (ret)
return ret;
++addr;
if (size_presence_reg < 0 || size_presence_reg > 35)
return -EIO;
memset(buf, 0, sizeof(buf));
ret = rmi_read_block(d, addr, buf, size_presence_reg);
if (ret)
return ret;
++addr;
if (buf[0] == 0) {
presense_offset = 3;
rdesc->struct_size = buf[1] | (buf[2] << 8);
} else {
rdesc->struct_size = buf[0];
}
for (i = presense_offset; i < size_presence_reg; i++) {
for (b = 0; b < 8; b++) {
if (buf[i] & (0x1 << b))
bitmap_set(rdesc->presense_map, map_offset, 1);
++map_offset;
}
}
rdesc->num_registers = bitmap_weight(rdesc->presense_map,
RMI_REG_DESC_PRESENSE_BITS);
rdesc->registers = devm_kzalloc(&d->dev, rdesc->num_registers *
sizeof(struct rmi_register_desc_item),
GFP_KERNEL);
if (!rdesc->registers)
return -ENOMEM;
struct_buf = kzalloc(rdesc->struct_size, GFP_KERNEL);
if (!struct_buf)
return -ENOMEM;
ret = rmi_read_block(d, addr, struct_buf, rdesc->struct_size);
if (ret)
goto free_struct_buff;
reg = find_first_bit(rdesc->presense_map, RMI_REG_DESC_PRESENSE_BITS);
map_offset = 0;
for (i = 0; i < rdesc->num_registers; i++) {
struct rmi_register_desc_item *item = &rdesc->registers[i];
int reg_size = struct_buf[offset];
++offset;
if (reg_size == 0) {
reg_size = struct_buf[offset] |
(struct_buf[offset + 1] << 8);
offset += 2;
}
if (reg_size == 0) {
reg_size = struct_buf[offset] |
(struct_buf[offset + 1] << 8) |
(struct_buf[offset + 2] << 16) |
(struct_buf[offset + 3] << 24);
offset += 4;
}
item->reg = reg;
item->reg_size = reg_size;
do {
for (b = 0; b < 7; b++) {
if (struct_buf[offset] & (0x1 << b))
bitmap_set(item->subpacket_map,
map_offset, 1);
++map_offset;
}
} while (struct_buf[offset++] & 0x80);
item->num_subpackets = bitmap_weight(item->subpacket_map,
RMI_REG_DESC_SUBPACKET_BITS);
rmi_dbg(RMI_DEBUG_CORE, &d->dev,
"%s: reg: %d reg size: %ld subpackets: %d\n", __func__,
item->reg, item->reg_size, item->num_subpackets);
reg = find_next_bit(rdesc->presense_map,
RMI_REG_DESC_PRESENSE_BITS, reg + 1);
}
free_struct_buff:
kfree(struct_buf);
return ret;
}
const struct rmi_register_desc_item *rmi_get_register_desc_item(
struct rmi_register_descriptor *rdesc, u16 reg)
{
const struct rmi_register_desc_item *item;
int i;
for (i = 0; i < rdesc->num_registers; i++) {
item = &rdesc->registers[i];
if (item->reg == reg)
return item;
}
return NULL;
}
size_t rmi_register_desc_calc_size(struct rmi_register_descriptor *rdesc)
{
const struct rmi_register_desc_item *item;
int i;
size_t size = 0;
for (i = 0; i < rdesc->num_registers; i++) {
item = &rdesc->registers[i];
size += item->reg_size;
}
return size;
}
int rmi_register_desc_calc_reg_offset(
struct rmi_register_descriptor *rdesc, u16 reg)
{
const struct rmi_register_desc_item *item;
int offset = 0;
int i;
for (i = 0; i < rdesc->num_registers; i++) {
item = &rdesc->registers[i];
if (item->reg == reg)
return offset;
++offset;
}
return -1;
}
bool rmi_register_desc_has_subpacket(const struct rmi_register_desc_item *item,
u8 subpacket)
{
return find_next_bit(item->subpacket_map, RMI_REG_DESC_PRESENSE_BITS,
subpacket) == subpacket;
}
static int rmi_check_bootloader_mode(struct rmi_device *rmi_dev,
const struct pdt_entry *pdt)
{
int error;
u8 device_status;
error = rmi_read(rmi_dev, pdt->data_base_addr + pdt->page_start,
&device_status);
if (error) {
dev_err(&rmi_dev->dev,
"Failed to read device status: %d.\n", error);
return error;
}
return RMI_F01_STATUS_BOOTLOADER(device_status);
}
static int rmi_count_irqs(struct rmi_device *rmi_dev,
void *ctx, const struct pdt_entry *pdt)
{
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
int *irq_count = ctx;
*irq_count += pdt->interrupt_source_count;
if (pdt->function_number == 0x01) {
data->f01_bootloader_mode =
rmi_check_bootloader_mode(rmi_dev, pdt);
if (data->f01_bootloader_mode)
dev_warn(&rmi_dev->dev,
"WARNING: RMI4 device is in bootloader mode!\n");
}
return RMI_SCAN_CONTINUE;
}
static int rmi_initial_reset(struct rmi_device *rmi_dev,
void *ctx, const struct pdt_entry *pdt)
{
int error;
if (pdt->function_number == 0x01) {
u16 cmd_addr = pdt->page_start + pdt->command_base_addr;
u8 cmd_buf = RMI_DEVICE_RESET_CMD;
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(rmi_dev);
if (rmi_dev->xport->ops->reset) {
error = rmi_dev->xport->ops->reset(rmi_dev->xport,
cmd_addr);
if (error)
return error;
return RMI_SCAN_DONE;
}
error = rmi_write_block(rmi_dev, cmd_addr, &cmd_buf, 1);
if (error) {
dev_err(&rmi_dev->dev,
"Initial reset failed. Code = %d.\n", error);
return error;
}
mdelay(pdata->reset_delay_ms ?: DEFAULT_RESET_DELAY_MS);
return RMI_SCAN_DONE;
}
return pdt->page_start == 0 ? RMI_SCAN_CONTINUE : -ENODEV;
}
static int rmi_create_function(struct rmi_device *rmi_dev,
void *ctx, const struct pdt_entry *pdt)
{
struct device *dev = &rmi_dev->dev;
struct rmi_driver_data *data = dev_get_drvdata(&rmi_dev->dev);
int *current_irq_count = ctx;
struct rmi_function *fn;
int i;
int error;
rmi_dbg(RMI_DEBUG_CORE, dev, "Initializing F%02X.\n",
pdt->function_number);
fn = kzalloc(sizeof(struct rmi_function) +
BITS_TO_LONGS(data->irq_count) * sizeof(unsigned long),
GFP_KERNEL);
if (!fn) {
dev_err(dev, "Failed to allocate memory for F%02X\n",
pdt->function_number);
return -ENOMEM;
}
INIT_LIST_HEAD(&fn->node);
rmi_driver_copy_pdt_to_fd(pdt, &fn->fd);
fn->rmi_dev = rmi_dev;
fn->num_of_irqs = pdt->interrupt_source_count;
fn->irq_pos = *current_irq_count;
*current_irq_count += fn->num_of_irqs;
for (i = 0; i < fn->num_of_irqs; i++)
set_bit(fn->irq_pos + i, fn->irq_mask);
error = rmi_register_function(fn);
if (error)
goto err_put_fn;
if (pdt->function_number == 0x01)
data->f01_container = fn;
list_add_tail(&fn->node, &data->function_list);
return RMI_SCAN_CONTINUE;
err_put_fn:
put_device(&fn->dev);
return error;
}
int rmi_driver_suspend(struct rmi_device *rmi_dev)
{
int retval = 0;
retval = rmi_suspend_functions(rmi_dev);
if (retval)
dev_warn(&rmi_dev->dev, "Failed to suspend functions: %d\n",
retval);
return retval;
}
int rmi_driver_resume(struct rmi_device *rmi_dev)
{
int retval;
retval = rmi_resume_functions(rmi_dev);
if (retval)
dev_warn(&rmi_dev->dev, "Failed to suspend functions: %d\n",
retval);
return retval;
}
static int rmi_driver_remove(struct device *dev)
{
struct rmi_device *rmi_dev = to_rmi_device(dev);
rmi_free_function_list(rmi_dev);
return 0;
}
static int rmi_driver_of_probe(struct device *dev,
struct rmi_device_platform_data *pdata)
{
int retval;
retval = rmi_of_property_read_u32(dev, &pdata->reset_delay_ms,
"syna,reset-delay-ms", 1);
if (retval)
return retval;
return 0;
}
static inline int rmi_driver_of_probe(struct device *dev,
struct rmi_device_platform_data *pdata)
{
return -ENODEV;
}
static int rmi_driver_probe(struct device *dev)
{
struct rmi_driver *rmi_driver;
struct rmi_driver_data *data;
struct rmi_device_platform_data *pdata;
struct rmi_device *rmi_dev;
size_t size;
void *irq_memory;
int irq_count;
int retval;
rmi_dbg(RMI_DEBUG_CORE, dev, "%s: Starting probe.\n",
__func__);
if (!rmi_is_physical_device(dev)) {
rmi_dbg(RMI_DEBUG_CORE, dev, "Not a physical device.\n");
return -ENODEV;
}
rmi_dev = to_rmi_device(dev);
rmi_driver = to_rmi_driver(dev->driver);
rmi_dev->driver = rmi_driver;
pdata = rmi_get_platform_data(rmi_dev);
if (rmi_dev->xport->dev->of_node) {
retval = rmi_driver_of_probe(rmi_dev->xport->dev, pdata);
if (retval)
return retval;
}
data = devm_kzalloc(dev, sizeof(struct rmi_driver_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
INIT_LIST_HEAD(&data->function_list);
data->rmi_dev = rmi_dev;
dev_set_drvdata(&rmi_dev->dev, data);
retval = rmi_scan_pdt(rmi_dev, NULL, rmi_initial_reset);
if (retval < 0)
dev_warn(dev, "RMI initial reset failed! Continuing in spite of this.\n");
retval = rmi_read(rmi_dev, PDT_PROPERTIES_LOCATION, &data->pdt_props);
if (retval < 0) {
dev_warn(dev, "Could not read PDT properties from %#06x (code %d). Assuming 0x00.\n",
PDT_PROPERTIES_LOCATION, retval);
}
rmi_dbg(RMI_DEBUG_CORE, dev, "Counting IRQs.\n");
irq_count = 0;
retval = rmi_scan_pdt(rmi_dev, &irq_count, rmi_count_irqs);
if (retval < 0) {
dev_err(dev, "IRQ counting failed with code %d.\n", retval);
goto err;
}
data->irq_count = irq_count;
data->num_of_irq_regs = (data->irq_count + 7) / 8;
mutex_init(&data->irq_mutex);
size = BITS_TO_LONGS(data->irq_count) * sizeof(unsigned long);
irq_memory = devm_kzalloc(dev, size * 4, GFP_KERNEL);
if (!irq_memory) {
dev_err(dev, "Failed to allocate memory for irq masks.\n");
goto err;
}
data->irq_status = irq_memory + size * 0;
data->fn_irq_bits = irq_memory + size * 1;
data->current_irq_mask = irq_memory + size * 2;
data->new_irq_mask = irq_memory + size * 3;
if (rmi_dev->xport->input) {
data->input = rmi_dev->xport->input;
} else {
data->input = devm_input_allocate_device(dev);
if (!data->input) {
dev_err(dev, "%s: Failed to allocate input device.\n",
__func__);
retval = -ENOMEM;
goto err_destroy_functions;
}
rmi_driver_set_input_params(rmi_dev, data->input);
data->input->phys = devm_kasprintf(dev, GFP_KERNEL,
"%s/input0", dev_name(dev));
}
irq_count = 0;
rmi_dbg(RMI_DEBUG_CORE, dev, "Creating functions.");
retval = rmi_scan_pdt(rmi_dev, &irq_count, rmi_create_function);
if (retval < 0) {
dev_err(dev, "Function creation failed with code %d.\n",
retval);
goto err_destroy_functions;
}
if (!data->f01_container) {
dev_err(dev, "Missing F01 container!\n");
retval = -EINVAL;
goto err_destroy_functions;
}
retval = rmi_read_block(rmi_dev,
data->f01_container->fd.control_base_addr + 1,
data->current_irq_mask, data->num_of_irq_regs);
if (retval < 0) {
dev_err(dev, "%s: Failed to read current IRQ mask.\n",
__func__);
goto err_destroy_functions;
}
if (data->input) {
rmi_driver_set_input_name(rmi_dev, data->input);
if (!rmi_dev->xport->input) {
if (input_register_device(data->input)) {
dev_err(dev, "%s: Failed to register input device.\n",
__func__);
goto err_destroy_functions;
}
}
}
if (data->f01_container->dev.driver)
return enable_sensor(rmi_dev);
return 0;
err_destroy_functions:
rmi_free_function_list(rmi_dev);
err:
return retval < 0 ? retval : 0;
}
bool rmi_is_physical_driver(struct device_driver *drv)
{
return drv == &rmi_physical_driver.driver;
}
int __init rmi_register_physical_driver(void)
{
int error;
error = driver_register(&rmi_physical_driver.driver);
if (error) {
pr_err("%s: driver register failed, code=%d.\n", __func__,
error);
return error;
}
return 0;
}
void __exit rmi_unregister_physical_driver(void)
{
driver_unregister(&rmi_physical_driver.driver);
}
