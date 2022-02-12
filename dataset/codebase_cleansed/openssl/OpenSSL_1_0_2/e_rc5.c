static int rc5_ctrl(EVP_CIPHER_CTX *c, int type, int arg, void *ptr)
{
switch (type) {
case EVP_CTRL_INIT:
data(c)->rounds = RC5_12_ROUNDS;
return 1;
case EVP_CTRL_GET_RC5_ROUNDS:
*(int *)ptr = data(c)->rounds;
return 1;
case EVP_CTRL_SET_RC5_ROUNDS:
switch (arg) {
case RC5_8_ROUNDS:
case RC5_12_ROUNDS:
case RC5_16_ROUNDS:
data(c)->rounds = arg;
return 1;
default:
EVPerr(EVP_F_RC5_CTRL, EVP_R_UNSUPORTED_NUMBER_OF_ROUNDS);
return 0;
}
default:
return -1;
}
}
static int r_32_12_16_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
RC5_32_set_key(&data(ctx)->ks, EVP_CIPHER_CTX_key_length(ctx),
key, data(ctx)->rounds);
return 1;
}
