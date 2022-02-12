int i2d_PKCS12_SAFEBAG(PKCS12_SAFEBAG *a, unsigned char **pp)
{
int bagnid, v = 0;
M_ASN1_I2D_vars(a);
bagnid = OBJ_obj2nid (a->type);
M_ASN1_I2D_len (a->type, i2d_ASN1_OBJECT);
switch (bagnid) {
case NID_keyBag:
M_ASN1_I2D_len_EXP_opt (a->value.keybag,
i2d_PKCS8_PRIV_KEY_INFO, 0, v);
break;
case NID_pkcs8ShroudedKeyBag:
M_ASN1_I2D_len_EXP_opt (a->value.shkeybag,
i2d_X509_SIG, 0, v);
break;
case NID_safeContentsBag:
M_ASN1_I2D_len_EXP_SEQUENCE_opt_type
(PKCS12_SAFEBAG, a->value.safes, i2d_PKCS12_SAFEBAG,
0, V_ASN1_SEQUENCE, v);
break;
case NID_certBag:
case NID_crlBag:
case NID_secretBag:
M_ASN1_I2D_len_EXP_opt (a->value.bag,
i2d_PKCS12_BAGS, 0, v);
break;
default:
M_ASN1_I2D_len_EXP_opt (a->value.other,
i2d_ASN1_TYPE, 0, v);
break;
}
M_ASN1_I2D_len_SET_type (X509_ATTRIBUTE,a->attrib, i2d_X509_ATTRIBUTE);
M_ASN1_I2D_seq_total ();
M_ASN1_I2D_put (a->type, i2d_ASN1_OBJECT);
switch (bagnid) {
case NID_keyBag:
M_ASN1_I2D_put_EXP_opt (a->value.keybag,
i2d_PKCS8_PRIV_KEY_INFO, 0, v);
break;
case NID_pkcs8ShroudedKeyBag:
M_ASN1_I2D_put_EXP_opt (a->value.shkeybag,
i2d_X509_SIG, 0, v);
break;
case NID_safeContentsBag:
M_ASN1_I2D_put_EXP_SEQUENCE_opt_type
(PKCS12_SAFEBAG, a->value.safes, i2d_PKCS12_SAFEBAG,
0, V_ASN1_SEQUENCE, v);
break;
case NID_certBag:
case NID_crlBag:
case NID_secretBag:
M_ASN1_I2D_put_EXP_opt (a->value.bag,
i2d_PKCS12_BAGS, 0, v);
break;
default:
M_ASN1_I2D_put_EXP_opt (a->value.other,
i2d_ASN1_TYPE, 0, v);
break;
}
M_ASN1_I2D_put_SET_type (X509_ATTRIBUTE, a->attrib, i2d_X509_ATTRIBUTE);
M_ASN1_I2D_finish();
}
PKCS12_SAFEBAG *PKCS12_SAFEBAG_new(void)
{
PKCS12_SAFEBAG *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PKCS12_SAFEBAG);
ret->type=NULL;
ret->value.other=NULL;
M_ASN1_New(ret->attrib, sk_X509_ATTRIBUTE_new_null);
ret->rest=NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_PKCS12_SAFEBAG_NEW);
}
PKCS12_SAFEBAG *d2i_PKCS12_SAFEBAG(PKCS12_SAFEBAG **a, unsigned char **pp,
long length)
{
int bagnid;
M_ASN1_D2I_vars(a,PKCS12_SAFEBAG *,PKCS12_SAFEBAG_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->type, d2i_ASN1_OBJECT);
bagnid = OBJ_obj2nid (ret->type);
switch (bagnid) {
case NID_keyBag:
M_ASN1_D2I_get_EXP_opt (ret->value.keybag,
d2i_PKCS8_PRIV_KEY_INFO, 0);
break;
case NID_pkcs8ShroudedKeyBag:
M_ASN1_D2I_get_EXP_opt (ret->value.shkeybag,
d2i_X509_SIG, 0);
break;
case NID_safeContentsBag:
M_ASN1_D2I_get_EXP_set_opt_type
(PKCS12_SAFEBAG, ret->value.safes,
d2i_PKCS12_SAFEBAG, PKCS12_SAFEBAG_free, 0,
V_ASN1_SEQUENCE);
break;
case NID_certBag:
case NID_crlBag:
case NID_secretBag:
M_ASN1_D2I_get_EXP_opt (ret->value.bag,
d2i_PKCS12_BAGS, 0);
break;
default:
M_ASN1_D2I_get_EXP_opt (ret->value.other,
d2i_ASN1_TYPE, 0);
break;
}
M_ASN1_D2I_get_set_opt_type(X509_ATTRIBUTE,ret->attrib,
d2i_X509_ATTRIBUTE,X509_ATTRIBUTE_free);
M_ASN1_D2I_Finish(a, PKCS12_SAFEBAG_free, ASN1_F_D2I_PKCS12_SAFEBAG);
}
void PKCS12_SAFEBAG_free (PKCS12_SAFEBAG *a)
{
if (a == NULL) return;
switch (OBJ_obj2nid(a->type)) {
case NID_keyBag:
PKCS8_PRIV_KEY_INFO_free (a->value.keybag);
break;
case NID_pkcs8ShroudedKeyBag:
X509_SIG_free (a->value.shkeybag);
break;
case NID_certBag:
case NID_crlBag:
case NID_secretBag:
PKCS12_BAGS_free (a->value.bag);
break;
default:
ASN1_TYPE_free (a->value.other);
break;
}
ASN1_OBJECT_free (a->type);
sk_X509_ATTRIBUTE_pop_free (a->attrib, X509_ATTRIBUTE_free);
OPENSSL_free (a);
}
