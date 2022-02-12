__init int ima_mok_init(void)
{
pr_notice("Allocating IMA blacklist keyring.\n");
ima_blacklist_keyring = keyring_alloc(".ima_blacklist",
KUIDT_INIT(0), KGIDT_INIT(0), current_cred(),
(KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ |
KEY_USR_WRITE | KEY_USR_SEARCH,
KEY_ALLOC_NOT_IN_QUOTA,
restrict_link_by_builtin_trusted, NULL);
if (IS_ERR(ima_blacklist_keyring))
panic("Can't allocate IMA blacklist keyring.");
set_bit(KEY_FLAG_KEEP, &ima_blacklist_keyring->flags);
return 0;
}
