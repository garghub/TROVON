static inline void lms_adapt_bg(struct oslec_state *ec, int clean, int shift)
{
int i;
int offset1;
int offset2;
int factor;
int exp;
int16_t *phist;
int n;
if (shift > 0)
factor = clean << shift;
else
factor = clean >> -shift;
offset2 = ec->curr_pos;
offset1 = ec->taps - offset2;
phist = &ec->fir_state_bg.history[offset2];
n = ec->taps;
for (i = 0; i < n; i++) {
exp = *phist++ * factor;
ec->fir_taps16[1][i] += (int16_t) ((exp + (1 << 14)) >> 15);
}
}
static inline void lms_adapt_bg(struct oslec_state *ec, int clean, int shift)
{
int i;
int offset1;
int offset2;
int factor;
int exp;
if (shift > 0)
factor = clean << shift;
else
factor = clean >> -shift;
offset2 = ec->curr_pos;
offset1 = ec->taps - offset2;
for (i = ec->taps - 1; i >= offset1; i--) {
exp = (ec->fir_state_bg.history[i - offset1] * factor);
ec->fir_taps16[1][i] += (int16_t) ((exp + (1 << 14)) >> 15);
}
for (; i >= 0; i--) {
exp = (ec->fir_state_bg.history[i + offset2] * factor);
ec->fir_taps16[1][i] += (int16_t) ((exp + (1 << 14)) >> 15);
}
}
static inline int top_bit(unsigned int bits)
{
if (bits == 0)
return -1;
else
return (int)fls((int32_t) bits) - 1;
}
struct oslec_state *oslec_create(int len, int adaption_mode)
{
struct oslec_state *ec;
int i;
const int16_t *history;
ec = kzalloc(sizeof(*ec), GFP_KERNEL);
if (!ec)
return NULL;
ec->taps = len;
ec->log2taps = top_bit(len);
ec->curr_pos = ec->taps - 1;
ec->fir_taps16[0] =
kcalloc(ec->taps, sizeof(int16_t), GFP_KERNEL);
if (!ec->fir_taps16[0])
goto error_oom_0;
ec->fir_taps16[1] =
kcalloc(ec->taps, sizeof(int16_t), GFP_KERNEL);
if (!ec->fir_taps16[1])
goto error_oom_1;
history = fir16_create(&ec->fir_state, ec->fir_taps16[0], ec->taps);
if (!history)
goto error_state;
history = fir16_create(&ec->fir_state_bg, ec->fir_taps16[1], ec->taps);
if (!history)
goto error_state_bg;
for (i = 0; i < 5; i++)
ec->xvtx[i] = ec->yvtx[i] = ec->xvrx[i] = ec->yvrx[i] = 0;
ec->cng_level = 1000;
oslec_adaption_mode(ec, adaption_mode);
ec->snapshot = kcalloc(ec->taps, sizeof(int16_t), GFP_KERNEL);
if (!ec->snapshot)
goto error_snap;
ec->cond_met = 0;
ec->Pstates = 0;
ec->Ltxacc = ec->Lrxacc = ec->Lcleanacc = ec->Lclean_bgacc = 0;
ec->Ltx = ec->Lrx = ec->Lclean = ec->Lclean_bg = 0;
ec->tx_1 = ec->tx_2 = ec->rx_1 = ec->rx_2 = 0;
ec->Lbgn = ec->Lbgn_acc = 0;
ec->Lbgn_upper = 200;
ec->Lbgn_upper_acc = ec->Lbgn_upper << 13;
return ec;
error_snap:
fir16_free(&ec->fir_state_bg);
error_state_bg:
fir16_free(&ec->fir_state);
error_state:
kfree(ec->fir_taps16[1]);
error_oom_1:
kfree(ec->fir_taps16[0]);
error_oom_0:
kfree(ec);
return NULL;
}
void oslec_free(struct oslec_state *ec)
{
int i;
fir16_free(&ec->fir_state);
fir16_free(&ec->fir_state_bg);
for (i = 0; i < 2; i++)
kfree(ec->fir_taps16[i]);
kfree(ec->snapshot);
kfree(ec);
}
void oslec_adaption_mode(struct oslec_state *ec, int adaption_mode)
{
ec->adaption_mode = adaption_mode;
}
void oslec_flush(struct oslec_state *ec)
{
int i;
ec->Ltxacc = ec->Lrxacc = ec->Lcleanacc = ec->Lclean_bgacc = 0;
ec->Ltx = ec->Lrx = ec->Lclean = ec->Lclean_bg = 0;
ec->tx_1 = ec->tx_2 = ec->rx_1 = ec->rx_2 = 0;
ec->Lbgn = ec->Lbgn_acc = 0;
ec->Lbgn_upper = 200;
ec->Lbgn_upper_acc = ec->Lbgn_upper << 13;
ec->nonupdate_dwell = 0;
fir16_flush(&ec->fir_state);
fir16_flush(&ec->fir_state_bg);
ec->fir_state.curr_pos = ec->taps - 1;
ec->fir_state_bg.curr_pos = ec->taps - 1;
for (i = 0; i < 2; i++)
memset(ec->fir_taps16[i], 0, ec->taps * sizeof(int16_t));
ec->curr_pos = ec->taps - 1;
ec->Pstates = 0;
}
void oslec_snapshot(struct oslec_state *ec)
{
memcpy(ec->snapshot, ec->fir_taps16[0], ec->taps * sizeof(int16_t));
}
int16_t oslec_update(struct oslec_state *ec, int16_t tx, int16_t rx)
{
int32_t echo_value;
int clean_bg;
int tmp;
int tmp1;
ec->tx = tx;
ec->rx = rx;
tx >>= 1;
rx >>= 1;
if (ec->adaption_mode & ECHO_CAN_USE_RX_HPF) {
tmp = rx << 15;
tmp -= (tmp >> 4);
ec->rx_1 += -(ec->rx_1 >> DC_LOG2BETA) + tmp - ec->rx_2;
tmp1 = ec->rx_1 >> 15;
if (tmp1 > 16383)
tmp1 = 16383;
if (tmp1 < -16383)
tmp1 = -16383;
rx = tmp1;
ec->rx_2 = tmp;
}
{
int new, old;
new = (int)tx * (int)tx;
old = (int)ec->fir_state.history[ec->fir_state.curr_pos] *
(int)ec->fir_state.history[ec->fir_state.curr_pos];
ec->Pstates +=
((new - old) + (1 << (ec->log2taps - 1))) >> ec->log2taps;
if (ec->Pstates < 0)
ec->Pstates = 0;
}
ec->Ltxacc += abs(tx) - ec->Ltx;
ec->Ltx = (ec->Ltxacc + (1 << 4)) >> 5;
ec->Lrxacc += abs(rx) - ec->Lrx;
ec->Lrx = (ec->Lrxacc + (1 << 4)) >> 5;
ec->fir_state.coeffs = ec->fir_taps16[0];
echo_value = fir16(&ec->fir_state, tx);
ec->clean = rx - echo_value;
ec->Lcleanacc += abs(ec->clean) - ec->Lclean;
ec->Lclean = (ec->Lcleanacc + (1 << 4)) >> 5;
echo_value = fir16(&ec->fir_state_bg, tx);
clean_bg = rx - echo_value;
ec->Lclean_bgacc += abs(clean_bg) - ec->Lclean_bg;
ec->Lclean_bg = (ec->Lclean_bgacc + (1 << 4)) >> 5;
ec->factor = 0;
ec->shift = 0;
if ((ec->nonupdate_dwell == 0)) {
int P, logP, shift;
P = MIN_TX_POWER_FOR_ADAPTION + ec->Pstates;
logP = top_bit(P) + ec->log2taps;
shift = 30 - 2 - logP;
ec->shift = shift;
lms_adapt_bg(ec, clean_bg, shift);
}
ec->adapt = 0;
if ((ec->Lrx > MIN_RX_POWER_FOR_ADAPTION) && (ec->Lrx > ec->Ltx))
ec->nonupdate_dwell = DTD_HANGOVER;
if (ec->nonupdate_dwell)
ec->nonupdate_dwell--;
if ((ec->adaption_mode & ECHO_CAN_USE_ADAPTION) &&
(ec->nonupdate_dwell == 0) &&
(8 * ec->Lclean_bg < 7 * ec->Lclean) &&
(8 * ec->Lclean_bg < ec->Ltx)) {
if (ec->cond_met == 6) {
ec->adapt = 1;
memcpy(ec->fir_taps16[0], ec->fir_taps16[1],
ec->taps * sizeof(int16_t));
} else
ec->cond_met++;
} else
ec->cond_met = 0;
ec->clean_nlp = ec->clean;
if (ec->adaption_mode & ECHO_CAN_USE_NLP) {
if ((16 * ec->Lclean < ec->Ltx)) {
if (ec->adaption_mode & ECHO_CAN_USE_CNG) {
ec->cng_level = ec->Lbgn;
ec->cng_rndnum =
1664525U * ec->cng_rndnum + 1013904223U;
ec->cng_filter =
((ec->cng_rndnum & 0xFFFF) - 32768 +
5 * ec->cng_filter) >> 3;
ec->clean_nlp =
(ec->cng_filter * ec->cng_level * 8) >> 14;
} else if (ec->adaption_mode & ECHO_CAN_USE_CLIP) {
if (ec->clean_nlp > ec->Lbgn)
ec->clean_nlp = ec->Lbgn;
if (ec->clean_nlp < -ec->Lbgn)
ec->clean_nlp = -ec->Lbgn;
} else {
ec->clean_nlp = 0;
}
} else {
if (ec->Lclean < 40) {
ec->Lbgn_acc += abs(ec->clean) - ec->Lbgn;
ec->Lbgn = (ec->Lbgn_acc + (1 << 11)) >> 12;
}
}
}
if (ec->curr_pos <= 0)
ec->curr_pos = ec->taps;
ec->curr_pos--;
if (ec->adaption_mode & ECHO_CAN_DISABLE)
ec->clean_nlp = rx;
return (int16_t) ec->clean_nlp << 1;
}
int16_t oslec_hpf_tx(struct oslec_state *ec, int16_t tx)
{
int tmp;
int tmp1;
if (ec->adaption_mode & ECHO_CAN_USE_TX_HPF) {
tmp = tx << 15;
tmp -= (tmp >> 4);
ec->tx_1 += -(ec->tx_1 >> DC_LOG2BETA) + tmp - ec->tx_2;
tmp1 = ec->tx_1 >> 15;
if (tmp1 > 32767)
tmp1 = 32767;
if (tmp1 < -32767)
tmp1 = -32767;
tx = tmp1;
ec->tx_2 = tmp;
}
return tx;
}
