int fw_compute_block_crc(__be32 *block)
{
int length;
u16 crc;
length = (be32_to_cpu(block[0]) >> 16) & 0xff;
crc = crc_itu_t(0, (u8 *)&block[1], length * 4);
*block |= cpu_to_be32(crc);
return length;
}
static void generate_config_rom(struct fw_card *card, __be32 *config_rom)
{
struct fw_descriptor *desc;
int i, j, k, length;
config_rom[0] = cpu_to_be32(
BIB_CRC_LENGTH(4) | BIB_INFO_LENGTH(4) | BIB_CRC(0));
config_rom[1] = cpu_to_be32(BIB_BUS_NAME);
config_rom[2] = cpu_to_be32(
BIB_LINK_SPEED(card->link_speed) |
BIB_GENERATION(card->config_rom_generation++ % 14 + 2) |
BIB_MAX_ROM(2) |
BIB_MAX_RECEIVE(card->max_receive) |
BIB_BMC | BIB_ISC | BIB_CMC | BIB_IRMC);
config_rom[3] = cpu_to_be32(card->guid >> 32);
config_rom[4] = cpu_to_be32(card->guid);
config_rom[6] = cpu_to_be32(NODE_CAPABILITIES);
i = 7;
j = 7 + descriptor_count;
list_for_each_entry (desc, &descriptor_list, link) {
if (desc->immediate > 0)
config_rom[i++] = cpu_to_be32(desc->immediate);
config_rom[i] = cpu_to_be32(desc->key | (j - i));
i++;
j += desc->length;
}
config_rom[5] = cpu_to_be32((i - 5 - 1) << 16);
list_for_each_entry (desc, &descriptor_list, link) {
for (k = 0; k < desc->length; k++)
config_rom[i + k] = cpu_to_be32(desc->data[k]);
i += desc->length;
}
for (i = 0; i < j; i += length + 1)
length = fw_compute_block_crc(config_rom + i);
WARN_ON(j != config_rom_length);
}
static void update_config_roms(void)
{
struct fw_card *card;
list_for_each_entry (card, &card_list, link) {
generate_config_rom(card, tmp_config_rom);
card->driver->set_config_rom(card, tmp_config_rom,
config_rom_length);
}
}
static size_t required_space(struct fw_descriptor *desc)
{
return desc->length + 1 + (desc->immediate > 0 ? 1 : 0);
}
int fw_core_add_descriptor(struct fw_descriptor *desc)
{
size_t i;
int ret;
i = 0;
while (i < desc->length)
i += (desc->data[i] >> 16) + 1;
if (i != desc->length)
return -EINVAL;
mutex_lock(&card_mutex);
if (config_rom_length + required_space(desc) > 256) {
ret = -EBUSY;
} else {
list_add_tail(&desc->link, &descriptor_list);
config_rom_length += required_space(desc);
descriptor_count++;
if (desc->immediate > 0)
descriptor_count++;
update_config_roms();
ret = 0;
}
mutex_unlock(&card_mutex);
return ret;
}
void fw_core_remove_descriptor(struct fw_descriptor *desc)
{
mutex_lock(&card_mutex);
list_del(&desc->link);
config_rom_length -= required_space(desc);
descriptor_count--;
if (desc->immediate > 0)
descriptor_count--;
update_config_roms();
mutex_unlock(&card_mutex);
}
static int reset_bus(struct fw_card *card, bool short_reset)
{
int reg = short_reset ? 5 : 1;
int bit = short_reset ? PHY_BUS_SHORT_RESET : PHY_BUS_RESET;
return card->driver->update_phy_reg(card, reg, 0, bit);
}
void fw_schedule_bus_reset(struct fw_card *card, bool delayed, bool short_reset)
{
card->br_short = short_reset;
fw_card_get(card);
if (!queue_delayed_work(fw_workqueue, &card->br_work,
delayed ? DIV_ROUND_UP(HZ, 100) : 0))
fw_card_put(card);
}
static void br_work(struct work_struct *work)
{
struct fw_card *card = container_of(work, struct fw_card, br_work.work);
if (card->reset_jiffies != 0 &&
time_before64(get_jiffies_64(), card->reset_jiffies + 2 * HZ)) {
if (!queue_delayed_work(fw_workqueue, &card->br_work, 2 * HZ))
fw_card_put(card);
return;
}
fw_send_phy_config(card, FW_PHY_CONFIG_NO_NODE_ID, card->generation,
FW_PHY_CONFIG_CURRENT_GAP_COUNT);
reset_bus(card, card->br_short);
fw_card_put(card);
}
static void allocate_broadcast_channel(struct fw_card *card, int generation)
{
int channel, bandwidth = 0;
if (!card->broadcast_channel_allocated) {
fw_iso_resource_manage(card, generation, 1ULL << 31,
&channel, &bandwidth, true);
if (channel != 31) {
fw_notice(card, "failed to allocate broadcast channel\n");
return;
}
card->broadcast_channel_allocated = true;
}
device_for_each_child(card->device, (void *)(long)generation,
fw_device_set_broadcast_channel);
}
void fw_schedule_bm_work(struct fw_card *card, unsigned long delay)
{
fw_card_get(card);
if (!schedule_delayed_work(&card->bm_work, delay))
fw_card_put(card);
}
static void bm_work(struct work_struct *work)
{
struct fw_card *card = container_of(work, struct fw_card, bm_work.work);
struct fw_device *root_device, *irm_device;
struct fw_node *root_node;
int root_id, new_root_id, irm_id, bm_id, local_id;
int gap_count, generation, grace, rcode;
bool do_reset = false;
bool root_device_is_running;
bool root_device_is_cmc;
bool irm_is_1394_1995_only;
bool keep_this_irm;
__be32 transaction_data[2];
spin_lock_irq(&card->lock);
if (card->local_node == NULL) {
spin_unlock_irq(&card->lock);
goto out_put_card;
}
generation = card->generation;
root_node = card->root_node;
fw_node_get(root_node);
root_device = root_node->data;
root_device_is_running = root_device &&
atomic_read(&root_device->state) == FW_DEVICE_RUNNING;
root_device_is_cmc = root_device && root_device->cmc;
irm_device = card->irm_node->data;
irm_is_1394_1995_only = irm_device && irm_device->config_rom &&
(irm_device->config_rom[2] & 0x000000f0) == 0;
keep_this_irm = irm_device && irm_device->config_rom &&
irm_device->config_rom[3] >> 8 == CANON_OUI;
root_id = root_node->node_id;
irm_id = card->irm_node->node_id;
local_id = card->local_node->node_id;
grace = time_after64(get_jiffies_64(),
card->reset_jiffies + DIV_ROUND_UP(HZ, 8));
if ((is_next_generation(generation, card->bm_generation) &&
!card->bm_abdicate) ||
(card->bm_generation != generation && grace)) {
if (!card->irm_node->link_on) {
new_root_id = local_id;
fw_notice(card, "%s, making local node (%02x) root\n",
"IRM has link off", new_root_id);
goto pick_me;
}
if (irm_is_1394_1995_only && !keep_this_irm) {
new_root_id = local_id;
fw_notice(card, "%s, making local node (%02x) root\n",
"IRM is not 1394a compliant", new_root_id);
goto pick_me;
}
transaction_data[0] = cpu_to_be32(0x3f);
transaction_data[1] = cpu_to_be32(local_id);
spin_unlock_irq(&card->lock);
rcode = fw_run_transaction(card, TCODE_LOCK_COMPARE_SWAP,
irm_id, generation, SCODE_100,
CSR_REGISTER_BASE + CSR_BUS_MANAGER_ID,
transaction_data, 8);
if (rcode == RCODE_GENERATION)
goto out;
bm_id = be32_to_cpu(transaction_data[0]);
spin_lock_irq(&card->lock);
if (rcode == RCODE_COMPLETE && generation == card->generation)
card->bm_node_id =
bm_id == 0x3f ? local_id : 0xffc0 | bm_id;
spin_unlock_irq(&card->lock);
if (rcode == RCODE_COMPLETE && bm_id != 0x3f) {
if (local_id == irm_id)
allocate_broadcast_channel(card, generation);
goto out;
}
if (rcode == RCODE_SEND_ERROR) {
fw_schedule_bm_work(card, DIV_ROUND_UP(HZ, 8));
goto out;
}
spin_lock_irq(&card->lock);
if (rcode != RCODE_COMPLETE && !keep_this_irm) {
new_root_id = local_id;
fw_notice(card, "BM lock failed (%s), making local node (%02x) root\n",
fw_rcode_string(rcode), new_root_id);
goto pick_me;
}
} else if (card->bm_generation != generation) {
spin_unlock_irq(&card->lock);
fw_schedule_bm_work(card, DIV_ROUND_UP(HZ, 8));
goto out;
}
card->bm_generation = generation;
if (root_device == NULL) {
new_root_id = local_id;
} else if (!root_device_is_running) {
spin_unlock_irq(&card->lock);
goto out;
} else if (root_device_is_cmc) {
new_root_id = root_id;
} else {
new_root_id = local_id;
}
pick_me:
if (!card->beta_repeaters_present &&
root_node->max_hops < ARRAY_SIZE(gap_count_table))
gap_count = gap_count_table[root_node->max_hops];
else
gap_count = 63;
if (card->bm_retries++ < 5 &&
(card->gap_count != gap_count || new_root_id != root_id))
do_reset = true;
spin_unlock_irq(&card->lock);
if (do_reset) {
fw_notice(card, "phy config: new root=%x, gap_count=%d\n",
new_root_id, gap_count);
fw_send_phy_config(card, new_root_id, generation, gap_count);
reset_bus(card, true);
goto out;
}
if (root_device_is_cmc) {
transaction_data[0] = cpu_to_be32(CSR_STATE_BIT_CMSTR);
rcode = fw_run_transaction(card, TCODE_WRITE_QUADLET_REQUEST,
root_id, generation, SCODE_100,
CSR_REGISTER_BASE + CSR_STATE_SET,
transaction_data, 4);
if (rcode == RCODE_GENERATION)
goto out;
}
if (local_id == irm_id)
allocate_broadcast_channel(card, generation);
out:
fw_node_put(root_node);
out_put_card:
fw_card_put(card);
}
void fw_card_initialize(struct fw_card *card,
const struct fw_card_driver *driver,
struct device *device)
{
static atomic_t index = ATOMIC_INIT(-1);
card->index = atomic_inc_return(&index);
card->driver = driver;
card->device = device;
card->current_tlabel = 0;
card->tlabel_mask = 0;
card->split_timeout_hi = DEFAULT_SPLIT_TIMEOUT / 8000;
card->split_timeout_lo = (DEFAULT_SPLIT_TIMEOUT % 8000) << 19;
card->split_timeout_cycles = DEFAULT_SPLIT_TIMEOUT;
card->split_timeout_jiffies =
DIV_ROUND_UP(DEFAULT_SPLIT_TIMEOUT * HZ, 8000);
card->color = 0;
card->broadcast_channel = BROADCAST_CHANNEL_INITIAL;
kref_init(&card->kref);
init_completion(&card->done);
INIT_LIST_HEAD(&card->transaction_list);
INIT_LIST_HEAD(&card->phy_receiver_list);
spin_lock_init(&card->lock);
card->local_node = NULL;
INIT_DELAYED_WORK(&card->br_work, br_work);
INIT_DELAYED_WORK(&card->bm_work, bm_work);
}
int fw_card_add(struct fw_card *card,
u32 max_receive, u32 link_speed, u64 guid)
{
int ret;
card->max_receive = max_receive;
card->link_speed = link_speed;
card->guid = guid;
mutex_lock(&card_mutex);
generate_config_rom(card, tmp_config_rom);
ret = card->driver->enable(card, tmp_config_rom, config_rom_length);
if (ret == 0)
list_add_tail(&card->link, &card_list);
mutex_unlock(&card_mutex);
return ret;
}
static int dummy_read_phy_reg(struct fw_card *card, int address)
{
return -ENODEV;
}
static int dummy_update_phy_reg(struct fw_card *card, int address,
int clear_bits, int set_bits)
{
return -ENODEV;
}
static void dummy_send_request(struct fw_card *card, struct fw_packet *packet)
{
packet->callback(packet, card, RCODE_CANCELLED);
}
static void dummy_send_response(struct fw_card *card, struct fw_packet *packet)
{
packet->callback(packet, card, RCODE_CANCELLED);
}
static int dummy_cancel_packet(struct fw_card *card, struct fw_packet *packet)
{
return -ENOENT;
}
static int dummy_enable_phys_dma(struct fw_card *card,
int node_id, int generation)
{
return -ENODEV;
}
static struct fw_iso_context *dummy_allocate_iso_context(struct fw_card *card,
int type, int channel, size_t header_size)
{
return ERR_PTR(-ENODEV);
}
static int dummy_start_iso(struct fw_iso_context *ctx,
s32 cycle, u32 sync, u32 tags)
{
return -ENODEV;
}
static int dummy_set_iso_channels(struct fw_iso_context *ctx, u64 *channels)
{
return -ENODEV;
}
static int dummy_queue_iso(struct fw_iso_context *ctx, struct fw_iso_packet *p,
struct fw_iso_buffer *buffer, unsigned long payload)
{
return -ENODEV;
}
static void dummy_flush_queue_iso(struct fw_iso_context *ctx)
{
}
static int dummy_flush_iso_completions(struct fw_iso_context *ctx)
{
return -ENODEV;
}
void fw_card_release(struct kref *kref)
{
struct fw_card *card = container_of(kref, struct fw_card, kref);
complete(&card->done);
}
void fw_core_remove_card(struct fw_card *card)
{
struct fw_card_driver dummy_driver = dummy_driver_template;
card->driver->update_phy_reg(card, 4,
PHY_LINK_ACTIVE | PHY_CONTENDER, 0);
fw_schedule_bus_reset(card, false, true);
mutex_lock(&card_mutex);
list_del_init(&card->link);
mutex_unlock(&card_mutex);
dummy_driver.free_iso_context = card->driver->free_iso_context;
dummy_driver.stop_iso = card->driver->stop_iso;
card->driver = &dummy_driver;
fw_destroy_nodes(card);
fw_card_put(card);
wait_for_completion(&card->done);
WARN_ON(!list_empty(&card->transaction_list));
}
