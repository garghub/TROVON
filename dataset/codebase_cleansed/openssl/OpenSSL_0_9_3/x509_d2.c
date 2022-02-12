int X509_STORE_set_default_paths(X509_STORE *ctx)
{
X509_LOOKUP *lookup;
lookup=X509_STORE_add_lookup(ctx,X509_LOOKUP_file());
if (lookup == NULL) return(0);
X509_LOOKUP_load_file(lookup,NULL,X509_FILETYPE_DEFAULT);
lookup=X509_STORE_add_lookup(ctx,X509_LOOKUP_hash_dir());
if (lookup == NULL) return(0);
X509_LOOKUP_add_dir(lookup,NULL,X509_FILETYPE_DEFAULT);
ERR_clear_error();
return(1);
}
int X509_STORE_load_locations(X509_STORE *ctx, const char *file,
const char *path)
{
X509_LOOKUP *lookup;
if (file != NULL)
{
lookup=X509_STORE_add_lookup(ctx,X509_LOOKUP_file());
if (lookup == NULL) return(0);
X509_LOOKUP_load_file(lookup,file,X509_FILETYPE_PEM);
}
if (path != NULL)
{
lookup=X509_STORE_add_lookup(ctx,X509_LOOKUP_hash_dir());
if (lookup == NULL) return(0);
X509_LOOKUP_add_dir(lookup,path,X509_FILETYPE_PEM);
}
if ((path == NULL) && (file == NULL))
return(0);
return(1);
}
