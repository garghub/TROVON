static int xp_cmp(const X509_PURPOSE * const *a,
const X509_PURPOSE * const *b)
{
return (*a)->purpose - (*b)->purpose;
}
int X509_check_purpose(X509 *x, int id, int ca)
{
int idx;
const X509_PURPOSE *pt;
if(!(x->ex_flags & EXFLAG_SET)) {
CRYPTO_w_lock(CRYPTO_LOCK_X509);
x509v3_cache_extensions(x);
CRYPTO_w_unlock(CRYPTO_LOCK_X509);
}
if(id == -1) return 1;
idx = X509_PURPOSE_get_by_id(id);
if(idx == -1) return -1;
pt = X509_PURPOSE_get0(idx);
return pt->check_purpose(pt, x, ca);
}
int X509_PURPOSE_set(int *p, int purpose)
{
if(X509_PURPOSE_get_by_id(purpose) == -1) {
X509V3err(X509V3_F_X509_PURPOSE_SET, X509V3_R_INVALID_PURPOSE);
return 0;
}
*p = purpose;
return 1;
}
int X509_PURPOSE_get_count(void)
{
if(!xptable) return X509_PURPOSE_COUNT;
return sk_X509_PURPOSE_num(xptable) + X509_PURPOSE_COUNT;
}
X509_PURPOSE * X509_PURPOSE_get0(int idx)
{
if(idx < 0) return NULL;
if(idx < (int)X509_PURPOSE_COUNT) return xstandard + idx;
return sk_X509_PURPOSE_value(xptable, idx - X509_PURPOSE_COUNT);
}
int X509_PURPOSE_get_by_sname(char *sname)
{
int i;
X509_PURPOSE *xptmp;
for(i = 0; i < X509_PURPOSE_get_count(); i++) {
xptmp = X509_PURPOSE_get0(i);
if(!strcmp(xptmp->sname, sname)) return i;
}
return -1;
}
int X509_PURPOSE_get_by_id(int purpose)
{
X509_PURPOSE tmp;
int idx;
if((purpose >= X509_PURPOSE_MIN) && (purpose <= X509_PURPOSE_MAX))
return purpose - X509_PURPOSE_MIN;
tmp.purpose = purpose;
if(!xptable) return -1;
idx = sk_X509_PURPOSE_find(xptable, &tmp);
if(idx == -1) return -1;
return idx + X509_PURPOSE_COUNT;
}
int X509_PURPOSE_add(int id, int trust, int flags,
int (*ck)(const X509_PURPOSE *, const X509 *, int),
char *name, char *sname, void *arg)
{
int idx;
X509_PURPOSE *ptmp;
flags &= ~X509_PURPOSE_DYNAMIC;
flags |= X509_PURPOSE_DYNAMIC_NAME;
idx = X509_PURPOSE_get_by_id(id);
if(idx == -1) {
if(!(ptmp = OPENSSL_malloc(sizeof(X509_PURPOSE)))) {
X509V3err(X509V3_F_X509_PURPOSE_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
ptmp->flags = X509_PURPOSE_DYNAMIC;
} else ptmp = X509_PURPOSE_get0(idx);
if(ptmp->flags & X509_PURPOSE_DYNAMIC_NAME) {
OPENSSL_free(ptmp->name);
OPENSSL_free(ptmp->sname);
}
ptmp->name = BUF_strdup(name);
ptmp->sname = BUF_strdup(sname);
if(!ptmp->name || !ptmp->sname) {
X509V3err(X509V3_F_X509_PURPOSE_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
ptmp->flags &= X509_PURPOSE_DYNAMIC;
ptmp->flags |= flags;
ptmp->purpose = id;
ptmp->trust = trust;
ptmp->check_purpose = ck;
ptmp->usr_data = arg;
if(idx == -1) {
if(!xptable && !(xptable = sk_X509_PURPOSE_new(xp_cmp))) {
X509V3err(X509V3_F_X509_PURPOSE_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
if (!sk_X509_PURPOSE_push(xptable, ptmp)) {
X509V3err(X509V3_F_X509_PURPOSE_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
}
return 1;
}
static void xptable_free(X509_PURPOSE *p)
{
if(!p) return;
if (p->flags & X509_PURPOSE_DYNAMIC)
{
if (p->flags & X509_PURPOSE_DYNAMIC_NAME) {
OPENSSL_free(p->name);
OPENSSL_free(p->sname);
}
OPENSSL_free(p);
}
}
void X509_PURPOSE_cleanup(void)
{
unsigned int i;
sk_X509_PURPOSE_pop_free(xptable, xptable_free);
for(i = 0; i < X509_PURPOSE_COUNT; i++) xptable_free(xstandard + i);
xptable = NULL;
}
int X509_PURPOSE_get_id(X509_PURPOSE *xp)
{
return xp->purpose;
}
char *X509_PURPOSE_get0_name(X509_PURPOSE *xp)
{
return xp->name;
}
char *X509_PURPOSE_get0_sname(X509_PURPOSE *xp)
{
return xp->sname;
}
int X509_PURPOSE_get_trust(X509_PURPOSE *xp)
{
return xp->trust;
}
static int nid_cmp(const int *a, const int *b)
{
return *a - *b;
}
int X509_supported_extension(X509_EXTENSION *ex)
{
static const int supported_nids[] = {
NID_netscape_cert_type,
NID_key_usage,
NID_subject_alt_name,
NID_basic_constraints,
NID_certificate_policies,
NID_ext_key_usage,
#ifndef OPENSSL_NO_RFC3779
NID_sbgp_ipAddrBlock,
NID_sbgp_autonomousSysNum,
#endif
NID_policy_constraints,
NID_proxyCertInfo,
NID_name_constraints,
NID_policy_mappings,
NID_inhibit_any_policy
};
int ex_nid = OBJ_obj2nid(X509_EXTENSION_get_object(ex));
if (ex_nid == NID_undef)
return 0;
if (OBJ_bsearch_nid(&ex_nid, supported_nids,
sizeof(supported_nids)/sizeof(int)))
return 1;
return 0;
}
static void setup_dp(X509 *x, DIST_POINT *dp)
{
X509_NAME *iname = NULL;
int i;
if (dp->reasons)
{
if (dp->reasons->length > 0)
dp->dp_reasons = dp->reasons->data[0];
if (dp->reasons->length > 1)
dp->dp_reasons |= (dp->reasons->data[1] << 8);
dp->dp_reasons &= CRLDP_ALL_REASONS;
}
else
dp->dp_reasons = CRLDP_ALL_REASONS;
if (!dp->distpoint || (dp->distpoint->type != 1))
return;
for (i = 0; i < sk_GENERAL_NAME_num(dp->CRLissuer); i++)
{
GENERAL_NAME *gen = sk_GENERAL_NAME_value(dp->CRLissuer, i);
if (gen->type == GEN_DIRNAME)
{
iname = gen->d.directoryName;
break;
}
}
if (!iname)
iname = X509_get_issuer_name(x);
DIST_POINT_set_dpname(dp->distpoint, iname);
}
static void setup_crldp(X509 *x)
{
int i;
x->crldp = X509_get_ext_d2i(x, NID_crl_distribution_points, NULL, NULL);
for (i = 0; i < sk_DIST_POINT_num(x->crldp); i++)
setup_dp(x, sk_DIST_POINT_value(x->crldp, i));
}
static void x509v3_cache_extensions(X509 *x)
{
BASIC_CONSTRAINTS *bs;
PROXY_CERT_INFO_EXTENSION *pci;
ASN1_BIT_STRING *usage;
ASN1_BIT_STRING *ns;
EXTENDED_KEY_USAGE *extusage;
X509_EXTENSION *ex;
int i;
if(x->ex_flags & EXFLAG_SET) return;
#ifndef OPENSSL_NO_SHA
X509_digest(x, EVP_sha1(), x->sha1_hash, NULL);
#endif
if(!X509_NAME_cmp(X509_get_subject_name(x), X509_get_issuer_name(x)))
x->ex_flags |= EXFLAG_SI;
if(!X509_get_version(x)) x->ex_flags |= EXFLAG_V1;
if((bs=X509_get_ext_d2i(x, NID_basic_constraints, NULL, NULL))) {
if(bs->ca) x->ex_flags |= EXFLAG_CA;
if(bs->pathlen) {
if((bs->pathlen->type == V_ASN1_NEG_INTEGER)
|| !bs->ca) {
x->ex_flags |= EXFLAG_INVALID;
x->ex_pathlen = 0;
} else x->ex_pathlen = ASN1_INTEGER_get(bs->pathlen);
} else x->ex_pathlen = -1;
BASIC_CONSTRAINTS_free(bs);
x->ex_flags |= EXFLAG_BCONS;
}
if((pci=X509_get_ext_d2i(x, NID_proxyCertInfo, NULL, NULL))) {
if (x->ex_flags & EXFLAG_CA
|| X509_get_ext_by_NID(x, NID_subject_alt_name, 0) >= 0
|| X509_get_ext_by_NID(x, NID_issuer_alt_name, 0) >= 0) {
x->ex_flags |= EXFLAG_INVALID;
}
if (pci->pcPathLengthConstraint) {
x->ex_pcpathlen =
ASN1_INTEGER_get(pci->pcPathLengthConstraint);
} else x->ex_pcpathlen = -1;
PROXY_CERT_INFO_EXTENSION_free(pci);
x->ex_flags |= EXFLAG_PROXY;
}
if((usage=X509_get_ext_d2i(x, NID_key_usage, NULL, NULL))) {
if(usage->length > 0) {
x->ex_kusage = usage->data[0];
if(usage->length > 1)
x->ex_kusage |= usage->data[1] << 8;
} else x->ex_kusage = 0;
x->ex_flags |= EXFLAG_KUSAGE;
ASN1_BIT_STRING_free(usage);
}
x->ex_xkusage = 0;
if((extusage=X509_get_ext_d2i(x, NID_ext_key_usage, NULL, NULL))) {
x->ex_flags |= EXFLAG_XKUSAGE;
for(i = 0; i < sk_ASN1_OBJECT_num(extusage); i++) {
switch(OBJ_obj2nid(sk_ASN1_OBJECT_value(extusage,i))) {
case NID_server_auth:
x->ex_xkusage |= XKU_SSL_SERVER;
break;
case NID_client_auth:
x->ex_xkusage |= XKU_SSL_CLIENT;
break;
case NID_email_protect:
x->ex_xkusage |= XKU_SMIME;
break;
case NID_code_sign:
x->ex_xkusage |= XKU_CODE_SIGN;
break;
case NID_ms_sgc:
case NID_ns_sgc:
x->ex_xkusage |= XKU_SGC;
break;
case NID_OCSP_sign:
x->ex_xkusage |= XKU_OCSP_SIGN;
break;
case NID_time_stamp:
x->ex_xkusage |= XKU_TIMESTAMP;
break;
case NID_dvcs:
x->ex_xkusage |= XKU_DVCS;
break;
}
}
sk_ASN1_OBJECT_pop_free(extusage, ASN1_OBJECT_free);
}
if((ns=X509_get_ext_d2i(x, NID_netscape_cert_type, NULL, NULL))) {
if(ns->length > 0) x->ex_nscert = ns->data[0];
else x->ex_nscert = 0;
x->ex_flags |= EXFLAG_NSCERT;
ASN1_BIT_STRING_free(ns);
}
x->skid =X509_get_ext_d2i(x, NID_subject_key_identifier, NULL, NULL);
x->akid =X509_get_ext_d2i(x, NID_authority_key_identifier, NULL, NULL);
x->altname = X509_get_ext_d2i(x, NID_subject_alt_name, NULL, NULL);
x->nc = X509_get_ext_d2i(x, NID_name_constraints, &i, NULL);
if (!x->nc && (i != -1))
x->ex_flags |= EXFLAG_INVALID;
setup_crldp(x);
#ifndef OPENSSL_NO_RFC3779
x->rfc3779_addr =X509_get_ext_d2i(x, NID_sbgp_ipAddrBlock, NULL, NULL);
x->rfc3779_asid =X509_get_ext_d2i(x, NID_sbgp_autonomousSysNum,
NULL, NULL);
#endif
for (i = 0; i < X509_get_ext_count(x); i++)
{
ex = X509_get_ext(x, i);
if (!X509_EXTENSION_get_critical(ex))
continue;
if (OBJ_obj2nid(X509_EXTENSION_get_object(ex))
== NID_freshest_crl)
x->ex_flags |= EXFLAG_FRESHEST;
if (!X509_supported_extension(ex))
{
x->ex_flags |= EXFLAG_CRITICAL;
break;
}
}
x->ex_flags |= EXFLAG_SET;
}
static int check_ca(const X509 *x)
{
if(ku_reject(x, KU_KEY_CERT_SIGN)) return 0;
if(x->ex_flags & EXFLAG_BCONS) {
if(x->ex_flags & EXFLAG_CA) return 1;
else return 0;
} else {
if((x->ex_flags & V1_ROOT) == V1_ROOT) return 3;
else if (x->ex_flags & EXFLAG_KUSAGE) return 4;
else if (x->ex_flags & EXFLAG_NSCERT
&& x->ex_nscert & NS_ANY_CA) return 5;
return 0;
}
}
int X509_check_ca(X509 *x)
{
if(!(x->ex_flags & EXFLAG_SET)) {
CRYPTO_w_lock(CRYPTO_LOCK_X509);
x509v3_cache_extensions(x);
CRYPTO_w_unlock(CRYPTO_LOCK_X509);
}
return check_ca(x);
}
static int check_ssl_ca(const X509 *x)
{
int ca_ret;
ca_ret = check_ca(x);
if(!ca_ret) return 0;
if(ca_ret != 5 || x->ex_nscert & NS_SSL_CA) return ca_ret;
else return 0;
}
static int check_purpose_ssl_client(const X509_PURPOSE *xp, const X509 *x, int ca)
{
if(xku_reject(x,XKU_SSL_CLIENT)) return 0;
if(ca) return check_ssl_ca(x);
if(ku_reject(x,KU_DIGITAL_SIGNATURE)) return 0;
if(ns_reject(x, NS_SSL_CLIENT)) return 0;
return 1;
}
static int check_purpose_ssl_server(const X509_PURPOSE *xp, const X509 *x, int ca)
{
if(xku_reject(x,XKU_SSL_SERVER|XKU_SGC)) return 0;
if(ca) return check_ssl_ca(x);
if(ns_reject(x, NS_SSL_SERVER)) return 0;
if(ku_reject(x, KU_DIGITAL_SIGNATURE|KU_KEY_ENCIPHERMENT)) return 0;
return 1;
}
static int check_purpose_ns_ssl_server(const X509_PURPOSE *xp, const X509 *x, int ca)
{
int ret;
ret = check_purpose_ssl_server(xp, x, ca);
if(!ret || ca) return ret;
if(ku_reject(x, KU_KEY_ENCIPHERMENT)) return 0;
return ret;
}
static int purpose_smime(const X509 *x, int ca)
{
if(xku_reject(x,XKU_SMIME)) return 0;
if(ca) {
int ca_ret;
ca_ret = check_ca(x);
if(!ca_ret) return 0;
if(ca_ret != 5 || x->ex_nscert & NS_SMIME_CA) return ca_ret;
else return 0;
}
if(x->ex_flags & EXFLAG_NSCERT) {
if(x->ex_nscert & NS_SMIME) return 1;
if(x->ex_nscert & NS_SSL_CLIENT) return 2;
return 0;
}
return 1;
}
static int check_purpose_smime_sign(const X509_PURPOSE *xp, const X509 *x, int ca)
{
int ret;
ret = purpose_smime(x, ca);
if(!ret || ca) return ret;
if(ku_reject(x, KU_DIGITAL_SIGNATURE|KU_NON_REPUDIATION)) return 0;
return ret;
}
static int check_purpose_smime_encrypt(const X509_PURPOSE *xp, const X509 *x, int ca)
{
int ret;
ret = purpose_smime(x, ca);
if(!ret || ca) return ret;
if(ku_reject(x, KU_KEY_ENCIPHERMENT)) return 0;
return ret;
}
static int check_purpose_crl_sign(const X509_PURPOSE *xp, const X509 *x, int ca)
{
if(ca) {
int ca_ret;
if((ca_ret = check_ca(x)) != 2) return ca_ret;
else return 0;
}
if(ku_reject(x, KU_CRL_SIGN)) return 0;
return 1;
}
static int ocsp_helper(const X509_PURPOSE *xp, const X509 *x, int ca)
{
if(ca) return check_ca(x);
return 1;
}
static int check_purpose_timestamp_sign(const X509_PURPOSE *xp, const X509 *x,
int ca)
{
int i_ext;
if (ca) return check_ca(x);
if ((x->ex_flags & EXFLAG_KUSAGE)
&& ((x->ex_kusage & ~(KU_NON_REPUDIATION | KU_DIGITAL_SIGNATURE)) ||
!(x->ex_kusage & (KU_NON_REPUDIATION | KU_DIGITAL_SIGNATURE))))
return 0;
if (!(x->ex_flags & EXFLAG_XKUSAGE) || x->ex_xkusage != XKU_TIMESTAMP)
return 0;
i_ext = X509_get_ext_by_NID((X509 *) x, NID_ext_key_usage, 0);
if (i_ext >= 0)
{
X509_EXTENSION *ext = X509_get_ext((X509 *) x, i_ext);
if (!X509_EXTENSION_get_critical(ext))
return 0;
}
return 1;
}
static int no_check(const X509_PURPOSE *xp, const X509 *x, int ca)
{
return 1;
}
int X509_check_issued(X509 *issuer, X509 *subject)
{
if(X509_NAME_cmp(X509_get_subject_name(issuer),
X509_get_issuer_name(subject)))
return X509_V_ERR_SUBJECT_ISSUER_MISMATCH;
x509v3_cache_extensions(issuer);
x509v3_cache_extensions(subject);
if(subject->akid)
{
int ret = X509_check_akid(issuer, subject->akid);
if (ret != X509_V_OK)
return ret;
}
if(subject->ex_flags & EXFLAG_PROXY)
{
if(ku_reject(issuer, KU_DIGITAL_SIGNATURE))
return X509_V_ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE;
}
else if(ku_reject(issuer, KU_KEY_CERT_SIGN))
return X509_V_ERR_KEYUSAGE_NO_CERTSIGN;
return X509_V_OK;
}
int X509_check_akid(X509 *issuer, AUTHORITY_KEYID *akid)
{
if(!akid)
return X509_V_OK;
if(akid->keyid && issuer->skid &&
ASN1_OCTET_STRING_cmp(akid->keyid, issuer->skid) )
return X509_V_ERR_AKID_SKID_MISMATCH;
if(akid->serial &&
ASN1_INTEGER_cmp(X509_get_serialNumber(issuer), akid->serial))
return X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH;
if(akid->issuer)
{
GENERAL_NAMES *gens;
GENERAL_NAME *gen;
X509_NAME *nm = NULL;
int i;
gens = akid->issuer;
for(i = 0; i < sk_GENERAL_NAME_num(gens); i++)
{
gen = sk_GENERAL_NAME_value(gens, i);
if(gen->type == GEN_DIRNAME)
{
nm = gen->d.dirn;
break;
}
}
if(nm && X509_NAME_cmp(nm, X509_get_issuer_name(issuer)))
return X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH;
}
return X509_V_OK;
}
