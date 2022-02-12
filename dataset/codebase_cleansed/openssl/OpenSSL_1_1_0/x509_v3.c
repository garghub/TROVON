int X509_EXTENSION_set_critical(X509_EXTENSION *ex, int crit)
{
if (ex == NULL)
return (0);
ex->critical = (crit) ? 0xFF : -1;
return (1);
}
int X509_EXTENSION_set_data(X509_EXTENSION *ex, ASN1_OCTET_STRING *data)
{
int i;
if (ex == NULL)
return (0);
i = ASN1_OCTET_STRING_set(&ex->value, data->data, data->length);
if (!i)
return (0);
return (1);
}
ASN1_OBJECT *X509_EXTENSION_get_object(X509_EXTENSION *ex)
{
if (ex == NULL)
return (NULL);
return (ex->object);
}
ASN1_OCTET_STRING *X509_EXTENSION_get_data(X509_EXTENSION *ex)
{
if (ex == NULL)
return (NULL);
return &ex->value;
}
int X509_EXTENSION_get_critical(const X509_EXTENSION *ex)
{
if (ex == NULL)
return (0);
if (ex->critical > 0)
return 1;
return 0;
}
