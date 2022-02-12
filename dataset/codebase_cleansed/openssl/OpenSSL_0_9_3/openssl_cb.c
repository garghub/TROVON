SV *new_ref(char *type, char *obj, int mort)
{
SV *ret;
if (mort)
ret=sv_newmortal();
else
ret=newSViv(0);
sv_setref_pv(ret,type,(void *)obj);
return(ret);
}
int ex_new(char *obj, SV *data, CRYPTO_EX_DATA *ad, int idx, long argl,
char *argp)
{
SV *sv;
fprintf(stderr,"ex_new idx=%d %08X %s\n",idx,obj,argp);
sv=sv_newmortal();
sv_setref_pv(sv,argp,(void *)obj);
CRYPTO_set_ex_data(ad,idx,(char *)sv);
return(1);
}
void ex_cleanup(char *obj, SV *data, CRYPTO_EX_DATA *ad, int idx, long argl,
char *argp)
{
pr_name("ex_cleanup");
fprintf(stderr,"ex_cleanup %08X %s\n",obj,argp);
if (data != NULL)
SvREFCNT_dec((SV *)data);
}
