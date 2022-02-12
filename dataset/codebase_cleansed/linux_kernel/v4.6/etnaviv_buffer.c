static inline void OUT(struct etnaviv_cmdbuf *buffer, u32 data)
{
u32 *vaddr = (u32 *)buffer->vaddr;
BUG_ON(buffer->user_size >= buffer->size);
vaddr[buffer->user_size / 4] = data;
buffer->user_size += 4;
}
static inline void CMD_LOAD_STATE(struct etnaviv_cmdbuf *buffer,
u32 reg, u32 value)
{
u32 index = reg >> VIV_FE_LOAD_STATE_HEADER_OFFSET__SHR;
buffer->user_size = ALIGN(buffer->user_size, 8);
OUT(buffer, VIV_FE_LOAD_STATE_HEADER_OP_LOAD_STATE |
VIV_FE_LOAD_STATE_HEADER_COUNT(1) |
VIV_FE_LOAD_STATE_HEADER_OFFSET(index));
OUT(buffer, value);
}
static inline void CMD_END(struct etnaviv_cmdbuf *buffer)
{
buffer->user_size = ALIGN(buffer->user_size, 8);
OUT(buffer, VIV_FE_END_HEADER_OP_END);
}
static inline void CMD_WAIT(struct etnaviv_cmdbuf *buffer)
{
buffer->user_size = ALIGN(buffer->user_size, 8);
OUT(buffer, VIV_FE_WAIT_HEADER_OP_WAIT | 200);
}
static inline void CMD_LINK(struct etnaviv_cmdbuf *buffer,
u16 prefetch, u32 address)
{
buffer->user_size = ALIGN(buffer->user_size, 8);
OUT(buffer, VIV_FE_LINK_HEADER_OP_LINK |
VIV_FE_LINK_HEADER_PREFETCH(prefetch));
OUT(buffer, address);
}
static inline void CMD_STALL(struct etnaviv_cmdbuf *buffer,
u32 from, u32 to)
{
buffer->user_size = ALIGN(buffer->user_size, 8);
OUT(buffer, VIV_FE_STALL_HEADER_OP_STALL);
OUT(buffer, VIV_FE_STALL_TOKEN_FROM(from) | VIV_FE_STALL_TOKEN_TO(to));
}
static inline void CMD_SEM(struct etnaviv_cmdbuf *buffer, u32 from, u32 to)
{
CMD_LOAD_STATE(buffer, VIVS_GL_SEMAPHORE_TOKEN,
VIVS_GL_SEMAPHORE_TOKEN_FROM(from) |
VIVS_GL_SEMAPHORE_TOKEN_TO(to));
}
static void etnaviv_cmd_select_pipe(struct etnaviv_gpu *gpu,
struct etnaviv_cmdbuf *buffer, u8 pipe)
{
u32 flush = 0;
if (gpu->exec_state == ETNA_PIPE_2D)
flush = VIVS_GL_FLUSH_CACHE_PE2D;
else if (gpu->exec_state == ETNA_PIPE_3D)
flush = VIVS_GL_FLUSH_CACHE_DEPTH | VIVS_GL_FLUSH_CACHE_COLOR;
CMD_LOAD_STATE(buffer, VIVS_GL_FLUSH_CACHE, flush);
CMD_SEM(buffer, SYNC_RECIPIENT_FE, SYNC_RECIPIENT_PE);
CMD_STALL(buffer, SYNC_RECIPIENT_FE, SYNC_RECIPIENT_PE);
CMD_LOAD_STATE(buffer, VIVS_GL_PIPE_SELECT,
VIVS_GL_PIPE_SELECT_PIPE(pipe));
}
static u32 gpu_va(struct etnaviv_gpu *gpu, struct etnaviv_cmdbuf *buf)
{
return buf->paddr - gpu->memory_base;
}
static void etnaviv_buffer_dump(struct etnaviv_gpu *gpu,
struct etnaviv_cmdbuf *buf, u32 off, u32 len)
{
u32 size = buf->size;
u32 *ptr = buf->vaddr + off;
dev_info(gpu->dev, "virt %p phys 0x%08x free 0x%08x\n",
ptr, gpu_va(gpu, buf) + off, size - len * 4 - off);
print_hex_dump(KERN_INFO, "cmd ", DUMP_PREFIX_OFFSET, 16, 4,
ptr, len * 4, 0);
}
static void etnaviv_buffer_replace_wait(struct etnaviv_cmdbuf *buffer,
unsigned int wl_offset, u32 cmd, u32 arg)
{
u32 *lw = buffer->vaddr + wl_offset;
lw[1] = arg;
mb();
lw[0] = cmd;
mb();
}
static u32 etnaviv_buffer_reserve(struct etnaviv_gpu *gpu,
struct etnaviv_cmdbuf *buffer, unsigned int cmd_dwords)
{
if (buffer->user_size + cmd_dwords * sizeof(u64) > buffer->size)
buffer->user_size = 0;
return gpu_va(gpu, buffer) + buffer->user_size;
}
u16 etnaviv_buffer_init(struct etnaviv_gpu *gpu)
{
struct etnaviv_cmdbuf *buffer = gpu->buffer;
buffer->user_size = 0;
CMD_WAIT(buffer);
CMD_LINK(buffer, 2, gpu_va(gpu, buffer) + buffer->user_size - 4);
return buffer->user_size / 8;
}
void etnaviv_buffer_end(struct etnaviv_gpu *gpu)
{
struct etnaviv_cmdbuf *buffer = gpu->buffer;
unsigned int waitlink_offset = buffer->user_size - 16;
u32 link_target, flush = 0;
if (gpu->exec_state == ETNA_PIPE_2D)
flush = VIVS_GL_FLUSH_CACHE_PE2D;
else if (gpu->exec_state == ETNA_PIPE_3D)
flush = VIVS_GL_FLUSH_CACHE_DEPTH |
VIVS_GL_FLUSH_CACHE_COLOR |
VIVS_GL_FLUSH_CACHE_TEXTURE |
VIVS_GL_FLUSH_CACHE_TEXTUREVS |
VIVS_GL_FLUSH_CACHE_SHADER_L2;
if (flush) {
unsigned int dwords = 7;
link_target = etnaviv_buffer_reserve(gpu, buffer, dwords);
CMD_SEM(buffer, SYNC_RECIPIENT_FE, SYNC_RECIPIENT_PE);
CMD_STALL(buffer, SYNC_RECIPIENT_FE, SYNC_RECIPIENT_PE);
CMD_LOAD_STATE(buffer, VIVS_GL_FLUSH_CACHE, flush);
if (gpu->exec_state == ETNA_PIPE_3D)
CMD_LOAD_STATE(buffer, VIVS_TS_FLUSH_CACHE,
VIVS_TS_FLUSH_CACHE_FLUSH);
CMD_SEM(buffer, SYNC_RECIPIENT_FE, SYNC_RECIPIENT_PE);
CMD_STALL(buffer, SYNC_RECIPIENT_FE, SYNC_RECIPIENT_PE);
CMD_END(buffer);
etnaviv_buffer_replace_wait(buffer, waitlink_offset,
VIV_FE_LINK_HEADER_OP_LINK |
VIV_FE_LINK_HEADER_PREFETCH(dwords),
link_target);
} else {
etnaviv_buffer_replace_wait(buffer, waitlink_offset,
VIV_FE_END_HEADER_OP_END, 0);
}
}
void etnaviv_buffer_queue(struct etnaviv_gpu *gpu, unsigned int event,
struct etnaviv_cmdbuf *cmdbuf)
{
struct etnaviv_cmdbuf *buffer = gpu->buffer;
unsigned int waitlink_offset = buffer->user_size - 16;
u32 return_target, return_dwords;
u32 link_target, link_dwords;
if (drm_debug & DRM_UT_DRIVER)
etnaviv_buffer_dump(gpu, buffer, 0, 0x50);
link_target = gpu_va(gpu, cmdbuf);
link_dwords = cmdbuf->size / 8;
if (gpu->mmu->need_flush || gpu->switch_context) {
u32 target, extra_dwords;
extra_dwords = 1;
if (gpu->mmu->need_flush)
extra_dwords += 1;
if (gpu->switch_context)
extra_dwords += 4;
target = etnaviv_buffer_reserve(gpu, buffer, extra_dwords);
if (gpu->mmu->need_flush) {
CMD_LOAD_STATE(buffer, VIVS_GL_FLUSH_MMU,
VIVS_GL_FLUSH_MMU_FLUSH_FEMMU |
VIVS_GL_FLUSH_MMU_FLUSH_UNK1 |
VIVS_GL_FLUSH_MMU_FLUSH_UNK2 |
VIVS_GL_FLUSH_MMU_FLUSH_PEMMU |
VIVS_GL_FLUSH_MMU_FLUSH_UNK4);
gpu->mmu->need_flush = false;
}
if (gpu->switch_context) {
etnaviv_cmd_select_pipe(gpu, buffer, cmdbuf->exec_state);
gpu->exec_state = cmdbuf->exec_state;
gpu->switch_context = false;
}
CMD_LINK(buffer, link_dwords, link_target);
link_target = target;
link_dwords = extra_dwords;
}
return_dwords = 3;
return_target = etnaviv_buffer_reserve(gpu, buffer, return_dwords);
CMD_LINK(cmdbuf, return_dwords, return_target);
CMD_LOAD_STATE(buffer, VIVS_GL_EVENT, VIVS_GL_EVENT_EVENT_ID(event) |
VIVS_GL_EVENT_FROM_PE);
CMD_WAIT(buffer);
CMD_LINK(buffer, 2, return_target + 8);
if (drm_debug & DRM_UT_DRIVER)
pr_info("stream link to 0x%08x @ 0x%08x %p\n",
return_target, gpu_va(gpu, cmdbuf), cmdbuf->vaddr);
if (drm_debug & DRM_UT_DRIVER) {
print_hex_dump(KERN_INFO, "cmd ", DUMP_PREFIX_OFFSET, 16, 4,
cmdbuf->vaddr, cmdbuf->size, 0);
pr_info("link op: %p\n", buffer->vaddr + waitlink_offset);
pr_info("addr: 0x%08x\n", link_target);
pr_info("back: 0x%08x\n", return_target);
pr_info("event: %d\n", event);
}
etnaviv_buffer_replace_wait(buffer, waitlink_offset,
VIV_FE_LINK_HEADER_OP_LINK |
VIV_FE_LINK_HEADER_PREFETCH(link_dwords),
link_target);
if (drm_debug & DRM_UT_DRIVER)
etnaviv_buffer_dump(gpu, buffer, 0, 0x50);
}
