static int copy_issuer(X509V3_CTX *ctx, GENERAL_NAMES *gens)
{
GENERAL_NAMES *ialt;
GENERAL_NAME *gen;
X509_EXTENSION *ext;
int i;
if(ctx && (ctx->flags == CTX_TEST)) return 1;
if(!ctx || !ctx->issuer_cert) {
X509V3err(X509V3_F_COPY_ISSUER,X509V3_R_NO_ISSUER_DETAILS);
goto err;
}
i = X509_get_ext_by_NID(ctx->issuer_cert, NID_subject_alt_name, -1);
if(i < 0) return 1;
if(!(ext = X509_get_ext(ctx->issuer_cert, i)) ||
!(ialt = X509V3_EXT_d2i(ext)) ) {
X509V3err(X509V3_F_COPY_ISSUER,X509V3_R_ISSUER_DECODE_ERROR);
goto err;
}
for(i = 0; i < sk_GENERAL_NAME_num(ialt); i++) {
gen = sk_GENERAL_NAME_value(ialt, i);
if(!sk_GENERAL_NAME_push(gens, gen)) {
X509V3err(X509V3_F_COPY_ISSUER,ERR_R_MALLOC_FAILURE);
goto err;
}
}
sk_GENERAL_NAME_free(ialt);
return 1;
err:
return 0;
}
static int copy_email(X509V3_CTX *ctx, GENERAL_NAMES *gens, int move_p)
{
X509_NAME *nm;
ASN1_IA5STRING *email = NULL;
X509_NAME_ENTRY *ne;
GENERAL_NAME *gen = NULL;
int i;
if(ctx->flags == CTX_TEST) return 1;
if(!ctx || (!ctx->subject_cert && !ctx->subject_req)) {
X509V3err(X509V3_F_COPY_EMAIL,X509V3_R_NO_SUBJECT_DETAILS);
goto err;
}
if(ctx->subject_cert) nm = X509_get_subject_name(ctx->subject_cert);
else nm = X509_REQ_get_subject_name(ctx->subject_req);
i = -1;
while((i = X509_NAME_get_index_by_NID(nm,
NID_pkcs9_emailAddress, i)) >= 0) {
ne = X509_NAME_get_entry(nm, i);
email = M_ASN1_IA5STRING_dup(X509_NAME_ENTRY_get_data(ne));
if (move_p)
{
X509_NAME_delete_entry(nm, i);
i--;
}
if(!email || !(gen = GENERAL_NAME_new())) {
X509V3err(X509V3_F_COPY_EMAIL,ERR_R_MALLOC_FAILURE);
goto err;
}
gen->d.ia5 = email;
email = NULL;
gen->type = GEN_EMAIL;
if(!sk_GENERAL_NAME_push(gens, gen)) {
X509V3err(X509V3_F_COPY_EMAIL,ERR_R_MALLOC_FAILURE);
goto err;
}
gen = NULL;
}
return 1;
err:
GENERAL_NAME_free(gen);
M_ASN1_IA5STRING_free(email);
return 0;
}
GENERAL_NAME *v2i_GENERAL_NAME(X509V3_EXT_METHOD *method, X509V3_CTX *ctx,
CONF_VALUE *cnf)
{
return v2i_GENERAL_NAME_ex(NULL, method, ctx, cnf, 0);
}
GENERAL_NAME *v2i_GENERAL_NAME_ex(GENERAL_NAME *out,
X509V3_EXT_METHOD *method, X509V3_CTX *ctx,
CONF_VALUE *cnf, int is_nc)
{
char is_string = 0;
int type;
GENERAL_NAME *gen = NULL;
char *name, *value;
name = cnf->name;
value = cnf->value;
if(!value)
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,X509V3_R_MISSING_VALUE);
return NULL;
}
if (out)
gen = out;
else
{
gen = GENERAL_NAME_new();
if(gen == NULL)
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,ERR_R_MALLOC_FAILURE);
return NULL;
}
}
if(!name_cmp(name, "email"))
{
is_string = 1;
type = GEN_EMAIL;
}
else if(!name_cmp(name, "URI"))
{
is_string = 1;
type = GEN_URI;
}
else if(!name_cmp(name, "DNS"))
{
is_string = 1;
type = GEN_DNS;
}
else if(!name_cmp(name, "RID"))
{
ASN1_OBJECT *obj;
if(!(obj = OBJ_txt2obj(value,0)))
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,X509V3_R_BAD_OBJECT);
ERR_add_error_data(2, "value=", value);
goto err;
}
gen->d.rid = obj;
type = GEN_RID;
}
else if(!name_cmp(name, "IP"))
{
if (is_nc)
gen->d.ip = a2i_IPADDRESS_NC(value);
else
gen->d.ip = a2i_IPADDRESS(value);
if(gen->d.ip == NULL)
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,X509V3_R_BAD_IP_ADDRESS);
ERR_add_error_data(2, "value=", value);
goto err;
}
type = GEN_IPADD;
}
else if(!name_cmp(name, "dirName"))
{
type = GEN_DIRNAME;
if (!do_dirname(gen, value, ctx))
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,X509V3_R_DIRNAME_ERROR);
goto err;
}
}
else if(!name_cmp(name, "otherName"))
{
if (!do_othername(gen, value, ctx))
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,X509V3_R_OTHERNAME_ERROR);
goto err;
}
type = GEN_OTHERNAME;
}
else
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,X509V3_R_UNSUPPORTED_OPTION);
ERR_add_error_data(2, "name=", name);
goto err;
}
if(is_string)
{
if(!(gen->d.ia5 = M_ASN1_IA5STRING_new()) ||
!ASN1_STRING_set(gen->d.ia5, (unsigned char*)value,
strlen(value)))
{
X509V3err(X509V3_F_V2I_GENERAL_NAME_EX,ERR_R_MALLOC_FAILURE);
goto err;
}
}
gen->type = type;
return gen;
err:
GENERAL_NAME_free(gen);
return NULL;
}
static int do_othername(GENERAL_NAME *gen, char *value, X509V3_CTX *ctx)
{
char *objtmp = NULL, *p;
int objlen;
if (!(p = strchr(value, ';')))
return 0;
if (!(gen->d.otherName = OTHERNAME_new()))
return 0;
ASN1_TYPE_free(gen->d.otherName->value);
if (!(gen->d.otherName->value = ASN1_generate_v3(p + 1, ctx)))
return 0;
objlen = p - value;
objtmp = OPENSSL_malloc(objlen + 1);
strncpy(objtmp, value, objlen);
objtmp[objlen] = 0;
gen->d.otherName->type_id = OBJ_txt2obj(objtmp, 0);
OPENSSL_free(objtmp);
if (!gen->d.otherName->type_id)
return 0;
return 1;
}
static int do_dirname(GENERAL_NAME *gen, char *value, X509V3_CTX *ctx)
{
int ret;
STACK_OF(CONF_VALUE) *sk;
X509_NAME *nm;
if (!(nm = X509_NAME_new()))
return 0;
sk = X509V3_get_section(ctx, value);
if (!sk)
{
X509V3err(X509V3_F_DO_DIRNAME,X509V3_R_SECTION_NOT_FOUND);
ERR_add_error_data(2, "section=", value);
X509_NAME_free(nm);
return 0;
}
ret = X509V3_NAME_from_section(nm, sk, MBSTRING_ASC);
if (!ret)
X509_NAME_free(nm);
gen->d.dirn = nm;
return ret;
}
