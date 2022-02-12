static inline u32 bit_mask(u8 position)
{
return (u32)1 << position;
}
static inline bool dim_on_error(u8 error_id, const char *error_message)
{
DIMCB_OnError(error_id, error_message);
return false;
}
static int dbr_get_mask_size(u16 size)
{
int i;
for (i = 0; i < 6; i++)
if (size <= (DBR_BLOCK_SIZE << i))
return 1 << i;
return 0;
}
static int alloc_dbr(u16 size)
{
int mask_size;
int i, block_idx = 0;
if (size <= 0)
return DBR_SIZE;
mask_size = dbr_get_mask_size(size);
if (mask_size == 0)
return DBR_SIZE;
for (i = 0; i < DBR_MAP_SIZE; i++) {
u32 const blocks = (size + DBR_BLOCK_SIZE - 1) / DBR_BLOCK_SIZE;
u32 mask = ~((~(u32)0) << blocks);
do {
if ((g.dbr_map[i] & mask) == 0) {
g.dbr_map[i] |= mask;
return block_idx * DBR_BLOCK_SIZE;
}
block_idx += mask_size;
mask <<= mask_size - 1;
} while ((mask <<= 1) != 0);
}
return DBR_SIZE;
}
static void free_dbr(int offs, int size)
{
int block_idx = offs / DBR_BLOCK_SIZE;
u32 const blocks = (size + DBR_BLOCK_SIZE - 1) / DBR_BLOCK_SIZE;
u32 mask = ~((~(u32)0) << blocks);
mask <<= block_idx % 32;
g.dbr_map[block_idx / 32] &= ~mask;
}
static u32 dim2_read_ctr(u32 ctr_addr, u16 mdat_idx)
{
DIMCB_IoWrite(&g.dim2->MADR, ctr_addr);
while ((DIMCB_IoRead(&g.dim2->MCTL) & 1) != 1)
continue;
DIMCB_IoWrite(&g.dim2->MCTL, 0);
return DIMCB_IoRead((&g.dim2->MDAT0) + mdat_idx);
}
static void dim2_write_ctr_mask(u32 ctr_addr, const u32 *mask, const u32 *value)
{
enum { MADR_WNR_BIT = 31 };
DIMCB_IoWrite(&g.dim2->MCTL, 0);
if (mask[0] != 0)
DIMCB_IoWrite(&g.dim2->MDAT0, value[0]);
if (mask[1] != 0)
DIMCB_IoWrite(&g.dim2->MDAT1, value[1]);
if (mask[2] != 0)
DIMCB_IoWrite(&g.dim2->MDAT2, value[2]);
if (mask[3] != 0)
DIMCB_IoWrite(&g.dim2->MDAT3, value[3]);
DIMCB_IoWrite(&g.dim2->MDWE0, mask[0]);
DIMCB_IoWrite(&g.dim2->MDWE1, mask[1]);
DIMCB_IoWrite(&g.dim2->MDWE2, mask[2]);
DIMCB_IoWrite(&g.dim2->MDWE3, mask[3]);
DIMCB_IoWrite(&g.dim2->MADR, bit_mask(MADR_WNR_BIT) | ctr_addr);
while ((DIMCB_IoRead(&g.dim2->MCTL) & 1) != 1)
continue;
DIMCB_IoWrite(&g.dim2->MCTL, 0);
}
static inline void dim2_write_ctr(u32 ctr_addr, const u32 *value)
{
u32 const mask[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
dim2_write_ctr_mask(ctr_addr, mask, value);
}
static inline void dim2_clear_ctr(u32 ctr_addr)
{
u32 const value[4] = { 0, 0, 0, 0 };
dim2_write_ctr(ctr_addr, value);
}
static void dim2_configure_cat(u8 cat_base, u8 ch_addr, u8 ch_type,
bool read_not_write, bool sync_mfe)
{
u16 const cat =
(read_not_write << CAT_RNW_BIT) |
(ch_type << CAT_CT_SHIFT) |
(ch_addr << CAT_CL_SHIFT) |
(sync_mfe << CAT_MFE_BIT) |
(false << CAT_MT_BIT) |
(true << CAT_CE_BIT);
u8 const ctr_addr = cat_base + ch_addr / 8;
u8 const idx = (ch_addr % 8) / 2;
u8 const shift = (ch_addr % 2) * 16;
u32 mask[4] = { 0, 0, 0, 0 };
u32 value[4] = { 0, 0, 0, 0 };
mask[idx] = (u32)0xFFFF << shift;
value[idx] = cat << shift;
dim2_write_ctr_mask(ctr_addr, mask, value);
}
static void dim2_clear_cat(u8 cat_base, u8 ch_addr)
{
u8 const ctr_addr = cat_base + ch_addr / 8;
u8 const idx = (ch_addr % 8) / 2;
u8 const shift = (ch_addr % 2) * 16;
u32 mask[4] = { 0, 0, 0, 0 };
u32 value[4] = { 0, 0, 0, 0 };
mask[idx] = (u32)0xFFFF << shift;
dim2_write_ctr_mask(ctr_addr, mask, value);
}
static void dim2_configure_cdt(u8 ch_addr, u16 dbr_address, u16 hw_buffer_size,
u16 packet_length)
{
u32 cdt[4] = { 0, 0, 0, 0 };
if (packet_length)
cdt[1] = ((packet_length - 1) << CDT1_BS_ISOC_SHIFT);
cdt[3] =
((hw_buffer_size - 1) << CDT3_BD_SHIFT) |
(dbr_address << CDT3_BA_SHIFT);
dim2_write_ctr(CDT + ch_addr, cdt);
}
static void dim2_clear_cdt(u8 ch_addr)
{
u32 cdt[4] = { 0, 0, 0, 0 };
dim2_write_ctr(CDT + ch_addr, cdt);
}
static void dim2_configure_adt(u8 ch_addr)
{
u32 adt[4] = { 0, 0, 0, 0 };
adt[0] =
(true << ADT0_CE_BIT) |
(true << ADT0_LE_BIT) |
(0 << ADT0_PG_BIT);
dim2_write_ctr(ADT + ch_addr, adt);
}
static void dim2_clear_adt(u8 ch_addr)
{
u32 adt[4] = { 0, 0, 0, 0 };
dim2_write_ctr(ADT + ch_addr, adt);
}
static void dim2_start_ctrl_async(u8 ch_addr, u8 idx, u32 buf_addr,
u16 buffer_size)
{
u8 const shift = idx * 16;
u32 mask[4] = { 0, 0, 0, 0 };
u32 adt[4] = { 0, 0, 0, 0 };
mask[1] =
bit_mask(ADT1_PS_BIT + shift) |
bit_mask(ADT1_RDY_BIT + shift) |
(ADT1_CTRL_ASYNC_BD_MASK << (ADT1_BD_SHIFT + shift));
adt[1] =
(true << (ADT1_PS_BIT + shift)) |
(true << (ADT1_RDY_BIT + shift)) |
((buffer_size - 1) << (ADT1_BD_SHIFT + shift));
mask[idx + 2] = 0xFFFFFFFF;
adt[idx + 2] = buf_addr;
dim2_write_ctr_mask(ADT + ch_addr, mask, adt);
}
static void dim2_start_isoc_sync(u8 ch_addr, u8 idx, u32 buf_addr,
u16 buffer_size)
{
u8 const shift = idx * 16;
u32 mask[4] = { 0, 0, 0, 0 };
u32 adt[4] = { 0, 0, 0, 0 };
mask[1] =
bit_mask(ADT1_RDY_BIT + shift) |
(ADT1_ISOC_SYNC_BD_MASK << (ADT1_BD_SHIFT + shift));
adt[1] =
(true << (ADT1_RDY_BIT + shift)) |
((buffer_size - 1) << (ADT1_BD_SHIFT + shift));
mask[idx + 2] = 0xFFFFFFFF;
adt[idx + 2] = buf_addr;
dim2_write_ctr_mask(ADT + ch_addr, mask, adt);
}
static void dim2_clear_ctram(void)
{
u32 ctr_addr;
for (ctr_addr = 0; ctr_addr < 0x90; ctr_addr++)
dim2_clear_ctr(ctr_addr);
}
static void dim2_configure_channel(
u8 ch_addr, u8 type, u8 is_tx, u16 dbr_address, u16 hw_buffer_size,
u16 packet_length, bool sync_mfe)
{
dim2_configure_cdt(ch_addr, dbr_address, hw_buffer_size, packet_length);
dim2_configure_cat(MLB_CAT, ch_addr, type, is_tx ? 1 : 0, sync_mfe);
dim2_configure_adt(ch_addr);
dim2_configure_cat(AHB_CAT, ch_addr, type, is_tx ? 0 : 1, sync_mfe);
DIMCB_IoWrite(&g.dim2->ACMR0,
DIMCB_IoRead(&g.dim2->ACMR0) | bit_mask(ch_addr));
}
static void dim2_clear_channel(u8 ch_addr)
{
DIMCB_IoWrite(&g.dim2->ACMR0,
DIMCB_IoRead(&g.dim2->ACMR0) & ~bit_mask(ch_addr));
dim2_clear_cat(AHB_CAT, ch_addr);
dim2_clear_adt(ch_addr);
dim2_clear_cat(MLB_CAT, ch_addr);
dim2_clear_cdt(ch_addr);
}
static void state_init(struct int_ch_state *state)
{
state->request_counter = 0;
state->service_counter = 0;
state->idx1 = 0;
state->idx2 = 0;
state->level = 0;
}
static inline bool check_channel_address(u32 ch_address)
{
return ch_address > 0 && (ch_address % 2) == 0 &&
(ch_address / 2) <= (u32)CAT_CL_MASK;
}
static inline bool check_packet_length(u32 packet_length)
{
u16 const max_size = ((u16)CDT3_BD_ISOC_MASK + 1u) / ISOC_DBR_FACTOR;
if (packet_length <= 0)
return false;
if (packet_length > max_size)
return false;
if (packet_length - 1u > (u32)CDT1_BS_ISOC_MASK)
return false;
return true;
}
static inline bool check_bytes_per_frame(u32 bytes_per_frame)
{
u16 const max_size = ((u16)CDT3_BD_MASK + 1u) / SYNC_DBR_FACTOR;
if (bytes_per_frame <= 0)
return false;
if (bytes_per_frame > max_size)
return false;
return true;
}
static inline u16 norm_ctrl_async_buffer_size(u16 buf_size)
{
u16 const max_size = (u16)ADT1_CTRL_ASYNC_BD_MASK + 1u;
if (buf_size > max_size)
return max_size;
return buf_size;
}
static inline u16 norm_isoc_buffer_size(u16 buf_size, u16 packet_length)
{
u16 n;
u16 const max_size = (u16)ADT1_ISOC_SYNC_BD_MASK + 1u;
if (buf_size > max_size)
buf_size = max_size;
n = buf_size / packet_length;
if (n < 2u)
return 0;
return packet_length * n;
}
static inline u16 norm_sync_buffer_size(u16 buf_size, u16 bytes_per_frame)
{
u16 n;
u16 const max_size = (u16)ADT1_ISOC_SYNC_BD_MASK + 1u;
u32 const unit = bytes_per_frame * (u16)FRAMES_PER_SUBBUFF;
if (buf_size > max_size)
buf_size = max_size;
n = buf_size / unit;
if (n < 1u)
return 0;
return unit * n;
}
static void dim2_cleanup(void)
{
DIMCB_IoWrite(&g.dim2->MLBC0, false << MLBC0_MLBEN_BIT);
dim2_clear_ctram();
DIMCB_IoWrite(&g.dim2->MIEN, 0);
DIMCB_IoWrite(&g.dim2->ACSR0, 0xFFFFFFFF);
DIMCB_IoWrite(&g.dim2->ACSR1, 0xFFFFFFFF);
DIMCB_IoWrite(&g.dim2->ACMR0, 0);
DIMCB_IoWrite(&g.dim2->ACMR1, 0);
}
static void dim2_initialize(bool enable_6pin, u8 mlb_clock)
{
dim2_cleanup();
DIMCB_IoWrite(&g.dim2->MLBC0,
enable_6pin << MLBC0_MLBPEN_BIT |
mlb_clock << MLBC0_MLBCLK_SHIFT |
MLBC0_FCNT_VAL(FRAMES_PER_SUBBUFF) << MLBC0_FCNT_SHIFT |
true << MLBC0_MLBEN_BIT);
DIMCB_IoWrite(&g.dim2->HCMR0, 0xFFFFFFFF);
DIMCB_IoWrite(&g.dim2->HCMR1, 0xFFFFFFFF);
DIMCB_IoWrite(&g.dim2->HCTL, bit_mask(HCTL_EN_BIT));
DIMCB_IoWrite(&g.dim2->ACTL,
ACTL_DMA_MODE_VAL_DMA_MODE_1 << ACTL_DMA_MODE_BIT |
true << ACTL_SCE_BIT);
#if 0
DIMCB_IoWrite(&g.dim2->MIEN,
bit_mask(MIEN_CTX_BREAK_BIT) |
bit_mask(MIEN_CTX_PE_BIT) |
bit_mask(MIEN_CTX_DONE_BIT) |
bit_mask(MIEN_CRX_BREAK_BIT) |
bit_mask(MIEN_CRX_PE_BIT) |
bit_mask(MIEN_CRX_DONE_BIT) |
bit_mask(MIEN_ATX_BREAK_BIT) |
bit_mask(MIEN_ATX_PE_BIT) |
bit_mask(MIEN_ATX_DONE_BIT) |
bit_mask(MIEN_ARX_BREAK_BIT) |
bit_mask(MIEN_ARX_PE_BIT) |
bit_mask(MIEN_ARX_DONE_BIT));
#endif
}
static bool dim2_is_mlb_locked(void)
{
u32 const mask0 = bit_mask(MLBC0_MLBLK_BIT);
u32 const mask1 = bit_mask(MLBC1_CLKMERR_BIT) |
bit_mask(MLBC1_LOCKERR_BIT);
u32 const c1 = DIMCB_IoRead(&g.dim2->MLBC1);
u32 const nda_mask = (u32)MLBC1_NDA_MASK << MLBC1_NDA_SHIFT;
DIMCB_IoWrite(&g.dim2->MLBC1, c1 & nda_mask);
return (DIMCB_IoRead(&g.dim2->MLBC1) & mask1) == 0 &&
(DIMCB_IoRead(&g.dim2->MLBC0) & mask0) != 0;
}
static inline bool service_channel(u8 ch_addr, u8 idx)
{
u8 const shift = idx * 16;
u32 const adt1 = dim2_read_ctr(ADT + ch_addr, 1);
if (((adt1 >> (ADT1_DNE_BIT + shift)) & 1) == 0)
return false;
{
u32 mask[4] = { 0, 0, 0, 0 };
u32 adt_w[4] = { 0, 0, 0, 0 };
mask[1] =
bit_mask(ADT1_DNE_BIT + shift) |
bit_mask(ADT1_ERR_BIT + shift) |
bit_mask(ADT1_RDY_BIT + shift);
dim2_write_ctr_mask(ADT + ch_addr, mask, adt_w);
}
DIMCB_IoWrite(&g.dim2->ACSR0, bit_mask(ch_addr));
return true;
}
static void isoc_init(struct dim_channel *ch, u8 ch_addr, u16 packet_length)
{
state_init(&ch->state);
ch->addr = ch_addr;
ch->packet_length = packet_length;
ch->bytes_per_frame = 0;
ch->done_sw_buffers_number = 0;
}
static void sync_init(struct dim_channel *ch, u8 ch_addr, u16 bytes_per_frame)
{
state_init(&ch->state);
ch->addr = ch_addr;
ch->packet_length = 0;
ch->bytes_per_frame = bytes_per_frame;
ch->done_sw_buffers_number = 0;
}
static void channel_init(struct dim_channel *ch, u8 ch_addr)
{
state_init(&ch->state);
ch->addr = ch_addr;
ch->packet_length = 0;
ch->bytes_per_frame = 0;
ch->done_sw_buffers_number = 0;
}
static bool channel_service_interrupt(struct dim_channel *ch)
{
struct int_ch_state *const state = &ch->state;
if (!service_channel(ch->addr, state->idx2))
return false;
state->idx2 ^= 1;
state->request_counter++;
return true;
}
static bool channel_start(struct dim_channel *ch, u32 buf_addr, u16 buf_size)
{
struct int_ch_state *const state = &ch->state;
if (buf_size <= 0)
return dim_on_error(DIM_ERR_BAD_BUFFER_SIZE, "Bad buffer size");
if (ch->packet_length == 0 && ch->bytes_per_frame == 0 &&
buf_size != norm_ctrl_async_buffer_size(buf_size))
return dim_on_error(DIM_ERR_BAD_BUFFER_SIZE,
"Bad control/async buffer size");
if (ch->packet_length &&
buf_size != norm_isoc_buffer_size(buf_size, ch->packet_length))
return dim_on_error(DIM_ERR_BAD_BUFFER_SIZE,
"Bad isochronous buffer size");
if (ch->bytes_per_frame &&
buf_size != norm_sync_buffer_size(buf_size, ch->bytes_per_frame))
return dim_on_error(DIM_ERR_BAD_BUFFER_SIZE,
"Bad synchronous buffer size");
if (state->level >= 2u)
return dim_on_error(DIM_ERR_OVERFLOW, "Channel overflow");
++state->level;
if (ch->packet_length || ch->bytes_per_frame)
dim2_start_isoc_sync(ch->addr, state->idx1, buf_addr, buf_size);
else
dim2_start_ctrl_async(ch->addr, state->idx1, buf_addr, buf_size);
state->idx1 ^= 1;
return true;
}
static u8 channel_service(struct dim_channel *ch)
{
struct int_ch_state *const state = &ch->state;
if (state->service_counter != state->request_counter) {
state->service_counter++;
if (state->level == 0)
return DIM_ERR_UNDERFLOW;
--state->level;
ch->done_sw_buffers_number++;
}
return DIM_NO_ERROR;
}
static bool channel_detach_buffers(struct dim_channel *ch, u16 buffers_number)
{
if (buffers_number > ch->done_sw_buffers_number)
return dim_on_error(DIM_ERR_UNDERFLOW, "Channel underflow");
ch->done_sw_buffers_number -= buffers_number;
return true;
}
u8 DIM_Startup(void *dim_base_address, u32 mlb_clock)
{
g.dim_is_initialized = false;
if (!dim_base_address)
return DIM_INIT_ERR_DIM_ADDR;
if (mlb_clock >= 8)
return DIM_INIT_ERR_MLB_CLOCK;
g.dim2 = dim_base_address;
g.dbr_map[0] = g.dbr_map[1] = 0;
dim2_initialize(mlb_clock >= 3, mlb_clock);
g.dim_is_initialized = true;
return DIM_NO_ERROR;
}
void DIM_Shutdown(void)
{
g.dim_is_initialized = false;
dim2_cleanup();
}
bool DIM_GetLockState(void)
{
return dim2_is_mlb_locked();
}
static u8 init_ctrl_async(struct dim_channel *ch, u8 type, u8 is_tx,
u16 ch_address, u16 hw_buffer_size)
{
if (!g.dim_is_initialized || !ch)
return DIM_ERR_DRIVER_NOT_INITIALIZED;
if (!check_channel_address(ch_address))
return DIM_INIT_ERR_CHANNEL_ADDRESS;
ch->dbr_size = hw_buffer_size;
ch->dbr_addr = alloc_dbr(ch->dbr_size);
if (ch->dbr_addr >= DBR_SIZE)
return DIM_INIT_ERR_OUT_OF_MEMORY;
channel_init(ch, ch_address / 2);
dim2_configure_channel(ch->addr, type, is_tx,
ch->dbr_addr, ch->dbr_size, 0, false);
return DIM_NO_ERROR;
}
u16 DIM_NormCtrlAsyncBufferSize(u16 buf_size)
{
return norm_ctrl_async_buffer_size(buf_size);
}
u16 DIM_NormIsocBufferSize(u16 buf_size, u16 packet_length)
{
if (!check_packet_length(packet_length))
return 0;
return norm_isoc_buffer_size(buf_size, packet_length);
}
u16 DIM_NormSyncBufferSize(u16 buf_size, u16 bytes_per_frame)
{
if (!check_bytes_per_frame(bytes_per_frame))
return 0;
return norm_sync_buffer_size(buf_size, bytes_per_frame);
}
u8 DIM_InitControl(struct dim_channel *ch, u8 is_tx, u16 ch_address,
u16 max_buffer_size)
{
return init_ctrl_async(ch, CAT_CT_VAL_CONTROL, is_tx, ch_address,
max_buffer_size * 2);
}
u8 DIM_InitAsync(struct dim_channel *ch, u8 is_tx, u16 ch_address,
u16 max_buffer_size)
{
return init_ctrl_async(ch, CAT_CT_VAL_ASYNC, is_tx, ch_address,
max_buffer_size * 2);
}
u8 DIM_InitIsoc(struct dim_channel *ch, u8 is_tx, u16 ch_address,
u16 packet_length)
{
if (!g.dim_is_initialized || !ch)
return DIM_ERR_DRIVER_NOT_INITIALIZED;
if (!check_channel_address(ch_address))
return DIM_INIT_ERR_CHANNEL_ADDRESS;
if (!check_packet_length(packet_length))
return DIM_ERR_BAD_CONFIG;
ch->dbr_size = packet_length * ISOC_DBR_FACTOR;
ch->dbr_addr = alloc_dbr(ch->dbr_size);
if (ch->dbr_addr >= DBR_SIZE)
return DIM_INIT_ERR_OUT_OF_MEMORY;
isoc_init(ch, ch_address / 2, packet_length);
dim2_configure_channel(ch->addr, CAT_CT_VAL_ISOC, is_tx, ch->dbr_addr,
ch->dbr_size, packet_length, false);
return DIM_NO_ERROR;
}
u8 DIM_InitSync(struct dim_channel *ch, u8 is_tx, u16 ch_address,
u16 bytes_per_frame)
{
if (!g.dim_is_initialized || !ch)
return DIM_ERR_DRIVER_NOT_INITIALIZED;
if (!check_channel_address(ch_address))
return DIM_INIT_ERR_CHANNEL_ADDRESS;
if (!check_bytes_per_frame(bytes_per_frame))
return DIM_ERR_BAD_CONFIG;
ch->dbr_size = bytes_per_frame * SYNC_DBR_FACTOR;
ch->dbr_addr = alloc_dbr(ch->dbr_size);
if (ch->dbr_addr >= DBR_SIZE)
return DIM_INIT_ERR_OUT_OF_MEMORY;
sync_init(ch, ch_address / 2, bytes_per_frame);
dim2_configure_channel(ch->addr, CAT_CT_VAL_SYNC, is_tx,
ch->dbr_addr, ch->dbr_size, 0, true);
return DIM_NO_ERROR;
}
u8 DIM_DestroyChannel(struct dim_channel *ch)
{
if (!g.dim_is_initialized || !ch)
return DIM_ERR_DRIVER_NOT_INITIALIZED;
dim2_clear_channel(ch->addr);
if (ch->dbr_addr < DBR_SIZE)
free_dbr(ch->dbr_addr, ch->dbr_size);
ch->dbr_addr = DBR_SIZE;
return DIM_NO_ERROR;
}
void DIM_ServiceIrq(struct dim_channel *const *channels)
{
bool state_changed;
if (!g.dim_is_initialized) {
dim_on_error(DIM_ERR_DRIVER_NOT_INITIALIZED,
"DIM is not initialized");
return;
}
if (!channels) {
dim_on_error(DIM_ERR_DRIVER_NOT_INITIALIZED, "Bad channels");
return;
}
do {
struct dim_channel *const *ch = channels;
state_changed = false;
while (*ch) {
state_changed |= channel_service_interrupt(*ch);
++ch;
}
} while (state_changed);
DIMCB_IoWrite(&g.dim2->MS0, 0);
DIMCB_IoWrite(&g.dim2->MS1, 0);
}
u8 DIM_ServiceChannel(struct dim_channel *ch)
{
if (!g.dim_is_initialized || !ch)
return DIM_ERR_DRIVER_NOT_INITIALIZED;
return channel_service(ch);
}
struct dim_ch_state_t *DIM_GetChannelState(struct dim_channel *ch,
struct dim_ch_state_t *state_ptr)
{
if (!ch || !state_ptr)
return NULL;
state_ptr->ready = ch->state.level < 2;
state_ptr->done_buffers = ch->done_sw_buffers_number;
return state_ptr;
}
bool DIM_EnqueueBuffer(struct dim_channel *ch, u32 buffer_addr, u16 buffer_size)
{
if (!ch)
return dim_on_error(DIM_ERR_DRIVER_NOT_INITIALIZED, "Bad channel");
return channel_start(ch, buffer_addr, buffer_size);
}
bool DIM_DetachBuffers(struct dim_channel *ch, u16 buffers_number)
{
if (!ch)
return dim_on_error(DIM_ERR_DRIVER_NOT_INITIALIZED, "Bad channel");
return channel_detach_buffers(ch, buffers_number);
}
u32 DIM_ReadRegister(u8 register_index)
{
return DIMCB_IoRead((u32 *)g.dim2 + register_index);
}
