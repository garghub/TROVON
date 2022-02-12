int BIO_get_new_index()
{
static int bio_count = BIO_TYPE_START;
int newval;
if (!RUN_ONCE(&bio_type_init, do_bio_type_init)) {
BIOerr(BIO_F_BIO_GET_NEW_INDEX, ERR_R_MALLOC_FAILURE);
return -1;
}
if (!CRYPTO_atomic_add(&bio_count, 1, &newval, bio_type_lock))
return -1;
return newval;
}
BIO_METHOD *BIO_meth_new(int type, const char *name)
{
BIO_METHOD *biom = OPENSSL_zalloc(sizeof(BIO_METHOD));
if (biom != NULL) {
biom->type = type;
biom->name = name;
}
return biom;
}
void BIO_meth_free(BIO_METHOD *biom)
{
OPENSSL_free(biom);
}
int BIO_meth_set_write(BIO_METHOD *biom,
int (*bwrite) (BIO *, const char *, int))
{
biom->bwrite = bwrite;
return 1;
}
int BIO_meth_set_read(BIO_METHOD *biom,
int (*bread) (BIO *, char *, int))
{
biom->bread = bread;
return 1;
}
int BIO_meth_set_puts(BIO_METHOD *biom,
int (*bputs) (BIO *, const char *))
{
biom->bputs = bputs;
return 1;
}
int BIO_meth_set_gets(BIO_METHOD *biom,
int (*bgets) (BIO *, char *, int))
{
biom->bgets = bgets;
return 1;
}
int BIO_meth_set_ctrl(BIO_METHOD *biom,
long (*ctrl) (BIO *, int, long, void *))
{
biom->ctrl = ctrl;
return 1;
}
int BIO_meth_set_create(BIO_METHOD *biom, int (*create) (BIO *))
{
biom->create = create;
return 1;
}
int BIO_meth_set_destroy(BIO_METHOD *biom, int (*destroy) (BIO *))
{
biom->destroy = destroy;
return 1;
}
int BIO_meth_set_callback_ctrl(BIO_METHOD *biom,
long (*callback_ctrl) (BIO *, int,
bio_info_cb *))
{
biom->callback_ctrl = callback_ctrl;
return 1;
}
