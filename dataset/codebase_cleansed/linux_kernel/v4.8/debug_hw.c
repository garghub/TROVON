static unsigned int show_channel_command(struct output *o, u32 val)
{
unsigned int mask, subop;
switch (val >> 28) {
case HOST1X_OPCODE_SETCLASS:
mask = val & 0x3f;
if (mask) {
host1x_debug_output(o, "SETCL(class=%03x, offset=%03x, mask=%02x, [",
val >> 6 & 0x3ff,
val >> 16 & 0xfff, mask);
return hweight8(mask);
}
host1x_debug_output(o, "SETCL(class=%03x)\n", val >> 6 & 0x3ff);
return 0;
case HOST1X_OPCODE_INCR:
host1x_debug_output(o, "INCR(offset=%03x, [",
val >> 16 & 0xfff);
return val & 0xffff;
case HOST1X_OPCODE_NONINCR:
host1x_debug_output(o, "NONINCR(offset=%03x, [",
val >> 16 & 0xfff);
return val & 0xffff;
case HOST1X_OPCODE_MASK:
mask = val & 0xffff;
host1x_debug_output(o, "MASK(offset=%03x, mask=%03x, [",
val >> 16 & 0xfff, mask);
return hweight16(mask);
case HOST1X_OPCODE_IMM:
host1x_debug_output(o, "IMM(offset=%03x, data=%03x)\n",
val >> 16 & 0xfff, val & 0xffff);
return 0;
case HOST1X_OPCODE_RESTART:
host1x_debug_output(o, "RESTART(offset=%08x)\n", val << 4);
return 0;
case HOST1X_OPCODE_GATHER:
host1x_debug_output(o, "GATHER(offset=%03x, insert=%d, type=%d, count=%04x, addr=[",
val >> 16 & 0xfff, val >> 15 & 0x1,
val >> 14 & 0x1, val & 0x3fff);
return 1;
case HOST1X_OPCODE_EXTEND:
subop = val >> 24 & 0xf;
if (subop == HOST1X_OPCODE_EXTEND_ACQUIRE_MLOCK)
host1x_debug_output(o, "ACQUIRE_MLOCK(index=%d)\n",
val & 0xff);
else if (subop == HOST1X_OPCODE_EXTEND_RELEASE_MLOCK)
host1x_debug_output(o, "RELEASE_MLOCK(index=%d)\n",
val & 0xff);
else
host1x_debug_output(o, "EXTEND_UNKNOWN(%08x)\n", val);
return 0;
default:
return 0;
}
}
static void show_gather(struct output *o, phys_addr_t phys_addr,
unsigned int words, struct host1x_cdma *cdma,
phys_addr_t pin_addr, u32 *map_addr)
{
u32 offset = phys_addr - pin_addr;
unsigned int data_count = 0, i;
if (offset > HOST1X_DEBUG_MAX_PAGE_OFFSET) {
host1x_debug_output(o, "[address mismatch]\n");
return;
}
for (i = 0; i < words; i++) {
u32 addr = phys_addr + i * 4;
u32 val = *(map_addr + offset / 4 + i);
if (!data_count) {
host1x_debug_output(o, "%08x: %08x:", addr, val);
data_count = show_channel_command(o, val);
} else {
host1x_debug_output(o, "%08x%s", val,
data_count > 0 ? ", " : "])\n");
data_count--;
}
}
}
static void show_channel_gathers(struct output *o, struct host1x_cdma *cdma)
{
struct host1x_job *job;
list_for_each_entry(job, &cdma->sync_queue, list) {
unsigned int i;
host1x_debug_output(o, "\n%p: JOB, syncpt_id=%d, syncpt_val=%d, first_get=%08x, timeout=%d num_slots=%d, num_handles=%d\n",
job, job->syncpt_id, job->syncpt_end,
job->first_get, job->timeout,
job->num_slots, job->num_unpins);
for (i = 0; i < job->num_gathers; i++) {
struct host1x_job_gather *g = &job->gathers[i];
u32 *mapped;
if (job->gather_copy_mapped)
mapped = (u32 *)job->gather_copy_mapped;
else
mapped = host1x_bo_mmap(g->bo);
if (!mapped) {
host1x_debug_output(o, "[could not mmap]\n");
continue;
}
host1x_debug_output(o, " GATHER at %pad+%#x, %d words\n",
&g->base, g->offset, g->words);
show_gather(o, g->base + g->offset, g->words, cdma,
g->base, mapped);
if (!job->gather_copy_mapped)
host1x_bo_munmap(g->bo, mapped);
}
}
}
static void host1x_debug_show_channel_cdma(struct host1x *host,
struct host1x_channel *ch,
struct output *o)
{
struct host1x_cdma *cdma = &ch->cdma;
u32 dmaput, dmaget, dmactrl;
u32 cbstat, cbread;
u32 val, base, baseval;
dmaput = host1x_ch_readl(ch, HOST1X_CHANNEL_DMAPUT);
dmaget = host1x_ch_readl(ch, HOST1X_CHANNEL_DMAGET);
dmactrl = host1x_ch_readl(ch, HOST1X_CHANNEL_DMACTRL);
cbread = host1x_sync_readl(host, HOST1X_SYNC_CBREAD(ch->id));
cbstat = host1x_sync_readl(host, HOST1X_SYNC_CBSTAT(ch->id));
host1x_debug_output(o, "%u-%s: ", ch->id, dev_name(ch->dev));
if (HOST1X_CHANNEL_DMACTRL_DMASTOP_V(dmactrl) ||
!ch->cdma.push_buffer.mapped) {
host1x_debug_output(o, "inactive\n\n");
return;
}
if (HOST1X_SYNC_CBSTAT_CBCLASS_V(cbstat) == HOST1X_CLASS_HOST1X &&
HOST1X_SYNC_CBSTAT_CBOFFSET_V(cbstat) ==
HOST1X_UCLASS_WAIT_SYNCPT)
host1x_debug_output(o, "waiting on syncpt %d val %d\n",
cbread >> 24, cbread & 0xffffff);
else if (HOST1X_SYNC_CBSTAT_CBCLASS_V(cbstat) ==
HOST1X_CLASS_HOST1X &&
HOST1X_SYNC_CBSTAT_CBOFFSET_V(cbstat) ==
HOST1X_UCLASS_WAIT_SYNCPT_BASE) {
base = (cbread >> 16) & 0xff;
baseval =
host1x_sync_readl(host, HOST1X_SYNC_SYNCPT_BASE(base));
val = cbread & 0xffff;
host1x_debug_output(o, "waiting on syncpt %d val %d (base %d = %d; offset = %d)\n",
cbread >> 24, baseval + val, base,
baseval, val);
} else
host1x_debug_output(o, "active class %02x, offset %04x, val %08x\n",
HOST1X_SYNC_CBSTAT_CBCLASS_V(cbstat),
HOST1X_SYNC_CBSTAT_CBOFFSET_V(cbstat),
cbread);
host1x_debug_output(o, "DMAPUT %08x, DMAGET %08x, DMACTL %08x\n",
dmaput, dmaget, dmactrl);
host1x_debug_output(o, "CBREAD %08x, CBSTAT %08x\n", cbread, cbstat);
show_channel_gathers(o, cdma);
host1x_debug_output(o, "\n");
}
static void host1x_debug_show_channel_fifo(struct host1x *host,
struct host1x_channel *ch,
struct output *o)
{
u32 val, rd_ptr, wr_ptr, start, end;
unsigned int data_count = 0;
host1x_debug_output(o, "%u: fifo:\n", ch->id);
val = host1x_ch_readl(ch, HOST1X_CHANNEL_FIFOSTAT);
host1x_debug_output(o, "FIFOSTAT %08x\n", val);
if (HOST1X_CHANNEL_FIFOSTAT_CFEMPTY_V(val)) {
host1x_debug_output(o, "[empty]\n");
return;
}
host1x_sync_writel(host, 0x0, HOST1X_SYNC_CFPEEK_CTRL);
host1x_sync_writel(host, HOST1X_SYNC_CFPEEK_CTRL_ENA_F(1) |
HOST1X_SYNC_CFPEEK_CTRL_CHANNR_F(ch->id),
HOST1X_SYNC_CFPEEK_CTRL);
val = host1x_sync_readl(host, HOST1X_SYNC_CFPEEK_PTRS);
rd_ptr = HOST1X_SYNC_CFPEEK_PTRS_CF_RD_PTR_V(val);
wr_ptr = HOST1X_SYNC_CFPEEK_PTRS_CF_WR_PTR_V(val);
val = host1x_sync_readl(host, HOST1X_SYNC_CF_SETUP(ch->id));
start = HOST1X_SYNC_CF_SETUP_BASE_V(val);
end = HOST1X_SYNC_CF_SETUP_LIMIT_V(val);
do {
host1x_sync_writel(host, 0x0, HOST1X_SYNC_CFPEEK_CTRL);
host1x_sync_writel(host, HOST1X_SYNC_CFPEEK_CTRL_ENA_F(1) |
HOST1X_SYNC_CFPEEK_CTRL_CHANNR_F(ch->id) |
HOST1X_SYNC_CFPEEK_CTRL_ADDR_F(rd_ptr),
HOST1X_SYNC_CFPEEK_CTRL);
val = host1x_sync_readl(host, HOST1X_SYNC_CFPEEK_READ);
if (!data_count) {
host1x_debug_output(o, "%08x:", val);
data_count = show_channel_command(o, val);
} else {
host1x_debug_output(o, "%08x%s", val,
data_count > 0 ? ", " : "])\n");
data_count--;
}
if (rd_ptr == end)
rd_ptr = start;
else
rd_ptr++;
} while (rd_ptr != wr_ptr);
if (data_count)
host1x_debug_output(o, ", ...])\n");
host1x_debug_output(o, "\n");
host1x_sync_writel(host, 0x0, HOST1X_SYNC_CFPEEK_CTRL);
}
static void host1x_debug_show_mlocks(struct host1x *host, struct output *o)
{
unsigned int i;
host1x_debug_output(o, "---- mlocks ----\n");
for (i = 0; i < host1x_syncpt_nb_mlocks(host); i++) {
u32 owner =
host1x_sync_readl(host, HOST1X_SYNC_MLOCK_OWNER(i));
if (HOST1X_SYNC_MLOCK_OWNER_CH_OWNS_V(owner))
host1x_debug_output(o, "%u: locked by channel %u\n",
i, HOST1X_SYNC_MLOCK_OWNER_CHID_V(owner));
else if (HOST1X_SYNC_MLOCK_OWNER_CPU_OWNS_V(owner))
host1x_debug_output(o, "%u: locked by cpu\n", i);
else
host1x_debug_output(o, "%u: unlocked\n", i);
}
host1x_debug_output(o, "\n");
}
