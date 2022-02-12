void OPENSSL_cleanse(void *ptr, size_t len)
{
memset_func(ptr, 0, len);
}
