int altera_jinit(struct altera_state *astate)
{
struct altera_jtag *js = &astate->js;
js->jtag_state = ILLEGAL_JTAG_STATE;
js->drstop_state = IDLE;
js->irstop_state = IDLE;
js->dr_pre = 0;
js->dr_post = 0;
js->ir_pre = 0;
js->ir_post = 0;
js->dr_length = 0;
js->ir_length = 0;
js->dr_pre_data = NULL;
js->dr_post_data = NULL;
js->ir_pre_data = NULL;
js->ir_post_data = NULL;
js->dr_buffer = NULL;
js->ir_buffer = NULL;
return 0;
}
int altera_set_drstop(struct altera_jtag *js, enum altera_jtag_state state)
{
js->drstop_state = state;
return 0;
}
int altera_set_irstop(struct altera_jtag *js, enum altera_jtag_state state)
{
js->irstop_state = state;
return 0;
}
int altera_set_dr_pre(struct altera_jtag *js,
u32 count, u32 start_index,
u8 *preamble_data)
{
int status = 0;
u32 i;
u32 j;
if (count > js->dr_pre) {
kfree(js->dr_pre_data);
js->dr_pre_data = (u8 *)alt_malloc((count + 7) >> 3);
if (js->dr_pre_data == NULL)
status = -ENOMEM;
else
js->dr_pre = count;
} else
js->dr_pre = count;
if (status == 0) {
for (i = 0; i < count; ++i) {
j = i + start_index;
if (preamble_data == NULL)
js->dr_pre_data[i >> 3] |= (1 << (i & 7));
else {
if (preamble_data[j >> 3] & (1 << (j & 7)))
js->dr_pre_data[i >> 3] |=
(1 << (i & 7));
else
js->dr_pre_data[i >> 3] &=
~(u32)(1 << (i & 7));
}
}
}
return status;
}
int altera_set_ir_pre(struct altera_jtag *js, u32 count, u32 start_index,
u8 *preamble_data)
{
int status = 0;
u32 i;
u32 j;
if (count > js->ir_pre) {
kfree(js->ir_pre_data);
js->ir_pre_data = (u8 *)alt_malloc((count + 7) >> 3);
if (js->ir_pre_data == NULL)
status = -ENOMEM;
else
js->ir_pre = count;
} else
js->ir_pre = count;
if (status == 0) {
for (i = 0; i < count; ++i) {
j = i + start_index;
if (preamble_data == NULL)
js->ir_pre_data[i >> 3] |= (1 << (i & 7));
else {
if (preamble_data[j >> 3] & (1 << (j & 7)))
js->ir_pre_data[i >> 3] |=
(1 << (i & 7));
else
js->ir_pre_data[i >> 3] &=
~(u32)(1 << (i & 7));
}
}
}
return status;
}
int altera_set_dr_post(struct altera_jtag *js, u32 count, u32 start_index,
u8 *postamble_data)
{
int status = 0;
u32 i;
u32 j;
if (count > js->dr_post) {
kfree(js->dr_post_data);
js->dr_post_data = (u8 *)alt_malloc((count + 7) >> 3);
if (js->dr_post_data == NULL)
status = -ENOMEM;
else
js->dr_post = count;
} else
js->dr_post = count;
if (status == 0) {
for (i = 0; i < count; ++i) {
j = i + start_index;
if (postamble_data == NULL)
js->dr_post_data[i >> 3] |= (1 << (i & 7));
else {
if (postamble_data[j >> 3] & (1 << (j & 7)))
js->dr_post_data[i >> 3] |=
(1 << (i & 7));
else
js->dr_post_data[i >> 3] &=
~(u32)(1 << (i & 7));
}
}
}
return status;
}
int altera_set_ir_post(struct altera_jtag *js, u32 count, u32 start_index,
u8 *postamble_data)
{
int status = 0;
u32 i;
u32 j;
if (count > js->ir_post) {
kfree(js->ir_post_data);
js->ir_post_data = (u8 *)alt_malloc((count + 7) >> 3);
if (js->ir_post_data == NULL)
status = -ENOMEM;
else
js->ir_post = count;
} else
js->ir_post = count;
if (status != 0)
return status;
for (i = 0; i < count; ++i) {
j = i + start_index;
if (postamble_data == NULL)
js->ir_post_data[i >> 3] |= (1 << (i & 7));
else {
if (postamble_data[j >> 3] & (1 << (j & 7)))
js->ir_post_data[i >> 3] |= (1 << (i & 7));
else
js->ir_post_data[i >> 3] &=
~(u32)(1 << (i & 7));
}
}
return status;
}
static void altera_jreset_idle(struct altera_state *astate)
{
struct altera_jtag *js = &astate->js;
int i;
for (i = 0; i < 5; ++i)
alt_jtag_io(TMS_HIGH, TDI_LOW, IGNORE_TDO);
alt_jtag_io(TMS_LOW, TDI_LOW, IGNORE_TDO);
js->jtag_state = IDLE;
}
int altera_goto_jstate(struct altera_state *astate,
enum altera_jtag_state state)
{
struct altera_jtag *js = &astate->js;
int tms;
int count = 0;
int status = 0;
if (js->jtag_state == ILLEGAL_JTAG_STATE)
altera_jreset_idle(astate);
if (js->jtag_state == state) {
if ((state == IDLE) || (state == DRSHIFT) ||
(state == DRPAUSE) || (state == IRSHIFT) ||
(state == IRPAUSE)) {
alt_jtag_io(TMS_LOW, TDI_LOW, IGNORE_TDO);
} else if (state == RESET)
alt_jtag_io(TMS_HIGH, TDI_LOW, IGNORE_TDO);
} else {
while ((js->jtag_state != state) && (count < 9)) {
tms = (altera_jtag_path_map[js->jtag_state] &
(1 << state))
? TMS_HIGH : TMS_LOW;
alt_jtag_io(tms, TDI_LOW, IGNORE_TDO);
if (tms)
js->jtag_state =
altera_transitions[js->jtag_state].tms_high;
else
js->jtag_state =
altera_transitions[js->jtag_state].tms_low;
++count;
}
}
if (js->jtag_state != state)
status = -EREMOTEIO;
return status;
}
int altera_wait_cycles(struct altera_state *astate,
s32 cycles,
enum altera_jtag_state wait_state)
{
struct altera_jtag *js = &astate->js;
int tms;
s32 count;
int status = 0;
if (js->jtag_state != wait_state)
status = altera_goto_jstate(astate, wait_state);
if (status == 0) {
tms = (wait_state == RESET) ? TMS_HIGH : TMS_LOW;
for (count = 0L; count < cycles; count++)
alt_jtag_io(tms, TDI_LOW, IGNORE_TDO);
}
return status;
}
int altera_wait_msecs(struct altera_state *astate,
s32 microseconds, enum altera_jtag_state wait_state)
{
struct altera_jtag *js = &astate->js;
int status = 0;
if ((js->jtag_state != ILLEGAL_JTAG_STATE) &&
(js->jtag_state != wait_state))
status = altera_goto_jstate(astate, wait_state);
if (status == 0)
udelay(microseconds);
return status;
}
static void altera_concatenate_data(u8 *buffer,
u8 *preamble_data,
u32 preamble_count,
u8 *target_data,
u32 start_index,
u32 target_count,
u8 *postamble_data,
u32 postamble_count)
{
u32 i, j, k;
for (i = 0L; i < preamble_count; ++i) {
if (preamble_data[i >> 3L] & (1L << (i & 7L)))
buffer[i >> 3L] |= (1L << (i & 7L));
else
buffer[i >> 3L] &= ~(u32)(1L << (i & 7L));
}
j = start_index;
k = preamble_count + target_count;
for (; i < k; ++i, ++j) {
if (target_data[j >> 3L] & (1L << (j & 7L)))
buffer[i >> 3L] |= (1L << (i & 7L));
else
buffer[i >> 3L] &= ~(u32)(1L << (i & 7L));
}
j = 0L;
k = preamble_count + target_count + postamble_count;
for (; i < k; ++i, ++j) {
if (postamble_data[j >> 3L] & (1L << (j & 7L)))
buffer[i >> 3L] |= (1L << (i & 7L));
else
buffer[i >> 3L] &= ~(u32)(1L << (i & 7L));
}
}
static int alt_jtag_drscan(struct altera_state *astate,
int start_state,
int count,
u8 *tdi,
u8 *tdo)
{
int i = 0;
int tdo_bit = 0;
int status = 1;
switch (start_state) {
case 0:
alt_jtag_io(1, 0, 0);
alt_jtag_io(0, 0, 0);
alt_jtag_io(0, 0, 0);
break;
case 1:
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(0, 0, 0);
alt_jtag_io(0, 0, 0);
break;
case 2:
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(0, 0, 0);
alt_jtag_io(0, 0, 0);
break;
default:
status = 0;
}
if (status) {
for (i = 0; i < count; i++) {
tdo_bit = alt_jtag_io(
(i == count - 1),
tdi[i >> 3] & (1 << (i & 7)),
(tdo != NULL));
if (tdo != NULL) {
if (tdo_bit)
tdo[i >> 3] |= (1 << (i & 7));
else
tdo[i >> 3] &= ~(u32)(1 << (i & 7));
}
}
alt_jtag_io(0, 0, 0);
}
return status;
}
static int alt_jtag_irscan(struct altera_state *astate,
int start_state,
int count,
u8 *tdi,
u8 *tdo)
{
int i = 0;
int tdo_bit = 0;
int status = 1;
switch (start_state) {
case 0:
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(0, 0, 0);
alt_jtag_io(0, 0, 0);
break;
case 1:
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(0, 0, 0);
alt_jtag_io(0, 0, 0);
break;
case 2:
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(1, 0, 0);
alt_jtag_io(0, 0, 0);
alt_jtag_io(0, 0, 0);
break;
default:
status = 0;
}
if (status) {
for (i = 0; i < count; i++) {
tdo_bit = alt_jtag_io(
(i == count - 1),
tdi[i >> 3] & (1 << (i & 7)),
(tdo != NULL));
if (tdo != NULL) {
if (tdo_bit)
tdo[i >> 3] |= (1 << (i & 7));
else
tdo[i >> 3] &= ~(u32)(1 << (i & 7));
}
}
alt_jtag_io(0, 0, 0);
}
return status;
}
static void altera_extract_target_data(u8 *buffer,
u8 *target_data,
u32 start_index,
u32 preamble_count,
u32 target_count)
{
u32 i;
u32 j;
u32 k;
j = preamble_count;
k = start_index + target_count;
for (i = start_index; i < k; ++i, ++j) {
if (buffer[j >> 3] & (1 << (j & 7)))
target_data[i >> 3] |= (1 << (i & 7));
else
target_data[i >> 3] &= ~(u32)(1 << (i & 7));
}
}
int altera_irscan(struct altera_state *astate,
u32 count,
u8 *tdi_data,
u32 start_index)
{
struct altera_jtag *js = &astate->js;
int start_code = 0;
u32 alloc_chars = 0;
u32 shift_count = js->ir_pre + count + js->ir_post;
int status = 0;
enum altera_jtag_state start_state = ILLEGAL_JTAG_STATE;
switch (js->jtag_state) {
case ILLEGAL_JTAG_STATE:
case RESET:
case IDLE:
start_code = 0;
start_state = IDLE;
break;
case DRSELECT:
case DRCAPTURE:
case DRSHIFT:
case DREXIT1:
case DRPAUSE:
case DREXIT2:
case DRUPDATE:
start_code = 1;
start_state = DRPAUSE;
break;
case IRSELECT:
case IRCAPTURE:
case IRSHIFT:
case IREXIT1:
case IRPAUSE:
case IREXIT2:
case IRUPDATE:
start_code = 2;
start_state = IRPAUSE;
break;
default:
status = -EREMOTEIO;
break;
}
if (status == 0)
if (js->jtag_state != start_state)
status = altera_goto_jstate(astate, start_state);
if (status == 0) {
if (shift_count > js->ir_length) {
alloc_chars = (shift_count + 7) >> 3;
kfree(js->ir_buffer);
js->ir_buffer = (u8 *)alt_malloc(alloc_chars);
if (js->ir_buffer == NULL)
status = -ENOMEM;
else
js->ir_length = alloc_chars * 8;
}
}
if (status == 0) {
altera_concatenate_data(js->ir_buffer,
js->ir_pre_data,
js->ir_pre,
tdi_data,
start_index,
count,
js->ir_post_data,
js->ir_post);
alt_jtag_irscan(astate,
start_code,
shift_count,
js->ir_buffer,
NULL);
js->jtag_state = IRPAUSE;
}
if (status == 0)
if (js->irstop_state != IRPAUSE)
status = altera_goto_jstate(astate, js->irstop_state);
return status;
}
int altera_swap_ir(struct altera_state *astate,
u32 count,
u8 *in_data,
u32 in_index,
u8 *out_data,
u32 out_index)
{
struct altera_jtag *js = &astate->js;
int start_code = 0;
u32 alloc_chars = 0;
u32 shift_count = js->ir_pre + count + js->ir_post;
int status = 0;
enum altera_jtag_state start_state = ILLEGAL_JTAG_STATE;
switch (js->jtag_state) {
case ILLEGAL_JTAG_STATE:
case RESET:
case IDLE:
start_code = 0;
start_state = IDLE;
break;
case DRSELECT:
case DRCAPTURE:
case DRSHIFT:
case DREXIT1:
case DRPAUSE:
case DREXIT2:
case DRUPDATE:
start_code = 1;
start_state = DRPAUSE;
break;
case IRSELECT:
case IRCAPTURE:
case IRSHIFT:
case IREXIT1:
case IRPAUSE:
case IREXIT2:
case IRUPDATE:
start_code = 2;
start_state = IRPAUSE;
break;
default:
status = -EREMOTEIO;
break;
}
if (status == 0)
if (js->jtag_state != start_state)
status = altera_goto_jstate(astate, start_state);
if (status == 0) {
if (shift_count > js->ir_length) {
alloc_chars = (shift_count + 7) >> 3;
kfree(js->ir_buffer);
js->ir_buffer = (u8 *)alt_malloc(alloc_chars);
if (js->ir_buffer == NULL)
status = -ENOMEM;
else
js->ir_length = alloc_chars * 8;
}
}
if (status == 0) {
altera_concatenate_data(js->ir_buffer,
js->ir_pre_data,
js->ir_pre,
in_data,
in_index,
count,
js->ir_post_data,
js->ir_post);
alt_jtag_irscan(astate,
start_code,
shift_count,
js->ir_buffer,
js->ir_buffer);
js->jtag_state = IRPAUSE;
}
if (status == 0)
if (js->irstop_state != IRPAUSE)
status = altera_goto_jstate(astate, js->irstop_state);
if (status == 0)
altera_extract_target_data(js->ir_buffer,
out_data, out_index,
js->ir_pre, count);
return status;
}
int altera_drscan(struct altera_state *astate,
u32 count,
u8 *tdi_data,
u32 start_index)
{
struct altera_jtag *js = &astate->js;
int start_code = 0;
u32 alloc_chars = 0;
u32 shift_count = js->dr_pre + count + js->dr_post;
int status = 0;
enum altera_jtag_state start_state = ILLEGAL_JTAG_STATE;
switch (js->jtag_state) {
case ILLEGAL_JTAG_STATE:
case RESET:
case IDLE:
start_code = 0;
start_state = IDLE;
break;
case DRSELECT:
case DRCAPTURE:
case DRSHIFT:
case DREXIT1:
case DRPAUSE:
case DREXIT2:
case DRUPDATE:
start_code = 1;
start_state = DRPAUSE;
break;
case IRSELECT:
case IRCAPTURE:
case IRSHIFT:
case IREXIT1:
case IRPAUSE:
case IREXIT2:
case IRUPDATE:
start_code = 2;
start_state = IRPAUSE;
break;
default:
status = -EREMOTEIO;
break;
}
if (status == 0)
if (js->jtag_state != start_state)
status = altera_goto_jstate(astate, start_state);
if (status == 0) {
if (shift_count > js->dr_length) {
alloc_chars = (shift_count + 7) >> 3;
kfree(js->dr_buffer);
js->dr_buffer = (u8 *)alt_malloc(alloc_chars);
if (js->dr_buffer == NULL)
status = -ENOMEM;
else
js->dr_length = alloc_chars * 8;
}
}
if (status == 0) {
altera_concatenate_data(js->dr_buffer,
js->dr_pre_data,
js->dr_pre,
tdi_data,
start_index,
count,
js->dr_post_data,
js->dr_post);
alt_jtag_drscan(astate, start_code, shift_count,
js->dr_buffer, NULL);
js->jtag_state = DRPAUSE;
}
if (status == 0)
if (js->drstop_state != DRPAUSE)
status = altera_goto_jstate(astate, js->drstop_state);
return status;
}
int altera_swap_dr(struct altera_state *astate, u32 count,
u8 *in_data, u32 in_index,
u8 *out_data, u32 out_index)
{
struct altera_jtag *js = &astate->js;
int start_code = 0;
u32 alloc_chars = 0;
u32 shift_count = js->dr_pre + count + js->dr_post;
int status = 0;
enum altera_jtag_state start_state = ILLEGAL_JTAG_STATE;
switch (js->jtag_state) {
case ILLEGAL_JTAG_STATE:
case RESET:
case IDLE:
start_code = 0;
start_state = IDLE;
break;
case DRSELECT:
case DRCAPTURE:
case DRSHIFT:
case DREXIT1:
case DRPAUSE:
case DREXIT2:
case DRUPDATE:
start_code = 1;
start_state = DRPAUSE;
break;
case IRSELECT:
case IRCAPTURE:
case IRSHIFT:
case IREXIT1:
case IRPAUSE:
case IREXIT2:
case IRUPDATE:
start_code = 2;
start_state = IRPAUSE;
break;
default:
status = -EREMOTEIO;
break;
}
if (status == 0)
if (js->jtag_state != start_state)
status = altera_goto_jstate(astate, start_state);
if (status == 0) {
if (shift_count > js->dr_length) {
alloc_chars = (shift_count + 7) >> 3;
kfree(js->dr_buffer);
js->dr_buffer = (u8 *)alt_malloc(alloc_chars);
if (js->dr_buffer == NULL)
status = -ENOMEM;
else
js->dr_length = alloc_chars * 8;
}
}
if (status == 0) {
altera_concatenate_data(js->dr_buffer,
js->dr_pre_data,
js->dr_pre,
in_data,
in_index,
count,
js->dr_post_data,
js->dr_post);
alt_jtag_drscan(astate,
start_code,
shift_count,
js->dr_buffer,
js->dr_buffer);
js->jtag_state = DRPAUSE;
}
if (status == 0)
if (js->drstop_state != DRPAUSE)
status = altera_goto_jstate(astate, js->drstop_state);
if (status == 0)
altera_extract_target_data(js->dr_buffer,
out_data,
out_index,
js->dr_pre,
count);
return status;
}
void altera_free_buffers(struct altera_state *astate)
{
struct altera_jtag *js = &astate->js;
if (js->jtag_state != ILLEGAL_JTAG_STATE)
altera_jreset_idle(astate);
kfree(js->dr_pre_data);
js->dr_pre_data = NULL;
kfree(js->dr_post_data);
js->dr_post_data = NULL;
kfree(js->dr_buffer);
js->dr_buffer = NULL;
kfree(js->ir_pre_data);
js->ir_pre_data = NULL;
kfree(js->ir_post_data);
js->ir_post_data = NULL;
kfree(js->ir_buffer);
js->ir_buffer = NULL;
}
