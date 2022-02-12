void DES_3cbc_encrypt(DES_cblock *input, DES_cblock *output, long length,
DES_key_schedule ks1, DES_key_schedule ks2, DES_cblock *iv1,
DES_cblock *iv2, int enc)
{
int off=((int)length-1)/8;
long l8=((length+7)/8)*8;
DES_cblock niv1,niv2;
if (enc == DES_ENCRYPT)
{
DES_cbc_encrypt((unsigned char*)input,
(unsigned char*)output,length,&ks1,iv1,enc);
if (length >= sizeof(DES_cblock))
memcpy(niv1,output[off],sizeof(DES_cblock));
DES_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,l8,&ks2,iv1,!enc);
DES_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,l8,&ks1,iv2,enc);
if (length >= sizeof(DES_cblock))
memcpy(niv2,output[off],sizeof(DES_cblock));
}
else
{
if (length >= sizeof(DES_cblock))
memcpy(niv2,input[off],sizeof(DES_cblock));
DES_cbc_encrypt((unsigned char*)input,
(unsigned char*)output,l8,&ks1,iv2,enc);
DES_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,l8,&ks2,iv1,!enc);
if (length >= sizeof(DES_cblock))
memcpy(niv1,output[off],sizeof(DES_cblock));
DES_cbc_encrypt((unsigned char*)output,
(unsigned char*)output,length,&ks1,iv1,enc);
}
memcpy(*iv1,niv1,sizeof(DES_cblock));
memcpy(*iv2,niv2,sizeof(DES_cblock));
}
