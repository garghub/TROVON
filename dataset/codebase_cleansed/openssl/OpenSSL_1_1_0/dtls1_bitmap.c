static int satsub64be(const unsigned char *v1, const unsigned char *v2)
{
int64_t ret;
uint64_t l1, l2;
n2l8(v1, l1);
n2l8(v2, l2);
ret = l1 - l2;
if (l1 > l2 && ret < 0)
return 128;
else if (l2 > l1 && ret > 0)
return -128;
if (ret > 128)
return 128;
else if (ret < -128)
return -128;
else
return (int)ret;
}
int dtls1_record_replay_check(SSL *s, DTLS1_BITMAP *bitmap)
{
int cmp;
unsigned int shift;
const unsigned char *seq = s->rlayer.read_sequence;
cmp = satsub64be(seq, bitmap->max_seq_num);
if (cmp > 0) {
SSL3_RECORD_set_seq_num(RECORD_LAYER_get_rrec(&s->rlayer), seq);
return 1;
}
shift = -cmp;
if (shift >= sizeof(bitmap->map) * 8)
return 0;
else if (bitmap->map & (1UL << shift))
return 0;
SSL3_RECORD_set_seq_num(RECORD_LAYER_get_rrec(&s->rlayer), seq);
return 1;
}
void dtls1_record_bitmap_update(SSL *s, DTLS1_BITMAP *bitmap)
{
int cmp;
unsigned int shift;
const unsigned char *seq = RECORD_LAYER_get_read_sequence(&s->rlayer);
cmp = satsub64be(seq, bitmap->max_seq_num);
if (cmp > 0) {
shift = cmp;
if (shift < sizeof(bitmap->map) * 8)
bitmap->map <<= shift, bitmap->map |= 1UL;
else
bitmap->map = 1UL;
memcpy(bitmap->max_seq_num, seq, SEQ_NUM_SIZE);
} else {
shift = -cmp;
if (shift < sizeof(bitmap->map) * 8)
bitmap->map |= 1UL << shift;
}
}
