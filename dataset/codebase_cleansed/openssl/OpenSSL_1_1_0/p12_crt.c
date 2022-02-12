static int copy_bag_attr(PKCS12_SAFEBAG *bag, EVP_PKEY *pkey, int nid)
{
int idx;
X509_ATTRIBUTE *attr;
idx = EVP_PKEY_get_attr_by_NID(pkey, nid, -1);
if (idx < 0)
return 1;
attr = EVP_PKEY_get_attr(pkey, idx);
if (!X509at_add1_attr(&bag->attrib, attr))
return 0;
return 1;
}
