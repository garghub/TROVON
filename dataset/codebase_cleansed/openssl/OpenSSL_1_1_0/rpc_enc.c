int _des_crypt(char *buf, int len, struct desparams *desp)
{
DES_key_schedule ks;
int enc;
DES_set_key_unchecked(&desp->des_key, &ks);
enc = (desp->des_dir == ENCRYPT) ? DES_ENCRYPT : DES_DECRYPT;
if (desp->des_mode == CBC)
DES_ecb_encrypt((const_DES_cblock *)desp->UDES.UDES_buf,
(DES_cblock *)desp->UDES.UDES_buf, &ks, enc);
else {
DES_ncbc_encrypt(desp->UDES.UDES_buf, desp->UDES.UDES_buf,
len, &ks, &desp->des_ivec, enc);
}
return (1);
}
