static void capidtmf_goertzel_loop (long *buffer, long *coeffs, short *sample, long count)
{
int i, j;
long c, d, q0, q1, q2;
for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT - 1; i++)
{
q1 = buffer[i];
q2 = buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
d = coeffs[i] >> 1;
c = d << 1;
if (c >= 0)
{
for (j = 0; j < count; j++)
{
q0 = sample[j] - q2 + (c * (q1 >> 16)) + (((dword)(((dword) d) * ((dword)(q1 & 0xffff)))) >> 15);
q2 = q1;
q1 = q0;
}
}
else
{
c = -c;
d = -d;
for (j = 0; j < count; j++)
{
q0 = sample[j] - q2 - ((c * (q1 >> 16)) + (((dword)(((dword) d) * ((dword)(q1 & 0xffff)))) >> 15));
q2 = q1;
q1 = q0;
}
}
buffer[i] = q1;
buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT] = q2;
}
q1 = buffer[i];
q2 = buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
c = (coeffs[i] >> 1) << 1;
if (c >= 0)
{
for (j = 0; j < count; j++)
{
q0 = sample[j] - q2 + (c * (q1 >> 16)) + (((dword)(((dword)(c >> 1)) * ((dword)(q1 & 0xffff)))) >> 15);
q2 = q1;
q1 = q0;
c -= CAPIDTMF_RECV_FUNDAMENTAL_DECREMENT;
}
}
else
{
c = -c;
for (j = 0; j < count; j++)
{
q0 = sample[j] - q2 - ((c * (q1 >> 16)) + (((dword)(((dword)(c >> 1)) * ((dword)(q1 & 0xffff)))) >> 15));
q2 = q1;
q1 = q0;
c += CAPIDTMF_RECV_FUNDAMENTAL_DECREMENT;
}
}
coeffs[i] = c;
buffer[i] = q1;
buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT] = q2;
}
static void capidtmf_goertzel_result (long *buffer, long *coeffs)
{
int i;
long d, e, q1, q2, lo, mid, hi;
dword k;
for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
{
q1 = buffer[i];
q2 = buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
d = coeffs[i] >> 1;
if (d >= 0)
d = ((d << 1) * (-q1 >> 16)) + (((dword)(((dword) d) * ((dword)(-q1 & 0xffff)))) >> 15);
else
d = ((-d << 1) * (-q1 >> 16)) + (((dword)(((dword) -d) * ((dword)(-q1 & 0xffff)))) >> 15);
e = (q2 >= 0) ? q2 : -q2;
if (d >= 0)
{
k = ((dword)(d & 0xffff)) * ((dword)(e & 0xffff));
lo = k & 0xffff;
mid = k >> 16;
k = ((dword)(d >> 16)) * ((dword)(e & 0xffff));
mid += k & 0xffff;
hi = k >> 16;
k = ((dword)(d & 0xffff)) * ((dword)(e >> 16));
mid += k & 0xffff;
hi += k >> 16;
hi += ((dword)(d >> 16)) * ((dword)(e >> 16));
}
else
{
d = -d;
k = ((dword)(d & 0xffff)) * ((dword)(e & 0xffff));
lo = -((long)(k & 0xffff));
mid = -((long)(k >> 16));
k = ((dword)(d >> 16)) * ((dword)(e & 0xffff));
mid -= k & 0xffff;
hi = -((long)(k >> 16));
k = ((dword)(d & 0xffff)) * ((dword)(e >> 16));
mid -= k & 0xffff;
hi -= k >> 16;
hi -= ((dword)(d >> 16)) * ((dword)(e >> 16));
}
if (q2 < 0)
{
lo = -lo;
mid = -mid;
hi = -hi;
}
d = (q1 >= 0) ? q1 : -q1;
k = ((dword)(d & 0xffff)) * ((dword)(d & 0xffff));
lo += k & 0xffff;
mid += k >> 16;
k = ((dword)(d >> 16)) * ((dword)(d & 0xffff));
mid += (k & 0xffff) << 1;
hi += (k >> 16) << 1;
hi += ((dword)(d >> 16)) * ((dword)(d >> 16));
d = (q2 >= 0) ? q2 : -q2;
k = ((dword)(d & 0xffff)) * ((dword)(d & 0xffff));
lo += k & 0xffff;
mid += k >> 16;
k = ((dword)(d >> 16)) * ((dword)(d & 0xffff));
mid += (k & 0xffff) << 1;
hi += (k >> 16) << 1;
hi += ((dword)(d >> 16)) * ((dword)(d >> 16));
mid += lo >> 16;
hi += mid >> 16;
buffer[i] = (lo & 0xffff) | (mid << 16);
buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT] = hi;
}
}
static void capidtmf_recv_init (t_capidtmf_state *p_state)
{
p_state->recv.min_gap_duration = 1;
p_state->recv.min_digit_duration = 1;
p_state->recv.cycle_counter = 0;
p_state->recv.current_digit_on_time = 0;
p_state->recv.current_digit_off_time = 0;
p_state->recv.current_digit_value = CAPIDTMF_RECV_NO_DIGIT;
p_state->recv.digit_write_pos = 0;
p_state->recv.digit_read_pos = 0;
p_state->recv.indication_state = 0;
p_state->recv.indication_state_ack = 0;
p_state->recv.state = CAPIDTMF_RECV_STATE_IDLE;
}
void capidtmf_recv_enable (t_capidtmf_state *p_state, word min_digit_duration, word min_gap_duration)
{
p_state->recv.indication_state_ack &= CAPIDTMF_RECV_INDICATION_DIGIT;
p_state->recv.min_digit_duration = (word)(((((dword) min_digit_duration) * 8) +
((dword)(CAPIDTMF_RECV_TIME_GRANULARITY / 2))) / ((dword) CAPIDTMF_RECV_TIME_GRANULARITY));
if (p_state->recv.min_digit_duration <= 1)
p_state->recv.min_digit_duration = 1;
else
(p_state->recv.min_digit_duration)--;
p_state->recv.min_gap_duration =
(word)((((dword) min_gap_duration) * 8) / ((dword) CAPIDTMF_RECV_TIME_GRANULARITY));
if (p_state->recv.min_gap_duration <= 1)
p_state->recv.min_gap_duration = 1;
else
(p_state->recv.min_gap_duration)--;
p_state->recv.state |= CAPIDTMF_RECV_STATE_DTMF_ACTIVE;
}
void capidtmf_recv_disable (t_capidtmf_state *p_state)
{
p_state->recv.state &= ~CAPIDTMF_RECV_STATE_DTMF_ACTIVE;
if (p_state->recv.state == CAPIDTMF_RECV_STATE_IDLE)
capidtmf_recv_init (p_state);
else
{
p_state->recv.cycle_counter = 0;
p_state->recv.current_digit_on_time = 0;
p_state->recv.current_digit_off_time = 0;
p_state->recv.current_digit_value = CAPIDTMF_RECV_NO_DIGIT;
}
}
word capidtmf_recv_indication (t_capidtmf_state *p_state, byte *buffer)
{
word i, j, k, flags;
flags = p_state->recv.indication_state ^ p_state->recv.indication_state_ack;
p_state->recv.indication_state_ack ^= flags & CAPIDTMF_RECV_INDICATION_DIGIT;
if (p_state->recv.digit_write_pos != p_state->recv.digit_read_pos)
{
i = 0;
k = p_state->recv.digit_write_pos;
j = p_state->recv.digit_read_pos;
do
{
buffer[i++] = p_state->recv.digit_buffer[j];
j = (j == CAPIDTMF_RECV_DIGIT_BUFFER_SIZE - 1) ? 0 : j + 1;
} while (j != k);
p_state->recv.digit_read_pos = k;
return (i);
}
p_state->recv.indication_state_ack ^= flags;
return (0);
}
void capidtmf_recv_block (t_capidtmf_state *p_state, byte *buffer, word length)
{
byte result_digit;
word sample_number, cycle_counter, n, i;
word low_peak, high_peak;
dword lo, hi;
byte *p;
short *q;
byte goertzel_result_buffer[CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
short windowed_sample_buffer[CAPIDTMF_RECV_WINDOWED_SAMPLES];
if (p_state->recv.state & CAPIDTMF_RECV_STATE_DTMF_ACTIVE)
{
cycle_counter = p_state->recv.cycle_counter;
sample_number = 0;
while (sample_number < length)
{
if (cycle_counter < CAPIDTMF_RECV_ACCUMULATE_CYCLES)
{
if (cycle_counter == 0)
{
for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
{
p_state->recv.goertzel_buffer[0][i] = 0;
p_state->recv.goertzel_buffer[1][i] = 0;
}
}
n = CAPIDTMF_RECV_ACCUMULATE_CYCLES - cycle_counter;
if (n > length - sample_number)
n = length - sample_number;
if (n > CAPIDTMF_RECV_WINDOWED_SAMPLES)
n = CAPIDTMF_RECV_WINDOWED_SAMPLES;
p = buffer + sample_number;
q = capidtmf_recv_window_function + cycle_counter;
if (p_state->ulaw)
{
for (i = 0; i < n; i++)
{
windowed_sample_buffer[i] =
(short)((capidtmf_expand_table_ulaw[p[i]] * ((long)(q[i]))) >> 15);
}
}
else
{
for (i = 0; i < n; i++)
{
windowed_sample_buffer[i] =
(short)((capidtmf_expand_table_alaw[p[i]] * ((long)(q[i]))) >> 15);
}
}
capidtmf_recv_goertzel_coef_table[CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT - 1] = CAPIDTMF_RECV_FUNDAMENTAL_OFFSET;
capidtmf_goertzel_loop (p_state->recv.goertzel_buffer[0],
capidtmf_recv_goertzel_coef_table, windowed_sample_buffer, n);
cycle_counter += n;
sample_number += n;
}
else
{
capidtmf_goertzel_result (p_state->recv.goertzel_buffer[0],
capidtmf_recv_goertzel_coef_table);
for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
{
lo = (dword)(p_state->recv.goertzel_buffer[0][i]);
hi = (dword)(p_state->recv.goertzel_buffer[1][i]);
if (hi != 0)
{
n = capidtmf_dword_leading_zeroes (hi);
hi = (hi << n) | (lo >> (32 - n));
}
else
{
n = capidtmf_dword_leading_zeroes (lo);
hi = lo << n;
n += 32;
}
n = 195 - 3 * n;
if (hi >= 0xcb300000L)
n += 2;
else if (hi >= 0xa1450000L)
n++;
goertzel_result_buffer[i] = (byte) n;
}
low_peak = DSPDTMF_RX_SENSITIVITY_LOW_DEFAULT;
result_digit = CAPIDTMF_RECV_NO_DIGIT;
for (i = 0; i < CAPIDTMF_LOW_GROUP_FREQUENCIES; i++)
{
if (goertzel_result_buffer[i] > low_peak)
{
low_peak = goertzel_result_buffer[i];
result_digit = (byte) i;
}
}
high_peak = DSPDTMF_RX_SENSITIVITY_HIGH_DEFAULT;
n = CAPIDTMF_RECV_NO_DIGIT;
for (i = CAPIDTMF_LOW_GROUP_FREQUENCIES; i < CAPIDTMF_RECV_BASE_FREQUENCY_COUNT; i++)
{
if (goertzel_result_buffer[i] > high_peak)
{
high_peak = goertzel_result_buffer[i];
n = (i - CAPIDTMF_LOW_GROUP_FREQUENCIES) << 2;
}
}
result_digit |= (byte) n;
if (low_peak + DSPDTMF_RX_HIGH_EXCEEDING_LOW_DEFAULT < high_peak)
result_digit = CAPIDTMF_RECV_NO_DIGIT;
if (high_peak + DSPDTMF_RX_LOW_EXCEEDING_HIGH_DEFAULT < low_peak)
result_digit = CAPIDTMF_RECV_NO_DIGIT;
n = 0;
for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
{
if ((((short)(low_peak - goertzel_result_buffer[i] - capidtmf_recv_guard_snr_low_table[i])) < 0)
|| (((short)(high_peak - goertzel_result_buffer[i] - capidtmf_recv_guard_snr_high_table[i])) < 0))
{
n++;
}
}
if (n != 2)
result_digit = CAPIDTMF_RECV_NO_DIGIT;
if (result_digit == CAPIDTMF_RECV_NO_DIGIT)
{
if (p_state->recv.current_digit_on_time != 0)
{
if (++(p_state->recv.current_digit_off_time) >= p_state->recv.min_gap_duration)
{
p_state->recv.current_digit_on_time = 0;
p_state->recv.current_digit_off_time = 0;
}
}
else
{
if (p_state->recv.current_digit_off_time != 0)
(p_state->recv.current_digit_off_time)--;
}
}
else
{
if ((p_state->recv.current_digit_on_time == 0)
&& (p_state->recv.current_digit_off_time != 0))
{
(p_state->recv.current_digit_off_time)--;
}
else
{
n = p_state->recv.current_digit_off_time;
if ((p_state->recv.current_digit_on_time != 0)
&& (result_digit != p_state->recv.current_digit_value))
{
p_state->recv.current_digit_on_time = 0;
n = 0;
}
p_state->recv.current_digit_value = result_digit;
p_state->recv.current_digit_off_time = 0;
if (p_state->recv.current_digit_on_time != 0xffff)
{
p_state->recv.current_digit_on_time += n + 1;
if (p_state->recv.current_digit_on_time >= p_state->recv.min_digit_duration)
{
p_state->recv.current_digit_on_time = 0xffff;
i = (p_state->recv.digit_write_pos == CAPIDTMF_RECV_DIGIT_BUFFER_SIZE - 1) ?
0 : p_state->recv.digit_write_pos + 1;
if (i == p_state->recv.digit_read_pos)
{
trace (dprintf ("%s,%d: Receive digit overrun",
(char *)(FILE_), __LINE__));
}
else
{
p_state->recv.digit_buffer[p_state->recv.digit_write_pos] = result_digit;
p_state->recv.digit_write_pos = i;
p_state->recv.indication_state =
(p_state->recv.indication_state & ~CAPIDTMF_RECV_INDICATION_DIGIT) |
(~p_state->recv.indication_state_ack & CAPIDTMF_RECV_INDICATION_DIGIT);
}
}
}
}
}
cycle_counter = 0;
sample_number++;
}
}
p_state->recv.cycle_counter = cycle_counter;
}
}
void capidtmf_init (t_capidtmf_state *p_state, byte ulaw)
{
p_state->ulaw = ulaw;
capidtmf_recv_init (p_state);
}
