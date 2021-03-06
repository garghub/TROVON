void xxh32_copy_state(struct xxh32_state *dst, const struct xxh32_state *src)
{
memcpy(dst, src, sizeof(*dst));
}
void xxh64_copy_state(struct xxh64_state *dst, const struct xxh64_state *src)
{
memcpy(dst, src, sizeof(*dst));
}
static uint32_t xxh32_round(uint32_t seed, const uint32_t input)
{
seed += input * PRIME32_2;
seed = xxh_rotl32(seed, 13);
seed *= PRIME32_1;
return seed;
}
uint32_t xxh32(const void *input, const size_t len, const uint32_t seed)
{
const uint8_t *p = (const uint8_t *)input;
const uint8_t *b_end = p + len;
uint32_t h32;
if (len >= 16) {
const uint8_t *const limit = b_end - 16;
uint32_t v1 = seed + PRIME32_1 + PRIME32_2;
uint32_t v2 = seed + PRIME32_2;
uint32_t v3 = seed + 0;
uint32_t v4 = seed - PRIME32_1;
do {
v1 = xxh32_round(v1, get_unaligned_le32(p));
p += 4;
v2 = xxh32_round(v2, get_unaligned_le32(p));
p += 4;
v3 = xxh32_round(v3, get_unaligned_le32(p));
p += 4;
v4 = xxh32_round(v4, get_unaligned_le32(p));
p += 4;
} while (p <= limit);
h32 = xxh_rotl32(v1, 1) + xxh_rotl32(v2, 7) +
xxh_rotl32(v3, 12) + xxh_rotl32(v4, 18);
} else {
h32 = seed + PRIME32_5;
}
h32 += (uint32_t)len;
while (p + 4 <= b_end) {
h32 += get_unaligned_le32(p) * PRIME32_3;
h32 = xxh_rotl32(h32, 17) * PRIME32_4;
p += 4;
}
while (p < b_end) {
h32 += (*p) * PRIME32_5;
h32 = xxh_rotl32(h32, 11) * PRIME32_1;
p++;
}
h32 ^= h32 >> 15;
h32 *= PRIME32_2;
h32 ^= h32 >> 13;
h32 *= PRIME32_3;
h32 ^= h32 >> 16;
return h32;
}
static uint64_t xxh64_round(uint64_t acc, const uint64_t input)
{
acc += input * PRIME64_2;
acc = xxh_rotl64(acc, 31);
acc *= PRIME64_1;
return acc;
}
static uint64_t xxh64_merge_round(uint64_t acc, uint64_t val)
{
val = xxh64_round(0, val);
acc ^= val;
acc = acc * PRIME64_1 + PRIME64_4;
return acc;
}
uint64_t xxh64(const void *input, const size_t len, const uint64_t seed)
{
const uint8_t *p = (const uint8_t *)input;
const uint8_t *const b_end = p + len;
uint64_t h64;
if (len >= 32) {
const uint8_t *const limit = b_end - 32;
uint64_t v1 = seed + PRIME64_1 + PRIME64_2;
uint64_t v2 = seed + PRIME64_2;
uint64_t v3 = seed + 0;
uint64_t v4 = seed - PRIME64_1;
do {
v1 = xxh64_round(v1, get_unaligned_le64(p));
p += 8;
v2 = xxh64_round(v2, get_unaligned_le64(p));
p += 8;
v3 = xxh64_round(v3, get_unaligned_le64(p));
p += 8;
v4 = xxh64_round(v4, get_unaligned_le64(p));
p += 8;
} while (p <= limit);
h64 = xxh_rotl64(v1, 1) + xxh_rotl64(v2, 7) +
xxh_rotl64(v3, 12) + xxh_rotl64(v4, 18);
h64 = xxh64_merge_round(h64, v1);
h64 = xxh64_merge_round(h64, v2);
h64 = xxh64_merge_round(h64, v3);
h64 = xxh64_merge_round(h64, v4);
} else {
h64 = seed + PRIME64_5;
}
h64 += (uint64_t)len;
while (p + 8 <= b_end) {
const uint64_t k1 = xxh64_round(0, get_unaligned_le64(p));
h64 ^= k1;
h64 = xxh_rotl64(h64, 27) * PRIME64_1 + PRIME64_4;
p += 8;
}
if (p + 4 <= b_end) {
h64 ^= (uint64_t)(get_unaligned_le32(p)) * PRIME64_1;
h64 = xxh_rotl64(h64, 23) * PRIME64_2 + PRIME64_3;
p += 4;
}
while (p < b_end) {
h64 ^= (*p) * PRIME64_5;
h64 = xxh_rotl64(h64, 11) * PRIME64_1;
p++;
}
h64 ^= h64 >> 33;
h64 *= PRIME64_2;
h64 ^= h64 >> 29;
h64 *= PRIME64_3;
h64 ^= h64 >> 32;
return h64;
}
void xxh32_reset(struct xxh32_state *statePtr, const uint32_t seed)
{
struct xxh32_state state;
memset(&state, 0, sizeof(state));
state.v1 = seed + PRIME32_1 + PRIME32_2;
state.v2 = seed + PRIME32_2;
state.v3 = seed + 0;
state.v4 = seed - PRIME32_1;
memcpy(statePtr, &state, sizeof(state));
}
void xxh64_reset(struct xxh64_state *statePtr, const uint64_t seed)
{
struct xxh64_state state;
memset(&state, 0, sizeof(state));
state.v1 = seed + PRIME64_1 + PRIME64_2;
state.v2 = seed + PRIME64_2;
state.v3 = seed + 0;
state.v4 = seed - PRIME64_1;
memcpy(statePtr, &state, sizeof(state));
}
int xxh32_update(struct xxh32_state *state, const void *input, const size_t len)
{
const uint8_t *p = (const uint8_t *)input;
const uint8_t *const b_end = p + len;
if (input == NULL)
return -EINVAL;
state->total_len_32 += (uint32_t)len;
state->large_len |= (len >= 16) | (state->total_len_32 >= 16);
if (state->memsize + len < 16) {
memcpy((uint8_t *)(state->mem32) + state->memsize, input, len);
state->memsize += (uint32_t)len;
return 0;
}
if (state->memsize) {
const uint32_t *p32 = state->mem32;
memcpy((uint8_t *)(state->mem32) + state->memsize, input,
16 - state->memsize);
state->v1 = xxh32_round(state->v1, get_unaligned_le32(p32));
p32++;
state->v2 = xxh32_round(state->v2, get_unaligned_le32(p32));
p32++;
state->v3 = xxh32_round(state->v3, get_unaligned_le32(p32));
p32++;
state->v4 = xxh32_round(state->v4, get_unaligned_le32(p32));
p32++;
p += 16-state->memsize;
state->memsize = 0;
}
if (p <= b_end - 16) {
const uint8_t *const limit = b_end - 16;
uint32_t v1 = state->v1;
uint32_t v2 = state->v2;
uint32_t v3 = state->v3;
uint32_t v4 = state->v4;
do {
v1 = xxh32_round(v1, get_unaligned_le32(p));
p += 4;
v2 = xxh32_round(v2, get_unaligned_le32(p));
p += 4;
v3 = xxh32_round(v3, get_unaligned_le32(p));
p += 4;
v4 = xxh32_round(v4, get_unaligned_le32(p));
p += 4;
} while (p <= limit);
state->v1 = v1;
state->v2 = v2;
state->v3 = v3;
state->v4 = v4;
}
if (p < b_end) {
memcpy(state->mem32, p, (size_t)(b_end-p));
state->memsize = (uint32_t)(b_end-p);
}
return 0;
}
uint32_t xxh32_digest(const struct xxh32_state *state)
{
const uint8_t *p = (const uint8_t *)state->mem32;
const uint8_t *const b_end = (const uint8_t *)(state->mem32) +
state->memsize;
uint32_t h32;
if (state->large_len) {
h32 = xxh_rotl32(state->v1, 1) + xxh_rotl32(state->v2, 7) +
xxh_rotl32(state->v3, 12) + xxh_rotl32(state->v4, 18);
} else {
h32 = state->v3 + PRIME32_5;
}
h32 += state->total_len_32;
while (p + 4 <= b_end) {
h32 += get_unaligned_le32(p) * PRIME32_3;
h32 = xxh_rotl32(h32, 17) * PRIME32_4;
p += 4;
}
while (p < b_end) {
h32 += (*p) * PRIME32_5;
h32 = xxh_rotl32(h32, 11) * PRIME32_1;
p++;
}
h32 ^= h32 >> 15;
h32 *= PRIME32_2;
h32 ^= h32 >> 13;
h32 *= PRIME32_3;
h32 ^= h32 >> 16;
return h32;
}
int xxh64_update(struct xxh64_state *state, const void *input, const size_t len)
{
const uint8_t *p = (const uint8_t *)input;
const uint8_t *const b_end = p + len;
if (input == NULL)
return -EINVAL;
state->total_len += len;
if (state->memsize + len < 32) {
memcpy(((uint8_t *)state->mem64) + state->memsize, input, len);
state->memsize += (uint32_t)len;
return 0;
}
if (state->memsize) {
uint64_t *p64 = state->mem64;
memcpy(((uint8_t *)p64) + state->memsize, input,
32 - state->memsize);
state->v1 = xxh64_round(state->v1, get_unaligned_le64(p64));
p64++;
state->v2 = xxh64_round(state->v2, get_unaligned_le64(p64));
p64++;
state->v3 = xxh64_round(state->v3, get_unaligned_le64(p64));
p64++;
state->v4 = xxh64_round(state->v4, get_unaligned_le64(p64));
p += 32 - state->memsize;
state->memsize = 0;
}
if (p + 32 <= b_end) {
const uint8_t *const limit = b_end - 32;
uint64_t v1 = state->v1;
uint64_t v2 = state->v2;
uint64_t v3 = state->v3;
uint64_t v4 = state->v4;
do {
v1 = xxh64_round(v1, get_unaligned_le64(p));
p += 8;
v2 = xxh64_round(v2, get_unaligned_le64(p));
p += 8;
v3 = xxh64_round(v3, get_unaligned_le64(p));
p += 8;
v4 = xxh64_round(v4, get_unaligned_le64(p));
p += 8;
} while (p <= limit);
state->v1 = v1;
state->v2 = v2;
state->v3 = v3;
state->v4 = v4;
}
if (p < b_end) {
memcpy(state->mem64, p, (size_t)(b_end-p));
state->memsize = (uint32_t)(b_end - p);
}
return 0;
}
uint64_t xxh64_digest(const struct xxh64_state *state)
{
const uint8_t *p = (const uint8_t *)state->mem64;
const uint8_t *const b_end = (const uint8_t *)state->mem64 +
state->memsize;
uint64_t h64;
if (state->total_len >= 32) {
const uint64_t v1 = state->v1;
const uint64_t v2 = state->v2;
const uint64_t v3 = state->v3;
const uint64_t v4 = state->v4;
h64 = xxh_rotl64(v1, 1) + xxh_rotl64(v2, 7) +
xxh_rotl64(v3, 12) + xxh_rotl64(v4, 18);
h64 = xxh64_merge_round(h64, v1);
h64 = xxh64_merge_round(h64, v2);
h64 = xxh64_merge_round(h64, v3);
h64 = xxh64_merge_round(h64, v4);
} else {
h64 = state->v3 + PRIME64_5;
}
h64 += (uint64_t)state->total_len;
while (p + 8 <= b_end) {
const uint64_t k1 = xxh64_round(0, get_unaligned_le64(p));
h64 ^= k1;
h64 = xxh_rotl64(h64, 27) * PRIME64_1 + PRIME64_4;
p += 8;
}
if (p + 4 <= b_end) {
h64 ^= (uint64_t)(get_unaligned_le32(p)) * PRIME64_1;
h64 = xxh_rotl64(h64, 23) * PRIME64_2 + PRIME64_3;
p += 4;
}
while (p < b_end) {
h64 ^= (*p) * PRIME64_5;
h64 = xxh_rotl64(h64, 11) * PRIME64_1;
p++;
}
h64 ^= h64 >> 33;
h64 *= PRIME64_2;
h64 ^= h64 >> 29;
h64 *= PRIME64_3;
h64 ^= h64 >> 32;
return h64;
}
