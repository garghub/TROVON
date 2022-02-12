static uint64_t intel_pt_lower_power_of_2(uint64_t x)
{
int i;
for (i = 0; x != 1; i++)
x >>= 1;
return x << i;
}
static void intel_pt_setup_period(struct intel_pt_decoder *decoder)
{
if (decoder->period_type == INTEL_PT_PERIOD_TICKS) {
uint64_t period;
period = intel_pt_lower_power_of_2(decoder->period);
decoder->period_mask = ~(period - 1);
decoder->period_ticks = period;
}
}
static uint64_t multdiv(uint64_t t, uint32_t n, uint32_t d)
{
if (!d)
return 0;
return (t / d) * n + ((t % d) * n) / d;
}
struct intel_pt_decoder *intel_pt_decoder_new(struct intel_pt_params *params)
{
struct intel_pt_decoder *decoder;
if (!params->get_trace || !params->walk_insn)
return NULL;
decoder = zalloc(sizeof(struct intel_pt_decoder));
if (!decoder)
return NULL;
decoder->get_trace = params->get_trace;
decoder->walk_insn = params->walk_insn;
decoder->pgd_ip = params->pgd_ip;
decoder->data = params->data;
decoder->return_compression = params->return_compression;
decoder->period = params->period;
decoder->period_type = params->period_type;
decoder->max_non_turbo_ratio = params->max_non_turbo_ratio;
decoder->max_non_turbo_ratio_fp = params->max_non_turbo_ratio;
intel_pt_setup_period(decoder);
decoder->mtc_shift = params->mtc_period;
decoder->ctc_rem_mask = (1 << decoder->mtc_shift) - 1;
decoder->tsc_ctc_ratio_n = params->tsc_ctc_ratio_n;
decoder->tsc_ctc_ratio_d = params->tsc_ctc_ratio_d;
if (!decoder->tsc_ctc_ratio_n)
decoder->tsc_ctc_ratio_d = 0;
if (decoder->tsc_ctc_ratio_d) {
if (!(decoder->tsc_ctc_ratio_n % decoder->tsc_ctc_ratio_d))
decoder->tsc_ctc_mult = decoder->tsc_ctc_ratio_n /
decoder->tsc_ctc_ratio_d;
decoder->tsc_slip = multdiv(2 << decoder->mtc_shift,
decoder->tsc_ctc_ratio_n,
decoder->tsc_ctc_ratio_d);
}
if (decoder->tsc_slip < 0x100)
decoder->tsc_slip = 0x100;
intel_pt_log("timestamp: mtc_shift %u\n", decoder->mtc_shift);
intel_pt_log("timestamp: tsc_ctc_ratio_n %u\n", decoder->tsc_ctc_ratio_n);
intel_pt_log("timestamp: tsc_ctc_ratio_d %u\n", decoder->tsc_ctc_ratio_d);
intel_pt_log("timestamp: tsc_ctc_mult %u\n", decoder->tsc_ctc_mult);
intel_pt_log("timestamp: tsc_slip %#x\n", decoder->tsc_slip);
return decoder;
}
static void intel_pt_pop_blk(struct intel_pt_stack *stack)
{
struct intel_pt_blk *blk = stack->blk;
stack->blk = blk->prev;
if (!stack->spare)
stack->spare = blk;
else
free(blk);
}
static uint64_t intel_pt_pop(struct intel_pt_stack *stack)
{
if (!stack->pos) {
if (!stack->blk)
return 0;
intel_pt_pop_blk(stack);
if (!stack->blk)
return 0;
stack->pos = INTEL_PT_BLK_SIZE;
}
return stack->blk->ip[--stack->pos];
}
static int intel_pt_alloc_blk(struct intel_pt_stack *stack)
{
struct intel_pt_blk *blk;
if (stack->spare) {
blk = stack->spare;
stack->spare = NULL;
} else {
blk = malloc(sizeof(struct intel_pt_blk));
if (!blk)
return -ENOMEM;
}
blk->prev = stack->blk;
stack->blk = blk;
stack->pos = 0;
return 0;
}
static int intel_pt_push(struct intel_pt_stack *stack, uint64_t ip)
{
int err;
if (!stack->blk || stack->pos == INTEL_PT_BLK_SIZE) {
err = intel_pt_alloc_blk(stack);
if (err)
return err;
}
stack->blk->ip[stack->pos++] = ip;
return 0;
}
static void intel_pt_clear_stack(struct intel_pt_stack *stack)
{
while (stack->blk)
intel_pt_pop_blk(stack);
stack->pos = 0;
}
static void intel_pt_free_stack(struct intel_pt_stack *stack)
{
intel_pt_clear_stack(stack);
zfree(&stack->blk);
zfree(&stack->spare);
}
void intel_pt_decoder_free(struct intel_pt_decoder *decoder)
{
intel_pt_free_stack(&decoder->stack);
free(decoder);
}
static int intel_pt_ext_err(int code)
{
switch (code) {
case -ENOMEM:
return INTEL_PT_ERR_NOMEM;
case -ENOSYS:
return INTEL_PT_ERR_INTERN;
case -EBADMSG:
return INTEL_PT_ERR_BADPKT;
case -ENODATA:
return INTEL_PT_ERR_NODATA;
case -EILSEQ:
return INTEL_PT_ERR_NOINSN;
case -ENOENT:
return INTEL_PT_ERR_MISMAT;
case -EOVERFLOW:
return INTEL_PT_ERR_OVR;
case -ENOSPC:
return INTEL_PT_ERR_LOST;
case -ELOOP:
return INTEL_PT_ERR_NELOOP;
default:
return INTEL_PT_ERR_UNK;
}
}
int intel_pt__strerror(int code, char *buf, size_t buflen)
{
if (code < 1 || code >= INTEL_PT_ERR_MAX)
code = INTEL_PT_ERR_UNK;
strlcpy(buf, intel_pt_err_msgs[code], buflen);
return 0;
}
static uint64_t intel_pt_calc_ip(const struct intel_pt_pkt *packet,
uint64_t last_ip)
{
uint64_t ip;
switch (packet->count) {
case 1:
ip = (last_ip & (uint64_t)0xffffffffffff0000ULL) |
packet->payload;
break;
case 2:
ip = (last_ip & (uint64_t)0xffffffff00000000ULL) |
packet->payload;
break;
case 3:
ip = packet->payload;
if (ip & (uint64_t)0x800000000000ULL)
ip |= (uint64_t)0xffff000000000000ULL;
break;
case 4:
ip = (last_ip & (uint64_t)0xffff000000000000ULL) |
packet->payload;
break;
case 6:
ip = packet->payload;
break;
default:
return 0;
}
return ip;
}
static inline void intel_pt_set_last_ip(struct intel_pt_decoder *decoder)
{
decoder->last_ip = intel_pt_calc_ip(&decoder->packet, decoder->last_ip);
}
static inline void intel_pt_set_ip(struct intel_pt_decoder *decoder)
{
intel_pt_set_last_ip(decoder);
decoder->ip = decoder->last_ip;
}
static void intel_pt_decoder_log_packet(struct intel_pt_decoder *decoder)
{
intel_pt_log_packet(&decoder->packet, decoder->pkt_len, decoder->pos,
decoder->buf);
}
static int intel_pt_bug(struct intel_pt_decoder *decoder)
{
intel_pt_log("ERROR: Internal error\n");
decoder->pkt_state = INTEL_PT_STATE_NO_PSB;
return -ENOSYS;
}
static inline void intel_pt_clear_tx_flags(struct intel_pt_decoder *decoder)
{
decoder->tx_flags = 0;
}
static inline void intel_pt_update_in_tx(struct intel_pt_decoder *decoder)
{
decoder->tx_flags = decoder->packet.payload & INTEL_PT_IN_TX;
}
static int intel_pt_bad_packet(struct intel_pt_decoder *decoder)
{
intel_pt_clear_tx_flags(decoder);
decoder->have_tma = false;
decoder->pkt_len = 1;
decoder->pkt_step = 1;
intel_pt_decoder_log_packet(decoder);
if (decoder->pkt_state != INTEL_PT_STATE_NO_PSB) {
intel_pt_log("ERROR: Bad packet\n");
decoder->pkt_state = INTEL_PT_STATE_ERR1;
}
return -EBADMSG;
}
static int intel_pt_get_data(struct intel_pt_decoder *decoder)
{
struct intel_pt_buffer buffer = { .buf = 0, };
int ret;
decoder->pkt_step = 0;
intel_pt_log("Getting more data\n");
ret = decoder->get_trace(&buffer, decoder->data);
if (ret)
return ret;
decoder->buf = buffer.buf;
decoder->len = buffer.len;
if (!decoder->len) {
intel_pt_log("No more data\n");
return -ENODATA;
}
if (!buffer.consecutive) {
decoder->ip = 0;
decoder->pkt_state = INTEL_PT_STATE_NO_PSB;
decoder->ref_timestamp = buffer.ref_timestamp;
decoder->timestamp = 0;
decoder->have_tma = false;
decoder->state.trace_nr = buffer.trace_nr;
intel_pt_log("Reference timestamp 0x%" PRIx64 "\n",
decoder->ref_timestamp);
return -ENOLINK;
}
return 0;
}
static int intel_pt_get_next_data(struct intel_pt_decoder *decoder)
{
if (!decoder->next_buf)
return intel_pt_get_data(decoder);
decoder->buf = decoder->next_buf;
decoder->len = decoder->next_len;
decoder->next_buf = 0;
decoder->next_len = 0;
return 0;
}
static int intel_pt_get_split_packet(struct intel_pt_decoder *decoder)
{
unsigned char *buf = decoder->temp_buf;
size_t old_len, len, n;
int ret;
old_len = decoder->len;
len = decoder->len;
memcpy(buf, decoder->buf, len);
ret = intel_pt_get_data(decoder);
if (ret) {
decoder->pos += old_len;
return ret < 0 ? ret : -EINVAL;
}
n = INTEL_PT_PKT_MAX_SZ - len;
if (n > decoder->len)
n = decoder->len;
memcpy(buf + len, decoder->buf, n);
len += n;
ret = intel_pt_get_packet(buf, len, &decoder->packet);
if (ret < (int)old_len) {
decoder->next_buf = decoder->buf;
decoder->next_len = decoder->len;
decoder->buf = buf;
decoder->len = old_len;
return intel_pt_bad_packet(decoder);
}
decoder->next_buf = decoder->buf + (ret - old_len);
decoder->next_len = decoder->len - (ret - old_len);
decoder->buf = buf;
decoder->len = ret;
return ret;
}
static int intel_pt_pkt_lookahead(struct intel_pt_decoder *decoder,
intel_pt_pkt_cb_t cb, void *data)
{
struct intel_pt_pkt_info pkt_info;
const unsigned char *buf = decoder->buf;
size_t len = decoder->len;
int ret;
pkt_info.decoder = decoder;
pkt_info.pos = decoder->pos;
pkt_info.pkt_len = decoder->pkt_step;
pkt_info.last_packet_type = decoder->last_packet_type;
pkt_info.data = data;
while (1) {
do {
pkt_info.pos += pkt_info.pkt_len;
buf += pkt_info.pkt_len;
len -= pkt_info.pkt_len;
if (!len)
return INTEL_PT_NEED_MORE_BYTES;
ret = intel_pt_get_packet(buf, len, &pkt_info.packet);
if (!ret)
return INTEL_PT_NEED_MORE_BYTES;
if (ret < 0)
return ret;
pkt_info.pkt_len = ret;
} while (pkt_info.packet.type == INTEL_PT_PAD);
ret = cb(&pkt_info);
if (ret)
return 0;
pkt_info.last_packet_type = pkt_info.packet.type;
}
}
static void intel_pt_fixup_last_mtc(uint32_t mtc, int mtc_shift,
uint32_t *last_mtc)
{
uint32_t first_missing_bit = 1U << (16 - mtc_shift);
uint32_t mask = ~(first_missing_bit - 1);
*last_mtc |= mtc & mask;
if (*last_mtc >= mtc) {
*last_mtc -= first_missing_bit;
*last_mtc &= 0xff;
}
}
static int intel_pt_calc_cyc_cb(struct intel_pt_pkt_info *pkt_info)
{
struct intel_pt_decoder *decoder = pkt_info->decoder;
struct intel_pt_calc_cyc_to_tsc_info *data = pkt_info->data;
uint64_t timestamp;
double cyc_to_tsc;
unsigned int cbr;
uint32_t mtc, mtc_delta, ctc, fc, ctc_rem;
switch (pkt_info->packet.type) {
case INTEL_PT_TNT:
case INTEL_PT_TIP_PGE:
case INTEL_PT_TIP:
case INTEL_PT_FUP:
case INTEL_PT_PSB:
case INTEL_PT_PIP:
case INTEL_PT_MODE_EXEC:
case INTEL_PT_MODE_TSX:
case INTEL_PT_PSBEND:
case INTEL_PT_PAD:
case INTEL_PT_VMCS:
case INTEL_PT_MNT:
return 0;
case INTEL_PT_MTC:
if (!data->have_tma)
return 0;
mtc = pkt_info->packet.payload;
if (decoder->mtc_shift > 8 && data->fixup_last_mtc) {
data->fixup_last_mtc = false;
intel_pt_fixup_last_mtc(mtc, decoder->mtc_shift,
&data->last_mtc);
}
if (mtc > data->last_mtc)
mtc_delta = mtc - data->last_mtc;
else
mtc_delta = mtc + 256 - data->last_mtc;
data->ctc_delta += mtc_delta << decoder->mtc_shift;
data->last_mtc = mtc;
if (decoder->tsc_ctc_mult) {
timestamp = data->ctc_timestamp +
data->ctc_delta * decoder->tsc_ctc_mult;
} else {
timestamp = data->ctc_timestamp +
multdiv(data->ctc_delta,
decoder->tsc_ctc_ratio_n,
decoder->tsc_ctc_ratio_d);
}
if (timestamp < data->timestamp)
return 1;
if (pkt_info->last_packet_type != INTEL_PT_CYC) {
data->timestamp = timestamp;
return 0;
}
break;
case INTEL_PT_TSC:
timestamp = pkt_info->packet.payload |
(data->timestamp & (0xffULL << 56));
if (data->from_mtc && timestamp < data->timestamp &&
data->timestamp - timestamp < decoder->tsc_slip)
return 1;
if (timestamp < data->timestamp)
timestamp += (1ULL << 56);
if (pkt_info->last_packet_type != INTEL_PT_CYC) {
if (data->from_mtc)
return 1;
data->tsc_timestamp = timestamp;
data->timestamp = timestamp;
return 0;
}
break;
case INTEL_PT_TMA:
if (data->from_mtc)
return 1;
if (!decoder->tsc_ctc_ratio_d)
return 0;
ctc = pkt_info->packet.payload;
fc = pkt_info->packet.count;
ctc_rem = ctc & decoder->ctc_rem_mask;
data->last_mtc = (ctc >> decoder->mtc_shift) & 0xff;
data->ctc_timestamp = data->tsc_timestamp - fc;
if (decoder->tsc_ctc_mult) {
data->ctc_timestamp -= ctc_rem * decoder->tsc_ctc_mult;
} else {
data->ctc_timestamp -=
multdiv(ctc_rem, decoder->tsc_ctc_ratio_n,
decoder->tsc_ctc_ratio_d);
}
data->ctc_delta = 0;
data->have_tma = true;
data->fixup_last_mtc = true;
return 0;
case INTEL_PT_CYC:
data->cycle_cnt += pkt_info->packet.payload;
return 0;
case INTEL_PT_CBR:
cbr = pkt_info->packet.payload;
if (data->cbr && data->cbr != cbr)
return 1;
data->cbr = cbr;
data->cbr_cyc_to_tsc = decoder->max_non_turbo_ratio_fp / cbr;
return 0;
case INTEL_PT_TIP_PGD:
case INTEL_PT_TRACESTOP:
case INTEL_PT_OVF:
case INTEL_PT_BAD:
default:
return 1;
}
if (!data->cbr && decoder->cbr) {
data->cbr = decoder->cbr;
data->cbr_cyc_to_tsc = decoder->cbr_cyc_to_tsc;
}
if (!data->cycle_cnt)
return 1;
cyc_to_tsc = (double)(timestamp - decoder->timestamp) / data->cycle_cnt;
if (data->cbr && cyc_to_tsc > data->cbr_cyc_to_tsc &&
cyc_to_tsc / data->cbr_cyc_to_tsc > 1.25) {
intel_pt_log("Timestamp: calculated %g TSC ticks per cycle too big (c.f. CBR-based value %g), pos " x64_fmt "\n",
cyc_to_tsc, data->cbr_cyc_to_tsc, pkt_info->pos);
return 1;
}
decoder->calc_cyc_to_tsc = cyc_to_tsc;
decoder->have_calc_cyc_to_tsc = true;
if (data->cbr) {
intel_pt_log("Timestamp: calculated %g TSC ticks per cycle c.f. CBR-based value %g, pos " x64_fmt "\n",
cyc_to_tsc, data->cbr_cyc_to_tsc, pkt_info->pos);
} else {
intel_pt_log("Timestamp: calculated %g TSC ticks per cycle c.f. unknown CBR-based value, pos " x64_fmt "\n",
cyc_to_tsc, pkt_info->pos);
}
return 1;
}
static void intel_pt_calc_cyc_to_tsc(struct intel_pt_decoder *decoder,
bool from_mtc)
{
struct intel_pt_calc_cyc_to_tsc_info data = {
.cycle_cnt = 0,
.cbr = 0,
.last_mtc = decoder->last_mtc,
.ctc_timestamp = decoder->ctc_timestamp,
.ctc_delta = decoder->ctc_delta,
.tsc_timestamp = decoder->tsc_timestamp,
.timestamp = decoder->timestamp,
.have_tma = decoder->have_tma,
.fixup_last_mtc = decoder->fixup_last_mtc,
.from_mtc = from_mtc,
.cbr_cyc_to_tsc = 0,
};
intel_pt_pkt_lookahead(decoder, intel_pt_calc_cyc_cb, &data);
}
static int intel_pt_get_next_packet(struct intel_pt_decoder *decoder)
{
int ret;
decoder->last_packet_type = decoder->packet.type;
do {
decoder->pos += decoder->pkt_step;
decoder->buf += decoder->pkt_step;
decoder->len -= decoder->pkt_step;
if (!decoder->len) {
ret = intel_pt_get_next_data(decoder);
if (ret)
return ret;
}
ret = intel_pt_get_packet(decoder->buf, decoder->len,
&decoder->packet);
if (ret == INTEL_PT_NEED_MORE_BYTES &&
decoder->len < INTEL_PT_PKT_MAX_SZ && !decoder->next_buf) {
ret = intel_pt_get_split_packet(decoder);
if (ret < 0)
return ret;
}
if (ret <= 0)
return intel_pt_bad_packet(decoder);
decoder->pkt_len = ret;
decoder->pkt_step = ret;
intel_pt_decoder_log_packet(decoder);
} while (decoder->packet.type == INTEL_PT_PAD);
return 0;
}
static uint64_t intel_pt_next_period(struct intel_pt_decoder *decoder)
{
uint64_t timestamp, masked_timestamp;
timestamp = decoder->timestamp + decoder->timestamp_insn_cnt;
masked_timestamp = timestamp & decoder->period_mask;
if (decoder->continuous_period) {
if (masked_timestamp != decoder->last_masked_timestamp)
return 1;
} else {
timestamp += 1;
masked_timestamp = timestamp & decoder->period_mask;
if (masked_timestamp != decoder->last_masked_timestamp) {
decoder->last_masked_timestamp = masked_timestamp;
decoder->continuous_period = true;
}
}
return decoder->period_ticks - (timestamp - masked_timestamp);
}
static uint64_t intel_pt_next_sample(struct intel_pt_decoder *decoder)
{
switch (decoder->period_type) {
case INTEL_PT_PERIOD_INSTRUCTIONS:
return decoder->period - decoder->period_insn_cnt;
case INTEL_PT_PERIOD_TICKS:
return intel_pt_next_period(decoder);
case INTEL_PT_PERIOD_NONE:
case INTEL_PT_PERIOD_MTC:
default:
return 0;
}
}
static void intel_pt_sample_insn(struct intel_pt_decoder *decoder)
{
uint64_t timestamp, masked_timestamp;
switch (decoder->period_type) {
case INTEL_PT_PERIOD_INSTRUCTIONS:
decoder->period_insn_cnt = 0;
break;
case INTEL_PT_PERIOD_TICKS:
timestamp = decoder->timestamp + decoder->timestamp_insn_cnt;
masked_timestamp = timestamp & decoder->period_mask;
decoder->last_masked_timestamp = masked_timestamp;
break;
case INTEL_PT_PERIOD_NONE:
case INTEL_PT_PERIOD_MTC:
default:
break;
}
decoder->state.type |= INTEL_PT_INSTRUCTION;
}
static int intel_pt_walk_insn(struct intel_pt_decoder *decoder,
struct intel_pt_insn *intel_pt_insn, uint64_t ip)
{
uint64_t max_insn_cnt, insn_cnt = 0;
int err;
if (!decoder->mtc_insn)
decoder->mtc_insn = true;
max_insn_cnt = intel_pt_next_sample(decoder);
err = decoder->walk_insn(intel_pt_insn, &insn_cnt, &decoder->ip, ip,
max_insn_cnt, decoder->data);
decoder->tot_insn_cnt += insn_cnt;
decoder->timestamp_insn_cnt += insn_cnt;
decoder->period_insn_cnt += insn_cnt;
if (err) {
decoder->no_progress = 0;
decoder->pkt_state = INTEL_PT_STATE_ERR2;
intel_pt_log_at("ERROR: Failed to get instruction",
decoder->ip);
if (err == -ENOENT)
return -ENOLINK;
return -EILSEQ;
}
if (ip && decoder->ip == ip) {
err = -EAGAIN;
goto out;
}
if (max_insn_cnt && insn_cnt >= max_insn_cnt)
intel_pt_sample_insn(decoder);
if (intel_pt_insn->branch == INTEL_PT_BR_NO_BRANCH) {
decoder->state.type = INTEL_PT_INSTRUCTION;
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
decoder->ip += intel_pt_insn->length;
err = INTEL_PT_RETURN;
goto out;
}
if (intel_pt_insn->op == INTEL_PT_OP_CALL) {
if (intel_pt_insn->branch != INTEL_PT_BR_UNCONDITIONAL ||
intel_pt_insn->rel) {
err = intel_pt_push(&decoder->stack, decoder->ip +
intel_pt_insn->length);
if (err)
goto out;
}
} else if (intel_pt_insn->op == INTEL_PT_OP_RET) {
decoder->ret_addr = intel_pt_pop(&decoder->stack);
}
if (intel_pt_insn->branch == INTEL_PT_BR_UNCONDITIONAL) {
int cnt = decoder->no_progress++;
decoder->state.from_ip = decoder->ip;
decoder->ip += intel_pt_insn->length +
intel_pt_insn->rel;
decoder->state.to_ip = decoder->ip;
err = INTEL_PT_RETURN;
if (cnt) {
if (cnt == 1) {
decoder->stuck_ip = decoder->state.to_ip;
decoder->stuck_ip_prd = 1;
decoder->stuck_ip_cnt = 1;
} else if (cnt > INTEL_PT_MAX_LOOPS ||
decoder->state.to_ip == decoder->stuck_ip) {
intel_pt_log_at("ERROR: Never-ending loop",
decoder->state.to_ip);
decoder->pkt_state = INTEL_PT_STATE_ERR_RESYNC;
err = -ELOOP;
goto out;
} else if (!--decoder->stuck_ip_cnt) {
decoder->stuck_ip_prd += 1;
decoder->stuck_ip_cnt = decoder->stuck_ip_prd;
decoder->stuck_ip = decoder->state.to_ip;
}
}
goto out_no_progress;
}
out:
decoder->no_progress = 0;
out_no_progress:
decoder->state.insn_op = intel_pt_insn->op;
decoder->state.insn_len = intel_pt_insn->length;
memcpy(decoder->state.insn, intel_pt_insn->buf,
INTEL_PT_INSN_BUF_SZ);
if (decoder->tx_flags & INTEL_PT_IN_TX)
decoder->state.flags |= INTEL_PT_IN_TX;
return err;
}
static int intel_pt_walk_fup(struct intel_pt_decoder *decoder)
{
struct intel_pt_insn intel_pt_insn;
uint64_t ip;
int err;
ip = decoder->last_ip;
while (1) {
err = intel_pt_walk_insn(decoder, &intel_pt_insn, ip);
if (err == INTEL_PT_RETURN)
return 0;
if (err == -EAGAIN) {
if (decoder->set_fup_tx_flags) {
decoder->set_fup_tx_flags = false;
decoder->tx_flags = decoder->fup_tx_flags;
decoder->state.type = INTEL_PT_TRANSACTION;
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
decoder->state.flags = decoder->fup_tx_flags;
return 0;
}
return err;
}
decoder->set_fup_tx_flags = false;
if (err)
return err;
if (intel_pt_insn.branch == INTEL_PT_BR_INDIRECT) {
intel_pt_log_at("ERROR: Unexpected indirect branch",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR_RESYNC;
return -ENOENT;
}
if (intel_pt_insn.branch == INTEL_PT_BR_CONDITIONAL) {
intel_pt_log_at("ERROR: Unexpected conditional branch",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR_RESYNC;
return -ENOENT;
}
intel_pt_bug(decoder);
}
}
static int intel_pt_walk_tip(struct intel_pt_decoder *decoder)
{
struct intel_pt_insn intel_pt_insn;
int err;
err = intel_pt_walk_insn(decoder, &intel_pt_insn, 0);
if (err == INTEL_PT_RETURN &&
decoder->pgd_ip &&
decoder->pkt_state == INTEL_PT_STATE_TIP_PGD &&
(decoder->state.type & INTEL_PT_BRANCH) &&
decoder->pgd_ip(decoder->state.to_ip, decoder->data)) {
decoder->no_progress = 0;
decoder->pge = false;
decoder->continuous_period = false;
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
decoder->state.to_ip = 0;
return 0;
}
if (err == INTEL_PT_RETURN)
return 0;
if (err)
return err;
if (intel_pt_insn.branch == INTEL_PT_BR_INDIRECT) {
if (decoder->pkt_state == INTEL_PT_STATE_TIP_PGD) {
decoder->pge = false;
decoder->continuous_period = false;
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
if (decoder->packet.count != 0)
decoder->ip = decoder->last_ip;
} else {
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
decoder->state.from_ip = decoder->ip;
if (decoder->packet.count == 0) {
decoder->state.to_ip = 0;
} else {
decoder->state.to_ip = decoder->last_ip;
decoder->ip = decoder->last_ip;
}
}
return 0;
}
if (intel_pt_insn.branch == INTEL_PT_BR_CONDITIONAL) {
uint64_t to_ip = decoder->ip + intel_pt_insn.length +
intel_pt_insn.rel;
if (decoder->pgd_ip &&
decoder->pkt_state == INTEL_PT_STATE_TIP_PGD &&
decoder->pgd_ip(to_ip, decoder->data)) {
decoder->pge = false;
decoder->continuous_period = false;
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
decoder->ip = to_ip;
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
return 0;
}
intel_pt_log_at("ERROR: Conditional branch when expecting indirect branch",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR_RESYNC;
return -ENOENT;
}
return intel_pt_bug(decoder);
}
static int intel_pt_walk_tnt(struct intel_pt_decoder *decoder)
{
struct intel_pt_insn intel_pt_insn;
int err;
while (1) {
err = intel_pt_walk_insn(decoder, &intel_pt_insn, 0);
if (err == INTEL_PT_RETURN)
return 0;
if (err)
return err;
if (intel_pt_insn.op == INTEL_PT_OP_RET) {
if (!decoder->return_compression) {
intel_pt_log_at("ERROR: RET when expecting conditional branch",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR3;
return -ENOENT;
}
if (!decoder->ret_addr) {
intel_pt_log_at("ERROR: Bad RET compression (stack empty)",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR3;
return -ENOENT;
}
if (!(decoder->tnt.payload & BIT63)) {
intel_pt_log_at("ERROR: Bad RET compression (TNT=N)",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR3;
return -ENOENT;
}
decoder->tnt.count -= 1;
if (!decoder->tnt.count)
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
decoder->tnt.payload <<= 1;
decoder->state.from_ip = decoder->ip;
decoder->ip = decoder->ret_addr;
decoder->state.to_ip = decoder->ip;
return 0;
}
if (intel_pt_insn.branch == INTEL_PT_BR_INDIRECT) {
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
if (decoder->packet.type != INTEL_PT_TIP ||
decoder->packet.count == 0) {
intel_pt_log_at("ERROR: Missing deferred TIP for indirect branch",
decoder->ip);
decoder->pkt_state = INTEL_PT_STATE_ERR3;
decoder->pkt_step = 0;
return -ENOENT;
}
intel_pt_set_last_ip(decoder);
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = decoder->last_ip;
decoder->ip = decoder->last_ip;
return 0;
}
if (intel_pt_insn.branch == INTEL_PT_BR_CONDITIONAL) {
decoder->tnt.count -= 1;
if (!decoder->tnt.count)
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
if (decoder->tnt.payload & BIT63) {
decoder->tnt.payload <<= 1;
decoder->state.from_ip = decoder->ip;
decoder->ip += intel_pt_insn.length +
intel_pt_insn.rel;
decoder->state.to_ip = decoder->ip;
return 0;
}
if (decoder->state.type & INTEL_PT_INSTRUCTION) {
decoder->tnt.payload <<= 1;
decoder->state.type = INTEL_PT_INSTRUCTION;
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
decoder->ip += intel_pt_insn.length;
return 0;
}
decoder->ip += intel_pt_insn.length;
if (!decoder->tnt.count)
return -EAGAIN;
decoder->tnt.payload <<= 1;
continue;
}
return intel_pt_bug(decoder);
}
}
static int intel_pt_mode_tsx(struct intel_pt_decoder *decoder, bool *no_tip)
{
unsigned int fup_tx_flags;
int err;
fup_tx_flags = decoder->packet.payload &
(INTEL_PT_IN_TX | INTEL_PT_ABORT_TX);
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
if (decoder->packet.type == INTEL_PT_FUP) {
decoder->fup_tx_flags = fup_tx_flags;
decoder->set_fup_tx_flags = true;
if (!(decoder->fup_tx_flags & INTEL_PT_ABORT_TX))
*no_tip = true;
} else {
intel_pt_log_at("ERROR: Missing FUP after MODE.TSX",
decoder->pos);
intel_pt_update_in_tx(decoder);
}
return 0;
}
static void intel_pt_calc_tsc_timestamp(struct intel_pt_decoder *decoder)
{
uint64_t timestamp;
decoder->have_tma = false;
if (decoder->ref_timestamp) {
timestamp = decoder->packet.payload |
(decoder->ref_timestamp & (0xffULL << 56));
if (timestamp < decoder->ref_timestamp) {
if (decoder->ref_timestamp - timestamp > (1ULL << 55))
timestamp += (1ULL << 56);
} else {
if (timestamp - decoder->ref_timestamp > (1ULL << 55))
timestamp -= (1ULL << 56);
}
decoder->tsc_timestamp = timestamp;
decoder->timestamp = timestamp;
decoder->ref_timestamp = 0;
decoder->timestamp_insn_cnt = 0;
} else if (decoder->timestamp) {
timestamp = decoder->packet.payload |
(decoder->timestamp & (0xffULL << 56));
decoder->tsc_timestamp = timestamp;
if (timestamp < decoder->timestamp &&
decoder->timestamp - timestamp < decoder->tsc_slip) {
intel_pt_log_to("Suppressing backwards timestamp",
timestamp);
timestamp = decoder->timestamp;
}
if (timestamp < decoder->timestamp) {
intel_pt_log_to("Wraparound timestamp", timestamp);
timestamp += (1ULL << 56);
decoder->tsc_timestamp = timestamp;
}
decoder->timestamp = timestamp;
decoder->timestamp_insn_cnt = 0;
}
if (decoder->last_packet_type == INTEL_PT_CYC) {
decoder->cyc_ref_timestamp = decoder->timestamp;
decoder->cycle_cnt = 0;
decoder->have_calc_cyc_to_tsc = false;
intel_pt_calc_cyc_to_tsc(decoder, false);
}
intel_pt_log_to("Setting timestamp", decoder->timestamp);
}
static int intel_pt_overflow(struct intel_pt_decoder *decoder)
{
intel_pt_log("ERROR: Buffer overflow\n");
intel_pt_clear_tx_flags(decoder);
decoder->have_tma = false;
decoder->cbr = 0;
decoder->pkt_state = INTEL_PT_STATE_ERR_RESYNC;
decoder->overflow = true;
return -EOVERFLOW;
}
static void intel_pt_calc_tma(struct intel_pt_decoder *decoder)
{
uint32_t ctc = decoder->packet.payload;
uint32_t fc = decoder->packet.count;
uint32_t ctc_rem = ctc & decoder->ctc_rem_mask;
if (!decoder->tsc_ctc_ratio_d)
return;
decoder->last_mtc = (ctc >> decoder->mtc_shift) & 0xff;
decoder->ctc_timestamp = decoder->tsc_timestamp - fc;
if (decoder->tsc_ctc_mult) {
decoder->ctc_timestamp -= ctc_rem * decoder->tsc_ctc_mult;
} else {
decoder->ctc_timestamp -= multdiv(ctc_rem,
decoder->tsc_ctc_ratio_n,
decoder->tsc_ctc_ratio_d);
}
decoder->ctc_delta = 0;
decoder->have_tma = true;
decoder->fixup_last_mtc = true;
intel_pt_log("CTC timestamp " x64_fmt " last MTC %#x CTC rem %#x\n",
decoder->ctc_timestamp, decoder->last_mtc, ctc_rem);
}
static void intel_pt_calc_mtc_timestamp(struct intel_pt_decoder *decoder)
{
uint64_t timestamp;
uint32_t mtc, mtc_delta;
if (!decoder->have_tma)
return;
mtc = decoder->packet.payload;
if (decoder->mtc_shift > 8 && decoder->fixup_last_mtc) {
decoder->fixup_last_mtc = false;
intel_pt_fixup_last_mtc(mtc, decoder->mtc_shift,
&decoder->last_mtc);
}
if (mtc > decoder->last_mtc)
mtc_delta = mtc - decoder->last_mtc;
else
mtc_delta = mtc + 256 - decoder->last_mtc;
decoder->ctc_delta += mtc_delta << decoder->mtc_shift;
if (decoder->tsc_ctc_mult) {
timestamp = decoder->ctc_timestamp +
decoder->ctc_delta * decoder->tsc_ctc_mult;
} else {
timestamp = decoder->ctc_timestamp +
multdiv(decoder->ctc_delta,
decoder->tsc_ctc_ratio_n,
decoder->tsc_ctc_ratio_d);
}
if (timestamp < decoder->timestamp)
intel_pt_log("Suppressing MTC timestamp " x64_fmt " less than current timestamp " x64_fmt "\n",
timestamp, decoder->timestamp);
else
decoder->timestamp = timestamp;
decoder->timestamp_insn_cnt = 0;
decoder->last_mtc = mtc;
if (decoder->last_packet_type == INTEL_PT_CYC) {
decoder->cyc_ref_timestamp = decoder->timestamp;
decoder->cycle_cnt = 0;
decoder->have_calc_cyc_to_tsc = false;
intel_pt_calc_cyc_to_tsc(decoder, true);
}
}
static void intel_pt_calc_cbr(struct intel_pt_decoder *decoder)
{
unsigned int cbr = decoder->packet.payload;
if (decoder->cbr == cbr)
return;
decoder->cbr = cbr;
decoder->cbr_cyc_to_tsc = decoder->max_non_turbo_ratio_fp / cbr;
}
static void intel_pt_calc_cyc_timestamp(struct intel_pt_decoder *decoder)
{
uint64_t timestamp = decoder->cyc_ref_timestamp;
decoder->have_cyc = true;
decoder->cycle_cnt += decoder->packet.payload;
if (!decoder->cyc_ref_timestamp)
return;
if (decoder->have_calc_cyc_to_tsc)
timestamp += decoder->cycle_cnt * decoder->calc_cyc_to_tsc;
else if (decoder->cbr)
timestamp += decoder->cycle_cnt * decoder->cbr_cyc_to_tsc;
else
return;
if (timestamp < decoder->timestamp)
intel_pt_log("Suppressing CYC timestamp " x64_fmt " less than current timestamp " x64_fmt "\n",
timestamp, decoder->timestamp);
else
decoder->timestamp = timestamp;
decoder->timestamp_insn_cnt = 0;
}
static int intel_pt_walk_psbend(struct intel_pt_decoder *decoder)
{
int err;
while (1) {
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
switch (decoder->packet.type) {
case INTEL_PT_PSBEND:
return 0;
case INTEL_PT_TIP_PGD:
case INTEL_PT_TIP_PGE:
case INTEL_PT_TIP:
case INTEL_PT_TNT:
case INTEL_PT_TRACESTOP:
case INTEL_PT_BAD:
case INTEL_PT_PSB:
decoder->have_tma = false;
intel_pt_log("ERROR: Unexpected packet\n");
return -EAGAIN;
case INTEL_PT_OVF:
return intel_pt_overflow(decoder);
case INTEL_PT_TSC:
intel_pt_calc_tsc_timestamp(decoder);
break;
case INTEL_PT_TMA:
intel_pt_calc_tma(decoder);
break;
case INTEL_PT_CBR:
intel_pt_calc_cbr(decoder);
break;
case INTEL_PT_MODE_EXEC:
decoder->exec_mode = decoder->packet.payload;
break;
case INTEL_PT_PIP:
decoder->cr3 = decoder->packet.payload & (BIT63 - 1);
break;
case INTEL_PT_FUP:
decoder->pge = true;
intel_pt_set_last_ip(decoder);
break;
case INTEL_PT_MODE_TSX:
intel_pt_update_in_tx(decoder);
break;
case INTEL_PT_MTC:
intel_pt_calc_mtc_timestamp(decoder);
if (decoder->period_type == INTEL_PT_PERIOD_MTC)
decoder->state.type |= INTEL_PT_INSTRUCTION;
break;
case INTEL_PT_CYC:
case INTEL_PT_VMCS:
case INTEL_PT_MNT:
case INTEL_PT_PAD:
default:
break;
}
}
}
static int intel_pt_walk_fup_tip(struct intel_pt_decoder *decoder)
{
int err;
if (decoder->tx_flags & INTEL_PT_ABORT_TX) {
decoder->tx_flags = 0;
decoder->state.flags &= ~INTEL_PT_IN_TX;
decoder->state.flags |= INTEL_PT_ABORT_TX;
} else {
decoder->state.flags |= INTEL_PT_ASYNC;
}
while (1) {
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
switch (decoder->packet.type) {
case INTEL_PT_TNT:
case INTEL_PT_FUP:
case INTEL_PT_TRACESTOP:
case INTEL_PT_PSB:
case INTEL_PT_TSC:
case INTEL_PT_TMA:
case INTEL_PT_CBR:
case INTEL_PT_MODE_TSX:
case INTEL_PT_BAD:
case INTEL_PT_PSBEND:
intel_pt_log("ERROR: Missing TIP after FUP\n");
decoder->pkt_state = INTEL_PT_STATE_ERR3;
return -ENOENT;
case INTEL_PT_OVF:
return intel_pt_overflow(decoder);
case INTEL_PT_TIP_PGD:
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
if (decoder->packet.count != 0) {
intel_pt_set_ip(decoder);
intel_pt_log("Omitting PGD ip " x64_fmt "\n",
decoder->ip);
}
decoder->pge = false;
decoder->continuous_period = false;
return 0;
case INTEL_PT_TIP_PGE:
decoder->pge = true;
intel_pt_log("Omitting PGE ip " x64_fmt "\n",
decoder->ip);
decoder->state.from_ip = 0;
if (decoder->packet.count == 0) {
decoder->state.to_ip = 0;
} else {
intel_pt_set_ip(decoder);
decoder->state.to_ip = decoder->ip;
}
return 0;
case INTEL_PT_TIP:
decoder->state.from_ip = decoder->ip;
if (decoder->packet.count == 0) {
decoder->state.to_ip = 0;
} else {
intel_pt_set_ip(decoder);
decoder->state.to_ip = decoder->ip;
}
return 0;
case INTEL_PT_PIP:
decoder->cr3 = decoder->packet.payload & (BIT63 - 1);
break;
case INTEL_PT_MTC:
intel_pt_calc_mtc_timestamp(decoder);
if (decoder->period_type == INTEL_PT_PERIOD_MTC)
decoder->state.type |= INTEL_PT_INSTRUCTION;
break;
case INTEL_PT_CYC:
intel_pt_calc_cyc_timestamp(decoder);
break;
case INTEL_PT_MODE_EXEC:
decoder->exec_mode = decoder->packet.payload;
break;
case INTEL_PT_VMCS:
case INTEL_PT_MNT:
case INTEL_PT_PAD:
break;
default:
return intel_pt_bug(decoder);
}
}
}
static int intel_pt_walk_trace(struct intel_pt_decoder *decoder)
{
bool no_tip = false;
int err;
while (1) {
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
next:
switch (decoder->packet.type) {
case INTEL_PT_TNT:
if (!decoder->packet.count)
break;
decoder->tnt = decoder->packet;
decoder->pkt_state = INTEL_PT_STATE_TNT;
err = intel_pt_walk_tnt(decoder);
if (err == -EAGAIN)
break;
return err;
case INTEL_PT_TIP_PGD:
if (decoder->packet.count != 0)
intel_pt_set_last_ip(decoder);
decoder->pkt_state = INTEL_PT_STATE_TIP_PGD;
return intel_pt_walk_tip(decoder);
case INTEL_PT_TIP_PGE: {
decoder->pge = true;
if (decoder->packet.count == 0) {
intel_pt_log_at("Skipping zero TIP.PGE",
decoder->pos);
break;
}
intel_pt_set_ip(decoder);
decoder->state.from_ip = 0;
decoder->state.to_ip = decoder->ip;
return 0;
}
case INTEL_PT_OVF:
return intel_pt_overflow(decoder);
case INTEL_PT_TIP:
if (decoder->packet.count != 0)
intel_pt_set_last_ip(decoder);
decoder->pkt_state = INTEL_PT_STATE_TIP;
return intel_pt_walk_tip(decoder);
case INTEL_PT_FUP:
if (decoder->packet.count == 0) {
intel_pt_log_at("Skipping zero FUP",
decoder->pos);
no_tip = false;
break;
}
intel_pt_set_last_ip(decoder);
err = intel_pt_walk_fup(decoder);
if (err != -EAGAIN) {
if (err)
return err;
if (no_tip)
decoder->pkt_state =
INTEL_PT_STATE_FUP_NO_TIP;
else
decoder->pkt_state = INTEL_PT_STATE_FUP;
return 0;
}
if (no_tip) {
no_tip = false;
break;
}
return intel_pt_walk_fup_tip(decoder);
case INTEL_PT_TRACESTOP:
decoder->pge = false;
decoder->continuous_period = false;
intel_pt_clear_tx_flags(decoder);
decoder->have_tma = false;
break;
case INTEL_PT_PSB:
intel_pt_clear_stack(&decoder->stack);
err = intel_pt_walk_psbend(decoder);
if (err == -EAGAIN)
goto next;
if (err)
return err;
break;
case INTEL_PT_PIP:
decoder->cr3 = decoder->packet.payload & (BIT63 - 1);
break;
case INTEL_PT_MTC:
intel_pt_calc_mtc_timestamp(decoder);
if (decoder->period_type != INTEL_PT_PERIOD_MTC)
break;
if (!decoder->mtc_insn)
break;
decoder->mtc_insn = false;
if (!decoder->timestamp)
break;
decoder->state.type = INTEL_PT_INSTRUCTION;
decoder->state.from_ip = decoder->ip;
decoder->state.to_ip = 0;
decoder->mtc_insn = false;
return 0;
case INTEL_PT_TSC:
intel_pt_calc_tsc_timestamp(decoder);
break;
case INTEL_PT_TMA:
intel_pt_calc_tma(decoder);
break;
case INTEL_PT_CYC:
intel_pt_calc_cyc_timestamp(decoder);
break;
case INTEL_PT_CBR:
intel_pt_calc_cbr(decoder);
break;
case INTEL_PT_MODE_EXEC:
decoder->exec_mode = decoder->packet.payload;
break;
case INTEL_PT_MODE_TSX:
if (!decoder->pge) {
intel_pt_update_in_tx(decoder);
break;
}
err = intel_pt_mode_tsx(decoder, &no_tip);
if (err)
return err;
goto next;
case INTEL_PT_BAD:
return intel_pt_bug(decoder);
case INTEL_PT_PSBEND:
case INTEL_PT_VMCS:
case INTEL_PT_MNT:
case INTEL_PT_PAD:
break;
default:
return intel_pt_bug(decoder);
}
}
}
static inline bool intel_pt_have_ip(struct intel_pt_decoder *decoder)
{
return decoder->last_ip || decoder->packet.count == 0 ||
decoder->packet.count == 3 || decoder->packet.count == 6;
}
static int intel_pt_walk_psb(struct intel_pt_decoder *decoder)
{
int err;
while (1) {
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
switch (decoder->packet.type) {
case INTEL_PT_TIP_PGD:
decoder->continuous_period = false;
__fallthrough;
case INTEL_PT_TIP_PGE:
case INTEL_PT_TIP:
intel_pt_log("ERROR: Unexpected packet\n");
return -ENOENT;
case INTEL_PT_FUP:
decoder->pge = true;
if (intel_pt_have_ip(decoder)) {
uint64_t current_ip = decoder->ip;
intel_pt_set_ip(decoder);
if (current_ip)
intel_pt_log_to("Setting IP",
decoder->ip);
}
break;
case INTEL_PT_MTC:
intel_pt_calc_mtc_timestamp(decoder);
break;
case INTEL_PT_TSC:
intel_pt_calc_tsc_timestamp(decoder);
break;
case INTEL_PT_TMA:
intel_pt_calc_tma(decoder);
break;
case INTEL_PT_CYC:
intel_pt_calc_cyc_timestamp(decoder);
break;
case INTEL_PT_CBR:
intel_pt_calc_cbr(decoder);
break;
case INTEL_PT_PIP:
decoder->cr3 = decoder->packet.payload & (BIT63 - 1);
break;
case INTEL_PT_MODE_EXEC:
decoder->exec_mode = decoder->packet.payload;
break;
case INTEL_PT_MODE_TSX:
intel_pt_update_in_tx(decoder);
break;
case INTEL_PT_TRACESTOP:
decoder->pge = false;
decoder->continuous_period = false;
intel_pt_clear_tx_flags(decoder);
__fallthrough;
case INTEL_PT_TNT:
decoder->have_tma = false;
intel_pt_log("ERROR: Unexpected packet\n");
if (decoder->ip)
decoder->pkt_state = INTEL_PT_STATE_ERR4;
else
decoder->pkt_state = INTEL_PT_STATE_ERR3;
return -ENOENT;
case INTEL_PT_BAD:
return intel_pt_bug(decoder);
case INTEL_PT_OVF:
return intel_pt_overflow(decoder);
case INTEL_PT_PSBEND:
return 0;
case INTEL_PT_PSB:
case INTEL_PT_VMCS:
case INTEL_PT_MNT:
case INTEL_PT_PAD:
default:
break;
}
}
}
static int intel_pt_walk_to_ip(struct intel_pt_decoder *decoder)
{
int err;
while (1) {
err = intel_pt_get_next_packet(decoder);
if (err)
return err;
switch (decoder->packet.type) {
case INTEL_PT_TIP_PGD:
decoder->continuous_period = false;
__fallthrough;
case INTEL_PT_TIP_PGE:
case INTEL_PT_TIP:
decoder->pge = decoder->packet.type != INTEL_PT_TIP_PGD;
if (intel_pt_have_ip(decoder))
intel_pt_set_ip(decoder);
if (decoder->ip)
return 0;
break;
case INTEL_PT_FUP:
if (decoder->overflow) {
if (intel_pt_have_ip(decoder))
intel_pt_set_ip(decoder);
if (decoder->ip)
return 0;
}
if (decoder->packet.count)
intel_pt_set_last_ip(decoder);
break;
case INTEL_PT_MTC:
intel_pt_calc_mtc_timestamp(decoder);
break;
case INTEL_PT_TSC:
intel_pt_calc_tsc_timestamp(decoder);
break;
case INTEL_PT_TMA:
intel_pt_calc_tma(decoder);
break;
case INTEL_PT_CYC:
intel_pt_calc_cyc_timestamp(decoder);
break;
case INTEL_PT_CBR:
intel_pt_calc_cbr(decoder);
break;
case INTEL_PT_PIP:
decoder->cr3 = decoder->packet.payload & (BIT63 - 1);
break;
case INTEL_PT_MODE_EXEC:
decoder->exec_mode = decoder->packet.payload;
break;
case INTEL_PT_MODE_TSX:
intel_pt_update_in_tx(decoder);
break;
case INTEL_PT_OVF:
return intel_pt_overflow(decoder);
case INTEL_PT_BAD:
return intel_pt_bug(decoder);
case INTEL_PT_TRACESTOP:
decoder->pge = false;
decoder->continuous_period = false;
intel_pt_clear_tx_flags(decoder);
decoder->have_tma = false;
break;
case INTEL_PT_PSB:
err = intel_pt_walk_psb(decoder);
if (err)
return err;
if (decoder->ip) {
decoder->state.type = 0;
return 0;
}
break;
case INTEL_PT_TNT:
case INTEL_PT_PSBEND:
case INTEL_PT_VMCS:
case INTEL_PT_MNT:
case INTEL_PT_PAD:
default:
break;
}
}
}
static int intel_pt_sync_ip(struct intel_pt_decoder *decoder)
{
int err;
intel_pt_log("Scanning for full IP\n");
err = intel_pt_walk_to_ip(decoder);
if (err)
return err;
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
decoder->overflow = false;
decoder->state.from_ip = 0;
decoder->state.to_ip = decoder->ip;
intel_pt_log_to("Setting IP", decoder->ip);
return 0;
}
static int intel_pt_part_psb(struct intel_pt_decoder *decoder)
{
const unsigned char *end = decoder->buf + decoder->len;
size_t i;
for (i = INTEL_PT_PSB_LEN - 1; i; i--) {
if (i > decoder->len)
continue;
if (!memcmp(end - i, INTEL_PT_PSB_STR, i))
return i;
}
return 0;
}
static int intel_pt_rest_psb(struct intel_pt_decoder *decoder, int part_psb)
{
size_t rest_psb = INTEL_PT_PSB_LEN - part_psb;
const char *psb = INTEL_PT_PSB_STR;
if (rest_psb > decoder->len ||
memcmp(decoder->buf, psb + part_psb, rest_psb))
return 0;
return rest_psb;
}
static int intel_pt_get_split_psb(struct intel_pt_decoder *decoder,
int part_psb)
{
int rest_psb, ret;
decoder->pos += decoder->len;
decoder->len = 0;
ret = intel_pt_get_next_data(decoder);
if (ret)
return ret;
rest_psb = intel_pt_rest_psb(decoder, part_psb);
if (!rest_psb)
return 0;
decoder->pos -= part_psb;
decoder->next_buf = decoder->buf + rest_psb;
decoder->next_len = decoder->len - rest_psb;
memcpy(decoder->temp_buf, INTEL_PT_PSB_STR, INTEL_PT_PSB_LEN);
decoder->buf = decoder->temp_buf;
decoder->len = INTEL_PT_PSB_LEN;
return 0;
}
static int intel_pt_scan_for_psb(struct intel_pt_decoder *decoder)
{
unsigned char *next;
int ret;
intel_pt_log("Scanning for PSB\n");
while (1) {
if (!decoder->len) {
ret = intel_pt_get_next_data(decoder);
if (ret)
return ret;
}
next = memmem(decoder->buf, decoder->len, INTEL_PT_PSB_STR,
INTEL_PT_PSB_LEN);
if (!next) {
int part_psb;
part_psb = intel_pt_part_psb(decoder);
if (part_psb) {
ret = intel_pt_get_split_psb(decoder, part_psb);
if (ret)
return ret;
} else {
decoder->pos += decoder->len;
decoder->len = 0;
}
continue;
}
decoder->pkt_step = next - decoder->buf;
return intel_pt_get_next_packet(decoder);
}
}
static int intel_pt_sync(struct intel_pt_decoder *decoder)
{
int err;
decoder->pge = false;
decoder->continuous_period = false;
decoder->last_ip = 0;
decoder->ip = 0;
intel_pt_clear_stack(&decoder->stack);
err = intel_pt_scan_for_psb(decoder);
if (err)
return err;
decoder->pkt_state = INTEL_PT_STATE_NO_IP;
err = intel_pt_walk_psb(decoder);
if (err)
return err;
if (decoder->ip) {
decoder->state.type = 0;
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
} else {
return intel_pt_sync_ip(decoder);
}
return 0;
}
static uint64_t intel_pt_est_timestamp(struct intel_pt_decoder *decoder)
{
uint64_t est = decoder->timestamp_insn_cnt << 1;
if (!decoder->cbr || !decoder->max_non_turbo_ratio)
goto out;
est *= decoder->max_non_turbo_ratio;
est /= decoder->cbr;
out:
return decoder->timestamp + est;
}
const struct intel_pt_state *intel_pt_decode(struct intel_pt_decoder *decoder)
{
int err;
do {
decoder->state.type = INTEL_PT_BRANCH;
decoder->state.flags = 0;
switch (decoder->pkt_state) {
case INTEL_PT_STATE_NO_PSB:
err = intel_pt_sync(decoder);
break;
case INTEL_PT_STATE_NO_IP:
decoder->last_ip = 0;
case INTEL_PT_STATE_ERR_RESYNC:
err = intel_pt_sync_ip(decoder);
break;
case INTEL_PT_STATE_IN_SYNC:
err = intel_pt_walk_trace(decoder);
break;
case INTEL_PT_STATE_TNT:
err = intel_pt_walk_tnt(decoder);
if (err == -EAGAIN)
err = intel_pt_walk_trace(decoder);
break;
case INTEL_PT_STATE_TIP:
case INTEL_PT_STATE_TIP_PGD:
err = intel_pt_walk_tip(decoder);
break;
case INTEL_PT_STATE_FUP:
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
err = intel_pt_walk_fup(decoder);
if (err == -EAGAIN)
err = intel_pt_walk_fup_tip(decoder);
else if (!err)
decoder->pkt_state = INTEL_PT_STATE_FUP;
break;
case INTEL_PT_STATE_FUP_NO_TIP:
decoder->pkt_state = INTEL_PT_STATE_IN_SYNC;
err = intel_pt_walk_fup(decoder);
if (err == -EAGAIN)
err = intel_pt_walk_trace(decoder);
break;
default:
err = intel_pt_bug(decoder);
break;
}
} while (err == -ENOLINK);
decoder->state.err = err ? intel_pt_ext_err(err) : 0;
decoder->state.timestamp = decoder->timestamp;
decoder->state.est_timestamp = intel_pt_est_timestamp(decoder);
decoder->state.cr3 = decoder->cr3;
decoder->state.tot_insn_cnt = decoder->tot_insn_cnt;
if (err)
decoder->state.from_ip = decoder->ip;
return &decoder->state;
}
static bool intel_pt_at_psb(unsigned char *buf, size_t len)
{
if (len < INTEL_PT_PSB_LEN)
return false;
return memmem(buf, INTEL_PT_PSB_LEN, INTEL_PT_PSB_STR,
INTEL_PT_PSB_LEN);
}
static bool intel_pt_next_psb(unsigned char **buf, size_t *len)
{
unsigned char *next;
next = memmem(*buf, *len, INTEL_PT_PSB_STR, INTEL_PT_PSB_LEN);
if (next) {
*len -= next - *buf;
*buf = next;
return true;
}
return false;
}
static bool intel_pt_step_psb(unsigned char **buf, size_t *len)
{
unsigned char *next;
if (!*len)
return false;
next = memmem(*buf + 1, *len - 1, INTEL_PT_PSB_STR, INTEL_PT_PSB_LEN);
if (next) {
*len -= next - *buf;
*buf = next;
return true;
}
return false;
}
static unsigned char *intel_pt_last_psb(unsigned char *buf, size_t len)
{
const char *n = INTEL_PT_PSB_STR;
unsigned char *p;
size_t k;
if (len < INTEL_PT_PSB_LEN)
return NULL;
k = len - INTEL_PT_PSB_LEN + 1;
while (1) {
p = memrchr(buf, n[0], k);
if (!p)
return NULL;
if (!memcmp(p + 1, n + 1, INTEL_PT_PSB_LEN - 1))
return p;
k = p - buf;
if (!k)
return NULL;
}
}
static bool intel_pt_next_tsc(unsigned char *buf, size_t len, uint64_t *tsc)
{
struct intel_pt_pkt packet;
int ret;
while (len) {
ret = intel_pt_get_packet(buf, len, &packet);
if (ret <= 0)
return false;
if (packet.type == INTEL_PT_TSC) {
*tsc = packet.payload;
return true;
}
if (packet.type == INTEL_PT_PSBEND)
return false;
buf += ret;
len -= ret;
}
return false;
}
static int intel_pt_tsc_cmp(uint64_t tsc1, uint64_t tsc2)
{
const uint64_t halfway = (1ULL << 55);
if (tsc1 == tsc2)
return 0;
if (tsc1 < tsc2) {
if (tsc2 - tsc1 < halfway)
return -1;
else
return 1;
} else {
if (tsc1 - tsc2 < halfway)
return 1;
else
return -1;
}
}
static unsigned char *intel_pt_find_overlap_tsc(unsigned char *buf_a,
size_t len_a,
unsigned char *buf_b,
size_t len_b)
{
uint64_t tsc_a, tsc_b;
unsigned char *p;
size_t len;
p = intel_pt_last_psb(buf_a, len_a);
if (!p)
return buf_b;
len = len_a - (p - buf_a);
if (!intel_pt_next_tsc(p, len, &tsc_a)) {
len_a -= len;
p = intel_pt_last_psb(buf_a, len_a);
if (!p)
return buf_b;
len = len_a - (p - buf_a);
if (!intel_pt_next_tsc(p, len, &tsc_a))
return buf_b;
}
while (1) {
if (intel_pt_next_tsc(buf_b, len_b, &tsc_b) &&
intel_pt_tsc_cmp(tsc_a, tsc_b) < 0)
return buf_b;
if (!intel_pt_step_psb(&buf_b, &len_b))
return buf_b + len_b;
}
}
unsigned char *intel_pt_find_overlap(unsigned char *buf_a, size_t len_a,
unsigned char *buf_b, size_t len_b,
bool have_tsc)
{
unsigned char *found;
if (!intel_pt_next_psb(&buf_b, &len_b))
return buf_b + len_b;
if (!intel_pt_next_psb(&buf_a, &len_a))
return buf_b;
if (have_tsc) {
found = intel_pt_find_overlap_tsc(buf_a, len_a, buf_b, len_b);
if (found)
return found;
}
while (len_b < len_a) {
if (!intel_pt_step_psb(&buf_a, &len_a))
return buf_b;
}
if (len_b > len_a) {
while (!intel_pt_at_psb(buf_b + len_a, len_b - len_a)) {
if (!intel_pt_step_psb(&buf_a, &len_a))
return buf_b;
}
}
while (1) {
found = memmem(buf_a, len_a, buf_b, len_a);
if (found)
return buf_b + len_a;
if (!intel_pt_step_psb(&buf_a, &len_a))
return buf_b;
while (!intel_pt_at_psb(buf_b + len_a, len_b - len_a)) {
if (!intel_pt_step_psb(&buf_a, &len_a))
return buf_b;
}
}
}
