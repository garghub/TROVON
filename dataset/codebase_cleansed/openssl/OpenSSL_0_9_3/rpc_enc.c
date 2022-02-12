int _des_crypt(char *buf, int len, struct desparams *desp)
{
des_key_schedule ks;
int enc;
des_set_key(&desp->des_key,ks);
enc=(desp->des_dir == ENCRYPT)?DES_ENCRYPT:DES_DECRYPT;
if (desp->des_mode == CBC)
des_ecb_encrypt((const_des_cblock *)desp->UDES.UDES_buf,
(des_cblock *)desp->UDES.UDES_buf,ks,
enc);
else
{
des_ncbc_encrypt(desp->UDES.UDES_buf,desp->UDES.UDES_buf,
len,ks,&desp->des_ivec,enc);
#ifdef undef
a=(char *)&(desp->UDES.UDES_buf[len-8]);
b=(char *)&(desp->des_ivec[0]);
*(a++)= *(b++); *(a++)= *(b++);
*(a++)= *(b++); *(a++)= *(b++);
*(a++)= *(b++); *(a++)= *(b++);
*(a++)= *(b++); *(a++)= *(b++);
#endif
}
return(1);
}
