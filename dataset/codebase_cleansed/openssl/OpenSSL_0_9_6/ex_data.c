int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad, int idx, void *val)
{
int i;
if (ad->sk == NULL)
{
if ((ad->sk=sk_new_null()) == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA,ERR_R_MALLOC_FAILURE);
return(0);
}
}
i=sk_num(ad->sk);
while (i <= idx)
{
if (!sk_push(ad->sk,NULL))
{
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA,ERR_R_MALLOC_FAILURE);
return(0);
}
i++;
}
sk_set(ad->sk,idx,val);
return(1);
}
void *CRYPTO_get_ex_data(CRYPTO_EX_DATA *ad, int idx)
{
if (ad->sk == NULL)
return(0);
else if (idx >= sk_num(ad->sk))
return(0);
else
return(sk_value(ad->sk,idx));
}
