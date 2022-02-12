void des_3cbc_encrypt(des_cblock *input, des_cblock *output, long length,
des_key_schedule ks1, des_key_schedule ks2, des_cblock *iv1,
des_cblock *iv2, int enc)
{
int off=((int)length-1)/8;
long l8=((length+7)/8)*8;
des_cblock niv1,niv2;
if (enc == DES_ENCRYPT)
{
des_cbc_encrypt((unsigned char*)input,
(unsigned char*)output,length,ks1,iv1,enc);
if (length >= sizeof(des_cblock))
memcpy(niv1,output[off],sizeof(des_cblock));
des_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,l8,ks2,iv1,!enc);
des_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,l8,ks1,iv2,enc);
if (length >= sizeof(des_cblock))
memcpy(niv2,output[off],sizeof(des_cblock));
}
else
{
if (length >= sizeof(des_cblock))
memcpy(niv2,input[off],sizeof(des_cblock));
des_cbc_encrypt((unsigned char*)input,
(unsigned char*)output,l8,ks1,iv2,enc);
des_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,l8,ks2,iv1,!enc);
if (length >= sizeof(des_cblock))
memcpy(niv1,output[off],sizeof(des_cblock));
des_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,length,ks1,iv1,enc);
}
memcpy(*iv1,niv1,sizeof(des_cblock));
memcpy(*iv2,niv2,sizeof(des_cblock));
}
