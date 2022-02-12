POLICYINFO *policy_section(X509V3_CTX *ctx, STACK *polstrs, int ia5org)
{
int i;
CONF_VALUE *cnf;
POLICYINFO *pol;
POLICYQUALINFO *qual;
if(!(pol = POLICYINFO_new())) goto merr;
for(i = 0; i < sk_num(polstrs); i++) {
cnf = (CONF_VALUE *)sk_value(polstrs, i);
if(!strcmp(cnf->name, "policyIdentifier")) {
ASN1_OBJECT *pobj;
if(!(pobj = OBJ_txt2obj(cnf->value, 0))) {
X509V3err(X509V3_F_POLICY_SECTION,X509V3_R_INVALID_OBJECT_IDENTIFIER);
X509V3_conf_err(cnf);
goto err;
}
pol->policyid = pobj;
} else if(!name_cmp(cnf->name, "CPS")) {
if(!pol->qualifiers) pol->qualifiers =
sk_POLICYQUALINFO_new_null();
if(!(qual = POLICYQUALINFO_new())) goto merr;
if(!sk_POLICYQUALINFO_push(pol->qualifiers, qual))
goto merr;
qual->pqualid = OBJ_nid2obj(NID_id_qt_cps);
qual->d.cpsuri = ASN1_IA5STRING_new();
if(!ASN1_STRING_set(qual->d.cpsuri, cnf->value,
strlen(cnf->value))) goto merr;
} else if(!name_cmp(cnf->name, "userNotice")) {
STACK *unot;
if(*cnf->value != '@') {
X509V3err(X509V3_F_POLICY_SECTION,X509V3_R_EXPECTED_A_SECTION_NAME);
X509V3_conf_err(cnf);
goto err;
}
unot = X509V3_get_section(ctx, cnf->value + 1);
if(!unot) {
X509V3err(X509V3_F_POLICY_SECTION,X509V3_R_INVALID_SECTION);
X509V3_conf_err(cnf);
goto err;
}
qual = notice_section(ctx, unot, ia5org);
X509V3_section_free(ctx, unot);
if(!qual) goto err;
if(!sk_POLICYQUALINFO_push(pol->qualifiers, qual))
goto merr;
} else {
X509V3err(X509V3_F_POLICY_SECTION,X509V3_R_INVALID_OPTION);
X509V3_conf_err(cnf);
goto err;
}
}
if(!pol->policyid) {
X509V3err(X509V3_F_POLICY_SECTION,X509V3_R_NO_POLICY_IDENTIFIER);
goto err;
}
return pol;
merr:
X509V3err(X509V3_F_POLICY_SECTION,ERR_R_MALLOC_FAILURE);
err:
POLICYINFO_free(pol);
return NULL;
}
static POLICYQUALINFO *notice_section(X509V3_CTX *ctx, STACK *unot, int ia5org)
{
int i;
CONF_VALUE *cnf;
USERNOTICE *not;
POLICYQUALINFO *qual;
if(!(qual = POLICYQUALINFO_new())) goto merr;
qual->pqualid = OBJ_nid2obj(NID_id_qt_unotice);
if(!(not = USERNOTICE_new())) goto merr;
qual->d.usernotice = not;
for(i = 0; i < sk_num(unot); i++) {
cnf = (CONF_VALUE *)sk_value(unot, i);
if(!strcmp(cnf->name, "explicitText")) {
not->exptext = ASN1_VISIBLESTRING_new();
if(!ASN1_STRING_set(not->exptext, cnf->value,
strlen(cnf->value))) goto merr;
} else if(!strcmp(cnf->name, "organization")) {
NOTICEREF *nref;
if(!not->noticeref) {
if(!(nref = NOTICEREF_new())) goto merr;
not->noticeref = nref;
} else nref = not->noticeref;
if(ia5org) nref->organization = ASN1_IA5STRING_new();
else nref->organization = ASN1_VISIBLESTRING_new();
if(!ASN1_STRING_set(nref->organization, cnf->value,
strlen(cnf->value))) goto merr;
} else if(!strcmp(cnf->name, "noticeNumbers")) {
NOTICEREF *nref;
STACK *nos;
if(!not->noticeref) {
if(!(nref = NOTICEREF_new())) goto merr;
not->noticeref = nref;
} else nref = not->noticeref;
nos = X509V3_parse_list(cnf->value);
if(!nos || !sk_num(nos)) {
X509V3err(X509V3_F_NOTICE_SECTION,X509V3_R_INVALID_NUMBERS);
X509V3_conf_err(cnf);
goto err;
}
nref->noticenos = nref_nos(nos);
sk_pop_free(nos, X509V3_conf_free);
if(!nref->noticenos) goto err;
} else {
X509V3err(X509V3_F_NOTICE_SECTION,X509V3_R_INVALID_OPTION);
X509V3_conf_err(cnf);
goto err;
}
}
if(not->noticeref &&
(!not->noticeref->noticenos || !not->noticeref->organization)) {
X509V3err(X509V3_F_NOTICE_SECTION,X509V3_R_NEED_ORGANIZATION_AND_NUMBERS);
goto err;
}
return qual;
merr:
X509V3err(X509V3_F_NOTICE_SECTION,ERR_R_MALLOC_FAILURE);
err:
POLICYQUALINFO_free(qual);
return NULL;
}
static STACK *nref_nos(STACK *nos)
{
STACK *nnums;
CONF_VALUE *cnf;
ASN1_INTEGER *aint;
int i;
if(!(nnums = sk_new_null())) goto merr;
for(i = 0; i < sk_num(nos); i++) {
cnf = (CONF_VALUE *)sk_value(nos, i);
if(!(aint = s2i_ASN1_INTEGER(NULL, cnf->name))) {
X509V3err(X509V3_F_NREF_NOS,X509V3_R_INVALID_NUMBER);
goto err;
}
if(!sk_push(nnums, (char *)aint)) goto merr;
}
return nnums;
merr:
X509V3err(X509V3_F_NOTICE_SECTION,ERR_R_MALLOC_FAILURE);
err:
sk_pop_free(nnums, ASN1_STRING_free);
return NULL;
}
int i2d_POLICYINFO(POLICYINFO *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->policyid, i2d_ASN1_OBJECT);
M_ASN1_I2D_len_SEQUENCE_type(POLICYQUALINFO, a->qualifiers,
i2d_POLICYQUALINFO);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->policyid, i2d_ASN1_OBJECT);
M_ASN1_I2D_put_SEQUENCE_type(POLICYQUALINFO, a->qualifiers,
i2d_POLICYQUALINFO);
M_ASN1_I2D_finish();
}
POLICYINFO *POLICYINFO_new(void)
{
POLICYINFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, POLICYINFO);
ret->policyid = NULL;
ret->qualifiers = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_POLICYINFO_NEW);
}
POLICYINFO *d2i_POLICYINFO(POLICYINFO **a, unsigned char **pp,long length)
{
M_ASN1_D2I_vars(a,POLICYINFO *,POLICYINFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->policyid, d2i_ASN1_OBJECT);
if(!M_ASN1_D2I_end_sequence()) {
M_ASN1_D2I_get_seq_type (POLICYQUALINFO, ret->qualifiers,
d2i_POLICYQUALINFO, POLICYQUALINFO_free);
}
M_ASN1_D2I_Finish(a, POLICYINFO_free, ASN1_F_D2I_POLICYINFO);
}
void POLICYINFO_free(POLICYINFO *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->policyid);
sk_POLICYQUALINFO_pop_free(a->qualifiers, POLICYQUALINFO_free);
Free (a);
}
static void print_notice(BIO *out, USERNOTICE *notice, int indent)
{
int i;
if(notice->noticeref) {
NOTICEREF *ref;
ref = notice->noticeref;
BIO_printf(out, "%*sOrganization: %s\n", indent, "",
ref->organization->data);
BIO_printf(out, "%*sNumber%s: ", indent, "",
(sk_num(ref->noticenos) > 1) ? "s" : "");
for(i = 0; i < sk_num(ref->noticenos); i++) {
ASN1_INTEGER *num;
char *tmp;
num = (ASN1_INTEGER *)sk_value(ref->noticenos, i);
if(i) BIO_puts(out, ", ");
tmp = i2s_ASN1_INTEGER(NULL, num);
BIO_puts(out, tmp);
Free(tmp);
}
BIO_puts(out, "\n");
}
if(notice->exptext)
BIO_printf(out, "%*sExplicit Text: %s\n", indent, "",
notice->exptext->data);
}
int i2d_POLICYQUALINFO(POLICYQUALINFO *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->pqualid, i2d_ASN1_OBJECT);
switch(OBJ_obj2nid(a->pqualid)) {
case NID_id_qt_cps:
M_ASN1_I2D_len(a->d.cpsuri, i2d_ASN1_IA5STRING);
break;
case NID_id_qt_unotice:
M_ASN1_I2D_len(a->d.usernotice, i2d_USERNOTICE);
break;
default:
M_ASN1_I2D_len(a->d.other, i2d_ASN1_TYPE);
break;
}
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->pqualid, i2d_ASN1_OBJECT);
switch(OBJ_obj2nid(a->pqualid)) {
case NID_id_qt_cps:
M_ASN1_I2D_put(a->d.cpsuri, i2d_ASN1_IA5STRING);
break;
case NID_id_qt_unotice:
M_ASN1_I2D_put(a->d.usernotice, i2d_USERNOTICE);
break;
default:
M_ASN1_I2D_put(a->d.other, i2d_ASN1_TYPE);
break;
}
M_ASN1_I2D_finish();
}
POLICYQUALINFO *POLICYQUALINFO_new(void)
{
POLICYQUALINFO *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, POLICYQUALINFO);
ret->pqualid = NULL;
ret->d.other = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_POLICYQUALINFO_NEW);
}
POLICYQUALINFO *d2i_POLICYQUALINFO(POLICYQUALINFO **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,POLICYQUALINFO *,POLICYQUALINFO_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->pqualid, d2i_ASN1_OBJECT);
switch(OBJ_obj2nid(ret->pqualid)) {
case NID_id_qt_cps:
M_ASN1_D2I_get(ret->d.cpsuri, d2i_ASN1_IA5STRING);
break;
case NID_id_qt_unotice:
M_ASN1_D2I_get(ret->d.usernotice, d2i_USERNOTICE);
break;
default:
M_ASN1_D2I_get(ret->d.other, d2i_ASN1_TYPE);
break;
}
M_ASN1_D2I_Finish(a, POLICYQUALINFO_free, ASN1_F_D2I_POLICYQUALINFO);
}
void POLICYQUALINFO_free(POLICYQUALINFO *a)
{
if (a == NULL) return;
switch(OBJ_obj2nid(a->pqualid)) {
case NID_id_qt_cps:
ASN1_IA5STRING_free(a->d.cpsuri);
break;
case NID_id_qt_unotice:
USERNOTICE_free(a->d.usernotice);
break;
default:
ASN1_TYPE_free(a->d.other);
break;
}
ASN1_OBJECT_free(a->pqualid);
Free (a);
}
int i2d_USERNOTICE(USERNOTICE *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->noticeref, i2d_NOTICEREF);
M_ASN1_I2D_len (a->exptext, i2d_DISPLAYTEXT);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->noticeref, i2d_NOTICEREF);
M_ASN1_I2D_put (a->exptext, i2d_DISPLAYTEXT);
M_ASN1_I2D_finish();
}
USERNOTICE *USERNOTICE_new(void)
{
USERNOTICE *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, USERNOTICE);
ret->noticeref = NULL;
ret->exptext = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_USERNOTICE_NEW);
}
USERNOTICE *d2i_USERNOTICE(USERNOTICE **a, unsigned char **pp,long length)
{
M_ASN1_D2I_vars(a,USERNOTICE *,USERNOTICE_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_opt(ret->noticeref, d2i_NOTICEREF, V_ASN1_SEQUENCE);
if (!M_ASN1_D2I_end_sequence()) {
M_ASN1_D2I_get(ret->exptext, d2i_DISPLAYTEXT);
}
M_ASN1_D2I_Finish(a, USERNOTICE_free, ASN1_F_D2I_USERNOTICE);
}
void USERNOTICE_free(USERNOTICE *a)
{
if (a == NULL) return;
NOTICEREF_free(a->noticeref);
DISPLAYTEXT_free(a->exptext);
Free (a);
}
int i2d_NOTICEREF(NOTICEREF *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->organization, i2d_DISPLAYTEXT);
M_ASN1_I2D_len_SEQUENCE(a->noticenos, i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->organization, i2d_DISPLAYTEXT);
M_ASN1_I2D_put_SEQUENCE(a->noticenos, i2d_ASN1_INTEGER);
M_ASN1_I2D_finish();
}
NOTICEREF *NOTICEREF_new(void)
{
NOTICEREF *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, NOTICEREF);
ret->organization = NULL;
ret->noticenos = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_NOTICEREF_NEW);
}
NOTICEREF *d2i_NOTICEREF(NOTICEREF **a, unsigned char **pp,long length)
{
M_ASN1_D2I_vars(a,NOTICEREF *,NOTICEREF_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_opt(ret->organization, d2i_ASN1_IA5STRING,
V_ASN1_IA5STRING);
if(!ret->organization) {
M_ASN1_D2I_get(ret->organization, d2i_DISPLAYTEXT);
}
M_ASN1_D2I_get_seq(ret->noticenos, d2i_ASN1_INTEGER, ASN1_STRING_free);
M_ASN1_D2I_Finish(a, NOTICEREF_free, ASN1_F_D2I_NOTICEREF);
}
void NOTICEREF_free(NOTICEREF *a)
{
if (a == NULL) return;
DISPLAYTEXT_free(a->organization);
sk_pop_free(a->noticenos, ASN1_STRING_free);
Free (a);
}
