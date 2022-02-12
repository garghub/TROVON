int EVP_add_cipher(const EVP_CIPHER *c)
{
int r;
r=OBJ_NAME_add(OBJ_nid2sn(c->nid),OBJ_NAME_TYPE_CIPHER_METH,(char *)c);
if (r == 0) return(0);
r=OBJ_NAME_add(OBJ_nid2ln(c->nid),OBJ_NAME_TYPE_CIPHER_METH,(char *)c);
return(r);
}
int EVP_add_digest(const EVP_MD *md)
{
int r;
const char *name;
name=OBJ_nid2sn(md->type);
r=OBJ_NAME_add(name,OBJ_NAME_TYPE_MD_METH,(char *)md);
if (r == 0) return(0);
r=OBJ_NAME_add(OBJ_nid2ln(md->type),OBJ_NAME_TYPE_MD_METH,(char *)md);
if (r == 0) return(0);
if (md->type != md->pkey_type)
{
r=OBJ_NAME_add(OBJ_nid2sn(md->pkey_type),
OBJ_NAME_TYPE_MD_METH|OBJ_NAME_ALIAS,name);
if (r == 0) return(0);
r=OBJ_NAME_add(OBJ_nid2ln(md->pkey_type),
OBJ_NAME_TYPE_MD_METH|OBJ_NAME_ALIAS,name);
}
return(r);
}
const EVP_CIPHER *EVP_get_cipherbyname(const char *name)
{
const EVP_CIPHER *cp;
cp=(const EVP_CIPHER *)OBJ_NAME_get(name,OBJ_NAME_TYPE_CIPHER_METH);
return(cp);
}
const EVP_MD *EVP_get_digestbyname(const char *name)
{
const EVP_MD *cp;
cp=(const EVP_MD *)OBJ_NAME_get(name,OBJ_NAME_TYPE_MD_METH);
return(cp);
}
void EVP_cleanup(void)
{
OBJ_NAME_cleanup(OBJ_NAME_TYPE_CIPHER_METH);
OBJ_NAME_cleanup(OBJ_NAME_TYPE_MD_METH);
OBJ_NAME_cleanup(-1);
EVP_PBE_cleanup();
}
