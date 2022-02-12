void crypt_rc4_init(rc4_state_struct *rc4_state,
const unsigned char *key, int key_len)
{
int ind;
unsigned char j = 0;
unsigned char *s_box;
memset(rc4_state, 0, sizeof(rc4_state_struct));
s_box = rc4_state->s_box;
for (ind = 0; ind < 256; ind++)
{
s_box[ind] = (unsigned char)ind;
}
for( ind = 0; ind < 256; ind++)
{
unsigned char tc;
j += (s_box[ind] + key[ind%key_len]);
tc = s_box[ind];
s_box[ind] = s_box[j];
s_box[j] = tc;
}
}
void crypt_rc4(rc4_state_struct *rc4_state, unsigned char *data, int data_len)
{
unsigned char *s_box;
unsigned char index_i;
unsigned char index_j;
int ind;
index_i = rc4_state->index_i;
index_j = rc4_state->index_j;
s_box = rc4_state->s_box;
for( ind = 0; ind < data_len; ind++)
{
unsigned char tc;
unsigned char t;
index_i++;
index_j += s_box[index_i];
tc = s_box[index_i];
s_box[index_i] = s_box[index_j];
s_box[index_j] = tc;
t = s_box[index_i] + s_box[index_j];
data[ind] = data[ind] ^ s_box[t];
}
rc4_state->index_i = index_i;
rc4_state->index_j = index_j;
}
