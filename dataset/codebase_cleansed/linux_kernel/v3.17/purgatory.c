static int copy_backup_region(void)
{
if (backup_dest)
memcpy((void *)backup_dest, (void *)backup_src, backup_sz);
return 0;
}
int verify_sha256_digest(void)
{
struct sha_region *ptr, *end;
u8 digest[SHA256_DIGEST_SIZE];
struct sha256_state sctx;
sha256_init(&sctx);
end = &sha_regions[sizeof(sha_regions)/sizeof(sha_regions[0])];
for (ptr = sha_regions; ptr < end; ptr++)
sha256_update(&sctx, (uint8_t *)(ptr->start), ptr->len);
sha256_final(&sctx, digest);
if (memcmp(digest, sha256_digest, sizeof(digest)))
return 1;
return 0;
}
void purgatory(void)
{
int ret;
ret = verify_sha256_digest();
if (ret) {
for (;;)
;
}
copy_backup_region();
}
