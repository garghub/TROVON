int X509V3_EXT_add(X509V3_EXT_METHOD *ext)
{
if(!ext_list && !(ext_list = sk_new(ext_cmp))) {
X509V3err(X509V3_F_X509V3_EXT_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
if(!sk_push(ext_list, (char *)ext)) {
X509V3err(X509V3_F_X509V3_EXT_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
return 1;
}
static int ext_cmp(X509V3_EXT_METHOD **a, X509V3_EXT_METHOD **b)
{
return ((*a)->ext_nid - (*b)->ext_nid);
}
X509V3_EXT_METHOD *X509V3_EXT_get_nid(int nid)
{
X509V3_EXT_METHOD tmp;
int idx;
tmp.ext_nid = nid;
if(!ext_list || (tmp.ext_nid < 0) ) return NULL;
idx = sk_find(ext_list, (char *)&tmp);
if(idx == -1) return NULL;
return (X509V3_EXT_METHOD *)sk_value(ext_list, idx);
}
X509V3_EXT_METHOD *X509V3_EXT_get(X509_EXTENSION *ext)
{
int nid;
if((nid = OBJ_obj2nid(ext->object)) == NID_undef) return NULL;
return X509V3_EXT_get_nid(nid);
}
int X509V3_EXT_add_list(X509V3_EXT_METHOD *extlist)
{
for(;extlist->ext_nid!=-1;extlist++)
if(!X509V3_EXT_add(extlist)) return 0;
return 1;
}
int X509V3_EXT_add_alias(int nid_to, int nid_from)
{
X509V3_EXT_METHOD *ext, *tmpext;
if(!(ext = X509V3_EXT_get_nid(nid_from))) {
X509V3err(X509V3_F_X509V3_EXT_ADD_ALIAS,X509V3_R_EXTENSION_NOT_FOUND);
return 0;
}
if(!(tmpext = (X509V3_EXT_METHOD *)Malloc(sizeof(X509V3_EXT_METHOD)))) {
X509V3err(X509V3_F_X509V3_EXT_ADD_ALIAS,ERR_R_MALLOC_FAILURE);
return 0;
}
*tmpext = *ext;
tmpext->ext_nid = nid_to;
tmpext->ext_flags |= X509V3_EXT_DYNAMIC;
return 1;
}
void X509V3_EXT_cleanup(void)
{
sk_pop_free(ext_list, ext_list_free);
ext_list = NULL;
}
static void ext_list_free(X509V3_EXT_METHOD *ext)
{
if(ext->ext_flags & X509V3_EXT_DYNAMIC) Free(ext);
}
int X509V3_add_standard_extensions(void)
{
X509V3_EXT_add_list(v3_ns_ia5_list);
X509V3_EXT_add_list(v3_alt);
X509V3_EXT_add(&v3_bcons);
X509V3_EXT_add(&v3_nscert);
X509V3_EXT_add(&v3_key_usage);
X509V3_EXT_add(&v3_ext_ku);
X509V3_EXT_add(&v3_skey_id);
X509V3_EXT_add(&v3_akey_id);
X509V3_EXT_add(&v3_pkey_usage_period);
X509V3_EXT_add(&v3_crl_num);
X509V3_EXT_add(&v3_sxnet);
X509V3_EXT_add(&v3_crl_reason);
X509V3_EXT_add(&v3_cpols);
X509V3_EXT_add(&v3_crld);
return 1;
}
void *X509V3_EXT_d2i(X509_EXTENSION *ext)
{
X509V3_EXT_METHOD *method;
unsigned char *p;
if(!(method = X509V3_EXT_get(ext)) || !method->d2i) return NULL;
p = ext->value->data;
return method->d2i(NULL, &p, ext->value->length);
}
